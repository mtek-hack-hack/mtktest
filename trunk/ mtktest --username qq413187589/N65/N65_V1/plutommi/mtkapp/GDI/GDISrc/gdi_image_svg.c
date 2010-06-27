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
 *  gdi_image_svg.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GDI SVG related.
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
#include "ucs2prot.h"
#ifdef GDI_USING_SVG
#include "med_utility.h"
#include "svg.h"

static MMI_BOOL gdi_svg_is_used = MMI_FALSE;
static svg_handle gdi_svg_handle;
static void*      svg_work_buffer;
/*****************************************************************************
 * FUNCTION
 *  gdi_image_svg_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  width       [IN]        
 *  height      [IN]        
 *  buf         [?]         
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_svg_init(void)
{
    GDI_ENTER_CRITICAL_SECTION(gdi_image_svg_init)
    if(gdi_svg_is_used)
        GDI_RETURN(GDI_FAILED);
    
    svg_work_buffer = (void*) med_alloc_ext_mem(SVG_WORK_BUFFER_SIZE);
    if(svg_work_buffer==NULL)
        GDI_RETURN(GDI_IMAGE_ERR_MEMORY_NOT_AVAILABLE);
    
    svg_init((U32*)svg_work_buffer, SVG_WORK_BUFFER_SIZE);
    if (svg_new(&gdi_svg_handle) != SVG_OK)
        GDI_RETURN(GDI_FAILED);
    
    gdi_svg_is_used=MMI_TRUE;
    
    GDI_RETURN(GDI_SUCCEED);
    GDI_EXIT_CRITICAL_SECTION(gdi_image_svg_init)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_svg_deinit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_svg_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_image_svg_deinit)

    if(svg_work_buffer)
        med_free_ext_mem(&svg_work_buffer);
    
    gdi_svg_is_used=MMI_FALSE;

    GDI_RETURN(GDI_SUCCEED);
    GDI_EXIT_CRITICAL_SECTION(gdi_image_svg_deinit)
}

GDI_RESULT gdi_image_svg_get_result(svg_enum svg_result)
{
	GDI_RESULT result;
	switch (svg_result)
	{
	case SVG_OK: 
        result = GDI_SUCCEED;
		break;
	case SVG_FAIL_NO_MEMORY: 
		result = GDI_IMAGE_ERR_IMAGE_TOO_LARGE;
		break;
    case SVG_FAIL_TIMEOUT:
        result = GDI_IMAGE_ERR_DECODE_TIME_OUT;
        break;
	default:
		result = GDI_FAILED;
		break;
	}
	return result;
}

/*****************************************************************************
 * FUNCTION
 *  gdi_image_svg_load
 * DESCRIPTION
 *  
 * PARAMETERS
 *  svg_src         [?]         
 *  size            [IN]        
 *  is_file         [IN]        
 *  is_svg_type     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_svg_load(U8 *svg_src, U32 size, MMI_BOOL is_file)
{
	GDI_RESULT ret;
    GDI_ENTER_CRITICAL_SECTION(gdi_image_svg_load)

    GDI_DEBUG_ASSERT(gdi_svg_is_used);
    GDI_DEBUG_ASSERT(is_file==MMI_TRUE); // currently, xml parser only support file
    
    ret=svg_parse_file(gdi_svg_handle, (U16*)svg_src);

    GDI_RETURN(gdi_image_svg_get_result(ret));

    GDI_EXIT_CRITICAL_SECTION(gdi_image_svg_load)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_svg_draw_before_handler
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
GDI_RESULT gdi_image_svg_draw_before_handler(
            U32 flag,
            U32 frame_pos,
            S32 x,
            S32 y,
            S32 w,
            S32 h,
            U8 *data_ptr,
            U32 img_size)
{
	GDI_RESULT ret;
    GDI_ENTER_CRITICAL_SECTION(gdi_image_svg_draw_before_handler)

    MMI_BOOL is_file;

    if(gdi_image_svg_init() != GDI_SUCCEED)
        GDI_RETURN(GDI_FAILED);
    
    if (flag & GDI_IMAGE_CODEC_FLAG_IS_FILE)
        is_file = MMI_TRUE;
    else
        is_file = MMI_FALSE;
    
    if((ret = gdi_image_svg_load(data_ptr, img_size, is_file)) != GDI_SUCCEED)
        GDI_RETURN(gdi_image_svg_get_result(ret));

	if(w==0 || h == 0)
		svg_get_dimension(gdi_svg_handle,&w,&h);

    svg_reset_anim(gdi_svg_handle,x,y,w,h,NULL);
    
    GDI_RETURN(GDI_SUCCEED);
    GDI_EXIT_CRITICAL_SECTION(gdi_image_svg_draw_before_handler)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_svg_draw_handler
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
GDI_RESULT gdi_image_svg_draw_handler(U32 flag, U32 frame_pos, S32 x, S32 y, S32 w, S32 h, U8 *data_ptr, U32 img_size)
{
    GDI_ENTER_CRITICAL_SECTION(gdi_image_svg_draw_handler)
    GDI_RESULT result;
	svg_enum svg_result;

	svg_result = svg_draw_anim_single_frame();
	result = gdi_image_svg_get_result(svg_result);
    
    gdi_anim_set_delay(100);
    
    GDI_RETURN(result);
    GDI_EXIT_CRITICAL_SECTION(gdi_image_svg_draw_handler)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_svg_draw_after_handler
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
GDI_RESULT gdi_image_svg_draw_after_handler(
            U32 flag,
            U32 frame_pos,
            S32 x,
            S32 y,
            S32 w,
            S32 h,
            U8 *data_ptr,
            U32 img_size)
{
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_image_svg_draw_after_handler)
    GDI_RETURN(gdi_image_svg_deinit());
    GDI_EXIT_CRITICAL_SECTION(gdi_image_svg_draw_after_handler)
}

/*****************************************************************************
 * FUNCTION
 *  gdi_image_svg_get_dimension_handler
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
GDI_RESULT gdi_image_svg_get_dimension_handler(U32 flag, U8 *data_ptr, U32 img_size, S32 *width, S32 *height)
{
    GDI_ENTER_CRITICAL_SECTION(gdi_image_svg_get_dimension_handler)
    GDI_RESULT ret = GDI_FAILED;
    MMI_BOOL is_file;
    *width = *height = 0;
    if(gdi_image_svg_init() != GDI_SUCCEED)
        GDI_RETURN(GDI_FAILED);

    if (flag & GDI_IMAGE_CODEC_FLAG_IS_FILE)
        is_file = MMI_TRUE;
    else
        is_file = MMI_FALSE;
        
    if((ret = gdi_image_svg_load(data_ptr, img_size, is_file))==GDI_SUCCEED)
    {
        svg_get_dimension(gdi_svg_handle,width,height);
    }

    gdi_image_svg_deinit();
    GDI_RETURN(ret);
    GDI_EXIT_CRITICAL_SECTION(gdi_image_svg_get_dimension_handler)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_svg_get_pos_info_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  flag            [IN]        
 *  data_ptr        [?]         
 *  img_size        [IN]        
 *  quick_mode      [IN]        
 *  total_pos       [?]         
 *  pos_type        [?]         
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_svg_get_pos_info_handler(
            U32 flag,
            U8 *data_ptr,
            U32 img_size,
            BOOL quick_mode,
            S32 *total_pos,
            gdi_anim_pos_type_enum *pos_type)
{
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_image_svg_get_frame_count_handler)
    *total_pos = (U32) 0;
    *pos_type = GDI_ANIM_POS_TYPE_TIME;
    GDI_RETURN(GDI_SUCCEED);
    GDI_EXIT_CRITICAL_SECTION(gdi_image_svg_get_frame_count_handler)
}

/*****************************************************************************
 * FUNCTION
 *  gdi_image_is_svg_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_name       [?]     
 * RETURNS
 *  
 *****************************************************************************/
BOOL gdi_image_is_svg_file(U8 *file_name)
{
    S32 len;
    U16 *s;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    len = mmi_ucs2strlen((S8*)file_name);
    if(len>4)
    {
        s = (U16*) file_name;
        if( s[len-4]==(U16)'.' 
        && (s[len-3]|32)==(U16)'s'
        && (s[len-2]|32)==(U16)'v'
        && (s[len-1]|32)==(U16)'g')
            return MMI_TRUE;
    }
    return MMI_FALSE;
}

#endif

