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
 *   stack_ltlcom.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contains the extern declarations and macros for
 *   using the Inter Layer Message structure.
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*********************************************************************
   (C) _____ (year of first publication) Sasken communication
   Technologies Limited, All rights reserved.
*   This file provides a template for .c files. This space
*   should be used to describe the file contents
*   Component-specific prefix : xxxx
*********************************************************************/

#ifndef _STACK_LTLCOM_H
#define _STACK_LTLCOM_H

/*************************************************************************
 * Prototype of functions used in the FSM tables of modules
 *************************************************************************/
typedef void (* fsm_func_ptr)(local_para_struct *,
                              peer_buff_struct *);

/*************************************************************************
 * Exported Function Prototypes
 *************************************************************************/
#define SEND_ILM( src_mod, dest_mod, sap, ilm_ptr)\
{ \
   ilm_ptr->src_mod_id  = src_mod;  \
   ilm_ptr->dest_mod_id = dest_mod; \
   ilm_ptr->sap_id = sap; \
   if (mod_task_g[src_mod] == mod_task_g[dest_mod]) { \
     msg_send_int_queue(ilm_ptr); \
   } else { \
     msg_send_ext_queue(ilm_ptr); \
   } \
}

#if defined(DEBUG_KAL) && defined(DEBUG_ITC)
__inline void
free_ilm(ilm_struct* ilm_ptr)
{
   if (ilm_ptr->src_mod_id != MOD_TIMER)
      free_int_ilm(ilm_ptr, (kal_char*)__FILE__, __LINE__ );
}
#else
__inline void
free_ilm(ilm_struct* ilm_ptr)
{
   if (ilm_ptr->src_mod_id != MOD_TIMER)
      free_int_ilm(ilm_ptr, NULL, 0);
}
#endif /* DEBUG_ITC */

#define SEND_APP_ILM( src_mod, sap, ilm_ptr )\
{\
  ilm_ptr->sap_id      = sap;\
  ilm_ptr->src_mod_id  = src_mod;\
  ilm_ptr->dest_mod_id = MOD_APP;\
  (*app_send_fptr_g)(ilm_ptr);\
}

/*************************************************************************
 * Generic functions used by send_ilm
 *************************************************************************/
#ifdef MTK_NEW_API
extern kal_bool msg_send_ext_queue(ilm_struct *ilm_ptr);
#else
extern kal_bool msg_send_ext_queue( void* param1_ptr, ilm_struct *ilm_ptr);
#endif /* MTK_NEW_API */

#ifdef MTK_NEW_API
extern kal_bool msg_send_ext_queue_to_head(ilm_struct *ilm_ptr);
#else
extern kal_bool msg_send_ext_queue_to_head(void *param1_ptr, ilm_struct *ilm_ptr);
#endif /* MTK_NEW_API */

extern kal_bool msg_send_int_queue(ilm_struct *ilm_ptr);

extern ilm_struct *allocate_ilm(module_type module_id);

extern kal_bool cancel_ilm(module_type module_id);

extern kal_bool hold_peer_buff( peer_buff_struct *peer_buff_ptr);

extern kal_bool hold_local_para( local_para_struct *local_para_ptr );

#ifdef __ROMSA_SUPPORT__
extern void append_to_peer_buff( peer_buff_struct *peer_buff_ptr,
                                 void *tail_data_ptr,
                                 kal_uint8 tail_len);

extern void prepend_to_peer_buff( peer_buff_struct *peer_buff_ptr,
                                  void *header_data_ptr,
                                  kal_uint8 header_len);
#else
extern void append_to_peer_buff( peer_buff_struct *peer_buff_ptr,
                                 void *tail_data_ptr,
                                 kal_uint16 tail_len);

extern void prepend_to_peer_buff( peer_buff_struct *peer_buff_ptr,
                                  void *header_data_ptr,
                                  kal_uint16 header_len);
#endif

extern void* get_local_para_ptr( local_para_struct *local_para_ptr,
                                 kal_uint16 *local_para_len_ptr);

extern kal_status receive_msg_ext_q( kal_msgqid task_ext_qid,
                                     ilm_struct *ilm_ptr);

extern kal_bool msg_get_ext_queue_info(kal_msgqid task_ext_qid,
                                       kal_uint32 *messages);

extern kal_bool msg_get_ext_queue_length(kal_msgqid task_ext_qid, kal_uint32 *length);

#ifdef MTK_NEW_API
extern kal_bool receive_msg_int_q(task_indx_type task_indx, ilm_struct *ilm_ptr);
#endif /* MTK_NEW_API */

#ifdef __ROMSA_SUPPORT__
extern void remove_hdr_of_peer_buff( peer_buff_struct *peer_buff_ptr,
                                     kal_uint8 hdr_len);

extern void remove_tail_of_peer_buff( peer_buff_struct *peer_buff_ptr,
                                      kal_uint8 tail_len);

extern void update_peer_buff_hdr(peer_buff_struct *peer_buff_ptr,
                                 kal_uint8        new_hdr_len,
                                 kal_uint16       new_pdu_len,
                                 kal_uint8        new_tail_len);
#else
extern void remove_hdr_of_peer_buff( peer_buff_struct *peer_buff_ptr,
                                     kal_uint16 hdr_len);

extern void remove_tail_of_peer_buff( peer_buff_struct *peer_buff_ptr,
                                      kal_uint16 tail_len);

extern void update_peer_buff_hdr(peer_buff_struct *peer_buff_ptr,
                                 kal_uint16        new_hdr_len,
                                 kal_uint16        new_pdu_len,
                                 kal_uint16        new_tail_len);
#endif

extern kal_bool hold_peer_buff_r(peer_buff_struct *peer_buff_ptr);

extern kal_bool hold_local_para_r(local_para_struct *local_para_ptr);

#endif /* _STACK_LTLCOM_H */


