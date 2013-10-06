//////////////////////////////////////////////////////////////////////////////
// Product: QEP/C++  port to uC/OS-II/80x86, Open Watcom compiler
// Last Updated for Version: 4.5.02
// Date of the Last Update:  Aug 15, 2012
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
#ifndef qep_port_h
#define qep_port_h

#include "ucos_ii.h"                                  // uC/OS-II include file

                          // Exact-width integer types, as defined in uC/OS-II
typedef INT8S    int8_t;
typedef INT16S   int16_t;
typedef INT32S   int32_t;
typedef INT8U    uint8_t;
typedef INT16U   uint16_t;
typedef INT32U   uint32_t;

#include "qep.h"                  // QEP platform-independent public interface

#endif                                                           // qep_port_h
