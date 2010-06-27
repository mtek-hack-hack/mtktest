# Microsoft Developer Studio Project File - Name="mmiresource" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=mmiresource - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "mmiresource.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "mmiresource.mak" CFG="mmiresource - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "mmiresource - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "mmiresource - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "mmiresource - Win32 Release"
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
# ADD CPP @"mmiresource.ini"
# ADD CPP /FD /GZ /c
# ADD BASE RSC /l 0x404 /d "NDEBUG"
# ADD RSC /l 0x404 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo
!ELSEIF  "$(CFG)" == "mmiresource - Win32 Debug"
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
# ADD CPP @"mmiresource.ini"
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
# Name "mmiresource - Win32 Release"
# Name "mmiresource - Win32 Debug"
# Begin Source File 
SOURCE=..\..\plutommi\customer\custresource\custadomap.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\customer\custresource\custadomapext.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\customer\custresource\custadores.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\customer\custresource\custadoresext.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\customer\custresource\custcoordinates.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\customer\custresource\custenfbimgmap.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\customer\custresource\custimgmap.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\customer\custresource\custimgmapext.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\customer\custresource\custimgres.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\customer\custresource\custimgresext.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\customer\custresource\custmenures.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\customer\custresource\custmiscdata.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\customer\custresource\custstrmap.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\customer\custresource\custstrres.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\customer\custresource\fontres.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\customer\custresource\fonttype.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\customer\custresource\gui_wrapper.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\customer\custresource\imeres.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\customer\custresource\resource_abrepeat_skins.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\customer\custresource\resource_aud_eq_values.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\customer\custresource\resource_audply_skins.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\customer\custresource\resource_audply_sub_skins.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\customer\custresource\resource_autogen_audio_jtbl.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\customer\custresource\resource_barcodereader_skins.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\customer\custresource\resource_calc_coordinates.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\customer\custresource\resource_camera_skins.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\customer\custresource\resource_fmradio_skins.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\customer\custresource\resource_fmradio_sub_skins.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\customer\custresource\resource_fmschedulerec_skins.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\customer\custresource\resource_image_jtbl.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\customer\custresource\resource_lang_pack_jtbl.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\customer\custresource\resource_langln_lk_skins.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\customer\custresource\resource_shortcuts.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\customer\custresource\resource_vdoedt_skins.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\customer\custresource\resource_video_skins.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\customer\custresource\resource_vt_skins.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\customer\custresource\resource_world_clock_city.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\customer\custresource\themeres.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\resource\standaloneres.c
# End Source File 

# End Target
# End Project
