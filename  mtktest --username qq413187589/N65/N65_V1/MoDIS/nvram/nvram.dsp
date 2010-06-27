# Microsoft Developer Studio Project File - Name="nvram" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=nvram - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "nvram.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "nvram.mak" CFG="nvram - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "nvram - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "nvram - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "nvram - Win32 Release"
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
# ADD CPP @"nvram.ini"
# ADD CPP /FD /GZ /c
# ADD BASE RSC /l 0x404 /d "NDEBUG"
# ADD RSC /l 0x404 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo
!ELSEIF  "$(CFG)" == "nvram - Win32 Debug"
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
# ADD CPP @"nvram.ini"
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
# Name "nvram - Win32 Release"
# Name "nvram - Win32 Debug"
# Begin Group "src"
# Begin Source File 
SOURCE=..\..\nvram\src\nvram_context.c
# End Source File 
# Begin Source File 
SOURCE=..\..\nvram\src\nvram_data_items.c
# End Source File 
# Begin Source File 
SOURCE=..\..\nvram\src\nvram_drv_int.c
# End Source File 
# Begin Source File 
SOURCE=..\..\nvram\src\nvram_drval_fat.c
# End Source File 
# Begin Source File 
SOURCE=..\..\nvram\src\nvram_handler_read.c
# End Source File 
# Begin Source File 
SOURCE=..\..\nvram\src\nvram_handler_reset.c
# End Source File 
# Begin Source File 
SOURCE=..\..\nvram\src\nvram_handler_startup.c
# End Source File 
# Begin Source File 
SOURCE=..\..\nvram\src\nvram_handler_tst.c
# End Source File 
# Begin Source File 
SOURCE=..\..\nvram\src\nvram_handler_write.c
# End Source File 
# Begin Source File 
SOURCE=..\..\nvram\src\nvram_ilm.c
# End Source File 
# Begin Source File 
SOURCE=..\..\nvram\src\nvram_interface.c
# End Source File 
# Begin Source File 
SOURCE=..\..\nvram\src\nvram_io.c
# End Source File 
# Begin Source File 
SOURCE=..\..\nvram\src\nvram_l1def.c
# End Source File 
# Begin Source File 
SOURCE=..\..\nvram\src\nvram_ltable.c
# End Source File 
# Begin Source File 
SOURCE=..\..\nvram\src\nvram_main.c
# End Source File 
# Begin Source File 
SOURCE=..\..\nvram\src\nvram_ul1def.c
# End Source File 
# End Group "src"

# End Target
# End Project
