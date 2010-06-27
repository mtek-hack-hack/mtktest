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
 * img_main.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes primary global functions/variables of image module.
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

#ifdef __MED_IMG_MOD__

#ifndef _IMG_MAIN_H
#define _IMG_MAIN_H

#define IMG_CODEC_BLOCK_WAITING_TIME 5000       /* ms */
#define IMG_CODEC_RETRY_TIME  2000      /* ms */
#define IMG_DECODE_FILE_UNIT  17        /* 128K byte */

typedef enum
{
    IMG_EVT_NOWAIT = 0,
    IMG_EVT_DECODE = 0x0001,
    IMG_EVT_ENCODE = 0x0002,
    IMG_EVT_STOP = 0x0004,
    IMG_EVT_RESIZE = 0x0008,
    IMG_EVT_EXIF_DECODE = 0x0010
}
img_wait_event_enum;

#define IMG_WAIT_EVENT(evt_) do{                                  \
         kal_uint32 retrieved_events;                             \
         IMG_WAIT_EVT(evt_, __LINE__);                            \
         kal_retrieve_eg_events(img_context_p->img_event, (evt_), \
         KAL_OR_CONSUME, &retrieved_events, KAL_SUSPEND); }while(0)

#define IMG_SET_EVENT(evt_) do{                                                          \
                              kal_set_eg_events(img_context_p->img_event, (evt_),KAL_OR);\
                              IMG_SET_EVT(evt_,__LINE__);                                \
                              } while(0)

/*==== PROTOTYPE ===========*/
/* main */
extern void img_startup_hdlr(ilm_struct *ilm_ptr);
extern void img_main(ilm_struct *ilm_ptr);
extern kal_bool img_init(void);

/* msg handler */
extern void img_release_memory(void);
extern kal_int16 img_get_decode_res(kal_uint8 cause);
extern void img_decode_restart(void);
extern void img_codec_retry_handler(void *arg);
extern void img_decode_event_ind_hdlr(ilm_struct *ilm_ptr);
extern void img_encode_event_ind_hdlr(ilm_struct *ilm_ptr);
extern void img_decode_req_hdlr(ilm_struct *ilm_ptr);
extern void img_encode_req_hdlr(ilm_struct *ilm_ptr);
extern void img_stop_req_hdlr(ilm_struct *ilm_ptr);
extern void img_resize_req_hdlr(ilm_struct *ilm_ptr);
extern void img_exif_decode_req_hdlr(ilm_struct *ilm_ptr);

/* ilm */
extern void img_send_decode_req(module_type src_mod_id, void *data);
extern void img_send_encode_req(module_type src_mod_id, void *data);
extern void img_send_decode_finish_ind(kal_int16 result, kal_uint16 seq_num);
extern void img_send_encode_finish_ind(kal_int16 result, kal_uint16 seq_num);
extern void img_send_decode_event_ind(kal_uint8 cause, kal_uint32 arg0, kal_uint32 arg1);
extern void img_send_encode_event_ind(kal_uint8 cause);
extern void img_send_stop_req(module_type src_mod_id);
extern void img_send_resize_req(module_type src_mod_id, void *data);
extern void img_send_resize_done_ind(kal_int16 result, kal_uint16 seq_num);
extern void img_send_exif_decode_req(module_type src_mod_id, void *data);

/* api */
extern void img_set_result(kal_int32 result);
extern void img_set_result_ext(kal_int32 reslt, kal_uint32 arg0, kal_uint32 arg1);
extern void img_set_decoded_width(kal_uint16 width);

#endif /* _IMG_MAIN_H */ 

#endif /* __MED_IMG_MOD__ */ 

#endif /* MED_NOT_PRESENT */ 

