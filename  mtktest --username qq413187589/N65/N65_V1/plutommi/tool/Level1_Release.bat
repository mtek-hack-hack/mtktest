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
if /I "%3" EQU "LEVEL1" goto copy1
goto not_copy1

:copy1
	copy Tool\Run_Level1_Simulator.bat %2\plutommi\Run_Level1_Simulator.bat
	copy Tool\remakeL1Simulator.bat %2\plutommi\remakeL1Simulator.bat

:not_copy1

mkdir %2\plutommi\Customer
copy Customer\ResGenerator_HW_Level1.bat %2\plutommi\Customer\ResGenerator_HW.bat
mkdir %2\plutommi\Customer\CustomerInc
mkdir %2\plutommi\Customer\Customize
mkdir %2\plutommi\Customer\CustResource\
mkdir %2\plutommi\Customer\Images
mkdir %2\plutommi\Customer\ResGenerator
mkdir %2\plutommi\Customer\ResourceDLL

xcopy Customer\Images\%1 %2\plutommi\Customer\Images\%1\ /E /Q /Y
xcopy Customer\Images\Games %2\plutommi\Customer\Images\Games\ /E /Q /Y
copy Customer\Images\BMPLoad.exe %2\plutommi\Customer\Images\BMPLoad.exe
copy Customer\Images\GIFLoad.exe %2\plutommi\Customer\Images\GIFLoad.exe
copy Customer\Images\EMSLoad.exe %2\plutommi\Customer\Images\EMSLoad.exe
copy Customer\Images\Default.bmp %2\plutommi\Customer\Images\Default.bmp
copy Customer\Images\NoImage.bmp %2\plutommi\Customer\Images\NoImage.bmp
copy Customer\Images\EmptyImage.bmp %2\plutommi\Customer\Images\EmptyImage.bmp

xcopy Customer\Audio\%1 %2\plutommi\Customer\Audio\%1\ /E /Q /Y
copy Customer\Audio\Default.mp3 %2\plutommi\Customer\Audio\Default.mp3
copy Customer\Audio\NoAudio.mp3 %2\plutommi\Customer\Audio\NoAudio.mp3
copy Customer\Audio\EmptyAudio.mp3 %2\plutommi\Customer\Audio\EmptyAudio.mp3

copy Customer\Customize\GCML.txt %2\plutommi\Customer\Customize\GCML.txt
copy Customer\Customize\GCML.txt %2\plutommi\Customer\Customize\XMLconfig.ini

copy Customer\CustResource\%1_MMI\*.* %2\plutommi\Customer\CustResource\*.*
copy Customer\CustResource\FontType.c %2\plutommi\Customer\CustResource\FontType.c
copy Customer\CustResource\gui_wrapper.c %2\plutommi\Customer\CustResource\gui_wrapper.c
copy Customer\CustResource\CustMenuTree_Out.c %2\plutommi\Customer\CustResource\CustMenuTree_Out.c
copy Customer\CustResource\CustMenuTreeID_Out.c %2\plutommi\Customer\CustResource\CustMenuTreeID_Out.c
move %2\plutommi\Customer\CustResource\CustMiscData%1.c %2\plutommi\Customer\CustResource\CustMiscData.c
move %2\plutommi\Customer\CustResource\CustResDef%1.h %2\plutommi\Customer\CustomerInc\CustResDef.h
move %2\plutommi\Customer\CustResource\Gui_Setting%1.h %2\plutommi\Customer\CustomerInc\Gui_Setting.h
del  %2\plutommi\Customer\CustResource\MMI_features%1.h
rem move %2\plutommi\Customer\CustResource\ref_list.txt %2\plutommi\Customer\ResGenerator\ref_list.txt
del %2\plutommi\Customer\CustResource\Themecomponentsx.h
del %2\plutommi\Customer\CustResource\ThemeResTable.c

copy Customer\ResGenerator\readexcel.exe %2\plutommi\Customer\ResGenerator\readexcel.exe
copy Customer\ResGenerator\mtk_resgenerator.exe %2\plutommi\Customer\ResGenerator\mtk_resgenerator.exe
rem copy Customer\ResGenerator\CustResList_out.txt %2\plutommi\Customer\ResGenerator\ref_list.txt
copy Customer\ResGenerator\copy_images.bat %2\plutommi\Customer\ResGenerator\copy_images.bat

if /I "%3" EQU "LEVEL1" goto copy2
goto not_copy2

:copy2
mkdir %2\plutommi\Customer\ResourceDLL\Win32_Level1_Release

:not_copy2


if /I "%3" EQU "LEVEL2_OBJ" goto copy3
goto not_copy3

:copy3
   mkdir %2\plutommi\MMI\Release

:not_copy3
   

mkdir %2\plutommi\Customer\ResourceDLL\INC
copy Customer\ResourceDLL\ResourceDLL.def %2\plutommi\Customer\ResourceDLL\ResourceDLL.def
copy Customer\ResourceDLL\ResourceDLL.mak %2\plutommi\Customer\ResourceDLL\ResourceDLL.mak

xcopy MMI\framework\NVRAMManager\NVRAM_DATA %2\plutommi\MMI\framework\NVRAMManager\NVRAM_DATA\ /E /Q /Y
xcopy MMI\Melodies\*.* %2\plutommi\MMI\Melodies\ /E /Q /Y

mkdir %2\plutommi\MMI\framework\Osl\OslInc
copy MMI\framework\Osl\OslInc\OslMemory.h %2\plutommi\MMI\framework\Osl\OslInc\OslMemory.h

mkdir %2\plutommi\MMI\framework\Tasks\TasksInc
copy MMI\framework\Tasks\TasksInc\TaskInit.h %2\plutommi\MMI\framework\Tasks\TasksInc\TaskInit.h

if /I "%3" EQU "LEVEL1" goto copy4
goto not_copy4

:copy4
	mkdir %2\plutommi\MMI\Win32_Level1_Release
	copy MMI\Win32_Level1_Release\QMMINWSimulator.dll %2\plutommi\MMI\Win32_Level1_Release\QMMINWSimulator.dll
   copy MMI\Win32_Level1_Release\mmiresource.dll %2\plutommi\MMI\Win32_Level1_Release\mmiresource.dll
   copy MMI\Win32_Level1_Release\PC_Simulator.exe %2\plutommi\MMI\Win32_Level1_Release\PC_Simulator.exe  
:not_copy4

if /I "%3" EQU "LEVEL2_OBJ" goto copy5
goto not_copy5

:copy5
	mkdir %2\plutommi\MMI\Release
	copy MMI\Release\QMMINWSimulator.dll %2\plutommi\MMI\Release\QMMINWSimulator.dll
   copy MMI\Release\mmiresource.dll %2\plutommi\MMI\Release\mmiresource.dll
   copy MMI\Release\PC_Simulator.exe %2\plutommi\MMI\Release\PC_Simulator.exe
:not_copy5

xcopy MMI\Inc %2\plutommi\MMI\Inc\ /E /Q /Y


mkdir %2\plutommi\MMI\MiscFramework\MiscFrameworkInc
copy MMI\MiscFramework\MiscFrameworkInc\PixcomFontEngine.h %2\plutommi\MMI\MiscFramework\MiscFrameworkInc\PixcomFontEngine.h

mkdir %2\plutommi\MMI\GUI\GUI_INC
copy MMI\GUI\GUI_INC\gui_data_types.h %2\plutommi\MMI\GUI\GUI_INC\gui_data_types.h
copy MMI\GUI\GUI_INC\gui_config.h %2\plutommi\MMI\GUI\GUI_INC\gui_config.h
copy MMI\GUI\GUI_INC\gui.h %2\plutommi\MMI\GUI\GUI_INC\gui.h
copy MMI\GUI\GUI_INC\gui_themes.h %2\plutommi\MMI\GUI\GUI_INC\gui_themes.h
rem copy MMI\GUI\GUI_INC\theme_struct.h %2\plutommi\MMI\GUI\GUI_INC\theme_struct.h
copy MMI\GUI\GUI_INC\gui_theme_struct.h %2\plutommi\MMI\GUI\GUI_INC\gui_theme_struct.h
                                                                              
mkdir %2\plutommi\MMI\Organizer\OrganizerInc
copy MMI\Organizer\OrganizerInc\worldclock.h %2\plutommi\MMI\Organizer\OrganizerInc\worldclock.h

mkdir %2\plutommi\MtkApp\EngineerMode\EngineerModeInc
rem copy MtkApp\EngineerMode\EngineerModeInc\EMMenuItems.h %2\plutommi\MtkApp\EngineerMode\EngineerModeInc\EMMenuItems.h
rem copy MtkApp\EngineerMode\EngineerModeInc\FMMenuItems.h %2\plutommi\MtkApp\EngineerMode\EngineerModeInc\FMMenuItems.h

mkdir %2\plutommi\MtkApp\MtkAppInc
rem copy MtkApp\MtkAppInc\VMMenuItems.h %2\plutommi\MtkApp\MtkAppInc\VMMenuItems.h
rem copy MtkApp\MtkAppInc\WAPMenuItems.h %2\plutommi\MtkApp\MtkAppInc\WAPMenuItems.h

if /I "%3" EQU "LEVEL1" goto copy6
goto not_copy6

:copy6
	copy Tool\remakeL1Simulator.bat %2\plutommi\remakeL1Simulator.bat
	copy Tool\Run_Level1_Simulator.bat %2\plutommi\Run_Level1_Simulator.bat
:not_copy6

if /I "%3" EQU "LEVEL2_OBJ" goto copy7
goto not_copy7

:copy7
	copy Tool\remakeL2Simulator.bat %2\plutommi\remakeL1Simulator.bat
	copy Tool\Run_Level2_Simulator.bat %2\plutommi\Run_Level1_Simulator.bat
:not_copy7

rem ********************************************
rem **** Copy skins folder for pc simulator ****
rem ********************************************
if not exist %2\plutommi\MMI\Skins\ mkdir %2\plutommi\MMI\Skins\
xcopy MMI\Skins %2\plutommi\MMI\Skins\*.*  /E /Q /Y /I

cd tool
