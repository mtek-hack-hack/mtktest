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
 * bra_int.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for adapter functions of Browser Application of Mobile Suite
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *******************************************************************************/

#include "kal_release.h"        /* Basic data type */

#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */

#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "custom_config.h"

#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */

#include "event_shed.h" /* Event scheduler */

#include "stack_timer.h"        /* Stack timer */
#include "app_buff_alloc.h"

#ifdef __SAT__
#include "mcd_l4_common.h"
#include "sat_def.h"
#include "wap_ps_struct.h"
#endif /* __SAT__ */ 

#include "soc_api.h"
#include "app2soc_struct.h"
#include "msf_cfg.h"
#include "msf_def.h"
#include "msf_int.h"
#include "widget_extension.h"
#include "bra_cfg.h"
#include "bra_str.h"
#include "bra_sif.h"
#include "brs_if.h"
#include "bra_if.h"
#ifdef WAP_SEC_SUPPORT
#include "sec_if.h"
#endif 
#include "bra_int.h"
#include "bra_view.h"
#include "msf_chrs.h"
#include "msf_cmmn.h"

/* SMS includes */
#include "SMSApi.h"
#include "smsal_l4c_enum.h"

#include "app_datetime.h"
#include "wgui_datetime.h"

#include "DLAgentDef.h"

#define WAP_WAIT_BEARER_TIMEOUT (750)   /* ms */

extern void HDIa_socketDiscBearerById(MSF_INT32 networkAccountID);
extern void HDIa_socketTermBearer(void);
extern void wap_disc_bearer_by_id(MSF_INT32 networkAccountID);
extern eventid msf_start_timer(MSF_UINT32 timeInterval, kal_timer_func_ptr timer_hdlr, void *event_param);
extern void msf_stop_timer(eventid *event_id);
#ifdef __MMI_EMAIL__
extern void mmi_email_app_send_cont(const S8* cont);
#endif

static int bearer_state = SOC_DEACTIVATED;
static int bearer_type;
static int bearer_conn = 0;
static eventid bearer_timer_eventid;


/*****************************************************************************
 * FUNCTION
 *  BRAa_stopBearerTimer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void BRAa_stopBearerTimer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (bearer_timer_eventid != NULL)
    {
        msf_stop_timer(&bearer_timer_eventid);
        bearer_timer_eventid = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  BRAa_bearerInConn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
int BRAa_bearerInConn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (bearer_state == SOC_ACTIVATING || bearer_state == SOC_ACTIVATED);
}


/*****************************************************************************
 * FUNCTION
 *  BRAa_bearerCsdIsDisc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
int BRAa_bearerCsdIsDisc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (bearer_type == SOC_CSD && bearer_state == SOC_DEACTIVATING);
}


/*****************************************************************************
 * FUNCTION
 *  BRAa_bearerDiscCsd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void BRAa_bearerDiscCsd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (bearer_type == SOC_CSD)
    {
        wap_disc_bearer_by_id(BRAif_getNetAccId());
    }
}


/*****************************************************************************
 * FUNCTION
 *  BRAa_userCancel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void BRAa_userCancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (bearer_state == SOC_ACTIVATING)
    {
        HDIa_socketDiscBearerById(BRAif_getNetAccId());
    }
}


/*****************************************************************************
 * FUNCTION
 *  BRAa_loadingComplete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void BRAa_loadingComplete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bearer_state = (bearer_state == SOC_ACTIVATING) ? SOC_ACTIVATED : bearer_state;
}


/*****************************************************************************
 * FUNCTION
 *  BRAa_setStatusIcon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void BRAa_setStatusIcon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (bearer_state == SOC_ACTIVATING || bearer_state == SOC_ACTIVATED)
    {
        widget_disable_status_bar(WIDGET_STATUS_BAR_DISCONNECT);
        if (bearer_type == SOC_CSD)
        {
            widget_enable_status_bar(WIDGET_STATUS_BAR_CSD);
        }
        else if (bearer_type == SOC_GPRS)
        {
            widget_enable_status_bar(WIDGET_STATUS_BAR_GPRS);
        }
#ifdef __WIFI_SUPPORT__
        else if (bearer_type == SOC_WIFI)
        {
        	widget_enable_status_bar(WIDGET_STATUS_BAR_WIFI);
    	}
#endif
    }
    else if (bearer_state == SOC_DEACTIVATING || bearer_state == SOC_DEACTIVATED)
    {
        if (bearer_type == SOC_CSD)
        {
            widget_enable_status_bar(WIDGET_STATUS_BAR_CSD);    /* dirty patch, need discuss with widget */
            widget_disable_status_bar(WIDGET_STATUS_BAR_CSD);
        }
        else if (bearer_type == SOC_GPRS)
        {
            widget_enable_status_bar(WIDGET_STATUS_BAR_GPRS);   /* dirty patch, need discuss with widget */
            widget_disable_status_bar(WIDGET_STATUS_BAR_GPRS);
        }
#ifdef __WIFI_SUPPORT__
        else if (bearer_type == SOC_WIFI)
        {
            widget_enable_status_bar(WIDGET_STATUS_BAR_WIFI);   /* dirty patch, need discuss with widget */
            widget_disable_status_bar(WIDGET_STATUS_BAR_WIFI);
        }
#endif
        widget_enable_status_bar(WIDGET_STATUS_BAR_DISCONNECT);
    }
}


/*****************************************************************************
 * FUNCTION
 *  BRAa_setSecureIcon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sec_class       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void BRAa_setSecureIcon(int sec_class)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sec_class < 1)
    {
        widget_disable_status_bar(WIDGET_STATUS_BAR_SECURITY);
    }
    else
    {
        widget_enable_status_bar(WIDGET_STATUS_BAR_SECURITY);
    }
}


/*****************************************************************************
 * FUNCTION
 *  BRA_handleBearerTimeout
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event_param     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void BRA_handleBearerTimeout(void *event_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bearer_timer_eventid = NULL;

    if (bearer_state == SOC_ACTIVATING)
    {
        wap_disc_bearer_by_id(BRAif_getNetAccId());
    }
}


/*****************************************************************************
 * FUNCTION
 *  BRA_handleBearerInfo
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void BRA_handleBearerInfo(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    app_soc_bearer_info_ind_struct *soc_bearer_info = (app_soc_bearer_info_ind_struct*) p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(soc_bearer_info->account_id != BRAif_getNetAccId())
  	{
  	    return;
    }
    
    if (soc_bearer_info->state == SOC_ACTIVATING && bearer_timer_eventid == NULL)
    {
        bearer_timer_eventid = msf_start_timer(WAP_WAIT_BEARER_TIMEOUT, BRA_handleBearerTimeout, NULL);
    }
    else if (soc_bearer_info->state != SOC_ACTIVATING && bearer_timer_eventid != NULL)
    {
        msf_stop_timer(&bearer_timer_eventid);
        bearer_timer_eventid = NULL;
    }

    if (soc_bearer_info->state == SOC_ACTIVATING
        || soc_bearer_info->state == SOC_DEACTIVATING || soc_bearer_info->state == SOC_DEACTIVATED)
    {
        if (soc_bearer_info->state == SOC_DEACTIVATING || soc_bearer_info->state == SOC_DEACTIVATED)
        {
            HDIa_socketTermBearer();
            if (bearer_conn == 1)
            {
                BRSif_stop(MSF_MODID_BRA, bra_sif_get_brs_id());
            }
            if (soc_bearer_info->bearer==SOC_CSD && soc_bearer_info->state==SOC_DEACTIVATED)
                BRAif_notifyBearerInfo(HDI_SOCKET_BEARER_GSM_CSD, BRA_BRINFO_CSD_DISC);
        #if 0 /* #ifdef __J2ME__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* __J2ME__ */ 
        #ifdef WAP_SEC_SUPPORT
            if (soc_bearer_info->state == SOC_DEACTIVATED)
            {
                SECif_sessionClear(MSF_MODID_BRA, 0);
            }
        #endif /* WAP_SEC_SUPPORT */ 
        }
        bearer_state = soc_bearer_info->state;
        bearer_type = soc_bearer_info->bearer;
        BRAa_setStatusIcon();
    }
    else if (soc_bearer_info->state == SOC_AUTO_DISC_TIMEOUT)
    {
        if (bearer_state == SOC_ACTIVATING || bearer_state == SOC_ACTIVATED)
        {
            if (soc_bearer_info->bearer == SOC_CSD)
            {
                bearer_state = SOC_DEACTIVATING;
                wap_disc_bearer_by_id(BRAif_getNetAccId());

                BRAif_showDialog(MsfInfo, BRA_STR_LONG_IDLE_DISCONNECT);
                //BRAif_notifyBearerInfo(HDI_SOCKET_BEARER_GSM_CSD, BRA_BRINFO_CSD_TIMEOUT);
            }
        }
    }

    if (soc_bearer_info->state == SOC_ACTIVATED)
    {
        bearer_conn = 1;
        bearer_state = SOC_ACTIVATED;
        BRAa_setStatusIcon();
    }
    else if (soc_bearer_info->state == SOC_AUTO_DISC_TIMEOUT)
    {
        bearer_conn = 2;
    }
    else
    {
        bearer_conn = 0;
    }

}

/*****************************************************************************
 * FUNCTION
 *  BRA_handleDAinfo
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void BRA_handleDAinfo(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_download_info_ind_struct *da_download_info = (mmi_da_download_info_ind_struct*) p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    BRAif_DADownloadInfo(da_download_info->job_count, da_download_info->active_job_count);
}


/*****************************************************************************
 * FUNCTION
 *  BRAa_setBearerType
 * DESCRIPTION
 *  
 * PARAMETERS
 *  net_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void BRAa_setBearerType(int net_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int curBearerType;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    curBearerType = HDIa_networkAccountGetBearer(net_id);
    //bearer_type = (curBearerType == HDI_SOCKET_BEARER_GSM_CSD) ? SOC_CSD : SOC_GPRS;
    if (curBearerType == HDI_SOCKET_BEARER_GSM_CSD)
    	bearer_type = SOC_CSD;
    	
    else if (curBearerType == HDI_SOCKET_BEARER_GSM_GPRS)
    	bearer_type = SOC_GPRS;
    	
#ifdef __WIFI_SUPPORT__
    else if (curBearerType == HDI_SOCKET_BEARER_WIFI)
    	bearer_type = SOC_WIFI;
#endif

    else if (curBearerType == HDI_SOCKET_BEARER_ANY)
    	bearer_type = SOC_BEARER_ANY;
    	
    else
    	bearer_type = SOC_GPRS;
    	
    BRAa_setStatusIcon();
}


/*****************************************************************************
 * FUNCTION
 *  BRAa_getBearerType
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
int BRAa_getBearerType(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return bearer_type;
}


/*****************************************************************************
 * FUNCTION
 *  BRAa_setBearerState
 * DESCRIPTION
 *  
 * PARAMETERS
 *  state       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void BRAa_setBearerState(int state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bearer_state = state;
    if (state == SOC_ACTIVATED)
    {
        bearer_conn = 1;
    }
    else if (state == SOC_AUTO_DISC_TIMEOUT)
    {
        bearer_conn = 2;
    }
    else
    {
        bearer_conn = 0;
    }
}

#ifdef __SAT__


/*****************************************************************************
 * FUNCTION
 *  bra_send_lauch_rsp_to_mmi
 * DESCRIPTION
 *  
 * PARAMETERS
 *  res     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void bra_send_lauch_rsp_to_mmi(MSF_UINT8 res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    wap_mmi_lauch_browser_rsp_struct *lauch_rsp_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    lauch_rsp_ptr = (wap_mmi_lauch_browser_rsp_struct*) construct_local_para
        ((kal_uint16) sizeof(wap_mmi_lauch_browser_rsp_struct), TD_CTRL);

    switch (res)
    {
        case BRA_SAT_LAUCH_SUCC:
            /* TERMINAL RESPONSE successfully */
            lauch_rsp_ptr->res = SAT_CMD_PERFORMED_SUCCESSFULLY;
            lauch_rsp_ptr->additionalInfo = SAT_LAUNCH_BROWSER_NO_SPECIFIC_CAUSE;
            break;
        case BRA_SAT_BRWOSER_BUSY:
            /* TERMINAL RESPONSE (ME unable to process command ¡V browser unavailable) */
            lauch_rsp_ptr->res = SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD;
            lauch_rsp_ptr->additionalInfo = SAT_LAUNCH_BROWSER_BROWSER_UNAVALIABLE;
            break;
        case BRA_SAT_BEARER_UNAVAILABLE:
            /* TERMINAL RESPONSE (ME unable to process command ¡V bearer unavailable) */
            lauch_rsp_ptr->res = SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD;
            lauch_rsp_ptr->additionalInfo = SAT_LAUNCH_BROWSER_BEARER_UNAVALIABLE;
            break;
        case BRA_SAT_PARAM_GATEWAY_ERROR:
        case BRA_SAT_PARAM_URL_ERROR:
            lauch_rsp_ptr->res = SAT_LAUNCH_BROWER_GENERIC_ERROR_CODE;
            lauch_rsp_ptr->additionalInfo = SAT_LAUNCH_BROWSER_NO_SPECIFIC_CAUSE;
            break;
        case BRA_SAT_PROV_DATA_ERROR:
            lauch_rsp_ptr->res = SAT_LAUNCH_BROWER_GENERIC_ERROR_CODE;
            lauch_rsp_ptr->additionalInfo = SAT_LAUNCH_BROWSER_ME_UNABLE_TO_READ_PROVISION_DATA;
            break;
        default:
            lauch_rsp_ptr->res = SAT_LAUNCH_BROWER_GENERIC_ERROR_CODE;
            lauch_rsp_ptr->additionalInfo = SAT_LAUNCH_BROWSER_NO_SPECIFIC_CAUSE;
            break;
    }

    ilm_ptr = allocate_ilm(MOD_WAP);
    ilm_ptr->msg_id = (kal_uint16) MSG_ID_WAP_MMI_LAUNCH_BROWSER_RSP;
    ilm_ptr->peer_buff_ptr = NULL;
    ilm_ptr->local_para_ptr = (local_para_struct*) lauch_rsp_ptr;

    SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  bra_send_termination_to_mmi
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cause       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void bra_send_termination_to_mmi(MSF_UINT8 cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    wap_mmi_browser_termination_ind_struct *browser_term_ind_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    browser_term_ind_ptr = (wap_mmi_browser_termination_ind_struct*) construct_local_para
        ((kal_uint16) sizeof(wap_mmi_browser_termination_ind_struct), TD_CTRL);

    if (cause == BRA_SAT_USER_TERMINATION)
    {
        browser_term_ind_ptr->cause = SAT_BROWSER_USER_TERMINATION;
    }
    else
    {
        browser_term_ind_ptr->cause = SAT_BROWSER_ERROR_TERMINATION;
    }

    ilm_ptr = allocate_ilm(MOD_WAP);
    ilm_ptr->msg_id = (kal_uint16) MSG_ID_WAP_MMI_BROWSER_TERMINATION_IND;
    ilm_ptr->peer_buff_ptr = NULL;
    ilm_ptr->local_para_ptr = (local_para_struct*) browser_term_ind_ptr;

    SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);
}
#endif /* __SAT__ */ 



void bra_send_select_bookmark_rsp_to_mmi(MSF_UINT8 result, MSF_UINT8 *title, MSF_UINT8 *url)
{
    kal_int32 destLen;
    kal_int32 srcLen;

    ilm_struct *ilm_ptr = NULL;
    wap_select_bookmark_rsp_struct *bookmark_info;

    bookmark_info = (wap_select_bookmark_rsp_struct*)construct_local_para((kal_uint16)sizeof(wap_select_bookmark_rsp_struct), 0);
    memset(bookmark_info->title, 0, sizeof(bookmark_info->title));
    memset(bookmark_info->url, 0, sizeof(bookmark_info->url));
    bookmark_info->result = 0;
    bookmark_info->dcs = 0;

    /* fill result */
    bookmark_info->result = (kal_uint8)result;

    /* fill url */
    if (url)
        strncpy((char*)bookmark_info->url, (const char*)url, BRA_CFG_MAX_NBR_CHARS_URL);

    /* fill dcs + title */
    if (title)
    {
        /* if title not UTF8 string */
        if (!(widget_utf8_length((const kal_uint8 *)title)!=strlen((char*)title)))
        {
            bookmark_info->dcs = 0; /* ASCII */
            strncpy((char*)bookmark_info->title, (const char*)title, BRA_CFG_MAX_NBR_CHARS_TITLE);
        }
        else
        {
            bookmark_info->dcs = 1; /* UCS2 */

            srcLen = strlen((char*)title);
            destLen = BRA_CFG_MAX_NBR_CHARS_TITLE*2;
            msf_charset_utf8_to_ucs2be((const char*)title, (long*)&srcLen, (char*)bookmark_info->title, (long*)&destLen);
        }
    }

    ilm_ptr = allocate_ilm(MOD_WAP);
    ilm_ptr->msg_id = (kal_uint16) MSG_ID_WAP_SELECT_BOOKMARK_RSP;
    ilm_ptr->peer_buff_ptr = NULL;
    ilm_ptr->local_para_ptr = (local_para_struct*)bookmark_info;

    SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);
}



/*****************************************************************************
 * FUNCTION
 *  wap_enter_sms_editor_handler
 * DESCRIPTION
 *  This function is invoked by WAP RPC and runs as MMI task. It enters sms editor with specified information.
 * PARAMETERS
 *  p
 * RETURNS
 *  void
 *****************************************************************************/
void wap_enter_sms_editor_handler(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    extern int msf_charset_utf8_to_ucs2le (const char *src, long *srcLen, char *dst, long *dstLen);
    mmi_frm_sms_api_entry_write_struct sendData;
    wap_message_editor_t *params;
    kal_int32 destBufferLen;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&sendData, 0, sizeof(mmi_frm_sms_api_entry_write_struct));
    params = (wap_message_editor_t*)p;
    sendData.stringlength = msf_cmmn_utf8_strlen(params->content);
    
    //if (strlen(params->content) == sendData.stringlength)
    //{
        //sendData.string = params->content;
        //sendData.dcs = SMSAL_DEFAULT_DCS;
    //}
    //else

        sendData.dcs = SMSAL_UCS2_DCS;

        destBufferLen = sendData.stringlength * 2;
        sendData.string = (char*)MSF_MEM_ALLOC(MSF_MODID_WIDGET, destBufferLen+2);
        memset(sendData.string, 0, destBufferLen+2);

        //msf_charset_utf8_to_ucs2be(
        msf_charset_utf8_to_ucs2le(
                        (const char*)params->content,
                        (long*)&(sendData.stringlength),
                        (char*)sendData.string,
                        (long*)&destBufferLen);

        sendData.stringlength = widget_ucs2_length((const kal_uint8*)(sendData.string));

        MSF_MEM_FREE(MSF_MODID_WIDGET, params->content);
        params->content = sendData.string;
    

    sendData.flag = MMI_FRM_SMS_ENTRY_WRITE_REPLY;
    sendData.ascii_addr = (U8*)(params->addr);

    mmi_frm_sms_api_entry_write_msg(&sendData);

    if (params->content)
        MSF_MEM_FREE(MSF_MODID_WIDGET, params->content);
    if (params->addr)
        MSF_MEM_FREE(MSF_MODID_WIDGET, params->addr);
    MSF_MEM_FREE(MSF_MODID_WIDGET, params);
}

/*****************************************************************************
 * FUNCTION
 *  wap_enter_mms_editor_handler
 * DESCRIPTION
 *  This function is invoked by WAP RPC and runs as MMI task. It enters sms editor with specified information.
 * PARAMETERS
 *  p
 * RETURNS
 *  void
 *****************************************************************************/
void wap_enter_mms_editor_handler(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    extern int msf_charset_utf8_to_ucs2le (const char *src, long *srcLen, char *dst, long *dstLen);
#ifdef MMS_SUPPORT
    extern void mms_address_insert_hdlr(char *address);
    extern void mms_text_insert_hdlr(char *subject, unsigned int subject_len, char *text, unsigned int text_len);
#endif
    
    MSF_INT32 destLen;
    MSF_INT32 srcLen;
    char *ucs2number = 0;
    char *ucs2text = 0;
    wap_message_editor_t *params;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    params = (wap_message_editor_t*)p;
    
    if (params->addr)
    {
        srcLen = strlen((char*)params->addr);
        destLen = srcLen*2;
        ucs2number = (char*)MSF_MEM_ALLOC(MSF_MODID_WIDGET, destLen+2);
        memset(ucs2number, 0, destLen+2);
        msf_charset_utf8_to_ucs2le((const char*)params->addr, (long*)&srcLen, ucs2number, (long*)&destLen);
        
#ifdef MMS_SUPPORT
        mms_address_insert_hdlr(ucs2number);
#endif
    }
    else if (params->content)
    {
        srcLen = strlen((char*)params->content);
        destLen = srcLen*2;
        ucs2text = (char*)MSF_MEM_ALLOC(MSF_MODID_WIDGET, destLen+2);
        memset(ucs2text, 0, destLen+2);
        msf_charset_utf8_to_ucs2le((const char*)params->content, (long*)&srcLen, ucs2text, (long*)&destLen);
        
#ifdef MMS_SUPPORT
        mms_text_insert_hdlr(0, 0, ucs2text, (unsigned int)srcLen);
#endif
    }
    
    if (params->content)
        MSF_MEM_FREE(MSF_MODID_WIDGET, params->content);
    if (params->addr)
        MSF_MEM_FREE(MSF_MODID_WIDGET, params->addr);
    MSF_MEM_FREE(MSF_MODID_WIDGET, params);
    if (ucs2number)
        MSF_MEM_FREE(MSF_MODID_WIDGET, ucs2number);
    if (ucs2text)
        MSF_MEM_FREE(MSF_MODID_WIDGET, ucs2text);
}

#ifdef __MMI_EMAIL__
/*****************************************************************************
 * FUNCTION
 *  wap_enter_sms_editor_handler
 * DESCRIPTION
 *  This function is invoked by WAP RPC and runs as MMI task. It enters sms editor with specified information.
 * PARAMETERS
 *  p
 * RETURNS
 *  void
 *****************************************************************************/
void wap_enter_email_editor_handler(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    extern int msf_charset_utf8_to_ucs2le (const char *src, long *srcLen, char *dst, long *dstLen);
    char*                   sendData;
    wap_message_editor_t    *params;
	long                    len;
    long                    destLen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    params = (wap_message_editor_t*)p;
    len = strlen(params->content) + 1;
    destLen = len * 2;
    sendData = MSF_MEM_ALLOC(MSF_MODID_WIDGET, destLen);
    
    msf_charset_utf8_to_ucs2le(
        (const char*)params->content,
        (long*)&(len),
        (char*)sendData,
        (long*)&destLen);

    mmi_email_app_send_cont(sendData);

    MSF_MEM_FREE(MSF_MODID_WIDGET, sendData);

    if (params->content)
        MSF_MEM_FREE(MSF_MODID_WIDGET, params->content);
    if (params->addr)
        MSF_MEM_FREE(MSF_MODID_WIDGET, params->addr);
    MSF_MEM_FREE(MSF_MODID_WIDGET, params);
}
#endif

/*****************************************************************************
 * FUNCTION
 *  bra_format_datetime_string
 * DESCRIPTION
 *  takes in a UTC seconds (includes timezone) and obtain a string representation of this time
 *  based on the format set in device's Phone Setup setting
 *  caller must free the returned string with MSF_MEM_FREE(MSF_MODID_BRA, ...)
 * PARAMETERS
 *  dt_secs       [IN]        
 * RETURNS
 *  char*
 *****************************************************************************/
char* bra_format_datetime_string(MSF_UINT32 dt_secs)
{
    char ucs2str[100];
    char ascstr[100];
    MSF_INT32 len = 0;
    MYTIME datetime;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(ascstr, 0, 100*sizeof(char));

    mmi_dt_utc_sec_2_mytime((kal_int32)dt_secs, &datetime, KAL_TRUE);

    memset(ucs2str, 0, 100*sizeof(char));
    date_string(&datetime, (UI_string_type)ucs2str, DT_IDLE_SCREEN);
    widget_ucs2_to_utf8_string((kal_uint8*)ascstr, 100, (const kal_uint8*)ucs2str);

    memset(ucs2str, 0, 100*sizeof(char));
    time_string(&datetime, (UI_string_type)ucs2str, DT_IDLE_SCREEN);
    len = strlen(ascstr);
    ascstr[len] = ' ';
    len++;
    widget_ucs2_to_utf8_string((kal_uint8*)(ascstr+len), 100-len-1, (const kal_uint8*)ucs2str);

    return msf_cmmn_strdup(MSF_MODID_BRA, (const char*)ascstr);
}

/*****************************************************************************
 * FUNCTION
 *  bra_determine_push_addr
 * DESCRIPTION
 *  determine the correct address to transform given the push message's initiator-uri and sockaddr
 *  the selected address to use is based on a MSF compile option
 *  the buffer must be big enough to accomodate the output address string
 * PARAMETERS
 *  buffer          [IN]
 *  size            [IN]    size of buffer
 *  initiator_uri   [IN]
 *  sockaddr        [IN]
 * RETURNS
 *  address-type    0 = unsupported - no number
 *                  1 = sender addr - initiator-uri
 *                  2 = sender addr - IPv4
 *                  3 = sender addr - Phone Number
 *                  4 = sender addr - no number
 *                  5 = SMSC addr - Domain Name
 *                  6 = SMSC addr - IPv4
 *                  7 = SMSC addr - Phone Number
 *                  8 = SMSC addr - no number
 *****************************************************************************/
MSF_UINT8 bra_determine_push_addr(char *buffer, MSF_INT32 size, const char *initiator_uri, msf_sockaddr_t *sockaddr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(buffer, 0, size);

#ifndef MSF_CFG_PUSH_ADDRESS_OPTION
    /* Sender Addr and SMSC Addr Not Supported */
    return 0;
#endif
#if MSF_CFG_PUSH_ADDRESS_OPTION != 1 && MSF_CFG_PUSH_ADDRESS_OPTION != 2
    /* Sender Addr and SMSC Addr Not Supported */
    return 0;
#endif

#if MSF_CFG_PUSH_ADDRESS_OPTION == 1
    /* Originator address */
    if (initiator_uri) {
        MSF_INT32 maxLen;

        maxLen = strlen(initiator_uri);
        maxLen = (maxLen>(size-1)?(size-1):maxLen);
        strncpy(buffer, (char*)initiator_uri, maxLen);
        return 1;
    }
#endif

#ifndef __MTK_TARGET__
    /* on simulator, only IPv4 is allowed as push message comes in via UDP 2948 only */
    if (sockaddr->addrLen == 4) {
        /* IPv4 */
        ASSERT(size>=17);

#if MSF_CFG_PUSH_ADDRESS_OPTION == 2
        /* add addr type to first byte of the SC address */
        buffer[0] = (char)BRA_ADDRTYPE_IPV4;
        buffer++;
#endif

        sprintf(buffer, "%d.%d.%d.%d", (MSF_UINT8)sockaddr->addr[0], (MSF_UINT8)sockaddr->addr[1], (MSF_UINT8)sockaddr->addr[2], (MSF_UINT8)sockaddr->addr[3]);
#if MSF_CFG_PUSH_ADDRESS_OPTION == 1
        return 2;   /* Originator address */
#elif MSF_CFG_PUSH_ADDRESS_OPTION == 2
        return 6;   /* SC address */
#endif
    }
#else
    /* on target, only Phone Number is allowed as push message mostly comes in via SMS 2948
     * although UDP 2948 can be bound on target also, but chances of any message comes in via this port is extremely low
     * as for connection-oriented push, a way to determine socket type will be investigated when time comes.
     */
    if (sockaddr->addrLen != 0) {
        /* Phone Number */
        unsigned char *addrStart;
        MSF_INT16 addrLen;
        MSF_INT16 i;

        ASSERT(size>=24);

#if MSF_CFG_PUSH_ADDRESS_OPTION == 1
        /* Originator address */
        addrStart = sockaddr->addr + 1; /* first byte = numbering plan */
        addrLen = sockaddr->addrLen - 1;

        /* workout whether a '0' or a '+' should be added */
        if ((sockaddr->addr[0] & 0xF0) == 0x80 || (sockaddr->addr[0] & 0xF0) == 0xA0) {
            buffer[0] = '0';
            buffer++;
        } else if ((sockaddr->addr[0] & 0xF0) == 0x90) {
            buffer[0] = '+';
            buffer++;
        }

        /* first byte = first address byte */
        for (i=0; i<addrLen; i++) {
            buffer[i*2] = (char)((addrStart[i] & 0x0F) + '0');
            if ((addrStart[i] & 0xF0) != 0xF0)
                buffer[i*2+1] = (char)(((addrStart[i] & 0xF0)>>4) + '0');
        }

        return 3;
#elif MSF_CFG_PUSH_ADDRESS_OPTION == 2
        /* SC address */
        addrStart = sockaddr->addr; /* addr start on first byte */
        addrLen = sockaddr->addrLen;

        /* add addr type to first byte of the SC address */
        buffer[0] = (char)BRA_ADDRTYPE_PHONENO;
        buffer++;

        /* first byte = first address byte (numbering plan not included in sockaddr) */
        for (i=0; i<addrLen; i++) {
            buffer[i*2] = (char)((addrStart[i] & 0x0F) + '0');
            if ((addrStart[i] & 0xF0) != 0xF0)
                buffer[i*2+1] = (char)(((addrStart[i] & 0xF0)>>4) + '0');
        }

        return 7;
#endif
    }
#endif  /* __MTK_TARGET__ */

#if MSF_CFG_PUSH_ADDRESS_OPTION == 1
    return 4;   /* Originator address */
#elif MSF_CFG_PUSH_ADDRESS_OPTION == 2
    return 8;   /* SC address */
#endif
}
