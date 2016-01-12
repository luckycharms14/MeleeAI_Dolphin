#include "Global.hpp"
#include "GameState.hpp"
#include "SocketGameState.hpp"
#include "AI/MoveSet.hpp"
#include "AI/AI.hpp"
#include "AI/DefensiveAI.hpp"
#include "PipeController.hpp"
#include "Controller.hpp"

#include <iostream>
#include <sstream>
#include <cmath>

int main() {
  
  DefensiveAI ai = DefensiveAI();
  MoveSet mv = MoveSet();
  GameState* st = new SocketGameState();
//  PipeController* cnt = new PipeController();
//  cnt->Stick(1,90);
//  cnt->Press('B');

//  cnt->Release('A');
//  GLOBAL_SLEEP(3000);
//  cnt->Stick(0,0);
//  cnt->Release('X');
//  cnt->Stick(1,90);
//  while (true) {
mv.UpB();      
//    while(!st->InGame()) {GLOBAL_SLEEP(100)}
//    ai.MakeMove();
//    mv.UpB();
//    std::cout << st->P2InAir() << std::endl;
//    std::cout << st->CharacterID(1) << " " << st->CharacterID(2) << std::endl;
//    std::cout << std::hex << st->Raw(16) << std::endl;
//    GLOBAL_SLEEP(100)
//  }

//  delete cnt;
  delete st;
}

