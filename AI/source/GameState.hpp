#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

class GameState {

private:

  GameState() {}

  static GameState* m_instance;

public:

  static GameState* Instance();

  int p1_stocks = 0;
  int p2_stocks = 0;
  int p1_percent = 0;
  int p2_percent = 0;
  int p1_char = 0;
  int p2_char = 0;
  float p1_x = 0.0;
  float p1_y = 0.0;
  float p2_x = 0.0;
  float p2_y = 0.0;
  int stage_id = 0;
  int frame_count = 0;
  int p2_action_state = 0;
  float p2_vert_velocity = 0.0;
  int p2_in_air = 0;
  int p2_hitlag_frames = 0;
  int p2_jumps_used = 0;
  float p2_shield_size = 0.0;
  int p2_hitstun_frames = 0;
  bool in_game = false;
  
};

#endif
