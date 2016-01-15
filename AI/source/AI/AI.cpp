#include "../Global.hpp"
#include "../StageInfo.hpp"
#include "../GameState.hpp"
#include "AI.hpp"

#include <cmath>
#include <iostream>

AI::AI() {
    m_game_state = GameState::Instance();
    m_move_set = new MoveSet();
    m_generator = new std::default_random_engine;
}

AI::~AI() {
    delete m_move_set;
    delete m_generator;
}

bool AI::CoinFlip(double prob) {
    std::uniform_real_distribution<double> dist(0.0,1.0);
    return (dist(*m_generator) < prob);
}

double AI::Uniform(double a, double b) {
    std::uniform_real_distribution<double> dist(a,b);
    return dist(*m_generator);
}

bool AI::IsOffStage() {
    return abs(Xcoord()) > abs(StageLimit());
}

bool AI::InHitstun() {
    return (m_game_state->p2_in_air && (m_game_state->p2_hitstun_frames > 0));
}

bool AI::InHitlag() {
    return m_game_state->p2_hitlag_frames > 0;
}

double AI::StageLimit() {
    return StageInfo::Limit(m_game_state->stage_id);
}

void AI::WaitForHitstun() {
    while (m_game_state->p2_hitstun_frames > 0) {
        GLOBAL_WAIT_FRAMES(1)
    }
}

bool AI::TechSituation() {
    return m_game_state->p2_in_air && Ycoord() < 5 && m_game_state->p2_vert_velocity < 0;
}

void AI::WaitAndReact(int frames) {
    int count = 0;
    while (count < frames) {
        if (!InHitstun() && !OnLedge() && !InHitlag()) {
            GLOBAL_WAIT_FRAMES(1)
            count++;
        } else {
            m_move_set->ReleaseStick();
            throw ActionInterruptedException();
        }
    }
}

bool AI::OnLedge() {
    while (m_game_state->p2_action_state == 0xFC) {
        GLOBAL_WAIT_FRAMES(1)
    }

    return (m_game_state->p2_action_state == 0xFD);
}  

//0 on left side, 1 on right side
int AI::StageSide() {
    return 0.5 * (1 + GLOBAL_SIGN(Xcoord()));
}

double AI::Xcoord() {
    return m_game_state->p2_x;
}

double AI::Ycoord() {
    return m_game_state->p2_y;
}