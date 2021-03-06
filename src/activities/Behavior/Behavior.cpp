#include "Behavior.h"
#include "hal/robot/generic_nao/kAlBroker.h"

#include "alxplatform.h"
#include <albroker.h>
#include <alproxy.h>
#include <almemoryfastaccess.h>
#include "almotionproxy.h"
#include "almemoryproxy.h"
#include "albrokermanager.h"
#include "alvalue.h"

#include "tools/logger.h"
#include "tools/toString.h"
#include "messages/RoboCupGameControlData.h"
#include "architecture/narukom/pub_sub/filters/special_filters.h"

namespace {
	ActivityRegistrar<Behavior>::Type temp("Behavior");
}

Behavior::Behavior() :
	Publisher("Behavior") {
}

void Behavior::UserInit() {
	readConfiguration(ArchConfig::Instance().GetConfigPrefix() + "/team_config.xml");

	_com->get_message_queue()->add_publisher(this);
	_com->get_message_queue()->add_subscriber(_blk);
	_com->get_message_queue()->subscribe("vision", _blk, 0);
	_com->get_message_queue()->subscribe("sensors", _blk, 0);
	_com->get_message_queue()->subscribe("behavior", _blk, 0);
	_com->get_message_queue()->subscribe("obstacle", _blk, 0);

	wmot = new MotionWalkMessage();
	wmot->set_topic("motion");
	wmot->add_parameter(0.0f);
	wmot->add_parameter(0.0f);
	wmot->add_parameter(0.0f);
	wmot->add_parameter(0.0f);

	hmot = new MotionHeadMessage();
	hmot->set_topic("motion");
	hmot->add_parameter(0.0f);
	hmot->add_parameter(0.0f);

	amot = new MotionActionMessage();
	amot->set_topic("motion");

	ballfound = 0;

	reachedlimitup = false;
	reachedlimitdown = false;
	reachedlimitleft = false;
	reachedlimitright = false;

	scanforball = true;
	startscan = true;

	calibrated = 0;

	stopped = true;
	play = false;
	kickoff = false; 

	hjsm = 0;
	bmsg = 0;
	gsm = 0;
	obsm = 0;
	om = 0;

	readytokick = false;
	back = 0;
	direction = 1;
	turning = false;
	count = 0;
	obstacleFront = false;
	gameState = PLAYER_INITIAL;
	
	teamColor = TEAM_BLUE;
	orientation = 0; 
	
	srand(time(0));

	Logger::Instance().WriteMsg("Behavior", "Initialized", Logger::Info);
}

int Behavior::MakeTrackBallAction() {

	float overshootfix = 0.50;
	float cx = bmsg->cx();
	float cy = bmsg->cy();
	if (fabs(cx) > 0.015 || fabs(cy) > 0.015) {
		//hmot->set_command("setHead");
		//hmot->set_parameter(0, bmsg->referenceyaw() - overshootfix * cx);
		//hmot->set_parameter(1, bmsg->referencepitch() - overshootfix * cy);
		hmot->set_command("changeHead");
		if (fabs(cx) > 0.015)
			hmot->set_parameter(0, - overshootfix * cx);
		else
			hmot->set_parameter(0, 0.0);
		if (fabs(cy) > 0.015)
			hmot->set_parameter(1, - overshootfix * cy);
		else
			hmot->set_parameter(1, 0.0);
		Publisher::publish(hmot, "motion");
	}
	return 1;
}


//void Behavior::mgltest() {

	//if (om!=0) {
		//Logger::Instance().WriteMsg("Behavior", "Obstacle - Direction: " + _toString(om->direction()), Logger::Info);
		//if (om->direction(0) == 0) 
			//velocityWalk(0.0, 0.0, 1.0, 1.0);
	//}
	//else
		//velocityWalk(1.0, 0.0, 0.0, 1.0);
//}

int Behavior::Execute() {

	read_messages();

	if (gsm != 0) {
		Logger::Instance().WriteMsg("Behavior", " Player_state " + _toString(gsm->player_state()), Logger::ExtraExtraInfo);
		gameState = gsm->player_state();
		//teamColor = gsm->team_color();
		
		if (gameState == PLAYER_PLAYING) {
			if (calibrated == 2) {
				play = true;
				littleWalk(0.01,0.0,0.0,1);
			}
			else if (calibrated == 0) {
				calibrate();
			}
			else if (calibrated == 1) {
				// wait
			}
		}
		else if (gameState == PLAYER_INITIAL) {
			play = false;
		}
		else if (gameState == PLAYER_READY) {
			play = false;
		}
		else if (gameState == PLAYER_SET) {
			play = false;
			calibrate();
			kickoff = gsm->kickoff();
			orientation = 0; 
		}
		else if (gameState == PLAYER_FINISHED) {
			play = false;
		}
		else if (gameState == PLAYER_PENALISED) {
			play = false;
			calibrate();
		}
	}
	
	if (gameState == PLAYER_PLAYING) {
		if (calibrated == 2) {
			play = true;
		}
		else if (calibrated == 0) {
			calibrate();
		}
	}

	//if (play) mgltest();
	//return 1;

	if (play) {

		if (bmsg != 0) {
			Logger::Instance().WriteMsg("Behavior", "BallTrackMessage", Logger::ExtraExtraInfo);
			if (bmsg->radius() > 0) { //This means that a ball was found
				scanforball = false; //if you are scanning for ball please stop now
				back = 0;
				MakeTrackBallAction();
				ballfound += 5;
				if (ballfound > 20)
					ballfound = 20; //Increase this value when we see the ball
			}
			else {
				if (ballfound > 0)
					ballfound -= 1; //Decrease it when we don't see the ball
			}
		}
		Logger::Instance().WriteMsg("Behavior", "ballfound Value: " + _toString(ballfound), Logger::ExtraInfo);

		float X=0.0, Y=0.0, theta=0.0;
		float bd=0.0, bx=0.0, by=0.0, bb=0.0;

		if ((obsm != 0) && !turning) {
			
			if (obsm->regular_objects_size()>0) {
				if ( ( (obsm->regular_objects(0).object_name() == "BlueGoal") && (teamColor == TEAM_RED) ) ||
					 ( (obsm->regular_objects(0).object_name() == "YellowGoal") && (teamColor == TEAM_BLUE) )  ) {
						double ogb = obsm->regular_objects(0).bearing();
						if (fabs(ogb)<+45*TO_RAD) {
							orientation = 0; 
						}
						else if (ogb>+45*TO_RAD) {
							orientation = 1;
						}
						else if (ogb<-45*TO_RAD) {
							orientation = 3; 
						}
					 }
				
				if ( ( (obsm->regular_objects(0).object_name() == "YellowGoal") && (teamColor == TEAM_RED) ) ||
					 ( (obsm->regular_objects(0).object_name() == "BlueGoal") && (teamColor == TEAM_BLUE) )  ) {
						double mgb = obsm->regular_objects(0).bearing();
						if (fabs(mgb)<+45*TO_RAD) {
							orientation = 2; 
						}
						else if (mgb>+45*TO_RAD) {
							orientation = 3;
						}
						else if (mgb<-45*TO_RAD) {
							orientation = 1; 
						}
					 }
				Logger::Instance().WriteMsg("Behavior", "Orientation: " + _toString(orientation) + " Team Color " + _toString(teamColor), Logger::Info);
			}
			
			if (obsm->has_ball()) { 
				
				scanforball = false; //be sure to stop scanning
				int side=1;
				bd = obsm->ball().dist();
				bb = obsm->ball().bearing();
				bx = obsm->ball().dist() * cos( obsm->ball().bearing() );
				by = obsm->ball().dist() * sin( obsm->ball().bearing() );
				//side = (bb > 0) ? 1 : -1;
				if (orientation==1)
					side = -1;
				else if (orientation==3)
					side = +1;
				else 
					side = (bb > 0) ? 1 : -1;
					
				Logger::Instance().WriteMsg("Behavior", "Measurements - Distance: " + _toString(bd) + "  Bearing: " + _toString(bb) + "  BX: " + _toString(bx) + "  BY: " + _toString(by), Logger::Info);
	
				if (!readytokick) {
					readytokick = true;
					double gain = 1.0;
					if (bd>0.4)
						gain = 1.5;
		            double gainTheta = 0.3;
		            double gainFine = 1.0;
					if (bd <= 8.0) {
						float posx=0.17, posy=0.05;
						if (bd > 0.25) {
							X = gain * bx;
							Y = gain * by;
							if (fabs(bb) > 3*TO_RAD)
								theta = gainTheta * bb;
							readytokick = false;
						} else if (bd > 0.25) {
							X = gain * (bx - posx);
							Y = gain * ( by - (side*posy) );
							readytokick = false;
						} else {
							if ( fabs( bx - posx ) > 0.025) {
								X = gainFine * (bx - posx);
								readytokick = false;
							}
							if ( fabs( by - (side*posy) ) > 0.025) {
								Y = gainFine * ( by - (side*posy) );
								readytokick = false;
							}
						}
					}
		
					if (!readytokick) {
						
						if (fabs(X) > 1.0)
							X = (X > 0.0) ? 1.0 : -1.0;
						if (fabs(Y) > 1.0)
							Y = (Y > 0.0) ? 1.0 : -1.0;
						if (fabs(theta) > 1.0)
							theta = (theta > 0.0) ? 1.0 : -1.0;
							
						if (om!=0) {
							if (om->direction(1)==1) {
								X = 0.0;
							}
							else if ( (om->direction(0)==1) && (Y>0) ) {
								Y = 0.0;
							}
							else if ( (om->direction(0)==1) && (theta>0) ) {
								theta = 0.0;
							}
							else if ( (om->direction(2)==1) && (Y<0) ) {
								Y = 0.0; 
							}
							else if ( (om->direction(2)==1) && (theta<0) ) {
								theta = 0.0; 
							}
						}
						
						velocityWalk(X, Y, theta, 1.0);
					}
					else {
						velocityWalk(0.0, 0.0, 0.0, 1.0); 
						return 1;
					}
				}
			}
		}
		else {
			readytokick = false;
		}


		/* Ready to take action */
		if (readytokick && !turning) {
			obstacleFront = false; 
			if (om!=0) 
				if (om->direction(1) == 1) 
					obstacleFront = true; 
			
			if ( kickoff ) {
				//if (mglRand()<0.5) {
				if ( (mglRand()<1.0) && !obstacleFront ) {
					littleWalk(0.2, 0.0, 0.0, 2);
				} else {
					if (by > 0.0) {
						amot->set_command("SoftLeftSideKick");
						direction = -1;
					}
					else {
						amot->set_command("SoftRightSideKick");
						direction = +1;
					}
					Publisher::publish(amot, "motion");
				}
				kickoff = false;
			}
			else {
				
				/* **************** Targetted Kicks ********************** */
				if (orientation == 0) {
					if (by > 0.0) 
						amot->set_command("LeftKick");
					else 
						amot->set_command("RightKick");
				}
				else if (orientation == 1) {
					amot->set_command("HardLeftSideKick");
					direction = -1;
				}
				else if (orientation == 3) {
					amot->set_command("HardRightSideKick");
					direction = +1;
				} 
				else if (orientation == 2) {
					if (by > 0.0)
						amot->set_command("LeftBackKick");
					else 
						amot->set_command("RightBackKick");
				} 
				else {
					if (by > 0.0) 
						amot->set_command("SoftLeftSideKick");
					else 
						amot->set_command("SoftRightSideKick");
				}
				
				Publisher::publish(amot, "motion");
				back = 0;
				/* **************** End of Targetted Kicks ********************** */
				
				/* **************** Randomized Kicks ********************** */
				//if (mglRand()<0.6) {
				////if ( (mglRand()<1.0) && !obstacleFront ) {
					//if (by > 0.0) 
						//amot->set_command("LeftKick");
					//else 
						//amot->set_command("RightKick");
				//}
				//else if (mglRand()<0.5) {
					//if (by > 0.0) {
						//amot->set_command("HardLeftSideKick");
						//direction = -1;
					//}
					//else {
						//amot->set_command("HardRightSideKick");
						//direction = +1;
					//}
				//}
				//else {
					//if (by > 0.0)
						//amot->set_command("LeftBackKick");
					//else 
						//amot->set_command("RightBackKick");
				//}
				//Publisher::publish(amot, "motion");
				//back = 0;
				/* **************** End of Randomized Kicks ********************** */
			}
			
			readytokick = false;
			scanforball = true;
			startscan = true;
		}

		if ( (ballfound == 0) && !readytokick && !turning ) {
			if (!scanforball) {
				startscan = true;
				velocityWalk(0.0, 0.0, 0.0, 1.0);
			}
			scanforball = true;
		}

		if (scanforball && !readytokick && !turning && (hjsm != 0) ) {
			HeadYaw = hjsm->sensordata(0);
			HeadPitch = hjsm->sensordata(1);
			HeadScanStep();
		}

	} else if (!play) {   // Non-Play state
		velocityWalk(0.0, 0.0, 0.0, 1.0);
	}

	return 0;
}




void Behavior::HeadScanStep() {

	if (startscan) {
		littleWalk(0.0, 0.0, +2*TO_RAD, 0);
		//BE CAREFULL the max sign is according to sensors values (max maybe negative! :p)
		if (HeadPitch.sensorvalue() < LIMITDOWN) { // first go down
			scandirectionpitch = 1;
		} else {
			scandirectionpitch = -1; // go up
		}
		reachedlimitup = false;
		reachedlimitdown = false;
		reachedlimitleft = false;
		reachedlimitright = false;
		scandirectionyaw = (HeadYaw.sensorvaluediff() > 0) ? 1 : -1;
		startscan = false;
	}

	//continue scan
	if (HeadPitch.sensorvalue() < LIMITUP) {
		//Logger::Instance().WriteMsg("Behavior", " LIMITUP ", Logger::ExtraExtraInfo);
		reachedlimitup = true;
		scandirectionpitch = 1;
	}
	if (HeadPitch.sensorvalue() > LIMITDOWN) {
		//Logger::Instance().WriteMsg("Behavior", " LIMITDOWN ", Logger::ExtraExtraInfo);
		reachedlimitdown = true;
		scandirectionpitch = -1;
	}
	if (HeadYaw.sensorvalue() > LIMITLEFT) {
		//Logger::Instance().WriteMsg("Behavior", "LIMITLEFT  ", Logger::ExtraExtraInfo);
		reachedlimitleft = true;
		scandirectionyaw = -1;
	}
	if (HeadYaw.sensorvalue() < LIMITRIGHT) {
		//Logger::Instance().WriteMsg("Behavior", " LIMITRIGHT  ", Logger::ExtraExtraInfo);
		reachedlimitright = true;
		scandirectionyaw = 1;
	}

	hmot->set_command("changeHead");
	hmot->set_parameter(0, scandirectionyaw * STEPHOR); // Headyaw
	hmot->set_parameter(1, 0.0); // headPitch

	if (reachedlimitleft && reachedlimitright) {
		Logger::Instance().WriteMsg("Behavior", " reachedlimitleft && reachedlimitright ", Logger::ExtraExtraInfo);
		hmot->set_parameter(1, scandirectionpitch * STEPVER); // headPitch
		reachedlimitleft = false;
		reachedlimitright = false;
	}
	Publisher::publish(hmot, "motion");

	if (reachedlimitup && reachedlimitdown) { //scanning completed
		Logger::Instance().WriteMsg("Behavior", " reachedlimitup && reachedlimitdown ", Logger::ExtraExtraInfo);
		startscan = true;
		reachedlimitdown = false;
		reachedlimitup = false;
		reachedlimitright = false;
		reachedlimitleft = false;
		///we should do something;
		if (back>0) {
			littleWalk(-0.2, 0.0, 0.0, 2);
			back--;
		} 
		else {
			littleWalk(0.0, 0.0, direction * 90 * TO_RAD, 1);
			//direction = - direction;
		}
	}
}

void Behavior::read_messages() {

	if (gsm != 0) delete gsm;
	if (bmsg != 0) delete bmsg;
	if (hjsm != 0) delete hjsm;
	if (obsm != 0) delete obsm;
	if (om != 0) delete om;

	_blk->process_messages();

	gsm  = _blk->in_msg_nb<GameStateMessage> ("GameStateMessage");
	bmsg = _blk->in_msg_nb<BallTrackMessage> ("BallTrackMessage");
	hjsm = _blk->in_msg_nb<HeadJointSensorsMessage> ("HeadJointSensorsMessage");
	obsm = _blk->in_msg_nb<ObservationMessage> ("ObservationMessage");
	om   = _blk->in_msg_nb<ObstacleMessageArray> ("ObstacleMessageArray");

	Logger::Instance().WriteMsg("Behavior", "read_messages ", Logger::ExtraExtraInfo);
	CalibrateCam *c = _blk->in_msg_nb<CalibrateCam> ("CalibrateCam");
	if (c != NULL) {
		if (c->status() == 1)
			calibrated = 2;
		delete c;
	}
}

double Behavior::mglRand()
{
    return rand() / double(RAND_MAX);
}

void Behavior::velocityWalk(double x, double y, double th, double f)
{
	wmot->set_command("setWalkTargetVelocity");
	wmot->set_parameter(0, x);
	wmot->set_parameter(1, y);
	wmot->set_parameter(2, th);
	wmot->set_parameter(3, f);
	Publisher::publish(wmot, "motion");
}

void Behavior::littleWalk(double x, double y, double th, int s)
{
	RejectAllFilter reject_filter("RejectFilter");
	_blk->getBuffer()->add_filter(&reject_filter);
	wmot->set_command("walkTo");
	wmot->set_parameter(0, x);
	wmot->set_parameter(1, y);
	wmot->set_parameter(2, th);
	Publisher::publish(wmot, "motion");
	sleep(s);
	_blk->getBuffer()->remove_filter(&reject_filter);
}

void Behavior::calibrate()
{
	CalibrateCam v;
	v.set_status(0);
	publish(&v, "vision");
	calibrated = 1;
}

bool Behavior::readConfiguration(const std::string& file_name) {
	XMLConfig config(file_name);

	int playernum=-1;
	if (!config.QueryElement("player", playernum))
		Logger::Instance().WriteMsg("Behavior", "Configuration file has no player, setting to default value: " + _toString(playernum), Logger::Error);

	//If color is changed default configuration color does need to be changed
	std::string color = "blue";
	teamColor =TEAM_BLUE;
	if (!config.QueryElement("default_team_color", color))
		Logger::Instance().WriteMsg("Behavior", "Configuration file has no team_color, setting to default value: " + color, Logger::Error);
	if (color == "blue")
		teamColor =TEAM_BLUE;
	else if (color == "red")
		teamColor = TEAM_RED;
	else
		Logger::Instance().WriteMsg("Behavior", "Undefined color in configuration, setting to default value: " + color, Logger::Error);

	return true;
}
