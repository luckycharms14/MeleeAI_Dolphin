#include "../Global.hpp"
#include "DIBot.hpp"

void DIBot::WaitForHitlag() {
    GLOBAL_WAIT_FRAMES(m_game_state->p2_hitlag_frames-1);
}

void DIBot::DI() {
    WaitForHitlag();
    m_move_set->HoldStick(180); //still in testing
    GLOBAL_WAIT_FRAMES(1)
    m_move_set->ReleaseStick();
}