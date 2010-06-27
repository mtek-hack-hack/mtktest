#ifndef _PIXCOM_EBOOKPROT_H
#define _PIXCOM_EBOOKPROT_H

#include "EbookGprot.h"
#include "L4Dr.h"
#include "FileManagerGProt.h"

#define     EBR_MAX_EBOOK_PERCENTAGE_VALUE         3
#define     EBR_DISPLAY_INFO_SIZE               200
#define     EBR_NEW_LINE_SIZE                5
#define     EBR_MAX_SETTINGS_VAL_FONT        3
#define     EBR_MAX_SETTINGS_VAL_SCROLL         2
#define     EBR_MAX_SETTINGS_VAL_SCROLL_SPEED   5
#define     EBR_MAX_SETTINGS_VAL_ENCD_TYPE      11
#define     EBR_TOTAL_NUMBER_OF_ITEM_BKSHLF     16
#define     EBR_TOTAL_NUMBER_OF_ITEM_BOOK    14

typedef struct
{
    S8 ebr_search_string_input[(EBR_MAX_STR_SEARCH_LENGTH + 1) *ENCODING_LENGTH + ENCODING_LENGTH];
	S8 ebr_file_mgr_file_path[FMGR_MAX_PATH_LEN *ENCODING_LENGTH + ENCODING_LENGTH];
    U8 book_mark_name[EBR_FRM_MAX_BOOKMARK_NAME_SIZE *ENCODING_LENGTH + ENCODING_LENGTH];
    U8 percentage_val[(EBR_MAX_EBOOK_PERCENTAGE_VALUE + 1) *ENCODING_LENGTH];
    S16 ebr_set_local_setting_flag;
    pBOOL ebr_search_found_next_flag;
    S32 enable_screen_exit;
    S32 current_highlighted_item;
    S32 current_selected_bookmark;
    U8 *ebook_jump_text_end_beg[EBR_MAX_SETTINGS_VAL_FONT];
    U8 *ebook_settings_font_style[EBR_MAX_SETTINGS_VAL_FONT];
    U8 *ebook_settings_font_size[EBR_MAX_SETTINGS_VAL_FONT];
    U8 *ebook_settings_scroll_by[EBR_MAX_SETTINGS_VAL_SCROLL];
    U8 *ebook_settings_auto_scroll[EBR_MAX_SETTINGS_VAL_SCROLL];
    U8 *ebook_settinsg_auto_scroll_speed[EBR_MAX_SETTINGS_VAL_SCROLL_SPEED];
    U8 *ebook_settings_full_screen[EBR_MAX_SETTINGS_VAL_SCROLL];
    U8 *ebook_settings_encoding_format[EBR_MAX_SETTINGS_VAL_ENCD_TYPE];
    U8 buffer_data[EBR_RECORD_SIZE_MAX + GUI_SHARED_BYTES];
    S8 ebook_settings_memory_type[(FMGR_MAX_DRIVE_NAME_LEN + 1) * ENCODING_LENGTH];
    U8 *info_buffer;
} g_ebook_app_cntx;

extern void go_back_to_bookshelf_screen(void);
extern void ebr_highlight_ebk_restore_default(void);
extern void ebr_highlight_delete_all(void);
extern void ebr_highlight_book_shelf_restore_default(void);
extern void InitEbookApp(void);

extern void ebr_show_limit_book_shelf_option(void);
extern void ebr_mmi_ebook_exit(void);
extern void ebr_highlight_open_ebook(void);
extern void ebr_highlight_refresh_book_shelf(void);
extern void ebr_highlight_refresh_book_shelf(void);
extern void ebr_highlight_open_ebook(void);
extern void ebr_entry_open_book(void);
extern void ebr_highlight_book_shelf_settings(void);
extern void ebr_highlight_help(void);
extern void ebr_highlight_delete_ebook(void);
extern void ebr_entry_book_info(void);
extern U8 ebr_book_info_del_callback(void);
extern void ebr_entry_delete_ebook(void);
extern void ebr_entry_help(void);
extern void ebr_entry_settings(void);
extern void ebr_higlight_book_info(void);
extern void ebr_entry_book_settings(void);
extern void ebr_highlight_case_in_sensitive_serach(void);
extern void ebr_highlight_case_sensitive_serach(void);
extern void ebr_entry_search(void);
extern void ebr_highlight_jump_to(void);
extern void ebr_delete_bookmark(void);
extern void ebr_entry_delete_book_popup(void);
extern void ebr_highlight_search(void);
extern void ebr_highlight_goto_book_mark(void);
extern void ebr_highlight_remove_book_mark(void);
extern void ebr_highlight_add_book_mark(void);
extern void ebr_highlight_book_settings(void);
extern void ebr_highlight_open_book_info(void);
extern void ebr_close_book(void);
extern void ebr_entry_jump_to(void);
extern void ebr_entry_jump_to_done_hndlr(void);
extern void ebr_entry_settings_done_hndlr(void);
extern void ebr_fill_settings_inline_edit_struct(void *pInlineStruct);
extern void ebr_entry_add_book_mark(void);
extern void ebr_entry_remove_book_mark(void);
extern void ebr_remove_selected_bookmark(void);
extern void ebr_entry_goto_book_mark(void);
extern void ebr_entry_close_book(void);
extern void ebr_highlight_selected_bookmark(S32 index);
extern void ebr_goto_selected_bookmark(void);
extern void ebr_book_file_callback(void *fullname, int is_short);
extern void ebr_book_fmgr_empty_list_callback(void);
extern void ebr_book_settings_done_hdlr(void);
extern void ebr_exit_jump_to(void);
extern void go_back_to_settings_screen(void);
extern S8 *ebr_get_book_mark_name(void);

extern void ebr_app_search_string(void);
extern void ebr_highlight_jump_to_item(S32 index);
extern void ebr_entry_percentage_screen(void);
extern void ebr_go_back_to_inline_edit_screen(void);
extern void ebr_app_delete_all_from_book_shelf(void);
extern void ebr_confirm_deletion_of_all_files(void);
extern void ebr_app_restore_default_book_settings(void);
extern void ebr_app_restore_default_book_shelf_settings(void);
extern void ebr_exit_settings(void);
extern void ebr_pre_entry_jump_to(void);
extern void ebr_book_settings_confirm_pop_up(void);
extern void ebr_app_display_pop_up_book_mark_sucessfully_added(void);
extern void ebr_app_search_result_unsucessfull(void);
extern void ebr_app_display_pop_up_changed_screen_mode(S32 screen_mode);
extern void ebr_app_display_pop_up_changed_auto_scroll(S32 auto_scroll_mode);
extern void ebr_app_display_pop_up_format_not_supported(void);
extern void ebr_app_display_pop_up_default_settings_restored(void);
extern void ebr_app_display_pop_up_default_settings_not_restored(void);
extern void ebr_app_display_pop_up_default_settings_for_book_restored(void);
extern void ebr_app_delete_upto_open_book_screen_id(void);
extern void ebr_app_go_back_history(void);

extern void ebr_app_search_string_next(void);
extern void ebr_app_search_result_successful(pBOOL search_type);
extern void ebr_highlight_search_next(void);
extern void ebr_app_search_string_next_from_menu(void);
extern void ebr_app_save_settings_screen_mode(void);
extern void ebr_app_save_settings_scroll(void);
extern void ebr_ebook_search_string(void);
extern void ebr_exit_ebook_search_string(void);
extern void ebr_frm_set_full_screen_on(void);
extern void ebr_frm_set_full_screen_off(void);

extern void ebr_app_add_to_book_shelf(void);
extern void go_back_to_book_shelf_scren(void);
extern void go_back_to_open_book_screen(void);
extern void ebr_entry_book_mark_edit_list(void);
extern void ebr_get_add_book_mark(void);
extern void ebr_get_add_book_mark_options(S32 nIndex);
extern void GoBackHistoryFromInputMethod(void);
extern void ebr_entry_search_edit_list(void);
extern void ebr_get_add_search_string(void);
extern void ebr_get_add_search_string_options(S32 nIndex);
extern void ebr_frm_search_string_empty(void);
extern void ebr_app_display_pop_up_empty_book(void);

extern void GoBacktobokshelfHistory(void);
#ifdef __MMI_TOUCH_SCREEN__
extern void ebr_set_key_TS(UI_character_type c);
#endif 
#ifdef __MMI_LANG_HINDI__
extern void ebr_app_show_string_incomplete_pop_up(void);
#endif
extern void ebr_app_search_result_invalid(void);
extern void mmi_ebr_highlight_setting(S32 index);
extern void mmi_ebr_entry_select_drive(void);
extern void mmi_ebr_save_drive_selection(S8 drive_letter);

#ifdef __MMI_BPP_SUPPORT__
extern void ebr_highlight_book_bpp_print(void);
extern void ebr_app_bpp_print(void);

#endif /* __MMI_BPP_SUPPORT__ */ 
#endif /* _PIXCOM_EBOOKPROT_H */ /* End _PIXCOM_EBOOKPROT_H */

