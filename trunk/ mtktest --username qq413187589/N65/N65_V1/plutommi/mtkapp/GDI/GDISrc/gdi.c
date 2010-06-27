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
 *  gdi.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GDI
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

/*****************************************************************************
 * FUNCTION
 *  gdi_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U32 GDI_DEBUG_FLAG;
U32 GDI_DEBUG_CNT;
U8 GDI_DEBUG_ARG[32];

void gdi_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static BOOL is_init = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_init == FALSE)
    {
        GDI_DEBUG_FLAG = 0;
        /* init global lfs object */
        gdi_lfs_initialize();
        
        /* init the gdi global mutex */
        gdi_fast_mutex_init();

        /* init lcd */
        gdi_lcd_init();

        /* init layer */
        gdi_layer_init();

        /* init 2D engine */
    #if defined(GDI_USING_2D_ENGINE) || defined(GDI_USING_2D_ENGINE_V2)
        gdi_2d_engine_init();
    #endif 

        /* init image */
        gdi_image_init();

        /* init animation */
        gdi_anim_init();

    #if defined(GDI_USING_HW_GIF) || defined(GDI_USING_HW_GIF_V2)
        /* init the hardware gif */
        gdi_image_hwgif_init();
    #endif /* defined(GDI_USING_HW_GIF) || defined(GDI_USING_HW_GIF_V2) */ 

    #if defined(GDI_USING_HW_PNG)
        gdi_image_png_init();
    #endif 

    #if defined(WIN32)
    #if defined(GDI_USING_W32_JPEG) || defined(GDI_USING_W32_PNG)
        w32_image_init();
    #endif 
    #endif /* defined(WIN32) */ 
    
        /* set flag to true avoid re-init */
        is_init = TRUE;

        /* set Main LCD and base layer active */
        gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
        
        /* set the default ABM source layer to the main LCD base layer */
        gdi_image_abm_set_source_layer(GDI_LAYER_MAIN_BASE_LAYER_HANDLE);
    }
}


void gdi_debug_handler(S32 index,U8* string)
{
    strncpy((char*)GDI_DEBUG_ARG,(char*)string,sizeof(GDI_DEBUG_ARG));
    GDI_DEBUG_FLAG = index;
    GDI_DEBUG_CNT  = 0;
}

