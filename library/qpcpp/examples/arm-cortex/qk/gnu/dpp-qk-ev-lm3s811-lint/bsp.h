//////////////////////////////////////////////////////////////////////////////
// Product: DPP example, Board Support Package
// Last Updated for Version: 4.5.02
// Date of the Last Update:  Aug 09, 2012
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
#ifndef bsp_h
#define bsp_h
                                                // System clock tick rate [Hz]
namespace DPP {

uint32_t const BSP_TICKS_PER_SEC = static_cast<uint32_t>(50);
uint32_t const BSP_SCREEN_WIDTH  = static_cast<uint32_t>(96);
uint32_t const BSP_SCREEN_HEIGHT = static_cast<uint32_t>(16);

void BSP_init(void);
void BSP_displayPaused(uint8_t const paused);
void BSP_displayPhilStat(uint8_t const n, char_t const *stat);
void BSP_terminate(int16_t const result);

void BSP_randomSeed(uint32_t const seed);                       // random seed
uint32_t BSP_random(void);                          // pseudo-random generator

}                                                             // namespace DPP

#endif                                                                // bsp_h


