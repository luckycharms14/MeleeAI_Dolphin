#ifndef MEM_READER_HPP
#define MEM_READER_HPP

#include "GameState.hpp"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <poll.h>

#include <map>
#include <thread>

enum MemoryAddress
{
  p1_stocks,
  p2_stocks,
  p1_percent,
  p2_percent,
  p1_char,
  p2_char,
  p1_x,
  p1_y,
  p2_x,
  p2_y,
  stage_id,
  frame_count,
  p2_action_state,
  p2_vert_velocity,
  p2_in_air,
  p2_hitlag_frames,
  p2_jumps_used,
  p2_shield_size,
  p2_hitstun_frames
};

class MemReader {

private:

  std::map<std::string,int> m_address_index { 
    {"8045310E", p1_stocks},
    {"80453F9E", p2_stocks},
    {"804530E0", p1_percent},
    {"80453F70", p2_percent},
    {"803F0E08", p1_char},
    {"803F0E2C", p2_char},
    {"80453090", p1_x},
    {"80453094", p1_y},
    {"80453F20", p2_x},
    {"80453F24", p2_y},
    {"804D6CAD", stage_id},
    {"8046B6CC", frame_count},
    {"80453FC0 70", p2_action_state},
    {"80453FC0 F0", p2_vert_velocity},
    {"80453FC0 140", p2_in_air},
    {"80453FC0 19BC", p2_hitlag_frames},
    {"80453FC0 19C8", p2_jumps_used},
    {"80453FC0 19F8", p2_shield_size},
    {"80453FC0 23A0", p2_hitstun_frames}
  };

  int fd;
  struct sockaddr_un addr; 

  GameState* m_game_state;

  void MonitorMemory();
  void SocketSetup();
  void UpdateMemAddress(std::string,long);
  float LongToFloat(long);

public:

  MemReader(GameState*);

  std::thread MemMonitorThread();

};

#endif
