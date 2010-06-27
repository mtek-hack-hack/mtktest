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
 * mmiapi.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends to dispatch the message
 *
 * Author:
 * -------
 * -------
 *
*==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
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

#define NEW_LOCAL_PTR(t) (t*)construct_local_para(sizeof(t),TD_CTRL);

#define SEND_MESSAGE(MOD_SRC,MOD_DEST,MSG_SAP,MSG_ID,LOCAL,PEER) \
   {                                                             \
      struct ilm_struct *ilm_ptr=NULL;                           \
      ilm_ptr = allocate_ilm( MOD_SRC);                          \
                                                                 \
      ilm_ptr->msg_id = (kal_uint16) MSG_ID;                     \
      ilm_ptr->local_para_ptr = (local_para_struct *)LOCAL;      \
      ilm_ptr->peer_buff_ptr = (peer_buff_struct *)PEER;         \
                                                                 \
      ilm_ptr->src_mod_id  = MOD_SRC;                            \
      ilm_ptr->dest_mod_id = MOD_DEST;                           \
      ilm_ptr->sap_id = MSG_SAP;                                 \
      msg_send_ext_queue(ilm_ptr);                               \
   }

#define MMI_SEND_ILM_EXT( src_mod, dest_mod, sap, ilm_ptr)\
   {                                                      \
      ilm_ptr->src_mod_id  = src_mod;                     \
      ilm_ptr->dest_mod_id = dest_mod;                    \
      ilm_ptr->sap_id = sap;                              \
      msg_send_ext_queue(ilm_ptr);                        \
   }

#ifdef MMIAPI_USING_BLOCKING
/* engine initialize */
extern void mmiapi_init_engine(void);
extern void mmiapi_register_blocking(module_type mod, kal_char *mutex_name);
extern void mmiapi_unregister_blocking(module_type mod);
extern void mmiapi_lock(module_type mod);
extern void mmiapi_unlock(module_type mod);
extern int mmiapi_mod_index(module_type mod);
extern mmiapi_blocking_data_struct *mmiapi_get_blocking_data(module_type mod);
#endif /* MMIAPI_USING_BLOCKING */ 

