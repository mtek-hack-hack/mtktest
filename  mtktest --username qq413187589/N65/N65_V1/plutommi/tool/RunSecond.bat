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
echo Please make sure that u have got the latest version
echo PixtelMMI from VSS before running this utility
mkdir ..\..\PixtelMMI\MMI\SecondMMIObj
mkdir ..\..\PixtelMMI\MMI\ExeSecondMMI
mkdir ..\..\PixtelMMI\MMI\Debug
mkdir ..\..\PixtelMmi\MMI\Inc
mkdir ..\..\PixtelMmi\Customer\CustResource
mkdir ..\..\PixtelMmi\Customer\CustResource\PLUTO_MMI
mkdir ..\..\PixtelMmi\Customer\Resources
echo Directories Created

copy ..\Customer\CustResource\* ..\..\PixtelMmi\Customer\CustResource
echo Copied CustResource Folder
xcopy ..\Customer\Customize ..\..\PixtelMmi\Customer\Customize\ /f /e
echo Copied Customize Folder
xcopy ..\Customer\Images ..\..\PixtelMmi\Customer\Images\ /f /e
echo Copied Images Folder
xcopy ..\MMI\libraries ..\..\PixtelMmi\MMI\Libraries\ /f /e
echo Copied Libraries Folder
xcopy ..\Customer\Resources ..\..\PixtelMmi\Customer\Resources\ /f /e
echo Copied Skin Pictures Folder
copy ..\MMI\Framework\NVRAMManager\NVRAM_DATA\* ..\..\PixtelMmi\MMI\Framework\NVRAMManager\NVRAM_DATA
echo Copied NVRAMDATA Folder


copy ..\MMI\debug\mmicustomizer.dll ..\..\PixtelMMI\MMI\Debug
echo copied mmicustomizer dll
copy ..\MMI\debug\QMMINWSimulator.dll ..\..\PixtelMMI\MMI\Debug
echo copied QMMINWSimulator.dll
copy ..\MMI\debug\NWSimulator.dll ..\..\PixtelMMI\MMI\Debug
echo copied NWSimulator.dll

copy ..\MMI\debug\*.* ..\..\PixtelMMI\MMI\SecondMMIObj
copy ..\MMI\debug\phonebook.obj ..\..\PixtelMMI\MMI\SecondMMIObj\phonebook_temp.obj
copy ..\MMI\debug\DemoApp.obj ..\..\PixtelMMI\MMI\SecondMMIObj\DemoApp_temp.obj
copy ..\MMI\debug\pixtelmmi.exe ..\..\PixtelMMI\MMI\Debug
echo copied obj files
del ..\..\PixtelMMI\MMI\SecondMMIObj\CustImgMap.*
del ..\..\PixtelMMI\MMI\SecondMMIObj\CustImgRes.*
del ..\..\PixtelMMI\MMI\SecondMMIObj\CustMenuRes.*
del ..\..\PixtelMMI\MMI\SecondMMIObj\CustStrMap.*
del ..\..\PixtelMMI\MMI\SecondMMIObj\CustStrRes.*
del ..\..\PixtelMmi\MMI\SecondMMIObj\FontRes.*
del ..\..\PixtelMmi\MMI\SecondMMIObj\gui_wrapper.*
del ..\..\PixtelMmi\MMI\SecondMMIObj\KeyMapDeclare.*
del ..\..\PixtelMMI\MMI\SecondMMIObj\ThemeRes.*
del ..\..\PixtelMmi\MMI\SecondMMIObj\ThemeResTable.*
del ..\..\PixtelMMI\MMI\SecondMMIObj\*.dll
del ..\..\PixtelMMI\MMI\SecondMMIObj\*.exe
del ..\..\PixtelMmi\MMI\SecondMMIObj\*.res

copy ..\MMI\Inc\BuildCfg.h ..\..\PixtelMMI\MMI\Inc
copy ..\MMI\Inc\CustDataRes.h ..\..\PixtelMMI\MMI\Inc
copy ..\MMI\Inc\CustDataProts.h ..\..\PixtelMMI\MMI\Inc
copy ..\MMI\Inc\CustMenuRes.h ..\..\PixtelMMI\MMI\Inc
copy ..\MMI\Inc\CustThemesRes.h ..\..\PixtelMMI\MMI\Inc
copy ..\MMI\Inc\FontDcl.h ..\..\PixtelMMI\MMI\Inc
copy ..\MMI\Inc\FontRes.h ..\..\PixtelMMI\MMI\Inc
copy ..\MMI\Inc\GlobalMenuItems.h ..\..\PixtelMMI\MMI\Inc
copy ..\MMI\Inc\PixtelDataTypes.h ..\..\PixtelMMI\MMI\Inc
copy ..\MMI\Inc\StdAfx.h ..\..\PixtelMMI\MMI\Inc
copy ..\MMI\Inc\StdC.h ..\..\PixtelMMI\MMI\Inc
copy ..\MMI\Inc\MMI_features.h ..\..\PixtelMMI\MMI\Inc

copy ..\MMI\GUI\GUI_INC\gui.h ..\..\PixtelMMI\MMI\Inc
copy ..\MMI\GUI\GUI_INC\gui_buttons.h ..\..\PixtelMMI\MMI\Inc
copy ..\MMI\GUI\GUI_INC\gui_common_menus.h ..\..\PixtelMMI\MMI\Inc
copy ..\MMI\GUI\GUI_INC\gui_config.h ..\..\PixtelMMI\MMI\Inc
copy ..\MMI\GUI\GUI_INC\gui_custom_menus.h ..\..\PixtelMMI\MMI\Inc
copy ..\MMI\GUI\GUI_INC\gui_data_types.h ..\..\PixtelMMI\MMI\Inc
copy ..\MMI\GUI\GUI_INC\gui_ems.h ..\..\PixtelMMI\MMI\Inc
copy ..\MMI\GUI\GUI_INC\gui_fixed_menuitems.h ..\..\PixtelMMI\MMI\Inc
copy ..\MMI\GUI\GUI_INC\gui_fixed_menus.h ..\..\PixtelMMI\MMI\Inc
copy ..\MMI\GUI\GUI_INC\gui_generic_menuitems.h ..\..\PixtelMMI\MMI\Inc
copy ..\MMI\GUI\GUI_INC\gui_generic_menus.h ..\..\PixtelMMI\MMI\Inc
copy ..\MMI\GUI\GUI_INC\gui_inputs.h ..\..\PixtelMMI\MMI\Inc
copy ..\MMI\GUI\GUI_INC\gui_scrollbars.h ..\..\PixtelMMI\MMI\Inc
copy ..\MMI\GUI\GUI_INC\gui_themes.h ..\..\PixtelMMI\MMI\Inc
copy ..\MMI\GUI\GUI_INC\gui_windows.h ..\..\PixtelMMI\MMI\Inc
copy ..\MtkApp\MtkAppInc\EMMenuItems.h ..\..\PixtelMMI\MMI\Inc
copy ..\MtkApp\MtkAppInc\FMMenuItems.h ..\..\PixtelMMI\MMI\Inc
copy ..\MtkApp\MtkAppInc\VMMenuItems.h ..\..\PixtelMMI\MMI\Inc
copy ..\MtkApp\MtkAppInc\WAPMenuItems.h ..\..\PixtelMMI\MMI\Inc
copy ..\MMI\EMS\EmsInc\ems.h ..\..\PixtelMMI\MMI\Inc
copy ..\MMI\Framework\Osl\OslInc\OslMemory.h ..\..\PixtelMMI\MMI\Inc
copy ..\MMI\Framework\Osl\OslInc\L4Dr.h ..\..\PixtelMMI\MMI\Inc
copy ..\MMI\MiscFramework\MiscFrameworkInc\PixcomFontEngine.h ..\..\PixtelMMI\MMI\Inc
copy ..\MMI\Framework\Tasks\TasksInc\TaskInit.h ..\..\PixtelMMI\MMI\Inc
copy ..\MMI\Framework\Ems\EmsInc\ems.h ..\..\PixtelMMI\MMI\Inc
copy ..\Customer\CustomerInc\CustResDef.h ..\..\PixtelMMI\MMI\Inc
copy ..\Customer\CustomerInc\Resource.h ..\..\PixtelMMI\MMI\Inc
copy ..\MMI_Custom.h ..\..\PixtelMMI\MMI\Inc

echo Header Files Copied
copy files\* ..\..\PixtelMMI\MMI

echo --
echo RunSecond Complete!!
pause
exit