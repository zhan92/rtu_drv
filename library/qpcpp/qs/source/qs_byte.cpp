//////////////////////////////////////////////////////////////////////////////
// Product: QS/C++
// Last Updated for Version: 4.4.00
// Date of the Last Update:  Mar 28, 2012
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
#include "qs_pkg.h"

/// \file
/// \ingroup qs
/// \brief QS::getByte() implementation

QP_BEGIN_

//............................................................................
uint16_t QS::getByte(void) {
    uint16_t ret;
    if (QS_used_ == static_cast<QSCtr>(0)) {
        ret = QS_EOD;                                       // set End-Of-Data
    }
    else {
        ret = static_cast<uint16_t>(QS_PTR_AT_(QS_tail_));   // byte to return
        ++QS_tail_;                                        // advance the tail
        if (QS_tail_ == QS_end_) {                        // tail wrap around?
            QS_tail_ = static_cast<QSCtr>(0);
        }
        --QS_used_;                                      // one less byte used
    }
    return ret;                                      // return the byte or EOD
}

QP_END_

