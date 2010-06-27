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
 *  wgui_inline_edit.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  Functions for Inline items.
 *
 *  Author:
 * -------
 *  Leo Hu (MTK00563)
 *  Elvis Lin (MTK00560)
 *  Terry Yang (MTK00866)
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
/**
 * Copyright Notice
 * (c) 2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**********************************************************************************
   Filename:      wgui_inline_edit.h
   Author:        manju
   Date Created:  June-17-2003
   Contains:      Prototypes for inline editing
**********************************************************************************/

#ifndef __WGUI_INLINE_EDIT_H__
#define __WGUI_INLINE_EDIT_H__
#include "gui_config.h"
#include "FrameworkStruct.h"
#include "wgui_tab_bars.h"
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

#ifdef __MMI_TOUCH_SCREEN__

#include "kal_non_specific_general_types.h"
#include "TouchScreenGprot.h"

    typedef enum
    {
        GUI_INLINE_PEN_NONE,
        GUI_INLINE_PEN_NEED_REDRAW,
        GUI_INLINE_PEN_ITEM_SELECTED
    } gui_inline_pen_enum;

    typedef enum
    {
        GUI_INLINE_ITEM_PEN_NONE,
        GUI_INLINE_ITEM_PEN_NEED_REDRAW_ITEM,
        GUI_INLINE_ITEM_PEN_NEED_REDRAW_MENU,
        GUI_INLINE_ITEM_PEN_SELECTED
    } gui_inline_item_pen_enum;

#endif /* __MMI_TOUCH_SCREEN__ */ 

    /* Specific types of inline items   */

    typedef struct _wgui_inline_item_text_edit
    {
        U32 flags;
        U16 input_type;
        /* MTK Terry for 0x81 Encoding in Phone Book */
        U16 input_ext_type;
        U16 title;      /* Used only for full screen edit   */
        U16 title_icon; /* Used only for full screen edit   */
        U8 *buffer;
        S32 buffer_size;
        U8 *mask_buffer;
        U8 max_lines;
        void (*edit_complete_callback) (U8 *buffer, S32 buffer_size);
        S32 UCS2_count;
        void (*custom_setup_function) (void);
        void (*validation_callback) (UI_buffer_type text, UI_buffer_type cursor_p, S32 text_length);
        /* PMT  MANISH  START  20050722 */
    #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
        U8 *default_item_text;
    #endif 
        /* PMT  MANISH  END  20050722 */
    } wgui_inline_item_text_edit;

    typedef struct _wgui_inline_item_select
    {
        U32 flags;
        S32 n_items;
        S32 *highlighted_item;
        U8 **list_of_strings;
        void (*item_highlighted) (S32 item_index);
    } wgui_inline_item_select;

    typedef struct _wgui_inline_item_date
    {
        U32 flags;
        U8 *day_buffer;
        U8 *month_buffer;
        U8 *year_buffer;
        void (*string_construct_callback) (U8 *string_buffer, U8 *day_buffer, U8 *month_buffer, U8 *year_buffer);
    } wgui_inline_item_date;

    typedef struct _wgui_inline_item_time
    {
        U32 flags;
        U8 *hours_buffer;
        U8 *minutes_buffer;
        U8 *seconds_buffer;
        U8 *AM_PM_flag;
        void (*string_construct_callback) (U8 *string_buffer, U8 *hours_buffer, U8 *minutes_buffer, U8 *AM_PM_flag);
    } wgui_inline_item_time;

    typedef struct _wgui_inline_item_user_defined_select
    {
        U32 flags;
        U8 *current_text_p;
        U8 *(*current_item_callback) (void);
        U8 *(*previous_item_callback) (void);
        U8 *(*next_item_callback) (void);
    } wgui_inline_item_user_defined_select;

    typedef struct _wgui_inline_item_DOW_select
    {
        U32 flags;
        U8 *list_of_states;
    } wgui_inline_item_DOW_select;

    typedef struct _wgui_inline_item_time_period
    {
        U32 flags;
        U8 *hours_buffer1;
        U8 *minutes_buffer1;
        U8 *AM_PM_flag1;
        U8 *hours_buffer2;
        U8 *minutes_buffer2;
        U8 *AM_PM_flag2;
        void (*string_construct_callback) (U8 *string_buffer, U8 *hours_buffer1, U8 *minutes_buffer1,
                                           U8 *AM_PM_flag1, U8 *hours_buffer2, U8 *minutes_buffer2,
                                           U8 *AM_PM_flag2);
    } wgui_inline_item_time_period;

    typedef struct _wgui_inline_item_IP4
    {
        U32 flags;
        U8 *b1;
        U8 *b2;
        U8 *b3;
        U8 *b4;
        void (*string_construct_callback) (U8 *string_buffer, U8 *b1, U8 *b2, U8 *b3, U8 *b4);
    } wgui_inline_item_IP4;

    typedef struct _wgui_inline_item_color_select
    {
        U32 flags;
        U16 n_color;
        U16 highlighted_index;
        U16 start_index;
        color *list_of_color;
        void (*color_highlighted) (U16 index);
    } wgui_inline_item_color_select;

#define INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT     254

#define INLINE_ITEM_TYPE_MASK                0x000000FF
#define INLINE_ITEM_TYPE_CAPTION                0x00000001
#define INLINE_ITEM_TYPE_DISPLAY_ONLY           0x00000002
#define INLINE_ITEM_TYPE_TEXT_EDIT              0x00000003
#define INLINE_ITEM_TYPE_FULL_SCREEN_EDIT       0x00000004
#define INLINE_ITEM_TYPE_SELECT                 0x00000005
#define INLINE_ITEM_TYPE_USER_DEFINED_SELECT    0x00000006
#define INLINE_ITEM_TYPE_DATE                   0x00000007
#define INLINE_ITEM_TYPE_TIME                   0x00000008
#define INLINE_ITEM_TYPE_TIME_PERIOD            0x00000009
#define INLINE_ITEM_TYPE_DOW_SELECT             0x0000000A
#define INLINE_ITEM_TYPE_IP4_EDIT               0x0000000B
#define INLINE_ITEM_IMAGE_TEXT_TYPE             0x0000000C
#define INLINE_ITEM_ATTACH_IMAGE                0x0000000D
#if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__)
#define INLINE_ITEM_TYPE_MULTI_LINE_EDIT        0x0000000E
#define INLINE_ITEM_TYPE_MULTI_LINE_RD_ONLY     0x0000000F
#endif /* defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__) */ 
#define INLINE_ITEM_TYPE_COLOR_SELECT           0x00000010

#define INLINE_ITEM_DISABLED                    0x00000100
#define INLINE_ITEM_OPEN                        0x00000200
#define INLINE_ITEM_CHANGED                     0x00000400
#define INLINE_ITEM_NOT_HIGHLIGHTED             0x00000800
#define INLINE_ITEM_FOLLOW_DOWN                 0x00001000
#define INLINE_ITEM_FOLLOW_UP                   0x00002000
#define INLINE_ITEM_LEFT_ALIGN                  0x00004000
#define INLINE_ITEM_DISABLE_HIGHLIGHT           0x00008000
#define INLINE_ITEM_JUSTIFY_MASK                0x00030000
#define INLINE_ITEM_LEFT_JUSTIFY                0x00000000
#define INLINE_ITEM_RIGHT_JUSTIFY               0x00010000
#define INLINE_ITEM_CENTER_JUSTIFY              0x00020000
#define INLINE_ITEM_BOUNDARY_MASK               0x000C0000
#define INLINE_ITEM_BOUNDARY_ON_EDIT            0x00000000
#define INLINE_ITEM_BOUNDARY_ALWAYS             0x00040000
#define INLINE_ITEM_BOUNDARY_NEVER              0x00080000
#define INLINE_ITEM_DOTTED_UNDERLINE            0x00100000

    typedef struct _wgui_inline_item
    {
        U32 flags;
        S32 key_code;
        S32 key_event;
        U8 *text_p;
        PU8 side_img;
        U8 show_img_flag;
        void *item;
        void (*handler) (S32 x, S32 y, S32 width, S32 height, S32 key_code, S32 key_event, U8 **text_p, void *item,
                         U32 flags, U8 *history_buffer);
    } wgui_inline_item;

    typedef wgui_inline_item InlineItem;

#define MAX_INLINE_ITEMS   32
    extern wgui_inline_item wgui_inline_items[MAX_INLINE_ITEMS];
    extern wgui_inline_item *current_wgui_inline_item;

#ifdef __MMI_TOUCH_SCREEN__
    extern BOOL UI_dummy_inline_item_pen_function(
                    mmi_pen_event_type_enum pen_event,
                    S16 x,
                    S16 y,
                    gui_inline_item_pen_enum *item_event);
    extern BOOL gui_inline_translate_pen_event(
                    fixed_list_menu *m,
                    mmi_pen_event_type_enum pen_event,
                    S16 x,
                    S16 y,
                    gui_inline_pen_enum *inline_event);
#endif /* __MMI_TOUCH_SCREEN__ */ 

    extern void SetInlineItemActivation(InlineItem *item, S32 key_code, S32 key_event);
    extern void SetInlineItemTextEdit(InlineItem *item, U8 *buffer, S32 buffer_size, S16 input_type);
    void RegisterInlineTextEditCompleteHandler(InlineItem *item, void (*f) (U8 *string, S32 buffer_size));
    void RegisterInlineTextEditValidationFunction(InlineItem *item,
                                                  void (*f) (U8 *buffer, U8 *cursor, S32 text_length));
    void SetInlineTextEditCustomFunction(InlineItem *item, void (*f) (void));
    extern void SetInlineItemDisplayOnly(InlineItem *item, U8 *text_p);
    extern void SetInlineItemCaption(InlineItem *item, U8 *text_p);
    extern void SetInlineItemFullScreenEdit(
                    InlineItem *item,
                    U16 title,
                    U16 title_icon,
                    U8 *buffer,
                    S32 buffer_size,
                    S16 input_type);
    /* MTK Terry for 0x81 Encoding in Phone Book */
    extern void SetInlineItemFullScreenEdit_ext(
                    InlineItem *item,
                    U16 title,
                    U16 title_icon,
                    U8 *buffer,
                    S32 buffer_size,
                    S16 input_type,
                    S16 input_extended_type);
    void RegisterInlineFullScreenEditCompleteHandler(InlineItem *item, void (*f) (U8 *string, S32 buffer_size));
    void SetInlineFullScreenEditCustomFunction(InlineItem *item, void (*f) (void));
    void RegisterInlineFullScreenEditValidationFunction(InlineItem *item,
                                                        void (*f) (U8 *buffer, U8 *cursor, S32 text_length));
    extern void SetInlineItemSelect(InlineItem *item, S32 n_items, U8 **list_of_items, S32 *highlighted_item);
    void RegisterInlineSelectHighlightHandler(InlineItem *item, void (*f) (S32 item_index));
    extern S32 GetInlineSelectHighlightedItem(void);
    void SetInlineItemDate(InlineItem *item, U8 *day_buffer, U8 *month_buffer, U8 *year_buffer,
                           void (*f) (U8 *string_buffer, U8 *day_buffer, U8 *month_buffer, U8 *year_buffer));
    void SetInlineItemTime(InlineItem *item, U8 *hours_buffer, U8 *minutes_buffer, U8 *AM_PM_flag,
                           void (*f) (U8 *string_buffer, U8 *hours_buffer, U8 *minutes_buffer, U8 *AM_PM_flag));
    void SetInlineItemUserDefinedSelect(InlineItem *item, U8 *(*current_item_callback) (void),
                                        U8 *(*previous_item_callback) (void), U8 *(*next_item_callback) (void));
    extern void SetInlineItemDOWSelect(InlineItem *item, S32 item_index, U8 *list_of_states);
    void SetInlineItemTimePeriod(InlineItem *item, U8 *hours_buffer1, U8 *minutes_buffer1, U8 *AM_PM_flag1,
                                 U8 *hours_buffer2, U8 *minutes_buffer2, U8 *AM_PM_flag2,
                                 void (*f) (U8 *string_buffer, U8 *hours_buffer1, U8 *minutes_buffer1,
                                            U8 *AM_PM_flag1, U8 *hours_buffer2, U8 *minutes_buffer2,
                                            U8 *AM_PM_flag2));
    void SetInlineItemIP4(InlineItem *item, U8 *b1, U8 *b2, U8 *b3, U8 *b4,
                          void (*f) (U8 *string_buffer, U8 *b1, U8 *b2, U8 *b3, U8 *b4));
    void SetInlineItemColorSelect(InlineItem *item, S32 n_color, U16 highlighted_index, color *list_of_color,
                                  void (*color_highlighted) (U16 index));
    extern void SetInlineItemFollowUp(InlineItem *item, S32 index);
    extern void SetInlineItemFollowDown(InlineItem *item, S32 index);
    extern void DisableInlineItem(InlineItem *item, S32 index);
    extern void EnableInlineItem(InlineItem *item, S32 index);
    extern S32 GetInlineEditUCS2Count(InlineItem *i);
    extern void SetInlineItemFullWidth(InlineItem *i);
    extern void LeftJustifyInlineItem(InlineItem *i);
    extern void RightJustifyInlineItem(InlineItem *i);
    extern void CenterJustifyInlineItem(InlineItem *i);
    extern void DisableInlineItemBoundary(InlineItem *i);
    extern void EnableInlineItemBoundary(InlineItem *i);
    extern void DisableInlineItemHighlight(InlineItem *i);
    extern void SetInlineItemDottedUnderline(InlineItem *i);

    extern void ReConfigureInlineItemDisplayOnly(InlineItem *item, U8 *text_p);
    extern void ReconfigureInlineItemCaption(InlineItem *item, U8 *text_p);
    extern void ReConfigureInlineItemTextEdit(InlineItem *item, U8 *buffer, S32 buffer_size, S16 input_type);
    extern void ReConfigureInlineItemFullScreenEdit(
                    InlineItem *item,
                    U16 title,
                    U16 title_icon,
                    U8 *buffer,
                    S32 buffer_size,
                    S16 input_type);
    extern void ReConfigureInlineItemSelect(
                    InlineItem *item,
                    S32 n_items,
                    U8 **list_of_items,
                    S32 *highlighted_item);
    void ReConfigureInlineItemDate(InlineItem *item, U8 *day_buffer, U8 *month_buffer, U8 *year_buffer,
                                   void (*f) (U8 *string_buffer, U8 *day_buffer, U8 *month_buffer,
                                              U8 *year_buffer));
    void ReConfigureInlineItemTime(InlineItem *item, U8 *hours_buffer, U8 *minutes_buffer, U8 *AM_PM_flag,
                                   void (*f) (U8 *string_buffer, U8 *hours_buffer, U8 *minutes_buffer,
                                              U8 *AM_PM_flag));
    void ReConfigureInlineItemUserDefinedSelect(InlineItem *item, U8 *(*current_item_callback) (void),
                                                U8 *(*previous_item_callback) (void),
                                                U8 *(*next_item_callback) (void));
    extern void ReConfigureInlineItemDOWSelect(InlineItem *item, S32 item_index, U8 *list_of_states);
    void ReConfigureInlineItemTimePeriod(InlineItem *item, U8 *hours_buffer1, U8 *minutes_buffer1, U8 *AM_PM_flag1,
                                         U8 *hours_buffer2, U8 *minutes_buffer2, U8 *AM_PM_flag2,
                                         void (*f) (U8 *string_buffer, U8 *hours_buffer1, U8 *minutes_buffer1,
                                                    U8 *AM_PM_flag1, U8 *hours_buffer2, U8 *minutes_buffer2,
                                                    U8 *AM_PM_flag2));
    void ReConfigureInlineItemIP4(InlineItem *item, U8 *b1, U8 *b2, U8 *b3, U8 *b4,
                                  void (*f) (U8 *string_buffer, U8 *b1, U8 *b2, U8 *b3, U8 *b4));

    extern void inline_edit_singleline_inputbox_delete_in_pos(S32 pos);
    extern void inline_edit_singleline_inputbox_direct_input_in_pos(UI_character_type c, S32 pos);
    
    extern U8 GetInlineDoneFlag(U8 *history_buffer);
    extern void SetInlineDoneFlag(U8 *history_buffer);
    extern void ResetInlineDoneFlag(U8 *history_buffer);
    extern void DisableInlineInputMethodHints(void);

    /* PMT  MANISH  START  20050722 */
#ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
    extern void SetInlineItemTextEditDefaultItemNameIfEmpty(InlineItem *item, U16 default_text_id);
    extern void EnableInlineItemDefaultText(void);
    extern void DisableInlineItemDefaultText(void);
    extern U8 IsInlineItemDefaultTextEnable(void);
#endif /* __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__ */ 
    /* PMT  MANISH  END  20050722 */

    extern void Category57ChangeItemText(S32 index, U8 *text);
    extern void Category57ChangeItemIcon(S32 index, U16 image_ID);
    extern void DisableCategory57ScreenDone(void);
    extern void EnableCategory57ScreenDone(void);
    extern void InitializeCategory57Screen(void);
    extern void RedrawCategory57Screen(void);
    extern void ShowCategory57Screen(
                    U16 title,
                    U16 title_icon,
                    U16 left_softkey,
                    U16 left_softkey_icon,
                    U16 right_softkey,
                    U16 right_softkey_icon,
                    S32 number_of_items,
                    U16 *list_of_icons,
                    InlineItem *list_of_items,
                    S32 highlighted_item,
                    U8 *history_buffer);
    extern void ExitCategory57Screen(void);
    
    extern void ExitCategory657Screen(void);
    
    extern void ShowCategory657Screen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S32 number_of_items,
                U16 *list_of_icons,
                InlineItem *list_of_items,
                S32 highlighted_item,
                S8 highlighted_tab,                
                U8 *history_buffer);
    
    extern U8 *GetCategory57History(U8 *history_buffer);
    extern S32 GetCategory57HistorySize(void);
    void SetCategory57RightSoftkeyFunctions(void (*done_function) (void), void (*back_function) (void));
    void SetCategory57LeftSoftkeyFunction(void (*LSK_function) (void));
    extern S32 GetCategory57DataSize(void);
    extern U8 *GetCategory57Data(U8 *data);
    extern void SetCategory57Data(InlineItem *list_of_items, S32 number_of_items, U8 *data);
    extern void CloseCategory57Screen(void);
    extern void set_wgui_inline_list_menu_changed(void);
    void Category57AppendTopInfoBox(U16 num_of_info_box_rows,
                                    void (*draw_info_callback) (S32 idx, S32 x1, S32 y1, S32 x2, S32 y2),
                                    void (*hide_info_callback) (S32 idx), BOOL is_draw_once);

    extern void Category157ChangeItemText(S32 index, U8 *text);
    extern void Category157ChangeItemIcon(S32 index, U16 image_ID);
    extern void DisableCategory157ScreenDone(void);
    extern void InitializeCategory157Screen(void);
    extern void RedrawCategory157Screen(void);
    extern void ShowCategory157Screen(
                    U8 *title,
                    U16 title_icon,
                    U16 left_softkey,
                    U16 left_softkey_icon,
                    U16 right_softkey,
                    U16 right_softkey_icon,
                    S32 number_of_items,
                    U16 *list_of_icons,
                    InlineItem *list_of_items,
                    S32 highlighted_item,
                    U8 *history_buffer);
    extern void ExitCategory157Screen(void);
    extern U8 *GetCategory157History(U8 *history_buffer);
    extern S32 GetCategory157HistorySize(void);
    void SetCategory157RightSoftkeyFunctions(void (*done_function) (void), void (*back_function) (void));
    void SetCategory157LeftSoftkeyFunction(void (*LSK_function) (void));
    extern S32 GetCategory157DataSize(void);
    extern U8 *GetCategory157Data(U8 *data);
    extern void SetCategory157Data(InlineItem *list_of_items, S32 number_of_items, U8 *data);
    extern void CloseCategory157Screen(void);

    /* Max: function to set RSK to "Clear" */
    extern void SetCategory57ScreenRSKClear(void);
    extern void ShowCategory257Screen(
                    U16 title,
                    U16 title_icon,
                    U16 left_softkey,
                    U16 left_softkey_icon,
                    U16 right_softkey,
                    U16 right_softkey_icon,
                    U16 ImgId,
                    S32 number_of_items,
                    U16 *list_of_icons,
                    InlineItem *list_of_items,
                    S32 highlighted_item,
                    U8 *history_buffer);

    extern void ShowCategory357Screen(
                    U16 title,
                    U16 title_icon,
                    U16 left_softkey,
                    U16 left_softkey_icon,
                    U16 right_softkey,
                    U16 right_softkey_icon,
                    U16 ImgId,
                    S32 number_of_items,
                    U16 *list_of_icons,
                    InlineItem *list_of_items,
                    S32 highlighted_item,
                    U8 *history_buffer);

    /* Image text */

    typedef struct _wgui_inline_image_text
    {
        U32 flags;
        PU8 image1;
        PU8 image2;
        U8 *text;
        S32 buffer_size;
        PU8 image3;
        S32 UCS2_count;
        S32 x, y, width, height;
        wgui_inline_item_text_edit *inline_full_text;

    #ifdef __MMI_TOUCH_SCREEN__
        /* Only support callback of image2 and image3 */
        FuncPtr image_callback[2];
        mmi_pen_point_struct image_left_top[2];
        mmi_pen_point_struct image_right_bottom[2];
        S16 pen_down_image_index;
        S16 pen_curr_pressed_image_index;
    #endif /* __MMI_TOUCH_SCREEN__ */ 
    } wgui_inline_image_text;

    /* Image attachments */

#define MMI_ATTACHMENT_FILE_NAME_SIZE           12 * ENCODING_LENGTH

    /* Same as MMI_EMAIL_MAX_NUM_ATTACH */
#define MAX_IMAGES_IN_INLINE_ATTACHMENT         3

    typedef struct _wgui_inline_images_detail
    {
        U8 image_file_name[MMI_ATTACHMENT_FILE_NAME_SIZE];
        U8 type_of_image;
        PU8 image1;
    } wgui_inline_images_detail;

    typedef struct _wgui_inline_image_attachment    /* vandi */
    {
        U32 flags;
        U16 title;
        U16 title_icon;
        wgui_inline_images_detail attach_image[MAX_IMAGES_IN_INLINE_ATTACHMENT];
        PU8 image1;
        PU8 image2;
        PU8 image3;
        U16 control_x1;
        U16 control_y1;
        U16 control_width;
        U16 control_height;
        S16 highlited_image;
    #ifdef __MMI_TOUCH_SCREEN__
        S16 highlight_changed;
        mmi_pen_point_struct image_left_top[MAX_IMAGES_IN_INLINE_ATTACHMENT];
        mmi_pen_point_struct image_right_bottom[MAX_IMAGES_IN_INLINE_ATTACHMENT];
    #endif /* __MMI_TOUCH_SCREEN__ */ 
        void (*lsk_function) (PU8, UI_string_type str);
        void (*rsk_function) (PU8, UI_string_type str);
        void (*image_change_cb)(S32 index);

    } wgui_inline_image_attachment;

    extern void RegisterAttachmentLskFunction(InlineItem *item, void (*f) (PU8 image, UI_string_type str));
    extern void RegisterAttachmentRskFunction(InlineItem *item, void (*f) (PU8 image, UI_string_type str));
    extern void RegisterAttachmentHighlightedFunction (InlineItem * item, void (*f)(S32 index));
    extern void SetInlineItemImageAttachment(
                    InlineItem *item,
                    PU8 image1,
                    PU8 image2,
                    PU8 image3,
                    U16 title,
                    U16 title_icon,
                    U8 highlight_image);

    extern void ShowAsControl(InlineItem *item);
    extern void SetInlineFullScreenEditCustomFunctionImageText(InlineItem *item, void (*f) (void));
    extern void SetInlineItemImageText(
                    InlineItem *item,
                    U8 *text,
                    PU8 image1,
                    PU8 image2,
                    PU8 image3,
                    S32 buf_size,
                    U16 title,
                    U16 title_icon,
                    S16 input_type);
#ifdef __MMI_TOUCH_SCREEN__
    extern void SetInlineImageTextPenHandler(InlineItem *item, FuncPtr image2_callback, FuncPtr image3_callback);
#endif 
    extern void ClearAttachmentImage(InlineItem *item, S32 index);
    extern void AddEmailImageAttachmentUI(InlineItem *item, wgui_inline_images_detail *image_details);
    extern void ClearAllAttachmentImages(InlineItem *item, S32 attachments_present);
    extern void SetHighlightedAttachment(wgui_inline_item *inline_item, S32 index);

    /* Function Decleration Added For Old Functions In Header File - Gurinder 15/4/2004 */
    extern S32 get_wgui_inline_list_menu_status(void);
    extern void set_wgui_inline_list_menu_status(S32 status);
    extern void execute_wgui_inline_edit_RSK_function(void);
    extern void execute_wgui_inline_edit_LSK_function(void);

    /* Pixtel - Gurinder 2/6/04. Signatures for MultiLine Input Box Inscreen Control. */
#if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__)
    extern void SetInlineItemMultiLineEdit(InlineItem *item, U8 *buffer, U8 *title, S32 buffer_size, S16 input_type);
    void SetInlineMultiLineEditCustomFunction(InlineItem *item, void (*f) (void));
    extern void handle_inline_multi_line_edit(
                    S32 x,
                    S32 y,
                    S32 width,
                    S32 height,
                    S32 key_code,
                    S32 key_event,
                    U8 **text_p,
                    void *item,
                    U32 flags,
                    U8 *history_buffer);
    extern void wgui_show_inline_inscreen_multi_line_edit(
                    S32 x1,
                    S32 y1,
                    S32 width,
                    S32 height,
                    wgui_inline_item *item);
    extern void gui_draw_inscreen_multi_line_input_box_title(S32 x1, S32 y1, S32 x2, S32 y2);
    extern void handle_inline_multi_line_edit_complete(void);
    extern void handle_inline_full_screen_edit_close(void);
    extern void inline_multiline_edit_complete(void);
    extern S8 MMI_multi_line_inputbox_present;
    extern void handle_inline_multi_line_rd_only(
                    S32 x,
                    S32 y,
                    S32 width,
                    S32 height,
                    S32 key_code,
                    S32 key_event,
                    U8 **text_p,
                    void *item,
                    U32 flags,
                    U8 *history_buffer);
    extern void wgui_show_inline_multi_line_rd_only(S32 x1, S32 y1, S32 width, S32 height, wgui_inline_item *item);
    extern void SetInlineMultiLineRdOnly(InlineItem *item, U8 *buffer, S32 buffer_size, U16 input_type, U8);
    /* Gurinder - 5/5/2004 Inline Multiline Box History Control */
    extern void set_inscreen_multi_line_input_box_changed(void);
    extern void reset_inscreen_multi_line_input_box_changed(void);
    extern S32 menu_item_inline_multiline_box(void);
#endif /* defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__) */ 
    /* End Pixtel */
    extern void SetInlineListMenuChanged(void);
    extern S32 GetInlineListMenuChanged(void);
#ifdef __MMI_DRAW_MANAGER__
    /* For Draw Manager  */
    extern U8 *wgui_get_inline_history(U16 history_ID, U8 *history_buffer);
    extern S32 wgui_get_inline_history_size(void);
#endif /* __MMI_DRAW_MANAGER__ */ 
    //PMT VIKAS START 20050630
    //No need of this declaration. Remove this.
    //PMT VIKAS START 20050524
    //#ifdef __MMI_UI_TRANSPARENT_EFFECT__
    //   void gui_inline_edit_disable_transparent_effect(horizontal_select   *m);
    //#endif
    //PMT VIKAS END
    //PMT VIKAS END 20050630
#ifdef __cplusplus
}
#endif 

void RegisterInlineItemChangedNotification(void (*callback) (U16 index));
extern void ResetInlineItemChangedNotification(void);

extern U8 *wgui_inline_edit_get_current_item_history(U8 *history_buffer);
extern void wgui_update_inline_data(void);

#endif /* __WGUI_INLINE_EDIT_H__ */ 

