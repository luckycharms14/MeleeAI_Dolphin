#include "Global.hpp"
#include "GameState.hpp"
#include "MemReader.hpp"
#include "AI/AI.hpp"
#include "AI/DefensiveAI.hpp"

#include <thread>

int main() {
  
  GameState* game_state = GameState::Instance();
  MemReader mem_reader = MemReader(game_state);
  std::thread mr_thread = mem_reader.MemMonitorThread();
  
  DefensiveAI* ai = new DefensiveAI();

  while (1) {
    while (!game_state->in_game) {GLOBAL_SLEEP(100)}
    ai->MakeMove();
  }
}

