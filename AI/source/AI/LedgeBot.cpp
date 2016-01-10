#include "LedgeBot.hpp"
#include "../Global.hpp"

//TODO: clean this up
void LedgeBot::GetUp() {
  double dash_angle = 30; // -30 degrees
  double ang = (180 + 2*dash_angle) * StageSide() - dash_angle; //really jank
  m_move_set->LedgeDash(m_game_state->CharacterID(2),ang);
}
