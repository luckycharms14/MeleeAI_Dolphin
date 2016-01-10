#ifndef MOVE_SET_HPP
#define MOVE_SET_HPP

#include "../Controller.hpp"

//TODO: name moves instead of switch statement

class MoveSet {

private:

  Controller* m_controller;
    
public:

  MoveSet();
  ~MoveSet();

  void UpB();
  void SideB(char);
  void DoubleJump();
  void HoldStick(int);
  void ReleaseStick();
  void LedgeDash(int,int);
  
};

#endif
