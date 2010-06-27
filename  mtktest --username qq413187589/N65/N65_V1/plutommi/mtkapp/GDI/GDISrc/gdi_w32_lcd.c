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
 *  gdi_w32_lcd.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GDI Image Hardware Gif related.
 *
 * Author:
 * -------
 *  JF (MT00481)
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * $Log$
 *
 * Oct 16 2007 mtk00481
 * [MAUI_00539202] Obigo Q05A_Browser can not show this image file
 * 
 *
 * Oct 5 2007 mtk00481
 * [MAUI_00548910] [MMI][GDI] remove compile error/warning
 * 
 *
 * Sep 20 2007 mtk00481
 * [MAUI_00548910] [MMI][GDI] remove compile error/warning
 * 
 *
 * Apr 29 2007 mtk00481
 * [MAUI_00387494] [Need Patch] to solve mono SUBLCD can't bootup in MoDIS
 * 
 *
 * Aug 23 2006 mtk00481
 * [MAUI_00323969] [MMI][BugFix] MAUI Dragonfly_demo W06.34 Jataayu gdi_w32_lcd.c link error
 * 
 *
 * Jul 18 2006 mtk00548
 * [MAUI_00211232] [MoDIS][LCD] Modify MoDIS LCD interface for supporting of 32bit color depths
 * 
 *
 * Jul 17 2006 mtk00481
 * [MAUI_00211263] [BugFix][GDI] to support sw png
 * 
 *
 * Jul 17 2006 mtk00548
 * [MAUI_00211232] [MoDIS][LCD] Modify MoDIS LCD interface for supporting of 32bit color depths
 * 
 *
 * May 2 2006 mtk00548
 * [MAUI_00188704] Camera- In horizontal mode, OSD indicator is not in the center of screen
 * 
 *
 * Mar 29 2006 mtk00548
 * [MAUI_00183308] Remove Modis link error
 * 
 *
 * Mar 16 2006 mtk00481
 * [MAUI_00219358] view pic abnormal
 * 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#include "gdi_internal.h"
#include "gd_primitive.h"

static U32 gdi_w32_main_lcd_buffer[GDI_LCD_WIDTH * GDI_LCD_HEIGHT];

#ifdef __MMI_SUBLCD__
static U32 gdi_w32_sub_lcd_buffer[GDI_SUBLCD_WIDTH * GDI_SUBLCD_HEIGHT];
#endif 

U32 *gdi_w32_lcd_buffer[GDI_LCD_SUM];
lcd_layer_struct gdi_w32_layer_data[GDI_LCD_SUM][GDI_LAYER_HW_LAYER_COUNT];
gdi_layer_struct *gdi_w32_layer[GDI_LCD_SUM][GDI_LAYER_HW_LAYER_COUNT];
gdi_color gdi_w32_palette[2][256];
gdi_layer_struct gdi_w32_output_layer;

/* create this table, so we can use for loop to prcess each layer */
static U32 layer_flag_table[] = 
{
    LCD_LAYER0_ENABLE,
    LCD_LAYER1_ENABLE,
    LCD_LAYER2_ENABLE,
    LCD_LAYER3_ENABLE,
    LCD_LAYER4_ENABLE,
    LCD_LAYER5_ENABLE
};

#define BGR(R,G,B)      (((R)<<16)|((G)<<8)|(B))


/*****************************************************************************
 * FUNCTION
 *  lcd_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  lcd_id                  [IN]        
 *  background_color        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void lcd_init(kal_uint8 lcd_id, kal_uint16 background_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    U8 R, G, B;
    U32 c;
    int size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    lcd_id--;
    switch (lcd_id)
    {
        case 0:
            R = DRV_HW_TO_RGB_R(background_color);
            G = DRV_HW_TO_RGB_G(background_color);
            B = DRV_HW_TO_RGB_B(background_color);
            c = BGR(R, G, B);
            size = GDI_LCD_WIDTH * GDI_LCD_HEIGHT;
            gdi_w32_lcd_buffer[lcd_id] = gdi_w32_main_lcd_buffer;
            break;
    #ifdef __MMI_SUBLCD__
        case 1:
            R = HW_FORMAT_TO_SUBMMI_R(background_color);
            G = HW_FORMAT_TO_SUBMMI_G(background_color);
            B = HW_FORMAT_TO_SUBMMI_B(background_color);
            c = BGR(R, G, B);
            size = GDI_SUBLCD_WIDTH * GDI_SUBLCD_HEIGHT;
            gdi_w32_lcd_buffer[lcd_id] = gdi_w32_sub_lcd_buffer;
            break;
    #endif /* __MMI_SUBLCD__ */ 
        default:
            GDI_ASSERT(0);
    }

    for (i = 0; i < size; i++)
    {
        gdi_w32_lcd_buffer[lcd_id][i] = c;
    }

}


/*****************************************************************************
 * FUNCTION
 *  config_lcd_layer_window
 * DESCRIPTION
 *  
 * PARAMETERS
 *  lcd_layer       [IN]        
 *  layer_data      [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_bool config_lcd_layer_window(kal_uint8 lcd_layer, lcd_layer_struct *layer_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int layer_id = (layer_data - gdi_layer_info);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_w32_layer_data[GDI_LCD->act_handle - 1][lcd_layer] = *layer_data;
    gdi_w32_layer[GDI_LCD->act_handle - 1][lcd_layer] = &GDI_LAYERS[layer_id];
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  set_lcd_color_palette
 * DESCRIPTION
 *  
 * PARAMETERS
 *  color_palette_select        [IN]        
 *  color_palette_addr_ptr      [?]         
 *  start_index                 [IN]        
 *  number_of_color             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void set_lcd_color_palette(
        kal_uint8 color_palette_select,
        kal_uint32 *color_palette_addr_ptr,
        kal_uint8 start_index,
        kal_uint8 number_of_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    gdi_color *c = (gdi_color*) color_palette_addr_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < number_of_color; i++)
    {
        gdi_w32_palette[color_palette_select][start_index + i] = *c;
        c++;
    }
}

/*****************************************************************************
 * FUNCTION
 *  config_lcd_hw_layer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hw_layer            [IN]        
 *  layer_offset_x      [IN]        
 *  layer_offset_y      [IN]        
 *  layer_width         [IN]        
 *  layer_height        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void config_lcd_hw_layer(
        kal_uint32 hw_layer,
        kal_uint16 layer_offset_x,
        kal_uint16 layer_offset_y,
        kal_uint16 layer_width,
        kal_uint16 layer_height)
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
 *  lcd_stop_hw_update
 * DESCRIPTION
 *  
 * PARAMETERS
 *  lcd_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void lcd_stop_hw_update(kal_uint8 lcd_id)
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
 *  lcd_fb_update_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  lcd                 [IN]        
 *  DEST                [?]         
 *  width               [IN]        
 *  height              [IN]        
 *  dest_start_x        [IN]        
 *  dest_start_y        [IN]        
 *  dest_end_x          [IN]        
 *  dest_end_y          [IN]        
 *  dest_roi_x          [IN]        
 *  dest_roi_y          [IN]        
 *  update_layers       [IN]        
 *  is_up_to_down       [IN]        
 *  is_to_layer         [IN]        
 *  background          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void lcd_fb_update_internal(
        int lcd,
        U32 *DEST,
        U32 width,
        U32 height,
        /* destination buffer */ int dest_start_x,
        int dest_start_y,
        int dest_end_x,
        int dest_end_y,
        /* destination output window */ int dest_roi_x,
        int dest_roi_y,
        /* universal  coordinate */ U32 update_layers,
        /* which layers want to be update ? */ int is_up_to_down,
        int is_to_layer,
        U32 background)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int dx, dy;     /* destination position */
    int adx, ady;   /* destination position in universal coordinate */
    U32 layer;
    int lx, ly;     /* layer position */
    lcd_layer_struct *layer_info;
    U32 *dest;
    U32 bg_a, bg_r, bg_g, bg_b;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef GDI_USING_LAYER_BACKGROUND
    gd_color_to_rgb_24(&bg_a, &bg_r, &bg_g, &bg_b, background);
#else 
    bg_a = bg_r = bg_g = bg_b = 0x00ff;
#endif 

    if (dest_start_x < 0)
    {
        dest_start_x = 0;
    }
    if (dest_start_y < 0)
    {
        dest_start_y = 0;
    }

    // shift buffer address to ROI. idea from Glory
    {
        if (dest_roi_x < width)
        {
            dest_start_x = dest_roi_x;
            dest_start_y = dest_roi_y;

            dest_end_x = dest_start_x + dest_end_x;
            dest_end_y = dest_start_y + dest_end_y;            
        }
    }
    
    if (lcd == 0)
    {
        if (dest_end_x >= GDI_LCD_WIDTH)
        {
            dest_end_x = GDI_LCD_WIDTH - 1;
        }
        if (dest_end_y >= GDI_LCD_HEIGHT)
        {
            dest_end_y = GDI_LCD_HEIGHT - 1;
        }
    }
#ifdef __MMI_SUBLCD__
    else if (lcd == 1)
    {
        if (dest_end_x >= GDI_SUBLCD_WIDTH)
        {
            dest_end_x = GDI_SUBLCD_WIDTH - 1;
        }
        if (dest_end_y >= GDI_SUBLCD_HEIGHT)
        {
            dest_end_y = GDI_SUBLCD_HEIGHT - 1;
        }
    }
#endif /* __MMI_SUBLCD__ */ 

    gdi_layer_push_and_set_active((gdi_handle) gdi_act_layer);

    for (dy = dest_start_y, ady = dest_roi_y; dy <= dest_end_y; dy++, ady++)
    {
        if (is_up_to_down)
        {
            dest = DEST + (dest_start_x + dy * width);
        }
        else
        {
            dest = DEST + (dest_start_x + (height - dy - 1) * width);
        }

        for (dx = dest_start_x, adx = dest_roi_x; dx <= dest_end_x; dx++, adx++, dest++)
        {
            U32 OA, OR, OG, OB;

            /* the initial color is white ! */
            OA = bg_a;
            OR = bg_r;
            OG = bg_g;
            OB = bg_b;
            for (layer = 0; layer < GDI_LAYER_HW_LAYER_COUNT; layer++)
                if (update_layers & layer_flag_table[layer])
                {
                    gdi_color lc;
                    U32 LA, LR, LG, LB;

                    gdi_act_layer = gdi_w32_layer[lcd][layer];
                    layer_info = &gdi_w32_layer_data[lcd][layer];
                    /* To Support COLOR_FORMAT_32*/
                    gdi_act_color_to_rgb = gd_color_to_rgb[gdi_act_layer->cf];

                    /* transform to layer's local coordinate */
                    lx = adx - layer_info->x_offset;
                    ly = ady - layer_info->y_offset;

                #ifdef GDI_USING_LAYER_ROTATE
                    switch (layer_info->rotate_value)
                    {
                        case LCD_LAYER_ROTATE_270:
                        {
                            int temp;

                            temp = lx;
                            lx = ly;
                            /* ly = GDI_LCD_WIDTH-1-temp; */
                            ly = layer_info->row_number - 1 - temp;
                        }
                            break;
                    }
                #endif /* GDI_USING_LAYER_ROTATE */ 

                    /* test if in region */
                    if (lx < 0 || lx >= layer_info->column_number || ly < 0 || ly >= layer_info->row_number)
                    {
                        continue;
                    }

                    lc = gd_get_pixel[gdi_act_layer->cf] (lx, ly);

                    if (gdi_act_layer->vcf == GDI_COLOR_FORMAT_8)       /* if is index color */
                    {
                        lc &= 0x00ff;
                        GDI_PALETTE_COLOR_TO_RGB(
                            &LA,
                            &LR,
                            &LG,
                            &LB,
                            gdi_w32_palette[layer_info->color_palette_select][lc]);
                    }
                    else
                    {
                        gdi_act_color_to_rgb(&LA, &LR, &LG, &LB, lc);
                    }

                    /* is source key color */
                    if (layer_info->source_key_enable && layer_info->source_key == lc)
                    {
                        continue;
                    }

                    if (layer_info->opacity_enable || layer_info->source_color_format == GDI_HW_COLOR_FORMAT_32)
                    {
                        unsigned char op_value;     /* opacity value */
                        unsigned char op_value_c;   /* opacity value complement */

                        /* calc opacity ratio */
                        if (layer_info->source_color_format == GDI_HW_COLOR_FORMAT_32)
                        {
                            /* To Support COLOR_FORMAT_32*/
                            op_value_c = (LA & 0x0ff);
                            op_value = (~LA) & 0x0ff;

                        }
                        else
                        {

                        #ifdef LCD_MAX_OPACITY
                            op_value_c = layer_info->opacity_value * 255 / LCD_MAX_OPACITY;
                        #else 
                            op_value_c = layer_info->opacity_value << 3;
                        #endif 
                            op_value = ~op_value_c;
                        }

                        if (op_value != 0)
                        {
                            OR = (OR * op_value + LR * op_value_c) >> 8;
                            OG = (OG * op_value + LG * op_value_c) >> 8;
                            OB = (OB * op_value + LB * op_value_c) >> 8;
                        }
                        else
                        {

                            OR = LR;
                            OG = LG;
                            OB = LB;
                        }
                    }
                    else
                    {
                        OR = LR;
                        OG = LG;
                        OB = LB;
                    }
                }
            if (!is_to_layer)
            {
                *dest = BGR(OR, OG, OB);
            }
            else
            {
                gdi_act_layer = &gdi_w32_output_layer;
                gd_put_pixel[gdi_act_layer->cf] (dx, dy, gdi_act_color_from_rgb(0xFF, OR, OG, OB));
            }
        }
    }

    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
 * FUNCTION
 *  lcd_fb_update
 * DESCRIPTION
 *  
 * PARAMETERS
 *  lcd_para        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void lcd_fb_update(lcd_frame_update_struct *lcd_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 bg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef GDI_USING_LAYER_BACKGROUND
    bg = lcd_para->roi_background_color;
#else 
    bg = 0x00ffffff;
#endif 

    lcd_fb_update_internal(
        lcd_para->lcd_id - 1,
        (U32*) gdi_w32_lcd_buffer[lcd_para->lcd_id - 1],
        GDI_LCD->act_width,
        GDI_LCD->act_height,
        lcd_para->lcm_start_x,
        lcd_para->lcm_start_y,
        lcd_para->lcm_end_x,
        lcd_para->lcm_end_y,
        lcd_para->roi_offset_x,
        lcd_para->roi_offset_y,
        lcd_para->update_layer,
        FALSE,
        FALSE,
        bg);

    w32_lcd_update(lcd_para, gdi_w32_layer_data, layer_flag_table, gdi_w32_lcd_buffer[lcd_para->lcd_id - 1]);
    
    if(!lcd_para->block_mode_flag)
        if(lcd_para->lcd_block_mode_cb)
           lcd_para->lcd_block_mode_cb();

}


/*****************************************************************************
 * FUNCTION
 *  lcd_fb_update_to_memory
 * DESCRIPTION
 *  
 * PARAMETERS
 *  para        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void lcd_fb_update_to_memory(lcd_frame_update_to_mem_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 bg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef GDI_USING_LAYER_BACKGROUND
    bg = para->roi_background_color;
#else 
    bg = 0x00ffffff;
#endif 

    gdi_w32_output_layer = *gdi_act_layer;

    lcd_fb_update_internal(
        GDI_LCD->act_handle - 1,
        (U32*) para->dest_buffer_address,
        para->dest_block_width,
        0,  /* top-to-download will not use this variable */
        0,  /* startx */
        0,  /* starty */
        para->roi_width - 1,
        para->roi_height - 1,
        para->roi_offset_x,
        para->roi_offset_y,
        para->update_layer,
        TRUE,
        TRUE,
        bg);

}


/*****************************************************************************
 * FUNCTION
 *  config_lcd_output
 * DESCRIPTION
 *  
 * PARAMETERS
 *  lcd_output      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void config_lcd_output(kal_bool lcd_output)
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
 *  lcd_get_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  lcd_id          [IN]        
 *  lcd_width       [?]         
 *  lcd_height      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void lcd_get_size(kal_uint8 lcd_id, kal_uint16 *lcd_width, kal_uint16 *lcd_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}   /* lcd_get_size() */


