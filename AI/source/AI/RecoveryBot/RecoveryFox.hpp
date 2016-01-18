#ifndef RECOVERY_FOX_HPP
#define RECOVERY_FOX_HPP

#include "RecoveryBot.hpp"

class RecoveryFox : public RecoveryBot {

private:

public:

  RecoveryFox(Controller* controller) : RecoveryBot(controller) {}
 
  void Recover();

  void FirefoxRecovery();
  void IllusionRecovery();
  void Firefox(int);
  void FadeToLedge();
  int LedgeAngle();
  int HighestAngle();
  int GetAngle(double,double);
  int CleanAngle(int);
  double IllusionHeight();
};

#endif
