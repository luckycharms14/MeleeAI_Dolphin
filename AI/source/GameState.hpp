#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#define MEM_SIZE 19

#include <utility>
#include <boost/interprocess/managed_shared_memory.hpp>

class GameState {

private:

	long raw_input[MEM_SIZE];
  long contr_input[19];
  boost::interprocess::managed_shared_memory melee_mem;
  
  float LongToFloat(long);
  
public:
	
	GameState();
	
  void UpdateAddress(int);

  int Stocks(int);
  int Percent(int);
  int CharacterID(int);
  std::pair<float, float> Coordinates(int);
  int StageID();
  int FrameCount();
  bool InGame();
  
  //TODO: have a function that waits for the next frame in the game
  int P2Hitstun();
  float P2VerticalVelocity();
  long P2ActionState();
  int P2Hitlag();
  int P2JumpsUsed();
  float P2ShieldSize();
  bool P2InAir();

  long Raw(int); //get raw data from dolphin

};

#endif



