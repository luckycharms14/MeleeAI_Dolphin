#include "MemShareController.hpp"

#include <cmath>

MemShareController::MemShareController() {
	{
		using namespace boost::interprocess;
		melee_mem = managed_shared_memory{open_only, "MeleeAI"};
	}
  for (int i = 0; i < 19; ++i) {
    m_full_control_state[i] = 0;
  }
  m_controller_state.buttons = 0;
  m_controller_state.control_stick[0] = 0;
  m_controller_state.control_stick[1] = 0;
  m_controller_state.c_stick[0] = 0;
  m_controller_state.c_stick[1] = 0;

}

void MemShareController::Press(char button) {
  m_controller_state.buttons += m_button_hex_map[button];
  WriteState();
}

void MemShareController::Release(char button) {
  m_controller_state.buttons -= m_button_hex_map[button];
  WriteState();
}  

void MemShareController::Stick(float rad, int deg, bool CStick) {

  union LongFloat {
    long lg;
    float fl;
  };
  union LongFloat x,y;

  x.fl = rad * cos (deg * M_PI / 180);
  y.fl = rad * sin (deg * M_PI / 180);
  
  if (CStick) {  
    m_controller_state.c_stick[0] = x.lg;
    m_controller_state.c_stick[1] = y.lg;
  } else {
    m_controller_state.control_stick[0] = x.lg;
    m_controller_state.control_stick[1] = y.lg;
  }

  WriteState();

}

void MemShareController::WriteState() {

  m_full_control_state[0] = m_controller_state.buttons;
  m_full_control_state[11] = m_controller_state.control_stick[0];
  m_full_control_state[12] = m_controller_state.control_stick[1];
  m_full_control_state[13] = m_controller_state.c_stick[0];
  m_full_control_state[14] = m_controller_state.c_stick[1];

  std::pair<long*, std::size_t> p = melee_mem.find<long>("melee_ai_contr");

  for (int i = 0; i < 19; ++i) {
    *(p.first++) = m_full_control_state[i];
  }

}


