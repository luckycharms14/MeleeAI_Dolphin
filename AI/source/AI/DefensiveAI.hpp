#ifndef DEFENSIVE_AI_HPP
#define DEFENSIVE_AI_HPP

#include "RecoveryBot/RecoveryBot.hpp"
#include "RecoveryBot/RecoveryFox.hpp"

#include "LedgeBot.hpp"

class DefensiveAI : public AI {

private:

  RecoveryBot* m_recovery_bot;
  LedgeBot* m_ledge_bot;

public:

  DefensiveAI();
  ~DefensiveAI();

  void MakeMove();
  void WaitForTrigger();
  bool TriggerEvents();

};

#endif
