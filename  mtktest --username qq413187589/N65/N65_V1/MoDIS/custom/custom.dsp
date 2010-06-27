# Microsoft Developer Studio Project File - Name="custom" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=custom - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "custom.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "custom.mak" CFG="custom - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "custom - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "custom - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "custom - Win32 Release"
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
# ADD CPP @"custom.ini"
# ADD CPP /FD /GZ /c
# ADD BASE RSC /l 0x404 /d "NDEBUG"
# ADD RSC /l 0x404 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo
!ELSEIF  "$(CFG)" == "custom - Win32 Debug"
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
# ADD CPP @"custom.ini"
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
# Name "custom - Win32 Release"
# Name "custom - Win32 Debug"
# Begin Group "app"
# Begin Group "UNIRISE25_GEMINI_BB"
# Begin Source File 
SOURCE=..\..\custom\app\UNIRISE25_GEMINI_BB\app_features.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\app\UNIRISE25_GEMINI_BB\app_features.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\app\UNIRISE25_GEMINI_BB\custom_led_patterns.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\app\UNIRISE25_GEMINI_BB\custom_led_patterns.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\app\UNIRISE25_GEMINI_BB\custom_nvram_editor_data_item.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\app\UNIRISE25_GEMINI_BB\custom_uc_config.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\app\UNIRISE25_GEMINI_BB\custom_uc_config.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\app\UNIRISE25_GEMINI_BB\custom_wap_cfg.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\app\UNIRISE25_GEMINI_BB\nvram_cust_pack.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\app\UNIRISE25_GEMINI_BB\nvram_user_config.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\app\UNIRISE25_GEMINI_BB\nvram_user_defs.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\app\UNIRISE25_GEMINI_BB\resource_custpack_jtbl.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\app\UNIRISE25_GEMINI_BB\resource_custpack_jtbl.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\app\UNIRISE25_GEMINI_BB\resource_verno.h
# End Source File 
# End Group "UNIRISE25_GEMINI_BB"
# End Group "app"
# Begin Group "audio"
# Begin Group "UNIRISE25_GEMINI_BB"
# Begin Source File 
SOURCE=..\..\custom\audio\UNIRISE25_GEMINI_BB\MT6188.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\audio\UNIRISE25_GEMINI_BB\MT6189.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\audio\UNIRISE25_GEMINI_BB\NS953_SerialComm.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\audio\UNIRISE25_GEMINI_BB\TEA5761UK.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\audio\UNIRISE25_GEMINI_BB\TEA5767HN.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\audio\UNIRISE25_GEMINI_BB\audcoeff.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\audio\UNIRISE25_GEMINI_BB\custpack_audio.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\audio\UNIRISE25_GEMINI_BB\nvram_default_audio.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\audio\UNIRISE25_GEMINI_BB\nvram_default_audio.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\audio\UNIRISE25_GEMINI_BB\resource_audio.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\audio\UNIRISE25_GEMINI_BB\resource_audio.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\audio\UNIRISE25_GEMINI_BB\resource_audio_func.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\audio\UNIRISE25_GEMINI_BB\resource_audio_jtbl.c
# End Source File 
# End Group "UNIRISE25_GEMINI_BB"
# End Group "audio"
# Begin Group "common"
# Begin Source File 
SOURCE=..\..\custom\common\CharsetTable.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\common\CharsetTable.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\common\Conversions.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\common\Conversions.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\common\MemoryDevice_TypeDef.h
# End Source File 
# Begin Group "PLUTO_MMI"
# Begin Source File 
SOURCE=..\..\custom\common\PLUTO_MMI\common_nvram_editor_data_item.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\common\PLUTO_MMI\custom_mmi_default_value.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\common\PLUTO_MMI\nvram_common_config.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\common\PLUTO_MMI\nvram_common_defs.h
# End Source File 
# End Group "PLUTO_MMI"
# Begin Source File 
SOURCE=..\..\custom\common\WiFi_common_config.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\common\apm_TaskDef.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\common\aud_common.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\common\audcoeff_default.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\common\bt_common_config.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\common\bt_common_config.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\common\custom_atcmd_parse.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\common\custom_em.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\common\custom_em.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\common\custom_em_dummyDrv.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\common\custom_ems_context.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\common\custom_ems_context.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\common\custom_imps_config.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\common\custom_imps_config.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\common\custom_nvram_extra.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\common\custom_nvram_extra.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\common\custom_nvram_sec.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\common\custom_nvram_sec.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\common\custom_syncml_dm_config.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\common\custom_video.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\common\custom_video.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\common\custom_voip_config.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\common\custom_voip_config.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\common\custom_wap_config.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\common\custom_wap_config.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\common\custom_wap_cust_pack.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\common\customer_email_num.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\common\fs_quota.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\common\ft_bt_customize.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\common\ft_bt_customize.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\common\ft_customize.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\common\meta_customize.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\common\meta_customize.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\common\mmi_msg_context.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\common\mmi_msg_context.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\common\mms_gprs_config_default.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\common\mms_gprs_config_sm.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\common\mms_gprs_config_sm_th.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\common\mms_gprs_config_th.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\common\nvram_lid_statistics.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\common\syncml_common_customize.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\common\syncml_common_customize.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\common\syscomp_tasks_create_func.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\common\wap_gprs_config_defult.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\common\wap_gprs_config_sm.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\common\wap_gprs_config_sm_th.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\common\wap_gprs_config_th.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\common\wifi_common_config.h
# End Source File 
# End Group "common"
# Begin Group "drv"
# Begin Group "LCD"
# Begin Group "UNIRISE25_GEMINI_LCM"
# Begin Source File 
SOURCE=..\..\custom\drv\LCD\UNIRISE25_GEMINI_LCM\lcd.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\LCD\UNIRISE25_GEMINI_LCM\lcd_ft1505c_yt372604pe.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\LCD\UNIRISE25_GEMINI_LCM\lcd_ft1505c_yt372604pf.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\LCD\UNIRISE25_GEMINI_LCM\lcd_ft1505c_yt372804pk.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\LCD\UNIRISE25_GEMINI_LCM\lcd_ft1505c_yt372804pl.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\LCD\UNIRISE25_GEMINI_LCM\lcd_hw.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\LCD\UNIRISE25_GEMINI_LCM\lcd_sw.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\LCD\UNIRISE25_GEMINI_LCM\lcd_sw_inc.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\LCD\UNIRISE25_GEMINI_LCM\lcd_sw_rnd.h
# End Source File 
# End Group "UNIRISE25_GEMINI_LCM"
# End Group "LCD"
# Begin Group "analog_tv"
# Begin Group "TLG1100"
# Begin Source File 
SOURCE=..\..\custom\drv\analog_tv\TLG1100\tlg1100.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\analog_tv\TLG1100\tlg1100.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\analog_tv\TLG1100\tlg1100Api.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\analog_tv\TLG1100\tlg1100Api.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\analog_tv\TLG1100\tlg1100App.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\analog_tv\TLG1100\tlg1100App.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\analog_tv\TLG1100\tlg1100ChnApi.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\analog_tv\TLG1100\tlg1100Config.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\analog_tv\TLG1100\tlg1100Hal.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\analog_tv\TLG1100\tlg1100Mfg.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\analog_tv\TLG1100\tlg1100customize.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\analog_tv\TLG1100\tlg1100i2c.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\analog_tv\TLG1100\tlg1100i2c_impl.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\analog_tv\TLG1100\tv_yuv_para.c
# End Source File 
# End Group "TLG1100"
# End Group "analog_tv"
# Begin Group "bluetooth"
# Begin Group "UNIRISE25_GEMINI_BB"
# Begin Source File 
SOURCE=..\..\custom\drv\bluetooth\UNIRISE25_GEMINI_BB\btmtk_config.c
# End Source File 
# End Group "UNIRISE25_GEMINI_BB"
# End Group "bluetooth"
# Begin Group "common_drv"
# Begin Source File 
SOURCE=..\..\custom\drv\common_drv\gpio_setting.c
# End Source File 
# End Group "common_drv"
# Begin Group "g_sensor"
# Begin Source File 
SOURCE=..\..\custom\drv\g_sensor\FSL_MMA.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\g_sensor\FSL_MMA_IIC.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\g_sensor\FSL_data.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\g_sensor\g_sensor.c
# End Source File 
# End Group "g_sensor"
# Begin Group "misc_drv"
# Begin Group "UNIRISE25_GEMINI_BB"
# Begin Source File 
SOURCE=..\..\custom\drv\misc_drv\UNIRISE25_GEMINI_BB\MT6302_custom.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\misc_drv\UNIRISE25_GEMINI_BB\adc_channel.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\misc_drv\UNIRISE25_GEMINI_BB\adc_channel.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\misc_drv\UNIRISE25_GEMINI_BB\alerter_tone.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\misc_drv\UNIRISE25_GEMINI_BB\alerterdrv.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\misc_drv\UNIRISE25_GEMINI_BB\auxmain.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\misc_drv\UNIRISE25_GEMINI_BB\batvalue.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\misc_drv\UNIRISE25_GEMINI_BB\bt_hw_define.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\misc_drv\UNIRISE25_GEMINI_BB\chr_parameter.c
# End Source File 
# Begin Group "codegen"
# Begin Source File 
SOURCE=..\..\custom\drv\misc_drv\UNIRISE25_GEMINI_BB\codegen\adc_var.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\misc_drv\UNIRISE25_GEMINI_BB\codegen\eint_drv.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\misc_drv\UNIRISE25_GEMINI_BB\codegen\eint_var.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\misc_drv\UNIRISE25_GEMINI_BB\codegen\gpio_drv.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\misc_drv\UNIRISE25_GEMINI_BB\codegen\gpio_var.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\misc_drv\UNIRISE25_GEMINI_BB\codegen\keypad_drv.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\misc_drv\UNIRISE25_GEMINI_BB\codegen\uem_drv.c
# End Source File 
# End Group "codegen"
# Begin Source File 
SOURCE=..\..\custom\drv\misc_drv\UNIRISE25_GEMINI_BB\custom_drv_init.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\misc_drv\UNIRISE25_GEMINI_BB\custom_equipment.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\misc_drv\UNIRISE25_GEMINI_BB\custom_equipment.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\misc_drv\UNIRISE25_GEMINI_BB\custom_hw_default.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\misc_drv\UNIRISE25_GEMINI_BB\custom_hw_default.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\misc_drv\UNIRISE25_GEMINI_BB\eint_def.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\misc_drv\UNIRISE25_GEMINI_BB\exif_custom.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\misc_drv\UNIRISE25_GEMINI_BB\gpio_def.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\misc_drv\UNIRISE25_GEMINI_BB\gpio_drv.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\misc_drv\UNIRISE25_GEMINI_BB\irda_custom.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\misc_drv\UNIRISE25_GEMINI_BB\keypad_def.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\misc_drv\UNIRISE25_GEMINI_BB\motion_sensor_hw_define.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\misc_drv\UNIRISE25_GEMINI_BB\msdc_custom.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\misc_drv\UNIRISE25_GEMINI_BB\pmic_custom.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\misc_drv\UNIRISE25_GEMINI_BB\pwmdrv.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\misc_drv\UNIRISE25_GEMINI_BB\sccb_v2_custom.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\misc_drv\UNIRISE25_GEMINI_BB\touch_panel_custom.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\misc_drv\UNIRISE25_GEMINI_BB\touch_panel_custom.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\misc_drv\UNIRISE25_GEMINI_BB\touch_panel_spi.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\misc_drv\UNIRISE25_GEMINI_BB\touch_panel_spi.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\misc_drv\UNIRISE25_GEMINI_BB\touchpad.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\misc_drv\UNIRISE25_GEMINI_BB\touchpad_custom.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\misc_drv\UNIRISE25_GEMINI_BB\touchpad_keydef.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\misc_drv\UNIRISE25_GEMINI_BB\uart_def.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\misc_drv\UNIRISE25_GEMINI_BB\uem_gpio.c
# End Source File 
# End Group "UNIRISE25_GEMINI_BB"
# End Group "misc_drv"
# Begin Group "yuv_sensor"
# Begin Source File 
SOURCE=..\..\custom\drv\yuv_sensor\camera_hw.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\yuv_sensor\camera_info.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\yuv_sensor\camera_yuv_para.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\yuv_sensor\image_sensor.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\yuv_sensor\image_sensor.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\yuv_sensor\image_sensor_BF3403.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\yuv_sensor\image_sensor_BF3503.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\yuv_sensor\image_sensor_BF3603.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\yuv_sensor\image_sensor_GC0307.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\yuv_sensor\image_sensor_GC0316.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\yuv_sensor\image_sensor_OV7670.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\yuv_sensor\image_sensor_OV7680.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\drv\yuv_sensor\usbvideo_attr.c
# End Source File 
# End Group "yuv_sensor"
# End Group "drv"
# Begin Group "l1_rf"
# Begin Group "UNIRISE25_GEMINI_MT6139E"
# Begin Source File 
SOURCE=..\..\custom\l1_rf\UNIRISE25_GEMINI_MT6139E\l1d_custom_rf.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\l1_rf\UNIRISE25_GEMINI_MT6139E\m12193.c
# End Source File 
# End Group "UNIRISE25_GEMINI_MT6139E"
# End Group "l1_rf"
# Begin Group "meta"
# Begin Group "UNIRISE25_GEMINI_BB"
# Begin Source File 
SOURCE=..\..\custom\meta\UNIRISE25_GEMINI_BB\ft_customize.c
# End Source File 
# End Group "UNIRISE25_GEMINI_BB"
# End Group "meta"
# Begin Group "ps"
# Begin Group "UNIRISE25_GEMINI_BB"
# Begin Source File 
SOURCE=..\..\custom\ps\UNIRISE25_GEMINI_BB\Customer_sim_voltage_support.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\ps\UNIRISE25_GEMINI_BB\custom_data_account.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\ps\UNIRISE25_GEMINI_BB\custom_data_account.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\ps\UNIRISE25_GEMINI_BB\custom_poc_config.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\ps\UNIRISE25_GEMINI_BB\custom_poc_config.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\ps\UNIRISE25_GEMINI_BB\customer_at_command.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\ps\UNIRISE25_GEMINI_BB\customer_cm_retry_count.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\ps\UNIRISE25_GEMINI_BB\customer_cmux_setting.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\ps\UNIRISE25_GEMINI_BB\customer_operator_name.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\ps\UNIRISE25_GEMINI_BB\customer_ps_inc.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\ps\UNIRISE25_GEMINI_BB\customer_pwr_level_report.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\ps\UNIRISE25_GEMINI_BB\customer_recovery_timer_interval.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\ps\UNIRISE25_GEMINI_BB\customer_sms_msg_box_num.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\ps\UNIRISE25_GEMINI_BB\customer_sms_prefer_order.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\ps\UNIRISE25_GEMINI_BB\customer_sms_tl_retry.c
# End Source File 
# End Group "UNIRISE25_GEMINI_BB"
# End Group "ps"
# Begin Group "system"
# Begin Group "UNIRISE25_GEMINI_BB"
# Begin Source File 
SOURCE=..\..\custom\system\UNIRISE25_GEMINI_BB\custom1_create.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\system\UNIRISE25_GEMINI_BB\custom_EMI.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\system\UNIRISE25_GEMINI_BB\custom_MemoryDevice.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\system\UNIRISE25_GEMINI_BB\custom_config.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\system\UNIRISE25_GEMINI_BB\custom_config.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\system\UNIRISE25_GEMINI_BB\custom_fota.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\system\UNIRISE25_GEMINI_BB\custom_fota.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\system\UNIRISE25_GEMINI_BB\custom_jump_tbl.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\system\UNIRISE25_GEMINI_BB\custom_jump_tbl.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\system\UNIRISE25_GEMINI_BB\custom_sap.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\system\UNIRISE25_GEMINI_BB\custom_scatstruct.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\system\UNIRISE25_GEMINI_BB\custom_switchclock.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\system\UNIRISE25_GEMINI_BB\custom_util.c
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\system\UNIRISE25_GEMINI_BB\custom_util.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\system\UNIRISE25_GEMINI_BB\flash_opt.h
# End Source File 
# Begin Source File 
SOURCE=..\..\custom\system\UNIRISE25_GEMINI_BB\scatUNIRISE25_GEMINI.txt
# End Source File 
# End Group "UNIRISE25_GEMINI_BB"
# End Group "system"

# End Target
# End Project
