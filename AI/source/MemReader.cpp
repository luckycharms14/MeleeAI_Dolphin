#include "MemReader.hpp"

#include <iostream>

#define PATH "/home/tom/.dolphin-emu/MemoryWatcher/MemoryWatcher"

// MemReader* MemReader::m_instance = NULL;

// MemReader* MemReader::Instance(GameState* gs) {
//   if (m_instance == NULL) {
//     m_instance = new MemReader();
//   }
//   return m_instance;
// }

MemReader::MemReader() {
  fd = socket(AF_UNIX, SOCK_DGRAM, 0); //TODO: add error handling
  memset(&addr, 0, sizeof(addr));
  addr.sun_family = AF_UNIX;
  unlink(PATH);
  strncpy(addr.sun_path, PATH, sizeof(addr.sun_path) - 1);
  bind(fd, (struct sockaddr*) &addr, sizeof(addr));//TODO: add error handling
}

void MemReader::MonitorMemory() {
  //TODO: can only be called once, include check for that
  char* buf[128];
  char temp[24];
  char add[8];  
  char val[8];

  while (1) {
      struct sockaddr remaddr;
      socklen_t addr_len;

      recvfrom(fd, buf, sizeof(buf), 0, &remaddr, &addr_len);
      snprintf(temp,24,"%s",buf); 
      strncpy(add, temp, 8);
      strncpy(val, temp + 9,8);
      // UpdateMemAddress(strtol(add,NULL,16), strtol(val,NULL,16));
  }
}

// std::thread MemReader::MemMonitorThread() {
//   return std::thread([=] {MonitorMemory();});
// }

void MemReader::UpdateMemAddress(std::string add, long val) {
//  std::cout << std::hex << add << " " << val << std::endl;
  // raw_data[m_address_index[add]] = val;
  switch(m_address_index[add]):
    case Player1Stocks : m_gameState->player1Stocks = val >> 24;   break;
    case Player2Stocks : m_gameState->player2Stocks = val >> 24; break;
    case Player1Percent : m_gameState->player1Percent = val >> 16;  break;
    case Player2Percent : m_gameState->player2Percent = val >> 16;  break;
}

// long MemReader::ReadAddress(int n) {
//   return raw_data[n];
// }
