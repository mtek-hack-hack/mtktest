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
#include "svg_vpath.h"
#include "svg_parser.h"
#include "svg_transform.h"
#include "svg_svp.h"
#include "svg_render.h"
#include "svg_work_buffer.h"

#include "ucs2prot.h"

#define KEY_FRAME_INTERVAL 500 /* 500 ms */

jmp_buf svg_jmpbuf;
BOOL svg_jmpbuf_is_used;

svg_t *svg_context;

extern void kal_check_stack(void);
extern kal_taskid kal_get_current_thread_ID(void);

/*****************************************************************************
 * FUNCTION
 *  svg_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buffer      [?]         
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void svg_init(U32 *buffer, U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    svg_context = NULL;
    svg_mem_set_pool((U8*) buffer, size);
}


/*****************************************************************************
 * FUNCTION
 *  svg_new
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [?]     
 * RETURNS
 *  
 *****************************************************************************/
svg_enum svg_new(svg_handle *handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    svg_t *svg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *handle = (svg_handle) NULL;

    svg = (svg_t*) svg_mem_malloc(sizeof(svg_t));
    if (!svg)
    {
        return SVG_FAIL_NO_MEMORY;
    }
    memset(svg,0,sizeof(svg_t));

    svg->elements = svg_hash_create(64);    /* use 64 entry to store elements */
    if (!svg->elements)
    {
        return SVG_FAIL_NO_MEMORY;
    }

    svg->styles = svg_hash_create(32);  /* use 64 entry to store elements */
    if (!svg->styles)
    {
        return SVG_FAIL_NO_MEMORY;
    }

    svg->font_family = svg_hash_create(4);  /* use 4 entry to store font family */
    if (!svg->font_family)
    {
        return SVG_FAIL_NO_MEMORY;
    }

    if (svg_const_pool_init() != SVG_OK)
    {
        return SVG_FAIL;
    }

    svg->dpi_x = 100;       /* default 100 DPI width */
    svg->dpi_y = 100;       /* default 100 DPI height */
    svg->font_size = 14;    /* default font size */
    svg->width = 1000;
    svg->height = 1000;
    svg->current_time = 0;
    svg->units_per_em = 1000;

    svg->style.font_size = 14;
    svg->style.font_weight = svg_const_pool((U8*) "400");

    svg->style.flag |= SVG_STYLE_FLAG_FILL;
    svg->style.fill_color = 0;
    svg->style.fill_color_type = SVG_COLOR_TYPE_HWRGB;

    *handle = (svg_handle) svg;

    return SVG_OK;
}


/*****************************************************************************
 * FUNCTION
 *  svg_parse_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle          [IN]        
 *  filename        [?]         
 * RETURNS
 *  
 *****************************************************************************/
svg_enum svg_parse_file(svg_handle handle, U16 *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    XML_PARSER_STRUCT parser;
    svg_enum ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (svg_context != NULL)
    {
        return SVG_FAIL_BUSY;
    }

    svg_context = (svg_t*) handle;
    svg_viewport_reset();

    mmi_ucs2cpy((char*)svg_context->current_path, (char*)filename);
    svg_fp_to_dirname(svg_context->current_path);

    svg_wb_init((U8*)gdi_work_buffer,gdi_work_buffer_size);
    svg_parser_init();
    SVG_TRY
    {
        xml_new_parser(&parser);
        xml_configure_memory(&parser, (XML_malloc_buffer_ptr) svg_mem_malloc, (XML_free_buffer_ptr) svg_mem_free);

        xml_register_element_handler(&parser, svg_read_start_element, svg_read_end_element);
        xml_register_data_handler(&parser, svg_read_data_element);

        svg_parser_container_list_create();

        ret = xml_parse(&parser, filename);
        if (ret != XML_RESULT_OK)
        {
            ret = SVG_FAIL_PARSER;
        }
        else
        {
            ret = SVG_OK;
        }
    }
    SVG_CATCH_BEGIN
    {
        xml_stop_parse(&parser);
        ret = (svg_enum) jmpret;
    }
    SVG_CATCH_END 
	xml_close_parser(&parser);
    svg_parser_container_list_free();
    svg_wb_uninit();
    svg_context = NULL;

    return ret;
}

svg_enum svg_get_dimension(svg_handle handle,S32 *width,S32 *height)
{
	S32 tmp_x,tmp_y;
    svg_context = (svg_t*) handle;
    *width = (S32)svg_context->width;
    *height = (S32)svg_context->height;

	gdi_util_fit_box(
            GDI_UTIL_MODE_LONG_SIDE_FIT,
            GDI_LCD_WIDTH,
            GDI_LCD_HEIGHT,
			(S32)svg_context->width,
			(S32)svg_context->height,
            &tmp_x,
            &tmp_y,
            width,
            height);
    return SVG_OK;
}
/*****************************************************************************
 * FUNCTION
 *  svg_draw
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 *  x1          [IN]        
 *  y1          [IN]        
 *  x2          [IN]        
 *  y2          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
svg_enum svg_draw(svg_handle handle, S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    svg_enum ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    svg_context = (svg_t*) handle;

    svg_context->output_x1 = x1;
    svg_context->output_y1 = y1;
    svg_context->output_x2 = x2;
    svg_context->output_y2 = y2;
    svg_context->output_width = x2 - x1 + 1;
    svg_context->output_height = y2 - y1 + 1;

    /* svg width/height is 0 */
    if (svg_context->width == 0 || svg_context->height == 0)
        return SVG_OK;

    svg_wb_init((U8*)gdi_work_buffer,gdi_work_buffer_size);
    SVG_TRY
    {
        /* transform to output area */
        {
            float T[6];
            S32 tx, ty, tw, th;

            gdi_util_fit_box(
                GDI_UTIL_MODE_LONG_SIDE_FIT,
                (S32) svg_context->output_width,
                (S32) svg_context->output_height,
                (S32) svg_context->width,
                (S32) svg_context->height,
                &tx,
                &ty,
                &tw,
                &th);
            tx += svg_context->output_x1;
            ty += svg_context->output_y1;

            svg_transform_identify(svg_context->style.transform);

            svg_transform_translate(T, -svg_context->x, -svg_context->y);
            svg_transform_multiply(svg_context->style.transform, T, svg_context->style.transform);

            svg_transform_scale(T, (float)tw / svg_context->width, (float)th / svg_context->height);
            svg_transform_multiply(svg_context->style.transform, svg_context->style.transform, T);

            svg_transform_translate(T, tx, ty);
            svg_transform_multiply(svg_context->style.transform, svg_context->style.transform, T);

            svg_transform_multiply(
                svg_context->style.transform,
                svg_context->style.transform,
                svg_context->predefine_transform);
        }

        /* default style */
        svg_context->style.miter_limit = 4;

        if (svg_context->root)
        {
            if (svg_context->root->style)
            {
                svg_inherit_style(svg_render, svg_context->root);
            }
            else
            {
                svg_render(svg_context->root);
            }
        }
        ret = SVG_OK;
    }
    SVG_CATCH_BEGIN
    {
        ret = (svg_enum) jmpret;
    }
    SVG_CATCH_END 
    svg_wb_uninit();
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  svg_draw_anim_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  arg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
svg_enum svg_draw_anim_single_frame(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 now_tick;
    svg_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(svg_context==NULL)
    {
        return SVG_FAIL;
    }
    kal_get_time(&now_tick);
    if (svg_context->current_time < 0)  /* first time */
    {
        svg_context->current_time = 0;
        svg_context->current_tick = now_tick;
        svg_context->current_serial = 1;
        svg_context->virtual_time = KEY_FRAME_INTERVAL;
    }
    else
    {
        U32 diff_tick;
        U32 diff_ms;

        diff_tick = now_tick - svg_context->current_tick;
        diff_ms = kal_ticks_to_milli_secs(diff_tick);   /* m-seconds */
        svg_context->current_tick = now_tick;
        svg_context->current_time += ((float)diff_ms) / 1000.0;

        if(svg_context->current_time*1000.0 >=svg_context->virtual_time)
		{
            svg_context->current_time = ((float)svg_context->virtual_time)/(float)1000.0;
			svg_context->virtual_time += KEY_FRAME_INTERVAL; /* next frame is 500 ms */
		}
        svg_context->current_serial++;
    }
    
    if (svg_context->max_end_time + 1 < svg_context->current_time)
                return SVG_FAIL;

#ifdef WIN32
    printf("Time: %lf \n", svg_context->current_time);
#endif 
    gdi_layer_push_clip();
    SVG_CLIP_TWO_RECT(
        gdi_act_layer->clipx1,
        gdi_act_layer->clipy1,
        gdi_act_layer->clipx2,
        gdi_act_layer->clipy2,
        svg_context->output_x1, 
        svg_context->output_y1, 
        svg_context->output_x2, 
        svg_context->output_y2,
        NULL);

    gdi_draw_solid_rect(
        svg_context->output_x1,
        svg_context->output_y1,
        svg_context->output_x2,
        svg_context->output_y2,
        GDI_COLOR_WHITE);

    result = svg_draw(
                (svg_handle) svg_context,
                svg_context->output_x1,
                svg_context->output_y1,
                svg_context->output_x2,
                svg_context->output_y2);
    gdi_layer_pop_clip();
  
    if (svg_context->render_callback)
    {
        svg_context->render_callback(result);
    }

    return result;
}

void svg_draw_anim_handler(void *arg)
{
    svg_enum result;
    result = svg_draw_anim_single_frame();
    if (result == SVG_OK)
        StartNonAlignTimer((U16) (SVG_TIMER_BASE), 100, (FuncPtr) svg_draw_anim_handler);
}
svg_enum svg_reset_anim(svg_handle handle, S32 x1, S32 y1, S32 w, S32 h, void (*callback) (svg_enum result))
{
	S32 x2,y2;
    svg_context = (svg_t*) handle;


	if(w==0 && h==0)
	{
		w = (S32)svg_context->width;
		h = (S32)svg_context->height;
	}
	x2 = x1+w-1;
	y2 = y1+h-1;

    svg_context->current_time = -1;
    svg_context->max_end_time = 0;
    svg_context->render_callback = callback;
    svg_context->virtual_time = 0;

    svg_context->output_x1 = x1;
    svg_context->output_y1 = y1;
    svg_context->output_x2 = x2;
    svg_context->output_y2 = y2;
    return SVG_OK;
}
/*****************************************************************************
 * FUNCTION
 *  svg_draw_anim
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle          [IN]        
 *  x1              [IN]        
 *  y1              [IN]        
 *  x2              [IN]        
 *  y2              [IN]        
 *  callback        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
svg_enum svg_draw_anim(svg_handle handle, S32 x1, S32 y1, S32 x2, S32 y2, void (*callback) (svg_enum result))
{
    svg_reset_anim(handle,x1,y1,x2-x1+1,y2-y1+1,callback);
    svg_draw_anim_handler(NULL);
    return SVG_OK;
}


/*****************************************************************************
 * FUNCTION
 *  svg_stop_draw_anim
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void svg_stop_draw_anim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer((U16) (SVG_TIMER_BASE));
}
svg_enum svg_check_stack_overflow(void)
{
#ifdef __MTK_TARGET__
    kal_check_stack(); /* if overflow , assert it */
    {
        kal_taskid myid = kal_get_current_thread_ID();
        //U8* stack_begin;
        if(myid)
        {
            if(kal_get_task_remain_stack_size(myid) < 768)
            //stack_begin = (U8 *)kal_get_task_stack_ptr(myid);
            //stack_begin = (U8*)((struct TC_TCB_STRUCT *)myid)->tc_stack_start;
            //if( ((U8*)&myid) - stack_begin < 768)
            {
                //PRINT_INFORMATION("svg detect stack will be fulled");
                
                if(svg_jmpbuf_is_used)
                    SVG_RAISE(SVG_FAIL_STACK_WILL_OVERFLOW);
                else
                    return SVG_FAIL_STACK_WILL_OVERFLOW;
            }
        }
    }
#endif
    return SVG_OK;
}
#endif /* __MMI_SVG__ */ /* __SVG__ */

