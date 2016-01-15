#include "Global.hpp"
#include "GameState.hpp"
#include "MemReader.hpp"
#include "AI/AI.hpp"
#include "AI/DefensiveAI.hpp"

#include <thread>

int main() {
    std::thread mem_reader_thread = MemReader::Init();
    DefensiveAI* ai = new DefensiveAI();
    GameState* game_state = GameState::Instance();
    
    while (1) {
    //TODO: check for pause here as well, need to add mem address for that    
        while (!game_state->in_game) {GLOBAL_WAIT_FRAMES(1)}
            ai->MakeMove();  
    }
}

