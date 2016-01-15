#ifndef DI_BOT_HPP
#define DI_BOT_HPP

#include "AI.hpp"

class DIBot : AI {
public:
    DIBot() : AI() {}
    void DI();

private:
    void WaitForHitlag();
};

#endif