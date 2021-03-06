#include "SoftLeftSideKick.h"

#include "hal/robot/generic_nao/kAlBroker.h"

namespace {
  SpecialActionRegistrar<SoftLeftSideKick>::Type temp("SoftLeftSideKick");
}

SoftLeftSideKick::SoftLeftSideKick() {
  Initialize();
  Logger::Instance().WriteMsg("SP:SoftLeftSideKick","Initialized!",Logger::ExtraInfo);
  
  try {
    motion = KAlBroker::Instance().GetBroker()->getMotionProxy();
  } catch (AL::ALError& e) {
    Logger::Instance().WriteMsg("SP:SoftLeftSideKick","Error in getting motion proxy",Logger::FatalError);
  }
  
}




void SoftLeftSideKick::Initialize() {
  
  /******************************** Soft Left Side Kick ****************************/
  
  SoftLeftSideKick_names.reserve(19);
  SoftLeftSideKick_times.arraySetSize(19);
  SoftLeftSideKick_keys.arraySetSize(19);
  
  SoftLeftSideKick_names.push_back("LShoulderPitch");
  SoftLeftSideKick_times[0].arraySetSize(10);
  SoftLeftSideKick_keys[0].arraySetSize(10);
  
  SoftLeftSideKick_times[0][0] = 0.400000;
  SoftLeftSideKick_keys[0][0] = AL::ALValue::array(1.43126, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.133333, 0.00000));
  SoftLeftSideKick_times[0][1] = 0.800000;
  SoftLeftSideKick_keys[0][1] = AL::ALValue::array(1.45266, AL::ALValue::array(2, -0.133333, -0.00153238), AL::ALValue::array(2, 0.133333, 0.00153238));
  SoftLeftSideKick_times[0][2] = 1.20000;
  SoftLeftSideKick_keys[0][2] = AL::ALValue::array(1.45419, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.0666667, 0.00000));
  SoftLeftSideKick_times[0][3] = 1.40000;
  SoftLeftSideKick_keys[0][3] = AL::ALValue::array(1.45112, AL::ALValue::array(2, -0.0666667, -0.00000), AL::ALValue::array(2, 0.100000, 0.00000));
  SoftLeftSideKick_times[0][4] = 1.70000;
  SoftLeftSideKick_keys[0][4] = AL::ALValue::array(1.46186, AL::ALValue::array(2, -0.100000, -0.00369833), AL::ALValue::array(2, 0.0666667, 0.00246555));
  SoftLeftSideKick_times[0][5] = 1.90000;
  SoftLeftSideKick_keys[0][5] = AL::ALValue::array(1.46961, AL::ALValue::array(2, -0.0666667, -0.00513203), AL::ALValue::array(2, 0.0333333, 0.00256601));
  SoftLeftSideKick_times[0][6] = 2.00000;
  SoftLeftSideKick_keys[0][6] = AL::ALValue::array(1.48495, AL::ALValue::array(2, -0.0333333, -0.00149230), AL::ALValue::array(2, 0.0666667, 0.00298460));
  SoftLeftSideKick_times[0][7] = 2.20000;
  SoftLeftSideKick_keys[0][7] = AL::ALValue::array(1.48794, AL::ALValue::array(2, -0.0666667, -0.00000), AL::ALValue::array(2, 0.166667, 0.00000));
  SoftLeftSideKick_times[0][8] = 2.70000;
  SoftLeftSideKick_keys[0][8] = AL::ALValue::array(1.48487, AL::ALValue::array(2, -0.166667, 0.00306836), AL::ALValue::array(2, 0.200000, -0.00368203));
  SoftLeftSideKick_times[0][9] = 3.30000;
  SoftLeftSideKick_keys[0][9] = AL::ALValue::array(1.43433, AL::ALValue::array(2, -0.200000, -0.00000), AL::ALValue::array(2, 0.00000, 0.00000));
  
  SoftLeftSideKick_names.push_back("LShoulderRoll");
  SoftLeftSideKick_times[1].arraySetSize(10);
  SoftLeftSideKick_keys[1].arraySetSize(10);
  
  SoftLeftSideKick_times[1][0] = 0.400000;
  SoftLeftSideKick_keys[1][0] = AL::ALValue::array(0.326783, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.133333, 0.00000));
  SoftLeftSideKick_times[1][1] = 0.800000;
  SoftLeftSideKick_keys[1][1] = AL::ALValue::array(0.292952, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.133333, 0.00000));
  SoftLeftSideKick_times[1][2] = 1.20000;
  SoftLeftSideKick_keys[1][2] = AL::ALValue::array(0.292952, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.0666667, 0.00000));
  SoftLeftSideKick_times[1][3] = 1.40000;
  SoftLeftSideKick_keys[1][3] = AL::ALValue::array(0.292952, AL::ALValue::array(2, -0.0666667, -0.00000), AL::ALValue::array(2, 0.100000, 0.00000));
  SoftLeftSideKick_times[1][4] = 1.70000;
  SoftLeftSideKick_keys[1][4] = AL::ALValue::array(0.291418, AL::ALValue::array(2, -0.100000, -0.00000), AL::ALValue::array(2, 0.0666667, 0.00000));
  SoftLeftSideKick_times[1][5] = 1.90000;
  SoftLeftSideKick_keys[1][5] = AL::ALValue::array(1.38985, AL::ALValue::array(2, -0.0666667, -0.00000), AL::ALValue::array(2, 0.0333333, 0.00000));
  SoftLeftSideKick_times[1][6] = 2.00000;
  SoftLeftSideKick_keys[1][6] = AL::ALValue::array(0.992541, AL::ALValue::array(2, -0.0333333, 0.124604), AL::ALValue::array(2, 0.0666667, -0.249209));
  SoftLeftSideKick_times[1][7] = 2.20000;
  SoftLeftSideKick_keys[1][7] = AL::ALValue::array(0.268407, AL::ALValue::array(2, -0.0666667, -0.00000), AL::ALValue::array(2, 0.166667, 0.00000));
  SoftLeftSideKick_times[1][8] = 2.70000;
  SoftLeftSideKick_keys[1][8] = AL::ALValue::array(0.269941, AL::ALValue::array(2, -0.166667, -0.00153415), AL::ALValue::array(2, 0.200000, 0.00184098));
  SoftLeftSideKick_times[1][9] = 3.30000;
  SoftLeftSideKick_keys[1][9] = AL::ALValue::array(0.320648, AL::ALValue::array(2, -0.200000, -0.00000), AL::ALValue::array(2, 0.00000, 0.00000));
  
  SoftLeftSideKick_names.push_back("LElbowYaw");
  SoftLeftSideKick_times[2].arraySetSize(10);
  SoftLeftSideKick_keys[2].arraySetSize(10);
  
  SoftLeftSideKick_times[2][0] = 0.400000;
  SoftLeftSideKick_keys[2][0] = AL::ALValue::array(-1.38363, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.133333, 0.00000));
  SoftLeftSideKick_times[2][1] = 0.800000;
  SoftLeftSideKick_keys[2][1] = AL::ALValue::array(-1.36990, AL::ALValue::array(2, -0.133333, -0.00153411), AL::ALValue::array(2, 0.133333, 0.00153411));
  SoftLeftSideKick_times[2][2] = 1.20000;
  SoftLeftSideKick_keys[2][2] = AL::ALValue::array(-1.36837, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.0666667, 0.00000));
  SoftLeftSideKick_times[2][3] = 1.40000;
  SoftLeftSideKick_keys[2][3] = AL::ALValue::array(-1.36837, AL::ALValue::array(2, -0.0666667, -0.00000), AL::ALValue::array(2, 0.100000, 0.00000));
  SoftLeftSideKick_times[2][4] = 1.70000;
  SoftLeftSideKick_keys[2][4] = AL::ALValue::array(-1.36837, AL::ALValue::array(2, -0.100000, -0.00000), AL::ALValue::array(2, 0.0666667, 0.00000));
  SoftLeftSideKick_times[2][5] = 1.90000;
  SoftLeftSideKick_keys[2][5] = AL::ALValue::array(-1.35755, AL::ALValue::array(2, -0.0666667, -0.00547259), AL::ALValue::array(2, 0.0333333, 0.00273629));
  SoftLeftSideKick_times[2][6] = 2.00000;
  SoftLeftSideKick_keys[2][6] = AL::ALValue::array(-1.34374, AL::ALValue::array(2, -0.0333333, -0.00000), AL::ALValue::array(2, 0.0666667, 0.00000));
  SoftLeftSideKick_times[2][7] = 2.20000;
  SoftLeftSideKick_keys[2][7] = AL::ALValue::array(-1.35917, AL::ALValue::array(2, -0.0666667, -0.00000), AL::ALValue::array(2, 0.166667, 0.00000));
  SoftLeftSideKick_times[2][8] = 2.70000;
  SoftLeftSideKick_keys[2][8] = AL::ALValue::array(-1.35917, AL::ALValue::array(2, -0.166667, -0.00000), AL::ALValue::array(2, 0.200000, 0.00000));
  SoftLeftSideKick_times[2][9] = 3.30000;
  SoftLeftSideKick_keys[2][9] = AL::ALValue::array(-1.38209, AL::ALValue::array(2, -0.200000, -0.00000), AL::ALValue::array(2, 0.00000, 0.00000));
  
  SoftLeftSideKick_names.push_back("LElbowRoll");
  SoftLeftSideKick_times[3].arraySetSize(10);
  SoftLeftSideKick_keys[3].arraySetSize(10);
  
  SoftLeftSideKick_times[3][0] = 0.400000;
  SoftLeftSideKick_keys[3][0] = AL::ALValue::array(-1.02782, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.133333, 0.00000));
  SoftLeftSideKick_times[3][1] = 0.800000;
  SoftLeftSideKick_keys[3][1] = AL::ALValue::array(-1.01393, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.133333, 0.00000));
  SoftLeftSideKick_times[3][2] = 1.20000;
  SoftLeftSideKick_keys[3][2] = AL::ALValue::array(-1.01393, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.0666667, 0.00000));
  SoftLeftSideKick_times[3][3] = 1.40000;
  SoftLeftSideKick_keys[3][3] = AL::ALValue::array(-1.01393, AL::ALValue::array(2, -0.0666667, -0.00000), AL::ALValue::array(2, 0.100000, 0.00000));
  SoftLeftSideKick_times[3][4] = 1.70000;
  SoftLeftSideKick_keys[3][4] = AL::ALValue::array(-1.01393, AL::ALValue::array(2, -0.100000, -0.00000), AL::ALValue::array(2, 0.0666667, 0.00000));
  SoftLeftSideKick_times[3][5] = 1.90000;
  SoftLeftSideKick_keys[3][5] = AL::ALValue::array(-1.01248, AL::ALValue::array(2, -0.0666667, -0.00145042), AL::ALValue::array(2, 0.0333333, 0.000725212));
  SoftLeftSideKick_times[3][6] = 2.00000;
  SoftLeftSideKick_keys[3][6] = AL::ALValue::array(-1.00481, AL::ALValue::array(2, -0.0333333, -0.00000), AL::ALValue::array(2, 0.0666667, 0.00000));
  SoftLeftSideKick_times[3][7] = 2.20000;
  SoftLeftSideKick_keys[3][7] = AL::ALValue::array(-1.01393, AL::ALValue::array(2, -0.0666667, -0.00000), AL::ALValue::array(2, 0.166667, 0.00000));
  SoftLeftSideKick_times[3][8] = 2.70000;
  SoftLeftSideKick_keys[3][8] = AL::ALValue::array(-1.01393, AL::ALValue::array(2, -0.166667, -0.00000), AL::ALValue::array(2, 0.200000, 0.00000));
  SoftLeftSideKick_times[3][9] = 3.30000;
  SoftLeftSideKick_keys[3][9] = AL::ALValue::array(-1.02629, AL::ALValue::array(2, -0.200000, -0.00000), AL::ALValue::array(2, 0.00000, 0.00000));
  
  SoftLeftSideKick_names.push_back("RShoulderPitch");
  SoftLeftSideKick_times[4].arraySetSize(10);
  SoftLeftSideKick_keys[4].arraySetSize(10);
  
  SoftLeftSideKick_times[4][0] = 0.400000;
  SoftLeftSideKick_keys[4][0] = AL::ALValue::array(1.41891, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.133333, 0.00000));
  SoftLeftSideKick_times[4][1] = 0.800000;
  SoftLeftSideKick_keys[4][1] = AL::ALValue::array(1.42359, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.133333, 0.00000));
  SoftLeftSideKick_times[4][2] = 1.20000;
  SoftLeftSideKick_keys[4][2] = AL::ALValue::array(1.41746, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.0666667, 0.00000));
  SoftLeftSideKick_times[4][3] = 1.40000;
  SoftLeftSideKick_keys[4][3] = AL::ALValue::array(1.41746, AL::ALValue::array(2, -0.0666667, -0.00000), AL::ALValue::array(2, 0.100000, 0.00000));
  SoftLeftSideKick_times[4][4] = 1.70000;
  SoftLeftSideKick_keys[4][4] = AL::ALValue::array(1.44200, AL::ALValue::array(2, -0.100000, -0.00857341), AL::ALValue::array(2, 0.0666667, 0.00571561));
  SoftLeftSideKick_times[4][5] = 1.90000;
  SoftLeftSideKick_keys[4][5] = AL::ALValue::array(1.46033, AL::ALValue::array(2, -0.0666667, -0.00509481), AL::ALValue::array(2, 0.0333333, 0.00254740));
  SoftLeftSideKick_times[4][6] = 2.00000;
  SoftLeftSideKick_keys[4][6] = AL::ALValue::array(1.46493, AL::ALValue::array(2, -0.0333333, -0.00120254), AL::ALValue::array(2, 0.0666667, 0.00240507));
  SoftLeftSideKick_times[4][7] = 2.20000;
  SoftLeftSideKick_keys[4][7] = AL::ALValue::array(1.47115, AL::ALValue::array(2, -0.0666667, -0.00000), AL::ALValue::array(2, 0.166667, 0.00000));
  SoftLeftSideKick_times[4][8] = 2.70000;
  SoftLeftSideKick_keys[4][8] = AL::ALValue::array(1.46194, AL::ALValue::array(2, -0.166667, 0.00745046), AL::ALValue::array(2, 0.200000, -0.00894055));
  SoftLeftSideKick_times[4][9] = 3.30000;
  SoftLeftSideKick_keys[4][9] = AL::ALValue::array(1.42198, AL::ALValue::array(2, -0.200000, -0.00000), AL::ALValue::array(2, 0.00000, 0.00000));
  
  SoftLeftSideKick_names.push_back("RShoulderRoll");
  SoftLeftSideKick_times[5].arraySetSize(10);
  SoftLeftSideKick_keys[5].arraySetSize(10);
  
  SoftLeftSideKick_times[5][0] = 0.400000;
  SoftLeftSideKick_keys[5][0] = AL::ALValue::array(-0.368118, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.133333, 0.00000));
  SoftLeftSideKick_times[5][1] = 0.800000;
  SoftLeftSideKick_keys[5][1] = AL::ALValue::array(-1.37911, AL::ALValue::array(2, -0.133333, 0.0322136), AL::ALValue::array(2, 0.133333, -0.0322136));
  SoftLeftSideKick_times[5][2] = 1.20000;
  SoftLeftSideKick_keys[5][2] = AL::ALValue::array(-1.41132, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.0666667, 0.00000));
  SoftLeftSideKick_times[5][3] = 1.40000;
  SoftLeftSideKick_keys[5][3] = AL::ALValue::array(-1.41132, AL::ALValue::array(2, -0.0666667, -0.00000), AL::ALValue::array(2, 0.100000, 0.00000));
  SoftLeftSideKick_times[5][4] = 1.70000;
  SoftLeftSideKick_keys[5][4] = AL::ALValue::array(-1.36990, AL::ALValue::array(2, -0.100000, -0.0159705), AL::ALValue::array(2, 0.0666667, 0.0106470));
  SoftLeftSideKick_times[5][5] = 1.90000;
  SoftLeftSideKick_keys[5][5] = AL::ALValue::array(-1.33147, AL::ALValue::array(2, -0.0666667, -0.0133134), AL::ALValue::array(2, 0.0333333, 0.00665669));
  SoftLeftSideKick_times[5][6] = 2.00000;
  SoftLeftSideKick_keys[5][6] = AL::ALValue::array(-1.30999, AL::ALValue::array(2, -0.0333333, -0.00000), AL::ALValue::array(2, 0.0666667, 0.00000));
  SoftLeftSideKick_times[5][7] = 2.20000;
  SoftLeftSideKick_keys[5][7] = AL::ALValue::array(-1.31315, AL::ALValue::array(2, -0.0666667, 0.00161502), AL::ALValue::array(2, 0.166667, -0.00403754));
  SoftLeftSideKick_times[5][8] = 2.70000;
  SoftLeftSideKick_keys[5][8] = AL::ALValue::array(-1.32695, AL::ALValue::array(2, -0.166667, -0.00000), AL::ALValue::array(2, 0.200000, 0.00000));
  SoftLeftSideKick_times[5][9] = 3.30000;
  SoftLeftSideKick_keys[5][9] = AL::ALValue::array(-0.369652, AL::ALValue::array(2, -0.200000, -0.00000), AL::ALValue::array(2, 0.00000, 0.00000));
  
  SoftLeftSideKick_names.push_back("RElbowYaw");
  SoftLeftSideKick_times[6].arraySetSize(10);
  SoftLeftSideKick_keys[6].arraySetSize(10);
  
  SoftLeftSideKick_times[6][0] = 0.400000;
  SoftLeftSideKick_keys[6][0] = AL::ALValue::array(1.38218, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.133333, 0.00000));
  SoftLeftSideKick_times[6][1] = 0.800000;
  SoftLeftSideKick_keys[6][1] = AL::ALValue::array(1.37902, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.133333, 0.00000));
  SoftLeftSideKick_times[6][2] = 1.20000;
  SoftLeftSideKick_keys[6][2] = AL::ALValue::array(1.39283, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.0666667, 0.00000));
  SoftLeftSideKick_times[6][3] = 1.40000;
  SoftLeftSideKick_keys[6][3] = AL::ALValue::array(1.39283, AL::ALValue::array(2, -0.0666667, -0.00000), AL::ALValue::array(2, 0.100000, 0.00000));
  SoftLeftSideKick_times[6][4] = 1.70000;
  SoftLeftSideKick_keys[6][4] = AL::ALValue::array(1.37749, AL::ALValue::array(2, -0.100000, 0.00642594), AL::ALValue::array(2, 0.0666667, -0.00428396));
  SoftLeftSideKick_times[6][5] = 1.90000;
  SoftLeftSideKick_keys[6][5] = AL::ALValue::array(1.36070, AL::ALValue::array(2, -0.0666667, 0.00611758), AL::ALValue::array(2, 0.0333333, -0.00305879));
  SoftLeftSideKick_times[6][6] = 2.00000;
  SoftLeftSideKick_keys[6][6] = AL::ALValue::array(1.34996, AL::ALValue::array(2, -0.0333333, -0.00000), AL::ALValue::array(2, 0.0666667, 0.00000));
  SoftLeftSideKick_times[6][7] = 2.20000;
  SoftLeftSideKick_keys[6][7] = AL::ALValue::array(1.35295, AL::ALValue::array(2, -0.0666667, -0.00174517), AL::ALValue::array(2, 0.166667, 0.00436292));
  SoftLeftSideKick_times[6][8] = 2.70000;
  SoftLeftSideKick_keys[6][8] = AL::ALValue::array(1.36829, AL::ALValue::array(2, -0.166667, -0.00442866), AL::ALValue::array(2, 0.200000, 0.00531439));
  SoftLeftSideKick_times[6][9] = 3.30000;
  SoftLeftSideKick_keys[6][9] = AL::ALValue::array(1.38218, AL::ALValue::array(2, -0.200000, -0.00000), AL::ALValue::array(2, 0.00000, 0.00000));
  
  SoftLeftSideKick_names.push_back("RElbowRoll");
  SoftLeftSideKick_times[7].arraySetSize(10);
  SoftLeftSideKick_keys[7].arraySetSize(10);
  
  SoftLeftSideKick_times[7][0] = 0.400000;
  SoftLeftSideKick_keys[7][0] = AL::ALValue::array(1.02007, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.133333, 0.00000));
  SoftLeftSideKick_times[7][1] = 0.800000;
  SoftLeftSideKick_keys[7][1] = AL::ALValue::array(1.21650, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.133333, 0.00000));
  SoftLeftSideKick_times[7][2] = 1.20000;
  SoftLeftSideKick_keys[7][2] = AL::ALValue::array(1.20883, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.0666667, 0.00000));
  SoftLeftSideKick_times[7][3] = 1.40000;
  SoftLeftSideKick_keys[7][3] = AL::ALValue::array(1.21037, AL::ALValue::array(2, -0.0666667, -0.00000), AL::ALValue::array(2, 0.100000, 0.00000));
  SoftLeftSideKick_times[7][4] = 1.70000;
  SoftLeftSideKick_keys[7][4] = AL::ALValue::array(1.19349, AL::ALValue::array(2, -0.100000, 0.00242701), AL::ALValue::array(2, 0.0666667, -0.00161800));
  SoftLeftSideKick_times[7][5] = 1.90000;
  SoftLeftSideKick_keys[7][5] = AL::ALValue::array(1.19188, AL::ALValue::array(2, -0.0666667, 0.00161800), AL::ALValue::array(2, 0.0333333, -0.000809002));
  SoftLeftSideKick_times[7][6] = 2.00000;
  SoftLeftSideKick_keys[7][6] = AL::ALValue::array(1.17347, AL::ALValue::array(2, -0.0333333, -0.00000), AL::ALValue::array(2, 0.0666667, 0.00000));
  SoftLeftSideKick_times[7][7] = 2.20000;
  SoftLeftSideKick_keys[7][7] = AL::ALValue::array(1.18429, AL::ALValue::array(2, -0.0666667, -0.00161500), AL::ALValue::array(2, 0.166667, 0.00403751));
  SoftLeftSideKick_times[7][8] = 2.70000;
  SoftLeftSideKick_keys[7][8] = AL::ALValue::array(1.19043, AL::ALValue::array(2, -0.166667, -0.00000), AL::ALValue::array(2, 0.200000, 0.00000));
  SoftLeftSideKick_times[7][9] = 3.30000;
  SoftLeftSideKick_keys[7][9] = AL::ALValue::array(1.02160, AL::ALValue::array(2, -0.200000, -0.00000), AL::ALValue::array(2, 0.00000, 0.00000));
  
  SoftLeftSideKick_names.push_back("LHipYawPitch");
  SoftLeftSideKick_times[8].arraySetSize(10);
  SoftLeftSideKick_keys[8].arraySetSize(10);
  
  SoftLeftSideKick_times[8][0] = 0.400000;
  SoftLeftSideKick_keys[8][0] = AL::ALValue::array(4.19617e-05, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.133333, 0.00000));
  SoftLeftSideKick_times[8][1] = 0.800000;
  SoftLeftSideKick_keys[8][1] = AL::ALValue::array(-0.0106960, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.133333, 0.00000));
  SoftLeftSideKick_times[8][2] = 1.20000;
  SoftLeftSideKick_keys[8][2] = AL::ALValue::array(-0.00762803, AL::ALValue::array(2, -0.133333, -0.00306801), AL::ALValue::array(2, 0.0666667, 0.00153400));
  SoftLeftSideKick_times[8][3] = 1.40000;
  SoftLeftSideKick_keys[8][3] = AL::ALValue::array(0.00464395, AL::ALValue::array(2, -0.0666667, -0.0122720), AL::ALValue::array(2, 0.100000, 0.0184080));
  SoftLeftSideKick_times[8][4] = 1.70000;
  SoftLeftSideKick_keys[8][4] = AL::ALValue::array(0.104354, AL::ALValue::array(2, -0.100000, -0.0288392), AL::ALValue::array(2, 0.0666667, 0.0192261));
  SoftLeftSideKick_times[8][5] = 1.90000;
  SoftLeftSideKick_keys[8][5] = AL::ALValue::array(0.148840, AL::ALValue::array(2, -0.0666667, -0.00000), AL::ALValue::array(2, 0.0333333, 0.00000));
  SoftLeftSideKick_times[8][6] = 2.00000;
  SoftLeftSideKick_keys[8][6] = AL::ALValue::array(0.148840, AL::ALValue::array(2, -0.0333333, -0.00000), AL::ALValue::array(2, 0.0666667, 0.00000));
  SoftLeftSideKick_times[8][7] = 2.20000;
  SoftLeftSideKick_keys[8][7] = AL::ALValue::array(0.138102, AL::ALValue::array(2, -0.0666667, 0.0107380), AL::ALValue::array(2, 0.166667, -0.0268449));
  SoftLeftSideKick_times[8][8] = 2.70000;
  SoftLeftSideKick_keys[8][8] = AL::ALValue::array(-0.127280, AL::ALValue::array(2, -0.166667, -0.00000), AL::ALValue::array(2, 0.200000, 0.00000));
  SoftLeftSideKick_times[8][9] = 3.30000;
  SoftLeftSideKick_keys[8][9] = AL::ALValue::array(4.19617e-05, AL::ALValue::array(2, -0.200000, -0.00000), AL::ALValue::array(2, 0.00000, 0.00000));
  
  SoftLeftSideKick_names.push_back("LHipRoll");
  SoftLeftSideKick_times[9].arraySetSize(10);
  SoftLeftSideKick_keys[9].arraySetSize(10);
  
  SoftLeftSideKick_times[9][0] = 0.400000;
  SoftLeftSideKick_keys[9][0] = AL::ALValue::array(-4.19617e-05, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.133333, 0.00000));
  SoftLeftSideKick_times[9][1] = 0.800000;
  SoftLeftSideKick_keys[9][1] = AL::ALValue::array(-0.165714, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.133333, 0.00000));
  SoftLeftSideKick_times[9][2] = 1.20000;
  SoftLeftSideKick_keys[9][2] = AL::ALValue::array(-0.0873960, AL::ALValue::array(2, -0.133333, -0.0296573), AL::ALValue::array(2, 0.0666667, 0.0148287));
  SoftLeftSideKick_times[9][3] = 1.40000;
  SoftLeftSideKick_keys[9][3] = AL::ALValue::array(-0.0322560, AL::ALValue::array(2, -0.0666667, -0.00000), AL::ALValue::array(2, 0.100000, 0.00000));
  SoftLeftSideKick_times[9][4] = 1.70000;
  SoftLeftSideKick_keys[9][4] = AL::ALValue::array(-0.0506639, AL::ALValue::array(2, -0.100000, 0.0184080), AL::ALValue::array(2, 0.0666667, -0.0122720));
  SoftLeftSideKick_times[9][5] = 1.90000;
  SoftLeftSideKick_keys[9][5] = AL::ALValue::array(-0.354396, AL::ALValue::array(2, -0.0666667, -0.00000), AL::ALValue::array(2, 0.0333333, 0.00000));
  SoftLeftSideKick_times[9][6] = 2.00000;
  SoftLeftSideKick_keys[9][6] = AL::ALValue::array(-0.354396, AL::ALValue::array(2, -0.0333333, -0.00000), AL::ALValue::array(2, 0.0666667, 0.00000));
  SoftLeftSideKick_times[9][7] = 2.20000;
  SoftLeftSideKick_keys[9][7] = AL::ALValue::array(-0.363515, AL::ALValue::array(2, -0.0666667, 0.00116870), AL::ALValue::array(2, 0.166667, -0.00292176));
  SoftLeftSideKick_times[9][8] = 2.70000;
  SoftLeftSideKick_keys[9][8] = AL::ALValue::array(-0.366667, AL::ALValue::array(2, -0.166667, -0.00000), AL::ALValue::array(2, 0.200000, 0.00000));
  SoftLeftSideKick_times[9][9] = 3.30000;
  SoftLeftSideKick_keys[9][9] = AL::ALValue::array(-4.19617e-05, AL::ALValue::array(2, -0.200000, -0.00000), AL::ALValue::array(2, 0.00000, 0.00000));
  
  SoftLeftSideKick_names.push_back("LHipPitch");
  SoftLeftSideKick_times[10].arraySetSize(10);
  SoftLeftSideKick_keys[10].arraySetSize(10);
  
  SoftLeftSideKick_times[10][0] = 0.400000;
  SoftLeftSideKick_keys[10][0] = AL::ALValue::array(-0.437231, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.133333, 0.00000));
  SoftLeftSideKick_times[10][1] = 0.800000;
  SoftLeftSideKick_keys[10][1] = AL::ALValue::array(-0.115092, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.133333, 0.00000));
  SoftLeftSideKick_times[10][2] = 1.20000;
  SoftLeftSideKick_keys[10][2] = AL::ALValue::array(-0.248467, AL::ALValue::array(2, -0.133333, 0.0497699), AL::ALValue::array(2, 0.0666667, -0.0248849));
  SoftLeftSideKick_times[10][3] = 1.40000;
  SoftLeftSideKick_keys[10][3] = AL::ALValue::array(-0.339056, AL::ALValue::array(2, -0.0666667, -0.00000), AL::ALValue::array(2, 0.100000, 0.00000));
  SoftLeftSideKick_times[10][4] = 1.70000;
  SoftLeftSideKick_keys[10][4] = AL::ALValue::array(-0.329852, AL::ALValue::array(2, -0.100000, -0.00000), AL::ALValue::array(2, 0.0666667, 0.00000));
  SoftLeftSideKick_times[10][5] = 1.90000;
  SoftLeftSideKick_keys[10][5] = AL::ALValue::array(-0.478650, AL::ALValue::array(2, -0.0666667, -0.00000), AL::ALValue::array(2, 0.0333333, 0.00000));
  SoftLeftSideKick_times[10][6] = 2.00000;
  SoftLeftSideKick_keys[10][6] = AL::ALValue::array(-0.478650, AL::ALValue::array(2, -0.0333333, -0.00000), AL::ALValue::array(2, 0.0666667, 0.00000));
  SoftLeftSideKick_times[10][7] = 2.20000;
  SoftLeftSideKick_keys[10][7] = AL::ALValue::array(-0.154892, AL::ALValue::array(2, -0.0666667, -0.0487958), AL::ALValue::array(2, 0.166667, 0.121989));
  SoftLeftSideKick_times[10][8] = 2.70000;
  SoftLeftSideKick_keys[10][8] = AL::ALValue::array(0.0337060, AL::ALValue::array(2, -0.166667, -0.00000), AL::ALValue::array(2, 0.200000, 0.00000));
  SoftLeftSideKick_times[10][9] = 3.30000;
  SoftLeftSideKick_keys[10][9] = AL::ALValue::array(-0.437231, AL::ALValue::array(2, -0.200000, -0.00000), AL::ALValue::array(2, 0.00000, 0.00000));
  
  SoftLeftSideKick_names.push_back("LKneePitch");
  SoftLeftSideKick_times[11].arraySetSize(10);
  SoftLeftSideKick_keys[11].arraySetSize(10);
  
  SoftLeftSideKick_times[11][0] = 0.400000;
  SoftLeftSideKick_keys[11][0] = AL::ALValue::array(0.699545, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.133333, 0.00000));
  SoftLeftSideKick_times[11][1] = 0.800000;
  SoftLeftSideKick_keys[11][1] = AL::ALValue::array(0.704148, AL::ALValue::array(2, -0.133333, -0.00460241), AL::ALValue::array(2, 0.133333, 0.00460241));
  SoftLeftSideKick_times[11][2] = 1.20000;
  SoftLeftSideKick_keys[11][2] = AL::ALValue::array(1.01240, AL::ALValue::array(2, -0.133333, -0.113857), AL::ALValue::array(2, 0.0666667, 0.0569284));
  SoftLeftSideKick_times[11][3] = 1.40000;
  SoftLeftSideKick_keys[11][3] = AL::ALValue::array(1.21650, AL::ALValue::array(2, -0.0666667, -0.00000), AL::ALValue::array(2, 0.100000, 0.00000));
  SoftLeftSideKick_times[11][4] = 1.70000;
  SoftLeftSideKick_keys[11][4] = AL::ALValue::array(0.179519, AL::ALValue::array(2, -0.100000, -0.00000), AL::ALValue::array(2, 0.0666667, 0.00000));
  SoftLeftSideKick_times[11][5] = 1.90000;
  SoftLeftSideKick_keys[11][5] = AL::ALValue::array(0.316046, AL::ALValue::array(2, -0.0666667, -0.00000), AL::ALValue::array(2, 0.0333333, 0.00000));
  SoftLeftSideKick_times[11][6] = 2.00000;
  SoftLeftSideKick_keys[11][6] = AL::ALValue::array(0.316046, AL::ALValue::array(2, -0.0333333, -0.00000), AL::ALValue::array(2, 0.0666667, 0.00000));
  SoftLeftSideKick_times[11][7] = 2.20000;
  SoftLeftSideKick_keys[11][7] = AL::ALValue::array(0.257670, AL::ALValue::array(2, -0.0666667, -0.00000), AL::ALValue::array(2, 0.166667, 0.00000));
  SoftLeftSideKick_times[11][8] = 2.70000;
  SoftLeftSideKick_keys[11][8] = AL::ALValue::array(0.296104, AL::ALValue::array(2, -0.166667, -0.0384339), AL::ALValue::array(2, 0.200000, 0.0461207));
  SoftLeftSideKick_times[11][9] = 3.30000;
  SoftLeftSideKick_keys[11][9] = AL::ALValue::array(0.698011, AL::ALValue::array(2, -0.200000, -0.00000), AL::ALValue::array(2, 0.00000, 0.00000));
  
  SoftLeftSideKick_names.push_back("LAnklePitch");
  SoftLeftSideKick_times[12].arraySetSize(10);
  SoftLeftSideKick_keys[12].arraySetSize(10);
  
  SoftLeftSideKick_times[12][0] = 0.400000;
  SoftLeftSideKick_keys[12][0] = AL::ALValue::array(-0.348176, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.133333, 0.00000));
  SoftLeftSideKick_times[12][1] = 0.800000;
  SoftLeftSideKick_keys[12][1] = AL::ALValue::array(-0.409536, AL::ALValue::array(2, -0.133333, 0.0388755), AL::ALValue::array(2, 0.133333, -0.0388755));
  SoftLeftSideKick_times[12][2] = 1.20000;
  SoftLeftSideKick_keys[12][2] = AL::ALValue::array(-0.581429, AL::ALValue::array(2, -0.133333, 0.0552238), AL::ALValue::array(2, 0.0666667, -0.0276119));
  SoftLeftSideKick_times[12][3] = 1.40000;
  SoftLeftSideKick_keys[12][3] = AL::ALValue::array(-0.658043, AL::ALValue::array(2, -0.0666667, -0.00000), AL::ALValue::array(2, 0.100000, 0.00000));
  SoftLeftSideKick_times[12][4] = 1.70000;
  SoftLeftSideKick_keys[12][4] = AL::ALValue::array(0.259288, AL::ALValue::array(2, -0.100000, -0.00230122), AL::ALValue::array(2, 0.0666667, 0.00153415));
  SoftLeftSideKick_times[12][5] = 1.90000;
  SoftLeftSideKick_keys[12][5] = AL::ALValue::array(0.260822, AL::ALValue::array(2, -0.0666667, -0.00000), AL::ALValue::array(2, 0.0333333, 0.00000));
  SoftLeftSideKick_times[12][6] = 2.00000;
  SoftLeftSideKick_keys[12][6] = AL::ALValue::array(0.259288, AL::ALValue::array(2, -0.0333333, 0.00153415), AL::ALValue::array(2, 0.0666667, -0.00306829));
  SoftLeftSideKick_times[12][7] = 2.20000;
  SoftLeftSideKick_keys[12][7] = AL::ALValue::array(0.00456004, AL::ALValue::array(2, -0.0666667, 0.0392996), AL::ALValue::array(2, 0.166667, -0.0982490));
  SoftLeftSideKick_times[12][8] = 2.70000;
  SoftLeftSideKick_keys[12][8] = AL::ALValue::array(-0.153358, AL::ALValue::array(2, -0.166667, 0.0536773), AL::ALValue::array(2, 0.200000, -0.0644127));
  SoftLeftSideKick_times[12][9] = 3.30000;
  SoftLeftSideKick_keys[12][9] = AL::ALValue::array(-0.349710, AL::ALValue::array(2, -0.200000, -0.00000), AL::ALValue::array(2, 0.00000, 0.00000));
  
  SoftLeftSideKick_names.push_back("LAnkleRoll");
  SoftLeftSideKick_times[13].arraySetSize(10);
  SoftLeftSideKick_keys[13].arraySetSize(10);
  
  SoftLeftSideKick_times[13][0] = 0.400000;
  SoftLeftSideKick_keys[13][0] = AL::ALValue::array(-4.19617e-05, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.133333, 0.00000));
  SoftLeftSideKick_times[13][1] = 0.800000;
  SoftLeftSideKick_keys[13][1] = AL::ALValue::array(-0.214801, AL::ALValue::array(2, -0.133333, 0.0495854), AL::ALValue::array(2, 0.133333, -0.0495854));
  SoftLeftSideKick_times[13][2] = 1.20000;
  SoftLeftSideKick_keys[13][2] = AL::ALValue::array(-0.297554, AL::ALValue::array(2, -0.133333, 0.0221579), AL::ALValue::array(2, 0.0666667, -0.0110790));
  SoftLeftSideKick_times[13][3] = 1.40000;
  SoftLeftSideKick_keys[13][3] = AL::ALValue::array(-0.314512, AL::ALValue::array(2, -0.0666667, -0.00000), AL::ALValue::array(2, 0.100000, 0.00000));
  SoftLeftSideKick_times[13][4] = 1.70000;
  SoftLeftSideKick_keys[13][4] = AL::ALValue::array(0.104270, AL::ALValue::array(2, -0.100000, -0.00000), AL::ALValue::array(2, 0.0666667, 0.00000));
  SoftLeftSideKick_times[13][5] = 1.90000;
  SoftLeftSideKick_keys[13][5] = AL::ALValue::array(0.0735901, AL::ALValue::array(2, -0.0666667, -0.00000), AL::ALValue::array(2, 0.0333333, 0.00000));
  SoftLeftSideKick_times[13][6] = 2.00000;
  SoftLeftSideKick_keys[13][6] = AL::ALValue::array(0.0735901, AL::ALValue::array(2, -0.0333333, -0.00000), AL::ALValue::array(2, 0.0666667, 0.00000));
  SoftLeftSideKick_times[13][7] = 2.20000;
  SoftLeftSideKick_keys[13][7] = AL::ALValue::array(0.00924597, AL::ALValue::array(2, -0.0666667, 0.0195768), AL::ALValue::array(2, 0.166667, -0.0489419));
  SoftLeftSideKick_times[13][8] = 2.70000;
  SoftLeftSideKick_keys[13][8] = AL::ALValue::array(-0.131966, AL::ALValue::array(2, -0.166667, -0.00000), AL::ALValue::array(2, 0.200000, 0.00000));
  SoftLeftSideKick_times[13][9] = 3.30000;
  SoftLeftSideKick_keys[13][9] = AL::ALValue::array(-4.19617e-05, AL::ALValue::array(2, -0.200000, -0.00000), AL::ALValue::array(2, 0.00000, 0.00000));
  
  SoftLeftSideKick_names.push_back("RHipRoll");
  SoftLeftSideKick_times[14].arraySetSize(10);
  SoftLeftSideKick_keys[14].arraySetSize(10);
  
  SoftLeftSideKick_times[14][0] = 0.400000;
  SoftLeftSideKick_keys[14][0] = AL::ALValue::array(-0.00157596, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.133333, 0.00000));
  SoftLeftSideKick_times[14][1] = 0.800000;
  SoftLeftSideKick_keys[14][1] = AL::ALValue::array(-0.251617, AL::ALValue::array(2, -0.133333, 0.0815435), AL::ALValue::array(2, 0.133333, -0.0815435));
  SoftLeftSideKick_times[14][2] = 1.20000;
  SoftLeftSideKick_keys[14][2] = AL::ALValue::array(-0.490837, AL::ALValue::array(2, -0.133333, 0.000171042), AL::ALValue::array(2, 0.0666667, -8.55208e-05));
  SoftLeftSideKick_times[14][3] = 1.40000;
  SoftLeftSideKick_keys[14][3] = AL::ALValue::array(-0.490923, AL::ALValue::array(2, -0.0666667, -0.00000), AL::ALValue::array(2, 0.100000, 0.00000));
  SoftLeftSideKick_times[14][4] = 1.70000;
  SoftLeftSideKick_keys[14][4] = AL::ALValue::array(-0.490923, AL::ALValue::array(2, -0.100000, -0.00000), AL::ALValue::array(2, 0.0666667, 0.00000));
  SoftLeftSideKick_times[14][5] = 1.90000;
  SoftLeftSideKick_keys[14][5] = AL::ALValue::array(-0.493989, AL::ALValue::array(2, -0.0666667, 0.00102237), AL::ALValue::array(2, 0.0333333, -0.000511186));
  SoftLeftSideKick_times[14][6] = 2.00000;
  SoftLeftSideKick_keys[14][6] = AL::ALValue::array(-0.495523, AL::ALValue::array(2, -0.0333333, -0.00000), AL::ALValue::array(2, 0.0666667, 0.00000));
  SoftLeftSideKick_times[14][7] = 2.20000;
  SoftLeftSideKick_keys[14][7] = AL::ALValue::array(-0.490837, AL::ALValue::array(2, -0.0666667, -0.00000), AL::ALValue::array(2, 0.166667, 0.00000));
  SoftLeftSideKick_times[14][8] = 2.70000;
  SoftLeftSideKick_keys[14][8] = AL::ALValue::array(-0.507797, AL::ALValue::array(2, -0.166667, -0.00000), AL::ALValue::array(2, 0.200000, 0.00000));
  SoftLeftSideKick_times[14][9] = 3.30000;
  SoftLeftSideKick_keys[14][9] = AL::ALValue::array(-4.19617e-05, AL::ALValue::array(2, -0.200000, -0.00000), AL::ALValue::array(2, 0.00000, 0.00000));
  
  SoftLeftSideKick_names.push_back("RHipPitch");
  SoftLeftSideKick_times[15].arraySetSize(10);
  SoftLeftSideKick_keys[15].arraySetSize(10);
  
  SoftLeftSideKick_times[15][0] = 0.400000;
  SoftLeftSideKick_keys[15][0] = AL::ALValue::array(-0.435613, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.133333, 0.00000));
  SoftLeftSideKick_times[15][1] = 0.800000;
  SoftLeftSideKick_keys[15][1] = AL::ALValue::array(-0.343573, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.133333, 0.00000));
  SoftLeftSideKick_times[15][2] = 1.20000;
  SoftLeftSideKick_keys[15][2] = AL::ALValue::array(-0.343659, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.0666667, 0.00000));
  SoftLeftSideKick_times[15][3] = 1.40000;
  SoftLeftSideKick_keys[15][3] = AL::ALValue::array(-0.343573, AL::ALValue::array(2, -0.0666667, -0.00000), AL::ALValue::array(2, 0.100000, 0.00000));
  SoftLeftSideKick_times[15][4] = 1.70000;
  SoftLeftSideKick_keys[15][4] = AL::ALValue::array(-0.343573, AL::ALValue::array(2, -0.100000, -0.00000), AL::ALValue::array(2, 0.0666667, 0.00000));
  SoftLeftSideKick_times[15][5] = 1.90000;
  SoftLeftSideKick_keys[15][5] = AL::ALValue::array(-0.342041, AL::ALValue::array(2, -0.0666667, -0.000681459), AL::ALValue::array(2, 0.0333333, 0.000340729));
  SoftLeftSideKick_times[15][6] = 2.00000;
  SoftLeftSideKick_keys[15][6] = AL::ALValue::array(-0.340507, AL::ALValue::array(2, -0.0333333, -0.00000), AL::ALValue::array(2, 0.0666667, 0.00000));
  SoftLeftSideKick_times[15][7] = 2.20000;
  SoftLeftSideKick_keys[15][7] = AL::ALValue::array(-0.342125, AL::ALValue::array(2, -0.0666667, 0.00161794), AL::ALValue::array(2, 0.166667, -0.00404484));
  SoftLeftSideKick_times[15][8] = 2.70000;
  SoftLeftSideKick_keys[15][8] = AL::ALValue::array(-0.388060, AL::ALValue::array(2, -0.166667, 0.0141649), AL::ALValue::array(2, 0.200000, -0.0169979));
  SoftLeftSideKick_times[15][9] = 3.30000;
  SoftLeftSideKick_keys[15][9] = AL::ALValue::array(-0.435613, AL::ALValue::array(2, -0.200000, -0.00000), AL::ALValue::array(2, 0.00000, 0.00000));
  
  SoftLeftSideKick_names.push_back("RKneePitch");
  SoftLeftSideKick_times[16].arraySetSize(10);
  SoftLeftSideKick_keys[16].arraySetSize(10);
  
  SoftLeftSideKick_times[16][0] = 0.400000;
  SoftLeftSideKick_keys[16][0] = AL::ALValue::array(0.697927, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.133333, 0.00000));
  SoftLeftSideKick_times[16][1] = 0.800000;
  SoftLeftSideKick_keys[16][1] = AL::ALValue::array(1.29159, AL::ALValue::array(2, -0.133333, -0.00775446), AL::ALValue::array(2, 0.133333, 0.00775446));
  SoftLeftSideKick_times[16][2] = 1.20000;
  SoftLeftSideKick_keys[16][2] = AL::ALValue::array(1.29934, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.0666667, 0.00000));
  SoftLeftSideKick_times[16][3] = 1.40000;
  SoftLeftSideKick_keys[16][3] = AL::ALValue::array(1.29619, AL::ALValue::array(2, -0.0666667, -0.00000), AL::ALValue::array(2, 0.100000, 0.00000));
  SoftLeftSideKick_times[16][4] = 1.70000;
  SoftLeftSideKick_keys[16][4] = AL::ALValue::array(1.31613, AL::ALValue::array(2, -0.100000, -0.00000), AL::ALValue::array(2, 0.0666667, 0.00000));
  SoftLeftSideKick_times[16][5] = 1.90000;
  SoftLeftSideKick_keys[16][5] = AL::ALValue::array(1.29772, AL::ALValue::array(2, -0.0666667, 0.00613619), AL::ALValue::array(2, 0.0333333, -0.00306809));
  SoftLeftSideKick_times[16][6] = 2.00000;
  SoftLeftSideKick_keys[16][6] = AL::ALValue::array(1.28852, AL::ALValue::array(2, -0.0333333, -0.00000), AL::ALValue::array(2, 0.0666667, 0.00000));
  SoftLeftSideKick_times[16][7] = 2.20000;
  SoftLeftSideKick_keys[16][7] = AL::ALValue::array(1.30701, AL::ALValue::array(2, -0.0666667, -0.00000), AL::ALValue::array(2, 0.166667, 0.00000));
  SoftLeftSideKick_times[16][8] = 2.70000;
  SoftLeftSideKick_keys[16][8] = AL::ALValue::array(1.24096, AL::ALValue::array(2, -0.166667, 0.0660468), AL::ALValue::array(2, 0.200000, -0.0792561));
  SoftLeftSideKick_times[16][9] = 3.30000;
  SoftLeftSideKick_keys[16][9] = AL::ALValue::array(0.697927, AL::ALValue::array(2, -0.200000, -0.00000), AL::ALValue::array(2, 0.00000, 0.00000));
  
  SoftLeftSideKick_names.push_back("RAnklePitch");
  SoftLeftSideKick_times[17].arraySetSize(10);
  SoftLeftSideKick_keys[17].arraySetSize(10);
  
  SoftLeftSideKick_times[17][0] = 0.400000;
  SoftLeftSideKick_keys[17][0] = AL::ALValue::array(-0.349794, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.133333, 0.00000));
  SoftLeftSideKick_times[17][1] = 0.800000;
  SoftLeftSideKick_keys[17][1] = AL::ALValue::array(-0.780848, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.133333, 0.00000));
  SoftLeftSideKick_times[17][2] = 1.20000;
  SoftLeftSideKick_keys[17][2] = AL::ALValue::array(-0.780764, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.0666667, 0.00000));
  SoftLeftSideKick_times[17][3] = 1.40000;
  SoftLeftSideKick_keys[17][3] = AL::ALValue::array(-0.780848, AL::ALValue::array(2, -0.0666667, 8.37564e-05), AL::ALValue::array(2, 0.100000, -0.000125635));
  SoftLeftSideKick_times[17][4] = 1.70000;
  SoftLeftSideKick_keys[17][4] = AL::ALValue::array(-0.791585, AL::ALValue::array(2, -0.100000, -0.00000), AL::ALValue::array(2, 0.0666667, 0.00000));
  SoftLeftSideKick_times[17][5] = 1.90000;
  SoftLeftSideKick_keys[17][5] = AL::ALValue::array(-0.776246, AL::ALValue::array(2, -0.0666667, -0.00000), AL::ALValue::array(2, 0.0333333, 0.00000));
  SoftLeftSideKick_times[17][6] = 2.00000;
  SoftLeftSideKick_keys[17][6] = AL::ALValue::array(-0.776246, AL::ALValue::array(2, -0.0333333, -0.00000), AL::ALValue::array(2, 0.0666667, 0.00000));
  SoftLeftSideKick_times[17][7] = 2.20000;
  SoftLeftSideKick_keys[17][7] = AL::ALValue::array(-0.785367, AL::ALValue::array(2, -0.0666667, -0.00000), AL::ALValue::array(2, 0.166667, 0.00000));
  SoftLeftSideKick_times[17][8] = 2.70000;
  SoftLeftSideKick_keys[17][8] = AL::ALValue::array(-0.731761, AL::ALValue::array(2, -0.166667, -0.0536060), AL::ALValue::array(2, 0.200000, 0.0643272));
  SoftLeftSideKick_times[17][9] = 3.30000;
  SoftLeftSideKick_keys[17][9] = AL::ALValue::array(-0.348260, AL::ALValue::array(2, -0.200000, -0.00000), AL::ALValue::array(2, 0.00000, 0.00000));
  
  SoftLeftSideKick_names.push_back("RAnkleRoll");
  SoftLeftSideKick_times[18].arraySetSize(10);
  SoftLeftSideKick_keys[18].arraySetSize(10);
  
  SoftLeftSideKick_times[18][0] = 0.400000;
  SoftLeftSideKick_keys[18][0] = AL::ALValue::array(-4.19617e-05, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.133333, 0.00000));
  SoftLeftSideKick_times[18][1] = 0.800000;
  SoftLeftSideKick_keys[18][1] = AL::ALValue::array(-0.0951499, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.133333, 0.00000));
  SoftLeftSideKick_times[18][2] = 1.20000;
  SoftLeftSideKick_keys[18][2] = AL::ALValue::array(-0.0950660, AL::ALValue::array(2, -0.133333, -0.00000), AL::ALValue::array(2, 0.0666667, 0.00000));
  SoftLeftSideKick_times[18][3] = 1.40000;
  SoftLeftSideKick_keys[18][3] = AL::ALValue::array(-0.0951499, AL::ALValue::array(2, -0.0666667, -0.00000), AL::ALValue::array(2, 0.100000, 0.00000));
  SoftLeftSideKick_times[18][4] = 1.70000;
  SoftLeftSideKick_keys[18][4] = AL::ALValue::array(-0.0951499, AL::ALValue::array(2, -0.100000, -0.00000), AL::ALValue::array(2, 0.0666667, 0.00000));
  SoftLeftSideKick_times[18][5] = 1.90000;
  SoftLeftSideKick_keys[18][5] = AL::ALValue::array(-0.101286, AL::ALValue::array(2, -0.0666667, -0.00000), AL::ALValue::array(2, 0.0333333, 0.00000));
  SoftLeftSideKick_times[18][6] = 2.00000;
  SoftLeftSideKick_keys[18][6] = AL::ALValue::array(-0.0997520, AL::ALValue::array(2, -0.0333333, -0.000691112), AL::ALValue::array(2, 0.0666667, 0.00138222));
  SoftLeftSideKick_times[18][7] = 2.20000;
  SoftLeftSideKick_keys[18][7] = AL::ALValue::array(-0.0950660, AL::ALValue::array(2, -0.0666667, -0.00468604), AL::ALValue::array(2, 0.166667, 0.0117151));
  SoftLeftSideKick_times[18][8] = 2.70000;
  SoftLeftSideKick_keys[18][8] = AL::ALValue::array(0.0843280, AL::ALValue::array(2, -0.166667, -0.00000), AL::ALValue::array(2, 0.200000, 0.00000));
  SoftLeftSideKick_times[18][9] = 3.30000;
  SoftLeftSideKick_keys[18][9] = AL::ALValue::array(-4.19617e-05, AL::ALValue::array(2, -0.200000, -0.00000), AL::ALValue::array(2, 0.00000, 0.00000)); 
  
  
}

int SoftLeftSideKick::ExecutePost() {
  return motion->post.angleInterpolationBezier(SoftLeftSideKick_names, SoftLeftSideKick_times, SoftLeftSideKick_keys); 
} 
