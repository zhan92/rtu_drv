About QP/C++
============
QP/C++ is an event-driven, RTOS-like, active object framework for
microcontrollers.

The QP/C++ framework provides thread-safe execution of active objects
(concurrent state machines) and supports both manual and automatic coding
of UML statecharts in readable, production-quality ANSI-C. Automatic code
generation for QP/C++ applications, compliant with the MISRA-C:2004
guidelines, is provided by the free QM modeling tool.

The QP/C++ framework can run on "bare-metal" completely replacing a 
traditional RTOS. Ports and ready-to-use examples are provided for:
Cortex-M0/M0+/M1/M3/M4/M4F, RX600, MSP430, C28x, C55x, AVR, ARM7/9,
ColdFire, PIC24, dsPIC, M16C/R8C, H8, HC08, 8051, as well as
Arduino, Raspberry PI, and mbed.

QP/C++ can also work with a traditional (RT)OS, e.g., POSIX (Linux, QNX),
Windows, VxWorks, ThreadX, uC/OS, FreeRTOS.

All versions of QP are described in detail in the book "Practical UML
Statecharts in C/C++, 2nd Edition: Event-Driven Programming for Embedded
Systems" published by Newnes in 2008 (see www.state-machine.com/psicc2).
QP has a strong user community and has been applied worldwide by some of
the largest companies in their respective industries, such as: consumer
electronics, telecommunications equipment, industrial automation,
transportation systems, medical devices, and many more. Please refer to
the www.state-machine.com website for more information.


Download Instructions
=====================
The Generally Available release of QP/C contains the baseline code
(independent on any particular processor or compiler), extensive "QP/C
Reference Manual" in CHM and HTML, and a full Tutorial that explains
step-by-step how to develop a non-trivial real-time application with QP.
 
Out of the box, the Generally Available release of QP/C contains ports
and examples for ARM Cortex-M3 and M4F as well as ports and examples for
desktop systems (Windows, Linux/POSIX), which you can run without any
embedded targets.

The Makefiles and project files provided in the examples\ directory assume
that the environment variable QPCPP is defined and it points to the location
of the QP/C++ framework. For example, assuming that you have installed QP/C++
into the directory C:\qp\qpcpp, you should define the environment variable
QPCPP to C:\qp\qpcpp.

Additionally, the provided Makefiles for win32\mingw (Windows with MinGW
GNU-based compiler) assume that the MinGW toolset is available. The MinGW
toolset is now available in the Qtools collection for Windows, which should
be unzipped to your disk and added to the PATH. For example, assuming that
you have the Qtools collection into the C:\tools\qtools\ directory, please
make sure that your PATH contains C:\tools\qtools\bin.


Editing the Environment Variables on Windows
--------------------------------------------
Open the Windows Explorer and right-click on the Computer icon. Then select
Properties from the pop-up menu. This opens a window with the basic
information about your computer. In the left panel of this window, click
on "Advanced system settings". This opens the dialog "System Properties".
Click the "Environment Variables..." button.

To add a new environment variable, click the "New..." button in the System
Variables section and provide the variable name (e.g., QPCPP) and value
(e.g., C:\qp\qpcpp).

To modify the Path variable, look in the bottom panel "System Variables"
and scroll down to find the variable Path. Click on it and then press
"Edit..." button. Click on the Variable value edit field. At the end of
the string append ;C:\tools\qtools\bin (assuming that you have installed
the Qtools collection in C:\tools\qtools). Make sure that there is a
semicolon ';' between the last entry and the added path.


Editing the Environment Variables on Linux
------------------------------------------
You need to edit the ~/.bash_profile file to add the following line:

export QPCPP=~/qpcpp
export QTOOLS=~/qtools

assuming that you have installed QP/C++ into ~/qpcpp and Qtools
into ~/qtools.


Editing the Environment Variables on Mac OS X
---------------------------------------------
You need to edit the ~/.profile file to add the following line:

export QPCPP=~/qpcpp
export QTOOLS=~/qtools

assuming that you have installed QP/C++ into ~/qpcpp and Qtools
into ~/qtools.

****
NOTE: After updating envrinment variables, you should log off your account
and then log on again so that all applications can pick up the changes.
****


QP/C++ Development Kits (QDKs)
==============================
The QP/C++ baseline code usually needs to be adapted to various operating
systems, microprocessors, and compilers. Adapting the QP software is called
porting and QP has been designed from ground up to make the porting easy. 

A large and steadily growing number of QP/C++ Development Kits (QDKs) for
popular processors (such as ARM7/ARM9, Atmel AVR, TI MSP430, TI TMS320C28x,
TMS320C55x, Renesas RX600, M16C/R8C, Renesas H8/300, FreeScale ColdFire,
80251) and operating systems  (such as Linux/BSD, Windows/WinCE, VxWorks,
ThreadX, FreeRTOS.org, uC/OS-II, eCos) are available for download from: 

http://www.state-machine.com/downloads/

Please keep checking this website, as new QDKs are added frequently.

All QDKs are designed to "plug-into" the directory structure
already established after the installation of the QP/C baseline
code. In other words, you need to install the QP baseline code,
before you install any QDK. 


Licensing QP/C++
================
The QP/C++ software may be distributed and modified under the terms of the
GNU General Public License as published by the Free Software Foundation,
either version 2 of the License, or (at your option) any later version.
 
Alternatively, the QP software may be distributed and modified under the
terms of Quantum Leaps, LLC commercial licenses, which expressly supersede
the GPL and are specifically designed for licensees interested in retaining
the proprietary status of their code.

This software is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
for more details.

You should have received a copy of the GNU General Public License along
with this program (see file GPLv2.txt). If not, see:

http://www.gnu.org/licenses/


Licensing QM
------------
The QM graphical modeling tool is free to download and use,
but is not open source. The QM tool is provided under the terms
of a simple End-User License Agreement (EULA).


Contact information:
--------------------
Quantum Leaps Websites: http://www.state-machine.com
                        http://www.quantum-leaps.com
e-mail:                 info@quantum-leaps.com
toll-free:              1-866-450-LEAP (US Eastern Standard Time)


=================================================================

QP/C++ Revision History
=======================

QP/C++ Version 4.5.04 (10-Feb-2013)
-----------------------------------
The main purpose of this release is adding support for the ARM Cortex-M4F
processors with the hardware Floating-Point Unit (FPU). The QP/C ports
to Cortex-M4F take full advantage of the "lazy stacking" feature of the
FPU registers, and by doing so offer the most efficient preemptive
multitasking on this processor.

Changes in detail:

1. Added ports and examples for ARM Cortex-M4F with the EK-LM4F120XL
board (Stellaris Launchpad).

2. Added the macro QF_LOG2(), which can be re-implemented in the QP ports,
if the CPU supports special instructions, such as CLZ (count leading zeros
in Cortex-M3/M4). If the macro is not defined in the QP port, the default
implementation uses a lookup table.

3. Updated all ARM Cortex-M ports and examples to the latest IAR EWARM
6.50 and Sourcery CodeBench 2012.09-85.

4. Updated App Notes "QP and ARM Cortex-M with IAR" and "QP and ARM
Cortex-M with GNU".

5. Updated the PC-Lint support files (include\lib-qpcpp.lnt, au-misra2.lnt)
to the latest PC-Lint 9.00j.

6. Updated the Application Note: "QP/C++ MISRA-C:2004 Compliance Matrix".

7. Spell-checked the comments in all QP/C++ source files and removed
several typos.

8. Removed the Qt ports and examples from the QP/C++ Baseline Code and
moved them to the separate QDK/C++-Qt.

***
NOTE: QP/C++ Version 4.5.04 preserves full compatibility with QM 2.2.03
and all existing QDKs for QP/C++ 4.5.xx.
***


QP/C++ Version 4.5.03 (29-Nov-2012)
---------------------------------
This release changes the directory structure of QP ports to various
operating systems, such as POSIX (Linux, BSD, etc.), Win32 (Windows),
Qt, etc. The OS ports are moved from the ports\80x86\ directory one
level up to ports\. Also, the OS examples are moved from the
exampels\80x86\ directory one level up to examples\.


QP/C++ Version 4.5.02 (15-Aug-2012)
-----------------------------------
The main purpose of this release is providing QM models in most
examples and better, more comprehensive support for (rapid)
prototyping of embedded QP applications on the desktop with the
Win32 API and with Qt. Among others, this release adds a complete
toolkit for creating realistic embedded front panels with pure
Win32-GUI API and free Visual C++ Express and ResEdit. An extensive
Application Note "QP and Win32" is included in this release.

This QP relase adds QM models, created with the new QM 2.2.01,
to most of the examples. The code generated by this new QM version
complies with MISRA-C++:2008 rules. For this compliance, the QM code
generator applies the QP:: namespace prefix to all QP/C++ elements,
such as classes, types, enumerations, etc.

For compliance with MISRA-C++:2008 and compatibility with QM, all
QP/C++ ports in this release use the QP:: namespace. The namespace
generation can be suppressed by providing the new configuration
macro Q_NNAMESPACE, but this is generally *not* recommended, because
it breaks compatiblity with the QM code generation. (In other words,
a QP/C++ port without namespace cannot use the code generated by QM.)

This release simplifies the QP ports to desktop OSs, such as
Windows (Win32), Linux, BSD, Mac OSX (POSIX) and combines 32-bit
and 64-bit ports in one with conditional compilation.

This release also enhances the option for using constructors for
dynamically allocated events. When the configuration macro
Q_EVT_CTOR is defined, the QEvt class provides a non-default
constructor and the Q_NEW() macro becomes variadic and
takes the arguments for the event constructor. This generally
allows creating dynamic events "on-the-fly" without a temporary
pointer to the event. This QP configuration is demonstrated only
in the QP port to Qt, but can be used in any other port.
NOTE: The event constructor feature is NOT backward-compatible
with the existing applications.

At the same time, the QEvt class in this release provides the virtual
destructor only when the new macro Q_EVT_VIRTUAL is defined. This
separation of QEvt constructor from virtual destructor makes the
constructor more attractive, because it saves the virtual pointer
in every event, if no virtual functions are used in QEvt subclasses
(which seems to be generally the case).

This release also adds a new macro QF_MPOOL_EL, which is intended
for allocating properly aligned storage for memory pools and event
pools.

Finally, all QP ports included in this release use only a single QP
library, rather than separate libraries for QEP, QF, QK, and QS.


Changes in detail:

1. Modified QP port to Win32 and used the free Visual C++ Express
2010 with Platform SDK rather than Visual C++ Pro 2008. Renamed
the port directory from vc2008\ to vc\. Provided a completely
revised App Note "QP and Win32".

2. Eliminated QP port to Win32 with one thread (Win32-1T).

3. Consolidated all QP ports to POSIX OSs (Linux, Linux64, Mac_OSX)
into a single port to POSIX and placed it in the directory posix\.

4. Renamed the port directory qt_1t\ to qt\.

5. Added event constructor to qevt.h (controlled by the configuration
macro Q_EVT_CTOR).

6. Added the conditional compilation with the macro Q_EVT_VIRTUAL
around the virtual destructor in the QEvt class. 

7. Added macro QF_MPOOL_EL to qmpool.h. Modified all examples to
demonstrate the use of this macro to allocate properly aligned
storage for event pools.

8. Added new typedef 'enum_t' and modified signatures of functions
taking event signals from QSignal to enum_t. This was done to
significantly reduce the number of casts necessary when enumerated
signals were passed to QP functions.

9. Modified all QP ports distributed in the QP/C++ baseline code
to generate only a single QP library, rather than separate
libraries for QEP, QF, QK, and QS. This includes all QP ports
to the desktop (ports\80x86\ directory) and ARM Cortex-M ports
(ports\arm-cortex\ directory).

10. Modified all examples to link only one QP library.

11. Added QM models to most examples and used the automatically
generated code from the models instead of the hand-written code.

12. Modified Qt ports to use the event constructors and
modified examples for Qt to demonstrate this feature.

13. Added .ui files to the Qt examples for generating UIs
graphically with the Qt Designer tool. Revised and updated the
App Note "QP and Qt".

14. Added new macro QS_USR_DICTIONARY() to QS for providing symbolic
names for user-defined trace records

15. Added new macro QS_RESET() to QS for telling the QSPY application
when the target resets. This allows QSPY to reset its internal state.


QP/C++ Version 4.5.01 (14-Jun-2012)
-----------------------------------
The main purpose of this minor release is providing improved
MISRA-compliant state machine implementation. Specifically, a new
macro Q_UNHANDLED() has been added for a situation when a guard
condition evaluates to FALSE, but the state model does not prescribe
the explicit [else] case for this guard. In this case, the state
handler can return Q_UNHANDLED(), which will cause the QEP event
processor to propagate the event to the superstate, which is what
UML semantics prescribes.

NOTE: These change to the QEP event processor is completely
backwards-compatible. All state hander functions coded the old
way will continue to handle the guard conditions correctly and
in accordance with the UML specification. The new Q_UNHANDLED()
macro is necessary only for MISRA-compliant state handler coding,
which will be applied in the upcoming release of the QM modeling
and code generation tool.  

Changes in detail:

1. Added macro Q_UNHANDLED() and return value Q_RET_UNHANDLED in
qep.h.

2. Modified qhsm_dis.cpp to handle the Q_RET_UNHANDLED return value.

3. Updated the QP/C MISRA-C++:2008 compliance matrix to 
include the new MISRA-compliant way of coding guard conditions.

4. Modified qs.h and qs_dummy.h to add new trace record type
QS_QEP_UNHANDLED, which is generated when the state handler returns
Q_RET_UNHANDLED.

5. Modified qs.h and qs_dummy.h to add the User record dictionary
trace record and macro QS_USR_DICTIONARY().
         
NOTE: This new trace record requires the updated QSPY 4.5.01.

6. Corrected qfsm_dis.cpp, which did not generate QS trace records
for entry and exit from non-hierarchical states.

7. Updated the IAR ARM compiler used in the ARM Cortex-M examples
to the latest version IAR EWARM 6.40.

8. Modified the Qt port not to define the QPApp::onClockTick()
slot function, but instead to allow defining this slot function in
the BSP of the application.


QP/C++ Version 4.5.00 (26-May-2012)
-----------------------------------
The main pupose of this relase is to improve host-based development of QP
applications, which is critical for Test-Driven Development (TDD). Among
others, this release provides integration between QP and the popular
Qt GUI framework, which allows developers to easily build host-based
simulations of the embedded systems with the realistic user interfaces.

This realase also simplifies implementing transitions to history, which
is a preparation to providing this feature in the QM modeling tool.

Changes in detail:

1. Renamed the event class from QEvent to QEvt to avoid a name conflict
with the Qt framework. Also, for consistency, renamed the file qevent.h
to qevt.h and the macro Q_EVENT_CAST() to Q_EVT_CAST(). 

NOTE: To minimize impact of this change on the existing QP ports and
applications, the name QEvent is provided as well, but this can be
suppressed by defining the configuration macro Q_NQEVENT in qep_port.h.

2. Changed the design of QF::tick() (file qf_tick.cpp) to better support
calling this function from low-priority tasks (as opposed to interrupts
and highest-priority tasks), which often happens when QP is executed on
the desktop operating systems. In this design only QF::tick() can remove
time events from the active linked list, so no unexpected changes to the
list structure are eliminated 

3. Simplified the QTimeEvt class by removing the m_prev link pointer,
as the new design no longer needs a bi-directional list. These changes
impact the files: qte_*.cpp. 

4. Added return value to QF::run() to allow transfer of the exit
status to the destop operating systems.

NOTE: This modification haves impact on most QP/C++ ports, because
the QF::run() function must now return a int16_t value.

5. Eliminated the m_running member of the QActive class, which
has been used only in the QP ports to "big" OSes such as Linux
or Windows.

6. Added member m_temp to the QHsm and QFsm base classes to prevent
clobbering the current state (the m_state member) during transitons.
This change allows keeping the current state unchanged during the
entire transition chain, which in turn allows easy and generic access
to the state information to store the state history in the exit
actions from states. Additional bonus of this re-design is the 
opportunity of testing for stable state configuration in assertions
added to the qhsm_*.cpp and qfsm_*.cpp files.

7. Added the QHsm::state() and QFsm::state() accessor methods.

8. Modified the "Transition to History" pattern implementation to 
use the simplified technique of obtaining the current state in the
exit action from the superstate rather than all the exit actions from
the substates. Modified the "State-Local Storage" (SLS) pattern as
well, because it was using the transition to history constructs. 

9. Re-designed the implementation of the QSPY host application, so
that it can be convenienty included as part of the QP library.
This allows direct QS tracing output to the screen for QP applications
running on the desktop.

NOTE: This change is part of the Qtools release 4.5.00.  

10. Modified the QP ports to Win32_1t (both the MinGW and VC2008) to
output QS trace data directly to the stdout via the QSPY host-application
interface. Modified the DPP examples for Win32_1T to demonstrate the
direct QS output to the screen.

11. Added QP port to Qt_1t (Qt with one thread) and two example
applications (DPP and PELICAN crossing).

12. Added GNU compiler option -pthread to QP ports for POSIX with
P-threads, including QP ports and examples for Linux and Mac OS X. 


QP/C++ Version 4.4.00 (02-May-2012)
-----------------------------------
The main pupose of this relase is MISRA-C++:2008 compliance, strong-type
checking compliance, update of PC-Lint option files and tests, and
general cleanup.

1. Moved the qp_port.h header file from the port directories to
the qcppp/include/ directory. Also, moved the inclusion of the
QS (Spy) header files (qs_port.h/qs_dummy.h) from qep.h, qf.h,
and qk.h headers to qp_port.h. These structural changes were made
to reduce the number of preprocessor #if nesting levels below 8,
which is the ANSI-C limit. This was done to comply with the MISRA-C
rule 1.1 (all code shall conform to ANSI/ISO C). 

NOTE: This modifications have impact on most QP/C++ ports, because
the qp_port.h header file must be removed from the port.

2. Enabled the QP namespace in most QP/C++ ports (except the DOS ports
with the Open Watcom compiler). This modification was needed for
MISRA-C++:2008 compliance with the rule 7-3-1. 

NOTE: This modifications have impact on most QP/C++ ports, because
all QP elements require now using the QP:: prefix. However, this prefix
can be dropped when the application applies the "using namespace QP"
directive. (The "using" directive deviates from MISRA-C++:2008 rule
7-3-4, so it is not used in the MISRA-compliant examples. However,
a number of QP ports applies the "using" directive for backwards
compatibilty.)  

3. Added the PC-Lint option files std.lnt and lib-qpcpp.lnt to the
qcppp/include/ directory.
 
4. Cleaned the whole QP/C code from lint comments. All PC-Lint options
have been moved to PC-Lint option files.
 
5. Modified QP assertion macro Q_DEFINE_THIS_MODULE() to avoid using
the # operator (MISRA rule 16-3-2). This macro now requires the argument
enclosed in doble quotes "".

NOTE: This modification has impact on some QP/C++ ports. 

6. Added typedefs for char_t, int_t, float32_t, and float64_t to
event.h header file for compliance with MISRA-C++:2008 rules 3-9-2.

7. Added macros Q_STATE_CAST() and Q_EVENT_CAST() to qep.h to
encapsulate deviation from MISRA-C++:2008 rule 5-2-7.

8. Added macro Q_UINT2PTR_CAST() to encapsulate casting unsigned
integers to pointers, which deviates from MISRA-C++:2008 rules 5-2-7
and 5-2-8. This macro has been added for *application-level* code.

9. Updated ARM Cortex-M examples with the latest CMSIS v3.0, which
complies with more MISRA-C:2004 rules.

10. Added DPP examples for MISRA-C++:2008 compliant applications (for
IAR-ARM and GNU-ARM).

11. Updated ARM-Cortex-M3 port with GNU to the latest Sourcery
CodeBench 2011.09-60.

12. Added QP/C++ port to Win32-1t and examples (Windows with 1 thread).
This port is useful for testing embedded QP/C++ applications on windows.

13. Added documentation to QP/C++ distribution in the directory
qpcpp/doc/, with the following Application notes:
"MISRA-C++:2008 Compliance Matrix", "Quantum Leaps Coding Standard",
"QP and ARM Cortex-M, and QP and Windows",  


QP/C++ Version 4.3.00 (03-Nov-2011)
-----------------------------------
1. This release changes the names of critical section macros and
introduces macros for unconditional interrupt disabling/enabling.
This is done to simplify and speed up the built-in Vanilla and QK
kernels, which no longer are dependent on the interrupt locking
policy.

NOTE: The change in handling the critical section in the Vanilla and
QK kernels can break QP ports, which use the "save and restore
interrupt lock" policy, because all such ports must also define
unconditional interrupt disabling and enabling.

2. This release changes the partitioning of the QK scheduler.
Specifically, the QK scheduler is now divided between two functions
QK_schedPrio_() and QK_sched_(), to calculate the highest-priority
task ready to run and to perform scheduling, respectively. The function
QK_schedPrio_() is useful to determine if scheduling is even necessary.

3. Updated all QP ports to comply with the new critical section
names and policies.

4. Modified the ARM Cortex-M port qk_port.s to take advantage of the
new structure of the QK scheduler.

5. Upgraded the examples for ARM Cortex with IAR EWARM to the
latest IAR EWARM version 6.30.

6. Upgraded the examples for ARM Cortex with GNU (CodeSourcery) to the
latest Sourcery CodeBench 2011.07-60.


QP/C++ Version 4.2.04 (24-Sep-2011)
-----------------------------------
The main pupose of this relase is to provide a bug fix for the QK port
to ARM Cortex processors. The bug fix addresses a very rare and
undocumented behavior of late-arrival of an interrupt while entering
the PendSV exception. In this case the PENDSVSET bit in the NVIC-ICSR
register is *not* cleared when finally PendSV is entered, so the
PendSV exception is entered in a *different* state when it is entered
via the late-arrival mechanism versus the normal activation of the
exception through tail-chaining. The consequence of this undocumented
and inconsistent hardware behavior, PendSV could be re-entered again
before the SVCall exception cleans up the stack. The bug fix is
implemented in the qk_port.s file and consists of clearing the
PENDSVSET bit programmatically inside PendSV_Handler.


QP/C++ Version 4.2.02 (08-Sep-2011)
-----------------------------------
1. The main pupose of this relase is to repackage the default QP/C++
distribution to contain the single root directory qpcpp/ in the
archive. That way, unziping the archive will produce only one
directory (qpcpp/), which can be then changed by the user.

2. This release also changes the ARM Cortex QP ports with GNU. The
suffix "_cs" has been added to all QP libraries generated by the
Code Sourcery toolset (now Mentor Sourcery CodeBench). This is to 
distinguish libraries generated by different GNU-toolchains (such
as CodeRed, Attolic, DevKit ARM, etc.) 


QP/C++ Version 4.2.01 (13-Aug-2011)
-----------------------------------
1. Modified file qassert.h to add assertion macros #Q_ASSERT_ID,
#Q_REQUIRE_ID, #Q_ENSURE_ID, #Q_INVARIANT_ID, and #Q_ERROR_ID,
which are better suited for unit testig, because they avoid the
volatility of line numbers for indentifying assertions.

2. Added QP port and examples for Mac OS X on 80x86.


QP/C++ Version 4.2.00 (15-Jul-2011)
-----------------------------------
The goal of this milestone release is to extend the number of event
pools (theoretically up to 255 pools) instead of just three event
pools available up til now. This release adds an option to use
constructors/destructors and virtual functions in subclasses of QEvent.
Also, this release adds an option to wrap the whole QP framework in
the QP namespace to avoid name conflicts with other libraries and to
improve QP compliance with MISRA C++ 2008. This release adds also
several improvements to the QS/QSPY software tracing, such as adding
sender information to event posting so that sequence diagrams could be
easily and automatically reconstructed from tracing data. Also, the
tracing now supports 64-bit targets, such as embedded Linux 64-bit.
Finally, this milestone release migrates the examples to use the
environment variable QPCPP instead of relying on the relative path to
the QP/C++ framework. This allows easier adaptation of the examples for
real projects, which don't really belong to the examples directory.

The changes in detail are:

1. Changed the QEvent base class (file qevent.h). The private member
'dynamic_' has been replaced by two members 'poolId_' and 'refCtr_'.

2. Added conditionally-compiled constructor and virtual destructor
to the QEvent base class (file qevent.h). Also added the inclusion
of the <new> header file for placement new if the constructor/
destructor option is configured.

3. Added new version of the macro #Q_NEW() with variable number of
paramters, which invokes the event constructor (via placement new)
with any parameters requried by the event constructor (file qf.h).

4. Added explicit call to the event destructor in QF::gc() (file
qf_gc.cpp).

5. Added configuration macro QF_MAX_EPOOL (file qf.h) to define the
maximum number of event pools in the QP application (default to 3).
The maximum theoretical number of this macro is 255.

6. Made algorithmic changes in the QF source code related to the change
of storing the event pool-IDs and reference counters inside QEvent.

7. Changed the default signal size (macro Q_SIGNAL_SIZE in the file
qevent.h) from 1 to 2 bytes.

8. Changed the signature of QActive::recall() to return uint8_t instead
of QEvent*, which this could encourage incorrect usage (processing of
the event at the point of recalling it). Now, the function only returns
1 (TRUE) if the event was recalled and 0 (FALSE) if the event was not
recalled.

9. Added the QTimeEvt() constructor and new source file qte_ctr.cpp.
The function returns the counter of a time event, which allows using
a time event for measuring the time. 

10. Added new QF macros #QF_TICK, #QF_PUBLISH, and #QACTIVE_POST in
file qf.h to provide sender of the events for software tracing.  

11. Added new QS macros (files qs.h and qs_dummy.h) for handling 64-bit
integers. 

12. Added the functions QS::u64() and QS::u64_() and new source file
qs_u64.cpp.

13. Added the QS macro #QS_U32_HEX_T for hexadecimal formatting of
integer numbers in the user-defined trace records. 

14. Added the new port linux64 for 64-bit Linux. Also added the
corresponding examples for 64-bit Linux. 

15. Adapted the QSPY host application for 64-bit pointer sizes and
the changed layout of trace records that contain event information
(such as PoolID and RefCtr). Also added the backwards-compatibility
option (-v) for switching the tool to the previous data format.

16. Removed the tools directory from the QPC distribution and moved
the QSPY host application to the QTOOLS distribution, which now also
contains the GNU make tools for Windows. 

17. Modified the make files and project files to use the environment
variable QPCPP instead of relying on the relative path to the QP/C++
framework.

18. Upgraded the examples for ARM Cortex with IAR EWARM to the
latest IAR EWARM 6.20.


QP/C++ Version 4.1.07 (28-Feb-2011)
-----------------------------------
The goal of this release is to improve the ease of experimenting with
QP/C++ on the desktop. This release adds support for Windows (Win32) to
the baseline code. Two most popular compilers for Windows are supported:
Microsoft Visual Studio and MinGW (GNU). The support for Linux has been
improved by including pre-built QP/C++ libraries and improving makefiles
for Eclipse compatibility.

The changes in detail are:

1. Added Win32 port with the Visual C++ 2008 (ports/80x86/win32/vc2008).
This directory contains the Visual Studio solution all_qp.sln for
building all QP/C++ libraries from the IDE. Three build configurations
(Debug, Release, and Spy) are supported.

2. Added Win32 port with the MinGW comiler (ports/80x86/win32/mingw).
This directory contains the Makefile for building all QP/C++ libraries.
Three build configurations (dbg, rel, and spy) are supported.
NOTE: the Makefile assumes that the MinGW/bin directory is added
to the PATH.

3. Added Win32 examples for Visual C++ 2008 (examples/80x86/win32/
vc2008/dpp and examples/80x86/win32/vc2008/qhsmtst). Visual Studio
soultions are provides for all build configurations.

4. Added Win32 examples for MinGW (examples/80x86/win32/mingw/dpp
and examples/80x86/win32/mingw/qhsmtst). Eclipse-compatible makefiles
are provided for all build configurations. NOTE: the Makefiles assume
that the MinGW/bin directory is added to the PATH.

5. Removed memory alignment correction in the file qmp_init.c. This
correction required casting of pointers to integers and was problematic
on 64-bit targets (such as 64-bit Linux).

6. Upgraded the examples for ARM Cortex with CodeSourcery to the
latest Sourcery G++ 2011.02-2.


QP/C++ Version 4.1.06 (07-Jan-2011)
-----------------------------------
1. Fixed a bug in the software tracing instrumentation in the function
QF::remove_(), file qf_act.cpp.

2. Made cosmetic improvements to the example QM models of the
"Fly 'n' Shoot" game. 

3. Made improvements in make.bat files for building the examples for
DOS/Open Watcom to run better in DosBox on Linux.

4. Upgraded the examples for ARM Cortex with IAR to the latest
IAR EWARM version 6.10.

5. Upgraded the examples for ARM Cortex with CodeSourcery to the
latest Sourcery G++ 2010.09-66.


QP/C++ Version 4.1.05 (01-Nov-2010)
-----------------------------------
This release is adds examples for the QM (QP Modeler) graphical modeling
and code generation tool. The examples are based on the "Fly 'n' Shoot"
game described in the QP/C++ Tutorial and in Chapter 1 of the PSiCC2 book.

Specifically, the directory <qpcpp>\examples\80x86\dos\watcom\l\game-qm\
contains the "Fly 'n' Shoot" game model file "game.qm". This model, when
opened in the QM tool contains all state machine diagrams and generates
code into the subdirectory qm_code\. This code can then be built and
executed on any 80x86 machine (newer versions of Windows or Linux require
the DOSbox application, see http://www.dosbox.com).

The directory <qpcpp>\examples\arm-cortex\vanilla\iar\game-ev-lm3s811-qm\
contains the version of the game for the EV-LM3S811 ARM Cortex-M3 board.
This directory contains the model file "game.qm", which is actually
identical as the model in the DOS version. The LM3S811 version needs to
be compiled with the IAR compiler and executed on the EV-LM3S811 board.

Additionally, the QP/C++ baseline code has been slighlty modified for
better conformance to the MISRA C++ 2008 rules and the latest PC-Lint 9.x. 


QP/C++ Version 4.1.04 (16-Mar-2010)
-----------------------------------
This release is adds compatibility of all examples for DOS with the
DOSBox
emulator (http://www.dosbox.com/) that recreates a MS-DOS compatible

environment on all versions of Windows, including 64-bit Windows that don't

run 16-bit DOS applications anymore.

Also, this release includes QP ports and
examples for EV-LM3S811 board with
the GNU-based Code Sourcery G++ toolset.
Support for Sourcery G++ provides
a very cost-effective option for developing
QP applications for ARM Cortex
MCUs. 

Finally, this release improves the Cortex
Microcontroller Software Interface
Standard (CMSIS) for the whole family of
the Stellaris LM3Sxxx MCUs. The
improvement extends the CMSIS from Sandstorm
to Fury, DustDevil, and Tempest
Stellaris families.  



QP/C++ Version 4.1.03 (21-Feb-2010)
-----------------------------------
This release is concerned with the ARM Cortex ports and examples. Specifically,
this release contains the following improvements:

1. Unified source code for ARM Cortex-M3 and the new ARM Cortex-M0 cores,
including the code for the preemptive QK kernel.

2. Compliance with the Cortex Microcontroller Software Interface Standard
(CMSIS) in all ARM Cortex examples.

3. Backward-compatible support for the new LM3S811 EVAL Rev C board with
different OLED display than previous revisions. (NOTE: The OSRAM 96x16x1 OLED
used in REV A-B boards has been replaced RITEK 96x16x1 OLED used in Rev C.)

In the process of making the examples CMSIS-compliant, the dependency on the
Luminary Micro driver library (driverlib.a) has been completely removed.

Additionally, the screen saver of the "Fly 'n' Shoot" game has been improved
to periodically switch off the power of the OLED display, which better protects
the display from burn-in. The affected file is tunnel.cpp.

Finally, this release introduces the QP_VERSION macro, which identifies the QP
version. Otherwise, this maintenance release does not change the QP/C++ API in
any way, so the release has NO IMPACT on the QP/C++ applications except for the
ARM Cortex ports and applications.


QP/C++ Version 4.1.02 (14-Jan-2010)
-----------------------------------
The purpose of this minor maintenance release is the change in the directory
structure for the ARM Cortex ports and examples. As new ARM Cortex cores are
becoming available, the old port name "cortex-m3" could be misleading, because
it actually applies to wider range of ARM Cortex cores. Consequently, all ARM
Cortex ports and examples are hosted in the directory tree called
"arm-cortex".

This maintenance release does not change the QP/C++ API in any way, so the
release has NO IMPACT on the QP/C++ applications except for the ARM Cortex
ports and applications. 


QP/C++ Version 4.1.01 (05-Nov-2009)
-----------------------------------
The main purpose of this release is to replace the Turbo C++ 1.01 toolset
with the Open Watcom C/C++ toolset, because Turbo C++ 1.01 is no longer
available for a free download. In contrast, Open Watcom is distributed under
an OSI-certified open source license, which permits free commercial and
non-commercial use. Open Watcom can be downloaded from www.openwatcom.org.

All 80x86/DOS and 80x86/qk ports and examples for Turbo C++ 1.01 have been
replaced with ports and examples for Open Watcom. The make.bat scripts are
provided to build the QP/C++ libraries and examples. 

In the process of converting the examples to Open Watcom two new examples
have been added to the standard QP/C++ distribution. The Calc2 example
located in <qpcpp>\examples\80x86\dos\watcom\l\calc2 shows how to derive
state machine classes with QP 4.x. The SLS example located in
<qpcpp>\examples\80x86\dos\watcom\l\sls shows the implemenation of the
new State-Local Storage state design pattern.


QP/C++ Version 4.1.00 (10-Oct-2009)
-----------------------------------
The release provides brings a number of improvements to QP/C++ and updates
the QP/C++ ARM Cortex-M3 examples for the EK-LM3S811 board to the latest
IAR EWARM 5.40. Due to the acquisition of Liminary Micro by Texas Instruments
the directory IAR structure for the examples and drivers has changed and the
QP examples had to be changed accordingly.

This maintenance release does not change the QP/C++ API in any way, so the
release has NO IMPACT on the QP/C++ applications. 

The main changes in QP v4.1.00 with respect to earlier versions are as
follows:

- in qs.h added a new trace record QS_QEP_DISPATCH logged when an event is
dispatched to a state machine. This timestamped trace record marks the
beginning of an RTC step. The end of the RTC step is marked by the existing
timestamped trace records QS_QEP_INTERN_TRAN, QS_QEP_INIT_TRAN, and
QS_QEP_IGNORED, depending on how the event is handled. The new QS_QEP_DISPATCH
record facilitates measurement of the RTC step lengths.

- in qhsm_dis.cpp added generation of the QS_QEP_DISPATCH trace record.

- in the tools\qspy\ sub-directory added output of the new trace record to the
Q-SPY host application.

- in the tools\qspy\matlab\ sub-directory added processing of the new trace
record to the qspy.m script.

- in qpset.h changed the implementation of the Priority Set. In particular,
the QPSet64 now derives from QPSet8, which enables a common way of testing for
non-empty set (e.g., useful in assembly). Also, the findMax() functions in
QPSet8 and QPSet64 now can work with an empty set, in which case they return
0.

- in qk_sched.cpp simplified the QK_schedule_() function to skip the testing
of the ready-set for non-empty condition. Such test is no longer necessary.
The test can still be performed outside the QK_schedule_() function (e.g., in
assembly) to avoid calling the scheduler if the ready set is empty.

- in qk_ext.cpp simplified the QK_scheduleExt_() function in the same way as
QK_schedule_().

- modified make.bat files for building QP libraries in the ports\ directory
to use the externally defined environment variables for the location of the
toolchains. The defaults are applied only when the environment variable is
not defined. This enables greater flexibility in installing the development
tools in different directories than those chosen by Quantum Leaps.

- modified the ARM Cortex-M3 examples for the new IAR EWARM 5.40.

- modified slighlty the Calculator example to allow extensibility.

- in the ARM Cortex-M3 port file qk_port.s added explicit testing of the
QK_readySet_ set for empty condition. This test allows avoiding calling the QK
scheduler and two contex-switches if the ready-set is empty.

- in the game example moved setting up the QS filters from main.cpp to bsp.cpp.


QP/C++ Version 4.0.04 (09-Apr-2009)
-----------------------------------
The maintenance release introduces the virtual destructor in the QHsm and 
QFsm base classes. This is done to allow proper handling of virtual functions
in the subclasses of QHsm or QFsm. Please note, however, that the change
increases the size of every state machine object by the additional (hidden)
virtual pointer (vptr).

Also, this release provides a fix for the compile-time assertions, which did
not work correctly for the GNU compiler family.

Finally, the ARM Cortex-M3 examples have been recompiled with the newer
IAR EWARM v5.30.  

This maintenance release does not change the QP/C++ API in any way, so the
release has NO IMPACT on the QP/C++ applications. 

The main changes in QP v4.0.04 with respect to earlier version are as follows:

- in qep.h file, virtual destructors have been added to QFsm and QHsm.
- in qassert.h file the #Q_ASSERT_COMPILE macro has been modified to render
a negative array dimension when the asserted condition is not TRUE.


QP/C++ Version 4.0.03 (27-Dec-2008)
-----------------------------------
The main purpose of this release is to fix a bug in the QK preemptive kernel,
which occurs only when the advanced QK features are used. Specifically, the QK
priority-ceiling mutex could interfere with QK thread-local storage (TLS) or
QK extended context switch. When the QK mutex is in use, the TLS or the
extended context for this task could get saved to an incorrect priority level.

The release 4.0.03 fixes the bug by strictly preserving the semantics of
QK_currPrio_ variable. The mutex locking now uses a different variable
QK_ceilingPrio_, which represents the ceiling-priority locked by the mutex.
The QK scheduler and extended scheduler now perform an additional check to
make sure that only tasks with priorities above the ceiling can run. To avoid
that additional overhead, the user can define the macro QK_NO_MUTEX, which
eliminates the QK mutex API and eliminates the additional tests in the QK
schedulers.

This maintenance release does not change the QP/C++ API in any way, so the
release has NO IMPACT on the QP/C++ applications. 

The main changes in QP v4.0.03 with respect to earlier version are as follows:

- in qk.h file, made the QK mutex API only visible when the macro QK_NO_MUTEX
is *not* defined.
- in qk_pkg.h file, added the QK_ceilingPrio_ external declaration when the
macro QK_NO_MUTEX is not defined.
- in qk_mutex.cpp file, changed priority-ceiling mutex implementation to use
the QK_ceilingPrio_ instead of QK_currPrio_. Also, added compiler error when
the macro QK_NO_MUTEX is definedthis and this file is included in the build.
- in qk_sched.cpp file added testing priority against the QK_ceilingPrio_,
when the macro QK_NO_MUTEX is not defined.
- in qk_ext.cpp file added testing priority against the QK_ceilingPrio_,
when the macro QK_NO_MUTEX is not defined.


QP/C++ Version 4.0.02 (15-Nov-2008)
-----------------------------------
This maintenance release does not change the QP/C++ API in any way, so the
release has NO IMPACT on the QP/C++ applications. 

The main changes in QP v4.0.02 with respect to earlier version are as follows:

- in qep.h file, added comments to macros Q_TRAN() and Q_SUPER() to suppress
the PC-lint warining about using the comma-operator (MISRA rule 42).
- in qhsm_in.cpp file, fixed a bug in the QHsm::isIn() function.
- fixed a bug in tunnel.cpp file ("Fly 'n' Shoot" game). The constant event
HIT_WALL was not declared static.


QP/C++ Version 4.0.01 (09-Jun-2008)

-----------------------------------
This maintenace release is made to allow using QS software tracing with
the GNU compiler for AVR (WinAVR). Specifically, the output of the strings
residing in ROM has been fixed.

This maintenance release does not change the QP/C++ API in any way, so the
release has NO IMPACT on the QP/C++ applications.

The main changes in QP v4.0.01 with respect to earlier version are as follows:

- in qs_.cpp file, updated the function QS::str_ROM_().
- in qs_str.cpp file, updated the function QS::str_ROM().
- in qvanilla.cpp file, funciton QF::run(), declared the temporary variables
as static to save stack space, because QF::run() never returns and is not
reentrant.


QP/C++ Version 4.0.00 (07-Apr-2008)


-----------------------------------
This milestone release is made for the book "Practical UML Statecharts in C/C++,
Second Edition" (http://www.quantum-leaps.com/psicc2/). The book describes in
great detail this new release. The older "QP Programmer's Manual" is now
phased out and is replaced with this hyper-linked "QP/C++ Reference Manual"
(http://www.quantum-leaps.com/doxygen/qpcpp/tutorial_page.html),
which provides very detailed, easily searchable reference to the
software. The book "Practical UML Statecharts in C/C++,
Second Edition" provies in-depth discussion of the relevant
concepts as well as the design study of QP v4.0.

The main changes in QP v4.0
with respect to earlier versions are as follows:

- the coding techniques for hierarchical state machines (HSMs)
and the simpler finite state machines (FSMs) have changed. While
the changes are quite simple, the backward compatibility with
QEP 3.x has been broken, meaning that some manual changes to the
state machines implemented with earlier versions are necessary.
Please refer to the "QP/C++ Tutorial" Section "Coding HSMs"
http://www.quantum-leaps.com/doxygen/qpcpp/coding_hsm.html)
for more information about coding state machines with QEP 4.x.

- The main change is the signature of a state-handler function,
which now returns simply a byte. This return type (typedef'ed as
QState) is the status of the event-handling that the state
handler conveys to the QEP event processor.
    - The macro Q_TRAN() must now always follow the return
    statement.
    - The new macro Q_SUPER() designates the
    superstate of the given state. Again, this macro must follow
    the return statement.
    - Then two new macros Q_HANDLED() and
    Q_IGNORED() have been added to return the status of event
    handled and event ignored, respectively.

- all callback functions are now consistently called XXX_onYYY() or
XXX::onYYY():
    - Q_assert_handler() is now Q_onAssert()
    - QF::start() is now QF::onStartup()
    - QF::cleanup() is now QF::onCleanup()

- the new header file qevent.h has been broken off the qep.h header file.
qevent.h contains the QEvent class and other basic facilities used in the
whole QP. This new file allows easier replacement of the entire QEP event
processor with custom event processors, if you wish do so.

- the macro QEP_SIGNAL_SIZE is renamed to Q_SIGNAL_SIZE.

- the data type QSTATE is now deprecated. Please use ::QState.

- the QF_FSM_ACTIVE macro is now deprecated. Instead, please define
QF_ACTIVE_SUPER_ to the base class of ::QActive and QF_ACTIVE_STATE_ to the
data type represented state. By default, these macros are defined to use the
::QHsm base class from the QEP hierarchical event processor, but you can
replace the event processor, if you wish.

- the internal macro QACTIVE_OSOBJECT_WAIT_() is now QACTIVE_EQUEUE_WAIT_().

- the internal macro QACTIVE_OSOBJECT_SIGNAL_() is now
QACTIVE_EQUEUE_SIGNAL_().

- the internal macro QACTIVE_OSOBJECT_ONIDLE_() is now
QACTIVE_EQUEUE_ONEMPTY_().

- the data mebers QActive::m_osObject and QActive::m_thread are now present
only if the macros QF_OS_OBJECT_TYPE and QF_THREAD_TYPE are defined.

- the ::QPSet class has been renamed to ::QPSet64.

- the QPSet::hasElements() has been renamed QPSet64::notEmpty()

- the QS software tracing is now better integrated with all QP components. You
no longer need to explicitly include qs_port.h, because it is automatically
included when you define the macro Q_SPY. Also the file qs_dummy.h is included
automatically when the macro Q_SPY is <STRONG>not</STRONG> defined.

- the new header file qvanilla.h now replaces the file qsched.h.

- the macros QF_SCHED_LOCK() and QF_SCHED_UNLOCK() are now obsolete.

- the native QF event queues (both the active object event queues and the
"raw" thread-safe queues) are slightly more efficient by counting down the
head and tail pointers rather than up. This leads to wrap-around at zero,
which is easier (faster) to test than any other wrap-around point. Also the
native QF event queues maintain the minimum of the free events in the queue
rather the maximum of used events.

- the data member of QEQueue::nTot class is removed.

- the QF::publish() function has been re-written so that QF no does
<STRONG>not need to lock the scheduler</STRONG>. The QF::publish() function
posts events to active objects with scheduler unlocked starting from the
highest-priority active objects. However, the event is protected from
inadvertent recycling by incrementing its reference counter before the publish
operation. After the event  is posted to all subscribers, the garbage
collector QF::gc() is called to decrement the reference counter and recycle
the event, if necessary.

- the qf_run.cpp file is obsolete. The QF::run() function for the cooperative
"vanilla" kernel is now implemented in the file qvanilla.cpp.
 
- the QF::tick() function has been rewritten to allow calling QF::tick() from
the task context as well as from the interrupt context. The nested critical
section around QF::tick() is no longer needed when it is called from the task
level. Among others, this re-design <STRONG>eliminates the need for the
recursive</STRONG> mutex in the POSIX QF port.

- the QMPool::init() function has been re-designed to optimally align the
memory buffer in a portable and platform-independent way. This should bring
some performance improvements on some CPUs (e.g., 80x86).

- the extended QK scheduler has been re-designed to save stack space. The
extended context (e.g., coprocessor registers) are no longer saved on the
precious stack, but rather in the active object.
 
 
- a bug has been fixed in handling of Thread-Local Storage (TLS) in the QK
scheduler and extended scheduler.

- the -q (quiet) flag has been added to the QSPY host application.

- the support for two new compilers for Windows has been added for the QSPY
host application. The application can now be build with the MinGW GNU compiler
for Windows as well as the Microsoft Visual C++ 2005.

- the QP port to Linux has been improved by eliminating the need for recursive
P-Thread mutex.

- the QP port to MicroC/OS-II has been upgraded to the latest version 2.86.

- all examples in the standard QP distribution have been cleaned up and
updated to the latest QP API changes.

- all examples that use QF now contain the QS software tracing support.


-----------------------------------------------------------------
-----------------------------------------------------------------
Version 3.4.01 (Product)
Release date: Sep 25, 2007

This product release adds the backward-compatibility
layer so that previous
QP/C++ ports continue to work with the new version.


This product release also comes with the updated "QP Programmer's Manual", 
which now
includes the QS target component and the QSpy host application.


\section qpcpp_3_4_00
Version 3.4.00 (Beta)
Release date: Sep 03, 2007

This release brings several changes
with the overall goal of simplifying and
improving consistency across the whole
QP family of frameworks (QP/C, QP/C++,
and QP-nano).

The main changes are made to the
QEP component. The "static transition
optimization" has been removed altogether. 
This simplifies significantly the
state machine structure (which now contains just the
currently active state).
Also, the efficiency is improved for processing the dynamic transitions and
the stack usage is lower. This change brings the QEP/C++ implementation
 much
closer to QEP-nano.

The other big change in this release is including the Quantum
Spy (QS)
component in the distribution. Previously, the QS component was available
 only
under the commercial licensing. It is now open source, just as the rest of QP.


In, the QF/C++ component, the QTimerEvt::publishIn() and
QTimeEvt::publishEvery() have been removed, because they introduced
a coupling between time events and publish-
subscribe. This is undesirable for
projects that do not want to include the publish-
subscribe facilty.

Finally, the revision history for individual QP/C++ components has
 been moved
from the header files and is now consolidated in the header file
doxygen/

qpcpp_rev.h.

The updated "QP Programmer's Manual" is in the works...


-----------------------------------------------------------------
Version 3.3.00 (Product)
Release date: Jan 23, 2007

The main change in this release is removing include 
<stdint.h> from the qep.h header file. This has been 
done becasue vast majority of embedded compilers for 
small MCUs actually do not provide the C-99 Standard 
header file <stdint.h>. Worse, compilers such as 
Freescale HC(S)08 C/C++ compiler will not include 
<stdint.h> unless it's in the compilers's include 
directory, even though the "stdint.h" file might be in 
the compiler include path. 
 
Removing the "#include <stdint.h>" from qep.h header 
file allows more flexibility in the way the standard 
exact-width integer types are defined. For compilers 
that do not provide the <stdint.h> file, you provide 
the typedef's in the qep_port.h file before including 
qep.h. For compilers that do provide the <stdint.h> 
header file, you simply include this file in the 
qep_port.h header file before including qep.h. 
 
The changes in release 3.3.00 have impact on all QP 
ports, because you need to modify the qep_port.h file 
in all these ports. 
 
The other significant change in this release is adding 
the macro Q_ROM_VAR for all constant objects allocated 
in ROM. The Q_ROM_VAR macro has been added for the 
compilers like Freescale HC(S)08, which require far 
pointers to access the objects in ROM. Please note 
that specifying the pointer size for accessing a ROM 
objects is syntactically different than specifying 
that the object is allocated in ROM (see macro Q_ROM). 
 
Finally, in release 3.3.00 the build strategy for QP 
ports has been simplified as well. Instead of separate 
Makefile for every QP component, such as QEP, QF, QK, 
and QS, not the "ports" directory contains a batch 
file "make.bat" that builds all the libraries at once. 

1.	in file qep.h removed "#include <stdint.h>". 
2.	in file qassert.h added macro Q_ROM_VAR for 
objects allocated in ROM and to signatures of 
functions accessing these objects. 
3.	in file qep.h added macro Q_ROM_VAR for objects 
allocated in ROM and to signatures of functions 
accessing these objects. 
4.	in file qep.h added default empty definitions 
and Doxygen comments for macros Q_ROM and 
Q_ROM_VAR. 
5.	in file qep.cpp added macro Q_ROM_VAR for 
objects allocated in ROM and to signatures of 
functions accessing these objects. 
6.	in file qf.cpp added macro Q_ROM_VAR for 
objects allocated in ROM and to signatures of 
functions accessing these objects. 
7.	in file qk.cpp added macro Q_ROM_VAR for 
objects allocated in ROM and to signatures of 
functions accessing these objects. 
8.	in file qep.cpp added Q_ROM_VAR to the 
signature of QEP::getVersion(). 
9.	in file qep.cpp changed the version number to 
"3.3.00". 
10.	Updated the "QP Programmer's Manaul" to 
Revision E

-----------------------------------------------------------------
Version 3.2.01 (Product)
Release date: Sep 01, 2006

1.	In file qep.cpp updated version number to 
3.2.01 
2.	Added makefiles for building ports of all 
QP/C++ libraries at once. 
3.	Created the consolidated manual "QP/C++ 
Programmer's Manual".

-----------------------------------------------------------------
Version 3.2.00 (Product)
Release date: Aug 07, 2006

1.	In file qep.h added the default definition of 
Q_ROM in case it's not defined by the user. 
2.	In file qassert.h added the macro Q_ROM to 
allocate constant strings to ROM. 
3.	In file qep.cpp updated version number to 
3.2.00
Updated the "QEP/C++ Programmer's Manual". 

-----------------------------------------------------------------
Version 3.1.03 (Product)
Release date: Feb 10, 2006

1.	In file qep.cpp added the Revision History 
Doxygen comment, which was previously in 
doxygen/qp.h

-----------------------------------------------------------------
Version 3.1.02 (Product)
Release date: Jan 29, 2006

1.	Removed Quantum Spy (QS) dependency from the 
QCalc and QHsmTst examples
Version 3.1.01 (Product)
Release date: Oct 18, 2005
1.	Removed Quantum Spy (QS) dependency from the 
examples

-----------------------------------------------------------------
Version 3.1.00 (Beta3)
Release date: Oct 03, 2005

1.	Applied new directory structure desribed in 
Application Note: QP Directory Structure 
2.	Added Quantum Spy instrumentation. 
3.	Removed file qfsm_tra.cpp. 
4.	Introduced file qfsm_dis.cpp.

-----------------------------------------------------------------
Version 3.0.11 (Beta2)
Release date: Aug 14, 2005

1.	Fixed potential race condition for static 
transitions 
2.	Added assertion in QHsm::execTran() to catch 
potential path[] array overrun that previously 
could go undetected.

-----------------------------------------------------------------
Version 3.0.10 (Beta1)
Release date: Aug 06, 2005

This release contains completely redesigned Quantum 
Event Processor (QEP). The main focus is on compliance 
with standards (MISRA, Lint, Coding Standard), better 
portability, stack-use efficiency. 
1.	This release includes a comprehensive "QEP/C++ 
v3.0 Programmer's Manual" in PDF. 
2.	This release contains in-source comments for 
automatic generation of this Reference Manual 
with doxygen. 
3.	This release includes re-packaging the code 
into much larger numberof modules (.cpp files) 
with typically one function per module. This 
fine-granularity packaging allows for better 
automatic elimination of unused code at link 
time and fine-tuning by applying different 
compiler options to different files. 
4.	Although this is a C++ version, it has been 
still thoroughly checked against the Motor 
Industry Software Reliability Association 
(MISRA) "Guidelines for the Use of the C 
Language in Vehicle Based Software", April 
1998, ISBN 0-9524156-9-0 (see also 
http://www.misra.org.uk). A separate 
Application Note "QEP/C++ MISRA Compliance 
Matrix" contains detailed account how QEP/C++ 
compiles with the 127 MISRA rules (See 
http://www.quantum-
leaps.com/doc/AN_QP_Cpp_MISRA.pdf). 
5.	This release is now "lint-free". The source 
code has been thoroughly checked with the 
latest version of PC-lint(TM) (version 8.00q) 
from Gimpel Software (www.gimpel.com). The PC-
lint configuration files and output files are 
included in the distribution. A separate 
Application Note "QEP/C++ PC-Lint Compliance" 
contains detailed account how QEP/C++ compiles 
with PC-Lint. (See http://www.quantum-
leaps.com/doc/AN_QP_Cpp_PC-Lint.pdf). 
6.	This release is compliant with the "Quantum 
Leaps Coding Standard" (http://www.quantum-
leaps.com/resources/QL_coding_standard.pdf). 
Among others, all public names are prefixed by 
"Q_", or "QEP_" to minimize compile-time and 
link-time name conflicts. In addition, QEP/C++ 
uses the C99 standard include file <stdint.h> 
(C99 Standard, Section 7.18). Pre-standard 
compilers are still supported by placing 
<stdint.h> in the compiler's header file 
directory. 
7.	The QEvent class has been redesigned to use 
memory more efficiently. QEvent takes up only 2 
bytes now. 
8.	The QHsm class now derives from the QFsm class, 
which promotes better code re-use. In 
particular, macros Q_INIT() and Q_TRAN() are 
now common for both traditional non-
hierarchical FSMs and for HSMs. 
9.	The QFsm class has been redesigned to allow 
using entry and exit actions. Now the QFsm 
class strictly avoids recursion, just as QHsm 
does (MISRA rule 70). 
10.	The QPseudoState type has been eliminated 
and replaced by QState. 
11.	The central QHsm class in QEP has been 
completely redesigned. The basic transition 
algorithm is essentially the same as described 
in "PSiCC", however the implementation is very 
different. The redesign was necessary to comply 
with the MISRA rules and to eliminate Lint 
warnings. 
12.	The event processor is now strictly non-
recursive (MISRA rule 70), that is, event 
handlers never call themselves, even 
indirectly. (Previous algorithm required one-
level of indirect recursion.) 
13.	Dynamic state transition is now default. 
Static transition optimization is still 
supported, but considered optional for 
performance tuning. 
14.	The artificial limitation of initial 
transitions targeting only immediate substate 
of a composite state has been removed (see 
"PSiCC" Figure 5.4[a]). Initial transitions can 
now target any substate, arbitrarily nested 
within the composite state. 
15.	This distribution uses the legacy Borland 
Turbo C++ 1.01 as the default compiler. Port to 
DOS with Turbo C++ 1.01 is provided along with 
GNU-compatible makefiles for the QEP library 
and sample applications. This compiler is not 
C99-compliant and does not provide the 
<stdint.h> header file. However, the port of 
QEP includes a minimal <stdint.h>, which should 
be placed into the INCLUDE directory of the 
Borland Turbo C++ 1.01 installation. 
16.	This distribution contains three sample 
applications: A simple time bomb (QBomb) to 
demonstrate use of QFsm, a calculator (QCalc), 
and an exhaustive test of the QHsm class 
(QHsmTst). All examples are implemented as 
text-only application compiled with Turbo C++ 
1.01. The QHsmTst sample application supports 
interactive and batch mode for exhaustive 
testing of the event processor. The source code 
for QHsmTst demonstrates also how QEP/C++ 
application code can be MISRA-compliant. 
17.	This distribution contains make files for 
the Turbo C++ 1.01 make utility, as well as 
GNU-compatible Makefiles. 


QF/C++ Revision History
=======================

Version 3.3.00 (Product)
Release date: Jan 23, 2007

The main change in this release is adding the macro 
Q_ROM_VAR in QEP for all constant objects allocated in 
ROM. The Q_ROM_VAR macro has been added for the 
compilers like Freescale HC(S)08, which require far 
pointers to access the objects in ROM. Please note 
that specifying the pointer size for accessing a ROM 
objects is syntactically different than specifying 
that the object is allocated in ROM (see macro Q_ROM). 
 
The other significant change in release 3.3.00 is 
simplification of the build strategy for QP ports. 
Instead of separate Makefile for every QP component, 
such as QEP, QF, QK, and QS, not the "ports" directory 
contains a batch file "make.bat" that builds all the 
libraries at once. 

1.	in file qf.h added macro Q_ROM_VAR for objects 
allocated in ROM and to signatures of 
functions accessing these objects. 
2.	in file qf.h removed method QF::getTime() and 
deleted external variable QF::tickCtr. 
3.	deleted obsolete file qa_fifo_.cpp 
4.	deleted obsolete file qa_lifo_.cpp 
5.	deleted obsolete file qf_time.cpp 
6.	in file qf_act.cpp added Q_ROM_VAR to the 
signature of QF::getVersion() 
7.	in file qf_log2.cpp added Q_ROM_VAR to the 
definition of the lookup. 
8.	in file qf_pwr2.cpp added Q_ROM_VAR to the 
definition of the lookups. 
9.	in file qf_tick.cpp removed incrementing 
QF::tickCtr. 
10.	In file qf_act.cpp updated version number 
to 3.3.00 
11.	Updated the "QP Programmer's Manaul" to 
Revision E


Version 3.2.05
Release date: Dec 08, 2006

This QF release rolls back the changes made to the 
reference-counting policy. The reference count of a 
dynamic event is incremented when the event is posted, 
but is NOT decremented when the event is retreived 
from the queue. The reference count is decremented 
only later, in the garbage collector (QF::gc()). 
This release adds direct support for event deferral 
(the "Deferred Event" state pattern) through methods 
QActive::defer() and QActive::recall().
1.	In file qf.h added methods QActive::defer() 
and QActive::recall(). 
2.	In file qa_get_.cpp removed decrementing the 
reference count of a dynamic event. 
3.	In file qeq_get.cpp removed decrementing the 
reference count of a dynamic event. 
4.	In file qf_gc.cpp restored decrementing of the 
reference count of a dynamic event. 
5.	Added new file qa_defer.cpp that implements 
QActive::defer() and QActive::recall(). 
6.	In file qf_act.cpp updated version number to 
3.2.05 
7.	Updated the "QP Programmer's Manaul" to 
Revision D


Version 3.2.04
Release date: Dec 01, 2006

This QF release changes the internal policy of 
reference-counting for dynamic events. The reference 
count of a dynamic event is now incremented when the 
event is posted to a queue and decremented when the 
event is later retreived from the queue. This policy 
pertains to both active object queues and native QF 
thread-safe queues (QEQueue).
Previously, the reference count of a dynamic event was 
not decremented upon retreival of the event from the 
event queue, but rather in the garbage collector 
(QF::gc()).
1.	In file qf.h eliminated methods 
QActive::postFIFO_() and QActive::postLIFO_(). 
2.	In file qf.h promoted method QActive::get_() 
to the public scope to make it available to 
various thread-run routines. 
3.	In file qf.h promoted method 
QActive::unsubscribeAll() to the public scope 
to make it available to various thread-run 
routines. 
4.	In file qf.h promoted method QF::remove_() to 
the public scope to make it available to 
various thread-run routines. 
5.	In file qf.h added friendship between class 
QActive and QK_scheduleExt_() and 
QK_isrExit_(). 
6.	In file qa_fifo.cpp changed the implementation 
of QActive::postFIFO() to represent the native 
QF event queue of an active object. 
7.	In file qa_fifo_.cpp removed the 
implementation of QActive::postFIFO_() and 
declared the file obsolete (will be removed in 
future releases). 
8.	In file qa_lifo.cpp changed the implementation 
of QActive::postLIFO() to represent the native 
QF event queue of an active object. 
9.	In file qa_lifo_.cpp removed the 
implementation of QActive::postLIFO_() and 
declared the file obsolete (will be removed in 
future releases). 
10.	In file qa_get_.cpp added decrementing the 
reference count of a dynamic event. 
11.	In file qf_gc.cpp removed decrementing of 
the reference count of a dynamic event. Also 
changed the test for recycling an event 
(reference count of zero). 
12.	In file qf_pspub.cpp removed incrementing 
the reference count of a dynamic event. 
13.	Removed all uses of the macros 
QACTIVE_POST_FIFO_, QACTIVE_POST_LIFO_ and 
QACTIVE_GET_. These macros are made now 
obsolete. 
14.	In file qsched.h removed definitions of the 
obsolete macros QACTIVE_POST_FIFO_, 
QACTIVE_POST_LIFO_, and QACTIVE_GET_. 
15.	In file qf_pspub.cpp replaced the macro 
QACTIVE_POST_FIFO_() with the direct method 
invocation active_[p]->postFIFO(e). 
16.	In file qf_tick.cpp replaced the macro 
QACTIVE_POST_FIFO_() with the direct method 
invocation active_[p]->postFIFO(e). 
17.	In file qa_run.cpp replaced the macro 
QACTIVE_POST_GET_() with the direct method 
invocation get_(). 
18.	Changed the uC/OS-II port to reflect new 
policy of handling reference counters inside 
the dynamic events. Also removed files 
qa_fifo.cpp and qa_lifo.cpp from the uC/OS-II 
build. 
19.	In file qf_act.cpp updated version number 
to 3.2.04 
20.	Updated the "QP Programmer's Manaul" to 
Revision C


Version 3.2.03 (Product)
Release date: Nov 15, 2006

The main purpose of this release is to adapt the code 
to the shortcomings of the gcc compiler for handling 
data in program ROM for Harvard architecture CPUs, 
such as the Atmel's AVR or the 8051. In such machines, 
the data space (RAM) and program space (ROM) are 
accessed with different instructions. The gcc compiler 
does not automatically synthesize the correct code for 
accessing data placed in the program ROM, even though 
__attribute__((__progmem__)) is used. The workaround 
for the gcc is to add special assembly instructions to 
transfer the data from the program space to the data 
space. This version of QP-nano adds macros for each 
data element allocated to the program space (delcared 
with the Q_ROM attribute) Please note that commercial 
compilers, such as IAR, handle data allocated in the 
program space (ROM) correctly and do not need any 
workarounds.

This release also fixes a few minor inconsistencies in 
the code (see the list below):
1.	In file qf.h added default definition of macro 
Q_ROM_BYTE 
2.	In file qf_set.h added macro Q_ROM_BYTE to 
access the lookup tables allocated in ROM 
(several places). 
3.	In file qf_sched.h changed types 
QF_OS_OBJECT_TYPE and QF_THREAD_TYPE to 
uint8_t from int8_t 
4.	In file qs_dummy.h added dummy definitions of 
some missing QS macros 
5.	In file qa_sub.cpp added macro Q_ROM_BYTE to 
access the lookup tables allocated in ROM 
(several places). 
6.	In file qa_usub.cpp added macro Q_ROM_BYTE to 
access the lookup tables allocated in ROM 
(several places). 
7.	In file qf_usuba.cpp added macro Q_ROM_BYTE to 
access the lookup tables allocated in ROM 
(several places). 
8.	In file qf_pspub.cpp added macro Q_ROM_BYTE to 
access the lookup tables allocated in ROM 
(several places). 
9.	In file qf_tick.cpp replaced QF_tickCtr_ with 
QS::tickCtr_. allocated in ROM (several 
places). 
10.	In file qf_act.cpp updated version number 
to 3.2.03
Version 3.2.01 (Product)
Release date: Sep 01, 2006
1.	In file qf_act.cpp updated version number to 
3.2.01 
2.	Added makefiles for building ports of all 
QP/C++ libraries at once. 
3.	Created the consolidated manual "QP/C++ 
Programmer's Manual".
Version 3.2.00 (Product Release)
Release date: Aug 08, 2006
1.	In file qf.h changed the semantics of the 
QF::onIdle() callback. This callback is now 
invoked with interrupts LOCKED from the non-
preemptive scheduler used in the "vanilla" QF 
ports to "bare metal" target boards. 
 
The modification changes the responsibilities 
of QF::onIdle(), which now MUST at least 
unlock interrupts. A failure to unlock 
interrupts in QF::onIdle() will leave the 
interrupts locked all the time and would 
prevent the application from running. 
 
Also, the signature of QF::onIdle() now 
depends on the interrupt locking policy. In 
case of the "save and restore interrupt 
status" policy, the QF::onIdle() callback 
takes the interrupt lock key as parameter (to 
be able to unlock the interrups correctly). 
2.	In file qf.h used the macro Q_ROM to allocate 
constant objects to ROM ( 
See also: 
qep.h). Objects allocated to ROM are: the 
version strings, and the lookup tables 
(QF::log2Lkup[], QF::pwr2Lkup[], 
QF::invPwr2Lkup[], and QF::div8Lkup[].
3.	Added new platform-independent header file 
qsched.h to provide the interface to the 
simple non-preemptive scheduler used in the 
"vanilla" ports of QF to "bare metal" targets. 
This header file is only applicable to the 
"vanilla" ports. 
4.	Added new platform-independent implementation 
file qf_run.cpp to implement the simple non-
preemptive scheduler used in the "vanilla" 
ports of QF to "bare metal" targets. This 
implementation file eliminates the need for 
qf_port.cpp file in the "vanilla" ports of QF. 
Also, the qf_run.cpp module should only be 
placed in the QF library in the vanilla QF 
ports. 
5.	Simplified all "vanilla" ports of QF to use 
the common platform- independent 
implementation provided in qf_run.cpp. 
6.	Updated QF::onIdle() callback in all examples 
of "vanilla" ports of QF to unlock interrupts. 
7.	Updated the "QF/C++ Programmer's Manual".


Version 3.1.06 (Product Release)
Release date: Jul 14, 2006

1.	In file qf.h added function QF_stop() to be 
called from the application code to stop the 
framework. 
2.	In file qf.h added callback function 
QF_cleanup() to be called from the QF port to 
cleanup before exiting to the OS. 
3.	In file qf.h deprecated the function 
QF_exit().


Version 3.1.05 (Product Release)
Release date: Feb 10, 2006

1.	In file qf_act.cpp added the Revision History 
Doxygen comment, which was previously in 
doxygen/qp.h 
2.	In file qf.h augmented comment for QF_run() to 
cover the case when QF is used with QK. 
3.	In file qf.h added the extern declarations of 
QF_tickCtr_, QF_intLockNest, and QF_isrNest_, 
which were previously declared in qf_pkg.h. 
4.	In file qf.h added macros QF_QS_INT_LOCK, 
QF_QS_INT_UNLOCK(), QF_QS_ISR_ENTRY, and 
QF_QS_ISR_EXIT, which were previously declared 
in qs_port.h. 
5.	In file ports/linux/gcc/qf_port.h added extern 
uint8_t QF_running_. 
6.	In file qf/80x86/dos/tcpp101/l/qf_port.cpp 
replaced deprecated QPSet::hasElements() to 
QPSet::isEmpty(). 
7.	In file qf/80x86/linux/gcc/qf_port.cpp added 
QF::run() 
8.	In file qeq_init.cpp changed QS_OBJ(this) to 
QS_OBJ(qSto) to consistently refer to a queue 
by the ring buffer object 
9.	In file qf_pkg.h removed extern QF_tickCtr_.


Version 3.1.04 (Product Release)
Release date: Dec 11, 2005

1.	In file qmpool.h changed the definition of the 
QF_MPOOL_SIZ_SIZE macro to remove the 
dependency on the QF_EVENT_SIZ_SIZE. Macro 
QF_EVENT_SIZ_SIZE might not be defined by the 
time qmpool.h is included. 
2.	Added explicit definition of the configuration 
macro QF_EVENT_SIZ_SIZE to all qf_port.h 
files. 
3.	Fixed a bug in function QMPool::init() (file 
qmp_init.cpp) by changing the type of variable 
n from uint8_t to QMPoolCtr. The uint8_t data 
type was failing for bigger block sizes. 
4.	Added the QF::onIdle() callback to qf.h 
5.	Improved comments in qpset.h 
6.	Corrected dependencies in the Makefile for 
QDPP example (directory 80x86 and 80x86) 
7.	Added Linux QF port to the standard QF/C++ 
distribution. 
8.	Released the "QF/C++ Programmer's Manual"


Version 3.1.03 (Beta Release)
Release date: Nov 21, 2005

1.	Added Doxygen documentation to the source code 
2.	Added running__ member to the QActive 
structure 
3.	Added QF_EVENT_SIZ_SIZE configuration macro 
and related data type QEventSize. Made the 
following changes to the signatures: 
void QF::poolInit(void *poolSto, uint32_t 
poolSize, QEventSize evtSize); 
QEvent *QFnew_(QEventSize evtSize, QSignal 
sig);


Version 3.1.00 (Snapshot Release)
Release date: Oct 10, 2005

1.	Applied new directory structure desribed in 
Application Note: QP Directory Structure 
2.	Added Quantum Spy instrumentation. 


QK/C++ Revision History
=======================

Version 3.3.00 (Product)
Release date: Jan 22, 2007

The main change in this release is adding the macro 
Q_ROM_VAR in QEP for all constant objects allocated in 
ROM. The Q_ROM_VAR macro has been added for the 
compilers like Freescale HC(S)08, which require far 
pointers to access the objects in ROM. Please note 
that specifying the pointer size for accessing a ROM 
objects is syntactically different than specifying 
that the object is allocated in ROM (see macro Q_ROM). 
 
The other significant change in release 3.3.00 is 
simplification of the build strategy for QP ports. 
Instead of separate Makefile for every QP component, 
such as QEP, QF, QK, and QS, not the "ports" directory 
contains a batch file "make.bat" that builds all the 
libraries at once. 

1.	in file qk.h added macro Q_ROM_VAR for objects 
allocated in ROM and to signatures of 
functions accessing these objects. 
2.	In file qk.cpp added Q_ROM_VAR to the 
signature of QK::getVersion(). 
3.	In file qk.cpp updated version number to 
3.3.00 
4.	Updated the "QP Programmer's Manaul" to 
Revision E


Version 3.2.04
Release date: Dec 01, 2006

This QK release adds two new features in QK.
The first feature added is the extended context switch 
for CPUs with co-processors, such as the x87 FPU 
accompanying the x86 CPU. As a fully- preemptive 
kernel, QK needs to save and restore the context of 
the co- processor accrosss the asynchronous 
preemption. This QK release adds a generic mechanism 
for saving and restoring extened context in the 
extended scheduler (QK_scheduleExt_()), which is used 
only at the exit from the interrupts (asynchronous 
preemptions).
The second feature added is the Thread-Local Storage 
(TLS) for reentrant libraries, such as the NewLib. 
This feature allows assigning per-thread memory and 
providing a hook (callback) activated at every context 
switch. 

1.	In file qk.h updated revision history and 
added the prototype for the extended scheduler 
QK_scheduleExt_(). This scheduler implements 
the generic extended context via macros 
QK_EXT_TYPE, QK_EXT_SAVE, and QK_EXT_RESTORE. 
2.	In file qk.h removed definitions of the 
obsolete macros QACTIVE_POST_FIFO_, 
QACTIVE_POST_LIFO_, and QACTIVE_GET_. 
3.	In file qk_sched.cpp added logic for handling 
the TLS via the macro QK_TLS. 
4.	Added new file qk_ext.cpp with the definition 
of the extended scheduler QK_scheduleExt_(). 
5.	Added the file qk_ext.cpp to the Makefile for 
QK port to 80x86 with Turbo C++ 1.01. 
6.	Extended the QK port to 80x86 with Turbo C++ 
1.01 to handle the x87 FPU context. 
7.	Extended the QDPP example for QK with Turbo 
C++ 1.01 to demonstrate threads that use the 
FPU and require the extended context switch. 
8.	In file qk.cpp updated version number to 
3.2.04 
9.	Updated the "QP Programmer's Manaul" to 
Revision C


Version 3.2.00 (Product Release)
Release date: Aug 10, 2006

1.	in file qk.h added new idle callback 
QK::onIdle(), which in contrast to 
QF::onIdle() is invoked with interrupts 
unlocked. 
2.	in file qk.h removed 
QK_schedLock()/QK_schedUnlock() and replaced 
them with QK_mutexLock()/QK_mutexUnlock(), 
with the semantics of returning the mutex. 
3.	in file qk.h changed the definitions of macros 
QF_SCHED_LOCK/ QF_SCHED_UNLOCK to use the new 
QK mutex API. 
4.	In file qk.h used the macro Q_ROM to allocate 
constant objects to ROM ( 
See also: 
qep.h).
5.	in file qk.h added the typedef for QMutex. 
6.	in file qk.cpp replaced the callback 
QF::onIdle() with the new one QK::onIdle(). 
7.	removed source file qk_lock.cpp 
8.	added source file qk_mutex.cpp 
9.	in file qk.cpp changed the version number to 
3.2.00 
10.	in all QK/C++ examples replaced callback 
QF::onIdle() with QK::onIdle() 
11.	Updated "QK/C++ Programmer's Manual"


Version 3.2.01 (Product)
Release date: Sep 01, 2006

1.	In file qk.cpp updated version number to 
3.2.01 
2.	Added makefiles for building ports of all 
QP/C++ libraries at once. 
3.	Created the consolidated manual "QP/C++ 
Programmer's Manual".


Version 3.2.00 (Product Release)
Release date: Aug 10, 2006

1.	in file qk.h added new idle callback 
QK::onIdle(), which in contrast to 
QF::onIdle() is invoked with interrupts 
unlocked. 
2.	in file qk.h removed 
QK_schedLock()/QK_schedUnlock() and replaced 
them with QK_mutexLock()/QK_mutexUnlock(), 
with the semantics of returning the mutex. 
3.	in file qk.h changed the definitions of macros 
QF_SCHED_LOCK/ QF_SCHED_UNLOCK to use the new 
QK mutex API. 
4.	In file qk.h used the macro Q_ROM to allocate 
constant objects to ROM ( 
See also: 
qep.h).
5.	in file qk.h added the typedef for QMutex. 
6.	in file qk.cpp replaced the callback 
QF::onIdle() with the new one QK::onIdle(). 
7.	removed source file qk_lock.cpp 
8.	added source file qk_mutex.cpp 
9.	in file qk.cpp changed the version number to 
3.2.00 
10.	in all QK/C++ examples replaced callback 
QF::onIdle() with QK::onIdle() 
11.	Updated "QK/C++ Programmer's Manual"


Version 3.1.06 (Product Release)
Release date: May 11, 2006

1.	In file qk_sched.cpp removed unlocking of 
interrupts upon exit from QK::schedule_(). Now 
QK_schedule_() enters and exits with 
interrupts LOCKED. 
2.	In file qk.h modified macro 
QACTIVE_OSOBJECT_SIGNAL_() to always unlock 
the interrupts, regardless if QK_schedule_() 
has been called or not. 
3.	In file qk.cpp added unlocking interrupts 
after the call to QK_SCHEDULE_() in the 
function QF::run(). 
4.	In file qk_lock.cpp modified the function 
QK::schedUnlock() to always unlock the 
interrupts upon exit.


Version 3.1.05 (Product Release)
Release date: Feb 13, 2006

1.	In file qk.h removed extern QK_intLockNest_ 
and QK_isrNest_. These counters have been 
moved to QF and renamed in the process to 
QF_intLockNest_ and QF_isrNest_, respectively. 
2.	In file qk.h added QS instrumentatin to 
QF_INT_LOCK and QF_INT_UNLOCK macros for 
tracing interrupt locking/unlocking. The QS 
interrupt locking/ unlocking instrumentation 
has been previously added at the QK port 
level. 
3.	In file qk.h removed macros QK_QS_INT_LOCK()/ 
QK_QS_INT_UNLOCK(), QK_QS_ISR_ENTRY()/ 
QK_QS_ISR_EXIT(). These macros have been moved 
to QF and renamed in the process to 
QF_QS_INT_LOCK()/ QF_QS_INT_UNLOCK(), 
QF_QS_ISR_ENTRY()/ QF_QS_ISR_EXIT(), 
respectively. 
4.	In file ports/80x86/qk/tcpp101/l/qk_port.h 
simplified the definition of the macros 
QK_INT_LOCK/ QK_INT_UNLOCK to NOT contain the 
QS instrumenation. 
5.	In file ports/80x86/qk/tcpp101/l/qk_port.h 
changed the definitions of QK_ISR_ENTRY and 
QK_ISR_EXIT to use QF_QS_ISR_ENTRY/ 
QF_QS_ISR_EXIT. 
6.	In file qk.cpp added the Revision History 
Doxygen comment 
7.	In file qk_pkg.h changed the definition of 
internal QK macros QK_INT_LOCK_/ 
QK_INT_UNLOCK_ to use the QS-instrumented 
QF_INT_LOCK/ QF_INT_UNLOCK. 
8.	In file qk_lock.cpp corrected a comment 
9.	In file qk_sched.cpp corrected a comment


Version 3.1.04 (Product Release)
Release date: Dec 30, 2005

1.	Provided "QK/C++ Programmer's Manual" in PDF. 
2.	In file qk.h removed callbacks QK::init(), 
QK::start(), QK::idle(), and QK::exit(), 
because they duplicate the QF callbacks. 
3.	Modified qk.cpp to define the following QF 
"callbacks": QF::getPortVersion(), QF::run(), 
QActive::start(), and QActive::stop_(). 
4.	Added an argument to the signature of 
QK::schedLock() to allow selective QK 
scheduler locking up to the specified priority 
level. 
5.	Changed the implementation of QK::schedLock() 
in file qk_lock.cpp. 
6.	Eliminated the need for qf_port.cpp in the 
QF/C++ ports for QK. 
7.	Simplified elements that go into qk_port.cpp 
in the QK/C++ ports. 
8.	Added the ARM-Simulator port to the standard 
QK/C++ distribution. 
9.	Cleaned-up the 80x86 QK port.


Version 3.1.03 (Beta Release)
Release date: Nov 21, 2005

1.	Added Doxygen documentation to the source code 



QS/C++ Revision History
=======================

Version 3.3.00 (Product)
Release date: Jan 25, 2007

The main change in the release 3.3.00 is better 
integration of QS with the rest of QP. This is 
achieved by using the QP macros Q_ROM, Q_ROM_VAR, 
QF_INT_KEY_TYPE, QF_INT_LOCK, and QF_INT_UNLOCK. By 
simply including the header file "qf_port.h" before 
"qs.h" in the "qs_port.h" include, you no longer need 
to manually ensure that QS implements the same 
policies as the rest of QP. This change still allows 
using QS standalone (without any other QP components), 
but then the QP macros must be explicitly defined in 
the qs_port.h header file. 
 
The other significant change in release 3.3.00 is 
adding the macro QS_ROM_VAR for all constant objects 
allocated in ROM (see also macro Q_ROM_VAR added to 
QEP). The QS_ROM_VAR macro has been added for the 
compilers like Freescale HC(S)08, which require far 
pointers to access the objects in ROM. Please note 
that specifying the pointer size for accessing a ROM 
objects is syntactically different than specifying 
that the object is allocated in ROM (see macro Q_ROM).
1.	in file qs.h added macro QS_ROM_VAR for 
objects allocated in ROM and to signatures of 
functions accessing these objects. 
2.	In file qs.h added default definitions of the 
QS macros Q_ROM, Q_ROM_VAR, and Q_ROM_BYTE. 
3.	In file qs.h added declaration of QS_tickCtr_. 
4.	In file qs.cpp added Q_ROM_VAR to the 
signature of QS::getVersion(). 
5.	In file qs_.cpp added Q_ROM_VAR to the 
signature of QS::str_ROM_(). 
6.	In file qs_.cpp added definition of 
QS_tickCtr_. 
7.	In file qs_str.cpp added Q_ROM_VAR to the 
signature of QS::str_ROM(). 
8.	In file qs.cpp updated version number to 
3.3.00 
9.	Updated the "QP Programmer's Manaul" to 
Revision E


Version 3.2.02 (Product)
Release date: Oct 30, 2006

1.	In file qs.h replaced macro Q_ROM with QS_ROM 
2.	In file qs.h added methods QS::str_ROM_() and 
QS::str_ROM() 
3.	In file qs.h added macros QS_STR_ROM_() and 
QS_STR_ROM() 
4.	In file qs.h modified macros 
QS_???_DICTIONARY() to use ROM strings 
5.	In file qs.h included qs_dummy.h instead of 
the dummy definitions of the QS macros 
6.	In file qs_pkg.h added ifndef Q_SPY before 
definition of macro Q_SPY 
7.	In file qs_.cpp added definition of the 
function QS::str_ROM_() 
8.	In file qs_str.cpp added definition of the 
function QS::str_ROM() 
9.	In file qs.cpp updated version number to 
3.2.02


Version 3.2.01 (Product)
Release date: Sep 01, 2006

1.	In file qs.cpp updated version number to 
3.2.01 
2.	In file qs.cpp removed superfluous semicolons 
after QS_INSERT...() 
3.	In file qs_.cpp removed superfluous semicolons 
after QS_INSERT...() 
4.	In file qs_str.cpp removed superfluous 
semicolons after QS_INSERT...() 
5.	In file qs_mem.cpp removed superfluous 
semicolons after QS_INSERT...() 
6.	In file qs_f32.cpp removed superfluous 
semicolons after QS_INSERT...() 
7.	In file qs_f64.cpp removed superfluous 
semicolons after QS_INSERT...() 
8.	Added makefiles for building ports of all 
QP/C++ libraries at once. 
9.	Created the consolidated manual "QP/C++ 
Programmer's Manual".


Version 3.2.00 (Commercial Release)
Release date: Aug 11, 2006

1.	In file qs.h replaced QS_QK_SCHED_LOCK/UNLOCK 
with QS_QK_MUTEX_LOCK/ QS_QK_MUTEX_UNLOCK. 
Also, changed data accompanying the trace 
records QS_QK_MUTEX_LOCK/UNLOCK. 
2.	In file qs.h used the macro Q_ROM to allocate 
constant objects to ROM ( 
See also: 
qep.h).
3.	in file qs.cpp changed the version number to 
3.2.00 
4.	Updated "QS Programmer's Manual" in PDF.


Version 3.1.06 (Commercial Release)
Release date: May 07, 2006

1.	Updated licensing information. 
2.	Updated "QS/C++ Programmer's Manual" in PDF.
Version 3.1.05 (Product Release)
Release date: Feb 13, 2006
1.	Provided "QS/C++ Programmer's Manual" in PDF. 
2.	In file qs.h changed around the pre-defined 
records. Added records: QS_QF_INT_LOCK, 
QS_QF_INT_UNLOCK, QS_QF_ISR_ENTRY, 
QS_QF_ISR_EXIT. Removed records 
QS_QK_INT_LOCK, QS_QK_INT_UNLOCK, 
QS_QK_ISR_ENTRY, QS_QK_ISR_EXIT. 
3.	In file qs.h renamed functions QS::filterIn()/ 
QS::filerOut() to QS::filterOn()/ 
QS::filerOff(). Correspondingly, changed 
macros QS_FILTER_IN(), QS_FILTER_OUT(), to 
QS_FILTER_ON(), QS_FILTER_OFF(). 
4.	In file qs.h changed the signature and 
semantics of QS::getByte() to return QS_EOD 
(End-Of-Data). 
5.	In file qs.h changed the signature of 
QS::getBlock() to take a pointer to uint16_t 
rather than uint32_t. 
6.	In file qs.h eliminated the callback 
QS::newRecord() 
7.	In file qs.h added new callback QS::flush() 
8.	In file qs.h added application-level local 
filter object QS::apObj_. Consistently, added 
macro QS_FILTER_AP_OBJ() to set the new local 
filter. Consistently, added object argument to 
macros QS_BEGIN() and QS_BEGIN_NOLOCK(). 
9.	In files qs.cpp, qs_.cpp, qs_blk.cpp, 
qs_byte.cpp, qs_pkg.h renamed some variables 
and adjusted comments. 
10.	Ported the QSpy host applicatoin to Linux. 
Added TCP/IP input to QSpy. Added new options. 
11.	Added redesigned QS port to Linux with 
TCP/IP data link.

Version 3.1.03 (Beta Release)
Release date: Nov 21, 2005

1.	Added Doxygen documentation to the source code 
2.	Renamed file qqs.cpp to qs_.cpp 

