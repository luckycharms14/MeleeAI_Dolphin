#include "Global.hpp"
#include "GameState.hpp"

#include <chrono>
#include <thread>

GameState* GameState::m_instance = nullptr;

GameState* GameState::Instance() {
    if (m_instance == nullptr) {
        m_instance = new GameState();
    }
    return m_instance;
}  

void GameState::WaitFrames(int n) {
    for (int i = 0; i < n; i++) {
        WaitFrame();
    }
}

void GameState::WaitFrame() {
    GameState* gs = GameState::Instance(); 
    int cur_frame = gs->frame_count;
    while (cur_frame == gs->frame_count) { 
        std::this_thread::sleep_for(std::chrono::milliseconds(4));
    }
}
