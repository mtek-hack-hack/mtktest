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
 *	l4c_context.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for ¡K.
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



#ifndef _L4C_CONTEXT_H
#define _L4C_CONTEXT_H

#ifndef _RMMI_CONTEXT_H
#error "rmmi_context.h shall be included before l4c_context.h"
#endif


#ifdef DATA_DOWNLOAD
#include "fat_fs.h"

#define L4C_IMELODY_DIR L"c:\\USER\\sound\\imelody"
#define L4C_SOUND_OTHER_DIR L"c:\\USER\\sound\\other"
#define L4C_IMAGE_DIR L"c:\\USER\\image\\standard"

#define L4C_ENCODE_BYTE 2
#define L4C_MAX_DATA_DL_NAME_EXTENSION_WIDTH		(5*L4C_ENCODE_BYTE)													//NULL ermiante
#define L4C_MAX_DATA_DL_NAME_WIDTH				((13*L4C_ENCODE_BYTE)	+	L4C_MAX_DATA_DL_NAME_EXTENSION_WIDTH + L4C_ENCODE_BYTE)

typedef struct
{
	kal_uint8 filename[L4C_MAX_DATA_DL_NAME_WIDTH];
	kal_uint16 file_id;
}l4c_download_file_info;

#endif/* DATA_DOWNLOAD */

#include "mmi_l3_enums.h"

#include "mcd_l3_inc_struct.h"
#include "l4c_hz_context.h"

#include "med_struct.h"

#define MAX_CONCAT_SMS_NUM    4

//#define MAX_CEER_REPORT_LEN    80

#define L4C_STATES      3

//#define L4C_PTR      LAYER4_PTR(l4c_ptr)
#define L4C_PTR        l4c_ptr_g
#define RMMI_PTR     l4c_ptr_g->rmmi_ptr

#ifdef __HOMEZONE_SUPPORT__
#define HZ_PTR     l4c_ptr_g->hz_ptr
#endif

#ifdef __MCD__

extern peer_buff_struct *l4c_mcd_pack (kal_uint16 structid,
                  kal_uint8 *msg,
                  kal_uint8 hdr_size,
                  kal_uint8 tlr_size);

extern kal_uint16 l4c_mcd_unpack(kal_uint16 structid,
                           peer_buff_struct *peer_buff_ptr);

#define L4C_PACK_ALLOC(ALLOC_FUNC, STRUCTID, STRUCT, MSG_PTR) \
   mcd_pseudo_alloc(STRUCTID, l4_pun_src_buff ,sizeof(l4_pun_src_buff)); \
   MSG_PTR = (STRUCT*)l4_pun_src_buff

#define L4C_UNPACK_ALLOC(ALLOC_FUNC, STRUCTID, STRUCT, MSG_PTR)

#define L4C_PACK_DEALLOC(DEALLOC_FUNC, MSG_PTR)

#define L4C_UNPACK_DEALLOC(DEALLOC_FUNC, MSG_PTR)

#define L4C_PACK(PACK_FUNC, BITS_FUNC, STRUCTID, MSG_PTR, \
                 HDR_SIZE, TLR_SIZE) \
   l4c_mcd_pack(STRUCTID, \
                (kal_uint8*)MSG_PTR, \
                HDR_SIZE, \
                TLR_SIZE)

#define L4C_UNPACK(UNPACK_FUNC, STRUCTID, STRUCT, MSG_PTR, PEER_BUFF) \
   l4c_mcd_unpack(STRUCTID, PEER_BUFF); \
   MSG_PTR = (STRUCT*)l4_pun_dest_buff

#define REMAP_UNPACK_DATA(MSG_LEN, MSG_PTR) \
   kal_mem_cpy (l4_pun_dest_buff, MSG_PTR, MSG_LEN)

#define COPY_UNPACK_DATA(MSG_LEN, MSG_PTR) \
   ASSERT(MSG_LEN <2048); \
   MSG_PTR = get_ctrl_buffer(MSG_LEN); \
   kal_mem_cpy (MSG_PTR, l4_pun_dest_buff, MSG_LEN)

#define FREE_COPY_UNPACK_DATA(MSG_PTR) \
   free_ctrl_buffer (MSG_PTR)

#define REMAP_PACK_DATA(MSG_LEN, MSG_PTR) \
   kal_mem_cpy (l4_pun_src_buff, MSG_PTR, MSG_LEN)

#define COPY_PACK_DATA(MSG_LEN, MSG_PTR) \
   MSG_PTR = get_ctrl_buffer(MSG_LEN); \
   ASSERT(MSG_LEN <2048); \
   kal_mem_cpy (MSG_PTR, l4_pun_src_buff, MSG_LEN)

#define FREE_COPY_PACK_DATA(MSG_PTR) \
   free_ctrl_buffer (MSG_PTR)

#define SUBFIELD(PARENT, CHILD) PARENT->CHILD

#else

typedef unsigned int (*l4c_pack_func_t)(kal_uint8 *,
                                          void *,
                                          unsigned int);

typedef unsigned int (l4c_unpack_func_t)(void *,
                                           kal_uint8 *,
                                           unsigned int,
                                           unsigned int,
                                           void *);

extern peer_buff_struct *l4c_asn_pack (l4c_pack_func_t msg_pack_func,
                  void *msg_ptr,
                  kal_uint16 length,
                  kal_uint8 hdr_size,
                  kal_uint8 tlr_size);

extern kal_uint16 l4c_asn_unpack(l4c_unpack_func_t msg_unpack_func,
                                 kal_uint16 length,
                                 void *msg_ptr,
                                 peer_buff_struct *peer_buff_ptr);

#define L4C_PACK_ALLOC(ALLOC_FUNC, STRUCTID, STRUCT, MSG_PTR) \
   ASSERT(sizeof(STRUCT) <2048); \
   MSG_PTR = get_ctrl_buffer(sizeof(STRUCT)); \
   ALLOC_FUNC(MSG_PTR)

#define L4C_UNPACK_ALLOC L4C_PACK_ALLOC

#define L4C_PACK_DEALLOC(DEALLOC_FUNC, MSG_PTR) \
   DEALLOC_FUNC(MSG_PTR); \
   free_ctrl_buffer(MSG_PTR)

#define L4C_UNPACK_DEALLOC L4C_PACK_DEALLOC

#define L4C_PACK(PACK_FUNC, BITS_FUNC, STRUCTID, MSG_PTR, \
                 HDR_SIZE, TLR_SIZE) \
   l4c_asn_pack(PACK_FUNC, \
                  MSG_PTR, \
                  (kal_uint16)((BITS_FUNC(MSG_PTR)+7) >> 3), \
                  HDR_SIZE, \
                  TLR_SIZE)

#define L4C_UNPACK(UNPACK_FUNC, STRUCTID, STRUCT, MSG_PTR, PEER_BUFF) \
   l4c_asn_unpack(UNPACK_FUNC, sizeof(STRUCT), MSG_PTR, PEER_BUFF)

#define REMAP_UNPACK_DATA(MSG_LEN, MSG_PTR)
#define COPY_UNPACK_DATA(MSG_LEN, MSG_PTR)
#define FREE_COPY_UNPACK_DATA(MSG_PTR)
#define REMAP_PACK_DATA(MSG_LEN, MSG_PTR)
#define COPY_PACK_DATA(MSG_LEN, MSG_PTR)
#define FREE_COPY_PACK_DATA(MSG_PTR)

#define SUBFIELD(PARENT, CHILD) PARENT.CHILD

#endif


#define L4C_UART_Open UART_Open
#define L4C_UART_Close UART_Close
#define L4C_UART_GetBytes UART_GetBytes
#define L4C_UART_PutBytes UART_PutBytes
#define L4C_UART_GetBytesAvail UART_GetBytesAvail
#define L4C_UART_GetTxRoomLeft UART_GetTxRoomLeft
#define L4C_UART_SetOwner UART_SetOwner
#define L4C_UART_SetFlowCtrl UART_SetFlowCtrl
#define L4C_UART_CtrlDCD UART_CtrlDCD
#define L4C_UART_CtrlBreak UART_CtrlBreak
#define L4C_UART_ClrRxBuffer UART_ClrRxBuffer
#define L4C_UART_ClrTxBuffer UART_ClrTxBuffer
#define L4C_UART_GetOwnerID UART_GetOwnerID
#define L4C_UART_ConfigEscape UART_ConfigEscape
#define L4C_UART_SetBaudRate UART_SetBaudRate
#define L4C_UART_SetDCBConfig UART_SetDCBConfig
#define L4C_UART_SetAutoBaud_Div UART_SetAutoBaud_Div
#define L4C_UART_Purge UART_Purge
#define L4C_UART_GetFlowCtrl UART_GetFlowCtrl



typedef void (*L4C_MSG_FUNCTION) ( local_para_struct *,
                                   peer_buff_struct * );

typedef void (*L4C_CMD_FUNCTION) ();


typedef struct
{
   kal_uint16   length;
   void        *data;
} l4c_parameter_struct;

typedef struct
{
   kal_bool    is_valid;
   kal_bool    need_retry;
   kal_uint16  length;
   void        *local_para;
   void        *peer_buff;
} l4c_concat_sms_buff_struct;

typedef struct
{
   kal_uint8 type;
   kal_uint8 length;
   kal_uint8 number[MAX_CC_ADDR_LEN];
} l4_number_struct;

typedef struct
{
   kal_uint8	reason;
   kal_uint8	mode;
   kal_uint8	timer;
   kal_uint8     dest_buffer[50];           
   kal_uint8     sub_dest_buffer[50];
   kal_bool     sub_addr_flag;
} ccfc_req_param_struct; /* for remembering params of AT+CFCC */

typedef struct
{
   kal_uint8	mode;
} ccwa_req_param_struct; /* for remembering params of AT+CCWA */

typedef struct
{
   kal_uint8	reason;
   kal_uint8	mode;
   kal_uint8 passwd[9];
} clck_ss_req_param_struct; /* for remembering params of AT+CLCK */

#ifdef __CTM_SUPPORT__
typedef struct
{
    kal_uint8 is_turn_on;
    kal_uint8 ctm_interface;
    ctm_param_struct ctm_param;
}l4c_ctm_default_settings_struct;
#endif

typedef struct
{
	kal_uint8	is_gsm_conn_exist;
	kal_uint8	gsm_cipher_cond;
	kal_uint8	gprs_cipher_cond;
} cipher_ind_msg_struct;

typedef struct
{
    /* ============================== action ============================== */
   kal_uint16  cc_current_action[MAX_SOURCE_NUM];  /*l4c_action_enum*/
   kal_uint16  smu_current_action[MAX_SOURCE_NUM];	// MAUI_00635939, to remember if there is pending change password request
                                                  
   l4c_state_enum   cc_state[MAX_SOURCE_NUM];           /* l4c_state_enum */
   //l4c_sub_state_enum   cc_sub_state[MAX_SOURCE_NUM];       /* l4c_sub_state_enum */
   l4c_source_id_enum   cc_user; 

   kal_uint16  ss_current_action;  /*l4c_action_enum*/
   l4c_source_id_enum   ss_user; 

   kal_uint16  sms_current_action;   /*l4c_action_enum*/
   l4c_source_id_enum   sms_user;

   kal_uint16   rac_current_action;
   l4c_source_id_enum   rac_user;

   kal_uint16   tcm_current_action;
   l4c_source_id_enum   tcm_user;

   kal_uint16   phb_current_action;
   l4c_source_id_enum   phb_user;

#ifdef __CTM_SUPPORT__                                                  
   kal_uint16   ctm_current_action;
   l4c_source_id_enum   ctm_user;
#endif
    /* ============================== ~action ============================== */   

    /* ============================== timer ============================== */    
   eventid                    event_id[7]; /* 0: keypad
                                                           1: gprs
                                                           2: gprs
                                                           3: retry
                                                           4: hz 
                                                           5: BT
                                                           6: +EFSL file list*/
   event_scheduler            *event_scheduler_ptr;
   stack_timer_struct         base_timer;
    /* ============================== ~timer ============================== */  

    /* ============================== queue/retry ============================== */      
   /* we using this local context to save local parameter if we have to send one message, 
   but we have to do another thing before it, we have to save in this parameter*/
   l4c_parameter_struct       parameter[MAX_SOURCE_NUM];
   /* parameter 2 is using to save local parameter for retry using*/
   l4c_parameter_struct       parameter2[MAX_SOURCE_NUM];
   /* parameter3 is using to save peer buffer for retry using*/
   l4c_parameter_struct       parameter3[MAX_SOURCE_NUM];
//mtk01616_070910:remove obsolete code
	#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    /* parameter_sat is using to save SAT cc/ss/ussd/sms/dtmf local parameter using*/
   l4c_parameter_struct       parameter_sat;

   /* this flag using to chek the retry mechineism working or not. so that we can ignore some message or clear*/
   /* the queued message for retry */
   kal_bool    retry_flag;   
   /*retry timer timeout, sending queued message, rety_ongoing_flag will set as TRUE until receiving cnf*/
   kal_bool    cc_retry_ongoing_flag;
   /* keep the retry count value */
   kal_uint8   retry_count;   
   kal_uint8 retry_src_id; //src_id that you want to retry
   kal_bool retry_ss; //to tell the retry_flag is set for cc or ss
    /* ============================== ~queue/retry ============================== */  

    /* ============================== other context ============================== */     
   rmmi_context_struct        *rmmi_ptr;

#ifdef __HOMEZONE_SUPPORT__   
   l4c_hz_context_struct *hz_ptr;											 
#endif
    /* ============================== ~other context ============================== */ 

    /* ============================== flag ============================== */
   /* this flag chek if rac is actived tru or fale , we can initila submodule, and can dial ECC call*/
   kal_bool    rac_activated;
   /* keep the value of  GPRS PDP active form NW with auto answser mode */
   kal_bool    tcm_auto_answer;
   /* this flag using to identify the power on procedure with finish indcation, we can use it to chek */
   /* if uper layer like to write sim as power on not finish, in reg_ind if power on not finish we need*/
   /* inform MMI with attach_ind. however, if power on finish, we any reg_ind we will using reg_ind to*/
   /* inform MMI with the registed stste changed. */
   kal_bool    power_on_not_finish;
   /* this flag is using for RMMI setting some equiement value but route to LMMI , it means we LMMI tigger*/
   /* the set request , but we have to inform RMMI and afer confirm we should clear L4C state to default.*/
   kal_bool    route_thru_lmmi;
   kal_uint8 route_thru_lmmi_user;
   /* WTAI (Wireless Telephony Application Interface) */
   kal_bool    wtai_flag;
   /* this flag using for detect the plmn sel cnf and reg_ind message and cehck if it is first camp on this PLMN*/
   /* if true, CFU for CPHS to and SMS memory available message may be send out to NW */
   kal_bool    first_camp_on;
   /* this flag is using for SIM restart and wthin SIM_ERROR_IND with cause , we got to keep this value and when*/
   /* security cnf will perform another proceure*/
   kal_bool    sim_refresh;
   /* this flag using to make sure SIM has receive detach form NW when SIM refesh procedure is running*/
   kal_bool    sim_reg_state_received;
   /* This flag using to make sure SIM has read all reg required data and can be trigger RAC to reg*/
   kal_bool    sim_security_received;   
   /**/
   //kal_bool    ph_reset;
   
   kal_bool   mt_call_incoming; //mtk00468 add for remember one mt call coming , any action should be response as command conflict
   kal_bool    adc_flag; /* using for active or deavtice EM ADC indication*/
   kal_bool    keypad_event_flag;/* using for engineer mode for keypad event use*/
   kal_bool    sim_detected; /* using for ESIMS using*/
   kal_uint16  sim_error_cause; 
   
   kal_bool     phb_ready_flag;
   kal_bool     ciss_ready_flag;
   kal_bool     tcm_ready_flag;
   kal_bool	mmi_ready_flag;   
      
   kal_bool 				sms_da_fdn_check; //using to check if da is approve now   
       
   kal_bool   call_exist; /*copy from L4CCSM_CC_CALL_INFO_IND -> call_exist*/
  // kal_bool   ps_abm_act; /*ABM_ACT by PS: TRUE or FALSE*/
   kal_bool   concat_retry_error; /*concat retry not allowed*/
   kal_bool   csd_end_connect_race_flag; //this flag is using to avoid when we ever send connect indicatino to MMI
   // but before we send it to MMI , END key press. MMI will send ATH to end call
   
   kal_bool usb_plugout; /*detect usb plug out during data transfer*/
   kal_bool  call_alert; /*True: play alert tone, stop it when call connect or call release*/
   //kal_bool  cipher_ind; //from l4csmu_mmrr_ready_ind, true: enable , false: disable
   kal_bool sim_poweroff; //ture: sim power off finished  
   kal_bool sms_init_sent; //true: MSG_ID_L4CSMSAL_INIT_REQ is sent  
   kal_bool is_cpbw_phb_fdn; //true: cpbw type == PHB_FDN   
   kal_bool gprs_connection_timeout; /* Johnny 2006/01/12: KAL_TRUE: gprs connection timeout but can not dereg (due to command conflict) */
   kal_bool wap_init_flag;
   kal_bool sat_ussr_flag; // mtk01616 070325 :for SAT_USSD ,get ussr fac 
   kal_bool mmrr_ready_flag;//mtk01616 070426:mmrr_ready_flag is used only in rac_act_cnf_hdlr to check whether mmrr_ready_ind is already received
   kal_bool phb_need_restartup;//mtk01616_070515: we should pend the phb restartup until reciving mmi_info_ind from smu   
kal_bool sms_bg_action; //mtk01616_070703: to keep MMI sms background sending state
   kal_bool sms_bg_need_delete;//mtk01616_070703: to judge if MMI will delete this sms after background sending
   kal_uint8 sms_bg_index; //mtk01616_070703: to keep MMI sms background sending index
    /* ============================== ~flag ============================== */
         
    /* ============================== value ============================== */
   /* save line number here so that l4c can prepare setup call type to CC according to this value*/
   /* this value is set as default line 1 , but will be change when change line form MMI and keep */
   /* right here.*/
   kal_uint8   line_num;     /*Line_1 Line_2*/
   /* save phone book storage value, so that we can retrive phone book with it storage*/
   kal_uint8   phb_storage;/*MMI (SIM,ME)  L4C(1,2)  */

   /* because we will active rac and smu at the same time, therefore, we have to keep*/
   /* if smu being active so that we can perform normal plmn selection. */
   kal_uint8   concat_sms_num;
   kal_uint8   smu_activated;/* L4C_SMU_INACTIVE, L4C_SMU_ACTIVE,L4C_SMU_ACTIVATE_FAIL*/

   /**/
   //kal_uint8   ph_func;
   kal_uint8   keypad_press_timer; //mtk00468 add for ckpd to simulate driver kedpad event using. 

   kal_uint8  mt_call_id; //keep the imcoimg call ID, this is make sure when release by NW we can clear the mt_call_imcoming flag correct
   kal_uint8  crss_opcode;//MMI may using chld to accept one mt call , we need to keep it so that in crss cnf we can clear the above flag

   /* 030618 mtk00468 add handle the power on mode in different mode , we have to keep this value.*/
   /* when mode is not normal power , after uem_startup_cnf we dont need to initial other module*/
   kal_uint8   poweron_mode; /* POWER_ON_KEYPAD  0 POWER_ON_ALARM 1 POWER_ON_CHARGER_IN  2 */

   /* keep the CLI vlaue here so that we can fill in setup message using this variable CLIR_INVOKE,
   CLIR_SUPPRESS, CLIR_AUTO*/
   kal_uint8   clir_flag; 
   
   kal_uint32   data_left_size[3]; /* EM mode, GPRS send data left size */ //mtk00714 w0634
   
   kal_uint8    uart_port_value; /* this value store the default value form NVRAM */
  
   kal_uint16    cpbr_range[2];
   kal_uint8    cpbf_findtext[30];

//   kal_uint8     ceer_report[MAX_CEER_REPORT_LEN];//this array save the last unsuccessful call 
   kal_uint8     ceer_report;
   //setup or in call modification , the last call release.
   
   void	    *sms_da_number;
   //mtk01616_070910
////   l4c_concat_sms_buff_struct concat_sms[MAX_CONCAT_SMS_NUM];

   kal_uint16  ps_abm_current_action;  /* L4C_NO_ACTION, ABM_ACT, ABM_DEACT*/
   //l4c_sub_state_enum   abm_sub_state;       /* l4c_sub_state_enum */

   kal_uint8  ekey_mode; /* 20040510 mtk00714 add +EKEY for Joseph: to enable testing +CKPD from Catcher during dial-up*/
   kal_uint8 rr_plmn_sel_flag; /* uisng to keep RR doing plmn sel lead E-call fail */
   kal_uint8 plmn_sel_by_retry; // mtk01616 070409 flag to indicate the plmn is caused by l4c call retry

   kal_uint8 physical_port;
   kal_uint16 phb_del_index;
   kal_uint8	phb_del_storage;
   kal_uint8 waiting_call_id; /*waiting call id for open/close waiting tone without MMI*/
   kal_uint8 cfun_state;
   kal_uint8  pdp_context_id[GPRS_MAX_PDP_SUPPORT];
   			//bit7-> 0: not exist, 1: exist
   			//bit6 -bit0 -> profile id from abm
   kal_uint8 usb_app; //remember usb app is USB_SWITCH_PORT_APP_DATA or USB_SWITCH_PORT_APP_DEBUG

   kal_uint8 flightmode_state; //l4cmmi_flightmode_enum
   kal_uint8  last_number_seq; //if MAX_PHB_LN_ENTRY > 20, check seq_id = 1
   kal_uint8 last_number_dialed[MAX_CC_ADDR_LEN];//mtk00758 - atdL last number dialed
   kal_uint8 csd_profile_id_for_abm_act_ecc; /* when we abort WAP over CSD in ABM_ACT_ECC,
						 L4C must keep csd_profile_id and send it to abm in L4C_CC_ABM_DISC_IND */
   l4_number_struct l4cphb_approve_req_string;    

   cipher_ind_msg_struct cipher_ind_msg; /* Johnny: L4C will save cipher_ind_msg additionally and send it to MMI after CALL_RING_IND */   
   
   /* Johnny:
      if SET_GPRS_CON_TYPE command conflict with SET_GPRS_CON_TYPE,
      L4C will return TRUE instead of FALSE but pending the latest auto_attach
      and re-do it when clear SET_GPRS_CON_TYPE
      
      l4c_gprs_connect_type_enum =>
      L4C_WHEN_NEEDED,
      L4C_ALWAYS,
      L4C_GPRS_CONN_TYPE_UNKNOWN (init value)
   */
   kal_uint8 pending_latest_auto_attach;   
    /* ============================== ~value ============================== */

    /* ============================== other ============================== */
   /*20040102 mtk00714 add for at+ccfc */
   kal_uint8   ccfc_combi_classx; //original <classx> given by AT+CFCC 
							// each bit is for each classx. (TS or BS) 
							 // 1: we need to make req for this bs_code / 0: ignored
							 //use bit operation 
   kal_uint8   ccfc_current_class; //the class of current req 
   ccfc_req_param_struct ccfc_req_param;  //stores other req parameter information
   kal_bool	ccfc_result;
   
   kal_uint8   ccwa_combi_classx; //original <classx> given by AT+CCWA 
							// each bit is for each classx. (TS or BS) 
							 // 1: we need to make req for this bs_code / 0: ignored
							 //use bit operation 
   kal_uint8   ccwa_current_class; //the class of current req 
   ccwa_req_param_struct ccwa_req_param;  //stores other req parameter information
   kal_bool	ccwa_result;

      kal_uint8   clck_ss_combi_classx; //original <classx> given by AT+CLCK 
							// each bit is for each classx. (TS or BS) 
							 // 1: we need to make req for this bs_code / 0: ignored
							 //use bit operation 
   kal_uint8   clck_ss_current_class; //the class of current req 
   clck_ss_req_param_struct clck_ss_req_param;  //stores other req parameter information
   kal_bool	clck_ss_result;

#ifdef DATA_DOWNLOAD
   FS_HANDLE fd[2];
   kal_uint32 data_buf_len;
   kal_uint8 data_folder;
   kal_bool printingDownloadData_flag ;  /* use to indicate unfinished task of printing download data, rtw_ind will check this */
   kal_uint16 printingDownloadData_loopCount;
	kal_wchar *downloadFilename;
	kal_wchar* downloadFullpath;
	kal_wchar* data_rename_path[2];
	
   kal_uint8 download_src_id;//set to rmmi_current_src_id
#ifdef FMT_NOT_PRESENT 								
   kal_wchar data_filename[50];
#endif
#endif

#ifdef __IRDA_SUPPORT__
   l4c_data_mode_enum      uart_data_mode;
#endif
#ifdef __IP_NUMBER__
   kal_uint8 ip_string[21];
#endif /*__IP_NUMBER__*/

   kal_bool queue_ata; /* when action ==  ATA_EXE and cc_current_action == CHLD_EXE, 
                          L4C will queue ATA_EXE until L4C receive L4CCSM_CC_CRSS_CNF */
   kal_bool queue_chld; /* when action ==  CHLD_EXE (opcode == 0) and cc_current_action == CHLD_EXE, 
                          L4C will queue CHLD_EXE (opcode == 0) until L4C receive L4CCSM_CC_CRSS_CNF */
   kal_uint8 queue_src_id;
   kal_uint8 queue_chld_call_id;
   kal_bool power_on_pin_check;
   kal_uint8 max_retry_count;
 
#ifdef __CTM_SUPPORT__
    l4c_ctm_default_settings_struct ctm_default_settings;
    kal_bool is_ctm_connected;
    kal_uint8 connected_src_id;
    kal_bool is_gpio_plug; /* tty or ear phone */
#endif

    kal_uint8 rat_mode;
#ifdef __CSD_FAX__
    kal_uint8 fax_src_id; //temp solution for fax
#endif /*__CSD_FAX__*/

#ifdef __GEMINI__
kal_uint8 dual_sim_mode_setting;
kal_uint8 dual_sim_uart_setting;
kal_uint8 dual_sim_inserted_status;
kal_uint8 single_sim_inserted_status;
kal_bool is_dual_sim_ind_sent;
kal_bool dual_sim_to_flight_mode;
kal_bool plmn_sel_during_rfon_attach_flag;
#endif
    /* ============================== ~other ============================== */
} l4c_context_struct;





#endif /* l4c_context.h */


