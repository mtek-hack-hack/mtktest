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
 * MMITask.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Protocol task functionality.
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
 *
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

/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**************************************************************

   FILENAME : MMItask.c

   PURPOSE     : Protocol task functionality 

   REMARKS     : nil

   AUTHOR      : Neeraj Sharma

   DATE     : Dec' 28, 2002

**************************************************************/

/*****************************************************************************
* Include                                                                     
*****************************************************************************/

#if !defined(__MTK_TARGET__)
#include <windows.h>
#endif 

#include "MMI_features.h"
#include "stdC.h"
#include "L4Dr.h"
#include "MMIDataType.h"
#include "GlobalStruct.h"
#include "GlobalConstants.h"
#include "FrameworkGprot.h"         
#include "FrameworkProt.h"   
/* __CUSTPACK_MULTIBIN     Terry   BEGIN */
#include "wgui_categories_inputs.h"
#include "IMERes.h"
/* __CUSTPACK_MULTIBIN     Terry   END */
#if defined(__MMI_RESOURCE_ENFB_SUPPORT__)
    #include "ResMemMgrGprot.h"
#endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */
#include "ThrdOsInterface.h"
#include "DebugInitDef.h"
#include "MMI_trc.h"
#include "ProtocolEvents.h"
#include "AsyncEventsGprot.h"
#include "ATHandlerProt.h"
#include "AlarmFrameWorkProt.h"
#include "CallManagementGprot.h"
#include "CallManagementStruct.h"
#include "SettingProfile.h"
#include "ProfileGprots.h"
#include "Service.h"
#include "SATGProts.h"
#include "CPHSProtocolHandlers.h"
#include "EngineerModeProt.h"
#include "FactoryModeProt.h"
#include "gpioInc.h"
#include "PhoneBookGProt.h"
#include "CallHistoryMain.h"
#include "FunAndGamesProts.h"
#include "MessagesResourceData.h"
#include "OrganizerGprot.h"
#include "AlarmGprot.h"
#include "ScheduledPowerOnOffGprot.h"
#include "Unicodedef.h"
#include "Unicodexdcl.h"
#include "Unicodedcl.h"		/* define the string function pointer */
#include "OrganizerGProt.h"
#include "ExtraGProt.h"
#include "IdleAppProt.h"
#include "Conversions.h"
#include "datetimetype.h"
#include "app_datetime.h"
#include "MessagesExDcl.h"

#ifdef __MMI_USB_SUPPORT__
#include "USBDeviceGprot.h"
extern kal_bool INT_USBBoot(void);
#endif /* __MMI_USB_SUPPORT__ */ 

#ifdef __MMI_IRDA_SUPPORT__
#include "IrdaMMIGprots.h"
#endif 


#ifdef __MMI_BT_SUPPORT__
#include "BTMMIScrGprots.h"
#endif 

#ifdef __MMI_FILE_MANAGER__
#include "FileManagerGProt.h"
#include "msdc_def.h"
#endif /* __MMI_FILE_MANAGER__ */ 

#ifdef __MMI_WEBCAM__
#include "mdi_datatype.h"
#include "mdi_webcam.h"
#endif /* __MMI_WEBCAM__ */ 

#include "SoundEffect.h"

#include "vObjects.h"
#include "vCalendar.h"

#include "ShortcutsProts.h"
#include "ToDoListDef.h"
#include "DataAccountGProt.h"
#include "WPSSProtos.h"
#include "CallerIdGprot.h"
#if defined(__MMI_STOPWATCH__)
#include "StopwatchGprot.h"
#endif 
#if defined(__MMI_EMAIL__)
#include "EmailAppGProt.h"
#endif /* def __MMI_EMAIL__ */
#include "OSThreadInterfaceGprot.h"

#include "AllAppGprot.h"
#include "WrapperGprot.h"
#ifdef __MMI_EBOOK_READER__
#include "EbookProt.h"
#endif 
#include "SimDetectionGprot.h"
#include "wgui_status_icons.h"
#include "PowerOnChargerProt.h"
#include "SettingGprots.h"
#include "SimDetectionGexdcl.h"
#include "PhoneSetupGprots.h"   /* PhnsetReadNvramCalibrationData */
#include "MExEGProt.h"

#if defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)
#include "SmsGuiInterfaceType.h"
#endif 

#ifdef __MMI_VOIP__
#include "VoIPGProt.h"
#endif

#ifdef __MMI_VIDEO_TELEPHONY__
#include "VTGProt.h"
#endif /* __MMI_VIDEO_TELEPHONY__ */

#ifdef __MMI_POC__
#include "PoCGProt.h"
#endif 

#ifdef __MMI_AVATAR__
#include "avatargprot.h"
#endif

#ifdef __SYNCML_SUPPORT__
#include "SyncMLGProt.h" /* mmi_syncml_init */
#endif

#ifdef __MMI_MMS_2__
#include "MMSAppGprot.h"
#endif

#ifdef __MMI_MOBILE_SERVICE__
#include "MobileServiceGProt.h"
#endif

#ifdef __MMI_CUSTOMER_SERVICE__
#include "CustSerGProt.h"
#endif

#ifdef __MMI_MY_FAVORITE__
#include "MyFavoriteGProt.h"
#endif

extern void InitAlarmHandler(void);


#if defined(__MMI_THEMES_APPLICATION__)
extern void InitThemes(void);
#endif

#ifdef __FLIGHT_MODE_SUPPORT__
#include "WallpaperDefs.h"
#include "DownloadDefs.h"
#include "PhoneSetup.h"
#endif /* __FLIGHT_MODE_SUPPORT__ */ 

extern void ATHandlerInit(void);

#if defined(__MMI_NITZ__)
extern void NITZHandlerInit(void);
#endif 
extern void PhnsetInitSetTimeNDateNvram(void);
extern void ReadValueCityNVRAM(void);


#include "lcd_sw.h"
#include "lcd_sw_inc.h"
#include "sublcd.h"

#include "ComposeRingToneProts.h"

#ifdef __MMI_IMPS__
#include "mmi_imps_gprot.h"
#endif 

#include "gdi_include.h"

#ifdef __MMI_UNIFIED_MESSAGE__
#include "UnifiedMessageGProt.h"
#endif 

#ifdef __MMI_UNIFIED_COMPOSER__
#include "UnifiedComposerGProt.h"
#endif 

#ifdef __MMI_WLAN_FEATURES__
#include "NetworkSetupDefs.h"
#endif

#ifdef __MMI_PICT_BRIDGE_SUPPORT__
#include "PictBridgeGProt.h"
#endif

#ifdef __MMI_MMS_2__
#include "MMSViewerAPPDefs.h"
#endif /* __MMI_MMS_2__ */

#ifdef SYNCML_DM_SUPPORT     
#include "dmuigprot.h"
#endif

#ifdef __MMI_DM_SELF_REGISTER_SUPPORT__
#include "DmSelfRegisterGprot.h"
#endif /* __MMI_DM_SELF_REGISTER_SUPPORT__ */

#ifdef __DRM_SUPPORT__
#include "RightsMgrGProt.h"
#endif

#ifdef __MMI_MAPBAR_GIS__
#include "MB_GISGProt.h"
#endif

#ifdef __MMI_SUNAVI_GIS__
#include "SN_GISGProt.h"
#endif

#ifdef __MMI_DUAL_SIM_MASTER__
#include "MTPNP_AD_master_header.h"
#include "MTPNP_AD_resdef.h"
#include "MTPNP_PFAL_DM_Setup.h"
#include "MTPNP_PFAL_HelpInfo.h"
#include "MTPNP_PFAL_Master_MM.h"
#include "customer_ps_inc.h"
#include "mmi_msg_context.h"
#endif	/* __MMI_DUAL_SIM_MASTER__ */

#ifdef __MMI_DUAL_SIM_DUAL_CALL_SLAVE__
#include "MTPNP_AD_slave_header.h"
#include "MTPNP_PFAL_Slave_MM.h"
#endif	/* __MMI_DUAL_SIM_DUAL_CALL_SLAVE__ */

/*****************************************************************************
* Define                                                                      
*****************************************************************************/
#ifdef __MMI_SUPPORT_DUMP_SCREEN_STRING__
// #define ENABLE_DUMP_SCREEN_STRING_TRACE
#endif /* __MMI_SUPPORT_DUMP_SCREEN_STRING__ */

/*****************************************************************************
* Typedef                                                                     
*****************************************************************************/

/*****************************************************************************
* Local Variable                                                              
*****************************************************************************/

/*****************************************************************************
* Extern Global Variable                                                      
*****************************************************************************/
oslMsgqid mmi_ext_qid;
MMI_BOOL g_keypad_flag = MMI_FALSE;
drv_get_key_func keypad_ptr = NULL;

U8 gInitAllAppFlag = 0;
U8 gInsertSimAppFlag = 0;

MYTIME StartUpTime, LastDuration;

#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
U8 g_sim_insert_state;
U8 g_dual_mode_value;
#endif

extern kal_mutexid mmi_mutex_trace;

extern U8 isEarphonePlugged;
extern U8 gMMIClamState;

/* __CUSTPACK_MULTIBIN     Terry   BEGIN */
extern U8 MMI_english_input_mode_set[INPUT_MODE_MAX_NUM];
extern U8 MMI_qsearch_input_mode_set[INPUT_MODE_MAX_NUM];
extern U8 MMI_all_input_mode_set[INPUT_MODE_MAX_NUM];
/* __CUSTPACK_MULTIBIN     Terry   END */

#ifdef __MMI_PREFER_INPUT_METHOD__
extern U16 MMI_all_prefered_input_mode_set[INPUT_MODE_MAX_NUM];
#endif 
extern const sIMEModeDetails *gIMEModeArray;
extern const sIMEModeDetails *gIMEQSearchModeArray;
extern const U8 MMI_implement_input_mode_set[];

#ifdef __FLIGHT_MODE_SUPPORT__
extern PHNSET_CNTX g_phnset_cntx;
#endif /* __FLIGHT_MODE_SUPPORT__ */

#if defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)
extern nsm_msg_struct g_nsm_msg_context;
#endif 

/*****************************************************************************
* Local Function                                                              
*****************************************************************************/
static void InitializeAll(void);
static void InitEventHandlersBeforePowerOn(void);

static U8 mmi_frm_check_is_valid_msg(MYQUEUE *base, MYQUEUE *msg);

static BOOL IMECheck(U8 IME_Mode, const U8 all_implement_IME[]);
static void InitIME(void);
static void InitIMEQSearch(const sIMEModeDetails *IMEQArray, U8 *QuickIME);
static void InitIMESetting(const sIMEModeDetails *IMEArray, U8 *allIME, U8 *englishOnlyIME, U16 *PreferedIME);

static void mmi_enable_str_dump(void *info);
static void mmi_str_cmd_ind(void *info);

#ifdef __MMI_SUPPORT_DUMP_SCREEN_STRING__
static void mmi_no_more_str_hdlr(void);
#endif /* __MMI_SUPPORT_DUMP_SCREEN_STRING__ */

/*****************************************************************************
* Extern Global Function                                                      
*****************************************************************************/
#ifdef __VOIP__
extern void em_voip_log_init(void);
#endif /*  __VOIP__ */
extern void goto_opening_screen(void);

#ifdef __MMI_PROFILE_EXTMELODY_SUPPORT__
extern void PmgInitExtMelodyStruct(void);
#endif 
extern void InitAllApplications(void);
extern void InitDownloadNVRAM(void);
extern void ReadThemesFromNVRAM(void);
extern void initnvramprofapp(void);
extern void InitializeChargingScr(void);
extern void QuitSystemOperation(void);
extern void mmi_pwron_entry_animation_screen(void);

/* 
 * for MDI 
 */
extern void mdi_audio_init(void);
extern void mdi_audio_init_event_hdlrs(void);

extern void setup_UI_wrappers(void);

/* __CUSTPACK_MULTIBIN     Terry   BEGIN */
/* 
 * For Input method
 */
#ifdef __MMI_T9__
extern void InitInputMethod(void);
#elif defined __MMI_ZI__
extern void InitZiInputMethod(void);
#elif defined __MMI_CSTAR__
extern void InitCstarInputMethod(void);
#elif defined(__MMI_KA__)
extern void InitKonkaInputMethod(void);
#elif defined(__MMI_ITAP__)
/* under construction !*/
#endif 

/* __CUSTPACK_MULTIBIN     Terry   BEGIN */
extern U8 MMI_english_input_mode_set[INPUT_MODE_MAX_NUM];
extern U8 MMI_qsearch_input_mode_set[INPUT_MODE_MAX_NUM];
extern U8 MMI_all_input_mode_set[INPUT_MODE_MAX_NUM];

#ifdef __MMI_PREFER_INPUT_METHOD__
extern U16 MMI_all_prefered_input_mode_set[INPUT_MODE_MAX_NUM];
#endif

#if defined(__MMI_MIXED_LANG_SUPPORT__) || defined(__MMI_PREFER_WRITING_LANG__)
extern ime_writing_lang_struct g_ime_writing_lang_array[12]; /* for 123 and null end */
extern S16 g_ime_main_writing_lang;
#if defined(__MMI_MIXED_LANG_SUPPORT__)
extern S16 g_ime_sub_writing_lang;
#endif /* defined(__MMI_MIXED_LANG_SUPPORT__) */
#endif


extern const sIMEModeDetails *gIMEModeArray;
extern const sIMEModeDetails *gIMEQSearchModeArray;
extern const U8 MMI_implement_input_mode_set[];

/* __CUSTPACK_MULTIBIN     Terry   END */

extern void mmiapi_init_engine(void);

/* 
 * Move InitPhoneSetupApp() to InitializeAll() for text encoding 
 */
extern void InitPhoneSetupApp(void);
extern void InitPhoneSetupCntx(void);
extern void InitAppMem(void);
extern void CheckAndPrintMsgId(U16 Id);

#if defined(__MMI_VRSD__)
extern void mmi_vrsd_init(void);
#endif 

#if defined(__MMI_VRSI__)
extern mmi_vrsi_init(void);
#endif 

#ifndef __MTK_TARGET__
extern void mmi_vrsi_setting_init_simulator(void);
#endif

#if defined(__MMI_SOUND_RECORDER__)
extern void InitSoundRecorderApp(void);
#endif 

extern void mmi_phb_sos_list_init(void);

#ifdef __MMI_MESSAGES_CHAT__
extern void InitializeChatApp(void);
#endif 
#ifdef __MMI_IRDA_SUPPORT__
extern void mmi_irda_init_menu_hdlr(void);
#endif 

#ifndef __DISABLE_SHORTCUTS_IMPL__
extern void ShctInit(void);
#endif 

extern void SetDateTime(void *t);
extern void mmi_frm_sms_init(void);

/* diamond, 2005/07/05 Flight mode */
#ifdef __FLIGHT_MODE_SUPPORT__
extern void PowerOnFlightMode(void);
extern void PowerOnNormalMode(void);
extern void EntryQueryFlightModeScreen(void);
extern void PhnsetFlightModeQueryBackground(void);  /* diamond, 2006/01/01 Force to draw the background */
extern void PhnsetFlightModePowerOnException(void);
extern void mmi_flight_mode_set_mode(U8 bFlightMode); /* send the mode to L4C ASAP to speed up the L4C startup time */
#endif /* __FLIGHT_MODE_SUPPORT__ */ 
/* end, diamond */

#ifdef __MMI_BG_SOUND_EFFECT__
extern void mmi_bgsnd_init(void);
#endif 

#if defined(__MMI_FM_RADIO_SCHEDULE_REC__)
extern void mmi_fmsr_init_app(void);
#endif 

#if defined(__MMI_DOWNLOAD_AGENT__)
extern void mmi_da_init_app(void);
#endif 

extern void mdi_audio_set_audio_mode(U8 mode);

extern void PhnsetReadGPIOSetting(void);

#ifdef __MMI_USER_CTRL_PLMN_SUPPORT__
extern void mmi_netset_init_user_ctrl_plmn(void);
#endif 

#ifdef __MMI_SWFLASH__
extern void mmi_swflash_init_app(void);
#endif

#ifdef __MMI_CCA_SUPPORT__
extern void mmi_cca_init(void);
#endif

#if defined(__MMI_LANGLN__)
extern mmi_langln_init(void);
#endif 

#ifdef OBIGO_Q05A
extern void wap_task_init(void);
#endif
#ifdef __MMI_MMS_BGSR_SUPPORT__
extern void mmi_mms_bgsr_init(void);
#endif /*__MMI_MMS_BGSR_SUPPORT__*/

#ifdef __MMI_DUAL_SIM_MASTER__ 
extern void MMI_MTPNP_master_init(void);
#endif	/* __MMI_DUAL_SIM_MASTER__  */

#ifdef __MMI_DUAL_SIM_DUAL_CALL_SLAVE__
extern void MMI_MTPNP_slave_init(void);
#endif	/* __MMI_DUAL_SIM_DUAL_CALL_SLAVE__ */


#ifdef __MMI_BOOTUP_SCALE__
#define MMI_APP_INIT(func) {U32 start_time, end_time;\
                            S8 func_name[] = #func;\
                            kal_get_time(&start_time);\
                            func;\
                            kal_get_time(&end_time);\
                            kal_sleep_task(50);\
                            Trace2(TRACE_FUNC, "[BOOTUP SCALE]Function: %s Time: %d", func_name, (end_time-start_time));\
                           }
#else
#define MMI_APP_INIT(func)  func
#endif

/*****************************************************************************
 * FUNCTION
 *  MMI_Init
 * DESCRIPTION
 *  MMI Init Function
 * PARAMETERS
 *  task_indx       [IN]        Index of task
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL MMI_Init(task_indx_type task_indx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_mutex_trace = kal_create_mutex("mmi_trace");

    mmi_frm_get_2step_keys();

    /* 
     * initial the system service timer 
     */
    L4InitTimer();
    setup_UI_wrappers();

#if defined(__MMI_RESOURCE_ENFB_SUPPORT__)
    /* 
     * Init Resource Memory Manamger  for E-NFB
     */
	mmi_frm_resmem_init();
#endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  FlightModeCheckBeforeAnimation
 * DESCRIPTION
 *  Flight mode query screen before animation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/* static U8 gFlightModeFromCalibration; */
void FlightModeCheckBeforeAnimation()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* diamond, 2005/07/05 Flight mode */
#if defined(__MMI_DUAL_SIM_MASTER__) || defined(__MMI_DUAL_SIM_DUAL_CALL_SLAVE__)
#ifdef __QUERY_PSN_SUPPORT__
	EntryQueryRegisterSW();
#else	/* __QUERY_PSN_SUPPORT__ */
	MTPNP_AD_Bootup();
#endif	/* __QUERY_PSN_SUPPORT__ */
#else	/* __MMI_DUAL_SIM_MASTER__ || __MMI_DUAL_SIM_DUAL_CALL_SLAVE__ */
#ifdef __FLIGHT_MODE_SUPPORT__
    switch (g_phnset_cntx.curFlightMode)
    {
        case FLIGHTMODE_QUERY:
            TurnOnBacklight(1);
            PhnsetFlightModeQueryBackground();  /* diamond, 2006/01/01 Force to draw the background */
            EntryQueryFlightModeScreen();
            break;

        case FLIGHTMODE_SILENT:
        case FLIGHTMODE_OFF:
            mmi_bootup_exit_flight_mode_query();
            break;

        default:
            PowerOnNormalMode();
            break;
    }
#else /* __FLIGHT_MODE_SUPPORT__ */ 
    mmi_bootup_entry_animation();   /* not necessary to enter flight mode query screen if it is not supported */
#endif /* __FLIGHT_MODE_SUPPORT__ */ 
#endif	/* __MMI_DUAL_SIM_MASTER__  || __MMI_DUAL_SIM_DUAL_CALL_SLAVE__ */
    /* end, diamond */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_fetch_msg_from_extQ_to_circularQ
 * DESCRIPTION
 *  fetch the message from external queue and put
 *  in the circular queue.
 *  (*) Need to set my_index & mmi_ext_qid before using
 *  this function
 * PARAMETERS
 *  void
 * RETURNS
 *  1 - the message is invalid, and discard the message
 *  0 - the message is vaild
 *****************************************************************************/
void mmi_frm_fetch_msg_from_extQ_to_circularQ(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    U32 my_index;
    U32 queue_node_number = 0;
    MYQUEUE checkBaseNode = {0};
    U8 flag = 0;
    ilm_struct ilm_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsInNVRAMProcedure() == MMI_FALSE)
    {
        /*
         * If not in NVRAM access procedure,
         * receive the message from MMI queue and put in circular queue 
         */
        msg_get_ext_queue_info(mmi_ext_qid, &queue_node_number);
        while ((queue_node_number > 0) && !OslIsCircularQFull())
        {
            OslReceiveMsgExtQ(mmi_ext_qid, &Message);
            OslGetMyTaskIndex(&my_index);
            OslStackSetActiveModuleID(my_index, MOD_MMI);
            OslLookUpLastCircularQMsg((void*)&checkBaseNode);

            if (mmi_frm_check_is_valid_msg(&checkBaseNode, &Message) == 1)
            {
                /* put Message in circular queue */
                ilm_ptr.src_mod_id = Message.src_mod_id;
                ilm_ptr.dest_mod_id = Message.dest_mod_id;
                ilm_ptr.msg_id = Message.msg_id;
                ilm_ptr.sap_id = Message.sap_id;
                ilm_ptr.local_para_ptr = Message.local_para_ptr;
                ilm_ptr.peer_buff_ptr = Message.peer_buff_ptr;

                flag = OslWriteCircularQ(&ilm_ptr);
                MMI_ASSERT(flag == 1);
                /* TIMER use special data in the local_para_ptr field. Can NOT treat as general ILM */
                if (Message.src_mod_id != MOD_TIMER)
                {
                    hold_local_para(ilm_ptr.local_para_ptr);
                    hold_peer_buff(ilm_ptr.peer_buff_ptr);
                }
            }
            OslFreeInterTaskMsg(&Message);

            msg_get_ext_queue_info(mmi_ext_qid, &queue_node_number);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_power_on_set_mode
 * DESCRIPTION
 *  Power on set flight mode before initializa all applications
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_power_on_set_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __FLIGHT_MODE_SUPPORT__
    /* send the mode to L4C ASAP to speed up the L4C startup time */
    if (g_phnset_cntx.curFlightMode == FLIGHTMODE_SILENT)
    {
        mmi_flight_mode_set_mode(1);
    }
    else if (g_phnset_cntx.curFlightMode == FLIGHTMODE_OFF)
    {
    #ifdef __MMI_WLAN_FEATURES__
        if (mmi_netset_get_active_preferred_mode() == P_WLAN_ONLY)
            mmi_flight_mode_set_mode(1);
	else
    #endif /* __MMI_WLAN_FEATURES__ */
        mmi_flight_mode_set_mode(0);
    }
    else
    {
        /* display qurey screen after InitializeAll */
    }
#endif /* __FLIGHT_MODE_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_power_on_init_procedure
 * DESCRIPTION
 *  Power on initializations
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_power_on_init_procedure(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static U8 bInit = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!bInit)
    {
        MMI_APP_INIT(InitializeAll());
        OslDumpDataInFile();
        MMI_APP_INIT(InitNvramData());

        bInit = 1;
    }
}

extern int bPrintEnable;
/*****************************************************************************
 * FUNCTION
 *  noke_dbg_printf
 * DESCRIPTION
 *  noke_dbg_printf
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void noke_dbg_printf( const char * format,  ... )
{

#if (defined(NOKE_DEBUG) && !defined(WIN32))
if(bPrintEnable)
{
	int i =0;
	char ch[256];
	va_list ap;

	va_start(ap,format);
	vsprintf(ch,format,ap);
	va_end (ap);


	while(ch[i]!=(char)0 && i<256)
	{
		PutUARTByte(uart_port1,ch[i]);
		++i;
	}

	if(ch[0])
	{
		PutUARTByte(uart_port1, 0);
	}
}
#endif
}



/* 2009.05.04 move here by hongzhe.liu + */

#include "AudioPlayerResDef.h"
#include "IdleAppResDef.h"
extern BOOL mmi_audply_is_playing(void);
extern U16 GetActiveScreenId(void);
extern void ProcessMusicUpMessage(void) ;
extern void ProcessMusicDownMessage(void) ;
extern void ProcessWallPaperUpMessage(void);
extern void ProcessWallPaperDownMessage(void);
extern unsigned short NVRAM_GSENSOR_DATA ;

#if defined(G_SENSOR_SUPPORT) ||defined( __DIRECTION_SENSOR_SUPPORT__)//sk 0812

void Process_Music_Up(void)
{
	unsigned 	short index = 0 ;	
	char  data = 0 ;	
	char play_music = 0 ;

#if defined(G_SENSOR_SUPPORT) 
	index = NVRAM_GSENSOR_DATA ;
#endif
	play_music =  mmi_audply_is_playing();
	
	if (  GetActiveScreenId() == SCR_ID_AUDPLY_MAIN  )
      	{
	      if((index == 0 ) && (play_music == KAL_TRUE))
	      {
			ProcessMusicUpMessage();
		}
      	}
}

void Process_Music_Down(void)
{
	unsigned 	short index = 0 ;	
	char  data = 0 ;	
	char play_music = 0 ;

#if defined(G_SENSOR_SUPPORT) 
	index = NVRAM_GSENSOR_DATA ;
#endif
	play_music =  mmi_audply_is_playing();
	
	if (  GetActiveScreenId() == SCR_ID_AUDPLY_MAIN  )
      	{
	      if((index == 0 ) && (play_music == KAL_TRUE))
	      {
			ProcessMusicDownMessage();
		}
      	}
}

void Process_WallPaper_Up(void)
{
	unsigned 	short index = 0 ;	
	char  data = 0 ;	
#if defined(G_SENSOR_SUPPORT) 
	index = NVRAM_GSENSOR_DATA ;
#endif
	if (  GetActiveScreenId() == IDLE_SCREEN_ID  )
      	{
	      if((index == 0 ) )
			ProcessWallPaperUpMessage();	
      	}
}

void Process_WallPaper_Down(void)
{
	unsigned 	short index = 0 ;	
	char  data = 0 ;	
#if defined(G_SENSOR_SUPPORT) 
	index = NVRAM_GSENSOR_DATA ;
#endif
	if (  GetActiveScreenId() == IDLE_SCREEN_ID  )
      	{
	      if((index == 0 ) )
			ProcessWallPaperDownMessage();
	
      	}
}
#endif

#include "VdoRecResDef.h"
extern void ProcessTVChannelUpMessage(void);
extern void ProcessTVChannelDownMessage(void);

void Process_TvChannel_Up(void)
{
	unsigned 	short index = 0 ;	
	char  data = 0 ;	
#if defined(G_SENSOR_SUPPORT) 
	index = NVRAM_GSENSOR_DATA ;
#endif
#ifdef ANALOG_TV_SUPPORT
	if (  GetActiveScreenId() == SCR_ID_TV_IN_APP  )
      	{
	      if((index == 0 ) )
			ProcessTVChannelUpMessage();
	
      	}
#endif
}

void Process_TvChannel_Down(void)
{
	unsigned 	short index = 0 ;	
	char  data = 0 ;	
#if defined(G_SENSOR_SUPPORT) 
	index = NVRAM_GSENSOR_DATA ;
#endif
#ifdef ANALOG_TV_SUPPORT	
	if (  GetActiveScreenId() == SCR_ID_TV_IN_APP  )
      	{
	      if((index == 0 ) )
			ProcessTVChannelDownMessage();
	
      	}
#endif
}
/* 2009.05.04 move here by hongzhe.liu - */

/* 2009.05.04 added by hongzhe.liu  +  */

/*
 *  Parameter = 1 : full screen
 */
extern void ProcessTVFullScreenMessage(int full_scr);
void Process_Tv_Full_Screen(int full_scr)
{
#ifdef ANALOG_TV_SUPPORT	
	if (  GetActiveScreenId() == SCR_ID_TV_IN_APP  )
      	{
		ProcessTVFullScreenMessage(full_scr);
		
      	}
#endif
}

#include "VdoPlyResDef.h"
extern void ProcessVdoplayerFullScreenMessage(int full_scr);
extern BOOL mmi_vdoply_is_toggle_fullscreen_enable();
void Process_Vdoplayer_Full_Screen(int full_scr)
{
	if (  /*(GetActiveScreenId() == SCR_ID_VDOPLY_APP ||  GetActiveScreenId() ==  SCR_ID_VDOPLY_PLAYER) &&  */
		mmi_vdoply_is_toggle_fullscreen_enable())
      	{
		ProcessVdoplayerFullScreenMessage(full_scr);
      	}
}

/* 2009.05.04 added by hongzhe.liu -  */

#if defined(G_SENSOR_SUPPORT)
//Huyanwei Add It 
#include "FSL_MMA.h"

extern VINT8 paraX  ;
extern VINT8 paraY  ;
extern VINT8 paraZ  ;

void Process_GSensor(int Flags)
{
	static int mutex = 1 ;
	if(mutex == 1)
	{
		mutex = 0;
		if(Flags == 0)
		{
			Process_Music_Up();	
			Process_WallPaper_Up();
			Process_TvChannel_Up();
		}
		else
		{
			Process_Music_Down();	
			Process_WallPaper_Down();
			Process_TvChannel_Down();
		}
		mutex = 1 ;
	}
}


void ReadData_GSensor(void)
{
	char data = 0 ;
	char Z= 0 ;
#if defined(G_SENSOR_SUPPORT) 
	data=mma745x_IICRead(0x17); 
	Z= mma745x_IICRead(0x08); 
#endif	
}

#endif



/* 2009.05.04 added by hongzhe.liu for m-sensor +  */

extern void Process_image_viewer(msg_type msg_id);
#include "idleappdef.h"
extern idle_keylock_struct g_keylock_context;
void Process_MSensor(msg_type msg_id)
{
	if(g_keylock_context.gKeyPadLockFlag == 1)
	{
		return ;
	}	
#if defined(__DIRECTION_SENSOR_SUPPORT__)
    if( (msg_id>=MSG_ID_MSENSOR_DIRECTION_0) && (msg_id<=MSG_ID_MSENSOR_DIRECTION_270) )
    {
	switch(msg_id)
	{
	case MSG_ID_MSENSOR_DIRECTION_0:
		Process_Music_Down();	
		Process_Tv_Full_Screen(0);
		Process_Vdoplayer_Full_Screen(0);
#if defined(NOKE_DEBUG)
		noke_dbg_printf("\rHongzhe.Liu : Msensor direction 0\n");
#endif
		break;
	case MSG_ID_MSENSOR_DIRECTION_90:
		Process_Tv_Full_Screen(0);
		Process_Vdoplayer_Full_Screen(0);
#if defined(NOKE_DEBUG)
		noke_dbg_printf("\rHongzhe.Liu : Msensor direction 90\n");
#endif
		break;
	case MSG_ID_MSENSOR_DIRECTION_180:
		//Process_Music_Up();	
		Process_Tv_Full_Screen(1);
		Process_Vdoplayer_Full_Screen(1);
#if defined(NOKE_DEBUG)
		noke_dbg_printf("\rHongzhe.Liu : Msensor direction 180\n");
#endif
		break;
	case MSG_ID_MSENSOR_DIRECTION_270:
		Process_Tv_Full_Screen(0);
		Process_Vdoplayer_Full_Screen(0);
#if defined(NOKE_DEBUG)
		noke_dbg_printf("\rHongzhe.Liu : Msensor direction 270\n");
#endif
		break;
	default:
		break;
	}

        Process_image_viewer(msg_id);
    }
	
#endif /* __DIRECTION_SENSOR_SUPPORT__ */
}

/* 2009.05.04 added by hongzhe.liu for m-sensor -  */


#if defined(HORSERACE_SUPPORT)
//Huyanwei Add it 
extern void HorseRaceThreadTask(void );
extern int  HorseRaceThreadTaskFlag(void);
extern void SendMessagesMMIToTwo(msg_type MSG_ID );
#endif


/*****************************************************************************
 * FUNCTION
 *  MMI_task
 * DESCRIPTION
 *  Entry function for Protocol task
 *  
 *  This receives protocol task events from the stack and forwards it to
 *  MMI task.
 * PARAMETERS
 *  entry_param     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void MMI_task(oslEntryType *entry_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    oslMsgqid qid;

    U32 my_index;
    U32 count = 0;
    U32 queue_node_number = 0;

#if defined(NOKE_DEBUG)
    noke_dbg_printf("\r Entry MMI_task \n");
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    qid = task_info_g[entry_param->task_indx].task_ext_qid;
    mmi_ext_qid = qid;
    InitEventHandlersBeforePowerOn();

#if defined (__MMI_DUAL_SIM_MASTER__)
    MMI_MTPNP_master_init();
#endif

#ifdef __MMI_DUAL_SIM_DUAL_CALL_SLAVE__
    MMI_MTPNP_slave_init();
#endif	/* __MMI_DUAL_SIM_DUAL_CALL_SLAVE__ */
    while (1)
    {
        {

            if (g_keypad_flag == MMI_TRUE)
            {
                mmi_frm_key_handle(NULL);
            }

            /* Leo start 20050825 */
/********************************************************************
*   Check if number of events in queue increases.
*   If yes, clear more external queue events, else clear less external queue events.
*   At lease clear one external queue event.
********************************************************************/
            /* Get Total count in external queue */
            msg_get_ext_queue_info(mmi_ext_qid, &queue_node_number);

            if ((queue_node_number == 0) && (OslNumOfCircularQMsgs() == 0) && (g_keypad_flag == MMI_FALSE))
            {
                U8 flag = 0;
                ilm_struct ilm_ptr;

                /* MMI task suspends for the queue */
                OslReceiveMsgExtQ(qid, &Message);
                OslGetMyTaskIndex(&my_index);
                OslStackSetActiveModuleID(my_index, MOD_MMI);

                /* put Message in circular queue */
                ilm_ptr.src_mod_id = Message.src_mod_id;
                ilm_ptr.dest_mod_id = Message.dest_mod_id;
                ilm_ptr.msg_id = Message.msg_id;
                ilm_ptr.sap_id = Message.sap_id;
                ilm_ptr.local_para_ptr = Message.local_para_ptr;
                ilm_ptr.peer_buff_ptr = Message.peer_buff_ptr;

                flag = OslWriteCircularQ(&ilm_ptr);
                MMI_ASSERT(flag == 1);
                /* TIMER use special data in the local_para_ptr field. Can NOT treat as general ILM */
                if (Message.src_mod_id != MOD_TIMER)
                {
                    hold_local_para(ilm_ptr.local_para_ptr);
                    hold_peer_buff(ilm_ptr.peer_buff_ptr);
                    OslFreeInterTaskMsg(&Message);
                }
            }
            else
            {
                mmi_frm_fetch_msg_from_extQ_to_circularQ();
            }

            count = OslNumOfCircularQMsgs();
            while (count > 0)
            {
                OslGetMyTaskIndex(&my_index);
                OslStackSetActiveModuleID(my_index, MOD_MMI);

                if (OslReadCircularQ(&Message))
                {
                    CheckAndPrintMsgId((U16) (Message.msg_id));

			 #if defined(G_SENSOR_SUPPORT)
			 //huyanwei Add it 
			   if (Message.msg_id == MSG_ID_GSENSOR_LEFT)
	                    	{     	                    		
	                    		Process_GSensor(0);					
	                    	}
				else if (Message.msg_id == MSG_ID_GSENSOR_RIGHT)
	                    	{     	                   		
		                    	Process_GSensor(1);
	                    	}				
			 #endif
				 /* 2009.05.04 added by hongzhe.liu for m-sensor +  */
			 #if defined(__DIRECTION_SENSOR_SUPPORT__)
			  	Process_MSensor(Message.msg_id);			
			 #endif
				/* 2009.05.04 added by hongzhe.liu for m-sensor -  */				 	


			 #if defined(HORSERACE_SUPPORT)
			 //Huyanwei Add It For HorseRace 
			   if (Message.msg_id == MSG_ID_HORSERACE_ON)			 	
			   {
					// Avoid Message Loop
				   	HorseRaceThreadTask();
			   }
			 #endif


			#if defined(DOUBLE_BATTERY_SUPPORT)
 		       //huyanwei Add it For The New Message Battery
		       if (Message.msg_id == MSG_ID_BATTERYII_PLUG_IN )
                    	{     
                  		#ifndef WIN32		           
                    		// Battery II In
                    		UpdateBatteryLevel(); //Huyanwei Add It 
        		
                    		if(ExistSubBattery() == 1)
                    		{                    			
#if defined(NOKE_DEBUG)
					noke_dbg_printf(" ====In ExistSubBattery()= 1 \n\r");                    				
#endif
	               		}
				else
				{
#if defined(NOKE_DEBUG)
					noke_dbg_printf(" ====In ExistSubBattery() =0 \n\r");                    					
#endif
				}

				if( g_charbat_context.isChargerConnected == 1)
                    		{
#if defined(NOKE_DEBUG)
                    			     noke_dbg_printf(" Sub Battery Charging ...\n\r");        
#endif
					     #ifndef WIN32									 
                    			     ChargeSwCtl( 1 ); //Switch Sub Battery
                    			     #endif
                   			     SetMainBatteryChargeState(0);
                    		}
				#endif
                    	}
			else if (Message.msg_id == MSG_ID_BATTERYII_PLUG_OUT )
                    	{  
                    		// Battery II Out
			       #ifndef WIN32	
                    		UpdateBatteryLevel(); //Huyanwei Add It 					                    		
                    		if(ExistSubBattery() == 1 )
                    		{
#if defined(NOKE_DEBUG)
					noke_dbg_printf(" ====Out ExistSubBattery()= 1 \n\r");                    				
#endif
	             		}
				else
				{
#if defined(NOKE_DEBUG)
					noke_dbg_printf(" ====Out ExistSubBattery() =0 \n\r");                    					
#endif
				}

				if( g_charbat_context.isChargerConnected == 1)
                    		{
#if defined(NOKE_DEBUG)
                    			     noke_dbg_printf(" Main Battery Charging ...\n\r");        
#endif
	 			            ChargeSwCtl( 0 ); //Switch to Main  Battery	 			               	     
                    			     SetMainBatteryChargeState(1);
                    		}
				#endif
                    	}			
		       #endif


                    if (Message.dest_mod_id == MOD_WAP)
                    {
                    #if defined(JATAAYU_SUPPORT) || defined(OBIGO_Q05A)
                        extern void mmi_wap_handle_msg(void *msgPtr);

                        mmi_wap_handle_msg((void*)&Message);
                    #endif /* JATAAYU_SUPPORT */ 
                    }
                    else
                    {
                        switch (Message.msg_id)
                        {
                     #if (defined(__MMI_DUAL_SIM_MASTER__) || defined(__MMI_DUAL_SIM_DUAL_CALL_SLAVE__)) && !defined (__MMI_DUAL_SIM_SINGLE_CALL__)
                            case MSG_ID_MTPNP:
                                {
                                MTPNP_AD_EventHandler((void *)Message.oslDataPtr);
                                }
                                break;
			        #endif	/* defined(__MMI_DUAL_SIM_MASTER__) || defined(__MMI_DUAL_SIM_DUAL_CALL_SLAVE__) */
                    #ifdef __MMI_DUAL_SIM_DUAL_CALL_SLAVE__
                            case MSG_ID_SLAVE_STARTUP_REQ:
                                MTPNP_PFAL_slave_MMI_task_boot();
                                break;
                            case MSG_ID_VEINT:
                                MTPNP_Send_VEINT();
                                break;
                    #endif	/* __MMI_DUAL_SIM_DUAL_CALL_SLAVE__ */
                            case MSG_ID_TIMER_EXPIRY:
                            {
                                kal_uint16 msg_len;

                                EvshedMMITimerHandler(get_local_para_ptr(Message.oslDataPtr, &msg_len));
                            }
                                break;

                        #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                            case MSG_ID_MMI_EQ_PWNON_DUAL_SIM_IND:
                                MTPNP_AD_Pwnon_Dual_SIM();
                                break;
                        #endif /* __MMI_DUAL_SIM_SINGLE_CALL__ */

                            case MSG_ID_MMI_EQ_POWER_ON_IND:
                            {
                                mmi_eq_power_on_ind_struct *p = (mmi_eq_power_on_ind_struct*) Message.oslDataPtr;

                                /* To initialize data/time */
                                SetDateTime((void*)&(p->rtc_time));
                                gdi_init();

                                g_pwr_context.PowerOnMMIStatus = MMI_POWER_ON_INDICATION;       /* 0x01: POWER_ON_KEYPAD indication */
                            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__                            
                                g_pwr_context_2.PowerOnMMIStatus = MMI_POWER_ON_INDICATION;
                            #endif

                            #ifdef __MMI_TVOUT__
                                mmi_phnset_tvout_check_pwron_start();
                            #endif

                                switch (p->poweron_mode)
                                {
                                    case POWER_ON_KEYPAD:
#if defined(NOKE_DEBUG)
										noke_dbg_printf("\r POWER_ON_KEYPAD \n");
#endif
                                    #ifdef __MMI_DUAL_SIM_MASTER__
                                        MTPNP_AD_Set_PowerOn_Mode(MTPNP_AD_POWERON_KEYPAD);
                                        MTPNP_AD_Init();
                                    #endif /* __MMI_DUAL_SIM_MASTER__ */

                                    #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                                        if (p->flightmode_state == 1)
                                        {
                                            g_pwr_context.PowerOnNWStatus |= MMI_NW_STATUS_NETWORK_FLAG;
                                            g_pwr_context_2.PowerOnNWStatus |= MMI_NW_STATUS_NETWORK_FLAG;
                                            MTPNP_AD_Set_Startup_Mode(MTPNP_AD_NVRAM_FLIGHT);
                                        }
                                        else if (p->dual_sim_mode_setting == 0)
                                        {
                                            g_pwr_context_2.PowerOnNWStatus |= MMI_NW_STATUS_NETWORK_FLAG; /* no need to search SIM2 network in SIM1 only mode */
                                            MTPNP_AD_Set_Startup_Mode(MTPNP_AD_NVRAM_CARD1);
                                            MTPNP_PFAL_Replace_StatusICON(STATUS_ICON_SIGNAL_STRENGTH, IMG_SI_MASTER_SIGNAL_STRENGTH);
                                        }
                                        else if (p->dual_sim_mode_setting == 1)
                                        {
                                            g_pwr_context.PowerOnNWStatus |= MMI_NW_STATUS_NETWORK_FLAG; /* no need to search SIM1 network in SIM2 only mode */
                                            MTPNP_AD_Set_Startup_Mode(MTPNP_AD_NVRAM_CARD2);
                                            MTPNP_PFAL_Replace_StatusICON(STATUS_ICON_SLAVE_SIGNAL_STRENGTH, IMG_SI_SLAVE_SIGNAL_STRENGTH);
                                        }
                                        else
                                        {
                                            MTPNP_AD_Set_Startup_Mode(MTPNP_AD_NVRAM_DUALCARD);
                                            MTPNP_PFAL_Replace_StatusICON(STATUS_ICON_SIGNAL_STRENGTH, IMG_SI_MASTER_SIGNAL_STRENGTH);
                                            MTPNP_PFAL_Replace_StatusICON(STATUS_ICON_SLAVE_SIGNAL_STRENGTH, IMG_SI_SLAVE_SIGNAL_STRENGTH);
                                        }

                                        PhnsetSetUARTConfig(p->dual_sim_uart_setting); 
                                    #endif /* __MMI_DUAL_SIM_SINGLE_CALL__ */

                                        OslMemoryStart(TRUE);
                                        g_charbat_context.PowerOnCharger = 0;
                                        g_pwr_context.PowerOnMode = POWER_ON_KEYPAD;
                                    #ifdef __MMI_DUAL_SIM_SINGLE_CALL__                            
                                        g_pwr_context_2.PowerOnMMIStatus = POWER_ON_KEYPAD;
                                    #endif

                                        DTGetRTCTime(&StartUpTime);
                                        memset(&LastDuration, 0, sizeof(LastDuration));

                                #if !defined(__MTK_TARGET__) /* MoDIS only */
                                        mmi_netset_write_auto_test_result(MMI_FALSE);
                                #endif

                                        /* disk check */
                                #ifdef __FLIGHT_MODE_SUPPORT__
                                        g_phnset_cntx.curFlightMode = p->flightmode_state;
                                #endif 

                                    #ifdef __MMI_DUAL_SIM_DUAL_CALL_SLAVE__
                                        MTPNP_AD_Set_Slave_PowerOn_Mode(MTPNP_AD_POWERON_KEYPAD);
                                        break;
                                    #else
                                        mmi_bootup_entry_disk_check();
                                        PRINT_INFORMATION(" NORMAL POWER ON SUCCESS!!!!");
                                        break;
                                    #endif

                                    case POWER_ON_PRECHARGE:
                                    case POWER_ON_CHARGER_IN:
#if defined(NOKE_DEBUG)
										noke_dbg_printf("\r POWER_ON_PRECHARGE | POWER_ON_CHARGER_IN \n");
#endif
                           /************************************** 
                            * Always send charger-in indication
                            * to avoid fast repeating charger 
                            * in-out b4 power-on completes
                            * Lisen 04/13/2004
                           ***************************************/
                                    #ifdef __MMI_DUAL_SIM_MASTER__
                                        if (p->poweron_mode == POWER_ON_PRECHARGE)
                                        {
                                            MTPNP_AD_Set_PowerOn_Mode(MTPNP_AD_POWERON_PRECHARGE);
                                        }
                                        else if (p->poweron_mode == POWER_ON_CHARGER_IN)
                                        {
                                            MTPNP_AD_Set_PowerOn_Mode(MTPNP_AD_POWERON_CHARGER_IN);
                                        }
                                    #endif  /* __MMI_DUAL_SIM_MASTER__ */
                                    #ifdef __MMI_DUAL_SIM_DUAL_CALL_SLAVE__
                                        break;
                                    #endif
                                        g_pwr_context.PowerOnMode = p->poweron_mode;    /* Charger/Pre-charge Power On */
                                        InitializeChargingScr();
                                        if (!g_charbat_context.isChargerConnected)
                                        {
                                            QuitSystemOperation();
                                        }

                                        PRINT_INFORMATION(" CHARGER POWER ON SUCCESS!!!!");
                                        break;

                                    case POWER_ON_ALARM:
#if defined(NOKE_DEBUG)
										noke_dbg_printf("\r POWER_ON_ALARM \n");
#endif
                                	#ifdef __MMI_DUAL_SIM_MASTER__
                                        MTPNP_AD_Set_PowerOn_Mode(MTPNP_AD_POWERON_ALARM);
                                	#endif
                                	#ifdef __MMI_DUAL_SIM_DUAL_CALL_SLAVE__
                                           break;
                                	#endif
                                        g_pwr_context.PowerOnMode = POWER_ON_ALARM;
                                    #ifdef __MMI_SUBLCD__
                                        gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
                                        gdi_layer_clear(GDI_COLOR_BLACK);
                                        gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
                                    #endif /* __MMI_SUBLCD__ */ 
                                        gdi_layer_clear(GDI_COLOR_BLACK);
                                        AlmInitRTCPwron();
                                        PRINT_INFORMATION(" ALARM POWER ON SUCCESS!!!!");
                                        break;
                                    case POWER_ON_EXCEPTION:
#if defined(NOKE_DEBUG)
										noke_dbg_printf("\r POWER_ON_EXCEPTION \n");
#endif
                                    #ifdef __MMI_DUAL_SIM_MASTER__
                                        {
                                            MTPNP_AD_Set_PowerOn_Mode(MTPNP_AD_POWERON_EXCEPTION);
                                            MTPNP_AD_Init();
                                        }
                                    #endif  /* __MMI_DUAL_SIM_MASTER__ */
                                    #ifdef __MMI_DUAL_SIM_DUAL_CALL_SLAVE__
                                        {
                                            MTPNP_AD_Set_Slave_PowerOn_Mode(MTPNP_AD_POWERON_EXCEPTION);
                                            break;
                                        }
                                    #endif  /* __MMI_DUAL_SIM_DUAL_CALL_SLAVE__ */
                                        g_pwr_context.PowerOnMode = POWER_ON_EXCEPTION;

                                    #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                                        if (p->flightmode_state == 1)
                                        {
                                            g_pwr_context.PowerOnNWStatus |= MMI_NW_STATUS_NETWORK_FLAG;
                                            g_pwr_context_2.PowerOnNWStatus |= MMI_NW_STATUS_NETWORK_FLAG;
                                            MTPNP_AD_Set_Startup_Mode(MTPNP_AD_NVRAM_FLIGHT);
                                        }
                                        else if (p->dual_sim_mode_setting == 0)
                                        {
                                            g_pwr_context_2.PowerOnNWStatus |= MMI_NW_STATUS_NETWORK_FLAG; /* no need to search SIM2 network in SIM1 only mode */
                                            MTPNP_AD_Set_Startup_Mode(MTPNP_AD_NVRAM_CARD1);
                                            MTPNP_PFAL_Replace_StatusICON(STATUS_ICON_SIGNAL_STRENGTH, IMG_SI_MASTER_SIGNAL_STRENGTH);
                                        }
                                        else if (p->dual_sim_mode_setting == 1)
                                        {
                                            g_pwr_context.PowerOnNWStatus |= MMI_NW_STATUS_NETWORK_FLAG; /* no need to search SIM1 network in SIM2 only mode */
                                            MTPNP_AD_Set_Startup_Mode(MTPNP_AD_NVRAM_CARD2);
                                            MTPNP_PFAL_Replace_StatusICON(STATUS_ICON_SLAVE_SIGNAL_STRENGTH, IMG_SI_SLAVE_SIGNAL_STRENGTH);
                                        }
                                        else
                                        {
                                            MTPNP_AD_Set_Startup_Mode(MTPNP_AD_NVRAM_DUALCARD);
                                            MTPNP_PFAL_Replace_StatusICON(STATUS_ICON_SIGNAL_STRENGTH, IMG_SI_MASTER_SIGNAL_STRENGTH);
                                            MTPNP_PFAL_Replace_StatusICON(STATUS_ICON_SLAVE_SIGNAL_STRENGTH, IMG_SI_SLAVE_SIGNAL_STRENGTH);
                                        }

                                        PhnsetSetUARTConfig(p->dual_sim_uart_setting); 
                                    #endif /* __MMI_DUAL_SIM_SINGLE_CALL__ */

                                    #ifdef __MMI_SUBLCD__
                                        gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
                                        gdi_layer_clear(GDI_COLOR_BLACK);
                                        gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
                                    #endif /* __MMI_SUBLCD__ */ 
                                        gdi_layer_clear(GDI_COLOR_BLACK);
                                        OslMemoryStart(TRUE);
                                        SetAbnormalReset();
                                        InitializeAll();
                                        OslDumpDataInFile();
                                        PRINT_INFORMATION(" Exception POWER ON SUCCESS!!!!");
                                        ClearInputEventHandler(MMI_DEVICE_ALL);
                                        ClearKeyHandler(KEY_END, KEY_LONG_PRESS);

                           /**************************************
                            * Please note that the order of the following actions matters. 
                            * NVRAM data must be read before InitAllApplications, or there might be 
                            * unexpected errors. 
                           ***************************************/
                                        InitNvramData();
                                        InitAllApplications();

                                    #ifdef __FLIGHT_MODE_SUPPORT__
                                        PhnsetFlightModePowerOnException();
                                    #endif 
                           /***************************************
                            * To check power on display if need restore 
                            ***************************************/
                                        mmi_pwron_exception_check_display();
									

                                        break;

                                    #ifdef __MMI_USB_SUPPORT__
                                    case POWER_ON_USB:
#if defined(NOKE_DEBUG)
										noke_dbg_printf("\r POWER_ON_USB \n");
#endif										
                                    #ifdef __MMI_DUAL_SIM_MASTER__
                                        {
                                            MTPNP_AD_Set_PowerOn_Mode(MTPNP_AD_POWERON_USB);
                                        }
									#endif	/* __MMI_DUAL_SIM_MASTER__ */
                                    #ifdef __MMI_DUAL_SIM_DUAL_CALL_SLAVE__
                                            break;
                                    #endif  /* __MMI_DUAL_SIM_DUAL_CALL_SLAVE__ */
                                        g_pwr_context.PowerOnMode = POWER_ON_USB;
                           /***************************************
                            * Because Aux task will not init in USB boot mode 
                            * Interrupt service routine for clam detection CLAM_EINT_HISR() 
                            * is not register, force the clam state to open 
                            * If Aux task is necessary in USB mode, this tircky could be removed 
                            * Robin 1209 
                            ***************************************/
                                        gMMIClamState = 1;
                                        InitializeUsbScr();
                           /***************************************
                            * To disable keypad tone state 
                            ***************************************/
                                        mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);
                                        PRINT_INFORMATION(" USB POWER ON SUCCESS!!!!");
                                        break;
                                    #endif /* __MMI_USB_SUPPORT__ */ 

                                    default:
                                        break;
                                }
                            }
                                break;

                            default:
                                ProtocolEventHandler(
                                    (U16) Message.oslMsgId,
                                    (void*)Message.oslDataPtr,
                                    (int)Message.oslSrcId,
                                    (void*)&Message);
                                break;
                        }

                    }

                    OslFreeInterTaskMsg(&Message);
                }   /* OslReadCircularQ(&Message) */
                msg_get_ext_queue_info(mmi_ext_qid, &queue_node_number);
                count--;
            }
        }     
    }
}


/*****************************************************************************
 * FUNCTION
 *  InitFramework
 * DESCRIPTION
 *  To Initialize framework,
 *  
 *  This is used to To Initialize framework,.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitFramework(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 
     * Initialize events handler  
     */
    InitEvents();
    /* 
     * Initialize keyprocess 
     */
    InitProcessKeyEvent();
    /* 
     * Initialize history 
     */
    InitHistory(NULL, (SubLcdHistoryCBPtr)SubLCDIdleScreen);

}

#ifdef __MMI_SUPPORT_DUMP_SCREEN_STRING__

/*****************************************************************************
 * FUNCTION
 *  mmi_trace_screen_string
 * DESCRIPTION
 *  Sending the screen string
 *  
 * PARAMETERS
 *  x           [IN]
 *  y           [IN]
 *  str         [IN]
 *  len         [IN]
 *  Bordered    [IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_trace_screen_string(S32 x, S32 y, U8 *str, S32 len, S32 Bordered)
{
    MMI_BOOL ret = MMI_FALSE;
#ifdef __MTK_TARGET__
    mmi_eq_str_res_req_struct *rsp_msg;
#else
    U8 data_string[200];
#endif

    /* If having combined_chars, dump the string first */
    if (mmi_ucs2strlen(g_mmi_frm_cntx.dump_screen_info.combined_chars))
    {
    #ifdef __MTK_TARGET__
        rsp_msg = (mmi_eq_str_res_req_struct *)	OslConstructDataPtr( sizeof(mmi_eq_str_res_req_struct) );
        kal_sprintf((char*)rsp_msg->data_string, "%d,(%d,%d),%d,", 
                        1,  /* Normal string */
                        g_mmi_frm_cntx.dump_screen_info.combined_chars_x,
                        g_mmi_frm_cntx.dump_screen_info.combined_chars_y,
                        mmi_ucs2strlen(g_mmi_frm_cntx.dump_screen_info.combined_chars));

        rsp_msg->length = strlen((char*)rsp_msg->data_string);
        mmi_ucs2ncpy((S8*)(rsp_msg->data_string+rsp_msg->length), (S8*)g_mmi_frm_cntx.dump_screen_info.combined_chars, MMI_SCREEN_COMBINED_CHAR_MAX_LENGTH/ENCODING_LENGTH);
        rsp_msg->length += mmi_ucs2strlen(g_mmi_frm_cntx.dump_screen_info.combined_chars)*ENCODING_LENGTH;

        MMI_ASSERT(rsp_msg->length <= MMI_SCREEN_STR_MAX_LENGTH);
        SendMsg2AT(MSG_ID_MMI_EQ_STR_RES_REQ, (void *)rsp_msg, NULL);
    #else /* __MTK_TARGET__ */
        kal_sprintf((char*)data_string, "%d,(%d,%d),%d,", 
                        1,  /* Normal string */
                        g_mmi_frm_cntx.dump_screen_info.combined_chars_x,
                        g_mmi_frm_cntx.dump_screen_info.combined_chars_y,
                        mmi_ucs2strlen(g_mmi_frm_cntx.dump_screen_info.combined_chars));

    #ifdef ENABLE_DUMP_SCREEN_STRING_TRACE
        kal_printf(data_string);
        kal_printf("%c%c%c%c%c ...",g_mmi_frm_cntx.dump_screen_info.combined_chars[0], g_mmi_frm_cntx.dump_screen_info.combined_chars[2], 
                                    g_mmi_frm_cntx.dump_screen_info.combined_chars[4], g_mmi_frm_cntx.dump_screen_info.combined_chars[6],
                                    g_mmi_frm_cntx.dump_screen_info.combined_chars[8]);
        kal_printf(" ++++ \n");
    #endif /* ENABLE_DUMP_SCREEN_STRING_TRACE */
    #endif /* __MTK_TARGET__ */

    }

    /* Dump the screen string */
    if (g_mmi_frm_cntx.dump_screen_info.is_enable
        && (g_mmi_frm_cntx.dump_screen_info.allow_dump_screen_str
            || g_mmi_frm_cntx.dump_screen_info.allow_dump_dm_screen))
    {
        /* check if the string is the same */
        if (mmi_ucs2strlen((S8*)str) && 
            (mmi_ucs2cmp((S8*)str, g_mmi_frm_cntx.dump_screen_info.backup_string) != 0 || g_mmi_frm_cntx.dump_screen_info.y != y))
        {
            mmi_ucs2ncpy(g_mmi_frm_cntx.dump_screen_info.backup_string, (S8*)str, MMI_SCREEN_STR_MAX_LENGTH/ENCODING_LENGTH);
            g_mmi_frm_cntx.dump_screen_info.y = y;

            if (g_mmi_frm_cntx.dump_screen_info.backup_hightlight_type &&
                g_mmi_frm_cntx.dump_screen_info.backup_y == y)
            {
                g_mmi_frm_cntx.dump_screen_info.hightlight_type = g_mmi_frm_cntx.dump_screen_info.backup_hightlight_type;
            }
            /*
            else
            {
                g_mmi_frm_cntx.dump_screen_info.backup_y = 0;
                g_mmi_frm_cntx.dump_screen_info.hightlight_type = 0;
            }
            */
        #ifdef __MTK_TARGET__

            rsp_msg = (mmi_eq_str_res_req_struct *)	OslConstructDataPtr( sizeof(mmi_eq_str_res_req_struct) );
            kal_sprintf((char*)rsp_msg->data_string, "%d,(%d,%d),%d,", 
                            (g_mmi_frm_cntx.dump_screen_info.hightlight_type>0)?MMI_SCREEN_HIGHLIGHT_STR:MMI_SCREEN_NORMAL_STR,
                            x, 
                            y,
                            mmi_ucs2strlen(g_mmi_frm_cntx.dump_screen_info.backup_string));
            rsp_msg->length = strlen((char*)rsp_msg->data_string);
            mmi_ucs2cpy((S8*)(rsp_msg->data_string+rsp_msg->length), g_mmi_frm_cntx.dump_screen_info.backup_string);
            rsp_msg->length += mmi_ucs2strlen(g_mmi_frm_cntx.dump_screen_info.backup_string)*ENCODING_LENGTH;

            MMI_ASSERT(rsp_msg->length <= MMI_SCREEN_STR_MAX_LENGTH);
            SendMsg2AT(MSG_ID_MMI_EQ_STR_RES_REQ, (void *)rsp_msg, NULL);
        #else  /* __MTK_TARGET__ */
            kal_sprintf((char*)data_string, "%d,(%d,%d),%d,", 
                            (g_mmi_frm_cntx.dump_screen_info.hightlight_type>0)?MMI_SCREEN_HIGHLIGHT_STR:MMI_SCREEN_NORMAL_STR,
                            x, 
                            y,
                            mmi_ucs2strlen(g_mmi_frm_cntx.dump_screen_info.backup_string));

        #ifdef ENABLE_DUMP_SCREEN_STRING_TRACE
            kal_printf(data_string);
            kal_printf("%c%c%c%c%c ...",str[0], str[2], str[4], str[6], str[8]);
            kal_printf(" ++++ \n");
        #endif  /* ENABLE_DUMP_SCREEN_STRING_TRACE */
        #endif  /* __MTK_TARGET__ */
            if (g_mmi_frm_cntx.dump_screen_info.hightlight_type)
            {
                g_mmi_frm_cntx.dump_screen_info.backup_hightlight_type = g_mmi_frm_cntx.dump_screen_info.hightlight_type;
                g_mmi_frm_cntx.dump_screen_info.backup_y = y;
            }

            gui_cancel_timer(mmi_no_more_str_hdlr);
            gui_start_timer(MMI_STR_DUMP_TIMEOUT, mmi_no_more_str_hdlr);
            ret = MMI_TRUE;
        }
    }
    g_mmi_frm_cntx.dump_screen_info.hightlight_type = 0;

    if (mmi_ucs2strlen(g_mmi_frm_cntx.dump_screen_info.combined_chars))
    {
        memset(g_mmi_frm_cntx.dump_screen_info.combined_chars, 0, ENCODING_LENGTH);
        g_mmi_frm_cntx.dump_screen_info.combined_chars_x = 0;
        g_mmi_frm_cntx.dump_screen_info.combined_chars_y = 0;
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_trace_screen_char
 * DESCRIPTION
 *  Sending the screen char
 *  
 * PARAMETERS
 *  x           [IN]
 *  y           [IN]
 *  unicode     [IN]
 *  len         [IN]
 *  Bordered    [IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_trace_screen_char(S32 x, S32 y, U16 unicode, S32 len, S32 Bordered)
{
    MMI_BOOL ret = MMI_FALSE;
    
    if (g_mmi_frm_cntx.dump_screen_info.is_enable
        && (g_mmi_frm_cntx.dump_screen_info.allow_dump_screen_str
            || g_mmi_frm_cntx.dump_screen_info.allow_dump_dm_screen))
    {
    #ifdef __COMBINE_CHAR_IN_DUMP_SCREEN_STRING__
        U8 dummy;
        S32 len;

        /* combine the separated chars to the string */
        len = mmi_ucs2strlen(g_mmi_frm_cntx.dump_screen_info.combined_chars);
        if (g_mmi_frm_cntx.dump_screen_info.combined_chars_y == y)
        {
            /* chars are at The same column */
			if ((len + 1) < (MMI_SCREEN_COMBINED_CHAR_MAX_LENGTH/ENCODING_LENGTH))
			{
				mmi_wc_to_ucs2(
						unicode, 
						&dummy, 
						(U8*)g_mmi_frm_cntx.dump_screen_info.combined_chars + len * ENCODING_LENGTH);
				memset(g_mmi_frm_cntx.dump_screen_info.combined_chars + ((len + 1) * ENCODING_LENGTH),
					   0,
					   ENCODING_LENGTH);
			}
        }
        else
        {
            /* chars are not at The same column */
            if (len)
            {
                mmi_trace_screen_string(
                        g_mmi_frm_cntx.dump_screen_info.combined_chars_x,
                        g_mmi_frm_cntx.dump_screen_info.combined_chars_y,
                        (U8*)g_mmi_frm_cntx.dump_screen_info.combined_chars,
                        len,
                        0);
            }
            mmi_wc_to_ucs2(
                    unicode, 
                    &dummy, 
                    (U8*)g_mmi_frm_cntx.dump_screen_info.combined_chars);
            memset(g_mmi_frm_cntx.dump_screen_info.combined_chars + ENCODING_LENGTH,
                   0,
                   ENCODING_LENGTH);
            g_mmi_frm_cntx.dump_screen_info.combined_chars_x = x;
            g_mmi_frm_cntx.dump_screen_info.combined_chars_y = y;
        }
    #else
        /* Dump the separated chars directly */
        #ifdef __MTK_TARGET__
        {
            mmi_eq_str_res_req_struct *rsp_msg;

            rsp_msg = (mmi_eq_str_res_req_struct *)	OslConstructDataPtr( sizeof(mmi_eq_str_res_req_struct) );
            kal_sprintf((char*)rsp_msg->data_string, "%d,(%d,%d),1,", 0, x, y);
    
            rsp_msg->length = strlen((char*)rsp_msg->data_string);
            memcpy((S8*)(rsp_msg->data_string+rsp_msg->length), &unicode, ENCODING_LENGTH);
            rsp_msg->length += ENCODING_LENGTH;
    
            SendMsg2AT(MSG_ID_MMI_EQ_STR_RES_REQ, (void *)rsp_msg, NULL);
        }
        #else /* __MTK_TARGET__ */
        {
            U8 data_string[200];

            kal_sprintf((char*)data_string, "%d,(%d,%d),1,", 0, x, y);
        #ifdef ENABLE_DUMP_SCREEN_STRING_TRACE
            kal_printf(data_string);
            kal_printf(" %c ", unicode>>8);
            kal_printf(" %c ", unicode&0x00FF);
            kal_printf(" --- \n");
        #endif /* ENABLE_DUMP_SCREEN_STRING_TRACE */
        }
        #endif /* __MTK_TARGET__ */
    #endif
        gui_cancel_timer(mmi_no_more_str_hdlr);
        gui_start_timer(MMI_STR_DUMP_TIMEOUT, mmi_no_more_str_hdlr);
        ret = MMI_TRUE;
    }
    
    return ret;
}
#endif /* __MMI_SUPPORT_DUMP_SCREEN_STRING__ */


/**************************br************************************

   FUNCTION NAME     : ProtocolEventHandler(PRT_MESSAGE*)

   PURPOSE           : To handle protocol events.

   INPUT PARAMETERS  : U16 eventID

   OUTPUT PARAMETERS : nil

   RETURNS           : static void

   REMARKS           : This is used to handle protocol events .

**************************************************************/


/*****************************************************************************
 * FUNCTION
 *  ProtocolEventHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  eventID         [IN]        
 *  MsgStruct       [IN]         
 *  mod_src         [IN]        
 *  peerBuf         [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void ProtocolEventHandler(U16 eventID, void *MsgStruct, int mod_src, void *peerBuf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* PRINT_INFORMATION(("\n MMItask   -> protocol event <id %d>\n",eventID)); */
    PRINT_INFORMATION_2(MMI_FW_TRC_G1_FRM, "<<protocol event %d>>\n", eventID);
    ExecuteCurrProtocolHandler((U16) eventID, MsgStruct, mod_src, peerBuf);
}


/*****************************************************************************
 * FUNCTION
 *  InitUnicodeSupport
 * DESCRIPTION
 *  Initalizes string functions for UCS2 support
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitUnicodeSupport(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef MMI_FRM_BACKWARD_COMPATIBLE_STRING
    pfnUnicodeToEncodingScheme = mmi_wc_to_ucs2;
    pfnEncodingSchemeToUnicode = mmi_ucs2_to_wc;
    pfnUnicodeStrlen = mmi_ucs2strlen;
    pfnUnicodeStrcpy = mmi_ucs2cpy;
    pfnUnicodeStrcmp = mmi_ucs2cmp;
    pfnUnicodeStrncpy = mmi_ucs2ncpy;
    pfnUnicodeStrncmp = mmi_ucs2ncmp;
    pfnUnicodeStrcat = mmi_ucs2cat;
    pfnUnicodeStrncat = mmi_ucs2ncat;
#endif /* MMI_FRM_BACKWARD_COMPATIBLE_STRING */
}

/*****************************************************************************
 * FUNCTION
 *  InitAllApplications
 * DESCRIPTION
 *  Initialize all application which requires SIM to be present
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

void InitAllApplications(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* please see the detailed description in InitializeAll() */
    gInitAllAppFlag = 1;
    gInsertSimAppFlag = 0;
    MMI_APP_INIT(mmi_phb_sos_list_init());
    MMI_APP_INIT(initalize_main_menu_application());

    /* 
     * Initialize Setting application 
     */
    MMI_APP_INIT(InitSettingApp());

    /* 
     * init fun and game applcations 
     */
    MMI_APP_INIT(mmi_fng_init_app());

    /* 
     * Initialize phone book aplication 
     */
    MMI_APP_INIT(mmi_phb_init());


#ifdef __MOD_SMSAL__
        MMI_APP_INIT(InitMessagesApp());  /* sms-code */
    #ifdef __MMI_MESSAGES_CHAT__
            MMI_APP_INIT(InitializeChatApp());
    #endif
#endif /* __MOD_SMSAL__ */ 

#ifdef __MMI_DM_SELF_REGISTER_SUPPORT__
    MMI_APP_INIT(mmi_dm_sr_init());
#endif /* __MMI_DM_SELF_REGISTER_SUPPORT__ */

    MMI_APP_INIT(InitCallCost());
    MMI_APP_INIT(InitCallHistory());


#ifdef __MMI_WLAN_FEATURES__
    MMI_APP_INIT(mmi_wlan_post_init());
    MMI_APP_INIT(mmi_netset_init_wlan_setting());
#endif

#ifdef __MMI_VOIP__
    MMI_APP_INIT(mmi_voip_init());
#endif

#ifdef __MMI_POC__
    MMI_APP_INIT(mmi_poc_init());
#endif
#ifdef __MMI_EMAIL__
    MMI_APP_INIT(mmi_email_init());
#endif

    MMI_APP_INIT(OrgInit());
    MMI_APP_INIT(ExtraInit());
#if (defined(__MMI_VCARD__) || defined(__MMI_VCALENDAR__) || defined(__MMI_VBOOKMARK__))
    MMI_APP_INIT(mmi_vobj_init());   /* Initial after mmiapi */
#endif

#ifdef __MMI_VRSD__
    MMI_APP_INIT(mmi_vrsd_init());
#endif 
#ifdef __MMI_VRSI__
    MMI_APP_INIT(mmi_vrsi_init());
#endif 
#ifndef __MTK_TARGET__
    MMI_APP_INIT(mmi_vrsi_setting_init_simulator());
#endif
#ifdef __MMI_IMPS__
    MMI_APP_INIT(mmi_imps_init());
#endif 
#ifdef __MMI_DOWNLOAD_AGENT__
    MMI_APP_INIT(mmi_da_init_app());
#endif
#ifdef __MMI_EBOOK_READER__
    MMI_APP_INIT(InitEbookApp());
#endif 
#ifdef __SYNCML_SUPPORT__
    MMI_APP_INIT(mmi_syncml_init());
#endif

#ifdef __MMI_CCA_SUPPORT__
    MMI_APP_INIT(mmi_cca_init());
#endif

#ifdef __MMI_MExE_SUPPORT__
    MMI_APP_INIT(mmi_mexe_init());
#endif

#ifdef SYNCML_DM_SUPPORT
    MMI_APP_INIT(mmi_dmui_init());
#endif /* SYNCML_DM_SUPPORT */

#ifdef __MMI_MOBILE_SERVICE__
    MMI_APP_INIT(mmi_optrser_init());
#endif

#ifdef __MMI_CUSTOMER_SERVICE__
    MMI_APP_INIT(mmi_custser_init());
#endif

#ifdef __VOIP__
    MMI_APP_INIT(em_voip_log_init());
#endif /*  __VOIP__ */



    /* 
     * Note: all applications shall be initialized before shortcut
     */
#ifndef __DISABLE_SHORTCUTS_IMPL__
    MMI_APP_INIT(ShctInit());
#endif 

#ifdef __MMI_MMS_BGSR_SUPPORT__
    MMI_APP_INIT(mmi_mms_bgsr_init());
#endif /*__MMI_MMS_BGSR_SUPPORT__*/
#ifdef __CMS_WAP__//05.10.18 pan add for wap&mms
#ifdef MMI_ON_HARDWARE_P
	init_cms_mms_app();
#endif
#endif



}


/*****************************************************************************
 * FUNCTION
 *  InitInsertSimApp
 * DESCRIPTION
 *  Initialize few applications which do not require SIM to be present
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitInsertSimApp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* please see the detailed description in InitializeAll() */
    gInsertSimAppFlag = 1;
    DinitSubLCDHistory();


    /* diamond, 2006/03/31 Not re-init these applications if no sim indication is sent after successful power on with sim */
    if (!gInitAllAppFlag)
    {
        MMI_APP_INIT(initalize_main_menu_application());
        MMI_APP_INIT(mmi_fng_init_app());
        MMI_APP_INIT(mmi_phb_init());
        MMI_APP_INIT(OrgInit());
        MMI_APP_INIT(ExtraInit());
        MMI_APP_INIT(InitSettingApp());   /* diamond, 2005/12/23 Phone setup in option menu */

#ifdef __VOIP__
        MMI_APP_INIT(em_voip_log_init());
#endif /*  __VOIP__ */

    #if (defined(__MMI_VCARD__) || defined(__MMI_VCALENDAR__) || defined(__MMI_VBOOKMARK__))
        MMI_APP_INIT(mmi_vobj_init());    /* Initial after mmiapi */
    #endif

    #ifdef __MMI_DOWNLOAD_AGENT__
         MMI_APP_INIT(mmi_da_init_app());
    #endif

#ifdef __MMI_WLAN_FEATURES__
        MMI_APP_INIT(mmi_wlan_post_init());
        MMI_APP_INIT(mmi_netset_init_wlan_setting());
    #ifdef __MMI_VOIP__
        MMI_APP_INIT(mmi_voip_init());
        MMI_APP_INIT(InitCallHistory());
    #endif
    #ifdef __MMI_POC__
        MMI_APP_INIT(mmi_poc_init());
    #endif
    #ifdef __MMI_EMAIL__
        MMI_APP_INIT(mmi_email_init());
    #endif
    #ifdef __MMI_IMPS__
        MMI_APP_INIT(mmi_imps_init());
    #endif
    #ifdef __SYNCML_SUPPORT__
        MMI_APP_INIT(mmi_syncml_init());
    #endif
#else /* __MMI_WLAN_FEATURES__ */
    #ifdef __SYNCML_SUPPORT__
        MMI_APP_INIT(mmi_syncml_read_settings_from_nvram());
    #endif
#endif /* __MMI_WLAN_FEATURES__ */
    /* AlarmInitNvRam(); */
    }


    /* 
     * Note: all applications shall be initialized before shortcut
     */
#ifndef __DISABLE_SHORTCUTS_IMPL__
    MMI_APP_INIT(ShctInit());
#endif

    gInitAllAppFlag = 1;
}


/*****************************************************************************
 * FUNCTION
 *  InitNvramData
 * DESCRIPTION
 *  Allows the applications to read their NVRAM data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitNvramData(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* make sure the cache buffer is large enough */
    MMI_ASSERT((NVRAM_LAST_BYTE_ELEMENT*DS_BYTE) <= NVRAM_CACHE_SIZE);
    MMI_ASSERT((NVRAM_LAST_SHORT_ELEMENT*DS_SHORT) <= NVRAM_CACHE_SIZE);
    MMI_ASSERT((NVRAM_LAST_DOUBLE_ELEMENT*DS_DOUBLE) <= NVRAM_CACHE_SIZE);
        
    MMI_APP_INIT(InitDownloadNVRAM());
#ifdef __MMI_PROFILE_EXTMELODY_SUPPORT__
    MMI_APP_INIT(PmgInitExtMelodyStruct());
#endif 
    /* __USB_IN_NORMAL_MODE__ */
    MMI_APP_INIT(PhnsetReadWallpaper());

    MMI_APP_INIT(PhnsetReadGPIOSetting());
#if defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__)
    MMI_APP_INIT(PhnsetReadIdleClockType());
#endif 
#ifdef __MMI_POWER_ON_OFF_DISPLAY__
    MMI_APP_INIT(PhnsetReadPwrOnOffDisp());
#endif 
    /* __USB_IN_NORMAL_MODE__ */

#ifdef __MMI_AVATAR__
    MMI_APP_INIT(mmi_avatar_init());
#endif

#ifdef __MMI_THEMES_V2_SUPPORT__
    MMI_APP_INIT(mmi_theme_manager_init());
#endif 
    MMI_APP_INIT(PhnsetInitSetTimeNDateNvram());
    MMI_APP_INIT(PhnsetReadNvramScrSvrSettings());
    MMI_APP_INIT(InitNvramCallerId());
#ifdef __IP_NUMBER__
    MMI_APP_INIT(LoadIPNumbers());
#endif 
    /*
     * Call Management:load black list
     */
#ifdef __MMI_CM_BLACK_LIST__
    MMI_APP_INIT(LoadBlackListNum());
#endif 

    MMI_APP_INIT(initnvramprofapp());
    MMI_APP_INIT(InitSettingNVRAM());
    MMI_APP_INIT(ReadValueCityNVRAM());
    /*
     * MAX: for new alarm
     */
    MMI_APP_INIT(InitAlarmFrameWork());

#if defined(__MMI_THEMES_APPLICATION__)
    MMI_APP_INIT(InitThemes());
#endif

    MMI_APP_INIT(SetModeSpeechVolume());

#ifdef __MOD_SMSAL__
    MMI_APP_INIT(InitCBNVRAMData());
    #ifdef __MMI_MESSAGES_TEMPLATE__
    MMI_APP_INIT(InitTemplates());
    #endif
#endif /* __MOD_SMSAL__ */ 

#if defined(__MMI_RING_COMPOSER__) && defined(__MMI_IMELODY_SUPPORT__)
    MMI_APP_INIT(InitRingToneComposer());
#endif

#ifdef __MMI_STOPWATCH__
    MMI_APP_INIT(InitStopwatchNVRAM());
#endif

#ifdef __MMI_IMPS__
    MMI_APP_INIT(mmi_imps_init_nvram());
#endif

#ifdef __MMI_USER_CTRL_PLMN_SUPPORT__
    MMI_APP_INIT(mmi_netset_init_user_ctrl_plmn());
#endif 
}



/*****************************************************************************
* Local Function                                                              
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  InitEventHandlersBeforePowerOn
 * DESCRIPTION
 *  Init event handlers before power on indication
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void InitEventHandlersBeforePowerOn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    InitEvents();
    InitKeypadBeforePWRON();
    SetProtocolEventHandler(GpioDetectInd, MSG_ID_MMI_EQ_GPIO_DETECT_IND);
    SetProtocolEventHandler(BatteryStatusRsp, MSG_ID_MMI_EQ_BATTERY_STATUS_IND);
#ifdef __MMI_USB_SUPPORT__
    SetProtocolEventHandler(UsbDetectIndHdlr, PRT_EQ_USB_DETECT_IND);
#endif 
    InitAlarmHandler();

#ifdef __MMI_TVOUT__
    /* init tvout, since TV-out indication will come before poweron indication */
    mmi_phnset_early_init_tvout_before_pwron();
#endif    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_check_is_valid_msg
 * DESCRIPTION
 *  Check if the follow message is useful
 *  If the successive messages are MSG_ID_TIMER_EXPIRY,
 *  only one message will be usegful. We will keep only one
 *  MSG_ID_TIMER_EXPIRY in the queue
 * PARAMETERS
 *  base        [IN]     
 *  msg         [IN]     
 * RETURNS
 *  0 - the message is invalid, and discard the message
 *  1 - the message is vaild
 *****************************************************************************/
static U8 mmi_frm_check_is_valid_msg(MYQUEUE *base, MYQUEUE *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((base != NULL) && (msg != NULL) && (base->msg_id == msg->msg_id))
    {
        switch (base->msg_id)
        {
            case MSG_ID_TIMER_EXPIRY:
            {
                kal_uint16 msg_len = 0;
                stack_timer_struct *base_timer_ptr;
                stack_timer_struct *timer_ptr;

                base_timer_ptr = (stack_timer_struct*) get_local_para_ptr(base->oslDataPtr, &msg_len);
                timer_ptr = (stack_timer_struct*) get_local_para_ptr(msg->oslDataPtr, &msg_len);
                if (base_timer_ptr == timer_ptr)
                {
                    stack_is_time_out_valid(base_timer_ptr);
                    stack_process_time_out(base_timer_ptr);
                    /* msg is invalid, can discard it */
                    return 0;
                }
            }
                break;

            default:
                break;
        }
    }
    /* msg is valid, can't discard */
    return 1;
}


/* __CUSTPACK_MULTIBIN     Terry   BEGIN */

/*****************************************************************************
 * FUNCTION
 *  ime_check_input_type
 * DESCRIPTION
 *  To check if the specified input type is supported
 * PARAMETERS
 *  input_type  [IN] the specified input type
 * RETURNS
 *  MMI_TRUE    the specified input type is supported
 *  MMI_FALSE   the specified input type is not supported
 *****************************************************************************/
BOOL ime_check_input_type(S16 input_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0; /* index */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (gIMEModeArray[i].IME_Mode_ID != (0xff))
    {
        if (input_type == gIMEModeArray[i].IME_Type_ID)
        {
            return TRUE;
        }
        i ++;
    }

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  IMECheck
 * DESCRIPTION
 *  To Check IME,
 *  
 *  This is used to To Check IME,.
 * PARAMETERS
 *  IME_Mode                [IN]        
 *  all_implement_IME       [IN]        
 * RETURNS
 *  MMI_TRUE : if the IME_Mode is in
 *  MMI_FALSE : if the IME_Mode is not in
 *****************************************************************************/
static BOOL IMECheck(U8 IME_Mode, const U8 all_implement_IME[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (;;)
    {
        if ((0xff) != all_implement_IME[i])
        {
            if (IME_Mode == all_implement_IME[i])
            {
                return MMI_TRUE;
            }
        }
        else
        {
            return MMI_FALSE;
        }
        i++;
        if (i > INPUT_MODE_MAX_NUM)
        {
            ASSERT(0);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  InitIMESetting
 * DESCRIPTION
 *  To Initialize IME,
 *  
 *  This is used to To Initialize IME,.
 * PARAMETERS
 *  IMEArray            [IN]        
 *  allIME              [OUT]       
 *  englishOnlyIME      [OUT]       
 *  PreferedIME         [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
static void InitIMESetting(const sIMEModeDetails *IMEArray, U8 *allIME, U8 *englishOnlyIME, U16 *PreferedIME)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0, j = 0;
#ifdef __MMI_PREFER_INPUT_METHOD__    
    int k = 0;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (;;)
    {
        if ((0xff) != IMEArray[i].IME_Mode_ID)
        {
            /* W05.34 Fix Compile Warning */
            if (!IMECheck((U8) IMEArray[i].IME_Mode_ID, MMI_implement_input_mode_set))
            {
                ASSERT(0);
            }
            allIME[i] = IMEArray[i].IME_Mode_ID;
        #ifdef __MMI_PREFER_INPUT_METHOD__
            if ((NULL != PreferedIME) && (0 != IMEArray[i].IME_Type_ID))
            {
                PreferedIME[k] = IMEArray[i].IME_Type_ID;
                k++;
            }
        #endif /* __MMI_PREFER_INPUT_METHOD__ */ 
            if (IME_IS_ENGLISH_ONLY(IMEArray[i].Lang_Special_Attrib))
            {
                englishOnlyIME[j] = IMEArray[i].IME_Mode_ID;
                j++;
            }
            i++;
        }
        else
        {
            break;
        }
        if (i > INPUT_MODE_MAX_NUM)
        {
            ASSERT(0);
        }
    }
    allIME[i] = 0xff;
#if defined(__MMI_PREFER_INPUT_METHOD__)
    PreferedIME[k] = 0xffff;
#endif /* defined(__MMI_PREFER_INPUT_METHOD__) */
    englishOnlyIME[j] = 0xff;
}


/*****************************************************************************
 * FUNCTION
 *  InitIMEQSearch
 * DESCRIPTION
 *  To Initialize IME,
 *  
 *  This is used to To Initialize IME,.
 * PARAMETERS
 *  IMEQArray       [IN]        
 *  QuickIME        [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
static void InitIMEQSearch(const sIMEModeDetails *IMEQArray, U8 *QuickIME)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0, j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (;;)
    {
        if ((0xff) != IMEQArray[i].IME_Mode_ID)
        {
            i++;
            QuickIME[j] = IMEQArray[i - 1].IME_Mode_ID;
            j++;
        }
        else
        {
            break;
        }
        if (i > INPUT_MODE_MAX_NUM)
        {
            ASSERT(0);
        }
    }
    QuickIME[j] = 0xff;
}

#if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
extern U16 gMaxDeployedLangs;
extern sLanguageDetails *gLanguageArray;
extern S16 MMI_prefered_input_type;
/*****************************************************************************
 * FUNCTION
 *  ime_init_get_writing_lang_str
 * DESCRIPTION
 *  To init  
 * PARAMETERS
 *  void
 * RETURNS
 *  UI_string_type
 *****************************************************************************/
UI_string_type ime_init_get_writing_lang_str(UI_string_type lang_country_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                               */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < gMaxDeployedLangs; i++)
    {
        if (strcmp((S8*)lang_country_code, (S8*)gLanguageArray[i].aLangCountryCode) == 0)
        {
            return (UI_string_type)gLanguageArray[i].aName;
        }
    }
    return NULL;

}

/*****************************************************************************
 * FUNCTION
 *  ime_init_support_lang
 * DESCRIPTION
 *  To init  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ime_init_support_lang(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                               */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    S32 j = 0;
    S32 total = 0;
    U16 value;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                                      */
    /*----------------------------------------------------------------*/
    while((0xff) != gIMEModeArray[i].IME_Mode_ID)
    {
        /* Search g_ime_writing_lang_array to check if the input method belong to a new lang */
        for( j = 0; j < total; j++)
        {
            if (g_ime_writing_lang_array[j].lang_id == gIMEModeArray[i].lang_id) break;                
        }

        if (j < total)
        {
            /* the input method belong to a existed lang in g_ime_writing_lang_array */
            if (IME_IS_MIXED_LANG_SUPPORT(gIMEModeArray[i].Lang_Special_Attrib))
            {
                g_ime_writing_lang_array[j].mixed_lang_support = MMI_TRUE; 
            }            
        }
        else
        {
            if (gIMEModeArray[i].lang_id != IME_WRITING_LANG_NONE && gIMEModeArray[i].lang_id != IME_WRITING_LANG_123)
            {
            /* the input method belong to a new lang to g_ime_writing_lang_array */
                g_ime_writing_lang_array[j].default_input_mode = gIMEModeArray[i].IME_Mode_ID;
                g_ime_writing_lang_array[j].lang_id = gIMEModeArray[i].lang_id;
                g_ime_writing_lang_array[j].lang_str_ptr = ime_init_get_writing_lang_str((UI_string_type)gIMEModeArray[i].aLangCountryCode);
                g_ime_writing_lang_array[j].mixed_lang_support = MMI_FALSE;
                if (IME_IS_MIXED_LANG_SUPPORT(gIMEModeArray[i].Lang_Special_Attrib))
                {
                    g_ime_writing_lang_array[j].mixed_lang_support = MMI_TRUE; 
                }
                total++;
            }
        }
        i++;

        MMI_ASSERT(total <= (MAX_WRITING_LANG - 2));
    }
    /* 123... */
    g_ime_writing_lang_array[total].default_input_mode = INPUT_MODE_123;
    g_ime_writing_lang_array[total].lang_id = IME_WRITING_LANG_123;
    g_ime_writing_lang_array[total].lang_str_ptr = (UI_string_type)GetString(STR_ID_IME_WRITING_LANGUAGE_123);
    g_ime_writing_lang_array[total].mixed_lang_support = MMI_FALSE;
    total++;
    /* None */
    g_ime_writing_lang_array[total].default_input_mode = INPUT_MODE_MAX_NUM;
    g_ime_writing_lang_array[total].lang_id = IME_WRITING_LANG_NONE;
    g_ime_writing_lang_array[total].mixed_lang_support = MMI_TRUE;
    g_ime_writing_lang_array[total].lang_str_ptr = (UI_string_type)GetString(STR_ID_IMG_WRITING_LANGUAGE_NONE);

    value = 0xFFFF;
    ReadValue(NVRAM_SETTING_WRITING_LANG, &value, DS_SHORT, &error);
    g_ime_main_writing_lang = ((value == 0xFFFF) ? IME_WRITING_LANG_ABC : (S16)value);
    
#if defined(__MMI_MIXED_LANG_SUPPORT__)
    value = 0xFFFF;
    ReadValue(NVRAM_SETTING_WRITING_LANG_SUB, &value, DS_SHORT, &error);
    g_ime_sub_writing_lang = ((value == 0xFFFF) ? IME_WRITING_LANG_NONE : (S16)value);
#endif

#if defined(__MMI_PREFER_INPUT_METHOD__) || defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
    value = 0xFFFF;
    ReadValue(NVRAM_SETTING_PREFER_INPUT_METHOD, &value, DS_SHORT, &error);
    if(value != 0xFFFF)
        MMI_prefered_input_type = (S16)value;
    

    i = 0;
    while((0xff) != gIMEModeArray[i].IME_Mode_ID)
    {
        if (gIMEModeArray[i].lang_id == g_ime_main_writing_lang)
            break;
        i ++;
    }
    /* To check if the MMI_prefered_input_type read from NVRAM is supported or not */
    if ((!ime_check_input_type(MMI_prefered_input_type)) ||
        (MMI_prefered_input_type != gIMEModeArray[i].IME_Type_ID))
    {
        MMI_prefered_input_type = gIMEModeArray[i].IME_Type_ID;
    }
#endif    
}
#endif /* defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__) */


/*****************************************************************************
 * FUNCTION
 *  InitIME
 * DESCRIPTION
 *  To Initialize IME,
 *  
 *  This is used to To Initialize IME,.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void InitIME(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // #if defined(__MMI_MULTIPLE_BIN_IME__)||defined(__MMI_MULTIPLE_BIN_LANG_PACK__)
#ifdef __MMI_PREFER_INPUT_METHOD__
    InitIMESetting(gIMEModeArray, MMI_all_input_mode_set, MMI_english_input_mode_set, MMI_all_prefered_input_mode_set);
#else 
    InitIMESetting(gIMEModeArray, MMI_all_input_mode_set, MMI_english_input_mode_set, NULL);
#endif 
    InitIMEQSearch(gIMEQSearchModeArray, MMI_qsearch_input_mode_set);
    // #endif
#if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
    ime_init_support_lang();
#endif

#ifdef __MMI_T9__
    InitInputMethod();
#elif defined __MMI_ZI__
    InitZiInputMethod();
#elif defined __MMI_CSTAR__
    InitCstarInputMethod();
#elif defined __MMI_KA__
    InitKonkaInputMethod();
#elif defined __MMI_ITAP__
/* under construction !*/
#endif 
}

/* __CUSTPACK_MULTIBIN     Terry   END */


/*****************************************************************************
 * FUNCTION
 *  mmi_enable_str_dump
 * DESCRIPTION
 *  The message handler of MSG_ID_MMI_EQ_STR_ENABLE_REQ_IND
 *  
 * PARAMETERS
 *  void*           [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_enable_str_dump(void *info)
{
#ifdef __MTK_TARGET__
    mmi_eq_str_enable_req_ind_struct *data = (mmi_eq_str_enable_req_ind_struct *)info;
    mmi_at_general_res_req_struct *rsp_msg;
#ifndef __MMI_SUPPORT_DUMP_SCREEN_STRING__
    kal_bool ret = KAL_FALSE;
#else
    kal_bool ret = KAL_TRUE;
    
    g_mmi_frm_cntx.dump_screen_info.is_enable = (MMI_BOOL)(data->enable);
    g_mmi_frm_cntx.dump_screen_info.hightlight_type = 0;
    g_mmi_frm_cntx.dump_screen_info.backup_hightlight_type = 0;
    g_mmi_frm_cntx.dump_screen_info.y = 0;
    g_mmi_frm_cntx.dump_screen_info.backup_y = 0;
    g_mmi_frm_cntx.dump_screen_info.combined_chars_x = 0;
    g_mmi_frm_cntx.dump_screen_info.combined_chars_y = 0;
    memset(g_mmi_frm_cntx.dump_screen_info.backup_string, 0, MMI_SCREEN_STR_MAX_LENGTH);
#endif
    
    /* confirm the message */
    rsp_msg = (mmi_at_general_res_req_struct *)	OslConstructDataPtr( sizeof(mmi_at_general_res_req_struct) );
    rsp_msg->result = ret;
    SendMsg2AT(MSG_ID_MMI_AT_GENERAL_RES_REQ, (void *)rsp_msg, NULL);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_str_cmd_ind
 * DESCRIPTION
 *  The message handler of MSG_ID_MMI_EQ_STR_REQ_IND
 *  
 * PARAMETERS
 *  void*           [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_str_cmd_ind(void *info)
{
#ifdef __MTK_TARGET__
    mmi_eq_str_req_ind_struct *data = (mmi_eq_str_req_ind_struct *)info;
    mmi_at_general_res_req_struct *rsp_msg;

    MMI_ASSERT(data->length <= MMI_SCREEN_STR_MAX_LENGTH);
    /* process the string command here */

    /* confirm the message */
    rsp_msg = (mmi_at_general_res_req_struct *)	OslConstructDataPtr( sizeof(mmi_at_general_res_req_struct) );
    rsp_msg->result = KAL_TRUE;
    SendMsg2AT(MSG_ID_MMI_AT_GENERAL_RES_REQ, (void *)rsp_msg, NULL);
#endif
}


#ifdef __MMI_SUPPORT_DUMP_SCREEN_STRING__

/*****************************************************************************
 * FUNCTION
 *  mmi_no_more_str_hdlr
 * DESCRIPTION
 *  Sending the termination of dumpping screen string
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_no_more_str_hdlr(void)
{
    mmi_eq_str_res_req_struct *rsp_msg;

    if (mmi_ucs2strlen(g_mmi_frm_cntx.dump_screen_info.combined_chars))
    {
        mmi_trace_screen_string(
                g_mmi_frm_cntx.dump_screen_info.combined_chars_x,
                g_mmi_frm_cntx.dump_screen_info.combined_chars_y,
                (U8*)g_mmi_frm_cntx.dump_screen_info.combined_chars,
                mmi_ucs2strlen(g_mmi_frm_cntx.dump_screen_info.combined_chars),
                0);
    }
    memset(g_mmi_frm_cntx.dump_screen_info.combined_chars, 0, ENCODING_LENGTH);
    g_mmi_frm_cntx.dump_screen_info.allow_dump_screen_str = MMI_FALSE;
    g_mmi_frm_cntx.dump_screen_info.hightlight_type = 0;
    g_mmi_frm_cntx.dump_screen_info.backup_hightlight_type = 0;
    g_mmi_frm_cntx.dump_screen_info.y = 0;
    g_mmi_frm_cntx.dump_screen_info.backup_y = 0;
    g_mmi_frm_cntx.dump_screen_info.combined_chars_x = 0;
    g_mmi_frm_cntx.dump_screen_info.combined_chars_y = 0;
#ifdef __MTK_TARGET__
    rsp_msg = (mmi_eq_str_res_req_struct *)	OslConstructDataPtr( sizeof(mmi_eq_str_res_req_struct) );
    kal_sprintf((char*)rsp_msg->data_string, "%d", MMI_SCREEN_NO_STR);
    rsp_msg->length = strlen((char*)rsp_msg->data_string);
    SendMsg2AT(MSG_ID_MMI_EQ_STR_RES_REQ, (void *)rsp_msg, NULL);
#else /* __MTK_TARGET__ */
#ifdef ENABLE_DUMP_SCREEN_STRING_TRACE
    kal_printf("\n <<END>> \n");
#endif
#endif /* __MTK_TARGET__ */
}

#endif /* __MMI_SUPPORT_DUMP_SCREEN_STRING__ */



#if defined(HORSERACE_SUPPORT)
//Huyanwei Add It 
extern void Init_HorseRaceData(void);
extern void SendMessagesMMIToTwo(msg_type MSG_ID );
#endif

#if defined(G_SENSOR_SUPPORT)
//Huyanwei Add It 
extern void Init_GSensorData(void);
#endif



/*****************************************************************************
 * FUNCTION
 *  InitializeAll
 * DESCRIPTION
 *  This is used to initialize framework
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void InitializeAll()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*
     * Currectly, there are three functions which allow to add init functions because not every application needs to be initialized if the SIM is not present..
     * 1. InitializeAll
     * 2. InitAllApplications
     * 3. InitInsertSimApp

     * Here are the steps to show when these three functions are called..
     * 1. Power on the handset..
     * 2. InitializeAll() is called..
     * 3. Start to play power on animation..
     * 4. SIM is present or not present notification to MMI..
     * 5. Stop playing power on animation..
     * 6. If SIM is present, InitAllApplications() is called. If SIM is not present, InitInsertSimApp() is called..
  
     * There is a simple rule of where to add your initialization function..
     * If your application always works no matter SIM is present or not, please add it in InitializeAll()..
     * If your application is SIM-dependent, please add it in InitAllApplications() or InitInsertSimApp()..
     */

    MMI_APP_INIT(InitUnicodeSupport());

    /* 
     * Init graphic lib 
     */
    MMI_APP_INIT(gdi_init());
    /* 
     * Init media driver lib 
     */
    MMI_APP_INIT(mdi_audio_init());


#ifdef __MMI_WEBCAM__
    MMI_APP_INIT(mdi_webcam_init());
#endif 

#ifdef __MMI_USB_SUPPORT__
    MMI_APP_INIT(InitMMIUsbContext());
#endif /* __MMI_USB_SUPPORT__ */ 

#ifdef __MMI_IRDA_SUPPORT__
    MMI_APP_INIT(mmi_irda_init_cntx());
    MMI_APP_INIT(mmi_irda_set_recv_files_cnt(0));
#endif /* __MMI_IRDA_SUPPORT__ */ 

    /* 
     * Initialize the ProtocolEvents 
     */
    MMI_APP_INIT(InitProtocolEvents());
    /* 
     * Initialize framework 
     */
    MMI_APP_INIT(InitFramework());
    MMI_APP_INIT(InitHardwareEvents());
    MMI_APP_INIT(InitTime());
    MMI_APP_INIT(InitMMI_App());
    MMI_APP_INIT(setup_UI_wrappers());
    MMI_APP_INIT(PopulateResData());
    MMI_APP_INIT(PowerAndEndKeyHandler());

#ifdef __MMI_UNIFIED_MESSAGE__
    MMI_APP_INIT(mmi_um_init());
#endif 

#ifdef __MMI_UNIFIED_COMPOSER__
    MMI_APP_INIT(mmi_uc_init());
#endif 

#ifdef __CERTMAN_SUPPORT__
	MMI_APP_INIT(mmi_certman_init());
#endif /*__CERTMAN_SUPPORT__ */

#ifdef __MMI_MMS_2__
	MMI_APP_INIT(mmi_umms_mem_init());
	MMI_APP_INIT(mmi_umms_init());
	MMI_APP_INIT(mmi_jsr_init());
	MMI_APP_INIT(mmi_mv_init_mms_viewer_at_bootup());
#endif

#ifndef __MMI_DUAL_SIM_DUAL_CALL_SLAVE__
#ifdef __MOD_SMSAL__
    MMI_APP_INIT(InitMessageProtocolEventHandlers());
    MMI_APP_INIT(mmi_frm_sms_init());
#endif /* __MOD_SMSAL__ */ 
#endif	/* __MMI_DUAL_SIM_DUAL_CALL_SLAVE__ */


    /* 
     * Data Account Application 
     */
#ifdef __TCPIP__
    MMI_APP_INIT(InitDataAccountApp());
#endif

    /* 
     * Call manahement needs to be initialized here because of SOS calls concept
     */
#ifndef __MMI_DUAL_SIM_DUAL_CALL_SLAVE__
    MMI_APP_INIT(InitCallManagement());
#endif /* __MMI_DUAL_SIM_DUAL_CALL_SLAVE__ */

#ifdef __MMI_VIDEO_TELEPHONY__
    MMI_APP_INIT(mmi_vt_init());
#endif /* __MMI_VIDEO_TELEPHONY__ */

#ifdef __MMI_UCM__
    MMI_APP_INIT(mmi_ucm_init());
#endif
    MMI_APP_INIT(initialize_UI_demo());
    MMI_APP_INIT(InitNetWorkBootUpEventsCallBack());
    MMI_APP_INIT(InitProfileApp());
    MMI_APP_INIT(InitSimDetection());
    MMI_APP_INIT(InitService());
    MMI_APP_INIT(InitCPHS());

    /* 
     * For engineer mode
     */
#ifdef __MMI_ENGINEER_MODE__    /* For saperate MMI feature by project */
    MMI_APP_INIT(InitEngineerMode());
#endif

#ifdef __MMI_FACTORY_MODE__     /* For saperate MMI feature by project */
    MMI_APP_INIT(InitFactoryMode());
#endif

#ifdef __MMI_FILE_MANAGER__
    MMI_APP_INIT(mmi_fmgr_init());
#endif

#ifdef __MMI_MY_FAVORITE__
    MMI_APP_INIT(mmi_my_favorite_init());
#endif

#ifdef __MMI_SOUND_RECORDER__
    MMI_APP_INIT(InitSoundRecorderApp());
#endif

    MMI_APP_INIT(InitSoundEffect());
    MMI_APP_INIT(mdi_audio_init_event_hdlrs());
    /* 
     * To initialize T9 before power on for To Do List
     */
    MMI_APP_INIT(InitIME());

    /* 
     * Max: To add backlight on/off interface for HW test 0925
     */
    MMI_APP_INIT(InitHWBacklightTest());

    MMI_APP_INIT(InitCallLogs());
    MMI_APP_INIT(ATHandlerInit());
    MMI_APP_INIT(mmi_chset_init());

    /*
     * Phonebook Protocol Initialization - Should be initialized before L4 PHB begin to read
     */
#ifndef __MMI_DUAL_SIM_DUAL_CALL_SLAVE__
    MMI_APP_INIT(mmi_phb_init_protocol());
#endif	/* __MMI_DUAL_SIM_DUAL_CALL_SLAVE__ */
    /* 
     * Move from InitSettingApp() for text encoding 
     */
    MMI_APP_INIT(InitPhoneSetupCntx());
    MMI_APP_INIT(InitPhoneSetupApp());


#ifdef __MMI_BT_SUPPORT__
    MMI_APP_INIT(mmi_bt_init());
#endif
    
#ifdef __MMI_IRDA_SUPPORT__
    MMI_APP_INIT(mmi_irda_init_menu_hdlr());
#endif

#if defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)
    MMI_APP_INIT(mmi_nsm2_init_nsm_msg_struct(&g_nsm_msg_context));
#endif

#if defined(__MMI_FM_RADIO_SCHEDULE_REC__)
    MMI_APP_INIT(mmi_fmsr_init_app());
#endif 

#ifdef __MMI_BG_SOUND_EFFECT__
    MMI_APP_INIT(mmi_bgsnd_init());
#endif 

    MMI_APP_INIT(mmiapi_init_engine());

#ifdef OBIGO_Q05A
    MMI_APP_INIT(wap_task_init());
#endif
#if defined(JATAAYU_SUPPORT) && !defined(__MTK_TARGET__)
    {
        ilm_struct *ilm_ptr = NULL;

        ilm_ptr = allocate_ilm(MOD_MMI);
        ilm_ptr->local_para_ptr = NULL;
        ilm_ptr->msg_id = MSG_ID_MMI_EQ_POWER_ON_IND;
        ilm_ptr->peer_buff_ptr = NULL;

        ilm_ptr->src_mod_id = MOD_MMI;
        ilm_ptr->dest_mod_id = MOD_WAP;
        ilm_ptr->sap_id = WPS_APP_SAP;
        msg_send_ext_queue(ilm_ptr);
    }
#endif /* defined(JATAAYU_SUPPORT) && !defined(__MTK_TARGET__) */ 

#if defined(__MMI_NITZ__)
    MMI_APP_INIT(NITZHandlerInit());
#endif 

#if defined(__FOTA_ENABLE__)
    MMI_APP_INIT(mmi_dm_fwu_init());
#endif /* defined(__FOTA_ENABLE__) */

	SetProtocolEventHandler(mmi_enable_str_dump, MSG_ID_MMI_EQ_STR_ENABLE_REQ_IND);
	SetProtocolEventHandler(mmi_str_cmd_ind, MSG_ID_MMI_EQ_STR_REQ_IND);

#ifdef __MMI_SWFLASH__
    MMI_APP_INIT(mmi_swflash_init_app());
#endif

#ifdef __MMI_PICT_BRIDGE_SUPPORT__
    MMI_APP_INIT(mmi_pict_init());
#endif

#ifdef __MMI_LANGLN__
    MMI_APP_INIT(mmi_langln_init());
#endif

#ifdef __MMI_SUPPORT_DUMP_SCREEN_STRING__
#if !defined(__MTK_TARGET__)
    g_mmi_frm_cntx.dump_screen_info.is_enable = (MMI_BOOL)0;
    g_mmi_frm_cntx.dump_screen_info.hightlight_type = 0;
    g_mmi_frm_cntx.dump_screen_info.backup_hightlight_type = 0;
    g_mmi_frm_cntx.dump_screen_info.y = 0;
    g_mmi_frm_cntx.dump_screen_info.backup_y = 0;
    g_mmi_frm_cntx.dump_screen_info.combined_chars_x = 0;
    g_mmi_frm_cntx.dump_screen_info.combined_chars_y = 0;
    memset(g_mmi_frm_cntx.dump_screen_info.backup_string, 0, MMI_SCREEN_STR_MAX_LENGTH);
#endif
#endif /* __MMI_SUPPORT_DUMP_SCREEN_STRING__ */

#ifdef __MMI_RMGR__
    MMI_APP_INIT(mmi_rmgr_init());
#endif

#ifdef __DRM_SUPPORT__
    MMI_APP_INIT(mmi_drm_init());
#endif

#ifdef __MMI_UCM__
    MMI_APP_INIT(mmi_idle_init_dial_pad_option());
#endif

#ifdef __MMI_BROWSER_2__
    MMI_APP_INIT(mmi_brw_wap_init()); /* For Generic Browser */
#endif

#if defined(__MMI_MAPBAR_GIS__) || defined(__MMI_SUNAVI_GIS__)
    MMI_APP_INIT(mdi_gps_uart_init());
    MMI_APP_INIT(mmi_gis_init());
#endif

#ifdef __SF_MP4_SUPPORT__ //tylerWang
#ifndef MMI_ON_WIN32	//Add 08Mar14, Matthew
    initializeSFMP4();
#endif
#endif

#if defined(__MMI_DUAL_SIM_MASTER__)
    MMI_APP_INIT(MTPNP_PFAL_Init());
#endif  /* __MMI_DUAL_SIM_MASTER__ */

#if defined (__MMI_DUAL_SIM_DUAL_CALL_SLAVE__)|| defined(__MMI_DUAL_SIM_SINGLE_CALL__)
	MMI_APP_INIT(MTPNP_PFAL_slave_App_InitialAll());
#endif	/* defined (__MMI_DUAL_SIM_DUAL_CALL_SLAVE__)|| defined(__MMI_DUAL_SIM_SINGLE_CALL__) */

#if defined(HORSERACE_SUPPORT)
//Huyanwei Add It 
	Init_HorseRaceData();
	SendMessagesMMIToTwo( MSG_ID_HORSERACE_ON );
#if defined(NOKE_DEBUG)
	noke_dbg_printf("\r\n Init Horse Race Data ......\r\n");
#endif
#endif

#if defined(G_SENSOR_SUPPORT)
//Huyanwei Add It 
	Init_GSensorData();
#if defined(NOKE_DEBUG)
	noke_dbg_printf("\r\n Init GSensor Data ......\r\n");
#endif
#endif
}

#if defined(__MMI_DUAL_SIM_MASTER__)
void MMI_MTPNP_master_init(void)
{
    ST_MTPNP_AD_SYS_ID sys_id;
    ST_MTPNP_AD_NVRAM_ID nvram_id;

//    sys_id.DLL_task_mod_id = MOD_MTPNP;
    sys_id.MMI_task_mod_id = MOD_MMI;
//    sys_id.PNP_task_startup_msg_id = MSG_ID_MTPNP_STARTUP;
//    sys_id.PNP_task_stop_msg_id = MSG_ID_MTPNP_STOP;
//    sys_id.PNP_data_msg_id = MSG_ID_MTPNP;
//    sys_id.PNP_stack_sap_id = STACK_MTPNP_SAP;
//    sys_id.PNP_DLL_resume_msg_id = MSG_ID_MTPNP_DLL_RESUME;
//    sys_id.PNP_restart_timer_id = MTPNP_RESET_SLAVE_TIMER;
    MTPNP_PFAL_Set_sys_Info(&sys_id);
	
    nvram_id.nvram_last_dm_status_id = NVRAM_MTPNP_STATUS;
    nvram_id.nvram_start_mode_id = NVRAM_MTPNP_SETTING;

    nvram_id.nvram_owner_number_id = NVRAM_CARD2_OWNER_NUMBER;
	
    nvram_id.nvram_sms_recv_count_id = NVRAM_SLAVE_SMSCOUNTERS_RECV;
    nvram_id.nvram_sms_sent_count_id = NVRAM_SLAVE_SMSCOUNTERS_SENT;
	
    MTPNP_PFAL_Set_nvram_Info(&nvram_id);
	
    MTPNP_AD_Set_Msgbox_Capacity(MMI_SMS_MAX_MSG_NUM);

    /*
    * virtual eint initial
    */
#ifndef __MMI_DUAL_SIM_SINGLE_CALL__
    MTPNP_VENT_Init();
#endif /* __MMI_DUAL_SIM_SINGLE_CALL__ */

    /*
    * init module control
    */
    MTPNP_PFAL_MM_Init();
}
#endif /* __MMI_DUAL_SIM_MASTER__ */

#ifdef __MMI_DUAL_SIM_DUAL_CALL_SLAVE__
void MMI_MTPNP_slave_init(void)
{
    ST_MTPNP_AD_SYS_ID sys_id;
    ST_MTPNP_QOS_LEVEL qos_level;
    MTPNP_UINT8 * codebase_version = MTPNP_NULL;

    sys_id.DLL_task_mod_id = MOD_MTPNP;
    sys_id.MMI_task_mod_id = MOD_MMI;
    sys_id.PNP_task_startup_msg_id = MSG_ID_MTPNP_STARTUP;
    sys_id.PNP_task_stop_msg_id = MSG_ID_MTPNP_STOP;
    sys_id.PNP_data_msg_id = MSG_ID_MTPNP;
    sys_id.PNP_stack_sap_id = STACK_MTPNP_SAP;
    sys_id.Startup_req_msg_id = MSG_ID_SLAVE_STARTUP_REQ;
    MTPNP_PFAL_Set_sys_Info(&sys_id);

    qos_level.QOS_min_lvl = MTPNP_AD_Custom_qos_min_level();
    qos_level.QOS_max_lvl = MTPNP_AD_Custom_qos_max_level();
    MTPNP_AD_Set_QOS_Level(qos_level);

    /* Initial MTPNP ad & ps */
    MTPNP_AD_Init_Slave(codebase_version);
}

void MMI_Exception_Bootup(void)
{
    g_pwr_context.PowerOnMode = POWER_ON_EXCEPTION;
#ifdef __MMI_SUBLCD__
    gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
#endif /* __MMI_SUBLCD__ */ 
    gdi_layer_clear(GDI_COLOR_BLACK);
    OslMemoryStart(TRUE);									
    SetAbnormalReset();
    InitializeAll();
    OslDumpDataInFile();
    ClearInputEventHandler(MMI_DEVICE_ALL);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
    InitNvramData();
    InitAllApplications();
#ifdef __FLIGHT_MODE_SUPPORT__
    PhnsetFlightModePowerOnException();
#endif
    mmi_pwron_exception_check_display();
}
#endif	/* __MMI_DUAL_SIM_DUAL_CALL_SLAVE__ */
