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
*  gui_spectrum.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   audio spectrum display APIs
*
* Author:
* -------
*  Siyin Liu (mbj06076)
*
*==============================================================================
*           HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*------------------------------------------------------------------------------
* $Log$
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

/*
 * This file contains internal UI component API, and is intended to be used by category screen module only. 
 * It's not recommended to be included in application code directly. 
 * For application developers, please include category screen header files instead (e.g., wgui_categories.h).
 */


#include "MMI_features.h"
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__

#include "gui_spectrum.h"
#include "gdi_include.h"
#include "gui.h"
#include "DebugInitDef.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"

extern gd_color_from_rgb_func gdi_act_color_from_rgb;
extern void gd_draw_ellipse16(
                U16 *dstPtr,
                int destWidth,
                int x,
                int y,
                int arcWidth,
                int arcHeight,
                int clipx1,
                int clipy1,
                int clipx2,
                int clipy2,
                gdi_color color,
                BOOL dotted);
extern void gd_fill_ellipse16(
                U16 *dstPtr,
                int destWidth,
                int x,
                int y,
                int arcWidth,
                int arcHeight,
                int clipx1,
                int clipy1,
                int clipx2,
                int clipy2,
                gdi_color color);

/* HARDCODE */
spectrum_struct *g_ui_spectrum_list[MAX_NUM_OF_SPECTRUMS] = {NULL, NULL, NULL, NULL, NULL};

U8 amplitude_val[16];
U8 top[16];

U16 g_ui_spectrum_timer_interval = 150; /* ms */

U8 g_ui_spectrum_active_count = 0;  /* how many spectrums atre active */

BOOL g_ui_spectrum_no_blt_after_clear = FALSE;  /* flag used for deciding whether the blt should be done after clear. */

U8 g_ui_spectrum_odd_even_identifier = 1;   /* In case of STYLE_CIRCLES, odd and even positioned vals are shown turn by turn. */

/* 1 means odd vals and 2 means even vals. */

/*****************************************************************************
 * FUNCTION
 *  mmi_audio_spectrum_init_display
 * DESCRIPTION
 *  
 * PARAMETERS
 *  spectrum        [?]     
 * RETURNS
 *  
 *****************************************************************************/
BOOL mmi_audio_spectrum_init_display(spectrum_struct *spectrum)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_HANDLE present_lcd;
    int index = 0;
    int row, col;
    BOOL found = FALSE;
    int ind ;
    S32 hrzntl_space_for_bars = 0;
    S16 no_of_blocks_in_block_style;
    S16 bar_width = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* proceed only if there is room for the spectrum */
    for (ind = 0; ind < MAX_NUM_OF_SPECTRUMS; ind++)
    {
        if(g_ui_spectrum_list[ind] == spectrum)
        {
            found = TRUE;
            index = ind;
            break;
        }
        else if(g_ui_spectrum_list[ind] == NULL && found == FALSE)
        {
            found = TRUE;
            index = ind;
        }
    }
    
    if(found) //(g_ui_spectrum_list[index] == spectrum || g_ui_spectrum_list[index] == NULL)
    {
        // check if the spectrum already exist in the list, if so, check if it's already active, then to stop it
        // this case will happen when a spectrum is re-inited without stopping it
        if (g_ui_spectrum_list[index] == spectrum)
        {
            if (spectrum->active)
            {
                if (--g_ui_spectrum_active_count == 0)
                {
                    gui_cancel_timer(mmi_audio_spectrum_display_timer);
                }
            }
        }
        spectrum->active = FALSE;

        gdi_lcd_get_active(&present_lcd);
        if (spectrum->target_lcd == GDI_LCD_SUB_LCD_HANDLE && present_lcd == GDI_LCD_MAIN_LCD_HANDLE)
        {
            UI_set_sub_LCD_graphics_context();  /* switch to sub lcd graphic context */
        }
        else if (spectrum->target_lcd == GDI_LCD_MAIN_LCD_HANDLE && present_lcd == GDI_LCD_SUB_LCD_HANDLE)
        {
            UI_set_main_LCD_graphics_context(); /* switch to sub lcd graphic context */
        }

    #ifdef __GDI_MEMORY_PROFILE_2__
        if (spectrum->target_layer)
        {
            gdi_layer_push_and_set_active(spectrum->target_layer);
        }
    #endif /* __GDI_MEMORY_PROFILE_2__ */ 

        gdi_layer_lock_frame_buffer();
        gdi_layer_push_clip();

        gdi_layer_set_clip(
            spectrum->start_x,
            spectrum->start_y,
            spectrum->start_x + spectrum->width,
            spectrum->start_y + spectrum->height);

        if (spectrum->style == STYLE_BARS || spectrum->style == STYLE_BLOCKS)
        {
            /* check for proper parameters for bar and block styles. */

            if (spectrum->width <
                (spectrum->number_of_bars * (MIN_BAR_WIDTH) +
                 (spectrum->number_of_bars + 1) * DIST_BETWEEN_BARS /* + SPACE_FOR_SCALE * 2 */ ))
            {
                MMI_ASSERT(0);
            }
            else if (spectrum->height < ( /* SPACE_FOR_SCALE + */ DIST_BETWEEN_BLOCKS + BLOCK_HEIGHT))
            {
                MMI_ASSERT(0);
            }

        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* 0 */ 

            /* find the bar width ... */
            hrzntl_space_for_bars = spectrum->width - DIST_BETWEEN_BARS * (spectrum->number_of_bars + 1);   /* 2 * (spectrum->number_of_bars + 1) 
                                                                                                               is sub. for leaving 2 pixel space between the various bars. */
            if (hrzntl_space_for_bars % spectrum->number_of_bars)
            {
                bar_width =
                    (hrzntl_space_for_bars -
                     (hrzntl_space_for_bars % spectrum->number_of_bars)) / spectrum->number_of_bars;
            }
            else
            {
                bar_width = hrzntl_space_for_bars / spectrum->number_of_bars;
            }

        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* 0 */ 
        }
        else    /* if(spectrum->style == STYLE_CIRCLES) */
        {
            unsigned char alpha, r, g, b;
            int center_x, center_y, radius_x, radius_y, ellipse_index;
            int radius_x_dec, radius_y_dec;

            radius_x_dec = radius_y_dec = 1;

            /* check for the minimum space required for making the Circles Style. */
            if ((spectrum->width - SPACE_TO_BE_LEFT_FOR_CIRCLES_STYLE) < (spectrum->number_of_bars * 2) ||
                (spectrum->height - SPACE_TO_BE_LEFT_FOR_CIRCLES_STYLE) < (spectrum->number_of_bars * 2))
            {
                MMI_ASSERT(0);
            }
            else    /* here the extra width and height are equally distributed among the circles.and then the separation */
            {       /* between each of the circles is calculated. */
                int tempx, tempy;

                tempx = (spectrum->width - SPACE_TO_BE_LEFT_FOR_CIRCLES_STYLE) / (spectrum->number_of_bars * 2);
                tempy = (spectrum->height - SPACE_TO_BE_LEFT_FOR_CIRCLES_STYLE) / (spectrum->number_of_bars * 2);
                radius_x_dec += (tempx - 1);
                radius_y_dec += (tempy - 1);
            }

            center_x = spectrum->start_x + spectrum->width / 2;
            center_y = spectrum->start_y + spectrum->height / 2;
            radius_x = (spectrum->width - SPACE_TO_BE_LEFT_FOR_CIRCLES_STYLE) / 2;
            radius_y = (spectrum->height - SPACE_TO_BE_LEFT_FOR_CIRCLES_STYLE) / 2;
            alpha = 50;
            r = 255;
            b = 0;
            g = 0;
            gdi_draw_solid_rect(
                spectrum->start_x,
                spectrum->start_y,
                spectrum->start_x + spectrum->width,
                spectrum->start_y + spectrum->height,
                GDI_COLOR_TRANSPARENT /* gdi_act_color_from_rgb(0xFF,0,0,0) */ );
            GDI_LOCK;
            for (ellipse_index = spectrum->number_of_bars; ellipse_index > 0; ellipse_index--)
            {
                gd_draw_ellipse16(
                    (U16*) gdi_act_layer->buf_ptr,
                    gdi_act_layer->width,
                    center_x,
                    center_y,
                    radius_x,
                    radius_y,
                    gdi_act_layer->clipx1,
                    gdi_act_layer->clipy1,
                    gdi_act_layer->clipx2,
                    gdi_act_layer->clipy2,
                    gdi_act_color_from_rgb(alpha, r, g, b),
                    0);

                radius_x -= radius_x_dec;
                radius_y -= radius_y_dec;
                r -= 10;
                b += 10;
                g += 5;
            }
            GDI_UNLOCK;

        }

        switch (spectrum->style)
        {
            case STYLE_BLOCKS:
            {
                int start_x, start_y, end_x, end_y;

                start_x = spectrum->start_x;
                start_y = spectrum->start_y;
                end_x = spectrum->start_x + spectrum->width - 1;
                end_y = start_y + spectrum->height - 1;
                gdi_draw_solid_rect(
                    start_x,
                    start_y,
                    end_x,
                    end_y,
                    GDI_COLOR_TRANSPARENT /* gdi_act_color_from_rgb(0x0,204,230,229) */ );
                /* calculate the maximum no. of blocks in each column/bar in spectrum */
                no_of_blocks_in_block_style = spectrum->height / (DIST_BETWEEN_BLOCKS + BLOCK_HEIGHT);

                /* draw the light colored rectangles */
                for (col = 0; col < spectrum->number_of_bars; col++)
                {
                    if (col == 0)
                    {
                        start_x =
                            spectrum->start_x + (hrzntl_space_for_bars % spectrum->number_of_bars) / 2 +
                            DIST_BETWEEN_BARS;
                        end_x = start_x + bar_width - 1;
                    }
                    else
                    {
                        start_x = start_x + bar_width + DIST_BETWEEN_BARS;
                        end_x = start_x + bar_width - 1;
                    }
                    for (row = 0; row < no_of_blocks_in_block_style; row++)
                    {
                        if (row == 0)
                        {
                            start_y =
                                spectrum->start_y + (spectrum->height - 1) - DIST_BETWEEN_BLOCKS - (BLOCK_HEIGHT -
                                                                                                    1);
                            end_y = start_y + BLOCK_HEIGHT - 1;
                        }
                        else
                        {
                            start_y = (start_y - 1) - DIST_BETWEEN_BLOCKS - (BLOCK_HEIGHT - 1);
                            end_y = start_y + BLOCK_HEIGHT - 1;
                        }
                        gdi_draw_solid_rect(
                            start_x,
                            start_y,
                            end_x,
                            end_y,
                            GDI_COLOR_TRANSPARENT /* SPECTRUM_BKGD_COLOR_BLOCK_STYLE */ );
                    }
                }
                break;
            }

            case STYLE_BARS:
            {
                int start_x, start_y, end_x, end_y;

                start_x = spectrum->start_x;
                start_y = spectrum->start_y;
                end_x = spectrum->start_x + spectrum->width - 1;
                end_y = start_y + spectrum->height - 1;
                gdi_draw_solid_rect(
                    start_x,
                    start_y,
                    end_x,
                    end_y,
                    GDI_COLOR_TRANSPARENT /* SPECTRUM_BKGD_COLOR_BAR_STYLE */ );
                break;
            }
        }

        gdi_layer_pop_clip();
        gdi_layer_unlock_frame_buffer();

        /* check on which lcd we have to show the spectrum */

        gdi_layer_blt_previous(
            spectrum->start_x,
            spectrum->start_y,
            spectrum->start_x + spectrum->width,
            spectrum->start_y + spectrum->height);

    #ifdef __GDI_MEMORY_PROFILE_2__
        if (spectrum->target_layer)
        {
            gdi_layer_pop_and_restore_active();
        }
    #endif /* __GDI_MEMORY_PROFILE_2__ */ 

        if (spectrum->target_lcd == GDI_LCD_SUB_LCD_HANDLE && present_lcd == GDI_LCD_MAIN_LCD_HANDLE)
        {
            UI_set_main_LCD_graphics_context();
        }
        else if (spectrum->target_lcd == GDI_LCD_MAIN_LCD_HANDLE && present_lcd == GDI_LCD_SUB_LCD_HANDLE)
        {
            UI_set_sub_LCD_graphics_context();
        }

        /* save the pointer in the global spectrum array. */
        g_ui_spectrum_list[index] = spectrum;

        return TRUE;    /* return TRUE since the assignment and init of the spectrum are done. */
    }
    return FALSE;   /* return FALSE since there is no room for the new display */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audio_spectrum_start_display
 * DESCRIPTION
 *  
 * PARAMETERS
 *  spectrum        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audio_spectrum_start_display(spectrum_struct *spectrum)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int spectrum_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get values from l1 audio layer *//* HARDCODE */
    for (spectrum_index = 0; spectrum_index < MAX_NUM_OF_SPECTRUMS; spectrum_index++)
    {
        if (spectrum == g_ui_spectrum_list[spectrum_index])
        {
            mdi_audio_get_spectrum(top, amplitude_val);

            mmi_audio_spectrum_redraw_display(spectrum, amplitude_val, top);

            if (g_ui_spectrum_active_count == 0)
            {
                gui_start_timer(g_ui_spectrum_timer_interval, mmi_audio_spectrum_display_timer);
            }
            if (!spectrum->active)
            {
                spectrum->active = TRUE;
                g_ui_spectrum_active_count++;
            }
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audio_spectrum_display_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audio_spectrum_display_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int spectrum_index = 0;
    spectrum_struct *spectrum;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get values from l1 audio layer */
    mdi_audio_get_spectrum(top, amplitude_val);

    g_ui_spectrum_odd_even_identifier = ((g_ui_spectrum_odd_even_identifier == 1) ? 2 : 1);     /* usefule only in case of STYLE_CIRCLES. */

    for (spectrum_index = 0; spectrum_index < MAX_NUM_OF_SPECTRUMS; spectrum_index++)
    {
        if (((spectrum = g_ui_spectrum_list[spectrum_index]) != NULL) && spectrum->active)
        {
            g_ui_spectrum_no_blt_after_clear = TRUE;    /* this indicates that their is no need to BLT after clearing the screen */
            mmi_audio_spectrum_clear_display(spectrum); /* blt should be done only after redrawing to make more efficient...this is only for the case in which after erase redraw is to be done. */
            mmi_audio_spectrum_redraw_display(spectrum, amplitude_val, top);
        }
    }

    gui_start_timer(g_ui_spectrum_timer_interval, mmi_audio_spectrum_display_timer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audio_spectrum_redraw_display
 * DESCRIPTION
 *  
 * PARAMETERS
 *  spectrum            [?]     
 *  amplitude_val       [?]     
 *  top                 [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audio_spectrum_redraw_display(spectrum_struct *spectrum, U8 *amplitude_val, U8 *top)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 hrzntl_space_for_bars, no_of_blocks_in_blocks_style, no_of_whole_blocks_in_a_bar;
    S16 bar_width;
    int index, col, color_variation_limit;
    float one_pixel_represents;
    GDI_HANDLE present_lcd;
    int start_x, start_y, end_x, end_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!spectrum->active)
    {
        return;
    }

    start_x = spectrum->start_x;
    start_y = spectrum->start_y;
    end_x = start_x + spectrum->width - 1;
    end_y = start_y + spectrum->height - 1;

    /* find the bar width ... */
    hrzntl_space_for_bars = spectrum->width - DIST_BETWEEN_BARS * (spectrum->number_of_bars + 1);       /* DIST_BETWEEN_BARS * (spectrum->number_of_bars + 1) 
                                                                                                           is sub. for leaving 2 pixel space between the various bars. */
    if (hrzntl_space_for_bars % spectrum->number_of_bars)
    {
        bar_width =
            (hrzntl_space_for_bars - (hrzntl_space_for_bars % spectrum->number_of_bars)) / spectrum->number_of_bars;
    }
    else
    {
        bar_width = hrzntl_space_for_bars / spectrum->number_of_bars;
    }

    gdi_lcd_get_active(&present_lcd);
    if (spectrum->target_lcd == GDI_LCD_SUB_LCD_HANDLE && present_lcd == GDI_LCD_MAIN_LCD_HANDLE)
    {
        UI_set_sub_LCD_graphics_context();  /* switch to sub lcd graphic context */
    }
    else if (spectrum->target_lcd == GDI_LCD_MAIN_LCD_HANDLE && present_lcd == GDI_LCD_SUB_LCD_HANDLE)
    {
        UI_set_main_LCD_graphics_context(); /* switch to sub lcd graphic context */
    }

#ifdef __GDI_MEMORY_PROFILE_2__
    if (spectrum->target_layer)
    {
        gdi_layer_push_and_set_active(spectrum->target_layer);
    }
#endif /* __GDI_MEMORY_PROFILE_2__ */ 

    /* draw the display spectrum... */
    gdi_layer_lock_frame_buffer();
    gdi_layer_push_clip();

    gdi_layer_set_clip(start_x, start_y, end_x, end_y);

    /* different handling for different styles */
    switch (spectrum->style)
    {
        case STYLE_BLOCKS:
        {
            /* calculate the maximum no. of blocks in each column/bar in spectrum */
            no_of_blocks_in_blocks_style = spectrum->height / (DIST_BETWEEN_BLOCKS + BLOCK_HEIGHT);

            one_pixel_represents = (float)256 / (float)(no_of_blocks_in_blocks_style * BLOCK_HEIGHT);

            for (col = 0; col < spectrum->number_of_bars; col++)
            {
                S32 required_height_of_a_bar, required_height_of_top, difference;

                if (col == 0)
                {
                    start_x =
                        spectrum->start_x + (hrzntl_space_for_bars % spectrum->number_of_bars) / 2 + DIST_BETWEEN_BARS;
                    end_x = start_x + bar_width - 1;
                }
                else
                {
                    start_x = start_x + bar_width + DIST_BETWEEN_BARS;
                    end_x = start_x + bar_width - 1;
                }

                /* draw the bar... */
                required_height_of_a_bar = (int)(amplitude_val[col] / one_pixel_represents);

                /* small calculation for the top indicator and the difference between bar height and top indicator height. */
                required_height_of_top = (int)(top[col] / one_pixel_represents);
                difference = required_height_of_top - required_height_of_a_bar;
                /* calculation ends here. */

                /* calculate the maximum color variation value for the given height */
                color_variation_limit = amplitude_val[col];

                /* initialize end_y: which will be the same for all the cases. */
                end_y = spectrum->start_y + spectrum->height - 1;

                no_of_whole_blocks_in_a_bar = required_height_of_a_bar / BLOCK_HEIGHT;
                if (no_of_whole_blocks_in_a_bar)
                {
                    end_y -= DIST_BETWEEN_BLOCKS;
                    for (index = 0; index < no_of_whole_blocks_in_a_bar; index++)
                    {
                        start_y = end_y - (BLOCK_HEIGHT - 1);
                        gdi_draw_solid_rect(
                            start_x,
                            start_y,
                            end_x,
                            end_y,
                            gdi_act_color_from_rgb(0xFF, SPECTRUM_BLOCK_RED_COMPONENT, color_variation_limit, SPECTRUM_BLOCK_BLUE_COMPONENT));
                        end_y = (start_y - 1) - DIST_BETWEEN_BLOCKS;
                        color_variation_limit -= (int)(BLOCK_HEIGHT * one_pixel_represents);
                    }

                    end_y += DIST_BETWEEN_BLOCKS;

                }

                if (required_height_of_a_bar % BLOCK_HEIGHT)
                {
                    end_y -= DIST_BETWEEN_BLOCKS;
                    start_y = end_y - ((required_height_of_a_bar % BLOCK_HEIGHT) - 1);
                    gdi_draw_solid_rect(
                        start_x,
                        start_y,
                        end_x,
                        end_y,
                        gdi_act_color_from_rgb(0xFF, SPECTRUM_BLOCK_RED_COMPONENT, color_variation_limit, SPECTRUM_BLOCK_BLUE_COMPONENT));
                    end_y = start_y - 1;
                    /* drawing the bar is complete */

                    /* draw the top indicator */

                    //now the start_y is to be moved to the top indicator position.
                    //first check that difference is morethan or equal to the unfilled block height...
                    //if it is then simply subtract the unfilled height from start_y and difference
                    //and bring the start_y to the top of block.
                    if (difference)
                    {
                        if (difference >= (BLOCK_HEIGHT - (required_height_of_a_bar % BLOCK_HEIGHT)))
                        {
                            end_y -= (BLOCK_HEIGHT - (required_height_of_a_bar % BLOCK_HEIGHT));
                            difference -= (BLOCK_HEIGHT - (required_height_of_a_bar % BLOCK_HEIGHT));
                        }
                        else
                        {   /* else simply subtract the difference from start_y and nullify the difference. */
                            end_y -= difference;
                            difference = 0;
                        }
                    }
                }

                while (difference)  /* no if still the difference is left then subtarct it (by comparing it's value with BLOCK_HEIGHT from start_x */
                {
                    if (difference > BLOCK_HEIGHT)
                    {
                        end_y -= (DIST_BETWEEN_BLOCKS + BLOCK_HEIGHT);
                        difference -= BLOCK_HEIGHT;
                    }
                    else
                    {
                        end_y -= (DIST_BETWEEN_BLOCKS + difference);
                        difference = 0;
                    }
                }
                end_y++;
                start_y = end_y;
                /* draw the top indicator. */
                gdi_draw_solid_rect(start_x, start_y, end_x, end_y, SPECTRUM_TOP_INDICATOR_COLOR_BLOCK_STYLE);
            }
            break;
        }

        case STYLE_BARS:
        {
            int start_x = 0, start_y, end_x, end_y;

            /* calculate the maximum no. of blocks in each column/bar in spectrum */
            no_of_blocks_in_blocks_style = spectrum->height / BLOCK_HEIGHT;

            one_pixel_represents = (float)256 / (float)(no_of_blocks_in_blocks_style * BLOCK_HEIGHT);

            for (col = 0; col < spectrum->number_of_bars; col++)
            {
                S32 required_height_of_a_bar, required_height_of_top, difference;

                if (col == 0)
                {
                    start_x =
                        spectrum->start_x + (hrzntl_space_for_bars % spectrum->number_of_bars) / 2 + DIST_BETWEEN_BARS;
                    end_x = start_x + bar_width - 1;
                }
                else
                {
                    start_x = start_x + bar_width + DIST_BETWEEN_BARS;
                    end_x = start_x + bar_width - 1;
                }

                /* draw the bar... */
                required_height_of_a_bar = (int)(amplitude_val[col] / one_pixel_represents);

                /* small calculation for the top indicator and the difference between bar height and top indicator height. */
                required_height_of_top = (int)(top[col] / one_pixel_represents);
                difference = required_height_of_top - required_height_of_a_bar;
                /* calculation ends here. */

                /* calculate the maximum color variation value for the given height */
                color_variation_limit = amplitude_val[col];

                /* initialize end_y: which will be the same for all the cases. */
                end_y = spectrum->start_y + spectrum->height - 1;

                no_of_whole_blocks_in_a_bar = required_height_of_a_bar / BLOCK_HEIGHT;
                if (no_of_whole_blocks_in_a_bar)
                {
                    for (index = 0; index < no_of_whole_blocks_in_a_bar; index++)
                    {
                        start_y = end_y - (BLOCK_HEIGHT - 1);
                        gdi_draw_solid_rect(
                            start_x,
                            start_y,
                            end_x,
                            end_y,
                            gdi_act_color_from_rgb(0xFF, SPECTRUM_BLOCK_RED_COMPONENT, color_variation_limit, SPECTRUM_BLOCK_BLUE_COMPONENT));
                        end_y = start_y - 1;
                        color_variation_limit -= (int)(BLOCK_HEIGHT * one_pixel_represents);
                    }

                }

                if (required_height_of_a_bar % BLOCK_HEIGHT)
                {
                    start_y = end_y - ((required_height_of_a_bar % BLOCK_HEIGHT) - 1);
                    gdi_draw_solid_rect(
                        start_x,
                        start_y,
                        end_x,
                        end_y,
                        gdi_act_color_from_rgb(0xFF, SPECTRUM_BLOCK_RED_COMPONENT, color_variation_limit, SPECTRUM_BLOCK_BLUE_COMPONENT));
                    end_y = start_y - 1;
                }
                if (difference)
                {
                    end_y -= (difference - 1);
                }
                start_y = end_y;
                /* draw the top indicator. */
                if(start_y != spectrum->start_y + spectrum->height - 1 )
                {
                    gdi_draw_solid_rect(start_x, start_y, end_x, end_y, SPECTRUM_TOP_INDICATOR_COLOR_BAR_STYLE);
                }

            }
            break;
        }
        case STYLE_CIRCLES:
        {
            {
                unsigned char alpha, color_index, color_array[NUM_OF_COLOR_COMPONENTS];
                int center_x, center_y, radius_x, radius_y, ellipse_index, radius_x_dec, radius_y_dec, tempx, tempy;
                BOOL toggle_fill_draw = FALSE;

                color_index = 1;
                center_x = spectrum->start_x + (spectrum->width) / 2;
                center_y = spectrum->start_y + (spectrum->height) / 2;
                radius_x = (spectrum->width - SPACE_TO_BE_LEFT_FOR_CIRCLES_STYLE) / 2;
                radius_y = (spectrum->height - SPACE_TO_BE_LEFT_FOR_CIRCLES_STYLE) / 2;
                radius_x_dec = radius_y_dec = 1;
                tempx = (spectrum->width - SPACE_TO_BE_LEFT_FOR_CIRCLES_STYLE) / (spectrum->number_of_bars * 2);
                tempy = (spectrum->height - SPACE_TO_BE_LEFT_FOR_CIRCLES_STYLE) / (spectrum->number_of_bars * 2);
                radius_x_dec += (tempx - 1);
                radius_y_dec += (tempy - 1);
                alpha = 50;
                color_array[0] = 45;    /* red component */
                color_array[1] = 255;   /* blue component */

                GDI_LOCK;

                /* this if statement is for showing the odd positioned values once and then the even posotioned values */

                for (ellipse_index = spectrum->number_of_bars; ellipse_index >= 1; ellipse_index--)
                {
                    /* the 2 components have values 45 and 255 and the 3rd one has the val from the amplitude_val array. */
                    color_array[(color_index + 1) % NUM_OF_COLOR_COMPONENTS] =
                        amplitude_val[(ellipse_index * 2) - g_ui_spectrum_odd_even_identifier];

                    if (color_array[(color_index + 1) % 3])
                    {
                        if (toggle_fill_draw)
                        {
                            /* draw the ellipse */
                            gd_draw_ellipse16(
                                (U16*) gdi_act_layer->buf_ptr,
                                gdi_act_layer->width,
                                center_x,
                                center_y,
                                radius_x,
                                radius_y,
                                gdi_act_layer->clipx1,
                                gdi_act_layer->clipy1,
                                gdi_act_layer->clipx2,
                                gdi_act_layer->clipy2,
                                gdi_act_color_from_rgb(alpha, color_array[0], color_array[1], color_array[2]),
                                0);
                            toggle_fill_draw = FALSE;
                        }
                        else
                        {
                            /* fill the ellipse */
                            gd_fill_ellipse16(
                                (U16*) gdi_act_layer->buf_ptr,
                                gdi_act_layer->width,
                                center_x,
                                center_y,
                                radius_x,
                                radius_y,
                                gdi_act_layer->clipx1,
                                gdi_act_layer->clipy1,
                                gdi_act_layer->clipx2,
                                gdi_act_layer->clipy2,
                                gdi_act_color_from_rgb(alpha, color_array[0], color_array[1], color_array[2]));
                            toggle_fill_draw = TRUE;
                        }
                    }

                    /* shuffle the colors for better visual affect; */
                    color_array[(color_index + 1) % NUM_OF_COLOR_COMPONENTS] = color_array[color_index];
                    color_array[color_index] =
                        color_array[(NUM_OF_COLOR_COMPONENTS - 1 + color_index) % NUM_OF_COLOR_COMPONENTS];
                    color_index = (color_index + 1) % NUM_OF_COLOR_COMPONENTS;

                    radius_x -= radius_x_dec;
                    radius_y -= radius_y_dec;
                }
                GDI_UNLOCK;
            }
            break;
        }
    }

    gdi_layer_pop_clip();
    gdi_layer_unlock_frame_buffer();

    /* check on which lcd we have to show the spectrum */
    gdi_layer_blt_previous(
        spectrum->start_x,
        spectrum->start_y,
        spectrum->start_x + spectrum->width - 1,
        spectrum->start_y + spectrum->height - 1);

#ifdef __GDI_MEMORY_PROFILE_2__
    if (spectrum->target_layer)
    {
        gdi_layer_pop_and_restore_active();
    }
#endif /* __GDI_MEMORY_PROFILE_2__ */ 

    if (spectrum->target_lcd == GDI_LCD_SUB_LCD_HANDLE && present_lcd == GDI_LCD_MAIN_LCD_HANDLE)
    {
        UI_set_main_LCD_graphics_context();
    }
    else if (spectrum->target_lcd == GDI_LCD_MAIN_LCD_HANDLE && present_lcd == GDI_LCD_SUB_LCD_HANDLE)
    {
        UI_set_sub_LCD_graphics_context();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audio_spectrum_clear_display
 * DESCRIPTION
 *  
 * PARAMETERS
 *  spectrum        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audio_spectrum_clear_display(spectrum_struct *spectrum)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_HANDLE present_lcd;
    int row, col;
    int start_x, start_y, end_x, end_y;
    int x1 = 0, y1 = 0, x2, y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    start_x = spectrum->start_x;
    start_y = spectrum->start_y;
    end_x = start_x + spectrum->width - 1;
    end_y = start_y + spectrum->height - 1;

    gdi_lcd_get_active(&present_lcd);
    if (spectrum->target_lcd == GDI_LCD_SUB_LCD_HANDLE && present_lcd == GDI_LCD_MAIN_LCD_HANDLE)
    {
        UI_set_sub_LCD_graphics_context();  /* switch to sub lcd graphic context */
    }
    else if (spectrum->target_lcd == GDI_LCD_MAIN_LCD_HANDLE && present_lcd == GDI_LCD_SUB_LCD_HANDLE)
    {
        UI_set_main_LCD_graphics_context(); /* switch to sub lcd graphic context */
    }

#ifdef __GDI_MEMORY_PROFILE_2__
    if (spectrum->target_layer)
    {
        gdi_layer_push_and_set_active(spectrum->target_layer);
    }
#endif /* __GDI_MEMORY_PROFILE_2__ */ 

    gdi_layer_lock_frame_buffer();
    gdi_layer_push_clip();

    gdi_layer_set_clip(start_x, start_y, end_x, end_y);

    switch (spectrum->style)
    {
        case STYLE_BLOCKS:
        {
            S32 hrzntl_space_for_bars, bar_width, no_of_blocks_in_block_style;

            gdi_draw_solid_rect(
                start_x,
                start_y,
                end_x,
                end_y,
                GDI_COLOR_TRANSPARENT /* gdi_act_color_from_rgb(0x0,204,230,229) */ );

            /* find the bar width ... */
            hrzntl_space_for_bars = spectrum->width - DIST_BETWEEN_BARS * (spectrum->number_of_bars + 1);       /* DIST_BETWEEN_BARS * (spectrum->number_of_bars + 1) \
                                                                                                                   is sub. for leaving 2 pixel space between the various bars. */
            if (hrzntl_space_for_bars % spectrum->number_of_bars)
            {
                bar_width =
                    (hrzntl_space_for_bars -
                     (hrzntl_space_for_bars % spectrum->number_of_bars)) / spectrum->number_of_bars;
            }
            else
            {
                bar_width = hrzntl_space_for_bars / spectrum->number_of_bars;
            }

            /* calculate the maximum no. of blocks in each column/bar in spectrum */
            no_of_blocks_in_block_style = spectrum->height / (DIST_BETWEEN_BLOCKS + BLOCK_HEIGHT);

            /* draw the light colored rectangles */
            for (col = 0; col < spectrum->number_of_bars; col++)
            {
                if (col == 0)
                {
                    x1 = spectrum->start_x + (hrzntl_space_for_bars % spectrum->number_of_bars) / 2 + DIST_BETWEEN_BARS;
                }
                else
                {
                    x1 = x1 + bar_width + DIST_BETWEEN_BARS;
                }
                x2 = x1 + (bar_width - 1);

                for (row = 0; row < no_of_blocks_in_block_style; row++)
                {
                    if (row == 0)
                    {
                        y1 = (spectrum->start_y + spectrum->height - 1) - DIST_BETWEEN_BLOCKS - (BLOCK_HEIGHT - 1);
                    }
                    else
                    {
                        y1 = (y1 - 1) - DIST_BETWEEN_BLOCKS - (BLOCK_HEIGHT - 1);
                    }

                    y2 = y1 + (BLOCK_HEIGHT - 1);
                    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT /* SPECTRUM_BKGD_COLOR_BLOCK_STYLE */ );
                }
            }
            break;
        }

        case STYLE_BARS:
        {
            gdi_draw_solid_rect(
                start_x,
                start_y,
                end_x,
                end_y,
                GDI_COLOR_TRANSPARENT /* SPECTRUM_BKGD_COLOR_BAR_STYLE */ );

            break;
        }

        case STYLE_CIRCLES:
        {
            gdi_draw_solid_rect(
                start_x,
                start_y,
                end_x,
                end_y,
                GDI_COLOR_TRANSPARENT /* SPECTRUM_BKGD_COLOR_BAR_STYLE */ );
            break;
        }
    }

    gdi_layer_pop_clip();
    gdi_layer_unlock_frame_buffer();

    if (!g_ui_spectrum_no_blt_after_clear)
    {
        gdi_layer_blt_previous(start_x, start_y, end_x, end_y);
    }
    else
    {
        g_ui_spectrum_no_blt_after_clear = FALSE;
    }

#ifdef __GDI_MEMORY_PROFILE_2__
    if (spectrum->target_layer)
    {
        gdi_layer_pop_and_restore_active();
    }
#endif /* __GDI_MEMORY_PROFILE_2__ */ 

    if (spectrum->target_lcd == GDI_LCD_SUB_LCD_HANDLE && present_lcd == GDI_LCD_MAIN_LCD_HANDLE)
    {
        UI_set_main_LCD_graphics_context();
    }
    else if (spectrum->target_lcd == GDI_LCD_MAIN_LCD_HANDLE && present_lcd == GDI_LCD_SUB_LCD_HANDLE)
    {
        UI_set_sub_LCD_graphics_context();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audio_spectrum_stop_display
 * DESCRIPTION
 *  
 * PARAMETERS
 *  spectrum        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audio_spectrum_stop_display(spectrum_struct *spectrum)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < MAX_NUM_OF_SPECTRUMS; index++)
    {
        if (spectrum == g_ui_spectrum_list[index])
        {
            /* stop this particular spectrum if it's active */
            if (spectrum->active)
            {
                mmi_audio_spectrum_clear_display(spectrum);
                spectrum->active = FALSE;
                g_ui_spectrum_active_count--;
            }
            g_ui_spectrum_list[index] = NULL;   /* added by PANKAJ for removal of Black Patch problem on Idle Screen...in case the song is being played and the user reaches the IDLE screen. */
            break;
        }
    }
    if (g_ui_spectrum_active_count == 0)
    {
        gui_cancel_timer(mmi_audio_spectrum_display_timer);
    }
}

#endif /* __MMI_AUDIO_SPECTRUM_DISPLAY__ */ 

