//////////////////////////////////////////////////////////////////////////////
// Model: game.qm
// File:  ././mine2.cpp
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

Q_DEFINE_THIS_FILE

// encapsulated delcaration of the Mine1 HSM ---------------------------------
// @(/2/4) ...................................................................
/// The Mine2 orthogonal component
class Mine2 : public QP::QHsm {
private:
    uint8_t m_x;
    uint8_t m_y;

public:
    uint8_t m_exp_ctr;

public:
    Mine2();

protected:
    static QP::QState initial(Mine2 * const me, QP::QEvt const * const e);
    static QP::QState unused(Mine2 * const me, QP::QEvt const * const e);
    static QP::QState used(Mine2 * const me, QP::QEvt const * const e);
    static QP::QState exploding(Mine2 * const me, QP::QEvt const * const e);
    static QP::QState planted(Mine2 * const me, QP::QEvt const * const e);
};

// local objects -------------------------------------------------------------
static Mine2 l_mine2[GAME_MINES_MAX]; // a pool of type-2 mines

//............................................................................
QP::QHsm *Mine2_getInst(uint8_t id) {
    Q_REQUIRE(id < GAME_MINES_MAX);
    return &l_mine2[id];
}

// helper function to provide the ID of this mine ............................
static inline uint8_t MINE_ID(Mine2 const * const me) {
    return static_cast<uint8_t>(me - l_mine2);
}

// Mine1 class definition ----------------------------------------------------
// @(/2/4) ...................................................................
// @(/2/4/3) .................................................................
Mine2::Mine2() 
  : QHsm(Q_STATE_CAST(&Mine2::initial))
{
}

// @(/2/4/4) .................................................................
// @(/2/4/4/0)
QP::QState Mine2::initial(Mine2 * const me, QP::QEvt const * const e) {
    static bool dict_sent = false;
    if (!dict_sent) {
        dict_sent = true;
        QS_OBJ_DICTIONARY(&l_mine2[0]); // obj. dictionaries for Mine2 pool
        QS_OBJ_DICTIONARY(&l_mine2[1]);
        QS_OBJ_DICTIONARY(&l_mine2[2]);
        QS_OBJ_DICTIONARY(&l_mine2[3]);
        QS_OBJ_DICTIONARY(&l_mine2[4]);

        QS_FUN_DICTIONARY(&Mine2::initial);// fun. dictionaries for Mine2 HSM
        QS_FUN_DICTIONARY(&Mine2::unused);
        QS_FUN_DICTIONARY(&Mine2::used);
        QS_FUN_DICTIONARY(&Mine2::planted);
        QS_FUN_DICTIONARY(&Mine2::exploding);
    }
    // local signals
    QS_SIG_DICTIONARY(MINE_PLANT_SIG,    me);
    QS_SIG_DICTIONARY(MINE_DISABLED_SIG, me);
    QS_SIG_DICTIONARY(MINE_RECYCLE_SIG,  me);
    QS_SIG_DICTIONARY(SHIP_IMG_SIG,      me);
    QS_SIG_DICTIONARY(MISSILE_IMG_SIG,   me);
    return Q_TRAN(&Mine2::unused);
}
// @(/2/4/4/1) ...............................................................
QP::QState Mine2::unused(Mine2 * const me, QP::QEvt const * const e) {
    QP::QState status;
    switch (e->sig) {
        // @(/2/4/4/1/0)
        case MINE_PLANT_SIG: {
            me->m_x = Q_EVT_CAST(ObjectPosEvt)->x;
            me->m_y = Q_EVT_CAST(ObjectPosEvt)->y;
            status = Q_TRAN(&Mine2::planted);
            break;
        }
        default: {
            status = Q_SUPER(&QHsm::top);
            break;
        }
    }
    return status;
}
// @(/2/4/4/2) ...............................................................
QP::QState Mine2::used(Mine2 * const me, QP::QEvt const * const e) {
    QP::QState status;
    switch (e->sig) {
        // @(/2/4/4/2)
        case Q_EXIT_SIG: {
            // tell the Tunnel that this mine is becoming disabled
            MineEvt *mev = Q_NEW(MineEvt, MINE_DISABLED_SIG);
            mev->id = MINE_ID(me);
            AO_Tunnel->POST(mev, me);
            status = Q_HANDLED();
            break;
        }
        // @(/2/4/4/2/0)
        case MINE_RECYCLE_SIG: {
            status = Q_TRAN(&Mine2::unused);
            break;
        }
        default: {
            status = Q_SUPER(&QHsm::top);
            break;
        }
    }
    return status;
}
// @(/2/4/4/2/1) .............................................................
QP::QState Mine2::exploding(Mine2 * const me, QP::QEvt const * const e) {
    QP::QState status;
    switch (e->sig) {
        // @(/2/4/4/2/1)
        case Q_ENTRY_SIG: {
            me->m_exp_ctr = 0U;
            status = Q_HANDLED();
            break;
        }
        // @(/2/4/4/2/1/0)
        case TIME_TICK_SIG: {
            // @(/2/4/4/2/1/0/0)
            if ((me->m_x >= GAME_SPEED_X) && (me->m_exp_ctr < 15)) {
                ++me->m_exp_ctr;  // advance the explosion counter
                me->m_x -= GAME_SPEED_X; // move explosion by 1 step

                // tell the Game to render the current stage of Explosion
                ObjectImageEvt *oie = Q_NEW(ObjectImageEvt, EXPLOSION_SIG);
                oie->x   = me->m_x + 1U;  // x of explosion
                oie->y   = (int8_t)((int)me->m_y - 4 + 2); // y of explosion
                oie->bmp = EXPLOSION0_BMP + (me->m_exp_ctr >> 2);
                AO_Tunnel->POST(oie, me);
                status = Q_HANDLED();
            }
            // @(/2/4/4/2/1/0/1)
            else {
                status = Q_TRAN(&Mine2::unused);
            }
            break;
        }
        default: {
            status = Q_SUPER(&Mine2::used);
            break;
        }
    }
    return status;
}
// @(/2/4/4/2/2) .............................................................
QP::QState Mine2::planted(Mine2 * const me, QP::QEvt const * const e) {
    QP::QState status;
    switch (e->sig) {
        // @(/2/4/4/2/2/0)
        case TIME_TICK_SIG: {
            // @(/2/4/4/2/2/0/0)
            if (me->m_x >= GAME_SPEED_X) {
                me->m_x -= GAME_SPEED_X; // move the mine 1 step
                // tell the Tunnel to draw the Mine
                ObjectImageEvt *oie = Q_NEW(ObjectImageEvt, MINE_IMG_SIG);
                oie->x   = me->m_x;
                oie->y   = me->m_y;
                oie->bmp = MINE2_BMP;
                AO_Tunnel->POST(oie, me);
                status = Q_HANDLED();
            }
            // @(/2/4/4/2/2/0/1)
            else {
                status = Q_TRAN(&Mine2::unused);
            }
            break;
        }
        // @(/2/4/4/2/2/1)
        case SHIP_IMG_SIG: {
            uint8_t x   = Q_EVT_CAST(ObjectImageEvt)->x;
            uint8_t y   = Q_EVT_CAST(ObjectImageEvt)->y;
            uint8_t bmp = Q_EVT_CAST(ObjectImageEvt)->bmp;
            // @(/2/4/4/2/2/1/0)
            if (do_bitmaps_overlap(MINE2_BMP, me->m_x, me->m_y, bmp, x, y)) {
                static MineEvt const mine2_hit(HIT_MINE_SIG, 2U);
                AO_Ship->POST(&mine2_hit, me);
                // go straight to 'disabled' and let the Ship do
                // the exploding
                status = Q_TRAN(&Mine2::unused);
            }
            else {
                status = Q_UNHANDLED();
            }
            break;
        }
        // @(/2/4/4/2/2/2)
        case MISSILE_IMG_SIG: {
            uint8_t x   = Q_EVT_CAST(ObjectImageEvt)->x;
            uint8_t y   = Q_EVT_CAST(ObjectImageEvt)->y;
            uint8_t bmp = Q_EVT_CAST(ObjectImageEvt)->bmp;
            // @(/2/4/4/2/2/2/0)
            if (do_bitmaps_overlap(MINE2_MISSILE_BMP, me->m_x, me->m_y, bmp, x, y)) {
                static ScoreEvt const mine2_destroyed(DESTROYED_MINE_SIG, 45U);
                AO_Missile->POST(&mine2_destroyed, me);
                status = Q_TRAN(&Mine2::exploding);
            }
            else {
                status = Q_UNHANDLED();
            }
            break;
        }
        default: {
            status = Q_SUPER(&Mine2::used);
            break;
        }
    }
    return status;
}


} // namespace GAME
