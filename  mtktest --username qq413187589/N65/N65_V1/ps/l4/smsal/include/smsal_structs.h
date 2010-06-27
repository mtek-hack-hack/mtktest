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
 *	smsal_structs.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for defining data structures used in SMSAL context.
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


#ifndef _SMSAL_STRUCTS_H
#define _SMSAL_STRUCTS_H


/* if some header should be include before this one */
#ifndef _SMSAL_L4C_ENUM_H
#error "smsal_l4c_enum.h should be included before smsal_structs.h"
#endif

#if defined(__MTK_3G_MRAT_ARCH__)
#ifndef _l3_INC_ENUMS_H
#error "L3_inc_enums.h should be included before smsal_structs.h"
#endif
#endif

#ifndef _L4C2SMSAL_STRUCT_H
#error "l4c2smsal_struct.h should be included before smsal_structs.h"
#endif

#ifndef _SMSAL_PEER_STRUCT_H
#error "smsal_peer_struct.h should be included before smsal_structs.h"
#endif

#ifndef _MNSMS_STRUCT_H
#error "mnsms_struct.h should be included before smsal_structs.h"
#endif


#define SMSAL_MAX_FILE 18

typedef struct _nvram_smsal_common_param_struct smsal_nvm_common_param_struct;

struct _read_file_aux_info_struct;

typedef struct _read_file_aux_info_struct smsal_read_file_aux_info_struct;

typedef kal_uint8 (*READ_FILE_FUNC)(kal_uint8, /* id */
                                   smsal_read_file_aux_info_struct *,
                                   peer_buff_struct  *, 
                                   local_para_struct *);

typedef void (*READ_FILE_FINISH_FUNC)(kal_uint8, /* id */
                                      kal_bool  /* result */);

typedef struct
{  
   kal_bool       is_used; 
   kal_uint8      file_id;
   kal_uint8      read_type;
   READ_FILE_FUNC succ_fn_ptr;   
   READ_FILE_FUNC fail_fn_ptr;   
} file_list_struct;

struct _read_file_aux_info_struct
{
   kal_uint32            file_type_bitmap;  /* 0: sim, 1: nvram
                                             * bit0: 1st read file
                                             * bit1: 2nd read file, so on 
                                             */
                                             
   kal_bool              occur_error;       /* whether occur error during
                                             * reading files */
   kal_uint8             current_read_idx;  /* index of current read file */
   kal_uint16            record_no;         /* current record no */
   kal_uint16            number;            /* store number of records */
   kal_uint16            nvram_rec_amount;  /* nvram multiple recoder reading */
   kal_uint16            nvram_rec_decoded; /* number of record already prcessed */
   kal_bool              send_init_cnf;     /* for SIM refresh during SMSAL initialization */

   kal_uint8             msg_box_seq_num;   /* used during startup */

   file_list_struct      file[SMSAL_MAX_FILE];
   READ_FILE_FINISH_FUNC finish_fn_ptr;     
};

/* Message Waiting Indication Status */
typedef struct
{
   //kal_uint8 waiting_ind;
   kal_uint8 waiting_num[NUM_OF_MSG_WAITING_TYPE];
} smsal_mwis_struct;

typedef struct 
{
   kal_uint8         type_of_info;
   kal_bool          need_store;
   kal_bool          is_msg_wait;
   kal_bool          is_show_num[NUM_OF_MSG_WAITING_TYPE];
   kal_bool          is_clear[NUM_OF_MSG_WAITING_TYPE];
   kal_bool          ind_flag[NUM_OF_MSG_WAITING_TYPE];
   smsal_mwis_struct mwis;    
} smsal_msg_waiting_struct;

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
#endif

typedef struct
{
   /* smsal_mb_entry_state_enum */
   kal_uint8                       state;
                                    /* state of the entry */

   /* smsal_storage_enum */
   kal_uint8                        storage_type;                                    
                                    /* storage type of the entry */

   /* smsal_mti_enum */
   kal_uint8                        mti;
                                    /* message type identifier */

   kal_uint8                        status;        
                                    /* status of the message */

   kal_uint16                       record_no;     
                                    /* indicate record number in storage */

   kal_uint16                       mb_type_ind;     
                                    /* bitmap for specific type SM, ie. PID with replace type,  */
                                    /* FO with reply path.                                      */

} smsal_mb_entry_struct;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __CPHS__
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#endif

typedef struct
{     
   kal_uint16   inbox_sim_num;
   kal_uint16   outbox_sim_num;
   
#ifdef __SMS_ME_STORAGE__   
   kal_uint16   inbox_me_num;
   kal_uint16   outbox_me_num;
#endif

   kal_uint16	sim_msg_num;   	/* maximum number of 
                                    supported messages in SIM */
   kal_uint16   used_sim_msg_num;
   
#ifdef __SMS_ME_STORAGE__
   kal_uint16	me_msg_num;       /* maximum number of 
                                    supported messages in ME */
   kal_uint16  used_me_msg_num;
#endif
   
} smsal_storage_num_struct;


typedef struct
{      
   l4_name_struct       profile_name;
                        /* store alpha-identifier */

   kal_uint8	         para_ind;                              
                        /* Parameter Indicator */

   kal_uint8	         vp;                                    
                        /*	Validity period */

   kal_uint8	         pid;                                   
                        /*	Protocol identifier */

   kal_uint8	         dcs;                                   
                        /*	Data coding scheme */

   sms_addr_struct      sca;  
                        /* Service Centre Address */

   sms_addr_struct      da;  
                        /* Destination Address */

} smsal_profile_element_struct;

/* KEEP this struct even SAT is not supported */
typedef struct 
{
   sms_addr_struct        sc_addr;
   sms_addr_struct        dest_addr;   
} smsal_sat_addr_struct;


typedef struct
{
   kal_int32 dest_port; /* -1: invalid port */
   kal_int32 src_port;
} smsal_port_struct;


typedef struct
{
   union 
   {
      smsal_deliver_peer_struct  deliver_tpdu;
      smsal_submit_peer_struct   submit_tpdu;
      smsal_status_report_peer_struct  report_tpdu;
   } data;

   smsal_concat_struct        concat_info;
                
   smsal_mti_enum             mti;      
   kal_uint8                  fo;     /* first octet */
   kal_uint8                  offset; /* offset to message content */
   kal_uint8                  msg_len;/* length of user data */   
  
   kal_uint8                  udhl;   /* for calculating offset to unpack */

   /* for decoding DCS */   
   smsal_msg_class_enum       msg_class;    
   smsal_alphabet_enum        alphabet_type;
   kal_bool                   is_compress;
   smsal_msg_waiting_struct   msg_wait;

   smsal_port_struct          port;

} smsal_tpdu_decode_struct;

typedef struct
{
   sms_addr_struct          sca;
   smsal_tpdu_decode_struct tpdu; 
   kal_uint8                pdu_len;   /* length of PDU */
   kal_uint8                tpdu_len;  /* length of TPDU */
} smsal_pdu_decode_struct;


typedef struct
{     
   kal_uint8                  bitmap; /* refer to smsal_reset_file_enum */ 

} smsal_reset_file_aux_info_struct;

typedef struct
{   
   kal_uint16                   index;                                
   
#ifdef __SMS_ME_STORAGE__
   kal_uint8                   storage_type;
#endif
} smsal_write_aux_info_struct;

typedef struct
{
   kal_uint8              src_id;
   kal_uint8              msg_ref;
} smsal_pending_send_struct;

typedef struct
{   
   kal_uint8                   smi;
   kal_uint8                   replace_count;
   kal_uint8                   pid_type;       /* Replace type or Return Call Message */
   kal_bool                    is_msg_writing;
   kal_uint16                  index;                                      
   smsal_pdu_decode_struct     *pdu_decode;   
   
#ifdef __SMS_ME_STORAGE__
   kal_uint8                   storage_type;
#endif
} smsal_mt_msg_aux_info_struct;

typedef struct
{   
   kal_uint16             index;                                      
   kal_uint8              msg_ref;
   kal_uint8              status;
   sms_addr_struct        rcpnt_addr;

} smsal_status_report_aux_info_struct;


typedef struct
{  
   kal_uint8   set_ind; /* 0: not present 1:present 
                           bit0: common param in NVRAM (NVRAM_EF_SMSAL_COMMON_PARAM_LID)
                           bit1: mailbox num in NVRAM (NVRAM_EF_SMSAL_MAILBOX_ADDR_LID) or 
                                                SIM (FILE_MAILBOX_NUM_IDX if CPHS) 
                           bit2: profile in SIM (FILE_SMSP_IDX) */
   smsal_nvm_common_param_struct *common;   
   smsal_profile_element_struct  *profile;
} smsal_set_param_aux_info_struct;

#ifdef __CB__ /* added by Kevin */
typedef struct
{  
   kal_uint8                     ori_para_ind; /* original para_ind */
   kal_uint8                     para_ind; /* smsal_cb_para_enum */

#if defined(__MTK_3G_MRAT_ARCH__)
   kal_uint16                    cbmi[CB_MAX_MSG_CBMI_NUM];
#else
   kal_uint16                    cbmi[SMSAL_PS_CBMI_MAX_ENTRY];
#endif

   kal_uint16                    cbmir[SMSAL_CB_MAX_ENTRY*2];   
   kal_uint16                    dcs[SMSAL_CB_MAX_ENTRY];

   kal_uint8                     cbmir_mask[SMSAL_CB_MAX_ENTRY];

#if defined(__MTK_3G_MRAT_ARCH__)
   kal_uint8                     cbmi_mask[CB_MAX_MSG_CBMI_NUM];
#else
   kal_uint8                     cbmi_mask[SMSAL_PS_CBMI_MAX_ENTRY];
#endif

   kal_uint8                     dcs_mask[SMSAL_CB_MAX_ENTRY];

   kal_uint8                     cbmi_num;
   kal_uint8                     cbmir_num;   
   kal_uint8                     dcs_num;

   kal_uint8                     is_all_lang_on;
} smsal_set_cb_aux_info_struct;
#endif

typedef struct
{     
   kal_uint8              src_id;
   kal_uint8              msg_ref;

   kal_uint8            scts[7];
   kal_uint8            sat_res_type;
   
   kal_bool               is_da_modified;
                           /* to identify the DA in sat_addr is modified */
                           /* by RP message or SAT.                      */

   kal_uint8              req_type; /* send message or command */
   smsal_sat_addr_struct  sat_addr;   
   smsal_concat_struct    concat_info;   

   peer_buff_struct       *peer_to_send;

} smsal_send_sms_aux_info_struct;

#if defined (__SAT__)
typedef struct
{  
   kal_uint8              smi; 
   kal_uint8              dcs;      
   kal_uint8              pid;
} smsal_sim_dl_aux_info_struct;
#endif



typedef struct 
{
   kal_uint8            in_use;           /* KAL_TRUE:  used
                                             KAL_FALSE: free to use */
   kal_uint8            act_code;         /* Main action code */
   kal_uint8            sub_act_code;     /* Sub action code */

   local_para_struct    *local_para_ptr;  /* To hold the pointer 
                                             of request struct */

   peer_buff_struct     *peer_buff_ptr;   /* To hold the pointer of
                                             peer message */

   void                 *aux_info;        /* auxiliary information which 
                                             store the necessary data */
} smsal_pending_act_struct;

typedef struct
{
   kal_uint8	status_report;			
   kal_uint8	reply_path;			
   kal_uint8   vp_format;
   kal_uint8	bearer_service;			

   kal_uint8	sms_fdn_off;			
      
   kal_uint8	fo;               /*	First octet , includes 
                                  * reply path, status report request, 
                                  * validity period format, etc. */
} smsal_common_parameter_struct;

typedef struct
{
   kal_uint8	max_profile_num; 	/* maximum number of supported 
                                  * SMS parameter profiles in SIM */

   kal_uint8   alpha_size;       /* size of alpha-identifier in EFsmsp */

   smsal_profile_element_struct profile[SMSAL_MAX_PROFILE_NUM];

} smsal_profile_parameter_struct;

typedef struct
{   
   /*smsal_service_mode_enum*/
   kal_uint8                     service_mode;
   smsal_service_mode_struct	   service_info;
   smsal_mt_msg_route_struct	   nmi_para;          
                                 /*	New Message Indication Parameters */
                                 
   /*smsal_storage_enum*/
   kal_uint8                     prefer_mem1;
   kal_uint8                     prefer_mem2;
   kal_uint8                     prefer_mem3;
   
   /*smsal_msg_format_enum*/
   kal_uint8              	      message_format;    /* 0: PDU mode 1:TEXT mode */
   
   //kal_uint8	                  sdh;	            /* Show Detailed Header		
   //                                                   0: not show 1: show */
   kal_uint8	                  mms;              /*	mode of More Message to Send		
                                                      refer to 127.005 3.5.6 */

   /* RMI activate profile ID, refer to smsal_profile_parameter_struct  */
   kal_uint8                     act_pfile_id;

   kal_uint8                     set_read_status;

   /* running profile, ie: running setting for RMI */
   smsal_profile_element_struct  profile;

} smsal_rmi_parameter_struct;

typedef struct
{
   smsal_mwis_struct          mwis[SMSAL_MAX_LINES]; /* msg waiting status */
   smsal_mailbox_addr_struct  addr[SMSAL_MAX_LINES]; /* mailbox address */
   kal_uint8 alpha_size;     /* alpha id size of EFmailbox_numr */

#ifdef __CPHS__
   kal_uint8 mwf_file_size;  /* file size of EFmwf */
   kal_uint8 rec_num;        /* record number of EFmailbox_numr */
#endif

} smsal_mailbox_info_struct;

typedef struct
{     
   smsal_rmi_parameter_struct       rmi;
   smsal_common_parameter_struct    common;
   smsal_profile_parameter_struct   profile;
   smsal_mailbox_info_struct        mailbox;               
} smsal_parameter_struct;

typedef struct
{
   kal_bool    is_used;
   kal_bool    sent_report;
   kal_uint8   smi;
} smsal_pending_cnmi_struct;

typedef struct
{
   kal_bool    pending_smma;
} smsal_pending_smma_struct;


#ifdef __CB__

/* for CB queueing */
typedef struct
{
   kal_uint8  total_pages; /* 0xff: not used */
   kal_uint8  page;
   kal_uint8  recv_pages;
   kal_uint8  dcs;
   kal_uint8  alphabet;
   kal_uint16 cbmi;   
   kal_uint16 sn;   
   kal_uint16 pages_map; /* bit map for received pate */
   kal_uint32 last_time; /* unit: system ticks */
#if !defined(__MTK_3G_MRAT_ARCH__)
   kal_uint8  page_offset[15]; /* offset of each page */
#endif
   l4csmsal_cb_msg_text_ind_struct *msg_ind ;    /* for start pointer of data */
} smsal_cb_ctrl_block_struct;

typedef struct
{
   kal_uint8                             cbch_req;
   kal_uint8                             hz_act;

   kal_uint16                            cbmi_default[SMSAL_DEFAULT_CBMI_ENTRY];

#if defined(__MTK_3G_MRAT_ARCH__)
   kal_uint16                            cbmi[CB_MAX_MSG_CBMI_NUM];
#else
   kal_uint16                            cbmi[SMSAL_PS_CBMI_MAX_ENTRY];
#endif

   kal_uint16                            cbmir[SMSAL_CB_MAX_ENTRY*2];
   kal_uint16                             dcs[SMSAL_CB_MAX_ENTRY];
   kal_uint16                            cbmid[SMSAL_CB_MAX_ENTRY];

#if defined(__MTK_3G_MRAT_ARCH__)
   kal_uint8                             cbmi_mask[CB_MAX_MSG_CBMI_NUM];
#else
   kal_uint8                             cbmi_mask[SMSAL_PS_CBMI_MAX_ENTRY];
#endif

   kal_uint8                              cbmir_mask[SMSAL_CB_MAX_ENTRY];/* added by Kevin */
   kal_uint8                              dcs_mask[SMSAL_CB_MAX_ENTRY];

   kal_uint8                             cbmi_num;
   kal_uint8                             cbmir_num;
   kal_uint8                             dcs_num;
   kal_uint8                             cbmid_num;

   kal_bool                              is_elp_used; /* true: if EFelp is used */
   kal_bool                              all_lang_on; /* true: all cb languages turn on */  
   
   /* for CB queueing */
   smsal_cb_ctrl_block_struct            ctrl_blk_pool[SMSAL_CB_MAX_SESSION];

} smsal_cb_struct;
#endif

typedef struct
{
   kal_int32 port[SMSAL_MAX_REG_PORT_NUM];    /* invalid: SMSAL_INVALID_PORT_NUM */
   kal_uint16 mod_id[SMSAL_MAX_REG_PORT_NUM];
} smsal_reg_port_struct;

#if defined(__SMS_ME_STORAGE__) 
typedef struct
{
   smsal_concat_struct concat_info; /* total_seg = 1 : free slot */	
   kal_uint16          hash;
   kal_uint8           storage_type;
} smsal_concat_msg_save_struct;
#endif

#endif /* _SMSAL_STRUCTS_H */

