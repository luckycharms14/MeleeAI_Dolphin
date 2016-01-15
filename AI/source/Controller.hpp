#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

class Controller {
public:
    virtual ~Controller(){}

    virtual void Press(char) = 0;
    virtual void Release(char) = 0;

    /** 1st arg = 0 to 1, radius of stick
        2nd arg = 0 to 360, angle of stick, pushed to the right = 0 degrees
        3rd arg, true for c-stick, false for control stick
    */
    virtual void Stick(float,int,bool=false) = 0;
};

#endif