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
 *  svg
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SVG tiny basic library
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#include "MMI_include.h"
#if defined(SVG_SUPPORT) 

#include "xml_def.h"
#include "wrappergprot.h"

#include "svg_internal.h"
#include "svg_work_buffer.h"

U16 *svg_wb_buffer;
U32 svg_wb_layer;
U32 svg_wb_width, svg_wb_height;
U32 svg_wb_buffer_size;


/*****************************************************************************
 * FUNCTION
 *  svg_wb_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void svg_wb_init(U8* buffer_address, U32 buffer_size)
{
    svg_wb_buffer = (U16*) buffer_address;
    svg_wb_buffer_size   = buffer_size;
    svg_wb_width = GDI_LCD_WIDTH;
    svg_wb_height = (svg_wb_buffer_size / svg_wb_width) / 2;

    gdi_layer_create_cf_using_outside_memory(
        GDI_COLOR_FORMAT_16,
        0,
        0,
        svg_wb_width,
        svg_wb_height,
        (gdi_handle*) & svg_wb_layer,
        (U8*) svg_wb_buffer,
        svg_wb_buffer_size);
}


/*****************************************************************************
 * FUNCTION
 *  svg_wb_uninit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void svg_wb_uninit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_free(svg_wb_layer);
}


/*****************************************************************************
 * FUNCTION
 *  svg_wb_resize_with_width
 * DESCRIPTION
 *  
 * PARAMETERS
 *  width       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void svg_wb_resize_with_width(U32 width)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    svg_wb_width = width;
    svg_wb_height = svg_wb_buffer_size / (2 * width);
    if (svg_wb_height == 0)
    {
        SVG_RAISE(SVG_FAIL_WORK_BUFFER_RESIZE);
    }

    gdi_layer_push_and_set_active((gdi_handle) svg_wb_layer);
    gdi_layer_resize(svg_wb_width, svg_wb_height);
    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
 * FUNCTION
 *  svg_wb_resize_with_height
 * DESCRIPTION
 *  
 * PARAMETERS
 *  height      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void svg_wb_resize_with_height(U32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    svg_wb_height = height * 2;
    if (svg_wb_height > 512)
    {
        svg_wb_height = 512;
    }

    svg_wb_width = svg_wb_buffer_size / (2 * height);
    if (svg_wb_width > 512)
    {
        svg_wb_width = 512;
    }

    if (svg_wb_width == 0)
    {
        SVG_RAISE(SVG_FAIL_WORK_BUFFER_RESIZE);
    }

    gdi_layer_push_and_set_active((gdi_handle) svg_wb_layer);
    gdi_layer_resize(svg_wb_width, svg_wb_height);
    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
 * FUNCTION
 *  svg_wb_resize_with_ratio
 * DESCRIPTION
 *  
 * PARAMETERS
 *  width       [IN]        
 *  height      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void svg_wb_resize_with_ratio(U32 width, U32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (width * height * 2 <= svg_wb_buffer_size)
    {
        svg_wb_width = width;
        svg_wb_height = height;
    }
    else
    {
        svg_wb_width = (svg_wb_buffer_size / 2) * width / height;
        svg_wb_height = (svg_wb_buffer_size / 2) * height / width;
        svg_wb_width = (int)sqrt((float)svg_wb_width);
        svg_wb_height = (int)sqrt((float)svg_wb_height);
    }

    gdi_layer_push_and_set_active((gdi_handle) svg_wb_layer);
    gdi_layer_resize(svg_wb_width, svg_wb_height);
    gdi_layer_pop_and_restore_active();
}

#endif /* __MMI_SVG__ */ /* __SVG__ */

