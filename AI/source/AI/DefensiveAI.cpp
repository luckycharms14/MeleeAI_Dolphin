#include "../Global.hpp"
#include "DefensiveAI.hpp"

#include <iostream>

DefensiveAI::DefensiveAI() : AI() {
  m_recovery_bot = new RecoveryFox();
  m_ledge_bot = new LedgeBot();
}
  
DefensiveAI::~DefensiveAI() {
  delete m_recovery_bot;
  delete m_ledge_bot;
}

void DefensiveAI::MakeMove() {
  WaitForTrigger();  
  if (OnLedge()) {
    m_ledge_bot->GetUp();
  } else if (IsOffStage()) {
    WaitForHitstun();
    try {
      m_recovery_bot->Recover();
    } catch (ActionInterruptedException e) {}
  }
}

void DefensiveAI::WaitForTrigger() {
  while (!TriggerEvents()) {
    if(m_game_state->P2ActionState() == 0x0D) { //respawning
      m_move_set->HoldStick(270); //fast fall, TODO: put in moveset
      WaitAndReact(20);
      m_move_set->ReleaseStick();
    }
    GLOBAL_SLEEP(17)
  }
} 

bool DefensiveAI::TriggerEvents() {
  return IsOffStage() || OnLedge();
} 
