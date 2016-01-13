#include "MemReader.hpp"

#include <iostream>

#define PATH "/home/tom/.dolphin-emu/MemoryWatcher/MemoryWatcher"

MemReader::MemReader(GameState* gs) {
  m_game_state = gs;
  SocketSetup();
}

void MemReader::SocketSetup() {
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
  char temp[32];
  char add[24];  
  char val[8];

  while (1) {
    struct sockaddr remaddr;
    socklen_t addr_len;

    recvfrom(fd, buf, sizeof(buf), 0, &remaddr, &addr_len);
    snprintf(temp,32,"%s",buf); 
    strncpy(add, temp, (strchr(temp, '\n') - temp));
    strncpy(val, temp + (strchr(temp, '\n') - temp) + 1,8);
    UpdateMemAddress(std::string(add), strtol(val,NULL,16));
    memset(add,0,sizeof(add));
    memset(val,0,sizeof(val));
    memset(temp,0,sizeof(temp));
    memset(buf,0,sizeof(buf));
  }
}

std::thread MemReader::MemMonitorThread() {
  return std::thread([=] {MonitorMemory();});
}

void MemReader::UpdateMemAddress(std::string add, long val) {
  switch(m_address_index[add]) {
    case p1_stocks: m_game_state->p1_stocks = val >> 24; break;
    case p2_stocks: m_game_state->p2_stocks = val >> 24; break;
    case p1_percent: m_game_state->p1_percent = val >> 16; break;
    case p2_percent: m_game_state->p2_percent = val >> 16; break;
    case p1_char: m_game_state->p1_char = val & 0xFF; break;
    case p2_char: m_game_state->p2_char = val & 0xFF; break;
    case p1_x: m_game_state->p1_x = LongToFloat(val); break;
    case p1_y: m_game_state->p1_y = LongToFloat(val); break;
    case p2_x: m_game_state->p2_x = LongToFloat(val); break;
    case p2_y: m_game_state->p2_y = LongToFloat(val); break;
    case stage_id: m_game_state->stage_id = val >> 16; break;
    case frame_count: m_game_state->frame_count = val >> 16; break;
    case p2_action_state: m_game_state->p2_action_state = val; break;
    case p2_vert_velocity: m_game_state->p2_vert_velocity = val; break;
    case p2_in_air: m_game_state->p2_x = val; break;
    case p2_hitlag_frames: m_game_state->p2_y = val; break;
    case p2_jumps_used: m_game_state->stage_id = val; break;
    case p2_shield_size: m_game_state->frame_count = val; break;
    case p2_hitstun_frames: m_game_state->frame_count = val; break;
    default: printf("invalid address\n"); break; //TODO: add error handling
  }
}

float MemReader::LongToFloat(long n) {
  union LongFloat {
    long lg;
    float fl;
  };
  union LongFloat ret;
  ret.lg = n;
  return ret.fl;
}
