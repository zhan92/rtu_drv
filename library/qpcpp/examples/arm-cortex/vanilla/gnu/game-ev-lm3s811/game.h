//////////////////////////////////////////////////////////////////////////////
// Product: Product: "Fly'n'Shoot" game
// Last Updated for Version: 4.5.00
// Date of the Last Update:  May 20, 2012
//
//                    Q u a n t u m     L e a P s
//                    ---------------------------
//                    innovating embedded systems
//
// Copyright (C) 2002-2012 Quantum Leaps, LLC. All rights reserved.
//
// This program is open source software: you can redistribute it and/or
// modify it under the terms of the GNU General Public License as published
// by the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// Alternatively, this program may be distributed and modified under the
// terms of Quantum Leaps commercial licenses, which expressly supersede
// the GNU General Public License and are specifically designed for
// licensees interested in retaining the proprietary status of their code.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <http://www.gnu.org/licenses/>.
//
// Contact information:
// Quantum Leaps Web sites: http://www.quantum-leaps.com
//                          http://www.state-machine.com
// e-mail:                  info@quantum-leaps.com
//////////////////////////////////////////////////////////////////////////////
#ifndef game_h
#define game_h

using namespace QP;

enum GameSignals {                                 // signals used in the game
    TIME_TICK_SIG = Q_USER_SIG,                     // published from tick ISR
    PLAYER_TRIGGER_SIG,    // published by Player (ISR) to trigger the Missile
    PLAYER_QUIT_SIG,             // published by Player (ISR) to quit the game
    GAME_OVER_SIG,             // published by Ship when it finishes exploding

    // insert other published signals here ...
    MAX_PUB_SIG,                                  // the last published signal

    PLAYER_SHIP_MOVE_SIG,     // posted by Player (ISR) to the Ship to move it


    BLINK_TIMEOUT_SIG,              // signal for Tunnel's blink timeout event
    SCREEN_TIMEOUT_SIG,            // signal for Tunnel's screen timeout event

    TAKE_OFF_SIG,       // from Tunnel to Ship to grant permission to take off
    HIT_WALL_SIG,               // from Tunnel to Ship when Ship hits the wall
    HIT_MINE_SIG,        // from Mine to Ship or Missile when it hits the mine
    SHIP_IMG_SIG,        // from Ship to the Tunnel to draw and check for hits
    MISSILE_IMG_SIG,     // from Missile the Tunnel to draw and check for hits
    MINE_IMG_SIG,               // sent by Mine to the Tunnel to draw the mine
    MISSILE_FIRE_SIG,                   // sent by Ship to the Missile to fire
    DESTROYED_MINE_SIG,    // from Missile to Ship when Missile destroyed Mine
    EXPLOSION_SIG,        // from any exploding object to render the explosion
    MINE_PLANT_SIG,                     // from Tunnel to the Mine to plant it
    MINE_DISABLED_SIG,         // from Mine to Tunnel when it becomes disabled
    MINE_RECYCLE_SIG,            // sent by Tunnel to Mine to recycle the mine
    SCORE_SIG,      // from Ship to Tunnel to adjust game level based on score

    MAX_SIG                              // the last signal (keep always last)
};

struct ObjectPosEvt : public QEvt {          // derive from the QEvt class
    uint8_t x;                                 // the x-position of the object
    uint8_t y;                                 // new y-position of the object
};

struct ObjectImageEvt : public QEvt {        // derive from the QEvt class
    uint8_t x;                                 // the x-position of the object
    int8_t  y;                                 // the y-position of the object
    uint8_t bmp;                      // the bitmap ID representing the object
};

struct MineEvt : public QEvt {               // derive from the QEvt class
    uint8_t id;                                          // the ID of the Mine
    MineEvt(QSignal sig, uint8_t id) {
        this->sig     = sig;
        this->poolId_ = 0;
        this->id      = id;
    }
};

struct ScoreEvt : public QEvt {              // derive from the QEvt class
    uint16_t score;                                       // the current score
    ScoreEvt(QSignal sig, uint16_t score) {
        this->sig     = sig;
        this->poolId_ = 0;
        this->score   = score;
    }
};

#define GAME_SCREEN_WIDTH          BSP_SCREEN_WIDTH
#define GAME_SCREEN_HEIGHT         BSP_SCREEN_HEIGHT
#define GAME_MINES_MAX             5
#define GAME_MINES_DIST_MIN        10
#define GAME_SPEED_X               1
#define GAME_MISSILE_SPEED_X       2
#define GAME_SHIP_X                10
#define GAME_SHIP_Y                (GAME_SCREEN_HEIGHT / 2)

enum GameBitmapIds {
    PRESS_BUTTON_BMP,
    SHIP_BMP,
    MISSILE_BMP,
    MINE1_BMP,
    MINE2_BMP,
    MINE2_MISSILE_BMP,
    EXPLOSION0_BMP,
    EXPLOSION1_BMP,
    EXPLOSION2_BMP,
    EXPLOSION3_BMP,
    MAX_BMP
};

// opaque pointers to active objects in the application
extern QActive * const AO_Tunnel;
extern QActive * const AO_Ship;
extern QActive * const AO_Missile;

uint8_t do_bitmaps_overlap(uint8_t bmp_id1, uint8_t x1, uint8_t y1,
                           uint8_t bmp_id2, uint8_t x2, uint8_t y2);

// obtain instances of the Mines orthogonal components
QHsm *Mine1_getInst(uint8_t id);
QHsm *Mine2_getInst(uint8_t id);

#endif                                                               // game_h
