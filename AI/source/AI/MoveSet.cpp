#include "../Global.hpp"
#include "MoveSet.hpp"
#include "../MemShareController.hpp"

MoveSet::MoveSet() {
  m_controller = new MemShareController();
}

MoveSet::~MoveSet() {
  delete m_controller;
}

void MoveSet::UpB() {
  m_controller->Stick(1,90);
  GLOBAL_SLEEP(17);
  m_controller->Press('B');
  GLOBAL_SLEEP(2*17);
  m_controller->Release('B');
  m_controller->Stick(0,0);
}    

void MoveSet::SideB(char dir) {
  if (dir == 'R') {
    m_controller->Stick(1,0);
  } else {
    m_controller->Stick(1,180);          
  }
  m_controller->Press('B');
  GLOBAL_SLEEP(3*17);
  m_controller->Release('B');
  m_controller->Stick(0,0);
}

void MoveSet::DoubleJump() {
  m_controller->Press('X');
  GLOBAL_SLEEP(3*17);
  m_controller->Release('X');
}   

void MoveSet::HoldStick(int dir) {
  m_controller->Stick(1,dir);
}

void MoveSet::ReleaseStick() {
  m_controller->Stick(0,0);
}

void MoveSet::LedgeDash(int id, int deg) {
  m_controller->Stick(1,270);
  GLOBAL_SLEEP(2*17);
  m_controller->Stick(0,0);
  m_controller->Press('X');
  GLOBAL_SLEEP(2*17);
  m_controller->Release('X');
  GLOBAL_SLEEP(3*17);
  m_controller->Stick(1,deg);
  m_controller->Press('L');
  GLOBAL_SLEEP(2*17);
  m_controller->Stick(0,0);
  m_controller->Release('L');
}
  







