#ifndef DEFENSIVE_AI_HPP
#define DEFENSIVE_AI_HPP

#include "RecoveryBot/RecoveryBot.hpp"
#include "RecoveryBot/RecoveryFox.hpp"

#include "LedgeBot.hpp"
#include "TechBot.hpp"
#include "DIBot.hpp"

class DefensiveAI : public AI {
public:
    DefensiveAI();
    ~DefensiveAI();

    void MakeMove();
    void WaitForTrigger();
    bool TriggerEvents();
    
private:
    RecoveryBot* m_recovery_bot;
    LedgeBot* m_ledge_bot;
    DIBot* m_di_bot;
    TechBot* m_tech_bot;
};

#endif