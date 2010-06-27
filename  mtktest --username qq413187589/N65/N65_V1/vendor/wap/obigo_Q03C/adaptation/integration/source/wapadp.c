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

/*******************************************************************************
 *
 * Filename:
 * ---------
 * wapadp.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for common functions provided in different WAP/MMS solutions.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *==============================================================================
 *******************************************************************************/
#ifndef WAPADP_C
#define WAPADP_C

#ifdef WAP_SUPPORT

#include "kal_release.h"        /* Basic data type */

/* Timer Management  */
#include "stacklib.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */
#include "app_str.h"
#include "event_shed.h" /* event schedulet */
#include "stack_timer.h"

#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */

#include "wap_ps_struct.h"
#include "USBDeviceGprot.h"
/* Included by Sandeep */
#include "EventsGprot.h"
#include "DebugInitDef.h"
#include "custom_wap_config.h"

/* plutommi includes */
#include "resource_audio.h"     /* Standard tone */
#include "CommonScreens.h"
#include "AlarmFrameworkProt.h" /* Alarm */
#include "gpioInc.h"
#include "MessagesMiscell.h"
#include "SettingProfile.h"
#include "gui_data_types.h"
#include "ProfileGprots.h"      /* PlayRequestedTone */

#ifdef __WIFI_SUPPORT__
/* WLAN includes */
#include "L4a.h"
#include "NetworkSetupDefs.h"
#endif

/* SMS includes */
#include "SMSApi.h"
#include "smsal_l4c_enum.h"

#include "widget.h"

#ifdef MMS_SUPPORT
#include "mea_def.h"
#include "mms_def.h"
#include "WapDef.h"
extern void goto_mms_editor(mms_content_entry_struct *data);
#endif /* MMS_SUPPORT */ 

extern void wap_entry_widget_not_ready(void);
extern void wap_entry_busy_progressing_screen_in_idle(void);

/* Handle WPS primitives */
extern void wps_fsm(ilm_struct *ilm_ptr);

#ifdef __UNIFIED_MSG_SUPPORT__
#include "Widget_extension.h"
extern MeaFolder wap_translate_um_folder_2_mea_folder(kal_uint16 box);

#ifdef __UNIFIED_COMPOSER_SUPPORT__
#include "UnifiedMessageGProt.h"
#include "UnifiedComposerGProt.h"
#endif
#endif /* __UNIFIED_MSG_SUPPORT__ */ 

#ifdef __MMI_MMS_BGSR_SUPPORT__
#include "MMSBGSRGprot.h"
#include "mma_conf.h"
#endif /*__MMI_MMS_BGSR_SUPPORT__*/
#ifdef __USB_IN_NORMAL_MODE__
extern kal_bool is_mms_storage_exported_to_pc(void);
extern kal_bool mmi_usb_is_in_mass_storage_mode(void);
extern void mmi_usb_app_unavailable_popup(kal_uint16 stringId);
#endif /* __USB_IN_NORMAL_MODE__ */ 

#ifdef __MMI_DUAL_SIM_MASTER__
#include "MTPNP_AD_Master_common_def.h"
#endif

/* EnginerMode Variables */

#if defined(WIDGET_VERBOSE_DEBUG)
kal_bool wap_enable_debug_assert = KAL_TRUE;
#else 
kal_bool wap_enable_debug_assert = KAL_FALSE;
#endif 
kal_uint8 global_wap_user_agent = EM_WAP_USERAGENT_MAUI_E800;

#ifdef WAP2
kal_uint8 global_wap_accept_header = EM_WAP_ACCEPTHEADER_WAP20;
#else 
kal_uint8 global_wap_accept_header = EM_WAP_ACCEPTHEADER_WAP121;
#endif 
//kal_uint8 global_mms_version = EM_MMS_VERSION_10;
kal_uint8 global_mms_version = 0;
kal_bool global_offline_page = 0;
kal_bool wap_suppress_popup_flag = KAL_FALSE;

stack_timer_struct wps_base_timer;
event_scheduler *wps_event_scheduler;

/*****************************************************************************
 * FUNCTION
 *  wap_get_screen_id
 * DESCRIPTION
 *  This function returns the wap screen id
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 wap_get_screen_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return WAP_SCREEN_WIDGET;
}



/*****************************************************************************
 * FUNCTION
 *  wap_is_ready
 * DESCRIPTION
 *  The function is used to check if wap task is ready (Browser, MMS and Transport modules are ready).
 * PARAMETERS
 *  void
 * RETURNS
 *  0: FASLE, 1: TRUE
 *****************************************************************************/
int wap_is_ready()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    extern int MSF_wapIsReady(void);

    return MSF_wapIsReady();
}


/*****************************************************************************
 * FUNCTION
 *  wap_is_init
 * DESCRIPTION
 *  The function is used to check if wap task is in initialization state.
 * PARAMETERS
 *  void
 * RETURNS
 *  0: FASLE, 1: TRUE
 *****************************************************************************/
int wap_is_init()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    extern int MSF_wapIsInit(void);

    return MSF_wapIsInit();
}

/*****************************************************************************
 * FUNCTION
 *  wap_get_service_module
 * DESCRIPTION
 *  This function is to implement viewing a specific push message by index
 * CALLS
 *  
 * PARAMETERS
 *  msg_id    [IN]   primitve id     
 * RETURNS
 *  module id, MOD_MMI or MOD_WAP
 *****************************************************************************/
module_type wap_get_service_module(kal_uint32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    return MOD_WAP;
}

/*****************************************************************************
 * FUNCTION
 *  wap_browser_is_open
 * DESCRIPTION
 *  The function is used to check if browser is opened.
 * PARAMETERS
 *  void
 * RETURNS
 *  0: FASLE, 1: TRUE
 *****************************************************************************/
int wap_browser_is_open()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    extern MSF_BOOL bra_win_any_win_exists(void);
    return bra_win_any_win_exists();
}


#ifdef MMS_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  mms_is_ready
 * DESCRIPTION
 *  The function is used to check if mms application is ready
 * PARAMETERS
 *  void
 * RETURNS
 *  0: FASLE, 1: TRUE
 *****************************************************************************/
int mms_is_ready()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM_MASTER__
    U8 sim_status = wap_get_sim_status();
    U8 sim_setting_mode = wap_get_sim_setting_mode();
#endif /* __MMI_DUAL_SIM_MASTER__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    extern int mmi_bootup_get_active_flight_mode(void);
    extern int mmi_bootup_is_sim_valid(void);
#ifdef __WIFI_SUPPORT__
    extern U8 mmi_netset_get_active_preferred_mode(void);
#endif
    extern int MSF_wapIsReady(void);

    return (MSF_wapIsReady() && !IsScreenPresent(wap_get_screen_id()) && 
        /*                                  *
         *  widget screen can't be re-entry *
         *                                  */
    #ifndef __UNIFIED_COMPOSER_SUPPORT__
        !(isInCall()&&!IsWapCallPresent()) &&
    #endif
        /*                                                                      *
         *  if not defined UC, because widget screen will check if it's in call *
         *  and if it's in call, widget won't show anything                     *
         *  so we wiil check if it's in call when not defined UC                *
         *                                                                      */
        mmi_bootup_get_active_flight_mode() == 0 && 
    #ifndef __MMI_DUAL_SIM_MASTER__
        mmi_bootup_is_sim_valid()
    #else /* __MMI_DUAL_SIM_MASTER__ */
        (
          (sim_status == WAP_SIM_ID_DUAL_SIM && sim_setting_mode == WAP_SIM_ID_DUAL_SIM)||
          (sim_status == WAP_SIM_ID_SIM1 && sim_setting_mode == WAP_SIM_ID_SIM1) ||
          (sim_status == WAP_SIM_ID_SIM1 && sim_setting_mode == WAP_SIM_ID_DUAL_SIM) ||
          (sim_status == WAP_SIM_ID_DUAL_SIM && sim_setting_mode == WAP_SIM_ID_SIM1) ||
          (sim_status == WAP_SIM_ID_SIM2 && sim_setting_mode == WAP_SIM_ID_SIM2) ||
          (sim_status == WAP_SIM_ID_SIM2 && sim_setting_mode == WAP_SIM_ID_DUAL_SIM) ||
          (sim_status == WAP_SIM_ID_DUAL_SIM && sim_setting_mode == WAP_SIM_ID_SIM2)
        )
    #endif /* __MMI_DUAL_SIM_MASTER__ */
  #ifdef __WIFI_SUPPORT__
        && mmi_netset_get_active_preferred_mode() != P_WLAN_ONLY
  #endif
  #ifdef __MMI_UNIFIED_MESSAGE__
        && mmi_um_check_ready()
  #endif
        );
}

/*****************************************************************************
 * FUNCTION
 *  mma_is_ready_for_usb
 * DESCRIPTION
 *  This function is used to check if MMA is ready for USB mode.
 * PARAMETERS
 *  NONE       
 * RETURNS
 *  TRUE or FALSE
 *****************************************************************************/
int mma_is_ready_for_usb(void)
{
#ifdef __MMS_DUAL_SIM_SUPPORT__
    return (wap_is_ready() && !IsMasterSIMBusy() && !IsSlaveSIMBusy());
#else
    return (wap_is_ready() && !isMMSBusy());
#endif
}

/*****************************************************************************
 * FUNCTION
 *  wap_mms_is_open
 * DESCRIPTION
 *  The function is used to check if MMS is opened.
 * PARAMETERS
 *  void
 * RETURNS
 *  0: FASLE, 1: TRUE
 *****************************************************************************/
int wap_mms_is_open()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MSF_moduleIsRunning(MSF_MODID_MEA);
}
#endif


/*****************************************************************************
 * FUNCTION
 *  wap_entry_no_ready_screen
 * DESCRIPTION
 *  The function is used to show "Please Wait" screen when WAP/MMS is not ready
 * PARAMETERS
 *  service_id      [IN]
 * RETURNS
 *  
 *****************************************************************************/
void wap_entry_no_ready_screen(wap_service_enum service_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(!MSF_wapIsReady());
    if (service_id == WAP_SERVICE_MMS)
    {
        WGUI_CTX->not_ready_for_MMS = 1;
    }
    else
    {
        WGUI_CTX->not_ready_for_MMS = 0;
    }
    wap_entry_widget_not_ready();
}




/*****************************************************************************
 * FUNCTION
 *  wap_bearer_csd_is_disc
 * DESCRIPTION
 *  The function is used to check if wap task is deinitializing CSD connection.
 * PARAMETERS
 *  void
 * RETURNS
 *  0: FASLE, 1: TRUE
 *****************************************************************************/
int wap_bearer_csd_is_disc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    extern int BRAa_bearerCsdIsDisc(void);

    return BRAa_bearerCsdIsDisc();
}


/*****************************************************************************
 * FUNCTION
 *  wap_url_is_valid
 * DESCRIPTION
 *  The function is used to check if url is valid.
 * PARAMETERS
 *  url     [IN]        
 * RETURNS
 *  0: FASLE, 1: TRUE
 *****************************************************************************/
int wap_url_is_valid(const char *url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    extern int msf_url_is_valid(const char*);

    return msf_url_is_valid(url);
}


/*****************************************************************************
 * FUNCTION
 *  wap_internet_key_hdlr
 * DESCRIPTION
 *  WAP internet key handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wap_internet_key_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr;
    wap_browser_startup_req_struct *para = (wap_browser_startup_req_struct*)
        construct_local_para((kal_uint16) sizeof(wap_browser_startup_req_struct), 0);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_WAP_INTERNET_KEY_HDLR);
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());

    if (!MSF_wapIsReady())
    {
        WGUI_CTX->not_ready_for_MMS = 0;
        wap_entry_widget_not_ready();
        return;
    }

    /* 
     * Scenario:
     * 
     * a. To avoid sending duplicated requests by WAP key in wap_internet_key_hdlr().
     * 
     * b. If the following procedures happen, it might try to enter WAP and MMS at the same time,
     *  which is not allowed due to memory restrictions. (assert happens)
     *
     *  Assume that we stay in idle screen after wap_internet_key_hdlr(). 
     *  (1) Press End key to return to idle screen when there is no incoming MMS message 
     *  (2) An incoming MMS message is received on idle screen, and it send RPC request 
     *     to execute widget_MMI_register_new_msg () in MMI task.
     *  (3) Long press WAP key triggers MSG_ID_WAP_BROWSER_STARTUP_REQ in extq of WAP task 
     *  (4) MMI task executes widget_MMI_register_new_msg() and EntryIdleScreen() again because it 
     *     still stays in idle screen. It then invokes widget_MMI_check_and_display_new_msg() and 
     *     send request to WAP task.
     *  (5) MSG_ID_WAP_BROWSER_STARTUP_REQ is processed in WAP task, it enters browser window.
     *  (6) It tries to start MEA to display new MMS message screen, but BRA UI is already started.
     */
    wap_entry_busy_progressing_screen_in_idle();

    if (bra_win_any_win_exists())
    {
        /* Abnormal case. BRA should already terminate its UI. */
        WAP_DBG_ASSERT(0);

        ilm_ptr = allocate_ilm(MOD_MMI);
        ilm_ptr->msg_id = MSG_ID_WAP_BROWSER_SHUTDOWN_REQ;
        ilm_ptr->peer_buff_ptr = NULL;
        ilm_ptr->local_para_ptr = (local_para_struct*) NULL;
        SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);
    }

    para->type = 1;

    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->msg_id = MSG_ID_WAP_BROWSER_STARTUP_REQ;
    ilm_ptr->peer_buff_ptr = NULL;
    ilm_ptr->local_para_ptr = (local_para_struct*) para;
    SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  em_wap_change_setting
 * DESCRIPTION
 *  This function is used by engineer mode to change WAP settings.
 * PARAMETERS
 *  opt     [IN]        Option type
 *  val     [IN]        Option value
 * RETURNS
 *  void
 *****************************************************************************/
void em_wap_change_setting(kal_uint8 opt, kal_uint8 val)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    extern void bra_prof_change_em_setting(kal_uint8 opt, kal_uint8 val);

    bra_prof_change_em_setting(opt, val);
}

/*****************************************************************************
* FUNCTION
*  wap_get_user_agent_brand
*
* DESCRIPTION
*  This function is used to get the brand of current user-agent.
*
* PARAMETERS
*  none
*  
* RETURNS
*  void
*
* GLOBALS AFFECTED
*  
*****************************************************************************/
em_wap_user_agent_brand_enum wap_get_user_agent_brand(void)
{
    return EM_WAP_USERAGENT_BRAND_MTK;
}

/*****************************************************************************
* FUNCTION
*  wap_get_user_agent
*
* DESCRIPTION
*  This function is used to get the current Browser user-agent.
*
* PARAMETERS
*  none
*  
* RETURNS
*  void
*
* GLOBALS AFFECTED
*  
*****************************************************************************/
char *wap_get_user_agent(void)
{
    extern const char* bra_prof_get_cur_user_agent (void);
    return (char *)bra_prof_get_cur_user_agent();
}

/*****************************************************************************
 * FUNCTION
 *  goto_mobile_suite_screen
*
 * DESCRIPTION
 *  WAP entry point from MMI menu
*
 * PARAMETERS
 *  void
 * RETURNS
 *  void
*
* GLOBALS AFFECTED
*  
 *****************************************************************************/
void goto_mobile_suite_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GOTO_MOBILE_SUITE_SCREEN);
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());

    if (!MSF_wapIsReady())
    {
        WGUI_CTX->not_ready_for_MMS = 0;
        wap_entry_widget_not_ready();
        return;
    }

    /* Disable key to prevent sending duplicated requests */
    ClearAllKeyHandler();
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);

    if (bra_win_any_win_exists())
    {
        /* Abnormal case. BRA should already terminate its UI. */
        WAP_DBG_ASSERT(0);

        ilm_ptr = allocate_ilm(MOD_MMI);
        ilm_ptr->msg_id = MSG_ID_WAP_BROWSER_SHUTDOWN_REQ;
        ilm_ptr->peer_buff_ptr = NULL;
        ilm_ptr->local_para_ptr = (local_para_struct*) NULL;
        SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);
    }

    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->msg_id = MSG_ID_WAP_BROWSER_STARTUP_REQ;
    ilm_ptr->peer_buff_ptr = NULL;
    ilm_ptr->local_para_ptr = (local_para_struct*) NULL;
    SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);
}

int wap_start_browser(kal_uint8 option, const kal_uint8 *url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_browser_startup_req_struct *p = NULL;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!wap_is_ready())
    {
        wap_entry_no_ready_screen(WAP_SERVICE_BROWSER);
        return -1;
    }

    /* Do not clear key handler if we are opening in background. */
    if(option != WAP_BROWSER_GOTO_URL_BACKGROUND)
    {
        /* Disable key to prevent sending duplicated requests */
        ClearAllKeyHandler();
        ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    }
    
    if (wap_browser_is_open())
    {
        if(option != WAP_BROWSER_GOTO_URL_BACKGROUND)
        {
            widget_MMI_shutdown_WAP_Widget_UI();
        }
    }
#ifdef MMS_SUPPORT
    else if(wap_mms_is_open())
    {
        widget_MMI_shutdown_WAP_Widget_UI();
    }
#endif

    p = (wap_browser_startup_req_struct*) construct_local_para(sizeof(wap_browser_startup_req_struct), TD_CTRL);

    p->type = option;

    memset(p->url, 0, sizeof(p->url));
    mmi_ucs2_n_to_asc((S8 *)p->url, (S8 *) url, sizeof(p->url));

    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->local_para_ptr = (local_para_struct*) p;
    ilm_ptr->msg_id = MSG_ID_WAP_BROWSER_STARTUP_REQ;
    ilm_ptr->peer_buff_ptr = NULL;
   
    ilm_ptr->src_mod_id  = MOD_MMI;
    ilm_ptr->dest_mod_id = MOD_WAP;
    ilm_ptr->sap_id = WAP_MMI_SAP;
    msg_send_ext_queue(ilm_ptr);
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  wap_suppress_popup
 * DESCRIPTION
 *  This function allow the other application suppress WAP/MMS popup
 * PARAMETERS
 *  is_true
 * RETURNS
 *  void
 *****************************************************************************/
void wap_suppress_popup(kal_bool is_true)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wap_suppress_popup_flag = is_true;
}


/*****************************************************************************
 * FUNCTION
 *  wap_is_new_msg_popup_handled
 * DESCRIPTION
 *  This function will handle new message popup in special behavior
 * PARAMETERS
 *  is_true
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool wap_is_new_msg_popup_handled(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wap_suppress_popup_flag == KAL_TRUE)
    {
        MMI_ALERT_TYPE alertType;

        /*
         * If the applications won't want to show the WAP/MMS notification popup, 
         * we may play SMS_IN_CALL_TONE and return directly.
         */    
        alertType = GetMtCallAlertTypeEnum();
    
        /* We play SMS_IN_CALL_TONE in this situation */
        if (alertType == MMI_VIBRATION_AND_RING || alertType == MMI_VIBRATION_THEN_RING || alertType == MMI_RING)
        {
            playRequestedTone(SMS_IN_CALL_TONE);
        }

        if ((alertType == MMI_VIBRATION_ONLY) || (alertType == MMI_VIBRATION_AND_RING) ||
            (alertType == MMI_VIBRATION_THEN_RING))
        {
            if (!AlmIsTonePlaying())
            {
                PlaySmsVibratorOnce();
            }
        }
        return KAL_TRUE;
    }
    else
    {
        /* do nothing, the application will execute the normal procedure */
        return KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wap_entry_select_bookmark
 * DESCRIPTION
 *  This function is used by MMI applications to make entry to bookmark selector screen
 * PARAMETERS
 *  p
 * RETURNS
 *  void
 *****************************************************************************/
int wap_entry_select_bookmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!wap_is_ready())
    {
        wap_entry_no_ready_screen(WAP_SERVICE_BROWSER);
        return -1;
    }

    if (IsScreenPresent(wap_get_screen_id()))
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_NOT_AVAILABLE),
            IMG_GLOBAL_ERROR,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
        return -1;
    }

    /* Disable key to prevent sending duplicated requests */
    ClearAllKeyHandler();
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);

    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->local_para_ptr = NULL;
    ilm_ptr->msg_id = MSG_ID_WAP_SELECT_BOOKMARK_REQ;
    ilm_ptr->peer_buff_ptr = NULL;

    SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  wap_fix_push_time
 * DESCRIPTION
 *  This function is used by PUSH module in both Obigo & Jataayu to fix invalid push time
 *      datetime[0] = year
 *      datetime[1] = month (1-12)
 *      datetime[2] = day  (1-31)
 *      datetime[3] = hour (0-23)
 *      datetime[4] = min (0-59)
 *      datetime[5] = sec (0-59)
 * PARAMETERS
 *  datetime        [in/out]
 * RETURNS
 *  0       datetime remains unchanged
 *  1       datetime modified
 *****************************************************************************/
int wap_fix_push_time (kal_uint32 datetime[6])
{
    kal_uint32 monthdays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int modified = 0;
    
    if (datetime[0] > 2100)
    {
        datetime[0] = 2100;
        datetime[1] = 12;
        datetime[2] = 31;
        modified = 1;
    }
    if (datetime[1] > 12)
    {
        datetime[1] = 12;
        modified = 1;
    }
    monthdays[1] += (!(datetime[0]%400) || (datetime[0]%100 && !(datetime[0]%4)));
    if (datetime[2] > monthdays[datetime[1]-1])
    {
        datetime[2] = monthdays[datetime[1]-1];
        modified = 1;
    }

    if (datetime[3] > 23)
    {
        datetime[3] = 0;
        modified = 1;
    }
    if (datetime[4] > 59)
    {
        datetime[4] = 0;
        modified = 1;
    }
    if (datetime[5] > 59)
    {
        datetime[5] = 0;
        modified = 1;
    }

    return modified;
}

#ifdef MMS_SUPPORT


/*****************************************************************************
 * FUNCTION
 *  goto_mms_screen
 * DESCRIPTION
 *  MMS entry point from MMI menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/* Executed in MMI task */
void goto_mms_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GOTO_MMS_SCREEN);
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());

#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode() && is_mms_storage_exported_to_pc())   /* Check if MMS should be disabled */
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_IN_USB_MODE_AND_EXIT);
        mmi_usb_app_unavailable_popup(0);
        return;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    if (!MSF_wapIsReady())
    {
        WGUI_CTX->not_ready_for_MMS = 1;
        wap_entry_widget_not_ready();
        return;
    }

    /* Disable key to prevent sending duplicated requests */
    ClearAllKeyHandler();
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);

#ifndef __UNIFIED_MSG_SUPPORT__
    if (MSF_moduleIsRunning(MSF_MODID_MEA))
    {
        /* 
         * Abnormal case:
         * History node of MEA is deleted by someone, and users enter MMS menu again.
         */
        ilm_struct *ilm_ptr = NULL;

        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GOTO_MMS_SCREEN_AND_MEA_RUNNING);

        WAP_DBG_ASSERT(0);

        ilm_ptr = allocate_ilm(MOD_MMI);
        ilm_ptr->msg_id = MSG_ID_WAP_BROWSER_SHUTDOWN_REQ;
        ilm_ptr->peer_buff_ptr = NULL;
        ilm_ptr->local_para_ptr = (local_para_struct*) NULL;
        SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);

        ilm_ptr = allocate_ilm(MOD_MMI);
        ilm_ptr->msg_id = MSG_ID_MEA_STARTUP_REQ;
        ilm_ptr->peer_buff_ptr = NULL;
        ilm_ptr->local_para_ptr = NULL;
        SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);
    }
    else
#endif /* __UNIFIED_MSG_SUPPORT__ */ 
    {
        ilm_struct *ilm_ptr = NULL;

        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GOTO_MMS_SCREEN_AND_MEA_NOT_RUNNING);

        ilm_ptr = allocate_ilm(MOD_MMI);
        ilm_ptr->msg_id = MSG_ID_MEA_STARTUP_REQ;
        ilm_ptr->peer_buff_ptr = NULL;
        ilm_ptr->local_para_ptr = NULL;
        SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);
    }
    HDIa_widgetExtDisplayTransitionAnimationNoEnd(KAL_TRUE);
}

/*****************************************************************************
 * FUNCTION
 *  mms_text_insert_hdlr
 * DESCRIPTION
 *  Start MEA in editor with a text buffer (and subject) inserted
 * CALLS
 *  
 * PARAMETERS
 *  subject         [IN]         
 *  subject_len     [IN]        
 *  text            [IN]         
 *  text_len        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mms_text_insert_hdlr(char *subject, unsigned int subject_len, char *text, unsigned int text_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMS_TEXT_INSERT_HDLR);

  #ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode() && is_mms_storage_exported_to_pc())
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_IN_USB_MODE_AND_EXIT);
        mmi_usb_app_unavailable_popup(0);
        return;
    }
  #endif /* __USB_IN_NORMAL_MODE__ */ 

  #ifdef __UNIFIED_COMPOSER_SUPPORT__
    {
        mmi_uc_entry_write_struct data;
        memset(&data, 0x00, sizeof(mmi_uc_entry_write_struct));
        data.subject = (kal_uint8*) subject;
        data.text_buffer = (kal_uint8*) text;
        data.text_num = text_len;
        data.info_type = MMI_UC_INFO_TYPE_MMS;
        data.msg_type = MMI_UC_MSG_TYPE_MMS_ONLY;
        mmi_uc_entry_write_msg_with_content(MMI_UC_STATE_WRITE_NEW_MSG, &data);
        return;
    }
  #else
    {
        mms_content_entry_struct data;
        
        memset(&data, 0x00, sizeof(mms_content_entry_struct));
        data.mode = MEA_NEW_BUFFER;
        data.subject = subject;
        data.text_buffer = text;
        goto_mms_editor(&data);
    }
  #endif  /* __UNIFIED_COMPOSER_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mms_content_insert_hdlr
 * DESCRIPTION
 *  Start MEA in editor with a file inserted
 * CALLS
 *  
 * PARAMETERS
 *  content_source      [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mms_content_insert_hdlr(char *content_source)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMS_CONTENT_INSERT_HDLR);

  #ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode() && is_mms_storage_exported_to_pc())
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_IN_USB_MODE_AND_EXIT);
        mmi_usb_app_unavailable_popup(0);
        return;
    }
  #endif /* __USB_IN_NORMAL_MODE__ */ 

  #ifdef __UNIFIED_COMPOSER_SUPPORT__
    {
        mmi_uc_entry_write_struct data;
        memset(&data, 0x00, sizeof(mmi_uc_entry_write_struct));
        data.file_path = (kal_uint8*) content_source;
        data.info_type = MMI_UC_INFO_TYPE_MMS;
        mmi_uc_entry_write_msg_with_content(MMI_UC_STATE_WRITE_NEW_MSG, &data);
        return;
    }
  #else
    {
        mms_content_entry_struct data;
        
        memset(&data, 0x00, sizeof(mms_content_entry_struct));
        data.mode = MEA_NEW_FILE;
        data.file_path = content_source;
        goto_mms_editor(&data);
    }
  #endif  /* __UNIFIED_COMPOSER_SUPPORT__ */
}

/*****************************************************************************
 * FUNCTION
 *  mms_content_insert_hdlr_with_callback
 * DESCRIPTION
 *  Start MMS editor with the specified content. A callback function is provided so that MMS editor
 *  can evoke the function when work is done.
 * CALLS
 *  
 * PARAMETERS
 *  data      [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mms_content_insert_hdlr_with_callback(mms_content_entry_struct *entry_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMS_CONTENT_INSERT_HDLR_WITH_CALLBACK);
    
  #ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode() && is_mms_storage_exported_to_pc())
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_IN_USB_MODE_AND_EXIT);
        mmi_usb_app_unavailable_popup(0);
        return;
    }
  #endif /* __USB_IN_NORMAL_MODE__ */ 

    if(!mms_is_ready())
    {
        DisplayPopup((U8*) GetString(STR_GLOBAL_NOT_AVAILABLE), IMG_GLOBAL_WARNING, 0, UI_POPUP_NOTIFYDURATION_TIME, WARNING_TONE);
        if (entry_data && entry_data->callback)
        {
            entry_data->callback(entry_data->callback_param);
        }
        return;
    }
  
  #ifdef __UNIFIED_COMPOSER_SUPPORT__
    {
        mmi_uc_entry_write_struct data;
        memset(&data, 0x00, sizeof(mmi_uc_entry_write_struct));
        data.file_path = (kal_uint8*) entry_data->file_path;
        data.info_type = MMI_UC_INFO_TYPE_MMS;
        data.callback = entry_data->callback;
        data.callback_para = entry_data->callback_param;
        mmi_uc_entry_write_msg_with_content(MMI_UC_STATE_WRITE_NEW_MSG, &data);
        return;
    }
  #else
    {
        goto_mms_editor(entry_data);
    }
  #endif  /* __UNIFIED_COMPOSER_SUPPORT__ */
}

/*****************************************************************************
 * FUNCTION
 *  mms_address_insert_hdlr
 * DESCRIPTION
 *  Start MMS in editor with a file inserted
 * CALLS
 *  
 * PARAMETERS
 *  address     [IN]        Phone number to be inserted
 * RETURNS
 *  void
 *****************************************************************************/
void mms_address_insert_hdlr(char *address)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMS_ADDRESS_INSERT_HDLR);

  #ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode() && is_mms_storage_exported_to_pc())
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_IN_USB_MODE_AND_EXIT);
        mmi_usb_app_unavailable_popup(0);
        return;
    }
  #endif /* __USB_IN_NORMAL_MODE__ */ 
    {
      int size;
      char *strAddress;
      
      size = widget_ucs2_to_utf8_length_in_bytes((const kal_uint8*)address) + 1;
      strAddress = MSF_MEM_ALLOC(MSF_MODID_MSM, size + 1);
      widget_ucs2_to_utf8_string(
          (kal_uint8*) strAddress,
          size + 1,
          (const kal_uint8*)address);
    
        if(meaGetAddrType(strAddress) == MEA_ADDR_TYPE_NONE)
        {
            DisplayPopup(
                (PU8) GetString(MEA_STR_ID_INVALID_RECIP_ADDRESS),
                IMG_GLOBAL_WARNING,
                0,
                UI_POPUP_NOTIFYDURATION_TIME,
                WARNING_TONE);
        
            return;
        }
    }
  #ifdef __UNIFIED_COMPOSER_SUPPORT__
    {
        mmi_uc_entry_write_struct data;
        mmi_uc_addr_struct addr;
        memset(&data, 0x00, sizeof(mmi_uc_entry_write_struct));
        memset(&addr, 0x00, sizeof(mmi_uc_addr_struct));
        data.addr_num = 1;
        addr.addr = (kal_uint8*) address;
        if (mmi_ucs2chr(address, L'@') == NULL)
        {
            addr.type = MMI_UC_ADDRESS_TYPE_PHONE_NUMBER;
        }
        else
        {
            addr.type = MMI_UC_ADDRESS_TYPE_EMAIL;
        }
        addr.group = MMI_UC_ADDRESS_GROUP_TYPE_TO;
        data.addr = &addr;
        data.msg_type = MMI_UC_MSG_TYPE_MMS_ONLY;
        data.info_type = MMI_UC_INFO_TYPE_MMS;
        mmi_uc_entry_write_msg_with_content(MMI_UC_STATE_WRITE_NEW_MSG, &data);
        return;
    }
  #else
    {
        mms_content_entry_struct data;

        memset(&data, 0x00, sizeof(mms_content_entry_struct));
        data.mode = MEA_NEW_ADDRESS;
        data.addr = address;
        goto_mms_editor(&data);
    }
  #endif  /* __UNIFIED_COMPOSER_SUPPORT__ */
}
/*****************************************************************************
 * FUNCTION
 *  mms_general_insert_hdlr
 * DESCRIPTION
 *  Start MMS in editor with a mms_content_entry_struct is filled
 * CALLS
 *  
 * PARAMETERS
 *  data     [IN]        the mms_content_entry_struct data
 * RETURNS
 *  void
 *****************************************************************************/
void mms_general_insert_hdlr (mms_content_entry_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode() && is_mms_storage_exported_to_pc())
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_IN_USB_MODE_AND_EXIT);
        mmi_usb_app_unavailable_popup(0);
        return;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    if(!mms_is_ready())
    {
        DisplayPopup((U8*) GetString(STR_GLOBAL_NOT_AVAILABLE), IMG_GLOBAL_WARNING, 0, UI_POPUP_NOTIFYDURATION_TIME, WARNING_TONE);
        if (data && data->callback)
        {
            data->callback(data->callback_param);
        }
        return;
    }
    
    if(data->addr != NULL)
    {
      int size;
      char *strAddress;
      
      size = widget_ucs2_to_utf8_length_in_bytes((const kal_uint8*)data->addr) + 1;
      strAddress = MSF_MEM_ALLOC(MSF_MODID_MSM, size + 1);
      widget_ucs2_to_utf8_string(
          (kal_uint8*) strAddress,
          size + 1,
          (const kal_uint8*)data->addr);
    
        if(meaGetAddrType(strAddress) == MEA_ADDR_TYPE_NONE)
        {
            DisplayPopup(
                (PU8) GetString(MEA_STR_ID_INVALID_RECIP_ADDRESS),
                IMG_GLOBAL_WARNING,
                0,
                UI_POPUP_NOTIFYDURATION_TIME,
                WARNING_TONE);
        
            return;
        }
    }

#ifdef __UNIFIED_COMPOSER_SUPPORT__
    {
        mmi_uc_entry_write_struct uc_data;
        mmi_uc_addr_struct addr;
        memset(&uc_data, 0x00, sizeof(mmi_uc_entry_write_struct));
        memset(&addr, 0x00, sizeof(mmi_uc_addr_struct));

        uc_data.callback = data->callback;
        uc_data.callback_para = data->callback_param;
        uc_data.subject = (kal_uint8*) data->subject;
        uc_data.text_buffer = (kal_uint8*) data->text_buffer;
        uc_data.text_num = widget_ucs2_to_utf8_length_in_bytes((kal_uint8*) data->text_buffer);
        uc_data.file_path = (kal_uint8*) data->file_path;
        if(data->addr != NULL)
        {
            uc_data.addr_num = 1;
            addr.addr = (kal_uint8*) data->addr;
            if (mmi_ucs2chr(data->addr, L'@') == NULL)
            {
                addr.type = MMI_UC_ADDRESS_TYPE_PHONE_NUMBER;
            }
            else
            {
                addr.type = MMI_UC_ADDRESS_TYPE_EMAIL;
            }
            addr.group = MMI_UC_ADDRESS_GROUP_TYPE_TO;
            uc_data.addr = &addr;
        }

        uc_data.msg_type = MMI_UC_MSG_TYPE_MMS_ONLY;
        uc_data.info_type = MMI_UC_INFO_TYPE_MMS;
        mmi_uc_entry_write_msg_with_content(MMI_UC_STATE_WRITE_NEW_MSG, &uc_data);
        return;
    }
#endif /*__UNIFIED_COMPOSER_SUPPORT__*/
    data->mode = MEA_NEW_GENERAL;
    goto_mms_editor(data);
}
/***************************************************************************** 
 * FUNCTION 
 *  wap_content_is_mms_forward 
 * DESCRIPTION 
 *  The function is used to check if the media can be forwarded to MMS 
 * PARAMETERS 
 *  filename     [IN]        Encoded by UCS2 
 * RETURNS 
 *  0: FASLE, 1: TRUE 
 *****************************************************************************/ 
int wap_content_is_mms_forward(const char *filename) 
{ 
    /*----------------------------------------------------------------*/ 
    /* Local Variables                                                */ 
    /*----------------------------------------------------------------*/ 

    /*----------------------------------------------------------------*/ 
    /* Code Body                                                      */ 
    /*----------------------------------------------------------------*/ 
    extern int mms_is_file_can_be_forwarded_to_mms(const char *input);
    return mms_is_file_can_be_forwarded_to_mms(filename);
} 

#ifdef __USB_IN_NORMAL_MODE__


/*****************************************************************************
 * FUNCTION
 *  mms_on_enter_usb_mode
 * DESCRIPTION
 *  This function is invoked when entering USB mode. When WAP MMS is ready
 *  send MSG_ID_MMS_ENTER_USB_MODE_RSP to MMI.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mms_on_enter_usb_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->msg_id = MSG_ID_MMS_ENTER_USB_MODE_REQ;
    ilm_ptr->peer_buff_ptr = NULL;
    ilm_ptr->local_para_ptr = (local_para_struct*) NULL;
    SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  mms_on_exit_usb_mode
 * DESCRIPTION
 *  This function is invoked when leaving USB mode. When WAP MMS is ready
 *  send MSG_ID_MMS_EXIT_USB_MODE_RSP to MMI.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mms_on_exit_usb_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->msg_id = MSG_ID_MMS_EXIT_USB_MODE_REQ;
    ilm_ptr->peer_buff_ptr = NULL;
    ilm_ptr->local_para_ptr = (local_para_struct*) NULL;
    SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);
}
#endif /* __USB_IN_NORMAL_MODE__ */ 

/*****************************************************************************
 * FUNCTION
 *  mms_enter_sms_editor_handler
 * DESCRIPTION
 *  This function is invoked by WAP RPC and runs as MMI task. It enters sms editor with specified information.
 * PARAMETERS
 *  p
 * RETURNS
 *  void
 *****************************************************************************/
void mms_enter_sms_editor_handler(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_api_entry_write_struct sendData;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&sendData, 0, sizeof(mmi_frm_sms_api_entry_write_struct));

    sendData.string = NULL;
    sendData.stringlength = 0;
    sendData.dcs = SMSAL_UCS2_DCS;
    sendData.flag = MMI_FRM_SMS_ENTRY_WRITE_REPLY;
    sendData.ascii_addr = (U8 *)p;

    mmi_frm_sms_api_entry_write_msg(&sendData);
    MSF_MEM_FREE(MSF_MODID_WIDGET, p);
}

/*****************************************************************************
 * FUNCTION
 *  wap_plmn_number_indication_callback
 * DESCRIPTION
 *  This function is used to infom WAP task of PLMN number of current operator.
 *  MMS version may be changed by this number. Ex: Taiwan FET => MMS v1.0
 * CALLS
 *  
 * PARAMETERS
 *  plmn_number     [IN]        PLMN number of network we campon
 * RETURNS
 *  void
 *****************************************************************************/
void wap_plmn_number_indication_callback(const unsigned char *plmn_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    extern void setMmscVersion(const char *curPLMN);

    setMmscVersion((const char*)plmn_number);
}


/*****************************************************************************
 * FUNCTION
 *  wap_roaming_status_indication_callback
 * DESCRIPTION
 *  This function is used to infom WAP task of PLMN number of current operator.
 *  MMS version may be changed by this number. Ex: Taiwan FET => MMS v1.0
 * CALLS
 *  
 * PARAMETERS
 *  isRoaming           [IN]        
 *  plmn_number(?)      [IN]        PLMN number of network we campon
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_DUAL_SIM__
void wap_roaming_status_indication_callback(int simId, unsigned long isRoaming)
#else
void wap_roaming_status_indication_callback(unsigned long isRoaming)
#endif
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    extern void writeRoamingStatusForMMS(int simId, unsigned long isRoaming);
#ifndef __MMI_DUAL_SIM__
    writeRoamingStatusForMMS(MMS_SIM_CARD_MASTER, isRoaming);
#else
    if (simId == 0)
    {
        writeRoamingStatusForMMS(MMS_SIM_CARD_MASTER, isRoaming);
    }
    else if (simId == 1)
    {
        writeRoamingStatusForMMS(MMS_SIM_CARD_SLAVE, isRoaming);
    }
    else
    {
#ifndef __PRODUCTION_RELEASE__
        ASSERT(0);
#endif
        writeRoamingStatusForMMS(MMS_SIM_CARD_MASTER, isRoaming);        
    }
#endif
}

/*****************************************************************************
 * FUNCTION
 *  wap_get_mms_content_class
 * DESCRIPTION
 *  This function is used to get mms content class
 * CALLS
 *  
 * PARAMETERS
 *  NONE
 * RETURNS
 *  wap_mms_content_class_enum
 *****************************************************************************/
wap_mms_content_class_enum wap_get_mms_content_class(void)
{
    wap_mms_content_class_enum result = WAP_MMS_CONTENT_CLASS_TEXT;

#if (defined(MP4_CODEC) && defined(JPG_DECODE) && defined(__MMI_VCALENDAR__) && defined(__MMI_VCARD__) && defined(__DRM_SUPPORT__) && WAP_CUSTOM_CFG_MAX_MMS_MSG_SIZE >= 300*1024)
    result = WAP_MMS_CONTENT_CLASS_VIDEO_RICH;
#elif (defined(MP4_CODEC) && defined(JPG_DECODE) && defined(__MMI_VCALENDAR__) && defined(__MMI_VCARD__) && defined(__DRM_SUPPORT__) && WAP_CUSTOM_CFG_MAX_MMS_MSG_SIZE >= 100*1024)
    result = WAP_MMS_CONTENT_CLASS_VIDEO_BASIC;
#elif (defined(JPG_DECODE) && defined(__MMI_VCALENDAR__) && defined(__MMI_VCARD__) && defined(__DRM_SUPPORT__) && WAP_CUSTOM_CFG_MAX_MMS_MSG_SIZE >= 100*1024)
    result = WAP_MMS_CONTENT_CLASS_IMAGE_RICH;
#elif (defined(JPG_DECODE) && defined(__MMI_VCALENDAR__) && defined(__MMI_VCARD__) && WAP_CUSTOM_CFG_MAX_MMS_MSG_SIZE >= 30*1024)
    result = WAP_MMS_CONTENT_CLASS_IMAGE_BASIC;
#endif
    return result;
}

/*****************************************************************************
 * FUNCTION
 *  wap_get_max_mms_size_in_restricted_mode
 * DESCRIPTION
 *  This function is used to get max mms size in restricted creation mode
 * CALLS
 *  
 * PARAMETERS
 *  NONE
 * RETURNS
 *  Max size
 *****************************************************************************/
kal_uint32 wap_get_max_mms_size_in_restricted_mode(void)
{
    wap_mms_content_class_enum mms_content_class = wap_get_mms_content_class();

    if (mms_content_class == WAP_MMS_CONTENT_CLASS_VIDEO_RICH)
    {
        return 300*1024;
    }
    else if (mms_content_class == WAP_MMS_CONTENT_CLASS_VIDEO_BASIC ||
             mms_content_class == WAP_MMS_CONTENT_CLASS_IMAGE_RICH)
    {
        return 100*1024;
    }
    else
    {
        return 30*1024;
    }        
}

#endif /* MMS_SUPPORT */ 

/**************************************************************************
*
*     WPS Functionalities
*
***************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  wps_pun_uint32
 * DESCRIPTION
 *  this function will be called when MSF environment send message to module JAS.
 * PARAMETERS
 *  op      [IN]        
 *  buf     [?]         
 *  p       [?]         
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 wps_pun_uint32(kal_uint8 op, kal_uint8 *buf, kal_uint32 *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (op)
    {
        case WPS_PUN_PACK:
            buf[0] = ((*p >> 24) & 0xff);
            buf[1] = ((*p >> 16) & 0xff);
            buf[2] = ((*p >> 8) & 0xff);
            buf[3] = *p & 0xff;
            break;
        case WPS_PUN_UNPACK:
            *p = (buf[0] << 24) + (buf[1] << 16) + (buf[2] << 8) + buf[3];
            break;
    }
    return 4;
}


/*****************************************************************************
 * FUNCTION
 *  wps_pun_string
 * DESCRIPTION
 *  this function will be called when MSF environment send message to module JAS.
 * PARAMETERS
 *  op      [IN]        
 *  buf     [?]         
 *  p       [IN]        
 *  len     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 wps_pun_string(kal_uint8 op, kal_uint8 *buf, kal_uint8 **p, kal_uint32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (len == 0)
    {
        return 0;
    }

    switch (op)
    {
        case WPS_PUN_PACK:
            memcpy(buf, *p, len);
            break;
        case WPS_PUN_UNPACK:
            *p = buf;
            break;
    }
    return len;
}


/*****************************************************************************
 * FUNCTION
 *  wps_pun_var_part
 * DESCRIPTION
 *  this function will be called when MSF environment send message to module JAS.
 * PARAMETERS
 *  op          [IN]        
 *  msg_id      [IN]        
 *  p           [?]         
 *  buf         [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 wps_pun_var_part(kal_uint8 op, kal_uint32 msg_id, void *p, kal_uint8 *buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 pos = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (msg_id)
    {
        case MSG_ID_WPS_SET_CHANNEL_REQ:
        {
            wps_set_channel_req_var_struct *v = (wps_set_channel_req_var_struct*) p;

            switch (op)
            {
                case WPS_PUN_PACK:
                case WPS_PUN_UNPACK:
                    pos += wps_pun_uint32(op, buf, &(v->static_header_len));
                    pos += wps_pun_string(op, buf + pos, &(v->static_header), v->static_header_len);
                    break;
                case WPS_PUN_SIZE:
                    pos += sizeof(kal_uint32) + v->static_header_len;
                    break;
                default:
                    return 0;
            }
            break;
        }
        case MSG_ID_WPS_HTTP_REQ:
        {
            wps_http_req_var_struct *v = (wps_http_req_var_struct*) p;

            switch (op)
            {
                case WPS_PUN_PACK:
                case WPS_PUN_UNPACK:
                    pos += wps_pun_uint32(op, buf, &(v->request_header_len));
                    pos += wps_pun_string(op, buf + pos, &(v->request_header), v->request_header_len);
                    pos += wps_pun_uint32(op, buf + pos, &(v->request_url_len));
                    pos += wps_pun_string(op, buf + pos, &(v->request_url), v->request_url_len);
                    pos += wps_pun_uint32(op, buf + pos, &(v->post_segment_len));
                    pos += wps_pun_string(op, buf + pos, &(v->post_segment), v->post_segment_len);
                    break;
                case WPS_PUN_SIZE:
                    pos += sizeof(kal_uint32) + v->request_header_len;
                    pos += sizeof(kal_uint32) + v->request_url_len;
                    pos += sizeof(kal_uint32) + v->post_segment_len;
                    break;
                default:
                    return 0;
            }
            break;
        }
        case MSG_ID_WPS_HTTP_RSP:
        {
            wps_http_rsp_var_struct *v = (wps_http_rsp_var_struct*) p;

            switch (op)
            {
                case WPS_PUN_PACK:
                case WPS_PUN_UNPACK:
                    pos += wps_pun_uint32(op, buf, &(v->new_url_len));
                    pos += wps_pun_string(op, buf + pos, &(v->new_url), v->new_url_len);
                    pos += wps_pun_uint32(op, buf + pos, &(v->reply_header_len));
                    pos += wps_pun_string(op, buf + pos, &(v->reply_header), v->reply_header_len);
                    pos += wps_pun_uint32(op, buf + pos, &(v->reply_segment_len));
                    pos += wps_pun_string(op, buf + pos, &(v->reply_segment), v->reply_segment_len);
                    break;
                case WPS_PUN_SIZE:
                    pos += sizeof(kal_uint32) + v->new_url_len;
                    pos += sizeof(kal_uint32) + v->reply_header_len;
                    pos += sizeof(kal_uint32) + v->reply_segment_len;
                    break;
                default:
                    return 0;
            }
            break;
        }
        case MSG_ID_WPS_READ_CONTENT_RSP:
        {
            wps_read_content_rsp_var_struct *v = (wps_read_content_rsp_var_struct*) p;

            switch (op)
            {
                case WPS_PUN_PACK:
                case WPS_PUN_UNPACK:
                    pos += wps_pun_uint32(op, buf, &(v->reply_segment_len));
                    pos += wps_pun_string(op, buf + pos, &(v->reply_segment), v->reply_segment_len);
                    break;
                case WPS_PUN_SIZE:
                    pos = sizeof(kal_uint32) + v->reply_segment_len;
                    break;
                default:
                    return 0;
            }
            break;
        }
        case MSG_ID_WPS_POST_CONTENT_RES:
        {
            wps_post_content_res_var_struct *v = (wps_post_content_res_var_struct*) p;

            switch (op)
            {
                case WPS_PUN_PACK:
                case WPS_PUN_UNPACK:
                    pos += wps_pun_uint32(op, buf, &(v->post_segment_len));
                    pos += wps_pun_string(op, buf + pos, &(v->post_segment), v->post_segment_len);
                    break;
                case WPS_PUN_SIZE:
                    pos = sizeof(kal_uint32) + v->post_segment_len;
                    break;
                default:
                    return 0;
            }
            break;
        }
        case MSG_ID_WPS_CLEAR_REQ:
        {
            wps_clear_req_var_struct *v = (wps_clear_req_var_struct*) p;

            switch (op)
            {
                case WPS_PUN_PACK:
                case WPS_PUN_UNPACK:
                    pos += wps_pun_uint32(op, buf, &(v->cache_url_len));
                    pos += wps_pun_string(op, buf + pos, &(v->cache_url), v->cache_url_len);
                    break;
                case WPS_PUN_SIZE:
                    pos += sizeof(kal_uint32) + v->cache_url_len;
                    break;
                default:
                    return 0;
            }
            break;
        }
        case MSG_ID_WAP_MMI_FILE_DL_IND:
        {
            wap_mmi_file_dl_var_struct *v = (wap_mmi_file_dl_var_struct*) p;

            switch (op)
            {
                case WPS_PUN_PACK:
                case WPS_PUN_UNPACK:
                    pos += wps_pun_uint32(op, buf + pos, &(v->header_len));
                    pos += wps_pun_string(op, buf + pos, &(v->header), v->header_len);
                    pos += wps_pun_uint32(op, buf + pos, &(v->content_len));
                    pos += wps_pun_string(op, buf + pos, &(v->content), v->content_len);
                    break;
                case WPS_PUN_SIZE:
                    pos += sizeof(kal_uint32) + v->header_len;
                    pos += sizeof(kal_uint32) + v->content_len;
                    break;
                default:
                    return 0;
            }
            break;
        }
    }
    return pos;
}


/*****************************************************************************
 * FUNCTION
 *  wps_start_base_timer
 * DESCRIPTION
 *  This is the function to start base timer
 * PARAMETERS
 *  base_timer_p        [IN]        The stack timer
 *  time_out            [IN]        Time-out
 * RETURNS
 *  void
 *****************************************************************************/
void wps_start_base_timer(void *base_timer_p, unsigned int time_out)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stack_start_timer((stack_timer_struct*) base_timer_p, 0, time_out);
}   /* end of wps_start_base_timer */


/*****************************************************************************
 * FUNCTION
 *  wps_stop_base_timer
 * DESCRIPTION
 *  This is the function to stop base timer.
 * PARAMETERS
 *  base_timer_p        [IN]        The stack timer
 * RETURNS
 *  void
 *****************************************************************************/
void wps_stop_base_timer(void *base_timer_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stack_stop_timer((stack_timer_struct*) base_timer_p);
}   /* end of wps_stop_base_timer */


/*****************************************************************************
 * FUNCTION
 *  wps_handle_timer_expiry
 * DESCRIPTION
 *  This is the function to timer expiry event.
 * PARAMETERS
 *  ilm_ptr     [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
void wps_handle_timer_expiry(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (stack_is_time_out_valid(&wps_base_timer))
    {
        evshed_timer_handler(wps_event_scheduler);
    }
    stack_process_time_out(&wps_base_timer);

}   /* end of wps_handle_timer_expiry */

#ifdef JATAAYU_SUPPORT


/*****************************************************************************
 * FUNCTION
 *  wps_timer_mem_alloc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *wps_timer_mem_alloc(unsigned int size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return jdd_MemAlloc(1, size);
}


/*****************************************************************************
 * FUNCTION
 *  wps_timer_mem_free
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mem_ptr     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void wps_timer_mem_free(void *mem_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jdd_MemFree(mem_ptr);
}
#endif /* JATAAYU_SUPPORT */ 


/*****************************************************************************
 * FUNCTION
 *  wps_init_timer
 * DESCRIPTION
 *  This function initializes the timers for WPS.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wps_init_timer(void)
{
#ifdef JATAAYU_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Create Base timer */
    stack_init_timer(&wps_base_timer, "WPS_BASE_TIMER", MOD_WPS);

    /* Create an Event Scheduler */
    wps_event_scheduler = (event_scheduler*) new_evshed(
                                                &wps_base_timer,
                                                wps_start_base_timer,
                                                wps_stop_base_timer,
                                                0,
                                                (malloc_fp_t) wps_timer_mem_alloc,
                                                wps_timer_mem_free,
                                                0);
#endif /* JATAAYU_SUPPORT */ 
    return;
}   /* end of wps_init_timer */


/*****************************************************************************
 * FUNCTION
 *  wps_init
 * DESCRIPTION
 *  This function should be called to Initialize the WAP PS task
 * CALLS
 *  
 * PARAMETERS
 *  task_indx       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool wps_init(task_indx_type task_indx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wps_init_timer();

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  wps_reset
 * DESCRIPTION
 *  This function should be called to reset the WAP task
 * CALLS
 *  
 * PARAMETERS
 *  task_indx       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool wps_reset(task_indx_type task_indx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  wps_task_main
 * DESCRIPTION
 *  This function is used to be WAP PS task entry point
 * CALLS
 *  
 * PARAMETERS
 *  task_entry_ptr      [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void wps_task_main(task_entry_struct *task_entry_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct current_ilm;
    kal_uint32 my_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_get_my_task_index(&my_index);

    while (1)
    {
        receive_msg_ext_q(task_info_g[task_entry_ptr->task_indx].task_ext_qid, &current_ilm);

        stack_set_active_module_id(my_index, current_ilm.dest_mod_id);
        wps_fsm(&current_ilm);  /* process external ILM */
    }
}


/*****************************************************************************
 * FUNCTION
 *  wps_create
 * DESCRIPTION
 *  This function is used to create WAP PS task
 * CALLS
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool wps_create(comptask_handler_struct **handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(WPS_TASK_SUPPORT)
    return KAL_FALSE;
#endif 
    static const comptask_handler_struct ms_handler_info = 
    {
        wps_task_main,  /* task entry function */
        wps_init,       /* task initialization function */
        NULL,           /* task configuration function */
        wps_reset,      /* task reset handler */
        NULL,           /* task termination handler */
    };

    *handle = (comptask_handler_struct*) & ms_handler_info;
    return KAL_TRUE;
}

#ifdef __UNIFIED_MSG_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  wap_um_entry_msg_wap_push
 * DESCRIPTION
 *  This function is to implement viewing a specific push message by index
 * CALLS
 *  
 * PARAMETERS
 *  msg_box_type        [IN]        
 *  msg_index           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wap_um_entry_msg_wap_push(kal_uint16 msg_box_type, kal_uint16 msg_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* send MSG_ID_WAP_BROWSER_STARTUP_REQ to open push message */
    ilm_struct *ilm_ptr = NULL;
    wap_browser_startup_req_struct *browser_startup_req = (wap_browser_startup_req_struct*) construct_local_para
        ((kal_uint16) sizeof(wap_browser_startup_req_struct), TD_CTRL);

    /* fill local parameter */
    browser_startup_req->type = 8;                          /* view push */
    browser_startup_req->url[0] = (kal_uint8) msg_index;    /* use 1st byte of url as message index */

    /* compose ILM */
    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->local_para_ptr = (local_para_struct*) browser_startup_req;
    ilm_ptr->msg_id = MSG_ID_WAP_BROWSER_STARTUP_REQ;
    ilm_ptr->peer_buff_ptr = NULL;
    SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr)
}


/*****************************************************************************
 * FUNCTION
 *  wap_um_entry_write_mms
 * DESCRIPTION
 *  This function is to enter MMS editor screen
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wap_um_entry_write_mms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    mea_um_entry_req_struct *entry_req = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode() && is_mms_storage_exported_to_pc())
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WAP_UM_ENTRY_WRITE_MMS);
        mmi_usb_app_unavailable_popup(0);
        return;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    /* fill local parameter */
    entry_req = (mea_um_entry_req_struct*) construct_local_para((kal_uint16) sizeof(mea_um_entry_req_struct), TD_CTRL);
    entry_req->mode = MEA_UM_ENTRY_WRITE_MSG;

    /* compose ILM */
    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->local_para_ptr = (local_para_struct*) entry_req;
    ilm_ptr->msg_id = MSG_ID_MEA_UM_ENTRY_REQ;
    ilm_ptr->peer_buff_ptr = NULL;
    SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr)
}


/*****************************************************************************
 * FUNCTION
 *  wap_um_entry_msg_mms
 * DESCRIPTION
 *  This function is to enter MMS reading (player) screen by specifying MMS folder and index in that folder
 * CALLS
 *  
 * PARAMETERS
 *  msg_box_type        [IN]        
 *  msg_index           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wap_um_entry_msg_mms(kal_uint16 msg_box_type, kal_uint16 msg_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    mea_um_entry_req_struct *entry_req = NULL;
    MeaFolder folder = wap_translate_um_folder_2_mea_folder(msg_box_type);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode() && is_mms_storage_exported_to_pc())
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WAP_UM_ENTRY_MSG_MMS);
        mmi_usb_app_unavailable_popup(0);
        return;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    /* fill local parameter */
    entry_req = (mea_um_entry_req_struct*) construct_local_para((kal_uint16) sizeof(mea_um_entry_req_struct), TD_CTRL);
    entry_req->mode = MEA_UM_ENTRY_READ_MSG;
    entry_req->msg_box = folder;
    entry_req->msg_index = msg_index;

    /* compose ILM */
    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->local_para_ptr = (local_para_struct*) entry_req;
    ilm_ptr->msg_id = MSG_ID_MEA_UM_ENTRY_REQ;
    ilm_ptr->peer_buff_ptr = NULL;
    SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr)
}


/*****************************************************************************
 * FUNCTION
 *  wap_um_entry_template_mms
 * DESCRIPTION
 *  This function is to enter MMS template list screen
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wap_um_entry_template_mms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    mea_um_entry_req_struct *entry_req = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode() && is_mms_storage_exported_to_pc())
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WAP_UM_ENTRY_TEMPLATE_MMS);
        mmi_usb_app_unavailable_popup(0);
        return;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    /* fill local parameter */
    entry_req = (mea_um_entry_req_struct*) construct_local_para((kal_uint16) sizeof(mea_um_entry_req_struct), TD_CTRL);
    entry_req->mode = MEA_UM_ENTRY_TEMPLATE;

    /* compose ILM */
    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->local_para_ptr = (local_para_struct*) entry_req;
    ilm_ptr->msg_id = MSG_ID_MEA_UM_ENTRY_REQ;
    ilm_ptr->peer_buff_ptr = NULL;
    SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr)
}


/*****************************************************************************
 * FUNCTION
 *  wap_um_entry_setting_mms
 * DESCRIPTION
 *  This function is to enter MMS setting screen
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wap_um_entry_setting_mms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    mea_um_entry_req_struct *entry_req = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode() && is_mms_storage_exported_to_pc())
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WAP_UM_ENTRY_SETTING_MMS);
        mmi_usb_app_unavailable_popup(0);
        return;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    /* fill local parameter */
    entry_req = (mea_um_entry_req_struct*) construct_local_para((kal_uint16) sizeof(mea_um_entry_req_struct), TD_CTRL);
    entry_req->mode = MEA_UM_ENTRY_SETTING;

    /* compose ILM */
    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->local_para_ptr = (local_para_struct*) entry_req;
    ilm_ptr->msg_id = MSG_ID_MEA_UM_ENTRY_REQ;
    ilm_ptr->peer_buff_ptr = NULL;
    SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr)
}


/*****************************************************************************
 * FUNCTION
 *  wap_is_message_resource_available
 * DESCRIPTION
 *  The function is used to check if UM enter MMS menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  KAL_FASLE, KAL_TRUE
 *****************************************************************************/
int wap_is_message_resource_available()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!MSF_wapIsReady() || !MSF_moduleIsRunning(MSF_MODID_MEA) || 
        IsScreenPresent(WAP_SCREEN_WIDGET) || WGUI_CTX->is_shutdown_UI == 1 ||
        wap_status != WAP_RUNNING)
    {
        return KAL_FALSE;
    }
    return KAL_TRUE;
}

#endif /* __UNIFIED_MSG_SUPPORT__ */ 


/****************************************************************
 * Default value for WCSS input
 ***************************************************************/
/*****************************************************************************
 * Defalut input value according to wap-input-format
 *
 * Even though MMI WCSS editor will setup default value, users might submit before
 * editing anything
 *
 * This also can not be delayed until widget_paint_gadget_input because widget_paint_gadget_input might 
 * not be invoked if the input gadget is not displayed inside the screen.
 *
 *****************************************************************************/

/* return 0 for error */


/*****************************************************************************
 * FUNCTION
 *  widget_css_format_char_to_default_char
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fmt_char        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static char widget_css_format_char_to_default_char(char fmt_char)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (fmt_char)
    {
        case 'A':
        case 'a':
        case 'X':
        case 'x':
        case 'M':
        case 'm':
            return ' ';
        case 'N':
        case 'n':
            return '0';
        default:
            /* WAP_DBG_ASSERT(0); */
            return (char)0;
    }
}

/* return -1 for error */


/*****************************************************************************
 * FUNCTION
 *  widget_set_wcss_input_format_default_value
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buffer              [IN]         
 *  maxlen              [IN]        
 *  format_pattern      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int widget_set_wcss_input_format_default_value(kal_uint8 *buffer, int *max_len, const char *format_pattern)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const char *fmt;
    int index;
    int has_start_mark = 0;
    char newchar;
#ifdef JATAAYU_SUPPORT
    int maxlen = *max_len;

#else
    int maxlen = (*max_len < WIDGET_MAX_INPUT_LEN)?(*max_len):(WIDGET_MAX_INPUT_LEN);
    
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(buffer);

    if (!format_pattern || maxlen <= 0) /* With default value or input */
    {
        WAP_DBG_ASSERT(0);
        return -1;
    }

    fmt = format_pattern;
    index = 0;

    do
    {
        if (*fmt == '*')
        {
            has_start_mark = 1;
            if (*(fmt+2) == '\0' && *(fmt+3) != '\0')
            {
                return -1;
            }
            fmt += 4;

            break;  /* Finished */
        }
        else if (*fmt >= '0' && *fmt <= '9')
        {
            int cnt = *fmt - '0';
            int i;

            fmt+=2;
            while (*fmt >= '0' && *fmt <= '9')
            {
                cnt *= 10;
                cnt += (*fmt - '0');
                fmt+=2;
            }
            if (*(fmt) == '\0' && *(fmt+1) == '\0')
            {
                return -1;
            }
            if (index + cnt > maxlen)
            {
                return -1;
            }
            if ((newchar = widget_css_format_char_to_default_char(*fmt)) == 0)
            {
                return -1;
            }
            for (i = 0; i < cnt; i++)
            {
                SET_CHR_AT(buffer, (index + i), newchar);
            }
            fmt+=2;
            index += cnt;
        }
        else if (*fmt == '\\')
        {
            fmt+=2;
            if (*(fmt) == '\0' && *(fmt+1) != '\0')
            {
                return -1;
            }
            SET_CHR_AT(
                buffer,
                index,
                ((kal_uint16)*(fmt+1)) << 8 | ((kal_uint16)(*fmt) & 0x00ff));
            fmt+=2;
            index++;
        }
        else
        {
            if ((newchar = widget_css_format_char_to_default_char(*fmt)) == 0)
            {
                return -1;
            }

            SET_CHR_AT(buffer, index, newchar);
            fmt+=2;
            index++;
        }
    } while (*fmt && index < maxlen);

    if (*fmt && (*fmt != '*'))
    {
        return -1;  /* Buffer not large enough */
    }

    if (index > maxlen) /* At most 'maxlen' char (without L'\0') */
    {
        WAP_DBG_ASSERT(0);
        return -1;
    }

    SET_CHR_AT(buffer, index, 0);

    /* update the max_len if restrict the input length */
    if (!has_start_mark)
    {
        *max_len = index;
    }

    return 0;
}


#ifdef __MMI_WCSS_INPUT_FORMAT_SUPPORT__ 

/* the special pattern in format_pattern[] to represent the character WCSS format */
#define WIDGET_FORMAT_PATTERN (0xFF)

/* Global variables related to WCSS format  */
static kal_uint8 format_string[WIDGET_MAX_FORMAT_PATTERN_LEN];
static kal_uint8 format_pattern[WIDGET_MAX_FORMAT_PATTERN_LEN];
static kal_uint8 format_string_len = 0;
static kal_uint8 format_pattern_len = 0;
static kal_int16 format_end_repeat = 0;			/* keep the number of end symbol */
static kal_int16 format_end_repeat_cnt = 0;		/* keep the count of repeated related information in format_string */
static kal_uint8 format_end_symbol = 0;			/* keep the repeated symbol */


/* input method enum */
enum
{
    REPEAT_INFINITE = -1,
    REPEAT_NOT_USED = -2
};

/* The following check is not completely correct  */


/*****************************************************************************
 * FUNCTION
 *  widget_extract_format_characters
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pattern         [OUT]     
 *  string          [IN]     
 *  end_symbol      [OUT]     
 *  repeat          [OUT]     
 *  repeat_cnt      [OUT]     
 * RETURNS
 *  
 *****************************************************************************/
static int widget_extract_format_characters(
            kal_uint8 *pattern,
            kal_uint8 *string,
            kal_uint8 *end_symbol,
            kal_int16 *repeat)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *src;
    kal_uint8 dest;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    src = string;
    dest = 0;

    memset(pattern, WIDGET_FORMAT_PATTERN, WIDGET_MAX_FORMAT_PATTERN_LEN);

    while (*src)
    {

        switch (*src)
        {
            case '\\':
                src+=2;
                if (dest < WIDGET_MAX_FORMAT_PATTERN_LEN)
                {
                    pattern[dest] = *src;
                    pattern[dest+1] = *(src+1);
                }
                string[dest] = WIDGET_FORMAT_PATTERN;
                string[dest+1] = WIDGET_FORMAT_PATTERN;
                break;
            default:
                string[dest] = *src;
                string[dest+1] = *(src+1);
        }
        dest+=2;
        src+=2;
    }
    string[dest] = 0;
    string[dest+1] = 0;

    /* extract the repeat symbol */
	/* assume *f in WCSS format */
    format_end_repeat_cnt = 2;
    if (repeat && end_symbol)
    {
        if (string[dest - 4] == '*')
        {
            *repeat = REPEAT_INFINITE;
            *end_symbol = string[dest - 2];
        }
        else if ('0' <= string[dest - 4] && string[dest - 4] <= '9')
        {
            int i = 0, count = 0;
            kal_int16 num = 0;
            kal_int16 decimal[4] = {1, 10, 100, 1000};

            /* find the repeat number */
            i = dest - 4;
            while (i >= 0 && '0' <= string[i] && string[i] <= '9')
            {
                num = ((kal_uint8) string[i] - '0') * decimal[count] + num;
                count++;
                i-=2;
            }
            *repeat = num;
            format_end_repeat_cnt = count + 1;
            *end_symbol = string[dest - 2];
        }
        else
        {
            *repeat = REPEAT_NOT_USED;
        }
    }

    if (dest >= WIDGET_MAX_FORMAT_PATTERN_LEN)
    {
        dest = WIDGET_MAX_FORMAT_PATTERN_LEN - 2;
    }
    while (dest > 2 && 
           pattern[dest - 2] == WIDGET_FORMAT_PATTERN && 
           pattern[dest - 1] == WIDGET_FORMAT_PATTERN)
    {
        pattern[dest-2] = 0;
        pattern[dest-1] = 0;
        dest -= 2;
    }
    pattern[dest] = 0;
    pattern[dest+1] = 0;

    return dest;
}


/*****************************************************************************
 * FUNCTION
 *  widget_init_input_CSS_pattern
 * DESCRIPTION
 *  prepare some global structure to check CSS input pattern later
 * PARAMETERS
 *  input_pattern       [IN]        -  CSS format string
 * RETURNS
 *  void
 *****************************************************************************/
void widget_init_input_CSS_pattern(const char *input_pattern)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    format_string_len = 0;
    format_pattern_len = 0;
    format_end_repeat = 0;
    format_end_repeat_cnt = 0;
    format_end_symbol = 0;

    memcpy(format_string, input_pattern, WIDGET_MAX_FORMAT_PATTERN_LEN);
    widget_extract_format_characters(format_pattern, format_string, &format_end_symbol, &format_end_repeat);//, &format_end_repeat_cnt);
    format_pattern_len = (kal_uint8)app_ucs2_strlen((const kal_int8 *)format_pattern);
    format_string_len = (kal_uint8)app_ucs2_strlen((const kal_int8 *)format_string);
}


/*****************************************************************************
 * FUNCTION
 *  widget_is_the_same_kind_of_format
 * DESCRIPTION
 *  
 * PARAMETERS
 *  a           [IN]        
 *  format      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool widget_is_the_same_kind_of_format(UI_character_type a, kal_uint8 format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (format)
    {
        case 'A':
            return !((CHR('a') <= a && a <= CHR('z')) || (CHR('0') <= a && a <= CHR('9')));
        case 'a':
            return !((CHR('A') <= a && a <= CHR('Z')) || (CHR('0') <= a && a <= CHR('9')));
        case 'N':
            return CHR('0') <= a && a <= CHR('9');
        case 'n':
            return !((CHR('A') <= a && a <= CHR('Z')) || (CHR('a') <= a && a <= CHR('z')));
        case 'X':
            return !((CHR('a') <= a && a <= CHR('z')));
        case 'x':
            return !((CHR('A') <= a && a <= CHR('Z')));
        case 'M':
        case 'm':
            return KAL_TRUE;
        default:
            return KAL_FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  widget_get_input_CSS_format_pattern
 * DESCRIPTION
 *  return the input CSS format string pointer
 * PARAMETERS
 *  void
 * RETURNS
 *  the string 
 *****************************************************************************/
kal_uint8 * widget_get_input_CSS_format_pattern(void)
{
    return format_string;
}


/*****************************************************************************
 * FUNCTION
 *  widget_is_match_CSS_pattern
 * DESCRIPTION
 *  verify if the input buffer meets the CSS pattern
 *  (global variables format_* must be initialized first)
 * PARAMETERS
 *  input_buffer        [IN]     -  the text to be verified
 * RETURNS
 *  if matched
 *****************************************************************************/
kal_bool widget_is_match_CSS_pattern(void *input_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int pos;
    UI_character_type c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (pos = 0; (c = CHR_AT(input_buffer, pos)) != 0; pos++)
    {
        if (format_end_repeat != REPEAT_NOT_USED && pos >= format_string_len - format_end_repeat_cnt)
        {
            if (format_end_repeat == REPEAT_INFINITE)
            {
                if (!widget_is_the_same_kind_of_format(c, format_end_symbol))
                {
                    return KAL_FALSE;
                }
            }
            else
            {
                if (!widget_is_the_same_kind_of_format(c, format_end_symbol)
                    || pos >= format_string_len - format_end_repeat_cnt + format_end_repeat)
                {
                    return KAL_FALSE;
                }
            }
        }
        else
        {
            if (format_string[2*pos] != WIDGET_FORMAT_PATTERN && 
                format_string[2*pos+1] != WIDGET_FORMAT_PATTERN)
            {
                if (!widget_is_the_same_kind_of_format(c, format_string[2*pos]))
                {
                    return KAL_FALSE;
                }
            }
            else if (CHR_AT(format_pattern, pos) != c)
            {
                return KAL_FALSE;
            }
        }
    }

    if (format_end_repeat != REPEAT_NOT_USED)
    {
        if (format_end_repeat == REPEAT_INFINITE)
        {
            return (pos >= format_string_len - 2);
        }
        else
        {
            return (pos == format_string_len - format_end_repeat_cnt + format_end_repeat);
        }
    }
    if (format_end_repeat == REPEAT_NOT_USED && pos < format_string_len)
    {
        return KAL_FALSE;
    }

    return KAL_TRUE;
}
#endif /* __MMI_WCSS_INPUT_FORMAT_SUPPORT__ */ 

#if (defined(__MMI_MMS_2__) || defined(__MMI_MMS_BGSR_SUPPORT__))
/*****************************************************************************
 * FUNCTION
 *  wap_mms_send_msg
 * DESCRIPTION
 *  send message request
 * PARAMETERS
 *  msg_id        [IN]     -  the message id
 * RETURNS
 *  void
 *****************************************************************************/
void wap_mms_send_msg(kal_uint32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_MMS_2__
    mmi_umms_entry_send_msg(msg_id);
#else
    mmi_mms_bgsr_send_req(msg_id, 0, mma_conf_get_send_setting());
#endif    
}
#endif /*#if (defined(__MMI_MMS_2__) || defined(__MMI_MMS_BGSR_SUPPORT__))*/

#endif /* WAP_SUPPORT */ 
#endif /* WAPADP_C */ 

