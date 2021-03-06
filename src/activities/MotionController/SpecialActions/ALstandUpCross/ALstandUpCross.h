#ifndef _ALstandUpCross_h_
#define _ALstandUpCross_h_ 1

#include "../../ISpecialAction.h"

#include "alptr.h"
#include "alvalue.h"
#include "almotionproxy.h"

class ALstandUpCross: public ISpecialAction {
  
  public:
    std::string GetName () {
      return "ALstandUpCross";
    }
    
    ALstandUpCross();
    
    int ExecutePost();
    
  private:
    
    void Initialize();
    
    AL::ALPtr<AL::ALMotionProxy> motion;
    
    AL::ALValue jointCodes, angles, times;     
    
}; 

#endif // _ALstandUpCross_h_ 
