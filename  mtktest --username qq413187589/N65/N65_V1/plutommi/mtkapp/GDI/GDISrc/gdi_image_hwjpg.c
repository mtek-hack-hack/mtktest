/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  gdi_image_hwjpeg.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GDI Image hardware jpeg decoder.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "gdi_internal.h"
#ifdef GDI_USING_JPEG
#include "visual_comm.h"
#include "img_comm.h"
#include "jpeg.h"
#include "drm_gprot.h"
#include "med_global.h"
#include "med_utility.h"

#ifdef  __MMI_A2DP_SUPPORT__
#include "mdi_datatype.h"
#include "mdi_audio.h"
#endif
extern kal_bool idp_register_app(MMDI_SCENERIO_ID new_app, MMDI_SCENERIO_ID *old_app);

#include "gdd_include.h"

#if defined(__SPATIAL_DITHERING__) && defined(__MTK_TARGET__) && defined(GDI_HW_JPEG_SUPPORT_COLOR_FORMAT) && !defined(__SW_JPEG_CODEC_SUPPORT__)
    #define GDI_USING_SPATIAL_DITHERING
//    #include "image_codec_common.h"
    extern void spatial_dithering_bgr8882565(kal_uint8 *pSrc, kal_uint16 *pDest,
                                  kal_uint32 uWidth, kal_uint32 uHeight, kal_uint32 uPitch);
    struct
    {
        gdi_handle   handle;
        U8*             buffer;
        S32             save_ox;
        S32             save_oy;
        S32             save_clipx1;
        S32             save_clipy1;
        S32             save_clipx2;
        S32             save_clipy2;
        S32             is_push_and_set_active;
    } gdi_jpeg_dithering;
#endif

#define GDI_HW_JPEG_CODEC_WAITING_TIME 5000       /* ms */
#define GDI_IMAGE_JPEG_FILE_BUFFER_LEN_WHEN_A2DP_ENABLE 10*1024 /* 10kb */

#define ROUND16(x)   (((x) + 15)&(~0xf))


static jpeg_decode_process_struct jpeg;
static MMI_BOOL jpeg_is_need_stop;
typedef struct
{
    U8 cause;    
    U8 pre_cause;
} gdi_image_hwjpeg_state_struct;

static gdi_image_hwjpeg_state_struct jpeg_result;

extern void gdi_image_hwjpeg_start_decode(void);
/*****************************************************************************
 * FUNCTION
 *  gdi_image_hwjpeg_callback
 * DESCRIPTION
 *  handle the jpeg callback 
 *****************************************************************************/
void gdi_image_hwjpeg_callback(U8 cause)
{
    gdi_image_hwjpeg_state_struct data;
    data.cause = cause;
    gdd_send_img_codec_ind(&data,sizeof(data));
}

/*****************************************************************************
 * FUNCTION
 *  gdi_image_hwjpeg_set_memory
 * DESCRIPTION
 *  try to allocate memory for jpeg decoding from media task.
 *****************************************************************************/
static GDI_RESULT gdi_image_hwjpeg_set_memory(void)
{
    jpeg.intmem_start_address = (U32) med_alloc_int_mem(MAX_IMG_DEC_INT_MEM_SIZE);
    if(jpeg.intmem_start_address==0)
        return GDI_IMAGE_ERR_FRAME_BUFFER_NOT_ENOUGH;
    
    jpeg.intmem_size = MAX_IMG_DEC_INT_MEM_SIZE;
    /* try to allocate large memory to decode jpeg for performance */
    {
        int mem_size = MAX_PROG_JPG_DEC_EXT_MEM_SIZE;
        int min_size = MAX_IMG_DEC_EXT_MEM_SIZE;
        while(1)
        {
            jpeg.extmem_start_address =  (U32)med_alloc_ext_mem(mem_size);
            if(jpeg.extmem_start_address >0) break;
            if(mem_size == min_size) break;
            
            mem_size/=2;
            if( mem_size < min_size)
                mem_size = min_size;
        }
        
        if(jpeg.extmem_start_address==0) 
            return GDI_IMAGE_ERR_FRAME_BUFFER_NOT_ENOUGH;
        jpeg.extmem_size = mem_size;
        MMI_TRACE(GDI_TRC, GDI_TRC_15,//"GDI_HW_JPG set_ext_memory size=%d",
                        mem_size);
    }
    return GDI_SUCCEED;
}
/*****************************************************************************
 * FUNCTION
 *  gdi_image_hwjpeg_set_thumbnail_value
 * DESCRIPTION
 *  setting use thumbnail or not,  driver will use thumbnail if resize size is match
 *****************************************************************************/
static GDI_RESULT gdi_image_hwjpeg_set_thumbnail_value(BOOL is_resized)
{
    if (is_resized)
    {
        jpeg.jpeg_thumbnail_mode = TRUE;
    }
    else
    {
        jpeg.jpeg_thumbnail_mode = FALSE;
    }
    return GDI_SUCCEED;
}
/*****************************************************************************
 * FUNCTION
 *  gdi_image_hwjpeg_set_source_image
 * DESCRIPTION
 *   setting image source
 *****************************************************************************/
static GDI_RESULT gdi_image_hwjpeg_set_source_image(U8* src,U32 size,BOOL is_file)
{
    if (is_file)
    {
        FS_HANDLE fs = DRM_open_file((U16*) src, FS_READ_ONLY, DRM_PERMISSION_DISPLAY);
        if (fs < 0)
            return GDI_IMAGE_ERR_OPEN_FILE_FAILED;
        
        jpeg.jpeg_file_handle = (U32) fs;
        DRM_file_size(fs, &jpeg.jpeg_file_size);
        

        jpeg.jpeg_file_buffer_address = 0;

        // Here will check A2DP is active or not
        // Because A2DP need more CPU to process audio, 
        // JPEG should access file using small file buffer to avoid block A2DP
        #ifdef  __MMI_A2DP_SUPPORT__
        if(mdi_audio_bt_is_a2dp_codec_open())
        {
            jpeg.jpeg_file_buffer_address = (kal_uint32) med_alloc_ext_mem(GDI_IMAGE_JPEG_FILE_BUFFER_LEN_WHEN_A2DP_ENABLE);
            jpeg.jpeg_file_buffer_size = GDI_IMAGE_JPEG_FILE_BUFFER_LEN_WHEN_A2DP_ENABLE;
        }
        else
        #endif
        {
            jpeg.jpeg_file_buffer_address = (kal_uint32) med_alloc_ext_mem(MAX_IMG_DEC_FILE_BUFFER_LEN);
            jpeg.jpeg_file_buffer_size = MAX_IMG_DEC_FILE_BUFFER_LEN;
        }

        if(jpeg.jpeg_file_buffer_address==0)
		{
			jpeg.jpeg_file_buffer_address = (kal_uint32)gdi_bytestream_buffer;
			jpeg.jpeg_file_buffer_size = BYTESTREAM_BUFFER_SIZE;
			//return GDI_IMAGE_ERR_FRAME_BUFFER_NOT_ENOUGH;
		}
            
        MMI_TRACE(GDI_TRC, GDI_TRC_16,//"GDI_HW_JPG set_source_image file mem_size=%d",
                    jpeg.jpeg_file_buffer_size);
    }
    else
    {
        jpeg.jpeg_file_buffer_address = (U32) src;
        jpeg.jpeg_file_buffer_size = (U32) size;
        jpeg.jpeg_file_size = (U32)size;
    }
    return GDI_SUCCEED;
}
/*****************************************************************************
 * FUNCTION
 *  gdi_image_hwjpeg_enlarge_file_buffer
 * DESCRIPTION
 *   setting image source
 *****************************************************************************/
static GDI_RESULT gdi_image_hwjpeg_enlarge_file_buffer(void)
{
    MMI_TRACE(GDI_TRC, GDI_TRC_17//"try gdi_image_hwjpeg_enlarge_file_buffer "
                );

    if(jpeg.jpeg_file_handle)
    {
        // Here will check A2DP is active or not
        // Because A2DP need more CPU to process audio, 
        // JPEG should access file using small file buffer to avoid block A2DP
        #ifdef  __MMI_A2DP_SUPPORT__
        if(mdi_audio_bt_is_a2dp_codec_open())
            return GDI_FAILED;
        #endif
        /* already reach x3 buffer size */
        if(jpeg.jpeg_file_buffer_size >= MAX_IMG_DEC_FILE_BUFFER_LEN*3)
            return GDI_FAILED;
		if(jpeg.jpeg_file_buffer_address != (kal_uint32)gdi_bytestream_buffer)
            med_free_ext_mem((void**)&jpeg.jpeg_file_buffer_address);

        jpeg.jpeg_file_buffer_size += MAX_IMG_DEC_FILE_BUFFER_LEN;
        jpeg.jpeg_file_buffer_address = (kal_uint32) med_alloc_ext_mem(jpeg.jpeg_file_buffer_size);
                
        MMI_TRACE(GDI_TRC, GDI_TRC_18,//"gdi_image_hwjpeg_enlarge_file_buffer size=%d",
                    jpeg.jpeg_file_buffer_size);

        if(jpeg.jpeg_file_buffer_address!=0)
            return GDI_SUCCEED;
    }
    return GDI_FAILED;
}

/*****************************************************************************
 * FUNCTION
 *  gdi_image_hwjpeg_set_real_size
 * DESCRIPTION
 *   parse the jpeg size & real resized size
 *****************************************************************************/
static GDI_RESULT gdi_image_hwjpeg_set_real_size(S32 *resized_width,S32* resized_height,S32 *decoded_image_width)
{
    U16 resized_width16,resized_height16;
    U16 real_resize_width,real_resize_height;

    resized_width16 = (U16)*resized_width;
    resized_height16 = (U16)*resized_height;
    get_jpeg_resize_size(
    jpeg.jpeg_file_handle,
    jpeg.jpeg_file_buffer_address,
    jpeg.jpeg_file_buffer_size,
    &(resized_width16),
    &(resized_height16),
    &(real_resize_width),
    &(real_resize_height));
    
	*decoded_image_width = (S32)real_resize_width;
    
    if (*resized_width == 0 && *resized_height == 0)
    {
        *resized_width = (S32)resized_width16;
        *resized_height = (S32)resized_height16;
    }

    if(resized_width16 == (U16)0xFFFF && resized_height16 == (U16)0xFFFF)
        return GDI_IMAGE_ERR_FILE_FORMAT_WRONG;
    
    return GDI_SUCCEED;
}
/*****************************************************************************
 * FUNCTION
 *  gdi_image_hwjpeg_set_clipping
 * DESCRIPTION
 *   
 *****************************************************************************/
static GDI_RESULT gdi_image_hwjpeg_set_clipping(
                            S32 *ox,S32 *oy,
                            U8 *dest_buf,
                            S32 resized_width,
                            S32 resized_height,
                            S32 *output_clipx1,
                            S32 *output_clipy1,
                            S32 *output_clipx2,
                            S32 *output_clipy2)
{
    /**************************************************************************
    * revise output clipping & (ox,oy)
    **************************************************************************/
    
    /* initialize output_clipping if unset */
    if (*output_clipx1 == -1 && *output_clipy1 == -1 && *output_clipx2 == -1 && *output_clipy2 == -1)
    {
        *output_clipx1 = 0;
        *output_clipy1 = 0;
        *output_clipx2 = resized_width - 1;
        *output_clipy2 = resized_height - 1;
    }
     
    /*output clipping should consider the layer clipping area if output target is active layer*/
    if (NULL == dest_buf)
    {   
        int tx, ty;

        tx = *output_clipx1;
        ty = *output_clipy1;
        *output_clipx1 += *ox;
        *output_clipy1 += *oy;
        *output_clipx2 += *ox;
        *output_clipy2 += *oy;
        GDI_CLIP_RECT_TEST(*output_clipx1, *output_clipy1, *output_clipx2, *output_clipy2, return GDI_IMAGE_OUT_OF_CLIP_REGION);
        *output_clipx1 -= *ox;
        *output_clipy1 -= *oy;
        *output_clipx2 -= *ox;
        *output_clipy2 -= *oy;
    }
    /* adjust (ox,oy) to correct position, because output clipping window may change. */
    *ox += *output_clipx1;
    *oy += *output_clipy1;
    /**************************************************************************
    * setting output width/height/clipping
    **************************************************************************/
    jpeg.image_width = (U16)resized_width;
    jpeg.image_height = (U16)resized_height;
    jpeg.image_clip_x1 = *output_clipx1;
    jpeg.image_clip_y1 = *output_clipy1;
    jpeg.image_clip_x2 = *output_clipx2;
    jpeg.image_clip_y2 = *output_clipy2;
    return GDI_SUCCEED;
}
/*****************************************************************************
 * FUNCTION
 *  gdi_image_hwjpeg_set_dest_buffer
 * DESCRIPTION
 *   
 *****************************************************************************/
static GDI_RESULT gdi_image_hwjpeg_set_dest_buffer(
												    S32 ox,S32 oy,
                                                    U8* *dest_buf,
                                                    S32 *dest_buf_size,
                                                    gdi_color_format *dest_buf_cf,
                                                    S32 resized_width,S32 resized_height,
                                                    S32 output_clipx1,
                                                    S32 output_clipy1,
                                                    S32 output_clipx2,
                                                    S32 output_clipy2)
{
    #if !defined(GDI_HW_JPEG_PADDING_PITCH)
    /* we can direct output if hardware support pitch & source_key_disable & whole layer size is the same as resized jpeg */
    if (NULL == *dest_buf)
    {
        if ((resized_width == gdi_act_layer->width) 
        &&  (resized_height == gdi_act_layer->height))
        {
            if ((jpeg.image_clip_x1 == 0) &&
                (jpeg.image_clip_y1 == 0) && 
                (jpeg.image_clip_x2 == resized_width - 1) && 
                (jpeg.image_clip_y2 == resized_height - 1))
            {
                *dest_buf = gdi_act_layer->buf_ptr;
                *dest_buf_size = gdi_act_layer->layer_size;
                *dest_buf_cf = gdi_act_layer->vcf;
            }
        }
    }
    #endif /* !defined(GDI_HW_JPEG_PADDING_PITCH) */ 
    
    if (NULL == *dest_buf)
    {
        #ifdef GDI_HW_JPEG_SUPPORT_OUTPUT_ANOTHER_BUFFER
        jpeg.memory_output = gdi_memory_output;
        jpeg.memory_output_width = gdi_memory_output_width;
        jpeg.memory_output_height = gdi_memory_output_height;
        jpeg.memory_output_buffer_address = gdi_memory_output_buffer_address;
        jpeg.memory_output_buffer_size = gdi_memory_output_buffer_size;
        #endif /* GDI_HW_JPEG_SUPPORT_OUTPUT_ANOTHER_BUFFER */ 
    
        #ifdef GDI_HW_JPEG_SUPPORT_DIRECT_OUTPUT_BUFFER
        {
            jpeg.image_pitch_mode = TRUE;
            jpeg.image_pitch_bytes = (gdi_act_layer->bits_per_pixel * gdi_act_layer->width + 7) >> 3;
            jpeg.image_buffer_address = (U32)(gdi_act_layer->buf_ptr +
                                         ((((gdi_act_layer->width * oy + ox) * gdi_act_layer->bits_per_pixel) + 7) >> 3));
            jpeg.image_buffer_size = ((U32) gdi_act_layer->buf_ptr + gdi_act_layer->layer_size) - (U32) jpeg.image_buffer_address;
        }
        #else /* GDI_HW_JPEG_SUPPORT_DIRECT_OUTPUT_BUFFER */ 
        {
            if (gdi_sizeof_pixels(
                gdi_act_layer->cf,
                output_clipx2 - output_clipx1 + 1,
                output_clipy2 - output_clipy1 + 1) > gdi_work_buffer_size)
                    return GDI_IMAGE_ERR_FRAME_BUFFER_NOT_ENOUGH;
            
            #ifndef GDI_HW_JPEG_SUPPORT_OUTPUT_CLIPPING
                if (gdi_sizeof_pixels(gdi_act_layer->cf, resized_width, resized_height) > gdi_work_buffer_size)
                    return GDI_IMAGE_ERR_FRAME_BUFFER_NOT_ENOUGH;
            #endif /* GDI_HW_JPEG_SUPPORT_OUTPUT_CLIPPING */ 
            
            if (((ROUND16(output_clipx2 - output_clipx1 + 1)
                  * ROUND16(output_clipy2 - output_clipy1 + 1) * GDI_MAINLCD_BIT_PER_PIXEL) >> 3) > gdi_work_buffer_size)
                return GDI_IMAGE_ERR_FRAME_BUFFER_NOT_ENOUGH;

            /*TODO: Fix Broken JPEG Issue, but it should downgrade performance */
            gdi_memset16((U8*)gdi_work_buffer, (U16)gdi_act_get_pixel(ox,oy), gdi_work_buffer_size);
                
            jpeg.image_buffer_address= (U32)gdi_work_buffer;
            jpeg.image_buffer_size = (U32) gdi_work_buffer_size;
        }
        #endif /* GDI_HW_JPEG_SUPPORT_DIRECT_OUTPUT_BUFFER */ 
    }
    else
    {
        /* Check buffer size is enough to decode image or not */
        GDI_ASSERT(*dest_buf_size >= gdi_sizeof_pixels(*dest_buf_cf, resized_width, resized_height));
    
        /*TODO: Fix Broken JPEG Issue, but it should downgrade performance */
        memset(*dest_buf, 0xff, *dest_buf_size);
        
        jpeg.image_buffer_address = (U32)*dest_buf;
        jpeg.image_buffer_size = (U32) *dest_buf_size;
    }
    return GDI_SUCCEED;
}
/*****************************************************************************
 * FUNCTION
 *  gdi_image_hwjpeg_set_color_format
 * DESCRIPTION
 *  setting color format
 *****************************************************************************/
static GDI_RESULT gdi_image_hwjpeg_set_color_format(U8* dest_buf,gdi_color_format dest_buf_cf)
{
    #ifdef GDI_HW_JPEG_SUPPORT_COLOR_FORMAT
        if (NULL == dest_buf) dest_buf_cf = gdi_act_layer->vcf;

        switch (dest_buf_cf)
        {
        case GDI_COLOR_FORMAT_16:
            jpeg.image_data_format = IMGDMA_IBW_OUTPUT_RGB565;
            break;
        case GDI_COLOR_FORMAT_24:
            jpeg.image_data_format = IMGDMA_IBW_OUTPUT_RGB888;
            break;
        default:
            GDI_ASSERT(0);  /* strange  color format */
        }
    #endif /* GDI_HW_JPEG_SUPPORT_COLOR_FORMAT */ 
    
    return GDI_SUCCEED;
}
/*****************************************************************************
 * FUNCTION
 *  gdi_image_hwjpeg_set_callback
 * DESCRIPTION
 *  setting driver jpeg callback
 *****************************************************************************/
static GDI_RESULT gdi_image_hwjpeg_set_callback(void)
{
    jpeg.jpeg_decode_cb = gdi_image_hwjpeg_callback;
    return GDI_SUCCEED;
}
/*****************************************************************************
 * FUNCTION
 *  gdi_image_hwjpeg_init
 * DESCRIPTION
 *  setting driver jpeg parameter
 *****************************************************************************/
static GDI_RESULT gdi_image_hwjpeg_init(
            S32 *ox,
            S32 *oy,
            S32 *resized_width,
            S32 *resized_height,
            S32 *output_clipx1,
            S32 *output_clipy1,
            S32 *output_clipx2,
            S32 *output_clipy2,
            U8 *src,
            U32 size,
            BOOL is_file,
            BOOL is_resized,
            U8 **dest_buf,
            S32 *dest_buf_size,
            S32 *decoded_image_width,
            gdi_color_format *dest_buf_cf)
{
    GDI_RESULT ret;
    
    memset(&jpeg,0,sizeof(jpeg)); /* initialize jpeg decoder struct */
    jpeg.jpg_timeout_period = GDI_HW_JPEG_CODEC_WAITING_TIME/10;
    jpeg.jpeg_decode_retry_flag = JPEG_DECODER_RETRY_DISABLE;
    MMI_TRACE(GDI_TRC, GDI_TRC_19//"---- GDI_HW_JPG INIT BEGIN----"
                );
    do
    {
        if((ret = gdi_image_hwjpeg_set_thumbnail_value(is_resized))!=GDI_SUCCEED) break;
        if((ret = gdi_image_hwjpeg_set_source_image(src,size,is_file))!=GDI_SUCCEED) break;
        if((ret = gdi_image_hwjpeg_set_real_size(resized_width,resized_height,decoded_image_width))!=GDI_SUCCEED) break;
        if((ret = gdi_image_hwjpeg_set_memory())!=GDI_SUCCEED) break;
       if((ret = gdi_image_hwjpeg_set_clipping(
                                    ox,oy,
                                    *dest_buf,
                                    *resized_width,*resized_height,
                                    output_clipx1,
                                    output_clipy1,
                                    output_clipx2,
                                    output_clipy2
                                    ))!=GDI_SUCCEED) break;
       
        #ifdef GDI_USING_SPATIAL_DITHERING
        gdi_jpeg_dithering.handle = GDI_NULL_HANDLE;
        gdi_jpeg_dithering.is_push_and_set_active = 0;
        
        if(gdi_act_layer->bits_per_pixel == 16  // only process 16 bits desintation
        && ((*output_clipx2 - *output_clipx1 + 1)*3 &1)==0  // only process even width because HW didn't support odd pitch_width
        && *dest_buf == NULL   // only process direct output to layer
        && is_file )           // only process file source
        {
            U32 size;

            size = gdi_sizeof_pixels(GDI_COLOR_FORMAT_24,
                                     *output_clipx2 - *output_clipx1 + 1,
                                     *output_clipy2 - *output_clipy1 + 1);
            size = ROUND16(size);

            MMI_TRACE(GDI_TRC, GDI_TRC_48,//"jpeg spatial dithering buffer size = %d",
                                                size);
            gdi_jpeg_dithering.buffer = med_alloc_ext_mem(size);
            
            if(gdi_jpeg_dithering.buffer)
            {
                MMI_TRACE(GDI_TRC, GDI_TRC_49//"jpeg spatial dithering enable"
                                    );

                gdi_layer_create_cf_using_outside_memory(
                                            GDI_COLOR_FORMAT_24,
                                            0,0,
                                            *output_clipx2 - *output_clipx1 + 1,
                                            *output_clipy2 - *output_clipy1 + 1,
                                            &gdi_jpeg_dithering.handle,
                                            gdi_jpeg_dithering.buffer,
                                            size);
                gdi_layer_push_and_set_active(gdi_jpeg_dithering.handle);
                gdi_jpeg_dithering.is_push_and_set_active++;
                
                gdi_jpeg_dithering.save_ox = *ox; *ox = 0;
                gdi_jpeg_dithering.save_oy = *oy; *oy = 0;
                gdi_jpeg_dithering.save_clipx1 = *output_clipx1;
                gdi_jpeg_dithering.save_clipy1 = *output_clipy1;
                gdi_jpeg_dithering.save_clipx2 = *output_clipx2;
                gdi_jpeg_dithering.save_clipy2 = *output_clipy2;
                *output_clipx1 = 0; 
                *output_clipy1 = 0;
                *output_clipx2 = gdi_act_layer->width-1;
                *output_clipy2 = gdi_act_layer->height-1;
            }
        }

        if(gdi_jpeg_dithering.handle == GDI_NULL_HANDLE)
        {
            MMI_TRACE(GDI_TRC, GDI_TRC_50//"jpeg spatial dithering disable"
                            );
        }

        #endif

        #ifdef __SW_JPEG_CODEC_SUPPORT__
        {
            sw_jpeg_hook_decode_progress_callback(gdi_image_progress_callback);
        }
        #endif

        // clear destination as WHITE COLOR for avoid broken JPEG.  ( only apply at layer )
        //if(*dest_buf==NULL)
        //    gdi_draw_solid_rect(*ox,*oy,*ox+*resized_width-1, *oy+*resized_height-1, 0xffffffff);

        gdi_image_set_update_area(*ox,*oy,*ox+*resized_width-1, *oy+*resized_height-1);
 
        if((ret = gdi_image_hwjpeg_set_dest_buffer(
                                    *ox,*oy,
                                    dest_buf,
                                    dest_buf_size,
                                    dest_buf_cf,
                                    *resized_width,*resized_height,
                                    *output_clipx1,
                                    *output_clipy1,
                                    *output_clipx2,
                                    *output_clipy2
                                    ))!=GDI_SUCCEED) break;
        if((ret = gdi_image_hwjpeg_set_color_format(*dest_buf,*dest_buf_cf))!=GDI_SUCCEED) break;
        if((ret = gdi_image_hwjpeg_set_callback())!=GDI_SUCCEED) break;
    }while(0);
    MMI_TRACE(GDI_TRC, GDI_TRC_20,//"---- GDI_HW_JPG INIT END ret=%d----",
                ret);

    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  gdi_image_hwjpeg_copy_buf_to_dest
 * DESCRIPTION
 *  copy from intermeidate buffer to destination buffer
 *****************************************************************************/
static GDI_RESULT gdi_image_hwjpeg_copy_buf_to_dest(
                            S32 ox,
                            S32 oy,
                            S32 resized_width,
                            S32 resized_height,
                            S32 output_clipx1,
                            S32 output_clipy1,
                            S32 output_clipx2,
                            S32 output_clipy2,
                            S32 decoded_image_width)
{
    S32 decoded_width, show_width, show_height;
	gdi_rect_struct clip;
    
    clip.x1 = gdi_act_layer->clipx1;
    clip.y1 = gdi_act_layer->clipy1;
    clip.x2 = gdi_act_layer->clipx2;
    clip.y2 = gdi_act_layer->clipy2;


    /* show_size is MIN( clipping are , resized image size) */
    show_width = output_clipx2 - output_clipx1 + 1;
    if (show_width > resized_width)
        show_width = resized_width;

    show_height = output_clipy2 - output_clipy1 + 1;
    if (show_height > resized_height)
        show_height = resized_height;

    /* decoded_width is pass from JPEG codec ( some JPEG codec may have padding bytes ) */
    #ifdef GDI_HW_JPEG_SUPPORT_OUTPUT_CLIPPING
        decoded_width = show_width;
    #else
        decoded_width = decoded_image_width;
    #endif /* GDI_HW_JPEG_SUPPORT_OUTPUT_CLIPPING */ 

    gdi_2d_memory_blt((U8*) gdi_work_buffer,    /* src_ptr */
                      decoded_width,
#ifdef GDI_HW_JPEG_SUPPORT_OUTPUT_CLIPPING
                      0,                        /* src_offset_x */
                      0,                        /* src_offset_y */
#else /* GDI_HW_JPEG_SUPPORT_OUTPUT_CLIPPING */ 
                      output_clipx1,            /* src_offset_x */
                      output_clipy1,            /* src_offset_y */
#endif /* GDI_HW_JPEG_SUPPORT_OUTPUT_CLIPPING */ 
                      show_width,               /* src_width */
                      show_height,              /* src_height */
                      gdi_act_layer->buf_ptr,   /* dest_ptr */
                      gdi_act_layer->width,     /* dest_pitch */
                      ox, oy, clip,
                      gdi_act_layer->bits_per_pixel);            /* dest_clip */
    return GDI_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_hwjpeg_deinit
 * DESCRIPTION
 *  setting driver jpeg callback
 *****************************************************************************/
static GDI_RESULT gdi_image_hwjpeg_deinit(BOOL is_file)
{

    if(jpeg.intmem_start_address)
    {
        med_free_int_mem((void**)&jpeg.intmem_start_address);
    }
    if(jpeg.extmem_start_address)
    {
        med_free_ext_mem((void**)&jpeg.extmem_start_address);
    }
    if(jpeg.jpeg_file_buffer_address && is_file)
    {
    	if(jpeg.jpeg_file_buffer_address != (kal_uint32)gdi_bytestream_buffer)
            med_free_ext_mem((void**)&jpeg.jpeg_file_buffer_address);
    }

    if(jpeg.jpeg_file_handle)
    {
        DRM_close_file(jpeg.jpeg_file_handle);
        jpeg.jpeg_file_handle=NULL;
    }

    #ifdef GDI_USING_SPATIAL_DITHERING
    if(gdi_jpeg_dithering.handle != GDI_NULL_HANDLE)
    {
        if(gdi_jpeg_dithering.is_push_and_set_active)
            gdi_layer_pop_and_restore_active();
        
        gdi_layer_free(gdi_jpeg_dithering.handle);
        med_free_ext_mem((void**)&gdi_jpeg_dithering.buffer);
        gdi_jpeg_dithering.handle  = GDI_NULL_HANDLE;
    }
    #endif
    return GDI_SUCCEED;
}
/*****************************************************************************
 * FUNCTION
 *  gdi_image_hwjpeg_timeout_handler
 * DESCRIPTION
 *  This function is to handle image codec timeout.
 *****************************************************************************/
void gdi_image_hwjpeg_timeout_handler(void *arg)
{
    gdi_image_hwjpeg_callback(JPEG_DECODE_DECODER_TIMEOUT_FAIL);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_hwjpeg_msg_handler
 * DESCRIPTION
 *  handle any hwjpeg msg
 *****************************************************************************/
void gdi_image_hwjpeg_msg_handler(ilm_struct *ilm)
{
    gdi_image_hwjpeg_state_struct *p = (gdi_image_hwjpeg_state_struct*)
                                            &(((gdd_img_codec_event_ind_struct*)ilm->local_para_ptr)->header);
    
   
    if(jpeg_result.cause != JPEG_DECODE_DECODING) // remember error cause only success or problem happen.
        jpeg_result.pre_cause = jpeg_result.cause;
    
    jpeg_result.cause = p->cause;
    
    
    MMI_TRACE(GDI_TRC, GDI_TRC_21,//"gdi_image_hwjpeg_msg_handler cause=%d",
                jpeg_result.pre_cause);
    MMI_TRACE(GDI_TRC, GDI_TRC_21,//"gdi_image_hwjpeg_msg_handler cause=%d",
                jpeg_result.cause);

    if(!gdi_image_progress_callback())
    {
        jpeg_result.cause = JPEG_DECODE_DECODER_TIMEOUT_FAIL;
        jpeg.jpeg_decode_retry_flag = JPEG_DECODER_RETRY_THUMBNAIL; // don't retry
    }

    MMI_TRACE(GDI_TRC, GDI_TRC_21,//"gdi_image_hwjpeg_msg_handler cause=%d",
                jpeg_result.cause);

    switch(jpeg_result.cause)
    {
    case JPEG_DECODE_DECODING:
        decode_jpeg_next_block();
        break;
    case JPEG_DECODE_BUFFER_SIZE_FAIL:
    case JPEG_DECODE_SUCCESS:
    case JPEG_DECODE_DECODER_TIMEOUT_FAIL:
    default:
        if(jpeg_is_need_stop)
        {
            stop_jpeg_decode_process();
            jpeg_is_need_stop = MMI_FALSE;
        }
        gdd_stop_timer(GDD_TIMER_IMAGE_CODEC_TIMEOUT);
        gdd_register_msg_handler(MSG_ID_MMI_GDD_IMG_CODEC_EVENT_IND, NULL);
        GDD_SET_EVENT(GDD_EVENT_WAIT_DECODING);
        break;
    }

}
/*****************************************************************************
 * FUNCTION
 *  gdi_image_hwjpeg_start_decode
 * DESCRIPTION
 *  This function is to active jpeg driver to run
 *****************************************************************************/

extern kal_uint32 INT_SwitchStackToRun(void *stack_start, kal_uint32 stack_size, kal_func_ptr func, kal_uint32 argc, ...);

void gdi_image_hwjpeg_start_decode(void) // run by MMI
{
    U8 cause;
    
    MMI_TRACE(GDI_TRC, GDI_TRC_22//"---- GDI_HW_JPG decode BEGIN ----"
                );
    
    while(1)
    {
        gdd_register_msg_handler(MSG_ID_MMI_GDD_IMG_CODEC_EVENT_IND, gdi_image_hwjpeg_msg_handler);
        jpeg_is_need_stop = MMI_TRUE;

        #if defined(__SW_JPEG_CODEC_SUPPORT__) && !defined(WIN32)
        {
            U32 stack_begin;
            med_get_med_int_stack_mem(&stack_begin);

            cause = (U8) INT_SwitchStackToRun((void*)stack_begin,MED_INT_STACK_MEM_SIZE,(kal_func_ptr)jpeg_decode_process, 1,&jpeg);

            med_free_med_int_stack_mem();
        }
        #else
        {
            cause = jpeg_decode_process(&jpeg);
        }
        #endif
        
        MMI_TRACE(GDI_TRC, GDI_TRC_23,//"jpeg_decode_process cause=%d",
                            cause);
        
        if(cause ==JPEG_DECODE_DECODING)
        {
            gdd_start_timer(GDD_TIMER_IMAGE_CODEC_TIMEOUT,
                            GDI_HW_JPEG_CODEC_WAITING_TIME,
                            gdi_image_hwjpeg_timeout_handler, 0);
        }
        else
        {
            jpeg_is_need_stop = MMI_FALSE;
            gdi_image_hwjpeg_callback(cause);
        }

        GDD_WAIT_EVENT(GDD_EVENT_WAIT_DECODING); // wait GDD finish decode

        //try again
        if(jpeg_result.cause == JPEG_DECODE_BUFFER_SIZE_FAIL)
            if(gdi_image_hwjpeg_enlarge_file_buffer()==GDI_SUCCEED)
                continue;

        #ifndef __SW_JPEG_CODEC_SUPPORT__
        // try use thumbnail to decode
        if(jpeg.jpeg_decode_retry_flag == JPEG_DECODER_RETRY_DISABLE )
            if(jpeg_result.cause == JPEG_DECODE_DECODER_OVERFLOW_FAIL 
            || jpeg_result.cause == JPEG_DECODE_DECODER_BREAK_FAIL
            || jpeg_result.cause == JPEG_DECODE_DECODER_TIMEOUT_FAIL
            || jpeg_result.cause == JPEG_DECODE_SRC_WIDHT_TOO_LARGE_FAIL
            || jpeg_result.cause == JPEG_DECODE_SRC_HEIGHT_TOO_LARGE_FAIL
            )
            {
                jpeg.jpeg_decode_retry_flag = JPEG_DECODER_RETRY_THUMBNAIL;
                continue;
            }
        #endif
        break;
    }
    
    MMI_TRACE(GDI_TRC, GDI_TRC_24//"---- GDI_HW_JPG decode END ----"
                );
}

/*****************************************************************************
 * FUNCTION
 *  gdi_image_hwjpeg_get_result
 * DESCRIPTION
 *  convert jpeg driver return cause into GDI return cause
 *****************************************************************************/
static GDI_RESULT gdi_image_hwjpeg_get_result(void)
{
    U8 cause = jpeg_result.cause;

    if(cause == JPEG_DECODE_NO_THUMBNAIL_FAIL) // re-try fail, caused by no thumbnail. We should use previous error cause
        cause = jpeg_result.pre_cause;

    switch (cause)
    {
    case JPEG_DECODE_SUCCESS:
    case JPEG_DECODE_DECODER_OVERFLOW_FAIL:
    case JPEG_DECODE_DECODER_BREAK_FAIL:
        return GDI_SUCCEED;
        
    case JPEG_DECODE_INT_BUFFER_NOT_ENOUGH:
    case JPEG_DECODE_EXT_BUFFER_NOT_ENOUGH:
        return GDI_IMAGE_ERR_IMAGE_TOO_LARGE;
        
    case JPEG_DECODE_TARGET_BUFFER_NOT_ENOUGH:
    case JPEG_DECODE_SRC_WIDHT_TOO_LARGE_FAIL:
    case JPEG_DECODE_SRC_HEIGHT_TOO_LARGE_FAIL:
    case JPEG_DECODE_TARGET_WIDTH_TOO_LARGE_FAIL:
    case JPEG_DECODE_TARGET_HEIGHT_TOO_LARGE_FAIL:
    case JPEG_DECODE_BUFFER_SIZE_FAIL:
        return GDI_IMAGE_ERR_IMAGE_TOO_LARGE;
    case JPEG_DECODE_DECODER_TIMEOUT_FAIL:
        return GDI_IMAGE_ERR_DECODE_TIME_OUT;
    default:
        return GDI_FAILED;
    }
}

/*****************************************************************************
 * FUNCTION
 *  gdi_image_hwjpeg_draw_internal
 * DESCRIPTION
 *  use jpeg driver to draw
 *****************************************************************************/
GDI_RESULT gdi_image_hwjpeg_draw_internal(
                            S32 ox,
                            S32 oy,
                            S32 resized_width,
                            S32 resized_height,
                            S32 output_clipx1,
                            S32 output_clipy1,
                            S32 output_clipx2,
                            S32 output_clipy2,
                            U8 *src,
                            U32 size,
                            BOOL is_file,
                            BOOL is_resized,
                            U8 *dest_buf,
                            S32 dest_buf_size,
                            S32 *ret_decoded_image_width,
                            gdi_color_format dest_buf_cf)
{
    GDI_ENTER_CRITICAL_SECTION(gdi_image_hwjpeg_draw_internal)
    {
        GDI_RESULT ret;
        S32 decoded_image_width = 0;
        /* if use want draw dimesion zero image, just return GDI_SUCCEED */
        if (is_resized && (resized_width == 0 || resized_height == 0))
            GDI_RETURN(GDI_SUCCEED);

    #ifdef GDI_USING_IMAGE_SINGLE_BANK_CACHE
        if (!is_file)
        {
            if (gdi_image_single_bank_cache_load(src, size, NULL) != GDI_SUCCEED)
            {
                 GDI_RETURN(GDI_FAILED);
            }

            src = gdi_image_single_bank_cache_get_buffer();
        }
    #endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

        {
            MMDI_SCENERIO_ID old_app;
            if(!idp_register_app(SCENARIO_JPEG_DECODE_ID,&old_app))
                GDI_RETURN(GDI_FAILED);
        }

        do
        {
            MMI_BOOL is_output_current_layer;
            if(dest_buf==NULL)
                is_output_current_layer = MMI_TRUE;
            else
                is_output_current_layer = MMI_FALSE;

            if((ret =gdi_image_hwjpeg_init(
                            &ox,&oy,
                            &resized_width,
                            &resized_height,
                            &output_clipx1,
                            &output_clipy1,
                            &output_clipx2,
                            &output_clipy2,
                            src,
                            size,
                            is_file,
                            is_resized,
                            &dest_buf,
                            &dest_buf_size,
                            &decoded_image_width,
                            &dest_buf_cf))!=GDI_SUCCEED) break;

            gdi_image_hwjpeg_start_decode();/* BLOCKING and wait jpeg driver */
            
            if((ret = gdi_image_hwjpeg_get_result())!=GDI_SUCCEED) break;


            #ifdef GDI_USING_SPATIAL_DITHERING
            if(gdi_jpeg_dithering.handle != GDI_NULL_HANDLE)
            {
                U8* dest;
                S32 show_width,show_height,dest_width;
                
                ox = gdi_jpeg_dithering.save_ox;
                oy = gdi_jpeg_dithering.save_oy;
                output_clipx1 = gdi_jpeg_dithering.save_clipx1;
                output_clipy1 = gdi_jpeg_dithering.save_clipy1;
                output_clipx2 = gdi_jpeg_dithering.save_clipx2;
                output_clipy2 = gdi_jpeg_dithering.save_clipy2;

                show_width = output_clipx2 - output_clipx1+1;
                show_height= output_clipy2 - output_clipy1+1;

                gdi_jpeg_dithering.is_push_and_set_active--;
                gdi_layer_pop_and_restore_active();
                
                if(is_output_current_layer)
                {
                    dest = gdi_act_layer->buf_ptr + (((ox + oy*gdi_act_layer->width) * gdi_act_layer->bits_per_pixel)>>3);
                    dest_width = gdi_act_layer->width;
                }
                else
                {
                    dest = dest_buf;
                    dest_width = show_width;
                }
                
                MMI_TRACE(GDI_TRC, GDI_TRC_51,//"jpeg spatial_dithering888_565 [%x -> %x] , (%d,%d)  (%d x %d)", 
                                    gdi_jpeg_dithering.buffer,
                                    dest,
                                    ox,
                                    oy,
                                    show_width,
                                    show_height);
                
                spatial_dithering_bgr8882565(
                                (U8*) gdi_jpeg_dithering.buffer,
                                (U16*)dest,
                                (U32) show_width,
                                (U32) show_height,
                                (U32) dest_width);
            }
            #endif

            if(is_output_current_layer
            #ifndef GDI_HW_JPEG_SUPPORT_DIRECT_OUTPUT_BUFFER
            && dest_buf != NULL
            #endif
            && gdi_act_layer_info->source_key_enable)
            {
                gdi_act_replace_src_key(
                        gdi_act_layer->buf_ptr,
                        gdi_act_layer->width,
                        ox,
                        oy,
                        gdi_act_layer->clipx1,
                        gdi_act_layer->clipy1,
                        gdi_act_layer->clipx2,
                        gdi_act_layer->clipy2,
                        gdi_act_layer_info->source_key,
                        resized_width,
                        resized_height);
                break;
            }
            
            if(dest_buf != NULL) /* don't need copy to current layer */
                break;
            #ifdef GDI_HW_JPEG_SUPPORT_DIRECT_OUTPUT_BUFFER
            else /* direct output to layer, we need replace src key if need */
                break;
            #endif
            
            if((ret = gdi_image_hwjpeg_copy_buf_to_dest(
                                ox,oy,
                                resized_width,resized_height,
                                output_clipx1,
                                output_clipy1,
                                output_clipx2,
                                output_clipy2,
                                decoded_image_width))!=GDI_SUCCEED) break;
            
        }while(0);
        gdi_image_hwjpeg_deinit(is_file);

		if(ret_decoded_image_width)
			*ret_decoded_image_width = decoded_image_width;

        /* threat out of clipping as succeed */
        if(ret == GDI_IMAGE_OUT_OF_CLIP_REGION) ret = GDI_SUCCEED;
        GDI_RETURN(ret);
    }
    GDI_EXIT_CRITICAL_SECTION(gdi_image_hwjpeg_draw_internal)
}

#endif /* GDI_USING_JPEG */

