#include "Global.hpp"
#include "GameState.hpp"
#include "MemReader.hpp"

#include <thread>
#include <iostream>

int main() {
    
    std::thread mem_reader_thread = MemReader::Init();

    GameState* gs_1 = GameState::Instance();

    while (1) {
        std::cout << std::hex << gs_1->p2_vert_velocity << std::endl;
        GLOBAL_SLEEP(50);
    }
}

