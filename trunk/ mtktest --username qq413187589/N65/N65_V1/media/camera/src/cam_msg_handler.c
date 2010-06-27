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
 *   cam_msg_handler.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes message handle functions of image module.
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
#include "lcd_if.h"
#include "lcd_sw_inc.h"
#include "fat_fs.h"
#include "custom_equipment.h"
#if defined(JPG_ENCODE) || defined(__SW_JPEG_CODEC_SUPPORT__)
#include "jpeg.h"
#endif
#ifdef ISP_SUPPORT
#include "isp_if.h"
#include "ae_awb.h"
#include "image_effect.h"
#include "visual_comm.h"
#include "img_comm.h"
#endif /* ISP_SUPPORT */

/* local includes */
#include "med_global.h"
#include "med_main.h"
#include "aud_defs.h"
#include "med_struct.h"
#include "med_api.h"
#include "med_context.h"
#include "med_smalloc.h"
#include "med_utility.h"
#include "cam_main.h"
#include "img_main.h"

/* XENON_FLASHLIGHT */
#if defined(XENON_FLASHLIGHT) || defined(XENON_FLASHLIGHT_ANTI_RED_EYE)
#include "uem_context.h"
#include "uem_utility.h"
#include "isp_flashlight.h"
#endif

#if defined(__MED_VID_ENC_MOD__) || defined(__MED_MJPG_ENC_MOD__)
#include "vid_main.h"
#endif

#ifdef MP4_CODEC
#include "med_c_main.h"
#include "med_c_struct.h"
#endif /* MP4_CODEC */

#ifdef __MED_TVO_MOD__
#include "tv_out.h"
#include "tvo_main.h"
#endif /* __MED_TVO_MOD__ */

#ifdef __CAM_TRACE_ON__
#include "med_trc.h"
#endif

#ifdef BARCODE_DECODER_SCANBUY
#include "sc_2dDecoder.h"
    #if MT6219_SERIES
    #include "dcmgr.h"
    #endif
#endif

#ifdef __MED_CAM_MOD__

#if (MT6228_SERIES)
extern void set_overlay_palette(kal_uint8 palette_size, kal_uint32 *palette_addr_ptr);
#endif
#if defined(__SW_JPEG_CODEC_SUPPORT__) && !defined(WIN32)
extern kal_uint32 INT_SwitchStackToRun(void *stack_start, kal_uint32 stack_size, kal_func_ptr func, kal_uint32 argc, ...);
#endif

#define CAM_FREE_CAPTURE_BUFFER()       if (cam_context_p->capture_buffer_p)  \
                                             med_free_ext_mem((void**)&cam_context_p->capture_buffer_p)

#define CAM_FREE_INT_BUFFER()       if (cam_context_p->intmem_start_address)  \
                                             med_free_int_mem((void**)&cam_context_p->intmem_start_address)

#define CAM_FREE_EXT_BUFFER()       if (cam_context_p->extmem_start_address)  \
                                             med_free_ext_mem((void**)&cam_context_p->extmem_start_address)
#ifdef BARCODE_SUPPORT
#define CAME_FREE_BARCODE_BUFFER()  if(cam_context_p->barcode_buffer_address) \
                                             med_free_ext_mem((void**)&cam_context_p->barcode_buffer_address)
#endif
#if defined(ISP_SUPPORT)
#if MT6219_SERIES
kal_int32 cam_capture_mem[2] = {MAX_CAM_CAP_INT_MEM_SIZE, MAX_CAM_CAP_EXT_MEM_SIZE};
kal_int32 cam_preview_mem[2] = {3840, 0};
#else /* MT6219_SERIES */
kal_int32 cam_capture_mem[2] = {MAX_CAM_CAP_INT_MEM_SIZE, MAX_CAM_CAP_EXT_MEM_SIZE};
kal_int32 cam_preview_mem[2] = {46080, 0};
#endif /* MT6219_SERIES */
/* rotate mapping for MT6219 */
kal_uint8 cam_rotate_map[CAM_NO_OF_IMAGE_ROTATE] =
{
    IMAGE_NORMAL,
    IMAGE_NORMAL,
    IMAGE_HV_MIRROR,
    IMAGE_NORMAL,
    IMAGE_H_MIRROR,
    IMAGE_NORMAL,
    IMAGE_V_MIRROR,
    IMAGE_NORMAL
};

/* wb mapping for MT6219 */
kal_uint8 cam_wb_map[CAM_NO_OF_WB] =
{
    0,
    DAYLIGHT,
    TUNGSTEN,
    FLUORESCENT,
    CLOUD,
    INCANDESCENCE
};

#endif /* defined(ISP_SUPPORT) */

#if defined (ISP_SUPPORT)
camera_capture_mem_struct capture_mem_param;
jpeg_encode_process_struct jpg_encode;
#ifdef BARCODE_DECODER_SCANBUY
camera_capture_barcode_struct capture_barcode_param;
#endif
#endif

#if defined(XENON_FLASHLIGHT) || defined(XENON_FLASHLIGHT_ANTI_RED_EYE)
static void cam_xenon_status_check(void *args);
kal_int32 cam_turn_on_xenonflash(void);
kal_int32 cam_turn_off_xenonflash(void);
#endif

/*==== FUNCTIONS ===========*/


/*****************************************************************************
 * FUNCTION
 *  cam_open_image_file
 * DESCRIPTION
 *  This function is to open image file for capture.
 * PARAMETERS
 *  file_name       [?]
 *  buffer_size     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 cam_open_image_file(kal_wchar *file_name, kal_uint32 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if the format valid */

    /* open the file */
    cam_context_p->file_handle = FS_Open((kal_wchar*) file_name, FS_CREATE | FS_READ_WRITE);

    if (cam_context_p->file_handle >= 0)
    {
        /* Check free memory space first */
        if ((result = med_check_disc_space(file_name, CAPTURE_MEM_MARGIN)) != MED_RES_OK)
        {
            FS_Close(cam_context_p->file_handle);
            FS_Delete((kal_wchar*) file_name);
            return result;
        }
        /* to release the memory allocated in MED_MODE_BUFFER mode */
        CAM_FREE_CAPTURE_BUFFER();
        cam_context_p->capture_buffer_p = (kal_uint32) med_alloc_ext_mem(buffer_size);
        if (cam_context_p->capture_buffer_p == NULL)
        {
            FS_Close(cam_context_p->file_handle);
            FS_Delete((kal_wchar*) file_name);
            return MED_RES_MEM_INSUFFICIENT;
        }
        else
        {
            cam_context_p->file_name_p = (kal_wchar*) file_name;
            return MED_RES_OK;
        }
    }
    else if (cam_context_p->file_handle == FS_WRITE_PROTECTION)
    {
        return MED_RES_WRITE_PROTECTION;
    }
    else if ((cam_context_p->file_handle == FS_ROOT_DIR_FULL) || (cam_context_p->file_handle == FS_DISK_FULL))
    {
        return MED_RES_DISC_FULL;
    }
    else
    {
        return MED_RES_OPEN_FILE_FAIL;
    }

}


/*****************************************************************************
 * FUNCTION
 *  cam_close_image_file
 * DESCRIPTION
 *  This function is to close image file for capture.
 * PARAMETERS
 *  size        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 cam_close_image_file(kal_uint32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;
    kal_uint32 len;
    kal_int32 res = MED_RES_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (size > 0)
    {
        result = FS_Write(cam_context_p->file_handle, (void*)cam_context_p->capture_buffer_p, size, &len);
        FS_Close(cam_context_p->file_handle);
        if (result != FS_NO_ERROR)
        {
            CAM_CLOSE_IMAGE_RESULT_TRACE(result);
            FS_Delete((kal_wchar*) cam_context_p->file_name_p);
            if (result == FS_DRIVE_NOT_FOUND)
            {
                res = MED_RES_NO_DISC;
            }
            else if (result == FS_DISK_FULL)
            {
                res = MED_RES_DISC_FULL;
            }
            else
            {
                res = MED_RES_OPEN_FILE_FAIL;
            }
        }
        else if (size != len)
        {
            FS_Delete((kal_wchar*) cam_context_p->file_name_p);
            res = MED_RES_DISC_FULL;
        }
    }
    else
    {
        /* Close and delete the file */
        FS_Close(cam_context_p->file_handle);
        FS_Delete((kal_wchar*) cam_context_p->file_name_p);
        res = MED_RES_DISC_FULL;
    }

    /* to release the memory allocated in MED_MODE_BUFFER mode */
    CAM_FREE_CAPTURE_BUFFER();
    return res;

}


/*****************************************************************************
 * FUNCTION
 *  cam_set_flash
 * DESCRIPTION
 *  This function is to set the flash.
 * PARAMETERS
 *  flash_mode      [IN]
 *  kal_int16 value(?)
 * RETURNS
 *  void
 *****************************************************************************/
kal_int16 cam_set_flash(kal_int16 flash_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return MED_RES_OK;
}


/*****************************************************************************
 * FUNCTION
 *  cam_set_flash_req_hdlr
 * DESCRIPTION
 *  This function is to handle camera set flash request.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void cam_set_flash_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_set_flash_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_context_p->src_mod = ilm_ptr->src_mod_id;

    req_p = (media_cam_set_flash_req_struct*) ilm_ptr->local_para_ptr;

    cam_set_flash(req_p->flash_mode);

}

#if defined (ISP_SUPPORT)
/*****************************************************************************
 * FUNCTION
 *  cam_release_memory
 * DESCRIPTION
 *  This function is to release cam related memory.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cam_release_memory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //if (cam_context_p->capture_buffer_p)
    //med_free_ext_mem((void**)&cam_context_p->capture_buffer_p);
    if (cam_context_p->int_frame_buffer_p)
    {
        med_free_int_mem((void **)&cam_context_p->int_frame_buffer_p);
    }
    if (cam_context_p->ext_frame_buffer_p)
    {
        med_free_ext_mem((void **)&cam_context_p->ext_frame_buffer_p);
    }
    if (cam_context_p->intmem_start_address)
    {
        med_free_int_mem((void **)&cam_context_p->intmem_start_address);
    }
    if (cam_context_p->extmem_start_address)
    {
        med_free_ext_mem((void **)&cam_context_p->extmem_start_address);
    }
#if defined(MT6225)
    if (cam_context_p->y_address)
    {
        med_free_ext_mem((void **)&cam_context_p->y_address);
    }
    if (cam_context_p->u_address)
    {
        med_free_ext_mem((void **)&cam_context_p->u_address);
    }
    if (cam_context_p->v_address)
    {
        med_free_ext_mem((void **)&cam_context_p->v_address);
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  cam_power_up_req_hdlr
 * DESCRIPTION
 *  This function is to handle power up request.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void cam_power_up_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_power_up_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_context_p->src_mod = ilm_ptr->src_mod_id;

    req_p = (media_cam_power_up_req_struct*) ilm_ptr->local_para_ptr;

    cam_context_p->seq_num = req_p->seq_num;

    if (CAM_IN_STATE(CAM_IDLE))
    {
    #ifdef __MTK_TARGET__
        init_isp_if();
    #endif
        CAM_ENTER_STATE(CAM_READY);
        cam_send_ready_ind(MED_RES_OK);
    }
    else if (CAM_IN_STATE(CAM_READY))
    {
        cam_send_ready_ind(MED_RES_OK);
    }
    CAM_SET_EVENT(CAM_EVT_POWER_UP);
}


/*****************************************************************************
 * FUNCTION
 *  cam_power_down_req_hdlr
 * DESCRIPTION
 *  This function is to handle power down request.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void cam_power_down_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_power_down_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_context_p->src_mod = ilm_ptr->src_mod_id;

    req_p = (media_cam_power_down_req_struct*) ilm_ptr->local_para_ptr;

    if (!CAM_IN_STATE(CAM_IDLE))
    {
    #ifdef __MTK_TARGET__
    #ifdef __MED_VID_ENC_MOD__
        ASSERT((!VID_IN_STATE(VID_RECORD)) && (!VID_IN_STATE(VID_RECORD_PAUSED))) if (VID_IN_STATE(VID_PREVIEW))
        {
            exit_mpeg4_encode_process();
            vid_release_memory();
            VID_ENTER_STATE(VID_IDLE);
        }
    #endif /* __MED_VID_ENC_MOD__ */
        if (CAM_IN_STATE(CAM_PREVIEW))
        {
            exit_camera_preview_process();
        }
        power_off_isp();
        /* to release the memory allocated in MED_MODE_BUFFER mode */
        CAM_FREE_CAPTURE_BUFFER();
        cam_release_memory();
    #endif /* __MTK_TARGET__ */
        CAM_ENTER_STATE(CAM_IDLE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  cam_preview_callback
 * DESCRIPTION
 *  This function is to handle camera preview callback.
 * PARAMETERS
 *  cause       [IN]
 *  ilm_struct *ilm_ptr(?)
 * RETURNS
 *  void
 *****************************************************************************/
void cam_preview_callback(kal_uint8 cause)
{
#ifdef MP4_CODEC
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_hp_send_event_ind(CAM_EVT_PREVIEW, cause);
#else /* MP4_CODEC */
    cam_send_event_ind(CAM_EVT_PREVIEW, cause);
#endif /* MP4_CODEC */
}


/*****************************************************************************
 * FUNCTION
 *  cam_focus_callback
 * DESCRIPTION
 *  This function is to handle camera focus callback.
 * PARAMETERS
 *  cause       [IN]
 *  ilm_struct *ilm_ptr(?)
 * RETURNS
 *  void
 *****************************************************************************/
void cam_focus_callback(kal_uint8 cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_send_event_ind(CAM_EVT_AUTOFOCUS, cause);
}

#ifdef BARCODE_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  cam_barcode_callback
 * DESCRIPTION
 *  This function is to handle camera focus callback.
 * PARAMETERS
 *  cause       [IN]
 *  ilm_struct *ilm_ptr(?)
 * RETURNS
 *  void
 *****************************************************************************/
void cam_barcode_callback(kal_uint8 cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* cam_send_barcode_decode_done_ind(cause); */
}
#endif

/*****************************************************************************
 * FUNCTION
 *  cam_get_preview_frame_rate
 * DESCRIPTION
 *  This function is to convert preview frame rate.
 * PARAMETERS
 *  frame_rate      [IN]
 * RETURNS
 *  kal_uint8
 *****************************************************************************/
kal_uint8 cam_get_preview_frame_rate(kal_int16 frame_rate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (frame_rate)
    {
        case CAMERA_PERVIEW_FRAME_RATE:
            return 30;
        case VIDEO_PERVIEW_FRAME_RATE:
            return 15;
        default:
            return 15;
    }
}

#if defined(XENON_FLASHLIGHT) || defined(XENON_FLASHLIGHT_ANTI_RED_EYE)
#define XENON_FLASH_STATE_IN(STATE) (cam_context_p->xenon_flash_status==STATE)

/*****************************************************************************
 * FUNCTION
 *  cam_xenon_status_check
 * DESCRIPTION
 *  This function is to check current xenon flash light status
 * PARAMETERS
 *  args     [IN]  we do not use it.
 * RETURNS
 *  void
 *****************************************************************************/
static void cam_xenon_status_check(void *args)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    xenon_para_struct xenon_para;
    xenon_info_struct *xenon_info_p;
    uem_bmt_struct bmt_status;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (CAM_IN_STATE(CAM_PREVIEW)||CAM_IN_STATE(CAM_READY)) 
    {
        uem_get_bat_status(&bmt_status);

        if (bmt_status.volt == 0)
            xenon_para.voltage = 3700;
        else
            xenon_para.voltage = bmt_status.volt/1000;

        if (xenon_para.voltage  < 3400)
        {
            cam_turn_off_xenonflash();
            cam_send_xenon_flash_status_ind(CAM_XENON_FLASH_LOW_BATTERY);
            return;
        }                

        xenon_info_p = isp_xenon_flashlight_ready_check(&xenon_para);
        switch (xenon_info_p->retcode)
        {
            case XENON_RETCODE_READY:
                if (XENON_FLASH_STATE_IN(CAM_XENON_FLASH_CHARGING))
                {
                    cam_context_p->xenon_flash_status = CAM_XENON_FLASH_READY;
                    cam_send_xenon_flash_status_ind(cam_context_p->xenon_flash_status);
                }
                med_start_timer(CAM_XENON_FLASH_CHECK_TIMER , xenon_info_p->ready_polling_period, cam_xenon_status_check, 0);
                break;
            case XENON_RETCODE_CHARGE_STOP:
            case XENON_RETCODE_CHARGE_TIMEOUT:
                //**< do nothing 
                break;
            case XENON_RETCODE_NOT_READY:
                if (XENON_FLASH_STATE_IN(CAM_XENON_FLASH_CHARGING))
                {
                    if (cam_context_p->xenon_max_charge_duty == 0)
                    {
                        cam_turn_off_xenonflash();
                        cam_send_xenon_flash_status_ind(CAM_XENON_FLASH_TIMEOUT);
                    }
                    else
                    {
                        if (cam_context_p->xenon_max_charge_duty < xenon_info_p->ready_polling_period)
                            cam_context_p->xenon_max_charge_duty = 0;
                        else 
                            cam_context_p->xenon_max_charge_duty -= xenon_info_p->ready_polling_period;
                        med_start_timer(CAM_XENON_FLASH_CHECK_TIMER , xenon_info_p->ready_polling_period, cam_xenon_status_check, 0);
                    }
                }
                else if(XENON_FLASH_STATE_IN(CAM_XENON_FLASH_READY))
                {
                    ASSERT(0);
                }                
                break;
        }
    }
    else
        ASSERT(0);
}


/*****************************************************************************
 * FUNCTION
 *  cam_turn_on_xenonflash
 * DESCRIPTION
 *  This function is to turn on/off xenon flash light.
 * PARAMETERS
 *  voltage        [IN]  Current voltage
 * RETURNS
 *  kal_int32     
 *****************************************************************************/
kal_int32 cam_turn_on_xenonflash(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    xenon_para_struct xenon_para;
    xenon_info_struct *xenon_info_p;
    kal_int32 ret_code = MED_RES_OK;
    uem_bmt_struct bmt_status;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    uem_get_bat_status(&bmt_status);

    if (bmt_status.volt == 0)
        xenon_para.voltage = 3700;
    else
        xenon_para.voltage = bmt_status.volt/1000;

    if (xenon_para.voltage < 3400)
    {
        cam_turn_off_xenonflash();
        cam_send_xenon_flash_status_ind(CAM_XENON_FLASH_LOW_BATTERY);
        return ret_code;
    }
    
    xenon_info_p = isp_xenon_flashlight_charge(KAL_TRUE,&xenon_para);
    switch (xenon_info_p->retcode)
    {
        case XENON_RETCODE_READY:            
            cam_context_p->xenon_flash_status = CAM_XENON_FLASH_READY;
            cam_send_xenon_flash_status_ind(cam_context_p->xenon_flash_status);
            med_start_timer(CAM_XENON_FLASH_CHECK_TIMER , xenon_info_p->ready_polling_period, cam_xenon_status_check, 0);
            break;
        case XENON_RETCODE_CHARGE_STOP:
            //* do nothing
            break;
        case XENON_RETCODE_NOT_READY:
            cam_context_p->xenon_flash_status = CAM_XENON_FLASH_CHARGING;
            cam_send_xenon_flash_status_ind(cam_context_p->xenon_flash_status);
            cam_context_p->xenon_max_charge_duty = xenon_info_p->max_charge_duty - xenon_info_p->ready_polling_period;
            med_start_timer(CAM_XENON_FLASH_CHECK_TIMER , xenon_info_p->ready_polling_period, cam_xenon_status_check, 0);
            break;                
    }
    return ret_code;
}


/*****************************************************************************
 * FUNCTION
 *  cam_turn_off_xenonflash
 * DESCRIPTION
 *  This function is to turn off xenon flash light.
 * PARAMETERS
 *  voltage        [IN]  Current voltage
 * RETURNS
 *  kal_int32    
 *****************************************************************************/
kal_int32 cam_turn_off_xenonflash(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    xenon_para_struct xenon_para;
    xenon_info_struct *xenon_info_p;
    kal_int32 ret_code = MED_RES_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    xenon_info_p = isp_xenon_flashlight_charge(KAL_FALSE,&xenon_para);
    cam_context_p->xenon_flash_status = CAM_XENON_FLASH_OFF;
    camera_operation_setting((kal_uint8) CAM_FLASH_MODE, (kal_uint16) CAM_FLASH_OFF);
    med_stop_timer(CAM_XENON_FLASH_CHECK_TIMER);
    return ret_code;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  cam_preview_req_hdlr
 * DESCRIPTION
 *  This function is to handle camera preview request.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void cam_preview_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_preview_req_struct *req_p;
    camera_preview_process_struct preview_param;
    MMDI_SCENERIO_ID old_app;
    kal_uint32 result_code = MED_RES_OK;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_context_p->src_mod = ilm_ptr->src_mod_id;

    if (KAL_TRUE != idp_register_app(SCENARIO_CAMERA_PREVIEW_ID,&old_app))
    {
        cam_set_result(MED_RES_BUSY);
        CAM_SET_EVENT(CAM_EVT_PREVIEW);
        return;
    }

    if (CAM_IN_STATE(CAM_READY))
    {
        req_p = (media_cam_preview_req_struct*) ilm_ptr->local_para_ptr;

        cam_context_p->lcd_update = preview_param.lcd_update = req_p->lcd_update;
        cam_context_p->lcd_id = preview_param.lcd_id = req_p->lcd_id;
        cam_context_p->lcd_start_x = preview_param.lcm_start_x = req_p->lcd_start_x;
        cam_context_p->lcd_start_y = preview_param.lcm_start_y = req_p->lcd_start_y;
        cam_context_p->lcd_end_x = preview_param.lcm_end_x = req_p->lcd_end_x;
        cam_context_p->lcd_end_y = preview_param.lcm_end_y = req_p->lcd_end_y;
        cam_context_p->roi_offset_x = preview_param.roi_offset_x = req_p->roi_offset_x;
        cam_context_p->roi_offset_y = preview_param.roi_offset_y = req_p->roi_offset_y;
        cam_context_p->update_layer = preview_param.update_layer = req_p->update_layer;
        cam_context_p->hw_update_layer = preview_param.hw_update_layer = req_p->hw_update_layer;

        cam_context_p->preview_offset_x = preview_param.preview_offset_x = req_p->preview_offset_x;
        cam_context_p->preview_offset_y = preview_param.preview_offset_y = req_p->preview_offset_y;

        cam_context_p->camera_offset_x=preview_param.camera_offset_x=req_p->camera_offset_x;
        cam_context_p->camera_offset_y=preview_param.camera_offset_y=req_p->camera_offset_y;
        cam_context_p->continue_capture = preview_param.continue_capture = req_p->continue_capture;

        preview_param.intmem_start_address = cam_context_p->intmem_start_address =
            (kal_uint32) med_alloc_int_mem(cam_preview_mem[0]);
        preview_param.intmem_size = cam_context_p->intmem_size = (kal_uint32) cam_preview_mem[0];
        preview_param.extmem_start_address = 0;
        preview_param.extmem_size = 0;
        cam_context_p->preview_width = preview_param.target_width = req_p->preview_width;
        cam_context_p->preview_height = preview_param.target_height = req_p->preview_height;

        /* use internal memory for preview buffer if enough */
        if (((req_p->image_buffer_size * 2) + MEM_OVERHEAD) < med_int_left_size())
        {
            CAM_BUFFER_TRACE(1);
            /* internal memory enough for double buffer */
            cam_context_p->frame_buffer_p = (kal_uint32) req_p->image_buffer_p;
            cam_context_p->frame_buffer_size = cam_context_p->extmem_size = preview_param.frame_buffer_size =
                preview_param.frame_buffer_size1 = req_p->image_buffer_size;
            cam_context_p->int_frame_buffer_p = preview_param.frame_buffer_address =
                (kal_uint32) med_alloc_int_mem(preview_param.frame_buffer_size * 2);
            preview_param.frame_buffer_address1 = preview_param.frame_buffer_address + preview_param.frame_buffer_size;
            cam_context_p->ext_frame_buffer_p = 0;
        }
        else if (req_p->image_buffer_size + MEM_OVERHEAD < med_int_left_size())
        {
            CAM_BUFFER_TRACE(2);
            /* internal memory enough for single buffer */
            cam_context_p->frame_buffer_p = (kal_uint32) req_p->image_buffer_p;
            cam_context_p->frame_buffer_size = cam_context_p->extmem_size = preview_param.frame_buffer_size =
                preview_param.frame_buffer_size1 = req_p->image_buffer_size;
            /* one internal buffer */
            cam_context_p->int_frame_buffer_p = preview_param.frame_buffer_address =
                (kal_uint32) med_alloc_int_mem(preview_param.frame_buffer_size);
            /* one external buffer */
            preview_param.frame_buffer_address1 = cam_context_p->frame_buffer_p;
            cam_context_p->ext_frame_buffer_p = 0;
        }
        else if (req_p->image_buffer_size + MEM_OVERHEAD < med_ext_left_size())
        {
            CAM_BUFFER_TRACE(3);
            /* internal memory enough for single buffer */
            cam_context_p->frame_buffer_p = (kal_uint32) req_p->image_buffer_p;
            cam_context_p->frame_buffer_size = cam_context_p->extmem_size = preview_param.frame_buffer_size =
                preview_param.frame_buffer_size1 = req_p->image_buffer_size;
            /* one external buffer given from MMI */
            preview_param.frame_buffer_address = cam_context_p->frame_buffer_p;
            /* one more external buffer */
            cam_context_p->ext_frame_buffer_p = preview_param.frame_buffer_address1 =
                (kal_uint32) med_alloc_ext_mem(preview_param.frame_buffer_size);
            cam_context_p->int_frame_buffer_p = 0;
        }
        else
        {
            CAM_BUFFER_TRACE(4);
            /* use single external buffer from MMI */
            cam_context_p->frame_buffer_p = preview_param.frame_buffer_address1 = preview_param.frame_buffer_address =
                (kal_uint32) req_p->image_buffer_p;
            cam_context_p->frame_buffer_size = preview_param.frame_buffer_size1 = preview_param.frame_buffer_size =
                req_p->image_buffer_size;
            cam_context_p->int_frame_buffer_p = 0;
            cam_context_p->ext_frame_buffer_p = 0;
        }

        cam_context_p->zoom_factor = preview_param.zoom_factor = (kal_uint8) req_p->zoom_factor;
        cam_context_p->image_mirror = preview_param.image_mirror = cam_rotate_map[req_p->rotate];
        cam_context_p->ev_value = preview_param.ev_value = req_p->exposure;
        cam_context_p->wb_mode = preview_param.wb_mode = req_p->WB;
        cam_context_p->contrast_level = preview_param.contrast_level = req_p->contrast;
        cam_context_p->brightness_level = preview_param.brightness_level = req_p->brightness;
        cam_context_p->saturation_value = preview_param.saturation_value = req_p->saturation;
        cam_context_p->image_effect = preview_param.image_effect = req_p->effect;
        cam_context_p->hue_value = preview_param.hue_value = req_p->hue;
        cam_context_p->night_mode = preview_param.night_mode = req_p->night_mode;
        cam_context_p->banding_freq = preview_param.banding_freq = req_p->banding_freq;
        cam_context_p->lcd_rotate = req_p->lcd_rotate;
        preview_param.frame_rate = cam_context_p->frame_rate = cam_get_preview_frame_rate(req_p->frame_rate);
        preview_param.rotate_value = (kal_uint8) req_p->lcd_rotate;

        /* LCD Setting */
        cam_context_p->roi_background_color = preview_param.roi_background_color = req_p->roi_background_color;

        /* AF */
        cam_context_p->af_zone0_x = preview_param.af_zone0_x = req_p->af_zone0_x;
        cam_context_p->af_zone0_y = preview_param.af_zone0_y = req_p->af_zone0_y;
        cam_context_p->af_zone1_x = preview_param.af_zone1_x = req_p->af_zone1_x;
        cam_context_p->af_zone1_y = preview_param.af_zone1_y = req_p->af_zone1_y;
        cam_context_p->af_zone2_x = preview_param.af_zone2_x = req_p->af_zone2_x;
        cam_context_p->af_zone2_y = preview_param.af_zone2_y = req_p->af_zone2_y;
        cam_context_p->af_zone3_x = preview_param.af_zone3_x = req_p->af_zone3_x;
        cam_context_p->af_zone3_y = preview_param.af_zone3_y = req_p->af_zone3_y;
        cam_context_p->af_zone4_x = preview_param.af_zone4_x = req_p->af_zone4_x;
        cam_context_p->af_zone4_y = preview_param.af_zone4_y = req_p->af_zone4_y;

    #if MT6228_SERIES
        #ifdef __MED_TVO_MOD__
            tvo_context_p->tv_output_mode = req_p->tv_output_mode;
            preview_param.tv_output = tvo_context_p->tv_output = req_p->tv_output;
            preview_param.tv_output_width = tvo_context_p->tv_output_width = req_p->tv_output_width;
            preview_param.tv_output_height = tvo_context_p->tv_output_height = req_p->tv_output_height;
            preview_param.tv_output_offset_x = tvo_context_p->tv_output_offset_x = req_p->tv_output_offset_x;
            preview_param.tv_output_offset_y = tvo_context_p->tv_output_offset_y = req_p->tv_output_offset_y;
            preview_param.tv_output_buffer_size = tvo_context_p->tv_output_buffer_size = req_p->tv_output_buffer_size;
            preview_param.tv_output_buffer1_address = tvo_context_p->tv_output_buffer1_address =
                req_p->tv_output_buffer1_address;
            preview_param.tv_output_buffer2_address = tvo_context_p->tv_output_buffer2_address =
                req_p->tv_output_buffer2_address;
            preview_param.tv_rotate_buffer1_address = tvo_context_p->tv_rotate_buffer1_address =
                req_p->tv_rotate_buffer1_address;
            preview_param.tv_rotate_buffer2_address = tvo_context_p->tv_rotate_buffer2_address =
                req_p->tv_rotate_buffer2_address;
        #endif /* __MED_TVO_MOD__ */

        /* ISP Setting */
        cam_context_p->ae_metering_mode = preview_param.ae_metering_mode = req_p->ae_metering_mode;
        cam_context_p->iso_setting = preview_param.iso_setting = req_p->iso_setting;
        cam_context_p->prev_dsc_mode = req_p->dsc_mode;
        cam_context_p->dsc_mode = preview_param.dsc_mode = req_p->dsc_mode;
        cam_context_p->af_metering_mode = preview_param.af_metering_mode = req_p->af_metering_mode;
        cam_context_p->af_mode = preview_param.af_mode = req_p->af_mode;
        cam_context_p->tv_setting = preview_param.tv_setting = req_p->tv_setting;
        cam_context_p->av_setting = preview_param.av_setting = req_p->av_setting;
        cam_context_p->flash_mode = preview_param.flash_mode = req_p->flash_mode;

        if (cam_context_p->dsc_mode != CAM_NIGHTSCENE && cam_context_p->iso_setting != CAM_ISO_AUTO)
        {
            if (cam_context_p->dsc_mode == CAM_FLOWER)
            {
                cam_context_p->af_mode = preview_param.af_mode = CAM_AF_MACRO_MODE;
            }
            else
                cam_context_p->af_mode = preview_param.af_mode = CAM_AF_AUTO_MODE;    
            cam_context_p->dsc_mode = preview_param.dsc_mode = CAM_ISO_MODE;
        }
        else if (cam_context_p->dsc_mode!= CAM_FLOWER)
        {
            cam_context_p->af_mode = preview_param.af_mode = CAM_AF_AUTO_MODE;
        }

        /* IPP Setting */
        cam_context_p->image_pitch_mode = preview_param.image_pitch_mode = req_p->image_pitch_mode;
        cam_context_p->image_data_format = preview_param.image_data_format = req_p->image_data_format;
        cam_context_p->image_pitch_bytes = preview_param.image_pitch_bytes = req_p->image_pitch_bytes;

        cam_context_p->overlay_frame_mode = preview_param.overlay_frame_mode = req_p->overlay_frame_mode;
        cam_context_p->overlay_color_depth = preview_param.overlay_color_depth = req_p->overlay_color_depth;
        cam_context_p->overlay_frame_source_key = preview_param.overlay_frame_source_key =
            req_p->overlay_frame_source_key;
        cam_context_p->overlay_frame_width = preview_param.overlay_frame_width = req_p->overlay_frame_width;
        cam_context_p->overlay_frame_height = preview_param.overlay_frame_height = req_p->overlay_frame_height;
        cam_context_p->overlay_frame_buffer_address = preview_param.overlay_frame_buffer_address =
            req_p->overlay_frame_buffer_address;
        /* TV Setting */
    #elif MT6225_SERIES || ( MT6219_SERIES && !defined(MT6219))
        /* ISP Setting */
        cam_context_p->ae_metering_mode = preview_param.ae_metering_mode = req_p->ae_metering_mode;
        cam_context_p->af_metering_mode = preview_param.af_metering_mode = req_p->af_metering_mode;
        cam_context_p->af_mode = preview_param.af_mode = req_p->af_mode;
        cam_context_p->flash_mode = preview_param.flash_mode = req_p->flash_mode;
        cam_context_p->prev_dsc_mode = req_p->dsc_mode;
        cam_context_p->dsc_mode = preview_param.dsc_mode = req_p->dsc_mode;
        cam_context_p->iso_setting = preview_param.iso_setting = req_p->iso_setting;       

        if (cam_context_p->dsc_mode != CAM_NIGHTSCENE && cam_context_p->iso_setting != CAM_ISO_AUTO)
        {
            if (cam_context_p->dsc_mode == CAM_FLOWER)
            {
                cam_context_p->af_mode = preview_param.af_mode = CAM_AF_MACRO_MODE;
            }
            else
                cam_context_p->af_mode = preview_param.af_mode = CAM_AF_AUTO_MODE;    
            cam_context_p->dsc_mode = preview_param.dsc_mode = CAM_ISO_MODE;
        }
        else if (cam_context_p->dsc_mode!= CAM_FLOWER)
        {
            cam_context_p->af_mode = preview_param.af_mode = CAM_AF_AUTO_MODE;
        }
        
    #endif

        preview_param.cam_preview_cb = cam_preview_callback;

    #ifdef __CAM_AUTO_FOCUS__
        preview_param.cam_focus_cb = cam_focus_callback;
    #endif


    #if defined(XENON_FLASHLIGHT) || defined(XENON_FLASHLIGHT_ANTI_RED_EYE)
    /* initialize off */
    cam_context_p->xenon_flash_status = CAM_XENON_FLASH_OFF;
    if (cam_context_p->flash_mode != CAM_FLASH_OFF)
    {
        result_code = cam_turn_on_xenonflash();
    }
    #endif

    #ifdef __MTK_TARGET__
        if (result_code == MED_RES_OK && camera_preview_process(&preview_param) != KAL_TRUE)
        {
            /* preview failed, free memory and power off camera */
            cam_release_memory();
            power_off_isp();
            /* to release the memory allocated in MED_MODE_BUFFER mode */
            CAM_FREE_CAPTURE_BUFFER();
            CAM_ENTER_STATE(CAM_IDLE);
            cam_set_result(MED_RES_FAIL);
        }
        else
    #endif /* __MTK_TARGET__ */
        {
            CAM_ENTER_STATE(CAM_PREVIEW);
        }

    }
    else
    {
        cam_set_result(MED_RES_BUSY);
    }

    CAM_SET_EVENT(CAM_EVT_PREVIEW);

}


/*****************************************************************************
 * FUNCTION
 *  cam_stop_req_hdlr
 * DESCRIPTION
 *  This function is to handle camera stop request.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void cam_stop_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_context_p->src_mod = ilm_ptr->src_mod_id;

    if (CAM_IN_STATE(CAM_PREVIEW))
    {
    #ifdef __MTK_TARGET__
        exit_camera_preview_process();
    #endif
        /* copy int_frame_buffer data to MMI buffer for displaying correct */
        if (cam_context_p->int_frame_buffer_p)
        {
            memcpy(
                (kal_uint8*) cam_context_p->frame_buffer_p,
                (kal_uint8*) cam_context_p->int_frame_buffer_p,
                cam_context_p->frame_buffer_size);
        }
        cam_release_memory();
        CAM_ENTER_STATE(CAM_READY);
    }
    else if (CAM_IN_STATE(CAM_CAPTURE))
    {
        stop_camera_capture_process();
        cam_release_memory();
        CAM_ENTER_STATE(CAM_READY);
    }
    
    #if defined(XENON_FLASHLIGHT) || defined(XENON_FLASHLIGHT_ANTI_RED_EYE)
    if (cam_context_p->xenon_flash_status != CAM_XENON_FLASH_OFF)
    med_stop_timer(CAM_XENON_FLASH_CHECK_TIMER);
    #endif
    
    CAM_SET_EVENT(CAM_EVT_STOP);

}


/*****************************************************************************
 * FUNCTION
 *  cam_start_fast_zoom_req_hdlr
 * DESCRIPTION
 *  This function is to handle the request of starting the camera fast zoom.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void cam_start_fast_zoom_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_start_fast_zoom_req_struct *req_p;
    isp_fast_zoom_struct zoom_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_context_p->src_mod = ilm_ptr->src_mod_id;

    req_p = (media_cam_start_fast_zoom_req_struct*) ilm_ptr->local_para_ptr;
    zoom_data.start = KAL_TRUE;
    zoom_data.zoom_in = req_p->zoom_in;
    zoom_data.zoom_limit = req_p->zoom_limit;
    zoom_data.zoom_step = req_p->zoom_step;
    zoom_data.zoom_speed = req_p->zoom_speed;

    isp_fast_zoom_setting(zoom_data);
}


/*****************************************************************************
 * FUNCTION
 *  cam_stop_fast_zoom_req_hdlr
 * DESCRIPTION
 *  This function is to handle the request of stopping the camera fast zoom.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void cam_stop_fast_zoom_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    isp_fast_zoom_struct zoom_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_context_p->src_mod = ilm_ptr->src_mod_id;

    zoom_data.start = KAL_FALSE;

    isp_fast_zoom_setting(zoom_data);
    CAM_SET_EVENT(CAM_EVT_STOP_FAST_ZOOM);
}


/*****************************************************************************
 * FUNCTION
 *  cam_get_focus_steps_req_hdlr
 * DESCRIPTION
 *  This function is to handle the request of getting the camera fast zoom factor.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void cam_get_focus_steps_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_get_focus_steps_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* isp_fast_zoom_struct zoom_data; */

    cam_context_p->src_mod = ilm_ptr->src_mod_id;

    req_p = (media_cam_get_focus_steps_req_struct*) ilm_ptr->local_para_ptr;
#ifdef __CAM_AUTO_FOCUS__
    *(req_p->flag) = get_focus_step(req_p->total_steps, req_p->current_steps);
#endif
    CAM_SET_EVENT(CAM_EVT_GET_FOCUS_STEPS);
}


/*****************************************************************************
 * FUNCTION
 *  cam_get_fast_zoom_factor_req_hdlr
 * DESCRIPTION
 *  This function is to handle the request of getting the camera fast zoom factor.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void cam_get_fast_zoom_factor_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_get_fast_zoom_factor_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* isp_fast_zoom_struct zoom_data; */

    cam_context_p->src_mod = ilm_ptr->src_mod_id;

    req_p = (media_cam_get_fast_zoom_factor_req_struct*) ilm_ptr->local_para_ptr;

    *(req_p->factor) = get_isp_digital_zoom_factor();

    CAM_SET_EVENT(CAM_EVT_GET_FAST_ZOOM_FACTOR);
}


/*****************************************************************************
 * FUNCTION
 *  cam_img_encode_callback
 * DESCRIPTION
 *  This function is the callback function of image encoding for capture.
 * PARAMETERS
 *  cause       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void cam_img_encode_callback(kal_uint8 cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    img_send_encode_event_ind(cause);
}


/*****************************************************************************
 * FUNCTION
 *  cam_capture_callback
 * DESCRIPTION
 *  This function is the callback function of capture.
 * PARAMETERS
 *  cause       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void cam_capture_callback(kal_uint8 cause)
{
#if (MT6228_SERIES && defined(AF_SUPPORT))
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cam_context_p->continue_capture == KAL_FALSE && cam_context_p->af_mode != CAM_AF_MANUAL_MODE)
    {
        camera_operation_setting((kal_uint8) CAM_AF_KEY, (kal_uint16) CAM_AF_RELEASE);
    }
#endif /* (MT6228_SERIES && defined(AF_SUPPORT)) */
    jfif_thumbnail_swap((kal_uint32) cam_context_p->capture_buffer_p);

    cam_send_event_ind(CAM_EVT_CAPTURE, cause);

}


/*****************************************************************************
 * FUNCTION
 *  cam_capture_from_isp
 * DESCRIPTION
 *  This function is to capture image from ISP to jpeg.
 * PARAMETERS
 *  req_p       [?]
 *  ilm_struct *ilm_ptr(?)
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint32 cam_capture_from_isp(media_cam_capture_req_struct *req_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    camera_capture_jpeg_struct capture_isp_param;
    kal_uint32 file_size = 0;
#if MT6225_SERIES
    kal_uint32 img_width ,img_height;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    capture_isp_param.target_width = req_p->image_width;
    capture_isp_param.target_height = req_p->image_height;
    capture_isp_param.image_quality = (kal_uint8) req_p->image_quality;
    capture_isp_param.jpeg_gray_mode = 0;   /* alway color mode */
    capture_isp_param.intmem_start_address = cam_context_p->intmem_start_address =
        (kal_uint32) med_alloc_int_mem(cam_capture_mem[0]);
    capture_isp_param.intmem_size = cam_context_p->intmem_size = (kal_uint32) cam_capture_mem[0];
    capture_isp_param.extmem_start_address = 0;
    capture_isp_param.extmem_size = 0;

    capture_isp_param.target_buffer_start_address = (kal_uint32) cam_context_p->capture_buffer_p;
    capture_isp_param.target_buffer_size = MAX_CAM_FILE_BUFFER_LEN;
#if MT6225_SERIES
    /* allocate memory for YUV channels */
    img_width = (req_p->image_width%16==0)? req_p->image_width : 16 - (req_p->image_width%16) + req_p->image_width;
    img_height = (req_p->image_height%16==0)? req_p->image_height : 16 - (req_p->image_height%16) + req_p->image_height;
    cam_context_p->channel_size = img_width*img_height;

    #ifdef DRV_JPG_ENC_DIRECT_COUPLE_SUPPORT
        capture_isp_param.memory_output = cam_context_p->memory_output = req_p->memory_output;
        capture_isp_param.memory_output_type = IMAGE_FORMAT_RGB565;
        capture_isp_param.memory_output_width = cam_context_p->memory_output_width = req_p->memory_output_width;
        capture_isp_param.memory_output_height = cam_context_p->memory_output_height = req_p->memory_output_height;
        capture_isp_param.memory_output_buffer_address = cam_context_p->memory_output_buffer_address = req_p->memory_output_buffer_address;
        capture_isp_param.memory_output_buffer_size = cam_context_p->memory_output_buffer_size = req_p->memory_output_buffer_size;
    #endif

    if (capture_isp_param.jpeg_gray_mode ==0)
    {
        /* color mode */
        capture_isp_param.y_address = cam_context_p->y_address =
            (kal_uint32) med_alloc_ext_mem(cam_context_p->channel_size);
        capture_isp_param.u_address = cam_context_p->u_address =
            (kal_uint32) med_alloc_ext_mem(cam_context_p->channel_size/4);
        capture_isp_param.v_address = cam_context_p->v_address =
            (kal_uint32) med_alloc_ext_mem(cam_context_p->channel_size/4);

        EXT_ASSERT ((capture_isp_param.y_address != NULL) &&
                    (capture_isp_param.u_address != NULL) &&
                    (capture_isp_param.v_address != NULL)
                    ,capture_isp_param.y_address 
                    ,capture_isp_param.u_address
                    ,capture_isp_param.v_address );

        capture_isp_param.y_size = cam_context_p->channel_size;
        capture_isp_param.u_size = cam_context_p->channel_size/4;
        capture_isp_param.v_size = cam_context_p->channel_size/4;
    }
    else
    {
        /* gray mode */
        capture_isp_param.y_address = cam_context_p->y_address =
            (kal_uint32) med_alloc_ext_mem(cam_context_p->channel_size);
        ASSERT (capture_isp_param.v_address != NULL);
        capture_isp_param.y_size = cam_context_p->channel_size;
        capture_isp_param.u_size = 0;
        capture_isp_param.v_size = 0;
    }

    #ifdef __MTK_TARGET__
        #if defined(__SW_JPEG_CODEC_SUPPORT__) && !defined(WIN32)
        {
            kal_uint32 stack_begin;
            med_get_med_int_stack_mem(&stack_begin);
            file_size = INT_SwitchStackToRun((void*)stack_begin,MED_INT_STACK_MEM_SIZE,(kal_func_ptr)camera_capture_jpeg_process, 1,&capture_isp_param);
            med_free_med_int_stack_mem();
        }
        #else
            file_size = camera_capture_jpeg_process(&capture_isp_param);
        #endif
    #endif

    return file_size;
#elif MT6228_SERIES

    /* ISP Setting */
    capture_isp_param.flash_mode = req_p->flash_mode;

    /* JPEG Setting */
    capture_isp_param.jpeg_yuv_mode = JPEG_FORMAT_YUV420;   /* req_p->jpeg_yuv_mode; */
    capture_isp_param.thumbnail_mode = KAL_FALSE;           /* req_p->thumbnail_mode; */
    capture_isp_param.thumbnail_width = req_p->thumbnail_width;
    capture_isp_param.thumbnail_height = req_p->thumbnail_height;
    /* IPP Setting */
    capture_isp_param.overlay_frame_mode = req_p->overlay_frame_mode;
    capture_isp_param.overlay_color_depth = req_p->overlay_color_depth;
    capture_isp_param.overlay_frame_source_key = req_p->overlay_frame_source_key;
    capture_isp_param.overlay_frame_width = req_p->overlay_frame_width;
    capture_isp_param.overlay_frame_height = req_p->overlay_frame_height;
    capture_isp_param.overlay_frame_buffer_address = req_p->overlay_frame_buffer_address;
    capture_isp_param.image_pitch_mode = KAL_FALSE;         /* req_p->image_pitch_mode; */
    capture_isp_param.image_data_format = req_p->image_data_format;
    capture_isp_param.image_pitch_bytes = req_p->image_pitch_bytes;
    /* Display Setting */
    capture_isp_param.lcd_id = req_p->lcd_id;
    capture_isp_param.lcm_start_x = req_p->lcm_start_x;
    capture_isp_param.lcm_start_y = req_p->lcm_start_y;
    capture_isp_param.lcm_end_x = req_p->lcm_end_x;
    capture_isp_param.lcm_end_y = req_p->lcm_end_y;
    capture_isp_param.roi_offset_x = req_p->roi_offset_x;
    capture_isp_param.roi_offset_y = req_p->roi_offset_y;
    capture_isp_param.update_layer = req_p->update_layer;
    capture_isp_param.hw_update_layer = req_p->hw_update_layer;
    capture_isp_param.display = req_p->display;
    capture_isp_param.frame_buffer_address = req_p->frame_buffer_address;
    capture_isp_param.frame_buffer_size = req_p->frame_buffer_size;
    capture_isp_param.tv_output = req_p->tv_output;
    capture_isp_param.tv_output_width = req_p->tv_output_width;
    capture_isp_param.tv_output_height = req_p->tv_output_height;
    capture_isp_param.tv_output_offset_x = req_p->tv_output_offset_x;
    capture_isp_param.tv_output_offset_y = req_p->tv_output_offset_y;
    capture_isp_param.tv_output_buffer1_address = req_p->tv_output_buffer1_address;
    capture_isp_param.tv_output_buffer2_address = req_p->tv_output_buffer2_address;
    capture_isp_param.tv_output_buffer_size = req_p->tv_output_buffer_size;
    capture_isp_param.snapshot_number = cam_context_p->snapshot_number;
    capture_isp_param.cam_capture_jpeg_cb = cam_capture_callback;
    if (cam_context_p->snapshot_number == 1)
    {
        capture_isp_param.jpeg_file_info = (isp_burst_capture_info_struct*) & cam_context_p->jpeg_file_info;
    }
    else
    {
        ASSERT(req_p->jpegs_p != NULL)
            capture_isp_param.jpeg_file_info = (isp_burst_capture_info_struct*) req_p->jpegs_p;
    }
    #ifdef __MTK_TARGET__
        #if defined(__SW_JPEG_CODEC_SUPPORT__) && !defined(WIN32)
        {
            kal_uint32 stack_begin;
            med_get_med_int_stack_mem(&stack_begin);
            file_size = INT_SwitchStackToRun((void*)stack_begin,MED_INT_STACK_MEM_SIZE,(kal_func_ptr)camera_capture_jpeg_process, 1,&capture_isp_param);
            med_free_med_int_stack_mem();
        }
        #else
            file_size = camera_capture_jpeg_process(&capture_isp_param);
        #endif
    #endif

    return 1;

#else /* MT6228_SERIES */

    #if !defined(MT6219)
        capture_isp_param.flash_mode = req_p->flash_mode;
    #endif

    #ifdef __MTK_TARGET__
        #if defined(__SW_JPEG_CODEC_SUPPORT__) && !defined(WIN32)
        {
            kal_uint32 stack_begin;
            med_get_med_int_stack_mem(&stack_begin);
            file_size = INT_SwitchStackToRun((void*)stack_begin,MED_INT_STACK_MEM_SIZE,(kal_func_ptr)camera_capture_jpeg_process, 1,&capture_isp_param);
            med_free_med_int_stack_mem();
        }
        #else
            file_size = camera_capture_jpeg_process(&capture_isp_param);
        #endif
    #endif

    return file_size;
#endif /* MT6228_SERIES */

}


/*****************************************************************************
 * FUNCTION
 *  cam_capture_from_layer
 * DESCRIPTION
 *  This function is to capture image from lcd layers to jpeg file.
 * PARAMETERS
 *  req_p       [?]
 *  ilm_struct *ilm_ptr(?)
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint32 cam_capture_from_layer(media_cam_capture_req_struct *req_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* step 1. get image from lcd layers to image buffer */
    if (cam_context_p->lcd_rotate == CAM_IMAGE_ROTATE_90 || cam_context_p->lcd_rotate == CAM_IMAGE_ROTATE_270)
    {
        capture_mem_param.target_width = req_p->image_height;
        capture_mem_param.target_height = req_p->image_width;
    }
    else
    {
        capture_mem_param.target_width = req_p->image_width;
        capture_mem_param.target_height = req_p->image_height;
    }
    capture_mem_param.intmem_start_address = cam_context_p->intmem_start_address =
        (kal_uint32) med_alloc_int_mem(cam_capture_mem[0]);
    capture_mem_param.intmem_size = cam_context_p->intmem_size = (kal_uint32) cam_capture_mem[0];
    capture_mem_param.extmem_start_address = 0;
    capture_mem_param.extmem_size = 0;
    capture_mem_param.imgdma_buffer_size = cam_context_p->frame_buffer_size;
    capture_mem_param.imgdma_buffer_address = (kal_uint32) cam_context_p->frame_buffer_p;
    capture_mem_param.block_mode = 0;
    /* for lcd if */
    capture_mem_param.dest_buffer_size = req_p->image_width * req_p->image_height * 2;
    capture_mem_param.dest_buffer_address = cam_context_p->extmem_start_address =
        (kal_uint32) med_alloc_ext_mem(capture_mem_param.dest_buffer_size);
    capture_mem_param.roi_offset_x = req_p->roi_offset_x;
    capture_mem_param.roi_offset_y = req_p->roi_offset_y;
    capture_mem_param.roi_width = req_p->image_width;
    capture_mem_param.roi_height = req_p->image_height;
    capture_mem_param.update_layer = req_p->capture_layer;
    capture_mem_param.hw_update_layer = cam_context_p->hw_update_layer;
#if MT6228_SERIES
    /* */
    capture_mem_param.manual_wb = req_p->manual_wb;
    /* IPP Setting */
    capture_mem_param.overlay_frame_mode = req_p->overlay_frame_mode;
    capture_mem_param.overlay_color_depth = req_p->overlay_color_depth;
    capture_mem_param.overlay_frame_source_key = req_p->overlay_frame_source_key;
    capture_mem_param.overlay_frame_width = req_p->overlay_frame_width;
    capture_mem_param.overlay_frame_height = req_p->overlay_frame_height;
    capture_mem_param.overlay_frame_buffer_address = req_p->overlay_frame_buffer_address;
    capture_mem_param.image_pitch_mode = KAL_FALSE; /* req_p->image_pitch_mode; */
    capture_mem_param.image_data_format = req_p->image_data_format;
    capture_mem_param.image_pitch_bytes = req_p->image_pitch_bytes;
    /* Display Setting */
    capture_mem_param.roi_offset_x = req_p->roi_offset_x;
    capture_mem_param.roi_offset_y = req_p->roi_offset_y;
    capture_mem_param.update_layer = req_p->update_layer;
    capture_mem_param.hw_update_layer = req_p->hw_update_layer;
#endif /* MT6228_SERIES */
    /* capture */
#ifdef __MTK_TARGET__
    camera_capture_mem_process(&capture_mem_param);
#endif
    /* free internal mem for capture */
    CAM_FREE_INT_BUFFER();

    /* if manual_wb equals TRUE, call camera_mwb_process then return */
#if (MT6228_SERIES)
    if (capture_mem_param.manual_wb)
    {
        camera_mwb_process_struct mwb_para;

        mwb_para.mwb_buffer_address = capture_mem_param.dest_buffer_address;
        mwb_para.mwb_image_height = capture_mem_param.target_width;
        mwb_para.mwb_image_width = capture_mem_param.target_height;
        camera_mwb_process(&mwb_para);
        return 0;
    }
#endif /* (MT6228_SERIES) */
    /* step 2. encode image buffer to file */

#if MT6225_SERIES
	jpg_encode.input_type					=IMAGE_FORMAT_RGB565;
	jpg_encode.output_type					=IMAGE_FORMAT_YUV420;
    {

        kal_uint32 img_width ,img_height;

        img_width = (req_p->image_width%16==0)? req_p->image_width : 16 - (req_p->image_width%16) + req_p->image_width;
        img_height = (req_p->image_height%16==0)? req_p->image_height : 16 - (req_p->image_height%16) + req_p->image_height;
        cam_context_p->channel_size = img_width*img_height;


        /* color mode */
        cam_context_p->y_address = (kal_uint32) med_alloc_ext_mem(cam_context_p->channel_size);
        cam_context_p->u_address = (kal_uint32) med_alloc_ext_mem(cam_context_p->channel_size/4);
        cam_context_p->v_address = (kal_uint32) med_alloc_ext_mem(cam_context_p->channel_size/4);
        jpg_encode.jpeg_yuv_data[0] = (kal_uint8*) cam_context_p->y_address;
        jpg_encode.jpeg_yuv_data[1] = (kal_uint8*) cam_context_p->u_address;
        jpg_encode.jpeg_yuv_data[2] = (kal_uint8*) cam_context_p->v_address;

        jpg_encode.jpeg_yuv_size[0] = cam_context_p->channel_size;
        jpg_encode.jpeg_yuv_size[1] = cam_context_p->channel_size/4;
        jpg_encode.jpeg_yuv_size[2] = cam_context_p->channel_size/4;

   }
    jpg_encode.image_buffer_address = capture_mem_param.dest_buffer_address;
#else
    jpg_encode.type = IBR1_TYPE_RGB565;
    jpg_encode.data_order = IBR1_ORDER_RGB888;
    jpg_encode.extmem_size = img_context_p->extmem_size = MAX_IMG_ENC_EXT_MEM_SIZE;
    if (MAX_IMG_ENC_EXT_MEM_SIZE > 0)
    {
        jpg_encode.extmem_start_address = img_context_p->extmem_start_address =
            (kal_uint32) med_alloc_ext_mem(MAX_IMG_ENC_EXT_MEM_SIZE);
    }
    else
    {
        jpg_encode.extmem_start_address = img_context_p->extmem_start_address = 0;
    }
    jpg_encode.target_width = req_p->image_width;
    jpg_encode.target_height = req_p->image_height;
    jpg_encode.jpeg_gray_mode = 0;
    jpg_encode.jpeg_encode_cb = cam_img_encode_callback;
    jpg_encode.image_buffer_address = (kal_uint32) cam_context_p->extmem_start_address;
#endif


    jpg_encode.intmem_size = img_context_p->intmem_size = MAX_IMG_ENC_INT_MEM_SIZE;
    if (MAX_IMG_ENC_INT_MEM_SIZE > 0)
    {
        jpg_encode.intmem_start_address = img_context_p->intmem_start_address =
            (kal_uint32) med_alloc_int_mem(MAX_IMG_ENC_INT_MEM_SIZE);
    }
    else
    {
        jpg_encode.intmem_start_address = img_context_p->intmem_start_address = 0;
    }

    jpg_encode.image_width = req_p->image_width;
    jpg_encode.image_height = req_p->image_height;
    jpg_encode.image_quality = req_p->image_quality;
    jpg_encode.jpeg_file_start_address = (kal_uint32) cam_context_p->capture_buffer_p;
    jpg_encode.jpeg_file_buffer_size = MAX_IMG_ENC_FILE_BUFFER_LEN * cam_context_p->snapshot_number;

#if MT6228_SERIES

    /* JPEG Setting */
    jpg_encode.jpeg_yuv_mode = JPEG_FORMAT_YUV420;  /* req_p->jpeg_yuv_mode; */
    jpg_encode.thumbnail_mode = KAL_FALSE;          /* req_p->thumbnail_mode; */
    jpg_encode.thumbnail_width = req_p->thumbnail_width;
    jpg_encode.thumbnail_height = req_p->thumbnail_height;
    /* IPP Setting */
    jpg_encode.overlay_frame_mode = KAL_FALSE;      /* req_p->overlay_frame_mode; */
    jpg_encode.overlay_color_depth = req_p->overlay_color_depth;
    jpg_encode.overlay_frame_source_key = req_p->overlay_frame_source_key;
    jpg_encode.overlay_frame_width = req_p->overlay_frame_width;
    jpg_encode.overlay_frame_height = req_p->overlay_frame_height;
    jpg_encode.overlay_frame_buffer_address = req_p->overlay_frame_buffer_address;
#endif /* MT6228_SERIES */

#ifdef __MTK_TARGET__
    #if defined(__SW_JPEG_CODEC_SUPPORT__) && !defined(WIN32)
    {
        kal_uint32 stack_begin;
        med_get_med_int_stack_mem(&stack_begin);
        img_context_p->file_size = INT_SwitchStackToRun((void*)stack_begin,MED_INT_STACK_MEM_SIZE,(kal_func_ptr)jpeg_encode_process, 1,&jpg_encode);
        med_free_med_int_stack_mem();
    }
    #else
    {
        img_context_p->file_size = jpeg_encode_process(&jpg_encode);
    }
    #endif

    exit_jpeg_encode_process();
#endif /* __MTK_TARGET__ */
    if (img_context_p->intmem_start_address)
    {
        med_free_int_mem((void **)&img_context_p->intmem_start_address);
    }

    return img_context_p->file_size;

}


/*****************************************************************************
 * FUNCTION
 *  cam_capture_req_hdlr
 * DESCRIPTION
 *  This function is to handle camera capture request.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void cam_capture_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_capture_req_struct *req_p;
    kal_int32 result;
    kal_uint32 file_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_context_p->src_mod = ilm_ptr->src_mod_id;

    req_p = (media_cam_capture_req_struct*) ilm_ptr->local_para_ptr;

    #if defined(XENON_FLASHLIGHT) || defined(XENON_FLASHLIGHT_ANTI_RED_EYE)
    if (cam_context_p->xenon_flash_status != CAM_XENON_FLASH_OFF)
        med_stop_timer(CAM_XENON_FLASH_CHECK_TIMER);
    #endif

    if (CAM_IN_STATE(CAM_READY) || CAM_IN_STATE(CAM_PREVIEW))
    {
        cam_context_p->media_mode = req_p->media_mode;
        cam_context_p->continue_capture = req_p->continue_capture;
#ifdef BARCODE_SUPPORT
        CAM_FREE_CAPTURE_BUFFER();
#endif
        if (req_p->media_mode == MED_MODE_FILE)
        {
            kal_uint32 file_buffer_size;

            /* stop prevew before capture */
        #ifdef __MTK_TARGET__
            exit_camera_preview_process();
        #endif
            if (cam_context_p->int_frame_buffer_p)
            {
                memcpy(
                    (kal_uint8*) cam_context_p->frame_buffer_p,
                    (kal_uint8*) cam_context_p->int_frame_buffer_p,
                    cam_context_p->frame_buffer_size);
            }

            cam_release_memory();

            cam_context_p->snapshot_number = req_p->snapshot_number;
            cam_context_p->source_device = req_p->source_device;
            if (req_p->source_device == CAM_SRC_ISP)
            {
                file_buffer_size = MAX_CAM_FILE_BUFFER_LEN;
            }
            else
            {
                file_buffer_size = MAX_IMG_ENC_FILE_BUFFER_LEN * cam_context_p->snapshot_number;
            }

            if ((result = cam_open_image_file((kal_wchar*) req_p->data, file_buffer_size)) == MED_RES_OK)
            {
                if (req_p->source_device == CAM_SRC_ISP)
                {
                    file_size = cam_capture_from_isp(req_p);
                #if MT6228_SERIES
                    CAM_ENTER_STATE(CAM_CAPTURE);
                    if (cam_context_p->snapshot_number > 1)
                    {
                        ASSERT(req_p->media_mode == MED_MODE_FILE && cam_context_p->snapshot_number == 1);
                        /* if single shot, use blocking mode */
                        CAM_SET_EVENT(CAM_EVT_CAPTURE);
                    }
                #else /* MT6228_SERIES */ 
                    /* close image file */
                    result = cam_close_image_file(file_size);
                    cam_set_result(result);
                    cam_release_memory();
                #if defined(AF_SUPPORT)
                    if (cam_context_p->continue_capture == KAL_FALSE && cam_context_p->af_mode != CAM_AF_MANUAL_MODE)
                    {
                        camera_operation_setting((kal_uint8) CAM_AF_KEY, (kal_uint16) CAM_AF_RELEASE);
                    }
                #endif /* defined(AF_SUPPORT) */

                    CAM_ENTER_STATE(CAM_READY);
                    CAM_SET_EVENT(CAM_EVT_CAPTURE);
                #endif /* MT6228_SERIES */
                }
                else if (req_p->source_device == CAM_SRC_MEM)
                {

                    file_size = cam_capture_from_layer(req_p);
                #if MT6228_SERIES
                    CAM_ENTER_STATE(CAM_CAPTURE);
                    if (cam_context_p->snapshot_number > 1)
                    {
                        ASSERT(req_p->media_mode == MED_MODE_FILE && cam_context_p->snapshot_number == 1);
                    }
                    else
                    {
                        cam_release_memory();
                        img_release_memory();
                        jfif_thumbnail_swap((kal_uint32) cam_context_p->capture_buffer_p);
                        result = cam_close_image_file(file_size);
                        cam_set_result(result);
                        CAM_ENTER_STATE(CAM_READY);
                        CAM_SET_EVENT(CAM_EVT_CAPTURE);
                    }

                #else /* MT6228_SERIES */
                    cam_release_memory();
                    img_release_memory();
                    result = cam_close_image_file(file_size);
                    cam_set_result(result);
                #if defined(AF_SUPPORT)
                    if (cam_context_p->continue_capture == KAL_FALSE && cam_context_p->af_mode != CAM_AF_MANUAL_MODE)
                    {
                        camera_operation_setting((kal_uint8) CAM_AF_KEY, (kal_uint16) CAM_AF_RELEASE);
                    }
                #endif /* defined(AF_SUPPORT) */
                    CAM_ENTER_STATE(CAM_READY);
                    CAM_SET_EVENT(CAM_EVT_CAPTURE);
                #endif /* MT6228_SERIES */
                }
                else
                {
                    ASSERT(req_p->source_device == CAM_SRC_ISP || req_p->source_device == CAM_SRC_MEM);
                    cam_set_result(MED_RES_ERROR);
                    CAM_ENTER_STATE(CAM_READY);
                    CAM_SET_EVENT(CAM_EVT_CAPTURE);
                }
            }
            else
            {
                cam_set_result(result);
                CAM_ENTER_STATE(CAM_READY);
                CAM_SET_EVENT(CAM_EVT_CAPTURE);
            }

        }
        else if (req_p->media_mode == MED_MODE_ARRAY)
        {
            /* stop prevew before capture */
        #ifdef __MTK_TARGET__
            exit_camera_preview_process();
        #endif
            if (cam_context_p->int_frame_buffer_p)
            {
                memcpy(
                    (kal_uint8*) cam_context_p->frame_buffer_p,
                    (kal_uint8*) cam_context_p->int_frame_buffer_p,
                    cam_context_p->frame_buffer_size);
            }

            cam_release_memory();

            cam_context_p->snapshot_number = req_p->snapshot_number;
            cam_context_p->source_device = req_p->source_device;

            if (req_p->data != NULL && req_p->file_buffer_len > 0)
            {
                cam_context_p->capture_buffer_p = (kal_uint32) req_p->data;

                if (req_p->source_device == CAM_SRC_ISP)
                {
                    file_size = cam_capture_from_isp(req_p);
                    cam_context_p->capture_buffer_p = 0;
                #if MT6228_SERIES
                    cam_context_p->file_size_p = req_p->file_size_p;
                    CAM_ENTER_STATE(CAM_CAPTURE);
                    if (cam_context_p->snapshot_number > 1)
                    {
                        /* if single shot, use blocking mode */
                        CAM_SET_EVENT(CAM_EVT_CAPTURE);
                    }
                #else /* MT6228_SERIES */ 

                    *req_p->file_size_p = file_size;
                    /* close image fie */
                    cam_set_result(MED_RES_OK);
                    cam_release_memory();
                #if defined(AF_SUPPORT)
                    if (cam_context_p->continue_capture == KAL_FALSE && cam_context_p->af_mode != CAM_AF_MANUAL_MODE)
                    {
                        camera_operation_setting((kal_uint8) CAM_AF_KEY, (kal_uint16) CAM_AF_RELEASE);
                    }
                #endif /* defined(AF_SUPPORT) */
                    CAM_ENTER_STATE(CAM_READY);
                    CAM_SET_EVENT(CAM_EVT_CAPTURE);
                #endif /* MT6228_SERIES */
                }
                else if (req_p->source_device == CAM_SRC_MEM)
                {
                    file_size = cam_capture_from_layer(req_p);
                    cam_context_p->capture_buffer_p = 0;
                #if MT6228_SERIES
                    CAM_ENTER_STATE(CAM_CAPTURE);
                    if (cam_context_p->snapshot_number > 1)
                    {
                        cam_context_p->jpeg_file_info_p = (jpegs_struct*) req_p->jpegs_p;
                        cam_context_p->jpeg_file_info_p->file_address[0] = cam_context_p->capture_buffer_p;
                        cam_context_p->jpeg_file_info_p->file_size[0] = img_context_p->file_size;
                        /* update buffer address and size for next shot */
                        jpg_encode.jpeg_file_start_address =
                            (kal_uint32) (cam_context_p->capture_buffer_p + img_context_p->file_size);
                        jpg_encode.jpeg_file_buffer_size -= img_context_p->file_size;
                        /* free internal mem for jpeg encode */
                        if (img_context_p->intmem_start_address)
                        {
                            med_free_int_mem((void **)&img_context_p->intmem_start_address);
                        }
                        CAM_SET_EVENT(CAM_EVT_CAPTURE);
                        cam_send_event_ind(CAM_EVT_CAPTURE, 1);

                    }
                    else
                    {
                        cam_release_memory();
                        img_release_memory();
                        jfif_thumbnail_swap((kal_uint32) cam_context_p->capture_buffer_p);
                        *req_p->file_size_p = img_context_p->file_size;
                        cam_set_result(MED_RES_OK);
                        CAM_ENTER_STATE(CAM_READY);
                        CAM_SET_EVENT(CAM_EVT_CAPTURE);
                    }

                #else /* MT6228_SERIES */
                    cam_release_memory();
                    img_release_memory();

                    *req_p->file_size_p = img_context_p->file_size;
                    cam_set_result(MED_RES_OK);
                #if defined(AF_SUPPORT)
                    if (cam_context_p->continue_capture == KAL_FALSE && cam_context_p->af_mode != CAM_AF_MANUAL_MODE)
                    {
                        camera_operation_setting((kal_uint8) CAM_AF_KEY, (kal_uint16) CAM_AF_RELEASE);
                    }
                #endif /* defined(AF_SUPPORT) */
                    CAM_ENTER_STATE(CAM_READY);
                    CAM_SET_EVENT(CAM_EVT_CAPTURE);
                #endif /* MT6228_SERIES */
                }
                else
                {
                    cam_set_result(MED_RES_ERROR);
                    CAM_ENTER_STATE(CAM_READY);
                    CAM_SET_EVENT(CAM_EVT_CAPTURE);
                }
            }
            else
            {
                cam_set_result(MED_RES_PARAM_ERROR);
                CAM_ENTER_STATE(CAM_READY);
                CAM_SET_EVENT(CAM_EVT_CAPTURE);
            }
        }
        else if (req_p->media_mode == MED_MODE_BUFFER)
        {
            kal_uint32 file_buffer_size;

            /* stop prevew before capture */
        #ifdef __MTK_TARGET__
            exit_camera_preview_process();
        #endif
            if (cam_context_p->int_frame_buffer_p)
            {
                memcpy(
                    (kal_uint8*) cam_context_p->frame_buffer_p,
                    (kal_uint8*) cam_context_p->int_frame_buffer_p,
                    cam_context_p->frame_buffer_size);
            }

            cam_release_memory();

            cam_context_p->snapshot_number = req_p->snapshot_number;
            cam_context_p->source_device = req_p->source_device;

            if (req_p->source_device == CAM_SRC_ISP)
            {
                file_buffer_size = MAX_CAM_FILE_BUFFER_LEN;
            }
            else
            {
                file_buffer_size = MAX_IMG_ENC_FILE_BUFFER_LEN * cam_context_p->snapshot_number;
            }

            CAM_FREE_CAPTURE_BUFFER();
            cam_context_p->capture_buffer_p = (kal_uint32) med_alloc_ext_mem(file_buffer_size);
            if (cam_context_p->capture_buffer_p != NULL)
            {
                if (req_p->source_device == CAM_SRC_ISP)
                {
                    file_size = cam_capture_from_isp(req_p);
                #if MT6228_SERIES
                    CAM_ENTER_STATE(CAM_CAPTURE);
                    if (cam_context_p->snapshot_number > 1)
                    {
                        /* if single shot, use blocking mode */
                        CAM_SET_EVENT(CAM_EVT_CAPTURE);
                    }
                    else
                    {
                        *req_p->capture_buffer_p = (void*)cam_context_p->capture_buffer_p;
                        cam_context_p->file_size_p = req_p->file_size_p;
                    }
                #else /* MT6228_SERIES */

                    *req_p->file_size_p = file_size;
                    *req_p->capture_buffer_p = (void*)cam_context_p->capture_buffer_p;
                    /* close image fie */
                    cam_set_result(MED_RES_OK);
                    cam_release_memory();
                #if defined(AF_SUPPORT)
                    if (cam_context_p->continue_capture == KAL_FALSE && cam_context_p->af_mode != CAM_AF_MANUAL_MODE)
                    {
                        camera_operation_setting((kal_uint8) CAM_AF_KEY, (kal_uint16) CAM_AF_RELEASE);
                    }
                #endif /* defined(AF_SUPPORT) */
                    CAM_ENTER_STATE(CAM_READY);
                    CAM_SET_EVENT(CAM_EVT_CAPTURE);
                #endif /* MT6228_SERIES */
                }
                else if (req_p->source_device == CAM_SRC_MEM)
                {

                    file_size = cam_capture_from_layer(req_p);
                #if MT6228_SERIES
                    CAM_ENTER_STATE(CAM_CAPTURE);
                    if (cam_context_p->snapshot_number > 1)
                    {
                        cam_context_p->jpeg_file_info_p = (jpegs_struct*) req_p->jpegs_p;
                        cam_context_p->jpeg_file_info_p->file_address[0] = cam_context_p->capture_buffer_p;
                        cam_context_p->jpeg_file_info_p->file_size[0] = img_context_p->file_size;
                        /* update buffer address and size for next shot */
                        jpg_encode.jpeg_file_start_address =
                            (kal_uint32) (cam_context_p->capture_buffer_p + img_context_p->file_size);
                        jpg_encode.jpeg_file_buffer_size -= img_context_p->file_size;
                        /* free internal mem for jpeg encode */
                        if (img_context_p->intmem_start_address)
                        {
                            med_free_int_mem((void **)&img_context_p->intmem_start_address);
                        }
                        CAM_SET_EVENT(CAM_EVT_CAPTURE);
                        cam_send_event_ind(CAM_EVT_CAPTURE, 1);

                    }
                    else
                    {
                        cam_release_memory();
                        img_release_memory();
                        jfif_thumbnail_swap((kal_uint32) cam_context_p->capture_buffer_p);

                        if (!req_p->manual_wb)
                        {
                            *req_p->file_size_p = img_context_p->file_size;
                            *req_p->capture_buffer_p = (void*)cam_context_p->capture_buffer_p;
                        }

                        cam_set_result(MED_RES_OK);
                        CAM_ENTER_STATE(CAM_READY);
                        CAM_SET_EVENT(CAM_EVT_CAPTURE);
                    }

                #else /* MT6228_SERIES */
                    cam_release_memory();
                    img_release_memory();

                    *req_p->file_size_p = img_context_p->file_size;
                    *req_p->capture_buffer_p = (void*)cam_context_p->capture_buffer_p;
                    cam_set_result(MED_RES_OK);
                #if defined(AF_SUPPORT)
                    if (cam_context_p->continue_capture == KAL_FALSE && cam_context_p->af_mode != CAM_AF_MANUAL_MODE)
                    {
                        camera_operation_setting((kal_uint8) CAM_AF_KEY, (kal_uint16) CAM_AF_RELEASE);
                    }
                #endif /* defined(AF_SUPPORT) */
                    CAM_ENTER_STATE(CAM_READY);
                    CAM_SET_EVENT(CAM_EVT_CAPTURE);
                #endif /* MT6228_SERIES */
                }
                else
                {
                    cam_set_result(MED_RES_ERROR);
                    CAM_ENTER_STATE(CAM_READY);
                    CAM_SET_EVENT(CAM_EVT_CAPTURE);
                }
            }
            else
            {
                ASSERT(cam_context_p->capture_buffer_p);
                cam_set_result(MED_RES_MEM_INSUFFICIENT);
                CAM_SET_EVENT(CAM_EVT_CAPTURE);
            }
        }
        else
        {
            cam_set_result(MED_RES_INVALID_FORMAT);
            CAM_SET_EVENT(CAM_EVT_CAPTURE);
        }
    }
    else
    {
        cam_set_result(MED_RES_BUSY);
        CAM_SET_EVENT(CAM_EVT_CAPTURE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  cam_set_param_req_hdlr
 * DESCRIPTION
 *  This function is to handle camera set parameter request.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void cam_set_param_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_set_param_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_context_p->src_mod = ilm_ptr->src_mod_id;

    req_p = (media_cam_set_param_req_struct*) ilm_ptr->local_para_ptr;

    if (CAM_IN_STATE(CAM_PREVIEW) || CAM_IN_STATE(CAM_CAPTURE) || CAM_IN_STATE(CAM_CAPTURE_BARCODE)
    #if defined(__MED_VID_ENC_MOD__) || defined(__MED_MJPG_ENC_MOD__)
        || VID_IN_STATE(VID_PREVIEW) || VID_IN_STATE(VID_RECORD) || VID_IN_STATE(VID_RECORD_PAUSED)
    #endif 
    #ifdef __MED_VCALL_MOD__
        || media_vall_is_cam_able_to_update_para()
    #endif
        )
    {
        if (req_p->param_id >= CAM_PARAM_ZOOM_FACTOR && req_p->param_id <= CAM_PARAM_EV_VALUE)
        {
            camera_image_setting((kal_uint8) req_p->param_id, (kal_uint16) req_p->value);
        }
    #if (MT6228_SERIES || MT6225_SERIES || (MT6219_SERIES&&!defined(MT6219)))
        else
        {
            kal_uint32 param_id = 255;

            switch (req_p->param_id)
            {
                case CAM_PARAM_ISO:
                    param_id = CAM_ISO;
                    cam_context_p->iso_setting = req_p->value;

                    if (cam_context_p->iso_setting == CAM_ISO_AUTO)
                    {
                        cam_context_p->dsc_mode = cam_context_p->prev_dsc_mode;
                        camera_operation_setting(CAM_DSC_MODE, cam_context_p->dsc_mode);
                    }
                    else
                    {
                        if (cam_context_p->af_mode == CAM_AF_AUTO_MODE)
                        {
                            camera_operation_setting(CAM_AF_MODE, CAM_AF_AUTO_MODE);
                        }
                        else if (cam_context_p->af_mode == CAM_AF_MACRO_MODE)
                        {
                            camera_operation_setting(CAM_AF_MODE, CAM_AF_MACRO_MODE);
                        }

                        /* SPECIAL CASE!  SET ISO VALUE FIRST, THEN SET DSC MODE TO ISO */
                        if (cam_context_p->dsc_mode != CAM_ISO_MODE)
                        {
                            cam_context_p->prev_dsc_mode = cam_context_p->dsc_mode;
                            cam_context_p->dsc_mode = CAM_ISO_MODE;
                            camera_operation_setting((kal_uint8) param_id, (kal_uint16) req_p->value);
                            camera_operation_setting(CAM_DSC_MODE, CAM_ISO_MODE);                            
                            CAM_SET_EVENT(CAM_EVT_SET_PARAM);
                            return;
                        }                        
                    }
                    break;
                case CAM_PARAM_AF_KEY:
                    param_id = CAM_AF_KEY;
                    break;
                case CAM_PARAM_AF_MODE:
                    param_id = CAM_AF_MODE;
                    cam_context_p->af_mode = req_p->value;
                    break;
                case CAM_PARAM_AF_METERING:
                    param_id = CAM_AF_METERING;
                    break;
                case CAM_PARAM_DSC_MODE:
                    param_id = CAM_DSC_MODE;                    
                    cam_context_p->prev_dsc_mode = cam_context_p->dsc_mode = req_p->value;
                    // adjust AF and ISO only in Camera Mode.
                    if (CAM_IN_STATE(CAM_PREVIEW) || CAM_IN_STATE(CAM_CAPTURE))
                    {
                        /* if dsc mode != night and iso != auto, apply af mode then iso setting */
                        if (req_p->value != CAM_NIGHTSCENE && cam_context_p->iso_setting != CAM_ISO_AUTO)
                        {
                            if (req_p->value == CAM_FLOWER) // MACRO MODE
                            {
                                cam_context_p->af_mode = CAM_AF_MACRO_MODE;
                                camera_operation_setting(CAM_AF_MODE, CAM_AF_MACRO_MODE);
                            }
                            else
                            {
                                cam_context_p->af_mode = CAM_AF_AUTO_MODE;
                                camera_operation_setting(CAM_AF_MODE, CAM_AF_AUTO_MODE);
                            }                            
                            camera_operation_setting(CAM_ISO, cam_context_p->iso_setting);                      
                            cam_context_p->dsc_mode = req_p->value = CAM_ISO_MODE;
                        }
                        else if (req_p->value != CAM_FLOWER)
                        {
                            cam_context_p->af_mode = CAM_AF_AUTO_MODE;
                            camera_operation_setting(CAM_AF_MODE, CAM_AF_AUTO_MODE);
                        }
                    }
                    break;
                case CAM_PARAM_AE_METERING:
                    param_id = CAM_AE_METERING;
                    break;
                case CAM_PARAM_MANUAL_FOCUS_DIR:
                    param_id = CAM_MANUAL_FOCUS_DIR;
                    break;
                case CAM_PARAM_FLASH:
                    /* XENON FLASHLIGHT NOT USE camera_operation_setting interface */
                    #if defined(XENON_FLASHLIGHT) || defined(XENON_FLASHLIGHT_ANTI_RED_EYE)
                        if (req_p->value == CAM_FLASH_OFF)
                        {
                            cam_turn_off_xenonflash();
                        }
                        else if (cam_context_p->xenon_flash_status == CAM_XENON_FLASH_OFF)
                        {
                            uem_bmt_struct bmt_status;
                            uem_get_bat_status(&bmt_status);
                            /* tmp solution for EVB */
                            if (bmt_status.volt <= 0)
                                bmt_status.volt = 3700;
                            
                            if (bmt_status.volt < 3400)
                            {
                                cam_send_xenon_flash_status_ind(CAM_XENON_FLASH_LOW_BATTERY);
                            }                
                            else if(cam_turn_on_xenonflash()!=MED_RES_OK)
                                ASSERT(0);
                        }
                    #endif /* #if defined(XENON_FLASHLIGHT) || defined(XENON_FLASHLIGHT_ANTI_RED_EYE) */
                    param_id = CAM_FLASH_MODE;
                    break;
                default:
                    ASSERT(0);
                    break;
            }

            camera_operation_setting((kal_uint8) param_id, (kal_uint16) req_p->value);
        }
    #endif /* MT6228_SERIES || MT6225_SERIES || (MT6219_SERIES&&!defined(MT6219)) */ 
    }
    else
    {
        cam_set_result(MED_RES_FAIL);
    }

    CAM_SET_EVENT(CAM_EVT_SET_PARAM);

}


/*****************************************************************************
 * FUNCTION
 *  cam_mwb_op_req_hdlr
 * DESCRIPTION
 *  This function is to handle camera mwb require.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void cam_mwb_op_req_hdlr(ilm_struct *ilm_ptr)
{
#if MT6228_SERIES
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_mwb_operation_req_struct *ind_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p = (media_cam_mwb_operation_req_struct*) ilm_ptr->local_para_ptr;
    switch (ind_p->op_type)
    {
        case CAM_MWB_ADJUST:
        {
            camera_mwb_process_struct mwb_para;

            mwb_para.mwb_buffer_address = ind_p->pmwb->mwb_buffer_address;
            mwb_para.mwb_image_height = ind_p->pmwb->mwb_image_height;
            mwb_para.mwb_image_width = ind_p->pmwb->mwb_image_width;
            camera_mwb_process(&mwb_para);
        }
            break;
        case CAM_MWB_BACKUP:
            backup_mwb_setting();
            break;
        case CAM_MWB_RESTORE:
            restore_mwb_setting();
            break;
        default:
            ASSERT(0) break;
    }
#endif /* MT6228_SERIES */
    CAM_SET_EVENT(CAM_EVT_MWB_OP);
}


/*****************************************************************************
 * FUNCTION
 *  cam_set_overlay_palette_req_hdlr
 * DESCRIPTION
 *  This function is to handle set overlay palette request.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void cam_set_overlay_palette_req_hdlr(ilm_struct *ilm_ptr)
{
#if (MT6228_SERIES)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_set_overlay_palette_req_struct *msg_p =
        (media_cam_set_overlay_palette_req_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_overlay_palette(msg_p->palette_size, msg_p->palette_addr);
#endif /* MT6228_SERIES */
    CAM_SET_EVENT(CAM_EVT_SET_PAL);
}


/*****************************************************************************
 * FUNCTION
 *  cam_event_ind_hdlr
 * DESCRIPTION
 *  This function is to handle camera event indication.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void cam_event_ind_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_event_ind_struct *ind_p;
    kal_int32 result = MED_RES_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p = (media_cam_event_ind_struct*) ilm_ptr->local_para_ptr;

    if ((ind_p->event == CAM_EVT_PREVIEW) &&
        (CAM_IN_STATE(CAM_READY) || CAM_IN_STATE(CAM_PREVIEW) || CAM_IN_STATE(CAM_CAPTURE_BARCODE) ||
         (FACTORY_BOOT == stack_query_boot_mode())
    #ifdef __MED_VID_ENC_MOD__
         || VID_IN_STATE(VID_PREVIEW)
    #endif
        ))
    {
        /* auto adjust exposue value and white balance */
    #if defined(__MTK_TARGET__) && !defined(YUV_SENSOR_SUPPORT)
        ae_awb_main();
    #endif
    }
#ifdef __MED_WEBCAM_MOD__
    else if ((ind_p->event == CAM_EVT_PREVIEW) && (WEBCAM_IN_STATE(WEBCAM_PREVIEW)))
    {
        /* auto adjust exposue value and white balance */
    #if defined(__MTK_TARGET__) && !defined(YUV_SENSOR_SUPPORT)
        ae_awb_main();
    #endif
    }
#endif /* __MED_WEBCAM_MOD__ */
    else if ((ind_p->event == CAM_EVT_CAPTURE) && CAM_IN_STATE(CAM_CAPTURE))
    {
        if (cam_context_p->source_device == CAM_SRC_ISP)
        {
            if (ind_p->cause == JPEG_ENCODE_BUFFER_FULL)
            {
                if (cam_context_p->snapshot_number == 1)
                {
                    /* if single shot, use blocking mode */
                    cam_set_result(MED_RES_BUFFER_INSUFFICIENT);
                    CAM_SET_EVENT(CAM_EVT_CAPTURE);
                }
                else
                {
                    cam_send_capture_event_ind(MED_RES_BUFFER_INSUFFICIENT, 0);
                }
                stop_camera_capture_process();
                cam_release_memory();
                CAM_ENTER_STATE(CAM_READY);
            }
            else
            {
                if (cam_context_p->snapshot_number == 1)
                {
                    /* if single shot, use blocking mode */
                    if (cam_context_p->media_mode == MED_MODE_FILE)
                    {
                        result = cam_close_image_file(cam_context_p->jpeg_file_info.file_size[0]);
                    }
                    else if (cam_context_p->media_mode == MED_MODE_ARRAY)
                    {
                        *cam_context_p->file_size_p = cam_context_p->jpeg_file_info.file_size[0];
                    }
                    else if (cam_context_p->media_mode == MED_MODE_BUFFER)
                    {
                        *cam_context_p->file_size_p = cam_context_p->jpeg_file_info.file_size[0];
                    }
                    cam_set_result(result);
                    CAM_SET_EVENT(CAM_EVT_CAPTURE);
                }
                else
                {
                    cam_send_capture_event_ind(MED_RES_OK, (kal_uint16) ind_p->cause);
                }
                if (ind_p->cause >= cam_context_p->snapshot_number)
                {
                    stop_camera_capture_process();
                    cam_release_memory();
                    CAM_ENTER_STATE(CAM_READY);
                }
            }
        }
        else
        {
            kal_uint8 shot_count;

            shot_count = ind_p->cause;
            /* step 1. get image from lcd layers to image buffer */
            capture_mem_param.intmem_start_address = cam_context_p->intmem_start_address =
                (kal_uint32) med_alloc_int_mem(cam_capture_mem[0]);
            capture_mem_param.intmem_size = cam_context_p->intmem_size = (kal_uint32) cam_capture_mem[0];
        #ifdef __MTK_TARGET__
            camera_capture_mem_process(&capture_mem_param);
        #endif
            /* free internal mem for capture */
            if (cam_context_p->intmem_start_address)
            {
                med_free_int_mem((void **)&cam_context_p->intmem_start_address);
            }

            /* step 2. encode image buffer to file */

            jpg_encode.intmem_size = img_context_p->intmem_size = MAX_IMG_ENC_INT_MEM_SIZE;
            if (MAX_IMG_ENC_INT_MEM_SIZE > 0)
            {
                jpg_encode.intmem_start_address = img_context_p->intmem_start_address =
                    (kal_uint32) med_alloc_int_mem(MAX_IMG_ENC_INT_MEM_SIZE);
            }
            else
            {
                jpg_encode.intmem_start_address = img_context_p->intmem_start_address = 0;
            }

        #ifdef __MTK_TARGET__
            #if defined(__SW_JPEG_CODEC_SUPPORT__) && !defined(WIN32)
            {
                kal_uint32 stack_begin;
                med_get_med_int_stack_mem(&stack_begin);
                img_context_p->file_size = INT_SwitchStackToRun((void*)stack_begin,MED_INT_STACK_MEM_SIZE,(kal_func_ptr)jpeg_encode_process, 1,&jpg_encode);
                med_free_med_int_stack_mem();
            }
            #else
            {
                img_context_p->file_size = jpeg_encode_process(&jpg_encode);
            }
            #endif
            exit_jpeg_encode_process();
        #endif /* __MTK_TARGET__ */
            cam_context_p->jpeg_file_info_p->file_address[shot_count - 1] = jpg_encode.jpeg_file_start_address;
            cam_context_p->jpeg_file_info_p->file_size[shot_count - 1] = img_context_p->file_size;
            /* update buffer address and size for next shot */
            jpg_encode.jpeg_file_start_address =
                (kal_uint32) (jpg_encode.jpeg_file_start_address + img_context_p->file_size);
            jpg_encode.jpeg_file_buffer_size -= img_context_p->file_size;
            /* free internal mem for jpeg encode */
            if (img_context_p->intmem_start_address)
            {
                med_free_int_mem((void **)&img_context_p->intmem_start_address);
            }
            if (shot_count >= cam_context_p->snapshot_number)
            {
                cam_context_p->continue_capture = KAL_FALSE;
                cam_release_memory();
                img_release_memory();
                CAM_ENTER_STATE(CAM_READY);
            }
            else
            {
                cam_send_event_ind(CAM_EVT_CAPTURE, (kal_uint8) (shot_count + 1));
            }
            cam_send_capture_event_ind(MED_RES_OK, (kal_uint16) shot_count);
        }
    }
#if (defined(AF_SUPPORT) && ( MT6225_SERIES || (MT6219_SERIES && !defined(MT6219))|| MT6228_SERIES))
    else if ((ind_p->event == CAM_EVT_AUTOFOCUS))
    {
        if (FACTORY_BOOT == stack_query_boot_mode())
        {
            af_main();
        }
        else if ((CAM_IN_STATE(CAM_READY) || CAM_IN_STATE(CAM_PREVIEW)))
        {
            if (ind_p->cause == 0)
            {
                af_main();
            }
            else
            {
                cam_send_autofocus_process_done_ind(ind_p->event, ind_p->cause);
            }
        }
    }
#endif /* defined(AF_SUPPORT) && ( MT6225_SERIES || (MT6219_SERIES && !defined(MT6219))|| MT6228_SERIES) */ 
#ifdef BARCODE_SUPPORT
    else if (ind_p->event == CAM_EVT_CAPTURE_BARCODE)
    {
        if (CAM_IN_STATE(CAM_READY))
        {
            media_cam_barcode_event_ind_struct barcode_event_ind;
            barcode_event_ind.event = ind_p->event;
            barcode_event_ind.cause = ind_p->cause;
            cam_send_barcode_decode_done_ind(&barcode_event_ind);
        }
        else
        {
            ASSERT(0);
        }
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  cam_preview_restart
 * DESCRIPTION
 *  This function is to restart preview after recording paused.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cam_preview_restart(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  cam_abort_to_idle
 * DESCRIPTION
 *  This function is to abort all operations and go to idle state .
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cam_abort_to_idle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (CAM_IN_STATE(CAM_PREVIEW))
    {
    #ifdef __MTK_TARGET__
        exit_camera_preview_process();
        cam_release_memory();
        CAM_ENTER_STATE(CAM_READY);
        power_off_isp();
    #endif /* __MTK_TARGET__ */
        /* to release the memory allocated in MED_MODE_BUFFER mode */
        CAM_FREE_CAPTURE_BUFFER();
        CAM_ENTER_STATE(CAM_IDLE);
    }
    else if (CAM_IN_STATE(CAM_CAPTURE))
    {
    #ifdef __MTK_TARGET__
        stop_camera_capture_process();
        cam_release_memory();
        CAM_ENTER_STATE(CAM_READY);
        power_off_isp();
    #endif /* __MTK_TARGET__ */
        /* to release the memory allocated in MED_MODE_BUFFER mode */
        CAM_FREE_CAPTURE_BUFFER();
        CAM_ENTER_STATE(CAM_IDLE);
        CAM_SET_EVENT(CAM_EVT_CAPTURE);
    }
    else if (CAM_IN_STATE(CAM_READY))
    {
    #ifdef __MTK_TARGET__
        power_off_isp();
    #endif
        /* to release the memory allocated in MED_MODE_BUFFER mode */
        CAM_FREE_CAPTURE_BUFFER();
        CAM_ENTER_STATE(CAM_IDLE);
    }
}

#ifdef BARCODE_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  cam_barcode_preview_req_hdlr
 * DESCRIPTION
 *  This function is to handle camera preview request.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void cam_barcode_preview_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_preview_req_struct *req_p;
    camera_capture_barcode_struct preview_param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_context_p->src_mod = ilm_ptr->src_mod_id;

    if (CAM_IN_STATE(CAM_READY))
    {
        CAME_FREE_BARCODE_BUFFER();
        req_p = (media_cam_preview_req_struct*) ilm_ptr->local_para_ptr;
        cam_context_p->lcd_id = preview_param.lcd_id = req_p->lcd_id;
        cam_context_p->lcd_start_x = preview_param.lcm_start_x = req_p->lcd_start_x;
        cam_context_p->lcd_start_y = preview_param.lcm_start_y = req_p->lcd_start_y;
        cam_context_p->lcd_end_x = preview_param.lcm_end_x = req_p->lcd_end_x;
        cam_context_p->lcd_end_y = preview_param.lcm_end_y = req_p->lcd_end_y;
        cam_context_p->roi_offset_x = preview_param.roi_offset_x = req_p->roi_offset_x;
        cam_context_p->roi_offset_y = preview_param.roi_offset_y = req_p->roi_offset_y;
        cam_context_p->update_layer = preview_param.update_layer = req_p->update_layer;
        cam_context_p->hw_update_layer = preview_param.hw_update_layer = req_p->hw_update_layer;


        preview_param.intmem_start_address = cam_context_p->intmem_start_address =
            (kal_uint32) med_alloc_int_mem(cam_preview_mem[0]);
        preview_param.intmem_size = cam_context_p->intmem_size = (kal_uint32) cam_preview_mem[0];
        preview_param.extmem_start_address = 0;
        preview_param.extmem_size = 0;
        preview_param.target_width = req_p->image_width;
        preview_param.target_height = req_p->image_height;


        preview_param.source_width = cam_context_p->preview_width = req_p->preview_width;
        preview_param.source_height = cam_context_p->preview_height = req_p->preview_height;
        /* use internal memory for preview buffer if enough */
    #if MT6228_SERIES
        if (req_p->image_buffer_size * 2 < (med_int_left_size() - MEM_OVERHEAD ))
        {
            /* internal memory enough for double buffer */
            cam_context_p->frame_buffer_p = (kal_uint32) req_p->image_buffer_p;
            cam_context_p->frame_buffer_size = cam_context_p->extmem_size = preview_param.frame_buffer_size =
                preview_param.frame_buffer_size1 = req_p->image_buffer_size;
            cam_context_p->int_frame_buffer_p = preview_param.frame_buffer_address =
                (kal_uint32) med_alloc_int_mem(preview_param.frame_buffer_size * 2);
            preview_param.frame_buffer_address1 = preview_param.frame_buffer_address + preview_param.frame_buffer_size;
            cam_context_p->ext_frame_buffer_p = 0;
        }
        else if (req_p->image_buffer_size < (med_int_left_size() - MEM_OVERHEAD ))
        {
            /* internal memory enough for single buffer */
            cam_context_p->frame_buffer_p = (kal_uint32) req_p->image_buffer_p;
            cam_context_p->frame_buffer_size = cam_context_p->extmem_size = preview_param.frame_buffer_size =
                preview_param.frame_buffer_size1 = req_p->image_buffer_size;
            /* one internal buffer */
            cam_context_p->int_frame_buffer_p = preview_param.frame_buffer_address =
                (kal_uint32) med_alloc_int_mem(preview_param.frame_buffer_size);
            /* one external buffer */
            preview_param.frame_buffer_address1 = cam_context_p->frame_buffer_p;
            cam_context_p->ext_frame_buffer_p = 0;
        }
        else if (req_p->image_buffer_size < (med_ext_left_size() - MEM_OVERHEAD ))
        {
            /* internal memory enough for single buffer */
            cam_context_p->frame_buffer_p = (kal_uint32) req_p->image_buffer_p;
            cam_context_p->frame_buffer_size = cam_context_p->extmem_size = preview_param.frame_buffer_size =
                preview_param.frame_buffer_size1 = req_p->image_buffer_size;
            /* one external buffer given from MMI */
            preview_param.frame_buffer_address = cam_context_p->frame_buffer_p;
            /* one more external buffer */
            cam_context_p->ext_frame_buffer_p = preview_param.frame_buffer_address1 =
                (kal_uint32) med_alloc_ext_mem(preview_param.frame_buffer_size);
            cam_context_p->int_frame_buffer_p = 0;
        }
        else
    #endif
        {
            /* use single external buffer from MMI */
            cam_context_p->frame_buffer_p = preview_param.frame_buffer_address1 = preview_param.frame_buffer_address =
                (kal_uint32) req_p->image_buffer_p;
            cam_context_p->frame_buffer_size = preview_param.frame_buffer_size1 = preview_param.frame_buffer_size =
                req_p->image_buffer_size;
            cam_context_p->int_frame_buffer_p = 0;
            cam_context_p->ext_frame_buffer_p = 0;
        }

        cam_context_p->barcode_buffer_size = preview_param.barcode_buffer_size =
            req_p->image_width * req_p->image_height * 2;
        cam_context_p->barcode_buffer_address = preview_param.barcode_buffer_address =
            (kal_uint32) med_alloc_ext_mem(cam_context_p->barcode_buffer_size);
        cam_context_p->barcode_buffer_width = req_p->image_width;
        cam_context_p->barcode_buffer_height = req_p->image_height;

        if (cam_context_p->barcode_buffer_address == NULL)
        {
            ASSERT(0);
        }

        cam_context_p->ev_value = preview_param.ev_value = req_p->exposure;

        cam_context_p->image_mirror = preview_param.image_mirror = cam_rotate_map[req_p->rotate];
        cam_context_p->banding_freq = preview_param.banding_freq = req_p->banding_freq;
        cam_context_p->lcd_rotate = req_p->lcd_rotate;
        preview_param.frame_rate = cam_context_p->frame_rate = cam_get_preview_frame_rate(req_p->frame_rate);

        /* preview_param.rotate_value=(kal_uint8)req_p->lcd_rotate; */
        /* LCD Setting */
        /* cam_context_p->roi_background_color=preview_param.roi_background_color=req_p->roi_background_color; */

        /* AF */
        cam_context_p->camera_offset_x = preview_param.camera_offset_x = req_p->camera_offset_x;
        cam_context_p->camera_offset_y = preview_param.camera_offset_y = req_p->camera_offset_y;
        cam_context_p->af_zone0_x = preview_param.af_zone0_x = req_p->af_zone0_x;
        cam_context_p->af_zone0_y = preview_param.af_zone0_y = req_p->af_zone0_y;
        cam_context_p->af_zone1_x = preview_param.af_zone1_x = req_p->af_zone1_x;
        cam_context_p->af_zone1_y = preview_param.af_zone1_y = req_p->af_zone1_y;
        cam_context_p->af_zone2_x = preview_param.af_zone2_x = req_p->af_zone2_x;
        cam_context_p->af_zone2_y = preview_param.af_zone2_y = req_p->af_zone2_y;
        cam_context_p->af_zone3_x = preview_param.af_zone3_x = req_p->af_zone3_x;
        cam_context_p->af_zone3_y = preview_param.af_zone3_y = req_p->af_zone3_y;
        cam_context_p->af_zone4_x = preview_param.af_zone4_x = req_p->af_zone4_x;
        cam_context_p->af_zone4_y = preview_param.af_zone4_y = req_p->af_zone4_y;

    #if MT6228_SERIES
        preview_param.barcode_image_data_format = IMGDMA_IBW_OUTPUT_RGB565;

    #ifdef __MED_TVO_MOD__
        tvo_context_p->tv_output_mode = req_p->tv_output_mode;
        preview_param.tv_output = tvo_context_p->tv_output = req_p->tv_output;
        preview_param.tv_output_width = tvo_context_p->tv_output_width = req_p->tv_output_width;
        preview_param.tv_output_height = tvo_context_p->tv_output_height = req_p->tv_output_height;
        preview_param.tv_output_offset_x = tvo_context_p->tv_output_offset_x = req_p->tv_output_offset_x;
        preview_param.tv_output_offset_y = tvo_context_p->tv_output_offset_y = req_p->tv_output_offset_y;
        preview_param.tv_output_buffer_size = tvo_context_p->tv_output_buffer_size = req_p->tv_output_buffer_size;
        preview_param.tv_output_buffer1_address = tvo_context_p->tv_output_buffer1_address =
            req_p->tv_output_buffer1_address;
        preview_param.tv_output_buffer2_address = tvo_context_p->tv_output_buffer2_address =
            req_p->tv_output_buffer2_address;
        //      preview_param.tv_rotate_buffer1_address=tvo_context_p->tv_rotate_buffer1_address=req_p->tv_rotate_buffer1_address;
        //      preview_param.tv_rotate_buffer2_address=tvo_context_p->tv_rotate_buffer2_address=req_p->tv_rotate_buffer2_address;
    #endif /* __MED_TVO_MOD__ */
        /* IPP Setting */
        cam_context_p->image_pitch_mode = preview_param.image_pitch_mode = req_p->image_pitch_mode;
        cam_context_p->image_data_format = preview_param.image_data_format = req_p->image_data_format;
        cam_context_p->image_pitch_bytes = preview_param.image_pitch_bytes = req_p->image_pitch_bytes;
    #endif /* MT6228_SERIES */

        preview_param.cam_preview_cb = cam_preview_callback;
        preview_param.cam_focus_cb = cam_focus_callback;

        preview_param.cam_capture_barcode_cb = cam_barcode_callback;

    #ifdef __MTK_TARGET__
        if (camera_capture_barcode_process(&preview_param) != KAL_TRUE)
        {
            /* preview failed, free memory and power off camera */
            cam_release_memory();
            power_off_isp();
            /* to release the memory allocated in MED_MODE_BUFFER mode */
            CAM_FREE_CAPTURE_BUFFER();
            CAM_ENTER_STATE(CAM_IDLE);
            cam_set_result(MED_RES_FAIL);
        }
        else
    #endif /* __MTK_TARGET__ */
        {
            CAM_ENTER_STATE(CAM_PREVIEW);
        }

    }
    else
    {
        cam_set_result(MED_RES_BUSY);
    }

    CAM_SET_EVENT(CAM_EVT_PREVIEW);

}


/*****************************************************************************
 * FUNCTION
 *  cam_barcode_stop_req_hdlr
 * DESCRIPTION
 *  This function is to handle camera stop request.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void cam_barcode_stop_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_context_p->src_mod = ilm_ptr->src_mod_id;

    if (CAM_IN_STATE(CAM_PREVIEW))
    {
    #ifdef __MTK_TARGET__
        stop_camera_capture_barcode_process();
    #endif
        cam_release_memory();
        img_release_memory();
        CAME_FREE_BARCODE_BUFFER();
        CAM_ENTER_STATE(CAM_READY);
    }
    else if (CAM_IN_STATE(CAM_CAPTURE_BARCODE))
    {
        med_stop_timer(CAM_BARCODE_DECODE_TIMER);
        stop_camera_capture_barcode_process();
        cam_release_memory();
        img_release_memory();
        CAME_FREE_BARCODE_BUFFER();
        CAM_ENTER_STATE(CAM_READY);
    }
    else
    {
        cam_release_memory();
        img_release_memory();
        CAME_FREE_BARCODE_BUFFER();
    }

    CAM_SET_EVENT(CAM_EVT_STOP);

}


/*****************************************************************************
 * FUNCTION
 *  cam_barcode_capture_req_hdlr
 * DESCRIPTION
 *  This function is to handle camera capture request.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void cam_barcode_capture_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_barcode_capture_struct *req_p;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cam_context_p->src_mod = ilm_ptr->src_mod_id;

    req_p = (media_cam_barcode_capture_struct*) ilm_ptr->local_para_ptr;
    cam_context_p->barcode_text_buf_address = (kal_uint8*) req_p->text_buf;
    cam_context_p->barcode_text_buf_length = req_p->buf_length;
    cam_context_p->barcode_type = req_p->barcode_type;
    if (CAM_IN_STATE(CAM_PREVIEW))
    {
        CAM_ENTER_STATE(CAM_CAPTURE_BARCODE);
        cam_context_p->barcode_decode_time = 0;
    #ifdef __MTK_TARGET__
        cam_barcode_capture_and_decode(NULL);
    #endif

    }
    else
    {
        ASSERT(0);
    }
    CAM_SET_EVENT(CAM_EVT_CAPTURE_BARCODE);
}


/*****************************************************************************
 * FUNCTION
 *  cam_barcode_stop_capture_req_hdlr
 * DESCRIPTION
 *  This function is to handle camera capture request.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void cam_barcode_stop_capture_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (CAM_IN_STATE(CAM_CAPTURE_BARCODE))
    {

    #ifdef __MTK_TARGET__
    #if defined(AF_SUPPORT)
        if (cam_context_p->af_mode != CAM_AF_MANUAL_MODE)
            camera_operation_setting((kal_uint8) CAM_AF_KEY, (kal_uint16) CAM_AF_RELEASE);
    #endif
        med_stop_timer(CAM_BARCODE_DECODE_TIMER);
    #endif /* __MTK_TARGET__ */
        CAM_ENTER_STATE(CAM_PREVIEW);
    }

    CAM_SET_EVENT(CAM_EVT_STOP_CAPTURE_BARCODE);

}


/*****************************************************************************
 * FUNCTION
 *  cam_barcode_capture_and_decode
 * DESCRIPTION
 *  This function is to handle camera capture request.
 * PARAMETERS
 *  args        [?]
 *  ilm_struct *ilm_ptr(?)
 * RETURNS
 *  void
 *****************************************************************************/
void cam_barcode_capture_and_decode(void *args)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sc2dBarcode *psc2dBcd = NULL;
    kal_int32 string_length;
    media_cam_barcode_event_ind_struct barcode_event_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (CAM_IN_STATE(CAM_CAPTURE_BARCODE))
    {
    #ifdef __MTK_TARGET__
        kal_int32 status = 0;

        get_barcode_image();

        //Generating structure
        psc2dBcd = sc2dDecoder_New();
        if (psc2dBcd == NULL){
            ASSERT(0);
        }        

    #ifdef __MED_DEBUG__
    {
        FS_HANDLE fp;
        kal_wchar file_name[50];
        unsigned int len;

        kal_wsprintf(file_name, "c:\\Photos\\%d.RAW", cam_file_number);
        fp = FS_Open(file_name, FS_CREATE | FS_READ_WRITE);

        if (fp < FS_NO_ERROR)
        {
            kal_prompt_trace(MOD_MED, " open file error: e drvie \n");
            kal_prompt_trace(MOD_MED, " open file error: %d\n", fp);
        }
        else
        {
            FS_Write(
                fp,
                (unsigned char*)cam_context_p->barcode_buffer_address,
                cam_context_p->barcode_buffer_width * cam_context_p->barcode_buffer_height * 2,
                &len);
            FS_Close(fp);
            cam_file_number++;
        }
    }
    #endif /* __MED_DEBUG__ */

    #if (MT6219_SERIES && !defined(MT6219))
        DCM_Load( DYNAMIC_CODE_BCODE, NULL, NULL);
    #endif

    status = sc2dDecoder_SetInput(psc2dBcd,
                                  (TUint8*) cam_context_p->barcode_buffer_address,
                                  SC_IMG_RGB565,//SC_IMG_RGB888,//SC_IMG_RGB565,//SC_IMG_GRAY,
                                  (TUint32)cam_context_p->barcode_buffer_width,
                                  (TUint32)cam_context_p->barcode_buffer_height,
                                  (TUint32)cam_context_p->barcode_type);

   

    if (status != SC_2D_SUCCESS)
    {
        scFree2dBarcode(&psc2dBcd);
    }
    else
        status = sc2dDecoder_Process(psc2dBcd);

    #if (MT6219_SERIES && !defined(MT6219))
        DCM_Unload(DYNAMIC_CODE_BCODE);
    #endif

        /*********************************************************************
         *
         *  check if it is appended QR Code
         *
         ********************************************************************/
        if (status ==SC_2D_SUCCESS)
        {
            barcode_event_ind.event = (kal_uint16)CAM_EVT_CAPTURE_BARCODE;
            barcode_event_ind.cause = (kal_uint8)MED_RES_OK;
            barcode_event_ind.encoding = 0;
            barcode_event_ind.nsymbol = 1;
            barcode_event_ind.symbolid = 1;
            barcode_event_ind.paritydata = 0;

            string_length = (psc2dBcd->retLength > cam_context_p->barcode_text_buf_length - 2)?
                (cam_context_p->barcode_text_buf_length - 2) : psc2dBcd->retLength;
            memcpy(cam_context_p->barcode_text_buf_address,psc2dBcd->retVal,string_length);
            cam_context_p->barcode_text_buf_address[string_length] = 0;
            cam_context_p->barcode_text_buf_address[string_length+1] = 0;
            
            #if defined(AF_SUPPORT)
            camera_operation_setting((kal_uint8) CAM_AF_KEY, (kal_uint16) CAM_AF_RELEASE);
            #endif
            stop_camera_capture_barcode_process();
            cam_release_memory();
            img_release_memory();
            CAME_FREE_BARCODE_BUFFER();
            
            if (psc2dBcd->retType == SC_2D_QR)
            {
                barcode_event_ind.encoding = psc2dBcd->pQR->encodeMode;
                barcode_event_ind.nsymbol = psc2dBcd->pQR->nSymbols;
                barcode_event_ind.symbolid = psc2dBcd->pQR->symbolId;
                barcode_event_ind.paritydata = psc2dBcd->pQR->parityData;
            }
            
            cam_send_barcode_decode_done_ind(&barcode_event_ind);

            CAM_ENTER_STATE(CAM_READY);
            sc2dDecoder_Clean(psc2dBcd);
            scFree2dBarcode(&psc2dBcd);	
        }
        else
        {
            CAM_QR_RESULT_TRACE(status);
            barcode_event_ind.event = (kal_uint16)CAM_EVT_CAPTURE_BARCODE;
            barcode_event_ind.encoding = 0;
            barcode_event_ind.nsymbol = 0;
            barcode_event_ind.symbolid = 0;
            barcode_event_ind.paritydata = 0;

            if (status == SC_2D_EFAILED && (cam_context_p->barcode_decode_time++ <= 20))
            {
                med_start_timer(CAM_BARCODE_DECODE_TIMER, 100, cam_barcode_capture_and_decode, 0);
                sc2dDecoder_Clean(psc2dBcd);
                scFree2dBarcode(&psc2dBcd);
            }
            else
            {
                if (cam_context_p->barcode_decode_time++ > 20)
                    barcode_event_ind.cause = MED_RES_BR_DECODE_TIMEOUT;
                else
                {
                    switch (status)
                    {
                        case SC_2D_EIMGSIZE:
                            barcode_event_ind.cause = (kal_uint8)MED_RES_BR_MODULE_ERROR;
                        break;
                        case SC_2D_ENOMEMORY:
                            barcode_event_ind.cause = (kal_uint8)MED_RES_BR_OUT_OF_MEMORY;
                        break;
                        case SC_2D_EVERSIONNOTSUPPORT:
                        case SC_2D_EQRVERSION2HIGH:
                            barcode_event_ind.cause = (kal_uint8)MED_RES_BR_OVER_VERSION;
                        break;
                        case SC_2D_ECODETYPE:
                            barcode_event_ind.cause = (kal_uint8)MED_RES_BR_ERROR_BARCODE_TYPE;
                        break;
                        case SC_2D_EIMGTYPE:
                            barcode_event_ind.cause = (kal_uint8)MED_RES_BR_IMAGE_ERROR;
                        break;
                    }            
                }                    

            #if defined(AF_SUPPORT)
                camera_operation_setting((kal_uint8) CAM_AF_KEY, (kal_uint16) CAM_AF_RELEASE);
            #endif
                stop_camera_capture_barcode_process();
                cam_release_memory();
                img_release_memory();
                CAME_FREE_BARCODE_BUFFER();
                cam_send_barcode_decode_done_ind(&barcode_event_ind);
                sc2dDecoder_Clean(psc2dBcd);
                scFree2dBarcode(&psc2dBcd);	
                CAM_ENTER_STATE(CAM_READY);
                return;
            }
        }
    #ifdef __MED_BARCODE_TEST__
        FREE_MEM_SCANBUY(retVal);
    #endif

    #endif /* __MTK_TARGET__ */

    }
    else
    {
        ASSERT(0);
    }
}
#endif
#else
#error "no such combination"
#endif

#endif /* __MED_CAM_MOD__ */

#endif /* MED_NOT_PRESENT */

