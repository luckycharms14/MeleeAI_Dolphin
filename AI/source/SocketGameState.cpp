#include "SocketGameState.hpp"

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
  char temp1[16];
  char temp2[24];
  char add[8];  
  char val[8];
  char offset[6];

  while (poll(&fds,1,NULL) > 0)
  {
      struct sockaddr remaddr;
      socklen_t addr_len;

      recvfrom(fd, buf, sizeof(buf), 0, &remaddr, &addr_len);
      sprintf(temp1,"%s",buf); 
      strncpy(add, temp1, 8);
      if (strcmp(add, "80453130") == 0) {
        sprintf(temp2,"%s",buf); 
        strncpy(offset,temp2 + 12, 4);
        strcpy(val, temp2 + 16);
        UpdateMemSlot(strtol(offset,NULL,16),strtol(val,NULL,16));
      } else {
        strncpy(val, temp1 + 8, 8);
        UpdateMemSlot(strtol(add,NULL,16), strtol(val,NULL,16));
      }
  }
}

void SocketGameState::UpdateMemSlot(uint32_t add, uint32_t val) {

  raw_input[m_address_index[add]] = val;

}





