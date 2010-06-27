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
 * widget_struct.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  Data structure of widget
 *
 * Author:
 * -------
 * -------
 * -------
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

/*************************************************************************
 * Internal definition
 *************************************************************************/

#define WIDGET_FORM_FLAG_DISABLE_GADGET_BORDER     (1<<0)
#define WIDGET_FORM_FLAG_DISABLE_SCROLLING         (1<<1)       /* Deprecated */
#define WIDGET_FORM_FLAG_SHOW_UP_ARROW             (1<<2)
#define WIDGET_FORM_FLAG_SHOW_DOWN_ARROW           (1<<3)
#define WIDGET_FORM_FLAG_SHOW_LEFT_ARROW           (1<<4)
#define WIDGET_FORM_FLAG_SHOW_RIGHT_ARROW          (1<<5)

#define WIDGET_MENU_FLAG_PROFILE_STYLE             (1<<0)
#define WIDGET_MENU_FLAG_TOO_MANY_ITEMS            (1<<1)

typedef enum
{
    WIDGET_DRAW_OP_LINE,
    WIDGET_DRAW_OP_RECT,
    WIDGET_DRAW_OP_STRING,
    WIDGET_DRAW_OP_POLYGON,
    WIDGET_DRAW_OP_IMAGE
} widget_draw_op_enum;

typedef struct widget_draw_op_struct
{
    struct widget_draw_op_struct *next;
    widget_draw_op_enum type;
    union
    {
        struct
        {
            MsfPosition start;
            MsfPosition end;
            MsfColor color; /* Hack for SMTR underline color! We do not want to enqueue the whole style */
        } line;
        struct
        {
            MsfPosition position;
            MsfSize size;
            int fill;
        #ifdef WIDGET_DRAW_RECT_STORE_STYLE
            MsfColor fg_color;
            MsfColor bg_color;
        #endif /* WIDGET_DRAW_RECT_STORE_STYLE */ 
        } rect;
        struct
        {
            MsfStringHandle string; /* Dynamically allocated */
            MsfPosition position;
            MsfSize maxSize;
        #ifndef WIDGET_COMPACT_IMAGE_DRAW_OP
            int index;
            int nbrOfChars;
        #endif /* WIDGET_COMPACT_IMAGE_DRAW_OP */ 
            int baseline;
            int useBrushStyle;
        } string;
        struct
        {
            int nbrOfCorners;
            MSF_INT16 *corners; /* Dynamically allocated */
            int fill;
        } polygon;
        struct
        {
            MsfImageHandle image;
            MsfPosition position;
            MsfSize *maxSize;
            MsfImageZoom imageZoom;
        } image;
    } _u;
} widget_draw_op_struct;

typedef enum
{
    WIDGET_PAINT_CMD_TITLE,
    WIDGET_PAINT_CMD_GADGET
#ifdef WIDGET_SMIL_SLIDING_BAR
        , WIDGET_PAINT_CMD_SLIDING_BAR
#endif 
} widget_paint_command_enum;

#ifdef WIDGET_PRECACHE_IMAGE
typedef enum
{
    WIDGET_PRECACHE_IMAGE_NONE = 0,
    WIDGET_PRECACHE_IMAGE_ACCEPT
} widget_precache_image_enum;
#endif /* WIDGET_PRECACHE_IMAGE */ 

struct widget_header_struct;

typedef struct widget_paint_command_struct
{
    widget_paint_command_enum type;
    /* Target MsfGagdet (For WIDGET_PAINT_CMD_GADGET) */
    struct widget_header_struct *gadget;
    /* Next paint command in queue */
    struct widget_paint_command_struct *next;
} widget_paint_command_struct;

#ifdef WIDGET_SLIDING_SMIL_SUPPORT

/*
 * Hold information of a SMIL player supporting scrolling in a MsfForm. 
 * * widget_sliding_info_struct.text_scroll_offset + (-WGUI_CTX->curr_display_pos) is the real offset.
 * * Text scrolling (widget_sliding_info_struct.text_scroll_offset) is controlled by SMA module.
 */
typedef struct
{
    /* Image on top or text on top */
    kal_uint8 image_on_top;
    /* We need to restore WGUI_CTX->current_pos because it is not stored in MsfWindow */
    kal_uint8 restore_scroll_offset_before_paint;
    /* Original scroll offset when the form losts focus  (WGUI_CTX->current_pos.y) */
    kal_int16 scroll_offset_backup;
    /* Maximum possible height of text area (not exceeding screen height) */
    kal_int16 max_text_gadget_height;
#ifdef WIDGET_SLIDING_SMIL_VBAR
    /* real height of text gadget ( < screen height) */
    kal_int32 text_gadget_height;
    /* Real height of text. It might be larger than screen height. Provided by SMA module */
    kal_int32 total_text_height;
    /* the single text line height */
    kal_int32 text_line_height;
    /* Scroll offset of text area. Provided by SMA module */
    kal_int32 text_scroll_offset;
    /* Total height without text (height of gadgets - text gadget height) */
    kal_int32 total_height_without_text;
    /* Total height (height of gadgets - text gadget height + total_text_height) */
    kal_int32 total_height;
    /* Veritcal scrollbar */
    MsfGadgetHandle vbar;
#ifdef __MMI_TOUCH_SCREEN__
    /* Scroll notification handler (executed in WAP task) */
    void (*text_scroll_notification_hdlr) (void);
#endif /* __MMI_TOUCH_SCREEN__ */ 
#endif /* WIDGET_SLIDING_SMIL_VBAR */ 
} widget_sliding_info_struct;

#endif /* WIDGET_SLIDING_SMIL_SUPPORT */ 

#ifdef __MMI_TOUCH_SCREEN__

typedef struct
{
    /* Scroll offset of text area in mixed MMS viewer */
    kal_int32 text_scroll_offset;
    /* Veritcal scrollbar */
    MsfGadgetHandle vbar;
    /* Scroll notification handler (executed in WAP task) */
    void (*text_scroll_notification_hdlr) (void);

} widget_MOB_pen_struct;

#endif /* __MMI_TOUCH_SCREEN__ */ 


typedef struct
{
    kal_uint16 prev_botton_img;
    kal_int16 prev_botton_x;
    kal_int16 prev_botton_y;
    kal_uint16 next_botton_img;
    kal_int16 next_botton_x;
    kal_int16 next_botton_y;
    kal_int16 button_width;
    kal_int16 button_height;
    kal_uint32 pen_by_prev_button:1;
    kal_uint32 pen_by_next_button:1;
    kal_uint32 prev_button_pressed:1;
    kal_uint32 next_button_pressed:1;

}widget_MMS_viewer_title_struct;


/* Blinking Text */
typedef struct
{
    /* The corresponding MsfStringGadget is displayed. */
    kal_uint8 displayed;
    /* Background color */
    MsfColor bgcolor;
} widget_blinking_struct;

/* Marquee */
typedef struct
{
    /*
     * All marquee object are linked in WGUI_CTX->marquee_head, but only 
     * * "displayed" marquee are animated.
     */

    /* 
     * Parameter in HDIa_widgetSetMarquee()
     */
    MsfMarqueeType marqueeType;
    int direction;
    int repeat;
    int scrollAmount;
    int scrollDelay;

    /* 
     * Internal 
     */
    /* The corresponding MsfImageGadget is displayed */
    kal_uint8 displayed;
    /* Disabled after looping is finished */
    kal_bool enabled;
    /* Is a new loop */
    kal_bool is_new_loop;
    /* 0: left-to-right. 1: right-to-left. Used in case like MsfMarqueeAlternative */
    kal_uint8 curr_direction;
    /* Number of loops finished */
    kal_int16 loop_count;
    /* Current position */
    kal_int16 x_offset, y_offset;
    /* Used to control marquee speed */
    kal_uint32 elapsed_time;
} widget_marquee_struct;

/*************************************************************************
 * Widgets
 *
 * Note: fields should be adjusted to 4-byte alignment in order to reduce runtime memory
 *************************************************************************/

#define S_BASIC_HEADER                                         \
   /* widget_data_type_enum */                                 \
   kal_uint8                  data_type;                       \
   /* WIDGET_FLAG_XXX   */                                     \
   kal_uint8                  flag;                            \

#ifdef WIDGET_COMPACT_RUNTIME_STRUCT

/* The size of S_HEADER is (4 * n + 2) */
#define S_HEADER                                               \
   S_BASIC_HEADER                                              \
   /* Owner module */                                          \
   kal_uint8                        module_id;                 \
   /* Reference count. Release the widget when it reachs 0 */  \
   kal_uint8                        parent_cnt;                \
   /* Chain objects by module for HDIa_widgetReleaseAll() */   \
   struct widget_header_struct      *next_memory_block;        \
   /* The owner of this widget object */                       \
   struct widget_header_struct      *parent;                   \
   /* Point to an array containing child widget objects */     \
   struct widget_header_struct      **childs;                  \
   /* Current number of widgets in 'childs' array */           \
   kal_uint16                       childs_sum;                \
   /* Size of 'childs' array.  */                              \
   kal_uint16                       max_childs_sum;            \

#else /* WIDGET_COMPACT_RUNTIME_STRUCT */ 

#define S_HEADER                                               \
   S_BASIC_HEADER                                              \
   struct widget_header_struct      *next_memory_block;        \
   struct widget_header_struct      *parent;                   \
   struct widget_header_struct      **childs;                  \
   kal_uint8                        module_id;                 \
   kal_uint8                        parent_cnt;                \
   kal_uint16                       childs_sum;                \
   kal_uint16                       max_childs_sum;            \

#endif /* WIDGET_COMPACT_RUNTIME_STRUCT */ 

#ifdef WIDGET_COMPACT_RUNTIME_STRUCT

#define S_WINDOW                                               \
   /* attribute */                                             \
   kal_uint32                       total_action_mask;         \
   kal_uint32                       event_mask;                \
   kal_uint32                       event_override;            \
   kal_uint32                       accesskey;                 \
   kal_uint32                       accesskey_override;        \
   MsfStyleHandle                   style;                     \
   MsfPosition                      position;                  \
   /* MsfAlignment                  alignment;  */             \
   /* MsfStringHandle               ticker;  */                \
   int                              property_mask;             \
   MsfStringHandle                  title;                     \
   /* layout variables */                                       \
   /* MsfSize                       minimal_size; */           \
   /* MsfSize                       editable_size; */          \
   MsfSize                          size;                      \
   /* MsfLineStyle                  border_style;  */          \
   /* MsfDecoration                 decoration; */             \

#else /* WIDGET_COMPACT_RUNTIME_STRUCT */ 

#define S_WINDOW                                               \
   /* attribute */                                             \
   kal_uint32                       total_action_mask;         \
   kal_uint32                       event_mask;                \
   kal_uint32                       event_override;            \
   kal_uint32                       accesskey;                 \
   kal_uint32                       accesskey_override;        \
   MsfStyleHandle                   style;                     \
   MsfPosition                      position;                  \
   MsfAlignment                     alignment;                 \
   MsfStringHandle                  ticker;                    \
   int                              property_mask;             \
   MsfStringHandle                  title;                     \
   /* layout variables */                                       \
   MsfSize                          minimal_size;              \
   MsfSize                          editable_size;             \
   MsfSize                          size;                      \
   MsfLineStyle                     border_style;              \
   MsfDecoration                    decoration;                \

#endif /* WIDGET_COMPACT_RUNTIME_STRUCT */ 

struct widget_gadget_string_struct;

#define S_GADGET_STRING                                        \
   kal_bool                         is_single_line;            \
   MsfStringHandle                  text;                      \
   widget_blinking_struct           *blinking;                 \
   struct widget_gadget_string_struct  *blinking_next;         \

#ifdef WIDGET_COMPACT_RUNTIME_STRUCT

#define S_ACTION                                               \
   kal_uint16                       property_mask;             \
    int                             priority;                  \
   kal_uint32                       action_mask;               \
   MsfStringHandle                  text;                      \

#else /* WIDGET_COMPACT_RUNTIME_STRUCT */ 

#define S_ACTION                                               \
   int                              priority;                  \
   kal_uint32                       action_mask;               \
   kal_uint16                       property_mask;             \
   MsfStringHandle                  text;                      \

#endif /* WIDGET_COMPACT_RUNTIME_STRUCT */ 

#define S_EDITOR                                                                  \
   /* input_max_size does not include terminating char '\0' */                    \
   int                              input_max_size;                               \
   int                              index;                                        \
   MsfColor                         color;                                        \
   MsfStringHandle                  text;                                         \
   MsfFont                          font;                                         \
   MsfTextProperty                  text_property;                                \
   MsfTextType                      text_type;                                    \
   kal_uint8                        format_pattern[WIDGET_MAX_FORMAT_PATTERN_LEN];\
   kal_int8                         is_input_required;                            \
   kal_bool                         is_single_line;                               \
   kal_bool                         is_readonly;                                  \
   kal_bool                         is_string_gadget_emulation;                   \

#define S_GADGET_INPUT              S_EDITOR

#ifdef WIDGET_COMPACT_RUNTIME_STRUCT

#define S_STRING                                               \
   MsfStyleHandle                   style;                     \
   widget_raw_data_struct           *raw;                      \

#else /* WIDGET_COMPACT_RUNTIME_STRUCT */ 

#define S_STRING                                               \
   MsfStringFormat                  string_format;             \
   MsfStyleHandle                   style;                     \
   widget_raw_data_struct           *raw;                      \

#endif /* WIDGET_COMPACT_RUNTIME_STRUCT */ 

#define S_RAW_DATA                                             \
   int                              size;                      \
   /* Used in widget_read_image_from_file_to_raw_data() */     \
   int                              used_size;                 \
   kal_uint8                        data[1];                   \

#define S_MENU                                                 \
   MsfChoiceType                    choice_type;               \
   MsfElementPosition               element_position;          \
   int                              element_bitmask;           \
   int                              menu_items_sum;            \
   MsfMenuExtHighlightHandle        highlight_handler;         \
   U8*                              checkbox_menu_list_state;  \
   int                              highlight_index;           \
   int                              first_displayed_item;      \
   int                              last_displayed_item;       \
   kal_uint32                       menu_flags;                \
   /* HACK. used with WIDGET_MENU_FLAG_PROFILE_STYLE  */       \
   int                              profile_activated_index;   \

#ifdef __MMI_TOUCH_SCREEN__
#define S_FORM_MOB_PEN              widget_MOB_pen_struct      mob_pen_info;
#else 
#define S_FORM_MOB_PEN
#endif 

#ifdef WIDGET_SLIDING_SMIL_SUPPORT

#define S_FORM                                                 \
   kal_uint32                       form_flags;                \
   /* Total seconds for  SMIL */                               \
   kal_int16                        total_sec;                 \
   /* Remaining seconds for SMIL */                            \
   kal_int16                        remain_sec;                \
   widget_MMS_viewer_title_struct   *MMs_view_title;           \
   widget_sliding_info_struct       *sliding_info;             \
   S_FORM_MOB_PEN

#else /* WIDGET_SLIDING_SMIL_SUPPORT */ 

#define S_FORM                                                 \
   kal_uint32                       form_flags;                \
   /* Total seconds for  SMIL */                               \
   kal_int16                        total_sec;                 \
   /* Remaining seconds for  SMIL */                           \
   kal_int16                        remain_sec;                \
   widget_MMS_viewer_title_struct   *MMs_view_title;           \
   S_FORM_MOB_PEN

#endif /* WIDGET_SLIDING_SMIL_SUPPORT */ 

struct widget_gadget_image_struct;

#define S_GADGET_IMAGE                                         \
   MsfImageHandle                   image;                     \
   MsfImageZoom                     zoom;                      \
   widget_marquee_struct            *marquee;                  \
   struct widget_gadget_image_struct *marquee_next;            \
   MsfPosition                      border_offset;             \
   MsfSize                          border_size;               \

#define S_GADGET_DATE                                          \
   MsfDateTimeType                  datetime_type;             \
   MsfDate                          date;                      \
   MsfTime                          time;                      \

#define S_GADGET_BAR                                           \
   MsfBarType                       bar_type;                  \
   int                              max_value;                 \
   int                              value;                     \
   int                              pen_min_offset;            \

#define S_DIALOG                                               \
   widget_screen_struct             *next_screen;              \
   widget_window_struct             *next_window;              \
   MsfDialogType                    dialog_type;               \
   MsfGadgetHandle                  dialog_input;              \
   MsfStringHandle                  dialog_text;               \
   kal_uint32                       timeout;                   \
   MsfColor                         color;                     \
   MsfFont                          font;                      \
   MsfTextProperty                  text_property;             \
   kal_int16                        input_sum;                 \
   kal_int8                         is_tone_played;            \

// TODO: S_STYLE takes a lot of memory. This can be optimized with some efforts.
#define S_STYLE                                                \
   MsfColor                         fg_color;                  \
   MsfColor                         bg_color;                  \
   MsfPattern                       fg_pattern;                \
   MsfPattern                       bg_pattern;                \
   MsfLineStyle                     line_style;                \
   MsfFont                          font;                      \
   MsfTextProperty                  text_property;             \

#ifdef WIDGET_PRECACHE_IMAGE
#define  S_PRECACHE_STATE  widget_precache_image_enum precache_state;
#else 
#define  S_PRECACHE_STATE
#endif 

#define S_IMAGE                                                     \
   MsfImageFormat                   image_format;                   \
   MsfStyleHandle                   style;                          \
   MsfSize                          size;                           \
   S_PRECACHE_STATE                                                 \
   /* case 1. an icon */                                            \
   MsfIconHandle                    icon;                           \
   /* case 2. in mem */                                             \
   widget_raw_data_struct           *raw;                           \
   /* case 3. in file */                                            \
   kal_int16                        rawfile_id;                     \
   kal_uint16                       GIF_frames;                     \
   kal_uint32                       GIF_frames_initialized : 1;     \
   /* 0. normal 1. drawn image in EmptyImage (using draw_op_{head|tail}) */       \
   kal_uint32                       is_drawn_image : 1;             \
   kal_uint32                       disable_animation : 1;          \
   kal_uint32                       draw_op_directly : 1;           \
   /* draw the image in marquee procedure */                        \
   kal_uint32                       is_in_drawing_marquee : 1;      \
   kal_uint32                       video_in_preview : 1;           \
   /* Only used in compile option WIDGET_BROWSER_AUTORESIZE_JPEG */ \
   kal_uint32                       is_jpeg_auto_resize : 1;        \
   kal_bool                         is_done;                        \
   /* case 4. stored operations */                                  \
   widget_draw_op_struct            *draw_op_head;                  \
   widget_draw_op_struct            *draw_op_tail;                  \
   /* For marquee */                                                \
   MsfPosition                      draw_op_position;               \
   MsfSize                          draw_op_max_size;               \
   MsfPosition                      draw_op_border_position;        \
   MsfSize                          draw_op_border_size;            \
   kal_int16                        draw_op_x_offset;               \
   kal_int16                        draw_op_y_offset;               \
   MsfSize                          draw_op_content_size;           \
   kal_int32                        video_time_duration;            \

#define S_SOUND                                                      \
   MsfSoundFormat                   sound_format;                    \
   /* rawfile_id == -1 on system error; 0 for unused; > 0 if used */ \
   /* case 1. in file */                                               \
   kal_int16                        rawfile_id;                      \
   /* case 2. predefined */                                            \
   kal_uint8                        sound_id;                        \
   /* Finish reading */                                              \
   kal_uint8                        is_done;                         \

#define S_CHOICE_ELEMENT                                       \
   MsfStringHandle                  string1;                   \
   MsfStringHandle                  string2;                   \
   MsfImageHandle                   image1;                    \
   MsfImageHandle                   image2;                    \
   kal_uint8                        state;                     \
   kal_uint8                        flags;                     \

#define S_ICON                                                 \
   MsfStyleHandle                   style;                     \
   MsfIconType                      icon;                      \
   int                              icon_data;                 \

#ifndef WIDGET_COMPACT_PRE_STRING
#define S_PRE_STRING \
   const kal_uint8*                 string;
#endif /* WIDGET_COMPACT_PRE_STRING */ 

struct widget_accesskey_struct;

#define S_ACCESSKEY                                            \
   kal_uint32                       mask;                      \
   MSF_UINT32                       window;                    \
   struct widget_accesskey_struct   *accesskey_next;           \

#ifndef WIDGET_COMPACT_PRE_IMAGE
#define S_PRE_IMAGE                                            \
   MsfImageFormat                   image_format;              \
   MsfSize                          size;                      \
   kal_uint8                        *src;                      \
   int                              length;                    \
   int                              resource_id;               \

#endif /* WIDGET_COMPACT_PRE_IMAGE */ 

#define S_CTK                                                  \
   ctk_screen_handle                ctk_screen;                \
   widget_ctk_state_enum            ctk_state;                 \
   widget_ctk_predefined_type_enum  ctk_predefined_type;       \
   widget_ctk_flag_t                ctk_flag;                  \
   void                             (*on_post_paint)(void);    \
   kal_uint32                       idlescreen_seq_no;         \

/*
 * Note: MsfScreen, MsfWindow, and MsfGadget share common based S_WINDOW
 */

typedef struct widget_header_struct
{
S_HEADER} widget_header_struct;

typedef struct
{
S_HEADER S_RAW_DATA} widget_raw_data_struct;
typedef struct
{
S_HEADER S_ACTION} widget_action_struct;

/* MsfScreen */
typedef struct
{
S_HEADER S_WINDOW} widget_screen_struct;

/* MsfWindow */
typedef struct
{
S_HEADER S_WINDOW} widget_window_struct;
typedef struct
{
S_HEADER S_WINDOW S_EDITOR} widget_editor_struct;
typedef struct
{
S_HEADER S_WINDOW S_DIALOG} widget_dialog_struct;
typedef struct
{
S_HEADER S_WINDOW S_MENU} widget_menu_struct;
typedef struct
{
S_HEADER S_WINDOW S_FORM} widget_form_struct;
typedef widget_window_struct widget_paintbox_struct;

/* CTK (extension to MsfWindow) */
typedef struct
{
S_HEADER S_WINDOW S_CTK} widget_ctk_struct;

/* MsfGadget */
typedef struct widget_gadget_string_struct
{
S_HEADER S_WINDOW S_GADGET_STRING} widget_gadget_string_struct;
typedef struct
{
S_HEADER S_WINDOW S_GADGET_INPUT} widget_gadget_input_struct;
typedef struct widget_gadget_image_struct
{
S_HEADER S_WINDOW S_GADGET_IMAGE} widget_gadget_image_struct;
typedef struct
{
S_HEADER S_WINDOW S_MENU} widget_gadget_select_group_struct;
typedef struct
{
S_HEADER S_WINDOW S_GADGET_DATE} widget_gadget_date_struct;
typedef struct
{
S_HEADER S_WINDOW S_GADGET_BAR} widget_gadget_bar_struct;

/* Others */
typedef struct
{
S_HEADER S_STRING} widget_string_struct;
typedef struct
{
S_HEADER S_STYLE} widget_style_struct;
typedef struct
{
S_HEADER S_IMAGE} widget_image_struct;
typedef struct
{
S_HEADER S_SOUND} widget_sound_struct;
typedef struct
{
S_HEADER S_ICON} widget_icon_struct;
typedef struct
{
S_HEADER S_CHOICE_ELEMENT} widget_choice_element_struct;

/* Static (predefined) Resource  */
#ifdef WIDGET_COMPACT_PRE_STRING
typedef struct
{
S_BASIC_HEADER} widget_pre_string_struct;
#else /* WIDGET_COMPACT_PRE_STRING */ 
typedef struct
{
S_BASIC_HEADER S_PRE_STRING} widget_pre_string_struct;
#endif /* WIDGET_COMPACT_PRE_STRING */ 

#ifdef WIDGET_COMPACT_PRE_IMAGE
typedef struct
{
S_BASIC_HEADER} widget_pre_image_struct;
#else /* WIDGET_COMPACT_PRE_IMAGE */ 
typedef struct
{
S_BASIC_HEADER S_PRE_IMAGE} widget_pre_image_struct;
#endif /* WIDGET_COMPACT_PRE_IMAGE */ 

typedef struct widget_accesskey_struct
{
S_BASIC_HEADER S_ACCESSKEY} widget_accesskey_struct;

