/*804530E0
80453F70
8045310E
80453F9E
803F0E0A
803F0E2E
80453090
80453094
80453F20
80453F24
804D6CAD
8046B6CC
80453130 08 70
80453130 08 F0
80453130 08 140
80453130 08 19BC
80453130 08 19C8
80453130 08 19F8
80453130 08 23A0*/


#ifndef SOCKET_GAME_STATE_HPP
#define SOCKET_GAME_STATE_HPP

#include "GameState.hpp"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <poll.h>
#include <map>

class SocketGameState : public GameState {

private:

  char *path = "/home/tom/.dolphin-emu/MemoryWatcher/MemoryWatcher";

  int fd;
  struct sockaddr_un addr; 
  struct pollfd fds;

  std::map<long, int> m_address_index {
    {0x8045310E, 0},
    {0x80453F9E, 1},
    {0x804530E0, 2},
    {0x80453F70, 3},
    {0x803F0E08, 4},
    {0x803F0E2C, 5},
    {0x80453090, 6},
    {0x80453094, 7},
    {0x80453F20, 8},
    {0x80453F24, 9},
    {0x804D6CAD, 10},
    {0x8046B6CC, 11},
    {0x70, 12},
    {0xF0, 13},
    {0x140, 14},
    {0x19BC, 15},
    {0x19C8, 16},
    {0x19F8, 17},
    {0x23A0, 18}
  };

public:

  SocketGameState();

  void UpdateAddress(int);  
  void SocketSetup();
  void Update();
  void UpdateMemSlot(uint32_t, int32_t);

};

#endif
