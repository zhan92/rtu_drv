@echo off
:: ===========================================================================
:: Product: QP/C++ buld script for uC/OS-II port, Open Watcom compiler
:: Last Updated for Version: 4.4.00
:: Date of the Last Update:  Apr 19, 2012
::
::                    Q u a n t u m     L e a P s
::                    ---------------------------
::                    innovating embedded systems
::
:: Copyright (C) 2002-2012 Quantum Leaps, LLC. All rights reserved.
::
:: This program is open source software: you can redistribute it and/or
:: modify it under the terms of the GNU General Public License as published
:: by the Free Software Foundation, either version 2 of the License, or
:: (at your option) any later version.
::
:: Alternatively, this program may be distributed and modified under the
:: terms of Quantum Leaps commercial licenses, which expressly supersede
:: the GNU General Public License and are specifically designed for
:: licensees interested in retaining the proprietary status of their code.
::
:: This program is distributed in the hope that it will be useful,
:: but WITHOUT ANY WARRANTY; without even the implied warranty of
:: MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
:: GNU General Public License for more details.
::
:: You should have received a copy of the GNU General Public License
:: along with this program. If not, see <http:::www.gnu.org/licenses/>.
::
:: Contact information:
:: Quantum Leaps Web sites: http://www.quantum-leaps.com
::                          http://www.state-machine.com
:: e-mail:                  info@quantum-leaps.com
:: ===========================================================================

:: If you have defined the WATCOM environment variable, the following line has
:: no effect and your definition is used. However, if the varible WATCOM is
:: not defined, the following default is assuemed: 
if "%WATCOM%"=="" set WATCOM=c:\tools\WATCOM

path %WATCOM%\binw
set INCLUDE=%WATCOM%\H
set CC=wpp.exe
set AS=wasm.exe
set LIB=wlib.exe

:: NOTE: you don't need to have the uC/OS-II source code to build the
:: QP libraries for uC/OS-II. In this case you will use the default
:: uC/OS-II configuration, as provided in the ucos2.86 directory.
:: However, if you do have uC/OS-II source code, you can recompile it
:: to use your own configuration. The following symbols define the
:: locations of uC/OS-II source and port directories
:: 
set UCOS_SRCDIR=\software\uCOS-II\Source
set UCOS_INCDIR=ucos2.86
set UCOS_PRTDIR=ucos2.86

if not "%1"=="rel" goto spy
    echo rel selected
    set BINDIR=rel
    set CCFLAGS=-d0 -ot @cc_opt.rsp
    set ASFLAGS=-fpi87
goto compile
:spy
if not "%1"=="spy" goto dbg
    echo spy selected
    set BINDIR=spy
    set CCFLAGS=-d2 -dQ_SPY @cc_opt.rsp
    set ASFLAGS=-fpi87
goto compile
:dbg
echo default selected
set BINDIR=dbg
set CCFLAGS=-d2 @cc_opt.rsp
set ASFLAGS=-fpi87

::===========================================================================
:compile

mkdir %BINDIR%
set LIBDIR=%BINDIR%

:: uC/OS-II -----------------------------------------------------------------
if not "%1"=="rel" goto qp

@echo on
%AS% %ASFLAGS% -fo=%UCOS_PRTDIR%\os_cpu_a.obj %UCOS_PRTDIR%\os_cpu_a.asm
%CC% %CCFLAGS% @inc_ucos.rsp -fo=%UCOS_PRTDIR%\os_cpu_c.obj %UCOS_PRTDIR%\os_cpu_c.c
%CC% %CCFLAGS% @inc_ucos.rsp -fo=%UCOS_PRTDIR%\ucos_ii.obj  %UCOS_SRCDIR%\ucos_ii.c
@echo off

:qp

:: QEP ----------------------------------------------------------------------
set SRCDIR=..\..\..\..\..\qep\source
set CCINC=@inc_qep.rsp

@echo on
%CC% %CCFLAGS% %CCINC% -fo=%BINDIR%\qep.obj      %SRCDIR%\qep.cpp
%CC% %CCFLAGS% %CCINC% -fo=%BINDIR%\qfsm_ini.obj %SRCDIR%\qfsm_ini.cpp
%CC% %CCFLAGS% %CCINC% -fo=%BINDIR%\qfsm_dis.obj %SRCDIR%\qfsm_dis.cpp
%CC% %CCFLAGS% %CCINC% -fo=%BINDIR%\qhsm_ini.obj %SRCDIR%\qhsm_ini.cpp
%CC% %CCFLAGS% %CCINC% -fo=%BINDIR%\qhsm_dis.obj %SRCDIR%\qhsm_dis.cpp
%CC% %CCFLAGS% %CCINC% -fo=%BINDIR%\qhsm_top.obj %SRCDIR%\qhsm_top.cpp
%CC% %CCFLAGS% %CCINC% -fo=%BINDIR%\qhsm_in.obj  %SRCDIR%\qhsm_in.cpp

erase %LIBDIR%\qep.lib
%LIB% -n %LIBDIR%\qep
%LIB% %LIBDIR%\qep +%BINDIR%\qep
%LIB% %LIBDIR%\qep +%BINDIR%\qfsm_ini
%LIB% %LIBDIR%\qep +%BINDIR%\qfsm_dis
%LIB% %LIBDIR%\qep +%BINDIR%\qhsm_ini
%LIB% %LIBDIR%\qep +%BINDIR%\qhsm_dis
%LIB% %LIBDIR%\qep +%BINDIR%\qhsm_top
%LIB% %LIBDIR%\qep +%BINDIR%\qhsm_in
@echo off

:: QF -----------------------------------------------------------------------
set SRCDIR=..\..\..\..\..\qf\source
set CCINC=@inc_qf.rsp

@echo on
%CC% %CCFLAGS% %CCINC% -fo=%BINDIR%\qa_defer.obj %SRCDIR%\qa_defer.cpp
%CC% %CCFLAGS% %CCINC% -fo=%BINDIR%\qa_sub.obj   %SRCDIR%\qa_sub.cpp
%CC% %CCFLAGS% %CCINC% -fo=%BINDIR%\qa_usub.obj  %SRCDIR%\qa_usub.cpp
%CC% %CCFLAGS% %CCINC% -fo=%BINDIR%\qa_usuba.obj %SRCDIR%\qa_usuba.cpp
%CC% %CCFLAGS% %CCINC% -fo=%BINDIR%\qf_act.obj   %SRCDIR%\qf_act.cpp
%CC% %CCFLAGS% %CCINC% -fo=%BINDIR%\qf_gc.obj    %SRCDIR%\qf_gc.cpp
%CC% %CCFLAGS% %CCINC% -fo=%BINDIR%\qf_log2.obj  %SRCDIR%\qf_log2.cpp
%CC% %CCFLAGS% %CCINC% -fo=%BINDIR%\qf_new.obj   %SRCDIR%\qf_new.cpp
%CC% %CCFLAGS% %CCINC% -fo=%BINDIR%\qf_pool.obj  %SRCDIR%\qf_pool.cpp
%CC% %CCFLAGS% %CCINC% -fo=%BINDIR%\qf_psini.obj %SRCDIR%\qf_psini.cpp
%CC% %CCFLAGS% %CCINC% -fo=%BINDIR%\qf_pspub.obj %SRCDIR%\qf_pspub.cpp
%CC% %CCFLAGS% %CCINC% -fo=%BINDIR%\qf_pwr2.obj  %SRCDIR%\qf_pwr2.cpp
%CC% %CCFLAGS% %CCINC% -fo=%BINDIR%\qf_tick.obj  %SRCDIR%\qf_tick.cpp
%CC% %CCFLAGS% %CCINC% -fo=%BINDIR%\qte_ctor.obj %SRCDIR%\qte_ctor.cpp
%CC% %CCFLAGS% %CCINC% -fo=%BINDIR%\qte_arm.obj  %SRCDIR%\qte_arm.cpp
%CC% %CCFLAGS% %CCINC% -fo=%BINDIR%\qte_darm.obj %SRCDIR%\qte_darm.cpp
%CC% %CCFLAGS% %CCINC% -fo=%BINDIR%\qte_rarm.obj %SRCDIR%\qte_rarm.cpp
%CC% %CCFLAGS% %CCINC% -fo=%BINDIR%\qte_ctr.obj  %SRCDIR%\qte_ctr.cpp
%CC% %CCFLAGS% %CCINC% -fo=%BINDIR%\qf_port.obj  src\qf_port.cpp

erase %LIBDIR%\qf.lib
%LIB% -n %LIBDIR%\qf
%LIB% %LIBDIR%\qf +%BINDIR%\qa_defer
%LIB% %LIBDIR%\qf +%BINDIR%\qa_sub
%LIB% %LIBDIR%\qf +%BINDIR%\qa_usub
%LIB% %LIBDIR%\qf +%BINDIR%\qa_usuba
%LIB% %LIBDIR%\qf +%BINDIR%\qf_act
%LIB% %LIBDIR%\qf +%BINDIR%\qf_gc
%LIB% %LIBDIR%\qf +%BINDIR%\qf_log2
%LIB% %LIBDIR%\qf +%BINDIR%\qf_new
%LIB% %LIBDIR%\qf +%BINDIR%\qf_pool
%LIB% %LIBDIR%\qf +%BINDIR%\qf_psini
%LIB% %LIBDIR%\qf +%BINDIR%\qf_pspub
%LIB% %LIBDIR%\qf +%BINDIR%\qf_pwr2
%LIB% %LIBDIR%\qf +%BINDIR%\qf_tick
%LIB% %LIBDIR%\qf +%BINDIR%\qte_ctor
%LIB% %LIBDIR%\qf +%BINDIR%\qte_arm
%LIB% %LIBDIR%\qf +%BINDIR%\qte_darm
%LIB% %LIBDIR%\qf +%BINDIR%\qte_rarm
%LIB% %LIBDIR%\qf +%BINDIR%\qte_ctr
%LIB% %LIBDIR%\qf +%BINDIR%\qf_port
@echo off

:: QS -----------------------------------------------------------------------
if not "%1"=="spy" goto clean

set SRCDIR=..\..\..\..\..\qs\source
set CCINC=@inc_qs.rsp

@echo on
%CC% %CCFLAGS% %CCINC% -fo=%BINDIR%\qs.obj      %SRCDIR%\qs.cpp
%CC% %CCFLAGS% %CCINC% -fo=%BINDIR%\qs_.obj     %SRCDIR%\qs_.cpp
%CC% %CCFLAGS% %CCINC% -fo=%BINDIR%\qs_blk.obj  %SRCDIR%\qs_blk.cpp
%CC% %CCFLAGS% %CCINC% -fo=%BINDIR%\qs_byte.obj %SRCDIR%\qs_byte.cpp
%CC% %CCFLAGS% %CCINC% -fo=%BINDIR%\qs_f32.obj  %SRCDIR%\qs_f32.cpp
%CC% %CCFLAGS% %CCINC% -fo=%BINDIR%\qs_f64.obj  %SRCDIR%\qs_f64.cpp
%CC% %CCFLAGS% %CCINC% -fo=%BINDIR%\qs_mem.obj  %SRCDIR%\qs_mem.cpp
%CC% %CCFLAGS% %CCINC% -fo=%BINDIR%\qs_str.obj  %SRCDIR%\qs_str.cpp

erase %LIBDIR%\qs.lib
%LIB% -n %LIBDIR%\qs
%LIB% %LIBDIR%\qs +%BINDIR%\qs.obj
%LIB% %LIBDIR%\qs +%BINDIR%\qs_.obj
%LIB% %LIBDIR%\qs +%BINDIR%\qs_blk.obj
%LIB% %LIBDIR%\qs +%BINDIR%\qs_byte.obj
%LIB% %LIBDIR%\qs +%BINDIR%\qs_f32.obj
%LIB% %LIBDIR%\qs +%BINDIR%\qs_f64.obj
%LIB% %LIBDIR%\qs +%BINDIR%\qs_mem.obj
%LIB% %LIBDIR%\qs +%BINDIR%\qs_str.obj
@echo off

:clean
@echo off

erase %BINDIR%\*.obj
erase %LIBDIR%\*.bak
