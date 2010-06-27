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
 * wgui_categories_ems.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for EMS category screens.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *********************************************************************************/

#ifndef __WGUI_CATEGORIES_EMS_H__
#define __WGUI_CATEGORIES_EMS_H__

#if(!UI_DISABLE_EMS_CATEGORY_SCREENS)

    #include "gui_config.h"
    #include "MMIDataType.h"
    #include "gui_ems.h"
    #include "wgui_categories.h"

    #ifdef __MMI_MESSAGES_EMS__
    #define CAT_144_DATA_FILE_SIZE  1600
    #endif 

    extern void RedrawCategory143Screen(void);
    extern void ShowCategory143Screen(
                    U16 title,
                    U16 title_icon,
                    U16 left_softkey,
                    U16 left_softkey_icon,
                    U16 right_softkey,
                    U16 right_softkey_icon,
                    EMSObject *object_list,
                    S32 *n_items,
                    S32 *index,
                    U8 *history_buffer);
    extern void ExitCategory143Screen(void);
    extern S32 GetCategory143HistorySize(void);
    extern U8 *GetCategory143History(U8 *history_buffer);
    extern S32 GetCategory143DataSize(void);
    extern U8 *GetCategory143Data(U8 *data);
    extern U8 GetCategory143DataType(void);
    extern void GetEMSObjectPDUSize(U8 *data, S32 *size);
    extern S32 GetEMSPredefinedObjectPDUSize(U32 object_type);
    extern void InsertEMSObjectUIHeader(U32 object_type, S32 object_size, U8 *source, U8 *destination);
    extern void RemoveEMSObjectUIHeader(U32 object_type, U8 *source, U8 *destination);
    extern void CreateCategory143ObjectList(EMSData *data, EMSObject **object_list);
    extern void FreeCategory143ObjectList(EMSObject **object_list);

    extern void RedrawCategory144Screen(void);
    extern void ShowCategory144Screen(
                    U8 *title,
                    U16 title_icon,
                    U16 left_softkey,
                    U16 left_softkey_icon,
                    U16 right_softkey,
                    U16 right_softkey_icon,
                    U32 object_type,
                    S32 n_items,
                    U8 **object_titles,
                    U16 *predefined_objects,
                    MMI_BOOL is_short_name,
                    U8 **userdefined_objects,
                    S32 *index,
                    U8 *history_buffer);
    extern void ExitCategory144Screen(void);
    extern S32 GetCategory144HistorySize(void);
    extern U8 *GetCategory144History(U8 *history_buffer);
    void RegisterCategory144ObjectLoader(U8 *(*f) (S32 index));

    extern void EMSObjectStopPlayBack(void);
    extern EMSTATUS EMSObjectPlayback(U32 object_type, U8 *data, S32 index);

    /* Call before EMSPack  */
    extern void EMS_ConvertAsciiEncodingToGSM7BitDefault(EMSData *data);
    extern void EMS_ConvertAsciiEncodingToGSM7BitDefaultWithExtended(EMSData *data);

    /* Call after EMSUnpack */
    extern void EMS_ConvertGSM7BitDefaultEncodingToAscii(EMSData *data);
    extern void EMS_ConvertGSM7BitDefaultEncodingToAsciiWithExtended(EMSData *data);

    extern MMI_BOOL is_EMS_inputbox_in_view_mode(void);
#define CAT145_BLACK_TITLE 0x00000000
#define CAT145_BLUE_TITLE  0x00000001
#define CAT145_RED_TITLE   0x00000002
#define CAT145_GREEN_TITLE 0x00000003

    extern void RedrawCategory145Screen(void);
    extern void ShowCategory145Screen(
                    U8 *title,
                    U16 title_icon,
                    U16 left_softkey,
                    U16 left_softkey_icon,
                    U16 right_softkey,
                    U16 right_softkey_icon,
                    U16 message_icon,
                    U8 *message_title,
                    U8 *message,
                    U32 flags,
                    U8 *history_buffer);
    extern void ExitCategory145Screen(void);
    extern S32 GetCategory145HistorySize(void);
    extern U8 *GetCategory145History(U8 *history_buffer);

#ifdef UI_SMALL_IMAGE_SELECTOR_SCREEN
#define UI_SMALL_IMAGE_SELECTOR_SHOW_VERTICAL_SCROLLBAR     0x00000001
#define UI_SMALL_IMAGE_SELECTOR_SHOW_HORIZONTAL_SCROLLBAR   0x00000002
#define MAX_IMAGE_SELECTOR_COL (6)
#define MAX_IMAGE_SELECTOR_ROW (4)
    extern void gui_enable_small_image_selector(void);
    extern void gui_disable_small_image_selector(void);
    extern BOOL gui_is_small_image_selector_set(void);
    extern void gui_enable_fixed_list_line_draw(void);
    extern void redraw_small_image_selector_images(void);
    extern void small_image_selector_goto_previous_row(void);
    extern void small_image_selector_goto_next_row(void);
    extern void small_image_selector_compute_row_col(S32 index, S32 *row, S32 *col);
    extern S32 small_image_selector_compute_next_row_image_index(S32 index);
    extern S32 small_image_selector_compute_previous_row_image_index(S32 index);
    extern void small_image_selector_key_handler(S32 vkey_code, S32 key_state);
    extern void ExitSmallImageSelectorScreen(void);
    extern void RedrawSmallImageSelectorScreen(void);
    extern void ShowImageSelectorScreen(
                    S8 *title,
                    U16 title_icon,
                    U16 left_softkey,
                    U16 left_softkey_icon,
                    U16 right_softkey,
                    U16 right_softkey_icon,
                    U32 object_type,
                    S32 n_items,
                    U8 **object_titles,
                    U16 *predefined_objects,
                    U8 **userdefined_objects,
                    S32 *index,
                    U8 *history_buffer);
    typedef struct _small_image_selector
    {
        S32 x, y;
        S32 width, height;
        S32 n_columns;
        S32 n_rows;
        S32 n_images;
        S32 first_displayed_column;
        S32 first_displayed_row;
        S32 first_displayed_image;
        S32 displayed_columns;
        S32 displayed_rows;
        S32 highlighted_column;
        S32 highlighted_row;
        S32 highlighted_image;
        S32 image_width;
        S32 image_height;
        vertical_scrollbar vbar;
        horizontal_scrollbar hbar;
        U32 flags;
        S32 h_gap;
        S32 v_gap;
    } small_image_selector_struct;
    extern void small_image_selector_configure_current_display(
                    small_image_selector_struct *s,
                    S32 new_highlighted_image);
    extern void associate_small_image_selector(small_image_selector_struct *s);
    extern void small_image_selector_auto_calculate(small_image_selector_struct *s);
    extern void small_image_selector_auto_configure(small_image_selector_struct *s);
    extern void small_image_selector_set_up(small_image_selector_struct *s, S32 n_images);
    extern U8 *GetCategory146History(U8 *history_buffer);
#endif /* UI_SMALL_IMAGE_SELECTOR_SCREEN */ 

#endif /* (!UI_DISABLE_EMS_CATEGORY_SCREENS) */ 

#endif /* __WGUI_CATEGORIES_EMS_H__ */ 


