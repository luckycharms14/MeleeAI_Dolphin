#include "../Global.hpp"
#include "DefensiveAI.hpp"

#include <iostream>

DefensiveAI::DefensiveAI(Controller* controller) : AI(controller) {
    m_recovery_bot = new RecoveryFox(controller);
    m_ledge_bot = new LedgeBot(controller);
    m_di_bot = new DIBot(controller);
    m_tech_bot = new TechBot(controller);
}

DefensiveAI::~DefensiveAI() {
    delete m_recovery_bot;
    delete m_ledge_bot;
    delete m_di_bot;
    delete m_tech_bot;
}

void DefensiveAI::MakeMove() {
    WaitForTrigger();  
    if (OnLedge()) {
        m_ledge_bot->GetUp();
    } else if (InHitlag()) {
        m_di_bot->DI();
    } else if (IsOffStage()) {
        WaitForHitstun();
        try {
            m_recovery_bot->Recover();
        } catch (ActionInterruptedException e) {}
    } else if (TechSituation()) {
        m_tech_bot->Tech();
    }
}

void DefensiveAI::WaitForTrigger() {
    while (!TriggerEvents()) {
        if(m_game_state->p2_action_state == 0x0D) { //respawning
            m_move_set->HoldStick(270); //fast fall, TODO: put in moveset
            WaitAndReact(20);
            m_move_set->ReleaseStick();
        }
        GLOBAL_WAIT_FRAMES(1)
    }
} 

bool DefensiveAI::TriggerEvents() {
    return IsOffStage() || OnLedge() || InHitstun() || InHitlag();
}