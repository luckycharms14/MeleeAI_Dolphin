#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <boost/interprocess/managed_shared_memory.hpp>
#include <map>

struct ControllerState {
  long buttons;
  long control_stick[2];
  long c_stick[2];
};

class Controller {

private:

  long m_full_control_state[19];
  boost::interprocess::managed_shared_memory melee_mem;
  ControllerState m_controller_state;  

  std::map<char, long> m_button_hex_map {
    {'A', 0x00000100},
    {'B', 0x00000200},
    {'X', 0x00000400},
    {'Z', 0x00000010},
    {'L', 0x00000040},
  };

public:

  Controller();
  
  void Press(char);
  void Release(char);    

  /** 1st arg = 0 to 1, radius of stick
      2nd arg = 0 to 360, angle of stick, pushed to the right = 0 degrees
      3rd arg, true for c-stick, false for control stick
  */
  void Stick(float,int,bool=false);

  void WriteStateToMemory();

};
    
#endif
        
        
        
