#include "Global.hpp"
#include "PipeController.hpp"

#include <cmath>


std::string PipeController::pipePath = DOLPHIN_PATH + "/Pipes/pipe";

PipeController::PipeController() {

    namedPipe = new std::ofstream();
    namedPipe->open (pipePath);

}

PipeController::~PipeController() {

    namedPipe->close();

}

void PipeController::Press(char button) {
    std::string output = "PRESS ";
    *namedPipe << ((output + button) + "\n") << std::flush;
}

void PipeController::Release(char button) {
    std::string output = "RELEASE ";
    *namedPipe << ((output + button) + "\n") << std::flush;
}  

void PipeController::Stick(float rad, int deg, bool CStick) {

    float x, y;

    x = 0.5 + rad * cos (deg * M_PI / 180) / 2;
    y = 0.5 + rad * sin (deg * M_PI / 180) / 2;

    std::string output = "SET ";
    output += (CStick ? "C " : "MAIN ");
    output += std::to_string(x);
    output += " ";
    output += std::to_string(y);

    *namedPipe << (output + "\n") << std::flush;

}