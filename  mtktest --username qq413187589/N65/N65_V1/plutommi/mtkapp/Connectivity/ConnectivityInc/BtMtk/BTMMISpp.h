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
 * BTMMISpp.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is the header file for SPP application.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "bt_common_config.h"
 
#ifndef BT_MMI_SPP_H
#define BT_MMI_SPP_H

//#ifndef BT_DM_STRUCT_H
//#error "bt_dm_struct.h should be included"
//#endif

#ifndef BT_MMI_CM_H
#error "BTMMICm.h should be included"
#endif


/****************************************************************************
* Extern function
*****************************************************************************/ 
extern void SPPClientApp1_SDP_Result_Ind_CB(kal_uint8 srv_chnl_num);
extern void SPPClientApp1_SDP_Search_Cnf_CB(kal_uint8 result);
extern void SPPClientApp1_Connect_Cnf_CB(U8 result,U8 server_chnl_num,U8 con_id,U16 port,mmi_bth_bt_addr bd_addr);
extern void SPPClientApp1_Uart_Owner_Ind_CB(U16 port);
extern void SPPClientApp1_Uart_Ready_To_Read_Ind_CB(U16 port);
extern void SPPClientApp1_Uart_Ready_To_Write_Ind_CB(U16 port);
extern void SPPClientApp1_Uart_Plugout_Ind_CB(U16 port);
extern void SPPClientApp1_Disconnect_Ind_CB(void);
extern void SPPClientApp1_Disconnect_Cnf_CB(kal_bool result);

extern void SPPClientApp1_Audio_Connect_Cnf_CB(kal_uint8 result, kal_uint16 port);
extern void SPPClientApp1_Audio_Connect_Ind_CB(kal_uint16 port);
extern void SPPClientApp1_Audio_Disconnect_Cnf_CB(kal_uint8 result, kal_uint16 port);
extern void SPPClientApp1_Audio_Disconnect_Ind_CB(kal_uint16 port);


extern void SPPServerApp1_Connect_Ind_CB(U8 con_id,U16 port,mmi_bth_bt_addr bd_addr);
extern void SPPServerApp1_Uart_Owner_Ind_CB(U16 port);
extern void SPPServerApp1_Uart_Ready_To_Read_Ind_CB(U16 port);
extern void SPPServerApp1_Uart_Ready_To_Write_Ind_CB(U16 port);
extern void SPPServerApp1_Uart_Plugout_Ind_CB(U16 port);
extern void SPPServerApp1_Disconnect_Ind_CB(U16 port);


extern void SPPServerApp1_Audio_Connect_Cnf_CB(kal_uint8 result, kal_uint16 port);
extern void SPPServerApp1_Audio_Connect_Ind_CB(kal_uint16 port);
extern void SPPServerApp1_Audio_Disconnect_Cnf_CB(kal_uint8 result, kal_uint16 port);
extern void SPPServerApp1_Audio_Disconnect_Ind_CB(kal_uint16 port);


/***************************************************************************** 
* Macro
*****************************************************************************/

/***************************************************************************** 
* Definations
*****************************************************************************/
#if defined (__MMI_HFP_SUPPORT__) || defined(__MMI_HSP_SUPPORT__) 
#define MMI_NUM_HFG_PORT 1
#else
#define MMI_NUM_HFG_PORT 0
#endif

#ifdef __MMI_DUN_SUPPORT__
/* For Testing : Disable DUN: Let one general SPP Server, one SPP SCP Server, one general SPP Client, and one SPP SCO Client */
#define MMI_NUM_DUN_PORT 1
#else
#define MMI_NUM_DUN_PORT 0
#endif

#ifdef __MMI_FAX_SUPPORT__
#define MMI_NUM_FAX_PORT 1
#else
#define MMI_NUM_FAX_PORT 0
#endif

#define MMI_BTH_SPP_MAX_CONNECTION        (VIRTUAL_PORTS_NUM -MMI_NUM_HFG_PORT -MMI_NUM_DUN_PORT - MMI_NUM_FAX_PORT)

#define MMI_BTH_SPP_CLIENT_AVAILABLE_PORT   (5)
#define MMI_BTH_SPP_CLIENT_SDAP_MAX_CONNECTION        (2)

#define MMI_BTH_SDP_AID_PROTOCOL_DESC_LIST  0x0004
#define MMI_BTH_SDP_AID_SUPPORTED_CAPABILITIES   0x0310

/* This feature should be dependent on btconfig.h setting */
#if defined(__BT_SPP_SRV_WITH_SCO__) || defined(__BT_SPP_CLI_WITH_SCO__)
    #ifndef __MMI_SPP_SCO_SUPPORT__
    #define __MMI_SPP_SCO_SUPPORT__ 
    #endif
#endif

#if 0 /* Only for SPPClient UT to turn on */
/* under construction !*/
#endif

/***************************************************************************** 
* typedef 
*****************************************************************************/
typedef enum
{
	MMI_BTH_SPP_STAT_IDLE=0,
	MMI_BTH_SPP_STAT_ACTIVATE,
	MMI_BTH_SPP_STAT_CONNECT_REQ,
	MMI_BTH_SPP_STAT_CONNECTED,	
	MMI_BTH_SPP_STAT_DISCONNECT_REQ,
	MMI_BTH_SPP_STAT_DISC_AUDIO_LINK_FRIST_THEN_DISC_SPP_CHNL

} mmi_bth_spp_state_enum;

typedef enum
{
	MMI_BTH_SPP_STAT_AUDIO_IDLE=0,
	MMI_BTH_SPP_STAT_AUDIO_CONNECT_REQ,
	MMI_BTH_SPP_STAT_AUDIO_CONNECTED,	
	MMI_BTH_SPP_STAT_AUDIO_DISCONNECT_REQ

} mmi_bth_spp_audio_state_enum;



/* Add for SPP Client Application */
typedef enum
{
    MMI_BTH_SPP_SDP_PROCESS_NONE=0,
    MMI_BTH_SPP_SDP_ONGOING    

}mmi_bth_spp_sdp_operation_status_enum;

/* Add for SPP Client Application */
typedef enum
{
    MMI_BTH_SPP_CONNECT_PROCESS_NONE=0,
    MMI_BTH_SPP_CONNECT_ONGOING    

}mmi_bth_spp_connect_operation_status_enum;


/* Add for SPP Client Application: Query SDP Type with different attribute ID */
typedef enum
{
    MMI_BTH_SPP_SDP_WITH_ATTRIB_PROTOCOL_DESCRIPTOR_LIST=0,
    MMI_BTH_SPP_SDP_WITH_ATTRIB_SUPPORTED_CAPABILITIES    

}mmi_bth_spp_sdp_attribute_type_enum;

/* Add for SPP Client Application: Connection Type */
typedef enum
{
    MMI_BTH_SPP_CLIENT_WITHOUT_SCO_REQ=0,
    MMI_BTH_SPP_CLIENT_WITH_SCO_REQ    

}mmi_bth_spp_connect_type_enum;

/* Add for SPP Client Application */
typedef enum
{
    MMI_BTH_ACCEPT_SPP_SDP_REQUEST=0,
    MMI_BTH_REJECT_SPP_SDP_REQUEST

}mmi_bth_spp_sdp_operation_error_code_enum;


/* Add for SPP Client Application */
typedef enum
{
    MMI_BTH_ACCEPT_SPP_CONNECT=0, 
    MMI_BTH_REJECT_SPP_CONNECT,  
    MMI_BTH_SPP_CONNECT_REQ_REJECT_WITH_ALREADY_CONNECTING,
    MMI_BTH_SPP_CONNECT_REQ_REJECT_WITH_ALREADY_CONNECTED,
    MMI_BTH_SPP_NO_FREE_ENTRY,
    MMI_BTH_SPP_INVALID_CONNECTION_TYPE,
    MMI_BTH_SPP_INVAILD_STATE,
    MMI_BTH_SPP_AUDIO_CONNECT_INVALID_PORT,
    MMI_BTH_ACCEPT_SPP_AUDIO_CONNECT,
    MMI_BTH_SPP_AUDIO_DISCONNECT_INVALID_PORT,
    MMI_BTH_ACCEPT_SPP_AUDIO_DISCONNECT,
    MMI_BTH_SPP_AUDIO_ALREADY_DISCONNECTING_DUE_TO_SPP_DISC_REQ
}mmi_bth_spp_connect_operation_error_code_enum;



/***************************************************************************** 
* Structure
*****************************************************************************/

typedef struct
{
	mmi_bth_spp_state_enum state;
	U16 connect_id;
	U16 port;
	U32 lap;
	U8   uap;
	U16 nap;
       S8   server_chnl_num; /* only for SPP Client Application */
#ifdef __MMI_SPP_SCO_SUPPORT__       
       mmi_bth_spp_audio_state_enum audio_state;
#endif
       U8   app_inx; /* only for SPP Client Application */ 
} mmi_spp_cntx_struct;
	 

typedef struct
{
    U8 srv_chnl_num_no;
    S8 srv_chnl_num[MMI_BTH_SPP_CLIENT_AVAILABLE_PORT];
} mmi_spp_client_sdap_cntx_struct;	 


/* This FuncSet is registered by SPP Client's Application */
typedef struct RegisteredClientFuncSet
{
    void (*bt_spp_sdp_attribute_search_cnf_hdler)(U8 result);
    void (*bt_spp_sdp_attribute_search_result_ind_hdler)(U8 server_chnl_num); 	
    void (*bt_spp_connect_cnf_hdler)(U8 result,U8 server_chnl_num,U8 con_id,U16 port,mmi_bth_bt_addr bd_addr);
    void (*bt_spp_uart_owner_ind_hdler)(U16 port);
    void (*bt_spp_uart_ready_to_read_ind_hdler)(U16 port);
    void (*bt_spp_uart_ready_to_write_ind_hdler)(U16 port);
    void (*bt_spp_uart_plugout_ind_hdler)(U16 port);
    void (*bt_spp_disconnect_ind_hdler)(void);
    void (*bt_spp_disconnect_cnf_hdler)(kal_bool result);

#ifdef __MMI_SPP_SCO_SUPPORT__ 
    void (*bt_spp_audio_connect_cnf_hdler)(kal_uint8 result, kal_uint16 port);
    void (*bt_spp_audio_connect_ind_hdler)(kal_uint16 port);
    void (*bt_spp_audio_disconnect_cnf_hdler)(kal_uint8 result, kal_uint16 port);
    void (*bt_spp_audio_disconnect_ind_hdler)(kal_uint16 port);
#endif

    /* The purpose of this filed always_notified:
      * If this field is set TRUE, the callback of this SPP Client Application is always invoked upon receipt events.
      * No matter if his SPP Client Application is the original request initator or not.
      * Example: If SPP Client Application#1 issues a sdp request and this request is ongoing, 
      * then SPP Client Application#2 's sdp request is rejected due to the previous ongoing request.
      * 1.If the SPP Client Application#2 sets this filed as TRUE:
      * the SPP Client Application#2 will be also notified if the sdp request issued by SPP Client Application#1 has been done.
      * 2.Otherwise, only the request initator (i.e., SPP Client Application#1) will be notified.
      */
    kal_bool always_notified;

 }RegisteredClientFuncSet;



typedef struct RegisteredServerFuncSet
{
    kal_uint8 service_registered_port; /* the range from of service_registered_port is from (start_of_virtual_port) to (start_of_virtual_port + NUM_SPP_SERVERS -1) */
    void (*bt_spp_connect_ind_hdler)(U8 con_id,U16 port,mmi_bth_bt_addr bd_addr);
    void (*bt_spp_uart_owner_ind_hdler)(U16 port);
    void (*bt_spp_uart_ready_to_read_ind_hdler)(U16 port);
    void (*bt_spp_uart_ready_to_write_ind_hdler)(U16 port);
    void (*bt_spp_uart_plugout_ind_hdler)(U16 port);
    void (*bt_spp_disconnect_ind_hdler)(U16 port);
#ifdef __MMI_SPP_SCO_SUPPORT__ 
    void (*bt_spp_audio_connect_cnf_hdler)(kal_uint8 result, kal_uint16 port);
    void (*bt_spp_audio_connect_ind_hdler)(kal_uint16 port);
    void (*bt_spp_audio_disconnect_cnf_hdler)(kal_uint8 result, kal_uint16 port);
    void (*bt_spp_audio_disconnect_ind_hdler)(kal_uint16 port);
#endif

}RegisteredServerFuncSet;


 

/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/

/***************************************************************************** 
* Functions
*****************************************************************************/
void		mmi_bth_spp_init(void);
void mmi_bth_init_spp_event_handler(void);
void     mmi_bth_spp_activate_cnf_hdler(void *msg);
void     mmi_bth_spp_deactivate_cnf_hdler(void *msg);
void     mmi_bth_spp_connect_ind_hdler(void *msg);
void        mmi_bth_spp_disconnect_req_hdler(mmi_bth_bt_addr device_addr, U32 connect_id);
void     mmi_bth_spp_disconnect_cnf_hdler(void *msg);
void     mmi_bth_spp_disconnect_ind_hdler(void *msg);
void     mmi_bth_spp_authroize_hdler(void* msg);

/* This is first set SDP Event Callback Handler for SPP Client Application usage */
void    mmi_bth_spp_sdp_attribute_search_result_ind_hdler(void* msg);
void    mmi_bth_spp_sdp_attribute_search_cnf_hdler(void*msg);

/* This is second set SDP Event Handler for testing */
void   mmi_bth_spp_service_attribute_ind_hdler(void* msg);
void   mmi_bth_spp_service_attribute_result_hdler(void* msg);

/* Add by mtk01411:2007-0326 */
void     mmi_bth_spp_connect_cnf_hdler(void* msg);

/* Add by mtk01411:2007-0401 */
void mmi_bth_spp_uart_owner_ind_hdler(void *msg);

/* Add by mtk01411:2007-0401 */
void mmi_bth_spp_uart_readyToRead_ind_hdler(void *msg);
void    mmi_bth_spp_uart_readyToWrite_ind_hdler(void *msg);

/*Add by mtk01411:2007-0409 */
void mmi_bth_spp_uart_plugout_ind_hdler(void *msg);

void mmi_bth_spp_send_uart_owner_cnf_hdler(U16 port);
void mmi_bth_spp_send_uart_plugout_cnf_hdler(U16 port);

#ifdef __MMI_SPP_SCO_SUPPORT__
/* Add by mtk01411:2007-0709 */
void    mmi_bth_spp_audio_connect_cnf_hdler(void *msg);
void    mmi_bth_spp_audio_connect_ind_hdler(void *msg);
void    mmi_bth_spp_audio_disconnect_cnf_hdler(void *msg);
void    mmi_bth_spp_audio_disconnect_ind_hdler(void *msg);
#endif

#if defined (__MMI_SPP_CLIENT_USAGE_DEMO__) && defined(__MMI_SPP_SCO_SUPPORT__)
void    mmi_bth_spp_sco_rssi_ind_hdler(void* msg);
#endif

#endif//end of BT_MMI_SPP_H


