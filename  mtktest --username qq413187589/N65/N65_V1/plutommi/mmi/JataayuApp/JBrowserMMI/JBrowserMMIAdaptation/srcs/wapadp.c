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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "MMI_include.h"
#ifndef WAPADP_C
#define WAPADP_C

#if defined(JATAAYU_SUPPORT)

/* Timer Management  */
#include "app_str.h"


#include "wap_ps_struct.h"

/* Included by Sandeep */
#include "custom_wap_config.h"

/* plutommi includes */
#include "CommonScreens.h"
#include "MessagesMiscell.h"
#include "SettingProfile.h"
#include "gui_data_types.h"

#ifdef __WIFI_SUPPORT__
/* WLAN includes */
#include "NetworkSetupDefs.h"
#endif /* __WIFI_SUPPORT__ */ 

/* SMS includes */
#include "SMSApi.h"
#include "smsal_l4c_enum.h"

#include "gui_data_types.h"
#include "ProfileGprots.h"
#include "gpioInc.h"
#include "AlarmFrameworkProt.h"
/* JDD */
#include "jdd_config.h"
#include "ddl.h"
#include "jcal.h"
/* Common Utility */
#include "jdi_urivalidation.h"

#ifdef __UNIFIED_COMPOSER_SUPPORT__
#include "UnifiedMessageGProt.h"
#include "UnifiedComposerGProt.h"
#endif /* __UNIFIED_COMPOSER_SUPPORT__ */ 

#include "wapadp.h"
#include "jta_export.h"

#include "JMMSGprot.h"
#include "JBrowserMMIGprots.h"
#ifdef __USB_IN_NORMAL_MODE__
#include "USBDeviceGprot.h"
#endif
#ifdef __MMI_UNIFIED_MESSAGE__
#include "JPushInboxUM.h"
#include "JMMSUMHandling.h"
#endif /* __MMI_UNIFIED_MESSAGE__ */
#ifdef MMS_SUPPORT
#include "JMMSMessageSettings.h"
#include "JMMSMainMMS.h"
#include "JMMSWriteMMS.h"
#include "JMMSCompose.h"
#include "mmsadp.h"
#endif /* MMS_SUPPORT */
#include "Conversions.h"

extern int mmi_charset_ucs2_to_utf8_length_in_bytes(const kal_uint8 *raw);
extern void mmi_brw_wap_entry_busy_progressing_screen_in_idle(void);

/* Handle WPS primitives */
extern void wps_jta_fsm(ilm_struct *ilm_ptr);
extern void jdd_init(void);
extern JC_BOOLEAN jdd_FSIsMMSStorageExported(void);
int jas_content_routing_serial; /* To recover Java issue for now */

extern kal_mutexid wap_status_mutex;

/* EnginerMode Variables */

kal_bool wap_enable_debug_assert = KAL_FALSE;

kal_uint8 global_wap_user_agent = EM_WAP_USERAGENT_MAUI_E800;

#ifdef WAP2
kal_uint8 global_wap_accept_header = EM_WAP_ACCEPTHEADER_WAP20;
#else 
kal_uint8 global_wap_accept_header = EM_WAP_ACCEPTHEADER_WAP121;
#endif 
/* kal_uint8 global_mms_version = EM_MMS_VERSION_10; */
kal_uint8 global_mms_version = 0;
kal_bool global_offline_page = 0;
kal_bool wap_suppress_popup_flag = KAL_FALSE;

stack_timer_struct wps_base_timer;
event_scheduler *wps_event_scheduler;


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
    /* To-Do: PMT needs to implement this function */
    kal_bool result = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_take_mutex(wap_status_mutex);

    if (jta_is_ready() == KAL_FALSE ||
#ifdef MMS_SUPPORT
        jmms_is_ready() == KAL_FALSE ||
#endif 
        mmi_brw_jbrowser_is_ready() == KAL_FALSE)
    {
        result = KAL_FALSE;
    }
    else
    {
        result = KAL_TRUE;
    }

    kal_give_mutex(wap_status_mutex);
    return result;
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

    kal_bool result = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_take_mutex(wap_status_mutex);

    if (jta_is_init() == KAL_FALSE ||
#ifdef MMS_SUPPORT
        jmms_is_init() == KAL_FALSE ||
#endif 
        mmi_brw_jbrowser_is_init() == KAL_FALSE)
    {
        result = KAL_FALSE;
    }
    else
    {
        result = KAL_TRUE;
    }

    kal_give_mutex(wap_status_mutex);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  wap_get_service_module
 * DESCRIPTION
 *  This function is to implement viewing a specific push message by index
 * CALLS
 *  
 * PARAMETERS
 *  msg_id      [IN]        Primitve id
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
    return mmi_brw_jbrowser_is_open();
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
    /* To-Do: PMT needs to implement this function */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    extern int mmi_bootup_get_active_flight_mode(void);
    extern int mmi_bootup_is_sim_valid(void);

#ifdef __WIFI_SUPPORT__
    extern U8 mmi_netset_get_active_preferred_mode(void);
#endif 

    return (wap_is_ready() && mmi_bootup_get_active_flight_mode() == 0 && mmi_bootup_is_sim_valid()
#ifdef __WIFI_SUPPORT__
            && mmi_netset_get_active_preferred_mode() != P_WLAN_ONLY
#endif 
#ifdef __MMI_UNIFIED_COMPOSER__
            && mmi_um_check_ready()
#endif 
        );
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
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mma_is_ready_for_usb
 * DESCRIPTION
 *  This function returns MMS ststus
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 mma_is_ready_for_usb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return wap_is_ready();  
}

#endif /* MMS_SUPPORT */ 


/*****************************************************************************
 * FUNCTION
 *  wap_entry_no_ready_screen
 * DESCRIPTION
 *  The function is used to show "Please Wait" screen when WAP/MMS is not ready
 * PARAMETERS
 *  service_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wap_entry_no_ready_screen(wap_service_enum service_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (service_id == WAP_SERVICE_BROWSER)
    {
        mmi_brw_entry_wap_not_ready();
    }
#if defined(MMS_SUPPORT)
    else if (service_id == WAP_SERVICE_MMS)
    {
        mmi_jmms_entry_wap_not_ready();
    }
#endif /* defined(MMS_SUPPORT) */ 
}


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
    return mmi_brw_jbrowser_wap_screen_id();
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
    extern int jdd_DataConnCsdIsDisc(void);

    return jdd_DataConnCsdIsDisc();
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
    return (int)jdi_isValidUrl((JC_UINT8*) url);
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

    MYQUEUE Message;
    wap_browser_startup_req_struct *para =
        (wap_browser_startup_req_struct*) OslConstructDataPtr(sizeof(wap_browser_startup_req_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* added by tk */
    if (!wap_is_ready())
    {
        mmi_brw_entry_wap_not_ready();
        return;
    }
    /* tk end */
    mmi_brw_wap_entry_busy_progressing_screen_in_idle();

    para->type = 1;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_WAP;
    Message.oslMsgId = MSG_ID_WAP_BROWSER_STARTUP_REQ;
    Message.oslDataPtr = (oslParaType*) para;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
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
    extern void jdd_CFGEmChangeWAPSetting(kal_uint8 opt, kal_uint8 val);

    jdd_CFGEmChangeWAPSetting(opt, val);
}


/*****************************************************************************
 * FUNCTION
 *  wap_get_user_agent_brand
 * DESCRIPTION
 *  This function is used to get the brand of current user-agent.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
em_wap_user_agent_brand_enum wap_get_user_agent_brand(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    extern em_wap_user_agent_enum jdd_CFGEmGetUserAgentBrand(void);

    return jdd_CFGEmGetUserAgentBrand();
}


/*****************************************************************************
 * FUNCTION
 *  wap_get_user_agent
 * DESCRIPTION
 *  This function is used to get the current Browser user-agent.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
char *wap_get_user_agent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    extern char *jdd_CFGEmGetUserAgent(void);

    return jdd_CFGEmGetUserAgent();
}


/*****************************************************************************
 * FUNCTION
 *  goto_mobile_suite_screen
 * DESCRIPTION
 *  WAP entry point from MMI menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void goto_mobile_suite_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wap_is_ready())
    {
        mmi_brw_pre_entry_internet_services();
    }
    else
    {
        mmi_brw_entry_wap_not_ready();
    }
}


/*****************************************************************************
 * FUNCTION
 *  wap_start_browser
 * DESCRIPTION
 *  
 * PARAMETERS
 *  option      [IN]        
 *  url         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
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
    if (option != WAP_BROWSER_GOTO_URL_BACKGROUND)
    {
        /* Disable key to prevent sending duplicated requests */
        ClearAllKeyHandler();
        ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    }

    if (wap_browser_is_open())
    {
        if (option != WAP_BROWSER_GOTO_URL_BACKGROUND)
        {
            mmi_brw_jbrowser_shutdown();
        }
    }
#ifdef MMS_SUPPORT
    else if (wap_mms_is_open())
    {
        /* TODO: Need to handle this */ 
    }
#endif /* MMS_SUPPORT */ 

    p = (wap_browser_startup_req_struct*) construct_local_para(sizeof(wap_browser_startup_req_struct), TD_CTRL);

    p->type = option;

    memset(p->url, 0, sizeof(p->url));
    mmi_ucs2_n_to_asc((S8*) p->url, (S8*) url, sizeof(p->url));

    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->local_para_ptr = (local_para_struct*) p;
    ilm_ptr->msg_id = MSG_ID_WAP_BROWSER_STARTUP_REQ;
    ilm_ptr->peer_buff_ptr = NULL;

    ilm_ptr->src_mod_id = MOD_MMI;
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
 *  is_true     [IN]        
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
 *  wap_entry_select_bookmark
 * DESCRIPTION
 *  This function is used by MMI applications to make entry to bookmark selector screen
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
int wap_entry_select_bookmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!wap_is_ready())
    {
        wap_entry_no_ready_screen(WAP_SERVICE_BROWSER);
        return -1;
    }

    /* Disable key to prevent sending duplicated requests */
    ClearAllKeyHandler();
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_WAP;
    Message.oslMsgId = MSG_ID_WAP_SELECT_BOOKMARK_REQ;
    Message.oslDataPtr = NULL;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  wap_fix_push_time
 * DESCRIPTION
 *  This function is used by PUSH module in both Obigo & Jataayu to fix invalid push time
 *  datetime[0] = year
 *  datetime[1] = month (1-12)
 *  datetime[2] = day  (1-31)
 *  datetime[3] = hour (0-23)
 *  datetime[4] = min (0-59)
 *  datetime[5] = sec (0-59)
 * PARAMETERS
 *  datetime        [IN/OUT]        
 * RETURNS
 *  0       datetime remains unchanged
 *  1       datetime modified
 *****************************************************************************/
int wap_fix_push_time(kal_uint32 datetime[6])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 monthdays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int modified = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
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
    monthdays[1] += (!(datetime[0] % 400) || (datetime[0] % 100 && !(datetime[0] % 4)));
    if (datetime[2] > monthdays[datetime[1] - 1])
    {
        datetime[2] = monthdays[datetime[1] - 1];
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
#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode() && jdd_FSIsMMSStorageExported())      /* Check if MMS should be disabled */
    {
        mmi_usb_app_unavailable_popup(0);
        return;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    if (wap_is_ready())
    {
        mmi_jmms_entry_main_menu();
    }
    else
    {
        mmi_jmms_entry_wap_not_ready();
    }
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
#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode() && jdd_FSIsMMSStorageExported())      /* Check if MMS should be disabled */
    {
        mmi_usb_app_unavailable_popup(0);
        return;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    if (wap_is_ready())
    {
    #ifdef __MMI_BARCODEREADER__
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
    #else /* __UNIFIED_COMPOSER_SUPPORT__ */ 
        mmi_jmms_create_mms_for_barcode((JC_CHAR*)subject, subject_len, (JC_CHAR*)text, text_len);
    #endif /* __UNIFIED_COMPOSER_SUPPORT__ */ 
    #endif /* __MMI_BARCODEREADER__ */ 
    }
    else
    {
        mmi_jmms_entry_wap_not_ready();
    }

    return;
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
#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode() && jdd_FSIsMMSStorageExported())      /* Check if MMS should be disabled */
    {
        mmi_usb_app_unavailable_popup(0);
        return;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    if (wap_is_ready())
    {
    #ifdef __UNIFIED_COMPOSER_SUPPORT__
        {
            mmi_uc_entry_write_struct data;

            memset(&data, 0x00, sizeof(mmi_uc_entry_write_struct));
            data.file_path = (kal_uint8*) content_source;
            data.info_type = MMI_UC_INFO_TYPE_MMS;
            mmi_uc_entry_write_msg_with_content(MMI_UC_STATE_WRITE_NEW_MSG, &data);
            return;
        }
    #else /* __UNIFIED_COMPOSER_SUPPORT__ */ 
        mmi_jmms_create_mms_for_file((JC_CHAR*)content_source, NULL, NULL);
    #endif /* __UNIFIED_COMPOSER_SUPPORT__ */ 
    }
    else
    {
        mmi_jmms_entry_wap_not_ready();
    }
    return;
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
 *  entry_data      [IN]        
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
#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode() && jdd_FSIsMMSStorageExported())      /* Check if MMS should be disabled */
    {
        mmi_usb_app_unavailable_popup(0);
        if (entry_data && entry_data->callback)
        {
            entry_data->callback(entry_data->callback_param);
        }
        return;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    if (wap_is_ready())
    {
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
    #else /* __UNIFIED_COMPOSER_SUPPORT__ */ 
        mmi_jmms_create_mms_for_file((JC_CHAR*)entry_data->file_path, entry_data->callback, entry_data->callback_param);
    #endif /* __UNIFIED_COMPOSER_SUPPORT__ */ 
    }
    else
    {
        mmi_jmms_entry_wap_not_ready();
        if (entry_data && entry_data->callback)
        {
            entry_data->callback(entry_data->callback_param);
        }
    }
    return;
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
#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode() && jdd_FSIsMMSStorageExported())      /* Check if MMS should be disabled */
    {
        mmi_usb_app_unavailable_popup(0);
        return;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 
    if (wap_is_ready())
    {
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
    #else /* __UNIFIED_COMPOSER_SUPPORT__ */ 
        mmi_jmms_create_mms_to_address((JC_CHAR*)address);
    #endif /* __UNIFIED_COMPOSER_SUPPORT__ */ 
    }
    else
    {
        mmi_jmms_entry_wap_not_ready();
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mms_general_insert_hdlr
 * DESCRIPTION
 *  Start MMS in editor with a mms_content_entry_struct is filled
 * CALLS
 *  
 * PARAMETERS
 *  data        [IN]        The mms_content_entry_struct data
 * RETURNS
 *  void
 *****************************************************************************/
void mms_general_insert_hdlr(mms_content_entry_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* VIKAS START 12072007 */
#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode() && jdd_FSIsMMSStorageExported())      /* Check if MMS should be disabled */
    {
        mmi_usb_app_unavailable_popup(0);
        if (data && data->callback)
        {
            data->callback(data->callback_param);
        }
        return;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    if (wap_is_ready())
    {
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
            uc_data.text_num = mmi_charset_ucs2_to_utf8_length_in_bytes((kal_uint8*) data->text_buffer);
            uc_data.file_path = (kal_uint8*) data->file_path;
            if (data->addr != NULL)
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
    #else /* __UNIFIED_COMPOSER_SUPPORT__ */ 
        mmi_jmms_create_mms_for_general_insert(
            (JC_CHAR*)data->addr,
            (JC_CHAR*)data->subject,
            (JC_CHAR*)data->file_path,
            (JC_CHAR*)data->text_buffer,
            data->callback,
            data->callback_param);
    #endif /* __UNIFIED_COMPOSER_SUPPORT__ */ 
    }
    else
    {
        mmi_jmms_entry_wap_not_ready();
        if (data && data->callback)
        {
            data->callback(data->callback_param);
        }
    }
    return;
    /* VIKAS END 12072007 */
}


/*****************************************************************************
 * FUNCTION
 *  wap_content_is_mms_forward
 * DESCRIPTION
 *  The function is used to check if the media can be forwarded to MMS
 * PARAMETERS
 *  filename        [IN]        Encoded by UCS2
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

    return mmi_jmms_is_file_can_be_forwarded_to_mms(filename);
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

    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_WAP;
    Message.oslMsgId = MSG_ID_MMS_ENTER_USB_MODE_REQ;
    Message.oslDataPtr = NULL;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mms_on_enter_usb_mode");
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

    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_WAP;
    Message.oslMsgId = MSG_ID_MMS_EXIT_USB_MODE_REQ;
    Message.oslDataPtr = NULL;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mms_on_exit_usb_mode");
}
#endif /* __USB_IN_NORMAL_MODE__ */ 


/*****************************************************************************
 * FUNCTION
 *  mms_enter_sms_editor_handler
 * DESCRIPTION
 *  This function is invoked by WAP RPC and runs as MMI task. It enters sms editor with specified information.
 * PARAMETERS
 *  p       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mms_enter_sms_editor_handler(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* To-Do: PMT needs to implement this function */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
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
    /* To-Do: PMT needs to implement this function */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
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
 *  isRoaming       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wap_roaming_status_indication_callback(unsigned long isRoaming)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_jmms_update_roaming_status(isRoaming);
}


/*****************************************************************************
 * FUNCTION
 *  wap_get_mms_content_class
 * DESCRIPTION
 *  This function is used to get mms content class
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  wap_mms_content_class_enum
 *****************************************************************************/
wap_mms_content_class_enum wap_get_mms_content_class(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mms_content_class_enum result = WAP_MMS_CONTENT_CLASS_TEXT;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
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
 *  void
 * RETURNS
 *  Max size
 *****************************************************************************/
kal_uint32 wap_get_max_mms_size_in_restricted_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mms_content_class_enum mms_content_class = wap_get_mms_content_class();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mms_content_class == WAP_MMS_CONTENT_CLASS_VIDEO_RICH)
    {
        return 300 * 1024;
    }
    else if (mms_content_class == WAP_MMS_CONTENT_CLASS_VIDEO_BASIC ||
             mms_content_class == WAP_MMS_CONTENT_CLASS_IMAGE_RICH)
    {
        return 100 * 1024;
    }
    else
    {
        return 30 * 1024;
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
 *  buf     [IN/OUT]        
 *  p       [IN/OUT]        
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
 *  buf     [IN/OUT]        
 *  p       [IN/OUT]        
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
 *  p           [IN]        
 *  buf         [IN]        
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
    jdd_init();
    while (1)
    {
        receive_msg_ext_q(task_info_g[task_entry_ptr->task_indx].task_ext_qid, &current_ilm);

        stack_set_active_module_id(my_index, current_ilm.dest_mod_id);
        wps_jta_fsm(&current_ilm);  /* process external ILM */
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
    mmi_um_jataayu_entry_message_wap_push(msg_box_type, msg_index);
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

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode() && jdd_FSIsMMSStorageExported())
    {
        mmi_usb_app_unavailable_popup(0);
        return;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 
    mmi_jmms_entry_write_message();
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

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode() && jdd_FSIsMMSStorageExported())
    {
        mmi_usb_app_unavailable_popup(0);
        return;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 
    mmi_um_jataayu_entry_message_mms(msg_box_type, msg_index);
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

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode() && jdd_FSIsMMSStorageExported())
    {
        mmi_usb_app_unavailable_popup(0);
        return;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 
    mmi_jmms_entry_templates();
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

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode() && jdd_FSIsMMSStorageExported())
    {
        mmi_usb_app_unavailable_popup(0);
        return;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 
    mmi_jmms_entry_message_settings();
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
    if (mms_is_re_entrant() || !wap_is_ready() || IsScreenPresent(wap_get_screen_id()))
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
 *  max_len             [IN]        
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

    int maxlen = *max_len;

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
            if (*(fmt + 2) == '\0' && *(fmt + 3) != '\0')
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

            fmt += 2;
            while (*fmt >= '0' && *fmt <= '9')
            {
                cnt *= 10;
                cnt += (*fmt - '0');
                fmt += 2;
            }
            if (*(fmt) == '\0' && *(fmt + 1) == '\0')
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
            fmt += 2;
            index += cnt;
        }
        else if (*fmt == '\\')
        {
            fmt += 2;
            if (*(fmt) == '\0' && *(fmt + 1) != '\0')
            {
                return -1;
            }
            SET_CHR_AT(buffer, index, ((kal_uint16) * (fmt + 1)) << 8 | ((kal_uint16) (*fmt) & 0x00ff));
            fmt += 2;
            index++;
        }
        else
        {
            if ((newchar = widget_css_format_char_to_default_char(*fmt)) == 0)
            {
                return -1;
            }

            SET_CHR_AT(buffer, index, newchar);
            fmt += 2;
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
static kal_int16 format_end_repeat = 0;     /* keep the number of end symbol */
static kal_int16 format_end_repeat_cnt = 0; /* keep the count of repeated related information in format_string */
static kal_uint8 format_end_symbol = 0;     /* keep the repeated symbol */

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
                src += 2;
                if (dest < WIDGET_MAX_FORMAT_PATTERN_LEN)
                {
                    pattern[dest] = *src;
                    pattern[dest + 1] = *(src + 1);
                }
                string[dest] = WIDGET_FORMAT_PATTERN;
                string[dest + 1] = WIDGET_FORMAT_PATTERN;
                break;
            default:
                string[dest] = *src;
                string[dest + 1] = *(src + 1);
        }
        dest += 2;
        src += 2;
    }
    string[dest] = 0;
    string[dest + 1] = 0;

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
                i -= 2;
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
    while (dest > 2 && pattern[dest - 2] == WIDGET_FORMAT_PATTERN && pattern[dest - 1] == WIDGET_FORMAT_PATTERN)
    {
        pattern[dest - 2] = 0;
        pattern[dest - 1] = 0;
        dest -= 2;
    }
    pattern[dest] = 0;
    pattern[dest + 1] = 0;

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
    widget_extract_format_characters(format_pattern, format_string, &format_end_symbol, &format_end_repeat);    /* , &format_end_repeat_cnt); */
    format_pattern_len = (kal_uint8) app_ucs2_strlen((const kal_int8*)format_pattern);
    format_string_len = (kal_uint8) app_ucs2_strlen((const kal_int8*)format_string);
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
kal_uint8 *widget_get_input_CSS_format_pattern(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return format_string;
}


/*****************************************************************************
 * FUNCTION
 *  widget_is_match_CSS_pattern
 * DESCRIPTION
 *  verify if the input buffer meets the CSS pattern
 *  (global variables format_* must be initialized first)
 * PARAMETERS
 *  input_buffer        [IN]        -  the text to be verified
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
            if (format_string[2 * pos] != WIDGET_FORMAT_PATTERN && format_string[2 * pos + 1] != WIDGET_FORMAT_PATTERN)
            {
                if (!widget_is_the_same_kind_of_format(c, format_string[2 * pos]))
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
        MMI_ALERT_TYPE alert_type;

        /*
         * If the applications won't want to show the WAP/MMS notification popup, 
         * we may play SMS_IN_CALL_TONE and return directly.
         */    
        alert_type = GetMtCallAlertTypeEnum();
    
        /* We play SMS_IN_CALL_TONE in this situation */
        if (alert_type == MMI_VIBRATION_AND_RING || alert_type == MMI_VIBRATION_THEN_RING ||
			alert_type == MMI_RING)
        {
            playRequestedTone(SMS_IN_CALL_TONE);
        }

        if ((alert_type == MMI_VIBRATION_ONLY) || (alert_type == MMI_VIBRATION_AND_RING) ||
            (alert_type == MMI_VIBRATION_THEN_RING))
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
#endif /* defined(JATAAYU_SUPPORT) */ 
#endif /* WAPADP_C */ 

