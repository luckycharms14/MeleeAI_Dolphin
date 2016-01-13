#include "../Global.hpp"
#include "DIBot.hpp"

void DIBot::WaitForHitlag() {
  GLOBAL_SLEEP(17*(m_game_state->p2_hitlag_frames-1));
}

void DIBot::DI() {
  WaitForHitlag();
  m_move_set->HoldStick(180); //still in testing
  GLOBAL_SLEEP(17*2);
  m_move_set->ReleaseStick();
}
