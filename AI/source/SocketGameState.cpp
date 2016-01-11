#include "SocketGameState.hpp"

#include <iostream>

/** Code adapted from spxtr's example code
in pull request #3413 for the Dolphin Emulator */

SocketGameState::SocketGameState() {
  SocketSetup();
}

void SocketGameState::UpdateAddress(int n) {
  Update();
}

void SocketGameState::SocketSetup() {
  fd = socket(AF_UNIX, SOCK_DGRAM, 0); //TODO: add error handling
  memset(&addr, 0, sizeof(addr));
  addr.sun_family = AF_UNIX;
  unlink(path);
  strncpy(addr.sun_path, path, sizeof(addr.sun_path) - 1);
  bind(fd, (struct sockaddr*) &addr, sizeof(addr));//TODO: add error handling
  fds.fd = fd;
  fds.events = POLLIN;
}

void SocketGameState::Update() {
  char* buf[128];
  char temp[32];
  char add[9];  
  char val[9];
  char offset[7];

  while (poll(&fds,1,0) > 0)
  {
      struct sockaddr remaddr;
      socklen_t addr_len;

      recvfrom(fd, buf, sizeof(buf), 0, &remaddr, &addr_len);
      snprintf(temp,32,"%s",buf); 
      strncpy(add, temp, 8);
      add[8] = '\0';
      if (strcmp(add, "80453130") == 0) {
        strncpy(offset,temp + 12, 4);
        strncpy(val, temp + 16,9);
        UpdateMemSlot(strtol(offset,NULL,16),strtol(val,NULL,16));
      } else {
        strncpy(val, temp + 8, 9);
        UpdateMemSlot(strtol(add,NULL,16), strtol(val,NULL,16));
      }
  }
}

void SocketGameState::UpdateMemSlot(uint32_t add, uint32_t val) {
  raw_input[m_address_index[add]] = val;
}




