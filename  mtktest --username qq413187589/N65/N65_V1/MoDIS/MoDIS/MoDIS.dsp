# Microsoft Developer Studio Project File - Name="MoDIS" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=MoDIS - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "MoDIS.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "MoDIS.mak" CFG="MoDIS - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "MoDIS - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "MoDIS - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "MoDIS - Win32 Release"

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
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "__WIN32__" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /D "KAL_ON_OSCAR" /D "MTK_KAL" /D "MEM_CHECK_ON" /D "L1_NOT_PRESENT" @"../conn_app/conn_app.ini" /c
# ADD BASE RSC /l 0x404 /d "NDEBUG"
# ADD RSC /l 0x404 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 winmm.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib ws2_32.lib nafxcwd.lib Msimg32.lib Release/MoDis_UI.lib /nologo /subsystem:console /machine:I386 /nodefaultlib:"libc.lib" /nodefaultlib:"libcmt.lib" /nodefaultlib:"libcd.lib" /pdbtype:sept

!ELSEIF  "$(CFG)" == "MoDIS - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /Gi /GX /Zi /Od /I "..\tst\database_classb\pstrace_db" /D "WIN32" /D "__WIN32__" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /D "KAL_ON_OSCAR" /D "MTK_KAL" /D "MEM_CHECK_ON" /D "L1_NOT_PRESENT" /D "MMI_ON_WIN32" /FR @"../conn_app/conn_app.ini" /c
# ADD BASE RSC /l 0x404 /d "_DEBUG"
# ADD RSC /l 0x404 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 winmm.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib ws2_32.lib nafxcwd.lib Msimg32.lib Debug/MoDis_UI.lib /nologo /subsystem:console /debug /machine:I386 /nodefaultlib:"libc.lib" /nodefaultlib:"libcmt.lib" /nodefaultlib:"libcd.lib" /pdbtype:sept
# SUBTRACT LINK32 /pdb:none

!ENDIF 

# Begin Target

# Name "MoDIS - Win32 Release"
# Name "MoDIS - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\w32_dspl_layer.c
DEP_CPP_W32_D=\
	".\StdAfx.h"\
	".\w32_dspl.h"\
	
NODEP_CPP_W32_D=\
	".\app_ltlcom.h"\
	".\device.h"\
	".\gdi_include.h"\
	".\kal_non_specific_general_types.h"\
	".\kal_release.h"\
	".\kbd_table.h"\
	".\lcd_if.h"\
	".\lcd_sw.h"\
	".\lcd_sw_inc.h"\
	".\lcd_sw_rnd.h"\
	".\mmi_features.h"\
	".\pixteldatatypes.h"\
	".\stack_common.h"\
	".\stack_msgs.h"\
	".\stack_timer.h"\
	".\stacklib.h"\
	".\syscomp_config.h"\
	".\task_config.h"\
	
# End Source File
# Begin Source File

SOURCE=.\w32_winmain.c
DEP_CPP_W32_W=\
	".\StdAfx.h"\
	
NODEP_CPP_W32_W=\
	".\kal_release.h"\
	".\lcd_sw_inc.h"\
	
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\picture\bitmap23.bmp
# End Source File
# Begin Source File

SOURCE=.\picture\mtk.bmp
# End Source File
# Begin Source File

SOURCE=.\mtk_icon.ICO
# End Source File
# Begin Source File

SOURCE=.\mtk_simulator.ICO
# End Source File
# Begin Source File

SOURCE=.\mtk_simulator.rc
# End Source File
# End Group



















# Begin Group "libs"
# PROP Default_Filter ""
# Begin Source File
SOURCE=..\MoDIS_LIB\MT6225\S00\gprs\sw_jpeg_codec.lib
# End Source File
# Begin Source File
SOURCE=..\MoDIS_LIB\MT6225\S00\gprs\init.lib
# End Source File
# Begin Source File
SOURCE=..\MoDIS_LIB\MT6225\S00\gprs\kal.lib
# End Source File
# Begin Source File
SOURCE=..\MoDIS_LIB\MT6225\S00\gprs\abm.lib
# End Source File
# Begin Source File
SOURCE=..\MoDIS_LIB\MT6225\S00\gprs\adaptation.lib
# End Source File
# Begin Source File
SOURCE=..\MoDIS_LIB\MT6225\S00\gprs\applib_inet.lib
# End Source File
# Begin Source File
SOURCE=..\MoDIS_LIB\MT6225\S00\gprs\btadp.lib
# End Source File
# Begin Source File
SOURCE=..\MoDIS_LIB\MT6225\S00\gprs\btprofiles.lib
# End Source File
# Begin Source File
SOURCE=..\MoDIS_LIB\MT6225\S00\gprs\btstack.lib
# End Source File
# Begin Source File
SOURCE=..\MoDIS_LIB\MT6225\S00\gprs\cc.lib
# End Source File
# Begin Source File
SOURCE=..\MoDIS_LIB\MT6225\S00\gprs\che.lib
# End Source File
# Begin Source File
SOURCE=..\MoDIS_LIB\MT6225\S00\gprs\ciss.lib
# End Source File
# Begin Source File
SOURCE=..\MoDIS_LIB\MT6225\S00\gprs\config.lib
# End Source File
# Begin Source File
SOURCE=..\MoDIS_LIB\MT6225\S00\gprs\data.lib
# End Source File
# Begin Source File
SOURCE=..\MoDIS_LIB\MT6225\S00\gprs\ems.lib
# End Source File
# Begin Source File
SOURCE=..\MoDIS_LIB\MT6225\S00\gprs\flc2.lib
# End Source File
# Begin Source File
SOURCE=..\MoDIS_LIB\MT6225\S00\gprs\ft.lib
# End Source File
# Begin Source File
SOURCE=..\MoDIS_LIB\MT6225\S00\gprs\image_codec.lib
# End Source File
# Begin Source File
SOURCE=..\MoDIS_LIB\MT6225\S00\gprs\interface_classb.lib
# End Source File
# Begin Source File
SOURCE=..\MoDIS_LIB\MT6225\S00\gprs\interface_classb_2.lib
# End Source File
# Begin Source File
SOURCE=..\MoDIS_LIB\MT6225\S00\gprs\l4_classb.lib
# End Source File
# Begin Source File
SOURCE=..\MoDIS_LIB\MT6225\S00\gprs\llc.lib
# End Source File
# Begin Source File
SOURCE=..\MoDIS_LIB\MT6225\S00\gprs\mcd.lib
# End Source File
# Begin Source File
SOURCE=..\MoDIS_LIB\MT6225\S00\gprs\media_rtp.lib
# End Source File
# Begin Source File
SOURCE=..\MoDIS_LIB\MT6225\S00\gprs\media_sec.lib
# End Source File
# Begin Source File
SOURCE=..\MoDIS_LIB\MT6225\S00\gprs\mercury_gemini.lib
# End Source File
# Begin Source File
SOURCE=..\MoDIS_LIB\MT6225\S00\gprs\mm_classb.lib
# End Source File
# Begin Source File
SOURCE=..\MoDIS_LIB\MT6225\S00\gprs\nvram_sec.lib
# End Source File
# Begin Source File
SOURCE=..\MoDIS_LIB\MT6225\S00\gprs\ppp.lib
# End Source File
# Begin Source File
SOURCE=..\MoDIS_LIB\MT6225\S00\gprs\rr_classb.lib
# End Source File
# Begin Source File
SOURCE=..\MoDIS_LIB\MT6225\S00\gprs\sim.lib
# End Source File
# Begin Source File
SOURCE=..\MoDIS_LIB\MT6225\S00\gprs\sm.lib
# End Source File
# Begin Source File
SOURCE=..\MoDIS_LIB\MT6225\S00\gprs\sms.lib
# End Source File
# Begin Source File
SOURCE=..\MoDIS_LIB\MT6225\S00\gprs\sndcp.lib
# End Source File
# Begin Source File
SOURCE=..\MoDIS_LIB\MT6225\S00\gprs\soc.lib
# End Source File
# Begin Source File
SOURCE=..\MoDIS_LIB\MT6225\S00\gprs\sst.lib
# End Source File
# Begin Source File
SOURCE=..\MoDIS_LIB\MT6225\S00\gprs\stacklib.lib
# End Source File
# Begin Source File
SOURCE=..\MoDIS_LIB\MT6225\S00\gprs\sw_jpeg_codec.lib
# End Source File
# Begin Source File
SOURCE=..\MoDIS_LIB\MT6225\S00\gprs\tcpip.lib
# End Source File
# Begin Source File
SOURCE=..\MoDIS_LIB\MT6225\S00\gprs\tst.lib
# End Source File
# Begin Source File
SOURCE=..\MoDIS_LIB\MT6225\S00\gprs\xmlp.lib
# End Source File
# Begin Source File
SOURCE=..\MoDIS_LIB\MT6225\S00\gprs\oscar.lib
# End Source File
# Begin Source File
SOURCE=..\..\vendor\InputMethod\zi\project\UNIRISE25_GEMINI\v6_official\lib\zi8clib_modis.lib
# End Source File
# Begin Source File
SOURCE=..\..\vendor\handwriting\hanwang\v1_official\lib\hws.lib
# End Source File
# End Group
# End Target
# End Project
