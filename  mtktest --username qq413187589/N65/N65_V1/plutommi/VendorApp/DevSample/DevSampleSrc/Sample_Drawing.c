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
 *  Sample_Drawing.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Sample code for drawing (GDI, text)
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *******************************************************************************/
#include "MMI_features.h"
#include "MMIDataType.h"
#include "gdi_include.h"
#include "GlobalMenuItems.h"
#include "DevAppDef.h"
#include "gui.h"

typedef struct
{
    GDI_HANDLE anim_handle;
} mmi_sample_drawing_cntx_struct;

mmi_sample_drawing_cntx_struct g_sample_drawing_cntx;
mmi_sample_drawing_cntx_struct *sample_drawing_p = &g_sample_drawing_cntx;

/****************************************************************************
*
*  [Sample]
*
*  Draw static image at center of screen
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_sample_drawing_image
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sample_drawing_image(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 image_width;
    S32 image_height;
    S32 offset_x;
    S32 offset_y;
    GDI_RESULT ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* clear base layer as black */
    gdi_layer_clear(GDI_COLOR_BLACK);

    /* get image size */
    ret = gdi_image_get_dimension_id(IMG_ID_DEVAPP_1, &image_width, &image_height);

    if (ret < 0)
    {
        /* error handling */
    }

    /* align at center */
    offset_x = (UI_device_width - image_width) >> 1;
    offset_y = (UI_device_width - image_height) >> 1;

    gdi_image_draw_id(offset_x, offset_y, IMG_ID_DEVAPP_1);

}

/****************************************************************************
*
*  [Sample]
*
*  Draw static gif animation at center of screen
*  Start a timer to terminate animation after 1 sec
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_sample_drawing_stop_animation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sample_drawing_stop_animation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sample_drawing_p->anim_handle)
    {
        gdi_image_stop_animation(sample_drawing_p->anim_handle);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sample_drawing_start_animation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sample_drawing_start_animation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 image_width;
    S32 image_height;
    S32 offset_x;
    S32 offset_y;
    GDI_RESULT ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* clear base layer as black */
    gdi_layer_clear(GDI_COLOR_BLACK);

    /* get image size */
    ret = gdi_image_get_dimension_id(IMG_ID_DEVAPP_1, &image_width, &image_height);

    if (ret < 0)
    {
        /* error handling */
    }

    /* align at center */
    offset_x = (UI_device_width - image_width) >> 1;
    offset_y = (UI_device_width - image_height) >> 1;

    sample_drawing_p->anim_handle = 0;
    ret = gdi_image_draw_animation_id(offset_x, offset_y, IMG_ID_DEVAPP_1, &sample_drawing_p->anim_handle);

    /* >= 0 means no error */
    if (ret >= 0)
    {
        gui_start_timer(1000, mmi_sample_drawing_stop_animation);

    }

}

