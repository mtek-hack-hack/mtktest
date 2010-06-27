# Microsoft Developer Studio Project File - Name="obigo03cadp" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=obigo03cadp - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "obigo03cadp.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "obigo03cadp.mak" CFG="obigo03cadp - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "obigo03cadp - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "obigo03cadp - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "obigo03cadp - Win32 Release"
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
# ADD CPP @"obigo03cadp.ini"
# ADD CPP /FD /GZ /c
# ADD BASE RSC /l 0x404 /d "NDEBUG"
# ADD RSC /l 0x404 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo
!ELSEIF  "$(CFG)" == "obigo03cadp - Win32 Debug"
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
# ADD CPP @"obigo03cadp.ini"
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
# Name "obigo03cadp - Win32 Release"
# Name "obigo03cadp - Win32 Debug"
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\integration\source\bra_int.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\integration\source\msf_file.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\integration\source\msf_int.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\integration\source\msf_misc.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\integration\source\msf_nw_acc.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\integration\source\msf_pipe.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\integration\source\msf_signal.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\integration\source\msf_socket.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\integration\source\msm_int.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\integration\source\sec_int.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\integration\source\wap_cca.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\integration\source\wap_create.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\integration\source\wap_mem.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\integration\source\wap_prof.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\integration\source\wap_um.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\integration\source\wap_wtai.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\integration\source\wapadp.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\modules\das\src\das_env.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\modules\das\src\das_main.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\modules\das\src\das_msg.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\modules\das\src\das_view.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\modules\mma\intgr\mma_env.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\modules\mma\source\mma_conf.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\modules\mma\source\mma_if_wrapper.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\modules\mma\source\mma_intsig.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\modules\mma\source\mma_main.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\modules\mma\source\mma_rpl.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\modules\mma\source\mma_send.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\modules\mma\source\mma_utils.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\modules\mma\source\mma_utils_xml.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\modules\mma\source\mmsadp.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\modules\mmc\intgr\mmc_env.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\modules\mmc\source\mmc_jsr.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\modules\wps\src\wps_env.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\modules\wps\src\wps_if.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\modules\wps\src\wps_main.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\modules\wps\src\wps_msg.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\msf_ui\src\mobile_suite_app.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\msf_ui\src\widget.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\msf_ui\src\widget_action.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\msf_ui\src\widget_ctk.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\msf_ui\src\widget_dialog.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\msf_ui\src\widget_drawing.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\msf_ui\src\widget_editor.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\msf_ui\src\widget_encoding.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\msf_ui\src\widget_font.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\msf_ui\src\widget_form.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\msf_ui\src\widget_gadget.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\msf_ui\src\widget_general.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\msf_ui\src\widget_icon.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\msf_ui\src\widget_image.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\msf_ui\src\widget_key_handler.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\msf_ui\src\widget_layout.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\msf_ui\src\widget_menu.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\msf_ui\src\widget_msg_hdr.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\msf_ui\src\widget_paint.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\msf_ui\src\widget_paint_action.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\msf_ui\src\widget_paint_dialog.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\msf_ui\src\widget_paint_editor.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\msf_ui\src\widget_paint_gadget_bar.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\msf_ui\src\widget_paint_gadget_image.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\msf_ui\src\widget_paint_gadget_input.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\msf_ui\src\widget_paint_gadget_string.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\msf_ui\src\widget_paint_menu.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\msf_ui\src\widget_paintbox.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\msf_ui\src\widget_screen.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\msf_ui\src\widget_sound.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\msf_ui\src\widget_string.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\msf_ui\src\widget_style.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\msf_ui\src\widget_test.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\msf_ui\src\widget_text.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\msf_ui\src\widget_window.c
# End Source File 
# Begin Source File 
SOURCE=..\..\vendor\wap\obigo_q03c\adaptation\msf_ui\src\widget_winsocket.c
# End Source File 
# Begin Source File 
SOURCE=..\..\wapadp\src\wap_cmmn_utils.c
# End Source File 

# End Target
# End Project
