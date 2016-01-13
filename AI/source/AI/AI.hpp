#ifndef AI_HPP
#define AI_HPP

#include "../GameState.hpp"
#include "MoveSet.hpp"

#include <random>
#include <exception>

class ActionInterruptedException : public std::exception {};

class AI {

private:

protected:

  MoveSet* m_move_set;
  GameState* m_game_state;
  std::default_random_engine* m_generator;  

public:

  bool CoinFlip(double);
  bool IsOffStage();
  bool InHitstun();
  bool InHitlag();
  void WaitForHitstun();
  double StageLimit();  
  void WaitAndReact(int);
  bool OnLedge();
  int StageSide();
  double Xcoord();
  double Ycoord();
  double Uniform(double,double);

  AI();
  ~AI();

};

#endif
