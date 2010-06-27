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
 * tvo_main.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes primary global functions/variables of tvo module.
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

#ifndef MED_NOT_PRESENT

#ifdef __MED_TVO_MOD__

#ifndef _TVO_MAIN_H
#define _TVO_MAIN_H

#define TVO_TV_DETECT_PERIOD   1000     /* 1 sec */

typedef enum
{
    TVO_EVT_NOWAIT = 0,
    TVO_EVT_START = 0x0001,
    TVO_EVT_STOP = 0x0002,
    TVO_EVT_SET_MODE = 0x0004,
    TVO_EVT_GET_BUFFER = 0x0008,
    TVO_EVT_FREE_BUFFER = 0x0010
}
tvo_wait_event_enum;

#define TVO_WAIT_EVENT(evt_) do{                                  \
         kal_uint32 retrieved_events;                             \
         kal_retrieve_eg_events(tvo_context_p->tvo_event, (evt_), \
         KAL_OR_CONSUME, &retrieved_events, KAL_SUSPEND); }while(0)

#define TVO_SET_EVENT(evt_) do{                                                          \
                              kal_set_eg_events(tvo_context_p->tvo_event, (evt_),KAL_OR);\
                              } while(0)

#define TVO_FREE_DUAL_BUFFER() do{                                                                          \
                                    if (tvo_context_p->tv_output_buffer1_address)                           \
                                       med_free_ext_mem((void**)&tvo_context_p->tv_output_buffer1_address); \
                                    if (tvo_context_p->tv_output_buffer2_address)                           \
                                       med_free_ext_mem((void**)&tvo_context_p->tv_output_buffer2_address); \
                                 } while(0)
/*==== PROTOTYPE ===========*/
/* main */
extern void tvo_startup_hdlr(ilm_struct *ilm_ptr);
extern void tvo_main(ilm_struct *ilm_ptr);
extern kal_bool tvo_init(void);

/* msg hander */
extern void tvo_av_cable_detect_ind_hdlr(ilm_struct *ilm_ptr);
extern void tvo_start_req_hdlr(ilm_struct *ilm_ptr);
extern void tvo_stop_req_hdlr(ilm_struct *ilm_ptr);
extern void tvo_set_mode_req_hdlr(ilm_struct *ilm_ptr);
extern void tvo_set_param_req_hdlr(ilm_struct *ilm_ptr);

/* api */

/* ilm */
extern void tvo_send_start_req(module_type src_mod_id, void *data);
extern void tvo_send_stop_req(module_type src_mod_id);
extern void tvo_send_set_mode_req(module_type src_mod_id, void *data);
extern void tvo_send_set_param_req(module_type src_mod_id, void *data);
extern void tvo_send_av_cable_detect_ind(kal_int16 result);
extern void tvo_send_tv_connect_ind(kal_int16 result);

#endif /* _TVO_MAIN_H */ 

#endif /* __MED_TVO_MOD__ */ 

#endif /* MED_NOT_PRESENT */ 

