#include "GameState.hpp"

#include <cstdlib>
#include <string>

#define GLOBAL_WAIT_FRAMES(x) GameState::WaitFrames(x);
#define GLOBAL_SIGN(x) ((x > 0) - (x < 0))
const std::string DOLPHIN_PATH = "/home/tom/.dolphin-emu";
