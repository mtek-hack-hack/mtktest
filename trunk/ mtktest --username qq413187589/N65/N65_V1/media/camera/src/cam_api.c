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
 *   cam_api.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes primary exported functions of image module.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef MED_NOT_PRESENT

/*==== INCLUDES =========*/

/* system includes */
#include "kal_release.h"
#include "kal_trace.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */
#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "app_buff_alloc.h"     /* Declaration of buffer management API */
#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h" /* Event scheduler */
#include "stack_timer.h"        /* Stack timer */

/* global includes */
#include "l1audio.h"
#include "device.h"
#include "resource_audio.h"
#include "nvram_enums.h"
#include "nvram_struct.h"
#include "nvram_user_defs.h"
#include "nvram_data_items.h"
#include "custom_nvram_editor_data_item.h"

/* local includes */
#include "med_global.h"
#include "med_main.h"
#include "aud_defs.h"
#include "med_struct.h"
#include "med_api.h"
#include "med_context.h"
#include "med_api.h"
#include "cam_main.h"

#ifdef __CAM_TRACE_ON__
#include "med_trc.h"
#endif 

#ifdef __MED_CAM_MOD__

static kal_int32 cam_result;

/*==== FUNCTIONS ===========*/


/*****************************************************************************
 * FUNCTION
 *  cam_set_result
 * DESCRIPTION
 *  This function is to set return result.
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void cam_set_result(kal_int32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CAM_RESULT_TRACE(result, cam_context_p->state, cam_context_p->seq_num) cam_result = result;
}


/*****************************************************************************
 * FUNCTION
 *  media_cam_power_up
 * DESCRIPTION
 *  This function is to power on camera.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  seq_num         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_cam_power_up(module_type src_mod_id, kal_uint16 seq_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_send_power_up_req(src_mod_id, seq_num);
    CAM_WAIT_EVENT(CAM_EVT_POWER_UP);
    return MED_RES_OK;
}


/*****************************************************************************
 * FUNCTION
 *  media_cam_power_down
 * DESCRIPTION
 *  This function is to power down camera.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  delay_time      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_cam_power_down(module_type src_mod_id, kal_int16 delay_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_send_power_down_req(src_mod_id, delay_time);
    return MED_RES_OK;
}


/*****************************************************************************
 * FUNCTION
 *  media_cam_preview
 * DESCRIPTION
 *  This function is to start camera preview.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  preview         [?]         
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_cam_preview(module_type src_mod_id, void *preview)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_result = MED_RES_OK;
    cam_send_preview_req(src_mod_id, preview);
    CAM_WAIT_EVENT(CAM_EVT_PREVIEW);
    return cam_result;
}

#if defined (BARCODE_SUPPORT)
/*****************************************************************************
 * FUNCTION
 *  media_cam_barcode_preview
 * DESCRIPTION
 *  This function is to start camera preview.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  preview         [?]         
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_cam_barcode_preview(module_type src_mod_id, void *preview)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_result = MED_RES_OK;
    cam_send_barcode_preview_req(src_mod_id, preview);
    CAM_WAIT_EVENT(CAM_EVT_PREVIEW);
    return cam_result;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  media_cam_stop
 * DESCRIPTION
 *  This function is to stop camera preview.
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void media_cam_stop(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_send_stop_req(src_mod_id);
    CAM_WAIT_EVENT(CAM_EVT_STOP);
}

#if defined (BARCODE_SUPPORT)
/*****************************************************************************
 * FUNCTION
 *  media_cam_barcode_stop
 * DESCRIPTION
 *  This function is to stop camera preview.
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void media_cam_barcode_stop(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_send_barcode_stop_req(src_mod_id);
    CAM_WAIT_EVENT(CAM_EVT_STOP);
}


/*****************************************************************************
 * FUNCTION
 *  media_cam_barcode_start_capture_end_decode
 * DESCRIPTION
 *  This function is to start barcode capture and decode
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  capture         [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void media_cam_barcode_start_capture_end_decode(module_type src_mod_id, void *capture)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_send_barcode_capture_req(src_mod_id, capture);
    CAM_WAIT_EVENT(CAM_EVT_CAPTURE_BARCODE);

}


/*****************************************************************************
 * FUNCTION
 *  media_cam_barcode_stop_capture_and_decode
 * DESCRIPTION
 *  This function is to stop barcode capture and decode.
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void media_cam_barcode_stop_capture_and_decode(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_send_barcode_stop_capture_req(src_mod_id);
    CAM_WAIT_EVENT(CAM_EVT_STOP_CAPTURE_BARCODE);
}
#endif

/*****************************************************************************
 * FUNCTION
 *  media_cam_capture
 * DESCRIPTION
 *  This function is to capture the image.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  capture         [?]         
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_cam_capture(module_type src_mod_id, void *capture)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_result = MED_RES_OK;
    cam_send_capture_req(src_mod_id, capture);
    CAM_WAIT_EVENT(CAM_EVT_CAPTURE);
    return cam_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_cam_set_param
 * DESCRIPTION
 *  This function is to set the parameter of camera.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  param_id        [IN]        
 *  value           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void media_cam_set_param(module_type src_mod_id, kal_uint16 param_id, kal_int16 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_send_set_param_req(src_mod_id, param_id, value);
    CAM_WAIT_EVENT(CAM_EVT_SET_PARAM);
}


/*****************************************************************************
 * FUNCTION
 *  media_cam_set_flash
 * DESCRIPTION
 *  This function is to set the flash for camera.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  flash_mode      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void media_cam_set_flash(module_type src_mod_id, kal_int16 flash_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_send_set_flash_req(src_mod_id, flash_mode);
}


/*****************************************************************************
 * FUNCTION
 *  media_cam_set_af
 * DESCRIPTION
 *  This function is to set the parameter of AF.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  param_id        [IN]        
 *  value           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void media_cam_set_af(module_type src_mod_id, kal_uint16 param_id, kal_int16 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_send_set_param_req(src_mod_id, param_id, value);
}


/*****************************************************************************
 * FUNCTION
 *  media_cam_cal_mwb
 * DESCRIPTION
 *  This function is to calculate the mwb.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  pmwb            [?]         
 *  op_type         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void media_cam_cal_mwb(module_type src_mod_id, cam_mwb_process_struct *pmwb, kal_uint8 op_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_send_cal_mwb_req(src_mod_id, pmwb, op_type);
    CAM_WAIT_EVENT(CAM_EVT_MWB_OP);
}


/*****************************************************************************
 * FUNCTION
 *  media_cam_mwb_operation
 * DESCRIPTION
 *  *
 *  This function is to do mwb relate operation
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  op_type         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void media_cam_mwb_operation(module_type src_mod_id, kal_uint8 op_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_send_mwb_operation_req(src_mod_id, op_type);
    CAM_WAIT_EVENT(CAM_EVT_MWB_OP);
}


/*****************************************************************************
 * FUNCTION
 *  media_cam_set_overlay_palette
 * DESCRIPTION
 *  This function is to set the overlay palette for camera.
 * PARAMETERS
 *  src_mod_id              [IN]        
 *  palette_size            [IN]        
 *  palette_addr_ptr        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void media_cam_set_overlay_palette(module_type src_mod_id, kal_uint8 palette_size, kal_uint32 *palette_addr_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_send_set_overlay_palette_req(src_mod_id, palette_size, palette_addr_ptr);
    CAM_WAIT_EVENT(CAM_EVT_SET_PAL);
}


/*****************************************************************************
 * FUNCTION
 *  media_cam_start_fast_zoom
 * DESCRIPTION
 *  This function is to start fast zoom for camera.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  zoom_in         [IN]        
 *  zoom_limit      [IN]        
 *  zoom_step       [IN]        
 *  zoom_speed      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void media_cam_start_fast_zoom(
        module_type src_mod_id,
        kal_bool zoom_in,
        kal_uint8 zoom_limit,
        kal_uint8 zoom_step,
        kal_uint8 zoom_speed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_send_start_fast_zoom_req(src_mod_id, zoom_in, zoom_limit, zoom_step, zoom_speed);
}


/*****************************************************************************
 * FUNCTION
 *  media_cam_stop_fast_zoom
 * DESCRIPTION
 *  This function is to stop fast zoom for camera.
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void media_cam_stop_fast_zoom(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_send_stop_fast_zoom_req(src_mod_id);
    CAM_WAIT_EVENT(CAM_EVT_STOP_FAST_ZOOM);
}


/*****************************************************************************
 * FUNCTION
 *  media_cam_get_fast_zoom_factor
 * DESCRIPTION
 *  This function is to get the fast zoom factor for camera.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  factor          [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void media_cam_get_fast_zoom_factor(module_type src_mod_id, kal_uint8 *factor)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_send_get_fast_zoom_factor_req(src_mod_id, factor);
    CAM_WAIT_EVENT(CAM_EVT_GET_FAST_ZOOM_FACTOR);
}


/*****************************************************************************
 * FUNCTION
 *  media_cam_get_focus_steps
 * DESCRIPTION
 *  This function is to get the focus steps for camera.
 * PARAMETERS
 *  src_mod_id          [IN]        
 *  total_steps         [?]         
 *  current_steps       [?]         
 *  flag                [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void media_cam_get_focus_steps(
        module_type src_mod_id,
        kal_uint32 *total_steps,
        kal_uint32 *current_steps,
        kal_bool *flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_send_get_focus_steps_req(src_mod_id, total_steps, current_steps, flag);
    CAM_WAIT_EVENT(CAM_EVT_GET_FOCUS_STEPS);
}


/*****************************************************************************
 * FUNCTION
 *  media_cam_flash_setting
 * DESCRIPTION
 *  This function is to set ledlight on/off
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  flag            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void media_cam_flash_setting(module_type src_mod_id, kal_bool flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef ISP_SUPPORT
    isp_led_setting(flag);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  media_cam_get_max_zoom_factor
 * DESCRIPTION
 *  This function is to get the max zoom factor
 * PARAMETERS
 *  target_width        [IN]        
 *  target_height       [IN]        
 *  kal_uint16 image_width(?)
 *  kal_uint16 image_height(?)
 * RETURNS
 *  kal_uint8 max_zoom_factor
 *****************************************************************************/
kal_uint8 media_cam_get_max_zoom_factor(kal_uint16 target_width, kal_uint16 target_height)
{
#ifdef ISP_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return get_max_digital_zoom_factor(target_width, target_height);
#else /* ISP_SUPPORT */ 
    return 0;
#endif /* ISP_SUPPORT */ 
}
#endif /* __MED_CAM_MOD__ */ 

#endif /* MED_NOT_PRESENT */ 

