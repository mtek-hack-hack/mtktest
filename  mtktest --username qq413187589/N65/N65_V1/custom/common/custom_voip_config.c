/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 *  custom_voip_config.c
 *
 * Project:
 * --------
 *   MAUI Project
 *
 * Description:
 * ------------
 *   This file is used to define the VoIP customization functions.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#include "kal_release.h"
#ifdef __VOIP__
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"    /* local/peer struct */
#include "nvram_common_defs.h"

#include "sip_msg_api.h"
#include "sip_ua_api.h"
#include "sdp_msg_api.h"
#include "med_struct.h"
#include "mmi2voip_enums.h"
#include "mmi2voip_struct.h"
#include "voip_struct.h"
#include "custom_voip_config.h"
#include "voip_custom_api.h"

/* Call List */
voip_call_struct     voip_custom_call_list[VOIP_MAX_NUM_CALL];     /* List of sip cb hdlr for calls */  
voip_call_sip_struct voip_custom_call_sip_list[VOIP_MAX_NUM_CALL]; /* List of sip cb hdlr for calls */  

/* Memory pool */
kal_uint8 voip_custom_mem_pool[VOIP_MEM_SIZE]; /* memory pool */

/* setting variables, do not change manually!!! */
kal_uint32 voip_custom_re_reg_timer = VOIP_REREGISTER_TIMER;
kal_int32 voip_custom_call_refersh_timer = VOIP_SESSION_EXPIRE;
kal_int32 voip_custom_refer_sub_timer = VOIP_REFER_SUBASCIPTION_EXPIRE;
kal_uint32 voip_custom_mwi_expire = VOIP_MWI_SUBS_RETRY_DURATION;
kal_uint32 voip_custom_mwi_retry = VOIP_SUBS_RETRY_TIMES;
kal_uint32 voip_custom_max_ringing_call = VOIP_MAX_RINGING_CALL;

kal_char voip_custom_sip_support[VOIP_CUST_STR_LEN];
kal_char voip_custom_sip_require[VOIP_CUST_STR_LEN];
kal_uint32 voip_custom_sip_uac_call_refresher = VOIP_SIP_UAC_CALL_REFRESH;
kal_uint32 voip_custom_sip_uas_call_refresher = VOIP_SIP_UAS_CALL_REFRESH;
kal_bool voip_custom_p2p_call = KAL_FALSE;
kal_bool voip_custom_rport = KAL_TRUE;
kal_bool voip_setting_done;

static void voip_custom_init(void)
{
    if(voip_setting_done == KAL_FALSE)
    {
        if(strlen(voip_custom_sip_support) == 0)
        {
            /* first time use */
            memset(voip_custom_sip_support, 0, VOIP_CUST_STR_LEN);
            if(strlen(VOIP_SIP_SUPPORTED) < VOIP_CUST_STR_LEN)
            {
                strcpy(voip_custom_sip_support, VOIP_SIP_SUPPORTED);
            }
        }

        
        if(strlen(voip_custom_sip_require) == 0)
        {
            /* first time use */
            memset(voip_custom_sip_require, 0, VOIP_CUST_STR_LEN);
            if(strlen(VOIP_SIP_REQUIRE) == 0)
            {
             /* do nothing */
            }
            else if(strlen(VOIP_SIP_REQUIRE) < VOIP_CUST_STR_LEN)
            {
                strcpy(voip_custom_sip_require, VOIP_SIP_REQUIRE);
            }
        }
        
        voip_setting_done = KAL_TRUE;
    }
}

/*****************************************************************************
* FUNCTION
*  voip_custom_get_local_port 
* DESCRIPTION
*   This function is used to get the local port
* PARAMETERS
*  none
* RETURNS
*  local port number
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_uint32 voip_custom_get_local_port(void)
{
   return VOIP_DEFAULT_LOCAL_PORT;
}


/*****************************************************************************
* FUNCTION
*  voip_custom_get_max_call_num 
* DESCRIPTION
*   This function is used to get the max number of VoIP calls.
* PARAMETERS
*  none
* RETURNS
*  maximum number of calls
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_uint32 voip_custom_get_max_call_num(void)
{
   return VOIP_MAX_NUM_CALL;
}


/*****************************************************************************
* FUNCTION
*  voip_custom_get_mem_size 
* DESCRIPTION
*   This function is used to get the size of memory pool.
* PARAMETERS
*  none
* RETURNS
*  size of memory pool.
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_uint32 voip_custom_get_mem_size(void)
{
   return VOIP_MEM_SIZE;
}


/*****************************************************************************
* FUNCTION
*  voip_custom_get_uac_string 
* DESCRIPTION
*   This function is used to get the UAC string
* PARAMETERS
*  none
* RETURNS
*  UAC string
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_char *voip_custom_get_uac_string(void)
{
    return VOIP_UAC_STRING;
}


/*****************************************************************************
* FUNCTION
*  voip_custom_get_sip_allow 
* DESCRIPTION
*   This function is used to get the ALLOW capablities
* PARAMETERS
*  none
* RETURNS
*  string of ALLOW
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_char *voip_custom_get_sip_allow(void)
{
    return VOIP_SIP_ALLOW;
}


/*****************************************************************************
* FUNCTION
*  voip_custom_get_sip_accept 
* DESCRIPTION
*   This function is used to get the ACCEPT capablities
* PARAMETERS
*  none
* RETURNS
*  string of ACCEPT
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_char *voip_custom_get_sip_accept(void)
{
    return VOIP_SIP_ACCEPT;
}


/*****************************************************************************
* FUNCTION
*  voip_custom_get_sip_allow_event 
* DESCRIPTION
*   This function is used to get the "ALLOW Event" capablities
* PARAMETERS
*  none
* RETURNS
*  string of ALLOW EVENT
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_char *voip_custom_get_sip_allow_event(void)
{
    return VOIP_SIP_ALLOW_EVENT;
}

kal_char *voip_custom_get_sip_accept_encoding(void)//[SIP CONF TEST]
{
    return VOIP_SIP_ACCEPT_ENCODING;
}

kal_char *voip_custom_get_sip_accept_language(void)//[SIP CONF TEST]
{
    return VOIP_SIP_ACCEPT_LANGUAGE;
}


/*****************************************************************************
* FUNCTION
*  voip_custom_get_uas_string 
* DESCRIPTION
*   This function is used to get the UAS string
* PARAMETERS
*  none
* RETURNS
*  UAS string
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_char *voip_custom_get_uas_string(void)
{
    return VOIP_UAS_STRING;
}


/*****************************************************************************
* FUNCTION
*  voip_custom_get_reregister_timer 
* DESCRIPTION
*   This function is used to get expiry time of registration
* PARAMETERS
*  none
* RETURNS
*  expiry timer of registration
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_uint32 voip_custom_get_reregister_timer(void)
{
    return voip_custom_re_reg_timer;
}


/*****************************************************************************
* FUNCTION
*  voip_custom_set_reregister_timer 
* DESCRIPTION
*   This function is used to set expiry time of registration
* PARAMETERS
*  expire   IN      expire time of registration
* RETURNS
*  none
* GLOBALS AFFECTED
*   None
*****************************************************************************/
void voip_custom_set_reregister_timer(kal_uint32 expire)
{
    if(expire > 0)
    {
        voip_custom_re_reg_timer = expire;
    }
    else
    {
        voip_custom_re_reg_timer = VOIP_REREGISTER_TIMER;
    }
}


/*****************************************************************************
* FUNCTION
*  voip_custom_get_call_refresh_timer 
* DESCRIPTION
*   This function is used to get refresh time of INVITE session
* PARAMETERS
*  none
* RETURNS
*  expiry timer of registration
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_int32 voip_custom_get_call_refresh_timer(void)
{
    return voip_custom_call_refersh_timer;
}


 /*****************************************************************************
 * FUNCTION
 *  voip_custom_set_call_refresh_timer 
 * DESCRIPTION
 *   This function is used to set refresh time of INVITE session
 * PARAMETERS
 *  expire  IN  expire time of call refresh
 * RETURNS
 *  none
 * GLOBALS AFFECTED
 *   None
 *****************************************************************************/
void voip_custom_set_call_refresh_timer(kal_int32 expire)
{
    if(expire >= 90)
    {
        voip_custom_call_refersh_timer = expire;
    }
    else
    {
        voip_custom_call_refersh_timer = VOIP_SESSION_EXPIRE;
    }
}


/*****************************************************************************
* FUNCTION
*  voip_custom_get_refer_sub_timer 
* DESCRIPTION
*   This function is used to get subscription expire time of REFER
* PARAMETERS
*  none
* RETURNS
*  expiry timer of registration
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_int32 voip_custom_get_refer_sub_timer(void)
{
    return voip_custom_refer_sub_timer;
}


/*****************************************************************************
* FUNCTION
*  voip_custom_set_refer_sub_timer 
* DESCRIPTION
*   This function is used to set subscription expire time of REFER
* PARAMETERS
*  expire   IN  refer timer
* RETURNS
*  none
* GLOBALS AFFECTED
*   None
*****************************************************************************/
void voip_custom_set_refer_sub_timer(kal_int32 expire)
{
    if(expire > 0)
    {
        voip_custom_refer_sub_timer = expire;
    }
    else
    {
        voip_custom_refer_sub_timer = VOIP_REFER_SUBASCIPTION_EXPIRE;
    }
}


/*****************************************************************************
* FUNCTION
*  voip_custom_get_mwi_sub_timer 
* DESCRIPTION
*   This function is used to get duration of MWI subscription retry timer.
* PARAMETERS
*  none
* RETURNS
* duration of retry timer
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_uint32 voip_custom_get_mwi_sub_timer(void)
{
    return voip_custom_mwi_expire;
}


/*****************************************************************************
* FUNCTION
*  voip_custom_set_mwi_sub_timer 
* DESCRIPTION
*   This function is used to set duration of MWI subscription retry timer.
* PARAMETERS
*  none
* RETURNS
* duration of retry timer
* GLOBALS AFFECTED
*   None
*****************************************************************************/
void voip_custom_set_mwi_sub_timer(kal_uint32 expire)
{
    if(expire > 0)
    {
        voip_custom_mwi_expire = expire;
    }
    else
    {
        voip_custom_mwi_expire = VOIP_MWI_SUBS_RETRY_DURATION;
    } 
}


/*****************************************************************************
* FUNCTION
*  voip_custom_get_mwi_retry_times 
* DESCRIPTION
*   This function is used to get number of trials for MWI subscription
* PARAMETERS
*  none
* RETURNS
*  number of trials
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_uint32 voip_custom_get_mwi_retry_times(void)
{
    return voip_custom_mwi_retry;
}


/*****************************************************************************
* FUNCTION
*  voip_custom_set_mwi_retry_times 
* DESCRIPTION
*   This function is used to set number of trials for MWI subscription
* PARAMETERS
*  none
* RETURNS
*  number of trials
* GLOBALS AFFECTED
*   None
*****************************************************************************/
void voip_custom_set_mwi_retry_times(kal_uint32 retry)
{
    if(retry == 0)
    {
        voip_custom_mwi_retry = VOIP_SUBS_RETRY_TIMES;
    }
    else
    {
        voip_custom_mwi_retry = retry;    
    }
}


/*****************************************************************************
* FUNCTION
*  voip_custom_get_port_base 
* DESCRIPTION
*   This function is used to get the RTP post base
* PARAMETERS
*  none
* RETURNS
*  base of RTP port
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_uint16 voip_custom_get_port_base(void)
{
    return VOIP_RTP_PORT_BASE;
}


/*****************************************************************************
* FUNCTION
*  voip_custom_get_conf_subscription_timer 
* DESCRIPTION
*   This function is used to get the conference server subscription time
* PARAMETERS
*  none
* RETURNS
*  time of conference server subscription timer
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_uint32 voip_custom_get_conf_subscription_timer(void)
{
    return VOIP_REFER_SUBASCIPTION_EXPIRE;
}


/*****************************************************************************
* FUNCTION
*  voip_custom_set_p2p_call_state
* DESCRIPTION
*   This function is used to get the state of P2P call
* PARAMETERS
*  none
* RETURNS
*  state of P2P call.
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_bool voip_custom_get_p2p_call_state(void)
{
    return voip_custom_p2p_call;
}


/*****************************************************************************
* FUNCTION
*  voip_custom_set_p2p_call_state
* DESCRIPTION
*   This function is used to set the state of P2P call
* PARAMETERS
*  state    IN  state of P2P call
* RETURNS
*  none
* GLOBALS AFFECTED
*   None
*****************************************************************************/
void voip_custom_set_p2p_call_state(kal_bool state)
{
    voip_custom_p2p_call = state;
}


/*****************************************************************************
* FUNCTION
*  voip_custom_get_sip_supported 
* DESCRIPTION
*   This function is used to get the "SUPPORTED" capablities
* PARAMETERS
*  none
* RETURNS
*  string of SUPORTED
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_char *voip_custom_get_sip_supported(void)
{
    voip_custom_init();
    return voip_custom_sip_support;
}


/*****************************************************************************
* FUNCTION
*  voip_custom_set_sip_supported 
* DESCRIPTION
*   This function is used to set the "SUPPORTED" capablities
* PARAMETERS
*  str  IN  string to be saved
* RETURNS
*  none
* GLOBALS AFFECTED
*   None
*****************************************************************************/
void voip_custom_set_sip_supported(kal_char* str)
{
    memset(voip_custom_sip_support, 0, VOIP_CUST_STR_LEN);
    if(strlen(str))
    {
        strcpy(voip_custom_sip_support, str);
    }
}


/*****************************************************************************
* FUNCTION
*  voip_custom_get_sip_require
* DESCRIPTION
*   This function is used to get the "REQUIRE" capablities
* PARAMETERS
*  none
* RETURNS
*  string of SUPORTED
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_char *voip_custom_get_sip_require(void)
{
    voip_custom_init();

    return voip_custom_sip_support;
}


/*****************************************************************************
* FUNCTION
*  voip_custom_set_sip_require
* DESCRIPTION
*   This function is used to set the "REQUIRE" capablities
* PARAMETERS
*  str  IN  string to be saved
* RETURNS
*  string of SUPORTED
* GLOBALS AFFECTED
*   None
*****************************************************************************/
void voip_custom_set_sip_require(kal_char* str)
{
    memset(voip_custom_sip_require, 0, VOIP_CUST_STR_LEN);
    if(strlen(str))
    {
        strcpy(voip_custom_sip_require, str);
    }
}


/*****************************************************************************
* FUNCTION
*  voip_custom_get_uac_call_refresher
* DESCRIPTION
*   This function is used to get the call refresher direction of UAC call
* PARAMETERS
*  none
* RETURNS
*  direction of call refresher
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_uint32 voip_custom_get_uac_call_refresher(void)
{
    return voip_custom_sip_uac_call_refresher;
}


/*****************************************************************************
* FUNCTION
*  voip_custom_get_uas_call_refresher
* DESCRIPTION
*   This function is used to get the call refresher direction of UAS call
* PARAMETERS
*  none
* RETURNS
*  direction of call refresher
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_uint32 voip_custom_get_uas_call_refresher(void)
{
    return voip_custom_sip_uas_call_refresher;
}


/*****************************************************************************
* FUNCTION
*  voip_custom_set_uac_call_refresher
* DESCRIPTION
*   This function is used to get the call refresher direction of UAC call
* PARAMETERS
*  refresher    IN      refreher of UAC call
* RETURNS
*  direction of call refresher
* GLOBALS AFFECTED
*   None
*****************************************************************************/
void voip_custom_set_uac_call_refresher(kal_uint32 refresher)
{
    voip_custom_sip_uac_call_refresher = refresher;
}


/*****************************************************************************
* FUNCTION
*  voip_custom_set_uas_call_refresher
* DESCRIPTION
*   This function is used to get the call refresher direction of UAS call
* PARAMETERS
*  refresher    IN      refreher of UAS call
* RETURNS
*  direction of call refresher
* GLOBALS AFFECTED
*   None
*****************************************************************************/
void voip_custom_set_uas_call_refresher(kal_uint32 refresher)
{
    voip_custom_sip_uas_call_refresher = refresher;
}


/*****************************************************************************
* FUNCTION
*  voip_custom_rport
* DESCRIPTION
*   This function is used to get the RPORT SUPPORT
* PARAMETERS
*  none
* RETURNS
*  rport support of not
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_bool voip_custom_get_rport_support(void)
{
    return voip_custom_rport;
}


/*****************************************************************************
* FUNCTION
*  voip_custom_rport
* DESCRIPTION
*   This function is used to set the RPORT SUPPORT
* PARAMETERS
*  rport_support    IN  rport support of not
* RETURNS
*  setting of RPORT SUPPORT
* GLOBALS AFFECTED
*   None
*****************************************************************************/
void voip_custom_set_rport_support(kal_bool rport_support)
{
    voip_custom_rport = rport_support;
}

/*****************************************************************************
* FUNCTION
*  voip_custom_get_max_ringing_call
* DESCRIPTION
*   This function is used to get the MAX ringing call number allowed
* PARAMETERS
*  none
* RETURNS
*  max ringing call number allowed
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_uint32 voip_custom_get_max_ringing_call(void)
{
    return voip_custom_max_ringing_call;
}

/*****************************************************************************
* FUNCTION
*  voip_custom_get_ring_wait_timer
* DESCRIPTION
*   This function is used to get the ringing call waiting time
* PARAMETERS
*  none
* RETURNS
*  ringing call waiting time
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_uint32 voip_custom_get_ring_wait_timer(void)
{
    return VOIP_RINGING_WAIT_TIME;
}

#endif /* __VOIP__ */
