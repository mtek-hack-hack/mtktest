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
echo off
echo This is Customization configuration utility
echo Please make sure that u have performed the developer build second pass obj before running this batch file
mkdir ..\..\PixtelMMI
mkdir ..\..\PixtelMMI\MMI
mkdir ..\..\PixtelMmi\MMI\FinalMMIObj
mkdir ..\..\PixtelMMI\MMI\ExeFinalMMI
mkdir ..\..\PixtelMMI\MMI\Blankobj
mkdir ..\..\PixtelMMI\Customer
mkdir ..\..\PixtelMMI\MMI\Framework
mkdir ..\..\PixtelMMI\MMI\Framework\NVRAMManager
mkdir ..\..\PixtelMMI\MMI\Framework\NVRAMManager\NVRAM_DATA

echo Directories Created
copy ..\MMI\debug\*.* ..\..\PixtelMmi\MMI\FinalMMIObj
copy ..\MMI\debug\phonebook.obj ..\..\PixtelMmi\MMI\FinalMMIObj\phonebook_temp.obj
copy ..\MMI\debug\DemoApp.obj ..\..\PixtelMmi\MMI\FinalMMIObj\DemoApp_temp.obj

del ..\..\PixtelMmi\MMI\FinalMMIObj\CustImgMap.*
del ..\..\PixtelMmi\MMI\FinalMMIObj\CustImgRes.*
del ..\..\PixtelMmi\MMI\FinalMMIObj\CustMenuRes.*
del ..\..\PixtelMmi\MMI\FinalMMIObj\CustStrMap.*
del ..\..\PixtelMmi\MMI\FinalMMIObj\CustStrRes.*
del ..\..\PixtelMmi\MMI\FinalMMIObj\FontRes.*
del ..\..\PixtelMmi\MMI\FinalMMIObj\gui_wrapper.*
del ..\..\PixtelMmi\MMI\FinalMMIObj\KeyMapDeclare.*
del ..\..\PixtelMmi\MMI\FinalMMIObj\ThemeRes.*
del ..\..\PixtelMmi\MMI\FinalMMIObj\ThemeResTable.*
del ..\..\PixtelMmi\MMI\FinalMMIObj\*.dll
del ..\..\PixtelMmi\MMI\FinalMMIObj\*.exe
del ..\..\PixtelMmi\MMI\FinalMMIObj\*.res

echo --
echo RunFirst Complete!!
pause
exit
