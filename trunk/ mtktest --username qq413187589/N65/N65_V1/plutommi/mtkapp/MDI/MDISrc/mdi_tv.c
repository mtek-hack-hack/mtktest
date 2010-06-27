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
 *  mdi_tv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  TV related interface
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *******************************************************************************/

/* @@mdi_tv.c */
/***************************************************************************** 
* This file is the source file of MDI_TV module.
*****************************************************************************/

#include "MMI_features.h"
#ifdef __MMI_TVOUT__

#ifdef __MTK_TARGET__
   /* 
    * - For PC Simulator and MoDis, do not call media's tvout functions 
    * - For Target, call media's tvout functions.
    */
#define MDI_TVOUT_DRIVER_AVAIALBE
#endif /* __MTK_TARGET__ */ 

/***************************************************************************** 
* Include
*****************************************************************************/
#include "stdC.h"
#include "L4Dr1.h"
#include "MMIDataType.h"    /* MMI Data type */
#include "lcd_sw_rnd.h" /* lcd color format */
#include "lcd_if.h"     /* lcd interface - for rotate */
#include "gdi_include.h"        /* GDI */
#include "mdi_datatype.h"       /* mdi datatype */
#include "QueueGprot.h" /* message handling */
#include "EventsGprot.h"        /* event hadnling - get message return from driver */
#include "mdi_tv.h"     /* mdi tv include */
#include "debuginitdef.h"       /* MMI_ASSERT */

#ifdef MDI_TVOUT_DRIVER_AVAIALBE
#include "med_api.h"    /* media task */
#include "med_main.h"   /* media task */
#include "med_struct.h" /* media task */
#include "Tv_out.h"     /* driver */
#endif /* MDI_TVOUT_DRIVER_AVAIALBE */ 

/***************************************************************************** 
* Define
*****************************************************************************/
/* double buffer */
#define MDI_TV_ACTIVE_BUF_NONE               0
#define MDI_TV_ACTIVE_BUF_1                  1
#define MDI_TV_ACTIVE_BUF_2                  2

//#define MDI_TV_NTSC_WIDTH     TV_OUTPUT_NTSC_WIDTH
//#define MDI_TV_NTSC_HEIGHT    TV_OUTPUT_NTSC_WIDTH
//#define MDI_TV_PAL_WIDTH      TV_OUTPUT_PAL_WIDTH
//#define MDI_TV_PAL_HEIGHT     TV_OUTPUT_PAL_WIDTH

#define MDI_TV_NTSC_WIDTH  512
#define MDI_TV_NTSC_HEIGHT 384
#define MDI_TV_PAL_WIDTH   512
#define MDI_TV_PAL_HEIGHT  384

/* one of double buffer's size */
/* buffer_width*buffer_height*2 */
#define TVOUT_BUFFER_SIZE (512*384*2)

/***************************************************************************** 
* Typedef 
*****************************************************************************/

/***************************************************************************** 
* Global Variable
*****************************************************************************/
U8 g_tvout_buf_1[TVOUT_BUFFER_SIZE];
U8 g_tvout_buf_2[TVOUT_BUFFER_SIZE];

/***************************************************************************** 
* Global Function
*****************************************************************************/

/***************************************************************************** 
* Local Variable
*****************************************************************************/
mdi_tv_cntx_struct g_mdi_tv_cntx;

/***************************************************************************** 
* Local Function
*****************************************************************************/
static void mdi_tvout_connect_ind_hdlr(void *msg_ptr);


/*****************************************************************************
 * FUNCTION
 *  mdi_tvout_init
 * DESCRIPTION
 *  Init MDI_TV module.
 * PARAMETERS
 *  tv_event_callback       [IN]        Callback function when event happens
 * RETURN VALUE
 *  MDI_RES_TV_SUCCEED  Succeed
 * REMARKS
 *  void
 * SEE ALSO
 *  void
 *****************************************************************************/
MDI_RESULT mdi_tvout_init(mdi_tv_event_callback tv_event_callback)
{
#ifdef MDI_TVOUT_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 buffer_size;
    S32 PAL_size;
    S32 NTSC_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA,"[MDI_TVOUT] mdi_tvout_init()");

    /* callback function shall not be NULL */
    MMI_ASSERT(tv_event_callback != NULL);

    g_mdi_tv_cntx.event_callback = tv_event_callback;

    SetProtocolEventHandler(mdi_tvout_connect_ind_hdlr, MSG_ID_MEDIA_TVO_TV_CONNECT_IND);

    if (!g_mdi_tv_cntx.is_init)
    {
        /* init mode value */
        g_mdi_tv_cntx.mode = MDI_TV_MODE_NONE;

        /* GDI is defalt owner */
        g_mdi_tv_cntx.owner = MDI_TV_OWNER_GDI;

        g_mdi_tv_cntx.act_buf_id = MDI_TV_ACTIVE_BUF_NONE;
        g_mdi_tv_cntx.force_disable_vertical_filter = FALSE;
            
        /* allocate buffer */
        /* move from start to init, to avoid med memory fragmentation problem */
        NTSC_size = MDI_TV_NTSC_WIDTH * MDI_TV_NTSC_HEIGHT;
        PAL_size = MDI_TV_PAL_WIDTH * MDI_TV_PAL_HEIGHT;

        if (NTSC_size > PAL_size)
        {
            buffer_size = NTSC_size << 1;
        }
        else
        {
            buffer_size = PAL_size << 1;
        }
 
        g_mdi_tv_cntx.buf_1_ptr = &g_tvout_buf_1[0];
        g_mdi_tv_cntx.buf_2_ptr = &g_tvout_buf_2[0];

        g_mdi_tv_cntx.rotate_buf_1_ptr = NULL;
        g_mdi_tv_cntx.rotate_buf_2_ptr = NULL;

        g_mdi_tv_cntx.is_enable = FALSE;

        g_mdi_tv_cntx.layer_1 = GDI_LAYER_EMPTY_HANDLE;
        g_mdi_tv_cntx.layer_2 = GDI_LAYER_EMPTY_HANDLE;

        g_mdi_tv_cntx.is_init = TRUE;
    }

    return MDI_RES_TV_SUCCEED;

#else /* MDI_TVOUT_DRIVER_AVAIALBE */ 
    return MDI_RES_TV_SUCCEED;
#endif /* MDI_TVOUT_DRIVER_AVAIALBE */ 
}
/*****************************************************************************
 * FUNCTION
 *  mdi_tvout_force_disable_vertical_filter
 * DESCRIPTION
 *  .
 *  Set TV-Out mode.
 * PARAMETERS
 *  void
 * RETURN VALUE
 *  MDI_RES_TV_SUCCEED     Succeed
 *****************************************************************************/
MDI_RESULT mdi_tvout_force_disable_vertical_filter(void)
{
    g_mdi_tv_cntx.force_disable_vertical_filter = TRUE;
    return MDI_RES_TV_SUCCEED;
}
/*****************************************************************************
 * FUNCTION
 *  mdi_tvout_set_mode
 * DESCRIPTION
 *  .
 *  Set TV-Out mode.
 * PARAMETERS
 *  mode                    [IN]        Mode enum
 *  owner_draw_width        [IN]        Owner draw mode's buffer width
 *  owner_draw_height       [IN]        Owner draw mode's buffer height
 * RETURN VALUE
 *  MDI_RES_TV_SUCCEED     Succeed
 *****************************************************************************/
MDI_RESULT mdi_tvout_set_mode(mdi_tv_mode_enum mode, S32 owner_draw_width, S32 owner_draw_height)
{
#ifdef MDI_TVOUT_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    tvo_mode_struct tvout_data;
    S32 prev_buf_width;
    S32 prev_buf_height;
    U8 lcd_rotate;
    S32 buffer_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA,"[MDI_TVOUT] mdi_tvout_set_mode() mode:%d, width:%d, height:%d",mode,owner_draw_width,owner_draw_height);

    prev_buf_width = g_mdi_tv_cntx.buf_width;
    prev_buf_height = g_mdi_tv_cntx.buf_height;

    lcd_rotate = gdi_lcd_get_rotate();

    if (g_mdi_tv_cntx.rotate_buf_1_ptr != NULL)
    {
        /* !! disable MODE 4 due to some senarior cant use this mode */
        MMI_ASSERT(0);
    
        /* free buffer if needed */
        media_free_ext_buffer(MOD_MMI, (void **)&g_mdi_tv_cntx.rotate_buf_1_ptr);
        media_free_ext_buffer(MOD_MMI, (void **)&g_mdi_tv_cntx.rotate_buf_2_ptr);

        g_mdi_tv_cntx.rotate_buf_1_ptr = NULL;
        g_mdi_tv_cntx.rotate_buf_2_ptr = NULL;
    }

    if (mode == MDI_TV_MODE_LCD_SCR)
    {
        tvout_data.tv_output_vertical_filter = TRUE;

        g_mdi_tv_cntx.mode = TV_OUTPUT_MODE1;
        g_mdi_tv_cntx.buf_width = UI_DEVICE_WIDTH;
        g_mdi_tv_cntx.buf_height = UI_DEVICE_HEIGHT;

        /* bind tvout mainlcd to tvout */
        gdi_lcd_set_bind(GDI_LCD_TVOUT_HANDLE);
    }
    else if (mode == MDI_TV_MODE_MULTIMEDIA_HOR_LCD_SCR)
    {
        if (((lcd_rotate == GDI_LAYER_ROTATE_270) ||
             (lcd_rotate == GDI_LAYER_ROTATE_90)) && (gdi_lcd_get_rotate_by_layer()))
        {
            /* if gdi_lcd is rotate and not using lcm rotate - using mode 4 */
            
            /* !! disable MODE 4 due to some senarior cant use this mode */
            MMI_ASSERT(0);

            g_mdi_tv_cntx.mode = TV_OUTPUT_MODE4;
            g_mdi_tv_cntx.buf_width = UI_DEVICE_HEIGHT; 
            g_mdi_tv_cntx.buf_height = UI_DEVICE_WIDTH;
            
            if (g_mdi_tv_cntx.rotate_buf_1_ptr == NULL)
            {
                buffer_size = UI_DEVICE_HEIGHT * UI_DEVICE_WIDTH * MDI_TV_BUFFER_DEPTH;

                /* allocate new buffer */
                media_get_ext_buffer(MOD_MMI, (void **)&g_mdi_tv_cntx.rotate_buf_1_ptr, buffer_size);
                media_get_ext_buffer(MOD_MMI, (void **)&g_mdi_tv_cntx.rotate_buf_2_ptr, buffer_size);
            }

            gdi_lcd_set_bind(GDI_NULL_HANDLE);
        }
        else
        {
            tvout_data.tv_output_vertical_filter = FALSE;
            g_mdi_tv_cntx.mode = TV_OUTPUT_MODE1;
            g_mdi_tv_cntx.buf_width = UI_DEVICE_HEIGHT;
            g_mdi_tv_cntx.buf_height = UI_DEVICE_WIDTH;

            #ifdef MDI_TVOUT_MT6228_SERIES
            if ( 0 != (g_mdi_tv_cntx.buf_width % 8))
                g_mdi_tv_cntx.buf_width += (8-(g_mdi_tv_cntx.buf_width % 8));
            #endif

            /* bind tvout mainlcd to tvout */
            gdi_lcd_set_bind(GDI_LCD_TVOUT_HANDLE);
        }

    }
    else if (mode == MDI_TV_MODE_MULTIMEDIA_FULL_SCR)
    {
        tvout_data.tv_output_vertical_filter = FALSE;
    
        if (((lcd_rotate == GDI_LAYER_ROTATE_270) ||
             (lcd_rotate == GDI_LAYER_ROTATE_90)) && (gdi_lcd_get_rotate_by_layer()))
        {
            /* if gdi_lcd is rotate and not using lcm rotate - using mode 3 */
            g_mdi_tv_cntx.mode = TV_OUTPUT_MODE3;
            g_mdi_tv_cntx.buf_width = g_mdi_tv_cntx.best_buf_width;
            g_mdi_tv_cntx.buf_height = g_mdi_tv_cntx.best_buf_height;
        }
        else
        {
            g_mdi_tv_cntx.mode = TV_OUTPUT_MODE2;
            g_mdi_tv_cntx.buf_width = g_mdi_tv_cntx.best_buf_width;
            g_mdi_tv_cntx.buf_height = g_mdi_tv_cntx.best_buf_height;
        }

        gdi_lcd_set_bind(GDI_NULL_HANDLE);
    }
    else if (mode == MDI_TV_MODE_OWNER_DRAW)
    {

        /* TV OUT Buffer width/height must >= 2 */
        if ((owner_draw_width<=1)||(owner_draw_height<=1))
        ASSERT(0);

        if (g_mdi_tv_cntx.force_disable_vertical_filter == TRUE)
        {
            tvout_data.tv_output_vertical_filter = FALSE;
            g_mdi_tv_cntx.force_disable_vertical_filter = FALSE;
        }
        else
        tvout_data.tv_output_vertical_filter = TRUE;

        g_mdi_tv_cntx.mode = TV_OUTPUT_MODE1;
        g_mdi_tv_cntx.buf_width = owner_draw_width;
        g_mdi_tv_cntx.buf_height = owner_draw_height;

        /* unbind lcd to tvout */
        gdi_lcd_set_bind(GDI_NULL_HANDLE);
    }
    else
    {
        /* unsupported mode */
        MMI_ASSERT(0);
    }

    /* if layer alreay created */

    /* resize layer if needed */
    if (g_mdi_tv_cntx.layer_1 != GDI_LAYER_EMPTY_HANDLE)
    {
        if ((prev_buf_width != g_mdi_tv_cntx.buf_width) || (prev_buf_height != g_mdi_tv_cntx.buf_height))
        {
            gdi_layer_push_and_set_active(g_mdi_tv_cntx.layer_1);
            gdi_layer_resize(g_mdi_tv_cntx.buf_width, g_mdi_tv_cntx.buf_height);
            gdi_layer_clear(GDI_COLOR_BLACK);
            gdi_layer_pop_and_restore_active();

            gdi_layer_push_and_set_active(g_mdi_tv_cntx.layer_2);
            gdi_layer_resize(g_mdi_tv_cntx.buf_width, g_mdi_tv_cntx.buf_height);
            gdi_layer_clear(GDI_COLOR_BLACK);
            gdi_layer_pop_and_restore_active();
        }
    }

    /* tv out buffer is 16bit rbg buffer */
    /* in some scenario, the buffer will be 12bit per pixel(YUV444), but we still allocate 16bit */
    g_mdi_tv_cntx.buf_size = g_mdi_tv_cntx.buf_width * g_mdi_tv_cntx.buf_height * MDI_TV_BUFFER_DEPTH;

    tvout_data.tv_output_format = g_mdi_tv_cntx.format;
    tvout_data.tv_output_mode = g_mdi_tv_cntx.mode;
    tvout_data.tv_output_width = g_mdi_tv_cntx.buf_width;
    tvout_data.tv_output_height = g_mdi_tv_cntx.buf_height;

    media_tvo_set_mode(MOD_MMI, &tvout_data);

    return MDI_RES_TV_SUCCEED;
#else /* MDI_TVOUT_DRIVER_AVAIALBE */ 
    return MDI_RES_TV_SUCCEED;
#endif /* MDI_TVOUT_DRIVER_AVAIALBE */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_tvout_start
 * DESCRIPTION
 *  .
 *  Start display on TV.
 * PARAMETERS
 *  void
 * RETURN VALUE
 *  MDI_RES_TV_SUCCEED     Succeed
 *****************************************************************************/
MDI_RESULT mdi_tvout_start(void)
{
#ifdef MDI_TVOUT_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    tvo_mode_struct tvout_data;
    S32 buffer_size;
    S32 ret;
    S32 NTSC_size;
    S32 PAL_size;
    S32 max_buf_width;
    S32 max_buf_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA,"[MDI_TVOUT] mdi_tvout_start()");

    /* if mode is none, means caller didnt set mode correctly before start */
    MMI_ASSERT(g_mdi_tv_cntx.mode != MDI_TV_MODE_NONE);

    /* var check */
    MMI_ASSERT(g_mdi_tv_cntx.layer_1 == GDI_LAYER_EMPTY_HANDLE);
    MMI_ASSERT(g_mdi_tv_cntx.layer_2 == GDI_LAYER_EMPTY_HANDLE);


    NTSC_size = MDI_TV_NTSC_WIDTH * MDI_TV_NTSC_HEIGHT;
    PAL_size = MDI_TV_PAL_WIDTH * MDI_TV_PAL_HEIGHT;

    if (NTSC_size > PAL_size)
    {
        buffer_size = NTSC_size << 1;
        max_buf_width = MDI_TV_NTSC_WIDTH;
        max_buf_height = MDI_TV_NTSC_HEIGHT;
    }
    else
    {
        buffer_size = PAL_size << 1;
        max_buf_width = MDI_TV_PAL_WIDTH;
        max_buf_height = MDI_TV_PAL_HEIGHT;
    }

    /* clear buffer as black */
    memset((void*)g_mdi_tv_cntx.buf_1_ptr, 0, buffer_size);
    memset((void*)g_mdi_tv_cntx.buf_2_ptr, 0, buffer_size);

    /* set active buffer as buffer 1 */
    g_mdi_tv_cntx.act_buf_id = MDI_TV_ACTIVE_BUF_1;

    /* use buffer to create layer */
    gdi_layer_create_using_outside_memory(
        0,
        0,
        max_buf_width,
        max_buf_height,
        &g_mdi_tv_cntx.layer_1,
        (PU8) g_mdi_tv_cntx.buf_1_ptr,
        (S32) buffer_size);

    gdi_layer_push_and_set_active(g_mdi_tv_cntx.layer_1);
    gdi_layer_resize(g_mdi_tv_cntx.buf_width, g_mdi_tv_cntx.buf_height);
    gdi_layer_pop_and_restore_active();

    gdi_layer_create_using_outside_memory(
        0,
        0,
        max_buf_width,
        max_buf_height,
        &g_mdi_tv_cntx.layer_2,
        (PU8) g_mdi_tv_cntx.buf_2_ptr,
        (S32) buffer_size);

    gdi_layer_push_and_set_active(g_mdi_tv_cntx.layer_2);
    gdi_layer_resize(g_mdi_tv_cntx.buf_width, g_mdi_tv_cntx.buf_height);
    gdi_layer_pop_and_restore_active();

    tvout_data.tv_output_format = g_mdi_tv_cntx.format;
    tvout_data.tv_output_mode = g_mdi_tv_cntx.mode;
    tvout_data.tv_output_width = g_mdi_tv_cntx.buf_width;
    tvout_data.tv_output_height = g_mdi_tv_cntx.buf_height;

    /* set buffer to driver before it start running */
    tv_fb_update(TV_OUT_OWNER_MMI, (S32) g_mdi_tv_cntx.buf_1_ptr);

    ret = media_tvo_start(MOD_MMI, &tvout_data);
    PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA,"[MDI_TVOUT] media ret: %d", ret);

    if (ret == MED_RES_OK)
    {
        g_mdi_tv_cntx.is_enable = TRUE;
		gdi_lcd_repaint_all();

        return MDI_RES_TV_SUCCEED;
    }
    else if (ret == MED_RES_BUSY)
    {
        /* driver not ready - maybe already stopped */
        g_mdi_tv_cntx.mode = MDI_TV_MODE_NONE;
        g_mdi_tv_cntx.is_enable = FALSE;

        /* free layer */
        gdi_layer_free(g_mdi_tv_cntx.layer_1);
        gdi_layer_free(g_mdi_tv_cntx.layer_2);

        g_mdi_tv_cntx.layer_1 = GDI_LAYER_EMPTY_HANDLE;
        g_mdi_tv_cntx.layer_2 = GDI_LAYER_EMPTY_HANDLE;

        return MDI_RES_TV_NOT_READY;
    }
    else
    {
        MMI_ASSERT(0);
    }

    return MDI_RES_TV_SUCCEED;

#else /* MDI_TVOUT_DRIVER_AVAIALBE */ 
    return MDI_RES_TV_SUCCEED;
#endif /* MDI_TVOUT_DRIVER_AVAIALBE */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_tvout_stop
 * DESCRIPTION
 *  Stop display on TV.
 * PARAMETERS
 *  void
 * RETURN VALUE
 *  MDI_RES_TV_SUCCEED      Succeed
 *****************************************************************************/
MDI_RESULT mdi_tvout_stop(void)
{
#ifdef MDI_TVOUT_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA,"[MDI_TVOUT] mdi_tvout_stop()");
    PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA,"[MDI_TVOUT] is_enable: %d", g_mdi_tv_cntx.is_enable);

    if (g_mdi_tv_cntx.is_enable == FALSE)
    {
        return MDI_RES_TV_ALREADY_STOPPED;
    }

    MMI_ASSERT(g_mdi_tv_cntx.layer_1 != GDI_LAYER_EMPTY_HANDLE);
    MMI_ASSERT(g_mdi_tv_cntx.layer_2 != GDI_LAYER_EMPTY_HANDLE);

    g_mdi_tv_cntx.mode = MDI_TV_MODE_NONE;
    g_mdi_tv_cntx.is_enable = FALSE;

    media_tvo_stop(MOD_MMI);

    /* free layer */
    gdi_layer_free(g_mdi_tv_cntx.layer_1);
    gdi_layer_free(g_mdi_tv_cntx.layer_2);

    if (g_mdi_tv_cntx.rotate_buf_1_ptr != NULL)
    {
        /* !! disable MODE 4 due to some senarior cant use this mode */
        MMI_ASSERT(0);
    
        media_free_ext_buffer(MOD_MMI, (void **)&g_mdi_tv_cntx.rotate_buf_1_ptr);
        media_free_ext_buffer(MOD_MMI, (void **)&g_mdi_tv_cntx.rotate_buf_2_ptr);
        g_mdi_tv_cntx.rotate_buf_1_ptr = NULL;
        g_mdi_tv_cntx.rotate_buf_2_ptr = NULL;
    }

    g_mdi_tv_cntx.layer_1 = GDI_LAYER_EMPTY_HANDLE;
    g_mdi_tv_cntx.layer_2 = GDI_LAYER_EMPTY_HANDLE;

    return MDI_RES_TV_SUCCEED;

#else /* MDI_TVOUT_DRIVER_AVAIALBE */ 
    return MDI_RES_TV_SUCCEED;
#endif /* MDI_TVOUT_DRIVER_AVAIALBE */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_tvout_pause_for_em_mode
 * DESCRIPTION
 *  Pause display on TV - only for enginner mode
 *  Will stop tv-out feature, but keep all resource
 * PARAMETERS
 *  void
 * RETURN VALUE
 *  MDI_RES_TV_SUCCEED      Succeed
 *****************************************************************************/
MDI_RESULT mdi_tvout_pause_for_em_mode(void)
{
#ifdef MDI_TVOUT_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA,"[MDI_TVOUT] mdi_tvout_pause()");
    
    g_mdi_tv_cntx.mode = MDI_TV_MODE_NONE;
    g_mdi_tv_cntx.is_enable = FALSE;
    media_tvo_stop(MOD_MMI);   
#endif /* MDI_TVOUT_DRIVER_AVAIALBE */     

    return MDI_RES_TV_SUCCEED;
}



/*****************************************************************************
 * FUNCTION
 *  mdi_tvout_resume_for_em_mode
 * DESCRIPTION
 *  Resume display on TV - only for enginner mode
 *  Will resume tv-out 
 * PARAMETERS
 *  void
 * RETURN VALUE
 *  MDI_RES_TV_SUCCEED      Succeed
 *****************************************************************************/
MDI_RESULT mdi_tvout_resume_for_em_mode(void)
{
#ifdef MDI_TVOUT_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    tvo_mode_struct tvout_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA,"[MDI_TVOUT] mdi_tvout_pause()");
    
    g_mdi_tv_cntx.mode =MDI_TV_MODE_LCD_SCR;    
    g_mdi_tv_cntx.is_enable = TRUE;
         
    tvout_data.tv_output_format = g_mdi_tv_cntx.format;
    tvout_data.tv_output_mode = g_mdi_tv_cntx.mode;
    tvout_data.tv_output_width = g_mdi_tv_cntx.buf_width;
    tvout_data.tv_output_height = g_mdi_tv_cntx.buf_height;

    /* set buffer to driver before it start running */
    tv_fb_update(TV_OUT_OWNER_MMI, (S32) g_mdi_tv_cntx.buf_1_ptr);

    media_tvo_start(MOD_MMI, &tvout_data);
#endif /* MDI_TVOUT_DRIVER_AVAIALBE */     

    return MDI_RES_TV_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_tvout_sleep_in
 * DESCRIPTION
 *  sleep in
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_tvout_sleep_in(void)
{
#ifdef MDI_TVOUT_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA,"[MDI_TVOUT] mdi_tvout_sleep_in()");

    /* TODO: add more assert checking */
    /* TODO: call media task */

    enable_tv_output(KAL_FALSE);
#endif /* MDI_TVOUT_DRIVER_AVAIALBE */ 
    return MDI_RES_TV_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_tvout_sleep_out
 * DESCRIPTION
 *  sleep in
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_tvout_sleep_out(void)
{
#ifdef MDI_TVOUT_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA,"[MDI_TVOUT] mdi_tvout_sleep_out()");

    /* TODO: add more assert checking */
    /* TODO: call media task */

    /* force redraw full screen after lcd wake up */
    gdi_layer_lock_frame_buffer();
    gdi_lcd_repaint_all();
    gdi_layer_unlock_frame_buffer();

    enable_tv_output(KAL_TRUE);

#endif /* MDI_TVOUT_DRIVER_AVAIALBE */ 
    return MDI_RES_TV_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_tvout_get_para
 * DESCRIPTION
 *  Get parameters.
 *  This function is called by GDI, MDI_CAMREA, MDI_VIDEO to get variables to
 *  fill in TV-out related parameters required by drivers.
 * PARAMETERS
 *  owner               [IN]        Owner id
 *  mode_ptr            [OUT]       Mode
 *  buf_width_ptr       [OUT]       Buffer width
 *  buf_height_ptr      [OUT]       Buffer height
 *  buf_size_ptr        [OUT]       Buffer size
 *  buf_1_pp            [OUT]       Buffer1's pointer
 *  buf_2_pp            [OUT]       Buffer2's pointer
 *  rotate_buf_1_pp     [OUT]       Rotation Buffer1's pointer, for Mode 4 only
 *  rotate_buf_2_pp     [OUT]       Rotation Buffer2's pointer, for Mode 4 only
 * RETURN VALUE
 *  MDI_RES_TV_ENABLE       TV-out is enabled and get parameter succeed
 *  MDI_RES_TV_DISABLE      TV-out is not enabled
 *  MDI_RES_TV_NOT_OWNER    The caller is not a valid owner
 *****************************************************************************/
MDI_RESULT mdi_tvout_get_para(
            mdi_tv_owner_enum owner,
            U16 *mode_ptr,
            U16 *buf_width_ptr,
            U16 *buf_height_ptr,
            U32 *buf_size_ptr,
            U8 **buf_1_pp,
            U8 **buf_2_pp,
            U8 **rotate_buf_1_pp,
            U8 **rotate_buf_2_pp)
{
#ifdef MDI_TVOUT_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 tvout_using_buf_ptr = NULL;
    PU8 mmi_using_buf_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get tvout using buffer */
    tvout_using_buf_ptr = (PU8) get_current_tv_output_buffer();

    if (tvout_using_buf_ptr == g_mdi_tv_cntx.buf_1_ptr)
    {
        /* if tvout is using buffer 1, we can use buffer 2 to draw */
        g_mdi_tv_cntx.act_buf_id = MDI_TV_ACTIVE_BUF_2;
        mmi_using_buf_ptr = g_mdi_tv_cntx.buf_2_ptr;
    }
    else if (tvout_using_buf_ptr == g_mdi_tv_cntx.buf_2_ptr)
    {
        /* if tvout is using buffer 2, we can use buffer 1 to draw */
        g_mdi_tv_cntx.act_buf_id = MDI_TV_ACTIVE_BUF_1;
        mmi_using_buf_ptr = g_mdi_tv_cntx.buf_1_ptr;
    }
    else
    {
        /* tvout not using any buffer */
        /* this may happened when tv out using video play buffer of driver directly */
    }

    /* init */
    if (mode_ptr != NULL)
    {
        *mode_ptr = NULL;
    }

    if (buf_width_ptr != NULL)
    {
        *buf_width_ptr = NULL;
    }

    if (buf_height_ptr != NULL)
    {
        *buf_height_ptr = NULL;
    }

    if (buf_size_ptr != NULL)
    {
        *buf_size_ptr = NULL;
    }

    if (buf_1_pp != NULL)
    {
        *buf_1_pp = NULL;
    }

    if (buf_2_pp != NULL)
    {
        *buf_2_pp = NULL;
    }

    if (rotate_buf_1_pp != NULL)
    {
        /* !! disable MODE 4 due to some senarior cant use this mode */
        MMI_ASSERT(0);
        *rotate_buf_1_pp = NULL;
    }

    if (rotate_buf_2_pp != NULL)
    {
        /* !! disable MODE 4 due to some senarior cant use this mode */
        MMI_ASSERT(0);
        *rotate_buf_2_pp = NULL;
    }

    /* tv out not active */
    if (g_mdi_tv_cntx.mode == MDI_TV_MODE_NONE)
    {
        return MDI_RES_TV_DISABLE;
    }

    switch (owner)
    {
        case MDI_TV_OWNER_GDI:

            if (g_mdi_tv_cntx.owner == MDI_TV_OWNER_GDI)
            {

                if ((tvout_using_buf_ptr != NULL) && (mmi_using_buf_ptr != NULL))
                {
                    /* copy content from tv-out using buffer to the other buffer */
                    memcpy(
                        (void*)mmi_using_buf_ptr,
                        (void*)tvout_using_buf_ptr,
                        g_mdi_tv_cntx.buf_width * g_mdi_tv_cntx.buf_height * MDI_TV_BUFFER_DEPTH);
                }

                /* assgin value to caller */
                if (buf_width_ptr != NULL)
                {
                    *buf_width_ptr = g_mdi_tv_cntx.buf_width;
                }

                if (buf_height_ptr != NULL)
                {
                    *buf_height_ptr = g_mdi_tv_cntx.buf_height;
                }

                if (buf_size_ptr != NULL)
                {
                    *buf_size_ptr = g_mdi_tv_cntx.buf_size;
                }

                if (g_mdi_tv_cntx.act_buf_id == MDI_TV_ACTIVE_BUF_1)
                {
                    if (buf_1_pp != NULL)
                    {
                        *buf_1_pp = g_mdi_tv_cntx.buf_1_ptr;
                    }
                }
                else
                {
                    if (buf_1_pp != NULL)
                    {
                        *buf_1_pp = g_mdi_tv_cntx.buf_2_ptr;
                    }
                }

                /* return true means tv out is active */
                return MDI_RES_TV_ENABLE;
            }
            else
            {
                return MDI_RES_TV_NOT_OWNER;
            }
            break;

        case MDI_TV_OWNER_CAMERA:
        case MDI_TV_OWNER_VIDEO:

            if (g_mdi_tv_cntx.owner == MDI_TV_OWNER_GDI)
            {
                MMI_ASSERT(0);
                return MDI_RES_TV_NOT_OWNER;
            }
            else
            {
                if (mode_ptr != NULL)
                {
                    *mode_ptr = g_mdi_tv_cntx.mode;
                }

                /* assgin value to caller */
                if (buf_width_ptr != NULL)
                {
                    *buf_width_ptr = g_mdi_tv_cntx.buf_width;
                }

                if (buf_height_ptr != NULL)
                {
                    *buf_height_ptr = g_mdi_tv_cntx.buf_height;
                }

                if (buf_size_ptr != NULL)
                {
                    *buf_size_ptr = g_mdi_tv_cntx.buf_size;
                }

                if (g_mdi_tv_cntx.act_buf_id == MDI_TV_ACTIVE_BUF_1)
                {
                    if (buf_1_pp != NULL)
                    {
                        *buf_1_pp = g_mdi_tv_cntx.buf_1_ptr;
                    }

                    if (buf_2_pp != NULL)
                    {
                        *buf_2_pp = g_mdi_tv_cntx.buf_2_ptr;
                    }
                }
                else
                {
                    if (buf_1_pp != NULL)
                    {
                        *buf_1_pp = g_mdi_tv_cntx.buf_2_ptr;
                    }

                    if (buf_2_pp != NULL)
                    {
                        *buf_2_pp = g_mdi_tv_cntx.buf_1_ptr;
                    }
                }

                if (rotate_buf_1_pp != NULL)
                {
                    /* !! disable MODE 4 due to some senarior cant use this mode */
                    MMI_ASSERT(0);                
                    
                    *rotate_buf_1_pp = g_mdi_tv_cntx.rotate_buf_1_ptr;
                }

                if (rotate_buf_2_pp != NULL)
                {
                    /* !! disable MODE 4 due to some senarior cant use this mode */
                    MMI_ASSERT(0);
                
                    *rotate_buf_2_pp = g_mdi_tv_cntx.rotate_buf_2_ptr;
                }

                /* return true means tv out is active */
                return MDI_RES_TV_ENABLE;
            }
            break;

        case MDI_TV_OWNER_APP:

            if (g_mdi_tv_cntx.owner == MDI_TV_OWNER_APP)
            {
                /* assgin value to caller */
                if (buf_width_ptr != NULL)
                {
                    *buf_width_ptr = g_mdi_tv_cntx.buf_width;
                }

                if (buf_height_ptr != NULL)
                {
                    *buf_height_ptr = g_mdi_tv_cntx.buf_height;
                }

                if (buf_size_ptr != NULL)
                {
                    *buf_size_ptr = g_mdi_tv_cntx.buf_size;
                }

                if (g_mdi_tv_cntx.act_buf_id == MDI_TV_ACTIVE_BUF_1)
                {
                    if (buf_1_pp != NULL)
                    {
                        *buf_1_pp = g_mdi_tv_cntx.buf_1_ptr;
                    }
                }
                else
                {
                    if (buf_1_pp != NULL)
                    {
                        *buf_1_pp = g_mdi_tv_cntx.buf_2_ptr;
                    }
                }

                /* return true means tv out is active */
                return MDI_RES_TV_ENABLE;
            }
            else
            {
                MMI_ASSERT(0);
                return MDI_RES_TV_NOT_OWNER;
            }
            break;

        default:
            MMI_ASSERT(0);

    }

    return MDI_RES_TV_SUCCEED;

#else /* MDI_TVOUT_DRIVER_AVAIALBE */ 
    return MDI_RES_TV_SUCCEED;
#endif /* MDI_TVOUT_DRIVER_AVAIALBE */ 

}


/*****************************************************************************
 * FUNCTION
 *  mdi_tvout_blt
 * DESCRIPTION
 *  Blt TV-out buffer to TV.
 * PARAMETERS
 *  void
 * RETURN VALUE
 *  MDI_RES_TV_SUCCEED      Succeed
 *****************************************************************************/
MDI_RESULT mdi_tvout_blt(void)
{
#ifdef MDI_TVOUT_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* tvout_blt function can only call when owner is GDI or MMI APP */
    MMI_ASSERT((g_mdi_tv_cntx.owner == MDI_TV_OWNER_GDI) || (g_mdi_tv_cntx.owner == MDI_TV_OWNER_APP));

    /* blt ot tvout and toggle double buffer */
    if (g_mdi_tv_cntx.act_buf_id == MDI_TV_ACTIVE_BUF_1)
    {
        /* buffer 1 */
        tv_fb_update(TV_OUT_OWNER_MMI, (S32) g_mdi_tv_cntx.buf_1_ptr);
    }
    else
    {
        /* buffer 2 */
        tv_fb_update(TV_OUT_OWNER_MMI, (S32) g_mdi_tv_cntx.buf_2_ptr);
    }

    return MDI_RES_TV_SUCCEED;
#else /* MDI_TVOUT_DRIVER_AVAIALBE */ 
    return MDI_RES_TV_SUCCEED;
#endif /* MDI_TVOUT_DRIVER_AVAIALBE */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_tvout_set_format
 * DESCRIPTION
 *  Set TV-Out format.
 * PARAMETERS
 *  format      [IN]        TV-Out output format
 * RETURN VALUE
 *  MDI_RES_TV_SUCCEED      Succeed
 *****************************************************************************/
MDI_RESULT mdi_tvout_set_format(mdi_tv_format_enum format)
{
#ifdef MDI_TVOUT_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    tvo_mode_struct tvout_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (format)
    {
        case MDI_TV_OUTPUT_FORMAT_PAL:
            g_mdi_tv_cntx.format = TV_FORMAT_PAL;
            g_mdi_tv_cntx.best_buf_width = MDI_TV_PAL_WIDTH;
            g_mdi_tv_cntx.best_buf_height = MDI_TV_PAL_HEIGHT;
            break;

        case MDI_TV_OUTPUT_FORMAT_NTSC:
            g_mdi_tv_cntx.format = TV_FORMAT_NTSC;
            g_mdi_tv_cntx.best_buf_width = MDI_TV_NTSC_WIDTH;
            g_mdi_tv_cntx.best_buf_height = MDI_TV_NTSC_HEIGHT;
            break;

        case MDI_TV_OUTPUT_FORMAT_PALM:
            g_mdi_tv_cntx.best_buf_width = MDI_TV_PAL_WIDTH;
            g_mdi_tv_cntx.best_buf_height = MDI_TV_PAL_HEIGHT;
            g_mdi_tv_cntx.format = TV_FORMAT_PALM;
            break;

        case MDI_TV_OUTPUT_FORMAT_PALC:
            g_mdi_tv_cntx.best_buf_width = MDI_TV_PAL_WIDTH;
            g_mdi_tv_cntx.best_buf_height = MDI_TV_PAL_HEIGHT;
            g_mdi_tv_cntx.format = TV_FORMAT_PALC;
            break;

        default:
            MMI_ASSERT(0);

    }

    if (mdi_tvout_is_enable())
    {
        tvout_data.tv_output_format = g_mdi_tv_cntx.format;
        tvout_data.tv_output_mode = g_mdi_tv_cntx.mode;
        tvout_data.tv_output_width = g_mdi_tv_cntx.buf_width;
        tvout_data.tv_output_height = g_mdi_tv_cntx.buf_height;

        media_tvo_stop(MOD_MMI);
        media_tvo_set_mode(MOD_MMI, &tvout_data);
        media_tvo_start(MOD_MMI, &tvout_data);
    }

#endif /* MDI_TVOUT_DRIVER_AVAIALBE */ 

    return MDI_RES_TV_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_tvout_set_owner
 * DESCRIPTION
 *  Set owner of TV-Out.
 * PARAMETERS
 *  owner       [IN]        TV-Out owner
 * RETURN VALUE
 *  MDI_RES_TV_SUCCEED      Succeed
 *****************************************************************************/
MDI_RESULT mdi_tvout_set_owner(mdi_tv_owner_enum owner)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 
     * if previous owner is GDI and change to camera or video play, we need the
     * dobule buffer to have same MMI content, so we need blt once more 
     */
    PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA,"[MDI_TVOUT] mdi_tvout_set_owner : %d", owner);

    if ((g_mdi_tv_cntx.owner == MDI_TV_OWNER_GDI) && ((owner == MDI_TV_OWNER_CAMERA) || (owner == MDI_TV_OWNER_VIDEO)))
    {
        gdi_lcd_repaint_all();
    }

    g_mdi_tv_cntx.owner = owner;

    return MDI_RES_TV_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_tvout_get_owner
 * DESCRIPTION
 *  Get current owner of TV-Out.
 * PARAMETERS
 *  void
 *  owner(?)        [IN]        TV-Out owner
 * RETURNS
 *  Current TV-Out owner.
 *****************************************************************************/
mdi_tv_owner_enum mdi_tvout_get_owner(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mdi_tv_cntx.owner;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_tvout_is_enable
 * DESCRIPTION
 *  Check if TV-out is enable or not.
 * PARAMETERS
 *  void
 * RETURN VALUE
 *  MMI_TRUE    TV-Out is enabled
 *  MMI_FASE    TV-Out is disabled
 *****************************************************************************/
MMI_BOOL mdi_tvout_is_enable(void)
{
#ifdef MDI_TVOUT_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mdi_tv_cntx.is_enable;

#else /* MDI_TVOUT_DRIVER_AVAIALBE */ 
    /* in PC simuator, always disable TV Out */
    return FALSE;
#endif /* MDI_TVOUT_DRIVER_AVAIALBE */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_tvout_get_active_layer
 * DESCRIPTION
 *  Get current active TV-out layer. We are using double layer for TV-Out.
 *  One layer is using by TV-out driver, it continously getting data from that
 *  buffer and draw to TV. The other buffer is drawable buffer.
 *  Calling this function will get the drawable layer handle.
 * PARAMETERS
 *  void
 * RETURNS
 *  Drawable layer handle.
 *****************************************************************************/
GDI_HANDLE mdi_tvout_get_active_layer(void)
{
#ifdef MDI_TVOUT_DRIVER_AVAIALBE

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 tvout_using_buf_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get tvout using buffer */
    tvout_using_buf_ptr = (PU8) get_current_tv_output_buffer();

    if (tvout_using_buf_ptr == g_mdi_tv_cntx.buf_1_ptr)
    {
        /* if tvout is using buffer 1, we can use buffer 2 to draw */
        g_mdi_tv_cntx.act_buf_id = MDI_TV_ACTIVE_BUF_2;
    }
    else if (tvout_using_buf_ptr == g_mdi_tv_cntx.buf_2_ptr)
    {
        /* if tvout is using buffer 2, we can use buffer 1 to draw */
        g_mdi_tv_cntx.act_buf_id = MDI_TV_ACTIVE_BUF_1;
    }
    else
    {
        /* tvout not using any buffer */
        /* this may happened when tv out using video play buffer of driver directly */
    }

    /* return drawable gdi_handle */
    if (g_mdi_tv_cntx.act_buf_id == MDI_TV_ACTIVE_BUF_1)
    {
        return g_mdi_tv_cntx.layer_1;
    }
    else
    {
        return g_mdi_tv_cntx.layer_2;
    }
#else /* MDI_TVOUT_DRIVER_AVAIALBE */ 
    return GDI_LAYER_EMPTY_HANDLE;
#endif /* MDI_TVOUT_DRIVER_AVAIALBE */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_tvout_get_and_dupe_active_layer
 * DESCRIPTION
 *  Get current active TV-out layer. We are using double layer for TV-Out.
 *  One layer is using by TV-out driver, it continously getting data from that
 *  buffer and draw to TV. The other buffer is drawable buffer.
 *  Calling this function will get the drawable layer handle.
 *  We will also dupe the buffer from tv using buffer to active layer.
 * PARAMETERS
 *  void
 * RETURNS
 *  Drawable layer handle.
 *****************************************************************************/
GDI_HANDLE mdi_tvout_get_and_dupe_active_layer(void)
{
#ifdef MDI_TVOUT_DRIVER_AVAIALBE

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 tvout_using_buf_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get tvout using buffer */
    tvout_using_buf_ptr = (PU8) get_current_tv_output_buffer();

    if (tvout_using_buf_ptr == g_mdi_tv_cntx.buf_1_ptr)
    {
        /* if tvout is using buffer 1, we can use buffer 2 to draw */
        g_mdi_tv_cntx.act_buf_id = MDI_TV_ACTIVE_BUF_2;
    }
    else if (tvout_using_buf_ptr == g_mdi_tv_cntx.buf_2_ptr)
    {
        /* if tvout is using buffer 2, we can use buffer 1 to draw */
        g_mdi_tv_cntx.act_buf_id = MDI_TV_ACTIVE_BUF_1;
    }
    else
    {
        /* tvout not using any buffer */
        /* this may happened when tv out using video play buffer of driver directly */
    }

    /* return drawable gdi_handle */
    if (g_mdi_tv_cntx.act_buf_id == MDI_TV_ACTIVE_BUF_1)
    {
    		memcpy((void*)g_mdi_tv_cntx.buf_1_ptr, (void*)g_mdi_tv_cntx.buf_2_ptr, g_mdi_tv_cntx.buf_size);
        return g_mdi_tv_cntx.layer_1;
    }
    else
    {
    		memcpy((void*)g_mdi_tv_cntx.buf_2_ptr, (void*)g_mdi_tv_cntx.buf_1_ptr, g_mdi_tv_cntx.buf_size);    	
        return g_mdi_tv_cntx.layer_2;
    }
#else /* MDI_TVOUT_DRIVER_AVAIALBE */ 
    return GDI_LAYER_EMPTY_HANDLE;
#endif /* MDI_TVOUT_DRIVER_AVAIALBE */ 
}



/*****************************************************************************
 * FUNCTION
 *  mdi_tvout_resize_buffer
 * DESCRIPTION
 *  Resize the TV-Out buffer.
 * PARAMETERS
 *  buffer_width        [IN]        Reszied buffer width
 *  buffer_height       [IN]        Reszied buffer height
 * RETURN VALUE
 *  MDI_RES_TV_SUCCEED      Succeed
 *****************************************************************************/
MDI_RESULT mdi_tvout_resize_buffer(S32 buffer_width, S32 buffer_height)
{
#ifdef MDI_TVOUT_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL is_size_change = FALSE;
    S32 tmp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* get drawable layer */
    if (g_mdi_tv_cntx.mode == TV_OUTPUT_MODE4)
    {
        tmp = buffer_width;
        buffer_height = buffer_width;
        buffer_width = tmp;
    }
    #ifdef MDI_TVOUT_MT6228_SERIES
    else if (g_mdi_tv_cntx.mode == TV_OUTPUT_MODE1)
    {
        if ( 0 != (buffer_width % 8))
            buffer_width += (8-(buffer_width % 8));
    }
    #endif

    if ((buffer_width != g_mdi_tv_cntx.buf_width) || (buffer_height != g_mdi_tv_cntx.buf_height))
    {
        gdi_layer_push_and_set_active(g_mdi_tv_cntx.layer_1);
        gdi_layer_resize(buffer_width, buffer_height);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();

//        g_mdi_tv_cntx.buf_width = buffer_width;
//        g_mdi_tv_cntx.buf_height = buffer_height;
//        g_mdi_tv_cntx.buf_size = g_mdi_tv_cntx.buf_width * g_mdi_tv_cntx.buf_height * MDI_TV_BUFFER_DEPTH;

//        is_size_change = TRUE;
//    }
//
//    if ((buffer_width != g_mdi_tv_cntx.buf_width) || (buffer_height != g_mdi_tv_cntx.buf_height))
//    {
        gdi_layer_push_and_set_active(g_mdi_tv_cntx.layer_2);
        gdi_layer_resize(buffer_width, buffer_height);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();

        g_mdi_tv_cntx.buf_width = buffer_width;
        g_mdi_tv_cntx.buf_height = buffer_height;
        g_mdi_tv_cntx.buf_size = g_mdi_tv_cntx.buf_width * g_mdi_tv_cntx.buf_height * MDI_TV_BUFFER_DEPTH;
        
        is_size_change = TRUE;
    }

    if (is_size_change)
    {
        set_tv_src_size(TV_OUT_OWNER_MMI, g_mdi_tv_cntx.buf_width, g_mdi_tv_cntx.buf_height);
    }

    return MDI_RES_TV_SUCCEED;

#else /* MDI_TVOUT_DRIVER_AVAIALBE */ 
    return MDI_RES_TV_SUCCEED;
#endif /* MDI_TVOUT_DRIVER_AVAIALBE */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_tvout_get_owner_draw_best_size
 * DESCRIPTION
 *  Get owner draw's best fit buffer size, will return max buffer size with same ratio
 * PARAMETERS
 *  buf_width       [OUT]       Best fit width
 *  buf_height      [OUT]       Best fit height
 * RETURN VALUE
 *  MDI_RES_TV_SUCCEED      Succeed
 *****************************************************************************/
MDI_RESULT mdi_tvout_get_owner_draw_best_size(S32 *buf_width, S32 *buf_height)
{
#ifdef MDI_TVOUT_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    *buf_width = g_mdi_tv_cntx.best_buf_width;
    *buf_height = g_mdi_tv_cntx.best_buf_height;
#endif /* MDI_TVOUT_DRIVER_AVAIALBE */ 

    return MDI_RES_TV_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_tvout_adjust_y_gamma
 * DESCRIPTION
 *  Adjust TV-Out y (gamma) value.
 * PARAMETERS
 *  y_gamma     [IN]        Gamma value
 * RETURN VALUE
 *  MDI_RES_TV_SUCCEED      Succeed
 *****************************************************************************/
MDI_RESULT mdi_tvout_adjust_y_gamma(mdi_tv_gamma_enum y_gamma)
{
#ifdef MDI_TVOUT_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_tvo_set_param_req_struct data;
    S32 tmp_gamma;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check valid range */
    /* use S32 to avoid compile warning */
    tmp_gamma = y_gamma;
    MMI_ASSERT((tmp_gamma >= (MDI_TV_OUTPUT_GAMMA_1)) && (tmp_gamma <= MDI_TV_OUTPUT_GAMMA_5));

    data.para = y_gamma;

    switch (y_gamma)
    {
        case MDI_TV_OUTPUT_GAMMA_1:
            data.para = TV_OUT_GAMMA1;
            break;

        case MDI_TV_OUTPUT_GAMMA_2:
            data.para = TV_OUT_GAMMA2;
            break;

        case MDI_TV_OUTPUT_GAMMA_3:
            data.para = TV_OUT_GAMMA3;
            break;

        case MDI_TV_OUTPUT_GAMMA_4:
            data.para = TV_OUT_GAMMA4;
            break;

        case MDI_TV_OUTPUT_GAMMA_5:
            data.para = TV_OUT_GAMMA5;
            break;
    }

    data.type = MED_TV_PARAM_Y_COMP;

    media_tvo_set_param(MOD_MMI, (void*)&data);

#endif /* MDI_TVOUT_DRIVER_AVAIALBE */ 

    return MDI_RES_TV_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_tvout_adjust_u
 * DESCRIPTION
 *  Adjust TV-Out u value.
 * PARAMETERS
 *  u       [IN]        U value
 * RETURN VALUE
 *  MDI_RES_TV_SUCCEED      Succeed
 *****************************************************************************/
MDI_RESULT mdi_tvout_adjust_u(U16 u)
{
#ifdef MDI_TVOUT_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_tvo_set_param_req_struct data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* valid range 0-255 */
    MMI_ASSERT(u < 256);

    data.para = u;
    data.type = MED_TV_PARAM_U_COMP;

    media_tvo_set_param(MOD_MMI, (void*)&data);

#endif /* MDI_TVOUT_DRIVER_AVAIALBE */ 

    return MDI_RES_TV_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_tvout_adjust_v
 * DESCRIPTION
 *  Adjust TV-Out v value.
 * PARAMETERS
 *  v       [IN]        V value
 * RETURN VALUE
 *  MDI_RES_TV_SUCCEED      Succeed
 *****************************************************************************/
MDI_RESULT mdi_tvout_adjust_v(U16 v)
{
#ifdef MDI_TVOUT_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_tvo_set_param_req_struct data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* valid range 0-255 */
    MMI_ASSERT(v < 256);

    data.para = v;
    data.type = MED_TV_PARAM_V_COMP;

    media_tvo_set_param(MOD_MMI, (void*)&data);

#endif /* MDI_TVOUT_DRIVER_AVAIALBE */ 

    return MDI_RES_TV_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_tvout_set_aud_path
 * DESCRIPTION
 *  Adjust set audio path
 * PARAMETERS
 *  aud_path     [IN]    audio path 
 * RETURN VALUE
 *  MDI_RES_TV_SUCCEED      Succeed
 *****************************************************************************/
MDI_RESULT mdi_tvout_set_aud_path(mdi_tv_aud_path_enum aud_path)
{
#ifdef MDI_TVOUT_DRIVER_AVAIALBE
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	media_tvo_set_param_req_struct data;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/	
    if (aud_path == MDI_TV_AUD_PATH_BOTH)
    {
	    data.para = MED_TV_PARAM_AUD_PATH_BOTH;
    }
    else if (aud_path == MDI_TV_AUD_PATH_TV)
    {
  	    data.para = MED_TV_PARAM_AUD_PATH_TV;
    }
    else
    {
        MMI_ASSERT(0);
    }

	data.type = MED_TV_PARAM_AUD_PATH;
	
	media_tvo_set_param(MOD_MMI, (void*)&data);

#endif /* MDI_TVOUT_DRIVER_AVAIALBE */

	return MDI_RES_TV_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_tvout_connect_ind_hdlr
 * DESCRIPTION
 *  Message handler for connect indications.
 * PARAMETERS
 *  msg_ptr     [IN]        Message data pointer
 * RETURNS
 *  void
 *****************************************************************************/
static void mdi_tvout_connect_ind_hdlr(void *msg_ptr)
{
#ifdef MDI_TVOUT_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_tvo_tv_connect_ind_struct *ind_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*  
        NOTICE!! due to speical poweron tv-out connection handling, 
        do not modify any g_mdi_tv_cntx data.
    */
    
    ind_p = (media_tvo_tv_connect_ind_struct*) msg_ptr;

    if (ind_p->result)
    {
        g_mdi_tv_cntx.event_callback(MDI_RES_TV_ENABLE);
    }
    else
    {
        g_mdi_tv_cntx.event_callback(MDI_RES_TV_DISABLE);
    }
#endif /* MDI_TVOUT_DRIVER_AVAIALBE */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_tvout_force_init
 * DESCRIPTION
 *  Force to init tvout hw, this is for enginner mode only. For those
 *  dont have hw cable detection.
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RES_TV_SUCCEED      Succeed
 *****************************************************************************/
MDI_RESULT mdi_tvout_force_init(void)
{
#ifdef MDI_TVOUT_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    media_tvo_force_init();

#endif /* MDI_TVOUT_DRIVER_AVAIALBE */ 
    return MDI_RES_TV_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_tvout_early_init_before_pwoeron
 * DESCRIPTION
 *  register callback function to be handler tv-out event before power on indication 
 * PARAMETERS
 *  tv_event_callback
 * RETURNS
 *  MDI_RES_TV_SUCCEED      Succeed
 *****************************************************************************/
MDI_RESULT mdi_tvout_early_init_before_pwoeron(mdi_tv_event_callback tv_event_callback)
{
#ifdef MDI_TVOUT_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 buffer_size;
    S32 PAL_size;
    S32 NTSC_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA,"[MDI_TVOUT] mdi_tvout_early_init()");

    /* callback function shall not be NULL */
    MMI_ASSERT(tv_event_callback != NULL);

    g_mdi_tv_cntx.event_callback = tv_event_callback;

    SetProtocolEventHandler(mdi_tvout_connect_ind_hdlr, MSG_ID_MEDIA_TVO_TV_CONNECT_IND);

    if (!g_mdi_tv_cntx.is_init)
    {
        /* init mode value */
        g_mdi_tv_cntx.mode = MDI_TV_MODE_NONE;

        /* GDI is defalt owner */
        g_mdi_tv_cntx.owner = MDI_TV_OWNER_GDI;

        g_mdi_tv_cntx.act_buf_id = MDI_TV_ACTIVE_BUF_NONE;

        /* allocate buffer */
        /* move from start to init, to avoid med memory fragmentation problem */
        NTSC_size = MDI_TV_NTSC_WIDTH * MDI_TV_NTSC_HEIGHT;
        PAL_size = MDI_TV_PAL_WIDTH * MDI_TV_PAL_HEIGHT;

        if (NTSC_size > PAL_size)
        {
            buffer_size = NTSC_size << 1;
        }
        else
        {
            buffer_size = PAL_size << 1;
        }
 
        g_mdi_tv_cntx.buf_1_ptr = &g_tvout_buf_1[0];
        g_mdi_tv_cntx.buf_2_ptr = &g_tvout_buf_2[0];

        g_mdi_tv_cntx.rotate_buf_1_ptr = NULL;
        g_mdi_tv_cntx.rotate_buf_2_ptr = NULL;

        g_mdi_tv_cntx.is_enable = FALSE;

        g_mdi_tv_cntx.layer_1 = GDI_LAYER_EMPTY_HANDLE;
        g_mdi_tv_cntx.layer_2 = GDI_LAYER_EMPTY_HANDLE;

        g_mdi_tv_cntx.is_init = TRUE;
    }



#endif /* MDI_TVOUT_DRIVER_AVAIALBE */ 
    return MDI_RES_TV_SUCCEED;
}



#endif /* __MMI_TVOUT__ */ 

