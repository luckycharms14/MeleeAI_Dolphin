#include "Global.hpp"
#include "GameState.hpp"

GameState* GameState::m_instance = nullptr;

GameState* GameState::Instance() {
  if (m_instance == nullptr) {
    m_instance = new GameState();
  }
  return m_instance;
}  

