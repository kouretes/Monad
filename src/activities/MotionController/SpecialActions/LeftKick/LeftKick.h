#ifndef _LeftKick_h_
#define _LeftKick_h_ 1

#include "../../ISpecialAction.h"

#include "alptr.h"
#include "alvalue.h"
#include "almotionproxy.h"

class LeftKick: public ISpecialAction {
  
  public:
    std::string GetName () {
      return "LeftKick";
    }
    
    LeftKick();
    
    int ExecutePost();
    
  private:
    
    void Initialize();
    
    AL::ALPtr<AL::ALMotionProxy> motion;
    
    AL::ALValue LeftKick_names, LeftKick_times, LeftKick_keys;     
    
}; 

#endif // _LeftKick_h_ 
