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
 *   cam_main.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes primary functions of camera module.
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
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
#if defined (ISP_SUPPORT)
#include "ae_awb.h"
#endif
/* local includes */
#include "med_global.h"
#include "med_main.h"
#include "aud_defs.h"
#include "med_struct.h"
#include "med_api.h"
#include "med_context.h"
#include "cam_main.h"

#ifdef __CAM_TRACE_ON__
#include "med_trc.h"
#endif

#ifdef __MED_CAM_MOD__

cam_context_struct *cam_context_p = &(med_context.cam_context);

/*==== FUNCTIONS ===========*/


/*****************************************************************************
 * FUNCTION
 *  cam_startup_hdlr
 * DESCRIPTION
 *  This function is handle startup procedure of camera module.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void cam_startup_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_context_p->src_mod = ilm_ptr->src_mod_id;
}


/*****************************************************************************
 * FUNCTION
 *  cam_main
 * DESCRIPTION
 *  This function is main message dispatching function of camera module.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void cam_main(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (ilm_ptr->msg_id)
    {
        case MSG_ID_MEDIA_CAM_POWER_UP_REQ:
            cam_power_up_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_CAM_POWER_DOWN_REQ:
            cam_power_down_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_CAM_PREVIEW_REQ:
            cam_preview_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_CAM_STOP_REQ:
            cam_stop_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_CAM_CAPTURE_REQ:
            cam_capture_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_CAM_SET_PARAM_REQ:
            cam_set_param_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_CAM_SET_FLASH_REQ:
            cam_set_flash_req_hdlr(ilm_ptr);
            break;
    #if defined (ISP_SUPPORT)
    #if defined (BARCODE_SUPPORT)
        case MSG_ID_MEDIA_CAM_BARCODE_PREVIEW_REQ:
            cam_barcode_preview_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_CAM_BARCODE_STOP_REQ:
            cam_barcode_stop_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_CAM_BARCODE_CAPTURE_REQ:
            cam_barcode_capture_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_CAM_BARCODE_STOP_CAPTURE_REQ:
            cam_barcode_stop_capture_req_hdlr(ilm_ptr);
            break;
    #endif
        case MSG_ID_MEDIA_CAM_EVENT_IND:
            cam_event_ind_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_CAM_START_FAST_ZOOM_REQ:
            cam_start_fast_zoom_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_CAM_STOP_FAST_ZOOM_REQ:
            cam_stop_fast_zoom_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_CAM_GET_FAST_ZOOM_FACTOR_REQ:
            cam_get_fast_zoom_factor_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_CAM_GET_FOCUS_STEPS_REQ:
            cam_get_focus_steps_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_CAM_CAL_MANUAL_WB_REQ:
            cam_mwb_op_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_CAM_MWB_OPERATION_REQ:
            cam_mwb_op_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_CAM_SET_OVERLAY_PALETTE_REQ:
            cam_set_overlay_palette_req_hdlr(ilm_ptr);
            break;
    #endif /* defined (ISP_SUPPORT) */ 

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  cam_init
 * DESCRIPTION
 *  This function is used to init camera module of media task.
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
kal_bool cam_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_context_p->state = CAM_IDLE;
    cam_context_p->capture_buffer_p = 0;
    cam_context_p->cam_event = kal_create_event_group("cam_events");

    cam_context_p->intmem_start_address = 0;
    cam_context_p->extmem_start_address = 0;
    cam_context_p->int_frame_buffer_p = 0;
    cam_context_p->ext_frame_buffer_p = 0;
    return KAL_TRUE;
}

#endif /* __MED_CAM_MOD__ */
#endif /* MED_NOT_PRESENT */

