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
 *  mteGprot.h
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  MoDIS Theme Editor External Interface
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
 ****************************************************************************/

#ifndef __MTEGPROT_H__
#define __MTEGPROT_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

/***************************************************************************** 
 * Define
 *****************************************************************************/
/* MTE RPC */
#define MMI_MTE_RPC_GET_RETURN_VALUE_API_INDEX            666
#define MMI_MTE_RPC_REGISTER_FINISH_CALLBACK_API_INDEX    888

#define MMI_MTE_MAX_THEME_NUMBER    10

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef enum
{
    MMI_MTE_THEME_DATA_TYPE_COLOR,              // color*
    MMI_MTE_THEME_DATA_TYPE_TEXT_BORDER_COLOR,  // color* for text border
    MMI_MTE_THEME_DATA_TYPE_FILLER,             // UI_filled_area*
    MMI_MTE_THEME_DATA_TYPE_IMAGE,              // PU8  (unsigned char *)
    MMI_MTE_THEME_DATA_TYPE_FONT,               // UI_font_type
    MMI_MTE_THEME_DATA_TYPE_INTEGER,            // S32 (signed int)
    MMI_MTE_THEME_DATA_TYPE_SYMBOL              // A fixed symbol
} mmi_mte_theme_data_type_enum;

typedef enum
{
    MMI_MTE_LCD_TYPE_MAIN,
    MMI_MTE_LCD_TYPE_SUB
} mmi_mte_lcd_type_enum;

/* LCD DIMENSION */
typedef enum
{
    MMI_MTE_LCD_DEFAULT,
    MMI_MTE_LCD_128x128,
    MMI_MTE_LCD_128x160,
    MMI_MTE_LCD_176x220,
    MMI_MTE_LCD_240x320,        
    MMI_MTE_LCD_320x240,            
    MMI_MTE_LCD_240x400,            
    MMI_MTE_LCD_RESOLUTION_NUM    
} mmi_mte_lcd_dimension_enum;

typedef enum
{
    MMI_MTE_FILLER_ALLOW_NULL = 1 << 0,     /* transparent */
    MMI_MTE_FILLER_ALLOW_BORDER = 1 << 1,   /* single line border */
    MMI_MTE_FILLER_ALLOW_IMAGE = 1 << 2     /* image. NOT USED YET. */
} mmi_mte_filler_capability_enum;

typedef struct
{
    unsigned int mmi_theme_offset;      /* theme byte offset in MMI_theme structure */
    unsigned int image_type;            /* image type flag */
    char *symbol_name;                  /* symbol name */
    int image_dimension[MMI_MTE_LCD_RESOLUTION_NUM][2]; /* image dimension for each resolution */
    int *category_filter;
} mmi_mte_theme_component_internal_struct;

typedef struct
{
    char *name;                         /* component name in ASCII */
    unsigned int id;                    /* component ID */
    unsigned int group_id;              /* component group id. (group names are in Unicode) */
    mmi_mte_theme_data_type_enum type;  /* component data type */
    char *description;                  /* component detail description in Unicode */
    int allow_editing;                  /* component allow editing in [Screen 5] */
    mmi_mte_lcd_type_enum lcd_type;     /* component LCD type */
    int min_value;                      /* min value */
    int max_value;                      /* max value */
    mmi_mte_filler_capability_enum filler_flag; /* filler capability flag */
    mmi_mte_theme_component_internal_struct internal_data;	/* internal data, should not be accessed by MTE UI. */
} mmi_mte_theme_component_struct;

typedef enum
{
    MMI_MTE_FONT_TYPE_DEFAULT,
    MMI_MTE_FONT_TYPE_UI_DEFAULT,
    MMI_MTE_FONT_TYPE_SMALL,
    MMI_MTE_FONT_TYPE_MEDIUM,
    MMI_MTE_FONT_TYPE_LARGE,
    MMI_MTE_FONT_TYPE_VKBD,             /* for virtual keyboard */
    MMI_MTE_FONT_TYPE_SUBLCD, 
    MMI_MTE_FONT_TYPE_DIALER_F1,        /* dialer input box */
    MMI_MTE_FONT_TYPE_DIALER_F2,        /* dialer input box */
    MMI_MTE_FONT_TYPE_MEDIUM_BOLD,      
    MMI_MTE_FONT_TYPE_NEW_FONT1,
    MMI_MTE_FONT_TYPE_NEW_FONT2,
    MMI_MTE_FONT_TYPE_NEW_FONT3,
    MMI_MTE_FONT_TYPE_NEW_FONT4,    
    MMI_MTE_FONT_TYPE_NUM,
    MMI_MTE_FONT_TYPE_UNDEF = MMI_MTE_FONT_TYPE_NUM  /* undefined. It also marks the end of the enum. */
} mmi_mte_theme_font_data_type_enum;

typedef enum
{
    MMI_MTE_IMAGE_NONE = 0,             /* NONE */
    MMI_MTE_IMAGE_GIF = 1 << 0,         /* GIF */
    MMI_MTE_IMAGE_JPG = 1 << 1,         /* JPG */
    MMI_MTE_IMAGE_BMP = 1 << 2,         /* BMP */
    MMI_MTE_IMAGE_PNG = 1 << 3,         /* Standard PNG format (only allowed after MT6238) */
    MMI_MTE_IMAGE_BMP_TO_ABM = 1 << 4,  /* BMP files will be converted to ABM internally. */	
    MMI_MTE_IMAGE_PNG_TO_ABM = 1 << 5   /* PNG files will be converted to ABM internally. */
} mmi_mte_image_enum;

typedef enum
{
    MMI_MTE_STATE_INACTIVE,
    MMI_MTE_STATE_ACTIVE
} mmi_mte_state_enum;


/* ABM encoder error code */
typedef enum
{
    MMI_MTE_ABMENC_NO_ERROR,            /* success */
    MMI_MTE_ABMENC_INPUT_TYPE_ERROR,    /* only support BMP and PNG input */
    MMI_MTE_ABMENC_PNG_CONVERT_ERROR,   /* convert PNG to BMP by convert.exe error */
    MMI_MTE_ABMENC_ABM_ENCODE_ERROR,    /* convert BMP to ABM error */
    MMI_MTE_ABMENC_OUTPUT_ABM_FILE_ERROR, /* output ABM file error */
    MMI_MTE_ABMENC_OUTPUT_BUFFER_OVERFLOW /* output size is more than given. */
} mmi_mte_abm_encoder_error_enum;

/* ABM encoder mode */
typedef enum
{
    MMI_MTE_ABMENC_MODE_OUTPUT_MEM,
    MMI_MTE_ABMENC_MODE_OUTPUT_FILE
} mmi_mte_abmenc_mode_enum;


/* MTE system variables */
typedef enum
{
    MMI_MTE_SYSTEM_VALUE_CONVERT_EXE_PATH,
    MMI_MTE_SYSTEM_VALUE_TEMP_PATH,
    MMI_MTE_SYSTEM_VALUE_NUM
} mmi_mte_system_value_enum;


/***************************************************************************** 
 * Global Function
 *****************************************************************************/
// TODO: using __MMI_FEATURES__ to differentiate between MTE UI and MMI seems not an elegant way.
#ifdef __MMI_FEATURES__ /* __MMI_FEATURES__ */

/*
 * MoDIS MMI API
 */
extern const char *mmi_mte_get_baseband_chip(void);
extern int mmi_mte_get_lcd_resolution(mmi_mte_lcd_type_enum lcd_type, int *width, int *height);
extern const char *mmi_mte_get_theme_component_symbol_info(const mmi_mte_theme_component_struct *theme_component);
extern mmi_mte_theme_data_type_enum mmi_mte_translate_font_pointer(UI_font_type font_ptr);
extern const char *mmi_mte_get_font_symbol(mmi_mte_theme_font_data_type_enum font_type);
extern void mmi_mte_get_theme_component_image_info(mmi_mte_theme_component_struct *theme_component, int *recommend_width, int *recommend_height, int *max_width, int *max_height, unsigned int *allowed_image_type, mmi_mte_image_enum *recommend_image_type);
extern const char *mmi_mte_get_image_info_string(mmi_mte_image_enum image_type);
extern int mmi_mte_get_image_dimension(mmi_mte_image_enum image_type, char *image_data, int *width, int *height);
extern int mmi_mte_start_decode_image(mmi_mte_image_enum image_type, char *image_data, int image_size, char *output_buffer, unsigned int output_buffer_size, int output_image_width, int output_image_height, void (*frame_finish_callback)(char *output_buffer, int output_image_width, int output_image_height));
extern void mmi_mte_stop_decode_image(void);
extern const char *mmi_mte_get_theme_schema_version(int *major_verno, int *minor_verno);
extern int mmi_mte_get_theme_component_num(void);
extern const mmi_mte_theme_component_struct *mmi_mte_get_theme_component(int component_id);
extern int mmi_mte_get_theme_components_in_current_screen(int max_component_number, const mmi_mte_theme_component_struct *theme_component_list[]);
extern int mmi_mte_get_component_group_num(void);
extern const char *mmi_mte_get_component_group_name(int group_id);
extern int mmi_mte_get_system_theme_data(int max_theme_number, const MMI_theme **theme_list, const char *theme_name_list[]);
extern void mmi_mte_refresh_screen(mmi_mte_lcd_type_enum lcd_type);
extern void mmi_mte_activate_theme(MMI_theme *theme);
extern void *mmi_mte_translate_theme_component_data_pointer(const mmi_mte_theme_component_struct *theme_component, MMI_theme *theme);
extern void mmi_mte_register_switch_screen_callback(void (*switch_screen_callback)(void));
extern int mmi_mte_get_example_screen_num(void);
extern const char* mmi_mte_get_example_screen_name(int screen_index);
extern int mmi_mte_show_example_screen(int screen_index);
extern int mmi_mte_set_image_source(int use_image_folder, const char *folder_path);
extern int mmi_mte_get_image_resource_total_size(int in_local_folder);
extern void mmi_mte_set_language(int language_id);
extern const char *mmi_mte_get_welcome_string(const MMI_theme *theme);
extern int mmi_mte_get_image_data_length(char *image_ptr);
extern void mmi_mte_get_image_header(char *header, mmi_mte_image_enum image_type, int width, int height, int size);
extern MMI_theme *mmi_mte_get_current_system_theme(void);
extern void mmi_mte_get_image_resource_info(char *img_res_ptr, char **img_data_ptr, mmi_mte_image_enum *mte_image_type, int *width, int *height, int *size);
extern void mmi_mte_set_state(mmi_mte_state_enum state);
extern int mmi_mte_show_example_screen_by_group(int group_index);
extern mmi_mte_abm_encoder_error_enum mmi_mte_encode_abm_image(mmi_mte_abmenc_mode_enum mode, mmi_mte_image_enum input_image_type, char *input_filename, char *output_abm_bitstream, int *output_size);
extern void *mmi_mte_get_value(mmi_mte_system_value_enum name);
extern int mmi_mte_set_value(mmi_mte_system_value_enum name, void *value);

#else /* __MMI_FEATURES__ */

/* 
 * MTE UI interface API
 */

/*
 * DO NOT CHANGE THE FOLLOWING TYPE DEFINITIONS.
 */
typedef unsigned int    U32;
typedef unsigned short  U16;
typedef unsigned char   U8;
typedef signed int      S32;

typedef U8* PU8;

typedef struct stFontAttribute
{
    U8 bold;
    U8 italic;
    U8 underline;
    U8 size;
    U8 color;
    U8 type;
    U8 oblique;
    U8 smallCaps;
} stFontAttribute;
typedef stFontAttribute*	UI_font_type;

typedef U8 UI_transparent_color_type;

typedef struct
{	U8 r; // 0 ~ 255
	U8 g; // 0 ~ 255
	U8 b; // 0 ~ 255
	U8 alpha; // 0 ~ 100
} color;

typedef struct _gradient_color
{
    color *c;   /* List of colors in the gradient   */
    U8 *p;      /* Percentage of each color      */
    U8 n;       /* Number of colors in the list  */
} gradient_color;

/*
 * UI filled area structure
 * -------------------
 * bits 0-7:         filler types
 * bit    8:            1=vertical filler, 0=horizontal filler (used for gradients and textures)
 * bit  9:           flip filler
 * bit    10:        (reserved)
 * bit  11:       (reserved)
 * bit    12:        border yes/no
 * bit  13:       border size 0=single line, 1=double line
 * bit  14:       3D border
 * bit  15:       rounded border
 * bit    16:        1=elevated border, 0=depressed border
 * bit    17:        1=filled area with shadow
 * bit  18:            1=filled area with double line shadow, 0=single line shadow
 * bit  19:       (reserved)
 * bit  20:       left rounded border
 * bit  21:       right rounded border
 * bit  22:       Draw only horizontal lines in borders
 * bit  24:       transparent color
 */

/* Bits 0-7: filler type */
#define UI_FILLED_AREA_MASK_TYPE                            0x000000FF
#define UI_FILLED_AREA_TYPE_COLOR                           0x00000000
#define UI_FILLED_AREA_TYPE_GRADIENT_COLOR                  0x00000001
#define UI_FILLED_AREA_TYPE_TEXTURE                         0x00000002
#define UI_FILLED_AREA_TYPE_BITMAP                          0x00000003
#define UI_FILLED_AREA_TYPE_HATCH_COLOR                     0x00000004
#define UI_FILLED_AREA_TYPE_ALTERNATE_HATCH_COLOR           0x00000005
#define UI_FILLED_AREA_TYPE_CROSS_HATCH_COLOR               0x00000006
#define UI_FILLED_AREA_TYPE_ALTERNATE_CROSS_HATCH_COLOR     0x00000007
#define UI_FILLED_AREA_TYPE_NO_BACKGROUND                   0x00000008
#define UI_FILLED_AREA_TYPE_CUSTOM_FILL_TYPE1               0x00000009  /* Popup description 1 */
#define UI_FILLED_AREA_TYPE_CUSTOM_FILL_TYPE2               0x0000000A  /* Popup description 2 */
#define UI_FILLED_AREA_TYPE_3D_BORDER                       0x0000000B

/* Bit 8: horiztonal or vertical fill for gradient color */
#define UI_FILLED_AREA_MASK_FILL_DIRECTION                  0x00000100
/* --- */
#define UI_FILLED_AREA_HORIZONTAL_FILL                      0x00000000
#define UI_FILLED_AREA_VERTICAL_FILL                        0x00000100

/* Bit 9: flip fill or not */
#define UI_FILLED_AREA_FLIP_FILL                            0x00000200

/* Bits 12-13: single-double-border */
#define UI_FILLED_AREA_MASK_BORDER_WIDTH                    0x00003000
#define UI_FILLED_AREA_TYPE_NO_BORDER                       0x00000000
#define UI_FILLED_AREA_BORDER                               0x00001000
#define UI_FILLED_AREA_SINGLE_BORDER                        0x00001000  /* Contain UI_FILLED_AREA_BORDER */
#define UI_FILLED_AREA_DOUBLE_BORDER                        0x00003000  /* Contain UI_FILLED_AREA_BORDER */

/* Bits 14: 3D border */
#define UI_FILLED_AREA_3D_BORDER                            0x00004000

/* Bits 15: Rounded border */
#define UI_FILLED_AREA_ROUNDED_BORDER                       0x00008000

/* Bits 16: Elevated or depressed border */
#define UI_FILLED_AREA_MASK_ELEVATION                       0x00010000
/* --- */
#define UI_FILLED_AREA_ELEVATED_BORDER                      0x00010000
#define UI_FILLED_AREA_DEPRESSED_BORDER                     0x00000000

/* Combination of Bit 14 and 16 */
#define UI_FILLED_AREA_3D_ELEVATED_BORDER                   (UI_FILLED_AREA_ELEVATED_BORDER | UI_FILLED_AREA_3D_BORDER)
#define UI_FILLED_AREA_3D_DEPRESSED_BORDER                  (UI_FILLED_AREA_DEPRESSED_BORDER | UI_FILLED_AREA_3D_BORDER)

/* Bits 17-18: single-double-shadown */
#define UI_FILLED_AREA_MASK_SHADOW                          0x00060000
#define UI_FILLED_AREA_SHADOW                               0x00020000
#define UI_FILLED_AREA_SHADOW_DOUBLE_LINE                   0x00040000

/* Bit 20: Left rounded border for Dalmatian style */
#define UI_FILLED_AREA_LEFT_ROUNDED_BORDER                  0x00100000

/* Bit 21: Right rounded border for Dalmatian style */
#define UI_FILLED_AREA_RIGHT_ROUNDED_BORDER                 0x00200000

/* Bit 22: Draw only horizontal lines w/o vertical lines in UI_FILLED_AREA_BORDER */
#define UI_FILLED_AREA_NO_VERTICAL_LINE                     0x00400000

/* Bit 24: Transparent color filler */
#define UI_FILLED_AREA_TYPE_TRANSPARENT_COLOR               0x01000000

typedef struct _UI_filled_area
{
    U32 flags;
    PU8 b;
    gradient_color *gc;
    color c;
    color ac;   /* alternate color used for hatch fills   */
    color border_color;
    color shadow_color;
    UI_transparent_color_type transparent_color;
} UI_filled_area;


/* 
 * UPDATE THE FOLLOWING MMI THEME STRUCTURE FOR NEW BRANCHES 
 */
/* 07B */
typedef struct _MMI_theme
{
    /* Multitap area theme */
    UI_filled_area  *multitap_filler;
    /* Editor area theme */
    UI_filled_area  *inputbox_filler;

    /* Back ground filler of scrollbar */
    UI_filled_area  *scrollbar_background_filler;
    /* Indicator filler of scrollbar */
    UI_filled_area  *scrollbar_indicator_filler;

    /* Back ground filler of title */
    UI_filled_area  *title_filler;

    /* List menu background filler */
    UI_filled_area  *list_background_filler;
    /* Normal list menu item background filler */
    UI_filled_area  *list_normal_item_filler;
    /* Highlighted list menu item background filler */
    UI_filled_area  *list_selected_item_filler;
    /* Disabled list menu item background filler */
    UI_filled_area  *list_disabled_item_filler;

    /* Matrix menu background filler */
    UI_filled_area  *matrix_background_filler;
    /* Normal matrix menu item background filler */
    UI_filled_area  *matrix_normal_item_filler;
    /* Highlighted matrix menu item background filler */
    UI_filled_area  *matrix_selected_item_filler;
    /* Disabled matrix menu item background filler */
    UI_filled_area  *matrix_disabled_item_filler;

    UI_filled_area  *formatted_inputbox_normal_filler;
    UI_filled_area  *formatted_inputbox_selected_filler;

    /* Main menu background filler for list and matrix menu */
    UI_filled_area  *main_menu_background_filler;

    /* Normal list main menu item background filler */
    UI_filled_area  *list_main_menu_normal_item_filler;
    /* Highlighted list main menu item background filler */
    UI_filled_area  *list_main_menu_selected_item_filler;
    /* Disabled list main menu item background filler */
    UI_filled_area  *list_main_menu_disabled_item_filler;

    /* Normal matrix main menu item background filler */
    UI_filled_area  *matrix_main_menu_normal_item_filler;
    /* Highlighted matrix main menu item background filler */
    UI_filled_area  *matrix_main_menu_selected_item_filler;
    /* Disabled matrix main menu item background filler */
    UI_filled_area  *matrix_main_menu_disabled_item_filler;

    /* General background filler, background of text and picture, usually is transparent color. 
    preview just an example. */
    UI_filled_area  *general_background_filler;

    UI_filled_area  *popup_description_background_filler;

    /* The theme for memu list seted by Inline Screen. It's the similar to the list filler, 
    such as list_background_filler */
    UI_filled_area  *inline_list_background_filler;
    UI_filled_area  *inline_list_normal_item_filler;
    UI_filled_area  *inline_list_selected_item_filler;
    UI_filled_area  *inline_list_disabled_item_filler;

    /* The filler for inline singleline editor without border. At current, no one use it. */
    UI_filled_area  *inline_edit_focussed_filler;
    UI_filled_area  *inline_edit_unfocussed_filler;
    UI_filled_area  *inline_edit_noboundary_filler;

    /* Pin input editor filler */
    UI_filled_area  *PIN_inputbox_background_filler;
    UI_filled_area  *PIN_screen_background_filler;
    /* Data time background */
    UI_filled_area  *network_screen_background_filler;
    /* Not used */
    UI_filled_area  *aphorism_screen_background_filler;
    /* Background filler of call manager screen */
    UI_filled_area  *CM_screen_background_filler;
    /* Not used */
    UI_filled_area  *progress_screen_background_filler;
    /* The dialer input box background filler */
    UI_filled_area  *dialer_inputbox_background_filler;

    /* background filler of key when it is selected. */
    UI_filled_area  *virtual_keyboard_key_down_filler;

    /* Not used */
    UI_filled_area  *alarm_background_filler;

    /* Menu background filler of small list screen */
    UI_filled_area  *small_list_menu_normal_filler;
    /* Border filler of small list screen */
    UI_filled_area  *small_list_screen_border_filler;
    color           *UI_black_color;
    color           *UI_white_color;

    color           *lite_disp_scr_bg_color;

    /* Text color of normal left softkey */
    color           *LSK_up_text_color;
    /* Text color of down left softkey */
    color           *LSK_down_text_color;
    /* Text color of disabled left softkey */
    color           *LSK_disabled_text_color;
    /* Text color of normal right softkey */
    color           *RSK_up_text_color;
    /* Text color of down right softkey */
    color           *RSK_down_text_color;
    /* Text color of disabled right  softkey */
    color           *RSK_disabled_text_color;

    /* Multitap area theme */
    color           *multitap_selector_color;
    color           *multitap_normal_text_color;
    color           *multitap_selected_text_color;

    /* Editor area theme */
    color           *inputbox_normal_text_color;
    color           *inputbox_selected_text_color;
    color           *inputbox_selector_color;
    color           *inputbox_cursor_color;

    /* Text color in title */
    color           *title_text_color;
    /* Text border color in title */
    color           *title_text_border_color;
    /* Text color of shortcut */
    color           *title_shortcut_text_color;

    /* Text color of the normal (unhighlited) list menu item */
    color           *list_normal_text_color;
    /* Text color of the highlighted list menu item */
    color           *list_selected_text_color;
    /* Text color of the disabled list menu item */
    color           *list_disabled_text_color;

    /* Text color of the normal (unhighlited) matrix menu item */
    color           *matrix_normal_text_color;
    /* Text color of the highlighted matrix menu item */
    color           *matrix_selected_text_color;
    /* Text color of the disabled matrix menu item */
    color           *matrix_disabled_text_color;

    /* OBSOLETE */
    color           *menubar_index_background_color;
    /* OBSOLETE */
    color           *menubar_item_background_color;
    /* OBSOLETE */
    color           *menubar_index_text_color;
    /* OBSOLETE */
    color           *menubar_item_text_color;

    color           *drop_down_normal_text_color;
    color           *drop_down_disabled_text_color;
    color           *drop_down_focussed_text_color;

    /* Not used */
    color           *formatted_inputbox_selector_color;
    /* Not used */
    color           *formatted_inputbox_normal_text_color;
    /* Not used */
    color           *formatted_inputbox_disabled_text_color;
    /* Not used */
    color           *formatted_inputbox_selected_text_color;
    color           *formatted_inputbox_cursor_color;

    /* Text color of the normal (unhighlited) list menu item for category 14*/
    color           *list_main_menu_normal_text_color;
    /* Text color of the highlighted list menu item for category 14 */
    color           *list_main_menu_selected_text_color;
    /* Text color of the disabled list menu item for category 14 */
    color           *list_main_menu_disabled_text_color;

    /* Text color of the normal (unhighlited) matrix menu item for category 14 */
    color           *matrix_main_menu_normal_text_color;
    /* Text color of the highlighted matrix menu item for category 14 */
    color           *matrix_main_menu_selected_text_color;
    /* Text color of the disabled matrix menu item for category 14 */
    color           *matrix_main_menu_disabled_text_color;

    /* Text color of the normal (unhighlited) 3D circular menu item for category 14*/
    color           *circular_main_menu_normal_text_color;
    /* Text color of the highlighted 3D circular menu item for category 14 */
    color           *circular_main_menu_selected_text_color;
    /* Text color of the disabled 3D circular menu item for category 14 */
    color           *circular_main_menu_disabled_text_color;

    /* Popup background color */
    color           *popup_screen_background_color;
    color           *popup_screen_border_color;

    color           *popup_description_text_color;

    /* Call manager screen text color */
    color           *CM_screen_text_color;

    /* Call manager screen data Time background */
    color           *datetime_bar_background_color;
    color           *datetime_bar_duration_background_color;
    color           *datetime_bar_date_text_color;
    color           *datetime_bar_time_text_color;
    color           *datetime_bar_duration_text_color;
    /* AOC text color */
    color           *datetime_bar_AOC_text_color;

    /* UCE information bar color */
    color           *information_bar_color;
    color           *input_method_text_color;
    /* The message remaining length text color */
    color           *remaining_length_text_color;

    /* Inline single line editor text color */
    color           *inline_edit_focussed_text_color;
    /* Not used */
    color           *inline_edit_unfocussed_text_color;
    /* Inline single line editor selected text color */
    color           *inline_edit_selected_text_color;
    /* Inline single line editor selector color */
    color           *inline_edit_selector_color;
    /* Inline single line editor cursor color */
    color           *inline_edit_cursor_color;

    color           *inline_list_normal_text_color;
    color           *inline_list_selected_text_color;
    color           *inline_list_disabled_text_color;

    /* Pin input editor text color */
    color           *PIN_inputbox_normal_text_color;
    /* Pin input editor selected text color	 */
    color           *PIN_inputbox_selected_text_color;
    /* Pin input editor selector color */
    color           *PIN_inputbox_selector_color;
    /* Pin input editor cursor color */
    color           *PIN_inputbox_cursor_color;

    /* The dialer input box text color */
    color           *dialer_inputbox_normal_text_color;
    /* The dialer input box selected text color */
    color           *dialer_inputbox_selected_text_color;
    /* The dialer input box selector color */
    color           *dialer_inputbox_selector_color;
    /* The dialer input box corsor color */
    color           *dialer_inputbox_cursor_color;

    /* text color of key when it is selected */
    color           *virtual_keyboard_key_down_text_color;
    /* text color of key when it is not selected */
    color           *virtual_keyboard_key_up_text_color;
    /* text color of dead key when it is selected */
    color           *virtual_keyboard_dead_key_down_text_color;
    /* text color of dead key when it is not selected */
    color           *virtual_keyboard_dead_key_up_text_color;
    /* text color of display area */
    color           *virtual_keyboard_disp_area_text_color;

    /* Not used */
    color           *calculator_color;
    /* Not used */
    color           *alarm_text_color;

    /* Data color */
    color           *idle_scr_date_color; 
    /* Time color */
    color           *idle_scr_time_color;
    /* Data border color */
    color           *idle_scr_date_border_color; 
    /* Time border color */
    color           *idle_scr_time_border_color;
    /* Network name color */
    color           *idle_scr_network_name_color; 
    /* Network name border color */
    color           *idle_scr_network_name_border_color; 
    /* Network status color */
    color           *idle_scr_network_status_color; 
    /* Network status border color */
    color           *idle_scr_network_status_border_color; 
    /* Network extra color */
    color           *idle_scr_network_extra_color; 
    /* Net work extra border color */
    color           *idle_scr_network_extra_border_color; 

    UI_font_type    button_font;
    UI_font_type    multitap_font;
    UI_font_type    inputbox_font;
    /* Font of title */
    UI_font_type    window_title_font;
    /* Font of list menu */
    UI_font_type    list_menu_font;
    /* Font of matrix menu */
    UI_font_type    matrix_menu_font;
    /* OBSOLETE */
    UI_font_type    menu_bar_index_font;
    /* OBSOLETE */
    UI_font_type    menu_bar_item_font;
    /* Font of shortcut */
    UI_font_type    shortcut_indicator_font;
    /* Font of title */
    UI_font_type    title_text_font;
    /* Not Used */
    UI_font_type    drop_down_control_font;
    /* Font of list main menu */
    UI_font_type    list_main_menu_font;
    /* Font of matrix main menu */
    UI_font_type    matrix_main_menu_font;
    /* text font of custom key */
    UI_font_type    virtual_keyboard_font;

    /* width of vertical scroll bar or height of horizontal scroll bar */
    S32             scrollbar_size;

    /* Full opacity of screen */
    S32             bg_opacity_full;
    /* High opacity of screen (Not used) */
    S32             bg_opacity_high;
    /* Medium opacity of screen */
    S32             bg_opacity_medium;
    /* Low opacity of screen */
    S32             bg_opacity_low;

    /* highlight fillers */
    /*
     * Highlight dimension for menu items
     *
     * HIGHLIGHT WIDTH = LCD_WIDTH - UI_SCROLLBAR_WIDTH - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP
     * HIGHLIGT HEIGHT: 
     *      Single-line     = MMI_MENUITEM_HEIGHT
     *      Two-line        = MMI_MENUITEM_HEIGHT * 2
     *      Multi-row       = MMI_MULTIROW_MENUITEM_HEIGHT
     *      Thick           = MMI_THICK_MENUITEM_HEIGHT = CAT425_MENUITEM_HEIGHT
     *      Thick with tab  = CAT425_MENUITEM_HEIGHT_NO_TAB
     *
     * If the menu item dimension does not fit perfectly, the highlight filler will be list_selected_item_filler.
     */
     /* Single-line highlighted menu item background filler */
    UI_filled_area  *menuitem_single_line_highlight_filler;
    /* Two-line highlighted menu item background filler */
    UI_filled_area  *menuitem_two_line_highlight_filler;
    /* Multi-row highlighted menu item background filler */
    UI_filled_area  *menuitem_multirow_highlight_filler;
    /* Thick highlighted menu item background filler */
    UI_filled_area  *menuitem_thick_highlight_filler;
    /* Thick with tab menu item background filler (Category 425 only)*/
    UI_filled_area  *menuitem_thick_with_tab_highlight_filler;
    /* Symbol picker highlight filler (Category 22 only)*/
    UI_filled_area  *symbol_picker_highlight_filler;
    /* Not used */
    UI_filled_area  *matrix_highlight_filler;

    /* full-screen background */
    /* Main menu background filler */
    UI_filled_area  *main_menu_bkg_filler;
    /* Sub menu background filler */
    UI_filled_area  *sub_menu_bkg_filler;
    /* Idle background filler */
    UI_filled_area  *idle_bkg_filler;

    /* popup background*/
    /* Popup background image */
    PU8             popup_bkg_image;
    color           *popup_text_color;

    /* weekday in idle */
    color           *idle_scr_weekday_color;
    color           *idle_scr_weekday_border_color;

    /* clock */    
    /* Clock component: text font of date text for digital clock in main lcd */
    UI_font_type    date_text_font;
    /* Clock component: text font of time text for digital clock in main lcd */
    UI_font_type    time_text_font;
    /* Clock component: text color of date text for digital clock in main lcd */
    color           *date_text_color;
    /* Clock component: text border color of date text for digital clock in main lcd */
    color           *date_text_border_color;
    /* Clock component: text color of time text for digital clock in main lcd */
    color           *time_text_color;
    /* Clock component: text border color of time text for digital clock in main lcd */
    color           *time_text_border_color;
    /* Clock component: text font of date text for digital clock in sub lcd */
    UI_font_type    date_text_font_sub_lcd;
    /* Clock component: text font of time text for digital clock in sub lcd */
    UI_font_type    time_text_font_sub_lcd;    
    /* Clock component: text color of date text for digital clock in sub lcd */
    color           *date_text_color_sub_lcd;
    /* Clock component: text border color of date text for digital clock in sub lcd */
    color           *date_text_border_color_sub_lcd;
    /* Clock component: text color of time text for digital clock in sub lcd */
    color           *time_text_color_sub_lcd;
    /* Clock component: text border color of time text for digital clock in sub lcd */
    color           *time_text_border_color_sub_lcd;
    /* Clock component: hour hand color of analog clock in main lcd */
    color           *analog_hand_hour_color;
    /* Clock component: minute hand color of analog clock in main lcd */
    color           *analog_hand_min_color;
    /* Clock component: Not used */
    color           *analog_axis_color;

    /* softkey */
    /* Text border color softkey((0, 0, 255)means no border) */
    color           *softkey_text_border_color;
    /* Back ground filler of softkey bar
                            128x128     128x160     176x220     240x320
    Wdith of softkey            50          50          70          74
    Height of softkey           18          19          20          36
    */
    UI_filled_area  *softkey_bar_bkg_filler;

    /* tab title */
    /* Filler of tab title */
    UI_filled_area  *tab_title_filler;
    /* Text color of tab title */
    color           *tab_title_text_color;
    /* Text border color of tab title */
    color           *tab_title_text_border_color;
    /* Shortcut color of tab title */
    color           *tab_title_shortcut_text_color;
    /* Font of tab title */
    UI_font_type    tab_title_text_font;

    /* IME */
    /* Under line color */
    color           *ime_underline_color;
    /* Indicator color */
    color           *ime_indicator_color;
    /* Focused area background color
            128X128  176X220 240X320
    Width       128      176     240
    Height      18       20      24
    */
    color           *ime_focused_background_color;
    /* Non-focused area background color
            128X128  176X220 240X320
    Width       128      176     240
    Height      14       16      20
    */
    color           *ime_background_color;
    /* Focused area border color */
    color           *ime_focused_border_color;
    /* Non-focused area background color */
    color           *ime_border_color;
    /* Text color  */
    color           *ime_text_color;
    /* Label color */
    color           *ime_lable_color;
    /* Highlighted text background color */
    color           *ime_hilite_color;
    /* Highlighted text color */
    color           *ime_hilite_text_color;
    /* Cursor color */
    color           *ime_cursor_color;
    /* Arrow color */
    color           *ime_arrow_color;
    UI_font_type    ime_text_font;
    UI_font_type    ime_lable_font;

    /* inline edit */
    UI_filled_area  *inline_list_default_text_item_filler;

    /* calendar */
    /* text color of title */
    color           *calendar_title_fg_color;
    /* text color of year select */
    color           *calendar_horizontal_fg_color;
    /* text border color of year select */
    color           *calendar_horizontal_border_color;
    /* text color of week number */
    color           *calendar_vertical_fg_color;
    /* text color of month select */
    color           *calendar_horizontal_string_fg_color;
    /* text color of week day */
    color           *calendar_current_color;
    /* cell background color of one task state */
    color           *calendar_one_task_color;
    /* cell background color of more tasks state */
    color           *calendar_more_task_color;
    /* cell background color of menstrual state */
    color           *calendar_menstrual_color;
    /* cell background color of PP state */
    color           *calendar_PP_color;
    /* cell background color of danger state */
    color           *calendar_danger_color;
    /* cell background color of invalid state */
    color           *calendar_invalid_color;
    /* text color of cell valid state */
    color           *calendar_valid_fg_color;
    /* text color of cell invalid state */
    color           *calendar_invalid_fg_color;
    /* cell background color of highlight state */
    color           *calendar_highlight_color;
    /* background color of info box */
    color           *calendar_infobox_bg_color;
    /* background color of info box item */
    color           *calendar_infobox_entry_bg_color;
    /* text color of info box */
    color           *calendar_infobox_fg_color;
    /* text font of info box */
    UI_font_type    calendar_infobox_font;
    /* text font of week day */
    UI_font_type    calendar_horizontal_string_font;
    /* text font of cell text */
    UI_font_type    calendar_cell_font;
    
    /* Status icon bar */
    /* Back ground filler of status icon bar */
    UI_filled_area  *status_icon_bar_filler;

    /* thick title */
    /* thick title back gournd filler */
    UI_filled_area  *thick_title_filler;
    /* text color of thick title */
    color           *thick_title_text_color;
    /* text border of thick title */
    color           *thick_title_text_border_color;
    /* shortcut color of thick title */
    color           *thick_title_shortcut_text_color;

    /* main menu icon */
    PU8             main_menu_icon1;
    PU8             main_menu_icon2;    
    PU8             main_menu_icon3;
    PU8             main_menu_icon4;    
    PU8             main_menu_icon5;
    PU8             main_menu_icon6;    
    PU8             main_menu_icon7;
    PU8             main_menu_icon8;    
    PU8             main_menu_icon9;
    PU8             main_menu_icon10;    
    PU8             main_menu_icon11;
    PU8             main_menu_icon12;    
    PU8             main_menu_icon13;
    PU8             main_menu_icon14;    
    PU8             main_menu_icon15;
    
    /* rotated screen */
    /* back ground filler of rotate screen*/
    UI_filled_area  *rotated_bkg_filler;
    /* back ground image of rotate popup screen */
    PU8             rotated_popup_bkg_image;
    /* filler of title in rotate screen */
    UI_filled_area  *rotated_title_filler;

    /* small screen */    
    /* filler of title in small screen */
    UI_filled_area  *small_screen_title_filler;

    /* tab bar */
    /* normal image for tab bar */
    UI_filled_area  *tab_normal_tab_filler;
    /* focused image for tab bar */
    UI_filled_area  *tab_highlight_tab_filler;
    /* focused image for tab bar */
    UI_filled_area  *tab_blink_tab_filler;

    /* main menu */
    /* high light filler of bidegree main menu */
    UI_filled_area  *main_menu_bidegree_tab_highlight_filler;
    /* high light image of matrix main menu */
    PU8             matrix_main_menu_highlight_image;
    /* background filler of bidegree main menu */
    UI_filled_area  *main_menu_bidegree_tab_background_filler;

    /* list menu */
    /* separator color in list menu */
    color           *list_separator_color;

    /* cascade menu */
    /* separator color of cascade menu */
    color           *cascade_menu_separator_color;
    /* normal text color of cascade menu */
    color           *cascade_menu_normal_text_color;
    /* selected text color of cascade menu */
    color           *cascade_menu_selected_text_color;
    /* disabled text color of cascade menu */
    color           *cascade_menu_disabled_text_color;
    /* border color of cascade menu */
    color           *cascade_menu_border_color;
    /* back ground filler of cascade menu */
    UI_filled_area  *cascade_menu_background_filler;
    /* high light filler of cascade menu */
    UI_filled_area  *cascade_menu_highlight_filler;
    /* left arrow image of cascade submenu */
    PU8             cascade_menu_submenu_left_arrow_image;
    /* right arrow image of cascade submenu */
    PU8             cascade_menu_submenu_right_arrow_image;

    /* check & radio */
    /* selected image for check */
    PU8             list_check_selected_image;
    /* unselected image for check */
    PU8             list_check_unselected_image;
    /* selected image for radio */
    PU8             list_radio_selected_image;
    /* unselected image for radio */
    PU8             list_radio_unselected_image;

    /* Inline edit */
    /* left arrow image in inline edit */
    PU8             inline_edit_left_arrow_image;
    /* right arrow image in inline edit */
    PU8             inline_edit_right_arrow_image;

    /* inputbox */
    /* color of base line in inputbox */
    color           *inputbox_base_line_color;
    /* color of control character base line in ems */
    color           *inputbox_ems_cr_base_line_color;
    
    /* dialing */
    /* text color in dialer inputbox */
    color           *dialer_inputbox_text_color;
    /* border color in dialer inputbox */
    color           *dialer_inputbox_text_border_color;
    /* back ground filler for dialer inputbox for touch screen */
    UI_filled_area  *dialer_inputbox_touch_background_filler;
        
    /* reserved for the future */
    /* left softkey down filler */
    UI_filled_area  *softkey_lsk_down_filler;
    /* left softkey up filler */
    UI_filled_area  *softkey_lsk_up_filler;       
    /* right softkey down filler */
    UI_filled_area  *softkey_rsk_down_filler;        
    /* right softkey up filler */
    UI_filled_area  *softkey_rsk_up_filler; 
} MMI_theme;


/*
 * MTE UI RPC
 */
static HANDLE _mte_rpc_event;

static void mmi_mte_rpc_finish_cb(void *msg)
{
    SetEvent(_mte_rpc_event);
}

#define MTE_RPC_GET_RETURN_VALUE()  w32_mmi_mte_api(MMI_MTE_RPC_GET_RETURN_VALUE_API_INDEX)
#define mmi_mte_set_finish_cb(arg0) ((void (*)( void (*)(void*)))w32_mmi_mte_api(MMI_MTE_RPC_REGISTER_FINISH_CALLBACK_API_INDEX))(arg0)

#define MTE_RPC_BEGIN   { _mte_rpc_event = CreateEvent(NULL, 0, 0, "MTE_EV"); mmi_mte_set_finish_cb(mmi_mte_rpc_finish_cb);
#define MTE_RPC_END     WaitForSingleObject(_mte_rpc_event, INFINITE); CloseHandle(_mte_rpc_event); }

/*
 * !!! The following data are program-generated. DO NOT MODIFY THEM. !!!
 */
#define mmi_mte_get_baseband_chip() ((const char * (*)(void))w32_mmi_mte_api(0))()
#define mmi_mte_get_lcd_resolution(arg0, arg1, arg2) ((int  (*)(mmi_mte_lcd_type_enum lcd_type, int *width, int *height))w32_mmi_mte_api(1))(arg0, arg1, arg2)
#define mmi_mte_get_theme_component_symbol_info(arg0) ((const char * (*)(const mmi_mte_theme_component_struct *theme_component))w32_mmi_mte_api(2))(arg0)
#define mmi_mte_translate_font_pointer(arg0) ((mmi_mte_theme_data_type_enum  (*)(UI_font_type font_ptr))w32_mmi_mte_api(3))(arg0)
#define mmi_mte_get_font_symbol(arg0) ((const char * (*)(mmi_mte_theme_font_data_type_enum font_type))w32_mmi_mte_api(4))(arg0)
#define mmi_mte_get_theme_component_image_info(arg0, arg1, arg2, arg3, arg4, arg5, arg6) ((void  (*)(mmi_mte_theme_component_struct *theme_component, int *recommend_width, int *recommend_height, int *max_width, int *max_height, unsigned int *allowed_image_type, mmi_mte_image_enum *recommend_image_type))w32_mmi_mte_api(5))(arg0, arg1, arg2, arg3, arg4, arg5, arg6)
#define mmi_mte_get_image_info_string(arg0) ((const char * (*)(mmi_mte_image_enum image_type))w32_mmi_mte_api(6))(arg0)
#define mmi_mte_get_image_dimension(arg0, arg1, arg2, arg3) mmi_mte_get_image_dimension_RPC(arg0, arg1, arg2, arg3, w32_mmi_mte_api)
static int mmi_mte_get_image_dimension_RPC(mmi_mte_image_enum image_type, char *image_data, int *width, int *height, void (*(*w32_mmi_mte_api)(int))(void)){     MTE_RPC_BEGIN    ((int  (*)(mmi_mte_image_enum image_type, char *image_data, int *width, int *height))w32_mmi_mte_api(7))(image_type, image_data, width, height);    MTE_RPC_END    return (int )MTE_RPC_GET_RETURN_VALUE();}
#define mmi_mte_start_decode_image(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7) mmi_mte_start_decode_image_RPC(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, w32_mmi_mte_api)
static int mmi_mte_start_decode_image_RPC(mmi_mte_image_enum image_type, char *image_data, int image_size, char *output_buffer, unsigned int output_buffer_size, int ouput_image_width, int output_image_height, void (*frame_finish_callback)(char *output_buffer, int output_image_width, int output_image_height), void (*(*w32_mmi_mte_api)(int))(void)){     MTE_RPC_BEGIN    ((int  (*)(mmi_mte_image_enum image_type, char *image_data, int image_size, char *output_buffer, unsigned int output_buffer_size, int ouput_image_width, int output_image_height, void (*frame_finish_callback)(char *output_buffer, int output_image_width, int output_image_height)))w32_mmi_mte_api(8))(image_type, image_data, image_size, output_buffer, output_buffer_size, ouput_image_width, output_image_height, frame_finish_callback);    MTE_RPC_END    return (int )MTE_RPC_GET_RETURN_VALUE();}
#define mmi_mte_stop_decode_image() do { MTE_RPC_BEGIN ((void  (*)(void))w32_mmi_mte_api(9))(); MTE_RPC_END } while (0)
#define mmi_mte_get_theme_schema_version(arg0, arg1) ((const char * (*)(int *major_verno, int *minor_verno))w32_mmi_mte_api(10))(arg0, arg1)
#define mmi_mte_get_theme_component_num() ((int  (*)(void))w32_mmi_mte_api(11))()
#define mmi_mte_get_theme_component(arg0) ((const mmi_mte_theme_component_struct * (*)(int component_id))w32_mmi_mte_api(12))(arg0)
#define mmi_mte_get_theme_components_in_current_screen(arg0, arg1) mmi_mte_get_theme_components_in_current_screen_RPC(arg0, arg1, w32_mmi_mte_api)
static int mmi_mte_get_theme_components_in_current_screen_RPC(int max_component_number, const mmi_mte_theme_component_struct *theme_component_list[], void (*(*w32_mmi_mte_api)(int))(void)){     MTE_RPC_BEGIN    ((int  (*)(int max_component_number, const mmi_mte_theme_component_struct *theme_component_list[]))w32_mmi_mte_api(13))(max_component_number, theme_component_list);    MTE_RPC_END    return (int )MTE_RPC_GET_RETURN_VALUE();}
#define mmi_mte_get_component_group_num() ((int  (*)(void))w32_mmi_mte_api(14))()
#define mmi_mte_get_component_group_name(arg0) ((const char * (*)(int group_id))w32_mmi_mte_api(15))(arg0)
#define mmi_mte_get_system_theme_data(arg0, arg1, arg2) ((int  (*)(int max_theme_number, const MMI_theme *theme_list[], const char *theme_name_list[]))w32_mmi_mte_api(16))(arg0, arg1, arg2)
#define mmi_mte_refresh_screen(arg0) do { MTE_RPC_BEGIN ((void  (*)(mmi_mte_lcd_type_enum lcd_type))w32_mmi_mte_api(17))(arg0); MTE_RPC_END } while (0)
#define mmi_mte_activate_theme(arg0) do { MTE_RPC_BEGIN ((void  (*)(MMI_theme *theme))w32_mmi_mte_api(18))(arg0); MTE_RPC_END } while (0)
#define mmi_mte_translate_theme_component_data_pointer(arg0, arg1) ((void * (*)(const mmi_mte_theme_component_struct *theme_component, MMI_theme *theme))w32_mmi_mte_api(19))(arg0, arg1)
#define mmi_mte_register_switch_screen_callback(arg0) do { MTE_RPC_BEGIN ((void  (*)(void (*switch_screen_callback)(void)))w32_mmi_mte_api(20))(arg0); MTE_RPC_END } while (0)
#define mmi_mte_get_example_screen_num() ((int  (*)(void))w32_mmi_mte_api(21))()
#define mmi_mte_get_example_screen_name(arg0) ((const char * (*)(int screen_index))w32_mmi_mte_api(22))(arg0)
#define mmi_mte_show_example_screen(arg0) mmi_mte_show_example_screen_RPC(arg0, w32_mmi_mte_api)
static int mmi_mte_show_example_screen_RPC(int screen_index, void (*(*w32_mmi_mte_api)(int))(void)){     MTE_RPC_BEGIN    ((int  (*)(int screen_index))w32_mmi_mte_api(23))(screen_index);    MTE_RPC_END    return (int )MTE_RPC_GET_RETURN_VALUE();}
#define mmi_mte_set_image_source(arg0, arg1) ((int  (*)(int use_image_folder, const char *folder_path))w32_mmi_mte_api(24))(arg0, arg1)
#define mmi_mte_get_image_resource_total_size(arg0) ((int  (*)(int in_local_folder))w32_mmi_mte_api(25))(arg0)
#define mmi_mte_set_language(arg0) ((void  (*)(int language_id))w32_mmi_mte_api(26))(arg0)
#define mmi_mte_get_welcome_string(arg0) ((const char * (*)(const MMI_theme *theme))w32_mmi_mte_api(27))(arg0)
#define mmi_mte_get_image_data_length(arg0) ((int  (*)(char *image_ptr))w32_mmi_mte_api(28))(arg0)
#define mmi_mte_get_image_header(arg0, arg1, arg2, arg3, arg4) ((void  (*)(char *header, mmi_mte_image_enum image_type, int width, int height, int size))w32_mmi_mte_api(29))(arg0, arg1, arg2, arg3, arg4)
#define mmi_mte_get_current_system_theme() mmi_mte_get_current_system_theme_RPC(w32_mmi_mte_api)
static MMI_theme *mmi_mte_get_current_system_theme_RPC(void (*(*w32_mmi_mte_api)(int))(void)){     MTE_RPC_BEGIN    ((MMI_theme * (*)(void))w32_mmi_mte_api(30))();    MTE_RPC_END    return (MMI_theme *)MTE_RPC_GET_RETURN_VALUE();}
#define mmi_mte_get_image_resource_info(arg0, arg1, arg2, arg3, arg4, arg5) ((void  (*)(char *img_res_ptr, char **img_data_ptr, mmi_mte_image_enum *mte_image_type, int *width, int *height, int *size))w32_mmi_mte_api(31))(arg0, arg1, arg2, arg3, arg4, arg5)
#define mmi_mte_set_state(arg0) ((void  (*)(mmi_mte_state_enum state))w32_mmi_mte_api(32))(arg0)
#define mmi_mte_show_example_screen_by_group(arg0) mmi_mte_show_example_screen_by_group_RPC(arg0, w32_mmi_mte_api)
static int mmi_mte_show_example_screen_by_group_RPC(int group_index, void (*(*w32_mmi_mte_api)(int))(void)){     MTE_RPC_BEGIN    ((int  (*)(int group_index))w32_mmi_mte_api(33))(group_index);    MTE_RPC_END    return (int )MTE_RPC_GET_RETURN_VALUE();}
#define mmi_mte_encode_abm_image(arg0, arg1, arg2, arg3, arg4) mmi_mte_encode_abm_image_RPC(arg0, arg1, arg2, arg3, arg4, w32_mmi_mte_api)
static mmi_mte_abm_encoder_error_enum mmi_mte_encode_abm_image_RPC(mmi_mte_abmenc_mode_enum mode, mmi_mte_image_enum input_image_type, char *input_filename, char *output_abm_bitstream, int *output_size, void (*(*w32_mmi_mte_api)(int))(void)){     MTE_RPC_BEGIN    ((mmi_mte_abm_encoder_error_enum  (*)(mmi_mte_abmenc_mode_enum mode, mmi_mte_image_enum input_image_type, char *input_filename, char *output_abm_bitstream, int *output_size))w32_mmi_mte_api(34))(mode, input_image_type, input_filename, output_abm_bitstream, output_size);    MTE_RPC_END    return (mmi_mte_abm_encoder_error_enum)(int)MTE_RPC_GET_RETURN_VALUE();}
#define mmi_mte_get_value(arg0) ((void * (*)(mmi_mte_system_value_enum name))w32_mmi_mte_api(35))(arg0)
#define mmi_mte_set_value(arg0, arg1) ((int  (*)(mmi_mte_system_value_enum name, void *value))w32_mmi_mte_api(36))(arg0, arg1)

#endif /* __MMI_FEATURES__ */

#endif /* __MTEGPROT_H__ */


