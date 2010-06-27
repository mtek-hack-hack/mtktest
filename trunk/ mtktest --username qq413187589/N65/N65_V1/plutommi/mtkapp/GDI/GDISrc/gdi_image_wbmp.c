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
 *  gdi_image_wbmp.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  WBMP image decoder
 *
 * Author:
 * -------
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "gdi_internal.h"
#include "drm_gprot.h"

#define GET_U8       gdi_bytestream_get_byte
#define PEEK_U8         gdi_bytestream_peek_byte
#define GET_U16         gdi_bytestream_get_word
#define GET_U32         gdi_bytestream_get_dword
#define FLUSH(count)    gdi_bytestream_flush(count)
#define SEEK(offset)    gdi_bytestream_seek(offset)
#define IS_EOF()        gdi_bytestream_is_eof()

#define GDI_WBMP_MAX_WIDTH  (8192)
#define GDI_WBMP_MAX_HEIGHT (8192)


/*****************************************************************************
 * FUNCTION
 *  gdi_wbmp_multi_byte_int
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static int gdi_wbmp_multi_byte_int(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int value = 0;
    int maxlen = 4;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (maxlen--)
    {
        value <<= 7;
        value |= (PEEK_U8()) & 0x7f;
        if (!((PEEK_U8()) & 0x80))
        {
            maxlen = 0;
        }
        GET_U8();
    }
    return value;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_wbmp_draw_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sx                  [IN]        
 *  sy                  [IN]        
 *  is_resized          [IN]        
 *  resized_width       [IN]        
 *  resized_height      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static GDI_RESULT gdi_image_wbmp_draw_internal(S32 sx, S32 sy, BOOL is_resized, S32 resized_width, S32 resized_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int width, height;
    int x, y;
    int ex, ey;
    gdi_color colors[2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    colors[0] = gdi_act_color_from_rgb(0xff, 0, 0, 0);
    colors[1] = gdi_act_color_from_rgb(0xff, 0xff, 0xff, 0xff);

    //only support WBMP Type 0
    // B/W Uncompressed Bitmap
    if (GET_U8() || GET_U8())
    {
        return GDI_FAILED;
    }

    width = gdi_wbmp_multi_byte_int();
    height = gdi_wbmp_multi_byte_int();

    if (width > GDI_WBMP_MAX_WIDTH || height > GDI_WBMP_MAX_HEIGHT)
    {
        /* Otherwise, the next loop takes too much time with corrupted header */
        return GDI_FAILED;
    }

    /* W05.41 If resized width > original width or resized height > original height, do not resize */
    if (!is_resized || resized_width > width || resized_height > height)
    {
        resized_width = width;
        resized_height = height;
    }
    /* W05.52 Fix resized_width/resized_height == 0 issue */
    if (resized_width == 0 || resized_height == 0)
    {
        return (GDI_SUCCEED);
    }

    if (!gdi_resizer_init(
            width,
            height,
            0,
            0,
            width - 1,
            height - 1,
            sx,
            sy,
            sx + resized_width - 1,
            sy + resized_height - 1))
    {
        return (GDI_SUCCEED);
    }

    ex = sx + width;
    ey = sy + height;

    for (y = 0; y < height; y++)
    {

        for (x = 0; x < width;)
        {
            U32 d;
            int len;

            if (IS_EOF())
            {
                d = 0;
            }
            else
            {
                d = (U32) GET_U8();
            }

            len = width - x;
            if (len > 8)
            {
                len = 8;
            }

            switch (len)
            {
                case 8:
                    if (IS_GDI_RESIZER_WANT_DRAW(x, y))
                    {
                        gdi_resizer_put(colors[(d & 0x80) ? 1 : 0], TRUE);
                    }
                    d <<= 1;
                    x++;
                case 7:
                    if (IS_GDI_RESIZER_WANT_DRAW(x, y))
                    {
                        gdi_resizer_put(colors[(d & 0x80) ? 1 : 0], TRUE);
                    }
                    d <<= 1;
                    x++;
                case 6:
                    if (IS_GDI_RESIZER_WANT_DRAW(x, y))
                    {
                        gdi_resizer_put(colors[(d & 0x80) ? 1 : 0], TRUE);
                    }
                    d <<= 1;
                    x++;
                case 5:
                    if (IS_GDI_RESIZER_WANT_DRAW(x, y))
                    {
                        gdi_resizer_put(colors[(d & 0x80) ? 1 : 0], TRUE);
                    }
                    d <<= 1;
                    x++;
                case 4:
                    if (IS_GDI_RESIZER_WANT_DRAW(x, y))
                    {
                        gdi_resizer_put(colors[(d & 0x80) ? 1 : 0], TRUE);
                    }
                    d <<= 1;
                    x++;
                case 3:
                    if (IS_GDI_RESIZER_WANT_DRAW(x, y))
                    {
                        gdi_resizer_put(colors[(d & 0x80) ? 1 : 0], TRUE);
                    }
                    d <<= 1;
                    x++;
                case 2:
                    if (IS_GDI_RESIZER_WANT_DRAW(x, y))
                    {
                        gdi_resizer_put(colors[(d & 0x80) ? 1 : 0], TRUE);
                    }
                    d <<= 1;
                    x++;
                case 1:
                    if (IS_GDI_RESIZER_WANT_DRAW(x, y))
                    {
                        gdi_resizer_put(colors[(d & 0x80) ? 1 : 0], TRUE);
                    }
                    d <<= 1;
                    x++;
            }
        }
    }
    return GDI_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_wbmp_get_dimension_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  width       [?]     
 *  height      [?]     
 * RETURNS
 *  
 *****************************************************************************/
static GDI_RESULT gdi_image_wbmp_get_dimension_internal(S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GET_U8() || GET_U8())
    {
        return GDI_FAILED;
    }

    *width = gdi_wbmp_multi_byte_int();
    *height = gdi_wbmp_multi_byte_int();

    if (*width > GDI_WBMP_MAX_WIDTH || *height > GDI_WBMP_MAX_HEIGHT)
    {
        *width = 0;
        *height = 0;
        return GDI_FAILED;
    }

    return GDI_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_wbmp_draw
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ox              [IN]        
 *  oy              [IN]        
 *  WBMP_src        [?]         
 *  size            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_wbmp_draw(S32 ox, S32 oy, U8 *WBMP_src, U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_image_wbmp_draw)
    GDI_RESULT ret;

    if (gdi_bytestream_create(WBMP_src, (U32) size) != GDI_SUCCEED)
    {
        GDI_RETURN(GDI_FAILED);
    }

    GDI_TRY
    {
        ret = gdi_image_wbmp_draw_internal(ox, oy, FALSE, 0, 0);
    }
    GDI_CATCH_BEGIN
    {
        ret = GDI_FAILED;
    }
    GDI_CATCH_END gdi_bytestream_free();

    GDI_RETURN(ret);
    GDI_EXIT_CRITICAL_SECTION(gdi_image_wbmp_draw)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_wbmp_draw_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ox              [IN]        
 *  oy              [IN]        
 *  filename        [?]         
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_wbmp_draw_file(S32 ox, S32 oy, S8 *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_image_wbmp_draw_file)
    GDI_RESULT ret;

    if (filename == NULL || gdi_bytestream_create_file((PS8) filename) != GDI_SUCCEED)
    {
        GDI_RETURN(GDI_FAILED);
    }

    GDI_TRY
    {
        ret = gdi_image_wbmp_draw_internal(ox, oy, FALSE, 0, 0);
    }
    GDI_CATCH_BEGIN
    {
        ret = GDI_FAILED;
    }
    GDI_CATCH_END gdi_bytestream_free();

    GDI_RETURN(ret);
    GDI_EXIT_CRITICAL_SECTION(gdi_image_wbmp_draw_file)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_wbmp_draw_resized
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ox                  [IN]        
 *  oy                  [IN]        
 *  resized_width       [IN]        
 *  resized_height      [IN]        
 *  WBMP_src            [?]         
 *  size                [IN]        
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_wbmp_draw_resized(S32 ox, S32 oy, S32 resized_width, S32 resized_height, U8 *WBMP_src, U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_image_wbmp_draw_resized)
    GDI_RESULT ret;

    if (gdi_bytestream_create(WBMP_src, (U32) size) != GDI_SUCCEED)
    {
        GDI_RETURN(GDI_FAILED);
    }

    GDI_TRY
    {
        ret = gdi_image_wbmp_draw_internal(ox, oy, TRUE, resized_width, resized_height);
    }
    GDI_CATCH_BEGIN
    {
        ret = GDI_FAILED;
    }
    GDI_CATCH_END gdi_bytestream_free();

    GDI_RETURN(ret);
    GDI_EXIT_CRITICAL_SECTION(gdi_image_wbmp_draw_resized)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_wbmp_draw_resized_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ox                  [IN]        
 *  oy                  [IN]        
 *  resized_width       [IN]        
 *  resized_height      [IN]        
 *  filename            [?]         
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_wbmp_draw_resized_file(S32 ox, S32 oy, S32 resized_width, S32 resized_height, S8 *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_image_wbmp_draw_resized_file)
    GDI_RESULT ret;

    if (filename == NULL || gdi_bytestream_create_file((PS8) filename) != GDI_SUCCEED)
    {
        GDI_RETURN(GDI_FAILED);
    }

    GDI_TRY
    {
        ret = gdi_image_wbmp_draw_internal(ox, oy, TRUE, resized_width, resized_height);
    }
    GDI_CATCH_BEGIN
    {
        ret = GDI_FAILED;
    }
    GDI_CATCH_END gdi_bytestream_free();

    GDI_RETURN(ret);
    GDI_EXIT_CRITICAL_SECTION(gdi_image_wbmp_draw_resized_file)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_wbmp_get_dimension
 * DESCRIPTION
 *  
 * PARAMETERS
 *  WBMP_src        [?]     
 *  width           [?]     
 *  height          [?]     
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_wbmp_get_dimension(U8 *WBMP_src, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_image_wbmp_get_dimension)
    GDI_RESULT ret;

    /* FIXME. remove the magic number 12 */
    if (gdi_bytestream_create(WBMP_src, 12) != GDI_SUCCEED)
    {
        *width = *height = 0;
        GDI_RETURN(GDI_FAILED);
    }

    GDI_TRY
    {
        ret = gdi_image_wbmp_get_dimension_internal(width, height);
    }
    GDI_CATCH_BEGIN
    {
        *width = *height = 0;
        ret = GDI_FAILED;
    }
    GDI_CATCH_END gdi_bytestream_free();

    GDI_RETURN(ret);
    GDI_EXIT_CRITICAL_SECTION(gdi_image_wbmp_get_dimension)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_wbmp_get_dimension_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [?]     
 *  width           [?]     
 *  height          [?]     
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_wbmp_get_dimension_file(S8 *filename, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filename == NULL || gdi_bytestream_create_file((PS8) filename) != GDI_SUCCEED)
    {
        *width = *height = 0;
        return GDI_FAILED;
    }

    GDI_TRY
    {
        ret = gdi_image_wbmp_get_dimension_internal(width, height);
    }
    GDI_CATCH_BEGIN
    {
        *width = *height = 0;
        ret = GDI_FAILED;
    }
    GDI_CATCH_END gdi_bytestream_free();

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_wbmp_draw_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  flag            [IN]        
 *  frame_pos       [IN]        
 *  x               [IN]        
 *  y               [IN]        
 *  w               [IN]        
 *  h               [IN]        
 *  data_ptr        [?]         
 *  img_size        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_wbmp_draw_handler(U32 flag, U32 frame_pos, S32 x, S32 y, S32 w, S32 h, U8 *data_ptr, U32 img_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (flag & GDI_IMAGE_CODEC_FLAG_IS_FILE)
    {
        if (w && h)
        {
            return gdi_image_wbmp_draw_resized_file(x, y, w, h, (S8*) data_ptr);
        }
        else
        {
            return gdi_image_wbmp_draw_file(x, y, (S8*) data_ptr);
        }
    }
    else
    {
        if (w && h)
        {
            return gdi_image_wbmp_draw_resized(x, y, w, h, data_ptr, img_size);
        }
        else
        {
            return gdi_image_wbmp_draw(x, y, data_ptr, img_size);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_wbmp_get_dimension_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  flag            [IN]        
 *  data_ptr        [?]         
 *  img_size        [IN]        
 *  width           [?]         
 *  height          [?]         
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_wbmp_get_dimension_handler(U32 flag, U8 *data_ptr, U32 img_size, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (flag & GDI_IMAGE_CODEC_FLAG_IS_FILE)
    {
        return gdi_image_wbmp_get_dimension_file((S8*) data_ptr, width, height);
    }
    else
    {
        return gdi_image_wbmp_get_dimension(data_ptr, width, height);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_is_wbmp_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_name       [?]     
 * RETURNS
 *  
 *****************************************************************************/
BOOL gdi_image_is_wbmp_file(U8 *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int f;
    U8 buf[2];
    U32 len;
    U32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    f = gdi_lfs_open(gdi_lfs_handle,(U16*) file_name, FS_READ_ONLY | FS_OPEN_NO_DIR | FS_OPEN_SHARED, 0);
    if (f < 0) return FALSE;
    f = gdi_lfs_handle;

    result = gdi_lfs_read(f, buf, 2, &len);

    gdi_lfs_close(f);

    if (result == FS_NO_ERROR)
        if (len == 2)
            if (buf[0] == 0 && buf[1] == 0)
            {
                return TRUE;
            }
    return FALSE;
}

