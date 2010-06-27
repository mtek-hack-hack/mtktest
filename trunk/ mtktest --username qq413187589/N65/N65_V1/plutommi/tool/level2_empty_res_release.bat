rem
rem  Copyright Statement:
rem  --------------------
rem  This software is protected by Copyright and the information contained
rem  herein is confidential. The software may not be copied and the information
rem  contained herein may not be used or disclosed except with the written
rem  permission of MediaTek Inc. (C) 2005
rem
rem  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
rem  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
rem  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
rem  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
rem  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
rem  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
rem  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
rem  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
rem  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
rem  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
rem  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
rem  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
rem
rem  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
rem  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
rem  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
rem  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
rem  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
rem
rem  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
rem  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
rem  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
rem  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
rem  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
rem
cd ..

rem ************************************************************
rem ***************** Copy Empty Resource to PLUTO *************
rem ************************************************************
if not exist %1\plutommi\Customer\CustResource\PLUTO_MMI\ md %1\plutommi\Customer\CustResource\PLUTO_MMI
xcopy Customer\custresource\EMPTY_MMI %1\plutommi\Customer\CustResource\PLUTO_MMI\*.*  /E /Q /Y /I

if not exist %1\plutommi\Customer\CustResource\ md %1\plutommi\Customer\CustResource
xcopy Customer\custresource\EMPTY_MMI %1\plutommi\Customer\CustResource\*.*  /E /Q /Y /I

if not exist %1\plutommi\Customer\Images\PLUTO\ md %1\plutommi\Customer\Images\PLUTO
rd /S/Q %1\plutommi\Customer\Images\PLUTO\mainlcd\
rd /S/Q %1\plutommi\Customer\Images\PLUTO\sublcd\
xcopy Customer\Images\EmptyImages %1\plutommi\Customer\Images\PLUTO\*.*  /E /Q /Y /I

rem ******* copy even the destination folder not existed *******
if not exist %1\plutommi\Customer\Images\PLUTO128X160\ md %1\plutommi\Customer\Images\PLUTO128X160
rd /S/Q %1\plutommi\Customer\Images\PLUTO128X160\mainlcd\
rd /S/Q %1\plutommi\Customer\Images\PLUTO128X160\sublcd\
xcopy Customer\Images\EmptyImages128X160 %1\plutommi\Customer\Images\PLUTO128X160\*.*  /E /Q /Y /I

rem ******* copy even the destination folder not existed *******
if not exist %1\plutommi\Customer\Images\PLUTO176X220\ md %1\plutommi\Customer\Images\PLUTO176X220
rd /S/Q %1\plutommi\Customer\Images\PLUTO176X220\mainlcd\
rd /S/Q %1\plutommi\Customer\Images\PLUTO176X220\sublcd\
xcopy Customer\Images\EmptyImages176X220 %1\plutommi\Customer\Images\PLUTO176X220\*.*  /E /Q /Y /I

rem ******* copy even the destination folder not existed *******
if not exist %1\plutommi\Customer\Images\PLUTO240X320\ md %1\plutommi\Customer\Images\PLUTO240X320
rd /S/Q %1\plutommi\Customer\Images\PLUTO240X320\mainlcd\
rd /S/Q %1\plutommi\Customer\Images\PLUTO240X320\sublcd\
xcopy Customer\Images\EmptyImages240X320 %1\plutommi\Customer\Images\PLUTO240X320\*.*  /E /Q /Y /I

rem ******* copy even the destination folder not existed *******
if not exist %1\plutommi\Customer\Images\PLUTO320X240\ md %1\plutommi\Customer\Images\PLUTO320X240
rd /S/Q %1\plutommi\Customer\Images\PLUTO320X240\mainlcd\
rd /S/Q %1\plutommi\Customer\Images\PLUTO320X240\sublcd\
xcopy Customer\Images\EmptyImages320X240 %1\plutommi\Customer\Images\PLUTO320X240\*.*  /E /Q /Y /I

rem ******* copy even the destination folder not existed *******
if not exist %1\plutommi\Customer\Images\SubLCD64X96\ md %1\plutommi\Customer\Images\SubLCD64X96
xcopy Customer\Images\EmptyImagesSubLCD64X96 %1\plutommi\Customer\Images\SubLCD64X96\*.*  /E /Q /Y /I

rem ******* copy even the destination folder not existed *******
if not exist %1\plutommi\Customer\Images\SubLCD96X64\ md %1\plutommi\Customer\Images\SubLCD96X64
xcopy Customer\Images\EmptyImagesSubLCD96X64 %1\plutommi\Customer\Images\SubLCD96X64\*.*  /E /Q /Y /I

rem ******* copy even the destination folder not existed *******
if not exist %1\plutommi\Customer\Images\SubLCD128X128\ md %1\plutommi\Customer\Images\SubLCD128X128
xcopy Customer\Images\EmptyImagesSubLCD128X128 %1\plutommi\Customer\Images\SubLCD128X128\*.*  /E /Q /Y /I

rem ******* copy even the destination folder not existed *******
if not exist %1\plutommi\Customer\Images\SubLCDBW48X64\ md %1\plutommi\Customer\Images\SubLCDBW48X64
xcopy Customer\Images\EmptyImagesSubLCDBW48X64 %1\plutommi\Customer\Images\SubLCDBW48X64\*.*  /E /Q /Y /I

rem ******* copy even the destination folder not existed *******
if not exist %1\plutommi\Customer\Images\SubLCDBW96X64\ md %1\plutommi\Customer\Images\SubLCDBW96X64
xcopy Customer\Images\EmptyImagesSubLCDBW96X64 %1\plutommi\Customer\Images\SubLCDBW96X64\*.*  /E /Q /Y /I

rem ******* copy even the destination folder not existed *******
if not exist %1\plutommi\Customer\LcdResource\MainLcd128X128\ md %1\plutommi\Customer\LcdResource\MainLcd128X128
xcopy Customer\custresource\EMPTY_MMI %1\plutommi\Customer\LcdResource\MainLcd128X128\*.*  /E /Q /Y /I
if not exist %1\plutommi\Customer\LcdResource\MainLcd128X160\ md %1\plutommi\Customer\LcdResource\MainLcd128X160
xcopy Customer\custresource\EMPTY_MMI %1\plutommi\Customer\LcdResource\MainLcd128X160\*.*  /E /Q /Y /I
if not exist %1\plutommi\Customer\LcdResource\MainLcd176X220\ md %1\plutommi\Customer\LcdResource\MainLcd176X220
xcopy Customer\custresource\EMPTY_MMI %1\plutommi\Customer\LcdResource\MainLcd176X220\*.*  /E /Q /Y /I
if not exist %1\plutommi\Customer\LcdResource\MainLcd240X320\ md %1\plutommi\Customer\LcdResource\MainLcd240X320
xcopy Customer\custresource\EMPTY_MMI %1\plutommi\Customer\LcdResource\MainLcd240X320\*.*  /E /Q /Y /I

rem ******* remove %1\plutommi\Customer\CustResource\PLUTO_MMI\InputMethod *******
if exist %1\plutommi\Customer\CustResource\PLUTO_MMI\InputMethod rd /s /q %1\plutommi\Customer\CustResource\PLUTO_MMI\InputMethod\

cd tool
