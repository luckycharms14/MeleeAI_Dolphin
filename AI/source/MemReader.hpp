#ifndef MEM_READER_HPP
#define MEM_READER_HPP

#define NUM_ADDR 8

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <poll.h>

#include <map>
#include <thread>

#include "GameState.hpp"


enum MemoryAddress
{ 
  Player1Stocks, 
  Player2Stocks, 
  Player1Percent,
  Player2Percent
};

class MemReader {

private:

  static MemReader* m_instance;
  GameState m_gameState

  long raw_data[NUM_ADDR];

  std::map<std::string, int> m_address_index {
    {"8045310E", Player1Stocks},
    {"80453F9E", Player2Stocks},
    {"804530E0", Player1Percent},
    {"80453F70", Player2Percent},
    // {0x803F0E08, 4},
    // {0x803F0E2C, 5},
    // {0x80453090, 6},
    // {0x80453094, 7},
    // {0x80453F20, 8},
    // {0x80453F24, 9},
    // {0x804D6CAD, 10},
    // {0x8046B6CC, 11},
    // {0x70, 12},
    // {0xF0, 13},
    // {0x140, 14},
    // {0x19BC, 15},
    // {0x19C8, 16},
    // {0x19F8, 17},
    // {0x23A0, 18}
  };

  int fd;
  struct sockaddr_un addr; 


public:

  void MonitorMemory();
  MemReader(GameState* gs);
  // static MemReader* Instance();
  // std::thread MemMonitorThread();
  // long ReadAddress(int);
  // void UpdateMemAddress(long,long);

};

#endif
