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
/*
 * Copyright (C) Teleca Mobile Technologies AB, 2002-2003.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Teleca Mobile Technologies AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Teleca Mobile Technologies AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */
/*
 * bra_if.h
 *
 * Created by Mats Tedenvall
 *
 * Revision  history:
 * 
 *
 */

#ifndef _bra_if_h
#define _bra_if_h

#ifndef _bra_cfg_h
#include "bra_cfg.h"
#endif

#ifndef _msf_cfg_h
#include "msf_cfg.h"
#endif
#ifndef _msf_def_h
#include "msf_def.h"
#endif
#ifndef _msf_dcvt_h
#include "msf_dcvt.h"
#endif


/**********************************************************************
 * External Signals
 **********************************************************************/

/**********************************************************************
 * Signal parameter definitions:
 **********************************************************************/
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
#endif //0


typedef enum
{
  BRA_SIG_CREATE_UI =  ((MSF_MODID_BRA << 8) + 1),
  BRA_SIG_DESTROY_UI,        
  BRA_SIG_SHOW_DIALOG,        
  BRA_SIG_WTAI_MAKE_CALL,     
  BRA_SIG_WTAI_SEND_DTMF,     
  BRA_SIG_WTAI_PB_ADD_ENTRY,  
  BRA_SIG_SAT_LAUCH_REQUEST,  
  BRA_SIG_SHOW_DIALOG_EXT,    
  BRA_SIG_SHOW_AUTH_DIALOG,   
  BRA_SIG_GET_PUSH_MSG_NUM,   
  BRA_SIG_GET_PUSH_MSG_LIST, 
  BRA_SIG_GET_PUSH_MSG_INFO,  
  BRA_SIG_DEL_PUSH_MSG_INBOX, 
  BRA_SIG_VIEW_PUSH_MSG,      
  BRA_SIG_NOTIFY_PINNED_PROV, 
  BRA_SIG_INVALID_PROV_RECV,  
  BRA_SIG_REGISTER_PROV_AUTH, 
  BRA_SIG_HANDLE_EXTSCHEME,   
  BRA_SIG_CANCEL_PROV_CONF,   
  BRA_SIG_BEARER_STATUS,      
  BRA_SIG_SELECT_BOOKMARK,   
  BRA_SIG_SELECT_BOOKMARK_REPLY,  
  BRA_SIG_DOWNLOAD_COMPLETE,  
  BRA_SIG_NOTIFY_BEARER_INFO, 
    
#ifdef BRA_CFG_CCA
  BRA_SIG_CCA_APP_CONFIGURE_IND,  
  BRA_SIG_CCA_GET_PROF_IND,        
  BRA_SIG_CCA_UPDATE_PROF_IND,     
#endif /* BRA_CFG_CCA */
    
#ifdef BRA_CFG_USE_DTCNT_SELECT_SCREEN
  BRA_SIG_NET_ID_SELECT_RSP,      
#endif
    
  BRA_SIG_DA_DOWNLOAD_INFO_IND,     
  BRA_SIG_PROV_AUTH_FAILED,
    
  BRA_SIG_CBM_SELECT_ACCOUNT_RESULT_IND,      
  BRA_SIG_CBM_ADD_BEARER_STATUS_NOTIFY_CNF,
  BRA_SIG_CBM_DEL_BEARER_STATUS_NOTIFY_CNF,
  BRA_SIG_CBM_BEARER_STATUS_NOTIFY_IND,

#ifdef BRA_CFG_DUAL_SIM
  BRA_SIG_SIM_INFO_NOTIFY_IND,
#endif
  
  BRA_SIG_MAX_ITEM
}bra_sig_enum;



#define BRA_UI_MAIN_MENU     0
#define BRA_UI_PROF_MENU     1
#define BRA_UI_VIEWPORT      2
#define BRA_UI_RESET_COMPL   3
#define BRA_UI_GOTO_URL      4
#define BRA_UI_MEM_FULL      5
#define BRA_UI_HOMEPAGE      6
#define BRA_UI_ADD_BOOKMARK  7


#define BRA_SCHEME_SMS      0x01
#define BRA_SCHEME_EGE      0x02
#define BRA_SCHEME_RTSP     0x03
#define BRA_SCHEME_MMS	    0x04

#define BRA_DNSTATUS_OK     0
#define BRA_DNSTATUS_FAIL   1

#define BRA_BRINFO_CSD_TIMEOUT  0
#define BRA_BRINFO_CSD_DISC     1

#ifdef BRA_CFG_CANCEL_PROV_CONF
#define PRS_CFG_CANCEL_PROV_CONF
#endif

/*
 * Called by any other module that wants to use the BRA module.
 */
void
BRAif_startInterface (void);

/**********************************************************************
 * Conversion routines for all signal owned by this module.
 * None of these functions should be called directly by another module.
 **********************************************************************/

/*
 * Convert from memory buffer to signal structs.
 */
void*
bra_convert (MSF_UINT8 module, MSF_UINT16 signal, void* buffer);

/*
 * Released a signal structure to a signal.
 */
void
bra_destruct (MSF_UINT8 module, MSF_UINT16 signal, void* p);

typedef struct {
  MSF_UINT8 type;
  char *url;
} bra_create_ui_t;

void
BRAif_createUI (MSF_UINT8 type, const char* url);

void
BRAif_destroyUI (void);

typedef struct {
  MSF_UINT8 module;
  int requestId;
  int authType;
  char *realm;
  char *username;
  int warnings;
} bra_show_auth_dlg_t;

void
BRAif_showAuthDialog (MSF_UINT8 module, int requestId, int authType, 
                      const char *realm, const char* username, int warnings);

typedef struct {
  MSF_UINT8 dlg_type;
  MSF_UINT32 ms;
} bra_show_dlg_t;

void
BRAif_showDialog (MSF_UINT8 dlg_type, MSF_UINT32 ms);

typedef struct {
  MSF_UINT8 dlg_type;
  MSF_UINT32 ms;
  MSF_UINT32 callback;
} bra_show_dlg_ext_t;

void
BRAif_showDialogExt (MSF_UINT8 dlg_type, MSF_UINT32 ms, MSF_UINT32 callback);

int
BRAif_getNetAccId (void);

#ifdef MMS_CFG_FALLBACK_SUPPORT
int
BRAif_getMMSFallbackStatus (void);

int
BRAif_setMMSFallback (void);

int
BRAif_restoreMMSFallback (void);
#endif  /* MMS_CFG_FALLBACK_SUPPORT */

typedef struct { 
  MSF_UINT8 modId;
  MSF_UINT16 telId;
  char* number;
} bra_wtai_make_call_t;

void
BRAif_telMakeCall (MSF_UINT8 modId, MSF_UINT16 telId, const char* number);

typedef struct {
  MSF_UINT8 modId;
  MSF_UINT16 telId;
  char *dtmf;
} bra_wtai_send_dtmf_t;

void 
BRAif_telSendDtmf (MSF_UINT8 modId, MSF_UINT16 telId, const char* dtmf);

typedef struct {
  MSF_UINT8 modId;
  MSF_UINT16 pbId;
  char* name;
  char* number;
} bra_wtai_pb_add_entry_t;

void
BRAif_pbAddEntry (MSF_UINT8 modId, MSF_UINT16 pbId, const char* name, const char* number);

typedef struct {
  MSF_UINT8 browserMode;
  MSF_UINT8 browserIdentity;
  MSF_UINT8 sim_id;
  MSF_UINT16 noUrl;
  unsigned char *url;
  MSF_UINT16 noBearer;
  unsigned char *bearer;
  MSF_UINT16 noGateway;
  unsigned char *gateway;
} bra_sat_lauch_request_t;

void
BRAif_satLauchRequest (MSF_UINT8 browserMode, 
                       MSF_UINT8 browserIdentity,
                       MSF_UINT8 wap_sim_id,
                       MSF_UINT16 noUrl,
                       unsigned char *url,
                       MSF_UINT16 noBearer,
                       unsigned char *bearer,
                       MSF_UINT16 noGateway,
                       unsigned char *gateway);

typedef struct {
  MSF_UINT32 dlgHandle;
  MSF_UINT32 yesHandle;
  MSF_UINT32 noHandle;
  MSF_UINT8  stage;
  MSF_UINT32 sim_id;
} bra_prs_pinned_prov_t;

void
BRAif_notifyPinnedProvDocNew(MSF_UINT32 dlgHandle, MSF_UINT32 yesHandle, MSF_UINT32 noHandle, MSF_UINT32 prs_sim_id);

void
BRAif_notifyPinnedProvDocAbort(void);

void
BRAif_invalidProvDocRecv(void);

void
BRAif_provAuthFailed(void);

void
BRAif_registerProvAuth(MSF_UINT32 dlgHandle, MSF_UINT32 noHandle);

void
BRAif_cancelProvConf(void);

#ifdef __UNIFIED_MSG_SUPPORT__

void
BRAif_getPushMsgNumber (void);

typedef struct {
  MSF_UINT16 startFromMsg;
} bra_get_push_msg_list_t;

void
BRAif_getPushMsgList (MSF_UINT16 startFromMsg);

typedef struct {
  MSF_UINT16 startFromMsg;
  MSF_UINT16 numberOfMsg;
} bra_get_push_msg_info_t;

void
BRAif_getPushMsgInfo (MSF_UINT16 startFromMsg, MSF_UINT16 numberOfMsg);

void
BRAif_delPushMsgInbox (void);

typedef struct {
  MSF_UINT16 msgIndex;
} bra_view_push_msg_t;

void
BRAif_viewPushMsg (MSF_UINT16 msgIndex);

#endif

/* Functions for BRS Plug-in */
typedef struct {
  MSF_UINT8 schType;
  MSF_UINT8 modId;
  MSF_UINT16 id;
  char* data;
} bra_handle_extscheme_t;

void
BRAif_smsSend (MSF_UINT8 modId, MSF_UINT16 smsId, const char* number);

void
BRAif_egeSend (MSF_UINT8 modId, MSF_UINT16 egeId, const char* param);

void
BRAif_rtspSend (MSF_UINT8 modId, MSF_UINT16 rtspId, const char* tgturl);

void
BRAif_mmsSend (MSF_UINT8 modId, MSF_UINT16 mmsId, const char* number);

typedef struct {
  MSF_UINT8 bearerType;
  MSF_UINT32 status;
} bra_handle_bearer_status_t;

void
BRAif_handleBearerStatus (MSF_UINT8 bearer_type, MSF_UINT32 status);

typedef struct {
  MSF_UINT8 srcModId;
} bra_select_bookmark_t;

typedef struct {
  MSF_UINT8 result;
  char* title;
  char* url;
} bra_select_bookmark_reply_t;

void
BRAif_selectBookmark (MSF_UINT8 srcModId);

typedef struct {
  MSF_UINT8 status;
} bra_download_complete_t;

void
BRAif_downloadComplete(MSF_UINT8 status);


typedef struct {
  MSF_UINT8 bearer;     /* HDI_SOCKET_BEARER_GSM_CSD */
  MSF_UINT8 status;     /* BRA_BRINFO_CSD_TIMEOUT */
} bra_notify_bearer_info_t;

void
BRAif_notifyBearerInfo(MSF_UINT8 bearer, MSF_UINT8 status);


typedef struct {
  MSF_UINT32 jobCount;           /* current DA job count */
  MSF_UINT32 activeJobCount;     /* current DA active job count */
} bra_da_download_info_t;

void
BRAif_DADownloadInfo(MSF_UINT32 jobCount, MSF_UINT32 activeJobCount);



/**********************************************************************
 * BRA CCA interface
 **********************************************************************/
#ifdef BRA_CFG_CCA

/*for BRA_SIG_CCA_APP_CONFIGURE_IND*/
typedef struct
{
  MSF_UINT16      sim_id;
  MSF_UINT16      config_id;
  MSF_INT32       hConfig;
  MSF_INT32       num_symbols;
  MSF_UINT16      *l1symbols;
  MSF_INT32       *l1symbols_count;
}bra_cca_app_configure_ind_t;



/*MSG_ID_MMI_CCA_APP_CONFIGURE_IND*/
void
BRAif_CcaAppConfigure(MSF_UINT16 cca_sim_id, MSF_UINT16 config_id,
                      MSF_INT32 hConfig, MSF_INT32 num_symbols, 
                      MSF_UINT16* l1symbols, MSF_INT32* l1symbols_count);




/*for BRA_SIG_CCA_GET_PROF_IND*/
typedef struct
{
  MSF_UINT16      sim_id;
  MSF_UINT16      app_id;
  MSF_INT32       prof_id;
}bra_cca_get_prof_ind_t;

/*MSG_ID_MMI_CCA_APP_GET_PROF_IND*/
void
BRAif_CcaGetProfile(MSF_UINT16 cca_sim_id, MSF_UINT16 app_id, MSF_INT32 prof_id);


/*for BRA_SIG_CCA_UPDATE_PROF_IND*/
typedef struct
{
  MSF_UINT16      sim_id;
  MSF_UINT16      app_id;
  MSF_INT32       prof_id;
  MSF_INT32       hConfig;
}bra_cca_update_prof_ind_t;

/*MSG_ID_MMI_CCA_APP_UPDATE_PROF_ID*/
void
BRAif_CcaUpdateProfile(MSF_UINT16 cca_sim_id, MSF_UINT16 app_id, MSF_INT32 prof_id, MSF_INT32 hConfig);




#endif /*BRA_CFG_CCA*/



#ifdef BRA_CFG_USE_DTCNT_SELECT_SCREEN


#define  BRA_MULITI_NET_ID_MAX_NUM     (2)  


typedef struct  
{
  MSF_BOOL        result;
  MSF_UINT16      app_id;
  MSF_UINT32      id_num;
  MSF_UINT32      bearer_scope;
  MSF_UINT32      *bearer_type;
  MSF_UINT32      *net_id;
}bra_net_id_select_rsp_t;


void
BRAif_handleNetIdSelectResponse(MSF_BOOL result, MSF_UINT16 app_id,
                                MSF_UINT32 id_num, MSF_UINT32 bearer_scope, 
                                MSF_UINT32 *bearer_type, MSF_UINT32 *net_id);


#endif/*BRA_CFG_USE_DTCNT_SELECT_SCREEN*/







/* BRA_SIG_CBM_SELECT_ACCOUNT_RESULT_IND */
typedef struct  
{
  MSF_UINT32  acct_id;
  MSF_BOOL    result;
}bra_cbm_select_result_t;

void
BRAif_cbmSelectResult(MSF_UINT32 acct_id, MSF_BOOL result);


/* BRA_SIG_CBM_ADD_BEARER_STATUS_NOTIFY_CNF */
typedef struct  
{
  MSF_UINT8   index;
  MSF_BOOL    result;
}bra_cbm_add_bearer_status_notify_t;

void
BRAif_cbmAddBearerStatusNotify(MSF_UINT8 index, MSF_BOOL result);


/* BRA_SIG_CBM_DEL_BEARER_STATUS_NOTIFY_CNF */

typedef struct  
{
  MSF_UINT32  acct_id;
  MSF_BOOL    result;
}bra_cbm_del_bearer_status_notify_t;

void
BRAif_cbmDelBearerStatusNotify(MSF_UINT32 acct_id, MSF_BOOL result);

/* BRA_SIG_CBM_BEARER_STATUS_NOTIFY_IND */

typedef struct  
{
  MSF_UINT32 acct_id;
  MSF_UINT32 status;
}bra_cbm_bearer_status_notify_t;

void
BRAif_cbmBearerStatusNotify(MSF_UINT32 acct_id, MSF_UINT32 status);


#ifdef BRA_CFG_DUAL_SIM

typedef struct  
{
  MSF_UINT8   sim_status;
  MSF_UINT8   setting_mode;
}bra_sim_info_notify_t;


void
BRAif_handleSimInfoNotify(MSF_UINT8 sim_status, MSF_UINT8 setting_mode);

#endif /* BRA_CFG_DUAL_SIM */





#endif /*_bra_if_h*/




