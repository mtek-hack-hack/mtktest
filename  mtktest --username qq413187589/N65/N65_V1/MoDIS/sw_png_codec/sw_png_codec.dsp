# Microsoft Developer Studio Project File - Name="sw_png_codec" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=sw_png_codec - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "sw_png_codec.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "sw_png_codec.mak" CFG="sw_png_codec - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "sw_png_codec - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "sw_png_codec - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "sw_png_codec - Win32 Release"
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
# ADD CPP @"sw_png_codec.ini"
# ADD CPP /FD /GZ /c
# ADD BASE RSC /l 0x404 /d "NDEBUG"
# ADD RSC /l 0x404 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo
!ELSEIF  "$(CFG)" == "sw_png_codec - Win32 Debug"
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
# ADD CPP @"sw_png_codec.ini"
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
# Name "sw_png_codec - Win32 Release"
# Name "sw_png_codec - Win32 Debug"
# Begin Source File 
SOURCE=..\..\image_codec\sw_png_codec\img_resizer.c
# End Source File 
# Begin Group "libpng"
# Begin Source File 
SOURCE=..\..\image_codec\sw_png_codec\libpng\png.c
# End Source File 
# Begin Source File 
SOURCE=..\..\image_codec\sw_png_codec\libpng\pngerror.c
# End Source File 
# Begin Source File 
SOURCE=..\..\image_codec\sw_png_codec\libpng\pngget.c
# End Source File 
# Begin Source File 
SOURCE=..\..\image_codec\sw_png_codec\libpng\pngmem.c
# End Source File 
# Begin Source File 
SOURCE=..\..\image_codec\sw_png_codec\libpng\pngread.c
# End Source File 
# Begin Source File 
SOURCE=..\..\image_codec\sw_png_codec\libpng\pngrio.c
# End Source File 
# Begin Source File 
SOURCE=..\..\image_codec\sw_png_codec\libpng\pngrtran.c
# End Source File 
# Begin Source File 
SOURCE=..\..\image_codec\sw_png_codec\libpng\pngrutil.c
# End Source File 
# Begin Source File 
SOURCE=..\..\image_codec\sw_png_codec\libpng\pngset.c
# End Source File 
# Begin Source File 
SOURCE=..\..\image_codec\sw_png_codec\libpng\pngtrans.c
# End Source File 
# End Group "libpng"
# Begin Source File 
SOURCE=..\..\image_codec\sw_png_codec\png_decoder_sw.c
# End Source File 
# Begin Source File 
SOURCE=..\..\applib\misc\src\app_zlib.c
# End Source File 

# End Target
# End Project
