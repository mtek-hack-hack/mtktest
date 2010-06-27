#
#  Copyright Statement:
#  --------------------
#  This software is protected by Copyright and the information contained
#  herein is confidential. The software may not be copied and the information
#  contained herein may not be used or disclosed except with the written
#  permission of MediaTek Inc. (C) 2005
#
#  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
#  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
#  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
#  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
#  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
#  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
#  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
#  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
#  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
#  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
#  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
#  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
#
#  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
#  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
#  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
#  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
#  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
#
#  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
#  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
#  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
#  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
#  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
#
#
# Microsoft Developer Studio Generated NMAKE File, Based on ResGenerator.dsp
!IF "$(CFG)" == ""
CFG=ResGenerator - Win32 Debug
!MESSAGE No configuration specified. Defaulting to ResGenerator - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "ResGenerator - Win32 Release" && "$(CFG)" != "ResGenerator - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
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
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "ResGenerator - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\ResGenerator.exe"


CLEAN :
	-@erase "$(INTDIR)\CustResDeclare.obj"
	-@erase "$(INTDIR)\Debug.obj"
	-@erase "$(INTDIR)\DebugInit.obj"
	-@erase "$(INTDIR)\ExportMMIFunc.obj"
	-@erase "$(INTDIR)\FontRes.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\PopulateRes.obj"
	-@erase "$(INTDIR)\ReadRes.obj"
	-@erase "$(INTDIR)\Res_Alarm.obj"
	-@erase "$(INTDIR)\Res_Calendar.obj"
	-@erase "$(INTDIR)\Res_CallManagement.obj"
	-@erase "$(INTDIR)\Res_Calls.obj"
	-@erase "$(INTDIR)\Res_CommonScreens.obj"
	-@erase "$(INTDIR)\Res_DataAccount.obj"
	-@erase "$(INTDIR)\Res_Ems.obj"
	-@erase "$(INTDIR)\Res_FunAndGames.obj"
	-@erase "$(INTDIR)\Res_Games.obj"
	-@erase "$(INTDIR)\Res_Gui.obj"
	-@erase "$(INTDIR)\Res_Help.obj"
	-@erase "$(INTDIR)\Res_IdleDemo.obj"
	-@erase "$(INTDIR)\Res_MainMenu.obj"
	-@erase "$(INTDIR)\Res_Messages.obj"
	-@erase "$(INTDIR)\Res_MiscFramework.obj"
	-@erase "$(INTDIR)\Res_MtkApp.obj"
	-@erase "$(INTDIR)\Res_NITZHandler.obj"
	-@erase "$(INTDIR)\Res_Organizer.obj"
	-@erase "$(INTDIR)\Res_PhoneBook.obj"
	-@erase "$(INTDIR)\Res_Profiles.obj"
	-@erase "$(INTDIR)\Res_SAT.obj"
	-@erase "$(INTDIR)\Res_Setting.obj"
	-@erase "$(INTDIR)\Res_Shortcuts.obj"
	-@erase "$(INTDIR)\Res_SSC.obj"
	-@erase "$(INTDIR)\Res_ToDoList.obj"
	-@erase "$(INTDIR)\ResGenerator.obj"
	-@erase "$(INTDIR)\ResGenerator.res"
	-@erase "$(INTDIR)\ResGeneratorDoc.obj"
	-@erase "$(INTDIR)\ResGeneratorView.obj"
	-@erase "$(INTDIR)\UCS2.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\WriteRes.obj"
	-@erase "$(OUTDIR)\ResGenerator.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\ResGenerator.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\ResGenerator.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ResGenerator.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\ResGenerator.pdb" /machine:I386 /out:"$(OUTDIR)\ResGenerator.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Res_Alarm.obj" \
	"$(INTDIR)\Res_Calendar.obj" \
	"$(INTDIR)\Res_CallManagement.obj" \
	"$(INTDIR)\Res_Calls.obj" \
	"$(INTDIR)\Res_CommonScreens.obj" \
	"$(INTDIR)\Res_DataAccount.obj" \
	"$(INTDIR)\Res_Ems.obj" \
	"$(INTDIR)\Res_FunAndGames.obj" \
	"$(INTDIR)\Res_Games.obj" \
	"$(INTDIR)\Res_Gui.obj" \
	"$(INTDIR)\Res_Help.obj" \
	"$(INTDIR)\Res_IdleDemo.obj" \
	"$(INTDIR)\Res_MainMenu.obj" \
	"$(INTDIR)\Res_Messages.obj" \
	"$(INTDIR)\Res_MiscFramework.obj" \
	"$(INTDIR)\Res_MtkApp.obj" \
	"$(INTDIR)\Res_NITZHandler.obj" \
	"$(INTDIR)\Res_Organizer.obj" \
	"$(INTDIR)\Res_PhoneBook.obj" \
	"$(INTDIR)\Res_Profiles.obj" \
	"$(INTDIR)\Res_SAT.obj" \
	"$(INTDIR)\Res_Setting.obj" \
	"$(INTDIR)\Res_Shortcuts.obj" \
	"$(INTDIR)\Res_SSC.obj" \
	"$(INTDIR)\Res_ToDoList.obj" \
	"$(INTDIR)\CustResDeclare.obj" \
	"$(INTDIR)\Debug.obj" \
	"$(INTDIR)\DebugInit.obj" \
	"$(INTDIR)\ExportMMIFunc.obj" \
	"$(INTDIR)\FontRes.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\PopulateRes.obj" \
	"$(INTDIR)\ReadRes.obj" \
	"$(INTDIR)\ResGenerator.obj" \
	"$(INTDIR)\ResGeneratorDoc.obj" \
	"$(INTDIR)\ResGeneratorView.obj" \
	"$(INTDIR)\UCS2.obj" \
	"$(INTDIR)\WriteRes.obj" \
	"$(INTDIR)\ResGenerator.res"

"$(OUTDIR)\ResGenerator.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "ResGenerator - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug

ALL : "..\Debug\ResGenerator.exe" "..\Debug\ResGenerator.bsc"


CLEAN :
	-@erase "$(INTDIR)\CustResDeclare.obj"
	-@erase "$(INTDIR)\CustResDeclare.sbr"
	-@erase "$(INTDIR)\Debug.obj"
	-@erase "$(INTDIR)\Debug.sbr"
	-@erase "$(INTDIR)\DebugInit.obj"
	-@erase "$(INTDIR)\DebugInit.sbr"
	-@erase "$(INTDIR)\ExportMMIFunc.obj"
	-@erase "$(INTDIR)\ExportMMIFunc.sbr"
	-@erase "$(INTDIR)\FontRes.obj"
	-@erase "$(INTDIR)\FontRes.sbr"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MainFrm.sbr"
	-@erase "$(INTDIR)\PopulateRes.obj"
	-@erase "$(INTDIR)\PopulateRes.sbr"
	-@erase "$(INTDIR)\ReadRes.obj"
	-@erase "$(INTDIR)\ReadRes.sbr"
	-@erase "$(INTDIR)\Res_Alarm.obj"
	-@erase "$(INTDIR)\Res_Alarm.sbr"
	-@erase "$(INTDIR)\Res_Calendar.obj"
	-@erase "$(INTDIR)\Res_Calendar.sbr"
	-@erase "$(INTDIR)\Res_CallManagement.obj"
	-@erase "$(INTDIR)\Res_CallManagement.sbr"
	-@erase "$(INTDIR)\Res_Calls.obj"
	-@erase "$(INTDIR)\Res_Calls.sbr"
	-@erase "$(INTDIR)\Res_CommonScreens.obj"
	-@erase "$(INTDIR)\Res_CommonScreens.sbr"
	-@erase "$(INTDIR)\Res_DataAccount.obj"
	-@erase "$(INTDIR)\Res_DataAccount.sbr"
	-@erase "$(INTDIR)\Res_Ems.obj"
	-@erase "$(INTDIR)\Res_Ems.sbr"
	-@erase "$(INTDIR)\Res_FunAndGames.obj"
	-@erase "$(INTDIR)\Res_FunAndGames.sbr"
	-@erase "$(INTDIR)\Res_Games.obj"
	-@erase "$(INTDIR)\Res_Games.sbr"
	-@erase "$(INTDIR)\Res_Gui.obj"
	-@erase "$(INTDIR)\Res_Gui.sbr"
	-@erase "$(INTDIR)\Res_Help.obj"
	-@erase "$(INTDIR)\Res_Help.sbr"
	-@erase "$(INTDIR)\Res_IdleDemo.obj"
	-@erase "$(INTDIR)\Res_IdleDemo.sbr"
	-@erase "$(INTDIR)\Res_MainMenu.obj"
	-@erase "$(INTDIR)\Res_MainMenu.sbr"
	-@erase "$(INTDIR)\Res_Messages.obj"
	-@erase "$(INTDIR)\Res_Messages.sbr"
	-@erase "$(INTDIR)\Res_MiscFramework.obj"
	-@erase "$(INTDIR)\Res_MiscFramework.sbr"
	-@erase "$(INTDIR)\Res_MtkApp.obj"
	-@erase "$(INTDIR)\Res_MtkApp.sbr"
	-@erase "$(INTDIR)\Res_NITZHandler.obj"
	-@erase "$(INTDIR)\Res_NITZHandler.sbr"
	-@erase "$(INTDIR)\Res_Organizer.obj"
	-@erase "$(INTDIR)\Res_Organizer.sbr"
	-@erase "$(INTDIR)\Res_PhoneBook.obj"
	-@erase "$(INTDIR)\Res_PhoneBook.sbr"
	-@erase "$(INTDIR)\Res_Profiles.obj"
	-@erase "$(INTDIR)\Res_Profiles.sbr"
	-@erase "$(INTDIR)\Res_SAT.obj"
	-@erase "$(INTDIR)\Res_SAT.sbr"
	-@erase "$(INTDIR)\Res_Setting.obj"
	-@erase "$(INTDIR)\Res_Setting.sbr"
	-@erase "$(INTDIR)\Res_Shortcuts.obj"
	-@erase "$(INTDIR)\Res_Shortcuts.sbr"
	-@erase "$(INTDIR)\Res_SSC.obj"
	-@erase "$(INTDIR)\Res_SSC.sbr"
	-@erase "$(INTDIR)\Res_ToDoList.obj"
	-@erase "$(INTDIR)\Res_ToDoList.sbr"
	-@erase "$(INTDIR)\ResGenerator.obj"
	-@erase "$(INTDIR)\ResGenerator.sbr"
	-@erase "$(INTDIR)\ResGeneratorDoc.obj"
	-@erase "$(INTDIR)\ResGeneratorDoc.sbr"
	-@erase "$(INTDIR)\ResGeneratorView.obj"
	-@erase "$(INTDIR)\ResGeneratorView.sbr"
	-@erase "$(INTDIR)\UCS2.obj"
	-@erase "$(INTDIR)\UCS2.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\WriteRes.obj"
	-@erase "$(INTDIR)\WriteRes.sbr"
	-@erase "$(OUTDIR)\ResGenerator.pdb"
	-@erase "..\Debug\ResGenerator.bsc"
	-@erase "..\Debug\ResGenerator.exe"
	-@erase "..\Debug\ResGenerator.ilk"
	-@erase "..\Debug\ResGenerator.res"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /I "..\customerinc" /I "..\..\MMI\DebugLevels\DebugLevelInc" /I "..\..\MMI\Calls\CallsInc" /I "..\..\MMI\Inc" /I "..\..\MtkApp\MtkAppInc" /I "..\..\MMI\Framework\osl\oslinc" /I "..\..\MMI\alarm\alarminc" /I "..\..\MMI\calendar\calendarinc" /I "..\..\MMI\CallManagement\CommonFiles\CommonInc" /I "..\..\MMI\CallManagement\OutgoingCallManagement\OutgoingInc" /I "..\..\MMI\CallManagement\IncomingCallManagement\IncomingInc" /I "..\..\MMI\Setting\SettingInc" /I "..\..\MMI\PhoneBook\PhoneBookInc" /I "..\..\MMI\CommonScreens\CommonScreensInc" /I "..\..\MMI\Framework\Tasks\TasksInc" /I "..\..\MMI\Framework\EventHandling\EventsInc" /I "..\..\MMI\Framework\History\HistoryInc" /I "..\..\MMI\DataAccount\DataAccountInc" /I "..\..\MMI\FunAndGames\FunAndGamesInc" /I "..\..\MMI\gui\gui_inc" /I "..\..\MMI\DateTime\DateTimeInc" /I "..\..\MMI\MiscFramework\MiscFrameworkInc" /I "..\..\MMI\Help\HelpInc" /I "..\..\MMI\IdleDemo\IdleDemoInc" /I "..\..\MMI\Messages\MessagesInc" /I "..\..\MMI\NITZHandler\NITZInc" /I "..\..\MMI\PROFILES\ProfilesInc" /I "..\..\MMI\SAT\SATInc" /I "..\..\MMI\Shortcuts\ShortcutsInc" /I "..\..\MMI\SSC\SSCInc" /I\
 "..\..\MMI\ToDoList\ToDoListInc" /I "..\..\MMI\Organizer\OrganizerInc" /I "..\..\MMI\CustResource" /I "..\..\MMI\FontData" /I "..\..\MMI\debuglevels\DebugLevelInc" /I "..\..\MMI\MainMenu\MainMenuInc" /I "..\..\MMI\ems\emsinc" /I "..\..\..\kal\include" /I "..\..\..\ps\interfaces\enum" /I "..\..\..\ps\l4\include" /I "..\..\..\ps\gen\mcd" /I "..\..\..\ps\interfaces\local_inc" /I "..\..\MMI\CPHS\CPHSInc" /I "..\..\MMI\audio\audioinc" /I "." /I "..\..\..\custom\audio\MT6208_CEVB" /I "..\Customize" /I "..\.." /I "..\..\..\custom\audio\CHICAGO2003_BB" /I "..\..\..\custom\audio\KLM2003_BB" /I "..\..\..\interface\mmi" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_CONSOLE" /D "__UCS2_ENCODING" /D "__RESOURCE_GEN_" /D "_L4_COMMON_STRUCT_H" /D "DEVELOPER_BUILD_FIRST_PASS" /D "__EM_MODE__" /D "MMI_ON_WIN32" /D "_AFXDLL" /D "__MOD_SMSAL__" /D "__SAT__" /D "SHORTCUTS_APP" /D "__POPULATE_ENGINE_" /D "DEBUG_WINDOW" /D "VM_SUPPORT" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\ResGenerator.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /Zm200 /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"../Debug/ResGenerator.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"../Debug/ResGenerator.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\Res_Alarm.sbr" \
	"$(INTDIR)\Res_Calendar.sbr" \
	"$(INTDIR)\Res_CallManagement.sbr" \
	"$(INTDIR)\Res_Calls.sbr" \
	"$(INTDIR)\Res_CommonScreens.sbr" \
	"$(INTDIR)\Res_DataAccount.sbr" \
	"$(INTDIR)\Res_Ems.sbr" \
	"$(INTDIR)\Res_FunAndGames.sbr" \
	"$(INTDIR)\Res_Games.sbr" \
	"$(INTDIR)\Res_Gui.sbr" \
	"$(INTDIR)\Res_Help.sbr" \
	"$(INTDIR)\Res_IdleDemo.sbr" \
	"$(INTDIR)\Res_MainMenu.sbr" \
	"$(INTDIR)\Res_Messages.sbr" \
	"$(INTDIR)\Res_MiscFramework.sbr" \
	"$(INTDIR)\Res_MtkApp.sbr" \
	"$(INTDIR)\Res_NITZHandler.sbr" \
	"$(INTDIR)\Res_Organizer.sbr" \
	"$(INTDIR)\Res_PhoneBook.sbr" \
	"$(INTDIR)\Res_Profiles.sbr" \
	"$(INTDIR)\Res_SAT.sbr" \
	"$(INTDIR)\Res_Setting.sbr" \
	"$(INTDIR)\Res_Shortcuts.sbr" \
	"$(INTDIR)\Res_SSC.sbr" \
	"$(INTDIR)\Res_ToDoList.sbr" \
	"$(INTDIR)\CustResDeclare.sbr" \
	"$(INTDIR)\Debug.sbr" \
	"$(INTDIR)\DebugInit.sbr" \
	"$(INTDIR)\ExportMMIFunc.sbr" \
	"$(INTDIR)\FontRes.sbr" \
	"$(INTDIR)\MainFrm.sbr" \
	"$(INTDIR)\PopulateRes.sbr" \
	"$(INTDIR)\ReadRes.sbr" \
	"$(INTDIR)\ResGenerator.sbr" \
	"$(INTDIR)\ResGeneratorDoc.sbr" \
	"$(INTDIR)\ResGeneratorView.sbr" \
	"$(INTDIR)\UCS2.sbr" \
	"$(INTDIR)\WriteRes.sbr"

"..\Debug\ResGenerator.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=MMICustomizer.lib /nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\ResGenerator.pdb" /debug /machine:I386 /out:"../Debug/ResGenerator.exe" /pdbtype:sept /libpath:"../customize" 
LINK32_OBJS= \
	"$(INTDIR)\Res_Alarm.obj" \
	"$(INTDIR)\Res_Calendar.obj" \
	"$(INTDIR)\Res_CallManagement.obj" \
	"$(INTDIR)\Res_Calls.obj" \
	"$(INTDIR)\Res_CommonScreens.obj" \
	"$(INTDIR)\Res_DataAccount.obj" \
	"$(INTDIR)\Res_Ems.obj" \
	"$(INTDIR)\Res_FunAndGames.obj" \
	"$(INTDIR)\Res_Games.obj" \
	"$(INTDIR)\Res_Gui.obj" \
	"$(INTDIR)\Res_Help.obj" \
	"$(INTDIR)\Res_IdleDemo.obj" \
	"$(INTDIR)\Res_MainMenu.obj" \
	"$(INTDIR)\Res_Messages.obj" \
	"$(INTDIR)\Res_MiscFramework.obj" \
	"$(INTDIR)\Res_MtkApp.obj" \
	"$(INTDIR)\Res_NITZHandler.obj" \
	"$(INTDIR)\Res_Organizer.obj" \
	"$(INTDIR)\Res_PhoneBook.obj" \
	"$(INTDIR)\Res_Profiles.obj" \
	"$(INTDIR)\Res_SAT.obj" \
	"$(INTDIR)\Res_Setting.obj" \
	"$(INTDIR)\Res_Shortcuts.obj" \
	"$(INTDIR)\Res_SSC.obj" \
	"$(INTDIR)\Res_ToDoList.obj" \
	"$(INTDIR)\CustResDeclare.obj" \
	"$(INTDIR)\Debug.obj" \
	"$(INTDIR)\DebugInit.obj" \
	"$(INTDIR)\ExportMMIFunc.obj" \
	"$(INTDIR)\FontRes.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\PopulateRes.obj" \
	"$(INTDIR)\ReadRes.obj" \
	"$(INTDIR)\ResGenerator.obj" \
	"$(INTDIR)\ResGeneratorDoc.obj" \
	"$(INTDIR)\ResGeneratorView.obj" \
	"$(INTDIR)\UCS2.obj" \
	"$(INTDIR)\WriteRes.obj" \
	"..\Debug\ResGenerator.res"

"..\Debug\ResGenerator.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("ResGenerator.dep")
!INCLUDE "ResGenerator.dep"
!ELSE 
!MESSAGE Warning: cannot find "ResGenerator.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "ResGenerator - Win32 Release" || "$(CFG)" == "ResGenerator - Win32 Debug"
SOURCE=..\Res_MMI\Res_Alarm.c

!IF  "$(CFG)" == "ResGenerator - Win32 Release"


"$(INTDIR)\Res_Alarm.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ResGenerator.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ResGenerator - Win32 Debug"


"$(INTDIR)\Res_Alarm.obj"	"$(INTDIR)\Res_Alarm.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\Res_MMI\Res_Calendar.c

!IF  "$(CFG)" == "ResGenerator - Win32 Release"


"$(INTDIR)\Res_Calendar.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ResGenerator.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ResGenerator - Win32 Debug"


"$(INTDIR)\Res_Calendar.obj"	"$(INTDIR)\Res_Calendar.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\Res_MMI\Res_CallManagement.c

!IF  "$(CFG)" == "ResGenerator - Win32 Release"


"$(INTDIR)\Res_CallManagement.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ResGenerator.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ResGenerator - Win32 Debug"


"$(INTDIR)\Res_CallManagement.obj"	"$(INTDIR)\Res_CallManagement.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\Res_MMI\Res_Calls.c

!IF  "$(CFG)" == "ResGenerator - Win32 Release"


"$(INTDIR)\Res_Calls.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ResGenerator.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ResGenerator - Win32 Debug"


"$(INTDIR)\Res_Calls.obj"	"$(INTDIR)\Res_Calls.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\Res_MMI\Res_CommonScreens.c

!IF  "$(CFG)" == "ResGenerator - Win32 Release"


"$(INTDIR)\Res_CommonScreens.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ResGenerator.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ResGenerator - Win32 Debug"


"$(INTDIR)\Res_CommonScreens.obj"	"$(INTDIR)\Res_CommonScreens.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\Res_MMI\Res_DataAccount.c

!IF  "$(CFG)" == "ResGenerator - Win32 Release"


"$(INTDIR)\Res_DataAccount.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ResGenerator.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ResGenerator - Win32 Debug"


"$(INTDIR)\Res_DataAccount.obj"	"$(INTDIR)\Res_DataAccount.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\Res_MMI\Res_Ems.c

!IF  "$(CFG)" == "ResGenerator - Win32 Release"


"$(INTDIR)\Res_Ems.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ResGenerator.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ResGenerator - Win32 Debug"


"$(INTDIR)\Res_Ems.obj"	"$(INTDIR)\Res_Ems.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\Res_MMI\Res_FunAndGames.c

!IF  "$(CFG)" == "ResGenerator - Win32 Release"


"$(INTDIR)\Res_FunAndGames.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ResGenerator.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ResGenerator - Win32 Debug"


"$(INTDIR)\Res_FunAndGames.obj"	"$(INTDIR)\Res_FunAndGames.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\Res_MMI\Res_Games.c

!IF  "$(CFG)" == "ResGenerator - Win32 Release"


"$(INTDIR)\Res_Games.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ResGenerator.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ResGenerator - Win32 Debug"


"$(INTDIR)\Res_Games.obj"	"$(INTDIR)\Res_Games.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\Res_MMI\Res_Gui.c

!IF  "$(CFG)" == "ResGenerator - Win32 Release"


"$(INTDIR)\Res_Gui.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ResGenerator.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ResGenerator - Win32 Debug"


"$(INTDIR)\Res_Gui.obj"	"$(INTDIR)\Res_Gui.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\Res_MMI\Res_Help.c

!IF  "$(CFG)" == "ResGenerator - Win32 Release"


"$(INTDIR)\Res_Help.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ResGenerator.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ResGenerator - Win32 Debug"


"$(INTDIR)\Res_Help.obj"	"$(INTDIR)\Res_Help.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\Res_MMI\Res_IdleDemo.c

!IF  "$(CFG)" == "ResGenerator - Win32 Release"


"$(INTDIR)\Res_IdleDemo.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ResGenerator.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ResGenerator - Win32 Debug"


"$(INTDIR)\Res_IdleDemo.obj"	"$(INTDIR)\Res_IdleDemo.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\Res_MMI\Res_MainMenu.c

!IF  "$(CFG)" == "ResGenerator - Win32 Release"


"$(INTDIR)\Res_MainMenu.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ResGenerator.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ResGenerator - Win32 Debug"


"$(INTDIR)\Res_MainMenu.obj"	"$(INTDIR)\Res_MainMenu.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\Res_MMI\Res_Messages.c

!IF  "$(CFG)" == "ResGenerator - Win32 Release"


"$(INTDIR)\Res_Messages.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ResGenerator.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ResGenerator - Win32 Debug"


"$(INTDIR)\Res_Messages.obj"	"$(INTDIR)\Res_Messages.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\Res_MMI\Res_MiscFramework.c

!IF  "$(CFG)" == "ResGenerator - Win32 Release"


"$(INTDIR)\Res_MiscFramework.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ResGenerator.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ResGenerator - Win32 Debug"


"$(INTDIR)\Res_MiscFramework.obj"	"$(INTDIR)\Res_MiscFramework.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\Res_MMI\Res_MtkApp.c

!IF  "$(CFG)" == "ResGenerator - Win32 Release"


"$(INTDIR)\Res_MtkApp.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ResGenerator.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ResGenerator - Win32 Debug"


"$(INTDIR)\Res_MtkApp.obj"	"$(INTDIR)\Res_MtkApp.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\Res_MMI\Res_NITZHandler.c

!IF  "$(CFG)" == "ResGenerator - Win32 Release"


"$(INTDIR)\Res_NITZHandler.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ResGenerator.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ResGenerator - Win32 Debug"


"$(INTDIR)\Res_NITZHandler.obj"	"$(INTDIR)\Res_NITZHandler.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\Res_MMI\Res_Organizer.c

!IF  "$(CFG)" == "ResGenerator - Win32 Release"


"$(INTDIR)\Res_Organizer.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ResGenerator.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ResGenerator - Win32 Debug"


"$(INTDIR)\Res_Organizer.obj"	"$(INTDIR)\Res_Organizer.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\Res_MMI\Res_PhoneBook.c

!IF  "$(CFG)" == "ResGenerator - Win32 Release"


"$(INTDIR)\Res_PhoneBook.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ResGenerator.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ResGenerator - Win32 Debug"


"$(INTDIR)\Res_PhoneBook.obj"	"$(INTDIR)\Res_PhoneBook.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\Res_MMI\Res_Profiles.c

!IF  "$(CFG)" == "ResGenerator - Win32 Release"


"$(INTDIR)\Res_Profiles.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ResGenerator.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ResGenerator - Win32 Debug"


"$(INTDIR)\Res_Profiles.obj"	"$(INTDIR)\Res_Profiles.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\Res_MMI\Res_SAT.c

!IF  "$(CFG)" == "ResGenerator - Win32 Release"


"$(INTDIR)\Res_SAT.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ResGenerator.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ResGenerator - Win32 Debug"


"$(INTDIR)\Res_SAT.obj"	"$(INTDIR)\Res_SAT.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\Res_MMI\Res_Setting.c

!IF  "$(CFG)" == "ResGenerator - Win32 Release"


"$(INTDIR)\Res_Setting.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ResGenerator.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ResGenerator - Win32 Debug"


"$(INTDIR)\Res_Setting.obj"	"$(INTDIR)\Res_Setting.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\Res_MMI\Res_Shortcuts.c

!IF  "$(CFG)" == "ResGenerator - Win32 Release"


"$(INTDIR)\Res_Shortcuts.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ResGenerator.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ResGenerator - Win32 Debug"


"$(INTDIR)\Res_Shortcuts.obj"	"$(INTDIR)\Res_Shortcuts.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\Res_MMI\Res_SSC.c

!IF  "$(CFG)" == "ResGenerator - Win32 Release"


"$(INTDIR)\Res_SSC.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ResGenerator.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ResGenerator - Win32 Debug"


"$(INTDIR)\Res_SSC.obj"	"$(INTDIR)\Res_SSC.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\Res_MMI\Res_ToDoList.c

!IF  "$(CFG)" == "ResGenerator - Win32 Release"


"$(INTDIR)\Res_ToDoList.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ResGenerator.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ResGenerator - Win32 Debug"


"$(INTDIR)\Res_ToDoList.obj"	"$(INTDIR)\Res_ToDoList.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\CustResDeclare.c

!IF  "$(CFG)" == "ResGenerator - Win32 Release"


"$(INTDIR)\CustResDeclare.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ResGenerator.pch"


!ELSEIF  "$(CFG)" == "ResGenerator - Win32 Debug"


"$(INTDIR)\CustResDeclare.obj"	"$(INTDIR)\CustResDeclare.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=..\..\MMI\DebugLevels\DebugLevelSrc\Debug.cpp

!IF  "$(CFG)" == "ResGenerator - Win32 Release"


"$(INTDIR)\Debug.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ResGenerator.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ResGenerator - Win32 Debug"


"$(INTDIR)\Debug.obj"	"$(INTDIR)\Debug.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\MMI\DebugLevels\DebugLevelSrc\DebugInit.c

!IF  "$(CFG)" == "ResGenerator - Win32 Release"


"$(INTDIR)\DebugInit.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ResGenerator.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ResGenerator - Win32 Debug"


"$(INTDIR)\DebugInit.obj"	"$(INTDIR)\DebugInit.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\ExportMMIFunc.c

!IF  "$(CFG)" == "ResGenerator - Win32 Release"


"$(INTDIR)\ExportMMIFunc.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ResGenerator.pch"


!ELSEIF  "$(CFG)" == "ResGenerator - Win32 Debug"


"$(INTDIR)\ExportMMIFunc.obj"	"$(INTDIR)\ExportMMIFunc.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=..\CustResource\FontRes.c

!IF  "$(CFG)" == "ResGenerator - Win32 Release"


"$(INTDIR)\FontRes.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ResGenerator.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ResGenerator - Win32 Debug"


"$(INTDIR)\FontRes.obj"	"$(INTDIR)\FontRes.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\MainFrm.cpp

!IF  "$(CFG)" == "ResGenerator - Win32 Release"


"$(INTDIR)\MainFrm.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ResGenerator.pch"


!ELSEIF  "$(CFG)" == "ResGenerator - Win32 Debug"


"$(INTDIR)\MainFrm.obj"	"$(INTDIR)\MainFrm.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=..\..\MMI\Resource\PopulateRes.c

!IF  "$(CFG)" == "ResGenerator - Win32 Release"


"$(INTDIR)\PopulateRes.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ResGenerator.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ResGenerator - Win32 Debug"


"$(INTDIR)\PopulateRes.obj"	"$(INTDIR)\PopulateRes.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\MMI\Resource\ReadRes.c

!IF  "$(CFG)" == "ResGenerator - Win32 Release"


"$(INTDIR)\ReadRes.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ResGenerator.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ResGenerator - Win32 Debug"


"$(INTDIR)\ReadRes.obj"	"$(INTDIR)\ReadRes.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\ResGenerator.cpp

!IF  "$(CFG)" == "ResGenerator - Win32 Release"


"$(INTDIR)\ResGenerator.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ResGenerator.pch"


!ELSEIF  "$(CFG)" == "ResGenerator - Win32 Debug"


"$(INTDIR)\ResGenerator.obj"	"$(INTDIR)\ResGenerator.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\ResGenerator.rc

!IF  "$(CFG)" == "ResGenerator - Win32 Release"


"$(INTDIR)\ResGenerator.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ResGenerator - Win32 Debug"


"..\Debug\ResGenerator.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\ResGeneratorDoc.cpp

!IF  "$(CFG)" == "ResGenerator - Win32 Release"


"$(INTDIR)\ResGeneratorDoc.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ResGenerator.pch"


!ELSEIF  "$(CFG)" == "ResGenerator - Win32 Debug"


"$(INTDIR)\ResGeneratorDoc.obj"	"$(INTDIR)\ResGeneratorDoc.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\ResGeneratorView.cpp

!IF  "$(CFG)" == "ResGenerator - Win32 Release"


"$(INTDIR)\ResGeneratorView.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ResGenerator.pch"


!ELSEIF  "$(CFG)" == "ResGenerator - Win32 Debug"


"$(INTDIR)\ResGeneratorView.obj"	"$(INTDIR)\ResGeneratorView.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=..\..\MMI\MiscFramework\MiscFrameworkSrc\UCS2.c

!IF  "$(CFG)" == "ResGenerator - Win32 Release"


"$(INTDIR)\UCS2.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ResGenerator.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ResGenerator - Win32 Debug"


"$(INTDIR)\UCS2.obj"	"$(INTDIR)\UCS2.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\MMI\Resource\WriteRes.c

!IF  "$(CFG)" == "ResGenerator - Win32 Release"


"$(INTDIR)\WriteRes.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ResGenerator.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ResGenerator - Win32 Debug"


"$(INTDIR)\WriteRes.obj"	"$(INTDIR)\WriteRes.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 


!ENDIF 

