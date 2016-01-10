#include "Global.hpp"
#include "GameState.hpp"
#include "AI/MoveSet.hpp"
#include "AI/AI.hpp"
#include "AI/DefensiveAI.hpp"

#include <iostream>
#include <sstream>
#include <cmath>

int main() {
  
  DefensiveAI ai = DefensiveAI();
  MoveSet mv = MoveSet();
  GameState st = GameState();

  while (true) {
    while(!st.InGame()) {GLOBAL_SLEEP(100)}
    ai.MakeMove();
//      mv.LedgeDash(-17);
//    std::cout << std::hex << st.Coordinates(1).second << std::endl;
//    GLOBAL_SLEEP(100)
  }

}

