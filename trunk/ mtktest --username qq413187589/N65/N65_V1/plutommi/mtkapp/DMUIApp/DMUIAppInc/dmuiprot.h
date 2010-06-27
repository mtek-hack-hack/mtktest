/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *	dmuiprot.h
 *
 * Project:
 * --------
 *	MAUI
 *
 * Description:
 * ------------
 *	This file external functions for DMUI application.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *
 *****************************************************************************/
#ifndef _DMUIPROT_H
#define _DMUIPROT_H

#include "MMI_features.h"

#ifdef SYNCML_DM_SUPPORT

#include "DMTypeDef.h"
#include "GlobalConstants.h"
#include "gui_data_types.h"

#define DMUI_MAX_DT_INPUT_LENGTH       3
#define DMUI_MAX_IPADDRES_LENGTH       4
#define DMUI_MAX_SERVERID              5
#define DMUI_MAX_PROXY_PORT_LEN        6

#define DM_DEFAULT_PROFILE_INDEX       0

#define DMUI_INPUT_BUFFER_SIZE         2048

#define DMUI_MIN_PIN_LENGTH 4
#define DMUI_MAX_PIN_LENGTH 8

#define MAX_SYNCML_DM_PROFILES         DMUI_MAX_SERVERID

#define DMUI_SEND_MSG_TO_DMPS(msgid, req)  {                 \
    ilm_struct *ilm_send = allocate_ilm(MOD_MMI);            \
    ilm_send->msg_id = (msgid);                              \
    ilm_send->peer_buff_ptr = NULL;                          \
    ilm_send->local_para_ptr = (local_para_struct*)(req);    \
    ilm_send->src_mod_id = MOD_MMI;                          \
    ilm_send->dest_mod_id = MOD_DM;                          \
    ilm_send->sap_id = 0;                                    \
msg_send_ext_queue(ilm_send);  }

/***************************************************************************** 
* External Variable
*****************************************************************************/
extern const U16 gIndexIconsImageList[];

extern U8 subMenuData[MAX_SUB_MENUS][MAX_SUB_MENU_SIZE];
extern PU8 subMenuDataPtrs[MAX_SUB_MENUS];

MMI_BOOL mmi_dmui_serverid_valid(S8 *p_serverid);

typedef enum
{
    MMI_DMUI_SERVERID = 0,
    MMI_DMUI_SERVERID_EDITOR,
    MMI_DMUI_SERVER_PASSWORD,
    MMI_DMUI_SERVER_PASSWORD_EDITOR,
    MMI_DMUI_SERVER_ADDRESS,

    MMI_DMUI_SERVER_ADDRESS_EDITOR,
    MMI_DMUI_USERNAME,
    MMI_DMUI_USERNAME_EDITOR,
    MMI_DMUI_USER_PASSWORD,
    MMI_DMUI_USER_PASSWORD_EDITOR,

#ifndef __MMI_OP01_DM_PROFILE_SETTING__
    MMI_DMUI_CONNECTION_SETTING,
    MMI_DMUI_CONNECTION_SETTING_EDITOR,
#endif  /* __MMI_OP01_DM_PROFILE_SETTING__ */
    MMI_DMUI_AUTHTYPE,
    MMI_DMUI_AUTHTYPE_EDITOR,
    MMI_DMUI_INLINE_ITEM_TOTAL
} dmui_setting_inline_item_enum;

typedef enum
{
    MMI_DMUI_CS_DATA_ACCOUNT = 0,
    MMI_DMUI_CS_DATA_ACCOUNT_EDITOR,
    MMI_DMUI_CS_USE_PROXY,
    MMI_DMUI_CS_USE_PROXY_EDITOR,
    MMI_DMUI_CS_IP,

    MMI_DMUI_CS_IP_EDITOR,
    MMI_DMUI_CS_PORT,
    MMI_DMUI_CS_PORT_EDITOR,
    MMI_DMUI_CS_USERNAME,
    MMI_DMUI_CS_USERNAME_EDITOR,
    
    MMI_DMUI_CS_PASSWORD,
    MMI_DMUI_CS_PASSWORD_EDITOR,
    MMI_DMUI_CS_INLINE_ITEM_TOTAL
} dmui_cs_setting_inline_item_enum;

typedef enum
{
    MMI_DMUI_IDLE_STATUS = 0,
    MMI_DMUI_INIT_SESSION_STATUS,
    MMI_DMUI_BOOTSTRAP_USERPIN_STATUS,
    MMI_DMUI_LIST_SERVERID_STATUS,
    MMI_DMUI_GET_PSERVERID_STATUS,

    MMI_DMUI_SET_PSERVERID_STATUS,
    MMI_DMUI_EDIT_SET_PSERVERID_STATUS,     /* set P_serverid when edit P_serverid item and server id changed */
	MMI_DMUI_ERASE_SET_PSERVERID_STATUS,	/* set P_serverid when erase P_serverid item and server id empty */
    MMI_DMUI_ADD_ACCOUNT_STATUS,
    MMI_DMUI_EDIT_ACTIVATED_ADD_ACCOUNT_STATUS,   /* add account when edit op with serverid active */

    MMI_DMUI_EDIT_INACTIVATED_ADD_ACCOUNT_STATUS, /* add account when edit op with serverid inactive */
    MMI_DMUI_ERASE_INACTIVATED_ACCOUNT_STATUS,  /* del inactivated account when erase operation */
	MMI_DMUI_ERASE_ACTIVATED_ACCOUNT_STATUS,	/* del activated account when erase operation */
    MMI_DMUI_EDIT_ACTIVATED_DEL_ACCOUNT_STATUS,   /* del account when edit operation with activated server id */
    MMI_DMUI_EDIT_INACTIVATED_DEL_ACCOUNT_STATUS, /* del account when edit operation with inactivated server id */

    MMI_DMUI_GET_ACCOUNT_STATUS,
    MMI_DMUI_DOWNLOAD_STATUS,
    MMI_DMUI_UPDATE_STATUS,
    MMI_DMUI_ALERT_STATUS,
    MMI_DMUI_ONLY_INIT_SERVERID_STATUS,

    MMI_DMUI_ONLY_INIT_PSERVERID_STATUS,
    MMI_DMUI_STATUS_END,   /* end of DMUI status */
    MMI_DM_OTA_LIST_SERVERID_STATUS,
    MMI_DM_OTA_GET_PSERVERID_STATUS,
    MMI_DM_OTA_ADD_ACCOUNT_STATUS,

    MMI_DM_OTA_ACTIVE_ADD_ACCOUNT_STATUS,
    MMI_DM_OTA_REPACE_INACTIVATED_DEL_ACCOUNT_STATUS,
    MMI_DM_OTA_REPACE_INACTIVATED_ADD_ACCOUNT_STATUS,
    MMI_DM_OTA_REPACE_ACTIVATED_DEL_ACCOUNT_STATUS,
    MMI_DM_OTA_REPACE_ACTIVATED_ADD_ACCOUNT_STATUS,

    MMI_DM_OTA_REPACE_ACTIVATED_SET_PSERVERID_STATUS,
    MMI_DM_OTA_INIT_ADD_ACCOUNT_STATUS,
    MMI_DMUI_STATUS_TOTAL
} dmui_message_status_enum;

typedef enum
{
    MMI_DMUI_SERVER_MAP_IDLE = 0,
    MMI_DMUI_SERVER_MAP_ADD,
    MMI_DMUI_SERVER_MAP_EDIT,   
    MMI_DMUI_SERVER_MAP_DELETE,
    MMI_DMUI_SERVER_MAP_TOTAL
} dmui_server_map_enum;

typedef struct
{
    S8  year[DMUI_MAX_DT_INPUT_LENGTH * ENCODING_LENGTH];
    S8  month[DMUI_MAX_DT_INPUT_LENGTH * ENCODING_LENGTH];
    S8  day[DMUI_MAX_DT_INPUT_LENGTH * ENCODING_LENGTH];
    S8  hour[DMUI_MAX_DT_INPUT_LENGTH * ENCODING_LENGTH];
    S8  minute[DMUI_MAX_DT_INPUT_LENGTH * ENCODING_LENGTH];

    UI_character_type ip_addr_str[4][DMUI_MAX_IPADDRES_LENGTH * ENCODING_LENGTH];
} dmui_alert_input_struct;

typedef struct
{
    U8                          dmui_serverid[DM_MAX_ID_STR];
    U8                          dmui_nodename[DM_MAX_ID_STR];   /* from 1 - DMUI_MAX_SERVERID */
} dmui_serverid_map_struct;

typedef struct
{
    dm_account_struct           dmui_cur_edit_account;
    dm_conn_setting_struct      dmui_cur_edit_conn_setting;             
    dm_omadl_dd_struct          dmui_display_info;
    dm_alert_struct             dmui_alert_struct;
    dmui_alert_input_struct     dmui_alert_input_context;   /* struct for alert input */
    dmui_message_status_enum    dmui_status;    /* DMUI message status */
    U8                          dmui_alert_input_text[DMUI_INPUT_BUFFER_SIZE];  /* input text */
    U8                          dmui_alert_string[DMUI_INPUT_BUFFER_SIZE];
    U8                         *mmi_dmui_cs_use_proxy[2];  /* use proxy string */
    U8                         *mmi_dmui_authtype[DM_AUTH_TYPE_TOTAL];
    U8                          dmui_alert_default_value[MAX_SUB_MENUS];
    U8                          pin_password[(DMUI_MAX_PIN_LENGTH + 1) * ENCODING_LENGTH];
    U8                          proxy_port_str[DMUI_MAX_PROXY_PORT_LEN * ENCODING_LENGTH];
    U8                          dmui_hilite_index;  /* index of high light item */
    U8                          dmui_alert_choice_num;  /* number of alert choice list */
    U32                         dmui_hilite_serverid_index; /* high light server id index */
    U8                          dmui_primary_serverid[DM_MAX_ID_STR];
    U8                          dmui_alert_choice_send[DMUI_INPUT_BUFFER_SIZE];
    U8                          dmui_serverid_array[DMUI_MAX_SERVERID][DM_MAX_ID_STR];
    U16                         dmui_dl_percent;    /* download progress */
    U16                         dmui_alert_scr_id;  /* current alert screen id */

    U16                         app_id;             /* Save app_id for get & update DM   */
    S32                         prof_id;            /* Save prof id for get & update DM  */
    S32                         hConfig;

    kal_wchar                   *dmui_dd_rsp_file_path;
    MMI_BOOL                    dmui_info_done_flag;  /* save conn setting info yes or not and set done to info screen */
    MMI_BOOL                    dmui_data_account_init;     /* flag to mark data account init or not */
    UI_character_type           dmui_info_cs_ip[4][DMUI_MAX_IPADDRES_LENGTH * ENCODING_LENGTH];  /* conn setting ip */
} dmui_context_struct;


/* save server id list to global struct */
extern void mmi_dmui_save_serverid_list(U8 *sour_str);

/* convert unicode string to 4 digit int and set IP inline editor */
extern void mmi_dmui_return_four_digit_ip(U8 *four_digit, S8 *ip_ucs_string);

#ifdef __MMI_SYNCML_DM_OTAP__

typedef struct 
{
    S32          auth_level;
    dm_auth_type_enum auth_pref;
    U8           auth_pref_unused[3];
    U8           auth_name[DM_MAX_ID_STR];
    U8           auth_pw[DM_MAX_ID_STR];
    U8           auth_nonce[DM_MAX_NAME_STR];
} mmi_dm_ota_appauth_struct;

typedef struct 
{
    U8           proxy_id[DM_MAX_ID_STR];
    U8           conn_type;

    U8           conn_ref[DM_MAX_ID_STR];
    U8           proxy_addr[DM_MAX_IP_SIZE];
    U8           proxy_user_name[DM_MAX_ID_STR];
    U8           proxy_user_pw[DM_MAX_ID_STR];
    U32          proxy_port;
    U16          data_account_id;
    U8           data_account_id_unused[2];
    MMI_BOOL     proxy_used;
    U8           proxy_used_unused[3];
} mmi_dm_ota_conn_setting_struct;

typedef struct 
{
    U32          port_num;
    dm_auth_type_enum   auth_pref;
    U8           auth_pref_unused[3];
    dm_addr_type_enum   addr_type;
    U8           addr_type_unused[3];
    U8           node_name[DM_MAX_ID_STR];
    U8           server_addr[DM_MAX_URI_SIZE];
    U8           server_id[DM_MAX_ID_STR];
    U8           server_pw[DM_MAX_ID_STR];
    U8           server_nonce[DM_MAX_NAME_STR];
    U8           server_prenonce[DM_MAX_NAME_STR];
    U8           user_name[DM_MAX_ID_STR];
    U8           user_pw[DM_MAX_ID_STR];
    U8           client_nonce[DM_MAX_NAME_STR];
    U8           acct_name[DM_MAX_ID_STR];
    U8           proxy_id[DM_MAX_ID_STR];       /* For mapping profile number use. */
    mmi_dm_ota_conn_setting_struct  conn_setting;
} mmi_dm_ota_account_struct;

typedef struct
{
    U16 conf_id;                             /* Configuration ID                  */
    S32 doc_hdl;                             /* Configuration document handle     */

    U8 num_profiles;                         /* Num of processed profiles         */
    U8 num_proxy;                            /* Num of processed proxy */    
    U8 iter;                                 /* Used to traverse profiles         */
    U8 num_installed;
    U32 edit_serverid_index;                     /* index of provisioning server id in server id array */
    MMI_BOOL isvalidprof[MAX_SYNCML_DM_PROFILES];   /* Used to place profiles index that are valid */
    mmi_dm_ota_account_struct profile[MAX_SYNCML_DM_PROFILES];
        /* Be a temp storage used to store the settings of the new profile. */    
    mmi_dm_ota_conn_setting_struct *proxy[MAX_SYNCML_DM_PROFILES]; 
        /*Be a temp storage used to store the data of the new proxy.*/

} syncml_dm_ota_context_struct;


MMI_BOOL mmi_dmui_serverid_valid(S8 *p_serverid);

/* set value to DM message struct */
extern void mmi_syncml_dm_set_value(dm_account_struct* ptr_dm_account, mmi_dm_ota_account_struct* ptr_dm_ota);

extern void mmi_syncml_dm_entry_installation(void);

extern void mmi_syncml_dm_next_profile(void);

#endif /* __MMI_SYNCML_DM_OTAP__ */


#endif /* SYNCML_DM_SUPPORT */

#endif /* _DMUIPROT_H */
