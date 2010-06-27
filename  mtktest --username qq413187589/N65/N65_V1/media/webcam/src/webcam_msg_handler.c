/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2003
*
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *   webcam_msg_handler.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes message handle functions of webcam module.
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
#include "med_smalloc.h"
#include "fat_fs.h"

#ifdef __WEBCAM_TRACE_ON__
#include "med_trc.h"
#endif 

#ifdef __MED_WEBCAM_MOD__
#include "cam_main.h"
#include "usbvideo_if.h"
#include "webcam_main.h"
#include "usbvideo_cam_if.h"

#define WEBCAM_FREE_INT_MEM()                                               \
do {                                                                        \
    if (webcam_context_p->intmem_start_address)                             \
    {                                                                       \
        med_free_int_mem((void**)&webcam_context_p->intmem_start_address);  \
        webcam_context_p->intmem_start_address = NULL;                      \
    }                                                                       \
} while(0);


#define WEBCAM_FREE_USB_BUFFER()                                    \
do {                                                                \
    if (webcam_context_p->buffer_addr)                              \
    {                                                               \
        med_free_ext_mem((void**)&webcam_context_p->buffer_addr);   \
        webcam_context_p->buffer_addr = NULL;                       \
    }                                                               \
} while(0);


#define WEBCAM_FREE_JPG_YUV_BUFFER()                                \
do {                                                                \
    if (webcam_context_p->jpeg_y_buf_p)                             \
    {                                                               \
        med_free_ext_mem((void**)&webcam_context_p->jpeg_y_buf_p);  \
        webcam_context_p->jpeg_y_buf_p = NULL;                      \
    }                                                               \
    if (webcam_context_p->jpeg_u_buf_p)                             \
    {                                                               \
        med_free_ext_mem((void**)&webcam_context_p->jpeg_u_buf_p);  \
        webcam_context_p->jpeg_u_buf_p = NULL;                      \
    }                                                               \
    if (webcam_context_p->jpeg_v_buf_p)                             \
    {                                                               \
        med_free_ext_mem((void**)&webcam_context_p->jpeg_v_buf_p);  \
        webcam_context_p->jpeg_v_buf_p = NULL;                      \
    }                                                               \
} while(0);


#if MT6219_SERIES
kal_int32 webcam_preview_mem[2] = {51200, 0};
kal_int32 webcam_capture_mem[2] = {122880, 0};
#else /* MT6219_SERIES */ 
#ifdef MT6225
kal_int32 webcam_preview_mem[2] = {45056, 0};
kal_int32 webcam_capture_mem[2] = {45056, 0};
#else /* MT6225 */
kal_int32 webcam_preview_mem[2] = {45056, 0};
kal_int32 webcam_capture_mem[2] = {104448, 0};
#endif /* MT6225 */
#endif /* MT6219_SERIES */ 

extern kal_uint8 cam_rotate_map[CAM_NO_OF_IMAGE_ROTATE];

usbvideo_camera_process_struct usbvideo_param;

/*==== FUNCTIONS ===========*/


/*****************************************************************************
 * FUNCTION
 *  webcam_start_req_hdlr
 * DESCRIPTION
 *  This function is to start webcam preview and transmit the image to USB.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void webcam_start_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_webcam_start_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_webcam_start_req_struct*) ilm_ptr->local_para_ptr;

    webcam_context_p->src_mod = ilm_ptr->src_mod_id;
    webcam_context_p->seq_num = req_p->seq_num;

    if (WEBCAM_IN_STATE(WEBCAM_IDLE))
    {
        usbvideo_video_req_struct start;
        webcam_context_p->banding = req_p->banding;
        webcam_context_p->image_mirror = cam_rotate_map[req_p->rotate];
        webcam_context_p->buffer_size = MAX_WEBCAM_BUFFER_SIZE;
        webcam_context_p->buffer_addr = (kal_uint8*) med_alloc_ext_mem(webcam_context_p->buffer_size);

    #ifdef __SW_JPEG_CODEC_SUPPORT__ 
        webcam_context_p->jpeg_y_buf_size = WEBCAM_JPEG_BUFFER_SIZE;        
        webcam_context_p->jpeg_y_buf_p = (kal_uint32)med_alloc_ext_mem(webcam_context_p->jpeg_y_buf_size);

        webcam_context_p->jpeg_u_buf_size = WEBCAM_JPEG_BUFFER_SIZE / 4;    
        webcam_context_p->jpeg_u_buf_p = (kal_uint32)med_alloc_ext_mem(webcam_context_p->jpeg_u_buf_size);

        webcam_context_p->jpeg_v_buf_size = WEBCAM_JPEG_BUFFER_SIZE / 4;            
        webcam_context_p->jpeg_v_buf_p = (kal_uint32)med_alloc_ext_mem(webcam_context_p->jpeg_v_buf_size);
    #endif /* __SW_JPEG_CODEC_SUPPORT__ */

        if (webcam_context_p->buffer_addr)
        {
            start.buffer_addr = webcam_context_p->buffer_addr;
            start.buffer_size = webcam_context_p->buffer_size;
            webcam_send_usb_start_video_req((void*)&start);
            WEBCAM_ENTER_STATE(WEBCAM_START_PREVIEW);
            webcam_set_result(MED_RES_OK);
            WEBCAM_SET_EVENT(WEBCAM_EVT_START);

        }
        else
        {
            /* insufficent memory */
            ASSERT(0);
            WEBCAM_SET_EVENT(WEBCAM_EVT_START);
        }

    }
    else
    {
        webcam_set_result(MED_RES_BUSY);
        WEBCAM_SET_EVENT(WEBCAM_EVT_START);
    }

}


/*****************************************************************************
 * FUNCTION
 *  webcam_start_cnf_hdlr
 * DESCRIPTION
 *  This function is to handle the video start confirm from USB task.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void webcam_start_cnf_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    usbvideo_video_size_struct *msg_p;
    kal_bool camera_result = KAL_TRUE; 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (usbvideo_video_size_struct*) ilm_ptr->local_para_ptr;

    if (WEBCAM_IN_STATE(WEBCAM_START_PREVIEW))
    {
        if (msg_p->result)
        {
            do {
                camera_result = usbvideo_camera_power_on();
                if(camera_result == KAL_FALSE)
                {
                    usbvideo_camera_power_off();
                    break;
                }
                webcam_context_p->intmem_start_address = (kal_uint32) med_alloc_int_mem(webcam_preview_mem[0]);
                webcam_context_p->intmem_size = (kal_uint32) webcam_preview_mem[0];

                usbvideo_param.banding_freq = webcam_context_p->banding;
                usbvideo_param.intmem_start_address = webcam_context_p->intmem_start_address;
                usbvideo_param.intmem_size = webcam_context_p->intmem_size;
                usbvideo_param.image_mirror = webcam_context_p->image_mirror;
                usbvideo_param.target_size_enum = msg_p->video_size_type;
                usbvideo_param.target_comp_enum = msg_p->video_compression_type;
                usbvideo_param.usbvideo_cam_preview_cb = cam_preview_callback;
            
        #ifdef __SW_JPEG_CODEC_SUPPORT__ 
                usbvideo_param.y_address = (kal_uint32)webcam_context_p->jpeg_y_buf_p;
                usbvideo_param.y_size = webcam_context_p->jpeg_y_buf_size;
                usbvideo_param.u_address = (kal_uint32)webcam_context_p->jpeg_u_buf_p;
                usbvideo_param.u_size = webcam_context_p->jpeg_u_buf_size;
                usbvideo_param.v_address = (kal_uint32)webcam_context_p->jpeg_v_buf_p;
                usbvideo_param.v_size = webcam_context_p->jpeg_v_buf_size;
                usbvideo_param.usbvideo_encode_cb = webcam_send_encode_request;
        #endif /* __SW_JPEG_CODEC_SUPPORT__ */
          
                camera_result = usbvideo_camera_preview(&usbvideo_param);
                if(camera_result == KAL_FALSE)
                {
                    exit_usbvideo_camera_preview();
                    usbvideo_camera_power_off();
                    break;
                }
                webcam_send_start_cnf(MED_RES_OK, camera_result);
                WEBCAM_ENTER_STATE(WEBCAM_PREVIEW);
           } while(0);
                
            if(camera_result == KAL_FALSE)
            {
                webcam_send_start_cnf(MED_RES_FAIL, camera_result);                
                WEBCAM_FREE_INT_MEM();                
                webcam_send_usb_stop_video_req(NULL);
                WEBCAM_ENTER_STATE(WEBCAM_STOPPING);              
            }
        }
        else
        {
            webcam_send_start_cnf(MED_RES_FAIL, camera_result);
            WEBCAM_FREE_USB_BUFFER();
        #ifdef __SW_JPEG_CODEC_SUPPORT__
            WEBCAM_FREE_JPG_YUV_BUFFER();
        #endif
            WEBCAM_ENTER_STATE(WEBCAM_IDLE);
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  webcam_stop_req_hdlr
 * DESCRIPTION
 *  This function is to stop tv output.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void webcam_stop_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_webcam_stop_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_webcam_stop_req_struct*) ilm_ptr->local_para_ptr;

    webcam_context_p->src_mod = ilm_ptr->src_mod_id;

    if (WEBCAM_IN_STATE(WEBCAM_START_PREVIEW))
    {
        webcam_send_usb_stop_video_req(NULL);
        WEBCAM_ENTER_STATE(WEBCAM_STOPPING);

    }
    else if (WEBCAM_IN_STATE(WEBCAM_PREVIEW))
    {
        exit_usbvideo_camera_preview();
        usbvideo_camera_power_off();
        WEBCAM_FREE_INT_MEM();
        webcam_send_usb_stop_video_req(NULL);
        WEBCAM_ENTER_STATE(WEBCAM_STOPPING);

    }
    else if (WEBCAM_IN_STATE(WEBCAM_CAPTURE))
    {
        exit_usbvideo_camera_capture();
        usbvideo_camera_power_off();
        WEBCAM_FREE_INT_MEM();
        webcam_send_usb_stop_video_req(NULL);
        WEBCAM_ENTER_STATE(WEBCAM_STOPPING);
    }
    else if (WEBCAM_IN_STATE(WEBCAM_PAUSED))
    {
        webcam_send_usb_stop_video_req(NULL);
        WEBCAM_ENTER_STATE(WEBCAM_STOPPING);
    }
    else
    {
        webcam_set_result(MED_RES_BUSY);
        WEBCAM_SET_EVENT(WEBCAM_EVT_STOP);
    }

}


/*****************************************************************************
 * FUNCTION
 *  webcam_stop_cnf_hdlr
 * DESCRIPTION
 *  This function is to handle the stop confirm from USB task.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void webcam_stop_cnf_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    usbvideo_result_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (usbvideo_result_struct*) ilm_ptr->local_para_ptr;

    if (WEBCAM_IN_STATE(WEBCAM_STOPPING))
    {
        if (msg_p->result)
        {
            webcam_set_result(MED_RES_OK);
        }
        else
        {
            ASSERT(msg_p->result);
        }
        WEBCAM_FREE_USB_BUFFER();
    #ifdef __SW_JPEG_CODEC_SUPPORT__
        WEBCAM_FREE_JPG_YUV_BUFFER();
    #endif
       
        WEBCAM_ENTER_STATE(WEBCAM_IDLE);
        WEBCAM_SET_EVENT(WEBCAM_EVT_STOP);

    }
}


/*****************************************************************************
 * FUNCTION
 *  webcam_pause_req_hdlr
 * DESCRIPTION
 *  This function is to pause webcam.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void webcam_pause_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_webcam_pause_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_webcam_pause_req_struct*) ilm_ptr->local_para_ptr;

    webcam_context_p->src_mod = ilm_ptr->src_mod_id;

    if (WEBCAM_IN_STATE(WEBCAM_START_PREVIEW))
    {
        webcam_send_usb_pause_req(req_p);
        WEBCAM_ENTER_STATE(WEBCAM_PAUSING);
    }
    else if (WEBCAM_IN_STATE(WEBCAM_PREVIEW))
    {
        exit_usbvideo_camera_preview();
        usbvideo_camera_power_off();
        WEBCAM_FREE_INT_MEM();
        webcam_send_usb_pause_req(req_p);
        WEBCAM_ENTER_STATE(WEBCAM_PAUSING);

    }
    else if (WEBCAM_IN_STATE(WEBCAM_CAPTURE))
    {
        exit_usbvideo_camera_capture();
        usbvideo_camera_power_off();
        WEBCAM_FREE_INT_MEM();
        webcam_send_usb_pause_req(req_p);
        WEBCAM_ENTER_STATE(WEBCAM_PAUSING);
    }
    else
    {
        webcam_set_result(MED_RES_BUSY);
        WEBCAM_SET_EVENT(WEBCAM_EVT_PAUSE);
    }

}


/*****************************************************************************
 * FUNCTION
 *  webcam_pause_cnf_hdlr
 * DESCRIPTION
 *  This function is to handle the pause confirm from USB task.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void webcam_pause_cnf_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    usbvideo_result_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (usbvideo_result_struct*) ilm_ptr->local_para_ptr;

    if (WEBCAM_IN_STATE(WEBCAM_PAUSING))
    {

        if (msg_p->result)
        {
            webcam_set_result(MED_RES_OK);
            WEBCAM_ENTER_STATE(WEBCAM_PAUSED);
        }
        else
        {
            webcam_set_result(MED_RES_FAIL);
            WEBCAM_ENTER_STATE(WEBCAM_IDLE);
        }
        WEBCAM_FREE_USB_BUFFER();
    #ifdef __SW_JPEG_CODEC_SUPPORT__
        WEBCAM_FREE_JPG_YUV_BUFFER();
    #endif
        
        WEBCAM_SET_EVENT(WEBCAM_EVT_PAUSE);

    }
}


/*****************************************************************************
 * FUNCTION
 *  webcam_resume_req_hdlr
 * DESCRIPTION
 *  This function is to resume webcam.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void webcam_resume_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_webcam_resume_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_webcam_resume_req_struct*) ilm_ptr->local_para_ptr;

    webcam_context_p->src_mod = ilm_ptr->src_mod_id;

    if (WEBCAM_IN_STATE(WEBCAM_PAUSED))
    {
        usbvideo_video_req_struct start;

        webcam_context_p->image_mirror = cam_rotate_map[req_p->rotate];
        webcam_context_p->buffer_size = MAX_WEBCAM_BUFFER_SIZE;
        webcam_context_p->buffer_addr = (kal_uint8*) med_alloc_ext_mem(webcam_context_p->buffer_size);

    #ifdef __SW_JPEG_CODEC_SUPPORT__
        webcam_context_p->jpeg_y_buf_size = WEBCAM_JPEG_BUFFER_SIZE;        
        webcam_context_p->jpeg_y_buf_p = (kal_uint32)med_alloc_ext_mem(webcam_context_p->jpeg_y_buf_size);

        webcam_context_p->jpeg_u_buf_size = WEBCAM_JPEG_BUFFER_SIZE / 4;    
        webcam_context_p->jpeg_u_buf_p = (kal_uint32)med_alloc_ext_mem(webcam_context_p->jpeg_u_buf_size);

        webcam_context_p->jpeg_v_buf_size = WEBCAM_JPEG_BUFFER_SIZE / 4;            
        webcam_context_p->jpeg_v_buf_p = (kal_uint32)med_alloc_ext_mem(webcam_context_p->jpeg_v_buf_size);
    #endif /* __SW_JPEG_CODEC_SUPPORT__ */
        
        if (webcam_context_p->buffer_addr)
        {
            start.buffer_addr = webcam_context_p->buffer_addr;
            start.buffer_size = webcam_context_p->buffer_size;
            webcam_send_usb_resume_req((void*)&start);
            WEBCAM_ENTER_STATE(WEBCAM_START_PREVIEW);
        }
        else
        {
            /* insufficient memory */
            ASSERT(0);
            WEBCAM_SET_EVENT(WEBCAM_EVT_RESUME);
        }

    }
    else
    {
        webcam_set_result(MED_RES_BUSY);
        WEBCAM_SET_EVENT(WEBCAM_EVT_RESUME);
    }

}


/*****************************************************************************
 * FUNCTION
 *  webcam_resume_cnf_hdlr
 * DESCRIPTION
 *  This function is to handle the video resume confirm from USB task.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void webcam_resume_cnf_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    usbvideo_video_size_struct *msg_p;
    kal_bool camera_result = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (usbvideo_video_size_struct*) ilm_ptr->local_para_ptr;

    if (WEBCAM_IN_STATE(WEBCAM_START_PREVIEW))
    {
        if (msg_p->result)
        {
            do {
                camera_result = usbvideo_camera_power_on();
                if(camera_result == KAL_FALSE)
                {
                    usbvideo_camera_power_off();                    
                    break;
                }
                webcam_context_p->intmem_start_address = (kal_uint32) med_alloc_int_mem(webcam_preview_mem[0]);
                webcam_context_p->intmem_size = (kal_uint32) webcam_preview_mem[0];

                usbvideo_param.banding_freq = webcam_context_p->banding;
                usbvideo_param.intmem_start_address = webcam_context_p->intmem_start_address;
                usbvideo_param.intmem_size = webcam_context_p->intmem_size;
                usbvideo_param.image_mirror = webcam_context_p->image_mirror;
                usbvideo_param.target_size_enum = msg_p->video_size_type;
                usbvideo_param.target_comp_enum = msg_p->video_compression_type;
                usbvideo_param.usbvideo_cam_preview_cb = cam_preview_callback;
            
        #ifdef __SW_JPEG_CODEC_SUPPORT__ 
                usbvideo_param.y_address = (kal_uint32)webcam_context_p->jpeg_y_buf_p;
                usbvideo_param.y_size = webcam_context_p->jpeg_y_buf_size;
                usbvideo_param.u_address = (kal_uint32)webcam_context_p->jpeg_u_buf_p;
                usbvideo_param.u_size = webcam_context_p->jpeg_u_buf_size;
                usbvideo_param.v_address = (kal_uint32)webcam_context_p->jpeg_v_buf_p;
                usbvideo_param.v_size = webcam_context_p->jpeg_v_buf_size;
        #endif /* __SW_JPEG_CODEC_SUPPORT__ */
            
                camera_result = usbvideo_camera_preview(&usbvideo_param);
                if(camera_result == KAL_FALSE)
                {
                    exit_usbvideo_camera_preview();
                    usbvideo_camera_power_off();
                    break;
                }        
                WEBCAM_ENTER_STATE(WEBCAM_PREVIEW);
                webcam_set_result(MED_RES_OK);
                WEBCAM_SET_EVENT(WEBCAM_EVT_RESUME);
                
            } while(0);
            if(camera_result == KAL_FALSE)
            {
                webcam_set_result(MED_RES_FAIL);
                WEBCAM_FREE_INT_MEM();              
                WEBCAM_SET_EVENT(WEBCAM_EVT_RESUME);   
                /* Webcam is still in WEBCAM_START_PREVIEW state */
            }
        }
        else
        {
            webcam_set_result(MED_RES_FAIL);
            WEBCAM_SET_EVENT(WEBCAM_EVT_RESUME);
        }

    }

}


/*****************************************************************************
 * FUNCTION
 *  webcam_capture_req_hdlr
 * DESCRIPTION
 *  This function is to inform host to start capture.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void webcam_capture_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_webcam_capture_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_webcam_capture_req_struct*) ilm_ptr->local_para_ptr;

    webcam_context_p->src_mod = ilm_ptr->src_mod_id;

    if (WEBCAM_IN_STATE(WEBCAM_PREVIEW))
    {
        webcam_send_usb_still_capture_req(NULL);
    }
    else
    {
        webcam_set_result(MED_RES_BUSY);
        WEBCAM_SET_EVENT(WEBCAM_EVT_CAPTURE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  webcam_capture_cnf_hdlr
 * DESCRIPTION
 *  This function is to handle the video capture confirm from USB task.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void webcam_capture_cnf_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    usbvideo_result_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (usbvideo_result_struct*) ilm_ptr->local_para_ptr;

    if (WEBCAM_IN_STATE(WEBCAM_PREVIEW) || WEBCAM_IN_STATE(WEBCAM_CAPTURE))
    {
        if (msg_p->result)
        {
            webcam_set_result(MED_RES_OK);
        }
        else
        {
            webcam_set_result(MED_RES_FAIL);
        }
    }
    WEBCAM_SET_EVENT(WEBCAM_EVT_CAPTURE);
}


/*****************************************************************************
 * FUNCTION
 *  webcam_rotate_req_hdlr
 * DESCRIPTION
 *  This function is to rotate webcam.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void webcam_rotate_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_webcam_rotate_req_struct *req_p;
    kal_bool camera_result = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_webcam_rotate_req_struct*) ilm_ptr->local_para_ptr;

    if (WEBCAM_IN_STATE(WEBCAM_PREVIEW))
    {
        webcam_context_p->image_mirror = cam_rotate_map[req_p->rotate];
        /* 1. stop camera preview */
        exit_usbvideo_camera_preview();
        /* 2. change the rotate value */
        usbvideo_param.image_mirror = webcam_context_p->image_mirror;
        /* 3. restart the preview */
        camera_result = usbvideo_camera_preview(&usbvideo_param);
        if(camera_result)
        {
            webcam_set_result(MED_RES_OK);
            WEBCAM_SET_EVENT(WEBCAM_EVT_ROTATE);
        }
        else
        {
            webcam_set_result(MED_RES_FAIL);
            exit_usbvideo_camera_preview();
            usbvideo_camera_power_off();
            WEBCAM_FREE_INT_MEM();                    
            WEBCAM_SET_EVENT(WEBCAM_EVT_ROTATE);            
        }
    }
    else if (WEBCAM_IN_STATE(WEBCAM_CAPTURE) || WEBCAM_IN_STATE(WEBCAM_START_PREVIEW))
    {
        webcam_context_p->image_mirror = cam_rotate_map[req_p->rotate];
        webcam_set_result(MED_RES_OK);
        WEBCAM_SET_EVENT(WEBCAM_EVT_ROTATE);
    }
    else
    {
        webcam_set_result(MED_RES_BUSY);
        WEBCAM_SET_EVENT(WEBCAM_EVT_ROTATE);
    }

}


/*****************************************************************************
 * FUNCTION
 *  webcam_set_camera_attr_req_hdlr
 * DESCRIPTION
 *  This function is to handle set camera attributes from USB.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void webcam_set_camera_attr_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    usbvideo_attr_msg_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (usbvideo_attr_msg_struct*) ilm_ptr->local_para_ptr;

    /* set camera to camera driver */
    usbvideo_camera_set_attr(&(req_p->attr_value));
    /* send confirm msg to USB task */
    webcam_send_usb_set_camera_attr_cnf((void*)req_p);

}


/*****************************************************************************
 * FUNCTION
 *  webcam_start_still_ind_hdlr
 * DESCRIPTION
 *  This function is to handle start still capture indication from USB.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void webcam_start_still_ind_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    usbvideo_still_size_struct *msg_p;
    kal_bool camera_result = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (usbvideo_still_size_struct*) ilm_ptr->local_para_ptr;

    if (WEBCAM_IN_STATE(WEBCAM_PREVIEW))
    {
        /* stop camera preview */
        exit_usbvideo_camera_preview();
        WEBCAM_FREE_INT_MEM();
        /* start camera still capture */
        webcam_context_p->intmem_start_address = (kal_uint32) med_alloc_int_mem(webcam_capture_mem[0]);
        webcam_context_p->intmem_size = (kal_uint32) webcam_capture_mem[0];

        usbvideo_param.intmem_start_address = webcam_context_p->intmem_start_address;
        usbvideo_param.intmem_size = webcam_context_p->intmem_size;
        usbvideo_param.image_mirror = webcam_context_p->image_mirror;
        usbvideo_param.target_size_enum = msg_p->still_size_type;
        usbvideo_param.target_comp_enum = msg_p->still_compression_type;
        usbvideo_param.usbvideo_cam_preview_cb = cam_preview_callback;

    #ifdef __SW_JPEG_CODEC_SUPPORT__ 
        usbvideo_param.y_address = (kal_uint32)webcam_context_p->jpeg_y_buf_p;
        usbvideo_param.y_size = webcam_context_p->jpeg_y_buf_size;
        usbvideo_param.u_address = (kal_uint32)webcam_context_p->jpeg_u_buf_p;
        usbvideo_param.u_size = webcam_context_p->jpeg_u_buf_size;
        usbvideo_param.v_address = (kal_uint32)webcam_context_p->jpeg_v_buf_p;
        usbvideo_param.v_size = webcam_context_p->jpeg_v_buf_size;
    #endif /* __SW_JPEG_CODEC_SUPPORT__ */
        
        camera_result = usbvideo_camera_capture(&usbvideo_param);
        if(camera_result == KAL_TRUE)
        {
            WEBCAM_ENTER_STATE(WEBCAM_CAPTURE);
        }
        else
        {
            exit_usbvideo_camera_capture();
            usbvideo_camera_power_off();
            WEBCAM_FREE_INT_MEM();                
            webcam_send_usb_stop_video_req(NULL);
            WEBCAM_ENTER_STATE(WEBCAM_STOPPING);                           
            webcam_set_result(MED_RES_FAIL);
            webcam_send_abort_ind();
        }
    }
    else if (WEBCAM_IN_STATE(WEBCAM_CAPTURE))
    {
        /* stop camera capture */
        exit_usbvideo_camera_capture();

        usbvideo_param.intmem_start_address = webcam_context_p->intmem_start_address;
        usbvideo_param.intmem_size = webcam_context_p->intmem_size;
        usbvideo_param.image_mirror = webcam_context_p->image_mirror;
        usbvideo_param.target_size_enum = msg_p->still_size_type;
        usbvideo_param.target_comp_enum = msg_p->still_compression_type;
        usbvideo_param.usbvideo_cam_preview_cb = cam_preview_callback;
        camera_result = usbvideo_camera_capture(&usbvideo_param);
        if(camera_result == KAL_TRUE)
        {
            WEBCAM_ENTER_STATE(WEBCAM_CAPTURE);
        }
        else
        {
            exit_usbvideo_camera_capture();
            usbvideo_camera_power_off();
            WEBCAM_FREE_INT_MEM();                
            webcam_send_usb_stop_video_req(NULL);
            WEBCAM_ENTER_STATE(WEBCAM_STOPPING);                         
            webcam_set_result(MED_RES_FAIL);
            webcam_send_abort_ind();
        }
    }
    else if (WEBCAM_IN_STATE(WEBCAM_PAUSING))
    {
        /* already send pause command to usb driver, ingore this action */
    }
    else
    {
        ASSERT(WEBCAM_IN_STATE(WEBCAM_PREVIEW));
    }

}


/*****************************************************************************
 * FUNCTION
 *  webcam_start_video_ind_hdlr
 * DESCRIPTION
 *  This function is to handle start video indication from USB.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void webcam_start_video_ind_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    usbvideo_video_size_struct *msg_p;
    kal_bool camera_result = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (usbvideo_video_size_struct*) ilm_ptr->local_para_ptr;

    if (WEBCAM_IN_STATE(WEBCAM_CAPTURE))
    {
        if (msg_p->result)
        {
            /* stop camera still capture */
            exit_usbvideo_camera_capture();
            WEBCAM_FREE_INT_MEM();
            /* start camera preview */
            webcam_context_p->intmem_start_address = (kal_uint32) med_alloc_int_mem(webcam_preview_mem[0]);
            webcam_context_p->intmem_size = (kal_uint32) webcam_preview_mem[0];

            usbvideo_param.intmem_start_address = webcam_context_p->intmem_start_address;
            usbvideo_param.intmem_size = webcam_context_p->intmem_size;
            usbvideo_param.image_mirror = webcam_context_p->image_mirror;
            usbvideo_param.target_size_enum = msg_p->video_size_type;
            usbvideo_param.target_comp_enum = msg_p->video_compression_type;
            usbvideo_param.usbvideo_cam_preview_cb = cam_preview_callback;
            
        #ifdef __SW_JPEG_CODEC_SUPPORT__ 
            usbvideo_param.y_address = (kal_uint32)webcam_context_p->jpeg_y_buf_p;
            usbvideo_param.y_size = webcam_context_p->jpeg_y_buf_size;
            usbvideo_param.u_address = (kal_uint32)webcam_context_p->jpeg_u_buf_p;
            usbvideo_param.u_size = webcam_context_p->jpeg_u_buf_size;
            usbvideo_param.v_address = (kal_uint32)webcam_context_p->jpeg_v_buf_p;
            usbvideo_param.v_size = webcam_context_p->jpeg_v_buf_size;
        #endif /* __SW_JPEG_CODEC_SUPPORT__ */
            
            camera_result = usbvideo_camera_preview(&usbvideo_param);
            if(camera_result)
            {
                WEBCAM_ENTER_STATE(WEBCAM_PREVIEW);
            }
            else
            {
                webcam_set_result(MED_RES_FAIL);
                exit_usbvideo_camera_preview();
                usbvideo_camera_power_off();
                WEBCAM_FREE_INT_MEM();                
                webcam_send_usb_stop_video_req(NULL);
                WEBCAM_ENTER_STATE(WEBCAM_STOPPING); 
                webcam_send_abort_ind();
            }
        }
        else
        {
            ASSERT(msg_p->result);
        }
    }
    else
    {
        ASSERT(WEBCAM_IN_STATE(WEBCAM_CAPTURE));
    }

}


/*****************************************************************************
 * FUNCTION
 *  webcam_change_video_ind_hdlr
 * DESCRIPTION
 *  This function is to handle change video size indication from USB.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void webcam_change_video_ind_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    usbvideo_video_size_struct *msg_p;
    kal_bool camera_result = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (usbvideo_video_size_struct*) ilm_ptr->local_para_ptr;

    if (WEBCAM_IN_STATE(WEBCAM_PREVIEW))
    {
        if (msg_p->result)
        {
            /* stop camera a preview */
            exit_usbvideo_camera_preview();

            usbvideo_param.intmem_start_address = webcam_context_p->intmem_start_address;
            usbvideo_param.intmem_size = webcam_context_p->intmem_size;
            usbvideo_param.image_mirror = webcam_context_p->image_mirror;
            usbvideo_param.target_size_enum = msg_p->video_size_type;
            usbvideo_param.target_comp_enum = msg_p->video_compression_type;
            usbvideo_param.usbvideo_cam_preview_cb = cam_preview_callback;
            
        #ifdef __SW_JPEG_CODEC_SUPPORT__ 
            usbvideo_param.y_address = (kal_uint32)webcam_context_p->jpeg_y_buf_p;
            usbvideo_param.y_size = webcam_context_p->jpeg_y_buf_size;
            usbvideo_param.u_address = (kal_uint32)webcam_context_p->jpeg_u_buf_p;
            usbvideo_param.u_size = webcam_context_p->jpeg_u_buf_size;
            usbvideo_param.v_address = (kal_uint32)webcam_context_p->jpeg_v_buf_p;
            usbvideo_param.v_size = webcam_context_p->jpeg_v_buf_size;
        #endif /* __SW_JPEG_CODEC_SUPPORT__ */
            
            camera_result = usbvideo_camera_preview(&usbvideo_param);
            if(camera_result)
            {
                WEBCAM_ENTER_STATE(WEBCAM_PREVIEW);
            }
            else
            {
                webcam_set_result(MED_RES_FAIL);
                exit_usbvideo_camera_preview();
                usbvideo_camera_power_off();
                WEBCAM_FREE_INT_MEM();                
                webcam_send_usb_stop_video_req(NULL);
                WEBCAM_ENTER_STATE(WEBCAM_STOPPING);  
                webcam_send_abort_ind();                
            }
        }
        else
        {
            ASSERT(msg_p->result);
        }
    }
    else
    {
        ASSERT(WEBCAM_IN_STATE(WEBCAM_PREVIEW));
    }

}


/*****************************************************************************
 * FUNCTION
 *  webcam_drv_abort_ind_hdlr
 * DESCRIPTION
 *  This function is to handle drvier aboart, but the cable didnt plugout.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void webcam_drv_abort_ind_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!WEBCAM_IN_STATE(WEBCAM_IDLE))
    {
        webcam_send_abort_ind();
    }
}

/*****************************************************************************
 * FUNCTION
 *  webcam_encode_req_hdlr
 * DESCRIPTION
 *  jpeg encode event handler
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __SW_JPEG_CODEC_SUPPORT__
void webcam_encode_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (WEBCAM_IN_STATE(WEBCAM_PREVIEW) ||
        WEBCAM_IN_STATE(WEBCAM_CAPTURE))
    {
        usbvideo_camera_frame_ready();
    }
}
#endif /* __SW_JPEG_CODEC_SUPPORT__ */ 


#endif /* __MED_WEBCAM_MOD__ */ 

#endif /* MED_NOT_PRESENT */ 

