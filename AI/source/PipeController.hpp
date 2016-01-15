#ifndef PIPECONTROLLER_HPP
#define PIPECONTROLLER_HPP

#include "Controller.hpp"
#include <iostream>
#include <fstream>
#include <string>

class PipeController : public Controller {

private:

    static std::string pipePath;
    std::ofstream* namedPipe;

public:

    PipeController();
    ~PipeController();
    void Press(char);
    void Release(char);    

    /** 1st arg = 0 to 1, radius of stick
        2nd arg = 0 to 360, angle of stick, pushed to the right = 0 degrees
        3rd arg, true for c-stick, false for control stick
    */
    void Stick(float,int,bool=false);

  };

#endif