#include "../Global.hpp"
#include "../StageInfo.hpp"
#include "AI.hpp"

#include <cmath>
#include <iostream>

AI::AI() {
  m_game_state = new GameState();
  m_move_set = new MoveSet();
  m_generator = new std::default_random_engine;
}

AI::~AI() {
  delete m_game_state;
  delete m_move_set;
  delete m_generator;
}

bool AI::CoinFlip(double prob) {
  std::uniform_real_distribution<double> dist(0.0,1.0);
  return (dist(*m_generator) < prob);
}

double AI::Uniform(double a, double b) {
  std::uniform_real_distribution<double> dist(a,b);
  return dist(*m_generator);
}

bool AI::IsOffStage() {
  return abs(Xcoord()) > abs(StageLimit());
}

bool AI::InHitstun() {
  return (m_game_state->P2InAir() && (m_game_state->P2Hitstun() > 0));
}

double AI::StageLimit() {
  return StageInfo::Limit(m_game_state->StageID());
}

void AI::WaitForHitstun() {
  while (m_game_state->P2Hitstun() > 0) {
    GLOBAL_SLEEP(17)
  }
}

void AI::WaitAndReact(int frames) {
  int count = 0;
  while (count < frames) {
    if (m_game_state->P2Hitstun() == 0 && !OnLedge()) {
      GLOBAL_SLEEP(17);
      count++;
    } else {
      m_move_set->ReleaseStick();
      throw ActionInterruptedException();
    }
  }
}

bool AI::OnLedge() {
  while (m_game_state->P2ActionState() == 0xFC) {
    GLOBAL_SLEEP(17);
  }
  return (m_game_state->P2ActionState() == 0xFD);
}  

//0 on left side, 1 on right side
int AI::StageSide() {
  return 0.5 * (1 + GLOBAL_SIGN(Xcoord()));
}

double AI::Xcoord() {
  return m_game_state->Coordinates(2).first;
}

double AI::Ycoord() {
  return m_game_state->Coordinates(2).second;
}



