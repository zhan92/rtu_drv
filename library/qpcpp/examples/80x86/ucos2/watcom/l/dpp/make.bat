@echo off
:: ==========================================================================
:: Product: DPP/C++ example, uC/OS-II/80x86 port, Open Watcom compiler
:: Last Updated for Version: 4.4.00
:: Date of the Last Update:  Apr 26, 2012
::
::                    Q u a n t u m     L e a P s
::                    ---------------------------
::                    innovating embedded systems
::
:: Copyright (C) 2002-2012 Quantum Leaps, LLC. All rights reserved.
::
:: This software may be distributed and modified under the terms of the GNU
:: General Public License version 2 (GPL) as published by the Free Software
:: Foundation and appearing in the file GPL.TXT included in the packaging of
:: this file. Please note that GPL Section 2[b] requires that all works based
:: on this software must also be made publicly available under the terms of
:: the GPL ("Copyleft").
::
:: Alternatively, this software may be distributed and modified under the
:: terms of Quantum Leaps commercial licenses, which expressly supersede
:: the GPL and are specifically designed for licensees interested in
:: retaining the proprietary status of their code.
::
:: Contact information:
:: Quantum Leaps Web site:  http://www.quantum-leaps.com
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
set LD=wlink.exe

if not "%1"=="rel" goto spy
    echo rel selected
    set BINDIR=rel
    set CCFLAGS=-d0 -ml -ecc -s -3 -fpi87 -ot -dNDEBUG
    set LDFLAGS=@link_rel.rsp
goto compile
:spy
if not "%1"=="spy" goto dbg
    echo spy selected
    set BINDIR=spy
    set CCFLAGS=-d2 -ml -ecc -s -3 -fpi87 -dQ_SPY
    set LDFLAGS=@link_spy.rsp
goto compile
:dbg
    echo default selected
    set BINDIR=dbg
    set CCFLAGS=-d2 -ml -ecc -s -3 -fpi87
    set LDFLAGS=@link_dbg.rsp

:: compile -------------------------------------------------------------------
:compile
mkdir %BINDIR%
set CCINC=@inc_qp.rsp

:: DPP ----------------------------------------------------------------------
:dpp
set SRCDIR=.

@echo on
%CC% %CCFLAGS% %CCINC% -fo=%BINDIR%\main.obj   %SRCDIR%\main.cpp
%CC% %CCFLAGS% %CCINC% -fo=%BINDIR%\bsp.obj    %SRCDIR%\bsp.cpp
%CC% %CCFLAGS% %CCINC% -fo=%BINDIR%\philo.obj  %SRCDIR%\philo.cpp
%CC% %CCFLAGS% %CCINC% -fo=%BINDIR%\table.obj  %SRCDIR%\table.cpp
%CC% %CCFLAGS% %CCINC% -fo=%BINDIR%\video.obj  %SRCDIR%\video.cpp

:: link ----------------------------------------------------------------------
@echo on
%LD% %LDFLAGS%
@echo off
