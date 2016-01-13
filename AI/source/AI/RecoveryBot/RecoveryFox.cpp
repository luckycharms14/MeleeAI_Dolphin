#include "../../Global.hpp"
#include "../../StageInfo.hpp"
#include "RecoveryFox.hpp"

#include <cmath>
#include <random>
#include <algorithm>

void RecoveryFox::Recover() {
  if (Ycoord() < -55 || CoinFlip(0.7)) {
    FirefoxRecovery();
  } else {
    IllusionRecovery();
  }
}

void RecoveryFox::FirefoxRecovery() {
  if (m_game_state->p2_jumps_used < 2) {
    if (abs(Xcoord()) - StageLimit() > 100) {
      m_move_set->HoldStick(180 * StageSide()); 
    }
    m_move_set->DoubleJump();
    WaitAndReact(20); 
    m_move_set->ReleaseStick();
  }
  double ledge_ang = LedgeAngle();
  double high_ang = HighestAngle();
  if (ledge_ang < 0 && CoinFlip(0.9)) {
    if (CoinFlip(0.7)) {
      Firefox(ledge_ang);    
    } else {
      Firefox(Uniform(ledge_ang + 10, ledge_ang + 45));
    }
  } else {
    if (Ycoord() < 50 && CoinFlip(0.8)) {
      Firefox(high_ang);
    } else if (CoinFlip(0.45)) {
      Firefox(ledge_ang + 10);
    } else if  (CoinFlip(0.5)) {
      Firefox(high_ang - 15);
    } else {
      Firefox(Uniform(ledge_ang + 15, high_ang));
    }
  }
}

//adjust for side of stage here
void RecoveryFox::Firefox(int angle) {
  if (StageSide() == 1) {
    angle = 180 - angle;
  }
  m_move_set->UpB();
  m_move_set->HoldStick(angle);
  WaitAndReact(42);
  m_move_set->ReleaseStick();
  WaitAndReact(30);
  FadeToLedge();
}

//TODO: this doesn't work always
void RecoveryFox::FadeToLedge() {
  while (Ycoord() > 5) {
    if (abs(Xcoord()) > StageLimit() + 10) {
      m_move_set->HoldStick(180 * StageSide());
    }
    if (abs(Xcoord()) < StageLimit()) {
      m_move_set->HoldStick(180 * (1 - StageSide())); 
    }
    WaitAndReact(1);
  }
  m_move_set->ReleaseStick();
}

//TODO: give a wider margin of error on Battlefield
int RecoveryFox::LedgeAngle() {
  double ang = GetAngle(StageLimit(),-10);  
  if (85 * cos(ang * M_PI / 180) < abs(Xcoord()) - StageLimit() - 10) {
    ang = 45;
  }
  return ang;
}

int RecoveryFox::HighestAngle() {

  double fade_ang = 80 * M_PI / 180;//[63,90]
  double ang_rad = fade_ang + GetAngle(StageLimit(),0) * M_PI / 180;
  double dist = pow(pow(abs(Xcoord())-StageLimit(),2) + pow(Ycoord(),2),0.5);
  double target = dist * cos(ang_rad) + pow(7225 - pow(dist * sin(ang_rad),2),0.5);
  double ang = GetAngle(target * cos(fade_ang) + StageLimit(), target * sin(fade_ang));  
  if (ang < 0 || ang > 90) {ang = 45;}
  return ang;

}

int RecoveryFox::GetAngle(double a, double b) {

  double numer = b - Ycoord();
  double denom = abs(Xcoord()) - abs(a); //maps to left side of stage
  double raw_angle = atan2(numer,denom) * 180 / M_PI;

  return CleanAngle(raw_angle);

}

int RecoveryFox::CleanAngle(int angle) {
  
  if (angle > 90) {angle = 90;}
  if (angle < -90) {angle = -90;}
  if (angle > 0 && angle < 17) {angle = 17;}
  if (angle < 0 && angle > -17) {angle = 0;}
  if (angle > 73 && angle < 90) {angle = 90;}
  if (angle < -73 && angle > -90) {angle = -90;}

  return angle;

}

void RecoveryFox::IllusionRecovery() {
  int jumps_used = m_game_state->p2_jumps_used;
  if (Ycoord() < -55 || (Ycoord() < -15 &&  jumps_used > 1)) {
    FirefoxRecovery();
  } else if (abs(Xcoord()) - StageLimit() > 100 && jumps_used < 2) {
    m_move_set->HoldStick(StageSide() * 180); 
    m_move_set->DoubleJump();
    WaitAndReact(20);
    m_move_set->ReleaseStick();  
  } else if (jumps_used < 2 && (Ycoord() < -15 || CoinFlip(0.3))) {
    m_move_set->DoubleJump();
    WaitAndReact(20);
  }
  double height = IllusionHeight();
  while (Ycoord() > height) {
    WaitAndReact(1);
  }
  if (StageSide() == 1) {
    m_move_set->SideB('L');
  } else {
    m_move_set->SideB('R');
  }
  WaitAndReact(60);
}

double RecoveryFox::IllusionHeight() {
  if (CoinFlip(0.6)) {
    return -5;
  } else if (CoinFlip(0.5)) {
    return StageInfo::SidePlatHeight(m_game_state->stage_id) + 3;
  } else {
    return Uniform(-5, StageInfo::TopPlatHeight(m_game_state->stage_id));
  }
}






