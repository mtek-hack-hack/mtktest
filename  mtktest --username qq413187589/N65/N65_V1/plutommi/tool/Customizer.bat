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
echo PC_Simulator from VSS before running this utility
mkdir ..\..\Customizer
mkdir ..\..\Customizer\MMI
mkdir ..\..\Customizer\MMI\Blankobj
mkdir ..\..\Customizer\MMI\Framework
mkdir ..\..\Customizer\MMI\Framework\NVRAMManager
mkdir ..\..\Customizer\MMI\Framework\NVRAMManager\NVRAM_DATA
mkdir ..\..\Customizer\MMI\SecondMMIObj
mkdir ..\..\Customizer\MMI\ExeSecondMMI
mkdir ..\..\Customizer\MMI\Debug
mkdir ..\..\Customizer\MMI\Inc
mkdir ..\..\Customizer\Customer
mkdir ..\..\Customizer\Customer\CustomerInc
mkdir ..\..\Customizer\Customer\CustResource
mkdir ..\..\Customizer\Customer\CustResource\PLUTO_MMI
mkdir ..\..\Customizer\Customer\Resources
mkdir ..\..\Customizer\Customer\Images
echo Directories Created

copy ..\Customer\CustResource\* ..\..\Customizer\Customer\CustResource
echo Copied CustResource Folder
xcopy ..\Customer\Customize ..\..\Customizer\Customer\Customize\ /f /e
echo Copied Customize Folder
xcopy ..\Customer\Images ..\..\Customizer\Customer\Images\ /f /e
echo Copied Images Folder
xcopy ..\MMI\libraries ..\..\Customizer\MMI\Libraries\ /f /e
echo Copied Libraries Folder
xcopy ..\Customer\Resources ..\..\Customizer\Customer\Resources\ /f /e
echo Copied Skin Pictures Folder
copy ..\MMI\Framework\NVRAMManager\NVRAM_DATA\* ..\..\Customizer\MMI\Framework\NVRAMManager\NVRAM_DATA
echo Copied NVRAMDATA Folder


copy ..\MMI\debug\mmicustomizer.dll ..\..\Customizer\MMI\Debug
echo copied mmicustomizer dll
copy ..\MMI\debug\QMMINWSimulator.dll ..\..\Customizer\MMI\Debug
echo copied QMMINWSimulator.dll
copy ..\MMI\debug\NWSimulator.dll ..\..\Customizer\MMI\Debug
echo copied NWSimulator.dll

copy ..\MMI\debug\*.* ..\..\Customizer\MMI\SecondMMIObj
copy ..\MMI\debug\phonebook.obj ..\..\Customizer\MMI\SecondMMIObj\phonebook_temp.obj
copy ..\MMI\debug\DemoApp.obj ..\..\Customizer\MMI\SecondMMIObj\DemoApp_temp.obj
copy ..\MMI\debug\PC_Simulator.exe ..\..\Customizer\MMI\Debug

echo copied obj files
del ..\..\Customizer\MMI\SecondMMIObj\CustImgMap.*
del ..\..\Customizer\MMI\SecondMMIObj\CustImgRes.*
del ..\..\Customizer\MMI\SecondMMIObj\CustMenuRes.*
del ..\..\Customizer\MMI\SecondMMIObj\CustStrMap.*
del ..\..\Customizer\MMI\SecondMMIObj\CustStrRes.*
del ..\..\Customizer\MMI\SecondMMIObj\FontRes.*
del ..\..\Customizer\MMI\SecondMMIObj\gui_wrapper.*
del ..\..\Customizer\MMI\SecondMMIObj\KeyMapDeclare.*
del ..\..\Customizer\MMI\SecondMMIObj\ThemeRes.*
del ..\..\Customizer\MMI\SecondMMIObj\ThemeResTable.*
del ..\..\Customizer\MMI\SecondMMIObj\*.dll
del ..\..\Customizer\MMI\SecondMMIObj\*.exe
del ..\..\Customizer\MMI\SecondMMIObj\*.res

copy ..\MMI\Inc\BuildCfg.h ..\..\Customizer\MMI\Inc
copy ..\MMI\Inc\CustDataRes.h ..\..\Customizer\MMI\Inc
copy ..\MMI\Inc\CustDataProts.h ..\..\Customizer\MMI\Inc
copy ..\MMI\Inc\CustMenuRes.h ..\..\Customizer\MMI\Inc
copy ..\MMI\Inc\CustThemesRes.h ..\..\Customizer\MMI\Inc
copy ..\MMI\Inc\FontDcl.h ..\..\Customizer\MMI\Inc
copy ..\MMI\Inc\FontRes.h ..\..\Customizer\MMI\Inc
copy ..\MMI\Inc\GlobalMenuItems.h ..\..\Customizer\MMI\Inc
copy ..\MMI\Inc\PixtelDataTypes.h ..\..\Customizer\MMI\Inc
copy ..\MMI\Inc\StdAfx.h ..\..\Customizer\MMI\Inc
copy ..\MMI\Inc\StdC.h ..\..\Customizer\MMI\Inc
copy ..\MMI\Inc\MMI_features.h ..\..\Customizer\MMI\Inc

copy ..\MMI\GUI\GUI_INC\gui.h ..\..\Customizer\MMI\Inc
copy ..\MMI\GUI\GUI_INC\gui_buttons.h ..\..\Customizer\MMI\Inc
copy ..\MMI\GUI\GUI_INC\gui_common_menus.h ..\..\Customizer\MMI\Inc
copy ..\MMI\GUI\GUI_INC\gui_config.h ..\..\Customizer\MMI\Inc
copy ..\MMI\GUI\GUI_INC\gui_custom_menus.h ..\..\Customizer\MMI\Inc
copy ..\MMI\GUI\GUI_INC\gui_data_types.h ..\..\Customizer\MMI\Inc
copy ..\MMI\GUI\GUI_INC\gui_ems.h ..\..\Customizer\MMI\Inc
copy ..\MMI\GUI\GUI_INC\gui_fixed_menuitems.h ..\..\Customizer\MMI\Inc
copy ..\MMI\GUI\GUI_INC\gui_fixed_menus.h ..\..\Customizer\MMI\Inc
copy ..\MMI\GUI\GUI_INC\gui_generic_menuitems.h ..\..\Customizer\MMI\Inc
copy ..\MMI\GUI\GUI_INC\gui_generic_menus.h ..\..\Customizer\MMI\Inc
copy ..\MMI\GUI\GUI_INC\gui_inputs.h ..\..\Customizer\MMI\Inc
copy ..\MMI\GUI\GUI_INC\gui_scrollbars.h ..\..\Customizer\MMI\Inc
copy ..\MMI\GUI\GUI_INC\gui_themes.h ..\..\Customizer\MMI\Inc
copy ..\MMI\GUI\GUI_INC\gui_windows.h ..\..\Customizer\MMI\Inc
copy ..\MtkApp\EngineerMode\EngineerModeInc\EMMenuItems.h ..\..\Customizer\MMI\Inc
copy ..\MtkApp\MtkAppInc\FMMenuItems.h ..\..\Customizer\MMI\Inc
copy ..\MtkApp\MtkAppInc\VMMenuItems.h ..\..\Customizer\MMI\Inc
copy ..\MtkApp\MtkAppInc\WAPMenuItems.h ..\..\Customizer\MMI\Inc
copy ..\MMI\EMS\EmsInc\ems.h ..\..\Customizer\MMI\Inc
copy ..\MMI\Framework\Osl\OslInc\OslMemory.h ..\..\Customizer\MMI\Inc
copy ..\MMI\Framework\Osl\OslInc\L4Dr.h ..\..\Customizer\MMI\Inc
copy ..\MMI\MiscFramework\MiscFrameworkInc\PixcomFontEngine.h ..\..\Customizer\MMI\Inc
copy ..\MMI\Framework\Tasks\TasksInc\TaskInit.h ..\..\Customizer\MMI\Inc
copy ..\MMI\Framework\Ems\EmsInc\ems.h ..\..\Customizer\MMI\Inc
copy ..\Customer\CustomerInc\CustResDef.h ..\..\Customizer\MMI\Inc
copy ..\Customer\CustomerInc\Resource.h ..\..\Customizer\MMI\Inc
copy ..\MMI_Custom.h ..\..\Customizer\MMI\Inc
copy ..\MMI\Organizer\OrganizerInc\worldclock.h ..\..\Customizer\MMI\Inc

echo Header Files Copied
copy files\* ..\..\Customizer\MMI

echo copy object file



echo --
echo Customizer copy Complete!!
pause
exit
