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
 * Filename:
 * ---------
 *	wap_ps_struct.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for local parameter declaration about WAP sap
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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
 *==============================================================================
 *******************************************************************************/

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/

#ifndef _WAP_PS_STRUCT_H
#define _WAP_PS_STRUCT_H 

#define WPS_MAX_AUTH_USERNAME_LENGTH	129
#define WPS_MAX_AUTH_PASSWORD_LENGTH	31
#define MMA_MAX_PROF_HOMEPAGE_URL_LENGTH 255
#define MMA_MAX_PROF_USERNAME_LENGTH 128
#define MMA_MAX_PROF_PASSWORD_LENGTH 128
#define MMA_MAX_RESPONSE_TEXT_LENGTH 256
#define MMA_MAX_APP_DATA_LENGTH 32
#define MMA_MAX_ADDR_LEN 128
#define MMA_MAX_SUBJECT_LEN 41
#define MMA_MAX_INTERNAL_FILENAME_LENGTH	100
#define MMA_MAX_MSG_ARRAY_NUM   400

typedef enum
{
    WAP_PROF_EWIL, /* WAP Image Load */
    WAP_PROF_EWHP, /* WAP Homepage */
    WAP_PROF_EWPR, /* WAP Profiles */
    WAP_PROF_EWPN, /* WAP Profile Name */
    WAP_PROF_EWDT, /* WAP Download Timeout */
    WAP_PROF_EWLI, /* WAP Login */
    WAP_PROF_EWPB, /* WAP Preferred Bearer, non-support */
    WAP_PROF_EWCG, /* WAP CSD Gateway, non-support */
    WAP_PROF_EWBA, /* WAP Bookmark Add */
    WAP_PROF_EWBR, /* WAP Bookmark Read */
    WAP_PROF_EWCT, /* WAP Connection Timeout, non-support */
    WAP_PROF_EWNI  /* WAP Current Network Account Id */
} wap_prof_access_enum;

typedef enum
{
    WAP_MMS_PROF_MMSC_ADDRESS /* WAP MMSC address */
} wap_mms_prof_access_enum;

typedef enum
{
    WAP_PROF_SET,
    WAP_PROF_READ,
    WAP_PROF_TEST
} wap_prof_cmd_enum;

typedef enum
{
    WAP_BEARER_STATUS_GPRS,
    WAP_BEARER_STATUS_WIFI
} wap_bearer_status_type_enum;

typedef enum
{
    WAP_GPRS_NONE,
    WAP_GPRS_COVERAGE,
    WAP_GPRS_ATTACHED,
    WAP_GPRS_DETACHED
} wap_gprs_state_enum;

typedef enum
{
    WAP_SIM_ID_DEFAULT,
    WAP_SIM_ID_SIM1,
    WAP_SIM_ID_SIM2,
    WAP_SIM_ID_DUAL_SIM,
    WAP_SIM_ID_NO_SIM,
    WAP_SIM_ID_FLIGHT_MODE,
    WAP_SIM_ID_MAX_ITEM
}wap_sim_id_enum;

typedef struct wap_prof_access_req_struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 query;
    kal_uint8 cmd;
    kal_uint8 param[5][16];
}wap_prof_access_req_struct;

//for search pbook address- Jo 031203 
typedef struct mea_addr_input_struct 
{
    kal_uint8	ref_count; 
    kal_uint16	msg_len;  //LOCAL_PARA_HDR
    kal_uint8*	name;
    kal_uint8*	addr;

} mea_addr_input_struct;

typedef struct mea_addr_input_struct wap_phb_addr_input_struct;

typedef struct 
{	
    kal_uint8 ref_count;
    kal_uint16 msg_len;	
    kal_uint8 app_id_len;
    kal_uint8 app_id[100];
}wap_mmc_recv_appmms_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 result; /* FFS */
    kal_uint8 priority; //WAP_MMS_PRIORITY_LOW:0,  WAP_MMS_PRIORITY_MED: 1, WAP_MMS_PRIORITY_HIGH: 2
    kal_uint8 from_addr_no; //If this value is zero, please skip item 2 (FROM address field)of peer bufer.
    kal_uint8 to_addr_no;
    kal_uint8 cc_addr_no;
    kal_uint8 bdy_part_no;
    kal_uint32 date;
    kal_uint8 start_cnt_id_len;  
    kal_uint8 start_cnt_id[100];
    kal_uint8 reply_app_id_len;
    kal_uint8 reply_app_id[100];
}wap_mmc_recv_appmms_rsp_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 send_by_file; //SEND BY MEM:0, SEND BY FILE:1
    kal_uint8 filepath_len; //Valid when send_by_file=1
    kal_wchar filepath[100];//Valid when send_by_file=1 
    kal_uint8 mms_type; //WAP_MMS_MULTIPART_RELATED: 0, WAP_MMS_MULTIPART_MIXED: 1
    kal_uint8 priority; //WAP_MMS_PRIORITY_LOW:0,  WAP_MMS_PRIORITY_MED: 1, WAP_MMS_PRIORITY_HIGH: 2
    kal_uint8 to_addr_no;
    kal_uint8 cc_addr_no;
    kal_uint8 bcc_addr_no;
    kal_uint8 bdy_part_no;
    kal_uint32 delivery_time; /*tony: 0 means deliver immediately*/
    kal_uint8 app_id_len;
    kal_uint8 reply_app_id_len;
    kal_uint8 start_cnt_id_len;   
    kal_uint8 app_id[100];
    kal_uint8 reply_app_id[100];
    kal_uint8 start_cnt_id[100];
}wap_mmc_send_appmms_req_struct;

typedef struct 
{	
    kal_uint8 ref_count;
    kal_uint16 msg_len;	
    kal_uint8 result; /* FFS */
}wap_mmc_send_appmms_rsp_struct;

typedef struct 
{	
    kal_uint8 ref_count;
    kal_uint16 msg_len;	
    kal_uint8 result; /* FFS */
}wap_mmc_post_appmms_msg_part_ind_struct;

typedef struct 
{	
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 encoding_scheme;
    kal_uint8 content_type_len;
    kal_uint8 content_type[256];
    kal_uint8 content_id_len;
    kal_uint8 content_id[100];
    kal_uint8 content_location_len;
    kal_uint8 content_location[100];   
    kal_uint8 filepath_len;
    kal_wchar filepath[100];
}wap_mmc_post_appmms_msg_part_res_struct;

typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 result; /* FFS */
    kal_uint8 encoding_scheme;
    kal_uint32 content_type_value; /*MmsKnownMediaType*/
    kal_uint8 content_type_len;
    kal_uint8 content_type[256];
    kal_uint8 content_id_len;
    kal_uint8 content_id[100];
    kal_uint8 content_location_len;
    kal_uint8 content_location[100];   
    kal_uint8 filepath_len;
    kal_wchar filepath[100];
}wap_mmc_read_appmms_msg_part_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 op; //SET APP ID:0, REMOVE APP ID: 1
    module_type  ind_module; // the task which is indicated when new MMS with app_id is received
    kal_uint8 app_id_len;
    kal_uint8 app_id[100];
} wap_mmc_cfg_appmms_appid_req_struct;
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8	result;
} wap_mmc_cfg_appmms_appid_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_bool only_new;
    kal_uint8 app_id_len;
    kal_uint8 app_id[100];
} wap_mmc_check_appmms_coming_req_struct;
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8	result;
} wap_mmc_check_appmms_coming_rsp_struct;

typedef struct 
{	
    kal_uint8 ref_count;
    kal_uint16 msg_len;	
    kal_uint8 result;
}wap_mmc_abort_appmms_rsp_struct;

typedef struct 
{	
    LOCAL_PARA_HDR
    kal_uint32 access_id; /* wap_mms_prof_access_enum.*/
}wap_mmc_get_mms_prof_req_struct;

typedef struct 
{	
    LOCAL_PARA_HDR
    kal_uint8 result; /* 0 means Success; 1 means MMS is not ready yet; 2 means invalid prof_id*/
    kal_uint8 value_len; /*length include NULL terminator*/
    kal_uint8 value[256];
}wap_mmc_get_mms_prof_rsp_struct;

typedef struct 
{	
    LOCAL_PARA_HDR
    kal_uint8 app_id_len;
    kal_uint8 app_id[100];
}wap_mmc_appmms_new_mms_ind_struct;
typedef struct 
{
    LOCAL_PARA_HDR
    kal_uint16 keycode;
    kal_uint16 keytype;
} wap_mmi_key_indication_struct;

typedef struct mea_new_mms_req_struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;  //LOCAL_PARA_HDR
    kal_uint8 mode;

    /* commandInfo: 
    * subject[82]: MEA_ME_SUBJECT_MAX_SIZE(40)* ENCODING_LENGTH(2) + ENCODING_LENGTH(2)
    * file path[522]: FMGR_MAX_PATH_LEN(260) * ENCODING_LENGTH(2) + ENCODING_LENGTH(2) 
    * address: phone number */
    kal_uint8 commandInfo[522];
    kal_uint8 isContentTruncated;
    void *funcPtr;
    void *funcParam;
} mea_new_mms_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_wchar filename[261]; /* FMGR_MAX_PATH_LEN(260) + NULL char */
}mms_get_attachment_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 result;
    kal_wchar filepath[261];	/* FMGR_MAX_PATH_LEN(260) + NULL char */
}mms_get_attachment_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 mode;
    kal_uint16 msg_index;
    kal_uint32 msg_box;
}mea_um_entry_req_struct;

/* MMS adaptor { */
#define MMA_MAX_INTERNAL_FILENAME_LENGTH	100

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 mode;
    kal_uint16 msg_index;
    kal_uint32 msg_box;
}wap_mma_um_entry_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 app_id; /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */    
    kal_uint8 mode;  /* mma_app_mode_enum */
    kal_uint32 msg_id;
}wap_mma_uc_start_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 app_id; /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */    
    kal_uint8 result;  /* mma_result_enum */
    kal_uint32 msg_id;
    kal_uint8 mode;  /* mma_app_mode_enum */
}wap_mma_uc_start_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 app_id; /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */       
    kal_uint8 result;  /* mma_result_enum */
    kal_uint32 req_id;
    kal_uint32 msg_id;
}wap_mma_rsp_struct;

typedef struct
{
    kal_bool enable;
    kal_uint32 width;
    kal_uint32 height;
}mma_image_resizing_struct;

typedef struct
{
    kal_bool enable;
    kal_wchar text_file[MMA_MAX_INTERNAL_FILENAME_LENGTH];
    kal_wchar img_file[MMA_MAX_INTERNAL_FILENAME_LENGTH];
    kal_wchar audio_file[MMA_MAX_INTERNAL_FILENAME_LENGTH];
    kal_wchar video_file[MMA_MAX_INTERNAL_FILENAME_LENGTH];
}mma_signature_struct;

typedef struct
{
    kal_uint32 value;
    kal_uint32 min;
    kal_uint32 max;
}mma_setting_struct;

typedef struct
{
    kal_uint8   creation_mode; /*mma_creation_mode_enum*/
    kal_uint8   priority; /*mma_priority_enum*/
#if defined(OBIGO_Q05A)
    kal_uint32   validity_period; /*mma_expiry_time_enum*/
    kal_uint32   delivery_time; /*mma_delivery_time_enum*/
#else
    kal_uint8   validity_period; /*mma_expiry_time_enum*/
    kal_uint8   delivery_time; /*mma_delivery_time_enum*/
#endif    
    kal_bool    delivery_report;
    kal_bool    read_report;
    kal_uint32  max_mms_size;
    mma_image_resizing_struct   image_resize;
    mma_signature_struct    signature;
    mma_setting_struct  sliding_time;
    kal_uint8   layout;
    kal_uint8   add_as_drm; /*1: TRUE, 0:FASLE*/
    kal_uint8   max_no_pages;
    kal_uint8   best_page_duration;
    kal_uint8   reply_charging;
    kal_uint8   request_type; /*mma_reply_charging_type_enum*/
    kal_uint32  deadline_for_reply;
    kal_uint8   hide_sender;
    kal_uint32  size;
}mma_compose_sending_setting_struct;

typedef struct
{
    kal_uint8	home_network; /*mma_retrieval_mode_enum*/
    kal_uint8	roaming; /*mma_retrieval_mode_enum*/
    kal_uint8	anonymous_filter; /*1: TRUE, 0:FASLE*/
    kal_uint8	advertisement_filter; /*1: TRUE, 0:FASLE*/
    kal_uint8	delivery_report; /*1: Allowed: 0, Not Allowed*/
}mma_retrieval_setting_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 app_id; /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */    
    kal_uint32 req_id;
}wap_mma_get_setting_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 app_id; /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */    
    kal_uint8 result;  /* mma_result_enum */
    kal_uint32 req_id;
    kal_uint8   mms_version; /*0x10 is 1.0, 0x11 is 1.1, 0x12 is 1.2*/
    /*mma_compose_sending_setting*/
    kal_uint8   creation_mode; /*mma_creation_mode_enum*/
    kal_uint8   priority; /*mma_priority_enum*/
#if defined(OBIGO_Q05A)    
    kal_uint32   validity_period; /*mma_expiry_time_enum*/
    kal_uint32   delivery_time; /*mma_delivery_time_enum*/
#else
    kal_uint8   validity_period; /*mma_expiry_time_enum*/
    kal_uint8   delivery_time; /*mma_delivery_time_enum*/
#endif    
    kal_bool    delivery_report;
    kal_bool    read_report;
    kal_uint32  max_mms_size;
    mma_image_resizing_struct   image_resize;
    mma_signature_struct    signature;
    mma_setting_struct  sliding_time;
    kal_uint8   layout;
    kal_uint8   add_as_drm; /*1: TRUE, 0:FASLE*/
    kal_uint8   max_no_pages;
    kal_uint8   best_page_duration;
    kal_uint8   reply_charging;
    kal_uint8   request_type; /*mma_reply_charging_type_enum*/
    kal_uint32  deadline_for_reply;
    kal_uint8   hide_sender;
    kal_uint32  size;
    /*mma_retrieval_setting*/
    mma_retrieval_setting_struct retrieval_setting;     
}wap_mma_get_setting_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 app_id; /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */    
    kal_uint32 req_id;
}wap_mma_get_mem_status_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 app_id; /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */    
    kal_uint8 result;  /* mma_result_enum */
    kal_uint32	req_id;
    kal_uint32	used_size;
    kal_uint32	free_size;
}wap_mma_get_mem_status_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 app_id; /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */    
    kal_uint32 req_id;
    kal_uint8   mms_version; /*0x10 is 1.0, 0x11 is 1.1, 0x12 is 1.2*/    
    mma_compose_sending_setting_struct  compose_sending_setting;
    mma_retrieval_setting_struct    retrieval_setting;
}wap_mma_set_setting_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 app_id; /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */    
    kal_uint8 result;  /* mma_result_enum */
    kal_uint32	req_id;
}wap_mma_set_setting_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 app_id; /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */
    kal_uint32	req_id;    
    kal_uint8	connection_type;
    kal_uint16	proxy_port;
    kal_uint8	proxy_addr[4];
    kal_wchar	homepage_url[MMA_MAX_PROF_HOMEPAGE_URL_LENGTH]; /*Encoded by UCS2*/
    kal_wchar	username[MMA_MAX_PROF_USERNAME_LENGTH]; /*Encoded by UCS2*/
    kal_wchar	password[MMA_MAX_PROF_PASSWORD_LENGTH]; /*Encoded by UCS2*/
    kal_uint8	data_account;
}wap_mma_set_profile_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 app_id; /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */    
    kal_uint8 result;  /* mma_result_enum */
    kal_uint32	req_id;
}wap_mma_set_profile_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 app_id; /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */       
    kal_uint32 req_id;
    kal_uint32 msg_id;
    kal_uint32 buffer_index;
    kal_uint8 mode;  /* mma_app_mode_enum */
    kal_uint8 creation_mode;
}wap_mma_get_content_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 app_id; /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */       
    kal_uint8 result;  /* mma_result_enum */
    kal_uint32 req_id;
    kal_uint32 msg_id;
    kal_uint32 mms_header_size;
    kal_uint32 mms_body_size;
    kal_uint32 xml_size;
    kal_wchar xml_filepath[MMA_MAX_INTERNAL_FILENAME_LENGTH];
    kal_uint32 buffer_index;
    kal_uint32 buffer_size;
    kal_bool more;
}wap_mma_get_content_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 app_id; /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */       
    kal_uint32 req_id;
    kal_uint32 msg_id;
    kal_wchar msg_file_path[MMA_MAX_INTERNAL_FILENAME_LENGTH];
    kal_uint8 mode;  /* mma_app_mode_enum */
    kal_uint32 xml_size;
    kal_wchar xml_filepath[MMA_MAX_INTERNAL_FILENAME_LENGTH];
    kal_uint32 buffer_index;
    kal_uint32 buffer_size;
    kal_bool more;
}wap_mma_create_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 app_id; /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */       
    kal_uint8 result;  /* mma_result_enum */
    kal_uint32 req_id;
    kal_uint32 msg_id;
    kal_uint32 buffer_index;
    kal_uint32 min_fs_space_required; /*When the value is more than 0, it means we don't have enoguh working file space to create the MMS*/
}wap_mma_create_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 app_id; /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */
    kal_uint32 req_id;
    kal_uint32 msg_id;
    kal_uint16 box;   /* mma_folder_enum */
}wap_mma_delete_req_struct;

typedef wap_mma_rsp_struct wap_mma_delete_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 app_id; /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */    
    kal_uint32 req_id;
    kal_uint32 msg_id;
    kal_uint16 box;   /* mma_folder_enum */
}wap_mma_save_req_struct;

typedef wap_mma_rsp_struct wap_mma_save_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 app_id; /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */
    kal_uint32 req_id;
    kal_uint32 msg_id;
}wap_mma_preview_req_struct;

typedef wap_mma_rsp_struct wap_mma_preview_rsp_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 app_id; /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */    
    kal_uint32 req_id;
    kal_uint32 msg_id;
    kal_bool is_read_report;
    kal_uint16 box;   /* mma_folder_enum */
    kal_bool send_and_save;
}wap_mma_send_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 app_id; /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */        
    kal_uint32 req_id;
    kal_uint32 msg_id;
    kal_uint8 retry;
    kal_uint8 percent;
}wap_mma_send_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 app_id; /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */        
    kal_uint8 result;  /* mma_result_enum */
    kal_uint32 req_id;
    kal_uint32 msg_id;
    kal_uint32 rr_id; /*Read report id*/
    kal_wchar response_text[MMA_MAX_RESPONSE_TEXT_LENGTH];
    kal_uint16 box;   /* mma_folder_enum */
    kal_bool send_and_save;
}wap_mma_send_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 app_id;
    kal_uint32 req_id;
    kal_uint32 msg_id;
}wap_mma_cancel_send_req_struct;

typedef wap_mma_rsp_struct wap_mma_cancel_send_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 app_id; /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */    
    kal_uint32 req_id;
    kal_uint32 msg_id;
}wap_mma_download_req_struct;

typedef wap_mma_rsp_struct wap_mma_download_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 app_id; /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */        
    kal_uint32 req_id;
    kal_uint32 msg_id;
    kal_uint8 retry;
    kal_uint8 percent;
    kal_uint32 bytes_received;    
}wap_mma_download_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 app_id; /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */        
    kal_uint8 result;  /* mma_result_enum */
    kal_uint32 req_id;
}wap_mma_download_res_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 app_id; /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */        
    kal_uint32 req_id;
    kal_uint32 msg_id;
}wap_mma_cancel_download_req_struct;

typedef wap_mma_rsp_struct wap_mma_cancel_download_rsp_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 app_id; /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */        
    kal_uint32 req_id;
    kal_uint32 msg_id;
}wap_mma_get_msg_info_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 app_id; /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */        
    kal_uint8   result; /*mma_result_enum*/
    kal_uint32  req_id;
    kal_uint32  msg_id;    
    kal_uint8   from_address_type; /*mma_addr_type_enum*/
    kal_wchar   from_address [MMA_MAX_ADDR_LEN]; /*Encoded by USC2*/
    kal_uint8	to_address_type; /*mma_addr_type_enum*/
    kal_wchar	to_address [MMA_MAX_ADDR_LEN]; /*Encoded by USC2*/
    kal_uint8	cc_address_type; /*mma_addr_type_enum*/
    kal_wchar	cc_address [MMA_MAX_ADDR_LEN]; /*Encoded by USC2*/
    kal_uint8	bcc_address_type; /*mma_addr_type_enum*/
    kal_wchar	bcc_address [MMA_MAX_ADDR_LEN]; /*Encoded by USC2*/
    kal_wchar	subject[MMA_MAX_SUBJECT_LEN];  /*Encoded by USC2*/
    kal_uint8	msg_type; /*mma_msg_type_enum*/
    kal_uint8	msg_class;/*mma_msg_class_enum*/
    kal_uint8	priority; /*mma_priority_enum*/
    kal_uint8	msg_status; /*mma_msg_status_enum*/
    kal_uint32	msg_size;
    kal_uint32	date;
    kal_uint32	expiry_date;
    kal_uint32	received_date;
    kal_bool	need_read_report;
    kal_bool	isRead;
    kal_bool	isForwardlock; /*When MMS contain any DRM forward-lock or combine-delivery object, the value is KAL_TRUE. Because sepertae-delivery DRM object can be forwarded.*/
    kal_bool	isDRM; /*When MMS contain any DRM object, the value is KAL_TRUE*/
    kal_bool	isFollowPhoneMMSContentClass;    
    kal_bool    hasAttachment;
    kal_uint8   app_data[MMA_MAX_APP_DATA_LENGTH];
    kal_uint8   java_app_id[100];    /*For JSR205  Encoded by ASCII*/
    kal_uint8   java_reply_app_id[100];/*For JSR205  Encoded by ASCII*/
}wap_mma_get_msg_info_rsp_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 app_id; /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */
    kal_uint32 req_id;
    kal_uint32 msg_id;
    kal_bool readmark;
}wap_mma_set_readmark_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32  app_id; /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */
    kal_uint8   result; /*mma_result_enum*/    
    kal_uint32  req_id;
}wap_mma_set_readmark_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 msg_id;
}wap_mma_start_immed_retrieval_ind_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32	msg_id;
    kal_uint8   result; /*mma_result_enum*/    
    kal_uint32	error_cause;
    kal_wchar	response_text[MMA_MAX_RESPONSE_TEXT_LENGTH]; /*Encoded by UCS2*/
}wap_mma_stop_immed_retrueval_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 app_id; /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */       
    kal_uint32 req_id;
    kal_uint32 msg_id;
    kal_uint8 app_data[MMA_MAX_APP_DATA_LENGTH];
}wap_mma_set_app_data_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 app_id; /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */       
    kal_uint32 req_id;
    kal_uint32 msg_id;
    kal_uint8 result; /*mma_result_enum*/    
}wap_mma_set_app_data_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 app_id; /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */       
    kal_uint32 req_id;
    kal_uint32 folder; /*mma_folder_enum*/
}wap_mma_get_msg_list_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 app_id; /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */       
    kal_uint8 result; /*mma_result_enum*/  
    kal_uint32 req_id;
    kal_uint32 no_of_msg; /*Total number of MMS messages in folder.*/
    kal_uint32 msg_id[MMA_MAX_MSG_ARRAY_NUM]; /* The array can store 399 msg_ids. The value of last item is 0. For emaple, if msg_id[10] is 0, it means there are 9 valid msg_ids from msg_id[0] ~ msg_id[9]*/
    kal_bool    more; /*If no_of_msg is more than 399, the more flag will be KAL_TRUE.*/
}wap_mma_get_msg_list_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_bool is_no_fs_space;
    kal_bool is_max_num_reached;
}wap_mma_storage_full_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32	msg_id;
}wap_mma_view_msg_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 app_id; /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application, BGSR */    
    kal_uint32 req_id;
    kal_uint32 msg_id_list[MMA_MAX_MSG_ARRAY_NUM];
}wap_mma_msg_is_valid_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 app_id; /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application, BGSR */    
    kal_uint32 req_id;
    kal_uint8 result; /* mma_result_enum */
    kal_uint8 msg_validity_list[MMA_MAX_MSG_ARRAY_NUM];
    kal_uint16 box[MMA_MAX_MSG_ARRAY_NUM]; /* mma_folder_enum */
}wap_mma_msg_is_valid_rsp_struct;

/* MMS adaptor } */

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 browserMode;
    kal_uint8 browserIdentity;
    kal_uint8 sim_id;
    kal_uint16 noUrl;
    kal_uint8 *url;
    kal_uint16 noBearer;
    kal_uint8 *bearer;
    kal_uint16 noGateway;
    kal_uint8 *gateway;
} wap_mmi_lauch_browser_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 res;
    kal_uint8 additionalInfo;
} wap_mmi_lauch_browser_rsp_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cause;
} wap_mmi_browser_termination_ind_struct;

typedef struct
{
    kal_wchar *midlet_path;
} wap_drm_local_install_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 type;
    kal_uint8 url[768];
} wap_browser_startup_req_struct;

typedef struct
{
    kal_uint8 len;
    kal_uint8 dcs;
    kal_uint8 value[40];
} wap_prof_name_struct;

typedef struct
{
    kal_uint8 id;
    wap_prof_name_struct name;
    kal_uint8 conn_type;
} wap_prof_entry_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 result;
    kal_uint8 number;
    wap_prof_entry_struct *prof_list;
} wap_get_prof_list_rsp_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 id;
} wap_get_prof_content_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 result;   
    kal_uint8 id;
    kal_uint8 conn_type;
    kal_uint8 prx_ip[4];
    kal_uint16 prx_port;
    kal_uint8 username[30];
    kal_uint8 password[30];
    kal_uint32 net_id;
    kal_uint32 net_id2;
} wap_get_prof_content_rsp_struct;

typedef struct
{
    kal_uint8  ref_count;
    kal_uint16 msg_len;   
    kal_int32  prof_id;
    kal_uint32 net_id;
    kal_uint32 net_id2;
} wap_get_bra_prof_id_rsp_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint32 jTaskID;
} wap_jataayu_queue_recv_ind_struct;


typedef struct 
{	
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 user_agent_len; /*length include NULL terminator*/
    kal_uint8 user_agent[256];
}wap_get_user_agent_rsp_struct;

/* WPS SAP Begin */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_bool use_default;
    kal_uint8 conn_type;
    kal_uint32 net_id;
    kal_uint32 timeout;
    kal_bool use_proxy;
    kal_uint8 prx_ip[4];
    kal_uint16 prx_port;
    kal_uint8 username[30];
    kal_uint8 password[30];
    kal_uint8 server_auth_username[WPS_MAX_AUTH_USERNAME_LENGTH];
    kal_uint8 server_auth_password[WPS_MAX_AUTH_PASSWORD_LENGTH];
} wps_set_channel_req_struct;

typedef struct
{
    kal_uint32 static_header_len;
    kal_uint8* static_header;
} wps_set_channel_req_var_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 channel_id;
    kal_uint8 result;
} wps_set_channel_rsp_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 channel_id;
} wps_unset_channel_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 channel_id;
    kal_uint8 result;
} wps_unset_channel_rsp_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 channel_id;   
    kal_bool use_default;
    kal_uint8 conn_type;
    kal_uint32 net_id;
    kal_uint32 timeout;
    kal_bool use_proxy;
    kal_uint8 prx_ip[4];
    kal_uint16 prx_port;
    kal_uint8 username[30];
    kal_uint8 password[30];
} wps_reconfig_channel_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 channel_id;
    kal_uint8 result;
} wps_reconfig_channel_rsp_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 channel_id;   
    kal_uint8 request_id;
    kal_uint8 method;
    kal_uint16 option;
    kal_uint8 reply_type;
    kal_wchar reply_path[256];
    kal_uint32 reply_segment_len;
    kal_uint8 post_type;
    kal_wchar post_path[256];
    kal_uint32 post_total_len;
    kal_bool   more_post;
} wps_http_req_struct; 

typedef struct
{
    kal_uint32 request_url_len;
    kal_uint8* request_url;
    kal_uint32 request_header_len;
    kal_uint8* request_header;
    kal_uint32 post_segment_len;
    kal_uint8* post_segment;
} wps_http_req_var_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 request_id;
    kal_uint8 result;
    kal_uint16 status;      
    kal_int32 cause;
    kal_uint8 protocol;
    kal_uint8 content_type[256];
    kal_uint32 content_length;
    kal_bool more;
} wps_http_rsp_struct; 

typedef struct
{
    kal_uint32 new_url_len;
    kal_uint8* new_url;
    kal_uint32 reply_header_len;
    kal_uint8* reply_header;
    kal_uint32 reply_segment_len;
    kal_uint8* reply_segment;
} wps_http_rsp_var_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 channel_id;
    kal_uint8 request_id;
    kal_uint8 seq_num;
    kal_uint32 read_segnemtn_len;
} wps_read_content_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 request_id;
    kal_uint8 seq_num;
    kal_uint8 result;
    kal_bool more;
} wps_read_content_rsp_struct;

typedef struct
{
    kal_uint32 reply_segment_len;
    kal_uint8* reply_segment;
} wps_read_content_rsp_var_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 channel_id;
    kal_uint8 request_id;
    kal_uint8 seq_num;
    kal_bool more;
} wps_post_content_res_struct;

typedef struct
{
    kal_uint32 post_segment_len;
    kal_uint8* post_segment;
} wps_post_content_res_var_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 request_id;
    kal_uint8 seq_num;
    kal_uint8 result;
} wps_post_content_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 request_id;
    kal_uint8 seq_num;
    kal_uint8 status;
    kal_int32 cause;
    kal_uint32 acc_size;
} wps_dl_progress_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;  
    kal_uint8 channel_id; 
    kal_uint8 request_id;
    kal_uint8 seq_num;
} wps_dl_progress_res_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;  
    kal_uint8 channel_id; 
    kal_uint8 request_id;
} wps_cancel_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 request_id;
    kal_uint8 result;
} wps_cancel_rsp_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 content_type[256];
    kal_uint32 content_length;
    kal_wchar data_path[256];
} wps_push_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 channel_id;
    kal_uint8 request_id;
    kal_uint8 operation;
} wps_clear_req_struct;

typedef struct
{
    kal_uint32 cache_url_len;
    kal_uint8  *cache_url;
} wps_clear_req_var_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 request_id;
    kal_uint8 result;
} wps_clear_rsp_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 channel_id;
} wps_sec_get_session_info_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 channel_id;
    kal_uint8 result;
    kal_uint16 key_exchange_alg;
    kal_uint8 blk_encrypt_alg;
    kal_uint8 hash_alg;
    kal_uint8 sec_conn_type;
} wps_sec_get_session_info_rsp_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 channel_id;
} wps_sec_get_current_cert_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 channel_id;
    kal_uint8 result;
    kal_uint8 issuer[256];
    kal_uint16 issuer_len;
    kal_uint32 not_after;
    kal_uint32 not_before;
    kal_uint8 serial_num[128];
    kal_uint16 serial_num_len;
    kal_uint8 sig_alg_name[128];
    kal_uint16 sig_alg_name_len;
    kal_uint8 subject[256];
    kal_uint16 subject_len;
    kal_uint8 type;
    kal_uint8 version;
} wps_sec_get_current_cert_rsp_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 channel_id;
    kal_uint8 request_id;
    kal_uint8 auth_type;
    kal_uint8 realm_len;
    kal_uint8 realm[256];
    kal_uint8 username_len;
    kal_uint8 username[256];
} wps_http_auth_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 channel_id;
    kal_uint8 request_id;
    kal_uint8 username[WPS_MAX_AUTH_USERNAME_LENGTH];
    kal_uint8 password[WPS_MAX_AUTH_PASSWORD_LENGTH];
} wps_http_auth_res_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 status;
} wps_status_query_rsp_struct;
/* WPS SAP end */


#define WAP_DL_MAX_URL_LEN      512
#define WAP_DL_MAX_MIME_TYPE_LEN    512
#define WAP_DL_MAX_FILE_NAME_LEN    256

typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;   
    kal_int32   session_id;
    kal_uint8   url[WAP_DL_MAX_URL_LEN];
    kal_uint8   mime_type[WAP_DL_MAX_MIME_TYPE_LEN];
    kal_uint8   file_name[WAP_DL_MAX_FILE_NAME_LEN];
    kal_uint32  file_length;
} wap_mmi_file_dl_ind_struct;

typedef struct
{
    kal_uint32  header_len;
    kal_uint8   *header;
    kal_uint32  content_len;
    kal_uint8   *content;
} wap_mmi_file_dl_var_struct;

typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;   
    kal_int32   session_id;
    kal_uint8   result;
    kal_wchar   file_path[261];
} wap_mmi_file_dl_res_struct;

typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;   
    kal_int32   session_id;
    kal_uint32  seq_num;
    kal_uint8   status;
    kal_int32   cause;
    kal_uint32  acc_size;
} wap_mmi_file_dl_progress_ind_struct;

typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;   
    kal_int32   session_id;
    kal_uint32  seq_num;
} wap_mmi_file_dl_progress_res_struct;

typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;   
    kal_int32   session_id;
} wap_mmi_file_dl_stop_req_struct;

typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;   
    kal_int32	session_id;
    kal_uint32  seq_num;
    kal_uint8   status;
    kal_uint8   cause;
    kal_uint32  acc_size;
} wap_mmi_file_dl_stop_rsp_struct;

typedef struct
{
    kal_uint8 issuer[256];
    kal_uint16 issuer_len;
    kal_uint32 not_after;
    kal_uint32 not_before;
    kal_uint8 serial_num[128];
    kal_uint16 serial_num_len;
    kal_uint8 sig_alg_name[128];
    kal_uint16 sig_alg_name_len;
    kal_uint8 subject[256];
    kal_uint16 subject_len;
    kal_uint8 type;
    kal_uint8 version;
} wps_sec_cert_content_struct;

typedef struct
{
    kal_uint8 *rsa_modulus;
    kal_uint16 mod_len;
    kal_uint8 *rsa_exponent;
    kal_uint16 exp_len;
} wps_sec_rsa_public_key_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 idx;
    wps_sec_cert_content_struct root_ca;
    wps_sec_rsa_public_key_struct rsa_public_key;
} wps_sec_get_x509_ca_cert_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 total;
} wps_sec_get_x509_ca_cert_rsp_struct;

#define MAX_WPS_CERTIFICATE_NUM       20

typedef struct
{
    kal_uint8 format;
    kal_uint32 cert_len;
    unsigned char *cert;
} wps_sec_certificate_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 cert_num;
    wps_sec_certificate_struct certs[MAX_WPS_CERTIFICATE_NUM];
} wps_sec_verify_cert_chain_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 result;
    kal_uint8 format;
    kal_uint32 root_len;  /* root_cert file size */
    kal_uint16 root_cert[261]; /* root_cert file patch in UCS2 with null terminator */
} wps_sec_verify_cert_chain_rsp_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 bearer_type;
    kal_uint32 status;
} wap_bearer_status_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 result;
    kal_uint8 title[82];
    kal_uint8 dcs;
    kal_uint8 url[256];
} wap_select_bookmark_rsp_struct;

typedef struct
{
   kal_uint8  ref_count;
   kal_uint16 msg_len;
   kal_uint8  sim_status;        /* Which SIM card in slot */
   kal_uint8  setting_mode;      /*  Which SIM card is enabled in Setting */
}wap_sim_info_notify_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_bool use_default;
    kal_uint8 conn_type;
    kal_uint32 net_id;
    kal_uint8 addr[4];
    kal_uint16 port;
    char domain[256];
} wps_create_stream_connection_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 channel_id;
    kal_uint8 result;
    kal_int16 error_cause;
} wps_create_stream_connection_rsp_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 channel_id;
    kal_int16 error_cause;
} wps_stream_connection_closed_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 channel_id;
} wps_close_stream_connection_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 channel_id;
    kal_uint8 result;
} wps_close_stream_connection_rsp_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 channel_id;
    kal_uint8 seq_num;
} wps_stream_data_send_req_struct;

typedef struct
{
    kal_uint32 length;
    kal_uint8* data;
} wps_stream_data_send_req_var_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 channel_id;
    kal_uint8 seq_num;
    kal_uint8 result;
} wps_stream_data_send_rsp_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 channel_id;
    kal_uint8 seq_num;
} wps_stream_data_recv_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 channel_id;
    kal_uint8 seq_num;
    kal_uint32 read_length;
} wps_stream_data_read_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 channel_id;
    kal_uint8 seq_num;
    kal_uint8 result;
    kal_bool more;
} wps_stream_data_read_rsp_struct;

typedef struct
{
    kal_uint32 length;
    kal_uint8* data;
} wps_stream_data_read_rsp_var_struct;

typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 idx;
} wps_sec_delete_ca_cert_req_struct;

typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 idx;
   kal_uint8 result;
} wps_sec_delete_ca_cert_rsp_struct;

typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 request_id;
   kal_uint8 dialog_type;
   kal_uint8 buttons;
   kal_uint32 title_id;
   kal_uint32 text_id;
} wps_show_confirm_dialog_ind_struct;

typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 request_id;
   kal_uint8 result;
} wps_show_confirm_dialog_res_struct;

typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 cert_options;
   kal_uint8 key_purpose;
} wps_sec_get_cert_ids_req_struct;

typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 total;
   kal_uint32 cert_ids[256];
} wps_sec_get_cert_ids_rsp_struct;

typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;   
   kal_uint32 cert_id;
   kal_uint8 key_purpose;
} wps_sec_get_cert_req_struct;

typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;   
   kal_uint32 cert_id;
   kal_uint8 result;
   wps_sec_cert_content_struct cert;
   wps_sec_rsa_public_key_struct rsa_public_key;
} wps_sec_get_cert_rsp_struct;

#include "bam_struct.h"

#endif


