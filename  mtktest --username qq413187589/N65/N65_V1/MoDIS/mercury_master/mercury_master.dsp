# Microsoft Developer Studio Project File - Name="mercury_master" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=mercury_master - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "mercury_master.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "mercury_master.mak" CFG="mercury_master - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "mercury_master - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "mercury_master - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "mercury_master - Win32 Release"
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
# ADD CPP @"mercury_master.ini"
# ADD CPP /FD /GZ /c
# ADD BASE RSC /l 0x404 /d "NDEBUG"
# ADD RSC /l 0x404 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo
!ELSEIF  "$(CFG)" == "mercury_master - Win32 Debug"
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
# ADD CPP @"mercury_master.ini"
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
# Name "mercury_master - Win32 Release"
# Name "mercury_master - Win32 Debug"
# Begin Group "src"
# Begin Source File 
SOURCE=..\..\custom\mercury\mercury_master\src\MTPNP_PFAL_custom_VEINT.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\mercury\mercury_master\src\MTPNP_PFAL_custom_config.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\mercury\mercury_master\src\MTPNP_PFAL_custom_hw.c
# End Source File 
# End Group "src"
# Begin Group "src"
# Begin Source File 
SOURCE=..\..\vendor\mercury_master\src\MTPNP_PFAL_CC.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\mercury_master\src\MTPNP_PFAL_CC_UCM.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\mercury_master\src\MTPNP_PFAL_CHV_Verify.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\mercury_master\src\MTPNP_PFAL_Card2_MSISDN.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\mercury_master\src\MTPNP_PFAL_CardSelection.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\mercury_master\src\MTPNP_PFAL_CellBroadcast.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\mercury_master\src\MTPNP_PFAL_DM_Setup.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\mercury_master\src\MTPNP_PFAL_Debug.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\mercury_master\src\MTPNP_PFAL_HelpInfo.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\mercury_master\src\MTPNP_PFAL_Master_ADN.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\mercury_master\src\MTPNP_PFAL_Master_CallHistory.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\mercury_master\src\MTPNP_PFAL_Master_CallsCost.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\mercury_master\src\MTPNP_PFAL_Master_EngineerMode.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\mercury_master\src\MTPNP_PFAL_Master_FDN.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\mercury_master\src\MTPNP_PFAL_Master_MM.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\mercury_master\src\MTPNP_PFAL_Master_Msgs.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\mercury_master\src\MTPNP_PFAL_MessageQ.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\mercury_master\src\MTPNP_PFAL_MessageSetup.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\mercury_master\src\MTPNP_PFAL_Message_Data_Convert.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\mercury_master\src\MTPNP_PFAL_Network.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\mercury_master\src\MTPNP_PFAL_SMS_Chat.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\mercury_master\src\MTPNP_PFAL_VoiceMail.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\mercury_master\src\MTPNP_PFAL_category_screen.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\mercury_master\src\MTPNP_PFAL_dualprof.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\mercury_master\src\MTPNP_PFAL_menuitem.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\mercury_master\src\MTPNP_PFAL_resource.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\mercury_master\src\MTPNP_PFAL_showscreen.c
# End Source File 
# End Group "src"

# End Target
# End Project
