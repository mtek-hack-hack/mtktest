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
 * cam_main.h
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

#ifndef MED_NOT_PRESENT

#ifdef __MED_CAM_MOD__

#ifndef _CAM_MAIN_H
#define _CAM_MAIN_H

#define CAM_POWER_UP_INIT_TIME      200 /* ms, Power up polling first time period */
#define CAM_POWER_UP_POLLING_TIME   20  /* ms, Power up periodic polling time out period */
#define CAM_PREVIEW_INIT_TIME      10   /* ms, Preview polling first time period */

#ifdef CAMERA_MODULE_WITH_LCD
#define CAM_PREVIEW_POLLING_TIME    200 /* ms, Preview periodic polling time period */
#else 
#define CAM_PREVIEW_POLLING_TIME    10  /* ms, Preview periodic polling time period */
#endif 
#define CAM_CAPTURE_INIT_TIME      20   /* ms, Capture polling first time period */
#define CAM_CAPTURE_POLLING_TIME    20  /* ms, Capture periodic polling time period */

#define MAX_POWER_UP_CHECK_COUNT 4
#define MAX_PREVIEW_CHECK_COUNT 150
#define MAX_PREVIEW_RETRY_COUNT 3
#define MAX_CAPTURE_CHECK_COUNT 400
#define MAX_CAPTURE_RETRY_COUNT 3

#define CAPTURE_MEM_MARGIN  (512)       /* Minimal necessary storage space for capture. */
#define MIN_JPG_FILE_SIZE (128) /* Minimal necessary storage space for capture. */

typedef enum
{
    CAM_EVT_NOWAIT = 0,
    CAM_EVT_PREVIEW = 0x0001,
    CAM_EVT_STOP = 0x0002,
    CAM_EVT_CAPTURE = 0x0004,
    CAM_EVT_SET_PARAM = 0x0008,
    CAM_EVT_POWER_UP = 0x0010,
    CAM_EVT_AUTOFOCUS = 0X0020,
    CAM_EVT_MWB_OP = 0X0040,
    CAM_EVT_GET_FAST_ZOOM_FACTOR = 0x0080,
    CAM_EVT_STOP_FAST_ZOOM = 0X0100,
    CAM_EVT_SET_PAL = 0X0200,
    CAM_EVT_GET_FOCUS_STEPS = 0X0400,
    CAM_EVT_CAPTURE_BARCODE = 0x0800,
    CAM_EVT_STOP_CAPTURE_BARCODE = 0x1000
}
cam_wait_event_enum;

#define CAM_WAIT_EVENT(evt_) do{                                  \
         kal_uint32 retrieved_events;                             \
         CAM_WAIT_EVT(evt_, __LINE__);                            \
         kal_retrieve_eg_events(cam_context_p->cam_event, (evt_), \
         KAL_OR_CONSUME, &retrieved_events, KAL_SUSPEND); }while(0)

#define CAM_SET_EVENT(evt_) do{                                                          \
                              kal_set_eg_events(cam_context_p->cam_event, (evt_),KAL_OR);\
                              CAM_SET_EVT(evt_,__LINE__);                                \
                              } while(0)

/*==== PROTOTYPE ===========*/
/* main */
extern void cam_startup_hdlr(ilm_struct *ilm_ptr);
extern void cam_main(ilm_struct *ilm_ptr);
extern kal_bool cam_init(void);

/* msg handler */
extern kal_int16 cam_set_flash(kal_int16 flash_mode);
extern void cam_set_flash_req_hdlr(ilm_struct *ilm_ptr);

extern void cam_power_up_req_hdlr(ilm_struct *ilm_ptr);
extern void cam_power_down_req_hdlr(ilm_struct *ilm_ptr);
extern void cam_preview_callback(kal_uint8 cause);

#ifdef __CAM_AUTO_FOCUS__
extern void cam_focus_callback(kal_uint8 cause);
#endif 
extern void cam_preview_req_hdlr(ilm_struct *ilm_ptr);
extern void cam_stop_req_hdlr(ilm_struct *ilm_ptr);
extern void cam_capture_req_hdlr(ilm_struct *ilm_ptr);
extern void cam_set_param_req_hdlr(ilm_struct *ilm_ptr);
extern void cam_abort_to_idle(void);
extern void cam_mwb_op_req_hdlr(ilm_struct *ilm_ptr);
extern void cam_set_overlay_palette_req_hdlr(ilm_struct *ilm_ptr);

#if defined (ISP_SUPPORT)
extern void cam_release_memory(void);
extern void cam_event_ind_hdlr(ilm_struct *ilm_ptr);
#if defined (BARCODE_SUPPORT)
extern void cam_barcode_preview_req_hdlr(ilm_struct *ilm_ptr);
extern void cam_barcode_stop_req_hdlr(ilm_struct *ilm_ptr);
extern void cam_barcode_stop_capture_req_hdlr(ilm_struct *ilm_ptr);
extern void cam_barcode_capture_req_hdlr(ilm_struct *ilm_ptr);
extern void cam_barcode_capture_and_decode(void *args);
extern void cam_barcode_callback(kal_uint8 cause);
#endif
#endif /* defined (ISP_SUPPORT) */ 

extern void cam_start_fast_zoom_req_hdlr(ilm_struct *ilm_ptr);
extern void cam_stop_fast_zoom_req_hdlr(ilm_struct *ilm_ptr);
extern void cam_get_fast_zoom_factor_req_hdlr(ilm_struct *ilm_ptr);

extern void cam_get_focus_steps_req_hdlr(ilm_struct *ilm_ptr);

extern void cam_preview_restart(void);

extern kal_int16 cam_set_zoom_factor(kal_int16 value);
extern kal_int16 cam_set_contrast(kal_int16 value);
extern kal_int16 cam_set_brigntness(kal_int16 value);
extern kal_int16 cam_set_hue(kal_int16 value);
extern kal_int16 cam_set_gamma(kal_int16 value);
extern kal_int16 cam_set_wb(kal_int16 value);
extern kal_int16 cam_set_exposure(kal_int16 value);
extern kal_int16 cam_set_effect(kal_int16 value);
extern kal_int16 cam_set_night_mode(kal_int16 value);

/* ilm */
extern void cam_send_xenon_flash_status_ind(kal_uint16 seq_num);

extern void cam_send_power_up_req(module_type src_mod_id, kal_uint16 seq_num);
extern void cam_send_power_down_req(module_type src_mod_id, kal_int16 delay_time);
extern void cam_send_preview_req(module_type src_mod_id, void *data);
extern void cam_send_capture_req(module_type src_mod_id, void *data);
extern void cam_send_stop_req(module_type src_mod_id);
extern void cam_send_set_param_req(module_type src_mod_id, kal_uint16 param_id, kal_int16 value);
extern void cam_send_set_flash_req(module_type src_mod_id, kal_int16 flash_mode);
extern void cam_send_ready_ind(kal_int16 result);
extern void cam_send_preview_fail_ind(kal_int16 result);
extern void cam_send_event_ind(kal_uint8 event, kal_uint8 cause);
extern void cam_send_capture_event_ind(kal_int16 result, kal_uint16 count);
extern void cam_send_autofocus_process_done_ind(kal_uint8 event, kal_uint8 result);
extern void cam_send_cal_mwb_req(module_type src_mod_id, void *pmwb, kal_uint8 op_type);
extern void cam_send_start_fast_zoom_req(
                module_type src_mod_id,
                kal_bool zoom_in,
                kal_uint8 zoom_limit,
                kal_uint8 zoom_step,
                kal_uint8 zoom_speed);
extern void cam_send_stop_fast_zoom_req(module_type src_mod_id);
extern void cam_send_get_fast_zoom_factor_req(module_type src_mod_id, kal_uint8 *factor);
extern void cam_send_get_focus_steps_req(
                module_type src_mod_id,
                kal_uint32 *total_steps,
                kal_uint32 *current_steps,
                kal_bool *flag);
extern void cam_send_mwb_operation_req(module_type src_mod_id, kal_uint8 op_type);
extern void cam_send_set_overlay_palette_req(module_type src_mod_id, kal_uint8 palette_size, kal_uint32 *palette_addr);
#if defined (BARCODE_SUPPORT)
extern void cam_send_barcode_preview_req(module_type src_mod_id, void *data);
extern void cam_send_barcode_stop_req(module_type src_mod_id);

extern void cam_send_barcode_capture_req(module_type src_mod_id, void *data);
extern void cam_send_barcode_stop_capture_req(module_type src_mod_id);
extern void cam_send_barcode_decode_done_ind(media_cam_barcode_event_ind_struct *ind);
#endif
/* api */
extern void cam_set_result(kal_int32 result);

#endif /* _CAM_MAIN_H */ 

#endif /* __MED_CAM_MOD__ */ 

#endif /* MED_NOT_PRESENT */ 

