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
 * ctk.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 * This file intends for declaration of CTK - Category Toolkits
 * CTK can help WAP to integrate MMI category in an easier way.
 *
 * Author:
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _CTK_H
#define _CTK_H

/*************************************************************************
 * Include Statements
 *************************************************************************/

#include "kal_release.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"
#include "stack_config.h"

/* Some basic MMI  types */
#include "GlobalDefs.h"
#include "MMIDataType.h"
#include "FrameworkStruct.h"
#include "wgui.h"
#include "DebugInitDef.h"

/*************************************************************************
 * Configurations
 *************************************************************************/
#define CTK_APP_NAME_LEN   (12)

/* Maximum number of ctk_screen */
#define CTK_SCREEN_MAX                 (30)


typedef enum
{
    SCR_ID_CTK_SCREEN_1 = CTK_BASE,
    SCR_ID_CTK_SCREEN_2,
    SCR_ID_CTK_SCREEN_3,
    SCR_ID_CTK_SCREEN_4,
    SCR_ID_CTK_SCREEN_5,
    SCR_ID_CTK_SCREEN_6,
    SCR_ID_CTK_SCREEN_7,
    SCR_ID_CTK_SCREEN_8,
    SCR_ID_CTK_SCREEN_9,
    SCR_ID_CTK_SCREEN_10,
    SCR_ID_CTK_SCREEN_11,
    SCR_ID_CTK_SCREEN_12,
    SCR_ID_CTK_SCREEN_13,
    SCR_ID_CTK_SCREEN_14,
    SCR_ID_CTK_SCREEN_15,
    SCR_ID_CTK_SCREEN_16,
    SCR_ID_CTK_SCREEN_17,
    SCR_ID_CTK_SCREEN_18,
    SCR_ID_CTK_SCREEN_19,
    SCR_ID_CTK_SCREEN_20,
    SCR_ID_CTK_SCREEN_21,
    SCR_ID_CTK_SCREEN_22,
    SCR_ID_CTK_SCREEN_23,
    SCR_ID_CTK_SCREEN_24,
    SCR_ID_CTK_SCREEN_25,
    SCR_ID_CTK_SCREEN_26,
    SCR_ID_CTK_SCREEN_27,
    SCR_ID_CTK_SCREEN_28,
    SCR_ID_CTK_SCREEN_29,
    SCR_ID_CTK_SCREEN_30,
    SCR_ID_CTK_UTF8_EDITOR_SCREEN
        
}ctk_screen_id_enum;

// depends on MMI setting
// FIXME move the MMI settings into header files
#define CTK_INLINE_MAX_ITEMS                    (24 /* MAX_INLINE_ITEMS */)

/*************************************************************************
 * Miscellaneous
 *************************************************************************/
#define CTK_LOG_GROUP   (MMI_FW_TRC_G2_GUI)

#ifdef __MTK_TARGET__

  #ifndef __PRODUCTION_RELEASE__
    #define CTK_LOG(x_)                 Trace2(MMI_FW_TRC_G2_GUI, "[CTK] " x_ "\n")
    #define CTK_LOG_VAR(x_)             Trace2 x_
    #define CTK_DBG_ASSERT(x)
  #else /* __PRODUCTION_RELEASE__ */ 
    /* KAL may define kal_trace to be NULL on the target, but PC compiler doesn't know (...) in the macro */
    #define CTK_LOG(x_)               
    #define CTK_LOG_VAR(x_)      
    #define CTK_DBG_ASSERT(x)
  #endif /* __PRODUCTION_RELEASE__ */ 

#else /* __MTK_TARGET__ */ 

    /* KAL always has kal_trace() on PC simulator */
    #define CTK_LOG(x_)                 Trace2(MMI_FW_TRC_G2_GUI, "[CTK] " x_ "\n")
    #define CTK_LOG_VAR(x_)             Trace2 x_
    #define CTK_DBG_ASSERT(x)
#endif /* __MTK_TARGET__ */ 


#define CTK_UNUSED(x)               (void)(x)

#define CTK_INIT_STRUCT(x)          memset(&x, 0, sizeof(x))

/*************************************************************************
 * General Types
 *************************************************************************/

typedef kal_uint32 ctk_object_handle;
typedef ctk_object_handle ctk_app_handle;
typedef ctk_object_handle ctk_screen_handle;
typedef ctk_object_handle ctk_layout_handle;

/*************************************************************************
 * Constants/Enum
 *************************************************************************/

#define  CTK_NULL_HANDLE      ((ctk_object_handle) 0)

typedef enum
{
    CTK_OBJECT_TYPE_APP = 0xB0,
    CTK_OBJECT_TYPE_SCREEN = 0xB7,
    CTK_OBJECT_TYPE_LAYOUT = 0xBF,
    CTK_OBJECT_TYPE_INVALID = 0xF0
} ctk_object_type_enum;

typedef enum
{
    CTK_LAYOUT_TYPE_PCATEGORY = 0x17,
    CTK_LAYOUT_TYPE_INLINE,
    CTK_LAYOUT_TYPE_LIST
} ctk_layout_type_enum;

typedef enum
{
    CTK_APP_STATE_CREATED,
    CTK_APP_STATE_CLOSING,
    CTK_APP_STATE_CLOSED
} ctk_app_state_enum;

typedef enum
{
    CTK_SCREEN_STATE_CREATED,
    /* Ready to display */
    CTK_SCREEN_STATE_LAYOUT_ATTACHED,
    /* The only state that interacts with MMI. */
    CTK_SCREEN_STATE_ACTIVE,
    CTK_SCREEN_STATE_CLOSING,
    CTK_SCREEN_STATE_CLOSED
} ctk_screen_state_enum;

typedef enum
{
    CTK_SCREEN_FLAG_NONE,
    CTK_SCREEN_FLAG_REDRAW,				/* ctk screen is in redraw flow */
    CTK_SCREEN_FLAG_EXIT_IN_HISTORY,	/* ctk screen exits and adds in the history */
    CTK_SCREEN_FLAG_EXIT_NOT_IN_HISTORY,

    CTK_SCREEN_FLAG_END
} ctk_screen_flag_enum;

typedef enum
{
    CTK_SCREEN_EXIT_NOPAUSE,
    CTK_SCREEN_EXIT_PAUSE,                  /* add in the history */
    CTK_SCREEN_EXIT_PAUSE_NOT_IN_HISTORY    /* does not add history, but store GUI input in ctk_screen itself */
} ctk_screen_exit_enum;

typedef enum
{
    CTK_INLINE_ITEM_TYPE_CAPTION,
    CTK_INLINE_ITEM_TYPE_SINGLE_LINE,
    CTK_INLINE_ITEM_TYPE_SELECT,
    CTK_INLINE_ITEM_TYPE_DISPLAY_ONLY,
    CTK_INLINE_ITEM_TYPE_EDITOR,
    CTK_INLINE_ITEM_TYPE_IP4,
    CTK_INLINE_ITEM_TYPE_UTF8_EDITOR
} ctk_inline_item_type_enum;

typedef enum
{
    CTK_INLINE_ACTIVATION_NONE,
    CTK_INLINE_ACTIVATION_AUTO,
    CTK_INLINE_ACTIVATION_LSK
} ctk_inline_activation_enum;

typedef kal_uint8 ctk_inline_item_flag_t;

#define CTK_INLINE_ITEM_FLAG_UNDERLINE (0x01)

typedef enum
{
    CTK_INPUT_TYPE_DEFAULT = 0,
    CTK_INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
    CTK_INPUT_TYPE_ALPHANUMERIC_UPPERCASE,
    CTK_INPUT_TYPE_ALPHANUMERIC_LOWERCASE,
    CTK_INPUT_TYPE_ALPHA,           /* only english letters */
    CTK_INPUT_TYPE_NUMBER,          /* [0-9] */
    CTK_INPUT_TYPE_DECIMAL,         /* support decimal point (.) */
    CTK_INPUT_TYPE_PASSWORD_ALPHANUMERIC,
	CTK_INPUT_TYPE_PASSWORD_ALPHA,
    CTK_INPUT_TYPE_PASSWORD_NUMBER,
    CTK_INPUT_TYPE_PHONE_NUMBER,    /*  handle '+' char */
    CTK_INPUT_TYPE_ALPHANUMERIC_SENTENCECASE_USE_ENCODING_BASED_LENGTH,
    CTK_INPUT_TYPE_OVERRIDE = 0x80  /* Override default input method */
} ctk_input_type_enum;

typedef kal_uint32 ctk_keytype_t;

#define CTK_KEYTYPE_DOWN      (0x0001)
#define CTK_KEYTYPE_UP        (0x0002)
#define CTK_KEYTYPE_LONG_PRESS   (0x0004)
#define CTK_KEYTYPE_REPEAT    (0x0008)
#define CTK_KEYTYPE_EXCL      (0x0080)

typedef kal_uint32 ctk_key_identifier_t;

/*************************************************************************
 * Global variables
 *************************************************************************/
/* CTK_MMI_DUMMY_APPID */

/*************************************************************************
 * Callback handlers
 *************************************************************************/

typedef void *(*ctk_mem_alloc_hdlr) (int);

typedef void (*ctk_mem_free_hdlr) (void *);

typedef void (*ctk_app_callback_hdlr) (ctk_app_handle);

typedef void (*ctk_screen_callback_hdlr) (ctk_screen_handle);

typedef void (*ctk_highlight_callback_hdlr) (ctk_screen_handle, int);

typedef void (*ctk_key_identifer_callback_hdlr) (ctk_screen_handle, ctk_key_identifier_t);

typedef void (*ctk_void_callback_hdlr) (void);

typedef void (*ctk_layout_callback_hdlr) (ctk_layout_handle);

typedef void (*ctk_layout_set_softkey_hdlr) (ctk_layout_handle, ctk_screen_callback_hdlr);

/*************************************************************************
 * Types related to MMI
 *************************************************************************/

typedef U16 ctk_keycode_id;
typedef U16 ctk_string_id;
typedef U16 ctk_image_id;
typedef U16 ctk_MMI_screen_id;
typedef U16 ctk_key_code;
typedef U8 ctk_tone_id;

/*************************************************************************
 * System limitation that depends on other settings
 *************************************************************************/

#define CTK_MAX_BACKUP_INPUT  MAX_INPUT_BUFFER

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

/*************************************************************************
 * Object
 *************************************************************************/

extern kal_bool ctk_object_is_type(ctk_object_handle obj, ctk_object_type_enum type);
extern kal_bool ctk_object_is_valid_type(ctk_object_handle obj);

/*************************************************************************
 * Application
 *************************************************************************/

typedef void (*ctk_func_void) (void);
typedef void (*ctk_func_handle) (ctk_object_handle);

typedef void (*ctk_rpc_void) (ctk_func_void func, kal_bool is_blocking);
typedef void (*ctk_rpc_handle) (ctk_func_handle func, ctk_object_handle handle, kal_bool is_blocking);

typedef struct
{
    kal_char app_name[CTK_APP_NAME_LEN + 1];    /* Mandatory */
    module_type app_taskid;                     /* Mandatory */
    ctk_mem_alloc_hdlr app_mem_alloc_fp;
    ctk_mem_free_hdlr app_mem_free_fp;
    kal_bool app_mem_auto_freeall;              /* UNFINISHED */
    ctk_rpc_void app_rpc_MMI_void_fp;
    ctk_rpc_void app_rpc_UA_void_fp;
    ctk_rpc_handle app_rpc_MMI_handle_fp;
    ctk_rpc_handle app_rpc_UA_handle_fp;
} ctk_app_create_struct;

extern ctk_app_handle ctk_app_create(ctk_app_create_struct *create_struct);
extern void ctk_app_close(ctk_app_handle appid);
extern ctk_app_state_enum ctk_app_get_state(ctk_app_handle appid);

/*************************************************************************
 * Remote execution
 *************************************************************************/
/*
 * extern void ctk_remote_execute_in_UA_p(ctk_object_handle container, void (*fp)(void *), void *arg);
 * extern void ctk_remote_execute_in_MMI_p(ctk_object_handle container, void (*fp)(void *), void *arg);
 */

extern void ctk_remote_execute_in_UA_h(ctk_object_handle container, void (*fp) (ctk_object_handle),
                                       ctk_object_handle arg, kal_bool is_blocking);
extern void ctk_remote_execute_in_MMI_h(ctk_object_handle container, void (*fp) (ctk_object_handle),
                                        ctk_object_handle arg, kal_bool is_blocking);

/*
 * extern void ctk_remote_execute_in_UA_v(ctk_object_handle container, void (*fp)(void));
 * extern void ctk_remote_execute_in_MMI_v(ctk_object_handle container, void (*fp)(void));
 */

/*************************************************************************
 * Memory
 *************************************************************************/
extern void *ctk_mem_alloc(ctk_object_handle holder, int size);

extern void ctk_mem_free(ctk_object_handle holder, void *ptr);

/*************************************************************************
 * Screen
 *************************************************************************/

typedef struct
{
    ctk_MMI_screen_id scr_predefined_id;            /* Optional */
    ctk_screen_callback_hdlr scr_on_enter_fp;       /* Mandatory, MMI layer */
    ctk_screen_callback_hdlr scr_on_exit_fp;        /* Mandatory, MMI layer */
    ctk_screen_callback_hdlr scr_on_post_close_fp;  /* Optional */
    ctk_screen_callback_hdlr scr_on_pre_paint_fp;   /* Optional */
    void *scr_localdata_p;                          /* Optional */
} ctk_screen_create_struct;

/************
 *From UA layer 
 ************/
/* Creation */
extern ctk_screen_handle ctk_screen_create(ctk_app_handle appid, ctk_screen_create_struct *scr_create_arg);
extern void ctk_screen_close(ctk_screen_handle scrid);
extern ctk_screen_state_enum ctk_screen_get_current_state(ctk_screen_handle scrid);
extern ctk_MMI_screen_id ctk_screen_get_MMI_screen_id(ctk_screen_handle scrid);
extern kal_bool ctk_screen_is_back_history(ctk_screen_handle scrid);

/* Data members */
extern void ctk_screen_set_on_enter_handler(ctk_screen_handle scrid, ctk_screen_callback_hdlr on_post_enter_fp);
extern ctk_screen_callback_hdlr ctk_screen_get_on_enter_handler(ctk_screen_handle scrid);
extern void ctk_screen_set_on_exit_handler(ctk_screen_handle scrid, ctk_screen_callback_hdlr on_exit_fp);
extern ctk_screen_callback_hdlr ctk_screen_get_on_exit_handler(ctk_screen_handle scrid);
extern void ctk_screen_set_on_post_close_handler(ctk_screen_handle scrid, ctk_screen_callback_hdlr on_post_close_fp);
extern ctk_screen_callback_hdlr ctk_screen_get_on_post_close_handler(ctk_screen_handle scrid);
extern void ctk_screen_set_on_pre_paint_handler(ctk_screen_handle scrid, ctk_screen_callback_hdlr on_pre_paint_fp);
extern ctk_screen_callback_hdlr ctk_screen_get_on_pre_paint_handler(ctk_screen_handle scrid);

extern void ctk_screen_set_local_data(ctk_screen_handle scrid, void *data);
extern void *ctk_screen_get_local_data(ctk_screen_handle scrid);

/* WAP widget integration */
extern void ctk_screen_set_msf_window(ctk_screen_handle scrid, kal_uint32 window);
extern kal_uint32 ctk_screen_get_msf_window(ctk_screen_handle scrid);

/* Layout */
extern void ctk_screen_attach_layout(ctk_screen_handle scrid, ctk_layout_handle layoutid);
extern ctk_layout_handle ctk_screen_get_layout(ctk_screen_handle scrid);

/* Window management */
extern ctk_screen_handle ctk_screen_get_current_scrid(void);

extern void ctk_screen_invoke_on_enter(ctk_screen_handle scrid);
extern void ctk_screen_invoke_on_exit(ctk_screen_handle scrid);
extern void ctk_screen_invoke_redraw(ctk_screen_handle scrid);

/************
 * From MMI Layer 
 * (Typically used in the OnEnter or OnExit callback handler)
 ************/
extern void ctk_screen_enter(ctk_screen_handle scrid);

/* extern void ctk_screen_redraw(ctk_screen_handle scrid); */
extern void ctk_screen_exit(ctk_screen_handle scrid, ctk_screen_exit_enum exit_type);
extern void ctk_screen_redraw(ctk_screen_handle scrid);

/* 
 * Key handling 
 */

/* Typically used by OnEnter callback */
extern void ctk_screen_get_LSK_label(ctk_screen_handle scrid, ctk_string_id *label, ctk_image_id *image);
extern void ctk_screen_get_RSK_label(ctk_screen_handle scrid, ctk_string_id *label, ctk_image_id *image);

extern void ctk_screen_enable_key_again(ctk_screen_handle scrid);

extern void ctk_screen_addLSK(
                ctk_screen_handle scrid,
                ctk_string_id label,
                ctk_image_id image,
                ctk_screen_callback_hdlr softkey_fp,
                /* MMI layer */ kal_bool onetime);

extern void ctk_screen_addRSK(
                ctk_screen_handle scrid,
                ctk_string_id label,
                ctk_image_id image,
                ctk_screen_callback_hdlr softkey_fp,
                /* MMI layer */ kal_bool onetime);

extern void ctk_screen_addLSK_UA(
                ctk_screen_handle scrid,
                ctk_string_id label,
                ctk_image_id image,
                ctk_screen_callback_hdlr softkey_MMI_fp,
                ctk_screen_callback_hdlr softkey_UA_fp,
                kal_bool onetime);

extern void ctk_screen_addRSK_UA(
                ctk_screen_handle scrid,
                ctk_string_id label,
                ctk_image_id image,
                ctk_screen_callback_hdlr softkey_MMI_fp,
                ctk_screen_callback_hdlr softkey_UA_fp,
                kal_bool onetime);

extern ctk_key_identifier_t ctk_screen_addLSK_with_id(
                                ctk_screen_handle scrid,
                                ctk_string_id label,
                                ctk_image_id image,
                                ctk_key_identifer_callback_hdlr softkey_MMI_fp,
                                ctk_key_identifer_callback_hdlr softkey_UA_fp,
                                kal_bool onetime);

extern ctk_key_identifier_t ctk_screen_addRSK_with_id(
                                ctk_screen_handle scrid,
                                ctk_string_id label,
                                ctk_image_id image,
                                ctk_key_identifer_callback_hdlr softkey_MMI_fp,
                                ctk_key_identifer_callback_hdlr softkey_UA_fp,
                                kal_bool onetime);

extern void ctk_screen_add_key(
                ctk_screen_handle scrid,
                ctk_key_code keycode,
                ctk_screen_callback_hdlr key_MMI_fp,
                kal_bool onetime);

extern void ctk_screen_add_key_UA(
                ctk_screen_handle scrid,
                ctk_key_code keycode,
                ctk_screen_callback_hdlr key_MMI_fp,
                ctk_screen_callback_hdlr key_UA_fp,
                kal_bool onetime);

extern ctk_key_identifier_t ctk_screen_add_key_with_id(
                                ctk_screen_handle scrid,
                                ctk_key_code keycode,
                                ctk_key_identifer_callback_hdlr softkey_MMI_fp,
                                ctk_key_identifer_callback_hdlr softkey_UA_fp,
                                kal_bool onetime);

/*
 * for inline edit only
 */

extern void ctk_screen_add_inline_Done(
                ctk_screen_handle scrid,
                ctk_screen_callback_hdlr softkey_fp,
                /* MMI layer */ kal_bool onetime);

extern void ctk_screen_add_inline_Done_UA(
                ctk_screen_handle scrid,
                ctk_screen_callback_hdlr softkey_MMI_fp,
                ctk_screen_callback_hdlr softkey_UA_fp,
                kal_bool onetime);

/*************************************************************************
 * Layout
 *************************************************************************/
extern ctk_screen_handle ctk_layout_get_parent_screen(ctk_layout_handle layoutid);
extern ctk_layout_handle ctk_screen_get_layout_handle(ctk_screen_handle scrid);
extern void ctk_layout_close(ctk_layout_handle layoutid);

/*************************************************************************
 * Layout of Inline Edit
 *************************************************************************/

typedef struct
{
    int in_num_items;                       /* Mandatory */
    int in_highlighted;
    ctk_string_id in_str_title;
    ctk_image_id in_img_title;
    ctk_screen_callback_hdlr in_cancel_fp;  /* default to GoBackHistory */
    kal_bool in_disable_icons;
    kal_bool in_disable_done;               /* Done key */
    kal_bool in_set_LSK;
} ctk_inline_create_struct;

typedef struct
{
    U16 title;
} ctk_inline_item_caption_copy_struct;

typedef struct
{
    ctk_inline_activation_enum activation;

    S32 max_len;        /* In Unicode, not including '\0' */
    ctk_input_type_enum input_type;
    U8 *default_text;   /* Optional */
#ifdef WAP_SUPPORT
    kal_bool is_UTF8;
#endif 
} ctk_inline_item_single_line_copy_struct;

typedef struct
{
    S32 num_options;
    const U16 *list_options_strid;  /* a list of string ID */
    int highlighted;
} ctk_inline_item_select_copy_struct;

typedef struct
{
    U8 *text;
#ifdef WAP_SUPPORT
    kal_bool is_UTF8;
#endif 
    /* OPTIONAL: Customize left softkey (executed in the MMI layer) */
    ctk_void_callback_hdlr edit_fp;
    ctk_string_id edit_strid;
    ctk_image_id edit_imageid;
} ctk_inline_item_display_only_copy_struct;

typedef struct
{
    S32 max_len;        /* In Unicode, not including '\0' */
    ctk_input_type_enum input_type;
    U8 *default_text;   /* Optional */
    ctk_string_id str_title;
    ctk_image_id img_title;
#ifdef WAP_SUPPORT
    kal_bool is_UTF8;
#endif 
    kal_bool use_input_method_menu;
} ctk_inline_item_editor_copy_struct;

typedef struct
{
    S32 max_len;        /* In Unicode, not including '\0' */
    ctk_input_type_enum input_type;
    U8 *default_text;   /* Optional */
    ctk_string_id str_title;
    ctk_image_id img_title;
#ifdef WAP_SUPPORT
    kal_bool is_UTF8;
#endif 
    kal_bool use_input_method_menu;

    ctk_string_id edit_strid;
    ctk_image_id edit_imageid;
    ctk_void_callback_hdlr edit_fp;
    U8 *content;
} ctk_inline_item_utf8_editor_copy_struct;

typedef struct
{
    kal_uint8 IP[4];
} ctk_inline_item_IP4_copy_struct;

typedef union
{
    char *input_buffer;
    int select_highlight;
} ctk_inline_result_union;

extern ctk_layout_handle ctk_inline_create(ctk_app_handle appid, ctk_inline_create_struct *lc);

extern void ctk_inline_set_item_copy(
                ctk_layout_handle layoutid,
                int index,
                U16 icon,
                ctk_string_id str_title,
                ctk_inline_item_type_enum type,
                void *copy_struct);

extern void ctk_inline_set_flag(ctk_layout_handle layoutid, int index, ctk_inline_item_flag_t flags);
extern void ctk_inline_unset_flag(ctk_layout_handle layoutid, int index, ctk_inline_item_flag_t flags);

/* extern void ctk_inline_set_item_nocopy(ctk_layout_handle layoutid, int index, ctk_inline_item_type_enum type, void *create_struct); */

extern void ctk_inline_update_display_only_data(ctk_layout_handle layoutid, int index, U8 *text, kal_bool is_UTF8);

extern void ctk_inline_get_result(
                ctk_layout_handle layoutid,
                int index,
                ctk_inline_item_type_enum *type_p,
                ctk_inline_result_union *result_p);

extern void ctk_inline_enable_done(ctk_layout_handle layoutid, kal_bool state);
extern void ctk_inline_set_modified(ctk_layout_handle layoutid);

/*************************************************************************
 * Layout of PlutoMMI categories
 *************************************************************************/
typedef void (*ctk_pcategory_set_softkey_hdlr) (ctk_void_callback_hdlr, MMI_key_event_type);

typedef struct
{
    ctk_layout_callback_hdlr pcat_show_fp;  /* Mandatory */
    ctk_pcategory_set_softkey_hdlr pcat_set_default_RSK_fp;
    ctk_highlight_callback_hdlr pcat_highlight_fp;
} ctk_pcategory_create_struct;

extern ctk_layout_handle ctk_pcategory_create(ctk_app_handle appid, ctk_pcategory_create_struct *pc);
extern U8 *ctk_pcategory_get_gui_buffer(ctk_layout_handle layoutid);

/*************************************************************************
 * Predefined callback functions
 *************************************************************************/
/* OnEnterScreen callback  */
extern void ctk_generic_on_enter(ctk_screen_handle scrid);

/* OnExitScreen callback  */
extern void ctk_generic_on_exit_pause(ctk_screen_handle scrid);
extern void ctk_generic_on_exit_nopause(ctk_screen_handle scrid);

/* Softkey callback  */
extern void ctk_generic_on_goback(ctk_screen_handle scrid);

#endif /* _CTK_H */ 

