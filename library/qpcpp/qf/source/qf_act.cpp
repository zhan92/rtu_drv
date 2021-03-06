//////////////////////////////////////////////////////////////////////////////
// Product: QF/C++
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
#include "qf_pkg.h"
#include "qassert.h"

/// \file
/// \ingroup qf
/// \brief QF::active_[], QF::getVersion(), and QF::add_()/QF::remove_()
/// implementation.

QP_BEGIN_

Q_DEFINE_THIS_MODULE("qf_act")

// public objects ------------------------------------------------------------
QActive *QF::active_[QF_MAX_ACTIVE + 1];        // to be used by QF ports only
uint8_t QF_intLockNest_;                       // interrupt-lock nesting level

//............................................................................
char_t const Q_ROM * Q_ROM_VAR QF::getVersion(void) {
    uint8_t const u8_zero = static_cast<uint8_t>('0');
    static char_t const Q_ROM Q_ROM_VAR version[] = {
        static_cast<char_t>(((QP_VERSION >> 12) & 0xFU) + u8_zero),
        static_cast<char_t>('.'),
        static_cast<char_t>(((QP_VERSION >>  8) & 0xFU) + u8_zero),
        static_cast<char_t>('.'),
        static_cast<char_t>(((QP_VERSION >>  4) & 0xFU) + u8_zero),
        static_cast<char_t>((QP_VERSION         & 0xFU) + u8_zero),
        static_cast<char_t>('\0')
    };
    return version;
}
//............................................................................
void QF::add_(QActive * const a) {
    uint8_t p = a->m_prio;

    Q_REQUIRE((u8_0 < p) && (p <= static_cast<uint8_t>(QF_MAX_ACTIVE))
              && (active_[p] == static_cast<QActive *>(0)));

    QF_CRIT_STAT_
    QF_CRIT_ENTRY_();

    active_[p] = a;            // registger the active object at this priority

    QS_BEGIN_NOCRIT_(QS_QF_ACTIVE_ADD, QS::aoObj_, a)
        QS_TIME_();                                               // timestamp
        QS_OBJ_(a);                                       // the active object
        QS_U8_(p);                        // the priority of the active object
    QS_END_NOCRIT_()

    QF_CRIT_EXIT_();
}
//............................................................................
void QF::remove_(QActive const * const a) {
    uint8_t p = a->m_prio;

    Q_REQUIRE((u8_0 < p) && (p <= static_cast<uint8_t>(QF_MAX_ACTIVE))
              && (active_[p] == a));

    QF_CRIT_STAT_
    QF_CRIT_ENTRY_();

    active_[p] = static_cast<QActive *>(0);      // free-up the priority level

    QS_BEGIN_NOCRIT_(QS_QF_ACTIVE_REMOVE, QS::aoObj_, a)
        QS_TIME_();                                               // timestamp
        QS_OBJ_(a);                                       // the active object
        QS_U8_(p);                        // the priority of the active object
    QS_END_NOCRIT_()

    QF_CRIT_EXIT_();
}

QP_END_

