#include "HardRightSideKick.h"

#include "hal/robot/generic_nao/kAlBroker.h"

namespace {
  SpecialActionRegistrar<HardRightSideKick>::Type temp("HardRightSideKick");
}

HardRightSideKick::HardRightSideKick() {
  Initialize();
  Logger::Instance().WriteMsg("SP:HardRightSideKick","Initialized!",Logger::ExtraInfo);
  
  try {
    motion = KAlBroker::Instance().GetBroker()->getMotionProxy();
  } catch (AL::ALError& e) {
    Logger::Instance().WriteMsg("SP:HardRightSideKick","Error in getting motion proxy",Logger::FatalError);
  }
  
}


void HardRightSideKick::Initialize() {
  
  /******************************** Hard Right Side Kick ****************************/
  
  HardRightSideKick_names.reserve(19);
  HardRightSideKick_times.arraySetSize(19);
  HardRightSideKick_keys.arraySetSize(19);
  
  HardRightSideKick_names.push_back("LShoulderPitch");
  HardRightSideKick_times[0].arraySetSize(10);
  HardRightSideKick_keys[0].arraySetSize(10);
  
  HardRightSideKick_times[0][0] = 0.400000;
  HardRightSideKick_keys[0][0] = AL::ALValue::array(1.41891, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.133333, 0.00000));
  HardRightSideKick_times[0][1] = 0.800000;
  HardRightSideKick_keys[0][1] = AL::ALValue::array(1.42359, AL::ALValue::array(2, -0.133333, -0.00410473), AL::ALValue::array(2, 0.133333, 0.00410473));
  HardRightSideKick_times[0][2] = 1.20000;
  HardRightSideKick_keys[0][2] = AL::ALValue::array(1.44354, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.100000, 0.00000));
  HardRightSideKick_times[0][3] = 1.50000;
  HardRightSideKick_keys[0][3] = AL::ALValue::array(1.44038, AL::ALValue::array(2, -0.100000, -0.00000), AL::ALValue::array(2, 0.100000, 0.00000));
  HardRightSideKick_times[0][4] = 1.80000;
  HardRightSideKick_keys[0][4] = AL::ALValue::array(1.44200, AL::ALValue::array(2, -0.100000, -0.00161787), AL::ALValue::array(2, 0.0333333, 0.000539290));
  HardRightSideKick_times[0][5] = 1.90000;
  HardRightSideKick_keys[0][5] = AL::ALValue::array(1.46033, AL::ALValue::array(2, -0.0333333, -0.00315198), AL::ALValue::array(2, 0.0333333, 0.00315198));
  HardRightSideKick_times[0][6] = 2.00000;
  HardRightSideKick_keys[0][6] = AL::ALValue::array(1.46348, AL::ALValue::array(2, -0.0333333, -0.000901902), AL::ALValue::array(2, 0.100000, 0.00270571));
  HardRightSideKick_times[0][7] = 2.30000;
  HardRightSideKick_keys[0][7] = AL::ALValue::array(1.47115, AL::ALValue::array(2, -0.100000, -0.00000), AL::ALValue::array(2, 0.166667, 0.00000));
  HardRightSideKick_times[0][8] = 2.80000;
  HardRightSideKick_keys[0][8] = AL::ALValue::array(1.46194, AL::ALValue::array(2, -0.166667, 0.00819550), AL::ALValue::array(2, 0.166667, -0.00819550));
  HardRightSideKick_times[0][9] = 3.30000;
  HardRightSideKick_keys[0][9] = AL::ALValue::array(1.42198, AL::ALValue::array(2, -0.166667, -0.00000), AL::ALValue::array(2, 0.00000, 0.00000));
  
  HardRightSideKick_names.push_back("LShoulderRoll");
  HardRightSideKick_times[1].arraySetSize(10);
  HardRightSideKick_keys[1].arraySetSize(10);
  
  HardRightSideKick_times[1][0] = 0.400000;
  HardRightSideKick_keys[1][0] = AL::ALValue::array(0.368118, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.133333, 0.00000));
  HardRightSideKick_times[1][1] = 0.800000;
  HardRightSideKick_keys[1][1] = AL::ALValue::array(1.37911, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.133333, 0.00000));
  HardRightSideKick_times[1][2] = 1.20000;
  HardRightSideKick_keys[1][2] = AL::ALValue::array(1.37451, AL::ALValue::array(2, -0.133333, 0.000111853), AL::ALValue::array(2, 0.100000, -8.38896e-05));
  HardRightSideKick_times[1][3] = 1.50000;
  HardRightSideKick_keys[1][3] = AL::ALValue::array(1.37442, AL::ALValue::array(2, -0.100000, 8.38896e-05), AL::ALValue::array(2, 0.100000, -8.38896e-05));
  HardRightSideKick_times[1][4] = 1.80000;
  HardRightSideKick_keys[1][4] = AL::ALValue::array(1.36990, AL::ALValue::array(2, -0.100000, 0.00451859), AL::ALValue::array(2, 0.0333333, -0.00150620));
  HardRightSideKick_times[1][5] = 1.90000;
  HardRightSideKick_keys[1][5] = AL::ALValue::array(0.621337, AL::ALValue::array(2, -0.0333333, -0.00000), AL::ALValue::array(2, 0.0333333, 0.00000));
  HardRightSideKick_times[1][6] = 2.00000;
  HardRightSideKick_keys[1][6] = AL::ALValue::array(0.635118, AL::ALValue::array(2, -0.0333333, -0.0137811), AL::ALValue::array(2, 0.100000, 0.0413434));
  HardRightSideKick_times[1][7] = 2.30000;
  HardRightSideKick_keys[1][7] = AL::ALValue::array(0.925025, AL::ALValue::array(2, -0.100000, -0.0864791), AL::ALValue::array(2, 0.166667, 0.144132));
  HardRightSideKick_times[1][8] = 2.80000;
  HardRightSideKick_keys[1][8] = AL::ALValue::array(1.32695, AL::ALValue::array(2, -0.166667, -0.00000), AL::ALValue::array(2, 0.166667, 0.00000));
  HardRightSideKick_times[1][9] = 3.30000;
  HardRightSideKick_keys[1][9] = AL::ALValue::array(0.369652, AL::ALValue::array(2, -0.166667, -0.00000), AL::ALValue::array(2, 0.00000, 0.00000));
  
  HardRightSideKick_names.push_back("LElbowYaw");
  HardRightSideKick_times[2].arraySetSize(10);
  HardRightSideKick_keys[2].arraySetSize(10);
  
  HardRightSideKick_times[2][0] = 0.400000;
  HardRightSideKick_keys[2][0] = AL::ALValue::array(-1.38218, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.133333, 0.00000));
  HardRightSideKick_times[2][1] = 0.800000;
  HardRightSideKick_keys[2][1] = AL::ALValue::array(-1.37902, AL::ALValue::array(2, -0.133333, -0.00129214), AL::ALValue::array(2, 0.133333, 0.00129214));
  HardRightSideKick_times[2][2] = 1.20000;
  HardRightSideKick_keys[2][2] = AL::ALValue::array(-1.37442, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.100000, 0.00000));
  HardRightSideKick_times[2][3] = 1.50000;
  HardRightSideKick_keys[2][3] = AL::ALValue::array(-1.37604, AL::ALValue::array(2, -0.100000, 0.000511394), AL::ALValue::array(2, 0.100000, -0.000511394));
  HardRightSideKick_times[2][4] = 1.80000;
  HardRightSideKick_keys[2][4] = AL::ALValue::array(-1.37749, AL::ALValue::array(2, -0.100000, -0.00000), AL::ALValue::array(2, 0.0333333, 0.00000));
  HardRightSideKick_times[2][5] = 1.90000;
  HardRightSideKick_keys[2][5] = AL::ALValue::array(-1.35456, AL::ALValue::array(2, -0.0333333, -0.00000), AL::ALValue::array(2, 0.0333333, 0.00000));
  HardRightSideKick_times[2][6] = 2.00000;
  HardRightSideKick_keys[2][6] = AL::ALValue::array(-1.36368, AL::ALValue::array(2, -0.0333333, -0.00000), AL::ALValue::array(2, 0.100000, 0.00000));
  HardRightSideKick_times[2][7] = 2.30000;
  HardRightSideKick_keys[2][7] = AL::ALValue::array(-1.35295, AL::ALValue::array(2, -0.100000, -0.00000), AL::ALValue::array(2, 0.166667, 0.00000));
  HardRightSideKick_times[2][8] = 2.80000;
  HardRightSideKick_keys[2][8] = AL::ALValue::array(-1.36829, AL::ALValue::array(2, -0.166667, 0.00487152), AL::ALValue::array(2, 0.166667, -0.00487152));
  HardRightSideKick_times[2][9] = 3.30000;
  HardRightSideKick_keys[2][9] = AL::ALValue::array(-1.38218, AL::ALValue::array(2, -0.166667, -0.00000), AL::ALValue::array(2, 0.00000, 0.00000));
  
  HardRightSideKick_names.push_back("LElbowRoll");
  HardRightSideKick_times[3].arraySetSize(10);
  HardRightSideKick_keys[3].arraySetSize(10);
  
  HardRightSideKick_times[3][0] = 0.400000;
  HardRightSideKick_keys[3][0] = AL::ALValue::array(-1.02007, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.133333, 0.00000));
  HardRightSideKick_times[3][1] = 0.800000;
  HardRightSideKick_keys[3][1] = AL::ALValue::array(-1.21650, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.133333, 0.00000));
  HardRightSideKick_times[3][2] = 1.20000;
  HardRightSideKick_keys[3][2] = AL::ALValue::array(-1.19810, AL::ALValue::array(2, -0.133333, -0.00498300), AL::ALValue::array(2, 0.100000, 0.00373725));
  HardRightSideKick_times[3][3] = 1.50000;
  HardRightSideKick_keys[3][3] = AL::ALValue::array(-1.19034, AL::ALValue::array(2, -0.100000, -0.00000), AL::ALValue::array(2, 0.100000, 0.00000));
  HardRightSideKick_times[3][4] = 1.80000;
  HardRightSideKick_keys[3][4] = AL::ALValue::array(-1.19349, AL::ALValue::array(2, -0.100000, -0.00000), AL::ALValue::array(2, 0.0333333, 0.00000));
  HardRightSideKick_times[3][5] = 1.90000;
  HardRightSideKick_keys[3][5] = AL::ALValue::array(-1.17654, AL::ALValue::array(2, -0.0333333, -0.00000), AL::ALValue::array(2, 0.0333333, 0.00000));
  HardRightSideKick_times[3][6] = 2.00000;
  HardRightSideKick_keys[3][6] = AL::ALValue::array(-1.18276, AL::ALValue::array(2, -0.0333333, 0.000511371), AL::ALValue::array(2, 0.100000, -0.00153411));
  HardRightSideKick_times[3][7] = 2.30000;
  HardRightSideKick_keys[3][7] = AL::ALValue::array(-1.18429, AL::ALValue::array(2, -0.100000, 0.000958838), AL::ALValue::array(2, 0.166667, -0.00159806));
  HardRightSideKick_times[3][8] = 2.80000;
  HardRightSideKick_keys[3][8] = AL::ALValue::array(-1.19043, AL::ALValue::array(2, -0.166667, -0.00000), AL::ALValue::array(2, 0.166667, 0.00000));
  HardRightSideKick_times[3][9] = 3.30000;
  HardRightSideKick_keys[3][9] = AL::ALValue::array(-1.02160, AL::ALValue::array(2, -0.166667, -0.00000), AL::ALValue::array(2, 0.00000, 0.00000));
  
  HardRightSideKick_names.push_back("RShoulderPitch");
  HardRightSideKick_times[4].arraySetSize(10);
  HardRightSideKick_keys[4].arraySetSize(10);
  
  HardRightSideKick_times[4][0] = 0.400000;
  HardRightSideKick_keys[4][0] = AL::ALValue::array(1.43126, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.133333, 0.00000));
  HardRightSideKick_times[4][1] = 0.800000;
  HardRightSideKick_keys[4][1] = AL::ALValue::array(1.45266, AL::ALValue::array(2, -0.133333, -0.00509927), AL::ALValue::array(2, 0.133333, 0.00509927));
  HardRightSideKick_times[4][2] = 1.20000;
  HardRightSideKick_keys[4][2] = AL::ALValue::array(1.46186, AL::ALValue::array(2, -0.133333, -0.000111675), AL::ALValue::array(2, 0.100000, 8.37564e-05));
  HardRightSideKick_times[4][3] = 1.50000;
  HardRightSideKick_keys[4][3] = AL::ALValue::array(1.46194, AL::ALValue::array(2, -0.100000, -8.37564e-05), AL::ALValue::array(2, 0.100000, 8.37564e-05));
  HardRightSideKick_times[4][4] = 1.80000;
  HardRightSideKick_keys[4][4] = AL::ALValue::array(1.97222, AL::ALValue::array(2, -0.100000, -0.00000), AL::ALValue::array(2, 0.0333333, 0.00000));
  HardRightSideKick_times[4][5] = 1.90000;
  HardRightSideKick_keys[4][5] = AL::ALValue::array(1.46501, AL::ALValue::array(2, -0.0333333, -0.00000), AL::ALValue::array(2, 0.0333333, 0.00000));
  HardRightSideKick_times[4][6] = 2.00000;
  HardRightSideKick_keys[4][6] = AL::ALValue::array(1.49407, AL::ALValue::array(2, -0.0333333, -0.00000), AL::ALValue::array(2, 0.100000, 0.00000));
  HardRightSideKick_times[4][7] = 2.30000;
  HardRightSideKick_keys[4][7] = AL::ALValue::array(1.48794, AL::ALValue::array(2, -0.100000, 0.00115040), AL::ALValue::array(2, 0.166667, -0.00191734));
  HardRightSideKick_times[4][8] = 2.80000;
  HardRightSideKick_keys[4][8] = AL::ALValue::array(1.48487, AL::ALValue::array(2, -0.166667, 0.00306836), AL::ALValue::array(2, 0.166667, -0.00306836));
  HardRightSideKick_times[4][9] = 3.30000;
  HardRightSideKick_keys[4][9] = AL::ALValue::array(1.43433, AL::ALValue::array(2, -0.166667, -0.00000), AL::ALValue::array(2, 0.00000, 0.00000));
  
  HardRightSideKick_names.push_back("RShoulderRoll");
  HardRightSideKick_times[5].arraySetSize(10);
  HardRightSideKick_keys[5].arraySetSize(10);
  
  HardRightSideKick_times[5][0] = 0.400000;
  HardRightSideKick_keys[5][0] = AL::ALValue::array(-0.326783, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.133333, 0.00000));
  HardRightSideKick_times[5][1] = 0.800000;
  HardRightSideKick_keys[5][1] = AL::ALValue::array(-0.292952, AL::ALValue::array(2, -0.133333, -0.00691674), AL::ALValue::array(2, 0.133333, 0.00691674));
  HardRightSideKick_times[5][2] = 1.20000;
  HardRightSideKick_keys[5][2] = AL::ALValue::array(-0.285283, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.100000, 0.00000));
  HardRightSideKick_times[5][3] = 1.50000;
  HardRightSideKick_keys[5][3] = AL::ALValue::array(-0.289967, AL::ALValue::array(2, -0.100000, 0.00468443), AL::ALValue::array(2, 0.100000, -0.00468443));
  HardRightSideKick_times[5][4] = 1.80000;
  HardRightSideKick_keys[5][4] = AL::ALValue::array(-0.453786, AL::ALValue::array(2, -0.100000, 0.163818), AL::ALValue::array(2, 0.0333333, -0.0546061));
  HardRightSideKick_times[5][5] = 1.90000;
  HardRightSideKick_keys[5][5] = AL::ALValue::array(-0.972599, AL::ALValue::array(2, -0.0333333, -0.00000), AL::ALValue::array(2, 0.0333333, 0.00000));
  HardRightSideKick_times[5][6] = 2.00000;
  HardRightSideKick_keys[5][6] = AL::ALValue::array(-0.929562, AL::ALValue::array(2, -0.0333333, -0.0430363), AL::ALValue::array(2, 0.100000, 0.129109));
  HardRightSideKick_times[5][7] = 2.30000;
  HardRightSideKick_keys[5][7] = AL::ALValue::array(-0.268407, AL::ALValue::array(2, -0.100000, -0.00000), AL::ALValue::array(2, 0.166667, 0.00000));
  HardRightSideKick_times[5][8] = 2.80000;
  HardRightSideKick_keys[5][8] = AL::ALValue::array(-0.269941, AL::ALValue::array(2, -0.166667, 0.00153415), AL::ALValue::array(2, 0.166667, -0.00153415));
  HardRightSideKick_times[5][9] = 3.30000;
  HardRightSideKick_keys[5][9] = AL::ALValue::array(-0.320648, AL::ALValue::array(2, -0.166667, -0.00000), AL::ALValue::array(2, 0.00000, 0.00000));
  
  HardRightSideKick_names.push_back("RElbowYaw");
  HardRightSideKick_times[6].arraySetSize(10);
  HardRightSideKick_keys[6].arraySetSize(10);
  
  HardRightSideKick_times[6][0] = 0.400000;
  HardRightSideKick_keys[6][0] = AL::ALValue::array(1.38363, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.133333, 0.00000));
  HardRightSideKick_times[6][1] = 0.800000;
  HardRightSideKick_keys[6][1] = AL::ALValue::array(1.36990, AL::ALValue::array(2, -0.133333, 0.00279834), AL::ALValue::array(2, 0.133333, -0.00279834));
  HardRightSideKick_times[6][2] = 1.20000;
  HardRightSideKick_keys[6][2] = AL::ALValue::array(1.36684, AL::ALValue::array(2, -0.133333, 0.000111853), AL::ALValue::array(2, 0.100000, -8.38896e-05));
  HardRightSideKick_times[6][3] = 1.50000;
  HardRightSideKick_keys[6][3] = AL::ALValue::array(1.36675, AL::ALValue::array(2, -0.100000, -0.00000), AL::ALValue::array(2, 0.100000, 0.00000));
  HardRightSideKick_times[6][4] = 1.80000;
  HardRightSideKick_keys[6][4] = AL::ALValue::array(1.36837, AL::ALValue::array(2, -0.100000, -0.00000), AL::ALValue::array(2, 0.0333333, 0.00000));
  HardRightSideKick_times[6][5] = 1.90000;
  HardRightSideKick_keys[6][5] = AL::ALValue::array(1.36215, AL::ALValue::array(2, -0.0333333, 0.00230093), AL::ALValue::array(2, 0.0333333, -0.00230093));
  HardRightSideKick_times[6][6] = 2.00000;
  HardRightSideKick_keys[6][6] = AL::ALValue::array(1.35456, AL::ALValue::array(2, -0.0333333, -0.00000), AL::ALValue::array(2, 0.100000, 0.00000));
  HardRightSideKick_times[6][7] = 2.30000;
  HardRightSideKick_keys[6][7] = AL::ALValue::array(1.35917, AL::ALValue::array(2, -0.100000, -0.00000), AL::ALValue::array(2, 0.166667, 0.00000));
  HardRightSideKick_times[6][8] = 2.80000;
  HardRightSideKick_keys[6][8] = AL::ALValue::array(1.35917, AL::ALValue::array(2, -0.166667, -0.00000), AL::ALValue::array(2, 0.166667, 0.00000));
  HardRightSideKick_times[6][9] = 3.30000;
  HardRightSideKick_keys[6][9] = AL::ALValue::array(1.38209, AL::ALValue::array(2, -0.166667, -0.00000), AL::ALValue::array(2, 0.00000, 0.00000));
  
  HardRightSideKick_names.push_back("RElbowRoll");
  HardRightSideKick_times[7].arraySetSize(10);
  HardRightSideKick_keys[7].arraySetSize(10);
  
  HardRightSideKick_times[7][0] = 0.400000;
  HardRightSideKick_keys[7][0] = AL::ALValue::array(1.02782, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.133333, 0.00000));
  HardRightSideKick_times[7][1] = 0.800000;
  HardRightSideKick_keys[7][1] = AL::ALValue::array(1.01393, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.133333, 0.00000));
  HardRightSideKick_times[7][2] = 1.20000;
  HardRightSideKick_keys[7][2] = AL::ALValue::array(1.01393, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.100000, 0.00000));
  HardRightSideKick_times[7][3] = 1.50000;
  HardRightSideKick_keys[7][3] = AL::ALValue::array(1.01248, AL::ALValue::array(2, -0.100000, 0.00145042), AL::ALValue::array(2, 0.100000, -0.00145042));
  HardRightSideKick_times[7][4] = 1.80000;
  HardRightSideKick_keys[7][4] = AL::ALValue::array(0.436332, AL::ALValue::array(2, -0.100000, -0.00000), AL::ALValue::array(2, 0.0333333, 0.00000));
  HardRightSideKick_times[7][5] = 1.90000;
  HardRightSideKick_keys[7][5] = AL::ALValue::array(1.00788, AL::ALValue::array(2, -0.0333333, -0.00000), AL::ALValue::array(2, 0.0333333, 0.00000));
  HardRightSideKick_times[7][6] = 2.00000;
  HardRightSideKick_keys[7][6] = AL::ALValue::array(1.00166, AL::ALValue::array(2, -0.0333333, -0.00000), AL::ALValue::array(2, 0.100000, 0.00000));
  HardRightSideKick_times[7][7] = 2.30000;
  HardRightSideKick_keys[7][7] = AL::ALValue::array(1.01393, AL::ALValue::array(2, -0.100000, -0.00000), AL::ALValue::array(2, 0.166667, 0.00000));
  HardRightSideKick_times[7][8] = 2.80000;
  HardRightSideKick_keys[7][8] = AL::ALValue::array(1.01393, AL::ALValue::array(2, -0.166667, -0.00000), AL::ALValue::array(2, 0.166667, 0.00000));
  HardRightSideKick_times[7][9] = 3.30000;
  HardRightSideKick_keys[7][9] = AL::ALValue::array(1.02629, AL::ALValue::array(2, -0.166667, -0.00000), AL::ALValue::array(2, 0.00000, 0.00000));
  
  HardRightSideKick_names.push_back("LHipYawPitch");
  HardRightSideKick_times[8].arraySetSize(10);
  HardRightSideKick_keys[8].arraySetSize(10);
  
  HardRightSideKick_times[8][0] = 0.400000;
  HardRightSideKick_keys[8][0] = AL::ALValue::array(4.19617e-05, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.133333, 0.00000));
  HardRightSideKick_times[8][1] = 0.800000;
  HardRightSideKick_keys[8][1] = AL::ALValue::array(-0.0106960, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.133333, 0.00000));
  HardRightSideKick_times[8][2] = 1.20000;
  HardRightSideKick_keys[8][2] = AL::ALValue::array(-0.00609404, AL::ALValue::array(2, -0.133333, -0.00292190), AL::ALValue::array(2, 0.100000, 0.00219143));
  HardRightSideKick_times[8][3] = 1.50000;
  HardRightSideKick_keys[8][3] = AL::ALValue::array(0.00464395, AL::ALValue::array(2, -0.100000, -0.0107380), AL::ALValue::array(2, 0.100000, 0.0107380));
  HardRightSideKick_times[8][4] = 1.80000;
  HardRightSideKick_keys[8][4] = AL::ALValue::array(0.104354, AL::ALValue::array(2, -0.100000, -0.0360490), AL::ALValue::array(2, 0.0333333, 0.0120163));
  HardRightSideKick_times[8][5] = 1.90000;
  HardRightSideKick_keys[8][5] = AL::ALValue::array(0.148840, AL::ALValue::array(2, -0.0333333, -0.00000), AL::ALValue::array(2, 0.0333333, 0.00000));
  HardRightSideKick_times[8][6] = 2.00000;
  HardRightSideKick_keys[8][6] = AL::ALValue::array(0.147306, AL::ALValue::array(2, -0.0333333, 0.000894830), AL::ALValue::array(2, 0.100000, -0.00268449));
  HardRightSideKick_times[8][7] = 2.30000;
  HardRightSideKick_keys[8][7] = AL::ALValue::array(0.138102, AL::ALValue::array(2, -0.100000, 0.00920399), AL::ALValue::array(2, 0.166667, -0.0153400));
  HardRightSideKick_times[8][8] = 2.80000;
  HardRightSideKick_keys[8][8] = AL::ALValue::array(-0.127280, AL::ALValue::array(2, -0.166667, -0.00000), AL::ALValue::array(2, 0.166667, 0.00000));
  HardRightSideKick_times[8][9] = 3.30000;
  HardRightSideKick_keys[8][9] = AL::ALValue::array(4.19617e-05, AL::ALValue::array(2, -0.166667, -0.00000), AL::ALValue::array(2, 0.00000, 0.00000));
  
  HardRightSideKick_names.push_back("LHipRoll");
  HardRightSideKick_times[9].arraySetSize(10);
  HardRightSideKick_keys[9].arraySetSize(10);
  
  HardRightSideKick_times[9][0] = 0.400000;
  HardRightSideKick_keys[9][0] = AL::ALValue::array(0.00157596, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.133333, 0.00000));
  HardRightSideKick_times[9][1] = 0.800000;
  HardRightSideKick_keys[9][1] = AL::ALValue::array(0.251617, AL::ALValue::array(2, -0.133333, -0.0815435), AL::ALValue::array(2, 0.133333, 0.0815435));
  HardRightSideKick_times[9][2] = 1.20000;
  HardRightSideKick_keys[9][2] = AL::ALValue::array(0.490837, AL::ALValue::array(2, -0.133333, -0.000114028), AL::ALValue::array(2, 0.100000, 8.55208e-05));
  HardRightSideKick_times[9][3] = 1.50000;
  HardRightSideKick_keys[9][3] = AL::ALValue::array(0.490923, AL::ALValue::array(2, -0.100000, -0.00000), AL::ALValue::array(2, 0.100000, 0.00000));
  HardRightSideKick_times[9][4] = 1.80000;
  HardRightSideKick_keys[9][4] = AL::ALValue::array(0.490923, AL::ALValue::array(2, -0.100000, -0.00000), AL::ALValue::array(2, 0.0333333, 0.00000));
  HardRightSideKick_times[9][5] = 1.90000;
  HardRightSideKick_keys[9][5] = AL::ALValue::array(0.420357, AL::ALValue::array(2, -0.0333333, 8.37564e-05), AL::ALValue::array(2, 0.0333333, -8.37564e-05));
  HardRightSideKick_times[9][6] = 2.00000;
  HardRightSideKick_keys[9][6] = AL::ALValue::array(0.420274, AL::ALValue::array(2, -0.0333333, -0.00000), AL::ALValue::array(2, 0.100000, 0.00000));
  HardRightSideKick_times[9][7] = 2.30000;
  HardRightSideKick_keys[9][7] = AL::ALValue::array(0.490837, AL::ALValue::array(2, -0.100000, -0.0101756), AL::ALValue::array(2, 0.166667, 0.0169594));
  HardRightSideKick_times[9][8] = 2.80000;
  HardRightSideKick_keys[9][8] = AL::ALValue::array(0.507797, AL::ALValue::array(2, -0.166667, -0.00000), AL::ALValue::array(2, 0.166667, 0.00000));
  HardRightSideKick_times[9][9] = 3.30000;
  HardRightSideKick_keys[9][9] = AL::ALValue::array(4.19617e-05, AL::ALValue::array(2, -0.166667, -0.00000), AL::ALValue::array(2, 0.00000, 0.00000));
  
  HardRightSideKick_names.push_back("LHipPitch");
  HardRightSideKick_times[10].arraySetSize(10);
  HardRightSideKick_keys[10].arraySetSize(10);
  
  HardRightSideKick_times[10][0] = 0.400000;
  HardRightSideKick_keys[10][0] = AL::ALValue::array(-0.435613, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.133333, 0.00000));
  HardRightSideKick_times[10][1] = 0.800000;
  HardRightSideKick_keys[10][1] = AL::ALValue::array(-0.343573, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.133333, 0.00000));
  HardRightSideKick_times[10][2] = 1.20000;
  HardRightSideKick_keys[10][2] = AL::ALValue::array(-0.506262, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.100000, 0.00000));
  HardRightSideKick_times[10][3] = 1.50000;
  HardRightSideKick_keys[10][3] = AL::ALValue::array(-0.383972, AL::ALValue::array(2, -0.100000, -0.0271149), AL::ALValue::array(2, 0.100000, 0.0271149));
  HardRightSideKick_times[10][4] = 1.80000;
  HardRightSideKick_keys[10][4] = AL::ALValue::array(-0.343573, AL::ALValue::array(2, -0.100000, -0.00459725), AL::ALValue::array(2, 0.0333333, 0.00153242));
  HardRightSideKick_times[10][5] = 1.90000;
  HardRightSideKick_keys[10][5] = AL::ALValue::array(-0.342041, AL::ALValue::array(2, -0.0333333, -0.00000), AL::ALValue::array(2, 0.0333333, 0.00000));
  HardRightSideKick_times[10][6] = 2.00000;
  HardRightSideKick_keys[10][6] = AL::ALValue::array(-0.343659, AL::ALValue::array(2, -0.0333333, -0.00000), AL::ALValue::array(2, 0.100000, 0.00000));
  HardRightSideKick_times[10][7] = 2.30000;
  HardRightSideKick_keys[10][7] = AL::ALValue::array(-0.342125, AL::ALValue::array(2, -0.100000, -0.00000), AL::ALValue::array(2, 0.166667, 0.00000));
  HardRightSideKick_times[10][8] = 2.80000;
  HardRightSideKick_keys[10][8] = AL::ALValue::array(-0.388060, AL::ALValue::array(2, -0.166667, 0.0155814), AL::ALValue::array(2, 0.166667, -0.0155814));
  HardRightSideKick_times[10][9] = 3.30000;
  HardRightSideKick_keys[10][9] = AL::ALValue::array(-0.435613, AL::ALValue::array(2, -0.166667, -0.00000), AL::ALValue::array(2, 0.00000, 0.00000));
  
  HardRightSideKick_names.push_back("LKneePitch");
  HardRightSideKick_times[11].arraySetSize(10);
  HardRightSideKick_keys[11].arraySetSize(10);
  
  HardRightSideKick_times[11][0] = 0.400000;
  HardRightSideKick_keys[11][0] = AL::ALValue::array(0.697927, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.133333, 0.00000));
  HardRightSideKick_times[11][1] = 0.800000;
  HardRightSideKick_keys[11][1] = AL::ALValue::array(1.29159, AL::ALValue::array(2, -0.133333, -0.0108227), AL::ALValue::array(2, 0.133333, 0.0108227));
  HardRightSideKick_times[11][2] = 1.20000;
  HardRightSideKick_keys[11][2] = AL::ALValue::array(1.30241, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.100000, 0.00000));
  HardRightSideKick_times[11][3] = 1.50000;
  HardRightSideKick_keys[11][3] = AL::ALValue::array(1.29619, AL::ALValue::array(2, -0.100000, -0.00000), AL::ALValue::array(2, 0.100000, 0.00000));
  HardRightSideKick_times[11][4] = 1.80000;
  HardRightSideKick_keys[11][4] = AL::ALValue::array(1.31613, AL::ALValue::array(2, -0.100000, -0.00000), AL::ALValue::array(2, 0.0333333, 0.00000));
  HardRightSideKick_times[11][5] = 1.90000;
  HardRightSideKick_keys[11][5] = AL::ALValue::array(1.29619, AL::ALValue::array(2, -0.0333333, 0.00535495), AL::ALValue::array(2, 0.0333333, -0.00535495));
  HardRightSideKick_times[11][6] = 2.00000;
  HardRightSideKick_keys[11][6] = AL::ALValue::array(1.28400, AL::ALValue::array(2, -0.0333333, -0.00000), AL::ALValue::array(2, 0.100000, 0.00000));
  HardRightSideKick_times[11][7] = 2.30000;
  HardRightSideKick_keys[11][7] = AL::ALValue::array(1.30701, AL::ALValue::array(2, -0.100000, -0.00000), AL::ALValue::array(2, 0.166667, 0.00000));
  HardRightSideKick_times[11][8] = 2.80000;
  HardRightSideKick_keys[11][8] = AL::ALValue::array(1.24096, AL::ALValue::array(2, -0.166667, 0.0660468), AL::ALValue::array(2, 0.166667, -0.0660468));
  HardRightSideKick_times[11][9] = 3.30000;
  HardRightSideKick_keys[11][9] = AL::ALValue::array(0.697927, AL::ALValue::array(2, -0.166667, -0.00000), AL::ALValue::array(2, 0.00000, 0.00000));
  
  HardRightSideKick_names.push_back("LAnklePitch");
  HardRightSideKick_times[12].arraySetSize(10);
  HardRightSideKick_keys[12].arraySetSize(10);
  
  HardRightSideKick_times[12][0] = 0.400000;
  HardRightSideKick_keys[12][0] = AL::ALValue::array(-0.349794, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.133333, 0.00000));
  HardRightSideKick_times[12][1] = 0.800000;
  HardRightSideKick_keys[12][1] = AL::ALValue::array(-0.780848, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.133333, 0.00000));
  HardRightSideKick_times[12][2] = 1.20000;
  HardRightSideKick_keys[12][2] = AL::ALValue::array(-0.681054, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.100000, 0.00000));
  HardRightSideKick_times[12][3] = 1.50000;
  HardRightSideKick_keys[12][3] = AL::ALValue::array(-0.790051, AL::ALValue::array(2, -0.100000, 0.00153411), AL::ALValue::array(2, 0.100000, -0.00153411));
  HardRightSideKick_times[12][4] = 1.80000;
  HardRightSideKick_keys[12][4] = AL::ALValue::array(-0.791585, AL::ALValue::array(2, -0.100000, -0.00000), AL::ALValue::array(2, 0.0333333, 0.00000));
  HardRightSideKick_times[12][5] = 1.90000;
  HardRightSideKick_keys[12][5] = AL::ALValue::array(-0.774711, AL::ALValue::array(2, -0.0333333, -0.00315205), AL::ALValue::array(2, 0.0333333, 0.00315205));
  HardRightSideKick_times[12][6] = 2.00000;
  HardRightSideKick_keys[12][6] = AL::ALValue::array(-0.771559, AL::ALValue::array(2, -0.0333333, -0.00000), AL::ALValue::array(2, 0.100000, 0.00000));
  HardRightSideKick_times[12][7] = 2.30000;
  HardRightSideKick_keys[12][7] = AL::ALValue::array(-0.785367, AL::ALValue::array(2, -0.100000, -0.00000), AL::ALValue::array(2, 0.166667, 0.00000));
  HardRightSideKick_times[12][8] = 2.80000;
  HardRightSideKick_keys[12][8] = AL::ALValue::array(-0.731761, AL::ALValue::array(2, -0.166667, -0.0536060), AL::ALValue::array(2, 0.166667, 0.0536060));
  HardRightSideKick_times[12][9] = 3.30000;
  HardRightSideKick_keys[12][9] = AL::ALValue::array(-0.348260, AL::ALValue::array(2, -0.166667, -0.00000), AL::ALValue::array(2, 0.00000, 0.00000));
  
  HardRightSideKick_names.push_back("LAnkleRoll");
  HardRightSideKick_times[13].arraySetSize(10);
  HardRightSideKick_keys[13].arraySetSize(10);
  
  HardRightSideKick_times[13][0] = 0.400000;
  HardRightSideKick_keys[13][0] = AL::ALValue::array(4.19617e-05, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.133333, 0.00000));
  HardRightSideKick_times[13][1] = 0.800000;
  HardRightSideKick_keys[13][1] = AL::ALValue::array(0.0951499, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.133333, 0.00000));
  HardRightSideKick_times[13][2] = 1.20000;
  HardRightSideKick_keys[13][2] = AL::ALValue::array(0.0873960, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.100000, 0.00000));
  HardRightSideKick_times[13][3] = 1.50000;
  HardRightSideKick_keys[13][3] = AL::ALValue::array(0.0951499, AL::ALValue::array(2, -0.100000, -0.00000), AL::ALValue::array(2, 0.100000, 0.00000));
  HardRightSideKick_times[13][4] = 1.80000;
  HardRightSideKick_keys[13][4] = AL::ALValue::array(0.0951499, AL::ALValue::array(2, -0.100000, -0.00000), AL::ALValue::array(2, 0.0333333, 0.00000));
  HardRightSideKick_times[13][5] = 1.90000;
  HardRightSideKick_keys[13][5] = AL::ALValue::array(0.104354, AL::ALValue::array(2, -0.0333333, -0.00000), AL::ALValue::array(2, 0.0333333, 0.00000));
  HardRightSideKick_times[13][6] = 2.00000;
  HardRightSideKick_keys[13][6] = AL::ALValue::array(0.0950660, AL::ALValue::array(2, -0.0333333, -0.00000), AL::ALValue::array(2, 0.100000, 0.00000));
  HardRightSideKick_times[13][7] = 2.30000;
  HardRightSideKick_keys[13][7] = AL::ALValue::array(0.0950660, AL::ALValue::array(2, -0.100000, -0.00000), AL::ALValue::array(2, 0.166667, 0.00000));
  HardRightSideKick_times[13][8] = 2.80000;
  HardRightSideKick_keys[13][8] = AL::ALValue::array(-0.0843280, AL::ALValue::array(2, -0.166667, -0.00000), AL::ALValue::array(2, 0.166667, 0.00000));
  HardRightSideKick_times[13][9] = 3.30000;
  HardRightSideKick_keys[13][9] = AL::ALValue::array(4.19617e-05, AL::ALValue::array(2, -0.166667, -0.00000), AL::ALValue::array(2, 0.00000, 0.00000));
  
  HardRightSideKick_names.push_back("RHipRoll");
  HardRightSideKick_times[14].arraySetSize(10);
  HardRightSideKick_keys[14].arraySetSize(10);
  
  HardRightSideKick_times[14][0] = 0.400000;
  HardRightSideKick_keys[14][0] = AL::ALValue::array(4.19617e-05, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.133333, 0.00000));
  HardRightSideKick_times[14][1] = 0.800000;
  HardRightSideKick_keys[14][1] = AL::ALValue::array(0.165714, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.133333, 0.00000));
  HardRightSideKick_times[14][2] = 1.20000;
  HardRightSideKick_keys[14][2] = AL::ALValue::array(0.0873960, AL::ALValue::array(2, -0.133333, 0.0254206), AL::ALValue::array(2, 0.100000, -0.0190654));
  HardRightSideKick_times[14][3] = 1.50000;
  HardRightSideKick_keys[14][3] = AL::ALValue::array(0.0322560, AL::ALValue::array(2, -0.100000, -0.00000), AL::ALValue::array(2, 0.100000, 0.00000));
  HardRightSideKick_times[14][4] = 1.80000;
  HardRightSideKick_keys[14][4] = AL::ALValue::array(0.0506639, AL::ALValue::array(2, -0.100000, -0.0184080), AL::ALValue::array(2, 0.0333333, 0.00613600));
  HardRightSideKick_times[14][5] = 1.90000;
  HardRightSideKick_keys[14][5] = AL::ALValue::array(0.379471, AL::ALValue::array(2, -0.0333333, -0.00000), AL::ALValue::array(2, 0.0333333, 0.00000));
  HardRightSideKick_times[14][6] = 2.00000;
  HardRightSideKick_keys[14][6] = AL::ALValue::array(0.375789, AL::ALValue::array(2, -0.0333333, 0.00132965), AL::ALValue::array(2, 0.100000, -0.00398895));
  HardRightSideKick_times[14][7] = 2.30000;
  HardRightSideKick_keys[14][7] = AL::ALValue::array(0.363515, AL::ALValue::array(2, -0.100000, -0.00000), AL::ALValue::array(2, 0.166667, 0.00000));
  HardRightSideKick_times[14][8] = 2.80000;
  HardRightSideKick_keys[14][8] = AL::ALValue::array(0.366667, AL::ALValue::array(2, -0.166667, -0.00000), AL::ALValue::array(2, 0.166667, 0.00000));
  HardRightSideKick_times[14][9] = 3.30000;
  HardRightSideKick_keys[14][9] = AL::ALValue::array(4.19617e-05, AL::ALValue::array(2, -0.166667, -0.00000), AL::ALValue::array(2, 0.00000, 0.00000));
  
  HardRightSideKick_names.push_back("RHipPitch");
  HardRightSideKick_times[15].arraySetSize(10);
  HardRightSideKick_keys[15].arraySetSize(10);
  
  HardRightSideKick_times[15][0] = 0.400000;
  HardRightSideKick_keys[15][0] = AL::ALValue::array(-0.437231, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.133333, 0.00000));
  HardRightSideKick_times[15][1] = 0.800000;
  HardRightSideKick_keys[15][1] = AL::ALValue::array(-0.115092, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.133333, 0.00000));
  HardRightSideKick_times[15][2] = 1.20000;
  HardRightSideKick_keys[15][2] = AL::ALValue::array(-0.248467, AL::ALValue::array(2, -0.133333, 0.0426599), AL::ALValue::array(2, 0.100000, -0.0319949));
  HardRightSideKick_times[15][3] = 1.50000;
  HardRightSideKick_keys[15][3] = AL::ALValue::array(-0.339056, AL::ALValue::array(2, -0.100000, -0.00000), AL::ALValue::array(2, 0.100000, 0.00000));
  HardRightSideKick_times[15][4] = 1.80000;
  HardRightSideKick_keys[15][4] = AL::ALValue::array(-0.329852, AL::ALValue::array(2, -0.100000, -0.00000), AL::ALValue::array(2, 0.0333333, 0.00000));
  HardRightSideKick_times[15][5] = 1.90000;
  HardRightSideKick_keys[15][5] = AL::ALValue::array(-0.478650, AL::ALValue::array(2, -0.0333333, -0.00000), AL::ALValue::array(2, 0.0333333, 0.00000));
  HardRightSideKick_times[15][6] = 2.00000;
  HardRightSideKick_keys[15][6] = AL::ALValue::array(-0.473963, AL::ALValue::array(2, -0.0333333, -0.00468623), AL::ALValue::array(2, 0.100000, 0.0140587));
  HardRightSideKick_times[15][7] = 2.30000;
  HardRightSideKick_keys[15][7] = AL::ALValue::array(-0.154892, AL::ALValue::array(2, -0.100000, -0.0634587), AL::ALValue::array(2, 0.166667, 0.105764));
  HardRightSideKick_times[15][8] = 2.80000;
  HardRightSideKick_keys[15][8] = AL::ALValue::array(0.0337060, AL::ALValue::array(2, -0.166667, -0.00000), AL::ALValue::array(2, 0.166667, 0.00000));
  HardRightSideKick_times[15][9] = 3.30000;
  HardRightSideKick_keys[15][9] = AL::ALValue::array(-0.437231, AL::ALValue::array(2, -0.166667, -0.00000), AL::ALValue::array(2, 0.00000, 0.00000));
  
  HardRightSideKick_names.push_back("RKneePitch");
  HardRightSideKick_times[16].arraySetSize(10);
  HardRightSideKick_keys[16].arraySetSize(10);
  
  HardRightSideKick_times[16][0] = 0.400000;
  HardRightSideKick_keys[16][0] = AL::ALValue::array(0.699545, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.133333, 0.00000));
  HardRightSideKick_times[16][1] = 0.800000;
  HardRightSideKick_keys[16][1] = AL::ALValue::array(0.704148, AL::ALValue::array(2, -0.133333, -0.00460241), AL::ALValue::array(2, 0.133333, 0.00460241));
  HardRightSideKick_times[16][2] = 1.20000;
  HardRightSideKick_keys[16][2] = AL::ALValue::array(1.01240, AL::ALValue::array(2, -0.133333, -0.0975915), AL::ALValue::array(2, 0.100000, 0.0731936));
  HardRightSideKick_times[16][3] = 1.50000;
  HardRightSideKick_keys[16][3] = AL::ALValue::array(1.21650, AL::ALValue::array(2, -0.100000, -0.00000), AL::ALValue::array(2, 0.100000, 0.00000));
  HardRightSideKick_times[16][4] = 1.80000;
  HardRightSideKick_keys[16][4] = AL::ALValue::array(0.179519, AL::ALValue::array(2, -0.100000, -0.00000), AL::ALValue::array(2, 0.0333333, 0.00000));
  HardRightSideKick_times[16][5] = 1.90000;
  HardRightSideKick_keys[16][5] = AL::ALValue::array(0.316046, AL::ALValue::array(2, -0.0333333, -0.00145036), AL::ALValue::array(2, 0.0333333, 0.00145036));
  HardRightSideKick_times[16][6] = 2.00000;
  HardRightSideKick_keys[16][6] = AL::ALValue::array(0.317496, AL::ALValue::array(2, -0.0333333, -0.00000), AL::ALValue::array(2, 0.100000, 0.00000));
  HardRightSideKick_times[16][7] = 2.30000;
  HardRightSideKick_keys[16][7] = AL::ALValue::array(0.257670, AL::ALValue::array(2, -0.100000, -0.00000), AL::ALValue::array(2, 0.166667, 0.00000));
  HardRightSideKick_times[16][8] = 2.80000;
  HardRightSideKick_keys[16][8] = AL::ALValue::array(0.296104, AL::ALValue::array(2, -0.166667, -0.0384339), AL::ALValue::array(2, 0.166667, 0.0384339));
  HardRightSideKick_times[16][9] = 3.30000;
  HardRightSideKick_keys[16][9] = AL::ALValue::array(0.698011, AL::ALValue::array(2, -0.166667, -0.00000), AL::ALValue::array(2, 0.00000, 0.00000));
  
  HardRightSideKick_names.push_back("RAnklePitch");
  HardRightSideKick_times[17].arraySetSize(10);
  HardRightSideKick_keys[17].arraySetSize(10);
  
  HardRightSideKick_times[17][0] = 0.400000;
  HardRightSideKick_keys[17][0] = AL::ALValue::array(-0.348176, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.133333, 0.00000));
  HardRightSideKick_times[17][1] = 0.800000;
  HardRightSideKick_keys[17][1] = AL::ALValue::array(-0.409536, AL::ALValue::array(2, -0.133333, 0.0388755), AL::ALValue::array(2, 0.133333, -0.0388755));
  HardRightSideKick_times[17][2] = 1.20000;
  HardRightSideKick_keys[17][2] = AL::ALValue::array(-0.581429, AL::ALValue::array(2, -0.133333, 0.0473347), AL::ALValue::array(2, 0.100000, -0.0355010));
  HardRightSideKick_times[17][3] = 1.50000;
  HardRightSideKick_keys[17][3] = AL::ALValue::array(-0.658043, AL::ALValue::array(2, -0.100000, -0.00000), AL::ALValue::array(2, 0.100000, 0.00000));
  HardRightSideKick_times[17][4] = 1.80000;
  HardRightSideKick_keys[17][4] = AL::ALValue::array(0.259288, AL::ALValue::array(2, -0.100000, -0.00460244), AL::ALValue::array(2, 0.0333333, 0.00153415));
  HardRightSideKick_times[17][5] = 1.90000;
  HardRightSideKick_keys[17][5] = AL::ALValue::array(0.260822, AL::ALValue::array(2, -0.0333333, -0.000753109), AL::ALValue::array(2, 0.0333333, 0.000753109));
  HardRightSideKick_times[17][6] = 2.00000;
  HardRightSideKick_keys[17][6] = AL::ALValue::array(0.263807, AL::ALValue::array(2, -0.0333333, -0.00000), AL::ALValue::array(2, 0.100000, 0.00000));
  HardRightSideKick_times[17][7] = 2.30000;
  HardRightSideKick_keys[17][7] = AL::ALValue::array(0.00456004, AL::ALValue::array(2, -0.100000, 0.0521456), AL::ALValue::array(2, 0.166667, -0.0869093));
  HardRightSideKick_times[17][8] = 2.80000;
  HardRightSideKick_keys[17][8] = AL::ALValue::array(-0.153358, AL::ALValue::array(2, -0.166667, 0.0590450), AL::ALValue::array(2, 0.166667, -0.0590450));
  HardRightSideKick_times[17][9] = 3.30000;
  HardRightSideKick_keys[17][9] = AL::ALValue::array(-0.349710, AL::ALValue::array(2, -0.166667, -0.00000), AL::ALValue::array(2, 0.00000, 0.00000));
  
  HardRightSideKick_names.push_back("RAnkleRoll");
  HardRightSideKick_times[18].arraySetSize(10);
  HardRightSideKick_keys[18].arraySetSize(10);
  
  HardRightSideKick_times[18][0] = 0.400000;
  HardRightSideKick_keys[18][0] = AL::ALValue::array(4.19617e-05, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.133333, 0.00000));
  HardRightSideKick_times[18][1] = 0.800000;
  HardRightSideKick_keys[18][1] = AL::ALValue::array(0.214801, AL::ALValue::array(2, -0.133333, -0.0495854), AL::ALValue::array(2, 0.133333, 0.0495854));
  HardRightSideKick_times[18][2] = 1.20000;
  HardRightSideKick_keys[18][2] = AL::ALValue::array(0.297554, AL::ALValue::array(2, -0.133333, -0.0189925), AL::ALValue::array(2, 0.100000, 0.0142444));
  HardRightSideKick_times[18][3] = 1.50000;
  HardRightSideKick_keys[18][3] = AL::ALValue::array(0.314512, AL::ALValue::array(2, -0.100000, -0.00000), AL::ALValue::array(2, 0.100000, 0.00000));
  HardRightSideKick_times[18][4] = 1.80000;
  HardRightSideKick_keys[18][4] = AL::ALValue::array(-0.104270, AL::ALValue::array(2, -0.100000, -0.00000), AL::ALValue::array(2, 0.0333333, 0.00000));
  HardRightSideKick_times[18][5] = 1.90000;
  HardRightSideKick_keys[18][5] = AL::ALValue::array(0.349794, AL::ALValue::array(2, -0.0333333, -0.00000), AL::ALValue::array(2, 0.0333333, 0.00000));
  HardRightSideKick_times[18][6] = 2.00000;
  HardRightSideKick_keys[18][6] = AL::ALValue::array(0.309826, AL::ALValue::array(2, -0.0333333, 0.0299200), AL::ALValue::array(2, 0.100000, -0.0897599));
  HardRightSideKick_times[18][7] = 2.30000;
  HardRightSideKick_keys[18][7] = AL::ALValue::array(-0.00924597, AL::ALValue::array(2, -0.100000, -0.00000), AL::ALValue::array(2, 0.166667, 0.00000));
  HardRightSideKick_times[18][8] = 2.80000;
  HardRightSideKick_keys[18][8] = AL::ALValue::array(0.131966, AL::ALValue::array(2, -0.166667, -0.00000), AL::ALValue::array(2, 0.166667, 0.00000));
  HardRightSideKick_times[18][9] = 3.30000;
  HardRightSideKick_keys[18][9] = AL::ALValue::array(4.19617e-05, AL::ALValue::array(2, -0.166667, -0.00000), AL::ALValue::array(2, 0.00000, 0.00000)); 
  
  
}

int HardRightSideKick::ExecutePost() {
  return motion->post.angleInterpolationBezier(HardRightSideKick_names, HardRightSideKick_times, HardRightSideKick_keys); 
} 
