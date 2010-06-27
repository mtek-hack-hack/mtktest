# Microsoft Developer Studio Project File - Name="conn_app" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=conn_app - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "conn_app.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "conn_app.mak" CFG="conn_app - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "conn_app - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "conn_app - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "conn_app - Win32 Release"
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
# ADD CPP @"conn_app.ini"
# ADD CPP /FD /GZ /c
# ADD BASE RSC /l 0x404 /d "NDEBUG"
# ADD RSC /l 0x404 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo
!ELSEIF  "$(CFG)" == "conn_app - Win32 Debug"
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
# ADD CPP @"conn_app.ini"
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
# Name "conn_app - Win32 Release"
# Name "conn_app - Win32 Debug"
# Begin Source File 
SOURCE=..\..\plutommi\mmi\connectmanagement\connectmanagementsrc\alwaysaskinterfaces.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\connectmanagement\connectmanagementsrc\connectmanagemain.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\dataaccount\dataaccountsrc\dataaccount.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\dataaccount\dataaccountsrc\dataaccounteap.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\dataaccount\dataaccountsrc\dataaccountprov.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\dataaccount\dataaccountsrc\dataaccountps.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\dataaccount\dataaccountsrc\dataaccountui.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\dataaccount\dataaccountsrc\dataaccountutils.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\dataaccount\dataaccountsrc\dataaccountwlanotap.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\centralconfigagent\centralconfigagentsrc\centralconfigagentconfig.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\centralconfigagent\centralconfigagentsrc\centralconfigagentdispatcher.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\centralconfigagent\centralconfigagentsrc\centralconfigagentdocument.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\centralconfigagent\centralconfigagentsrc\centralconfigagentmain.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\centralconfigagent\centralconfigagentsrc\centralconfigagentoma.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\centralconfigagent\centralconfigagentsrc\centralconfigagentui.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\connectivity\connectivitysrc\btcommon\av_bt.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\connectivity\connectivitysrc\btcommon\btmmihidscr.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\connectivity\connectivitysrc\btcommon\btmmiscr.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\connectivity\connectivitysrc\btcommon\oppmmiscr.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\connectivity\connectivitysrc\btmtk\btmmia2dp.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\connectivity\connectivitysrc\btmtk\btmmiavrcp.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\connectivity\connectivitysrc\btmtk\btmmibip.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\connectivity\connectivitysrc\btmtk\btmmibipscr.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\connectivity\connectivitysrc\btmtk\btmmibpp.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\connectivity\connectivitysrc\btmtk\btmmibppscr.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\connectivity\connectivitysrc\btmtk\btmmibppxhtml.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\connectivity\connectivitysrc\btmtk\btmmicm.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\connectivity\connectivitysrc\btmtk\btmmidun.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\connectivity\connectivitysrc\btmtk\btmmifax.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\connectivity\connectivitysrc\btmtk\btmmiftp.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\connectivity\connectivitysrc\btmtk\btmmiftpscr.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\connectivity\connectivitysrc\btmtk\btmmihfp.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\connectivity\connectivitysrc\btmtk\btmmihidd.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\connectivity\connectivitysrc\btmtk\btmmihsp.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\connectivity\connectivitysrc\btmtk\btmmiobex.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\connectivity\connectivitysrc\btmtk\btmmiopp.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\connectivity\connectivitysrc\btmtk\btmmisimap.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\connectivity\connectivitysrc\btmtk\btmmispp.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\connectivity\connectivitysrc\connectivity.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\connectivity\connectivitysrc\irdammi.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\connectivity\connectivitysrc\irdammiscr.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\connectivity\connectivitysrc\usbdevice.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\dlagent\dlagentsrc\dlagentconfig.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\dlagent\dlagentsrc\dlagenthttp.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\dlagent\dlagentsrc\dlagentoma.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\dlagent\dlagentsrc\dlagentoma2.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\dlagent\dlagentsrc\dlagentomautil.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\dlagent\dlagentsrc\dlagentscreen.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\dlagent\dlagentsrc\dlagentsrc.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\dlagent\dlagentsrc\dlagentutil.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\dlagent\dlagentsrc\dlagentwps.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\dmuiapp\dmuiappsrc\dmselfregister.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\dmuiapp\dmuiappsrc\dmuiapp.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\dmuiapp\dmuiappsrc\dmuiotap.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\syncml\syncmlsrc\syncmlchangelog.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\syncml\syncmlsrc\syncmlcustomizedsettings.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\syncml\syncmlsrc\syncmlhandler.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\syncml\syncmlsrc\syncmlmain.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\syncml\syncmlsrc\syncmlotap.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\syncml\syncmlsrc\syncmlprofile.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\syncml\syncmlsrc\syncmlregularity.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\syncml\syncmlsrc\syncmlreport.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\syncml\syncmlsrc\syncmlsas.c
# End Source File 

# End Target
# End Project
