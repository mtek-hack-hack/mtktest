/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 * FactoryModeSrc.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is Factory Mode
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_FACTORY_MODE__

#if !defined(__MTK_TARGET__)
#include <windows.h>
#endif 
#include "MMI_include.h"

/*****************************************************************************
* Include Files                                                                
*****************************************************************************/
#include "ProtocolEvents.h"
#ifdef __MMI_SUBLCD__
#endif 
#include "HardwareEvents.h"
#include "Thrdosinterface.h"
#include "OSThreadInterfaceGprot.h"
#include "PixcomFontEngine.h"
#include "MainMenuDef.h"
#include "CustomCfg.h"
#include "audioInc.h"
#include "IdleAppDef.h"
#include "FactoryModeDef.h"
#include "FactoryModeProt.h"
#include "EngineerModeProt.h"
#include "AlarmDef.h"
#include "gpioInc.h"
#include "mdi_datatype.h"
#include "mdi_include.h"
#include "mdi_audio.h"
#include "CommonScreens.h"
#include "SettingDefs.h"        /* ST_NOTIFYDURATION define */
#include "fmt_struct.h"
#include "ProfileGprots.h"
#if defined(__MMI_TOUCH_SCREEN__)
#endif 

#ifdef __MMI_SUBLCD__
#endif 

#if defined(__MSDC_MS__) || defined(__MSDC_SD_MMC__) || defined(__MSDC_MSPRO__)
#include "..\..\..\..\drv\include\Msdc_def.h"
#endif 

#if defined(__MMI_CAMERA__) && defined(__MTK_TARGET__) && !defined(YUV_SENSOR_SUPPORT)
#include "lcd_if.h"
#include "lcd_sw_rnd.h" /* LCD layer enable flag */
#include "mdi_datatype.h"
#include "med_api.h"    /* media task camera module */
#include "MMI_features_camera.h"
#include "resource_camera_skins.h"
#include "mdi_camera.h"
#include "CameraApp.h"
#include "Camera_para.h"
#include "NVRAM_user_defs.h"

#if defined(ISP_SUPPORT)
#include "image_sensor.h"
#endif 
#endif /* defined(__MMI_CAMERA__) && defined(__MTK_TARGET__) */ 

#include "init.h"
#include "device.h"
#include "custom_em.h"
#include "custom_equipment.h"
#include "custom_hw_default.h"
#include "nvram_data_items.h"
#include "nvram_user_defs.h"
#include "lcd_sw.h"
#include "lcd_sw_inc.h"
#include "custom_jump_tbl.h"
#include "resource_verno.h"
#include "uart_sw.h"    /* UART_PORT type */

#ifdef __MTK_TARGET__
#include "l1audio.h"
#else 
#define L1SP_Tones kal_uint16
#endif 

#include "datetimetype.h"
#include "app_datetime.h"

#ifdef __MMI_FM_RADIO__
#include "aud_defs.h"
#endif

#include "adc_channel.h"


/* hongzhe.liu add start */

#if defined(ANALOG_TV_SUPPORT) 
#include"mmi_features_video.h"
#include "resource_video_skins.h" 
#include "VdoRecResDef.h"
#include "VdoRecApp.h"
#include "VdoRecGProt.h"
#include "VdoPlyGProt.h"   
#include "VdoPlyResDef.h"
#include "mdi_video.h" 
#include "VdoPlyApp.h"
#include "..\..\plutommi\mmi\AnalogTVApp\AnalogTVAppInc\AnalogTvInc.h"
#include "Med_struct.h"
#include "wgui_categories_inputsenum.h"
#include "MessagesresourceData.H"
#include "HealthMenstural.h"			
#include "Gui_data_types.h"
#endif  

/* hongzhe.liu add end */


/***************************************************************************** 
* Define
*****************************************************************************/

/***************************/
/* Camera                  */
/***************************/
#define FM_CAMERA_OSD_BUFFER_SIZE   (((GDI_LCD_WIDTH*GDI_LCD_HEIGHT*GDI_MAINLCD_BIT_PER_PIXEL)>>3))     /* single buffer */

/* camera support for Backend module or ISP */
#if defined(__MMI_CAMERA__) && defined(__MTK_TARGET__) && !defined(YUV_SENSOR_SUPPORT)
#if defined(ISP_SUPPORT)
      /* using own ISP, support tunning */
#define __FM_CAMERA_TUNNING__
#define __FM_CAMERA_PREVIEW__
#else /* defined(ISP_SUPPORT) */ 
      /* using backend, only support preview */
#define __FM_CAMERA_PREVIEW__
#endif /* defined(ISP_SUPPORT) */ 
#endif /* defined(__MMI_CAMERA__) && defined(__MTK_TARGET__) */ /* __MMI_CAMERA__ && ISP_SUPPORT */

#if (UI_DEVICE_HEIGHT == 128)
#define CAMTUNE_PREVIEW_HEIGHT_COUNT 3
#elif (UI_DEVICE_HEIGHT == 160)
#define CAMTUNE_PREVIEW_HEIGHT_COUNT 3
#elif (UI_DEVICE_HEIGHT == 220)
#define CAMTUNE_PREVIEW_HEIGHT_COUNT 3
#else 
#define CAMTUNE_PREVIEW_HEIGHT_COUNT 3
#endif 

#define CAMTUNE_GROUP_NAME_LEN         (20)     /* group name length */
#define CAMTUNE_GROUP_NAME_BUF_LEN     ((CAMTUNE_GROUP_NAME_LEN-1)*ENCODING_LENGTH)

#define CAMTUNE_ITEM_PER_GROUP         (15)
#define CAMTUNE_ITEM_NAME_LEN          (20)
#define CAMTUNE_ITEM_NAME_BUF_LEN      ((CAMTUNE_ITEM_NAME_LEN-1)*ENCODING_LENGTH)
#define CAMTUNE_ITEM_DIG_LEN           (15)
#define CAMTUNE_ITEM_DIG_BUF_LEN       ((CAMTUNE_ITEM_DIG_LEN-1)*ENCODING_LENGTH)

/***************************/
/* KeyPad                  */
/***************************/
#define PHYSICAL_KEYs (sizeof(IdleScreenDigits)/sizeof(IdleScreenDigits[0]))
#define KEYNUMs (sizeof(keypad_value)/sizeof(keypad_value[0]))

#define LINE_NUM     8
#define COLUMN_NUM   4

#define KEY_NA       2
#define KEY_HIDE     1
#define KEY_SHOW     0
#define BLANK        "    "

#define KEY_NONE_NAME         BLANK
#define KEY_NONE_VALUE        0xFF
#define KEY_LSK_NAME          "LSK "
#define KEY_LSK_VALUE         KEY_LSK
#define KEY_RSK_NAME          "RSK "
#define KEY_RSK_VALUE         KEY_RSK
#define KEY_UP_ARROW_NAME     " Up "
#define KEY_UP_ARROW_VALUE    KEY_UP_ARROW
#define KEY_DOWN_ARROW_NAME   " Dn "
#define KEY_DOWN_ARROW_VALUE  KEY_DOWN_ARROW
#define KEY_LEFT_ARROW_NAME   " LF "
#define KEY_LEFT_ARROW_VALUE  KEY_LEFT_ARROW
#define KEY_RIGHT_ARROW_NAME  " RT "
#define KEY_RIGHT_ARROW_VALUE KEY_RIGHT_ARROW
#define KEY_SEND_NAME         "Snd "
#define KEY_SEND_VALUE        KEY_SEND
#define KEY_END_NAME          "End "
#define KEY_END_VALUE         KEY_END

#ifdef __MMI_NO_SIDEKEY__
#define KEY_VOL_UP_NAME    KEY_NONE_NAME
#define KEY_VOL_UP_VALUE   KEY_NONE_VALUE
#define KEY_VOL_DOWN_NAME  KEY_NONE_NAME
#define KEY_VOL_DOWN_VALUE KEY_NONE_VALUE
#else /* __MMI_NO_SIDEKEY__ */ 
#define KEY_VOL_UP_NAME    "Vup "
#define KEY_VOL_UP_VALUE   KEY_VOL_UP
#define KEY_VOL_DOWN_NAME  "Vdn "
#define KEY_VOL_DOWN_VALUE KEY_VOL_DOWN
#endif /* __MMI_NO_SIDEKEY__ */ 

#if defined(__MMI_IP_KEY__) || defined(__MMI_FACTORY_MODE_I_KEY__)
#define KEY_IP_NAME     " I "
#define KEY_IP_VALUE    KEY_ENTER
#else /* defined(__MMI_IP_KEY__) || defined(__MMI_FACTORY_MODE_I_KEY__) */ 
#define KEY_IP_NAME     KEY_NONE_NAME
#define KEY_IP_VALUE    KEY_NONE_VALUE
#endif /* defined(__MMI_IP_KEY__) || defined(__MMI_FACTORY_MODE_I_KEY__) */ 

#if defined(__MMI_CAMERA__)
#define KEY_CAMERA_NAME    "CAM "
#define KEY_CAMERA_VALUE   KEY_CAMERA
#else /* defined(__MMI_CAMERA__) */ 
#define KEY_CAMERA_NAME    KEY_NONE_NAME
#define KEY_CAMERA_VALUE   KEY_NONE_VALUE
#endif /* defined(__MMI_CAMERA__) */ 

#if defined(__MMI_FACTORY_MODE_NAV_KEY__)
#define KEY_OK_NAME     "OK "
#define KEY_OK_VALUE    KEY_LSK
#else /* defined(__MMI_FACTORY_MODE_NAV_KEY__) */ 
#define KEY_OK_NAME     KEY_NONE_NAME
#define KEY_OK_VALUE    KEY_NONE_VALUE
#endif /* defined(__MMI_FACTORY_MODE_NAV_KEY__) */ 

#if defined(__MMI_WITH_C_KEY__)
#define KEY_CLR_NAME    "CLR"
#define KEY_CLR_VALUE   KEY_CLEAR
#else /* defined(__MMI_WITH_C_KEY__) */ 
#define KEY_CLR_NAME    KEY_NONE_NAME
#define KEY_CLR_VALUE   KEY_NONE_VALUE
#endif /* defined(__MMI_WITH_C_KEY__) */ 


/***************************************************************************** 
* Typedef 
*****************************************************************************/
typedef enum
{
    FM_CAMERA_SENSOR,
    FM_CAMERA_ISP
} fm_camtune_cat_enum;

typedef struct
{
    S32 value;
    S32 min_value;
    S32 max_value;
    BOOL is_read_only;
    BOOL is_true_false;
    BOOL is_need_restart;
    S8 name_buf[CAMTUNE_ITEM_NAME_BUF_LEN];
    S8 digit_buf[CAMTUNE_ITEM_DIG_BUF_LEN];
} fm_camtune_item_struct;

typedef struct
{
    S32 item_count;
    S32 item_inx;
    S8 name_buf[CAMTUNE_GROUP_NAME_BUF_LEN];
    fm_camtune_item_struct items[CAMTUNE_ITEM_PER_GROUP];
} fm_camtune_group_struct;

typedef struct
{
    S32 group_count;
    S32 group_idx;

    S32 category_idx;

    S32 hilight_idx;

    gdi_handle preview_layer_handle;
    PU8 preview_layer_buf_ptr;

    BOOL is_previewing;
    BOOL is_fullscreen;

    UI_string_type true_false_str[2];
    fm_camtune_group_struct group_data;
#if defined(__MMI_CAMERA__) && defined(__MTK_TARGET__) && !defined(YUV_SENSOR_SUPPORT)
    mdi_camera_setting_struct camera_setting_data;
#endif 
} fm_camtune_cntx_struct;

typedef enum
{

    MAINLCD_BL = 0,

#ifdef __MMI_SUBLCD__
    SUBLCD_BL,
#endif 

    KEYPAD_LED,

#ifndef __MMI_HIDE_STATUS_LED_R__
    STATUSLED_R,
#endif 

#ifndef __MMI_HIDE_STATUS_LED_G__
    STATUSLED_G,
#endif 

#ifndef __MMI_HIDE_STATUS_LED_B__
    STATUSLED_B,
#endif 

    MAX_FM_LED_MENU_NUM
} FM_LED_MENU_ENUM;

/****************************************************************************
* Global Variable                                                           
*****************************************************************************/
extern U8 subMenuData[MAX_SUB_MENUS][MAX_SUB_MENU_SIZE];
extern PU8 subMenuDataPtrs[MAX_SUB_MENUS];
extern bitmap *current_LCD_device_bitmap;
extern bitmap main_LCD_device_bitmap;
extern bitmap sub_LCD_device_bitmap;
extern U8 gCurrentMode;
extern S32 MAIN_LCD_device_width;
extern S32 MAIN_LCD_device_height;
extern S16 gAutoTestListSize;
extern PU8 AutoTestSelectedItems[MAX_AUTO_TEST_ITEMS];

extern rtc_format_struct myclocktime;
extern AutoTestResultArray nvramTestResultArray;
extern AutoTestItemArray nvramTestItemArray;

/*UNI@bw_20070427 9:52:40  add analog tv auto test*/
#if defined(ANALOG_TV_SUPPORT) 
void FM_AutoTest_AnalogTv(void);
void mmi_fm_exit_analogtv_screen(void);
extern mmi_analog_tv_context_struct g_analog_tv_cntx;
//extern mmi_analog_tv_menu_context_struct g_analog_tv_menu_cntx;
extern mmi_AnalogTv_data_struct  g_AnalogTv_data;
extern void GetSingalIndicate();
extern U16 mmi_tv_max_index;
kal_bool  mmi_tv_test_on=KAL_FALSE; /*UNI@bw070530 测试完TV后，按power key退出，再进入电视还是测试模式*/
#endif
#ifdef DOUBLE_CAMERA_SUPPORT   /*UNI@bw070628 add sub camera test*/
extern BOOL  mmi_main_camera_active;
#endif

#if defined(__FM_CAMERA_TUNNING__) || defined(__FM_CAMERA_PREVIEW__)
extern camera_context_struct g_camera_cntx;
extern const U8 camera_ev_command_map[];
extern const U8 camera_zoom_command_map[];
extern const U8 camera_effect_command_map[];
extern const U8 camera_wb_command_map[];
extern const U8 camera_banding_command_map[];
extern const U8 camera_jpg_size_command_map[];
extern const U8 camera_image_qty_command_map[];

/* extern gdi_color                     GDI_COLOR_BLACK; */
extern wgui_inline_item wgui_inline_items[];

extern gdi_handle wgui_base_layer;
extern gdi_handle wgui_layer_1;

#endif /* defined(__FM_CAMERA_TUNNING__) || defined(__FM_CAMERA_PREVIEW__) */ 

/****************************************************************************
* Global Function                                                           
*****************************************************************************/
extern void UI_set_clip(S32 x1, S32 y1, S32 x2, S32 y2);
extern void UI_fill_rectangle(S32 x1, S32 y1, S32 x2, S32 y2, color c);
extern void UI_reset_text_clip(void);
extern void UI_set_font(UI_font_type f);
extern void UI_set_text_color(color c);

extern void ShowCategory205Screen(
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                UI_string_type message,
                U16 message_icon,
                U8 *history_buffer);
extern void PhnsetMainLCDContrast(U8 level);
extern void PhnsetSubLCDContrast(U8 level);
extern void BatteryStatusRsp(void *);
extern void QuitSystemOperation(void);
extern void FactorySetAlarm(U8 sec);
extern void SetBacklightModeExe(U8 mode);
extern kal_char *build_date_time(void);
extern void GoBackBothLCDHistory(void);
extern void EMFMBatteryStatusMsgHandler(void *inMsg);
extern module_type UART_GetOwnerID(UART_PORT port);
extern void wgui_update_inline_data(void);  /* for camera tune screen */
extern U16 GetCurKeypadTone(void);

#ifdef NAND_SUPPORT
extern kal_bool NANDsanitycheck_Factory(void);
#endif 

#if defined(__FM_CAMERA_TUNNING__) || defined(__FM_CAMERA_PREVIEW__)
extern void mmi_fm_camera_entry_sublcd_screen(void);
#endif 

/***************************************************************************** 
* Local Variable
*****************************************************************************/
S8 EMFMUnicodeDisplayBuf[MAX_TEST_STRING_BUF * 2];  /* display buffer */
S8 CardType[32];
U8 EMFMAsciiDisplayBuf[MAX_TEST_STRING_BUF];
U8 NeedExitFunc = TRUE;
S16 currTestItem = 0;
BOOL TestExecuted[MAX_AUTO_TEST_ITEMS];

U8 FmcurrentHighlightIndex;

static U8 sequence_counter = 0; /* for auto display action use */
static U16 currentContrast = 7;
static U8 LCDType = 0;
static U8 autoTestMode = 0;
static U8 currentTest = 0;
static U8 gFM_HighlightIdx;
static U8 gFM_MenuItemNum;
static U8 gBarCode[MAX_SUB_MENU_SIZE];
static U8 gBarCodeReadFlag = 0;
static U32 FM_LEDState;
static FM_ADC_TYPE_ENUM adc_mode = FM_ADC_BATTERY;

static unsigned char keypad_status[LINE_NUM][COLUMN_NUM];
static U8 InkeyTestingScreen = 0;

/* ===== Audio test status ======= */
typedef enum
{
    FM_AUDIO_TEST_STAT_NONE,
    FM_AUDIO_TEST_STAT_ECHOLOOP,
    FM_AUDIO_TEST_STAT_RINGTONE,
    FM_AUDIO_TEST_STAT_RECEIVER
} FM_AUDIO_TEST_STAT_ENUM;

/* ===== Audio test status ======= */
static U8 g_FM_AUDIO_TEST_STATUS = FM_AUDIO_TEST_STAT_NONE;

/* ===== Loud Speak ============ */
static BOOL LoudSpkTestOn = FALSE;

/*=============== MTBF =============== */
static U32 MTBF_counter = 0;    /* for MTBF */
static FM_MTBF_LCD_ENUM MTBF_state_LCD = 0;
static FM_MTBF_LED_ENUM MTBF_state_LED = 0;
static FM_MTBF_VIB_ENUM MTBF_state_VIB = 0;
static FM_MTBF_AUD_ALTERNATION_ENUM AUD_TEST_ON = 0;

const device_tones_struct test_tone[] = { {1000, 0, 0, 0, 0} };

const device_tones_struct SPK_test_tone[FM_MTBF_SPK_MAX] = 
{
    {400, 0, FM_MTBF_SPK_UNIT_CYCLE, FM_MTBF_AUDIO_GAP, 1},
    {600, 0, FM_MTBF_SPK_UNIT_CYCLE, FM_MTBF_AUDIO_GAP, 2},
    {800, 0, FM_MTBF_SPK_UNIT_CYCLE, FM_MTBF_AUDIO_GAP, 3},
    {850, 0, FM_MTBF_SPK_UNIT_CYCLE, FM_MTBF_AUDIO_GAP, 4},
    {850, 0, FM_MTBF_SPK_UNIT_CYCLE, FM_MTBF_AUDIO_GAP, 5},
    {900, 0, FM_MTBF_SPK_UNIT_CYCLE, FM_MTBF_AUDIO_GAP, 6},
    {1000, 0, FM_MTBF_SPK_UNIT_CYCLE, FM_MTBF_AUDIO_GAP, 7},
    {2000, 0, FM_MTBF_SPK_UNIT_CYCLE, FM_MTBF_AUDIO_GAP, 8},
    {4000, 0, FM_MTBF_SPK_UNIT_CYCLE, FM_MTBF_AUDIO_GAP, 9},
    {8000, 0, FM_MTBF_SPK_UNIT_CYCLE, FM_MTBF_AUDIO_GAP, 0}
};

const device_tones_struct REV_test_tone[FM_MTBF_REV_MAX] = 
{
    {400, 0, FM_MTBF_REV_UNIT_CYCLE, FM_MTBF_AUDIO_GAP, 1},
    {500, 0, FM_MTBF_REV_UNIT_CYCLE, FM_MTBF_AUDIO_GAP, 2},
    {600, 0, FM_MTBF_REV_UNIT_CYCLE, FM_MTBF_AUDIO_GAP, 3},
    {600, 0, FM_MTBF_REV_UNIT_CYCLE, FM_MTBF_AUDIO_GAP, 4},
    {700, 0, FM_MTBF_REV_UNIT_CYCLE, FM_MTBF_AUDIO_GAP, 5},
    {800, 0, FM_MTBF_REV_UNIT_CYCLE, FM_MTBF_AUDIO_GAP, 6},
    {1000, 0, FM_MTBF_REV_UNIT_CYCLE, FM_MTBF_AUDIO_GAP, 7},
    {1500, 0, FM_MTBF_REV_UNIT_CYCLE, FM_MTBF_AUDIO_GAP, 8},
    {2000, 0, FM_MTBF_REV_UNIT_CYCLE, FM_MTBF_AUDIO_GAP, 9},
    {3000, 0, FM_MTBF_REV_UNIT_CYCLE, FM_MTBF_AUDIO_GAP, 0}
};

static BOOL EchoLoopTestOn = FALSE;     /* Echo Loop */
static U8 vib, vib_status = KAL_FALSE;  /* Vibrator */
static BOOL ReceiverTestOn = FALSE;     /* Receiver */
static BOOL HeadsetTestOn = FALSE;      /* Headset Test */
static BOOL RingToneTestOn = FALSE;     /* RingTone */
U8 gFactoryAlarm = 0;                   /* Factory Alarm Flag for MMI alarm framework use */

mmi_fmt_get_msdc_status_rsp_strcut FM_Card_Status;

BOOL Card_Response_Received = FALSE;
BOOL Card_Response_Sent = FALSE;
BOOL UART_Response_Received = FALSE;

U8 FM_LED_Menu[][MAX_SUB_MENU_SIZE] = 
{
    "Main LCM BL",
#ifdef __MMI_SUBLCD__
    "Sub LCM BL",
#endif 
    "Keypad LED",

#ifndef __MMI_HIDE_STATUS_LED_R__
    "Status LED R",
#endif 

#ifndef __MMI_HIDE_STATUS_LED_G__
    "Status LED G",
#endif 

#ifndef __MMI_HIDE_STATUS_LED_B__
    "Status LED B"
#endif 
};

/* camera */
fm_camtune_cntx_struct g_camtune_cntx;

#if defined(DOUBLE_BATTERY_SUPPORT)
//Huyanwei Add It 
extern void FM_AutoTest_ADC(void);
#endif


/*=============== Auto Testing =============== */
const testlet Tests[MAX_AUTO_TEST_ITEMS] = {    /* Maximum name length = MAX_TEST_ITEM_NAME_LEN*ENCODING_LENGTH */
    {{'L', 0, 'E', 0, 'D', 0}, FM_AutoTest_LED},
#if defined(DOUBLE_BATTERY_SUPPORT)
  //Huyanwei Add It For ADC
    {{'A', 0,'D', 0,'C', 0}, FM_AutoTest_ADC},
 #endif		
    {{'C', 0, 'l', 0, 'a', 0, 'm', 0}, FM_AutoTest_CLAM},
    {{'L', 0, 'C', 0, 'M', 0}, FM_AutoTest_SubLCM},
    {{'V', 0, 'e', 0, 'r', 0, 's', 0, 'i', 0, 'o', 0, 'n', 0}, FM_AutoTest_Version},
    {{'B', 0, 'a', 0, 'c', 0, 'k', 0, 'L', 0, 'i', 0, 'g', 0, 'h', 0, 't', 0}, FM_AutoTest_Backlight},
    {{'L', 0, 'C', 0, 'D', 0}, FM_AutoTest_LCD},
    {{'K', 0, 'e', 0, 'y', 0, 'P', 0, 'a', 0, 'd', 0}, FM_AutoTest_Keypad},
    {{'R', 0, 'e', 0, 'c', 0, 'e', 0, 'i', 0, 'v', 0, 'e', 0, 'r', 0}, FM_AutoTest_Receiver},
    {{'M', 0, 'I', 0, 'C', 0}, FM_AutoTest_MIC},
    {{'S', 0, 'p', 0, 'e', 0, 'a', 0, 'k', 0, 'e', 0, 'r', 0}, FM_AutoTest_Speaker},
    {{'H', 0, 'e', 0, 'a', 0, 'd', 0, 's', 0, 'e', 0, 't', 0}, FM_AutoTest_Headset},
    {{'B', 0, 'a', 0, 't', 0, 't', 0, 'e', 0, 'r', 0, 'y', 0}, FM_AutoTest_Battery},
    {{'M', 0, 'e', 0, 'l', 0, 'o', 0, 'd', 0, 'y', 0}, FM_AutoTest_Melody},
    {{'V', 0, 'i', 0, 'b', 0, 'r', 0, 'a', 0, 't', 0, 'o', 0, 'r', 0}, FM_AutoTest_VIB},
    {{'C', 0, 'h', 0, 'a', 0, 'r', 0, 'g', 0, 'e', 0, 'r', 0}, FM_AutoTest_Charger},
    {{'N', 0, 'A', 0, 'N', 0, 'D', 0}, FM_AutoTest_NAND},
    {{'U', 0, 'A', 0, 'R', 0, 'T', 0}, FM_AutoTest_UART},
    {{'D', 0, 'o', 0, 'u', 0, 'b', 0, 'l', 0, 'e', 0, 'S', 0, 'p', 0, 'e', 0, 'a', 0, 'k', 0, 'e', 0, 'r', 0}, FM_AutoTest_Double_Speaker},     /* 17 */
    {{'C', 0, 'A', 0, 'M', 0, 'E', 0, 'R', 0, 'A', 0}, FM_AutoTest_CAMERA},     /* 18 */
    {{'M', 0, 'e', 0, 'm', 0, 'o', 0, 'r', 0, 'y', 0, 'C', 0, 'a', 0, 'r', 0, 'd', 0}, FM_AutoTest_MemoryCard}  /* 19 */
#ifdef __MMI_TOUCH_SCREEN__
    , {{'P', 0, 'a', 0, 'r', 0, 'a', 0, 'l', 0, 'l', 0, 'e', 0, 'l', 0, 'L', 0, 'i', 0, 'n', 0, 'e', 0}, FM_AutoTest_Pen_Parallel_Test} /* 20 */
    , {{'N', 0, 'x', 0, 'M', 0, 'P', 0, 'o', 0, 'i', 0, 'n', 0, 't', 0}, FM_AutoTest_Pen_N_Cross_M_Test}        /* 21 */
#endif /* __MMI_TOUCH_SCREEN__ */ 
/* hongzhe.liu add start */
  #if defined(ANALOG_TV_SUPPORT)
  ,{{'A', 0,'N', 0,'A', 0,'L', 0,'O', 0,'G', 0,'T', 0,'V', 0}, FM_AutoTest_AnalogTv} //24
  #endif
/* hongzhe.liu add end */
};

#if !defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_NORMAL_KEYPAD__)

	/* ========== KeyPad test use ================ */
	const char *keypad_layout[LINE_NUM][COLUMN_NUM] = 
	{
		{ "V+ ",    "V- ", "Cam ", KEY_NONE_NAME},
		{"Sd1","Sd2", KEY_END_NAME," OK"},
		{KEY_UP_ARROW_NAME, KEY_DOWN_ARROW_NAME, KEY_LEFT_ARROW_NAME, KEY_RIGHT_ARROW_NAME},
		{KEY_NONE_NAME, KEY_RSK_NAME, "Ext1 ", "Ext2 "},
		{" 1 ", " 2 ", " 3 ", " * "},
		{" 4 ", " 5 ", " 6 ", " 0 "},
		{"   7", " 8 ", " 9 ", " # "},
		{KEY_NONE_NAME, KEY_NONE_NAME, KEY_NONE_NAME, KEY_NONE_NAME},
	};

	const U16 keypad_value[] = 
	{
		KEY_VOL_UP_VALUE,       KEY_VOL_DOWN_VALUE,     KEY_CAMERA,                    KEY_NONE_VALUE,
		KEY_LSK_VALUE/*KEY_SEND1*/,                   KEY_SEND2,                       KEY_END,                           KEY_ENTER,
		KEY_UP_ARROW_VALUE, KEY_DOWN_ARROW_VALUE, KEY_LEFT_ARROW_VALUE, KEY_RIGHT_ARROW_VALUE,
		KEY_NONE_VALUE,       KEY_RSK_VALUE,                  KEY_EXTRA_1,                 KEY_EXTRA_2,
		KEY_1,                           KEY_2,                                KEY_3,                              KEY_STAR,  
		KEY_4,                           KEY_5,                                KEY_6,                              KEY_0, 
		KEY_7,                           KEY_8,                                KEY_9,                              KEY_POUND,
		KEY_NONE_VALUE,       KEY_NONE_VALUE,            KEY_NONE_VALUE,          KEY_NONE_VALUE
	};
	
#else /* __MMI_TOUCH_SCREEN__ */ 
/* ========== KeyPad test use ================ */
const char *keypad_layout[LINE_NUM][COLUMN_NUM] = 
{
    {KEY_LSK_NAME, KEY_NONE_NAME, KEY_NONE_NAME, KEY_RSK_NAME},
#if defined(__MMI_FACTORY_MODE_NAV_KEY__) || defined(__MMI_WITH_C_KEY__)
    {KEY_NONE_NAME, KEY_NONE_NAME, KEY_NONE_NAME, KEY_NONE_NAME},
#endif 

#if defined(__MMI_FOURWAYS_KEY_DISABLE__)
    {KEY_NONE_NAME, KEY_NONE_NAME, KEY_NONE_NAME, KEY_NONE_NAME},
#else 
    {KEY_UP_ARROW_NAME, KEY_DOWN_ARROW_NAME, KEY_LEFT_ARROW_NAME, KEY_RIGHT_ARROW_NAME},
#endif 

    /* {KEY_SEND_NAMEE, KEY_VOL_UP_NAME, KEY_VOL_DOWN_NAME, KEY_END_NAM}, */
    {KEY_SEND_NAME, KEY_NONE_NAME, KEY_NONE_NAME, KEY_END_NAME},

    {KEY_NONE_NAME, KEY_NONE_NAME, KEY_NONE_NAME, KEY_NONE_NAME},
    {KEY_NONE_NAME, KEY_NONE_NAME, KEY_NONE_NAME, KEY_NONE_NAME},
    {KEY_NONE_NAME, KEY_NONE_NAME, KEY_NONE_NAME, KEY_NONE_NAME},
    {KEY_NONE_NAME, KEY_NONE_NAME, KEY_NONE_NAME, KEY_NONE_NAME},
};

const U16 keypad_value[] = 
{
    KEY_LSK_VALUE, KEY_NONE_VALUE, KEY_NONE_VALUE, KEY_RSK_VALUE,
#if defined(__MMI_FACTORY_MODE_NAV_KEY__) || defined(__MMI_WITH_C_KEY__)
    KEY_NONE_VALUE, KEY_NONE_VALUE, KEY_NONE_VALUE, KEY_NONE_VALUE,
#endif 

#if defined(__MMI_FOURWAYS_KEY_DISABLE__)
    KEY_NONE_VALUE, KEY_NONE_VALUE, KEY_NONE_VALUE, KEY_NONE_VALUE,
#else 
    KEY_UP_ARROW_VALUE, KEY_DOWN_ARROW_VALUE, KEY_LEFT_ARROW_VALUE, KEY_RIGHT_ARROW_VALUE,
#endif 

    /* KEY_SEND_VALUE, KEY_VOL_UP_VALUE, KEY_VOL_DOWN_VALUE, KEY_END_VALUE, */
    KEY_SEND_VALUE, KEY_NONE_VALUE, KEY_NONE_VALUE, KEY_END_VALUE,

    KEY_NONE_VALUE, KEY_NONE_VALUE, KEY_NONE_VALUE, KEY_NONE_VALUE,
    KEY_NONE_VALUE, KEY_NONE_VALUE, KEY_NONE_VALUE, KEY_NONE_VALUE,
    KEY_NONE_VALUE, KEY_NONE_VALUE, KEY_NONE_VALUE, KEY_NONE_VALUE,
    KEY_NONE_VALUE, KEY_NONE_VALUE, KEY_NONE_VALUE, KEY_NONE_VALUE,
};

#endif /* __MMI_TOUCH_SCREEN__ */ 

#ifdef __MMI_FM_RADIO__
typedef struct {
    U16      text_id;
    U16      Currfreq;
    U8       CurrVolume;
    U8       is_FMRDO_on;
} fm_fm_radio_struct;

fm_fm_radio_struct g_fm_fm_radio_cntx={0};
#endif

/*****************************************************************************
* Local Function 
*****************************************************************************/
#if defined(__FM_CAMERA_TUNNING__)
static void mmi_fm_camtune_init(void);
static void mmi_fm_entry_camera_screen(void);
static void mmi_fm_camera_entry_restore_confirm_screen(void);
static void mmi_fm_camera_restore_confirm_yes(void);
static void mmi_fm_camera_entry_save_confirm_screen(void);
static void mmi_fm_camera_save_confirm_yes(void);
static void mmi_fm_camera_highlight_hdlr(S32 index);

static void mmi_fm_camtune_set_value(void);
static void mmi_fm_camtune_draw_info_callback(S32 index, S32 x1, S32 y1, S32 x2, S32 y2);
static void mmi_fm_camtune_highlight_hdlr(S32 index);
static void mmi_fm_camtune_get_category_info(U16 category_idx);
static void mmi_fm_camtune_get_group_info(U16 category_idx, U16 group_idx);
static void mmi_fm_camtune_change_group_fwd(void);
static void mmi_fm_camtune_change_group_bwd(void);
static void mmi_fm_camtune_toggle_fullscreen(void);
static void mmi_fm_camtune_show_group(void);
static void mmi_fm_camtune_customize(void);
static void mmi_fm_camtune_entry_screen(void);
static void mmi_fm_camtune_exit_screen(void);

static void mmi_fm_highlight_camera(void);
#endif /* defined(__FM_CAMERA_TUNNING__) */ 

#if defined(__FM_CAMERA_PREVIEW__)
void mmi_fm_camera_entry_preview_screen(void);
#ifdef DOUBLE_CAMERA_SUPPORT   /*UNI@bw070628 add sub camera test*/
void mmi_fm_sub_camera_entry_preview_screen(void);
#endif
#endif 

/*UNI@bw_20070427 9:52:40  add analog tv auto test*/
#if defined(ANALOG_TV_SUPPORT) 
      void mmi_fm_entry_analogtv_screen(void);
#endif 

#if defined(__FM_CAMERA_PREVIEW__) || defined(__FM_CAMERA_TUNNING__)
static void mmi_fm_highlight_camera(void);
#endif 

/***************************************************************************
*
*  Cody Body                                                   
*
***************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  InitFactoryMode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitFactoryMode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU_ID_FM_VERSION, HightlightFMVersionHdlr);

    SetHiliteHandler(MENU_ID_FM_SW_SUMMARY, HightlightFMVersionSummaryHdlr);
    SetHiliteHandler(MENU_ID_FM_SW_VER, HightlightFMVersionCommonHdlr);
    SetHiliteHandler(MENU_ID_FM_MELODY_VER, HightlightFMVersionCommonHdlr);
    SetHiliteHandler(MENU_ID_FM_ISN, HightlightFMVersionCommonHdlr);
    SetHiliteHandler(MENU_ID_FM_BBCHIP_VER, HightlightFMVersionCommonHdlr);
    SetHiliteHandler(MENU_ID_FM_DSPCODE_VER, HightlightFMVersionCommonHdlr);
    SetHiliteHandler(MENU_ID_FM_DSPATCH_VER, HightlightFMVersionCommonHdlr);
    SetHiliteHandler(MENU_ID_FM_HW_VER, HightlightFMVersionCommonHdlr);
    SetHiliteHandler(MENU_ID_FM_BUILD_TIME, HightlightFMVersionCommonHdlr);

    SetHiliteHandler(MENU_ID_FM_RESOURCE_BIN, HightlightFMResourceBinHdlr);
    SetHiliteHandler(MENU_ID_FM_LED, HightlightFMLEDHdlr);
    SetHiliteHandler(MENU_ID_FM_LCD, HightlightFMLCDHdlr);
    SetHiliteHandler(MENU_ID_FM_LCD_AUTO, HightlightFMLCDCertainHdlr);
    SetHiliteHandler(MENU_ID_FM_LCD_R, HightlightFMLCDCertainHdlr);
    SetHiliteHandler(MENU_ID_FM_LCD_G, HightlightFMLCDCertainHdlr);
    SetHiliteHandler(MENU_ID_FM_LCD_B, HightlightFMLCDCertainHdlr);
    SetHiliteHandler(MENU_ID_FM_LCD_W, HightlightFMLCDCertainHdlr);
    SetHiliteHandler(MENU_ID_FM_LCD_BLACK, HightlightFMLCDCertainHdlr);
    SetHiliteHandler(MENU_ID_FM_LCD_CONTRAST, HightlightFMLCDContrastHdlr);
    SetHiliteHandler(MENU_ID_FM_LCD_CONTRAST_MAINLCD, HightlightFMLCDContrastMainHdlr);
    SetHiliteHandler(MENU_ID_FM_LCD_CONTRAST_SUBLCD, HightlightFMLCDContrastSubHdlr);
    SetHiliteHandler(MENU_ID_FM_KEYPAD, HightlightFMKeypadHdlr);
    SetHiliteHandler(MENU_ID_FM_LOUDSPK, HightlightFMLoudSpkHdlr);
    SetHiliteHandler(MENU_ID_FM_EACHLOOP, HightlightFMEchoLoopHdlr);
    SetHiliteHandler(MENU_ID_FM_VIBRATOR, HightlightFMVibratorHdlr);
    SetHiliteHandler(MENU_ID_FM_ADC, HightlightFMADCHdlr);
    SetHiliteHandler(MENU_ID_FM_RECEIVER, HightlightFMReceiverHdlr);
    SetHiliteHandler(MENU_ID_FM_RTC, HightlightFMRTCHdlr);
    SetHiliteHandler(MENU_ID_FM_MTBF, HightlightFMMTBFHdlr);

#if (defined(__MSDC_MS__) || defined(__MSDC_SD_MMC__) || defined(__MSDC_MSPRO__))
    SetHiliteHandler(MENU_ID_FM_MEMORY_CARD, HightlightFMMemoryCardHdlr);
#endif 
    SetHiliteHandler(MENU_ID_FM_UART, HightlightFMUARTHdlr);

#if defined(__FM_CAMERA_TUNNING__) || defined(__FM_CAMERA_PREVIEW__)
    SetHiliteHandler(MENU_ID_FM_CAMERA, mmi_fm_highlight_camera);
#endif 

    SetHiliteHandler(MENU_ID_FM_NAND_FLASH, HightlightFMNandFlashHdlr);
    SetHiliteHandler(MENU_ID_FM_HEADSET, HightlightFMHeadsetHdlr);
    SetHiliteHandler(MENU_ID_FM_CHARGER, HightlightFMChargerHdlr);
    SetHiliteHandler(MENU_ID_FM_RINGTONE, HightlightFMRingToneHdlr);

    /* Set protocol event handler */
    SetProtocolEventHandler(FM_ATEntryMenuHdlr, MSG_ID_MMI_FACTORY_TEST_IND);
    SetProtocolEventHandler(FM_ATKeypadTestMsgHdlr, MSG_ID_MMI_EM_KEYPAD_EVENT_ACT_IND);
    SetProtocolEventHandler(FM_ATLCDTestMsgHdlr, MSG_ID_MMI_EM_LCM_TEST_IND);

#if (defined(__MSDC_MS__) || defined(__MSDC_SD_MMC__) || defined(__MSDC_MSPRO__))
    SetProtocolEventHandler(FM_MemoryCardResponseHandler, MSG_ID_MMI_FMT_GET_MSDC_STATUS_RSP);
#endif 
    /* SetProtocolEventHandler (FM_UARTResponseHandler, MSG_ID_MMI_FMT_GET_MSDC_STATUS_RSP); */
#ifdef __MMI_TOUCH_SCREEN__
    SetHiliteHandler(MENU_ID_FM_PARALLEL_LINE, HighlightFMParallelTestHdlr);
    SetHiliteHandler(MENU_ID_FM_N_CROSS_M, HighlightFMNCrossMTestHdlr);
#endif /* __MMI_TOUCH_SCREEN__ */ 

#ifdef __MMI_FM_RADIO__
    SetHiliteHandler(MENU_ID_FM_FMRADIO, HighlightFMFMRadiohdlr);
#endif

#if defined(__FM_CAMERA_TUNNING__)
    mmi_fm_camtune_init();
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  InitFactoryModeSetting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitFactoryModeSetting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gCurrentMode = FACTORY_MODE;
    mdi_audio_suspend_background_play();
    mdi_audio_stop_all();
    mdi_switch_device_ownership(MOD_MMI, MDI_DEVICE_AUDIO | MDI_DEVICE_CAMER | MDI_DEVICE_VIDEO);
    StopLEDPatternBackGround();
}


/*****************************************************************************
 * FUNCTION
 *  FM_ReTest
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void FM_ReTest(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* currTestItem--; */
    sequence_counter = 0;   /* Reset the sequence counter */
    TestExecuted[currTestItem] = FALSE;
    EntryFMAutoTestStart();
}


/*****************************************************************************
 * FUNCTION
 *  FM_Autotest_test_done_USC2string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  name        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void FM_Autotest_test_done_USC2string(const S8 *name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 name_ascii[MAX_TEST_ITEM_NAME_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2_to_asc((S8*) name_ascii, (S8*) name);

    sprintf((S8*) EMFMAsciiDisplayBuf, "%s (%d/%d)\n", name_ascii, currTestItem + 1, gAutoTestListSize);

    mmi_asc_to_ucs2((S8*) EMFMUnicodeDisplayBuf, (S8*) EMFMAsciiDisplayBuf);

    /* Lisen 01262005 */
    if (currentTest == FM_AUTOTEST_MEMORYCARD)
    {
        mmi_ucs2cat((S8*) EMFMUnicodeDisplayBuf, CardType);
    }
    else
    {
        mmi_ucs2cat((S8*) EMFMUnicodeDisplayBuf, GetString(STR_GLOBAL_DONE));
    }

    mmi_asc_to_ucs2((S8*) EMFMAsciiDisplayBuf, ".\n\nSendkey: ");

    mmi_ucs2cat((S8*) EMFMUnicodeDisplayBuf, (S8*) EMFMAsciiDisplayBuf);

    mmi_ucs2cat((S8*) EMFMUnicodeDisplayBuf, GetString(STR_ID_FM_AUTO_TEST_RETEST));

    mmi_asc_to_ucs2((S8*) EMFMAsciiDisplayBuf, "\nEndkey: ");

    mmi_ucs2cat((S8*) EMFMUnicodeDisplayBuf, (S8*) EMFMAsciiDisplayBuf);

    mmi_ucs2cat((S8*) EMFMUnicodeDisplayBuf, GetString(STR_ID_FM_AUTO_TEST_EXIT));
}


/*****************************************************************************
 * FUNCTION
 *  FM_RESET_AUDIO_STATE
 * DESCRIPTION
 *  
 * PARAMETERS
 *  status      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void FM_RESET_AUDIO_STATE(FM_AUDIO_TEST_STAT_ENUM status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_FM_AUDIO_TEST_STATUS == FM_AUDIO_TEST_STAT_ECHOLOOP) && (status != FM_AUDIO_TEST_STAT_ECHOLOOP))
    {
        EchoLoopTestOn = FALSE;
    }
    else if ((g_FM_AUDIO_TEST_STATUS == FM_AUDIO_TEST_STAT_RINGTONE) && (status != FM_AUDIO_TEST_STAT_RINGTONE))
    {
        RingToneTestOn = FALSE;
    }
    else if ((g_FM_AUDIO_TEST_STATUS == FM_AUDIO_TEST_STAT_RECEIVER) && (status != FM_AUDIO_TEST_STAT_RECEIVER))
    {
        ReceiverTestOn = FALSE;
    }
    g_FM_AUDIO_TEST_STATUS = status;
}


/*****************************************************************************
 * FUNCTION
 *  FM_BACK_TO_NORMAL_STATE
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void FM_BACK_TO_NORMAL_STATE(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sequence_counter = 0;
    StopTimer(FM_AUTO_TEST_COMMNON_TIMER);

    ReceiverTestOn = FALSE;
    EchoLoopTestOn = FALSE;
    LoudSpkTestOn = FALSE;
    HeadsetTestOn = FALSE;

    /* LED */
    FM_SetGpioReq(GPIO_DEV_LED_STATUS_1, LED_LIGHT_LEVEL0);
    FM_SetGpioReq(GPIO_DEV_LED_STATUS_2, LED_LIGHT_LEVEL0);
    FM_SetGpioReq(GPIO_DEV_LED_STATUS_3, LED_LIGHT_LEVEL0);

    /* LCD */
    FM_SetGpioReq(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL5);
    FM_SetGpioReq(GPIO_DEV_LED_KEY, LED_LIGHT_LEVEL0);

    /* LCD contrast */
    PhnsetMainLCDContrast(7);
    PhnsetSubLCDContrast(7);

    //Lisen 0702
    //Receiver : stop 1K tone
    TONE_Stop();

    /* MIC: close loopback */
    custom_em_set_loopback(FALSE);

    /* Ringtone */
    RingToneTestOn = FALSE;
    FM_SendSetAudioModeReq(AUD_MODE_NORMAL);
    /* stop MIDI */
    FM_SendStopAudioReq(0);

    /* VIB */
    FM_SetGpioReq(GPIO_DEV_VIBRATOR, VIBRATOR_OFF);
}


/*****************************************************************************
 * FUNCTION
 *  FM_Handle_Pass_Key_Press
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void FM_Handle_Pass_Key_Press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FM_BACK_TO_NORMAL_STATE();

    nvramTestResultArray.result[currTestItem] = FM_TEST_PASSED;
    currTestItem++;
    WriteTestResultToNVRAM();
    EntryFMAutoTestStart();
}


/*****************************************************************************
 * FUNCTION
 *  FM_Handle_Fail_Key_Press
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void FM_Handle_Fail_Key_Press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FM_BACK_TO_NORMAL_STATE();

    nvramTestResultArray.result[currTestItem] = FM_TEST_FAILED;
    currTestItem++;
    WriteTestResultToNVRAM();
    EntryFMAutoTestStart();
}


/*****************************************************************************
 * FUNCTION
 *  FM_Autotest_set_key_handlers
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void FM_Autotest_set_key_handlers(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(FM_ReTest, KEY_SEND, KEY_EVENT_DOWN);
    PowerAndEndKeyHandler();
    SetLeftSoftkeyFunction(FM_Handle_Pass_Key_Press, KEY_EVENT_UP);
    SetRightSoftkeyFunction(FM_Handle_Fail_Key_Press, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  FM_Autotest_Stop_Test
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void FM_Autotest_Stop_Test(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sequence_counter = 0;   /* Reset the sequence counter */

    switch (currentTest)
    {
        case FM_TEST_LED:
            break;
        case FM_TEST_CLAM_DETECT:
            break;
        case FM_TEST_SUBLCM:
            break;
        case FM_TEST_SW_VERSION:
            break;
        case FM_TEST_BACKLIGHT:
            break;
        case FM_TEST_LCD:
            break;
        case FM_TEST_KEYPAD:
            break;
        case FM_TEST_RECEIVER:
        case FM_TEST_MIC:
        case FM_TEST_SPEAKER:
        case FM_TEST_HEADSET:
            Media_Stop();
            break;
        case FM_TEST_VIB:
            break;
        case FM_TEST_BATTERY:
            break;
        case FM_TEST_MELODY:
            Media_Stop();
            FM_SendSetAudioModeReq(AUD_MODE_NORMAL);
            FM_SendStopAudioReq(0);
            break;
        case FM_TEST_CHARGER:
            break;
        case FM_TEST_NAND:
            break;
        case FM_TEST_UART:
        case FM_TEST_DOUBLE_SPEAKER:
            Media_Stop();
            break;
        case FM_TEST_MEMORYCARD:
            break;
        case FM_TEST_CAMERA:
    #if defined(__MMI_CAMERA__)

    #endif 
            break;
    #ifdef __MMI_TOUCH_SCREEN__
        case FM_TEST_PEN_PARALLEL_LINES:
            break;
        case FM_TEST_PEN_N_CROSS_M_POINTS:
            break;
    #endif /* __MMI_TOUCH_SCREEN__ */ 

	 /*UNI@bw_20070429 14:12:45  add tv auto test*/
     #ifdef  ANALOG_TV_SUPPORT
             case      FM_TEST_ANALOG_TV:
			break;
    #endif

        default:
            ASSERT(0);
    }
}

/*****************************************************************
 **  Root Menu
 *****************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_main_delete_history_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  param       [?]     
 * RETURNS
 *  
 *****************************************************************************/
U8 mmi_fm_main_delete_history_hdlr(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gCurrentMode = NORMAL_MODE;
    mdi_switch_device_ownership(MOD_MMI, MDI_DEVICE_AUDIO | MDI_DEVICE_CAMER | MDI_DEVICE_VIDEO);
    mdi_audio_start_background_timer();
    mdi_audio_resume_background_play();
    StartLEDPatternBackGround();
    mmi_profiles_restore_activated_profile();
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  EntryFMMenu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryFMMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[32];
    U16 ItemIcons[32];
    U16 nItems;
    U8 *guiBuffer;
    S32 i;
    UI_string_type PopUpList[32];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_FM_ROOT, ExitFMMenu, NULL, NULL);

#ifndef __MTK_TARGET__
    mmi_frm_hide_menu_item(MENU_ID_FM_CAMERA);
#endif 

    autoTestMode = 0;
    guiBuffer = GetCurrGuiBuffer(SCR_ID_FM_ROOT);
    nItems = GetNumOfChild_Ext(MENU_ID_FM_ROOT);
    GetSequenceStringIds_Ext(MENU_ID_FM_ROOT, ItemList);
    /* GetSequenceImageIds(SCR_ID_FM_ROOT,ItemIcons); */
    SetParentHandler(MENU_ID_FM_ROOT);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    for (i = 0; i < nItems; i++)
    {
        if (ItemList[i] == STR_ID_FM_UART)
        {
            mmi_asc_to_ucs2((S8*) subMenuData[i], (S8*) "Be sure that UART2 is not in use!");
            PopUpList[i] = (UI_string_type) subMenuData[i];
        }
        else
        {
            PopUpList[i] = NULL;
        }
    }
    for (i = 0; i < nItems ; i++)
    {
        ItemIcons[i] = (U16) (IMG_GLOBAL_L1 + i);   /* ReturnRequiredNumberImageId(i); */
    }

    /*
     * FM_PreparePopUp( PopUpList );
     * ShowCategory52Screen(   STR_ID_FM_ROOT,0,
     * STR_GLOBAL_OK,0,
     * STR_GLOBAL_BACK,0,
     * nItems, ItemList, ItemIcons, (U8**) PopUpList, 0, 0, guiBuffer);
     */

    ShowCategory52Screen(
        STR_ID_FM_ROOT,
        0,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        nItems,
        ItemList,
        ItemIcons,
        (U8 **) PopUpList,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    InitFactoryModeSetting();

    SetDelScrnIDCallbackHandler(SCR_ID_FM_ROOT, (HistoryDelCBPtr) mmi_fm_main_delete_history_hdlr);
}

/**************************************************************
** FUNCTION NAME     : FM_RestoreAudio
**
**    PURPOSE           : Helper function for Restoring audio
**
** INPUT PARAMETERS  : nil
**
** OUTPUT PARAMETERS : void
**
** RETURNS           : void
**
** REMARKS        : 
**************************************************************/
void FM_RestoreAudio(void);


/*****************************************************************************
 * FUNCTION
 *  ExitFMMenu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitFMMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history currHistory;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* FM_RestoreAudio(); */
    if (LoudSpkTestOn || ReceiverTestOn)
    {
        TONE_Stop();
    }
    if (EchoLoopTestOn || HeadsetTestOn)
    {
        custom_em_set_loopback(FALSE);
    }
    if (RingToneTestOn)
    {
        FM_SendStopAudioReq(0);
    }
    mdi_switch_device_ownership(MOD_MMI, MDI_DEVICE_AUDIO | MDI_DEVICE_CAMER | MDI_DEVICE_VIDEO);
    mdi_audio_start_background_timer();

    currHistory.scrnID = SCR_ID_FM_ROOT;
    currHistory.entryFuncPtr = EntryFMMenu;
    mmi_ucs2cpy((S8*) currHistory.inputBuffer, (S8*) L"");
    GetCategoryHistory(currHistory.guiBuffer);
    AddHistory(currHistory);
}

/* Lisen 0921 */


/*****************************************************************************
 * FUNCTION
 *  HightlightFMVersionSummaryHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HightlightFMVersionSummaryHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    change_left_softkey(STR_GLOBAL_OK, 0);
    redraw_left_softkey();
    SetLeftSoftkeyFunction(EntryFMVersionSummaryMenu, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HightlightFMVersionCommonHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HightlightFMVersionCommonHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    clear_left_softkey_handler();
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    change_left_softkey((U16) NULL, 0);
    redraw_left_softkey();
    RedrawCategoryFunction();
}


/*****************************************************************************
 * FUNCTION
 *  EntryFMVersionSummaryMenu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S8 UnicodeDisplayBuf[MAX_TEST_STRING_BUF * 4];
extern kal_char *release_build(void);
/* 2009.05.08 added by huyanwei for software info + */
extern kal_char* software_summary(void) ;
/* 2009.05.08 added by huyanwei for software info - */
void EntryFMVersionSummaryMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 tempbuf[MAX_TEST_STRING_BUF * 2];
    U8 AsciiDisplayBuf[MAX_TEST_STRING_BUF];

    S16 ErrorCode, Ret;
    version_struct ver_struct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_FM_VERSION_SUMMARY, NULL, EntryFMVersionSummaryMenu, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_FM_VERSION_SUMMARY);
    SetParentHandler(MENU_ID_FM_SW_SUMMARY);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* Get Barcode from Nvram */
    if (gBarCodeReadFlag == 0)
    {
        memset(gBarCode, 0, sizeof(gBarCode));
        Ret = ReadRecord(NVRAM_EF_BARCODE_NUM_LID, 1, gBarCode, 64, &ErrorCode);
        if (!(ErrorCode == NVRAM_READ_SUCCESS && Ret == NVRAM_EF_BARCODE_NUM_SIZE))
        {
            strcpy((S8*) gBarCode, "SN001234567");
        }
        gBarCodeReadFlag = 1;
    }

    /* Get sturctured version number */
    INT_VersionNumbers(&ver_struct);

    memset(UnicodeDisplayBuf, 0, sizeof(UnicodeDisplayBuf));
    memset(AsciiDisplayBuf, 0, sizeof(AsciiDisplayBuf));
    mmi_asc_to_ucs2((S8*) AsciiDisplayBuf, "[VERSION] ");
    mmi_ucs2cpy((S8*) UnicodeDisplayBuf, (const S8*)AsciiDisplayBuf);

    memset(AsciiDisplayBuf, 0, sizeof(AsciiDisplayBuf));
    sprintf((S8*) AsciiDisplayBuf, " %s\n", (S8*) ver_struct.mcu_sw);
    memset(tempbuf, 0, sizeof(tempbuf));
    mmi_asc_to_ucs2((S8*) tempbuf, (S8*) AsciiDisplayBuf);
    mmi_ucs2cat((S8*) UnicodeDisplayBuf, (const S8*)tempbuf);

    /* Lisen 04072005 */
    memset(AsciiDisplayBuf, 0, sizeof(AsciiDisplayBuf));
    mmi_asc_to_ucs2((S8*) AsciiDisplayBuf, "[BRANCH]:");
    mmi_ucs2cat((S8*) UnicodeDisplayBuf, (const S8*)AsciiDisplayBuf);

    memset(AsciiDisplayBuf, 0, sizeof(AsciiDisplayBuf));
    sprintf((S8*) AsciiDisplayBuf, " %s\n", (S8*) ver_struct.mcu_sw_branch);
    memset(tempbuf, 0, sizeof(tempbuf));
    mmi_asc_to_ucs2((S8*) tempbuf, (S8*) AsciiDisplayBuf);
    mmi_ucs2cat((S8*) UnicodeDisplayBuf, (const S8*)tempbuf);

    memset(AsciiDisplayBuf, 0, sizeof(AsciiDisplayBuf));
    sprintf((S8*) AsciiDisplayBuf, "BUILD: %s\n", release_build());
    memset(tempbuf, 0, sizeof(tempbuf));
    mmi_asc_to_ucs2((S8*) tempbuf, (S8*) AsciiDisplayBuf);
    mmi_ucs2cat((S8*) UnicodeDisplayBuf, (const S8*)tempbuf);

    memset(AsciiDisplayBuf, 0, sizeof(AsciiDisplayBuf));
    sprintf((S8*) AsciiDisplayBuf, "SERIAL#: %s\n", (S8*) gBarCode);
    memset(tempbuf, 0, sizeof(tempbuf));
    mmi_asc_to_ucs2((S8*) tempbuf, (S8*) AsciiDisplayBuf);
    mmi_ucs2cat((S8*) UnicodeDisplayBuf, (const S8*)tempbuf);

/* 2009.05.08 added by huyanwei for software info + */
#if 1
	// Huyanwei Add It For Software Summary
   memset(AsciiDisplayBuf, 0, sizeof(AsciiDisplayBuf));
    sprintf((S8*) AsciiDisplayBuf, "[Software Summary] \n");
    memset(tempbuf, 0, sizeof(tempbuf));
    mmi_asc_to_ucs2((S8*) tempbuf, (S8*) AsciiDisplayBuf);
    mmi_ucs2cat((S8*) UnicodeDisplayBuf, (const S8*)tempbuf);

    memset(AsciiDisplayBuf, 0, sizeof(AsciiDisplayBuf));
    sprintf((S8*) AsciiDisplayBuf, "%s\n", (S8*) software_summary());
    memset(tempbuf, 0, sizeof(tempbuf));
    mmi_asc_to_ucs2((S8*) tempbuf, (S8*) AsciiDisplayBuf);
    mmi_ucs2cat((S8*) UnicodeDisplayBuf, (const S8*)tempbuf);
#endif
/* 2009.05.08 added by huyanwei for software info - */

    memset(AsciiDisplayBuf, 0, sizeof(AsciiDisplayBuf));
    sprintf((S8*) AsciiDisplayBuf, "[BUILD TIME] \n");
    memset(tempbuf, 0, sizeof(tempbuf));
    mmi_asc_to_ucs2((S8*) tempbuf, (S8*) AsciiDisplayBuf);
    mmi_ucs2cat((S8*) UnicodeDisplayBuf, (const S8*)tempbuf);

    memset(AsciiDisplayBuf, 0, sizeof(AsciiDisplayBuf));
    sprintf((S8*) AsciiDisplayBuf, "%s\n", (S8*) build_date_time());
    memset(tempbuf, 0, sizeof(tempbuf));
    mmi_asc_to_ucs2((S8*) tempbuf, (S8*) AsciiDisplayBuf);
    mmi_ucs2cat((S8*) UnicodeDisplayBuf, (const S8*)tempbuf);

    ShowCategory74Screen(
        STR_ID_FM_SW_SUMMARY,
        0,
        (U16) NULL,
        0,
        STR_GLOBAL_BACK,
        0,
        (PU8) UnicodeDisplayBuf,
        sizeof(UnicodeDisplayBuf),
        guiBuffer);
    /*          
     * ShowCategory7Screen( STR_ID_FM_VERSION, 0, (U16)NULL, 0, STR_GLOBAL_BACK,0, 
     * (PU8) UnicodeDisplayBuf, guiBuffer );
     */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}

/*****************************************************************
 **  Version Number
 *****************************************************************/


/*****************************************************************************
 * FUNCTION
 *  FM_PrepareVersionPopUp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  list        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void FM_PrepareVersionPopUp(UI_string_type *list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    S8 TempString[MAX_SUB_MENU_SIZE];

    S16 ErrorCode, Ret;
    version_struct ver_struct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(subMenuData, 0, sizeof(subMenuData));

#if defined(__MTK_TARGET__)

    /* Get Barcode from Nvram */
    if (gBarCodeReadFlag == 0)
    {
        memset(gBarCode, 0, sizeof(gBarCode));
        Ret = ReadRecord(NVRAM_EF_BARCODE_NUM_LID, 1, gBarCode, 64, &ErrorCode);
        if (!(ErrorCode == NVRAM_READ_SUCCESS && Ret == NVRAM_EF_BARCODE_NUM_SIZE))
        {
            strcpy((S8*) gBarCode, "SN001234567");
        }
        gBarCodeReadFlag = 1;
    }

    /* Get sturctured version number */
    INT_VersionNumbers(&ver_struct);

    /* Lisen 04072005 */
    /* MCU SW Version */
    memset(TempString, 0, sizeof(TempString));
    memcpy(TempString, (S8*) ver_struct.mcu_sw, MAX_SUB_MENU_SIZE - 2);
    mmi_asc_to_ucs2((S8*) subMenuData[1], (S8*) TempString);

    /* Melody Ver. */
    memset(TempString, 0, sizeof(TempString));
    custom_em_get_melody_version(TempString);
    mmi_asc_to_ucs2((S8*) subMenuData[2], (S8*) TempString);

    /* Serial No. */
    memset(TempString, 0, sizeof(TempString));
    memcpy(TempString, (S8*) gBarCode, MAX_SUB_MENU_SIZE - 2);
    mmi_asc_to_ucs2((S8*) subMenuData[3], (S8*) TempString);

    /* BB Chip Ver. */
    memset(TempString, 0, sizeof(TempString));
    memcpy(TempString, (S8*) ver_struct.bb_chip, MAX_SUB_MENU_SIZE - 2);
    mmi_asc_to_ucs2((S8*) subMenuData[4], (S8*) TempString);

    /* DSP Code Ver. */
    memset(TempString, 0, sizeof(TempString));
    memcpy(TempString, (S8*) ver_struct.dsp_fw, MAX_SUB_MENU_SIZE - 2);
    mmi_asc_to_ucs2((S8*) subMenuData[5], (S8*) TempString);

    /* DSP Patch Ver. */
    memset(TempString, 0, sizeof(TempString));
    memcpy(TempString, (S8*) ver_struct.dsp_ptch, MAX_SUB_MENU_SIZE - 2);
    mmi_asc_to_ucs2((S8*) subMenuData[6], (S8*) TempString);

    /* MS Board (HW Ver.) */
    memset(TempString, 0, sizeof(TempString));
    memcpy(TempString, (S8*) ver_struct.bb_board, MAX_SUB_MENU_SIZE - 2);
    mmi_asc_to_ucs2((S8*) subMenuData[7], (S8*) TempString);

    /* Build Version */
    memset(TempString, 0, sizeof(TempString));
    memcpy(TempString, (S8*) build_date_time(), MAX_SUB_MENU_SIZE - 2);
    mmi_asc_to_ucs2((S8*) subMenuData[8], (S8*) TempString);
    for (i = 0; i < MAX_VER_NUM; i++)
    {
        list[i] = (UI_string_type) subMenuData[i];
    }

#else /* defined(__MTK_TARGET__)) */ 
    /* For PC Simulatior */

    if (gBarCodeReadFlag == 0)
    {
        memset(gBarCode, 0, sizeof(gBarCode));
        strcpy((S8*) gBarCode, "SN001234567");
        gBarCodeReadFlag = 1;
    }

    /* BB Chip Ver. */
    memset(TempString, 0, sizeof(TempString));
    mmi_asc_to_ucs2((S8*) subMenuData[1], (S8*) "MTK_BB.V0");

    /* DSP Code Ver. */
    memset(TempString, 0, sizeof(TempString));
    mmi_asc_to_ucs2((S8*) subMenuData[2], (S8*) "MTK_DSP.V0");

    /* DSP Patch Ver. */
    memset(TempString, 0, sizeof(TempString));
    mmi_asc_to_ucs2((S8*) subMenuData[3], (S8*) "MTK_DSP_P.V0");

    /* MCU (SW Ver.) */
    memset(TempString, 0, sizeof(TempString));
    mmi_asc_to_ucs2((S8*) subMenuData[4], (S8*) "Branch MTK_SW.V0");

    /* MS Board (HW Ver.) */
    memset(TempString, 0, sizeof(TempString));
    mmi_asc_to_ucs2((S8*) subMenuData[5], (S8*) "MTK_HW.V0");

    /* Melody Ver. */
    memset(TempString, 0, sizeof(TempString));
    mmi_asc_to_ucs2((S8*) subMenuData[6], (S8*) "Melody.V0");

    /* Serial No. */
    memset(TempString, 0, sizeof(TempString));
    memcpy(TempString, (S8*) gBarCode, MAX_SUB_MENU_SIZE - 2);
    mmi_asc_to_ucs2((S8*) subMenuData[7], (S8*) TempString);

    /* Build Version */
    memset(TempString, 0, sizeof(TempString));
    mmi_asc_to_ucs2((S8*) subMenuData[8], (S8*) "Oct 25 19:08  2003");

    for (i = 0; i < MAX_VER_NUM; i++)
    {
        list[i] = (UI_string_type) subMenuData[i];
    }
#endif /* ( defined(__MTK_TARGET__)) */ 
}


/*****************************************************************************
 * FUNCTION
 *  HightlightFMVersionHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HightlightFMVersionHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryFMVersionMenu, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    change_left_softkey(STR_GLOBAL_OK, 0);
    redraw_left_softkey();
}


/*****************************************************************************
 * FUNCTION
 *  EntryFMVersionMenu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryFMVersionMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[32];
    U16 ItemIcons[32];
    U16 nItems;
    U8 *guiBuffer;
    S32 i;
    UI_string_type PopUpList[32];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_FM_VERSION, NULL, EntryFMVersionMenu, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_FM_VERSION);
    nItems = GetNumOfChild(MENU_ID_FM_VERSION);
    GetSequenceStringIds(MENU_ID_FM_VERSION, ItemList);
    SetParentHandler(MENU_ID_FM_VERSION);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    for (i = 0; i < nItems; i++)
    {
        PopUpList[i] = NULL;
        ItemIcons[i] = (U16) (IMG_GLOBAL_L1 + i);   /* ReturnRequiredNumberImageId(i); */
    }

    FM_PrepareVersionPopUp(PopUpList);

    ShowCategory52Screen(
        STR_ID_FM_VERSION,
        0,
        (U16) STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        nItems,
        ItemList,
        ItemIcons,
        (U8 **) PopUpList,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mtk_itoa
 * DESCRIPTION
 *  
 * PARAMETERS
 *  TempString      [?]         
 *  val             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mtk_itoa(S8 *TempString, S32 val)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (val <= 0)
    {
        TempString[0] = '0';
        return;
    }
    else if (val <= 9)
    {
        TempString[0] = (S8) ('0' + val);
        return;
    }
    else
    {
        S32 v, digits, pos;

        for (v = val, digits = 0; v > 0; v = v / 10)
        {
            digits++;
        }

        for (v = val, pos = digits - 1; digits > 0; v = v / 10)
        {
            TempString[pos] = '0' + v % 10;
            digits--;
            pos--;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  FM_PrepareResourceBinPopUp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  list        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void FM_PrepareResourceBinPopUp(UI_string_type *list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    S8 version_string[] = "version ";

#if defined(__MTK_TARGET__)
    S8 TempString[MAX_SUB_MENU_SIZE];
    S8 *temp;
    extern custpack_nvram_header *custpack_nvram_header_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(subMenuData, 0, sizeof(subMenuData));
    /* Lisen 06052005 */
    /* LangPack Ver# */
    memset(TempString, 0, sizeof(TempString));
    memcpy(TempString, version_string, sizeof(version_string));
    temp = TempString + sizeof(version_string) - 1;
    mtk_itoa((S8*) temp, CURRENT_LANG_PACK_RES_VERSION);
    mmi_asc_to_ucs2((S8*) subMenuData[0], (S8*) TempString);

    /* CustPack Ver# */
    memset(TempString, 0, sizeof(TempString));
    memcpy(TempString, version_string, sizeof(version_string));
    temp = TempString + sizeof(version_string) - 1;

    if (custpack_nvram_header_ptr->version == 0)
    {
        mtk_itoa((S8*) temp, CURRENT_CUSTPACK_RES_VERSION);
    }
    else
    {
        memcpy(temp, custpack_nvram_header_ptr->version, NVRAM_EF_CUSTPACK_VERNO_SIZE);
    }

    mmi_asc_to_ucs2((S8*) subMenuData[1], (S8*) TempString);

    for (i = 0; i < 2; i++)
    {
        list[i] = (UI_string_type) subMenuData[i];
    }

#else /* (defined(__MTK_TARGET__)) */ 
    memset(subMenuData, 0, sizeof(subMenuData));
    /* For PC Simulatior */

    /* LangPack Ver# */
    mmi_asc_to_ucs2((S8*) subMenuData[0], (S8*) "version 0");

    /* CustPack Ver# */
    mmi_asc_to_ucs2((S8*) subMenuData[1], (S8*) "version 0");

    for (i = 0; i < 2; i++)
    {
        list[i] = (UI_string_type) subMenuData[i];
    }
#endif /* ( defined(__MTK_TARGET__)) */ 
}


/*****************************************************************************
 * FUNCTION
 *  HightlightFMResourceBinHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HightlightFMResourceBinHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryFMResourceBinMenuHdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    change_left_softkey(STR_GLOBAL_OK, 0);
    redraw_left_softkey();
}


/*****************************************************************************
 * FUNCTION
 *  EntryFMResourceBinMenuHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryFMResourceBinMenuHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    UI_string_type PopUpList[32];
    U16 ItemList[32];
    U16 ItemIcons[32];
    U16 nItems;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_FM_RESOURCE_BIN, NULL, EntryFMResourceBinMenuHdlr, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_FM_RESOURCE_BIN);
    nItems = GetNumOfChild(MENU_ID_FM_RESOURCE_BIN);
    GetSequenceStringIds(MENU_ID_FM_RESOURCE_BIN, ItemList);
    SetParentHandler(MENU_ID_FM_RESOURCE_BIN);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    for (i = 0; i < nItems; i++)
    {
        PopUpList[i] = NULL;
        ItemIcons[i] = (U16) (IMG_GLOBAL_L1 + i);   /* ReturnRequiredNumberImageId(i); */
    }

    FM_PrepareResourceBinPopUp(PopUpList);

    ShowCategory52Screen(
        STR_ID_FM_RESOURCE_BIN,
        0,
        (U16) NULL,
        0,
        STR_GLOBAL_BACK,
        0,
        nItems,
        ItemList,
        ItemIcons,
        (U8 **) PopUpList,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}

/*****************************************************************
 **  LED
 *****************************************************************/


/*****************************************************************************
 * FUNCTION
 *  HightlightFMLEDHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HightlightFMLEDHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryFMLEDMenuHdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    change_left_softkey(STR_GLOBAL_OK, 0);
    redraw_left_softkey();
}


/*****************************************************************************
 * FUNCTION
 *  HighlightFMOnCertainLED
 * DESCRIPTION
 *  
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightFMOnCertainLED(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gFM_HighlightIdx = (U8) nIndex;
    StopTimer(FM_AUTO_TEST_COMMNON_TIMER);

    if (FM_IS_SET(FM_LEDState, gFM_HighlightIdx))
    {
        change_left_softkey(STR_GLOBAL_OFF, 0);
    }
    else
    {
        change_left_softkey(STR_GLOBAL_ON, 0);
    }
    redraw_left_softkey();

}


/*****************************************************************************
 * FUNCTION
 *  FM_PrepareLEDList
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FM_PrepareLEDList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    S8 buffer[32];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(subMenuData, 0, sizeof(subMenuData));
    memset(subMenuDataPtrs, 0, sizeof(subMenuDataPtrs));

    for (i = 0; i < MAX_FM_LED_MENU_NUM; i++)
    {
        sprintf(buffer, "%s", FM_LED_Menu[i]);
        mmi_asc_to_ucs2((PS8) subMenuData[i], buffer);
        subMenuDataPtrs[i] = subMenuData[i];
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryFMLEDMenuHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryFMLEDMenuHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_FM_LED, NULL, EntryFMLEDMenuHdlr, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_FM_LED);

    RegisterHighlightHandler(HighlightFMOnCertainLED);

    FM_PrepareLEDList();

    ShowCategory6Screen(
        STR_ID_FM_LED,
        0,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        MAX_FM_LED_MENU_NUM,
        (PU8*) subMenuDataPtrs,
        NULL,
        0,
        guiBuffer);
    SetLeftSoftkeyFunction(FM_ExecuteLEDFunc, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  FM_LEDToggleLSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FM_LEDToggleLSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FM_STATE_TOGGLE(FM_LEDState, gFM_HighlightIdx);
    if (FM_IS_SET(FM_LEDState, gFM_HighlightIdx))
    {
        change_left_softkey(STR_GLOBAL_OFF, 0);
    }
    else
    {
        change_left_softkey(STR_GLOBAL_ON, 0);
    }

    redraw_left_softkey();
}


/*****************************************************************************
 * FUNCTION
 *  FM_LEDStepFunc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FM_LEDStepFunc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sequence_counter < LED_LIGHT_LEVEL_MAX)
    {
        switch (gFM_HighlightIdx)
        {
            case MAINLCD_BL:    /* Main LCM BL */
                FM_SetGpioReq(GPIO_DEV_LED_MAINLCD, sequence_counter);
                StartTimer(FM_AUTO_TEST_COMMNON_TIMER, 200, FM_LEDStepFunc);
                break;
        #ifdef __MMI_SUBLCD__
            case SUBLCD_BL:     /* Sub LCM BL */
                FM_SetGpioReq(GPIO_DEV_LED_SUBLCD, sequence_counter);
                StartTimer(FM_AUTO_TEST_COMMNON_TIMER, 200, FM_LEDStepFunc);
                break;
        #endif /* __MMI_SUBLCD__ */ 
            case KEYPAD_LED:    /* Keypad LED */
                FM_SetGpioReq(GPIO_DEV_LED_KEY, sequence_counter);
                StartTimer(FM_AUTO_TEST_COMMNON_TIMER, 200, FM_LEDStepFunc);
                break;

        #ifndef __MMI_HIDE_STATUS_LED_R__
            case STATUSLED_R:   /* Status LED R */
                FM_SetGpioReq(GPIO_DEV_LED_STATUS_1, sequence_counter);
                StartTimer(FM_AUTO_TEST_COMMNON_TIMER, 200, FM_LEDStepFunc);
                break;
        #endif /* __MMI_HIDE_STATUS_LED_R__ */ 

        #ifndef __MMI_HIDE_STATUS_LED_G__
            case STATUSLED_G:   /* Status LED G */
                FM_SetGpioReq(GPIO_DEV_LED_STATUS_2, sequence_counter);
                StartTimer(FM_AUTO_TEST_COMMNON_TIMER, 200, FM_LEDStepFunc);
                break;
        #endif /* __MMI_HIDE_STATUS_LED_G__ */ 

        #ifndef __MMI_HIDE_STATUS_LED_B__
            case STATUSLED_B:   /* Status LED B */
                FM_SetGpioReq(GPIO_DEV_LED_STATUS_3, sequence_counter);
                StartTimer(FM_AUTO_TEST_COMMNON_TIMER, 200, FM_LEDStepFunc);
                break;
        #endif /* __MMI_HIDE_STATUS_LED_B__ */ 

            default:
                sequence_counter = 0;
                StopTimer(FM_AUTO_TEST_COMMNON_TIMER);
                break;
        }

        sequence_counter++;
    }
    else
    {
        sequence_counter = 0;
        StopTimer(FM_AUTO_TEST_COMMNON_TIMER);

        /* Robin 0830 for Cannon+ SRC 3782 */
    #if 0
/* under construction !*/
/* under construction !*/
	#ifndef __MMI_HIDE_STATUS_LED_R__   
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
/* under construction !*/
	#ifndef __MMI_HIDE_STATUS_LED_G__   
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
/* under construction !*/
	#ifndef __MMI_HIDE_STATUS_LED_B__   
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* 0 */ 
    }
}


/*****************************************************************************
 * FUNCTION
 *  FM_ExecuteLEDFunc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FM_ExecuteLEDFunc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FM_LEDToggleLSK();

    sequence_counter = 0;
    StopTimer(FM_AUTO_TEST_COMMNON_TIMER);

    switch (gFM_HighlightIdx)
    {
        case MAINLCD_BL:    /* Main LCM BL */
            if (FM_IS_SET(FM_LEDState, gFM_HighlightIdx))
            {
                FM_LEDStepFunc();
            }
            else
            {
                FM_SetGpioReq(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL0);
            }
            break;
        #ifdef __MMI_SUBLCD__
        case SUBLCD_BL: /* Sub LCM BL */
            if (FM_IS_SET(FM_LEDState, gFM_HighlightIdx))
            {
                FM_LEDStepFunc();
            }
            else
            {
                FM_SetGpioReq(GPIO_DEV_LED_SUBLCD, LED_LIGHT_LEVEL0);
            }
            break;
        #endif /* __MMI_SUBLCD__ */ 
        case KEYPAD_LED:    /* Keypad LED */
            if (FM_IS_SET(FM_LEDState, gFM_HighlightIdx))
            {
                FM_LEDStepFunc();
            }
            else
            {
                FM_SetGpioReq(GPIO_DEV_LED_KEY, LED_LIGHT_LEVEL0);
            }
            break;

        #ifndef __MMI_HIDE_STATUS_LED_R__
        case STATUSLED_R:   /* Status LED R */
            if (FM_IS_SET(FM_LEDState, gFM_HighlightIdx))
            {
                FM_LEDStepFunc();
            }
            else
            {
                FM_SetGpioReq(GPIO_DEV_LED_STATUS_1, LED_LIGHT_LEVEL0);
            }
            break;
        #endif /* __MMI_HIDE_STATUS_LED_R__ */ 

        #ifndef __MMI_HIDE_STATUS_LED_G__
        case STATUSLED_G:   /* Status LED G */
            if (FM_IS_SET(FM_LEDState, gFM_HighlightIdx))
            {
                FM_LEDStepFunc();
            }
            else
            {
                FM_SetGpioReq(GPIO_DEV_LED_STATUS_2, LED_LIGHT_LEVEL0);
            }
            break;
        #endif /* __MMI_HIDE_STATUS_LED_G__ */ 

        #ifndef __MMI_HIDE_STATUS_LED_B__
        case STATUSLED_B:   /* Status LED B */
            if (FM_IS_SET(FM_LEDState, gFM_HighlightIdx))
            {
                FM_LEDStepFunc();
            }
            else
            {
                FM_SetGpioReq(GPIO_DEV_LED_STATUS_3, LED_LIGHT_LEVEL0);
            }
            break;
        #endif /* __MMI_HIDE_STATUS_LED_B__ */ 

        default:
            break;
    }

}

/*****************************************************************
 **  LCD
 *****************************************************************/


/*****************************************************************************
 * FUNCTION
 *  FM_LCDCertainRskHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FM_LCDCertainRskHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackBothLCDHistory();
}


/*****************************************************************************
 * FUNCTION
 *  HightlightFMLCDHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HightlightFMLCDHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryFMLCDMenuHdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    change_left_softkey(STR_GLOBAL_OK, 0);
    redraw_left_softkey();
}


/*****************************************************************************
 * FUNCTION
 *  EntryFMLCDMenuHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void (*SUBLCD_ExitCategoryFunction) (void);
void EntryFMLCDMenuHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[32];
    U16 ItemIcons[32];
    U16 nItems;
    U8 *guiBuffer;
    S32 i;
    UI_string_type PopUpList[32];

#ifdef __MMI_SUBLCD__
    bitmap *saved_graphics_context = current_LCD_device_bitmap;
    UI_character_type ScrText[16];
#endif /* __MMI_SUBLCD__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* EntryNewScreen(SCR_ID_FM_LCD, ExitFMLCDMenuHdlr, EntryFMLCDMenuHdlr, NULL); */
    EntryNewScreen(SCR_ID_FM_LCD, ExitFMLCDMenuHdlr, NULL, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_FM_LCD);
    nItems = GetNumOfChild(MENU_ID_FM_LCD);
    GetSequenceStringIds(MENU_ID_FM_LCD, ItemList);
    SetParentHandler(MENU_ID_FM_LCD);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    for (i = 0; i < nItems; i++)
    {
        PopUpList[i] = NULL;
        ItemIcons[i] = (U16) (IMG_GLOBAL_L1 + i);   /* ReturnRequiredNumberImageId(i); */
    }

    /* Main LCD */
    ShowCategory52Screen(
        STR_ID_FM_LCD,
        0,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        nItems,
        ItemList,
        ItemIcons,
        (U8 **) PopUpList,
        0,
        0,
        guiBuffer);

#ifdef __MMI_SUBLCD__
    /* Sub LCD Show Large 88888 Full Screen */

    /* ShowCategory301Screen( (PU8)"", NULL, NULL); */

    SUBLCD_ExitCategoryFunction();
    UI_set_sub_LCD_graphics_context();
    clear_screen();
    gui_set_font(&MMI_medium_bold_font);
    gui_set_text_border_color(gui_color(0, 0, 0));
    /* gui_set_text_clip(UI_clip_x1,UI_clip_y1,UI_clip_x2,UI_clip_y2); */
    mmi_asc_to_ucs2((S8*) ScrText, (S8*) "SuLCD");
    gui_move_text_cursor(4, 20);
    /* UI_print_bordered_text(ScrText); */
    gui_print_text(ScrText);

    mmi_asc_to_ucs2((S8*) ScrText, (S8*) "TEST");
    gui_move_text_cursor(4, 40);
    gui_print_text(ScrText);
    /* UI_print_bordered_text(ScrText); */

    /* gui_BLT_double_buffer(UI_clip_x1,UI_clip_y1,UI_clip_x2,UI_clip_y2); */
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);

    if (saved_graphics_context == &main_LCD_device_bitmap)
    {
        UI_set_main_LCD_graphics_context();
    }
    else if (saved_graphics_context == &sub_LCD_device_bitmap)
    {
        UI_set_sub_LCD_graphics_context();
    }
#endif /* __MMI_SUBLCD__ */ 

    SetRightSoftkeyFunction(FM_LCDCertainRskHdlr, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  ExitFMLCDMenuHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitFMLCDMenuHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history currHistory;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SUBLCD__
    ShowSubLCDLogoString();
#endif 
    currHistory.scrnID = SCR_ID_FM_LCD;
    currHistory.entryFuncPtr = EntryFMLCDMenuHdlr;
    mmi_ucs2cpy((S8*) currHistory.inputBuffer, (S8*) L"");
    GetCategoryHistory(currHistory.guiBuffer);
    AddHistory(currHistory);

}

/*********************
 **  LCD Auto/Certain
 *********************/


/*****************************************************************************
 * FUNCTION
 *  HightlightFMLCDCertainHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HightlightFMLCDCertainHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(FM_StartCertainLCDTest, KEY_EVENT_UP);
    SetRightSoftkeyFunction(FM_LCDCertainRskHdlr, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  FM_LCDShowColor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void FM_LCDShowColor(S32 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case 0: /* Auto */
            sequence_counter = 0;
            EntryFMColorTest();
            break;
        case 1: /* R */

            gui_lock_double_buffer();
            FM_HandleInitialColor(255, 0, 0);
            gui_unlock_double_buffer();
            gui_BLT_double_buffer(0, 0, MAIN_LCD_device_width - 1, MAIN_LCD_device_height - 1);
            break;

        case 2: /* G */
            gui_lock_double_buffer();
            FM_HandleInitialColor(0, 255, 0);
            gui_unlock_double_buffer();
            gui_BLT_double_buffer(0, 0, MAIN_LCD_device_width - 1, MAIN_LCD_device_height - 1);
            break;

        case 3: /* B */
            gui_lock_double_buffer();
            FM_HandleInitialColor(0, 0, 255);
            gui_unlock_double_buffer();
            gui_BLT_double_buffer(0, 0, MAIN_LCD_device_width - 1, MAIN_LCD_device_height - 1);
            break;

        case 4: /* W */
            gui_lock_double_buffer();
            FM_HandleInitialColor(255, 255, 255);
            gui_unlock_double_buffer();
            gui_BLT_double_buffer(0, 0, MAIN_LCD_device_width - 1, MAIN_LCD_device_height - 1);
            break;

            /* Lisen 05312005 */
        case 5: /* Black */
            gui_lock_double_buffer();
            FM_HandleInitialColor(0, 0, 0);
            gui_unlock_double_buffer();
            gui_BLT_double_buffer(0, 0, MAIN_LCD_device_width - 1, MAIN_LCD_device_height - 1);
            break;

        default:
            sequence_counter = 0;
            EntryFMColorTest();
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  FM_StartCertainLCDTest
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FM_StartCertainLCDTest(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    type = GetHighlightedItem();

    if (type > 0)
    {
        EntryNewScreen(GLOBAL_SCR_DUMMY, NULL, NULL, NULL);
        ShowCategory7Screen(0, 0, STR_GLOBAL_OK, 0, 0, 0, NULL, NULL);
        SetLeftSoftkeyFunction(ExitFMColorSetChange, KEY_EVENT_UP);
        SetRightSoftkeyFunction(ExitFMColorSetChange, KEY_EVENT_UP);
        SetKeyHandler(ExitFMColorSetChange, KEY_END, KEY_EVENT_UP);
    }

    FM_LCDShowColor(type);

}


/*****************************************************************************
 * FUNCTION
 *  FM_HandleInitialColor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  color_r     [IN]        
 *  color_g     [IN]        
 *  color_b     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void FM_HandleInitialColor(U8 color_r, U8 color_g, U8 color_b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    stFontAttribute debug_print_font = {0, 0, 0, SMALL_FONT, 0, 0};
    color c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    c = gui_color(color_r, color_g, color_b);
    UI_set_clip(0, 0, UI_device_width, UI_device_height);
    gdi_layer_set_source_key(FALSE, 0);
    UI_fill_rectangle(0, 0, UI_device_width, UI_device_height, c);
    UI_reset_text_clip();
    UI_set_font(&debug_print_font);
    c = gui_color(0, 0, 0);
    UI_set_text_color(c);
}


/*****************************************************************************
 * FUNCTION
 *  FM_HandleColorSetChange
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FM_HandleColorSetChange(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (sequence_counter)
    {
        case 0:
            gui_lock_double_buffer();
            sequence_counter++;
            FM_HandleInitialColor(255, 0, 0);
            StartTimer(FM_LCD_COLOR_CHANGE_TIMER, 1000, FM_HandleColorSetChange);
            gui_unlock_double_buffer();
            gui_BLT_double_buffer(0, 0, MAIN_LCD_device_width - 1, MAIN_LCD_device_height - 1);
            break;

        case 1:
            gui_lock_double_buffer();
            sequence_counter++;
            FM_HandleInitialColor(0, 255, 0);
            StartTimer(FM_LCD_COLOR_CHANGE_TIMER, 1000, FM_HandleColorSetChange);
            gui_unlock_double_buffer();
            gui_BLT_double_buffer(0, 0, MAIN_LCD_device_width - 1, MAIN_LCD_device_height - 1);
            break;

        case 2:
            gui_lock_double_buffer();
            sequence_counter++;
            FM_HandleInitialColor(0, 0, 255);
            StartTimer(FM_LCD_COLOR_CHANGE_TIMER, 1000, FM_HandleColorSetChange);
            gui_unlock_double_buffer();
            gui_BLT_double_buffer(0, 0, MAIN_LCD_device_width - 1, MAIN_LCD_device_height - 1);
            break;

        case 3:
            gui_lock_double_buffer();
            sequence_counter++;
            FM_HandleInitialColor(255, 255, 255);
            StartTimer(FM_LCD_COLOR_CHANGE_TIMER, 1000, FM_HandleColorSetChange);
            gui_unlock_double_buffer();
            gui_BLT_double_buffer(0, 0, MAIN_LCD_device_width - 1, MAIN_LCD_device_height - 1);
            break;

            /* Lisen 05312005 */
        case 4:
            gui_lock_double_buffer();
            sequence_counter++;
            FM_HandleInitialColor(0, 0, 0);
            StartTimer(FM_LCD_COLOR_CHANGE_TIMER, 1000, FM_HandleColorSetChange);
            gui_unlock_double_buffer();
            gui_BLT_double_buffer(0, 0, MAIN_LCD_device_width - 1, MAIN_LCD_device_height - 1);
            break;

        default:
            sequence_counter = 0;
            StopTimer(FM_LCD_COLOR_CHANGE_TIMER);

            EntryNewScreen(GLOBAL_SCR_DUMMY, NULL, NULL, NULL);

            if (autoTestMode == 0)  /* Display the screen if not in autotest mode */
            {
                mmi_asc_to_ucs2(EMFMUnicodeDisplayBuf, (S8*) "Pass");
                ShowCategory7Screen(0, 0, STR_GLOBAL_OK, 0, 0, 0, (U8*) EMFMUnicodeDisplayBuf, NULL);
                SetKeyHandler(ExitFMColorSetChange, KEY_LSK, KEY_EVENT_UP);
            }
            else
            {
                FM_Autotest_test_done_USC2string(Tests[FM_AUTOTEST_LCD].name);
                ShowCategory7Screen(
                    STR_ID_FM_AUTO_TEST_RESULT,
                    IMG_ID_FM_AUTO_TEST_ROOT,
                    STR_ID_FM_AUTO_TEST_PASS,
                    IMG_GLOBAL_OK,
                    STR_ID_FM_AUTO_TEST_FAIL,
                    IMG_GLOBAL_BACK,
                    (PU8) EMFMUnicodeDisplayBuf,
                    NULL);

                FM_Autotest_set_key_handlers();
            }
            return;
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  ExitFMColorSetChange
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitFMColorSetChange(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sequence_counter = 0;
    StopTimer(FM_LCD_COLOR_CHANGE_TIMER);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  EntryFMColorTest
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryFMColorTest(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(GLOBAL_SCR_DUMMY, NULL, NULL, NULL);

    SetKeyHandler(ExitFMColorSetChange, KEY_END, KEY_EVENT_UP);
    FM_HandleColorSetChange();
    /* StartTimer(CM_NOTIFYDURATION_TIMER, 1000, FM_HandleColorSetChange); */
}

/*****************************************************************
 **  LCD Contrast
 *****************************************************************/


/*****************************************************************************
 * FUNCTION
 *  HightlightFMLCDContrastHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HightlightFMLCDContrastHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryFMLCDContrastMenuHdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    change_left_softkey(STR_GLOBAL_OK, 0);
    redraw_left_softkey();
}


/*****************************************************************************
 * FUNCTION
 *  EntryFMLCDContrastMenuHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryFMLCDContrastMenuHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[32];
    U16 ItemIcons[32];
    U16 nItems;
    U8 *guiBuffer;
    S32 i;
    UI_string_type PopUpList[32];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_FM_LCD_CONTRAST, NULL, EntryFMLCDContrastMenuHdlr, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_FM_LCD_CONTRAST);
    nItems = GetNumOfChild(MENU_ID_FM_LCD_CONTRAST);
    GetSequenceStringIds(MENU_ID_FM_LCD_CONTRAST, ItemList);
    SetParentHandler(MENU_ID_FM_LCD_CONTRAST);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    for (i = 0; i < nItems; i++)
    {
        PopUpList[i] = NULL;
        ItemIcons[i] = (U16) (IMG_GLOBAL_L1 + i);   /* ReturnRequiredNumberImageId(i); */
    }

    ShowCategory52Screen(
        STR_ID_FM_LCD_CONTRAST,
        0,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        nItems,
        ItemList,
        ItemIcons,
        (U8 **) PopUpList,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}

/*************************/
/* Main/Sub LCD Contrast */
/*************************/


/*****************************************************************************
 * FUNCTION
 *  HightlightFMLCDContrastMainHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HightlightFMLCDContrastMainHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    LCDType = 0;
    SetLeftSoftkeyFunction(EntryFMLCDContrastSliderHdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HightlightFMLCDContrastSubHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HightlightFMLCDContrastSubHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    LCDType = 1;

#ifdef __MMI_SUBLCD__
    SetLeftSoftkeyFunction(EntryFMLCDContrastSliderHdlr, KEY_EVENT_UP);
#else 
    SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
#endif 

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  FM_ShowLCDContrastScreen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FM_ShowLCDContrastScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type text1[32];
    UI_character_type text2[32];
    U8 u8text[32];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (LCDType == 0)
    {
        /* Main LCD */
        sprintf((S8*) u8text, "%d/%d", currentContrast, MAX_CONTRAST_NUM);
    #ifdef __ASCII
        strcpy((S8*) text1, (S8*) u8text);
    #else 
        mmi_asc_to_ucs2((S8*) text1, (S8*) u8text);
    #endif 

        ShowCategory205Screen(STR_GLOBAL_OK, 0, STR_GLOBAL_BACK, 0, text1, IMG_ID_FM_CONTRAST, NULL);
    }
    else
    {
        /* Sub LCD */
        sprintf((S8*) u8text, "8888\n%d/%d", currentContrast, MAX_CONTRAST_NUM);
    #ifdef __ASCII
        strcpy((S8*) text1, (S8*) u8text);
    #else /* __ASCII */ 
        mmi_asc_to_ucs2((S8*) text1, (S8*) u8text);
        mmi_asc_to_ucs2((S8*) text2, (S8*) "Adjusting SubLCD");
    #endif /* __ASCII */ 
        /* ShowCategory205Screen( FM_OK,0,NULL,0, text2, NULL, NULL); */
        ShowCategory301Screen((PU8) text1, (U16) NULL, NULL);
    #ifdef __MMI_SUBLCD__
        ShowCategory7Screen(0, 0, STR_GLOBAL_OK, 0, STR_GLOBAL_BACK, 0, (U8*) text2, NULL);
    #endif 
    }

    SetLeftSoftkeyFunction(GoBackBothLCDHistory, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackBothLCDHistory, KEY_EVENT_UP);
    SetKeyHandler(FM_LCDContrastLevelUp, KEY_UP_ARROW, KEY_EVENT_UP);
    SetKeyHandler(FM_LCDContrastLevelDown, KEY_DOWN_ARROW, KEY_EVENT_UP);

#ifdef __MMI_FOURWAYS_KEY_DISABLE__
    SetKeyHandler(FM_LCDContrastLevelUp, KEY_VOL_UP, KEY_EVENT_UP);
    SetKeyHandler(FM_LCDContrastLevelDown, KEY_VOL_DOWN, KEY_EVENT_UP);
#endif /* __MMI_FOURWAYS_KEY_DISABLE__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  EntryFMLCDContrastSliderHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryFMLCDContrastSliderHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_SETTING_CONTRAST_LEVEL, &currentContrast, DS_BYTE, &error);
    EntryNewScreen(GLOBAL_SCR_DUMMY, NULL, NULL, NULL);
#ifdef __MMI_SUBLCD__
    ExecSubLCDCurrExitHandler();
#endif 

    if (LCDType == 0)
    {
        PhnsetMainLCDContrast((U8) currentContrast);
    }
    else
    {
        PhnsetSubLCDContrast((U8) currentContrast);
    }

    SetRightSoftkeyFunction(GoBackBothLCDHistory, KEY_EVENT_UP);
    FM_ShowLCDContrastScreen();

}


/*****************************************************************************
 * FUNCTION
 *  FM_LCDContrastLevelUp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FM_LCDContrastLevelUp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (currentContrast < MAX_CONTRAST_NUM - CONTRAST_STEP)
    {
        currentContrast += CONTRAST_STEP;
    }
    else
    {
        currentContrast = MAX_CONTRAST_NUM;
    }

    if (LCDType == 0)
    {
        PhnsetMainLCDContrast((U8) currentContrast);
    }
    else
    {
        PhnsetSubLCDContrast((U8) currentContrast);
    }

    FM_ShowLCDContrastScreen();
    SetLeftSoftkeyFunction(FM_LCDSetContrastLevel, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackBothLCDHistory, KEY_EVENT_UP);
    SetKeyHandler(FM_LCDContrastLevelUp, KEY_UP_ARROW, KEY_EVENT_UP);
    SetKeyHandler(FM_LCDContrastLevelDown, KEY_DOWN_ARROW, KEY_EVENT_UP);

#ifdef __MMI_FOURWAYS_KEY_DISABLE__
    SetKeyHandler(FM_LCDContrastLevelUp, KEY_VOL_UP, KEY_EVENT_UP);
    SetKeyHandler(FM_LCDContrastLevelDown, KEY_VOL_DOWN, KEY_EVENT_UP);
#endif /* __MMI_FOURWAYS_KEY_DISABLE__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  FM_LCDContrastLevelDown
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FM_LCDContrastLevelDown(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (currentContrast > MIN_CONTRAST_NUM + CONTRAST_STEP)
    {
        currentContrast -= CONTRAST_STEP;
    }
    else
    {
        currentContrast = MIN_CONTRAST_NUM;
    }

    if (LCDType == 0)
    {
        PhnsetMainLCDContrast((U8) currentContrast);
    }
    else
    {
        PhnsetSubLCDContrast((U8) currentContrast);
    }

    FM_ShowLCDContrastScreen();
    SetLeftSoftkeyFunction(FM_LCDSetContrastLevel, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackBothLCDHistory, KEY_EVENT_UP);
    SetKeyHandler(FM_LCDContrastLevelUp, KEY_UP_ARROW, KEY_EVENT_UP);
    SetKeyHandler(FM_LCDContrastLevelDown, KEY_DOWN_ARROW, KEY_EVENT_UP);

#ifdef __MMI_FOURWAYS_KEY_DISABLE__
    SetKeyHandler(FM_LCDContrastLevelUp, KEY_VOL_UP, KEY_EVENT_UP);
    SetKeyHandler(FM_LCDContrastLevelDown, KEY_VOL_DOWN, KEY_EVENT_UP);
#endif /* __MMI_FOURWAYS_KEY_DISABLE__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  FM_LCDSetContrastLevel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FM_LCDSetContrastLevel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteValue(NVRAM_SETTING_CONTRAST_LEVEL, &currentContrast, DS_BYTE, &error);
    WriteValue(RESTORE_DEFAULT_CONTRAST_LEVEL, &currentContrast, DS_BYTE, &error);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  EntryFMLCDContrastSubHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryFMLCDContrastSubHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  ExitFMLCDContrastSubHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitFMLCDContrastSubHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}

/*****************************************************************
 **  Keypad
 *****************************************************************/


/*****************************************************************************
 * FUNCTION
 *  HightlightFMKeypadHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HightlightFMKeypadHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryFMKeypadTest, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    change_left_softkey(STR_GLOBAL_OK, 0);
    redraw_left_softkey();
}


/*****************************************************************************
 * FUNCTION
 *  FM_IsInKeypadTest
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
BOOL FM_IsInKeypadTest(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (InkeyTestingScreen == 1)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}

/* MTK added by JL for 031115 keypad test out of window display at other screen */


/*****************************************************************************
 * FUNCTION
 *  FM_HandleKeypadEndout
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FM_HandleKeypadEndout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(GLOBAL_SCR_DUMMY, NULL, NULL, NULL);
    GoBackHistory();
}

/* MTK end */


/*****************************************************************************
 * FUNCTION
 *  EntryFMKeypadTest
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryFMKeypadTest(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 IdleScreenDigits[] = 
	{
		KEY_VOL_UP_VALUE,       KEY_VOL_DOWN_VALUE,     KEY_CAMERA,                    KEY_NONE_VALUE,
		KEY_LSK_VALUE/*KEY_SEND1*/,                   KEY_SEND2,                       KEY_END,                         KEY_ENTER,
		KEY_UP_ARROW_VALUE, KEY_DOWN_ARROW_VALUE, KEY_LEFT_ARROW_VALUE, KEY_RIGHT_ARROW_VALUE,
		KEY_NONE_VALUE,       KEY_RSK_VALUE,                  KEY_EXTRA_1,                 KEY_EXTRA_2,
		KEY_1,                           KEY_2,                                KEY_3,                              KEY_STAR,  
		KEY_4,                           KEY_5,                                KEY_6,                              KEY_0, 
		KEY_7,                           KEY_8,                                KEY_9,                              KEY_POUND,
		KEY_NONE_VALUE,       KEY_NONE_VALUE,            KEY_NONE_VALUE,          KEY_NONE_VALUE
	};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(GLOBAL_SCR_DUMMY, NULL, NULL, NULL);
    SetGroupKeyHandler(FM_HandleKeypadTest, (U16*) IdleScreenDigits, PHYSICAL_KEYs /* KEYNUMs */ , KEY_EVENT_UP);
    SetGroupKeyHandler(
        FM_HandleKeypadTestKeyDown,
        (U16*) IdleScreenDigits,
        PHYSICAL_KEYs /* KEYNUMs */ ,
        KEY_EVENT_DOWN);

    //MTK added by JL for 031115 keypad test out of window display at other screen
    //SetKeyHandler( GoBackHistory, KEY_END, KEY_EVENT_LONG_PRESS);
    SetKeyHandler(FM_HandleKeypadEndout, KEY_END, KEY_EVENT_LONG_PRESS);
    FM_KeypadInit();
    InkeyTestingScreen = 1;
}


/*****************************************************************************
 * FUNCTION
 *  FM_KeypadCheck
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FM_KeypadCheck(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 count = 0, y = 40, index, alignment_width = 0, alignment_height = 0;
    stFontAttribute fontInfo;
    S8 temp1[50], temp2[100];
    bitmap *saved_graphics_context = current_LCD_device_bitmap;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fontInfo.bold = 0;
    fontInfo.italic = 0;
    fontInfo.underline = 0;

    fontInfo.size = 9;  /* (size 8..15 FOR type 2..5 ) & (size 9...15 FOR type 1 ) */
    fontInfo.type = 1;  /* 1...5 */

    gui_lock_double_buffer();

    FM_HandleInitialColor(255, 255, 255);
    /* gui_move_text_cursor(0,0); */
    UI_set_main_LCD_graphics_context();

    for (count = 0; count < LINE_NUM; count++)
    {
        memset(temp1, 0, sizeof(temp1));
        for (index = 0; index < COLUMN_NUM; index++)
        {
            if (keypad_status[count][index] != KEY_HIDE)
            {
                strcat(temp1, (S8*) keypad_layout[count][index]);
            }
            else
            {
                strcat(temp1, (S8*) BLANK);
            }
        }

        mmi_asc_to_ucs2(temp2, (S8*) temp1);

        /* alignment_width = (S16)Get_StringWidth((U8*)temp2); */
        Get_StringWidthHeight((U8*) temp2, (S32*) & alignment_width, (S32*) & alignment_height);

        /* gui_set_font(&fontInfo); */
        gui_set_font(&MMI_small_font);
        gui_set_text_clip(UI_clip_x1, UI_clip_y1, UI_clip_x2, UI_clip_y2);
        gui_set_text_color(gui_color(0, 0, 0));
        gui_move_text_cursor((MAIN_LCD_device_width - alignment_width) / 2, y);
        gui_print_text((UI_string_type) temp2);
        y += 10;
        //ShowString((128-alignment_width)/2, y, fontInfo, 0 , (PU8)temp2, sizeof(temp2)/2);      
        //y += 10;
    }

    /* RollBack to original LCD */
    if (saved_graphics_context == &main_LCD_device_bitmap)
    {
        UI_set_main_LCD_graphics_context();
    }
    else if (saved_graphics_context == &sub_LCD_device_bitmap)
    {
        UI_set_sub_LCD_graphics_context();
    }

    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, MAIN_LCD_device_width - 1, MAIN_LCD_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  FM_KeypadInit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FM_KeypadInit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < LINE_NUM; i++)
    {
        for (j = 0; j < COLUMN_NUM; j++)
        {
            if (keypad_value[i * COLUMN_NUM + j] == 0xFF)
            {
                keypad_status[i][j] = KEY_NA;   /* FOR blank dispaly */
            }
            else
            {
                keypad_status[i][j] = KEY_SHOW;
            }
        }
    }

    FM_KeypadCheck();
}


/*****************************************************************************
 * FUNCTION
 *  FM_KeypadSet
 * DESCRIPTION
 *  
 * PARAMETERS
 *  key_code        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void FM_KeypadSet(U16 key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    U8 nKeys = sizeof(keypad_value) / sizeof(keypad_value[0]);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = nKeys - 1; i >= 0 && i < nKeys; i--)
    {
        if (keypad_value[i] == key_code)
        {
            if (keypad_status[i / COLUMN_NUM][i % COLUMN_NUM] != KEY_HIDE)
            {
                keypad_status[i / COLUMN_NUM][i % COLUMN_NUM] = KEY_HIDE;
                break;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  FM_KeypadPass
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 FM_KeypadPass(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < LINE_NUM; i++)
    {
        for (j = 0; j < COLUMN_NUM; j++)
        {
            if (keypad_status[i][j] == KEY_SHOW)
            {
                return FALSE;
            }
        }
    }
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  FM_HandleKeypadTestKeyDown
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FM_HandleKeypadTestKeyDown(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 Keycode, Keytype;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetkeyInfo(&Keycode, &Keytype);
    FM_SendKeyEventReq((U8) Keytype, (U8) Keycode);
}


/*****************************************************************************
 * FUNCTION
 *  FM_HandleKeypadTest
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FM_HandleKeypadTest(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 Keycode, Keytype;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetkeyInfo(&Keycode, &Keytype);
    FM_SendKeyEventReq((U8) Keytype, (U8) Keycode);

    FM_KeypadSet(Keycode);

    FM_KeypadCheck();

    if (FM_KeypadPass() == TRUE)
    {
        EntryNewScreen(GLOBAL_SCR_DUMMY, NULL, NULL, NULL);

        if (autoTestMode == 0)
        {
            mmi_asc_to_ucs2(EMFMUnicodeDisplayBuf, (S8*) "Pass");
            ShowCategory7Screen(0, 0, STR_GLOBAL_OK, 0, 0, 0, (U8*) EMFMUnicodeDisplayBuf, NULL);

            InkeyTestingScreen = 0;
            GoBackHistory();
        }
        else
        {
            FM_Autotest_test_done_USC2string(Tests[FM_AUTOTEST_KEYPAD].name);
            ShowCategory7Screen(
                STR_ID_FM_AUTO_TEST_ROOT,
                IMG_ID_FM_AUTO_TEST_ROOT,
                STR_ID_FM_AUTO_TEST_PASS,
                IMG_GLOBAL_OK,
                STR_ID_FM_AUTO_TEST_FAIL,
                IMG_GLOBAL_BACK,
                (PU8) EMFMUnicodeDisplayBuf,
                NULL);

            FM_Autotest_set_key_handlers();
        }
    }

}

/*****************************************************************
 **  LoudSpeak
 *****************************************************************/


/*****************************************************************************
 * FUNCTION
 *  HightlightFMLoudSpkHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HightlightFMLoudSpkHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryFMLoudSpkHdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    if (LoudSpkTestOn)
    {
        change_left_softkey(STR_GLOBAL_OFF, 0);
    }
    else
    {
        change_left_softkey(STR_GLOBAL_ON, 0);
    }

    redraw_left_softkey();

}


/*****************************************************************************
 * FUNCTION
 *  EntryFMLoudSpkHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryFMLoudSpkHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!LoudSpkTestOn)
    {
        LoudSpkTestOn = TRUE;

        /* set audio mode to LoudSp */
        /* custom_em_set_mode(AUD_MODE_LOUDSPK); */
        FM_SendSetAudioModeReq(AUD_MODE_LOUDSPK);
        /* play 1K tone */
        TONE_SetOutputVolume(255, 0);
        TONE_Play((const L1SP_Tones*)test_tone);
        change_left_softkey(STR_GLOBAL_OFF, 0);
    }
    else
    {
        LoudSpkTestOn = FALSE;

        /* set audio mode to Normal */
        /* custom_em_set_mode(AUD_MODE_NORMAL); */
        FM_SendSetAudioModeReq(AUD_MODE_NORMAL);
        /* stop 1K tone */
        TONE_Stop();

        change_left_softkey(STR_GLOBAL_ON, 0);
    }
    redraw_left_softkey();

}

/*****************************************************************
 **  Echo Loop
 *****************************************************************/


/*****************************************************************************
 * FUNCTION
 *  HightlightFMEchoLoopHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HightlightFMEchoLoopHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryFMEchoLoopHdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    if (EchoLoopTestOn)
    {
        change_left_softkey(STR_GLOBAL_OFF, 0);
    }
    else
    {
        change_left_softkey(STR_GLOBAL_ON, 0);
    }
    redraw_left_softkey();
}


/*****************************************************************************
 * FUNCTION
 *  EntryFMEchoLoopHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryFMEchoLoopHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FM_RestoreAudio();
    FM_RESET_AUDIO_STATE(FM_AUDIO_TEST_STAT_ECHOLOOP);

    if (!EchoLoopTestOn)
    {
        EchoLoopTestOn = TRUE;

        /* set audio mode to Normal */
        /* custom_em_set_mode(AUD_MODE_NORMAL); */
        FM_SendSetAudioModeReq(AUD_MODE_NORMAL);
        /* open loopback */
        kal_sleep_task(kal_milli_secs_to_ticks(200));
        custom_em_set_loopback(TRUE);

        change_left_softkey(STR_GLOBAL_OFF, 0);
    }
    else
    {
        EchoLoopTestOn = FALSE;

        /* set audio mode to Normal */
        /* custom_em_set_mode(AUD_MODE_NORMAL); */
        FM_SendSetAudioModeReq(AUD_MODE_NORMAL);
        /* open loopback */
        kal_sleep_task(kal_milli_secs_to_ticks(200));
        custom_em_set_loopback(FALSE);

        change_left_softkey(STR_GLOBAL_ON, 0);

    }
    redraw_left_softkey();
}

/*****************************************************************
 **  Vibrator
 *****************************************************************/


/*****************************************************************************
 * FUNCTION
 *  HightlightFMVibratorHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HightlightFMVibratorHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vib_status)
    {
        SetLeftSoftkeyFunction(FM_StopVibrator, KEY_EVENT_UP);
        change_left_softkey(STR_GLOBAL_OFF, 0);
    }
    else
    {
        SetLeftSoftkeyFunction(EntryFMVibratorHdlr, KEY_EVENT_UP);
        change_left_softkey(STR_GLOBAL_ON, 0);
    }

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    redraw_left_softkey();
}


/*****************************************************************************
 * FUNCTION
 *  EntryFMVibratorHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryFMVibratorHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vib = 1;
    FM_SetGpioReq(GPIO_DEV_VIBRATOR, VIBRATOR_ON);
    SetLeftSoftkeyFunction(FM_StopVibrator, KEY_EVENT_UP);
    change_left_softkey(STR_GLOBAL_OFF, 0);
    redraw_left_softkey();
    StartTimer(FM_VIB_TIMER, 1000, FM_HandleVibratorRsp);
}


/*****************************************************************************
 * FUNCTION
 *  FM_HandleVibratorRsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FM_HandleVibratorRsp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vib_status = KAL_TRUE;
    if (vib == 1)
    {
        vib = 0;
        FM_SetGpioReq(GPIO_DEV_VIBRATOR, VIBRATOR_OFF);
    }
    else
    {
        vib = 1;
        FM_SetGpioReq(GPIO_DEV_VIBRATOR, VIBRATOR_ON);
    }

    StartTimer(FM_VIB_TIMER, 1000, FM_HandleVibratorRsp);
}


/*****************************************************************************
 * FUNCTION
 *  FM_StopVibrator
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FM_StopVibrator(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vib_status = KAL_FALSE;
    StopTimer(FM_VIB_TIMER);
    FM_SetGpioReq(GPIO_DEV_VIBRATOR, VIBRATOR_OFF);
    SetLeftSoftkeyFunction(EntryFMVibratorHdlr, KEY_EVENT_UP);
    change_left_softkey(STR_GLOBAL_ON, 0);
    redraw_left_softkey();
}

/*****************************************************************
 **  ADC
 *****************************************************************/


/*****************************************************************************
 * FUNCTION
 *  HightlightFMADCHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HightlightFMADCHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryFMADCMenu, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    change_left_softkey(STR_GLOBAL_OK, 0);
    redraw_left_softkey();

}


/*****************************************************************************
 * FUNCTION
 *  FM_PrepareADCList
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FM_PrepareADCList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i = 0;
    S8 buffer[32];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gFM_MenuItemNum = 0;
    memset(subMenuData, 0, sizeof(subMenuData));
    memset(subMenuDataPtrs, 0, sizeof(subMenuDataPtrs));
    for (i = 0; i < ADC_LABELID_MAX; i++)
    {
        if (adc_map_tbl[i].vaild == GPIO_VAILD)
        {
            sprintf(buffer, "%s %d.%d", adc_map_tbl[i].netname, 0, 0);
            mmi_asc_to_ucs2((PS8) subMenuData[gFM_MenuItemNum], buffer);
            subMenuDataPtrs[gFM_MenuItemNum] = subMenuData[gFM_MenuItemNum];
            gFM_MenuItemNum++;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryFMADCMenu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryFMADCMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_FM_ADC, ExitFMADCMenu, NULL, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_FM_ADC);

#ifdef __MTK_TARGET__
    FM_PrepareADCList();
#endif 

    if (gFM_MenuItemNum < 1)
    {
        gFM_MenuItemNum = 0;
    }

    ShowCategory6Screen(
        STR_ID_FM_ADC,
        0,
        (U16) NULL,
        0,
        STR_GLOBAL_BACK,
        0,
        gFM_MenuItemNum,
        (PU8*) subMenuDataPtrs,
        NULL,
        0,
        guiBuffer);

    SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
    SetRightSoftkeyFunction(FM_StopADCMenu, KEY_EVENT_UP);

    SetProtocolEventHandler(FM_UpdateADCHdlr, MSG_ID_MMI_EQ_ADC_ALL_CHANNEL_IND);
    /* SetProtocolEventHandler( NULL, PRT_BATTERY_STATUS_IND ); */
    SetProtocolEventHandler(EMFMBatteryStatusMsgHandler, PRT_BATTERY_STATUS_IND);
    FM_SendADCStartReq();

}


/*****************************************************************************
 * FUNCTION
 *  FM_UpdateADCHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void FM_UpdateADCHdlr(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 i = 0, j = 0;
    S8 buffer[32];
    double adc_value;
    mmi_eq_adc_all_channel_ind_struct *adc_struct = (mmi_eq_adc_all_channel_ind_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i=0; i<ADC_LABELID_MAX; i++)
    {
        if (adc_map_tbl[i].vaild == GPIO_VAILD)
        {
            if (adc_map_tbl[i].port == ADC_VBAT)
            {
                adc_value = (double)adc_struct->vbat;
                sprintf(buffer, "%s %4.2f V", adc_map_tbl[i].netname, adc_value / 1000000.0);

                mmi_asc_to_ucs2((PS8) subMenuData[j], buffer);
                subMenuDataPtrs[j] = subMenuData[j];
                j++;
            }
            else if (adc_map_tbl[i].port == ADC_VBATTMP)
            {
                adc_value = (double)adc_struct->bat_temp;
                sprintf(buffer, "%s %4.2f C", adc_map_tbl[i].netname, adc_value / 1000.0);

                mmi_asc_to_ucs2((PS8) subMenuData[j], buffer);
                subMenuDataPtrs[j] = subMenuData[j];
                j++;
            }
            else if (adc_map_tbl[i].port == ADC_ACCESSORYID)
            {
                adc_value = (double)adc_struct->vaux;
                sprintf(buffer, "%s %4.2f V", adc_map_tbl[i].netname, adc_value / 1000000.0);

                mmi_asc_to_ucs2((PS8) subMenuData[j], buffer);
                subMenuDataPtrs[j] = subMenuData[j];
                j++;
            }
            else if (adc_map_tbl[i].port == ADC_VISENSE)
            {
                adc_value = (double)adc_struct->charge_current;
                if ((adc_struct->charge_current) & 0x80000000)
                {
                    sprintf(buffer, "%s n/a", adc_map_tbl[i].netname);
                }
                else
                {
                    sprintf(buffer, "%s %4.2f A", adc_map_tbl[i].netname, (adc_value) / 1000000.0);
                } 
                mmi_asc_to_ucs2((PS8) subMenuData[j], buffer);
                subMenuDataPtrs[j] = subMenuData[j];
                j++;
            }
            else if (adc_map_tbl[i].port == ADC_VCHARGER)
            {
                adc_value = (double)adc_struct->vcharge;
                sprintf(buffer, "%s %4.2f V", adc_map_tbl[i].netname, adc_value / 1000000.0);

                mmi_asc_to_ucs2((PS8) subMenuData[j], buffer);
                subMenuDataPtrs[j] = subMenuData[j];
                j++;
            }
        }
    }
    

#if 0    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* if 0 */    

    ShowCategory6Screen(
        STR_ID_FM_ADC,
        0,
        (U16) NULL,
        0,
        STR_GLOBAL_BACK,
        0,
        gFM_MenuItemNum,
        (PU8*) subMenuDataPtrs,
        NULL,
        0,
        NULL);

    SetRightSoftkeyFunction(FM_StopADCMenu, KEY_EVENT_UP);
    ReplaceNewScreenHandler(SCR_ID_FM_ADC, ExitFMADCMenu, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  FM_StopADCMenu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FM_StopADCMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(NULL, MSG_ID_MMI_EQ_ADC_ALL_CHANNEL_IND);
    SetProtocolEventHandler(BatteryStatusRsp, PRT_BATTERY_STATUS_IND);
    FM_SendADCStopReq();
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  ExitFMADCMenu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitFMADCMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(NULL, MSG_ID_MMI_EQ_ADC_ALL_CHANNEL_IND);
    SetProtocolEventHandler(BatteryStatusRsp, PRT_BATTERY_STATUS_IND);
    FM_SendADCStopReq();
}

/*****************************************************************
 **  Receiver
 *****************************************************************/


/*****************************************************************************
 * FUNCTION
 *  HightlightFMReceiverHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HightlightFMReceiverHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryFMReceiverHdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    if (ReceiverTestOn)
    {
        change_left_softkey(STR_GLOBAL_OFF, 0);
    }
    else
    {
        change_left_softkey(STR_GLOBAL_ON, 0);
    }
    redraw_left_softkey();
}


/*****************************************************************************
 * FUNCTION
 *  EntryFMReceiverHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryFMReceiverHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FM_RestoreAudio();
    FM_RESET_AUDIO_STATE(FM_AUDIO_TEST_STAT_RECEIVER);

    if (!ReceiverTestOn)
    {
        ReceiverTestOn = TRUE;

        /* set audio mode to Normal */
        /* custom_em_set_mode(AUD_MODE_NORMAL); */
        /* play 1K tone */
        kal_sleep_task(kal_milli_secs_to_ticks(200));
        TONE_SetOutputVolume(255, 0);
        TONE_Play((const L1SP_Tones*)test_tone);

        change_left_softkey(STR_GLOBAL_OFF, 0);

    }
    else
    {
        ReceiverTestOn = FALSE;
        /* set audio mode to Normal */
        /* custom_em_set_mode(AUD_MODE_NORMAL); */
        /* stop 1K tone */
        TONE_Stop();
        change_left_softkey(STR_GLOBAL_ON, 0);

    }

    redraw_left_softkey();
}

/*****************************************************************
 **  Headset
 *****************************************************************/


/*****************************************************************************
 * FUNCTION
 *  HightlightFMHeadsetHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HightlightFMHeadsetHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryFMHeadsetHdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    if (HeadsetTestOn)
    {
        change_left_softkey(STR_GLOBAL_OFF, 0);
    }
    else
    {
        change_left_softkey(STR_GLOBAL_ON, 0);
    }
    redraw_left_softkey();
}


/*****************************************************************************
 * FUNCTION
 *  EntryFMHeadsetHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryFMHeadsetHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!HeadsetTestOn)
    {
        HeadsetTestOn = TRUE;
        /* set audio mode to Headset */
        /* custom_em_set_mode(AUD_MODE_HEADSET); */
        FM_SendSetAudioModeReq(AUD_MODE_HEADSET);
        /* open loopback */
        kal_sleep_task(kal_milli_secs_to_ticks(200));
        custom_em_set_loopback(TRUE);
        change_left_softkey(STR_GLOBAL_OFF, 0);

    }
    else
    {
        HeadsetTestOn = FALSE;
        /* set audio mode to Normal */
        /* custom_em_set_mode(AUD_MODE_NORMAL); */
        FM_SendSetAudioModeReq(AUD_MODE_NORMAL);
        /* open loopback */
        kal_sleep_task(kal_milli_secs_to_ticks(200));
        custom_em_set_loopback(FALSE);

        change_left_softkey(STR_GLOBAL_ON, 0);

    }
    redraw_left_softkey();
}

/*****************************************************************
 **  Charger
 *****************************************************************/


/*****************************************************************************
 * FUNCTION
 *  HightlightFMChargerHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HightlightFMChargerHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(FM_EntryChargerHdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    change_left_softkey(STR_GLOBAL_OK, 0);
    redraw_left_softkey();
}


/*****************************************************************************
 * FUNCTION
 *  FM_EntryChargerHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FM_EntryChargerHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __CUST_NEW__
    custom_em_gpio_start(12);
#endif 
    EntryFMADCMenu();
}

/*****************************************************************
 **  RingTone
 *****************************************************************/


/*****************************************************************************
 * FUNCTION
 *  HightlightFMRingToneHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HightlightFMRingToneHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryFMRingToneHdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    if (RingToneTestOn)
    {
        change_left_softkey(STR_GLOBAL_OFF, 0);
    }
    else
    {
        change_left_softkey(STR_GLOBAL_ON, 0);
    }
    redraw_left_softkey();

}


/*****************************************************************************
 * FUNCTION
 *  EntryFMRingToneHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryFMRingToneHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FM_RestoreAudio();
    FM_RESET_AUDIO_STATE(FM_AUDIO_TEST_STAT_RINGTONE);

    if (!RingToneTestOn)
    {
        RingToneTestOn = TRUE;
        /* set gain */
        Media_SetOutputVolume(255, 0);
        /* play MIDI_1 */
        FM_SendPlayAudioReq(0);

        change_left_softkey(STR_GLOBAL_OFF, 0);

    }
    else
    {
        RingToneTestOn = FALSE;
        /* custom_em_set_mode(AUD_MODE_NORMAL); */
        FM_SendSetAudioModeReq(AUD_MODE_NORMAL);
        /* stop MIDI */
        FM_SendStopAudioReq(0);

        change_left_softkey(STR_GLOBAL_ON, 0);

    }
    redraw_left_softkey();
}


/*****************************************************************************
 * FUNCTION
 *  FM_RestoreAudio
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FM_RestoreAudio(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (LoudSpkTestOn || ReceiverTestOn)
    {
        TONE_Stop();
    }
    if (EchoLoopTestOn || HeadsetTestOn)
    {
        custom_em_set_loopback(FALSE);
    }
    if (RingToneTestOn)
    {
        FM_SendStopAudioReq(0);
    }

    /* MTK Brian modified for deinit special mode, 2003/12/03 */
    FM_SendSetAudioModeReq(AUD_MODE_NORMAL);
}

/*****************************************************************
 **  RTC
 *****************************************************************/


/*****************************************************************************
 * FUNCTION
 *  HightlightFMRTCHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HightlightFMRTCHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryFMRTCHdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    change_left_softkey(STR_GLOBAL_OK, 0);
    redraw_left_softkey();
}


/*****************************************************************************
 * FUNCTION
 *  FM_HandleRTCRsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FM_HandleRTCRsp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(FM_RTC_START_TIMER);

    /* MTK added, Max for alarm */
    gFactoryAlarm = 1;
    FactorySetAlarm(3);
    //  custom_em_rtc_set(15);
    // MTK end
    //ShutdownSystemOperation();
    // MTK added, Max to move this function to alarm response
    //  QuitSystemOperation();
    // MTK end

}


/*****************************************************************************
 * FUNCTION
 *  EntryFMRTCHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryFMRTCHdlr(void)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory21Screen((U16) NULL, 0, (U16) NULL, 0, (U16) NULL, 0, STR_ID_FM_RTC_NOTIFY, NULL);

    FM_HandleRTCRsp();

#else /* __MTK_TARGET__ */ 

    PopupNoSupport();

#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  ExitFMRTCInitScr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitFMRTCInitScr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    QuitSystemOperation();
}


/*****************************************************************************
 * FUNCTION
 *  HightlightFMMTBFHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HightlightFMMTBFHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryFMMTBF, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    change_left_softkey(STR_GLOBAL_OK, 0);
    redraw_left_softkey();
}


/*****************************************************************************
 * FUNCTION
 *  FM_StopMTBF
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void FM_StopMTBF(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TurnOnBacklight(1);
    FM_BACK_TO_NORMAL_STATE();
    FM_RestoreAudio();

    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  EntryFMMTBF
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryFMMTBF(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_FM_MTBF, ExitFMMTBF, NULL, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_FM_MTBF);

    AUD_TEST_ON = 0;
    MTBF_counter = 0;
    MTBF_state_LCD = 0;
    MTBF_state_LED = 0;
    MTBF_state_VIB = 0;

    FM_MTBF();

    ShowCategory7Screen(
        STR_ID_FM_MTBF,
        IMG_ID_FM_MTBF,
        (U16) NULL,
        (U16) NULL,
        STR_GLOBAL_ABORT,
        IMG_GLOBAL_OK,
        NULL,
        guiBuffer);

    SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
    SetRightSoftkeyFunction(FM_StopMTBF, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  ExitFMMTBF
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitFMMTBF(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history currHistory;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TurnOnBacklight(1);
    FM_BACK_TO_NORMAL_STATE();

    FM_RestoreAudio();

    currHistory.scrnID = SCR_ID_FM_MTBF;
    currHistory.entryFuncPtr = EntryFMMTBF;
    mmi_ucs2cpy((S8*) currHistory.inputBuffer, (S8*) L"");
    GetCategoryHistory(currHistory.guiBuffer);
    AddHistory(currHistory);
}

#if (defined(__MSDC_MS__) || defined(__MSDC_SD_MMC__) || defined(__MSDC_MSPRO__))


/*****************************************************************************
 * FUNCTION
 *  HightlightFMMemoryCardHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HightlightFMMemoryCardHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryFMMemoryCardMenu, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    change_left_softkey(STR_GLOBAL_OK, 0);
    redraw_left_softkey();
}


/*****************************************************************************
 * FUNCTION
 *  FM_MemoryCardResponseHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void FM_MemoryCardResponseHandler(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Card_Response_Received = TRUE;
    memcpy((void*)&FM_Card_Status, info, sizeof(mmi_fmt_get_msdc_status_rsp_strcut));
    Card_Response_Sent = FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  FM_MemoryCardReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FM_MemoryCardReq(void)
{
#if ( !defined(FMT_NOT_PRESENT) && !defined(__L1_STANDALONE__) && !defined(__MAUI_BASIC__))
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_FMT;
    Message.oslMsgId = MSG_ID_MMI_FMT_GET_MSDC_STATUS_REQ;

    ClearInputEventHandler(MMI_DEVICE_ALL);

    Card_Response_Received = FALSE;
    FM_Card_Status.present = FALSE;

    Message.oslDataPtr = (oslParaType*) NULL;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

    Card_Response_Sent = TRUE;

#endif /* ( !defined(FMT_NOT_PRESENT) && !defined(__L1_STANDALONE__) && !defined(__MAUI_BASIC__)) */ 
}


/*****************************************************************************
 * FUNCTION
 *  EntryFMMemoryCardMenu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryFMMemoryCardMenu(void)
{
#if (defined(__MSDC_MS__) || defined(__MSDC_SD_MMC__) || defined(__MSDC_MSPRO__))
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    StopTimer(FM_AUTO_TEST_COMMNON_TIMER);

    if (FM_Card_Status.present == TRUE)
    {
        switch (FM_Card_Status.type)
        {
            case MS_CARD:
                mmi_asc_to_ucs2((S8*) EMFMUnicodeDisplayBuf, "\nMS_CARD.");
                break;
            case SD_CARD:
                mmi_asc_to_ucs2((S8*) EMFMUnicodeDisplayBuf, "\nSD_CARD.");
                break;
            case MMC_CARD:
                mmi_asc_to_ucs2((S8*) EMFMUnicodeDisplayBuf, "\nMMC_CARD.");
                break;
            default:
                mmi_asc_to_ucs2((S8*) EMFMUnicodeDisplayBuf, "\nError!!!");
        }
    }
    else
    {
        if (Card_Response_Received == FALSE)
        {   /* Keep waiting..... */
            if (Card_Response_Sent == FALSE)
            {
                FM_MemoryCardReq();
            }
            StartTimer(FM_AUTO_TEST_COMMNON_TIMER, 300, EntryFMMemoryCardMenu);
            mmi_asc_to_ucs2((S8*) EMFMUnicodeDisplayBuf, "\nPlease Wait....");
        }
        else
        {   /* No Card inserted. */
            mmi_asc_to_ucs2((S8*) EMFMUnicodeDisplayBuf, "\nNo Card.");
        }
    }

    if (Card_Response_Sent == FALSE)
    {
        EntryNewScreen(SCR_ID_FM_MEMORY_CARD, NULL, EntryFMMemoryCardMenu, NULL);

        guiBuffer = GetCurrGuiBuffer(SCR_ID_FM_MEMORY_CARD);
    }
    else
    {
        guiBuffer = NULL;
    }

    SetParentHandler(MENU_ID_FM_MEMORY_CARD);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory7Screen(
        STR_ID_FM_MEMORY_CARD,
        IMG_ID_FM_MEMORY_CARD,
        (U16) NULL,
        (U16) NULL,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8) EMFMUnicodeDisplayBuf,
        guiBuffer);

    SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

#endif /* (defined(__MSDC_MS__) || defined(__MSDC_SD_MMC__) || defined(__MSDC_MSPRO__)) */ 
}

#endif /* (defined(__MSDC_MS__) || defined(__MSDC_SD_MMC__) || defined(__MSDC_MSPRO__)) */ 


/*****************************************************************************
 * FUNCTION
 *  HightlightFMUARTHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HightlightFMUARTHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryFMUARTMenu, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    change_left_softkey(STR_GLOBAL_OK, 0);
    redraw_left_softkey();
}


/*****************************************************************************
 * FUNCTION
 *  FM_UARTResponseHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void FM_UARTResponseHandler(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UART_Response_Received = TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  FM_UARTReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FM_UARTReq(void)
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}

#ifdef __FM_UART_TEST_ON_UART1__
#define port_to_test uart_port1
#else 
#define port_to_test uart_port2
#endif 


/*****************************************************************************
 * FUNCTION
 *  FM_WriteReadUART
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FM_WriteReadUART(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

#define TEST_INFO_LENGTH 10
    kal_uint8 put_buffer[] = "1234567890";
    kal_uint8 get_buffer[TEST_INFO_LENGTH];
    kal_uint32 read_length = 0;
    kal_uint32 send_length;
    kal_uint8 status = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    send_length = UART_PutBytes(port_to_test, (kal_uint8*) put_buffer, (kal_uint16) TEST_INFO_LENGTH, MOD_MMI);

    if (send_length != TEST_INFO_LENGTH)    /* Send error or incomplete */
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 0, 1000, 0);
    }
    else
    {
        memset((void*)get_buffer, 0, TEST_INFO_LENGTH);
        kal_sleep_task(100);
        read_length = UART_GetBytes(port_to_test, get_buffer, TEST_INFO_LENGTH, &status, MOD_MMI);

        if ((read_length == TEST_INFO_LENGTH) && !strncmp((void*)put_buffer, (void*)get_buffer, TEST_INFO_LENGTH))
        {
            DisplayPopup((PU8) GetString(STR_GLOBAL_OK), IMG_GLOBAL_OK, 0, 1000, 0);
        }
        else    /* Error case */
        {
            DisplayPopup((PU8) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 0, 1000, 0);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryFMUARTMenu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryFMUARTMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    module_type UART_Owner = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UART_Owner = UART_GetOwnerID(port_to_test);
    UART_SetOwner(port_to_test, MOD_MMI);

    FM_WriteReadUART();
    UART_SetOwner(port_to_test, (kal_uint8) UART_Owner);
}

/*****************************************************************************
*
* Camera Parameter Adjusment Test
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_camera_exit_sublcd_screen
 * DESCRIPTION
 *  exit camrea sublcd screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_SUBLCD__
#if defined(__FM_CAMERA_TUNNING__) || defined(__FM_CAMERA_PREVIEW__)
void mmi_fm_camera_exit_sublcd_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SubLCDHistoryNode SubLCDHistory;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_camera_preview_stop();
    SubLCDHistory.entryFuncPtr = mmi_fm_camera_entry_sublcd_screen;
    AddSubLCDHistory(&SubLCDHistory);
}
#endif /* defined(__FM_CAMERA_TUNNING__) || defined(__FM_CAMERA_PREVIEW__) */ 
#endif /* __MMI_SUBLCD__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_camera_entry_sublcd_screen
 * DESCRIPTION
 *  entry camera sublcd screen. avoid Main and Sub update at same time
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_SUBLCD__
#if defined(__FM_CAMERA_TUNNING__) || defined(__FM_CAMERA_PREVIEW__)
void mmi_fm_camera_entry_sublcd_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecSubLCDCurrExitHandler();
    ShowCategory331Screen();
    SetSubLCDExitHandler(mmi_fm_camera_exit_sublcd_screen);
}
#endif /* defined(__FM_CAMERA_TUNNING__) || defined(__FM_CAMERA_PREVIEW__) */ 
#endif /* __MMI_SUBLCD__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_camera_clam_close_event_hdlr
 * DESCRIPTION
 *  clam close event handler
 * PARAMETERS
 *  ptr     [IN]        Ptr
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__FM_CAMERA_TUNNING__) || defined(__FM_CAMERA_PREVIEW__)
U8 mmi_fm_camera_clam_close_event_hdlr(mmi_frm_int_event_type interrupt_event)
{
#ifdef __MMI_CLAMSHELL__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (interrupt_event == MMI_FRM_INT_CLAM_CLOSE)
    {
        GoBackHistory();
        return FALSE;
    }
#endif /* __MMI_CLAMSHELL__ */ 

    /* return false means will pass this interrut to default handler */
    return FALSE;
}
#endif /* defined(__FM_CAMERA_TUNNING__) || defined(__FM_CAMERA_PREVIEW__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_highlight_camera
 * DESCRIPTION
 *  highlight camera item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__FM_CAMERA_TUNNING__) || defined(__FM_CAMERA_PREVIEW__)
static void mmi_fm_highlight_camera(void)
{
#if defined(__FM_CAMERA_TUNNING__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    change_left_softkey(STR_GLOBAL_OK, 0);
    SetLeftSoftkeyFunction(mmi_fm_entry_camera_screen, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    redraw_left_softkey();

#elif defined(__FM_CAMERA_PREVIEW__)

    change_left_softkey(STR_GLOBAL_OK, 0);
    SetLeftSoftkeyFunction(mmi_fm_camera_entry_preview_screen, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    redraw_left_softkey();

#endif 
}
#endif /* defined(__FM_CAMERA_TUNNING__) || defined(__FM_CAMERA_PREVIEW__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_camera_exit_preview_screen
 * DESCRIPTION
 *  exit factory mode camera preview screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__FM_CAMERA_PREVIEW__)
void mmi_fm_camera_exit_preview_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_camera_preview_stop();

    /* shut down camera */
    mdi_camera_power_off();

    /* set blt base layer only */
    gdi_layer_set_blt_layer(GDI_LAYER_MAIN_BASE_LAYER_HANDLE, 0, 0, 0);

    /* resume LCD patten */
    StartLEDPatternBackGround();

    /* let MMI can sleep */
    TurnOffBacklight();

    /* un-hook clam close msg */
    mmi_frm_clear_interrupt_event_handler(MMI_FRM_INT_CLAM_CLOSE);
    /* exit sublcd */
#ifdef __MMI_SUBLCD__
    GoBackSubLCDHistory();
#endif 
}
#endif /* defined(__FM_CAMERA_PREVIEW__) */ 


/*UNI@bw_20070427 9:52:40  add analog tv auto test*/
#if defined(ANALOG_TV_SUPPORT) 

void mmi_fm_entry_analogtv_screen(void)
{
	 /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    U8 *guiBuffer;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
EntryNewScreen(SCR_ID_FM_ANALOGTV, mmi_fm_exit_analogtv_screen, mmi_fm_entry_analogtv_screen, NULL);
gdi_layer_reset_clip();
 gdi_layer_reset_text_clip();

      entry_full_screen();
	/* enable multi_layer */
	gdi_layer_multi_layer_enable();

/*****************************************************************************
	* Create layers 
	*****************************************************************************/
	mmi_analog_tv_to_normal_screen_screen();
 
	guiBuffer = GetCurrGuiBuffer(SCR_ID_FM_ANALOGTV);

   memset(g_AnalogTv_data.ChannelList, 0, ANALOG_TV_CHANNEL_NUM);
    /* load setting */
    //mmi_analog_tv_load_setting();
      g_AnalogTv_data.DistrictSelected= ANALOG_TV_AREA_CHINA;
	g_AnalogTv_data.ModeSelected= 0;
	 mmi_tv_max_index=mmi_get_all_channels_of_current_district();
	 g_analog_tv_cntx.is_mute=FALSE;
	 g_AnalogTv_data.volume=2;
	 
	/*For reuse the interface of MOD_MED*/
    if (guiBuffer == NULL)
    {
        /* each time newly enter vdorec, zoom will be reset to default */
        g_analog_tv_cntx.setting.zoom = VDOREC_DEFAULT_SETTING_ZOOM;
        g_analog_tv_cntx.zoom_limit = 40;
	//mmi_analog_tv_get_channlelist_to_current_channel(); //lgadd	//p_6226_m24_bw_z0167 修改来电话时在回到此界面频道改变
	 g_AnalogTv_data.g_current_channel=1;
    #ifdef __MMI_ANALOG_TV_LOGO__
        DisplayAnalogLogo();//UNI@bw_20070413  添加电视logo
   #endif

    }

     mmi_tv_test_on=KAL_TRUE;  /*UNI@bw070530 测试完TV后，按power key退出，再进入电视还是测试模式*/
    /* init some golbal value */
    g_analog_tv_cntx.last_error= MDI_RES_VDOREC_SUCCEED;
    g_analog_tv_cntx.record_time= 0;
    g_analog_tv_cntx.is_lsk_pressed = FALSE;
    g_analog_tv_cntx.is_rsk_pressed = FALSE;
    g_analog_tv_cntx.is_ck_pressed = FALSE;
    g_analog_tv_cntx.is_zoom_in_key_pressed = FALSE;
    g_analog_tv_cntx.is_zoom_out_key_pressed = FALSE;
    g_analog_tv_cntx.is_ev_inc_key_pressed = FALSE;
    g_analog_tv_cntx.is_ev_dec_key_pressed = FALSE;
    g_AnalogTv_data.g_analog_tv_enable=TRUE;	
    /*UNI@bw070417A 上下方向键改为在channellist中切换 */
   // mmi_tv_all_valid_channels=mmi_analog_tv_get_all_valid_channels();
  
   /*******************************************************************
   * Init proper global state for video applcation  
   ********************************************************************/
    /* force all playing keypad tone off */
    AudioStopReq(GetCurKeypadTone());

    /* disable key pad tone */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);

    /* enable multi_layer */
	//gdi_layer_multi_layer_enable();

    /* suspend background play */
    mdi_audio_suspend_background_play();

    /* disalbe align timer */
    UI_disable_alignment_timers();

    /* stop LED patten */
    GpioCtrlReq(1);//MMIAPI_DEV_CTRL_GET

    /* 
		This is used to solve a very rare situation.	When playing a IMELODY 
		with backlight on/off, and the screen previous to this screen is a 
		horizontal screen. Before enter this screen, the IMELODY turn off the
		backlight. While exit previous screen, the layer rotate back to normal
		size and the content is not correct. So when calling TurnOnBacklight, 
		LCD is in sleepin state and draw wrong content to LCD.
		So we need to clear the buffer first to avoid this situation.
     */
    gdi_layer_clear(GDI_COLOR_BLACK);

    /* stop MMI sleep */
    TurnOnBacklight(0);

    /* use medium font */
	gui_set_font(&MMI_medium_font);

   /***************************************************************************** 
   * register interrupt event hdlr
   *****************************************************************************/
/* hook to touch screen callback */


   /****************************************************************************
   * draw skin                                                                 
   *****************************************************************************/
	mmi_analog_tv_init_panel();

	/* start preview */
       g_analog_tv_cntx.last_error = mdi_video_rec_power_on();
	if(FALSE == mmi_analog_tv_check_and_display_error_popup())
    {
     
	   mdi_tlg_tv_open_path();
	 if(g_analog_tv_cntx.is_mute==FALSE) //P_6226_M24_bw_z0149 modified: volume set mute, still phonate when fist entry
        {  
           mdi_tlg_tv_mute(0);
	    mdi_tlg_tv_set_volume(g_AnalogTv_data.volume ); 
	  }
	 else
	 	mdi_tlg_tv_mute(1);
	  
	  mmi_analog_tv_enter_state(ANALOG_TV_STATE_PREVIEW);
    }
}
static void EntryFMAnalogTvTransientScreen(void)
{
	U8*	guiBuffer;
	NeedExitFunc = FALSE; // discard auto test history
	EntryNewScreen(SCR_ID_FM_AUTO_TEST_START, ExitFMAutoTestStart, NULL, NULL);
	NeedExitFunc = TRUE;
       guiBuffer = GetCurrGuiBuffer(SCR_ID_FM_AUTO_TEST_START);
	RegisterHighlightHandler(ExecuteCurrHiliteHandler);

       FM_Autotest_test_done_USC2string(Tests[FM_AUTOTEST_ANALOGTV].name);
       ShowCategory7Screen( STR_ID_FM_AUTO_TEST_RESULT, IMG_ID_FM_AUTO_TEST_ROOT,
	                        STR_ID_FM_AUTO_TEST_PASS, IMG_GLOBAL_OK, STR_ID_FM_AUTO_TEST_FAIL,
	                        IMG_GLOBAL_BACK, ( PU8 ) EMFMUnicodeDisplayBuf, NULL );

       FM_Autotest_set_key_handlers();
}
void mmi_fm_exit_analogtv_screen(void)
{
 /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     U8  audio_mode;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 
       mmi_tv_test_on=KAL_FALSE; /*UNI@bw070530 测试完TV后，按power key退出，再进入电视还是测试模式*/
	g_analog_tv_cntx.state = ANALOG_TV_STATE_EXIT;
  /*UNI@bw_20070429 14:12:45  add tv auto test*/
        StopTimer(FM_AUTO_TEST_COMMNON_TIMER);       
        /*UNI@bw_20070817 [WQVGA LCD][ALL] auto test TV 重启*/    
        #if defined(__UNI_LCD_WQVGA_RESOLUTION_SUPPORT__)
          mdi_video_rec_preview_stop();
        #else

#ifndef MMI_ON_WIN32		
	  media_cam_stop(MOD_MMI);
#endif

        #endif /*__UNI_LCD_WQVGA_RESOLUTION_SUPPORT__*/ 
	/* retore default state */
	//g_vdorec_cntx.state = VDOREC_STATE_EXIT;
//P_6226_M38_bw_Z0001 解决从TV出来后漏电问题        
#ifndef WIN32
//Huyanwei Add It		
        analog_tv_Mute(1);
        kal_sleep_task(10);
#endif
	
	mdi_video_rec_power_off();

//#ifdef __ANALOG_TV_FEATURE_FULL_SCREEN__
  // if(mmi_analog_tv_is_full_screen())
   // {
	//	gIsAnalogTvFullScreen = 0;
	mmi_analog_tv_to_normal_screen_screen();
  //  }
//#endif 

   g_AnalogTv_data.g_analog_tv_enable=KAL_FALSE;
    audio_mode=mdi_audio_get_audio_mode();
    if(audio_mode==AUD_MODE_NORMAL)
        mdi_audio_set_audio_mode(AUD_MODE_NORMAL);	
//   mdi_tlg_tv_mute(1);//P_6226_M38_bw_Z0001 解决从TV出来后漏电问题 
  // pixtel_UI_cancel_timer(mmi_analog_tv_lcd_split_hdlr);

	leave_full_screen();

    gdi_layer_flatten_to_base(g_analog_tv_cntx.base_layer_handle,
        g_analog_tv_cntx.preview_layer_handle,
        g_analog_tv_cntx.osd_layer_handle,
        0);

    /* free layers */
    gdi_layer_free(g_analog_tv_cntx.preview_layer_handle);
    g_analog_tv_cntx.preview_layer_handle = 0;

    /* free osd layer */
    gdi_layer_free(g_analog_tv_cntx.osd_layer_handle);
    g_analog_tv_cntx.osd_layer_handle = GDI_LAYER_EMPTY_HANDLE;

    /* free buffer */
    mmi_frm_scrmem_free((void*)g_analog_tv_cntx.osd_layer_buf_ptr);
    g_analog_tv_cntx.osd_layer_buf_ptr = NULL;

    /* disable multi layer */
    gdi_layer_multi_layer_disable();

    /* resume alignment timer */
    UI_disable_alignment_timers();

    /* resume LED patten */
    GpioCtrlReq(2);//MMIAPI_DEV_CTRL_RELEASE

    /* let MMI can sleep */
    TurnOffBacklight();

    /* resume background audio */
    mdi_audio_resume_background_play();

    /* re-enable keypad tone */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);

#ifndef MMI_ON_WIN32
    /* un-hook clam close msg */
    SetInterruptEventHandler(NULL, NULL, MSG_ID_MMI_EQ_GPIO_DETECT_IND);
#endif /* MMI_ON_WIN32 */ 

#ifdef __MMI_ANALOG_TV_SIGNAL__
	 UI_cancel_timer(GetSingalIndicate); //bw added
#endif

	gdi_layer_clear(GDI_COLOR_BLACK);	
	/* set lcm rotate to default */
	gdi_lcd_set_rotate(GDI_LAYER_ROTATE_0);
	/* rotate base layer back to normal */
	gdi_layer_resize(UI_device_width, UI_device_height);
	
	enable_softkey_background();
	reset_softkeys();//reset softkeys 	

	/* restore to base layer only */
	gdi_layer_set_blt_layer(g_analog_tv_cntx.base_layer_handle, 0, 0, 0);
}

/**************************************************************
**	FUNCTION NAME		: FM_AutoTest_AnalogTv
**
**  	PURPOSE				: For Auto test in AnalogTv
**
**	INPUT PARAMETERS	: nil
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			:
**************************************************************/
void FM_AutoTest_AnalogTv(void)
{
#ifdef MMI_ON_HARDWARE_P
   currentTest = FM_TEST_ANALOG_TV;
   switch(sequence_counter)
   {
   case 0:
      sequence_counter++;
      mmi_fm_entry_analogtv_screen();
      StartTimer(FM_AUTO_TEST_COMMNON_TIMER, ANALOGTV_DURATION, FM_AutoTest_AnalogTv);

      break;
   default:
      sequence_counter=0;
      StopTimer(FM_AUTO_TEST_COMMNON_TIMER);

      EntryFMAnalogTvTransientScreen();
   }
#endif
}

U8  FM_Polling_current_test_item(void)
{
   return currentTest;
}

U8  FM_Polling_analogtv_test_item(void)
{
   return  FM_TEST_ANALOG_TV;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_camera_entry_preview_screen
 * DESCRIPTION
 *  exit factory mode camera preview screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__FM_CAMERA_PREVIEW__)
void mmi_fm_camera_entry_preview_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    mdi_camera_setting_struct camera_setting_data;
    mdi_camera_preview_struct camera_preview_data;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* entry new screen */
    EntryNewScreen(SCR_ID_FM_CAMERA, mmi_fm_camera_exit_preview_screen, mmi_fm_camera_entry_preview_screen, NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_FM_CAMERA);

    /* entry a full screen app */
    entry_full_screen();

    /* entry sublcd */
#ifdef __MMI_SUBLCD__
    ForceSubLCDScreen(mmi_fm_camera_entry_sublcd_screen);
#endif 

    mmi_camera_load_setting();

    /* enable multi-layer */
    gdi_layer_multi_layer_enable();

    /* stop MMI sleep */
    TurnOnBacklight(0);

#ifdef __MMI_CLAMSHELL__
    /* register event hdlr */
    mmi_frm_block_interrupt_event_handler(MMI_FRM_INT_CLAM_CLOSE, mmi_fm_camera_clam_close_event_hdlr, NULL);
#endif /* __MMI_CLAMSHELL__ */ 

    /* stop LCD patten */
    StopLEDPatternBackGround();

    /* power on and init hardware module */
    mdi_camera_power_on();

    /* clear background */
    gdi_layer_reset_clip();
    gdi_layer_reset_text_clip();
    gdi_layer_clear(GDI_COLOR_BLACK);

    SetKeyHandler(GoBackHistory, KEY_LSK, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_RSK, KEY_EVENT_UP);

    mdi_camera_load_default_setting(&camera_setting_data);

    /* preview parametes */
    camera_setting_data.zoom = 10;
    camera_setting_data.wb = camera_wb_command_map[g_camera_cntx.setting.wb];
    camera_setting_data.ev = camera_ev_command_map[g_camera_cntx.setting.ev];
    camera_setting_data.banding = camera_banding_command_map[g_camera_cntx.setting.banding];
    camera_setting_data.night = g_camera_cntx.setting.night;

    /* default effect */
    camera_setting_data.effect = camera_effect_command_map[g_camera_cntx.setting.effect];
    camera_setting_data.brightness = 128;
    camera_setting_data.saturation = 128;
    camera_setting_data.contrast = 128;
    camera_setting_data.hue = 0;

    camera_setting_data.preview_width = CAMERA_FACTORY_PREVIEW_WIDTH;
    camera_setting_data.preview_height = CAMERA_FACTORY_PREVIEW_HEIGHT;

    /* capture parameters - not used */
    camera_setting_data.image_qty = camera_image_qty_command_map[g_camera_cntx.setting.image_qty];
    camera_setting_data.image_width = g_camera_cntx.image_width;
    camera_setting_data.image_height = g_camera_cntx.image_height;

    camera_setting_data.lcm = MDI_CAMERA_PREVIEW_LCM_MAINLCD;
    camera_setting_data.preview_rotate = CAMERA_PREVIEW_MAINLCD_ROTATE;

    gdi_layer_set_blt_layer(GDI_LAYER_MAIN_BASE_LAYER_HANDLE, 0, 0, 0);

    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

    camera_preview_data.preview_layer_handle = GDI_LAYER_MAIN_BASE_LAYER_HANDLE;
    camera_preview_data.preview_wnd_offset_x = 0;
    camera_preview_data.preview_wnd_offset_y = 0;
    camera_preview_data.preview_wnd_width = UI_device_width;
    camera_preview_data.preview_wnd_height = UI_device_height;
    camera_preview_data.blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0;
    camera_preview_data.preview_layer_flag = GDI_LAYER_ENABLE_LAYER_0;
    camera_preview_data.is_lcd_update = TRUE;
    camera_preview_data.src_key_color = 0;
    camera_preview_data.is_tvout = FALSE;
    camera_preview_data.xenon_flash_status_callback = NULL;

    mdi_camera_preview_start(
        &camera_preview_data,
        &camera_setting_data);

}
#endif /* defined(__FM_CAMERA_PREVIEW__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_camtune_init
 * DESCRIPTION
 *  init camera tunning
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__FM_CAMERA_TUNNING__)
static void mmi_fm_camtune_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_camtune_cntx.group_idx = 0;
    g_camtune_cntx.group_count = 0;
    g_camtune_cntx.is_fullscreen = FALSE;
    g_camtune_cntx.is_previewing = FALSE;
    g_camtune_cntx.hilight_idx = 0;

    g_camtune_cntx.true_false_str[0] = (UI_string_type) GetString((U16) (STR_GLOBAL_OFF));
    g_camtune_cntx.true_false_str[1] = (UI_string_type) GetString((U16) (STR_GLOBAL_ON));
}
#endif /* defined(__FM_CAMERA_TUNNING__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_entry_camera_screen
 * DESCRIPTION
 *  entry factory mode camera screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__FM_CAMERA_TUNNING__)
static void mmi_fm_entry_camera_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 item_list[16];
    U16 item_icons[16];
    U16 num_item;
    U8 *gui_buffer;
    U8 *popup_list[16];
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_FM_CAMERA_SENSOR_SETTING, NULL, mmi_fm_entry_camera_screen, NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_FM_CAMERA_SENSOR_SETTING);
    num_item = GetNumOfChild(MENU_ID_FM_CAMERA);

    GetSequenceStringIds(MENU_ID_FM_CAMERA, item_list);
    GetSequenceImageIds(MENU_ID_FM_CAMERA, item_icons);
    SetParentHandler(MENU_ID_FM_CAMERA);

    RegisterHighlightHandler(mmi_fm_camera_highlight_hdlr);

    for (i = 0; i < num_item; i++)
    {
        item_icons[i] = (U16) (IMG_GLOBAL_L1 + i);
    }

    for (i = 0; i < num_item; i++)
    {
        popup_list[i] = NULL;
    }

    ConstructHintsList(MENU_ID_FM_CAMERA, popup_list);

    ShowCategory52Screen(
        STR_ID_FM_CAMERA,
        MENU_ID_FM_CAMERA,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_item,
        item_list,
        item_icons,
        (U8 **) popup_list,
        0,
        0,
        gui_buffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

#ifdef __MMI_FOURWAYS_KEY_DISABLE__
    SetKeyHandler(GoBackHistory, KEY_VOL_DOWN, KEY_EVENT_DOWN);
#endif 

}
#endif /* defined(__FM_CAMERA_TUNNING__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_camera_entry_restore_confirm_screen
 * DESCRIPTION
 *  entry restore default confirm screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__FM_CAMERA_TUNNING__)
static void mmi_fm_camera_entry_restore_confirm_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_ID_FM_CAMERA_RESTORE_CONFIRM),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_fm_camera_restore_confirm_yes, KEY_EVENT_UP);
}
#endif /* defined(__FM_CAMERA_TUNNING__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_camera_restore_confirm_yes
 * DESCRIPTION
 *  restore defualt confirm yes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__FM_CAMERA_TUNNING__)
static void mmi_fm_camera_restore_confirm_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    S32 data_size;

    nvram_camera_para_struct *camera_para_p;
    nvram_camera_para_struct *default_camera_para_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    camera_para_p = (nvram_camera_para_struct*) get_camera_para();
    default_camera_para_p = (nvram_camera_para_struct*) get_default_camera_para();

    data_size = sizeof(nvram_camera_para_struct);

    memcpy((void*)camera_para_p, (void*)default_camera_para_p, data_size);

    WriteRecord(NVRAM_EF_CAMERA_PARA_LID, 1, (void*)camera_para_p, data_size, &error);
    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, SUCCESS_TONE);

}
#endif /* defined(__FM_CAMERA_TUNNING__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_camera_entry_save_confirm_screen
 * DESCRIPTION
 *  entry save confirm screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__FM_CAMERA_TUNNING__)
static void mmi_fm_camera_entry_save_confirm_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_ID_FM_CAMERA_SAVE_CONFRIM),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_fm_camera_save_confirm_yes, KEY_EVENT_UP);
}
#endif /* defined(__FM_CAMERA_TUNNING__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_camera_save_confirm_yes
 * DESCRIPTION
 *  restore defualt confirm yes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__FM_CAMERA_TUNNING__)
static void mmi_fm_camera_save_confirm_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    nvram_camera_para_struct *camera_para_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    camera_para_p = get_camera_para();
    WriteRecord(NVRAM_EF_CAMERA_PARA_LID, 1, (void*)camera_para_p, sizeof(nvram_camera_para_struct), &error);
    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_SAVE, 1, ST_NOTIFYDURATION, SUCCESS_TONE);
}
#endif /* defined(__FM_CAMERA_TUNNING__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_camera_highlight_hdlr
 * DESCRIPTION
 *  camera screen highlight handler
 * PARAMETERS
 *  index       [IN]        Selected index
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__FM_CAMERA_TUNNING__)
static void mmi_fm_camera_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* select on Sensor setting or ISP setting */
    switch (index)
    {
        case 0: /*  Sensor Setting */
            g_camtune_cntx.category_idx = index;
            SetLeftSoftkeyFunction(mmi_fm_camtune_entry_screen, KEY_EVENT_UP);
            break;

        case 1: /* ISP Setting */
            g_camtune_cntx.category_idx = index;
            SetLeftSoftkeyFunction(mmi_fm_camtune_entry_screen, KEY_EVENT_UP);
            break;

        case 2: /* Save To NVRAM */
            g_camtune_cntx.category_idx = index;
            SetLeftSoftkeyFunction(mmi_fm_camera_entry_save_confirm_screen, KEY_EVENT_UP);
            break;

        case 3: /* Restore Default */
            g_camtune_cntx.category_idx = index;
            SetLeftSoftkeyFunction(mmi_fm_camera_entry_restore_confirm_screen, KEY_EVENT_UP);
            break;

        default:
            ASSERT(0);

    }

}
#endif /* defined(__FM_CAMERA_TUNNING__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_camtune_set_value
 * DESCRIPTION
 *  set value to driver
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__FM_CAMERA_TUNNING__)
static void mmi_fm_camtune_set_value(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 value;
    S32 index;
    S32 max, min;
    S8 buffer[128];
    S8 uni_buffer[256];
    S8 disp_buffer[256];
    mdi_camera_preview_struct camera_preview_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* convert digit string to value */
    index = g_camtune_cntx.hilight_idx / 2; /* 2 line per item */
    min = g_camtune_cntx.group_data.items[index].min_value;
    max = g_camtune_cntx.group_data.items[index].max_value;

    /* stop preview. if need to restart preview when apply setting */
    if (g_camtune_cntx.group_data.items[index].is_need_restart)
    {
        mdi_camera_preview_stop();
    }

    /* flush inline edit buffer to app's buffer */
    wgui_update_inline_data();

    /* if not ture false item, need covert from string to digit */
    if (!g_camtune_cntx.group_data.items[index].is_true_false)
    {
        value = gui_atoi((UI_string_type) g_camtune_cntx.group_data.items[index].digit_buf);

        /* value changed, set to driver */
        if ((value > max) || (value < min))
        {
            sprintf(buffer, "%d-%d", min, max);
            mmi_asc_to_ucs2(uni_buffer, buffer);
            mmi_ucs2cpy(disp_buffer, (PS8) (L"Out of range\n\n"));
            mmi_ucs2cat(disp_buffer, g_camtune_cntx.group_data.items[index].name_buf);
            mmi_ucs2cat(disp_buffer, (PS8) (L"\n"));
            mmi_ucs2cat(disp_buffer, uni_buffer);

            DisplayPopup((PU8) disp_buffer, 0, 1, 1000, WARNING_TONE);  /* popup time shorter than normal case */
            return;
        }

        g_camtune_cntx.group_data.items[index].value = value;

    }

    if (g_camtune_cntx.category_idx == FM_CAMERA_SENSOR)
    {
        set_sensor_item_info(g_camtune_cntx.group_idx, index, g_camtune_cntx.group_data.items[index].value);
    }
#if !defined(MT6225)    
    else if (g_camtune_cntx.category_idx == FM_CAMERA_ISP)
    {
        set_isp_engmode_item_info(g_camtune_cntx.group_idx, index, g_camtune_cntx.group_data.items[index].value);
    }
#endif    
    else
    {
        ASSERT(0);
    }

    /* re-start preview, if need to restart preview when apply setting */
    if (g_camtune_cntx.group_data.items[index].is_need_restart)
    {
        camera_preview_data.preview_layer_handle = g_camtune_cntx.preview_layer_handle;
        camera_preview_data.preview_wnd_offset_x = 0;
        camera_preview_data.preview_wnd_offset_y = MMI_title_height + MMI_title_y;
        camera_preview_data.preview_wnd_width = UI_device_width;
        camera_preview_data.preview_wnd_height = MMI_MENUITEM_HEIGHT * CAMTUNE_PREVIEW_HEIGHT_COUNT;
#if defined(__MMI_SUBMENU_USE_MM_IMAGE__)
        camera_preview_data.blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | GDI_LAYER_ENABLE_LAYER_2;
#else
        camera_preview_data.blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 ;
#endif
        camera_preview_data.preview_layer_flag = GDI_LAYER_ENABLE_LAYER_0;
        camera_preview_data.is_lcd_update = TRUE;
        camera_preview_data.src_key_color = 0;
        camera_preview_data.is_tvout = FALSE;
        camera_preview_data.xenon_flash_status_callback = NULL;

        mdi_camera_preview_start(
            &camera_preview_data,
            &g_camtune_cntx.camera_setting_data);
    }

}
#endif /* defined(__FM_CAMERA_TUNNING__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_camtune_draw_info_callback
 * DESCRIPTION
 *  draw info callback function. We use info region to display preview.
 * PARAMETERS
 *  index       [IN]        Hilight handler
 *  x1          [IN]        Pos1 x
 *  y1          [IN]        Pos1 y
 *  x2          [IN]        Pos2 x
 *  y2          [IN]        Pos2 y
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__FM_CAMERA_TUNNING__)
static void mmi_fm_camtune_draw_info_callback(S32 index, S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_clip();
    gdi_layer_reset_clip();
    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_clip();
}
#endif /* defined(__FM_CAMERA_TUNNING__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_camtune_highlight_hdlr
 * DESCRIPTION
 *  get group's info
 * PARAMETERS
 *  index       [IN]        Hilight handler
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__FM_CAMERA_TUNNING__)
static void mmi_fm_camtune_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_camtune_cntx.hilight_idx = index;

    /* hook key from cat57 */
    set_left_softkey_function(mmi_fm_camtune_set_value, KEY_EVENT_UP);
    set_right_softkey_function(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_fm_camtune_change_group_fwd, KEY_STAR, KEY_EVENT_UP);
    SetKeyHandler(mmi_fm_camtune_change_group_fwd, KEY_VOL_UP, KEY_EVENT_UP);
    SetKeyHandler(mmi_fm_camtune_change_group_bwd, KEY_VOL_DOWN, KEY_EVENT_UP);

}
#endif /* defined(__FM_CAMERA_TUNNING__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_camtune_get_category_info
 * DESCRIPTION
 *  get group's info
 * PARAMETERS
 *  category_idx        [IN]        Category index
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__FM_CAMERA_TUNNING__)
static void mmi_fm_camtune_get_category_info(U16 category_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get group count of the category */
    switch (category_idx)
    {
        case FM_CAMERA_SENSOR:
            get_sensor_group_count(&g_camtune_cntx.group_count);
            break;
    #if !defined(MT6225)
        case FM_CAMERA_ISP:
            get_isp_engmode_group_count(&g_camtune_cntx.group_count);
            break;
    #endif
        default:
            ASSERT(0);
            break;
    }
}
#endif /* defined(__FM_CAMERA_TUNNING__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_camtune_get_group_info
 * DESCRIPTION
 *  get group's info
 * PARAMETERS
 *  category_idx        [IN]        Category index, ISP or Sensor or whatelse
 *  group_idx           [IN]        Group's index
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__FM_CAMERA_TUNNING__)
static void mmi_fm_camtune_get_group_info(U16 category_idx, U16 group_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S8 buffer[256];

    ENG_sensor_info sensor_info;
    isp_engmode_item_info_struct isp_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (category_idx == FM_CAMERA_SENSOR)
    {
        get_sensor_group_info(group_idx, (kal_int8*) buffer, &g_camtune_cntx.group_data.item_count);
        mmi_asc_to_ucs2((PS8) g_camtune_cntx.group_data.name_buf, (PS8) buffer);

        g_camtune_cntx.group_data.item_inx = 0;

        /* set name buf's terminate, avoid overflow */
        g_camtune_cntx.group_data.name_buf[CAMTUNE_GROUP_NAME_BUF_LEN - 2] = '0';
        g_camtune_cntx.group_data.name_buf[CAMTUNE_GROUP_NAME_BUF_LEN - 1] = '0';

        /* get item info */
        for (i = 0; i < g_camtune_cntx.group_data.item_count; i++)
        {
            /* give it init value */
            sensor_info.is_true_false = FALSE;
            sensor_info.is_read_only = FALSE;
            sensor_info.is_need_restart = FALSE;
            sensor_info.item_value = 0;
            sensor_info.min = 0;
            sensor_info.max = 0;

            memset((void*)&g_camtune_cntx.group_data.items[i], 0, sizeof(fm_camtune_item_struct));

            get_sensor_item_info(group_idx, i, &sensor_info);

            /* set item name */
            mmi_asc_to_ucs2((PS8) g_camtune_cntx.group_data.items[i].name_buf, (PS8) sensor_info.item_name_ptr);
            g_camtune_cntx.group_data.items[i].name_buf[CAMTUNE_ITEM_NAME_BUF_LEN - 2] = '0';
            g_camtune_cntx.group_data.items[i].name_buf[CAMTUNE_ITEM_NAME_BUF_LEN - 1] = '0';

            g_camtune_cntx.group_data.items[i].is_true_false = sensor_info.is_true_false;
            g_camtune_cntx.group_data.items[i].is_read_only = sensor_info.is_read_only;
            g_camtune_cntx.group_data.items[i].is_need_restart = sensor_info.is_need_restart;
            g_camtune_cntx.group_data.items[i].value = sensor_info.item_value;
            g_camtune_cntx.group_data.items[i].min_value = sensor_info.min;
            g_camtune_cntx.group_data.items[i].max_value = sensor_info.max;

            /* conver from value to digit */
            gui_itoa(
                g_camtune_cntx.group_data.items[i].value,
                (UI_string_type) g_camtune_cntx.group_data.items[i].digit_buf,
                10);
        }

    }
#if !defined(MT6225)
    else if (category_idx == FM_CAMERA_ISP)
    {
        get_isp_engmode_group_info(group_idx, (kal_uint8*) buffer, &g_camtune_cntx.group_data.item_count);
        mmi_asc_to_ucs2((PS8) g_camtune_cntx.group_data.name_buf, (PS8) buffer);

        g_camtune_cntx.group_data.item_inx = 0;

        /* set name buf's terminate, avoid overflow */
        g_camtune_cntx.group_data.name_buf[CAMTUNE_GROUP_NAME_BUF_LEN - 2] = '0';
        g_camtune_cntx.group_data.name_buf[CAMTUNE_GROUP_NAME_BUF_LEN - 1] = '0';

        /* get item info */
        for (i = 0; i < g_camtune_cntx.group_data.item_count; i++)
        {
            isp_info.is_true_false = FALSE;
            isp_info.is_read_only = FALSE;
            isp_info.is_need_restart = FALSE;
            isp_info.item_value = 0;
            isp_info.min = 0;
            isp_info.max = 0;

            memset((void*)&g_camtune_cntx.group_data.items[i], 0, sizeof(fm_camtune_item_struct));

            get_isp_engmode_item_info(group_idx, i, &isp_info);

            /* set item name */
            mmi_asc_to_ucs2((PS8) g_camtune_cntx.group_data.items[i].name_buf, (PS8) isp_info.item_name_ptr);
            g_camtune_cntx.group_data.items[i].name_buf[CAMTUNE_ITEM_NAME_BUF_LEN - 2] = '0';
            g_camtune_cntx.group_data.items[i].name_buf[CAMTUNE_ITEM_NAME_BUF_LEN - 1] = '0';

            g_camtune_cntx.group_data.items[i].is_true_false = isp_info.is_true_false;
            g_camtune_cntx.group_data.items[i].is_read_only = isp_info.is_read_only;
            g_camtune_cntx.group_data.items[i].is_need_restart = isp_info.is_need_restart;
            g_camtune_cntx.group_data.items[i].value = isp_info.item_value;
            g_camtune_cntx.group_data.items[i].min_value = isp_info.min;
            g_camtune_cntx.group_data.items[i].max_value = isp_info.max;

            /* conver from value to digit */
            gui_itoa(
                g_camtune_cntx.group_data.items[i].value,
                (UI_string_type) g_camtune_cntx.group_data.items[i].digit_buf,
                10);
        }

    }
#endif /* #if !defined(MT6225) */    
    else
    {
        ASSERT(0);
    }
}
#endif /* defined(__FM_CAMERA_TUNNING__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_camtune_change_group_fwd
 * DESCRIPTION
 *  toggle group, change to next group
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__FM_CAMERA_TUNNING__)
static void mmi_fm_camtune_change_group_fwd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_camtune_cntx.group_count == 1)
    {
        return;
    }

    if (g_camtune_cntx.group_idx < g_camtune_cntx.group_count - 1)
    {
        g_camtune_cntx.group_idx++;
    }
    else
    {
        /* loop back */
        g_camtune_cntx.group_idx = 0;
    }

    /* stop preview */
    if (g_camtune_cntx.is_previewing)
    {
        mdi_camera_preview_stop();
        g_camtune_cntx.is_previewing = FALSE;
    }

    /* close previous category57 */
    /* 
     * we are will call category57 many times in one screen, so we need to close it 
     * to reset some data before calling next cat57.
     */
    CloseCategory57Screen();

    mmi_fm_camtune_get_group_info(g_camtune_cntx.category_idx, g_camtune_cntx.group_idx);
    mmi_fm_camtune_show_group();
}
#endif /* defined(__FM_CAMERA_TUNNING__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_camtune_change_group_bwd
 * DESCRIPTION
 *  toggle group, change to prev group
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__FM_CAMERA_TUNNING__)
static void mmi_fm_camtune_change_group_bwd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_camtune_cntx.group_count == 1)
    {
        return;
    }

    if (g_camtune_cntx.group_idx > 0)
    {
        g_camtune_cntx.group_idx--;
    }
    else
    {
        g_camtune_cntx.group_idx = g_camtune_cntx.group_count - 1;
    }

    /* stop preview */
    if (g_camtune_cntx.is_previewing)
    {
        mdi_camera_preview_stop();
        g_camtune_cntx.is_previewing = FALSE;
    }

    /* close previous category57 */
    /* 
     * we are will call category57 many times in one screen, so we need to close it 
     * to reset some data before calling next cat57.
     */
    CloseCategory57Screen();

    mmi_fm_camtune_get_group_info(g_camtune_cntx.category_idx, g_camtune_cntx.group_idx);
    mmi_fm_camtune_show_group();
}
#endif /* defined(__FM_CAMERA_TUNNING__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_camtune_toggle_fullscreen
 * DESCRIPTION
 *  toggle to fullscreen, clear OSD
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__FM_CAMERA_TUNNING__)
static void mmi_fm_camtune_toggle_fullscreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_camera_preview_struct camera_preview_data;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_camtune_cntx.is_fullscreen)
    {
        /* Change to FULLSCREEN preview */

        g_camtune_cntx.is_fullscreen = TRUE;

        /* stop preview */
        mdi_camera_preview_stop();

        gdi_layer_set_blt_layer(g_camtune_cntx.preview_layer_handle, 0, 0, 0);

        /* start preview if it is not previewing */

        g_camtune_cntx.camera_setting_data.preview_width = UI_device_width;
        g_camtune_cntx.camera_setting_data.preview_height = UI_device_height;

        camera_preview_data.preview_layer_handle = g_camtune_cntx.preview_layer_handle;
        camera_preview_data.preview_wnd_offset_x = 0;
        camera_preview_data.preview_wnd_offset_y = 0;
        camera_preview_data.preview_wnd_width = UI_device_width;
        camera_preview_data.preview_wnd_height = UI_device_height;
        camera_preview_data.blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0;
        camera_preview_data.preview_layer_flag = GDI_LAYER_ENABLE_LAYER_0;
        camera_preview_data.is_lcd_update = TRUE;
        camera_preview_data.src_key_color = 0;
        camera_preview_data.is_tvout = FALSE;
        camera_preview_data.xenon_flash_status_callback = NULL;

        mdi_camera_preview_start(
            &camera_preview_data,
            &g_camtune_cntx.camera_setting_data);

        SetKeyHandler(mmi_fm_camtune_toggle_fullscreen, KEY_POUND, KEY_EVENT_UP);

    }
    else
    {
        /* Change to NORMAL preview with UI */

        g_camtune_cntx.is_fullscreen = FALSE;

        mdi_camera_preview_stop();

    #ifdef __MMI_SUBMENU_USE_MM_IMAGE__
        /* use wallpaper for submenu */
        gdi_layer_set_blt_layer(g_camtune_cntx.preview_layer_handle, wgui_layer_1, wgui_base_layer, 0);
    #else /* __MMI_SUBMENU_USE_MM_IMAGE__ */ 
        gdi_layer_set_blt_layer(g_camtune_cntx.preview_layer_handle, wgui_base_layer, 0, 0);
    #endif /* __MMI_SUBMENU_USE_MM_IMAGE__ */ 

        /* preview parametes */
        g_camtune_cntx.camera_setting_data.preview_width = UI_device_width;
        g_camtune_cntx.camera_setting_data.preview_height = MMI_MENUITEM_HEIGHT * CAMTUNE_PREVIEW_HEIGHT_COUNT;

        /* call this function to redraw all UI/keys */
        mmi_fm_camtune_show_group();

        /* blt UI */
        gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

        camera_preview_data.preview_layer_handle = g_camtune_cntx.preview_layer_handle;
        camera_preview_data.preview_wnd_offset_x = 0;
        camera_preview_data.preview_wnd_offset_y = MMI_title_height + MMI_title_y;
        camera_preview_data.preview_wnd_width = UI_device_width;
        camera_preview_data.preview_wnd_height = MMI_MENUITEM_HEIGHT * CAMTUNE_PREVIEW_HEIGHT_COUNT;
#if defined(__MMI_SUBMENU_USE_MM_IMAGE__)
        camera_preview_data.blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | GDI_LAYER_ENABLE_LAYER_2;
#else
        camera_preview_data.blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 ;
#endif
        camera_preview_data.preview_layer_flag = GDI_LAYER_ENABLE_LAYER_0;
        camera_preview_data.is_lcd_update = TRUE;
        camera_preview_data.src_key_color = 0;
        camera_preview_data.is_tvout = FALSE;
        camera_preview_data.xenon_flash_status_callback = NULL;

        mdi_camera_preview_start(
            &camera_preview_data,
            &g_camtune_cntx.camera_setting_data);

    }

}
#endif /* defined(__FM_CAMERA_TUNNING__) */ 


#if defined(__FM_CAMERA_TUNNING__)
/*****************************************************************************
* FUNCTION
*   mmi_fm_camtune_customize
* DESCRIPTION
*   Customize category57
* PARAMETERS
*	 none
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
static void mmi_fm_camtune_customize(void)
{
    #if defined(__MMI_TOUCH_SCREEN__)
        mmi_pen_editor_disable_input(PEN_EDITOR_DISABLE_HANDWRITNG);
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_camtune_show_group
 * DESCRIPTION
 *  Camera tuning entry fucntion
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_camtune_show_group(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 item_id;
    mdi_camera_preview_struct camera_preview_data;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    InitializeCategory57Screen();

    item_id = 0;

    for (i = 0; i < g_camtune_cntx.group_data.item_count; i++)
    {
        SetInlineItemCaption(&wgui_inline_items[item_id++], (PU8) g_camtune_cntx.group_data.items[i].name_buf);
        if (g_camtune_cntx.group_data.items[i].is_read_only)
        {
            /* read only, cant modify */
            SetInlineItemActivation(&wgui_inline_items[item_id], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
            SetInlineItemDisplayOnly(&wgui_inline_items[item_id++], (PU8) g_camtune_cntx.group_data.items[i].digit_buf);
        }
        else
        {
            if (g_camtune_cntx.group_data.items[i].is_true_false)
            {
                SetInlineItemActivation(&wgui_inline_items[item_id], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
                SetInlineItemSelect(
                    &wgui_inline_items[item_id++],
                    2,
                    (U8 **) g_camtune_cntx.true_false_str,
                    &g_camtune_cntx.group_data.items[i].value);
            }
            else
            {
                SetInlineItemActivation(&wgui_inline_items[item_id], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
                SetInlineItemTextEdit(
                    &wgui_inline_items[item_id],
                    (PU8) g_camtune_cntx.group_data.items[i].digit_buf,
                    CAMTUNE_ITEM_DIG_BUF_LEN,
                    INPUT_TYPE_NUMERIC);
                SetInlineTextEditCustomFunction(&wgui_inline_items[item_id], mmi_fm_camtune_customize);
                DisableInlineItemHighlight(&wgui_inline_items[item_id++]);
            }

        }
    }

    RegisterHighlightHandler(mmi_fm_camtune_highlight_hdlr);

    /* append a info box on top of cateogory 57 screen */
    Category57AppendTopInfoBox(CAMTUNE_PREVIEW_HEIGHT_COUNT, mmi_fm_camtune_draw_info_callback, NULL, TRUE);

    gdi_layer_lock_frame_buffer();

    ShowCategory57Screen(
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        g_camtune_cntx.group_data.item_count * 2,   /* num of items *//* 2 line per item */
        NULL,                                       /* icon list */
        wgui_inline_items,                          /* inline data */
        g_camtune_cntx.hilight_idx,                 /* highlight idx */
        NULL);

    /* change titile - since catgory57 do not support disply title from string buffer, we have do it our own */
    ChangeTitleString((PU8) g_camtune_cntx.group_data.name_buf);
    draw_title();

#ifdef __MMI_SUBMENU_USE_MM_IMAGE__
    /* use wallpaper for submenu */
    gdi_layer_set_blt_layer(g_camtune_cntx.preview_layer_handle, wgui_layer_1, wgui_base_layer, 0);
#else /* __MMI_SUBMENU_USE_MM_IMAGE__ */ 
    gdi_layer_set_blt_layer(g_camtune_cntx.preview_layer_handle, wgui_base_layer, 0, 0);
#endif /* __MMI_SUBMENU_USE_MM_IMAGE__ */ 

    /* set key hdlr */
    SetCategory57RightSoftkeyFunctions(GoBackHistory, GoBackHistory);
    set_left_softkey_function(mmi_fm_camtune_set_value, KEY_EVENT_UP);
    DisableCategory57ScreenDone();

    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

    SetKeyHandler(mmi_fm_camtune_change_group_fwd, KEY_STAR, KEY_EVENT_UP);

    SetKeyHandler(mmi_fm_camtune_toggle_fullscreen, KEY_POUND, KEY_EVENT_UP);

    /* start preview if it is not previewing */
    if (!g_camtune_cntx.is_previewing)
    {

        mdi_camera_load_default_setting(&g_camtune_cntx.camera_setting_data);

        /* preview parametes */
        g_camtune_cntx.camera_setting_data.zoom = 10;   /* 1x */
        g_camtune_cntx.camera_setting_data.wb = camera_wb_command_map[CAMERA_DEFAULT_SETTING_WB];
        g_camtune_cntx.camera_setting_data.ev = camera_ev_command_map[CAMERA_DEFAULT_SETTING_EV];
        g_camtune_cntx.camera_setting_data.banding = camera_banding_command_map[CAMERA_DEFAULT_SETTING_BANDING];
        g_camtune_cntx.camera_setting_data.night = CAMERA_DEFAULT_SETTING_NIGHT;
        g_camtune_cntx.camera_setting_data.flash = CAMERA_DEFAULT_SETTING_FLASH;

        /* default effect */
        g_camtune_cntx.camera_setting_data.effect = camera_effect_command_map[CAMERA_DEFAULT_SETTING_EFFECT];
        g_camtune_cntx.camera_setting_data.brightness = 128;
        g_camtune_cntx.camera_setting_data.saturation = 128;
        g_camtune_cntx.camera_setting_data.contrast = 128;
        g_camtune_cntx.camera_setting_data.hue = 0;
#ifdef HORIZONTAL_CAMERA
        g_camtune_cntx.camera_setting_data.preview_width =  MMI_MENUITEM_HEIGHT * CAMTUNE_PREVIEW_HEIGHT_COUNT;
        g_camtune_cntx.camera_setting_data.preview_height =UI_device_width;
#else
        g_camtune_cntx.camera_setting_data.preview_width = UI_device_width;
        g_camtune_cntx.camera_setting_data.preview_height = MMI_MENUITEM_HEIGHT * CAMTUNE_PREVIEW_HEIGHT_COUNT;
#endif
        /* capture parameters */
        g_camtune_cntx.camera_setting_data.image_qty = camera_image_qty_command_map[CAMERA_DEFAULT_SETTING_IMAGE_QTY];

        g_camtune_cntx.camera_setting_data.image_width = g_camtune_cntx.camera_setting_data.preview_width ;
        g_camtune_cntx.camera_setting_data.image_height = g_camtune_cntx.camera_setting_data.preview_height ;

        g_camtune_cntx.camera_setting_data.lcm = MDI_CAMERA_PREVIEW_LCM_MAINLCD;
        g_camtune_cntx.camera_setting_data.preview_rotate = CAMERA_PREVIEW_MAINLCD_ROTATE;
        g_camtune_cntx.camera_setting_data.lcm_rotate = CAMERA_LCM_MAINLCD_ROTATE;


        camera_preview_data.preview_layer_handle = g_camtune_cntx.preview_layer_handle;
        camera_preview_data.preview_wnd_offset_x = 0;
        camera_preview_data.preview_wnd_offset_y = MMI_title_height + MMI_title_y;
        camera_preview_data.preview_wnd_width = UI_device_width;
        camera_preview_data.preview_wnd_height = MMI_MENUITEM_HEIGHT * CAMTUNE_PREVIEW_HEIGHT_COUNT;
#if defined(__MMI_SUBMENU_USE_MM_IMAGE__)
        camera_preview_data.blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | GDI_LAYER_ENABLE_LAYER_2;
#else
        camera_preview_data.blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 ;
#endif
        camera_preview_data.preview_layer_flag = GDI_LAYER_ENABLE_LAYER_0;
        camera_preview_data.is_lcd_update = TRUE;
        camera_preview_data.src_key_color = 0;
        camera_preview_data.is_tvout = FALSE;
        camera_preview_data.xenon_flash_status_callback = NULL;

        mdi_camera_preview_start(
            &camera_preview_data,
            &g_camtune_cntx.camera_setting_data);

        g_camtune_cntx.is_previewing = TRUE;
    }

}
#endif /* defined(__FM_CAMERA_TUNNING__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_camtune_entry_screen
 * DESCRIPTION
 *  Camera tuning entry fucntion
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__FM_CAMERA_TUNNING__)
static void mmi_fm_camtune_entry_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* this will force title status to redraw */
    entry_full_screen();

    EntryNewScreen(SCR_ID_FM_CAMERA, mmi_fm_camtune_exit_screen, NULL, NULL);

    mmi_fm_camtune_get_category_info(g_camtune_cntx.category_idx);

    g_camtune_cntx.is_previewing = FALSE;
    g_camtune_cntx.is_fullscreen = FALSE;
    gdi_layer_multi_layer_enable();

    /* entry sublcd */
#ifdef __MMI_SUBLCD__
    ForceSubLCDScreen(mmi_fm_camera_entry_sublcd_screen);
#endif 

    /* stop MMI sleep */
    TurnOnBacklight(0);

    /* force all playing keypad tone off */
    AudioStopReq(GetCurKeypadTone());

#ifdef __MMI_CLAMSHELL__
    /* register event hdlr */
    mmi_frm_block_interrupt_event_handler(MMI_FRM_INT_CLAM_CLOSE, mmi_fm_camera_clam_close_event_hdlr, NULL);
#endif /* __MMI_CLAMSHELL__ */ 

    /* stop LCD patten */
    StopLEDPatternBackGround();

    /* power on and init hardware module */
    mdi_camera_power_on();

{
    S32 buf_size;
    S32 offset_x = 0;
    S32 offset_y = 0;
    
#ifdef HORIZONTAL_CAMERA
    offset_x =             MMI_title_height + MMI_title_y;
#else 
    offset_y =             MMI_title_height + MMI_title_y;
#endif 


#ifdef HORIZONTAL_CAMERA
    g_camtune_cntx.camera_setting_data.preview_width =  MMI_MENUITEM_HEIGHT * CAMTUNE_PREVIEW_HEIGHT_COUNT;
    g_camtune_cntx.camera_setting_data.preview_height =UI_device_width;
#else
    g_camtune_cntx.camera_setting_data.preview_width = UI_device_width;
    g_camtune_cntx.camera_setting_data.preview_height = MMI_MENUITEM_HEIGHT * CAMTUNE_PREVIEW_HEIGHT_COUNT;
#endif
    buf_size =
        ((g_camtune_cntx.camera_setting_data.preview_width * g_camtune_cntx.camera_setting_data.preview_height * GDI_MAINLCD_BIT_PER_PIXEL) >> 3);

    /* create OSD layer */
    g_camtune_cntx.preview_layer_buf_ptr = mmi_frm_scrmem_alloc(buf_size);
 
    gdi_layer_create_using_outside_memory(
        0,
        0,
        g_camtune_cntx.camera_setting_data.preview_width ,
        g_camtune_cntx.camera_setting_data.preview_height ,
        &g_camtune_cntx.preview_layer_handle,
        (PU8) g_camtune_cntx.preview_layer_buf_ptr,
        (S32) buf_size);

    gdi_layer_push_and_set_active(g_camtune_cntx.preview_layer_handle);
#ifdef  HORIZONTAL_CAMERA
    gdi_layer_set_rotate(GDI_LCD_LAYER_ROTATE_90);
#endif
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_layer_set_position(offset_x, offset_y);
    gdi_layer_pop_and_restore_active();
}

    gdi_layer_get_base_handle(&wgui_base_layer);
    gdi_layer_push_and_set_active(wgui_base_layer);
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();

    mmi_fm_camtune_get_group_info(g_camtune_cntx.category_idx, g_camtune_cntx.group_idx);
    mmi_fm_camtune_show_group();

}
#endif /* defined(__FM_CAMERA_TUNNING__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_camtune_exit_screen
 * DESCRIPTION
 *  exit text selection screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__FM_CAMERA_TUNNING__)
static void mmi_fm_camtune_exit_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 input_buffer_size;
    history h;
    S16 n_history = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    h.scrnID = SCR_ID_FM_CAMERA;
    CloseCategory57Screen();
    h.entryFuncPtr = mmi_fm_camtune_entry_screen;
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & n_history);
    GetCategory57History(h.guiBuffer);
    input_buffer_size = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) h.inputBuffer);
    AddNHistory(h, input_buffer_size);

    if (g_camtune_cntx.is_previewing)
    {
        mdi_camera_preview_stop();
        g_camtune_cntx.is_previewing = FALSE;
    }

    gdi_layer_flatten_previous_to_base();

   /****** free osd layer ******/
#if defined(ISP_SUPPORT)
    gdi_layer_free(g_camtune_cntx.preview_layer_handle);
    g_camtune_cntx.preview_layer_handle = GDI_LAYER_EMPTY_HANDLE;

    mmi_frm_scrmem_free((void*)g_camtune_cntx.preview_layer_buf_ptr);
    g_camtune_cntx.preview_layer_buf_ptr = NULL;
#endif /* defined(ISP_SUPPORT) */ 

    /* turn off camera */
    mdi_camera_power_off();

    gdi_layer_multi_layer_disable();

    /* this will force title status to redraw */
    entry_full_screen();

    /* set blt base layer only */
    gdi_layer_set_blt_layer(GDI_LAYER_MAIN_BASE_LAYER_HANDLE, 0, 0, 0);

    /* resume LCD patten */
    StartLEDPatternBackGround();

    /* let MMI can sleep */
    TurnOffBacklight();

    /* re-enable keypad tone */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);

    /* un-hook clam close msg */
    mmi_frm_clear_interrupt_event_handler(MMI_FRM_INT_CLAM_CLOSE);

    /* exit sublcd */
#ifdef __MMI_SUBLCD__
    GoBackSubLCDHistory();
#endif 

}
#endif /* defined(__FM_CAMERA_TUNNING__) */ 


/*****************************************************************************
 * FUNCTION
 *  HightlightFMNandFlashHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HightlightFMNandFlashHdlr(void)
{
#ifdef NAND_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    change_left_softkey(STR_GLOBAL_OK, 0);
    SetLeftSoftkeyFunction(EntryFMNandFlashMenu, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    redraw_left_softkey();
#else /* NAND_SUPPORT */ 
    change_left_softkey((U16) NULL, 0);
    SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    redraw_left_softkey();

#endif /* NAND_SUPPORT */ 
}


/*****************************************************************************
 * FUNCTION
 *  EntryFMNandFlashMenu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryFMNandFlashMenu(void)
{
#ifdef NAND_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NANDsanitycheck_Factory() == KAL_TRUE)
    {
        DisplayPopup((PU8) GetString(STR_ID_FM_AUTO_TEST_PASS), IMG_GLOBAL_OK, 0, 1000, 0);
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_ID_FM_AUTO_TEST_FAILED), IMG_GLOBAL_ERROR, 0, 1000, 0);
    }
#endif /* NAND_SUPPORT */ 
}


/*****************************************************************************
 * FUNCTION
 *  ExitFMNandFlashMenu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitFMNandFlashMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}

/*=============== Auto Testing =============== */


/*****************************************************************************
 * FUNCTION
 *  FM_AutoTest_LED
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FM_AutoTest_LED(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currentTest = FM_TEST_LED;
    switch (sequence_counter)
    {
        case 0:
            sequence_counter++;
            FM_SetGpioReq(GPIO_DEV_LED_STATUS_1, LED_LIGHT_LEVEL5);
            ShowCategory7Screen(
                STR_ID_FM_AUTO_TEST_ROOT,
                IMG_ID_FM_AUTO_TEST_ROOT,
                STR_ID_FM_AUTO_TEST_PASS,
                IMG_GLOBAL_OK,
                STR_ID_FM_AUTO_TEST_FAIL,
                IMG_GLOBAL_BACK,
                (U8*) GetString(STR_ID_FM_AUTOTEST_LED_R),
                NULL);
            StartTimer(FM_AUTO_TEST_COMMNON_TIMER, LED_DURATION, FM_AutoTest_LED);
            FM_Autotest_set_key_handlers();

            break;
        case 1:
            sequence_counter++;
            FM_SetGpioReq(GPIO_DEV_LED_STATUS_1, LED_LIGHT_LEVEL0);
            FM_SetGpioReq(GPIO_DEV_LED_STATUS_2, LED_LIGHT_LEVEL5);
            ShowCategory7Screen(
                STR_ID_FM_AUTO_TEST_ROOT,
                IMG_ID_FM_AUTO_TEST_ROOT,
                STR_ID_FM_AUTO_TEST_PASS,
                IMG_GLOBAL_OK,
                STR_ID_FM_AUTO_TEST_FAIL,
                IMG_GLOBAL_BACK,
                (U8*) GetString(STR_ID_FM_AUTOTEST_LED_G),
                NULL);
            StartTimer(FM_AUTO_TEST_COMMNON_TIMER, LED_DURATION, FM_AutoTest_LED);
            FM_Autotest_set_key_handlers();
            break;
        case 2:
            sequence_counter++;
            FM_SetGpioReq(GPIO_DEV_LED_STATUS_2, LED_LIGHT_LEVEL0);
            FM_SetGpioReq(GPIO_DEV_LED_STATUS_3, LED_LIGHT_LEVEL5);
            ShowCategory7Screen(
                STR_ID_FM_AUTO_TEST_ROOT,
                IMG_ID_FM_AUTO_TEST_ROOT,
                STR_ID_FM_AUTO_TEST_PASS,
                IMG_GLOBAL_OK,
                STR_ID_FM_AUTO_TEST_FAIL,
                IMG_GLOBAL_BACK,
                (U8*) GetString(STR_ID_FM_AUTOTEST_LED_B),
                NULL);
            StartTimer(FM_AUTO_TEST_COMMNON_TIMER, LED_DURATION, FM_AutoTest_LED);
            FM_Autotest_set_key_handlers();
            break;
        default:
            sequence_counter = 0;
            FM_SetGpioReq(GPIO_DEV_LED_STATUS_3, LED_LIGHT_LEVEL0);
            StopTimer(FM_AUTO_TEST_COMMNON_TIMER);

            {
                //                 FM_Autotest_test_done_string((S8*) EMFMAsciiDisplayBuf, Tests[FM_AUTOTEST_LED].name);
                //          mmi_asc_to_ucs2(EMFMUnicodeDisplayBuf, (S8*)EMFMAsciiDisplayBuf);
                FM_Autotest_test_done_USC2string(Tests[FM_AUTOTEST_LED].name);
                ShowCategory7Screen(
                    STR_ID_FM_AUTO_TEST_RESULT,
                    IMG_ID_FM_AUTO_TEST_ROOT,
                    STR_ID_FM_AUTO_TEST_PASS,
                    IMG_GLOBAL_OK,
                    STR_ID_FM_AUTO_TEST_FAIL,
                    IMG_GLOBAL_BACK,
                    (PU8) EMFMUnicodeDisplayBuf,
                    NULL);

                FM_Autotest_set_key_handlers();
            }
            return;
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  FM_AutoTest_CLAM
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FM_AutoTest_CLAM(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currentTest = FM_TEST_CLAM_DETECT;

    switch (sequence_counter)
    {
        case 0:
            sequence_counter++;
            StartTimer(FM_AUTO_TEST_COMMNON_TIMER, CLAM_DURATION, FM_AutoTest_CLAM);
            ShowCategory7Screen(
                STR_ID_FM_AUTO_TEST_ROOT,
                IMG_ID_FM_AUTO_TEST_ROOT,
                STR_ID_FM_AUTO_TEST_PASS,
                IMG_GLOBAL_OK,
                STR_ID_FM_AUTO_TEST_FAIL,
                IMG_GLOBAL_BACK,
                (U8*) GetString(STR_ID_FM_AUTOTEST_CLAM),
                NULL);
            FM_Autotest_set_key_handlers();

            break;
        default:
            sequence_counter = 0;
            StopTimer(FM_AUTO_TEST_COMMNON_TIMER);

            {
                FM_Autotest_test_done_USC2string(Tests[FM_AUTOTEST_CLAM].name);
                ShowCategory7Screen(
                    STR_ID_FM_AUTO_TEST_RESULT,
                    IMG_ID_FM_AUTO_TEST_ROOT,
                    STR_ID_FM_AUTO_TEST_PASS,
                    IMG_GLOBAL_OK,
                    STR_ID_FM_AUTO_TEST_FAIL,
                    IMG_GLOBAL_BACK,
                    (PU8) EMFMUnicodeDisplayBuf,
                    NULL);

                FM_Autotest_set_key_handlers();
            }
    }
}


/*****************************************************************************
 * FUNCTION
 *  FM_AutoTest_SubLCM
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FM_AutoTest_SubLCM(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currentTest = FM_TEST_SUBLCM;

    if (sequence_counter < LCD_CONTRAST_MAX_LEVEL)
    {
        UI_character_type text1[32];
        U8 u8text[32];

        sequence_counter++;
        PhnsetMainLCDContrast((U8) sequence_counter);
        PhnsetSubLCDContrast((U8) sequence_counter);

        sprintf((S8*) u8text, "%d/%d", sequence_counter, MAX_CONTRAST_NUM);
        mmi_asc_to_ucs2((S8*) text1, (S8*) u8text);

        ShowCategory205Screen(
            (U16) STR_ID_FM_AUTO_TEST_PASS,
            0,
            (U16) STR_ID_FM_AUTO_TEST_FAIL,
            0,
            text1,
            IMG_ID_FM_CONTRAST,
            NULL);

        StartTimer(FM_AUTO_TEST_COMMNON_TIMER, LCM_CONSTRAST_DURATION, FM_AutoTest_SubLCM);

        FM_Autotest_set_key_handlers();
    }
    else
    {
        sequence_counter = 0;
        PhnsetMainLCDContrast(7);
        PhnsetSubLCDContrast(7);
        StopTimer(FM_AUTO_TEST_COMMNON_TIMER);

        {
            FM_Autotest_test_done_USC2string(Tests[FM_AUTOTEST_SUBLCM].name);
            ShowCategory7Screen(
                STR_ID_FM_AUTO_TEST_RESULT,
                IMG_ID_FM_AUTO_TEST_ROOT,
                STR_ID_FM_AUTO_TEST_PASS,
                IMG_GLOBAL_OK,
                STR_ID_FM_AUTO_TEST_FAIL,
                IMG_GLOBAL_BACK,
                (PU8) EMFMUnicodeDisplayBuf,
                NULL);

            FM_Autotest_set_key_handlers();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  FM_AutoTest_Version
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FM_AutoTest_Version(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MTK_TARGET__)
    version_struct ver_struct;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currentTest = FM_TEST_SW_VERSION;

    switch (sequence_counter)
    {
        case 0:
    #if defined(__MTK_TARGET__)
            /* Get sturctured version number */
            INT_VersionNumbers(&ver_struct);

            /* MCU (SW Ver.) */
            memset(EMFMAsciiDisplayBuf, 0, sizeof(EMFMAsciiDisplayBuf));
            memcpy(EMFMAsciiDisplayBuf, (S8*) ver_struct.mcu_sw, MAX_TEST_STRING_BUF - 2);
            mmi_asc_to_ucs2((S8*) EMFMUnicodeDisplayBuf, (S8*) EMFMAsciiDisplayBuf);

    #else /* defined(__MTK_TARGET__)) */ 
            /* For PC Simulatior */
            mmi_asc_to_ucs2((S8*) EMFMUnicodeDisplayBuf, (S8*) "MTK_SW.V0");
    #endif /* defined(__MTK_TARGET__)) */ 
            sequence_counter++;
            ShowCategory7Screen(
                STR_ID_FM_AUTO_TEST_ROOT,
                IMG_ID_FM_AUTO_TEST_ROOT,
                STR_ID_FM_AUTO_TEST_PASS,
                IMG_GLOBAL_OK,
                STR_ID_FM_AUTO_TEST_FAIL,
                IMG_GLOBAL_BACK,
                (PU8) EMFMUnicodeDisplayBuf,
                NULL);

            StartTimer(FM_AUTO_TEST_COMMNON_TIMER, VERSION_DURATION, FM_AutoTest_Version);

            FM_Autotest_set_key_handlers();

            break;
        default:
            sequence_counter = 0;
            StopTimer(FM_AUTO_TEST_COMMNON_TIMER);

            {
                FM_Autotest_test_done_USC2string(Tests[FM_AUTOTEST_VERSION].name);
                ShowCategory7Screen(
                    STR_ID_FM_AUTO_TEST_RESULT,
                    IMG_ID_FM_AUTO_TEST_ROOT,
                    STR_ID_FM_AUTO_TEST_PASS,
                    IMG_GLOBAL_OK,
                    STR_ID_FM_AUTO_TEST_FAIL,
                    IMG_GLOBAL_BACK,
                    (PU8) EMFMUnicodeDisplayBuf,
                    NULL);

                FM_Autotest_set_key_handlers();
            }
    }
}


/*****************************************************************************
 * FUNCTION
 *  FM_AutoTest_Backlight
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FM_AutoTest_Backlight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currentTest = FM_TEST_BACKLIGHT;

    switch (sequence_counter)
    {
        case 0:
            sequence_counter++;
            StartTimer(FM_AUTO_TEST_COMMNON_TIMER, BACKLIGHT_DURATION, FM_AutoTest_Backlight);
            ShowCategory7Screen(
                STR_ID_FM_AUTO_TEST_ROOT,
                IMG_ID_FM_AUTO_TEST_ROOT,
                STR_ID_FM_AUTO_TEST_PASS,
                IMG_GLOBAL_OK,
                STR_ID_FM_AUTO_TEST_FAIL,
                IMG_GLOBAL_BACK,
                (U8*) GetString(STR_ID_FM_AUTOTEST_BACKLIGHT),
                NULL);
            FM_Autotest_set_key_handlers();

            break;
        case 1:
            sequence_counter++;
            FM_SetGpioReq(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL0);
            FM_SetGpioReq(GPIO_DEV_LED_KEY, LED_LIGHT_LEVEL0);
            StartTimer(FM_AUTO_TEST_COMMNON_TIMER, BACKLIGHT_DURATION, FM_AutoTest_Backlight);
            ShowCategory7Screen(
                STR_ID_FM_AUTO_TEST_ROOT,
                IMG_ID_FM_AUTO_TEST_ROOT,
                STR_ID_FM_AUTO_TEST_PASS,
                IMG_GLOBAL_OK,
                STR_ID_FM_AUTO_TEST_FAIL,
                IMG_GLOBAL_BACK,
                (U8*) GetString(STR_ID_FM_AUTOTEST_BACKLIGHT),
                NULL);
            FM_Autotest_set_key_handlers();

            break;
        case 2:
            sequence_counter++;
            FM_SetGpioReq(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL5);
            StartTimer(FM_AUTO_TEST_COMMNON_TIMER, BACKLIGHT_DURATION, FM_AutoTest_Backlight);
            ShowCategory7Screen(
                STR_ID_FM_AUTO_TEST_ROOT,
                IMG_ID_FM_AUTO_TEST_ROOT,
                STR_ID_FM_AUTO_TEST_PASS,
                IMG_GLOBAL_OK,
                STR_ID_FM_AUTO_TEST_FAIL,
                IMG_GLOBAL_BACK,
                (U8*) GetString(STR_ID_FM_AUTOTEST_BACKLIGHT),
                NULL);
            FM_Autotest_set_key_handlers();

            break;
        case 3:
            sequence_counter++;
            FM_SetGpioReq(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL0);
            FM_SetGpioReq(GPIO_DEV_LED_KEY, LED_LIGHT_LEVEL5);
            StartTimer(FM_AUTO_TEST_COMMNON_TIMER, BACKLIGHT_DURATION, FM_AutoTest_Backlight);
            ShowCategory7Screen(
                STR_ID_FM_AUTO_TEST_ROOT,
                IMG_ID_FM_AUTO_TEST_ROOT,
                STR_ID_FM_AUTO_TEST_PASS,
                IMG_GLOBAL_OK,
                STR_ID_FM_AUTO_TEST_FAIL,
                IMG_GLOBAL_BACK,
                (U8*) GetString(STR_ID_FM_AUTOTEST_BACKLIGHT),
                NULL);
            FM_Autotest_set_key_handlers();

            break;
        default:
            sequence_counter = 0;
            StopTimer(FM_AUTO_TEST_COMMNON_TIMER);
            FM_SetGpioReq(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL5);
            FM_SetGpioReq(GPIO_DEV_LED_KEY, LED_LIGHT_LEVEL0);

            {
                FM_Autotest_test_done_USC2string(Tests[FM_AUTOTEST_BACKLIGHT].name);
                ShowCategory7Screen(
                    STR_ID_FM_AUTO_TEST_RESULT,
                    IMG_ID_FM_AUTO_TEST_ROOT,
                    STR_ID_FM_AUTO_TEST_PASS,
                    IMG_GLOBAL_OK,
                    STR_ID_FM_AUTO_TEST_FAIL,
                    IMG_GLOBAL_BACK,
                    (PU8) EMFMUnicodeDisplayBuf,
                    NULL);

                FM_Autotest_set_key_handlers();
            }
            return;
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  FM_AutoTest_LCD
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FM_AutoTest_LCD(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currentTest = FM_TEST_LCD;

    sequence_counter = 0;
    FM_HandleColorSetChange();
}


/*****************************************************************************
 * FUNCTION
 *  FM_AutoTest_Keypad
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FM_AutoTest_Keypad(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currentTest = FM_TEST_KEYPAD;

    EntryFMKeypadTest();
}


/*****************************************************************************
 * FUNCTION
 *  FM_AutoTest_Receiver
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FM_AutoTest_Receiver(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currentTest = FM_TEST_RECEIVER;

    FM_SendStopAudioReq(0);
    Media_Stop();
    ReceiverTestOn = TRUE;
    FM_SendSetAudioModeReq(AUD_MODE_NORMAL);
    /* play 1K tone */
    TONE_SetOutputVolume(255, 0);
    TONE_Play((const L1SP_Tones*)test_tone);

    switch (sequence_counter)
    {
        case 0:
            sequence_counter++;
            StartTimer(FM_AUTO_TEST_COMMNON_TIMER, RECEIVER_DURATION, FM_AutoTest_Receiver);
            ShowCategory7Screen(
                STR_ID_FM_AUTO_TEST_ROOT,
                IMG_ID_FM_AUTO_TEST_ROOT,
                STR_ID_FM_AUTO_TEST_PASS,
                IMG_GLOBAL_OK,
                STR_ID_FM_AUTO_TEST_FAIL,
                IMG_GLOBAL_BACK,
                (U8*) GetString(STR_ID_FM_AUTOTEST_RECEIVER),
                NULL);
            FM_Autotest_set_key_handlers();

            break;
        default:
            sequence_counter = 0;
            StopTimer(FM_AUTO_TEST_COMMNON_TIMER);

            ReceiverTestOn = FALSE;

            FM_SendSetAudioModeReq(AUD_MODE_NORMAL);
            /* stop 1K tone */
            TONE_Stop();

            {
                FM_Autotest_test_done_USC2string(Tests[FM_AUTOTEST_RECEIVER].name);
                ShowCategory7Screen(
                    STR_ID_FM_AUTO_TEST_RESULT,
                    IMG_ID_FM_AUTO_TEST_ROOT,
                    STR_ID_FM_AUTO_TEST_PASS,
                    IMG_GLOBAL_OK,
                    STR_ID_FM_AUTO_TEST_FAIL,
                    IMG_GLOBAL_BACK,
                    (PU8) EMFMUnicodeDisplayBuf,
                    NULL);

                FM_Autotest_set_key_handlers();
            }
    }
}


/*****************************************************************************
 * FUNCTION
 *  FM_AutoTest_MIC
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FM_AutoTest_MIC(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currentTest = FM_TEST_MIC;

    FM_SendStopAudioReq(0);
    Media_Stop();
    EchoLoopTestOn = TRUE;
    FM_SendSetAudioModeReq(AUD_MODE_NORMAL);
    /* open loopback */
    kal_sleep_task(kal_milli_secs_to_ticks(100));
    custom_em_set_loopback(TRUE);

    switch (sequence_counter)
    {
        case 0:
            sequence_counter++;
            StartTimer(FM_AUTO_TEST_COMMNON_TIMER, MIC_DURATION, FM_AutoTest_MIC);
            ShowCategory7Screen(
                STR_ID_FM_AUTO_TEST_ROOT,
                IMG_ID_FM_AUTO_TEST_ROOT,
                STR_ID_FM_AUTO_TEST_PASS,
                IMG_GLOBAL_OK,
                STR_ID_FM_AUTO_TEST_FAIL,
                IMG_GLOBAL_BACK,
                (U8*) GetString(STR_ID_FM_AUTOTEST_MIC),
                NULL);

            FM_Autotest_set_key_handlers();

            break;
        default:
            sequence_counter = 0;
            StopTimer(FM_AUTO_TEST_COMMNON_TIMER);

            EchoLoopTestOn = FALSE;
            /* close loopback */
            custom_em_set_loopback(FALSE);

            {
                FM_Autotest_test_done_USC2string(Tests[FM_AUTOTEST_MIC].name);
                ShowCategory7Screen(
                    STR_ID_FM_AUTO_TEST_RESULT,
                    IMG_ID_FM_AUTO_TEST_ROOT,
                    STR_ID_FM_AUTO_TEST_PASS,
                    IMG_GLOBAL_OK,
                    STR_ID_FM_AUTO_TEST_FAIL,
                    IMG_GLOBAL_BACK,
                    (PU8) EMFMUnicodeDisplayBuf,
                    NULL);

                FM_Autotest_set_key_handlers();
            }
    }
}


/*****************************************************************************
 * FUNCTION
 *  FM_AutoTest_Speaker
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FM_AutoTest_Speaker(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currentTest = FM_TEST_SPEAKER;

    FM_SendStopAudioReq(0);
    Media_Stop();
    LoudSpkTestOn = TRUE;
    FM_SendSetAudioModeReq(AUD_MODE_LOUDSPK);
    /* play 1K tone */
    TONE_SetOutputVolume(255, 0);
    TONE_Play((const L1SP_Tones*)test_tone);

    switch (sequence_counter)
    {
        case 0:
            sequence_counter++;
            StartTimer(FM_AUTO_TEST_COMMNON_TIMER, SPEAKER_DURATION, FM_AutoTest_Speaker);
            ShowCategory7Screen(
                STR_ID_FM_AUTO_TEST_ROOT,
                IMG_ID_FM_AUTO_TEST_ROOT,
                STR_ID_FM_AUTO_TEST_PASS,
                IMG_GLOBAL_OK,
                STR_ID_FM_AUTO_TEST_FAIL,
                IMG_GLOBAL_BACK,
                (U8*) GetString(STR_ID_FM_AUTOTEST_SPEAKER),
                NULL);
            FM_Autotest_set_key_handlers();

            break;
        default:
            sequence_counter = 0;
            StopTimer(FM_AUTO_TEST_COMMNON_TIMER);

            LoudSpkTestOn = FALSE;

            FM_SendSetAudioModeReq(AUD_MODE_NORMAL);
            /* stop 1K tone */
            TONE_Stop();

            {
                FM_Autotest_test_done_USC2string(Tests[FM_AUTOTEST_SPEAKER].name);
                ShowCategory7Screen(
                    STR_ID_FM_AUTO_TEST_RESULT,
                    IMG_ID_FM_AUTO_TEST_ROOT,
                    STR_ID_FM_AUTO_TEST_PASS,
                    IMG_GLOBAL_OK,
                    STR_ID_FM_AUTO_TEST_FAIL,
                    IMG_GLOBAL_BACK,
                    (PU8) EMFMUnicodeDisplayBuf,
                    NULL);

                FM_Autotest_set_key_handlers();
            }
    }
}

/* Lisen 01262005 */


/*****************************************************************************
 * FUNCTION
 *  FM_AutoTest_Double_Speaker
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FM_AutoTest_Double_Speaker(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currentTest = FM_TEST_DOUBLE_SPEAKER;

    FM_SendStopAudioReq(0);
    Media_Stop();
    LoudSpkTestOn = TRUE;
    FM_SendSetAudioModeReq(AUD_MODE_LOUDSPK);
    /* play 1K tone */
    TONE_SetOutputVolume(255, 0);

    /* sequence_counter=0; */
    switch (sequence_counter)
    {
        case 0:
            sequence_counter++;
            TONE_Play((const L1SP_Tones*)test_tone);
            StartTimer(FM_AUTO_TEST_COMMNON_TIMER, SPEAKER_DURATION, FM_AutoTest_Double_Speaker);
            ShowCategory7Screen(
                STR_ID_FM_AUTO_TEST_ROOT,
                IMG_ID_FM_AUTO_TEST_ROOT,
                STR_ID_FM_AUTO_TEST_PASS,
                IMG_GLOBAL_OK,
                STR_ID_FM_AUTO_TEST_FAIL,
                IMG_GLOBAL_BACK,
                (U8*) GetString(STR_ID_FM_AUTOTEST_LEFT_SPEAKER),
                NULL);

            FM_Autotest_set_key_handlers();

            break;
        case 1:
            sequence_counter++;
            StartTimer(FM_AUTO_TEST_COMMNON_TIMER, 1000, FM_AutoTest_Double_Speaker);
            ShowCategory7Screen(
                STR_ID_FM_AUTO_TEST_ROOT,
                IMG_ID_FM_AUTO_TEST_ROOT,
                STR_ID_FM_AUTO_TEST_PASS,
                IMG_GLOBAL_OK,
                STR_ID_FM_AUTO_TEST_FAIL,
                IMG_GLOBAL_BACK,
                (U8*) GetString(STR_ID_FM_AUTO_TEST_STOP),
                NULL);
            FM_Autotest_set_key_handlers();
            TONE_Stop();
            break;
        case 2:
            sequence_counter++;
            TONE_Play((const L1SP_Tones*)test_tone);
            StartTimer(FM_AUTO_TEST_COMMNON_TIMER, SPEAKER_DURATION, FM_AutoTest_Double_Speaker);
            ShowCategory7Screen(
                STR_ID_FM_AUTO_TEST_ROOT,
                IMG_ID_FM_AUTO_TEST_ROOT,
                STR_ID_FM_AUTO_TEST_PASS,
                IMG_GLOBAL_OK,
                STR_ID_FM_AUTO_TEST_FAIL,
                IMG_GLOBAL_BACK,
                (U8*) GetString(STR_ID_FM_AUTOTEST_RIGHT_SPEAKER),
                NULL);
            FM_Autotest_set_key_handlers();
            /* TONE_Stop(); */
            break;
        default:
            sequence_counter = 0;
            StopTimer(FM_AUTO_TEST_COMMNON_TIMER);

            LoudSpkTestOn = FALSE;

            FM_SendSetAudioModeReq(AUD_MODE_NORMAL);
            /* stop 1K tone */
            TONE_Stop();

            {
                FM_Autotest_test_done_USC2string(Tests[FM_AUTOTEST_DOUBLE_SPEAKER].name);
                ShowCategory7Screen(
                    STR_ID_FM_AUTO_TEST_RESULT,
                    IMG_ID_FM_AUTO_TEST_ROOT,
                    STR_ID_FM_AUTO_TEST_PASS,
                    IMG_GLOBAL_OK,
                    STR_ID_FM_AUTO_TEST_FAIL,
                    IMG_GLOBAL_BACK,
                    (PU8) EMFMUnicodeDisplayBuf,
                    NULL);

                FM_Autotest_set_key_handlers();
            }
    }
}


/*****************************************************************************
 * FUNCTION
 *  FM_AutoTest_Headset
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FM_AutoTest_Headset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currentTest = FM_TEST_HEADSET;

    FM_SendStopAudioReq(0);
    Media_Stop();
    HeadsetTestOn = TRUE;
    FM_SendSetAudioModeReq(AUD_MODE_HEADSET);
    /* open loopback */
    kal_sleep_task(kal_milli_secs_to_ticks(200));
    custom_em_set_loopback(TRUE);

    switch (sequence_counter)
    {
        case 0:
            sequence_counter++;
            StartTimer(FM_AUTO_TEST_COMMNON_TIMER, HEADSET_DURATION, FM_AutoTest_Headset);
            ShowCategory7Screen(
                STR_ID_FM_AUTO_TEST_ROOT,
                IMG_ID_FM_AUTO_TEST_ROOT,
                STR_ID_FM_AUTO_TEST_PASS,
                IMG_GLOBAL_OK,
                STR_ID_FM_AUTO_TEST_FAIL,
                IMG_GLOBAL_BACK,
                (U8*) GetString(STR_ID_FM_AUTOTEST_HEADSET),
                NULL);
            FM_Autotest_set_key_handlers();

            break;
        default:
            sequence_counter = 0;
            StopTimer(FM_AUTO_TEST_COMMNON_TIMER);

            HeadsetTestOn = FALSE;

            /* set headset mode */
            FM_SendSetAudioModeReq(AUD_MODE_NORMAL);
            /* close loopback */
            kal_sleep_task(kal_milli_secs_to_ticks(200));
            custom_em_set_loopback(FALSE);

            {
                FM_Autotest_test_done_USC2string(Tests[FM_AUTOTEST_HEADSET].name);
                ShowCategory7Screen(
                    STR_ID_FM_AUTO_TEST_RESULT,
                    IMG_ID_FM_AUTO_TEST_ROOT,
                    STR_ID_FM_AUTO_TEST_PASS,
                    IMG_GLOBAL_OK,
                    STR_ID_FM_AUTO_TEST_FAIL,
                    IMG_GLOBAL_BACK,
                    (PU8) EMFMUnicodeDisplayBuf,
                    NULL);

                FM_Autotest_set_key_handlers();
            }
    }
}


#if defined(DOUBLE_BATTERY_SUPPORT)
//Huyanwei Add It 

extern const kal_uint8 ADC6_M_BATT ;
extern const kal_uint8 ADC4_S_BATT ;

extern kal_uint8 ExistSubBattery();
kal_uint16 g_adc_value_begin = 0;
kal_uint16 g_adc_value_end    = 0;
kal_int16   g_adc_alue_result = 0 ;
kal_uint32 g_adc_data = 0;

void FM_AutoTest_ADC_Step_End(void)
{	
#ifndef WIN32
       S16 ErrCode = 0 ;
       kal_uint8 i = 0 ;
       kal_uint8 nBattery = ADC4_S_BATT ;

#if defined(NOKE_DEBUG)
       noke_dbg_printf("\r FM_AutoTest_ADC_Step_End ...\n");
#endif
	if(ExistSubBattery() == 1)
	{
		nBattery = ADC4_S_BATT ;
	}
	else
	{
		nBattery = ADC6_M_BATT ;
	}

	g_adc_value_end = ADC_GetData(nBattery);
	while (((g_adc_value_end < 0)  ||  (g_adc_value_end > 1024)) && (i < 3) )
	{
		g_adc_value_end = ADC_GetData(nBattery);
		i++;
	}

	g_adc_alue_result = (g_adc_value_end-g_adc_value_begin);	

	if( g_adc_alue_result <= 0)
	{
		sprintf((S8*) EMFMAsciiDisplayBuf, "Error!!!\r\n");
		AnsiiToUnicodeString(EMFMUnicodeDisplayBuf, (S8*) EMFMAsciiDisplayBuf);
		ShowCategory7Screen(
		STR_ID_FM_AUTO_TEST_ROOT,
		IMG_ID_FM_AUTO_TEST_ROOT,
		STR_ID_FM_AUTO_TEST_FAIL,
		IMG_GLOBAL_OK,
		STR_ID_FM_AUTO_TEST_REPORT,
		IMG_GLOBAL_BACK,
		(PU8) EMFMUnicodeDisplayBuf,
		NULL);		
	}
	else
	{
		sprintf((S8*) EMFMAsciiDisplayBuf, "OK !!!\r\n");
		AnsiiToUnicodeString(EMFMUnicodeDisplayBuf, (S8*) EMFMAsciiDisplayBuf);

#if defined(NOKE_DEBUG)
		noke_dbg_printf("\r Begin:%ld ,End :%ld\n", g_adc_value_begin , g_adc_value_end);
#endif
		g_adc_data= ( g_adc_value_begin << 16) | g_adc_value_end ;
		WriteRecord(NVRAM_ADC_LID, 1, (void *)&g_adc_data, NVRAM_ADC_SIZE, &ErrCode);

		ShowCategory7Screen(
		STR_ID_FM_AUTO_TEST_ROOT,
		IMG_ID_FM_AUTO_TEST_ROOT,
		STR_ID_FM_AUTO_TEST_PASS,
		IMG_GLOBAL_OK,
		STR_ID_FM_AUTO_TEST_REPORT,
		IMG_GLOBAL_BACK,
		(PU8) EMFMUnicodeDisplayBuf,
		NULL);
	}


	SetKeyHandler(FM_ReTest, KEY_SEND, KEY_EVENT_DOWN);
	PowerAndEndKeyHandler();
	SetLeftSoftkeyFunction(FM_Handle_Pass_Key_Press, KEY_EVENT_UP);
	SetRightSoftkeyFunction(FM_Handle_Fail_Key_Press, KEY_EVENT_UP);
	#endif
}



void FM_AutoTest_ADC_Step_Begin(void)
{
	#ifndef WIN32
        kal_uint8 i = 0 ;
        kal_uint8 nBattery = ADC4_S_BATT ;
		
#if defined(NOKE_DEBUG)		
	noke_dbg_printf("\r FM_AutoTest_ADC_Step_Begin ...\n");
#endif

	if(ExistSubBattery() == 1)
	{
		nBattery = ADC4_S_BATT ;
	}
	else
	{
		nBattery = ADC6_M_BATT ;
	}
	
	g_adc_value_begin = ADC_GetData(nBattery);
	while (((g_adc_value_begin < 0)  ||  (g_adc_value_begin > 1024)) && (i < 3) )
	{
		g_adc_value_begin = ADC_GetData(nBattery);
		i++;
	}

	
	sprintf((S8*) EMFMAsciiDisplayBuf, "\r\nPlease set battery Level Value: 4.2V \r\n");
        AnsiiToUnicodeString(EMFMUnicodeDisplayBuf, (S8*) EMFMAsciiDisplayBuf);
			
        ShowCategory7Screen(
        STR_ID_FM_AUTO_TEST_ROOT,
        IMG_ID_FM_AUTO_TEST_ROOT,
        STR_ID_FM_AUTO_TEST_START,
        IMG_GLOBAL_OK,
        STR_ID_FM_AUTO_TEST_REPORT,
        IMG_GLOBAL_BACK,
        (PU8) EMFMUnicodeDisplayBuf,
        NULL);
		
	SetKeyHandler(FM_ReTest, KEY_SEND, KEY_EVENT_DOWN);
        PowerAndEndKeyHandler();
        SetLeftSoftkeyFunction(FM_AutoTest_ADC_Step_End, KEY_EVENT_UP);
        SetRightSoftkeyFunction(FM_Handle_Fail_Key_Press, KEY_EVENT_UP);
	#endif
}


//Huyanwei Add It For ADC
void FM_AutoTest_ADC(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef MMI_ON_WIN32
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	currentTest = FM_TEST_DOUBLE_BATTERY; 
#if defined(NOKE_DEBUG)
	noke_dbg_printf("\r FM_AutoTest_ADC ...\n");
#endif
	sprintf((S8*) EMFMAsciiDisplayBuf, "\r\nPlease set battery Level Value: 3.4V \r\n");
        AnsiiToUnicodeString(EMFMUnicodeDisplayBuf, (S8*) EMFMAsciiDisplayBuf);
			
        ShowCategory7Screen(
        STR_ID_FM_AUTO_TEST_ROOT,
        IMG_ID_FM_AUTO_TEST_ROOT,
        STR_ID_FM_AUTO_TEST_START,
        IMG_GLOBAL_OK,
        STR_ID_FM_AUTO_TEST_REPORT,
        IMG_GLOBAL_BACK,
        (PU8) EMFMUnicodeDisplayBuf,
        NULL);
	
    SetKeyHandler(FM_ReTest, KEY_SEND, KEY_EVENT_DOWN);
    PowerAndEndKeyHandler();
    SetLeftSoftkeyFunction(FM_AutoTest_ADC_Step_Begin, KEY_EVENT_UP);
    SetRightSoftkeyFunction(FM_Handle_Fail_Key_Press, KEY_EVENT_UP);
	#endif
}
#endif


/*****************************************************************************
 * FUNCTION
 *  FM_AutoTest_VIB
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FM_AutoTest_VIB(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currentTest = FM_TEST_VIB;


    switch (sequence_counter)
    {
        case 0:
            sequence_counter++;
	#if defined(__VIBRATOR_TONE_SUPPORT__)
	     VibratorOn();	
	#else
            FM_SetGpioReq(GPIO_DEV_VIBRATOR, VIBRATOR_ON);
       #endif
            StartTimer(FM_AUTO_TEST_COMMNON_TIMER, VIB_DURATION, FM_AutoTest_VIB);
            ShowCategory7Screen(
                STR_ID_FM_AUTO_TEST_ROOT,
                IMG_ID_FM_AUTO_TEST_ROOT,
                STR_ID_FM_AUTO_TEST_PASS,
                IMG_GLOBAL_OK,
                STR_ID_FM_AUTO_TEST_FAIL,
                IMG_GLOBAL_BACK,
                (U8*) GetString(STR_ID_FM_AUTOTEST_VIB),
                NULL);
            FM_Autotest_set_key_handlers();

            break;
        case 1:
            sequence_counter++;
	#if defined(__VIBRATOR_TONE_SUPPORT__)
            VibratorOff();
	#else
            FM_SetGpioReq(GPIO_DEV_VIBRATOR, VIBRATOR_OFF);
       #endif
            StartTimer(FM_AUTO_TEST_COMMNON_TIMER, VIB_DURATION, FM_AutoTest_VIB);
            ShowCategory7Screen(
                STR_ID_FM_AUTO_TEST_ROOT,
                IMG_ID_FM_AUTO_TEST_ROOT,
                STR_ID_FM_AUTO_TEST_PASS,
                IMG_GLOBAL_OK,
                STR_ID_FM_AUTO_TEST_FAIL,
                IMG_GLOBAL_BACK,
                (U8*) NULL,
                NULL);
            FM_Autotest_set_key_handlers();

            break;
        case 2:
            sequence_counter++;
	#if defined(__VIBRATOR_TONE_SUPPORT__)
	     VibratorOn();	
	#else
            FM_SetGpioReq(GPIO_DEV_VIBRATOR, VIBRATOR_ON);
       #endif
            StartTimer(FM_AUTO_TEST_COMMNON_TIMER, VIB_DURATION, FM_AutoTest_VIB);
            ShowCategory7Screen(
                STR_ID_FM_AUTO_TEST_ROOT,
                IMG_ID_FM_AUTO_TEST_ROOT,
                STR_ID_FM_AUTO_TEST_PASS,
                IMG_GLOBAL_OK,
                STR_ID_FM_AUTO_TEST_FAIL,
                IMG_GLOBAL_BACK,
                (U8*) GetString(STR_ID_FM_AUTOTEST_VIB),
                NULL);
            FM_Autotest_set_key_handlers();

            break;
        default:
            sequence_counter = 0;
            StopTimer(FM_AUTO_TEST_COMMNON_TIMER);
	#if defined(__VIBRATOR_TONE_SUPPORT__)
            VibratorOff();
	#else		
            FM_SetGpioReq(GPIO_DEV_VIBRATOR, VIBRATOR_OFF);
	#endif
            {
                FM_Autotest_test_done_USC2string(Tests[FM_AUTOTEST_VIB].name);
                ShowCategory7Screen(
                    STR_ID_FM_AUTO_TEST_RESULT,
                    IMG_ID_FM_AUTO_TEST_ROOT,
                    STR_ID_FM_AUTO_TEST_PASS,
                    IMG_GLOBAL_OK,
                    STR_ID_FM_AUTO_TEST_FAIL,
                    IMG_GLOBAL_BACK,
                    (PU8) EMFMUnicodeDisplayBuf,
                    NULL);

                FM_Autotest_set_key_handlers();
            }
    }
}


/*****************************************************************************
 * FUNCTION
 *  FM_AutoTestUpdateADCHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void FM_AutoTestUpdateADCHdlr(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    double vbat, temp, curr;
    mmi_eq_adc_all_channel_ind_struct *adc_struct = (mmi_eq_adc_all_channel_ind_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vbat = ((double)adc_struct->vbat) / 1000000.0;
    temp = ((double)adc_struct->bat_temp) / 1000.0;
    curr = ((double)adc_struct->charge_current) / 1000000.0;

    if (vbat < VBAT_LOWER_BOUNDARY || vbat > VBAT_UPPER_BOUNDARY)
    {
        sprintf(
            (S8*) EMFMAsciiDisplayBuf,
            "%s%4.2f V\nValid Range:\n%4.2f V - %4.2f V\n\nsuggest: FAIL",
            "vbat=",
            vbat,
            VBAT_LOWER_BOUNDARY,
            VBAT_UPPER_BOUNDARY);
    }
    else if ((adc_mode == FM_ADC_BATTERY) && (temp < TEMP_LOWER_BOUNDARY || temp > TEMP_UPPER_BOUNDARY))
    {
        sprintf(
            (S8*) EMFMAsciiDisplayBuf,
            "%s%4.2f C\nValid Range:\n%d C - %d C\n\nsuggest: FAIL",
            "temp=",
            temp,
            TEMP_LOWER_BOUNDARY,
            TEMP_UPPER_BOUNDARY);
    }
    else if ((adc_mode == FM_ADC_CHARGER) && (curr < CURR__LOWER_BOUNDARY))
    {
        sprintf(
            (S8*) EMFMAsciiDisplayBuf,
            "%s%4.2f A\nMust be at least %4.2f A\n\nsuggest: FAIL",
            "current=",
            curr,
            CURR__LOWER_BOUNDARY);
    }
    else
    {
        if (adc_mode == FM_ADC_BATTERY)
        {
            sprintf((S8*) EMFMAsciiDisplayBuf, "BATTERY OK!");
        }
        else
        {
            sprintf((S8*) EMFMAsciiDisplayBuf, "CHARGER OK!");
        }
    }

    mmi_asc_to_ucs2((PS8) EMFMUnicodeDisplayBuf, (S8*) EMFMAsciiDisplayBuf);
    ShowCategory7Screen(
        STR_ID_FM_AUTO_TEST_RESULT,
        IMG_ID_FM_AUTO_TEST_ROOT,
        STR_ID_FM_AUTO_TEST_PASS,
        IMG_GLOBAL_OK,
        STR_ID_FM_AUTO_TEST_FAIL,
        IMG_GLOBAL_BACK,
        (PU8) EMFMUnicodeDisplayBuf,
        NULL);

    FM_Autotest_set_key_handlers();

    SetProtocolEventHandler(NULL, MSG_ID_MMI_EQ_ADC_ALL_CHANNEL_IND);
    SetProtocolEventHandler(BatteryStatusRsp, PRT_BATTERY_STATUS_IND);
    FM_SendADCStopReq();
}


/*****************************************************************************
 * FUNCTION
 *  FM_AutoTest_Battery
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FM_AutoTest_Battery(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currentTest = FM_TEST_BATTERY;
    adc_mode = FM_ADC_BATTERY;


    if (sequence_counter == 0)
    {
        SetProtocolEventHandler(FM_AutoTestUpdateADCHdlr, MSG_ID_MMI_EQ_ADC_ALL_CHANNEL_IND);
        SetProtocolEventHandler(EMFMBatteryStatusMsgHandler, PRT_BATTERY_STATUS_IND);
        FM_SendADCStartReq();
    }

    switch (sequence_counter)
    {
        case 0:
            sequence_counter++;
            StartTimer(FM_AUTO_TEST_COMMNON_TIMER, ADC_DURATION, FM_AutoTest_Battery);
            break;
        default:
            sequence_counter = 0;
            StopTimer(FM_AUTO_TEST_COMMNON_TIMER);
    }
}


/*****************************************************************************
 * FUNCTION
 *  FM_AutoTest_Melody
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FM_AutoTest_Melody(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currentTest = FM_TEST_MELODY;


    switch (sequence_counter)
    {
        case 0:
            sequence_counter++;
            RingToneTestOn = TRUE;
            Media_SetOutputVolume(255, 0);
            /* stop MIDI */
            FM_SendStopAudioReq(0);
            /* play MIDI_1 */
            FM_SendPlayAudioReq(0);

            StartTimer(FM_AUTO_TEST_COMMNON_TIMER, MELODY_DURATION, FM_AutoTest_Melody);
            ShowCategory7Screen(
                STR_ID_FM_AUTO_TEST_ROOT,
                IMG_ID_FM_AUTO_TEST_ROOT,
                STR_ID_FM_AUTO_TEST_PASS,
                IMG_GLOBAL_OK,
                STR_ID_FM_AUTO_TEST_FAIL,
                IMG_GLOBAL_BACK,
                (U8*) GetString(STR_ID_FM_AUTOTEST_MELODY),
                NULL);

            FM_Autotest_set_key_handlers();

            break;
        default:
            sequence_counter = 0;
            StopTimer(FM_AUTO_TEST_COMMNON_TIMER);

            RingToneTestOn = FALSE;
            FM_SendSetAudioModeReq(AUD_MODE_NORMAL);
            /* stop MIDI */
            FM_SendStopAudioReq(0);

            {
                FM_Autotest_test_done_USC2string(Tests[FM_AUTOTEST_MELODY].name);
                ShowCategory7Screen(
                    STR_ID_FM_AUTO_TEST_RESULT,
                    IMG_ID_FM_AUTO_TEST_ROOT,
                    STR_ID_FM_AUTO_TEST_PASS,
                    IMG_GLOBAL_OK,
                    STR_ID_FM_AUTO_TEST_FAIL,
                    IMG_GLOBAL_BACK,
                    (PU8) EMFMUnicodeDisplayBuf,
                    NULL);

                FM_Autotest_set_key_handlers();
            }
    }
}


/*****************************************************************************
 * FUNCTION
 *  FM_AutoTest_Charger
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FM_AutoTest_Charger(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currentTest = FM_TEST_CHARGER;
    adc_mode = FM_ADC_CHARGER;

    if (sequence_counter == 0)
    {
        SetProtocolEventHandler(FM_AutoTestUpdateADCHdlr, MSG_ID_MMI_EQ_ADC_ALL_CHANNEL_IND);
        SetProtocolEventHandler(EMFMBatteryStatusMsgHandler, PRT_BATTERY_STATUS_IND);
        FM_SendADCStartReq();
    }

    switch (sequence_counter)
    {
        case 0:
            sequence_counter++;
            StartTimer(FM_AUTO_TEST_COMMNON_TIMER, ADC_DURATION, FM_AutoTest_Battery);
            break;
        default:
            sequence_counter = 0;
            StopTimer(FM_AUTO_TEST_COMMNON_TIMER);
    }
}


/*****************************************************************************
 * FUNCTION
 *  FM_AutoTest_NAND
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FM_AutoTest_NAND(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currentTest = FM_TEST_NAND;


    switch (sequence_counter)
    {
        case 0:
            sequence_counter++;
            StartTimer(FM_AUTO_TEST_COMMNON_TIMER, 3000, FM_AutoTest_NAND);
            ShowCategory7Screen(
                STR_ID_FM_AUTO_TEST_ROOT,
                IMG_ID_FM_AUTO_TEST_ROOT,
                STR_ID_FM_AUTO_TEST_PASS,
                IMG_GLOBAL_OK,
                STR_ID_FM_AUTO_TEST_FAIL,
                IMG_GLOBAL_BACK,
                (U8*) GetString(STR_ID_FM_AUTOTEST_NAND),
                NULL);
            FM_Autotest_set_key_handlers();

            break;
        case 1:
            sequence_counter++;
            StartTimer(FM_AUTO_TEST_COMMNON_TIMER, 2000, FM_AutoTest_NAND);
            EntryFMNandFlashMenu();
            FM_Autotest_set_key_handlers();
            break;

        default:
            sequence_counter = 0;
            StopTimer(FM_AUTO_TEST_COMMNON_TIMER);
            FM_Autotest_test_done_USC2string(Tests[FM_AUTOTEST_NAND].name);
            ShowCategory7Screen(
                STR_ID_FM_AUTO_TEST_RESULT,
                IMG_ID_FM_AUTO_TEST_ROOT,
                STR_ID_FM_AUTO_TEST_PASS,
                IMG_GLOBAL_OK,
                STR_ID_FM_AUTO_TEST_FAIL,
                IMG_GLOBAL_BACK,
                (PU8) EMFMUnicodeDisplayBuf,
                NULL);

            FM_Autotest_set_key_handlers();
    }
}


/*****************************************************************************
 * FUNCTION
 *  FM_AutoTest_UART
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FM_AutoTest_UART(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currentTest = FM_TEST_UART;


    switch (sequence_counter)
    {
        case 0:
            sequence_counter++;
            StartTimer(FM_AUTO_TEST_COMMNON_TIMER, 1000, FM_AutoTest_UART);
            ShowCategory7Screen(
                STR_ID_FM_AUTO_TEST_ROOT,
                IMG_ID_FM_AUTO_TEST_ROOT,
                STR_ID_FM_AUTO_TEST_PASS,
                IMG_GLOBAL_OK,
                STR_ID_FM_AUTO_TEST_FAIL,
                IMG_GLOBAL_BACK,
                (U8*) GetString(STR_ID_FM_AUTOTEST_UART),
                NULL);
            FM_Autotest_set_key_handlers();
            break;
        case 1:
            sequence_counter++;
            StartTimer(FM_AUTO_TEST_COMMNON_TIMER, 2000, FM_AutoTest_UART);
            EntryFMUARTMenu();
            FM_Autotest_set_key_handlers();
            break;

        default:
            sequence_counter = 0;
            StopTimer(FM_AUTO_TEST_COMMNON_TIMER);
            FM_Autotest_test_done_USC2string(Tests[FM_AUTOTEST_UART].name);
            ShowCategory7Screen(
                STR_ID_FM_AUTO_TEST_RESULT,
                IMG_ID_FM_AUTO_TEST_ROOT,
                STR_ID_FM_AUTO_TEST_PASS,
                IMG_GLOBAL_OK,
                STR_ID_FM_AUTO_TEST_FAIL,
                IMG_GLOBAL_BACK,
                (PU8) EMFMUnicodeDisplayBuf,
                NULL);

            FM_Autotest_set_key_handlers();
    }
}

/* Lisen 01262005 */


/*****************************************************************************
 * FUNCTION
 *  EntryFMCameraTransientScreen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void EntryFMCameraTransientScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NeedExitFunc = FALSE;   /* discard auto test history */
    EntryNewScreen(SCR_ID_FM_AUTO_TEST_START, ExitFMAutoTestStart, NULL, NULL);
    NeedExitFunc = TRUE;
    guiBuffer = GetCurrGuiBuffer(SCR_ID_FM_AUTO_TEST_START);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    FM_Autotest_test_done_USC2string(Tests[FM_AUTOTEST_CAMERA].name);
    ShowCategory7Screen(
        STR_ID_FM_AUTO_TEST_RESULT,
        IMG_ID_FM_AUTO_TEST_ROOT,
        STR_ID_FM_AUTO_TEST_PASS,
        IMG_GLOBAL_OK,
        STR_ID_FM_AUTO_TEST_FAIL,
        IMG_GLOBAL_BACK,
        (PU8) EMFMUnicodeDisplayBuf,
        NULL);

    FM_Autotest_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  FM_AutoTest_CAMERA
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FM_AutoTest_CAMERA(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currentTest = FM_TEST_CAMERA;

#if defined(__FM_CAMERA_PREVIEW__)

    switch (sequence_counter)
    {
        case 0:
            sequence_counter++;
            mmi_fm_camera_entry_preview_screen();
            StartTimer(FM_AUTO_TEST_COMMNON_TIMER, CAMERA_DURATION, FM_AutoTest_CAMERA);

            break;
        default:
            sequence_counter = 0;
            StopTimer(FM_AUTO_TEST_COMMNON_TIMER);

            EntryFMCameraTransientScreen();
    }
#else /* defined(__FM_CAMERA_PREVIEW__) */ 
    {
        FM_Autotest_test_done_USC2string(Tests[FM_AUTOTEST_CAMERA].name);
        ShowCategory7Screen(
            STR_ID_FM_AUTO_TEST_RESULT,
            IMG_ID_FM_AUTO_TEST_ROOT,
            STR_ID_FM_AUTO_TEST_PASS,
            IMG_GLOBAL_OK,
            STR_ID_FM_AUTO_TEST_FAIL,
            IMG_GLOBAL_BACK,
            (PU8) EMFMUnicodeDisplayBuf,
            NULL);

        FM_Autotest_set_key_handlers();
    }
#endif /* defined(__FM_CAMERA_PREVIEW__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  FM_AutoTest_MemoryCard
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FM_AutoTest_MemoryCard(void)
{
#if defined(__MSDC_MS__) || defined(__MSDC_SD_MMC__) || defined(__MSDC_MSPRO__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type text1[32];
    U8 u8text[32];
#endif /* defined(__MSDC_MS__) || defined(__MSDC_SD_MMC__) || defined(__MSDC_MSPRO__) */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currentTest = FM_TEST_MEMORYCARD;

    EntryNewScreen(SCR_ID_FM_MEMORY_CARD, NULL, FM_AutoTest_MemoryCard, NULL);

#if defined(__MSDC_MS__) || defined(__MSDC_SD_MMC__) || defined(__MSDC_MSPRO__)
    if (sequence_counter < 10)
    {
        if (FM_Card_Status.present == TRUE)
        {
            sequence_counter = 10;
            switch (FM_Card_Status.type)
            {
                case MS_CARD:
                    mmi_asc_to_ucs2((S8*) CardType, "MS_CARD.");
                    break;
                case SD_CARD:
                    mmi_asc_to_ucs2((S8*) CardType, "SD_CARD.");
                    break;
                case MMC_CARD:
                    mmi_asc_to_ucs2((S8*) CardType, "MMC_CARD.");
                    break;
                default:
                    mmi_asc_to_ucs2((S8*) CardType, "Error!!!");
            }
            StartTimer(FM_AUTO_TEST_COMMNON_TIMER, 300, FM_AutoTest_MemoryCard);
        }
        else
        {
            sequence_counter++;

            if (Card_Response_Sent == FALSE)
            {
                FM_MemoryCardReq();
            }

            sprintf(
                (S8*) u8text,
                "\nPlease Insert Memory Card....%d",
                (MEMORYCARD_DURATION / 1000) - sequence_counter);
            mmi_asc_to_ucs2((S8*) text1, (S8*) u8text);
            ShowCategory205Screen(
                (U16) STR_ID_FM_AUTO_TEST_PASS,
                0,
                (U16) STR_ID_FM_AUTO_TEST_FAIL,
                0,
                text1,
                IMG_ID_FM_MEMORY_CARD,
                NULL);
            FM_Autotest_set_key_handlers();

            StartTimer(FM_AUTO_TEST_COMMNON_TIMER, 1000, FM_AutoTest_MemoryCard);
            if ((sequence_counter >= (MEMORYCARD_DURATION / 1000) - 1) && FM_Card_Status.present == FALSE)
            {   /* No Card inserted. */
                mmi_asc_to_ucs2((S8*) CardType, "No Card.");
                StartTimer(FM_AUTO_TEST_COMMNON_TIMER, 300, FM_AutoTest_MemoryCard);
                sequence_counter++;
            }
        }
    }
    else
#endif /* defined(__MSDC_MS__) || defined(__MSDC_SD_MMC__) || defined(__MSDC_MSPRO__) */ 
    {
        sequence_counter = 0;
        StopTimer(FM_AUTO_TEST_COMMNON_TIMER);
        FM_Autotest_test_done_USC2string(Tests[FM_AUTOTEST_MEMORYCARD].name);
        ShowCategory7Screen(
            STR_ID_FM_AUTO_TEST_RESULT,
            IMG_ID_FM_AUTO_TEST_ROOT,
            STR_ID_FM_AUTO_TEST_PASS,
            IMG_GLOBAL_OK,
            STR_ID_FM_AUTO_TEST_FAIL,
            IMG_GLOBAL_BACK,
            (PU8) EMFMUnicodeDisplayBuf,
            NULL);

        FM_Autotest_set_key_handlers();
    }
}


/*****************************************************************************
 * FUNCTION
 *  FM_Handle_RTC_Stop_Key_Press
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void FM_Handle_RTC_Stop_Key_Press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sequence_counter = 0;
    StopTimer(FM_AUTO_TEST_COMMNON_TIMER);
    WriteCurrentTimeToNVRAM();
    EntryFMMenuAutoTest();
}


/*****************************************************************************
 * FUNCTION
 *  FM_ManualTest_RTC
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FM_ManualTest_RTC(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 uniBuf[240];
    U8 AsciiBuf[120];
    U16 msec = 1000;
    U16 sec = 2;

    MYTIME t;
    rtc_format_struct currtime;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sequence_counter < sec)
    {
        sequence_counter++;
        StartTimer(FM_AUTO_TEST_COMMNON_TIMER, msec, FM_ManualTest_RTC);

        DTGetRTCTime(&t);

        currtime.rtc_sec = t.nSec;
        currtime.rtc_min = t.nMin;
        currtime.rtc_hour = t.nHour;
        currtime.rtc_day = t.nDay;
        currtime.rtc_mon = t.nMonth;
        currtime.rtc_wday = 0;
        currtime.rtc_year = (kal_uint8) (t.nYear - 2000);

        sprintf(
            (S8*) AsciiBuf,
            "Last RTC:\n%d.%d.%d %02d:%02d:%02d\nCurrent RTC:\n%d.%d.%d %02d:%02d:%02d\n\npoweroff in %d sec",
            2000 + myclocktime.rtc_year,
            myclocktime.rtc_mon,
            myclocktime.rtc_day,
            myclocktime.rtc_hour,
            myclocktime.rtc_min,
            myclocktime.rtc_sec,
            2000 + currtime.rtc_year,
            currtime.rtc_mon,
            currtime.rtc_day,
            currtime.rtc_hour,
            currtime.rtc_min,
            currtime.rtc_sec,
            sec - sequence_counter);

        mmi_asc_to_ucs2(uniBuf, (S8*) AsciiBuf);
        ShowCategory7Screen(
            STR_ID_FM_AUTO_TEST_ROOT,
            IMG_ID_FM_AUTO_TEST_ROOT,
            (U16) NULL,
            IMG_GLOBAL_OK,
            STR_ID_FM_AUTO_TEST_STOP,
            IMG_GLOBAL_BACK,
            (PU8) uniBuf,
            NULL);

        SetRightSoftkeyFunction(FM_Handle_RTC_Stop_Key_Press, KEY_EVENT_UP);
    }
    else
    {
        sequence_counter = 0;
        StopTimer(FM_AUTO_TEST_COMMNON_TIMER);

        WriteCurrentTimeToNVRAM();
        gFactoryAlarm = 1;
        FactorySetAlarm(3);
    }

}


/*****************************************************************************
 * FUNCTION
 *  FM_InitAutoTest
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FM_InitAutoTest(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadSettingsFromNVRAM();
    ReadTestResultFromNVRAM();
    currTestItem = 0;
    for (i = 0; i < MAX_AUTO_TEST_ITEMS; i++)
    {
        TestExecuted[i] = FALSE;
    }
    InitFactoryModeSetting();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_auto_test_delete_history_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  param       [?]     
 * RETURNS
 *  
 *****************************************************************************/
U8 mmi_fm_auto_test_delete_history_hdlr(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gCurrentMode = NORMAL_MODE;
    mdi_switch_device_ownership(MOD_MMI, MDI_DEVICE_AUDIO | MDI_DEVICE_CAMER | MDI_DEVICE_VIDEO);
    mdi_audio_start_background_timer();
    mdi_audio_resume_background_play();
    StartLEDPatternBackGround();
    mmi_profiles_restore_activated_profile();
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  EntryFMMenuAutoTest
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryFMMenuAutoTest(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S8 display_str[30];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_FM_AUTO_TEST_ROOT, ExitFMMenuAutoTest, NULL, NULL);

    autoTestMode = 1;

    guiBuffer = GetCurrGuiBuffer(SCR_ID_FM_AUTO_TEST_ROOT);
    SetParentHandler(MENU_ID_FM_AUTO_TEST_ROOT);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    mmi_ucs2cpy((S8*) EMFMUnicodeDisplayBuf, GetString(STR_ID_FM_AUTO_TEST_ROOT));

    mmi_asc_to_ucs2((S8*) display_str, "\n\n\n\nEndkey: ");

    mmi_ucs2cat((S8*) EMFMUnicodeDisplayBuf, (S8*) display_str);

    mmi_ucs2cat((S8*) EMFMUnicodeDisplayBuf, GetString(STR_ID_FM_AUTO_TEST_EXIT));

    ShowCategory7Screen(
        STR_ID_FM_AUTO_TEST_ROOT,
        IMG_ID_FM_AUTO_TEST_ROOT,
        STR_ID_FM_AUTO_TEST_START,
        IMG_GLOBAL_OK,
        STR_ID_FM_AUTO_TEST_REPORT,
        IMG_GLOBAL_BACK,
        (PU8) EMFMUnicodeDisplayBuf,
        guiBuffer);

    SetLeftSoftkeyFunction(EntryFMAutoTestStart, KEY_EVENT_UP);
    SetRightSoftkeyFunction(EntryFMAutoTestReport, KEY_EVENT_UP);

    FM_InitAutoTest();
    SetDelScrnIDCallbackHandler(SCR_ID_FM_AUTO_TEST_ROOT, (HistoryDelCBPtr) mmi_fm_auto_test_delete_history_hdlr);
}


/*****************************************************************************
 * FUNCTION
 *  ExitFMMenuAutoTest
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitFMMenuAutoTest(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history currHistory;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FM_RestoreAudio();

    currHistory.scrnID = SCR_ID_FM_AUTO_TEST_ROOT;
    currHistory.entryFuncPtr = EntryFMMenuAutoTest;
    mmi_ucs2cpy((S8*) currHistory.inputBuffer, (S8*) L"");
    GetCategoryHistory(currHistory.guiBuffer);
    AddHistory(currHistory);
}


/*****************************************************************************
 * FUNCTION
 *  EntryFMAutoTestReport
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryFMAutoTestReport(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 i, passed, failed, untested;
    U8 fail_items[MAX_AUTO_TEST_ITEMS];
    U8 untested_items[MAX_AUTO_TEST_ITEMS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NeedExitFunc = FALSE;
    EntryNewScreen(SCR_ID_FM_AUTO_TEST_REPORT, NULL, EntryFMAutoTestReport, NULL);
    NeedExitFunc = TRUE;
    guiBuffer = GetCurrGuiBuffer(SCR_ID_FM_AUTO_TEST_REPORT);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    for (i = 0, passed = 0, failed = 0, untested = 0; i < gAutoTestListSize; i++)
    {
        if (nvramTestResultArray.result[i] == FM_TEST_UNTESTED)
        {
            untested_items[untested] = (U8) i;
            untested++;
        }
        else if (nvramTestResultArray.result[i] == FM_TEST_FAILED)
        {
            fail_items[failed] = (U8) i;
            failed++;
        }
        else if (nvramTestResultArray.result[i] >= FM_TEST_PASSED)
        {
            passed++;
        }
    }

    if (untested > 0)
    {
        S8 uniBuf[MAX_TEST_STRING_BUF * 2];

        memset(EMFMAsciiDisplayBuf, 0, sizeof(EMFMAsciiDisplayBuf));
        if (untested > 1)
        {
            sprintf((S8*) EMFMAsciiDisplayBuf, "\n\n%d Untested items:\n", untested);
        }
        else
        {
            sprintf((S8*) EMFMAsciiDisplayBuf, "\n\n1 Untested item:\n");
        }

        for (i = 0; i < untested; i++)
        {
            S8 str[3];

            if (i == untested - 1)
            {
                sprintf(str, "%d", 1 + untested_items[i]);
            }
            else
            {
                sprintf(str, "%d-", 1 + untested_items[i]);
            }

            strcat((S8*) EMFMAsciiDisplayBuf, (const S8*)str);
        }

        mmi_asc_to_ucs2((S8*) uniBuf, (S8*) EMFMAsciiDisplayBuf);

        mmi_ucs2cpy((S8*) EMFMUnicodeDisplayBuf, GetString(STR_ID_FM_AUTO_TEST_UNFINISHED));

        mmi_ucs2cat((S8*) EMFMUnicodeDisplayBuf, (S8*) uniBuf);

        ShowCategory7Screen(
            STR_ID_FM_AUTO_TEST_REPORT,
            IMG_ID_FM_AUTO_TEST_ROOT,
            (U16) NULL,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            (PU8) EMFMUnicodeDisplayBuf,
            guiBuffer);

        SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
    else if (failed > 0)
    {
        S8 uniBuf[MAX_TEST_STRING_BUF * 2];

        memset(EMFMAsciiDisplayBuf, 0, sizeof(EMFMAsciiDisplayBuf));
        if (failed > 1)
        {
            sprintf((S8*) EMFMAsciiDisplayBuf, "\n%d Failed items:\n", failed);
        }
        else
        {
            sprintf((S8*) EMFMAsciiDisplayBuf, "\n1 Failed item:\n");
        }

        for (i = 0; i < failed; i++)
        {
            S8 str[3];

            if (i == failed - 1)
            {
                sprintf(str, "%d", 1 + fail_items[i]);
            }
            else
            {
                sprintf(str, "%d-", 1 + fail_items[i]);
            }

            strcat((S8*) EMFMAsciiDisplayBuf, (const S8*)str);
        }

        mmi_asc_to_ucs2((S8*) uniBuf, (S8*) EMFMAsciiDisplayBuf);

        mmi_ucs2cpy((S8*) EMFMUnicodeDisplayBuf, GetString(STR_ID_FM_AUTO_TEST_FAILED));

        mmi_ucs2cat((S8*) EMFMUnicodeDisplayBuf, (S8*) uniBuf);

        ShowCategory7Screen(
            STR_ID_FM_AUTO_TEST_REPORT,
            IMG_ID_FM_AUTO_TEST_ROOT,
            (U16) NULL,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            (PU8) EMFMUnicodeDisplayBuf,
            guiBuffer);

        SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
    else
    {
        ShowCategory7Screen(
            STR_ID_FM_AUTO_TEST_REPORT,
            IMG_ID_FM_AUTO_TEST_ROOT,
            STR_ID_FM_AUTO_TEST_RTC,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            (PU8) GetString(STR_ID_FM_AUTO_TEST_ALLPASSED),
            guiBuffer);

        SetLeftSoftkeyFunction(FM_ManualTest_RTC, KEY_EVENT_UP);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }

}


/*****************************************************************************
 * FUNCTION
 *  EntryFMAutoTestSummary
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryFMAutoTestSummary(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_FM_AUTO_TEST_SUMMARY, NULL, EntryFMAutoTestSummary, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  EntryFMAutoTestResult
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryFMAutoTestResult(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_FM_AUTO_TEST_RESULT, NULL, EntryFMAutoTestResult, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  EntryFMAutoTestStart
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryFMAutoTestStart(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 testitem;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NeedExitFunc = FALSE;   /* discard auto test history */
    EntryNewScreen(SCR_ID_FM_AUTO_TEST_START, ExitFMAutoTestStart, NULL, NULL);
    NeedExitFunc = TRUE;
    guiBuffer = GetCurrGuiBuffer(SCR_ID_FM_AUTO_TEST_START);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* currTestItem++; */

    if (currTestItem == 0)  /* Testing just began, clear all tet results */
    {
        U16 i;

        for (i = 0; i < gAutoTestListSize; i++)
        {
            nvramTestResultArray.result[i] = FM_TEST_UNTESTED;
        }

        ReadTimeFromNVRAM();
    }

    if (currTestItem <= gAutoTestListSize - 1)
    {
        /* Call test item according to the selected order */
        testitem = nvramTestItemArray.priority[currTestItem];

        if (TestExecuted[currTestItem] == FALSE)    /* prevent reentry of the same tests on interrupts */
        {
            /* Execute the test */
            (Tests[testitem].func) ();

            TestExecuted[currTestItem] = TRUE;
        }
        else if (currentTest == FM_TEST_NAND || currentTest == FM_TEST_UART)
        {
            /* Execute the test */
            (Tests[testitem].func) ();
        }
        else
        {
            FM_Autotest_Stop_Test();
            sprintf((S8*) EMFMAsciiDisplayBuf, "Interrupted!!\nPlease re-test\n\nSendkey: ReTest\nEndkey: Exit");
            mmi_asc_to_ucs2(EMFMUnicodeDisplayBuf, (S8*) EMFMAsciiDisplayBuf);
            ShowCategory7Screen(
                STR_ID_FM_AUTO_TEST_ROOT,
                IMG_ID_FM_AUTO_TEST_ROOT,
                STR_ID_FM_AUTO_TEST_PASS,
                IMG_GLOBAL_OK,
                STR_ID_FM_AUTO_TEST_FAIL,
                IMG_GLOBAL_BACK,
                (PU8) EMFMUnicodeDisplayBuf,
                NULL);

            FM_Autotest_set_key_handlers();
        }
    }
    else
    {
        ShowCategory7Screen(
            STR_ID_FM_AUTO_TEST_ROOT,
            IMG_ID_FM_AUTO_TEST_ROOT,
            STR_ID_FM_AUTO_TEST_REPORT,
            IMG_GLOBAL_OK,
            STR_GLOBAL_DONE,
            IMG_GLOBAL_BACK,
            (PU8) GetString(STR_ID_FM_AUTO_TEST_ALLDONE),
            guiBuffer);

        DeleteUptoScrID(SCR_ID_FM_AUTO_TEST_ROOT);

        SetLeftSoftkeyFunction(EntryFMAutoTestReport, KEY_EVENT_UP);
        SetRightSoftkeyFunction(EntryFMMenuAutoTest, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ExitFMAutoTestStart
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitFMAutoTestStart(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NeedExitFunc)
    {
        history currHistory;

        currHistory.scrnID = SCR_ID_FM_AUTO_TEST_START;
        currHistory.entryFuncPtr = EntryFMAutoTestStart;
        mmi_ucs2cpy((S8*) currHistory.inputBuffer, (S8*) L"");
        GetCategoryHistory(currHistory.guiBuffer);
        AddHistory(currHistory);

        StopTimer(FM_AUTO_TEST_COMMNON_TIMER);
    }
}

/*=============== MTBF =============== */


/*****************************************************************************
 * FUNCTION
 *  FM_MTBF
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FM_MTBF(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 Count_ms = FM_MTBF_PERIOD * MTBF_counter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* LCD */
    if ((Count_ms % FM_MTBF_LCD_CYCLE) == 0)
    {
        TurnOnBacklight(0);
        gui_lock_double_buffer();

        switch (MTBF_state_LCD)
        {
            case FM_MTBF_LCD_R:
                FM_HandleInitialColor(255, 0, 0);
                break;
            case FM_MTBF_LCD_G:
                FM_HandleInitialColor(0, 255, 0);
                break;
            case FM_MTBF_LCD_B:
                FM_HandleInitialColor(0, 0, 255);
                break;
            case FM_MTBF_LCD_W:
                FM_HandleInitialColor(255, 255, 255);
                break;
            default:
                ASSERT(0);
        }

        gui_unlock_double_buffer();
        gui_BLT_double_buffer(0, 0, MAIN_LCD_device_width - 1, MAIN_LCD_device_height - 1);

        if (MTBF_state_LCD == FM_MTBF_LCD_END)
        {
            MTBF_state_LCD = FM_MTBF_LCD_START;
        }
        else
        {
            MTBF_state_LCD++;
        }

    }

    /* LED */
    if ((Count_ms % FM_MTBF_LED_CYCLE) == 0)
    {
        FM_SetGpioReq(GPIO_DEV_LED_KEY, LED_LIGHT_LEVEL0);
        FM_SetGpioReq(GPIO_DEV_LED_STATUS_1, LED_LIGHT_LEVEL0);
        FM_SetGpioReq(GPIO_DEV_LED_STATUS_2, LED_LIGHT_LEVEL0);
        FM_SetGpioReq(GPIO_DEV_LED_STATUS_3, LED_LIGHT_LEVEL0);

        switch (MTBF_state_LED)
        {
            case FM_MTBF_LED_KEYPAD:
                FM_SetGpioReq(GPIO_DEV_LED_KEY, LED_LIGHT_LEVEL5);
                break;
            case FM_MTBF_LED_R:
                FM_SetGpioReq(GPIO_DEV_LED_STATUS_1, LED_LIGHT_LEVEL5);
                break;
            case FM_MTBF_LED_G:
                FM_SetGpioReq(GPIO_DEV_LED_STATUS_2, LED_LIGHT_LEVEL5);
                break;
            case FM_MTBF_LED_B:
                FM_SetGpioReq(GPIO_DEV_LED_STATUS_3, LED_LIGHT_LEVEL5);
                break;
            default:
                ASSERT(0);
        }

        if (MTBF_state_LED == FM_MTBF_LED_END)
        {
            MTBF_state_LED = FM_MTBF_LED_START;
        }
        else
        {
            MTBF_state_LED++;
        }
    }

    /* VIB */
    if ((Count_ms % FM_MTBF_VIB_CYCLE) == 0)
    {
        if (MTBF_state_VIB == FM_MTBF_VIB_ON)
        {
            FM_SetGpioReq(GPIO_DEV_VIBRATOR, VIBRATOR_ON);
        }
        else
        {
            FM_SetGpioReq(GPIO_DEV_VIBRATOR, VIBRATOR_OFF);
        }

        if (MTBF_state_VIB == FM_MTBF_VIB_END)
        {
            MTBF_state_VIB = FM_MTBF_VIB_START;
        }
        else
        {
            MTBF_state_VIB++;
        }
    }

    /* Speaker */
    if ((Count_ms % FM_MTBF_SPK_CYCLE) == 0 && AUD_TEST_ON == FM_MTBF_AUD_SPK)
    {
        /* Louk Speaker Mode */
        TONE_Stop();
        kal_sleep_task(20);
        FM_SendSetAudioModeReq(AUD_MODE_LOUDSPK);
        /* TONE_SetOutputDevice(L1SP_LOUD_SPEAKER); */
        TONE_SetOutputVolume(255, 0);
        TONE_Play((const L1SP_Tones*)(SPK_test_tone));

        if (AUD_TEST_ON == FM_MTBF_AUD_END)
        {
            AUD_TEST_ON = FM_MTBF_AUD_START;
        }
        else
        {
            AUD_TEST_ON++;
        }
    }
    else /* Receiver */ if ((Count_ms % FM_MTBF_REV_CYCLE) == 0 && AUD_TEST_ON == FM_MTBF_AUD_REV)
    {
        /* Normal Mode */
        TONE_Stop();
        kal_sleep_task(20);
        FM_SendSetAudioModeReq(AUD_MODE_NORMAL);
        /* TONE_SetOutputDevice(L1SP_SPEAKER1); */
        TONE_SetOutputVolume(255, 0);
        TONE_Play((const L1SP_Tones*)(REV_test_tone));

        if (AUD_TEST_ON == FM_MTBF_AUD_END)
        {
            AUD_TEST_ON = FM_MTBF_AUD_START;
        }
        else
        {
            AUD_TEST_ON++;
        }
    }

   /***** Prepare for the next step *****/
    MTBF_counter++;
    StartTimer(FM_AUTO_TEST_COMMNON_TIMER, FM_MTBF_PERIOD, FM_MTBF);


}

#ifdef __MMI_TOUCH_SCREEN__
#include "wgui_touch_screen.h"

typedef enum
{
    INVALID_TEST = 0,
    PARALLEL_TEST_1,    /* \\ */
    PARALLEL_TEST_2     /* // */
} parallel_test_type;

/* Previous point in pen test program */
static mmi_pen_point_struct gFMPenPreviousPoint;

/* Capture pen events by test drawing program */
static BOOL gFMPenTestCapture = MMI_FALSE;

/* Line color */
static color gFMPenLineColor = {0, 0, 0, 100};

static S16 gFMPenParallel_test_type = PARALLEL_TEST_1;
static S16 gFMPenParallel_first_x1;
static S16 gFMPenParallel_first_y1;
static S16 gFMPenParallel_first_x2;
static S16 gFMPenParallel_first_y2;
static S16 gFMPenParallel_second_x1;
static S16 gFMPenParallel_second_y1;
static S16 gFMPenParallel_second_x2;
static S16 gFMPenParallel_second_y2;
static S16 gFMPenParallel_first_point_x;    /* Starting point's x */
static S16 gFMPenParallel_first_point_y;    /* Starting point's y */
static S16 gFMPenParallel_second_point_x;   /* End point's x */
static S16 gFMPenParallel_second_point_y;   /* End point's y */

BOOL gFM_pen_test_start_from_top = FALSE;

static const S16 gFMPenPointOffset = 10;    /* Offset around start and end point */

U8 addtohistory = FALSE;    /* Parallel Test screen need's to be added in History */


/*****************************************************************************
 * FUNCTION
 *  HighlightFMParallelTestHdlr
 * DESCRIPTION
 *  This function is highlight handler for Parallel line Test
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightFMParallelTestHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryFMPenParallelTest, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  FMPenParallelTestPenDown
 * DESCRIPTION
 *  This function handles pen down events on Parallel Lines Test screen
 * PARAMETERS
 *  pos     [IN]        
 *  mmi_pen_point_struct(?)
 * RETURNS
 *  void
 *****************************************************************************/
static void FMPenParallelTestPenDown(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL inside_region = FALSE;
    long x, y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x = (pos.x - gFMPenParallel_first_point_x) * (pos.x - gFMPenParallel_first_point_x);
    y = (pos.y - gFMPenParallel_first_point_y) * (pos.y - gFMPenParallel_first_point_y);

    if ((x + y) <= (gFMPenPointOffset * gFMPenPointOffset))
    {
        /* Starting from Top */
        inside_region = TRUE;
        gFM_pen_test_start_from_top = TRUE;
    }
    else
    {
        x = (pos.x - gFMPenParallel_second_point_x) * (pos.x - gFMPenParallel_second_point_x);
        y = (pos.y - gFMPenParallel_second_point_y) * (pos.y - gFMPenParallel_second_point_y);

        if ((x + y) <= (gFMPenPointOffset * gFMPenPointOffset))
        {
            /* Starting from Bottom */
            inside_region = TRUE;
            gFM_pen_test_start_from_top = FALSE;
        }
    }
    if (inside_region)
    {
        gFMPenPreviousPoint.x = pos.x;
        gFMPenPreviousPoint.y = pos.y;
        gFMPenTestCapture = MMI_TRUE;
        gFMPenLineColor = gui_color(0, 150, 0);
    }
    else
    {
        gFMPenPreviousPoint.x = -1;
        gFMPenPreviousPoint.y = -1;
        wgui_general_pen_down_hdlr(pos);
        gFMPenTestCapture = MMI_FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  FMPenParallelTestPenMove
 * DESCRIPTION
 *  This function handles pen move events on Parallel Lines Test screen
 * PARAMETERS
 *  pos     [IN]        
 *  mmi_pen_point_struct(?)
 * RETURNS
 *  void
 * REMARKS
 *  If pen is moved outside parallel lines test fails
 *****************************************************************************/
static void FMPenParallelTestPenMove(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    float first_x1 = gFMPenParallel_first_x1;
    float first_x2 = gFMPenParallel_first_x2;
    float first_y1 = gFMPenParallel_first_y1;
    float first_y2 = gFMPenParallel_first_y2;
    float second_x1 = gFMPenParallel_second_x1;
    float second_x2 = gFMPenParallel_second_x2;
    float second_y1 = gFMPenParallel_second_y1;
    float second_y2 = gFMPenParallel_second_y2;
    BOOL inside_region = FALSE;
    float xdiff1, xdiff2, test1, test2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!gFMPenTestCapture)
    {
        wgui_general_pen_move_hdlr(pos);
        return;
    }

    xdiff1 = (first_x2 - first_x1);
    xdiff2 = (second_x2 - second_x1);

    if (0 == xdiff1 || 0 == xdiff2)
    {
        ASSERT(0);
    }

    test1 = pos.y - first_y1 - ((first_y2 - first_y1) * (pos.x - first_x1)) / (xdiff1);
    test2 = pos.y - second_y1 - ((second_y2 - second_y1) * (pos.x - second_x1)) / (xdiff2);

    switch (gFMPenParallel_test_type)
    {
        case PARALLEL_TEST_1:
        {
            if ((test1 < 0) && (test2 > 0))
            {
                inside_region = TRUE;
            }
        }
            break;
        case PARALLEL_TEST_2:
        {
            if ((test1 > 0) && (test2 < 0))
            {
                inside_region = TRUE;
            }
        }
            break;
        default:
            ASSERT(0);
            break;
    }
    if (inside_region)
    {
        gui_lock_double_buffer();
        gui_push_clip();
        gui_set_clip(0, 0, UI_device_width - 1, UI_device_height - 1);
        gui_line(gFMPenPreviousPoint.x, gFMPenPreviousPoint.y, pos.x, pos.y, gFMPenLineColor);
        gui_pop_clip();
        gui_unlock_double_buffer();
        gui_BLT_double_buffer(
            PEN_MIN(gFMPenPreviousPoint.x, pos.x),
            PEN_MIN(gFMPenPreviousPoint.y, pos.y),
            PEN_MAX(gFMPenPreviousPoint.x, pos.x),
            PEN_MAX(gFMPenPreviousPoint.y, pos.y));
        gFMPenPreviousPoint.x = pos.x;
        gFMPenPreviousPoint.y = pos.y;
    }
    else
    {
        gFMPenPreviousPoint.x = -1;
        gFMPenPreviousPoint.y = -1;
        wgui_general_pen_move_hdlr(pos);
        gFMPenTestCapture = MMI_FALSE;
        DisplayPopup((PU8) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 0, 1000, 0);
    }

}


/*****************************************************************************
 * FUNCTION
 *  FMPenParallelTestPenUp
 * DESCRIPTION
 *  This function handles pen UP event on Parallel Lines Test screen
 * PARAMETERS
 *  pos     [IN]        
 *  mmi_pen_point_struct(?)
 * RETURNS
 *  void
 * REMARKS
 *  When pen is UP is should be with in a predefined area (calculated by gFMPenPointOffset)
 *  of the end point of the test
 *****************************************************************************/
static void FMPenParallelTestPenUp(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!gFMPenTestCapture)
    {
        wgui_general_pen_up_hdlr(pos);
    }
    else
    {
        long x, y;
        S16 result = 0;

        if (gFM_pen_test_start_from_top)
        {
            x = (pos.x - gFMPenParallel_second_point_x) * (pos.x - gFMPenParallel_second_point_x);
            y = (pos.y - gFMPenParallel_second_point_y) * (pos.y - gFMPenParallel_second_point_y);
            if ((x + y) < (gFMPenPointOffset * gFMPenPointOffset))
            {
                result = 1;
            }
        }
        else
        {
            x = (pos.x - gFMPenParallel_first_point_x) * (pos.x - gFMPenParallel_first_point_x);
            y = (pos.y - gFMPenParallel_first_point_y) * (pos.y - gFMPenParallel_first_point_y);
            if ((x + y) < (gFMPenPointOffset * gFMPenPointOffset))
            {
                result = 1;
            }
        }

        if (result)
        {
            if (PARALLEL_TEST_1 == gFMPenParallel_test_type)
            {
                DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 0, 1000, 0);
                gFMPenParallel_test_type = PARALLEL_TEST_2;
            }
            else if (PARALLEL_TEST_2 == gFMPenParallel_test_type)
            {
                addtohistory = FALSE;
                EntryNewScreen(SCR_ID_FM_PARALLEL_PEN, NULL, NULL, NULL);
                if (autoTestMode == 0)
                {
                    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 0, 1000, 0);
                    gFMPenParallel_test_type = PARALLEL_TEST_1;
                }
                else
                {
                    FM_Autotest_test_done_USC2string(Tests[FM_AUTOTEST_PARALLEL_LINE].name);
                    ShowCategory7Screen(
                        STR_ID_FM_AUTO_TEST_ROOT,
                        IMG_ID_FM_AUTO_TEST_ROOT,
                        STR_ID_FM_AUTO_TEST_PASS,
                        IMG_GLOBAL_OK,
                        STR_ID_FM_AUTO_TEST_FAIL,
                        IMG_GLOBAL_BACK,
                        (PU8) EMFMUnicodeDisplayBuf,
                        NULL);
                    FM_Autotest_set_key_handlers();
                    gFMPenParallel_test_type = PARALLEL_TEST_1;
                }
            }
        }
        else
        {
            gFMPenPreviousPoint.x = -1;
            gFMPenPreviousPoint.y = -1;
            gFMPenTestCapture = MMI_FALSE;
            gFMPenLineColor = gui_color(0, 0, 0);
            wgui_general_pen_up_hdlr(pos);
            DisplayPopup((PU8) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 0, 1000, 0);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  EmPenParallelTestSetupCoordinates
 * DESCRIPTION
 *  This function sets up coordinates according to type of test
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * REMARKS
 *  FIRST TEST :: \\
 *  SECOND TEST :: //
 *****************************************************************************/
static void EmPenParallelTestSetupCoordinates(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (gFMPenParallel_test_type)
    {
        case PARALLEL_TEST_1:
        {
            gFMPenParallel_first_x1 = 0;
            gFMPenParallel_first_y1 = 20;
            gFMPenParallel_first_x2 = UI_device_width - 20;
            gFMPenParallel_first_y2 = UI_device_height;

            gFMPenParallel_second_x1 = 20;
            gFMPenParallel_second_y1 = 0;
            gFMPenParallel_second_x2 = UI_device_width;
            gFMPenParallel_second_y2 = UI_device_height - 20;

            gFMPenParallel_first_point_x = 8;
            gFMPenParallel_first_point_y = 8;
            gFMPenParallel_second_point_x = UI_device_width - 8;
            gFMPenParallel_second_point_y = UI_device_height - 8;
        }
            break;
        case PARALLEL_TEST_2:
        {
            gFMPenParallel_first_x1 = UI_device_width - 20;
            gFMPenParallel_first_y1 = 0;
            gFMPenParallel_first_x2 = 0;
            gFMPenParallel_first_y2 = UI_device_height - 20;

            gFMPenParallel_second_x1 = UI_device_width;
            gFMPenParallel_second_y1 = 20;
            gFMPenParallel_second_x2 = 20;
            gFMPenParallel_second_y2 = UI_device_height;

            gFMPenParallel_first_point_x = UI_device_width - 8;
            gFMPenParallel_first_point_y = 8;
            gFMPenParallel_second_point_x = 8;
            gFMPenParallel_second_point_y = UI_device_height - 8;
        }
            break;
        default:
            ASSERT(0);
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  EmPenParallelTestDisplay
 * DESCRIPTION
 *  This function displays Parallel lines and start and end points of the test
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * REMARKS
 *  FIRST TEST :: \\
 *  SECOND TEST :: //
 *****************************************************************************/
static void EmPenParallelTestDisplay(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    clear_screen();
    gui_lock_double_buffer();

    gui_line(
        gFMPenParallel_first_x1,
        gFMPenParallel_first_y1,
        gFMPenParallel_first_x2,
        gFMPenParallel_first_y2,
        gui_color(255, 0, 0));
    gui_line(
        gFMPenParallel_second_x1,
        gFMPenParallel_second_y1,
        gFMPenParallel_second_x2,
        gFMPenParallel_second_y2,
        gui_color(255, 0, 0));

    gui_line(
        gFMPenParallel_first_point_x - 5,
        gFMPenParallel_first_point_y - 5,
        gFMPenParallel_first_point_x + 5,
        gFMPenParallel_first_point_y + 5,
        gui_color(0, 0, 0));
    gui_line(
        gFMPenParallel_first_point_x + 5,
        gFMPenParallel_first_point_y - 5,
        gFMPenParallel_first_point_x - 5,
        gFMPenParallel_first_point_y + 5,
        gui_color(0, 0, 0));
    gui_line(
        gFMPenParallel_second_point_x - 5,
        gFMPenParallel_second_point_y - 5,
        gFMPenParallel_second_point_x + 5,
        gFMPenParallel_second_point_y + 5,
        gui_color(0, 0, 0));
    gui_line(
        gFMPenParallel_second_point_x + 5,
        gFMPenParallel_second_point_y - 5,
        gFMPenParallel_second_point_x - 5,
        gFMPenParallel_second_point_y + 5,
        gui_color(0, 0, 0));

    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);

}


/*****************************************************************************
 * FUNCTION
 *  ExitFMPenParallelTest
 * DESCRIPTION
 *  This function is Exit handler for Parallel lines Test
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitFMPenParallelTest(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (addtohistory)
    {
        history currHistory;

        currHistory.scrnID = SCR_ID_FM_PARALLEL_PEN;
        currHistory.entryFuncPtr = EntryFMPenParallelTest;
        GetCategoryHistory(currHistory.guiBuffer);
        AddHistory(currHistory);
    }
}


/*****************************************************************************
 * FUNCTION
 *  FM_ParallelTestEndKeyTimeout
 * DESCRIPTION
 *  This function handles Long Press of End Key on Parallel Line Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FM_ParallelTestEndKeyTimeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    addtohistory = FALSE;
    gFMPenParallel_test_type = PARALLEL_TEST_1;
    FM_HandleKeypadEndout();
}


/*****************************************************************************
 * FUNCTION
 *  EntryFMPenParallelTest
 * DESCRIPTION
 *  This function is Entry function of Parallel Line Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryFMPenParallelTest(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    addtohistory = FALSE;
    EntryNewScreen(SCR_ID_FM_PARALLEL_PEN, ExitFMPenParallelTest, NULL, NULL);
    addtohistory = TRUE;

    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    SetKeyHandler(FM_ParallelTestEndKeyTimeout, KEY_END, KEY_EVENT_LONG_PRESS);
    gFMPenPreviousPoint.x = -1;
    gFMPenPreviousPoint.y = -1;

    EmPenParallelTestSetupCoordinates();
    entry_full_screen();
    EmPenParallelTestDisplay();

    wgui_register_pen_down_handler(FMPenParallelTestPenDown);
    wgui_register_pen_move_handler(FMPenParallelTestPenMove);
    wgui_register_pen_up_handler(FMPenParallelTestPenUp);
    wgui_register_pen_repeat_handler(mmi_pen_dummy_hdlr);
    wgui_register_pen_long_tap_handler(mmi_pen_dummy_hdlr);
    wgui_register_pen_abort_handler(mmi_pen_dummy_hdlr);
}


/*****************************************************************************
 * FUNCTION
 *  FM_AutoTest_Pen_Parallel_Test
 * DESCRIPTION
 *  This function is for Parallel line Test in Auto Test mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FM_AutoTest_Pen_Parallel_Test(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currentTest = FM_TEST_PEN_PARALLEL_LINES;
    EntryFMPenParallelTest();
}

/* N Cross M Points Test */

#define TOUCH_N_ROWS 4  /* Number of Rows of Points */
#define TOUCH_N_COLS 5  /* Number of Columns of Points */
#define IMAGE_HIDE      0       /* Hide image of Point */
#define IMAGE_SHOW      1       /* Show image of Point */
// TODO: dynamic compute margin
#define TOUCH_ROW_MARGIN   30   /* Horizontal Margin between points */
#define TOUCH_COL_MARGIN   15   /* Vertical Margin between points */

static S16 gFMPenNByMStartx;
static S16 gFMPenNByMStarty;

static S32 gFMPenNByMImageHeight;   /* Point Image's height */
static S32 gFMPenNByMImageWidth;    /* Point Image's width */

static S16 gFMPenNByMStatus[TOUCH_N_ROWS][TOUCH_N_COLS];    /* Show hide point status */


/*****************************************************************************
 * FUNCTION
 *  HighlightFMNCrossMTestHdlr
 * DESCRIPTION
 *  This function is Highlight handler for N Cross M points Test
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightFMNCrossMTestHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryFMPenNCrossMTest, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  FMPenNByMTestInitStatus
 * DESCRIPTION
 *  This function initializes image status array of the points
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void FMPenNByMTestInitStatus(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x, y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (x = 0; x < TOUCH_N_ROWS; x++)
    {
        for (y = 0; y < TOUCH_N_COLS; y++)
        {
            gFMPenNByMStatus[x][y] = IMAGE_SHOW;
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  FMPenNByMPenTestStatus
 * DESCRIPTION
 *  This function checks image status array of the points to see if all the images
 *  have been clicked
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static BOOL FMPenNByMPenTestStatus(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x, y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (x = 0; x < TOUCH_N_ROWS; x++)
    {
        for (y = 0; y < TOUCH_N_COLS; y++)
        {
            if (IMAGE_SHOW == gFMPenNByMStatus[x][y])
            {
                return FALSE;
            }
        }
    }
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  FMPenNByMTestDisplay
 * DESCRIPTION
 *  This function displays point images according to image status array of the points
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void FMPenNByMTestDisplay(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 r, c, x, y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 
    gui_push_clip();
    gui_set_clip(0, 0, UI_device_width - 1, UI_device_height - 1);
    clear_screen();
    for (r = 0; r < TOUCH_N_ROWS; r++)
    {
        for (c = 0; c < TOUCH_N_COLS; c++)
        {
            if (IMAGE_SHOW == gFMPenNByMStatus[r][c])
            {
                x = gFMPenNByMStartx + c * (gFMPenNByMImageWidth + TOUCH_COL_MARGIN);
                y = gFMPenNByMStarty + r * (gFMPenNByMImageHeight + TOUCH_ROW_MARGIN);
                gui_show_image(x, y, get_image((MMI_ID_TYPE) (IMG_GLOBAL_L1 + c)));
            }
        }
    }
    gui_pop_clip();
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width, UI_device_height);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}


/*****************************************************************************
 * FUNCTION
 *  FMPenNByMTestTranslatePenPosition
 * DESCRIPTION
 *  This function translates pen position on N Cross M points test screen
 * PARAMETERS
 *  pos     [IN]        
 *  row     [?]         
 *  col     [?]         
 *  mmi_pen_point_struct(?)
 * RETURNS
 *  void
 *****************************************************************************/
static void FMPenNByMTestTranslatePenPosition(mmi_pen_point_struct pos, S32 *row, S32 *col)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 end_x, end_y, x, y, r, c, x1, y1, image_height, image_width, start_x, start_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x = pos.x;
    y = pos.y;
    *row = -1;
    *col = -1;
    start_x = gFMPenNByMStartx;
    start_y = gFMPenNByMStarty;
    image_height = gFMPenNByMImageHeight;
    image_width = gFMPenNByMImageWidth;
    end_x = start_x + TOUCH_N_COLS * image_width + (TOUCH_N_COLS - 1) * TOUCH_COL_MARGIN;
    end_y = start_y + TOUCH_N_ROWS * image_height + (TOUCH_N_ROWS - 1) * TOUCH_ROW_MARGIN;

    if (PEN_CHECK_BOUND(x, y, start_x, start_y, end_x, end_y))
    {
        for (y1 = start_y, r = 0; y1 < end_y; y1 += image_height + TOUCH_ROW_MARGIN, r++)
        {
            if (y > y1 && y < y1 + image_height)
            {
                *row = r;
            }
        }
        for (x1 = start_x, c = 0; x1 < end_x; x1 += image_width + TOUCH_COL_MARGIN, c++)
        {
            if (x > x1 && x < x1 + image_width)
            {
                *col = c;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  FMPenNByMTestPenDown
 * DESCRIPTION
 *  This function handles Pen Down Events on N Cross M Points screen
 * PARAMETERS
 *  pos     [IN]        
 *  mmi_pen_point_struct(?)
 * RETURNS
 *  void
 *****************************************************************************/
static void FMPenNByMTestPenDown(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x, y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMPenNByMTestTranslatePenPosition(pos, &x, &y);

    if (-1 != x && -1 != y)
    {
        gFMPenNByMStatus[x][y] = IMAGE_HIDE;
    }
    if (FMPenNByMPenTestStatus())
    {
        EntryNewScreen(SCR_ID_FM_N_CROSS_M_PEN, NULL, NULL, NULL);
        if (0 == autoTestMode)
        {
            DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 0, 1000, 0);
        }
        else
        {
            FM_Autotest_test_done_USC2string(Tests[FM_AUTOTEST_N_CROSS_M_POINTS].name);
            ShowCategory7Screen(
                STR_ID_FM_AUTO_TEST_ROOT,
                IMG_ID_FM_AUTO_TEST_ROOT,
                STR_ID_FM_AUTO_TEST_PASS,
                IMG_GLOBAL_OK,
                STR_ID_FM_AUTO_TEST_FAIL,
                IMG_GLOBAL_BACK,
                (PU8) EMFMUnicodeDisplayBuf,
                NULL);
            FM_Autotest_set_key_handlers();
        }
    }
    else
    {
        FMPenNByMTestDisplay();
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryFMPenNCrossMTest
 * DESCRIPTION
 *  This function is Entry Function of N Cross M Points screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryFMPenNCrossMTest(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_FM_N_CROSS_M_PEN, NULL, NULL, NULL);

    gui_measure_image(get_image(IMG_GLOBAL_L1), &gFMPenNByMImageWidth, &gFMPenNByMImageHeight);
    gFMPenNByMStartx =
        (UI_device_width - ((TOUCH_N_COLS * gFMPenNByMImageWidth) + (TOUCH_N_COLS - 1) * TOUCH_COL_MARGIN)) / 2;
    gFMPenNByMStarty =
        (UI_device_height - ((TOUCH_N_ROWS * gFMPenNByMImageHeight) + (TOUCH_N_ROWS - 1) * TOUCH_ROW_MARGIN)) / 2;

    ASSERT(gFMPenNByMStartx >= 0 && gFMPenNByMStartx <= UI_device_width);
    ASSERT(gFMPenNByMStarty >= 0 && gFMPenNByMStarty <= UI_device_height);

    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    SetKeyHandler(FM_HandleKeypadEndout, KEY_END, KEY_EVENT_LONG_PRESS);
    FMPenNByMTestInitStatus();
    entry_full_screen();
    FMPenNByMTestDisplay();

    wgui_register_pen_up_handler(mmi_pen_dummy_hdlr);
    wgui_register_pen_down_handler(FMPenNByMTestPenDown);
    wgui_register_pen_move_handler(mmi_pen_dummy_hdlr);
    wgui_register_pen_repeat_handler(mmi_pen_dummy_hdlr);
    wgui_register_pen_long_tap_handler(mmi_pen_dummy_hdlr);
    wgui_register_pen_abort_handler(mmi_pen_dummy_hdlr);
}


/*****************************************************************************
 * FUNCTION
 *  FM_AutoTest_Pen_N_Cross_M_Test
 * DESCRIPTION
 *  This function sets is for N Cross M point test in Auto Test Mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FM_AutoTest_Pen_N_Cross_M_Test(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currentTest = FM_TEST_PEN_N_CROSS_M_POINTS;
    EntryFMPenNCrossMTest();
}

#endif /* __MMI_TOUCH_SCREEN__ */ 


#ifdef __MMI_FM_RADIO__
/*****************************************************************************
 * FUNCTION
 *  HighlightFMFMRadiohdlr
 * DESCRIPTION
 *  This function is Highlight handler for FM Radio Test
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightFMFMRadiohdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryFMFMRadioTest, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    change_left_softkey(STR_GLOBAL_OK, 0);
    redraw_left_softkey();
}


/*****************************************************************************
 * FUNCTION
 *  EntryFMFMRadioTest
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryFMFMRadioTest(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[] = 
    {
        STR_ID_FM_FM_RADIO_CHANNEL_1,
        STR_ID_FM_FM_RADIO_CHANNEL_2,
        STR_ID_FM_FM_RADIO_CHANNEL_3
    };
    U16 ItemIcons[3];
    U16 nItems = 3;
    U8 *guiBuffer;
    U8 *PopUpList[3];
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* If FM Radio is turned on, then stop/turn-off it */
    if (g_fm_fm_radio_cntx.is_FMRDO_on)
    {
        mdi_audio_stop_fmr();
        g_fm_fm_radio_cntx.is_FMRDO_on = 0;
    }
    
    EntryNewScreen(SCR_ID_FM_FM_RADIO, NULL, EntryFMFMRadioTest, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_FM_FM_RADIO);
    SetParentHandler(MENU_ID_FM_FMRADIO);

    RegisterHighlightHandler(FMSetHighlightIndex);

    for (i = 0; i < nItems; i++)
    {
        PopUpList[i] = NULL;
        ItemIcons[i] = (U16) (IMG_GLOBAL_L1 + i);   
    }

    ShowCategory52Screen(
        STR_ID_FM_FM_RADIO,
        0,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        nItems,
        ItemList,
        ItemIcons,
        (U8 **) PopUpList,
        0,
        0,
        guiBuffer);

    SetLeftSoftkeyFunction(FMRADIOChannelTestInit, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EntryFMRADIOChannelTestInit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FMRADIOChannelTestInit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* init volume */
    g_fm_fm_radio_cntx.CurrVolume = 3;

    /* Turn on FM Radio */
    mdi_fmr_power_on_with_path( MDI_DEVICE_SPEAKER2, (mdi_callback) NULL);  

    /* Read channel info from NVRAM */
    switch(FmcurrentHighlightIndex)
    {
        case 0:   /* Channel 1 */
        {
            ReadValue(NVRAM_FM_FM_RADIO_CHANNEL_1, &g_fm_fm_radio_cntx.Currfreq, DS_SHORT, &error);
            if (g_fm_fm_radio_cntx.Currfreq == 0xffff)
            {
                g_fm_fm_radio_cntx.Currfreq = 875;    /* init value */
                WriteValue(NVRAM_FM_FM_RADIO_CHANNEL_1, &g_fm_fm_radio_cntx.Currfreq, DS_SHORT, &error);
            }
            g_fm_fm_radio_cntx.text_id= STR_ID_FM_FM_RADIO_CHANNEL_1;
            break;
        }
        case 1:   /* Channel 2 */
        {
            ReadValue(NVRAM_FM_FM_RADIO_CHANNEL_2, &g_fm_fm_radio_cntx.Currfreq, DS_SHORT, &error);
            if (g_fm_fm_radio_cntx.Currfreq == 0xffff)
            {
                g_fm_fm_radio_cntx.Currfreq = 875;    /* init value */
                WriteValue(NVRAM_FM_FM_RADIO_CHANNEL_2, &g_fm_fm_radio_cntx.Currfreq, DS_SHORT, &error);
            }
            g_fm_fm_radio_cntx.text_id = STR_ID_FM_FM_RADIO_CHANNEL_2;            
            break;
        }
        case 2:   /* Channel 3 */
        {
            ReadValue(NVRAM_FM_FM_RADIO_CHANNEL_3, &g_fm_fm_radio_cntx.Currfreq, DS_SHORT, &error);
            if (g_fm_fm_radio_cntx.Currfreq == 0xffff)
            {
                g_fm_fm_radio_cntx.Currfreq = 875;    /* init value */
                WriteValue(NVRAM_FM_FM_RADIO_CHANNEL_3, &g_fm_fm_radio_cntx.Currfreq, DS_SHORT, &error);
            }            
            g_fm_fm_radio_cntx.text_id = STR_ID_FM_FM_RADIO_CHANNEL_3;            
            break;
        }
        default:
        {
            ASSERT(0);
            break;
        }
    }
    
    EntryFMRADIOChannelTest();
}


/*****************************************************************************
 * FUNCTION
 *  EntryFMRADIOChannelTest
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryFMRADIOChannelTest(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* guiBuffer;
    S8 stringbuf[110];
    S8 tmpStr[12];
    S8 tmpStr_UCS2[24];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_fm_fm_radio_cntx.is_FMRDO_on = 1;

    /* set audio volume */
    mdi_audio_set_volume( AUD_VOLUME_FMR,  g_fm_fm_radio_cntx.CurrVolume);

    /* set FM Radio Frequency */
    mdi_fmr_set_freq( g_fm_fm_radio_cntx.Currfreq);

   /* initialize display string */
    memset(stringbuf, 0, 100);

    /* frequency */
    memset(tmpStr, 0, 10);
    sprintf(tmpStr, "Fre:");
    mmi_asc_to_ucs2(tmpStr_UCS2, tmpStr);
    mmi_ucs2cat(stringbuf, tmpStr_UCS2);
    
    memset(tmpStr, 0, 10);
    sprintf(tmpStr, "  %d.%d \n\n",  g_fm_fm_radio_cntx.Currfreq/10, g_fm_fm_radio_cntx.Currfreq%10);
    mmi_asc_to_ucs2(tmpStr_UCS2, tmpStr);
    mmi_ucs2cat(stringbuf, tmpStr_UCS2);

    /* volume */
    memset(tmpStr, 0, 10);
    sprintf(tmpStr, "Vol:");
    mmi_asc_to_ucs2(tmpStr_UCS2, tmpStr);
    mmi_ucs2cat(stringbuf, tmpStr_UCS2);
    
    memset(tmpStr, 0, 10);
    sprintf(tmpStr, "    %d\n\n", g_fm_fm_radio_cntx.CurrVolume);
    mmi_asc_to_ucs2(tmpStr_UCS2, tmpStr);
    mmi_ucs2cat(stringbuf, tmpStr_UCS2);

    /* Entry New Screen & Show Category */
    EntryNewScreen(SCR_ID_FM_FM_RADIO_CHANNEL_TEST, NULL, NULL, NULL);
    guiBuffer = GetCurrGuiBuffer (SCR_ID_FM_FM_RADIO_CHANNEL_TEST);
    
    ShowCategory7Screen(g_fm_fm_radio_cntx.text_id, 0, 0, 0,
                        STR_GLOBAL_BACK, IMG_GLOBAL_BACK, (PU8)stringbuf, guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory,KEY_EVENT_UP);

    /* Register End key handler */
    SetKeyHandler(GoBackHistory, KEY_END , KEY_EVENT_DOWN);

    SetKeyHandler(FmFMRadioLeftArrowHdlr, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(FmFMRadioRightArrowHdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(FmFMRadioUpArrowHdlr, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(FmFMRadioDownArrowHdlr, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    
}


/**************************************************************
**	FUNCTION NAME		: FmFMRadioLeftArrowHdlr
**
**  	PURPOSE				: Entry function to FM Radio RSSI Info Left Arrow Hdler
**
**	INPUT PARAMETERS	: index
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			: 
**************************************************************/
void FmFMRadioLeftArrowHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Channel Freq. Range: 875 - 1080 */
    if (g_fm_fm_radio_cntx.Currfreq > 875)
        g_fm_fm_radio_cntx.Currfreq -= 1;

    /* Restore the changed frequency to NVRAM */
    switch(FmcurrentHighlightIndex)
    {
        case 0:   /* Channel 1 */
        {
            WriteValue(NVRAM_FM_FM_RADIO_CHANNEL_1, &g_fm_fm_radio_cntx.Currfreq, DS_SHORT, &error);
            break;
        }
        case 1:   /* Channel 2 */
        {
            WriteValue(NVRAM_FM_FM_RADIO_CHANNEL_2, &g_fm_fm_radio_cntx.Currfreq, DS_SHORT, &error);
            break;
        }
        case 2:   /* Channel 3 */
        {
            WriteValue(NVRAM_FM_FM_RADIO_CHANNEL_3, &g_fm_fm_radio_cntx.Currfreq, DS_SHORT, &error);
            break;
        }
        default:
        {
            ASSERT(0);
            break;
        }
    }

    EntryFMRADIOChannelTest();
}


/**************************************************************
**	FUNCTION NAME		: FmFMRadioRightArrowHdlr
**
**  	PURPOSE				: Entry function to FM Radio RSSI Info Right Arrow Hdler
**
**	INPUT PARAMETERS	: index
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			: 
**************************************************************/
void FmFMRadioRightArrowHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Channel Freq. Range: 875 - 1080 */    
    if (g_fm_fm_radio_cntx.Currfreq < 1080)
        g_fm_fm_radio_cntx.Currfreq += 1;

    /* Restore the changed frequency to NVRAM */
    switch(FmcurrentHighlightIndex)
    {
        case 0:   /* Channel 1 */
        {
            WriteValue(NVRAM_FM_FM_RADIO_CHANNEL_1, &g_fm_fm_radio_cntx.Currfreq, DS_SHORT, &error);
            break;
        }
        case 1:   /* Channel 2 */
        {
            WriteValue(NVRAM_FM_FM_RADIO_CHANNEL_2, &g_fm_fm_radio_cntx.Currfreq, DS_SHORT, &error);
            break;
        }
        case 2:   /* Channel 3 */
        {
            WriteValue(NVRAM_FM_FM_RADIO_CHANNEL_3, &g_fm_fm_radio_cntx.Currfreq, DS_SHORT, &error);
            break;
        }
        default:
        {
            ASSERT(0);
            break;
        }
    }
    
    EntryFMRADIOChannelTest();
}


/**************************************************************
**	FUNCTION NAME		: FmFMRadioUpArrowHdlr
**
**  	PURPOSE				: Entry function to FM Radio RSSI Info Up Arrow Hdler
**
**	INPUT PARAMETERS	: index
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			: 
**************************************************************/
void FmFMRadioUpArrowHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fm_fm_radio_cntx.CurrVolume < MAX_VOL_LEVEL - 1)
        g_fm_fm_radio_cntx.CurrVolume++;

    EntryFMRADIOChannelTest();
}


/**************************************************************
**	FUNCTION NAME		: FmFMRadioDownArrowHdlr
**
**  	PURPOSE				: Entry function to FM Radio RSSI Info Down Arrow Hdler
**
**	INPUT PARAMETERS	: index
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			: 
**************************************************************/
void FmFMRadioDownArrowHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fm_fm_radio_cntx.CurrVolume > 0)
        g_fm_fm_radio_cntx.CurrVolume--;

    EntryFMRADIOChannelTest();
}

#endif /* #ifdef __MMI_FM_RADIO__ */


/*****************************************************************************
 * FUNCTION
 *  FMSetHighlightIndex
 * DESCRIPTION
 *  
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void FMSetHighlightIndex(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FmcurrentHighlightIndex = (U8) nIndex;
}


#endif /* __MMI_FACTORY_MODE__ */ 

