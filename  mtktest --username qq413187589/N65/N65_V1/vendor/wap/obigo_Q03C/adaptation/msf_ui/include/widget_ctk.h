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
 * widget_ctk.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Integration of CTK and widget
 *
 * Author:
 * -------
 * -------
*
*==============================================================================
*           HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * $Log$
 *
 * removed!
 * removed!
 * sync 07B to Gemini branch
 *
 * removed!
 * removed!
 * add to source control recursely
 *
 * removed!
 * removed!
 * Check in for landscape (320X240)
 *
 * removed!
 * removed!
 * Modify ASM usage in MMS SMIL editor (only use screen-based memory)
 *
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/
#ifndef __WIDGET_CTK_H__
#define __WIDGET_CTK_H__

#include "MMIDataType.h"
#include "wgui.h"

/*************************************************************************
 * TextView
 *************************************************************************/
#define WIDGET_CTK_TEXT_VIEW_NORMAL             (0x00)
#define WIDGET_CTK_TEXT_VIEW_DRAW_SEPARATOR     (0x01)
#define WIDGET_CTK_TEXT_VIEW_DRAW_NO_SCROLLBAR  (0x02)



/*************************************************************************
 * Progress view
 *************************************************************************/
#define WIDGET_CTK_PROGRESS_BAR_UPDATE_NONE         (0)
#define WIDGET_CTK_PROGRESS_BAR_UPDATE_REQ          (1)
#define WIDGET_CTK_PROGRESS_BAR_UPDATE_DONE         (2)


/*************************************************************************
 * Advanced SMIL editor
 *************************************************************************/
#if defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__)

#define WIDGET_SMIL_EDITOR_LARGE_RESOLUTION  /* large resolution */

#if defined(__MMI_MAINLCD_320X240__)
#define WIDGET_SMIL_EDITOR_LANDSCAPE_STYLE
#endif

#else

#define WIDGET_SMIL_EDITOR_SMALL_RESOLUTION  /* small resolution */

#endif /* #if defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) */


/*
 * Beware of the macro SE_EDITOR_MIN_HEIGHT 
 * (Minimum height reserved for the editor information bar, multitap, and initial display region of text)
 * If it is set too small, image might be resized too tall.
 *
 * <one-line text>
 * <tall image>
 *
 * Because the editor cursor must be always displayed inside the editor, it might not be able to 
 * scroll to the bottom of the image
 */
#if defined(WIDGET_SMIL_EDITOR_LARGE_RESOLUTION)

#if defined(WIDGET_SMIL_EDITOR_LANDSCAPE_STYLE)
#define WIDGET_SMIL_EDITOR_ICON_IN_INFO_BAR
#define SE_PADDING_H_START_SPACE (75)   /* Horizotnal started padding of the icons */
#define SE_PADDING_V_SPACE       (4)    /* Vertical padding of the icons */
#define SE_PADDING_H_SPACE       (3)    /* Horizotnal padding of the icons */

#else
#define SE_PADDING_H_START_SPACE (6)    /* Horizotnal started padding of the icons */
#define SE_PADDING_V_SPACE       (4)    /* Vertical padding of the icons */
#define SE_PADDING_H_SPACE       (6)    /* Horizotnal padding of the icons */

#endif

/* two lines + information bar + multitap  */
#define SE_EDITOR_MIN_HEIGHT     (80)   // TODO: reference GUI definition

#else /* WIDGET_SMIL_EDITOR_LARGE_RESOLUTION */

/* WIDGET_SMIL_EDITOR_SMALL_RESOLUTION - Typically we only support 128x160 */
#define SE_PADDING_V_SPACE       (2)    /* Veritcal padding of the icons */
#define SE_PADDING_H_SPACE       (3)    /* Horizonal padding of the icons */
#define SE_PADDING_H_START_SPACE (3)    /* Horizotnal started padding of the icons */

/* one line + information bar + multitap  */
#define SE_EDITOR_MIN_HEIGHT     (54)   // TODO: reference GUI definition

#endif /* WIDGET_SMIL_EDITOR_LARGE_RESOLUTION */

/* 
 * Maximum width of cached image: MMI_content_width. 
 * Maximum height of cached image: (MMI_content_height - SE_EDITOR_MIN_HEIGHT) 
 *
 * We use GDI layer for playing SMIL, but we can not use it for SMIL editor because SMIL editor
 * requires to enter other screens in order to set input method.
 */

#if defined(WIDGET_SMIL_EDITOR_LARGE_RESOLUTION)
#define SE_IMAGE_MAX_HEIGHT (GDI_LCD_HEIGHT - MMI_BUTTON_BAR_HEIGHT - MMI_TITLE_HEIGHT - MMI_STATUS_BAR_HEIGHT - SE_EDITOR_MIN_HEIGHT)
#else 
#define SE_IMAGE_MAX_HEIGHT (GDI_LCD_HEIGHT - MMI_BUTTON_BAR_HEIGHT - MMI_TITLE_HEIGHT - SE_EDITOR_MIN_HEIGHT)
#endif 

#define WIDGET_CTK_SE_IMAGE_CACHE_BUF_SIZE   \
         ( GDI_LCD_WIDTH * SE_IMAGE_MAX_HEIGHT * (GDI_MAINLCD_BIT_PER_PIXEL>>3) )



#endif /* __WIDGET_CTK_H__ */
