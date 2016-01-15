#include "Global.hpp"
#include "GameState.hpp"
#include "MemReader.hpp"

#include <thread>
#include <iostream>

int main() {
    
    std::thread mem_reader_thread = MemReader::Init();

    GameState* gs_1 = GameState::Instance();

    while (1) {
        std::cout << std::hex << gs_1->p2_vert_velocity << std::endl;
        GLOBAL_SLEEP(100);
    }
}

/*
enum MemoryAddress
{
  p1_stocks,
  p2_stocks,
  p1_percent,
  p2_percent,
  p1_char,
  p2_char,
  p1_x,
  p1_y,
  p2_x,
  p2_y,
  stage_id,
  frame_count,
  p2_action_state,
  p2_vert_velocity,
  p2_in_air,
  p2_hitlag_frames,
  p2_jumps_used,
  p2_shield_size,
  p2_hitstun_frames,
  in_game
};
*/