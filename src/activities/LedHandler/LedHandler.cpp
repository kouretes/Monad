#include "LedHandler.h"
#include "messages/Gamecontroller.pb.h"
#include <iostream>
#include "hal/robot/generic_nao/kAlBroker.h"
using std::cout;
using std::endl;
using std::string;
namespace {
ActivityRegistrar<LedHandler>::Type temp("LedHandler");
}
int LedHandler::Execute()
{
	static bool firstRun = true;
	
	if(firstRun)
	{
		leds->callVoid<string,int,float>("fadeRGB","AllLeds",colors["off"],0.001);
		firstRun = false;
	}
//     cout << "LedHandler run " << endl;
    process_messages();
    return 0;
}
void LedHandler::process_messages()
{
    MessageBuffer* buf = _blk->getBuffer();
		if(buf == 0)
			return;
// 		cout << "SIZE OF BUFFER = " << buf->size() << endl;
//     _blk->process_messages();
//     cout << "After returns " << endl;
    LedChangeMessage* led_change =0;// _blk->in_msg_nb<LedChangeMessage>("LedChangeMessage");
    Tuple* cur = 0;
		cur = buf->remove_head();
// 		cout << "remove head " << endl;
    while ( cur != 0)
    {
// 			cout << "in while " << endl;
        if (cur->get_type() != "LedChangeMessage")
        {
//             cout << "not led" << endl;
            delete cur;
            cur = buf->remove_head();
            continue;
        }
// 				cout << cur << endl;
        led_change = _blk->extract_result_from_tuple<LedChangeMessage>(*cur);
				if(led_change != 0)
				{
					for (int i = 0; i < led_change->leds_size(); i++)
					{
// 						cout << "In for " << i << " " << led_change->leds_size() <<  endl;
// 						/*` << led_change->leds(i).chain()<< "   " << led_change->leds(i).color() << endl;
							setLed(led_change->leds(i).chain(),led_change->leds(i).color());

					}
		   }
// 				led_change->Clear();
				if( cur != 0)
				{
// 					cout << " deleiting cur " << endl;
					delete cur;
				}
				
        
				

//  				cout << "led_chjange deleted " << endl;
				cur = buf->remove_head();
//  				cout << " cur re inited " << endl;
//       }
//       led_change = _blk->in_msg_nb<LedChangeMessage>("LedChangeMessage");
    }
//       while(cur != 0)
//       {
// 	  if(cur->get_type() != "LedChangeMessage")
// 	  {
// 	      cout << "not led" << endl;
// 	      delete cur;
// 	      cur = buf->remove_head();
// 	      continue;
// 	  }

// 	  LedChangeMessage* led_change = _blk->extract_result_from_tuple<LedChangeMessage>(*cur);


// 	  cur = buf->remove_head();

//       }
}
void LedHandler::UserInit()
{
//      tm = new TimeFilter("periodic_filter",1);
    _com->get_message_queue()->add_subscriber(_blk);
    _com->get_message_queue()->subscribe("communication",_blk,0);
    try {

        cout << "trying to get ALLeds Proxy "  << endl;;//<< KAlBroker::Instance()->GetBroker() << endl;
        leds =  KAlBroker::Instance().GetBroker()->getProxy("ALLeds");
         cout << "Initialized" << endl;
				
		}
    catch (AL::ALError& e)
    {
        cout << "Could not create DCM or ALLEds Proxy" << endl;

    }
//     cout << "LedHandler " << " init before " << endl;
    initializeColorMap();
//     cout << " Leaving Constructor" << endl;
}



LedHandler::LedHandler(): Publisher("LedHandler")
{

//     cout << "LedHandler " << " Constructor" << endl;
}

void LedHandler::setLed(const std::string& device, const std::string& color)
{
// 		cout << "Set " << device <<" to " << color << endl;
    if (device.compare("chest") == 0)
    {

        setDcmChestColor(color);
        return ;
    }
    if (device.compare("l_foot") == 0)
    {

        setDcmFootColor(device,color); //cout << "SETTING " + device + " " + color<<endl;
        return;
    }
    if (device.compare("r_foot") == 0)
    {

        setDcmFootColor(device,color);//cout << "SETTING " + device + " " + color<<endl;
        return;
    }
    if ((device.compare("r_ear") == 0) || (device.compare("l_ear") == 0))
    {	  
        setDcmEarColor(device,color);
        return;
    }
    if ((device.compare("r_eye") == 0) || (device.compare("l_eye") == 0 ))
    {
// 			cout << "EYYYYYYYYYYYYYEEEEEEEEEEEEEEe " << endl;
        setDcmEyeColor(device,color);
    }
}

void LedHandler::setDcmChestColor(const string& color)
{
    // cout << "chest to " << colors[color] << endl;
    leds->callVoid<string,int,float>("fadeRGB","ChestLeds",colors[color],0.01);
}


void LedHandler::setDcmFootColor(const string& device , const string& color)
{
    
//     cout << device << " " << colors[color] << endl;
// 		std::cout << "Foot COLOR:  " << color  <<endl;
// 		std::cout << "Foot COLOR:  " << device[0] << endl;
		if (device.find("l") != device.npos)
		{
			leds->callVoid<string,int,float>("fadeRGB","LeftFootLeds",colors[color],0.01);
		}
    else
		{ 
        leds->callVoid<string,int,float>("fadeRGB","RightFootLeds",colors[color],0.01);
		}
// 		cout << "Change color " << endl;
}

void LedHandler::setDcmEyeColor(const string& device ,const string& color)
{
//     std::cout << "Eye COLOR:  " << color << endl;
    if (device.find("l") != device.npos)
    {
        leds->callVoid<string,int,float>("fadeRGB","FaceLedsLeftExternal",colors[color],0.1);
        leds->callVoid<string,int,float>("fadeRGB","FaceLedsLeftInternal",colors[color],0.1);

    }
    else
    {
        leds->callVoid<string,int,float>("fadeRGB","FaceLedsRightExternal",colors[color],0.1);
        leds->callVoid<string,int,float>("fadeRGB","FaceLedsRightInternal",colors[color],0.1);
    }
}

void LedHandler::setDcmIndividualEyeColor(const string& device,const string& color)
{
    return;
}
void LedHandler::setDcmEarColor(const string& device,const string& color)
{
    //std::cout << "Ear COLOR:  " << color << endl;
    if ( color.compare("off") != 0 && color.compare("blue") != 0)
    {
        //cout << "Invalid color for Ears \n Please use only blue and off" << endl;
        return;
    }
    if (device.find("l") != device.npos)
        leds->callVoid<string,int,float>("fadeRGB","LeftEarLeds",colors[color.c_str()],0.1);
    else
        leds->callVoid<string,int,float>("fadeRGB","RightEarLeds",colors[color.c_str()],0.1);
}

void LedHandler::setDcmIndividualEarColor(const string& device,const string& color)
{
    return;
}

void LedHandler::initializeColorMap()
{
    //add off to color map
    colors["off"] = 0x00000000;
    //add on = white to color map
    colors["on"] = 0x00FFFFFF   ;
    //add red to color map
    colors["red"] = 0x00FF0000;
    //add green to color map
    colors["green"] = 0x0000FF00;
    //add blue to color map
    colors["blue"] = 0x000000FF;
    //add yellow to color map
    colors["yellow"] = 0x00FFF52C;


    //add orange to color map
    colors["orange"] = 0x00FFFF00;
    colors["purple"] = 0x00FF00FF;

}
int LedHandler::getColor(string color)
{
    return colors[color];
}
