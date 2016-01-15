#ifndef TECH_BOT_HPP
#define TECH_BOT_HPP

#include "AI.hpp"

class TechBot : public AI {
    private:
        void WaitForGround();

    public:
        TechBot() : AI() {}
        void Tech();
};

#endif