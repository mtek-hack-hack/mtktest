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
 *  gdi_lcd.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GDI LCD related.
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
#include "gdi_internal.h"
#include "wrappergprot.h"
#include "GlobalConstants.h"

#ifdef GDI_USING_TV_OUTPUT
#include "med_api.h"    /* media task */
#include "mdi_datatype.h"
#include "mdi_tv.h"
#endif /* GDI_USING_TV_OUTPUT */ 

/****************************************************************************
* Local Variable
*****************************************************************************/
/* gdi_layer context */
gdi_lcd_cntx_struct *GDI_LCD;
gdi_lcd_cntx_struct GDI_LCD_ARRAY[GDI_LCD_SUM];


/*****************************************************************************
 * FUNCTION
 *  gdi_lcd_init
 * DESCRIPTION
 *  Init lcd
 * PARAMETERS
 *  void
 * RETURNS
 *  GDI_RESULT(?)
 *****************************************************************************/
void gdi_lcd_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_lcd_init)
    S32 i = 0;

    memset(GDI_LCD_ARRAY, 0, sizeof(GDI_LCD_ARRAY));

    GDI_LCD_ARRAY[i].act_handle = GDI_LCD_MAIN_LCD_HANDLE;
    GDI_LCD_ARRAY[i].act_width = GDI_LCD_WIDTH;
    GDI_LCD_ARRAY[i].act_height = GDI_LCD_HEIGHT;
    GDI_LCD_ARRAY[i].act_layer_handle = GDI_LAYER_MAIN_BASE_LAYER_HANDLE;
    GDI_LCD_ARRAY[i].cf = gdi_get_color_format(DRV_MAINLCD_BIT_PER_PIXEL);
    GDI_LCD_ARRAY[i].is_freeze = FALSE;
    GDI_LCD_ARRAY[i].lcd_type = GDI_LCD_TYPE_LCD;
    GDI_LCD_ARRAY[i].bind_handle = GDI_NULL_HANDLE;
    GDI_LCD_ARRAY[i].rotate_value = GDI_LCD_LAYER_ROTATE_0;
    GDI_LCD_ARRAY[i].rotate_by_layer = FALSE;

    i++;
#ifdef __MMI_SUBLCD__
    GDI_LCD_ARRAY[i].act_handle = GDI_LCD_SUB_LCD_HANDLE;
    GDI_LCD_ARRAY[i].act_width = GDI_SUBLCD_WIDTH;
    GDI_LCD_ARRAY[i].act_height = GDI_SUBLCD_HEIGHT;
    GDI_LCD_ARRAY[i].act_layer_handle = GDI_LAYER_SUB_BASE_LAYER_HANDLE;
    GDI_LCD_ARRAY[i].cf = gdi_get_color_format(DRV_SUBLCD_BIT_PER_PIXEL);
    GDI_LCD_ARRAY[i].is_freeze = FALSE;
    GDI_LCD_ARRAY[i].lcd_type = GDI_LCD_TYPE_LCD;
    GDI_LCD_ARRAY[i].bind_handle = GDI_NULL_HANDLE;
    GDI_LCD_ARRAY[i].rotate_value = GDI_LCD_LAYER_ROTATE_0;
    GDI_LCD_ARRAY[i].rotate_by_layer = FALSE;
#endif /* __MMI_SUBLCD__ */ 
    i++;
#ifdef GDI_USING_TV_OUTPUT
    GDI_LCD_ARRAY[i].act_handle = GDI_LCD_TVOUT_HANDLE;
    GDI_LCD_ARRAY[i].act_width = 0;
    GDI_LCD_ARRAY[i].act_height = 0;
    GDI_LCD_ARRAY[i].act_layer_handle = 0;
    GDI_LCD_ARRAY[i].cf = GDI_COLOR_FORMAT_16;
    GDI_LCD_ARRAY[i].is_freeze = FALSE;
    GDI_LCD_ARRAY[i].lcd_type = GDI_LCD_TYPE_TVOUT;
    GDI_LCD_ARRAY[i].bind_handle = GDI_NULL_HANDLE;
    GDI_LCD_ARRAY[i].rotate_value = GDI_LCD_LAYER_ROTATE_0;
    GDI_LCD_ARRAY[i].rotate_by_layer = FALSE;
#endif /* GDI_USING_TV_OUTPUT */ 
    /* init LCD */

    lcd_init(MAIN_LCD, DRV_MAINLCD_INIT_COLOR);

    /* sub lcd supported */
#ifdef __MMI_SUBLCD__
    lcd_init(SUB_LCD, DRV_SUBLCD_INIT_COLOR);

#endif /* __MMI_SUBLCD__ */ 

    GDI_LCD = &GDI_LCD_ARRAY[0];

    GDI_EXIT_CRITICAL_SECTION(gdi_lcd_init)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_lcd_set_active
 * DESCRIPTION
 *  set a lcd active
 * PARAMETERS
 *  lcd_handle      [IN]        
 * RETURNS
 *  GDI_RESULT(?)
 *****************************************************************************/
void gdi_lcd_set_active(gdi_handle lcd_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_lcd_set_active)
    /* check if is already active */
    if (GDI_LCD->act_handle == lcd_handle)
    {
        GDI_RETURN_VOID;
    }

    /* backup the active layer for current LCD */
    gdi_layer_get_active(&GDI_LCD->act_layer_handle);

    /* switch to the new LCD */
    GDI_ASSERT(0 < lcd_handle && lcd_handle <= GDI_LCD_SUM);
    GDI_LCD = &GDI_LCD_ARRAY[lcd_handle - 1];
    GDI_ASSERT(GDI_LCD->lcd_type);

    /* set the active layer for new LCD */
    if(GDI_LCD->act_layer_handle != GDI_NULL_HANDLE)
        gdi_layer_set_active(GDI_LCD->act_layer_handle);

    GDI_EXIT_CRITICAL_SECTION(gdi_lcd_set_active)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_lcd_get_active
 * DESCRIPTION
 *  get current active lcd's handle
 * PARAMETERS
 *  lcd_handle_ptr      [OUT]       
 * RETURNS
 *  GDI_RESULT(?)
 *****************************************************************************/
void gdi_lcd_get_active(gdi_handle *lcd_handle_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_lcd_get_active)
    *lcd_handle_ptr = GDI_LCD->act_handle;
    GDI_EXIT_CRITICAL_SECTION(gdi_lcd_get_active)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_lcd_get_dimension
 * DESCRIPTION
 *  get dimesion of current active lcd
 * PARAMETERS
 *  width       [OUT]       
 *  height      [OUT]       
 * RETURNS
 *  GDI_RESULT(?)
 *****************************************************************************/
void gdi_lcd_get_dimension(S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_lcd_get_dimension)
    if ((GDI_LCD->rotate_value) & (0x01))
    {
        *width = GDI_LCD->act_height;
        *height = GDI_LCD->act_width;
    }
    else
    {
        *width = GDI_LCD->act_width;
        *height = GDI_LCD->act_height;
    }
    GDI_EXIT_CRITICAL_SECTION(gdi_lcd_get_dimension)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_lcd_get_bits_per_pixel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
int gdi_lcd_get_bits_per_pixel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_lcd_get_bits_per_pixel)
    GDI_RETURN(gdi_bits_per_pixel(GDI_LCD->cf));
    GDI_EXIT_CRITICAL_SECTION(gdi_lcd_get_bits_per_pixel)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_lcd_freeze
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_freeze       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_lcd_freeze(BOOL is_freeze)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_lcd_freeze)
    GDI_LCD->is_freeze = is_freeze;
    GDI_EXIT_CRITICAL_SECTION(gdi_lcd_freeze)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_lcd_get_freeze
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  The acrive LCD is freezed or not
 *****************************************************************************/
BOOL gdi_lcd_get_freeze(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_lcd_get_freeze)
    GDI_RETURN(GDI_LCD->is_freeze);
    GDI_EXIT_CRITICAL_SECTION(gdi_lcd_get_freeze)
}

/*****************************************************************************
 * FUNCTION
 *  gdi_lcd_esd_recovery
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_lcd_esd_recovery(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_lcd_esd_recovery)
#ifdef __LCD_ESD_RECOVERY__
    gdi_handle current_lcd_handle;
    S32 lcd_width, lcd_height;

    gdi_lcd_get_active(&current_lcd_handle);
    if (!lcd_ESD_check())
    {
        /* init LCD */

        lcd_init(MAIN_LCD, DRV_MAINLCD_INIT_COLOR);

        /* sub lcd supported */
    #ifdef __MMI_SUBLCD__
        lcd_init(SUB_LCD, DRV_SUBLCD_INIT_COLOR);
    #endif 

        gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
        gdi_lcd_get_dimension(&lcd_width, &lcd_height);
        gdi_layer_blt_previous(0, 0, lcd_width - 1, lcd_height - 1);
    #ifdef __MMI_SUBLCD__
        gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
        gdi_lcd_get_dimension(&lcd_width, &lcd_height);
        gdi_layer_blt_previous(0, 0, lcd_width - 1, lcd_height - 1);
    #endif /* __MMI_SUBLCD__ */ 
    }
    gdi_lcd_set_active(current_lcd_handle);
#endif /* __LCD_ESD_RECOVERY__ */ 
    GDI_EXIT_CRITICAL_SECTION(gdi_lcd_esd_recovery)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_lcd_start_esd_recovery_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_lcd_start_esd_recovery_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_lcd_start_esd_recovery_timer)
    gdi_lcd_esd_recovery();
    StartTimer(
        (U16) GDI_TIMER_ESD_RECOVERY,
        GDI_LCD_ESD_RECOVERY_TIME,
        (FuncPtr) gdi_lcd_start_esd_recovery_timer);
    GDI_EXIT_CRITICAL_SECTION(gdi_lcd_start_esd_recovery_timer)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_lcd_stop_esd_recovery_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_lcd_stop_esd_recovery_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_lcd_stop_esd_recovery_timer)
    StopTimer((U16) GDI_TIMER_ESD_RECOVERY);
    GDI_EXIT_CRITICAL_SECTION(gdi_lcd_stop_esd_recovery_timer)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_lcd_set_rotate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rotate_value        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_lcd_set_rotate(U8 rotate_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_lcd_set_rotate)
    GDI_LCD->rotate_value = rotate_value;
    GDI_EXIT_CRITICAL_SECTION(gdi_lcd_set_rotate)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_lcd_get_rotate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 gdi_lcd_get_rotate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_lcd_get_rotate)
    GDI_RETURN(GDI_LCD->rotate_value);
    GDI_EXIT_CRITICAL_SECTION(gdi_lcd_get_rotate)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_lcd_set_actual_rotate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rotate_value        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_lcd_set_actual_rotate(U8 rotate_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_lcd_set_actual_rotate)
#ifdef GDI_USING_LCD_ROTATE
    U8 lcd_rotate_value = LCD_LAYER_ROTATE_NORMAL;

#ifdef GDI_USING_TV_OUTPUT
    U16 tv_owner;
    S32 tv_out_width = 0;
    S32 tv_out_height = 0;
#endif /* GDI_USING_TV_OUTPUT */ 

    switch (rotate_value)
    {
        case GDI_LCD_LAYER_ROTATE_0:
            lcd_rotate_value = LCD_LAYER_ROTATE_NORMAL;
            break;
        case GDI_LCD_LAYER_ROTATE_90:
            lcd_rotate_value = LCD_LAYER_ROTATE_90;
            break;
        case GDI_LCD_LAYER_ROTATE_180:
            lcd_rotate_value = LCD_LAYER_ROTATE_180;
            break;
        case GDI_LCD_LAYER_ROTATE_270:
            lcd_rotate_value = LCD_LAYER_ROTATE_270;
            break;
        case GDI_LCD_LAYER_ROTATE_0_MIRROR:
            lcd_rotate_value = LCD_LAYER_MIRROR;
            break;
        case GDI_LCD_LAYER_ROTATE_90_MIRROR:
            lcd_rotate_value = LCD_LAYER_MIRROR_ROTATE_90;
            break;
        case GDI_LCD_LAYER_ROTATE_180_MIRROR:
            lcd_rotate_value = LCD_LAYER_MIRROR_ROTATE_180;
            break;
        case GDI_LCD_LAYER_ROTATE_270_MIRROR:
            lcd_rotate_value = LCD_LAYER_MIRROR_ROTATE_270;
            break;
        default:
            GDI_ASSERT(0);
    }

    if (GDI_LCD_MAIN_LCD_HANDLE == GDI_LCD->act_handle)
    {
        lcd_set_rotate(MAIN_LCD, lcd_rotate_value);

    #ifdef GDI_USING_TV_OUTPUT
        if (mdi_tvout_is_enable())
        {
            tv_owner = mdi_tvout_get_owner();

            if (tv_owner == MDI_TV_OWNER_GDI)
            {
                switch (rotate_value)
                {
                    case GDI_LCD_LAYER_ROTATE_0:
                    case GDI_LCD_LAYER_ROTATE_0_MIRROR:
                    case GDI_LCD_LAYER_ROTATE_180:
                    case GDI_LCD_LAYER_ROTATE_180_MIRROR:
                        tv_out_width = GDI_LCD->act_width;
                        tv_out_height = GDI_LCD->act_height;
                        break;

                    case GDI_LCD_LAYER_ROTATE_90:
                    case GDI_LCD_LAYER_ROTATE_270:
                    case GDI_LCD_LAYER_ROTATE_90_MIRROR:
                    case GDI_LCD_LAYER_ROTATE_270_MIRROR:
                        tv_out_width = GDI_LCD->act_height;
                        tv_out_height = GDI_LCD->act_width;
                        break;
                    default:
                        GDI_ASSERT(0);

                }

                mdi_tvout_resize_buffer(tv_out_width, tv_out_height);
            }
        }
    #endif /* GDI_USING_TV_OUTPUT */ 

    }
    else
    {
        lcd_set_rotate(SUB_LCD, lcd_rotate_value);
    }

#endif /* GDI_USING_LCD_ROTATE */ 

    GDI_EXIT_CRITICAL_SECTION(gdi_lcd_set_actual_rotate)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_lcd_set_bind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  lcd_handle      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_lcd_set_bind(gdi_handle lcd_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_lcd_set_bind)
    GDI_ASSERT(GDI_LCD->lcd_type != GDI_LCD_TYPE_TVOUT);
    GDI_ASSERT(GDI_LCD_ARRAY[lcd_handle - 1].lcd_type == GDI_LCD_TYPE_TVOUT || lcd_handle == GDI_NULL_HANDLE);
    GDI_LCD->bind_handle = lcd_handle;
    GDI_EXIT_CRITICAL_SECTION(gdi_lcd_set_bind)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_rotate_map_lcd_to_absolute_hw_region
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rotate_value        [IN]        
 *  x1                  [?]         
 *  y1                  [?]         
 *  x2                  [?]         
 *  y2                  [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_rotate_map_lcd_to_absolute_hw_region(U8 rotate_value, S32 *x1, S32 *y1, S32 *x2, S32 *y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_rotate_map_lcd_to_absolute_hw_region)
    S32 tx1, ty1, tx2, ty2;

    switch (rotate_value)
    {
        case GDI_LCD_LAYER_ROTATE_0:
        default:
            break;
        case GDI_LCD_LAYER_ROTATE_90:
            tx1 = *y1;
            ty1 = GDI_LCD->act_height - *x2 - 1;
            tx2 = *y2;
            ty2 = GDI_LCD->act_height - *x1 - 1;
            *x1 = tx1;
            *y1 = ty1;
            *x2 = tx2;
            *y2 = ty2;
            break;
        case GDI_LCD_LAYER_ROTATE_180:
            tx1 = GDI_LCD->act_width - *x2 - 1;
            ty1 = GDI_LCD->act_height - *y2 - 1;
            tx2 = GDI_LCD->act_width - *x1 - 1;
            ty2 = GDI_LCD->act_height - *y1 - 1;
            *x1 = tx1;
            *y1 = ty1;
            *x2 = tx2;
            *y2 = ty2;
            break;
        case GDI_LCD_LAYER_ROTATE_270:
            tx1 = GDI_LCD->act_width - *y2 - 1;
            ty1 = *x1;
            tx2 = GDI_LCD->act_width - *y1 - 1;
            ty2 = *x2;
            *x1 = tx1;
            *y1 = ty1;
            *x2 = tx2;
            *y2 = ty2;
            break;
        case GDI_LCD_LAYER_ROTATE_0_MIRROR:
            tx1 = GDI_LCD->act_width - *x2 - 1;
            tx2 = GDI_LCD->act_width - *x1 - 1;
            *x1 = tx1;
            *x2 = tx2;
            break;
        case GDI_LCD_LAYER_ROTATE_90_MIRROR:
            tx1 = *y1;
            ty1 = *x1;
            tx2 = *y2;
            ty2 = *x2;
            *x1 = tx1;
            *y1 = ty1;
            *x2 = tx2;
            *y2 = ty2;
            break;
        case GDI_LCD_LAYER_ROTATE_180_MIRROR:
            ty1 = GDI_LCD->act_height - *y2 - 1;
            ty2 = GDI_LCD->act_height - *y1 - 1;
            *y1 = ty1;
            *y2 = ty2;
            break;
        case GDI_LCD_LAYER_ROTATE_270_MIRROR:
            tx1 = GDI_LCD->act_width - *y2 - 1;
            ty1 = GDI_LCD->act_height - *x2 - 1;
            tx2 = GDI_LCD->act_width - *y1 - 1;
            ty2 = GDI_LCD->act_height - *x1 - 1;
            *x1 = tx1;
            *y1 = ty1;
            *x2 = tx2;
            *y2 = ty2;
            break;
    }
    GDI_EXIT_CRITICAL_SECTION(gdi_rotate_map_lcd_to_absolute_hw_region)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_rotate_map_absolute_hw_to_lcd_region
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rotate_value        [IN]        
 *  x1                  [?]         
 *  y1                  [?]         
 *  x2                  [?]         
 *  y2                  [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_rotate_map_absolute_hw_to_lcd_region(U8 rotate_value, S32 *x1, S32 *y1, S32 *x2, S32 *y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_rotate_map_lcd_to_absolute_hw_region)
    S32 tx1, ty1, tx2, ty2;

    switch (rotate_value)
    {
        case GDI_LCD_LAYER_ROTATE_0:
        default:
            break;
        case GDI_LCD_LAYER_ROTATE_90:
            tx1 = GDI_LCD->act_height - *y2 - 1;
            ty1 = *x1;
            tx2 = GDI_LCD->act_height - *y1 - 1;
            ty2 = *x2;
            *x1 = tx1;
            *y1 = ty1;
            *x2 = tx2;
            *y2 = ty2;
            break;
        case GDI_LCD_LAYER_ROTATE_180:
            tx1 = GDI_LCD->act_width - *x2 - 1;
            ty1 = GDI_LCD->act_height - *y2 - 1;
            tx2 = GDI_LCD->act_width - *x1 - 1;
            ty2 = GDI_LCD->act_height - *y1 - 1;
            *x1 = tx1;
            *y1 = ty1;
            *x2 = tx2;
            *y2 = ty2;
            break;
        case GDI_LCD_LAYER_ROTATE_270:
            tx1 = *y1;
            ty1 = GDI_LCD->act_width - *x2 - 1;
            tx2 = *y2;
            ty2 = GDI_LCD->act_width - *x1 - 1;
            *x1 = tx1;
            *y1 = ty1;
            *x2 = tx2;
            *y2 = ty2;
            break;
        case GDI_LCD_LAYER_ROTATE_0_MIRROR:
            tx1 = GDI_LCD->act_width - *x2 - 1;
            tx2 = GDI_LCD->act_width - *x1 - 1;
            *x1 = tx1;
            *x2 = tx2;
            break;
        case GDI_LCD_LAYER_ROTATE_90_MIRROR:
            break;
        case GDI_LCD_LAYER_ROTATE_180_MIRROR:
            ty1 = GDI_LCD->act_height - *y2 - 1;
            ty2 = GDI_LCD->act_height - *y1 - 1;
            *y1 = ty1;
            *y2 = ty2;
            break;
        case GDI_LCD_LAYER_ROTATE_270_MIRROR:
            tx1 = GDI_LCD->act_height - *x2 - 1;
            ty1 = GDI_LCD->act_width - *y2 - 1;
            tx2 = GDI_LCD->act_height - *x1 - 1;
            ty2 = GDI_LCD->act_width - *y1 - 1;
            *x1 = tx1;
            *y1 = ty1;
            *x2 = tx2;
            *y2 = ty2;
            break;
    }
    GDI_EXIT_CRITICAL_SECTION(gdi_rotate_map_lcd_to_absolute_hw_region)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_rotate_map_absolute_hw_to_lcd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [?]     
 *  y       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_rotate_map_absolute_hw_to_lcd(S32 *x, S32 *y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_rotate_map_absolute_hw_to_lcd)
    S32 tx, ty;

    switch (GDI_LCD->rotate_value)
    {
        case GDI_LCD_LAYER_ROTATE_0:
        default:
            break;
        case GDI_LCD_LAYER_ROTATE_90:
            tx = GDI_LCD->act_height - *y - 1;
            ty = *x;
            *x = tx;
            *y = ty;
            break;
        case GDI_LCD_LAYER_ROTATE_180:
            tx = GDI_LCD->act_width - *x - 1;
            ty = GDI_LCD->act_height - *y - 1;
            *x = tx;
            *y = ty;
            break;
        case GDI_LCD_LAYER_ROTATE_270:
            tx = *y;
            ty = GDI_LCD->act_width - *x - 1;
            *x = tx;
            *y = ty;
            break;
        case GDI_LCD_LAYER_ROTATE_0_MIRROR:
            tx = GDI_LCD->act_width - *x - 1;
            *x = tx;
            break;
        case GDI_LCD_LAYER_ROTATE_90_MIRROR:
            tx = *y;
            ty = *x;
            *x = tx;
            *y = ty;
            break;
        case GDI_LCD_LAYER_ROTATE_180_MIRROR:
            ty = GDI_LCD->act_height - *y - 1;
            *y = ty;
            break;
        case GDI_LCD_LAYER_ROTATE_270_MIRROR:
            tx = GDI_LCD->act_height - *y - 1;
            ty = GDI_LCD->act_width - *x - 1;
            *x = tx;
            *y = ty;
            break;
    }
    GDI_EXIT_CRITICAL_SECTION(gdi_rotate_map_absolute_hw_to_lcd)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_rotate_map_lcd_to_absolute_hw
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [?]     
 *  y       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_rotate_map_lcd_to_absolute_hw(S32 *x, S32 *y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_rotate_map_lcd_to_absolute_hw)
    S32 tx, ty;

    switch (GDI_LCD->rotate_value)
    {
        case GDI_LCD_LAYER_ROTATE_0:
        default:
            break;
        case GDI_LCD_LAYER_ROTATE_90:
            tx = *y;
            ty = GDI_LCD->act_height - *x - 1;
            *x = tx;
            *y = ty;
            break;
        case GDI_LCD_LAYER_ROTATE_180:
            tx = GDI_LCD->act_width - *x - 1;
            ty = GDI_LCD->act_height - *y - 1;
            *x = tx;
            *y = ty;
            break;
        case GDI_LCD_LAYER_ROTATE_270:
            tx = GDI_LCD->act_height - *y - 1;
            ty = *x;
            *x = tx;
            *y = ty;
            break;
        case GDI_LCD_LAYER_ROTATE_0_MIRROR:
            tx = GDI_LCD->act_width - *x - 1;
            *x = tx;
            break;
        case GDI_LCD_LAYER_ROTATE_90_MIRROR:
            tx = *y;
            ty = *x;
            *x = tx;
            *y = ty;
            break;
        case GDI_LCD_LAYER_ROTATE_180_MIRROR:
            ty = GDI_LCD->act_height - *y - 1;
            *y = ty;
            break;
        case GDI_LCD_LAYER_ROTATE_270_MIRROR:
            tx = GDI_LCD->act_height - *y - 1;
            ty = GDI_LCD->act_width - *x - 1;
            *x = tx;
            *y = ty;
            break;
    }
    GDI_EXIT_CRITICAL_SECTION(gdi_rotate_map_lcd_to_absolute_hw)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_lcd_blt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle0     [IN]        
 *  handle1     [IN]        
 *  handle2     [IN]        
 *  handle3     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_lcd_blt(gdi_handle handle0, gdi_handle handle1, gdi_handle handle2, gdi_handle handle3)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_lcd_blt)
    S32 lcd_width, lcd_height;

    gdi_lcd_get_dimension(&lcd_width, &lcd_height);

    GDI_RETURN(gdi_layer_blt(handle0, handle1, handle2, handle3, 0, 0, lcd_width - 1, lcd_height - 1));
    GDI_EXIT_CRITICAL_SECTION(gdi_lcd_blt)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_lcd_set_rotate_by_layer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rotate_by_layer     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_lcd_set_rotate_by_layer(BOOL rotate_by_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_lcd_set_rotate_by_layer)
    GDI_LCD->rotate_by_layer = rotate_by_layer;
    GDI_EXIT_CRITICAL_SECTION(gdi_lcd_set_rotate_by_layer)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_lcd_get_rotate_by_layer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
BOOL gdi_lcd_get_rotate_by_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_lcd_get_rotate_by_layer)
#if defined(GDI_USING_LCD_ROTATE)
    GDI_RETURN(GDI_LCD->rotate_by_layer);
#else 
    GDI_RETURN(TRUE);
#endif 
    GDI_EXIT_CRITICAL_SECTION(gdi_lcd_get_rotate_by_layer)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_lcd_set_blt_handle_rotate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_lcd_set_blt_handle_rotate(void)
{
#if defined(GDI_USING_LCD_ROTATE)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* GDI_USING_LCD_ROTATE */
    if (!GDI_LCD->rotate_by_layer)
    {
        gdi_lcd_set_actual_rotate(GDI_LCD->rotate_value);
        {
            U32 i = 0;

            for (i = 0; i < GDI_LAYER_HW_LAYER_COUNT; i++)
            {
                if (GDI_LCD->blt_handle[i] >= GDI_LAYER_VALID_HANDLE_START)
                {
                    gdi_layer_set_actual_rotate(
                        GDI_LCD->blt_handle[i],
                        ((gdi_layer_struct*) GDI_LCD->blt_handle[i])->rotate_value);
                }
            }
        }
    }
    else
#endif /* defined(GDI_USING_LCD_ROTATE) */ 
#if defined(GDI_USING_LAYER_ROTATE) || defined(GDI_USING_LCD_ROTATE)
        /* Not Support GDI_USING_LCD_ROTATE */
    {
        U32 i = 0;

    #if defined(GDI_USING_LCD_ROTATE)
        gdi_lcd_set_actual_rotate(GDI_LCD_LAYER_ROTATE_0);
    #endif 
        for (i = 0; i < GDI_LAYER_HW_LAYER_COUNT; i++)
        {
            if (GDI_LCD->blt_handle[i] >= GDI_LAYER_VALID_HANDLE_START)
            {
                U8 layer_actual_rotate_value = (U8) ((((GDI_LCD_LAYER_ROTATE_MIRROR_MASK & GDI_LCD->rotate_value) |
                                                       (0x04 -
                                                        (GDI_LCD_LAYER_ROTATE_ANGLE_MASK & GDI_LCD->rotate_value))) +
                                                      ((gdi_layer_struct*) GDI_LCD->blt_handle[i])->
                                                      rotate_value) & GDI_LCD_LAYER_ROTATE_ALL_MASK);
                gdi_layer_set_actual_rotate(GDI_LCD->blt_handle[i], layer_actual_rotate_value);
            }
        }
    }
#else /* defined(GDI_USING_LAYER_ROTATE) || defined(GDI_USING_LCD_ROTATE) */ 
        GDI_ASSERT(!GDI_LCD->rotate_value);
#endif /* defined(GDI_USING_LAYER_ROTATE) || defined(GDI_USING_LCD_ROTATE) */ 
}


/*****************************************************************************
 * FUNCTION
 *  gdi_lcd_paint_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle0     [IN]        
 *  handle1     [IN]        
 *  handle2     [IN]        
 *  handle3     [IN]        
 *  handle4     [IN]        
 *  handle5     [IN]        
 *  x1          [IN]        
 *  y1          [IN]        
 *  x2          [IN]        
 *  y2          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_lcd_paint_ext(gdi_handle handle0, gdi_handle handle1, gdi_handle handle2, gdi_handle handle3,
#ifdef GDI_6_LAYERS
                             gdi_handle handle4, gdi_handle handle5,
#endif 
                             S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_lcd_paint_ext)
    GDI_RESULT result;

    result = gdi_layer_blt_ext(handle0, handle1, handle2, handle3,
#ifdef GDI_6_LAYERS
                               handle4, handle5,
#endif 
                               x1, y1, x2, y2);
    GDI_RETURN(result);
    GDI_EXIT_CRITICAL_SECTION(gdi_lcd_paint_ext)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_lcd_repaint
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x1      [IN]        
 *  y1      [IN]        
 *  x2      [IN]        
 *  y2      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_lcd_repaint(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_lcd_repaint_ext)
    GDI_RETURN(gdi_layer_blt_previous(x1, y1, x2, y2));
    GDI_EXIT_CRITICAL_SECTION(gdi_lcd_repaint_ext)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_lcd_paint_all_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle0     [IN]        
 *  handle1     [IN]        
 *  handle2     [IN]        
 *  handle3     [IN]        
 *  handle4     [IN]        
 *  handle5     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_lcd_paint_all_ext(gdi_handle handle0, gdi_handle handle1, gdi_handle handle2, gdi_handle handle3
#ifdef GDI_6_LAYERS
                                 , gdi_handle handle4, gdi_handle handle5
#endif 
    )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_lcd_paint_all_ext)
    S32 lcd_width, lcd_height;
    GDI_RESULT result;

    gdi_lcd_get_dimension(&lcd_width, &lcd_height);
    result = gdi_layer_blt_ext(handle0, handle1, handle2, handle3
#ifdef GDI_6_LAYERS
                               , handle4, handle5
#endif 
                               , 0, 0, lcd_width - 1, lcd_height - 1);

    GDI_RETURN(result);
    GDI_EXIT_CRITICAL_SECTION(gdi_lcd_paint_all_ext)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_lcd_repaint_all
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_lcd_repaint_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_lcd_repaint_all_ext)
    S32 lcd_width, lcd_height;

    gdi_lcd_get_dimension(&lcd_width, &lcd_height);

    GDI_RETURN(gdi_layer_blt_previous(0, 0, lcd_width - 1, lcd_height - 1));
    GDI_EXIT_CRITICAL_SECTION(gdi_lcd_repaint_all_ext)
}

