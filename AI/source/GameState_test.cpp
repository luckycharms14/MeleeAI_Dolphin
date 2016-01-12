#include "Global.hpp"
#include "GameState.hpp"
#include "MemReader.hpp"

#include <thread>
#include <iostream>

int main() {
  
  MemReader* mr = MemReader::Instance();
  std::thread mem_reader = mr->MemMonitorThread();

  GameState* gs_1 = new GameState();
  GameState* gs_2 = new GameState();

  while (1) {
//    std::cout << gs_1->Stocks(1) << " " << gs_2->Stocks(2) << std::endl;
//    std::cout << gs_2->Percent(1) << " " << gs_2->Percent(2) << std::endl;
//    std::cout << gs_1->CharacterID(1) << " " << gs_2->CharacterID(2) << std::endl;
//    std::cout << gs_2->FrameCount() << std::endl;
//    std::cout << gs_1->Coordinates(1).first << " " << gs_1->Coordinates(1).second << std::endl;
//    std::cout << gs_2->Coordinates(2).first << " " << gs_2->Coordinates(2).second << std::endl;
    GLOBAL_SLEEP(100);
  }
}

