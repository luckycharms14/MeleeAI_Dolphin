#include "Global.hpp"
#include "GameState.hpp"

GameState* GameState::m_instance = nullptr;

GameState* GameState::Instance() {
  if (m_instance == nullptr) {
    m_instance = new GameState();
  }
  return m_instance;
}  

bool GameState::InGame() {
  int last_frame = frame_count;
  GLOBAL_SLEEP(30); 
  return last_frame != frame_count;
}
