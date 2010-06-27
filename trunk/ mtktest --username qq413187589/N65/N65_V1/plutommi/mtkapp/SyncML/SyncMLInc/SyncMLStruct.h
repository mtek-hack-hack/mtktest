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
 *   SyncMLStruct.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for SyncML (ESI) structure
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __SYNCML_STRUCT_H__
#define __SYNCML_STRUCT_H__

#ifdef __SYNCML_SUPPORT__

#include "DataAccountGProt.h" /* MAX_DATA_ACCOUNT_NAME_LEN */

typedef struct
{
    /* sync state */
    pBOOL contact_sync_state;   // 1: synchronizing, 0: sync done
    pBOOL calendar_sync_state;  // 1: synchronizing, 0: sync done
    pBOOL email_sync_state;     // reserved, email is not support to sync
    pBOOL abort_state;
    /* sync anchor */
    U32 last_phb_anchor[MAX_SYNCML_PROFILES];
    U32 last_tdl_anchor[MAX_SYNCML_PROFILES];
    U32 next_phb_anchor;
    U32 next_tdl_anchor;
    /* app id*/
#if (defined(__MMI_DUAL_SIM__) || defined(__CBM_ALWAYS_ASK_FEATURE__))
    U8 app_id;
#endif 
    /* sync settings */
    U8 active_profile;
    U8 applications_to_sync;
#ifdef __MMI_SYNCML_REFRESH_SYNC_SUPPORT__
    U8 sync_type;
#endif
    U8 regular_sync;
    U8 power_on_sync;
    U8 sync_report_status;
    U8 profile_deactivated;
    /* sync selection */
    U8 selected_profile;
    U8 selected_applications[2];
#ifdef __MMI_SYNCML_REFRESH_SYNC_SUPPORT__
    U8 selected_type;
#endif
    U8 selected_regularity;
    /* sync progrssion indication */
    U8 sync_progress;
    U16 contact_send_noc; /* noc: numberofchanges */
    U16 contact_recv_noc;
    U16 contact_send_current; 
    U16 contact_recv_current;
    U16 calendar_send_noc; 
    U16 calendar_recv_noc;
    U16 calendar_send_current; 
    U16 calendar_recv_current;
    /* sync report */
    U8 db_sync_result;
    U16 contact_ok_cnt[3]; // add, replace, delete
    U16 contact_ng_cnt;
    U16 calendar_ok_cnt[3];  // add, replace, delete
    U16 calendar_ng_cnt;
    U16 svr_contact_ok_cnt[3];  /* 0:add, 1:replace, 2:delete */
    U16 svr_contact_ng_cnt;
    U16 svr_calendar_ok_cnt[3]; /* 0:add, 1:replace, 2:delete */
    U16 svr_calendar_ng_cnt;
    /* profile name display */
    U8 profile_name_display[MAX_SYNCML_PROFILES][MAX_SYNCML_PROFILE_NAME * ENCODING_LENGTH];
#ifdef __MMI_OP01_SYNCML_SETTING__
/* under construction !*/
#endif     
} syncml_context_struct;

#define syncml_profile_struct nvram_ef_syncml_profile_struct

#if 0 /* move to common_nvram_editor_data_item.h */
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
#endif /* 0 */

typedef struct
{
    U8 addr_buffer[MAX_SYNCML_SERVER_ADDR_LEN * ENCODING_LENGTH]; // including null-terminator
    U8 name_buffer[MAX_SYNCML_USERNAME * ENCODING_LENGTH];        // including null-terminator
    U8 pswd_buffer[MAX_SYNCML_PASSWORD * ENCODING_LENGTH];        // including null-terminator
    U8 *bearer_list[3]; // only used for pc profile
    S32 use_bearer; // only used for pc profile
#ifdef __MMI_OP01_SYNCML_SETTING__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP01_SYNCML_SETTING__ */
    U8 server_addr_hint[MAX_SYNCML_SERVER_ADDR_LEN * ENCODING_LENGTH];
    U8 contact_addr_hint[MAX_SYNCML_DATABASE_ADDR_LEN * ENCODING_LENGTH];
    U8 calendar_addr_hint[MAX_SYNCML_DATABASE_ADDR_LEN * ENCODING_LENGTH];
    U8 data_account_hint[MAX_DATA_ACCOUNT_NAME_LEN * ENCODING_LENGTH];
} syncml_profile_edit_struct;

typedef struct
{
    U32 net_id;
    U8 data_account[MAX_DATA_ACCOUNT_NAME_LEN * ENCODING_LENGTH]; // including null-terminator
    U8 name_buffer[MAX_SYNCML_PROXY_USERNAME * ENCODING_LENGTH];        // including null-terminator
    U8 pswd_buffer[MAX_SYNCML_PROXY_PASSWORD * ENCODING_LENGTH];        // including null-terminator
    U8 *yes_no_list[2];
    U8 *http_wap_list[2];
    S32 use_proxy;
    S32 conn_type;
    U8 proxy_ip[4][4 * ENCODING_LENGTH];
    U8 proxy_port[MAX_SYNCML_PROXY_PORT_LEN * ENCODING_LENGTH];
} syncml_data_account_edit_struct;

typedef struct
{
    U8 operation; // add, modify, or delete
    U8 database;
    U16 luid;
    U16 result;
    U8 more_data;
    U8 *vobj_ptr;
    U16 *luid_buf;
} syncml_sync_request_struct;

/*following below is for CCA use.*/
typedef struct
{
	U8  proxy_id[MAX_PROXY_ID_LEN];           /*For mapping profile number use. */ 
	U8  proxy_username[MAX_SYNCML_PROXY_USERNAME];	      /*Proxy user name 30 */
	U8  proxy_password[MAX_SYNCML_PROXY_PASSWORD]; 	      /*Proxy password 30 */
	U8  proxy_addr[MAX_PROXY_IP_ADDR_LEN];  	      /*Proxy ip */
	U8  proxy_portnbr[MAX_PROXY_PORT_LEN];      /*proxy port */
    U32  dataaccountid;  	                         /*DataAccount id */
    U8  conn_type;
} ota_proxy_context_struct;

typedef struct
{
    U16 conf_id;                             /* Configuration ID                  */
    S32 doc_hdl;                             /* Configuration document handle     */
    U8 currentprofnamelist[MAX_SYNCML_SV_PROFILES][MAX_SYNCML_PROFILE_NAME * ENCODING_LENGTH];  
        /*currentProfNameList for select screen display*/
    U8 num_profiles;                         /* Num of processed profiles         */
    U8 num_proxy;                            /*Num of processed proxy*/    
    U8 app_to_proxy[MAX_SYNCML_SV_PROFILES][MAX_PROXY_ID_LEN];   /*For mapping profile number use.*/
	S16 in_use;                               /*The index of the profile that is being used currently*/			       
    U8 iter;                                 /* Used to traverse profiles         */
    S16 dst_idx[MAX_SYNCML_SV_PROFILES];         /*The index of slot where place the new profile.*/
    BOOL isvalidprof[MAX_SYNCML_SV_PROFILES];
        /*Used to place profiles index that are valid*/
    nvram_ef_syncml_profile_struct *profile[MAX_SYNCML_SV_PROFILES];
        /*Be a temp storage used to store the settings of the new profile.*/    
    ota_proxy_context_struct proxy[MAX_SYNCML_SV_PROFILES]; 
        /*Be a temp storage used to store the data of the new proxy.*/
} syncml_ota_context_struct;

#ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
typedef struct
{
    pBOOL sync_from_server;
    U8 ui_mode;
    U8 sas_sync_type;
    U8 sas_applications_to_sync;
    U8 sas_active_profile;
#ifdef __MMI_SYNCML_REFRESH_SYNC_SUPPORT__
    U8 phn_sync_type;
#endif
    U8 phn_applications_to_sync;
    U8 phn_active_profile;
    U8 sas_server_uri[MAX_SYNCML_SERVER_ADDR_LEN];
    U8 sas_contact_database_uri[MAX_SYNCML_DATABASE_ADDR_LEN];
    U8 sas_calendar_database_uri[MAX_SYNCML_DATABASE_ADDR_LEN];
} syncml_sas_struct;
#endif /* __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__ */

#endif /* __SYNCML_SUPPORT__ */

#endif /* __SYNCML_STRUCT_H__ */

