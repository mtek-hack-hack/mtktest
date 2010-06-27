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
@echo off
path ..\..\tools;..\..\..\Tools\MSYS\bin;..\..\..\Tools\MinGW\bin;..\debug;..\..\..\Tools;%path%;

echo Remake PC Simulator
cd ResGenerator
copy ..\debug\UCS2.o .\
@echo off
if not exist mtk_resgenerator.exe goto MakeResGen

:ResGen
rem // __CUSTPACK_MULTIBIN Calvin BEGIN
mtk_resgenerator.exe -g
rem // __CUSTPACK_MULTIBIN Calvin END

rem ************************************************************
rem *** Menu Tree Tool gen resource to copy back if needed *****
rem ************************************************************
copy ..\custresource\CustMenuToolRes.c ..\custresource\CustMenuRes.c

echo Completed Making Resources...

del ..\..\MMI\Debug\ThemeRes.obj
del ..\..\MMI\Debug\CustImgMap.obj
del ..\..\MMI\Debug\CustImgRes.obj
del ..\..\MMI\Debug\CustMenuRes.obj
del ..\..\MMI\Debug\CustStrMap.obj
del ..\..\MMI\Debug\CustStrRes.obj
del ..\..\MMI\Debug\FontRes.obj
del ..\..\MMI\Debug\gui_wrapper.obj
del ..\..\MMI\Debug\KeyMapDeclare.obj
del ..\..\MMI\Debug\PopulateRes.obj

COPY ..\custresource\%prj%_MMI\ref_list.txt ..\custresource\ref_list.txt
MergeStrRes ..\custresource\CustStrList.txt ..\custresource\ref_list.txt
del readexcel.exe
make readexcel.exe
if not exist readexcel.exe goto ERROR
ReadExcel CustResList_out.txt
echo String Resource generated successfully...

COPY .\CustStrMap.c ..\custresource\CustStrMap.c
COPY .\CustStrRes.c ..\custresource\CustStrRes.c

cd ..\..\MMI
EditMakfile PixtelMMI.mak
nmake /f "PixtelMMI.mak" CFG="PixtelMMI - Win32 Release"
exit 3


:MakeResGen
copy ..\debug\UCS2.o .\
copy ..\debug\ReadRes.o .\
copy ..\debug\WriteRes.o .\
copy ..\Customize\mmicustomizer.lib .\mmicustomizer.lib
reimp mmicustomizer.lib
make
if not exist mtk_resgenerator.exe goto ERROR
echo Completed Making Resources...
goto ResGen

:ERROR
echo Make Error!!
echo Please Check again!!
exit 3

:noinput
cd ..
echo Please specify customer
exit 3
