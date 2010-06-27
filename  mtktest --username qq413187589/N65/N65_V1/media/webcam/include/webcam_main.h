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
 * webcam_main.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes primary global functions/variables of webcam module.
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef MED_NOT_PRESENT

#ifdef __MED_WEBCAM_MOD__

#ifndef _WEBCAM_MAIN_H_
#define _WEBCAM_MAIN_H_

typedef enum
{
    WEBCAM_EVT_NOWAIT = 0,
    WEBCAM_EVT_START = 0x0001,
    WEBCAM_EVT_STOP = 0x0002,
    WEBCAM_EVT_PAUSE = 0x0004,
    WEBCAM_EVT_RESUME = 0x0008,
    WEBCAM_EVT_CAPTURE = 0x0010,
    WEBCAM_EVT_ROTATE = 0x0011
}
webcam_wait_event_enum;

#define WEBCAM_WAIT_EVENT(evt_) do{                                     \
         kal_uint32 retrieved_events;                                   \
         kal_retrieve_eg_events(webcam_context_p->webcam_event, (evt_), \
         KAL_OR_CONSUME, &retrieved_events, KAL_SUSPEND); }while(0)

#define WEBCAM_SET_EVENT(evt_) do{                                                             \
                              kal_set_eg_events(webcam_context_p->webcam_event, (evt_),KAL_OR);\
                              } while(0)

/*==== PROTOTYPE ===========*/
/* main */
extern void webcam_startup_hdlr(ilm_struct *ilm_ptr);
extern void webcam_main(ilm_struct *ilm_ptr);
extern kal_bool webcam_init(void);

/* msg hander */
extern void webcam_start_req_hdlr(ilm_struct *ilm_ptr);
extern void webcam_start_cnf_hdlr(ilm_struct *ilm_ptr);
extern void webcam_stop_req_hdlr(ilm_struct *ilm_ptr);
extern void webcam_stop_cnf_hdlr(ilm_struct *ilm_ptr);
extern void webcam_pause_req_hdlr(ilm_struct *ilm_ptr);
extern void webcam_pause_cnf_hdlr(ilm_struct *ilm_ptr);
extern void webcam_resume_req_hdlr(ilm_struct *ilm_ptr);
extern void webcam_resume_cnf_hdlr(ilm_struct *ilm_ptr);
extern void webcam_capture_req_hdlr(ilm_struct *ilm_ptr);
extern void webcam_capture_cnf_hdlr(ilm_struct *ilm_ptr);
extern void webcam_rotate_req_hdlr(ilm_struct *ilm_ptr);
extern void webcam_set_camera_attr_req_hdlr(ilm_struct *ilm_ptr);
extern void webcam_start_still_ind_hdlr(ilm_struct *ilm_ptr);
extern void webcam_start_video_ind_hdlr(ilm_struct *ilm_ptr);
extern void webcam_change_video_ind_hdlr(ilm_struct *ilm_ptr);
extern void webcam_drv_abort_ind_hdlr(ilm_struct *ilm_ptr);
#ifdef __SW_JPEG_CODEC_SUPPORT__ 
extern void webcam_encode_req_hdlr(ilm_struct *ilm_ptr);
#endif /* __SW_JPEG_CODEC_SUPPORT__ */ 

/* api */
extern void webcam_set_result(kal_int32 result);

/* ilm */
extern void webcam_send_start_req(module_type src_mod_id, void *data);
extern void webcam_send_start_cnf(kal_int16 result, kal_bool camera_workable);
extern void webcam_send_stop_req(module_type src_mod_id);
extern void webcam_send_pause_req(module_type src_mod_id, void *data);
extern void webcam_send_resume_req(module_type src_mod_id, void *data);
extern void webcam_send_capture_req(module_type src_mod_id);
extern void webcam_send_rotate_req(module_type src_mod_id, void *data);
extern void webcam_send_abort_ind(void);

extern void webcam_send_usb_start_video_req(void *data);
extern void webcam_send_usb_stop_video_req(void *data);
extern void webcam_send_usb_pause_req(void *data);
extern void webcam_send_usb_still_capture_req(void *data);
extern void webcam_send_usb_resume_req(void *data);
extern void webcam_send_usb_set_camera_attr_cnf(void *data);

#ifdef __SW_JPEG_CODEC_SUPPORT__ 
extern void webcam_send_encode_request(kal_uint8 return_code);
#endif /* __SW_JPEG_CODEC_SUPPORT__ */

#endif /* _WEBCAM_MAIN_H_ */ 
#endif /* __MED_WEBCAM_MOD__ */ 

#endif /* MED_NOT_PRESENT */ 

