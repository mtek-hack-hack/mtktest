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
 * BTMMICM.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is for MTK bluetooth application.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifdef __MMI_BT_MTK_SUPPORT__
/***************************************************************************** 
* Included files
*****************************************************************************/
#include "ProtocolEvents.h"
#include "CommonScreens.h"
#include "IdleAppProt.h"
#include "gpioInc.h"

/* MMI Nvram access */

/* Trace Header Files */

/* kal adapter */

/* bm header files */
#include "bluetooth_bm_struct.h"

/* cm header files */
#include "btmmicm.h"

/* External Device Header Files */
#include "ExtDeviceDefs.h"

/* HFP */
#ifdef __MMI_HFP_SUPPORT__
#include "BTMMIHFPGprots.h"
/* HSP */
#include "BTMMIHSPGprots.h"
#endif

/* SPP */
#ifdef __MMI_SPP_SUPPORT__
#include "BTMMISppGprots.h"
#endif

/* DUN */
#ifdef __MMI_DUN_SUPPORT__
#include "BTMMIDUNGprots.h"
#endif

/* FTP */
#if defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__)
#include "BTMMIFtpGprots.h"
#endif

/* OPP */
#if defined(__MMI_OPP_SUPPORT__)
#include "BTMMIOppGprots.h"
#endif

/* BPP */
#if defined(__MMI_BPP_SUPPORT__)
#include "BTMMIBppGprot.h"
#endif

/* BIP */
#ifdef __MMI_BIP_SUPPORT__
#include "BTMMIBipGprot.h"
#endif

/* A2DP */
#ifdef __MMI_A2DP_SUPPORT__
#include "BTMMIA2DP.h"
#endif

/* AVRCP */
#if defined(__MMI_AVRCP_SUPPORT__) || defined(__MMI_AVRCP_CT_SUPPORT__)
#include "BTMMIAVRCPGprot.h"
#endif

/* SIM Access Profile */
#ifdef __MMI_SIMAP_SUPPORT__
#include "BTMMISIMAPGprots.h"
#endif

/* Fax Profile */
#ifdef __MMI_FAX_SUPPORT__
#include "BTMMIFaxGprots.h"
#endif

/* HIDD Profile */
#ifdef __MMI_HIDD_SUPPORT__
#include "BTMMIHiddGprots.h"
#endif


/* MMI BT profile related files */
#ifdef __MMI_BT_PROFILE__
#include "ProfilesDefs.h"
#include "ProfileGprots.h"
#endif /* __MMI_BT_PROFILE__ */ 

/* Call Management related API */
#include "CallManagementStruct.h"
#include "CallManagementGprot.h"

/* filght mode related API */
#include "FlightModeGProt.h"

#ifdef __GEMINI__
#include "PhoneSetupGprots.h"
#endif
/***************************************************************************** 
* External Variable
*****************************************************************************/

/***************************************************************************** 
* Globol Variable
*****************************************************************************/
mmi_bth_cntx_struct g_mmi_bth_cntx;

const U8 MMI_BT_DEF_HOST_BT_NAME[] = { 'M', 'T', 'K', 'B', 'T', 'D', 'E', 'V', 'I', 'C', 'E', '\0' };

const U16 profile_id_to_connect_type_map[MMI_BTH_NUM_OF_PROFILE_UUID][2] = 
{
    {MMI_BTH_HF_PROFILE_UUID, MMI_BTH_HFP_CONNECTION},
    {MMI_BTH_HFG_PROFILE_UUID, MMI_BTH_HFP_CONNECTION},
    {MMI_BTH_HS_PROFILE_UUID, MMI_BTH_HSP_CONNECTION},
    {MMI_BTH_HEADSET_AG_SERVICE_UUID, MMI_BTH_HSP_CONNECTION},
    {MMI_BTH_DUN_PROFILE_UUID, MMI_BTH_DUN_CONNECTION},
    {MMI_BTH_SPP_PROFILE_UUID, MMI_BTH_SPP_CONNECTION},
    {MMI_BTH_LAP_PROFILE_UUID, MMI_BTH_NO_CONNECTION},
    {MMI_BTH_OBEX_IR_MC_SYNC_SERVICE_UUID, MMI_BTH_NO_CONNECTION},
    {MMI_BTH_OBEX_OBJECT_PUSH_SERVICE_UUID, MMI_BTH_OPP_CONNECTION},
    {MMI_BTH_OBEX_FILE_TRANSFER_UUID, MMI_BTH_FTP_CONNECTION},
    {MMI_BTH_CTP_PROFILE_UUID, MMI_BTH_NO_CONNECTION},
    {MMI_BTH_AUDIO_SOURCE_UUID, MMI_BTH_NO_CONNECTION},
    {MMI_BTH_AUDIO_SINK_UUID, MMI_BTH_NO_CONNECTION},
    {MMI_BTH_AV_REMOTE_CONTROL_TARGET_UUID, MMI_BTH_AVRCP_CONNECTION},
    {MMI_BTH_ADVANCED_AUDIO_PROFILE_UUID, MMI_BTH_A2DP_CONNECTION},
    {MMI_BTH_AV_REMOTE_CONTROL_UUID, MMI_BTH_AVRCP_CT_CONNECTION},
    {MMI_BTH_ICP_PROFILE_UUID, MMI_BTH_NO_CONNECTION},
    {MMI_BTH_FAX_PROFILE_UUID, MMI_BTH_FAX_CONNECTION}, 
    {MMI_BTH_PAN_PANU_PROFILE_UUID, MMI_BTH_NO_CONNECTION},
    {MMI_BTH_PAN_NAP_PROFILE_UUID, MMI_BTH_NO_CONNECTION},
    {MMI_BTH_PAN_GN_PROFILE_UUID, MMI_BTH_NO_CONNECTION},
    {MMI_BTH_DIRECT_PRINTING, MMI_BTH_NO_CONNECTION},
    {MMI_BTH_OBEX_IMAGING_UUID, MMI_BTH_BIP_CONNECTION},
    {MMI_BTH_OBEX_IMAGING_RESPONDER_UUID, MMI_BTH_BIP_CONNECTION},
    {MMI_BTH_BASIC_PRINTING, MMI_BTH_BPP_CONNECTION},
    {MMI_BTH_HID_PROFILE_UUID, MMI_BTH_HID_CONNECTION},
    {MMI_BTH_SIM_ACCESS_PROFILE_UUID, MMI_BTH_SIMAP_CONNECTION},
    {MMI_BTH_OBEX_PBA_PROFILE_UUID, MMI_BTH_NO_CONNECTION},
    {MMI_BTH_OBEX_BPPS_PROFILE_UUID, MMI_BTH_BPP_CONNECTION}
};

const mmi_bth_supported_profile_struct support_profile_tbl[] = 
{
#ifdef __MMI_HFP_SUPPORT__
    {MMI_BTH_HFG_PROFILE_UUID, MMI_BTH_HFP_DEACTIVATED,
     mmi_bth_hfg_activate_req_hdler,
     mmi_bth_hfg_deactivate_req_hdler,
     mmi_bth_hfg_connect_req_hdler,
     mmi_bth_hfg_disconnect_req_hdler,
     NULL,
     NULL},
#endif /* __MMI_HFP_SUPPORT__ */ 
 #ifdef __MMI_HSP_SUPPORT__
    {MMI_BTH_HEADSET_AG_SERVICE_UUID, MMI_BTH_HSP_DEACTIVATED,
     mmi_bth_hsg_activate_req_hdler,
     mmi_bth_hsg_deactivate_req_hdler,
     mmi_bth_hsg_connect_req_hdler,
     mmi_bth_hsg_disconnect_req_hdler,
     NULL,
     NULL},
 #endif /* __MMI_HSP_SUPPORT__ */ 
 #ifdef __MMI_SPP_SUPPORT__
    {MMI_BTH_SPP_PROFILE_UUID, MMI_BTH_SPP_DEACTIVATED,
     mmi_bth_spp_activate_req_hdler,
     mmi_bth_spp_deactivate_req_hdler,
     NULL,
     mmi_bth_spp_disconnect_req_hdler,
     NULL,
     NULL},
 #endif /* __MMI_SPP_SUPPORT__ */ 
 #ifdef __MMI_DUN_SUPPORT__
    {MMI_BTH_DUN_PROFILE_UUID, MMI_BTH_DUN_DEACTIVATED,
     mmi_bth_dun_activate_req_hdler,
     mmi_bth_dun_deactivate_req_hdler,
     NULL,
     mmi_bth_dun_disconnect_req_hdler,
     NULL,
     NULL},
 #endif /* __MMI_DUN_SUPPORT__ */ 
 #ifdef __MMI_OPP_SUPPORT__
    {MMI_BTH_OBEX_OBJECT_PUSH_SERVICE_UUID, MMI_BTH_OPS_DEACTIVATED,
     mmi_bt_opps_activate, 
     mmi_bt_opps_deactivate, 
     NULL, 
     mmi_bt_opps_disconnect_client, 
     NULL,
     NULL},
 #endif /* __MMI_OPP_SUPPORT__ */ 
 #ifdef __MMI_FTS_SUPPORT__
    {MMI_BTH_OBEX_FILE_TRANSFER_UUID, MMI_BTH_FTS_DEACTIVATED,
     mmi_bt_ftps_activate,
     mmi_bt_ftps_deactivate,
     NULL,
     mmi_bt_ftps_disconnect_client,
     NULL,
     NULL},
 #endif /* __MMI_FTS_SUPPORT__ */ 
 #ifdef __MMI_FTC_SUPPORT__
    {MMI_BTH_OBEX_FILE_TRANSFER_CLIENT_UUID, MMI_BTH_FTC_DEACTIVATED,
     NULL,
     NULL, 
     NULL, 
     NULL, 
     NULL,
     mmi_bt_ftpc_connect_server},
 #endif /* __MMI_FTC_SUPPORT__ */ 
 #ifdef __MMI_A2DP_SUPPORT__
    {MMI_BTH_ADVANCED_AUDIO_PROFILE_UUID, MMI_BTH_A2DP_DEACTIVATED,
     mmi_bt_a2dp_activate_req,
     mmi_bt_a2dp_deactivate_req,
     mmi_bt_a2dp_connect_req_by_cm,
     mmi_bt_a2dp_disconnect_req_by_cm,
     NULL,
     NULL},
 #endif /* __MMI_A2DP_SUPPORT__ */ 
 #ifdef __MMI_AVRCP_SUPPORT__
    {MMI_BTH_AV_REMOTE_CONTROL_TARGET_UUID, MMI_BTH_AVRCP_DEACTIVATED,
     mmi_bt_avrcp_activate_tg_req,
     mmi_bt_avrcp_deactivate_tg_req,
     mmi_bt_avrcp_connect_tg_req,
     mmi_bt_avrcp_disconnect_tg_req,
     NULL,
     NULL},
 #endif /* __MMI_AVRCP_SUPPORT__ */ 
 #ifdef __MMI_AVRCP_CT_SUPPORT__
    {MMI_BTH_AV_REMOTE_CONTROL_UUID, MMI_BTH_AVRCP_CT_DEACTIVATED,
     mmi_bt_avrcp_activate_ct_req,
     mmi_bt_avrcp_deactivate_ct_req,
     mmi_bt_avrcp_connect_ct_req,
     mmi_bt_avrcp_disconnect_ct_req,
     NULL,
     NULL},
 #endif /* __MMI_AVRCP_CT_SUPPORT__ */ 

 #ifdef __MMI_BPP_SUPPORT__
    {MMI_BTH_BASIC_PRINTING, MMI_BTH_BPP_DEACTIVATED,
     NULL,
     NULL,
     mmi_bt_bpp_connect_printer,
     mmi_bt_bpp_disconnect_printer, 
     NULL,
     NULL},
 #endif /* __MMI_BPP_SUPPORT__ */ 
 
 #ifdef __MMI_SIMAP_SUPPORT__
    {MMI_BTH_SIM_ACCESS_PROFILE_UUID, MMI_BTH_SIMAP_DEACTIVATED,
     NULL,/*mmi_bth_simap_activate_req_hdler*//* activated by bt setting menu */
     NULL,/*mmi_bth_simap_deactivate_req_hdler*//* deactivated by bt setting menu */
     NULL,
     mmi_bth_simap_disconnect_req_hdler,
     NULL,
     NULL},
 #endif /* __MMI_SIMAP_SUPPORT__*/

 #ifdef __MMI_FAX_SUPPORT__
    {MMI_BTH_FAX_PROFILE_UUID, MMI_BTH_FAX_DEACTIVATED,
     mmi_bth_fax_activate_req_hdler,
     mmi_bth_fax_deactivate_req_hdler,
     NULL,
     mmi_bth_fax_disconnect_req_hdler,
     NULL,
     NULL},
 #endif /* __MMI_FAX_SUPPORT__ : Add by stanley: 2006-11-24 */

 #ifdef __MMI_HIDD_SUPPORT__
    {MMI_BTH_HID_PROFILE_UUID, MMI_BTH_HIDD_DEACTIVATED,
     mmi_bth_hidd_activate_req_hdler,
     mmi_bth_hidd_deactivate_req_hdler,
     mmi_bth_hidd_connect_req_hdler,
     mmi_bth_hidd_disconnect_req_hdler,
     mmi_bth_hidd_connection_authorize_rsp_hdler,
     NULL},
 #endif /* __MMI_HIDD_SUPPORT__ */ 

 /* BIP */
 #ifdef __MMI_BIP_SUPPORT__
    {MMI_BTH_OBEX_IMAGING_RESPONDER_UUID, MMI_BTH_BIP_DEACTIVATED,
     mmi_bt_bipr_activate,
     mmi_bt_bipr_deactivate,
     NULL,
     mmi_bt_bipr_disconnect_client,
     NULL,
     NULL},

     {MMI_BTH_OBEX_IMAGING_UUID, MMI_BTH_BIP_DEACTIVATED,
      NULL,
      NULL, 
      mmi_bt_bipi_connect_pull_responder,
      NULL, 
      NULL, 
      NULL
      },
 #endif /* __MMI_BIP_SUPPORT__ */ 

    {MMI_BTH_MAX_PROFILE_UUID, 0, NULL, NULL, NULL, NULL, NULL, NULL}
};

const U32 inquiry_profile_tbl[] = 
{
#ifdef __MMI_HSP_SUPPORT__
    {MMI_BTH_HS_PROFILE_UUID},
#endif 
#ifdef __MMI_HFP_SUPPORT__
    {MMI_BTH_HF_PROFILE_UUID},
#endif 
#ifdef __MMI_SPP_SUPPORT__
    {MMI_BTH_SPP_PROFILE_UUID},
#endif 
#ifdef __MMI_DUN_SUPPORT__
    {MMI_BTH_DUN_PROFILE_UUID},
#endif 
#ifdef __MMI_OPP_SUPPORT__
    {MMI_BTH_OBEX_OBJECT_PUSH_SERVICE_UUID},
#endif 
#ifdef __MMI_FTS_SUPPORT__
    {MMI_BTH_OBEX_FILE_TRANSFER_UUID},
#endif 
#ifdef __MMI_A2DP_SUPPORT__
    { /* MMI_BTH_ADVANCED_AUDIO_PROFILE_UUID */ MMI_BTH_AUDIO_SINK_UUID},
#endif
#ifdef __MMI_AVRCP_CT_SUPPORT__
    { MMI_BTH_AV_REMOTE_CONTROL_TARGET_UUID},
#endif
#ifdef __MMI_BPP_SUPPORT__
        {MMI_BTH_OBEX_BPPS_PROFILE_UUID},
#endif 
#ifdef __MMI_SIMAP_SUPPORT__
    {MMI_BTH_SIM_ACCESS_PROFILE_UUID},
#endif 
#ifdef __MMI_FAX_SUPPORT__
    {MMI_BTH_FAX_PROFILE_UUID}, /* Add by stanley:2006-11-24 */ 
#endif 
#ifdef __MMI_HIDD_SUPPORT__
        {MMI_BTH_HID_PROFILE_UUID},
#endif 
#ifdef __MMI_BIP_SUPPORT__
        {MMI_BTH_OBEX_IMAGING_RESPONDER_UUID},
#endif 


    {MMI_BTH_MAX_PROFILE_UUID}
};

/***************************************************************************** 
* External Functions
*****************************************************************************/

/***************************************************************************** 
* Functions
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_init
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_mmi_bth_cntx, 0, sizeof(mmi_bth_cntx_struct));
    mmi_bth_nvram_read_info();
    mmi_bth_init_event_handler();

    /* Guard flag is not set, fresh devie first time power on or data corrupted */
    if (MMI_BTH_GET_FLAG(MMI_BTH_MASK_GUARD) == MMI_FALSE)
    {
        memset(&g_mmi_bth_cntx, 0, sizeof(mmi_bth_cntx_struct));
        mmi_bth_init_freshdev_default((U8*) MMI_BT_DEF_HOST_BT_NAME);
        /* set default audio path to earphone */
        MMI_BTH_SET_FLAG(MMI_BTH_MASK_AUDPATH);
        /* set default visibility to be on */
        MMI_BTH_SET_FLAG(MMI_BTH_MASK_VIS);
        /* set default authentication to be on */
        MMI_BTH_SET_FLAG(MMI_BTH_MASK_AUTH);
        MMI_BTH_SET_FLAG(MMI_BTH_MASK_GUARD);
        /* set default idx of last hid device to be 0xFFFFFFFF */
        g_mmi_bth_cntx.idx_of_last_hid_dev = 0xFFFFFFFF;

        /* Configure Default Headset */
        g_mmi_bth_cntx.idx_of_last_hs_dev = 0xFFFFFFFF;

        mmi_bth_nvram_write_info();
    }

	/* update the supported service list of host phone */
    while (support_profile_tbl[i].uuid != MMI_BTH_MAX_PROFILE_UUID)
    {
        g_mmi_bth_cntx.host_dev.service_list[i] = support_profile_tbl[i].uuid;
        i++;
    }
    g_mmi_bth_cntx.host_dev.service_list_num = i;
    mmi_bth_nvram_write_info();

    /* init supported HFG features */
    /* config it in BtConfig.h and HFG.h or override.h */

    /* init deactivate flag */
    g_mmi_bth_cntx.deactivate_flag = 0xffffffff;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_init_event_handler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_init_event_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_INIT_EVENT_HDLR);

    /* Init protocol event handler */
    SetProtocolEventHandler(mmi_bth_antenna_off_rsp_hdler, MSG_ID_BT_POWEROFF_CNF);
    SetProtocolEventHandler(mmi_bth_antenna_on_rsp_hdler, MSG_ID_BT_POWERON_CNF);
    SetProtocolEventHandler(mmi_bth_ready_ind_hdler, MSG_ID_BT_READY_IND);
    SetProtocolEventHandler(mmi_bth_cm_allow_acl_link_establishment_cnf_hdler, MSG_ID_BT_BM_LINK_ALLOW_CNF);
    SetProtocolEventHandler(mmi_bth_cm_disallow_acl_link_establishment_cnf_hdler, MSG_ID_BT_BM_LINK_DISALLOW_CNF);

    SetProtocolEventHandler(mmi_bth_restart_req_ind_hdler, MSG_ID_BT_RESET_REQ_IND);
    SetProtocolEventHandler(mmi_bth_restart_rsp_hdler, MSG_ID_BT_MMI_RESET_CNF);

    SetProtocolEventHandler(mmi_bth_cm_discovery_result_ind_hdler, MSG_ID_BT_BM_DISCOVERY_RESULT_IND);
    SetProtocolEventHandler(mmi_bth_cm_discovery_cnf_hdler, MSG_ID_BT_BM_DISCOVERY_CNF);
    SetProtocolEventHandler(mmi_bth_cm_cancel_discovery_cnf_hdler, MSG_ID_BT_BM_DISCOVERY_CANCEL_CNF);
    SetProtocolEventHandler(mmi_bth_cm_set_local_name_cnf_hdler, MSG_ID_BT_BM_WRITE_LOCAL_NAME_CNF);
    SetProtocolEventHandler(mmi_bth_cm_read_local_bd_addr_cnf_hdler, MSG_ID_BT_BM_READ_LOCAL_ADDR_CNF);
    SetProtocolEventHandler(mmi_bth_cm_read_remote_name_cnf_hdler, MSG_ID_BT_BM_READ_REMOTE_NAME_CNF);
    SetProtocolEventHandler(mmi_bth_cm_sdc_search_ind_hdler, MSG_ID_BT_BM_SERVICE_SEARCH_RESULT_IND);
    SetProtocolEventHandler(mmi_bth_cm_sdc_search_cnf_hdler, MSG_ID_BT_BM_SERVICE_SEARCH_CNF);
    SetProtocolEventHandler(mmi_bth_cm_link_connect_accept_ind_hdler, MSG_ID_BT_BM_LINK_CONNECT_ACCEPT_IND);

    SetProtocolEventHandler(mmi_bth_cm_bond_ind_hdler, MSG_ID_BT_BM_BONDING_RESULT_IND);
    SetProtocolEventHandler(mmi_bth_cm_bond_cnf_hdler, MSG_ID_BT_BM_BONDING_CNF);
    SetProtocolEventHandler(mmi_bth_cm_debond_cnf_hdler, MSG_ID_BT_BM_DELETE_TRUST_CNF);
    SetProtocolEventHandler(mmi_bth_cm_passkey_ind_hdler, MSG_ID_BT_BM_PIN_CODE_IND);
    SetProtocolEventHandler(mmi_bth_cm_security_level_cnf_hdler, MSG_ID_BT_BM_WRITE_AUTHENTICATION_MODE_CNF);
    SetProtocolEventHandler(mmi_bth_cm_write_scanenable_mode_cnf_hdler, MSG_ID_BT_BM_WRITE_SCANENABLE_MODE_CNF);
    SetProtocolEventHandler(mmi_bth_cm_link_state_ind_hdler, MSG_ID_BT_BM_LINK_STATE_IND);


    SetProtocolEventHandler(mmi_bth_cm_sdpdb_register_cnf_hdler, MSG_ID_BT_SDPDB_REGISTER_CNF);
    SetProtocolEventHandler(mmi_bth_cm_sdpdb_deregister_cnf_hdler, MSG_ID_BT_SDPDB_DEREGISTER_CNF);

	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_nvram_reset_info
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_nvram_reset_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bth_nvram_struct write_struct;
    S16 err;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BT_ASSERT(NVRAM_EF_BT_INFO_SIZE == sizeof(mmi_bth_nvram_struct));

    memset(&write_struct, 0, NVRAM_EF_BT_INFO_SIZE);

    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_NVR_WRITE, write_struct.flag, write_struct.paired_dev_num);

    WriteRecord(NVRAM_EF_BT_INFO_LID, 1, &write_struct, NVRAM_EF_BT_INFO_SIZE, &err);
    if (err != NVRAM_WRITE_SUCCESS)
    {
        MMI_BT_ASSERT(MMI_FALSE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_nvram_read_info
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_nvram_read_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bth_nvram_struct read_struct;
    S16 err = 0, bth_nvram_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bth_nvram_size = sizeof(mmi_bth_nvram_struct);
    if (bth_nvram_size != NVRAM_EF_BT_INFO_SIZE)
    {
        MMI_BT_ASSERT(0);
    }
    MMI_BT_ASSERT(NVRAM_EF_BT_INFO_SIZE == bth_nvram_size);

    ReadRecord(NVRAM_EF_BT_INFO_LID, 1, &read_struct, NVRAM_EF_BT_INFO_SIZE, &err);
    if (err == NVRAM_READ_SUCCESS)
    {
        g_mmi_bth_cntx.flag = read_struct.flag;
        g_mmi_bth_cntx.paired_dev_num = read_struct.paired_dev_num;
        g_mmi_bth_cntx.idx_of_last_hid_dev = read_struct.idx_of_last_hid_dev;
        /* Configure Default Headset */
        g_mmi_bth_cntx.idx_of_last_hs_dev = read_struct.idx_of_last_hs_dev;


        memcpy(
            g_mmi_bth_cntx.paired_list,
            read_struct.paired_list,
            sizeof(mmi_bth_dev_struct) * (g_mmi_bth_cntx.paired_dev_num));
        memcpy(&(g_mmi_bth_cntx.host_dev), &(read_struct.host_dev), sizeof(mmi_bth_dev_struct));
    }
    else
    {
        memset(&g_mmi_bth_cntx, 0, sizeof(mmi_bth_cntx_struct));
        g_mmi_bth_cntx.idx_of_last_hid_dev = 0xFFFFFFFF;
        /* Configure Default Headset */
        g_mmi_bth_cntx.idx_of_last_hs_dev = 0xFFFFFFFF;

    }

    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_NVR_READ, g_mmi_bth_cntx.flag, g_mmi_bth_cntx.paired_dev_num);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_nvram_write_info
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_nvram_write_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bth_nvram_struct write_struct;
    S16 err;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BT_ASSERT(NVRAM_EF_BT_INFO_SIZE == sizeof(mmi_bth_nvram_struct));
    MMI_BT_ASSERT(g_mmi_bth_cntx.paired_dev_num <= MMI_BTH_MAX_PAIRED_DEVICE_LIST);

    write_struct.flag = g_mmi_bth_cntx.flag;
    write_struct.paired_dev_num = g_mmi_bth_cntx.paired_dev_num;
    write_struct.idx_of_last_hid_dev = g_mmi_bth_cntx.idx_of_last_hid_dev;
    /* Configure Default Headset */
    write_struct.idx_of_last_hs_dev = g_mmi_bth_cntx.idx_of_last_hs_dev;

    memcpy(
        write_struct.paired_list,
        g_mmi_bth_cntx.paired_list,
        sizeof(mmi_bth_dev_struct) * (g_mmi_bth_cntx.paired_dev_num));
    memcpy(&write_struct.host_dev, &g_mmi_bth_cntx.host_dev, sizeof(mmi_bth_dev_struct));

    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_NVR_WRITE, write_struct.flag, write_struct.paired_dev_num);

    WriteRecord(NVRAM_EF_BT_INFO_LID, 1, &write_struct, NVRAM_EF_BT_INFO_SIZE, &err);
    if (err != NVRAM_WRITE_SUCCESS)
    {
        MMI_BT_ASSERT(MMI_FALSE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_init_freshdev_default
 * DESCRIPTION
 *  This function is to register mydevice bd_addr, friend name for fresh device first time boot up.
 * PARAMETERS
 *  name_p      [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_init_freshdev_default(U8 *name_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (name_p == NULL)
    {
        name_p = (U8*) MMI_BT_DEF_HOST_BT_NAME;
    }

    kal_sprintf((kal_char*) g_mmi_bth_cntx.host_dev.name, (kal_char*) name_p);

    /* mmi_bth_nvram_write_info(); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_send_msg
 * DESCRIPTION
 *  This function is the handler for send msg to XXX module
 * PARAMETERS
 *  dest_module         [IN]        
 *  sap_id              [IN]        
 *  msg_id              [IN]        
 *  p_local_para        [?]         
 *  p_peer_buff         [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_send_msg(U32 dest_module, U32 sap_id, U32 msg_id, void *p_local_para, void *p_peer_buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_send;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_SEND_MSG , dest_module, msg_id ); */

    ilm_send = allocate_ilm(MOD_MMI);

    ilm_send->src_mod_id = MOD_MMI;
    ilm_send->dest_mod_id = dest_module;
    ilm_send->sap_id = sap_id;
    ilm_send->msg_id = (kal_uint16) msg_id;
    ilm_send->local_para_ptr = (local_para_struct*) p_local_para;
    ilm_send->peer_buff_ptr = (peer_buff_struct*) p_peer_buff;

    msg_send_ext_queue(ilm_send);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_antenna_on_req_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_antenna_on_req_hdler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#ifdef __GEMINI__
    bt_poweron_req_struct *msg_p;
 
    msg_p = (bt_poweron_req_struct*) construct_local_para(sizeof(bt_poweron_req_struct), TD_CTRL);
	if (PhnsetGetUARTConfig() == L4C_UART_TO_SIM1)
	{
    	msg_p->dual_sim_uart_setting = 0;
	}
	else
	{
    	msg_p->dual_sim_uart_setting = 1;
	}

    mmi_bth_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_POWERON_REQ, (void*)msg_p, NULL);
	#else
    mmi_bth_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_POWERON_REQ, NULL, NULL);
    /* SetProtocolEventHandler(mmi_bth_antenna_on_rsp_hdler, MSG_ID_BT_POWERON_CNF); */
	#endif /* __GEMINI__ */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_antenna_on_rsp_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg         [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_bth_hfg_activate_req_hdler(void);

void mmi_bth_antenna_on_rsp_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reset bt ready mask */
    MMI_BTH_RESET_RAMFLAG(MMI_BTH_RAMMASK_IS_READY);

	/* antenna on req->disable write scan enable(page off, inquiry off) */
	/* ->read BT address->set local name->set security->activate profiles */
	/* ->enable write scan mode */
	/* wait for ready indication to callback mmi_bth_activate_req*/

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_antenna_off_req_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_antenna_off_req_hdler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bth_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_POWEROFF_REQ, NULL, NULL);
    /* SetProtocolEventHandler(mmi_bth_antenna_off_rsp_hdler, MSG_ID_BT_POWEROFF_CNF); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_antenna_off_rsp_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg         [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_antenna_off_rsp_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reset bt ready mask */
    MMI_BTH_RESET_RAMFLAG(MMI_BTH_RAMMASK_IS_READY);

    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_POWER_OFF_FINISH);
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_CORE_STATUS,
               g_mmi_bth_cntx.state, g_mmi_bth_cntx.flag, g_mmi_bth_cntx.ram_flag, g_mmi_bth_cntx.deactivate_flag);

#ifndef __MMI_BT_BG_PWRON__
    /* disable write scan enable(page off, inquiry off) */
    /* ->deactivate profiles */
    /* ->antenna off */
    /* complete antenna off procedure */
    if (g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_deactivate)
    {
        (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_deactivate) (MMI_TRUE);
    }
#endif /* __MMI_BT_BG_PWRON__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_ready_ind_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg         [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_ready_ind_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_bth_is_activated() == MMI_TRUE)
    {

        /* antenna on req->disable write scan enable(page off, inquiry off) */
        /* ->read BT address->set local name->set security->activate profiles */
        /* ->enable write scan mode */
        /* disable write scan enable(page off, inquiry off) */
        MMI_BTH_STATE_TRANS(MMI_BTH_STAT_ACTIVATING_WRITE_SCAN_DISABLE);
        mmi_bth_set_connectable_req(MMI_FALSE);
        /* to ask BM(bluetooth management) to send link connect accept ind to MMI */
        mmi_bth_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_BM_LINK_CONNECT_ACCEPT_NOT_AUTO_REQ, NULL, NULL);

        
    }
    else
    {
        MMI_BTH_STATE_TRANS(MMI_BTH_STAT_INIT_OFF);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_restart_req_ind_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg         [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_restart_req_ind_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* notify UI layer to re-init bt content */
    if (g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_panic_ind)
    {
        (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_panic_ind) ();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_restart_rsp_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg         [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_restart_rsp_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* send antenna on req to BTH */
    /* while bt core reset, bt core will power on bt again */
    if (mmi_bth_is_activated())
    {
        //mmi_bth_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_POWERON_REQ, NULL, NULL);
        mmi_bth_antenna_on_req_hdler();
    }
    else
    {
        //mmi_bth_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_POWEROFF_REQ, NULL, NULL);
        mmi_bth_antenna_off_req_hdler();
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_cm_discovery_req_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  max_response        [IN]            
 *  timeout             [IN]            
 *  cod                 [IN]            
 *  name_discovery      [IN]            
 *  a(?)                [IN/OUT]        First variable, used as returns
 *  b(?)                [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_cm_discovery_req_hdler(U8 max_response, U16 timeout, U32 cod, MMI_BOOL name_discovery)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bm_discovery_req_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (bt_bm_discovery_req_struct*) construct_local_para(sizeof(bt_bm_discovery_req_struct), TD_CTRL);
    msg_p->cod = cod;
    msg_p->inquiry_length = ((timeout * 1000) / 1280);
    msg_p->inquiry_number = max_response;
    msg_p->access_mode = BTBM_GENERAL_INQUIRY;
    if (name_discovery)
    {
        msg_p->discovery_mode = BTBM_DISCOVERY_WITH_NAME;
    }
    else
    {
        msg_p->discovery_mode = BTBM_DISCOVERY_WITHOUT_NAME;
    }

    mmi_bth_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_BM_DISCOVERY_REQ, (void*)msg_p, NULL);
    //SetProtocolEventHandler(mmi_bth_cm_discovery_result_ind_hdler, MSG_ID_BT_BM_DISCOVERY_RESULT_IND);
    //SetProtocolEventHandler(mmi_bth_cm_discovery_cnf_hdler, MSG_ID_BT_BM_DISCOVERY_CNF);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_cm_discovery_result_ind_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg         [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_cm_discovery_result_ind_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i = 0;
    U32 name_len = 0;
    bt_bm_discovery_result_ind_struct *msg_p = (bt_bm_discovery_result_ind_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_PAIRED_DEV_INFO,
               msg_p->cod,
               ((msg_p->bd_addr.nap & 0xff00) >> 8), (msg_p->bd_addr.nap & 0x00ff),
               (msg_p->bd_addr.uap),
               ((msg_p->bd_addr.lap & 0xff0000) >> 16), ((msg_p->bd_addr.lap & 0x00ff00) >> 8),
               (msg_p->bd_addr.lap & 0x0000ff));
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_CORE_STATUS,
               g_mmi_bth_cntx.state, g_mmi_bth_cntx.flag, g_mmi_bth_cntx.ram_flag, g_mmi_bth_cntx.deactivate_flag);

    /* skip cm discovered result ind while not in inquiry/inquiry ind state */
    if ((g_mmi_bth_cntx.state != MMI_BTH_STAT_INQUIRING) && (g_mmi_bth_cntx.state != MMI_BTH_STAT_INQUIR_RES_IND))
    {
        return;
    }

    /* get index of discovered list */
    /* if it is a new one, i = g_mmi_bth_cntx.discovered_dev_num */
    /* if it is existed, i != g_mmi_bth_cntx.discovered_dev_num */
    /* it is to avoid BTH send duplicated result ind */
    for (i = 0; i < g_mmi_bth_cntx.discovered_dev_num; i++)
    {
        if (g_mmi_bth_cntx.discovered_list[i].bd_addr.lap == msg_p->bd_addr.lap
            && g_mmi_bth_cntx.discovered_list[i].bd_addr.uap == msg_p->bd_addr.uap
            && g_mmi_bth_cntx.discovered_list[i].bd_addr.nap == msg_p->bd_addr.nap)
        {
            return;
            /* break; */
        }
    }

    MMI_BTH_STATE_TRANS(MMI_BTH_STAT_INQUIR_RES_IND);

    /* Process Found Device */
    if (i < MMI_BTH_MAX_DISCOVERY_RESULTS_IN_LIST)
    {
        /* Store device info */
        g_mmi_bth_cntx.discovered_list[i].cod = msg_p->cod;
        g_mmi_bth_cntx.discovered_list[i].bd_addr.lap = msg_p->bd_addr.lap;
        g_mmi_bth_cntx.discovered_list[i].bd_addr.uap = msg_p->bd_addr.uap;
        g_mmi_bth_cntx.discovered_list[i].bd_addr.nap = msg_p->bd_addr.nap;
        /* strlen will not count the NULL terminate byte */
        name_len = strlen((const char*)msg_p->name);
        if (name_len >= MMI_BTH_BD_FNAME_LEN)
        {
            name_len = MMI_BTH_BD_FNAME_LEN;
            msg_p->name[MMI_BTH_BD_FNAME_LEN - 1] = '\0';
            msg_p->name[MMI_BTH_BD_FNAME_LEN - 2] = '\0';
        }
        memcpy(g_mmi_bth_cntx.discovered_list[i].name, msg_p->name, MMI_BTH_BD_FNAME_LEN);

        /* Increase device count */
        g_mmi_bth_cntx.discovered_dev_num++;
        MMI_BT_ASSERT(g_mmi_bth_cntx.discovered_dev_num <= MMI_BTH_MAX_DISCOVERY_RESULTS_IN_LIST);

        /* Indicate MMI Scr */
        if (g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_inquiry)
        {
            (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_inquiry) ();
        }
    }
    else
    {
        MMI_BT_ASSERT(0);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_cm_discovery_cnf_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg         [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_cm_discovery_cnf_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bm_discovery_cnf_struct *msg_p = (bt_bm_discovery_cnf_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BTH_STATE_TRANS(MMI_BTH_STAT_IDLE);

    if (msg_p->result == BTBM_ADP_SUCCESS)
    {

        if (msg_p->total_number != g_mmi_bth_cntx.discovered_dev_num)
        {
            MMI_BT_ASSERT(0);
        }

        /* Indicate MMI Scr */
        if (g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_inquiry_cfm)
        {
            (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_inquiry_cfm) (MMI_TRUE);
        }
    }
    else if (msg_p->result != BTBM_ADP_SUCCESS)
    {
        /* Indicate MMI Scr */
        if (g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_inquiry_cfm)
        {
            (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_inquiry_cfm) (MMI_FALSE);
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_cm_cancel_discovery_req_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_cm_cancel_discovery_req_hdler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bth_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_BM_DISCOVERY_CANCEL_REQ, (void*)NULL, NULL);
    /* SetProtocolEventHandler(mmi_bth_cm_cancel_discovery_cnf_hdler, MSG_ID_BT_BM_DISCOVERY_CANCEL_CNF); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_cm_cancel_discovery_cnf_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg         [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_cm_cancel_discovery_cnf_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bm_discovery_cancel_cnf_struct *msg_p = (bt_bm_discovery_cancel_cnf_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_CORE_STATUS,
               g_mmi_bth_cntx.state, g_mmi_bth_cntx.flag, g_mmi_bth_cntx.ram_flag, g_mmi_bth_cntx.deactivate_flag);
    
    switch (g_mmi_bth_cntx.state)
    {
        case MMI_BTH_STAT_BONDING:
            /* do nothing */
            /* if current state is bonding, shall not update bth state */
            /* the cancel-discovery cfm is coming because mmi will send cancel disconvery req before bonding */
            /* so it shall be in bonding state now */
            break;
        default:
            MMI_BTH_STATE_TRANS(MMI_BTH_STAT_IDLE);
            break;
    }

    if (msg_p->result == BTBM_ADP_SUCCESS)
    {

        /* Indicate MMI Scr */
        if (g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_inquiry_cancel)
        {
            (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_inquiry_cancel) (MMI_TRUE);
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_cm_set_local_name_req_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  name_len        [IN]            
 *  name            [?]             
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_cm_set_local_name_req_hdler(U8 name_len, U8 *name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bm_write_local_name_req_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p =
        (bt_bm_write_local_name_req_struct*) construct_local_para(sizeof(bt_bm_write_local_name_req_struct), TD_CTRL);
    msg_p->name_len = name_len;
    if (name_len + 1 > BTBM_ADP_MAX_NAME_LEN)
    {
        msg_p->name_len = BTBM_ADP_MAX_NAME_LEN - 1;
        name[BTBM_ADP_MAX_NAME_LEN] = '\0';
    }
    memcpy(msg_p->name, name, name_len + 1);

    mmi_bth_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_BM_WRITE_LOCAL_NAME_REQ, (void*)msg_p, NULL);
    /* SetProtocolEventHandler(mmi_bth_cm_set_local_name_cnf_hdler, MSG_ID_BT_BM_WRITE_LOCAL_NAME_CNF); */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_cm_set_local_name_cnf_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg         [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_cm_set_local_name_cnf_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    U32 name_len = 0;
    bt_bm_write_local_name_cnf_struct *msg_p = (bt_bm_write_local_name_cnf_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_SET_LOCAL_NAME_CNF,
               g_mmi_bth_cntx.state, msg_p->result, g_mmi_bth_cntx.flag, g_mmi_bth_cntx.ram_flag);

    if (msg_p->result == BTBM_ADP_SUCCESS)
    {
        result = MMI_TRUE;
    }
    else
    {
        result = MMI_FALSE;
    }

    switch (g_mmi_bth_cntx.state)
    {
        case MMI_BTH_STAT_ACTIVATING:
        case MMI_BTH_STAT_INIT_ON:
            /* antenna on req->disable write scan enable(page off, inquiry off) */
            /* ->read BT address->set local name->set security->activate profiles */
            /* ->enable write scan mode */
            /* set security level */
            mmi_bth_cm_security_level_req_hdler((MMI_BOOL) MMI_BTH_GET_FLAG(MMI_BTH_MASK_AUTH));
            break;
        case MMI_BTH_STAT_LOCAL_NAME_SETTING:
            MMI_BTH_STATE_TRANS(MMI_BTH_STAT_IDLE);
            if (result)
            {
                name_len = strlen((const char*)g_mmi_bth_cntx.host_name_setting);
                if (name_len >= MMI_BTH_BD_FNAME_LEN)
                {
                    name_len = MMI_BTH_BD_FNAME_LEN;
                    g_mmi_bth_cntx.host_name_setting[MMI_BTH_BD_FNAME_LEN - 1] = '\0';
                    g_mmi_bth_cntx.host_name_setting[MMI_BTH_BD_FNAME_LEN - 2] = '\0';
                }
                memcpy(g_mmi_bth_cntx.host_dev.name, g_mmi_bth_cntx.host_name_setting, MMI_BTH_BD_FNAME_LEN);
                mmi_bth_nvram_write_info();
            }
            if (g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_set_name)
            {
                (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_set_name) (result);
            }
            break;
        default:
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_cm_read_local_bd_addr_req_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_cm_read_local_bd_addr_req_hdler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bth_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_BM_READ_LOCAL_ADDR_REQ, NULL, NULL);
    /* SetProtocolEventHandler(mmi_bth_cm_read_local_bd_addr_cnf_hdler, MSG_ID_BT_BM_READ_LOCAL_ADDR_CNF); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_cm_read_local_bd_addr_cnf_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg         [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_cm_read_local_bd_addr_cnf_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 name_len;
    bt_bm_read_local_addr_cnf_struct *msg_p = (bt_bm_read_local_addr_cnf_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_GET_LOCAL_BD_ADD_CNF, 
	   			g_mmi_bth_cntx.state, 
	   			g_mmi_bth_cntx.flag,
	   			g_mmi_bth_cntx.ram_flag,
					((msg_p->bd_addr.nap&0xff00) >> 8), (msg_p->bd_addr.nap&0x00ff), 
					(msg_p->bd_addr.uap),
               ((msg_p->bd_addr.lap & 0xff0000) >> 16), ((msg_p->bd_addr.lap & 0x00ff00) >> 8),
               (msg_p->bd_addr.lap & 0x0000ff));

    if (msg_p->result == BTBM_ADP_SUCCESS)
    {
        #if 0 /* 0 BD address is allowed */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif

        g_mmi_bth_cntx.host_dev.bd_addr.lap = msg_p->bd_addr.lap;
        g_mmi_bth_cntx.host_dev.bd_addr.uap = msg_p->bd_addr.uap;
        g_mmi_bth_cntx.host_dev.bd_addr.nap = msg_p->bd_addr.nap;

        switch (g_mmi_bth_cntx.state)
        {
            case MMI_BTH_STAT_ACTIVATING:
            case MMI_BTH_STAT_INIT_ON:
                /* antenna on req->disable write scan enable(page off, inquiry off) */
                /* ->read BT address->set local name->set security->activate profiles */
                /* ->enable write scan mode */
                /* set local name */
                name_len = strlen((const char*)g_mmi_bth_cntx.host_dev.name);
                mmi_bth_cm_set_local_name_req_hdler(name_len, g_mmi_bth_cntx.host_dev.name);
                break;
            default:
                break;
        }

    }
    else
    {
        MMI_BT_ASSERT(0);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_cm_read_remote_name_req_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  bt_add      [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_cm_read_remote_name_req_hdler(mmi_bth_bt_addr bt_add)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bm_read_remote_name_req_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p =
        (bt_bm_read_remote_name_req_struct*) construct_local_para(sizeof(bt_bm_read_remote_name_req_struct), TD_CTRL);
    msg_p->bd_addr.lap = bt_add.lap;
    msg_p->bd_addr.uap = bt_add.uap;
    msg_p->bd_addr.nap = bt_add.nap;

    mmi_bth_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_BM_READ_REMOTE_NAME_REQ, (void*)msg_p, NULL);
    /* SetProtocolEventHandler(mmi_bth_cm_read_remote_name_cnf_hdler, MSG_ID_BT_BM_READ_REMOTE_NAME_CNF); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_cm_read_remote_name_cnf_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg         [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_cm_read_remote_name_cnf_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 table_index;
    U32 supported_profile_uuid;
    U32 i = 0, name_len = 0;
    bt_bm_read_remote_name_cnf_struct *msg_p = (bt_bm_read_remote_name_cnf_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_GET_REMOTE_DEV_NAME_CNF,
               g_mmi_bth_cntx.state,
               !msg_p->result,
               g_mmi_bth_cntx.flag,
               g_mmi_bth_cntx.ram_flag,
               ((msg_p->bd_addr.nap & 0xff00) >> 8), (msg_p->bd_addr.nap & 0x00ff),
               (msg_p->bd_addr.uap),
               ((msg_p->bd_addr.lap & 0xff0000) >> 16), ((msg_p->bd_addr.lap & 0x00ff00) >> 8),
               (msg_p->bd_addr.lap & 0x0000ff));

	if(msg_p->result == BTBM_ADP_SUCCESS)
	{
			/* get index of paired list */
			for(i=0; i<g_mmi_bth_cntx.paired_dev_num; i++)
			{
				if(    g_mmi_bth_cntx.paired_list[i].bd_addr.lap == msg_p->bd_addr.lap 
				    && g_mmi_bth_cntx.paired_list[i].bd_addr.uap == msg_p->bd_addr.uap 
				    && g_mmi_bth_cntx.paired_list[i].bd_addr.nap == msg_p->bd_addr.nap )
				{
					break;
				}
			}

        	if (i == g_mmi_bth_cntx.paired_dev_num)
        	{
           	 	return;
        	}

			/* update remote device name */
			/* strlen will not count the NULL terminate byte */
			name_len			= strlen((const char*)msg_p->name);
			if (name_len >= MMI_BTH_BD_FNAME_LEN)
			{
				name_len = MMI_BTH_BD_FNAME_LEN;
				msg_p->name[MMI_BTH_BD_FNAME_LEN-1] = '\0';
				msg_p->name[MMI_BTH_BD_FNAME_LEN-2] = '\0';
			}
			memcpy( g_mmi_bth_cntx.paired_list[i].name, msg_p->name, MMI_BTH_BD_FNAME_LEN );

        g_mmi_bth_cntx.paired_list[i].cod = msg_p->cod;

			/* write to NVRAM---store the device name */
			mmi_bth_nvram_write_info();

	}
	else
	{
			/* do nothing */
	}

    switch (g_mmi_bth_cntx.state)
    {
        case MMI_BTH_STAT_CONNECT_ACCEPT_CONFIRM_IND:
            if (msg_p->result == BTBM_ADP_SUCCESS)
            {
                if (g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_connect_accept_cnf_req)
                {
                    (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_connect_accept_cnf_req) ((U8*)g_mmi_bth_cntx.paired_list[i].name,
                                                                                       (U32)g_mmi_bth_cntx.paired_list[i].bd_addr.uap,
                                                                                       (U8)g_mmi_bth_cntx.paired_list[i].bd_addr.lap,
                                                                                       (U16)g_mmi_bth_cntx.paired_list[i].bd_addr.nap, 
																					   (U32)0xFFFFFFFF,
                                                                                       (U32)g_mmi_bth_cntx.conn_cnf_profile_id);
                }
            }
            else
            {
                /* reject the connect accept confirm */
                table_index = 0;
                if (g_mmi_bth_cntx.conn_cnf_profile_id == MMI_BTH_HF_PROFILE_UUID)
                {
                    supported_profile_uuid = MMI_BTH_HFG_PROFILE_UUID;
                }
                else if (g_mmi_bth_cntx.conn_cnf_profile_id == MMI_BTH_HS_PROFILE_UUID)
                {
                    supported_profile_uuid = MMI_BTH_HEADSET_AG_SERVICE_UUID;
                }
                else
                {
                    supported_profile_uuid = g_mmi_bth_cntx.conn_cnf_profile_id;
                }
                while (support_profile_tbl[table_index].uuid != MMI_BTH_MAX_PROFILE_UUID)
                {
                    if ((support_profile_tbl[table_index].uuid == supported_profile_uuid))
                    {
                        if (support_profile_tbl[table_index].connect_cnf_res_func_ptr)
                        {
                            (*support_profile_tbl[table_index].connect_cnf_res_func_ptr) (g_mmi_bth_cntx.
                                                                                          paired_list[g_mmi_bth_cntx.
                                                                                                      action_index].
                                                                                          bd_addr, MMI_FALSE);
                        }
                        break;
                    }
                    table_index++;
                }
                MMI_BTH_STATE_TRANS(MMI_BTH_STAT_IDLE);

            }
            break;
        default:
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_cm_sdc_search_req_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  bt_add          [IN]            
 *  sdap_len        [IN]            
 *  sdap_uuid       [?]             
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_cm_sdc_search_req_hdler(mmi_bth_bt_addr bt_add, U8 sdap_len, U16 *sdap_uuid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    bt_bm_service_search_req_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (bt_bm_service_search_req_struct*) construct_local_para(sizeof(bt_bm_service_search_req_struct), TD_CTRL);
    msg_p->bd_addr.lap = bt_add.lap;
    msg_p->bd_addr.uap = bt_add.uap;
    msg_p->bd_addr.nap = bt_add.nap;
    msg_p->sdap_len = sdap_len;
    MMI_BT_ASSERT(sdap_len <= BTBM_ADP_MAX_SDAP_UUID_NO) for (i = 0; i < sdap_len; i++)
    {
        msg_p->sdap_uuid[i] = sdap_uuid[i];
    }

    mmi_bth_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_BM_SERVICE_SEARCH_REQ, (void*)msg_p, NULL);
    //SetProtocolEventHandler(mmi_bth_cm_sdc_search_ind_hdler, MSG_ID_BT_BM_SERVICE_SEARCH_RESULT_IND);
    //SetProtocolEventHandler(mmi_bth_cm_sdc_search_cnf_hdler, MSG_ID_BT_BM_SERVICE_SEARCH_CNF);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_cm_sdc_search_ind_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg         [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_cm_sdc_search_ind_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;
    U8 service_count;
    U32 i, j;
    U32 service_profile_uuid;
    bt_bm_service_search_result_ind_struct *msg_p = (bt_bm_service_search_result_ind_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_p->uuid == MMI_BTH_AUDIO_SINK_UUID)
    {
        service_profile_uuid = MMI_BTH_ADVANCED_AUDIO_PROFILE_UUID;
    }
    else
    {
        service_profile_uuid = msg_p->uuid;
    }

    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_SDP_IND, g_mmi_bth_cntx.state, service_profile_uuid, 0);

    switch (g_mmi_bth_cntx.state)
    {
        case MMI_BTH_STAT_SDC_SEARCHING:
            index = g_mmi_bth_cntx.action_index;
            service_count = g_mmi_bth_cntx.discovered_list[index].service_list_num;

            /* to filter out the duplicated sdc indication */
            for (j = 0; j < g_mmi_bth_cntx.paired_list[index].service_list_num; j++)
            {
                if (g_mmi_bth_cntx.paired_list[index].service_list[j] == service_profile_uuid)
                {
                    break;
                }
            }
            if (j != g_mmi_bth_cntx.paired_list[index].service_list_num)
            {
                break;
            }

            /* add to dicovered list */
            g_mmi_bth_cntx.discovered_list[index].service_list[service_count] = service_profile_uuid;
            g_mmi_bth_cntx.discovered_list[index].service_list_num++;
            MMI_BT_ASSERT(g_mmi_bth_cntx.discovered_list[index].service_list_num <= MMI_BTH_MAX_HOST_SUPPORTED_PROFILE);
            /* add to paired list */
            g_mmi_bth_cntx.paired_list[index].service_list[service_count] = service_profile_uuid;
            g_mmi_bth_cntx.paired_list[index].service_list_num++;
            MMI_BT_ASSERT(g_mmi_bth_cntx.paired_list[index].service_list_num <= MMI_BTH_MAX_HOST_SUPPORTED_PROFILE);

            break;
        case MMI_BTH_STAT_SDC_REFRESHING:
        case MMI_BTH_STAT_IDLE:
            for (i = 0; i < g_mmi_bth_cntx.paired_dev_num; i++)
            {
                if (g_mmi_bth_cntx.paired_list[i].bd_addr.lap == msg_p->bd_addr.lap
                    && g_mmi_bth_cntx.paired_list[i].bd_addr.uap == msg_p->bd_addr.uap
                    && g_mmi_bth_cntx.paired_list[i].bd_addr.nap == msg_p->bd_addr.nap)
                {
                    break;
                }
            }
            MMI_BT_ASSERT( /* i==0 || */ i != g_mmi_bth_cntx.paired_dev_num);
            service_count = g_mmi_bth_cntx.paired_list[i].service_list_num;

            /* to filter out the duplicated sdc indication */
            for (j = 0; j < g_mmi_bth_cntx.paired_list[i].service_list_num; j++)
            {
                if (g_mmi_bth_cntx.paired_list[i].service_list[j] == service_profile_uuid)
                {
                    break;
                }
            }
            if (j != g_mmi_bth_cntx.paired_list[i].service_list_num)
            {
                break;
            }

            /* add to paired list */
            g_mmi_bth_cntx.paired_list[i].service_list[service_count] = service_profile_uuid;
            g_mmi_bth_cntx.paired_list[i].service_list_num++;
            MMI_BT_ASSERT(g_mmi_bth_cntx.paired_list[i].service_list_num <= MMI_BTH_MAX_HOST_SUPPORTED_PROFILE);

            break;
        default:
            break;

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_cm_sdc_search_cnf_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg         [?]             
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_cm_sdc_search_cnf_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bm_service_search_cnf_struct *msg_p = (bt_bm_service_search_cnf_struct*) msg;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_SDP_SEARCH_CNF,
               g_mmi_bth_cntx.state,
               msg_p->searched_number,
               ((msg_p->bd_addr.nap & 0xff00) >> 8), (msg_p->bd_addr.nap & 0x00ff),
               (msg_p->bd_addr.uap),
               ((msg_p->bd_addr.lap & 0xff0000) >> 16), ((msg_p->bd_addr.lap & 0x00ff00) >> 8),
               (msg_p->bd_addr.lap & 0x0000ff));

    switch (g_mmi_bth_cntx.state)
    {
        case MMI_BTH_STAT_SDC_SEARCHING:
            MMI_BTH_STATE_TRANS(MMI_BTH_STAT_IDLE);

            /* reset discovered dev list */
            g_mmi_bth_cntx.discovered_dev_num = 0;

            memset(
                &(g_mmi_bth_cntx.discovered_list),
                0,
                sizeof(mmi_bth_dev_struct) * MMI_BTH_MAX_DISCOVERY_RESULTS_IN_LIST);
            if (g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_bond)
            {
                (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_bond) ( /* MMI_TRUE */ );     /* connect confirm screen */
            }
            break;
        case MMI_BTH_STAT_SDC_REFRESHING:
        case MMI_BTH_STAT_PASSKEY_IND:
        case MMI_BTH_STAT_PASSKEY_RES:
        case MMI_BTH_STAT_IDLE:
            MMI_BTH_STATE_TRANS(MMI_BTH_STAT_IDLE);
			/* re-store the original number of service list */
			if (msg_p->result == BTBM_ADP_FAILED && msg_p->searched_number == 0)
			{
		        for (i = 0; i < g_mmi_bth_cntx.paired_dev_num; i++)
		        {
		            if (g_mmi_bth_cntx.paired_list[i].bd_addr.lap == msg_p->bd_addr.lap
		                && g_mmi_bth_cntx.paired_list[i].bd_addr.uap == msg_p->bd_addr.uap
		                && g_mmi_bth_cntx.paired_list[i].bd_addr.nap == msg_p->bd_addr.nap)
		            {
		                break;
		            }
		        }
		        if( i >= g_mmi_bth_cntx.paired_dev_num)
		        {
		        	return;
		        }
			
				g_mmi_bth_cntx.paired_list[i].service_list_num = g_mmi_bth_cntx.stored_ser_list_num;
			}
			
            if (g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_refresh_prof_list)
            {
                (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_refresh_prof_list) (MMI_TRUE);
            }
            break;
        default:
            break;

    }

    /* write to NVRAM---store the service list */
    mmi_bth_nvram_write_info();

}
/*****************************************************************************
 * FUNCTION
 *  mmi_bth_cm_link_connect_accept_ind_hdler
 * DESCRIPTION
 *  This function is to handle if reaching max number of paired device 
 * PARAMETERS
 *  msg     [IN]    msg structure
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_cm_link_connect_accept_ind_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 paired_dev_num;
    U32 paired_dev_index;
    bt_bm_link_connect_accept_ind_struct *msg_p = (bt_bm_link_connect_accept_ind_struct*) msg;
    bt_bm_link_connect_accept_rsp_struct *msg_rsp_p;
    mmi_bth_state_enum  cm_state;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_CORE_STATUS,
               g_mmi_bth_cntx.state, g_mmi_bth_cntx.flag, g_mmi_bth_cntx.ram_flag, g_mmi_bth_cntx.deactivate_flag);
    
    cm_state = g_mmi_bth_cntx.state;
    
    if (cm_state != MMI_BTH_STAT_IDLE || mmi_flight_mode_is_switching()== MMI_TRUE)
    {
        /* reject the acl link connect req */ 
        msg_rsp_p = (bt_bm_link_connect_accept_rsp_struct*) construct_local_para(sizeof(bt_bm_link_connect_accept_rsp_struct), TD_CTRL);
        msg_rsp_p->bd_addr.nap = msg_p->bd_addr.nap;
        msg_rsp_p->bd_addr.uap = msg_p->bd_addr.uap;
        msg_rsp_p->bd_addr.lap = msg_p->bd_addr.lap;
        msg_rsp_p->result = BTBM_ADP_FAILED;
        mmi_bth_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_BM_LINK_CONNECT_ACCEPT_RSP, (void*)msg_rsp_p, NULL);
        return;    
    }
    
    paired_dev_num = (U32)g_mmi_bth_cntx.paired_dev_num;

    for (paired_dev_index = 0; paired_dev_index < paired_dev_num; paired_dev_index++)
    {
        if (g_mmi_bth_cntx.paired_list[paired_dev_index].bd_addr.lap == msg_p->bd_addr.lap && 
            g_mmi_bth_cntx.paired_list[paired_dev_index].bd_addr.uap == msg_p->bd_addr.uap && 
            g_mmi_bth_cntx.paired_list[paired_dev_index].bd_addr.nap == msg_p->bd_addr.nap)
        {
            break;
        }
    }

    if ((paired_dev_index >= paired_dev_num) && (paired_dev_num == MMI_BTH_MAX_PAIRED_DEVICE_LIST))
    {
        /* 1. reject the acl link connect req */ 
        msg_rsp_p = (bt_bm_link_connect_accept_rsp_struct*) construct_local_para(sizeof(bt_bm_link_connect_accept_rsp_struct), TD_CTRL);
        msg_rsp_p->bd_addr.nap = msg_p->bd_addr.nap;
        msg_rsp_p->bd_addr.uap = msg_p->bd_addr.uap;
        msg_rsp_p->bd_addr.lap = msg_p->bd_addr.lap;
        msg_rsp_p->result = BTBM_ADP_FAILED;
        mmi_bth_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_BM_LINK_CONNECT_ACCEPT_RSP, (void*)msg_rsp_p, NULL);
        /* 2. notify end user to delete one paired device from MyDev and try it again */
        if (g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_display_popup)
        {
            (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_display_popup) ((PU8) GetString(STR_BT_PAIRED_DEV_FULL),
                                                                      IMG_GLOBAL_ERROR, 0,
                                                                      UI_POPUP_NOTIFYDURATION_TIME, ERROR_TONE);
        }
        
    }
    else
    {
        /* accept the acl link connect req */
        msg_rsp_p = (bt_bm_link_connect_accept_rsp_struct*) construct_local_para(sizeof(bt_bm_link_connect_accept_rsp_struct), TD_CTRL);
        msg_rsp_p->bd_addr.nap = msg_p->bd_addr.nap;
        msg_rsp_p->bd_addr.uap = msg_p->bd_addr.uap;
        msg_rsp_p->bd_addr.lap = msg_p->bd_addr.lap;
        msg_rsp_p->result = BTBM_ADP_SUCCESS;
        mmi_bth_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_BM_LINK_CONNECT_ACCEPT_RSP, (void*)msg_rsp_p, NULL);
    }

    return;    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bth_cm_bond_req_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  bt_add          [IN]            
 *  sdap_len        [IN]            
 *  sdap_uuid       [?]             
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_cm_bond_req_hdler(mmi_bth_bt_addr bt_add, U8 sdap_len, U16 *sdap_uuid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    bt_bm_bonding_req_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (bt_bm_bonding_req_struct*) construct_local_para(sizeof(bt_bm_bonding_req_struct), TD_CTRL);
    msg_p->bd_addr.lap = bt_add.lap;
    msg_p->bd_addr.uap = bt_add.uap;
    msg_p->bd_addr.nap = bt_add.nap;
    msg_p->sdap_len = sdap_len;
    MMI_BT_ASSERT(sdap_len <= BTBM_ADP_MAX_SDAP_UUID_NO) for (i = 0; i < sdap_len; i++)
    {
        msg_p->sdap_uuid[i] = sdap_uuid[i];
    }

    mmi_bth_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_BM_BONDING_REQ, (void*)msg_p, NULL);
    //SetProtocolEventHandler(mmi_bth_cm_bond_ind_hdler, MSG_ID_BT_BM_BONDING_RESULT_IND);
    //SetProtocolEventHandler(mmi_bth_cm_bond_cnf_hdler, MSG_ID_BT_BM_BONDING_CNF);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_cm_bond_ind_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg         [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_cm_bond_ind_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, j, k;
    bt_bm_bonding_result_ind_struct *msg_p = (bt_bm_bonding_result_ind_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_CORE_STATUS,
               g_mmi_bth_cntx.state, g_mmi_bth_cntx.flag, g_mmi_bth_cntx.ram_flag, g_mmi_bth_cntx.deactivate_flag);
    
    if (msg_p->result == BTBM_ADP_SUCCESS)
    {
        /* get index of paired list */
        for (i = 0; i < g_mmi_bth_cntx.paired_dev_num; i++)
        {
            if (g_mmi_bth_cntx.paired_list[i].bd_addr.lap == msg_p->bd_addr.lap
                && g_mmi_bth_cntx.paired_list[i].bd_addr.uap == msg_p->bd_addr.uap
                && g_mmi_bth_cntx.paired_list[i].bd_addr.nap == msg_p->bd_addr.nap)
            {
                break;
            }
        }

        /* update cod */
        /* if already in paired list, then replace it, */
        /* if not in paired list, then skip it */
        if (i < g_mmi_bth_cntx.paired_dev_num)
        {
            if (g_mmi_bth_cntx.paired_list[i].cod == 0)
            {
                g_mmi_bth_cntx.paired_list[i].cod = msg_p->cod;
                /* write to NVRAM */
                mmi_bth_nvram_write_info();
            }

        }
    }
    else    /* msg_p->result != BTBM_ADP_SUCCESS */
    {
        /* remove this device from my dev list if there is no active connection connected wit this device */
        if (!mmi_bth_is_connection_active((mmi_bth_bt_addr*) & (msg_p->bd_addr)) &&
            !MMI_BTH_GET_RAMFLAG(MMI_BTH_RAMMASK_REJECT_PAIR_REQ) &&
            MMI_BTH_GET_RAMFLAG(MMI_BTH_RAMMASK_FIRST_PAIR_REQ))
        {
            /* get index of paired list */
            for (i = 0; i < g_mmi_bth_cntx.paired_dev_num; i++)
            {
                if (g_mmi_bth_cntx.paired_list[i].bd_addr.lap == msg_p->bd_addr.lap
                    && g_mmi_bth_cntx.paired_list[i].bd_addr.uap == msg_p->bd_addr.uap
                    && g_mmi_bth_cntx.paired_list[i].bd_addr.nap == msg_p->bd_addr.nap)
                {
                    break;
                }
            }

            /* i cannot be equal to g_mmi_bth_cntx.paired_dev_num */
            /* if i=0 and g_mmi_bth_cntx.paired_dev_num=0, assert it */
            MMI_BT_ASSERT(i != g_mmi_bth_cntx.paired_dev_num);

            /* remove this paired device from paired list */
            if (i == (g_mmi_bth_cntx.paired_dev_num - 1))
            {
                memset(&(g_mmi_bth_cntx.paired_list[i]), 0, sizeof(mmi_bth_dev_struct));
            }
            else
            {
                for (j = i; j < g_mmi_bth_cntx.paired_dev_num - 1; j++)
                {
                    memcpy(
                        &(g_mmi_bth_cntx.paired_list[j]),
                        &(g_mmi_bth_cntx.paired_list[j + 1]),
                        sizeof(mmi_bth_dev_struct));
                }
                memset(&(g_mmi_bth_cntx.paired_list[j]), 0, sizeof(mmi_bth_dev_struct));

            }

            MMI_BT_ASSERT(g_mmi_bth_cntx.paired_dev_num);
            g_mmi_bth_cntx.paired_dev_num--;
            /* write to NVRAM */
            mmi_bth_nvram_write_info();

            /* re-struct the index_of_paried_list in existed conn list */
            for (j = 0; j < g_mmi_bth_cntx.existed_conn_num; j++)
            {
                if (g_mmi_bth_cntx.existed_conn[j].index_of_paried_list == i)
                {
                    /* set the index_of_paried_list of wanted deleted existed_conn to be 0xFF */
                    g_mmi_bth_cntx.existed_conn[j].index_of_paried_list = 0xFF;
                }
                else if (g_mmi_bth_cntx.existed_conn[j].index_of_paried_list > i)
                {
                    g_mmi_bth_cntx.existed_conn[j].index_of_paried_list--;
                }
            }

            /* remove this paired device from existed_conn list */
            for (j = 0; j < g_mmi_bth_cntx.existed_conn_num; j++)
            {
                if (g_mmi_bth_cntx.existed_conn[j].index_of_paried_list == 0xFF)
                {
                    if (j == (g_mmi_bth_cntx.existed_conn_num - 1))
                    {
                        memset(&(g_mmi_bth_cntx.existed_conn[j]), 0, sizeof(mmi_bth_connect_struct));
                    }
                    else
                    {
                        for (k = j; k < g_mmi_bth_cntx.existed_conn_num - 1; k++)
                        {
                            memcpy(
                                &(g_mmi_bth_cntx.existed_conn[k]),
                                &(g_mmi_bth_cntx.existed_conn[k + 1]),
                                sizeof(mmi_bth_connect_struct));
                        }
                        memset(&(g_mmi_bth_cntx.existed_conn[k]), 0, sizeof(mmi_bth_connect_struct));
                    }
                    /* remove this existed conn */
                    MMI_BT_ASSERT(g_mmi_bth_cntx.existed_conn_num);
                    g_mmi_bth_cntx.existed_conn_num--;
                    break;
                }
            }
        }
    }


    if (g_mmi_bth_cntx.state != MMI_BTH_STAT_BONDING && 
		g_mmi_bth_cntx.state != MMI_BTH_STAT_IDLE &&
		g_mmi_bth_cntx.state != MMI_BTH_STAT_CONNECTING)
    {
    
        if (!(MMI_BTH_GET_RAMFLAG(MMI_BTH_RAMMASK_REJECT_PAIR_REQ)))
        {
            if (g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_pair_result)
            {
                (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_pair_result) (!(msg_p->result));
            }
        }
    }

    if (!(MMI_BTH_GET_RAMFLAG(MMI_BTH_RAMMASK_REJECT_PAIR_REQ)))
    {
        if (g_mmi_bth_cntx.state == MMI_BTH_STAT_PASSKEY_RES || g_mmi_bth_cntx.state == MMI_BTH_STAT_PASSKEY_IND)
        {
            MMI_BTH_STATE_TRANS(MMI_BTH_STAT_IDLE);
        }
    }


    if (!MMI_BTH_GET_RAMFLAG(MMI_BTH_RAMMASK_REJECT_PAIR_REQ))
    {
        MMI_BTH_RESET_RAMFLAG(MMI_BTH_RAMMASK_FIRST_PAIR_REQ);
    }
    else
    {
        MMI_BTH_RESET_RAMFLAG(MMI_BTH_RAMMASK_REJECT_PAIR_REQ);
    }


}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_cm_bond_cnf_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg         [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_cm_bond_cnf_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    bt_bm_bonding_cnf_struct *msg_p = (bt_bm_bonding_cnf_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_p->result != BTBM_ADP_SUCCESS)
    {
        if(g_mmi_bth_cntx.state == MMI_BTH_STAT_BONDING)
        {
            MMI_BTH_STATE_TRANS(MMI_BTH_STAT_IDLE);
        
            if (g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_bond_ind)
            {
                (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_bond_ind) (MMI_FALSE);
            }
        }
    }
    else
    {

        MMI_BTH_STATE_TRANS(MMI_BTH_STAT_SDC_SEARCHING);

        /* get index of paired list */
        for (i = 0; i < g_mmi_bth_cntx.paired_dev_num; i++)
        {
            if (g_mmi_bth_cntx.paired_list[i].bd_addr.lap == msg_p->bd_addr.lap
                && g_mmi_bth_cntx.paired_list[i].bd_addr.uap == msg_p->bd_addr.uap
                && g_mmi_bth_cntx.paired_list[i].bd_addr.nap == msg_p->bd_addr.nap)
            {
                break;
            }
        }

        /* if already in paired list, then replace it, */
        /* if not in paired list, add it into paired list */

        /* add it into paired list */
        memcpy(
            &(g_mmi_bth_cntx.paired_list[i]),
            &(g_mmi_bth_cntx.discovered_list[g_mmi_bth_cntx.action_index]),
            sizeof(mmi_bth_dev_struct));

        MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_PAIRED_DEV_INFO,
                   g_mmi_bth_cntx.paired_list[i].cod,
                   ((g_mmi_bth_cntx.paired_list[i].bd_addr.nap & 0xff00) >> 8),
                   (g_mmi_bth_cntx.paired_list[i].bd_addr.nap & 0x00ff), (g_mmi_bth_cntx.paired_list[i].bd_addr.uap),
                   ((g_mmi_bth_cntx.paired_list[i].bd_addr.lap & 0xff0000) >> 16),
                   ((g_mmi_bth_cntx.paired_list[i].bd_addr.lap & 0x00ff00) >> 8),
                   (g_mmi_bth_cntx.paired_list[i].bd_addr.lap & 0x0000ff));

        /* reset original service list num */
        g_mmi_bth_cntx.paired_list[i].service_list_num = 0;
        g_mmi_bth_cntx.discovered_list[g_mmi_bth_cntx.action_index].service_list_num = 0;

        /* change the action_item to index to paired_list */
        g_mmi_bth_cntx.action_index = i;

        if (i == g_mmi_bth_cntx.paired_dev_num)
        {
            g_mmi_bth_cntx.paired_dev_num++;
            /* write to NVRAM */
            mmi_bth_nvram_write_info();
            MMI_BT_ASSERT(g_mmi_bth_cntx.paired_dev_num <= MMI_BTH_MAX_PAIRED_DEVICE_LIST);
        }

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_cm_debond_req_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  bt_add      [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_cm_debond_req_hdler(mmi_bth_bt_addr bt_add)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bm_delete_trust_req_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (bt_bm_delete_trust_req_struct*) construct_local_para(sizeof(bt_bm_delete_trust_req_struct), TD_CTRL);
    msg_p->bd_addr.lap = bt_add.lap;
    msg_p->bd_addr.uap = bt_add.uap;
    msg_p->bd_addr.nap = bt_add.nap;

    mmi_bth_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_BM_DELETE_TRUST_REQ, (void*)msg_p, NULL);
    /* SetProtocolEventHandler(mmi_bth_cm_debond_cnf_hdler, MSG_ID_BT_BM_DELETE_TRUST_CNF); */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_cm_debond_cnf_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg         [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_cm_debond_cnf_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, j, k;
    U32 last_hid_dev_idx;
    /* Configure Default Headset */
    U32 last_hs_dev_idx;    

    bt_bm_delete_trust_cnf_struct *msg_p = (bt_bm_delete_trust_cnf_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_CORE_STATUS,
               g_mmi_bth_cntx.state, g_mmi_bth_cntx.flag, g_mmi_bth_cntx.ram_flag, g_mmi_bth_cntx.deactivate_flag);
    
    last_hid_dev_idx = g_mmi_bth_cntx.idx_of_last_hid_dev;
    if (g_mmi_bth_cntx.paired_list[last_hid_dev_idx].bd_addr.lap == msg_p->bd_addr.lap
        && g_mmi_bth_cntx.paired_list[last_hid_dev_idx].bd_addr.uap == msg_p->bd_addr.uap
        && g_mmi_bth_cntx.paired_list[last_hid_dev_idx].bd_addr.nap == msg_p->bd_addr.nap)
    {
	    /* clear the last hid device information */
		g_mmi_bth_cntx.idx_of_last_hid_dev = 0xFFFFFFFF;
	    #ifdef __MMI_HIDD_SUPPORT__
	    mmi_bth_hidd_clear_last_dev_info();
	    #endif
    }

    /* Configure Default Headset */
    last_hs_dev_idx = g_mmi_bth_cntx.idx_of_last_hs_dev;
    if (g_mmi_bth_cntx.paired_list[last_hs_dev_idx].bd_addr.lap == msg_p->bd_addr.lap
        && g_mmi_bth_cntx.paired_list[last_hs_dev_idx].bd_addr.uap == msg_p->bd_addr.uap
        && g_mmi_bth_cntx.paired_list[last_hs_dev_idx].bd_addr.nap == msg_p->bd_addr.nap)
    {
	    /* clear the last hs device information */
		g_mmi_bth_cntx.idx_of_last_hs_dev = 0xFFFFFFFF;
    }


    switch (g_mmi_bth_cntx.state)
    {
        case MMI_BTH_STAT_DEBONDING:
            if (msg_p->result == BTBM_ADP_SUCCESS)
            {
                MMI_BTH_STATE_TRANS(MMI_BTH_STAT_IDLE);

                /* get index of paired list */
                for (i = 0; i < g_mmi_bth_cntx.paired_dev_num; i++)
                {
                    if (g_mmi_bth_cntx.paired_list[i].bd_addr.lap == msg_p->bd_addr.lap
                        && g_mmi_bth_cntx.paired_list[i].bd_addr.uap == msg_p->bd_addr.uap
                        && g_mmi_bth_cntx.paired_list[i].bd_addr.nap == msg_p->bd_addr.nap)
                    {
                        break;
                    }
                }

                /* i cannot be equal to g_mmi_bth_cntx.paired_dev_num */
                /* if i=0 and g_mmi_bth_cntx.paired_dev_num=0, assert it */
                if (i >= g_mmi_bth_cntx.paired_dev_num)
                {
                    return;
                }

                /* remove this paired device from paired list */
                if (i == (g_mmi_bth_cntx.paired_dev_num - 1))
                {
                    memset(&(g_mmi_bth_cntx.paired_list[i]), 0, sizeof(mmi_bth_dev_struct));
                }
                else
                {
                    for (j = i; j < g_mmi_bth_cntx.paired_dev_num - 1; j++)
                    {
                        memcpy(
                            &(g_mmi_bth_cntx.paired_list[j]),
                            &(g_mmi_bth_cntx.paired_list[j + 1]),
                            sizeof(mmi_bth_dev_struct));
                    }
                    memset(&(g_mmi_bth_cntx.paired_list[j]), 0, sizeof(mmi_bth_dev_struct));

                }

                MMI_BT_ASSERT(g_mmi_bth_cntx.paired_dev_num);
                g_mmi_bth_cntx.paired_dev_num--;
                /* write to NVRAM */
                mmi_bth_nvram_write_info();

                /* re-struct the index_of_paried_list in existed conn list */
                for (j = 0; j < g_mmi_bth_cntx.existed_conn_num; j++)
                {
                    if (g_mmi_bth_cntx.existed_conn[j].index_of_paried_list == i)
                    {
                        /* set the index_of_paried_list of wanted deleted existed_conn to be 0xFF */
                        g_mmi_bth_cntx.existed_conn[j].index_of_paried_list = 0xFF;
                    }
                    else if (g_mmi_bth_cntx.existed_conn[j].index_of_paried_list > i)
                    {
                        g_mmi_bth_cntx.existed_conn[j].index_of_paried_list--;
                    }
                }

                /* remove this paired device from existed_conn list */
                for (j = 0; j < g_mmi_bth_cntx.existed_conn_num; j++)
                {
                    if (g_mmi_bth_cntx.existed_conn[j].index_of_paried_list == 0xFF)
                    {
                        if (j == (g_mmi_bth_cntx.existed_conn_num - 1))
                        {
                            memset(&(g_mmi_bth_cntx.existed_conn[j]), 0, sizeof(mmi_bth_connect_struct));
                        }
                        else
                        {
                            for (k = j; k < g_mmi_bth_cntx.existed_conn_num - 1; k++)
                            {
                                memcpy(
                                    &(g_mmi_bth_cntx.existed_conn[k]),
                                    &(g_mmi_bth_cntx.existed_conn[k + 1]),
                                    sizeof(mmi_bth_connect_struct));
                            }
                            memset(&(g_mmi_bth_cntx.existed_conn[k]), 0, sizeof(mmi_bth_connect_struct));
                        }
                        /* remove this existed conn */
                        MMI_BT_ASSERT(g_mmi_bth_cntx.existed_conn_num);
                        g_mmi_bth_cntx.existed_conn_num--;
                        break;
                    }
                }

                if (g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_mydev_del)
                {
                    (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_mydev_del) (MMI_TRUE);
                }
            }
            else
            {
                if (g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_mydev_del)
                {
                    (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_mydev_del) (MMI_FALSE);
                }
            }
            break;
        case MMI_BTH_STAT_DEBONDING_ALL:
            if (msg_p->result == BTBM_ADP_SUCCESS)
            {
                if (g_mmi_bth_cntx.paired_dev_num == 0)
                {
                    MMI_BTH_STATE_TRANS(MMI_BTH_STAT_IDLE);
                    /* write to NVRAM */
                    mmi_bth_nvram_write_info();

                    if (g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_mydev_del_all)
                    {
                        (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_mydev_del_all) (MMI_TRUE);
                    }
                }
                else
                {
                    /* get index of paired list */
                    for (i = 0; i < g_mmi_bth_cntx.paired_dev_num; i++)
                    {
                        if (g_mmi_bth_cntx.paired_list[i].bd_addr.lap == msg_p->bd_addr.lap
                            && g_mmi_bth_cntx.paired_list[i].bd_addr.uap == msg_p->bd_addr.uap
                            && g_mmi_bth_cntx.paired_list[i].bd_addr.nap == msg_p->bd_addr.nap)
                        {
                            break;
                        }
                    }
                    /* i cannot be equal to g_mmi_bth_cntx.paired_dev_num */
                    /* if i=0 and g_mmi_bth_cntx.paired_dev_num=0, assert it */
                    if (i >= g_mmi_bth_cntx.paired_dev_num)
                    {
                        return;
                    }

                    /* remove this paired device from paired list */
                    if (i == (g_mmi_bth_cntx.paired_dev_num - 1))
                    {
                        memset(&(g_mmi_bth_cntx.paired_list[i]), 0, sizeof(mmi_bth_dev_struct));
                    }
                    else
                    {
                        for (j = i; j < g_mmi_bth_cntx.paired_dev_num - 1; j++)
                        {
                            memcpy(
                                &(g_mmi_bth_cntx.paired_list[j]),
                                &(g_mmi_bth_cntx.paired_list[j + 1]),
                                sizeof(mmi_bth_dev_struct));
                        }
                        memset(&(g_mmi_bth_cntx.paired_list[j]), 0, sizeof(mmi_bth_dev_struct));

                    }

                    MMI_BT_ASSERT(g_mmi_bth_cntx.paired_dev_num);
                    g_mmi_bth_cntx.paired_dev_num--;

                    /* re-struct the index_of_paried_list in existed conn list */
                    for (j = 0; j < g_mmi_bth_cntx.existed_conn_num; j++)
                    {
                        if (g_mmi_bth_cntx.existed_conn[j].index_of_paried_list == i)
                        {
                            /* set the index_of_paried_list of wanted deleted existed_conn to be 0xFF */
                            g_mmi_bth_cntx.existed_conn[j].index_of_paried_list = 0xFF;
                        }
                        else if (g_mmi_bth_cntx.existed_conn[j].index_of_paried_list > i)
                        {
                            g_mmi_bth_cntx.existed_conn[j].index_of_paried_list--;
                        }
                    }

                    /* remove this paired device from existed_conn list */
                    for (j = 0; j < g_mmi_bth_cntx.existed_conn_num; j++)
                    {
                        if (g_mmi_bth_cntx.existed_conn[j].index_of_paried_list == 0xFF)
                        {
                            if (j == (g_mmi_bth_cntx.existed_conn_num - 1))
                            {
                                memset(&(g_mmi_bth_cntx.existed_conn[j]), 0, sizeof(mmi_bth_connect_struct));
                            }
                            else
                            {
                                for (k = j; k < g_mmi_bth_cntx.existed_conn_num - 1; k++)
                                {
                                    memcpy(
                                        &(g_mmi_bth_cntx.existed_conn[k]),
                                        &(g_mmi_bth_cntx.existed_conn[k + 1]),
                                        sizeof(mmi_bth_connect_struct));
                                }
                                memset(&(g_mmi_bth_cntx.existed_conn[k]), 0, sizeof(mmi_bth_connect_struct));

                            }
                            /* remove this existed conn */
                            MMI_BT_ASSERT(g_mmi_bth_cntx.existed_conn_num);
                            g_mmi_bth_cntx.existed_conn_num--;
                            break;
                        }
                    }

                    if (g_mmi_bth_cntx.paired_dev_num == 0)
                    {
                        MMI_BTH_STATE_TRANS(MMI_BTH_STAT_IDLE);
                        /* write to NVRAM */
                        mmi_bth_nvram_write_info();

                        if (g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_mydev_del_all)
                        {
                            (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_mydev_del_all) (MMI_TRUE);
                        }
                    }
                    else
                    {

                        mmi_bth_cm_debond_req_hdler((g_mmi_bth_cntx.paired_list->bd_addr));
                    }

                }

            }
            break;
        default:
            return;

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_cm_passkey_ind_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg         [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_cm_passkey_ind_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, name_len = 0;
    mmi_bth_state_enum bth_state;
    U8 reject_pin_code[2];
    mmi_bth_bt_addr bd_add;
    bt_bm_pin_code_ind_struct *msg_p = (bt_bm_pin_code_ind_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_CORE_STATUS,
               g_mmi_bth_cntx.state, g_mmi_bth_cntx.flag, g_mmi_bth_cntx.ram_flag, g_mmi_bth_cntx.deactivate_flag);

    bth_state = mmi_bth_get_state();
    bd_add.lap = msg_p->bd_addr.lap;
    bd_add.uap = msg_p->bd_addr.uap;
    bd_add.nap = msg_p->bd_addr.nap;


    if (bth_state == MMI_BTH_STAT_INIT_ON ||
        bth_state == MMI_BTH_STAT_INIT_OFF ||
        bth_state == MMI_BTH_STAT_ACTIVATING ||
        bth_state == MMI_BTH_STAT_ACTIVATING_WRITE_SCAN_ENABLE ||
        bth_state == MMI_BTH_STAT_ACTIVATING_WRITE_SCAN_DISABLE ||
        bth_state == MMI_BTH_STAT_DEACTIVATING ||
        bth_state == MMI_BTH_STAT_PASSKEY_IND ||
        bth_state == MMI_BTH_STAT_PASSKEY_RES ||        
        bth_state == MMI_BTH_STAT_CONNECT_ACCEPT_CONFIRM_IND ||
        bth_state == MMI_BTH_STAT_INQUIRING ||
        bth_state == MMI_BTH_STAT_INQUIR_RES_IND ||
        bth_state == MMI_BTH_STAT_DEBONDING ||
        bth_state == MMI_BTH_STAT_DEBONDING_ALL ||
        /* for registering pairing function call */
        #if 0
        #ifdef __MMI_OPP_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
		#endif
        /* to check if doing the pairing process, if one profile app is doing abort or disconnect, pairing process is not required. */
        /* then BT CM shall reject the pairing directly */
		mmi_bth_is_pairing_permitted(bd_add) == MMI_FALSE ||
        bth_state == MMI_BTH_STAT_RELEASE_DEV_CONNECTION ||
        bth_state == MMI_BTH_STAT_RELEASE_ALL_CONNECTION 
       )
    {
        memset(reject_pin_code, 0, 2);
        /* reject the pair request */
        mmi_bth_cm_passkey_ind_rsp_hdler(bd_add, 0, reject_pin_code);
        /* SetProtocolEventHandler(mmi_bth_cm_bond_ind_hdler, MSG_ID_BT_BM_BONDING_RESULT_IND); */
        MMI_BTH_SET_RAMFLAG(MMI_BTH_RAMMASK_REJECT_PAIR_REQ);
        
    }
    else if (mmi_bth_get_state() != MMI_BTH_STAT_BONDING)
    {

        /* get index of paired list */
        for (i = 0; i < g_mmi_bth_cntx.paired_dev_num; i++)
        {
            if (g_mmi_bth_cntx.paired_list[i].bd_addr.lap == msg_p->bd_addr.lap
                && g_mmi_bth_cntx.paired_list[i].bd_addr.uap == msg_p->bd_addr.uap
                && g_mmi_bth_cntx.paired_list[i].bd_addr.nap == msg_p->bd_addr.nap)
            {
                break;
            }
        }

        if (i >= MMI_BTH_MAX_PAIRED_DEVICE_LIST)
        {
            /* skip this passcode request while */
            /* (1)it is not in paired_list */
            /* (2)and paired_dev_num == MMI_BTH_MAX_PAIRED_DEVICE_LIST */
            MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_MY_DEV_FUL_REJECT_PIN_REQ);
            memset(reject_pin_code, 0, 2);
            /* reject the another pair request */
            mmi_bth_cm_passkey_ind_rsp_hdler(bd_add, 0, reject_pin_code);
            /* SetProtocolEventHandler(mmi_bth_cm_bond_ind_hdler, MSG_ID_BT_BM_BONDING_RESULT_IND); */
            MMI_BTH_SET_RAMFLAG(MMI_BTH_RAMMASK_REJECT_PAIR_REQ);
            return;
        }

        /* add it into paired list */
        /* name of paired device is NULL, then update it or reget it */
        /* strlen will not count the NULL terminate byte */
        if (g_mmi_bth_cntx.paired_list[i].name[0] == 0 && msg_p->name[0] != 0)
        {
            name_len = strlen((const char*)msg_p->name);
            if (name_len >= MMI_BTH_BD_FNAME_LEN)
            {
                name_len = MMI_BTH_BD_FNAME_LEN;
                msg_p->name[MMI_BTH_BD_FNAME_LEN - 1] = '\0';
                msg_p->name[MMI_BTH_BD_FNAME_LEN - 2] = '\0';
            }
            memcpy((g_mmi_bth_cntx.paired_list[i].name), (msg_p->name), MMI_BTH_BD_FNAME_LEN);
        }
        else if (g_mmi_bth_cntx.paired_list[i].name[0] == 0 && msg_p->name[0] == 0)
        {
			//allow the name to be NULL
            //MMI_BT_ASSERT(0);
        }

        /* update BT address */
        g_mmi_bth_cntx.paired_list[i].bd_addr.lap = msg_p->bd_addr.lap;
        g_mmi_bth_cntx.paired_list[i].bd_addr.uap = msg_p->bd_addr.uap;
        g_mmi_bth_cntx.paired_list[i].bd_addr.nap = msg_p->bd_addr.nap;

        g_mmi_bth_cntx.action_index = i;

        MMI_BTH_STATE_TRANS(MMI_BTH_STAT_PASSKEY_IND);
        if (i == g_mmi_bth_cntx.paired_dev_num)
        {
            MMI_BTH_SET_RAMFLAG(MMI_BTH_RAMMASK_FIRST_PAIR_REQ);
            g_mmi_bth_cntx.paired_dev_num++;
            /* write to NVRAM */
            mmi_bth_nvram_write_info();
            MMI_BT_ASSERT(g_mmi_bth_cntx.paired_dev_num <= MMI_BTH_MAX_PAIRED_DEVICE_LIST);
        }
        /* will send to bt screen while name is not NULL */
        //if (g_mmi_bth_cntx.paired_list[i].name[0] != 0)
        //{
            if (g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_pair)
            {
                (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_pair) ();
            }
        //}

    }
    else
    {
        if (g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_pair)
        {
            (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_pair) ();
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_cm_passkey_ind_rsp_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  bt_add          [IN]            
 *  pin_len         [IN]            
 *  pin_code        [?]             
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_cm_passkey_ind_rsp_hdler(mmi_bth_bt_addr bt_add, U8 pin_len, U8 *pin_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bm_pin_code_rsp_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (bt_bm_pin_code_rsp_struct*) construct_local_para(sizeof(bt_bm_pin_code_rsp_struct), TD_CTRL);
    msg_p->bd_addr.lap = bt_add.lap;
    msg_p->bd_addr.uap = bt_add.uap;
    msg_p->bd_addr.nap = bt_add.nap;
    msg_p->pin_len = pin_len;
    MMI_BT_ASSERT(pin_len <= MMI_BTH_PASSKEY_MAX_LEN) memcpy(msg_p->pin_code, pin_code, pin_len + 1);
    mmi_bth_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_BM_PIN_CODE_RSP, (void*)msg_p, NULL);
    /* SetProtocolEventHandler(mmi_bth_cm_bond_ind_hdler, MSG_ID_BT_BM_BONDING_RESULT_IND); */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_cm_security_level_req_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  auth_flag       [IN]            
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_cm_security_level_req_hdler(MMI_BOOL auth_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bm_write_authentication_mode_req_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p =
        (bt_bm_write_authentication_mode_req_struct*)
        construct_local_para(sizeof(bt_bm_write_authentication_mode_req_struct), TD_CTRL);
    if (auth_flag)
    {
        msg_p->mode = BTBM_AUTHENTICATION_ENABLE;
    }
    else
    {
        msg_p->mode = BTBM_AUTHENTICATION_DISABLE;
    }
    mmi_bth_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_BM_WRITE_AUTHENTICATION_MODE_REQ, (void*)msg_p, NULL);
    /* SetProtocolEventHandler(mmi_bth_cm_security_level_cnf_hdler, MSG_ID_BT_BM_WRITE_AUTHENTICATION_MODE_CNF); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_cm_security_level_cnf_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg         [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_cm_security_level_cnf_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result;
    bt_bm_write_authentication_mode_cnf_struct *msg_p = (bt_bm_write_authentication_mode_cnf_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_SET_SEC_CNF,
               g_mmi_bth_cntx.state, msg_p->result, g_mmi_bth_cntx.flag, g_mmi_bth_cntx.ram_flag);

    if (msg_p->result == BTBM_ADP_SUCCESS)
    {
        result = MMI_TRUE;
    }
    else
    {
        result = MMI_FALSE;
        MMI_BT_ASSERT(0);
    }

    switch (g_mmi_bth_cntx.state)
    {
            /* phone power on to activate BT */
        case MMI_BTH_STAT_INIT_ON:
            /* antenna on req->disable write scan enable(page off, inquiry off) */
            /* ->read BT address->set local name->set security->activate profiles */
            /* ->enable write scan mode */
            /* activate profiles */
            mmi_bth_activate_profiles_req();
            break;
            /* phone power on to deactivate BT */
        case MMI_BTH_STAT_INIT_OFF:
            MMI_BTH_STATE_TRANS(MMI_BTH_STAT_IDLE);
            /* set BTH ready flag */
            MMI_BTH_SET_RAMFLAG(MMI_BTH_RAMMASK_IS_READY);
            break;

            /* BT power switching OFF */
        case MMI_BTH_STAT_DEACTIVATING:
            break;

            /* BT power switching ON */
        case MMI_BTH_STAT_ACTIVATING:
            if (result)
            {
                MMI_BTH_STATE_TRANS(MMI_BTH_STAT_IDLE);
                /* set MMI_BTH_MASK_ACTIVATED */
                MMI_BTH_SET_FLAG(MMI_BTH_MASK_ACTIVATED);
                mmi_bth_nvram_write_info();

            }
            else
            {
                MMI_BT_ASSERT(0);
            }

            if (g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_activate)
            {
                (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_activate) ((MMI_BOOL) result);
            }
            break;
            /* MMI menu autentication setting */
        case MMI_BTH_STAT_AUTHENTICATION_SETTING:
            MMI_BTH_STATE_TRANS(MMI_BTH_STAT_IDLE);
            if (result)
            {
                mmi_bth_nvram_write_info();
            }
            if (g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_set_auth)
            {
                (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_set_auth) ((MMI_BOOL) result);
            }
            break;
        default:
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_cm_write_scanenable_mode_req_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  connected_mode          [IN]            
 *  non_connected_mode      [IN]            
 *  a(?)                    [IN/OUT]        First variable, used as returns
 *  b(?)                    [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_cm_write_scanenable_mode_req_hdler(U8 connected_mode, U8 non_connected_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bm_write_scanenable_mode_req_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_CONNECTABLE_REQ, (non_connected_mode & BTBM_ADP_P_ON_I_OFF),
               (non_connected_mode & BTBM_ADP_P_OFF_I_ON));

    msg_p =
        (bt_bm_write_scanenable_mode_req_struct*) construct_local_para(
                                                    sizeof(bt_bm_write_scanenable_mode_req_struct),
                                                    TD_CTRL);
    msg_p->modenotconnected = non_connected_mode;
    msg_p->modeconnected = connected_mode;

    mmi_bth_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_BM_WRITE_SCANENABLE_MODE_REQ, (void*)msg_p, NULL);
    /* SetProtocolEventHandler(mmi_bth_cm_write_scanenable_mode_cnf_hdler, MSG_ID_BT_BM_WRITE_SCANENABLE_MODE_CNF); */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_cm_write_scanenable_mode_cnf_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg         [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_cm_write_scanenable_mode_cnf_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bm_write_scanenable_mode_cnf_struct *msg_p = (bt_bm_write_scanenable_mode_cnf_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_CORE_STATUS,
               g_mmi_bth_cntx.state, g_mmi_bth_cntx.flag, g_mmi_bth_cntx.ram_flag, g_mmi_bth_cntx.deactivate_flag);
    
    if (msg_p->result == BTBM_ADP_SUCCESS)
    {
        switch (g_mmi_bth_cntx.state)
        {
            case MMI_BTH_STAT_INIT_ON:
                /* antenna on req->disable write scan enable(page off, inquiry off) */
                /* ->read BT address->set local name->set security->activate profiles */
                /* ->enable write scan mode */
                /* read BT address */
                mmi_bth_cm_read_local_bd_addr_req_hdler();
                break;
            case MMI_BTH_STAT_ACTIVATING_WRITE_SCAN_DISABLE:
                /* antenna on req->disable write scan enable(page off, inquiry off) */
                /* ->read BT address->set local name->set security->activate profiles */
                /* ->enable write scan mode */
                /* read BT address */
                mmi_bth_activate_req();
                MMI_BTH_STATE_TRANS(MMI_BTH_STAT_INIT_ON);
                break;
            case MMI_BTH_STAT_ACTIVATING_WRITE_SCAN_ENABLE:
                /* antenna on req->disable write scan enable(page off, inquiry off) */
                /* ->read BT address->set local name->set security->activate profiles */
                /* ->enable write scan mode-> allow ACL link establishment */
                /* allow ACL link establishment */
                mmi_bth_cm_allow_acl_link_establishment_req_hdler();
                break;
            case MMI_BTH_STAT_DEACTIVATING:
                /* disable write scan enable(page off, inquiry off) */
                /* ->deactivate profiles */
                /* ->antenna off */
                /* deactivate profiles */
                mmi_bth_deactivate_profiles_req();
                break;
            case MMI_BTH_STAT_VISIBILITY_SETTING:
                MMI_BTH_STATE_TRANS(MMI_BTH_STAT_IDLE);
                /* write visibility setting to NVRAM */
                mmi_bth_nvram_write_info();
                if (g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_set_vis)
                {
                    (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_set_vis) (MMI_TRUE);
                }
                break;
            default:
				/* update status icon */
                if (g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_update_status_icon)
                {
                    (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_update_status_icon)();
                }
                break;
        }
    }
    else if (msg_p->result == BTBM_ADP_NOT_ALLOW)
    {
        switch (g_mmi_bth_cntx.state)
        {
            case MMI_BTH_STAT_VISIBILITY_SETTING:
                MMI_BTH_STATE_TRANS(MMI_BTH_STAT_IDLE);
                /* write visibility setting to NVRAM */
    		    if (MMI_BTH_GET_FLAG(MMI_BTH_MASK_VIS))
    		    {
    		        MMI_BTH_RESET_FLAG(MMI_BTH_MASK_VIS);
    		    }
    		    else
    		    {
    		        MMI_BTH_SET_FLAG(MMI_BTH_MASK_VIS);
    		    }
                if (g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_set_vis)
                {
                    (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_set_vis) (MMI_FALSE);
                }
                break;
            default:
                break;
        }
    }
    else
    {
        MMI_BT_ASSERT(0);
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_bth_cm_link_state_ind_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg         [?]             
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_cm_link_state_ind_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_CORE_STATUS,
               g_mmi_bth_cntx.state, g_mmi_bth_cntx.flag, g_mmi_bth_cntx.ram_flag, g_mmi_bth_cntx.deactivate_flag);
    /* it is not required to set the visibility to be off while reaching allowed max number of link */
    /* it will be controlled by BT stack and BT chip */
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
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_cm_allow_acl_link_establishment_req_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_cm_allow_acl_link_establishment_req_hdler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bth_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_BM_LINK_ALLOW_REQ, NULL, NULL);
    /* SetProtocolEventHandler(mmi_bth_cm_allow_acl_link_establishment_cnf_hdler, MSG_ID_BT_BM_LINK_ALLOW_CNF); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_cm_allow_acl_link_establishment_cnf_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg         [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_cm_allow_acl_link_establishment_cnf_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_CORE_STATUS,
               g_mmi_bth_cntx.state, g_mmi_bth_cntx.flag, g_mmi_bth_cntx.ram_flag, g_mmi_bth_cntx.deactivate_flag);

    switch (g_mmi_bth_cntx.state)
    {
        case MMI_BTH_STAT_ACTIVATING_WRITE_SCAN_ENABLE:
            /* antenna on req->disable write scan enable(page off, inquiry off) */
            /* ->read BT address->set local name->set security->activate profiles */
            /* ->enable write scan mode-> allow ACL link establishment */
            /* complete power on procedure */
            MMI_BTH_SET_RAMFLAG(MMI_BTH_RAMMASK_IS_READY);
            MMI_BTH_STATE_TRANS(MMI_BTH_STAT_IDLE);
            mmi_bth_nvram_write_info();
            MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_POWER_ON_FINISH);
            MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_CORE_STATUS,
                       g_mmi_bth_cntx.state, g_mmi_bth_cntx.flag, g_mmi_bth_cntx.ram_flag, g_mmi_bth_cntx.deactivate_flag);
            if (g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_activate)
            {
                (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_activate) (MMI_TRUE);
            }
            break;
        case MMI_BTH_STAT_DEACTIVATING_SIMAP:
            /* simap deactivate */
            /* -> allow acl link establishment */
            MMI_BTH_STATE_TRANS(MMI_BTH_STAT_IDLE);
            if (g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_set_simap)
            {
                (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_set_simap) (MMI_TRUE);
            }
            
        default:
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_cm_disallow_acl_link_establishment_req_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_cm_disallow_acl_link_establishment_req_hdler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bth_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_BM_LINK_DISALLOW_REQ, NULL, NULL);
    /* SetProtocolEventHandler(mmi_bth_cm_disallow_acl_link_establishment_cnf_hdler, MSG_ID_BT_BM_LINK_DISALLOW_CNF); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_cm_disallow_acl_link_establishment_cnf_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg         [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_cm_disallow_acl_link_establishment_cnf_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_CORE_STATUS,
               g_mmi_bth_cntx.state, g_mmi_bth_cntx.flag, g_mmi_bth_cntx.ram_flag, g_mmi_bth_cntx.deactivate_flag);
    
    switch (g_mmi_bth_cntx.state)
    {
        case MMI_BTH_STAT_DEACTIVATING:
            /* disallow acl link establishment */
            /* ->disable write scan enable(page off, inquiry off) */
            /* ->deactivate profiles */
            /* ->antenna off */
            /* disable write scan enable(page off, inquiry off) */
            mmi_bth_set_connectable_req(MMI_FALSE);
            break;
        case MMI_BTH_STAT_ACTIVATING_SIMAP:
            /* disallow acl link establishment */
            /* ->simap activate */
            #ifdef __MMI_SIMAP_SUPPORT__
            mmi_bth_simap_activate_req_hdler();
            #endif
            break;            
        default:
            break;
    }
}
/*****************************************************************************
 * FUNCTION
 *  mmi_bth_cm_sdpdb_register_cnf_hdler
 * DESCRIPTION
 *  This function is the msg hdler of BT_SDPDB_REGISTER_CNF
 * PARAMETERS
 *  msg      [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_cm_sdpdb_register_cnf_hdler(void *msg)
{
	U32 profile_uuid;
	bt_sdpdb_register_cnf_struct *msg_p = (bt_sdpdb_register_cnf_struct*) msg;

	profile_uuid = msg_p->uuid;

	switch(profile_uuid)
	{
		case MMI_BTH_OBEX_OBJECT_PUSH_SERVICE_UUID:
			/* callback opp sdp register cnf hdler */
            #ifdef __MMI_OPP_SUPPORT__
            mmi_bt_opps_sdpdb_register_cfn_handler(msg_p);
            #endif			
			break;
		case MMI_BTH_OBEX_FILE_TRANSFER_UUID:
			/* callback ftp sdp register cnf hdler */
            #ifdef __MMI_FTS_SUPPORT__
            mmi_bt_ftps_sdp_register_cnf_hdlr(msg_p);
            #endif
			break;
		/* BIP */
		case MMI_BTH_OBEX_IMAGING_RESPONDER_UUID:
            #ifdef __MMI_BIP_SUPPORT__
            mmi_bt_bipr_sdp_register_cnf_hdlr(msg_p);
            #endif
			break;
				
		default:
			break;
	}
	
}
/*****************************************************************************
 * FUNCTION
 *  mmi_bth_cm_sdpdb_deregister_cnf_hdler
 * DESCRIPTION
 *  This function is the msg hdler of BT_SDPDB_DEREGISTER_CNF
 * PARAMETERS
 *  msg      [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_cm_sdpdb_deregister_cnf_hdler(void *msg)
{
	U32 profile_uuid;
	bt_sdpdb_deregister_cnf_struct *msg_p = (bt_sdpdb_deregister_cnf_struct*) msg;

	profile_uuid = msg_p->uuid;

	switch(profile_uuid)
	{
		case MMI_BTH_OBEX_OBJECT_PUSH_SERVICE_UUID:
			/* callback opp sdp deregister cnf hdler */
            #ifdef __MMI_OPP_SUPPORT__
            mmi_bt_opps_bt_sdpdb_deregister_cfn_handler(msg_p);
            #endif			
			break;
		case MMI_BTH_OBEX_FILE_TRANSFER_UUID:
			/* callback ftp sdp deregister cnf hdler */
            #ifdef __MMI_FTS_SUPPORT__
            mmi_bt_ftps_sdp_deregister_cnf_hdlr(msg_p);
            #endif
			break;
		/* BIP */
		case MMI_BTH_OBEX_IMAGING_RESPONDER_UUID:
			      #ifdef __MMI_BIP_SUPPORT__
            mmi_bt_bipr_sdp_deregister_cnf_hdlr(msg_p);
            #endif
			break;
		default:
			break;
	}

}

/*****************************************************************************
 * FUNCTION
 *  mmi_bth_activate_cnf_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  profile_id      [IN]            
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_activate_cnf_hdler(U32 profile_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_ACTIVATE_CNF, profile_id);
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_DEACTIVATE_FLAG, g_mmi_bth_cntx.deactivate_flag);
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_CORE_STATUS,
               g_mmi_bth_cntx.state, g_mmi_bth_cntx.flag, g_mmi_bth_cntx.ram_flag, g_mmi_bth_cntx.deactivate_flag);
    

    i = 0;
    while (support_profile_tbl[i].uuid != MMI_BTH_MAX_PROFILE_UUID)
    {
        if (profile_id == (support_profile_tbl[i].uuid))
        {
            mmi_bth_reset_deactivate_flag((U32) support_profile_tbl[i].deactivate_flag);
            break;
        }
        i++;
    }

    MMI_ASSERT(support_profile_tbl[i].uuid != MMI_BTH_MAX_PROFILE_UUID);

    switch (g_mmi_bth_cntx.state)
    {
        case MMI_BTH_STAT_INIT_ON:
        case MMI_BTH_STAT_ACTIVATING:
            if (mmi_bth_is_all_supported_profiles_activated())
            {
                MMI_BTH_STATE_TRANS(MMI_BTH_STAT_ACTIVATING_WRITE_SCAN_ENABLE);
                /* antenna on req->disable write scan enable(page off, inquiry off) */
                /* ->read BT address->set local name->set security->activate profiles */
                /* ->enable write scan mode-> allow ACL link establishment */
                /* enable write scan mode */
                mmi_bth_set_connectable_req(MMI_TRUE);
            }
            break;
        case MMI_BTH_STAT_ACTIVATING_SIMAP:
            MMI_BTH_STATE_TRANS(MMI_BTH_STAT_IDLE);
            if (g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_set_simap)
            {
                (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_set_simap) (MMI_TRUE);
            }
            break;
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_deactivate_cnf_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  profile_id      [IN]            
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_deactivate_cnf_hdler(U32 profile_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 state;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_DEACTIVATE_CNF, profile_id);
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_DEACTIVATE_FLAG, g_mmi_bth_cntx.deactivate_flag);
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_CORE_STATUS,
               g_mmi_bth_cntx.state, g_mmi_bth_cntx.flag, g_mmi_bth_cntx.ram_flag, g_mmi_bth_cntx.deactivate_flag);

    i = 0;
    while (support_profile_tbl[i].uuid != MMI_BTH_MAX_PROFILE_UUID)
    {
        if (profile_id == (support_profile_tbl[i].uuid))
        {
            mmi_bth_set_deactivate_flag((U32) support_profile_tbl[i].deactivate_flag);
            break;
        }
        i++;
    }

    MMI_ASSERT(support_profile_tbl[i].uuid != MMI_BTH_MAX_PROFILE_UUID);

    state = g_mmi_bth_cntx.state;
    switch (state)
    {
        case MMI_BTH_STAT_DEACTIVATING:
            /* check if all services are deactivated */
            if (mmi_bth_is_all_supported_profiles_deactivated())
            {
                MMI_BTH_STATE_TRANS(MMI_BTH_STAT_IDLE);
                /* reset power mask */
                MMI_BTH_RESET_FLAG(MMI_BTH_MASK_ACTIVATED);
                mmi_bth_nvram_write_info();
                if (g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_deactivate)
                {
                    (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_deactivate) (MMI_TRUE);
                }
            }
            break;
        case MMI_BTH_STAT_DEACTIVATING_SIMAP:
            /* simap deactivate */
            /* -> allow acl link establishment */
            mmi_bth_cm_allow_acl_link_establishment_req_hdler();
            break;

        case MMI_BTH_STAT_RELEASE_OPP_CONNECTION:
            /* prohibit OPS->FTS->SPP->DUN profiles */
            mmi_bth_prohibit_ftp_req();
            break;
        case MMI_BTH_STAT_RELEASE_FTP_CONNECTION:
            /* prohibit OPS->FTS->SPP->DUN profiles */
            mmi_bth_prohibit_spp_req();
        default:
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_connect_ind_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  lap                 [IN]            
 *  uap                 [IN]            
 *  nap                 [IN]            
 *  name_p              [?]             
 *  profile_id          [IN]            
 *  connection_id       [IN]            
 *  a(?)                [IN/OUT]        First variable, used as returns
 *  b(?)                [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_connect_ind_hdler(
        U32 lap,
        U8 uap,
        U16 nap,
        U8 *name_p /* utf8 encoding */ ,
        U32 profile_id,
        U32 connection_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, j, name_len = 0;
    MMI_BOOL new_device = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_GEN_CONNECT_IND,
               g_mmi_bth_cntx.state,
               profile_id,
               connection_id,
               ((nap & 0xff00) >> 8), (nap & 0x00ff),
               (uap), ((lap & 0xff0000) >> 16), ((lap & 0x00ff00) >> 8), (lap & 0x0000ff));

    /* check if already in existed conn list */
    /* if yes, udpate it */
    /* if not, add it */
    for (i = 0; i < g_mmi_bth_cntx.existed_conn_num; i++)
    {
        if (g_mmi_bth_cntx.existed_conn[i].conn_id == connection_id)
        {
            break;
        }
    }

    /* store connection info */
    g_mmi_bth_cntx.existed_conn[i].conn_id = connection_id;
    g_mmi_bth_cntx.existed_conn[i].active = MMI_TRUE;

    if (i == g_mmi_bth_cntx.existed_conn_num)
    {
        g_mmi_bth_cntx.existed_conn_num++;
        MMI_BT_ASSERT(g_mmi_bth_cntx.existed_conn_num <= MMI_BTH_MAX_CONNECTION);
    }
    else
    {
        MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_CONNECTION_ID_EXISTED,connection_id);
    }
    

    /* get index of paired list */
    for (j = 0; j < g_mmi_bth_cntx.paired_dev_num; j++)
    {
        if (g_mmi_bth_cntx.paired_list[j].bd_addr.lap == lap
            && g_mmi_bth_cntx.paired_list[j].bd_addr.uap == uap && g_mmi_bth_cntx.paired_list[j].bd_addr.nap == nap)
        {
            break;
        }
    }

    if (j == g_mmi_bth_cntx.paired_dev_num)
    {
        new_device = MMI_TRUE;
        /* add it into paired list */
        g_mmi_bth_cntx.paired_list[j].bd_addr.lap = lap;
        g_mmi_bth_cntx.paired_list[j].bd_addr.uap = uap;
        g_mmi_bth_cntx.paired_list[j].bd_addr.nap = nap;

        /* reset original service list num */
        g_mmi_bth_cntx.paired_list[j].service_list_num = 0;

        g_mmi_bth_cntx.paired_dev_num++;
        /* write to NVRAM */
        mmi_bth_nvram_write_info();
        MMI_BT_ASSERT(g_mmi_bth_cntx.paired_dev_num <= MMI_BTH_MAX_PAIRED_DEVICE_LIST);
        /* replaced the in-active paired device or disconnect this connection */
    }

    if (profile_id == MMI_BTH_HID_PROFILE_UUID)
    {
        g_mmi_bth_cntx.idx_of_last_hid_dev = j;
        /* write to NVRAM */
        mmi_bth_nvram_write_info();
        MMI_BT_ASSERT(g_mmi_bth_cntx.paired_dev_num <= MMI_BTH_MAX_PAIRED_DEVICE_LIST);
    }

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

    g_mmi_bth_cntx.existed_conn[i].index_of_paried_list = j;
    /* update remote device name */
    if (name_p != NULL && new_device == MMI_TRUE)
    {
        /* strlen will not count the NULL terminate byte */
        name_len = strlen((const char*)name_p);
        if (name_len >= MMI_BTH_BD_FNAME_LEN)
        {
            name_len = MMI_BTH_BD_FNAME_LEN;
            name_p[MMI_BTH_BD_FNAME_LEN - 1] = '\0';
            name_p[MMI_BTH_BD_FNAME_LEN - 2] = '\0';
        }
        memcpy(g_mmi_bth_cntx.paired_list[j].name, name_p, MMI_BTH_BD_FNAME_LEN);
        /* write to NVRAM */
        mmi_bth_nvram_write_info();

    }
    else if (new_device == MMI_TRUE && g_mmi_bth_cntx.paired_list[j].name[0] == 0)
    {
        mmi_bth_bt_addr dev_addr;

        dev_addr.uap = uap;
        dev_addr.lap = lap;
        dev_addr.nap = nap;
        mmi_bth_cm_read_remote_name_req_hdler(dev_addr);
    }

    g_mmi_bth_cntx.existed_conn[i].conn_type = mmi_bth_get_connection_type(profile_id);

    if (profile_id == MMI_BTH_ADVANCED_AUDIO_PROFILE_UUID)
    {
        /* to disable the visibility */
        /* to avoid remote devie to inquiry us while a2dp is active and to impact the audio quality */
        if (g_mmi_bth_cntx.state != MMI_BTH_STAT_DEACTIVATING)
        {
            if (MMI_BTH_GET_FLAG(MMI_BTH_MASK_VIS))
            {
                U8 page_inquiry_mode;

                g_mmi_bth_cntx.a2dp_prohibit_vis = MMI_TRUE;
                page_inquiry_mode = BTBM_ADP_P_ON_I_OFF;
                mmi_bth_cm_write_scanenable_mode_req_hdler(page_inquiry_mode, page_inquiry_mode);
            }
        }
    }

    if (g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_connect)
    {
        (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_connect) (g_mmi_bth_cntx.existed_conn[i].conn_type, MMI_TRUE);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_connect_cnf_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  result              [IN]            
 *  lap                 [IN]            
 *  uap                 [IN]            
 *  nap                 [IN]            
 *  name_p              [?]             
 *  profile_id          [IN]            
 *  connection_id       [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_connect_cnf_hdler(
        MMI_BOOL result,
        U32 lap,
        U8 uap,
        U16 nap,
        U8 *name_p /* utf8 encoding */ ,
        U32 profile_id,
        U32 connection_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, j, name_len = 0;
    MMI_BOOL new_device = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_GEN_CONNECT_CNF,
               result,
               g_mmi_bth_cntx.state,
               profile_id,
               connection_id,
               ((nap & 0xff00) >> 8), (nap & 0x00ff),
               (uap), ((lap & 0xff0000) >> 16), ((lap & 0x00ff00) >> 8), (lap & 0x0000ff));

    MMI_BTH_STATE_TRANS(MMI_BTH_STAT_IDLE);

    if (result == MMI_TRUE)
    {
        /* check if already in existed conn list */
        /* if yes, udpate it */
        /* if not, add it */
        for (i = 0; i < g_mmi_bth_cntx.existed_conn_num; i++)
        {
            if (g_mmi_bth_cntx.existed_conn[i].conn_id == connection_id)
            {
                break;
            }
        }

        g_mmi_bth_cntx.existed_conn[i].conn_id = connection_id;

        g_mmi_bth_cntx.existed_conn[i].active = MMI_TRUE;
        if (i == g_mmi_bth_cntx.existed_conn_num)
        {
            g_mmi_bth_cntx.existed_conn_num++;
            MMI_BT_ASSERT(g_mmi_bth_cntx.existed_conn_num <= MMI_BTH_MAX_CONNECTION);
        }
        else
        {
            MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_CONNECTION_ID_EXISTED,connection_id);
        }

        /* get index of paired list */
        for (j = 0; j < g_mmi_bth_cntx.paired_dev_num; j++)
        {
            if (g_mmi_bth_cntx.paired_list[j].bd_addr.lap == lap
                && g_mmi_bth_cntx.paired_list[j].bd_addr.uap == uap && g_mmi_bth_cntx.paired_list[j].bd_addr.nap == nap)
            {
                break;
            }
        }

        if (j == g_mmi_bth_cntx.paired_dev_num)
        {
            new_device = MMI_TRUE;
            /* add it into paired list */
            g_mmi_bth_cntx.paired_list[j].bd_addr.lap = lap;
            g_mmi_bth_cntx.paired_list[j].bd_addr.uap = uap;
            g_mmi_bth_cntx.paired_list[j].bd_addr.nap = nap;

            /* reset original service list num */
            g_mmi_bth_cntx.paired_list[j].service_list_num = 0;

            g_mmi_bth_cntx.paired_dev_num++;
            /* write to NVRAM */
            mmi_bth_nvram_write_info();
            MMI_BT_ASSERT(g_mmi_bth_cntx.paired_dev_num <= MMI_BTH_MAX_PAIRED_DEVICE_LIST);
        }

        if (profile_id == MMI_BTH_HID_PROFILE_UUID)
        {
            g_mmi_bth_cntx.idx_of_last_hid_dev = j;
            /* write to NVRAM */
            mmi_bth_nvram_write_info();
            MMI_BT_ASSERT(g_mmi_bth_cntx.paired_dev_num <= MMI_BTH_MAX_PAIRED_DEVICE_LIST);
        }

		/* Configure Default Headset */
	    if (profile_id == MMI_BTH_HFG_PROFILE_UUID || profile_id == MMI_BTH_HEADSET_AG_SERVICE_UUID )
	    {
	        g_mmi_bth_cntx.idx_of_last_hs_dev = j;
	        /* write to NVRAM */
	        mmi_bth_nvram_write_info();
	        MMI_BT_ASSERT(g_mmi_bth_cntx.paired_dev_num <= MMI_BTH_MAX_PAIRED_DEVICE_LIST);
	    }


        g_mmi_bth_cntx.existed_conn[i].index_of_paried_list = j;
        /* update remote device name */
        if (name_p != NULL && new_device == MMI_TRUE)
        {
            /* strlen will not count the NULL terminate byte */
            name_len = strlen((const char*)name_p);
            if (name_len >= MMI_BTH_BD_FNAME_LEN)
            {
                name_len = MMI_BTH_BD_FNAME_LEN;
                name_p[MMI_BTH_BD_FNAME_LEN - 1] = '\0';
                name_p[MMI_BTH_BD_FNAME_LEN - 2] = '\0';
            }
            memcpy(g_mmi_bth_cntx.paired_list[j].name, name_p, MMI_BTH_BD_FNAME_LEN);
            /* write to NVRAM */
            mmi_bth_nvram_write_info();

        }

        g_mmi_bth_cntx.existed_conn[i].conn_type = mmi_bth_get_connection_type(profile_id);

        if (profile_id == MMI_BTH_ADVANCED_AUDIO_PROFILE_UUID)
        {
            /* to disable the visibility */
            /* to avoid remote devie to inquiry us while a2dp is active and to impact the audio quality */
            if (MMI_BTH_GET_FLAG(MMI_BTH_MASK_VIS))
            {
                U8 page_inquiry_mode;

                g_mmi_bth_cntx.a2dp_prohibit_vis = MMI_TRUE;
                page_inquiry_mode = BTBM_ADP_P_ON_I_OFF;
                mmi_bth_cm_write_scanenable_mode_req_hdler(page_inquiry_mode, page_inquiry_mode);
            }
        }
    }

    if (g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_connect)
    {
        (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_connect) ((U32) mmi_bth_get_connection_type(profile_id), result);
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_bth_multiple_connect_cnf_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  result              [IN]            
 *  lap                 [IN]            
 *  uap                 [IN]            
 *  nap                 [IN]            
 *  name_p              [?]             
 *  profile_id          [IN]            
 *  connection_id       [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_multiple_connect_cnf_hdler(
        MMI_BOOL result,
        U32 lap,
        U8 uap,
        U16 nap,
        U8 *name_p /* utf8 encoding */ ,
        U32 profile_id,
        U32 connection_id,
        U8  connecting_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, j, name_len = 0;
    MMI_BOOL new_device = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_GEN_CONNECT_CNF,
               result,
               g_mmi_bth_cntx.state,
               profile_id,
               connection_id,
               ((nap & 0xff00) >> 8), (nap & 0x00ff),
               (uap), ((lap & 0xff0000) >> 16), ((lap & 0x00ff00) >> 8), (lap & 0x0000ff));

    MMI_BTH_STATE_TRANS(MMI_BTH_STAT_IDLE);

    if (result == MMI_TRUE)
    {
        /* check if already in existed conn list */
        /* if yes, udpate it */
        /* if not, add it */
        for (i = 0; i < g_mmi_bth_cntx.existed_conn_num; i++)
        {
            if (g_mmi_bth_cntx.existed_conn[i].conn_id == connection_id)
            {
                break;
            }
        }

        g_mmi_bth_cntx.existed_conn[i].conn_id = connection_id;

        g_mmi_bth_cntx.existed_conn[i].active = MMI_TRUE;
        if (i == g_mmi_bth_cntx.existed_conn_num)
        {
            g_mmi_bth_cntx.existed_conn_num++;
            MMI_BT_ASSERT(g_mmi_bth_cntx.existed_conn_num <= MMI_BTH_MAX_CONNECTION);
        }
        else
        {
            MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_CONNECTION_ID_EXISTED,connection_id);
        }
        

        /* get index of paired list */
        for (j = 0; j < g_mmi_bth_cntx.paired_dev_num; j++)
        {
            if (g_mmi_bth_cntx.paired_list[j].bd_addr.lap == lap
                && g_mmi_bth_cntx.paired_list[j].bd_addr.uap == uap && g_mmi_bth_cntx.paired_list[j].bd_addr.nap == nap)
            {
                break;
            }
        }

        if (j == g_mmi_bth_cntx.paired_dev_num)
        {
            new_device = MMI_TRUE;
            /* add it into paired list */
            g_mmi_bth_cntx.paired_list[j].bd_addr.lap = lap;
            g_mmi_bth_cntx.paired_list[j].bd_addr.uap = uap;
            g_mmi_bth_cntx.paired_list[j].bd_addr.nap = nap;

            /* reset original service list num */
            g_mmi_bth_cntx.paired_list[j].service_list_num = 0;

            g_mmi_bth_cntx.paired_dev_num++;
            /* write to NVRAM */
            mmi_bth_nvram_write_info();
            MMI_BT_ASSERT(g_mmi_bth_cntx.paired_dev_num <= MMI_BTH_MAX_PAIRED_DEVICE_LIST);
        }

        g_mmi_bth_cntx.existed_conn[i].index_of_paried_list = j;
        /* update remote device name */
        if (name_p != NULL && new_device == MMI_TRUE)
        {
            /* strlen will not count the NULL terminate byte */
            name_len = strlen((const char*)name_p);
            if (name_len >= MMI_BTH_BD_FNAME_LEN)
            {
                name_len = MMI_BTH_BD_FNAME_LEN;
                name_p[MMI_BTH_BD_FNAME_LEN - 1] = '\0';
                name_p[MMI_BTH_BD_FNAME_LEN - 2] = '\0';
            }
            memcpy(g_mmi_bth_cntx.paired_list[j].name, name_p, MMI_BTH_BD_FNAME_LEN);
            /* write to NVRAM */
            mmi_bth_nvram_write_info();

        }

        g_mmi_bth_cntx.existed_conn[i].conn_type = mmi_bth_get_connection_type(profile_id);

        if (profile_id == MMI_BTH_ADVANCED_AUDIO_PROFILE_UUID)
        {
            /* to disable the visibility */
            /* to avoid remote devie to inquiry us while a2dp is active and to impact the audio quality */
            if (MMI_BTH_GET_FLAG(MMI_BTH_MASK_VIS))
            {
                U8 page_inquiry_mode;

                g_mmi_bth_cntx.a2dp_prohibit_vis = MMI_TRUE;
                page_inquiry_mode = BTBM_ADP_P_ON_I_OFF;
                mmi_bth_cm_write_scanenable_mode_req_hdler(page_inquiry_mode, page_inquiry_mode);
            }
        }
    }

    if (g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_connect)
    {
        (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_connect) ((U32) mmi_bth_get_connection_type(profile_id), result);
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_bth_connect_accept_confirm_req_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  lap             [IN]            
 *  uap             [IN]            
 *  nap             [IN]            
 *  profile_id      [IN]            
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_connect_accept_confirm_req_hdler(U32 lap, U8 uap, U16 nap, U8 *name_p /* utf8 encoding */, U32 profile_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 table_index;
    U32 supported_profile_uuid;
    mmi_bth_bt_addr dev_addr;
    mmi_bth_state_enum bth_state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_CORE_STATUS,
               g_mmi_bth_cntx.state, g_mmi_bth_cntx.flag, g_mmi_bth_cntx.ram_flag, g_mmi_bth_cntx.deactivate_flag);

    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_GEN_CONNECT_ACCEPT_CNF_REQ,
               g_mmi_bth_cntx.state,
               profile_id,
               ((nap & 0xff00) >> 8), (nap & 0x00ff),
               (uap), ((lap & 0xff0000) >> 16), ((lap & 0x00ff00) >> 8), (lap & 0x0000ff));

    bth_state = mmi_bth_get_state();
    dev_addr.lap = lap;
    dev_addr.uap = uap;
    dev_addr.nap = nap;

    if (bth_state == MMI_BTH_STAT_INIT_ON ||
        bth_state == MMI_BTH_STAT_INIT_OFF ||
        bth_state == MMI_BTH_STAT_ACTIVATING ||
        bth_state == MMI_BTH_STAT_ACTIVATING_WRITE_SCAN_ENABLE ||
        bth_state == MMI_BTH_STAT_ACTIVATING_WRITE_SCAN_DISABLE ||
        bth_state == MMI_BTH_STAT_DEACTIVATING ||
        bth_state == MMI_BTH_STAT_PASSKEY_IND ||
        bth_state == MMI_BTH_STAT_PASSKEY_RES ||
        bth_state == MMI_BTH_STAT_CONNECT_ACCEPT_CONFIRM_IND ||
        bth_state == MMI_BTH_STAT_INQUIRING ||
        bth_state == MMI_BTH_STAT_INQUIR_RES_IND ||
        bth_state == MMI_BTH_STAT_DEBONDING ||
        bth_state == MMI_BTH_STAT_DEBONDING_ALL ||
        bth_state == MMI_BTH_STAT_RELEASE_DEV_CONNECTION || 
        bth_state == MMI_BTH_STAT_RELEASE_ALL_CONNECTION ||
        mmi_flight_mode_is_switching() == MMI_TRUE)
    {
        /* reject the connect accept confirm */
        table_index = 0;
        if (profile_id == MMI_BTH_HF_PROFILE_UUID)
        {
            supported_profile_uuid = MMI_BTH_HFG_PROFILE_UUID;
        }
        else if (profile_id == MMI_BTH_HS_PROFILE_UUID)
        {
            supported_profile_uuid = MMI_BTH_HEADSET_AG_SERVICE_UUID;
        }
        else
        {
            supported_profile_uuid = profile_id;
        }
        while (support_profile_tbl[table_index].uuid != MMI_BTH_MAX_PROFILE_UUID)
        {
            if ((support_profile_tbl[table_index].uuid == supported_profile_uuid))
            {
                if (support_profile_tbl[table_index].connect_cnf_res_func_ptr)
                {
                    (*support_profile_tbl[table_index].connect_cnf_res_func_ptr) (dev_addr, MMI_FALSE);
                }
                break;
            }
            table_index++;
        }
        return;

    }
    else
    {

        /* get index of paired list */
        for (i = 0; i < g_mmi_bth_cntx.paired_dev_num; i++)
        {
            if (g_mmi_bth_cntx.paired_list[i].bd_addr.lap == lap
                && g_mmi_bth_cntx.paired_list[i].bd_addr.uap == uap && g_mmi_bth_cntx.paired_list[i].bd_addr.nap == nap)
            {
                break;
            }
        }

        /* add it into paired list */
        /* name of paired device is NULL, then update it or reget it */
        /* strlen will not count the NULL terminate byte */
        if (g_mmi_bth_cntx.paired_list[i].name[0] == 0)
        {
            dev_addr.uap = uap;
            dev_addr.lap = lap;
            dev_addr.nap = nap;
            mmi_bth_cm_read_remote_name_req_hdler(dev_addr);

        }

        /* update BT address */
        g_mmi_bth_cntx.paired_list[i].bd_addr.lap = lap;
        g_mmi_bth_cntx.paired_list[i].bd_addr.uap = uap;
        g_mmi_bth_cntx.paired_list[i].bd_addr.nap = nap;

        g_mmi_bth_cntx.action_index = i;
        g_mmi_bth_cntx.conn_cnf_profile_id = profile_id;
        MMI_BTH_STATE_TRANS(MMI_BTH_STAT_CONNECT_ACCEPT_CONFIRM_IND);

        if (i == g_mmi_bth_cntx.paired_dev_num)
        {
            g_mmi_bth_cntx.paired_dev_num++;
            /* write to NVRAM */
            mmi_bth_nvram_write_info();
            MMI_BT_ASSERT(g_mmi_bth_cntx.paired_dev_num <= MMI_BTH_MAX_PAIRED_DEVICE_LIST);
        }

        /* will send to bt screen while name is not NULL */
        if (g_mmi_bth_cntx.paired_list[i].name[0] != 0)
        {
            if (g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_connect_accept_cnf_req)
            {
                (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_connect_accept_cnf_req) ((U8*)g_mmi_bth_cntx.paired_list[i].name,
                                                                                   (U32)g_mmi_bth_cntx.paired_list[i].
                                                                                   bd_addr.uap,
                                                                                   (U8)g_mmi_bth_cntx.paired_list[i].
                                                                                   bd_addr.lap,
                                                                                   (U16)g_mmi_bth_cntx.paired_list[i].
                                                                                   bd_addr.nap, (U32)0xFFFFFFFF, 
                                                                                   (U32)profile_id);
            }
        }

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_connect_accept_confirm_failed_ind_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  lap             [IN]            
 *  uap             [IN]            
 *  nap             [IN]            
 *  profile_id      [IN]            
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_connect_accept_confirm_failed_ind_hdler(U32 lap, U8 uap, U16 nap, U32 profile_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* donothing */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_disconnect_cnf_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  result              [IN]            
 *  lap                 [IN]            
 *  uap                 [IN]            
 *  nap                 [IN]            
 *  profile_id          [IN]            
 *  connection_id       [IN]            
 *  a(?)                [IN/OUT]        First variable, used as returns
 *  b(?)                [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_disconnect_cnf_hdler(MMI_BOOL result, U32 lap, U8 uap, U16 nap, U32 profile_id, U32 connection_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_GEN_DISCONNECT_CNF,
               result,
               g_mmi_bth_cntx.state,
               profile_id,
               connection_id,
               ((nap & 0xff00) >> 8), (nap & 0x00ff),
               (uap), ((lap & 0xff0000) >> 16), ((lap & 0x00ff00) >> 8), (lap & 0x0000ff));


    if (result == MMI_TRUE)
    {
        /* get index of paired list */
        for (i = 0; i < g_mmi_bth_cntx.existed_conn_num; i++)
        {
            j = g_mmi_bth_cntx.existed_conn[i].index_of_paried_list;
            if (g_mmi_bth_cntx.paired_list[j].bd_addr.lap == lap
                && g_mmi_bth_cntx.paired_list[j].bd_addr.uap == uap
                && g_mmi_bth_cntx.paired_list[j].bd_addr.nap == nap
                && g_mmi_bth_cntx.existed_conn[i].conn_id == connection_id)
            {
                break;
            }
        }

        /* i cannot be equal to g_mmi_bth_cntx.paired_dev_num */
        /* if i=0 and g_mmi_bth_cntx.paired_dev_num=0, assert it */
        if ( /* i!=0 && */ i == g_mmi_bth_cntx.existed_conn_num)
        {
            MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_CONNECTION_NOT_FOUND,connection_id);
            MMI_BTH_STATE_TRANS(MMI_BTH_STAT_IDLE);
            return;
        }

        g_mmi_bth_cntx.existed_conn[i].active = MMI_FALSE;
        /* reset MMI_BTH_RAMMASK_IS_SWAP2BT flag */
        if (g_mmi_bth_cntx.existed_conn[i].audio_on == MMI_TRUE)
        {
            MMI_BTH_RESET_RAMFLAG(MMI_BTH_RAMMASK_IS_SWAP2BT);
        }

        /* remove this existed_conn */
        if (i == (g_mmi_bth_cntx.existed_conn_num - 1))
        {
            memset(&(g_mmi_bth_cntx.existed_conn[i]), 0, sizeof(mmi_bth_connect_struct));
        }
        else
        {
            for (j = i; j < g_mmi_bth_cntx.existed_conn_num - 1; j++)
            {
                memcpy(
                    &(g_mmi_bth_cntx.existed_conn[j]),
                    &(g_mmi_bth_cntx.existed_conn[j + 1]),
                    sizeof(mmi_bth_connect_struct));
            }
            memset(&(g_mmi_bth_cntx.existed_conn[j]), 0, sizeof(mmi_bth_connect_struct));

        }
        MMI_BT_ASSERT(g_mmi_bth_cntx.existed_conn_num);
        g_mmi_bth_cntx.existed_conn_num--;

        if (profile_id == MMI_BTH_ADVANCED_AUDIO_PROFILE_UUID)
        {
            /* to active the visibility while a2dp_prohibit_vis is TRUE */
            if (g_mmi_bth_cntx.a2dp_prohibit_vis == MMI_TRUE)
            {
                U8 page_inquiry_mode;

                g_mmi_bth_cntx.a2dp_prohibit_vis = MMI_FALSE;
                if (MMI_BTH_GET_FLAG(MMI_BTH_MASK_VIS))
                {
                    page_inquiry_mode = BTBM_ADP_P_ON_I_ON;
                }
                else
                {
                    page_inquiry_mode = BTBM_ADP_P_ON_I_OFF;
                }
                mmi_bth_cm_write_scanenable_mode_req_hdler(page_inquiry_mode, page_inquiry_mode);

            }
        }

    }

    switch (g_mmi_bth_cntx.state)
    {
        case MMI_BTH_STAT_RELEASE_ALL_CONNECTION:
            if (result == MMI_TRUE)
            {
                /* release connection again */
                if (mmi_bth_release_all_connection_req() == MMI_FALSE)
                {
                    /* all connections are released */
                    if (g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_release_all_conn)
                    {
                        (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_release_all_conn) (MMI_TRUE);
                    }
                    MMI_BTH_STATE_TRANS(MMI_BTH_STAT_IDLE);

                }
            }
            break;
        case MMI_BTH_STAT_RELEASE_DEV_CONNECTION:
            if (result == MMI_TRUE)
            {
                /* release connection again */
                if (mmi_bth_release_dev_connection_req
                    (&(g_mmi_bth_cntx.paired_list[g_mmi_bth_cntx.action_index].bd_addr)) == MMI_FALSE)
                {
                    /* all connections are released */
                    if (g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_release_all_conn)
                    {
                        (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_release_all_conn) (MMI_TRUE);
                    }
					 MMI_BTH_STATE_TRANS(MMI_BTH_STAT_IDLE);

                }
            }
            break;
        case MMI_BTH_STAT_RELEASE_OPP_CONNECTION:
            if (result == MMI_TRUE)
            {
                /* release connection again */
                if (mmi_bth_prohibit_opp_req() == MMI_FALSE)
                {
                    /* all opp connections are released */
                    if (g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_prohibit_services)
                    {
                        (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_prohibit_services) (MMI_TRUE);
                    }
                }
            }
            break;
        case MMI_BTH_STAT_RELEASE_FTP_CONNECTION:
            if (result == MMI_TRUE)
            {
                /* release connection again */
                if (mmi_bth_prohibit_ftp_req() == MMI_FALSE)
                {
                    /* all ftp connections are released */
                    if (g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_prohibit_services)
                    {
                        (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_prohibit_services) (MMI_TRUE);
                    }

                }
            }
            break;
        case MMI_BTH_STAT_DEACTIVATING:
            /* shall not callback UI while doing deactivating */
            break;
        default:
            MMI_BTH_STATE_TRANS(MMI_BTH_STAT_IDLE);
            if (g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_disconnect)
            {
                (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_disconnect) ((U32) mmi_bth_get_connection_type(profile_id),
                                                                       result);
            }
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_disconnect_ind_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  lap                 [IN]            
 *  uap                 [IN]            
 *  nap                 [IN]            
 *  profile_id          [IN]            
 *  connection_id       [IN]            
 *  a(?)                [IN/OUT]        First variable, used as returns
 *  b(?)                [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_disconnect_ind_hdler(U32 lap, U8 uap, U16 nap, U32 profile_id, U32 connection_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, j;
    mmi_bth_connection_type connection_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_GEN_DISCONNECT_IND,
               g_mmi_bth_cntx.state,
               profile_id,
               connection_id,
               ((nap & 0xff00) >> 8), (nap & 0x00ff),
               (uap), ((lap & 0xff0000) >> 16), ((lap & 0x00ff00) >> 8), (lap & 0x0000ff));

    /* to handle profile applications to callback disconnect indication and disconnect conf */
    /* skip the disconnect indication */
	if (g_mmi_bth_cntx.state == MMI_BTH_STAT_RELEASE_ALL_CONNECTION ||
		g_mmi_bth_cntx.state == MMI_BTH_STAT_RELEASE_DEV_CONNECTION )
	{
		if (profile_id == MMI_BTH_AV_REMOTE_CONTROL_TARGET_UUID)
		{
	        return;
		}
	}

    /* get index of paired list */
    for (i = 0; i < g_mmi_bth_cntx.existed_conn_num; i++)
    {
        j = g_mmi_bth_cntx.existed_conn[i].index_of_paried_list;
        if (g_mmi_bth_cntx.paired_list[j].bd_addr.lap == lap
            && g_mmi_bth_cntx.paired_list[j].bd_addr.uap == uap
            && g_mmi_bth_cntx.paired_list[j].bd_addr.nap == nap
            && g_mmi_bth_cntx.existed_conn[i].conn_id == connection_id)
        {
            break;
        }
    }

    /* i cannot be equal to g_mmi_bth_cntx.paired_dev_num */
    /* if i=0 and g_mmi_bth_cntx.paired_dev_num=0, assert it */
    if ( /* i!=0 && */ i == g_mmi_bth_cntx.existed_conn_num)
    {
        MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_CONNECTION_NOT_FOUND,connection_id);
        return;
    }

    g_mmi_bth_cntx.existed_conn[i].active = MMI_FALSE;

    /* reset MMI_BTH_RAMMASK_IS_SWAP2BT flag */
    if (g_mmi_bth_cntx.existed_conn[i].audio_on == MMI_TRUE)
    {
        MMI_BTH_RESET_RAMFLAG(MMI_BTH_RAMMASK_IS_SWAP2BT);
    }

    connection_type = g_mmi_bth_cntx.existed_conn[i].conn_type;

    /* remove this existed_conn */
    if (i == (g_mmi_bth_cntx.existed_conn_num - 1))
    {
        memset(&(g_mmi_bth_cntx.existed_conn[i]), 0, sizeof(mmi_bth_connect_struct));
    }
    else
    {
        for (j = i; j < g_mmi_bth_cntx.existed_conn_num - 1; j++)
        {
            memcpy(
                &(g_mmi_bth_cntx.existed_conn[j]),
                &(g_mmi_bth_cntx.existed_conn[j + 1]),
                sizeof(mmi_bth_connect_struct));
        }
        memset(&(g_mmi_bth_cntx.existed_conn[j]), 0, sizeof(mmi_bth_connect_struct));

    }
    MMI_BT_ASSERT(g_mmi_bth_cntx.existed_conn_num);
    g_mmi_bth_cntx.existed_conn_num--;

    switch (g_mmi_bth_cntx.state)
    {
        case MMI_BTH_STAT_RELEASE_ALL_CONNECTION:
			/* do nothing, just wait the mmi_bth_disconnect_cnf_hdler callback from profile application to disconnect the next active connection */
			/* if try to disconnec the connection here after receiving disconnect_ind, it may cause BT CM to disconnect the same profile connection twice, then cause assertion */
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
			#endif
            break;
        case MMI_BTH_STAT_RELEASE_DEV_CONNECTION:
			/* do nothing, just wait the mmi_bth_disconnect_cnf_hdler callback from profile application to disconnect the next active connection */
			/* if try to disconnec the connection here after receiving disconnect_ind, it may cause BT CM to disconnect the same profile connection twice, then cause assertion */
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
			#endif
            break;
        case MMI_BTH_STAT_RELEASE_OPP_CONNECTION:
            /* release connection again */
            if (mmi_bth_prohibit_opp_req() == MMI_FALSE)
            {
                /* all opp connections are released */
                if (g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_prohibit_services)
                {
                    (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_prohibit_services) (MMI_TRUE);
                }
            }
            break;
        case MMI_BTH_STAT_RELEASE_FTP_CONNECTION:
            /* release connection again */
            if (mmi_bth_prohibit_ftp_req() == MMI_FALSE)
            {
                /* all ftp connections are released */
                if (g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_prohibit_services)
                {
                    (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_prohibit_services) (MMI_TRUE);
                }

            }
            break;
        case MMI_BTH_STAT_DEACTIVATING:
            /* shall not callback UI while doing deactivating */
            break;

        default:
            if (g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_disconnect)
            {
                (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_disconnect) (connection_type, MMI_TRUE);
            }
            break;
    }

    if (profile_id == MMI_BTH_ADVANCED_AUDIO_PROFILE_UUID)
    {

        /* to active the visibility while a2dp_prohibit_vis is TRUE */
        if (g_mmi_bth_cntx.a2dp_prohibit_vis == MMI_TRUE)
        {
            U8 page_inquiry_mode;

            g_mmi_bth_cntx.a2dp_prohibit_vis = MMI_FALSE;
            if (MMI_BTH_GET_FLAG(MMI_BTH_MASK_VIS))
            {
                page_inquiry_mode = BTBM_ADP_P_ON_I_ON;
            }
            else
            {
                page_inquiry_mode = BTBM_ADP_P_ON_I_OFF;
            }
            if (g_mmi_bth_cntx.state != MMI_BTH_STAT_DEACTIVATING)
            {
                mmi_bth_cm_write_scanenable_mode_req_hdler(page_inquiry_mode, page_inquiry_mode);
            }
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_sco_connect_cnf_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  result              [IN]            
 *  connection_id       [IN]            
 *  a(?)                [IN/OUT]        First variable, used as returns
 *  b(?)                [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_sco_connect_cnf_hdler(U8 result, U32 connection_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_AUDIO_CON_CNF, result, g_mmi_bth_cntx.state, (~result), 0);

    switch (g_mmi_bth_cntx.state)
    {
        case MMI_BTH_STAT_RELEASE_ALL_CONNECTION:
        case MMI_BTH_STAT_RELEASE_DEV_CONNECTION:
            break;
        case MMI_BTH_STAT_DEACTIVATING:
        case MMI_BTH_STAT_ACTIVATING:
        case MMI_BTH_STAT_ACTIVATING_WRITE_SCAN_ENABLE:
        case MMI_BTH_STAT_ACTIVATING_WRITE_SCAN_DISABLE:
        case MMI_BTH_STAT_INQUIRING:
        case MMI_BTH_STAT_INQUIR_RES_IND:
        case MMI_BTH_STAT_BONDING:
        case MMI_BTH_STAT_PAIRING:
        case MMI_BTH_STAT_SDC_SEARCHING:
        case MMI_BTH_STAT_SDC_REFRESHING:
        case MMI_BTH_STAT_DEBONDING:
        case MMI_BTH_STAT_DEBONDING_ALL:
        case MMI_BTH_STAT_PASSKEY_IND:
        case MMI_BTH_STAT_PASSKEY_RES:
            /* do nothing */
            break;
        default:
            //MMI_BTH_STATE_TRANS(MMI_BTH_STAT_IDLE);
            break;
    }

    for (i = 0; i < g_mmi_bth_cntx.existed_conn_num; i++)
    {
        if (g_mmi_bth_cntx.existed_conn[i].conn_id == connection_id)
        {
            break;
        }
    }

    /* cannot find this connection */
    if (i == g_mmi_bth_cntx.existed_conn_num)
    {
        MMI_BTH_RESET_RAMFLAG(MMI_BTH_RAMMASK_IS_SWAP2BT);
        if (g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_sco_ind)
        {
            (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_sco_ind) (MMI_FALSE);
        }
        return;
    }

    if (!result)
    {
        MMI_BTH_SET_RAMFLAG(MMI_BTH_RAMMASK_IS_SWAP2BT);
        g_mmi_bth_cntx.existed_conn[i].audio_on = MMI_TRUE;
    }

    if (!result)
    {
        if (g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_sco_ind)
        {
            (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_sco_ind) (g_mmi_bth_cntx.existed_conn[i].audio_on);
        }
    }
    else
    {
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
        /* notify speech path for end user */        
        if (g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_sco_ind)
        {
            (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_sco_ind) (g_mmi_bth_cntx.existed_conn[i].audio_on);
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_sco_connect_ind_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  connection_id       [IN]            
 *  a(?)                [IN/OUT]        First variable, used as returns
 *  b(?)                [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_sco_connect_ind_hdler(U32 connection_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_AUDIO_CON_IND, g_mmi_bth_cntx.state, MMI_TRUE, 0);

    switch (g_mmi_bth_cntx.state)
    {
        case MMI_BTH_STAT_RELEASE_ALL_CONNECTION:
        case MMI_BTH_STAT_RELEASE_DEV_CONNECTION:
            break;
        case MMI_BTH_STAT_DEACTIVATING:
        case MMI_BTH_STAT_ACTIVATING:
        case MMI_BTH_STAT_ACTIVATING_WRITE_SCAN_ENABLE:
        case MMI_BTH_STAT_ACTIVATING_WRITE_SCAN_DISABLE:
        case MMI_BTH_STAT_INQUIRING:
        case MMI_BTH_STAT_INQUIR_RES_IND:
        case MMI_BTH_STAT_BONDING:
        case MMI_BTH_STAT_PAIRING:
        case MMI_BTH_STAT_SDC_SEARCHING:
        case MMI_BTH_STAT_SDC_REFRESHING:
        case MMI_BTH_STAT_DEBONDING:
        case MMI_BTH_STAT_DEBONDING_ALL:
        case MMI_BTH_STAT_PASSKEY_IND:
        case MMI_BTH_STAT_PASSKEY_RES:
            /* do nothing */
            break;
        default:
            //MMI_BTH_STATE_TRANS(MMI_BTH_STAT_IDLE);
            break;
    }

    for (i = 0; i < g_mmi_bth_cntx.existed_conn_num; i++)
    {
        if (g_mmi_bth_cntx.existed_conn[i].conn_id == connection_id)
        {
            break;
        }
    }

    /* cannot find this connection */
    if (i == g_mmi_bth_cntx.existed_conn_num)
    {
        MMI_BTH_RESET_RAMFLAG(MMI_BTH_RAMMASK_IS_SWAP2BT);
        if (g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_sco_ind)
        {
            (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_sco_ind) (MMI_FALSE);
        }
        return;
    }

    MMI_BTH_SET_RAMFLAG(MMI_BTH_RAMMASK_IS_SWAP2BT);

    g_mmi_bth_cntx.existed_conn[i].audio_on = MMI_TRUE;

    if (g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_sco_ind)
    {
        (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_sco_ind) (g_mmi_bth_cntx.existed_conn[i].audio_on);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_sco_disconnect_cnf_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  result              [IN]            
 *  connection_id       [IN]            
 *  a(?)                [IN/OUT]        First variable, used as returns
 *  b(?)                [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_sco_disconnect_cnf_hdler(U8 result, U32 connection_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_AUDIO_DISCON_CNF,
               result, g_mmi_bth_cntx.state, (~result), 0);

    switch (g_mmi_bth_cntx.state)
    {
        case MMI_BTH_STAT_RELEASE_ALL_CONNECTION:
        case MMI_BTH_STAT_RELEASE_DEV_CONNECTION:
            break;
        case MMI_BTH_STAT_DEACTIVATING:
        case MMI_BTH_STAT_ACTIVATING:
        case MMI_BTH_STAT_ACTIVATING_WRITE_SCAN_ENABLE:
        case MMI_BTH_STAT_ACTIVATING_WRITE_SCAN_DISABLE:
        case MMI_BTH_STAT_INQUIRING:
        case MMI_BTH_STAT_INQUIR_RES_IND:
        case MMI_BTH_STAT_BONDING:
        case MMI_BTH_STAT_PAIRING:
        case MMI_BTH_STAT_SDC_SEARCHING:
        case MMI_BTH_STAT_SDC_REFRESHING:
        case MMI_BTH_STAT_DEBONDING:
        case MMI_BTH_STAT_DEBONDING_ALL:
        case MMI_BTH_STAT_PASSKEY_IND:
        case MMI_BTH_STAT_PASSKEY_RES:
            /* do nothing */
            break;
        default:
            //MMI_BTH_STATE_TRANS(MMI_BTH_STAT_IDLE);
            break;
    }

    for (i = 0; i < g_mmi_bth_cntx.existed_conn_num; i++)
    {
        if (g_mmi_bth_cntx.existed_conn[i].conn_id == connection_id)
        {
            break;
        }
    }

    /* cannot find this connection */
    if (i == g_mmi_bth_cntx.existed_conn_num)
    {
        if (!result)
        {
            MMI_BTH_RESET_RAMFLAG(MMI_BTH_RAMMASK_IS_SWAP2BT);
            if (g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_sco_ind)
            {
                (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_sco_ind) (MMI_FALSE);
            }
        }
        else
        {
        
            if (g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_sco_ind)
            {
                (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_sco_ind) (MMI_TRUE);
            }

        }
        return;
    }

    if (!result)
    {
        MMI_BTH_RESET_RAMFLAG(MMI_BTH_RAMMASK_IS_SWAP2BT);
        g_mmi_bth_cntx.existed_conn[i].audio_on = MMI_FALSE;
    }

    switch (g_mmi_bth_cntx.state)
    {
        case MMI_BTH_STAT_RELEASE_ALL_CONNECTION:

            /* release connection again */
            if (mmi_bth_release_all_connection_req() == MMI_FALSE)
            {
                /* all connections are released */
                if (g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_release_all_conn)
                {
                    (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_release_all_conn) (MMI_TRUE);
                }
                MMI_BTH_STATE_TRANS(MMI_BTH_STAT_IDLE);

            }
            break;
        case MMI_BTH_STAT_RELEASE_DEV_CONNECTION:

            /* release connection again */
            if (mmi_bth_release_dev_connection_req(&(g_mmi_bth_cntx.paired_list[g_mmi_bth_cntx.action_index].bd_addr))
                == MMI_FALSE)
            {
                /* all connections are released */
                if (g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_release_all_conn)
                {
                    (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_release_all_conn) (MMI_TRUE);
                }
                MMI_BTH_STATE_TRANS(MMI_BTH_STAT_IDLE);

            }
            break;

        default:
            if (!result)
            {
                if (g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_sco_ind)
                {
                    (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_sco_ind) (g_mmi_bth_cntx.existed_conn[i].audio_on);
                }
            }
            else
            {
                #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                #endif
                /* notify speech path for end user */        
                if (g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_sco_ind)
                {
                    (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_sco_ind) (g_mmi_bth_cntx.existed_conn[i].audio_on);
                }
            }
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_sco_disconnect_ind_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  connection_id       [IN]            
 *  a(?)                [IN/OUT]        First variable, used as returns
 *  b(?)                [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_sco_disconnect_ind_hdler(U32 connection_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_AUDIO_DISCON_IND, g_mmi_bth_cntx.state, MMI_FALSE, 0);

    switch (g_mmi_bth_cntx.state)
    {
        case MMI_BTH_STAT_RELEASE_ALL_CONNECTION:
        case MMI_BTH_STAT_RELEASE_DEV_CONNECTION:
            /* do nothing */
            break;
        case MMI_BTH_STAT_DEACTIVATING:
        case MMI_BTH_STAT_ACTIVATING:
        case MMI_BTH_STAT_ACTIVATING_WRITE_SCAN_ENABLE:
        case MMI_BTH_STAT_ACTIVATING_WRITE_SCAN_DISABLE:
        case MMI_BTH_STAT_INQUIRING:
        case MMI_BTH_STAT_INQUIR_RES_IND:
        case MMI_BTH_STAT_BONDING:
        case MMI_BTH_STAT_PAIRING:
        case MMI_BTH_STAT_SDC_SEARCHING:
        case MMI_BTH_STAT_SDC_REFRESHING:
        case MMI_BTH_STAT_DEBONDING:
        case MMI_BTH_STAT_DEBONDING_ALL:
        case MMI_BTH_STAT_PASSKEY_IND:
        case MMI_BTH_STAT_PASSKEY_RES:
            /* do nothing */
            break;
        default:
            //MMI_BTH_STATE_TRANS(MMI_BTH_STAT_IDLE);
            break;
    }

    MMI_BTH_RESET_RAMFLAG(MMI_BTH_RAMMASK_IS_SWAP2BT);

    for (i = 0; i < g_mmi_bth_cntx.existed_conn_num; i++)
    {
        if (g_mmi_bth_cntx.existed_conn[i].conn_id == connection_id)
        {
            break;
        }
    }

    /* cannot find this connection */
    if (i == g_mmi_bth_cntx.existed_conn_num)
    {
        if (g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_sco_ind)
        {
            (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_sco_ind) (MMI_FALSE);
        }
        return;
    }

    g_mmi_bth_cntx.existed_conn[i].audio_on = MMI_FALSE;

    if (g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_sco_ind)
    {
        (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_sco_ind) (g_mmi_bth_cntx.existed_conn[i].audio_on);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_profile_callback_before_release_connection_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  lap                 [IN]        BD address, if no idea, pls set to 0
 *  uap                 [IN]        BD address, if no idea, pls set to 0
 *  nap                 [IN]        BD address, if no idea, pls set to 0
 *  profile_id          [IN]        Profile uuid
 *  connection_id       [IN]        Profile connection id, if no idea, pls set to 0xFFFFFFFF
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_profile_callback_before_release_connection_hdler(
        U32 lap,
        U8 uap,
        U16 nap,
        U32 profile_id,
        U32 connection_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, j;
    U32 connect_id = connection_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_PROF_CB_BEFORE_CON_DIS,
               g_mmi_bth_cntx.state,
               profile_id,
               connection_id,
               ((nap & 0xff00) >> 8), (nap & 0x00ff),
               (uap), ((lap & 0xff0000) >> 16), ((lap & 0x00ff00) >> 8), (lap & 0x0000ff));

    if ((lap == 0 && uap == 0 && nap == 0) || (connection_id == 0xFFFFFFFF))
    {
        /* a2dp audio stream closed before a2dp disconnected indication */
        return;
        mmi_bth_get_active_a2dp_infor(profile_id, &lap, &uap, &nap, &connect_id);
        connection_id = connect_id;
    }

    /* get index of paired list */
    for (i = 0; i < g_mmi_bth_cntx.existed_conn_num; i++)
    {
        j = g_mmi_bth_cntx.existed_conn[i].index_of_paried_list;
        if (g_mmi_bth_cntx.paired_list[j].bd_addr.lap == lap
            && g_mmi_bth_cntx.paired_list[j].bd_addr.uap == uap
            && g_mmi_bth_cntx.paired_list[j].bd_addr.nap == nap
            && g_mmi_bth_cntx.existed_conn[i].conn_id == connection_id)
        {
            break;
        }
    }

    /* i cannot be equal to g_mmi_bth_cntx.existed_conn_num */
    /* if i=0 and g_mmi_bth_cntx.existed_conn_num=0, assert it */
    if ( /* i!=0 && */ i == g_mmi_bth_cntx.existed_conn_num)
    {
        MMI_BT_ASSERT(0);
    }

    switch (g_mmi_bth_cntx.state)
    {
        case MMI_BTH_STAT_RELEASE_ALL_CONNECTION:
            /* release connection again */
            if (mmi_bth_release_all_connection_req() == MMI_FALSE)
            {
                /* all connections are released */
                if (g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_release_all_conn)
                {
                    (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_release_all_conn) (MMI_TRUE);
                }
				 MMI_BTH_STATE_TRANS(MMI_BTH_STAT_IDLE);

            }
            break;
        case MMI_BTH_STAT_RELEASE_DEV_CONNECTION:
            /* release connection again */
            if (mmi_bth_release_dev_connection_req(&(g_mmi_bth_cntx.paired_list[g_mmi_bth_cntx.action_index].bd_addr))
                == MMI_FALSE)
            {
                /* all connections are released */
                if (g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_release_all_conn)
                {
                    (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_release_all_conn) (MMI_TRUE);
                }
                MMI_BTH_STATE_TRANS(MMI_BTH_STAT_IDLE);

            }
            break;
        default:
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_is_activated
 * DESCRIPTION
 *  This function is to check if bt is activated
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bth_is_activated(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_BTH_GET_FLAG(MMI_BTH_MASK_ACTIVATED);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_is_panic
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bth_is_panic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_bth_get_state() == MMI_BTH_STAT_PANIC_RECOVERING)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_is_vis
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bth_is_vis(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_BTH_GET_FLAG(MMI_BTH_MASK_VIS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_is_auth
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bth_is_auth(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_BTH_GET_FLAG(MMI_BTH_MASK_AUTH);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_is_aud_pth_set_to_hf
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bth_is_aud_pth_set_to_hf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_BTH_GET_FLAG(MMI_BTH_MASK_AUDPATH);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_is_incall_aud_swap2bt
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bth_is_incall_aud_swap2bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_BTH_GET_RAMFLAG(MMI_BTH_RAMMASK_IS_SWAP2BT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_is_hs_connected
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bth_is_hs_connected(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_mmi_bth_cntx.existed_conn_num; i++)
    {
        switch (g_mmi_bth_cntx.existed_conn[i].conn_type)
        {
            case MMI_BTH_HFP_CONNECTION:
            case MMI_BTH_HSP_CONNECTION:
                if (g_mmi_bth_cntx.existed_conn[i].active == MMI_TRUE)
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
 *  mmi_bth_is_hs_audio_link_connected
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bth_is_hs_audio_link_connected(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_mmi_bth_cntx.existed_conn_num; i++)
    {
        switch (g_mmi_bth_cntx.existed_conn[i].conn_type)
        {
            case MMI_BTH_HFP_CONNECTION:
            case MMI_BTH_HSP_CONNECTION:
                if (g_mmi_bth_cntx.existed_conn[i].audio_on == MMI_TRUE)
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
 *  mmi_bth_is_hsp_connected
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bth_is_hsp_connected(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_mmi_bth_cntx.existed_conn_num; i++)
    {
        switch (g_mmi_bth_cntx.existed_conn[i].conn_type)
        {
            case MMI_BTH_HSP_CONNECTION:
                if (g_mmi_bth_cntx.existed_conn[i].active == MMI_TRUE)
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
 *  mmi_bth_is_hfp_connected
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bth_is_hfp_connected(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_mmi_bth_cntx.existed_conn_num; i++)
    {
        switch (g_mmi_bth_cntx.existed_conn[i].conn_type)
        {
            case MMI_BTH_HFP_CONNECTION:
                if (g_mmi_bth_cntx.existed_conn[i].active == MMI_TRUE)
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
 *  mmi_bth_is_any_connection_active
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bth_is_any_connection_active(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_mmi_bth_cntx.existed_conn_num; i++)
    {
        if (g_mmi_bth_cntx.existed_conn[i].active == MMI_TRUE)
        {
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_is_connection_active
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  dev_add_p       [?]             
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bth_is_connection_active(mmi_bth_bt_addr *dev_add_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, j;
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_mmi_bth_cntx.paired_dev_num; i++)
    {
        if (g_mmi_bth_cntx.paired_list[i].bd_addr.lap == dev_add_p->lap
            && g_mmi_bth_cntx.paired_list[i].bd_addr.uap == dev_add_p->uap
            && g_mmi_bth_cntx.paired_list[i].bd_addr.nap == dev_add_p->nap)
        {
            break;
        }
    }

    if (i == g_mmi_bth_cntx.paired_dev_num)
    {
        result = MMI_FALSE;
    }
    else
    {
        for (j = 0; j < g_mmi_bth_cntx.existed_conn_num; j++)
        {
            if (g_mmi_bth_cntx.existed_conn[j].index_of_paried_list == i
                && g_mmi_bth_cntx.existed_conn[j].active == MMI_TRUE)
            {
                result = MMI_TRUE;
            }
        }

    }

    return result;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bth_is_simap_activate
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bth_is_simap_activate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_bth_cntx.deactivate_flag & MMI_BTH_SIMAP_DEACTIVATED)
    {
        result = MMI_FALSE;
    }
    else
    {
        result = MMI_TRUE;
    }

    
    return result;
}

/* Configure Default Headset */
/*****************************************************************************
 * FUNCTION
 *  mmi_bth_is_service_support
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bth_is_service_support(U32 paired_index, U32 service_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
    U32 service_num;
    U32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BT_ASSERT(paired_index < g_mmi_bth_cntx.paired_dev_num);

    service_num = g_mmi_bth_cntx.paired_list[paired_index].service_list_num;
    
	for (i=0; i < service_num; i++)
	{
		if (g_mmi_bth_cntx.paired_list[paired_index].service_list[i] == service_id)
		{
		    result = MMI_TRUE;
		    break;
		}
    }

    return result;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_get_state
 * DESCRIPTION
 *  This function is to get current bluetooth state
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
mmi_bth_state_enum mmi_bth_get_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mmi_bth_cntx.state;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_get_host_dev_info
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
mmi_bth_dev_struct *mmi_bth_get_host_dev_info()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &(g_mmi_bth_cntx.host_dev);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_get_discov_dev_num
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_bth_get_discov_dev_num()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mmi_bth_cntx.discovered_dev_num;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_get_discov_dev_info
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  index       [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
mmi_bth_dev_struct *mmi_bth_get_discov_dev_info(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &(g_mmi_bth_cntx.discovered_list[index]);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_get_paired_dev_num
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_bth_get_paired_dev_num()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mmi_bth_cntx.paired_dev_num;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_get_paired_dev_info
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  index       [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
mmi_bth_dev_struct *mmi_bth_get_paired_dev_info(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &(g_mmi_bth_cntx.paired_list[index]);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_get_existed_dev_num
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_bth_get_existed_dev_num()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mmi_bth_cntx.existed_conn_num;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_get_existed_dev_info
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  index       [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
mmi_bth_dev_struct *mmi_bth_get_existed_dev_info(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BT_ASSERT(index == 0 || index < g_mmi_bth_cntx.existed_conn_num);
    i = g_mmi_bth_cntx.existed_conn[index].index_of_paried_list;
    MMI_BT_ASSERT(i < g_mmi_bth_cntx.paired_dev_num);

    return mmi_bth_get_paired_dev_info(i);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_get_existed_connect_info
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  index       [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
mmi_bth_connect_struct *mmi_bth_get_existed_connect_info(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BT_ASSERT(index == 0 || index < g_mmi_bth_cntx.existed_conn_num);

    return &(g_mmi_bth_cntx.existed_conn[index]);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_get_action_item_index
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_bth_get_action_item_index()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mmi_bth_cntx.action_index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_get_ram_flag
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  get_flag        [IN]            
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
U32 mmi_bth_get_ram_flag(U32 get_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_BTH_GET_RAMFLAG(get_flag);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_get_active_hfp_connect_id
 * DESCRIPTION
 *  This function is to get current active hfp/hsp connection id
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_bth_get_active_hfp_connect_id()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* assume that there is only one active HFP or HSP connection in active connection  list */
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_mmi_bth_cntx.existed_conn_num; i++)
    {
        switch (g_mmi_bth_cntx.existed_conn[i].conn_type)
        {
            case MMI_BTH_HFP_CONNECTION:
            case MMI_BTH_HSP_CONNECTION:
                if (g_mmi_bth_cntx.existed_conn[i].active == MMI_TRUE)
                {
                    return g_mmi_bth_cntx.existed_conn[i].conn_id;
                }
                break;
            default:
                break;

        }
    }
    /* cannot find the connection id */
    /* i cannot be equal to g_mmi_bth_cntx.existed_conn_num */
    /* if i=0 and g_mmi_bth_cntx.existed_conn_num=0, assert it */
    MMI_BT_ASSERT(i != g_mmi_bth_cntx.existed_conn_num);
    // return connection id with 0xff/*zero*/ if cannot find HFP/HSP connection
    return 0xff;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_get_sco_status
 * DESCRIPTION
 *  This function is to get sco status
 * PARAMETERS
 *  conn_id     [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bth_get_sco_status(U32 conn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_mmi_bth_cntx.existed_conn_num; i++)
    {
        if (g_mmi_bth_cntx.existed_conn[i].conn_id == conn_id && g_mmi_bth_cntx.existed_conn[i].active == MMI_TRUE)
        {
            return g_mmi_bth_cntx.existed_conn[i].audio_on;
        }
    }
    /* i cannot be equal to g_mmi_bth_cntx.existed_conn_num */
    /* if i=0 and g_mmi_bth_cntx.existed_conn_num=0, assert it */
    MMI_BT_ASSERT(i != g_mmi_bth_cntx.existed_conn_num);
    /* return MMI_FALSE if cannot find this connection */
    return MMI_FALSE;
}


/* Configure Default Headset */
/*****************************************************************************
 * FUNCTION
 *  mmi_bth_get_default_hs_index
 * DESCRIPTION
 *  This function is to get 
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
U32 mmi_bth_get_default_hs_index(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mmi_bth_cntx.idx_of_last_hs_dev;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_antenna_off_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bth_antenna_off_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reset BTH ready flag */
    MMI_BTH_RESET_RAMFLAG(MMI_BTH_RAMMASK_IS_READY);

    /* disable write scan enable(page off, inquiry off) */
    /* ->deactivate profiles */
    /* ->antenna off */
    /* antenna off */
    mmi_bth_antenna_off_req_hdler();
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_antenna_on_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bth_antenna_on_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reset BTH ready flag */
    MMI_BTH_RESET_RAMFLAG(MMI_BTH_RAMMASK_IS_READY);

    /* antenna on req->disable write scan enable(page off, inquiry off) */
    /* ->read BT address->set local name->set security->activate profiles */
    /* ->enable write scan mode */
    /* antenna on */
    mmi_bth_antenna_on_req_hdler();
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_restart_bt_module_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bth_restart_bt_module_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* restart_req_ind->reset_req->reset_cnf */
    /* restart_req->restart_req_ind->reset_req->reset_cnf */
    mmi_bth_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_RESTART_REQ, NULL, NULL);
    /* SetProtocolEventHandler(mmi_bth_restart_req_ind_hdler, MSG_ID_BT_RESET_REQ_IND); */
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_recover_panic_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bth_recover_panic_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* restart_req_ind->reset_req->reset_cnf */
    /* restart_req->restart_req_ind->reset_req->reset_cnf */
    mmi_bth_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_MMI_RESET_REQ, NULL, NULL);
    /* SetProtocolEventHandler(mmi_bth_restart_rsp_hdler,  MSG_ID_BT_MMI_RESET_CNF); */
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_deactivate_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bth_deactivate_req()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_DEACTIVATE_FLAG, g_mmi_bth_cntx.deactivate_flag);
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_CORE_STATUS,
               g_mmi_bth_cntx.state, g_mmi_bth_cntx.flag, g_mmi_bth_cntx.ram_flag, g_mmi_bth_cntx.deactivate_flag);

    if (g_mmi_bth_cntx.state != MMI_BTH_STAT_DEACTIVATING)
    {
        /* reset BTH ready flag */
        MMI_BTH_RESET_RAMFLAG(MMI_BTH_RAMMASK_IS_READY);

        MMI_BTH_STATE_TRANS(MMI_BTH_STAT_DEACTIVATING);
        /* disallow acl link establishment */
        /* ->disable write scan enable(page off, inquiry off) */
        /* ->deactivate profiles */
        /* ->antenna off */
        /* disallow acl link establishment */
        mmi_bth_cm_disallow_acl_link_establishment_req_hdler();
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_deactivate_profiles_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_deactivate_profiles_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_DEACTIVATE_FLAG, g_mmi_bth_cntx.deactivate_flag);

    while (support_profile_tbl[i].uuid != MMI_BTH_MAX_PROFILE_UUID)
    {
        if ((!(g_mmi_bth_cntx.deactivate_flag & (support_profile_tbl[i].deactivate_flag))))
        {
            if (support_profile_tbl[i].deactivate_func_ptr)
            {
                (*support_profile_tbl[i].deactivate_func_ptr) ();
            }
            else if(!(g_mmi_bth_cntx.deactivate_flag & MMI_BTH_SIMAP_DEACTIVATED) &&
					support_profile_tbl[i].uuid == MMI_BTH_SIM_ACCESS_PROFILE_UUID)
            {
                #ifdef __MMI_SIMAP_SUPPORT__
                mmi_bth_simap_deactivate_req_hdler();
                #endif
            }            
        }
        i++;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_activate_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bth_activate_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_DEACTIVATE_FLAG, g_mmi_bth_cntx.deactivate_flag);

    MMI_BTH_STATE_TRANS(MMI_BTH_STAT_ACTIVATING);

    /* reset BTH ready flag */
    MMI_BTH_RESET_RAMFLAG(MMI_BTH_RAMMASK_IS_READY);

    /* antenna on req->disable write scan enable(page off, inquiry off) */
    /* ->read BT address->set local name->set security->activate profiles */
    /* ->enable write scan mode */
    /* read BT address */
    mmi_bth_cm_read_local_bd_addr_req_hdler();

    return MMI_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_activate_profiles_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_activate_profiles_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_DEACTIVATE_FLAG, g_mmi_bth_cntx.deactivate_flag);

    while (support_profile_tbl[i].uuid != MMI_BTH_MAX_PROFILE_UUID)
    {
        if ((g_mmi_bth_cntx.deactivate_flag & (support_profile_tbl[i].deactivate_flag)))
        {
            if (support_profile_tbl[i].activate_func_ptr)
            {
                (*support_profile_tbl[i].activate_func_ptr) ();
            }
        }
        i++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_release_all_connection_req
 * DESCRIPTION
 *  This function is to get current bluetooth state
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bth_release_all_connection_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_mmi_bth_cntx.existed_conn_num; i++)
    {
        if (g_mmi_bth_cntx.existed_conn[i].active == MMI_TRUE)
        {
            {
                {
                    mmi_bth_disconnect_req(
                        g_mmi_bth_cntx.existed_conn[i].conn_id,
                        g_mmi_bth_cntx.existed_conn[i].conn_type);
                }
                result = MMI_TRUE;
                /* mmi_bth_hfg_audio_req or mmi_bth_disconnect_req will change the state */
                /* so assign the state here */
                MMI_BTH_STATE_TRANS(MMI_BTH_STAT_RELEASE_ALL_CONNECTION);
                break;
            }
        }
    }


    if (i == g_mmi_bth_cntx.existed_conn_num)
    {
        result = MMI_FALSE;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_release_dev_connection_req
 * DESCRIPTION
 *  This function is to get current bluetooth state
 * PARAMETERS
 *  dev_add_p       [?]             
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bth_release_dev_connection_req(mmi_bth_bt_addr *dev_add_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, j;
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_mmi_bth_cntx.paired_dev_num; i++)
    {
        if (g_mmi_bth_cntx.paired_list[i].bd_addr.lap == dev_add_p->lap
            && g_mmi_bth_cntx.paired_list[i].bd_addr.uap == dev_add_p->uap
            && g_mmi_bth_cntx.paired_list[i].bd_addr.nap == dev_add_p->nap)
        {
            break;
        }
    }

    if (i == g_mmi_bth_cntx.paired_dev_num)
    {
        result = MMI_FALSE;
    }
    else
    {
        /* save the index of paired list to action_index for release dev connections */
        /* XXX disconnected ind will use this index to get dev_addr for releasing next connection */
        g_mmi_bth_cntx.action_index = i;

        for (j = 0; j < g_mmi_bth_cntx.existed_conn_num; j++)
        {
            if (g_mmi_bth_cntx.existed_conn[j].index_of_paried_list == i
                && g_mmi_bth_cntx.existed_conn[j].active == MMI_TRUE)
            {
                {
                    {
                        mmi_bth_disconnect_req(
                            g_mmi_bth_cntx.existed_conn[j].conn_id,
                            g_mmi_bth_cntx.existed_conn[j].conn_type);
                    }
                    result = MMI_TRUE;
                    MMI_BTH_STATE_TRANS(MMI_BTH_STAT_RELEASE_DEV_CONNECTION);
                    break;
                }
            }
        }

        if (j == g_mmi_bth_cntx.existed_conn_num)
        {
            result = MMI_FALSE;
        }

    }


    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_inquiry_req
 * DESCRIPTION
 *  This function is to get current bluetooth state
 * PARAMETERS
 *  max_response        [IN]            
 *  timeout             [IN]            
 *  cod                 [IN]            
 *  name_discovery      [IN]            
 *  inquiry_type        [IN]            
 *  a(?)                [IN/OUT]        First variable, used as returns
 *  b(?)                [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bth_inquiry_req(U8 max_response, U16 timeout, U32 cod, MMI_BOOL name_discovery, U8 inquiry_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bth_cm_discovery_req_hdler(max_response, timeout, cod, name_discovery);

    /* reset discovered device counter */
    g_mmi_bth_cntx.discovered_dev_num = 0;
    MMI_BTH_STATE_TRANS(MMI_BTH_STAT_INQUIRING);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_inquiry_cancel_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  inquiry_type        [IN]            
 *  a(?)                [IN/OUT]        First variable, used as returns
 *  b(?)                [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bth_inquiry_cancel_req(U8 inquiry_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bth_cm_cancel_discovery_req_hdler();
    return MMI_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_bond_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  index       [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bth_bond_req(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U16 sdap_uuid[(sizeof(inquiry_profile_tbl) / sizeof(U32))];

    mmi_bth_bt_addr dev_addr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* store scr hilight_item to action_item */
    /* BTMMIScr will use this index to know the index of paried list */
    g_mmi_bth_cntx.action_index = index;

    dev_addr = (g_mmi_bth_cntx.discovered_list[index].bd_addr);
    for (i = 0; i < (sizeof(inquiry_profile_tbl) / sizeof(U32)); i++)
    {
        sdap_uuid[i] = inquiry_profile_tbl[i];
    }

    mmi_bth_cm_bond_req_hdler(dev_addr, (((sizeof(inquiry_profile_tbl) / sizeof(U32))) - 1), sdap_uuid);
    //SetProtocolEventHandler(mmi_bth_cm_bond_ind_hdler, MSG_ID_BT_BM_BONDING_RESULT_IND);
    //SetProtocolEventHandler(mmi_bth_cm_bond_cnf_hdler, MSG_ID_BT_BM_BONDING_CNF);
    //SetProtocolEventHandler(mmi_bth_cm_passkey_ind_hdler, MSG_ID_BT_BM_PIN_CODE_IND);
    MMI_BTH_STATE_TRANS(MMI_BTH_STAT_BONDING);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_pair_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  dev_addr        [?]             
 *  dev_passkey     [?]             
 *  result          [IN]            
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bth_pair_req(mmi_bth_bt_addr *dev_addr, U8 *dev_passkey, MMI_BOOL result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 pin_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_CORE_STATUS,
               g_mmi_bth_cntx.state, g_mmi_bth_cntx.flag, g_mmi_bth_cntx.ram_flag, g_mmi_bth_cntx.deactivate_flag);
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_PAIR_RSP,
               g_mmi_bth_cntx.state,
               ((dev_addr->nap & 0xff00) >> 8), (dev_addr->nap & 0x00ff),
               (dev_addr->uap),
               ((dev_addr->lap & 0xff0000) >> 16), ((dev_addr->lap & 0x00ff00) >> 8),
               (dev_addr->lap & 0x0000ff));
    
    if (result)
    {
        pin_len = strlen((const char*)dev_passkey);
    }
    else
    {
        pin_len = 0;
    }

    mmi_bth_cm_passkey_ind_rsp_hdler((*dev_addr), pin_len, dev_passkey);
    /* SetProtocolEventHandler(mmi_bth_cm_bond_ind_hdler, MSG_ID_BT_BM_BONDING_RESULT_IND); */
    if (g_mmi_bth_cntx.state == MMI_BTH_STAT_PASSKEY_IND)
    {
        /* waiting for bond ind result */
        MMI_BTH_STATE_TRANS(MMI_BTH_STAT_PASSKEY_RES);

    }

    return MMI_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_refresh_service_list_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  dev_addr        [?]             
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bth_refresh_service_list_req(mmi_bth_bt_addr *dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U16 sdap_uuid[(sizeof(inquiry_profile_tbl) / sizeof(U32))];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_mmi_bth_cntx.paired_dev_num; i++)
    {
        if (g_mmi_bth_cntx.paired_list[i].bd_addr.lap == dev_addr->lap
            && g_mmi_bth_cntx.paired_list[i].bd_addr.uap == dev_addr->uap
            && g_mmi_bth_cntx.paired_list[i].bd_addr.nap == dev_addr->nap)
        {
            break;
        }
    }

    /* i cannot be equal to g_mmi_bth_cntx.paired_dev_num */
    /* if i=0 and g_mmi_bth_cntx.paired_dev_num=0, assert it */
    MMI_BT_ASSERT( /* i==0 || */ i != g_mmi_bth_cntx.paired_dev_num);

    /* reset original service list num */
	g_mmi_bth_cntx.stored_ser_list_num = g_mmi_bth_cntx.paired_list[i].service_list_num;
    g_mmi_bth_cntx.paired_list[i].service_list_num = 0;

    for (i = 0; i < (sizeof(inquiry_profile_tbl) / sizeof(U32)); i++)
    {
        sdap_uuid[i] = inquiry_profile_tbl[i];
    }

    /* start the SDC searching */
    mmi_bth_cm_sdc_search_req_hdler((*dev_addr), (((sizeof(inquiry_profile_tbl) / sizeof(U32))) - 1), sdap_uuid);

    MMI_BTH_STATE_TRANS(MMI_BTH_STAT_SDC_REFRESHING);

    return MMI_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_connect_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  dev_addr        [?]             
 *  profile_id      [IN]            
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bth_connect_req(mmi_bth_bt_addr *dev_addr, U32 profile_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U32 paired_index, table_index;
    U32 supported_profile_uuid;
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (paired_index = 0; paired_index < g_mmi_bth_cntx.paired_dev_num; paired_index++)
    {
        if (g_mmi_bth_cntx.paired_list[paired_index].bd_addr.lap == dev_addr->lap
            && g_mmi_bth_cntx.paired_list[paired_index].bd_addr.uap == dev_addr->uap
            && g_mmi_bth_cntx.paired_list[paired_index].bd_addr.nap == dev_addr->nap)
        {
            break;
        }
    }

    /* paired_index cannot be equal to g_mmi_bth_cntx.paired_dev_num */
    /* if paired_index=0 and g_mmi_bth_cntx.paired_dev_num=0, assert it */
    MMI_BT_ASSERT(paired_index != g_mmi_bth_cntx.paired_dev_num);

    /* save the index of paired list to action_index for a2dp */
    /* deactivate cnf will use this index to get dev_addr */
    g_mmi_bth_cntx.action_index = paired_index;

    MMI_BTH_STATE_TRANS(MMI_BTH_STAT_CONNECTING);

    table_index = 0;
    if (profile_id == MMI_BTH_HF_PROFILE_UUID)
    {
        supported_profile_uuid = MMI_BTH_HFG_PROFILE_UUID;
    }
    else if (profile_id == MMI_BTH_HS_PROFILE_UUID)
    {
        supported_profile_uuid = MMI_BTH_HEADSET_AG_SERVICE_UUID;
    }
    else if (profile_id == MMI_BTH_AV_REMOTE_CONTROL_TARGET_UUID)
    {
        supported_profile_uuid = MMI_BTH_AV_REMOTE_CONTROL_UUID;
    }
    else if (profile_id == MMI_BTH_AV_REMOTE_CONTROL_UUID)
    {
        supported_profile_uuid = MMI_BTH_AV_REMOTE_CONTROL_TARGET_UUID;
    }
    else if (profile_id == MMI_BTH_OBEX_FILE_TRANSFER_UUID)
    {
        supported_profile_uuid = MMI_BTH_OBEX_FILE_TRANSFER_CLIENT_UUID;
    }
	/* BIP */
    else if (profile_id == MMI_BTH_OBEX_IMAGING_RESPONDER_UUID)
    {
        supported_profile_uuid = MMI_BTH_OBEX_IMAGING_UUID;
    }
    else
    {
        supported_profile_uuid = profile_id;
    }
    while (support_profile_tbl[table_index].uuid != MMI_BTH_MAX_PROFILE_UUID)
    {
        if ((support_profile_tbl[table_index].uuid == supported_profile_uuid))
        {
            if(supported_profile_uuid == MMI_BTH_OBEX_FILE_TRANSFER_CLIENT_UUID)
            {
                if (support_profile_tbl[table_index].multi_connect_func_ptr)
                {
                    (*support_profile_tbl[table_index].multi_connect_func_ptr) (g_mmi_bth_cntx.paired_list[paired_index].bd_addr, 0);
                }
            }
            else
            {
                if (support_profile_tbl[table_index].connect_func_ptr)
                {
                    (*support_profile_tbl[table_index].connect_func_ptr) (g_mmi_bth_cntx.paired_list[paired_index].bd_addr);
                }
            }
            result = MMI_TRUE;
            break;
        }
        table_index++;
    }

    return result;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_connect_accept_cnf_res
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  dev_addr        [?]             
 *  pro_uuid        [IN]            
 *  result          [IN]            
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bth_connect_accept_cnf_res(mmi_bth_bt_addr *dev_addr, U32 pro_uuid, MMI_BOOL result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 table_index;
    U32 supported_profile_uuid;
    MMI_BOOL ret_result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reject the connect accept confirm */
    table_index = 0;
    if (pro_uuid == MMI_BTH_HF_PROFILE_UUID)
    {
        supported_profile_uuid = MMI_BTH_HFG_PROFILE_UUID;
    }
    else if (pro_uuid == MMI_BTH_HS_PROFILE_UUID)
    {
        supported_profile_uuid = MMI_BTH_HEADSET_AG_SERVICE_UUID;
    }
    else
    {
        supported_profile_uuid = pro_uuid;
    }
    while (support_profile_tbl[table_index].uuid != MMI_BTH_MAX_PROFILE_UUID)
    {
        if ((support_profile_tbl[table_index].uuid == supported_profile_uuid))
        {
            if (support_profile_tbl[table_index].connect_cnf_res_func_ptr)
            {
                (*support_profile_tbl[table_index].connect_cnf_res_func_ptr) (*dev_addr, (U32)result);
                ret_result = MMI_TRUE;
            }
            break;
        }
        table_index++;
    }

    MMI_BTH_STATE_TRANS(MMI_BTH_STAT_IDLE);

    return ret_result;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_disconnect_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  connection_id       [IN]            
 *  conn_type           [IN]            
 *  a(?)                [IN/OUT]        First variable, used as returns
 *  b(?)                [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bth_disconnect_req(U32 connection_id, mmi_bth_connection_type conn_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 conn_index;
    U32 paired_index = 0, table_index = 0;
    U32 supported_profile_uuid = MMI_BTH_MAX_PROFILE_UUID;
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (conn_index = 0; conn_index < g_mmi_bth_cntx.existed_conn_num; conn_index++)
    {
        if (g_mmi_bth_cntx.existed_conn[conn_index].conn_id == connection_id)
        {
            paired_index = g_mmi_bth_cntx.existed_conn[conn_index].index_of_paried_list;
            break;
        }
    }

    /* conn_index cannot be equal to g_mmi_bth_cntx.paired_dev_num */
    /* if conn_index=0 and g_mmi_bth_cntx.paired_dev_num=0, assert it */
    MMI_BT_ASSERT( /* i==0 || */ conn_index != g_mmi_bth_cntx.existed_conn_num);

    MMI_BTH_STATE_TRANS(MMI_BTH_STAT_DISCONNECTING);

    switch (conn_type)
    {

        case MMI_BTH_HFP_CONNECTION:
            supported_profile_uuid = MMI_BTH_HFG_PROFILE_UUID;
            break;
        case MMI_BTH_HSP_CONNECTION:
            supported_profile_uuid = MMI_BTH_HEADSET_AG_SERVICE_UUID;
            break;
        case MMI_BTH_SPP_CONNECTION:
            supported_profile_uuid = MMI_BTH_SPP_PROFILE_UUID;
            break;
        case MMI_BTH_DUN_CONNECTION:
            supported_profile_uuid = MMI_BTH_DUN_PROFILE_UUID;
            break;
        case MMI_BTH_OPP_CONNECTION:
            supported_profile_uuid = MMI_BTH_OBEX_OBJECT_PUSH_SERVICE_UUID;
            break;
        case MMI_BTH_FTP_CONNECTION:
            supported_profile_uuid = MMI_BTH_OBEX_FILE_TRANSFER_UUID;
            break;
        case MMI_BTH_A2DP_CONNECTION:
            supported_profile_uuid = MMI_BTH_ADVANCED_AUDIO_PROFILE_UUID;
            break;
        case MMI_BTH_AVRCP_CONNECTION:
            supported_profile_uuid = MMI_BTH_AV_REMOTE_CONTROL_TARGET_UUID;
            break;
        case MMI_BTH_AVRCP_CT_CONNECTION:            
            supported_profile_uuid = MMI_BTH_AV_REMOTE_CONTROL_UUID;
            break;
        case MMI_BTH_SIMAP_CONNECTION:            
            supported_profile_uuid = MMI_BTH_SIM_ACCESS_PROFILE_UUID;
            break;
        case MMI_BTH_HID_CONNECTION:            
            supported_profile_uuid = MMI_BTH_HID_PROFILE_UUID;
            break;
        case MMI_BTH_FAX_CONNECTION:
            /* Add by stanley:2006-11-24 */ 
            supported_profile_uuid = MMI_BTH_FAX_PROFILE_UUID;
            break;
        case MMI_BTH_BPP_CONNECTION:            
            supported_profile_uuid = MMI_BTH_BASIC_PRINTING;
            break;
		/* BIP */
        case MMI_BTH_BIP_CONNECTION:            
            supported_profile_uuid = MMI_BTH_OBEX_IMAGING_RESPONDER_UUID;
            break;

        default:
            MMI_BT_ASSERT(0);
            break;
    }

    table_index = 0;
    while (support_profile_tbl[table_index].uuid != MMI_BTH_MAX_PROFILE_UUID)
    {
        if ((support_profile_tbl[table_index].uuid == supported_profile_uuid))
        {
            if (support_profile_tbl[table_index].disconnect_func_ptr)
            {
                (*support_profile_tbl[table_index].disconnect_func_ptr) (g_mmi_bth_cntx.paired_list[paired_index].
                                                                         bd_addr, connection_id);
            }
            result = MMI_TRUE;
            break;
        }
        table_index++;
    }

    return result;
}

/*****************************************************************************
* FUNCTION
*  mmi_bth_mydev_connect_req
* DESCRIPTION
*   This function is to 
*
* PARAMETERS
*  a  IN/OUT      first variable, used as returns
*  b  IN       second variable
* RETURNS
*  NONE.
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/
MMI_BOOL mmi_bth_mydev_connect_req(U32);

/*****************************************************************************
* FUNCTION
*  mmi_bth_mydev_rename_req
* DESCRIPTION
*   This function is to 
*
* PARAMETERS
*  a  IN/OUT      first variable, used as returns
*  b  IN       second variable
* RETURNS
*  NONE.
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/
MMI_BOOL mmi_bth_mydev_rename_req(U32);

/*****************************************************************************
* FUNCTION
*  mmi_bth_mydev_authorise_req
* DESCRIPTION
*   This function is to 
*
* PARAMETERS
*  a  IN/OUT      first variable, used as returns
*  b  IN       second variable
* RETURNS
*  NONE.
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/
MMI_BOOL mmi_bth_mydev_authorise_req(U32, U32 pro_uuid);


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_mydev_del_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  dev_addr        [?]             
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bth_mydev_del_req(mmi_bth_bt_addr *dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BTH_STATE_TRANS(MMI_BTH_STAT_DEBONDING);
    mmi_bth_cm_debond_req_hdler((*dev_addr));
    return MMI_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_mydev_del_all_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bth_mydev_del_all_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_bth_cntx.paired_dev_num != 0)
    {

        MMI_BTH_STATE_TRANS(MMI_BTH_STAT_DEBONDING_ALL);

        mmi_bth_cm_debond_req_hdler((g_mmi_bth_cntx.paired_list[0].bd_addr));
        result = MMI_TRUE;
    }
    else
    {
        result = MMI_FALSE;
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_mydev_add_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  dev_add_p       [?]             
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bth_mydev_add_req(mmi_bth_bt_addr *dev_add_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get index of paired list */
    for (i = 0; i < g_mmi_bth_cntx.paired_dev_num; i++)
    {
        if (g_mmi_bth_cntx.paired_list[i].bd_addr.lap == dev_add_p->lap
            && g_mmi_bth_cntx.paired_list[i].bd_addr.uap == dev_add_p->uap
            && g_mmi_bth_cntx.paired_list[i].bd_addr.nap == dev_add_p->nap)
        {
            break;
        }
    }

    g_mmi_bth_cntx.paired_list[i].bd_addr.nap = dev_add_p->nap;
    g_mmi_bth_cntx.paired_list[i].bd_addr.uap = dev_add_p->uap;
    g_mmi_bth_cntx.paired_list[i].bd_addr.lap = dev_add_p->lap;

    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_PAIRED_DEV_INFO,
               g_mmi_bth_cntx.paired_list[i].cod,
               ((g_mmi_bth_cntx.paired_list[i].bd_addr.nap & 0xff00) >> 8),
               (g_mmi_bth_cntx.paired_list[i].bd_addr.nap & 0x00ff), (g_mmi_bth_cntx.paired_list[i].bd_addr.uap),
               ((g_mmi_bth_cntx.paired_list[i].bd_addr.lap & 0xff0000) >> 16),
               ((g_mmi_bth_cntx.paired_list[i].bd_addr.lap & 0x00ff00) >> 8),
               (g_mmi_bth_cntx.paired_list[i].bd_addr.lap & 0x0000ff));

    /* reset original service list num */
    g_mmi_bth_cntx.paired_list[i].service_list_num = 0;

    if (i == g_mmi_bth_cntx.paired_dev_num)
    {
        g_mmi_bth_cntx.paired_dev_num++;
    }
    /* write to NVRAM */
    mmi_bth_nvram_write_info();
    MMI_BT_ASSERT(g_mmi_bth_cntx.paired_dev_num <= MMI_BTH_MAX_PAIRED_DEVICE_LIST);

    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bth_mydev_remove_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  dev_add_p       [?]             
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bth_mydev_remove_req(mmi_bth_bt_addr *dev_add_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, j, k;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get index of paired list */
    for (i = 0; i < g_mmi_bth_cntx.paired_dev_num; i++)
    {
        if (g_mmi_bth_cntx.paired_list[i].bd_addr.lap == dev_add_p->lap
            && g_mmi_bth_cntx.paired_list[i].bd_addr.uap == dev_add_p->uap
            && g_mmi_bth_cntx.paired_list[i].bd_addr.nap == dev_add_p->nap)
        {
            break;
        }
    }

    if (i < g_mmi_bth_cntx.paired_dev_num)
    {
        MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_PAIRED_DEV_INFO,
                   g_mmi_bth_cntx.paired_list[i].cod,
                   ((g_mmi_bth_cntx.paired_list[i].bd_addr.nap & 0xff00) >> 8),
                   (g_mmi_bth_cntx.paired_list[i].bd_addr.nap & 0x00ff), (g_mmi_bth_cntx.paired_list[i].bd_addr.uap),
                   ((g_mmi_bth_cntx.paired_list[i].bd_addr.lap & 0xff0000) >> 16),
                   ((g_mmi_bth_cntx.paired_list[i].bd_addr.lap & 0x00ff00) >> 8),
                   (g_mmi_bth_cntx.paired_list[i].bd_addr.lap & 0x0000ff));

        /* remove this paired device from paired list */
        if (i == (g_mmi_bth_cntx.paired_dev_num - 1))
        {
            memset(&(g_mmi_bth_cntx.paired_list[i]), 0, sizeof(mmi_bth_dev_struct));
        }
        else
        {
            for (j = i; j < g_mmi_bth_cntx.paired_dev_num - 1; j++)
            {
                memcpy(
                    &(g_mmi_bth_cntx.paired_list[j]),
                    &(g_mmi_bth_cntx.paired_list[j + 1]),
                    sizeof(mmi_bth_dev_struct));
            }
            memset(&(g_mmi_bth_cntx.paired_list[j]), 0, sizeof(mmi_bth_dev_struct));

        }

        MMI_BT_ASSERT(g_mmi_bth_cntx.paired_dev_num);
        g_mmi_bth_cntx.paired_dev_num--;
        /* write to NVRAM */
        mmi_bth_nvram_write_info();

        /* re-struct the index_of_paried_list in existed conn list */
        for (j = 0; j < g_mmi_bth_cntx.existed_conn_num; j++)
        {
            if (g_mmi_bth_cntx.existed_conn[j].index_of_paried_list == i)
            {
                /* set the index_of_paried_list of wanted deleted existed_conn to be 0xFF */
                g_mmi_bth_cntx.existed_conn[j].index_of_paried_list = 0xFF;
            }
            else if (g_mmi_bth_cntx.existed_conn[j].index_of_paried_list > i)
            {
                g_mmi_bth_cntx.existed_conn[j].index_of_paried_list--;
            }
        }

        /* remove this paired device from existed_conn list */
        for (j = 0; j < g_mmi_bth_cntx.existed_conn_num; j++)
        {
            if (g_mmi_bth_cntx.existed_conn[j].index_of_paried_list == 0xFF)
            {
                if (j == (g_mmi_bth_cntx.existed_conn_num - 1))
                {
                    memset(&(g_mmi_bth_cntx.existed_conn[j]), 0, sizeof(mmi_bth_connect_struct));
                }
                else
                {
                    for (k = j; k < g_mmi_bth_cntx.existed_conn_num - 1; k++)
                    {
                        memcpy(
                            &(g_mmi_bth_cntx.existed_conn[k]),
                            &(g_mmi_bth_cntx.existed_conn[k + 1]),
                            sizeof(mmi_bth_connect_struct));
                    }
                    memset(&(g_mmi_bth_cntx.existed_conn[k]), 0, sizeof(mmi_bth_connect_struct));
                }
                /* remove this existed conn */
                MMI_BT_ASSERT(g_mmi_bth_cntx.existed_conn_num);
                g_mmi_bth_cntx.existed_conn_num--;
                break;
            }
        }

    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_set_vis_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  vis         [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bth_set_vis_req(MMI_BOOL vis)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 page_inquiry_mode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vis)
    {
        MMI_BTH_SET_FLAG(MMI_BTH_MASK_VIS);
    }
    else
    {
        MMI_BTH_RESET_FLAG(MMI_BTH_MASK_VIS);
    }

    if (MMI_BTH_GET_FLAG(MMI_BTH_MASK_VIS))
    {
        page_inquiry_mode = BTBM_ADP_P_ON_I_ON;
    }
    else
    {
        page_inquiry_mode = BTBM_ADP_P_ON_I_OFF;
    }

    MMI_BTH_STATE_TRANS(MMI_BTH_STAT_VISIBILITY_SETTING);
    mmi_bth_cm_write_scanenable_mode_req_hdler(page_inquiry_mode, page_inquiry_mode);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_set_connectable_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  connectable     [IN]            
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bth_set_connectable_req(MMI_BOOL connectable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 page_inquiry_mode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (connectable)
    {
        MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_CONNECTABLE_REQ, connectable, MMI_BTH_GET_FLAG(MMI_BTH_MASK_VIS));
        if (MMI_BTH_GET_FLAG(MMI_BTH_MASK_VIS))
        {
            page_inquiry_mode = BTBM_ADP_P_ON_I_ON;
        }
        else
        {
            page_inquiry_mode = BTBM_ADP_P_ON_I_OFF;
        }
        mmi_bth_cm_write_scanenable_mode_req_hdler(page_inquiry_mode, page_inquiry_mode);
    }
    else
    {
        MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_CONNECTABLE_REQ, connectable, 0);
        mmi_bth_cm_write_scanenable_mode_req_hdler((U8) BTBM_ADP_P_OFF_I_OFF, (U8) BTBM_ADP_P_OFF_I_OFF);
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_set_name_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  name        [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bth_set_name_req(U8 *name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 name_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    name_len = strlen((const char*)name);
    mmi_bth_cm_set_local_name_req_hdler((U8) name_len, name);

    MMI_BTH_STATE_TRANS(MMI_BTH_STAT_LOCAL_NAME_SETTING);
    /* store the name pointer before receiving local name setting cfm */
    g_mmi_bth_cntx.host_name_setting = name;
    return MMI_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_set_auth_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  auth        [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bth_set_auth_req(MMI_BOOL auth)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (auth)
    {
        MMI_BTH_SET_FLAG(MMI_BTH_MASK_AUTH);
    }
    else
    {
        MMI_BTH_RESET_FLAG(MMI_BTH_MASK_AUTH);
    }
    MMI_BTH_STATE_TRANS(MMI_BTH_STAT_AUTHENTICATION_SETTING);
    mmi_bth_cm_security_level_req_hdler((MMI_BOOL) MMI_BTH_GET_FLAG(MMI_BTH_MASK_AUTH));
    return MMI_TRUE;

}
/*****************************************************************************
 * FUNCTION
 *  mmi_bth_set_simap_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  activate        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bth_set_simap_req(MMI_BOOL activate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (activate)
    {
        MMI_BTH_SET_RAMFLAG(MMI_BTH_RAMMASK_IS_SIMAP_ACTIVATE);
        MMI_BTH_STATE_TRANS(MMI_BTH_STAT_ACTIVATING_SIMAP);
        /* disallow acl link establishment */
        /* ->simap activate */
        mmi_bth_cm_disallow_acl_link_establishment_req_hdler();

    }
    else
    {
        MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_DEACTIVATE_FLAG, g_mmi_bth_cntx.deactivate_flag);
        MMI_BTH_RESET_RAMFLAG(MMI_BTH_RAMMASK_IS_SIMAP_ACTIVATE);
        MMI_BTH_STATE_TRANS(MMI_BTH_STAT_DEACTIVATING_SIMAP);
        /* simap deactivate */
        /* -> allow acl link establishment */
        #ifdef __MMI_SIMAP_SUPPORT__
        mmi_bth_simap_deactivate_req_hdler();
        #endif
    }
    
    return MMI_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_set_aud_pth_2_hf
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  pth_2_hg        [IN]            
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bth_set_aud_pth_2_hf(MMI_BOOL pth_2_hg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (pth_2_hg)
    {
        MMI_BTH_SET_FLAG(MMI_BTH_MASK_AUDPATH);
        
        #if defined(__MMI_BT_PROFILE__) && (defined(__MMI_BT_AUDIO_VIA_SCO__) || defined(__MMI_BT_FM_VIA_SCO__))
        if(mmi_bth_is_hs_connected())
        {
            mmi_profiles_bt_connect_req(MMI_PROFILES_BT_HFP_SCO);
        }
        #endif 
    }
    else
    {
        MMI_BTH_RESET_FLAG(MMI_BTH_MASK_AUDPATH);
        
        #if defined(__MMI_BT_PROFILE__) && (defined(__MMI_BT_AUDIO_VIA_SCO__) || defined(__MMI_BT_FM_VIA_SCO__))
        if(mmi_bth_is_hs_connected())
        {
            mmi_profiles_bt_disconnect_req(MMI_PROFILES_BT_HFP_SCO);
        }
        #endif 
    }

    mmi_bth_nvram_write_info();
    return MMI_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_set_ram_flag
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  set_flag        [IN]            
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bth_set_ram_flag(U32 set_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BTH_SET_RAMFLAG(set_flag);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_reset_ram_flag
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  set_flag        [IN]            
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bth_reset_ram_flag(U32 set_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BTH_RESET_RAMFLAG(set_flag);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_set_flag
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  set_flag        [IN]            
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bth_set_flag(U32 set_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BTH_SET_FLAG(set_flag);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_reset_flag
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  set_flag        [IN]            
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bth_reset_flag(U32 set_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BTH_RESET_FLAG(set_flag);
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bth_set_state
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  set_state       [IN]            
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bth_set_state(U32 set_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_bth_cntx.state = (mmi_bth_state_enum) set_state;
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_set_headset_speaker_gain_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  speaker_gain        [IN]            
 *  conn_id             [IN]            
 *  a(?)                [IN/OUT]        First variable, used as returns
 *  b(?)                [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bth_set_headset_speaker_gain_req(U8 speaker_gain, U32 conn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_bth_is_hfp_connected())
    {
    #if defined(__MMI_HFP_SUPPORT__)
        mmi_bth_hfg_speaker_gain_req_hdler(speaker_gain, conn_id);
        result = MMI_TRUE;
    #endif /* defined(__MMI_HFP_SUPPORT__) */ 
    }
    else if (mmi_bth_is_hsp_connected())
    {
    #if defined(__MMI_HSP_SUPPORT__)
        mmi_bth_hsg_speaker_gain_req_hdler(speaker_gain, conn_id);
        result = MMI_TRUE;
    #endif /* defined(__MMI_HSP_SUPPORT__) */ 
    }

    return result;

}

/* Configure Default Headset */
/*****************************************************************************
 * FUNCTION
 *  mmi_bth_set_default_hs_index
 * DESCRIPTION
 *  This function is to get 
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bth_set_default_hs_index(U32 paired_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL result = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (paired_index < g_mmi_bth_cntx.paired_dev_num)
    {
		g_mmi_bth_cntx.idx_of_last_hs_dev = paired_index;
		result = MMI_TRUE;
	}


    return result;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hfp_sco_connect_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bth_hfp_sco_connect_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_SPEECH, MMI_TRUE, g_mmi_bth_cntx.state, 0);

    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_AUDPATH_ON);
#if 0
/* under construction !*/
#else /* 0 */ 
#if defined(__MMI_BT_PROFILE__)
    mmi_profiles_bt_connect_req(MMI_PROFILES_BT_HFP_SCO);
    //mmi_profiles_bt_connect_sco(NULL);
#endif 
#endif /* 0 */ 

    return MMI_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hfp_sco_disconnect_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bth_hfp_sco_disconnect_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_SPEECH, MMI_FALSE, g_mmi_bth_cntx.state, 0);

    if (mmi_bth_get_sco_status(mmi_bth_get_active_hfp_connect_id()) == MMI_TRUE)
    {
    #if 0
/* under construction !*/
    #else /* 0 */ 
    #if defined(__MMI_BT_PROFILE__)
        mmi_profiles_bt_disconnect_req(MMI_PROFILES_BT_HFP_SCO);
        //mmi_profiles_bt_disconnect_sco();
    #endif 
    #endif /* 0 */ 
    }
    return MMI_TRUE;

}

/* Configure Default Headset */
/*****************************************************************************
 * FUNCTION
 *  mmi_bth_connect_last_headset_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bth_connect_last_headset_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
	U32 paired_index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	paired_index = g_mmi_bth_cntx.idx_of_last_hs_dev;

	if (paired_index == 0xFFFFFFFF)
	{
        if (g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_display_popup)
        {
            (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_display_popup) ((PU8) GetString(STR_BT_NO_DEFAULT_HEADSET),
                                                                      IMG_GLOBAL_UNFINISHED, 0,
                                                                      UI_POPUP_NOTIFYDURATION_TIME, ERROR_TONE);
        }
 		return result;
	}
	else
    {
		MMI_BT_ASSERT(paired_index < g_mmi_bth_cntx.paired_dev_num);
    }


	if (mmi_bth_is_service_support(paired_index, MMI_BTH_HF_PROFILE_UUID))
	{
		mmi_bth_connect_req(&(g_mmi_bth_cntx.paired_list[paired_index].bd_addr), MMI_BTH_HF_PROFILE_UUID);
	    
        if (g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_show_progress_scr)
        {
            (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_show_progress_scr) (SCR_BT_CONNECT_LAST_HEADSET,
                                                                          STR_BT_CONNECT,
                                                                          STR_BT_CONNECTING, NULL, MMI_FALSE, NULL);
        }
	    
	    result = MMI_TRUE;
	}
	else if (mmi_bth_is_service_support(paired_index, MMI_BTH_HS_PROFILE_UUID))  
	{
		mmi_bth_connect_req(&(g_mmi_bth_cntx.paired_list[paired_index].bd_addr), MMI_BTH_HS_PROFILE_UUID);
		
        if (g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_show_progress_scr)
        {
            (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_show_progress_scr) (SCR_BT_CONNECT_LAST_HEADSET,
                                                                          STR_BT_CONNECT,
                                                                          STR_BT_CONNECTING, NULL, MMI_FALSE, NULL);
        }

	    result = MMI_TRUE;
	}
	else if (g_mmi_bth_cntx.paired_list[paired_index].service_list_num == 0)
    {
		mmi_bth_connect_req(&(g_mmi_bth_cntx.paired_list[paired_index].bd_addr), MMI_BTH_HF_PROFILE_UUID);
		
        if (g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_show_progress_scr)
        {
            (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_show_progress_scr) (SCR_BT_CONNECT_LAST_HEADSET,
                                                                          STR_BT_CONNECT,
                                                                          STR_BT_CONNECTING, NULL, MMI_FALSE, NULL);
        }

	    result = MMI_TRUE;
    }
	
    return result;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_turn_on_speech_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  speech_on       [IN]            
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bth_turn_on_speech_req(MMI_BOOL speech_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_SPEECH, speech_on, g_mmi_bth_cntx.state, 0);

    if (speech_on == MMI_TRUE)
    {
        /* Switch audio front-end to PCM interace */
        MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_AUDPATH_ON);
        MMI_BTH_SET_RAMFLAG(MMI_BTH_RAMMASK_IS_SWAP2BT);
    #if !defined(__MMI_BT_PROFILE__) 
        mdi_audio_speech_codec_stop();
        mdi_audio_set_bluetooth_path(MMI_TRUE);
        /* connect sco link by MMI(HFP)->BT task instead of MDI->MED->BT task */
    #endif /* !defined(__MMI_BT_PROFILE__)  */ 

    }
    else
    {

    #if !defined(__MMI_BT_PROFILE__) 
        if (mmi_bth_get_sco_status(mmi_bth_get_active_hfp_connect_id()) == MMI_TRUE)
        {
            /* disconnect sco link by MMI(HFP)->BT task instead of MDI->MED->BT task */
        }
        mdi_audio_speech_codec_stop();
        mmi_bth_test_l1sp_bt_off();
    #endif /* !defined(__MMI_BT_PROFILE__) */ 
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_pwroff
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_pwroff(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bth_antenna_off_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_switch_voice_path_incall
 * DESCRIPTION
 *  This function is to get current active hfp/hsp connection id
 * PARAMETERS
 *  is_on       [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_bth_switch_voice_path_incall(MMI_BOOL is_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_bth_is_hs_connected())
    {
        if (g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_display_popup)
        {
            (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_display_popup) ((PU8) GetString(STR_GLOBAL_UNFINISHED),
                                                                      IMG_GLOBAL_UNFINISHED, 0,
                                                                      UI_POPUP_NOTIFYDURATION_TIME, ERROR_TONE);
        }
        return MMI_FALSE;
    }

    if (is_on == MMI_TRUE)
    {
        if (mmi_bth_get_sco_status(mmi_bth_get_active_hfp_connect_id()) != MMI_TRUE)
        {
        	#if defined(__MMI_BT_PROFILE__)
            if (mmi_profiles_bt_is_sco_connect_allowed())
            {
                mmi_profiles_bt_connect_req(MMI_PROFILES_BT_HFP_SCO);
                if (g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_show_progress_scr)
                {
                    (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_show_progress_scr) (SCR_BT_SWITCH_SPEECH_PATH,
                                                                                  STR_BT_DEV_SET_AUDIO_PATH,
                                                                                  STR_BT_CM_SETPATH, NULL, MMI_FALSE, NULL);
                }
            }
            else
            {
                (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_display_popup) ((PU8) GetString(STR_BT_NOT_ALLOW),
                                                                          IMG_GLOBAL_ERROR, 0,
                                                                          UI_POPUP_NOTIFYDURATION_TIME, ERROR_TONE);
            }
            #endif 
            return MMI_TRUE;
        }
        else
        {
            if (g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_display_popup)
            {
                (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_display_popup) ((PU8) GetString(STR_GLOBAL_UNFINISHED),
                                                                          IMG_GLOBAL_UNFINISHED, 0,
                                                                          UI_POPUP_NOTIFYDURATION_TIME, ERROR_TONE);
            }
            return MMI_FALSE;
        }
    }
    else
    {
        if (mmi_bth_get_sco_status(mmi_bth_get_active_hfp_connect_id()) == MMI_TRUE)
        {
        #if defined(__MMI_BT_PROFILE__)
            mmi_profiles_bt_disconnect_req(MMI_PROFILES_BT_HFP_SCO);
        #endif 
            if (g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_show_progress_scr)
            {
                (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_show_progress_scr) (SCR_BT_SWITCH_SPEECH_PATH,
                                                                              STR_BT_DEV_SET_AUDIO_PATH,
                                                                              STR_BT_CM_SETPATH, NULL, MMI_FALSE, NULL);
            }
            return MMI_TRUE;
        }
        else
        {
            if (g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_display_popup)
            {
                (*g_mmi_bth_cntx.scr_cb_tbl.mmi_bt_scr_cb_display_popup) ((PU8) GetString(STR_GLOBAL_UNFINISHED),
                                                                          IMG_GLOBAL_UNFINISHED, 0,
                                                                          UI_POPUP_NOTIFYDURATION_TIME, ERROR_TONE);
            }
            return MMI_FALSE;
        }

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_reset_hfp_module
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_reset_hfp_module(void)
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
 *  mmi_bth_reset_a2dp_module
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_reset_a2dp_module(void)
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
 *  mmi_bth_prohibit_opp_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bth_prohibit_opp_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* prohibit OPS->FTS->SPP->DUN profiles */

    for (i = 0; i < g_mmi_bth_cntx.existed_conn_num; i++)
    {
        if (g_mmi_bth_cntx.existed_conn[i].active == MMI_TRUE)
        {
            if (g_mmi_bth_cntx.existed_conn[i].conn_type == MMI_BTH_OPP_CONNECTION)
            {
                mmi_bth_disconnect_req(
                    g_mmi_bth_cntx.existed_conn[i].conn_id,
                    g_mmi_bth_cntx.existed_conn[i].conn_type);
                result = MMI_TRUE;
                break;
            }
        }
    }

    /* mmi_bth_hfg_audio_req or mmi_bth_disconnect_req will change the state */
    /* so assign the state here */
    MMI_BTH_STATE_TRANS(MMI_BTH_STAT_RELEASE_OPP_CONNECTION);

    if (i == g_mmi_bth_cntx.existed_conn_num)
    {
        StartTimer(
            BT_DEACTIVATE_PROHIBITED_PROFILES_TIMER,
            MMI_BTH_DEACTIVATE_PROHIBITED_PROFILES_TIMER_DUR,
            mmi_bth_deactivate_ops);
        //mmi_opp_deactivate_ops();
        //SetProtocolEventHandler(mmi_bth_deactivate_cnf_hdler, MSG_ID_MMI_BTH_HFG_DEACTIVATE_CFM);
        result = MMI_FALSE;
    }

    return result;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_prohibit_ftp_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bth_prohibit_ftp_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* prohibit OPS->FTS->SPP->DUN profiles */

    for (i = 0; i < g_mmi_bth_cntx.existed_conn_num; i++)
    {
        if (g_mmi_bth_cntx.existed_conn[i].active == MMI_TRUE)
        {
            if (g_mmi_bth_cntx.existed_conn[i].conn_type == MMI_BTH_FTP_CONNECTION)
            {
                mmi_bth_disconnect_req(
                    g_mmi_bth_cntx.existed_conn[i].conn_id,
                    g_mmi_bth_cntx.existed_conn[i].conn_type);
                result = MMI_TRUE;
                break;
            }
        }
    }

    /* mmi_bth_hfg_audio_req or mmi_bth_disconnect_req will change the state */
    /* so assign the state here */
    MMI_BTH_STATE_TRANS(MMI_BTH_STAT_RELEASE_FTP_CONNECTION);

    if (i == g_mmi_bth_cntx.existed_conn_num)
    {
        StartTimer(
            BT_DEACTIVATE_PROHIBITED_PROFILES_TIMER,
            MMI_BTH_DEACTIVATE_PROHIBITED_PROFILES_TIMER_DUR,
            mmi_bth_deactivate_fts);
        //mmi_ftp_deactivate_fts();
        //SetProtocolEventHandler(mmi_bth_deactivate_cnf_hdler, MSG_ID_MMI_BTH_HFG_DEACTIVATE_CFM);
        result = MMI_FALSE;
    }

    return result;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_prohibit_spp_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bth_prohibit_spp_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* prohibit OPS->FTS->SPP->DUN profiles */

    for (i = 0; i < g_mmi_bth_cntx.existed_conn_num; i++)
    {
        if (g_mmi_bth_cntx.existed_conn[i].active == MMI_TRUE)
        {
            if (g_mmi_bth_cntx.existed_conn[i].conn_type == MMI_BTH_SPP_CONNECTION)
            {
                mmi_bth_disconnect_req(
                    g_mmi_bth_cntx.existed_conn[i].conn_id,
                    g_mmi_bth_cntx.existed_conn[i].conn_type);
                result = MMI_TRUE;
                break;
            }
        }
    }

    /* mmi_bth_hfg_audio_req or mmi_bth_disconnect_req will change the state */
    /* so assign the state here */
    MMI_BTH_STATE_TRANS(MMI_BTH_STAT_RELEASE_SPP_CONNECTION);

    if (i == g_mmi_bth_cntx.existed_conn_num)
    {
        StartTimer(
            BT_DEACTIVATE_PROHIBITED_PROFILES_TIMER,
            MMI_BTH_DEACTIVATE_PROHIBITED_PROFILES_TIMER_DUR,
            mmi_bth_deactivate_spp);
        //mmi_bth_spp_deactivate_req();
        //SetProtocolEventHandler(mmi_bth_spp_deactivate_cfm_hdler, MSG_ID_MMI_BTH_HFG_DEACTIVATE_CFM);
        result = MMI_FALSE;
    }

    return result;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_prohibit_dun_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bth_prohibit_dun_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* prohibit OPS->FTS->SPP->DUN profiles */

    for (i = 0; i < g_mmi_bth_cntx.existed_conn_num; i++)
    {
        if (g_mmi_bth_cntx.existed_conn[i].active == MMI_TRUE)
        {
            if (g_mmi_bth_cntx.existed_conn[i].conn_type == MMI_BTH_DUN_CONNECTION)
            {
                mmi_bth_disconnect_req(
                    g_mmi_bth_cntx.existed_conn[i].conn_id,
                    g_mmi_bth_cntx.existed_conn[i].conn_type);
                result = MMI_TRUE;
                break;
            }
        }
    }

    /* mmi_bth_hfg_audio_req or mmi_bth_disconnect_req will change the state */
    /* so assign the state here */
    MMI_BTH_STATE_TRANS(MMI_BTH_STAT_RELEASE_DUN_CONNECTION);

    if (i == g_mmi_bth_cntx.existed_conn_num)
    {
        StartTimer(
            BT_DEACTIVATE_PROHIBITED_PROFILES_TIMER,
            MMI_BTH_DEACTIVATE_PROHIBITED_PROFILES_TIMER_DUR,
            mmi_bth_deactivate_dun);
        //mmi_bth_dun_deactivate_req();
        //SetProtocolEventHandler(mmi_bth_dun_deactivate_cfm_hdler, MSG_ID_MMI_BTH_HFG_DEACTIVATE_CFM);
        result = MMI_FALSE;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_permit_opp_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_permit_opp_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_bth_is_activated())
    {
        /* activate OPS */
    #ifdef __MMI_OPP_SUPPORT__
        if (g_mmi_bth_cntx.deactivate_flag & MMI_BTH_OPS_DEACTIVATED)
        {
            U32 i = 0;

            MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_DEACTIVATE_FLAG, g_mmi_bth_cntx.deactivate_flag);

            while (support_profile_tbl[i].uuid != MMI_BTH_MAX_PROFILE_UUID)
            {
                if ((support_profile_tbl[i].uuid == MMI_BTH_OBEX_OBJECT_PUSH_SERVICE_UUID) &&
                    (g_mmi_bth_cntx.deactivate_flag & MMI_BTH_OPS_DEACTIVATED))
                {
                    if (support_profile_tbl[i].activate_func_ptr)
                    {
                        (*support_profile_tbl[i].activate_func_ptr) ();
                    }
                    break;
                }
                i++;
            }

        }
    #endif /* __MMI_OPP_SUPPORT__ */ 
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_permit_ftp_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_permit_ftp_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_bth_is_activated())
    {
        /* activate FTS */
    #if defined(__MMI_FTS_SUPPORT__)
        if (g_mmi_bth_cntx.deactivate_flag & MMI_BTH_FTS_DEACTIVATED)
        {
            U32 i = 0;

            MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_DEACTIVATE_FLAG, g_mmi_bth_cntx.deactivate_flag);

            while (support_profile_tbl[i].uuid != MMI_BTH_MAX_PROFILE_UUID)
            {
                if ((support_profile_tbl[i].uuid == MMI_BTH_OBEX_FILE_TRANSFER_UUID) &&
                    (g_mmi_bth_cntx.deactivate_flag & MMI_BTH_FTS_DEACTIVATED))
                {
                    if (support_profile_tbl[i].activate_func_ptr)
                    {
                        (*support_profile_tbl[i].activate_func_ptr) ();
                    }
                    break;
                }
                i++;
            }
        }
    #endif /* defined(__MMI_FTS_SUPPORT__) */ 
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_permit_spp_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_permit_spp_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_bth_is_activated())
    {
        /* activate SPP */
    #if defined(__MMI_SPP_SUPPORT__)
        if (g_mmi_bth_cntx.deactivate_flag & MMI_BTH_SPP_DEACTIVATED)
        {
            U32 i = 0;

            MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_DEACTIVATE_FLAG, g_mmi_bth_cntx.deactivate_flag);

            while (support_profile_tbl[i].uuid != MMI_BTH_MAX_PROFILE_UUID)
            {
                if ((support_profile_tbl[i].uuid == MMI_BTH_SPP_PROFILE_UUID) &&
                    (g_mmi_bth_cntx.deactivate_flag & MMI_BTH_SPP_DEACTIVATED))
                {
                    if (support_profile_tbl[i].activate_func_ptr)
                    {
                        (*support_profile_tbl[i].activate_func_ptr) ();
                    }
                    break;
                }
                i++;
            }
        }
    #endif /* defined(__MMI_SPP_SUPPORT__) */ 
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_permit_dun_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_permit_dun_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_bth_is_activated())
    {
        /* activate DUN */
    #if defined(__MMI_DUN_SUPPORT__)
        if (g_mmi_bth_cntx.deactivate_flag & MMI_BTH_DUN_DEACTIVATED)
        {
            U32 i = 0;

            MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_DEACTIVATE_FLAG, g_mmi_bth_cntx.deactivate_flag);

            while (support_profile_tbl[i].uuid != MMI_BTH_MAX_PROFILE_UUID)
            {
                if ((support_profile_tbl[i].uuid == MMI_BTH_DUN_PROFILE_UUID) &&
                    (g_mmi_bth_cntx.deactivate_flag & MMI_BTH_DUN_DEACTIVATED))
                {
                    if (support_profile_tbl[i].activate_func_ptr)
                    {
                        (*support_profile_tbl[i].activate_func_ptr) ();
                    }
                    break;
                }
                i++;
            }
        }
    #endif /* defined(__MMI_DUN_SUPPORT__) */ 
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_test_l1sp_bt_off
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_test_l1sp_bt_off(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_BT_AUDPATH_OFF);

    MMI_BTH_RESET_RAMFLAG(MMI_BTH_RAMMASK_IS_SWAP2BT);
#if !defined(__MMI_BT_PROFILE__) 
    mdi_audio_set_bluetooth_path(MMI_FALSE);
#endif 


}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_get_connection_type
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  profile_id      [IN]            
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
mmi_bth_connection_type mmi_bth_get_connection_type(U32 profile_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_BTH_NUM_OF_PROFILE_UUID; i++)
    {
        if (profile_id_to_connect_type_map[i][0] == profile_id)
        {
            break;
        }
    }

    if (i == MMI_BTH_NUM_OF_PROFILE_UUID)
    {
        return MMI_BTH_NO_CONNECTION;
    }
    else
    {
        return profile_id_to_connect_type_map[i][1];
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_is_all_supported_profiles_activated
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bth_is_all_supported_profiles_activated(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    MMI_BOOL result = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (support_profile_tbl[i].uuid != MMI_BTH_MAX_PROFILE_UUID)
    {
        if ((g_mmi_bth_cntx.deactivate_flag & (support_profile_tbl[i].deactivate_flag)) && 
			(support_profile_tbl[i].activate_func_ptr != NULL))
        {
            result = MMI_FALSE;
            break;
        }
        i++;
    }

    return result;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_is_all_supported_profiles_deactivated
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bth_is_all_supported_profiles_deactivated(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    MMI_BOOL result = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (support_profile_tbl[i].uuid != MMI_BTH_MAX_PROFILE_UUID)
    {
        if (!(g_mmi_bth_cntx.deactivate_flag & (support_profile_tbl[i].deactivate_flag)) && 
			(support_profile_tbl[i].deactivate_func_ptr != NULL))
        {
            result = MMI_FALSE;
            break;
        }
        #ifdef __MMI_SIMAP_SUPPORT__
        else if(!(g_mmi_bth_cntx.deactivate_flag & MMI_BTH_SIMAP_DEACTIVATED))
        {
            result = MMI_FALSE;
            break;
        }            
        #endif

        
        i++;
    }

    return result;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_set_deactivate_flag
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  prof_flag       [IN]            
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_set_deactivate_flag(U32 prof_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_bth_cntx.deactivate_flag |= prof_flag;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_reset_deactivate_flag
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  prof_flag       [IN]            
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_reset_deactivate_flag(U32 prof_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_bth_cntx.deactivate_flag &= ~(prof_flag);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_deactivate_spp
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_deactivate_spp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_DEACTIVATE_FLAG, g_mmi_bth_cntx.deactivate_flag);

    while (support_profile_tbl[i].uuid != MMI_BTH_MAX_PROFILE_UUID)
    {
        if ((support_profile_tbl[i].uuid == MMI_BTH_SPP_PROFILE_UUID) &&
            (!(g_mmi_bth_cntx.deactivate_flag & MMI_BTH_SPP_DEACTIVATED)))
        {
            if (support_profile_tbl[i].deactivate_func_ptr)
            {
                (*support_profile_tbl[i].deactivate_func_ptr) ();
            }
            break;
        }
        i++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_deactivate_dun
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_deactivate_dun(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_DEACTIVATE_FLAG, g_mmi_bth_cntx.deactivate_flag);

    while (support_profile_tbl[i].uuid != MMI_BTH_MAX_PROFILE_UUID)
    {
        if ((support_profile_tbl[i].uuid == MMI_BTH_DUN_PROFILE_UUID) &&
            (!(g_mmi_bth_cntx.deactivate_flag & MMI_BTH_DUN_DEACTIVATED)))
        {
            if (support_profile_tbl[i].deactivate_func_ptr)
            {
                (*support_profile_tbl[i].deactivate_func_ptr) ();
            }
            break;
        }
        i++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_deactivate_ops
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_deactivate_ops(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_DEACTIVATE_FLAG, g_mmi_bth_cntx.deactivate_flag);

    while (support_profile_tbl[i].uuid != MMI_BTH_MAX_PROFILE_UUID)
    {
        if ((support_profile_tbl[i].uuid == MMI_BTH_OBEX_OBJECT_PUSH_SERVICE_UUID) &&
            (!(g_mmi_bth_cntx.deactivate_flag & MMI_BTH_OPS_DEACTIVATED)))
        {
            if (support_profile_tbl[i].deactivate_func_ptr)
            {
                (*support_profile_tbl[i].deactivate_func_ptr) ();
            }
            break;
        }
        i++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_deactivate_fts
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_deactivate_fts(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_DEACTIVATE_FLAG, g_mmi_bth_cntx.deactivate_flag);

    while (support_profile_tbl[i].uuid != MMI_BTH_MAX_PROFILE_UUID)
    {
        if ((support_profile_tbl[i].uuid == MMI_BTH_OBEX_FILE_TRANSFER_UUID) &&
            (!(g_mmi_bth_cntx.deactivate_flag & MMI_BTH_FTS_DEACTIVATED)))
        {
            if (support_profile_tbl[i].deactivate_func_ptr)
            {
                (*support_profile_tbl[i].deactivate_func_ptr) ();
            }
            break;
        }
        i++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_get_active_a2dp_infor
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  profile_id          [IN]            
 *  lap                 [?]             
 *  uap                 [?]             
 *  nap                 [?]             
 *  connection_id       [?]             
 *  a(?)                [IN/OUT]        First variable, used as returns
 *  b(?)                [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_get_active_a2dp_infor(U32 profile_id, U32 *lap, U8 *uap, U16 *nap, U32 *connection_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, j;
    mmi_bth_connection_type conn_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    conn_type = mmi_bth_get_connection_type(profile_id);

    for (i = 0; i < g_mmi_bth_cntx.existed_conn_num; i++)
    {
        if (g_mmi_bth_cntx.existed_conn[i].conn_type == conn_type)
        {
            j = g_mmi_bth_cntx.existed_conn[i].index_of_paried_list;
            *lap = g_mmi_bth_cntx.paired_list[j].bd_addr.lap;
            *uap = g_mmi_bth_cntx.paired_list[j].bd_addr.uap;
            *nap = g_mmi_bth_cntx.paired_list[j].bd_addr.nap;
            *connection_id = g_mmi_bth_cntx.existed_conn[i].conn_id;
            break;
        }

    }

    /* i cannot be equal to g_mmi_bth_cntx.paired_dev_num */
    /* if i=0 and g_mmi_bth_cntx.existed_conn_num=0, assert it */
    if (i == g_mmi_bth_cntx.existed_conn_num)
    {
        MMI_BT_ASSERT(0);
    }

}
/*****************************************************************************
 * FUNCTION
 *  mmi_bth_get_last_hid_dev
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_get_last_hid_dev(mmi_bth_bt_addr *bt_addr_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = g_mmi_bth_cntx.idx_of_last_hid_dev ;
    if (index != 0xFFFFFFFF)
    {
        bt_addr_p->lap = g_mmi_bth_cntx.paired_list[index].bd_addr.lap;
        bt_addr_p->uap = g_mmi_bth_cntx.paired_list[index].bd_addr.uap;
        bt_addr_p->nap = g_mmi_bth_cntx.paired_list[index].bd_addr.nap;
    }
}
/* for registering pairing function call */
/*****************************************************************************
 * FUNCTION
 *  mmi_bth_reg_pairing_permission
 * DESCRIPTION
 *  This function is to register the pairing permission function call
 * PARAMETERS
 *  U32 profile_id, to specify the profile uuid
 *  void *fp, registered function call for CM to check if pairing procedure is permitted
 *            the input argument of the registerd function call is mmi_bth_bt_addr, CM will pass this
 *            information to registered function call.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_reg_pairing_permission(U32 profile_id, void *fp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_REG_PAIRING_PERMISSION_CB, profile_id, fp);

	g_mmi_bth_cntx.pair_permission_cb.profile_uuid = profile_id;
	g_mmi_bth_cntx.pair_permission_cb.func_ptr = (MMI_BOOL(*)(mmi_bth_bt_addr))fp;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bth_unreg_pairing_permission
 * DESCRIPTION
 *  This function is to unregister the pairing permission function call
 * PARAMETERS
 *  U32   profile_id, to specify the profile uuid
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_unreg_pairing_permission(U32 profile_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_UNREG_PAIRING_PERMISSION_CB, profile_id);

	g_mmi_bth_cntx.pair_permission_cb.profile_uuid = 0;
	g_mmi_bth_cntx.pair_permission_cb.func_ptr = NULL;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bth_is_pairing_permitted
 * DESCRIPTION
 *  This function is to check if pairing is permitted
 * PARAMETERS
 *  mmi_bth_bt_addr dev_addr, specify the device address
 * RETURNS
 *  MMI_BOOL    MMI_TRUE    permitted
 *              MMI_FALSE   not permitted
 *****************************************************************************/
MMI_BOOL mmi_bth_is_pairing_permitted(mmi_bth_bt_addr dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL result =  MMI_TRUE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (g_mmi_bth_cntx.pair_permission_cb.func_ptr)
	{
		result = (*g_mmi_bth_cntx.pair_permission_cb.func_ptr)(dev_addr);
	}

    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_IS_PAIRING_PERMITTED, g_mmi_bth_cntx.pair_permission_cb.profile_uuid, result);

	return result;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_bth_close_sdc_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_close_sdc_req(void)
{
    return;
}

#endif /* __MMI_BT_MTK_SUPPORT__ */ 

