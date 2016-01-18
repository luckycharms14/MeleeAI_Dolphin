#ifndef TECH_BOT_HPP
#define TECH_BOT_HPP

#include "AI.hpp"

class TechBot : public AI {
public:
    TechBot(Controller* controller) : AI(controller) {}
    void Tech();

private:
    void WaitForGround();
};

#endif