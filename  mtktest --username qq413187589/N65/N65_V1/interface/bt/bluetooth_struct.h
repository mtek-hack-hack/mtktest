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
 *   bluetooth_struct.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is defines SAP for MTK Bluetooth.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __BLUETOOTH_STRUCT_H_
#define __BLUETOOTH_STRUCT_H_

/* MSG_ID_BT_SPP_CONNECT_REQ : by stanley 2007-0313 */
typedef struct
{
    kal_uint8 	ref_count;
    kal_uint16 	msg_len;
    kal_uint32      lap;
    kal_uint8        uap;
    kal_uint16      nap; 
    kal_uint8    server_chnl_num;
}bt_spp_connect_req_struct;


/*MSG_ID_BT_SPP_SEND_DATA_REQ*/
typedef struct
{
       kal_uint8	        ref_count;
       kal_uint16	 msg_len;
	UART_PORT	 port;	/* virtual port number*/
} bt_spp_send_data_req_struct; 

/*MSG_ID_BT_SPP_GET_DATA_REQ*/
typedef struct
{
       kal_uint8	        ref_count;
       kal_uint16	 msg_len;
	UART_PORT	 port;	/* virtual port number*/
} bt_spp_get_data_req_struct; 

/*MSG_ID_BT_SPP_CONNECT_IND*/
typedef struct
{
       kal_uint8	        ref_count;
       kal_uint16	 msg_len;
	UART_PORT	 port;	/* virtual port number*/
	kal_uint8         cid; /*connection id*/
	kal_uint32       lap;
	kal_uint8         uap;
	kal_uint16       nap;	
} bt_spp_connect_ind_struct; 


/*MSG_ID_BT_SPP_DISCONNECT_REQ*/
typedef struct
{
       kal_uint8	        ref_count;
       kal_uint16	 msg_len;
	UART_PORT	 port;	/* virtual port number*/
} bt_spp_disconnect_req_struct; 

typedef struct
{
       kal_uint8	        ref_count;
       kal_uint16	 msg_len;
	UART_PORT	 port;	/* virtual port number*/
} bt_spp_audio_connect_req_struct; 

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    UART_PORT port;	/* virtual port number*/
} bt_spp_audio_disconnect_req_struct; 


/*MSG_ID_BT_SPP_DISCONNECT_IND*/
typedef struct
{
       kal_uint8	        ref_count;
       kal_uint16	 msg_len;
	UART_PORT	 port;	/* virtual port number*/
} bt_spp_disconnect_ind_struct; 

typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    UART_PORT port;	/* virtual port number*/
    kal_uint8 result;
}bt_spp_audio_connect_cnf_struct;

typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    UART_PORT port;	/* virtual port number*/
}bt_spp_audio_connect_ind_struct;

typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    UART_PORT port;	/* virtual port number*/
    kal_uint8 result;
}bt_spp_audio_disconnect_cnf_struct;

typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    UART_PORT port;	/* virtual port number*/
}bt_spp_audio_disconnect_ind_struct;



/* MSG_ID_BT_SPP_DISCONNECT_CNF : Add by stanley 2007-0326 */
typedef struct
{
	kal_uint8		ref_count;
	kal_uint16      msg_len;
	UART_PORT	 port;	/* virtual port number*/
	kal_uint8         cid;       /*connection id*/
	kal_uint32       lap;
	kal_uint8         uap;
	kal_uint16       nap;
	kal_uint8         result;  /* This is result field of this returned cnf msg */
} bt_spp_disconnect_cnf_struct;




/*MSG_ID_BT_SPP_AUTH_REQ : add 2007-01-15*/
typedef struct
{
       kal_uint8	 ref_count;
       kal_uint16	 msg_len;
	UART_PORT	 port;	 /* virtual port number*/
	   
} bt_spp_auth_req_struct; 


/* MSG_ID_BT_SPP_CONNECT_CNF: Add  by stanley 2007-0320 */
typedef struct
{
	kal_uint8	        ref_count;
       kal_uint16	 msg_len;
	UART_PORT	 port;	/* virtual port number*/
	kal_uint8         cid;       /*connection id*/
	kal_uint32       lap;
	kal_uint8         uap;
	kal_uint16       nap;
	kal_uint8         result;  /* This is result field of this returned cnf msg */
       kal_uint8         server_chnl_num; /*Add bt stanley: 2007-0709 */
}bt_spp_connect_cnf_struct;



/*MSG_ID_BT_SPP_AUTH_RSP : add 2007-01-12*/
typedef struct
{
       kal_uint8	 ref_count;
       kal_uint16	 msg_len;
	   UART_PORT	 port;	 /* virtual port number*/
	   kal_bool      result; /* TRUE: accepted by MMI */
} bt_spp_auth_rsp_struct; 

/*MSG_ID_BT_SPP_UART_OWNER_IND : add 2007-0401*/
typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;
    UART_PORT   port;
}bt_spp_uart_owner_ind_struct;
 
/*MSG_ID_BT_SPP_UART_OWNER_CNF : add 2007-0402*/

typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;
    UART_PORT   port;
}bt_spp_uart_owner_cnf_struct;

/*MSG_ID_BT_SPP_UART_PLUGOUT_CNF : add 2007-0409*/
typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;
    UART_PORT   port;
}bt_spp_uart_plugout_cnf_struct;

/* MSG_ID_BT_SPP_SCO_RSSI_IND : Add 2007-0912 */
typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;
    kal_uint8 bd_address[6];
    kal_uint8 rssi_value;
}bt_spp_sco_rssi_ind_struct;

/*MSG_ID_BT_DUN_CONNECT_IND*/
typedef struct
{
       kal_uint8	        ref_count;
       kal_uint16	 msg_len;
	UART_PORT	 port;	/* virtual port number*/
	kal_uint8         cid; /*connection id*/
	kal_uint32       lap;
	kal_uint8         uap;
	kal_uint16       nap;
} bt_dun_connect_ind_struct; 


/*MSG_ID_BT_DUN_DISCONNECT_REQ*/
typedef struct
{
       kal_uint8	        ref_count;
       kal_uint16	 msg_len;
	UART_PORT	 port;	/* virtual port number*/
} bt_dun_disconnect_req_struct; 

/*MSG_ID_BT_DUN_DISCONNECT_IND*/
typedef struct
{
       kal_uint8	        ref_count;
       kal_uint16	 msg_len;
	UART_PORT	 port;	/* virtual port number*/
} bt_dun_disconnect_ind_struct; 

/*MSG_ID_BT_DUN_AUTH_RSP : add 2007-01-12*/
typedef struct
{
       kal_uint8	 ref_count;
       kal_uint16	 msg_len;
	   UART_PORT	 port;	 /* virtual port number*/
	   kal_bool      result; /* TRUE: accepted by MMI */
} bt_dun_auth_rsp_struct; 

/*MSG_ID_BT_FAX_CONNECT_IND:Add by stanley 2006-11-22*/
typedef struct
{
    kal_uint8	 ref_count;
    kal_uint16	 msg_len;
	UART_PORT	 port;	/* virtual port number*/
	kal_uint8    cid; /*connection id*/
	kal_uint32   lap;
	kal_uint8    uap;
	kal_uint16   nap;
} bt_fax_connect_ind_struct; 


/*MSG_ID_BT_FAX_DISCONNECT_REQ:Add by stanley 2006-11-22*/
typedef struct
{
    kal_uint8	 ref_count;
    kal_uint16	 msg_len;
	UART_PORT	 port;	/* virtual port number*/
} bt_fax_disconnect_req_struct; 

/*MSG_ID_BT_FAX_DISCONNECT_IND:Add by stanley 2006-11-22*/
typedef struct
{
    kal_uint8	 ref_count;
    kal_uint16	 msg_len;
	UART_PORT	 port;	/* virtual port number*/
} bt_fax_disconnect_ind_struct; 

/*MSG_ID_BT_FAX_AUTH_RSP : add 2007-01-12*/
typedef struct
{
       kal_uint8	 ref_count;
       kal_uint16	 msg_len;
	   UART_PORT	 port;	 /* virtual port number*/
	   kal_bool      result; /* TRUE: accepted by MMI */
} bt_fax_auth_rsp_struct; 


/*MSG_ID_BT_SPP_CONNECT_IND*/
typedef struct
{
	kal_uint8	        ref_count;
	kal_uint16	 msg_len;
	UART_PORT	 port;	/* virtual port number*/
} bt_hf_connect_ind_struct;


/*MSG_ID_BT_HFG_SEND_DATA_REQ*/
typedef struct
{
       kal_uint8	        ref_count;
       kal_uint16	 msg_len;
	UART_PORT	 port;	/* virtual port number*/
} bt_hf_send_data_req_struct; 

/*MSG_ID_BT_POWERON_CNF*/
typedef struct
{
       kal_uint8	        ref_count;
       kal_uint16	 msg_len;
	kal_bool	        result;	/* TRUE: successful, FALSE: failed*/
} bt_poweron_cnf_struct; 

typedef struct
{
       kal_uint8	        ref_count;
       kal_uint16	 msg_len;
	kal_bool	        result;	/* TRUE: successful, FALSE: failed*/
} bt_engineer_mode_poweron_cnf_struct; 

/*MSG_ID_BT_POWEROFF_CNF*/
typedef struct
{
       kal_uint8	        ref_count;
       kal_uint16	 msg_len;
	kal_bool	        result;	/* TRUE: successful, FALSE: failed*/
} bt_poweroff_cnf_struct; 

typedef struct
{
    LOCAL_PARA_HDR
    kal_bool afh; //True: send AFH command
    kal_uint32 freq;
    kal_bool pta; //True: send PTA command
    kal_uint8 pta_action;
}  bt_wifi_set_chnl_req_struct;

/*MSG_ID_BT_MMI_RESET_CNF*/
typedef struct
{
       kal_uint8	        ref_count;
       kal_uint16	 msg_len;
	kal_bool	        result;	/* TRUE: successful, FALSE: failed*/
} bt_mmi_reset_cnf_struct; 

/*MSG_ID_BT_TEST_MODE_REQ*/
typedef struct
{
	kal_uint8 ref_count;
	kal_uint16 msg_len;
	kal_uint8 mode;// 1: enter test mode, 2: leave test mode
#ifdef __GEMINI__	
	kal_uint8 dual_sim_uart_setting; /* 0: L4C_UART_TO_SIM1, 1: L4C_UART_UART_TO_SIM2 */
#endif
}bt_test_mode_req_struct;

typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 name[32];
   kal_uint8 bd_addr[6];
   kal_uint8 dcs;
} bt_set_bd_param_req_struct;

typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 index;
   kal_uint8 external_pa;
   kal_uint8 internal_pa;
   kal_uint16 output_power;
} bt_set_power_table_req_struct;

typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint16 trim_value;
}  bt_set_ana_trim_req_struct;

typedef struct{
	kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_bool result;
} bt_pcm_lb_rsp_struct;

typedef struct
{
    kal_uint8	ref_count;
    kal_uint16	msg_len;
    kal_bool	result;	/* TRUE: successful, FALSE: failed*/
    kal_uint16  chip_version;
    kal_uint16  lmp_version;
} bt_get_bt_version_cnf_struct; 


typedef struct{
	kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_bool result;
} bt_l4c_at_general_cnf_struct;

typedef struct{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool result;
} bt_engineer_mode_cnf_struct;

typedef struct{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 pattern;
    kal_uint8 channel_hopping;
    kal_uint8 tx_freq;
    kal_uint8 rx_freq;
    kal_uint8 poll_period;
    kal_uint8 packet_type;
    kal_uint16 packet_length;
} bt_engineer_mode_txrx_test_req_struct;

typedef struct{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool result;
} bt_engineer_mode_txrx_test_cnf_struct;

typedef struct{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 level;
} bt_engineer_mode_power_test_req_struct;


typedef struct{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool result;
} bt_engineer_mode_txrx_power_cnf_struct;

#ifdef __GEMINI__
/* MSG_ID_BT_ENGINEER_MODE_POWERON_REQ */
typedef struct{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 dual_sim_uart_setting;
}bt_engineer_mode_poweron_req_struct;
#endif

typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
#ifdef __GEMINI__   
   kal_uint8 dual_sim_uart_setting; /* 0: L4C_UART_TO_SIM1, 1: L4C_UART_UART_TO_SIM2 */
#endif
}  bt_read_bd_addr_req_struct;

typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_bool result;
   kal_uint8 bd_addr[6];	
}  bt_read_bd_addr_cnf_struct;

/*MSG_ID_BT_TEST_CMD_REQ*/
typedef struct{
	kal_uint8 ref_count;
	kal_uint16 msg_len;  
	kal_uint8 test_cmd_content[256];
}bt_test_cmd_req_struct;

/* MSG_ID_BT_L4C_TEST_CMD_CNF*/
typedef struct{
	kal_uint8 ref_count;
	kal_uint16 msg_len;
	kal_uint8 test_cmd_rsp_buf[256];
  kal_uint16 length;
}bt_test_cmd_rsp_struct;


/* BPP definitions */
#define BPP_FMGR_MAX_PATH_LEN 260
#define BPP_FMGR_MAX_FILE_LEN 41
#define BPP_ENCODING_LENGTH 2
#define OBRC_SCO_REJECT 0xFF /* SCO REJECT */

/* BIP definitions */
#define BT_BIP_MAX_PATH_LEN     260
#define BT_BIP_MAX_IMG_FORMATS  10
#define BT_BIP_MAX_IMG_NAME_LEN 256
#define BT_BIP_MAX_TIME_LEN     32
#define BT_BIP_IMG_HANDLE_LEN   8
#define BT_BIP_MAX_DEV_NAME_LEN 80
#define BT_BIP_MAX_ATTR_NAME_LEN 40
#define BT_BIP_MAX_IMG_LIST_ITEMS 32
#define BT_BIP_ENCODING_LENGTH 2

/* BPP Create Job Flag */
#define BPP_ADP_DOC_FORMAT_MASK_XHTML       (0x01)
#define BPP_ADP_DOC_FORMAT_MASK_XHTML_MULTI (0x02)
#define BPP_ADP_SIDES_MASK_ONE          (0x01)
#define BPP_ADP_SIDES_MASK_TWO_LONG     (0x02)
#define BPP_ADP_SIDES_MASK_TWO_SHORT    (0x04)
#define BPP_ADP_NUMBER_UP_MASK_1        (0x01)
#define BPP_ADP_NUMBER_UP_MASK_2        (0x02)
#define BPP_ADP_NUMBER_UP_MASK_4        (0x04)
#define BPP_ADP_ORIENTATION_MASK_P      (0x01)
#define BPP_ADP_ORIENTATION_MASK_L      (0x02)
#define BPP_ADP_MEDIA_MASK_A4           (0x01)
#define BPP_ADP_MEDIA_MASK_US           (0x02)
#define BPP_ADP_MEDIA_MASK_4X6          (0x04)
#define BPP_ADP_MEDIA_MASK_4X6_IOT      (0x08)
#define BPP_ADP_QUALITY_MASK_HIGH       (0x01)
#define BPP_ADP_QUALITY_MASK_NORMAL     (0x02)
#define BPP_ADP_QUALITY_MASK_DRAFT      (0x04)
/* GOEP definitions */
#define GOEP_MAX_UUID_SIZE 16
#define GOEP_MAX_PASSWD_SIZE 16
#define GOEP_MAX_REALM_SIZE 20
#define GOEP_MAX_USERID_SIZE 20
#define GOEP_MAX_OBJ_NAME 256
#define GOEP_MAX_FOLDER_NAME 256
#define GOEP_MAX_DEV_NAME 80
#define GOEP_MAX_DESCRIPTION 80
#define GOEP_MAX_MIME_TYPE 80
#define GOEP_MAX_SERVER_NUM 16
#define GOEP_MAX_CLIENT_NUM 16
#define GOEP_CONNECTION_NUM (GOEP_MAX_SERVER_NUM + GOEP_MAX_CLIENT_NUM)


/* The function call was successful. */
#define GOEP_STATUS_SUCCESS          0 
/* The operation has failed to start. */
#define GOEP_STATUS_FAILED           1 
/* The operation is pending to wait for authentication information */
#define GOEP_STATUS_PENDING          2
/* The transport layer link is disconnected. */
#define GOEP_STATUS_DISCONNECT       3
/* No connection exists, when one is required */
#define GOEP_STATUS_NO_CONNECT       4
/* A request is pending or resources are in use. */
#define GOEP_STATUS_BUSY             11
/* The necessary resources are not available. */
#define GOEP_STATUS_NO_RESOURCES     12
/* An invalid function parameter was provided. */
#define GOEP_STATUS_INVALID_PARM     18
/* Bluetooth Only: The request failed because the specified device
 *                 is in the process of being disconnected.
 */
#define GOEP_STATUS_IN_PROGRESS      19
/* Feature not supported */
#define GOEP_STATUS_NOT_SUPPORTED    23
/* Bluetooth Only : Feature is restricted, due to a 
 *                  Bluetooth security failure 
 */
#define GOEP_STATUS_RESTRICTED       20
/* The OBEX packet is too small to support the request. */
#define GOEP_STATUS_PACKET_TOO_SMALL 31
/* No active session exists, when one is required. */
#define GOEP_STATUS_NO_SESSION       32

/* SCO_REJECT */
#define GOEP_STATUS_SCO_REJECT       25


#define GOEP_CREATED              0x21 /* Created */
#define GOEP_ACCEPTED             0x22 /* Accepted */
#define GOEP_NON_AUTHOR_INFO      0x23 /* Non-Authoritative Information */
#define GOEP_NO_CONTENT           0x24 /* No Content */
#define GOEP_RESET_CONTENT        0x25 /* Reset Content */
#define GOEP_PARTIAL_CONTENT      0x26 /* Partial Content */

#define GOEP_MULTIPLE_CHOICES     0x30 /* Multiple Choices */
#define GOEP_MOVED_PERMANENT      0x31 /* Moved Permanently */
#define GOEP_MOVED_TEMPORARY      0x32 /* Moved Temporarily */
#define GOEP_SEE_OTHER            0x33 /* See Other */
#define GOEP_NOT_MODIFIED         0x34 /* Not Modified */
#define GOEP_USE_PROXY            0x35 /* Use Proxy */

#define GOEP_BAD_REQUEST          0x40 /* Bad Request */
#define GOEP_UNAUTHORIZED         0x41 /* Unauthorized */
#define GOEP_PAYMENT_REQUIRED     0x42 /* Payment Required */
#define GOEP_FORBIDDEN            0x43 /* Forbidden - operation is understood
                                        * but refused */
#define GOEP_NOT_FOUND            0x44 /* Not Found */
#define GOEP_METHOD_NOT_ALLOWED   0x45 /* Method Not Allowed */
#define GOEP_NOT_ACCEPTABLE       0x46 /* Not Acceptable */
#define GOEP_PROXY_AUTHEN_REQ     0x47 /* Proxy Authentication Required */
#define GOEP_REQUEST_TIME_OUT     0x48 /* Request Timed Out */
#define GOEP_CONFLICT             0x49 /* Conflict */

#define GOEP_GONE                 0x4a /* Gone */
#define GOEP_LENGTH_REQUIRED      0x4b /* Length Required */
#define GOEP_PRECONDITION_FAILED  0x4c /* Precondition Failed */
#define GOEP_REQ_ENTITY_TOO_LARGE 0x4d /* Requested entity is too large */
#define GOEP_REQ_URL_TOO_LARGE    0x4e /* Requested URL is too large */
#define GOEP_UNSUPPORT_MEDIA_TYPE 0x4f /* Unsupported Media Type */

#define GOEP_INTERNAL_SERVER_ERR  0x50 /* Internal Server Error */
#define GOEP_NOT_IMPLEMENTED      0x51 /* Not Implemented */
#define GOEP_BAD_GATEWAY          0x52 /* Bad Gateway */
#define GOEP_SERVICE_UNAVAILABLE  0x53 /* Service Unavailable */
#define GOEP_GATEWAY_TIMEOUT      0x54 /* Gateway Timeout */
#define GOEP_HTTP_VER_NO_SUPPORT  0x55 /* HTTP version not supported */

#define GOEP_DATABASE_FULL        0x60 /* Database Full */
#define GOEP_DATABASE_LOCKED      0x61 /* Database Locked */

/* End of GOEPStatus */


/* GOEP ENUM */
typedef enum
{
    GOEP_TP_BT = 0,
    GOEP_TP_IRDA
} goep_tp_type_enum;

typedef enum
{
    GOEP_FIRST_PKT = 0,
	GOEP_NORMAL_PKT,
	GOEP_FINAL_PKT,
	GOEP_SINGLE_PKT
} goep_pkt_type_enum;

typedef enum
{
    GOEP_FORWARD_FOLDER = 0,
    GOEP_BACK_FOLDER,
    GOEP_ROOT_FOLDER,
    GOEP_CREATE_FOLDER
} goep_set_folder_type_enum;

typedef enum
{
    GOEP_PUT_NORMAL = 0,
    GOEP_PUT_DELETE,
    GOEP_CREATEEMPTY
} goep_put_type_enum;

typedef enum
{
    GOEP_SERVER_ROLE = 0,
    GOEP_CLIENT_ROLE
} goep_role_enum;

/**** BPP Enum ****/
typedef enum
{
    BT_BPP_CNF_SUCCESS = 0,
    BT_BPP_CNF_FAILED,
    BT_BPP_CNF_AUTH_FAILED,
    BT_BPP_CNF_SERVICE_UNAVAILABLE,
    BT_BPP_CNF_SCO_REJECT,
    BT_BPP_CNF_RACE_CONDITION,
    BT_BPP_CNF_STATUS_FAILED,
    BT_BPP_CNF_WRITE_FILE_FAILED,    
    BT_BPP_CNF_TOTAL
} bt_bpp_cnf_enum;


typedef enum
{
    BT_BPP_GET_EVENT_ON = 0,
    BT_BPP_GET_EVENT_FAILED,
    BT_BPP_GET_EVENT_OFF,
    BT_BPP_GET_EVENT_DISCONNECTING,
    BT_BPP_GET_EVENT_TOTAL
} bt_bpp_get_event_enum;

typedef enum
{
    BT_BPP_JOB_STATE_STOPPED = 0,
    BT_BPP_JOB_STATE_ABORTED,
    BT_BPP_JOB_STATE_CANCELED,
    BT_BPP_JOB_STATE_UNKNOWN,
    BT_BPP_JOB_STATE_PRINTING,
    BT_BPP_JOB_STATE_TOTAL
} bt_bpp_job_state_enum;

typedef enum
{
    BT_BPP_PRINTER_STATE_STOPPED = 0,
    BT_BPP_PRINTER_STATE_PROCESSING,
    BT_BPP_PRINTER_STATE_TOTAL
} bt_bpp_printer_state_enum;

typedef enum
{
    BT_BPP_PRINTER_REASON_ATTENTION = 0,
    BT_BPP_PRINTER_REASON_JAM,
    BT_BPP_PRINTER_REASON_PAUSED,
    BT_BPP_PRINTER_REASON_DOOR,
    BT_BPP_PRINTER_REASON_MEDIA,
    BT_BPP_PRINTER_REASON_OUTPUT,
    BT_BPP_PRINTER_REASON_MARKER,
    BT_BPP_PRINTER_REASON_TOTAL
} bt_bpp_printer_reason_enum;

typedef enum
{
    BT_BPP_TYPE_XHTML = 0,
    BT_BPP_TYPE_XHTML_MULTI,        
    BT_BPP_TYPE_TOTAL
} bt_bpp_type_enum;
/**** End of BPP Enum ****/

/**** Start of BIP Enum ****/
typedef enum
{
    BT_BIP_IMAGE_PUSH = 0x01,
    BT_BIP_IMAGE_PULL = 0x02,
    BT_BIP_ADVANCED_PRINTING = 0x04,
    BT_BIP_REMOTE_CAMERA = 0x08,
    BT_BIP_AUTO_ARCHIVE = 0x10,
    BT_BIP_REMOTE_DISPLAY = 0x20
} bt_bip_service_enum;

typedef enum
{
    BT_BIP_CNF_SUCCESS = 0x70,
    BT_BIP_CNF_FAILED,
    BT_BIP_PARTIAL_CONTENT,
    BT_BIP_XML_GEN_FAIL,
    BT_BIP_FILE_OPEN_FAIL,
    BT_BIP_FILE_READ_FAIL,
    BT_BIP_FILE_WRITE_FAIL,
    BT_BIP_FILE_MOVE_FAIL,
    BT_BIP_INVALID_PARM,    
    BT_BIP_DISK_FULL,
    BT_BIP_ROOT_DIR_FULL,
    BT_BIP_SCO_REJECT,
    BT_BIP_BTCHIP_REJECT
} bt_bip_cnf_enum;

typedef enum
{
    BT_BIP_IMG_TYPE_UNSUPPORT = 0x00000000,
    BT_BIP_IMG_TYPE_JPEG    = 0x00000001,
    BT_BIP_IMG_TYPE_BMP     = 0x00000002,
    BT_BIP_IMG_TYPE_GIF     = 0x00000004,
    BT_BIP_IMG_TYPE_WBMP    = 0x00000008,
    BT_BIP_IMG_TYPE_PNG     = 0x00000010
} bt_bip_img_format_enum;

/**** End of BIP Enum ****/

/* GOEP structure */

typedef struct 
{
    kal_uint32 lap;
	kal_uint8 uap;
	kal_uint16 nap;
} goep_bd_addr_struct;

typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 uuid[GOEP_MAX_UUID_SIZE];
    kal_uint8 uuid_len;
    kal_uint8 req_id;
    goep_tp_type_enum tp_type;
    kal_bool need_auth;
    kal_uint8* buf_ptr;
    kal_uint16 buf_size;
} goep_register_server_req_struct;

typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 uuid[GOEP_MAX_UUID_SIZE];
    kal_uint8 uuid_len;
    kal_uint8 req_id;
    kal_uint8 rsp_code;
    kal_uint8 goep_conn_id;
} goep_register_server_rsp_struct;

typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 goep_conn_id;
} goep_deregister_server_req_struct;

typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 uuid[GOEP_MAX_UUID_SIZE];
    kal_uint8 uuid_len;
    kal_uint8 goep_conn_id;
    goep_bd_addr_struct bd_addr;
    kal_uint8 dev_name[GOEP_MAX_DEV_NAME];
} goep_authorize_ind_struct;

typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 uuid[GOEP_MAX_UUID_SIZE];
    kal_uint8 uuid_len;
    kal_uint8 goep_conn_id;
    goep_bd_addr_struct bd_addr;
    kal_uint8 dev_name[GOEP_MAX_DEV_NAME];
    kal_uint16 peer_mru;
    kal_uint32 cm_conn_id;
} goep_connect_ind_struct;

typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 uuid[GOEP_MAX_UUID_SIZE];
    kal_uint8 uuid_len;
    kal_uint8 goep_conn_id;
    goep_pkt_type_enum pkt_type;
    goep_put_type_enum put_type;
    kal_uint32 total_obj_len;
    kal_uint8 obj_name[GOEP_MAX_OBJ_NAME];
    kal_uint8 obj_mime_type[GOEP_MAX_MIME_TYPE];
    kal_uint8* frag_ptr;
    kal_uint16 frag_len;
} goep_push_ind_struct;

typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 uuid[GOEP_MAX_UUID_SIZE];
    kal_uint8 uuid_len;
    kal_uint8 goep_conn_id;
    goep_pkt_type_enum pkt_type;
    kal_uint8 obj_mime_type[GOEP_MAX_MIME_TYPE];
    kal_uint8 obj_name[GOEP_MAX_OBJ_NAME];
} goep_pull_ind_struct;

typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 goep_conn_id;
    goep_pkt_type_enum pkt_type;
    kal_uint8 rsp_code;
    kal_uint8 obj_mime_type[GOEP_MAX_MIME_TYPE];
    kal_uint32 total_obj_len;
    kal_uint8* frag_ptr;
    kal_uint16 frag_len;
} goep_pull_res_struct;

typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 uuid[GOEP_MAX_UUID_SIZE];
    kal_uint8 uuid_len;
    kal_uint8 goep_conn_id;
    goep_set_folder_type_enum setpath_flag;
    kal_uint8 folder_name[GOEP_MAX_FOLDER_NAME];
} goep_set_folder_ind_struct;

typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 uuid[GOEP_MAX_UUID_SIZE];
    kal_uint8 uuid_len;
    kal_uint8 goep_conn_id;
} goep_abort_ind_struct;

typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 uuid[GOEP_MAX_UUID_SIZE];
    kal_uint8 uuid_len;
    kal_uint8 req_id;
    kal_uint8 goep_conn_id;
    kal_uint8 passwd[GOEP_MAX_PASSWD_SIZE];
    kal_uint8 passwd_len;
    kal_uint8 realm_str[GOEP_MAX_REALM_SIZE];
    kal_uint8 realm_len;
    goep_role_enum goep_role;
} goep_auth_req_struct;

typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 uuid[GOEP_MAX_UUID_SIZE];
    kal_uint8 uuid_len;
    kal_uint8 req_id;
    goep_bd_addr_struct bd_addr;
    goep_tp_type_enum tp_type;
    kal_uint8* buf_ptr;
    kal_uint16 buf_size;
    kal_bool auth_use;
    kal_uint8 passwd[GOEP_MAX_PASSWD_SIZE];
    kal_uint8 passwd_len;
    kal_uint8 realm[GOEP_MAX_REALM_SIZE];
    kal_uint8 realm_len;
} goep_connect_req_struct;

typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 uuid[GOEP_MAX_UUID_SIZE];
    kal_uint8 uuid_len;
    kal_uint8 req_id;
    kal_uint8 goep_conn_id;
    kal_uint8 rsp_code;
    kal_uint16 peer_mru;
    kal_uint32 cm_conn_id;
} goep_connect_rsp_struct;

typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 goep_conn_id;
    goep_pkt_type_enum pkt_type;
    goep_put_type_enum put_type;
    kal_uint8 obj_mime_type[GOEP_MAX_MIME_TYPE];
    kal_uint32 total_obj_len;
    kal_uint8 obj_name[GOEP_MAX_OBJ_NAME];
    kal_uint8* frag_ptr;
    kal_uint16 frag_len;
} goep_push_req_struct;

typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 uuid[GOEP_MAX_UUID_SIZE];
    kal_uint8 uuid_len;
    kal_uint8 goep_conn_id;
    kal_uint8 rsp_code;
    kal_uint8 reason;  /* failed reason. added for application */
} goep_push_rsp_struct;

typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 goep_conn_id;
    goep_pkt_type_enum pkt_type;
    kal_uint8 obj_mime_type[GOEP_MAX_MIME_TYPE];
    kal_uint8 obj_name[GOEP_MAX_OBJ_NAME];
} goep_pull_req_struct;

typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 uuid[GOEP_MAX_UUID_SIZE];
    kal_uint8 uuid_len;
    kal_uint8 goep_conn_id;
    goep_pkt_type_enum pkt_type;
    kal_uint8 rsp_code;
    kal_uint32 total_obj_len;
    kal_uint8* frag_ptr;
    kal_uint16 frag_len;
    kal_bool to_self;    /* added for continue parsing large folder content */
    kal_uint8 reason;  /* failed reason. added for application */
} goep_pull_rsp_struct;

typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 goep_conn_id;
    goep_set_folder_type_enum setpath_flag;
    kal_uint8 folder_name[GOEP_MAX_FOLDER_NAME];
} goep_set_folder_req_struct;


typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 uuid[GOEP_MAX_UUID_SIZE];
    kal_uint8 uuid_len;
    kal_uint8 goep_conn_id;
    kal_uint8 rsp_code;
    kal_uint8 reason;  /* failed reason. added for application */
} goep_set_folder_rsp_struct;


typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 goep_conn_id;
} goep_abort_req_struct;

typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 req_id;
    kal_uint8 goep_conn_id;
} goep_disconnect_req_struct;

typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 uuid[GOEP_MAX_UUID_SIZE];
    kal_uint8 uuid_len;
    kal_uint8 goep_conn_id;
    kal_uint8 rsp_code;
} goep_disconnect_rsp_struct;

typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 uuid[GOEP_MAX_UUID_SIZE];
    kal_uint8 uuid_len;
    kal_uint8 req_id;
    kal_uint8 goep_conn_id;
} goep_disconnect_ind_struct;

typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 uuid[GOEP_MAX_UUID_SIZE];
    kal_uint8 uuid_len;
    kal_uint8 goep_conn_id;
    kal_uint8 req_id;
    kal_uint8 realm[GOEP_MAX_REALM_SIZE];
    kal_uint8 realm_len;
    kal_uint8 dev_name[GOEP_MAX_DEV_NAME];
} goep_auth_ind_struct;

typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 goep_conn_id;
    kal_uint8 passwd[GOEP_MAX_PASSWD_SIZE];
    kal_uint8 passwd_len;
    kal_uint8 userid[GOEP_MAX_USERID_SIZE];
    kal_uint8 userid_len;
} goep_auth_res_struct;

typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 uuid[GOEP_MAX_UUID_SIZE];
    kal_uint8 uuid_len;
    kal_uint8 goep_conn_id;
    kal_uint8 rsp_code;
} goep_rsp_struct;

/**** BPP Structure ****/
typedef struct 
{
    kal_uint8           ref_count;
    kal_uint16          msg_len;
    goep_bd_addr_struct     bd_addr;
} bt_bpp_connect_req_struct;

typedef struct 
{
    kal_uint8           ref_count;
    kal_uint16          msg_len;
    bt_bpp_cnf_enum     cnf_code;
    kal_uint32          cm_conn_id;
    kal_uint8           dev_name[GOEP_MAX_DEV_NAME];
} bt_bpp_connect_cnf_struct;

typedef struct 
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;
    kal_uint8   realm[GOEP_MAX_REALM_SIZE];
    kal_uint16  realm_len;
} bt_bpp_authentication_ind_struct;

typedef struct 
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;
    kal_bool    cancel;
    kal_uint8   passwd[GOEP_MAX_PASSWD_SIZE];
    kal_uint16  passwd_len;    
} bt_bpp_authentication_rsp_struct;

typedef struct 
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;
    kal_uint32  cm_conn_id;
    kal_bool    disc_timeout;
} bt_bpp_disconnect_req_struct;

typedef struct
{
    kal_uint8       ref_count;
    kal_uint16      msg_len;
    kal_uint32      cm_conn_id;
    bt_bpp_cnf_enum cnf_code;
} bt_bpp_disconnect_ind_struct;

typedef struct
{
    kal_uint8       ref_count;
    kal_uint16      msg_len;    
    kal_uint32      cm_conn_id;          
    kal_bool        DocFormat;
    kal_bool        Copies;
    kal_bool        Sides;    
    kal_bool        NumberUp;    
    kal_bool        Orientation;
    kal_bool        Media;
    kal_bool        Quality;        
} bt_bpp_get_printer_attr_req_struct;

typedef struct
{
    kal_uint8       ref_count;
    kal_uint16      msg_len;
    kal_uint32      cm_conn_id;
    bt_bpp_cnf_enum cnf_code;
    kal_uint8       DocFormat;
    kal_uint16      Copies;
    kal_uint8       Sides;    
    kal_uint8       NumberUp;    
    kal_uint8       Orientation;
    kal_uint8       Media;
    kal_uint8       Quality;        
} bt_bpp_get_printer_attr_cnf_struct;

typedef struct
{
    kal_uint8       ref_count;
    kal_uint16      msg_len;
    kal_uint32      cm_conn_id;
    bt_bpp_get_event_enum   get_event_flag;
    kal_uint8       DocFormat;
    kal_uint16      Copies;
    kal_uint8       Sides;    
    kal_uint8       NumberUp;    
    kal_uint8       Orientation;
    kal_uint8       Media;
    kal_uint8       Quality;        
} bt_bpp_create_job_req_struct;

typedef struct
{
    kal_uint8       ref_count;
    kal_uint16      msg_len;
    kal_uint32      cm_conn_id;
    kal_uint32      job_id;
    bt_bpp_cnf_enum cnf_code;
} bt_bpp_create_job_cnf_struct;

typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;
    kal_uint32  cm_conn_id;
    kal_uint32  job_id;
    bt_bpp_cnf_enum             cnf_code;
    bt_bpp_job_state_enum       job_state;
    bt_bpp_printer_state_enum   printer_state;
    bt_bpp_printer_reason_enum  printer_reason;
} bt_bpp_event_ind_struct;

typedef struct
{
    kal_uint8           ref_count;
    kal_uint16          msg_len;
    kal_uint32          cm_conn_id;
    kal_uint32          job_id;
    kal_uint8           file_path[BPP_FMGR_MAX_PATH_LEN*BPP_ENCODING_LENGTH];
    kal_uint8           file_name[BPP_FMGR_MAX_FILE_LEN*BPP_ENCODING_LENGTH];
    bt_bpp_type_enum    doc_type;
} bt_bpp_send_doc_req_struct;

typedef struct
{
    kal_uint8       ref_count;
    kal_uint16      msg_len;
    kal_uint32      cm_conn_id;
    kal_uint32      job_id;
    bt_bpp_cnf_enum cnf_code;
} bt_bpp_send_doc_cnf_struct;

typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;
    kal_uint32  cm_conn_id;
    kal_uint32  job_id;
    kal_uint32  remain_len;
} bt_bpp_prog_update_ind_struct;

typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;
    kal_uint32  cm_conn_id;
    kal_uint32  job_id;
} bt_bpp_prog_update_rsp_struct;

/**** End of BPP Structure ****/
typedef goep_rsp_struct goep_deregister_server_rsp_struct;
typedef goep_rsp_struct goep_auth_rsp_struct;
typedef goep_rsp_struct goep_abort_rsp_struct;

typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 goep_conn_id;
    kal_uint8 rsp_code;
} goep_res_struct;

typedef goep_res_struct goep_authorize_res_struct;
typedef goep_res_struct goep_connect_res_struct;
typedef goep_res_struct goep_push_res_struct;
typedef goep_res_struct goep_set_folder_res_struct;
typedef goep_res_struct goep_abort_res_struct;


/* The following defined structs for SIM Access Profile (SAP) */

#define APDU_REQ_MAX_LEN    261        /* 256 bytes for data + 5 bytes header information: CLA,INS,P1,P2,P3 */
#define APDU_RSP_MAX_LEN    258        /* 256 bytes for data + 2 bytes status word SW1 and SW2 */
#define ATR_MAX_LEN                40

/* MSG_ID_BT_SIMAP_CONNECT_IND */
typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 cid; /*connection id*/
   kal_uint32 lap;
   kal_uint8 uap;
   kal_uint16 nap;	 
}bt_simap_connect_ind_struct;

/* MSG_ID_BT_SIMAP_DISCONNECT_IND */
typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 cid; /*connection id*/
   
}bt_simap_disconnect_ind_struct;


/* MSG_ID_BT_SIMAP_DISCONNECT_CNF */
typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_bool result;
   kal_uint8 cid; /*connection id*/
} bt_simap_disconnect_cnf_struct;

/* MSG_ID_BT_SIMAP_DEACTIVATE_CNF */
typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_bool result;
}bt_simap_deactivate_cnf_struct;


/* MSG_ID_BT_SIMAP_AUTH_RSP */
typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_bool result; 
} bt_simap_auth_rsp_struct;

/* MSG_ID_BT_SIM_RESET_REQ */
typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 transport_protocol_type;  
} bt_sim_reset_req_struct;

/* MSG_ID_BT_SIM_APDU_REQ */
typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 transport_protocol_type;
   kal_uint16 apdu_req_len;
   kal_uint8 apdu_req[APDU_REQ_MAX_LEN]; 
} bt_sim_apdu_req_struct;

/* MSG_ID_BT_SIM_CONNECT_CNF */
typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint16 result;
   kal_uint8 current_transport_protocol_type;
   kal_uint8 supported_transport_protocol_type_capability;
   kal_uint16 atr_len;
   kal_uint8 atr[ATR_MAX_LEN];
} bt_sim_connect_cnf_struct;

/* MSG_ID_BT_SIM_RESET_CNF */
typedef struct 
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint16 result;
   kal_uint8 current_transport_protocol_type;
   kal_uint16 atr_len;
   kal_uint8 atr[ATR_MAX_LEN];   
} bt_sim_reset_cnf_struct;

/* MSG_ID_BT_SIM_APDU_CNF */
typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint16 result; 
   kal_uint16 apdu_rsp_len;
   kal_uint8 apdu_rsp[APDU_RSP_MAX_LEN];
} bt_sim_apdu_cnf_struct;


/* MSG_ID_BT_SIM_POWER_OFF_CNF */
typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint16 result;
} bt_sim_power_off_cnf_struct;


/* MSG_ID_BT_SIM_DISCONNECT_CNF */
typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint16 result;

}bt_sim_disconnect_cnf_struct;



typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8    result;
    kal_uint32	 handle;
} bt_app_sdpdb_get_handle_cnf_struct; 

/* MSG_ID_BT_SDPDB_REGISTER_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 handle;
    kal_uint8 type;
    kal_uint8   *record_raw;
    kal_uint16 record_raw_length;
    kal_uint8 *attribs_buffer;
    kal_uint16 attribs_buffer_size;
} bt_app_sdpdb_register_req_struct; 

/* MSG_ID_BT_SDPDB_REGISTER_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8	 result;
    kal_uint32 handle;
} bt_app_sdpdb_register_cnf_struct; 

/* MSG_ID_BT_SDPDB_DEREGISTER_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32   handle;
} bt_app_sdpdb_deregister_req_struct; 

/* MSG_ID_BT_SDPDB_DEREGISTER_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8	 result;
    kal_uint32	 handle;
} bt_app_sdpdb_deregister_cnf_struct; 

/* MSG_ID_BT_SDPDB_RETRIEVE_RECOED_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32   handle;
} bt_app_sdpdb_retrieve_record_req_struct; 
    
/* MSG_ID_BT_SDPDB_RETRIEVE_RECOED_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 result;
    kal_uint32   handle;
    kal_uint8 *record;
    kal_uint16 record_size;
} bt_app_sdpdb_retrieve_record_cnf_struct; 

#define BTSDPDBAPP_SUCCESS        (0)
#define BTSDPDBAPP_FAILED     (1)
#define BTSDPDBAPP_INVALID_HANDLE     (2)
#define BTSDPDBAPP_SDP_REGISTER_FAILED        (3)
#define BTSDPDBAPP_SDP_DEREGISTER_FAILED      (4)
#define BTSDPDBAPP_SDP_DDB_FULL        (5)
#define BTSDPDBAPP_SDP_RECORD_SYNTAX_ERROR     (6)
#define BTSDPDBAPP_SDP_RECORD_TOO_LARGE        (7)
#define BTSDPDBAPP_SDP_RECORD_ATTRIBUTE_BUFFER_TOO_SMALL       (8)

#define BT_APP_REGISTER_RECORD    (0x01)
#define BT_APP_UPDATE_RECORD    (0x02)

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 bd_addr[6];
    kal_uint8 ps_type;
    kal_uint16 mtu;
    kal_uint16 channel;
    kal_uint8 identify;
    kal_uint8 security_value;
    kal_uint8 *channel_context;
}bt_jsr82_connect_req;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 bd_addr[6];
    kal_uint16 mtu;
    kal_uint8 ps_type;
    kal_uint16 channel;
    kal_uint8 identify;
    kal_uint16 l2cap_id;    
    kal_uint8 result;
}bt_jsr82_connect_cfn;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 ps_type;
    kal_uint16 mtu;
    kal_uint32 identify;
    kal_uint8 security_value;
    kal_uint8 *channel_context;
}bt_jsr82_enable_service_req;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 result;
    kal_uint8 ps_type;
    kal_uint16 channel;
    kal_uint8 index;
    kal_uint32 identify;
}bt_jsr82_enable_service_cnf;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 index;
    kal_uint8 ps_type;    
    kal_uint32 transaction_id;
}bt_jsr82_turn_on_service_req;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 result;
    kal_uint8 index;
    kal_uint8 ps_type;     
    kal_uint32 transaction_id;
}bt_jsr82_turn_on_service_cnf;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 identify;
}bt_jsr82_disable_service_req;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 result;
    kal_uint8 identify;
}bt_jsr82_disable_service_cfn;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 bd_addr[6];
    kal_uint8 ps_type;
    kal_uint16 mtu;
    kal_uint16 channel;
    kal_uint8 identify;
    kal_uint16 l2cap_id;    
    kal_uint8 rsp_result;
}bt_jsr82_connect_ind;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 bd_addr[6];
    kal_uint8 ps_type;
    kal_uint16 mtu;
    kal_uint16 channel;
    kal_uint8 identify;
    kal_uint16 l2cap_id;    
    kal_uint8 result;
}bt_jsr82_connect_rsp;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 identify;
    kal_uint16 l2cap_id;    
}bt_jsr82_disconnect_req;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 identify;
    kal_uint16 l2cap_id;    
}bt_jsr82_disconnect_rsp;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 identify;
    kal_uint16 l2cap_id;    
}bt_jsr82_disconnect_ind;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 identify;
    kal_uint16 length;
    kal_uint16 l2cap_id;    
    kal_uint8 *data;
}bt_jsr82_tx_data_req;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 identify;
    kal_uint16 l2cap_id;    
    kal_uint8 result;
}bt_jsr82_tx_data_cfn;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 identify;
    kal_uint16 length;
    kal_uint16 l2cap_id;    
    kal_uint8 *data;
}bt_jsr82_rx_data_ind;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 identify;
    kal_uint16 l2cap_id;    
}bt_jsr82_rx_data_rsp;


/**** Start of BIP Structure ****/

typedef struct
{
    bt_bip_img_format_enum  encoding;
    kal_bool                define_pixel_with_range;
    kal_uint16              max_pixel_width;
    kal_uint16              min_pixel_width;
    kal_uint16              max_pixel_height;
    kal_uint16              min_pixel_height;
    kal_uint16              specified_pixel_width;
    kal_uint16              specified_pixel_height;
    kal_uint8               img_handle[8];
    kal_uint8               friendly_name[BT_BIP_MAX_IMG_NAME_LEN];
    kal_uint32              size;
    kal_uint8               created[BT_BIP_MAX_TIME_LEN];   /* (YYYYMMDDTHHMMSS)(Z)*/
    kal_uint8               modified[BT_BIP_MAX_TIME_LEN];   /* (YYYYMMDDTHHMMSS)(Z)*/
} bt_bip_img_info_struct;

typedef goep_bd_addr_struct bt_bip_bd_addr_struct;

typedef struct
{
    kal_uint8               ref_count;
    kal_uint16              msg_len;
    kal_uint8               req_id;
    bt_bip_bd_addr_struct   bd_addr;
    bt_bip_service_enum     bip_service;
} bt_bip_connect_req_struct;

typedef struct
{
    kal_uint8       ref_count;
    kal_uint16      msg_len;
    kal_uint8       req_id;
    bt_bip_cnf_enum cnf_code;
    kal_uint32      cm_conn_id;
} bt_bip_connect_cnf_struct;

typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;
    kal_uint32  cm_conn_id;
} bt_bip_get_capabilities_req_struct;

typedef struct
{
    kal_uint8               ref_count;
    kal_uint16              msg_len;
    kal_uint32              cm_conn_id;
    bt_bip_cnf_enum         cnf_code;
    bt_bip_img_format_enum  supported_img_formats[BT_BIP_MAX_IMG_FORMATS];
    bt_bip_img_format_enum  preferred_format;
    kal_bool                created_time_filter;
    kal_bool                modified_time_filter;
    kal_bool                encoding_filter;
    kal_bool                pixel_filter;
} bt_bip_get_capabilities_cnf_struct;

typedef struct
{
    kal_uint8               ref_count;
    kal_uint16              msg_len;
    kal_uint32              cm_conn_id;
    kal_uint8               img_name[BT_BIP_MAX_IMG_NAME_LEN];
    kal_uint8               img_path[BT_BIP_MAX_PATH_LEN*BT_BIP_ENCODING_LENGTH];
    kal_uint32              img_size;
    bt_bip_img_info_struct  img_descriptor;
} bt_bip_put_img_req_struct;

typedef struct
{
    kal_uint8       ref_count;
    kal_uint16      msg_len;
    kal_uint32      cm_conn_id;
    kal_uint8       img_handle[BT_BIP_IMG_HANDLE_LEN];
    bt_bip_cnf_enum cnf_code;
} bt_bip_put_img_cnf_struct;

typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;
    kal_uint32  cm_conn_id;
    kal_uint8   img_handle[BT_BIP_IMG_HANDLE_LEN];
    kal_uint8   img_path[BT_BIP_MAX_PATH_LEN*BT_BIP_ENCODING_LENGTH];
} bt_bip_put_linked_thumbnail_req_struct;

typedef struct
{
    kal_uint8       ref_count;
    kal_uint16      msg_len;
    kal_uint32      cm_conn_id;
    bt_bip_cnf_enum cnf_code;
} bt_bip_put_linked_thumbnail_cnf_struct;

typedef struct
{
    kal_uint8               ref_count;
    kal_uint16              msg_len;
    kal_uint32              cm_conn_id;
    bt_bip_img_info_struct  img_list_descriptor;
    kal_uint16              max_img_handle_number;
    kal_uint16              start_index;
    kal_bool                latest_captured;
} bt_bip_get_img_list_req_struct;

typedef struct
{
    kal_uint8       ref_count;
    kal_uint16      msg_len;
    kal_uint32      cm_conn_id;
    kal_uint8       img_list_path[BT_BIP_MAX_PATH_LEN*BT_BIP_ENCODING_LENGTH];
    kal_uint16      img_count;
    bt_bip_cnf_enum cnf_code;
} bt_bip_get_img_list_cnf_struct;

typedef struct
{
    kal_uint8               ref_count;
    kal_uint16              msg_len;
    kal_uint32              cm_conn_id;
    kal_uint8               img_handle[BT_BIP_IMG_HANDLE_LEN];
} bt_bip_get_img_prop_req_struct;

typedef struct
{
    kal_uint8               ref_count;
    kal_uint16              msg_len;
    kal_uint32              cm_conn_id;
    bt_bip_img_info_struct  native_img;
    bt_bip_img_info_struct* variant_img_p;
    bt_bip_img_info_struct* attachment_p;
    bt_bip_cnf_enum         cnf_code;
} bt_bip_get_img_prop_cnf_struct;

typedef struct
{
    kal_uint8               ref_count;
    kal_uint16              msg_len;
    kal_uint32              cm_conn_id;
    kal_uint8               img_path[BT_BIP_MAX_PATH_LEN*BT_BIP_ENCODING_LENGTH];
    kal_uint8               img_handle[BT_BIP_IMG_HANDLE_LEN];
    bt_bip_img_info_struct  img_descriptor;
} bt_bip_get_img_req_struct;

typedef struct
{
    kal_uint8       ref_count;
    kal_uint16      msg_len;
    kal_uint32      cm_conn_id;
    bt_bip_cnf_enum cnf_code;
} bt_bip_get_img_cnf_struct;

typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;
    kal_uint32  cm_conn_id;
    kal_uint8   img_handle[BT_BIP_IMG_HANDLE_LEN];
    kal_uint8   img_path[BT_BIP_MAX_PATH_LEN*BT_BIP_ENCODING_LENGTH];
} bt_bip_get_linked_thumbnail_req_struct;

typedef struct
{
    kal_uint8       ref_count;
    kal_uint16      msg_len;
    kal_uint32      cm_conn_id;
    bt_bip_cnf_enum cnf_code;
} bt_bip_get_linked_thumbnail_cnf_struct;

typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;
    kal_uint32  cm_conn_id;
    kal_uint8   img_path[BT_BIP_MAX_PATH_LEN*BT_BIP_ENCODING_LENGTH];
    kal_uint8   store_flag;
} bt_bip_get_monitoring_img_req_struct;

typedef struct
{
    kal_uint8       ref_count;
    kal_uint16      msg_len;
    kal_uint32      cm_conn_id;
    bt_bip_cnf_enum cnf_code;
} bt_bip_get_monitoring_img_cnf_struct;

typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;
    kal_uint32  cm_conn_id;
} bt_bip_abort_req_struct;

typedef struct
{
    kal_uint8       ref_count;
    kal_uint16      msg_len;
    kal_uint32      cm_conn_id;
    bt_bip_cnf_enum cnf_code;
} bt_bip_abort_cnf_struct;

typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;
    kal_uint8   req_id;
    kal_uint8   bip_service_set;
} bt_bip_activate_req_struct;

typedef struct
{
    kal_uint8       ref_count;
    kal_uint16      msg_len;
    kal_uint8       req_id;
    bt_bip_cnf_enum cnf_code;
} bt_bip_activate_cnf_struct;

typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;
    kal_uint8  req_id;
    kal_uint8   bip_service_set;
} bt_bip_deactivate_req_struct;

typedef struct
{
    kal_uint8       ref_count;
    kal_uint16      msg_len;
    kal_uint8      req_id;
    bt_bip_cnf_enum cnf_code;
} bt_bip_deactivate_cnf_struct;

typedef struct
{
    kal_uint8               ref_count;
    kal_uint16              msg_len;
    kal_uint32              cm_conn_id;
    bt_bip_bd_addr_struct   bd_addr;
    kal_uint8               dev_name[BT_BIP_MAX_DEV_NAME_LEN];
} bt_bip_connect_ind_struct;

typedef struct
{
    kal_uint8       ref_count;
    kal_uint16      msg_len;
    kal_uint32      cm_conn_id;
    bt_bip_cnf_enum cnf_code;
} bt_bip_connect_rsp_struct;

typedef struct
{
    kal_uint8       ref_count;
    kal_uint16      msg_len;
    kal_uint32      cm_conn_id;
} bt_bip_get_capabilities_ind_struct;

typedef struct
{
    kal_uint8               ref_count;
    kal_uint16              msg_len;
    kal_uint32              cm_conn_id;
    bt_bip_cnf_enum         cnf_code;
    bt_bip_img_format_enum  supported_img_formats[BT_BIP_MAX_IMG_FORMATS];
    bt_bip_img_format_enum  preferred_format;
    kal_bool                created_time_filter;
    kal_bool                modified_time_filter;
    kal_bool                encoding_filter;
    kal_bool                pixel_filter;
} bt_bip_get_capabilities_rsp_struct;

typedef struct
{
    kal_uint8               ref_count;
    kal_uint16              msg_len;
    kal_uint32              cm_conn_id;
    kal_uint8               img_name[BT_BIP_MAX_IMG_NAME_LEN];
    kal_uint32              img_size;
    bt_bip_img_info_struct  img_descriptor;
} bt_bip_put_img_ind_struct;

typedef struct
{
    kal_uint8       ref_count;
    kal_uint16      msg_len;
    kal_uint32      cm_conn_id;
    kal_uint8       img_handle[BT_BIP_IMG_HANDLE_LEN];
    kal_uint8       img_path[BT_BIP_MAX_PATH_LEN*BT_BIP_ENCODING_LENGTH];//checked done
    bt_bip_cnf_enum cnf_code;
} bt_bip_put_img_rsp_struct;

typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;
    kal_uint32  cm_conn_id;
    kal_uint8   img_handle[BT_BIP_IMG_HANDLE_LEN];
} bt_bip_put_linked_thumbnail_ind_struct;

typedef struct
{
    kal_uint8       ref_count;
    kal_uint16      msg_len;
    kal_uint32      cm_conn_id;
    kal_uint8   img_path[BT_BIP_MAX_PATH_LEN*BT_BIP_ENCODING_LENGTH];//checked done
    bt_bip_cnf_enum cnf_code;
} bt_bip_put_linked_thumbnail_rsp_struct;

typedef struct
{
    kal_uint8               ref_count;
    kal_uint16              msg_len;
    kal_uint32              cm_conn_id;
    bt_bip_img_info_struct  img_list_descriptor;
    kal_uint16              max_img_handle_number;
    kal_uint16              start_index;
    kal_bool                latest_captured;
} bt_bip_get_img_list_ind_struct;

typedef struct
{
    kal_uint8       ref_count;
    kal_uint16      msg_len;
    kal_uint32      cm_conn_id;
    kal_uint8       img_list_path[BT_BIP_MAX_PATH_LEN*BT_BIP_ENCODING_LENGTH];
    kal_uint16      img_count;
    bt_bip_cnf_enum cnf_code;
} bt_bip_get_img_list_rsp_struct;

typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;
    kal_uint32  cm_conn_id;
    kal_uint8   img_handle[BT_BIP_IMG_HANDLE_LEN];
} bt_bip_get_img_prop_ind_struct;

typedef struct
{
    kal_uint8               ref_count;
    kal_uint16              msg_len;
    kal_uint32              cm_conn_id;
    kal_uint8               img_handle[BT_BIP_IMG_HANDLE_LEN];
    bt_bip_img_info_struct  native_img;
    bt_bip_img_info_struct* variant_img_p;
    bt_bip_img_info_struct* attachment_p;
    bt_bip_cnf_enum         cnf_code;
} bt_bip_get_img_prop_rsp_struct;

typedef struct
{
    kal_uint8               ref_count;
    kal_uint16              msg_len;
    kal_uint32              cm_conn_id;
    kal_uint8               img_handle[BT_BIP_IMG_HANDLE_LEN];
    bt_bip_img_info_struct  img_descriptor;
} bt_bip_get_img_ind_struct;

typedef struct
{
    kal_uint8       ref_count;
    kal_uint16      msg_len;
    kal_uint32      cm_conn_id;
    kal_uint8       img_path[BT_BIP_MAX_PATH_LEN*BT_BIP_ENCODING_LENGTH];
    kal_uint8       img_handle[BT_BIP_IMG_HANDLE_LEN];
    bt_bip_cnf_enum cnf_code;
} bt_bip_get_img_rsp_struct;

typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;
    kal_uint32  cm_conn_id;
    kal_uint8   img_handle[BT_BIP_IMG_HANDLE_LEN];
} bt_bip_get_linked_thumbnail_ind_struct;

/*
typedef struct
{
    kal_uint8       ref_count;
    kal_uint16      msg_len;
    kal_uint32      cm_conn_id;
    bt_bip_cnf_enum cnf_code;
    kal_uint8       thumbnail_path[BT_BIP_MAX_PATH_LEN*ENCODING_LENGTH];
} bt_bip_get_linked_thumbnail_rsp_struct;
*/

typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;
    kal_uint32  cm_conn_id;
    kal_uint8   store_flag;
} bt_bip_get_monitoring_img_ind_struct;

/*
typedef struct
{
    kal_uint8       ref_count;
    kal_uint16      msg_len;
    kal_uint32      cm_conn_id;
    bt_bip_cnf_enum cnf_code;
    kal_uint8       img_path[BT_BIP_MAX_PATH_LEN*ENCODING_LENGTH];
    kal_uint8               img_handle[BT_BIP_IMG_HANDLE_LEN];
} bt_bip_get_monitoring_img_rsp_struct;
*/

typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;
    kal_uint32  cm_conn_id;
} bt_bip_abort_ind_struct;

typedef struct
{
    kal_uint8       ref_count;
    kal_uint16      msg_len;
    kal_uint32      cm_conn_id;
} bt_bip_complete_ind_struct;

typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;
    kal_uint32  cm_conn_id;
    kal_uint32    obj_len;
    kal_uint32    data_len;
} bt_bip_continue_ind_struct;

typedef struct
{
    kal_uint8       ref_count;
    kal_uint16      msg_len;
    kal_uint32      cm_conn_id;
    bt_bip_cnf_enum cnf_code;
} bt_bip_continue_rsp_struct;

typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;
    kal_uint8   req_id;
    kal_uint32  cm_conn_id;
    kal_bool disconnect_tp_directly;
} bt_bip_disconnect_req_struct;

typedef struct
{
    kal_uint8       ref_count;
    kal_uint16      msg_len;
    kal_uint32      cm_conn_id;
} bt_bip_disconnect_ind_struct;

typedef struct
{
    kal_uint8   img_handle[BT_BIP_IMG_HANDLE_LEN];
    kal_uint8   created[BT_BIP_MAX_TIME_LEN];   /* (YYYYMMDDTHHMMSS)(Z)*/
    kal_uint8   modified[BT_BIP_MAX_TIME_LEN];   /* (YYYYMMDDTHHMMSS)(Z)*/
} bt_bip_img_min_info_struct;

typedef bt_bip_get_img_rsp_struct bt_bip_get_linked_thumbnail_rsp_struct;
typedef bt_bip_get_img_rsp_struct bt_bip_get_monitoring_img_rsp_struct;

/**** End of BIP Structure ****/

//<!---------added by yufeng chu for __MMI_GOEP_AUTH__


typedef struct 
{
    kal_uint8 uuid[GOEP_MAX_UUID_SIZE];
    kal_uint8 uuid_len;
    kal_uint8 passwd[GOEP_MAX_PASSWD_SIZE];
    kal_uint8 passwd_len;
    kal_uint8 realm_str[GOEP_MAX_REALM_SIZE];
    kal_uint8 realm_len;
}auth_chal_struct;

typedef kal_uint8 (*AUTH_IND_HANDLER) (goep_auth_ind_struct *auth_ind);

struct auth_ind_handler_struct
{
    kal_uint8 uuid[GOEP_MAX_UUID_SIZE];
    kal_uint8 uuid_len;
	
    AUTH_IND_HANDLER auth_ind_handler;

   struct auth_ind_handler_struct * next;	

};

typedef struct auth_ind_handler_struct auth_ind_handler_struct;


//-------------->

#endif

