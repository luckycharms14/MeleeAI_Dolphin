#ifndef DI_BOT_HPP
#define DI_BOT_HPP

#include "AI.hpp"

class DIBot : AI {
public:
    DIBot(Controller* controller) : AI(controller) {}
    void DI();

private:
    void WaitForHitlag();
};

#endif