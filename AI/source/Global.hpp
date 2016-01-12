#include <cstdlib>
#include <chrono>
#include <thread>

#define GLOBAL_SLEEP(x) std::this_thread::sleep_for(std::chrono::milliseconds(x));
#define GLOBAL_SIGN(x) ((x > 0) - (x < 0))
