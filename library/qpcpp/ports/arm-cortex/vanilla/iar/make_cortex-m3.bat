@echo off
:: ===========================================================================
:: Product: QP/C++ buld script for ARM Cortex-M3, Vanilla port, IAR IAR compiler
:: Last Updated for Version: 4.5.04
:: Date of the Last Update:  Feb 10, 2013
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
:: along with this program. If not, see <http://www.gnu.org/licenses/>.
::
:: Contact information:
:: Quantum Leaps Web sites: http://www.quantum-leaps.com
::                          http://www.state-machine.com
:: e-mail:                  info@quantum-leaps.com
:: ===========================================================================
setlocal

:: define the IAR_ARM environment variable to point to the location 
:: where you've installed the IAR toolset or adjust the following 
:: set instruction 
::if "%IAR_ARM%"=="" set IAR_ARM="C:\Program Files\IAR Systems\Embedded Workbench 6.50"
if "%IAR_ARM%"=="" set IAR_ARM="C:\tools\IAR\ARM_6.5"

set PATH=%IAR_ARM%\arm\bin;%IAR_ARM%\common\bin;%PATH%

set CC=iccarm
set ASM=iasmarm
set LIB=iarchive

set QP_INCDIR=..\..\..\..\include
set QP_PRTDIR=.

set ARM_CORE=cortex-m3
set ARM_FPU=None

if "%1"=="" (
    echo default selected
    set BINDIR=%QP_PRTDIR%\dbg
    set CCFLAGS=-D DEBUG --debug --endian little --cpu=%ARM_CORE% --fpu %ARM_FPU% --eec++ -e --dlib_config %IAR_ARM%\ARM\INC\c\DLib_Config_Normal.h --diag_suppress Pa050 --no_static_destruction -Ohz
    set ASMFLAGS=-s+ -w+ -r --cpu %ARM_CORE% --fpu %ARM_FPU% -I%IAR_ARM%\ARM\INC\ 
)
if "%1"=="rel" (
    echo rel selected
    set BINDIR=%QP_PRTDIR%\rel
    set CCFLAGS=-D NDEBUG --endian little --cpu %ARM_CORE% --eec++ -e --fpu %ARM_FPU% --dlib_config %IAR_ARM%\ARM\INC\c\DLib_Config_Normal.h --diag_suppress Pa050 --no_static_destruction -Ohs --no_size_constraints
    set ASMFLAGS=-s+ -w+ -r --cpu %ARM_CORE% --fpu %ARM_FPU% -I%IAR_ARM%\ARM\INC\ 
)
if "%1"=="spy" (
    echo spy selected
    set BINDIR=%QP_PRTDIR%\spy
    set CCFLAGS=-D Q_SPY -D DEBUG --debug --endian little --cpu %ARM_CORE% --fpu %ARM_FPU% --eec++ -e --dlib_config %IAR_ARM%\ARM\INC\c\DLib_Config_Normal.h --diag_suppress Pa050 --no_static_destruction -Ohz
    set ASMFLAGS=-s+ -w+ -r --cpu %ARM_CORE% --fpu %ARM_FPU% -I%IAR_ARM%\ARM\INC\ 
)

mkdir %BINDIR%
set LIBDIR=%BINDIR%
set LIBFLAGS=-r
erase %LIBDIR%\libqp_%ARM_CORE%.a

:: QEP ----------------------------------------------------------------------
set SRCDIR=..\..\..\..\qep\source
set CCINC=-I%QP_PRTDIR% -I%QP_INCDIR% -I%SRCDIR%

@echo on
%CC% %CCFLAGS% %CCINC% -o%BINDIR%\ %SRCDIR%\qep.cpp
%CC% %CCFLAGS% %CCINC% -o%BINDIR%\ %SRCDIR%\qfsm_ini.cpp
%CC% %CCFLAGS% %CCINC% -o%BINDIR%\ %SRCDIR%\qfsm_dis.cpp
%CC% %CCFLAGS% %CCINC% -o%BINDIR%\ %SRCDIR%\qhsm_ini.cpp
%CC% %CCFLAGS% %CCINC% -o%BINDIR%\ %SRCDIR%\qhsm_dis.cpp
%CC% %CCFLAGS% %CCINC% -o%BINDIR%\ %SRCDIR%\qhsm_top.cpp
%CC% %CCFLAGS% %CCINC% -o%BINDIR%\ %SRCDIR%\qhsm_in.cpp

%LIB% --create %LIBDIR%\libqp_%ARM_CORE%.a %BINDIR%\qep.o %BINDIR%\qfsm_ini.o %BINDIR%\qfsm_dis.o %BINDIR%\qhsm_ini.o %BINDIR%\qhsm_dis.o %BINDIR%\qhsm_top.o %BINDIR%\qhsm_in.o
@echo off
erase %BINDIR%\*.o

:: QF -----------------------------------------------------------------------
set SRCDIR=..\..\..\..\qf\source
set CCINC=-I%QP_PRTDIR% -I%QP_INCDIR% -I%SRCDIR%

@echo on
%CC% %CCFLAGS% %CCINC% -o%BINDIR%\ %SRCDIR%\qa_defer.cpp
%CC% %CCFLAGS% %CCINC% -o%BINDIR%\ %SRCDIR%\qa_fifo.cpp
%CC% %CCFLAGS% %CCINC% -o%BINDIR%\ %SRCDIR%\qa_lifo.cpp
%CC% %CCFLAGS% %CCINC% -o%BINDIR%\ %SRCDIR%\qa_get_.cpp
%CC% %CCFLAGS% %CCINC% -o%BINDIR%\ %SRCDIR%\qa_sub.cpp
%CC% %CCFLAGS% %CCINC% -o%BINDIR%\ %SRCDIR%\qa_usub.cpp
%CC% %CCFLAGS% %CCINC% -o%BINDIR%\ %SRCDIR%\qa_usuba.cpp
%CC% %CCFLAGS% %CCINC% -o%BINDIR%\ %SRCDIR%\qeq_fifo.cpp
%CC% %CCFLAGS% %CCINC% -o%BINDIR%\ %SRCDIR%\qeq_get.cpp
%CC% %CCFLAGS% %CCINC% -o%BINDIR%\ %SRCDIR%\qeq_init.cpp
%CC% %CCFLAGS% %CCINC% -o%BINDIR%\ %SRCDIR%\qeq_lifo.cpp
%CC% %CCFLAGS% %CCINC% -o%BINDIR%\ %SRCDIR%\qf_act.cpp
%CC% %CCFLAGS% %CCINC% -o%BINDIR%\ %SRCDIR%\qf_gc.cpp
%CC% %CCFLAGS% %CCINC% -o%BINDIR%\ %SRCDIR%\qf_log2.cpp
%CC% %CCFLAGS% %CCINC% -o%BINDIR%\ %SRCDIR%\qf_new.cpp
%CC% %CCFLAGS% %CCINC% -o%BINDIR%\ %SRCDIR%\qf_pool.cpp
%CC% %CCFLAGS% %CCINC% -o%BINDIR%\ %SRCDIR%\qf_psini.cpp
%CC% %CCFLAGS% %CCINC% -o%BINDIR%\ %SRCDIR%\qf_pspub.cpp
%CC% %CCFLAGS% %CCINC% -o%BINDIR%\ %SRCDIR%\qf_pwr2.cpp
%CC% %CCFLAGS% %CCINC% -o%BINDIR%\ %SRCDIR%\qf_tick.cpp
%CC% %CCFLAGS% %CCINC% -o%BINDIR%\ %SRCDIR%\qmp_get.cpp
%CC% %CCFLAGS% %CCINC% -o%BINDIR%\ %SRCDIR%\qmp_init.cpp
%CC% %CCFLAGS% %CCINC% -o%BINDIR%\ %SRCDIR%\qmp_put.cpp
%CC% %CCFLAGS% %CCINC% -o%BINDIR%\ %SRCDIR%\qte_ctor.cpp
%CC% %CCFLAGS% %CCINC% -o%BINDIR%\ %SRCDIR%\qte_ctr.cpp
%CC% %CCFLAGS% %CCINC% -o%BINDIR%\ %SRCDIR%\qte_arm.cpp
%CC% %CCFLAGS% %CCINC% -o%BINDIR%\ %SRCDIR%\qte_darm.cpp
%CC% %CCFLAGS% %CCINC% -o%BINDIR%\ %SRCDIR%\qte_rarm.cpp
%CC% %CCFLAGS% %CCINC% -o%BINDIR%\ %SRCDIR%\qvanilla.cpp

%LIB% %LIBFLAGS% %LIBDIR%\libqp_%ARM_CORE%.a %BINDIR%\qa_defer.o %BINDIR%\qa_fifo.o %BINDIR%\qa_lifo.o %BINDIR%\qa_get_.o %BINDIR%\qa_sub.o %BINDIR%\qa_usub.o %BINDIR%\qa_usuba.o %BINDIR%\qeq_fifo.o %BINDIR%\qeq_get.o %BINDIR%\qeq_init.o %BINDIR%\qeq_lifo.o %BINDIR%\qf_act.o %BINDIR%\qf_gc.o %BINDIR%\qf_log2.o %BINDIR%\qf_new.o %BINDIR%\qf_pool.o %BINDIR%\qf_psini.o %BINDIR%\qf_pspub.o %BINDIR%\qf_pwr2.o %BINDIR%\qf_tick.o %BINDIR%\qmp_get.o %BINDIR%\qmp_init.o %BINDIR%\qmp_put.o %BINDIR%\qte_ctor.o %BINDIR%\qte_ctr.o %BINDIR%\qte_arm.o %BINDIR%\qte_darm.o %BINDIR%\qte_rarm.o %BINDIR%\qvanilla.o 
@echo off
erase %BINDIR%\*.o

:: QS -----------------------------------------------------------------------
if not "%1"=="spy" goto clean

set SRCDIR=..\..\..\..\qs\source
set CCINC=-I%QP_PRTDIR% -I%QP_INCDIR% -I%SRCDIR%

@echo on
%CC% %CCFLAGS% %CCINC% -o%BINDIR%\ %SRCDIR%\qs.cpp
%CC% %CCFLAGS% %CCINC% -o%BINDIR%\ %SRCDIR%\qs_.cpp
%CC% %CCFLAGS% %CCINC% -o%BINDIR%\ %SRCDIR%\qs_blk.cpp
%CC% %CCFLAGS% %CCINC% -o%BINDIR%\ %SRCDIR%\qs_byte.cpp
%CC% %CCFLAGS% %CCINC% -o%BINDIR%\ %SRCDIR%\qs_f32.cpp
%CC% %CCFLAGS% %CCINC% -o%BINDIR%\ %SRCDIR%\qs_f64.cpp
%CC% %CCFLAGS% %CCINC% -o%BINDIR%\ %SRCDIR%\qs_mem.cpp
%CC% %CCFLAGS% %CCINC% -o%BINDIR%\ %SRCDIR%\qs_str.cpp

%LIB% %LIBFLAGS% %LIBDIR%\libqp_%ARM_CORE%.a %BINDIR%\qs.o %BINDIR%\qs_.o %BINDIR%\qs_blk.o %BINDIR%\qs_byte.o %BINDIR%\qs_f32.o %BINDIR%\qs_f64.o %BINDIR%\qs_mem.o %BINDIR%\qs_str.o
@echo off
erase %BINDIR%\*.o

:: --------------------------------------------------------------------------

:clean
@echo off
erase %BINDIR%\tmp*.*

endlocal