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
 * BTMMIScr.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is for MMI screen of bluetooth application.
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#include "CommonScreens.h"
#include "MainMenuDef.h"        /* for MAIN_MENU_TITLE_EXTRA_APP_ICON  */

/* for pts V2.1.0.4 */
/* cannot update indicators to remote bluetooth headset while HFP is connected */
/* indicators shall be retrieved by remote HF AT+CIND? */
/* so for pts V2.1.0.4, host will not udpate indicators while HFP is just connected */
U8 g_enable_pts_test=0;  /* 0: disable, 1: enable */

#ifdef __MMI_BT_SUPPORT__

#include "wgui_status_icons.h"  /* for STATUS_ICON_BT */
#include "ProtocolEvents.h"
#include "SettingProfile.h"     /* for tone ID */
#include "ProfileGprots.h"      /* PlayRequestTone */
#include "gpioInc.h"    /* for turn on/off backlight */
#include "WrapperGprot.h"       /* IsMyTimerExist() */
#include "ExtDeviceDefs.h"
#include "SettingDefs.h"
#include "SimDetectionGprot.h"


#include "BTMMICM.h"



/***************************/
/* for MTK bluetooh       */
/***************************/
#ifdef __MMI_BT_MTK_SUPPORT__
#include "BTMMIHfpGprots.h"
#include "BTMMIHspGprots.h"
#include "BTMMISppGprots.h"
#include "BTMMIDunGprots.h"
#if defined(__MMI_SIMAP_SUPPORT__)
#include "BTMMISimapGprots.h"
#endif
#if defined(__MMI_FAX_SUPPORT__)
#include "BTMMIFaxGprots.h"
#endif
#if defined(__MMI_HIDD_SUPPORT__)
#include "BTMMIHiddGprots.h"
#include "BTMMIHidScrGprots.h"
#include "BTMMIHidScr.h"
#endif


#if defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__) || defined(__MMI_OPP_SUPPORT__) || defined(__MMI_BPP_SUPPORT__)

#include "BTMMIObexGprots.h"

#if defined(__MMI_OPP_SUPPORT__)
#include "BTMMIOppGprots.h"
#endif

#if defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__)
#include "BTMMIFtpGprots.h"
#endif

/* BIP */
#if defined(__MMI_BIP_SUPPORT__)
#include "BTMMIBipGprot.h"
#endif

#if defined(__MMI_BPP_SUPPORT__)
#include "BTMMIBppGprot.h"
#endif

#endif /* defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__) || defined(__MMI_OPP_SUPPORT__) || defined(__MMI_BPP_SUPPORT__) */ 

#endif /* __MMI_BT_MTK_SUPPORT__ */ 


/***************************/
/* bluetooh common files   */
/***************************/

#include "BTMMIScrGprots.h"
#include "BTMMIScr.h"

/* include opp related files */
#if defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__) || defined(__MMI_OPP_SUPPORT__)
#include "FileMgr.h"
#include "FileManagerGProt.h"
#endif /* defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__) || defined(__MMI_OPP_SUPPORT__) */ 

/* MMI BT profile related files */
#ifdef __MMI_BT_PROFILE__
#include "ProfilesDefs.h"
#include "ProfileGprots.h"
#endif /* __MMI_BT_PROFILE__ */ 

/* Trace Header Files */

/***************************************************************************** 
* External Variable
*****************************************************************************/
extern U8 isEarphonePlugged;
extern pBOOL IsBackHistory;

/***************************************************************************** 
* External functions
*****************************************************************************/
extern void wgui_stop_title_animation(void);
extern void ShowCategory111Screen_ext(
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        U8 *message,
        S16 input_type,
        U8 *buffer,
        S32 buffer_size,
        U8 *message2,
        S32 duration,
        U8 *history_buffer);                
extern kal_int32 mmi_chset_utf8_to_ucs2_string(kal_uint8 *dest, kal_int32 dest_size, kal_uint8 *src);
extern kal_int32 mmi_chset_ucs2_to_utf8_string(kal_uint8 *dest, kal_int32 dest_size, kal_uint8 *src);
extern kal_int32 mmi_chset_utf8_strlen(const kal_uint8 *s);
extern kal_int32 mmi_chset_utf8_to_ucs2(kal_uint8 *dest, kal_uint8 *utf8);
extern void UI_common_screen_exit(void);
extern void mmi_opp_init(void);
extern void mmi_ftp_init(void);
extern void mmi_opp_send_file_obj(void);
extern int mmi_profiles_bt_reset(void);
#ifdef __FLIGHT_MODE_SUPPORT__
extern void mmi_phnset_switch_flight_mode(void); //mmi_phnset_flight_mode_selection_finish(void);
#endif

#ifdef __MMI_DUAL_SIM_MASTER__
extern void DualModeSwitchCompleteUpdateStatus(void); 
#endif
	 
#ifdef __MTK_TARGET__
extern kal_bool BT_PcmLoopbackTest(void);
#endif 
extern void EmBTNotifyLoopbackDoneCnf(MMI_BOOL result);

#if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_A2DP_SUPPORT__)
extern void mmi_bt_a2dp_init(void);
extern void mmi_audply_bt_delete_device_callback(mmi_bt_dev_addr* bd_addr);
extern void mmi_audply_bt_power_off_callback(BOOL success);
extern void mmi_audply_bt_power_on_callback(BOOL success);
extern void av_bt_headset_selected_callback(mmi_bt_dev_struct* dev);
extern void av_bt_inquiry_start_callback(void);
extern void av_bt_inquiry_stop_callback(void);

#endif /* __MMI_BT_MTK_SUPPORT__ */ 

#if defined(__MMI_AVRCP_SUPPORT__) || defined(__MMI_AVRCP_CT_SUPPORT__)
extern void mmi_bt_avrcp_init(void);
#endif /* defined(__MMI_AVRCP_SUPPORT__) || defined(__MMI_AVRCP_CT_SUPPORT__) */ 


#if defined(__MMI_OPP_SUPPORT__)
extern void mmi_bt_opp_init(void);
#endif


extern BOOL mmi_profiles_bt_allow_popup(void);
extern pBOOL isInCall(void);
extern S32 mmi_is_redrawing_bk_screens(void);

/***************************************************************************** 
* Globol Variable
*****************************************************************************/

mmi_bt_scr_cntx_struct g_mmi_bt_scr_cntx;

PS8(*mmi_bt_ucs2_str_utility) (S8 *str_dest, const S8 *str_src);

const mmi_bt_func_ptr cm_profile_init_tbl[] = 
{
    mmi_bth_init,
#ifdef __MMI_HFP_SUPPORT__
    mmi_bth_hfg_init,
#endif 
#ifdef __MMI_HSP_SUPPORT__
    mmi_bth_hsg_init,
#endif 
#ifdef __MMI_SPP_SUPPORT__
    mmi_bth_spp_init,
#endif 
#ifdef __MMI_DUN_SUPPORT__
    mmi_bth_dun_init,
#endif 
#if defined(__MMI_FTS_SUPPORT__)|| defined(__MMI_FTC_SUPPORT__) || defined(__MMI_OPP_SUPPORT__)
    mmi_bt_obex_event_hdlr_init,
#endif /* defined (__MMI_FTS_SUPPORT__)|| defined(__MMI_FTC_SUPPORT__) || defined(__MMI_OPP_SUPPORT__) */
#ifdef __MMI_OPP_SUPPORT__
    mmi_bt_opp_init,
#endif 
#if defined(__MMI_FTS_SUPPORT__)|| defined(__MMI_FTC_SUPPORT__)
    mmi_bt_ftp_init,
#endif /* defined (__MMI_FTS_SUPPORT__)|| defined(__MMI_FTC_SUPPORT__) */
#if defined(__MMI_BPP_SUPPORT__)
    mmi_bt_bpp_init,
#endif /* defined (__MMI_BPP_SUPPORT__) */
#ifdef __MMI_A2DP_SUPPORT__
    mmi_bt_a2dp_init,
#endif 
#if defined(__MMI_AVRCP_SUPPORT__) || defined(__MMI_AVRCP_CT_SUPPORT__)
    mmi_bt_avrcp_init,
#endif 
#ifdef __MMI_BPP_SUPPORT__
    NULL,
#endif 
#ifdef __MMI_SIMAP_SUPPORT__
    mmi_bth_simap_init,
#endif 
#ifdef __MMI_FAX_SUPPORT__
    mmi_bth_fax_init,
#endif
#ifdef __MMI_HIDD_SUPPORT__
    mmi_bth_hidd_init,
#endif 
#ifdef __MMI_BIP_SUPPORT__
    mmi_bt_bip_init, /* BIP */
#endif 
    NULL
};

const mmi_bt_func_ptr cm_profile_deinit_tbl[] = 
{


#if defined (__MMI_OPP_SUPPORT__)
    mmi_bt_opp_deinit,
#endif /* defined (__MMI_FTS_SUPPORT__)|| defined(__MMI_FTC_SUPPORT__) */

#if defined (__MMI_FTS_SUPPORT__)|| defined(__MMI_FTC_SUPPORT__)
    mmi_bt_ftp_deinit,
#endif /* defined (__MMI_FTS_SUPPORT__)|| defined(__MMI_FTC_SUPPORT__) */
 
#if defined (__MMI_BPP_SUPPORT__)
    mmi_bt_bpp_deinit,
#endif /* defined (__MMI_BPP_SUPPORT__) */

#ifdef __MMI_BIP_SUPPORT__
    mmi_bt_bip_deinit, /* BIP */
#endif /* defined (__MMI_BIP_SUPPORT__) */
 
    NULL

};

const U16 profile_str_id_map[ /* MM_BT_NUM_OF_PROFILE_UUID */ ][2] =
{
    {MMI_BT_SPP_PROFILE_UUID, STR_BT_PROF_SPP},
    {MMI_BT_LAP_PROFILE_UUID, STR_BT_PROF_LAP},
    {MMI_BT_DUN_PROFILE_UUID, STR_BT_PROF_DUN},
    {MMI_BT_OBEX_IR_MC_SYNC_SERVICE_UUID, STR_BT_PROF_SYNC},
    {MMI_BT_OBEX_OBJECT_PUSH_SERVICE_UUID, STR_BT_PROF_OPP},
    {MMI_BT_OBEX_FILE_TRANSFER_UUID, STR_BT_PROF_FTP},
    {MMI_BT_HS_PROFILE_UUID, STR_BT_PROF_HS},
    {MMI_BT_CTP_PROFILE_UUID, STR_BT_PROF_CTP},
    /* for pts V2.1.0.4 */
    {MMI_BT_AUDIO_SOURCE_UUID, STR_BT_PROF_A2DP},
    {MMI_BT_AUDIO_SINK_UUID, STR_BT_PROF_A2DP},
    {MMI_BT_AV_REMOTE_CONTROL_TARGET_UUID, STR_BT_PROF_AVRCP_T},
    {MMI_BT_ADVANCED_AUDIO_PROFILE_UUID, STR_BT_PROF_A2DP},
    {MMI_BT_AV_REMOTE_CONTROL_UUID, STR_BT_PROF_AVRCP},
    {MMI_BT_ICP_PROFILE_UUID, STR_BT_PROF_ICP},
    {MMI_BT_FAX_PROFILE_UUID, STR_BT_PROF_FAX},
    {MMI_BT_HEADSET_AG_SERVICE_UUID, STR_BT_PROF_HS},
    {MMI_BT_PAN_PANU_PROFILE_UUID, STR_BT_PROF_PAN_PANU},
    {MMI_BT_PAN_NAP_PROFILE_UUID, STR_BT_PROF_PAN_NAP},
    {MMI_BT_PAN_GN_PROFILE_UUID, STR_BT_PROF_PAN_GN},
    {MMI_BT_DIRECT_PRINTING, STR_BT_PROF_OBEX_BPPS},
    {MMI_BT_OBEX_IMAGING_UUID, STR_BT_PROF_OBEX_IMAGING},
    {MMI_BT_OBEX_IMAGING_RESPONDER_UUID, STR_BT_PROF_OBEX_IMAGING_RESPONDER},
    {MMI_BT_HF_PROFILE_UUID, STR_BT_PROF_HF},
    {MMI_BT_HFG_PROFILE_UUID, STR_BT_PROF_HF},
    {MMI_BT_BASIC_PRINTING, STR_BT_PROF_BASIC_PRINTING},
    {MMI_BT_HID_PROFILE_UUID, STR_BT_PROF_HID},
    {MMI_BT_SIM_ACCESS_PROFILE_UUID, STR_BT_PROF_SAP},
    {MMI_BT_OBEX_PBA_PROFILE_UUID, STR_BT_PROF_PBAP},
    {MMI_BT_OBEX_BPPS_PROFILE_UUID, STR_BT_PROF_OBEX_BPPS},
    /* last one */
    {MMI_BT_MAX_PROFILE_UUID, STR_BT_PROF_UNKNOWN}

};

const U16 connect_type_str_id_map[][2] = 
{
    {MMI_BT_HFP_CONNECTION, STR_BT_PROF_HF},
    {MMI_BT_HSP_CONNECTION, STR_BT_PROF_HS},
    {MMI_BT_SPP_CONNECTION, STR_BT_PROF_SPP},
    {MMI_BT_DUN_CONNECTION, STR_BT_PROF_DUN},
    {MMI_BT_FTP_CONNECTION, STR_BT_PROF_FTP},
    {MMI_BT_OPP_CONNECTION, STR_BT_PROF_OPP},
    {MMI_BT_A2DP_CONNECTION, STR_BT_PROF_A2DP},
    {MMI_BT_AVRCP_CONNECTION, STR_BT_PROF_AVRCP_T},
    {MMI_BT_AVRCP_CT_CONNECTION, STR_BT_PROF_AVRCP},
    {MMI_BT_BPP_CONNECTION, STR_BT_PROF_BASIC_PRINTING},
    {MMI_BT_SIMAP_CONNECTION, STR_BT_PROF_SAP}, 
    {MMI_BT_FAX_CONNECTION, STR_BT_PROF_FAX},  
    {MMI_BT_HID_CONNECTION, STR_BT_PROF_HID},  
    {MMI_BT_BIP_CONNECTION, STR_BT_PROF_OBEX_IMAGING},  
    /* last one */
    {MMI_BT_LAST_CONNECTOIN_TYPE, STR_BT_PROF_UNKNOWN}

};

const U32 support_connecting_profile_tbl[] = 
{
#ifdef __MMI_HFP_SUPPORT__
    MMI_BT_HF_PROFILE_UUID,
#endif 

#ifdef __MMI_HSP_SUPPORT__
    MMI_BT_HS_PROFILE_UUID,
#endif 

#ifdef __MMI_SPP_SUPPORT__
    /* not allowed */
    /* MMI_BT_SPP_PROFILE_UUID, */
#endif /* __MMI_SPP_SUPPORT__ */ 

#ifdef __MMI_DUN_SUPPORT__
    /* not allowed */
    /* MMI_BT_DUN_PROFILE_UUID, */
#endif /* __MMI_DUN_SUPPORT__ */ 

#ifdef __MMI_OPP_SUPPORT__
    /* not allowed */
    /* MMI_BT_OBEX_OBJECT_PUSH_SERVICE_UUID, */
#endif /* __MMI_OPP_SUPPORT__ */ 

#if defined(__MMI_FTC_SUPPORT__)
    MMI_BT_OBEX_FILE_TRANSFER_UUID,
#endif 

#ifdef __MMI_A2DP_SUPPORT__
#if !defined(__MMI_BT_MTK_SUPPORT__)
    MMI_BT_ADVANCED_AUDIO_PROFILE_UUID,
#endif 
#endif 

#ifdef __MMI_AVRCP_SUPPORT__
    /* not allowed */
    /* MMI_BT_AV_REMOTE_CONTROL_UUID, */
#endif /* __MMI_AVRCP_SUPPORT__ */ 

#ifdef __MMI_AVRCP_CT_SUPPORT__
    MMI_BT_AV_REMOTE_CONTROL_TARGET_UUID,
#endif /* __MMI_AVRCP_CT_SUPPORT__ */ 

#ifdef __MMI_BPP_SUPPORT__
    MMI_BT_BASIC_PRINTING,
#endif 

#ifdef __MMI_HIDD_SUPPORT__
        MMI_BT_HID_PROFILE_UUID,
#endif 

/* BIP */
#ifdef __MMI_BIP_SUPPORT__
        MMI_BTH_OBEX_IMAGING_RESPONDER_UUID,
#endif 


    MMI_BT_MAX_PROFILE_UUID,
};

const U32 support_disconnecting_profile_tbl[] = 
{
#ifdef __MMI_HFP_SUPPORT__
    MMI_BT_HFP_CONNECTION,
#endif 
#ifdef __MMI_HSP_SUPPORT__
    MMI_BT_HSP_CONNECTION,
#endif 
#ifdef __MMI_SPP_SUPPORT__
    MMI_BT_SPP_CONNECTION,
#endif 
#ifdef __MMI_DUN_SUPPORT__
    MMI_BT_DUN_CONNECTION,
#endif 
#ifdef __MMI_OPP_SUPPORT__
    MMI_BT_OPP_CONNECTION,
#endif 
#if defined(__MMI_FTS_SUPPORT__)
    MMI_BT_FTP_CONNECTION,
#endif 
#ifdef __MMI_A2DP_SUPPORT__
    MMI_BT_A2DP_CONNECTION,
#endif 
#ifdef __MMI_AVRCP_SUPPORT__
    MMI_BT_AVRCP_CONNECTION,
#endif 
#ifdef __MMI_AVRCP_CT_SUPPORT__
    MMI_BT_AVRCP_CT_CONNECTION,
#endif 

#ifdef __MMI_BPP_SUPPORT__
    MMI_BT_BPP_CONNECTION,
#endif 

#ifdef __MMI_SIMAP_SUPPORT__
    MMI_BT_SIMAP_CONNECTION,
#endif 

#ifdef __MMI_FAX_SUPPORT__
    MMI_BT_FAX_CONNECTION,      
#endif
#ifdef __MMI_HIDD_SUPPORT__
        MMI_BT_HID_CONNECTION,
#endif 

/* BIP */
#ifdef __MMI_BIP_SUPPORT__
    MMI_BT_BIP_CONNECTION,
#endif 

    MMI_BT_MAX_PROFILE_UUID,
};

/***************************************************************************** 
* Functions
*****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_deinit
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_DEINIT);

    for (i = 0; i < (sizeof(cm_profile_deinit_tbl) / sizeof(mmi_bt_func_ptr)); i++)
    {
        if ((*cm_profile_deinit_tbl[i]) != NULL)
        {
            (*cm_profile_deinit_tbl[i]) ();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_init
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_INIT);

    for (i = 0; i < (sizeof(cm_profile_init_tbl) / sizeof(mmi_bt_func_ptr)); i++)
    {
        if ((*cm_profile_init_tbl[i]) != NULL)
        {
            (*cm_profile_init_tbl[i]) ();
        }
    }

    /* init loopack test msg handler from At command */
    SetProtocolEventHandler(mmi_bt_loopback_req_ind_hdler, MSG_ID_MMI_L4_BT_LOOPBACK_TEST_REQ_IND);

    /* init bt scr context */
    /* mmi_bt_scr_init shall be called after mmi_init */
    /* because mmi_bt_scr_init will reg scr callback to context */
    mmi_bt_scr_init();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_scr_init
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_scr_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_SCR_INIT);
    /* init menu hilight handler and hint handler */
    mmi_bt_init_menu_highlight_hdlr();
    /* reset bt screen context */
    memset(&g_mmi_bt_scr_cntx, 0, sizeof(mmi_bt_scr_cntx_struct));
    /* init stack cb of scr context */
    mmi_bt_init_stack_cb();
    /* init scr cb of core context */
    mmi_bt_init_scr_cb();
	#if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_HIDD_SUPPORT__)
    mmi_bt_hid_scr_init();
    #endif 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_init_menu_highlight_hdlr
 * DESCRIPTION
 *  This function is to initialize the mmi bt hightlight handler.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_init_menu_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU_CONN_BT_MAIN, mmi_bt_main_hilight_handler);
    SetHiliteHandler(MENU_CONN_BT_POWER, mmi_bt_power_hilight_handler);
    SetHiliteHandler(MENU_CONN_BT_SCH_AUDIO_DEV, mmi_bt_sch_aud_dev_hilight_handler);
    SetHiliteHandler(MENU_CONN_BT_MYDEV, mmi_bt_mydev_hilight_handler);
    SetHiliteHandler(MENU_CONN_BT_ACT_DEV, mmi_bt_act_dev_hilight_handler);
    SetHiliteHandler(MENU_CONN_BT_SET, mmi_bt_set_hilight_handler);
    SetHiliteHandler(MENU_CONN_BT_SET_VIS, mmi_bt_set_vis_hilight_handler);
    SetHiliteHandler(MENU_CONN_BT_SET_NAME, mmi_bt_set_name_hilight_handler);
    SetHiliteHandler(MENU_CONN_BT_SET_AUTH, mmi_bt_set_auth_hilight_handler);
    SetHiliteHandler(MENU_CONN_BT_SET_AUDIO_PATH, mmi_bt_set_aud_path_hilight_handler);
    SetHiliteHandler(MENU_CONN_BT_SET_AUDIO_PATH_PHONE, mmi_bt_set_aud_path_phone_hilight_handler);
    SetHiliteHandler(MENU_CONN_BT_SET_AUDIO_PATH_HF, mmi_bt_set_aud_path_hf_hilight_handler);
	#ifdef __MMI_SIMAP_SUPPORT__
    SetHiliteHandler(MENU_CONN_BT_SET_SIMAP, mmi_bt_set_simap_hilight_handler);
	#endif
    SetHiliteHandler(MENU_CONN_BT_ABOUT, mmi_bt_about_hilight_handler);

    SetHintHandler(MENU_CONN_BT_POWER, mmi_bt_power_hint_handler);
    SetHintHandler(MENU_CONN_BT_SET_VIS, mmi_bt_set_vis_hint_handler);
    SetHintHandler(MENU_CONN_BT_SET_AUTH, mmi_bt_set_auth_hint_handler);
    SetHintHandler(MENU_CONN_BT_SET_NAME, mmi_bt_set_name_hint_handler);
    SetHintHandler(MENU_CONN_BT_SET_AUDIO_PATH, mmi_bt_set_path_hint_handler);
	#ifdef __MMI_SIMAP_SUPPORT__
    SetHintHandler(MENU_CONN_BT_SET_SIMAP, mmi_bt_set_simap_hint_handler);
	#endif

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_init_stack_cb
 * DESCRIPTION
 *  This function is to init bt stack cb
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_init_stack_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* register stack callback */
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_IS_ACTIVATED, (void*)mmi_bth_is_activated);
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_IS_PANIC, (void*)mmi_bth_is_panic);
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_IS_VIS, (void*)mmi_bth_is_vis);
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_IS_AUTH, (void*)mmi_bth_is_auth);
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_IS_AUD_PTH_SET_TO_HF, (void*)mmi_bth_is_aud_pth_set_to_hf);
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_IS_AUD_PTH_SET_TO_HF, (void*)mmi_bth_is_aud_pth_set_to_hf);
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_IS_INCALL_AUD_SWAP2BT, (void*)mmi_bth_is_incall_aud_swap2bt);
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_IS_HS_CONNECTED, (void*)mmi_bth_is_hs_connected);
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_IS_HFP_AUDIO_LINK_CONNECTED, (void*)mmi_bth_is_hs_audio_link_connected);
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_IS_ANY_CONNECTION_ACTIVE, (void*)mmi_bth_is_any_connection_active);
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_IS_CONNECTION_ACTIVE, (void*)mmi_bth_is_connection_active);
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_IS_SIMAP_ACTIVATE, (void*)mmi_bth_is_simap_activate);

    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_GET_STATE, (void*)mmi_bth_get_state);
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_GET_HOST_DEV_INFO, (void*)mmi_bth_get_host_dev_info);
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_GET_DISCOV_DEV_NUM, (void*)mmi_bth_get_discov_dev_num);
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_GET_DISCOV_DEV_INFO, (void*)mmi_bth_get_discov_dev_info);
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_GET_PAIRED_DEV_NUM, (void*)mmi_bth_get_paired_dev_num);
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_GET_PAIRED_DEV_INFO, (void*)mmi_bth_get_paired_dev_info);
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_GET_EXISTED_DEV_NUM, (void*)mmi_bth_get_existed_dev_num);
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_GET_EXISTED_DEV_INFO, (void*)mmi_bth_get_existed_dev_info);
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_GET_EXISTED_CONN_INFO, (void*)mmi_bth_get_existed_connect_info);
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_GET_ACTION_ITEM_INDEX, (void*)mmi_bth_get_action_item_index);
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_GET_RAM_FLAG, (void*)mmi_bth_get_ram_flag);
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_GET_CONNECTION_TYPE, (void*)mmi_bth_get_connection_type);
	/* Configure Default Headset */
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_GET_DEFAULT_HS_INDEX, (void*)mmi_bth_get_default_hs_index);


    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_ANTENNA_OFF_REQ, (void*)mmi_bth_antenna_off_req);
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_ANTENNA_ON_REQ, (void*)mmi_bth_antenna_on_req);
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_RESTART_BT_MODULE_REQ, (void*)mmi_bth_restart_bt_module_req);
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_RECOVER_PANIC_REQ, (void*)mmi_bth_recover_panic_req);

    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_DEACTIVATE, (void*)mmi_bth_deactivate_req);
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_ACTIVATE, (void*)mmi_bth_activate_req);
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_RELEASE_ALL_CONNECT, (void*)mmi_bth_release_all_connection_req);
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_RELEASE_DEV_CONNECT, (void*)mmi_bth_release_dev_connection_req);

    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_INQUIRY, (void*)mmi_bth_inquiry_req);
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_INQUIRY_CANCEL, (void*)mmi_bth_inquiry_cancel_req);
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_BOND, (void*)mmi_bth_bond_req);
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_PAIR, (void*)mmi_bth_pair_req);
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_REFRESH_SERVICE_LIST, (void*)mmi_bth_refresh_service_list_req);
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_CONNECT, (void*)mmi_bth_connect_req);
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_DISCONNECT, (void*)mmi_bth_disconnect_req);
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_CONNECT_ACCEPT_CNF_RES, (void*)mmi_bth_connect_accept_cnf_res);

    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_MYDEV_DEL, (void*)mmi_bth_mydev_del_req);
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_MYDEV_DEL_ALL, (void*)mmi_bth_mydev_del_all_req);
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_MYDEV_ADD, (void*)mmi_bth_mydev_add_req);
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_MYDEV_REMOVE, (void*)mmi_bth_mydev_remove_req);

    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_SET_VIS_REQ, (void*)mmi_bth_set_vis_req);
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_SET_CONNECTABLE_REQ, (void*)mmi_bth_set_connectable_req);
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_SET_NAME_REQ, (void*)mmi_bth_set_name_req);
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_SET_AUTH_REQ, (void*)mmi_bth_set_auth_req);
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_SET_SIMAP_REQ, (void*)mmi_bth_set_simap_req);    
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_SET_AUD_PTH_2_HF, (void*)mmi_bth_set_aud_pth_2_hf);
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_SET_RAM_FLAG, (void*)mmi_bth_set_ram_flag);
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_RESET_RAM_FLAG, (void*)mmi_bth_reset_ram_flag);
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_SET_FLAG, (void*)mmi_bth_set_flag);
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_RESET_FLAG, (void*)mmi_bth_reset_flag);
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_SET_STATE, (void*)mmi_bth_set_state);
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_SET_HEADSET_SPEAKER_GAIN, (void*)mmi_bth_set_headset_speaker_gain_req);
	/* Configure Default Headset */
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_SET_DEFAULT_HS_INDEX, (void*)mmi_bth_set_default_hs_index);

    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_HFP_SCO_CONN_REQ, (void*)mmi_bth_hfp_sco_connect_req);
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_HFP_SCO_DISCONN_REQ, (void*)mmi_bth_hfp_sco_disconnect_req);
    /* Configure Default Headset */
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_CONNECT_LAST_HEADSET_REQ, (void*)mmi_bth_connect_last_headset_req);

    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_TURN_ON_SPEECH, (void*)mmi_bth_turn_on_speech_req);
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_POWER_OFF_CHIP, (void*)mmi_bth_pwroff);
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_SWITCH_VOICE_PATH_INCALL, (void*)mmi_bth_switch_voice_path_incall);

    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_RESET_HFP_MODULE, (void*)mmi_bth_reset_hfp_module);
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_RESET_A2DP_MODULE, (void*)mmi_bth_reset_a2dp_module);
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_CLOSE_SDC, (void *)mmi_bth_close_sdc_req); 
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_PROHIBIT_OPP, (void*)mmi_bth_prohibit_opp_req);
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_PROHIBIT_FTP, (void*)mmi_bth_prohibit_ftp_req);
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_PROHIBIT_SPP, (void*)mmi_bth_prohibit_spp_req);
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_PROHIBIT_DUN, (void*)mmi_bth_prohibit_dun_req);
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_PERMIT_OPP, (void*)mmi_bth_permit_opp_req);
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_PERMIT_FTP, (void*)mmi_bth_permit_ftp_req);
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_PERMIT_SPP, (void*)mmi_bth_permit_spp_req);
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_PERMIT_DUN, (void*)mmi_bth_permit_dun_req);
    mmi_bt_reg_stack_cb(
        MMI_BT_STACK_CB_PROFILE_CB_BEFORE_RELEASE_CONN,
        (void*)mmi_bth_profile_callback_before_release_connection_hdler);

    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_RESET_NVRAM, (void*)mmi_bth_nvram_reset_info);
    mmi_bt_reg_stack_cb(MMI_BT_STACK_CB_WRITE_NVRAM, (void*)mmi_bth_nvram_write_info);


}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_init_scr_cb
 * DESCRIPTION
 *  This function is to init bt scr cb
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_init_scr_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reg scr callback */
    mmi_bt_reg_scr_cb(MMI_BT_SCR_CB_DEACTIVATE, (void*)mmi_bt_power_switch_off_complete);
    mmi_bt_reg_scr_cb(MMI_BT_SCR_CB_ACTIVATE, (void*)mmi_bt_power_switch_on_complete);
    mmi_bt_reg_scr_cb(MMI_BT_SCR_CB_RELEASE_ALL_CONN, (void*)mmi_bt_release_all_conn_complete);
    mmi_bt_reg_scr_cb(MMI_BT_SCR_CB_PROHIBIT_SERVICE, (void*)mmi_bt_prohibit_service_complete);

    mmi_bt_reg_scr_cb(MMI_BT_SCR_CB_INQUIRY, (void*)mmi_bt_entry_inq_result);
    mmi_bt_reg_scr_cb(MMI_BT_SCR_CB_INQUIRY_CFM, (void*)mmi_bt_inq_complete);
    mmi_bt_reg_scr_cb(MMI_BT_SCR_CB_INQUIRY_CANCEL, (void*)mmi_bt_inq_complete);
    mmi_bt_reg_scr_cb(MMI_BT_SCR_CB_BOND, (void*)mmi_bt_entry_connect_confirm);
    mmi_bt_reg_scr_cb(MMI_BT_SCR_CB_BOND_IND, (void*)mmi_bt_entry_bond_result);
    mmi_bt_reg_scr_cb(MMI_BT_SCR_CB_PAIR, (void*)mmi_bt_entry_passkey_input);
    mmi_bt_reg_scr_cb(MMI_BT_SCR_CB_PAIR_RESULT, (void*)mmi_bt_entry_pair_result);
#if defined(__MMI_BT_MTK_SUPPORT__)
    mmi_bt_reg_scr_cb(MMI_BT_SCR_CB_CONNECT_ACCEPT_CNF, (void*)mmi_bt_connect_accept_cnf_req);
#endif /* defined(__MMI_BT_MTK_SUPPORT__) */ 
    mmi_bt_reg_scr_cb(MMI_BT_SCR_CB_CONNECT, (void*)mmi_bt_connect_complete);
    mmi_bt_reg_scr_cb(MMI_BT_SCR_CB_CONNECT_AUTHORISE_IND, (void*)mmi_bt_connect_authorise_ind);
    mmi_bt_reg_scr_cb(MMI_BT_SCR_CB_DISCONNECT, (void*)mmi_bt_entry_disconnect_complete);
    mmi_bt_reg_scr_cb(MMI_BT_SCR_CB_REFRESH_PROF, (void*)mmi_bt_refresh_prof_complete);

    mmi_bt_reg_scr_cb(MMI_BT_SCR_CB_MYDEV_CONNECT, (void*)NULL);
    mmi_bt_reg_scr_cb(MMI_BT_SCR_CB_MYDEV_RENAME, (void*)NULL);
    mmi_bt_reg_scr_cb(MMI_BT_SCR_CB_MYDEV_AUTH, (void*)NULL);
    mmi_bt_reg_scr_cb(MMI_BT_SCR_CB_MYDEV_DEL, (void*)mmi_bt_mydev_del_complete);
    mmi_bt_reg_scr_cb(MMI_BT_SCR_CB_MYDEV_DEL_ALL, (void*)mmi_bt_mydev_del_complete);

    mmi_bt_reg_scr_cb(MMI_BT_SCR_CB_SET_VIS_REQ, (void*)mmi_bt_set_vis_complete);
    mmi_bt_reg_scr_cb(MMI_BT_SCR_CB_SET_NAME_REQ, (void*)mmi_bt_set_name_proc_complete);
    mmi_bt_reg_scr_cb(MMI_BT_SCR_CB_SET_AUTH_REQ, (void*)mmi_bt_set_auth_complete);
    mmi_bt_reg_scr_cb(MMI_BT_SCR_CB_SET_AUD_PTH_2_HF, (void*)NULL);
#if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_SIMAP_SUPPORT__)
    mmi_bt_reg_scr_cb(MMI_BT_SCR_CB_SET_SIMAP_REQ, (void*)mmi_bt_set_simap_complete);
#endif    

    mmi_bt_reg_scr_cb(MMI_BT_SCR_CB_ERROR, (void*)mmi_bt_error);
    mmi_bt_reg_scr_cb(MMI_BT_SCR_CB_SCO_IND, (void*)mmi_bt_sco_ind);
    mmi_bt_reg_scr_cb(MMI_BT_SCR_CB_PANIC_IND, (void*)mmi_bt_panic_ind_pre_process);

    mmi_bt_reg_scr_cb(MMI_BT_SCR_CB_DISPLAY_POPUP, (void*)mmi_bt_show_popup_scr);
    mmi_bt_reg_scr_cb(MMI_BT_SCR_CB_SHOW_PROGRESSING, (void*)mmi_bt_show_progress_scr);
#if defined(__MMI_BT_MTK_SUPPORT__)
    mmi_bt_reg_scr_cb(MMI_BT_SCR_CB_UPDATE_STATUS_ICON, (void*)mmi_bt_update_status_icon);
#endif /* defined(__MMI_BT_MTK_SUPPORT__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_reg_stack_cb
 * DESCRIPTION
 *  This function is to reg bt stack cb
 * PARAMETERS
 *  type        [IN]            
 *  fp          [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_reg_stack_cb(mmi_bt_stack_cb_type_enum type, void *fp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {

        case MMI_BT_STACK_CB_IS_ACTIVATED:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_pwron = (MMI_BOOL(*)(void))fp;
            break;
        case MMI_BT_STACK_CB_IS_PANIC:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_panic = (MMI_BOOL(*)(void))fp;
            break;
        case MMI_BT_STACK_CB_IS_VIS:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_vis = (MMI_BOOL(*)(void))fp;
            break;
        case MMI_BT_STACK_CB_IS_AUTH:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_auth = (MMI_BOOL(*)(void))fp;
            break;
        case MMI_BT_STACK_CB_IS_AUD_PTH_SET_TO_HF:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_aud_pth_set_to_hf = (MMI_BOOL(*)(void))fp;
            break;
        case MMI_BT_STACK_CB_IS_INCALL_AUD_SWAP2BT:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_incall_aud_swap2bt = (MMI_BOOL(*)(void))fp;
            break;
        case MMI_BT_STACK_CB_IS_HS_CONNECTED:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_hs_connected = (MMI_BOOL(*)(void))fp;
            break;
        case MMI_BT_STACK_CB_IS_HFP_AUDIO_LINK_CONNECTED:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_hfp_audio_link_connected = (MMI_BOOL(*)(void))fp;
            break;
        case MMI_BT_STACK_CB_IS_ANY_CONNECTION_ACTIVE:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_any_connection_active = (MMI_BOOL(*)(void))fp;
            break;
        case MMI_BT_STACK_CB_IS_CONNECTION_ACTIVE:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_connection_active = (MMI_BOOL(*)(mmi_bt_dev_addr*)) fp;
            break;
        case MMI_BT_STACK_CB_IS_SIMAP_ACTIVATE:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_simap_activate= (MMI_BOOL(*)(void))fp;
            break;
        case MMI_BT_STACK_CB_GET_HOST_DEV_INFO:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_host_dev_info = (mmi_bt_dev_struct * (*)(void))fp;
            break;
        case MMI_BT_STACK_CB_GET_DISCOV_DEV_NUM:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_discov_dev_num = (U8(*)(void))fp;
            break;
        case MMI_BT_STACK_CB_GET_DISCOV_DEV_INFO:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_discov_dev_info = (mmi_bt_dev_struct * (*)(U16)) fp;
            break;
        case MMI_BT_STACK_CB_GET_STATE:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_state = (U8(*)(void))fp;
            break;
        case MMI_BT_STACK_CB_GET_PAIRED_DEV_NUM:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_num = (U8(*)(void))fp;
            break;
        case MMI_BT_STACK_CB_GET_PAIRED_DEV_INFO:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_info = (mmi_bt_dev_struct * (*)(U16)) fp;
            break;
        case MMI_BT_STACK_CB_GET_EXISTED_DEV_NUM:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_existed_dev_num = (U8(*)(void))fp;
            break;
        case MMI_BT_STACK_CB_GET_EXISTED_DEV_INFO:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_existed_dev_info = (mmi_bt_dev_struct * (*)(U16)) fp;
            break;
        case MMI_BT_STACK_CB_GET_EXISTED_CONN_INFO:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_existed_conn_info = (mmi_bt_connect_struct * (*)(U16)) fp;
            break;
        case MMI_BT_STACK_CB_GET_ACTION_ITEM_INDEX:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_action_item_index = (U8(*)(void))fp;
            break;
        case MMI_BT_STACK_CB_GET_RAM_FLAG:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_ram_flag = (U32(*)(U32)) fp;
            break;
        case MMI_BT_STACK_CB_GET_CONNECTION_TYPE:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_connection_type = (U32(*)(U32)) fp;
            break;
        /* Configure Default Headset */    
        case MMI_BT_STACK_CB_GET_DEFAULT_HS_INDEX:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_default_hs_index = (U32(*)(void)) fp;
            break;
            
        case MMI_BT_STACK_CB_ANTENNA_OFF_REQ:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_antenna_off_req = (MMI_BOOL(*)(void))fp;
            break;
        case MMI_BT_STACK_CB_ANTENNA_ON_REQ:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_antenna_on_req = (MMI_BOOL(*)(void))fp;
            break;
        case MMI_BT_STACK_CB_RESTART_BT_MODULE_REQ:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_restart_bt_module_req = (MMI_BOOL(*)(void))fp;
            break;
        case MMI_BT_STACK_CB_RECOVER_PANIC_REQ:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_recover_panic_req = (MMI_BOOL(*)(void))fp;
            break;
        case MMI_BT_STACK_CB_DEACTIVATE:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_deactivate_req = (MMI_BOOL(*)(void))fp;
            break;
        case MMI_BT_STACK_CB_ACTIVATE:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_activate_req = (MMI_BOOL(*)(void))fp;
            break;
        case MMI_BT_STACK_CB_RELEASE_ALL_CONNECT:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_release_all_connection_req = (MMI_BOOL(*)(void))fp;
            break;
        case MMI_BT_STACK_CB_RELEASE_DEV_CONNECT:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_release_dev_connection_req = (MMI_BOOL(*)(mmi_bt_dev_addr*)) fp;
            break;
        case MMI_BT_STACK_CB_INQUIRY:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_inquiry_req = (MMI_BOOL(*)(U8, U16, U32, MMI_BOOL, U8)) fp;
            break;
        case MMI_BT_STACK_CB_INQUIRY_CANCEL:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_inquiry_cancel_req = (MMI_BOOL(*)(U8)) fp;
            break;
        case MMI_BT_STACK_CB_BOND:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_bond_req = (MMI_BOOL(*)(U32)) fp;
            break;
        case MMI_BT_STACK_CB_PAIR:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_pair_req = (MMI_BOOL(*)(mmi_bt_dev_addr *, U8 *, MMI_BOOL)) fp;
            break;
        case MMI_BT_STACK_CB_REFRESH_SERVICE_LIST:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_refresh_service_list_req = (MMI_BOOL(*)(mmi_bt_dev_addr*)) fp;
            break;
        case MMI_BT_STACK_CB_CONNECT:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_connect_req = (MMI_BOOL(*)(mmi_bt_dev_addr *, U32)) fp;
            break;
        case MMI_BT_STACK_CB_DISCONNECT:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_disconnect_req = (MMI_BOOL(*)(U32, mmi_bt_connection_type)) fp;
            break;
        case MMI_BT_STACK_CB_CONNECT_ACCEPT_CNF_RES:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_connect_accept_cnf_res =
                (MMI_BOOL(*)(mmi_bt_dev_addr *, U32, MMI_BOOL)) fp;
            break;

            //case MMI_BT_STACK_CB_MYDEV_RENAME:
            //   g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_mydev_rename_req = (MMI_BOOL (*)(MMI_BOOL))fp;
            //   break;
            //case MMI_BT_STACK_CB_MYDEV_AUTH:
            //  g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_mydev_authorise_req = (MMI_BOOL (*)(mmi_bt_vis_enum))fp;
            //   break;
        case MMI_BT_STACK_CB_MYDEV_DEL:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_mydev_del_req = (MMI_BOOL(*)(mmi_bt_dev_addr*)) fp;
            break;
        case MMI_BT_STACK_CB_MYDEV_DEL_ALL:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_mydev_del_all_req = (MMI_BOOL(*)(void))fp;
            break;
        case MMI_BT_STACK_CB_MYDEV_ADD:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_mydev_add_req = (MMI_BOOL(*)(mmi_bt_dev_addr*)) fp;
            break;
        case MMI_BT_STACK_CB_MYDEV_REMOVE:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_mydev_remove_req = (MMI_BOOL(*)(mmi_bt_dev_addr*)) fp;
            break;
        case MMI_BT_STACK_CB_SET_VIS_REQ:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_set_vis_req = (MMI_BOOL(*)(MMI_BOOL)) fp;
            break;
        case MMI_BT_STACK_CB_SET_CONNECTABLE_REQ:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_set_connectable_req = (MMI_BOOL(*)(MMI_BOOL)) fp;
            break;
        case MMI_BT_STACK_CB_SET_NAME_REQ:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_set_name_req = (MMI_BOOL(*)(U8*)) fp;
            break;
        case MMI_BT_STACK_CB_SET_AUTH_REQ:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_set_auth_req = (MMI_BOOL(*)(MMI_BOOL)) fp;
            break;
        case MMI_BT_STACK_CB_SET_SIMAP_REQ:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_set_simap_req = (MMI_BOOL(*)(MMI_BOOL)) fp;
            break;
        case MMI_BT_STACK_CB_SET_AUD_PTH_2_HF:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_set_aud_pth_2_hf = (MMI_BOOL(*)(MMI_BOOL)) fp;
            break;
        case MMI_BT_STACK_CB_SET_RAM_FLAG:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_set_ram_flag_req = (MMI_BOOL(*)(U32)) fp;
            break;
        case MMI_BT_STACK_CB_RESET_RAM_FLAG:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_reset_ram_flag_req = (MMI_BOOL(*)(U32)) fp;
            break;
        case MMI_BT_STACK_CB_SET_FLAG:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_set_flag_req = (MMI_BOOL(*)(U32)) fp;
            break;
        case MMI_BT_STACK_CB_RESET_FLAG:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_reset_flag_req = (MMI_BOOL(*)(U32)) fp;
            break;
        case MMI_BT_STACK_CB_SET_STATE:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_set_state = (MMI_BOOL(*)(U32)) fp;
            break;
        case MMI_BT_STACK_CB_SET_HEADSET_SPEAKER_GAIN:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_set_headset_speaker_gain_req = (MMI_BOOL(*)(U8, U32)) fp;
            break;
        /* Configure Default Headset */    
        case MMI_BT_STACK_CB_SET_DEFAULT_HS_INDEX:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_set_default_hs_index = (MMI_BOOL(*)(U32)) fp;
            break;

        case MMI_BT_STACK_CB_HFP_SCO_CONN_REQ:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_hfp_sco_link_connect_req = (MMI_BOOL(*)(void))fp;
            break;
        case MMI_BT_STACK_CB_HFP_SCO_DISCONN_REQ:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_hfp_sco_link_disconnect_req = (MMI_BOOL(*)(void))fp;
            break;

		/* Configure Default Headset */
        case MMI_BT_STACK_CB_CONNECT_LAST_HEADSET_REQ:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_connect_last_headset_req = (MMI_BOOL(*)(void))fp;
            break;
		
        case MMI_BT_STACK_CB_TURN_ON_SPEECH:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_turn_on_speech_req = (MMI_BOOL(*)(MMI_BOOL)) fp;
            break;
        case MMI_BT_STACK_CB_POWER_OFF_CHIP:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_pwroff = (void (*)(void))fp;
            break;
        case MMI_BT_STACK_CB_SWITCH_VOICE_PATH_INCALL:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_switch_voice_path_incall = (U8(*)(MMI_BOOL)) fp;
            break;
        case MMI_BT_STACK_CB_RESET_NVRAM:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_nvram_reset_info = (MMI_BOOL(*)(void))fp;
            break;
        case MMI_BT_STACK_CB_WRITE_NVRAM:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_nvram_write_info = (MMI_BOOL(*)(void))fp;
            break;
        case MMI_BT_STACK_CB_RESET_HFP_MODULE:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_reset_hfp_module = (MMI_BOOL(*)(void))fp;
            break;
        case MMI_BT_STACK_CB_RESET_A2DP_MODULE:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_reset_a2dp_module = (MMI_BOOL(*)(void))fp;
            break;
        case MMI_BT_STACK_CB_CLOSE_SDC:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_close_sdc_req = (MMI_BOOL(*)(void))fp;
            break;
        case MMI_BT_STACK_CB_PROHIBIT_OPP:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_prohibit_opp_req = (MMI_BOOL(*)(void))fp;
            break;
        case MMI_BT_STACK_CB_PROHIBIT_FTP:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_prohibit_ftp_req = (MMI_BOOL(*)(void))fp;
            break;
        case MMI_BT_STACK_CB_PROHIBIT_SPP:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_prohibit_spp_req = (MMI_BOOL(*)(void))fp;
            break;
        case MMI_BT_STACK_CB_PROHIBIT_DUN:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_prohibit_dun_req = (MMI_BOOL(*)(void))fp;
            break;
        case MMI_BT_STACK_CB_PERMIT_OPP:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_permit_opp_req = (MMI_BOOL(*)(void))fp;
            break;
        case MMI_BT_STACK_CB_PERMIT_FTP:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_permit_ftp_req = (MMI_BOOL(*)(void))fp;
            break;
        case MMI_BT_STACK_CB_PERMIT_SPP:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_permit_spp_req = (MMI_BOOL(*)(void))fp;
            break;
        case MMI_BT_STACK_CB_PERMIT_DUN:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_permit_dun_req = (MMI_BOOL(*)(void))fp;
            break;
        case MMI_BT_STACK_CB_PROFILE_CB_BEFORE_RELEASE_CONN:
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_profile_callback_before_release_connection_hdler =
                (void (*)(U32, U8, U16, U32, U32))fp;
            break;

        default:
            MMI_BT_ASSERT(0);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_reg_scr_cb
 * DESCRIPTION
 *  This function is to register callback function.
 * PARAMETERS
 *  type        [IN]            
 *  fp          [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_reg_scr_cb(mmi_bt_scr_cb_type_enum type, void *fp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bth_cntx_struct *bt_core_cntx_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    bt_core_cntx_p = &g_mmi_bth_cntx;

    switch (type)
    {
        case MMI_BT_SCR_CB_ACTIVATE:
            bt_core_cntx_p->scr_cb_tbl.mmi_bt_scr_cb_activate = (void (*)(MMI_BOOL))fp;
            break;
        case MMI_BT_SCR_CB_DEACTIVATE:
            bt_core_cntx_p->scr_cb_tbl.mmi_bt_scr_cb_deactivate = (void (*)(MMI_BOOL))fp;
            break;
        case MMI_BT_SCR_CB_RELEASE_ALL_CONN:
            bt_core_cntx_p->scr_cb_tbl.mmi_bt_scr_cb_release_all_conn = (void (*)(MMI_BOOL))fp;
            break;
        case MMI_BT_SCR_CB_PROHIBIT_SERVICE:
            bt_core_cntx_p->scr_cb_tbl.mmi_bt_scr_cb_prohibit_services = (void (*)(MMI_BOOL))fp;
            break;

        case MMI_BT_SCR_CB_INQUIRY:
            bt_core_cntx_p->scr_cb_tbl.mmi_bt_scr_cb_inquiry = (void (*)(void))fp;
        case MMI_BT_SCR_CB_INQUIRY_CFM:
            bt_core_cntx_p->scr_cb_tbl.mmi_bt_scr_cb_inquiry_cfm = (void (*)(MMI_BOOL))fp;
            break;
        case MMI_BT_SCR_CB_INQUIRY_CANCEL:
            bt_core_cntx_p->scr_cb_tbl.mmi_bt_scr_cb_inquiry_cancel = (void (*)(MMI_BOOL))fp;
            break;
        case MMI_BT_SCR_CB_BOND:
            bt_core_cntx_p->scr_cb_tbl.mmi_bt_scr_cb_bond = (void (*)(void))fp;
            break;
        case MMI_BT_SCR_CB_BOND_IND:
            bt_core_cntx_p->scr_cb_tbl.mmi_bt_scr_cb_bond_ind = (void (*)(MMI_BOOL))fp;
            break;
        case MMI_BT_SCR_CB_PAIR:
            bt_core_cntx_p->scr_cb_tbl.mmi_bt_scr_cb_pair = (void (*)(void))fp;
            break;
        case MMI_BT_SCR_CB_PAIR_RESULT:
            bt_core_cntx_p->scr_cb_tbl.mmi_bt_scr_cb_pair_result = (void (*)(MMI_BOOL))fp;
            break;
    #if defined(__MMI_BT_MTK_SUPPORT__)
        case MMI_BT_SCR_CB_CONNECT_ACCEPT_CNF:
            bt_core_cntx_p->scr_cb_tbl.mmi_bt_scr_cb_connect_accept_cnf_req =
                (void (*)(U8 *, U32, U8, U16, U32, U32))fp;
            break;
    #endif /* defined(__MMI_BT_MTK_SUPPORT__) */ 
        case MMI_BT_SCR_CB_CONNECT:
            bt_core_cntx_p->scr_cb_tbl.mmi_bt_scr_cb_connect = (void (*)(U32, MMI_BOOL))fp;
            break;
        case MMI_BT_SCR_CB_CONNECT_AUTHORISE_IND:
            bt_core_cntx_p->scr_cb_tbl.mmi_bt_scr_cb_connect_authorise_ind =
                (void (*)(U8 *, /* mmi_bt_dev_addr, */ U32, U32))fp;
            break;
        case MMI_BT_SCR_CB_DISCONNECT:
            bt_core_cntx_p->scr_cb_tbl.mmi_bt_scr_cb_disconnect = (void (*)(U32, MMI_BOOL))fp;
            break;
        case MMI_BT_SCR_CB_REFRESH_PROF:
            bt_core_cntx_p->scr_cb_tbl.mmi_bt_scr_cb_refresh_prof_list = (void (*)(MMI_BOOL))fp;
            break;
        case MMI_BT_SCR_CB_MYDEV_CONNECT:
            bt_core_cntx_p->scr_cb_tbl.mmi_bt_scr_cb_mydev_connect = (void (*)(MMI_BOOL))fp;
            break;
        case MMI_BT_SCR_CB_MYDEV_RENAME:
            bt_core_cntx_p->scr_cb_tbl.mmi_bt_scr_cb_mydev_rename = (void (*)(MMI_BOOL))fp;
            break;
        case MMI_BT_SCR_CB_MYDEV_AUTH:
            bt_core_cntx_p->scr_cb_tbl.mmi_bt_scr_cb_mydev_auth = (void (*)(MMI_BOOL))fp;
            break;
        case MMI_BT_SCR_CB_MYDEV_DEL:
            bt_core_cntx_p->scr_cb_tbl.mmi_bt_scr_cb_mydev_del = (void (*)(MMI_BOOL))fp;
            break;
        case MMI_BT_SCR_CB_MYDEV_DEL_ALL:
            bt_core_cntx_p->scr_cb_tbl.mmi_bt_scr_cb_mydev_del_all = (void (*)(MMI_BOOL))fp;
            break;
        case MMI_BT_SCR_CB_SET_VIS_REQ:
            bt_core_cntx_p->scr_cb_tbl.mmi_bt_scr_cb_set_vis = (void (*)(MMI_BOOL))fp;
            break;
        case MMI_BT_SCR_CB_SET_NAME_REQ:
            bt_core_cntx_p->scr_cb_tbl.mmi_bt_scr_cb_set_name = (void (*)(MMI_BOOL))fp;
            break;
        case MMI_BT_SCR_CB_SET_AUTH_REQ:
            bt_core_cntx_p->scr_cb_tbl.mmi_bt_scr_cb_set_auth = (void (*)(MMI_BOOL))fp;
            break;
        case MMI_BT_SCR_CB_SET_AUD_PTH_2_HF:
            bt_core_cntx_p->scr_cb_tbl.mmi_bt_scr_cb_set_aud_pth_2_hf = (void (*)(MMI_BOOL))fp;
		#if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_SIMAP_SUPPORT__)
        case MMI_BT_SCR_CB_SET_SIMAP_REQ:
            bt_core_cntx_p->scr_cb_tbl.mmi_bt_scr_cb_set_simap = (void (*)(MMI_BOOL))fp;
            break;
		#endif            
        case MMI_BT_SCR_CB_ERROR:
            bt_core_cntx_p->scr_cb_tbl.mmi_bt_scr_cb_error = (void (*)(void))fp;
            break;
        case MMI_BT_SCR_CB_SCO_IND:
            bt_core_cntx_p->scr_cb_tbl.mmi_bt_scr_cb_sco_ind = (void (*)(MMI_BOOL))fp;
            break;
        case MMI_BT_SCR_CB_PANIC_IND:
            bt_core_cntx_p->scr_cb_tbl.mmi_bt_scr_cb_panic_ind = (void (*)(void))fp;
            break;
        case MMI_BT_SCR_CB_DISPLAY_POPUP:
            bt_core_cntx_p->scr_cb_tbl.mmi_bt_scr_cb_display_popup = (void (*)(U8 *, U16, U8, U32, U8))fp;
            break;
        case MMI_BT_SCR_CB_SHOW_PROGRESSING:
            bt_core_cntx_p->scr_cb_tbl.mmi_bt_scr_cb_show_progress_scr =
                (void (*)(U16, U16, U16, U16 *, MMI_BOOL, FuncPtr))fp;
            break;
	    #if defined(__MMI_BT_MTK_SUPPORT__)
        case MMI_BT_SCR_CB_UPDATE_STATUS_ICON:
            bt_core_cntx_p->scr_cb_tbl.mmi_bt_scr_cb_update_status_icon = (void (*)(void))fp;
            break;
    	#endif /* defined(__MMI_BT_MTK_SUPPORT__) */ 

        default:
            MMI_BT_ASSERT(0);
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_start_hf_ring_req
 * DESCRIPTION
 *  This function is to start out-of-band ring.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bt_start_hf_ring_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_stop_hf_ring_req
 * DESCRIPTION
 *  This function is to stop out-of-band ring.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bt_stop_hf_ring_req(void)
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_is_aud2hf
 * DESCRIPTION
 *  This function is to query bluetooth audio path setting
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bt_is_aud2hf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_hs_connected)
    {
        if ((*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_hs_connected) ())
        {
            result = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_aud_pth_set_to_hf) ();
        }
        else
        {
            result = MMI_FALSE;
        }
    }
    else
    {
        result = MMI_FALSE;
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_is_incall_aud_swap2bt
 * DESCRIPTION
 *  This function is to query current bluetooth audio route
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bt_is_incall_aud_swap2bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_incall_aud_swap2bt)
    {
        return (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_incall_aud_swap2bt) ();
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_is_hs_connected
 * DESCRIPTION
 *  This function is to check if any bt headset connected
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bt_is_hs_connected(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_hs_connected)
    {
        return (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_hs_connected) ();
    }
    else
    {
        return MMI_FALSE;
    }

}
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_is_hf_car_kit_connected
 * DESCRIPTION
 *  This function is to check if the cod of connected handsfree profile is car-kit
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bt_is_hf_car_kit_connected(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 act_con_num;
    U8 paired_dev_num;
    U8 act_con_index, paired_dev_index;
    mmi_bt_connect_struct *conn_p;
    mmi_bt_dev_struct *dev_p;
    U32 cod_hf_car_kit;
    MMI_BOOL result = MMI_FALSE; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    act_con_num = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_existed_dev_num) ();
    paired_dev_num = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_num) ();

    act_con_index = 0;
    while (act_con_index < act_con_num)
    {

        conn_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_existed_conn_info) ((U16) act_con_index);
        if (conn_p->active == MMI_TRUE && conn_p->conn_type == MMI_BT_HFP_CONNECTION)
        {
            paired_dev_index = conn_p->index_of_paried_list;
            MMI_BT_ASSERT(paired_dev_index < paired_dev_num);
            dev_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_info) (paired_dev_index);
            cod_hf_car_kit = (MMI_BT_HANDSFREE_AV_MINOR_DEVICE_CLASS | MMI_BT_AV_MAJOR_DEVICE_MASK); 
            if((dev_p->cod & cod_hf_car_kit) == cod_hf_car_kit)
            {
                result = MMI_TRUE;
                break;
            }


        }
        act_con_index++;
    }

    return result;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_is_hfp_audio_link_connected
 * DESCRIPTION
 *  This function is to check if hfp/hsp audio link connected
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bt_is_hfp_audio_link_connected(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_hfp_audio_link_connected)
    {
        return (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_hfp_audio_link_connected) ();
    }
    else
    {
        return MMI_FALSE;
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_is_doing_far_end_loopback_test
 * DESCRIPTION
 *  This function is to check if bt is doing far end LP test
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_bt_is_doing_far_end_loopback_test(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_bt_scr_cntx.flag & MMI_BT_SCO_FAR_END_LP_TESTING)
    {
        result = MMI_TRUE;
    }

    return result;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_is_simap_server_activate
 * DESCRIPTION
 *  This function is to check if simap server is activated or not
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_bt_is_simap_server_activate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_SIMAP_SUPPORT__)
    result = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_simap_activate)();
    #endif

    return result;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_is_device_paired
 * DESCRIPTION
 *  This function is to check if device is still paired or trusted
 * PARAMETERS
 *  lap       [IN]        BT device address    
 *  uap       [IN]        BT device address
 *  nap       [IN]        BT device address
 * RETURNS
 *  MMI_BOOL  MMI_TRUE meaans paired/trusted, MMI_FALSE means un-paired/un-trusted
 *****************************************************************************/
MMI_BOOL mmi_bt_is_device_paired(U32 lap, U8 uap, U16 nap)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL result = MMI_FALSE;
	U8 nItems;
    U32 i;
    mmi_bt_dev_struct *dev_struct_p;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_IS_DEVICE_PAIRED, lap, uap, nap);

    /* Get trust device info */
    nItems = (U8) g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_num();


    for (i = 0; i < nItems; i++)
    {
        dev_struct_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_info) ((U16)i);

    	MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_PAIRED_DEVICE, 
			dev_struct_p->bd_addr.lap, 
			dev_struct_p->bd_addr.uap, 
			dev_struct_p->bd_addr.nap);

		if (lap == dev_struct_p->bd_addr.lap && 
			uap == dev_struct_p->bd_addr.uap && 
			nap == dev_struct_p->bd_addr.nap)
		{
			result = MMI_TRUE;
			break;
		}
			
    }


	return result;


}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_turn_on_speech_req
 * DESCRIPTION
 *  This function is to turn bluetooth speech
 * PARAMETERS
 *  speech_on       [IN]            
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bt_turn_on_speech_req(MMI_BOOL speech_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_turn_on_speech_req)
    {
        return (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_turn_on_speech_req) (speech_on);
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_pwroff
 * DESCRIPTION
 *  This function is to power off bt chip
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_pwroff(void)
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
 *  mmi_bt_switch_voice_path_incall
 * DESCRIPTION
 *  This function is to switch voice path in call active state
 * PARAMETERS
 *  is_on       [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_bt_switch_voice_path_incall(MMI_BOOL is_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_switch_voice_path_incall)
    {
        return (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_switch_voice_path_incall) (is_on);
    }
    else
    {
        return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_reset_hw_on
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_reset_hw_on(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reinit BT */
    mmi_bt_init();

    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_SCR_HW_ON,
               mmi_bt_is_hw_ready(MMI_FALSE), (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_pwron) ());
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_SCR_STATUS,
               g_mmi_bt_scr_cntx.state, g_mmi_bt_scr_cntx.flag, g_mmi_bt_scr_cntx.blinking_flag);

#ifndef __MMI_BT_BG_PWRON__
    if ((*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_pwron) () == MMI_TRUE)
    {
        /* set bt screen flag */
        g_mmi_bt_scr_cntx.flag |= MMI_BT_RESET_HW_ON;

        /* turn on BT power */
        /* wait for mmi_antenna_on_rsp to reset bt ready ram flag  */
        (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_antenna_on_req) ();
    }
    else
    {
        /* indication flight mode app that bt power on is called */
          #ifdef __MMI_DUAL_SIM_MASTER__
          DualModeSwitchCompleteUpdateStatus(); //mmi_phnset_flight_mode_selection_finish();
	 	  #else
		  #ifdef __FLIGHT_MODE_SUPPORT__
          mmi_phnset_switch_flight_mode();
	 	  #endif
		  #endif
    }
#else /* __MMI_BT_BG_PWRON__ */ 
    /* turn on BT power */
    /* wait for antenna_on_rsp to reset bt ready ram flag  */
    (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_antenna_on_req) ();
    /* indication flight mode app that bt power on is called */
          #ifdef __MMI_DUAL_SIM_MASTER__
          DualModeSwitchCompleteUpdateStatus(); //mmi_phnset_flight_mode_selection_finish();
	 	  #else
          #ifdef __FLIGHT_MODE_SUPPORT__
          mmi_phnset_switch_flight_mode(); //mmi_phnset_flight_mode_selection_finish();
		  #endif
	 	  #endif
#endif /* __MMI_BT_BG_PWRON__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_reset_hw_off
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_reset_hw_off(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if bt is initialized */
    if (g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_pwron == NULL)
    {
        return;
    }

    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_SCR_HW_OFF,
               mmi_bt_is_hw_ready(MMI_FALSE),
               (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_any_connection_active) (),
               (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_pwron) ());
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_SCR_STATUS,
               g_mmi_bt_scr_cntx.state, g_mmi_bt_scr_cntx.flag, g_mmi_bt_scr_cntx.blinking_flag);

    if (!mmi_bt_is_hw_ready(MMI_FALSE))
    {
        MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_HW_READY_TIMER_START);
        StartTimer(BT_WAIT_HW_READY_TIMER, MMI_BT_HW_READY_TIMER_DUR, mmi_bt_reset_hw_off);
    }
    else
    {
        /* set bt screen flag */
        g_mmi_bt_scr_cntx.flag |= MMI_BT_RESET_HW_OFF;

        /* it is to handle reset HW off command */
        /* 1. release all connection */
        /* 2. deactivate all service */
        /* 3. send antenna off req */
        if ((*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_pwron) () == MMI_TRUE &&
            (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_ram_flag) (MMI_BT_RAMMASK_IS_READY))
        {

            {
                /* if any connection existed, then shall remove connection first */
                /* after receiving release all conn complete cfm, shall deactive profiles */
                /* if no connection existed, then deactive profiles directly */
                /* deactivate all services */
                (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_deactivate_req) ();
                /* start a power off timer to guard the power off period */
                /* if bt core doesnot reply the rsp of profile deactivation req in MMI_BT_BT_POWER_OFF_GUARD_TIMER_DUR seconds, */
                /* then send antenna off req to bt core to force to power off bt chip */
                StartTimer(
                    BT_POWER_OFF_GUARD_TIMER,
                    MMI_BT_BT_POWER_OFF_GUARD_TIMER_DUR,
                    mmi_bt_power_off_guard_timeout_hdler);

            }
        }
        else
        {
        #ifdef __MMI_BT_BG_PWRON__
            /* if bt is activated, then shall deactive BT first */
            /* after receiving deactivated cfm, shall turn of BT power */
            /* if bt is not activated, then turn of BT power directly */
            /* turn off BT power */
            /* wait for antenna_off_rsp to reset bt ready ram flag  */
            (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_antenna_off_req) ();
        #endif /* __MMI_BT_BG_PWRON__ */ 
            /* reset scr flag */
            mmi_bt_reset_scr_flag();
            /* indicate flight mode that bt power off action is finished */
            #ifdef __MMI_DUAL_SIM_MASTER__
            DualModeSwitchCompleteUpdateStatus(); //mmi_phnset_flight_mode_selection_finish();
	 	    #else
	 	    #ifdef __FLIGHT_MODE_SUPPORT__
            mmi_phnset_switch_flight_mode(); //mmi_phnset_flight_mode_selection_finish();
            #endif
            #endif
        }

        /* hide status icon */
        if (!isEarphonePlugged)
        {
            HideStatusIcon(STATUS_ICON_EARPHONE_INDICATOR);
        }

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_inquiry_opp_dev
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_inquiry_opp_dev(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 max_response;
    U16 timeout;
    U32 cod;
    MMI_BOOL name_discovery;
    U16 title_str_id;
    U8 inquiry_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((mmi_bt_is_hw_ready) (MMI_TRUE) == MMI_FALSE)
    {
        return;
    }

    /* to avoid the error operation while bt module is busy */
    if ((mmi_bt_is_permission) (MMI_TRUE) == MMI_FALSE)
    {
        return;
    }

#ifdef __MMI_BT_PROHIBIT_OPP__
    if (mmi_bt_is_a2dp_connected())
    {
        DisplayPopup(
            (U8*) GetString(STR_BT_PROHIBIT_BY_A2DP),
            IMG_GLOBAL_ERROR,
            MMI_FALSE,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
        return;
    }
#endif /* __MMI_BT_PROHIBIT_OPP__ */ 


    if ( mmi_profiles_bt_is_connected((U8)MMI_PROFILES_BT_HFP_SCO) &&  isInCall())
    {
    	#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#endif 
   	    mmi_bt_popup_operation_not_allowed();
        return;
    }


    title_str_id = STR_BT_SCH_ALL_DEV;  

    if ((*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_pwron) () == MMI_FALSE)
    {
        mmi_bt_open();
        /* set bt screen flag */
        g_mmi_bt_scr_cntx.flag |= MMI_BT_AUTO_POWER_SWITCHIING;
        g_mmi_bt_scr_cntx.flag |= MMI_BT_INQ_TYPE_OPP_DEV;
        /* start inqiry after bt activating successfully */
        mmi_bt_show_progress_scr(
            SCR_BT_SCH_PRO,
            title_str_id,
            STR_BT_SEARCHING,
            NULL,
            MMI_TRUE,
            mmi_bt_inq_result_cancel);
        /* mmi_bt_reg_scr_cb( MMI_BT_SCR_CB_ACTIVATE, (void *)mmi_bt_power_switch_on_complete ); */

    }
    else
    {

        #if defined(__MMI_BT_AUDIO_VIA_SCO__) || defined(__MMI_BT_FM_VIA_SCO__)
        //if(mmi_profiles_bt_is_connected((U8)MMI_PROFILES_BT_HFP_SCO))
        {
            if(mmi_profiles_bt_inquery_start_callback(mmi_bt_inquiry_opp_dev))
            {
                return;
            }
        }
        #endif
    
        max_response = MMI_BT_MAX_INQUIRY_RESULTS_IN_LIST;
        timeout = MMI_BT_INQUIRY_TIMEOUT_DURATION;
        cod = MMI_BT_OBJECT_TRANSFER_MAJOR_SERVICE_MASK;
        name_discovery = MMI_TRUE;
        inquiry_type = MMI_BT_INQ_TYPE_OPP_DEV;
        g_mmi_bt_scr_cntx.flag |= MMI_BT_INQ_TYPE_OPP_DEV;
        mmi_bt_inquiry(max_response, timeout, cod, name_discovery, title_str_id, inquiry_type);
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_inquiry_a2dp_dev
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_inquiry_a2dp_dev(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 max_response;
    U16 timeout;
    U32 cod;
    MMI_BOOL name_discovery;
    U16 title_str_id;
    U8 inquiry_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((mmi_bt_is_hw_ready) (MMI_TRUE) == MMI_FALSE)
    {
        return;
    }

    /* to avoid the error operation while bt module is busy */
    if ((mmi_bt_is_permission) (MMI_TRUE) == MMI_FALSE)
    {
        return;
    }



    title_str_id = STR_BT_SCH_ALL_DEV;  /* STR_BT_SCH_ALL_DEV; */

    if ((*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_pwron) () == MMI_FALSE)
    {
        mmi_bt_open();
        /* set bt screen flag */
        g_mmi_bt_scr_cntx.flag |= MMI_BT_AUTO_POWER_SWITCHIING;
        g_mmi_bt_scr_cntx.flag |= MMI_BT_INQ_TYPE_A2DP_DEV;
        mmi_bt_show_progress_scr(
            SCR_BT_SCH_PRO,
            title_str_id,
            STR_BT_SEARCHING,
            NULL,
            MMI_TRUE,
            mmi_bt_inq_result_cancel);

    }
    else
    {
        #if defined(__MMI_BT_AUDIO_VIA_SCO__) || defined(__MMI_BT_FM_VIA_SCO__)
        //if(mmi_profiles_bt_is_connected((U8)MMI_PROFILES_BT_HFP_SCO))
        {
            if(mmi_profiles_bt_inquery_start_callback(mmi_bt_inquiry_a2dp_dev))
            {
                return;
            }
        }
        #endif
    
        max_response = MMI_BT_MAX_INQUIRY_RESULTS_IN_LIST;
        timeout = MMI_BT_INQUIRY_TIMEOUT_DURATION;
		/* for a2dp src device, rendering bit is mandatory and av major device bit is recommended */
        cod = /*MMI_BT_AUDIO_MAJOR_SERVICE_MASK | */MMI_BT_RENDERING_MAJOR_SERVICE_MASK | MMI_BT_AV_MAJOR_DEVICE_MASK;
        name_discovery = MMI_TRUE;
        inquiry_type = (U8)MMI_BT_INQ_TYPE_A2DP_DEV;
        g_mmi_bt_scr_cntx.flag |= MMI_BT_INQ_TYPE_A2DP_DEV;
        mmi_bt_inquiry(max_response, timeout, cod, name_discovery, title_str_id, inquiry_type);
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_inquiry_remote_ctrl_dev
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_inquiry_remote_ctrl_dev(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 max_response;
    U16 timeout;
    U32 cod;
    MMI_BOOL name_discovery;
    U16 title_str_id;
    U8 inquiry_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((mmi_bt_is_hw_ready) (MMI_TRUE) == MMI_FALSE)
    {
        return;
    }

    /* to avoid the error operation while bt module is busy */
    if ((mmi_bt_is_permission) (MMI_TRUE) == MMI_FALSE)
    {
        return;
    }

    title_str_id = STR_BT_SCH_ALL_DEV;  /* STR_BT_SCH_ALL_DEV; */

    if ((*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_pwron) () == MMI_FALSE)
    {
        mmi_bt_open();
        /* set bt screen flag */
        g_mmi_bt_scr_cntx.flag |= MMI_BT_AUTO_POWER_SWITCHIING;
        g_mmi_bt_scr_cntx.flag |= MMI_BT_INQ_TYPE_HID_DEV;
        mmi_bt_show_progress_scr(
            SCR_BT_SCH_PRO,
            title_str_id,
            STR_BT_SEARCHING,
            NULL,
            MMI_TRUE,
            mmi_bt_inq_result_cancel);

    }
    else
    {

        #if defined(__MMI_BT_AUDIO_VIA_SCO__) || defined(__MMI_BT_FM_VIA_SCO__)
	    //if(mmi_profiles_bt_is_connected((U8)MMI_PROFILES_BT_HFP_SCO))
	    {
	       if (mmi_profiles_bt_inquery_start_callback(mmi_bt_inquiry_remote_ctrl_dev))
	       {
    		   return;
	       }
	    }
        #endif
    
        max_response = MMI_BT_MAX_INQUIRY_RESULTS_IN_LIST;
        timeout = MMI_BT_INQUIRY_TIMEOUT_DURATION;
        cod = MMI_BT_PERIPHERAL_MAJOR_DEVICE_MASK | MMI_BT_COMPUTER_MAJOR_DEVICE_MASK | MMI_BT_REMOTE_CONTRO_DEVICE_PERIPHERAL_MINOR_DEVICE_CLASS;
        name_discovery = MMI_TRUE;
        inquiry_type = (U8)MMI_BT_INQ_TYPE_HID_DEV;
        g_mmi_bt_scr_cntx.flag |= MMI_BT_INQ_TYPE_HID_DEV;
        mmi_bt_inquiry(max_response, timeout, cod, name_discovery, title_str_id, inquiry_type);
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_inquiry_printer_dev
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_inquiry_printer_dev(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 max_response;
    U16 timeout;
    U32 cod;
    MMI_BOOL name_discovery;
    U16 title_str_id;
    U8 inquiry_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((mmi_bt_is_hw_ready) (MMI_TRUE) == MMI_FALSE)
    {
        return;
    }

    /* to avoid the error operation while bt module is busy */
    if ((mmi_bt_is_permission) (MMI_TRUE) == MMI_FALSE)
    {
        return;
    }


    title_str_id = STR_BT_SCH_ALL_DEV;  /* STR_BT_SCH_ALL_DEV; */

    if ((*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_pwron) () == MMI_FALSE)
    {
        mmi_bt_open();
        /* set bt screen flag */
        g_mmi_bt_scr_cntx.flag |= MMI_BT_AUTO_POWER_SWITCHIING;
        g_mmi_bt_scr_cntx.flag_extended |= MMI_BT_EXT_INQ_TYPE_PRINTER_DEV;
        mmi_bt_show_progress_scr(
            SCR_BT_SCH_PRO,
            title_str_id,
            STR_BT_SEARCHING,
            NULL,
            MMI_TRUE,
            mmi_bt_inq_result_cancel);

    }
    else
    {

	    #if defined(__MMI_BT_AUDIO_VIA_SCO__) || defined(__MMI_BT_FM_VIA_SCO__)
	    //if(mmi_profiles_bt_is_connected((U8)MMI_PROFILES_BT_HFP_SCO))
	    {
	        if (mmi_profiles_bt_inquery_start_callback(mmi_bt_inquiry_printer_dev))
	        {
    		    return;
	        }
	    } 
	    #endif
	
        max_response = MMI_BT_MAX_INQUIRY_RESULTS_IN_LIST;
        timeout = MMI_BT_INQUIRY_TIMEOUT_DURATION;
        cod = MMI_BT_RENDERING_MAJOR_SERVICE_MASK | MMI_BT_IMAGING_MAJOR_DEVICE_MASK | MMI_BT_PRINTER_IMAGING_MINOR_DEVICE_CLASS;
        name_discovery = MMI_TRUE;
        inquiry_type = (U8)MMI_BT_EXT_INQ_TYPE_PRINTER_DEV;
        g_mmi_bt_scr_cntx.flag_extended |= MMI_BT_EXT_INQ_TYPE_PRINTER_DEV;
        mmi_bt_inquiry(max_response, timeout, cod, name_discovery, title_str_id, inquiry_type);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_inquiry_specific_cod_dev
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_inquiry_specific_cod_dev(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 max_response;
    U16 timeout;
    U32 cod;
    MMI_BOOL name_discovery;
    U16 title_str_id;
    U8 inquiry_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_INQUIRY_SPEC_COD_DEV, (g_mmi_bt_scr_cntx.select_device_cb));

    if ((mmi_bt_is_hw_ready) (MMI_TRUE) == MMI_FALSE)
    {
        return;
    }

    /* to avoid the error operation while bt module is busy */
    if ((mmi_bt_is_permission) (MMI_TRUE) == MMI_FALSE)
    {
        return;
    }

    title_str_id = STR_BT_SCH_ALL_DEV;  /* STR_BT_SCH_ALL_DEV; */

    if ((*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_pwron) () == MMI_FALSE)
    {
        mmi_bt_open();
        /* set bt screen flag */
        g_mmi_bt_scr_cntx.flag |= MMI_BT_AUTO_POWER_SWITCHIING;
        g_mmi_bt_scr_cntx.flag_extended |= MMI_BT_EXT_INQ_TYPE_SPEC_COD_DEV;
        mmi_bt_show_progress_scr(
            SCR_BT_SCH_PRO,
            title_str_id,
            STR_BT_SEARCHING,
            NULL,
            MMI_TRUE,
            mmi_bt_inq_result_cancel);

    }
    else
    {

	    #if defined(__MMI_BT_AUDIO_VIA_SCO__) || defined(__MMI_BT_FM_VIA_SCO__)
	    //if(mmi_profiles_bt_is_connected((U8)MMI_PROFILES_BT_HFP_SCO))
	    {
	        if (mmi_profiles_bt_inquery_start_callback(mmi_bt_inquiry_specific_cod_dev))
	        {
    	    	return;
	        }
	    }
	    #endif
	
        max_response = MMI_BT_MAX_INQUIRY_RESULTS_IN_LIST;
        timeout = MMI_BT_INQUIRY_TIMEOUT_DURATION;
        cod = g_mmi_bt_scr_cntx.specific_cod_mask;
        name_discovery = MMI_TRUE;
        inquiry_type = (U8)MMI_BT_EXT_INQ_TYPE_SPEC_COD_DEV;
        g_mmi_bt_scr_cntx.flag_extended |= MMI_BT_EXT_INQ_TYPE_SPEC_COD_DEV;
        mmi_bt_inquiry(max_response, timeout, cod, name_discovery, title_str_id, inquiry_type);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_open
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_open(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if bt is initialized */
    if (g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_pwron == NULL)
    {
        return;
    }

    /* check if power is on, if not, turn it on */
    if ((*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_pwron) () == MMI_FALSE)
    {
        (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_set_ram_flag_req) (MMI_BT_RAMMASK_IS_AUTO_PWR_SWTICH);
    #ifndef __MMI_BT_BG_PWRON__
        (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_set_flag_req) (MMI_BT_MASK_ACTIVATED);
        /* turn on BT power */
        /* wait for mmi_antenna_on_rsp to reset bt ready ram flag  */
        (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_antenna_on_req) ();
    #else /* __MMI_BT_BG_PWRON__ */ 
        (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_activate_req) ();
    #endif /* __MMI_BT_BG_PWRON__ */ 

    }
    /* blink the bluetooth status icon */
    /* mmi_bt_update_status_icon(); */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_close
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if auto power switching, if yes, turn it off */
    if ((*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_ram_flag) (MMI_BT_RAMMASK_IS_AUTO_PWR_SWTICH))
    {
        (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_reset_ram_flag_req) (MMI_BT_RAMMASK_IS_AUTO_PWR_SWTICH);
        if (!(*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_any_connection_active) ())
        {
            (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_deactivate_req) ();
        #ifndef __MMI_BT_BG_PWRON__
            g_mmi_bt_scr_cntx.flag |= MMI_BT_ANTENNA_OFF;
        #endif 
            /* start a power off timer to guard the power off period */
            /* if bt core doesnot reply the rsp of profile deactivation req in MMI_BT_BT_POWER_OFF_GUARD_TIMER_DUR seconds, */
            /* then send antenna off req to bt core to force to power off bt chip */
            StartTimer(
                BT_POWER_OFF_GUARD_TIMER,
                MMI_BT_BT_POWER_OFF_GUARD_TIMER_DUR,
                mmi_bt_power_off_guard_timeout_hdler);

        }
    }
    /* update bluetooth status icon--blinking */
    /* mmi_bt_update_status_icon(); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_get_hilight_index_of_discov_dev
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
U32 mmi_bt_get_hilight_index_of_discov_dev(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mmi_bt_scr_cntx.hilight_item;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_get_discoveryed_dev_info
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  index       [IN]            
 *  dev_p       [?]             
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bt_get_discoveryed_dev_info(U32 index, mmi_bt_dev_struct *dev_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    mmi_bt_dev_struct *discov_dev_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index >= (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_discov_dev_num) ())
    {
        result = MMI_FALSE;
    }
    else
    {
        discov_dev_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_discov_dev_info) ((U16) index);
        memcpy(dev_p, discov_dev_p, sizeof(mmi_bt_dev_struct));
        result = MMI_TRUE;
    }

    return result;
}

/* Higilight handler */


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_main_hilight_handler
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_main_hilight_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GENERIC_BT_HILIGHT_HDLR();
    /* Register entry function key handler */
    SetLeftSoftkeyFunction(mmi_bt_entry_main_menu, KEY_EVENT_UP);
    SetKeyHandler(mmi_bt_entry_main_menu, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_power_hilight_handler
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_power_hilight_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL bt_power;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_pwron) () && mmi_bt_is_hw_ready(MMI_FALSE) == MMI_TRUE)
    {
        bt_power = MMI_TRUE;
    }
    else
    {
        bt_power = MMI_FALSE;
    }

    GENERIC_BT_TOGGLE_HILIGHT_HDLR(bt_power, MMI_TRUE, MMI_FALSE);
    /* Register entry function key handler */
    SetLeftSoftkeyFunction(mmi_bt_entry_power_switch, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_sch_aud_dev_hilight_handler
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_sch_aud_dev_hilight_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GENERIC_BT_HILIGHT_HDLR();
    /* Register entry function key handler */
    SetLeftSoftkeyFunction(mmi_bt_entry_inq_aud_dev, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_mydev_hilight_handler
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_mydev_hilight_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GENERIC_BT_HILIGHT_HDLR();

    /* Register entry function key handler */
    SetLeftSoftkeyFunction(mmi_bt_entry_mydev_menu, KEY_EVENT_UP);
    SetKeyHandler(mmi_bt_entry_mydev_menu, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_act_dev_hilight_handler
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_act_dev_hilight_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GENERIC_BT_HILIGHT_HDLR();

    /* Register entry function key handler */
    SetLeftSoftkeyFunction(mmi_bt_entry_act_dev_menu, KEY_EVENT_UP);
    SetKeyHandler(mmi_bt_entry_act_dev_menu, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_set_hilight_handler
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_set_hilight_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GENERIC_BT_HILIGHT_HDLR();

    /* Register entry function key handler */
    SetLeftSoftkeyFunction(mmi_bt_entry_set_menu, KEY_EVENT_UP);
    SetKeyHandler(mmi_bt_entry_set_menu, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_set_vis_hilight_handler
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_set_vis_hilight_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = GetCurrHiliteID();

    /* prohibit visibility setting while a2dp is active */
    if (mmi_bt_is_a2dp_connected())
    {
        GENERIC_BT_TOGGLE_HILIGHT_HDLR(MMI_FALSE, MMI_TRUE, MMI_FALSE);
		Category52ChangeItemDescription((S32)index, (U8*) GetString(STR_GLOBAL_OFF));
    }
    else
    {
        GENERIC_BT_TOGGLE_HILIGHT_HDLR((*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_vis) (), MMI_TRUE, MMI_FALSE);
	    if ((*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_vis) () == MMI_TRUE )
	    {
	        Category52ChangeItemDescription((S32)index, (U8*) GetString(STR_GLOBAL_ON));
	    }
	    else
	    {
	        Category52ChangeItemDescription((S32)index, (U8*) GetString(STR_GLOBAL_OFF));
	    }
		
    }
    /* Register entry function key handler */
    SetLeftSoftkeyFunction(mmi_bt_entry_set_vis, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_set_name_hilight_handler
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_set_name_hilight_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GENERIC_BT_HILIGHT_HDLR();
    /* Register entry function key handler */
    SetLeftSoftkeyFunction(mmi_bt_entry_set_name, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_set_auth_hilight_handler
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_set_auth_hilight_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GENERIC_BT_TOGGLE_HILIGHT_HDLR((*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_auth) (), MMI_TRUE, MMI_FALSE);
    /* Register entry function key handler */
    SetLeftSoftkeyFunction(mmi_bt_entry_set_auth, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_set_aud_path_hilight_handler
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_set_aud_path_hilight_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GENERIC_BT_HILIGHT_HDLR();
    /* Register entry function key handler */
    SetLeftSoftkeyFunction(mmi_bt_entry_set_audio_pth_menu, KEY_EVENT_UP);
    SetKeyHandler(mmi_bt_entry_set_audio_pth_menu, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_set_aud_path_phone_hilight_handler
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_set_aud_path_phone_hilight_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    (g_mmi_bt_scr_cntx.hilight_item) = (U16) GetCurrHiliteID();
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_SCR_HIGHLIGHT_ITEM, (g_mmi_bt_scr_cntx.hilight_item));
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_set_aud_path_hf_hilight_handler
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_set_aud_path_hf_hilight_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    (g_mmi_bt_scr_cntx.hilight_item) = (U16) GetCurrHiliteID();
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_SCR_HIGHLIGHT_ITEM, (g_mmi_bt_scr_cntx.hilight_item));
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_set_simap_hilight_handler
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_set_simap_hilight_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GENERIC_BT_TOGGLE_HILIGHT_HDLR((*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_simap_activate) (), MMI_TRUE, MMI_FALSE);
    /* Register entry function key handler */
    SetLeftSoftkeyFunction(mmi_bt_entry_set_simap, KEY_EVENT_UP);
    return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_about_hilight_handler
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_about_hilight_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GENERIC_BT_HILIGHT_HDLR();
    /* Register entry function key handler */
    SetLeftSoftkeyFunction(mmi_bt_entry_about, KEY_EVENT_UP);
    return;
}

/* Hint handler */


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_power_hint_handler
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  index       [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_power_hint_handler(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PS8 hintStr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_pwron) () == MMI_TRUE && mmi_bt_is_hw_ready(MMI_FALSE) == MMI_TRUE)
    {
        hintStr = (PS8) GetString(STR_GLOBAL_ON);
    }
    else
    {
        hintStr = (PS8) GetString(STR_GLOBAL_OFF);
    }

    mmi_ucs2cpy((PS8) hintData[index], hintStr);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_set_vis_hint_handler
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  index       [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_set_vis_hint_handler(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PS8 hintStr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* prohibit visibility setting while a2dp is active */
    if ((*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_vis) () == MMI_TRUE && !mmi_bt_is_a2dp_connected())
    {
        hintStr = (PS8) GetString(STR_GLOBAL_ON);
    }
    else
    {
        hintStr = (PS8) GetString(STR_GLOBAL_OFF);
    }
    mmi_ucs2cpy((PS8) hintData[index], hintStr);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_set_auth_hint_handler
 * DESCRIPTION
 *  This function is for bt main menu
 * PARAMETERS
 *  index       [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_set_auth_hint_handler(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PS8 hintStr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_auth) () == MMI_TRUE)
    {
        hintStr = (PS8) GetString(STR_GLOBAL_ON);
    }
    else
    {
        hintStr = (PS8) GetString(STR_GLOBAL_OFF);
    }

    mmi_ucs2cpy((PS8) hintData[index], hintStr);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_set_name_hint_handler
 * DESCRIPTION
 *  This function is for bt main menu
 * PARAMETERS
 *  index       [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_set_name_hint_handler(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bt_dev_struct *host_dev_p;
    U8 utf8_char_cnt = 0;
    U8 ucs2_str_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    host_dev_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_host_dev_info) ();

    /* get byte count for convert utf8 string to UCS2 string */
    /* get character count of utf8 string */
    /* +1 is for UCS2 NULL terminate */
    /* *ENCODING_LENGTH is for byte count of one UCS2 character */
    utf8_char_cnt = (U8) ((mmi_chset_utf8_strlen((kal_uint8*) host_dev_p->name) + 1) * ENCODING_LENGTH);
    MMI_BT_ASSERT(MAX_SUB_MENU_HINT_SIZE >= MMI_BT_SCR_BD_NAME_LEN);
    if (utf8_char_cnt > MMI_BT_SCR_BD_NAME_LEN)
    {
        ucs2_str_len =
            (U8) mmi_chset_utf8_to_ucs2_string(
                    (kal_uint8*) hintData[index],
                    MMI_BT_SCR_BD_NAME_LEN,
                    (kal_uint8*) host_dev_p->name);
    }
    else
    {
        ucs2_str_len =
            (U8) mmi_chset_utf8_to_ucs2_string(
                    (kal_uint8*) hintData[index],
                    utf8_char_cnt,
                    (kal_uint8*) host_dev_p->name);
    }
	/* allow (MMI_BT_BD_NAME_LEN/3) chinese characters or (MMI_BT_BD_NAME_LEN/3)*2 english characters  */
	/* so for UCS2 encoding, need MMI_BT_SCR_BD_NAME_LEN bytes */

	/* shall check if there is any two_byte character mixed in one_bye UCS2 string */
	/* if yes, then truncate the string to meet above rules((MMI_BT_BD_NAME_LEN/3) chinese characters or (MMI_BT_BD_NAME_LEN/3)*2 english characters)*/	
	if(mmi_bt_test_ucs2((U16*)hintData[index], (U16)(ucs2_str_len/ENCODING_LENGTH)) )
	{ 
		mmi_bt_truncate_ucs2_string((U16*)hintData[index], 
		    							(U16)(ucs2_str_len/ENCODING_LENGTH),
		    							(U16)((MMI_BT_BD_NAME_LEN-2)/3)
		    						   );		    
	}

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_set_path_hint_handler
 * DESCRIPTION
 *  This function is for bt main menu
 * PARAMETERS
 *  index       [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_set_path_hint_handler(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PS8 hintStr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_aud_pth_set_to_hf) () == MMI_FALSE)
    {
        hintStr = (PS8) GetString(STR_BT_DEV_SET_AUDIO_PATH_PHONE);
    }
    else if ((*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_aud_pth_set_to_hf) () == MMI_TRUE)
    {
        hintStr = (PS8) GetString(STR_BT_DEV_SET_AUDIO_PATH_HF);
    }
    else
    {
        hintStr = (PS8) GetString(STR_GLOBAL_ERROR);
    }

    mmi_ucs2cpy((PS8) hintData[index], hintStr);

    return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_set_simap_hint_handler
 * DESCRIPTION
 *  This function is to hint simap status
 * PARAMETERS
 *  index       [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_set_simap_hint_handler(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PS8 hintStr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_simap_activate)() == MMI_TRUE)
    {
        hintStr = (PS8) GetString(STR_GLOBAL_ON);
    }
    else
    {
        hintStr = (PS8) GetString(STR_GLOBAL_OFF);
    }

    mmi_ucs2cpy((PS8) hintData[index], hintStr);
    return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_on_off_stress_testing
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_on_off_stress_testing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static U32 bt_on_off_test_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_ON_OFF_STRESS_TEST, (g_mmi_bt_scr_cntx.flag), (bt_on_off_test_count));

    g_mmi_bt_scr_cntx.flag |= MMI_BT_ANTENNA_ON_OFF_STRESS_TEST;

    if (bt_on_off_test_count < 1000)
    {
        mmi_bt_entry_power_switch();
        bt_on_off_test_count++;
    }
    else
    {
        /* mmi_bt_reset_scr_flag(); */
        g_mmi_bt_scr_cntx.flag &= ~MMI_BT_ANTENNA_ON_OFF_STRESS_TEST;
        bt_on_off_test_count = 0;
    }

}

/* Entry function */


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_main_menu
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_main_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];    /* Stores the strings id of submenus returned */
    U16 nNumofItem;                     /* Stores no of children in the submenu */
    U16 nDispAttribute;                 /* Stores display attribue */
    U8 *guiBuffer;                      /* Buffer holding history data */
    U8 *HintList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __FLIGHT_MODE_SUPPORT__
    if (mmi_bootup_get_active_flight_mode() != 0)
    {
        /* prevent from entry BT main menu from shortcut */
        DisplayPopup(
            (U8*) GetString(STR_MENU_FLIGHT_MODE),
            IMG_GLOBAL_ERROR,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
        return;
    }
#endif /* __FLIGHT_MODE_SUPPORT__ */

    if ((mmi_bt_is_hw_ready) (MMI_TRUE) == MMI_FALSE)
    {
        return;
    }

    /* 1 Call Exit Handler */
    EntryNewScreen(SCR_BT_MAIN, NULL, mmi_bt_entry_main_menu, NULL);

    /* 2 Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_BT_MAIN);

    /* 3. Retrieve no of child of menu item to be displayed */
    nNumofItem = GetNumOfChild(MENU_CONN_BT_MAIN);

    /* 4. Get attribute of menu to be displayed */
    nDispAttribute = GetDispAttributeOfItem(MENU_CONN_BT_MAIN);

    /* 5. Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds(MENU_CONN_BT_MAIN, nStrItemList);

    /* 6 Set current parent id */
    SetParentHandler(MENU_CONN_BT_MAIN);

    /* 7 Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* 8 Construct the Hints List */
    ConstructHintsList(MENU_CONN_BT_MAIN, HintList);

    /* 9. Display Category screen */

    ShowCategory52Screen(
        STR_BT_MENU_TITLE,
        //MAIN_MENU_TITLE_EXTRA_APP_ICON,
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (PU16) gIndexIconsImageList,
        HintList,
        0,
        0,
        guiBuffer);

    /* 10.Highlight handler will register function with softkey */
    /*
     * SetLeftSoftkeyFunction( ,KEY_EVENT_UP);
     * SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
     * SetRightSoftkeyFunction(GoBackHistory,KEY_EVENT_UP);
     * SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
     */
#ifdef MMI_BT_ON_OFF_STRESS_TEST
    SetKeyHandler(mmi_bt_on_off_stress_testing, KEY_ENTER, KEY_EVENT_DOWN);
#endif 

}

/*****************************************************************************
* FUNCTION
*  mmi_bt_exit_main_menu
* DESCRIPTION
*  This function is  
*
* PARAMETERS
*  a  IN/OUT   first variable, used as returns
*  b  IN       second variable
* RETURNS
*  NONE.  
* GLOBALS AFFECTED
*  external_global
*****************************************************************************/
void mmi_bt_exit_main_menu(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_power_switch
 * DESCRIPTION
 *  This function is to activate or deactivate bt function
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_power_switch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_SCR_STATUS,
               g_mmi_bt_scr_cntx.state, g_mmi_bt_scr_cntx.flag, g_mmi_bt_scr_cntx.blinking_flag);

    /* reset del cb for power on confirm window */
    SetDelScrnIDCallbackHandler(SCR_BT_REMOTE_CONTROL_POWER_ON_CONFIRM, (HistoryDelCBPtr) NULL);

    /* to avoid the twice operation*/
    if (g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_SWITCH_POWER_OFF)
    {
        g_mmi_bt_scr_cntx.flag &= ~MMI_BT_CONFIRM_SWITCH_POWER_OFF;    
        StopTimer(BT_POPUP_TIMER);
    }


    if ((mmi_bt_is_hw_ready) (MMI_TRUE) == MMI_FALSE)
    {
        mmi_bt_delete_screen(SCR_BT_POWER_ON_CNF, MMI_FALSE);
        return;
    }

    /* to avoid the error operation while bt module is busy */
    if ((mmi_bt_is_permission) (MMI_TRUE) == MMI_FALSE)
    {
        mmi_bt_delete_screen(SCR_BT_POWER_ON_CNF, MMI_FALSE);
        return;
    }

    state = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_state) ();

    /* to avoid to switch power at switing state */
    switch (state)
    {
        case MMI_BT_STAT_DEACTIVATING:
        case MMI_BT_STAT_ACTIVATE_SWITCHING:
            return;
            break;
        default:
            break;
    }

    if ((*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_pwron) () == MMI_TRUE)
    {
      /******************************/
        /* Switch power off */
      /******************************/
        MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_SCR_PWROFF);

        #if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_A2DP_SUPPORT__)
        mmi_audply_bt_power_off_callback( MMI_TRUE );
        #endif


        mmi_bt_show_progress_scr(SCR_BT_POWER_PRO, STR_BT_POWER, STR_BT_SWITCHING, NULL, MMI_FALSE, NULL);

        /* deactivate bluetooth services */
        (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_deactivate_req) ();
    #ifndef __MMI_BT_BG_PWRON__
        g_mmi_bt_scr_cntx.flag |= MMI_BT_ANTENNA_OFF;
    #endif 
        /* start a power off timer to guard the power off period */
        /* if bt core doesnot reply the rsp of profile deactivation req in MMI_BT_BT_POWER_OFF_GUARD_TIMER_DUR seconds, */
        /* then send antenna off req to bt core to force to power off bt chip */
        StartTimer(BT_POWER_OFF_GUARD_TIMER, MMI_BT_BT_POWER_OFF_GUARD_TIMER_DUR, mmi_bt_power_off_guard_timeout_hdler);

    }
    else
    {
      /******************************/
        /* Switch power on */
      /******************************/
        MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_SCR_PWRON_PROC);
        mmi_bt_show_progress_scr(SCR_BT_POWER_PRO, STR_BT_POWER, STR_BT_SWITCHING, NULL, MMI_FALSE, NULL);

    #ifndef __MMI_BT_BG_PWRON__
        (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_set_flag_req) (MMI_BT_MASK_ACTIVATED);

        /* turn on BT power */
        /* wait for mmi_antenna_on_rsp to reset bt ready ram flag  */
        (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_antenna_on_req) ();
    #else /* __MMI_BT_BG_PWRON__ */ 
        /* deactivate bluetooth services */
        (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_activate_req) ();
    #endif /* __MMI_BT_BG_PWRON__ */ 

    }

}

/*****************************************************************************
* FUNCTION
*  mmi_bt_exit_power_switch
* DESCRIPTION
*  This function is  
*
* PARAMETERS
*  a  IN/OUT   first variable, used as returns
*  b  IN       second variable
* RETURNS
*  NONE.  
* GLOBALS AFFECTED
*  external_global
*****************************************************************************/
void mmi_bt_exit_power_switch(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_power_off_guard_timeout_hdler
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_power_off_guard_timeout_hdler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_SCR_POWER_OFF_GUARD_TIMEOUT,
               (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_state) ());
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_SCR_STATUS,
               g_mmi_bt_scr_cntx.state, g_mmi_bt_scr_cntx.flag, g_mmi_bt_scr_cntx.blinking_flag);

#ifdef __MMI_BT_BG_PWRON__
    /* reset BT power */
    /* wait for re-start ind req  */
    (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_restart_bt_module_req) ();
    /* shall not go back history */
    mmi_bt_stop_progress_scr(MMI_FALSE);
    /* reset scr flag */
    mmi_bt_reset_scr_flag();
    /* reset extend proc timer */
    g_mmi_bt_scr_cntx.extend_proc_timer = 0;
    /* lead user to bluetooth main menu */
    mmi_bt_del_scr(SCR_BT_MAIN, SCR_BT_ABOUT);
    GoBackHistory();
#else /* __MMI_BT_BG_PWRON__ */ 
    (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_reset_flag_req) (MMI_BT_MASK_ACTIVATED);
    (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_set_state) ((U32) MMI_BT_STAT_IDLE);
    (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_nvram_write_info) ();
    mmi_bt_init();
    /* shall not go back history */
    mmi_bt_stop_progress_scr(MMI_FALSE);
    (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_antenna_off_req) ();
    /* reset scr flag */
    g_mmi_bt_scr_cntx.flag &= ~MMI_BT_ANTENNA_OFF;
#endif /* __MMI_BT_BG_PWRON__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_release_all_connections
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_release_all_connections(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_SCR_STATUS,
               g_mmi_bt_scr_cntx.state, g_mmi_bt_scr_cntx.flag, g_mmi_bt_scr_cntx.blinking_flag);
    
    if ((*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_release_all_connection_req) () == MMI_FALSE)
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_ERROR),
            IMG_GLOBAL_ERROR,
            MMI_FALSE,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
        mmi_bt_delete_screen(SCR_BT_RELEASE_ALL_CONN_CNF, MMI_FALSE);
        
    }
    else
    {
        mmi_bt_show_progress_scr(
            SCR_BT_REL_ALL_CONN_PRO,
            STR_BT_RELEASE_ALL_CONN,
            STR_BT_RELEASING,
            NULL,
            MMI_FALSE,
            NULL);
		/* start a release all connection timer to guard the releasing all connections period */	
		/* if bt core doesnot reply the rsp of profile disconnect req in MMI_BT_BT_RELEASE_ALL_CONN_GUARD_TIMER_DUR seconds, */
		/* then send reset to bt core */
		StartTimer( BT_RELEASE_ALL_CON_GUARD_TIMER, MMI_BT_BT_RELEASE_ALL_CONN_GUARD_TIMER_DUR, mmi_bt_release_all_conn_guard_timeout_goback_history_hdler);

#if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_A2DP_SUPPORT__)
        mmi_audply_bt_delete_device_callback(NULL);
#endif
    }

    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_release_all_conn_complete
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  result      [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_release_all_conn_complete(MMI_BOOL result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 state;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(BT_RELEASE_ALL_CON_GUARD_TIMER);

    mmi_bt_update_status_icon();

    /* it is to handle reset HW off command */
    /* 1. release all connection */
    /* 2. deactivate all service */
    /* 3. send antenna off req */
    if (g_mmi_bt_scr_cntx.flag & MMI_BT_RESET_HW_OFF)
    {
        /* deactivate all services */
        (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_deactivate_req) ();
        /* start a power off timer to guard the power off period */
        /* if bt core doesnot reply the rsp of profile deactivation req in MMI_BT_BT_POWER_OFF_GUARD_TIMER_DUR seconds, */
        /* then send antenna off req to bt core to force to power off bt chip */
        StartTimer(BT_POWER_OFF_GUARD_TIMER, MMI_BT_BT_POWER_OFF_GUARD_TIMER_DUR, mmi_bt_power_off_guard_timeout_hdler);
        return;
    }

    /* stop progressing */
    mmi_bt_stop_progress_scr(MMI_FALSE);
    if (result == MMI_TRUE)
    {
        DisplayPopup(
            (U8*) GetString(STR_BT_CON_RELEASED),
            IMG_GLOBAL_ACTIVATED,
            MMI_FALSE,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) SUCCESS_TONE);
    }
    else
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_ERROR),
            IMG_GLOBAL_ERROR,
            MMI_FALSE,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
    }

    DeleteScreenIfPresent(SCR_BT_REL_ALL_CONN_PRO);
    DeleteScreenIfPresent(SCR_BT_REL_DEV_CONN_PRO);

    state = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_state) ();

	/* to make sure that HID screens are removed */
	if (state == MMI_BT_STAT_RELEASE_ALL_CONNECTION)
	{
		#if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_HIDD_SUPPORT__)
		SetDelScrnIDCallbackHandler(SCR_BT_REMOTE_CONTROL_DEV_SELECT, (HistoryDelCBPtr) NULL);
		mmi_bt_del_scr(SCR_BT_REMOTE_CONTROL, SCR_BT_REMOTE_CONTROL_DISCONNECT_CONFIRM);
		#endif
	}

    if (g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_SWITCH_POWER_OFF)
    {
        StartTimer(BT_POPUP_TIMER, MMI_BT_BT_POPUP_TIMER_DUR, mmi_bt_entry_power_switch);
        /* delete the release all connection confirm screen */
        mmi_bt_delete_screen(SCR_BT_RELEASE_ALL_CONN_CNF, MMI_FALSE);

    }
    else if (g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_PAIRED_DEV_DEL)
    {
        StartTimer(BT_POPUP_TIMER, MMI_BT_BT_POPUP_TIMER_DUR, mmi_bt_entry_mydev_del);
        /* delete the release all connection confirm screen */
        mmi_bt_delete_screen(SCR_BT_RELEASE_DEV_CONN_CNF, MMI_FALSE);

    }
    else if (g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_PAIRED_DEV_DEL_ALL)
    {
        StartTimer(BT_POPUP_TIMER, MMI_BT_BT_POPUP_TIMER_DUR, mmi_bt_entry_mydev_del_all);
        /* delete the release all connection confirm screen */
        mmi_bt_delete_screen(SCR_BT_RELEASE_ALL_CONN_CNF, MMI_FALSE);
        
    }
    else if (g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_SIMAP_SET)
    {
        StartTimer(BT_POPUP_TIMER, MMI_BT_BT_POPUP_TIMER_DUR, mmi_bt_entry_set_simap);
        /* delete the release all connection confirm screen */
        mmi_bt_delete_screen(SCR_BT_RELEASE_ALL_CONN_CNF, MMI_FALSE);

    }
}

/*****************************************************************************
* FUNCTION
*  mmi_bt_release_all_conn_guard_timeout_hdler
* DESCRIPTION
*  This function is  
*
* PARAMETERS
*  a  IN/OUT   first variable, used as returns
*  b  IN       second variable
* RETURNS
*  NONE.  
* GLOBALS AFFECTED
*  external_global
*****************************************************************************/
void mmi_bt_release_all_conn_guard_timeout_hdler(void)
{
    MMI_BOOL    restore_power_flag = MMI_FALSE;
    
	MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_SCR_RELEASE_ALL_CONN_GUARD_TIMEOUT, (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_state)());
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_SCR_STATUS,
               g_mmi_bt_scr_cntx.state, g_mmi_bt_scr_cntx.flag, g_mmi_bt_scr_cntx.blinking_flag);

#ifdef __MMI_BT_BG_PWRON__
	/* reset bt menu power */
	(*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_reset_flag_req)(MMI_BT_MASK_ACTIVATED);
	/* wait for re-start ind req	*/
	(*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_restart_bt_module_req)();
	//shall not go back history
	mmi_bt_stop_progress_scr(MMI_FALSE);
	/* reset scr flag */
	mmi_bt_reset_scr_flag();
	/* reset extend proc timer */
	g_mmi_bt_scr_cntx.extend_proc_timer=0;
	/* lead user to bluetooth main menu */
	mmi_bt_del_scr(SCR_BT_MAIN, SCR_BT_ABOUT);
	GoBackHistory();
#else /* __MMI_BT_BG_PWRON__ */ 
        if (g_mmi_bt_scr_cntx.flag & MMI_BT_RESET_HW_OFF)
        {
            g_mmi_bt_scr_cntx.flag &= ~MMI_BT_RESET_HW_OFF;
            /* indicate flight mode that power off action is finished */
            #ifdef __MMI_DUAL_SIM_MASTER__
            DualModeSwitchCompleteUpdateStatus(); //mmi_phnset_flight_mode_selection_finish();
	 	    #else
            #ifdef __FLIGHT_MODE_SUPPORT__
            mmi_phnset_switch_flight_mode(); //mmi_phnset_flight_mode_selection_finish();
            #endif
            #endif
            restore_power_flag = MMI_TRUE;
        }

        (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_reset_flag_req) (MMI_BT_MASK_ACTIVATED);
        (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_set_state) ((U32) MMI_BT_STAT_IDLE);
        (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_nvram_write_info) ();
        mmi_bt_init();
        (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_antenna_off_req) ();
        if(restore_power_flag)
        {
            g_mmi_bt_scr_cntx.flag |= MMI_BT_RESTORE_POWER_STATUS;
        }
        /* shall not go back history */
        mmi_bt_stop_progress_scr(MMI_FALSE);
        /* lead user to bluetooth main menu */
        mmi_bt_del_scr(SCR_BT_MAIN, SCR_BT_ABOUT);

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
#endif /* 0 */ 
#endif /* __MMI_BT_BG_PWRON__ */ 


}

/*****************************************************************************
* FUNCTION
*  mmi_bt_release_all_conn_guard_timeout_goback_history_hdler
* DESCRIPTION
*  This function is  
*
* PARAMETERS
*  a  IN/OUT   first variable, used as returns
*  b  IN       second variable
* RETURNS
*  NONE.  
* GLOBALS AFFECTED
*  external_global
*****************************************************************************/
void mmi_bt_release_all_conn_guard_timeout_goback_history_hdler(void)
{
	MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_SCR_RELEASE_ALL_CONN_GUARD_TIMEOUT, (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_state)());
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_SCR_STATUS,
               g_mmi_bt_scr_cntx.state, g_mmi_bt_scr_cntx.flag, g_mmi_bt_scr_cntx.blinking_flag);

#ifdef __MMI_BT_BG_PWRON__
	/* reset bt menu power */
	(*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_reset_flag_req)(MMI_BT_MASK_ACTIVATED);
	/* wait for re-start ind req	*/
	(*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_restart_bt_module_req)();
	//shall not go back history
	mmi_bt_stop_progress_scr(MMI_FALSE);
	/* reset scr flag */
	mmi_bt_reset_scr_flag();
	/* reset extend proc timer */
	g_mmi_bt_scr_cntx.extend_proc_timer=0;
	/* lead user to bluetooth main menu */
	mmi_bt_del_scr(SCR_BT_MAIN, SCR_BT_ABOUT);
	GoBackHistory();
#else
	/* reset bt menu power */
	g_mmi_bt_scr_cntx.flag |= MMI_BT_RELEASE_ALL_CONN_TIMEOUT;
	(*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_reset_flag_req)(MMI_BT_MASK_ACTIVATED);
	(*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_nvram_write_info)();
	/* wait for re-start ind req	*/
	(*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_restart_bt_module_req)();
	//shall not go back history
	mmi_bt_stop_progress_scr(MMI_FALSE);
	/* reset extend proc timer */
	g_mmi_bt_scr_cntx.extend_proc_timer=0;
	/* lead user to bluetooth main menu */
	mmi_bt_del_scr(SCR_BT_MAIN, SCR_BT_ABOUT);
	GoBackHistory();
#endif

}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_power_switch_confirm_rsk_hdler
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_power_switch_confirm_rsk_hdler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reset scr flag */
    //mmi_bt_reset_scr_flag();
    g_mmi_bt_scr_cntx.flag &= ~MMI_BT_CONFIRM_SWITCH_POWER_OFF;
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_release_device_connections
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_release_device_connections(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_release_dev_connection_req) (&(g_mmi_bt_scr_cntx.conn_dev_add)) ==
        MMI_FALSE)
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_ERROR),
            IMG_GLOBAL_ERROR,
            MMI_FALSE,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
        mmi_bt_delete_screen(SCR_BT_RELEASE_DEV_CONN_CNF, MMI_FALSE);
        
    }
    else
    {
        mmi_bt_show_progress_scr(
            SCR_BT_REL_DEV_CONN_PRO,
            STR_BT_RELEASE_DEV_CONN,
            STR_BT_RELEASING,
            NULL,
            MMI_FALSE,
            NULL);

#if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_A2DP_SUPPORT__)
        mmi_audply_bt_delete_device_callback(&g_mmi_bt_scr_cntx.conn_dev_add);
#endif
    }


}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_power_switch_on_complete
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  result      [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_power_switch_on_complete(MMI_BOOL result)   /* power switch rsp */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 active_scr_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_POWER_SWITCH_ON_COMPLETE, g_mmi_bt_scr_cntx.flag);

	
#if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_A2DP_SUPPORT__)
    mmi_audply_bt_power_on_callback((BOOL) result );
#endif

    if (g_mmi_bt_scr_cntx.flag & MMI_BT_AUTO_POWER_SWITCHIING)
    {
        U8 max_response;
        U16 timeout;
        MMI_BOOL name_discovery;
        U16 title_str_id;
        U8 inquiry_type = 0;
        U32 cod = 0;

        mmi_bt_update_status_icon();
        max_response = MMI_BT_MAX_INQUIRY_RESULTS_IN_LIST;
        timeout = MMI_BT_INQUIRY_TIMEOUT_DURATION;
        name_discovery = MMI_TRUE;
        title_str_id = STR_BT_SCH_ALL_DEV;  /* STR_BT_SCH_OPP_DEV; */
        if (g_mmi_bt_scr_cntx.flag & MMI_BT_INQ_TYPE_OPP_DEV)
        {
            cod = MMI_BT_OBJECT_TRANSFER_MAJOR_SERVICE_MASK;
            inquiry_type = MMI_BT_INQ_TYPE_OPP_DEV;
        }
        else if (g_mmi_bt_scr_cntx.flag & MMI_BT_INQ_TYPE_A2DP_DEV)
        {
            cod = MMI_BT_AUDIO_MAJOR_SERVICE_MASK | MMI_BT_RENDERING_MAJOR_SERVICE_MASK | MMI_BT_AV_MAJOR_DEVICE_MASK;
            inquiry_type = (U8)MMI_BT_INQ_TYPE_A2DP_DEV;
        }
        else if (g_mmi_bt_scr_cntx.flag & MMI_BT_INQ_TYPE_HID_DEV)
        {
			cod = MMI_BT_PERIPHERAL_MAJOR_DEVICE_MASK | MMI_BT_COMPUTER_MAJOR_DEVICE_MASK | MMI_BT_REMOTE_CONTRO_DEVICE_PERIPHERAL_MINOR_DEVICE_CLASS;
            inquiry_type = (U8)MMI_BT_INQ_TYPE_HID_DEV;
        }
		else if (g_mmi_bt_scr_cntx.flag_extended & MMI_BT_EXT_INQ_TYPE_PRINTER_DEV)
		{
			cod = MMI_BT_RENDERING_MAJOR_SERVICE_MASK |MMI_BT_IMAGING_MAJOR_DEVICE_MASK |MMI_BT_PRINTER_IMAGING_MINOR_DEVICE_CLASS;
			inquiry_type = (U8)MMI_BT_EXT_INQ_TYPE_PRINTER_DEV;

		}
		else if (g_mmi_bt_scr_cntx.flag_extended & MMI_BT_EXT_INQ_TYPE_SPEC_COD_DEV)
		{
			cod = g_mmi_bt_scr_cntx.specific_cod_mask;
			inquiry_type = (U8)MMI_BT_EXT_INQ_TYPE_SPEC_COD_DEV;
		}


        g_mmi_bt_scr_cntx.flag &= ~MMI_BT_AUTO_POWER_SWITCHIING;        
        mmi_bt_inquiry(max_response, timeout, cod, name_discovery, title_str_id, inquiry_type);
        return;
    }
#ifndef __MMI_BT_BG_PWRON__
    else if (g_mmi_bt_scr_cntx.flag & MMI_BT_RESET_HW_ON)
    {

        mmi_bt_update_status_icon();
        g_mmi_bt_scr_cntx.flag &= ~MMI_BT_RESET_HW_ON;
        /* indicate flight mode that bt power off action is finished */
		    #ifdef __MMI_DUAL_SIM_MASTER__
            DualModeSwitchCompleteUpdateStatus(); //mmi_phnset_flight_mode_selection_finish();
	        #else
            #ifdef __FLIGHT_MODE_SUPPORT__
            mmi_phnset_switch_flight_mode(); //mmi_phnset_flight_mode_selection_finish();
            #endif
            #endif
        return;
    }
#endif /* __MMI_BT_BG_PWRON__ */ 
    else if (g_mmi_bt_scr_cntx.flag & MMI_BT_SCO_FAR_END_LP_TESTING)
    {
        mmi_bt_update_status_icon();
        /* connecting HFP profile */
        (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_connect_req) (&(g_mmi_bt_scr_cntx.far_end_dev_add),
                                                              MMI_BT_HF_PROFILE_UUID);
        return;
    }
    else if (g_mmi_bt_scr_cntx.flag & MMI_BT_AUTO_POWER_SWITCHIING_OFF)
    {
        g_mmi_bt_scr_cntx.flag &= ~MMI_BT_AUTO_POWER_SWITCHIING_OFF;
        mmi_bt_close();
        return;
    }
    else
    {
        mmi_bt_update_status_icon();
    }

    active_scr_id = GetActiveScreenId();
    if (active_scr_id != SCR_BT_MAIN && active_scr_id != SCR_BT_POWER_PRO)
    {
        /* if power on progressing is interrupted by other screen */
        /* progress will be stayed in history, so have to delete it */
        DeleteScreenIfPresent(SCR_BT_POWER_PRO);
		DeleteScreenIfPresent(SCR_BT_POWER_ON_CNF);        
        g_mmi_bt_scr_cntx.flag &= ~MMI_BT_CONFIRM_INQ_AUDIO_DEV;
        g_mmi_bt_scr_cntx.flag &= ~MMI_BT_CONFIRM_PAIRED_DEV_SCH;
        g_mmi_bt_scr_cntx.flag &= ~MMI_BT_CONFIRM_PAIRED_DEV_OPT;
        g_mmi_bt_scr_cntx.flag &= ~MMI_BT_CONFIRM_SET;
        g_mmi_bt_scr_cntx.flag &= ~MMI_BT_CONFIRM_SPECIFIC_DEV;
        return;
    }

    if (result == MMI_TRUE)
    {
        DisplayPopup(
            (U8*) GetString(STR_BT_SWITCHED_ON),
            IMG_GLOBAL_ACTIVATED,
            MMI_FALSE,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) SUCCESS_TONE);
    }
    else
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_ERROR),
            IMG_GLOBAL_ERROR,
            MMI_FALSE,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
    }
    /* In order to avoid the UI screen flashing(GoBackHistory, then entry another NEW screen)*/
    /* it is better to stop progressing screen from history if MMI shall */
    /* lead end user to another UI screen */
    mmi_bt_stop_progress_scr(MMI_FALSE);

    DeleteScreenIfPresent(SCR_BT_POWER_PRO);

    if (g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_INQ_AUDIO_DEV)
    {
        StartTimer(BT_POPUP_TIMER, MMI_BT_BT_POPUP_TIMER_DUR, mmi_bt_entry_inq_aud_dev);
        DeleteScreenIfPresent(SCR_BT_POWER_ON_CNF);
     }
    else if (g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_PAIRED_DEV_SCH)
    {
        StartTimer(BT_POPUP_TIMER, MMI_BT_BT_POPUP_TIMER_DUR, mmi_bt_entry_mydev_sch);
        DeleteScreenIfPresent(SCR_BT_POWER_ON_CNF);
    }
    else if (g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_PAIRED_DEV_OPT)
    {
        StartTimer(BT_POPUP_TIMER, MMI_BT_BT_POPUP_TIMER_DUR, mmi_bt_entry_mydev_opt);
        DeleteScreenIfPresent(SCR_BT_POWER_ON_CNF);
    }
    else if (g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_SET)
    {
        StartTimer(BT_POPUP_TIMER, MMI_BT_BT_POPUP_TIMER_DUR, mmi_bt_entry_set_menu);
        DeleteScreenIfPresent(SCR_BT_POWER_ON_CNF);
    }
    else if (g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_SPECIFIC_DEV)
    {
        StartTimer(BT_POPUP_TIMER, MMI_BT_BT_POPUP_TIMER_DUR, mmi_bt_entry_my_specific_dev_menu);
        DeleteScreenIfPresent(SCR_BT_POWER_ON_CNF);
        /* power on cnf screen will be removed in mmi_bt_entry_my_specific_dev_menu */
    }
    else if (g_mmi_bt_scr_cntx.flag_extended & MMI_BT_EXT_CONFIRM_POWER_ON)
    {
        StartTimer(BT_POPUP_TIMER, MMI_BT_BT_POPUP_TIMER_DUR, g_mmi_bt_scr_cntx.pwr_on_cb);
        /* power on cnf screen is handled by hid app */
        DeleteScreenIfPresent(SCR_BT_REMOTE_CONTROL_POWER_ON_CONFIRM);
        
    }
    

#ifdef MMI_BT_ON_OFF_STRESS_TEST
    if (g_mmi_bt_scr_cntx.flag & MMI_BT_ANTENNA_ON_OFF_STRESS_TEST)
    {
        mmi_bt_on_off_stress_testing();
        return;
    }
#endif /* MMI_BT_ON_OFF_STRESS_TEST */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_power_switch_off_complete
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  result      [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_power_switch_off_complete(MMI_BOOL result)  /* power switch rsp */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 active_scr_id;
    MMI_BOOL    restore_power_flag = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(BT_POWER_OFF_GUARD_TIMER);

    /* reset blinking status */
    mmi_bt_status_icon_stop_blinking(MMI_BT_OBEX_FILE_TRANSFER_UUID, MMI_BT_SERVER_ROLE);
    mmi_bt_status_icon_stop_blinking(MMI_BT_OBEX_FILE_TRANSFER_UUID, MMI_BT_CLIENT_ROLE);
    mmi_bt_status_icon_stop_blinking(MMI_BT_OBEX_OBJECT_PUSH_SERVICE_UUID, MMI_BT_SERVER_ROLE);
    mmi_bt_status_icon_stop_blinking(MMI_BT_OBEX_OBJECT_PUSH_SERVICE_UUID, MMI_BT_CLIENT_ROLE);
    mmi_bt_update_status_icon();

#if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_A2DP_SUPPORT__)
    mmi_audply_bt_power_off_callback((BOOL) result );
#endif

    /* it is to handle reset HW off command */
    /* 1. release all connection */
    /* 2. deactivate all service */
    /* 3. send antenna off req */
    if (g_mmi_bt_scr_cntx.flag & MMI_BT_RESET_HW_OFF)
    {
        /* turn off BT power */
        /* wait for antenna_off_rsp to reset bt ready ram flag  */
        (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_antenna_off_req) ();
        /* reset scr flag */
        //mmi_bt_reset_scr_flag();
        g_mmi_bt_scr_cntx.flag &= ~MMI_BT_RESET_HW_OFF;
        /* indicate flight mode that power off action is finished */
		       #ifdef __MMI_DUAL_SIM_MASTER__
               DualModeSwitchCompleteUpdateStatus(); //mmi_phnset_flight_mode_selection_finish();
	           #else
               #ifdef __FLIGHT_MODE_SUPPORT__
               mmi_phnset_switch_flight_mode(); //mmi_phnset_flight_mode_selection_finish();
		       #endif
               #endif
        g_mmi_bt_scr_cntx.flag |= MMI_BT_RESTORE_POWER_STATUS;

        return;
    }
    else if (g_mmi_bt_scr_cntx.flag & MMI_BT_RESTORE_POWER_STATUS)
    {
        (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_set_flag_req) (MMI_BT_MASK_ACTIVATED);
        (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_nvram_write_info) ();
        g_mmi_bt_scr_cntx.flag &= ~MMI_BT_RESTORE_POWER_STATUS;
        restore_power_flag = MMI_TRUE;
		
    }
    else if (g_mmi_bt_scr_cntx.flag & MMI_BT_ANTENNA_OFF)
    {
        /* turn off BT power */
        /* wait for mmi_antenna_off_rsp to reset bt ready ram flag  */
        (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_antenna_off_req) ();
        /* reset scr flag */
        g_mmi_bt_scr_cntx.flag &= ~MMI_BT_ANTENNA_OFF;
        return;

    }
    else if (g_mmi_bt_scr_cntx.flag & MMI_BT_SCO_FAR_END_LP_TESTING)
    {
        /* turn off BT power */
        /* wait for mmi_antenna_off_rsp to reset bt ready ram flag  */
        (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_antenna_off_req) ();
        /* reset scr flag */
        g_mmi_bt_scr_cntx.flag &= ~MMI_BT_SCO_FAR_END_LP_TESTING;
        return;
    }

    active_scr_id = GetActiveScreenId();

    if (restore_power_flag && active_scr_id != SCR_BT_MAIN && active_scr_id != SCR_BT_POWER_PRO)
    {
        /* if power on progressing is interrupted by other screen */
        /* progress will be stayed in history, so have to delete it */
        DeleteScreenIfPresent(SCR_BT_POWER_PRO);
        /* if passkey input screen being presented in history, the remove it */
        SetDelScrnIDCallbackHandler(SCR_BT_PIN_INPUT, (HistoryDelCBPtr) NULL);
        DeleteScreenIfPresent(SCR_BT_PIN_INPUT);
        /* it isnot expected to see the power on/off successful screen, so shall return here */
        return;
    }

    mmi_bt_stop_progress_scr(MMI_FALSE);
    if (result == MMI_TRUE)
    {
        DisplayPopup(
            (U8*) GetString(STR_BT_SWITCHED_OFF),
            IMG_GLOBAL_ACTIVATED,
            MMI_FALSE,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) SUCCESS_TONE);
    }
    else
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_ERROR),
            IMG_GLOBAL_ERROR,
            MMI_FALSE,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
    }

    DeleteScreenIfPresent(SCR_BT_POWER_PRO);
    SetDelScrnIDCallbackHandler(SCR_BT_PIN_INPUT, (HistoryDelCBPtr) NULL);
    DeleteScreenIfPresent(SCR_BT_PIN_INPUT);

#ifdef MMI_BT_ON_OFF_STRESS_TEST
    if (g_mmi_bt_scr_cntx.flag & MMI_BT_ANTENNA_ON_OFF_STRESS_TEST)
    {
        mmi_bt_on_off_stress_testing();
        return;
    }
#endif /* MMI_BT_ON_OFF_STRESS_TEST */ 

}
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_mask_scr_extended_flag
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_mask_scr_extended_flag(U32 flag)
{
    g_mmi_bt_scr_cntx.flag_extended |= flag;    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_unmask_scr_extended_flag
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_unmask_scr_extended_flag(U32 flag)
{
    if (g_mmi_bt_scr_cntx.flag_extended & flag)
    {
        g_mmi_bt_scr_cntx.flag_extended &= ~flag;    
        StopTimer(BT_POPUP_TIMER);
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_register_power_on_callback
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_register_power_on_callback(void (*power_on_cb_func_ptr) (void))
{
    g_mmi_bt_scr_cntx.pwr_on_cb = power_on_cb_func_ptr;    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_inq_aud_dev
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_inq_aud_dev(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 max_response;
    U16 timeout;
    U32 cod;
    MMI_BOOL name_discovery;
    U16 title_str_id;
    U8 inquiry_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* to avoid the twice inquiry operation while bt is just on and wanna do the inquiry */
    if (g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_INQ_AUDIO_DEV)
    {
        g_mmi_bt_scr_cntx.flag &= ~MMI_BT_CONFIRM_INQ_AUDIO_DEV;
        StopTimer(BT_POPUP_TIMER);
    }

    if ((mmi_bt_is_hw_ready) (MMI_TRUE) == MMI_FALSE)
    {
        return;
    }

    /* to avoid the error operation while bt module is busy */
    if ((mmi_bt_is_permission) (MMI_TRUE) == MMI_FALSE)
    {
        return;
    }

    /* prohibited by simap, shall deactivate simap first */
    if (mmi_bt_is_simap_server_activate())
    {
        mmi_bt_popup_prohibited_by_simap();
        return;
    }


    if ((*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_pwron) () == MMI_FALSE)
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
        #endif
        mmi_bt_display_power_on_confirm(MMI_BT_CONFIRM_INQ_AUDIO_DEV);
        return;
    }

    /* to disconnect sco first if sco connected */
    #if defined(__MMI_BT_AUDIO_VIA_SCO__) || defined(__MMI_BT_FM_VIA_SCO__)
	//if(mmi_profiles_bt_is_connected((U8)MMI_PROFILES_BT_HFP_SCO))
	{
	    if (mmi_profiles_bt_inquery_start_callback(mmi_bt_entry_inq_aud_dev))
	    {
    		return;
	    }
	}
    #endif

    max_response = MMI_BT_MAX_INQUIRY_RESULTS_IN_LIST;
    timeout = MMI_BT_INQUIRY_TIMEOUT_DURATION;
    cod = MMI_BT_AUDIO_MAJOR_SERVICE_MASK;
    name_discovery = MMI_TRUE /* MMI_FALSE */ ;
    title_str_id = STR_BT_SEARCHING;
    inquiry_type = MMI_BT_INQ_TYPE_AUDIO;
    g_mmi_bt_scr_cntx.flag |= MMI_BT_INQ_TYPE_AUDIO;
    mmi_bt_inquiry(max_response, timeout, cod, name_discovery, title_str_id, inquiry_type);

}

/*****************************************************************************
* FUNCTION
*  mmi_bt_exit_inq_aud_dev
* DESCRIPTION
*  This function is  
*
* PARAMETERS
*  a  IN/OUT   first variable, used as returns
*  b  IN       second variable
* RETURNS
*  NONE.  
* GLOBALS AFFECTED
*  external_global
*****************************************************************************/
void mmi_bt_exit_inq_aud_dev(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_inq_aud_dev_confirm_rsk_hdler
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_inq_aud_dev_confirm_rsk_hdler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reset scr flag */
    //mmi_bt_reset_scr_flag();
    g_mmi_bt_scr_cntx.flag &= ~MMI_BT_CONFIRM_INQ_AUDIO_DEV;
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_inquiry
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  max_response        [IN]            
 *  timeout             [IN]            
 *  cod                 [IN]            
 *  name_discovery      [IN]            
 *  title_str_id        [IN]            
 *  inquiry_type        [IN]            
 *  a(?)                [IN/OUT]        First variable, used as returns
 *  b(?)                [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_inquiry(U8 max_response, U16 timeout, U32 cod, MMI_BOOL name_discovery, U16 title_str_id, U8 inquiry_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 active_scr_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_SCR_STATUS,
               g_mmi_bt_scr_cntx.state, g_mmi_bt_scr_cntx.flag, g_mmi_bt_scr_cntx.blinking_flag);

    SetDelScrnIDCallbackHandler(SCR_BT_SCH_PRO, (HistoryDelCBPtr) NULL);

    /* notify bt AV that bt chip is doing inquiry */
    #if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_A2DP_SUPPORT__)
    av_bt_inquiry_start_callback();
    #endif

    if (!(*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_inquiry_req) (max_response,
                                                               timeout, cod, name_discovery, inquiry_type))
    {
        DisplayPopup(
            (U8*) GetString(STR_BT_DEV_BUSY),
            IMG_GLOBAL_ERROR,
            MMI_FALSE,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
        return;
    }
    else
    {
        g_mmi_bt_scr_cntx.state = MMI_BT_SCR_STATE_INQ_WAIT_CFM;
        if ((!IsScreenPresent(SCR_BT_SCH_PRO)))
        {
            mmi_bt_show_progress_scr(
                SCR_BT_SCH_PRO,
                title_str_id,
                STR_BT_SEARCHING,
                NULL,
                MMI_TRUE,
                mmi_bt_inq_result_cancel);
        }
    }

    active_scr_id = GetActiveScreenId();
    if (active_scr_id == SCR_BT_SCH_PRO)
    {
        SetRightSoftkeyFunction(mmi_bt_inq_result_cancel, KEY_EVENT_UP);
    }


}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_inq_progress_del_cb
 * DESCRIPTION
 *  This function is bluetooth highlight handler.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_bt_inq_progress_del_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_SCR_INQ_PROGRESS_DEL_CB,
               (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_state) ());

    SetDelScrnIDCallbackHandler(SCR_BT_SCH_PRO, (HistoryDelCBPtr) NULL);

    if (mmi_bt_is_hw_ready(MMI_FALSE) == MMI_FALSE)
    {
        g_mmi_bt_scr_cntx.flag &= ~MMI_BT_AUTO_POWER_SWITCHIING;
        g_mmi_bt_scr_cntx.flag |= MMI_BT_AUTO_POWER_SWITCHIING_OFF;
        mmi_bt_stop_progress_scr(MMI_TRUE);
        return MMI_FALSE;
    }

    state = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_state) ();

    switch (state)
    {
        case MMI_BT_STAT_INIT_ON:
        case MMI_BT_STAT_ACTIVATE_SWITCHING:
            g_mmi_bt_scr_cntx.flag &= ~MMI_BT_AUTO_POWER_SWITCHIING;
            g_mmi_bt_scr_cntx.flag |= MMI_BT_AUTO_POWER_SWITCHIING_OFF;
            mmi_bt_stop_progress_scr(MMI_TRUE);
            break;
        case MMI_BT_STAT_INQUIRING:
        case MMI_BT_STAT_INQUIR_RES_IND:
	            (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_inquiry_cancel_req) ((U8) g_mmi_bt_scr_cntx.flag);
	            g_mmi_bt_scr_cntx.flag |= MMI_BT_CANCEL_INQ_BEFORE_BT_CLOSE;
	            g_mmi_bt_scr_cntx.state = MMI_BT_SCR_STATE_CANCEL_INQ_WAIT_CFM;
	            mmi_bt_stop_progress_scr(MMI_FALSE);
	            break;
        default:
            break;
    }

    /* reset inquiry flag */
    g_mmi_bt_scr_cntx.flag &= ~MMI_BT_INQ_TYPE_AUDIO;
    g_mmi_bt_scr_cntx.flag &= ~MMI_BT_INQ_TYPE_ALL_DEV;
    g_mmi_bt_scr_cntx.flag &= ~MMI_BT_INQ_TYPE_OPP_DEV;
    g_mmi_bt_scr_cntx.flag &= ~MMI_BT_INQ_TYPE_A2DP_DEV;
    g_mmi_bt_scr_cntx.flag &= ~MMI_BT_INQ_TYPE_HID_DEV;
    g_mmi_bt_scr_cntx.flag_extended &= ~MMI_BT_EXT_INQ_TYPE_PRINTER_DEV;
    g_mmi_bt_scr_cntx.flag_extended &= ~MMI_BT_EXT_INQ_TYPE_SPEC_COD_DEV;

    return MMI_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_inq_result
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_inq_result(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 *ItemList[MAX_SUB_MENUS];
    U16 ItemIcons[MAX_SUB_MENUS];
    U16 nItems;
    U32 i = 0;
    U8 discov_dev_counter = 0;
    mmi_bt_dev_struct *discov_dev_p;
    U8 state;
    U8 utf8_char_cnt = 0;
    U8 ucs2_str_len = 0;
    U16 rsk_str, rsk_img, lsk_str, lsk_img;
    U16 currScreenId;
    MMI_BOOL is_back_from_history = MMI_FALSE;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetDelScrnIDCallbackHandler(SCR_BT_SCH_PRO, (HistoryDelCBPtr) NULL);
    SetDelScrnIDCallbackHandler(SCR_BT_SCH_RES, (HistoryDelCBPtr) mmi_bt_inq_result_del_cb);

    /* replace history */
    currScreenId = GetActiveScreenId();
    if (currScreenId != SCR_BT_SCH_PRO && currScreenId != SCR_BT_SCH_RES)
    {
        /* two cases that this entry fuction will be called */
        /* one is SCR_BT_SCH_PRO is in history and first result ind coming */
        /* for above case, shall replace the history SCR_BT_SCH_PRO by SCR_BT_SCH_RES */
        /* second is that this entry is called by ExecutePopHistory while interrup screen is finished */
        /* for above second case, IsBackHistory shall be TRUE */
        if (IsBackHistory == MMI_FALSE)
        {
            HistoryReplace(SCR_BT_SCH_PRO, SCR_BT_SCH_RES, mmi_bt_entry_inq_result);
            return;
        }
        else
        {
            is_back_from_history = MMI_TRUE;
        }
    }

    memset(ItemList, 0, sizeof(U8) * MAX_SUB_MENUS);
    memset(ItemIcons, 0, sizeof(U16) * MAX_SUB_MENUS);

    mmi_bt_stop_progress_scr(MMI_FALSE);
    discov_dev_counter = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_discov_dev_num) ();
    state = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_state) ();

    for (i = 0; i < discov_dev_counter; i++)
    {
        discov_dev_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_discov_dev_info) ((U8) i);

        /* put it into UI inq result list screen buffer */
        /* get byte count for convert utf8 string to UCS2 string */
        /* get character count of utf8 string */
        /* +1 is for UCS2 NULL terminate */
        /* *ENCODING_LENGTH is for byte count of one UCS2 character */
        utf8_char_cnt = (U8) ((mmi_chset_utf8_strlen((kal_uint8*) discov_dev_p->name) + 1) * ENCODING_LENGTH);
        MMI_BT_ASSERT(MAX_SUB_MENU_SIZE >= MMI_BT_SCR_BD_NAME_LEN);
        if (utf8_char_cnt > MMI_BT_SCR_BD_NAME_LEN)
        {
            ucs2_str_len =
                (U8) mmi_chset_utf8_to_ucs2_string(
                        (kal_uint8*) subMenuData[i],
                        MMI_BT_SCR_BD_NAME_LEN,
                        (kal_uint8*) discov_dev_p->name);
        }
        else
        {
            ucs2_str_len =
                (U8) mmi_chset_utf8_to_ucs2_string(
                        (kal_uint8*) subMenuData[i],
                        utf8_char_cnt,
                        (kal_uint8*) discov_dev_p->name);
        }

  		/* allow (MMI_BT_BD_NAME_LEN/3) chinese characters or (MMI_BT_BD_NAME_LEN/3)*2 english characters  */
  		/* so for UCS2 encoding, need MMI_BT_SCR_BD_NAME_LEN bytes */
  
  		/* shall check if there is any two_byte character mixed in one_bye UCS2 string */
  		/* if yes, then truncate the string to meet above rules((MMI_BT_BD_NAME_LEN/3) chinese characters or (MMI_BT_BD_NAME_LEN/3)*2 english characters)*/	
  		if(mmi_bt_test_ucs2((U16*)subMenuData[i], (U16)(ucs2_str_len/ENCODING_LENGTH)) )
  		{ 
  			mmi_bt_truncate_ucs2_string((U16*)subMenuData[i], 
  			    							(U16)(ucs2_str_len/ENCODING_LENGTH),
  			    							(U16)((MMI_BT_BD_NAME_LEN-2)/3)
  			    						   );		    
  		}

        ItemList[i] = subMenuData[i];

        /* BT address: NAP, UAP, LAP */
        kal_wsprintf(
            (U16*) hintData[i],
            "BD_ADDR: %02x:%02x:%02x:%02x:%02x:%02x",
            ((discov_dev_p->bd_addr.nap & 0xff00) >> 8),
            (discov_dev_p->bd_addr.nap & 0x00ff),
            (discov_dev_p->bd_addr.uap),
            ((discov_dev_p->bd_addr.lap & 0xff0000) >> 16),
            ((discov_dev_p->bd_addr.lap & 0x00ff00) >> 8),
            (discov_dev_p->bd_addr.lap & 0x0000ff));
        hintDataPtrs[i] = hintData[i];

        if (discov_dev_p->cod & MMI_BT_COMPUTER_MAJOR_DEVICE_MASK)
        {
            ItemIcons[i] = IMG_BT_DEV_LAP;
        }
        else if (discov_dev_p->cod & MMI_BT_PRINTER_IMAGING_MINOR_DEVICE_CLASS)
        {
            ItemIcons[i] = IMG_BT_DEV_PRT;
        }
        else if (discov_dev_p->cod & MMI_BT_PHONE_MAJOR_DEVICE_MASK)
        {
            ItemIcons[i] = IMG_BT_DEV_MOB;
        }
        else if (discov_dev_p->cod & MMI_BT_AV_MAJOR_DEVICE_MASK)
        {
            ItemIcons[i] = IMG_BT_DEV_EAR;
        }
        else
        {
            ItemIcons[i] = IMG_BT_DEV_OTHER;
        }
    }

    nItems = (U16) discov_dev_counter;

    switch (state)
    {
		   	case MMI_BT_STAT_INQUIRING:
		   	case MMI_BT_STAT_INQUIR_RES_IND:
				rsk_str = STR_GLOBAL_CANCEL;
				rsk_img = IMG_GLOBAL_OK;
	   	        break;
			default:
            	if (g_mmi_bt_scr_cntx.state == MMI_BT_SCR_STATE_INQ_WAIT_CFM)
            	{
					rsk_str = STR_GLOBAL_CANCEL;
					rsk_img = IMG_GLOBAL_OK;
				}
				else
				{
					rsk_str = STR_GLOBAL_BACK;
					rsk_img = IMG_GLOBAL_OK;
				}			
		        break;
    }
	   
    if( g_mmi_bt_scr_cntx.flag & MMI_BT_INQ_TYPE_OPP_DEV)
    {
		#if defined(__MMI_BT_MTK_SUPPORT__) 
        lsk_str = STR_BT_BOND;
    	#else
        lsk_str = STR_BT_SEND;
    	#endif
        lsk_img = IMG_GLOBAL_OK;
    }
    else
    {
        lsk_str = STR_BT_BOND;
        lsk_img = IMG_GLOBAL_OK;
    }

    if (discov_dev_counter == 0)
    {
        SetDelScrnIDCallbackHandler(SCR_BT_SCH_RES, (HistoryDelCBPtr) NULL);

        /* List Empty */
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_EMPTY),
            IMG_GLOBAL_EMPTY,
            MMI_FALSE,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) EMPTY_LIST_TONE);

    }
    /* display first found entry or finish inquiry action */
    else if (discov_dev_counter == 1 || (state == MMI_BT_STAT_IDLE) || is_back_from_history)
    {

        /* Display inquiry result */
        EntryNewScreen(SCR_BT_SCH_RES, mmi_bt_exit_inq_result, mmi_bt_entry_inq_result, NULL);

        guiBuffer = GetCurrGuiBuffer(SCR_BT_SCH_RES); 

        SetParentHandler(MENU_CONN_BT_SCH_AUDIO_DEV);

        RegisterHighlightHandler(mmi_bt_inq_result_hilite_hdlr);

        /* Store END key handler */
        mmi_bt_store_endkey_hdlr();

        ShowCategory53Screen(
            STR_BT_SCH_RESULT,
            IMG_BT_SCH_TITLE /* GetRootTitleIcon(MENU_CONN_BT_MAIN) */ ,
            lsk_str,
            lsk_img,
            rsk_str,
            rsk_img,
            nItems,
            (U8 **) ItemList,
            (U16*) ItemIcons,
            hintDataPtrs,
            0,
            0,
            guiBuffer);

        DeleteScreenIfPresent(SCR_BT_SCH_PRO);
        DeleteScreenIfPresent(SCR_BT_SCH_CANCEL_PRO);

    }
    else
    {
        if (GetActiveScreenId() != SCR_BT_SCH_RES)
        {
            return;
        }

        if (ExitCategoryFunction)
        {
            ExitCategoryFunction();
        }

        UI_common_screen_exit();

        RegisterHighlightHandler(mmi_bt_inq_result_hilite_hdlr);
        /* Store END key handler */
        /* mmi_bt_store_endkey_hdlr(); */

        ShowCategory53Screen(
            STR_BT_SCH_RESULT,
            IMG_BT_SCH_TITLE /* GetRootTitleIcon(MENU_CONN_BT_MAIN) */ ,
            lsk_str,
            lsk_img,
            rsk_str,
            rsk_img,
            nItems,
            (U8 **) ItemList,
            (U16*) ItemIcons,
            hintDataPtrs,
            0,
            (S32) g_mmi_bt_scr_cntx.hilight_item,
            NULL);
    }


    /* to stop searching icon if inqiry is finished */
    if ((*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_state) () != MMI_BT_STAT_INQUIR_RES_IND)
    {
        wgui_stop_title_animation();
    }

    DeleteScreenIfPresent(SCR_BT_MYDEV_OPT);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_exit_inq_result
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_exit_inq_result(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bt_clear_endkey_hdlr();
    /* stop the animated title icon */
    wgui_stop_title_animation();

    state = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_state) ();

    switch (state)
    {
        case MMI_BT_STAT_INIT_ON:
            break;
        case MMI_BT_STAT_ACTIVATE_SWITCHING:
            break;
        case MMI_BT_STAT_INQUIRING:
        case MMI_BT_STAT_INQUIR_RES_IND:
            /* shall not cancel inquiry */
            /* (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_inquiry_cancel_req)((U8)g_mmi_bt_scr_cntx.flag); */
            /* g_mmi_bt_scr_cntx.state = MMI_BT_SCR_STATE_CANCEL_INQ_WAIT_CFM; */
            break;
        case MMI_BT_STAT_BONDING:
            break;
        case MMI_BT_STAT_PAIRING:
            break;
        case MMI_BT_STAT_SDC_SEARCHING:
            break;
        case MMI_BT_STAT_CONNECTING:
            break;
        case MMI_BT_STAT_DEBONDING:
            break;
        case MMI_BT_STAT_DISCONNECTING:
            break;
        case MMI_BT_STAT_AUDIO_CON_ESTAB:
            break;
        case MMI_BT_STAT_SDC_REFRESHING:
            break;
        default:
            break;

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_inq_result_hilite_hdlr
 * DESCRIPTION
 *  This function is bluetooth highlight handler.
 * PARAMETERS
 *  idx         [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_inq_result_hilite_hdlr(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    (g_mmi_bt_scr_cntx.hilight_item) = idx;
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_SCR_HIGHLIGHT_ITEM, (g_mmi_bt_scr_cntx.hilight_item));
    state = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_state) ();

    SetDelScrnIDCallbackHandler(SCR_BT_SCH_RES, (HistoryDelCBPtr) mmi_bt_inq_result_del_cb);



    if ( (g_mmi_bt_scr_cntx.flag & MMI_BT_INQ_TYPE_AUDIO) ||
		 #if defined(__MMI_BT_MTK_SUPPORT__)
         (g_mmi_bt_scr_cntx.flag & MMI_BT_INQ_TYPE_OPP_DEV) ||
         #endif
         (g_mmi_bt_scr_cntx.flag & MMI_BT_INQ_TYPE_ALL_DEV) ||
         (g_mmi_bt_scr_cntx.flag & MMI_BT_INQ_TYPE_A2DP_DEV) ||
         (g_mmi_bt_scr_cntx.flag & MMI_BT_INQ_TYPE_HID_DEV) ||
		 (g_mmi_bt_scr_cntx.flag_extended & MMI_BT_EXT_INQ_TYPE_PRINTER_DEV) ||
		 (g_mmi_bt_scr_cntx.flag_extended & MMI_BT_EXT_INQ_TYPE_SPEC_COD_DEV) )
    {
        SetLeftSoftkeyFunction(mmi_bt_entry_bonding, KEY_EVENT_UP);
        SetKeyHandler(mmi_bt_entry_bonding, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
	#if !defined(__MMI_BT_MTK_SUPPORT__)
    else if( g_mmi_bt_scr_cntx.flag & MMI_BT_INQ_TYPE_OPP_DEV )
    {
        SetLeftSoftkeyFunction(mmi_bt_opp_sending, KEY_EVENT_UP);
        SetKeyHandler(mmi_bt_opp_sending, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
    #endif

    switch (state)
    {
		case MMI_BT_STAT_INQUIRING:
		case MMI_BT_STAT_INQUIR_RES_IND:
				SetRightSoftkeyFunction(mmi_bt_inq_result_cancel,KEY_EVENT_UP);
				//SetKeyHandler(mmi_bt_inq_result_cancel, KEY_LEFT_ARROW,KEY_EVENT_DOWN);
				SetKeyHandler(mmi_bt_inq_result_endkey, KEY_END,KEY_EVENT_DOWN);
				ClearKeyHandler( KEY_END, KEY_EVENT_UP);
		        break;
		      	  	
		default:
            	if (g_mmi_bt_scr_cntx.state == MMI_BT_SCR_STATE_INQ_WAIT_CFM)
            	{
					SetRightSoftkeyFunction(mmi_bt_inq_result_cancel,KEY_EVENT_UP);
					//SetKeyHandler(mmi_bt_inq_result_cancel, KEY_LEFT_ARROW,KEY_EVENT_DOWN);
					SetKeyHandler(mmi_bt_inq_result_endkey, KEY_END,KEY_EVENT_DOWN);
					ClearKeyHandler( KEY_END, KEY_EVENT_UP);
				}
				else
				{
					SetRightSoftkeyFunction(mmi_bt_inq_result_goback,KEY_EVENT_UP);
					//SetKeyHandler(mmi_bt_inq_result_goback, KEY_LEFT_ARROW,KEY_EVENT_DOWN);
					SetKeyHandler(mmi_bt_inq_result_endkey, KEY_END,KEY_EVENT_DOWN);
					ClearKeyHandler( KEY_END, KEY_EVENT_UP);
				}
		        break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_inq_result_del_cb
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_bt_inq_result_del_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_SCR_INQ_RES_DEL_CB, (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_state) ());

    SetDelScrnIDCallbackHandler(SCR_BT_SCH_RES, (HistoryDelCBPtr) NULL);

    state = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_state) ();
    switch (state)
    {
        case MMI_BT_STAT_INQUIRING:
        case MMI_BT_STAT_INQUIR_RES_IND:
            (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_inquiry_cancel_req) ((U8) g_mmi_bt_scr_cntx.flag);
            g_mmi_bt_scr_cntx.flag |= MMI_BT_CANCEL_INQ_BEFORE_BT_CLOSE;
            g_mmi_bt_scr_cntx.state = MMI_BT_SCR_STATE_CANCEL_INQ_WAIT_CFM;
            break;
        default:
            if (g_mmi_bt_scr_cntx.state == MMI_BT_SCR_STATE_INQ_WAIT_CFM)
            {
                (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_inquiry_cancel_req) ((U8) g_mmi_bt_scr_cntx.flag);
                g_mmi_bt_scr_cntx.flag |= MMI_BT_CANCEL_INQ_BEFORE_BT_CLOSE;
                g_mmi_bt_scr_cntx.state = MMI_BT_SCR_STATE_CANCEL_INQ_WAIT_CFM;
                break;
            }
            /* it is to reset MMI_BT_RAMMASK_IS_AUTO_PWR_SWTICH */
            /* inqiry OPP dev will call mmi_bt_open() */
            mmi_bt_close();
            break;
    }

    /* reset inquiry flag */
    g_mmi_bt_scr_cntx.flag &= ~MMI_BT_INQ_TYPE_AUDIO;
    g_mmi_bt_scr_cntx.flag &= ~MMI_BT_INQ_TYPE_ALL_DEV;
    g_mmi_bt_scr_cntx.flag &= ~MMI_BT_INQ_TYPE_OPP_DEV;
    g_mmi_bt_scr_cntx.flag &= ~MMI_BT_INQ_TYPE_A2DP_DEV;
    g_mmi_bt_scr_cntx.flag &= ~MMI_BT_INQ_TYPE_HID_DEV;
    g_mmi_bt_scr_cntx.flag_extended &= ~MMI_BT_EXT_INQ_TYPE_PRINTER_DEV;
    g_mmi_bt_scr_cntx.flag_extended &= ~MMI_BT_EXT_INQ_TYPE_SPEC_COD_DEV;

    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_inq_complete
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  result      [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_inq_complete(MMI_BOOL result)   /* discov cfm or discov-cancel cfm */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 act_scr_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    act_scr_id = GetActiveScreenId();

    g_mmi_bt_scr_cntx.state = MMI_BT_SCR_STATE_NORMAL;

    /* it is to handle cancel inq command before bonding */
    /* 1. cancel inqiry */
    /* 2. start to bond after receiving cancel inq cfm */
    if (g_mmi_bt_scr_cntx.flag & MMI_BT_CANCEL_INQ_BEFORE_BOND ||
        g_mmi_bt_scr_cntx.flag & MMI_BT_CANCEL_INQ_All_DEV_BEFORE_BOND)
    {
        /* reset scr flag */
        if (g_mmi_bt_scr_cntx.flag & MMI_BT_CANCEL_INQ_All_DEV_BEFORE_BOND)
        {
            /* it is to let mmi_bt_entry_connect_confirm to check if it is required to display connect confirm */    
            g_mmi_bt_scr_cntx.flag |= MMI_BT_INQ_TYPE_ALL_DEV;
        }
        #if 0    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
        g_mmi_bt_scr_cntx.flag &= ~MMI_BT_CANCEL_INQ_BEFORE_BOND;
        g_mmi_bt_scr_cntx.flag &= ~MMI_BT_CANCEL_INQ_All_DEV_BEFORE_BOND;
        
        /* start the bonding process */
        if (!(*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_bond_req) ((U32) (g_mmi_bt_scr_cntx.hilight_item)))
        {
            DisplayPopup(
                (U8*) GetString(STR_BT_DEV_BUSY),
                IMG_GLOBAL_ERROR,
                MMI_FALSE,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
            /* notify bt AV that inquiry is stopped */
            #if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_A2DP_SUPPORT__)
            av_bt_inquiry_stop_callback();
            #endif
            /* to notify bt profile that inquiry is stopped */
            #if defined(__MMI_BT_AUDIO_VIA_SCO__) || defined(__MMI_BT_FM_VIA_SCO__)
            mmi_profiles_bt_inquery_stop_callback();
            #endif
            return;
        }
        /* notify bt AV that inquiry is stopped */
        #if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_A2DP_SUPPORT__)
        av_bt_inquiry_stop_callback();
        #endif
        
        /* to notify bt profile that inquiry is stopped */
        #if defined(__MMI_BT_AUDIO_VIA_SCO__) || defined(__MMI_BT_FM_VIA_SCO__)
        mmi_profiles_bt_inquery_stop_callback();
        #endif

        return;
    }
    else if (g_mmi_bt_scr_cntx.flag & MMI_BT_CANCEL_INQ_BEFORE_BT_CLOSE)
    {
        /* reset scr flag */
        g_mmi_bt_scr_cntx.flag &= ~MMI_BT_INQ_TYPE_OPP_DEV;
        g_mmi_bt_scr_cntx.flag &= ~MMI_BT_INQ_TYPE_A2DP_DEV;
        g_mmi_bt_scr_cntx.flag &= ~MMI_BT_INQ_TYPE_HID_DEV;
        g_mmi_bt_scr_cntx.flag_extended &= ~MMI_BT_EXT_INQ_TYPE_PRINTER_DEV;
        g_mmi_bt_scr_cntx.flag_extended &= ~MMI_BT_EXT_INQ_TYPE_SPEC_COD_DEV;
        g_mmi_bt_scr_cntx.flag &= ~MMI_BT_CANCEL_INQ_BEFORE_BT_CLOSE;
        mmi_bt_close();
        /* notify bt AV that inquiry is stopped */
        #if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_A2DP_SUPPORT__)
        av_bt_inquiry_stop_callback();
        #endif
        
        /* to notify bt profile that inquiry is stopped */
        #if defined(__MMI_BT_AUDIO_VIA_SCO__) || defined(__MMI_BT_FM_VIA_SCO__)
        mmi_profiles_bt_inquery_stop_callback();
        #endif

        return;
    }
    else if (g_mmi_bt_scr_cntx.flag & MMI_BT_CANCEL_INQ_BEFORE_BT_OPP_SEND)
    {

        if (act_scr_id != SCR_BT_SCH_CANCEL_PRO)
        {
            /* stop the animated title icon */
            wgui_stop_title_animation();
            /* reset scr flag */
            //mmi_bt_reset_scr_flag();
            g_mmi_bt_scr_cntx.flag &= ~MMI_BT_CANCEL_INQ_BEFORE_BT_OPP_SEND;
        #ifdef __MMI_OPP_SUPPORT__
            HistoryReplace(SCR_BT_SCH_CANCEL_PRO, SCR_BT_SCH_CANCEL_PRO, mmi_opp_send_file_obj);
        #endif 
        }
        else
        {
            /* stop progressing screen */
            mmi_bt_stop_progress_scr(MMI_FALSE);
            /* stop the animated title icon */
            wgui_stop_title_animation();
            /* reset scr flag */
            //mmi_bt_reset_scr_flag();
            g_mmi_bt_scr_cntx.flag &= ~MMI_BT_CANCEL_INQ_BEFORE_BT_OPP_SEND;
        #ifdef __MMI_OPP_SUPPORT__
            mmi_opp_send_file_obj();
        #endif 
        }
        /* notify bt AV that inquiry is stopped */
        #if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_A2DP_SUPPORT__)
        av_bt_inquiry_stop_callback();
        #endif
        
        /* to notify bt profile that inquiry is stopped */
        #if defined(__MMI_BT_AUDIO_VIA_SCO__) || defined(__MMI_BT_FM_VIA_SCO__)
        mmi_profiles_bt_inquery_stop_callback();
        #endif

        return;
    }

    if (act_scr_id != SCR_BT_SCH_PRO && act_scr_id != SCR_BT_SCH_RES && act_scr_id != SCR_BT_SCH_CANCEL_PRO)
    {
        SetDelScrnIDCallbackHandler(SCR_BT_SCH_PRO, (HistoryDelCBPtr) NULL);
        DeleteScreenIfPresent(SCR_BT_SCH_PRO);
        DeleteScreenIfPresent(SCR_BT_SCH_CANCEL_PRO);

        /* notify bt AV that inquiry is stopped */
        #if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_A2DP_SUPPORT__)
        av_bt_inquiry_stop_callback();
        #endif
        
        /* to notify bt profile that inquiry is stopped */
        #if defined(__MMI_BT_AUDIO_VIA_SCO__) || defined(__MMI_BT_FM_VIA_SCO__)
        mmi_profiles_bt_inquery_stop_callback();
        #endif
        
        return;
    }

    /* stop progressing screen */
    mmi_bt_stop_progress_scr(MMI_FALSE);
    /* stop the animated title icon */
    wgui_stop_title_animation();

    switch (act_scr_id)
    {
        case SCR_BT_SCH_PRO:
            /* GoBackHistory(); */
            /* it is to reset MMI_BT_RAMMASK_IS_AUTO_PWR_SWTICH */
            /* inqiry OPP dev will call mmi_bt_open() */
            mmi_bt_close();
            /* List Empty */
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_EMPTY),
                IMG_GLOBAL_EMPTY,
                MMI_FALSE,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) EMPTY_LIST_TONE);
            DeleteScreenIfPresent(SCR_BT_SCH_PRO);
            break;

        case SCR_BT_SCH_CANCEL_PRO:
            GoBackHistory();
            act_scr_id = GetActiveScreenId();
            if (act_scr_id != SCR_BT_SCH_RES)
            {
                /* it is to reset MMI_BT_RAMMASK_IS_AUTO_PWR_SWTICH */
                /* inqiry OPP dev will call mmi_bt_open() */
                mmi_bt_close();
            }

            break;
        case SCR_BT_SCH_RES:
			#if !defined(__MMI_BT_MTK_SUPPORT__) 
            if (g_mmi_bt_scr_cntx.flag & MMI_BT_INQ_TYPE_OPP_DEV)
            {
                SetLeftSoftkeyFunction(mmi_bt_opp_sending, KEY_EVENT_UP);
                SetKeyHandler(mmi_bt_opp_sending, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                EnableLeftSoftkey(STR_BT_SEND, IMG_GLOBAL_OK);
            }
            #endif
            /* change the RSK to be back */
            SetRightSoftkeyFunction(mmi_bt_inq_result_goback, KEY_EVENT_UP);
            SetKeyHandler(mmi_bt_inq_result_goback, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
            ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
            break;
        default:
            MMI_BT_ASSERT(0);
            break;

    }
    DeleteScreenIfPresent(SCR_BT_SCH_CANCEL_PRO);

    /* notify bt AV that inquiry is stopped */
    #if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_A2DP_SUPPORT__)
    av_bt_inquiry_stop_callback();
    #endif
    
    /* to notify bt profile that inquiry is stopped */
    #if defined(__MMI_BT_AUDIO_VIA_SCO__) || defined(__MMI_BT_FM_VIA_SCO__)
    mmi_profiles_bt_inquery_stop_callback();
    #endif

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_inq_result_cancel
 * DESCRIPTION
 *  This function is RSK handler for Extra->Bluetooth->search handfree (result)
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_inq_result_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 currScreenId;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetDelScrnIDCallbackHandler(SCR_BT_SCH_PRO, (HistoryDelCBPtr) NULL);
    
    if (mmi_bt_is_hw_ready(MMI_FALSE) == MMI_FALSE)
    {
        g_mmi_bt_scr_cntx.flag &= ~MMI_BT_AUTO_POWER_SWITCHIING;
        g_mmi_bt_scr_cntx.flag |= MMI_BT_AUTO_POWER_SWITCHIING_OFF;
        mmi_bt_stop_progress_scr(MMI_TRUE);
        return;
    }

    /* to avoid the error operation while bt module is busy */
    if ((mmi_bt_is_permission) (MMI_TRUE) == MMI_FALSE)
    {
        return;
    }

    currScreenId = GetActiveScreenId();
    if (currScreenId == SCR_BT_SCH_PRO)
    {
        /* reset inquiry flag */
        g_mmi_bt_scr_cntx.flag &= ~MMI_BT_INQ_TYPE_AUDIO;
        g_mmi_bt_scr_cntx.flag &= ~MMI_BT_INQ_TYPE_ALL_DEV;
        g_mmi_bt_scr_cntx.flag &= ~MMI_BT_INQ_TYPE_A2DP_DEV;
        g_mmi_bt_scr_cntx.flag &= ~MMI_BT_INQ_TYPE_OPP_DEV;
        g_mmi_bt_scr_cntx.flag &= ~MMI_BT_INQ_TYPE_HID_DEV;
        g_mmi_bt_scr_cntx.flag_extended &= ~MMI_BT_EXT_INQ_TYPE_PRINTER_DEV;
        g_mmi_bt_scr_cntx.flag_extended &= ~MMI_BT_EXT_INQ_TYPE_SPEC_COD_DEV;
		
    }    


    switch ((*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_state) ())
    {
        case MMI_BT_STAT_INIT_ON:
        case MMI_BT_STAT_ACTIVATE_SWITCHING:
            g_mmi_bt_scr_cntx.flag &= ~MMI_BT_AUTO_POWER_SWITCHIING;
            g_mmi_bt_scr_cntx.flag |= MMI_BT_AUTO_POWER_SWITCHIING_OFF;
            mmi_bt_stop_progress_scr(MMI_TRUE);
            break;

        case MMI_BT_STAT_INQUIRING:
        case MMI_BT_STAT_INQUIR_RES_IND:
            (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_inquiry_cancel_req) ((U8) g_mmi_bt_scr_cntx.flag);
            g_mmi_bt_scr_cntx.state = MMI_BT_SCR_STATE_CANCEL_INQ_WAIT_CFM;
            mmi_bt_show_progress_scr(
                    SCR_BT_SCH_CANCEL_PRO,
                    STR_BT_INQUIRY_STOP,
                    STR_BT_INQUIRY_STOPPING,
                    NULL,
                    MMI_FALSE,
                    NULL);
        default:
            if (g_mmi_bt_scr_cntx.state == MMI_BT_SCR_STATE_INQ_WAIT_CFM)
            {
                (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_inquiry_cancel_req) ((U8) g_mmi_bt_scr_cntx.flag);
                g_mmi_bt_scr_cntx.state = MMI_BT_SCR_STATE_CANCEL_INQ_WAIT_CFM;
                mmi_bt_show_progress_scr(
                    SCR_BT_SCH_CANCEL_PRO,
                    STR_BT_INQUIRY_STOP,
                    STR_BT_INQUIRY_STOPPING,
                    NULL,
                    MMI_FALSE,
                    NULL);
            }
            break;
    }
    DeleteScreenIfPresent(SCR_BT_SCH_PRO);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_inq_result_goback
 * DESCRIPTION
 *  This function is RSK handler for Extra->Bluetooth->search handfree (result)
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_inq_result_goback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* shall clear the endkey handler at goback, exit handler, delete scr callback */
    mmi_bt_clear_endkey_hdlr();

    SetDelScrnIDCallbackHandler(SCR_BT_SCH_RES, (HistoryDelCBPtr) NULL);

    /* reset inquiry flag */
    g_mmi_bt_scr_cntx.flag &= ~MMI_BT_INQ_TYPE_AUDIO;
    g_mmi_bt_scr_cntx.flag &= ~MMI_BT_INQ_TYPE_ALL_DEV;
    g_mmi_bt_scr_cntx.flag &= ~MMI_BT_INQ_TYPE_OPP_DEV;
    g_mmi_bt_scr_cntx.flag &= ~MMI_BT_INQ_TYPE_A2DP_DEV;
    g_mmi_bt_scr_cntx.flag &= ~MMI_BT_INQ_TYPE_HID_DEV;
    g_mmi_bt_scr_cntx.flag_extended &= ~MMI_BT_EXT_INQ_TYPE_PRINTER_DEV;
    g_mmi_bt_scr_cntx.flag_extended &= ~MMI_BT_EXT_INQ_TYPE_SPEC_COD_DEV;


    if (SCR_BT_SCH_RES == GetActiveScreenId())
    {
        GoBackHistory();
    }
    else
    {
        DeleteScreenIfPresent(SCR_BT_SCH_RES);
    }

    /* it is to reset MMI_BT_RAMMASK_IS_AUTO_PWR_SWTICH */
    /* inqiry OPP dev will call mmi_bt_open() */
    mmi_bt_close();


}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_inq_result_endkey
 * DESCRIPTION
 *  This function is END key handler for Extra->Bluetooth->search handfree (result)
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_inq_result_endkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* to avoid the error operation while bt module is busy */
    if ((mmi_bt_is_permission) (MMI_TRUE) == MMI_FALSE)
    {
        return;
    }

    SetDelScrnIDCallbackHandler(SCR_BT_SCH_RES, (HistoryDelCBPtr) NULL);

    state = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_state) ();

    /* reset inquiry flag */
    g_mmi_bt_scr_cntx.flag &= ~MMI_BT_INQ_TYPE_AUDIO;
    g_mmi_bt_scr_cntx.flag &= ~MMI_BT_INQ_TYPE_ALL_DEV;
    g_mmi_bt_scr_cntx.flag &= ~MMI_BT_INQ_TYPE_OPP_DEV;
    g_mmi_bt_scr_cntx.flag &= ~MMI_BT_INQ_TYPE_A2DP_DEV;
    g_mmi_bt_scr_cntx.flag &= ~MMI_BT_INQ_TYPE_HID_DEV;
    g_mmi_bt_scr_cntx.flag_extended &= ~MMI_BT_EXT_INQ_TYPE_PRINTER_DEV;
    g_mmi_bt_scr_cntx.flag_extended &= ~MMI_BT_EXT_INQ_TYPE_SPEC_COD_DEV;

    
    switch (state)
    {
        case MMI_BT_STAT_INQUIRING:
        case MMI_BT_STAT_INQUIR_RES_IND:
            (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_inquiry_cancel_req) ((U8) g_mmi_bt_scr_cntx.flag);
            g_mmi_bt_scr_cntx.flag |= MMI_BT_CANCEL_INQ_BEFORE_BT_CLOSE;
            g_mmi_bt_scr_cntx.state = MMI_BT_SCR_STATE_CANCEL_INQ_WAIT_CFM;
            break;
        default:
            if (g_mmi_bt_scr_cntx.state == MMI_BT_SCR_STATE_INQ_WAIT_CFM)
            {
                (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_inquiry_cancel_req) ((U8) g_mmi_bt_scr_cntx.flag);
                g_mmi_bt_scr_cntx.flag |= MMI_BT_CANCEL_INQ_BEFORE_BT_CLOSE;
                g_mmi_bt_scr_cntx.state = MMI_BT_SCR_STATE_CANCEL_INQ_WAIT_CFM;
                break;
            }
            /* it is to reset MMI_BT_RAMMASK_IS_AUTO_PWR_SWTICH */
            /* inqiry OPP dev will call mmi_bt_open() */
            mmi_bt_close();
            break;
    }

	mmi_bt_exe_endkey_hdlr();

	if(GetActiveScreenId()>=SCR_BT_SCH_PRO && GetActiveScreenId()<=SCR_BT_SCH_CANCEL_PRO)
	{
		GoBackHistory();
	}
	else
	{
		mmi_bt_del_scr(SCR_BT_SCH_PRO, SCR_BT_SCH_CANCEL_PRO);
	}
	
	
	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_bonding
 * DESCRIPTION
 *  This function is to Entry function for Extra->Bluetooth->search handfree
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_bonding(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 state;
    U8 max_paired_dev;
    mmi_bt_dev_struct *discov_dev_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_SCR_STATUS,
               g_mmi_bt_scr_cntx.state, g_mmi_bt_scr_cntx.flag, g_mmi_bt_scr_cntx.blinking_flag);

    /* to avoid the error operation while bt module is busy */
    if ((mmi_bt_is_permission) (MMI_TRUE) == MMI_FALSE)
    {
        return;
    }
    
    SetDelScrnIDCallbackHandler(SCR_BT_SCH_RES, (HistoryDelCBPtr) NULL);

    state = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_state) ();
    max_paired_dev = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_num) ();
    discov_dev_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_discov_dev_info) ((U8) (g_mmi_bt_scr_cntx.hilight_item));

    if (max_paired_dev >= MMI_BT_MAX_PAIRED_DEVICE_LIST && !mmi_bt_is_paired_device(&(discov_dev_p->bd_addr)))
    {
        /* cancel discovery first */
        if (state == MMI_BT_STAT_INQUIRING || state == MMI_BT_STAT_INQUIR_RES_IND ||
            g_mmi_bt_scr_cntx.state == MMI_BT_SCR_STATE_INQ_WAIT_CFM)
        {
            (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_inquiry_cancel_req) ((U8) g_mmi_bt_scr_cntx.flag);
            g_mmi_bt_scr_cntx.state = MMI_BT_SCR_STATE_CANCEL_INQ_WAIT_CFM;

        }
        DisplayPopup(
            (U8*) GetString(STR_BT_PAIRED_DEV_FULL),
            IMG_GLOBAL_ERROR,
            MMI_FALSE,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
        mmi_bt_del_scr(SCR_BT_POWER_PRO, SCR_BT_SCH_RES);
        return;

    }

    switch (state)
    {
        case MMI_BT_STAT_IDLE:
            if (!(*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_bond_req) ((U32) (g_mmi_bt_scr_cntx.hilight_item)))
            {
                DisplayPopup(
                    (U8*) GetString(STR_BT_DEV_BUSY),
                    IMG_GLOBAL_ERROR,
                    MMI_FALSE,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    (U8) ERROR_TONE);
                return;
            }
            break;
        case MMI_BT_STAT_INQUIRING:
        case MMI_BT_STAT_INQUIR_RES_IND:
            /* cancel discovery first */
            (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_inquiry_cancel_req) ((U8) g_mmi_bt_scr_cntx.flag);
            g_mmi_bt_scr_cntx.state = MMI_BT_SCR_STATE_CANCEL_INQ_WAIT_CFM;
            if (g_mmi_bt_scr_cntx.flag & MMI_BT_INQ_TYPE_ALL_DEV)
            {
                g_mmi_bt_scr_cntx.flag |= MMI_BT_CANCEL_INQ_All_DEV_BEFORE_BOND;
            }
            else
            {
                g_mmi_bt_scr_cntx.flag |= MMI_BT_CANCEL_INQ_BEFORE_BOND;
            }
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* 0 */ 
            break;
        default:
            if (g_mmi_bt_scr_cntx.state == MMI_BT_SCR_STATE_INQ_WAIT_CFM)
            {
                (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_inquiry_cancel_req) ((U8) g_mmi_bt_scr_cntx.flag);
                g_mmi_bt_scr_cntx.state = MMI_BT_SCR_STATE_CANCEL_INQ_WAIT_CFM;
                if (g_mmi_bt_scr_cntx.flag & MMI_BT_INQ_TYPE_ALL_DEV)
                {
                    g_mmi_bt_scr_cntx.flag |= MMI_BT_CANCEL_INQ_All_DEV_BEFORE_BOND;
                }
                else
                {
                    g_mmi_bt_scr_cntx.flag |= MMI_BT_CANCEL_INQ_BEFORE_BOND;
                }

            }
            break;
    }

    mmi_bt_show_progress_scr(SCR_BT_BOND, STR_BT_BOND, STR_BT_BONDING, NULL, MMI_FALSE, NULL);
    mmi_bt_del_scr(SCR_BT_POWER_PRO, SCR_BT_SCH_RES);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_opp_sending
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_opp_sending(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetDelScrnIDCallbackHandler(SCR_BT_SCH_RES, (HistoryDelCBPtr) NULL);

    /* reset inquiry flag */
    g_mmi_bt_scr_cntx.flag &= ~MMI_BT_INQ_TYPE_OPP_DEV;

    state = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_state) ();

    switch (state)
    {
        case MMI_BT_STAT_IDLE:
    #ifdef __MMI_OPP_SUPPORT__
            mmi_opp_send_file_obj();
    #endif 
            break;
        case MMI_BT_STAT_INQUIRING:
        case MMI_BT_STAT_INQUIR_RES_IND:
            mmi_bt_show_progress_scr(
                SCR_BT_SCH_CANCEL_PRO,
                STR_BT_INQUIRY_STOP,
                STR_BT_INQUIRY_STOPPING,
                NULL,
                MMI_FALSE,
                NULL);
            (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_inquiry_cancel_req) ((U8) g_mmi_bt_scr_cntx.flag);
            g_mmi_bt_scr_cntx.flag |= MMI_BT_CANCEL_INQ_BEFORE_BT_OPP_SEND;
            g_mmi_bt_scr_cntx.state = MMI_BT_SCR_STATE_CANCEL_INQ_WAIT_CFM;
            break;
        default:
            if (g_mmi_bt_scr_cntx.state == MMI_BT_SCR_STATE_INQ_WAIT_CFM)
            {
                mmi_bt_show_progress_scr(
                    SCR_BT_SCH_CANCEL_PRO,
                    STR_BT_INQUIRY_STOP,
                    STR_BT_INQUIRY_STOPPING,
                    NULL,
                    MMI_FALSE,
                    NULL);
                (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_inquiry_cancel_req) ((U8) g_mmi_bt_scr_cntx.flag);
                g_mmi_bt_scr_cntx.flag |= MMI_BT_CANCEL_INQ_BEFORE_BT_OPP_SEND;
                g_mmi_bt_scr_cntx.state = MMI_BT_SCR_STATE_CANCEL_INQ_WAIT_CFM;
            }
            break;
    }

    mmi_bt_del_scr(SCR_BT_SCH_PRO, SCR_BT_SCH_CANCEL_PRO);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_passkey_input
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_passkey_input()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index = 0;
    U8 utf8_char_cnt = 0, ucs2_str_len = 0, state;
    mmi_bt_dev_struct *dev_p;
    U8 ascii_buf[5];
    U8 usc2_buf[10];
    U16 curr_screen_id;
    U8 *guiBuffer;  /* Buffer holding history data */
    U8 *inputBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_bt_scr_cntx.flag & MMI_BT_SCO_FAR_END_LP_TESTING)
    {
        (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_pair_req) (&(g_mmi_bt_scr_cntx.far_end_dev_add),
                                                           g_mmi_bt_scr_cntx.far_end_dev_pin, MMI_TRUE);
        return;
    }

    /* replace history */
    curr_screen_id = GetActiveScreenId();
    state = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_state) ();

    if (curr_screen_id != SCR_BT_BOND && state != MMI_BT_STAT_PASSKEY_IND)
    {
        /* two cases that this entry fuction will be called */
        /* one is SCR_BT_SCH_PRO is in history and first result ind coming */
        /* for above case, shall replace the history SCR_BT_BOND by SCR_BT_PIN_INPUT */
        /* second is that this entry is called by ExecutePopHistory while interrup screen is finished */
        /* for above second case, IsBackHistory shall be TRUE */
        if (IsBackHistory == MMI_FALSE)
        {
            HistoryReplace(SCR_BT_BOND, SCR_BT_PIN_INPUT, mmi_bt_entry_passkey_input);
            return;
        }
    }

	/* play a tone for passkey input screen */
    if (IsBackHistory == MMI_FALSE && 
        !mmi_is_redrawing_bk_screens()
       )
	{
		/* play a general tone */
		playRequestedTone(GENERAL_TONE);
	}

    /* turn off backlight first before TurnOnBacklight(1) */
    /* it is to avoid that TurnOnBacklight(0) is called, if TurnOnBacklight(0) is called, TurnOnBacklight(1) doesnot work */
    /* so have to TurnOffBacklight() first */
    TurnOffBacklight();
    TurnOnBacklight(1);

    EntryNewScreen(SCR_BT_PIN_INPUT, mmi_bt_exit_passkey_input, NULL, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_BT_PIN_INPUT);
    inputBuffer = GetCurrInputBuffer(SCR_BT_PIN_INPUT);

    if (inputBuffer == NULL)
    {
        memset(g_mmi_bt_scr_cntx.ui_buf, 0, sizeof(U8) * MMI_BT_UI_BUF_SIZE);
        memset(g_mmi_bt_scr_cntx.pin_scr_buf, 0, sizeof(U8) * MMI_BT_PIN_SCR_BUF_SIZE);

        /* from bonding process or remote device send passkey ind */
        index = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_action_item_index) ();
        
        /* display device name of passkey requested device */
        switch (state)
        {
            case MMI_BT_STAT_BONDING:
                dev_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_discov_dev_info) ((U16) index);
                break;
            default:
                dev_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_info) ((U16) index);
                break;
        
        }
        
        /* Fill device name list */
        /* get byte count for convert utf8 string to UCS2 string */
        /* get character count of utf8 string */
        /* +1 is for UCS2 NULL terminate */
        /* *ENCODING_LENGTH is for byte count of one UCS2 character */
        utf8_char_cnt = (U8) ((mmi_chset_utf8_strlen((kal_uint8*) dev_p->name) + 1) * ENCODING_LENGTH);
        MMI_BT_ASSERT(MAX_SUB_MENU_HINT_SIZE >= MMI_BT_SCR_BD_NAME_LEN);
        if (utf8_char_cnt > MMI_BT_SCR_BD_NAME_LEN)
        {
            ucs2_str_len =
                (U8) mmi_chset_utf8_to_ucs2_string(
                        (kal_uint8*) hintData[0],
                        MMI_BT_SCR_BD_NAME_LEN,
                        (kal_uint8*) dev_p->name);
        }
        else
        {
            ucs2_str_len =
                (U8) mmi_chset_utf8_to_ucs2_string((kal_uint8*) hintData[0], utf8_char_cnt, (kal_uint8*) dev_p->name);
        }
		/* allow (MMI_BT_BD_NAME_LEN/3) chinese characters or (MMI_BT_BD_NAME_LEN/3)*2 english characters  */
		/* so for UCS2 encoding, need MMI_BT_SCR_BD_NAME_LEN bytes */

		/* shall check if there is any two_byte character mixed in one_bye UCS2 string */
		/* if yes, then truncate the string to meet above rules((MMI_BT_BD_NAME_LEN/3) chinese characters or (MMI_BT_BD_NAME_LEN/3)*2 english characters)*/	
		if(mmi_bt_test_ucs2((U16*)hintData[0], (U16)(ucs2_str_len/ENCODING_LENGTH)) )
		{ 
			mmi_bt_truncate_ucs2_string((U16*)hintData[0], 
		    							(U16)(ucs2_str_len/ENCODING_LENGTH),
		    							(U16)((MMI_BT_BD_NAME_LEN-2)/3)
		    						   );		    
		}

        
        mmi_ucs2cpy((S8*) hintData[1], (const S8*)GetString(STR_BT_ENTER_PASSCODE));
        
        /* STR_BT_ENTER_PASSCODE string */
        mmi_ucs2cpy((S8*) g_mmi_bt_scr_cntx.ui_buf, (const S8*)hintData[1]);
        /* "(" string */
        if (hintData[0][0] != 0)
        {
            memset(ascii_buf, 0, 5);
            memset(usc2_buf, 0, 10);
            kal_sprintf((S8*) ascii_buf, "(");
            mmi_asc_to_ucs2((S8*) usc2_buf, (S8*) ascii_buf);
            mmi_ucs2cat((S8*) g_mmi_bt_scr_cntx.ui_buf, (const S8*)usc2_buf);
        }
        /* Device name */
        mmi_ucs2cat((S8*) g_mmi_bt_scr_cntx.ui_buf, (const S8*)hintData[0]);
        /* ")" string */
        if (hintData[0][0] != 0)
        {
            memset(ascii_buf, 0, 5);
            memset(usc2_buf, 0, 10);
            kal_sprintf((S8*) ascii_buf, ")");
            mmi_asc_to_ucs2((S8*) usc2_buf, (S8*) ascii_buf);
            mmi_ucs2cat((S8*) g_mmi_bt_scr_cntx.ui_buf, (const S8*)usc2_buf);
        }
        /* ":" string */
        memset(ascii_buf, 0, 5);
        memset(usc2_buf, 0, 10);
        kal_sprintf((S8*) ascii_buf, ":");
        mmi_asc_to_ucs2((S8*) usc2_buf, (S8*) ascii_buf);
        mmi_ucs2cat((S8*) g_mmi_bt_scr_cntx.ui_buf, (const S8*)usc2_buf);
        
    }
    else
    {
        mmi_ucs2cpy((S8*) g_mmi_bt_scr_cntx.pin_scr_buf, (S8*) inputBuffer);
        /* donot need to update ui_buffer */
    }

    RegisterInputBoxValidationFunction(mmi_bt_passkey_validation_func);

    /* Store END key handler */
    mmi_bt_store_endkey_hdlr();

    ShowCategory111Screen_ext(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        /* STR_BT_ENTER_PASSCODE */ g_mmi_bt_scr_cntx.ui_buf,
        INPUT_TYPE_NUMERIC_PASSWORD,
        (U8*) (g_mmi_bt_scr_cntx.pin_scr_buf),
        MMI_BT_MAX_PASSKEY_LENGHT,
        NULL,
        0,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_bt_send_passkey, KEY_EVENT_UP);

    if (mmi_ucs2strlen((S8*) (g_mmi_bt_scr_cntx.pin_scr_buf)) < 1)
    {
        ChangeLeftSoftkey(0, 0);
    }

    SetCategory111RightSoftkeyFunction(mmi_bt_passkey_input_goback, KEY_EVENT_UP);

    SetKeyHandler(mmi_bt_passkey_input_endkey, KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);

    SetDelScrnIDCallbackHandler(SCR_BT_PIN_INPUT, (HistoryDelCBPtr) mmi_bt_passkey_input_scr_del_callback);

    DeleteScreenIfPresent(SCR_BT_BOND);
    /* DeleteScreenIfPresent(SCR_BT_SCH_RES); */

    /* starting a timer when the user is prompted for the passcode, */
    /* and then automatically send a SC_PASSKEY_RES to BT */
    /* if the user has not entered a passkey within a certain amount of time. */
    /* framework will provide this screen for us later */
    /* StartTimer(BT_PASSCODE_INPUT_PROMPTED_TIMER, MMI_BT_BT_PASSCODE_INPUT_PROMPTED_TIMER_DUR, mmi_bt_passkey_input_timeout_hdlr); */



}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_exit_passkey_input
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_exit_passkey_input(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history Scr;    /* * Variable to hold the history data */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* to hold the history data */
    Scr.scrnID = SCR_BT_PIN_INPUT;
    Scr.entryFuncPtr = mmi_bt_entry_passkey_input;
    mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) g_mmi_bt_scr_cntx.pin_scr_buf);
    GetCategoryHistory(Scr.guiBuffer);
    AddHistory(Scr);

    mmi_bt_clear_endkey_hdlr();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_passkey_validation_func
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  text        [?]             
 *  cursor      [?]             
 *  length      [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_passkey_validation_func(U8 *text, U8 *cursor, S32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((length) < 1)
    {
        ChangeLeftSoftkey(0, 0);
    }
    else
    {
        EnableLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_send_passkey
 * DESCRIPTION
 *  This function is to send passkey request
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_send_passkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 asc_pin_buf[32];
    mmi_bt_dev_struct *dev_info;
    U8 index, state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    (g_mmi_bt_scr_cntx.pin_scr_buf[(sizeof(U8) * MMI_BT_PIN_SCR_BUF_SIZE) - 1]) = '\0';
    (g_mmi_bt_scr_cntx.pin_scr_buf[(sizeof(U8) * MMI_BT_PIN_SCR_BUF_SIZE) - 2]) = '\0';

    mmi_ucs2_to_asc((S8*) asc_pin_buf, (S8*) g_mmi_bt_scr_cntx.pin_scr_buf);

	MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_SCR_SENDPINREQ,g_mmi_bt_scr_cntx.state,
               asc_pin_buf[0], asc_pin_buf[1], asc_pin_buf[2], asc_pin_buf[3],
               asc_pin_buf[4], asc_pin_buf[5], asc_pin_buf[6], asc_pin_buf[7]);

    index = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_action_item_index) ();
    state = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_state) ();

    SetDelScrnIDCallbackHandler(SCR_BT_PIN_INPUT, (HistoryDelCBPtr) NULL);

    switch (state)
    {
        case MMI_BT_STAT_BONDING:
            dev_info = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_discov_dev_info) ((U16) index);
			(*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_pair_req)(&(dev_info->bd_addr), asc_pin_buf, MMI_TRUE);
            mmi_bt_show_progress_scr(SCR_BT_PAIR_PRO, STR_BT_PAIR_REQ, STR_BT_START_PAIRING, NULL, MMI_FALSE, NULL);
            DeleteScreenIfPresent(SCR_BT_PIN_INPUT);
            break;
        default:
			dev_info = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_info)((U16)index);
			(*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_pair_req)(&(dev_info->bd_addr), asc_pin_buf, MMI_TRUE);
            GoBackHistory();
            break;
            
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_passkey_input_scr_del_callback
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_bt_passkey_input_scr_del_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 asc_pin_buf[32];
    mmi_bt_dev_struct *dev_info;
    U8 index, state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetDelScrnIDCallbackHandler(SCR_BT_PIN_INPUT, (HistoryDelCBPtr) NULL);

    /* return bonding failed codes to reject remote device's bonding */
    (g_mmi_bt_scr_cntx.pin_scr_buf[(sizeof(U8) * MMI_BT_PIN_SCR_BUF_SIZE) - 1]) = '\0';
    (g_mmi_bt_scr_cntx.pin_scr_buf[(sizeof(U8) * MMI_BT_PIN_SCR_BUF_SIZE) - 2]) = '\0';

    mmi_ucs2_to_asc((S8*) asc_pin_buf, (S8*) g_mmi_bt_scr_cntx.pin_scr_buf);

    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_SCR_SENDPINREQ,
               asc_pin_buf[0], asc_pin_buf[1], asc_pin_buf[2], asc_pin_buf[3],
               asc_pin_buf[4], asc_pin_buf[5], asc_pin_buf[6], asc_pin_buf[7]);

    index = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_action_item_index) ();
    state = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_state) ();

    switch (state)
    {
        case MMI_BT_STAT_BONDING:
            dev_info = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_discov_dev_info) ((U16) index);
            break;
        default:
            dev_info = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_info) ((U16) index);
            break;

    }

    (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_pair_req) (&(dev_info->bd_addr), asc_pin_buf, MMI_FALSE);

    mmi_bt_clear_endkey_hdlr();
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_passkey_input_goback
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_passkey_input_goback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 asc_pin_buf[32];
    mmi_bt_dev_struct *dev_info;
    U8 index, state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* return bonding failed codes to reject remote device's bonding */
    (g_mmi_bt_scr_cntx.pin_scr_buf[(sizeof(U8) * MMI_BT_PIN_SCR_BUF_SIZE) - 1]) = '\0';
    (g_mmi_bt_scr_cntx.pin_scr_buf[(sizeof(U8) * MMI_BT_PIN_SCR_BUF_SIZE) - 2]) = '\0';

    mmi_ucs2_to_asc((S8*) asc_pin_buf, (S8*) g_mmi_bt_scr_cntx.pin_scr_buf);

    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_SCR_SENDPINREQ,
               asc_pin_buf[0], asc_pin_buf[1], asc_pin_buf[2], asc_pin_buf[3],
               asc_pin_buf[4], asc_pin_buf[5], asc_pin_buf[6], asc_pin_buf[7]);

    index = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_action_item_index) ();
    state = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_state) ();

    SetDelScrnIDCallbackHandler(SCR_BT_PIN_INPUT, (HistoryDelCBPtr) NULL);

    switch (state)
    {
        case MMI_BT_STAT_BONDING:
            dev_info = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_discov_dev_info) ((U16) index);
            break;
        default:
            dev_info = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_info) ((U16) index);
            break;

    }

    (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_pair_req) (&(dev_info->bd_addr), asc_pin_buf, MMI_FALSE);

    mmi_bt_clear_endkey_hdlr();
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_passkey_input_endkey
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_passkey_input_endkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 asc_pin_buf[32];
    mmi_bt_dev_struct *dev_info;
    U8 index, state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* return bonding failed codes to reject remote device's bonding */
    (g_mmi_bt_scr_cntx.pin_scr_buf[(sizeof(U8) * MMI_BT_PIN_SCR_BUF_SIZE) - 1]) = '\0';
    (g_mmi_bt_scr_cntx.pin_scr_buf[(sizeof(U8) * MMI_BT_PIN_SCR_BUF_SIZE) - 2]) = '\0';

    mmi_ucs2_to_asc((S8*) asc_pin_buf, (S8*) g_mmi_bt_scr_cntx.pin_scr_buf);

    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_SCR_SENDPINREQ,
               asc_pin_buf[0], asc_pin_buf[1], asc_pin_buf[2], asc_pin_buf[3],
               asc_pin_buf[4], asc_pin_buf[5], asc_pin_buf[6], asc_pin_buf[7]);

    index = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_action_item_index) ();
    state = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_state) ();

    SetDelScrnIDCallbackHandler(SCR_BT_PIN_INPUT, (HistoryDelCBPtr) NULL);

    switch (state)
    {
        case MMI_BT_STAT_BONDING:
            dev_info = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_discov_dev_info) ((U16) index);
            break;
        default:
            dev_info = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_info) ((U16) index);
            break;
    }

    (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_pair_req) (&(dev_info->bd_addr), asc_pin_buf, MMI_FALSE);

    /* it is to reset MMI_BT_RAMMASK_IS_AUTO_PWR_SWTICH */
    /* inqiry OPP dev will call mmi_bt_open() */
    mmi_bt_close();

    /* execute endkey handler */
    mmi_bt_exe_endkey_hdlr();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_passkey_input_timeout_hdlr
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_passkey_input_timeout_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(BT_PASSCODE_INPUT_PROMPTED_TIMER);
    mmi_bt_passkey_input_goback();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_pair_result
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  res         [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_pair_result(MMI_BOOL res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 act_scr = GetActiveScreenId();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_SCR_STATUS,
               g_mmi_bt_scr_cntx.state, g_mmi_bt_scr_cntx.flag, g_mmi_bt_scr_cntx.blinking_flag);
    
    SetDelScrnIDCallbackHandler(SCR_BT_PIN_INPUT, (HistoryDelCBPtr) NULL);
    
	/* in order to simplify the pairing UI procedure, */
	/* remove the "paired" or "pairing failed" popup */
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
	#else
	if (act_scr == SCR_BT_MYDEV)
	{
        mmi_bt_update_mydev_menu();
	}
    mmi_bt_delete_screen(SCR_BT_PIN_INPUT, MMI_TRUE);
	#endif
	
    mmi_bt_stop_progress_scr(MMI_FALSE);
    mmi_bt_del_scr(SCR_BT_PIN_INPUT, SCR_BT_PAIR_PRO);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_bond_result
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  res         [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_bond_result(MMI_BOOL res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_SCR_STATUS,
               g_mmi_bt_scr_cntx.state, g_mmi_bt_scr_cntx.flag, g_mmi_bt_scr_cntx.blinking_flag);

    if (res == MMI_FALSE)
    {
        /* reset inquiry flag */
        g_mmi_bt_scr_cntx.flag &= ~MMI_BT_INQ_TYPE_AUDIO;
        g_mmi_bt_scr_cntx.flag &= ~MMI_BT_INQ_TYPE_ALL_DEV;
        g_mmi_bt_scr_cntx.flag &= ~MMI_BT_INQ_TYPE_A2DP_DEV;
        g_mmi_bt_scr_cntx.flag &= ~MMI_BT_INQ_TYPE_OPP_DEV;
        g_mmi_bt_scr_cntx.flag &= ~MMI_BT_INQ_TYPE_HID_DEV;
        g_mmi_bt_scr_cntx.flag_extended &= ~MMI_BT_EXT_INQ_TYPE_PRINTER_DEV;
        g_mmi_bt_scr_cntx.flag_extended &= ~MMI_BT_EXT_INQ_TYPE_SPEC_COD_DEV;

        DisplayPopup(
            (U8*) GetString(STR_BT_BOND_FAILED),
            IMG_GLOBAL_ERROR,
            MMI_FALSE,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
    }

    SetDelScrnIDCallbackHandler(SCR_BT_PIN_INPUT, (HistoryDelCBPtr) NULL);

    mmi_bt_del_scr(SCR_BT_BOND, SCR_BT_PAIR_PRO);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_connect_confirm
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_connect_confirm( /* MMI_BOOL res */ void) /* sdc close ind */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bt_dev_struct *dev_p;
    U16 i;
    U16 curr_screen_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_CONNECT_CONFIRM,
               g_mmi_bt_scr_cntx.select_device_cb,
               g_mmi_bt_scr_cntx.flag);
	


    /* replace history */
    curr_screen_id = GetActiveScreenId();
    if (curr_screen_id != SCR_BT_BOND && curr_screen_id != SCR_BT_PAIR_PRO)
    {
        /* two cases that this entry fuction will be called */
        /* one is SCR_BT_SCH_PRO is in history and first result ind coming */
        /* for above case, shall replace the history SCR_BT_BOND by SCR_BT_PIN_INPUT */
        /* second is that this entry is called by ExecutePopHistory while interrup screen is finished */
        /* for above second case, IsBackHistory shall be TRUE */
        if (IsBackHistory == MMI_FALSE)
        {
            if (IsScreenPresent(SCR_BT_BOND))
            {
                if ((g_mmi_bt_scr_cntx.flag & MMI_BT_INQ_TYPE_AUDIO))
                {
                    HistoryReplace(SCR_BT_BOND, SCR_BT_CONNECT_CNF, mmi_bt_entry_connect_confirm);
                }
                else if(g_mmi_bt_scr_cntx.flag & MMI_BT_INQ_TYPE_A2DP_DEV)
				{
		            i = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_action_item_index) ();
		            dev_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_info) (i);
		            memcpy(&(g_mmi_bt_scr_cntx.selected_spec_dev), dev_p, sizeof(mmi_bt_dev_struct));
					#if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_A2DP_SUPPORT__)
		            av_bt_headset_selected_callback(dev_p);
		            #endif
		            g_mmi_bt_scr_cntx.flag &= ~MMI_BT_INQ_TYPE_A2DP_DEV;
	    		    DeleteScreenIfPresent(SCR_BT_MY_SPECIFIC_DEV);
			    	DeleteScreenIfPresent(SCR_BT_MY_SPECIFIC_DEV_DUMMY);
                    DeleteScreenIfPresent(SCR_BT_PAIR_PRO);

		        }
                else if(g_mmi_bt_scr_cntx.flag & MMI_BT_INQ_TYPE_HID_DEV)
				{
		            i = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_action_item_index) ();
		            dev_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_info) (i);
		            memcpy(&(g_mmi_bt_scr_cntx.selected_spec_dev), dev_p, sizeof(mmi_bt_dev_struct));
		            #if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_HIDD_SUPPORT__)
		            //mmi_bt_hid_connect_selected_dev((mmi_bth_bt_addr)g_mmi_bt_scr_cntx.selected_spec_dev.bd_addr);
		            #endif
		            g_mmi_bt_scr_cntx.flag &= ~MMI_BT_INQ_TYPE_HID_DEV;
	    		    DeleteScreenIfPresent(SCR_BT_MY_SPECIFIC_DEV);
			    	DeleteScreenIfPresent(SCR_BT_MY_SPECIFIC_DEV_DUMMY);
                    DeleteScreenIfPresent(SCR_BT_PAIR_PRO);

				}
		        else if(g_mmi_bt_scr_cntx.flag & MMI_BT_INQ_TYPE_OPP_DEV)
		        {
		            i = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_action_item_index) ();
		            dev_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_info) (i);
		            memcpy(&(g_mmi_bt_scr_cntx.selected_spec_dev), dev_p, sizeof(mmi_bt_dev_struct));
		            g_mmi_bt_scr_cntx.flag &= ~MMI_BT_INQ_TYPE_OPP_DEV;
		            mmi_bt_opp_sending();
		    	    DeleteScreenIfPresent(SCR_BT_MY_SPECIFIC_DEV);
			    	DeleteScreenIfPresent(SCR_BT_MY_SPECIFIC_DEV_DUMMY);
                    DeleteScreenIfPresent(SCR_BT_PAIR_PRO);
		    		  
		    		  
		        }
                else if(g_mmi_bt_scr_cntx.flag_extended & MMI_BT_EXT_INQ_TYPE_PRINTER_DEV)
				{
		            i = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_action_item_index) ();
		            dev_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_info) (i);
		            memcpy(&(g_mmi_bt_scr_cntx.selected_spec_dev), dev_p, sizeof(mmi_bt_dev_struct));
		            g_mmi_bt_scr_cntx.flag_extended &= ~MMI_BT_EXT_INQ_TYPE_PRINTER_DEV;
					#if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_BPP_SUPPORT__)
					//(*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_connect_req) (&(dev_p->bd_addr), MMI_BT_BASIC_PRINTING);			
                    mmi_bt_bpp_printing(dev_p->bd_addr.nap, dev_p->bd_addr.uap, dev_p->bd_addr.lap);
		            #endif
	    		    DeleteScreenIfPresent(SCR_BT_MY_SPECIFIC_DEV);
			    	DeleteScreenIfPresent(SCR_BT_MY_SPECIFIC_DEV_DUMMY);
                    DeleteScreenIfPresent(SCR_BT_PAIR_PRO);

		        }
                else if(g_mmi_bt_scr_cntx.flag_extended & MMI_BT_EXT_INQ_TYPE_SPEC_COD_DEV)
				{
		            i = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_action_item_index) ();
		            dev_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_info) (i);
		            memcpy(&(g_mmi_bt_scr_cntx.selected_spec_dev), dev_p, sizeof(mmi_bt_dev_struct));
		            g_mmi_bt_scr_cntx.flag_extended &= ~MMI_BT_EXT_INQ_TYPE_SPEC_COD_DEV;
					if (g_mmi_bt_scr_cntx.select_device_cb != NULL)
					{
						if (mmi_bt_is_service_support(dev_p, g_mmi_bt_scr_cntx.specific_service_id))
						{
						    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_SELECT_DEVICE_CB,
               							MMI_TRUE, 
						        		dev_p->bd_addr.lap, 
						        		dev_p->bd_addr.uap, 
						        		dev_p->bd_addr.nap );
							(*g_mmi_bt_scr_cntx.select_device_cb)(MMI_TRUE, dev_p->bd_addr.lap, dev_p->bd_addr.uap, dev_p->bd_addr.nap);
						}
						else
					    {
						    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_SELECT_DEVICE_CB, MMI_FALSE, 0,0,0);
							(*g_mmi_bt_scr_cntx.select_device_cb)(MMI_FALSE, 0, 0, 0);
					    }
						g_mmi_bt_scr_cntx.select_device_cb = NULL;
					}
			    	DeleteScreenIfPresent(SCR_BT_MY_SPECIFIC_DEV);
			    	DeleteScreenIfPresent(SCR_BT_MY_SPECIFIC_DEV_DUMMY);
                    DeleteScreenIfPresent(SCR_BT_PAIR_PRO);

		        }
                else
                {
                    DeleteScreenIfPresent(SCR_BT_BOND);
                }
            }
            else
            {
                if ((g_mmi_bt_scr_cntx.flag & MMI_BT_INQ_TYPE_AUDIO))
                {
                    HistoryReplace(SCR_BT_PAIR_PRO, SCR_BT_CONNECT_CNF, mmi_bt_entry_connect_confirm);
                }
                else if(g_mmi_bt_scr_cntx.flag & MMI_BT_INQ_TYPE_A2DP_DEV)
 		        {
		            i = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_action_item_index) ();
		            dev_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_info) (i);
		            memcpy(&(g_mmi_bt_scr_cntx.selected_spec_dev), dev_p, sizeof(mmi_bt_dev_struct));
					#if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_A2DP_SUPPORT__)
		            av_bt_headset_selected_callback(dev_p);
		            #endif
		            g_mmi_bt_scr_cntx.flag &= ~MMI_BT_INQ_TYPE_A2DP_DEV;
		    	    DeleteScreenIfPresent(SCR_BT_MY_SPECIFIC_DEV);
			    	DeleteScreenIfPresent(SCR_BT_MY_SPECIFIC_DEV_DUMMY);
                    DeleteScreenIfPresent(SCR_BT_PAIR_PRO);

		        }
                else if(g_mmi_bt_scr_cntx.flag & MMI_BT_INQ_TYPE_HID_DEV)
 		        {
		            i = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_action_item_index) ();
		            dev_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_info) (i);
		            memcpy(&(g_mmi_bt_scr_cntx.selected_spec_dev), dev_p, sizeof(mmi_bt_dev_struct));
		            #if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_HIDD_SUPPORT__)
		            //mmi_bt_hid_connect_selected_dev((mmi_bth_bt_addr)g_mmi_bt_scr_cntx.selected_spec_dev.bd_addr);
		            #endif
		            g_mmi_bt_scr_cntx.flag &= ~MMI_BT_INQ_TYPE_HID_DEV;
		    	    DeleteScreenIfPresent(SCR_BT_MY_SPECIFIC_DEV);
			    	DeleteScreenIfPresent(SCR_BT_MY_SPECIFIC_DEV_DUMMY);
                    DeleteScreenIfPresent(SCR_BT_PAIR_PRO);

		        }
		        else if(g_mmi_bt_scr_cntx.flag & MMI_BT_INQ_TYPE_OPP_DEV)
		        {
		            i = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_action_item_index) ();
		            dev_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_info) (i);
		            memcpy(&(g_mmi_bt_scr_cntx.selected_spec_dev), dev_p, sizeof(mmi_bt_dev_struct));
		            g_mmi_bt_scr_cntx.flag &= ~MMI_BT_INQ_TYPE_OPP_DEV;
		            mmi_bt_opp_sending();
		    	    DeleteScreenIfPresent(SCR_BT_MY_SPECIFIC_DEV);
			    	DeleteScreenIfPresent(SCR_BT_MY_SPECIFIC_DEV_DUMMY);
                    DeleteScreenIfPresent(SCR_BT_PAIR_PRO);

		        }
                else if(g_mmi_bt_scr_cntx.flag_extended & MMI_BT_EXT_INQ_TYPE_PRINTER_DEV)
 		        {
		            i = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_action_item_index) ();
		            dev_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_info) (i);
		            memcpy(&(g_mmi_bt_scr_cntx.selected_spec_dev), dev_p, sizeof(mmi_bt_dev_struct));
		            g_mmi_bt_scr_cntx.flag_extended &= ~MMI_BT_EXT_INQ_TYPE_PRINTER_DEV;
					#if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_BPP_SUPPORT__)
					//(*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_connect_req) (&(dev_p->bd_addr), MMI_BT_BASIC_PRINTING);			
                    mmi_bt_bpp_printing(dev_p->bd_addr.nap, dev_p->bd_addr.uap, dev_p->bd_addr.lap);
		            #endif
		    	    DeleteScreenIfPresent(SCR_BT_MY_SPECIFIC_DEV);
			    	DeleteScreenIfPresent(SCR_BT_MY_SPECIFIC_DEV_DUMMY);
                    DeleteScreenIfPresent(SCR_BT_PAIR_PRO);

		        }
                else if(g_mmi_bt_scr_cntx.flag_extended & MMI_BT_EXT_INQ_TYPE_SPEC_COD_DEV)
 		        {
		            i = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_action_item_index) ();
		            dev_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_info) (i);
		            memcpy(&(g_mmi_bt_scr_cntx.selected_spec_dev), dev_p, sizeof(mmi_bt_dev_struct));
		            g_mmi_bt_scr_cntx.flag_extended &= ~MMI_BT_EXT_INQ_TYPE_SPEC_COD_DEV;
					if (g_mmi_bt_scr_cntx.select_device_cb != NULL)
					{
						if (mmi_bt_is_service_support(dev_p, g_mmi_bt_scr_cntx.specific_service_id))
						{
						    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_SELECT_DEVICE_CB,
               							MMI_TRUE, 
						        		dev_p->bd_addr.lap, 
						        		dev_p->bd_addr.uap, 
						        		dev_p->bd_addr.nap );
							(*g_mmi_bt_scr_cntx.select_device_cb)(MMI_TRUE, dev_p->bd_addr.lap, dev_p->bd_addr.uap, dev_p->bd_addr.nap);
						}
						else
					    {
						    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_SELECT_DEVICE_CB, MMI_FALSE, 0,0,0);
							(*g_mmi_bt_scr_cntx.select_device_cb)(MMI_FALSE, 0, 0, 0);
					    }
						g_mmi_bt_scr_cntx.select_device_cb = NULL;

					}
			    	DeleteScreenIfPresent(SCR_BT_MY_SPECIFIC_DEV);
			    	DeleteScreenIfPresent(SCR_BT_MY_SPECIFIC_DEV_DUMMY);
                    DeleteScreenIfPresent(SCR_BT_PAIR_PRO);

		        }
                else
                {
                    DeleteScreenIfPresent(SCR_BT_PAIR_PRO);
                }
            }
		    /* reset inquiry flag */
            g_mmi_bt_scr_cntx.flag &= ~MMI_BT_INQ_TYPE_ALL_DEV;
            g_mmi_bt_scr_cntx.flag &= ~MMI_BT_INQ_TYPE_A2DP_DEV;
            g_mmi_bt_scr_cntx.flag &= ~MMI_BT_INQ_TYPE_OPP_DEV;
            g_mmi_bt_scr_cntx.flag &= ~MMI_BT_INQ_TYPE_HID_DEV;
            g_mmi_bt_scr_cntx.flag_extended &= ~MMI_BT_EXT_INQ_TYPE_PRINTER_DEV;
            g_mmi_bt_scr_cntx.flag_extended &= ~MMI_BT_EXT_INQ_TYPE_SPEC_COD_DEV;

            return;
        }
    }

    /* connect confirm */
    #if 0
/* under construction !*/
    #endif
    mmi_bt_stop_progress_scr(MMI_FALSE);

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 
    /* paired device bonding will not come to this screen_action */
    /* it will lead user to paried device menu */
    if ((g_mmi_bt_scr_cntx.flag & MMI_BT_INQ_TYPE_AUDIO))
    {

        /* store connecting device address */
        i = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_action_item_index) ();
        dev_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_info) (i);
        memcpy(&(g_mmi_bt_scr_cntx.conn_dev_add), &(dev_p->bd_addr), sizeof(mmi_bt_dev_addr));

        /* connect with HFP profile always */
        g_mmi_bt_scr_cntx.conn_profile_id = MMI_BT_HF_PROFILE_UUID;
        /* connect confirm */
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
        #endif
        mmi_bt_display_connect_profile_connection_confirm(MMI_BT_INQ_TYPE_AUDIO);
    }
    else
    {
        if(g_mmi_bt_scr_cntx.flag & MMI_BT_INQ_TYPE_A2DP_DEV)
        {
            /* store connecting device address */
            i = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_action_item_index) ();
            dev_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_info) (i);

            memcpy(&(g_mmi_bt_scr_cntx.selected_spec_dev), dev_p, sizeof(mmi_bt_dev_struct));

			#if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_A2DP_SUPPORT__)
            av_bt_headset_selected_callback(dev_p);
            #endif
            g_mmi_bt_scr_cntx.flag &= ~MMI_BT_INQ_TYPE_A2DP_DEV;
	    	DeleteScreenIfPresent(SCR_BT_MY_SPECIFIC_DEV_DUMMY);
            /* it will lead user to audio bt setting menu */
            GoBacknHistory(1);

        }
        else if(g_mmi_bt_scr_cntx.flag & MMI_BT_INQ_TYPE_OPP_DEV)
        {
            /* store connecting device address */
            i = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_action_item_index) ();
            dev_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_info) (i);

            memcpy(&(g_mmi_bt_scr_cntx.selected_spec_dev), dev_p, sizeof(mmi_bt_dev_struct));
        
            g_mmi_bt_scr_cntx.flag &= ~MMI_BT_INQ_TYPE_OPP_DEV;
            mmi_bt_opp_sending();
    		DeleteScreenIfPresent(SCR_BT_MY_SPECIFIC_DEV);
	    	DeleteScreenIfPresent(SCR_BT_MY_SPECIFIC_DEV_DUMMY);
    		
        }
        else if(g_mmi_bt_scr_cntx.flag & MMI_BT_INQ_TYPE_HID_DEV)
        {
            /* store connecting device address */
            i = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_action_item_index) ();
            dev_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_info) (i);

            memcpy(&(g_mmi_bt_scr_cntx.selected_spec_dev), dev_p, sizeof(mmi_bt_dev_struct));
            #if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_HIDD_SUPPORT__)
            //mmi_bt_hid_connect_selected_dev((mmi_bth_bt_addr)g_mmi_bt_scr_cntx.selected_spec_dev.bd_addr);
            #endif
            g_mmi_bt_scr_cntx.flag &= ~MMI_BT_INQ_TYPE_HID_DEV;

            DeleteScreenIfPresent(SCR_BT_MY_SPECIFIC_DEV);
	    	DeleteScreenIfPresent(SCR_BT_MY_SPECIFIC_DEV_DUMMY);
            
        }
        else if(g_mmi_bt_scr_cntx.flag_extended & MMI_BT_EXT_INQ_TYPE_PRINTER_DEV)
        {
            /* store connecting device address */
            i = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_action_item_index) ();
            dev_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_info) (i);

            memcpy(&(g_mmi_bt_scr_cntx.selected_spec_dev), dev_p, sizeof(mmi_bt_dev_struct));
        
            g_mmi_bt_scr_cntx.flag_extended &= ~MMI_BT_EXT_INQ_TYPE_PRINTER_DEV;
			#if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_BPP_SUPPORT__)
			//(*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_connect_req) (&(dev_p->bd_addr), MMI_BT_BASIC_PRINTING);			
            mmi_bt_bpp_printing(dev_p->bd_addr.nap, dev_p->bd_addr.uap, dev_p->bd_addr.lap);
            #endif
    		DeleteScreenIfPresent(SCR_BT_MY_SPECIFIC_DEV);
	    	DeleteScreenIfPresent(SCR_BT_MY_SPECIFIC_DEV_DUMMY);
			
        }
        else if(g_mmi_bt_scr_cntx.flag_extended & MMI_BT_EXT_INQ_TYPE_SPEC_COD_DEV)
        {
            /* store connecting device address */
            i = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_action_item_index) ();
            dev_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_info) (i);

            memcpy(&(g_mmi_bt_scr_cntx.selected_spec_dev), dev_p, sizeof(mmi_bt_dev_struct));
        
            g_mmi_bt_scr_cntx.flag_extended &= ~MMI_BT_EXT_INQ_TYPE_SPEC_COD_DEV;
       		if (g_mmi_bt_scr_cntx.select_device_cb != NULL)
			{
				if (mmi_bt_is_service_support(dev_p, g_mmi_bt_scr_cntx.specific_service_id))
				{
				    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_SELECT_DEVICE_CB,
       							MMI_TRUE, 
				        		dev_p->bd_addr.lap, 
				        		dev_p->bd_addr.uap, 
				        		dev_p->bd_addr.nap );
					(*g_mmi_bt_scr_cntx.select_device_cb)(MMI_TRUE, dev_p->bd_addr.lap, dev_p->bd_addr.uap, dev_p->bd_addr.nap);
				}
				else
			    {
				    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_SELECT_DEVICE_CB, MMI_FALSE, 0, 0, 0);
					(*g_mmi_bt_scr_cntx.select_device_cb)(MMI_FALSE, 0, 0, 0);
			    }
				g_mmi_bt_scr_cntx.select_device_cb = NULL;
			}
	    	DeleteScreenIfPresent(SCR_BT_MY_SPECIFIC_DEV);
	    	DeleteScreenIfPresent(SCR_BT_MY_SPECIFIC_DEV_DUMMY);
			
        }
        else
        {
            /* it will lead user to paried device menu */
            GoBackHistory();
            /* reset MMI_BT_INQ_TYPE_ALL_DEV */
            g_mmi_bt_scr_cntx.flag &= ~MMI_BT_INQ_TYPE_ALL_DEV;
        }                
    }

    /* reset inquiry flag */
    g_mmi_bt_scr_cntx.flag &= ~MMI_BT_INQ_TYPE_ALL_DEV;
    g_mmi_bt_scr_cntx.flag &= ~MMI_BT_INQ_TYPE_A2DP_DEV;
    g_mmi_bt_scr_cntx.flag &= ~MMI_BT_INQ_TYPE_OPP_DEV;
    g_mmi_bt_scr_cntx.flag &= ~MMI_BT_INQ_TYPE_HID_DEV;
    g_mmi_bt_scr_cntx.flag_extended &= ~MMI_BT_EXT_INQ_TYPE_PRINTER_DEV;
    g_mmi_bt_scr_cntx.flag_extended &= ~MMI_BT_EXT_INQ_TYPE_SPEC_COD_DEV;

    DeleteScreenIfPresent(SCR_BT_PAIR_PRO);
    DeleteScreenIfPresent(SCR_BT_MYDEV_PROF_CHO);
    DeleteScreenIfPresent(SCR_BT_MYDEV_OPT);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_exit_connect_confirm
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_exit_connect_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bt_clear_endkey_hdlr();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_connect_confirm_goback
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_connect_confirm_goback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bt_clear_endkey_hdlr();
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_connect_confirm_endkey
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_connect_confirm_endkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //memset(&(g_mmi_bt_scr_cntx.conn_dev_add),0, sizeof(mmi_bt_dev_addr));
    //memset(&(g_mmi_bt_scr_cntx.conn_profile_id),0, sizeof(U32));
    mmi_bt_exe_endkey_hdlr();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_connecting
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_connecting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bt_dev_struct *dev_p;
    U32 i, service_list_index;
    U32 conn_profile_bit_mask;
    U16 paired_dev_num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* connect confirm */
    /* reset flag */
    g_mmi_bt_scr_cntx.flag &= ~MMI_BT_INQ_TYPE_AUDIO;

    /* to avoid the error operation while bt module is busy */
    if ((mmi_bt_is_permission) (MMI_TRUE) == MMI_FALSE)
    {
        DeleteScreenIfPresent(SCR_BT_CONNECT_CNF);
        return;
    }

    conn_profile_bit_mask = MMI_BT_CONNECTING_HS_PROFILE;

	/* use conn_dev_add to identify which dev to connect */
    paired_dev_num = (U8) g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_num();

    for (i = 0; i < paired_dev_num; i++)
    {
        dev_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_info) ((U16)i);
        if (dev_p->bd_addr.lap == g_mmi_bt_scr_cntx.conn_dev_add.lap
            && dev_p->bd_addr.uap == g_mmi_bt_scr_cntx.conn_dev_add.uap
            && dev_p->bd_addr.nap == g_mmi_bt_scr_cntx.conn_dev_add.nap)
        {
            break;
        }

	}

	if (i >= paired_dev_num)
	{
		return;
	}

	#if 0
/* under construction !*/
/* under construction !*/
	#endif

    dev_p = (mmi_bt_dev_struct*)(*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_info) ((U16)i);
    for (service_list_index = 0; service_list_index < dev_p->service_list_num; service_list_index++)
    {
        if (dev_p->service_list[service_list_index] == MMI_BT_HF_PROFILE_UUID)
        {
            conn_profile_bit_mask |= MMI_BT_CONNECTING_HF_PROFILE;
        }
        else if (dev_p->service_list[service_list_index] == MMI_BT_ADVANCED_AUDIO_PROFILE_UUID)
        {
            conn_profile_bit_mask |= MMI_BT_CONNECTING_A2DP_PROFILE;
        }
    }

    if (!(conn_profile_bit_mask & MMI_BT_CONNECTING_HF_PROFILE))
    {
        g_mmi_bt_scr_cntx.conn_profile_id = MMI_BT_HS_PROFILE_UUID;
    }
    else
    {
        conn_profile_bit_mask &= ~MMI_BT_CONNECTING_HS_PROFILE;
    }

    mmi_bt_connecting(&(g_mmi_bt_scr_cntx.conn_dev_add), g_mmi_bt_scr_cntx.conn_profile_id);

	#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif

}
void mmi_bt_exit_connecting(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_connecting
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  dev_addr        [?]             
 *  pro_uuid        [IN]            
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_connecting(mmi_bt_dev_addr *dev_addr, U32 pro_uuid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_SCR_CONN_RFCOM);
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_SCR_STATUS,
               g_mmi_bt_scr_cntx.state, g_mmi_bt_scr_cntx.flag, g_mmi_bt_scr_cntx.blinking_flag);
    
    mmi_bt_clear_endkey_hdlr();

    switch (mmi_bt_connecting_pre_check(dev_addr, pro_uuid))
    {
        case MMI_BT_ONE_HEADSET_CONNECTED:
            DisplayPopup(
                (U8*) GetString(STR_BT_ONE_HEADSET_ALREADY_CONNECTED),
                IMG_GLOBAL_ERROR,
                MMI_FALSE,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
            DeleteScreenIfPresent(SCR_BT_CONNECT_CNF);
            DeleteScreenIfPresent(SCR_BT_MYDEV_PROF_CHO);
            return;

        case MMI_BT_ONE_A2DP_CONNECTED:
            DisplayPopup(
                (U8*) GetString(STR_BT_ONE_HEADSET_ALREADY_CONNECTED),
                IMG_GLOBAL_ERROR,
                MMI_FALSE,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
            DeleteScreenIfPresent(SCR_BT_CONNECT_CNF);
            DeleteScreenIfPresent(SCR_BT_MYDEV_PROF_CHO);
            return;

        default:
            break;
    }

    /* filter some unsupported-connecting profiles */
    if (mmi_bt_check_supported_profile((U32*) support_connecting_profile_tbl, pro_uuid))
    {

        switch (pro_uuid)
        {
            case MMI_BT_HF_PROFILE_UUID:
            case MMI_BT_HS_PROFILE_UUID:
                break;
            case MMI_BT_ADVANCED_AUDIO_PROFILE_UUID:
                break;
            case MMI_BT_OBEX_OBJECT_PUSH_SERVICE_UUID:
        #if defined(__MMI_BT_PROHIBIT_OPP__)
                if (mmi_bt_is_a2dp_connected())
                {
                    DisplayPopup(
                        (U8*) GetString(STR_BT_PROHIBIT_BY_A2DP),
                        IMG_GLOBAL_ERROR,
                        MMI_FALSE,
                        UI_POPUP_NOTIFYDURATION_TIME,
                        (U8) ERROR_TONE);
                    return;
                }
        #endif /* defined(__MMI_BT_PROHIBIT_OPP__) */ 
                break;
            case MMI_BT_OBEX_FILE_TRANSFER_UUID:
            #if defined(__MMI_BT_PROHIBIT_FTP__)
                if (mmi_bt_is_a2dp_connected())
                {
                    DisplayPopup(
                        (U8*) GetString(STR_BT_PROHIBIT_BY_A2DP),
                        IMG_GLOBAL_ERROR,
                        MMI_FALSE,
                        UI_POPUP_NOTIFYDURATION_TIME,
                        (U8) ERROR_TONE);
                    return;
                }
            #endif /* defined(__MMI_BT_PROHIBIT_FTP__) */ 
                break;
            case MMI_BT_SPP_PROFILE_UUID:
            #if defined(__MMI_BT_PROHIBIT_SPP__)
                if (mmi_bt_is_a2dp_connected())
                {
                    DisplayPopup(
                        (U8*) GetString(STR_BT_PROHIBIT_BY_A2DP),
                        IMG_GLOBAL_ERROR,
                        MMI_FALSE,
                        UI_POPUP_NOTIFYDURATION_TIME,
                        (U8) ERROR_TONE);
                    return;
                }
            #endif /* defined(__MMI_BT_PROHIBIT_SPP__) */ 
                break;
            case MMI_BT_DUN_PROFILE_UUID:
            #if defined(__MMI_BT_PROHIBIT_DUN__)
                if (mmi_bt_is_a2dp_connected())
                {
                    DisplayPopup(
                        (U8*) GetString(STR_BT_PROHIBIT_BY_A2DP),
                        IMG_GLOBAL_ERROR,
                        MMI_FALSE,
                        UI_POPUP_NOTIFYDURATION_TIME,
                        (U8) ERROR_TONE);
                    return;
                }
            #endif /* defined(__MMI_BT_PROHIBIT_DUN__) */ 
                break;
            default:
                break;
        }

        /* pro_uuid == MMI_BT_HS_PROFILE_UUID, will notify user will try to connect with HFP if remote support HFP */
        /* the HSP connect req will send after MMI_BT_BT_POPUP_TIMER_DUR */
        {
            if (!(*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_connect_req) (dev_addr, pro_uuid))
            {
                DisplayPopup(
                    (U8*) GetString(STR_BT_DEV_BUSY),
                    IMG_GLOBAL_ERROR,
                    MMI_FALSE,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    (U8) ERROR_TONE);
                DeleteScreenIfPresent(SCR_BT_CONNECT_CNF);
                DeleteScreenIfPresent(SCR_BT_MYDEV_PROF_CHO);
                return;
            }
            else
            {
				g_mmi_bt_scr_cntx.connecting_profile = pro_uuid;
                /* FTP will handle UI screen */
                /* BIP */
                if (pro_uuid != MMI_BT_OBEX_FILE_TRANSFER_UUID && 
                    pro_uuid != MMI_BT_OBEX_IMAGING_RESPONDER_UUID)
                {
                    mmi_bt_show_progress_scr(
                        SCR_BT_CONNECTING,
                        STR_BT_CONNECT,
                        STR_BT_CONNECTING,
                        NULL,
                        MMI_FALSE,
                        NULL);
                }
                DeleteScreenIfPresent(SCR_BT_CONNECT_CNF);
                DeleteScreenIfPresent(SCR_BT_MYDEV_PROF_CHO);
            }
        }
    }
    else
    {
        DisplayPopup(
            (U8*) GetString(STR_BT_NOT_ALLOW),
            IMG_GLOBAL_ERROR,
            MMI_FALSE,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
        DeleteScreenIfPresent(SCR_BT_CONNECT_CNF);
        DeleteScreenIfPresent(SCR_BT_MYDEV_PROF_CHO);

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_connecting_hsp
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_connecting_hsp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bt_dev_addr *dev_addr;
    U32 pro_uuid;
    U16 act_scr_id;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dev_addr = &(g_mmi_bt_scr_cntx.conn_dev_add);
    pro_uuid = g_mmi_bt_scr_cntx.conn_profile_id;

    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_SCR_CONN_RFCOM);
    mmi_bt_clear_endkey_hdlr();
    g_mmi_bt_scr_cntx.flag &= ~MMI_BT_CONNECT_HFP_FIRST_NOTIFY; 

    switch (mmi_bt_connecting_pre_check(dev_addr, pro_uuid))
    {
        case MMI_BT_ONE_HEADSET_CONNECTED:
            DisplayPopup(
                (U8*) GetString(STR_BT_NOT_ALLOW),
                IMG_GLOBAL_ERROR,
                MMI_FALSE,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
            DeleteScreenIfPresent(SCR_BT_CONNECT_CNF);
            DeleteScreenIfPresent(SCR_BT_MYDEV_PROF_CHO);
            return;
        default:
            break;
    }


    act_scr_id = GetActiveScreenId();
    if(act_scr_id == SCR_BT_PIN_INPUT)
    {
        /* reject the passkey exchange while doing connecting */
        mmi_bt_passkey_input_scr_del_callback();
        GoBackHistory();
    }
            


    if (!(*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_connect_req) (dev_addr, pro_uuid))
    {
        DisplayPopup(
            (U8*) GetString(STR_BT_DEV_BUSY),
            IMG_GLOBAL_ERROR,
            MMI_FALSE,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
        DeleteScreenIfPresent(SCR_BT_CONNECT_CNF);
        DeleteScreenIfPresent(SCR_BT_MYDEV_PROF_CHO);
        return;
    }
    else
    {
        g_mmi_bt_scr_cntx.connecting_profile = (U32)MMI_BT_HS_PROFILE_UUID;
        mmi_bt_show_progress_scr(SCR_BT_CONNECTING, STR_BT_CONNECT, STR_BT_CONNECTING, NULL, MMI_FALSE, NULL);
        DeleteScreenIfPresent(SCR_BT_CONNECT_CNF);
        DeleteScreenIfPresent(SCR_BT_MYDEV_PROF_CHO);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_connect_complete
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  connection_type     [IN]            
 *  result              [IN]            
 *  a(?)                [IN/OUT]        First variable, used as returns
 *  b(?)                [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_connect_complete(U32 connection_type, MMI_BOOL result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *str_prof, *str_conn_res;
    U8 str_output[80], str_ucs2_space[4], str_asc_space[2];
    U16 act_scr = GetActiveScreenId();
	U32 connecting_profile = g_mmi_bt_scr_cntx.connecting_profile;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_SCR_PROF_CON_IND, connection_type, result, connecting_profile, act_scr);

    MMI_BT_ASSERT((connection_type < MMI_BT_LAST_CONNECTOIN_TYPE));

    /* update BT Status Icon */
    mmi_bt_update_status_icon();

    /* reset extend proc timer */
    g_mmi_bt_scr_cntx.extend_proc_timer = 0;



    /* stop progressing screen */
    if (act_scr == SCR_BT_CONNECTING)
    {
        if (connection_type == (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_connection_type)(connecting_profile) ||
            connection_type == MMI_BT_NO_CONNECTION || 
            result == MMI_FALSE || 
            (connection_type == MMI_BT_HFP_CONNECTION && connecting_profile == MMI_BT_HS_PROFILE_UUID) || 
            (connection_type == MMI_BT_HSP_CONNECTION && connecting_profile == MMI_BT_HF_PROFILE_UUID) || 
            (connection_type == MMI_BT_AVRCP_CT_CONNECTION && connecting_profile == MMI_BT_AV_REMOTE_CONTROL_TARGET_UUID)
           )
        {
	        g_mmi_bt_scr_cntx.connecting_profile = 0;
            mmi_bt_stop_progress_scr(MMI_FALSE);
        }
    }
	/* Configure Default Headset */
    else if((act_scr == SCR_BT_CONNECT_LAST_HEADSET) &&
            ((connection_type == MMI_BT_HFP_CONNECTION) ||
             (connection_type == MMI_BT_HSP_CONNECTION) ||
             (connection_type == MMI_BT_NO_CONNECTION)) )
    {
        mmi_bt_stop_progress_scr(MMI_FALSE);
    }
    else if (act_scr == SCR_BT_ACT_DEV)
    {
        mmi_bt_update_act_dev_screen();
    }
    else if (act_scr == SCR_BT_MYDEV_CONNECTED_PROF)
    {
        mmi_bt_update_mydev_connected_prof_screen();
    }
    else if (act_scr == SCR_BT_MYDEV_OPT)
    {
        mmi_bt_update_mydev_opt();
    }
    else if (act_scr == SCR_BT_MYDEV)
    {
        mmi_bt_update_mydev_menu();
    }
    

    if (g_mmi_bt_scr_cntx.flag & MMI_BT_SCO_FAR_END_LP_TESTING)
    {

        if (result)
        {
            /* setup sco */
            mmi_bt_hfp_sco_link_connect_req();
        }
        else
        {
            if (g_mmi_bt_scr_cntx.test_by_at)
            {
		        mmi_at_general_res_req_struct *res_p;

		        res_p = construct_local_para(sizeof(mmi_at_general_res_req_struct), TD_UL);
		        /* indicate L4 AT module failed */
		        res_p->result = MMI_FALSE;

                /* indicate L4 AT module succeeded or failed */
                mmi_bt_send_l4_msg(MSG_ID_MMI_AT_GENERAL_RES_REQ, (void*)res_p, NULL);
                g_mmi_bt_scr_cntx.test_by_at = 0;
            }
            else
            {
				if (g_mmi_bt_scr_cntx.test_by_em)
				{
		            /* call back engineering...failed */
		            EmBTNotifyLoopbackDoneCnf(MMI_FALSE);
					g_mmi_bt_scr_cntx.test_by_em = 0;
				}
            }

            /* reset flag */
            /* mmi_bt_reset_scr_flag(); */

            (g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_mydev_remove_req) (&(g_mmi_bt_scr_cntx.far_end_dev_add));

            /* deactivate bluetooth services */
            (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_deactivate_req) ();

        }
        return;
    }

    /* to filter out OPP and FTP */
    /* OPP and FTP donot expect to see BT CM's connected popup screen */
    /* move this check to MMI screen layer, need MMI screen to update bt status icon */
    if (connection_type == MMI_BT_OPP_CONNECTION || connection_type == MMI_BT_FTP_CONNECTION ||
        connection_type == MMI_BT_BPP_CONNECTION || connection_type == MMI_BT_BIP_CONNECTION || connection_type == MMI_BT_HID_CONNECTION)
    {


        if (connection_type == (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_connection_type)(connecting_profile) ||
            connection_type == MMI_BT_NO_CONNECTION || 
            result == MMI_FALSE ||
            (connection_type == MMI_BT_HFP_CONNECTION && connecting_profile == MMI_BT_HS_PROFILE_UUID) ||
            (connection_type == MMI_BT_HSP_CONNECTION && connecting_profile == MMI_BT_HF_PROFILE_UUID) )
        {
	        g_mmi_bt_scr_cntx.connecting_profile = 0;
                DeleteScreenIfPresent(SCR_BT_CONNECTING);
			/* Configure Default Headset */
			DeleteScreenIfPresent(SCR_BT_CONNECT_LAST_HEADSET);
	        DeleteScreenIfPresent(SCR_BT_MYDEV_OPT);
	        DeleteScreenIfPresent(SCR_BT_MYDEV_PROF_CHO);
        }
        return;
    }

    switch (connection_type)
    {
        case MMI_BT_NO_CONNECTION:
            str_prof = (U8*) GetString(STR_BT_CONNECTING);
            break;

        case MMI_BT_HSP_CONNECTION:
            str_prof = (U8*) GetString(STR_BT_PROF_HS);
            /* update earphone Status Icon */
            break;

        case MMI_BT_HFP_CONNECTION:
            str_prof = (U8*) GetString(STR_BT_PROF_HF);
            /* update earphone Status Icon */
            break;

        case MMI_BT_DUN_CONNECTION:
            str_prof = (U8*) GetString(STR_BT_PROF_DUN);
            break;

        case MMI_BT_SPP_CONNECTION:
            str_prof = (U8*) GetString(STR_BT_PROF_SPP);
            break;

        case MMI_BT_FTP_CONNECTION:
            str_prof = (U8*) GetString(STR_BT_PROF_FTP);
            break;

        case MMI_BT_OPP_CONNECTION:
            str_prof = (U8*) GetString(STR_BT_PROF_OPP);
            break;

        case MMI_BT_A2DP_CONNECTION:
            str_prof = (U8*) GetString(STR_BT_PROF_A2DP);
            /* update earphone Status Icon */
            if (result == MMI_TRUE)
            {

                /* prohitbit some services while a2dp is active */
                /* prohibit OPS->FTS->SPP->DUN profiles */
            #ifdef __MMI_BT_PROHIBIT_OPP__
                (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_prohibit_opp_req) ();
            #elif defined(__MMI_BT_PROHIBIT_FTP__)
                (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_prohibit_ftp_req) ();
            #elif defined(__MMI_BT_PROHIBIT_SPP__)
                (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_prohibit_spp_req) ();
            #elif defined(__MMI_BT_PROHIBIT_DUN__)
                (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_prohibit_dun_req) ();
            #endif 

            }
            break;
        case MMI_BT_AVRCP_CONNECTION:
            str_prof = (U8*) GetString(STR_BT_PROF_AVRCP_T);
            break;
        case MMI_BT_AVRCP_CT_CONNECTION:
            str_prof = (U8*) GetString(STR_BT_PROF_AVRCP);
            break;

        case MMI_BT_BPP_CONNECTION:
            str_prof = (U8*) GetString(STR_BT_PROF_BASIC_PRINTING);
            break;
            
        case MMI_BT_SIMAP_CONNECTION:
            str_prof = (U8*) GetString(STR_BT_PROF_SAP);
            break;

        case MMI_BT_FAX_CONNECTION:
            str_prof = (U8*) GetString(STR_BT_PROF_FAX);
            break;

        case MMI_BT_HID_CONNECTION:
            str_prof = (U8*) GetString(STR_BT_PROF_HID);
            break;

        case MMI_BT_BIP_CONNECTION:
            str_prof = (U8*) GetString(STR_BT_PROF_OBEX_IMAGING);
            break;
        
        default:
            str_prof = (U8*) GetString(STR_BT_PROF_UNKNOWN);
            MMI_BT_ASSERT(0);
            break;
    }

    if (result == MMI_TRUE)
    {
        str_conn_res = (U8*) GetString(STR_BT_CONN_ED);
    }
    else
    {
        str_prof = (U8*) GetString(STR_BT_CONNECT);
        str_conn_res = (U8*) GetString(STR_BT_FAILED);
    }

    memset(str_output, 0, sizeof(U8) * 80);
    memset(str_asc_space, 0, sizeof(U8) * 2);
    memset(str_ucs2_space, 0, sizeof(U8) * 4);
    kal_sprintf((S8*) str_asc_space, " ");
    mmi_asc_to_ucs2((S8*) str_ucs2_space, (S8*) str_asc_space);

    mmi_ucs2cpy((S8*) str_output, (const S8*)str_prof);
    /* space is reserved in ref_list.txt for alphabetical languages */ 
    /* for Chinese language, space is not required */
    //mmi_ucs2cat((S8*) str_output, (const S8*)str_ucs2_space);
    /* check if str_prof string length + 2 + str_conn_res string length >= str_output */
    MMI_BT_ASSERT(((mmi_ucs2strlen((const S8*)str_prof) * ENCODING_LENGTH) + 2 +
                   (mmi_ucs2strlen((const S8*)str_conn_res) * ENCODING_LENGTH)) < (sizeof(U8) * 80));
    mmi_ucs2cat((S8*) str_output, (const S8*)str_conn_res);

	 #if defined(__MMI_BT_MTK_SUPPORT__)
	 if (!((connection_type == MMI_BT_A2DP_CONNECTION && (connecting_profile != MMI_BT_ADVANCED_AUDIO_PROFILE_UUID)) ||
	       (connection_type == MMI_BT_AVRCP_CONNECTION && (connecting_profile != MMI_BT_AV_REMOTE_CONTROL_UUID))
	      ) 
	    )
	 #endif	
	 {
		if (result == MMI_TRUE)
		{
            #if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_HIDD_SUPPORT__)
			if (connection_type == MMI_BT_HID_CONNECTION)
			{
				mmi_bt_entry_hid_app_select();
				DeleteScreenIfPresent(SCR_BT_CONNECTING);
			}
			else
			#endif    
		    {
		    	DisplayPopup(str_output, IMG_GLOBAL_ACTIVATED, MMI_FALSE, UI_POPUP_NOTIFYDURATION_TIME, (U8) SUCCESS_TONE);
			}
		}
		else
		{
		    DisplayPopup(str_output, IMG_GLOBAL_WARNING, MMI_FALSE, UI_POPUP_NOTIFYDURATION_TIME, (U8) WARNING_TONE);
		}
	}

   if (connection_type == (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_connection_type)(connecting_profile) ||
        connection_type == MMI_BT_NO_CONNECTION || 
        result == MMI_FALSE ||
        (connection_type == MMI_BT_HFP_CONNECTION && connecting_profile == MMI_BT_HS_PROFILE_UUID) ||
        (connection_type == MMI_BT_HSP_CONNECTION && connecting_profile == MMI_BT_HF_PROFILE_UUID))
    {
        g_mmi_bt_scr_cntx.connecting_profile = 0;
        DeleteScreenIfPresent(SCR_BT_CONNECTING);
		/* Configure Default Headset */
		DeleteScreenIfPresent(SCR_BT_CONNECT_LAST_HEADSET);
		DeleteScreenIfPresent(SCR_BT_MYDEV_OPT);
		DeleteScreenIfPresent(SCR_BT_MYDEV_PROF_CHO);
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_connect_accept_cnf_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  name_p              [?]         [?]
 *  uap                 [IN]        
 *  lap                 [IN]        
 *  nap                 [IN]        
 *  conn_id             [IN]        
 *  prof_id             [IN]        
 *  conn_type(?)        [IN]        
 *  a(?)            [IN/OUT]        First variable, used as returns(?)
 *  b(?)            [IN]            Second variable(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_connect_accept_cnf_req(U8 *name_p, U32 uap, U8 lap, U16 nap, U32 conn_id, U32 prof_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_SPEECH_SWITCH)
    {
    	/* allow only one authorize device information one time, so shall finish other authorization first */
        mmi_bt_connect_authorise_scr_del_callback();
    }
    g_mmi_bt_scr_cntx.authorize_name_p = name_p;
    g_mmi_bt_scr_cntx.authorize_dev_add.nap = nap;
    g_mmi_bt_scr_cntx.authorize_dev_add.uap = uap;
    g_mmi_bt_scr_cntx.authorize_dev_add.lap = lap;
    g_mmi_bt_scr_cntx.authorize_conn_id = conn_id;
    g_mmi_bt_scr_cntx.authorize_prof_id = prof_id;

    mmi_bt_entry_connect_accept_cnf();

    DeleteScreenIfPresent(SCR_BT_CONNECT_AUTHORIZE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_connect_accept_cnf
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns(?)
 *  b(?)        [IN]            Second variable(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_connect_accept_cnf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 utf8_char_cnt = 0, ucs2_str_len = 0;
    U8 ascii_buf[5];
    U8 usc2_buf[10];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_BT_CONNECT_ACCEPT_CNF, mmi_bt_exit_connect_accept_cnf, mmi_bt_entry_connect_accept_cnf, NULL);

    /* turn off backlight first before TurnOnBacklight(1) */
    /* it is to avoid that TurnOnBacklight(0) is called, if TurnOnBacklight(0) is called, TurnOnBacklight(1) doesnot work */
    /* so have to TurnOffBacklight() first */
    TurnOffBacklight();
    TurnOnBacklight(1);

    /* Store END key handler */
    mmi_bt_store_endkey_hdlr();

    memset(g_mmi_bt_scr_cntx.ui_buf, 0, sizeof(U8) * MMI_BT_UI_BUF_SIZE);

    /* Fill device name */
    /* get byte count for convert utf8 string to UCS2 string */
    /* get character count of utf8 string */
    /* +1 is for UCS2 NULL terminate */
    /* *ENCODING_LENGTH is for byte count of one UCS2 character */
    MMI_ASSERT(g_mmi_bt_scr_cntx.authorize_name_p != NULL);
    utf8_char_cnt =
        (U8) ((mmi_chset_utf8_strlen((kal_uint8*) g_mmi_bt_scr_cntx.authorize_name_p) + 1) * ENCODING_LENGTH);
    MMI_BT_ASSERT(MAX_SUB_MENU_HINT_SIZE >= MMI_BT_SCR_BD_NAME_LEN);
    if (utf8_char_cnt > MMI_BT_SCR_BD_NAME_LEN)
    {
        ucs2_str_len =
            (U8) mmi_chset_utf8_to_ucs2_string(
                    (kal_uint8*) hintData[0],
                    MMI_BT_SCR_BD_NAME_LEN,
                    (kal_uint8*) g_mmi_bt_scr_cntx.authorize_name_p);
    }
    else
    {
        ucs2_str_len =
            (U8) mmi_chset_utf8_to_ucs2_string(
                    (kal_uint8*) hintData[0],
                    utf8_char_cnt,
                    (kal_uint8*) g_mmi_bt_scr_cntx.authorize_name_p);
    }

	/* allow (MMI_BT_BD_NAME_LEN/3) chinese characters or (MMI_BT_BD_NAME_LEN/3)*2 english characters  */
	/* so for UCS2 encoding, need MMI_BT_SCR_BD_NAME_LEN bytes */

	/* shall check if there is any two_byte character mixed in one_bye UCS2 string */
	/* if yes, then truncate the string to meet above rules((MMI_BT_BD_NAME_LEN/3) chinese characters or (MMI_BT_BD_NAME_LEN/3)*2 english characters)*/	
	if(mmi_bt_test_ucs2((U16*)hintData[0], (U16)(ucs2_str_len/ENCODING_LENGTH)) )
	{ 
		mmi_bt_truncate_ucs2_string((U16*)hintData[0], 
		    							(U16)(ucs2_str_len/ENCODING_LENGTH),
		    							(U16)((MMI_BT_BD_NAME_LEN-2)/3)
		    						   );		    
	}

    mmi_ucs2cpy((S8*) hintData[1], (const S8*)GetString(STR_BT_ACCEPT_CONNECT_FROM));

    /* STR_BT_ACCEPT_CONNECT_FROM string */
    mmi_ucs2cpy((S8*) g_mmi_bt_scr_cntx.ui_buf, (const S8*)hintData[1]);
    /* " " string */
    if (hintData[0][0] != 0)
    {
        memset(ascii_buf, 0, 5);
        memset(usc2_buf, 0, 10);
        kal_sprintf((S8*) ascii_buf, " ");
        mmi_asc_to_ucs2((S8*) usc2_buf, (S8*) ascii_buf);
        mmi_ucs2cat((S8*) g_mmi_bt_scr_cntx.ui_buf, (const S8*)usc2_buf);
    }
    /* Device name */
    mmi_ucs2cat((S8*) g_mmi_bt_scr_cntx.ui_buf, (const S8*)hintData[0]);
    
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif

    ShowCategory7Screen(
        STR_BT_MENU_TITLE,
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (U8*) g_mmi_bt_scr_cntx.ui_buf,
        NULL);

    if (!mmi_is_redrawing_bk_screens())
    { 
	    /* play a warning tone */
	    playRequestedTone(WARNING_TONE);
	}



    SetLeftSoftkeyFunction(mmi_bt_connect_accept_cnf_accepted, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_bt_connect_accept_cnf_rejected, KEY_EVENT_UP);
    SetDelScrnIDCallbackHandler(
        SCR_BT_CONNECT_ACCEPT_CNF,
        (HistoryDelCBPtr) mmi_bt_connect_accept_cnf_scr_del_callback);

    SetKeyHandler(NULL, KEY_END, KEY_EVENT_UP);
    SetKeyHandler(mmi_bt_connect_accept_cnf_end_key, KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_exit_connect_accept_cnf
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns(?)
 *  b(?)        [IN]            Second variable(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_exit_connect_accept_cnf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bt_clear_endkey_hdlr();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_connect_accept_cnf_scr_del_callback
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns(?)
 *  b(?)        [IN]            Second variable(?)
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_bt_connect_accept_cnf_scr_del_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetDelScrnIDCallbackHandler(SCR_BT_CONNECT_ACCEPT_CNF, (HistoryDelCBPtr) NULL);
    if (g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_connect_accept_cnf_res)
    {
        /* reject */
        (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_connect_accept_cnf_res) (&(g_mmi_bt_scr_cntx.authorize_dev_add),
                                                                         g_mmi_bt_scr_cntx.authorize_prof_id,
                                                                         MMI_FALSE);
    }
    mmi_bt_clear_endkey_hdlr();

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_connect_accept_cnf_accepted
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns(?)
 *  b(?)        [IN]            Second variable(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_connect_accept_cnf_accepted(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetDelScrnIDCallbackHandler(SCR_BT_CONNECT_ACCEPT_CNF, (HistoryDelCBPtr) NULL);
    if (g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_connect_accept_cnf_res)
    {
        /* accept */
        (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_connect_accept_cnf_res) (&(g_mmi_bt_scr_cntx.authorize_dev_add),
                                                                         g_mmi_bt_scr_cntx.authorize_prof_id, MMI_TRUE);
    }

    mmi_bt_clear_endkey_hdlr();

    GoBackHistory();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_connect_accept_cnf_rejected
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns(?)
 *  b(?)        [IN]            Second variable(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_connect_accept_cnf_rejected(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetDelScrnIDCallbackHandler(SCR_BT_CONNECT_ACCEPT_CNF, (HistoryDelCBPtr) NULL);
    if (g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_connect_accept_cnf_res)
    {
        /* rejec */
        (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_connect_accept_cnf_res) (&(g_mmi_bt_scr_cntx.authorize_dev_add),
                                                                         g_mmi_bt_scr_cntx.authorize_prof_id,
                                                                         MMI_FALSE);
    }

    mmi_bt_clear_endkey_hdlr();

    GoBackHistory();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_connect_accept_cnf_end_key
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns(?)
 *  b(?)        [IN]            Second variable(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_connect_accept_cnf_end_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetDelScrnIDCallbackHandler(SCR_BT_CONNECT_ACCEPT_CNF, (HistoryDelCBPtr) NULL);
    /* execute endkey handler */
    mmi_bt_exe_endkey_hdlr();
    mmi_bt_clear_endkey_hdlr();

    if (g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_connect_accept_cnf_res)
    {
        /* reject */
        (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_connect_accept_cnf_res) (&(g_mmi_bt_scr_cntx.authorize_dev_add),
                                                                         g_mmi_bt_scr_cntx.authorize_prof_id,
                                                                         MMI_FALSE);
    }

    DeleteScreenIfPresent(SCR_BT_CONNECT_ACCEPT_CNF);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_connect_authorise_ind
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  name_p          [?]             
 *  conn_id         [IN]            
 *  conn_type       [IN]            
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_connect_authorise_ind(U8 *name_p, /* mmi_bt_dev_addr bd_addr, */ U32 conn_id, U32 conn_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_bt_scr_cntx.flag |= MMI_BT_CONFIRM_SPEECH_SWITCH;

    g_mmi_bt_scr_cntx.authorize_name_p = name_p;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 
    g_mmi_bt_scr_cntx.authorize_conn_id = conn_id;
    g_mmi_bt_scr_cntx.authorize_conn_type = conn_type;

    mmi_bt_entry_connect_authorise();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_connect_authorise
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_connect_authorise(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 utf8_char_cnt = 0, ucs2_str_len = 0;
    U8 ascii_buf[5];
    U8 usc2_buf[10];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_BT_CONNECT_AUTHORIZE, mmi_bt_exit_connect_authorise, mmi_bt_entry_connect_authorise, NULL);

    
    /* turn off backlight first before TurnOnBacklight(1) */
    /* it is to avoid that TurnOnBacklight(0) is called, if TurnOnBacklight(0) is called, TurnOnBacklight(1) doesnot work */
    /* so have to TurnOffBacklight() first */
    //TurnOffBacklight();
    //TurnOnBacklight(1);

    /* Store END key handler */
    mmi_bt_store_endkey_hdlr();

    memset(g_mmi_bt_scr_cntx.ui_buf, 0, sizeof(U8) * MMI_BT_UI_BUF_SIZE);

    /* Fill device name */
    /* get byte count for convert utf8 string to UCS2 string */
    /* get character count of utf8 string */
    /* +1 is for UCS2 NULL terminate */
    /* *ENCODING_LENGTH is for byte count of one UCS2 character */
    MMI_ASSERT(g_mmi_bt_scr_cntx.authorize_name_p != NULL);
    utf8_char_cnt =
        (U8) ((mmi_chset_utf8_strlen((kal_uint8*) g_mmi_bt_scr_cntx.authorize_name_p) + 1) * ENCODING_LENGTH);
    MMI_BT_ASSERT(MAX_SUB_MENU_HINT_SIZE >= MMI_BT_SCR_BD_NAME_LEN);
    if (utf8_char_cnt > MMI_BT_SCR_BD_NAME_LEN)
    {
        ucs2_str_len =
            (U8) mmi_chset_utf8_to_ucs2_string(
                    (kal_uint8*) hintData[0],
                    MMI_BT_SCR_BD_NAME_LEN,
                    (kal_uint8*) g_mmi_bt_scr_cntx.authorize_name_p);
    }
    else
    {
        ucs2_str_len =
            (U8) mmi_chset_utf8_to_ucs2_string(
                    (kal_uint8*) hintData[0],
                    utf8_char_cnt,
                    (kal_uint8*) g_mmi_bt_scr_cntx.authorize_name_p);
    }

	/* allow (MMI_BT_BD_NAME_LEN/3) chinese characters or (MMI_BT_BD_NAME_LEN/3)*2 english characters  */
	/* so for UCS2 encoding, need MMI_BT_SCR_BD_NAME_LEN bytes */

	/* shall check if there is any two_byte character mixed in one_bye UCS2 string */
	/* if yes, then truncate the string to meet above rules((MMI_BT_BD_NAME_LEN/3) chinese characters or (MMI_BT_BD_NAME_LEN/3)*2 english characters)*/	
	if(mmi_bt_test_ucs2((U16*)hintData[0], (U16)(ucs2_str_len/ENCODING_LENGTH)) )
	{ 
		mmi_bt_truncate_ucs2_string((U16*)hintData[0], 
		    							(U16)(ucs2_str_len/ENCODING_LENGTH),
		    							(U16)((MMI_BT_BD_NAME_LEN-2)/3)
		    						   );		    
	}

    mmi_ucs2cpy((S8*) hintData[1], (const S8*)GetString(STR_BT_SWITCH_SPEECH_PATH));

    /* STR_BT_CM_SETPATH string */
    mmi_ucs2cpy((S8*) g_mmi_bt_scr_cntx.ui_buf, (const S8*)hintData[1]);
    /* " " string */
    if (hintData[0][0] != 0)
    {
        memset(ascii_buf, 0, 5);
        memset(usc2_buf, 0, 10);
        kal_sprintf((S8*) ascii_buf, " ");
        mmi_asc_to_ucs2((S8*) usc2_buf, (S8*) ascii_buf);
        mmi_ucs2cat((S8*) g_mmi_bt_scr_cntx.ui_buf, (const S8*)usc2_buf);
    }
    /* Device name */
    mmi_ucs2cat((S8*) g_mmi_bt_scr_cntx.ui_buf, (const S8*)hintData[0]);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

    ShowCategory165Screen(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (UI_string_type) g_mmi_bt_scr_cntx.ui_buf,
        (U16) IMG_GLOBAL_QUESTION,
        NULL);


    if (!mmi_is_redrawing_bk_screens())
    { 
	    /* play a warning tone */
	    playRequestedTone(WARNING_TONE);
	}

    SetLeftSoftkeyFunction(mmi_bt_connect_authorised, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_bt_connect_inauthorised, KEY_EVENT_UP);
    SetDelScrnIDCallbackHandler(SCR_BT_CONNECT_AUTHORIZE, (HistoryDelCBPtr) mmi_bt_connect_authorise_scr_del_callback);

    SetKeyHandler(NULL, KEY_END, KEY_EVENT_UP);
    SetKeyHandler(mmi_bt_connect_authorise_end_key, KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_exit_connect_authorise
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_exit_connect_authorise(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bt_clear_endkey_hdlr();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_connect_authorise_scr_del_callback
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_bt_connect_authorise_scr_del_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetDelScrnIDCallbackHandler(SCR_BT_CONNECT_AUTHORIZE, (HistoryDelCBPtr) NULL);

    mmi_bt_clear_endkey_hdlr();

    if (mmi_bt_is_hs_connected())
    {
        /* for BT profile */
    #if defined(__MMI_BT_PROFILE__)
        mmi_profiles_bt_connect_callback(MMI_PROFILES_BT_HFP_ACL, MMI_PROFILES_BT_IND, MMI_PROFILES_BT_OK);
    #endif 
    }
    mmi_bt_update_status_icon();
    /* reset MMI_BT_CONFIRM_SPEECH_SWITCH screen flag */
    g_mmi_bt_scr_cntx.flag &= ~MMI_BT_CONFIRM_SPEECH_SWITCH;

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_connect_authorised
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_connect_authorised(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetDelScrnIDCallbackHandler(SCR_BT_CONNECT_AUTHORIZE, (HistoryDelCBPtr) NULL);

    mmi_bt_clear_endkey_hdlr();

    GoBackHistory();
    if (mmi_bt_is_hs_connected())
    {
        /* for BT profile */
        #if defined(__MMI_BT_PROFILE__)
        mmi_profiles_bt_connect_callback(MMI_PROFILES_BT_HFP_ACL, MMI_PROFILES_BT_IND, MMI_PROFILES_BT_OK);
        #endif 
    }
    mmi_bt_update_status_icon();
    /* reset MMI_BT_CONFIRM_SPEECH_SWITCH screen flag */
    g_mmi_bt_scr_cntx.flag &= ~MMI_BT_CONFIRM_SPEECH_SWITCH;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_connect_inauthorised
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_connect_inauthorised(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetDelScrnIDCallbackHandler(SCR_BT_CONNECT_AUTHORIZE, (HistoryDelCBPtr) NULL);

    mmi_bt_clear_endkey_hdlr();

    GoBackHistory();
    if (g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_disconnect_req)
    {
        (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_disconnect_req) (g_mmi_bt_scr_cntx.authorize_conn_id,
                                                                 g_mmi_bt_scr_cntx.authorize_conn_type);
    }
    /* reset MMI_BT_CONFIRM_SPEECH_SWITCH screen flag */
    g_mmi_bt_scr_cntx.flag &= ~MMI_BT_CONFIRM_SPEECH_SWITCH;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_connect_authorise_end_key
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_connect_authorise_end_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetDelScrnIDCallbackHandler(SCR_BT_CONNECT_AUTHORIZE, (HistoryDelCBPtr) NULL);

    /* execute endkey handler */
    mmi_bt_exe_endkey_hdlr();
    mmi_bt_clear_endkey_hdlr();

    if (mmi_bt_is_hs_connected())
    {
        #if defined(__MMI_BT_PROFILE__)
        mmi_profiles_bt_connect_callback(MMI_PROFILES_BT_HFP_ACL, MMI_PROFILES_BT_IND, MMI_PROFILES_BT_OK);
        #endif 
    }

    mmi_bt_update_status_icon();

    /* reset MMI_BT_CONFIRM_SPEECH_SWITCH screen flag */
    g_mmi_bt_scr_cntx.flag &= ~MMI_BT_CONFIRM_SPEECH_SWITCH;

    DeleteScreenIfPresent(SCR_BT_CONNECT_AUTHORIZE);
}

/* Put Inquiry NEW Device at the first item of Mydev menu */
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_mydev_menu
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_mydev_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemIcons[MAX_SUB_MENUS];
    U16 nItems, paired_dev_num;
    U8 *guiBuffer;
    U8 i;
    mmi_bt_dev_struct *dev_struct_p;
    U8 utf8_char_cnt = 0;
    U8 ucs2_str_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((mmi_bt_is_hw_ready) (MMI_TRUE) == MMI_FALSE)
    {
        return;
    }

    EntryNewScreen(SCR_BT_MYDEV, NULL, mmi_bt_entry_mydev_menu, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_BT_MYDEV);

    /* Get trust device info */
    paired_dev_num = (U8) g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_num();

    /* Clear UI buffer */
    memset(ItemIcons, 0, sizeof(U16) * MAX_SUB_MENUS);

    /* fill "Inquiry New Device menuitem" */
    nItems = 0;
    subMenuDataPtrs[nItems] =(U8*) GetString(STR_BT_SCH_ALL_DEV);
    hintDataPtrs[nItems] = NULL;
    ItemIcons[nItems] = IMG_BT_MENU_TITLE;
    
    nItems ++;


    for (i = 0; i < paired_dev_num; nItems ++, i++)
    {
        dev_struct_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_info) (i);

        /* Fill device name list */
        /* get byte count for convert utf8 string to UCS2 string */
        /* get character count of utf8 string */
        /* +1 is for UCS2 NULL terminate */
        /* *ENCODING_LENGTH is for byte count of one UCS2 character */
        utf8_char_cnt = (U8) ((mmi_chset_utf8_strlen((kal_uint8*) dev_struct_p->name) + 1) * ENCODING_LENGTH);
        MMI_BT_ASSERT(MAX_SUB_MENU_SIZE >= MMI_BT_SCR_BD_NAME_LEN);
        if (utf8_char_cnt > MMI_BT_SCR_BD_NAME_LEN)
        {
            ucs2_str_len =
                (U8) mmi_chset_utf8_to_ucs2_string(
                        (kal_uint8*) subMenuData[nItems],
                        MMI_BT_SCR_BD_NAME_LEN,
                        (kal_uint8*) dev_struct_p->name);
        }
        else
        {
            ucs2_str_len =
                (U8) mmi_chset_utf8_to_ucs2_string(
                        (kal_uint8*) subMenuData[nItems],
                        utf8_char_cnt,
                        (kal_uint8*) dev_struct_p->name);
        }

		/* allow (MMI_BT_BD_NAME_LEN/3) chinese characters or (MMI_BT_BD_NAME_LEN/3)*2 english characters  */
		/* so for UCS2 encoding, need MMI_BT_SCR_BD_NAME_LEN bytes */

		/* shall check if there is any two_byte character mixed in one_bye UCS2 string */
		/* if yes, then truncate the string to meet above rules((MMI_BT_BD_NAME_LEN/3) chinese characters or (MMI_BT_BD_NAME_LEN/3)*2 english characters)*/	
		if(mmi_bt_test_ucs2((U16*)subMenuData[nItems], (U16)(ucs2_str_len/ENCODING_LENGTH)) )
		{ 
			mmi_bt_truncate_ucs2_string((U16*)subMenuData[nItems], 
			    							(U16)(ucs2_str_len/ENCODING_LENGTH),
			    							(U16)((MMI_BT_BD_NAME_LEN-2)/3)
			    						   );		    
		}
        
        subMenuDataPtrs[nItems] = subMenuData[nItems];

        /* BT address: NAP, UAP, LAP */
        kal_wsprintf(
            (U16*) hintData[nItems],
            "BD_ADDR: %02x:%02x:%02x:%02x:%02x:%02x",
            ((dev_struct_p->bd_addr.nap & 0xff00) >> 8),
            (dev_struct_p->bd_addr.nap & 0x00ff),
            (dev_struct_p->bd_addr.uap),
            ((dev_struct_p->bd_addr.lap & 0xff0000) >> 16),
            ((dev_struct_p->bd_addr.lap & 0x00ff00) >> 8),
            (dev_struct_p->bd_addr.lap & 0x0000ff));
        hintDataPtrs[nItems] = hintData[nItems];

        /* Fill device icon list */
        if (dev_struct_p->cod & MMI_BT_COMPUTER_MAJOR_DEVICE_MASK)
        {
            ItemIcons[nItems] = IMG_BT_DEV_LAP;
        }
        else if (dev_struct_p->cod & MMI_BT_PRINTER_IMAGING_MINOR_DEVICE_CLASS)
        {
            ItemIcons[nItems] = IMG_BT_DEV_PRT;
        }
        else if (dev_struct_p->cod & MMI_BT_PHONE_MAJOR_DEVICE_MASK)
        {
            ItemIcons[nItems] = IMG_BT_DEV_MOB;
        }
        else if (dev_struct_p->cod & MMI_BT_AV_MAJOR_DEVICE_MASK)
        {
            ItemIcons[nItems] = IMG_BT_DEV_EAR;
        }
        else
        {
            ItemIcons[nItems] = IMG_BT_DEV_OTHER;
        }

    }

    SetParentHandler(MENU_CONN_BT_MAIN);

    RegisterHighlightHandler(mmi_bt_mydev_hilite_hdlr);

    if (nItems == 1)
    {

	    ShowCategory53Screen(
	        STR_BT_MYDEVICE,
	        GetRootTitleIcon(MENU_CONN_BT_MAIN),
	        STR_GLOBAL_OK,
	        IMG_GLOBAL_OK,
	        STR_GLOBAL_BACK,
	        IMG_GLOBAL_BACK,
	        nItems,
	        (U8 **) subMenuDataPtrs,
	        (U16*) ItemIcons,
	        hintDataPtrs,
	        0,
	        0,
	        guiBuffer);
        
    }
    else
    {
	    ShowCategory53Screen(
	        STR_BT_MYDEVICE,
	        GetRootTitleIcon(MENU_CONN_BT_MAIN),
	        STR_GLOBAL_OPTIONS,
	        IMG_GLOBAL_OPTIONS,
	        STR_GLOBAL_BACK,
	        IMG_GLOBAL_BACK,
	        nItems,
	        (U8 **) subMenuDataPtrs,
	        (U16*) ItemIcons,
	        hintDataPtrs,
	        0,
	        0,
	        guiBuffer);
    }


    /* Put Inquiry NEW Device at the first item of Mydev menu */
	#if 0
/* under construction !*/
/* under construction !*/
    #endif

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}

/*****************************************************************************
* FUNCTION
*  mmi_bt_exit_mydev_menu
* DESCRIPTION
*   This function is bluetooth highlight handler.
*
* PARAMETERS
*  a  IN/OUT      first variable, used as returns
*  b  IN       second variable
* RETURNS
*  NONE.
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/
void mmi_bt_exit_mydev_menu(void);

/* Put Inquiry NEW Device at the first item of Mydev menu */
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_update_mydev_menu
 * DESCRIPTION
 *  This function is to update mydev menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_update_mydev_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemIcons[MAX_SUB_MENUS];
    U16 nItems, paired_dev_num;
    U8 i;
    mmi_bt_dev_struct *dev_struct_p;
    U8 utf8_char_cnt = 0;
    U8 ucs2_str_len = 0;
    /* Put Inquiry NEW Device at the first item of Mydev menu */
    U32 hilight_item = g_mmi_bt_scr_cntx.hilight_item;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetActiveScreenId() != SCR_BT_MYDEV)
    {
        return;
    }

    if (ExitCategoryFunction)
    {
        ExitCategoryFunction();
    }

    UI_common_screen_exit();

    /* Get trust device info */
    paired_dev_num = (U8) g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_num();

    /* Clear UI buffer */
    memset(ItemIcons, 0, sizeof(U16) * MAX_SUB_MENUS);

    /* fill "Inquiry New Device menuitem" */
    nItems = 0;
    subMenuDataPtrs[nItems] =(U8*) GetString(STR_BT_SCH_ALL_DEV);
    hintDataPtrs[nItems] = NULL;
    ItemIcons[nItems] = IMG_BT_MENU_TITLE;
    
    nItems ++;


    for (i = 0; i < paired_dev_num; nItems++, i++)
    {
        dev_struct_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_info) (i);

        /* Fill device name list */
        /* get byte count for convert utf8 string to UCS2 string */
        /* get character count of utf8 string */
        /* +1 is for UCS2 NULL terminate */
        /* *ENCODING_LENGTH is for byte count of one UCS2 character */
        utf8_char_cnt = (U8) ((mmi_chset_utf8_strlen((kal_uint8*) dev_struct_p->name) + 1) * ENCODING_LENGTH);
        MMI_BT_ASSERT(MAX_SUB_MENU_SIZE >= MMI_BT_SCR_BD_NAME_LEN);
        if (utf8_char_cnt > MMI_BT_SCR_BD_NAME_LEN)
        {
            ucs2_str_len =
                (U8) mmi_chset_utf8_to_ucs2_string(
                        (kal_uint8*) subMenuData[nItems],
                        MMI_BT_SCR_BD_NAME_LEN,
                        (kal_uint8*) dev_struct_p->name);
        }
        else
        {
            ucs2_str_len =
                (U8) mmi_chset_utf8_to_ucs2_string(
                        (kal_uint8*) subMenuData[nItems],
                        utf8_char_cnt,
                        (kal_uint8*) dev_struct_p->name);
        }

		/* allow (MMI_BT_BD_NAME_LEN/3) chinese characters or (MMI_BT_BD_NAME_LEN/3)*2 english characters  */
		/* so for UCS2 encoding, need MMI_BT_SCR_BD_NAME_LEN bytes */

		/* shall check if there is any two_byte character mixed in one_bye UCS2 string */
		/* if yes, then truncate the string to meet above rules((MMI_BT_BD_NAME_LEN/3) chinese characters or (MMI_BT_BD_NAME_LEN/3)*2 english characters)*/	
		if(mmi_bt_test_ucs2((U16*)subMenuData[nItems], (U16)(ucs2_str_len/ENCODING_LENGTH)) )
		{ 
			mmi_bt_truncate_ucs2_string((U16*)subMenuData[nItems], 
			    							(U16)(ucs2_str_len/ENCODING_LENGTH),
			    							(U16)((MMI_BT_BD_NAME_LEN-2)/3)
			    						   );		    
		}
        
        subMenuDataPtrs[nItems] = subMenuData[nItems];

        /* BT address: NAP, UAP, LAP */
        kal_wsprintf(
            (U16*) hintData[nItems],
            "BD_ADDR: %02x:%02x:%02x:%02x:%02x:%02x",
            ((dev_struct_p->bd_addr.nap & 0xff00) >> 8),
            (dev_struct_p->bd_addr.nap & 0x00ff),
            (dev_struct_p->bd_addr.uap),
            ((dev_struct_p->bd_addr.lap & 0xff0000) >> 16),
            ((dev_struct_p->bd_addr.lap & 0x00ff00) >> 8),
            (dev_struct_p->bd_addr.lap & 0x0000ff));
        hintDataPtrs[nItems] = hintData[nItems];

        /* Fill device icon list */
        if (dev_struct_p->cod & MMI_BT_COMPUTER_MAJOR_DEVICE_MASK)
        {
            ItemIcons[nItems] = IMG_BT_DEV_LAP;
        }
        else if (dev_struct_p->cod & MMI_BT_PRINTER_IMAGING_MINOR_DEVICE_CLASS)
        {
            ItemIcons[nItems] = IMG_BT_DEV_PRT;
        }
        else if (dev_struct_p->cod & MMI_BT_PHONE_MAJOR_DEVICE_MASK)
        {
            ItemIcons[nItems] = IMG_BT_DEV_MOB;
        }
        else if (dev_struct_p->cod & MMI_BT_AV_MAJOR_DEVICE_MASK)
        {
            ItemIcons[nItems] = IMG_BT_DEV_EAR;
        }
        else
        {
            ItemIcons[nItems] = IMG_BT_DEV_OTHER;
        }

    }



    
    RegisterHighlightHandler(mmi_bt_mydev_hilite_hdlr);

    if (nItems == 1)
    {

	    ShowCategory53Screen(
	        STR_BT_MYDEVICE,
	        GetRootTitleIcon(MENU_CONN_BT_MAIN),
	        STR_GLOBAL_OK,
	        IMG_GLOBAL_OK,
	        STR_GLOBAL_BACK,
	        IMG_GLOBAL_BACK,
	        nItems,
	        (U8 **) subMenuDataPtrs,
	        (U16*) ItemIcons,
	        hintDataPtrs,
	        0,
	        0,
	        NULL);
        
    }
    else
    {
        /* Put Inquiry NEW Device at the first item of Mydev menu */
	    ShowCategory53Screen(
	        STR_BT_MYDEVICE,
	        GetRootTitleIcon(MENU_CONN_BT_MAIN),
	        STR_GLOBAL_OPTIONS,
	        IMG_GLOBAL_OPTIONS,
	        STR_GLOBAL_BACK,
	        IMG_GLOBAL_BACK,
	        nItems,
	        (U8 **) subMenuDataPtrs,
	        (U16*) ItemIcons,
	        hintDataPtrs,
	        0,
	        (S32) hilight_item,
	        NULL);
   }

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}

/* Put Inquiry NEW Device at the first item of Mydev menu */
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_mydev_hilite_hdlr
 * DESCRIPTION
 *  This function is bluetooth highlight handler.
 * PARAMETERS
 *  idx         [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_mydev_hilite_hdlr(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bt_dev_struct *dev_p;
	U32 action_item;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_SCR_HIGHLIGHT_ITEM, idx);

	if(idx == 0)
    {
        SetLeftSoftkeyFunction(mmi_bt_entry_mydev_sch, KEY_EVENT_UP);
        SetKeyHandler(mmi_bt_entry_mydev_sch, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    }
	else
	{
	    /* store the idx for device connecting and profile choosing index in paired list */
        /* Put Inquiry NEW Device at the first item of Mydev menu */
	    g_mmi_bt_scr_cntx.hilight_item = (U32)idx;
        MMI_BT_ASSERT(g_mmi_bt_scr_cntx.hilight_item !=0);        
		action_item = g_mmi_bt_scr_cntx.hilight_item - 1;

	    /* store connecting device address */

	    /* 1. idx=0 and paired_dev_num=0, then skip this */
	    /* 2. idx must be smaller than paired_dev_num */
	    if (action_item < (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_num) ())
	    {
	        dev_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_info) ((U16) action_item);
	        memcpy(&(g_mmi_bt_scr_cntx.conn_dev_add), &(dev_p->bd_addr), sizeof(mmi_bt_dev_addr));
	    }
	    else
	    {
	        /* do nothing */
	    }

	    SetLeftSoftkeyFunction(mmi_bt_entry_mydev_opt, KEY_EVENT_UP);
	    SetKeyHandler(mmi_bt_entry_mydev_opt, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);


	}
	

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

/* Configure Default Headset */
/* Put Inquiry NEW Device at the first item of Mydev menu */
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_mydev_opt
 * DESCRIPTION
 *  This function is to Entry function for Extra->Bluetooth->My Dev->Option
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_mydev_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *ItemList[MAX_SUB_MENUS];
    U16 nItems;
    U8 *guiBuffer;
    mmi_bt_dev_struct *dev_p;
    U32 action_item;
	U32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_is_redrawing_bk_screens())
    {

	    /* to avoid the twice operation while bt is just on and wanna enter mydev option menu */
	    if (g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_PAIRED_DEV_OPT)
	    {
	        g_mmi_bt_scr_cntx.flag &= ~MMI_BT_CONFIRM_PAIRED_DEV_OPT;    
	        StopTimer(BT_POPUP_TIMER);
	    }
	    
	    if ((*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_pwron) () == MMI_FALSE)
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
	        #endif 
	        mmi_bt_display_power_on_confirm(MMI_BT_CONFIRM_PAIRED_DEV_OPT);
	        return;
	    }

	    /* to avoid the error operation while bt module is busy */
	    if ((mmi_bt_is_permission) (MMI_TRUE) == MMI_FALSE)
	    {
	        return;
	    }
    }

    EntryNewScreen(SCR_BT_MYDEV_OPT, NULL, mmi_bt_entry_mydev_opt, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_BT_MYDEV_OPT);

    memset(&nItems, 0, MAX_SUB_MENUS);
    if ((*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_num) () > 0)
    {
		/* Configure Default Headset */
        /* Put Inquiry NEW Device at the first item of Mydev menu */ 
        MMI_BT_ASSERT(g_mmi_bt_scr_cntx.hilight_item !=0);
        action_item = g_mmi_bt_scr_cntx.hilight_item - 1;
        dev_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_info) ((U16) action_item);

        ItemList[MMI_BT_MYDEV_OPT_CONN] = (U8*) GetString((U16) STR_BT_MYDEV_OPT_CONN);
        /* Configure Default Headset */

		/* init hintDataPtrs */
		for (i=0; i<MMI_BT_MYDEV_OPT_LAST; i++)
		{
        	hintDataPtrs[i] = NULL;
        }

        /* connect */
        /* disconnect */
        /* set default hs */
        /* rename */        
        if ( (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_connection_active) (&(dev_p->bd_addr)) &&
             ( dev_p->cod & MMI_BT_AUDIO_MAJOR_SERVICE_MASK || 
                mmi_bt_is_service_support(dev_p, MMI_BT_HS_PROFILE_UUID) || 
                mmi_bt_is_service_support(dev_p, MMI_BT_HF_PROFILE_UUID) 
              ) 
           )
        {
            nItems = (U16) MMI_BT_MYDEV_OPT_LAST;
            ItemList[MMI_BT_MYDEV_OPT_DISCONN] = (U8*) GetString((U16) STR_BT_MYDEV_OPT_DISCONN);
            ItemList[MMI_BT_MYDEV_OPT_SET_DEFAULT_HS] = (U8*) GetString((U16) STR_BT_MYDEV_OPT_SET_DEFAULT_HS);
            ItemList[MMI_BT_MYDEV_OPT_REN] = (U8*) GetString((U16) STR_BT_MYDEV_OPT_REN);
            ItemList[MMI_BT_MYDEV_OPT_DEL] = (U8*) GetString((U16) STR_BT_MYDEV_OPT_DEL);
            ItemList[MMI_BT_MYDEV_OPT_DEL_ALL] = (U8*) GetString((U16) STR_BT_MYDEV_OPT_DEL_ALL);
            ItemList[MMI_BT_MYDEV_OPT_SUP_SERV] = (U8*) GetString((U16) STR_BT_MYDEV_OPT_SUP_SER);
            //ItemList[MMI_BT_MYDEV_OPT_SCH] = (U8*) GetString((U16) STR_BT_MYDEV_OPT_SCH);
	        hintDataPtrs[MMI_BT_MYDEV_OPT_SET_DEFAULT_HS] = mmi_bt_get_default_headset_device_name();
            
        }
        /* connect */
        /* disconnect */
        /* rename */        
	    else if ( (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_connection_active) (&(dev_p->bd_addr)) &&
	              !( dev_p->cod & MMI_BT_AUDIO_MAJOR_SERVICE_MASK || 
	                 mmi_bt_is_service_support(dev_p, MMI_BT_HS_PROFILE_UUID) || 
	                 mmi_bt_is_service_support(dev_p, MMI_BT_HF_PROFILE_UUID) 
	               ) 
	            )
        {
            nItems = (U16) MMI_BT_MYDEV_OPT_LAST - 1;
            ItemList[MMI_BT_MYDEV_OPT_DISCONN] = (U8*) GetString((U16) STR_BT_MYDEV_OPT_DISCONN);
            ItemList[MMI_BT_MYDEV_OPT_REN - 1] = (U8*) GetString((U16) STR_BT_MYDEV_OPT_REN);
            ItemList[MMI_BT_MYDEV_OPT_DEL - 1] = (U8*) GetString((U16) STR_BT_MYDEV_OPT_DEL);
            ItemList[MMI_BT_MYDEV_OPT_DEL_ALL - 1] = (U8*) GetString((U16) STR_BT_MYDEV_OPT_DEL_ALL);
            ItemList[MMI_BT_MYDEV_OPT_SUP_SERV - 1] = (U8*) GetString((U16) STR_BT_MYDEV_OPT_SUP_SER);
            //ItemList[MMI_BT_MYDEV_OPT_SCH - 1] = (U8*) GetString((U16) STR_BT_MYDEV_OPT_SCH);
        }
        /* connect */
        /* set default hs */
        /* rename */        
	    else if ( !(*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_connection_active) (&(dev_p->bd_addr)) &&
	              ( dev_p->cod & MMI_BT_AUDIO_MAJOR_SERVICE_MASK || 
	                 mmi_bt_is_service_support(dev_p, MMI_BT_HS_PROFILE_UUID) || 
	                 mmi_bt_is_service_support(dev_p, MMI_BT_HF_PROFILE_UUID) 
	               ) 
	            )
        {
            nItems = (U16) MMI_BT_MYDEV_OPT_LAST - 1;
            ItemList[MMI_BT_MYDEV_OPT_SET_DEFAULT_HS-1] = (U8*) GetString((U16) STR_BT_MYDEV_OPT_SET_DEFAULT_HS);
            ItemList[MMI_BT_MYDEV_OPT_REN - 1] = (U8*) GetString((U16) STR_BT_MYDEV_OPT_REN);
            ItemList[MMI_BT_MYDEV_OPT_DEL - 1] = (U8*) GetString((U16) STR_BT_MYDEV_OPT_DEL);
            ItemList[MMI_BT_MYDEV_OPT_DEL_ALL - 1] = (U8*) GetString((U16) STR_BT_MYDEV_OPT_DEL_ALL);
            ItemList[MMI_BT_MYDEV_OPT_SUP_SERV - 1] = (U8*) GetString((U16) STR_BT_MYDEV_OPT_SUP_SER);
            //ItemList[MMI_BT_MYDEV_OPT_SCH - 1] = (U8*) GetString((U16) STR_BT_MYDEV_OPT_SCH);
	        hintDataPtrs[MMI_BT_MYDEV_OPT_SET_DEFAULT_HS-1] = mmi_bt_get_default_headset_device_name();

        }
        /* connect */
        /* rename */        
        else
        {
            nItems = (U16) MMI_BT_MYDEV_OPT_LAST - 2;
            ItemList[MMI_BT_MYDEV_OPT_REN - 2] = (U8*) GetString((U16) STR_BT_MYDEV_OPT_REN);
            ItemList[MMI_BT_MYDEV_OPT_DEL - 2] = (U8*) GetString((U16) STR_BT_MYDEV_OPT_DEL);
            ItemList[MMI_BT_MYDEV_OPT_DEL_ALL - 2] = (U8*) GetString((U16) STR_BT_MYDEV_OPT_DEL_ALL);
            ItemList[MMI_BT_MYDEV_OPT_SUP_SERV - 2] = (U8*) GetString((U16) STR_BT_MYDEV_OPT_SUP_SER);
            //ItemList[MMI_BT_MYDEV_OPT_SCH - 2] = (U8*) GetString((U16) STR_BT_MYDEV_OPT_SCH);
        }

    }
    else
    {
        nItems = 1;
        ItemList[0] = (U8*) GetString((U16) STR_BT_MYDEV_OPT_SCH);
        hintDataPtrs[0] = NULL;

    }
    SetParentHandler(MENU_CONN_BT_MYDEV);

    RegisterHighlightHandler(mmi_bt_mydev_opt_hilite_hdlr);

    if (g_mmi_bt_scr_cntx.reset_gui_buffer_flag)
    {
        ShowCategory53Screen(
            STR_GLOBAL_OPTIONS,
            GetRootTitleIcon(MENU_CONN_BT_MAIN),
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            nItems,
            (U8 **) ItemList,
            (PU16) gIndexIconsImageList,
	        hintDataPtrs,
            0,
            0,
            NULL);
    }
    else
    {
        ShowCategory53Screen(
            STR_GLOBAL_OPTIONS,
            GetRootTitleIcon(MENU_CONN_BT_MAIN),
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            nItems,
            (U8 **) ItemList,
            (PU16) gIndexIconsImageList,
            hintDataPtrs,
            0,
            0,
            guiBuffer);
     }

    g_mmi_bt_scr_cntx.reset_gui_buffer_flag = MMI_FALSE;

}

/*****************************************************************************
* FUNCTION
*  mmi_bt_exit_mydev_opt
* DESCRIPTION
*   This function is 
*
* PARAMETERS
*  a  IN/OUT      first variable, used as returns
*  b  IN       second variable
* RETURNS
*  NONE.
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/
void mmi_bt_exit_mydev_opt(void);

/* Configure Default Headset */
/* Put Inquiry NEW Device at the first item of Mydev menu */
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_update_mydev_opt
 * DESCRIPTION
 *  This function is to update Extra->Bluetooth->My Dev->Option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_update_mydev_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *ItemList[MAX_SUB_MENUS];
    U16 nItems;
    mmi_bt_dev_struct *dev_p;
    U32 action_item;
    U32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetActiveScreenId() != SCR_BT_MYDEV_OPT)
    {
        return;
    }

    if (ExitCategoryFunction)
    {
        ExitCategoryFunction();
    }

    UI_common_screen_exit();

    memset(&nItems, 0, MAX_SUB_MENUS);
    if ((*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_num) () > 0)
    {
		/* Configure Default Headset */
        /* Put Inquiry NEW Device at the first item of Mydev menu */   
        MMI_BT_ASSERT(g_mmi_bt_scr_cntx.hilight_item !=0);
        action_item = g_mmi_bt_scr_cntx.hilight_item - 1;
        dev_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_info) ((U16) action_item);

        ItemList[MMI_BT_MYDEV_OPT_CONN] = (U8*) GetString((U16) STR_BT_MYDEV_OPT_CONN);
        /* Configure Default Headset */

		/* init hintDataPtrs */
		for (i=0; i<MMI_BT_MYDEV_OPT_LAST; i++)
		{
        	hintDataPtrs[i] = NULL;
        }

        /* connect */
        /* disconnect */
        /* set default hs */
        /* rename */        
        if ( (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_connection_active) (&(dev_p->bd_addr)) &&
             ( dev_p->cod & MMI_BT_AUDIO_MAJOR_SERVICE_MASK || 
                mmi_bt_is_service_support(dev_p, MMI_BT_HS_PROFILE_UUID) || 
                mmi_bt_is_service_support(dev_p, MMI_BT_HF_PROFILE_UUID) 
              ) 
           )
        {
            nItems = (U16) MMI_BT_MYDEV_OPT_LAST;
            ItemList[MMI_BT_MYDEV_OPT_DISCONN] = (U8*) GetString((U16) STR_BT_MYDEV_OPT_DISCONN);
            ItemList[MMI_BT_MYDEV_OPT_SET_DEFAULT_HS] = (U8*) GetString((U16) STR_BT_MYDEV_OPT_SET_DEFAULT_HS);/* show set default headset */
            ItemList[MMI_BT_MYDEV_OPT_REN] = (U8*) GetString((U16) STR_BT_MYDEV_OPT_REN);
            ItemList[MMI_BT_MYDEV_OPT_DEL] = (U8*) GetString((U16) STR_BT_MYDEV_OPT_DEL);
            ItemList[MMI_BT_MYDEV_OPT_DEL_ALL] = (U8*) GetString((U16) STR_BT_MYDEV_OPT_DEL_ALL);
            ItemList[MMI_BT_MYDEV_OPT_SUP_SERV] = (U8*) GetString((U16) STR_BT_MYDEV_OPT_SUP_SER);
            //ItemList[MMI_BT_MYDEV_OPT_SCH] = (U8*) GetString((U16) STR_BT_MYDEV_OPT_SCH);
	        hintDataPtrs[MMI_BT_MYDEV_OPT_SET_DEFAULT_HS] = mmi_bt_get_default_headset_device_name();

        }
        /* connect */
        /* disconnect */
        /* rename */        
	    else if ( (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_connection_active) (&(dev_p->bd_addr)) &&
	              !( dev_p->cod & MMI_BT_AUDIO_MAJOR_SERVICE_MASK || 
	                 mmi_bt_is_service_support(dev_p, MMI_BT_HS_PROFILE_UUID) || 
	                 mmi_bt_is_service_support(dev_p, MMI_BT_HF_PROFILE_UUID) 
	               ) 
	            )
        {
            nItems = (U16) MMI_BT_MYDEV_OPT_LAST - 1;
            ItemList[MMI_BT_MYDEV_OPT_DISCONN] = (U8*) GetString((U16) STR_BT_MYDEV_OPT_DISCONN);
            ItemList[MMI_BT_MYDEV_OPT_REN - 1] = (U8*) GetString((U16) STR_BT_MYDEV_OPT_REN);
            ItemList[MMI_BT_MYDEV_OPT_DEL - 1] = (U8*) GetString((U16) STR_BT_MYDEV_OPT_DEL);
            ItemList[MMI_BT_MYDEV_OPT_DEL_ALL - 1] = (U8*) GetString((U16) STR_BT_MYDEV_OPT_DEL_ALL);
            ItemList[MMI_BT_MYDEV_OPT_SUP_SERV - 1] = (U8*) GetString((U16) STR_BT_MYDEV_OPT_SUP_SER);
            //ItemList[MMI_BT_MYDEV_OPT_SCH - 1] = (U8*) GetString((U16) STR_BT_MYDEV_OPT_SCH);
        }
        /* connect */
        /* set default hs */
        /* rename */        
	    else if ( !(*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_connection_active) (&(dev_p->bd_addr)) &&
	              ( dev_p->cod & MMI_BT_AUDIO_MAJOR_SERVICE_MASK || 
	                 mmi_bt_is_service_support(dev_p, MMI_BT_HS_PROFILE_UUID) || 
	                 mmi_bt_is_service_support(dev_p, MMI_BT_HF_PROFILE_UUID) 
	               ) 
	            )
        {
            nItems = (U16) MMI_BT_MYDEV_OPT_LAST - 1;
            ItemList[MMI_BT_MYDEV_OPT_SET_DEFAULT_HS-1] = (U8*) GetString((U16) STR_BT_MYDEV_OPT_SET_DEFAULT_HS);
            ItemList[MMI_BT_MYDEV_OPT_REN - 1] = (U8*) GetString((U16) STR_BT_MYDEV_OPT_REN);
            ItemList[MMI_BT_MYDEV_OPT_DEL - 1] = (U8*) GetString((U16) STR_BT_MYDEV_OPT_DEL);
            ItemList[MMI_BT_MYDEV_OPT_DEL_ALL - 1] = (U8*) GetString((U16) STR_BT_MYDEV_OPT_DEL_ALL);
            ItemList[MMI_BT_MYDEV_OPT_SUP_SERV - 1] = (U8*) GetString((U16) STR_BT_MYDEV_OPT_SUP_SER);
            //ItemList[MMI_BT_MYDEV_OPT_SCH - 1] = (U8*) GetString((U16) STR_BT_MYDEV_OPT_SCH);
	        hintDataPtrs[MMI_BT_MYDEV_OPT_SET_DEFAULT_HS-1] = mmi_bt_get_default_headset_device_name();

        }
        /* connect */
        /* rename */        
        else
        {
            nItems = (U16) MMI_BT_MYDEV_OPT_LAST - 2;
            ItemList[MMI_BT_MYDEV_OPT_REN - 2] = (U8*) GetString((U16) STR_BT_MYDEV_OPT_REN);
            ItemList[MMI_BT_MYDEV_OPT_DEL - 2] = (U8*) GetString((U16) STR_BT_MYDEV_OPT_DEL);
            ItemList[MMI_BT_MYDEV_OPT_DEL_ALL - 2] = (U8*) GetString((U16) STR_BT_MYDEV_OPT_DEL_ALL);
            ItemList[MMI_BT_MYDEV_OPT_SUP_SERV - 2] = (U8*) GetString((U16) STR_BT_MYDEV_OPT_SUP_SER);
            //ItemList[MMI_BT_MYDEV_OPT_SCH - 2] = (U8*) GetString((U16) STR_BT_MYDEV_OPT_SCH);
        }

    }
    else
    {
        nItems = 1;
        ItemList[0] = (U8*) GetString((U16) STR_BT_MYDEV_OPT_SCH);
        hintDataPtrs[0] = NULL;

    }

    RegisterHighlightHandler(mmi_bt_mydev_opt_hilite_hdlr);

    ShowCategory53Screen(
            STR_GLOBAL_OPTIONS,
            GetRootTitleIcon(MENU_CONN_BT_MAIN),
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            nItems,
            (U8 **) ItemList,
            (PU16) gIndexIconsImageList,
            hintDataPtrs,
            0,
            0,
            NULL);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_mydev_opt_hilite_hdlr
 * DESCRIPTION
 *  This function is bluetooth highlight handler.
 * PARAMETERS
 *  idx         [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_mydev_opt_hilite_hdlr(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bt_dev_struct *dev_p = NULL;
    U32 action_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Configure Default Headset */
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
	if (g_mmi_bt_scr_cntx.hilight_item >= 1)
    {
    	/* Configure Default Headset */
        /* Put Inquiry NEW Device at the first item of Mydev menu */   
        MMI_BT_ASSERT(g_mmi_bt_scr_cntx.hilight_item !=0);
        action_item = g_mmi_bt_scr_cntx.hilight_item - 1;
        dev_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_info) ((U16) action_item);
        MMI_ASSERT(dev_p != NULL);
        /* Configure Default Headset */
        /* connect */
        /* rename */        
        if ( !(*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_connection_active) (&(dev_p->bd_addr)) &&
             !( dev_p->cod & MMI_BT_AUDIO_MAJOR_SERVICE_MASK || 
                mmi_bt_is_service_support(dev_p, MMI_BT_HS_PROFILE_UUID) || 
                mmi_bt_is_service_support(dev_p, MMI_BT_HF_PROFILE_UUID) 
              ) 
           )
        {
            /*  plus two to skip disconn and set default hs menu */
            if (idx != MMI_BT_MYDEV_OPT_CONN)
            {
                idx = idx + 2;
            }
        }
        /* connect */
        /* set default hs */
        /* rename */        
        else if ( !(*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_connection_active) (&(dev_p->bd_addr)) &&
                  ( dev_p->cod & MMI_BT_AUDIO_MAJOR_SERVICE_MASK || 
                    mmi_bt_is_service_support(dev_p, MMI_BT_HS_PROFILE_UUID) || 
                    mmi_bt_is_service_support(dev_p, MMI_BT_HF_PROFILE_UUID) 
                
						)
					  )
        {
            /*  plus one to skip disconn menu */
            if (idx != MMI_BT_MYDEV_OPT_CONN)
            {
                idx++;
            }
        }
        /* connect */
        /* disconnect */
        /* rename */        
        else if ( (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_connection_active) (&(dev_p->bd_addr)) &&
            	  !( dev_p->cod & MMI_BT_AUDIO_MAJOR_SERVICE_MASK || 
                     mmi_bt_is_service_support(dev_p, MMI_BT_HS_PROFILE_UUID) || 
                     mmi_bt_is_service_support(dev_p, MMI_BT_HF_PROFILE_UUID) ) 
                )
        {
            /*  plus one to skip set default hs menu */
            if (idx != MMI_BT_MYDEV_OPT_CONN && idx != MMI_BT_MYDEV_OPT_DISCONN)
            {
                idx++;
            }
        }


    }

    switch (idx)
    {
        case MMI_BT_MYDEV_OPT_CONN:
            if (dev_p->service_list_num == 0)
            {
                SetLeftSoftkeyFunction(mmi_bt_prof_choose_refresh_prof_list, KEY_EVENT_UP);
            }
            else
            {
                SetLeftSoftkeyFunction(mmi_bt_entry_mydev_prof_choose, KEY_EVENT_UP);
            }
            break;
        case MMI_BT_MYDEV_OPT_DISCONN:
            SetLeftSoftkeyFunction(mmi_bt_entry_mydev_connected_prof, KEY_EVENT_UP);
            break;
		/* Configure Default Headset */
        case MMI_BT_MYDEV_OPT_SET_DEFAULT_HS:
            SetLeftSoftkeyFunction(mmi_bt_entry_mydev_set_default_hs, KEY_EVENT_UP);
            break;

        case MMI_BT_MYDEV_OPT_REN:
            SetLeftSoftkeyFunction(mmi_bt_entry_mydev_ren, KEY_EVENT_UP);
            break;

        case MMI_BT_MYDEV_OPT_DEL:
            SetLeftSoftkeyFunction(mmi_bt_entry_mydev_del, KEY_EVENT_UP);
            break;
        case MMI_BT_MYDEV_OPT_DEL_ALL:
            SetLeftSoftkeyFunction(mmi_bt_entry_mydev_del_all, KEY_EVENT_UP);
            break;
        case MMI_BT_MYDEV_OPT_SUP_SERV:
            if (dev_p->service_list_num == 0)
            {
                SetLeftSoftkeyFunction(mmi_bt_sup_ser_refresh_prof_list, KEY_EVENT_UP);
            }
            else
            {
                SetLeftSoftkeyFunction(mmi_bt_entry_mydev_sup_ser, KEY_EVENT_UP);
            }

            break;
        /* Put Inquiry NEW Device at the first item of Mydev menu */
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif    
        default:
            SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
            break;
    }

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_mydev_opt_confirm_rsk_hdler
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_mydev_opt_confirm_rsk_hdler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reset scr flag */
    //mmi_bt_reset_scr_flag();
    g_mmi_bt_scr_cntx.flag &= ~MMI_BT_CONFIRM_PAIRED_DEV_OPT;
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_mydev_prof_choose
 * DESCRIPTION
 *  This function is bluetooth highlight handler.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_mydev_prof_choose(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *ItemList[MAX_SUB_MENUS];
    U16 nItems;
    U8 *guiBuffer;
    mmi_bt_dev_struct *dev_p;
    U32 i;
    U8 action_item;
    U16 lsk_str, lsk_img, rsk_str, rsk_img;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reset profile refresh flag */
    g_mmi_bt_scr_cntx.flag &= ~MMI_BT_REFRESH_PROFILE_LIST_PROF_CHO;
    
    memset(&nItems, 0, MAX_SUB_MENUS);
    /* action_item = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_action_item_index)(); */
    /* hilight_item is the index of paired list */
    /* Put Inquiry NEW Device at the first item of Mydev menu */
    MMI_BT_ASSERT(g_mmi_bt_scr_cntx.hilight_item != 0);
    action_item = g_mmi_bt_scr_cntx.hilight_item - 1;
    dev_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_info) ((U16) action_item);

    EntryNewScreen(SCR_BT_MYDEV_PROF_CHO, mmi_bt_exit_mydev_prof_choose, mmi_bt_entry_mydev_prof_choose, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_BT_MYDEV_PROF_CHO);

    nItems = 0;
    for (i = 0; i < dev_p->service_list_num; i++)
    {
        if (dev_p->service_list[i] != MMI_BT_OBEX_OBJECT_PUSH_SERVICE_UUID &&
				dev_p->service_list[i]!= MMI_BT_SPP_PROFILE_UUID &&
				dev_p->service_list[i]!= MMI_BT_DUN_PROFILE_UUID &&
				#if defined(__MMI_BT_MTK_SUPPORT__)
				dev_p->service_list[i]!= MMI_BT_ADVANCED_AUDIO_PROFILE_UUID &&
				#endif
                dev_p->service_list[i]!= MMI_BT_FAX_PROFILE_UUID &&
				dev_p->service_list[i]!= MMI_BT_SIM_ACCESS_PROFILE_UUID &&
				dev_p->service_list[i]!= MMI_BT_HID_PROFILE_UUID &&
				dev_p->service_list[i]!= MMI_BT_OBEX_BPPS_PROFILE_UUID &&
				dev_p->service_list[i]!= MMI_BT_AV_REMOTE_CONTROL_UUID)
        {
            if (mmi_bt_get_profile_str_id((U16) dev_p->service_list[i], &(ItemList[nItems])) == MMI_FALSE)
            {
                /* NOT Considered Profile UUID */
                //MMI_BT_ASSERT(0);
                //nItems--;
            }
            nItems++;
        }

    }
    SetParentHandler(MENU_CONN_BT_MYDEV);

    if (dev_p->service_list_num == 0)
    {
        ItemList[0] = (U8*) GetString((U16) STR_BT_NO_SUPPORTED_PROFILE);
        nItems = 1;
        lsk_str = STR_BT_REFRESH;
        lsk_img = IMG_GLOBAL_OK;
        rsk_str = STR_GLOBAL_BACK;
        rsk_img = IMG_GLOBAL_OK;
    }
    else if (nItems == 0)
    {
        lsk_str = 0;
        lsk_img = 0;
        rsk_str = STR_GLOBAL_BACK;
        rsk_img = IMG_GLOBAL_OK;
    }
    else
    {
        lsk_str = STR_BT_LSK_CONN;
        lsk_img = IMG_GLOBAL_OK;
        rsk_str = STR_GLOBAL_BACK;
        rsk_img = IMG_GLOBAL_OK;
    }

    RegisterHighlightHandler(mmi_bt_mydev_prof_choose_hilite_hdlr);
    ShowCategory53Screen(
        STR_BT_MYDEV_OPT_SUP_SER,
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        lsk_str,
        lsk_img,
        rsk_str,
        rsk_img,
        nItems,
        (U8 **) ItemList,
        (PU16) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);

    if (nItems == 0)
    {
        SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
        ChangeLeftSoftkey(0, 0);
    }

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_exit_mydev_prof_choose
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_exit_mydev_prof_choose(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //memset(&(g_mmi_bt_scr_cntx.conn_dev_add),0, sizeof(mmi_bt_dev_addr));
    //memset(&(g_mmi_bt_scr_cntx.conn_profile_id),0, sizeof(U32));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_mydev_prof_choose_hilite_hdlr
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  idx         [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_mydev_prof_choose_hilite_hdlr(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bt_dev_struct *dev_p;
    U32 action_item, i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_SCR_HIGHLIGHT_ITEM, idx);

    if ( g_mmi_bt_scr_cntx.flag & MMI_BT_CONNECT_HFP_FIRST_NOTIFY)
    {
        return;
    }
 
    /* Put Inquiry NEW Device at the first item of Mydev menu */
    MMI_BT_ASSERT(g_mmi_bt_scr_cntx.hilight_item != 0);

    action_item = g_mmi_bt_scr_cntx.hilight_item - 1;
    dev_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_info) ((U16) action_item);

    if (dev_p->service_list_num == 0)
    {
        SetLeftSoftkeyFunction(mmi_bt_prof_choose_refresh_prof_list, KEY_EVENT_UP);
        //SetKeyHandler(mmi_bt_prof_choose_refresh_prof_list, KEY_RIGHT_ARROW,KEY_EVENT_DOWN);
        //SetLeftSoftkeyFunction(NULL,KEY_EVENT_UP);
    }
    else
    {
        /* the hilight index(idx) donot point to the profile which wanted to connect */
        /* the hilight index had skiped OPP/SPP/DUN profiles */
        /* to adjust the service list index(j) to correct index */
        j = idx;
        for (i = 0; i < dev_p->service_list_num; i++)
        {
            if ((i <= j) &&
                (dev_p->service_list[i] == MMI_BT_OBEX_OBJECT_PUSH_SERVICE_UUID ||
                 dev_p->service_list[i] == MMI_BT_SPP_PROFILE_UUID ||
                 dev_p->service_list[i] == MMI_BT_DUN_PROFILE_UUID ||
				 #if defined(__MMI_BT_MTK_SUPPORT__)
				 dev_p->service_list[i]== MMI_BT_ADVANCED_AUDIO_PROFILE_UUID ||
				 #endif
				 dev_p->service_list[i]== MMI_BT_SIM_ACCESS_PROFILE_UUID ||
                 dev_p->service_list[i]== MMI_BT_FAX_PROFILE_UUID ||
                 dev_p->service_list[i]== MMI_BT_HID_PROFILE_UUID ||
				 dev_p->service_list[i]== MMI_BT_OBEX_BPPS_PROFILE_UUID ||
				 dev_p->service_list[i]== MMI_BT_AV_REMOTE_CONTROL_UUID))
            {
                j++;
            }
        }

        /* store choosed profile to connect */
        g_mmi_bt_scr_cntx.conn_profile_id = dev_p->service_list[j];
        SetLeftSoftkeyFunction(mmi_bt_entry_mydev_conn, KEY_EVENT_UP);
        /* SetKeyHandler(mmi_bt_entry_mydev_conn, KEY_RIGHT_ARROW,KEY_EVENT_DOWN); */
    }

    /* SetRightSoftkeyFunction(mmi_bt_prof_choose_refresh_prof_list,KEY_EVENT_UP); */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_prof_choose_refresh_prof_list
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_prof_choose_refresh_prof_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_SCR_STATUS,
               g_mmi_bt_scr_cntx.state, g_mmi_bt_scr_cntx.flag, g_mmi_bt_scr_cntx.blinking_flag);
    
    /* to avoid the error operation while bt module is busy */
    if ((mmi_bt_is_permission) (MMI_TRUE) == MMI_FALSE)
    {
        return;
    }
    
    g_mmi_bt_scr_cntx.flag |= MMI_BT_REFRESH_PROFILE_LIST_PROF_CHO;
    (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_refresh_service_list_req) (&(g_mmi_bt_scr_cntx.conn_dev_add));
    mmi_bt_show_progress_scr(
        SCR_BT_REFREAH_PROFILE,
        STR_BT_REFRESH_SERVICE_LIST,
        STR_BT_REFRESHING,
        NULL,
        MMI_FALSE,
        NULL);
    DeleteScreenIfPresent(SCR_BT_MYDEV_PROF_CHO);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_refresh_prof_complete
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  result      [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_refresh_prof_complete(MMI_BOOL result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 currScreenId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* replace history */
    currScreenId = GetActiveScreenId();
    if (currScreenId != SCR_BT_REFREAH_PROFILE && IsScreenPresent(SCR_BT_REFREAH_PROFILE))
    {
        /* two cases that this entry fuction will be called */
        /* one is SCR_BT_REFREAH_PROFILE is in history */
        /* for above case, shall replace the history SCR_BT_REFREAH_PROFILE by SCR_BT_MYDEV_PROF_CHO or SCR_BT_MYDEV_SUP_PROFILE */
        if (g_mmi_bt_scr_cntx.flag & MMI_BT_REFRESH_PROFILE_LIST_PROF_CHO)
        {
            HistoryReplace(SCR_BT_REFREAH_PROFILE, SCR_BT_MYDEV_PROF_CHO, mmi_bt_entry_mydev_prof_choose);
        }
        else if(g_mmi_bt_scr_cntx.flag & MMI_BT_REFRESH_PROFILE_LIST_SUP_PROF)
        {
            HistoryReplace(SCR_BT_REFREAH_PROFILE, SCR_BT_MYDEV_SUP_PROFILE, mmi_bt_entry_mydev_sup_ser);
        }
        return;
    }

    mmi_bt_stop_progress_scr(MMI_FALSE);

    if (g_mmi_bt_scr_cntx.flag & MMI_BT_REFRESH_PROFILE_LIST_PROF_CHO)
    {
        mmi_bt_entry_mydev_prof_choose();
    }
    else if(g_mmi_bt_scr_cntx.flag & MMI_BT_REFRESH_PROFILE_LIST_SUP_PROF)
    {
        mmi_bt_entry_mydev_sup_ser();
    }
    
    DeleteScreenIfPresent(SCR_BT_REFREAH_PROFILE);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_mydev_conn
 * DESCRIPTION
 *  This function is bluetooth highlight handler.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_mydev_conn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* to avoid the error operation while bt module is busy */
    if ((mmi_bt_is_permission) (MMI_TRUE) == MMI_FALSE)
    {
        return;
    }
    
    /* prohibited by simap, shall deactivate simap first */
    if (mmi_bt_is_simap_server_activate())
    {
        mmi_bt_popup_prohibited_by_simap();
        return;
    }
    
    mmi_bt_connecting(&(g_mmi_bt_scr_cntx.conn_dev_add), g_mmi_bt_scr_cntx.conn_profile_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_exit_mydev_conn
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_exit_mydev_conn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //memset(&(g_mmi_bt_scr_cntx.conn_dev_add),0, sizeof(mmi_bt_dev_addr));
    //memset(&(g_mmi_bt_scr_cntx.conn_profile_id),0, sizeof(U32));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_mydev_connected_prof
 * DESCRIPTION
 *  This function is bluetooth highlight handler.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_mydev_connected_prof(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *ItemList[MAX_SUB_MENUS];
    U16 nItems;
    U8 *guiBuffer;
    U32 i;
    U8 action_item;
    U8 act_con_num;
    mmi_bt_dev_struct *dev_p;
    mmi_bt_connect_struct *conn_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&nItems, 0, MAX_SUB_MENUS);
    /* hilight_item is the index of paired list */
    /* Put Inquiry NEW Device at the first item of Mydev menu */
    MMI_BT_ASSERT(g_mmi_bt_scr_cntx.hilight_item != 0);
    
    action_item = g_mmi_bt_scr_cntx.hilight_item -1 ;
    dev_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_info) ((U16) action_item);
    act_con_num = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_existed_dev_num) ();

    EntryNewScreen(
        SCR_BT_MYDEV_CONNECTED_PROF,
        mmi_bt_exit_mydev_connected_prof,
        mmi_bt_entry_mydev_connected_prof,
        NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_BT_MYDEV_CONNECTED_PROF);

    nItems = 0;

    for (i = 0; i < act_con_num; i++)
    {
        conn_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_existed_conn_info) ((U16) i);
        if (conn_p->active == MMI_TRUE && conn_p->index_of_paried_list == action_item)
        {
            mmi_bt_get_connect_type_str_id(conn_p->conn_type, &(ItemList[nItems]));
            nItems++;
        }

    }

    SetParentHandler(MENU_CONN_BT_MYDEV);
    RegisterHighlightHandler(mmi_bt_mydev_connected_prof_hilite_hdlr);


    if (!(*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_connection_active) (&(dev_p->bd_addr)))
    {
        ItemList[0] = (U8*) GetString(STR_GLOBAL_EMPTY_LIST);
        nItems = 1;
        ShowCategory53Screen(
            STR_BT_MYDEV_OPT_CONNECTED_PROF,
            GetRootTitleIcon(MENU_CONN_BT_MAIN),
            NULL,
            NULL,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_OK,
            nItems,
            (U8 **) ItemList,
            (PU16) gIndexIconsImageList,
            NULL,
            0,
            0,
            guiBuffer);
    }
    else
    {
        ShowCategory53Screen(
            STR_BT_MYDEV_OPT_CONNECTED_PROF,
            GetRootTitleIcon(MENU_CONN_BT_MAIN),
            STR_BT_LSK_DISC,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_OK,
            nItems,
            (U8 **) ItemList,
            (PU16) gIndexIconsImageList,
            NULL,
            0,
            0,
            guiBuffer);
    }


    if ((*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_connection_active) (&(dev_p->bd_addr)))
    {
        SetLeftSoftkeyFunction(mmi_bt_mydev_connected_prof_disconn, KEY_EVENT_UP);
        SetKeyHandler(mmi_bt_mydev_connected_prof_disconn, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
    else
    {
        g_mmi_bt_scr_cntx.reset_gui_buffer_flag = MMI_TRUE;
        SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
        SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        ChangeLeftSoftkey(0, 0);
    }

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_update_mydev_connected_prof_screen
 * DESCRIPTION
 *  This function is bluetooth highlight handler.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_update_mydev_connected_prof_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *ItemList[MAX_SUB_MENUS];
    U16 nItems;
    U32 i;
    U8 action_item;
    U8 act_con_num;
    mmi_bt_dev_struct *dev_p;
    mmi_bt_connect_struct *conn_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetActiveScreenId() != SCR_BT_MYDEV_CONNECTED_PROF)
    {
        return;
    }

    if (ExitCategoryFunction)
    {
        ExitCategoryFunction();
    }

    UI_common_screen_exit();

    memset(&nItems, 0, MAX_SUB_MENUS);
    /* hilight_item is the index of paired list */
    /* Put Inquiry NEW Device at the first item of Mydev menu */
    MMI_BT_ASSERT(g_mmi_bt_scr_cntx.hilight_item != 0);
    action_item = g_mmi_bt_scr_cntx.hilight_item - 1;
    dev_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_info) ((U16) action_item);
    act_con_num = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_existed_dev_num) ();

    nItems = 0;

    for (i = 0; i < act_con_num; i++)
    {
        conn_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_existed_conn_info) ((U16) i);
        if (conn_p->active == MMI_TRUE && conn_p->index_of_paried_list == action_item)
        {
            mmi_bt_get_connect_type_str_id(conn_p->conn_type, &(ItemList[nItems]));
            nItems++;
        }

    }


    RegisterHighlightHandler(mmi_bt_mydev_connected_prof_hilite_hdlr);

    if (!(*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_connection_active) (&(dev_p->bd_addr)))
    {
        ItemList[0] = (U8*) GetString(STR_GLOBAL_EMPTY_LIST);
        nItems = 1;
        
        ShowCategory53Screen(
            STR_BT_MYDEV_OPT_CONNECTED_PROF,
            GetRootTitleIcon(MENU_CONN_BT_MAIN),
            NULL,
            NULL,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_OK,
            nItems,
            (U8 **) ItemList,
            (PU16) gIndexIconsImageList,
            NULL,
            0,
            0,
            NULL);

    }
    else
    {
        ShowCategory53Screen(
            STR_BT_MYDEV_OPT_CONNECTED_PROF,
            GetRootTitleIcon(MENU_CONN_BT_MAIN),
            STR_BT_LSK_DISC,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_OK,
            nItems,
            (U8 **) ItemList,
            (PU16) gIndexIconsImageList,
            NULL,
            0,
            (S32)g_mmi_bt_scr_cntx.conn_prof_hilight_item,
            NULL);
    }

    

    if ((*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_connection_active) (&(dev_p->bd_addr)))
    {
        SetLeftSoftkeyFunction(mmi_bt_mydev_connected_prof_disconn, KEY_EVENT_UP);
        SetKeyHandler(mmi_bt_entry_act_dev_dis, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
    else
    {
        g_mmi_bt_scr_cntx.reset_gui_buffer_flag = MMI_TRUE;
        SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
        SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        ChangeLeftSoftkey(0, 0);
    }

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_exit_mydev_connected_prof
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_exit_mydev_connected_prof(void)
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
 *  mmi_bt_mydev_connected_prof_hilite_hdlr
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  idx         [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_mydev_connected_prof_hilite_hdlr(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_SCR_HIGHLIGHT_ITEM, idx);

    g_mmi_bt_scr_cntx.conn_prof_hilight_item = idx;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_mydev_connected_prof_disconn
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_mydev_connected_prof_disconn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 act_con_num;
    U8 paired_dev_num;
    U8 paired_dev_index;
    U32 i, j;
    mmi_bt_dev_struct *dev_p;
    mmi_bt_connect_struct *conn_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* to avoid the error operation while bt module is busy */
    if ((mmi_bt_is_permission) (MMI_TRUE) == MMI_FALSE)
    {
        return;
    }
    
    /* Put Inquiry NEW Device at the first item of Mydev menu */
    MMI_BT_ASSERT(g_mmi_bt_scr_cntx.hilight_item != 0);

    paired_dev_index = g_mmi_bt_scr_cntx.hilight_item - 1;
    act_con_num = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_existed_dev_num) ();
    paired_dev_num = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_num) ();
    MMI_BT_ASSERT(paired_dev_num);
    MMI_BT_ASSERT(paired_dev_index < paired_dev_num);
    dev_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_info) (paired_dev_index);

    j = 0;
    /* get index of existed_conn */
    for (i = 0; i < act_con_num; i++)
    {
        conn_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_existed_conn_info) ((U16) i);
        if (conn_p->active == MMI_TRUE && conn_p->index_of_paried_list == paired_dev_index)
        {
            if (j == g_mmi_bt_scr_cntx.conn_prof_hilight_item)
            {
                break;
            }
            j++;
        }
    }

    if (i == act_con_num || conn_p == NULL)
    {
        DisplayPopup(
            (U8*) GetString(STR_BT_CON_RELEASED),
            IMG_GLOBAL_ACTIVATED,
            MMI_FALSE,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) SUCCESS_TONE);
        return;
    }

    MMI_BT_ASSERT(i != act_con_num);
    MMI_BT_ASSERT(conn_p != NULL);

    /* filter some unsupported-disconnecting profiles */
    if (mmi_bt_check_supported_connection_type((U32*) support_disconnecting_profile_tbl, (U32) conn_p->conn_type))
    {
        /* for BT profile */
    #if defined(__MMI_BT_PROFILE__)
        switch (conn_p->conn_type)
        {
            case MMI_BT_HFP_CONNECTION:
            case MMI_BT_HSP_CONNECTION:
                mmi_profiles_bt_disconnect_callback(MMI_PROFILES_BT_HFP_ACL, MMI_PROFILES_BT_REQ, MMI_PROFILES_BT_OK);
                break;
            case MMI_BT_A2DP_CONNECTION:
                #if !defined(__MMI_BT_MTK_SUPPORT__)
                mmi_profiles_bt_disconnect_callback(MMI_PROFILES_BT_A2DP_SIG, MMI_PROFILES_BT_REQ, MMI_PROFILES_BT_OK);
                #endif
                break;
            default:
                break;
        }
    #endif /* defined(__MMI_BT_PROFILE__) */ 

        g_mmi_bt_scr_cntx.disconn_conn_type = (U32) conn_p->conn_type;

        if ((*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_disconnect_req) (conn_p->conn_id, conn_p->conn_type) == MMI_FALSE)
        {
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_ERROR),
                IMG_GLOBAL_ERROR,
                MMI_FALSE,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
        }
        else
        {
			g_mmi_bt_scr_cntx.disconnecting_conn_type = (U32) conn_p->conn_type;       
            mmi_bt_show_progress_scr(SCR_BT_DISC_PROC, STR_BT_DISCONNECT, STR_BT_DISCONNECTING, NULL, MMI_FALSE, NULL);
        }
    }
    else
    {
        DisplayPopup(
            (U8*) GetString(STR_BT_NOT_SUPPORT),
            IMG_GLOBAL_ERROR,
            MMI_FALSE,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
    }

}

/* Configure Default Headset */
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_mydev_set_default_hs
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_mydev_set_default_hs(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 action_item;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Configure Default Headset */
    /* Put Inquiry NEW Device at the first item of Mydev menu */    
    MMI_BT_ASSERT(g_mmi_bt_scr_cntx.hilight_item != 0);
	action_item = g_mmi_bt_scr_cntx.hilight_item - 1;
    if ((*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_set_default_hs_index) (action_item))
    {
	    DisplayPopup(
	        (U8*) GetString(STR_GLOBAL_DONE),
	        IMG_GLOBAL_ACTIVATED,
	        MMI_FALSE,
	        UI_POPUP_NOTIFYDURATION_TIME,
	        (U8) SUCCESS_TONE);
    }
    else
    {
		DisplayPopup(
		    (U8*) GetString(STR_GLOBAL_DONE), /* show re-select it again */
		    IMG_GLOBAL_WARNING,
		    MMI_FALSE,
		    UI_POPUP_NOTIFYDURATION_TIME,
		    (U8) WARNING_TONE);
    }

}
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_mydev_ren
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_mydev_ren(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    U8 utf8_char_cnt = 0;
    U8 ucs2_str_len = 0;
    mmi_bt_dev_struct *dev_p;
	U32 action_item;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_SCR_REN);

	/* Put Inquiry NEW Device at the first item of Mydev menu */
	MMI_BT_ASSERT(g_mmi_bt_scr_cntx.hilight_item !=0);
	action_item = g_mmi_bt_scr_cntx.hilight_item - 1;
    dev_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_info) ((U16) action_item);


    EntryNewScreen(SCR_BT_MYDEV_REN, NULL, mmi_bt_entry_mydev_ren, NULL);

    if ((gui_buffer = GetCurrGuiBuffer(SCR_BT_MYDEV_REN)) == NULL)
    {
        utf8_char_cnt = (U8) ((mmi_chset_utf8_strlen((kal_uint8*) (dev_p->name)) + 1) * ENCODING_LENGTH);
        MMI_BT_ASSERT(MMI_BT_SCR_BUF_SIZE >= MMI_BT_SCR_BD_NAME_LEN);
        if (utf8_char_cnt > MMI_BT_SCR_BD_NAME_LEN)
        {
            ucs2_str_len =
                (U8) mmi_chset_utf8_to_ucs2_string(
                        (kal_uint8*) g_mmi_bt_scr_cntx.scr_buf,
                        MMI_BT_SCR_BD_NAME_LEN,
                        (kal_uint8*) dev_p->name);
        }
        else
        {
            ucs2_str_len =
                (U8) mmi_chset_utf8_to_ucs2_string(
                        (kal_uint8*) g_mmi_bt_scr_cntx.scr_buf,
                        utf8_char_cnt,
                        (kal_uint8*) dev_p->name);
        }
    }
	/* allow (MMI_BT_BD_NAME_LEN/3) chinese characters or (MMI_BT_BD_NAME_LEN/3)*2 english characters  */
	/* so for UCS2 encoding, need MMI_BT_SCR_BD_NAME_LEN bytes */

	/* shall check if there is any two_byte character mixed in one_bye UCS2 string */
	/* if yes, then truncate the string to meet above rules((MMI_BT_BD_NAME_LEN/3) chinese characters or (MMI_BT_BD_NAME_LEN/3)*2 english characters)*/	
	if(mmi_bt_test_ucs2((U16*)g_mmi_bt_scr_cntx.scr_buf, (U16)(ucs2_str_len/ENCODING_LENGTH)) )
	{ 
		mmi_bt_truncate_ucs2_string((U16*)g_mmi_bt_scr_cntx.scr_buf, 
		    							(U16)(ucs2_str_len/ENCODING_LENGTH),
		    							(U16)((MMI_BT_BD_NAME_LEN-2)/3)
		    						   );		    
	}

    ShowCategory5Screen_ext(
        STR_BT_MYDEV_OPT_REN,
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        STR_GLOBAL_OPTIONS,
        0,
        STR_GLOBAL_BACK,
        0,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ENCODING_BASED_LENGTH,
        (U8*) g_mmi_bt_scr_cntx.scr_buf,
        (MMI_BT_SCR_BD_NAME_LEN / ENCODING_LENGTH),
        gui_buffer,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
        NULL,
        NULL);

    SetLeftSoftkeyFunction(mmi_bt_entry_mydev_ren_edopt, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    RegisterInputMethodScreenCloseFunction(mmi_bt_goback_2_history);
}

/*****************************************************************************
* FUNCTION
*  mmi_bt_exit_mydev_ren
* DESCRIPTION
*   This function is  
*
* PARAMETERS
*  a  IN/OUT      first variable, used as returns
*  b  IN       second variable
* RETURNS
*  NONE.
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/
void mmi_bt_exit_mydev_ren(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_mydev_ren_edopt
 * DESCRIPTION
 *  This function is the entry function for Bluetooth->My Dev->Option->rename
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_mydev_ren_edopt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 item_texts[] = {STR_GLOBAL_DONE, STR_GLOBAL_INPUT_METHOD};
    U16 item_icons[] = {IMG_GLOBAL_L1, IMG_GLOBAL_L2};
    U8 *guiBuffer;                      /* Buffer holding history data */
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_BT_MYDEV_REN_OPT, NULL, mmi_bt_entry_mydev_ren_edopt, NULL);

    /* Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_BT_MYDEV_REN_OPT);

    RegisterHighlightHandler(mmi_bt_mydev_ren_edopt_hilite_hdlr);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        2,
        item_texts,
        item_icons,
        NULL,
        0,
        0,
        guiBuffer);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_mydev_ren_edopt_hilite_hdlr
 * DESCRIPTION
 *  This function is hilight handler for Extra->Bluetooth->My Dev->Option->rename
 * PARAMETERS
 *  idx         [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_mydev_ren_edopt_hilite_hdlr(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BT_ASSERT((idx >= 0) && (idx < MMI_BT_DEVNAME_EDOPT_LAST));

    switch (idx)
    {
        case MMI_BT_DEVNAME_EDOPT_DONE:
            SetLeftSoftkeyFunction(mmi_bt_mydev_ren_proc, KEY_EVENT_UP);
            SetKeyHandler(mmi_bt_mydev_ren_proc, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            break;
        case MMI_BT_DEVNAME_EDOPT_INPMETHOD:
            SetLeftSoftkeyFunction(EntryInputMethodScreen, KEY_EVENT_UP);
            SetKeyHandler(EntryInputMethodScreen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            break;

        default:
            break;
    }

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_mydev_ren_proc
 * DESCRIPTION
 *  This function is to Entry function for Extra->Bluetooth->My Dev->Option->rename
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_mydev_ren_proc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index;
    mmi_bt_dev_struct *dev_p;
    S32 ucs2_byte_count;
    MMI_BOOL test_ucs2_char = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/* Put Inquiry NEW Device at the first item of Mydev menu */
    MMI_BT_ASSERT(g_mmi_bt_scr_cntx.hilight_item !=0);
    index = g_mmi_bt_scr_cntx.hilight_item - 1;
    dev_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_info) (index);


    ucs2_byte_count = (mmi_ucs2strlen((const S8*)g_mmi_bt_scr_cntx.scr_buf) * ENCODING_LENGTH) + ENCODING_LENGTH;

    if (ucs2_byte_count == ENCODING_LENGTH)
    {
        DisplayPopup(
            (U8*) GetString(STR_BT_SET_NAME_LENGTH_LIMITATION),
            IMG_GLOBAL_ERROR,
            MMI_FALSE,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);

        DeleteScreenIfPresent(SCR_BT_MYDEV_REN);
        DeleteScreenIfPresent(SCR_BT_MYDEV_REN_OPT);
        
    }
    else
    {
        if ((ucs2_byte_count-ENCODING_LENGTH)/ENCODING_LENGTH > (MMI_BT_BD_NAME_LEN-2)/3)
        {
            test_ucs2_char = mmi_bt_test_ucs2((U16*)g_mmi_bt_scr_cntx.scr_buf, (U16)(ucs2_byte_count/ENCODING_LENGTH));
            /* allow (MMI_BT_BD_NAME_LEN/3) chinese characters or (MMI_BT_BD_NAME_LEN/3)*2 english characters  */
            /* so for UCS2 encoding, need MMI_BT_SCR_BD_NAME_LEN bytes */
            /* shall check if there is any two_byte character mixed in one_bye UCS2 string */
            /* if yes, then truncate the string to meet above rules((MMI_BT_BD_NAME_LEN/3) chinese characters or (MMI_BT_BD_NAME_LEN/3)*2 english characters)*/ 
    		if(test_ucs2_char)
    		{ 
    			mmi_bt_truncate_ucs2_string((U16*)g_mmi_bt_scr_cntx.scr_buf, 
    			    							(U16)(ucs2_byte_count/ENCODING_LENGTH),
    			    							(U16)((MMI_BT_BD_NAME_LEN-2)/3)
    			    						   );		    
    		}
        }
        
        /* Store device name to nvram */
        mmi_chset_ucs2_to_utf8_string(
            (kal_uint8*) dev_p->name,
            MMI_BT_BD_NAME_LEN,
            (kal_uint8*) g_mmi_bt_scr_cntx.scr_buf);
        (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_nvram_write_info) ();

		if (test_ucs2_char)
	    {
            DisplayPopup(
                (U8*) GetString(STR_BT_TRUNCATE_NAME_FOR_DIFF_CHAR_SET),
                IMG_GLOBAL_WARNING,
                MMI_FALSE,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) WARNING_TONE);
	    }
		else
	    {
			DisplayPopup(
	            (U8*) GetString(STR_GLOBAL_DONE),
	            IMG_GLOBAL_ACTIVATED,
	            MMI_FALSE,
	            UI_POPUP_NOTIFYDURATION_TIME,
	            (U8) SUCCESS_TONE);
	    }


        DeleteScreenIfPresent(SCR_BT_MYDEV_OPT);
        DeleteScreenIfPresent(SCR_BT_MYDEV_REN);
        DeleteScreenIfPresent(SCR_BT_MYDEV_REN_OPT);

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_mydev_del
 * DESCRIPTION
 *  This function is to Entry function for Extra->Bluetooth->My Dev->Option->rename
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_mydev_del(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bt_dev_struct *dev_p;
    U32 action_item;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_SCR_DEL_TR);
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_SCR_STATUS,
               g_mmi_bt_scr_cntx.state, g_mmi_bt_scr_cntx.flag, g_mmi_bt_scr_cntx.blinking_flag);

	/* Put Inquiry NEW Device at the first item of Mydev menu */
	MMI_BT_ASSERT(g_mmi_bt_scr_cntx.hilight_item !=0);
	action_item = g_mmi_bt_scr_cntx.hilight_item - 1;
    dev_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_info) ((U16) action_item);


    /* to avoid the twice operation*/
    if (g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_PAIRED_DEV_DEL)
    {
        g_mmi_bt_scr_cntx.flag &= ~MMI_BT_CONFIRM_PAIRED_DEV_DEL;    
        StopTimer(BT_POPUP_TIMER);
    }

    /* to avoid the error operation while bt module is busy */
    if ((mmi_bt_is_permission) (MMI_TRUE) == MMI_FALSE)
    {
        return;
    }


    if ((*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_connection_active) (&(g_mmi_bt_scr_cntx.conn_dev_add)))
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
        #endif
        mmi_bt_display_release_dev_connection_confirm(MMI_BT_CONFIRM_PAIRED_DEV_DEL);
        return;
    }

    mmi_bt_show_progress_scr(SCR_BT_MYDEV_DEL, STR_BT_DELETE, STR_BT_DELETING, NULL, MMI_FALSE, NULL);
    #if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_A2DP_SUPPORT__)
    mmi_audply_bt_delete_device_callback(&(dev_p->bd_addr));
    #endif
    g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_mydev_del_req(&(dev_p->bd_addr));

}

/*****************************************************************************
* FUNCTION
*  mmi_bt_exit_mydev_del
* DESCRIPTION
*   This function is 
*
* PARAMETERS
*  a  IN/OUT      first variable, used as returns
*  b  IN       second variable
* RETURNS
*  NONE.
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/
void mmi_bt_exit_mydev_del(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_mydev_del_complete
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  res         [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_mydev_del_complete(U8 res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_SCR_DEL_TR_RES, res);

    mmi_bt_stop_progress_scr(MMI_FALSE);

    if (res == MMI_TRUE)
    {
        DisplayPopup(
            (U8*) GetString(STR_BT_DELETED),
            IMG_GLOBAL_ACTIVATED,
            MMI_FALSE,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) SUCCESS_TONE);
    }
    else
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_ERROR),
            IMG_GLOBAL_ERROR,
            MMI_FALSE,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
    }

    DeleteScreenIfPresent(SCR_BT_MYDEV_OPT);
    DeleteScreenIfPresent(SCR_BT_MYDEV_DEL);
    DeleteScreenIfPresent(SCR_BT_MYDEV_DEL_ALL);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_mydev_del_confirm_rsk_hdler
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_mydev_del_confirm_rsk_hdler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reset scr flag */
    //mmi_bt_reset_scr_flag();
    g_mmi_bt_scr_cntx.flag &= ~MMI_BT_CONFIRM_PAIRED_DEV_DEL;        
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_mydev_del_all
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_mydev_del_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_SCR_DEL_TR);
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_SCR_STATUS,
               g_mmi_bt_scr_cntx.state, g_mmi_bt_scr_cntx.flag, g_mmi_bt_scr_cntx.blinking_flag);
    /* to avoid the twice operation*/
    if (g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_PAIRED_DEV_DEL)
    {
        return;
    }

    /* to avoid the twice operation*/
    if (g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_PAIRED_DEV_DEL_ALL)
    {
        g_mmi_bt_scr_cntx.flag &= ~MMI_BT_CONFIRM_PAIRED_DEV_DEL_ALL;    
        StopTimer(BT_POPUP_TIMER);
    }

    /* to avoid the error operation while bt module is busy */
    if ((mmi_bt_is_permission) (MMI_TRUE) == MMI_FALSE)
    {
        return;
    }

    if ((*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_any_connection_active) ())
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
        #endif
        mmi_bt_display_release_all_connection_confirm(MMI_BT_CONFIRM_PAIRED_DEV_DEL_ALL);
        return;
    }

    #if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_A2DP_SUPPORT__)
    mmi_audply_bt_delete_device_callback(NULL);
    #endif

    if ((*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_mydev_del_all_req) () == MMI_FALSE)
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_EMPTY_LIST),
            IMG_GLOBAL_ERROR,
            MMI_FALSE,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
    }
    else
    {
        mmi_bt_show_progress_scr(SCR_BT_MYDEV_DEL_ALL, STR_BT_DELETE, STR_BT_DELETING, NULL, MMI_FALSE, NULL);
    }
}

/*****************************************************************************
* FUNCTION
*  mmi_bt_exit_mydev_del_all
* DESCRIPTION
*   This function is 
*
* PARAMETERS
*  a  IN/OUT      first variable, used as returns
*  b  IN       second variable
* RETURNS
*  NONE.
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/
void mmi_bt_exit_mydev_del_all(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_mydev_del_all_confirm_rsk_hdler
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_mydev_del_all_confirm_rsk_hdler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reset scr flag */
    //mmi_bt_reset_scr_flag();
    g_mmi_bt_scr_cntx.flag &= ~MMI_BT_CONFIRM_PAIRED_DEV_DEL_ALL;        
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_mydev_auth
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_mydev_auth(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bt_dev_struct *dev_p;
    U32 action_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/* Put Inquiry NEW Device at the first item of Mydev menu */
	MMI_BT_ASSERT(g_mmi_bt_scr_cntx.hilight_item !=0);
	action_item = g_mmi_bt_scr_cntx.hilight_item - 1;
    dev_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_info) ((U16) action_item);

    dev_p->authorise = ~(dev_p->authorise);
    (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_nvram_write_info) ();
    DisplayPopup(
        (U8*) GetString(STR_GLOBAL_DONE),
        IMG_GLOBAL_ACTIVATED,
        MMI_FALSE,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) SUCCESS_TONE);

}

/*****************************************************************************
* FUNCTION
*  mmi_bt_entry_mydev_sup_ser
* DESCRIPTION
*   This function is 
*
* PARAMETERS
*  a  IN/OUT      first variable, used as returns
*  b  IN       second variable
* RETURNS
*  NONE.
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/
void mmi_bt_exit_mydev_auth(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_mydev_sup_ser
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_mydev_sup_ser(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *ItemList[MAX_SUB_MENUS];
    U16 nItems;
    U8 *guiBuffer;
    mmi_bt_dev_struct *dev_p;
    U32 i;
    U32 action_item;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reset profile refresh flag */
    g_mmi_bt_scr_cntx.flag &= ~MMI_BT_REFRESH_PROFILE_LIST_SUP_PROF;
    
    memset(&nItems, 0, MAX_SUB_MENUS);

	/* Put Inquiry NEW Device at the first item of Mydev menu */
	MMI_BT_ASSERT(g_mmi_bt_scr_cntx.hilight_item !=0);
	action_item = g_mmi_bt_scr_cntx.hilight_item - 1;

    dev_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_info) ((U16)action_item);

    EntryNewScreen(SCR_BT_MYDEV_SUP_PROFILE, NULL, mmi_bt_entry_mydev_sup_ser, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_BT_MYDEV_SUP_PROFILE);

    nItems = 0;
    for (i = 0; i < dev_p->service_list_num; i++)
    {
        if (mmi_bt_get_profile_str_id((U16) dev_p->service_list[i], &(ItemList[nItems])) == MMI_FALSE)
        {
            /* NOT Considered Profile UUID */
            //MMI_BT_ASSERT(0);
            //nItems--;
        }
        nItems++;
    }

    SetParentHandler(MENU_CONN_BT_MYDEV);

    ShowCategory53Screen(
        STR_BT_MYDEV_OPT_SUP_SER,
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        STR_BT_REFRESH,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nItems,
        (U8 **) ItemList,
        (PU16) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_bt_sup_ser_refresh_prof_list, KEY_EVENT_UP);

    /* go back */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}

/*****************************************************************************
* FUNCTION
*  mmi_bt_exit_mydev_sup_ser
* DESCRIPTION
*   This function is 
*
* PARAMETERS
*  a  IN/OUT      first variable, used as returns
*  b  IN       second variable
* RETURNS
*  NONE.
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/
void mmi_bt_exit_mydev_sup_ser(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_sup_ser_refresh_prof_list
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_sup_ser_refresh_prof_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_SCR_STATUS,
               g_mmi_bt_scr_cntx.state, g_mmi_bt_scr_cntx.flag, g_mmi_bt_scr_cntx.blinking_flag);
    /* to avoid the twice operation*/
    if (g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_PAIRED_DEV_DEL_ALL)
    {
        return;
    }

    /* to avoid the error operation while bt module is busy */
    if ((mmi_bt_is_permission) (MMI_TRUE) == MMI_FALSE)
    {
        return;
    }

    g_mmi_bt_scr_cntx.flag |= MMI_BT_REFRESH_PROFILE_LIST_SUP_PROF;
    (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_refresh_service_list_req) (&(g_mmi_bt_scr_cntx.conn_dev_add));
    mmi_bt_show_progress_scr(
        SCR_BT_REFREAH_PROFILE,
        STR_BT_REFRESH_SERVICE_LIST,
        STR_BT_REFRESHING,
        NULL,
        MMI_FALSE,
        NULL);
    DeleteScreenIfPresent(SCR_BT_MYDEV_SUP_PROFILE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_mydev_sch
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_mydev_sch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 max_response;
    U16 timeout;
    U32 cod;
    MMI_BOOL name_discovery;
    U16 title_str_id;
    U8 inquiry_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* to avoid the twice inquiry operation while bt is just on and wanna do the inquiry */
    if (g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_PAIRED_DEV_SCH)
    {
        g_mmi_bt_scr_cntx.flag &= ~MMI_BT_CONFIRM_PAIRED_DEV_SCH;    
        StopTimer(BT_POPUP_TIMER);
    }

    
    if ((*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_pwron) () == MMI_FALSE)
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
        #endif
        mmi_bt_display_power_on_confirm(MMI_BT_CONFIRM_PAIRED_DEV_SCH);
        return;
    }

    /* to avoid the error operation while bt module is busy */
    if ((mmi_bt_is_permission) (MMI_TRUE) == MMI_FALSE)
    {
        return;
    }

    
    /* prohibited by simap, shall deactivate simap first */
    if (mmi_bt_is_simap_server_activate())
    {
        mmi_bt_popup_prohibited_by_simap();
        return;
    }

    /* to disconnect sco first if sco connected */
    #if defined(__MMI_BT_AUDIO_VIA_SCO__) || defined(__MMI_BT_FM_VIA_SCO__)
	//if(mmi_profiles_bt_is_connected((U8)MMI_PROFILES_BT_HFP_SCO))
	{
  	    if (mmi_profiles_bt_inquery_start_callback(mmi_bt_entry_mydev_sch))
	    {
    		return;
	    }
	}
    #endif

    max_response = MMI_BT_MAX_INQUIRY_RESULTS_IN_LIST;
    timeout = MMI_BT_INQUIRY_TIMEOUT_DURATION;
    cod = MMI_BT_MISCELLANEOUS_MAJOR_DEVICE_MASK;
    name_discovery = MMI_TRUE /* MMI_FALSE */ ;
    title_str_id = STR_BT_SCH_ALL_DEV;
    inquiry_type = MMI_BT_INQ_TYPE_ALL_DEV;
    g_mmi_bt_scr_cntx.flag |= MMI_BT_INQ_TYPE_ALL_DEV;
    mmi_bt_inquiry(max_response, timeout, cod, name_discovery, title_str_id, inquiry_type);

}

/*****************************************************************************
* FUNCTION
*  mmi_bt_exit_mydev_sch
* DESCRIPTION
*   This function is 
*
* PARAMETERS
*  a  IN/OUT      first variable, used as returns
*  b  IN       second variable
* RETURNS
*  NONE.
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/
void mmi_bt_exit_mydev_sch(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_mydev_sch_confirm_rsk_hdler
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_mydev_sch_confirm_rsk_hdler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reset scr flag */
    //mmi_bt_reset_scr_flag();
    g_mmi_bt_scr_cntx.flag &= ~MMI_BT_CONFIRM_PAIRED_DEV_SCH;
    GoBackHistory();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_act_dev_menu
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_act_dev_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemIcons[MAX_SUB_MENUS];
    U16 nItems;
    U8 *guiBuffer;
    U8 i, j;
    U8 act_con_num;
    U8 paired_dev_num;
    U8 paired_dev_index;
    mmi_bt_connect_struct *conn_p;
    mmi_bt_dev_struct *dev_struct_p;
    U8 utf8_char_cnt = 0;
    U8 ucs2_str_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((mmi_bt_is_hw_ready) (MMI_TRUE) == MMI_FALSE)
    {
        return;
    }

    EntryNewScreen(SCR_BT_ACT_DEV, NULL, mmi_bt_entry_act_dev_menu, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_BT_ACT_DEV);

    /* Get paired device info */
    /* nItems = (U16) g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_num(); */
    act_con_num = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_existed_dev_num) ();
    paired_dev_num = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_num) ();

    /* Clear UI buffer */
    memset(ItemIcons, 0, (sizeof(U16) * MAX_SUB_MENUS));
    //memset( subMenuData, 0, (MAX_SUB_MENUS*MAX_SUB_MENU_SIZE) );
    //memset( hintData, 0, (MAX_SUB_MENUS*MAX_SUB_MENU_HINT_SIZE) );

    j = 0;
    for (i = 0; i < act_con_num; i++)
    {

        conn_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_existed_conn_info) ((U16) i);
        if (conn_p->active == MMI_TRUE)
        {
            paired_dev_index = conn_p->index_of_paried_list;
            MMI_BT_ASSERT(paired_dev_index < paired_dev_num);
            dev_struct_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_info) (paired_dev_index);

            /* Fill device name list */
            /* get byte count for convert utf8 string to UCS2 string */
            /* get character count of utf8 string */
            /* +1 is for UCS2 NULL terminate */
            /* *ENCODING_LENGTH is for byte count of one UCS2 character */
            utf8_char_cnt = (U8) ((mmi_chset_utf8_strlen((kal_uint8*) dev_struct_p->name) + 1) * ENCODING_LENGTH);
            MMI_BT_ASSERT(MAX_SUB_MENU_SIZE >= MMI_BT_SCR_BD_NAME_LEN);
            if (utf8_char_cnt > MMI_BT_SCR_BD_NAME_LEN)
            {
                ucs2_str_len =
                    (U8) mmi_chset_utf8_to_ucs2_string(
                            (kal_uint8*) subMenuData[j],
                            MMI_BT_SCR_BD_NAME_LEN,
                            (kal_uint8*) dev_struct_p->name);
            }
            else
            {
                ucs2_str_len =
                    (U8) mmi_chset_utf8_to_ucs2_string(
                            (kal_uint8*) subMenuData[j],
                            utf8_char_cnt,
                            (kal_uint8*) dev_struct_p->name);
            }
            
			/* allow (MMI_BT_BD_NAME_LEN/3) chinese characters or (MMI_BT_BD_NAME_LEN/3)*2 english characters  */
			/* so for UCS2 encoding, need MMI_BT_SCR_BD_NAME_LEN bytes */

			/* shall check if there is any two_byte character mixed in one_bye UCS2 string */
			/* if yes, then truncate the string to meet above rules((MMI_BT_BD_NAME_LEN/3) chinese characters or (MMI_BT_BD_NAME_LEN/3)*2 english characters)*/	
			if(mmi_bt_test_ucs2((U16*)subMenuData[j], (U16)(ucs2_str_len/ENCODING_LENGTH)) )
			{ 
				mmi_bt_truncate_ucs2_string((U16*)subMenuData[j], 
				    							(U16)(ucs2_str_len/ENCODING_LENGTH),
				    							(U16)((MMI_BT_BD_NAME_LEN-2)/3)
				    						   );		    
			}
            
            subMenuDataPtrs[j] = subMenuData[j];

        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* 0 */ 
            /* connected profile */
            if (mmi_bt_get_connect_type_str_id(conn_p->conn_type, &(hintDataPtrs[j])) == MMI_FALSE)
            {
                /* NOT Considered Profile UUID */
                /* MMI_BT_ASSERT(0); */
            }

            /* Fill device icon list */
            if (dev_struct_p->cod & MMI_BT_COMPUTER_MAJOR_DEVICE_MASK)
            {
                ItemIcons[j] = IMG_BT_DEV_LAP;
            }
            else if (dev_struct_p->cod & MMI_BT_PRINTER_IMAGING_MINOR_DEVICE_CLASS)
            {
                ItemIcons[j] = IMG_BT_DEV_PRT;
            }
            else if (dev_struct_p->cod & MMI_BT_PHONE_MAJOR_DEVICE_MASK)
            {
                ItemIcons[j] = IMG_BT_DEV_MOB;
            }
            else if (dev_struct_p->cod & MMI_BT_AV_MAJOR_DEVICE_MASK)
            {
                ItemIcons[j] = IMG_BT_DEV_EAR;
            }
            else
            {
                ItemIcons[j] = IMG_BT_DEV_OTHER;
            }

            j++;
        }
    }

    nItems = j;
    SetParentHandler(MENU_CONN_BT_MAIN);

    RegisterHighlightHandler(mmi_bt_act_dev_hilite_hdlr);

    if (nItems == 0)
    {
        mmi_ucs2cpy((S8*) subMenuData[0], (S8*) GetString(STR_GLOBAL_EMPTY_LIST));
        subMenuDataPtrs[0] = subMenuData[0];
        hintDataPtrs[0] = NULL;
        ItemIcons[0] = 0;
        nItems = 1;
        ShowCategory53Screen(
            STR_BT_ACT_DEV,
            GetRootTitleIcon(MENU_CONN_BT_MAIN),
            NULL,
            NULL,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            nItems,
            (U8 **) subMenuDataPtrs,
            (U16*) ItemIcons,
            hintDataPtrs,
            0,
            0,
            guiBuffer);
        
    }
    else
    {
        ShowCategory53Screen(
            STR_BT_ACT_DEV,
            GetRootTitleIcon(MENU_CONN_BT_MAIN),
            STR_BT_LSK_DISC,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            nItems,
            (U8 **) subMenuDataPtrs,
            (U16*) ItemIcons,
            hintDataPtrs,
            0,
            0,
            guiBuffer);

    }


    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}

/*****************************************************************************
* FUNCTION
*  mmi_bt_exit_act_dev_menu
* DESCRIPTION
*  This function is to activate or deactivate bt function
*
* PARAMETERS
*  a  IN/OUT   first variable, used as returns
*  b  IN       second variable
* RETURNS
*  NONE.  
* GLOBALS AFFECTED
*  external_global
*****************************************************************************/
void mmi_bt_exit_act_dev_menu(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_update_act_dev_screen
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_update_act_dev_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemIcons[MAX_SUB_MENUS];
    U16 nItems;
    U8 i, j;
    U8 act_con_num;
    U8 paired_dev_num;
    U8 paired_dev_index;
    mmi_bt_connect_struct *conn_p;
    mmi_bt_dev_struct *dev_struct_p;
    U8 utf8_char_cnt = 0;
    U8 ucs2_str_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetActiveScreenId() != SCR_BT_ACT_DEV)
    {
        return;
    }

    if (ExitCategoryFunction)
    {
        ExitCategoryFunction();
    }

    UI_common_screen_exit();

    /* Get paired device info */
    act_con_num = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_existed_dev_num) ();
    paired_dev_num = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_num) ();

    /* Clear UI buffer */
    memset(ItemIcons, 0, (sizeof(U16) * MAX_SUB_MENUS));

    j = 0;
    for (i = 0; i < act_con_num; i++)
    {

        conn_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_existed_conn_info) ((U16) i);
        if (conn_p->active == MMI_TRUE)
        {
            paired_dev_index = conn_p->index_of_paried_list;
            MMI_BT_ASSERT(paired_dev_index < paired_dev_num);
            dev_struct_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_info) (paired_dev_index);

            /* Fill device name list */
            /* get byte count for convert utf8 string to UCS2 string */
            /* get character count of utf8 string */
            /* +1 is for UCS2 NULL terminate */
            /* *ENCODING_LENGTH is for byte count of one UCS2 character */
            utf8_char_cnt = (U8) ((mmi_chset_utf8_strlen((kal_uint8*) dev_struct_p->name) + 1) * ENCODING_LENGTH);
            MMI_BT_ASSERT(MAX_SUB_MENU_SIZE >= MMI_BT_SCR_BD_NAME_LEN);
            if (utf8_char_cnt > MMI_BT_SCR_BD_NAME_LEN)
            {
                ucs2_str_len =
                    (U8) mmi_chset_utf8_to_ucs2_string(
                            (kal_uint8*) subMenuData[j],
                            MMI_BT_SCR_BD_NAME_LEN,
                            (kal_uint8*) dev_struct_p->name);
            }
            else
            {
                ucs2_str_len =
                    (U8) mmi_chset_utf8_to_ucs2_string(
                            (kal_uint8*) subMenuData[j],
                            utf8_char_cnt,
                            (kal_uint8*) dev_struct_p->name);
            }

			/* allow (MMI_BT_BD_NAME_LEN/3) chinese characters or (MMI_BT_BD_NAME_LEN/3)*2 english characters  */
			/* so for UCS2 encoding, need MMI_BT_SCR_BD_NAME_LEN bytes */

			/* shall check if there is any two_byte character mixed in one_bye UCS2 string */
			/* if yes, then truncate the string to meet above rules((MMI_BT_BD_NAME_LEN/3) chinese characters or (MMI_BT_BD_NAME_LEN/3)*2 english characters)*/	
			if(mmi_bt_test_ucs2((U16*)subMenuData[j], (U16)(ucs2_str_len/ENCODING_LENGTH)) )
			{ 
				mmi_bt_truncate_ucs2_string((U16*)subMenuData[j], 
				    							(U16)(ucs2_str_len/ENCODING_LENGTH),
				    							(U16)((MMI_BT_BD_NAME_LEN-2)/3)
				    						   );		    
			}
            
            subMenuDataPtrs[j] = subMenuData[j];

            /* connected profile */
            if (mmi_bt_get_connect_type_str_id(conn_p->conn_type, &(hintDataPtrs[j])) == MMI_FALSE)
            {
                /* NOT Considered Profile UUID */
                /* MMI_BT_ASSERT(0); */
            }

            /* Fill device icon list */
            if (dev_struct_p->cod & MMI_BT_COMPUTER_MAJOR_DEVICE_MASK)
            {
                ItemIcons[j] = IMG_BT_DEV_LAP;
            }
            else if (dev_struct_p->cod & MMI_BT_PRINTER_IMAGING_MINOR_DEVICE_CLASS)
            {
                ItemIcons[j] = IMG_BT_DEV_PRT;
            }
            else if (dev_struct_p->cod & MMI_BT_PHONE_MAJOR_DEVICE_MASK)
            {
                ItemIcons[j] = IMG_BT_DEV_MOB;
            }
            else if (dev_struct_p->cod & MMI_BT_AV_MAJOR_DEVICE_MASK)
            {
                ItemIcons[j] = IMG_BT_DEV_EAR;
            }
            else
            {
                ItemIcons[j] = IMG_BT_DEV_OTHER;
            }

            j++;
        }
    }

    nItems = j;

    RegisterHighlightHandler(mmi_bt_act_dev_hilite_hdlr);

    if (nItems == 0)
    {
        mmi_ucs2cpy((S8*) subMenuData[0], (S8*) GetString(STR_GLOBAL_EMPTY_LIST));
        subMenuDataPtrs[0] = subMenuData[0];
        hintDataPtrs[0] = NULL;
        ItemIcons[0] = 0;
        nItems = 1;
        ShowCategory53Screen(
            STR_BT_ACT_DEV,
            GetRootTitleIcon(MENU_CONN_BT_MAIN),
            NULL,
            NULL,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            nItems,
            (U8 **) subMenuDataPtrs,
            (U16*) ItemIcons,
            hintDataPtrs,
            0,
            0,
            NULL);

    }
    else
    {
        ShowCategory53Screen(
            STR_BT_ACT_DEV,
            GetRootTitleIcon(MENU_CONN_BT_MAIN),
            STR_BT_LSK_DISC,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            nItems,
            (U8 **) subMenuDataPtrs,
            (U16*) ItemIcons,
            hintDataPtrs,
            0,
            (S32)g_mmi_bt_scr_cntx.hilight_item,
            NULL);
    }


    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_act_dev_hilite_hdlr
 * DESCRIPTION
 *  This function is bluetooth highlight handler.
 * PARAMETERS
 *  idx         [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_act_dev_hilite_hdlr(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 act_con_num;
    mmi_bt_connect_struct *conn_p = NULL;
    U32 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_bt_scr_cntx.hilight_item = idx;

    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_SCR_HIGHLIGHT_ITEM, idx);

    act_con_num = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_existed_dev_num) ();
    j = 0;
    /* get index of existed_conn */
    for (i = 0; i < act_con_num; i++)
    {
        conn_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_existed_conn_info) ((U16) i);
        if (conn_p->active == MMI_TRUE)
        {
            if (j == g_mmi_bt_scr_cntx.hilight_item)
            {
                break;
            }

            j++;
        }
    }


	if (conn_p != NULL)
	{
		if (conn_p->conn_type == MMI_BT_BPP_CONNECTION && conn_p->active == MMI_TRUE)
		{
            #if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_BPP_SUPPORT__)
	        SetLeftSoftkeyFunction(mmi_bt_bpp_foreground_print, KEY_EVENT_UP);
	        SetKeyHandler(mmi_bt_bpp_foreground_print, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            ChangeLeftSoftkey(STR_BT_BPP_FOREGROUND, IMG_GLOBAL_OK);
            #else
		    SetLeftSoftkeyFunction(mmi_bt_entry_act_dev_dis, KEY_EVENT_UP);
		    SetKeyHandler(mmi_bt_entry_act_dev_dis, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            ChangeLeftSoftkey(STR_BT_LSK_DISC, IMG_GLOBAL_OK);
            #endif
		}
		else if(conn_p->active == MMI_TRUE)
		{
		    SetLeftSoftkeyFunction(mmi_bt_entry_act_dev_dis, KEY_EVENT_UP);
		    SetKeyHandler(mmi_bt_entry_act_dev_dis, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            ChangeLeftSoftkey(STR_BT_LSK_DISC, IMG_GLOBAL_OK);
		}
        else
        {
            SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
            SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            ChangeLeftSoftkey(0, 0);
        }
	}
    else
    {
        SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
        SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        ChangeLeftSoftkey(0, 0);
    }
	

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_act_dev_dis
 * DESCRIPTION
 *  This function is to disconnect the all connections of the active device
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_act_dev_dis(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 act_con_num;
    U8 paired_dev_num;
    U8 paired_dev_index;
    mmi_bt_dev_struct *dev_p;
    mmi_bt_connect_struct *conn_p = NULL;
    U32 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_SCR_STATUS,
               g_mmi_bt_scr_cntx.state, g_mmi_bt_scr_cntx.flag, g_mmi_bt_scr_cntx.blinking_flag);
    
    /* to avoid the error operation while bt module is busy */
    if ((mmi_bt_is_permission) (MMI_TRUE) == MMI_FALSE)
    {
        return;
    }
    
    act_con_num = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_existed_dev_num) ();
    paired_dev_num = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_num) ();
    MMI_BT_ASSERT(paired_dev_num);
    j = 0;
    /* get index of existed_conn */
    for (i = 0; i < act_con_num; i++)
    {
        conn_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_existed_conn_info) ((U16) i);
        if (conn_p->active == MMI_TRUE)
        {
            if (j == g_mmi_bt_scr_cntx.hilight_item)
            {
                break;
            }

            j++;
        }
    }

    if (i == act_con_num || conn_p == NULL)
    {
        DisplayPopup(
            (U8*) GetString(STR_BT_CON_RELEASED),
            IMG_GLOBAL_ACTIVATED,
            MMI_FALSE,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) SUCCESS_TONE);
        return;
    }

    MMI_BT_ASSERT(i != act_con_num);
    MMI_BT_ASSERT(conn_p != NULL);

    paired_dev_index = conn_p->index_of_paried_list;
    MMI_BT_ASSERT(paired_dev_index < paired_dev_num);
    dev_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_info) (paired_dev_index);

    /* filter some unsupported-disconnecting profiles */
    if (mmi_bt_check_supported_connection_type((U32*) support_disconnecting_profile_tbl, (U32) conn_p->conn_type))
    {

        g_mmi_bt_scr_cntx.disconn_conn_type = (U32) conn_p->conn_type;

        if ((*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_disconnect_req) (conn_p->conn_id, conn_p->conn_type) == MMI_FALSE)
        {
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_ERROR),
                IMG_GLOBAL_ERROR,
                MMI_FALSE,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
        }
        else
        {
			g_mmi_bt_scr_cntx.disconnecting_conn_type = (U32) conn_p->conn_type;       
            mmi_bt_show_progress_scr(SCR_BT_DISC_PROC, STR_BT_DISCONNECT, STR_BT_DISCONNECTING, NULL, MMI_FALSE, NULL);
        }
    }
    else
    {
        DisplayPopup(
            (U8*) GetString(STR_BT_NOT_SUPPORT),
            IMG_GLOBAL_ERROR,
            MMI_FALSE,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_disconnect_complete
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  connection_type     [IN]            
 *  result              [IN]            
 *  a(?)                [IN/OUT]        First variable, used as returns
 *  b(?)                [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_disconnect_complete(U32 connection_type, MMI_BOOL result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *str_prof, *str_conn_res;
    U8 str_output[80], str_ucs2_space[4], str_asc_space[2];
    U16 act_scr = GetActiveScreenId();
    #if defined(__MMI_BT_MTK_SUPPORT__)
	U32 disconnecting_conn_type = g_mmi_bt_scr_cntx.disconnecting_conn_type;
	#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_SCR_PROF_CON_IND, connection_type);
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_SCR_PROF_DISCON_IND, connection_type, result, disconnecting_conn_type, act_scr);

    MMI_BT_ASSERT((connection_type < MMI_BT_LAST_CONNECTOIN_TYPE));

    /* update BT Status Icon */
    mmi_bt_update_status_icon();
    /* reset extend proc timer */
    g_mmi_bt_scr_cntx.extend_proc_timer = 0;

    if (act_scr == SCR_BT_DISC_PROC)
    {
        if (connection_type == g_mmi_bt_scr_cntx.disconn_conn_type ||
            connection_type == MMI_BT_NO_CONNECTION || result == MMI_FALSE)
        {
	        g_mmi_bt_scr_cntx.disconnecting_conn_type = 0;
            mmi_bt_stop_progress_scr(MMI_FALSE);
        }
    }
    else if (act_scr == SCR_BT_ACT_DEV)
    {
        mmi_bt_update_act_dev_screen();
    }
    else if (act_scr == SCR_BT_MYDEV_CONNECTED_PROF)
    {
        mmi_bt_update_mydev_connected_prof_screen();
    }
    else if (act_scr == SCR_BT_MYDEV_OPT)
    {
        mmi_bt_update_mydev_opt();
    }

    /* to filter out OPP and FTP */
	/* BIP */
    /* OPP and FTP donot expect to see BT CM's disconnected popup screen */
    if ((connection_type == MMI_BT_OPP_CONNECTION || 
		 connection_type == MMI_BT_FTP_CONNECTION || 
		 connection_type == MMI_BT_BPP_CONNECTION ||
		 connection_type == MMI_BT_HID_CONNECTION ||
		 connection_type == MMI_BT_BIP_CONNECTION)
        && (act_scr != SCR_BT_DISC_PROC))
    {
        if (connection_type == g_mmi_bt_scr_cntx.disconn_conn_type ||
            connection_type == MMI_BT_NO_CONNECTION || result == MMI_FALSE)
        {
	        g_mmi_bt_scr_cntx.disconnecting_conn_type = 0;
            DeleteScreenIfPresent(SCR_BT_DISC_PROC);
        }
        return;
    }

    switch (connection_type)
    {
        case MMI_BT_HSP_CONNECTION:
            str_prof = (U8*) GetString(STR_BT_PROF_HS);
            break;

        case MMI_BT_HFP_CONNECTION:
            str_prof = (U8*) GetString(STR_BT_PROF_HF);
            break;

        case MMI_BT_DUN_CONNECTION:
            str_prof = (U8*) GetString(STR_BT_PROF_DUN);
            break;

        case MMI_BT_SPP_CONNECTION:
            str_prof = (U8*) GetString(STR_BT_PROF_SPP);
            break;

        case MMI_BT_FTP_CONNECTION:
            str_prof = (U8*) GetString(STR_BT_PROF_FTP);
            break;

        case MMI_BT_OPP_CONNECTION:
            str_prof = (U8*) GetString(STR_BT_PROF_OPP);
            break;

        case MMI_BT_A2DP_CONNECTION:
            str_prof = (U8*) GetString(STR_BT_PROF_A2DP);
            break;
        case MMI_BT_AVRCP_CONNECTION:
            str_prof = (U8*) GetString(STR_BT_PROF_AVRCP_T);
            break;
        case MMI_BT_AVRCP_CT_CONNECTION:
            str_prof = (U8*) GetString(STR_BT_PROF_AVRCP);
            break;

        case MMI_BT_BPP_CONNECTION:
            str_prof = (U8*) GetString(STR_BT_PROF_BASIC_PRINTING);
            break;

        case MMI_BT_SIMAP_CONNECTION:
            str_prof = (U8*) GetString(STR_BT_PROF_SAP);
            break;

        case MMI_BT_FAX_CONNECTION:
            str_prof = (U8*) GetString(STR_BT_PROF_FAX);
            break; 

        case MMI_BT_HID_CONNECTION:
            str_prof = (U8*) GetString(STR_BT_PROF_HID);
            break; 

        case MMI_BT_BIP_CONNECTION:
            str_prof = (U8*) GetString(STR_BT_PROF_OBEX_IMAGING);
            break; 

        default:
            str_prof = (U8*) GetString(STR_BT_DISCONNECTING);
            MMI_BT_ASSERT(0);
            break;
    }

    if (result == MMI_TRUE)
    {
        str_conn_res = (U8*) GetString(STR_BT_DISCON_ED);
    }
    else
    {
        str_prof = (U8*) GetString(STR_BT_DISCONNECT);
        str_conn_res = (U8*) GetString(STR_BT_FAILED);
    }

    memset(str_output, 0, sizeof(U8) * 80);
    memset(str_asc_space, 0, sizeof(U8) * 2);
    memset(str_ucs2_space, 0, sizeof(U8) * 4);
    kal_sprintf((S8*) str_asc_space, " ");
    mmi_asc_to_ucs2((S8*) str_ucs2_space, (S8*) str_asc_space);

    mmi_ucs2cpy((S8*) str_output, (const S8*)str_prof);
    /* space is reserved in ref_list.txt for alphabetical languages */ 
    /* for Chinese language, space is not required */
    //mmi_ucs2cat((S8*) str_output, (const S8*)str_ucs2_space);
    /* check if str_prof string length + 2 + str_conn_res string length >= str_output */
    MMI_BT_ASSERT(((mmi_ucs2strlen((const S8*)str_prof) * ENCODING_LENGTH) + 2 +
                   (mmi_ucs2strlen((const S8*)str_conn_res) * ENCODING_LENGTH)) < (sizeof(U8) * 80));
    mmi_ucs2cat((S8*) str_output, (const S8*)str_conn_res);

	 #if defined(__MMI_BT_MTK_SUPPORT__)
	 if (!((connection_type == MMI_BT_A2DP_CONNECTION && (disconnecting_conn_type != MMI_BT_A2DP_CONNECTION)) ||
	       (connection_type == MMI_BT_AVRCP_CONNECTION && (disconnecting_conn_type != MMI_BT_AVRCP_CONNECTION))
	      ) 
	    )
	 #endif
	 {
	    if (result == MMI_TRUE)
	    {
	        DisplayPopup(str_output, IMG_GLOBAL_ACTIVATED, MMI_FALSE, UI_POPUP_NOTIFYDURATION_TIME, (U8) SUCCESS_TONE);
            #if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_HIDD_SUPPORT__)
			if (connection_type == MMI_BT_HID_CONNECTION)
			{
				SetDelScrnIDCallbackHandler(SCR_BT_REMOTE_CONTROL_DEV_SELECT, (HistoryDelCBPtr) NULL);
			    DeleteScreenIfPresent(SCR_BT_DISC_PROC);
				mmi_bt_del_scr(SCR_BT_REMOTE_CONTROL, SCR_BT_REMOTE_CONTROL_DISCONNECT_CONFIRM);
			}
			#endif    

	    }
	    else
	    {
	        DisplayPopup(str_output, IMG_GLOBAL_WARNING, MMI_FALSE, UI_POPUP_NOTIFYDURATION_TIME, (U8) WARNING_TONE);
	    }
	 }

    if (connection_type == g_mmi_bt_scr_cntx.disconn_conn_type ||
        connection_type == MMI_BT_NO_CONNECTION || result == MMI_FALSE)
    {
        g_mmi_bt_scr_cntx.disconnecting_conn_type = 0;
        DeleteScreenIfPresent(SCR_BT_DISC_PROC);
    }

    if (connection_type == MMI_BT_HSP_CONNECTION || connection_type == MMI_BT_HFP_CONNECTION)
    {
        DeleteScreenIfPresent(SCR_BT_CONNECT_AUTHORIZE);
        DeleteScreenIfPresent(SCR_BT_SWITCH_SPEECH_PATH);
        /* reset MMI_BT_CONFIRM_SPEECH_SWITCH flag */
        g_mmi_bt_scr_cntx.flag &= ~MMI_BT_CONFIRM_SPEECH_SWITCH;

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_set_menu
 * DESCRIPTION
 *  This function is to activate or deactivate bt function
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_set_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];    /* Stores the strings id of submenus returned */
    U16 nNumofItem;                     /* Stores no of children in the submenu */
    U16 nDispAttribute;                 /* Stores display attribue */
    U8 *guiBuffer;                      /* Buffer holding history data */
    U8 *HintList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* to avoid the twice operation while bt is just on and wanna enter setting menu */
    if (g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_SET)
    {
        g_mmi_bt_scr_cntx.flag &= ~MMI_BT_CONFIRM_SET;    
        StopTimer(BT_POPUP_TIMER);
    }

    if ((mmi_bt_is_hw_ready) (MMI_TRUE) == MMI_FALSE)
    {
        return;
    }


    if ((*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_pwron) () == MMI_FALSE)
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
        #endif
        mmi_bt_display_power_on_confirm(MMI_BT_CONFIRM_SET);
        return;
    }

    /* 1 Call Exit Handler */
    EntryNewScreen(SCR_BT_SET, NULL, mmi_bt_entry_set_menu, NULL);

    /* 2 Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_BT_SET);

    /* 3. Retrieve no of child of menu item to be displayed */
    nNumofItem = GetNumOfChild_Ext(MENU_CONN_BT_SET);

    /* 4. Get attribute of menu to be displayed */
    nDispAttribute = GetDispAttributeOfItem(MENU_CONN_BT_SET);

    /* 5. Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds_Ext(MENU_CONN_BT_SET, nStrItemList);

    /* 6 Set current parent id */
    SetParentHandler(MENU_CONN_BT_SET);

    /* 7 Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* 8 Construct the Hints List */
    ConstructHintsList(MENU_CONN_BT_SET, HintList);

    /* 9. Display Category screen */
    ShowCategory52Screen(
        STR_BT_DEV_SET,
        //MAIN_MENU_TITLE_EXTRA_APP_ICON,
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (PU16) gIndexIconsImageList,
        HintList,
        0,
        0,
        guiBuffer);

}

/*****************************************************************************
* FUNCTION
*  mmi_bt_exit_set_menu
* DESCRIPTION
*  This function is to activate or deactivate bt function
*
* PARAMETERS
*  a  IN/OUT   first variable, used as returns
*  b  IN       second variable
* RETURNS
*  NONE.  
* GLOBALS AFFECTED
*  external_global
*****************************************************************************/
void mmi_bt_exit_set_menu(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_set_menu_confirm_rsk_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_set_menu_confirm_rsk_hdler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reset scr flag */
    //mmi_bt_reset_scr_flag();
    g_mmi_bt_scr_cntx.flag &= ~MMI_BT_CONFIRM_SET;
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_set_vis
 * DESCRIPTION
 *  This function is to activate or deactivate bt function
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_set_vis(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* to avoid the error operation while bt module is busy */
    if ((mmi_bt_is_permission) (MMI_TRUE) == MMI_FALSE)
    {
        return;
    }

    /* it is allowed end user to configure the visibility while SAP is activated */
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif

    /* prohibit visibility setting while a2dp is active */
    if (mmi_bt_is_a2dp_connected())
    {
        DisplayPopup(
            (U8*) GetString(STR_BT_PROHIBIT_VIS_BY_A2DP),
            IMG_GLOBAL_ERROR,
            MMI_FALSE,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
        return;
    }

    

    if ((*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_ram_flag) (MMI_BT_RAMMASK_REACH_MAX_ACL_LINK))
    {
        DisplayPopup(
            (U8*) GetString(STR_BT_PROHIBIT_VIS_BY_MAX_ACL),
            IMG_GLOBAL_ERROR,
            MMI_FALSE,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
        return;
    }


    if ((*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_vis) () == MMI_TRUE)
    {
        (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_set_vis_req) (MMI_FALSE);
    }
    else
    {
        (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_set_vis_req) (MMI_TRUE);
    }

    mmi_bt_show_progress_scr(SCR_BT_SET_VIS, STR_BT_DEV_SET_VIS, STR_BT_DEV_SET, NULL, MMI_FALSE, NULL);

}

/*****************************************************************************
* FUNCTION
*  mmi_bt_exit_set_vis
* DESCRIPTION
*  This is UI screen function for setting vis completely 
*
* PARAMETERS
*  a  IN/OUT   first variable, used as returns
*  b  IN       second variable
* RETURNS
*  NONE.  
* GLOBALS AFFECTED
*  external_global
*****************************************************************************/
void mmi_bt_exit_set_vis(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_set_vis_complete
 * DESCRIPTION
 *  This is UI screen function for setting vis completely
 * PARAMETERS
 *  result      [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_set_vis_complete(MMI_BOOL result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bt_stop_progress_scr(MMI_FALSE);

    if (result == MMI_TRUE)
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_DONE),
            IMG_GLOBAL_ACTIVATED,
            MMI_FALSE,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) SUCCESS_TONE);
    }
    else
    {
    #ifdef __MMI_BT_MTK_SUPPORT__
        DisplayPopup(
            (U8*) GetString(STR_BT_NOT_ALLOW),
            IMG_GLOBAL_ERROR,
            MMI_FALSE,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
	#else
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_ERROR),
            IMG_GLOBAL_ERROR,
            MMI_FALSE,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
	#endif
    }

    /* update status icon */
    mmi_bt_update_status_icon();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_set_auth
 * DESCRIPTION
 *  This function is to activate or deactivate bt function
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_set_auth(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* to avoid the error operation while bt module is busy */
    if ((mmi_bt_is_permission) (MMI_TRUE) == MMI_FALSE)
    {
        return;
    }

    /* prohibited by simap, shall deactivate simap first */
    if (mmi_bt_is_simap_server_activate())
    {
        mmi_bt_popup_prohibited_by_simap();
        return;
    }



    if ((*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_auth) () == MMI_TRUE)
    {
        (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_set_auth_req) (MMI_FALSE);
    }
    else
    {
        (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_set_auth_req) (MMI_TRUE);
    }

    mmi_bt_show_progress_scr(SCR_BT_SET_AUTH, STR_BT_DEV_SET_AUTH, STR_BT_DEV_SET, NULL, MMI_FALSE, NULL);
}

/*****************************************************************************
* FUNCTION
*  mmi_bt_exit_set_auth
* DESCRIPTION
*  This function is to activate or deactivate bt function
*
* PARAMETERS
*  a  IN/OUT   first variable, used as returns
*  b  IN       second variable
* RETURNS
*  NONE.  
* GLOBALS AFFECTED
*  external_global
*****************************************************************************/
void mmi_bt_exit_set_auth(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_set_auth_complete
 * DESCRIPTION
 *  This function is to activate or deactivate bt function
 * PARAMETERS
 *  result      [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_set_auth_complete(MMI_BOOL result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bt_stop_progress_scr(MMI_FALSE);

    if (result == MMI_TRUE)
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_DONE),
            IMG_GLOBAL_ACTIVATED,
            MMI_FALSE,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) SUCCESS_TONE);
    }
    else
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_ERROR),
            IMG_GLOBAL_ERROR,
            MMI_FALSE,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
    }

    DeleteScreenIfPresent(SCR_BT_SET_AUTH);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_set_name
 * DESCRIPTION
 *  This function is to activate or deactivate bt function
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_set_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    mmi_bt_dev_struct *dev_p;
    U8 utf8_char_cnt = 0;
    U8 ucs2_str_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* to avoid the error operation while bt module is busy */
    if ((mmi_bt_is_permission) (MMI_TRUE) == MMI_FALSE)
    {
        return;
    }

    EntryNewScreen(SCR_BT_SET_NAME, NULL, mmi_bt_entry_set_name, NULL);

    dev_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_host_dev_info) ();
    if ((gui_buffer = GetCurrGuiBuffer(SCR_BT_SET_NAME)) == NULL)
    {
        /* get byte count for convert utf8 string to UCS2 string */
        /* get character count of utf8 string */
        /* +1 is for UCS2 NULL terminate */
        /* *ENCODING_LENGTH is for byte count of one UCS2 character */
        utf8_char_cnt = (U8) ((mmi_chset_utf8_strlen((kal_uint8*) dev_p->name) + 1) * ENCODING_LENGTH);
        MMI_BT_ASSERT(MMI_BT_SCR_BUF_SIZE >= (MMI_BT_SCR_BD_NAME_LEN));
        if (utf8_char_cnt > MMI_BT_SCR_BD_NAME_LEN)
        {
            ucs2_str_len =
                (U8) mmi_chset_utf8_to_ucs2_string(
                        (kal_uint8*) (g_mmi_bt_scr_cntx.scr_buf),
                        MMI_BT_SCR_BD_NAME_LEN,
                        (kal_uint8*) dev_p->name);
        }
        else
        {
            ucs2_str_len =
                (U8) mmi_chset_utf8_to_ucs2_string(
                        (kal_uint8*) (g_mmi_bt_scr_cntx.scr_buf),
                        utf8_char_cnt,
                        (kal_uint8*) dev_p->name);
        }
		/* allow (MMI_BT_BD_NAME_LEN/3) chinese characters or (MMI_BT_BD_NAME_LEN/3)*2 english characters  */
		/* so for UCS2 encoding, need MMI_BT_SCR_BD_NAME_LEN bytes */

		/* shall check if there is any two_byte character mixed in one_bye UCS2 string */
		/* if yes, then truncate the string to meet above rules((MMI_BT_BD_NAME_LEN/3) chinese characters or (MMI_BT_BD_NAME_LEN/3)*2 english characters)*/	
		if(mmi_bt_test_ucs2((U16*)g_mmi_bt_scr_cntx.scr_buf, (U16)(ucs2_str_len/ENCODING_LENGTH)) )
		{ 
			mmi_bt_truncate_ucs2_string((U16*)g_mmi_bt_scr_cntx.scr_buf, 
			    							(U16)(ucs2_str_len/ENCODING_LENGTH),
			    							(U16)((MMI_BT_BD_NAME_LEN-2)/3)
			    						   );		    
		}
        

    }

    ShowCategory5Screen_ext(
        STR_BT_DEV_SET_NAME,
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        STR_GLOBAL_OPTIONS,
        0,
        STR_GLOBAL_BACK,
        0,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ENCODING_BASED_LENGTH,
        (U8*) (g_mmi_bt_scr_cntx.scr_buf),
        (MMI_BT_SCR_BD_NAME_LEN / ENCODING_LENGTH),
        gui_buffer,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
        NULL,
        NULL);

    SetLeftSoftkeyFunction(mmi_bt_set_name_opt, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    RegisterInputMethodScreenCloseFunction(mmi_bt_goback_2_history);
    return;
}

/*****************************************************************************
* FUNCTION
*  mmi_bt_exit_set_name
* DESCRIPTION
*  This function is to activate or deactivate bt function
*
* PARAMETERS
*  a  IN/OUT   first variable, used as returns
*  b  IN       second variable
* RETURNS
*  NONE.  
* GLOBALS AFFECTED
*  external_global
*****************************************************************************/
void mmi_bt_exit_set_name(void);

/*****************************************************************************
* FUNCTION
*  mmi_bt_goback_2_history
* DESCRIPTION
*  This function is to goback 2 history
*
* PARAMETERS
* RETURNS
*  NONE.  
* GLOBALS AFFECTED
*  external_global
*****************************************************************************/
void mmi_bt_goback_2_history(void)
{
    GoBacknHistory(1);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_set_name_opt
 * DESCRIPTION
 *  This function is to activate or deactivate bt function
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_set_name_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 item_texts[] = {STR_GLOBAL_DONE, STR_GLOBAL_INPUT_METHOD};
    U16 item_icons[] = {IMG_GLOBAL_L1, IMG_GLOBAL_L2};
    U8 *guiBuffer;                      /* Buffer holding history data */
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_BT_SET_NAME_OPT, NULL, mmi_bt_set_name_opt, NULL);

    /* Get current screen to gui buffer for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_BT_SET_NAME_OPT);

    RegisterHighlightHandler(mmi_bt_set_name_opt_hilite_hdlr);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        2,
        item_texts,
        item_icons,
        NULL,
        0,
        0,
        guiBuffer);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_set_name_opt_hilite_hdlr
 * DESCRIPTION
 *  This function is hilight handler for Extra->Bluetooth->Setting->set name->Opt
 * PARAMETERS
 *  idx         [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_set_name_opt_hilite_hdlr(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BT_ASSERT((idx >= 0) && (idx < MMI_BT_DEVNAME_EDOPT_LAST));

    switch (idx)
    {
        case MMI_BT_DEVNAME_EDOPT_DONE:
            SetLeftSoftkeyFunction(mmi_bt_set_name_proc, KEY_EVENT_UP);
            SetKeyHandler(mmi_bt_set_name_proc, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            break;
        case MMI_BT_DEVNAME_EDOPT_INPMETHOD:
            SetLeftSoftkeyFunction(EntryInputMethodScreen, KEY_EVENT_UP);
            SetKeyHandler(EntryInputMethodScreen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            break;

        default:
            break;
    }

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_set_name_proc
 * DESCRIPTION
 *  This function is hilight handler for Extra->Bluetooth->Setting->set name->Opt
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_set_name_proc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 name_convert[MMI_BT_BD_NAME_LEN];
    S32 ucs2_byte_count;
    MMI_BOOL test_ucs2_char = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ucs2_byte_count = (mmi_ucs2strlen((const S8*)g_mmi_bt_scr_cntx.scr_buf) * ENCODING_LENGTH) + ENCODING_LENGTH;

    
    if (ucs2_byte_count == ENCODING_LENGTH)
    {
        DisplayPopup(
            (U8*) GetString(STR_BT_SET_NAME_LENGTH_LIMITATION),
            IMG_GLOBAL_ERROR,
            MMI_FALSE,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
        DeleteScreenIfPresent(SCR_BT_SET_NAME);
        DeleteScreenIfPresent(SCR_BT_SET_NAME_OPT);
        
    }
    else
    {
    
        if ((ucs2_byte_count-ENCODING_LENGTH)/ENCODING_LENGTH > (MMI_BT_BD_NAME_LEN-2)/3)
        {

            test_ucs2_char = mmi_bt_test_ucs2((U16*)g_mmi_bt_scr_cntx.scr_buf, (U16)(ucs2_byte_count/ENCODING_LENGTH));
            /* allow (MMI_BT_BD_NAME_LEN/3) chinese characters or (MMI_BT_BD_NAME_LEN/3)*2 english characters  */
            /* so for UCS2 encoding, need MMI_BT_SCR_BD_NAME_LEN bytes */
            /* shall check if there is any two_byte character mixed in one_bye UCS2 string */
            /* if yes, then truncate the string to meet above rules((MMI_BT_BD_NAME_LEN/3) chinese characters or (MMI_BT_BD_NAME_LEN/3)*2 english characters)*/ 
    		if(test_ucs2_char)
    		{ 
    			mmi_bt_truncate_ucs2_string((U16*)g_mmi_bt_scr_cntx.scr_buf, 
    			    							(U16)(ucs2_byte_count/ENCODING_LENGTH),
    			    							(U16)((MMI_BT_BD_NAME_LEN-2)/3)
    			    						   );		   
                g_mmi_bt_scr_cntx.flag_extended |= MMI_BT_EXT_TRUNCATE_NAME_STRING;

                
    		}
        }
        
        /* convert ucs2 string to utf8 string */
        mmi_chset_ucs2_to_utf8_string(
            (kal_uint8*) name_convert,
            MMI_BT_BD_NAME_LEN,
            (kal_uint8*) (g_mmi_bt_scr_cntx.scr_buf));

        MMI_BT_ASSERT(MMI_BT_SCR_BUF_SIZE >= MMI_BT_BD_NAME_LEN);
        memcpy(g_mmi_bt_scr_cntx.scr_buf, name_convert, MMI_BT_BD_NAME_LEN);

		/* To disable all key handlers or touch panel handlers */
		/* to avoid end user to do other key/touch panel operation */
		/* before getting set-name response */
		ClearInputEventHandler(MMI_DEVICE_ALL);

        (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_set_name_req) ((U8*) g_mmi_bt_scr_cntx.scr_buf);
		/* Donot show set-name progresssing screen */
		/* because the response is back right away */
        //mmi_bt_show_progress_scr(SCR_BT_SET_NAME, STR_BT_DEV_SET_NAME, STR_BT_DEV_SET_NAME, NULL, MMI_FALSE, NULL);

        DeleteScreenIfPresent(SCR_BT_SET_NAME_OPT);
        DeleteScreenIfPresent(SCR_BT_SET_NAME);

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_set_name_proc_complete
 * DESCRIPTION
 *  This function is to activate or deactivate bt function
 * PARAMETERS
 *  result      [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_set_name_proc_complete(MMI_BOOL result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/* Donot show set-name progresssing screen */
	/* because the response is back right away. */
	/* It is not required to stop progressing screen here */
	//mmi_bt_stop_progress_scr(MMI_FALSE);

    if (result == MMI_TRUE)
    {
        if (g_mmi_bt_scr_cntx.flag_extended & MMI_BT_EXT_TRUNCATE_NAME_STRING)
        {
            DisplayPopup(
                (U8*) GetString(STR_BT_TRUNCATE_NAME_FOR_DIFF_CHAR_SET),
                IMG_GLOBAL_WARNING,
                MMI_FALSE,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) WARNING_TONE);
        }
        else
        {
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_DONE),
                IMG_GLOBAL_ACTIVATED,
                MMI_FALSE,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) SUCCESS_TONE);
        }

    }
    else
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_ERROR),
            IMG_GLOBAL_ERROR,
            MMI_FALSE,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
    }

    g_mmi_bt_scr_cntx.flag_extended &= ~MMI_BT_EXT_TRUNCATE_NAME_STRING;


    DeleteScreenIfPresent(SCR_BT_SET_NAME_OPT);
    DeleteScreenIfPresent(SCR_BT_SET_NAME);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_set_audio_pth_menu
 * DESCRIPTION
 *  This function is to Entry function for Extra->Bluetooth->Setting->Path
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_set_audio_pth_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];    /* Stores the strings id of submenus returned */
    U16 nNumofItem;                     /* Stores no of children in the submenu */
    U16 nDispAttribute;                 /* Stores display attribue */
    U8 *guiBuffer;                      /* Buffer holding history data */
    U8 *HintList[MAX_SUB_MENUS];
    U16 highlight_item = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1 Call Exit Handler */
    EntryNewScreen(SCR_BT_SET_AUDIO_PATH, NULL, mmi_bt_entry_set_audio_pth_menu, NULL);

    /* 2 Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_BT_SET_AUDIO_PATH);

    /* 3. Retrieve no of child of menu item to be displayed */
    nNumofItem = GetNumOfChild(MENU_CONN_BT_SET_AUDIO_PATH);

    /* 4. Get attribute of menu to be displayed */
    nDispAttribute = GetDispAttributeOfItem(MENU_CONN_BT_SET_AUDIO_PATH);

    /* 5. Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds(MENU_CONN_BT_SET_AUDIO_PATH, nStrItemList);

    /* 6 Set current parent id */
    SetParentHandler(MENU_CONN_BT_SET_AUDIO_PATH);

    /* 7 Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* 8 Construct the Hints List */
    ConstructHintsList(MENU_CONN_BT_SET_AUDIO_PATH, HintList);

    /* Get Audio path setting */
    if ((*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_aud_pth_set_to_hf) () == MMI_TRUE)
    {
        highlight_item = 1;
    }

    /* 9. Display Category screen */
    ShowCategory11Screen(
        STR_BT_DEV_SET_AUDIO_PATH,
        MAIN_MENU_TITLE_EXTRA_APP_ICON,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        highlight_item,
        guiBuffer);

    /* 10.Register function with softkey */
    SetLeftSoftkeyFunction(mmi_bt_set_audio_pth_proc, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}

/*****************************************************************************
* FUNCTION
*  mmi_bt_exit_set_audio_pth_menu
* DESCRIPTION
*   This function is to Entry function for Extra->Bluetooth->Setting->Path
*
* PARAMETERS
*  a  IN/OUT      first variable, used as returns
*  b  IN       second variable
* RETURNS
*  NONE.
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/
void mmi_bt_exit_set_audio_pth_menu(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_set_audio_pth_proc
 * DESCRIPTION
 *  This function is to Entry function for Extra->Bluetooth->Setting->Path
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_set_audio_pth_proc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_mmi_bt_scr_cntx.hilight_item) == 0)
    {
        (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_set_aud_pth_2_hf) (MMI_FALSE);
    }
    else
    {
        (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_set_aud_pth_2_hf) (MMI_TRUE);
    }

    DisplayPopup(
        (U8*) GetString(STR_GLOBAL_DONE),
        IMG_GLOBAL_ACTIVATED,
        MMI_FALSE,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) SUCCESS_TONE);
    DeleteScreenIfPresent(SCR_BT_SET_AUDIO_PATH);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_set_simap
 * DESCRIPTION
 *  This function is to activate or deactivate simap
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_set_simap(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* to avoid the twice operation*/
    if (g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_SIMAP_SET)
    {
        g_mmi_bt_scr_cntx.flag &= ~MMI_BT_CONFIRM_SIMAP_SET;    
        StopTimer(BT_POPUP_TIMER);
    }

    
    /* to avoid the error operation while bt module is busy */
    if ((mmi_bt_is_permission) (MMI_TRUE) == MMI_FALSE)
    {
        return;
    }

    if ((*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_any_connection_active) ())
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
        #endif 
        mmi_bt_display_release_all_connection_confirm(MMI_BT_CONFIRM_SIMAP_SET);
        return;
    }

    if ((*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_simap_activate) () == MMI_TRUE)
    {
        (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_set_simap_req) (MMI_FALSE);
        mmi_bt_show_progress_scr(SCR_BT_SET_SIMAP, STR_BT_DEV_SET_SIMAP, STR_BT_DEACTIVATING, NULL, MMI_FALSE, NULL);

    }
    else
    {
        (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_set_simap_req) (MMI_TRUE);
        mmi_bt_show_progress_scr(SCR_BT_SET_SIMAP, STR_BT_DEV_SET_SIMAP, STR_BT_ACTIVATING, NULL, MMI_FALSE, NULL);
    }

}

/*****************************************************************************
* FUNCTION
*  mmi_bt_exit_set_simap
* DESCRIPTION
*  This function is to activate or deactivate simap
*
* PARAMETERS
*  a  IN/OUT   first variable, used as returns
*  b  IN       second variable
* RETURNS
*  NONE.  
* GLOBALS AFFECTED
*  external_global
*****************************************************************************/
void mmi_bt_exit_set_simap(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_set_simap_confirm_rsk_hdler
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_set_simap_confirm_rsk_hdler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_bt_scr_cntx.flag &= ~MMI_BT_CONFIRM_SIMAP_SET;        
    GoBackHistory();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_set_simap_complete
 * DESCRIPTION
 *  This function is to notify if setting simap successfully or not
 * PARAMETERS
 *  result      [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_set_simap_complete(MMI_BOOL result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bt_stop_progress_scr(MMI_FALSE);

    if (result == MMI_TRUE)
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_DONE),
            IMG_GLOBAL_ACTIVATED,
            MMI_FALSE,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) SUCCESS_TONE);
    }
    else
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_ERROR),
            IMG_GLOBAL_ERROR,
            MMI_FALSE,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
    }

    DeleteScreenIfPresent(SCR_BT_SET_SIMAP);
}


/* Configure Default Headset */
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_is_default_hs_existed
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bt_is_default_hs_existed(void)
{	
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 default_hs_index;
    MMI_BOOL result = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_default_hs_index)
    {
		default_hs_index = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_default_hs_index)();
		if (default_hs_index < (U32)(*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_num)())
	    {
			result = MMI_TRUE;
	    }
    }

	return result;	
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_about
 * DESCRIPTION
 *  This function is to Entry function for Extra->Bluetooth->Setting->Path
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_about(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 ascii_buf[5];
    U8 usc2_buf[10];
    S32 ui_buffer_size;
    U32 i;
    U8 *str_p;
    mmi_bt_dev_struct *dev_p;
    U8 utf8_char_cnt = 0;
    U8 ucs2_str_len = 0;
    U8 *guiBuffer;                      /* Buffer holding history data */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_BT_ABOUT, NULL, mmi_bt_entry_about, NULL);

    dev_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_host_dev_info) ();
    memset(g_mmi_bt_scr_cntx.ui_buf, 0, MMI_BT_UI_BUF_SIZE);
    memset(ascii_buf, 0, 5);
    memset(usc2_buf, 0, 10);
    kal_sprintf((S8*) ascii_buf, "\n");
    mmi_asc_to_ucs2((S8*) usc2_buf, (S8*) ascii_buf);

    /* Name */

    MMI_BT_ASSERT((mmi_ucs2strlen((const S8*)GetString(STR_BT_BD_NAME)) * ENCODING_LENGTH) <=
                  (MMI_BT_SCR_BUF_SIZE - ENCODING_LENGTH));

    memset(g_mmi_bt_scr_cntx.scr_buf, 0, MMI_BT_SCR_BUF_SIZE);
    mmi_ucs2cpy((S8*) g_mmi_bt_scr_cntx.scr_buf, (const S8*)GetString(STR_BT_BD_NAME));

    mmi_ucs2cpy((S8*) g_mmi_bt_scr_cntx.ui_buf, (const S8*)g_mmi_bt_scr_cntx.scr_buf);
    mmi_ucs2cat((S8*) g_mmi_bt_scr_cntx.ui_buf, (const S8*)usc2_buf);

    /* get byte count for convert utf8 string to UCS2 string */
    /* get character count of utf8 string */
    /* +1 is for UCS2 NULL terminate */
    /* *ENCODING_LENGTH is for byte count of one UCS2 character */
    utf8_char_cnt = (U8) ((mmi_chset_utf8_strlen((kal_uint8*) dev_p->name) + 1) * ENCODING_LENGTH);
    MMI_BT_ASSERT(MMI_BT_SCR_BUF_SIZE >= (MMI_BT_SCR_BD_NAME_LEN));
    if (utf8_char_cnt > MMI_BT_SCR_BD_NAME_LEN)
    {
        ucs2_str_len =
            (U8) mmi_chset_utf8_to_ucs2_string(
                    (kal_uint8*) (g_mmi_bt_scr_cntx.scr_buf),
                    MMI_BT_SCR_BD_NAME_LEN,
                    (kal_uint8*) dev_p->name);
    }
    else
    {
        ucs2_str_len =
            (U8) mmi_chset_utf8_to_ucs2_string(
                    (kal_uint8*) (g_mmi_bt_scr_cntx.scr_buf),
                    utf8_char_cnt,
                    (kal_uint8*) dev_p->name);
    }
	/* allow (MMI_BT_BD_NAME_LEN/3) chinese characters or (MMI_BT_BD_NAME_LEN/3)*2 english characters  */
	/* so for UCS2 encoding, need MMI_BT_SCR_BD_NAME_LEN bytes */

	/* shall check if there is any two_byte character mixed in one_bye UCS2 string */
	/* if yes, then truncate the string to meet above rules((MMI_BT_BD_NAME_LEN/3) chinese characters or (MMI_BT_BD_NAME_LEN/3)*2 english characters)*/	
	if(mmi_bt_test_ucs2((U16*)g_mmi_bt_scr_cntx.scr_buf, (U16)(ucs2_str_len/ENCODING_LENGTH)) )
	{ 
		mmi_bt_truncate_ucs2_string((U16*)g_mmi_bt_scr_cntx.scr_buf, 
		    							(U16)(ucs2_str_len/ENCODING_LENGTH),
		    							(U16)((MMI_BT_BD_NAME_LEN-2)/3)
		    						   );		    
	}
        

    
    mmi_ucs2cat((S8*) g_mmi_bt_scr_cntx.ui_buf, (const S8*)g_mmi_bt_scr_cntx.scr_buf);
    mmi_ucs2cat((S8*) g_mmi_bt_scr_cntx.ui_buf, (const S8*)usc2_buf);

    /* BD Address */
    MMI_BT_ASSERT((mmi_ucs2strlen((const S8*)GetString(STR_BT_BD_ADDR)) * ENCODING_LENGTH) <=
                  (MMI_BT_SCR_BUF_SIZE - ENCODING_LENGTH));

    memset(g_mmi_bt_scr_cntx.scr_buf, 0, MMI_BT_SCR_BUF_SIZE);
    mmi_ucs2cpy((S8*) g_mmi_bt_scr_cntx.scr_buf, (const S8*)GetString(STR_BT_BD_ADDR));

    mmi_ucs2cat((S8*) g_mmi_bt_scr_cntx.ui_buf, (const S8*)g_mmi_bt_scr_cntx.scr_buf);
    mmi_ucs2cat((S8*) g_mmi_bt_scr_cntx.ui_buf, (const S8*)usc2_buf);

    /* BT address: NAP, UAP, LAP */
    memset(g_mmi_bt_scr_cntx.scr_buf, 0, MMI_BT_SCR_BUF_SIZE);
    kal_wsprintf(
        (U16*) g_mmi_bt_scr_cntx.scr_buf,
        "%02x:%02x:%02x:%02x:%02x:%02x",
        ((dev_p->bd_addr.nap & 0xff00) >> 8),
        (dev_p->bd_addr.nap & 0x00ff),
        (dev_p->bd_addr.uap),
        ((dev_p->bd_addr.lap & 0xff0000) >> 16),
        ((dev_p->bd_addr.lap & 0x00ff00) >> 8),
        (dev_p->bd_addr.lap & 0x0000ff));

    mmi_ucs2cat((S8*) g_mmi_bt_scr_cntx.ui_buf, (const S8*)g_mmi_bt_scr_cntx.scr_buf);
    mmi_ucs2cat((S8*) g_mmi_bt_scr_cntx.ui_buf, (const S8*)usc2_buf);

    /* Profiles */
    MMI_BT_ASSERT((mmi_ucs2strlen((const S8*)GetString(STR_BT_SERVICE)) * ENCODING_LENGTH) <=
                  (MMI_BT_SCR_BUF_SIZE - ENCODING_LENGTH));
    /* memcpy(g_mmi_bt_scr_cntx.scr_buf, GetString(STR_BT_SERVICE), (mmi_ucs2strlen((const S8 *)GetString(STR_BT_SERVICE))*ENCODING_LENGTH)); */
    mmi_ucs2cpy((S8*) g_mmi_bt_scr_cntx.scr_buf, (const S8*)GetString(STR_BT_SERVICE));

    mmi_ucs2cat((S8*) g_mmi_bt_scr_cntx.ui_buf, (const S8*)g_mmi_bt_scr_cntx.scr_buf);
    mmi_ucs2cat((S8*) g_mmi_bt_scr_cntx.ui_buf, (const S8*)usc2_buf);

    for (i = 0; i < dev_p->service_list_num; i++)
    {
        if (mmi_bt_get_profile_str_id((U16) dev_p->service_list[i], &str_p) == MMI_TRUE)
        {
            /* skip avrcp controller profile */
            if(dev_p->service_list[i] != MMI_BT_AV_REMOTE_CONTROL_UUID &&
			   dev_p->service_list[i] != MMI_BT_OBEX_IMAGING_UUID)
            {
                mmi_ucs2cat((S8*) g_mmi_bt_scr_cntx.ui_buf, (const S8*)str_p);
                mmi_ucs2cat((S8*) g_mmi_bt_scr_cntx.ui_buf, (const S8*)usc2_buf);
            }
        }

    }

    ui_buffer_size = mmi_ucs2strlen((const S8*)g_mmi_bt_scr_cntx.ui_buf);
    MMI_BT_ASSERT(ui_buffer_size * ENCODING_LENGTH <= (MMI_BT_UI_BUF_SIZE - ENCODING_LENGTH));

    /* Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_BT_ABOUT);


    SetParentHandler(MENU_CONN_BT_MAIN);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory74Screen(
        STR_BT_MYDEV_OPT_SUP_SER,
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8) g_mmi_bt_scr_cntx.ui_buf,
        ui_buffer_size,
        guiBuffer);

    /* go back */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}

/*****************************************************************************
* FUNCTION
*  mmi_bt_exit_about
* DESCRIPTION
*  This function is to 
*
* PARAMETERS
*  a  IN/OUT   first variable, used as returns
*  b  IN       second variable
* RETURNS
*  NONE.  
* GLOBALS AFFECTED
*  external_global
*****************************************************************************/
void mmi_bt_exit_about(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_get_specific_cod_device
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_specific_cod_device(U32 cod_mask)
{
	/* it is not allowed to re-entry my_specific_dev_menu */
	if (IsScreenPresent(SCR_BT_MY_SPECIFIC_DEV_DUMMY))
	{
        DisplayPopup(
    	        (U8*) GetString(STR_BT_NOT_ALLOW),
        	    IMG_GLOBAL_ERROR,
            	MMI_FALSE,
	            UI_POPUP_NOTIFYDURATION_TIME,
    	        (U8) ERROR_TONE);
		return;
	}

    g_mmi_bt_scr_cntx.specific_cod_mask = cod_mask;
    mmi_bt_entry_my_specific_dev_menu();

}
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_my_specific_dev_menu
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_my_specific_dev_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemIcons[MAX_SUB_MENUS];
    U16 nItems, paired_dev_num;
    U8 *guiBuffer;
    U8 i;
    mmi_bt_dev_struct *dev_struct_p;
    U8 utf8_char_cnt = 0;
    U8 ucs2_str_len = 0;
    U32 specific_cod_mask = 0;
    U32 specific_service = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_ENTRY_MY_SPEC_DEV_MENU,
					g_mmi_bt_scr_cntx.specific_cod_mask, 
					g_mmi_bt_scr_cntx.specific_service_id, 
					g_mmi_bt_scr_cntx.select_device_cb);

    /* add dummy screen */
    if (IsBackHistory == MMI_FALSE && 
        !mmi_is_redrawing_bk_screens() && 
        /*!(g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_SPECIFIC_DEV)*/
		!IsScreenPresent(SCR_BT_MY_SPECIFIC_DEV_DUMMY))
    {
		mmi_bt_entry_dummy_specific_cod_device();
	}

    
    if (!mmi_is_redrawing_bk_screens())
    {
      /* to avoid the twice operation while bt is just on and wanna enter specific dev menu */
      if (g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_SPECIFIC_DEV)
      {
			/* delete the power on confirm screen */
			//mmi_bt_delete_screen(SCR_BT_POWER_ON_CNF, MMI_FALSE);
			
          g_mmi_bt_scr_cntx.flag &= ~MMI_BT_CONFIRM_SPECIFIC_DEV;    
          StopTimer(BT_POPUP_TIMER);
      }
    
      if ((mmi_bt_is_hw_ready) (MMI_TRUE) == MMI_FALSE)
      {
          return;
      }
    
      /* to avoid the error operation while bt module is busy */
      if ((mmi_bt_is_permission) (MMI_TRUE) == MMI_FALSE)
      {
          return;
      }
      
      if ( mmi_profiles_bt_is_connected((U8)MMI_PROFILES_BT_HFP_SCO) &&  isInCall())
      {
          #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
		  #endif
		  mmi_bt_popup_operation_not_allowed();
          return;
      }
      
      
      /* prohibited by simap, shall deactivate simap first */
      if (mmi_bt_is_simap_server_activate())
      {
          mmi_bt_popup_prohibited_by_simap();
          return;
      }
      
      if ((*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_pwron) () == MMI_FALSE)
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
      #endif
          /* DisplayConfirm will not be added in history */
          /* In order to control the g_mmi_bt_scr_cntx.flag, using mmi_bt_show_confirm_scr to keep confirm screen in history while confirm screen is interruted by other screen */
          mmi_bt_display_power_on_confirm(MMI_BT_CONFIRM_SPECIFIC_DEV);

          return;
      }
    
      /* to prohibit end user to send vCard via BT while BT is busy(doing inquiry now) */
      /* shall not do this condition check while re-entried by ExecutePopHistory */
      if (IsBackHistory == MMI_FALSE && ( ((*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_state) () != MMI_BT_STAT_IDLE) ||
          IsScreenPresent(SCR_BT_SCH_RES)) )
      {
          DisplayPopup(
              (U8*) GetString(STR_BT_DEV_BUSY),
              IMG_GLOBAL_ERROR,
              MMI_FALSE,
              UI_POPUP_NOTIFYDURATION_TIME,
              (U8) ERROR_TONE);
          return;
      }

    }


    EntryNewScreen(SCR_BT_MY_SPECIFIC_DEV, NULL, mmi_bt_entry_my_specific_dev_menu, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_BT_MY_SPECIFIC_DEV);

    /* Get trust device info */
    paired_dev_num = (U8) g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_num();

    /* Clear UI buffer */
    memset(ItemIcons, 0, sizeof(U16) * MAX_SUB_MENUS);
    /* fill "Inquiry New Device menuitem" */
    nItems = 0;
    subMenuDataPtrs[nItems] =(U8*) GetString(STR_BT_SCH_ALL_DEV);
    hintDataPtrs[nItems] = NULL;
    ItemIcons[nItems] = IMG_BT_MENU_TITLE;
    
    nItems ++;
    specific_cod_mask = g_mmi_bt_scr_cntx.specific_cod_mask;
    specific_service = g_mmi_bt_scr_cntx.specific_service_id;
    
    for (i = 0; i < paired_dev_num; i++)
    {
        dev_struct_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_info) (i);

        if ( (dev_struct_p->cod & specific_cod_mask) == specific_cod_mask &&
			 mmi_bt_is_service_support(dev_struct_p, specific_service))
        {

            /* Fill device name list */
            /* get byte count for convert utf8 string to UCS2 string */
            /* get character count of utf8 string */
            /* +1 is for UCS2 NULL terminate */
            /* *ENCODING_LENGTH is for byte count of one UCS2 character */
            utf8_char_cnt = (U8) ((mmi_chset_utf8_strlen((kal_uint8*) dev_struct_p->name) + 1) * ENCODING_LENGTH);
            MMI_BT_ASSERT(MAX_SUB_MENU_SIZE >= MMI_BT_SCR_BD_NAME_LEN);
            if (utf8_char_cnt > MMI_BT_SCR_BD_NAME_LEN)
            {
                ucs2_str_len =
                    (U8) mmi_chset_utf8_to_ucs2_string(
                            (kal_uint8*) subMenuData[nItems],
                            MMI_BT_SCR_BD_NAME_LEN,
                            (kal_uint8*) dev_struct_p->name);
            }
            else
            {
                ucs2_str_len =
                    (U8) mmi_chset_utf8_to_ucs2_string(
                            (kal_uint8*) subMenuData[nItems],
                            utf8_char_cnt,
                            (kal_uint8*) dev_struct_p->name);
            }
			/* allow (MMI_BT_BD_NAME_LEN/3) chinese characters or (MMI_BT_BD_NAME_LEN/3)*2 english characters  */
			/* so for UCS2 encoding, need MMI_BT_SCR_BD_NAME_LEN bytes */

			/* shall check if there is any two_byte character mixed in one_bye UCS2 string */
			/* if yes, then truncate the string to meet above rules((MMI_BT_BD_NAME_LEN/3) chinese characters or (MMI_BT_BD_NAME_LEN/3)*2 english characters)*/	
			if(mmi_bt_test_ucs2((U16*)subMenuData[nItems], (U16)(ucs2_str_len/ENCODING_LENGTH)) )
			{ 
				mmi_bt_truncate_ucs2_string((U16*)subMenuData[nItems], 
				    							(U16)(ucs2_str_len/ENCODING_LENGTH),
				    							(U16)((MMI_BT_BD_NAME_LEN-2)/3)
				    						   );		    
			}
        
            
            subMenuDataPtrs[nItems] = subMenuData[nItems];

            /* BT address: NAP, UAP, LAP */
            kal_wsprintf(
                (U16*) hintData[nItems],
                "BD_ADDR: %02x:%02x:%02x:%02x:%02x:%02x",
                ((dev_struct_p->bd_addr.nap & 0xff00) >> 8),
                (dev_struct_p->bd_addr.nap & 0x00ff),
                (dev_struct_p->bd_addr.uap),
                ((dev_struct_p->bd_addr.lap & 0xff0000) >> 16),
                ((dev_struct_p->bd_addr.lap & 0x00ff00) >> 8),
                (dev_struct_p->bd_addr.lap & 0x0000ff));
            hintDataPtrs[nItems] = hintData[nItems];

            /* Fill device icon list */
            if (dev_struct_p->cod & MMI_BT_COMPUTER_MAJOR_DEVICE_MASK)
            {
                ItemIcons[nItems] = IMG_BT_DEV_LAP;
            }
            else if (dev_struct_p->cod & MMI_BT_PRINTER_IMAGING_MINOR_DEVICE_CLASS)
            {
                ItemIcons[nItems] = IMG_BT_DEV_PRT;
            }
            else if (dev_struct_p->cod & MMI_BT_PHONE_MAJOR_DEVICE_MASK)
            {
                ItemIcons[nItems] = IMG_BT_DEV_MOB;
            }
            else if (dev_struct_p->cod & MMI_BT_AV_MAJOR_DEVICE_MASK)
            {
                ItemIcons[nItems] = IMG_BT_DEV_EAR;
            }
            else
            {
                ItemIcons[nItems] = IMG_BT_DEV_OTHER;
            }

            nItems ++;
        }

    }


    RegisterHighlightHandler(mmi_bt_my_specific_dev_hilite_hdlr);

    ShowCategory53Screen(
        STR_BT_MYDEVICE/*STR_BT_MY_AV_DEVICE*/,
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nItems,
        (U8 **) subMenuDataPtrs,
        (U16*) ItemIcons,
        hintDataPtrs,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}

/*****************************************************************************
* FUNCTION
*  mmi_bt_exit_mydev_menu
* DESCRIPTION
*   This function is bluetooth highlight handler.
*
* PARAMETERS
*  a  IN/OUT      first variable, used as returns
*  b  IN       second variable
* RETURNS
*  NONE.
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/
void mmi_bt_exit_my_specific_dev_menu(void)
{
    

}
/*****************************************************************************
* FUNCTION
*  mmi_bt_entry_my_specific_dev_rsk_hdler
* DESCRIPTION
*   This function is 
*
* PARAMETERS
*  a  IN/OUT      first variable, used as returns
*  b  IN       second variable
* RETURNS
*  NONE.
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/
void mmi_bt_entry_my_specific_dev_rsk_hdler(void)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reset scr flag */
    //mmi_bt_reset_scr_flag();
    g_mmi_bt_scr_cntx.flag &= ~MMI_BT_CONFIRM_SPECIFIC_DEV;
    GoBackHistory();

}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_mydev_hilite_hdlr
 * DESCRIPTION
 *  This function is bluetooth highlight handler.
 * PARAMETERS
 *  idx         [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_my_specific_dev_hilite_hdlr(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* store the idx for mmi_bt_select_my_specific_dev*/
    g_mmi_bt_scr_cntx.hilight_item = idx;

    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_SCR_HIGHLIGHT_ITEM, idx);
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_MY_SPEC_DEV_HILITE_HDLR, g_mmi_bt_scr_cntx.select_device_cb);

    if(idx == 0)
    {
		if (g_mmi_bt_scr_cntx.select_device_cb == NULL)
		{
            if(g_mmi_bt_scr_cntx.specific_cod_mask & MMI_BT_OBJECT_TRANSFER_MAJOR_SERVICE_MASK)
            {
                SetLeftSoftkeyFunction(mmi_bt_inquiry_opp_dev, KEY_EVENT_UP);
                SetKeyHandler(mmi_bt_inquiry_opp_dev, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            }
            else if ((g_mmi_bt_scr_cntx.specific_cod_mask & MMI_BT_RENDERING_MAJOR_SERVICE_MASK) &&
             	     (g_mmi_bt_scr_cntx.specific_cod_mask & MMI_BT_IMAGING_MAJOR_DEVICE_MASK) &&
             	     (g_mmi_bt_scr_cntx.specific_cod_mask & MMI_BT_PRINTER_IMAGING_MINOR_DEVICE_CLASS) )
            {
                SetLeftSoftkeyFunction(mmi_bt_inquiry_printer_dev, KEY_EVENT_UP);
                SetKeyHandler(mmi_bt_inquiry_printer_dev, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            }
            else if ((g_mmi_bt_scr_cntx.specific_cod_mask & MMI_BT_AUDIO_MAJOR_SERVICE_MASK) &&
                     (g_mmi_bt_scr_cntx.specific_cod_mask & MMI_BT_RENDERING_MAJOR_SERVICE_MASK) &&
                     (g_mmi_bt_scr_cntx.specific_cod_mask & MMI_BT_AV_MAJOR_DEVICE_MASK))
            {
                SetLeftSoftkeyFunction(mmi_bt_inquiry_a2dp_dev, KEY_EVENT_UP);
                SetKeyHandler(mmi_bt_inquiry_a2dp_dev, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            }
            else if ((g_mmi_bt_scr_cntx.specific_cod_mask & MMI_BT_PERIPHERAL_MAJOR_DEVICE_MASK) &&
					    (g_mmi_bt_scr_cntx.specific_cod_mask & MMI_BT_COMPUTER_MAJOR_DEVICE_MASK) &&            
                     (g_mmi_bt_scr_cntx.specific_cod_mask & MMI_BT_REMOTE_CONTRO_DEVICE_PERIPHERAL_MINOR_DEVICE_CLASS))
            {
                SetLeftSoftkeyFunction(mmi_bt_inquiry_remote_ctrl_dev, KEY_EVENT_UP);
                SetKeyHandler(mmi_bt_inquiry_remote_ctrl_dev, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            }
            else
            {
                SetLeftSoftkeyFunction(mmi_bt_entry_mydev_sch, KEY_EVENT_UP);
                SetKeyHandler(mmi_bt_entry_mydev_sch, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            }
		}
		else
	    {
	        SetLeftSoftkeyFunction(mmi_bt_inquiry_specific_cod_dev, KEY_EVENT_UP);
	        SetKeyHandler(mmi_bt_inquiry_specific_cod_dev, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
	    }

    }
    else
    {
        SetLeftSoftkeyFunction(mmi_bt_select_my_specific_dev, KEY_EVENT_UP);
        SetKeyHandler(mmi_bt_select_my_specific_dev, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }


    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_select_my_specific_dev
 * DESCRIPTION
 *  This function is 
 * PARAMETERS
 *  idx         [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_select_my_specific_dev(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bt_dev_struct *dev_p = NULL;
    U32 i, j, index, paired_dev_num;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_SELECT_MY_SPEC_DEV, g_mmi_bt_scr_cntx.select_device_cb);


    if ((mmi_bt_is_hw_ready) (MMI_TRUE) == MMI_FALSE)
    {
        return;
    }

    /* to avoid the error operation while bt module is busy */
    if ((mmi_bt_is_permission) (MMI_TRUE) == MMI_FALSE)
    {
        return;
    }

    index = g_mmi_bt_scr_cntx.hilight_item;
    paired_dev_num = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_num)();

    if(index > 0)
    {
        j = index - 1;
        for (i = 0; i < paired_dev_num; i++)
        {
            dev_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_info) ((U16) i);

            if ((i <= j) &&
                !(((dev_p->cod & g_mmi_bt_scr_cntx.specific_cod_mask)==g_mmi_bt_scr_cntx.specific_cod_mask ) &&
				mmi_bt_is_service_support(dev_p, g_mmi_bt_scr_cntx.specific_service_id))	                
               )
            {
                j++;
            }
        }
        
        if (j < (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_num) ())
        {
            dev_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_info) ((U16) j);
        }
    }

	 MMI_BT_ASSERT(dev_p);	
    /* store specific device */
    memcpy(&(g_mmi_bt_scr_cntx.selected_spec_dev), dev_p, sizeof(mmi_bt_dev_struct));

	if (g_mmi_bt_scr_cntx.select_device_cb == NULL)
	{
	    if (g_mmi_bt_scr_cntx.specific_cod_mask & MMI_BT_OBJECT_TRANSFER_MAJOR_SERVICE_MASK)
	    {
			mmi_bt_opp_sending();
	    	DeleteScreenIfPresent(SCR_BT_MY_SPECIFIC_DEV);
	    	DeleteScreenIfPresent(SCR_BT_MY_SPECIFIC_DEV_DUMMY);
	    	
	    }
	    else if ((g_mmi_bt_scr_cntx.specific_cod_mask & MMI_BT_RENDERING_MAJOR_SERVICE_MASK) &&
	           	 (g_mmi_bt_scr_cntx.specific_cod_mask & MMI_BT_IMAGING_MAJOR_DEVICE_MASK) &&
	           	 (g_mmi_bt_scr_cntx.specific_cod_mask & MMI_BT_PRINTER_IMAGING_MINOR_DEVICE_CLASS) )
		{
			#if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_BPP_SUPPORT__)
			//(*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_connect_req) (&(dev_p->bd_addr), MMI_BT_BASIC_PRINTING);			
        	mmi_bt_bpp_printing(dev_p->bd_addr.nap, dev_p->bd_addr.uap, dev_p->bd_addr.lap);
	        #endif
	    	DeleteScreenIfPresent(SCR_BT_MY_SPECIFIC_DEV);
	    	DeleteScreenIfPresent(SCR_BT_MY_SPECIFIC_DEV_DUMMY);

		}
    	else if ((g_mmi_bt_scr_cntx.specific_cod_mask & MMI_BT_AUDIO_MAJOR_SERVICE_MASK) &&
             (g_mmi_bt_scr_cntx.specific_cod_mask & MMI_BT_RENDERING_MAJOR_SERVICE_MASK) &&
	             (g_mmi_bt_scr_cntx.specific_cod_mask & MMI_BT_AV_MAJOR_DEVICE_MASK))
	    {
			#if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_A2DP_SUPPORT__)
	        av_bt_headset_selected_callback(dev_p);
	        #endif
	    	DeleteScreenIfPresent(SCR_BT_MY_SPECIFIC_DEV_DUMMY);
	        GoBackHistory();
	
	    }
	    else
	    {
	    	DeleteScreenIfPresent(SCR_BT_MY_SPECIFIC_DEV_DUMMY);
	        GoBackHistory();
	    }
	}
	else
    {
		if (g_mmi_bt_scr_cntx.select_device_cb != NULL)
		{
		    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_SELECT_DEVICE_CB,
						MMI_TRUE, 
		        		dev_p->bd_addr.lap, 
		        		dev_p->bd_addr.uap, 
		        		dev_p->bd_addr.nap );
			(*g_mmi_bt_scr_cntx.select_device_cb)(MMI_TRUE, dev_p->bd_addr.lap, dev_p->bd_addr.uap, dev_p->bd_addr.nap);
			g_mmi_bt_scr_cntx.select_device_cb = NULL;
		}
    	DeleteScreenIfPresent(SCR_BT_MY_SPECIFIC_DEV);
    	DeleteScreenIfPresent(SCR_BT_MY_SPECIFIC_DEV_DUMMY);
    }
       
    
}



/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_power_on_confirm
 * DESCRIPTION
 *  This function is 
 * PARAMETERS
 *  NULL         [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_display_power_on_confirm(U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_DISPLAY_CONFIRM_SCR, g_mmi_bt_scr_cntx.flag);

    /* not allow to re-entry mmi_bt_show_confirm_scr because only store one cnf scr id and string id */
    if (g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_SWITCH_POWER_OFF ||
        g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_INQ_AUDIO_DEV ||
        g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_PAIRED_DEV_OPT ||
        g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_PAIRED_DEV_DEL ||
        g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_PAIRED_DEV_DEL_ALL ||
        g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_PAIRED_DEV_SCH ||
        g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_SIMAP_SET ||
        g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_SET ||
        g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_SPECIFIC_DEV )
    {
        DisplayPopup(
            (U8*) GetString(STR_BT_NOT_ALLOW),
            IMG_GLOBAL_ERROR,
            MMI_FALSE,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
        return;
    }

	g_mmi_bt_scr_cntx.flag |= flag;
    mmi_bt_entry_power_on_confirm();

}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_power_on_confirm
 * DESCRIPTION
 *  This function is 
 * PARAMETERS
 *  NULL         [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_power_on_confirm(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_bt_show_confirm_scr(
	    SCR_BT_POWER_ON_CNF,
	    STR_BT_PWR_ON_CNF,
	    mmi_bt_exit_power_on_confirm,
	    mmi_bt_entry_power_on_confirm);

    SetDelScrnIDCallbackHandler(SCR_BT_POWER_ON_CNF, (HistoryDelCBPtr) mmi_bt_entry_power_on_confirm_del_cb);

	SetLeftSoftkeyFunction(mmi_bt_entry_power_switch, KEY_EVENT_UP);
	SetRightSoftkeyFunction(mmi_bt_entry_power_on_confirm_rsk_hdler, KEY_EVENT_UP);

	return;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_exit_power_on_confirm
 * DESCRIPTION
 *  This function is 
 * PARAMETERS
 *  NULL         [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_exit_power_on_confirm(void)
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
 *  mmi_bt_entry_power_on_confirm_del_cb
 * DESCRIPTION
 *  This function is 
 * PARAMETERS
 *  NULL         [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_bt_entry_power_on_confirm_del_cb(void)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_CONFIRM_SCR_DEL_CB, g_mmi_bt_scr_cntx.flag);
    
    /* reset confirm flag */
    /* only one confirm flag is set at one time */
    g_mmi_bt_scr_cntx.flag &= ~MMI_BT_CONFIRM_INQ_AUDIO_DEV;
    g_mmi_bt_scr_cntx.flag &= ~MMI_BT_CONFIRM_PAIRED_DEV_OPT;
    g_mmi_bt_scr_cntx.flag &= ~MMI_BT_CONFIRM_PAIRED_DEV_SCH;
    g_mmi_bt_scr_cntx.flag &= ~MMI_BT_CONFIRM_SET;
	if (!IsScreenPresent(SCR_BT_MY_SPECIFIC_DEV_DUMMY))
	{
	   g_mmi_bt_scr_cntx.flag &= ~MMI_BT_CONFIRM_SPECIFIC_DEV;
	}

    SetDelScrnIDCallbackHandler(SCR_BT_POWER_ON_CNF, (HistoryDelCBPtr) NULL);

	return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_power_on_confirm_rsk_hdler
 * DESCRIPTION
 *  This function is 
 * PARAMETERS
 *  NULL         [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_power_on_confirm_rsk_hdler(void)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reset confirm flag */
    /* only one confirm flag is set at one time */
    g_mmi_bt_scr_cntx.flag &= ~MMI_BT_CONFIRM_INQ_AUDIO_DEV;
    g_mmi_bt_scr_cntx.flag &= ~MMI_BT_CONFIRM_PAIRED_DEV_OPT;
    g_mmi_bt_scr_cntx.flag &= ~MMI_BT_CONFIRM_PAIRED_DEV_SCH;
    g_mmi_bt_scr_cntx.flag &= ~MMI_BT_CONFIRM_SET;
    g_mmi_bt_scr_cntx.flag &= ~MMI_BT_CONFIRM_SPECIFIC_DEV;
    
    GoBackHistory();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_display_release_all_connection_confirm
 * DESCRIPTION
 *  This function is 
 * PARAMETERS
 *  NULL         [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_display_release_all_connection_confirm(U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_DISPLAY_CONFIRM_SCR, g_mmi_bt_scr_cntx.flag);

    /* not allow to re-entry mmi_bt_show_confirm_scr because only store one cnf scr id and string id */
    if (g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_SWITCH_POWER_OFF ||
        g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_INQ_AUDIO_DEV ||
        g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_PAIRED_DEV_OPT ||
        g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_PAIRED_DEV_DEL ||
        g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_PAIRED_DEV_DEL_ALL ||
        g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_PAIRED_DEV_SCH ||
        g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_SIMAP_SET ||
        g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_SET ||
        g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_SPECIFIC_DEV )
    {
        DisplayPopup(
            (U8*) GetString(STR_BT_NOT_ALLOW),
            IMG_GLOBAL_ERROR,
            MMI_FALSE,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
        return;
    }

	g_mmi_bt_scr_cntx.flag |= flag;
    mmi_bt_entry_release_all_connection_confirm();

}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_release_all_connection_confirm
 * DESCRIPTION
 *  This function is 
 * PARAMETERS
 *  NULL         [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_release_all_connection_confirm(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
      
	mmi_bt_show_confirm_scr(
	    SCR_BT_RELEASE_ALL_CONN_CNF,
	    STR_BT_DISCONN_ALL_CONN_CNF,
	    mmi_bt_exit_release_all_connection_confirm,
	    mmi_bt_entry_release_all_connection_confirm);

    SetDelScrnIDCallbackHandler(SCR_BT_RELEASE_ALL_CONN_CNF, (HistoryDelCBPtr) mmi_bt_entry_release_all_connection_confirm_del_cb);

	SetLeftSoftkeyFunction(mmi_bt_entry_release_all_connections, KEY_EVENT_UP);
	SetRightSoftkeyFunction(mmi_bt_entry_release_all_connection_confirm_rsk_hdler, KEY_EVENT_UP);

	return;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_exit_release_all_connection_confirm
 * DESCRIPTION
 *  This function is 
 * PARAMETERS
 *  NULL         [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_exit_release_all_connection_confirm(void)
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
 *  mmi_bt_entry_release_all_connection_confirm_del_cb
 * DESCRIPTION
 *  This function is 
 * PARAMETERS
 *  NULL         [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_bt_entry_release_all_connection_confirm_del_cb(void)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_CONFIRM_SCR_DEL_CB, g_mmi_bt_scr_cntx.flag);
    
    /* reset confirm flag */
    /* only one confirm flag is set at one time */
    g_mmi_bt_scr_cntx.flag &= ~MMI_BT_CONFIRM_SWITCH_POWER_OFF;
    g_mmi_bt_scr_cntx.flag &= ~MMI_BT_CONFIRM_PAIRED_DEV_DEL_ALL;
    g_mmi_bt_scr_cntx.flag &= ~MMI_BT_CONFIRM_SIMAP_SET;

    SetDelScrnIDCallbackHandler(SCR_BT_RELEASE_ALL_CONN_CNF, (HistoryDelCBPtr) NULL);

	return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_release_all_connection_confirm_rsk_hdler
 * DESCRIPTION
 *  This function is 
 * PARAMETERS
 *  NULL         [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_release_all_connection_confirm_rsk_hdler(void)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reset confirm flag */
    /* only one confirm flag is set at one time */
    g_mmi_bt_scr_cntx.flag &= ~MMI_BT_CONFIRM_SWITCH_POWER_OFF;
    g_mmi_bt_scr_cntx.flag &= ~MMI_BT_CONFIRM_PAIRED_DEV_DEL_ALL;
    g_mmi_bt_scr_cntx.flag &= ~MMI_BT_CONFIRM_SIMAP_SET;

    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_display_release_dev_connection_confirm
 * DESCRIPTION
 *  This function is 
 * PARAMETERS
 *  NULL         [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_display_release_dev_connection_confirm(U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_DISPLAY_CONFIRM_SCR, g_mmi_bt_scr_cntx.flag);
    /* not allow to re-entry mmi_bt_show_confirm_scr because only store one cnf scr id and string id */
    if (g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_SWITCH_POWER_OFF ||
        g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_INQ_AUDIO_DEV ||
        g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_PAIRED_DEV_OPT ||
        g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_PAIRED_DEV_DEL ||
        g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_PAIRED_DEV_DEL_ALL ||
        g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_PAIRED_DEV_SCH ||
        g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_SIMAP_SET ||
        g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_SET ||
        g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_SPECIFIC_DEV )
    {
        DisplayPopup(
            (U8*) GetString(STR_BT_NOT_ALLOW),
            IMG_GLOBAL_ERROR,
            MMI_FALSE,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
        return;
    }

	g_mmi_bt_scr_cntx.flag |= flag;
    mmi_bt_entry_release_dev_connection_confirm();

}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_release_dev_connection_confirm
 * DESCRIPTION
 *  This function is 
 * PARAMETERS
 *  NULL         [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_release_dev_connection_confirm(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
      
	mmi_bt_show_confirm_scr(
	    SCR_BT_RELEASE_DEV_CONN_CNF,
	    STR_BT_DISCONN_DEV_CONN_CNF,
	    mmi_bt_exit_release_dev_connection_confirm,
	    mmi_bt_entry_release_dev_connection_confirm);

    SetDelScrnIDCallbackHandler(SCR_BT_RELEASE_ALL_CONN_CNF, (HistoryDelCBPtr) mmi_bt_entry_release_dev_connection_confirm_del_cb);

	SetLeftSoftkeyFunction(mmi_bt_entry_release_device_connections, KEY_EVENT_UP);
	SetRightSoftkeyFunction(mmi_bt_entry_release_dev_connection_confirm_rsk_hdler, KEY_EVENT_UP);

	return;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_exit_release_dev_connection_confirm
 * DESCRIPTION
 *  This function is 
 * PARAMETERS
 *  NULL         [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_exit_release_dev_connection_confirm(void)
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
 *  mmi_bt_entry_release_all_connection_confirm_del_cb
 * DESCRIPTION
 *  This function is 
 * PARAMETERS
 *  NULL         [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_bt_entry_release_dev_connection_confirm_del_cb(void)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_CONFIRM_SCR_DEL_CB, g_mmi_bt_scr_cntx.flag);
    
    /* reset confirm flag */
    /* only one confirm flag is set at one time */
    g_mmi_bt_scr_cntx.flag &= ~MMI_BT_CONFIRM_PAIRED_DEV_DEL;

    SetDelScrnIDCallbackHandler(SCR_BT_RELEASE_DEV_CONN_CNF, (HistoryDelCBPtr) NULL);

	return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_release_dev_connection_confirm_rsk_hdler
 * DESCRIPTION
 *  This function is 
 * PARAMETERS
 *  NULL         [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_release_dev_connection_confirm_rsk_hdler(void)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reset confirm flag */
    /* only one confirm flag is set at one time */
    g_mmi_bt_scr_cntx.flag &= ~MMI_BT_CONFIRM_PAIRED_DEV_DEL;

    GoBackHistory();
}

/* connect confirm */
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_display_connect_profile_connection_confirm
 * DESCRIPTION
 *  This function is 
 * PARAMETERS
 *  NULL         [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_display_connect_profile_connection_confirm(U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_DISPLAY_CONFIRM_SCR, g_mmi_bt_scr_cntx.flag);

	g_mmi_bt_scr_cntx.flag |= flag;
    mmi_bt_entry_connect_profile_connection_confirm();

}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_connect_profile_connection_confirm
 * DESCRIPTION
 *  This function is 
 * PARAMETERS
 *  NULL         [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_connect_profile_connection_confirm(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
      
	mmi_bt_show_confirm_scr(
	    SCR_BT_CONNECT_CNF,
	    STR_BT_CONNECT_AND_SET_AS_DEFAULT_HF,
	    mmi_bt_exit_connect_profile_connection_confirm,
	    mmi_bt_entry_connect_profile_connection_confirm);

    SetDelScrnIDCallbackHandler(SCR_BT_CONNECT_CNF, (HistoryDelCBPtr) mmi_bt_entry_connect_profile_connection_confirm_del_cb);


	SetLeftSoftkeyFunction(mmi_bt_entry_connecting, KEY_EVENT_UP);
	SetRightSoftkeyFunction(mmi_bt_entry_connect_profile_connection_confirm_rsk_hdler, KEY_EVENT_UP);

	return;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_exit_connect_profile_connection_confirm
 * DESCRIPTION
 *  This function is 
 * PARAMETERS
 *  NULL         [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_exit_connect_profile_connection_confirm(void)
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
 *  mmi_bt_entry_connect_profile_connection_confirm_del_cb
 * DESCRIPTION
 *  This function is 
 * PARAMETERS
 *  NULL         [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_bt_entry_connect_profile_connection_confirm_del_cb(void)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_CONFIRM_SCR_DEL_CB, g_mmi_bt_scr_cntx.flag);
    
    /* reset confirm flag */
    /* only one confirm flag is set at one time */
    g_mmi_bt_scr_cntx.flag &= ~MMI_BT_INQ_TYPE_AUDIO;

    SetDelScrnIDCallbackHandler(SCR_BT_CONNECT_CNF, (HistoryDelCBPtr) NULL);

	return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_connect_profile_connection_confirm_rsk_hdler
 * DESCRIPTION
 *  This function is 
 * PARAMETERS
 *  NULL         [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_connect_profile_connection_confirm_rsk_hdler(void)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reset confirm flag */
    /* only one confirm flag is set at one time */
    g_mmi_bt_scr_cntx.flag &= ~MMI_BT_INQ_TYPE_AUDIO;

    GoBackHistory();
}




/*****************************************************************************
 * FUNCTION
 *  mmi_bt_is_service_support
 * DESCRIPTION
 *  This function is to 
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bt_is_service_support(mmi_bt_dev_struct *dev_p, U32 service_id)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 i;
	MMI_BOOL result = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (service_id !=0)
	{
		for (i = 0; i < dev_p->service_list_num; i++)
		{
			if (dev_p->service_list[i] == service_id)
			{
				result = MMI_TRUE;
			}
		}
	}
	else
	{
		result = MMI_TRUE;
	}
	
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_IS_SERVICE_SUPPORT, service_id, result);

	
	return result;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_a2dp_device_select_screen
 * DESCRIPTION
 *  This function is to show
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_a2dp_device_select_screen(void)
{
    mmi_bt_entry_specific_cod_device((U32)(MMI_BT_AUDIO_MAJOR_SERVICE_MASK | MMI_BT_RENDERING_MAJOR_SERVICE_MASK | MMI_BT_AV_MAJOR_DEVICE_MASK));
}
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_obex_device_select_screen
 * DESCRIPTION
 *  This function is to  
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_obex_device_select_screen(void)
{

    mmi_bt_entry_specific_cod_device((U32)MMI_BT_OBJECT_TRANSFER_MAJOR_SERVICE_MASK);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_remote_control_device_select_screen
 * DESCRIPTION
 *  This function is to show
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_remote_control_device_select_screen(void)
{
    mmi_bt_entry_specific_cod_device((U32)(MMI_BT_PERIPHERAL_MAJOR_DEVICE_MASK | MMI_BT_REMOTE_CONTRO_DEVICE_PERIPHERAL_MINOR_DEVICE_CLASS | MMI_BT_COMPUTER_MAJOR_DEVICE_MASK));
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_printer_device_select_screen
 * DESCRIPTION
 *  This function is to show
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_printer_device_select_screen(void)
{
    mmi_bt_entry_specific_cod_device((U32)(MMI_BT_RENDERING_MAJOR_SERVICE_MASK |MMI_BT_IMAGING_MAJOR_DEVICE_MASK |MMI_BT_PRINTER_IMAGING_MINOR_DEVICE_CLASS));
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_cod_device_with_service_select_screen
 * DESCRIPTION
 *  This function is for bluetooth profile applications to inquiry NEW device or select device from BT CM paired device list
 *   to do application specific future operations. The future operation may be to connect with remote device or just list it on application setting menu.
 * PARAMETERS
 *  cod_bit_mask     [IN]    fill in the class of device bitmask for BT CM to filter the devices that profile application desired 
 *  service_id       [IN]    fill in the profile service UUID for BT CM to filter the devices which support specified profile service.
 *                           service_id=0 means that doesnot require to check if found device supports this service or not
 *  func_ptr         [IN]    BT CM will invoke the registered callback while BT CM found the matched device(cod and service_id)
 *                           with MMI_TRUE result and device address. If end user stops this operation by pressing RSK"Back"
 *                           or END key or screen deleted by other applications, BT CM will invoke the callback with MMI_FALSE result and NULL device address.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_cod_device_with_service_select_screen(
				U32 cod_bit_mask, 
				U32 service_id, 
				void *func_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_ENTRY_COD_DEV_WITH_SER_SELECT_SCREEN, 
			    cod_bit_mask, service_id, func_ptr);

	/* it is not allowed to re-entry my_specific_dev_menu */
	if (IsScreenPresent(SCR_BT_MY_SPECIFIC_DEV_DUMMY))
	{
		if (func_ptr)
		{
		    mmi_bt_select_specific_cod_dev_callback app_cb;

			app_cb = (void (*)(MMI_BOOL, U32, U8, U16))func_ptr;
			(*app_cb)(MMI_FALSE, 0, 0, 0);
		}
        DisplayPopup(
    	        (U8*) GetString(STR_BT_NOT_ALLOW),
        	    IMG_GLOBAL_ERROR,
            	MMI_FALSE,
	            UI_POPUP_NOTIFYDURATION_TIME,
    	        (U8) ERROR_TONE);
		return;
		
	}

    
	/* check the input arguments */
    g_mmi_bt_scr_cntx.specific_cod_mask = cod_bit_mask;
    g_mmi_bt_scr_cntx.specific_service_id = service_id;
	g_mmi_bt_scr_cntx.select_device_cb = (void (*)(MMI_BOOL, U32, U8, U16))func_ptr;
	mmi_bt_entry_my_specific_dev_menu();
	
}



/*****************************************************************************
 * FUNCTION
 *  mmi_bt_get_selected_specfic_device_info
 * DESCRIPTION
 *  This function is to  
 * PARAMETERS
 *  dev_add_p  [OUT]    fill the bd address for api caller
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_get_selected_specfic_device_info(void *dev_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //mmi_bt_dev_struct *selected_dev_p = (mmi_bt_dev_struct*) dev_p;
    memcpy(dev_p, &(g_mmi_bt_scr_cntx.selected_spec_dev), sizeof(mmi_bt_dev_struct));
}
/* Configure Default Headset */
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_get_default_headset_device_name
 * DESCRIPTION
 *  This function is to  get default headset device name
 * PARAMETERS
 *  void
 * RETURNS
 *  U8*    the returned device name will be encoded by UCS2 with two bytes NULL terminate.
  *****************************************************************************/
U8* mmi_bt_get_default_headset_device_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* dev_name_p=NULL;
    U32 index_default_hs;
    mmi_bt_dev_struct *dev_p;
    U8 utf8_char_cnt = 0;
    U8 ucs2_str_len = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_default_hs_index)
    {
        index_default_hs = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_default_hs_index)();
        if (index_default_hs < (U32)(*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_num)() )
        {
            dev_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_info) ((U16)index_default_hs);
            /* convert device name to UCS2 encoding */
            /* get byte count for convert utf8 string to UCS2 string */
            /* get character count of utf8 string */
            /* +1 is for UCS2 NULL terminate */
            /* *ENCODING_LENGTH is for byte count of one UCS2 character */
            utf8_char_cnt = (U8) ((mmi_chset_utf8_strlen((kal_uint8*) dev_p->name) + 1) * ENCODING_LENGTH);
            MMI_BT_ASSERT(MMI_BT_SCR_BUF_SIZE >= (MMI_BT_SCR_BD_NAME_LEN));
            if (utf8_char_cnt > MMI_BT_SCR_BD_NAME_LEN)
            {
                ucs2_str_len =
                    (U8) mmi_chset_utf8_to_ucs2_string(
                            (kal_uint8*) (g_mmi_bt_scr_cntx.scr_buf),
                            MMI_BT_SCR_BD_NAME_LEN,
                            (kal_uint8*) dev_p->name);
            }
            else
            {
                ucs2_str_len =
                    (U8) mmi_chset_utf8_to_ucs2_string(
                            (kal_uint8*) (g_mmi_bt_scr_cntx.scr_buf),
                            utf8_char_cnt,
                            (kal_uint8*) dev_p->name);
            }
            /* allow (MMI_BT_BD_NAME_LEN/3) chinese characters or (MMI_BT_BD_NAME_LEN/3)*2 english characters  */
            /* so for UCS2 encoding, need MMI_BT_SCR_BD_NAME_LEN bytes */
            
            /* shall check if there is any two_byte character mixed in one_bye UCS2 string */
            /* if yes, then truncate the string to meet above rules((MMI_BT_BD_NAME_LEN/3) chinese characters or (MMI_BT_BD_NAME_LEN/3)*2 english characters)*/ 
            if(mmi_bt_test_ucs2((U16*)g_mmi_bt_scr_cntx.scr_buf, (U16)(ucs2_str_len/ENCODING_LENGTH)) )
            { 
                mmi_bt_truncate_ucs2_string((U16*)g_mmi_bt_scr_cntx.scr_buf, 
                                                (U16)(ucs2_str_len/ENCODING_LENGTH),
                                                (U16)((MMI_BT_BD_NAME_LEN-2)/3)
                                               );           
            }
            
            dev_name_p = g_mmi_bt_scr_cntx.scr_buf;
                
        }
        
    }

	return dev_name_p;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_show_popup_scr
 * DESCRIPTION
 *  This function is to show popup screen
 * PARAMETERS
 *  string              [?]             
 *  imageId             [IN]            
 *  imageOnBottom       [IN]            
 *  popupDuration       [IN]            
 *  toneId              [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_show_popup_scr(U8 *string, U16 imageId, U8 imageOnBottom, U32 popupDuration, U8 toneId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopup(string, imageId, imageOnBottom, popupDuration, toneId);

    /* delete progressing screen */
    DeleteScreenIfPresent(SCR_BT_POWER_PRO);
    DeleteScreenIfPresent(SCR_BT_REL_ALL_CONN_PRO);
    DeleteScreenIfPresent(SCR_BT_SCH_PRO);
    DeleteScreenIfPresent(SCR_BT_SCH_CANCEL_PRO);
    DeleteScreenIfPresent(SCR_BT_BOND);
    DeleteScreenIfPresent(SCR_BT_PAIR_PRO);
    DeleteScreenIfPresent(SCR_BT_CONNECTING);
    /* Configure Default Headset */
    DeleteScreenIfPresent(SCR_BT_CONNECT_LAST_HEADSET);
    DeleteScreenIfPresent(SCR_BT_SET_NAME);
    DeleteScreenIfPresent(SCR_BT_SET_VIS);
    DeleteScreenIfPresent(SCR_BT_SET_AUTH);
    DeleteScreenIfPresent(SCR_BT_MYDEV_DEL);
    DeleteScreenIfPresent(SCR_BT_MYDEV_DEL_ALL);
    DeleteScreenIfPresent(SCR_BT_MYDEV_SCH);
    DeleteScreenIfPresent(SCR_BT_DISC_PROC);
    DeleteScreenIfPresent(SCR_BT_REFREAH_PROFILE);
    DeleteScreenIfPresent(SCR_BT_SWITCH_SPEECH_PATH);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_show_progress_scr
 * DESCRIPTION
 *  This function is to show progressing screen
 * PARAMETERS
 *  scrid           [IN]            
 *  title           [IN]            
 *  context_id      [IN]            
 *  context_str     [?]             
 *  cancel_key      [IN]            
 *  fp              [IN]            
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_show_progress_scr(U16 scrid, U16 title, U16 context_id, U16 *context_str, MMI_BOOL cancel_key, FuncPtr fp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_SCR_SHOW_PROGRESSING, (g_mmi_bt_scr_cntx.prog_scr.scr_id),
               (g_mmi_bt_scr_cntx.prog_scr.title_str_id), (g_mmi_bt_scr_cntx.prog_scr.context_id));

    /* Prevent progressing screen re-entry */
    if (((g_mmi_bt_scr_cntx.prog_scr.scr_id) != 0)
        || ((g_mmi_bt_scr_cntx.prog_scr.title_str_id) != 0)
        || (mmi_ucs2strlen((const S8*)(g_mmi_bt_scr_cntx.prog_scr.context_str)) != 0)
        || ((g_mmi_bt_scr_cntx.prog_scr.context_id) != 0))
    {
        mmi_bt_stop_progress_scr(MMI_FALSE);
    }

    (g_mmi_bt_scr_cntx.prog_scr.scr_id) = scrid;
    (g_mmi_bt_scr_cntx.prog_scr.title_str_id) = title;
    (g_mmi_bt_scr_cntx.prog_scr.context_id) = context_id;
    (g_mmi_bt_scr_cntx.prog_scr.cancel_allowed) = cancel_key;
    (g_mmi_bt_scr_cntx.prog_scr.fp) = (void*)fp;

    if (context_id)
    {
        mmi_ucs2cpy((S8*) (g_mmi_bt_scr_cntx.prog_scr.context_str), (S8*) GetString(context_id));
    }
    else if (context_str)
    {
        mmi_ucs2cpy((S8*) (g_mmi_bt_scr_cntx.prog_scr.context_str), (S8*) context_str);
    }
    else
    {
        /* error usage! */
        MMI_BT_ASSERT(0);
    }

    /* keep backlight on while processing */
    TurnOnBacklight(0);

    mmi_bt_entry_progress_scr();

    if (scrid == SCR_BT_SCH_PRO)
    {
        SetDelScrnIDCallbackHandler(SCR_BT_SCH_PRO, (HistoryDelCBPtr) mmi_bt_inq_progress_del_cb);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_stop_progress_scr
 * DESCRIPTION
 *  This function is to stop progressing screen
 * PARAMETERS
 *  is_goback       [IN]            
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_stop_progress_scr(BOOL is_goback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scr_id = GetActiveScreenId();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_SCR_STOP_PROGRESS, (g_mmi_bt_scr_cntx.prog_scr.scr_id),
               (g_mmi_bt_scr_cntx.prog_scr.title_str_id), (g_mmi_bt_scr_cntx.prog_scr.context_id));

    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_SCR_GTIMER_STOP);
    StopTimer(BT_CMD_GUARD_TIMER);

    /* Will start a timer then turn LCM backlight off */
    TurnOffBacklight();


    if (!(g_mmi_bt_scr_cntx.prog_scr.scr_id))
    {
        return;
    }

    if (scr_id == (g_mmi_bt_scr_cntx.prog_scr.scr_id))
    {
        EntryNewScreen(GLOBAL_SCR_DUMMY, NULL, NULL, NULL);
    }

    DeleteScreenIfPresent((g_mmi_bt_scr_cntx.prog_scr.scr_id));

    if (is_goback && (scr_id == (g_mmi_bt_scr_cntx.prog_scr.scr_id)))
    {
        GoBackHistory();
    }


}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_progress_scr
 * DESCRIPTION
 *  This function is to entry progressing screen
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_progress_scr()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_SCR_SHOW_PROGRESSING2, ((g_mmi_bt_scr_cntx.prog_scr.scr_id)),
               ((g_mmi_bt_scr_cntx.prog_scr.title_str_id)), ((g_mmi_bt_scr_cntx.prog_scr.context_id)));

    /* The context_str shall not be NULL because giving string ID will translate into string pointer by GetString() */
    MMI_BT_ASSERT(((g_mmi_bt_scr_cntx.prog_scr.scr_id) != 0)
                  && ((g_mmi_bt_scr_cntx.prog_scr.title_str_id) != 0)
                  && (mmi_ucs2strlen((S8*) (g_mmi_bt_scr_cntx.prog_scr.context_str)) != 0));

    /* Call Exit Handler */
    EntryNewScreen((g_mmi_bt_scr_cntx.prog_scr.scr_id), mmi_bt_exit_progress_scr, mmi_bt_entry_progress_scr, NULL);

	/* allow to cancel the inquiry by pressing end key */
    if (g_mmi_bt_scr_cntx.prog_scr.scr_id != SCR_BT_SCH_PRO)
    {
	    /* Clear all key handlers so as to restrict duplicate reqs */
	    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
	    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
    }

    /* Command does not support abort */
    if (g_mmi_bt_scr_cntx.prog_scr.cancel_allowed)
    {
        ShowCategory66Screen(
            (g_mmi_bt_scr_cntx.prog_scr.title_str_id),
            GetRootTitleIcon(MENU_CONN_BT_MAIN),
            0,
            0,
            STR_GLOBAL_CANCEL,
            IMG_GLOBAL_BACK,
            (U8*) (g_mmi_bt_scr_cntx.prog_scr.context_str),
            IMG_GLOBAL_PROGRESS,
            NULL);

        if (g_mmi_bt_scr_cntx.prog_scr.fp)
        {
            SetRightSoftkeyFunction((FuncPtr) (g_mmi_bt_scr_cntx.prog_scr.fp), KEY_EVENT_UP);
        }
        else
        {
            MMI_BT_ASSERT(0);
        }

    }
    else
    {
        ShowCategory66Screen(
            (g_mmi_bt_scr_cntx.prog_scr.title_str_id),
            GetRootTitleIcon(MENU_CONN_BT_MAIN),
            0,
            0,
            0,
            0,
            (U8*) (g_mmi_bt_scr_cntx.prog_scr.context_str),
            IMG_GLOBAL_PROGRESS,
            NULL);
    }

    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_SCR_GTIMER_START);

    StartTimer(BT_CMD_GUARD_TIMER, MMI_BT_BT_CMD_GUARD_TIMER_DUR, mmi_bt_scr_proc_guard_tout_hdlr);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_exit_progress_scr
 * DESCRIPTION
 *  This function is to exit progressing screen
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_exit_progress_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(BT_CMD_GUARD_TIMER);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_scr_proc_guard_tout_hdlr
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_scr_proc_guard_tout_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 state, num_paired_dev;
    U32 i;
    mmi_bt_dev_struct *dev_p;
    U16 scrid = mmi_bt_get_progress_scr();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_SCR_GTIMER_TO);

    state = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_state) ();
    switch (state)
    {
        case MMI_BT_STAT_INIT_ON:
            break;
        case MMI_BT_STAT_ACTIVATE_SWITCHING:
            break;
        case MMI_BT_STAT_DEACTIVATING:
            /* start a power off timer to guard the power off period */
    #if 0
    #ifdef __MMI_BT_BG_PWRON__
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
    #else /* __MMI_BT_BG_PWRON__ */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_BT_BG_PWRON__ */ 
/* under construction !*/
    #endif /* 0 */ 
            break;
        case MMI_BT_STAT_INQUIRING:
        case MMI_BT_STAT_INQUIR_RES_IND:
            if (g_mmi_bt_scr_cntx.state != MMI_BT_SCR_STATE_CANCEL_INQ_WAIT_CFM)
            {
                (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_inquiry_cancel_req) ((U8) g_mmi_bt_scr_cntx.flag);
                g_mmi_bt_scr_cntx.flag |= MMI_BT_CANCEL_INQ_BEFORE_BT_CLOSE;
                g_mmi_bt_scr_cntx.state = MMI_BT_SCR_STATE_CANCEL_INQ_WAIT_CFM;
                /* reset inquiry flag */
                g_mmi_bt_scr_cntx.flag &= ~MMI_BT_INQ_TYPE_AUDIO;
                g_mmi_bt_scr_cntx.flag &= ~MMI_BT_INQ_TYPE_ALL_DEV;
                g_mmi_bt_scr_cntx.flag &= ~MMI_BT_INQ_TYPE_OPP_DEV;
                g_mmi_bt_scr_cntx.flag &= ~MMI_BT_INQ_TYPE_A2DP_DEV;
                g_mmi_bt_scr_cntx.flag &= ~MMI_BT_INQ_TYPE_HID_DEV;
                g_mmi_bt_scr_cntx.flag_extended &= ~MMI_BT_EXT_INQ_TYPE_PRINTER_DEV;
                g_mmi_bt_scr_cntx.flag_extended &= ~MMI_BT_EXT_INQ_TYPE_SPEC_COD_DEV;

            }
            else
            {
                g_mmi_bt_scr_cntx.state = MMI_BT_SCR_STATE_NORMAL;
            }
            break;
        case MMI_BT_STAT_BONDING:
            break;
        case MMI_BT_STAT_PAIRING:
            break;
        case MMI_BT_STAT_SDC_SEARCHING:
            /* close SDC channel */
            (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_close_sdc_req) ();
            break;
        case MMI_BT_STAT_CONNECTING:
            break;
        case MMI_BT_STAT_DEBONDING:
            dev_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_info) ((U16) g_mmi_bt_scr_cntx.hilight_item);
            g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_mydev_remove_req(&(dev_p->bd_addr));
            break;
        case MMI_BT_STAT_DEBONDING_ALL:
            num_paired_dev = (U8) g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_num();
            for (i = 0; i < num_paired_dev; i++)
            {
                dev_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_info) ((U16) 0);
                g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_mydev_remove_req(&(dev_p->bd_addr));
            }
            break;
        case MMI_BT_STAT_DISCONNECTING:
            break;
        case MMI_BT_STAT_AUDIO_CON_ESTAB:
            break;
        case MMI_BT_STAT_SDC_REFRESHING:
            /* close SDC channel */
            (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_close_sdc_req) ();
            break;
        default:
            if (g_mmi_bt_scr_cntx.state == MMI_BT_SCR_STATE_INQ_WAIT_CFM)
            {
                (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_inquiry_cancel_req) ((U8) g_mmi_bt_scr_cntx.flag);
                g_mmi_bt_scr_cntx.flag |= MMI_BT_CANCEL_INQ_BEFORE_BT_CLOSE;
                g_mmi_bt_scr_cntx.state = MMI_BT_SCR_STATE_CANCEL_INQ_WAIT_CFM;
            }
            break;

    }


    /* shall reset delete callback before mmi_bt_stop_progress_scr */
    /* stop-progress-screen is to entry a dummy screen and delete the progress screen */
    /* if the delete callback is not expected to invoked while stopping progress screen, then shall reset it first */
    SetDelScrnIDCallbackHandler(SCR_BT_SCH_PRO, (HistoryDelCBPtr) NULL);
    SetDelScrnIDCallbackHandler(SCR_BT_SCH_RES, (HistoryDelCBPtr) NULL);

    /* shall not go back history */
    mmi_bt_stop_progress_scr(MMI_FALSE);

    if (state == MMI_BT_STAT_INQUIRING || g_mmi_bt_scr_cntx.state == MMI_BT_SCR_STATE_INQ_WAIT_CFM)
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_EMPTY),
            IMG_GLOBAL_EMPTY,
            MMI_FALSE,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) EMPTY_LIST_TONE);
    }
    else if (state == MMI_BT_STAT_DEBONDING || state == MMI_BT_STAT_DEBONDING_ALL)
    {
        DisplayPopup(
            (U8*) GetString(STR_BT_DELETED),
            IMG_GLOBAL_ACTIVATED,
            MMI_FALSE,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) SUCCESS_TONE);
        DeleteScreenIfPresent(SCR_BT_MYDEV_OPT);
        DeleteScreenIfPresent(SCR_BT_MYDEV_DEL);
        DeleteScreenIfPresent(SCR_BT_MYDEV_DEL_ALL);
    }
    else if (state == MMI_BT_STAT_SDC_SEARCHING)
    {
        GoBackHistory();
    }
    else
    {
        if (scrid >= SCR_BT_MAIN && scrid <= SCR_BT_SWITCH_SPEECH_PATH)
        {
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_CANCEL /* STR_GLOBAL_ERROR */ ),
                IMG_GLOBAL_ERROR,
                MMI_FALSE,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
        }
    }

    DeleteScreenIfPresent(scrid);

    if (state != MMI_BT_STAT_INQUIRING && state != MMI_BT_STAT_INQUIR_RES_IND &&
        g_mmi_bt_scr_cntx.state != MMI_BT_SCR_STATE_INQ_WAIT_CFM)
    {
        /* reset scr flag */
        mmi_bt_reset_scr_flag();
    }

    /* reset extend proc timer */
    g_mmi_bt_scr_cntx.extend_proc_timer = 0;
    if (g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_set_state)
    {
        (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_set_state) ((U32) MMI_BT_STAT_IDLE);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_get_progress_scr
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_bt_get_progress_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (g_mmi_bt_scr_cntx.prog_scr.scr_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_show_confirm_scr
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  scr_id          [IN]            
 *  msg_id          [IN]            
 *  exit_hdlr       [IN]            
 *  entry_hdlr      [IN]            
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_show_confirm_scr(U16 scr_id, U16 msg_id, FuncPtr exit_hdlr, FuncPtr entry_hdlr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_bt_scr_cntx.conf_scr.scr_id = scr_id;
    g_mmi_bt_scr_cntx.conf_scr.context_id = msg_id;
    g_mmi_bt_scr_cntx.conf_scr.fp = (void*)exit_hdlr;
    g_mmi_bt_scr_cntx.conf_scr.entry_fp = (void*)entry_hdlr;

    mmi_bt_entry_confirm();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_confirm
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_ENTRY_CONFIRM, g_mmi_bt_scr_cntx.conf_scr.scr_id, g_mmi_bt_scr_cntx.flag);

	
    guiBuffer = GetCurrGuiBuffer(g_mmi_bt_scr_cntx.conf_scr.scr_id);

    EntryNewScreen(
        g_mmi_bt_scr_cntx.conf_scr.scr_id,
        (FuncPtr) g_mmi_bt_scr_cntx.conf_scr.fp,
        (FuncPtr) g_mmi_bt_scr_cntx.conf_scr.entry_fp,
        NULL);
    ShowCategory165Screen(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (UI_string_type) GetString(g_mmi_bt_scr_cntx.conf_scr.context_id),
        (U16) IMG_GLOBAL_QUESTION,
        guiBuffer);
    /* play a warning tone */
    playRequestedTone(WARNING_TONE);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_error
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_error(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    
    if(GetActiveScreenId() == SCR_BT_SWITCH_SPEECH_PATH)
    {
        mmi_bt_stop_progress_scr(MMI_TRUE);
    }
    else
    {
        DeleteScreenIfPresent(SCR_BT_SWITCH_SPEECH_PATH);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_sco_ind
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  res         [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_sco_ind(MMI_BOOL res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_SCR_SCO_IND, res, g_mmi_bt_scr_cntx.flag, g_mmi_bt_scr_cntx.flag_extended);

    if (g_mmi_bt_scr_cntx.flag & MMI_BT_SCO_FAR_END_LP_TESTING)
    {


        if (res)
        {

            StartTimer(BT_LP2_DELAY_TIMER, MMI_BT_BT_LP2_DELAY_TIMER_DUR, mmi_bt_loopback_delay_timeout_hdler);

        }
        else
        {

            /* indicate L4 AT module succeeded or failed */
            if (g_mmi_bt_scr_cntx.test_by_at)
            {
		        mmi_at_general_res_req_struct *res_p;

		        res_p = construct_local_para(sizeof(mmi_at_general_res_req_struct), TD_UL);
	            /* indicate L4 AT module failed */
	            res_p->result = MMI_FALSE;
                /* indicate L4 AT module succeeded or failed */
                mmi_bt_send_l4_msg(MSG_ID_MMI_AT_GENERAL_RES_REQ, (void*)res_p, NULL);
                g_mmi_bt_scr_cntx.test_by_at = 0;
            }
            else
            {
				if (g_mmi_bt_scr_cntx.test_by_em)
				{
		            /* call back engineering...failed */
		            EmBTNotifyLoopbackDoneCnf(MMI_FALSE);
					g_mmi_bt_scr_cntx.test_by_em = 0;
				}
            }

            /* reset flag */
            /* mmi_bt_reset_scr_flag(); */

            (g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_mydev_remove_req) (&(g_mmi_bt_scr_cntx.far_end_dev_add));

            /* deactivate bluetooth services */
            (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_deactivate_req) ();

        }
        return;

    }

    if(GetActiveScreenId() == SCR_BT_SWITCH_SPEECH_PATH)
    {
        if (mmi_profiles_bt_allow_popup())
        {
            mmi_bt_stop_progress_scr(MMI_FALSE);
        }
        else
        {
            mmi_bt_stop_progress_scr(MMI_TRUE);
        }
    }

    if (res == MMI_TRUE)
    {
        /* shall not popup sco connected or disconnected screen in sound recoder app and voice recognize app */
        if (mmi_profiles_bt_allow_popup())
        {
            DisplayPopup(
                (U8*) GetString(STR_BT_AUDIO_SCO_CON),
                IMG_GLOBAL_ACTIVATED,
                MMI_FALSE,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) SUCCESS_TONE);
        }

        if (g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_SPEECH_SWITCH)
        {
            mmi_bt_update_status_icon();

            /* for BT profile */
        #if defined(__MMI_BT_PROFILE__)
            mmi_profiles_bt_connect_callback(MMI_PROFILES_BT_HFP_ACL, MMI_PROFILES_BT_IND, MMI_PROFILES_BT_OK);
        #endif 
            DeleteScreenIfPresent(SCR_BT_CONNECT_AUTHORIZE);
            /* reset screen flag */
            //mmi_bt_reset_scr_flag();
            g_mmi_bt_scr_cntx.flag &= ~MMI_BT_CONFIRM_SPEECH_SWITCH;
        }

    }
    else
    {
        /* shall not popup sco connected or disconnected screen in sound recoder app and voice recognize app */
        if (mmi_profiles_bt_allow_popup())
        {
            DisplayPopup(
                (U8*) GetString(STR_BT_AUDIO_SCO_DISCON),
                IMG_GLOBAL_ACTIVATED,
                MMI_FALSE,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) SUCCESS_TONE);
        }
    }

    DeleteScreenIfPresent(SCR_BT_SWITCH_SPEECH_PATH);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_panic_ind_pre_process
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_panic_ind_pre_process(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* re-init A2DP */
    /* re-init BT profile */
    mmi_profiles_bt_reset();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_panic_ind_post_process
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_panic_ind_post_process()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 pop_up_device_busy_flag = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_bt_scr_cntx.flag & MMI_BT_SCO_FAR_END_LP_TESTING || g_mmi_bt_scr_cntx.flag & MMI_BT_RELEASE_ALL_CONN_TIMEOUT)
    {
        pop_up_device_busy_flag = 0;
    }

    /* de-init BT Profiles */
    mmi_bt_deinit();
    /* re-init BT Profiles */
    mmi_bt_init();

    /* send restart req to ps stack */
    (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_recover_panic_req) ();

    /* update status icon */
    mmi_bt_update_status_icon();
    /* display busy */
    if (pop_up_device_busy_flag)
    {
        DisplayPopup(
            (U8*) GetString(STR_BT_DEV_BUSY),
            IMG_GLOBAL_WARNING,
            MMI_FALSE,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
    }
    mmi_bt_del_scr(SCR_BT_MAIN, SCR_BT_ABOUT);
    /* to reset the scr_cntx flag while set by screen delete callback */
    mmi_bt_reset_scr_flag();


}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_reset_scr_flag
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_reset_scr_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_SCR_STATUS,
               g_mmi_bt_scr_cntx.state, g_mmi_bt_scr_cntx.flag, g_mmi_bt_scr_cntx.blinking_flag);
    g_mmi_bt_scr_cntx.flag = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_del_scr
 * DESCRIPTION
 *  This function is to delete screen pack
 * PARAMETERS
 *  start_scrid     [IN]            
 *  end_scrid       [IN]            
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_del_scr(U32 start_scrid, U32 end_scrid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = start_scrid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (end_scrid < start_scrid)
    {
        return;
    }

    for (i = start_scrid; i <= end_scrid; i++)
    {
        DeleteScreenIfPresent((U16) i);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_store_endkey_hdlr
 * DESCRIPTION
 *  This function is to store screen END key handler
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_store_endkey_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_SCR_STO_ENDKEY);

    MMI_BT_ASSERT(((g_mmi_bt_scr_cntx.keyup_fp) == NULL) && ((g_mmi_bt_scr_cntx.keydown_fp) == NULL));
    (g_mmi_bt_scr_cntx.keydown_fp) = GetKeyHandler(KEY_END, KEY_EVENT_DOWN);
    (g_mmi_bt_scr_cntx.keyup_fp) = GetKeyHandler(KEY_END, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_restore_endkey_hdlr
 * DESCRIPTION
 *  This function is to restore screen END key handler
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_restore_endkey_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_SCR_RESTO_ENDKEY);

    SetKeyHandler(g_mmi_bt_scr_cntx.keydown_fp, KEY_END, KEY_EVENT_DOWN);
    SetKeyHandler(g_mmi_bt_scr_cntx.keyup_fp, KEY_END, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_clear_endkey_hdlr
 * DESCRIPTION
 *  This function is to clear screen END key handler
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_clear_endkey_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_SCR_CLR_ENDKEY);

    (g_mmi_bt_scr_cntx.keydown_fp) = NULL;
    (g_mmi_bt_scr_cntx.keyup_fp) = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_exe_endkey_hdlr
 * DESCRIPTION
 *  This function is to execute screen END key handler
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_exe_endkey_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_SCR_EXE_ENDKEY);

    if ((g_mmi_bt_scr_cntx.keydown_fp))
    {
        (*g_mmi_bt_scr_cntx.keydown_fp) ();
        (g_mmi_bt_scr_cntx.keydown_fp) = NULL;
    }

    if ((g_mmi_bt_scr_cntx.keyup_fp))
    {
        (*g_mmi_bt_scr_cntx.keyup_fp) ();
        (g_mmi_bt_scr_cntx.keyup_fp) = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_check_supported_profile
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  service_list        [?]             
 *  profile_id          [IN]            
 *  a(?)                [IN/OUT]        First variable, used as returns
 *  b(?)                [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bt_check_supported_profile(U32 *service_list, U32 profile_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (service_list[i] != MMI_BT_MAX_PROFILE_UUID)
    {
        if (service_list[i] == profile_id)
        {
            return MMI_TRUE;
        }
        i++;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_check_supported_connection_type
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  connect_type_list       [?]             
 *  connect_type            [IN]            
 *  a(?)                    [IN/OUT]        First variable, used as returns
 *  b(?)                    [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bt_check_supported_connection_type(U32 *connect_type_list, U32 connect_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (connect_type_list[i] != MMI_BT_MAX_PROFILE_UUID)
    {
        if (connect_type_list[i] == connect_type)
        {
            return MMI_TRUE;
        }
        i++;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_connecting_pre_check
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  dev_addr        [?]             
 *  pro_uuid        [IN]            
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
mmi_bt_result_codes mmi_bt_connecting_pre_check(mmi_bt_dev_addr *dev_addr, U32 pro_uuid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bt_result_codes result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (pro_uuid)
    {
        case MMI_BT_HF_PROFILE_UUID:
        case MMI_BT_HFG_PROFILE_UUID:
        case MMI_BT_HS_PROFILE_UUID:
        case MMI_BT_HEADSET_AG_SERVICE_UUID:
            if (mmi_bt_is_hs_connected())
            {
                result = MMI_BT_ONE_HEADSET_CONNECTED;
            }
            else
            {
                result = MMI_BT_RESULT_SUCCESS;
            }
            break;
        case MMI_BT_ADVANCED_AUDIO_PROFILE_UUID:
            if (mmi_bt_is_a2dp_connected())
            {
                result = MMI_BT_ONE_A2DP_CONNECTED;
            }
            else
            {
                result = MMI_BT_RESULT_SUCCESS;
            }
            break;
        default:
            result = MMI_BT_RESULT_SUCCESS;
            break;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_get_profile_str_id
 * DESCRIPTION
 *  This function is to get profile str id for UI display
 * PARAMETERS
 *  profile_uuid        [IN]            
 *  str                 [IN]            
 *  a(?)                [IN/OUT]        First variable, used as returns
 *  b(?)                [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bt_get_profile_str_id(U16 profile_uuid, U8 **str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = 0;
    while (profile_str_id_map[i][0] != MMI_BT_MAX_PROFILE_UUID)
    {
        if (profile_str_id_map[i][0] == profile_uuid)
        {
            break;
        }
        i++;
    }

    if (profile_str_id_map[i][0] == MMI_BT_MAX_PROFILE_UUID)
    {
        result = MMI_FALSE;
        *str = (U8*) GetString((U16) STR_BT_PROF_UNKNOWN);
    }
    else
    {
        result = MMI_TRUE;
        *str = (U8*) GetString((U16) profile_str_id_map[i][1]);
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_get_connect_type_str_id
 * DESCRIPTION
 *  This function is to get profile str id for UI display
 * PARAMETERS
 *  conn_type       [IN]            
 *  str             [IN]            
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bt_get_connect_type_str_id(mmi_bt_connection_type conn_type, U8 **str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = 0;
    while (connect_type_str_id_map[i][0] != MMI_BT_LAST_CONNECTOIN_TYPE)
    {
        if (connect_type_str_id_map[i][0] == conn_type)
        {
            break;
        }
        i++;
    }

    if (connect_type_str_id_map[i][0] == MMI_BT_LAST_CONNECTOIN_TYPE)
    {
        result = MMI_FALSE;
        *str = (U8*) GetString((U16) STR_BT_PROF_UNKNOWN);
    }
    else
    {
        result = MMI_TRUE;
        *str = (U8*) GetString((U16) connect_type_str_id_map[i][1]);
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_update_status_icon
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_update_status_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_GEN_UPDATE_STATUS_ICON,
               mmi_bt_is_hw_ready(MMI_FALSE),
               (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_ram_flag) (MMI_BT_RAMMASK_IS_ICON_BLINKING),
               (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_pwron) (),
               (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_any_connection_active) (),
               mmi_bt_is_a2dp_connected(),
               (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_hs_connected) (), isEarphonePlugged);

    if (mmi_bt_is_hw_ready(MMI_FALSE))
    {
        /* update BT status icon */
        if ((*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_ram_flag) (MMI_BT_RAMMASK_IS_ICON_BLINKING))
        {
            if ((*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_any_connection_active) ())
            {
                MMI_BT_SCR_CHANGE_ICON_CON();
            }
            else
            {
                MMI_BT_SCR_CHANGE_ICON_SCAN((*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_vis) ());
            }
            MMI_BT_SCR_CHANGE_ICON_BLINKING();
        }
        else
        {
            if ((*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_pwron) ())
            {
                if ((*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_any_connection_active) ())
                {
                    MMI_BT_SCR_CHANGE_ICON_CON();
                }
                else
                {
                    MMI_BT_SCR_CHANGE_ICON_SCAN((*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_vis) ());
                }
            }
            else
            {
                MMI_BT_SCR_CHANGE_ICON_HIDEALL();
            }
        }
        /* update headset icon in idle screen */
        if (mmi_bt_is_a2dp_connected() || (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_hs_connected) ())
        {
            ShowStatusIcon(STATUS_ICON_EARPHONE_INDICATOR);
        }
        else
        {
            if (!isEarphonePlugged)
            {
                HideStatusIcon(STATUS_ICON_EARPHONE_INDICATOR);
            }
        }
    }
    else
    {
        MMI_BT_SCR_CHANGE_ICON_HIDEALL();
        if (!isEarphonePlugged)
        {
            HideStatusIcon(STATUS_ICON_EARPHONE_INDICATOR);
        }

    }

	UpdateStatusIcons();
	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_prohibit_service_complete
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  result      [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_prohibit_service_complete(MMI_BOOL result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bt_update_status_icon();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_is_paired_device
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  dev_addr        [?]             
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bt_is_paired_device(mmi_bt_dev_addr *dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 paired_dev_num;
    U32 i;
    mmi_bt_dev_struct *dev_struct_p;
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    paired_dev_num = (U8) g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_num();

    for (i = 0; i < paired_dev_num; i++)
    {
        dev_struct_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_info) ((U16) i);
        if (dev_struct_p->bd_addr.lap == dev_addr->lap
            && dev_struct_p->bd_addr.uap == dev_addr->uap && dev_struct_p->bd_addr.nap == dev_addr->nap)
        {
            result = MMI_TRUE;
            break;
        }

    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_status_icon_start_blinking
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  profile_id          [IN]            
 *  profile_role        [IN]            
 *  a(?)                [IN/OUT]        First variable, used as returns
 *  b(?)                [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_status_icon_start_blinking(U32 profile_id, MMI_BT_PROFILE_ROLE profile_role)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if bt is initialized */
    if (g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_pwron == NULL)
    {
        return;
    }

    /* server role */
    if (profile_role == MMI_BT_SERVER_ROLE)
    {
        switch (profile_id)
        {
            case MMI_BT_OBEX_FILE_TRANSFER_UUID:
                g_mmi_bt_scr_cntx.blinking_flag |= MMI_BT_BLINKING_FTP_SERVER;
                break;
            case MMI_BT_OBEX_OBJECT_PUSH_SERVICE_UUID:
                g_mmi_bt_scr_cntx.blinking_flag |= MMI_BT_BLINKING_OPP_SERVER;
                break;
            case MMI_BT_OBEX_IMAGING_RESPONDER_UUID:
                g_mmi_bt_scr_cntx.blinking_flag |= MMI_BT_BLINKING_BIP_SERVER;
                break;
            default:
                break;
        }

    }
    /* client role */
    else
    {
        switch (profile_id)
        {
            case MMI_BT_OBEX_FILE_TRANSFER_UUID:
                g_mmi_bt_scr_cntx.blinking_flag |= MMI_BT_BLINKING_FTP_CLIENT;
                break;
            case MMI_BT_OBEX_OBJECT_PUSH_SERVICE_UUID:
                g_mmi_bt_scr_cntx.blinking_flag |= MMI_BT_BLINKING_OPP_CLIENT;
                break;
            case MMI_BT_OBEX_IMAGING_UUID:
                g_mmi_bt_scr_cntx.blinking_flag |= MMI_BT_BLINKING_BIP_CLIENT;
                break;
            case MMI_BT_BASIC_PRINTING:
                g_mmi_bt_scr_cntx.blinking_flag |= MMI_BT_BLINKING_BPP_CLIENT;
                break;
				
            default:
                break;

        }

    }
    /* set device to be non-connectable */
    /* (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_set_connectable_req)(MMI_FALSE); */
    /* set blinking bit mask */
    (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_set_ram_flag_req) (MMI_BT_RAMMASK_IS_ICON_BLINKING);
    /* update status icon */
    mmi_bt_update_status_icon();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_status_icon_stop_blinking
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  profile_id          [IN]            
 *  profile_role        [IN]            
 *  a(?)                [IN/OUT]        First variable, used as returns
 *  b(?)                [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_status_icon_stop_blinking(U32 profile_id, MMI_BT_PROFILE_ROLE profile_role)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if bt is initialized */
    if (g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_pwron == NULL)
    {
        return;
    }

    /* server role */
    if (profile_role == MMI_BT_SERVER_ROLE)
    {
        switch (profile_id)
        {
            case MMI_BT_OBEX_FILE_TRANSFER_UUID:
                g_mmi_bt_scr_cntx.blinking_flag &= ~MMI_BT_BLINKING_FTP_SERVER;
                break;
            case MMI_BT_OBEX_OBJECT_PUSH_SERVICE_UUID:
                g_mmi_bt_scr_cntx.blinking_flag &= ~MMI_BT_BLINKING_OPP_SERVER;
                break;
            case MMI_BT_OBEX_IMAGING_RESPONDER_UUID:
                g_mmi_bt_scr_cntx.blinking_flag &= ~MMI_BT_BLINKING_BIP_SERVER;
                break;
            default:
                break;
        }

    }
    /* client role */
    else
    {
        switch (profile_id)
        {
            case MMI_BT_OBEX_FILE_TRANSFER_UUID:
                g_mmi_bt_scr_cntx.blinking_flag &= ~MMI_BT_BLINKING_FTP_CLIENT;
                break;
            case MMI_BT_OBEX_OBJECT_PUSH_SERVICE_UUID:
                g_mmi_bt_scr_cntx.blinking_flag &= ~MMI_BT_BLINKING_OPP_CLIENT;
                break;
            case MMI_BT_OBEX_IMAGING_UUID:
                g_mmi_bt_scr_cntx.blinking_flag &= ~MMI_BT_BLINKING_BIP_CLIENT;
                break;
            case MMI_BT_BASIC_PRINTING:
                g_mmi_bt_scr_cntx.blinking_flag &= ~MMI_BT_BLINKING_BPP_CLIENT;
                break;
            default:
                break;

        }

    }

    if (g_mmi_bt_scr_cntx.blinking_flag == 0)
    {
        /* set device to be connectable */
        /* (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_set_connectable_req)(MMI_TRUE); */
        /* reset blinking bit mask */
        (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_reset_ram_flag_req) (MMI_BT_RAMMASK_IS_ICON_BLINKING);
    }
    mmi_bt_update_status_icon();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_is_permission
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  is_popup        [IN]            
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bt_is_permission(MMI_BOOL is_popup)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL res = MMI_TRUE;
    U8 btcore_state;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    btcore_state = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_state)();
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_SCR_PERMISSION_STATUS, 
                mmi_bt_is_hw_ready(MMI_FALSE),
                btcore_state);
    
    if (!mmi_bt_is_hw_ready(is_popup))
    {
        if (is_popup == MMI_TRUE)
        {
            DisplayPopup(
                (U8*) GetString(STR_BT_NOT_READY),
                IMG_GLOBAL_WARNING,
                MMI_FALSE,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) WARNING_TONE);
        }
        res = MMI_FALSE;
    }
	else if ( btcore_state == MMI_BT_STAT_PASSKEY_IND )
	{
    	mmi_bt_passkey_input_scr_del_callback();
		if( is_popup == MMI_TRUE )
		{
	   		DisplayPopup( (U8*)GetString(STR_BT_WAIT_PAIR_RESULT),  IMG_GLOBAL_WARNING, \
	                           			MMI_FALSE, UI_POPUP_NOTIFYDURATION_TIME, (U8)WARNING_TONE );
		}

		res = MMI_FALSE;
	}
	else if ( btcore_state == MMI_BT_STAT_PASSKEY_RES )
	{
		if( is_popup == MMI_TRUE )
		{
	   		DisplayPopup( (U8*)GetString(STR_BT_WAIT_PAIR_RESULT),  IMG_GLOBAL_WARNING, \
	                           			MMI_FALSE, UI_POPUP_NOTIFYDURATION_TIME, (U8)WARNING_TONE );
		}

		res = MMI_FALSE;
	}
    else if(g_mmi_bt_scr_cntx.state == MMI_BT_SCR_STATE_CANCEL_INQ_WAIT_CFM)
    {
		if( is_popup == MMI_TRUE )
		{
	   		DisplayPopup( (U8*)GetString(STR_BT_WAIT_INQUIRY_FINISH),  IMG_GLOBAL_WARNING, \
	                           			MMI_FALSE, UI_POPUP_NOTIFYDURATION_TIME, (U8)WARNING_TONE );
		}

		res = MMI_FALSE;
    }
    else if( btcore_state == MMI_BT_STAT_DISCONNECTING || btcore_state == MMI_BT_STAT_RELEASE_ALL_CONNECTION)
    {
		if( is_popup == MMI_TRUE )
		{
            DisplayPopup(
                (U8*) GetString(STR_BT_DEV_BUSY),
                IMG_GLOBAL_WARNING,
                MMI_FALSE,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) WARNING_TONE);
		}

		res = MMI_FALSE;
    }
	else if ( (g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_SIMAP_SET) || btcore_state == MMI_BT_STAT_ACTIVATING_SIMAP ||  btcore_state == MMI_BT_STAT_DEACTIVATING_SIMAP)
	{
		if( is_popup == MMI_TRUE )
		{
            DisplayPopup(
                (U8*) GetString(STR_BT_DEV_BUSY),
                IMG_GLOBAL_WARNING,
                MMI_FALSE,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) WARNING_TONE);
		}

		res = MMI_FALSE;
	}
    /* Configure Default Headset */
	else if ( btcore_state == MMI_BT_STAT_CONNECTING )
	{
		if( is_popup == MMI_TRUE )
		{
            DisplayPopup(
                (U8*) GetString(STR_BT_DEV_BUSY),
                IMG_GLOBAL_WARNING,
                MMI_FALSE,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) WARNING_TONE);
		}

		res = MMI_FALSE;
	}
    #if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_HIDD_SUPPORT__)
    else if(mmi_bt_hid_is_busy())
    {
		if( is_popup == MMI_TRUE )
		{
            DisplayPopup(
                (U8*) GetString(STR_BT_DEV_BUSY),
                IMG_GLOBAL_WARNING,
                MMI_FALSE,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) WARNING_TONE);
		}

		res = MMI_FALSE;
    }
    #endif


    return res;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_is_power_on
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  is_popup        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bt_is_power_on(MMI_BOOL is_popup)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL res = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_bt_is_hw_ready(is_popup))
    {
        if (is_popup == MMI_TRUE)
        {
            DisplayPopup(
                (U8*) GetString(STR_BT_NOT_READY),
                IMG_GLOBAL_WARNING,
                MMI_FALSE,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) WARNING_TONE);
        }
        res = MMI_FALSE;
    }
    else if ((*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_pwron) () == MMI_FALSE)
    {
        if (is_popup == MMI_TRUE)
        {
            /* not need to keep confirm screen in history while interrupted by other screen */
            DisplayConfirm(
                STR_GLOBAL_YES,
                IMG_GLOBAL_YES,
                STR_GLOBAL_NO,
                IMG_GLOBAL_NO,
                (UI_string_type) GetString(STR_BT_PWR_ON_CNF),
                IMG_GLOBAL_QUESTION,
                WARNING_TONE);

            SetLeftSoftkeyFunction(mmi_bt_entry_power_switch, KEY_EVENT_UP);
            SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        }

        res = MMI_FALSE;
    }

    return res;

}




/*****************************************************************************
 * FUNCTION
 *  mmi_bt_is_hw_ready
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  is_popup        [IN]            
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bt_is_hw_ready(MMI_BOOL is_popup)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL res = MMI_TRUE;
    MMI_BOOL power_status;
    U32      stack_ready;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    power_status = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_pwron)();
    stack_ready = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_ram_flag) (MMI_BT_RAMMASK_IS_READY);
    
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_SCR_POWER_AND_READY_STATUS, 
                power_status,
                stack_ready);
    
#ifndef __MMI_BT_BG_PWRON__
    if (!stack_ready && power_status == MMI_TRUE)
#else /* __MMI_BT_BG_PWRON__ */ 
    if (!stack_ready )
#endif /* __MMI_BT_BG_PWRON__ */ 
    {
        if (is_popup == MMI_TRUE)
        {
            DisplayPopup(
                (U8*) GetString(STR_BT_NOT_READY),
                IMG_GLOBAL_WARNING,
                MMI_FALSE,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) WARNING_TONE);
        }

        res = MMI_FALSE;
    }
    return res;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_set_headset_speaker_volume
 * DESCRIPTION
 *  This function is to set remote headset speaker volume
 * PARAMETERS
 *  ui_volume_level     [IN]            
 *  a(?)                [IN/OUT]        First variable, used as returns
 *  b(?)                [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_set_headset_speaker_volume(S32 ui_volume_level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 act_con_num;
    U8 paired_dev_num;
    U8 paired_dev_index;
    mmi_bt_dev_struct *dev_p;
    mmi_bt_connect_struct *conn_p = NULL;
    U32 i;
    U8 speaker_gain;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* return if bt headset is not connected */
    if (mmi_bt_is_hs_connected() == MMI_FALSE)
    {
        return;
    }

    act_con_num = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_existed_dev_num) ();
    paired_dev_num = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_num) ();
    MMI_BT_ASSERT(paired_dev_num);
    /* get index of existed_conn */
    for (i = 0; i < act_con_num; i++)
    {
        conn_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_existed_conn_info) ((U16) i);
        /* assume that there is only one HFP or HSP connection at one time */
        if ((conn_p->conn_type == MMI_BT_HFP_CONNECTION || conn_p->conn_type == MMI_BT_HSP_CONNECTION)
            && (conn_p->active == MMI_TRUE))
        {
            break;
        }
    }

    /* check if any HFP connection connected */
    /* if not, do nothing */
    if (i == act_con_num)
    {
        return;
    }

    paired_dev_index = conn_p->index_of_paried_list;
    MMI_BT_ASSERT(paired_dev_index < paired_dev_num);
    dev_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_info) (paired_dev_index);

    /* speaker gain shall be normalized to 0~15 */
    switch (ui_volume_level)
    {
        case LEVEL1:
            speaker_gain = 0;
            break;
        case LEVEL2:
            speaker_gain = 3;
            break;
        case LEVEL3:
            speaker_gain = 7;
            break;
        case LEVEL4:
            speaker_gain = 9;
            break;
        case LEVEL5:
            speaker_gain = 11;
            break;
        case LEVEL6:
            speaker_gain = 13;
            break;

        case LEVEL7:
            speaker_gain = 15;
            break;

        default:
            speaker_gain = 10;
            break;
    }

    (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_set_headset_speaker_gain_req) (speaker_gain, conn_p->conn_id);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_hfp_sco_link_connect_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_hfp_sco_link_connect_req()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_bt_is_hs_connected())
    {
        (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_hfp_sco_link_connect_req) ();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_hfp_sco_link_disconnect_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_hfp_sco_link_disconnect_req()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_bt_is_hs_connected())
    {
        (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_hfp_sco_link_disconnect_req) ();
    }
}

/* Configure Default Headset */
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_connect_last_headset
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_connect_last_headset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((mmi_bt_is_hw_ready) (MMI_TRUE) == MMI_FALSE)
    {
        return;
    }

    /* to avoid the error operation while bt module is busy */
    if ((mmi_bt_is_permission) (MMI_TRUE) == MMI_FALSE)
    {
        return;
    }

    /* prohibited by simap, shall deactivate simap first */
    #ifdef __MMI_SIMAP_SUPPORT__
    if (mmi_bt_is_simap_server_activate())
    {
        mmi_bt_popup_prohibited_by_simap();
        return;
    }
    #endif
    
    if (!mmi_bt_is_hs_connected())
    {
		if (g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_connect_last_headset_req != NULL)
		{
        	if((*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_connect_last_headset_req)() == MMI_TRUE) 
        	{
		        g_mmi_bt_scr_cntx.connecting_profile = (U32)MMI_BT_HF_PROFILE_UUID;
       		}
        }
    }
    else
    {
        DisplayPopup(
            (U8*) GetString(STR_BT_ONE_HEADSET_ALREADY_CONNECTED),
            IMG_GLOBAL_ERROR,
            MMI_FALSE,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_get_active_signal_connection_id
 * DESCRIPTION
 *  This function is to get signal connection id
 * PARAMETERS
 *  profile_uuid        [IN]            
 *  a(?)                [IN/OUT]        First variable, used as returns
 *  b(?)                [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_bt_get_active_signal_connection_id(U32 profile_uuid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* if a2dp signal connection is not existed, return -1 */
    S32 conn_id = -1;
    U32 i = 0;
    U8 act_con_num;
    mmi_bt_connect_struct *conn_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if bt is initialized */
    if (g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_pwron == NULL)
    {
        return conn_id;
    }

    act_con_num = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_existed_dev_num) ();

    /* get index of existed_conn */
    for (i = 0; i < act_con_num; i++)
    {
        conn_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_existed_conn_info) ((U16) i);
        /* assume that there is only one profile_uuid(A2DP/HFP) connection at one time */

        switch (conn_p->conn_type)
        {
            case MMI_BT_A2DP_CONNECTION:
                if (conn_p->active == MMI_TRUE && profile_uuid == MMI_BT_ADVANCED_AUDIO_PROFILE_UUID)
                {
                    conn_id = (S32) conn_p->conn_id;
                    return conn_id;
                }
                break;
            case MMI_BT_HFP_CONNECTION:
            case MMI_BT_HSP_CONNECTION:
                if (conn_p->active == MMI_TRUE &&
                    (profile_uuid == MMI_BT_HFG_PROFILE_UUID || profile_uuid == MMI_BT_HEADSET_AG_SERVICE_UUID))
                {
                    conn_id = (S32) conn_p->conn_id;
                    return conn_id;
                }
                break;
            default:
                break;

        }

    }

    return conn_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_is_a2dp_connected
 * DESCRIPTION
 *  This function is to check if a2dp connected
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bt_is_a2dp_connected(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    U8 act_con_num;
    mmi_bt_connect_struct *conn_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if bt is initialized */
    if (g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_pwron == NULL)
    {
        return MMI_FALSE;
    }

    act_con_num = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_existed_dev_num) ();

    /* get index of existed_conn */
    for (i = 0; i < act_con_num; i++)
    {
        conn_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_existed_conn_info) ((U16) i);
        /* assume that there is only one A2DP connection at one time */
        switch (conn_p->conn_type)
        {
            case MMI_BT_A2DP_CONNECTION:
                if (conn_p->active == MMI_TRUE)
                {
                    return MMI_TRUE;
                }
                break;
            default:
                break;

        }

    }

    return MMI_FALSE;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_is_profile_connected
 * DESCRIPTION
 *  This function is to check if XXX profile connected
 * PARAMETERS
 *  conn_type       [IN]        to check if conn_type is connected, conn_type is defind in mmi_bt_connection_type 
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_bt_is_profile_connected(U32 conn_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    U8 act_con_num;
    mmi_bt_connect_struct *conn_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if bt is initialized */
    if (g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_pwron == NULL)
    {
        return MMI_FALSE;
    }

    act_con_num = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_existed_dev_num) ();

    /* get index of existed_conn */
    for (i = 0; i < act_con_num; i++)
    {
        conn_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_existed_conn_info) ((U16) i);
        if (conn_p->conn_type == conn_type && conn_p->active == MMI_TRUE)
        {
           return MMI_TRUE;
        }

    }

    return MMI_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ps_stack_and_hw_init
 * DESCRIPTION
 *  This function is to inform bt stack and hw to start initialize or not
 * PARAMETERS
 *  flight_mode         [IN]            
 *  sim_inserted        [IN]            
 *  a(?)                [IN/OUT]        First variable, used as returns
 *  b(?)                [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bt_ps_stack_and_hw_init(MMI_BOOL flight_mode, MMI_BOOL sim_inserted)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if bt is initialized */
    if (g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_pwron == NULL)
    {
        MMI_BT_ASSERT(0);
    }

    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_PS_HW_INIT,
               flight_mode, sim_inserted, (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_pwron) ());

    if (!flight_mode)
    {
    #ifndef __MMI_BT_BG_PWRON__
        /* reinit BT */
        /* mmi_bt_init(); */
        if ((*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_pwron) () == MMI_TRUE)
        {
            /* turn on BT power */
            /* wait for mmi_antenna_on_rsp to reset bt ready ram flag  */
            (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_antenna_on_req) ();
        }
    #else /* __MMI_BT_BG_PWRON__ */ 
        mmi_bt_reset_hw_on();
    #endif /* __MMI_BT_BG_PWRON__ */ 
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_get_device_name
 * DESCRIPTION
 *  This function is to get the device name
 * PARAMETERS
 *  lap                 [IN]        bluetooth address
 *  uap                 [IN]        bluetooth address
 *  nap                 [IN]        bluetooth address
 *  max_name_len        [IN]        allowed max length of name_p
 *  name_p              [?]         name buffer pointer
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_get_device_name(U32 lap, U8 uap, U16 nap, U8 max_name_len, U8 *name_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bt_dev_struct *dev_p;
    U32 i;
    U8 paired_dev_num;
    U8 char_cnt = 0;
    U16 index_of_2byte_char;	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if bt is initialized */
    if (g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_pwron == NULL)
    {
        return;
    }

    paired_dev_num = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_num) ();

    /* reset name_p */
    name_p[0] = 0;

    /* find out the device info */
    for (i = 0; i < paired_dev_num; i++)
    {
        dev_p = (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_paired_dev_info) ((U16) i);
        if (dev_p->bd_addr.lap == lap && dev_p->bd_addr.uap == uap && dev_p->bd_addr.nap == nap)
        {

            /* get character count of utf8 string */
            char_cnt = (U8) (mmi_chset_utf8_strlen((kal_uint8*) dev_p->name));

            MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_GET_DEVICE_NAME, i, char_cnt, (MMI_BT_BD_NAME_LEN/3), (MMI_BT_BD_NAME_LEN/3*ENCODING_LENGTH) );


            if (char_cnt > (MMI_BT_BD_NAME_LEN/3) )   
            {
                /* check any two-byte UCS2 char before (MMI_BT_BD_NAME_LEN/3) chars of the utf8 string */
                if ((index_of_2byte_char = mmi_bt_test_2bytes_ucs2_char_in_utf8_string(dev_p->name, (U16)(MMI_BT_BD_NAME_LEN/3))) != (MMI_BT_BD_NAME_LEN/3))
                {
                    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_2BYTE_CHAR_INDEX, index_of_2byte_char);
                    /* copy the first (MMI_BT_BD_NAME_LEN/3) chars */
                    mmi_bt_copy_n_utf8_chars(name_p, max_name_len, dev_p->name, (U8)(MMI_BT_BD_NAME_LEN/3));
                    
                }
                /* check any two-byte UCS2 char before (MMI_BT_BD_NAME_LEN/3*ENCODING_LENGTH) chars of the utf8 string */
                else if ( (index_of_2byte_char = mmi_bt_test_2bytes_ucs2_char_in_utf8_string(dev_p->name, (U16)(MMI_BT_BD_NAME_LEN/3*ENCODING_LENGTH))) != (MMI_BT_BD_NAME_LEN/3*ENCODING_LENGTH) )
                {
                    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_2BYTE_CHAR_INDEX, index_of_2byte_char);
                    /* copy all the chars before this two-byte UCS2 char */
                    mmi_bt_copy_n_utf8_chars(name_p, max_name_len, dev_p->name, (U8)index_of_2byte_char);
                    
                }
                else
                {
                    /* copy the first (MMI_BT_BD_NAME_LEN/3*ENCODING_LENGTH) chars */
                    mmi_bt_copy_n_utf8_chars(name_p, max_name_len, dev_p->name, (U8)(MMI_BT_BD_NAME_LEN/3*ENCODING_LENGTH));
                    
                }
            }
            else
            {
                    /* copy the first (MMI_BT_BD_NAME_LEN/3*ENCODING_LENGTH) chars */
                    mmi_bt_copy_n_utf8_chars(name_p, max_name_len, dev_p->name, (U8)(MMI_BT_BD_NAME_LEN/3*ENCODING_LENGTH));
            }
            
        }
    }

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_profile_callback_before_release_connection
 * DESCRIPTION
 *  This function is to get the device name
 * PARAMETERS
 *  lap                 [IN]        BD address, if no idea, pls set to 0
 *  uap                 [IN]        BD address, if no idea, pls set to 0
 *  nap                 [IN]        BD address, if no idea, pls set to 0
 *  profile_id          [IN]        Profile uuid
 *  connection_id       [IN]        Profile connection id, if no idea, pls set to 0xFFFFFFFF
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_profile_callback_before_release_connection(U32 lap, U8 uap, U16 nap, U32 profile_id, U32 connection_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_profile_callback_before_release_connection_hdler)
    {
        (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_profile_callback_before_release_connection_hdler) (lap, uap, nap,
                                                                                                   profile_id,
                                                                                                   connection_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_host_device_power_off_pre_process
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_host_device_power_off_pre_process(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_ram_flag)
    {
        if ((*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_get_ram_flag) (MMI_BT_RAMMASK_IS_AUTO_PWR_SWTICH))
        {
            if (g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_reset_ram_flag_req)
            {
                (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_reset_ram_flag_req) (MMI_BT_RAMMASK_IS_AUTO_PWR_SWTICH);
            }
            if (g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_reset_flag_req)
            {
                (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_reset_flag_req) (MMI_BT_MASK_ACTIVATED);
            }
            if (g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_nvram_write_info)
            {
                (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_nvram_write_info) ();
            }
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_sco_near_end_loopback_test
 * DESCRIPTION
 *  This function is to do near end loopback test
 * PARAMETERS
 *  void
 *  IN   lap: bluetooth address(?)
 *  IN   uap: bluetooth address(?)
 *  IN   nap: bluetooth address(?)
 *  IN   pin_code: pin code of remote bt headset, max number of PIN is 16 digits(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_sco_near_end_loopback_test(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* L4 send command to BT task directly */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_sco_far_end_loopback_test
 * DESCRIPTION
 *  This function is to do far end loopback test
 * PARAMETERS
 *  lap             [IN]        bluetooth address
 *  uap             [IN]        bluetooth address
 *  nap             [IN]        bluetooth address
 *  pin_code        [?]         pin code of remote bt headset, max number of PIN is 16 digits
 *  size_of_pin     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_sco_far_end_loopback_test(U32 lap, U8 uap, U16 nap, U8 *pin_code /* ascii encoding */ , U8 size_of_pin)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_at_general_res_req_struct *res_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_LP_TEST,
               g_mmi_bt_scr_cntx.test_by_at, lap, uap, nap, pin_code[0], pin_code[1], pin_code[2], pin_code[3]);

	if (g_mmi_bt_scr_cntx.test_by_at == 0)
	{
		g_mmi_bt_scr_cntx.test_by_em = 1;
	}

    /* check if bt is initialized */
    if (g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_pwron == NULL)
    {
        if (g_mmi_bt_scr_cntx.test_by_at)
        {

	        res_p = construct_local_para(sizeof(mmi_at_general_res_req_struct), TD_UL);
	        /* indicate L4 AT module failed */
	        res_p->result = MMI_FALSE;

            /* indicate L4 AT module succeeded or failed */
            mmi_bt_send_l4_msg(MSG_ID_MMI_AT_GENERAL_RES_REQ, (void*)res_p, NULL);
            g_mmi_bt_scr_cntx.test_by_at = 0;
        }
        else
        {
			if (g_mmi_bt_scr_cntx.test_by_em)
			{
	            /* call back engineering...failed */
	            EmBTNotifyLoopbackDoneCnf(MMI_FALSE);
				g_mmi_bt_scr_cntx.test_by_em = 0;
			}
        }

        return;

    }

    /* store testin device bt address */
    g_mmi_bt_scr_cntx.far_end_dev_add.lap = lap;
    g_mmi_bt_scr_cntx.far_end_dev_add.uap = uap;
    g_mmi_bt_scr_cntx.far_end_dev_add.nap = nap;

    /* store pin code */
    /* strlen will not count the NULL terminate byte */
    if (strlen((const char*)pin_code) > MMI_BT_MAX_PASSKEY_LENGHT)
    {
        memcpy(g_mmi_bt_scr_cntx.far_end_dev_pin, pin_code, MMI_BT_MAX_PASSKEY_LENGHT);
        g_mmi_bt_scr_cntx.far_end_dev_pin[MMI_BT_MAX_PASSKEY_LENGHT] = 0;
    }
    else
    {
        memcpy(g_mmi_bt_scr_cntx.far_end_dev_pin, pin_code, size_of_pin);
        g_mmi_bt_scr_cntx.far_end_dev_pin[size_of_pin] = 0;
    }

    /* check if bluetooh stack is ready */
    if ((mmi_bt_is_hw_ready) (MMI_FALSE) == MMI_FALSE ||
        (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_any_connection_active) ())
    {
        if (g_mmi_bt_scr_cntx.test_by_at)
        {
	        res_p = construct_local_para(sizeof(mmi_at_general_res_req_struct), TD_UL);

	        /* indicate L4 AT module failed */
	        res_p->result = MMI_FALSE;

            /* indicate L4 AT module succeeded or failed */
            mmi_bt_send_l4_msg(MSG_ID_MMI_AT_GENERAL_RES_REQ, (void*)res_p, NULL);
            g_mmi_bt_scr_cntx.test_by_at = 0;
        }
        else
        {
			if (g_mmi_bt_scr_cntx.test_by_em)
			{
	            /* call back engineering...failed */
	            EmBTNotifyLoopbackDoneCnf(MMI_FALSE);
				g_mmi_bt_scr_cntx.test_by_em = 0;
			}
        }

        return;

    }
    else
    {
        g_mmi_bt_scr_cntx.flag |= MMI_BT_SCO_FAR_END_LP_TESTING;

        /* store device infor to paired dev */
        (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_mydev_add_req) (&(g_mmi_bt_scr_cntx.far_end_dev_add));

        if ((*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_pwron) () == MMI_TRUE)
        {

            /* connecting HFP profile */
            (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_connect_req) (&(g_mmi_bt_scr_cntx.far_end_dev_add),
                                                                  MMI_BT_HF_PROFILE_UUID);

        }
        else
        {
        #ifndef __MMI_BT_BG_PWRON__
            (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_set_flag_req) (MMI_BT_MASK_ACTIVATED);

            /* turn on BT power */
            /* wait for mmi_antenna_on_rsp to reset bt ready ram flag  */
            (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_antenna_on_req) ();
        #else /* __MMI_BT_BG_PWRON__ */ 
            /* deactivate bluetooth services */
            (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_activate_req) ();
        #endif /* __MMI_BT_BG_PWRON__ */ 
        }

    }

    /* to guard the loopback testing time */
    StartTimer(BT_LP2_TESTING_TIMER, MMI_BT_BT_LP2_GUARD_TIMER_DUR, mmi_bt_loopback_test_timeout_hdler);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_sco_far_end_loopback_cancel_test
 * DESCRIPTION
 *  This function is to do far end loopback test
 * PARAMETERS
 *  void
 *  IN   lap: bluetooth address(?)
 *  IN   uap: bluetooth address(?)
 *  IN   nap: bluetooth address(?)
 *  IN   pin_code: pin code of remote bt headset, max number of PIN is 16 digits(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_sco_far_end_loopback_cancel_test(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if bt is initialized */
    if (g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_is_pwron == NULL)
    {
        return;
    }

    /* reset flag */
    /* mmi_bt_reset_scr_flag(); */

    (g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_mydev_remove_req) (&(g_mmi_bt_scr_cntx.far_end_dev_add));

    if ((mmi_bt_is_hw_ready) (MMI_FALSE))
    {
        /* deactivate bluetooth services */
        (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_deactivate_req) ();

    }
    else
    {
        g_mmi_bt_scr_cntx.flag &= ~MMI_BT_SCO_FAR_END_LP_TESTING;
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_loopback_req_ind_hdler
 * DESCRIPTION
 *  This function is the handler for loopback req ind from L4
 * PARAMETERS
 *  msg_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_loopback_req_ind_hdler(void *msg_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bt_dev_addr dev_add_p;
    mmi_l4_bt_loopback_test_req_ind_struct *lp_test_p = (mmi_l4_bt_loopback_test_req_ind_struct*) msg_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_bt_scr_cntx.test_by_at = 1;

    dev_add_p.nap = ((U16) ((lp_test_p->bd_addr[3]) * 256)) | (U16) (lp_test_p->bd_addr[4]);
    dev_add_p.uap = (U8) (lp_test_p->bd_addr[5]);
    dev_add_p.lap = (U32) (lp_test_p->bd_addr[0]);
    dev_add_p.lap = (dev_add_p.lap << 16) | ((U32) ((lp_test_p->bd_addr[1]) * 256)) | ((U32) (lp_test_p->bd_addr[2]));
    mmi_bt_sco_far_end_loopback_test(
        dev_add_p.lap,
        dev_add_p.uap,
        dev_add_p.nap,
        lp_test_p->pin_code,
        (U8) strlen((const char*)lp_test_p->pin_code));

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_loopback_test_timeout_hdler
 * DESCRIPTION
 *  This function is the handler for loopback testing timeout
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_loopback_test_timeout_hdler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_mmi_bt_scr_cntx.flag & MMI_BT_SCO_FAR_END_LP_TESTING)
    {
        /* call back engineering...failed */

        if (g_mmi_bt_scr_cntx.test_by_at)
        {
		    mmi_at_general_res_req_struct *res_p;

		    res_p = construct_local_para(sizeof(mmi_at_general_res_req_struct), TD_UL);
	        /* indicate L4 AT module failed */
	        res_p->result = MMI_FALSE;

            /* indicate L4 AT module succeeded or failed */
            mmi_bt_send_l4_msg(MSG_ID_MMI_AT_GENERAL_RES_REQ, (void*)res_p, NULL);
            g_mmi_bt_scr_cntx.test_by_at = 0;
        }
        else
        {
			if (g_mmi_bt_scr_cntx.test_by_em)
			{
	            /* call back engineering...failed */
	            EmBTNotifyLoopbackDoneCnf(MMI_FALSE);
				g_mmi_bt_scr_cntx.test_by_em = 0;
			}
        }

        /* reset flag */
        /* mmi_bt_reset_scr_flag(); */

        (g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_mydev_remove_req) (&(g_mmi_bt_scr_cntx.far_end_dev_add));

        if ((mmi_bt_is_hw_ready) (MMI_FALSE))
        {
            /* deactivate bluetooth services */
            (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_deactivate_req) ();
        }
        else
        {
            g_mmi_bt_scr_cntx.flag &= ~MMI_BT_SCO_FAR_END_LP_TESTING;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_loopback_delay_timeout_hdler
 * DESCRIPTION
 *  This function is the handler for loopback testing timeout
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_loopback_delay_timeout_hdler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* callback dsp api */
#ifdef __MTK_TARGET__
    result = BT_PcmLoopbackTest();
#else 
    result = MMI_FALSE;
#endif 
    /* callback engineering mode....succeeded or failed */

    mmi_bt_hfp_sco_link_disconnect_req();

#if defined(__MMI_BT_PROFILE__)
    mmi_profiles_bt_disconnect_callback(MMI_PROFILES_BT_HFP_ACL, MMI_PROFILES_BT_IND, MMI_PROFILES_BT_OK);
#endif 

    /* indicate L4 AT module succeeded or failed */
    if (g_mmi_bt_scr_cntx.test_by_at)
    {
	    mmi_at_general_res_req_struct *res_p;

	    res_p = construct_local_para(sizeof(mmi_at_general_res_req_struct), TD_UL);
	    res_p->result = result;
        /* indicate L4 AT module succeeded or failed */
        mmi_bt_send_l4_msg(MSG_ID_MMI_AT_GENERAL_RES_REQ, (void*)res_p, NULL);
        g_mmi_bt_scr_cntx.test_by_at = 0;
    }
    else
    {
		if (g_mmi_bt_scr_cntx.test_by_em)
		{
            /* call back engineering... */
            EmBTNotifyLoopbackDoneCnf(result);
			g_mmi_bt_scr_cntx.test_by_em = 0;
		}
		
    }

    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_LP_TEST_RESULT, result);

    /* reset flag */
    /* mmi_bt_reset_scr_flag(); */
    (g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_mydev_remove_req) (&(g_mmi_bt_scr_cntx.far_end_dev_add));
    /* deactivate bluetooth services */
    (*g_mmi_bt_scr_cntx.stack_cb_tbl.mmi_bt_deactivate_req) ();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_send_l4_msg
 * DESCRIPTION
 *  This function is the handler for send msg to L4
 * PARAMETERS
 *  msg_id              [IN]        
 *  p_local_para        [?]         
 *  p_peer_buff         [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_send_l4_msg(U16 msg_id, void *p_local_para, void *p_peer_buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_SEND_MSG_2_L4, msg_id);

    Message.oslMsgId = msg_id;
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslDataPtr = (oslParaType*) p_local_para;
    Message.oslPeerBuffPtr = p_peer_buff;

    OslMsgSendExtQueue(&Message);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_reject_passkey_ind
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bt_reject_passkey_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    U16 act_scr = GetActiveScreenId();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (act_scr == SCR_BT_PIN_INPUT)
    {
        mmi_bt_passkey_input_scr_del_callback();
        GoBackHistory();
        result = MMI_TRUE;
    }
    else
    {
        if (DeleteScreenIfPresent(SCR_BT_PIN_INPUT))
        {
            result = MMI_TRUE;
        }
        else
        {
            result = MMI_FALSE;
        }

    }

    return result;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_test_UCS2
 * DESCRIPTION
 *  check if 2-byte UCS2 char existed
 * PARAMETERS
 *  buf         [IN]         
 *  charNum     [IN]        number of char in buffer
 * RETURNS
 *  return true if 2-byte UCS2 char existed, else return false
 *****************************************************************************/
MMI_BOOL mmi_bt_test_ucs2(U16 *buf, U16 char_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *buffer = buf;
    U16 char_number = char_num;
    U16 ch;
    U16 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (count < char_number)
    {
        ch = buffer[count];
        //if (UI_TEST_UCS2_CHARACTER(ch))
        /* if ch is larger than 128, then the byte count of UTF8 encoding is 2*/
        if (0xff80 & ch)
        {
            return MMI_TRUE;
        }
        count++;
    }

    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_truncate_ucs2_string
 * DESCRIPTION
 *  to truncate ucs2 string to compromise the size of utf8 string buffer in bt core
 * PARAMETERS
 *  buf         [IN]         
 *  charNum     [IN]        number of char in buffer
 *  truncate_char_num     [IN]        min number of char in input string
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_truncate_ucs2_string(U16 *buf, U16 char_num, U16 truncate_char_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *buffer = (U16*)buf;
    U16 char_number = char_num;
    U16 ch;
    U16 count = 0;
    U8 truncate_flag = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (count < char_number)
    {
        ch = buffer[count];
        //if (UI_TEST_UCS2_CHARACTER(ch))
        /* if ch is larger than 128, then the byte count of UTF8 encoding is 2*/
        if (0xff80 & ch)
        {
            truncate_flag = 1;
        }
        if (truncate_flag && (count >= truncate_char_num))
        {
			buffer[count] = 0;
        	break;
        }
        
        count++;
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_test_2bytes_ucs2_char_in_utf8_string
 * DESCRIPTION
 *  check if 2-byte UCS2 char existed in the input string
 * PARAMETERS
 *  buf             [IN]         
 *  charNum     [IN]        number of char in buffer
 * RETURNS
 *  return the index of first 2bytes ucs2 char
 *****************************************************************************/
U16 mmi_bt_test_2bytes_ucs2_char_in_utf8_string(U8 *buf, U8 char_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 found_index = 0;
    U8 char_count = 0;
    U8 char_byte_cnt=0;
    U8 ucs_char[4];
    U16 ch;
    
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_TEST_2BYTE_UCS2_CHAR, char_num);

    while (*buf && char_count < char_num)
    {
        char_byte_cnt = (U8)mmi_chset_utf8_to_ucs2(ucs_char, buf);
        ch = ucs_char[0] | (ucs_char[1] << 8); 
        //if (UI_TEST_UCS2_CHARACTER(ch))
        /* if ch is larger than 128, then the byte count of UTF8 encoding is 2*/
        if (0xff80 & ch)
	    {
	 	    break;
        }
        else  
        {
            buf += char_byte_cnt;
            char_count++;
            found_index++;
        }
    }

    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_TEST_2BYTE_UCS2_CHAR_FINISH, found_index);
    
    return found_index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_copy_n_utf8_chars
 * DESCRIPTION
 *  to copy n chars to dest string
 * PARAMETERS
 *  dest                 [IN]        dest buffer 
 *  size_of_dest     [IN]        max size of dest buffer
 *  src                   [IN]        src buffer 
 *  charNum          [IN]        number of char to be copied
 * RETURNS
 *  return true if 2-byte UCS2 char existed, else return false
 *****************************************************************************/
void mmi_bt_copy_n_utf8_chars(U8 *dest, U16 size_of_dest, U8 *src, U8 char_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 char_count = 0;
    U8 char_byte_cnt = 0;
    U8 ucs_char[4];
    U16 byes_copied = 0;
    U16 max_size_of_dest = size_of_dest-2;
    
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BT_ASSERT(dest);
    MMI_BT_ASSERT(src);

    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_COPY_N_UTF8_CHAR, size_of_dest, char_num);

    
    while (*src && char_count < char_num && byes_copied < max_size_of_dest)
    {
        char_byte_cnt = (U8)mmi_chset_utf8_to_ucs2(ucs_char, src);
        if ( (byes_copied+char_byte_cnt) > max_size_of_dest )
        {
        	*dest = 0;
        	*(dest+1) = 0;
        	break;
        }
        memcpy(dest, src, char_byte_cnt);
        dest += char_byte_cnt;
        src += char_byte_cnt;
        char_count++;
        byes_copied += char_byte_cnt;
    }

    *dest = 0;
    *(dest+1) = 0;

    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_COPY_N_UTF8_CHAR_FINISH, char_count, byes_copied);


}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_delete_screen
 * DESCRIPTION
 *  to 
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_delete_screen(U16 screen_id, MMI_BOOL go_back_history)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 act_scr_id = GetActiveScreenId();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ( act_scr_id == screen_id )
    {
        EntryNewScreen(GLOBAL_SCR_DUMMY, NULL, NULL, NULL);
    }

    DeleteScreenIfPresent(screen_id);

    if ((go_back_history) && 
        (act_scr_id == screen_id))
    {
        GoBackHistory();
    }

}
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_popup_operation_not_allowed
 * DESCRIPTION
 *  to popup operation not allowed information
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_popup_operation_not_allowed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;                      /* Buffer holding history data */
	S32 ui_buffer_size;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_BT_NOT_ALLOWED, NULL, mmi_bt_popup_operation_not_allowed, NULL);

    /* Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_BT_NOT_ALLOWED);

    ui_buffer_size = mmi_ucs2strlen((const S8*)GetString(STR_BT_OPERATION_NOT_ALLOWED_DIS_HFP_FIRST));


    ShowCategory74Screen(
        STR_BT_NOT_ALLOW,
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8) GetString(STR_BT_OPERATION_NOT_ALLOWED_DIS_HFP_FIRST),
        ui_buffer_size,
        guiBuffer);

    /* go back */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    if (IsBackHistory == MMI_FALSE && 
        !mmi_is_redrawing_bk_screens()
       )
	{
		/* play a warning tone */
		playRequestedTone(WARNING_TONE);
	}



	#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif

}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_popup_prohibited_by_simap
 * DESCRIPTION
 *  to popup operation not allowed information
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_popup_prohibited_by_simap(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;                      /* Buffer holding history data */
	S32 ui_buffer_size;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_BT_NOT_PROHIBIT_BY_SIMAP, NULL, mmi_bt_popup_prohibited_by_simap, NULL);

    /* Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_BT_NOT_PROHIBIT_BY_SIMAP);

    ui_buffer_size = mmi_ucs2strlen((const S8*)GetString(STR_BT_PROHIBIT_BY_SIMAP));


    ShowCategory74Screen(
        STR_BT_NOT_ALLOW,
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8) GetString(STR_BT_PROHIBIT_BY_SIMAP),
        ui_buffer_size,
        guiBuffer);

    /* go back */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    if (IsBackHistory == MMI_FALSE && 
        !mmi_is_redrawing_bk_screens()
       )
	{
		/* play a warning tone */
		playRequestedTone(WARNING_TONE);
	}


	#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif

}

/* for pts V2.1.0.4 */
/* cannot update indicators to remote bluetooth headset while HFP is connected */
/* indicators shall be retrieved by remote HF AT+CIND? */
/* so for pts V2.1.0.4, host will not udpate indicators while HFP is just connected */
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_enable_pts_test
 * DESCRIPTION
 *  to enable the global variable to indicate that pts testing is active
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_enable_pts_test(void)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_enable_pts_test = 1;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_disable_pts_test
 * DESCRIPTION
 *  to disable the global variable to indicate that pts testing is off
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_disable_pts_test(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_enable_pts_test = 0;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_dummy_specific_cod_device
 * DESCRIPTION
 *  This function is used to add a dummy screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_dummy_specific_cod_device(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_ENTRY_DUMMY_SPEC_COD_DEV, IsBackHistory, g_mmi_bt_scr_cntx.flag, mmi_is_redrawing_bk_screens());

    
    if (!mmi_is_redrawing_bk_screens())
    {
	    /* if gobackhistory -> shall invoke the registered callback  */
	    if (IsBackHistory)
	    {
	        EntryNewScreen(SCR_BT_MY_SPECIFIC_DEV_DUMMY, NULL, NULL, NULL); /* To enter dummy screen function */
		    //ShowCategoryDummyScreen();
		    ShowCategoryDummySmallScreen();
			if (!(g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_SPECIFIC_DEV))
			{
			    /* start a timer to goback */	 
		    	StartTimer(BT_DUMMY_SCR_TIMER, MMI_BT_DUMMY_SCR_TIMER_DURATION, mmi_bt_dummy_specific_cod_device_timer_expire_hdlr);
			}
	    }
	    /* else -> add a dummy screen under SCR_BT_MY_SPECIFIC_DEV */
	    else
	    {
	        EntryNewScreen(SCR_BT_MY_SPECIFIC_DEV_DUMMY, NULL, mmi_bt_entry_dummy_specific_cod_device, NULL);
		    //ShowCategoryDummyScreen();
		    ShowCategoryDummySmallScreen();
	        SetDelScrnIDCallbackHandler(SCR_BT_MY_SPECIFIC_DEV_DUMMY, mmi_bt_dummy_specific_cod_device_del_cb);
	    }    
    }

	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dummy_specific_cod_device_del_cb
 * DESCRIPTION
 *  This function is the delete callback function for dummy screen
 * PARAMETERS
 *  void*
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_bt_dummy_specific_cod_device_del_cb(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_ENTRY_DUMMY_SPEC_COD_DEV_DEL_CB, g_mmi_bt_scr_cntx.select_device_cb);
    
	if (g_mmi_bt_scr_cntx.select_device_cb != NULL)
	{
	    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_SELECT_DEVICE_CB, MMI_FALSE, 0, 0, 0);
		(*g_mmi_bt_scr_cntx.select_device_cb)(MMI_FALSE, 0, 0, 0);
		g_mmi_bt_scr_cntx.select_device_cb = NULL;
	}
    SetDelScrnIDCallbackHandler(SCR_BT_MY_SPECIFIC_DEV_DUMMY, NULL);
	
	g_mmi_bt_scr_cntx.flag &= ~MMI_BT_CONFIRM_SPECIFIC_DEV;
	
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dummy_specific_cod_device_timer_expire_hdlr
 * DESCRIPTION
 *  This function is to handle the bpp timer expires event for cm screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_dummy_specific_cod_device_timer_expire_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 cur_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_DUMMY_SPEC_COD_DEV_TIMER_EXPIRE, g_mmi_bt_scr_cntx.select_device_cb);

    SetDelScrnIDCallbackHandler(SCR_BT_MY_SPECIFIC_DEV_DUMMY, NULL);
    cur_id = GetActiveScreenId();
    switch(cur_id)
    {
        case SCR_BT_MY_SPECIFIC_DEV_DUMMY:
            GoBackHistory();
	        break;
	    default:
            DeleteScreenIfPresent(SCR_BT_MY_SPECIFIC_DEV_DUMMY);
            break; 	     
    }

	if (g_mmi_bt_scr_cntx.select_device_cb != NULL)
	{
	    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_SELECT_DEVICE_CB, MMI_FALSE, 0, 0, 0);
		(*g_mmi_bt_scr_cntx.select_device_cb)(MMI_FALSE, 0, 0, 0);
		g_mmi_bt_scr_cntx.select_device_cb = NULL;
	}
	
}




#elif !defined(__MTK_TARGET__) && !defined(__MMI_BT_SUPPORT__)


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_main_hilight_handler
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_main_hilight_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    /* Register go back function key handler */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    /* Register entry function key handler */
    SetLeftSoftkeyFunction(PopupNoSupport, KEY_EVENT_UP);
    SetKeyHandler(PopupNoSupport, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_init
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU_CONN_BT_MAIN, mmi_bt_main_hilight_handler);
}


#endif 

