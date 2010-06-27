# Microsoft Developer Studio Project File - Name="l4misc" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=l4misc - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "l4misc.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "l4misc.mak" CFG="l4misc - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "l4misc - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "l4misc - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "l4misc - Win32 Release"
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
# ADD CPP @"l4misc.ini"
# ADD CPP /FD /GZ /c
# ADD BASE RSC /l 0x404 /d "NDEBUG"
# ADD RSC /l 0x404 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo
!ELSEIF  "$(CFG)" == "l4misc - Win32 Debug"
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
# ADD CPP @"l4misc.ini"
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
# Name "l4misc - Win32 Release"
# Name "l4misc - Win32 Debug"
# Begin Source File 
SOURCE=..\..\ps\l4\l4a\src\l4a_callback.c
# End Source File 
# Begin Source File 
SOURCE=..\..\ps\l4\l4a\src\l4a_cmd.c
# End Source File 
# Begin Source File 
SOURCE=..\..\ps\l4\l4a\src\l4a_cmd_ft.c
# End Source File 
# Begin Source File 
SOURCE=..\..\ps\l4\l4a\src\l4a_main.c
# End Source File 
# Begin Source File 
SOURCE=..\..\ps\l4\phb\src\phb_common.c
# End Source File 
# Begin Source File 
SOURCE=..\..\ps\l4\phb\src\phb_config.c
# End Source File 
# Begin Source File 
SOURCE=..\..\ps\l4\phb\src\phb_context.c
# End Source File 
# Begin Source File 
SOURCE=..\..\ps\l4\phb\src\phb_control_block.c
# End Source File 
# Begin Source File 
SOURCE=..\..\ps\l4\phb\src\phb_data_desc.c
# End Source File 
# Begin Source File 
SOURCE=..\..\ps\l4\phb\src\phb_data_entry_table.c
# End Source File 
# Begin Source File 
SOURCE=..\..\ps\l4\phb\src\phb_handler_approve.c
# End Source File 
# Begin Source File 
SOURCE=..\..\ps\l4\phb\src\phb_handler_delete.c
# End Source File 
# Begin Source File 
SOURCE=..\..\ps\l4\phb\src\phb_handler_read.c
# End Source File 
# Begin Source File 
SOURCE=..\..\ps\l4\phb\src\phb_handler_sat.c
# End Source File 
# Begin Source File 
SOURCE=..\..\ps\l4\phb\src\phb_handler_search.c
# End Source File 
# Begin Source File 
SOURCE=..\..\ps\l4\phb\src\phb_handler_startup.c
# End Source File 
# Begin Source File 
SOURCE=..\..\ps\l4\phb\src\phb_handler_write.c
# End Source File 
# Begin Source File 
SOURCE=..\..\ps\l4\phb\src\phb_ilm.c
# End Source File 
# Begin Source File 
SOURCE=..\..\ps\l4\phb\src\phb_main.c
# End Source File 
# Begin Source File 
SOURCE=..\..\ps\l4\phb\src\phb_name_num_index.c
# End Source File 
# Begin Source File 
SOURCE=..\..\ps\l4\phb\src\phb_nvram_access.c
# End Source File 
# Begin Source File 
SOURCE=..\..\ps\l4\phb\src\phb_pindex.c
# End Source File 
# Begin Source File 
SOURCE=..\..\ps\l4\phb\src\phb_sap.c
# End Source File 
# Begin Source File 
SOURCE=..\..\ps\l4\phb\src\phb_se.c
# End Source File 
# Begin Source File 
SOURCE=..\..\ps\l4\phb\src\phb_sim_access.c
# End Source File 
# Begin Source File 
SOURCE=..\..\ps\l4\phb\src\phb_utils.c
# End Source File 
# Begin Source File 
SOURCE=..\..\ps\l4\uem\src\uem_at_cmd.c
# End Source File 
# Begin Source File 
SOURCE=..\..\ps\l4\uem\src\uem_gpio_ctrl.c
# End Source File 
# Begin Source File 
SOURCE=..\..\ps\l4\uem\src\uem_main.c
# End Source File 
# Begin Source File 
SOURCE=..\..\ps\l4\uem\src\uem_msg_hdlr.c
# End Source File 
# Begin Source File 
SOURCE=..\..\ps\l4\uem\src\uem_proc_cmd.c
# End Source File 
# Begin Source File 
SOURCE=..\..\ps\l4\uem\src\uem_proc_msg.c
# End Source File 
# Begin Source File 
SOURCE=..\..\ps\l4\uem\src\uem_utility.c
# End Source File 

# End Target
# End Project
