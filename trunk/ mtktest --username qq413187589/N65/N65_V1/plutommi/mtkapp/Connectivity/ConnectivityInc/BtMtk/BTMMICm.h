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
 * BTMMICm.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is the header file for BTMMICm.c.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef BT_MMI_CM_H
#define BT_MMI_CM_H

#ifndef _MMI_DATA_TYPE_H
#error "MMIDataType.h should be included"
#endif 

/***************************************************************************** 
* Macro
*****************************************************************************/
#define MMI_BTH_GET_FLAG(x)       ( ((g_mmi_bth_cntx.flag) & x) != 0 ? MMI_TRUE : MMI_FALSE )
#define MMI_BTH_SET_FLAG(x)       ( (g_mmi_bth_cntx.flag) |=  x )
#define MMI_BTH_RESET_FLAG(x)     ( (g_mmi_bth_cntx.flag) &=  ~x )

/* MMI context bit-wise flag operation */
#define MMI_BTH_GET_RAMFLAG(a)       ( ((g_mmi_bth_cntx.ram_flag) & a) != 0 ? MMI_TRUE : MMI_FALSE )
#define MMI_BTH_SET_RAMFLAG(a)       ( (g_mmi_bth_cntx.ram_flag) |=  a )
#define MMI_BTH_RESET_RAMFLAG(a)   ( (g_mmi_bth_cntx.ram_flag) &=  ~a )

#define  MMI_BT_ASSERT( a ) ASSERT( a )

#define MMI_BTH_LOG_STATE_TRANS(x)                                                    \
{                                                                                     \
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_STATE_TRANS, g_mmi_bth_cntx.state, x);\
}

#define MMI_BTH_STATE_TRANS(x)  \
{                               \
    MMI_BTH_LOG_STATE_TRANS(x); \
    g_mmi_bth_cntx.state = x;   \
}

/***************************************************************************** 
* Definations
*****************************************************************************/
#define MMI_BTH_PASSKEY_MAX_LEN                          16
#define MMI_BTH_BD_FNAME_LEN                             47

#define MMI_BTH_MAX_PAIRED_DEVICE_LIST                   10
#define MMI_BTH_MAX_DISCOVERY_RESULTS_IN_LIST            15
/* Configure Default Headset */
#define MMI_BTH_NVRAM_PAD_SIZE                           266
#define MMI_BTH_NUM_OF_PROFILE_UUID                      29

#define MMI_BTH_DISCONNECT_2ND_INCOMING_HFG_TIMER_DUR      4000 /* 4 sec */
#define MMI_BTH_DEACTIVATE_PROHIBITED_PROFILES_TIMER_DUR   1000 /* 1sec */
#define MMI_BTH_ACTIVATE_TIMER_DUR                          500 /* 0.5 sec */

#define MMI_BTH_SPP_PROFILE_UUID                   (0x1101 )
#define MMI_BTH_LAP_PROFILE_UUID                   (0x1102 )
#define MMI_BTH_DUN_PROFILE_UUID                   (0x1103 )
#define MMI_BTH_OBEX_IR_MC_SYNC_SERVICE_UUID       (0x1104 )
#define MMI_BTH_OBEX_OBJECT_PUSH_SERVICE_UUID      (0x1105 )
#define MMI_BTH_OBEX_FILE_TRANSFER_UUID            (0x1106 )
#define MMI_BTH_HS_PROFILE_UUID                    (0x1108 )
#define MMI_BTH_CTP_PROFILE_UUID                   (0x1109 )
#define MMI_BTH_AUDIO_SOURCE_UUID                  (0x110A )
#define MMI_BTH_AUDIO_SINK_UUID                    (0x110B )
#define MMI_BTH_AV_REMOTE_CONTROL_TARGET_UUID      (0x110C )
#define MMI_BTH_ADVANCED_AUDIO_PROFILE_UUID        (0x110D )
#define MMI_BTH_AV_REMOTE_CONTROL_UUID             (0x110E )
#define MMI_BTH_ICP_PROFILE_UUID                   (0x1110 )
#define MMI_BTH_FAX_PROFILE_UUID                   (0x1111 )
#define MMI_BTH_HEADSET_AG_SERVICE_UUID            (0x1112 )
#define MMI_BTH_PAN_PANU_PROFILE_UUID              (0x1115 )
#define MMI_BTH_PAN_NAP_PROFILE_UUID               (0x1116 )
#define MMI_BTH_PAN_GN_PROFILE_UUID                (0x1117 )
#define MMI_BTH_DIRECT_PRINTING                    (0x1118 )
#define MMI_BTH_OBEX_IMAGING_UUID                  (0x111A )
#define MMI_BTH_OBEX_IMAGING_RESPONDER_UUID        (0x111B )
#define MMI_BTH_HF_PROFILE_UUID                    (0x111E )
#define MMI_BTH_HFG_PROFILE_UUID                   (0x111F )
#define MMI_BTH_BASIC_PRINTING                     (0x1122 )
#define MMI_BTH_HID_PROFILE_UUID                   (0x1124 )
#define MMI_BTH_SIM_ACCESS_PROFILE_UUID            (0x112D )
#define MMI_BTH_OBEX_PBA_PROFILE_UUID              (0x1401 )
#define MMI_BTH_OBEX_BPPS_PROFILE_UUID             (0x1118 )
/* used by MMI CM only, cannot be used by profile application */
#define MMI_BTH_OBEX_OBJECT_PUSH_CLIENT_UUID       (0xfffd )
#define MMI_BTH_OBEX_FILE_TRANSFER_CLIENT_UUID     (0xfffe )
#define MMI_BTH_MAX_PROFILE_UUID                   (0xffff )
/* if add new profile UUID, pls also update MM_BCSH_NUM_OF_PROFILE_UUID and profile_id_to_connect_type_map */

#define MMI_BTH_MAX_HSP_NUM_CONNECTION   1
#define MMI_BTH_MAX_HFP_NUM_CONNECTION   1
#define MMI_BTH_MAX_SPP_NUM_CONNECTION   2
#define MMI_BTH_MAX_DUN_NUM_CONNECTION   1
#define MMI_BTH_MAX_OPS_NUM_CONNECTION   2
#define MMI_BTH_MAX_FTS_NUM_CONNECTION   2
#define MMI_BTH_MAX_A2DP_NUM_CONNECTION  1
#define MMI_BTH_MAX_AVRCP_NUM_CONNECTION 1
#define MMI_BTH_MAX_SIMAP_NUM_CONNECTION 1
#define MMI_BTH_MAX_CONNECTION           30
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#define MMI_BTH_MAX_MIC_GAIN                15
#define MMI_BTH_MIN_MIC_GAIN                 0
#define MMI_BTH_MAX_SPK_GAIN                15
#define MMI_BTH_MIN_SPK_GAIN                 0

#define MMI_BTH_SCO_PACKET_TYPE           (HCI_PKT_HV3)

#define MMI_BTH_MAX_HOST_SUPPORTED_PROFILE   23//10

/* MMI BT flag bit-wise flag defination(stored in NVRAM) */
#define MMI_BTH_MASK_GUARD       0x00000001
#define MMI_BTH_MASK_ACTIVATED   0x00000002
#define MMI_BTH_MASK_VIS         0x00000004
#define MMI_BTH_MASK_AUTH        0x00000008
#define MMI_BTH_MASK_AUDPATH     0x00000010     /* 0: Leave in Phone, 1: To Earphone */

/* MMI BT flag bit-wise ram flag defination(Not stored in NVRAM) */
#define MMI_BTH_RAMMASK_IS_SWAP2BT               0x00000001
#define MMI_BTH_RAMMASK_IS_AUTO_PWR_SWTICH       0x00000002
#define MMI_BTH_RAMMASK_IS_READY                 0x00000004
#define MMI_BTH_RAMMASK_IS_ICON_BLINKING         0x00000008
#define MMI_BTH_RAMMASK_FIRST_PAIR_REQ           0x00000010
#define MMI_BTH_RAMMASK_REJECT_PAIR_REQ          0x00000020
#define MMI_BTH_RAMMASK_REACH_MAX_ACL_LINK       0x00000040
#define MMI_BTH_RAMMASK_FORCE_TO_SET_VIS_BE_OFF  0x00000080
#define MMI_BTH_RAMMASK_IS_SIMAP_ACTIVATE        0x00000100


/* MMI BT flag bit-wise flag for service deactivated or not */
#define MMI_BTH_HFP_DEACTIVATED               0x00000001
#define MMI_BTH_HSP_DEACTIVATED               0x00000002
#define MMI_BTH_OPS_DEACTIVATED               0x00000004
#define MMI_BTH_FTS_DEACTIVATED               0x00000008
#define MMI_BTH_SPP_DEACTIVATED               0x00000010
#define MMI_BTH_DUN_DEACTIVATED               0x00000020
#define MMI_BTH_A2DP_DEACTIVATED              0x00000040
#define MMI_BTH_AVRCP_DEACTIVATED             0x00000080
#define MMI_BTH_AVRCP_CT_DEACTIVATED          0x00000100
#define MMI_BTH_FTC_DEACTIVATED               0x00000200
#define MMI_BTH_BPP_DEACTIVATED               0x00000400
#define MMI_BTH_SIMAP_DEACTIVATED             0x00000800
#define MMI_BTH_FAX_DEACTIVATED               0x00001000 
#define MMI_BTH_HIDD_DEACTIVATED              0x00002000 
#define MMI_BTH_BIP_DEACTIVATED               0x00004000 



/* Major Service Mask      */
#define MMI_BTH_OBJECT_TRANSFER_MAJOR_SERVICE_MASK    (0x100000)        /* OBJECT_TRANSFER_MAJOR_SERVICE_MASK */
#define MMI_BTH_AUDIO_MAJOR_SERVICE_MASK              (0x200000)        /* AUDIO_MAJOR_SERVICE_MASK */
#define MMI_BTH_RENDERING_MAJOR_SERVICE_MASK          (0x040000)        /* RENDERING_MAJOR_SERVICE_MASK */
/* Major Device Mask    */
#define MMI_BTH_MISCELLANEOUS_MAJOR_DEVICE_MASK       (0x000000)        /* MISCELLANEOUS_MAJOR_DEVICE_MASK */
#define MMI_BTH_COMPUTER_MAJOR_DEVICE_MASK            (0x000100)        /* COMPUTER_MAJOR_DEVICE_MASK */
#define MMI_BTH_PHONE_MAJOR_DEVICE_MASK               (0x000200)        /* PHONE_MAJOR_DEVICE_MASK */
#define MMI_BTH_AV_MAJOR_DEVICE_MASK                  (0x000400)        /* AV_MAJOR_DEVICE_MASK */
#define MMI_BTH_OBJECT_TRANSFER_MAJOR_SERVICE_MASK    (0x100000)        /* OBJECT_TRANSFER_MAJOR_SERVICE_MASK */

#define MMI_BTH_SEC_MODE0_OFF                   (0x00)
#define MMI_BTH_SEC_MODE1_NON_SECURE            (0x01)
#define MMI_BTH_SEC_MODE2_SERVICE               (0x02)
#define MMI_BTH_SEC_MODE3_LINK                  (0x03)

#define MMI_BTH_SEC_ON                            MMI_BTH_SEC_MODE3_LINK
#define MMI_BTH_SEC_OFF                           MMI_BTH_SEC_MODE1_NON_SECURE

#define MMI_BTH_CONNECTION_ID_OPS_CONNECT       0xFF

/* FuncPtr is a pointer to a func returns void */
/*
 * typedef void (*mmi_bth_func_ptr)(void); 
 * typedef void (*mmi_bth_func_ptr_bt_add)(mmi_bth_bt_addr); 
 * typedef void (*mmi_bth_func_ptr_bt_add_u32)(mmi_bth_bt_addr, U32); 
 */

/***************************************************************************** 
* typedef 
*****************************************************************************/
typedef enum
{
    MMI_BTH_STAT_INIT_ON,
    MMI_BTH_STAT_INIT_OFF,
    MMI_BTH_STAT_DEACTIVATING,
    MMI_BTH_STAT_ACTIVATING,
    MMI_BTH_STAT_ACTIVATING_WRITE_SCAN_ENABLE,
    MMI_BTH_STAT_ACTIVATING_WRITE_SCAN_DISABLE,
    MMI_BTH_STAT_IDLE,
    MMI_BTH_STAT_INQUIRING,
    MMI_BTH_STAT_INQUIR_RES_IND,
    MMI_BTH_STAT_BONDING,
    MMI_BTH_STAT_PAIRING,
    MMI_BTH_STAT_SDC_SEARCHING,
    MMI_BTH_STAT_CONNECTING,
    MMI_BTH_STAT_DEBONDING,
    MMI_BTH_STAT_DEBONDING_ALL,
    MMI_BTH_STAT_DISCONNECTING,
    MMI_BTH_STAT_DISCONNECTING_2ND_HFG,
    MMI_BTH_STAT_AUDIO_CON_ESTAB,
    MMI_BTH_STAT_PASSKEY_IND,
    MMI_BTH_STAT_PASSKEY_RES,
    MMI_BTH_STAT_CONNECT_ACCEPT_CONFIRM_IND,
    MMI_BTH_STAT_SDC_REFRESHING,
    MMI_BTH_STAT_VISIBILITY_SETTING,
    MMI_BTH_STAT_LOCAL_NAME_SETTING,
    MMI_BTH_STAT_AUTHENTICATION_SETTING,
    MMI_BTH_STAT_RELEASE_ALL_CONNECTION,
    MMI_BTH_STAT_RELEASE_DEV_CONNECTION,
    MMI_BTH_STAT_RELEASE_OPP_CONNECTION,
    MMI_BTH_STAT_RELEASE_FTP_CONNECTION,
    MMI_BTH_STAT_RELEASE_SPP_CONNECTION,
    MMI_BTH_STAT_RELEASE_DUN_CONNECTION,
    MMI_BTH_STAT_HFP_DEACTIVATING,
    MMI_BTH_STAT_A2DP_DEACTIVATING,
    MMI_BTH_STAT_PANIC_RECOVERING,
    MMI_BTH_STAT_ACTIVATING_SIMAP,
    MMI_BTH_STAT_DEACTIVATING_SIMAP    
} mmi_bth_state_enum;

typedef enum
{
    MMI_BTH_NO_CONNECTION,
    MMI_BTH_HFP_CONNECTION,
    MMI_BTH_HSP_CONNECTION,
    MMI_BTH_SPP_CONNECTION,
    MMI_BTH_DUN_CONNECTION,
    MMI_BTH_FTP_CONNECTION,
    MMI_BTH_OPP_CONNECTION,
    MMI_BTH_A2DP_CONNECTION,
    MMI_BTH_AVRCP_CONNECTION,
    MMI_BTH_AVRCP_CT_CONNECTION,
    MMI_BTH_BPP_CONNECTION,
    MMI_BTH_SIMAP_CONNECTION, /* Add by stanley*/
    MMI_BTH_FAX_CONNECTION,   /* Add by stanley*/
    MMI_BTH_HID_CONNECTION,  
    MMI_BTH_BIP_CONNECTION,
    MMI_BTH_LAST_CONNECTOIN_TYPE
} mmi_bth_connection_type;

/***************************************************************************** 
* Structure
*****************************************************************************/

typedef struct
{
    U32 lap;    /* Lower Address Part 00..23 */
    U8 uap;     /* upper Address Part 24..31 */
    U16 nap;    /* Non-significant    32..47 */
} mmi_bth_bt_addr;

/* FuncPtr is a pointer to a func returns void */
typedef void (*mmi_bth_func_ptr) (void);
typedef void (*mmi_bth_func_ptr_bt_add) (mmi_bth_bt_addr);
typedef void (*mmi_bth_func_ptr_bt_add_u32) (mmi_bth_bt_addr, U32);
typedef void (*mmi_bth_func_ptr_bt_add_u8) (mmi_bth_bt_addr, U8);
typedef MMI_BOOL (*mmi_bth_func_ptr_addr) (mmi_bth_bt_addr);


typedef struct
{
    U32 cod;
    U8 name[MMI_BTH_BD_FNAME_LEN];
    mmi_bth_bt_addr bd_addr;
    U8 authorise;
    U8 service_list_num;
    U32 service_list[MMI_BTH_MAX_HOST_SUPPORTED_PROFILE];
} mmi_bth_dev_struct;

typedef struct
{
    U32 uuid;
    U32 deactivate_flag;
    mmi_bth_func_ptr activate_func_ptr;
    mmi_bth_func_ptr deactivate_func_ptr;
    mmi_bth_func_ptr_bt_add connect_func_ptr;
    mmi_bth_func_ptr_bt_add_u32 disconnect_func_ptr;
    mmi_bth_func_ptr_bt_add_u32 connect_cnf_res_func_ptr;
    mmi_bth_func_ptr_bt_add_u8 multi_connect_func_ptr;

} mmi_bth_supported_profile_struct;

/* for registering pairing function call */
typedef struct
{
    U32 profile_uuid;
    mmi_bth_func_ptr_addr func_ptr;

} mmi_bth_pairing_permission_struct;

typedef struct
{
    /*  Connection identification  */
    U8 index_of_paried_list;
    U32 conn_id;
    mmi_bth_connection_type conn_type;
    /*  Feature config for hfp and hsp */
    U32 supported_features; /*  Negotiated - valid for current connection  */
    /* mux id for spp and dun */
    U16 mux_id;
    /*  Connection status  */
    U8 speaker_gain;
    U8 mic_gain;
    MMI_BOOL audio_on;
    MMI_BOOL active;

} mmi_bth_connect_struct;

typedef struct
{
    void (*mmi_bt_scr_cb_activate) (MMI_BOOL result);
    void (*mmi_bt_scr_cb_deactivate) (MMI_BOOL result);
    void (*mmi_bt_scr_cb_release_all_conn) (MMI_BOOL result);
    void (*mmi_bt_scr_cb_prohibit_services) (MMI_BOOL result);

    void (*mmi_bt_scr_cb_inquiry) (void);
    void (*mmi_bt_scr_cb_inquiry_cfm) (MMI_BOOL result);
    void (*mmi_bt_scr_cb_inquiry_cancel) (MMI_BOOL result);
    void (*mmi_bt_scr_cb_bond) (void);
    void (*mmi_bt_scr_cb_bond_ind) (MMI_BOOL result);
    void (*mmi_bt_scr_cb_pair) (void);
    void (*mmi_bt_scr_cb_pair_result) (MMI_BOOL result);
    void (*mmi_bt_scr_cb_connect) (U32 conn_type, MMI_BOOL result);
    void (*mmi_bt_scr_cb_connect_accept_cnf_req) (U8 *device_name, U32 uap, U8 lap, U16 nap, U32 conn_id, U32 prof_id);
    void (*mmi_bt_scr_cb_connect_authorise_ind) (U8 *device_name, U32 conn_id, U32 conn_type);
    void (*mmi_bt_scr_cb_disconnect) (U32 conn_type, MMI_BOOL result);
    void (*mmi_bt_scr_cb_refresh_prof_list) (MMI_BOOL result);

    void (*mmi_bt_scr_cb_mydev_connect) (MMI_BOOL result);
    void (*mmi_bt_scr_cb_mydev_rename) (MMI_BOOL result);
    void (*mmi_bt_scr_cb_mydev_auth) (MMI_BOOL result);
    void (*mmi_bt_scr_cb_mydev_del) (MMI_BOOL result);
    void (*mmi_bt_scr_cb_mydev_del_all) (MMI_BOOL result);

    void (*mmi_bt_scr_cb_set_vis) (MMI_BOOL result);
    void (*mmi_bt_scr_cb_set_name) (MMI_BOOL result);
    void (*mmi_bt_scr_cb_set_auth) (MMI_BOOL result);
    void (*mmi_bt_scr_cb_set_aud_pth_2_hf) (MMI_BOOL result);
    void (*mmi_bt_scr_cb_set_simap) (MMI_BOOL result);

    void (*mmi_bt_scr_cb_error) (void);
    void (*mmi_bt_scr_cb_sco_ind) (MMI_BOOL result);
    void (*mmi_bt_scr_cb_panic_ind) (void);

    void (*mmi_bt_scr_cb_display_popup) (U8 *string, U16 imageId, U8 imageOnBottom, U32 popupDuration, U8 toneId);
    void (*mmi_bt_scr_cb_show_progress_scr) (U16 scrid, U16 title, U16 context_id, U16 *context_str,
                                             MMI_BOOL cancel_key, FuncPtr fp);

    void (*mmi_bt_scr_cb_update_status_icon) (void);

} mmi_bt_scr_cb_tbl;

typedef struct
{
    /* bth flag(shall be stored in NVRAM) */
    U32 flag;
    /* bth ram flag(shall not be sotored in NVRAM) */
    U32 ram_flag;
    /* bth service deactivate flag */
    U32 deactivate_flag;
    /* bth a2dp prohibit visibility flag */
    U8 a2dp_prohibit_vis;

    /* bth state */
    mmi_bth_state_enum state;

    /* host Dev Info */
    mmi_bth_dev_struct host_dev;

    /* paired List */
    U8 paired_dev_num;
    mmi_bth_dev_struct paired_list[MMI_BTH_MAX_PAIRED_DEVICE_LIST];
    /* discovery List */
    U8 discovered_dev_num;
    mmi_bth_dev_struct discovered_list[MMI_BTH_MAX_DISCOVERY_RESULTS_IN_LIST];

    /* active connections */
    /* existed_conn is removed by deleting the paired device */
    /* disconnect ind will not remove existed_conn */
    U8 existed_conn_num;
    mmi_bth_connect_struct existed_conn[MMI_BTH_MAX_CONNECTION];

    /* pairing Dev Info */
    U8 action_index;
    mmi_bth_dev_struct pairing_dev;
    U8 *host_name_setting;

    /* connection id of connected 2nd hfg */
    U8 second_hfg_conn_id;
    /* profile id of connect accept confirm */
    U32 conn_cnf_profile_id;
    /* last HID Dev Info */
    U32 idx_of_last_hid_dev;
    /* Configure Default Headset */
    /* last HS Dev Info */
    U32 idx_of_last_hs_dev;

	/* to store the number of service before refreshing service list */
    U8 stored_ser_list_num;

	/* for registering pairing function call */
    /* Register callback */
    /* to check if doing the pairing process or not, if one profile app is doing abort or disconnect, pairing process is not required. */
    /* then BT CM shall reject the pairing directly */
    mmi_bth_pairing_permission_struct pair_permission_cb;

    /* Register event callback function */
    mmi_bt_scr_cb_tbl scr_cb_tbl;


} mmi_bth_cntx_struct;

typedef struct
{
    /* bt flag */
    U32 flag;
    U8 paired_dev_num;
    /* Host Dev Info */
    mmi_bth_dev_struct host_dev;

    /* Paired List */
    mmi_bth_dev_struct paired_list[MMI_BTH_MAX_PAIRED_DEVICE_LIST];

    /* Last HID Dev Info */
    U32 idx_of_last_hid_dev;

    /* Configure Default Headset */
    /* last HS Dev Info */
    U32 idx_of_last_hs_dev;

    U8 padding[MMI_BTH_NVRAM_PAD_SIZE];

} mmi_bth_nvram_struct;

/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/
/* Context access */
extern mmi_bth_cntx_struct g_mmi_bth_cntx;

/***************************************************************************** 
* Functions
*****************************************************************************/
/* */
extern void mmi_bth_init(void);
extern void mmi_bth_init_event_handler(void);

/* misc */
extern void mmi_bth_nvram_reset_info(void);
extern void mmi_bth_nvram_read_info(void);
extern void mmi_bth_nvram_write_info(void);
extern void mmi_bth_init_freshdev_default(U8 *name_p);
extern void mmi_bth_send_msg(U32 dest_module, U32 sap_id, U32 msg_id, void *p_local_para, void *p_peer_buff);

extern void mmi_bth_antenna_on_req_hdler(void);
extern void mmi_bth_antenna_on_rsp_hdler(void *msg);
extern void mmi_bth_antenna_off_req_hdler(void);
extern void mmi_bth_antenna_off_rsp_hdler(void *msg);
extern void mmi_bth_ready_ind_hdler(void *msg);
extern void mmi_bth_restart_req_ind_hdler(void *msg);
extern void mmi_bth_restart_rsp_hdler(void *msg);

extern void mmi_bth_cm_discovery_req_hdler(U8 max_response, U16 timeout, U32 cod, MMI_BOOL name_discovery);
extern void mmi_bth_cm_discovery_result_ind_hdler(void *msg);
extern void mmi_bth_cm_discovery_cnf_hdler(void *msg);
extern void mmi_bth_cm_cancel_discovery_req_hdler(void);
extern void mmi_bth_cm_cancel_discovery_cnf_hdler(void *msg);
extern void mmi_bth_cm_set_local_name_req_hdler(U8 name_len, U8 *name);
extern void mmi_bth_cm_set_local_name_cnf_hdler(void *msg);
extern void mmi_bth_cm_read_local_bd_addr_req_hdler(void);
extern void mmi_bth_cm_read_local_bd_addr_cnf_hdler(void *msg);
extern void mmi_bth_cm_read_remote_name_req_hdler(mmi_bth_bt_addr bt_add);
extern void mmi_bth_cm_read_remote_name_cnf_hdler(void *msg);
extern void mmi_bth_cm_sdc_search_req_hdler(mmi_bth_bt_addr bt_add, U8 sdap_len, U16 *sdap_uuid);
extern void mmi_bth_cm_sdc_search_ind_hdler(void *msg);
extern void mmi_bth_cm_sdc_search_cnf_hdler(void *msg);
extern void mmi_bth_cm_link_connect_accept_ind_hdler(void *msg);
extern void mmi_bth_cm_bond_req_hdler(mmi_bth_bt_addr bt_add, U8 sdap_len, U16 *sdap_uuid);
extern void mmi_bth_cm_bond_ind_hdler(void *msg);
extern void mmi_bth_cm_bond_cnf_hdler(void *msg);
extern void mmi_bth_cm_debond_req_hdler(mmi_bth_bt_addr bt_add);
extern void mmi_bth_cm_debond_cnf_hdler(void *msg);
extern void mmi_bth_cm_passkey_ind_hdler(void *msg);
extern void mmi_bth_cm_passkey_ind_rsp_hdler(mmi_bth_bt_addr bt_add, U8 pin_len, U8* pin_code);
extern void mmi_bth_cm_security_level_req_hdler(MMI_BOOL auth_flag);
extern void mmi_bth_cm_security_level_cnf_hdler(void *msg);
extern void mmi_bth_cm_write_scanenable_mode_req_hdler(U8 connected_mode, U8 non_connected_mode);
extern void mmi_bth_cm_write_scanenable_mode_cnf_hdler(void *msg);
extern void mmi_bth_cm_link_state_ind_hdler(void *msg);
extern void mmi_bth_cm_allow_acl_link_establishment_req_hdler(void);
extern void mmi_bth_cm_allow_acl_link_establishment_cnf_hdler(void *msg);
extern void mmi_bth_cm_disallow_acl_link_establishment_req_hdler(void);
extern void mmi_bth_cm_disallow_acl_link_establishment_cnf_hdler(void *msg);
extern void mmi_bth_cm_sdpdb_register_cnf_hdler(void *msg);
extern void mmi_bth_cm_sdpdb_deregister_cnf_hdler(void *msg);



/* stack functions for scr */
extern MMI_BOOL mmi_bth_is_activated(void);
extern MMI_BOOL mmi_bth_is_panic(void);
extern MMI_BOOL mmi_bth_is_vis(void);
extern MMI_BOOL mmi_bth_is_auth(void);
extern MMI_BOOL mmi_bth_is_aud_pth_set_to_hf(void);
extern MMI_BOOL mmi_bth_is_incall_aud_swap2bt(void);
extern MMI_BOOL mmi_bth_is_hs_connected(void);
extern MMI_BOOL mmi_bth_is_hs_audio_link_connected(void);
extern MMI_BOOL mmi_bth_is_hsp_connected(void);
extern MMI_BOOL mmi_bth_is_hfp_connected(void);
extern MMI_BOOL mmi_bth_is_any_connection_active(void);
extern MMI_BOOL mmi_bth_is_connection_active(mmi_bth_bt_addr *dev_add_p);
extern MMI_BOOL mmi_bth_is_simap_activate(void);
/* Configure Default Headset */
extern MMI_BOOL mmi_bth_is_service_support(U32 paired_index, U32 service_id);

extern mmi_bth_state_enum mmi_bth_get_state(void);
extern mmi_bth_dev_struct *mmi_bth_get_host_dev_info(void);
extern U8 mmi_bth_get_discov_dev_num(void);
extern mmi_bth_dev_struct *mmi_bth_get_discov_dev_info(U16 index);
extern U8 mmi_bth_get_paired_dev_num(void);
extern mmi_bth_dev_struct *mmi_bth_get_paired_dev_info(U16 index);
extern U8 mmi_bth_get_existed_dev_num(void);
extern mmi_bth_dev_struct *mmi_bth_get_existed_dev_info(U16 index);
extern mmi_bth_connect_struct *mmi_bth_get_existed_connect_info(U16 index);
extern U8 mmi_bth_get_action_item_index(void);
extern U32 mmi_bth_get_ram_flag(U32);
/* Configure Default Headset */
extern U32 mmi_bth_get_default_hs_index(void);

extern U8 mmi_bth_get_active_hfp_connect_id(void);
extern MMI_BOOL mmi_bth_get_sco_status(U32 conn_id);

extern MMI_BOOL mmi_bth_antenna_off_req(void);
extern MMI_BOOL mmi_bth_antenna_on_req(void);
extern MMI_BOOL mmi_bth_restart_bt_module_req(void);
extern MMI_BOOL mmi_bth_recover_panic_req(void);
extern MMI_BOOL mmi_bth_deactivate_req(void);
extern void mmi_bth_deactivate_profiles_req(void);
extern MMI_BOOL mmi_bth_activate_req(void);
extern void mmi_bth_activate_profiles_req(void);
extern MMI_BOOL mmi_bth_release_all_connection_req(void);
extern MMI_BOOL mmi_bth_release_dev_connection_req(mmi_bth_bt_addr *);
extern MMI_BOOL mmi_bth_inquiry_req(U8 max_response, U16 timeout, U32 cod, MMI_BOOL name_discovery, U8 inquiry_type);
extern MMI_BOOL mmi_bth_inquiry_cancel_req(U8 inquiry_type);
extern MMI_BOOL mmi_bth_bond_req(U32);
extern MMI_BOOL mmi_bth_pair_req(mmi_bth_bt_addr *dev_addr, U8 *dev_passkey, MMI_BOOL result);
extern MMI_BOOL mmi_bth_refresh_service_list_req(mmi_bth_bt_addr *dev_addr);
extern MMI_BOOL mmi_bth_connect_req(mmi_bth_bt_addr *dev_addr, U32 profile_id);
extern MMI_BOOL mmi_bth_connect_accept_cnf_res(mmi_bth_bt_addr *dev_addr, U32 pro_uuid, MMI_BOOL result);
extern MMI_BOOL mmi_bth_disconnect_req(U32 connection_id, mmi_bth_connection_type conn_type);
extern MMI_BOOL mmi_bth_mydev_connect_req(U32);
extern MMI_BOOL mmi_bth_mydev_rename_req(U32);
extern MMI_BOOL mmi_bth_mydev_authorise_req(U32, U32 pro_uuid);
extern MMI_BOOL mmi_bth_mydev_del_req(mmi_bth_bt_addr *dev_addr);
extern MMI_BOOL mmi_bth_mydev_del_all_req(void);
extern MMI_BOOL mmi_bth_mydev_add_req(mmi_bth_bt_addr *dev_add_p);
extern MMI_BOOL mmi_bth_mydev_remove_req(mmi_bth_bt_addr *dev_add_p);
extern MMI_BOOL mmi_bth_set_vis_req(MMI_BOOL vis);
extern MMI_BOOL mmi_bth_set_connectable_req(MMI_BOOL connectable);
extern MMI_BOOL mmi_bth_set_name_req(U8 *name);
extern MMI_BOOL mmi_bth_set_auth_req(MMI_BOOL);
extern MMI_BOOL mmi_bth_set_simap_req(MMI_BOOL);
extern MMI_BOOL mmi_bth_set_aud_pth_2_hf(MMI_BOOL);
extern MMI_BOOL mmi_bth_set_ram_flag(U32 set_flag);
extern MMI_BOOL mmi_bth_reset_ram_flag(U32 set_flag);
extern MMI_BOOL mmi_bth_set_flag(U32 set_flag);
extern MMI_BOOL mmi_bth_reset_flag(U32 set_flag);
extern MMI_BOOL mmi_bth_set_state(U32 set_state);
extern MMI_BOOL mmi_bth_set_headset_speaker_gain_req(U8 speaker_gain, U32 conn_id);
/* Configure Default Headset */
extern MMI_BOOL mmi_bth_set_default_hs_index(U32 paired_index);

extern MMI_BOOL mmi_bth_hfp_sco_connect_req(void);
extern MMI_BOOL mmi_bth_hfp_sco_disconnect_req(void);
/* Configure Default Headset */
extern MMI_BOOL mmi_bth_connect_last_headset_req(void);

extern MMI_BOOL mmi_bth_turn_on_speech_req(MMI_BOOL speech_on);
extern void mmi_bth_pwroff(void);
extern U8 mmi_bth_switch_voice_path_incall(MMI_BOOL is_on);
extern void mmi_bth_test_l1sp_bt_off(void);

extern void mmi_bth_reset_hfp_module(void);
extern void mmi_bth_reset_a2dp_module(void);
extern MMI_BOOL mmi_bth_prohibit_opp_req(void);
extern MMI_BOOL mmi_bth_prohibit_ftp_req(void);
extern MMI_BOOL mmi_bth_prohibit_spp_req(void);
extern MMI_BOOL mmi_bth_prohibit_dun_req(void);
extern void mmi_bth_permit_opp_req(void);
extern void mmi_bth_permit_ftp_req(void);
extern void mmi_bth_permit_spp_req(void);
extern void mmi_bth_permit_dun_req(void);

extern void mmi_bth_profile_callback_before_release_connection_hdler(
                U32 lap,
                U8 uap,
                U16 nap,
                U32 profile_id,
                U32 connection_id);

/* misc */
extern mmi_bth_connection_type mmi_bth_get_connection_type(U32);
extern MMI_BOOL mmi_bth_is_all_supported_profiles_activated(void);
extern MMI_BOOL mmi_bth_is_all_supported_profiles_deactivated(void);
extern void mmi_bth_set_deactivate_flag(U32 prof_flag);
extern void mmi_bth_reset_deactivate_flag(U32 prof_flag);
extern void mmi_bth_deactivate_spp(void);
extern void mmi_bth_deactivate_dun(void);
extern void mmi_bth_deactivate_ops(void);
extern void mmi_bth_deactivate_fts(void);
extern void mmi_bth_get_active_a2dp_infor(U32 profile_id, U32 *lap, U8 *uap, U16 *nap, U32 *connection_id);
extern void mmi_bth_close_sdc_req(void);
/* for registering pairing function call */
extern MMI_BOOL mmi_bth_is_pairing_permitted(mmi_bth_bt_addr dev_addr);

#endif /* BT_MMI_CM_H */ /* end of BT_MMI_CM_H */

