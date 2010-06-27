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

/*****************************************************************************
 *
 * Filename:
 * ---------
 * custom_voip_config.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for include file of VoIP customization parameters. 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _CUSTOM_VOIP_CONFIG_H
#define _CUSTOM_VOIP_CONFIG_H

//#ifdef __VOIP__

/*===========================================================
 * VoIP System Related Configurations (DO NOT NOTIFY!!!)
 *===========================================================*/

/*===========================================================
 * VoIP Protocol Related Configurations
 *===========================================================*/
typedef enum VOIP_REG_PRIORITY_ENUM
{
    VOIP_REG_OUTBOUND_SERVER_PRIORITY_VALUE,
    VOIP_REG_REGISTRAR_PRIORITY_VALUE,
    VOIP_REG_PRIORITY_END
}voip_reg_priority_enum;

 /*Duration of subscription retry timer (in second), 0 == not retry */
#define VOIP_MWI_SUBS_RETRY_DURATION (60) 
/* number of tries for subscription, 0 == not retry */
#define VOIP_SUBS_RETRY_TIMES	    (5)

#define VOIP_DEFAULT_LOCAL_PORT     (5060)

#define VOIP_MAX_NUM_CALL		    (6) 	    /* Maximun number of call */
#define VOIP_MAX_RINGING_CALL       (1)         /* Maximun number of ringing call */
#define VOIP_MEM_SIZE               (180*1024)  /* size of memory pool for VoIP task */

/* Expire macros: 
  * (1) -1 : use default 
  * (2) > 0 : unit is second
  * (3) MUST not set to "zero"
  */

/* registration expiry time in second , shall be greated than 0 */   
#define VOIP_REREGISTER_TIMER           (3600)  

/* INVITE refresh timer, shall be greater than 90 */    
#define VOIP_SESSION_EXPIRE             (1800)  

/* Subscription expiry time for incoming REFER, shall be greater than 0 */    
#define VOIP_REFER_SUBASCIPTION_EXPIRE  (60)

/* Incoming Ringing waiting time(s) */
#define VOIP_RINGING_WAIT_TIME          (64)

/* Subscription expiry time for conference server call state, 
   shall be greater than 0 or shall be -1 (default value)
*/
#define VOIP_CONF_SUBSCRIPTION_EXPIRE (-1)

/*===========================================================
 * VoIP SIP Capability
 *===========================================================*/
#define VOIP_SIP_ALLOW "INVITE, ACK, CANCEL, OPTIONS, BYE, REFER, NOTIFY" /* no UPDATE */
#define VOIP_SIP_ACCEPT "application/sdp"

/* 
    <SUPPORTED filed in SIP messages>
    "100rel" and "timer" can be removed individually if you do not want to 
    support (one of) them 
*/
#define VOIP_SIP_SUPPORTED "replaces, timer" /* no 100rel */

#define VOIP_SIP_REQUIRE ""

#define VOIP_SIP_UAC_CALL_REFRESH   VOIP_UAC_REFRESH    /* let the caller send call refresh */
#define VOIP_SIP_UAS_CALL_REFRESH   VOIP_UAC_REFRESH    /* let the caller send call refresh */

#define VOIP_SIP_ALLOW_EVENT "refer"
#define VOIP_UAC_STRING "VoIP-Client MTK/v1.0"
#define VOIP_UAS_STRING "VoIP-Server MTK/v1.0"
#define VOIP_SIP_ACCEPT_ENCODING "identity" /* [SIP CONF TEST] */
#define VOIP_SIP_ACCEPT_LANGUAGE "en, zh" /* [SIP CONF TEST] */

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*===========================================================
 * VoIP Network Setting
 *===========================================================*/
#define VOIP_RTP_PORT_BASE          (40000) /* port base of RTP session 
                                               (PoC base == 30000) */


extern voip_call_struct voip_custom_call_list[];
extern voip_call_sip_struct voip_custom_call_sip_list[];

extern kal_uint8 voip_custom_mem_pool[];

extern kal_uint32 voip_custom_get_max_call_num(void);
extern kal_uint32 voip_custom_get_mem_size(void);
extern kal_char *voip_custom_get_uac_string(void);
extern kal_char *voip_custom_get_uas_string(void);
extern kal_uint32 voip_custom_get_reregister_timer(void);
extern void voip_custom_set_reregister_timer(kal_uint32 expire);
extern kal_char *voip_custom_get_sip_allow(void);
extern kal_char *voip_custom_get_sip_accept(void);
extern kal_char *voip_custom_get_sip_allow_event(void);
extern kal_bool voip_custom_get_p2p_call_state(void);
extern kal_int32 voip_custom_get_call_refresh_timer(void);
extern kal_int32 voip_custom_get_refer_sub_timer(void);
extern kal_uint32 voip_custom_get_conf_subscription_timer(void);
extern kal_char *voip_custom_get_sip_accept_encoding(void);//[SIP CONF TEST]
extern kal_char *voip_custom_get_sip_accept_language(void);//[SIP CONF TEST]
extern kal_uint32 voip_custom_get_ring_wait_timer(void);
//#endif /* __VOIP__ */

#endif /* _CUSTOM_VOIP_CONFIG_H */

