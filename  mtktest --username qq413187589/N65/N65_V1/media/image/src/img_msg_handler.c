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
 *   img_msg_handler.c
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

/* DRM_REPLACE */
#include "drm_gprot.h"

/* local includes */
#include "med_global.h"
#include "med_main.h"
#include "aud_defs.h"
#include "med_struct.h"
#include "med_api.h"
#include "med_context.h"
#include "med_utility.h"
#include "med_smalloc.h"
#include "img_main.h"

media_img_decode_req_struct img_context_last_req;

#if defined(JPG_DECODE) || defined(JPG_ENCODE)
#include "jpeg.h"
jpeg_decode_process_struct jpg_decode;
#endif /* defined(JPG_DECODE) || defined(JPG_ENCODE) */ 

#include "scn_comm.h"
#include "img_comm.h"

#if (defined(EXIF_SUPPORT))
#include "exif.h"
#endif 

#if defined(USE_HW_GIF_DECODER_V2)
#include "gif_decoder_v2.h"
//#define GIF_FILE_BUFFER_SIZE         4096
gif_config_struct img_context_gif_config;
gif_info_struct *img_context_gif_info;
#endif /* defined(USE_HW_GIF_DECODER_V2) */ 

#if defined(USE_HW_PNG_DECODER_V1) || defined(USE_SW_PNG_DECODER)
#include "png_decoder.h"
#define PNG_FILE_BUFFER_SIZE        (16*1024)
png_config_struct img_context_png_config;
png_inform_struct *img_context_png_info;
#endif /* defined(USE_HW_PNG_DECODER_V1) */ 

#include "fat_fs.h"

#ifdef __IMG_TRACE_ON__
#include "med_trc.h"
#endif 

#ifdef __MED_IMG_MOD__

#define MAX_IMAGE_CODEC_COUNT 1
#ifdef __MED_CAM_MOD__

#define CAM_FREE_CAPTURE_BUFFER()       if (cam_context_p->capture_buffer_p)  \
                                             med_free_ext_mem((void**)&cam_context_p->capture_buffer_p)
#endif /* __MED_CAM_MOD__ */ 

#include "lcd_if.h"
#include "lcd_sw_rnd.h"
#include "PixtelDataTypes.h"

//REMOVE FOR GDI TASK
//#include "gdi_include.h"
//#include "gd_primitive.h"
//extern S16 gdi_gif_stack[];
//extern S32 GDI_TREE_BUFFER[];
//extern U8 gdi_bytestream_buffer[BYTESTREAM_BUFFER_SIZE];

#if defined(__SW_JPEG_CODEC_SUPPORT__) && !defined(WIN32)
extern kal_uint32 INT_SwitchStackToRun(void *stack_start, kal_uint32 stack_size, kal_func_ptr func, kal_uint32 argc, ...);
#endif

#define GDI_CLIP_TWO_RECT1(X1, Y1, X2, Y2,CX1,CY1,CX2,CY2,NULL_ACTION)\
{                                                                     \
   if(X1 > X2) { NULL_ACTION; }                                       \
   else if(Y1 > Y2)  { NULL_ACTION; }                                 \
   else if(X2 < CX1) { NULL_ACTION; }                                 \
   else if(Y2 < CY1) { NULL_ACTION; }                                 \
   else if(X1 > CX2) { NULL_ACTION; }                                 \
   else if(Y1 > CY2) { NULL_ACTION; }                                 \
   else                                                               \
   {                                                                  \
      if(X1 < CX1) { X1 = CX1; }                                      \
      if(Y1 < CY1) { Y1 = CY1; }                                      \
      if(X2 > CX2) { X2 = CX2; }                                      \
      if(Y2 > CY2) { Y2 = CY2; }                                      \
   }                                                                  \
}

/*==== FUNCTIONS ===========*/


/*****************************************************************************
 * FUNCTION
 *  img_open_image_file
 * DESCRIPTION
 *  This function is to open image file for encode.
 * PARAMETERS
 *  file_name       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 img_open_image_file(kal_wchar *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 max_file_buffer = 200*1024;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if the format valid */
    if (med_get_media_type((kal_wchar*) file_name) != MED_TYPE_JPG)
    {
        return MED_RES_INVALID_FORMAT;
    }

    if (max_file_buffer < MAX_IMG_ENC_FILE_BUFFER_LEN)
        max_file_buffer = MAX_IMG_ENC_FILE_BUFFER_LEN;

    /* open the file */
    img_context_p->file_handle = FS_Open((kal_wchar*) file_name, FS_CREATE | FS_READ_WRITE);

    kal_prompt_trace(MOD_MED, "img_open_image_file handle :%d \n", img_context_p->file_handle );

    if (img_context_p->file_handle >= 0)
    {
        img_context_p->file_buffer_address = NULL;
        while(1)
        {
            img_context_p->file_buffer_address=(kal_uint32)med_alloc_ext_mem(max_file_buffer);
            if(img_context_p->file_buffer_address==NULL)
            {
                max_file_buffer -= 25*1024;
                if (max_file_buffer < 0)
                {
                    max_file_buffer = 0;
                    break;
                }
            }
            else
            {
                break;
            }
        }

        img_context_p->file_buffer_size=max_file_buffer;
        if (img_context_p->file_buffer_address == NULL)
        {
            FS_Close(img_context_p->file_handle);
            FS_Delete((kal_wchar*) file_name);
            return MED_RES_MEM_INSUFFICIENT;
        }
        else
        {
            img_context_p->file_name_p = (kal_wchar*) file_name;
            return MED_RES_OK;
        }
    }
    else if (img_context_p->file_handle == FS_WRITE_PROTECTION)
    {
        return MED_RES_WRITE_PROTECTION;
    }
    else if ((img_context_p->file_handle == FS_DISK_FULL)||(img_context_p->file_handle == FS_PATH_NOT_FOUND))
    {
        return MED_RES_DISC_FULL;
    }
    else if (img_context_p->file_handle == FS_DRIVE_NOT_FOUND)
    {
        return MED_RES_NO_DISC;
    }
    else if (img_context_p->file_handle == FS_ROOT_DIR_FULL)
    {
        return MED_RES_ROOT_DIR_FULL;
    }
    else
    {
        return MED_RES_OPEN_FILE_FAIL;
    }

}


/*****************************************************************************
 * FUNCTION
 *  img_close_image_file
 * DESCRIPTION
 *  This function is to close image file for encode.
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 img_close_image_file(kal_uint32 size)
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
        result = FS_Write(img_context_p->file_handle, (void*)img_context_p->file_buffer_address, size, &len);
        FS_Close(img_context_p->file_handle);

        kal_prompt_trace(MOD_MED, "img_close_image_file error:%d \n", result);

        if (result != FS_NO_ERROR)
        {
            FS_Delete(img_context_p->file_name_p);
            if (result == FS_DRIVE_NOT_FOUND)
            {
                res = MED_RES_NO_DISC;
            }
            else if (result == FS_DISK_FULL)
            {
                res = MED_RES_DISC_FULL;
            }
            else if (img_context_p->file_handle == FS_ROOT_DIR_FULL)
            {
                res = MED_RES_ROOT_DIR_FULL;
            }
            else
            {
                res = MED_RES_OPEN_FILE_FAIL;
            }
        }
        else if (size != len)
        {
            FS_Delete(img_context_p->file_name_p);
            res = MED_RES_DISC_FULL;
        }
    }
    else
    {
        /* Close and delete the file */
        FS_Close(img_context_p->file_handle);
        FS_Delete((kal_wchar*) img_context_p->file_name_p);
        res = MED_RES_FAIL;
    }

    img_release_memory();
    return res;
}


/*****************************************************************************
 * FUNCTION
 *  img_release_memory
 * DESCRIPTION
 *  This function is to release memory for image decoding/encoding.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void img_release_memory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (img_context_p->file_buffer_address)
    {
        med_free_ext_mem((void **)&img_context_p->file_buffer_address);
    }
    if (img_context_p->intmem_start_address)
    {
        med_free_int_mem((void **)&img_context_p->intmem_start_address);
    }
    if (img_context_p->extmem_start_address)
    {
        med_free_ext_mem((void **)&img_context_p->extmem_start_address);
    }
    #ifdef BEREMOVED
    if (img_context_p->image_buffer_address1)
    {
        med_free_ext_mem((void **)&img_context_p->image_buffer_address1);
    }
    #endif

    #if defined(MT6225) || defined(MT6223P) || defined(MT6223P_S00) || defined(MT6223) || defined(MT6235)
    if (img_context_p->y_address)
    {
        med_free_ext_mem((void **)&img_context_p->y_address);
    }
    if (img_context_p->u_address)
    {
        med_free_ext_mem((void **)&img_context_p->u_address);
    }
    if (img_context_p->v_address)
    {
        med_free_ext_mem((void **)&img_context_p->v_address);
    }
    #endif /* defined(MT6225) || defined(MT6223P) || defined(MT6223P_S00) || defined(MT6223) || defined(MT6235) */
    
}


/*****************************************************************************
 * FUNCTION
 *  img_get_decode_res
 * DESCRIPTION
 *  This function is to get the decode result.
 * PARAMETERS
 *  cause       [IN]        
 * RETURNS
 *  kal_int16
 *****************************************************************************/
kal_int16 img_get_decode_res(kal_uint8 cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MED, "img_get_decode_res :%d \n", cause);

    switch (cause)
    {
    #ifdef JPG_DECODE
        case JPEG_DECODE_SUCCESS:
        case JPEG_DECODE_DECODER_OVERFLOW_FAIL:
        case JPEG_DECODE_DECODER_BREAK_FAIL:
            return MED_RES_OK;
        case JPEG_DECODE_INT_BUFFER_NOT_ENOUGH:
        case JPEG_DECODE_EXT_BUFFER_NOT_ENOUGH:
            return MED_RES_MEM_INSUFFICIENT;
        case JPEG_DECODE_TARGET_BUFFER_NOT_ENOUGH:
        case JPEG_DECODE_SRC_WIDHT_TOO_LARGE_FAIL:
        case JPEG_DECODE_SRC_HEIGHT_TOO_LARGE_FAIL:
        case JPEG_DECODE_TARGET_WIDTH_TOO_LARGE_FAIL:
        case JPEG_DECODE_TARGET_HEIGHT_TOO_LARGE_FAIL:
        case JPEG_DECODE_BUFFER_SIZE_FAIL:
            return MED_RES_BUFFER_INSUFFICIENT;
    #endif /* JPG_DECODE */ 
        default:
            return MED_RES_FAIL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  img_get_encode_res
 * DESCRIPTION
 *  This function is to get the encode result.
 * PARAMETERS
 *  cause       [IN]        
 * RETURNS
 *  kal_int16
 *****************************************************************************/
kal_int16 img_get_encode_res(kal_uint8 cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MED, "img_get_encode_res :%d \n", cause);

    switch (cause)
    {
    #ifdef JPG_ENCODE
        case JPEG_ENCODE_DONE:
            return MED_RES_OK;
        case JPEG_ENCODE_STALL:
            return MED_RES_FAIL;
    #endif /* JPG_ENCODE */ 
        default:
            return MED_RES_FAIL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  img_decode_callback
 * DESCRIPTION
 *  This function is the callback function of decoding.
 * PARAMETERS
 *  cause       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void img_decode_callback(kal_uint8 cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    img_context_p->processing = KAL_FALSE;
    img_send_decode_event_ind(cause, 0, 0);
}


/*****************************************************************************
 * FUNCTION
 *  img_decode_restart
 * DESCRIPTION
 *  This function is to restart decode process for retrying.
 * PARAMETERS
 *  void
 *  kal_uint8 cause(?)
 * RETURNS
 *  void
 *****************************************************************************/
void img_decode_restart(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 waiting_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (img_context_p->blocking)
    {
        waiting_time = IMG_CODEC_BLOCK_WAITING_TIME;
    }
    else
    {
        waiting_time = IMG_CODEC_RETRY_TIME * ((img_context_p->file_size >> IMG_DECODE_FILE_UNIT) + 1);
    }

    if (img_context_p->media_mode == MED_MODE_FILE)
    {
    #ifdef JPG_DECODE
        if (img_context_p->media_type == MED_TYPE_JPG)
        {
            /* init jpeg */
            kal_int16 result;
            kal_uint8 dec_ret = JPEG_DECODE_UNSUPPORT_FORMAT;

        #ifdef __MTK_TARGET__
            dec_ret = jpeg_decode_process(&jpg_decode);
        #endif 
            if (dec_ret == JPEG_DECODE_DECODING)
            {
                img_context_p->processing = KAL_TRUE;
                med_start_timer(IMAGE_CODEC_RETRY_TIMER, waiting_time, img_codec_retry_handler, 0);
            }
            else
            {
                img_release_memory();
                result = img_get_decode_res(dec_ret);
                if (!img_context_p->blocking)
                {
                    img_send_decode_finish_ind(result, img_context_p->seq_num);
                }
                else
                {
                    img_set_result(result);
                    IMG_SET_EVENT(IMG_EVT_DECODE);
                }
                IMG_ENTER_STATE(IMG_IDLE);
            }
        }
        else
    #endif /* JPG_DECODE */ 
        {
            img_release_memory();
            if (!img_context_p->blocking)
            {
                img_send_decode_finish_ind(MED_RES_INVALID_FORMAT, img_context_p->seq_num);
            }
            else
            {
                img_set_result(MED_RES_INVALID_FORMAT);
                IMG_SET_EVENT(IMG_EVT_DECODE);
            }
            IMG_ENTER_STATE(IMG_IDLE);
        }
    }
    else if (img_context_p->media_mode == MED_MODE_ARRAY)
    {
    #ifdef JPG_DECODE
        if (img_context_p->media_type == MED_TYPE_JPG)
        {
            /* init jpeg */
            kal_int16 result;
            kal_uint8 dec_ret = JPEG_DECODE_UNSUPPORT_FORMAT;

        #ifdef __MTK_TARGET__
            dec_ret = jpeg_decode_process(&jpg_decode);
        #endif 
            if (dec_ret == JPEG_DECODE_DECODING)
            {
                img_context_p->processing = KAL_TRUE;
                med_start_timer(IMAGE_CODEC_RETRY_TIMER, waiting_time, img_codec_retry_handler, 0);
            }
            else
            {
                img_context_p->file_buffer_address = NULL;
                img_release_memory();
                result = img_get_decode_res(dec_ret);
                if (!img_context_p->blocking)
                {
                    img_send_decode_finish_ind(result, img_context_p->seq_num);
                }
                else
                {
                    img_set_result(result);
                    IMG_SET_EVENT(IMG_EVT_DECODE);
                }
                IMG_ENTER_STATE(IMG_IDLE);
            }
        }
        else
    #endif /* JPG_DECODE */ 
        {
            img_context_p->file_buffer_address = NULL;
            img_release_memory();
            if (!img_context_p->blocking)
            {
                img_send_decode_finish_ind(MED_RES_INVALID_FORMAT, img_context_p->seq_num);
            }
            else
            {
                img_set_result(MED_RES_INVALID_FORMAT);
                IMG_SET_EVENT(IMG_EVT_DECODE);
            }
            IMG_ENTER_STATE(IMG_IDLE);
        }
    }
    else    /* MED_MODE_STREAM */
    {
        ASSERT(img_context_p->media_mode != MED_MODE_STREAM);
    }

}


/*****************************************************************************
 * FUNCTION
 *  img_codec_retry_handler
 * DESCRIPTION
 *  This function is to handle image codec timeout.
 * PARAMETERS
 *  arg     [?]     
 *  kal_uint8 cause(?)
 * RETURNS
 *  void
 *****************************************************************************/
void img_codec_retry_handler(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IMG_IN_STATE(IMG_JPG_DECODE))
    {
    #ifdef JPG_DECODE
        if (img_context_p->has_retried == TRUE || (img_context_p->jpeg_retry_thumbnail==FALSE))
        {    
            if (!img_context_p->processing)
            {
                return; /* means the call back happened but ind msg is in queue */
            }

            kal_prompt_trace(MOD_MED, "[MED_IMG] stop_jpeg_decode_process:1");
            stop_jpeg_decode_process();
            img_context_p->processing = KAL_FALSE;

            /* decode fail, hardware issue */
            if (img_context_p->media_mode == MED_MODE_ARRAY)
            {
                img_context_p->file_buffer_address = NULL;
            }
            img_release_memory();
            if (!img_context_p->blocking)
            {
                img_send_decode_finish_ind(MED_RES_INVALID_FORMAT, img_context_p->seq_num);
            }
            else
            {
                img_set_result(MED_RES_IMG_DECODE_TIME_OUT);
                IMG_SET_EVENT(IMG_EVT_DECODE);
            }
            IMG_ENTER_STATE(IMG_IDLE);
        }
        else
        {
            /* timeout, then try to decode thumbnail */
        
            kal_uint8 dec_ret = JPEG_DECODE_UNSUPPORT_FORMAT;
            kal_uint32 waiting_time;

            img_context_p->has_retried = TRUE;   
            jpg_decode.jpeg_decode_retry_flag = JPEG_DECODER_RETRY_THUMBNAIL;
            #ifdef BEREMOVED
            img_context_p->image_buffer_address1 = (kal_uint32) med_alloc_ext_mem(img_context_p->image_buffer_size);
            #endif

            kal_prompt_trace(MOD_MED, "[MED_IMG] stop_jpeg_decode_process:2");
            /* stop jpeg decode process */
            stop_jpeg_decode_process();

            /* allocate another buffer for thumbnail */
            #ifdef BEREMOVED
            if (img_context_p->image_buffer_address1 == NULL)
            {
                img_context_p->processing = KAL_FALSE;

                /* decode fail, hardware issue */
                if (img_context_p->media_mode == MED_MODE_ARRAY)
                {
                    img_context_p->file_buffer_address = NULL;
                }             
                img_release_memory();
                if (!img_context_p->blocking)
                {
                    img_send_decode_finish_ind(MED_RES_INVALID_FORMAT, img_context_p->seq_num);
                }
                else
                {
                    img_set_result(MED_RES_IMG_DECODE_TIME_OUT);
                    IMG_SET_EVENT(IMG_EVT_DECODE);
                }
                IMG_ENTER_STATE(IMG_IDLE);
            }
            else
            #endif
            {
                /* if there is enough memory to decode thumbnail */
                img_context_p->prev_result = MED_RES_IMG_DECODE_TIME_OUT;
                img_context_p->has_retried = TRUE;
                if (img_context_p->blocking)
                {
                    waiting_time = IMG_CODEC_BLOCK_WAITING_TIME;
                }
                else
                {
                    waiting_time = IMG_CODEC_RETRY_TIME * ((img_context_p->file_size >> IMG_DECODE_FILE_UNIT) + 1);
                }

            #ifdef __MTK_TARGET__
                dec_ret = jpeg_decode_process(&jpg_decode);
            #endif

                if (dec_ret == JPEG_DECODE_DECODING)
                {
                    img_context_p->processing = KAL_TRUE;
                    img_context_p->retry_conut = 0;
                    med_start_timer(IMAGE_CODEC_RETRY_TIMER, waiting_time, img_codec_retry_handler, 0);
                    IMG_ENTER_STATE(IMG_JPG_DECODE);
                }
                else
                {
                    if (dec_ret == JPEG_DECODE_SUCCESS)
                    {
                        /* copy to the destination buffer */
                        //memcpy((kal_uint8 *)img_context_p->image_buffer_address,
                        //       (kal_uint8 *)img_context_p->image_buffer_address1,
                        //       img_context_p->image_buffer_size);
                        img_set_result(MED_RES_OK);
                    }
                    else
                    {
                        img_set_result(MED_RES_IMG_DECODE_TIME_OUT);
                    }

                    if (img_context_p->media_mode == MED_MODE_ARRAY)
                    {
                        img_context_p->file_buffer_address = NULL;
                    }
                    img_release_memory();
                    img_set_decoded_width(img_context_p->image_width);
                    IMG_SET_EVENT(IMG_EVT_DECODE);
                    IMG_ENTER_STATE(IMG_IDLE);
                }
            }
        } 
    #endif /* JPG_DECODE */ 
    }
}


/*****************************************************************************
 * FUNCTION
 *  img_decode_event_ind_hdlr
 * DESCRIPTION
 *  This function is the event handler for decoding.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void img_decode_event_ind_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_img_decode_event_ind_struct *ind_p;
    kal_int16 result = MED_RES_FAIL;
    kal_bool is_finish = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p = (media_img_decode_event_ind_struct*) ilm_ptr->local_para_ptr;

    kal_prompt_trace(MOD_MED, "[MED_IMG] decode event ind: %d", ind_p->cause);

    if (IMG_IN_STATE(IMG_JPG_DECODE))
    {
    #ifdef JPG_DECODE
        if ((kal_uint8) ind_p->cause == JPEG_DECODE_DECODING)
        {
            img_context_p->processing = KAL_TRUE;
            decode_jpeg_next_block();
        }
        else if ((kal_uint8) ind_p->cause == JPEG_DECODE_DECODER_OVERFLOW_FAIL && img_context_p->has_retried == FALSE)
        {
            kal_uint8 dec_ret = JPEG_DECODE_UNSUPPORT_FORMAT;
            kal_uint32 waiting_time;

            kal_prompt_trace(MOD_MED, "[MED_IMG] HW issue, retry ");

            med_stop_timer(IMAGE_CODEC_RETRY_TIMER);
            /* HW issues: retry to decode thumbnail */
            jpg_decode.jpeg_decode_retry_flag = JPEG_DECODER_RETRY_THUMBNAIL;
            #ifdef BEREMOVED
            img_context_p->image_buffer_address1 = (kal_uint32) med_alloc_ext_mem(img_context_p->image_buffer_size);
            #endif
            kal_prompt_trace(MOD_MED, "[MED_IMG] stop_jpeg_decode_process:3");
            stop_jpeg_decode_process();
            #ifdef BEREMOVED
            if (img_context_p->image_buffer_address1 == NULL)
            {
                kal_prompt_trace(MOD_MED, "[MED_IMG] HW issue, do not retry");
                IMG_ENTER_STATE(IMG_IDLE);
                if (img_context_p->media_mode == MED_MODE_ARRAY)
                {
                    img_context_p->file_buffer_address = NULL;
                }
                img_release_memory();
                result = img_get_decode_res((kal_uint8) ind_p->cause);
                img_set_decoded_width(img_context_p->image_width);

                is_finish = KAL_TRUE;
            }
            else
            #endif
            {
                /* if there is enough memory to decode thumbnail */
                img_context_p->prev_result = img_get_decode_res((kal_uint8) ind_p->cause);
                img_context_p->has_retried = TRUE;
                if (img_context_p->blocking)
                {
                    waiting_time = IMG_CODEC_BLOCK_WAITING_TIME;
                }
                else
                {
                    waiting_time = IMG_CODEC_RETRY_TIME * ((img_context_p->file_size >> IMG_DECODE_FILE_UNIT) + 1);
                }

            #ifdef __MTK_TARGET__
                dec_ret = jpeg_decode_process(&jpg_decode);
            #endif

                if (dec_ret == JPEG_DECODE_DECODING)
                {
                    img_context_p->processing = KAL_TRUE;
                    img_context_p->retry_conut = 0;
                    med_start_timer(IMAGE_CODEC_RETRY_TIMER, waiting_time, img_codec_retry_handler, 0);
                    IMG_ENTER_STATE(IMG_JPG_DECODE);
                }
                else
                {
                    if (dec_ret == JPEG_DECODE_SUCCESS)
                    {
                        result = img_get_decode_res(dec_ret);

                        /* copy to the destination buffer */
                        //memcpy((kal_uint8 *)img_context_p->image_buffer_address,
                        //       (kal_uint8 *)img_context_p->image_buffer_address1,
                        //       img_context_p->image_buffer_size);
                    }
                    else
                    {
                        result = img_context_p->prev_result;
                    }
                    if (img_context_p->media_mode == MED_MODE_ARRAY)
                    {
                        img_context_p->file_buffer_address = NULL;
                    }
                    IMG_ENTER_STATE(IMG_IDLE);
                    img_release_memory();
                    img_set_decoded_width(img_context_p->image_width);
                    is_finish = KAL_TRUE;
                }
            }
        }
        else
        {
            med_stop_timer(IMAGE_CODEC_RETRY_TIMER);
            kal_prompt_trace(MOD_MED, "[MED_IMG] stop_jpeg_decode_process:4");
            stop_jpeg_decode_process();
            IMG_ENTER_STATE(IMG_IDLE);
            if (img_context_p->media_mode == MED_MODE_ARRAY)
            {
                img_context_p->file_buffer_address = NULL;
            }
            img_release_memory();
            result = img_get_decode_res((kal_uint8) ind_p->cause);
            img_set_decoded_width(img_context_p->image_width);

            is_finish = KAL_TRUE;
        }
    #endif /* JPG_DECODE */ 
    }
#if 0 //REMOVE FOR GDI TASKdefined(GDI_USING_HW_GIF_V2)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(GDI_USING_HW_GIF_V2) */ 

#if 0//REMOVE FOR GDI TASKdefined(USE_HW_PNG_DECODER_V1) || defined(USE_SW_PNG_DECODER)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(USE_HW_PNG_DECODER_V1) */ 

    /* global finializer */
    if (is_finish)
    {
        if (img_context_p->callback != NULL)
        {
            img_context_p->callback(result);
        }
        if (img_context_p->blocking)
        {
            img_set_result_ext(result, ind_p->arg0, ind_p->arg1);
            IMG_SET_EVENT(IMG_EVT_DECODE);
        }
        else
        {
            img_send_decode_finish_ind(result, img_context_p->seq_num);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  img_cal_work_buffer_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ret_ratio           [?]         
 *  wb_dest_x           [?]         
 *  wb_dest_y           [?]         
 *  wb_width            [?]         
 *  wb_height           [?]         
 *  wb_pixel_size       [IN]        
 *  img_w               [IN]        
 *  img_h               [IN]        
 *  dest_x              [IN]        
 *  dest_y              [IN]        
 *  expect_w            [IN]        
 *  expect_h            [IN]        
 *  clipx1              [IN]        
 *  clipy1              [IN]        
 *  clipx2              [IN]        
 *  clipy2              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void img_cal_work_buffer_info(
        kal_uint8 *ret_ratio,
        kal_int16 *wb_dest_x,
        kal_int16 *wb_dest_y,
        kal_uint16 *wb_width,
        kal_uint16 *wb_height,
        kal_uint32 wb_pixel_size,
        kal_uint16 img_w,
        kal_uint16 img_h,
        kal_int16 dest_x,
        kal_int16 dest_y,
        kal_uint16 expect_w,
        kal_uint16 expect_h,
        kal_int16 clipx1,
        kal_int16 clipy1,
        kal_int16 clipx2,
        kal_int16 clipy2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 dx, dy;
    S32 dx1, dy1, dx2, dy2, dw, dh;
    S32 sx1, sy1, sx2, sy2, sw, sh;
    S32 rw1, rw2, rh1, rh2;
    S32 ratio;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* initialize default value */
    *ret_ratio = 0;
    *wb_dest_x = dest_x;
    *wb_dest_y = dest_y;

    dx = dest_x;
    dy = dest_y;
    dw = expect_w;
    dh = expect_h;

    sw = img_w;
    sh = img_h;

    rw1 = sw - 1;
    rw2 = dw - 1;
    rh1 = sh - 1;
    rh2 = dh - 1;
    if (rw2 <= 0)
    {
        rw2 = 1;
    }
    if (rh2 <= 0)
    {
        rh2 = 1;
    }

    /* calculate  C   (the real output area) */
    dx1 = dx;
    dy1 = dy;
    dx2 = dx1 + dw - 1;
    dy2 = dy1 + dh - 1;
    GDI_CLIP_TWO_RECT1(dx1, dy1, dx2, dy2, clipx1, clipy1, clipx2, clipy2, return);
    dw = dx2 - dx1 + 1;
    dh = dy2 - dy1 + 1;

    /* calculate S  ( the source area which is mapping to C ) */
    sx1 = (dx1 - dx) * rw1 / rw2;
    sy1 = (dy1 - dy) * rh1 / rh2;
    sx2 = (dx2 - dx) * rw1 / rw2;
    sy2 = (dy2 - dy) * rh1 / rh2;
    sw = sx2 - sx1 + 1;
    sh = sy2 - sy1 + 1;

    /* check the ratio , how to fit into work buffer */
    for (ratio = 0; (sw >> ratio) * (sh >> ratio) > wb_pixel_size; ratio++)
    {
        ;
    }

    *ret_ratio = ratio;

    /* calculate the work buffer width/height depends on the ratio of sw,sh */
    *wb_width = sw >> ratio;
    *wb_height = sh >> ratio;

    /* calculate the dest_x,dest_y in work buffer coordinate */
    *wb_dest_x = -sx1 / (1 << ratio);
    *wb_dest_y = -sy1 / (1 << ratio);

}

#ifdef JPG_DECODE


/*****************************************************************************
 * FUNCTION
 *  image_decoder_jpeg_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  req_p       [?]     
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 image_decoder_jpeg_req_hdlr(media_img_decode_req_struct *req_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;
    kal_uint32 waiting_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* init jpeg_decode_retry_flag to DISABLE */    
    jpg_decode.jpeg_decode_retry_flag = JPEG_DECODER_RETRY_DISABLE;

    if (req_p->media_mode == MED_MODE_FILE)
    {
        if (req_p->media_type == MED_TYPE_JPG)
        {
            /* init jpeg */
            kal_uint8 dec_ret = JPEG_DECODE_UNSUPPORT_FORMAT;

            img_context_p->display_width = req_p->display_width;
            img_context_p->display_height = req_p->display_height;
            img_context_p->image_clip_x1 = req_p->image_clip_x1;
            img_context_p->image_clip_x2 = req_p->image_clip_x2;
            img_context_p->image_clip_y1 = req_p->image_clip_y1;
            img_context_p->image_clip_y2 = req_p->image_clip_y2;
            img_context_p->image_buffer_address = (kal_uint32) req_p->image_buffer_p;
            img_context_p->image_buffer_size = (kal_uint32) req_p->image_buffer_size;
            img_context_p->file_handle = (kal_int32) req_p->data;
            img_context_p->seq_num = req_p->seq_num;
            img_context_p->blocking = req_p->blocking;
            img_context_p->callback = req_p->callback;
            img_context_p->file_buffer_address = (kal_uint32) med_alloc_ext_mem(MAX_IMG_DEC_FILE_BUFFER_LEN);
            img_context_p->file_buffer_size = MAX_IMG_DEC_FILE_BUFFER_LEN;

            get_jpeg_resize_size(
                img_context_p->file_handle,
                img_context_p->file_buffer_address,
                img_context_p->file_buffer_size,
                &(img_context_p->display_width),
                &(img_context_p->display_height),
                &(img_context_p->image_width),
                &(img_context_p->image_height));

            jpg_decode.jpeg_file_handle = img_context_p->file_handle;
            /* DRM_REPLACE */
            /* FS_GetFileSize(img_context_p->file_handle, &img_context_p->file_size); */
            DRM_file_size(img_context_p->file_handle, &img_context_p->file_size);
            jpg_decode.jpeg_file_buffer_address = img_context_p->file_buffer_address;
            jpg_decode.jpeg_file_buffer_size = img_context_p->file_buffer_size;
            jpg_decode.intmem_start_address = img_context_p->intmem_start_address =
                (kal_uint32) med_alloc_int_mem(MAX_IMG_DEC_INT_MEM_SIZE);
            jpg_decode.intmem_size = img_context_p->intmem_size = MAX_IMG_DEC_INT_MEM_SIZE;
            img_context_p->extmem_start_address = (kal_uint32) med_alloc_ext_mem(MAX_PROG_JPG_DEC_EXT_MEM_SIZE);
            if (img_context_p->extmem_start_address)
            {
                img_context_p->extmem_size = MAX_PROG_JPG_DEC_EXT_MEM_SIZE;
            }
            else
            {
                kal_uint32 buf_size = MAX_PROG_JPG_DEC_EXT_MEM_SIZE ;
                /* this is for the case that target buffer size is allcated from MED */
                do
                {
                    buf_size = buf_size / 2;
                    img_context_p->extmem_start_address = (kal_uint32) med_alloc_ext_mem(buf_size);
                } while ((buf_size > MAX_IMG_DEC_EXT_MEM_SIZE) && img_context_p->extmem_start_address == NULL);

                if (img_context_p->extmem_start_address)
                {
                    img_context_p->extmem_size = buf_size;
                }
                else
                {
                    if ((img_context_p->extmem_start_address =
                         (kal_uint32) med_alloc_ext_mem(MAX_IMG_DEC_EXT_MEM_SIZE)) == 0)
                    {
                        ASSERT(img_context_p->extmem_start_address > 0);
                    }
                    img_context_p->extmem_size = MAX_IMG_DEC_EXT_MEM_SIZE;
                }
            }
            jpg_decode.extmem_start_address = img_context_p->extmem_start_address;
            jpg_decode.extmem_size = img_context_p->extmem_size;
            jpg_decode.image_buffer_address = img_context_p->image_buffer_address;
            jpg_decode.image_buffer_size = img_context_p->image_buffer_size;
            jpg_decode.image_width = img_context_p->display_width;
            jpg_decode.image_height = img_context_p->display_height;
            jpg_decode.image_clip_x1 = img_context_p->image_clip_x1;
            jpg_decode.image_clip_x2 = img_context_p->image_clip_x2;
            jpg_decode.image_clip_y1 = img_context_p->image_clip_y1;
            jpg_decode.image_clip_y2 = img_context_p->image_clip_y2;
            jpg_decode.jpeg_decode_cb = img_decode_callback;

            jpg_decode.jpeg_thumbnail_mode = req_p->jpeg_thumbnail_mode;
        #if MT6228_SERIES || defined(MT6225) || defined(MT6223P) || defined(MT6223P_S00) || defined(MT6223) || defined(MT6235)
            jpg_decode.image_pitch_mode = req_p->image_pitch_mode;
            jpg_decode.image_data_format = req_p->image_data_format;
            jpg_decode.image_pitch_bytes = req_p->image_pitch_bytes;

            jpg_decode.memory_output = req_p->memory_output;
            jpg_decode.memory_output_width = req_p->memory_output_width;
            jpg_decode.memory_output_height = req_p->memory_output_height;
            jpg_decode.memory_output_buffer_address = req_p->memory_output_buffer_address;
            jpg_decode.memory_output_buffer_size = req_p->memory_output_buffer_size;
        #endif /* MT6228_SERIES || defined(MT6225) || defined(MT6223P) || defined(MT6223P_S00) || defined(MT6223) || defined(MT6235) */ 

            if (img_context_p->blocking)
            {
                waiting_time = IMG_CODEC_BLOCK_WAITING_TIME;
            }
            else
            {
                waiting_time = IMG_CODEC_RETRY_TIME * ((img_context_p->file_size >> IMG_DECODE_FILE_UNIT) + 1);
            }

        #ifdef __MTK_TARGET__
            dec_ret = jpeg_decode_process(&jpg_decode);
        #endif 
            if (dec_ret == JPEG_DECODE_DECODING)
            {
                img_context_p->processing = KAL_TRUE;
                img_context_p->retry_conut = 0;
                med_start_timer(IMAGE_CODEC_RETRY_TIMER, waiting_time, img_codec_retry_handler, 0);
                IMG_ENTER_STATE(IMG_JPG_DECODE);
                return MED_RES_OK;
            }
            else if (dec_ret == JPEG_DECODE_BUFFER_SIZE_FAIL)
            {
                /* use different buffer size to retry again */
                med_free_ext_mem((void **)&img_context_p->file_buffer_address);
                img_context_p->file_buffer_address = (kal_uint32) med_alloc_ext_mem(MAX_IMG_DEC_FILE_BUFFER_LEN * 2);
                jpg_decode.jpeg_file_buffer_address = img_context_p->file_buffer_address;
                jpg_decode.jpeg_file_buffer_size = img_context_p->file_buffer_size = MAX_IMG_DEC_FILE_BUFFER_LEN * 2;

                //kal_prompt_trace(MOD_MED, "[MED_IMG] stop_jpeg_decode_process: 6");
                /* stop jpeg decode process */
                //stop_jpeg_decode_process();

                dec_ret = jpeg_decode_process(&jpg_decode);
                if (dec_ret == JPEG_DECODE_DECODING)
                {
                    img_context_p->processing = KAL_TRUE;
                    img_context_p->retry_conut = 0;
                    med_start_timer(IMAGE_CODEC_RETRY_TIMER, waiting_time, img_codec_retry_handler, 0);
                    IMG_ENTER_STATE(IMG_JPG_DECODE);
                    return MED_RES_OK;
                }
                else if (dec_ret == JPEG_DECODE_BUFFER_SIZE_FAIL)
                {
                    /* use different buffer size to retry again */
                    med_free_ext_mem((void **)&img_context_p->file_buffer_address);
                    img_context_p->file_buffer_address =
                        (kal_uint32) med_alloc_ext_mem(MAX_IMG_DEC_FILE_BUFFER_LEN * 3);
                    jpg_decode.jpeg_file_buffer_address = img_context_p->file_buffer_address;
                    jpg_decode.jpeg_file_buffer_size = img_context_p->file_buffer_size =
                        MAX_IMG_DEC_FILE_BUFFER_LEN * 3;
                    //kal_prompt_trace(MOD_MED, "[MED_IMG] stop_jpeg_decode_process: 7");                    /* stop jpeg decode process */
                    /* stop jpeg decode process */                    
                    //stop_jpeg_decode_process();

                    dec_ret = jpeg_decode_process(&jpg_decode);
                    if (dec_ret == JPEG_DECODE_DECODING)
                    {
                        img_context_p->processing = KAL_TRUE;
                        img_context_p->retry_conut = 0;
                        med_start_timer(IMAGE_CODEC_RETRY_TIMER, waiting_time, img_codec_retry_handler, 0);
                        IMG_ENTER_STATE(IMG_JPG_DECODE);
                        return MED_RES_OK;
                    }
                    else
                    {
                        //kal_prompt_trace(MOD_MED, "[MED_IMG] stop_jpeg_decode_process: 8");
                        /* stop jpeg decode process */
                        //stop_jpeg_decode_process();

                        img_release_memory();
                        result = img_get_decode_res(dec_ret);
                        return result;
                    }
                }
                else
                {
                    //kal_prompt_trace(MOD_MED, "[MED_IMG] stop_jpeg_decode_process: 9");
                    /* stop jpeg decode process */
                    //stop_jpeg_decode_process();
                
                    img_release_memory();
                    result = img_get_decode_res(dec_ret);
                    return result;
                }
            }
            else
            {
                //kal_prompt_trace(MOD_MED, "[MED_IMG] stop_jpeg_decode_process: 10");
                /* stop jpeg decode process */
                //stop_jpeg_decode_process();
            
                img_release_memory();
                result = img_get_decode_res(dec_ret);
                img_set_decoded_width(img_context_p->image_width);
                if (dec_ret == JPEG_DECODE_SUCCESS)
                {
                    if (img_context_p->callback != NULL)
                    {
                        img_context_p->callback(result);
                    }
                    IMG_ENTER_STATE(IMG_IDLE);
                    if (!img_context_p->blocking)
			        {
			            img_send_decode_finish_ind((kal_int16) result, img_context_p->seq_num);
			        }
                    else
			            IMG_SET_EVENT(IMG_EVT_DECODE);
                }
                return result;
            }
        }
        else
        {
            img_release_memory();
            return MED_RES_INVALID_FORMAT;
        }
    }
    else if (req_p->media_mode == MED_MODE_ARRAY)
    {
        if (req_p->media_type == MED_TYPE_JPG)
        {
            /* init jpeg */
            kal_uint8 dec_ret = JPEG_DECODE_UNSUPPORT_FORMAT;

            img_context_p->file_buffer_address = (kal_uint32) req_p->data;
            img_context_p->file_size = req_p->file_size;
            img_context_p->display_width = req_p->display_width;
            img_context_p->display_height = req_p->display_height;
            img_context_p->image_clip_x1 = req_p->image_clip_x1;
            img_context_p->image_clip_x2 = req_p->image_clip_x2;
            img_context_p->image_clip_y1 = req_p->image_clip_y1;
            img_context_p->image_clip_y2 = req_p->image_clip_y2;
            img_context_p->image_buffer_address = (kal_uint32) req_p->image_buffer_p;
            img_context_p->image_buffer_size = (kal_uint32) req_p->image_buffer_size;
            img_context_p->seq_num = req_p->seq_num;
            img_context_p->blocking = req_p->blocking;
            img_context_p->file_handle = 0;
            img_context_p->callback = req_p->callback;

            if (req_p->data != NULL && req_p->file_size > 0)
            {

                get_jpeg_resize_size(
                    0,
                    img_context_p->file_buffer_address,
                    img_context_p->file_size,
                    &(img_context_p->display_width),
                    &(img_context_p->display_height),
                    &(img_context_p->image_width),
                    &(img_context_p->image_height));

                jpg_decode.jpeg_file_handle = 0;
                jpg_decode.jpeg_file_buffer_address = img_context_p->file_buffer_address;
                jpg_decode.jpeg_file_size = img_context_p->file_size;
                jpg_decode.intmem_start_address = img_context_p->intmem_start_address =
                    (kal_uint32) med_alloc_int_mem(MAX_IMG_DEC_INT_MEM_SIZE);
                jpg_decode.intmem_size = img_context_p->intmem_size = MAX_IMG_DEC_INT_MEM_SIZE;
                img_context_p->extmem_start_address = (kal_uint32) med_alloc_ext_mem(MAX_PROG_JPG_DEC_EXT_MEM_SIZE);
                if (img_context_p->extmem_start_address)
                {
                    img_context_p->extmem_size = MAX_PROG_JPG_DEC_EXT_MEM_SIZE;
                }
                else
                {
                    if ((img_context_p->extmem_start_address =
                         (kal_uint32) med_alloc_ext_mem(MAX_IMG_DEC_EXT_MEM_SIZE)) == 0)
                    {
                        ASSERT(img_context_p->extmem_start_address > 0);
                    }
                    img_context_p->extmem_size = MAX_IMG_DEC_EXT_MEM_SIZE;
                }
                jpg_decode.extmem_start_address = img_context_p->extmem_start_address;
                jpg_decode.extmem_size = img_context_p->extmem_size;
                jpg_decode.image_buffer_address = img_context_p->image_buffer_address;
                jpg_decode.image_buffer_size = img_context_p->image_buffer_size;
                jpg_decode.image_width = img_context_p->display_width;
                jpg_decode.image_height = img_context_p->display_height;
                jpg_decode.image_clip_x1 = img_context_p->image_clip_x1;
                jpg_decode.image_clip_x2 = img_context_p->image_clip_x2;
                jpg_decode.image_clip_y1 = img_context_p->image_clip_y1;
                jpg_decode.image_clip_y2 = img_context_p->image_clip_y2;
                jpg_decode.jpeg_decode_cb = img_decode_callback;

                jpg_decode.jpeg_thumbnail_mode = req_p->jpeg_thumbnail_mode;
            #if MT6228_SERIES || defined(MT6225) || defined(MT6223P) || defined(MT6223P_S00) || defined(MT6223) || defined(MT6235)
                jpg_decode.image_pitch_mode = req_p->image_pitch_mode;
                jpg_decode.image_data_format = req_p->image_data_format;
                jpg_decode.image_pitch_bytes = req_p->image_pitch_bytes;

                jpg_decode.memory_output = req_p->memory_output;
                jpg_decode.memory_output_width = req_p->memory_output_width;
                jpg_decode.memory_output_height = req_p->memory_output_height;
                jpg_decode.memory_output_buffer_address = req_p->memory_output_buffer_address;
                jpg_decode.memory_output_buffer_size = req_p->memory_output_buffer_size;
            #endif /* MT6228_SERIES || defined(MT6225) || defined(MT6223P) || defined(MT6223P_S00) || defined(MT6223) || defined(MT6235) */ 
                if (img_context_p->blocking)
                {
                    waiting_time = IMG_CODEC_BLOCK_WAITING_TIME;
                }
                else
                {
                    waiting_time = IMG_CODEC_RETRY_TIME * ((img_context_p->file_size >> IMG_DECODE_FILE_UNIT) + 1);
                }

            #ifdef __MTK_TARGET__
                dec_ret = jpeg_decode_process(&jpg_decode);
            #endif 
                if (dec_ret == JPEG_DECODE_DECODING)
                {
                    img_context_p->processing = KAL_TRUE;
                    img_context_p->retry_conut = 0;
                    med_start_timer(IMAGE_CODEC_RETRY_TIMER, waiting_time, img_codec_retry_handler, 0);
                    IMG_ENTER_STATE(IMG_JPG_DECODE);
                    return MED_RES_OK;
                }
                else
                {
                    img_context_p->file_buffer_address = NULL;
                    img_release_memory();
                    result = img_get_decode_res(dec_ret);
                    img_set_decoded_width(img_context_p->image_width);
                    return result;
                }
            }
            else    /* parameters not correct */
            {
                img_context_p->file_buffer_address = NULL;
                img_release_memory();
                return MED_RES_ERROR;
            }
        }
        else
        {
            return MED_RES_INVALID_FORMAT;
        }
    }
    else
    {
        return MED_RES_ERROR;
    }
}
#endif /* JPG_DECODE */ 

#if 0//REMOVE FOR GDI TASKdefined(USE_HW_GIF_DECODER_V2)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(USE_HW_GIF_DECODER_V2) */ 

#if 0//REMOVE FOR GDI TASKdefined(USE_HW_PNG_DECODER_V1) || defined(USE_SW_PNG_DECODER)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(USE_HW_PNG_DECODER_V1) */ 


/*****************************************************************************
 * FUNCTION
 *  img_decode_req_hdlr
 * DESCRIPTION
 *  This function is to handle thd decode request.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void img_decode_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int16 result;
    media_img_decode_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    img_context_p->src_mod = ilm_ptr->src_mod_id;

    req_p = (media_img_decode_req_struct*) ilm_ptr->local_para_ptr;

    img_context_p->seq_num = req_p->seq_num;
    img_context_p->blocking = req_p->blocking;

    if (!IMG_IN_STATE(IMG_IDLE))
    {
        img_set_result(MED_RES_BUSY);
        IMG_SET_EVENT(IMG_EVT_DECODE);
        if (!img_context_p->blocking)
        {
            img_send_decode_finish_ind(MED_RES_BUSY, img_context_p->seq_num);
        }
        return;
    }

    img_context_p->media_mode = req_p->media_mode;
    img_context_p->media_type = req_p->media_type;
    img_context_p->has_retried = FALSE;
#if 0 //REMOVE FOR GDI TASKdef JPG_DECODE
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* JPG_DECODE */ 
#if 0//REMOVE FOR GDI TASKdefined(USE_HW_GIF_DECODER_V2)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(USE_HW_GIF_DECODER_V2) */ 
#if 0//REMOVE FOR GDI TASKdefined(USE_HW_PNG_DECODER_V1) || defined(USE_SW_PNG_DECODER)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(USE_HW_PNG_DECODER_V1) */ 
    {
        result = MED_RES_INVALID_FORMAT;
    }

    /* finializer */
    if (result == MED_RES_OK)
    {
        if (!img_context_p->blocking)
        {
            IMG_SET_EVENT(IMG_EVT_DECODE);
        }
    }
    else
    {
        if (!img_context_p->blocking)
        {
            img_send_decode_finish_ind(result, img_context_p->seq_num);
        }
        img_set_result(result);
        IMG_SET_EVENT(IMG_EVT_DECODE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  img_encode_callback
 * DESCRIPTION
 *  This function is the callback function of encoding.
 * PARAMETERS
 *  cause       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void img_encode_callback(kal_uint8 cause)
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
 *  img_encode_event_ind_hdlr
 * DESCRIPTION
 *  This function is the event handler for encoding.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void img_encode_event_ind_hdlr(ilm_struct *ilm_ptr)
{
#ifdef JPG_ENCODE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //media_img_encode_event_ind_struct *ind_p;
    //ind_p=(media_img_encode_event_ind_struct*)ilm_ptr->local_para_ptr;

#endif /* JPG_ENCODE */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  img_encode_req_hdlr
 * DESCRIPTION
 *  This function is to handle thd encode request.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void img_encode_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_img_encode_req_struct *req_p;
    kal_int16 result;
    MMDI_SCENERIO_ID old_app;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    img_context_p->src_mod = ilm_ptr->src_mod_id;

    req_p = (media_img_encode_req_struct*) ilm_ptr->local_para_ptr;

    img_context_p->seq_num = req_p->seq_num;
    img_context_p->blocking = req_p->blocking;
#if defined(MT6223P) || defined(MT6223P_S00) || defined(MT6223)
    if (!IMG_IN_STATE(IMG_IDLE))
#else /* defined(MT6223P) || defined(MT6223P_S00) || defined(MT6223) */
    if (!IMG_IN_STATE(IMG_IDLE) || KAL_TRUE != idp_register_app(SCENARIO_JPEG_ENCODE_ID,&old_app))
#endif    
    {
        img_set_result(MED_RES_BUSY);
        IMG_SET_EVENT(IMG_EVT_ENCODE);
        if (!img_context_p->blocking)
        {
            img_send_encode_finish_ind(MED_RES_BUSY, img_context_p->seq_num);
        }
        return;
    }

#ifdef __MED_CAM_MOD__

    CAM_FREE_CAPTURE_BUFFER();
#endif /* __MED_CAM_MOD__ */ 

    if (req_p->media_mode == MED_MODE_FILE)
    {
        if (req_p->media_type == MED_TYPE_JPG)
        {
            if ((result = img_open_image_file((kal_wchar*) req_p->data)) == MED_RES_OK)
            {
            #ifdef JPG_ENCODE
                jpeg_encode_process_struct jpg_encode;

                img_context_p->media_mode = req_p->media_mode;
                img_context_p->file_name_p = (kal_wchar*) req_p->data;

            #ifdef __MED_VID_MOD__
                if (VID_IN_STATE(VID_PLAY) || VID_IN_STATE(VID_PLAY_PAUSED) || VID_IN_STATE(VID_FILE_READY))
                    jpg_encode.intmem_size = img_context_p->intmem_size = 0;
                else   
                    jpg_encode.intmem_size = img_context_p->intmem_size = MAX_IMG_ENC_INT_MEM_SIZE;
            #else
                jpg_encode.intmem_size = img_context_p->intmem_size = MAX_IMG_ENC_INT_MEM_SIZE;
            #endif /* __MED_VID_MOD__ */

                if (jpg_encode.intmem_size > 0)
                {
                    jpg_encode.intmem_start_address = img_context_p->intmem_start_address =
                        (kal_uint32) med_alloc_int_mem(MAX_IMG_ENC_INT_MEM_SIZE);
                }
                else
                {
                    jpg_encode.intmem_start_address = img_context_p->intmem_start_address = 0;
                }
            #if defined(MT6225) || defined(MT6223P) || defined(MT6223P_S00) || defined(MT6223) || defined(MT6235)
    	        #ifdef DRV_JPG_ENC_DIRECT_COUPLE_SUPPORT
            	jpg_encode.memory_output = FALSE;
                #endif
            	jpg_encode.input_type					=IMAGE_FORMAT_RGB565;		
            	jpg_encode.output_type					=IMAGE_FORMAT_YUV420;	               

                {
                    kal_uint32 img_width ,img_height ,channel_size;
                    kal_uint32 y_address,u_address,v_address ;

                    img_width = (req_p->image_width%16==0)? req_p->image_width : 16 - (req_p->image_width%16) + req_p->image_width;
                    img_height = (req_p->image_height%16==0)? req_p->image_height :16 - (req_p->image_height%16) + req_p->image_height;
                    channel_size = img_width*img_height;

                    /* color mode */
                    img_context_p->yuv_channel_size = channel_size;
                    img_context_p->y_address = y_address = (kal_uint32) med_alloc_ext_mem(channel_size);
                    img_context_p->u_address = u_address = (kal_uint32) med_alloc_ext_mem(channel_size/4);
                    img_context_p->v_address = v_address = (kal_uint32) med_alloc_ext_mem(channel_size/4);

                    EXT_ASSERT ((img_context_p->y_address != NULL) &&
                                (img_context_p->u_address != NULL) &&
                                (img_context_p->v_address != NULL)
                                ,img_context_p->y_address
                                ,img_context_p->u_address
                                ,img_context_p->v_address);

                    jpg_encode.jpeg_yuv_data[0] = (kal_uint8*) y_address;
                    jpg_encode.jpeg_yuv_data[1] = (kal_uint8*) u_address;
                    jpg_encode.jpeg_yuv_data[2] = (kal_uint8*) v_address;

                    jpg_encode.jpeg_yuv_size[0] = channel_size;
                    jpg_encode.jpeg_yuv_size[1] = channel_size/4;
                    jpg_encode.jpeg_yuv_size[2] = channel_size/4;
                    
                }
            #else /* defined(MT6225) || defined(MT6223P) || defined(MT6223P_S00) || defined(MT6223) || defined(MT6235) */
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
                jpg_encode.target_width = req_p->target_width;
                jpg_encode.target_height = req_p->target_height;
                jpg_encode.jpeg_gray_mode = req_p->gray_mode;
                jpg_encode.jpeg_encode_cb = img_encode_callback;
            #endif /* defined(MT6225) || defined(MT6223P) || defined(MT6223P_S00) || defined(MT6223) || defined(MT6235) */
                jpg_encode.image_quality = req_p->image_quality;
                jpg_encode.image_buffer_address = (kal_uint32) req_p->image_buffer_p;
                jpg_encode.image_width = req_p->image_width;
                jpg_encode.image_height = req_p->image_height;

                jpg_encode.jpeg_file_start_address = img_context_p->file_buffer_address;
                jpg_encode.jpeg_file_buffer_size=img_context_p->file_buffer_size;

            #if MT6228_SERIES
                jpg_encode.jpeg_yuv_mode = req_p->jpeg_yuv_mode;  /* req_p->jpeg_yuv_mode; */

                jpg_encode.thumbnail_mode = KAL_FALSE;  /* req_p->thumbnail_mode; */
                jpg_encode.thumbnail_width = req_p->thumbnail_width;
                jpg_encode.thumbnail_height = req_p->thumbnail_height;

                jpg_encode.overlay_frame_mode = KAL_FALSE;  /* req_p->overlay_frame_mode; */
                jpg_encode.overlay_color_depth = req_p->overlay_color_depth;
                jpg_encode.overlay_frame_source_key = req_p->overlay_frame_source_key;
                jpg_encode.overlay_frame_width = req_p->overlay_frame_width;
                jpg_encode.overlay_frame_height = req_p->overlay_frame_height;
                jpg_encode.overlay_frame_buffer_address = req_p->overlay_frame_buffer_address;
            #endif /* MT6228_SERIES */ 

            #ifdef __MTK_TARGET__
            #ifdef __MED_VID_MOD__
                if (VID_IN_STATE(VID_PLAY) || VID_IN_STATE(VID_PLAY_PAUSED) || VID_IN_STATE(VID_FILE_READY))
                {
                    #if defined(__SW_JPEG_CODEC_SUPPORT__) && !defined(WIN32)
                    {
                        kal_uint32 stack_begin;
                        med_get_med_int_stack_mem(&stack_begin);

                        img_context_p->file_size = INT_SwitchStackToRun((void*)stack_begin,MED_INT_STACK_MEM_SIZE,(kal_func_ptr)jpeg_encode_snapshot_process, 1,&jpg_encode);

                        med_free_med_int_stack_mem();
                    }
                    #else
                    {
                        img_context_p->file_size = jpeg_encode_snapshot_process(&jpg_encode);
                    }
                    #endif

                }
                else
            #endif /* __MED_VID_MOD__ */ 
                {
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
                }

                exit_jpeg_encode_process();
            #endif /* __MTK_TARGET__ */ 
                if (!img_context_p->blocking)
                {
                    IMG_SET_EVENT(IMG_EVT_ENCODE);
                }

                result = img_close_image_file(img_context_p->file_size);

                if (img_context_p->blocking)
                {
                    img_set_result(result);
                    IMG_SET_EVENT(IMG_EVT_ENCODE);
                }
                else
                {
                    img_send_encode_finish_ind(result, img_context_p->seq_num);
                }

            #else /* JPG_ENCODE */ /* JPG_ENCODE not defined */
                img_close_image_file(0);
                IMG_SET_EVENT(IMG_EVT_ENCODE);
                img_send_encode_finish_ind(MED_RES_INVALID_FORMAT, req_p->seq_num);
            #endif /* JPG_ENCODE */ 
            }
            else
            {
                /* open file fail */
                img_set_result(result);
                IMG_SET_EVENT(IMG_JPG_ENCODE);
            }
        }
        else
        {
            img_send_encode_finish_ind(MED_RES_INVALID_FORMAT, img_context_p->seq_num);
        }
    }
    else if (req_p->media_mode == MED_MODE_ARRAY)
    {
        if (req_p->media_type == MED_TYPE_JPG)
        {
        #ifdef JPG_ENCODE
            jpeg_encode_process_struct jpg_encode;

            img_context_p->media_mode = req_p->media_mode;


        #ifdef __MED_VID_MOD__
            if (VID_IN_STATE(VID_PLAY) || VID_IN_STATE(VID_PLAY_PAUSED) || VID_IN_STATE(VID_FILE_READY))
                jpg_encode.intmem_size = img_context_p->intmem_size = 0;
            else   
                jpg_encode.intmem_size = img_context_p->intmem_size = MAX_IMG_ENC_INT_MEM_SIZE;
        #else
            jpg_encode.intmem_size = img_context_p->intmem_size=MAX_IMG_ENC_INT_MEM_SIZE;
        #endif /* __MED_VID_MOD__ */

            if (jpg_encode.intmem_size > 0)
            {
                jpg_encode.intmem_start_address = img_context_p->intmem_start_address =
                    (kal_uint32) med_alloc_int_mem(MAX_IMG_ENC_INT_MEM_SIZE);
            }
            else
            {
                jpg_encode.intmem_start_address = img_context_p->intmem_start_address = 0;
            }
        #if !(defined(MT6225)|| defined(MT6223P) || defined(MT6223P_S00) || defined(MT6223) || defined(MT6235))
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
            jpg_encode.target_width = req_p->target_width;
            jpg_encode.target_height = req_p->target_height;
            jpg_encode.jpeg_gray_mode = req_p->gray_mode;
            jpg_encode.jpeg_encode_cb = img_encode_callback;
        #endif /* !(defined(MT6225) || defined(MT6223P) || defined(MT6223P_S00) || defined(MT6223) || defined(MT6235)) */

        #if defined(MT6225) || defined(MT6223P) || defined(MT6223P_S00) || defined(MT6223) || defined(MT6235)
            #ifdef DRV_JPG_ENC_DIRECT_COUPLE_SUPPORT
        	jpg_encode.memory_output = FALSE;
            #endif
        #endif /* defined(MT6225) || defined(MT6223P) || defined(MT6223P_S00) || defined(MT6223)  || defined(MT6235)*/
            jpg_encode.image_quality = req_p->image_quality;
            jpg_encode.image_buffer_address = (kal_uint32) req_p->image_buffer_p;
            jpg_encode.image_width = req_p->image_width;
            jpg_encode.image_height = req_p->image_height;

            jpg_encode.jpeg_file_start_address = (kal_uint32) req_p->data;
            jpg_encode.jpeg_file_buffer_size = req_p->file_buffer_len;

        #if MT6228_SERIES
            jpg_encode.jpeg_yuv_mode = req_p->jpeg_yuv_mode;  /* req_p->jpeg_yuv_mode; */

            jpg_encode.thumbnail_mode = KAL_FALSE;  /* req_p->thumbnail_mode; */
            jpg_encode.thumbnail_width = req_p->thumbnail_width;
            jpg_encode.thumbnail_height = req_p->thumbnail_height;

            jpg_encode.overlay_frame_mode = KAL_FALSE;  /* req_p->overlay_frame_mode; */
            jpg_encode.overlay_color_depth = req_p->overlay_color_depth;
            jpg_encode.overlay_frame_source_key = req_p->overlay_frame_source_key;
            jpg_encode.overlay_frame_width = req_p->overlay_frame_width;
            jpg_encode.overlay_frame_height = req_p->overlay_frame_height;
            jpg_encode.overlay_frame_buffer_address = req_p->overlay_frame_buffer_address;
        #endif /* MT6228_SERIES */ 

            if (req_p->data != NULL && req_p->file_buffer_len > 0)
            {
            #ifdef __MTK_TARGET__
            #ifdef __MED_VID_MOD__
                if (VID_IN_STATE(VID_PLAY) || VID_IN_STATE(VID_PLAY_PAUSED) || VID_IN_STATE(VID_FILE_READY))
                {
                    #if defined(__SW_JPEG_CODEC_SUPPORT__) && !defined(WIN32)
                    {
                        kal_uint32 stack_begin;
                        med_get_med_int_stack_mem(&stack_begin);

                        img_context_p->file_size = INT_SwitchStackToRun((void*)stack_begin,MED_INT_STACK_MEM_SIZE,(kal_func_ptr)jpeg_encode_snapshot_process, 1,&jpg_encode);

                        med_free_med_int_stack_mem();
                    }
                    #else
                    {
                        img_context_p->file_size = jpeg_encode_snapshot_process(&jpg_encode);
                    }
                    #endif
                }
                else
            #endif /* __MED_VID_MOD__ */ 
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
                img_release_memory();

                if (!img_context_p->blocking)
                {
                    IMG_SET_EVENT(IMG_EVT_ENCODE);
                }

                *(req_p->file_size_p) = img_context_p->file_size;

                result = img_context_p->file_size > 0 ? MED_RES_OK : MED_RES_FAIL;
                if (img_context_p->blocking)
                {
                    img_set_result(result);
                    IMG_SET_EVENT(IMG_EVT_ENCODE);
                }
                else
                {
                    img_send_encode_finish_ind(result, img_context_p->seq_num);
                }
            }
            else
            {
                img_release_memory();
                img_set_result(MED_RES_MEM_INSUFFICIENT);
                IMG_SET_EVENT(IMG_EVT_ENCODE);
                if (!img_context_p->blocking)
                {
                    img_send_encode_finish_ind(MED_RES_MEM_INSUFFICIENT, img_context_p->seq_num);
                }
            }
        #else /* JPG_ENCODE */ /* JPG_ENCODE not defined */
            IMG_SET_EVENT(IMG_EVT_ENCODE);
            img_send_encode_finish_ind(MED_RES_INVALID_FORMAT, req_p->seq_num);
        #endif /* JPG_ENCODE */ 
        }
        else
        {
            img_send_encode_finish_ind(MED_RES_INVALID_FORMAT, img_context_p->seq_num);
        }
    }
    else    /* MED_MODE_STREAM */
    {
        img_send_encode_finish_ind(MED_RES_INVALID_FORMAT, img_context_p->seq_num);
    }

}


/*****************************************************************************
 * FUNCTION
 *  img_stop_req_hdlr
 * DESCRIPTION
 *  This function is to stop all processes
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void img_stop_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    img_context_p->src_mod = ilm_ptr->src_mod_id;

    switch (img_context_p->state)
    {
    #if defined(JPG_DECODE)
        case IMG_JPG_DECODE:
    #ifdef __MTK_TARGET__
            kal_prompt_trace(MOD_MED, "[MED_IMG] stop_jpeg_decode_process:5");
            stop_jpeg_decode_process();
            img_context_p->processing = KAL_FALSE;
            med_stop_timer(IMAGE_CODEC_RETRY_TIMER);
    #endif /* __MTK_TARGET__ */ 
            img_release_memory();
            break;
    #endif /* defined(JPG_DECODE) */ 
    #if defined(JPG_ENCODE)
        case IMG_JPG_ENCODE:
    #ifdef __MTK_TARGET__
            exit_jpeg_encode_process();
    #endif 
            img_release_memory();
            break;
    #endif /* defined(JPG_ENCODE) */ 
        default:
            /* ASSERT(img_context_p->state!=IMG_IDLE) */
            break;
    }

    IMG_ENTER_STATE(IMG_IDLE);
    IMG_SET_EVENT(IMG_EVT_STOP);

}


/*****************************************************************************
 * FUNCTION
 *  img_resize_req_hdlr
 * DESCRIPTION
 *  This function is to handle thd resize request.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void img_resize_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_img_resize_req_struct *req_p;
    MMDI_SCENERIO_ID old_app;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    img_context_p->src_mod = ilm_ptr->src_mod_id;

#if defined(MT6223P) || defined(MT6223P_S00) || defined(MT6223)
    if (!IMG_IN_STATE(IMG_IDLE))
#else /* defined(MT6223P) || defined(MT6223P_S00) || defined(MT6223) */  
    if (!IMG_IN_STATE(IMG_IDLE) || KAL_TRUE != idp_register_app(SCENARIO_JPEG_RESIZE_ID,&old_app))
#endif
    {
        img_set_result(MED_RES_BUSY);
        IMG_SET_EVENT(IMG_EVT_RESIZE);
        if (!img_context_p->blocking)
        {
            img_send_resize_done_ind(MED_RES_BUSY, img_context_p->seq_num);
        }
        return;
    }


    req_p = (media_img_resize_req_struct*) ilm_ptr->local_para_ptr;

    img_context_p->seq_num = req_p->seq_num;
    img_context_p->blocking = req_p->blocking;

    if (img_context_p->state == IMG_IDLE)
    {
        kal_int16 result;

    #if (MT6219_SERIES || MT6228_SERIES)

        resize_struct resize;

        resize.target_pitch = req_p->src_pitch * req_p->target_width / req_p->src_width;
        if (resize.target_pitch * 12 > MAX_IMG_DEC_INT_MEM_SIZE)
        {
            img_set_result(MED_RES_MEM_INSUFFICIENT);
            IMG_SET_EVENT(IMG_EVT_RESIZE);
            return;
        }
        resize.src_image_address = req_p->src_image_address;
        resize.dest_image_address = req_p->dest_image_address;
        resize.dest_buffer_size = req_p->dest_buffer_size;
        resize.intmem_start_address = img_context_p->intmem_start_address =
            (kal_uint32) med_alloc_int_mem(MAX_IMG_DEC_INT_MEM_SIZE);
        resize.intmem_size = img_context_p->intmem_size = MAX_IMG_DEC_INT_MEM_SIZE;
        resize.extmem_start_address = img_context_p->extmem_start_address =
            (kal_uint32) med_alloc_ext_mem(MAX_IMG_DEC_EXT_MEM_SIZE);
        resize.extmem_size = img_context_p->extmem_size = MAX_IMG_DEC_EXT_MEM_SIZE;
        resize.src_width = req_p->src_width;
        resize.src_height = req_p->src_height;
        resize.src_pitch = req_p->src_pitch;
        resize.target_width = req_p->target_width;
        resize.target_height = req_p->target_height;
        resize.image_clip_x1 = req_p->image_clip_x1;
        resize.image_clip_x2 = req_p->image_clip_x2;
        resize.image_clip_y1 = req_p->image_clip_y1;
        resize.image_clip_y2 = req_p->image_clip_y2;
        resize.type = req_p->type;
        resize.data_order = req_p->data_order;

    #if MT6228_SERIES
        resize.image_pitch_mode = req_p->image_pitch_mode;
        resize.image_data_format = req_p->image_data_format;
        resize.image_pitch_bytes = req_p->image_pitch_bytes;
    #endif /* MT6228_SERIES */ 

        if (!req_p->blocking)
        {
            IMG_SET_EVENT(IMG_EVT_RESIZE);
        }

    #ifdef __MTK_TARGET__
        if (image_resize_process(&resize) == KAL_TRUE)
        {
            result = MED_RES_OK;
        }
        else
        {
            result = MED_RES_ERROR;
        }
    #else
        result = MED_RES_OK;
    #endif

        img_release_memory();
    #endif /* (MT6219_SERIES || MT6228_SERIES) */ 
        if (!req_p->blocking)
        {
            img_send_resize_done_ind((kal_int16) result, img_context_p->seq_num);
        }
        else
        {
            img_set_result(result);
            IMG_SET_EVENT(IMG_EVT_RESIZE);
        }

    }
    else
    {
        if (!req_p->blocking)
        {
            img_send_resize_done_ind(MED_RES_BUSY, img_context_p->seq_num);
        }
        else
        {
            img_set_result(MED_RES_BUSY);
        }
        IMG_SET_EVENT(IMG_EVT_RESIZE);
    }

}


/*****************************************************************************
 * FUNCTION
 *  img_exif_decode_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void img_exif_decode_req_hdlr(ilm_struct *ilm_ptr)
{
#ifdef EXIF_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_img_exif_decode_req_struct *req_p;
    kal_uint32 req_buffer_size;
    kal_uint8 *buffer_p;
    EXIF_DEC_RESULT exif_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    img_context_p->src_mod = ilm_ptr->src_mod_id;

    req_p = (media_img_exif_decode_req_struct*) ilm_ptr->local_para_ptr;

    req_buffer_size = exif_open_jpeg_file(req_p->exif_info->filename);

    if (req_buffer_size == 0)
    {
        exif_close_jpeg_file();
        img_set_result(MED_RES_FAIL);
        IMG_SET_EVENT(IMG_EVT_EXIF_DECODE);
        return;
    }

    buffer_p = (kal_uint8*) med_alloc_ext_mem(req_buffer_size);

    exif_result = exif_parse_jpeg_file(buffer_p, req_buffer_size);

    if (exif_result != EXIF_DEC_DONE)
    {
        /* read EXIF information error */
        img_set_result(MED_RES_FAIL);
    }
    else
    {
        kal_char *tmp_p;

#define FIELD_COPY(_A_,_TAG_NAME_)                                                      \
                     do                                                                       \
                     {                                                                        \
                        tmp_p=exif_get_tag_value(_TAG_NAME_);                                 \
                        if(tmp_p!=0)                                                          \
                           strncpy(req_p->exif_info->_A_,tmp_p,sizeof(req_p->exif_info->_A_));\
                        else                                                                  \
                           strcpy(req_p->exif_info->_A_,"");                                  \
                     }while(0)

        FIELD_COPY(make, exif_tag_Make);
        FIELD_COPY(model, exif_tag_Model);
        FIELD_COPY(orientation, exif_tag_Orientation);
        FIELD_COPY(x_resolution, exif_tag_XResolution);
        FIELD_COPY(y_resolution, exif_tag_YResolution);
        FIELD_COPY(resolution_unit, exif_tag_ResolutionUnit);
        FIELD_COPY(software, exif_tag_Software);
        FIELD_COPY(date_time, exif_tag_DateTime);
        FIELD_COPY(ycbcr_positioning, exif_tag_YCbCrPositioning);
        FIELD_COPY(exif_ifd, exif_tag_ExifIFD);

        FIELD_COPY(exposure_time, exif_tag_ExposureTime);
        FIELD_COPY(fnumber, exif_tag_FNumber);
        FIELD_COPY(exposure_program, exif_tag_ExposureProgram);
        FIELD_COPY(iso_speed_ratings, exif_tag_ISOSpeedRatings);
        FIELD_COPY(exif_version, exif_tag_ExifVersion);
        FIELD_COPY(date_time_original, exif_tag_DateTimeOriginal);
        FIELD_COPY(date_time_digitized, exif_tag_DateTimeDigitized);
        FIELD_COPY(components_config, exif_tag_ComponentsConfig);
        FIELD_COPY(exposure_bias_value, exif_tag_ExposureBiasValue);
        FIELD_COPY(metering_mode, exif_tag_MeteringMode);
        FIELD_COPY(light_source, exif_tag_LightSource);
        FIELD_COPY(flash, exif_tag_Flash);
        FIELD_COPY(maker_note, exif_tag_MakerNote);
        FIELD_COPY(flashpix_version, exif_tag_FlashpixVersion);
        FIELD_COPY(color_space, exif_tag_ColorSpace);
        FIELD_COPY(pixel_x_dimension, exif_tag_PixelXDimension);
        FIELD_COPY(pixel_y_dimension, exif_tag_PixelYDimension);
        FIELD_COPY(exposure_mode, exif_tag_ExposureMode);
        FIELD_COPY(digital_zoom_ratio, exif_tag_DigitalZoomRatio);
        FIELD_COPY(scene_capture_type, exif_tag_SceneCaptureType);
#undef FIELD_COPY

        img_set_result(MED_RES_OK);
    }

    exif_close_jpeg_file();
    med_free_ext_mem((void **)&buffer_p);
    IMG_SET_EVENT(IMG_EVT_EXIF_DECODE);
#else /* EXIF_SUPPORT */ 
    img_set_result(MED_RES_FAIL);
    IMG_SET_EVENT(IMG_EVT_EXIF_DECODE);
#endif /* EXIF_SUPPORT */ 
}

#endif /* __MED_IMG_MOD__ */ 

#endif /* MED_NOT_PRESENT */ 

