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
 * webcam_ilm.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes send-ilm related funcions of webcam module.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef MED_NOT_PRESENT

/*==== INCLUDES ===========*/

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
#include "fat_fs.h"
#include "nvram_enums.h"
#include "nvram_struct.h"
#include "nvram_user_defs.h"
#include "nvram_data_items.h"
#include "custom_nvram_editor_data_item.h"

/* local includes */
#include "med_global.h"
#include "aud_defs.h"
#include "med_struct.h"
#include "med_api.h"
#include "med_context.h"

#ifdef __MED_WEBCAM_MOD__
#include "usbvideo_if.h"
#include "webcam_main.h"
#include "usbvideo_cam_if.h"


/*****************************************************************************
 * FUNCTION
 *  webcam_send_start_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  data            [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void webcam_send_start_req(module_type src_mod_id, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_webcam_start_req_struct *msg_p = NULL;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_webcam_start_req_struct*) construct_local_para(sizeof(media_webcam_start_req_struct), TD_CTRL);

    memcpy(
        ((kal_uint8*) msg_p) + sizeof(local_para_struct),
        ((kal_uint8*) data) + sizeof(local_para_struct),
        sizeof(media_webcam_start_req_struct) - sizeof(local_para_struct));

    ilm_ptr = allocate_ilm(src_mod_id);
    ilm_ptr->src_mod_id = src_mod_id;
    ilm_ptr->dest_mod_id = MOD_MED;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_WEBCAM_START_REQ;
    ilm_ptr->local_para_ptr = (local_para_struct*) msg_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

}


/*****************************************************************************
 * FUNCTION
 *  webcam_send_stop_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void webcam_send_stop_req(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_webcam_stop_req_struct *msg_p = NULL;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_webcam_stop_req_struct*) construct_local_para(sizeof(media_webcam_stop_req_struct), TD_CTRL);

    ilm_ptr = allocate_ilm(src_mod_id);
    ilm_ptr->src_mod_id = src_mod_id;
    ilm_ptr->dest_mod_id = MOD_MED;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_WEBCAM_STOP_REQ;
    ilm_ptr->local_para_ptr = (local_para_struct*) msg_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

}


/*****************************************************************************
 * FUNCTION
 *  webcam_send_pause_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  data            [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void webcam_send_pause_req(module_type src_mod_id, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_webcam_pause_req_struct *msg_p = NULL;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_webcam_pause_req_struct*) construct_local_para(sizeof(media_webcam_pause_req_struct), TD_CTRL);

    memcpy(
        ((kal_uint8*) msg_p) + sizeof(local_para_struct),
        ((kal_uint8*) data) + sizeof(local_para_struct),
        sizeof(media_webcam_pause_req_struct) - sizeof(local_para_struct));

    ilm_ptr = allocate_ilm(src_mod_id);
    ilm_ptr->src_mod_id = src_mod_id;
    ilm_ptr->dest_mod_id = MOD_MED;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_WEBCAM_PAUSE_REQ;
    ilm_ptr->local_para_ptr = (local_para_struct*) msg_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

}


/*****************************************************************************
 * FUNCTION
 *  webcam_send_resume_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  data            [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void webcam_send_resume_req(module_type src_mod_id, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_webcam_resume_req_struct *msg_p = NULL;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_webcam_resume_req_struct*) construct_local_para(sizeof(media_webcam_resume_req_struct), TD_CTRL);

    memcpy(
        ((kal_uint8*) msg_p) + sizeof(local_para_struct),
        ((kal_uint8*) data) + sizeof(local_para_struct),
        sizeof(media_webcam_resume_req_struct) - sizeof(local_para_struct));

    ilm_ptr = allocate_ilm(src_mod_id);
    ilm_ptr->src_mod_id = src_mod_id;
    ilm_ptr->dest_mod_id = MOD_MED;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_WEBCAM_RESUME_REQ;
    ilm_ptr->local_para_ptr = (local_para_struct*) msg_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

}


/*****************************************************************************
 * FUNCTION
 *  webcam_send_capture_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void webcam_send_capture_req(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_webcam_capture_req_struct *msg_p = NULL;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_webcam_capture_req_struct*) construct_local_para(sizeof(media_webcam_capture_req_struct), TD_CTRL);

    ilm_ptr = allocate_ilm(src_mod_id);
    ilm_ptr->src_mod_id = src_mod_id;
    ilm_ptr->dest_mod_id = MOD_MED;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_WEBCAM_CAPTURE_REQ;
    ilm_ptr->local_para_ptr = (local_para_struct*) msg_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

}


/*****************************************************************************
 * FUNCTION
 *  webcam_send_rotate_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  data            [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void webcam_send_rotate_req(module_type src_mod_id, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_webcam_rotate_req_struct *msg_p = NULL;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_webcam_rotate_req_struct*) construct_local_para(sizeof(media_webcam_rotate_req_struct), TD_CTRL);

    memcpy(
        ((kal_uint8*) msg_p) + sizeof(local_para_struct),
        ((kal_uint8*) data) + sizeof(local_para_struct),
        sizeof(media_webcam_rotate_req_struct) - sizeof(local_para_struct));

    ilm_ptr = allocate_ilm(src_mod_id);
    ilm_ptr->src_mod_id = src_mod_id;
    ilm_ptr->dest_mod_id = MOD_MED;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_WEBCAM_ROTATE_REQ;
    ilm_ptr->local_para_ptr = (local_para_struct*) msg_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

}


/*****************************************************************************
 * FUNCTION
 *  webcam_send_start_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void webcam_send_start_cnf(kal_int16 result, kal_bool camera_workable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_webcam_start_cnf_struct *msg_p = NULL;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_webcam_start_cnf_struct*) construct_local_para(sizeof(media_webcam_start_cnf_struct), TD_CTRL);

    msg_p->result = result;
    msg_p->seq_num = webcam_context_p->seq_num;
    msg_p->camera_workable = camera_workable;

    ilm_ptr = allocate_ilm(MOD_MED);
    ilm_ptr->src_mod_id = MOD_MED;
    ilm_ptr->dest_mod_id = webcam_context_p->src_mod;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_WEBCAM_START_CNF;
    ilm_ptr->local_para_ptr = (local_para_struct*) msg_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

}


/*****************************************************************************
 * FUNCTION
 *  webcam_send_abort_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void webcam_send_abort_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_webcam_abort_ind_struct *msg_p = NULL;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_webcam_abort_ind_struct*) construct_local_para(sizeof(media_webcam_abort_ind_struct), TD_CTRL);

    msg_p->seq_num = webcam_context_p->seq_num;

    ilm_ptr = allocate_ilm(MOD_MED);
    ilm_ptr->src_mod_id = MOD_MED;
    ilm_ptr->dest_mod_id = webcam_context_p->src_mod;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_WEBCAM_ABORT_IND;
    ilm_ptr->local_para_ptr = (local_para_struct*) msg_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

}

/* message to USB */


/*****************************************************************************
 * FUNCTION
 *  webcam_send_usb_start_video_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void webcam_send_usb_start_video_req(void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    usbvideo_video_req_struct *msg_p;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* send indication message to L4 */
    msg_p = (usbvideo_video_req_struct*) construct_local_para(sizeof(usbvideo_video_req_struct), TD_CTRL);

    memcpy(
        ((kal_uint8*) msg_p) + sizeof(local_para_struct),
        ((kal_uint8*) data) + sizeof(local_para_struct),
        sizeof(usbvideo_video_req_struct) - sizeof(local_para_struct));

    ilm_ptr = allocate_ilm(MOD_MED);
    ilm_ptr->src_mod_id = MOD_MED;
    ilm_ptr->dest_mod_id = MOD_USB;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MED_USB_START_VIDEO_REQ;
    ilm_ptr->local_para_ptr = (local_para_struct*) msg_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  webcam_send_usb_stop_video_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void webcam_send_usb_stop_video_req(void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm_ptr = allocate_ilm(MOD_MED);
    ilm_ptr->src_mod_id = MOD_MED;
    ilm_ptr->dest_mod_id = MOD_USB;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MED_USB_STOP_REQ;
    ilm_ptr->local_para_ptr = (local_para_struct*) NULL;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  webcam_send_usb_pause_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void webcam_send_usb_pause_req(void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    usbvideo_default_JPEG_struct *msg_p;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* send indication message to L4 */
    msg_p = (usbvideo_default_JPEG_struct*) construct_local_para(sizeof(usbvideo_default_JPEG_struct), TD_CTRL);

    memcpy(
        ((kal_uint8*) msg_p) + sizeof(local_para_struct),
        ((kal_uint8*) data) + sizeof(local_para_struct),
        sizeof(usbvideo_default_JPEG_struct) - sizeof(local_para_struct));

    ilm_ptr = allocate_ilm(MOD_MED);
    ilm_ptr->src_mod_id = MOD_MED;
    ilm_ptr->dest_mod_id = MOD_USB;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MED_USB_PAUSE_REQ;
    ilm_ptr->local_para_ptr = (local_para_struct*) msg_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  webcam_send_usb_resume_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void webcam_send_usb_resume_req(void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    usbvideo_video_req_struct *msg_p;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* send indication message to L4 */
    msg_p = (usbvideo_video_req_struct*) construct_local_para(sizeof(usbvideo_video_req_struct), TD_CTRL);

    memcpy(
        ((kal_uint8*) msg_p) + sizeof(local_para_struct),
        ((kal_uint8*) data) + sizeof(local_para_struct),
        sizeof(usbvideo_video_req_struct) - sizeof(local_para_struct));

    ilm_ptr = allocate_ilm(MOD_MED);
    ilm_ptr->src_mod_id = MOD_MED;
    ilm_ptr->dest_mod_id = MOD_USB;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MED_USB_RESUME_VIDEO_REQ;
    ilm_ptr->local_para_ptr = (local_para_struct*) msg_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  webcam_send_usb_still_capture_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void webcam_send_usb_still_capture_req(void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm_ptr = allocate_ilm(MOD_MED);
    ilm_ptr->src_mod_id = MOD_MED;
    ilm_ptr->dest_mod_id = MOD_USB;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MED_USB_DEVICE_STILL_REQ;
    ilm_ptr->local_para_ptr = (local_para_struct*) NULL;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  webcam_send_usb_set_camera_attr_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void webcam_send_usb_set_camera_attr_cnf(void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    usbvideo_attr_msg_struct *msg_p;
    usbvideo_attr_msg_struct *data_p;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (usbvideo_attr_msg_struct*) construct_local_para(sizeof(usbvideo_attr_msg_struct), TD_CTRL);

    data_p = (usbvideo_attr_msg_struct*) data;

    msg_p->attr_value = data_p->attr_value;

    ilm_ptr = allocate_ilm(MOD_MED);
    ilm_ptr->src_mod_id = MOD_MED;
    ilm_ptr->dest_mod_id = MOD_USB;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_USB_MED_SET_CAMERA_ATTR_CNF;
    ilm_ptr->local_para_ptr = (local_para_struct*) msg_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  webcam_send_encode_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  return_code        [IN]     return code
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __SW_JPEG_CODEC_SUPPORT__ 
void webcam_send_encode_request(kal_uint8 return_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_webcam_encode_req_struct *msg_p;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_webcam_encode_req_struct*)construct_local_para(sizeof(media_webcam_encode_req_struct), TD_CTRL);

    ilm_ptr = allocate_ilm(MOD_VISUAL_HISR);
    ilm_ptr->src_mod_id = MOD_VISUAL_HISR;
    ilm_ptr->dest_mod_id = MOD_MED;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_WEBCAM_ENCODE_REQ;
    ilm_ptr->local_para_ptr = (local_para_struct*)msg_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);
}
#endif /* __SW_JPEG_CODEC_SUPPORT__ */

#endif /* __MED_WEBCAM_MOD__ */ 

#endif /* MED_NOT_PRESENT */ 

