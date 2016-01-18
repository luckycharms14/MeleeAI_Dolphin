#ifndef MOVE_SET_HPP
#define MOVE_SET_HPP

#include "../Controller.hpp"

class MoveSet {
public:
    MoveSet(Controller*);
    ~MoveSet();

    void UpB();
    void SideB(char);
    void DoubleJump();
    void HoldStick(int);
    void ReleaseStick();
    void LedgeDash(int,int);
    void HitTech();
    
private:
    Controller* m_controller;
};

#endif