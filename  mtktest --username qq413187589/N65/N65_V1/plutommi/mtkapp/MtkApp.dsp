# Microsoft Developer Studio Project File - Name="MtkApp" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=MtkApp - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "MtkApp.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "MtkApp.mak" CFG="MtkApp - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "MtkApp - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "MtkApp - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "MtkApp - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD BASE RSC /l 0x404 /d "NDEBUG"
# ADD RSC /l 0x404 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "MtkApp - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ  /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /I "..\MMI\DataAccount\DataAccountInc" /I "..\MMI\IdleScreen\IdleScreenInc\DemoAppInc" /I "..\MMI\Inc" /I "..\MMI\Setting\SettingInc" /I "..\MMI\Help\HelpInc" /I "..\MMI\Connect\ConnectInc" /I "..\MMI\Calls\CallsInc" /I "..\MMI\FunAndGames\FunAndGamesInc" /I "..\MMI\Src" /I "..\MMI\Framework\Osl\OslSrc" /I "..\MMI\Framework\FileSystem\FileSystemInc" /I "..\MMI\resources" /I "..\MMI\Call\CallInc" /I "..\MMI\PhoneBook\PhoneBookInc" /I "..\MMI\Framework\NVRAMManager\NVRAMManagerInc" /I "..\MMI\..\MtkApp\MtkAppInc" /I "..\MMI\Framework\Osl\OslInc" /I "..\MMI\MiscFramework\MiscFrameworkInc" /I "..\MMI\MainMenu\MainMenuInc" /I "..\MMI\Settings\SettingsInc" /I "..\MMI\PROFILES\ProfilesInc" /I "..\MMI\Framework\Tasks\TasksInc" /I "..\MMI\CustResource" /I "..\MMI\Framework\EventHandling\EventsInc" /I "..\MMI\Framework\History\HistoryInc" /I "..\MMI\IdleScreen\IdleScreenInc" /I "..\MMI\gui\gui_Inc" /I "..\MMI\ProtocolEvents\ProtocolEventsInc" /I "..\MMI\debuglevels\DebugLevelInc" /I "..\MMI\FontData" /I "..\MMI\.\AsyncEvents\AsyncEventsInc\\" /I "..\MMI\.\CallManagement\OutgoingCallManagement\OutgoingInc\\" /I "..\MMI\.\CallManagement\IncomingCallManagement\IncomingInc\\" /I "..\MMI\Audio\AudioInc" /I "..\MMI\DateTime\DateTimeInc" /I "..\MMI\Messages\MessagesInc" /I "..\MMI\.\CallManagement\CommonFiles\CommonInc" /I "..\MMI\.\Customize" /I "..\MMI\EMS\EMSInc\\" /I "..\MMI\SAT\SATInc" /I "..\MMI\Shortcuts\ShortcutsInc" /I "..\MMI\GPIO\GPIOInc" /I "..\MMI\SSC\SSCInc" /I "..\MMI\Organizer\OrganizerInc" /I "..\MMI\Alarm\AlarmInc" /I "..\MMI\Calendar\CalendarInc" /I "..\MMI\ToDoList\ToDoListInc" /I "..\MMI\ATHandler\ATHandlerInc" /I "..\MMI\NITZHandler\NITZInc" /I "..\MMI\CPHS\CPHSInc" /I "..\MMI\CommonScreens\CommonScreensInc" /I "..\..\custom\include" /I "..\..\adaptation\include" /I "..\..\interface\mmi" /I "..\..\config\include" /I "..\..\drv\include" /I "..\..\init\include" /I "..\..\interface\hwdrv" /I "..\..\interface\l1interface" /I "..\..\interface\os" /I "..\..\nucleus\inc" /I "..\..\kal\common\include" /I "..\..\kal\include" /I "..\..\kal\nucleus\include" /I "..\..\interface\ps" /I "..\..\ps\config\include" /I "..\..\ps\flow_ctrl\include" /I "..\..\ps\gen\sme_tt" /I "..\..\ps\interfaces\enum" /I "..\..\ps\interfaces\local_inc" /I "..\..\ps\l4\csm\cc\include" /I "..\..\ps\l4\include" /I "..\..\ps\l4\l4c\include\common" /I "..\..\ps\l4\l4c\include\mmi" /I "..\..\ps\l4\smsal\include" /I "..\..\ps\tools\asn1lib\include" /I "..\..\stacklib\include" /I "..\..\tst\database\pstrace_db" /I "..\..\tst\include" /I "..\..\mtk_lib" /I "..\..\ps\l4\phb\include" /I ".\..\..\custom\audio\MT6208_CEVB" /I "..\..\ps\gen\mcd" /I ".\..\..\custom\app\MT6208_CEVB" /I "..\Customer\Customize" /I "..\Customer\CustomerInc" /I ".\.." /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "DEBUG_TRACE" /D "DEBUG_WINDOW" /D "DEBUG_INFORMATION" /D "DEVELOPER_BUILD" /D "MMI_ON_WIN32" /D "__UCS2_ENCODING" /D "EMS_ON_WIN32" /D "__EMS__" /D "SIM_APP_TOOLKIT" /D "CM_APPLICATION_ENABLE" /D "SHORTCUTS_APP" /D "__MCD__" /D "DEBUG_KAL" /D "MT6208" /D "__GSM_MODE__" /D "__MOD_L4C__" /D "__CUSTOM_RELEASE__" /D "__MOD_SMU__" /D "REASM_NOT_PRESENT" /D "DATA_NOT_PRESENT" /D "__MOD_SMS__" /D "PPP_NOT_PRESENT" /D "IDMA_DOWNLOAD" /D "__MOD_NVRAM__" /D "MTK_KAL" /D "SPLIT_SYS" /D "PIXTEL_HARDWARE" /D "MTK_KAL_MNT" /D "__MOD_CSM__" /D "__MMI_SMI__" /D DEBUG_LEVEL=0 /D "MP3_SUPPORT" /D "BRIGHT4_RF" /D "SME_NOT_PRESENT" /D "__TST_MODULE__" /D "SME_READER_NOT_PRESENT" /D "COLOR_LCD" /D "TARGET_BUILD" /D "__MOD_SMSAL__" /D "__MOD_PHB__" /D "__SYS_INTERN_RAM__" /D "IDLE_TASK" /D "STDC_HEADERS" /D "_CISS__" /D "__FS_OFF__" /D "NU_NO_ERROR_CHECKING" /D "DEBUG_ITC" /D "__MOD_MM__" /D "LLC_NOT_PRESENT" /D "__CPHS__" /D "MPLL_52M" /D "__MOD_SIM__" /D "FLASH_CODE" /D "__MOD_CC__" /D "__MOD_RAC__" /D "DEBUG_BUF2" /D "MT6208_CEVB" /D "__CB_MMI_MASK__" /D "SNDCP_NOT_PRESENT" /D "__MOD_UEM__" /D "__CB__" /D "__EM_MODE__" /D "MTK_NEW_API" /D "DEBUG_BUF" /D "__SAT__" /D "DUT_ON_TARGET" /D "KAL_ON_NUCLEUS" /D "SM_NOT_PRESENT" /D "__TCPIP__" /YX /FD /GZ  /c
# ADD BASE RSC /l 0x404 /d "_DEBUG"
# ADD RSC /l 0x404 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ENDIF 

# Begin Target

# Name "MtkApp - Win32 Release"
# Name "MtkApp - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\MtkAppSrc\EngineerModeDeviceSrc.c
# End Source File
# Begin Source File

SOURCE=.\MtkAppSrc\EngineerModeMsgHandler.c
# End Source File
# Begin Source File

SOURCE=.\MtkAppSrc\EngineerModeSocketApp.c
# End Source File
# Begin Source File

SOURCE=.\MtkAppSrc\EngineerModeSrc.c
# End Source File
# Begin Source File

SOURCE=.\MtkAppSrc\FactoryModeMsgSrc.c
# End Source File
# Begin Source File

SOURCE=.\MtkAppSrc\FactoryModeSrc.c
# End Source File
# Begin Source File

SOURCE=.\MtkAppSrc\MMIFrameworkMsgHandler.c
# End Source File
# Begin Source File

SOURCE=.\MtkAppSrc\VoiceMemoMsgHandler.c
# End Source File
# Begin Source File

SOURCE=.\MtkAppSrc\VoiceMemoSrc.c
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\MtkAppInc\EMMenuItems.h
# End Source File
# Begin Source File

SOURCE=.\MtkAppInc\EngineerModeDef.h
# End Source File
# Begin Source File

SOURCE=.\MtkAppInc\EngineerModeDeviceInc.h
# End Source File
# Begin Source File

SOURCE=.\MtkAppInc\EngineerModeProt.h
# End Source File
# Begin Source File

SOURCE=.\MtkAppInc\EngineerModeSocketApp.h
# End Source File
# Begin Source File

SOURCE=.\MtkAppInc\EngineerModeSocketAppPing.h
# End Source File
# Begin Source File

SOURCE=.\MtkAppInc\EngineerModeType.h
# End Source File
# Begin Source File

SOURCE=.\MtkAppInc\FactoryModeDef.h
# End Source File
# Begin Source File

SOURCE=.\MtkAppInc\FactoryModeProt.h
# End Source File
# Begin Source File

SOURCE=.\MtkAppInc\FMMenuItems.h
# End Source File
# Begin Source File

SOURCE=.\MtkAppInc\MMIFrameworkMsgHandlerProt.h
# End Source File
# Begin Source File

SOURCE=.\MtkAppInc\MMIFrameworkSap.h
# End Source File
# Begin Source File

SOURCE=.\MtkAppInc\MMIFrameworkStruct.h
# End Source File
# Begin Source File

SOURCE=.\MtkAppInc\t9def.h
# End Source File
# Begin Source File

SOURCE=.\MtkAppInc\VMMenuItems.h
# End Source File
# Begin Source File

SOURCE=.\MtkAppInc\VoiceMemoDef.h
# End Source File
# Begin Source File

SOURCE=.\MtkAppInc\VoiceMemoProt.h
# End Source File
# Begin Source File

SOURCE=.\MtkAppInc\VoiceMemoType.h
# End Source File
# Begin Source File

SOURCE=.\MtkAppInc\Wap.h
# End Source File
# Begin Source File

SOURCE=.\MtkAppInc\WAPMenuItems.h
# End Source File
# End Group
# End Target
# End Project
