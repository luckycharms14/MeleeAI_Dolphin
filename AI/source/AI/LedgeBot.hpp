#ifndef LEDGE_BOT_HPP
#define LEDGE_BOT_HPP

#include "AI.hpp"

class LedgeBot : public AI {

    private:

    public:

        LedgeBot() : AI() {}
        virtual ~LedgeBot() {}

        void GetUp();

};


#endif