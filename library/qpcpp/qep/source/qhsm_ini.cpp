//////////////////////////////////////////////////////////////////////////////
// Product: QEP/C++
// Last Updated for Version: 4.5.00
// Date of the Last Update:  May 19, 2012
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
#include "qep_pkg.h"
#include "qassert.h"

/// \file
/// \ingroup qep
/// \brief QHsm::init() implementation.

QP_BEGIN_

Q_DEFINE_THIS_MODULE("qhsm_ini")

//............................................................................
QHsm::~QHsm() {
}
//............................................................................
void QHsm::init(QEvt const * const e) {
    QStateHandler t = m_state;

    Q_REQUIRE((m_temp != Q_STATE_CAST(0))             // ctor must be executed
              && (t == Q_STATE_CAST(&QHsm::top)));  // initial tran. NOT taken

                              // the top-most initial transition must be taken
    Q_ALLEGE((*m_temp)(this, e) == Q_RET_TRAN);

    QS_CRIT_STAT_
    do {                                           // drill into the target...
        QStateHandler path[QEP_MAX_NEST_DEPTH_];
        int8_t ip = s8_0;                       // transition entry path index

        QS_BEGIN_(QS_QEP_STATE_INIT, QS::smObj_, this)
            QS_OBJ_(this);                        // this state machine object
            QS_FUN_(t);                                    // the source state
            QS_FUN_(m_temp);           // the target of the initial transition
        QS_END_()

        path[0] = m_temp;
        (void)QEP_TRIG_(m_temp, QEP_EMPTY_SIG_);
        while (m_temp != t) {
            ++ip;
            path[ip] = m_temp;
            (void)QEP_TRIG_(m_temp, QEP_EMPTY_SIG_);
        }
        m_temp = path[0];
                                               // entry path must not overflow
        Q_ASSERT(ip < QEP_MAX_NEST_DEPTH_);

        do {           // retrace the entry path in reverse (desired) order...
            QEP_ENTER_(path[ip]);                            // enter path[ip]
            --ip;
        } while (ip >= s8_0);

        t = path[0];                   // current state becomes the new source
    } while (QEP_TRIG_(t, Q_INIT_SIG) == Q_RET_TRAN);

    QS_BEGIN_(QS_QEP_INIT_TRAN, QS::smObj_, this)
        QS_TIME_();                                              // time stamp
        QS_OBJ_(this);                            // this state machine object
        QS_FUN_(t);                                    // the new active state
    QS_END_()

    m_state = t;                            // change the current active state
    m_temp  = t;                           // mark the configuration as stable
}

QP_END_

