# Microsoft Developer Studio Project File - Name="mmi_framework" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=mmi_framework - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "mmi_framework.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "mmi_framework.mak" CFG="mmi_framework - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "mmi_framework - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "mmi_framework - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "mmi_framework - Win32 Release"
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
# ADD CPP @"mmi_framework.ini"
# ADD CPP /FD /GZ /c
# ADD BASE RSC /l 0x404 /d "NDEBUG"
# ADD RSC /l 0x404 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo
!ELSEIF  "$(CFG)" == "mmi_framework - Win32 Debug"
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
# ADD CPP @"mmi_framework.ini"
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
# Name "mmi_framework - Win32 Release"
# Name "mmi_framework - Win32 Debug"
# Begin Source File 
SOURCE=..\..\plutommi\customer\custresource\custnfbprogressimg.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\bidi\bidisrc\bidi.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\bidi\bidisrc\bidi_l_rules.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\bidi\bidisrc\bidicharmap.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\bidi\bidisrc\bidipararules.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\bidi\bidisrc\bidiprocessdatatypes.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\commonscreens\commonscreenssrc\appmem.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\commonscreens\commonscreenssrc\commonscreens.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\debuglevels\debuglevelsrc\debuginit.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\editorpen\editorpensrc\editorpen.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\editorpen\editorpensrc\editorpen_hw.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\editorpen\editorpensrc\editorpen_im.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\editorpen\editorpensrc\editorpen_vk.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\framework\commonfiles\commonsrc\frameworkbackwardcompatible.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\framework\eventhandling\eventssrc\event_handler.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\framework\eventhandling\eventssrc\events.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\framework\eventhandling\eventssrc\keybrd.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\framework\eventhandling\eventssrc\mmitimer.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\framework\eventhandling\eventssrc\sublcd_master.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\framework\eventhandling\eventssrc\touchscreen.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\framework\history\historysrc\history.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\framework\history\historysrc\sublcdhistory.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\framework\memmanager\memmanagersrc\appmemmgr.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\framework\memmanager\memmanagersrc\resmemmgr.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\framework\memmanager\memmanagersrc\scrmemmgr.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\framework\nvrammanager\nvrammanagersrc\nvraminterface.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\framework\osl\oslsrc\l4drv.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\framework\osl\oslsrc\lcddrv.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\framework\osl\oslsrc\wrapper.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\framework\tasks\taskssrc\mmitask.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\framework\tasks\taskssrc\queue.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\framework\tasks\taskssrc\taskinit.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\framework\thememanager\thememanagersrc\themearchiver.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\framework\thememanager\thememanagersrc\themeconverterui.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\framework\thememanager\thememanagersrc\themeconverterxml.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\framework\thememanager\thememanagersrc\thememanager.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\gui.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\gui_asyncdynamic_menus.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\gui_buttons.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\gui_bytestream.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\gui_calendar.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\gui_clock.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\gui_color_slider.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\gui_custom_menus.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\gui_dynamic_menus.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\gui_ems.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\gui_fixed_menuitems.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\gui_fixed_menus.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\gui_hardware_dependent.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\gui_inputs.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\gui_lang_viet.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\gui_menu_shortcut.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\gui_panel.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\gui_scrollbars.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\gui_spectrum.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\gui_tab_bars.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\gui_text_label.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\gui_themes.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\gui_title.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\gui_virtual_keyboard.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\gui_windows.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\wgui.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\wgui_asyncdynamic_menuitems.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\wgui_asyncdynamic_menus.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\wgui_calendar.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\wgui_categories.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\wgui_categories_calendar.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\wgui_categories_cm.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\wgui_categories_email.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\wgui_categories_ems.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\wgui_categories_fmgr.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\wgui_categories_idlescreen.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\wgui_categories_imps.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\wgui_categories_inputs.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\wgui_categories_list.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\wgui_categories_mm.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\wgui_categories_mms.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\wgui_categories_mms_viewer.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\wgui_categories_multimedia.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\wgui_categories_panel.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\wgui_categories_pe.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\wgui_categories_popup.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\wgui_categories_stopwatch.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\wgui_categories_sublcd.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\wgui_categories_tab.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\wgui_categories_uce.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\wgui_categories_util.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\wgui_clock.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\wgui_datetime.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\wgui_draw_manager.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\wgui_dynamic_menuitems.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\wgui_dynamic_menus.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\wgui_ems.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\wgui_fixed_menuitems.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\wgui_fixed_menus.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\wgui_inline_edit.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\wgui_inputs.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\wgui_panel.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\wgui_softkeys.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\wgui_status_icons.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\wgui_tab_bars.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\wgui_text_label.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\wgui_title.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\wgui_touch_screen.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\wgui_virtual_keyboard.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\gui_src\wingui.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\oem_src\gui_effect_oem.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\oem_src\gui_main_menu_oem.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\oem_src\gui_menu_oem.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\oem_src\gui_scrollbars_oem.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\oem_src\gui_title_oem.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\oem_src\wgui_hint_oem.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gui\oem_src\wgui_softkey_oem.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\indiclanguages\indiclanguagessrc\bengali.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\indiclanguages\indiclanguagessrc\hindi.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\indiclanguages\indiclanguagessrc\indicruleengine.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\indiclanguages\indiclanguagessrc\indicruleenginecommon.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\indiclanguages\indiclanguagessrc\marathi.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\indiclanguages\indiclanguagessrc\punjabi.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\indiclanguages\indiclanguagessrc\tamil.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\indiclanguages\indiclanguagessrc\telugu.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\languages\thai\thaisrc\thai.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\miscframework\miscframeworksrc\arabicshapingengine.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\miscframework\miscframeworksrc\ascii.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\miscframework\miscframeworksrc\bootupapp.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\miscframework\miscframeworksrc\eons.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\miscframework\miscframeworksrc\gsm7bitdefaultalphabet.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\miscframework\miscframeworksrc\mempoolcontainer.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\miscframework\miscframeworksrc\mmiinitapp.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\miscframework\miscframeworksrc\networkfunctions.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\miscframework\miscframeworksrc\personalization.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\miscframework\miscframeworksrc\pixcomfontengine.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\miscframework\miscframeworksrc\plmnname.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\miscframework\miscframeworksrc\profilingengine.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\miscframework\miscframeworksrc\pwroncharger.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\miscframework\miscframeworksrc\quickaccessmenuitem.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\miscframework\miscframeworksrc\screenrotation.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\miscframework\miscframeworksrc\shutdownapp.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\miscframework\miscframeworksrc\simdetection.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\miscframework\miscframeworksrc\smlmenu.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\miscframework\miscframeworksrc\smscore.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\miscframework\miscframeworksrc\smsmsg.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\miscframework\miscframeworksrc\smsutil.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\miscframework\miscframeworksrc\ucs2.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\mte\mtesrc\mte.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\resource\abmloader.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\resource\populateres.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\resource\readres.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\resource\writeres.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\csbrowser\csbrowsersrc\catscreenbrowser.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\csbrowser\csbrowsersrc\csbentryhandlers.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\csbrowser\csbrowsersrc\csbframework.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\gdi\gdisrc\gd_2d_engine.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\gdi\gdisrc\gd_primitive.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\gdi\gdisrc\gd_primitive16.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\gdi\gdisrc\gd_primitive24.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\gdi\gdisrc\gd_primitive32.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\gdi\gdisrc\gd_primitive8.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\gdi\gdisrc\gdc_main.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\gdi\gdisrc\gdd_main.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\gdi\gdisrc\gdi.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\gdi\gdisrc\gdi_2d_engine.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\gdi\gdisrc\gdi_animate.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\gdi\gdisrc\gdi_bytestream.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\gdi\gdisrc\gdi_font.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\gdi\gdisrc\gdi_image.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\gdi\gdisrc\gdi_image_alpha_bmp.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\gdi\gdisrc\gdi_image_avatar.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\gdi\gdisrc\gdi_image_bmp.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\gdi\gdisrc\gdi_image_decoder.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\gdi\gdisrc\gdi_image_dev_bmp.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\gdi\gdisrc\gdi_image_gif.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\gdi\gdisrc\gdi_image_hwgif.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\gdi\gdisrc\gdi_image_hwjpg.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\gdi\gdisrc\gdi_image_jpeg.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\gdi\gdisrc\gdi_image_m3d.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\gdi\gdisrc\gdi_image_png.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\gdi\gdisrc\gdi_image_sequence.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\gdi\gdisrc\gdi_image_svg.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\gdi\gdisrc\gdi_image_virtualfile.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\gdi\gdisrc\gdi_image_wbmp.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\gdi\gdisrc\gdi_layer.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\gdi\gdisrc\gdi_lcd.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\gdi\gdisrc\gdi_lfs.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\gdi\gdisrc\gdi_mutex.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\gdi\gdisrc\gdi_primitive.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\gdi\gdisrc\gdi_util.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\gdi\gdisrc\gdi_w32_lcd.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\mmiapi\src\mmiapi_main.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\mmiapi\src\mmiapi_sms.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\mmiapi\src\mmiapi_sms_msg.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\mmiapi\src\mmiapi_ui.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\mmiapi\src\mmiapi_wap.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\mtkappsrc\ctk.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\mtkappsrc\wap_stub.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\svg\svgsrc\svg_attribute.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\svg\svgsrc\svg_element.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\svg\svgsrc\svg_hash.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\svg\svgsrc\svg_intersect.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\svg\svgsrc\svg_main.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\svg\svgsrc\svg_parser.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\svg\svgsrc\svg_parser_animate.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\svg\svgsrc\svg_parser_animate_motion.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\svg\svgsrc\svg_parser_circle.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\svg\svgsrc\svg_parser_defs.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\svg\svgsrc\svg_parser_ellipse.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\svg\svgsrc\svg_parser_font.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\svg\svgsrc\svg_parser_group.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\svg\svgsrc\svg_parser_image.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\svg\svgsrc\svg_parser_line.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\svg\svgsrc\svg_parser_path.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\svg\svgsrc\svg_parser_polygline.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\svg\svgsrc\svg_parser_polygon.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\svg\svgsrc\svg_parser_rect.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\svg\svgsrc\svg_parser_svg.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\svg\svgsrc\svg_parser_switch.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\svg\svgsrc\svg_parser_text.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\svg\svgsrc\svg_parser_use.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\svg\svgsrc\svg_pqueue.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\svg\svgsrc\svg_render.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\svg\svgsrc\svg_render_animate.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\svg\svgsrc\svg_render_animate_motion.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\svg\svgsrc\svg_render_circle.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\svg\svgsrc\svg_render_ellipse.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\svg\svgsrc\svg_render_image.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\svg\svgsrc\svg_render_line.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\svg\svgsrc\svg_render_path.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\svg\svgsrc\svg_render_rect.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\svg\svgsrc\svg_render_svp.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\svg\svgsrc\svg_render_text.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\svg\svgsrc\svg_render_use.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\svg\svgsrc\svg_render_vpath.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\svg\svgsrc\svg_smalloc.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\svg\svgsrc\svg_style.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\svg\svgsrc\svg_svp.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\svg\svgsrc\svg_transform.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\svg\svgsrc\svg_util.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\svg\svgsrc\svg_viewer.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\svg\svgsrc\svg_viewport.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\svg\svgsrc\svg_vpath.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\svg\svgsrc\svg_work_buffer.c
# End Source File 

# End Target
# End Project
