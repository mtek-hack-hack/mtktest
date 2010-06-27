# Microsoft Developer Studio Project File - Name="vendorapp" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=vendorapp - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "vendorapp.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "vendorapp.mak" CFG="vendorapp - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "vendorapp - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "vendorapp - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "vendorapp - Win32 Release"
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
# ADD CPP @"vendorapp.ini"
# ADD CPP /FD /GZ /c
# ADD BASE RSC /l 0x404 /d "NDEBUG"
# ADD RSC /l 0x404 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo
!ELSEIF  "$(CFG)" == "vendorapp - Win32 Debug"
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
# ADD CPP @"vendorapp.ini"
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
# Name "vendorapp - Win32 Release"
# Name "vendorapp - Win32 Debug"
# Begin Group "DevApp"
# Begin Group "DevAppSrc"
# Begin Source File 
SOURCE=..\..\plutommi\vendorapp\DevApp\DevAppSrc\DevApp.c
# End Source File 
# End Group "DevAppSrc"
# End Group "DevApp"
# Begin Group "DevResource"
# Begin Group "Resources"
# Begin Source File 
SOURCE=..\..\plutommi\vendorapp\DevResource\Resources\DevAppAdoMap.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\vendorapp\DevResource\Resources\DevAppAdoRes.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\vendorapp\DevResource\Resources\DevAppImgMap.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\vendorapp\DevResource\Resources\DevAppImgRes.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\vendorapp\DevResource\Resources\DevAppMenuRes.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\vendorapp\DevResource\Resources\DevAppStrMap.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\vendorapp\DevResource\Resources\DevAppStrRes.c
# End Source File 
# End Group "Resources"
# End Group "DevResource"
# Begin Group "DevSample"
# Begin Group "DevSampleSrc"
# Begin Source File 
SOURCE=..\..\plutommi\vendorapp\DevSample\DevSampleSrc\Sample_3DGame.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\vendorapp\DevSample\DevSampleSrc\Sample_Audio.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\vendorapp\DevSample\DevSampleSrc\Sample_DeviceCtrl.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\vendorapp\DevSample\DevSampleSrc\Sample_Drawing.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\vendorapp\DevSample\DevSampleSrc\Sample_GUI.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\vendorapp\DevSample\DevSampleSrc\Sample_Input.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\vendorapp\DevSample\DevSampleSrc\Sample_Memory.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\vendorapp\DevSample\DevSampleSrc\Sample_Misc.c
# End Source File 
# End Group "DevSampleSrc"
# End Group "DevSample"
# Begin Group "ResGenerator"
# Begin Source File 
SOURCE=..\..\plutommi\vendorapp\ResGenerator\DevApp_ReadRes.c
# End Source File 
# End Group "ResGenerator"

# End Target
# End Project
