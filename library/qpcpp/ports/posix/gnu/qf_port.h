//////////////////////////////////////////////////////////////////////////////
// Product: QF/C++  port to POSIX/P-threads, GNU compiler
// Last Updated for Version: 4.5.02
// Date of the Last Update:  Aug 13, 2012
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
#ifndef qf_port_h
#define qf_port_h
                                         // Linux event queue and thread types
#define QF_EQUEUE_TYPE              QEQueue
#define QF_OS_OBJECT_TYPE           pthread_cond_t
#define QF_THREAD_TYPE              uint8_t

                    // The maximum number of active objects in the application
#define QF_MAX_ACTIVE               63
                       // The maximum number of event pools in the application
#define QF_MAX_EPOOL                8
                        // various QF object sizes configuration for this port
#define QF_EVENT_SIZ_SIZE           4
#define QF_EQUEUE_CTR_SIZE          4
#define QF_MPOOL_SIZ_SIZE           4
#define QF_MPOOL_CTR_SIZE           4
#define QF_TIMEEVT_CTR_SIZE         4

                       // QF critical section entry/exit for Linux, see NOTE01
// QF_CRIT_STAT_TYPE not defined
#define QF_CRIT_ENTRY(dummy)    pthread_mutex_lock(&(QP_ QF_pThreadMutex_))
#define QF_CRIT_EXIT(dummy)     pthread_mutex_unlock(&(QP_ QF_pThreadMutex_))

#include <pthread.h>
#include <errno.h>
#include "qep_port.h"                                              // QEP port
#include "qequeue.h"                                // Linux needs event-queue
#include "qmpool.h"                                 // Linux needs memory-pool
#include "qf.h"                    // QF platform-independent public interface

//////////////////////////////////////////////////////////////////////////////
// interface used only inside QF, but not in applications
//
#ifdef qf_pkg_h
                                           // native QF event queue operations
    #define QACTIVE_EQUEUE_WAIT_(me_) \
        while ((me_)->m_eQueue.m_frontEvt == static_cast<QEvt const *>(0)) \
            pthread_cond_wait(&(me_)->m_osObject, &QF_pThreadMutex_)

    #define QACTIVE_EQUEUE_SIGNAL_(me_) \
        pthread_cond_signal(&(me_)->m_osObject) \

    #define QACTIVE_EQUEUE_ONEMPTY_(me_) ((void)0)

                                            // native QF event pool operations
    #define QF_EPOOL_TYPE_            QMPool
    #define QF_EPOOL_INIT_(p_, poolSto_, poolSize_, evtSize_) \
        (p_).init(poolSto_, poolSize_, evtSize_)
    #define QF_EPOOL_EVENT_SIZE_(p_)  ((p_).getBlockSize())
    #define QF_EPOOL_GET_(p_, e_)     ((e_) = static_cast<QEvt *>((p_).get()))
    #define QF_EPOOL_PUT_(p_, e_)     ((p_).put(e_))

#endif

QP_BEGIN_

void QF_setTickRate(uint32_t ticksPerSec);              // set clock tick rate
void QF_onClockTick(void);        // clock tick callback (provided in the app)

extern pthread_mutex_t QF_pThreadMutex_;      // mutex for QF critical section

QP_END_

// NOTES: ////////////////////////////////////////////////////////////////////
//
// NOTE01:
// QF, like all real-time frameworks, needs to execute certain sections of
// code indivisibly to avoid data corruption. The most straightforward way of
// protecting such critical sections of code is disabling and enabling
// interrupts, which Linux does not allow.
//
// This QF port uses therefore a single package-scope p-thread mutex
// QF_pThreadMutex_ to protect all critical sections. The mutex is locked upon
// the entry to each critical sectioni and unlocked upon exit.
//
// Using the single mutex for all crtical section guarantees that only one
// thread at a time can execute inside a critical section. This prevents race
// conditions and data corruption.
//
// Please note, however, that the mutex implementation of a critical section
// behaves differently than the standard interrupt locking. A common mutex
// ensures that only one thread at a time can execute a critical section, but
// it does not guarantee that a context switch cannot occur within the
// critical section. In fact, such context switches probably will happen, but
// they should not cause concurrency hazards because the mutex eliminates all
// race conditionis.
//
// Unlinke simply disabling and enabling interrupts, the mutex approach is
// also subject to priority inversions. However, the p-thread mutex
// implementation, such as Linux p-threads, should support the priority-
// inheritance protocol.
//

#endif                                                            // qf_port_h
