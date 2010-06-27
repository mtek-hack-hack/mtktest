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
 *  gdi_image_jpeg.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GDI Image Jpeg decoder.
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
/* DRM_REPLACE */
#include "drm_gprot.h"

#ifdef GDI_USING_JPEG

#include "gui.h"        /* for timer */
#include "Unicodexdcl.h"

#include "med_api.h"
#include "med_main.h"
#include "med_struct.h"

#ifdef GDI_HW_JPEG_SUPPORT_COLOR_FORMAT
#include "imgdma.h"
#endif 

#ifdef GDI_USING_JPEG_EXIF
#include "exif.h"
#endif

/* markers of JPEG standard */
#define JPEG_MARKER_SOF0      0xC0
#define JPEG_MARKER_SOF1      0xC1
#define JPEG_MARKER_SOF2      0xC2
#define JPEG_MARKER_SOF3      0xC3
#define JPEG_MARKER_SOF15     0xCF
#define JPEG_MARKER_SOS       0xDA
#define JPEG_MARKER_DQT       0xDB
#define JPEG_MARKER_DNL       0xDC
#define JPEG_MARKER_DRI       0xDD
#define JPEG_MARKER_DHP       0xDE
#define JPEG_MARKER_EXP       0xDF
#define JPEG_MARKER_APP0      0xE0
#define JPEG_MARKER_APP15     0xEF
#define JPEG_MARKER_COM       0xFE

#define ROUND16(x)   (((x) + 15)&(~0xf))


/*****************************************************************************
 * FUNCTION
 *  gdi_image_jpeg_get_dimension_internal
 * DESCRIPTION
 *  get jpeg dimension inetrnal function
 * PARAMETERS
 *  width       [OUT]       
 *  height      [OUT]       
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
static GDI_RESULT gdi_image_jpeg_get_dimension_internal(S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index, index_offset;
    U16 marker_length;

    U8 jpg_byte1, jpg_byte2, tmp_byte;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = 0;
    jpg_byte1 = gdi_bytestream_get_byte();
    jpg_byte2 = gdi_bytestream_get_byte();

    /* check first two byte to see if is valid jpeg file */
    if ((jpg_byte1 == 0xFF) && (jpg_byte2 == 0xD8))
    {

        /* parse bytestream */
        do
        {
            if (gdi_bytestream_is_eof() == TRUE)
            {
                break;
            }

            do
            {
                tmp_byte = gdi_bytestream_get_byte();
            } while (tmp_byte != 0xFF);

            jpg_byte1 = 0xFF;
            jpg_byte2 = gdi_bytestream_get_byte();

            switch (jpg_byte2)
            {
                case JPEG_MARKER_SOF0:
                case JPEG_MARKER_SOF2:

                    marker_length = gdi_bytestream_get_byte() << 8;
                    marker_length |= gdi_bytestream_get_byte();
                    marker_length -= 2;

                    gdi_bytestream_get_byte();  /* precision */
                    *height = gdi_bytestream_get_byte() << 8;
                    *height |= gdi_bytestream_get_byte();
                    *width = gdi_bytestream_get_byte() << 8;
                    *width |= gdi_bytestream_get_byte();

                    /* set terminate byte */
                    jpg_byte2 = 0xD9;

                    break;
                case JPEG_MARKER_SOS:
                    break;
                case 0xC8:
                case 0x00:
                    break;
                default:
                    if ((jpg_byte2 == JPEG_MARKER_SOF1) ||
                        ((jpg_byte2 >= JPEG_MARKER_SOF3) && (jpg_byte2 <= JPEG_MARKER_SOF15)) ||
                        (jpg_byte2 == JPEG_MARKER_DQT) || (jpg_byte2 == JPEG_MARKER_DNL) ||
                        (jpg_byte2 == JPEG_MARKER_DRI) || (jpg_byte2 == JPEG_MARKER_DHP) ||
                        (jpg_byte2 == JPEG_MARKER_EXP) || (jpg_byte2 == JPEG_MARKER_COM) ||
                        ((jpg_byte2 >= JPEG_MARKER_APP0) && (jpg_byte2 <= JPEG_MARKER_APP15)))
                    {
                        index_offset = gdi_bytestream_get_byte() << 8;
                        index_offset |= gdi_bytestream_get_byte();
                        index_offset -= 2;
                        gdi_bytestream_flush(index_offset);
                    }
                    break;
            }

        } while (!((jpg_byte1 == 0xFF) && (jpg_byte2 == 0xD9)));

        return GDI_SUCCEED;
    }
    else    /* not valid jpeg file */
    {
        return GDI_IMAGE_ERR_INVALID_IMG_TYPE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_jpeg_get_dimension
 * DESCRIPTION
 *  get jpeg dimension, source is from memory
 * PARAMETERS
 *  jpeg_src        [IN]        
 *  size            [IN]        
 *  width           [OUT]       
 *  height          [OUT]       
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_image_jpeg_get_dimension(U8 *jpeg_src, U32 size, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_image_jpeg_get_dimension)
    GDI_RESULT ret;

    *width = 0;
    *height = 0;

    if (jpeg_src == NULL || gdi_bytestream_create((U8*) jpeg_src, size) != GDI_SUCCEED)
    {
        GDI_RETURN(GDI_IMAGE_ERR_OPEN_FILE_FAILED);
    }

    GDI_TRY
    {
        ret = gdi_image_jpeg_get_dimension_internal(width, height);
    }
    GDI_CATCH_BEGIN
    {
        *width = 0;
        *height = 0;
        ret = GDI_IMAGE_ERR_INVALID_IMG_TYPE;
    }
    GDI_CATCH_END gdi_bytestream_free();

    GDI_RETURN(ret);
    GDI_EXIT_CRITICAL_SECTION(gdi_image_jpeg_get_dimension)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_jpeg_get_dimension_file
 * DESCRIPTION
 *  get jpeg dimension, source is from file
 * PARAMETERS
 *  image_name      [IN]        
 *  width           [OUT]       
 *  height          [OUT]       
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_image_jpeg_get_dimension_file(S8 *image_name, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_image_jpeg_get_dimension_file)
    GDI_RESULT ret;

    *width = 0;
    *height = 0;

    if (image_name == NULL || gdi_bytestream_create_file(image_name) != GDI_SUCCEED)
    {
        GDI_RETURN(GDI_FAILED);
    }

    GDI_TRY
    {
        ret = gdi_image_jpeg_get_dimension_internal(width, height);
    }
    GDI_CATCH_BEGIN
    {
        *width = 0;
        *height = 0;
        ret = GDI_IMAGE_ERR_INVALID_IMG_TYPE;
    }
    GDI_CATCH_END gdi_bytestream_free();

    GDI_RETURN(ret);
    GDI_EXIT_CRITICAL_SECTION(gdi_image_jpeg_get_dimension_file)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_jpeg_draw_to_buffer
 * DESCRIPTION
 *  draw resized jpeg
 * PARAMETERS
 *  width                   [IN]        
 *  height                  [IN]        
 *  jpeg_src                [IN]        
 *  size                    [IN]        
 *  buf                     [?]         
 *  buf_size                [IN]        
 *  decoded_image_width     [?]         
 *  oy(?)                   [IN]        
 *  resized_width(?)        [IN]        
 *  resized_height(?)       [IN]        
 *  ox(?)                   [IN]        
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_image_jpeg_draw_to_buffer(
            S32 width,
            S32 height,
            U8 *jpeg_src,
            U32 size,
            U8 *buf,
            S32 buf_size,
            S32 *decoded_image_width)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_image_jpeg_draw_to_buffer)
    GDI_RETURN(gdi_image_jpeg_draw_internal(
                0,0,width,height,
                -1,-1,-1,-1,
                jpeg_src,size,
                FALSE,TRUE,TRUE,
                buf,buf_size,decoded_image_width,GDI_COLOR_FORMAT_16));
    GDI_EXIT_CRITICAL_SECTION(gdi_image_jpeg_draw_to_buffer)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_jpeg_draw_file_to_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  width                   [IN]        
 *  height                  [IN]        
 *  jpeg_file               [?]         
 *  buf                     [?]         
 *  buf_size                [IN]        
 *  decoded_image_width     [?]         
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_jpeg_draw_file_to_buffer(
            S32 width,
            S32 height,
            U8 *jpeg_file,
            U8 *buf,
            S32 buf_size,
            S32 *decoded_image_width)
{
    GDI_ENTER_CRITICAL_SECTION(gdi_image_jpeg_draw_to_buffer)
    GDI_RETURN(gdi_image_jpeg_draw_internal(
                0,0,width,height,
                -1,-1,-1,-1,
                jpeg_file,0,
                TRUE,TRUE,TRUE,
                buf,buf_size,decoded_image_width,GDI_COLOR_FORMAT_16));
    GDI_EXIT_CRITICAL_SECTION(gdi_image_jpeg_draw_to_buffer)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_jpeg_draw_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ox                      [IN]        
 *  oy                      [IN]        
 *  resized_width           [IN]        
 *  resized_height          [IN]        
 *  output_clipx1           [IN]        
 *  output_clipy1           [IN]        
 *  output_clipx2           [IN]        
 *  output_clipy2           [IN]        
 *  src                     [?]         
 *  size                    [IN]        
 *  is_file                 [IN]        
 *  is_resized              [IN]        
 *  dest_buf                [?]         
 *  dest_buf_size           [IN]        
 *  decoded_image_width     [?]         
 *  dest_buf_cf             [IN]        
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_jpeg_draw_internal(
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
            BOOL retry_thumbnail,
            U8 *dest_buf,
            S32 dest_buf_size,
            S32 *decoded_image_width,
            gdi_color_format dest_buf_cf)
{
	return gdi_image_hwjpeg_draw_internal(
            ox,
            oy,
            resized_width,
            resized_height,
            output_clipx1,
            output_clipy1,
            output_clipx2,
            output_clipy2,
            src,
            size,
            is_file,
            is_resized,
            dest_buf,
            dest_buf_size,
            decoded_image_width,
            dest_buf_cf);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_jpeg_get_exif_info_internal
 * DESCRIPTION
 *****************************************************************************/
GDI_RESULT gdi_image_jpeg_get_exif_info_internal(S8 *filename, gdi_image_jpeg_exif_info_struct *info)
{
    GDI_RESULT ret = GDI_FAILED;
    #ifdef GDI_USING_JPEG_EXIF
    do
    {
        U32 buffer_size;
        EXIF_DEC_RESULT exif_ret;
        buffer_size = exif_open_jpeg_file((void*)filename);
        if(buffer_size==0) break; // open jpeg fail
        
        GDI_DEBUG_ASSERT(gdi_work_buffer_size>= buffer_size);

        exif_ret = exif_parse_jpeg_file((U8*)gdi_work_buffer, buffer_size);
        if (exif_ret != EXIF_DEC_DONE) break; // parse jpeg fail

        // start to fetch each field.
        #define FIELD_COPY(_A_,_TAG_NAME_)\
        do                                                              \
        {                                                               \
            S8* tmp_p;                                                  \
            tmp_p=exif_get_tag_value(_TAG_NAME_);                       \
            if(tmp_p!=0)                                                \
               strncpy((S8*)info->_A_,tmp_p,sizeof(info->_A_));         \
            else                                                        \
               strcpy((S8*)info->_A_,"");                               \
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
        ret = GDI_SUCCEED;
    } while(0);
    exif_close_jpeg_file();
    #endif
    return ret;
}

#else /* not support jpeg format */


/*****************************************************************************
 * FUNCTION
 *  gdi_image_jpeg_draw_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ox                      [IN]        
 *  oy                      [IN]        
 *  resized_width           [IN]        
 *  resized_height          [IN]        
 *  output_clipx1           [IN]        
 *  output_clipy1           [IN]        
 *  output_clipx2           [IN]        
 *  output_clipy2           [IN]        
 *  src                     [?]         
 *  size                    [IN]        
 *  is_file                 [IN]        
 *  is_resized              [IN]        
 *  dest_buf                [?]         
 *  dest_buf_size           [IN]        
 *  decoded_image_width     [?]         
 *  dest_buf_cf             [IN]        
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_jpeg_draw_internal(
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
            BOOL retry_thumbnail,
            U8 *dest_buf,
            S32 dest_buf_size,
            S32 *decoded_image_width,
            gdi_color_format dest_buf_cf)
{
	return GDI_FAILED;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_jpeg_get_dimension
 * DESCRIPTION
 *****************************************************************************/
GDI_RESULT gdi_image_jpeg_get_dimension(U8 *jpeg_src, U32 size, S32 *width, S32 *height)
{
    return GDI_FAILED;
}

/*****************************************************************************
 * FUNCTION
 *  gdi_image_jpeg_draw_to_buffer
 * DESCRIPTION
 *****************************************************************************/
GDI_RESULT gdi_image_jpeg_draw_to_buffer(
            S32 width,
            S32 height,
            U8 *jpeg_src,
            U32 size,
            U8 *buf,
            S32 buf_size,
            S32 *decoded_image_width)
{
    return GDI_FAILED;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_jpeg_draw_file_to_buffer
 * DESCRIPTION
 *****************************************************************************/
GDI_RESULT gdi_image_jpeg_draw_file_to_buffer(
            S32 width,
            S32 height,
            U8 *jpeg_file,
            U8 *buf,
            S32 buf_size,
            S32 *decoded_image_width)
{
    return GDI_FAILED;
}
GDI_RESULT gdi_image_jpeg_get_exif_info_internal(S8 *filename, gdi_image_jpeg_exif_info_struct *info)
{
    return GDI_FAILED;
}
#endif 


/*****************************************************************************
 * FUNCTION
 *  gdi_image_is_jpeg_file
 * DESCRIPTION
 *****************************************************************************/
BOOL gdi_image_is_jpeg_file(U8 *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int f;
    U8 buf[3];
    U32 len;
    U32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    f = gdi_lfs_open(gdi_lfs_handle,(U16*) file_name, FS_READ_ONLY | FS_OPEN_NO_DIR | FS_OPEN_SHARED, 0);
    if (f < 0) return FALSE;
    f = gdi_lfs_handle;

    result = gdi_lfs_read(f, buf, 3, &len);

    gdi_lfs_close(f);

    if (result == FS_NO_ERROR)
        if (len == 3)
            if (buf[0] == 0xff && buf[1] == 0xd8 && buf[2] == 0xff)
            {
                return TRUE;
            }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_jpeg_draw_handler
 * DESCRIPTION
 *****************************************************************************/
GDI_RESULT gdi_image_jpeg_draw_handler(U32 flag, U32 frame_pos, S32 x, S32 y, S32 w, S32 h, U8 *data_ptr, U32 img_size)
{
    #ifdef GDI_USING_JPEG
    return gdi_image_jpeg_draw_internal(
            x,
            y,
            w,
            h,
            -1,
            -1,
            -1,
            -1,
            data_ptr,
            img_size,
            TOBOOL(flag & GDI_IMAGE_CODEC_FLAG_IS_FILE),
            (BOOL) (w && h),
            TRUE,
            NULL,
            0,
            NULL,
            0);
    #else
    return GDI_FAILED;
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_jpeg_get_dimension_handler
 * DESCRIPTION
 *****************************************************************************/
GDI_RESULT gdi_image_jpeg_get_dimension_handler(U32 flag, U8 *data_ptr, U32 img_size, S32 *width, S32 *height)
{
    #ifdef GDI_USING_JPEG
        if (flag & GDI_IMAGE_CODEC_FLAG_IS_FILE)
        {
            return gdi_image_jpeg_get_dimension_file((S8*) data_ptr, width, height);
        }
        else
        {
            return gdi_image_jpeg_get_dimension(data_ptr, img_size, width, height);
        }
    #else
        return GDI_FAILED;    
    #endif
}

GDI_RESULT gdi_image_jpeg_get_exif_info(S8 *filename, gdi_image_jpeg_exif_info_struct *info)
{
    #ifdef GDI_USING_JPEG_EXIF
        return gdi_image_jpeg_get_exif_info_internal(filename,info);
    #else
        return GDI_FAILED;
    #endif
}


