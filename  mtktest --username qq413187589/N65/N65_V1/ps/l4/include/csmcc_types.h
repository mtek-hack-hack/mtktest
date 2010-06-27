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
 *	csmcc_types.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for type definition used in CSM(CC) module.
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


#ifndef _CSMCC_TYPES_H
#define _CSMCC_TYPES_H

typedef kal_uint16 csmcc_ret_t;

typedef enum
{
   CSMCC_CALL_FREE,
   CSMCC_CALL_BLK,
   CSMCC_CALL_UNUSED
} csmcc_call_alloc_enum;

typedef enum
{
   CSMCC_AUTO_DTMF,
   CSMCC_MANUAL_DTMF,
   CSMCC_VTS_DTMF,
   CSMCC_INVALID_DTMF_MODE = 255
} csmcc_dtmf_mode_enum;

typedef enum
{
   CSMCC_CALL_IDLE            = 0x0000, /*0*/
   CSMCC_CALL_INIT            = 0x0001, /*1*/
   CSMCC_CALL_ALERT           = 0x0002, /*2*/
   CSMCC_CALL_ACCEPT          = 0x0004, /*4*/
   CSMCC_CALL_ACTIVE          = 0x0008, /*8*/
   CSMCC_MS_CALL_DISC         = 0x0010, /*16*/
   CSMCC_NW_CALL_DISC         = 0x0020, /*32*/
   CSMCC_NW_CALL_DISC_ON_HOLD = 0x0040, /*64*/
   CSMCC_CALL_MODIFY          = 0x0080, /*128*/
   CSMCC_CALL_HOLD_REQ        = 0x0100, /*256*/
   CSMCC_CALL_HOLD            = 0x0200, /*512*/
   CSMCC_CALL_RETRIEVE_REQ    = 0x0400  /*1024*/
} csmcc_call_state_enum;

#define CSMCC_ALL_DISC_STATES (CSMCC_MS_CALL_DISC|   \
                               CSMCC_NW_CALL_DISC|   \
                               CSMCC_NW_CALL_DISC_ON_HOLD)   \

typedef enum
{
   CSMCC_CCBS_NONE,
   CSMCC_CCBS_POSSIBLE,
   CSMCC_CCBS_ACTIVATED,
   CSMCC_CCBS_INVOKED
} csmcc_ccbs_status_enum;

typedef enum
{
   CSMCC_MPTY_IDLE,
   CSMCC_MPTY_REQ,
   CSMCC_MPTY_ACTIVE,
   CSMCC_SPLIT_REQ
} csmcc_mpty_state_enum;

typedef struct csmcc_dtmf_struct
{
   kal_uint8          *digit;
   kal_uint8          cur_digit_index;
   kal_uint8          count;  
} csmcc_dtmf_struct;

typedef struct csmcc_inv_info_struct
{
   kal_bool           used;
   kal_uint32          inv_id;
   kal_uint8          opcode;
} csmcc_inv_info_struct;

typedef struct csmcc_cug_info_struct
{
   kal_uint16 cug_index;
   kal_uint8 cug_suppress;
} csmcc_cug_info_struct;

typedef struct csmcc_call_context_struct
{
   kal_uint8                   call_id;
   kal_uint8                   src_id;
   kal_uint8                   ti;
   kal_bool                    number_present;
   l4_addr_bcd_struct          number;
   kal_bool                    sub_addr_present;
   l4ccsm_cc_sub_addr_struct   sub_addr;
   csmcc_dtmf_mode_enum        dtmf_mode;
   kal_bool                    wait_stop_dtmf;
   csmcc_call_orig_enum        call_orig;   
   csmcc_dtmf_struct           dtmf;
   kal_bool                    cw_flag;                   
   kal_bool                    cug_info;
   kal_uint8                   clir_info;
   csmcc_call_priority_enum    call_priority;   
   csmcc_ccbs_status_enum      ccbs_status;
   kal_uint8                   ccbs_index;
   csmcc_mpty_state_enum       mpty_state;
   csmcc_call_mode_enum        call_mode;
   kal_uint8                   cur_call_type;
   csmcc_call_type_enum        bc[2];
   csmcc_call_state_enum       call_state;
   /* store previous state, when send or receive DISC */
   csmcc_call_state_enum       pre_call_state; 
   kal_uint32                  ccm;
   kal_uint32			 aoc_cdur;
   csmcc_inv_info_struct       inv_info;   

   /*mtk01602, 080124: temp solution for MAUI_258855. 
   Add additional information to tell if setup_cnf of normal call, 
   emergency call or sat setup call is sent or not*/
   kal_bool                    setup_cnf_not_sent;
   
   /* the following variable is for:
      1. sending connect indication after data activation in case of MO data or fax call 
      2. sending incoming call indication after sending alerting request in case of 
         early assignment */
   local_para_struct                *local_para_ptr;
   #ifdef __SAT__
   kal_uint8   sat_call_type;
   kal_uint8   type_of_modification; //mtk01602: Store tom for SAT modified call to avoid L4C retry but send call ctrl again
   #endif

   /*mtk01602: R4 new feature, Emergency Call Category*/
   #ifdef __REL4__
   kal_uint8                service_category;
   #endif

} csmcc_call_context_struct;

typedef struct csmcc_v120_param_struct
{
   csmcc_v120_rah_enum          v120_rah;
   csmcc_v120_mfm_enum          v120_mfm;
   csmcc_v120_mode_enum         v120_mode;
   csmcc_v120_llineg_enum       v120_llineg;
   csmcc_v120_assign_enum       v120_assign;
   csmcc_v120_negtype_enum      v120_negtype;
} csmcc_v120_param_struct;

typedef struct csmcc_rlp_param_struct
{
   kal_uint8           rlp_iws;
   kal_uint8           rlp_mws;
   kal_uint8           rlp_T1;
   kal_uint8            rlp_N2;
   kal_uint8            rlp_ver;
   kal_uint8            rlp_T4;
} csmcc_rlp_param_struct;

typedef struct csmcc_data_compression_param_struct
{
   csmcc_data_compression_dir_enum         dir;
   csmcc_data_compression_nego_enum        negotiation;
   kal_uint16                              max_dict;
   kal_uint8                               max_string;
} csmcc_data_compression_param_struct;

typedef struct csmcc_data_bc_param_struct
{
   csmcc_sync_enum             sync;
   csmcc_bearer_ce_enum        ce;
   csmcc_itc_enum              itc;
   csmcc_other_itc_enum        other_itc;
   csmcc_user_rate_enum        ur;
   csmcc_fnur_enum             fnur;
   csmcc_rate_adaptation_enum                ra;
   csmcc_other_rate_adaptation_enum          other_ra;
   csmcc_modem_type_enum                     mt;
   csmcc_other_modem_type_enum               other_mt;
   csmcc_v120_param_struct                   v120_param;
   csmcc_rlp_param_struct                    rlp_param;
   csmcc_data_compression_param_struct       data_compression_param;
   csmcc_nsb_enum              nsb;
   csmcc_ndb_enum              ndb;
   csmcc_parity_enum           parity;
   
} csmcc_data_bc_param_struct;

typedef struct csmcc_bearer_service_type_struct
{
   csmcc_bearer_speed_enum      bearer_speed;
   csmcc_bearer_name_enum       bearer_name;
   csmcc_bearer_ce_enum         bearer_ce;
} csmcc_bearer_service_type_struct;

#ifdef __SATCE__
typedef struct csmcc_sat_profile_struct
{
   l4_addr_bcd_struct addr;
   l4ccsm_cc_sub_addr_struct  subaddr;
   sat_csd_bearer_para_struct sat_cbst;
   kal_uint8 csd_module; //mtk01602, 070618: L4C need csd_module information
   kal_uint8 user_id[CSD_USER_ID_LEN];
   kal_uint8 user_pwd[CSD_USER_PWD_LEN];
   kal_uint8 local_addr[SAT_LOCAL_ADDR_LEN]; 
} csmcc_sat_profile_struct;
#endif

typedef struct csmcc_cf_param_struct
{
   csmcc_cf_format_enum          cf_format;
   csmcc_cf_parity_enum          cf_parity;
} csmcc_cf_param_struct;


typedef struct csmcc_cug_param_struct
{
   csmcc_cug_temporary_mode_enum    cug_temporary_mode;
   kal_uint8                        cug_index;
   csmcc_cug_suppress_enum          cug_suppress;
} csmcc_cug_param_struct;

typedef struct csmcc_at_param_struct
{
   csmcc_addr_type_enum          addr_type;
   csmcc_call_mode_enum          call_mode;
   csmcc_bearer_service_type_struct     bearer_service_type;
   csmcc_sns_mode_enum           sns_mode;
   csmcc_data_compression_param_struct  data_compression_param;
   csmcc_cf_param_struct                cf_param;
   csmcc_v120_param_struct              v120_param;
   csmcc_rlp_param_struct               rlp_param;
   csmcc_aoc_mode_enum                  aoc_mode;
   csmcc_cug_param_struct               cug_param;
   csmcc_fclass_mode_enum               fclass_mode;
} csmcc_at_param_struct;

typedef struct csmcc_nego_bc_struct
{
   kal_bool  bc1_present;
   csmcc_bc_struct  bc1;
   kal_bool  bc2_present;
   csmcc_bc_struct  bc2;
   kal_bool  repeat_present;
   mncc_repeat_ind_struct   bc_repeat_ind;
} csmcc_nego_bc_struct;

typedef struct csmcc_mscap_struct
{
   kal_uint8   speech_version;   
   kal_uint8   acc;   
   kal_uint16  data_cap;
} csmcc_mscap_struct;   

typedef struct csmcc_timer_struct
{
   stack_timer_struct timer;   
   kal_uint8 call_id;
   
} csmcc_timer_struct;

#ifdef __CPHS__
typedef struct csmcc_als_struct
{
   kal_uint8   line_id;
} csmcc_als_struct;
#endif


typedef struct csmcc_context_struct
{
   csmcc_call_alloc_enum            call_pool[MAX_CALL_NUM+1];
   csmcc_call_context_struct        call_tab[MAX_CALL_NUM];
   csmcc_data_bc_param_struct       data_bc_param;
   csmcc_at_param_struct            at_param;
   csmcc_nego_bc_struct             nego_bc;
   csmcc_mscap_struct               mscap;
   kal_uint8                        default_call_priority;
   kal_uint8                        auto_answer_priority_level;   
   csmcc_timer_struct               csmcc_timer;   /* used by auto dtmf pause */
   csmcc_timer_struct               csmcc_timer_2;   /* used by AoC update SIM ACM */   
   kal_bool			     cdur_present;
   kal_uint32			     cdur;
   kal_bool			     updated_cdur_present;
   kal_uint32			     updated_cdur;   
   kal_bool                         call_reest;
   csmcc_attach_status_enum         attach_status;   
   csmcc_channel_info_enum          channel_info;
   kal_uint8                        channel_mode;
   kal_uint8                        channel_type;
   csmcc_req_enum                   cur_req;
   kal_uint8                        req_src_id;
   kal_uint8                        req_call_id;
   /*csmcc_req_enum*/kal_uint8                   aux_req;
   kal_uint8                        aux_req_call_id;
   kal_bool                         is_aux_req_processed;
   csmcc_req_enum                   cur_non_l4c_req;
   kal_uint8                        cur_non_l4c_req_call_id;
   /*mtk01602, 070718: MMI needs opcode in CHLD_RSP, otherwise when there's multiple CHLD_REQ,
    MMI may confused with CHLD_RSP.*/
   csmcc_crss_req_enum              crss_req;
   kal_uint32                        inv_id_count;
   kal_bool                         acm_valid;
   kal_uint32                       acm;
   kal_uint32                       pre_acm;
   kal_uint32                       acmmax;
   kal_uint32                       acmmax_update_temp;
   kal_uint32                       last_ccm;
   kal_bool                          update_acm_flag;
   kal_uint32                       pause_duration;
   kal_bool                          is_sat_dtmf;
   kal_uint8                         dtmf_src_id;
   /*Michael: add for SAT retry, to store ccp from L4C or SIM until send SAT_CALL_SETUP_CNF*/
   kal_uint8                        ccp_temp[15];
   kal_uint8                         size_of_ccp_temp;
   kal_bool                          is_tch;     /*mtk00924 add 041210 for ECPI*/
   kal_bool                          is_ibt;      /*mtk00924 add 041210 for ECPI*/
   kal_uint8                         ctm_status;
   kal_uint8				activate_data_call_id;
   kal_uint8 			      iwf;
#ifdef __MTK_3G_MRAT_ARCH__
   kal_uint8				rat;
#endif
   /* [Cosine 070327] CNAP */
   l4ccsm_cc_name_ind_struct  	cnap_info;
#ifdef __TCPIP__
   /*nvram_ef_csd_profile_struct      csd_prof[MAX_CSD_PROFILE_NUM];*//*mtk00924: for CSD data account can be customized*/
   kal_uint8                        csd_prof_id;   
#endif      

#ifdef __CPHS__
   kal_uint8                              temp_als_id;
   csmcc_als_struct                   als;
#endif

#ifdef __CSD_FAX__
   kal_uint8     fax_dir; /*CSD_FAX_DIRECTION_ENUM*/
#endif
   kal_bool  rscd_P;
#ifdef __SATCE__
   csmcc_sat_profile_struct sat_prof;
#endif

#ifdef __GEMINI__
   module_type csmcc_mod_id;	
#endif
} csmcc_context_struct;

#ifdef __GEMINI__
extern csmcc_context_struct *csmcc_ptr_g;

#define CSMCC_PTR   (csmcc_ptr_g)
#else
extern csmcc_context_struct csmcc_context_g;

#define CSMCC_PTR   (&csmcc_context_g)
#endif /*__GEMINI__*/

/*every ILM from L4C, which relates one call
  shall be having the following header */
  
typedef struct l4ccsm_cc_local_para_hdr_struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 call_id;
} l4ccsm_cc_local_para_hdr_struct;

typedef l4_addr_bcd_struct mncc_called_num_struct;
typedef l4ccsm_cc_peer_addr_struct   mncc_calling_num_struct;
typedef l4ccsm_cc_sub_addr_struct mncc_sub_addr_struct;
#endif /* _CSMCC_TYPES_H */


