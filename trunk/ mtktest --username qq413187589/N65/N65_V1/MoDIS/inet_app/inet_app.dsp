# Microsoft Developer Studio Project File - Name="inet_app" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=inet_app - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "inet_app.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "inet_app.mak" CFG="inet_app - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "inet_app - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "inet_app - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "inet_app - Win32 Release"
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
# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /Zi /W2 /Od /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" 
# ADD CPP @"inet_app.ini"
# ADD CPP /FD /GZ /c
# ADD BASE RSC /l 0x404 /d "NDEBUG"
# ADD RSC /l 0x404 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo
!ELSEIF  "$(CFG)" == "inet_app - Win32 Debug"
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
# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /Zi /W2 /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" 
# ADD CPP @"inet_app.ini"
# ADD CPP /FD /GZ /c
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
# Name "inet_app - Win32 Release"
# Name "inet_app - Win32 Debug"
# Begin Source File 
SOURCE=..\..\plutommi\mmi\certificatemanager\certificatemanagermmisrc\certmanmmi.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\certificatemanager\certificatemanagermmisrc\certmanmmiinterfaces.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\certificatemanager\certificatemanagermmisrc\certmanmmiui.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\emailapp\emailappsrc\emailappaccount.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\emailapp\emailappsrc\emailappmain.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\emailapp\emailappsrc\emailappmiscell.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\emailapp\emailappsrc\emailappotap.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\emailapp\emailappsrc\emailapppsinterface.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\emailapp\emailappsrc\emailappuiinterface.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\imps\impssrc\mmi_imps_chat.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\imps\impssrc\mmi_imps_common.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\imps\impssrc\mmi_imps_contact.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\imps\impssrc\mmi_imps_main.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\imps\impssrc\mmi_imps_ota.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\imps\impssrc\mmi_imps_pa.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\imps\impssrc\mmi_imps_prof.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\imps\impssrc\mmi_imps_ps_gen.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\imps\impssrc\mmi_imps_ps_pa.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\imps\impssrc\mmi_imps_util.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\poc\pocsrc\poccallmanagement.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\poc\pocsrc\pocgroups.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\poc\pocsrc\pocmain.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\unifiedmms\mmsbgsr\mmsbgsrsrc\mmsbgsrapp.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\unifiedmms\mmsbgsr\mmsbgsrsrc\mmsbgsrmain.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\unifiedmms\mmsbgsr\mmsbgsrsrc\mmsbgsrmsg.c
# End Source File 

# End Target
# End Project
