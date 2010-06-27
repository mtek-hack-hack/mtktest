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
 * USBDevice.c
 *
 * Project:
 * --------
 *   MMI
 *
 * Description:
 * ------------
 *   This file is for mmi configure usb device
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

#include "MMI_include.h"

#ifdef __MMI_USB_SUPPORT__

#include "bootup.h"

#include "ProtocolEvents.h"
#include "CommonScreens.h"      /* DisplayPopup */
#include "wgui_status_icons.h"  /* STATUS_ICON_SUBLCD_BATTERY_STRENGTH */
#include "SimDetectionGexdcl.h" /* To access g_charbat_context */
#include "SimDetectionGprot.h"
#include "IdleAppProt.h"
#include "TaskInit.h"
#include "MMItaskProt.h"        /* InitFramework */

#include "PowerOnChargerProt.h" /* BatteryIndicationPopup() */

#include "CallManagementGprot.h"        /* isInCall() */
#ifdef __USB_IN_NORMAL_MODE__
#include "CallmanagementIdDef.h"        /* CM_SCR_MARKER */
#include "WPSSProtos.h" /* for DispChar */
#include "FileMgr.h"

#ifdef __MMI_EMAIL__
#include "EmailAppGProt.h"
#include "EmailAppProt.h"
#endif /* __MMI_EMAIL__ */ 

#endif /* __USB_IN_NORMAL_MODE__ */ 

#include "FileManagerGProt.h"

#ifdef __MMI_IRDA_SUPPORT__
#include "IrdaMMIGprots.h"      /* mmi_irda_is_open() */
#endif 

/* Trace Header Files */

/* USB Device Headder Files */
#include "ExtDeviceDefs.h"
#include "USBDeviceGprot.h"
#include "USBDeviceDefs.h"
#include "USBDeviceGexdcl.h"

#ifdef __MMI_ENGINEER_MODE__
#include "EngineerModeDef.h"
#endif 
#include "PhoneBookTypes.h"

#include "lcd_sw.h"
#include "uart_sw.h"
#include "lcd_sw.h"
#include "lcd_sw_inc.h"
#include "gpioInc.h"
#include "lcd_if.h"

#ifdef __MMI_WEBCAM__
#include "mdi_datatype.h"
#include "mdi_webcam.h"
#include "mdi_camera.h"
#include "IdleAppDef.h" /* for POPUP_SCREENID */
#include "WPSSProtos.h" /* enable/disable partial screen saver */
#include "gpioInc.h"    /* led pattern */
#endif /* __MMI_WEBCAM__ */ 

#ifdef __MMI_MMS__
#include "wapadp.h"
#endif 

#ifdef __MMI_VIDEO_RECORDER__
#include "VdoRecGprot.h"
#endif 

#include "SettingDefs.h"        /* SCR_RESTORE_PROCESSING */
#include "SettingsGdcl.h"
#include "AlarmFrameWorkProt.h"
#include "AlarmProt.h"
#include "vObjectsResDef.h"
#include "datetimetype.h"
#include "app_datetime.h"

#include "nvram_enums.h"
#include "Nvram_interface.h"

#if defined(__FOTA_ENABLE__)
#include "DeviceManagementGProt.h"
#endif

#include "PhoneSetupGprots.h"

#ifdef WAP_SUPPORT
#include "Wapadp.h"
#endif

#ifdef __MMI_PICT_BRIDGE_SUPPORT__
#include "PictBridgeGProt.h"
#endif
 
#ifdef __MMI_DOWNLOAD_AGENT__
#include "FileMgr.h"
#include "DLAgentDef.h"
#include "DLAgentGProt.h"
#endif

#if defined(__MMI_OPP_SUPPORT__) && defined(__MMI_BT_MTK_SUPPORT__)
#include "BTMMICm.h"
#include "BTMMIOppGprots.h"
#endif /* defined(__MMI_OPP_SUPPORT__) && defined(__MMI_BT_MTK_SUPPORT__) */

#if defined(__MMI_BT_MTK_SUPPORT__)  && (defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__))
#include "BTMMICm.h"
#include "BTMMIFtpGprots.h"
#endif

#include "l4c_common_enum.h"

#ifdef __MMI_DUAL_SIM_MASTER__
#include "MTPNP_AD_master_header.h"
#endif /* __MMI_DUAL_SIM_MASTER__ */

/***************************************************************************** 
* Define
*****************************************************************************/

#if defined(SENSOR_ON_BODY)
#if defined(SENSOR_ROTATE_0)
#define WEBCAM_CLAM_OPEN_ROTATE     MDI_WEBCAM_PREVIEW_ROTATE_0
#define WEBCAM_CLAM_CLOSE_ROTATE    MDI_WEBCAM_PREVIEW_ROTATE_0
#elif defined(SENSOR_ROTATE_180)
#define WEBCAM_CLAM_OPEN_ROTATE     MDI_WEBCAM_PREVIEW_ROTATE_180
#define WEBCAM_CLAM_CLOSE_ROTATE    MDI_WEBCAM_PREVIEW_ROTATE_180
#else 
#define WEBCAM_CLAM_OPEN_ROTATE     MDI_WEBCAM_PREVIEW_ROTATE_0
#define WEBCAM_CLAM_CLOSE_ROTATE    MDI_WEBCAM_PREVIEW_ROTATE_0
#endif 
#elif defined(SENSOR_ON_COVER)
#if defined(SENSOR_ROTATE_0)
#define WEBCAM_CLAM_OPEN_ROTATE     MDI_WEBCAM_PREVIEW_ROTATE_0
#define WEBCAM_CLAM_CLOSE_ROTATE    MDI_WEBCAM_PREVIEW_ROTATE_180
#elif defined(SENSOR_ROTATE_180)
#define WEBCAM_CLAM_OPEN_ROTATE     MDI_WEBCAM_PREVIEW_ROTATE_180
#define WEBCAM_CLAM_CLOSE_ROTATE    MDI_WEBCAM_PREVIEW_ROTATE_0
#else 
#define WEBCAM_CLAM_OPEN_ROTATE     MDI_WEBCAM_PREVIEW_ROTATE_0
#define WEBCAM_CLAM_CLOSE_ROTATE    MDI_WEBCAM_PREVIEW_ROTATE_180
#endif 
#endif /* SENSOR_LOCATION */

#ifdef __USB_IN_NORMAL_MODE__
#define MAX_DEINIT_CALLBACK   sizeof(mmi_usb_deinit_callback)/sizeof(mmi_usb_ms_callback_struct) - 1
#define MAX_REINIT_CALLBACK   sizeof(mmi_usb_reinit_callback)/sizeof(mmi_usb_ms_callback_struct) - 1
#endif /* __USB_IN_NORMAL_MODE__ */ 
/***************************************************************************** 
* Typedef
*****************************************************************************/
#ifdef __USB_IN_NORMAL_MODE__
typedef U8(*ChkFuncPtr) (void);

typedef struct
{
    U16 eventID;
    PsFuncPtr RspHdlr;
    FuncPtr callback;
    ChkFuncPtr checkfunc;
} mmi_usb_ms_callback_struct;
#endif /* __USB_IN_NORMAL_MODE__ */ 
/***************************************************************************** 
* Extern Variable
*****************************************************************************/
extern U8 subMenuData[MAX_SUB_MENUS][MAX_SUB_MENU_SIZE];
extern PU8 subMenuDataPtrs[MAX_SUB_MENUS];
extern charbat_context_struct g_charbat_context;

/***************************************************************************** 
* Extern Functions
*****************************************************************************/
extern void ClearKeyEvents(void);
extern void PopulateResData(void);
extern void InitUnicodeSupport(void);
extern U8 AlmIsRTCPwron(void);
extern void AlmDeInit(void);
extern BOOL IsClamClose(void);
extern void SetClamState(U16 clam_state);
extern void PhnsetReadGPIOSetting(void);
extern void QuitSystemOperation(void);

#ifdef __NVRAM_IN_USB_MS__
extern void InitHardwareEvents(void);
extern void InitSettingBootup(void);
extern void InitProfileApp(void);
extern void InitDownloadNVRAM(void);
extern void initnvramprofapp(void);
extern void InitSettingNVRAM(void);
extern void PhnsetReadNvramCalibrationData(void);
extern void InitRingToneComposer(void);
extern void PmgInitExtMelodyStruct(void);
extern void InitAlarmFrameWork(void);
extern void PendingAlarmReminder(void);
#endif /* __NVRAM_IN_USB_MS__ */ 

#ifdef __MMI_FM_RADIO__
extern void mmi_fmrdo_search_all_channels_stop(void);
#endif 

#ifdef __MMI_AUDIO_PLAYER__
extern void mmi_audply_stop_playing(void);
extern void mmi_audply_do_single_stop_action(void);
extern void mmi_audply_check_list(void);
#endif /* __MMI_AUDIO_PLAYER__ */ 

#ifdef __USB_IN_NORMAL_MODE__
#ifdef WAP_SUPPORT
extern void wap_on_enter_usb_mode(void);
#endif 
#ifdef MMS_SUPPORT
extern void mms_on_enter_usb_mode(void);
extern void mms_on_exit_usb_mode(void);
#endif /* MMS_SUPPORT */ 

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
extern void mmi_tm_init_theme_usb_mode_plugin_callback(void);
extern void mmi_tm_init_theme_usb_mode_plugout_callback(void);
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 
#ifdef __MMI_EBOOK_READER__
extern void mmi_ebook_usb_mode_on(void);
extern void mmi_ebook_usb_mode_off(void);
#endif /* __MMI_EBOOK_READER__ */ 

#ifdef __MMI_MMS_2__
extern void mmi_umms_usb_mode_on(void);
extern void mmi_umms_usb_mode_off(void);
#endif

#ifdef __MMI_MMS_BGSR_SUPPORT__
extern void mmi_mms_bgsr_usb_start_cb(void);
extern void mmi_mms_bgsr_usb_end_cb(void);
#endif /*__MMI_MMS_BGSR_SUPPORT__*/

#endif /* __USB_IN_NORMAL_MODE__ */ 
/***************************************************************************** 
* Local Functions
*****************************************************************************/
#ifdef __MMI_WEBCAM__
static void mmi_usb_webcam_exit_app_scr(void);
static void mmi_usb_webcam_event_hdlr(MDI_RESULT ret, BOOL camera_workable);
static U8 mmi_usb_webcam_del_screen_id_hdlr(void *ptr);
static void mmi_usb_webcam_rsk_release(void);
static void mmi_usb_webcam_capture_key_press(void);
static void mmi_usb_webcam_plug_out(void);


#ifdef __MMI_SUBLCD__
static void mmi_usb_webcam_entry_sublcd_scr(void);
static void mmi_usb_webcam_exit_sublcd_scr(void);
#endif /* __MMI_SUBLCD__ */ 

#if defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__)
static U8 mmi_usb_webcam_gpio_event_hdlr(mmi_frm_int_event_type interrupt_event);
static U8 mmi_usb_webcam_gpio_post_event_hdlr(mmi_frm_int_event_type interrupt_event);

#endif /* defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__) */ 
#endif /* __MMI_WEBCAM__ */ 

#if defined (__USB_IN_NORMAL_MODE__)
static void mmi_usb_hide_file_related_menus(void);
static void mmi_usb_restore_file_related_menus(void);
static MMI_BOOL mmi_usb_need_to_reboot(void);
static void mmi_usb_entry_progress_screen(void);
static void mmi_usb_app_deinit(void *p);
static void mmi_usb_app_reinit(void *p);
static void mmi_usb_send_removal_event_rsp(void *info);
static U8 mmi_usb_mms_check_to_deinit(void);
static U8 mmi_usb_mms_check_to_reinit(void);
#endif /* defined (__USB_IN_NORMAL_MODE__) */ 
static void mmi_usb_send_removal_event_req(void);
static void mmi_usb_send_power_on_req(void);
static void mmi_usb_send_detect_ack(void);

/***************************************************************************** 
* Local Variable
*****************************************************************************/
MMI_USB_CONTEXT g_mmi_usb_cntx;
MMI_USB_CONTEXT *mmi_usb_ptr = &g_mmi_usb_cntx;
static S32 highlightedItemIndex = 0;

#ifdef __USB_IN_NORMAL_MODE__
static MMI_BOOL mmi_usb_is_exported = 0;
static mmi_usb_ms_callback_struct mmi_usb_deinit_callback[] = 
{
    {0, NULL, PhnsetWPUseDefault, NULL},        /* suspend wallpaper */
    {0, NULL, PhnsetSSUseDefault, NULL},        /* suspend screensaver */
#ifdef __MMI_POWER_ON_OFF_DISPLAY__
    {0, NULL, PhnsetPwrOnOffUseDefault, NULL},  /* suspend power on/off disp. */
#endif 
#ifdef __MMI_AUDIO_PLAYER__
    {0, NULL, mmi_audply_stop_playing, NULL},
    {0, NULL, mmi_audply_do_single_stop_action, NULL},
#endif /* __MMI_AUDIO_PLAYER__ */ 
#ifdef __MMI_EMAIL__
    {MSG_ID_MMI_EMAIL_DEINIT_RSP, mmi_email_ps_deinit_rsp, mmi_email_deinit, mmi_email_check_to_deinit},
#endif 
    {0, NULL, fmgr_init_drive, NULL},
#ifdef MMS_SUPPORT
    {MSG_ID_MMS_ENTER_USB_MODE_RSP, NULL, mms_on_enter_usb_mode, mmi_usb_mms_check_to_deinit},
#endif 
#ifdef __MMI_VIDEO_RECORDER__
    {0, NULL, mmi_vdorec_usb_mode_hdlr, NULL},
#endif 
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
    {0, NULL, mmi_tm_init_theme_usb_mode_plugin_callback, NULL},
#endif 
#ifdef __MMI_EBOOK_READER__
    {0, NULL, mmi_ebook_usb_mode_on, NULL},
#endif 
#ifdef __MMI_IRDA_SUPPORT__
    {0, NULL, mmi_irda_obex_snd_abort, mmi_irda_is_sending},
#endif
#ifdef __MMI_DOWNLOAD_AGENT__
    {0, NULL, mmi_da_usb_mode_on, NULL},
#endif
#ifdef __MMI_MMS_2__
    {0, NULL, mmi_umms_usb_mode_on, NULL},
#endif
#ifdef __MMI_MMS_BGSR_SUPPORT__
    {0, NULL, mmi_mms_bgsr_usb_start_cb, NULL},
#endif  /*__MMI_MMS_BGSR_SUPPORT__*/
#if defined(__MMI_OPP_SUPPORT__) && defined(__MMI_BT_MTK_SUPPORT__)
    {0, NULL, mmi_opp_end_key_press_hdler, mmi_opp_is_sending},
#endif

    /* call back when plug in usb mass*/
#if defined(__MMI_BT_MTK_SUPPORT__)  && (defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__))
    {0, NULL, mmi_bt_ftp_usb_plugin_hdle, mmi_bt_ftp_usb_plugin_check},
#endif

    /* add callback before this */
    {0, NULL, NULL, NULL}
};

static mmi_usb_ms_callback_struct mmi_usb_reinit_callback[] = 
{
    {0, NULL, PhnsetReadWallpaper, NULL},           /* resume wallpaper from secondary flash */
    {0, NULL, PhnsetReadNvramScrSvrSettings, NULL}, /* resume screensaver from secondary flash */
#ifdef __MMI_POWER_ON_OFF_DISPLAY__
    {0, NULL, PhnsetReadPwrOnOffDisp, NULL},        /* resume power on/off disp. from secondary flash */
#endif 
#ifdef __MMI_AUDIO_PLAYER__
	{0, NULL, mmi_audply_check_list, NULL},
#endif /* __MMI_AUDIO_PLAYER__ */ 
#ifdef __MMI_EMAIL__
    {MSG_ID_MMI_EMAIL_INIT_RSP, mmi_email_ps_init_rsp, mmi_email_init, mmi_email_check_to_init}, /* initialize email module */
#endif 
    {0, NULL, fmgr_init_drive, NULL},
#ifdef MMS_SUPPORT
    {MSG_ID_MMS_EXIT_USB_MODE_RSP, NULL, mms_on_exit_usb_mode, mmi_usb_mms_check_to_reinit},
#endif 
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
    {0, NULL, mmi_tm_init_theme_usb_mode_plugout_callback, NULL},
#endif 
#ifdef __MMI_EBOOK_READER__
    {0, NULL, mmi_ebook_usb_mode_off, NULL},
#endif 
#ifdef __MMI_MMS_2__
    {0, NULL, mmi_umms_usb_mode_off, NULL},
#endif

#ifdef __MMI_MMS_BGSR_SUPPORT__
    {0, NULL, mmi_mms_bgsr_usb_end_cb, NULL},
#endif /*__MMI_MMS_BGSR_SUPPORT__*/

    /* add callback before this */
    {0, NULL, NULL}
};

static U8 counter_of_deinit = 0;
static U8 counter_of_reinit = 0;

#endif /* __USB_IN_NORMAL_MODE__ */ 


/*****************************************************************************
 * FUNCTION
 *  InitializeUsbScr
 * DESCRIPTION
 *  This function is initial function for usb boot mode
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: void(?)
 *****************************************************************************/
void InitializeUsbScr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    InitUnicodeSupport();

    PhnsetReadGPIOSetting();
    
    InitMMIUsbContext();
    SetUsbStatus(MMI_USBSTATUS_MS);

    MMIUSB_SET_FLAG(MMIUSB_MASK_IS_CONNECT);

    InitFramework();
    setup_UI_wrappers();

    PopulateResData();
    initialize_UI_demo();

    PhnsetSetLangByNvramValue(); 

    ShowUsbScr();
#ifdef __NVRAM_IN_USB_MS__
    InitHardwareEvents();
    InitTime();
    InitMMI_App();

    InitProfileApp();

    initnvramprofapp();

#if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)
    PhnsetReadNvramCalibrationData();
#endif 

    /* InitSettingNVRAM(); */

#ifdef __MMI_PROFILE_EXTMELODY_SUPPORT__
    PmgInitExtMelodyStruct();
#endif 
    PhnsetRestoreToNvramContrast();

    InitAlarmFrameWork();
    mmi_alm_disable_pwroff();

    StartLEDPatternCharging();
    g_charbat_context.PowerOnCharger = 1;
    AnimateStatusIcon(STATUS_ICON_BATTERY_STRENGTH);
    AnimateStatusIcon(STATUS_ICON_SUBLCD_BATTERY_STRENGTH);
    UpdateStatusIcons();

    PendingAlarmReminder();
#endif /* __NVRAM_IN_USB_MS__ */ 

    InitChargerPwrOn();
    InitUsbModeEventHandler();
    /* Enter USB mode will begin charge itself */
    /* Turn this flag on to prevent backlight off */
    g_charbat_context.isChargerConnected = 1;
    TurnOnBacklight(1);
}


/*****************************************************************************
 * FUNCTION
 *  InitMMIUsbContext
 * DESCRIPTION
 *  This function is to initialize the mmi usb context.
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: void(?)
 *****************************************************************************/
void InitMMIUsbContext(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_WEBCAM__
    S32 pause_jpeg_count;
    S32 jpeg_file_len;
    S32 image_width, image_height;
    S32 drv_image_width, drv_image_height;
    S32 i;
    PU8 jpeg_file_ptr;
#endif /* __MMI_WEBCAM__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMIUSB_GET_FLAG(MMIUSB_MASK_BEFORE_POWERON) == MMI_TRUE)
    {
        /* Usb has been pluged in before power on */
        MMI_USB_CTX(usb_status) = MMI_USBSTATUS_PLUGIN;
        MMI_USB_CTX(usb_status_prev) = MMI_USBSTATUS_PLUGOUT;
    }
    else
    {
        /* Usb is not pluged in */
        MMI_USB_CTX(usb_status) = MMI_USBSTATUS_PLUGOUT;
        MMI_USB_CTX(usb_status_prev) = MMI_USBSTATUS_UNKNOW;
    }

    MMI_USB_CTX(ps_port_prev) = uart_port1;
    MMI_USB_CTX(tst_port_prev) = uart_port2;
    MMI_USB_CTX(EndKeyFuncPtr) = NULL;

#ifdef __MMI_WEBCAM__
    mmi_usb_ptr->webcam_state = MMI_USB_WEBCAM_DISCONNECT;
    mmi_usb_ptr->webcam_is_sub_display = FALSE;
    mmi_usb_ptr->webcam_is_clam_close = FALSE;

    /* set pause jpeg file size limit */
    pause_jpeg_count = mdi_webcam_get_pause_jpeg_count();

    for (i = 0; i < pause_jpeg_count; i++)
    {
        gdi_image_get_dimension_id((U16) (IMG_ID_WEBCAM_PAUSE_JPEG_0 + i), &image_width, &image_height);
        mdi_webcam_get_pause_jpeg_info(i, &drv_image_width, &drv_image_height);

        /* jpeg size required by driver has to match the resouce */

        /* get jpeg resource's size and ptr */
        jpeg_file_len = gdi_image_get_buf_len_from_id(IMG_ID_WEBCAM_PAUSE_JPEG_0 + i);
        jpeg_file_ptr = gdi_image_get_buf_ptr_from_id(IMG_ID_WEBCAM_PAUSE_JPEG_0 + i);

        mdi_webcam_set_pause_jpeg_file(i, (PU8) jpeg_file_ptr, jpeg_file_len, image_width, image_height);
    }

#endif /* __MMI_WEBCAM__ */ 

    mmi_usb_ptr->reset_type = CHARGING_RESET;

}


/*****************************************************************************
 * FUNCTION
 *  InitUsbModeEventHandler
 * DESCRIPTION
 *  This function is to initialize the event handler
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: void(?)
 *  GLOBALS AFFECTED: None(?)
 *****************************************************************************/
void InitUsbModeEventHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_frm_key_handle, MSG_ID_MMI_EQ_KEYPAD_DETECT_IND);

    SetProtocolEventHandler(UsbDetectIndHdlr, PRT_EQ_USB_DETECT_IND);
    SetProtocolEventHandler(UsbGpioDetectIndHdlr, PRT_EQ_GPIO_DETECT_IND);
#ifdef __MMI_USB_COPY_RIGHT__
    SetProtocolEventHandler(UsbPowerOnFinishHdlr, PRT_EQ_USB_POWER_ON_FINISH_IND);
#endif 

    /* SetProtocolEventHandler(UsbConfigRspHdlr, PRT_EQ_USBCONFIG_RSP ); */
}

/* ===========================================================================================  */
/* ===  Query Functions  */
/* ===========================================================================================  */


/*****************************************************************************
 * FUNCTION
 *  GetUsbStatus
 * DESCRIPTION
 *  This function is to get the usb state
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: enum MMI_USB_STATUS(?)
 *****************************************************************************/
MMI_USB_STATUS GetUsbStatus(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_STATE, MMI_USB_CUR_STATE, MMI_USB_CTX(usb_status));
    return MMI_USB_CTX(usb_status);
}


/*****************************************************************************
 * FUNCTION
 *  SetUsbStatus
 * DESCRIPTION
 *  This function is to set the usb state
 *  
 *  PARAMETERS: enum MMI_USB_STATUS
 *  state       [IN]        
 *  RETURNS: void(?)
 *****************************************************************************/
void SetUsbStatus(MMI_USB_STATUS state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_STATE, MMI_USB_STATE_TRANSITION, MMI_USB_CTX(usb_status), state);
    MMI_USB_CTX(usb_status_prev) = GetUsbStatus();
    MMI_USB_CTX(usb_status) = state;
}


/*****************************************************************************
 * FUNCTION
 *  GetUsbDefAppSetting
 * DESCRIPTION
 *  This function is to get defined usb port app
 *  
 *  PARAMETERS: enum MMI_USB_STATUS
 *  void
 *  RETURNS: void(?)
 *****************************************************************************/
U8 GetUsbDefAppSetting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 pError;
    U8 app;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_DEFAULT_USB_APP, &app, DS_BYTE, &pError);

    if (pError != NVRAM_READ_SUCCESS)
    {
        app = USB_SWITCH_PORT_APP_DATA;
    }
    else if (app == 0xFF)
    {
        app = USB_SWITCH_PORT_APP_DATA;
        WriteValue(NVRAM_DEFAULT_USB_APP, &app, DS_BYTE, &pError);
    }

    ASSERT((app == USB_SWITCH_PORT_APP_DATA) || (app == USB_SWITCH_PORT_APP_DEBUG));

    return app;
}


/*****************************************************************************
 * FUNCTION
 *  SetUsbBeforePowerOnFlag
 * DESCRIPTION
 *  This function is to set usb plug in/out flag before power on.
 *  (The usb detection indication might come to mmi before power on indication)
 *  
 *  PARAMETERS: void
 *  flag        [IN]        
 *  RETURNS: enum MMI_USB_STATUS(?)
 *****************************************************************************/
void SetUsbBeforePowerOnFlag(BOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (flag == MMI_TRUE)
    {
        MMIUSB_SET_FLAG(MMIUSB_MASK_BEFORE_POWERON);
    }
    else
    {
        MMIUSB_RESET_FLAG(MMIUSB_MASK_BEFORE_POWERON);
    }
}


/*****************************************************************************
 * FUNCTION
 *  PermitUsbCfgScreenDisplay
 * DESCRIPTION
 *  This function check the if usb config screen display allowed or not.
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: T/F(?)
 *****************************************************************************/
BOOL PermitUsbCfgScreenDisplay(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_bootup_is_searching_or_idle_reached() || 
#ifdef __MMI_DUAL_SIM_MASTER__
        MTPNP_PFAL_Is_InCard2securityCheck() ||
#endif    	
        isInCall() || /* During Call */
        IsScreenPresent(GetCmMarkerScrnID()) ||
        GetActiveScreenId() == SCR_RESTORE_PROCESSING ||    /* During Restore Factory */
        GetActiveScreenId() == SCR_ID_SECSET_FDNBDN_WAITING ||    /* During FDN listing */
        GetActiveScreenId() == POPUP_SCREENID ||
        mmi_fmgr_is_busy() ||
        g_phb_cntx.processing ||
        gSecuritySetupContext.PINBlocked ||                 /* PUK needed after SIM lock failed or change PIN1 failed */
#ifdef __MMI_DUAL_SIM_MASTER__
        gSecuritySetupContext.PINBlocked_2 ||
#endif    	
    #if defined(__FOTA_ENABLE__)
        mmi_dm_fwu_is_busy() ||        /* if in firmware upgrade procedure */
    #endif
        mmi_shutdown_is_in_power_off_period())
    {
        MMI_TRACE(MMI_TRACE_G7_MISC, MMI_USB_G7_CONF_SCR_NOT_ALLOW);
        return MMI_FALSE;
    }
    else
    {
        MMI_TRACE(MMI_TRACE_G7_MISC, MMI_USB_G7_CONF_SCR_ALLOW);
        return MMI_TRUE;
    }
}

/* ============================================================================= */
/* ===  Screen Handling Functions  */
/* ============================================================================= */
/*                                                                               */
/*  USB device config screen flow:                                               */
/*                                                                               */
/*  (1) Plug in                                                                  */
/*  ===============                                                              */
/*  == 1. MS     ==                                                              */
/*  == 2. COM    ==                                                              */
/*  ==           ==                                                              */
/*  ==           ==                                                              */
/*  ==           ==                                                              */
/*  ==           ==                                                              */
/*  ===============                                                              */
/*  == OK  = BACK==                                                              */
/*  ===============                                                              */
/*                                                                               */
/*   --> UsbDetectIndHdlr()                                                      */
/*     --> EntryUsbDetectQueryScr()                                              */
/*                                                                               */
/*                                                                               */
/*                                                                               */
/*  (2) Mass storage:                                                            */
/*  ================         ===============          ===============            */
/*  ==            ==         ==           ==          ==           ==            */
/*  == ********** ==         ==  *******  ==          ==     **    ==            */
/*  == * Shut-  * ==         == ********* ==          ==    **     ==            */
/*  == *  Down  * ==         == **+***+** ==          ==   *USB    ==            */
/*  == *  ....  * ==  --->   == ********* ==   --->   ==  ****     ==            */
/*  == *        * ==         == ***&&&*** ==          ==   *MODE   ==            */
/*  == ********** ==         ==  *******  ==          ==   **      ==            */
/*  ==            ==         ==   *****   ==          ==   *  **   ==            */
/*  ================         == Animation ==          ==     **    ==            */
/*  == OK  = BACK ==         ==   .....   ==          ==      **   ==            */
/*  ================         ===============          ===============            */
/* ( Message exchanging      ( Shutdown Ani.)        (Reboot in USB Mode)        */
/* trasition screen 3 sec )                                                      */
/*                                                                               */
/*   -> UsbDetectScrLskHdlr()                           ->InitializeUsbScr()     */
/*    -> UsbConfigFirstPage()                                                    */
/*     -> UsbConfigRspHdlr()                                                     */
/*      -> UsbConfigMassStorage()                                                */
/*                                                                               */
/*                          --> ShutdownSystemOperation()                        */
/*                                                                               */
/*                                                                               */
/*                                                                               */
/*  (2) COM port emulator:                                                       */
/*  ================         ===============                                     */
/*  ==           ===         ==           ==                                     */
/*  == ********** ==         ==  Back     ==                                     */
/*  == * Config * ==         ==       to  ==                                     */
/*  == *  ..... * ==         ==  History  ==                                     */
/*  == *        * ==  --->   ==    Screen ==                                     */
/*  == *        * ==         ==           ==                                     */
/*  == ********** ==         ==           ==                                     */
/*  ==            ==         ==           ==                                     */
/*  ================         ==           ==                                     */
/*  == OK  = BACK ==         ==           ==                                     */
/*  ================         ===============                                     */
/* ( Message exchanging      ( Shutdown Ani.)                                    */
/* trasition screen 3 sec )                                                      */
/*                                                                               */
/*   -> UsbDetectScrLskHdlr()                                                    */
/*    -> UsbConfigFirstPage()                                                    */
/*     -> UsbConfigRspHdlr()                                                     */
/*      -> UsbConfigCDCACM()                                                     */
/*       -> SendUsbGetUartPortToHW()                                             */
/*        -> UsbGetUartPortRspHdlr()                                             */
/*         -> SendUsbUartSwitchToHW()                                            */
/*          -> UsbUartSwitchRspHdlr()                                            */
/*           -> GoBackHistory()                                                  */
/*                                                                               */
/*                                                                               */
/* ============================================================================= */

#ifdef __MMI_SUBLCD__


/*****************************************************************************
 * FUNCTION
 *  ShowSubLCDUsbScr
 * DESCRIPTION
 *  This function is to show sublcd screen for usb boot mode
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: void(?)
 *  GLOBALS AFFECTED : none(?)
 *****************************************************************************/
void ShowSubLCDUsbScr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecSubLCDCurrExitHandler();
    ShowCategory304Screen(IMG_SUB_USB_POWER_ON, 0);
    AnimateStatusIcon(STATUS_ICON_SUBLCD_BATTERY_STRENGTH);
    UpdateStatusIcons();
    SetSubLCDExitHandler(ExitSubLCDUsbScr);
}


/*****************************************************************************
 * FUNCTION
 *  ExitSubLCDUsbScr
 * DESCRIPTION
 *  This function is to exit handler for sublcd screen in usb boot mode
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: void(?)
 *  GLOBALS AFFECTED: none(?)
 *****************************************************************************/
void ExitSubLCDUsbScr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SubLCDHistoryNode SubLCDHistory;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SubLCDHistory.entryFuncPtr = ShowSubLCDUsbScr;
    AddSubLCDHistory(&SubLCDHistory);
}


/*****************************************************************************
 * FUNCTION
 *  ShowSubLCDUsbChgrCmpltScr
 * DESCRIPTION
 *  This function is to show sublcd charging complete screen for usb boot mode
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: void(?)
 *  GLOBALS AFFECTED : none(?)
 *****************************************************************************/
void ShowSubLCDUsbChgrCmpltScr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecSubLCDCurrExitHandler();
    ShowCategory304Screen(IMG_USB_SUB_CHGR_CMPLT, 0);
    HideStatusIcon(STATUS_ICON_SUBLCD_BATTERY_STRENGTH);
    ShowStatusIcon(STATUS_ICON_SUBLCD_BATTERY_STRENGTH);
    UpdateStatusIcons();
    SetSubLCDExitHandler(ExitSubLCDUsbChgrCmpltScr);
}


/*****************************************************************************
 * FUNCTION
 *  ExitSubLCDUsbChgrCmpltScr
 * DESCRIPTION
 *  This function is to exit handler for sublcd charging complete screen in usb boot mode
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: void(?)
 *  GLOBALS AFFECTED: none(?)
 *****************************************************************************/
void ExitSubLCDUsbChgrCmpltScr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SubLCDHistoryNode SubLCDHistory;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SubLCDHistory.entryFuncPtr = ShowSubLCDUsbChgrCmpltScr;
    AddSubLCDHistory(&SubLCDHistory);
}

#endif /* __MMI_SUBLCD__ */ 


/*****************************************************************************
 * FUNCTION
 *  ShowUsbChgCmpltScr
 * DESCRIPTION
 *  This function is to display main screen for usb boot mode
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: none(?)
 *****************************************************************************/
void ShowUsbChgCmpltScr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMIUSB_GET_FLAG(MMIUSB_MASK_IS_CONNECT))
    {

        EntryNewScreen(SCR_USB_CHGR_CMPLT, NULL, ShowUsbChgCmpltScr, NULL);
        DinitHistory();
        ShowCategory9Screen(0, IMG_USB_CHGR_CMPLT, NULL);

    #ifdef __MMI_SUBLCD__
        ChangeStatusIconLevel(STATUS_ICON_SUBLCD_BATTERY_STRENGTH, 100);
        ShowSubLCDScreen(ShowSubLCDUsbChgrCmpltScr);
    #endif /* __MMI_SUBLCD__ */ 

        ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    #ifndef __MMI_POWER_ON_OFF_BY_POWER_KEY__
        SetKeyHandler(UsbPwnOnThenPwnOn, KEY_END, KEY_LONG_PRESS);
    #endif
        SetKeyHandler(UsbPwnOnThenPwnOn, KEY_POWER, KEY_LONG_PRESS);        
    }
    else
    {
        QuitSystemOperation();
    }
        
}


/*****************************************************************************
 * FUNCTION
 *  ShowUsbScr
 * DESCRIPTION
 *  This function is to display main screen for usb boot mode
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: none(?)
 *****************************************************************************/
void ShowUsbScr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_usb_ptr->current_img)
    {
        mmi_usb_ptr->current_img = IMG_USB_POWER_ON;    /* Still image */
    }

    EntryNewScreen(SCR_USB_POWER_ON, NULL, ShowUsbScr, NULL);

    DinitHistory();

#ifdef __MMI_USB_COPY_RIGHT__
    ShowCategory65Screen((U8*) GetString(STR_USB_POWER_ON_PROCESSING), 0, NULL);
#else 
    ShowCategory106Screen(mmi_usb_ptr->current_img, NULL, NULL);
#endif 

#ifdef __MMI_SUBLCD__
    ShowSubLCDScreen(ShowSubLCDUsbScr);
#endif 

#ifndef __MMI_POWER_ON_OFF_BY_POWER_KEY__
    SetKeyHandler(UsbPwnOnThenPwnOn, KEY_END, KEY_LONG_PRESS);
#endif
    SetKeyHandler(UsbPwnOnThenPwnOn, KEY_POWER, KEY_LONG_PRESS);        
}


/*****************************************************************************
 * FUNCTION
 *  EntryUsbDetectQueryScr
 * DESCRIPTION
 *  This function is to display "Usb Config:" screen as received USB_DETECT_IND
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: none(?)
 *****************************************************************************/
void EntryUsbDetectQueryScr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Watch out: must check PermitUsbCfgScreenDisplay first */

    U8 *guiBuffer = NULL;
    U8 *listItemsIcons[8];
    S32 idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_USB_FUNC_DETECT_QUERY_SCR);

   /*************************************************/
    /* Turn on backlight before execute exit handler */
    /* Turn on backlight will blt out the LCD buffer */
    /* If execute exit handler before turn on BL     */
    /* migh see the blue background because turn on  */
    /* BL only blt out layer 0, in idle screen,      */
    /* layer 0 is not wallpaper, wallpaper locate at */
    /* layre 1.                                      */
   /*************************************************/

    TurnOnBacklight(1);
    /* EntryNewScreen will clear all key handler */
    MMI_USB_CTX(EndKeyFuncPtr) = GetKeyHandler(KEY_END, KEY_EVENT_DOWN);
    
    EntryNewScreen(SCR_DEV_USBDETECT, ExitUsbDetectQueryScr, EntryUsbDetectQueryScr, NULL);
    DeleteScreenIfPresent(SCR_DEV_USBDETECT);

#if defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__)        /* 041205 Calvin modified */
    entry_full_screen();
#endif 

    /* Set mmi usb status */
    SetUsbStatus(MMI_USBSTATUS_CONF_PAGE);

#if (defined(__MMI_USB_CDCACM_ONLY__) || defined(__MMI_USB_MS_ONLY__))
    {
        U16 str_title;

    #ifdef __MMI_USB_CDCACM_ONLY__

        /* CDCACM Mode only */
        highlightedItemIndex = MMI_USB_CONFIG_MENU_CDCACM;
        str_title = STR_USB_CONFIG_CDCACM_ONLY;

    #else /* __MMI_USB_CDCACM_ONLY__ */ /* __MMI_USB_MS_ONLY__ */

        /* MS Mode only */
        highlightedItemIndex = MMI_USB_CONFIG_MENU_MS;
        str_title = STR_USB_CONFIG_MS_ONLY;

    #endif /* __MMI_USB_CDCACM_ONLY__ */ 

        ShowCategory165Screen(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            get_string(str_title),
            IMG_GLOBAL_QUESTION,
            0);
    }

#else /* (defined(__MMI_USB_CDCACM_ONLY__) || defined(__MMI_USB_MS_ONLY__)) */ 

    /* Both Mass Storage and CDCACM mode */
    if (g_pwr_context.PowerOnMode == POWER_ON_KEYPAD || g_pwr_context.PowerOnMode == POWER_ON_EXCEPTION)
    {

        /* If normal power on, display selection menus (MS/COM) */

        RegisterHighlightHandler(UsbDetectScrHlightHdlr);

        memset(listItemsIcons, 0, sizeof(listItemsIcons));
        memset(subMenuDataPtrs, 0, sizeof(subMenuDataPtrs));

        idx = 0;
        subMenuDataPtrs[idx++] = (PU8) GetString(STR_USB_CONFIG_MS);

    #ifdef __MMI_WEBCAM__
        subMenuDataPtrs[idx++] = (PU8) GetString(STR_ID_USB_CONFIG_WEBCAM);
    #endif 

        subMenuDataPtrs[idx++] = (PU8) GetString(STR_USB_CONFIG_CDCACM_DATA);

    #ifdef __MMI_PICT_BRIDGE_SUPPORT__
        subMenuDataPtrs[idx++] = (PU8) GetString(STR_USB_CONFIG_PICT_BRIGE);    
    #endif

        ShowCategory32Screen(
            (PU8) GetString(STR_USB_CONFIG_TITLE),
            NULL,
            (PU8) GetString(STR_GLOBAL_OK),
            (PU8) GetImage(IMG_GLOBAL_OK),
            (PU8) GetString(STR_GLOBAL_BACK),
            (PU8) GetImage(IMG_GLOBAL_BACK),
            idx,
            subMenuDataPtrs,
            listItemsIcons,
            0,
            0,
            guiBuffer);
    }
    else
    {
        /* If alarm/charger power on, display MS config confirm */

        ShowCategory165Screen(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            get_string(STR_USB_CONFIG_MS_ONLY),
            IMG_GLOBAL_QUESTION,
            0);
    }

#endif /* (defined(__MMI_USB_CDCACM_ONLY__) || defined(__MMI_USB_MS_ONLY__)) */ 

    SetLeftSoftkeyFunction(UsbDetectScrLskHdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(UsbDetectScrRskHdlr, KEY_EVENT_UP);

    SetKeyHandler(UsbDetectScrENDKeyHdlr, KEY_END, KEY_EVENT_DOWN);

#ifdef __MMI_FM_RADIO__
    mmi_fmrdo_search_all_channels_stop();
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  ExitUsbDetectQueryScr
 * DESCRIPTION
 *  This function is exit handler for  "Usb Config:" screen
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: none(?)
 *****************************************************************************/
void ExitUsbDetectQueryScr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_USB_FUNC_EXIT_DETECT_QUERY_SCR);
#if defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__)        /* 041205 Calvin modified */
    leave_full_screen();
#endif 
    /*
     * history currHistory;
     * currHistory.scrnID = SCR_DEV_USBDETECT;
     * currHistory.entryFuncPtr = EntryUsbDetectQueryScr;
     * mmi_ucs2cpy((S8*)currHistory.inputBuffer, (S8*)L"");
     * GetCategory32History (currHistory.guiBuffer);
     * AddHistory (currHistory);
     */

}

/* ============================================================================= */
/* ===  Message Handling  Function  */
/* ============================================================================= */
/*                                                                               */
/*  USB device config message flow:                                              */
/*                                                                               */
/*  (1) Mass storage:                                                            */
/*                                                                               */
/*     MMI                               L4                                      */
/*   ========                          =======                                   */
/*      |                                 |                                      */
/*      |   MSG_ID_MMI_EQ_USBDETECT_IND   |                                      */
/*      |<--------------------------------|                                      */
/*      |                                 |                                      */
/*      |                                 |                                      */
/*      |   MSG_ID_MMI_EQ_USBCONFIG_REQ   |                                      */
/*      |-------------------------------->|                                      */
/*      |                                 |                                      */
/*      |                                 |                                      */
/*      |   MSG_ID_MMI_EQ_USBCONFIG_RSP   |                                      */
/*      |<--------------------------------|                                      */
/*      |                                 |                                      */
/*      |                                 |                                      */
/*      |   MSG_ID_MMI_EQ_POWER_OFF_REQ   |                                      */
/*      |-------------------------------->|                                      */
/*      |                                 |                                      */
/*      |                                 |                                      */
/*      |   MSG_ID_MMI_EQ_POWER_OFF_RSP   |                                      */
/*      |<--------------------------------|                                      */
/*      |                                 |                                      */
/*      |                                 |                                      */
/*      |   MSG_ID_MMI_EQ_POWER_ON_IND    |                                      */
/*      |<--------------------------------|                                      */
/*      |                                 |                                      */
/*      |                                 |                                      */
/*      |                                 |                                      */
/*   ========                          =======                                   */
/*                                                                               */
/*                                                                               */
/*                                                                               */
/*                                                                               */
/*  (2) COM Port emulator:                                                       */
/*                                                                               */
/*     MMI                               L4                                      */
/*   ========                          =======                                   */
/*      |                                 |                                      */
/*      |   MSG_ID_MMI_EQ_USBDETECT_IND   |                                      */
/*      |<--------------------------------|                                      */
/*      |                                 |                                      */
/*      |                                 |                                      */
/*      |   MSG_ID_MMI_EQ_USBCONFIG_REQ   |                                      */
/*      |-------------------------------->|                                      */
/*      |                                 |                                      */
/*      |                                 |                                      */
/*      |   MSG_ID_MMI_EQ_USBCONFIG_RSP   |                                      */
/*      |<--------------------------------|                                      */
/*      |                                 |                                      */
/*  ##########################################################################   */
/*  #   |                                 |    ** Interface change 040927 ** #   */
/*  #   |                                 |    L4C will switch specified app #   */
/*  #   |   MSG_ID_MMI_EQ_GET_UART_REQ    |    to usb port and store the     #   */
/*  #   |-------------------------------->|    previous port. When USB device#   */
/*  #   |                                 |    plug out, will switch back    #   */
/*  #   |                                 |    by L4C itself, so it is not   #   */
/*  #   |   MSG_ID_MMI_EQ_GET_UART_RSP    |    necessary to get UART and     #   */
/*  #   |<--------------------------------|    keep in MMI again.            #   */
/*  #   |                                 |                                  #   */
/*  ##########################################################################   */
/*      |                                 |                                      */
/*      |                                 |                                      */
/*      MSG_ID_MMI_EQ_USBUART_SWITCH_PORT_REQ                                    */
/*      |<--------------------------------|                                      */
/*      |                                 |                                      */
/*      |                                 |                                      */
/*      |                                 |                                      */
/*      MSG_ID_MMI_EQ_USBUART_SWITCH_PORT_RSP                                    */
/*      |-------------------------------->|                                      */
/*      |                                 |                                      */
/*      |                                 |                                      */
/*      |                                 |                                      */
/*   ========                          =======                                   */
/*                                                                               */
/*                                                                               */
/*                                                                               */
/* ============================================================================= */


/*****************************************************************************
 * FUNCTION
 *  UsbDetectScrHlightHdlr
 * DESCRIPTION
 *  This function assign the highlight item (usb function) for usb config.
 *  
 *  PARAMETERS: highlight function idx
 *  index       [IN]        
 *  RETURNS: void(?)
 *****************************************************************************/
void UsbDetectScrHlightHdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    highlightedItemIndex = index;
}


/*****************************************************************************
 * FUNCTION
 *  UsbDetectScrENDKeyHdlr
 * DESCRIPTION
 *  This function is END key handler at usb config page.
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: void(?)
 *****************************************************************************/
void UsbDetectScrENDKeyHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_USB_FUNC_DETECT_SCR_END_KEY_HDLR);

    if (GetUsbStatus() == MMI_USBSTATUS_CONF_PAGE)
    {
        GoBackHistory();
    }
    else
    {
        DeleteScreenIfPresent(SCR_DEV_USBDETECT);
    }

    SetUsbStatus(MMI_USBSTATUS_IGNORED);

}


/*****************************************************************************
 * FUNCTION
 *  UsbDetectScrRskHdlr
 * DESCRIPTION
 *  This function is right softkey handler at usb config page.
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: void(?)
 *****************************************************************************/
void UsbDetectScrRskHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetScreenCountInHistory())
    {
        GoBackHistory();
        DeleteScreenIfPresent(SCR_DEV_USBDETECT);
        SetUsbStatus(MMI_USBSTATUS_IGNORED);
    }
    else
    {
        QuitSystemOperation();
    }
}


/*****************************************************************************
 * FUNCTION
 *  UsbDetectScrLskHdlr
 * DESCRIPTION
 *  This function is left softkey handler at usb config page.
 *  (Press left softkey means start to config usb device as certain function)
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: void(?)
 *  GLOBALS AFFECTED: highlightedItemIndex, the usb function index(?)
 *****************************************************************************/
void UsbDetectScrLskHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (highlightedItemIndex)
    {

        case MMI_USB_CONFIG_MENU_MS:    /* MASS Storage */
            MMI_TRACE(MMI_TRACE_G7_MISC, MMI_USB_G7_CONF_AS_MS);
            UsbConfigFirstPage(DEVUSB_CFG_ACTION_MASS_STORAGE);
            break;

    #ifdef __MMI_WEBCAM__
        case MMI_USB_CONFIG_MENU_WEBCAM:    /* Webcam */
            UsbConfigFirstPage(DEVUSB_CFG_ACTION_WEBCAM);
            break;
    #endif /* __MMI_WEBCAM__ */ 

        case MMI_USB_CONFIG_MENU_CDCACM:    /* Com port emulator */
            MMI_TRACE(MMI_TRACE_G7_MISC, MMI_USB_G7_CONF_AS_CDCACM);
            UsbConfigFirstPage(DEVUSB_CFG_ACTION_CDC_ACM);
            break;

    #ifdef __MMI_PICT_BRIDGE_SUPPORT__
        case MMI_USB_CONFIG_MENU_PICTBRIGE:
    #ifdef MMI_ON_HARDWARE_P
            UsbConfigFirstPage(DEVUSB_CFG_ACTION_PICTBRIGE);
    #else /* MMI_ON_HARDWARE_P */ 
            GoBackHistory();
    #endif /* MMI_ON_HARDWARE_P */             
            break;
    #endif

        case MMI_USB_CONFIG_MENU_RESERVED:  /* reserved */
        default:
            MMI_TRACE(MMI_TRACE_G7_MISC, MMI_USB_G7_CONF_AS_NOTHING);
            GoBackHistory();
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  PendingUsbDetectionTimeoutHdlr
 * DESCRIPTION
 *  This function try to display usb config screen if usb device still there.
 *  If could not display, will wait a period of time and retry again.
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: void(?)
 *  GLOBALS AFFECTED: none(?)
 *****************************************************************************/
void PendingUsbDetectionTimeoutHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_USB_STATUS usb_state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_USB_FUNC_PEND_DETECT_TIMEOUT);

    usb_state = GetUsbStatus();

    if (usb_state == MMI_USBSTATUS_PLUGIN)
    {
    	PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[USB PendingTimeoutHdlr] cur_state:plug-in");
    	MMI_TRACE(MMI_TRACE_STATE, MMI_USB_STATE_TRANSITION, MMI_USB_CTX(usb_status_prev), MMI_USB_CTX(usb_status));
    	
        StopTimer(PENDING_USBDETECTION_HDLR_TIMER);

        MMIUSB_RESET_FLAG(MMIUSB_MASK_PENDING_TIMER);

        if (PermitUsbCfgScreenDisplay() == MMI_TRUE)
        {
            MMI_TRACE(MMI_TRACE_G7_MISC, MMI_USB_G7_PEND_DETECT_TIMEOUT_ALLOW);
            EntryUsbDetectQueryScr();
        }
        else
        {
            MMI_TRACE(MMI_TRACE_G7_MISC, MMI_USB_G7_PEND_DETECT_TIMEOUT_NOT_ALLOW);
            PendingUsbDetectionHdlr();
        }
    }
    else if (usb_state == MMI_USBSTATUS_PLUGOUT && MMIUSB_GET_FLAG(MMIUSB_MASK_IS_CONNECT))
    {
    	PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[USB PendingTimeoutHdlr] cur_state:plug-out");
    	MMI_TRACE(MMI_TRACE_STATE, MMI_USB_STATE_TRANSITION, MMI_USB_CTX(usb_status_prev), MMI_USB_CTX(usb_status));
    
        SetUsbStatus(MMI_USBSTATUS_PLUGIN);

        if (PermitUsbCfgScreenDisplay() == MMI_TRUE)
        {
            EntryUsbDetectQueryScr();
        }
        else
        {
            PendingUsbDetectionHdlr();
        }
    }
#ifdef __USB_IN_NORMAL_MODE__
    else if (mmi_usb_is_leaving_ms_mode())
    {
    	PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[USB PendingTimeoutHdlr] cur_state:leaving ms");
    	MMI_TRACE(MMI_TRACE_STATE, MMI_USB_STATE_TRANSITION, MMI_USB_CTX(usb_status_prev), MMI_USB_CTX(usb_status));

        StopTimer(PENDING_USBDETECTION_HDLR_TIMER);
        StartTimer(
            PENDING_USBDETECTION_HDLR_TIMER,
            PENDING_USBDETECTION_HDLR_TIMER_DUR,
            PendingUsbDetectionTimeoutHdlr);
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  PendingUsbDetectionHdlr
 * DESCRIPTION
 *  This function is to handle panding usb detection event. When usb detected
 *  at critical time and is not allow to display config screen, the detected event
 *  will be pending. After the time over, shall call this to deal with the pending
 *  event. This will start a timer then show config screen to prevent screen overlap
 *  case by function call.
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: void(?)
 *  GLOBALS AFFECTED: none(?)
 *****************************************************************************/
void PendingUsbDetectionHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_USB_STATUS usb_state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_USB_FUNC_START_TIMER);

    usb_state = GetUsbStatus();

    switch (usb_state)
    {
        case MMI_USBSTATUS_PLUGIN:
    #ifdef __USB_IN_NORMAL_MODE__
        case MMI_USBSTATUS_MS_PROC:
    #endif 
        {
            MMI_TRACE(MMI_TRACE_G7_MISC, MMI_USB_G7_START_PEND_TIMEER);

            MMIUSB_SET_FLAG(MMIUSB_MASK_PENDING_TIMER);
            StartTimer(
                PENDING_USBDETECTION_HDLR_TIMER,
                PENDING_USBDETECTION_HDLR_TIMER_DUR,
                PendingUsbDetectionTimeoutHdlr);
            break;
        }
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  UsbGpioDetectIndHdlr
 * DESCRIPTION
 *  This function is usb mode battery status indication handler
 *  
 *  PARAMETERS: void
 *  info        [?]     
 *  RETURNS: void(?)
 *  GLOBALS AFFECTED: none(?)
 *****************************************************************************/
void UsbGpioDetectIndHdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_gpio_detect_ind_struct *gpioDetectInd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gpioDetectInd = (mmi_eq_gpio_detect_ind_struct*) info;

    switch (gpioDetectInd->gpio_device)
    {

    #ifdef __MMI_CLAMSHELL__

            /* Clam open */
        case EXT_DEV_CLAM_OPEN:
            gMMIClamState = 1;
            if (mmi_bootup_is_in_power_on_period() == MMI_FALSE)
            {
                /* lcd_backlight = 0; */
                if (AlmIsRTCPwron())
                {
                    TurnOnBacklight(0);
                }
                else
                {
                    TurnOnBacklight(1);
                }
            }
            break;

            /* Clam close */
        case EXT_DEV_CLAM_CLOSE:
            gMMIClamState = 0;

            if (mmi_bootup_is_in_power_on_period() == MMI_FALSE)
            {
                CloseBacklight();
            }

            break;

    #endif /* __MMI_CLAMSHELL__ */ 

        default:
            break;
    }

    /* Robin 0715: Popup screen display permisstion flag */
    /* Shall reset this flag in the end of msg handler func */
    SetInterruptPopupDisplay(POPUP_ALL_ON);
}

#ifdef __MMI_USB_COPY_RIGHT__


/*****************************************************************************
 * FUNCTION
 *  UsbPowerOnFinishHdlr
 * DESCRIPTION
 *  This function is usb power on finish indication event handler
 *  
 *  PARAMETERS: void
 *  info        [?]     
 *  RETURNS: void(?)
 *  GLOBALS AFFECTED: none(?)
 *****************************************************************************/
void UsbPowerOnFinishHdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_USB_POWER_ON_DONE, NULL, (FuncPtr) UsbPowerOnFinishHdlr, NULL);

    DinitHistory();

    ShowCategory106Screen(IMG_USB_POWER_ON, NULL, NULL);

#ifdef __MMI_SUBLCD__
    ShowSubLCDScreen(ShowSubLCDUsbScr);
#endif 

#ifndef __MMI_POWER_ON_OFF_BY_POWER_KEY__
    SetKeyHandler(UsbPwnOnThenPwnOn, KEY_END, KEY_LONG_PRESS);
#endif 
    SetKeyHandler(UsbPwnOnThenPwnOn, KEY_POWER, KEY_LONG_PRESS);        
   
}
#endif /* __MMI_USB_COPY_RIGHT__ */ 


/*****************************************************************************
 * FUNCTION
 *  UsbDetectIndHdlr
 * DESCRIPTION
 *  This function is usb detect indication event handler
 *  
 *  PARAMETERS: void
 *  info        [?]     
 *  RETURNS: void(?)
 *  GLOBALS AFFECTED: none(?)
 *****************************************************************************/
void UsbDetectIndHdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_usbdetect_ind_struct *p = (mmi_eq_usbdetect_ind_struct*) info;
    MMI_USB_STATUS usb_state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_USB_FUNC_DETECT_SCR);

    usb_state = GetUsbStatus();

    if (p->action == DEVUSB_DETECT_ACTION_PLUGIN)
    {
        MMI_TRACE(MMI_TRACE_G7_MISC, MMI_USB_G7_DETECT_SCR_PLUGIN);

        MMIUSB_SET_FLAG(MMIUSB_MASK_IS_CONNECT);

        if (mmi_bootup_is_before_power_on() == MMI_TRUE)
        {
            SetUsbBeforePowerOnFlag(MMI_TRUE);
            SetUsbStatus(MMI_USBSTATUS_PLUGIN);
            PendingUsbDetectionHdlr();
        }
        else
        {
            switch (usb_state)
            {
                case MMI_USBSTATUS_PLUGOUT:
                {
                    SetUsbStatus(MMI_USBSTATUS_PLUGIN);

                    if (PermitUsbCfgScreenDisplay() == MMI_TRUE)
                    {
                        if (MMIUSB_GET_FLAG(MMIUSB_MASK_PENDING_TIMER))
                        {
                            MMIUSB_RESET_FLAG(MMIUSB_MASK_PENDING_TIMER);
                            StopTimer(PENDING_USBDETECTION_HDLR_TIMER);
                        }

                        EntryUsbDetectQueryScr();
                    }
                    else
                    {
                        PendingUsbDetectionHdlr();
                    }
                }
                    break;

                case MMI_USBSTATUS_MS:
                    /* USB power on */
                    break;

                case MMI_USBSTATUS_MS_PROC:
                {
                #ifdef __USB_IN_NORMAL_MODE__
                    PendingUsbDetectionHdlr();
                #endif /* __USB_IN_NORMAL_MODE__ */ 
                    break;
                }
                case MMI_USBSTATUS_CDCACM_PROC:
                    /* case MMI_USBSTATUS_CDCACM_SWCHPORT: */
                case MMI_USBSTATUS_UNKNOW:
                case MMI_USBSTATUS_PLUGIN:
                case MMI_USBSTATUS_CONF_PAGE:
                case MMI_USBSTATUS_IGNORED:
                case MMI_USBSTATUS_CDCACM:
                case MMI_USBSTATUS_WEBCAM:
                case MMI_USBSTATUS_PICTBRIGE:
                default:
            #ifndef __PRODUCTION_RELEASE__
                    ASSERT(0);
            #endif 
                    break;
            }
        }
    }   /* p->action == DEVUSB_DETECT_ACTION_PLUGIN */
    else if (p->action == DEVUSB_DETECT_ACTION_PLUGOUT)
    {
        MMI_TRACE(MMI_TRACE_G7_MISC, MMI_USB_G7_DETECT_SCR_PLUGOUT);

        StopTimer(PENDING_USBDETECTION_HDLR_TIMER);

        MMIUSB_RESET_FLAG(MMIUSB_MASK_IS_CONNECT);

        if (mmi_bootup_is_before_power_on() == MMI_TRUE)
        {
            SetUsbBeforePowerOnFlag(MMI_FALSE);
            StopTimer(PENDING_USBDETECTION_HDLR_TIMER);
            SetUsbStatus(MMI_USBSTATUS_PLUGOUT);
        }
        else
        {
            switch (usb_state)
            {
                case MMI_USBSTATUS_CONF_PAGE:
                {
                    /* Show the remove popup, then go on */
                    BatteryIndicationPopup(STR_USB_CHARGER_REMOVED);
                    /* detect last query screen is in history */
                    DeleteScreenIfPresent(SCR_DEV_USBDETECT);
                    SetUsbStatus(MMI_USBSTATUS_PLUGOUT);
                    break;
                }
            #ifdef __MMI_PICT_BRIDGE_SUPPORT__
                case MMI_USBSTATUS_PICTBRIGE:
                    /* notify pict_brige usb plug-out event */
                    mmi_pict_dps_disconnect_ind();
            #endif /* __MMI_PICT_BRIDGE_SUPPORT__ */
                case MMI_USBSTATUS_CDCACM:
                case MMI_USBSTATUS_CDCACM_PROC:
                case MMI_USBSTATUS_PLUGIN:
                case MMI_USBSTATUS_IGNORED:    
                    /* Show the remove popup, then go on */
                    if (mmi_bootup_is_in_power_on_period() == MMI_FALSE)
                    {
                        BatteryIndicationPopup(STR_USB_CHARGER_REMOVED);
                    }
                case MMI_USBSTATUS_PLUGOUT:
                {
                    DeleteScreenIfPresent(SCR_DEV_USBDETECT);
                    SetUsbStatus(MMI_USBSTATUS_PLUGOUT);
                    break;
                }
                case MMI_USBSTATUS_MS_PROC:
                case MMI_USBSTATUS_MS:
                {
                #if defined(__USB_IN_NORMAL_MODE__) || defined(__NVRAM_IN_USB_MS__)
                    mmi_usb_send_removal_event_req();
                #else 
                    DeleteScreenIfPresent(SCR_DEV_USBDETECT);
                #endif 
                    break;
                }
            #ifdef __MMI_WEBCAM__
                case MMI_USBSTATUS_WEBCAM:
                {
                    DeleteScreenIfPresent(SCR_DEV_USBDETECT);
                    BatteryIndicationPopup(STR_USB_CHARGER_REMOVED);                    
                    mmi_usb_webcam_plug_out();
                    SetUsbStatus(MMI_USBSTATUS_PLUGOUT);
                    break;
                }
            #endif /* __MMI_WEBCAM__ */ 

                case MMI_USBSTATUS_UNKNOW:
                default:
                {
                #ifndef __PRODUCTION_RELEASE__
                    ASSERT(0);
                #endif 
                    DeleteScreenIfPresent(SCR_DEV_USBDETECT);
                    SetUsbStatus(MMI_USBSTATUS_PLUGOUT);
                    break;
                }
            }
        }
    }
    else
    {
        ASSERT(0);
    }

    mmi_usb_send_detect_ack();

}


/*****************************************************************************
 * FUNCTION
 *  UsbConfigFirstPage
 * DESCRIPTION
 *  Display transition screen and send usb config request (MSG_ID_MMI_EQ_USBCONFIG_REQ) to HW
 *  
 *  PARAMETERS: mode, ms or cdcacm
 *  mode        [IN]        
 *  RETURNS: void(?)
 *  GLOBALS AFFECTED: none(?)
 *****************************************************************************/
void UsbConfigFirstPage(U8 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
//#if defined(__MMI_ONLY_ONE_UART_AVAILABLE__)
    U8 ps_port;
    U32 ps_baudrate;
//#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_USB_FUNC_CONF_FIRST_PAGE, mode);

    if ( (GetUsbStatus() == MMI_USBSTATUS_PLUGOUT)||
         (isInCall()))
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_UNFINISHED),
            IMG_GLOBAL_UNFINISHED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
        DeleteScreenIfPresent(SCR_DEV_USBDETECT);
        return;
    }
#ifdef __MMI_IRDA_SUPPORT__
    else if (mode == DEVUSB_CFG_ACTION_CDC_ACM && mmi_irda_is_ircomm_active() == MMI_TRUE)
    {
        /* currently, when IrComm is active, switch port not allow! */
        DisplayPopup(
            (PU8) GetString(STR_ID_USB_IRCOMM_OCCUPY_CDCACM),
            IMG_GLOBAL_UNFINISHED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
        DeleteScreenIfPresent(SCR_DEV_USBDETECT);
        return;
    }
#endif /* __MMI_IRDA_SUPPORT__ */ 

#ifdef __MMI_WEBCAM__
    if (mode == DEVUSB_CFG_ACTION_WEBCAM)
    {
        MMI_ASSERT(mmi_usb_ptr->webcam_state == MMI_USB_WEBCAM_DISCONNECT);

        mmi_usb_ptr->webcam_state = MMI_USB_WEBCAM_CONNECTED;

        mmi_usb_webcam_entry_app_scr();
        DeleteScreenIfPresent(SCR_DEV_USBDETECT);
        return;
    }
#endif /* __MMI_WEBCAM__ */ 

//#if defined(__MMI_ONLY_ONE_UART_AVAILABLE__)
    if (mode == DEVUSB_CFG_ACTION_CDC_ACM)
    {
        nvram_get_ps(&ps_port, &ps_baudrate);

        if (ps_port == uart_port_null)
        {
            DisplayPopup((PU8) GetString(STR_ID_USB_UART2_OCCUPIED),
                          IMG_GLOBAL_ERROR,
                          1,
                          UI_POPUP_NOTIFYDURATION_TIME,
                          ERROR_TONE);
        
            DeleteScreenIfPresent(SCR_DEV_USBDETECT);
            return;
        }
    }
//#endif /* __MMI_ONLY_ONE_UART_AVAILABLE__ */

    EntryNewScreen(GLOBAL_SCR_DUMMY, NULL, NULL, NULL);

    DeleteScreenIfPresent(SCR_DEV_USBDETECT);

    ClearKeyEvents();
    ClearInputEventHandler(MMI_DEVICE_KEY);
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);

    if (mode == DEVUSB_CFG_ACTION_MASS_STORAGE)
    {
    #ifdef __USB_IN_NORMAL_MODE__
        if (!mmi_usb_need_to_reboot())
        {

            mmi_usb_entry_progress_screen();

        #ifdef WAP_SUPPORT
            if (mmi_usb_is_network_services_available() == MMI_TRUE)
            {
                if (!wap_is_ready())
                {
                    DisplayPopup(
                        (PU8) GetString(STR_ID_USB_SYS_NOT_READY),
                        IMG_GLOBAL_WARNING,
                        1,
                        UI_POPUP_NOTIFYDURATION_TIME,
                        WARNING_TONE);
                    DeleteScreenIfPresent(SCR_ID_USB_PROGRESS);
                    SetUsbStatus(MMI_USBSTATUS_IGNORED);

                    return;
                }
            }
        #endif

        #ifdef MMS_SUPPORT
            if (mmi_usb_is_network_services_available() == MMI_TRUE)
            {
                if (!mma_is_ready_for_usb())
                {
                    DisplayPopup(
                        (PU8) GetString(STR_ID_USB_SYS_NOT_READY),
                        IMG_GLOBAL_WARNING,
                        1,
                        UI_POPUP_NOTIFYDURATION_TIME,
                        WARNING_TONE);
                    DeleteScreenIfPresent(SCR_ID_USB_PROGRESS);
                    SetUsbStatus(MMI_USBSTATUS_IGNORED);

                    return;
                }
            }
        #endif /* MMS_SUPPORT */

            mmi_usb_is_exported = mmi_usb_is_any_exported_drive();
        #if defined(__MSDC_NOT_SUPPORT_HOT_PLUG__) || defined(__MSDC_TFLASH_DAT3_1BIT_HOT_PLUG__)
            if (!mmi_usb_is_exported)
            {
                DisplayPopup(
                    (PU8) GetString(STR_ID_USB_NO_MS_FOR_PC),
                    IMG_GLOBAL_WARNING,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    WARNING_TONE);
                DeleteScreenIfPresent(SCR_ID_USB_PROGRESS);
                SetUsbStatus(MMI_USBSTATUS_IGNORED);
            }
            else
        #endif /* defined(__MSDC_NOT_SUPPORT_HOT_PLUG__) || defined(__MSDC_TFLASH_DAT3_1BIT_HOT_PLUG__) */ 
            {
                SetUsbStatus(MMI_USBSTATUS_MS_PROC);
                mmi_usb_hide_file_related_menus();
                mmi_usb_app_deinit(NULL);
            }
        }
        else
    #endif /* __USB_IN_NORMAL_MODE__ */ 
        {
            ShowCategory64Screen(STR_USB_SHUTDOWN_SCR, IMG_GLOBAL_WARNING, NULL);
            if ((g_pwr_context.PowerOnMode == POWER_ON_USB) || 
                (g_pwr_context.PowerOnMode == POWER_ON_ALARM) ||
                (g_pwr_context.PowerOnMode == POWER_ON_CHARGER_IN))
            {
                UsbConfigMassStorage();
                SetUsbStatus(MMI_USBSTATUS_MS_PROC);
            }
            else
            {
                SendUsbConfigToHW(DEVUSB_CFG_ACTION_MASS_STORAGE);
                SetUsbStatus(MMI_USBSTATUS_MS_PROC);
            }
        }
    }
    else if (mode == DEVUSB_CFG_ACTION_CDC_ACM)
    {
    #if defined(__MMI_ENGINEER_MODE__) && defined(__DSPIRDBG__)
        S16 pError;
        U8 mode;
    #endif /* defined(__MMI_ENGINEER_MODE__) && defined(__DSPIRDBG__) */ 

        /* avoid entry UART setting screen */
    #ifdef __MMI_ENGINEER_MODE__
        DeleteScreenIfPresent(EM_DEV_INLINE_CONFIG_UART_MENU_SCR);
        DeleteScreenIfPresent(EM_DEV_SET_UART_MENU_SCR);
    #endif /* __MMI_ENGINEER_MODE__ */ 

        SetUsbStatus(MMI_USBSTATUS_CDCACM_PROC);
        ShowCategory64Screen(STR_USB_CDCACM_SETTING_SCR, IMG_GLOBAL_WARNING, NULL);

    #if defined(__MMI_ENGINEER_MODE__) && defined(__DSPIRDBG__)
        ReadValue(NVRAM_EM_SWDBG_MODE, &mode, DS_BYTE, &pError);
        if (mode == EM_SWDBG_MCU_DSP_IRDBG)
        {
            SendUsbConfigToHW(DEVUSB_CFG_ACTION_IRDBG);
        }
        else
    #endif /* defined(__MMI_ENGINEER_MODE__) && defined(__DSPIRDBG__) */ 
            SendUsbConfigToHW(DEVUSB_CFG_ACTION_CDC_ACM);

    }
#ifdef __MMI_PICT_BRIDGE_SUPPORT__
    else if (mode == DEVUSB_CFG_ACTION_PICTBRIGE)
    {
        SetUsbStatus(MMI_USBSTATUS_PICTBRIGE);
        ShowCategory64Screen(STR_USB_PICT_BRIGE_CONFIGING, IMG_GLOBAL_WARNING, NULL);
        SendUsbConfigToHW(DEVUSB_CFG_ACTION_PICTBRIGE);
    }
#endif /* __MMI_PICT_BRIDGE_SUPPORT__ */
    else
    {
        ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  UsbConfigRspHdlr
 * DESCRIPTION
 *  This is usb config response handler
 *  
 *  PARAMETERS: void
 *  info        [?]     
 *  RETURNS: void(?)
 *  GLOBALS AFFECTED: none(?)
 *****************************************************************************/
void UsbConfigRspHdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_eq_usbconfig_rsp_struct *p_usbcfg_struct = (mmi_eq_usbconfig_rsp_struct*) info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_USB_FUNC_CONF_RSP_HDLR);
#ifdef __USB_IN_NORMAL_MODE__
    if (p_usbcfg_struct->result != KAL_TRUE)
    {
    #ifdef __NVRAM_IN_USB_MS__
        if (p_usbcfg_struct->mode == DEVUSB_CFG_ACTION_STOP_MS) /* g_pwr_context.PowerOnMode == POWER_ON_USB */
        {
            ;   /* no matter success or not, must reboot. */
        }
        else
    #endif /* __NVRAM_IN_USB_MS__ */ 
        {
            /* Config error or USB device pluged out, drv will be reset so stop further processing */
            if (MMIUSB_GET_FLAG(MMIUSB_MASK_IS_CONNECT))
            {
                SetUsbStatus(MMI_USBSTATUS_PLUGIN);
                GoBackHistory();
                DisplayPopup(
                    (PU8) GetString(STR_GLOBAL_UNFINISHED),
                    IMG_GLOBAL_UNFINISHED,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    ERROR_TONE);
            }
            else
            {
                if (p_usbcfg_struct->mode == DEVUSB_CFG_ACTION_MASS_STORAGE)
                {
                    /* Tricky, should add a temp state, e.g. MMI_USBSTATUS_CFG_RSP */
                    SetUsbStatus(MMI_USBSTATUS_MS);
                    mmi_usb_send_removal_event_req();
                }
                else
                {
                    SetUsbStatus(MMI_USBSTATUS_PLUGOUT);
                    GoBackHistory();
                    DisplayPopup(
                        (PU8) GetString(STR_GLOBAL_UNFINISHED),
                        IMG_GLOBAL_UNFINISHED,
                        1,
                        UI_POPUP_NOTIFYDURATION_TIME,
                        ERROR_TONE);
                }
            }

            return;
        }
    }
#else /* __USB_IN_NORMAL_MODE__ */ 
    if (p_usbcfg_struct->result != KAL_TRUE || GetUsbStatus() == MMI_USBSTATUS_PLUGOUT)
    {

    #ifdef __NVRAM_IN_USB_MS__
        if (p_usbcfg_struct->mode == DEVUSB_CFG_ACTION_STOP_MS) /* g_pwr_context.PowerOnMode == POWER_ON_USB */
        {
            ;   /* no matter success or not, must reboot. */
        }
        else
    #endif /* __NVRAM_IN_USB_MS__ */ 
        {
            if (!MMIUSB_GET_FLAG(MMIUSB_MASK_IS_CONNECT))
            {
                SetUsbStatus(MMI_USBSTATUS_PLUGOUT);
            }

            /* Config error or USB device pluged out, drv will be reset so stop further processing */
            GoBackHistory();
            DisplayPopup(
                (PU8) GetString(STR_GLOBAL_UNFINISHED),
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                ERROR_TONE);
            return;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    switch (p_usbcfg_struct->mode)
    {
        case DEVUSB_CFG_ACTION_MASS_STORAGE /* USB_MASS_STORAGE */ :
    #ifdef __USB_IN_NORMAL_MODE__
            if (!mmi_usb_need_to_reboot())
            {
                SetUsbStatus(MMI_USBSTATUS_MS);

                if (!isInCall())
                {
                    DisplayIdleScreen();
                }
                else
                {
                    U16 marker_screen = 0, start_screen = 0, end_screen = 0;

                    marker_screen = GetCmMarkerScrnID();

                    GetPreviousScrnIdOf(marker_screen, &end_screen);
                    GetNextScrnIdOf(IDLE_SCREEN_ID, &start_screen);
                    DeleteBetweenScreen(start_screen, end_screen);

//                    DeleteBetweenScreen(CM_SCR_MARKER, IDLE_SCREEN_ID);
                    DeleteScreenIfPresent(SCR_ID_USB_PROGRESS);
                }
                if (mmi_usb_is_exported)
                {
                    DisplayPopup(
                        (PU8) GetString(STR_GLOBAL_DONE),
                        IMG_GLOBAL_ACTIVATED,
                        1,
                        UI_POPUP_NOTIFYDURATION_TIME,
                        SUCCESS_TONE);
                    DeleteScreenIfPresent(SCR_ID_USB_PROGRESS);
                }
                else
                {
                    DisplayPopup(
                        (PU8) GetString(STR_ID_USB_NO_MS_FOR_PC),
                        IMG_GLOBAL_WARNING,
                        1,
                        UI_POPUP_NOTIFYDURATION_TIME,
                        WARNING_TONE);
                }

            }
            else
    #endif /* __USB_IN_NORMAL_MODE__ */ 
            {
                UsbConfigMassStorage();
            }
            break;

        case DEVUSB_CFG_ACTION_CDC_ACM /* USB_CDC_ACM */ :
            UsbConfigCDCACM();
            break;

        case DEVUSB_CFG_ACTION_WEBCAM /* USB_WEBCAM */ :
            /* Do nothing */
            break;

        #if defined(__NVRAM_IN_USB_MS__)
        case DEVUSB_CFG_ACTION_STOP_MS /* USB_STOP_MS */ :
            /* g_pwr_context.PowerOnMode == POWER_ON_USB */
            mmi_usb_send_power_on_req();
            break;
        #endif /* defined(__NVRAM_IN_USB_MS__) */ 

        #ifdef __MMI_PICT_BRIDGE_SUPPORT__
        case DEVUSB_CFG_ACTION_PICTBRIGE: /* PictBrige */
            DisplayPopup((PU8) GetString(STR_GLOBAL_DONE),
                IMG_GLOBAL_ACTIVATED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                SUCCESS_TONE);
            DeleteScreenIfPresent(SCR_DEV_USBDETECT);
            break;
        #endif /* __MMI_PICT_BRIDGE_SUPPORT__ */
        
        default:
            GoBackHistory();
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  UsbCfgMSTimeoutHdlr
 * DESCRIPTION
 *  This fucntion is mass storage following action after usb conigure response comes,
 *  (MSG_ID_MMI_EQ_USBCONFIG_RSP) and the screen timer expire
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: void(?)
 *  GLOBALS AFFECTED: none(?)
 *****************************************************************************/
void UsbCfgMSTimeoutHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pwr_context.PowerOnMode != POWER_ON_KEYPAD && g_pwr_context.PowerOnMode != POWER_ON_EXCEPTION)
    {
        AlmDeInit();
        SetInterruptPopupDisplay(POPUP_ALL_OFF);
        UsbSendMsgToHW(PRT_POWER_OFF_REQ, NULL, NULL);
    }
    else
    {
        ShutdownSystemOperation();
    }
}


/*****************************************************************************
 * FUNCTION
 *  UsbConfigMassStorage
 * DESCRIPTION
 *  This fucntion is mass storage following action after usb conigure response comes,
 *  (MSG_ID_MMI_EQ_USBCONFIG_RSP)
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: void(?)
 *  GLOBALS AFFECTED: none(?)
 *****************************************************************************/
void UsbConfigMassStorage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_USB_FUNC_CONF_MS);

    StartTimer(USB_SHUTDOWN_SCR_TIMER, USB_SHUTDOWN_SCR_TIMER_DUR, UsbCfgMSTimeoutHdlr);
}


/*****************************************************************************
 * FUNCTION
 *  UsbConfigCDCACM
 * DESCRIPTION
 *  This fucntion is cdcacm following action after usb conigure response comes,
 *  (MSG_ID_MMI_EQ_USBCONFIG_RSP)
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: void(?)
 *  GLOBALS AFFECTED: none(?)
 *****************************************************************************/
void UsbConfigCDCACM(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   /*******************************/
   /** Interface change 040927   **/
   /** See the description above **/
   /*******************************/
    S16 pError;
    U8 app;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_USB_FUNC_CONF_CDCACM);
    /*   
     * SetProtocolEventHandler (UsbGetUartPortRspHdlr, MSG_ID_MMI_EQ_GET_UART_RSP);
     * SendUsbGetUartPortToHW();
     */

    ReadValue(NVRAM_DEFAULT_USB_APP, &app, DS_BYTE, &pError);

    if (pError != NVRAM_READ_SUCCESS)
    {
        app = USB_SWITCH_PORT_APP_DATA;
    }
    else if (app == 0xFF)
    {
        app = USB_SWITCH_PORT_APP_DATA;
        WriteValue(NVRAM_DEFAULT_USB_APP, &app, DS_BYTE, &pError);
    }

    ASSERT((app == USB_SWITCH_PORT_APP_DATA) || (app == USB_SWITCH_PORT_APP_DEBUG));

    SendUsbUartSwitchToHW(app, uart_port_usb);
}


/*****************************************************************************
 * FUNCTION
 *  UsbUartSwitchRspHdlr
 * DESCRIPTION
 *  This is uart switch port response handler
 *  
 *  PARAMETERS: void
 *  info        [?]     
 *  RETURNS: void(?)
 *  GLOBALS AFFECTED: none(?)
 *****************************************************************************/
void UsbUartSwitchRspHdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_usbuart_switch_port_rsp_struct *rsp_p = info;
    MMI_USB_STATUS usb_state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_USB_FUNC_UART_SWITCH_RSP_HDLE);

    usb_state = GetUsbStatus();

    /* if(  usb_state != MMI_USBSTATUS_PLUGOUT )
       GoBackHistory(); */

    if (!(rsp_p->result))
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_UNFINISHED),
            IMG_GLOBAL_UNFINISHED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
    }
    else
    {
        if (usb_state != MMI_USBSTATUS_PLUGOUT)
        {
            /* Finish CDCACM config and port switch, change state */
            SetUsbStatus(MMI_USBSTATUS_CDCACM);
        }
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_DONE),
            IMG_GLOBAL_ACTIVATED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            SUCCESS_TONE);
        DeleteScreenIfPresent(SCR_DEV_USBDETECT);

      /*******************************/
      /** Interface change 040927   **/
      /** See the description above **/
      /*******************************/
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
    #endif /* 0 */ 

    }
}


/*****************************************************************************
 * FUNCTION
 *  UsbGetUartPortRspHdlr
 * DESCRIPTION
 *  This is uart get port response handler
 *  
 *  PARAMETERS: void
 *  info        [?]     
 *  RETURNS: void(?)
 *  GLOBALS AFFECTED: none(?)
 *****************************************************************************/
void UsbGetUartPortRspHdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_get_uart_rsp_struct *rsp_p = info;
    S16 pError;
    U8 app;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_USB_FUNC_GET_UART_PORT_RSP_HDLE);

    /* Error case, stop subsequence action and return */
    if (GetUsbStatus() == MMI_USBSTATUS_PLUGOUT || rsp_p->result != MMI_TRUE)
    {
        GoBackHistory();
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_UNFINISHED),
            IMG_GLOBAL_UNFINISHED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
        return;
    }

    /* Get uart port successfully, store in context */
    MMI_USB_CTX(ps_port_prev) = rsp_p->ps_uart_port;
    MMI_USB_CTX(tst_port_prev) = rsp_p->tst_uart_port_ps;

    /* Get the target application to switch COM port */
    /* (set from engineer mode, ps(data) or tst(debug) ) */
    ReadValue(NVRAM_DEFAULT_USB_APP, &app, DS_BYTE, &pError);
    if (pError != NVRAM_READ_SUCCESS)
    {
        app = USB_SWITCH_PORT_APP_DATA;
    }
    else if (app == 0xFF)
    {
        app = USB_SWITCH_PORT_APP_DATA;
        WriteValue(NVRAM_DEFAULT_USB_APP, &app, DS_BYTE, &pError);
    }

    ASSERT((app == USB_SWITCH_PORT_APP_DATA) || (app == USB_SWITCH_PORT_APP_DEBUG));

    if (((app == USB_SWITCH_PORT_APP_DATA) && (MMI_USB_CTX(tst_port_prev) == uart_port_usb))
        || ((app == USB_SWITCH_PORT_APP_DEBUG) && (MMI_USB_CTX(ps_port_prev) == uart_port_usb)))
    {
        /* Port confict with other application, other application has already set usb as commulation port */
        GoBackHistory();
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_UNFINISHED),
            IMG_GLOBAL_UNFINISHED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
        return;
    }
    else
    {
        /* Switch the uart port of defined application to usb port */
        /* SetUsbStatus( MMI_USBSTATUS_CDCACM_SWCHPORT ); */
        MMIUSB_SET_FLAG(MMIUSB_MASK_PORT_SWITCHING);
        SendUsbUartSwitchToHW(app, uart_port_usb);
    }

}

/* ===========================================================================================  */
/* ===  Send Message to Protocol Stack  */
/* ===========================================================================================  */


/*****************************************************************************
 * FUNCTION
 *  SendUsbConfigToHW
 * DESCRIPTION
 *  This function is to send usb config request to PS
 *  
 *  PARAMETERS: mode, ms or cdcacm
 *  mode        [IN]        
 *  RETURNS: void(?)
 *  GLOBALS AFFECTED: none(?)
 *****************************************************************************/
void SendUsbConfigToHW(U8 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_eq_usbconfig_req_struct *p_param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_param = OslConstructDataPtr(sizeof(mmi_eq_usbconfig_req_struct));
    p_param->mode = mode;
    p_param->reserved = 0;

    SetProtocolEventHandler(UsbConfigRspHdlr, MSG_ID_MMI_EQ_USBCONFIG_RSP);
    UsbSendMsgToHW(MSG_ID_MMI_EQ_USBCONFIG_REQ, (void*)p_param, (void*)NULL);

}


/*****************************************************************************
 * FUNCTION
 *  SendUsbUartSwitchToHW
 * DESCRIPTION
 *  This function is to send switch port request to PS
 *  
 *  PARAMETERS:
 *  app             [IN]        data or tst
 *  new_port        [IN]        uart 1, uart 2, usb, ircomm...etc
 *  RETURNS: void(?)
 *  GLOBALS AFFECTED: none(?)
 *****************************************************************************/
void SendUsbUartSwitchToHW(U8 app, U8 new_port)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_eq_usbuart_switch_port_req_struct *p_param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_USB_G7_SEND_SWITCH_PORT, app, new_port);

    p_param = OslConstructDataPtr(sizeof(mmi_eq_usbuart_switch_port_req_struct));

   /*******************************/
   /** Interface change 040927   **/
   /** See the description above **/
   /*******************************/
    /* p_param->new_port = new_port; */
    p_param->app = app;

    SetProtocolEventHandler(UsbUartSwitchRspHdlr, PRT_EQ_USBUART_SWITCH_PORT_RSP);
#ifdef __MMI_DUAL_SIM_SINGLE_CALL__    
    mmi_frm_set_slave_protocol_event_handler(UsbUartSwitchRspHdlr, PRT_EQ_USBUART_SWITCH_PORT_RSP);
#endif
    UsbSendMsgToHW(PRT_EQ_USBUART_SWITCH_PORT_REQ, (void*)p_param, (void*)NULL);

}


/*****************************************************************************
 * FUNCTION
 *  SendUsbGetUartPortToHW
 * DESCRIPTION
 *  This function is to send usb get port request to PS
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: void(?)
 *  GLOBALS AFFECTED: none(?)
 *****************************************************************************/
void SendUsbGetUartPortToHW(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UsbSendMsgToHW(MSG_ID_MMI_EQ_GET_UART_REQ, (void*)NULL, (void*)NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_usb_send_detect_ack
 * DESCRIPTION
 *  This function is to send usb detect ack to PS
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: void(?)
 *  GLOBALS AFFECTED: none(?)
 *****************************************************************************/
static void mmi_usb_send_detect_ack(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_usbdetect_res_req_struct *param_ack;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    param_ack = OslConstructDataPtr(sizeof(mmi_eq_usbdetect_res_req_struct));

    if (MMIUSB_GET_FLAG(MMIUSB_MASK_IS_CONNECT))
    {
        param_ack->action = DEVUSB_DETECT_ACTION_PLUGIN;
    }
    else
    {
        param_ack->action = DEVUSB_DETECT_ACTION_PLUGOUT;
    }

    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[USB] Send Ack to PS: Action = %d", param_ack->action);

    UsbSendMsgToHW(MSG_ID_MMI_EQ_USBDETECT_RES_REQ, (void*)param_ack, (void*)NULL);
}


/*****************************************************************************
 * FUNCTION
 *  UsbSendMsgToHW
 * DESCRIPTION
 *  This function is to send message to PS
 *  
 *  PARAMETERS: void
 *  msg_id              [IN]        
 *  local_param_ptr     [?]         
 *  peer_buf_ptr        [?]         
 *  RETURNS: void(?)
 *  GLOBALS AFFECTED: none(?)
 *****************************************************************************/
void UsbSendMsgToHW(U16 msg_id, void *local_param_ptr, void *peer_buf_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    U16 source_id = MOD_L4C;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM_SINGLE_CALL__    
    if (msg_id == PRT_EQ_USBUART_SWITCH_PORT_REQ)
    {
        U8 buffer[NVRAM_EF_SYS_CACHE_OCTET_SIZE];
        S16 pError;
    
        ReadRecord(NVRAM_EF_SYS_CACHE_OCTET_LID,
                   NVRAM_SYS_FLIGHTMODE_STATE, 
                   (void*)buffer, 
                   NVRAM_EF_SYS_CACHE_OCTET_SIZE, &pError);
    
        if (buffer[L4C_SETTING_DUAL_SIM_UART] ==  L4C_UART_TO_SIM2)
        {
            source_id = MOD_L4C_2;
        }
    }
#endif /* #ifdef __MMI_DUAL_SIM_SINGLE_CALL__*/    
      
    Message.oslMsgId = msg_id;
    Message.oslDataPtr = (oslParaType*) local_param_ptr;
    Message.oslPeerBuffPtr = peer_buf_ptr;
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = source_id;
    OslMsgSendExtQueue(&Message);

}


/*****************************************************************************
 * FUNCTION
 *  UsbPwnOnThenPwnOn
 * DESCRIPTION
 *  This function is to send power on request to PS
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: void(?)
 *  GLOBALS AFFECTED: none(?)
 *****************************************************************************/
void UsbPwnOnThenPwnOn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, " USB POWERKEY_ON!!!!");

#if defined(__MMI_SUBLCD__)
    lcd_power_on(SUB_LCD, 0);
#endif 

    LCDBackLightOff();

#if defined(__NVRAM_IN_USB_MS__)
    if (GetUsbStatus() == MMI_USBSTATUS_MS)
    {
        SendUsbConfigToHW(DEVUSB_CFG_ACTION_STOP_MS);
    }
    else
#endif /* defined(__NVRAM_IN_USB_MS__) */ 
        mmi_usb_send_power_on_req();
}

/*****************************************************************************
*
*  USB-WebCam                                                 
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_usb_webcam_entry_app_scr
 * DESCRIPTION
 *  entry of webcam screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_WEBCAM__
void mmi_usb_webcam_entry_app_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 image_width;
    S32 image_height;
    U16 banding;
    MDI_RESULT ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("[WEBCAM APP] mmi_usb_webcam_entry_app_scr()");
    PRINT_INFORMATION("[WEBCAM APP] state: %d", mmi_usb_ptr->webcam_state);

    EntryNewScreen(SCR_ID_USB_WEBCAM, mmi_usb_webcam_exit_app_scr, mmi_usb_webcam_entry_app_scr, NULL);

    ClearInputEventHandler(MMI_DEVICE_KEY);

    /* eanble keypad tone, since this might enter from idle when key pad is locked */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);

    /* disable partial screen saver */
    mmi_phnset_disable_partial_ss();

#ifdef __MMI_SUBLCD__
    if (!mmi_usb_ptr->webcam_is_sub_display)
    {
        ForceSubLCDScreen(mmi_usb_webcam_entry_sublcd_scr);
    }
#endif /* __MMI_SUBLCD__ */ 

   /***************************************************************************** 
   * register interrupt event hdlr
   *****************************************************************************/
    mmi_frm_block_general_interrupt_event(MMI_FRM_INT_COMMON_INTERRUPT_EVENT);
    /* hook del screen callback */
    SetDelScrnIDCallbackHandler(SCR_ID_USB_WEBCAM, mmi_usb_webcam_del_screen_id_hdlr);

#if defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__)
    /* register event hdlr */
    mmi_frm_block_interrupt_event_handler(
        MMI_FRM_INT_GPIO, 
        mmi_usb_webcam_gpio_event_hdlr, 
        mmi_usb_webcam_gpio_post_event_hdlr);
#endif /* defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__) */ 

    /* avoid status bar */
    entry_full_screen();

    /* stop bg music */
    mdi_audio_suspend_background_play();

    /* stop LED patten */
    StopLEDPatternBackGround();

#ifdef HORIZONTAL_CAMERA
    gdi_lcd_set_rotate(GDI_LAYER_ROTATE_270);
    gdi_layer_resize(UI_device_height, UI_device_width);

    /* draw bg */
    gdi_layer_clear(GDI_COLOR_WHITE);
    gdi_image_get_dimension_id(IMG_ID_WEBCAM_BG, &image_width, &image_height);

    gdi_image_draw_animation_id(
        (UI_device_height - image_width) >> 1,
        (UI_device_width - image_height) >> 1,
        IMG_ID_WEBCAM_BG,
        NULL);

    gdi_layer_blt_previous(0, 0, UI_device_height - 1, UI_device_width - 1);
#else /* HORIZONTAL_CAMERA */ 
    /* draw bg */
    gdi_layer_clear(GDI_COLOR_WHITE);
    gdi_image_get_dimension_id(IMG_ID_WEBCAM_BG, &image_width, &image_height);

    gdi_image_draw_animation_id(
        (UI_device_width - image_width) >> 1,
        (UI_device_height - image_height) >> 1,
        IMG_ID_WEBCAM_BG,
        NULL);

    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
#endif /* HORIZONTAL_CAMERA */ 

    SetKeyHandler(mmi_usb_webcam_rsk_release, KEY_RSK, KEY_EVENT_UP);
    SetKeyHandler(mmi_usb_webcam_capture_key_press, KEY_CAMERA, KEY_EVENT_DOWN);

    if (mmi_usb_ptr->webcam_state == MMI_USB_WEBCAM_CONNECTED)
    {
        /* set mmi usb state and notify driver to set state */
        SetUsbStatus(MMI_USBSTATUS_WEBCAM);
        SendUsbConfigToHW(DEVUSB_CFG_ACTION_WEBCAM);

        banding = mmi_camera_get_camera_banding();
        
        /* start webcam */
        if (IsClamClose())
        {
            ret = mdi_webcam_start(WEBCAM_CLAM_CLOSE_ROTATE, banding, mmi_usb_webcam_event_hdlr);
        }
        else
        {
            ret = mdi_webcam_start(WEBCAM_CLAM_OPEN_ROTATE, banding, mmi_usb_webcam_event_hdlr);
        }

        if (ret == MDI_RES_WEBCAM_ERR_FAILED)
        {
            /* USB is connected, but camera part cant start correctly */
            mdi_webcam_stop();
            mmi_usb_ptr->webcam_state = MMI_USB_WEBCAM_CONNECTED;

            DisplayPopup(
                (PU8) GetString(STR_ID_USB_NOTIFY_WEBCAM_ERROR),
                IMG_GLOBAL_INFO,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                WARNING_TONE);

            DeleteNHistory(1);
        }
        else
        {
            mmi_usb_ptr->webcam_state = MMI_USB_WEBCAM_LISTENING;
        }

    }
    else if (mmi_usb_ptr->webcam_state == MMI_USB_WEBCAM_PAUSE)
    {
        /* resume webcam */
        if (IsClamClose())
        {
            ret = mdi_webcam_resume(WEBCAM_CLAM_CLOSE_ROTATE);
        }
        else
        {
            ret = mdi_webcam_resume(WEBCAM_CLAM_OPEN_ROTATE);
        }
        if (ret == MDI_RES_WEBCAM_ERR_FAILED)
        {
            mdi_webcam_stop();
            mmi_usb_ptr->webcam_state = MMI_USB_WEBCAM_CONNECTED;

            DisplayPopup(
                (PU8) GetString(STR_ID_USB_NOTIFY_WEBCAM_ERROR),
                IMG_GLOBAL_INFO,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                WARNING_TONE);

            DeleteScreenIfPresent(SCR_ID_USB_WEBCAM);
        }
        else
        {
            mmi_usb_ptr->webcam_state = MMI_USB_WEBCAM_RUNNING;
        }
    }
    else
    {
        MMI_ASSERT(0);  /* shall not enter here */
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_usb_webcam_exit_app_scr
 * DESCRIPTION
 *  exit of webcam screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_usb_webcam_exit_app_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 screen_id;
    MDI_RESULT ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("[WEBCAM APP] mmi_usb_webcam_exit_app_scr()");
    PRINT_INFORMATION("[WEBCAM APP] state: %d", mmi_usb_ptr->webcam_state);

#ifdef HORIZONTAL_CAMERA
    gdi_lcd_set_rotate(GDI_LAYER_ROTATE_0);
    gdi_layer_resize(UI_device_width, UI_device_height);
    gdi_layer_clear(GDI_COLOR_WHITE);
#endif /* HORIZONTAL_CAMERA */ 

    /* restore partial screen saver */
    mmi_phnset_enable_partial_ss();

    /* stop bg drawing */
    gdi_image_stop_animation_all();

    /* resume background audio */
    mdi_audio_resume_background_play();

    /* resume LCD patten */
    StopLEDPatternPowerOn();

    /* check who exit webcam screen */
    screen_id = GetActiveScreenId();

    if (mmi_usb_ptr->webcam_state == MMI_USB_WEBCAM_RUNNING)
    {
        /* pause webcam */
        ret = mdi_webcam_pause();
        if (ret == MDI_RES_WEBCAM_ERR_FAILED)
        {
            /* USB is connected, but camera part cannot start correctly */
            mdi_webcam_stop(); 
            mmi_usb_ptr->webcam_state = MMI_USB_WEBCAM_CONNECTED;
        }
        else
        {
            mmi_usb_ptr->webcam_state = MMI_USB_WEBCAM_PAUSE;
        }
    }
    else if (mmi_usb_ptr->webcam_state == MMI_USB_WEBCAM_LISTENING)
    {
        mdi_webcam_stop();
        mmi_usb_ptr->webcam_state = MMI_USB_WEBCAM_CONNECTED;
    }

#ifdef __MMI_SUBLCD__
    /* exit sublcd */
    if (mmi_usb_ptr->webcam_is_sub_display)
    {
        GoBackSubLCDHistory();
        mmi_usb_ptr->webcam_is_sub_display = FALSE;
    }
#endif /* __MMI_SUBLCD__ */ 

#if defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__)
    /* unhook clam close handler */
    mmi_frm_clear_interrupt_event_handler(MMI_FRM_INT_CLAM_CLOSE);
#endif /* defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__)*/ 

    /* clear all key handler - restore to default key handling for end key */
    ClearInputEventHandler(MMI_DEVICE_KEY);
	mmi_frm_clear_interrupt_event_handler(MMI_FRM_INT_WAP_MMS | MMI_FRM_INT_BT_TASK);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_usb_webcam_is_active
 * DESCRIPTION
 *  is webcam active or not
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_usb_webcam_is_active(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_usb_ptr->webcam_state == MMI_USB_WEBCAM_DISCONNECT)
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_usb_webcam_event_hdlr
 * DESCRIPTION
 *  callback function when webcam screen start has some problem
 * PARAMETERS
 *  ret     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_usb_webcam_event_hdlr(MDI_RESULT ret, BOOL camera_workable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("[WEBCAM APP] mmi_usb_webcam_event_hdlr()");
    PRINT_INFORMATION("[WEBCAM APP] mdi_webcam ret: %d", ret);
    PRINT_INFORMATION("[WEBCAM APP] state: %d", mmi_usb_ptr->webcam_state);

    switch (ret)
    {
        case MDI_RES_WEBCAM_SUCCEED:
            /* start successful */
            if(mmi_usb_ptr->webcam_state == MMI_USB_WEBCAM_LISTENING)
            {
                mmi_usb_ptr->webcam_state = MMI_USB_WEBCAM_RUNNING;
            }
            break;

        case MDI_RES_WEBCAM_ERR_FAILED:
            if(mmi_usb_ptr->webcam_state == MMI_USB_WEBCAM_LISTENING)
            {
                mdi_webcam_stop();
                mmi_usb_ptr->webcam_state = MMI_USB_WEBCAM_DISCONNECT;

                if(!camera_workable)
                {
                    DisplayPopup(
                        (PU8) GetString(STR_ID_USB_NOTIFY_WEBCAM_CAM_ERROR),
                        IMG_GLOBAL_INFO,
                        1,
                        UI_POPUP_NOTIFYDURATION_TIME,
                        WARNING_TONE); 
                    
                    DeleteScreenIfPresent(SCR_ID_USB_WEBCAM);
                }
                /* If camera is workable, the fail is due to cable plug out.                     */ 
                /* So, don't display pop up or it will have a conflict with "USB plug out popup" */				                
            }
            break;

        case MDI_RES_WEBCAM_DRV_ABORT:
            if (mmi_usb_ptr->webcam_state != MMI_USB_WEBCAM_DISCONNECT)
            {
                mdi_webcam_stop();
                mmi_usb_ptr->webcam_state = MMI_USB_WEBCAM_DISCONNECT;

                DisplayPopup(
                    (PU8) GetString(STR_ID_USB_WEBCAM_STOPPED),
                    IMG_GLOBAL_INFO,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    WARNING_TONE);

                DeleteScreenIfPresent(SCR_ID_USB_WEBCAM);
            }
            break;

        default:
            /* shall not enter here */
            MMI_ASSERT(0);
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_usb_webcam_del_screen_id_hdlr
 * DESCRIPTION
 *  callback function when webcam screen removed from history webcam screen
 * PARAMETERS
 *  ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_usb_webcam_del_screen_id_hdlr(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* exit by other screens */
    if ((mmi_usb_ptr->webcam_state == MMI_USB_WEBCAM_RUNNING) ||
        (mmi_usb_ptr->webcam_state == MMI_USB_WEBCAM_LISTENING))
    {
        /* close webcam */
        mdi_webcam_stop();
        mmi_usb_ptr->webcam_state = MMI_USB_WEBCAM_DISCONNECT;
    }
    else if (mmi_usb_ptr->webcam_state == MMI_USB_WEBCAM_CONNECTED)
    {
        mmi_usb_ptr->webcam_state = MMI_USB_WEBCAM_DISCONNECT;
    }

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_usb_webcam_gpio_event_hdlr
 * DESCRIPTION
 *  clam handler
 * PARAMETERS
 *  ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
 #if defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__)
static U8 mmi_usb_webcam_gpio_event_hdlr(mmi_frm_int_event_type interrupt_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (interrupt_event == MMI_FRM_INT_CLAM_CLOSE)
    {
        mmi_usb_ptr->webcam_is_clam_close = TRUE;
        ret = mdi_webcam_rotate(WEBCAM_CLAM_CLOSE_ROTATE);        
        if (ret == MDI_RES_WEBCAM_ERR_FAILED)
        {
            mdi_webcam_stop();
            /* USB is connected, but camera part cant start correctly */
            mmi_usb_ptr->webcam_state = MMI_USB_WEBCAM_CONNECTED;

            DisplayPopup(
                (PU8) GetString(STR_ID_USB_NOTIFY_WEBCAM_ERROR),
                IMG_GLOBAL_INFO,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                WARNING_TONE);

            DeleteScreenIfPresent(SCR_ID_USB_WEBCAM);
            return FALSE;
        }
        SetClamState(EXT_DEV_CLAM_CLOSE);

        /* return TRUE means will block this interrut from passing default handler */
        return TRUE;
    }
    else if (interrupt_event == MMI_FRM_INT_CLAM_OPEN)
    {
        mmi_usb_ptr->webcam_is_clam_close = FALSE;
        ret = mdi_webcam_rotate(WEBCAM_CLAM_OPEN_ROTATE);
        if (ret == MDI_RES_WEBCAM_ERR_FAILED)
        {
            mdi_webcam_stop();
            /* USB is connected, but camera part cant start correctly */
            mmi_usb_ptr->webcam_state = MMI_USB_WEBCAM_CONNECTED;

            DisplayPopup(
                (PU8) GetString(STR_ID_USB_NOTIFY_WEBCAM_ERROR),
                IMG_GLOBAL_INFO,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                WARNING_TONE);

            DeleteScreenIfPresent(SCR_ID_USB_WEBCAM);
            return FALSE;
        }
        SetClamState(EXT_DEV_CLAM_OPEN);

        /* return TRUE means will block this interrut from passing default handler */
        return TRUE;
    }
    else if (interrupt_event & MMI_FRM_INT_EARPHONE)
    {
        SetInterruptPopupDisplay(POPUP_ALL_OFF);
    }

    return FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_usb_webcam_gpio_post_event_hdlr
 * DESCRIPTION
 *  clam handler
 * PARAMETERS
 *  ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_usb_webcam_gpio_post_event_hdlr(mmi_frm_int_event_type interrupt_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (interrupt_event & MMI_FRM_INT_EARPHONE)
    {
        SetInterruptPopupDisplay(POPUP_ALL_ON);
    }

    return FALSE;

}
#endif /* defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__) */
 

/*****************************************************************************
 * FUNCTION
 *  mmi_usb_webcam_rsk_release
 * DESCRIPTION
 *  rsk release handler, will stop webcam
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_usb_webcam_rsk_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((mmi_usb_ptr->webcam_state == MMI_USB_WEBCAM_LISTENING) ||
        (mmi_usb_ptr->webcam_state == MMI_USB_WEBCAM_RUNNING))
    {
        /* close webcam */
        mdi_webcam_stop();
        mmi_usb_ptr->webcam_state = MMI_USB_WEBCAM_DISCONNECT;
    }
    else
    {
        MMI_ASSERT(0);
    }

    GoBackHistory();
}



/*****************************************************************************
 * FUNCTION
 *  mmi_usb_webcam_capture_key_press
 * DESCRIPTION
 *  capture key is pressed, will capture an image to PC side
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_usb_webcam_capture_key_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_usb_ptr->webcam_state == MMI_USB_WEBCAM_RUNNING)
    {
        mdi_webcam_capture();

        /* flush all key event */
        ClearKeyEvents();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_usb_webcam_plug_out
 * DESCRIPTION
 *  webcam calbe plug out
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_usb_webcam_plug_out(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 screen_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* stop webcam if it is running */
    if ((mmi_usb_ptr->webcam_state == MMI_USB_WEBCAM_RUNNING) ||
        (mmi_usb_ptr->webcam_state == MMI_USB_WEBCAM_LISTENING) ||
        (mmi_usb_ptr->webcam_state == MMI_USB_WEBCAM_CONNECTED) || 
        (mmi_usb_ptr->webcam_state == MMI_USB_WEBCAM_PAUSE))
    {
        /* stop webcam */
        mdi_webcam_stop();
        mmi_usb_ptr->webcam_state = MMI_USB_WEBCAM_DISCONNECT;
    }

    screen_id = GetActiveScreenId();

    DeleteScreenIfPresent(SCR_ID_USB_WEBCAM);

    /* if is in webcam screen, leave it */
    if (screen_id == SCR_ID_USB_WEBCAM)
    {
        GoBackHistory();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_usb_webcam_entry_sublcd_scr
 * DESCRIPTION
 *  entry sublcd screen, if still remain on standard MMI sublcd screen, time update will
 *  redraw sublcd while mainlcd is previewing, will cause driver assert.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_SUBLCD__)
static void mmi_usb_webcam_entry_sublcd_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 lcd_width;
    S32 lcd_height;
    S32 image_width;
    S32 image_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecSubLCDCurrExitHandler();
    ShowCategory331Screen();
    SetSubLCDExitHandler(mmi_usb_webcam_exit_sublcd_scr);

    gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
    gdi_lcd_get_dimension(&lcd_width, &lcd_height);

    gdi_layer_reset_clip();

    gdi_layer_clear_background(GDI_COLOR_BLACK);

    gdi_image_get_dimension_id(IMG_ID_WEBCAM_SUB_BG, &image_width, &image_height);
    gdi_image_draw_id((lcd_width - image_width) >> 1, (lcd_height - image_height) >> 1, IMG_ID_WEBCAM_SUB_BG);
    gdi_layer_blt_base_layer(0, 0, lcd_width - 1, lcd_height - 1);

    gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);

    mmi_usb_ptr->webcam_is_sub_display = TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_usb_webcam_exit_sublcd_scr
 * DESCRIPTION
 *  exit sublcd screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_usb_webcam_exit_sublcd_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SubLCDHistoryNode SubLCDHistory;

    SubLCDHistory.entryFuncPtr = mmi_usb_webcam_entry_sublcd_scr;
    AddSubLCDHistory(&SubLCDHistory);

    mmi_usb_ptr->webcam_is_sub_display = FALSE;
}
#endif /* defined(__MMI_SUBLCD__) */ 
#endif /* __MMI_WEBCAM__ */ 

#ifdef __USB_IN_NORMAL_MODE__


/*****************************************************************************
 * FUNCTION
 *  mmi_usb_hide_file_related_menus
 * DESCRIPTION
 *  Hide file related menus before enter USB mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_usb_hide_file_related_menus(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* HideStatusIcon(STATUS_ICON_USB); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_usb_restore_file_related_menus
 * DESCRIPTION
 *  Restore file related menus before leave USB mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_usb_restore_file_related_menus(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ShowStatusIcon(STATUS_ICON_USB); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_usb_need_to_reboot
 * DESCRIPTION
 *  Check if it it necessary to reboot for USB mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_usb_need_to_reboot(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __USB_IN_NORMAL_MODE_IMPROVE__
    if (AlmIsRTCPwron())
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }    
#elif !defined(__FS_CARD_SUPPORT__) && !defined(NAND_SUPPORT)
    return MMI_TRUE;
#elif !defined(__FS_CARD_SUPPORT__) && defined(__NOR_NOT_PRESENT__)
    return MMI_TRUE;
#else 
    if (AlmIsRTCPwron())
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_usb_progress_del_callback
 * DESCRIPTION
 *  Callback function of delete bmi screen
 * PARAMETERS
 *  p       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_usb_progress_del_callback(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_USB_STATUS usb_state = GetUsbStatus();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (usb_state == MMI_USBSTATUS_MS_PROC)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_usb_entry_progress_screen
 * DESCRIPTION
 *  USB progress screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_usb_entry_progress_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_USB_PROGRESS, NULL, mmi_usb_entry_progress_screen, NULL);
    ShowCategory66Screen(
        STR_USB_CONFIG_TITLE,
        0,
        0,
        0,
        0,
        0,
        (PU8) GetString(STR_ID_USB_MODE_PROGRESS),
        IMG_GLOBAL_PROGRESS,
        NULL);
    DeleteScreenIfPresent(SCR_ID_USB_PROGRESS);

    SetDelScrnIDCallbackHandler(SCR_ID_USB_PROGRESS, (HistoryDelCBPtr) mmi_usb_progress_del_callback);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_usb_is_in_mass_storage_mode
 * DESCRIPTION
 *  Get current USB mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_usb_is_in_mass_storage_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_USB_STATUS usb_state = GetUsbStatus();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (usb_state == MMI_USBSTATUS_MS || usb_state == MMI_USBSTATUS_MS_PROC)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_usb_is_leaving_ms_mode
 * DESCRIPTION
 *  Get the USB status
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_usb_is_leaving_ms_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((MMI_USB_CTX(usb_status_prev) == MMI_USBSTATUS_MS && MMI_USB_CTX(usb_status) == MMI_USBSTATUS_MS_PROC) ||
        (!MMIUSB_GET_FLAG(MMIUSB_MASK_IS_CONNECT) && MMI_USB_CTX(usb_status) == MMI_USBSTATUS_MS_PROC))
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_usb_app_deinit
 * DESCRIPTION
 *  App de-init for entering USB mode, ex: close file handler in use
 * PARAMETERS
 *  p       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_usb_app_deinit(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[USB] mmi_usb_app_deinit");
    
    for (; counter_of_deinit < MAX_DEINIT_CALLBACK + 1; counter_of_deinit++)
    {
        U8 to_perform = TRUE;

        PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[USB] mmi_usb_app_deinit-- counter_of_deinit:%d", counter_of_deinit);
        
        if (counter_of_deinit &&
            mmi_usb_deinit_callback[counter_of_deinit - 1].RspHdlr &&
            mmi_usb_deinit_callback[counter_of_deinit - 1].checkfunc &&
            mmi_usb_deinit_callback[counter_of_deinit - 1].checkfunc())
        {
            PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[USB] mmi_usb_app_deinit: count-1 procedure");
            mmi_usb_deinit_callback[counter_of_deinit - 1].RspHdlr(p);
            SetProtocolEventHandler(
                mmi_usb_deinit_callback[counter_of_deinit - 1].RspHdlr,
                mmi_usb_deinit_callback[counter_of_deinit - 1].eventID);
        }

        if (mmi_usb_deinit_callback[counter_of_deinit].checkfunc)
        {
            to_perform = mmi_usb_deinit_callback[counter_of_deinit].checkfunc();
        }

        PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[USB] mmi_usb_app_deinit: to_perform:%d", to_perform);
        
        if (to_perform)
        {
            if (mmi_usb_deinit_callback[counter_of_deinit].callback)
            {
                mmi_usb_deinit_callback[counter_of_deinit].callback();
            }
            else
            {
                MMI_ASSERT(counter_of_deinit == MAX_DEINIT_CALLBACK);
            }

            if (mmi_usb_deinit_callback[counter_of_deinit].eventID != 0)
            {
                PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[USB] mmi_usb_app_deinit: eventID return");

                SetProtocolEventHandler(mmi_usb_app_deinit, mmi_usb_deinit_callback[counter_of_deinit].eventID);
                counter_of_deinit++;
                return;
            }
        }
    }

    /* reach here only when all callback are done */
    if (mmi_usb_deinit_callback[MAX_DEINIT_CALLBACK].callback == NULL)
    {
        SendUsbConfigToHW(DEVUSB_CFG_ACTION_MASS_STORAGE);
    }

    counter_of_deinit = 0;
    mmi_usb_deinit_callback[MAX_DEINIT_CALLBACK].callback = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_usb_app_reinit
 * DESCRIPTION
 *  App store for exiting from USB mode, ex: restore file handler in use
 * PARAMETERS
 *  p       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_usb_app_reinit(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (; counter_of_reinit < MAX_REINIT_CALLBACK; counter_of_reinit++)
    {
        U8 to_perform = TRUE;

        if (counter_of_reinit &&
            mmi_usb_reinit_callback[counter_of_reinit - 1].RspHdlr &&
            mmi_usb_reinit_callback[counter_of_reinit - 1].checkfunc &&
            mmi_usb_reinit_callback[counter_of_reinit - 1].checkfunc())
        {
            mmi_usb_reinit_callback[counter_of_reinit - 1].RspHdlr(p);
            SetProtocolEventHandler(
                mmi_usb_reinit_callback[counter_of_reinit - 1].RspHdlr,
                mmi_usb_reinit_callback[counter_of_reinit - 1].eventID);
        }

        if (mmi_usb_reinit_callback[counter_of_reinit].checkfunc)
        {
            to_perform = mmi_usb_reinit_callback[counter_of_reinit].checkfunc();
        }

        if (to_perform)
        {
            if (mmi_usb_reinit_callback[counter_of_reinit].callback)
            {
                mmi_usb_reinit_callback[counter_of_reinit].callback();
            }
            else
            {
                MMI_ASSERT(0);  /* break; */
            }

            if (mmi_usb_reinit_callback[counter_of_reinit].eventID != 0)
            {
                SetProtocolEventHandler(mmi_usb_app_reinit, mmi_usb_reinit_callback[counter_of_reinit].eventID);
                counter_of_reinit++;
                return;
            }
        }
    }

    /* reach here only when all callback are done */
    counter_of_reinit = 0;
    mmi_usb_send_removal_event_rsp(NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_usb_check_path_exported
 * DESCRIPTION
 *  To check if the path is exported to PC
 * PARAMETERS
 *  path        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_usb_check_path_exported(S8 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __USB_IN_NORMAL_MODE_IMPROVE__	    
    U16 unicode_buf[10] = {0};
#endif    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __USB_IN_NORMAL_MODE_IMPROVE__	

    if (mmi_ucs2ncmp(path, "Z:\\", 3)==0)
    {
    	return MMI_FALSE;
    }
    else
    {
    	return MMI_TRUE;
    }
    
#else    

    mmi_asc_n_to_ucs2((S8*) unicode_buf, path, 3);

    if (FS_GetDevType((PU16) unicode_buf) != FS_GetDevType(L"Z:\\"))
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
#endif /* __USB_IN_NORMAL_MODE_IMPROVE__	 */    

}


/*****************************************************************************
 * FUNCTION
 *  mmi_usb_app_unavailable_popup
 * DESCRIPTION
 *  To make a warning if the app. is disable in MS mode
 * PARAMETERS
 *  stringId        [IN]        0 will popup "USB: Can't access the storage now"; app specific string otherwise
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_usb_app_unavailable_popup(U16 stringId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (stringId == 0)
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_USB_MODE_EXPORTED_WARNING),
            IMG_GLOBAL_WARNING,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            WARNING_TONE);
    }
    else
    {
        DisplayPopup((U8*) GetString(stringId), IMG_GLOBAL_WARNING, 0, UI_POPUP_NOTIFYDURATION_TIME, WARNING_TONE);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_usb_send_removal_event_rsp
 * DESCRIPTION
 *  removal response handler
 * PARAMETERS
 *  info        [?]     response message
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_usb_send_removal_event_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //if (PermitUsbCfgScreenDisplay() == MMI_TRUE)
    {
        if (GetActiveScreenId() != POPUP_SCREENID)
        {
            BatteryIndicationPopup(STR_USB_CHARGER_REMOVED);
        }
    }

    SetUsbStatus(MMI_USBSTATUS_PLUGOUT);
    DeleteScreenIfPresent(SCR_ID_USB_PROGRESS);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_usb_mms_check_to_deinit
 * DESCRIPTION
 *  decide to perform callback or not
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_usb_mms_check_to_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wap_is_ready())
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_usb_mms_check_to_reinit
 * DESCRIPTION
 *  removal response handler
 * PARAMETERS
 *  void
 *  info: response message(?)
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_usb_mms_check_to_reinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wap_is_ready())
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_usb_is_any_exported_drive
 * DESCRIPTION
 *  is any exported drive
 * PARAMETERS
 *  void
 * RETURNS
 *  True or False
 *****************************************************************************/
MMI_BOOL mmi_usb_is_any_exported_drive(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __USB_IN_NORMAL_MODE_IMPROVE__	

    return MMI_TRUE;
    
#elif (defined(__FS_CARD_SUPPORT__) && !defined(NAND_SUPPORT)) || (defined(__FS_CARD_SUPPORT__) && defined(_NAND_FLASH_BOOTING_))
    if (!fmgr_is_msdc_present())
    {
        return MMI_FALSE;
    }
    else
#endif /* #ifdef __USB_IN_NORMAL_MODE_IMPROVE__ */
    {
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_usb_shutdown_handler
 * DESCRIPTION
 *  Hide file related menus before enter USB mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_usb_shutdown_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetUsbStatus() == MMI_USBSTATUS_MS)
    {
        SendUsbConfigToHW(DEVUSB_CFG_ACTION_STOP_MS);
    }
}

#endif /* __USB_IN_NORMAL_MODE__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_usb_send_removal_event_req
 * DESCRIPTION
 *  removal request handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_usb_send_removal_event_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[USB] mmi_usb_send_removal_event_req");

    if (g_pwr_context.PowerOnMode == POWER_ON_USB)
    {
        if (!mmi_alm_is_in_alarm())
        {
            SetInterruptPopupDisplay(POPUP_ALL_OFF);
            UsbSendMsgToHW(PRT_POWER_OFF_REQ, (void*)NULL, (void*)NULL);
        }
        else
        {
            SetUsbStatus(MMI_USBSTATUS_PLUGOUT);
            BatteryIndicationPopup(STR_USB_CHARGER_REMOVED);
            DeleteScreenIfPresent(SCR_USB_POWER_ON);
            mmi_alm_enable_pwroff();
        }
    }
    else
    {
    #ifdef __USB_IN_NORMAL_MODE__
        MMI_USB_STATUS usb_state = GetUsbStatus();

        if ((usb_state == MMI_USBSTATUS_MS) || (usb_state == MMI_USBSTATUS_IGNORED))
        {
            if (PermitUsbCfgScreenDisplay() == MMI_FALSE)
            {
        //        BatteryIndicationPopup(STR_USB_CHARGER_REMOVED);
            }
            else
            {
                mmi_usb_entry_progress_screen();
            }

            SetUsbStatus(MMI_USBSTATUS_MS_PROC);
        }
        else if (usb_state == MMI_USBSTATUS_MS_PROC)
        {
            if (!PermitUsbCfgScreenDisplay() == MMI_TRUE)
            {
                //BatteryIndicationPopup(STR_USB_CHARGER_REMOVED);
            }

            if (counter_of_reinit)
            {
                return; /* reinit already proceeding */
            }
            else if (!mmi_usb_deinit_callback[MAX_DEINIT_CALLBACK].callback)
            {
                /* '==' means come twice */
                mmi_usb_deinit_callback[MAX_DEINIT_CALLBACK].callback = mmi_usb_send_removal_event_req;
                return;
            }
            else if (counter_of_deinit < MAX_DEINIT_CALLBACK-1)
            {
            	return;
            }
        }

        DeleteScreenIfPresent(SCR_DEV_USBDETECT);

        mmi_usb_restore_file_related_menus();
        mmi_usb_app_reinit(NULL);
    #else

        if (mmi_bootup_is_in_power_on_period() == MMI_FALSE)
        {
            BatteryIndicationPopup(STR_USB_CHARGER_REMOVED);
        }
        SetUsbStatus(MMI_USBSTATUS_PLUGOUT);
    #endif /* __USB_IN_NORMAL_MODE__ */ 
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_usb_send_power_on_req
 * DESCRIPTION
 *  Send power on request (END key is long pressed) to L4C in USB power on mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_usb_send_power_on_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_eq_power_on_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (mmi_eq_power_on_req_struct*) OslConstructDataPtr(sizeof(mmi_eq_power_on_req_struct));
    myMsgPtr->fun = mmi_usb_ptr->reset_type;
    myMsgPtr->rst = 0;
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = MSG_ID_MMI_EQ_POWER_ON_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_usb_set_reset_type
 * DESCRIPTION
 *  Set reset type
 * PARAMETERS
 *  reset_type      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_usb_set_reset_type(U8 reset_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_usb_ptr->reset_type = reset_type;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_usb_set_background_still
 * DESCRIPTION
 *  Set background image
 * PARAMETERS
 *  isStill     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_usb_set_background_still(MMI_BOOL isStill)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (isStill)
    {
        mmi_usb_ptr->current_img = IMG_USB_POWER_ON;
    }
    else
    {
        mmi_usb_ptr->current_img = IMG_ID_USB_CHARGING;
    }

    if (GetActiveScreenId() == SCR_USB_POWER_ON)
    {
        ShowUsbScr();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_usb_set_background_still
 * DESCRIPTION
 *  Set background image
 * PARAMETERS
 *  isStill     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_usb_is_network_services_available(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
    E_MTPNP_AD_SIMCARD_USABLE_SIDE state;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
    state = MTPNP_AD_Get_UsableSide();
    if(state == MTPNP_AD_SIMCARD1_USABLE ||
        state == MTPNP_AD_SIMCARD2_USABLE ||
        state == MTPNP_AD_DUALSIM_USABLE)
    {
        return TRUE;
    }
#ifdef __MMI_WLAN_FEATURES__
    if (mmi_netset_get_active_preferred_mode() > 0)
    {
        return TRUE;
    }
#endif 
    return FALSE;

#else /* __MMI_DUAL_SIM_SINGLE_CALL__ */

    return mmi_bootup_is_sim_valid();

#endif /* __MMI_DUAL_SIM_SINGLE_CALL__ */
}

#endif /* __MMI_USB_SUPPORT__ */ 

