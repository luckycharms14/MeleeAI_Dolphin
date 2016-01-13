#include "Global.hpp"
#include "GameState.hpp"
#include "MemReader.hpp"

#include <thread>
#include <iostream>

int main() {
  
  GameState* game_state = GameState::Instance();
  MemReader mr_1 = MemReader(game_state);
  std::thread mem_reader = mr_1.MemMonitorThread();

  GameState* gs_1 = GameState::Instance();

  while (1) {
    std::cout << std::hex << gs_1->in_game << std::endl;
    GLOBAL_SLEEP(50);
  }
}

