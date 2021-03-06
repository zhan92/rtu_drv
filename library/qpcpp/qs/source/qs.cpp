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
/// \brief QS internal variables definitions and core QS functions
/// implementations.

QP_BEGIN_

//............................................................................
uint8_t QS::glbFilter_[32];                                // global QS filter

//............................................................................
uint8_t *QS_ring_;                  // pointer to the start of the ring buffer
QSCtr QS_end_;                         // offset of the end of the ring buffer
QSCtr QS_head_;                  // offset to where next byte will be inserted
QSCtr QS_tail_;                 // offset of where next byte will be extracted
QSCtr QS_used_;                // number of bytes currently in the ring buffer
uint8_t QS_seq_;                                 // the record sequence number
uint8_t QS_chksum_;                      // the checksum of the current record
uint8_t QS_full_;                       // the ring buffer is temporarily full

//............................................................................
char_t const Q_ROM * Q_ROM_VAR QS::getVersion(void) {
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
void QS::initBuf(uint8_t sto[], uint32_t const stoSize) {
    QS_ring_ = &sto[0];
    QS_end_  = static_cast<QSCtr>(stoSize);
}
//............................................................................
void QS::filterOn(uint8_t const rec) {
    if (rec == QS_ALL_RECORDS) {
        uint8_t i;
        for (i = static_cast<uint8_t>(0);
             i < static_cast<uint8_t>(sizeof(glbFilter_));
             ++i)
        {
            glbFilter_[i] = static_cast<uint8_t>(0xFF);
        }
    }
    else {
        glbFilter_[rec >> 3] |=
            static_cast<uint8_t>(1U << (rec & static_cast<uint8_t>(0x07)));
    }
}
//............................................................................
void QS::filterOff(uint8_t const rec) {
    if (rec == QS_ALL_RECORDS) {
        uint8_t i;
        for (i = static_cast<uint8_t>(0);
            i < static_cast<uint8_t>(sizeof(glbFilter_));
            ++i)
        {
            glbFilter_[i] = static_cast<uint8_t>(0);
        }
    }
    else {
        glbFilter_[rec >> 3] &= static_cast<uint8_t>(
           ~static_cast<uint8_t>((1U << (rec & static_cast<uint8_t>(0x07)))));
    }
}
//............................................................................
void QS::begin(uint8_t const rec) {
    QS_chksum_ = static_cast<uint8_t>(0);                // clear the checksum
    ++QS_seq_;                         // always increment the sequence number
    QS_INSERT_ESC_BYTE(QS_seq_)                   // store the sequence number
    QS_INSERT_ESC_BYTE(rec)                             // store the record ID
}
//............................................................................
void QS::end(void) {
    QS_INSERT_CHKSUM_BYTE()
    QS_INSERT_BYTE(QS_FRAME)
    if (QS_used_ > QS_end_) {                    // overrun over the old data?
        QS_tail_ = QS_head_;                 // shift the tail to the old data
        QS_used_ = QS_end_;                        // the whole buffer is used
    }
}
//............................................................................
void QS::u8(uint8_t const format, uint8_t const d) {
    QS_INSERT_ESC_BYTE(format)
    QS_INSERT_ESC_BYTE(d)
}
//............................................................................
void QS::u16(uint8_t const format, uint16_t d) {
    QS_INSERT_ESC_BYTE(format)
    QS_INSERT_ESC_BYTE(static_cast<uint8_t>(d))
    d >>= 8;
    QS_INSERT_ESC_BYTE(static_cast<uint8_t>(d))
}
//............................................................................
void QS::u32(uint8_t const format, uint32_t d) {
    QS_INSERT_ESC_BYTE(format)
    QS_INSERT_ESC_BYTE(static_cast<uint8_t>(d))
    d >>= 8;
    QS_INSERT_ESC_BYTE(static_cast<uint8_t>(d))
    d >>= 8;
    QS_INSERT_ESC_BYTE(static_cast<uint8_t>(d))
    d >>= 8;
    QS_INSERT_ESC_BYTE(static_cast<uint8_t>(d))
}

QP_END_
