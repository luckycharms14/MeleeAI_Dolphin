#include "GameState.hpp"

#include <cstdlib>
#include <string>
#include <chrono>
#include <thread>

#define GLOBAL_SLEEP(x) std::this_thread::sleep_for(std::chrono::milliseconds(x));
#define GLOBAL_WAIT_FRAMES(x) GameState::WaitFrames(x);
#define GLOBAL_SIGN(x) ((x > 0) - (x < 0))
const std::string DOLPHIN_PATH = "/home/tom/.dolphin-emu";
