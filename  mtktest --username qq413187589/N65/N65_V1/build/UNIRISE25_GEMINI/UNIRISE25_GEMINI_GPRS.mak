#
#  Copyright Statement:
#  --------------------
#  This software is protected by Copyright and the information contained
#  herein is confidential. The software may not be copied and the information
#  contained herein may not be used or disclosed except with the written
#  permission of MediaTek Inc. (C) 2005
#
#  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
#  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
#  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
#  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
#  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
#  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
#  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
#  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
#  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
#  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
#  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
#  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
#
#  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
#  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
#  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
#  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
#  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
#
#  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
#  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
#  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
#  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
#  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
#
#
# *************************************************************************
#
#        MediaTek Inc GSM/GPRS Wireless Communicatin Project
#              Build/Make Development Tools
#
#                 Copyright (C) 2002
#
#        Author         Date        Description
#        Rex Luo  2002/06/07     Create version 1.0
#
# *************************************************************************
#  MTK_GPRS.BLD  - Build option script
#
#  DISCUSSION:
#  USAGE:
#  IMPORTANT NOTES:
# *************************************************************************
#
#  Copyright Statement:
#  --------------------
#     This software is protected by Copyright and the information contained
#  herein is confidential. The software may not be copied and the information
#  contained herein may not be used or disclosed except with the written
#  permission of MediaTek Inc. (C) 2002
#
# *************************************************************************

-include make\Custom.bld         # Custom release build
ifndef CUSTOM_RELEASE
CUSTOM_RELEASE =  FALSE
endif

#**********************************************************************************************
# Huyanwei Add Macro Control 
#**********************************************************************************************
#6225上软件播放MP4功能
SF_MP4_SUPPORT  = FALSE  #TRUE FALSE  确定是否在6225上打开MP4播放功能
#******************************************************
SDEC_SUPPORT 		= TRUE  #使用新的MP4库,不能与SF_MP4_SUPPORT同时定义为TRUE sf_3gp huyi-20080414
#******************************************************
#******	Huyanwei 设置版本状态D = Debug A = Alpha B = Beta R = Release
NOKE_VER = R
#D A B R
#******************************************************
#******	Huyanwei Define Customer    设置项目
NOKE_PROJECT = N65

#******	Huyanwei Define Hardware Version    设置硬件版本号
NOKE_PCB_VERSION = V2P0

#**********设置RFPA 类型
NOKE_RFPA_MODULE = RF7168
                                     #TQM6M4003  
                                     #TQM6M4002
                                     #TQM6M4038  
                                     #RFMD3168
                                     #RDA6212
                                     #RF7168
#**********************************************************************
#**********设置RFPA 频段
NOKE_RFPA_FREQ =  850|900|1800|1900
# 850 900 1800 1900
# E203  => 900|1800|1900
# E203A => 850|900|1800|1900
#**********************************************************************

#**********设置按键定义版本
NOKE_KEYBOARD_VERSION = V1

#**********设置开关机动画和铃声
NOKE_POWER_ONOFF_ANIMATION = SMILE
                                     #TEST                        # 内部测试版本时使用这个
                                     #NOKE
                                     #CAR
                                     #GLASSBALL
                                     #BUTTERFLY
                                     #NEX                           # buttery fly ring
                                     #MISO                        # buttery fly ring
                                     #IMUSIC                    # buttery fly ring
                                     #MASTER                   # buttery fly ring
                                     #IPHONE                    # iphone ring
                                     #JPHONE                    # iphone ring
                                     #APHONE                    # iphone ring
                                     #MPMOBILE
                                     #STARPHONE
                                     #SCOOL                      #修改wap参数 
				#ZYQ
				#SMILE
                                     
NOKE_POWER_ONOFF_RING = NOKE
                                     #NOKE
                                     #CAR
                                     #GLASSBALL
                                     #BUTTERFLY
                                     #MASTER
                                     #IPHONE


#**************************************************************************************************************************
#******	Huyanwei Define Customer    设置版本发布客户
NOKE_CUSTOMER = ADH
#远信通YXT,锋辉达FHD ，爱德鹤ADH，鼎延DY,创泰CT，东林国际DLGJ
#******************************************************
#******	 设置泰文手写支持,只有在定义了泰文的时候才生效
NOKE_HANDWRITE_THAI = TRUE
#******************************************************
#******	 设置泰文手写库支持英文,需要NOKE_HANDWRITE_THAI=true支持
NOKE_HANDWRITE_THAI_AS_ENGLISH = TRUE
#**********************中文时,打开这HAND_WRITING 宏 *****
HAND_WRITING 	  = 	MMI_HANWANG       	# Input methods: NONE, MMI_HANWANG, MMI_PENPOWER 
#**************************************************************************************************************************
#******	Huyanwei Add Languages Control 设置语言,目前字符串Excel只有以下九国是完全的
NOKE_LANGUAGE = EN_SM
#EN_PO_AR_TU_PE_FR_SP_TH_RU
#EN_AR_TU_PE_FR_RU_VI_TH_IN_SP_PO_MA_GE
#EN_AR_TU_PE_FR_RU_VI_TH_IN_SP_PO_MA_GE_GR_IT
#EN_AR_TU_PE_FR,#EN_SM,#EN_RU_VI_SM,#EN_TH
#英文EN,简体中文SM,阿拉伯文AR,土耳其TU,波斯PE,法文FR,俄文RU,越南文VI,泰文TH,印尼IN ,西班牙SP ,葡萄牙PO,马来西亚MA,
#**********************************************************************
#**********设置LCD 类型
NOKE_GPRS_CONFIG=GPRS_DEFAULT
#GPRS_TH
#GPRS_SM
#GPRS_SM_TH
#GPRS_DEFAULT
#**********************************************************************
#**********设置LCD 类型
NOKE_LCD=FT1505C_YT372804PL
# FT1505C_YT372604PE      
# FT1505C_YT372604PF   
# FT1505C_YT372804PK  
# FT1505C_YT372404PQ
# FT1505C_YT372804PL
#**********************************************************************
#**********设置G-Sensor
NOKE_G_SENSOR = TRUE
#**********************************************************************
#**********G SENSOR GAME
NOKE_GSENSOR_GAME_SUPPORT       = FALSE
#**********************************************************************
#**********设置M-Sensor
NOKE_M_SENSOR = FALSE 
#**********************************************************************
#**********设置特效
NOKE_EFFECT = FALSE
#**********************************************************************
#**********设置跑马灯
NOKE_HORSERACE = FALSE
#**********************************************************************
#**********设置FLASH类型 
NOKE_FLASHTYPE =K5L2731CAA
                                                 #K5L2731CAA                   SM 128+32
                                                 #K5L2731CAM                   SM 128+32
                                                 #K5L5563CAA                     SM 256+64
                                                 #K5L5563CAM                    SM 256+64
                                                 #M36L0T7050T3ZAQ       ST 128+32
NOKE_MEMORY_DEVICE_TYPE=NOR_RAM_MCP
                                                 # NOR_RAM_MCP  LPSDRAM  NOR_LPSDRAM_MCP 
#**********************************************************************
#**********设置 RAR 程序路径
NOKE_RARPATH:="C:\Program Files\WinRAR"
#**********************************************************************
#**********设置摄像头列表, 增加摄像头时修改
CAMERA_SENSOR_SUPPORT_LIST = GC0316 OV7670 OV7680
#**********设置主摄相头
CMOS_SENSOR 		= OV7680
#**********设置副摄相头
SUB_CMOS_SENSOR 	=  OV7680
#**********设置双摄相头
NOKE_DOUBLE_CAMERA = FALSE
#**********设置摄相头130W 作弊
NOKE_CAMERA_130W_CHEAT = FALSE
#**********设置摄相头闪光灯
NOKE_CAMERA_WITH_FLASH = TRUE
#**********设置手电筒
NOKE_FLASHLIGHT_SUPPORT = TRUE
#**********设置验钞灯
NOKE_COUNTERFEIT_MONEY_LAMP_SUPPORT = FALSE
#**********************************************************************
#**********设置是否存在音量侧键
NOKE_SIDE_VOL_KEY=TRUE
#**********************************************************************
#**********设置双电池
NOKE_DOUBLE_BATTERY = FALSE
#**********************************************************************
#**********设置电视录制
NOKE_TV_RECORD=  FALSE
#**********************************************************************
#**********设置新的蓝牙芯片，但是用6601 协议栈
NOKE_BLUETOOTH_CHIP = MT6601
#hongzhe.liu add for 5868 bt chip, use 6601 stack
#**********************************************************************
###设置ok 键背光灯
NOKE_KEY_ENTER_BACKLIGHT_SUPPORT = TRUE

#********** 设置默认卡模式********************************************
NOKE_DEFAULT_DUAL_SIM_SUPPORT = TRUE
                                                              # TRUE
                                                              # FALSE

#**********JAVA SUPPORT  
#Modify by James 
J2ME_SUPPORT       = NONE # NONE, IJET, JBLENDIA, JBED
# NONE, IJET, JBLENDIA, JBED
#**********************************************************************
#**********************************************************************
#*********设置振动喇叭******************************************
VIBRATOR_TONE_SUPPORT =  FALSE  #TRUE and FALSE,default TRUE
#**********************************************************************
#如果sim 卡座需要交换，打开这个宏,现在已经用__DRV_DUAL_SIM_INVERSE__ 代替
EXCHANGE_SIM1_AND_SIM2 = FALSE
#*********设置左软键**************************************************
MTK_NO_LSK = TRUE 
#**********************************************************************
#软件插植到130M,200M
# 
#define __MMI_CAMERA_130M_SENSOR__ 130M
#define __MMI_CAMERA_200M_SENSOR__ 200M
#NOKE_CAMERA_TO_XXX_SUPPORT_ = 200M
#define __MMI_CAMERA_200M_SENSOR__
#**********************************************************************
ANALOG_TV_CHIP 				= TLG1100       		#NONE ,TLG1100

FM_RADIO_WITH_TV_CHIP		= TRUE   			# FALSE, TRUE , 模拟电视芯片使能收音机功能

FM_RADIO_CHIP     = NONE   
                                   #MT6188A1
                                   #RDA5800   
                                   #RDA5802
                                   #RDA5802E
                                   #RDA5803
                                   #  NONE

#设置fm 天线位置
FM_RADIO_ANTENNA_POS = NONE 
                                       # CHIP , 芯片内置天线
                                       # PCB, pcb上的天线
                                       # HEADSET , 耳机天线
                                       # NONE

FM_RADIO_RECORD  =  TRUE     #TRUE/FALSE


#**********************************************************************
# 第三方软件
#**********************************************************************


# *************************************************************************
# Feature Options (TRUE or FALSE)
# *************************************************************************

COMPILER          =  ADS       # RVCT or ADS

RVCT_MULTI_FILE   =  NONE      # NONE for ADS compiler
                               # NONE or MULTI_FILE for RVCT compiler

L1_CATCHER        =  TRUE        # L1 Catcher Support

MTK_SLEEP_ENABLE  =  TRUE       # Sleep Mode Support

RTOS              =  NUCLEUS   # NUCLEUS or THREADX

RTOS_DEBUG          =  TRUE        # Nucleus Plus Debug Support

RF_MODULE         =  UNIRISE25_GEMINI_MT6139E     # BRIGHT2, BRIGHT4, MT6119, AERO, FOUNTAIN, FOUNTAIN2, SPRING, KLM2003_FOUNTAIN2, KLM2003_SPRING
                                 # CHICAGO2003_FOUNTAIN2, CHICAGO2003_AERO, CANNON_FOUNTAIN2, MT6129D, AERO1PLUS

L1_GPRS           =  TRUE        # L1 GPRS Funtion, Notice: MT6205 don't support that

MTK_DSP_DEBUG     =  FALSE       # DSP Debugging Feature

CSD_SUPPORT       =  TRUE       # CSD Feature

PMIC              =  MT6305        # Charge Function, NONE, MT6305 or MT6318

PLATFORM          =  MT6225      # Hardware Platform, MT6208, FPGA, MT6218, MT6218B, MT6219, MT6226, MT6227, MT6228, MT6229 ...etc.

CHIP_VER          =  S00         # Chip version code of Platform MT6218B, SHOULD BE ONE OF THE FOLLOWINGS
                                 # BN, CN, DN, EN, FN
                                 # S00 for MT6228

CHIP_VERSION_CHECK    = TRUE       #  TRUE, FALSE
                                   # TURE: enable HW ID check
                                   # FALSE: disable HW ID check

MCUROM_SUPPORT    =  FALSE        # Only works for MT6226 and MT6227

UID_SUPPORT       =  FALSE       # TRUE or FALSE
                                 # For MT6226M, MT6226-9. FALSE for basic/evb/l1s

BOARD_VER         =  UNIRISE25_GEMINI_BB # Baseband main board description, SHOULD BE ONE OF THE FOLLOWINGS
                                 # MT6208_EVB, MT6208_CEVB, MT6205_CEVB, ORDNANCE, KLM2003_BB, CHICAGO2003_BB,
                                 # MT6218_MW001, CANNON, MT6218B_EVB, JUPITER_EVB, MT6219_EVB,
                                 # MT6226_EVB, MT6227_EVB, MT6228_EVB, MT6229_EVB

SUB_BOARD_VER     =  PCB01       # MT6218_MW001 Baseband main board subversion, SHOULD BE ONE OF THE FOLLOWINGS
                                 # PCB01

LCD_MODULE        =  UNIRISE25_GEMINI_LCM  # Based on the LCM solutions (even multiple LCM modules for this project)
											# SHOULD BE ONE OF THE FOLLOWINGS, based on the LCM
											# MTKLCM				-	Mono, 	102x64
											# MTKLCM_COLOR		-	Color, 	120x160, for MT6218_MW001 or MT6205_CEVB
											# ORDNANCELCM		-	Mono, 	112x64
											# KLMLCM				-	Color,	128x128
											# INFOLCM			-	Color,	128x128
											# TOPPOLY_LCM     -  Color,   128x160, for MT6218B_EVB
											# SONY_LCM        -  Color,   176x220, for JUPITER_EVB

MCU_CLOCK	  =	MCU_104M		# MCU clock setting, MCU_13M, MCU_26M, MCU_39M, MCU_52M, MCU_104M

MCU_DCM           =  DCM_ENABLE  # DCM_ENABLE, DCM_DISABLE
                                  # Dynamic Clock Management
                                  # Available BB chip: MT6217, MT6226, MT6226M, MT6227, MT6228, MT6229...etc.

EXT_CLOCK			=	EXT_26M		# External clock source setting, EXT_13M, EXT_26M

CUSTOM_CFLAGS     =  #-g -gtp          # custom flag

MMI_VERSION 		= 	PLUTO_MMI  	# FCB_MMI, PLUTO_MMI, BW_MMI, EMPTY_MMI, CHICAGO_MMI, KLM_MMI

EMPTY_RESOURCE    =  TRUE       #

SPLIT_SYSTEM      =  FALSE       # Split system feature

MCD_SUPPORT       =  TRUE       # MCD support feature

TST_SUPPORT			=	TRUE			# TST task Support

TCPIP_SUPPORT     =  UDP_TCP    # UDP_TCP, UDP, TCP, or NONE

TELECA_FEATURE    =  WAP2_SEC_MMS   # Teleca WAP support feature:
                                # WAP, WAP2, WAP_MMS WAP2_MMS or NONE

IRDA_SUPPORT      =  FALSE       # IRDA support feature

INPUT_METHOD 	  = 	MMI_ZI        	# Input methods: NONE, MMI_T9, or MMI_ZI

#HAND_WRITING 	  = 	MMI_HANWANG       	# Input methods: NONE, MMI_HANWANG, MMI_PENPOWER

DICT_SUPPORT	  =	NONE			# Dictionary library: NONE, MMI_GV, MMI_MOTECH, MMI_TRILOGY

AFC_VCXO_TYPE     = VCXO		  # VCTCXO     : VCTCXO
                                # VCXO       : VCXO
                                # VCXO_SC    : VCXO with 7 area slope control
                                # VCXO_TC    : VCXO with temperature compensation
                                # VCXO_SC_TC : VCXO with 7 area slope control & temperature compensation


EXT_CAM_MODULE   = NONE  			# AIT102N, AIT103, NONE
                                 # Chip above MT6218B  support camera interface

CAMERA_MODULE_WITH_LCD = FALSE	# TRUE or FALSE

HORIZONTAL_CAMERA = FALSE       # FALSE, TRUE
                                # To enable horizontal camera feature.
                                # Add HORIZONTAL_CAMERA to global compile option when the value is TRUE.


MELODY_VER	     = 	DSP_WT_SYN  	# SW_SYN_8K, SW_SYN_16K, EXT_AUDIO_CHIP, SIN_WAV_SYN, DSP_WT_SYN
                                 # SIN_WAV_SYN supported since MT6208
				  							# SW_SYN_8K supported since MT6205B, that means it is not valid on MT6208, MT6205
				  							# DSP_WT_SYN supported since MT6218B, that means it is not valid on MT6208, MT6205, MT6205B and MT6218

WAVETABLE_VER     = WT300K         # Wavetable version, Please choose one among:
					                  #  WT600K or WT150K for SW_SYN_16K and SW_SYN_8K
					                  #  WT600K for DSP_WT_SYN


MELODY_CHIP       =   NONE       # YAMAHA_MA3, ROHM_8788, NONE


DEDI_AMR_REC      =  TRUE      # AMR recording in GSM traffic mode. This function requires more than 50%MCU computing power.
				# For running smoothly, the system needs to be equipped with good flash/SRAM that have short
				# access time and page mode been enabled.

VR_ENGINE         =   NONE       #  NONE, VR_CYBERON

VRSI_LANGUAGE     =  NONE     # VRSI language,
                              # CYBERON_TWBI, CYBERON_CNBI, NONE

SW_CHANGE_BLOCKING  = FALSE             # TRUE is used to enforce backup on s set of important data items.

BAND_SUPPORT	    = QUAD		# support of designated band: PGSM900, EGSM900, RGSM900, DCS1800, PCS1900, GSM850, GSM450, GSM480, DUAL900, TRIPLE, QUAD, DUAL850

MSDC_CARD_SUPPORT_TYPE = MSDC_SD_MMC      #  MSDC_SD_MMC      for SD/MMC card support
                                          #  MSDC_MS 	      for MS card support
                                          #  MSDC_MSPRO       for MS-PRO card support
                                          #  NONE
                                          #  MT6218B, MT6217, MT6219 support MSDC
                                          #  MT6218, MT6205B, MT6208 don't support MSDC




NAND_SUPPORT     =  FALSE      # NAND SUPPORT

SYSTEM_DRIVE_ON_NAND = FALSE   # FALSE : System Drive on NOR flash
                 	                              # TRUE : System Drive on NAND flash

APP_STORAGE_IN_SYS_DRV = TRUE   # To put Email and MMS message to NOR or NAND flash

USB_SUPPORT      =  TRUE       # MT6218B and MT6219 chip support USB

USB_IN_META_SUPPORT = FALSE    # TRUE, FALSE
                              # To enable USB suuport in META mode feature

USB_IN_NORMAL_MODE_SUPPORT =  TRUE  # TRUE,FALSE
                                     # To enable USB mass storage support in normal mode

OTG_SUPPORT      = FALSE       #  TRUE, FALSE
                               #  To enable OTG suuport  feature

J2ME_VM			       = NONE		# J2ME VM:  NONE, KVM, KVM_SOURCE, HI_VM, HI_VM_SOURCE, JAZELLE

J2ME_FEATURE_SET   = NONE		# J2ME_FEATURE_SET: NONE, BASIC, JTWI


SUPPORT_JSR_75_PIM  = FALSE

SUPPORT_JSR_184     = FALSE

SUPPORT_JSR_205     = FALSE

SUPPORT_INFUSIO     = FALSE

SUPPORT_SURFKITCHEN = FALSE


DRM_SUPPORT = NONE # DRM VENDOR: NONE, MTK, BSCI

DRM_VERSION = NONE # DRM VERSION: NONE, V01, V02, ALL

AMRWB_DECODE 		= TRUE		# TRUE/FALSE

AMRWB_ENCODE 		= TRUE		# TRUE/FALSE
					# MT6219 DSP cannot support AMRWB_ENCODE when GPRS connection

JPG_DECODE 			= JPG_SW		# NONE, JPG_SW

JPG_ENCODE 			= JPG_SW		# NONE, JPG_SW

GIF_DECODE 			= TRUE		# TRUE/FALSE

PNG_DECODE 			= PNG_SW  	# NONE, PNG_HW, PNG_SW

DAF_DECODE 			= TRUE		# TRUE/FALSE

MUSICAM_DECODE      = TRUE      # TRUE/FALSE

MJPG_SUPPORT		= TRUE		# TRUE/FALSE

MP4_CODEC 			= FALSE		# TRUE/FALSE

ISP_SUPPORT 		= TRUE		# TRUE, FALSE

AAC_DECODE 			= TRUE		# TRUE/FALSE

SENSOR_ROTATE           = SENSOR_ROTATE_0    # SENSOR_ROTATE_0, SENSOR_ROTATE_90, SENSOR_ROTATE_180, SENSOR_ROTATE_270

SENSOR_LOCATION         = SENSOR_ON_BODY     # SENSOR_ON_BODY, SENSOR_ON_CLAM

PHB_SIM_ENTRY	=  300 #100	# Phonebook Entry Number in SIM: 100, 200

PHB_PHONE_ENTRY	= 300	#500	# Phonebook Entry Number in NVRAM: 100, 200

PHB_LN_ENTRY	=	20 #40	# Call log; Last Number Entry Number: 10, 20, 50

EMAIL_SUPPORT           =  NONE   # NONE or  SMTP_POP3 or ALL

FS_SORT_SUPPORT		=  TRUE	  # Both file system and file manager will support sort function

FS_MOVE_SUPPORT		=  TRUE	  # Both file system and file manager will support move/copy function

FS_CHECKDRIVE_SUPPORT	= FALSE	  # Both file system and file manager will support check drive function

FS_QM_SUPPORT		=  TRUE	  # File system will support quota management mechanism

FS_TRACE_SUPPORT	=  FALSE  # File System will support trace function only if TST is supported

AEC_ENABLE              =  TRUE  # Acoustic Echo Cancellation (AEC)
                                  # TRUE, FALSE

EES_ENABLE              =  TRUE  # Enhanced Echo Suppression (EES)
                                  # TRUE, FALSE



BLUETOOTH_SUPPORT       = BTMTK_MT6601    # NONE,   BTMTK or BTMTK_MT6601

CMUX_SUPPORT	        = FALSE   #

DIGIT_TONE_SUPPORT      = FALSE   # TRUE or FALSE

TTS                     = NONE    # SIMPLE_TTS, COMPLEX_TTS or NONE

CUST_KEYPAD_TONE_SUPPORT = FALSE  # TRUE or FALSE

MED_PROFILE             = MED_HIGH  # MED_LOW, MED_NORMAL, MED_HIGH, MED_MODEM

XML_SUPPORT             = TRUE    # TRUE or FALSE

AMR_LINK_SUPPORT        = TRUE    # TRUE or FALSE

IMPS_SUPPORT            =  FALSE  # TRUE or FALSE, IMPS Feature Support

TOUCH_PANEL_SUPPORT     = MT6301   #  NONE, MT6301, MT6301B
                                 # touch panel feature
TOUCH_PAD_SUPPORT       = FALSE   #  TRUE or FALSE, TOUCH PAD Feature

DEMO_PROJECT		= FALSE   # TRUE, FALSE. TRUE for internal demo project.

GPRS_MAX_PDP_SUPPORT    = 2      # 2, 3, 4, 5, 6 or 7  Maximum simultaneous PDP contexts (2~7)

UART3_SUPPORT		= TRUE   # TRUE or FALSE,  SUPPORT UART 3

DMA_UART_VIRTUAL_FIFO   = TRUE   # TRUE or FALSE

SIP_SUPPORT 	= FALSE      # TRUE or FALSE

POC_SUPPORT 	= NONE       # NONE, V01 or ALL

XDM_SUPPORT    = FALSE      # TRUE or FALSE

PHONE_TYPE 	     =  BAR  # BAR, CLAMSHELL, SLIDE
                                   #  Default is BAR

SWDBG_SUPPORT        = FALSE     # MT6228 support software debug

NAND_FLASH_BOOTING   = FALSE    # MT6228 support NAND FLASH BOOTING

WMA_DECODE = FALSE              # MT6228 support WMA DECODE

LOW_COST_SUPPORT	= FALSE		#  General compile option for Low Cost features.
					#  Please not that a module can define its own low-cost levels, or it can just adopt this compile option.


SUB_LCD_SIZE = NONE # NONE, 48X64BW, 64X96, 96X64BW, 96X64, 128X128

MAIN_LCD_SIZE = 240X320                              # To distinguish the main lcd size.
                                                                        # We can use it to copy the matching resources, such themecomponents.h, Fontres.c, L_xxx.h, etc, to PLUTO_MMI folder

MMI_MAIN_LCD_DEFAULT_FORMAT   = DEFAULT      # DEFAULT, 16, 24, 32

MMI_SUB_LCD_DEFAULT_FORMAT    = DEFAULT      # DEFAULT, 16, 24, 32


SUBLCD_DEDICATED_KEYS_SUPPORT = FALSE     # TRUE/FALSE
                                          # FALSE: No dedicated keys for subLCD operation
                                          # TRUE:  Have dedicated keys for subLCD when clam close,
                                          # ex. KEY_MP3_PLAY_STOP, KEY_MP3_FWD, KEY_MP3_BACK

SINGLE_BANK_NOR_FLASH_SUPPORT   =  FALSE  # For low-cost (Flash size targetted at 16Mbits) single-bank NOR-flash solution, where partial of NVRAM is shadowed at RAM.

ENHANCED_SINGLE_BANK_NOR_FLASH_SUPPORT = FALSE # TRUE, FALSE
                                               # For single-bank NOR-flash solution without shadowed NVRAM requirement.

AAC_PLUS_DECODE  =  FALSE		# TRUE/FALSE

EMS_SUPPORT          = EMS_40   # EMS_40 support only EMS 4.0
                                # EMS_50 support EMS 5.0
                                # EMS_NONE support only pure text content.

R99_SUPPORT	    = TRUE	  # Release 99 support

WEBCAM_SUPPORT       = TRUE      # TRUE, FALSE for WEB CAMERA support

TV_OUT_SUPPORT 	      = FALSE	  # TRUE, FALSE  only MT6228 and MT6229 support TV OUT
#通话中,加入背景噪音
BACKGROUND_SOUND      = FALSE	  # TRUE/FALSE

AU_DECODE             = TRUE       #  TRUE, FALSE

AIFF_DECODE           = TRUE       #  TRUE, FALSE

JTONE_SUPPORT         = TRUE       #  TRUE, FALSE

AUDIO_3D_SURROUND     = NONE      # NONE, MODE_LSPK, MODE_EARP, MODE_BOTH
                                  # to enable 3D surround

AUDIO_POST_PROCESS    = NONE	  # NONE, ALL_EFFECT, REVERB_ONLY, TIME_STRETCH_ONLY

MOTION_SENSOR_SUPPORT = NONE      # NONE or KXP84_SPI or KXP84_I2C or KXP74_SPI or MXC6202_I2C
                                  # For motion sensor function support or not.

LENS_MODULE 	     = NONE		# NONE, HYSONIC_ID9701

AF_SUPPORT	     = FALSE		# TRUE or FALSE

DT_SUPPORT           = TRUE      # TRUE, FALSE

CTM_SUPPORT          = FALSE     # TRUE, FALSE

J2ME_JSR184_SUPPORT  = NONE	 # MTK_M3G, NONE

M3D_MMI_SUPPORT      = FALSE     # TRUE, FALSE

BT_CONNECT_TO_UART2  = FALSE      # TRUE, FALSE
                                  # TRUE: BT module is connected to UART2
                                  # FALSE: BT module is connected to UART3, this is general case for most projects
                                  # When this is set to TRUE, compile option __BT_USE_UART2__ is added to notify
                                  # driver BT is connected to UART2 port

BT_SIM_PROFILE       = FALSE      # TRUE, FALSE

BT_BIP_PROFILE       = FALSE    # TRUE, FALSE

BT_BPP_PROFILE       = TRUE      # TRUE, FALSE,

BT_HIDD_PROFILE      = FALSE      # TRUE, FALSE
                                  # Turn on or turn off bluetooth HID profile feature

BT_HFG_PROFILE       = TRUE      # TRUE, FALSE

BT_FTS_PROFILE       = TRUE      # TRUE, FALSE

BT_FTC_PROFILE       = TRUE      # TRUE, FALSE

BT_OPP_PROFILE       = TRUE      # TRUE, FALSE

BT_DUN_PROFILE       = TRUE      # TRUE, FALSE

BT_SPP_SERVER        = BT_SPP_SRV_NO_SCO       # NONE, BT_SPP_SRV_NO_SCO or BT_SPP_SRV_WITH_SCO (default:BT_SPP_SRV_NO_SCO)
                                  # This is only used in BLUETOOTH_SUPPORT = BTMTK_MT6601
                                  # If BLUETOOTH_SUPPORT is not BTMTK_MT6601, its value must be NONE

BT_SPP_CLIENT        = NONE       # NONE, BT_SPP_CLI_NO_SCO or BT_SPP_CLI_WITH_SCO (default: NONE)
                                  # This is only used in BLUETOOTH_SUPPORT = BTMTK_MT6601
                                  # If BLUETOOTH_SUPPORT is not BTMTK_MT6601, its value must be NONE

BT_SPP_PROFILE       = TRUE      # TRUE, FALSE

BT_A2DP_PROFILE      = TRUE      # TRUE, FALSE

BT_AVRCP_PROFILE     = TRUE      # TRUE, FALSE
                                  # Turn on or off AVRCP profile feature

LCM_ROTATE_SUPPORT   = FALSE     # TRUE, FALSE

SVG_SUPPORT          = FALSE     # TRUE, FALSE
                                 # support SVG image format

WIFI_SUPPORT         =  NONE     #  MTK_WIFI, WIFI_LIB, NONE

WIFI_BB_MODULE       =  NONE     # MT5911

WIFI_RF_MODULE       =  NONE     # AL2236, MAX2827

OPENGL               =  NONE     # COMMON_LITE, NONE
                                 # This compile option is defined for 3D graphics engine.
                                 # Only MT6228 and MT6229 support OPENGL.

USB_MULTI_CHARGE_CURRENT_SUPPORT = FALSE  # TRUE, FALSE
                                          # Turn On or Off USB multiple charging-current support

RC5_SUPPORT          = TRUE      # TRUE or FALSE, RC5 feature support

GAME_ENGINE          = NONE      # NONE, GE_BROGENT
                                 # to add game engine

YUV_SENSOR_SUPPORT   = TRUE     # TRUE, FALSE
                                 # to enable YUV sensor interface

EXT_DAC_SUPPORT      = FALSE     # TRUE, FALSE
                                 # To enable the interface between AFE control and EXT_DAC control.

UNIFIED_MESSAGE_SUPPORT  = FALSE # TRUE or FALSE, unified message support
                                 # GSM project can NOT support UNIFIED_MESSAGE

UNIFIED_MESSAGE_SIMBOX_SUPPORT  = FALSE   # TRUE, FALSE,
                                          # only can be turned on if unified message feature is turned on.

DRV_CUSTOM_TOOL_SUPPORT  = TRUE # TRUE or FALSE, To enable using driver customization tool for GPIO/EINT/ADC/UEM/Keypad setting.

JATAAYU_FEATURE      = NONE      # Jataayu wap feature support:
                                 # NONE, WAP, WAP_MMS,  WAP2, WAP2_MMS.
                                 # WAP_SEC, WAP2_SEC, WAP_SEC_MMS, WAP2_SEC_MMS

WAP_SUPPORT          = OBIGO_Q03C	# NONE, OBIGO_Q03C, JATAAYU4

DSPIRDBG             = FALSE      # IRDBG interface for dsp debugging
                                 # only support in 6229 E2 and MT6225

BARCODE_DECODER     = NONE       # NONE, SCANBUY

SECURE_SUPPORT      = FALSE       #

SECURE_VERSION      = 1          #

SECURE_JTAG_ENABLE  = FALSE       #

SECURE_CUSTOM_NAME  = MTK        # MTK (6227C/6225 EVB) or JRD (JRD_06A)

SECURE_RO_ENABLE    = FALSE       # TRUE, FALSE

DISPLAY_TYPE        = COLOR      # BW, COLOR

OTP_SUPPORT         = FALSE      # TRUE, FALSE

SW_FLASH           = NONE    # NONE

SYNCML_SUPPORT                   = FALSE        # TRUE or FALSE

UNIFIED_MESSAGE_ADVANCE_FEATURE = NONE  	# Unified message advance feture:
                                                       # NONE, COMPOSER, LISTOPTION, ARCHIVE,
                                                       # COMPOSER_LISTOPTION, COMPOSER_ARCHIVE, LISTOPTION_ARCHIVE, COMPOSER_LISTOPTION_ARCHIVE
                                                       # Only support when unified message feature is turned on.

STREAM_SUPPORT		 = FALSE		# TRUE or FALSE

PGDL_SUPPORT		 = FALSE		# TRUE or FALSE

RTSP_SUPPORT		 = FALSE		# TRUE or FALSE

FOTA_ENABLE          = NONE      # FOTA_FULL, NONE

BT_AUDIO_VIA_SCO     = FALSE     # TRUE, FALSE
                                  # Support Audio being passed by BT SCO Link.

BT_FM_RADIO_VIA_SCO  = FALSE     # TRUE, FALSE
                                 # Support FM Radio being passed by BT SCO Link

OTG_DETECT_ID_PIN_WITH_EINT = FALSE    # TRUE, FALSE

VDOEDT_SUPPORT		 = FALSE		# TRUE or FALSE

SYNC_LCM_SUPPORT = FALSE         # TRUE or FALSE
                                 # TRUE if Sync mode LCM is applied and FALSE if Sync mode LCM is applied.

FEATURE_OVERLOAD = FALSE         # TRUE or FALSE
                                 # TRUE : turn on bypassing
                                 # FLASE : turn off bypassing

AAC_PLUS_PS_DECODE = FALSE       # TRUE, FALSE

OPTR_SPEC               = NONE   #   NONE

SYNCML_DM_SUPPORT       = FALSE  # TRUE or FALSE

VIRTUAL_PORTS_NUM       = 5      # default is 5, maximum is 9

SPATIAL_DITHERING       = TRUE   # TRUE or FALSE
                                 # support by MT6225, MT6228, MT6229 and MT6230

PICTBRIDGE_SUPPORT      = FALSE  # TRUE or FALSE, IMPS Feature Support

TDMB_SUPPORT            = NONE       # NONE, TELECHIP_TDMB, FRONTIER_TDMB

WBXML_SUPPORT   = TRUE		# TRUE or FALSE

ISO_PRIORITY_MODE_SUPPORT = FALSE   # FALSE, TRUE

KEYPAD_TYPE             = NORMAL_KEYPAD  # NORMAL_KEYPAD, REDUCED_KEYPAD

FLASHLIGHT_TYPE         = LED_FLASHLIGHT_SUPPORT            # NONE, LED_ONOFF_SUPPORT,LED_FLASHLIGHT_SUPPORT, XENON_FLASHLIGHT, XENON_FLASHLIGHT_ANTI_RED_EYE

UCM_SUPPORT             = TRUE          # TRUE or FALSE
                                         # to enable unified call management feature

TOUCH_PANEL_SHORTCUT_SUPPORT   = FALSE          # FALSE, TRUE
                                               # TRUE for  touch panel size need to be larger than LCD size
                                               # Support touch panel shortcut functionality

LANGLN_ENGINE                  =  NONE         # NONE, LANGLN_DIGIDEA
                                               # Add compile option for language learning application

GIS_SUPPORT                    =  NONE         # NONE, SUNAVI, MAPBAR
                                               # Add compile option for GIS application

SSL_SUPPORT             = NONE   # NONE, SSL_CIC_LIB, MTK_SSL_CIC

SYSGEN_ENABLE         = TRUE         # FALSE, TRUE

BACKGROUND_SMS_SUPPORT = FALSE		     # TRUE or FALSE

PURE_AUDIO_SUPPORT      = FALSE         # TRUE or FALSE
                                       # Support pure audio 3GP/MP4 file in audio player

FLC_VER               = FLC2       # FLC2 or FLC1

GPS_SUPPORT           = NONE       # NONE, MT3318

FAX_SUPPORT           = FALSE       # TRUE, FALSE

FONT_RESOURCE         = OFFICIAL   # DEMO, OFFICIAL


AUDIO_EQ_ENABLE       = FALSE      # TRUE/FALSE

AUDIO_COMPENSATION_ENABLE = FALSE  # TRUE/FALSE

PRODUCTION_RELEASE	= TRUE	  # Production release feature includs autoreset when system hang

DAYO_FULL_DIALSCREEN_FEATURE = TRUE # TRUE or FALSE


# below macro definition is for dual mode
DUAL_MODE_SUPPORT = GEMINI # MASTER, SLAVE, NONE,
                           # GEMINI: Single chip dual card solution


SENDKEY_MODE = SENDKEY2_SUPPORT# SINGLE_KEY_SELECT_MENU   SENDKEY2_SUPPORT   LSK_KEYSEND2_IN_ONE
                                      # SINGLE_KEY_SELECT_MENU only one sendkey will popup a menu to select dail card1 or card2
                                      # SENDKEY2_SUPPORT  two sendkeys the one is for card1 and the other is for card2
                                      # LSK_KEYSEND2_IN_ONE  only one sendkey and is for card1 dial ,card2 and lsk in one

MERCURY_SLAVE_BT_SUPPORT = TRUE # TRUE or FALSE

UART_EARPHONE_COMMONAGE = TRUE # TRUE or FALSE



GEMINI = TRUE

DUAL_MODE = TRUE

SINGLE_SIM_MMI_ONLY = FALSE # SINGLE_SIM_MMI_ONLY = TRUE/FALSE
                            # SINGLE_SIM_MMI_ONLY = TRUE : Use one single SIM MMI
                            # SINGLE_SIM_MMI_ONLY = FALSE : Use dual SIM MMI
# *************************************************************************
# Release Setting Section
# *************************************************************************
RELEASE_PACKAGE = REL_CR_GEMINI_OBJ_$(strip $(PROJECT))	# REL_CR_MMI_GPRS, REL_CR_MMI_GSM, REL_CR_PROTOCOL_GSM, REL_CR_PROTOCOL_GPRS, REL_CR_NEPTUNE_MMI_GSM,
					# REL_CR_NEPTUNE_PROTOCOL_GSM,
RELEASE_WAE		= SRC		# MTK/SRC, only works when TELECA_FEATURES works
RELEASE_WAP		= MTK		# MTK/SRC, only works when TELECA_FEATURES works

RELEASE_$(strip $(INPUT_METHOD)) = SRC	# MTK/SRC, only works when INPUT_METHOD is turning on
RELEASE_INPUT_METHODS_SRC =		# MMI_ZI, MMI_T9, MMI_ITAP,


##########################################################
#
##########################################################
COM_DEFS_FOR_UNIRISE25_GEMINI_MT6139E   = MT6139E_RF UNIRISE25_GEMINI_MT6139E
COM_DEFS_FOR_UNIRISE25_GEMINI_LCM       = UNIRISE25_GEMINI_LCM TFT_MAINLCD

# *************************************************************************
#
# *************************************************************************

ifndef MMI_BASE
	MMIDIR   = plutommi
else
	ifeq ($(strip $(MMI_BASE)),NEPTUNE_MMI)
		MMIDIR         =  lcmmi
	else
		MMIDIR         =  plutommi
	endif
endif

ifdef OPTR_SPEC
ifneq ($(strip $(OPTR_SPEC)),NONE)
  OPTR_PATH = operator\$(strip $(word 1,$(subst _, ,$(OPTR_SPEC)))\$(word 2,$(subst _, ,$(OPTR_SPEC))))\$(strip $(MMIDIR))
  -include $(OPTR_PATH)\operator.mak
endif
endif

# *************************************************************************
# Consistent Feature Options
# *************************************************************************

# *************************************************************************
# Components list
# *************************************************************************
ifeq ($(strip $(RTOS)),NUCLEUS)
COMPLIST       =  nucleus nucleus_int nucleus_ctrl_code nucleus_critical_data
endif

ifeq ($(strip $(RTOS)),THREADX)
COMPLIST       =  threadx threadx_ctrl_code threadx_ctrl_data
endif

ifeq ($(strip $(RTOS_DEBUG)),TRUE)
	ifeq ($(strip $(RTOS)),NUCLEUS)
		COMPLIST    += nucleus_debug
	else
		COMPLIST    += threadx_debug
	endif
endif


COMPLIST       += init config kal stacklib adaptation \
                  l1audio l1audio32 fm_drv custom drv   bmt \
                  ft fs fmt dp_engine  sst fdm dsp_ram applib vendorapp drv_sec

COMPLIST       += mtkdebug

#COMPLIST       += sim nvram nvram_sec cc l4_classb l4misc ciss sms ems mm_classb rr_classb ppp sndcp sm llc \
#media data

COMPLIST   += nvram nvram_sec ems ppp media

COMPLIST       += media_sec

# For PS team developers add component module here.
ifdef GEMINI
ifneq ($(strip $(GEMINI)),TRUE)
COMPLIST       += l1_classb cc data l4_classb llc rr_classb mm_classb sim sms sndcp l4misc
COMPLIST       += ciss sm interface_classb
else
# For SIM2 modules.
COMPLIST       += l1_classb_2 cc data l4_classb llc rr_classb mm_classb sim
COMPLIST       += sms sndcp interface_classb_2 l4misc ciss sm
COMPLIST       += l1_classb interface_classb
endif
else
COMPLIST       += l1_classb cc data l4_classb llc rr_classb mm_classb sim sms sndcp l4misc
COMPLIST       += ciss sm interface_classb
endif

ifeq ($(strip $(MCD_SUPPORT)),TRUE)
   COMPLIST          += mcd
else
   COMPLIST          += peer_classb
endif

ifdef EMAIL_SUPPORT
  ifneq ($(strip $(EMAIL_SUPPORT)),NONE)
      COMPLIST += email
  endif
endif

ifeq ($(strip $(MMI_VERSION)),PLUTO_MMI)
      COMPLIST  	+= plutommi gdi_arm mmiresource
else
 	ifeq ($(strip $(MMI_VERSION)),EMPTY_MMI)
  		COMPLIST		+= mmi
   else
  	   COMPLIST		+= plutommi gdi_arm mmiresource
	endif
endif

ifeq ($(strip $(TST_SUPPORT)),TRUE)
   COMPLIST    += tst
endif


ifneq ($(strip $(TCPIP_SUPPORT)),NONE)
   COMPLIST    += abm soc tcpip
endif

ifeq ($(strip $(IRDA_SUPPORT)),TRUE)
   COMPLIST    += irda ircomm obex
endif

ifeq ($(strip $(USB_SUPPORT)),TRUE)
	COMPLIST    += usb
endif

ifdef DRM_SUPPORT
  ifneq ($(strip $(DRM_SUPPORT)),NONE)
     COMPLIST    	+= drm
  endif
endif

ifdef CMUX_SUPPORT
  ifeq ($(strip $(CMUX_SUPPORT)),TRUE)
     COMPLIST          += cmux
  endif
endif

ifeq ($(strip $(XML_SUPPORT)),TRUE)
	COMPLIST    += xmlp
endif

ifneq ($(strip $(IMPS_SUPPORT)),FALSE)
       COMPLIST    += imps
endif

ifdef POC_SUPPORT
  ifneq ($(strip $(POC_SUPPORT)),NONE)
     COMPLIST    	+= poc
  endif
endif

ifdef SIP_SUPPORT
  ifneq ($(strip $(SIP_SUPPORT)),FALSE)
     COMPLIST    	+= sip
  endif
endif



ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK)
			   COMPLIST          += btadp btprofiles btstack
endif

ifdef DT_SUPPORT
  ifneq ($(strip $(DT_SUPPORT)),FALSE)
     COMPLIST    	+= dt
  endif
endif

ifdef XDM_SUPPORT
  ifneq ($(strip $(XDM_SUPPORT)),FALSE)
    COMPLIST         += xdm
  endif
endif

ifdef WIFI_SUPPORT
  ifeq ($(strip $(WIFI_SUPPORT)),MTK_WIFI)
     COMPLIST    	+= wndrv supc   dhcp
  else
       ifeq ($(strip $(WIFI_SUPPORT)),WIFI_LIB)
             COMPLIST    	+= wndrv supc  dhcp
       endif
  endif
endif

ifdef IPERF_SUPPORT
  ifneq ($(strip $(IPERF_SUPPORT)),NONE)
     COMPLIST    	+= iperf
  endif
endif

ifeq ($(strip $(DUAL_MODE_SUPPORT)),MASTER)
  	COMPLIST		+= mercury_master
endif

ifeq ($(strip $(DUAL_MODE_SUPPORT)),GEMINI)
  	COMPLIST		+= mercury_master
  	COMPLIST    += mercury_gemini
endif

ifdef TFTP_SUPPORT
  ifeq ($(strip $(TFTP_SUPPORT)),TRUE)
     COMPLIST    	+= tftp
  endif
endif

COMPLIST       += verno


# *************************************************************************
# Components Object Files
# *************************************************************************
COMPOBJS			=



# *************************************************************************
# Custom Release Component Configuration
# *************************************************************************

#

# *************************************************************************
# L1 TMD Files
# *************************************************************************
ifneq ($(strip $(GEMINI)),TRUE)
L1_TMD_FILES      =  l1\common\L1C_Trace.tmd \
                     l1\common\L1SC_Trace.tmd \
                     l1\common\l1i_cs_trace.tmd \
                     l1\common\L1D_Trace.tmd \
                     l1\common\l1i_ps_trace.tmd \
                     l1\common\L1C_csd_trace.tmd \
                     l1\common\l1c2_Trace.tmd \
                     l1\common\L1D2_Trace.tmd \
                     l1audio\l1audio_trace.tmd \
                     l1\common\l1i_amr_trace.tmd \
                     l1\common\l1t_amr_trace.tmd

L1_TMD_FILES   +=    l1\common\l1c_egprs_trace.tmd \
                     l1\common\l1i_egprs_trace.tmd \
                     l1\common\l1D_EDGE_trace.tmd
else
L1_TMD_FILES      =  SIM2\l1\common\L1C_Trace_2.tmd \
                     SIM2\l1\common\L1SC_Trace_2.tmd \
                     SIM2\l1\common\l1i_cs_trace_2.tmd \
                     SIM2\l1\common\L1D_Trace_2.tmd \
                     SIM2\l1\common\l1i_ps_trace_2.tmd \
                     SIM2\l1\common\L1C_csd_trace_2.tmd \
                     SIM2\l1\common\l1c2_Trace_2.tmd \
                     SIM2\l1\common\L1D2_Trace_2.tmd \
                     l1audio\l1audio_trace.tmd \
                     SIM2\l1\common\l1i_amr_trace_2.tmd \
                     SIM2\l1\common\l1t_amr_trace_2.tmd

L1_TMD_FILES   +=    SIM2\l1\common\l1c_egprs_trace_2.tmd \
                     SIM2\l1\common\l1i_egprs_trace_2.tmd \
                     SIM2\l1\common\l1D_EDGE_trace_2.tmd

L1_TMD_FILES      +=  l1\common\L1C_Trace.tmd \
                     l1\common\L1SC_Trace.tmd \
                     l1\common\l1i_cs_trace.tmd \
                     l1\common\L1D_Trace.tmd \
                     l1\common\l1i_ps_trace.tmd \
                     l1\common\L1C_csd_trace.tmd \
                     l1\common\l1c2_Trace.tmd \
                     l1\common\L1D2_Trace.tmd \
                     l1audio\l1audio_trace.tmd \
                     l1\common\l1i_amr_trace.tmd \
                     l1\common\l1t_amr_trace.tmd

L1_TMD_FILES   +=    l1\common\l1c_egprs_trace.tmd \
                     l1\common\l1i_egprs_trace.tmd \
                     l1\common\l1D_EDGE_trace.tmd
endif

# *************************************************************************
# Component trace definition header files
# *************************************************************************
ifneq ($(strip $(GEMINI)),TRUE)
COMP_TRACE_DEFS   =  tst\include\tst_trace.h \
                     l1\common\l1a_trace.h

COMP_TRACE_DEFS   += nvram\include\nvram_trc.h \
                     ps\sim\include\sim_trc.h \
                     ps\mm\common\include\mm_trc.h \
                     ps\l4\smsal\include\smsal_trc.h \
                     ps\l4\phb\include\phb_trc.h \
                     ps\l4\smu\include\smu_trc.h \
                     ps\cc-ss\ss\include\ciss_trc.h \
                     ps\cc-ss\cc\include\cc_trc.h \
                     ps\l4\csm\csm_trc.h \
                     ps\l4\include\l4_trc.h \
                     ps\sms\include\sms_trc.h \
                     ps\l4\uem\include\uem_trc.h \
                     ps\sndcp\include\snd_trc.h \
                     ps\sm\include\sm_trc.h \
                     ps\llc\include\llc_trc.h \
                     ps\rr\include\rr_trc.h \
                     ps\rr\lapdm\include\lapdm_trc.h \
                     ps\l4\rac\include\rac_trc.h \
                     ps\l4\tcm\include\tcm_trc.h \
                     ps\ppp\include\ppp_trc.h \
                     ps\rr\rrm\include\rrm_trc.h \
                     ps\rr\rlc\include\rlc_trc.h \
                     ps\rr\mac\include\mac_trc.h \
                     media\common\include\med_trc.h \
                     ps\data\l2r\include\l2r_trc.h \
                     ps\data\tdt\include\tdt_trc.h \
                     ps\data\rlp\include\rlp_trc.h \
                     ps\data\t30\include\t30_trc.h \
                     ps\data\fa\include\fa_trc.h \
                     ps\abm\include\abm_trc.h \
                     ps\soc\include\soc_trc.h \
                     ps\tcpip\include\tcpip_trc.h \
                     bmt\bmt_trc.h
else
COMP_TRACE_DEFS   =  tst\include\tst_trace.h \
                     SIM2\l1\common\l1a_trace.h

COMP_TRACE_DEFS   += nvram\include\nvram_trc.h \
                     ps\sim\include\sim_trc.h \
                     ps\mm\common\include\mm_trc.h \
                     ps\l4\smsal\include\smsal_trc.h \
                     ps\l4\phb\include\phb_trc.h \
                     ps\l4\smu\include\smu_trc.h \
                     ps\cc-ss\ss\include\ciss_trc.h \
                     ps\cc-ss\cc\include\cc_trc.h \
                     ps\l4\csm\csm_trc.h \
                     ps\l4\include\l4_trc.h \
                     ps\sms\include\sms_trc.h \
                     ps\sndcp\include\snd_trc.h \
                     ps\sm\include\sm_trc.h \
                     ps\llc\include\llc_trc.h \
                     ps\rr\include\rr_trc.h \
                     ps\rr\lapdm\include\lapdm_trc.h \
                     ps\l4\rac\include\rac_trc.h \
                     ps\l4\tcm\include\tcm_trc.h \
                     ps\ppp\include\ppp_trc.h \
                     ps\rr\rrm\include\rrm_trc.h \
                     ps\rr\rlc\include\rlc_trc.h \
                     ps\rr\mac\include\mac_trc.h \
                     media\common\include\med_trc.h \
                     ps\data\l2r\include\l2r_trc.h \
                     ps\data\tdt\include\tdt_trc.h \
                     ps\data\rlp\include\rlp_trc.h \
                     ps\data\t30\include\t30_trc.h \
                     ps\data\fa\include\fa_trc.h \
                     ps\abm\include\abm_trc.h \
                     ps\soc\include\soc_trc.h \
                     ps\tcpip\include\tcpip_trc.h \
                     bmt\bmt_trc.h

COMP_TRACE_DEFS   +=  l1\common\l1a_trace.h

COMP_TRACE_DEFS   += ps\sim\include\sim_trc.h \
                     ps\mm\common\include\mm_trc.h \
                     ps\l4\smsal\include\smsal_trc.h \
                     ps\l4\phb\include\phb_trc.h \
                     ps\l4\smu\include\smu_trc.h \
                     ps\cc-ss\ss\include\ciss_trc.h \
                     ps\cc-ss\cc\include\cc_trc.h \
                     ps\l4\csm\csm_trc.h \
                     ps\l4\include\l4_trc.h \
                     ps\sms\include\sms_trc.h \
                     ps\l4\uem\include\uem_trc.h \
                     ps\sndcp\include\snd_trc.h \
                     ps\sm\include\sm_trc.h \
                     ps\llc\include\llc_trc.h \
                     ps\rr\include\rr_trc.h \
                     ps\rr\lapdm\include\lapdm_trc.h \
                     ps\l4\rac\include\rac_trc.h \
                     ps\l4\tcm\include\tcm_trc.h \
                     ps\rr\rrm\include\rrm_trc.h \
                     ps\rr\rlc\include\rlc_trc.h \
                     ps\rr\mac\include\mac_trc.h \
                     ps\data\l2r\include\l2r_trc.h \
                     ps\data\tdt\include\tdt_trc.h \
                     ps\data\rlp\include\rlp_trc.h \
                     ps\data\t30\include\t30_trc.h \
                     ps\data\fa\include\fa_trc.h
endif

ifeq ($(strip $(IRDA_SUPPORT)),TRUE)
   COMP_TRACE_DEFS   += ps\ircomm\include\ircomm_trc.h \
                        ps\obex\include\obex_trc.h \
                        irda\inc\irda_trace.h
endif


ifeq ($(strip $(USB_SUPPORT)),TRUE)
        COMP_TRACE_DEFS	+= usb\include\usb_trc.h
endif


COMP_TRACE_DEFS   += sst\include\ex_trc.h
COMP_TRACE_DEFS += plutommi\mmi\inc\MMI_trc.h

COMP_TRACE_DEFS += sst\include\sst_common_trc.h \
                   sst\include\sst_task_trc.h \
                   sst\include\sst_mem_trc.h \
                   sst\include\sst_buff_trc.h \
                   sst\include\sst_init_trc.h \
                   sst\include\sst_itc_trc.h \
                   sst\include\sst_misc_trc.h \
                   sst\include\sst_timer_trc.h

ifneq ($(strip $(IMPS_SUPPORT)),FALSE)
   COMP_TRACE_DEFS	+= ps\imps\include\imps_trc.h
endif



# *************************************************************************
# Common include path
# *************************************************************************
CUSTOM_COMMINC    =  init\include stacklib\include adaptation\include config\include \
                     sst\include inc fdm\include \
                     interface\hwdrv interface\os interface\l1audio \
                     tst\database_classb\pstrace_db tst\include \
                     l1\common dummyps\include vendor\mercury_master\inc
ifdef GEMINI
ifneq ($(strip $(GEMINI)),TRUE)
CUSTOM_COMMINC    += interface\l1interface \
                     ps\config\include \
                     ps\interfaces\include \
                     ps\interfaces\enum \
                     ps\interfaces\local_inc \
                     ps\tools\asn1lib\include \
                     interface\ps \
                     interface\mmi \
                     ps\l4\include \
                     ps\l4\l4c\include\mmi \
                     ps\l4\l4c\include\common \
                     ps\l4\l4c\include\proc \
                     ps\l4\csm\cc\include \
                     ps\l4\uem\include \
                     ps\l4\phb\include \
                     ps\rr\include \
                     ps\rr\rrm\include \
                     ps\rr\rmc\include \
                     ps\rr\lapdm\include \
                     ps\rr\mpal\include \
                     ps\rr\rlc\include \
                     ps\rr\mac\include \
                     adaptation\include \
                     ps\l4\csm\cc\include \
                     ps\cc-ss\cc\include \
                     ps\l4\csm \
                     ps\sms\include \
                     ps\l4\smsal\include \
                     ps\sim\include \
                     ps\mm\cmm\include \
                     ps\mm\common\include \
                     ps\mm\pmm\include \
                     ps\sm\include \
                     ps\llc\include \
                     ps\l4\tcm\include \
                     ps\ppp\include \
                     media\common\include \
                     media\audio\include \
                     media\video\include \
                     media\camera\include \
                     media\image\include \
                     ps\data\include \
                     ps\data\l2r\include \
                     ps\data\rlp\include \
                     ps\data\tdt\include \
                     ps\data\t30\include \
                     ps\data\fa\include \
                     l1\l1d \
                     fs\fat\include \
                     fs\drv\include \
                     ps\mcd\include \
                     ps\gen\mcd \
                     ps\sndcp\include \
                     ps\abm\include \
                     ps\soc\include \
                     mmi\include \
                     ps\rr\rmp\include \
                     ps\ircomm\include \
                     fmt\include \
                     kal\Efs\include \
                     interface\media
else
CUSTOM_COMMINC    += SIM2\l1\common \
                     SIM2\interface\l1interface \
                     interface\l1interface \
                     ps\config\include \
                     ps\interfaces\include \
                     ps\interfaces\enum \
                     ps\interfaces\local_inc \
                     ps\tools\asn1lib\include \
                     interface\ps \
                     interface\mmi \
                     ps\l4\include \
                     ps\l4\include \
                     ps\l4\l4c\include\mmi \
                     ps\l4\l4c\include\common \
                     ps\l4\l4c\include\proc \
                     ps\l4\csm\cc\include \
                     ps\l4\uem\include \
                     ps\l4\phb\include \
                     ps\rr\include \
                     ps\rr\rrm\include \
                     ps\rr\rmc\include \
                     ps\rr\lapdm\include \
                     ps\rr\mpal\include \
                     ps\rr\rlc\include \
                     ps\rr\mac\include \
                     adaptation\include \
                     ps\l4\csm\cc\include \
                     ps\cc-ss\cc\include \
                     ps\l4\csm \
                     ps\sms\include \
                     ps\l4\smsal\include \
                     ps\sim\include \
                     ps\mm\cmm\include \
                     ps\mm\common\include \
                     ps\mm\pmm\include \
                     ps\sm\include \
                     ps\sm\include \
                     ps\llc\include \
                     ps\l4\tcm\include \
                     ps\ppp\include \
                     media\common\include \
                     media\audio\include \
                     media\video\include \
                     media\camera\include \
                     media\image\include \
                     ps\data\include \
                     ps\data\l2r\include \
                     ps\data\rlp\include \
                     ps\data\tdt\include \
                     ps\data\t30\include \
                     ps\data\fa\include \
                     l1\l1d \
                     fs\fat\include \
                     fs\drv\include \
                     ps\mcd\include \
                     ps\gen\mcd \
                     ps\sndcp\include \
                     ps\abm\include \
                     ps\soc\include \
                     mmi\include \
                     ps\rr\rmp\include \
                     ps\ircomm\include \
                     fmt\include \
                     kal\Efs\include \
                     interface\media

CUSTOM_COMMINC    += interface\mmi \
                     ps\l4\include \
                     ps\l4\l4c\include\mmi \
                     ps\l4\l4c\include\common \
                     ps\l4\l4c\include\proc \
                     ps\l4\csm\cc\include \
                     ps\l4\uem\include \
                     ps\l4\phb\include \
                     ps\rr\include \
                     ps\rr\rrm\include \
                     ps\rr\rmc\include \
                     ps\rr\lapdm\include \
                     ps\rr\mpal\include \
                     ps\rr\rlc\include \
                     ps\rr\mac\include \
                     ps\l4\csm\cc\include \
                     ps\cc-ss\cc\include \
                     ps\l4\csm \
                     ps\sms\include \
                     ps\l4\smsal\include \
                     ps\sim\include \
                     ps\mm\cmm\include \
                     ps\mm\common\include \
                     ps\mm\pmm\include \
                     ps\llc\include \
                     ps\l4\tcm\include \
                     ps\data\include \
                     ps\data\l2r\include \
                     ps\data\rlp\include \
                     ps\data\tdt\include \
                     ps\data\t30\include \
                     ps\data\fa\include \
                     l1\l1d \
                     ps\sndcp\include \
                     ps\rr\rmp\include
endif
endif

CUSTOM_COMMINC    +=	custom\l1_rf\$(RF_MODULE)

CUSTOM_COMMINC    +=	custom\drv\LCD\$(LCD_MODULE) \
            			custom\drv\misc_drv\$(BOARD_VER) \
             			custom\audio\$(BOARD_VER) \
             			custom\app\$(BOARD_VER) \
                     custom\ps\$(BOARD_VER) \
                     custom\system\$(BOARD_VER) custom\common

#hongzhe.liu add start
ifdef  ANALOG_TV_CHIP
  ifneq ($(strip $(ANALOG_TV_CHIP)),NONE)
    CUSTOM_COMMINC    +=	custom\drv\analog_tv\$(strip $(ANALOG_TV_CHIP))
  endif
endif
#hongzhe.liu add end

ifneq ($(strip $(EXT_CAM_MODULE)),NONE)
    CUSTOM_COMMINC    +=	custom\drv\cam_module\$(strip $(EXT_CAM_MODULE))
    CUSTOM_COMMINC    +=	custom\drv\cam_module\$(strip $(BOARD_VER))
endif


ifneq ($(strip $(MOTION_SENSOR_SUPPORT)),NONE)
    CUSTOM_COMMINC    +=	custom\drv\motion_sensor\$(strip $(MOTION_SENSOR_SUPPORT))
endif

ifneq ($(strip $(J2ME_SUPPORT)),NONE)
    CUSTOM_COMMINC    +=	custom\j2me\$(strip $(BOARD_VER))
endif

ifeq ($(strip $(MELODY_CHIP)),ROHM_8788)
	CUSTOM_COMMINC   += ROHM\rohm8788
else
	ifeq ($(strip $(MELODY_CHIP)),YAMAHA_MA3)
	   CUSTOM_COMMINC   += yamaha\ma3
	endif
endif



CUSTOM_COMMINC  +=	ps\email\inc \
                     ps\email\imap\inc \
                     ps\email\pop3\inc \
                     ps\email\smtp\inc

ifneq ($(strip $(EXT_CAM_MODULE)),NONE)
	CUSTOM_COMMINC   +=	custom\drv\cam_module\$(EXT_CAM_MODULE)
endif

ifeq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
   CUSTOM_COMMINC   +=  lcmmi\mmi\Inc
else
   CUSTOM_COMMINC   +=  plutommi\mmi\Inc
endif

ifneq ($(strip $(IMPS_SUPPORT)),FALSE)
       CUSTOM_COMMINC  +=	ps\imps\include
endif

ifneq ($(strip $(POC_SUPPORT)),NONE)
    CUSTOM_COMMINC   +=  ps\poc\include
endif

ifneq ($(strip $(SIP_SUPPORT)),FALSE)
    CUSTOM_COMMINC  +=  ps\sip\include \
                  ps\sip\sip_lib\sip_msg\include \
                  ps\sip\sip_lib\sip_ua\include \
                  ps\sip\sip_lib\sdp_msg\include
endif

# *************************************************************************
# Common preprocessor definitions
# *************************************************************************
CUSTOM_OPTION    =   __CS_SERVICE__ __PS_SERVICE__ \
                     __MOD_L4C__ __MOD_CSM__ __MOD_RAC__ __MOD_SMU__ __MOD_SMSAL__ \
                     __MOD_PHB__ __MOD_UEM__ __MOD_CC__ __MOD_CISS__ __MOD_SMS__ \
                     __MOD_MM__ __MOD_NVRAM__ __MOD_SIM__ __MOD_TCM__ \
                     __SAT__ __EM_MODE__ __CPHS__ __MULTI_BOOT__ __FS_ON__ \
                     $(MELODY_VER) __18V_30V_ME__  __PHB_COMPARE_NUMBER_9_DIGIT__ \
                     __FLIGHT_MODE_SUPPORT__ \
                     __CHARGER_USB_DETECT_WIHT_ONE_EINT__  __MSDC_NOT_SUPPORT_HOT_PLUG__

#__DRV_DUAL_SIM_INVERSE__

ifdef GEMINI
  ifeq ($(strip $(GEMINI)),TRUE)
    CUSTOM_OPTION += __GEMINI__ DRV_MULTIPLE_SIM
  endif
endif

ifdef SINGLE_SIM_MMI_ONLY
  ifeq ($(strip $(SINGLE_SIM_MMI_ONLY)),TRUE)
    CUSTOM_OPTION += __SINGLE_SIM_MMI_ONLY__
  endif
endif

CUSTOM_OPTION     += DEBUG_KAL __SYS_INTERN_RAM__ MTK_NEW_API

ifeq ($(strip $(PRODUCTION_RELEASE)),TRUE)
   CUSTOM_OPTION  += __PRODUCTION_RELEASE__ DEBUG_ITC DEBUG_BUF DEBUG_BUF2
else
   CUSTOM_OPTION  += DEBUG_ITC DEBUG_BUF DEBUG_BUF2
endif


ifeq ($(strip $(TST_SUPPORT)),TRUE)
   CUSTOM_OPTION    += __TST_MODULE__
else
	CUSTOM_OPTION    += DRV_DEBUG
endif


ifeq ($(strip $(MCD_SUPPORT)),TRUE)
   CUSTOM_OPTION    += __MCD__
endif

#ifeq ($(strip $(CSD_SUPPORT)),TRUE)
#   CUSTOM_OPTION    += CSD_SUPPORT __CSD_NT__ __CSD_T__ __CSD_FAX__
#endif

#ifeq ($(strip $(CSD_SUPPORT)),TRUE)
#   CUSTOM_OPTION    += __CSD_FAX__
#endif



ifeq ($(strip $(MMI_VERSION)),PLUTO_MMI)
  	CUSTOM_OPTION += __MMI_FMI__ __MOD_L4A__ PLUTO_MMI __VENUS_MMI__
else
	ifeq ($(strip $(MMI_VERSION)),EMPTY_MMI)
		CUSTOM_OPTION += __MMI_FMI__ __MOD_L4A__ EMPTY_MMI
	else
		ifeq ($(strip $(MMI_VERSION)),BW_MMI)
			CUSTOM_OPTION += __MMI_FMI__ __MOD_L4A__ PLUTO_MMI __BW_MMI__
		endif
	endif
endif

ifeq ($(strip $(SPLIT_SYSTEM)),TRUE)
   CUSTOM_OPTION    += UT_ON_TARGET SPLIT_SYS
endif

ifeq ($(strip $(EMAIL_SUPPORT)),TRUE)
   CUSTOM_OPTION    += __EMAIL__
endif


ifeq ($(strip $(IRDA_SUPPORT)),TRUE)
   CUSTOM_OPTION    += __IRDA_SUPPORT__
endif


ifneq ($(strip $(EXT_CAM_MODULE)),NONE)
   CUSTOM_OPTION    += CAMERA_MODULE
endif

ifeq ($(strip $(JPG_DECODE)),TRUE)
   CUSTOM_OPTION    += JPG_DECODE
endif

ifeq ($(strip $(DAF_DECODE)),TRUE)
   CUSTOM_OPTION    += DAF_DECODE
   CUSTOM_OPTION    += MUSICAM_DECODE
endif

ifneq ($(strip $(PHB_SIM_ENTRY)),)
  CUSTOM_OPTION += __PHB_SIM_$(strip $(PHB_SIM_ENTRY))__
endif

ifneq ($(strip $(PHB_PHONE_ENTRY)),)
  CUSTOM_OPTION += __PHB_PHONE_$(strip $(PHB_PHONE_ENTRY))__
endif

ifeq ($(strip $(BOARD_VER)),GEMINI25_BB)
  CUSTOM_OPTION += __MSDC_TFLASH_DAT3_1BIT_HOT_PLUG__
endif

ifeq ($(strip $(DAYO_FULL_DIALSCREEN_FEATURE)),TRUE)
  CUSTOM_OPTION  += __DAYO_FULL_DIALSCREEN_FEATURE__
endif

ifeq ($(strip $(DUAL_MODE_SUPPORT)),MASTER)
  	CUSTOM_OPTION += __MERCURY_MASTER__
  	ifeq ($(strip $(SENDKEY_MODE)),SENDKEY2_SUPPORT)
		CUSTOM_OPTION  += __SENDKEY2_SUPPORT__
		else
		     ifeq ($(strip $(SENDKEY_MODE)),LSK_KEYSEND2_IN_ONE)
		     CUSTOM_OPTION  += __LSK_KEYSEND2_IN_ONE__
		     endif
		endif
		ifeq ($(strip $(UART_EARPHONE_COMMONAGE)),TRUE)
		CUSTOM_OPTION  += __UART_EARPHONE_COMMONAGE__
		endif
  	ifeq ($(strip $(MERCURY_SLAVE_BT_SUPPORT)),TRUE)
  		ifneq ($(strip $(BLUETOOTH_SUPPORT)),NONE)
			CUSTOM_OPTION  += __MERCURY_SLAVE_BT_MASTER_SIDE__
		endif
		endif
		ifeq ($(strip $(DYNAMIC_CREATE_DUALMODE_TASK)),TRUE)
		CUSTOM_OPTION  += __DC_DM_TASK__
		endif
		ifeq ($(strip $(DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION)),TRUE)
		CUSTOM_OPTION  += __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__
		endif
		ifeq ($(strip $(DM_PWR_ON_QUERY_SUPPORT)),TRUE)
		CUSTOM_OPTION  += __DM_PWR_ON_QUERY_SUPPORT__
		endif
		ifeq ($(strip $(QUERY_PSN_SUPPORT)),TRUE)
		CUSTOM_OPTION  += __QUERY_PSN_SUPPORT__
		endif
endif

ifeq ($(strip $(DUAL_MODE_SUPPORT)),GEMINI)
  	CUSTOM_OPTION += __MERCURY_MASTER__
  	CUSTOM_OPTION += __MERCURY_GEMINI__
  	ifeq ($(strip $(SENDKEY_MODE)),SENDKEY2_SUPPORT)
		CUSTOM_OPTION  += __SENDKEY2_SUPPORT__
	else
		ifeq ($(strip $(SENDKEY_MODE)),LSK_KEYSEND2_IN_ONE)
		     CUSTOM_OPTION  += __LSK_KEYSEND2_IN_ONE__
		endif
	endif
  	ifneq ($(strip $(BLUETOOTH_SUPPORT)),NONE)
			CUSTOM_OPTION  += __MERCURY_SLAVE_BT_MASTER_SIDE__
	endif
	ifeq ($(strip $(DYNAMIC_CREATE_DUALMODE_TASK)),TRUE)
		CUSTOM_OPTION  += __DC_DM_TASK__
	endif
	ifeq ($(strip $(DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION)),TRUE)
		CUSTOM_OPTION  += __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__
	endif
endif

#vibrator tone 081204
ifeq ($(strip $(VIBRATOR_TONE_SUPPORT)),TRUE)
      CUSTOM_OPTION+=__VIBRATOR_TONE_SUPPORT__
endif

CUSTOM_OPTION    += __EMS_NOT_COMPRESS__

# *************************************************************************
# Custom Release Component Configuration
# *************************************************************************
include make\$(strip $(RELEASE_PACKAGE)).mak

CUS_REL_MTK_COMP += drv_sec

# *************************************************************************
# Component trace definition header files for custom release only
# *************************************************************************
# Following trace headers are already existed in custom release
# You can add new traces with kal_trace() in the following trace headers
EXISTED_CUS_REL_TRACE_DEFS =
EXISTED_CUS_REL_TRACE_DEFS += plutommi\mmi\inc\mmi_inet_app_trc.h
EXISTED_CUS_REL_TRACE_DEFS += plutommi\mmi\inc\mmi_trc.h
EXISTED_CUS_REL_TRACE_DEFS += plutommi\mmi\inc\mmi_media_app_trc.h
EXISTED_CUS_REL_TRACE_DEFS += plutommi\mmi\inc\mmi_conn_app_trc.h
EXISTED_CUS_REL_TRACE_DEFS += plutommi\mmi\inc\mmi_common_app_trc.h
EXISTED_CUS_REL_TRACE_DEFS += plutommi\mmi\inc\mmi_fw_trc.h

# Customer can add new trace headers here for new modules
NEW_CUS_REL_TRACE_DEFS =
