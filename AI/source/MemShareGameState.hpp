#ifndef MEM_SHARE_GAME_STATE_HPP
#define MEM_SHARE_GAME_STATE_HPP

#include "GameState.hpp"

#include <boost/interprocess/managed_shared_memory.hpp>

class MemShareGameState : public GameState {

private:

  boost::interprocess::managed_shared_memory melee_mem;

public:

  MemShareGameState();

  void UpdateAddress(int);

};

#endif
