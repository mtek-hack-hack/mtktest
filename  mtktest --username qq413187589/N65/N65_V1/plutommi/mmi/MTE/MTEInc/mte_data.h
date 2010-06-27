//
// DO NOT MODIFY ME!!!
//

#define	MMI_MTE_THEME_COMPONENT_NUM	280
#define	MMI_MTE_THEME_COMPONENT_GROUP_NUM	29

// GEMINI does not have the CASCADING MENU feature.
#undef __MMI_CASCADE_MENU__
#define MMI_CATEGORY_CASCADING_MENU_ID MMI_MTE_INVALID_FILTER_COMPONENT

typedef struct
{
    unsigned int num;
    int component_id[MMI_MTE_THEME_COMPONENT_NUM];    
} mmi_mte_control_set_group_struct;

typedef struct
{
    unsigned int num;
    int dm_group_id[DM_CONTROL_TOTAL];
} mmi_mte_control_set_discard_dm_struct;

typedef struct
{
    int   screen_id;
    int   category_id;
    mmi_mte_control_set_group_struct component_set;
    mmi_mte_control_set_discard_dm_struct discard_dm;
} mmi_mte_current_screen_filter_struct;


static S32 mmi_mte_category_filter_206[] = {MMI_CATEGORY12_ID, MMI_CATEGORY140_ID, MMI_CATEGORY186_ID, -1};
static S32 mmi_mte_category_filter_207[] = {MMI_CATEGORY12_ID, MMI_CATEGORY140_ID, MMI_CATEGORY186_ID, -1};
static S32 mmi_mte_category_filter_208[] = {MMI_CATEGORY36_ID, MMI_CATEGORY109_ID, MMI_CATEGORY172_ID, -1};
static S32 mmi_mte_category_filter_209[] = {MMI_CATEGORY36_ID, MMI_CATEGORY109_ID, MMI_CATEGORY172_ID, -1};


/* theme component info structure */
static mmi_mte_theme_component_struct g_mmi_mte_theme_component_info[MMI_MTE_THEME_COMPONENT_NUM] =
{
    {"calendar_title_fg_color", 0, 0, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {816, 0, "", {0}, NULL}},
    {"calendar_horizontal_fg_color", 1, 0, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {820, 0, "", {0}, NULL}},
    {"calendar_horizontal_border_color", 2, 0, MMI_MTE_THEME_DATA_TYPE_TEXT_BORDER_COLOR, NULL, 1, 0, 0, 0, 0, {824, 0, "", {0}, NULL}},
    {"calendar_vertical_fg_color", 3, 0, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {828, 0, "", {0}, NULL}},
    {"calendar_horizontal_string_fg_color", 4, 0, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {832, 0, "", {0}, NULL}},
    {"calendar_current_color", 5, 0, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {836, 0, "", {0}, NULL}},
    {"calendar_one_task_color", 6, 0, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {840, 0, "", {0}, NULL}},
    {"calendar_more_task_color", 7, 0, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {844, 0, "", {0}, NULL}},
#if defined(__MMI_MENSTRUAL__)
    {"calendar_menstrual_color", 8, 0, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {848, 0, "", {0}, NULL}},
#else
    {"calendar_menstrual_color", 8, 0, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {848, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_MENSTRUAL__)
    {"calendar_PP_color", 9, 0, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {852, 0, "", {0}, NULL}},
#else
    {"calendar_PP_color", 9, 0, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {852, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_MENSTRUAL__)
    {"calendar_danger_color", 10, 0, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {856, 0, "", {0}, NULL}},
#else
    {"calendar_danger_color", 10, 0, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {856, 0, "", {0}, NULL}},
#endif
    {"calendar_invalid_color", 11, 0, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {860, 0, "", {0}, NULL}},
    {"calendar_valid_fg_color", 12, 0, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {864, 0, "", {0}, NULL}},
    {"calendar_invalid_fg_color", 13, 0, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {868, 0, "", {0}, NULL}},
    {"calendar_highlight_color", 14, 0, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {872, 0, "", {0}, NULL}},
#if defined(__MMI_UI_CALENDAR_WITH_INFO_BOX__)
    {"calendar_infobox_bg_color", 15, 0, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {876, 0, "", {0}, NULL}},
#else
    {"calendar_infobox_bg_color", 15, 0, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {876, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_UI_CALENDAR_WITH_INFO_BOX__)
    {"calendar_infobox_entry_bg_color", 16, 0, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {880, 0, "", {0}, NULL}},
#else
    {"calendar_infobox_entry_bg_color", 16, 0, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {880, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_UI_CALENDAR_WITH_INFO_BOX__)
    {"calendar_infobox_fg_color", 17, 0, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {884, 0, "", {0}, NULL}},
#else
    {"calendar_infobox_fg_color", 17, 0, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {884, 0, "", {0}, NULL}},
#endif
    {"calendar_infobox_font", 18, 0, MMI_MTE_THEME_DATA_TYPE_FONT, NULL, 0, 0, 0, 0, 0, {888, 0, "", {0}, NULL}},
    {"calendar_horizontal_string_font", 19, 0, MMI_MTE_THEME_DATA_TYPE_FONT, NULL, 0, 0, 0, 0, 0, {892, 0, "", {0}, NULL}},
    {"calendar_cell_font", 20, 0, MMI_MTE_THEME_DATA_TYPE_FONT, NULL, 0, 0, 0, 0, 0, {896, 0, "", {0}, NULL}},
    {"date_text_font", 21, 1, MMI_MTE_THEME_DATA_TYPE_FONT, NULL, 0, 0, 0, 0, 0, {668, 0, "", {0}, NULL}},
    {"time_text_font", 22, 1, MMI_MTE_THEME_DATA_TYPE_FONT, NULL, 0, 0, 0, 0, 0, {672, 0, "", {0}, NULL}},
    {"date_text_color", 23, 1, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {676, 0, "", {0}, NULL}},
    {"date_text_border_color", 24, 1, MMI_MTE_THEME_DATA_TYPE_TEXT_BORDER_COLOR, NULL, 0, 0, 0, 0, 0, {680, 0, "", {0}, NULL}},
    {"time_text_color", 25, 1, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {684, 0, "", {0}, NULL}},
    {"time_text_border_color", 26, 1, MMI_MTE_THEME_DATA_TYPE_TEXT_BORDER_COLOR, NULL, 0, 0, 0, 0, 0, {688, 0, "", {0}, NULL}},
    {"date_text_font_sub_lcd", 27, 1, MMI_MTE_THEME_DATA_TYPE_FONT, NULL, 0, 1, 0, 0, 0, {692, 0, "", {0}, NULL}},
    {"time_text_font_sub_lcd", 28, 1, MMI_MTE_THEME_DATA_TYPE_FONT, NULL, 0, 1, 0, 0, 0, {696, 0, "", {0}, NULL}},
#if defined(__MMI_SUBLCD__)
    {"date_text_color_sub_lcd", 29, 1, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 1, 0, 0, 0, {700, 0, "", {0}, NULL}},
#else
    {"date_text_color_sub_lcd", 29, 1, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 1, 0, 0, 0, {700, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_SUBLCD__)
    {"date_text_border_color_sub_lcd", 30, 1, MMI_MTE_THEME_DATA_TYPE_TEXT_BORDER_COLOR, NULL, 1, 1, 0, 0, 0, {704, 0, "", {0}, NULL}},
#else
    {"date_text_border_color_sub_lcd", 30, 1, MMI_MTE_THEME_DATA_TYPE_TEXT_BORDER_COLOR, NULL, 0, 1, 0, 0, 0, {704, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_SUBLCD__)
    {"time_text_color_sub_lcd", 31, 1, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 1, 0, 0, 0, {708, 0, "", {0}, NULL}},
#else
    {"time_text_color_sub_lcd", 31, 1, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 1, 0, 0, 0, {708, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_SUBLCD__)
    {"time_text_border_color_sub_lcd", 32, 1, MMI_MTE_THEME_DATA_TYPE_TEXT_BORDER_COLOR, NULL, 1, 1, 0, 0, 0, {712, 0, "", {0}, NULL}},
#else
    {"time_text_border_color_sub_lcd", 32, 1, MMI_MTE_THEME_DATA_TYPE_TEXT_BORDER_COLOR, NULL, 0, 1, 0, 0, 0, {712, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_ANALOG_CLOCK__)
    {"analog_hand_hour_color", 33, 1, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {716, 0, "", {0}, NULL}},
#else
    {"analog_hand_hour_color", 33, 1, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {716, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_ANALOG_CLOCK__)
    {"analog_hand_min_color", 34, 1, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {720, 0, "", {0}, NULL}},
#else
    {"analog_hand_min_color", 34, 1, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {720, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_ANALOG_CLOCK__) && (!defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__) || (defined(__MMI_SUBLCD_SHOW_ANALOG_CLOCK__) && defined(__MMI_SUBLCD_COLOR__)))
    {"analog_axis_color", 35, 1, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {724, 0, "", {0}, NULL}},
#else
    {"analog_axis_color", 35, 1, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {724, 0, "", {0}, NULL}},
#endif
    {"general_background_filler", 36, 2, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, 0, {88, 0, "", {0}, NULL}},
    {"UI_black_color", 37, 2, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {168, 0, "", {0}, NULL}},
    {"UI_white_color", 38, 2, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {172, 0, "", {0}, NULL}},
    {"lite_disp_scr_bg_color", 39, 2, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {176, 0, "", {0}, NULL}},
    {"formatted_inputbox_normal_filler", 40, 3, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {52, 0, "", {0}, NULL}},
    {"formatted_inputbox_selected_filler", 41, 3, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {56, 0, "", {0}, NULL}},
    {"inline_list_background_filler", 42, 3, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {96, 0, "", {0}, NULL}},
    {"inline_list_normal_item_filler", 43, 3, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {100, 0, "", {0}, NULL}},
    {"inline_list_selected_item_filler", 44, 3, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {104, 0, "", {0}, NULL}},
    {"inline_list_disabled_item_filler", 45, 3, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {108, 0, "", {0}, NULL}},
    {"inline_edit_focussed_filler", 46, 3, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {112, 0, "", {0}, NULL}},
    {"inline_edit_unfocussed_filler", 47, 3, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {116, 0, "", {0}, NULL}},
    {"inline_edit_noboundary_filler", 48, 3, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {120, 0, "", {0}, NULL}},
    {"inline_edit_focussed_text_color", 49, 3, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {404, 0, "", {0}, NULL}},
    {"inline_edit_unfocussed_text_color", 50, 3, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {408, 0, "", {0}, NULL}},
    {"inline_edit_selected_text_color", 51, 3, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {412, 0, "", {0}, NULL}},
    {"inline_edit_selector_color", 52, 3, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {416, 0, "", {0}, NULL}},
    {"inline_edit_cursor_color", 53, 3, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {420, 0, "", {0}, NULL}},
    {"inline_list_normal_text_color", 54, 3, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {424, 0, "", {0}, NULL}},
    {"inline_list_selected_text_color", 55, 3, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {428, 0, "", {0}, NULL}},
    {"inline_list_disabled_text_color", 56, 3, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {432, 0, "", {0}, NULL}},
    {"inline_list_default_text_item_filler", 57, 3, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_NULL | MMI_MTE_FILLER_ALLOW_BORDER, {812, 0, "", {0}, NULL}},
    {"inline_edit_left_arrow_image", 58, 3, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1076, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | (MMI_MTE_IMAGE_BMP << 16), "", {{0, 0}, {9, 13}, {9, 13}, {9, 13}, {20, 20}, {20, 20}, {0, 0}, }, NULL}},
    {"inline_edit_right_arrow_image", 59, 3, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1080, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | (MMI_MTE_IMAGE_BMP << 16), "", {{0, 0}, {9, 13}, {9, 13}, {9, 13}, {20, 20}, {20, 20}, {0, 0}, }, NULL}},
    {"inputbox_filler", 60, 4, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {4, 0, "", {0}, NULL}},
    {"inputbox_normal_text_color", 61, 4, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {216, 0, "", {0}, NULL}},
    {"inputbox_selected_text_color", 62, 4, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {220, 0, "", {0}, NULL}},
    {"inputbox_selector_color", 63, 4, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {224, 0, "", {0}, NULL}},
    {"inputbox_cursor_color", 64, 4, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {228, 0, "", {0}, NULL}},
    {"information_bar_color", 65, 4, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {392, 0, "", {0}, NULL}},
    {"input_method_text_color", 66, 4, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {396, 0, "", {0}, NULL}},
    {"remaining_length_text_color", 67, 4, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {400, 0, "", {0}, NULL}},
    {"inputbox_font", 68, 4, MMI_MTE_THEME_DATA_TYPE_FONT, NULL, 0, 0, 0, 0, 0, {544, 0, "", {0}, NULL}},
    {"inputbox_base_line_color", 69, 4, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {1084, 0, "", {0}, NULL}},
    {"inputbox_ems_cr_base_line_color", 70, 4, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {1088, 0, "", {0}, NULL}},
#if defined(__MMI_CSTAR__) && !defined(__MMI_TOUCH_SCREEN__)
    {"ime_underline_color", 71, 5, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {756, 0, "", {0}, NULL}},
#else
    {"ime_underline_color", 71, 5, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {756, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_CSTAR__) && !defined(__MMI_TOUCH_SCREEN__)
    {"ime_indicator_color", 72, 5, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {760, 0, "", {0}, NULL}},
#else
    {"ime_indicator_color", 72, 5, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {760, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_CSTAR__) && !defined(__MMI_TOUCH_SCREEN__)
    {"ime_focused_background_color", 73, 5, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {764, 0, "", {0}, NULL}},
#else
    {"ime_focused_background_color", 73, 5, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {764, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_CSTAR__) && !defined(__MMI_TOUCH_SCREEN__)
    {"ime_background_color", 74, 5, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {768, 0, "", {0}, NULL}},
#else
    {"ime_background_color", 74, 5, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {768, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_CSTAR__) && !defined(__MMI_TOUCH_SCREEN__)
    {"ime_focused_border_color", 75, 5, MMI_MTE_THEME_DATA_TYPE_TEXT_BORDER_COLOR, NULL, 1, 0, 0, 0, 0, {772, 0, "", {0}, NULL}},
#else
    {"ime_focused_border_color", 75, 5, MMI_MTE_THEME_DATA_TYPE_TEXT_BORDER_COLOR, NULL, 0, 0, 0, 0, 0, {772, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_CSTAR__) && !defined(__MMI_TOUCH_SCREEN__)
    {"ime_border_color", 76, 5, MMI_MTE_THEME_DATA_TYPE_TEXT_BORDER_COLOR, NULL, 1, 0, 0, 0, 0, {776, 0, "", {0}, NULL}},
#else
    {"ime_border_color", 76, 5, MMI_MTE_THEME_DATA_TYPE_TEXT_BORDER_COLOR, NULL, 0, 0, 0, 0, 0, {776, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_CSTAR__) && !defined(__MMI_TOUCH_SCREEN__)
    {"ime_text_color", 77, 5, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {780, 0, "", {0}, NULL}},
#else
    {"ime_text_color", 77, 5, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {780, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_CSTAR__) && !defined(__MMI_TOUCH_SCREEN__)
    {"ime_lable_color", 78, 5, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {784, 0, "", {0}, NULL}},
#else
    {"ime_lable_color", 78, 5, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {784, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_CSTAR__) && !defined(__MMI_TOUCH_SCREEN__)
    {"ime_hilite_color", 79, 5, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {788, 0, "", {0}, NULL}},
#else
    {"ime_hilite_color", 79, 5, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {788, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_CSTAR__) && !defined(__MMI_TOUCH_SCREEN__)
    {"ime_hilite_text_color", 80, 5, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {792, 0, "", {0}, NULL}},
#else
    {"ime_hilite_text_color", 80, 5, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {792, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_CSTAR__) && !defined(__MMI_TOUCH_SCREEN__)
    {"ime_cursor_color", 81, 5, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {796, 0, "", {0}, NULL}},
#else
    {"ime_cursor_color", 81, 5, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {796, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_CSTAR__) && !defined(__MMI_TOUCH_SCREEN__)
    {"ime_arrow_color", 82, 5, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {800, 0, "", {0}, NULL}},
#else
    {"ime_arrow_color", 82, 5, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {800, 0, "", {0}, NULL}},
#endif
    {"ime_text_font", 83, 5, MMI_MTE_THEME_DATA_TYPE_FONT, NULL, 0, 0, 0, 0, 0, {804, 0, "", {0}, NULL}},
    {"ime_lable_font", 84, 5, MMI_MTE_THEME_DATA_TYPE_FONT, NULL, 0, 0, 0, 0, 0, {808, 0, "", {0}, NULL}},
#if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)
    {"virtual_keyboard_key_down_filler", 85, 6, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {152, 0, "", {0}, NULL}},
#else
    {"virtual_keyboard_key_down_filler", 85, 6, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {152, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)
    {"virtual_keyboard_key_down_text_color", 86, 6, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {468, 0, "", {0}, NULL}},
#else
    {"virtual_keyboard_key_down_text_color", 86, 6, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {468, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)
    {"virtual_keyboard_key_up_text_color", 87, 6, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {472, 0, "", {0}, NULL}},
#else
    {"virtual_keyboard_key_up_text_color", 87, 6, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {472, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)
    {"virtual_keyboard_dead_key_down_text_color", 88, 6, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {476, 0, "", {0}, NULL}},
#else
    {"virtual_keyboard_dead_key_down_text_color", 88, 6, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {476, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)
    {"virtual_keyboard_dead_key_up_text_color", 89, 6, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {480, 0, "", {0}, NULL}},
#else
    {"virtual_keyboard_dead_key_up_text_color", 89, 6, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {480, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)
    {"virtual_keyboard_disp_area_text_color", 90, 6, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {484, 0, "", {0}, NULL}},
#else
    {"virtual_keyboard_disp_area_text_color", 90, 6, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {484, 0, "", {0}, NULL}},
#endif
    {"virtual_keyboard_font", 91, 6, MMI_MTE_THEME_DATA_TYPE_FONT, NULL, 0, 0, 0, 0, 0, {588, 0, "", {0}, NULL}},
    {"multitap_filler", 92, 7, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {0, 0, "", {0}, NULL}},
    {"multitap_selector_color", 93, 7, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {204, 0, "", {0}, NULL}},
    {"multitap_normal_text_color", 94, 7, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {208, 0, "", {0}, NULL}},
    {"multitap_selected_text_color", 95, 7, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {212, 0, "", {0}, NULL}},
    {"multitap_font", 96, 7, MMI_MTE_THEME_DATA_TYPE_FONT, NULL, 0, 0, 0, 0, 0, {540, 0, "", {0}, NULL}},
#if defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
    {"main_menu_bidegree_tab_highlight_filler", 97, 8, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {1008, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {40, 44}, {65, 65}, {36, 53}, {0, 0}, }, NULL}},
#else
    {"main_menu_bidegree_tab_highlight_filler", 97, 8, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {1008, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
    {"main_menu_bidegree_tab_background_filler", 98, 8, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {1016, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {40, 44}, {65, 65}, {36, 53}, {0, 0}, }, NULL}},
#else
    {"main_menu_bidegree_tab_background_filler", 98, 8, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {1016, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_MAINMENU_CIRCULAR_SUPPORT__)
    {"circular_main_menu_normal_text_color", 99, 9, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {340, 0, "", {0}, NULL}},
#else
    {"circular_main_menu_normal_text_color", 99, 9, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {340, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_MAINMENU_CIRCULAR_SUPPORT__)
    {"circular_main_menu_selected_text_color", 100, 9, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {344, 0, "", {0}, NULL}},
#else
    {"circular_main_menu_selected_text_color", 100, 9, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {344, 0, "", {0}, NULL}},
#endif
    {"circular_main_menu_disabled_text_color", 101, 9, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {348, 0, "", {0}, NULL}},
    {"list_main_menu_normal_item_filler", 102, 10, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {64, 0, "", {0}, NULL}},
#if defined(__MMI_MAINMENU_LIST_SUPPORT__) && !defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
    {"list_main_menu_selected_item_filler", 103, 10, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {68, 0, "", {0}, NULL}},
#else
    {"list_main_menu_selected_item_filler", 103, 10, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {68, 0, "", {0}, NULL}},
#endif
    {"list_main_menu_disabled_item_filler", 104, 10, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {72, 0, "", {0}, NULL}},
#if defined(__MMI_MAINMENU_LIST_SUPPORT__) && !defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
    {"list_main_menu_normal_text_color", 105, 10, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {316, 0, "", {0}, NULL}},
#else
    {"list_main_menu_normal_text_color", 105, 10, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {316, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_MAINMENU_LIST_SUPPORT__) && !defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
    {"list_main_menu_selected_text_color", 106, 10, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {320, 0, "", {0}, NULL}},
#else
    {"list_main_menu_selected_text_color", 106, 10, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {320, 0, "", {0}, NULL}},
#endif
    {"list_main_menu_disabled_text_color", 107, 10, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {324, 0, "", {0}, NULL}},
    {"list_main_menu_font", 108, 10, MMI_MTE_THEME_DATA_TYPE_FONT, NULL, 0, 0, 0, 0, 0, {580, 0, "", {0}, NULL}},
#if defined(__MMI_MAINLCD_128X128__)
    {"main_menu_background_filler", 109, 11, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, 0, {60, MMI_MTE_IMAGE_BMP | (MMI_MTE_IMAGE_BMP << 16), "", {{LCD_WIDTH, MMI_CONTENT_HEIGHT}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
#else
    {"main_menu_background_filler", 109, 11, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {60, MMI_MTE_IMAGE_BMP | (MMI_MTE_IMAGE_BMP << 16), "", {0}, NULL}},
#endif
    {"matrix_main_menu_normal_item_filler", 110, 11, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {76, 0, "", {0}, NULL}},
#if defined(__MMI_MAINMENU_MATRIX_SUPPORT__) || defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
    {"matrix_main_menu_selected_item_filler", 111, 11, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, 0, {80, 0, "", {0}, NULL}},
#else
    {"matrix_main_menu_selected_item_filler", 111, 11, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {80, 0, "", {0}, NULL}},
#endif
    {"matrix_main_menu_disabled_item_filler", 112, 11, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {84, 0, "", {0}, NULL}},
#if defined(__MMI_MAINMENU_MATRIX_SUPPORT__) || defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
    {"matrix_main_menu_normal_text_color", 113, 11, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {328, 0, "", {0}, NULL}},
#else
    {"matrix_main_menu_normal_text_color", 113, 11, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {328, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_MAINMENU_MATRIX_SUPPORT__) || defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
    {"matrix_main_menu_selected_text_color", 114, 11, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {332, 0, "", {0}, NULL}},
#else
    {"matrix_main_menu_selected_text_color", 114, 11, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {332, 0, "", {0}, NULL}},
#endif
    {"matrix_main_menu_disabled_text_color", 115, 11, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {336, 0, "", {0}, NULL}},
    {"matrix_main_menu_font", 116, 11, MMI_MTE_THEME_DATA_TYPE_FONT, NULL, 0, 0, 0, 0, 0, {584, 0, "", {0}, NULL}},
#if defined(__MMI_MAINMENU_MATRIX_SUPPORT__)
    {"matrix_main_menu_highlight_image", 117, 11, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1012, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{MAIN_MENU_HIGHLIGHTED_IMAGE_WIDTH, MAIN_MENU_HIGHLIGHTED_IMAGE_HEIGHT}, {34, 34}, {38, 38}, {50, 50}, {80, 60}, {80, 58}, {0, 0}, }, NULL}},
#else
    {"matrix_main_menu_highlight_image", 117, 11, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1012, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
    {"CM_screen_background_filler", 118, 12, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {140, 0, "", {0}, NULL}},
#if !defined(__MMI_WALLPAPER_ON_BOTTOM__)
    {"CM_screen_text_color", 119, 12, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {364, 0, "", {0}, NULL}},
#else
    {"CM_screen_text_color", 119, 12, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {364, 0, "", {0}, NULL}},
#endif
    {"datetime_bar_background_color", 120, 12, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {368, 0, "", {0}, NULL}},
    {"datetime_bar_duration_background_color", 121, 12, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {372, 0, "", {0}, NULL}},
    {"datetime_bar_date_text_color", 122, 12, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {376, 0, "", {0}, NULL}},
    {"datetime_bar_time_text_color", 123, 12, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {380, 0, "", {0}, NULL}},
    {"datetime_bar_duration_text_color", 124, 12, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {384, 0, "", {0}, NULL}},
    {"datetime_bar_AOC_text_color", 125, 12, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {388, 0, "", {0}, NULL}},
    {"dialer_inputbox_background_filler", 126, 13, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {148, 0, "", {0}, NULL}},
    {"dialer_inputbox_normal_text_color", 127, 13, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {452, 0, "", {0}, NULL}},
    {"dialer_inputbox_selected_text_color", 128, 13, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {456, 0, "", {0}, NULL}},
    {"dialer_inputbox_selector_color", 129, 13, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {460, 0, "", {0}, NULL}},
    {"dialer_inputbox_cursor_color", 130, 13, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {464, 0, "", {0}, NULL}},
    {"dialer_inputbox_text_color", 131, 13, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {1092, 0, "", {0}, NULL}},
    {"dialer_inputbox_text_border_color", 132, 13, MMI_MTE_THEME_DATA_TYPE_TEXT_BORDER_COLOR, NULL, 1, 0, 0, 0, 0, {1096, 0, "", {0}, NULL}},
#if defined(__MMI_TOUCH_SCREEN__)
    {"dialer_inputbox_touch_background_filler", 133, 13, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_NULL | MMI_MTE_FILLER_ALLOW_BORDER, {1100, 0, "", {0}, NULL}},
#else
    {"dialer_inputbox_touch_background_filler", 133, 13, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_NULL | MMI_MTE_FILLER_ALLOW_BORDER, {1100, 0, "", {0}, NULL}},
#endif
    {"network_screen_background_filler", 134, 14, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {132, 0, "", {0}, NULL}},
    {"idle_scr_date_color", 135, 14, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {496, 0, "", {0}, NULL}},
    {"idle_scr_time_color", 136, 14, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {500, 0, "", {0}, NULL}},
    {"idle_scr_date_border_color", 137, 14, MMI_MTE_THEME_DATA_TYPE_TEXT_BORDER_COLOR, NULL, 1, 0, 0, 0, 0, {504, 0, "", {0}, NULL}},
    {"idle_scr_time_border_color", 138, 14, MMI_MTE_THEME_DATA_TYPE_TEXT_BORDER_COLOR, NULL, 1, 0, 0, 0, 0, {508, 0, "", {0}, NULL}},
    {"idle_scr_network_name_color", 139, 14, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {512, 0, "", {0}, NULL}},
    {"idle_scr_network_name_border_color", 140, 14, MMI_MTE_THEME_DATA_TYPE_TEXT_BORDER_COLOR, NULL, 1, 0, 0, 0, 0, {516, 0, "", {0}, NULL}},
    {"idle_scr_network_status_color", 141, 14, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {520, 0, "", {0}, NULL}},
    {"idle_scr_network_status_border_color", 142, 14, MMI_MTE_THEME_DATA_TYPE_TEXT_BORDER_COLOR, NULL, 1, 0, 0, 0, 0, {524, 0, "", {0}, NULL}},
    {"idle_scr_network_extra_color", 143, 14, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {528, 0, "", {0}, NULL}},
    {"idle_scr_network_extra_border_color", 144, 14, MMI_MTE_THEME_DATA_TYPE_TEXT_BORDER_COLOR, NULL, 1, 0, 0, 0, 0, {532, 0, "", {0}, NULL}},
    {"idle_scr_weekday_color", 145, 14, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {660, 0, "", {0}, NULL}},
    {"idle_scr_weekday_border_color", 146, 14, MMI_MTE_THEME_DATA_TYPE_TEXT_BORDER_COLOR, NULL, 1, 0, 0, 0, 0, {664, 0, "", {0}, NULL}},
    {"PIN_inputbox_background_filler", 147, 15, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {124, 0, "", {0}, NULL}},
#if !defined(__MMI_WALLPAPER_ON_BOTTOM__)
    {"PIN_screen_background_filler", 148, 15, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, 0, {128, 0, "", {0}, NULL}},
#else
    {"PIN_screen_background_filler", 148, 15, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {128, 0, "", {0}, NULL}},
#endif
    {"PIN_inputbox_normal_text_color", 149, 15, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {436, 0, "", {0}, NULL}},
    {"PIN_inputbox_selected_text_color", 150, 15, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {440, 0, "", {0}, NULL}},
    {"PIN_inputbox_selector_color", 151, 15, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {444, 0, "", {0}, NULL}},
    {"PIN_inputbox_cursor_color", 152, 15, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {448, 0, "", {0}, NULL}},
    {"popup_screen_background_color", 153, 16, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {352, 0, "", {0}, NULL}},
    {"popup_screen_border_color", 154, 16, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {356, 0, "", {0}, NULL}},
#if !defined(__MMI_MAINLCD_128X128__) && !defined(__MMI_MAINLCD_128X160__)
    {"popup_bkg_image", 155, 16, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {652, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_JPG | (MMI_MTE_IMAGE_JPG << 16), "", {{MMI_POP_UP_DIALOG_WIDTH, MMI_POP_UP_DIALOG_FULL_HEIGHT}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
#else
    {"popup_bkg_image", 155, 16, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {652, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_JPG | (MMI_MTE_IMAGE_JPG << 16), "", {0}, NULL}},
#endif
    {"popup_text_color", 156, 16, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {656, 0, "", {0}, NULL}},
#if defined(__MMI_SCREEN_ROTATE__)
    {"rotated_bkg_filler", 157, 17, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_NULL, {980, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_JPG | (MMI_MTE_IMAGE_JPG << 16), "", {{LCD_HEIGHT, LCD_WIDTH}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
#else
    {"rotated_bkg_filler", 157, 17, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_NULL, {980, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_JPG | (MMI_MTE_IMAGE_JPG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_SCREEN_ROTATE__) && defined(MMI_ROTATED_POP_UP_DIALOG_WIDTH) && defined(MMI_ROTATED_POP_UP_DIALOG_FULL_HEIGHT) && !defined(__MMI_MAINLCD_128X128__) && !defined(__MMI_MAINLCD_128X160__)
    {"rotated_popup_bkg_image", 158, 17, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {984, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_JPG | (MMI_MTE_IMAGE_JPG << 16), "", {{MMI_ROTATED_POP_UP_DIALOG_WIDTH, MMI_ROTATED_POP_UP_DIALOG_FULL_HEIGHT}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
#else
    {"rotated_popup_bkg_image", 158, 17, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {984, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_JPG | (MMI_MTE_IMAGE_JPG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_SCREEN_ROTATE__) && defined(MMI_ROTATED_TITLE_WIDTH) && defined(MMI_ROTATED_TITLE_HEIGHT)
    {"rotated_title_filler", 159, 17, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_NULL | MMI_MTE_FILLER_ALLOW_BORDER, {988, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{MMI_ROTATED_TITLE_WIDTH, MMI_ROTATED_TITLE_HEIGHT}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
#else
    {"rotated_title_filler", 159, 17, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_NULL | MMI_MTE_FILLER_ALLOW_BORDER, {988, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(UI_SMALL_LIST_SCREEN)
    {"small_list_menu_normal_filler", 160, 18, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, 0, {160, 0, "", {0}, NULL}},
#else
    {"small_list_menu_normal_filler", 160, 18, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {160, 0, "", {0}, NULL}},
#endif
#if defined(UI_SMALL_LIST_SCREEN)
    {"small_list_screen_border_filler", 161, 18, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {164, 0, "", {0}, NULL}},
#else
    {"small_list_screen_border_filler", 161, 18, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {164, 0, "", {0}, NULL}},
#endif
#if defined(UI_SMALL_LIST_SCREEN)
    {"small_screen_title_filler", 162, 18, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {992, 0, "", {0}, NULL}},
#else
    {"small_screen_title_filler", 162, 18, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {992, 0, "", {0}, NULL}},
#endif
    {"symbol_picker_highlight_filler", 163, 19, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {632, 0, "", {0}, NULL}},
    {"scrollbar_background_filler", 164, 20, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {8, 0, "", {0}, NULL}},
    {"scrollbar_indicator_filler", 165, 20, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {12, 0, "", {0}, NULL}},
    {"scrollbar_size", 166, 20, MMI_MTE_THEME_DATA_TYPE_SYMBOL, NULL, 0, 0, 0, 0, 0, {592, 0, "UI_SCROLLBAR_WIDTH", {0}, NULL}},
    {"LSK_up_text_color", 167, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {180, 0, "", {0}, NULL}},
    {"LSK_down_text_color", 168, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {184, 0, "", {0}, NULL}},
    {"LSK_disabled_text_color", 169, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {188, 0, "", {0}, NULL}},
    {"RSK_up_text_color", 170, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {192, 0, "", {0}, NULL}},
    {"RSK_down_text_color", 171, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {196, 0, "", {0}, NULL}},
    {"RSK_disabled_text_color", 172, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {200, 0, "", {0}, NULL}},
    {"button_font", 173, 21, MMI_MTE_THEME_DATA_TYPE_FONT, NULL, 0, 0, 0, 0, 0, {536, 0, "", {0}, NULL}},
    {"softkey_text_border_color", 174, 21, MMI_MTE_THEME_DATA_TYPE_TEXT_BORDER_COLOR, NULL, 1, 0, 0, 0, 0, {728, 0, "", {0}, NULL}},
    {"softkey_bar_bkg_filler", 175, 21, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_NULL | MMI_MTE_FILLER_ALLOW_BORDER, {732, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{LCD_WIDTH, MMI_SOFTKEY_HEIGHT}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
    {"softkey_lsk_down_filler", 176, 21, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_NULL | MMI_MTE_FILLER_ALLOW_BORDER, {1104, 0, "", {0}, NULL}},
    {"softkey_lsk_up_filler", 177, 21, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_NULL | MMI_MTE_FILLER_ALLOW_BORDER, {1108, 0, "", {0}, NULL}},
    {"softkey_rsk_down_filler", 178, 21, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_NULL | MMI_MTE_FILLER_ALLOW_BORDER, {1112, 0, "", {0}, NULL}},
    {"softkey_rsk_up_filler", 179, 21, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_NULL | MMI_MTE_FILLER_ALLOW_BORDER, {1116, 0, "", {0}, NULL}},
    {"status_icon_bar_filler", 180, 22, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_NULL | MMI_MTE_FILLER_ALLOW_BORDER, {900, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_BMP << 16), "", {{LCD_WIDTH, MMI_STATUS_BAR_HEIGHT}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
    {"cascade_menu_separator_color", 181, 23, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1024, 0, "", {0}, NULL}},
#if defined(__MMI_CASCADE_MENU__)
    {"cascade_menu_normal_text_color", 182, 23, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {1028, 0, "", {0}, NULL}},
#else
    {"cascade_menu_normal_text_color", 182, 23, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1028, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_CASCADE_MENU__)
    {"cascade_menu_selected_text_color", 183, 23, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {1032, 0, "", {0}, NULL}},
#else
    {"cascade_menu_selected_text_color", 183, 23, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1032, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_CASCADE_MENU__)
    {"cascade_menu_disabled_text_color", 184, 23, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {1036, 0, "", {0}, NULL}},
#else
    {"cascade_menu_disabled_text_color", 184, 23, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1036, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_CASCADE_MENU__)
    {"cascade_menu_border_color", 185, 23, MMI_MTE_THEME_DATA_TYPE_TEXT_BORDER_COLOR, NULL, 1, 0, 0, 0, 0, {1040, 0, "", {0}, NULL}},
#else
    {"cascade_menu_border_color", 185, 23, MMI_MTE_THEME_DATA_TYPE_TEXT_BORDER_COLOR, NULL, 0, 0, 0, 0, 0, {1040, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_CASCADE_MENU__)
    {"cascade_menu_background_filler", 186, 23, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, 0, {1044, 0, "", {0}, NULL}},
#else
    {"cascade_menu_background_filler", 186, 23, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {1044, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_CASCADE_MENU__)
    {"cascade_menu_highlight_filler", 187, 23, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {1048, 0, "", {0}, NULL}},
#else
    {"cascade_menu_highlight_filler", 187, 23, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {1048, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_CASCADE_MENU__)
    {"cascade_menu_submenu_left_arrow_image", 188, 23, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1052, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | (MMI_MTE_IMAGE_BMP << 16), "", {{0, 0}, {15, 15}, {15, 15}, {15, 15}, {20, 20}, {15, 15}, {0, 0}, }, NULL}},
#else
    {"cascade_menu_submenu_left_arrow_image", 188, 23, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1052, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | (MMI_MTE_IMAGE_BMP << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_CASCADE_MENU__)
    {"cascade_menu_submenu_right_arrow_image", 189, 23, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1056, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | (MMI_MTE_IMAGE_BMP << 16), "", {{0, 0}, {15, 15}, {15, 15}, {15, 15}, {20, 20}, {15, 15}, {0, 0}, }, NULL}},
#else
    {"cascade_menu_submenu_right_arrow_image", 189, 23, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1056, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | (MMI_MTE_IMAGE_BMP << 16), "", {0}, NULL}},
#endif
    {"popup_description_text_color", 190, 24, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {360, 0, "", {0}, NULL}},
#if defined(__MMI_MAINLCD_128X128__)
    {"list_background_filler", 191, 24, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, 0, {20, 0, "", {0}, NULL}},
#else
    {"list_background_filler", 191, 24, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {20, 0, "", {0}, NULL}},
#endif
    {"list_normal_item_filler", 192, 24, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {24, 0, "", {0}, NULL}},
    {"list_selected_item_filler", 193, 24, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {28, 0, "", {0}, NULL}},
    {"list_disabled_item_filler", 194, 24, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {32, 0, "", {0}, NULL}},
    {"popup_description_background_filler", 195, 24, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {92, 0, "", {0}, NULL}},
    {"list_normal_text_color", 196, 24, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {244, 0, "", {0}, NULL}},
    {"list_selected_text_color", 197, 24, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {248, 0, "", {0}, NULL}},
    {"list_disabled_text_color", 198, 24, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {252, 0, "", {0}, NULL}},
    {"list_menu_font", 199, 24, MMI_MTE_THEME_DATA_TYPE_FONT, NULL, 0, 0, 0, 0, 0, {552, 0, "", {0}, NULL}},
    {"menuitem_single_line_highlight_filler", 200, 24, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {612, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{LCD_WIDTH - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP - UI_SCROLLBAR_WIDTH, MMI_MENUITEM_HEIGHT}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
    {"menuitem_two_line_highlight_filler", 201, 24, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {616, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{LCD_WIDTH - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP - UI_SCROLLBAR_WIDTH, MMI_MENUITEM_HEIGHT*2}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
    {"menuitem_multirow_highlight_filler", 202, 24, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {620, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{LCD_WIDTH - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP - UI_SCROLLBAR_WIDTH, MMI_MULTIROW_MENUITEM_HEIGHT}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
    {"menuitem_thick_highlight_filler", 203, 24, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {624, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{LCD_WIDTH - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP - UI_SCROLLBAR_WIDTH, 30}, {LCD_WIDTH - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP - UI_SCROLLBAR_WIDTH, 30}, {LCD_WIDTH - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP - UI_SCROLLBAR_WIDTH, 30}, {LCD_WIDTH - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP - UI_SCROLLBAR_WIDTH, 39}, {LCD_WIDTH - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP - UI_SCROLLBAR_WIDTH, 60}, {LCD_WIDTH - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP - UI_SCROLLBAR_WIDTH, 44}, {0, 0}, }, NULL}},
    {"menuitem_thick_with_tab_highlight_filler", 204, 24, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {628, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{LCD_WIDTH - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP - UI_SCROLLBAR_WIDTH, 55}, {LCD_WIDTH - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP - UI_SCROLLBAR_WIDTH, 55}, {LCD_WIDTH - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP - UI_SCROLLBAR_WIDTH, 33}, {LCD_WIDTH - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP - UI_SCROLLBAR_WIDTH, 35}, {LCD_WIDTH - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP - UI_SCROLLBAR_WIDTH, 55}, {LCD_WIDTH - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP - UI_SCROLLBAR_WIDTH, 55}, {0, 0}, }, NULL}},
    {"list_separator_color", 205, 24, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1020, 0, "", {0}, NULL}},
    {"list_check_selected_image", 206, 24, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1060, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | (MMI_MTE_IMAGE_BMP << 16), "", {{0, 0}, {15, 15}, {15, 15}, {15, 15}, {26, 26}, {26, 26}, {0, 0}, }, mmi_mte_category_filter_206}},
    {"list_check_unselected_image", 207, 24, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1064, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | (MMI_MTE_IMAGE_BMP << 16), "", {{0, 0}, {15, 15}, {15, 15}, {15, 15}, {26, 26}, {26, 26}, {0, 0}, }, mmi_mte_category_filter_207}},
    {"list_radio_selected_image", 208, 24, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1068, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | (MMI_MTE_IMAGE_BMP << 16), "", {{0, 0}, {15, 15}, {15, 15}, {15, 15}, {26, 26}, {26, 26}, {0, 0}, }, mmi_mte_category_filter_208}},
    {"list_radio_unselected_image", 209, 24, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1072, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | (MMI_MTE_IMAGE_BMP << 16), "", {{0, 0}, {15, 15}, {15, 15}, {15, 15}, {26, 26}, {26, 26}, {0, 0}, }, mmi_mte_category_filter_209}},
#if !defined(__MMI_WALLPAPER_ON_BOTTOM__)
    {"matrix_background_filler", 210, 25, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {36, 0, "", {0}, NULL}},
#else
    {"matrix_background_filler", 210, 25, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {36, 0, "", {0}, NULL}},
#endif
    {"matrix_normal_item_filler", 211, 25, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {40, 0, "", {0}, NULL}},
    {"matrix_selected_item_filler", 212, 25, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {44, 0, "", {0}, NULL}},
    {"matrix_disabled_item_filler", 213, 25, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {48, 0, "", {0}, NULL}},
    {"matrix_normal_text_color", 214, 25, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {256, 0, "", {0}, NULL}},
    {"matrix_selected_text_color", 215, 25, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {260, 0, "", {0}, NULL}},
    {"matrix_disabled_text_color", 216, 25, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {264, 0, "", {0}, NULL}},
    {"matrix_menu_font", 217, 25, MMI_MTE_THEME_DATA_TYPE_FONT, NULL, 0, 0, 0, 0, 0, {556, 0, "", {0}, NULL}},
#if defined(__MMI_IMPS__) || defined(__MMI_UCM__) || defined(__MMI_VOIP__)
    {"tab_title_filler", 218, 26, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {736, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{MMI_HORIZONTAL_TAB_BAR_WIDTH, MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
#else
    {"tab_title_filler", 218, 26, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {736, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_IMPS__) || defined(__MMI_UCM__) || defined(__MMI_VOIP__)
    {"tab_title_text_color", 219, 26, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {740, 0, "", {0}, NULL}},
#else
    {"tab_title_text_color", 219, 26, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {740, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_IMPS__) || defined(__MMI_UCM__) || defined(__MMI_VOIP__)
    {"tab_title_text_border_color", 220, 26, MMI_MTE_THEME_DATA_TYPE_TEXT_BORDER_COLOR, NULL, 1, 0, 0, 0, 0, {744, 0, "", {0}, NULL}},
#else
    {"tab_title_text_border_color", 220, 26, MMI_MTE_THEME_DATA_TYPE_TEXT_BORDER_COLOR, NULL, 0, 0, 0, 0, 0, {744, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_IMPS__) || defined(__MMI_UCM__) || defined(__MMI_VOIP__)
    {"tab_title_shortcut_text_color", 221, 26, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {748, 0, "", {0}, NULL}},
#else
    {"tab_title_shortcut_text_color", 221, 26, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {748, 0, "", {0}, NULL}},
#endif
    {"tab_title_text_font", 222, 26, MMI_MTE_THEME_DATA_TYPE_FONT, NULL, 0, 0, 0, 0, 0, {752, 0, "", {0}, NULL}},
#if defined(__MMI_IMPS__) || defined(__MMI_UCM__) || defined(__MMI_VOIP__)
    {"tab_normal_tab_filler", 223, 26, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_NULL | MMI_MTE_FILLER_ALLOW_BORDER, {996, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {44, 20}, {44, 20}, {44, 20}, {60, 28}, {61, 36}, {0, 0}, }, NULL}},
#else
    {"tab_normal_tab_filler", 223, 26, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_NULL | MMI_MTE_FILLER_ALLOW_BORDER, {996, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_IMPS__) || defined(__MMI_UCM__) || defined(__MMI_VOIP__)
    {"tab_highlight_tab_filler", 224, 26, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_NULL | MMI_MTE_FILLER_ALLOW_BORDER, {1000, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {44, 20}, {44, 20}, {44, 20}, {60, 28}, {61, 36}, {0, 0}, }, NULL}},
#else
    {"tab_highlight_tab_filler", 224, 26, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_NULL | MMI_MTE_FILLER_ALLOW_BORDER, {1000, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_IMPS__) || defined(__MMI_UCM__) || defined(__MMI_VOIP__)
    {"tab_blink_tab_filler", 225, 26, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_NULL | MMI_MTE_FILLER_ALLOW_BORDER, {1004, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {44, 20}, {44, 20}, {44, 20}, {60, 28}, {61, 36}, {0, 0}, }, NULL}},
#else
    {"tab_blink_tab_filler", 225, 26, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_NULL | MMI_MTE_FILLER_ALLOW_BORDER, {1004, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
    {"title_filler", 226, 27, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_NULL | MMI_MTE_FILLER_ALLOW_BORDER, {16, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{MMI_TITLE_WIDTH, MMI_TITLE_HEIGHT}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
    {"title_text_color", 227, 27, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {232, 0, "", {0}, NULL}},
    {"title_text_border_color", 228, 27, MMI_MTE_THEME_DATA_TYPE_TEXT_BORDER_COLOR, NULL, 1, 0, 0, 0, 0, {236, 0, "", {0}, NULL}},
    {"title_shortcut_text_color", 229, 27, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {240, 0, "", {0}, NULL}},
    {"window_title_font", 230, 27, MMI_MTE_THEME_DATA_TYPE_FONT, NULL, 0, 0, 0, 0, 0, {548, 0, "", {0}, NULL}},
    {"shortcut_indicator_font", 231, 27, MMI_MTE_THEME_DATA_TYPE_FONT, NULL, 0, 0, 0, 0, 0, {568, 0, "", {0}, NULL}},
    {"title_text_font", 232, 27, MMI_MTE_THEME_DATA_TYPE_FONT, NULL, 0, 0, 0, 0, 0, {572, 0, "", {0}, NULL}},
#if defined(GUI_MAINMENU_USE_THICK_TITLE) || defined(GUI_SUBMENU_USE_THICK_TITLE) || defined(GUI_COMMON_USE_THICK_TITLE) || defined(GUI_DEFAULT_USE_THICK_TITLE)
    {"thick_title_filler", 233, 27, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_NULL | MMI_MTE_FILLER_ALLOW_BORDER, {904, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{LCD_WIDTH, MMI_THICK_TITLE_HEIGHT}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
#else
    {"thick_title_filler", 233, 27, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_NULL | MMI_MTE_FILLER_ALLOW_BORDER, {904, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(GUI_MAINMENU_USE_THICK_TITLE) || defined(GUI_SUBMENU_USE_THICK_TITLE) || defined(GUI_COMMON_USE_THICK_TITLE) || defined(GUI_DEFAULT_USE_THICK_TITLE)
    {"thick_title_text_color", 234, 27, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {908, 0, "", {0}, NULL}},
#else
    {"thick_title_text_color", 234, 27, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {908, 0, "", {0}, NULL}},
#endif
#if defined(GUI_MAINMENU_USE_THICK_TITLE) || defined(GUI_SUBMENU_USE_THICK_TITLE) || defined(GUI_COMMON_USE_THICK_TITLE) || defined(GUI_DEFAULT_USE_THICK_TITLE)
    {"thick_title_text_border_color", 235, 27, MMI_MTE_THEME_DATA_TYPE_TEXT_BORDER_COLOR, NULL, 1, 0, 0, 0, 0, {912, 0, "", {0}, NULL}},
#else
    {"thick_title_text_border_color", 235, 27, MMI_MTE_THEME_DATA_TYPE_TEXT_BORDER_COLOR, NULL, 0, 0, 0, 0, 0, {912, 0, "", {0}, NULL}},
#endif
#if defined(GUI_MAINMENU_USE_THICK_TITLE) || defined(GUI_SUBMENU_USE_THICK_TITLE) || defined(GUI_COMMON_USE_THICK_TITLE) || defined(GUI_DEFAULT_USE_THICK_TITLE)
    {"thick_title_shortcut_text_color", 236, 27, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {916, 0, "", {0}, NULL}},
#else
    {"thick_title_shortcut_text_color", 236, 27, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {916, 0, "", {0}, NULL}},
#endif
    {"bg_opacity_full", 237, 28, MMI_MTE_THEME_DATA_TYPE_INTEGER, NULL, 0, 0, 0, 255, 0, {596, 0, "", {0}, NULL}},
    {"bg_opacity_high", 238, 28, MMI_MTE_THEME_DATA_TYPE_INTEGER, NULL, 0, 0, 0, 255, 0, {600, 0, "", {0}, NULL}},
    {"bg_opacity_medium", 239, 28, MMI_MTE_THEME_DATA_TYPE_INTEGER, NULL, 0, 0, 0, 255, 0, {604, 0, "", {0}, NULL}},
    {"bg_opacity_low", 240, 28, MMI_MTE_THEME_DATA_TYPE_INTEGER, NULL, 1, 0, 0, 255, 0, {608, 0, "", {0}, NULL}},
#if defined(__MMI_WALLPAPER_ON_BOTTOM__)
    {"main_menu_bkg_filler", 241, 28, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, 0, {640, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_JPG | (MMI_MTE_IMAGE_JPG << 16), "", {{LCD_WIDTH, LCD_HEIGHT}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
#else
    {"main_menu_bkg_filler", 241, 28, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {640, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_JPG | (MMI_MTE_IMAGE_JPG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_WALLPAPER_ON_BOTTOM__)
    {"sub_menu_bkg_filler", 242, 28, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, 0, {644, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_JPG | (MMI_MTE_IMAGE_JPG << 16), "", {{LCD_WIDTH, LCD_HEIGHT}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
#else
    {"sub_menu_bkg_filler", 242, 28, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {644, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_JPG | (MMI_MTE_IMAGE_JPG << 16), "", {0}, NULL}},
#endif
    {"idle_bkg_filler", 243, 28, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, 0, {648, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_JPG | (MMI_MTE_IMAGE_JPG << 16), "", {{LCD_WIDTH, LCD_HEIGHT}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
    {"aphorism_screen_background_filler", 244, -1, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {136, 0, "", {0}, NULL}},
    {"progress_screen_background_filler", 245, -1, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {144, 0, "", {0}, NULL}},
    {"alarm_background_filler", 246, -1, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {156, 0, "", {0}, NULL}},
    {"menubar_index_background_color", 247, -1, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {268, 0, "", {0}, NULL}},
    {"menubar_item_background_color", 248, -1, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {272, 0, "", {0}, NULL}},
    {"menubar_index_text_color", 249, -1, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {276, 0, "", {0}, NULL}},
    {"menubar_item_text_color", 250, -1, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {280, 0, "", {0}, NULL}},
    {"drop_down_normal_text_color", 251, -1, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {284, 0, "", {0}, NULL}},
    {"drop_down_disabled_text_color", 252, -1, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {288, 0, "", {0}, NULL}},
    {"drop_down_focussed_text_color", 253, -1, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {292, 0, "", {0}, NULL}},
    {"formatted_inputbox_selector_color", 254, -1, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {296, 0, "", {0}, NULL}},
    {"formatted_inputbox_normal_text_color", 255, -1, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {300, 0, "", {0}, NULL}},
    {"formatted_inputbox_disabled_text_color", 256, -1, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {304, 0, "", {0}, NULL}},
    {"formatted_inputbox_selected_text_color", 257, -1, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {308, 0, "", {0}, NULL}},
    {"formatted_inputbox_cursor_color", 258, -1, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {312, 0, "", {0}, NULL}},
    {"calculator_color", 259, -1, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {488, 0, "", {0}, NULL}},
    {"alarm_text_color", 260, -1, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {492, 0, "", {0}, NULL}},
    {"menu_bar_index_font", 261, -1, MMI_MTE_THEME_DATA_TYPE_FONT, NULL, 0, 0, 0, 0, 0, {560, 0, "", {0}, NULL}},
    {"menu_bar_item_font", 262, -1, MMI_MTE_THEME_DATA_TYPE_FONT, NULL, 0, 0, 0, 0, 0, {564, 0, "", {0}, NULL}},
    {"drop_down_control_font", 263, -1, MMI_MTE_THEME_DATA_TYPE_FONT, NULL, 0, 0, 0, 0, 0, {576, 0, "", {0}, NULL}},
    {"matrix_highlight_filler", 264, -1, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {636, 0, "", {0}, NULL}},
    {"main_menu_icon1", 265, -1, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {920, 0, "", {0}, NULL}},
    {"main_menu_icon2", 266, -1, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {924, 0, "", {0}, NULL}},
    {"main_menu_icon3", 267, -1, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {928, 0, "", {0}, NULL}},
    {"main_menu_icon4", 268, -1, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {932, 0, "", {0}, NULL}},
    {"main_menu_icon5", 269, -1, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {936, 0, "", {0}, NULL}},
    {"main_menu_icon6", 270, -1, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {940, 0, "", {0}, NULL}},
    {"main_menu_icon7", 271, -1, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {944, 0, "", {0}, NULL}},
    {"main_menu_icon8", 272, -1, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {948, 0, "", {0}, NULL}},
    {"main_menu_icon9", 273, -1, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {952, 0, "", {0}, NULL}},
    {"main_menu_icon10", 274, -1, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {956, 0, "", {0}, NULL}},
    {"main_menu_icon11", 275, -1, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {960, 0, "", {0}, NULL}},
    {"main_menu_icon12", 276, -1, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {964, 0, "", {0}, NULL}},
    {"main_menu_icon13", 277, -1, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {968, 0, "", {0}, NULL}},
    {"main_menu_icon14", 278, -1, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {972, 0, "", {0}, NULL}},
    {"main_menu_icon15", 279, -1, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {976, 0, "", {0}, NULL}},
};


/* theme component English description */
static const wchar_t *g_mmi_mte_theme_component_description_EN[MMI_MTE_THEME_COMPONENT_NUM] =
{
    L"Calendar title text color",
    L"Calendar year select text color",
    L"Calendar year select text border color",
    L"Calendar week number text color",
    L"Calendar month select text color",
    L"Calendar week day text color",
    L"Calendar one task state cell background color",
    L"Calendar more tasks state cell background color",
    L"Calendar menstrual state cell background color",
    L"Calendar PP state cell background color",
    L"Calendar danger state cell background color",
    L"Calendar invalid state cell background color",
    L"Calendar valid state cell text color",
    L"Calendar invalid state cell text color",
    L"Calendar highlight state cell background color",
    L"Calendar info box background color",
    L"Calendar info box item background color",
    L"Calendar infobox text color",
    L"Calendar info box text font",
    L"Calendar week day text font",
    L"Calendar cell text font",
    L"Clock component: text font of date text for digital clock in main lcd",
    L"Clock component: text font of time text for digital clock in main lcd",
    L"Clock component: text color of date text for digital clock in main lcd",
    L"Clock component: text border color of date text for digital clock in main lcd",
    L"Clock component: text color of time text for digital clock in main lcd",
    L"Clock component: text border color of time text for digital clock in main lcd",
    L"Clock component: text font of date text for digital clock in sub lcd",
    L"Clock component: text font of time text for digital clock in sub lcd",
    L"Clock component: text color of date text for digital clock in sub lcd",
    L"Clock component: text border color of date text for digital clock in sub lcd",
    L"Clock component: text color of time text for digital clock in sub lcd",
    L"Clock component: text border color of time text for digital clock in sub lcd",
    L"Clock component: hour hand color of analog clock in main lcd",
    L"Clock component: minute hand color of analog clock in main lcd",
    L"Clock component: analog axis color (Set the wallpaper to 'Analog Clock' to see this.)",
    L"General background filler, background of text and picture, usually is white color.",
    L"Black color",
    L"White color",
    L"Lite display screen background color, used when the SCR BG image is absent. (Ex: WAP, Java)",
    L"Normal date and time inputbox background filler",
    L"Highlighted date and time inputbox background filler",
    L"Inline list menu background filler (128x128 only)",
    L"Normal inline list menu item background filler",
    L"Highlighted inline list menu item background filler",
    L"Disabled inline list menu item background filler (rarely used)",
    L"Highlighted inline singleline editor background filler",
    L"Normal inline singleline editor background filler",
    L"inline singleline editor without boundary background filler",
    L"Inline single line editor text color",
    L"Inline single line editor unfocussed text color",
    L"Inline single line editor selected text color",
    L"Inline single line editor selector color",
    L"Inline single line editor cursor color",
    L"Inline list menu item normal text color",
    L"Inline list menu item highlighted text color",
    L"Inline list menu item disabled text color (rarely used)",
    L"Inline list menu item background filler (only in phonebook Add New Entry)",
    L"Inline horizontal select left arrow image",
    L"Inline horizontal select right arrow image",
    L"Inputbox background filler",
    L"Inputbox normal text color",
    L"Inputbox highlighted text color",
    L"Inputbox highligthed background color",
    L"Inputbox cursor color",
    L"Information bar background color",
    L"IME text color",
    L"The message remaining length text color",
    L"Font of inputbox",
    L"Inputbox base line color",
    L"EMS control character base line color",
    L"IME under line color",
    L"IME indicator color",
    L"IME focused area background color",
    L"IME non-focused area background color",
    L"IME focused area border color",
    L"IME non-focused area border color",
    L"IME text color",
    L"IME label color",
    L"IME highlighted text background color",
    L"IME highlighted text color",
    L"IME cursor color",
    L"IME arrow color",
    L"IME text font",
    L"IME label text font",
    L"Virtual keyboard key down background filler",
    L"Text color of virtual keyboard key when it is selected",
    L"Text color of virtual keyboard key when it is not selected",
    L"Text color of virtual keyboard dead key when it is selected",
    L"Text color of virtual keyboard dead key when it is not selected",
    L"Text color of virtual keyboard display area",
    L"Font of virtual keyboard",
    L"Multitap inputbox background filler",
    L"Highlighted multitap inputbox background color",
    L"Multitatp inputbox normal text color",
    L"Multitatp inputbox highlighted text color",
    L"Font of multitap",
    L"Bidegree main menu tab highlight filler",
    L"Bidegree main menu tab normal background filler",
    L"Text color of the normal (unhighlited) 3D circular main menu item",
    L"Text color of the highlighted 3D circular main menu item",
    L"Text color of the disabled 3D circular main menu item (rarely used)",
    L"Normal list main menu item background filler",
    L"Highlighted list main menu item background filler",
    L"Disabled list main menu item background filler (rarely used)",
    L"Text color of the normal (unhighlited) list main menu item",
    L"Text color of the highlighted list main menu item",
    L"Text color of the disabled list main menu item (rarely used)",
    L"Font of list main menu",
    L"Main menu background filler for list and matrix menu (128x128 only)",
    L"Normal matrix main menu item background filler",
    L"Highlighted matrix main menu item background filler",
    L"Disabled matrix main menu item background filler (rarely used)",
    L"Text color of the normal (unhighlited) matrix main menu item",
    L"Text color of the highlighted matrix main menu item",
    L"Text color of the disabled matrix main menu item (rarely used)",
    L"Font of matrix main menu",
    L"Matrix main menu highlight image",
    L"Call manager screen background filler",
    L"Call manager screen text color",
    L"Call manager screen data time background color",
    L"Call manager screen time duration background color",
    L"Call manager screen date text color",
    L"Call manager screen time text color",
    L"Call manager screen duration text color",
    L"Advice Of Charge text color",
    L"Dialer input box background filler",
    L"The dialer input box text color",
    L"The dialer input box selected text color",
    L"The dialer input box selector color",
    L"The dialer input box corsor color",
    L"Dialer inputbox text color",
    L"Dialer inputbox text border color",
    L"Dialer inputbox in touch screen background filler",
    L"Date time and status bar 1 background filler",
    L"Idle screen date text color",
    L"Idle screen time text color",
    L"Idle screen date text border color",
    L"Idle screen time text border color",
    L"Idle screen network name text color",
    L"Idle screen network name text border color",
    L"Idle screen network status text color",
    L"Idle screen network status text border color",
    L"Idle screen network extra text color, such as MP3 song name in play.",
    L"Idle screen network extra text border color,  such as MP3 song name in play.",
    L"Idle screen weekday text color",
    L"Idle screen weekday text border color",
    L"PIN input editor background filler",
    L"PIN input screen background filler",
    L"PIN input editor text color",
    L"PIN input editor selected text color",
    L"PIN input editor selector color",
    L"PIN input editor cursor color",
    L"Popup background color (used when 'popup_bkg_image' is not set)",
    L"Popup border color",
    L"Popup background image",
    L"Popup text color",
    L"Rotated screen background filler",
    L"Rotated popup screen background image",
    L"Rotated screen title background filler",
    L"Normal small list screen background filler",
    L"Small list screen background border filler",
    L"Small list screen title background filler",
    L"Symbol picker highlight filler",
    L"Scrollbar background filler",
    L"Scrollbar button background filler",
    L"width of vertical scroll bar or height of horizontal scroll bar",
    L"Text color of normal left softkey",
    L"Text color of down left softkey",
    L"Text color of disabled left softkey (rarely used)",
    L"Text color of normal right softkey",
    L"Text color of down right softkey",
    L"Text color of disabled right softkey (rarely used)",
    L"Font of button",
    L"Softkey bar text border color",
    L"Softkey bar background filler",
    L"Left softkey down filler",
    L"Left softkey up filler",
    L"Right softkey down filler",
    L"Right softkey up filler",
    L"Status icon bar background filler",
    L"Cascade menu separator color",
    L"Cascade menu normal text color",
    L"Cascade menu highlighted text color",
    L"Cascade menu disabled text color",
    L"Cascade menu border color",
    L"Cascade menu background filler",
    L"Cascade menu item highlight filler",
    L"Cascade menu left arrow image",
    L"Cascade menu right arrow image",
    L"List menu hint description text color and category 165 count down popup text color",
    L"List menu background filler (128x128 only)",
    L"Normal list menu item background filler (rarely used)",
    L"Highlighted list menu item background filler (if the menuitem_xxx_filler is an image and the image dimension does not fit well in the current menu. )",
    L"Disabled list menu item background filler (rarely used)",
    L"List menu hint description background filler",
    L"Text color of the normal (unhighlited) list menu item",
    L"Text color of the highlighted list menu item",
    L"Text color of the disabled list menu item (rarely used)",
    L"Font of list menu",
    L"Single-line highlighted menu item background filler (The image dimension must be the same to the recommended dimension if using an image.)",
    L"Two-line highlighted menu item background filler (The image dimension must be the same to the recommended dimension if using an image.)",
    L"Multi-row highlighted menu item background filler (The image dimension must be the same to the recommended dimension if using an image.)",
    L"Thick highlighted menu item background filler (The image dimension must be the same to the recommended dimension if using an image.)",
    L"Thick with tab menu item background filler (Category 425 only. The image dimension must be the same to the recommended dimension if using an image.)",
    L"List menu separator color",
    L"List menu check box selected icon image",
    L"List menu check box unselected icon image",
    L"List menu radio box selected icon image",
    L"List menu radio box unselected icon image",
    L"Matrix menu background filler",
    L"Normal matrix menu item background filler (rarely used)",
    L"Highlighted matrix menu item background filler",
    L"Disabled matrix menu item background filler (rarely used)",
    L"Text color of the normal matrix menu item",
    L"Text color of the highlighted matrix menu item",
    L"Text color of the disabled matrix menu item (rarely used)",
    L"Font of matrix menu",
    L"Tab title background filler",
    L"Tab title text color",
    L"Tab title text border color",
    L"Tab title shortcut text color",
    L"Font of tab title",
    L"Tab bar normal background filler",
    L"Tab bar highlighted background filler",
    L"Tab bar blinking background filler",
    L"Title background filler",
    L"Title text color",
    L"Title text border color",
    L"Text color of shortcut",
    L"Font of title (same as 'title_text_font')",
    L"Font of shortcut",
    L"Font of title (same as 'window_title_font')",
    L"Thick title backgournd filler",
    L"Thick title text color",
    L"Thick title text border color",
    L"Thick title shortcut text color",
    L"Full opacity of screen",
    L"High opacity of screen (Not used)",
    L"Medium opacity of screen (Not used)",
    L"Low opacity of screen (used in Editor)",
    L"Main menu background filler",
    L"Sub menu background filler",
    L"Idle screen background filler (set the wallpaper to 'Theme Image' to see it)",
    L"",
    L"",
    L"",
    L"",
    L"",
    L"",
    L"",
    L"",
    L"",
    L"",
    L"",
    L"",
    L"",
    L"",
    L"",
    L"",
    L"",
    L"",
    L"",
    L"",
    L"",
    L"",
    L"",
    L"",
    L"",
    L"",
    L"",
    L"",
    L"",
    L"",
    L"",
    L"",
    L"",
    L"",
    L"",
    L"",
};


/* theme component GB description */
static const wchar_t *g_mmi_mte_theme_component_description_GB[MMI_MTE_THEME_COMPONENT_NUM] =
{
    L"\x65E5\x5386\x6807\x9898\x6587\x672C\x8272",
    L"\x65E5\x5386\x4E2D\x5E74\x4EFD\x002F\x6708\x4EFD\x9009\x62E9\x5BF9\x5E94\x672C\x8272",
    L"\x65E5\x5386\x4E2D\x5E74\x4EFD\x002F\x6708\x4EFD\x9009\x62E9\x5BF9\x5E94\x6587\x672C\x8FB9\x6846\x8272",
    L"\x65E5\x5386\x4E2D\x7B2C\x51E0\x5468\xFF08\x5468\x89C6\x56FE\xFF09\x002F\x7B2C\x51E0\x5C0F\x65F6\x0028\x6708\x89C6\x56FE\x0029\x5BF9\x5E94\x6587\x672C\x8272",
    L"\x65E5\x5386\x4E2D\x661F\x671F\x51E0\x5BF9\x5E94\x6587\x672C\x8272",
    L"\x65E5\x5386\x4E2D\x5F53\x524D\x5929\x65E5\x671F\x5BF9\x5E94\x6587\x672C\x8272",
    L"\x65E5\x5386\x4E2D\x5355\x4EFB\x52A1\x5355\x5143\x7684\x80CC\x666F\x8272",
    L"\x65E5\x5386\x4E2D\x591A\x4EFB\x52A1\x5355\x5143\x7684\x80CC\x666F\x8272",
    L"\x65E5\x5386\x4E2D\x751F\x7406\x671F\x5BF9\x5E94\x5355\x5143\x7684\x80CC\x666F\x8272",
    L"\x65E5\x5386\x4E2D\x53D7\x5B55\x671F\x5BF9\x5E94\x5355\x5143\x7684\x80CC\x666F\x8272",
    L"\x65E5\x5386\x4E2D\x5371\x9669\x671F\x5BF9\x5E94\x5355\x5143\x7684\x80CC\x666F\x8272",
    L"\x65E5\x5386\x4E2D\x65E0\x5371\x9669\x5BF9\x5E94\x5355\x5143\x7684\x80CC\x666F\x8272",
    L"\x65E5\x5386\x4E2D\x6709\x6548\x5355\x5143\x6587\x672C\x8272",
    L"\x65E5\x5386\x4E2D\x65E0\x6548\x5355\x5143\x6587\x672C\x8272",
    L"\x65E5\x5386\x4E2D\x9AD8\x4EAE\x6846\x7684\x989C\x8272",
    L"\x65E5\x5386\x4FE1\x606F\x6846\x7684\x80CC\x666F\x8272",
    L"\x65E5\x5386\x4FE1\x606F\x6846\x4E2D\x6BCF\x9879\x7684\x80CC\x666F\x8272",
    L"\x65E5\x5386\x4FE1\x606F\x6846\x6587\x672C\x8272",
    L"\x65E5\x5386\x4FE1\x606F\x6846\x6587\x672C\x5B57\x4F53",
    L"\x65E5\x5386\x661F\x671F\x51E0\x5BF9\x5E94\x6587\x672C\x5B57\x4F53",
    L"\x65E5\x5386\x5355\x5143\x6587\x672C\x5B57\x4F53",
    L"\x65F6\x949F\x7EC4\x4EF6\xFF1A\x4E3B\x5C4F\x6570\x5B57\x65F6\x949F\x65E5\x671F\x6587\x672C\x5B57\x4F53",
    L"\x65F6\x949F\x7EC4\x4EF6\xFF1A\x4E3B\x5C4F\x6570\x5B57\x65F6\x949F\x65F6\x95F4\x6587\x672C\x5B57\x4F53",
    L"\x65F6\x949F\x7EC4\x4EF6\xFF1A\x4E3B\x5C4F\x6570\x5B57\x65F6\x949F\x65E5\x671F\x6587\x672C\x8272",
    L"\x65F6\x949F\x7EC4\x4EF6\xFF1A\x4E3B\x5C4F\x6570\x5B57\x65F6\x949F\x65E5\x671F\x6587\x672C\x8FB9\x6846\x8272",
    L"\x65F6\x949F\x7EC4\x4EF6\xFF1A\x4E3B\x5C4F\x6570\x5B57\x65F6\x949F\x65F6\x95F4\x6587\x672C\x8272",
    L"\x65F6\x949F\x7EC4\x4EF6\xFF1A\x4E3B\x5C4F\x6570\x5B57\x65F6\x949F\x65F6\x95F4\x6587\x672C\x8FB9\x6846\x8272",
    L"\x65F6\x949F\x7EC4\x4EF6\xFF1A\x526F\x5C4F\x6570\x5B57\x65F6\x949F\x65E5\x671F\x6587\x672C\x5B57\x4F53",
    L"\x65F6\x949F\x7EC4\x4EF6\xFF1A\x526F\x5C4F\x6570\x5B57\x65F6\x949F\x65F6\x95F4\x6587\x672C\x5B57\x4F53",
    L"\x65F6\x949F\x7EC4\x4EF6\xFF1A\x526F\x5C4F\x6570\x5B57\x65F6\x949F\x65E5\x671F\x6587\x672C\x8272",
    L"\x65F6\x949F\x7EC4\x4EF6\xFF1A\x526F\x5C4F\x6570\x5B57\x65F6\x949F\x65E5\x671F\x6587\x672C\x8FB9\x6846\x8272",
    L"\x65F6\x949F\x7EC4\x4EF6\xFF1A\x526F\x5C4F\x6570\x5B57\x65F6\x949F\x65F6\x95F4\x6587\x672C\x8272",
    L"\x65F6\x949F\x7EC4\x4EF6\xFF1A\x526F\x5C4F\x6570\x5B57\x65F6\x949F\x65F6\x95F4\x6587\x672C\x8FB9\x6846\x8272",
    L"\x65F6\x949F\x7EC4\x4EF6\xFF1A\x4E3B\x5C4F\x6A21\x62DF\x65F6\x949F\x5C0F\x65F6\x6307\x9488\x7684\x989C\x8272",
    L"\x65F6\x949F\x7EC4\x4EF6\xFF1A\x4E3B\x5C4F\x6A21\x62DF\x65F6\x949F\x5206\x949F\x6307\x9488\x7684\x989C\x8272",
    L"\x65F6\x949F\x7EC4\x4EF6\xFF1A\x4E3B\x5C4F\x6A21\x62DF\x65F6\x949F\x8F74\x7EBF\x7684\x989C\x8272\xFF08\x5C06\x5899\x7EB8\x8BBE\x4E3A\x6A21\x62DF\x65F6\x949F\x4EE5\x663E\x793A\xFF09",
    L"\x901A\x7528\x80CC\x666F\x586B\x5145\xFF0C\x7528\x4E8E\x6587\x672C\x548C\x56FE\x7247\x7684\x80CC\x666F\xFF0C\x901A\x5E38\x4E3A\x767D\x8272",
    L"\x9ED1\x8272",
    L"\x767D\x8272",
    L"\x663E\x793A\x754C\x9762\x7684\x6D45\x80CC\x666F\x8272\xFF0C\x7528\x4E8E\x6CA1\x6709\x80CC\x666F\x56FE\x7247\x7684\x60C5\x51B5\xFF08\x5982\xFF1A\x0057\x0041\x0050\xFF0C\x004A\x0061\x0076\x0061\xFF09",
    L"\x65E5\x671F\x65F6\x95F4\x8F93\x5165\x6846\x6807\x51C6\x80CC\x666F\x586B\x5145",
    L"\x65E5\x671F\x65F6\x95F4\x8F93\x5165\x6846\x9AD8\x4EAE\x80CC\x666F\x586B\x5145",
    L"\x53EF\x8F93\x5165\x5217\x8868\x5F0F\x83DC\x5355\x80CC\x666F\x586B\x5145\xFF08\x4EC5\x9650\x0031\x0032\x0038\x0078\x0031\x0032\x0038\xFF09",
    L"\x53EF\x8F93\x5165\x5217\x8868\x5F0F\x83DC\x5355\x6807\x51C6\x83DC\x5355\x9879\x80CC\x666F\x586B\x5145",
    L"\x53EF\x8F93\x5165\x5217\x8868\x5F0F\x83DC\x5355\x9AD8\x4EAE\x83DC\x5355\x9879\x80CC\x666F\x586B\x5145",
    L"\x53EF\x8F93\x5165\x5217\x8868\x5F0F\x83DC\x5355\x7981\x7528\x83DC\x5355\x9879\x80CC\x666F\x586B\x5145\xFF08\x8F83\x5C11\x4F7F\x7528\xFF09",
    L"\x53EF\x7F16\x8F91\x5355\x884C\x5217\x8868\x9879\x9AD8\x4EAE\x80CC\x666F\x586B\x5145",
    L"\x53EF\x7F16\x8F91\x5355\x884C\x5217\x8868\x9879\x6807\x51C6\x80CC\x666F\x586B\x5145",
    L"\x53EF\x7F16\x8F91\x5355\x884C\x5217\x8868\x9879\x65E0\x8FB9\x6846\x80CC\x666F\x586B\x5145",
    L"\x53EF\x7F16\x8F91\x5355\x884C\x5217\x8868\x9879\x6587\x672C\x8272",
    L"\x53EF\x7F16\x8F91\x5355\x884C\x5217\x8868\x9879\x975E\x9AD8\x4EAE\x6587\x672C\x8272",
    L"\x53EF\x7F16\x8F91\x5355\x884C\x5217\x8868\x9879\x88AB\x9009\x4E2D\x6587\x672C\x8272",
    L"\x53EF\x7F16\x8F91\x5355\x884C\x5217\x8868\x9879\x9009\x4E2D\x9AD8\x4EAE\x8272",
    L"\x53EF\x7F16\x8F91\x5355\x884C\x5217\x8868\x9879\x5149\x6807\x586B\x5145\x8272",
    L"\x53EF\x8F93\x5165\x5217\x8868\x5F0F\x83DC\x5355\x83DC\x5355\x9879\x6807\x51C6\x6587\x672C\x8272",
    L"\x53EF\x8F93\x5165\x5217\x8868\x5F0F\x83DC\x5355\x83DC\x5355\x9879\x9AD8\x4EAE\x6587\x672C\x8272",
    L"\x53EF\x8F93\x5165\x5217\x8868\x5F0F\x83DC\x5355\x83DC\x5355\x9879\x7981\x7528\x6587\x672C\x8272\xFF08\x8F83\x5C11\x4F7F\x7528\xFF09",
    L"\x53EF\x7F16\x8F91\x5217\x8868\x9879\x80CC\x666F\x586B\x5145\xFF08\x53EA\x5728\x7535\x8BDD\x672C\x65B0\x589E\x8BB0\x5F55\x65F6\x4F7F\x7528\xFF09",
    L"\x6C34\x5E73\x9009\x62E9\x7EC4\x4EF6\x5DE6\x7BAD\x5934\x7684\x56FE\x7247",
    L"\x6C34\x5E73\x9009\x62E9\x7EC4\x4EF6\x53F3\x7BAD\x5934\x7684\x56FE\x7247",
    L"\x8F93\x5165\x6846\x80CC\x666F\x586B\x5145",
    L"\x8F93\x5165\x6846\x6807\x51C6\x6587\x672C\x8272",
    L"\x8F93\x5165\x6846\x9AD8\x4EAE\x6587\x672C\x8272",
    L"\x8F93\x5165\x6846\x9AD8\x4EAE\x80CC\x666F\x8272",
    L"\x8F93\x5165\x6846\x5149\x6807\x586B\x5145\x8272",
    L"\x4FE1\x606F\x680F\x80CC\x666F\x8272",
    L"\x8F93\x5165\x6CD5\x6587\x672C\x8272",
    L"\x8F93\x5165\x6846\x7684\x5269\x4F59\x5B57\x6570\x7EDF\x8BA1\x6587\x672C\x8272",
    L"\x8F93\x5165\x6846\x6587\x672C\x5B57\x4F53",
    L"\x7F16\x8F91\x5668\x57FA\x7EBF\x7684\x7EBF\x6761\x989C\x8272",
    L"\x0045\x004D\x0053\x0020\x7F16\x8F91\x5668\x6587\x5B57\x57FA\x7EBF\x7684\x7EBF\x6761\x989C\x8272",
    L"\x8F93\x5165\x6CD5\x7F16\x8F91\x5668\x4E2D\x4E0B\x5212\x7EBF\x7684\x989C\x8272",
    L"\x8F93\x5165\x6CD5\x7F16\x8F91\x5668\x4E2D\x62FC\x97F3\x6B67\x4E49\x6807\x8BC6\x7684\x989C\x8272",
    L"\x8F93\x5165\x6CD5\x7F16\x8F91\x5668\x4E2D\x7126\x70B9\x533A\x57DF\x80CC\x666F\x8272",
    L"\x8F93\x5165\x6CD5\x7F16\x8F91\x5668\x4E2D\x975E\x7126\x70B9\x533A\x57DF\x80CC\x666F\x8272",
    L"\x8F93\x5165\x6CD5\x7F16\x8F91\x5668\x4E2D\x7126\x70B9\x533A\x57DF\x8FB9\x6846\x8272",
    L"\x8F93\x5165\x6CD5\x7F16\x8F91\x5668\x4E2D\x975E\x7126\x70B9\x533A\x57DF\x8FB9\x6846\x8272",
    L"\x8F93\x5165\x6CD5\x7F16\x8F91\x5668\x4E2D\x6587\x672C\x8272",
    L"\x8F93\x5165\x6CD5\x7F16\x8F91\x5668\x4E2D\x5019\x9009\x5B57\x6807\x53F7\x7684\x989C\x8272",
    L"\x8F93\x5165\x6CD5\x7F16\x8F91\x5668\x4E2D\x9AD8\x4EAE\x6587\x672C\x80CC\x666F\x8272",
    L"\x8F93\x5165\x6CD5\x7F16\x8F91\x5668\x4E2D\x9AD8\x4EAE\x6587\x672C\x8272",
    L"\x8F93\x5165\x6CD5\x7F16\x8F91\x5668\x4E2D\x5149\x6807\x7684\x989C\x8272",
    L"\x8F93\x5165\x6CD5\x7F16\x8F91\x5668\x4E2D\x7BAD\x5934\x7684\x989C\x8272",
    L"\x8F93\x5165\x6CD5\x7F16\x8F91\x5668\x4E2D\x6587\x672C\x5B57\x4F53",
    L"\x8F93\x5165\x6CD5\x7F16\x8F91\x5668\x4E2D\x5019\x9009\x5B57\x6807\x53F7\x7684\x5B57\x4F53",
    L"\x865A\x62DF\x952E\x76D8\x6309\x952E\x6309\x4E0B\x72B6\x6001\x80CC\x666F\x586B\x5145",
    L"\x865A\x62DF\x952E\x76D8\x6309\x952E\x88AB\x9009\x4E2D\x65F6\x7684\x6587\x672C\x8272",
    L"\x865A\x62DF\x952E\x76D8\x6309\x952E\x672A\x9009\x4E2D\x65F6\x7684\x6587\x672C\x8272",
    L"\x865A\x62DF\x952E\x76D8\x53D8\x97F3\x7B26\x53F7\x88AB\x9009\x4E2D\x65F6\x7684\x6587\x672C\x8272",
    L"\x865A\x62DF\x952E\x76D8\x53D8\x97F3\x7B26\x53F7\x672A\x9009\x4E2D\x65F6\x7684\x6587\x672C\x8272",
    L"\x865A\x62DF\x952E\x76D8\x663E\x793A\x533A\x57DF\x7684\x6587\x672C\x8272",
    L"\x865A\x62DF\x952E\x76D8\x6587\x672C\x5B57\x4F53",
    L"\x5168\x952E\x6587\x672C\x8F93\x5165\x6CD5\x8F93\x5165\x6846\x80CC\x666F\x586B\x5145",
    L"\x5168\x952E\x6587\x672C\x8F93\x5165\x6CD5\x8F93\x5165\x6846\x9AD8\x4EAE\x80CC\x666F\x8272",
    L"\x5168\x952E\x6587\x672C\x8F93\x5165\x6CD5\x8F93\x5165\x6846\x6807\x51C6\x6587\x672C\x8272",
    L"\x5168\x952E\x6587\x672C\x8F93\x5165\x6CD5\x8F93\x5165\x6846\x9AD8\x4EAE\x6587\x672C\x8272",
    L"\x5168\x952E\x6587\x672C\x8F93\x5165\x6CD5\x6587\x672C\x5B57\x4F53",
    L"\x53CC\x5217\x5F0F\x4E3B\x83DC\x5355\x6807\x7B7E\x7684\x9AD8\x4EAE\x80CC\x666F\x586B\x5145",
    L"\x53CC\x5217\x5F0F\x4E3B\x83DC\x5355\x6807\x7B7E\x7684\x6B63\x5E38\x80CC\x666F\x586B\x5145",
    L"\x0033\x0044\x0020\x5FAA\x73AF\x5F0F\x4E3B\x83DC\x5355\x6807\x51C6\xFF08\x975E\x9AD8\x4EAE\xFF09\x83DC\x5355\x9879\x6587\x672C\x8272",
    L"\x0033\x0044\x0020\x5FAA\x73AF\x5F0F\x4E3B\x83DC\x5355\x9AD8\x4EAE\x83DC\x5355\x9879\x6587\x672C\x8272",
    L"\x0033\x0044\x0020\x5FAA\x73AF\x5F0F\x4E3B\x83DC\x5355\x7981\x7528\x83DC\x5355\x9879\x6587\x672C\x8272\xFF08\x8F83\x5C11\x4F7F\x7528\xFF09",
    L"\x5217\x8868\x5F0F\x4E3B\x83DC\x5355\x6807\x51C6\x83DC\x5355\x9879\x80CC\x666F\x586B\x5145",
    L"\x5217\x8868\x5F0F\x4E3B\x83DC\x5355\x9AD8\x4EAE\x83DC\x5355\x9879\x80CC\x666F\x586B\x5145",
    L"\x5217\x8868\x5F0F\x4E3B\x83DC\x5355\x7981\x7528\x83DC\x5355\x9879\x80CC\x666F\x586B\x5145\xFF08\x8F83\x5C11\x4F7F\x7528\xFF09",
    L"\x5217\x8868\x5F0F\x4E3B\x83DC\x5355\x6807\x51C6\xFF08\x975E\x9AD8\x4EAE\xFF09\x83DC\x5355\x9879\x6587\x672C\x8272",
    L"\x5217\x8868\x5F0F\x4E3B\x83DC\x5355\x9AD8\x4EAE\x83DC\x5355\x9879\x6587\x672C",
    L"\x5217\x8868\x5F0F\x4E3B\x83DC\x5355\x7981\x7528\x83DC\x5355\x9879\x6587\x672C\x8272\xFF08\x8F83\x5C11\x4F7F\x7528\xFF09",
    L"\x5217\x8868\x5F0F\x4E3B\x83DC\x5355\x6587\x672C\x5B57\x4F53",
    L"\x5217\x8868\x002F\x77E9\x9635\x5F0F\x4E3B\x83DC\x5355\x80CC\x666F\x586B\x5145\xFF08\x4EC5\x9650\x0031\x0032\x0038\x0078\x0031\x0032\x0038\xFF09",
    L"\x77E9\x9635\x5F0F\x4E3B\x83DC\x5355\x6807\x51C6\x83DC\x5355\x9879\x80CC\x666F\x586B\x5145",
    L"\x77E9\x9635\x5F0F\x4E3B\x83DC\x5355\x9AD8\x4EAE\x83DC\x5355\x9879\x80CC\x666F\x586B\x5145",
    L"\x77E9\x9635\x5F0F\x4E3B\x83DC\x5355\x7981\x7528\x83DC\x5355\x9879\x80CC\x666F\x586B\x5145\xFF08\x8F83\x5C11\x4F7F\x7528\xFF09",
    L"\x77E9\x9635\x5F0F\x4E3B\x83DC\x5355\x6807\x51C6\xFF08\x975E\x9AD8\x4EAE\xFF09\x83DC\x5355\x9879\x6587\x672C\x8272",
    L"\x77E9\x9635\x5F0F\x4E3B\x83DC\x5355\x9AD8\x4EAE\x83DC\x5355\x9879\x6587\x672C\x8272",
    L"\x77E9\x9635\x5F0F\x4E3B\x83DC\x5355\x7981\x7528\x83DC\x5355\x9879\x6587\x672C\x8272\xFF08\x8F83\x5C11\x4F7F\x7528\xFF09",
    L"\x77E9\x9635\x5F0F\x4E3B\x83DC\x5355\x6587\x672C\x5B57\x4F53",
    L"\x77E9\x9635\x5F0F\x4E3B\x83DC\x5355\x9AD8\x4EAE\x7684\x56FE\x7247",
    L"\x901A\x8BDD\x8BB0\x5F55\x754C\x9762\x80CC\x666F\x586B\x5145",
    L"\x901A\x8BDD\x8BB0\x5F55\x754C\x9762\x6587\x672C\x989C\x8272",
    L"\x901A\x8BDD\x8BB0\x5F55\x754C\x9762\x65E5\x671F\x65F6\x95F4\x80CC\x666F\x8272",
    L"\x901A\x8BDD\x8BB0\x5F55\x754C\x9762\x901A\x8BDD\x65F6\x95F4\x80CC\x666F\x8272",
    L"\x901A\x8BDD\x8BB0\x5F55\x754C\x9762\x65E5\x671F\x6587\x672C\x8272",
    L"\x901A\x8BDD\x8BB0\x5F55\x754C\x9762\x65F6\x95F4\x6587\x672C\x8272",
    L"\x901A\x8BDD\x8BB0\x5F55\x754C\x9762\x901A\x8BDD\x65F6\x95F4\x6587\x672C\x8272",
    L"\x5145\x7535\x63D0\x793A\x8BED\x7684\x6587\x672C\x8272",
    L"\x62E8\x53F7\x8F93\x5165\x6846\x80CC\x666F\x586B\x5145",
    L"\x62E8\x53F7\x8F93\x5165\x6846\x6587\x672C\x8272",
    L"\x62E8\x53F7\x8F93\x5165\x6846\x88AB\x9009\x4E2D\x6587\x672C\x8272",
    L"\x62E8\x53F7\x8F93\x5165\x6846\x9009\x4E2D\x9AD8\x4EAE\x8272",
    L"\x62E8\x53F7\x8F93\x5165\x6846\x5149\x6807\x586B\x5145\x8272",
    L"\x62E8\x53F7\x7F16\x8F91\x5668\x6587\x672C\x8272",
    L"\x62E8\x53F7\x7F16\x8F91\x5668\x6587\x672C\x8FB9\x6846\x8272",
    L"\x89E6\x6478\x5C4F\x4E0A\x62E8\x53F7\x7F16\x8F91\x5668\x7684\x80CC\x666F\x586B\x5145",
    L"\x65E5\x671F\x65F6\x95F4\x548C\x72B6\x6001\x680F\x0031\x7684\x80CC\x666F\x586B\x5145",
    L"\x5F85\x673A\x754C\x9762\x65E5\x671F\x6587\x672C\x8272",
    L"\x5F85\x673A\x754C\x9762\x65F6\x95F4\x6587\x672C\x8272",
    L"\x5F85\x673A\x754C\x9762\x65E5\x671F\x6587\x672C\x8FB9\x6846\x8272",
    L"\x5F85\x673A\x754C\x9762\x65F6\x95F4\x6587\x672C\x8FB9\x6846\x8272",
    L"\x5F85\x673A\x754C\x9762\x7F51\x7EDC\x540D\x79F0\x6587\x672C\x8272",
    L"\x5F85\x673A\x754C\x9762\x7F51\x7EDC\x540D\x79F0\x6587\x672C\x8FB9\x6846\x8272",
    L"\x5F85\x673A\x754C\x9762\x7F51\x7EDC\x72B6\x6001\x6587\x672C\x8272",
    L"\x5F85\x673A\x754C\x9762\x7F51\x7EDC\x72B6\x6001\x6587\x672C\x8FB9\x6846\x8272",
    L"\x5F85\x673A\x754C\x9762\x7F51\x7EDC\x5176\x4F59\x6587\x672C\x8272\xFF0C\x5982\x6B63\x5728\x64AD\x653E\x7684\x0020\x004D\x0050\x0033\x0020\x6B4C\x66F2\x540D\x79F0",
    L"\x5F85\x673A\x754C\x9762\x7F51\x7EDC\x5176\x4F59\x6587\x672C\x8FB9\x6846\x8272\xFF0C\x5982\x6B63\x5728\x64AD\x653E\x7684\x0020\x004D\x0050\x0033\x0020\x6B4C\x66F2\x540D\x79F0",
    L"\x5F85\x673A\x754C\x9762\x661F\x671F\x51E0\x5BF9\x5E94\x6587\x672C\x8272",
    L"\x5F85\x673A\x754C\x9762\x661F\x671F\x51E0\x5BF9\x5E94\x6587\x672C\x8FB9\x6846\x8272",
    L"\x0050\x0049\x004E\x0020\x7801\x8F93\x5165\x7F16\x8F91\x6846\x80CC\x666F\x586B\x5145",
    L"\x0050\x0049\x004E\x0020\x7801\x8F93\x5165\x754C\x9762\x80CC\x666F\x586B\x5145",
    L"\x0050\x0049\x004E\x0020\x7801\x8F93\x5165\x6846\x6587\x672C\x8272",
    L"\x0050\x0049\x004E\x0020\x7801\x8F93\x5165\x6846\x88AB\x9009\x4E2D\x6587\x672C\x8272",
    L"\x0050\x0049\x004E\x0020\x7801\x8F93\x5165\x6846\x9009\x4E2D\x9AD8\x4EAE\x8272",
    L"\x0050\x0049\x004E\x0020\x7801\x8F93\x5165\x6846\x5149\x6807\x586B\x5145\x8272",
    L"\x5F39\x51FA\x6846\x80CC\x666F\x8272\xFF08\x7528\x4E8E\x0020\x0070\x006F\x0070\x0075\x0070\x005F\x0062\x006B\x0067\x005F\x0069\x006D\x0061\x0067\x0065\x0020\x6CA1\x6709\x88AB\x8BBE\x7F6E\x7684\x60C5\x51B5\xFF09",
    L"\x5F39\x51FA\x6846\x8FB9\x6846\x8272",
    L"\x5F39\x51FA\x5F0F\x63D0\x793A\x6846\x7684\x80CC\x666F\x56FE\x7247",
    L"\x5F39\x51FA\x5F0F\x63D0\x793A\x6846\x6587\x672C\x8272",
    L"\x65CB\x8F6C\x540E\x753B\x9762\x7684\x80CC\x666F\x586B\x5145",
    L"\x65CB\x8F6C\x540E\x5F39\x51FA\x5F0F\x63D0\x793A\x6846\x753B\x9762\x7684\x80CC\x666F\x56FE\x7247",
    L"\x65CB\x8F6C\x540E\x753B\x9762\x6807\x9898\x7684\x80CC\x666F\x586B\x5145",
    L"\x975E\x5168\x5C4F\x5217\x8868\x754C\x9762\x6807\x51C6\x80CC\x666F\x586B\x5145",
    L"\x975E\x5168\x5C4F\x5217\x8868\x5F0F\x83DC\x5355\x80CC\x666F\x8FB9\x6846\x586B\x5145",
    L"\x975E\x5168\x5C4F\x5217\x8868\x5F0F\x83DC\x5355\x6807\x9898\x7684\x80CC\x666F\x586B\x5145",
    L"\x7B26\x53F7\x9009\x62E9\x753B\x9762\x9AD8\x4EAE\x7684\x586B\x5145",
    L"\x6EDA\x52A8\x6761\x80CC\x666F\x586B\x5145",
    L"\x6EDA\x52A8\x6761\x6ED1\x5757\x80CC\x666F\x586B\x5145",
    L"\x5782\x76F4\x6EDA\x52A8\x6761\x7684\x5BBD\x5EA6\x6216\x8005\x6C34\x5E73\x6EDA\x52A8\x6761\x7684\x9AD8\x5EA6",
    L"\x5DE6\x8F6F\x952E\x6807\x51C6\x72B6\x6001\x6587\x672C\x8272",
    L"\x5DE6\x8F6F\x952E\x6309\x4E0B\x72B6\x6001\x6587\x672C\x8272",
    L"\x5DE6\x8F6F\x952E\x7981\x7528\x72B6\x6001\x6587\x672C\x8272\xFF08\x8F83\x5C11\x4F7F\x7528\xFF09",
    L"\x53F3\x8F6F\x952E\x6807\x51C6\x72B6\x6001\x6587\x672C\x8272",
    L"\x53F3\x8F6F\x952E\x6309\x4E0B\x72B6\x6001\x6587\x672C\x8272",
    L"\x53F3\x8F6F\x952E\x7981\x7528\x72B6\x6001\x6587\x672C\x8272\xFF08\x8F83\x5C11\x4F7F\x7528\xFF09",
    L"\x6309\x94AE\x6587\x672C\x5B57\x4F53",
    L"\x8F6F\x952E\x533A\x6587\x672C\x8FB9\x6846\x8272",
    L"\x8F6F\x952E\x533A\x7684\x80CC\x666F\x586B\x5145",
    L"\x5DE6\x8F6F\x952E\x6309\x4E0B\x65F6\x7684\x586B\x5145",
    L"\x5DE6\x8F6F\x952E\x5F39\x8D77\x65F6\x7684\x586B\x5145",
    L"\x53F3\x8F6F\x952E\x6309\x4E0B\x65F6\x7684\x586B\x5145",
    L"\x53F3\x8F6F\x952E\x5F39\x8D77\x65F6\x7684\x586B\x5145",
    L"\x72B6\x6001\x680F\x80CC\x666F\x586B\x5145",
    L"\x5C42\x53E0\x5F0F\x83DC\x5355\x5206\x9694\x7EBF\x7684\x989C\x8272",
    L"\x5C42\x53E0\x5F0F\x83DC\x5355\x6B63\x5E38\x83DC\x5355\x9879\x6587\x672C\x8272",
    L"\x5C42\x53E0\x5F0F\x83DC\x5355\x9AD8\x4EAE\x83DC\x5355\x9879\x6587\x672C\x8272",
    L"\x5C42\x53E0\x5F0F\x83DC\x5355\x65E0\x6548\x83DC\x5355\x9879\x6587\x672C\x8272",
    L"\x5C42\x53E0\x5F0F\x83DC\x5355\x8FB9\x6846\x8272",
    L"\x5C42\x53E0\x5F0F\x83DC\x5355\x80CC\x666F\x586B\x5145",
    L"\x5C42\x53E0\x5F0F\x83DC\x5355\x9AD8\x4EAE\x83DC\x5355\x9879\x7684\x586B\x5145",
    L"\x5C42\x53E0\x5F0F\x83DC\x5355\x5DE6\x7BAD\x5934\x7684\x56FE\x7247",
    L"\x5C42\x53E0\x5F0F\x83DC\x5355\x53F3\x7BAD\x5934\x7684\x56FE\x7247",
    L"\x5217\x8868\x5F0F\x83DC\x5355\x63D0\x793A\x6587\x672C\x8272\x548C\x0020\x0031\x0036\x0035\x0020\x53F7\x7C7B\x522B\x7684\x5012\x8BA1\x6570\x5F39\x51FA\x6846\x6587\x672C\x8272",
    L"\x5217\x8868\x5F0F\x83DC\x5355\x80CC\x666F\x586B\x5145\xFF08\x4EC5\x9650\x0031\x0032\x0038\x0078\x0031\x0032\x0038\xFF09",
    L"\x5217\x8868\x5F0F\x83DC\x5355\x6807\x51C6\x83DC\x5355\x9879\x80CC\x666F\x586B\x5145\xFF08\x8F83\x5C11\x4F7F\x7528\xFF09",
    L"\x5217\x8868\x5F0F\x83DC\x5355\x9AD8\x4EAE\x83DC\x5355\x9879\x80CC\x666F\x586B\x5145\xFF08\x82E5\x9AD8\x4EAE\x80CC\x666F\x56FE\x957F\x5BBD\x4E0D\x7B26\x5408\x76EE\x524D\x83DC\x5355\x663E\x793A\x9700\x6C42\x0029",
    L"\x5217\x8868\x5F0F\x83DC\x5355\x7981\x7528\x83DC\x5355\x9879\x80CC\x666F\x586B\x5145\xFF08\x8F83\x5C11\x4F7F\x7528\xFF09",
    L"\x5217\x8868\x5F0F\x83DC\x5355\x63D0\x793A\x5B57\x4E32\x80CC\x666F\x586B\x5145",
    L"\x5217\x8868\x5F0F\x83DC\x5355\x6807\x51C6\xFF08\x975E\x9AD8\x4EAE\xFF09\x83DC\x5355\x9879\x6587\x672C\x8272",
    L"\x5217\x8868\x5F0F\x83DC\x5355\x9AD8\x4EAE\x83DC\x5355\x9879\x6587\x672C\x8272",
    L"\x5217\x8868\x5F0F\x83DC\x5355\x7981\x7528\x83DC\x5355\x9879\x6587\x672C\x8272\xFF08\x8F83\x5C11\x4F7F\x7528\xFF09",
    L"\x5217\x8868\x5F0F\x83DC\x5355\x6587\x672C\x5B57\x4F53",
    L"\x5355\x884C\x83DC\x5355\x9879\x9AD8\x4EAE\x7684\x80CC\x666F\x586B\x5145\xFF08\x82E5\x4F7F\x7528\x56FE\xFF0C\x56FE\x7684\x957F\x5BBD\x5FC5\x987B\x4E0E\x63A8\x8350\x957F\x5BBD\x4E00\x81F4\xFF09",
    L"\x53CC\x884C\x83DC\x5355\x9879\x9AD8\x4EAE\x7684\x80CC\x666F\x586B\x5145\xFF08\x82E5\x4F7F\x7528\x56FE\xFF0C\x56FE\x7684\x957F\x5BBD\x5FC5\x987B\x4E0E\x63A8\x8350\x957F\x5BBD\x4E00\x81F4\xFF09",
    L"\x591A\x884C\x83DC\x5355\x9879\x9AD8\x4EAE\x7684\x80CC\x666F\x586B\x5145\xFF08\x82E5\x4F7F\x7528\x56FE\xFF0C\x56FE\x7684\x957F\x5BBD\x5FC5\x987B\x4E0E\x63A8\x8350\x957F\x5BBD\x4E00\x81F4\xFF09",
    L"\x5BBD\x83DC\x5355\x9879\x9AD8\x4EAE\x7684\x80CC\x666F\x586B\x5145\xFF08\x82E5\x4F7F\x7528\x56FE\xFF0C\x56FE\x7684\x957F\x5BBD\x5FC5\x987B\x4E0E\x63A8\x8350\x957F\x5BBD\x4E00\x81F4\xFF09",
    L"\x6709\x6807\x7B7E\x9875\x7684\x5BBD\x83DC\x5355\x9879\x7684\x80CC\x666F\x586B\x5145\xFF08\x53EA\x5728\x0020\x0034\x0032\x0035\x0020\x53F7\x7C7B\x522B\x6709\x6548\xFF0C\x0020\x82E5\x4F7F\x7528\x56FE\xFF0C\x56FE\x7684\x957F\x5BBD\x5FC5\x987B\x4E0E\x63A8\x8350\x957F\x5BBD\x4E00\x81F4\xFF09",
    L"\x5217\x8868\x6846\x5206\x9694\x7EBF\x7684\x989C\x8272",
    L"\x591A\x9009\x5217\x8868\x91CC\x8868\x793A\x88AB\x9009\x4E2D\x7684\x56FE\x6807",
    L"\x591A\x9009\x5217\x8868\x91CC\x8868\x793A\x672A\x88AB\x9009\x4E2D\x7684\x56FE\x6807",
    L"\x5355\x9009\x5217\x8868\x91CC\x8868\x793A\x88AB\x9009\x4E2D\x7684\x56FE\x6807",
    L"\x5355\x9009\x5217\x8868\x91CC\x8868\x793A\x672A\x88AB\x9009\x4E2D\x7684\x56FE\x6807",
    L"\x77E9\x9635\x5F0F\x83DC\x5355\x80CC\x666F\x586B\x5145",
    L"\x77E9\x9635\x5F0F\x83DC\x5355\x6807\x51C6\x83DC\x5355\x9879\x80CC\x666F\x586B\x5145\xFF08\x8F83\x5C11\x4F7F\x7528\xFF09",
    L"\x77E9\x9635\x5F0F\x83DC\x5355\x9AD8\x4EAE\x83DC\x5355\x9879\x80CC\x666F\x586B\x5145",
    L"\x77E9\x9635\x5F0F\x83DC\x5355\x7981\x7528\x83DC\x5355\x9879\x80CC\x666F\x586B\x5145\xFF08\x8F83\x5C11\x4F7F\x7528\xFF09",
    L"\x77E9\x9635\x5F0F\x83DC\x5355\x6807\x51C6\x83DC\x5355\x9879\x6587\x672C\x8272",
    L"\x77E9\x9635\x5F0F\x83DC\x5355\x9AD8\x4EAE\x83DC\x5355\x9879\x6587\x672C\x8272",
    L"\x77E9\x9635\x5F0F\x83DC\x5355\x7981\x7528\x83DC\x5355\x9879\x6587\x672C\x8272\xFF08\x8F83\x5C11\x4F7F\x7528\xFF09",
    L"\x77E9\x9635\x5F0F\x83DC\x5355\x6587\x672C\x5B57\x4F53",
    L"\x6807\x7B7E\x6807\x9898\x7684\x80CC\x666F\x586B\x5145",
    L"\x6807\x7B7E\x6807\x9898\x6587\x672C\x8272",
    L"\x6807\x7B7E\x6807\x9898\x6587\x672C\x8FB9\x6846\x8272",
    L"\x6807\x7B7E\x6807\x9898\x5FEB\x6377\x65B9\x5F0F\x6587\x672C\x8272",
    L"\x6807\x7B7E\x6807\x9898\x6587\x672C\x5B57\x4F53",
    L"\x6807\x7B7E\x680F\x6B63\x5E38\x7684\x80CC\x666F\x586B\x5145",
    L"\x6807\x7B7E\x680F\x9AD8\x4EAE\x7684\x80CC\x666F\x586B\x5145",
    L"\x6807\x7B7E\x680F\x95EA\x70C1\x7684\x80CC\x666F\x586B\x5145",
    L"\x6807\x9898\x680F\x80CC\x666F\x586B\x5145",
    L"\x6807\x9898\x6587\x672C\x8272",
    L"\x6807\x9898\x6587\x672C\x8FB9\x6846\x8272",
    L"\x5FEB\x6377\x65B9\x5F0F\x6587\x672C\x8272",
    L"\x6807\x9898\x6587\x672C\x5B57\x4F53\xFF08\x4E0E\x0020\x0074\x0069\x0074\x006C\x0065\x005F\x0074\x0065\x0078\x0074\x005F\x0066\x006F\x006E\x0074\x0020\x76F8\x540C\xFF09",
    L"\x5FEB\x6377\x65B9\x5F0F\x6587\x672C\x5B57\x4F53",
    L"\x6807\x9898\x6587\x672C\x5B57\x4F53\xFF08\x4E0E\x0020\x0077\x0069\x006E\x0064\x006F\x0077\x005F\x0074\x0069\x0074\x006C\x0065\x005F\x0066\x006F\x006E\x0074\x0020\x76F8\x540C\xFF09",
    L"\x5927\x6807\x9898\x80CC\x666F\x586B\x5145",
    L"\x5927\x6807\x9898\x6587\x672C\x8272",
    L"\x5927\x6807\x9898\x6587\x672C\x8FB9\x6846\x8272",
    L"\x5927\x6807\x9898\x5FEB\x6377\x65B9\x5F0F\x6587\x672C\x8272",
    L"\x753B\x9762\x7684\x5168\x4E0D\x900F\x660E\x5EA6",
    L"\x753B\x9762\x7684\x9AD8\x4E0D\x900F\x660E\x5EA6\xFF08\x672A\x4F7F\x7528\xFF09",
    L"\x753B\x9762\x7684\x4E2D\x4E0D\x900F\x660E\x5EA6\xFF08\x672A\x4F7F\x7528\xFF09",
    L"\x753B\x9762\x7684\x4F4E\x4E0D\x900F\x660E\x5EA6\xFF08\x5728\x7F16\x8F91\x5668\x91CC\x4F7F\x7528\xFF09",
    L"\x4E3B\x83DC\x5355\x7684\x80CC\x666F\x586B\x5145",
    L"\x5B50\x83DC\x5355\x7684\x80CC\x666F\x586B\x5145",
    L"\x5F85\x673A\x754C\x9762\x7684\x80CC\x666F\x586B\x5145\xFF08\x5C06\x5899\x7EB8\x8BBE\x4E3A\x4E3B\x9898\x56FE\x7247\x4EE5\x663E\x793A\xFF09",
    L"",
    L"",
    L"",
    L"",
    L"",
    L"",
    L"",
    L"",
    L"",
    L"",
    L"",
    L"",
    L"",
    L"",
    L"",
    L"",
    L"",
    L"",
    L"",
    L"",
    L"",
    L"",
    L"",
    L"",
    L"",
    L"",
    L"",
    L"",
    L"",
    L"",
    L"",
    L"",
    L"",
    L"",
    L"",
    L"",
};


/* Example screen enumeration */
enum
{
	MMI_MTE_EXAMPLE_SCREEN_IDLE,
#if defined(__MMI_MAINMENU_MATRIX_SUPPORT__) && !defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
	MMI_MTE_EXAMPLE_SCREEN_MATRIX_MAIN_MENU,
#endif
#if defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
	MMI_MTE_EXAMPLE_SCREEN_BIDEGREE_MAIN_MENU,
#endif
#if defined(__MMI_MAINMENU_LIST_SUPPORT__) && !defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
	MMI_MTE_EXAMPLE_SCREEN_LIST_MAIN_MENU,
#endif
#if defined(__MMI_MAINMENU_PAGE_SUPPORT__) && !defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
	MMI_MTE_EXAMPLE_SCREEN_PAGE_MAIN_MENU,
#endif
#if defined(__MMI_MAINMENU_CIRCULAR_SUPPORT__) && !defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
	MMI_MTE_EXAMPLE_SCREEN_3D_CIRCULAR_MAIN_MENU,
#endif
#if defined(__MMI_MAINMENU_ROTATE_SUPPORT__) && !defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
	MMI_MTE_EXAMPLE_SCREEN_ROTATE_MAIN_MENU,
#endif
	MMI_MTE_EXAMPLE_SCREEN_LIST,
	MMI_MTE_EXAMPLE_SCREEN_TWOLINE_LIST,
	MMI_MTE_EXAMPLE_SCREEN_MULTIROW_LIST,
	MMI_MTE_EXAMPLE_SCREEN_RADIO_LIST,
	MMI_MTE_EXAMPLE_SCREEN_CHECK_LIST,
#if defined(UI_SMALL_LIST_SCREEN)
	MMI_MTE_EXAMPLE_SCREEN_SMALL_LIST,
#endif
	MMI_MTE_EXAMPLE_SCREEN_POPUP,
#if defined(__MMI_SCREEN_ROTATE__)
	MMI_MTE_EXAMPLE_SCREEN_ROTATED_POPUP,
#endif
#if defined(__MMI_SCREEN_ROTATE__)
	MMI_MTE_EXAMPLE_SCREEN_ROTATED_LIST,
#endif
	MMI_MTE_EXAMPLE_SCREEN_INLINE,
	MMI_MTE_EXAMPLE_SCREEN_EDITOR,
#if defined(__MMI_IMPS__) || defined(__MMI_UCM__) || defined(__MMI_VOIP__)
	MMI_MTE_EXAMPLE_SCREEN_TAB_LIST,
#endif
#if defined(__MMI_IMPS__) || defined(__MMI_UCM__) || defined(__MMI_VOIP__)
	MMI_MTE_EXAMPLE_SCREEN_TAB_LIST_WITHOUT_TAB,
#endif
#if defined(__MMI_CASCADE_MENU__)
	MMI_MTE_EXAMPLE_SCREEN_CASCADE_MENU,
#endif
	MMI_MTE_EXAMPLE_SCREEN_SYMBOL_PICKER,
	MMI_MTE_EXAMPLE_SCREEN_CALL,
	MMI_MTE_EXAMPLE_SCREEN_DIALER,
#if defined(__MMI_CALENDAR__)
	MMI_MTE_EXAMPLE_SCREEN_CALENDAR,
#endif
	MMI_MTE_EXAMPLE_SCREEN_PIN,
	MMI_MTE_EXAMPLE_SCREEN_NUM
} mmi_mte_example_screen_enum;

/* English example screen name */
static const wchar_t *g_mmi_mte_example_screen_name_EN[MMI_MTE_EXAMPLE_SCREEN_NUM] =
{
	L"Idle",
#if defined(__MMI_MAINMENU_MATRIX_SUPPORT__) && !defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
	L"Matrix Main Menu",
#endif
#if defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
	L"Bi-degree Main Menu",
#endif
#if defined(__MMI_MAINMENU_LIST_SUPPORT__) && !defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
	L"List Main Menu",
#endif
#if defined(__MMI_MAINMENU_PAGE_SUPPORT__) && !defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
	L"Page Main Menu",
#endif
#if defined(__MMI_MAINMENU_CIRCULAR_SUPPORT__) && !defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
	L"3D Circular Main Menu",
#endif
#if defined(__MMI_MAINMENU_ROTATE_SUPPORT__) && !defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
	L"Rotate Main Menu",
#endif
	L"List",
	L"Two-line List",
	L"Multirow List",
	L"Radio List",
	L"Check List",
#if defined(UI_SMALL_LIST_SCREEN)
	L"Small List",
#endif
	L"Popup",
#if defined(__MMI_SCREEN_ROTATE__)
	L"Rotated Popup",
#endif
#if defined(__MMI_SCREEN_ROTATE__)
	L"Rotated List",
#endif
	L"List-inline Editor",
	L"Editor",
#if defined(__MMI_IMPS__) || defined(__MMI_UCM__) || defined(__MMI_VOIP__)
	L"Tab List",
#endif
#if defined(__MMI_IMPS__) || defined(__MMI_UCM__) || defined(__MMI_VOIP__)
	L"Tab List Without tab",
#endif
#if defined(__MMI_CASCADE_MENU__)
	L"Cascading Menu",
#endif
	L"Symbol Picker",
	L"App - Call",
	L"App - Dialer",
#if defined(__MMI_CALENDAR__)
	L"App - Calendar",
#endif
	L"App - PIN",
};

/* GB example screen name */
static const wchar_t *g_mmi_mte_example_screen_name_GB[MMI_MTE_EXAMPLE_SCREEN_NUM] =
{
	L"\x5F85\x673A\x754C\x9762",
#if defined(__MMI_MAINMENU_MATRIX_SUPPORT__) && !defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
	L"\x77E9\x9635\x5F0F\x4E3B\x83DC\x5355",
#endif
#if defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
	L"\x53CC\x5217\x5F0F\x4E3B\x83DC\x5355",
#endif
#if defined(__MMI_MAINMENU_LIST_SUPPORT__) && !defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
	L"\x5217\x8868\x5F0F\x4E3B\x83DC\x5355",
#endif
#if defined(__MMI_MAINMENU_PAGE_SUPPORT__) && !defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
	L"\x9875\x5F0F\x4E3B\x83DC\x5355",
#endif
#if defined(__MMI_MAINMENU_CIRCULAR_SUPPORT__) && !defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
	L"\x0033\x0044\x0020\x5FAA\x73AF\x5F0F\x4E3B\x83DC\x5355",
#endif
#if defined(__MMI_MAINMENU_ROTATE_SUPPORT__) && !defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
	L"\x65CB\x8F6C\x5F0F\x4E3B\x83DC\x5355",
#endif
	L"\x5B50\x83DC\x5355",
	L"\x53CC\x884C\x5B50\x83DC\x5355",
	L"\x591A\x884C\x5B50\x83DC\x5355",
	L"\x5355\x9009\x5B50\x83DC\x5355",
	L"\x591A\x9009\x5B50\x83DC\x5355",
#if defined(UI_SMALL_LIST_SCREEN)
	L"\x975E\x5168\x5C4F\x5217\x8868\x5F0F\x83DC\x5355",
#endif
	L"\x5F39\x51FA\x5F0F\x63D0\x793A\x6846",
#if defined(__MMI_SCREEN_ROTATE__)
	L"\x65CB\x8F6C\x540E\x5F39\x51FA\x5F0F\x63D0\x793A\x6846",
#endif
#if defined(__MMI_SCREEN_ROTATE__)
	L"\x65CB\x8F6C\x540E\x5B50\x83DC\x5355",
#endif
	L"\x5355\x884C\x7F16\x8F91\x83DC\x5355",
	L"\x7F16\x8F91\x5668",
#if defined(__MMI_IMPS__) || defined(__MMI_UCM__) || defined(__MMI_VOIP__)
	L"\x6807\x7B7E\x5B50\x83DC\x5355",
#endif
#if defined(__MMI_IMPS__) || defined(__MMI_UCM__) || defined(__MMI_VOIP__)
	L"\x6CA1\x6709\x6807\x7B7E\x7684\x6807\x7B7E\x5B50\x83DC\x5355",
#endif
#if defined(__MMI_CASCADE_MENU__)
	L"\x5C42\x53E0\x5F0F\x83DC\x5355",
#endif
	L"\x7B26\x53F7\x9009\x62E9\x753B\x9762",
	L"\x5E94\x7528\x7A0B\x5F0F\x0020\x002D\x0020\x62E8\x53F7\x4E2D",
	L"\x5E94\x7528\x7A0B\x5F0F\x0020\x002D\x0020\x62E8\x53F7",
#if defined(__MMI_CALENDAR__)
	L"\x5E94\x7528\x7A0B\x5F0F\x0020\x002D\x0020\x65E5\x5386",
#endif
	L"\x5E94\x7528\x7A0B\x5F0F\x0020\x002D\x0020\x0050\x0049\x004E",
};

/* English component group name */
static const wchar_t *g_mmi_mte_theme_component_group_name_EN[MMI_MTE_THEME_COMPONENT_GROUP_NUM] =
{
	L"Calendar", // 0
	L"Clock", // 1
	L"Common", // 2
	L"Inline Editor", // 3
	L"Inputbox", // 4
	L"Inputbox - IME", // 5
	L"Inputbox - Keyboard", // 6
	L"Inputbox - Multitap", // 7
	L"Main Menu - Bidegree", // 8
	L"Main Menu - Circular", // 9
	L"Main Menu - List", // 10
	L"Main Menu - Matrix", // 11
	L"Screen - Calling", // 12
	L"Screen - Dialer", // 13
	L"Screen - Idle", // 14
	L"Screen - PIN input", // 15
	L"Screen - Popup", // 16
	L"Screen - Rotated", // 17
	L"Screen - Small Menu", // 18
	L"Screen - Symbol Picker", // 19
	L"Scrollbar", // 20
	L"Softkey", // 21
	L"Status Icons", // 22
	L"Submenu - Cascade", // 23
	L"Submenu - List", // 24
	L"Submenu - Matrix", // 25
	L"Tab", // 26
	L"Title", // 27
	L"Wallpaper", // 28
};

typedef enum
{
	MMI_MTE_GROUP_CALENDAR,
	MMI_MTE_GROUP_CLOCK,
	MMI_MTE_GROUP_COMMON,
	MMI_MTE_GROUP_INLINE_EDITOR,
	MMI_MTE_GROUP_INPUTBOX,
	MMI_MTE_GROUP_INPUTBOX_IME,
	MMI_MTE_GROUP_INPUTBOX_KEYBOARD,
	MMI_MTE_GROUP_INPUTBOX_MULTITAP,
	MMI_MTE_GROUP_MAIN_MENU_BIDEGREE,
	MMI_MTE_GROUP_MAIN_MENU_CIRCULAR,
	MMI_MTE_GROUP_MAIN_MENU_LIST,
	MMI_MTE_GROUP_MAIN_MENU_MATRIX,
	MMI_MTE_GROUP_SCREEN_CALLING,
	MMI_MTE_GROUP_SCREEN_DIALER,
	MMI_MTE_GROUP_SCREEN_IDLE,
	MMI_MTE_GROUP_SCREEN_PIN_INPUT,
	MMI_MTE_GROUP_SCREEN_POPUP,
	MMI_MTE_GROUP_SCREEN_ROTATED,
	MMI_MTE_GROUP_SCREEN_SMALL_MENU,
	MMI_MTE_GROUP_SCREEN_SYMBOL_PICKER,
	MMI_MTE_GROUP_SCROLLBAR,
	MMI_MTE_GROUP_SOFTKEY,
	MMI_MTE_GROUP_STATUS_ICONS,
	MMI_MTE_GROUP_SUBMENU_CASCADE,
	MMI_MTE_GROUP_SUBMENU_LIST,
	MMI_MTE_GROUP_SUBMENU_MATRIX,
	MMI_MTE_GROUP_TAB,
	MMI_MTE_GROUP_TITLE,
	MMI_MTE_GROUP_WALLPAPER
} mmi_mte_group_enum;

/* GB component group name */
static const wchar_t *g_mmi_mte_theme_component_group_name_GB[MMI_MTE_THEME_COMPONENT_GROUP_NUM] =
{
	L"\x65E5\x5386", // 0
	L"\x65F6\x949F", // 1
	L"\x4E00\x822C", // 2
	L"\x5355\x884C\x7F16\x8F91\x5668", // 3
	L"\x8F93\x5165\x6846", // 4
	L"\x8F93\x5165\x6CD5", // 5
	L"\x865A\x62DF\x952E\x76D8", // 6
	L"\x5168\x952E\x6587\x672C\x8F93\x5165\x6CD5", // 7
	L"\x53CC\x5217\x5F0F\x4E3B\x83DC\x5355", // 8
	L"\x5FAA\x73AF\x5F0F\x4E3B\x83DC\x5355", // 9
	L"\x5217\x8868\x5F0F\x4E3B\x83DC\x5355", // 10
	L"\x77E9\x9635\x5F0F\x4E3B\x83DC\x5355", // 11
	L"\x62E8\x53F7\x4E2D\x753B\x9762", // 12
	L"\x62E8\x53F7\x753B\x9762", // 13
	L"\x5F85\x673A\x753B\x9762", // 14
	L"\x0050\x0049\x004E\x0020\x8F93\x5165\x753B\x9762", // 15
	L"\x5F39\x51FA\x5F0F\x63D0\x793A\x6846\x753B\x9762", // 16
	L"\x65CB\x8F6C\x540E\x753B\x9762", // 17
	L"\x975E\x5168\x5C4F\x753B\x9762", // 18
	L"\x7B26\x53F7\x9009\x62E9\x753B\x9762", // 19
	L"\x6EDA\x52A8\x6761", // 20
	L"\x8F6F\x952E", // 21
	L"\x72B6\x6001\x680F", // 22
	L"\x5C42\x53E0\x5F0F\x83DC\x5355", // 23
	L"\x5217\x8868\x5F0F\x5B50\x83DC\x5355", // 24
	L"\x77E9\x9635\x5F0F\x5B50\x83DC\x5355", // 25
	L"\x6807\x7B7E", // 26
	L"\x6807\x9898\x680F", // 27
	L"\x5899\x7EB8", // 28
};

/* MTE theme components to DM control sets */
static const mmi_mte_control_set_group_struct g_mmi_mte_control_set_group[] =
{
	{0, {0}}, // DM_BASE_LAYER_START
	{0, {0}}, // DM_BASE_LAYER_END
	{0, {0}}, // DM_NEW_LAYER_START
	{0, {0}}, // DM_NEW_LAYER_END
	{0, {0}}, // DM_SCR_BG
	{0, {0}}, // DM_BASE_CONTROL_SET1
	{0, {0}}, // DM_BASE_CONTROL_SET2
	{0, {0}}, // DM_BASE_CONTROL_SET_SUBMENU
	{0, {0}}, // DM_BASE_CONTROL_SET_COMMON
	{0, {0}}, // DM_CIRCULAR_MENU1
	{19, {157, 164, 165, 166, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205}}, // DM_LIST1
	{0, {0}}, // DM_ROTATE_MENU1
	{25, {40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 164, 165, 166, 191, 193}}, // DM_INLINE_FIXED_LIST1
	{8, {210, 211, 212, 213, 214, 215, 216, 217}}, // DM_MATRIX_MENU1
	{19, {157, 164, 165, 166, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205}}, // DM_DYNAMIC_LIST1
	{19, {157, 164, 165, 166, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205}}, // DM_ASYNCDYNAMIC_LIST1
	{32, {60, 61, 62, 63, 64, 68, 69, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95}}, // DM_SINGLELINE_INPUTBOX1
	{39, {60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 164, 165, 166, 240}}, // DM_MULTILINE_INPUTBOX1
	{22, {60, 61, 62, 63, 64, 68, 69, 70, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 164, 165, 166}}, // DM_EMS_INPUTBOX1
	{8, {126, 127, 128, 129, 130, 131, 132, 133}}, // DM_DIALER_INPUT_BOX1
	{0, {0}}, // DM_TAB_CONTROL
	{8, {218, 219, 220, 221, 222, 223, 224, 225}}, // DM_HORIZONTAL_TAB_BAR
	{12, {21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32}}, // DM_DATE_TIME_DISPLAY
	{12, {159, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236}}, // DM_TITLE1
	{1, {180}}, // DM_STATUS_BAR1
	{0, {0}}, // DM_LSK
	{0, {0}}, // DM_RSK
	{0, {0}}, // DM_CSK
	{12, {167, 168, 169, 170, 171, 172, 174, 175, 176, 177, 178, 179}}, // DM_BUTTON_BAR1
	{1, {173}}, // DM_BUTTON
	{21, {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20}}, // DM_CALENDAR
	{0, {0}}, // DM_ALIGNED_AREA_START
	{0, {0}}, // DM_ALIGNED_AREA_END
	{0, {0}}, // DM_STRING
	{0, {0}}, // DM_IMAGE
	{0, {0}}, // DM_BACK_FILL_AREA
	{0, {0}}, // DM_RECTANGLE
	{0, {0}}, // DM_LINE
	{0, {0}}, // DM_SLIDE_CONTROL
	{0, {0}}, // DM_CATEGORY_CONTROLLED_AREA
	{0, {0}}, // DM_CATEGORY_CONTROLLED_AREA2
	{5, {153, 154, 155, 156, 158}}, // DM_POPUP_BACKGROUND
	{0, {0}}, // DM_NWAY_STOPWATCH
	{0, {0}}, // DM_TYPICAL_STOPWATCH
	{0, {0}}, // DM_WALL_PAPER
	{0, {0}}, // DM_SCROLL_TEXT
	{0, {0}}, // DM_PERCENTAGE_BAR
	{0, {0}}, // DM_PANEL
};

#define	MMI_MTE_CURRENT_SCREEN_FILTER_NUM	11

/*
 * screen filter
 */
/* filter dependencies */
#if !(((defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__)) && defined(__GDI_MEMORY_PROFILE_2__)) && !defined(__MMI_UI_DALMATIAN_IDLESCREEN__)) && !defined(__MMI_TOUCH_DIAL_SCREEN__)
#define MMI_CATEGORY16_ID_DATETIME_BAR_DATE_TEXT_COLOR 122
#define MMI_CATEGORY16_ID_DATETIME_BAR_TIME_TEXT_COLOR 123
#else
#define MMI_CATEGORY16_ID_DATETIME_BAR_DATE_TEXT_COLOR MMI_MTE_INVALID_FILTER_COMPONENT
#define MMI_CATEGORY16_ID_DATETIME_BAR_TIME_TEXT_COLOR MMI_MTE_INVALID_FILTER_COMPONENT
#endif
#if defined(__MMI_DOWNLOADABLE_THEMES_SUPPORT__) && !defined(__MMI_WALLPAPER_ON_BOTTOM__)
#define MMI_CATEGORY18_ID_CM_SCREEN_TEXT_COLOR 119
#else
#define MMI_CATEGORY18_ID_CM_SCREEN_TEXT_COLOR MMI_MTE_INVALID_FILTER_COMPONENT
#endif
#if !defined(__MMI_DOWNLOADABLE_THEMES_SUPPORT__)
#define MMI_CATEGORY18_ID_INPUTBOX_NORMAL_TEXT_COLOR 61
#else
#define MMI_CATEGORY18_ID_INPUTBOX_NORMAL_TEXT_COLOR MMI_MTE_INVALID_FILTER_COMPONENT
#endif

static const mmi_mte_current_screen_filter_struct g_mmi_mte_current_screen_filter[MMI_MTE_CURRENT_SCREEN_FILTER_NUM] =
{
	{0, MMI_CATEGORY16_ID, 7, {126, 130, 131, 132, 133, MMI_CATEGORY16_ID_DATETIME_BAR_DATE_TEXT_COLOR, MMI_CATEGORY16_ID_DATETIME_BAR_TIME_TEXT_COLOR, }, {0, {0}}},
	{0, MMI_CATEGORY14_LIST_ID, 7, {241, 109, 103, 105, 164, 165, 106, }, {1, {DM_LIST1, }}},
	{0, MMI_CATEGORY18_ID, 4, {MMI_CATEGORY18_ID_CM_SCREEN_TEXT_COLOR, MMI_CATEGORY18_ID_INPUTBOX_NORMAL_TEXT_COLOR, 196, 118, }, {0, {0}}},
	{0, MMI_CATEGORY9_ID+1, 7, {197, 196, 193, 164, 165, 160, 161, }, {1, {DM_LIST1, }}},
	{0, MMI_CATEGORY414_ID, 6, {241, 111, 97, 98, 113, 114, }, {1, {DM_LIST1, }}},
	{0, MMI_CATEGORY111_ID, 6, {147, 148, 149, 150, 151, 152, }, {2, {DM_MULTILINE_INPUTBOX1, DM_SINGLELINE_INPUTBOX1, }}},
	{0, MMI_CATEGORY14_MATRIX_ID, 3, {241, 109, 117, }, {1, {DM_MATRIX_MENU1, }}},
	{0, MMI_CATEGORY_CASCADING_MENU_ID, 10, {185, 186, 182, 183, 187, 184, 188, 189, 164, 165, }, {1, {DM_LIST1, }}},
	{IDLE_SCREEN_ID, 0, 15, {243, 145, 146, 135, 137, 136, 138, 145, 146, 139, 140, 141, 142, 143, 144, }, {0, {0}}},
	{0, MMI_CATEGORY86_ID, 3, {33, 34, 35, }, {0, {0}}},
	{0, MMI_CATEGORY22_ID, 1, {163, }, {0, {0}}},
};

