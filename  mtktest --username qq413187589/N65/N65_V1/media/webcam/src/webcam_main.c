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
 *   webcam_main.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes primary functions of webcam module.
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
#include "med_utility.h"
#include "img_main.h"

#ifdef __WEBCAM_TRACE_ON__
#include "med_trc.h"
#endif 

#ifdef __MED_WEBCAM_MOD__
#include "webcam_main.h"

webcam_context_struct *webcam_context_p = &(med_context.webcam_context);

/*==== FUNCTIONS ===========*/


/*****************************************************************************
 * FUNCTION
 *  webcam_startup_hdlr
 * DESCRIPTION
 *  This function is handle startup procedure of webcam module.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void webcam_startup_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    webcam_context_p->src_mod = ilm_ptr->src_mod_id;

}


/*****************************************************************************
 * FUNCTION
 *  webcam_main
 * DESCRIPTION
 *  This function is main message dispatching function of webcam module.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void webcam_main(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (ilm_ptr->msg_id)
    {
        case MSG_ID_MEDIA_WEBCAM_START_REQ:
            webcam_start_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_WEBCAM_STOP_REQ:
            webcam_stop_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_WEBCAM_PAUSE_REQ:
            webcam_pause_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_WEBCAM_RESUME_REQ:
            webcam_resume_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_WEBCAM_CAPTURE_REQ:
            webcam_capture_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_WEBCAM_ROTATE_REQ:
            webcam_rotate_req_hdlr(ilm_ptr);
            break;

        case MSG_ID_MEDIA_WEBCAM_ENCODE_REQ:
        #ifdef __SW_JPEG_CODEC_SUPPORT__                     
            webcam_encode_req_hdlr(ilm_ptr);
        #endif 
            break;
            
        case MSG_ID_USB_MED_SET_CAMERA_ATTR_REQ:
            webcam_set_camera_attr_req_hdlr(ilm_ptr);
            break;

        case MSG_ID_USB_MED_START_VIDEO_CNF:
            webcam_start_cnf_hdlr(ilm_ptr);
            break;
        case MSG_ID_USB_MED_STOP_CNF:
            webcam_stop_cnf_hdlr(ilm_ptr);
            break;
        case MSG_ID_USB_MED_PAUSE_CNF:
            webcam_pause_cnf_hdlr(ilm_ptr);
            break;
        case MSG_ID_USB_MED_RESUME_VIDEO_CNF:
            webcam_resume_cnf_hdlr(ilm_ptr);
            break;
        case MSG_ID_USB_MED_DEVICE_STILL_CNF:
            webcam_capture_cnf_hdlr(ilm_ptr);
            break;
        case MSG_ID_USB_MED_START_STILL_IND:
            webcam_start_still_ind_hdlr(ilm_ptr);
            break;
        case MSG_ID_USB_MED_START_VIDEO_IND:
            webcam_start_video_ind_hdlr(ilm_ptr);
            break;
        case MSG_ID_USB_MED_CHANGE_VIDEO_IND:
            webcam_change_video_ind_hdlr(ilm_ptr);
            break;
        case MSG_ID_USB_MED_ABORT_IND:
            webcam_drv_abort_ind_hdlr(ilm_ptr);
            break;

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  webcam_init
 * DESCRIPTION
 *  This function is used to init tv output module of media task.
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool webcam_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    webcam_context_p->state = WEBCAM_IDLE;
    webcam_context_p->intmem_start_address = 0;
    webcam_context_p->intmem_size = 0;
    webcam_context_p->buffer_addr = 0;
    webcam_context_p->buffer_size = 0;

    webcam_context_p->webcam_event = kal_create_event_group("webcam_events");

    return KAL_TRUE;
}

#endif /* __MED_WEBCAM_MOD__ */ 
#endif /* MED_NOT_PRESENT */ 

