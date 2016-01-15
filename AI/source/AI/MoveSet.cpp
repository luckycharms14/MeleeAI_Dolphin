#include "../Global.hpp"
#include "MoveSet.hpp"
#include "../PipeController.hpp"
#include <unistd.h>

//TODO: Have moves return the number of frames they waited

MoveSet::MoveSet() {
    m_controller = new PipeController();
}

MoveSet::~MoveSet() {
    delete m_controller;
}

void MoveSet::UpB() {
    m_controller->Stick(1,90);
    GLOBAL_WAIT_FRAMES(1)
    m_controller->Press('B');
    GLOBAL_WAIT_FRAMES(1)
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
    GLOBAL_WAIT_FRAMES(1)
    m_controller->Release('B');
    m_controller->Stick(0,0);
}

void MoveSet::DoubleJump() {
    m_controller->Press('X');
    GLOBAL_WAIT_FRAMES(1)
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
    GLOBAL_WAIT_FRAMES(2)
    m_controller->Stick(0,0);
    m_controller->Press('X');
    GLOBAL_WAIT_FRAMES(2)
    m_controller->Release('X');
    GLOBAL_WAIT_FRAMES(3)
    m_controller->Stick(1,deg);
    m_controller->Press('L');
    GLOBAL_WAIT_FRAMES(2)
    m_controller->Stick(0,0);
    m_controller->Release('L');
}

void MoveSet::HitTech() {
    m_controller->Press('L');
    GLOBAL_WAIT_FRAMES(1)
    m_controller->Release('L');
}






