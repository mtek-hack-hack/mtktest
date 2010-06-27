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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *  wgui_categories_UCE.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Unified Composer Category 
 *
 *  [Category280]       UCE Category
 *
 * Author:
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __WGUI_CATEGORIES_UCE_H__
#define __WGUI_CATEGORIES_UCE_H__
#include "FileMgr.h"    /* FMGR_MAX_PATH_LEN is defined in here */
#include "Gdi_include.h" 								/* Bits Per Pixel*/
#include "lcd_sw_rnd.h"
#include "gdi_lcd_config.h"     				/* LCD_WIDTH */

/***************************************************************************** 
* Define
*****************************************************************************/
#if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__)
#define CAT280_THUMBNAIL_FRAME_HEIGHT 80
#elif defined(__MMI_MAINLCD_176X220__)
#define CAT280_THUMBNAIL_FRAME_HEIGHT 80
#elif defined(__MMI_MAINLCD_128X160__)
#define CAT280_THUMBNAIL_FRAME_HEIGHT 50
#else /* 128x128 display */
#define CAT280_THUMBNAIL_FRAME_HEIGHT 45
#endif

#define CAT280_THUMBNAIL_BUFFER_SIZE ((CAT280_THUMBNAIL_FRAME_HEIGHT*LCD_WIDTH*GDI_MAINLCD_BIT_PER_PIXEL)>>3)

#if 0 
#if defined(__MMI_MAINLCD_240X320__)
/* under construction !*/
#elif defined(__MMI_MAINLCD_176X220__)
/* under construction !*/
#elif defined(__MMI_MAINLCD_128X160__)
/* under construction !*/
#else /* 128x128 display */
/* under construction !*/
#endif 
#endif
 
/***************************************************************************** 
* Typedef 
*****************************************************************************/
typedef enum
{
    WGUI_UCE_MSG_TYPE_SMS,
    WGUI_UCE_MSG_TYPE_MMS, /* Tony, for compile warning */
    WGUI_UCE_MSG_TYPE_TOTAL
} wgui_uce_msg_type_enum;

typedef enum
{
    WGUI_UCE_LAYOUT_TYPE_THUMBNAIL_AT_TOP,
    WGUI_UCE_LAYOUT_TYPE_THUMBNAIL_AT_BOTTOM,
    WGUI_UCE_LAYOUT_TYPE_THUMBNAIL_TOTAL
} wgui_uce_layout_type_enum;

typedef enum
{
    WGUI_UCE_OBJECT_TYPE_IMAGE,
    WGUI_UCE_OBJECT_TYPE_AUDIO,
    WGUI_UCE_OBJECT_TYPE_VIDEO,
    WGUI_UCE_OBJECT_TYPE_ATTACHMENT,
    WGUI_UCE_OBJECT_TYPE_TOTAL
} wgui_uce_object_type_enum;

typedef struct
{
    U16 char_count;             /* Total Character Count */
    U16 utf8_msg_len;           /* Msg Len in UTF8 */
    U16 extension_char_count;   /* EXT CHAR Count */
    U16 UCS2_count;             /* Tricky: count UCS2 characters that are not also extension characters */
} wgui_uce_text_info_struct;

typedef struct
{
    wgui_uce_msg_type_enum msg_type;

    U8 *text_buffer;        /* always UCS2. */
    U32 text_buffer_size;
    U8 *thumbnail_buffer;   /* allocated by category using screen based ASM and freed in exit category */
    U16 default_image_id;

    wgui_uce_text_info_struct text_info;

    U8 total_slides;
    U8 current_slide;
    MMI_BOOL is_image;
    MMI_BOOL is_audio;
    MMI_BOOL is_video;
    MMI_BOOL is_attachment;

    wgui_uce_layout_type_enum layout;
    U16 file_path[FMGR_MAX_PATH_LEN];   /* Currently ~260 characters */

    color text_color;       /* reserved */
    color background_color; /* reserved */
} wgui_uce_context_struct;

typedef enum
{
    WGUI_UCE_TEXT_CHANGE_ALLOWED,
    WGUI_UCE_TEXT_CHANGE_NOT_ALLOWED,
    WGUI_UCE_TEXT_CHANGE_TOTAL
} wgui_uce_text_change_result_enum;

typedef wgui_uce_text_change_result_enum(*wgui_uce_text_change_callback) (wgui_uce_text_info_struct *new_text_info);

typedef U32(*wgui_uce_get_message_size_callback) (wgui_uce_text_info_struct *current_text_info, wgui_uce_msg_type_enum uce_msg_type);

/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/

extern void wgui_uce_insert_text(wgui_uce_text_info_struct *text_info, U8 *text_buffer);
extern U32 wgui_uce_insert_text_template(U8 *string, U16 no_of_char, U8 *guibuffer);

extern void wgui_uce_get_current_text_info(wgui_uce_text_info_struct *current_text_info);
extern void wgui_uce_get_text_info_for_buffer(wgui_uce_text_info_struct *text_info, U8 *text_buffer);

extern void wgui_uce_add_object(
                wgui_uce_msg_type_enum object,
                U16 *file_path,
                U16 default_image_id,
                wgui_uce_layout_type_enum alignment_type);
extern void wgui_uce_delete_object(wgui_uce_msg_type_enum object);

extern void wgui_uce_initialize_editor(
                U8 *text_buffer,
                U16 text_buffer_size,
                U8 new_slide_number,
                U8 total_slide_number,
                wgui_uce_get_message_size_callback get_msg_size,
                wgui_uce_text_change_callback text_change);

extern void SetCategory280RightSoftkeyFunction(void (*f) (void), MMI_key_event_type k);
extern void ShowCategory280Screen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                wgui_uce_msg_type_enum msg_type,
                S16 input_method_type,
                U8 *gui_buffer);
#endif /* __WGUI_CATEGORIES_UCE_H__ */ 

