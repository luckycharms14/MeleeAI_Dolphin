#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#define MEM_SIZE 19

#include "MemReader.hpp"

#include <utility>
#include <stdint.h>

class GameState {

private:

  float LongToFloat(long);
  MemReader* m_mem_reader;

public:
	
  GameState();

  int Stocks(int);
  int Percent(int);
  int CharacterID(int);
  std::pair<float, float> Coordinates(int);
  int FrameCount();
  int StageID();
  bool InGame();

  long P2ActionState();
  int P2JumpsUsed();
  
  //TODO: have a function that waits for the next frame in the game
  int P2Hitstun();
  float P2VerticalVelocity();
  int P2Hitlag();
  float P2ShieldSize();
  bool P2InAir();

};

#endif



