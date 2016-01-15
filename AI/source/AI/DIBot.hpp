#ifndef DI_BOT_HPP
#define DI_BOT_HPP

#include "AI.hpp"

class DIBot : AI {

private:

    void WaitForHitlag();

public:
    
    DIBot() : AI() {}

    void DI();

};

#endif