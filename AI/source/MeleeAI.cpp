#include "Global.hpp"
#include "GameState.hpp"
#include "SocketGameState.hpp"
#include "AI/MoveSet.hpp"
#include "AI/AI.hpp"
#include "AI/DefensiveAI.hpp"

#include <iostream>
#include <sstream>
#include <cmath>

int main() {
  
  DefensiveAI ai = DefensiveAI();
  MoveSet mv = MoveSet();
  GameState* st = new SocketGameState();

  while (true) {
    while(!st->InGame()) {GLOBAL_SLEEP(100)}
    ai.MakeMove();
//    mv.LedgeDash(-17);
//    std::cout << st->P2InAir() << std::endl;
//    std::cout << st->CharacterID(1) << " " << st->CharacterID(2) << std::endl;
//    std::cout << std::hex << st->Raw(16) << std::endl;
    GLOBAL_SLEEP(100)
  }

  delete st;
}

