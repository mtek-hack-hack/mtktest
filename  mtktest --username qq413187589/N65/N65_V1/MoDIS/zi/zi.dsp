# Microsoft Developer Studio Project File - Name="zi" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=zi - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "zi.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "zi.mak" CFG="zi - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "zi - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "zi - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "zi - Win32 Release"
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
# ADD CPP @"zi.ini"
# ADD CPP /FD /GZ /c
# ADD BASE RSC /l 0x404 /d "NDEBUG"
# ADD RSC /l 0x404 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo
!ELSEIF  "$(CFG)" == "zi - Win32 Debug"
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
# ADD CPP @"zi.ini"
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
# Name "zi - Win32 Release"
# Name "zi - Win32 Debug"
# Begin Group "adaptation"
# Begin Group "include"
# Begin Source File 
SOURCE=..\..\vendor\inputmethod\zi\adaptation\include\Zi8HMI.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\inputmethod\zi\adaptation\include\ZiExtraCharacter.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\inputmethod\zi\adaptation\include\ZiExtraCharacter12.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\inputmethod\zi\adaptation\include\ZiExtraCharacter20.h
# End Source File 
# End Group "include"
# Begin Group "src"
# Begin Source File 
SOURCE=..\..\vendor\inputmethod\zi\adaptation\src\Zi8HMI.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\inputmethod\zi\adaptation\src\zi8sdata.c
# End Source File 
# End Group "src"
# End Group "adaptation"

# End Target
# End Project
