# Microsoft Developer Studio Project File - Name="media_app" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=media_app - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "media_app.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "media_app.mak" CFG="media_app - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "media_app - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "media_app - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "media_app - Win32 Release"
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
# ADD CPP @"media_app.ini"
# ADD CPP /FD /GZ /c
# ADD BASE RSC /l 0x404 /d "NDEBUG"
# ADD RSC /l 0x404 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo
!ELSEIF  "$(CFG)" == "media_app - Win32 Debug"
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
# ADD CPP @"media_app.ini"
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
# Name "media_app - Win32 Release"
# Name "media_app - Win32 Debug"
# Begin Source File 
SOURCE=..\..\plutommi\mmi\audio\audiosrc\audiosrc.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\funandgames\funandgamessrc\colorballs.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\funandgames\funandgamessrc\composeringtone.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\funandgames\funandgamessrc\copter.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\funandgames\funandgamessrc\dance.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\funandgames\funandgamessrc\doll.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\funandgames\funandgamessrc\downloadsrc.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\funandgames\funandgamessrc\f1race.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\funandgames\funandgamessrc\fruit.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\funandgames\funandgamessrc\funandgamessrc.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\funandgames\funandgamessrc\game.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\funandgames\funandgamessrc\game3d.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\funandgames\funandgamessrc\gameframework.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\funandgames\funandgamessrc\javagame.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\funandgames\funandgamessrc\magicsushi.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\funandgames\funandgamessrc\majung.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\funandgames\funandgamessrc\mmithemes.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\funandgames\funandgamessrc\motionapp.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\funandgames\funandgamessrc\motiondice.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\funandgames\funandgamessrc\motiondj.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\funandgames\funandgamessrc\motiondjres.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\funandgames\funandgamessrc\panda.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\funandgames\funandgamessrc\pictureeditor.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\funandgames\funandgamessrc\pictureeditorengine.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\funandgames\funandgamessrc\pictureeditorhandler.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\funandgames\funandgamessrc\puzzle.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\funandgames\funandgamessrc\riches.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\funandgames\funandgamessrc\ringtonecomposeengine.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\funandgames\funandgamessrc\smash.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\funandgames\funandgamessrc\snake.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\funandgames\funandgamessrc\stair.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\funandgames\funandgamessrc\toh.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\funandgames\funandgamessrc\ufo.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\funandgames\funandgamessrc\vsmj.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\abrepeater\abrepeatersrc\abrepeatermainscreen.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\abrepeater\abrepeatersrc\abrepeatermsghandler.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\abrepeater\abrepeatersrc\abrepeatersrc.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\audioplayer\audioplayersrc\audioplayermainscreen.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\audioplayer\audioplayersrc\audioplayermsghandler.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\audioplayer\audioplayersrc\audioplayerplaylist.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\audioplayer\audioplayersrc\audioplayersrc.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\avatar\avatarsrc\avatar.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\barcodereader\barcodereadersrc\barcodereader.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\bgsound\bgsoundsrc\bgsoundincall.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\bgsound\bgsoundsrc\bgsoundsetting.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\camera\camerasrc\cameraapp.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\camera\camerasrc\cameramenu.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\camera\camerasrc\imageviewer.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\fmradio\fmradiosrc\fmradiomainscreen.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\fmradio\fmradiosrc\fmradiomsghdlr.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\fmradio\fmradiosrc\fmradiosrc.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\fmschedulerec\fmschedulerecsrc\fmschedulerec.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\fmschedulerec\fmschedulerecsrc\fmschedulerecmsghdlr.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\fmschedulerec\fmschedulerecsrc\fmschedulerecscreen.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\fmschedulerec\fmschedulerecsrc\fmschedulerecsetting.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\javaagency\javaagencysrc\javaagencyem.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\javaagency\javaagencysrc\javaagencymidsinstall.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\javaagency\javaagencysrc\javaagencyrms.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\javaagency\javaagencysrc\javaagencysrc.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\javaagency\javaagencysrc\javaagencytaskswitch.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\javaagency\javaagencysrc\javaagencytimealarm.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\javaagency\javaagencysrc\javaagencyutil.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\mdi\mdisrc\mdi_audio.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\mdi\mdisrc\mdi_camera.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\mdi\mdisrc\mdi_common.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\mdi\mdisrc\mdi_motion.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\mdi\mdisrc\mdi_mtv.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\mdi\mdisrc\mdi_swflash.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\mdi\mdisrc\mdi_tv.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\mdi\mdisrc\mdi_video.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\mdi\mdisrc\mdi_webcam.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\mobiletvplayer\mobiletvplayersrc\mobiletvplayer.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\mtkappsrc\datamgr.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\mtkappsrc\voicememomsghandler.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\mtkappsrc\voicememosrc.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\photoeditor\photoeditorsrc\imagetile.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\photoeditor\photoeditorsrc\photoart.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\photoeditor\photoeditorsrc\photoeditor.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\photoeditor\photoeditorsrc\scenemaster.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\photoeditor\photoeditorsrc\slideshow.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\soundrecorder\soundrecordersrc\soundrecordermsghandler.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\soundrecorder\soundrecordersrc\soundrecordersrc.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\swflash\swflashsrc\swflashdlsrc.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\swflash\swflashsrc\swflashplayer.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\swflash\swflashsrc\swflashsrc.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\video\videosrc\vdoplyapp.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\video\videosrc\vdorecapp.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\videoeditor\videoeditorsrc\vdoedtapp.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\vrsd\vrsdsrc\vrsdaudiores.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\vrsd\vrsdsrc\vrsdaudplayer.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\vrsd\vrsdsrc\vrsddial.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\vrsd\vrsdsrc\vrsdmain.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\vrsd\vrsdsrc\vrsdprofile.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\vrsd\vrsdsrc\vrsdredial.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\vrsd\vrsdsrc\vrsdshortcut.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\vrsi\vrsisrc\vrsicityquery.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\vrsi\vrsisrc\vrsidigitdial.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\vrsi\vrsisrc\vrsigrammar.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\vrsi\vrsisrc\vrsimaincmd.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\vrsi\vrsisrc\vrsinamedial.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\vrsi\vrsisrc\vrsinamequery.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\vrsi\vrsisrc\vrsiprofile.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\vrsi\vrsisrc\vrsiredial.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\vrsi\vrsisrc\vrsisettings.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\vrsi\vrsisrc\vrsishortcut.c
# End Source File 

# End Target
# End Project
