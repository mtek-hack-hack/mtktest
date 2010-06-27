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
*  gui_spectrum.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   audio spectrum display header file
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
#include "gui.h"
#include "gdi_datatype.h"
#include "gdi_const.h"

#define MAX_NUM_OF_SPECTRUMS      5

/* #define SPACE_FOR_SCALE           3    3 pixels are allocated for scale (both vert. and hrzntl) this include 1 lines
   ( i.e. 1 pixels) & 2 pixels for scale markings.  */

#define DIST_BETWEEN_BARS         1     /* this is in pixels.the distance between the various different frequency structures 
                                           which may be single unit bars or multiple block bars. */

#define BLOCK_HEIGHT              2     /* the height of each block in the block */

#define DIST_BETWEEN_BLOCKS       1     /* this is used for vertical distance between the blocks and the vert. dist. between 
                                           horizontal scale line and bars */

#define MIN_BAR_WIDTH             2     /* this is the minimum bar width for checking the width parameter in Init function. */
#define NUM_OF_COLOR_COMPONENTS 3
#define SPECTRUM_BKGD_COLOR_BAR_STYLE       gdi_act_color_from_rgb(0xFF,0,0,0)  /* black color for the background in bar style */

//block style colors
//#define SPECTRUM_BKGD_COLOR_BLOCK_STYLE                gdi_act_color_from_rgb(0xFF,145,201,200)     //blue for bkgd in block style.
#define SPECTRUM_BKGD_COLOR_BLOCK_STYLE   GDI_COLOR_TRANSPARENT
#define SPECTRUM_BLOCK_RED_COMPONENT         255
#define SPECTRUM_BLOCK_BLUE_COMPONENT        35

#define SPECTRUM_TOP_INDICATOR_COLOR_BLOCK_STYLE       gdi_act_color_from_rgb(0xFF,255,0,0)
#define SPECTRUM_TOP_INDICATOR_COLOR_BAR_STYLE      gdi_act_color_from_rgb(0xFF,255,0,0)

#define SPECTRUM_SCALE_COLOR            gdi_act_color_from_rgb(0xFF,69,139,141)
#define SPACE_TO_BE_LEFT_FOR_CIRCLES_STYLE    10

typedef enum
{
    STYLE_OFF,
    STYLE_BLOCKS,
    STYLE_BARS,
    STYLE_CIRCLES
} SPECTRUM_STYLE_ENUM;

typedef struct
{
    S16 start_x;
    S16 start_y;
    S32 width;
    S32 height;
    S16 number_of_bars;
    GDI_HANDLE target_layer;
    GDI_HANDLE target_lcd;
    S8 style;
    BOOL active;
}
spectrum_struct;

/* functions */
extern BOOL mmi_audio_spectrum_init_display(spectrum_struct *spectrum);
extern void mmi_audio_spectrum_start_display(spectrum_struct *spectrum);
extern void mmi_audio_spectrum_display_timer(void);
extern void mmi_audio_spectrum_redraw_display(spectrum_struct *spectrum, U8 *amplitude_val, U8 *top);
extern void mmi_audio_spectrum_clear_display(spectrum_struct *spectrum);
extern void mmi_audio_spectrum_stop_display(spectrum_struct *spectrum);

#endif /* __MMI_AUDIO_SPECTRUM_DISPLAY__ */ 

