#include "Global.hpp"
#include "GameState.hpp"
#include "MemReader.hpp"
#include "AI/DefensiveAI.hpp"

#include <thread>

int main() {
  
  // MemReader* mem_reader = MemReader::Instance();
  // std::thread mr_thread = mem_reader->MemMonitorThread();

  // DefensiveAI ai = DefensiveAI();  
  GameState game_state = GameState();
  auto mem_reader = MemReader(game_state);

  // while(1) {
  //   while (!game_state.InGame()) {GLOBAL_SLEEP(100)}
  //   ai.MakeMove();
  // }

}    

