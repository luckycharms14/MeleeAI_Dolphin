#ifndef RECOVERY_BOT_HPP
#define RECOVERY_BOT_HPP

#include "../AI.hpp"

class RecoveryBot : public AI {

private:

public:

  RecoveryBot() : AI() {}
  virtual ~RecoveryBot() {}
  
  virtual void Recover() = 0;

};

#endif
