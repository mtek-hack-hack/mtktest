# Microsoft Developer Studio Project File - Name="obigo03capp" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=obigo03capp - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "obigo03capp.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "obigo03capp.mak" CFG="obigo03capp - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "obigo03capp - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "obigo03capp - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "obigo03capp - Win32 Release"
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
# ADD CPP @"obigo03capp.ini"
# ADD CPP /FD /GZ /c
# ADD BASE RSC /l 0x404 /d "NDEBUG"
# ADD RSC /l 0x404 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo
!ELSEIF  "$(CFG)" == "obigo03capp - Win32 Debug"
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
# ADD CPP @"obigo03capp.ini"
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
# Name "obigo03capp - Win32 Release"
# Name "obigo03capp - Win32 Debug"
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\bra\config\bra_cfg.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\bra\export\bra_if.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\bra\export\bra_if.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\bra\intgr\bra_env.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\bra\intgr\bra_env.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\bra\intgr\bra_int.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\bra\intgr\bra_vrsn.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\bra\source\bra_act.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\bra\source\bra_act.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\bra\source\bra_bkm.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\bra\source\bra_bkm.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\bra\source\bra_cbm.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\bra\source\bra_cbm.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\bra\source\bra_cca.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\bra\source\bra_cca.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\bra\source\bra_cch.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\bra\source\bra_cch.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\bra\source\bra_cks.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\bra\source\bra_cks.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\bra\source\bra_cmn.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\bra\source\bra_cmn.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\bra\source\bra_dlg.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\bra\source\bra_dlg.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\bra\source\bra_file.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\bra\source\bra_file.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\bra\source\bra_inse.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\bra\source\bra_inse.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\bra\source\bra_main.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\bra\source\bra_main.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\bra\source\bra_ofln.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\bra\source\bra_ofln.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\bra\source\bra_opt.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\bra\source\bra_opt.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\bra\source\bra_prof.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\bra\source\bra_prof.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\bra\source\bra_prs.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\bra\source\bra_prs.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\bra\source\bra_psl.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\bra\source\bra_psl.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\bra\source\bra_req.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\bra\source\bra_req.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\bra\source\bra_rpl.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\bra\source\bra_rpl.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\bra\source\bra_sec.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\bra\source\bra_sec.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\bra\source\bra_set.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\bra\source\bra_set.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\bra\source\bra_sif.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\bra\source\bra_sif.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\bra\source\bra_sig.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\bra\source\bra_sig.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\bra\source\bra_sim.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\bra\source\bra_sim.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\bra\source\bra_slct.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\bra\source\bra_slct.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\bra\source\bra_str.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\bra\source\bra_view.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\bra\source\bra_view.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\bra\source\bra_win.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\bra\source\bra_win.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\config\brs_cfg.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\export\brs_if.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\intgr\brs_env.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\intgr\brs_vrsn.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\refsrc\brs_char.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\refsrc\brs_char.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\refsrc\brs_dlg.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\refsrc\brs_dlg.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\refsrc\brs_plab.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\refsrc\brs_plege.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\refsrc\brs_plg.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\refsrc\brs_plg.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\refsrc\brs_plmms.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\refsrc\brs_plrtsp.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\refsrc\brs_plsms.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\refsrc\brs_plti.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\refsrc\brs_pltx.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\refsrc\brs_rc.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\refsrc\brs_spel.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\refsrc\brs_spel.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_css.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_cssm.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_datr.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_dcmn.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_ddt.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_dfcf.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_dhtm.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_dimf.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_dleh.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_dmsh.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_dwi.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_dwml.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_hdef.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_hist.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_html.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_hvld.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_job.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_lbxt.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_lccn.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_lcli.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_lcpr.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_lcss.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_lctl.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_ldef.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_ldrw.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_levt.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_lfrm.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_limg.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_list.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_lmn.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_lnav.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_lrct.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_lrdf.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_lrfl.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_lrnd.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_lsbr.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_lsig.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_ltbl.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_ltxt.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_lutl.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_main.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_memp.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_ofli.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_oflm.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_oflp.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_plh.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_prh.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_sibp.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_sicr.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_sifl.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_sifr.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_sifs.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_sig.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_siin.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_siit.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_sili.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_silt.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_sima.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_simi.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_siop.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_sire.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_sisi.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_sisq.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_sity.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_siva.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_str.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_ua.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_uad.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_var.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_vist.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\brs\source\brs_wml.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\config\mea_cfg.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\config\mea_def.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\export\mea_if.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\export\mea_if.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\export\meal_if.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\intgr\mea_env.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\intgr\mea_env.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\intgr\mea_int.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\intgr\mea_vrsn.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\refsrc\mea_int.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\refsrc\mea_rc.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\refsrc\mea_rc.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\maaddr.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\maaddr.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\maasync.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\maasync.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\macomm.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\macomm.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\maconf.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\maconf.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\macore.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\macore.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\macrh.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\macrh.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\macth.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\macth.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\madel.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\madel.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\maincn.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\maincn.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\maintsig.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\maintsig.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mamcr.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mamcr.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mame.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mame.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mamem.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mamem.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mamh.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mamh.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mamme.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mamme.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mammv.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mammv.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mamob.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mamob.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mamoh.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mamoh.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mamr.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mamr.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mamv.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mamv.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\manotif.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\manotif.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\maopts.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\maopts.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mapbh.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mapbh.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mapckg.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mapckg.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\maph.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\maph.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\masch.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\masch.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mase.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mase.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\masig.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\masig.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\maslh.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\maslh.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\masrh.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\masrh.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\matypes.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mauicmn.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mauicmn.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mauicols.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mauicols.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mauicomm.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mauicomm.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mauiconf.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mauiconf.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mauidia.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mauidia.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mauiform.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mauiform.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mauiincn.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mauiincn.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mauime.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mauime.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mauimenu.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mauimenu.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mauimh.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mauimh.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mauimme.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mauimme.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mauimmv.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mauimmv.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mauimob.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mauimob.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mauimv.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mauimv.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mauipm.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mauipm.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mauise.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mauise.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mauisemm.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mauisemm.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mauisig.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mauisig.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mautils.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mautils.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mtr.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mtr_cmn.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mtr_cmn.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mtr_ctrl.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mtr_ctrl.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mtr_par.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mtr_par.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mtr_rend.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mea\source\mtr_rend.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mms\config\mms_cfg.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mms\config\mms_def.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mms\export\mms_if.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mms\export\mmsl_if.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mms\intgr\mms_env.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mms\intgr\mms_int.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mms\intgr\mms_vrsn.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mms\refsrc\mms_a.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mms\refsrc\mms_aapp.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mms\refsrc\mms_aapp.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mms\refsrc\mms_rc.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mms\source\fldmgr.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mms\source\masync.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mms\source\mcget.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mms\source\mcnotif.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mms\source\mconfig.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mms\source\mcpdu.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mms\source\mcpost.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mms\source\mcsend.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mms\source\mcwap.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mms\source\mcwsp.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mms\source\mhandler.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mms\source\mlcreate.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mms\source\mlfetch.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mms\source\mlfieldc.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mms\source\mlfieldp.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mms\source\mlpduc.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mms\source\mlpdup.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mms\source\mltypes.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mms\source\mmain.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mms\source\mmem.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mms\source\mms_cont.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mms\source\mmsrec.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mms\source\mmsrpl.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mms\source\mmsui.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mms\source\mnotify.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mms\source\mreceive.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mms\source\mreport.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mms\source\msend.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mms\source\msig.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mms\source\mtimer.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\mms\source\mutils.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\phs\config\phs_cfg.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\phs\export\phs_def.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\phs\export\phs_if.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\phs\intgr\phs_env.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\phs\intgr\phs_vrsn.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\phs\refsrc\phs_dlg.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\phs\refsrc\phs_dlg.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\phs\refsrc\phs_rc.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\phs\source\phs_cmmn.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\phs\source\phs_conn.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\phs\source\phs_hdr.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\phs\source\phs_http.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\phs\source\phs_main.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\phs\source\phs_mprt.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\phs\source\phs_msg.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\phs\source\phs_prh.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\phs\source\phs_sia.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\phs\source\phs_sig.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\phs\source\phs_vld.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\prs\config\prs_cfg.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\prs\export\prs_if.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\prs\intgr\prs_env.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\prs\intgr\prs_vrsn.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\prs\refsrc\prs_a.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\prs\refsrc\prs_def.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\prs\refsrc\prs_def.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\prs\refsrc\prs_dlg.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\prs\refsrc\prs_rc.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\prs\refsrc\prs_xtrn.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\prs\refsrc\prs_xtrn.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\prs\source\prs_auth.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\prs\source\prs_bld.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\prs\source\prs_cnst.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\prs\source\prs_dlg.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\prs\source\prs_fldt.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\prs\source\prs_main.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\prs\source\prs_otab.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\prs\source\prs_otas.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\prs\source\prs_prcs.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\prs\source\prs_type.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\prs\source\prs_val.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\prs\source\prs_wap.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\config\sec_cfg.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\export\sec_if.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\export\sec_lib.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\intgr\sec_env.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\intgr\sec_int.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\intgr\sec_vrsn.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\refsrc\sec_rc.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\refsrc\sec_ti.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\refsrc\sec_ti.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\aes\aes.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\aes\aes_locl.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\algid.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\asnconv.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\bench.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\block.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\blt_asn1.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\bsafecst.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\bsapi.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\bstypes.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\cdk.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\cdkut.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\config.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\cstdll.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\cstfiles.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\cstheap.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\cstint.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\cstio.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\cstlib.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\cstmacro.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\cstopt.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\dh.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\dsaconf.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\dsai.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\fprnt.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\frstprmh.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\hash.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\heap.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\hshtypes.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\kdf.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\mgf.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\mma.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\monty.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\mpa.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\mpm.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\options.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\pad.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\padtypes.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\pbei.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\pkcs12.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\pkcs12t.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\pkcs8.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\privbsa.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\privdh.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\privhash.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\privmma.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\privmpa.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\privmpm.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\privut.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\prng.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\prntypes.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\register.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\rsai.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\sbeccom.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\sbecdh.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\sbecdsa.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\secshare.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\set.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\spkcs12.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\thrdcst.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\ut.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\utmpm.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\uttypes.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\vbcst.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\cryptlib\verify.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\sec.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\sec_ati.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\sec_awim.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\sec_cert.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\sec_ch.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\sec_cti.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\sec_cwim.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\sec_ifim.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\sec_pdf.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\sec_resp.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\sec_sig.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\sec_str.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\sec_sw.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\sec_sw2.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\sec_swsh.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\sec_utls.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\sec_wtls.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sec\source\sec_x509.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sls\config\sls_cfg.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sls\config\sls_def.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sls\export\sls_if.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sls\intgr\sls_env.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sls\intgr\sls_vrsn.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sls\source\sls_main.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sls\source\sls_mem.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sls\source\sls_prse.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sma\config\sma_cfg.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sma\config\sma_def.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sma\export\sma_if.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sma\export\sma_if.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sma\intgr\sma_env.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sma\intgr\sma_env.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sma\intgr\sma_vrsn.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sma\refsrc\sma_rc.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sma\source\saasync.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sma\source\saasync.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sma\source\saattach.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sma\source\saattach.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sma\source\saintsig.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sma\source\saintsig.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sma\source\salnk.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sma\source\salnk.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sma\source\samain.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sma\source\samain.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sma\source\samem.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sma\source\samenu.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sma\source\samenu.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sma\source\sapckg.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sma\source\sapckg.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sma\source\saph.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sma\source\saph.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sma\source\sapipe.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sma\source\sapipe.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sma\source\sasbp.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sma\source\sasbp.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sma\source\sasig.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sma\source\sasig.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sma\source\saslide.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sma\source\saslide.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sma\source\sasls.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sma\source\sasls.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sma\source\satypes.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sma\source\saui.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sma\source\saui.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sma\source\sauidia.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sma\source\sauidia.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sma\source\sauilnk.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sma\source\sauilnk.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sma\source\sauisig.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sma\source\sauisig.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sma\source\smtr.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sma\source\smtrcmn.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sma\source\smtrcmn.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sma\source\smtrctrl.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sma\source\smtrctrl.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sma\source\smtrpar.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sma\source\smtrpar.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sma\source\smtrrend.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\sma\source\smtrrend.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\stk\config\stk_cfg.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\stk\export\stk_if.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\stk\intgr\stk_env.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\stk\intgr\stk_vrsn.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\stk\refsrc\security\sec_if.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\stk\refsrc\security\sec_lib.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\stk\refsrc\stk_dlg.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\stk\refsrc\stk_dlg.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\stk\refsrc\stk_rc.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\stk\source\stk_auth.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\stk\source\stk_cach.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\stk\source\stk_cmgr.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\stk\source\stk_cook.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\stk\source\stk_hdr.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\stk\source\stk_hdrc.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\stk\source\stk_http.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\stk\source\stk_main.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\stk\source\stk_sig.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\stk\source\stk_ssld.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\stk\source\stk_tls.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\stk\source\stk_tlsd.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\stk\source\stk_tlsh.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\stk\source\stk_trdf.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\stk\source\stk_trh.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\stk\source\stk_wdp.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\stk\source\stk_wsp.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\stk\source\stk_wtld.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\stk\source\stk_wtlh.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\stk\source\stk_wtls.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\stk\source\stk_wtp.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\stk\source\stk_wtpd.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\stk\source\stk_wtps.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\uis\config\uis_cfg.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\uis\export\uis_ecfg.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\uis\export\uis_if.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\uis\intgr\uis_env.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\uis\intgr\uis_vrsn.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\uis\refsrc\uis_a.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\uis\refsrc\uis_a.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\uis\source\uis_hash.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\uis\source\uis_job.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\uis\source\uis_keyv.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\uis\source\uis_list.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\uis\source\uis_main.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\uis\source\uis_msg.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\uis\source\uis_msin.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\uis\source\uis_mtpy.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\uis\source\uis_ndx.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\modules\uis\source\uis_sig.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\msf\msf_lib\config\msf_cfg.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\msf\msf_lib\export\msf_act.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\msf\msf_lib\export\msf_afi.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\msf\msf_lib\export\msf_chrs.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\msf\msf_lib\export\msf_chrt.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\msf\msf_lib\export\msf_cmmn.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\msf\msf_lib\export\msf_core.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\msf\msf_lib\export\msf_dcvt.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\msf\msf_lib\export\msf_dlg.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\msf\msf_lib\export\msf_errc.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\msf\msf_lib\export\msf_file.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\msf\msf_lib\export\msf_hdr.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\msf\msf_lib\export\msf_log.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\msf\msf_lib\export\msf_mem.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\msf\msf_lib\export\msf_mime.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\msf\msf_lib\export\msf_neta.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\msf\msf_lib\export\msf_pck.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\msf\msf_lib\export\msf_pdec.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\msf\msf_lib\export\msf_pim.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\msf\msf_lib\export\msf_pipe.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\msf\msf_lib\export\msf_prsr.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\msf\msf_lib\export\msf_ptok.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\msf\msf_lib\export\msf_ptxt.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\msf\msf_lib\export\msf_sas.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\msf\msf_lib\export\msf_sock.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\msf\msf_lib\export\msf_tel.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\msf\msf_lib\export\msf_url.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\msf\msf_lib\export\msf_wid.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\msf\msf_lib\intgr\msf_def.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\msf\msf_lib\intgr\msf_env.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\msf\msf_lib\intgr\msf_int.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\msf\msf_lib\intgr\msf_lib.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\msf\msf_lib\refsrc\msf_dlg.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\msf\msf_lib\refsrc\msf_drc.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\msf\msf_lib\refsrc\msf_drc.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\msf\msf_lib\refsrc\msf_rc.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\msf\msf_lib\refsrc\msf_sas.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\msf\msf_lib\refsrc\msf_xchr.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\msf\msf_lib\refsrc\msf_xchr.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\msf\msf_lib\refsrc\msf_xmim.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\msf\msf_lib\refsrc\msf_xmim.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\msf\msf_lib\refsrc\wml_inpf.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\msf\msf_lib\refsrc\wml_inpf.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\msf\msf_mgr\intgr\msm_env.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\msf\msf_mgr\intgr\msm_int.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\msf\msf_mgr\intgr\msm_vrsn.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\msf\msf_mgr\refsrc\msm_dlg.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\msf\msf_mgr\refsrc\msm_dlg.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\msf\msf_mgr\source\msm.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\msf\msf_mgr\source\msm_cmmn.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\msf\msf_mgr\source\msm_reg.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\msf\msf_mgr\source\msm_sig.h
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\v1_official\msf\msf_mgr\source\msm_time.h
# End Source File 

# End Target
# End Project
