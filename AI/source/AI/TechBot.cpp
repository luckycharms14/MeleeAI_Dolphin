#include "../Global.hpp"
#include "TechBot.hpp"

void TechBot::Tech() {
    if (CoinFlip(0.8)) {
        if (CoinFlip(0.25)) {
          m_move_set->HoldStick(0);
      } else if (CoinFlip(0.25)) {
          m_move_set->HoldStick(180);  
      }
      m_move_set->HitTech();
  }
  WaitForGround();
  m_move_set->ReleaseStick();
}

void TechBot::WaitForGround() {
  while (m_game_state->p2_in_air && !IsOffStage()) {
    GLOBAL_WAIT_FRAMES(1)
}
}