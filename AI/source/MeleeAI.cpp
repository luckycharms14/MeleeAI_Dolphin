#include "Global.hpp"
#include "GameState.hpp"
#include "MemReader.hpp"
#include "AI/AI.hpp"
#include "AI/DefensiveAI.hpp"

#include <thread>

int main() {
  
  std::thread mem_reader_thread = MemReader::Init();
  DefensiveAI* ai = new DefensiveAI();
  GameState* game_state = GameState::Instance();

  while (1) {
    while (!game_state->in_game) {GLOBAL_SLEEP(100)}
    ai->MakeMove();
  }
}

