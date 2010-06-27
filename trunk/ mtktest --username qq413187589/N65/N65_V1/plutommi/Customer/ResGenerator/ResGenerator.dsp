# Microsoft Developer Studio Project File - Name="ResGenerator" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=ResGenerator - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "ResGenerator.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "ResGenerator.mak" CFG="ResGenerator - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ResGenerator - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "ResGenerator - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName "Perforce Project"
# PROP Scc_LocalPath "."
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "ResGenerator - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "ResGenerator - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "..\customerinc" /I "..\..\MMI\DebugLevels\DebugLevelInc" /I "..\..\MMI\Calls\CallsInc" /I "..\..\MMI\Inc" /I "..\..\MtkApp\MtkAppInc" /I "..\..\MMI\Framework\osl\oslinc" /I "..\..\MMI\alarm\alarminc" /I "..\..\MMI\calendar\calendarinc" /I "..\..\MMI\CallManagement\CommonFiles\CommonInc" /I "..\..\MMI\CallManagement\OutgoingCallManagement\OutgoingInc" /I "..\..\MMI\CallManagement\IncomingCallManagement\IncomingInc" /I "..\..\MMI\Setting\SettingInc" /I "..\..\MMI\PhoneBook\PhoneBookInc" /I "..\..\MMI\CommonScreens\CommonScreensInc" /I "..\..\MMI\Framework\Tasks\TasksInc" /I "..\..\MMI\Framework\EventHandling\EventsInc" /I "..\..\MMI\Framework\History\HistoryInc" /I "..\..\MMI\DataAccount\DataAccountInc" /I "..\..\MMI\FunAndGames\FunAndGamesInc" /I "..\..\MMI\gui\gui_inc" /I "..\..\MMI\DateTime\DateTimeInc" /I "..\..\MMI\MiscFramework\MiscFrameworkInc" /I "..\..\MMI\Help\HelpInc" /I "..\..\MMI\IdleScreen\IdleScreenInc" /I "..\..\MMI\Messages\MessagesInc" /I "..\..\MMI\NITZHandler\NITZInc" /I "..\..\MMI\PROFILES\ProfilesInc" /I "..\..\MMI\SAT\SATInc" /I "..\..\MMI\Shortcuts\ShortcutsInc" /I "..\..\MMI\SSC\SSCInc" /I "..\..\MMI\ToDoList\ToDoListInc" /I "..\..\MMI\Organizer\OrganizerInc" /I "..\..\MMI\CustResource" /I "..\..\MMI\FontData" /I "..\..\MMI\debuglevels\DebugLevelInc" /I "..\..\MMI\MainMenu\MainMenuInc" /I "..\..\MMI\ems\emsinc" /I "..\..\..\kal\include" /I "..\..\..\ps\interfaces\enum" /I "..\..\..\ps\l4\include" /I "..\..\..\ps\gen\mcd" /I "..\..\..\ps\interfaces\local_inc" /I "..\..\MMI\CPHS\CPHSInc" /I "..\..\MMI\audio\audioinc" /I "." /I "..\..\..\custom\audio\MT6208_CEVB" /I "..\Customize" /I "..\.." /I "..\..\..\custom\audio\CHICAGO2003_BB" /I "..\..\..\custom\audio\KLM2003_BB" /I "..\..\..\interface\mmi" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_CONSOLE" /D "__UCS2_ENCODING" /D "__RESOURCE_GEN_" /D "_L4_COMMON_STRUCT_H" /D "DEVELOPER_BUILD_FIRST_PASS" /D "__EM_MODE__" /D "MMI_ON_WIN32" /D "_AFXDLL" /D "__MOD_SMSAL__" /D "__SAT__" /D "SHORTCUTS_APP" /D "__POPULATE_ENGINE_" /D "DEBUG_WINDOW" /D "VM_SUPPORT" /FR /YX /FD /GZ /Zm200 /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /fo"../Debug/ResGenerator.res" /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"../Debug/ResGenerator.bsc"
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 MMICustomizer.lib /nologo /subsystem:windows /debug /machine:I386 /out:"../Debug/ResGenerator.exe" /pdbtype:sept /libpath:"../customize"

!ENDIF 

# Begin Target

# Name "ResGenerator - Win32 Release"
# Name "ResGenerator - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Group "PLUTO_MMI"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\Res_MMI\Res_Alarm.c
# End Source File
# Begin Source File

SOURCE=..\Res_MMI\Res_Calendar.c
# End Source File
# Begin Source File

SOURCE=..\Res_MMI\Res_CallManagement.c
# End Source File
# Begin Source File

SOURCE=..\Res_MMI\Res_Calls.c
# End Source File
# Begin Source File

SOURCE=..\Res_MMI\Res_CommonScreens.c
# End Source File
# Begin Source File

SOURCE=..\Res_MMI\Res_DataAccount.c
# End Source File
# Begin Source File

SOURCE=..\Res_MMI\Res_Ems.c
# End Source File
# Begin Source File

SOURCE=..\Res_MMI\Res_FunAndGames.c
# End Source File
# Begin Source File

SOURCE=..\Res_MMI\Res_Games.c
# End Source File
# Begin Source File

SOURCE=..\Res_MMI\Res_Gui.c
# End Source File
# Begin Source File

SOURCE=..\Res_MMI\Res_Help.c
# End Source File
# Begin Source File

SOURCE=..\Res_MMI\Res_IdleScreen.c
# End Source File
# Begin Source File

SOURCE=..\Res_MMI\Res_MainMenu.c
# End Source File
# Begin Source File

SOURCE=..\Res_MMI\Res_Messages.c
# End Source File
# Begin Source File

SOURCE=..\Res_MMI\Res_MiscFramework.c
# End Source File
# Begin Source File

SOURCE=..\Res_MMI\Res_MtkApp.c
# End Source File
# Begin Source File

SOURCE=..\Res_MMI\Res_NITZHandler.c
# End Source File
# Begin Source File

SOURCE=..\Res_MMI\Res_Organizer.c
# End Source File
# Begin Source File

SOURCE=..\Res_MMI\Res_PhoneBook.c
# End Source File
# Begin Source File

SOURCE=..\Res_MMI\Res_Profiles.c
# End Source File
# Begin Source File

SOURCE=..\Res_MMI\Res_SAT.c
# End Source File
# Begin Source File

SOURCE=..\Res_MMI\Res_Setting.c
# End Source File
# Begin Source File

SOURCE=..\Res_MMI\Res_Shortcuts.c
# End Source File
# Begin Source File

SOURCE=..\Res_MMI\Res_SSC.c
# End Source File
# Begin Source File

SOURCE=..\Res_MMI\Res_ToDoList.c
# End Source File
# End Group
# Begin Source File

SOURCE=.\CustResDeclare.c
# End Source File
# Begin Source File

SOURCE=..\..\MMI\DebugLevels\DebugLevelSrc\Debug.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MMI\DebugLevels\DebugLevelSrc\DebugInit.c
# End Source File
# Begin Source File

SOURCE=.\ExportMMIFunc.c
# End Source File
# Begin Source File

SOURCE=..\CustResource\FontRes.c
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MMI\Resource\PopulateRes.c
# End Source File
# Begin Source File

SOURCE=..\..\MMI\Resource\ReadRes.c
# End Source File
# Begin Source File

SOURCE=.\ResGenerator.cpp
# End Source File
# Begin Source File

SOURCE=.\ResGenerator.rc
# End Source File
# Begin Source File

SOURCE=.\ResGeneratorDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\ResGeneratorView.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MMI\MiscFramework\MiscFrameworkSrc\UCS2.c
# End Source File
# Begin Source File

SOURCE=..\..\MMI\Resource\WriteRes.c
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\ExportMMIFunc.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\ResGenerator.h
# End Source File
# Begin Source File

SOURCE=.\ResGeneratorDoc.h
# End Source File
# Begin Source File

SOURCE=.\ResGeneratorView.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\ResGenerator.ico
# End Source File
# Begin Source File

SOURCE=.\Resources\ResGenerator.ico
# End Source File
# Begin Source File

SOURCE=.\Resources\ResGenerator.rc2
# End Source File
# Begin Source File

SOURCE=.\res\ResGeneratorDoc.ico
# End Source File
# Begin Source File

SOURCE=.\Resources\ResGeneratorDoc.ico
# End Source File
# Begin Source File

SOURCE=.\Resources\Toolbar.bmp
# End Source File
# End Group
# End Target
# End Project
