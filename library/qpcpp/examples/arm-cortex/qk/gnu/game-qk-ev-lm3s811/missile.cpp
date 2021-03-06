//////////////////////////////////////////////////////////////////////////////
// Model: game.qm
// File:  ././missile.cpp
//
// This file has been generated automatically by QP Modeler (QM).
// DO NOT EDIT THIS FILE MANUALLY.
//
// Please visit www.state-machine.com/qm for more information.
//////////////////////////////////////////////////////////////////////////////
#include "qp_port.h"
#include "bsp.h"
#include "game.h"

namespace GAME {

//Q_DEFINE_THIS_FILE

// local objects -------------------------------------------------------------
// @(/2/2) ...................................................................
/// Missile Active Object
class Missile : public QP::QActive {
private:
    uint8_t m_x;
    uint8_t m_y;
    uint8_t m_exp_ctr;

public:
    Missile();

protected:
    static QP::QState initial(Missile * const me, QP::QEvt const * const e);
    static QP::QState armed(Missile * const me, QP::QEvt const * const e);
    static QP::QState flying(Missile * const me, QP::QEvt const * const e);
    static QP::QState exploding(Missile * const me, QP::QEvt const * const e);
};
static Missile l_missile;    // the sole instance of the Missile active object

// Public-scope objects ------------------------------------------------------
QP::QActive * const AO_Missile = &l_missile;                 // opaque pointer

// Active object definition --------------------------------------------------
// @(/2/2) ...................................................................
// @(/2/2/3) .................................................................
Missile::Missile() 
  : QActive(Q_STATE_CAST(&Missile::initial))
{
}

// @(/2/2/4) .................................................................
// @(/2/2/4/0)
QP::QState Missile::initial(Missile * const me, QP::QEvt const * const e) {
    me->subscribe( TIME_TICK_SIG);

    QS_OBJ_DICTIONARY(&l_missile);  // object dictionary for Missile object

    QS_FUN_DICTIONARY(&Missile::initial); // dictionaries for Missile HSM
    QS_FUN_DICTIONARY(&Missile::armed);
    QS_FUN_DICTIONARY(&Missile::flying);
    QS_FUN_DICTIONARY(&Missile::exploding);

    QS_SIG_DICTIONARY(MISSILE_FIRE_SIG,   &l_missile);     // local signals
    QS_SIG_DICTIONARY(HIT_WALL_SIG,       &l_missile);
    QS_SIG_DICTIONARY(DESTROYED_MINE_SIG, &l_missile);
    return Q_TRAN(&Missile::armed);
}
// @(/2/2/4/1) ...............................................................
QP::QState Missile::armed(Missile * const me, QP::QEvt const * const e) {
    QP::QState status;
    switch (e->sig) {
        // @(/2/2/4/1/0)
        case MISSILE_FIRE_SIG: {
            me->m_x = Q_EVT_CAST(ObjectPosEvt)->x;
            me->m_y = Q_EVT_CAST(ObjectPosEvt)->y;
            status = Q_TRAN(&Missile::flying);
            break;
        }
        default: {
            status = Q_SUPER(&QHsm::top);
            break;
        }
    }
    return status;
}
// @(/2/2/4/2) ...............................................................
QP::QState Missile::flying(Missile * const me, QP::QEvt const * const e) {
    QP::QState status;
    switch (e->sig) {
        // @(/2/2/4/2/0)
        case TIME_TICK_SIG: {
            // @(/2/2/4/2/0/0)
            if (me->m_x + GAME_MISSILE_SPEED_X < GAME_SCREEN_WIDTH) {
                me->m_x += GAME_MISSILE_SPEED_X;
                // tell the Tunnel to draw the Missile and test for wall hits
                ObjectImageEvt *oie = Q_NEW(ObjectImageEvt, MISSILE_IMG_SIG);
                oie->x   = me->m_x;
                oie->y   = me->m_y;
                oie->bmp = MISSILE_BMP;
                AO_Tunnel->POST(oie, me);
                status = Q_HANDLED();
            }
            // @(/2/2/4/2/0/1)
            else {
                status = Q_TRAN(&Missile::armed);
            }
            break;
        }
        // @(/2/2/4/2/1)
        case HIT_WALL_SIG: {
            status = Q_TRAN(&Missile::exploding);
            break;
        }
        // @(/2/2/4/2/2)
        case DESTROYED_MINE_SIG: {
            AO_Ship->POST(e, me);
            status = Q_TRAN(&Missile::armed);
            break;
        }
        default: {
            status = Q_SUPER(&QHsm::top);
            break;
        }
    }
    return status;
}
// @(/2/2/4/3) ...............................................................
QP::QState Missile::exploding(Missile * const me, QP::QEvt const * const e) {
    QP::QState status;
    switch (e->sig) {
        // @(/2/2/4/3)
        case Q_ENTRY_SIG: {
            me->m_exp_ctr = 0U;
            status = Q_HANDLED();
            break;
        }
        // @(/2/2/4/3/0)
        case TIME_TICK_SIG: {
            // @(/2/2/4/3/0/0)
            if ((me->m_x >= GAME_SPEED_X) && (me->m_exp_ctr < 15U)) {
                ++me->m_exp_ctr;           // advance the explosion counter
                me->m_x -= GAME_SPEED_X;   // move the explosion by one step

                // tell the Tunnel to render the current stage of Explosion
                ObjectImageEvt *oie = Q_NEW(ObjectImageEvt, EXPLOSION_SIG);
                oie->x   = me->m_x + 3U;   // x-pos of explosion
                oie->y   = (int8_t)((int)me->m_y - 4U); // y-pos
                oie->bmp = EXPLOSION0_BMP + (me->m_exp_ctr >> 2);
                AO_Tunnel->POST(oie, me);
                status = Q_HANDLED();
            }
            // @(/2/2/4/3/0/1)
            else {
                status = Q_TRAN(&Missile::armed);
            }
            break;
        }
        default: {
            status = Q_SUPER(&QHsm::top);
            break;
        }
    }
    return status;
}


} // namespace GAME
