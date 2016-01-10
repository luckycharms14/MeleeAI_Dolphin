#include "PipeController.hpp"

#include <cmath>


std::string PipeController::pipePath = "/path/to/pipe";

PipeController::PipeController() {

  namedPipe = new std::ofstream();
  namedPipe->open (pipePath);

}

PipeController::~PipeController() {

  namedPipe->close();

}

void PipeController::Press(char button) {
  std::string output = "PRESS ";
  *namedPipe << ((output + button) + "\n");
}

void PipeController::Release(char button) {
  std::string output = "RELEASE ";
  *namedPipe << ((output + button) + "\n");
}  

void PipeController::Stick(float rad, int deg, bool CStick) {

  float x, y;

  x = rad * cos (deg * M_PI / 180);
  y = rad * sin (deg * M_PI / 180);

  std::string output = "SET ";
  output += (CStick ? "1 " : "0 ");
  output += std::to_string(x);
  output += " ";
  output += std::to_string(y);

  *namedPipe << (output + "\n");

}