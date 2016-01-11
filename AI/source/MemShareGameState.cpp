#include "MemShareGameState.hpp"

#include <boost/interprocess/managed_shared_memory.hpp>

MemShareGameState::MemShareGameState() {
	{
		using namespace boost::interprocess;
		melee_mem = managed_shared_memory{open_only, "MeleeAI"};
	}
}

void MemShareGameState::UpdateAddress(int n) {
  std::pair<long*, std::size_t> melee_read_address = melee_mem.find<long>("game_data");
  raw_input[n] = *(melee_read_address.first + n);
}

