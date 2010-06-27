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
 * CTK.C
 *
 * Project:
 * --------
 * Maui
 *
 * Description:
 * ------------
 * CTK - Category Toolkits
 *
 * API of CTK is described in the design document 
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
 *============================================================================
 ****************************************************************************/

/* REFERENCE: widget_ctk.c */

 /*****************************************************************************
 Implementation steps:

 o list
 o Switch to another task
 o Data synchronization
 o stress test on memory
 
 *****************************************************************************/

#define CTK_C
#include "MMI_include.h"
#ifdef OBIGO_Q03C
#include "ctk.h"
#include "kal_active_module.h"

/* MMI header files */
#include "CommonScreens.h"
#include "wgui_inline_edit.h"
#include "mmiapi_func.h"

#ifdef WAP_SUPPORT
// TODO: should I move these functions to MMI ?
extern int widget_utf8_length(const kal_uint8 *s);
extern int widget_ucs2_length(const kal_uint8 *s);
extern int widget_utf8_to_ucs2_string(kal_uint8 *dest, int dest_size, kal_uint8 *src);
extern int widget_ucs2_to_utf8_string(kal_uint8 *dest, int dest_size, kal_uint8 *src);
#endif /* WAP_SUPPORT */ 

extern void mmi_frm_highlight_input_method_generic(void);

#define ASSERT_bypass_temporarily(x)

/*****************************************************************************
 * Define the object system
 *****************************************************************************/

struct _ctk_screen_struct;
struct _ctk_layout_struct;

typedef struct
{
    kal_bool is_set;
    ctk_string_id label;    /* Used only by softkey */
    ctk_image_id image;     /* Used only by softkey */
    ctk_screen_callback_hdlr key_MMI_fp;
    ctk_screen_callback_hdlr key_UA_fp;
    kal_bool onetime;       /* Can only be pressed once */
    kal_bool callback_with_key_identifier;
} ctk_key_info_struct;

#define CTK_OBJECT_HDR                             \
   ctk_object_type_enum type;                      \
   struct _ctk_app_struct  *app_p;      /* owner application */

#define CTK_LAYOUT_HDR                                                                                   \
   ctk_layout_type_enum       lay_type;                                                                  \
   struct _ctk_screen_struct  *lay_parent;                                                               \
   void              (*lay_show_fp)(struct _ctk_screen_struct *, struct _ctk_layout_struct *);           \
   void              (*lay_close_display_fp)(struct _ctk_screen_struct *, struct _ctk_layout_struct *);  \
   void              (*lay_backup_content_fp)(struct _ctk_screen_struct *, struct _ctk_layout_struct *); \
   void              (*lay_release_fp)(struct _ctk_layout_struct *);                                     \
   ctk_layout_callback_hdlr   lay_set_LSK_fp;                                                            \
   ctk_layout_callback_hdlr   lay_set_RSK_fp;                                                            \
   U8                      *lay_inputBuffer;                                                             \
   U8                      *lay_guiBuffer;

typedef struct
{
CTK_OBJECT_HDR} ctk_object_struct;

typedef struct _ctk_app_struct
{
    CTK_OBJECT_HDR ctk_app_state_enum app_state;
    kal_char app_name[CTK_APP_NAME_LEN + 1];
    module_type app_taskid;
    ctk_mem_alloc_hdlr app_mem_alloc_fp;
    ctk_mem_free_hdlr app_mem_free_fp;
    ctk_rpc_void app_rpc_MMI_void_fp;
    ctk_rpc_void app_rpc_UA_void_fp;
    ctk_rpc_handle app_rpc_MMI_handle_fp;
    ctk_rpc_handle app_rpc_UA_handle_fp;
} ctk_app_struct;

typedef struct _ctk_screen_struct
{
    CTK_OBJECT_HDR
        /* state */
    ctk_screen_state_enum scr_state;
    ctk_screen_flag_enum  scr_flag;
    /* MMI screen ID */
    ctk_MMI_screen_id scr_MMI_scrid;
    /* assigned data */
    ctk_screen_callback_hdlr scr_on_enter_fp;
    ctk_screen_callback_hdlr scr_on_pre_paint_fp;   /* After EntryNewScreen and before paint layout */
    ctk_screen_callback_hdlr scr_on_exit_fp;
    ctk_screen_callback_hdlr scr_on_post_close_fp;
    void *scr_localdata_p;
    kal_uint32 scr_msf_window;
    struct _ctk_layout_struct *scr_attached_layout_p;
    ctk_key_info_struct scr_LSK;
    ctk_key_info_struct scr_RSK;
    ctk_key_info_struct scr_left_key;
    ctk_key_info_struct scr_right_key;
    ctk_key_info_struct scr_enter_key;
    /* internal data */
    int scr_key_press_times;
} ctk_screen_struct;

typedef struct _ctk_layout_struct
{
CTK_OBJECT_HDR CTK_LAYOUT_HDR} ctk_layout_struct;

typedef struct
{
    U8 *buffer;
    S32 buffer_size;
    S16 input_type;
    ctk_string_id str_title;
    ctk_image_id img_title;
    kal_bool use_input_method_menu;

    ctk_string_id edit_strid;
    ctk_image_id edit_imageid;
    ctk_void_callback_hdlr edit_fp;
    U8 *content;
} _ctk_utf8_editor;

typedef union
{
    struct
    {
        U16 title;
    } caption;
    struct
    {
        S32 num_options;
        U8 **list_of_options;
        S32 highlighted;
    } select;
    struct
    {
        U8 *buffer;
        S32 buffer_size;    /* In Unicode */
        S16 input_type;
    } single_line;
    struct
    {
        U8 *buffer;
        S32 buffer_size;    /* In Unicode */
        S16 input_type;
        ctk_string_id str_title;
        ctk_image_id img_title;
        kal_bool use_input_method_menu;
    } editor;
    struct
    {
        U8 *IP[4];
        U8 *buffer;
    } IP4;
    struct
    {
        U8 *buffer;
        ctk_void_callback_hdlr edit_fp;
        ctk_string_id edit_strid;
        ctk_image_id edit_imageid;
    } display_only;

    _ctk_utf8_editor utf8_editor;
    
} ctk_inline_item_data_union;

typedef struct
{
    kal_bool created;
    ctk_inline_activation_enum activation;
    ctk_inline_item_type_enum type;
    ctk_inline_item_data_union data;
} ctk_inline_item_struct;

typedef struct
{
    CTK_OBJECT_HDR CTK_LAYOUT_HDR int in_num_items;
    int in_highlighted; /* first highlighted item */

    ctk_string_id in_str_title;
    ctk_image_id in_img_title;
    U16 in_icon_list[CTK_INLINE_MAX_ITEMS];
    ctk_string_id in_title_list[CTK_INLINE_MAX_ITEMS];
    ctk_inline_item_flag_t in_flag_list[CTK_INLINE_MAX_ITEMS];

    ctk_screen_callback_hdlr in_cancel_fp;

    /* the size of in_items is decided at runtime */
    ctk_inline_item_struct *in_items;

    unsigned int in_set_modified:1;
    unsigned int in_set_LSK:1;
    unsigned int in_disable_icons:1;
    unsigned int in_disable_done:1;
} ctk_inline_struct;

typedef struct
{
    CTK_OBJECT_HDR CTK_LAYOUT_HDR ctk_layout_callback_hdlr pcat_show_fp;
    ctk_pcategory_set_softkey_hdlr pcat_set_default_RSK_fp;
    ctk_highlight_callback_hdlr pcat_highlight_fp;
} ctk_pcategory_struct;

typedef struct
{
    ctk_screen_struct *scr_p;
    ctk_MMI_screen_id id;
} ctk_MMI_scrid_map_struct;

/*****************************************************************************
 *
 * Definition of local variable 
 *
 *****************************************************************************/

/*
 * CTK screen 
 */
static ctk_screen_struct *ctk_MMI_scrid_free_list[CTK_SCREEN_MAX];
static ctk_MMI_scrid_map_struct ctk_MMI_scrid_map[CTK_SCREEN_MAX];

/*
 * CTK inline layout
 */

extern wgui_inline_item wgui_inline_items[MAX_INLINE_ITEMS];

static kal_uint16 ctk_empty_string[1] = {0};

static ctk_image_id ctk_inline_current_img_title;


/*
 * CTK service should be used by widget, and entry/draw ctk screen is invoked by KEY_EVENT_UP.
 * When general MMI screen (non-widget screens) gobackhistory and back to ctk screen,
 * entry ctk screen is invoked by KEY_LEFT_ARROW's KEY_EVENT_DOWN.
 * We need to know if ctk screen changes by KEY_EVENT_DOWN.
 *
 * If it triggers by KEY_EVENT_DOWN, we need to discard the key event KEY_EVENT_UP
 * Because we will call SetKeyHandler (..., KEY_EVENT_UP, it will cause execute
 * ctk_screen_general_key_handler() continually.
 */
static mmi_keypads_enum _ctk_skip_key = KEY_INVALID;


/*****************************************************************************
 *
 * Definition of local functions/MACRO
 *
 *****************************************************************************/
#define OBJ_T(p)  ((ctk_object_struct*) p)
#define APP_T(p)  ((ctk_app_struct*) p)
#define SCREEN_T(p)  ((ctk_screen_struct*) p)
#define LAYOUT_T(p)  ((ctk_layout_struct*) p)

#define OBJ_H(p)  ((ctk_object_handle) p)
#define APP_H(p)  ((ctk_app_handle) p)
#define SCREEN_H(p)  ((ctk_screen_handle) p)
#define LAYOUT_H(p)  ((ctk_layout_handle) p)

#define IS_APP(h)    ctk_object_is_type(OBJ_H(h), CTK_OBJECT_TYPE_APP)
#define IS_SCREEN(h) ctk_object_is_type(OBJ_H(h), CTK_OBJECT_TYPE_SCREEN)
#define IS_LAYOUT(h) ctk_object_is_type(OBJ_H(h), CTK_OBJECT_TYPE_LAYOUT)

#define APP_STATE(h) (APP_T(h)->app_state)
#define SCREEN_STATE(h) (SCREEN_T(h)->scr_state)
#define LAYOUT_TYPE(h)  (LAYOUT_T(h)->lay_type)

#define OBJ_GET_APP(h)     (OBJ_T(h)->app_p)


/*****************************************************************************
 * FUNCTION
 *  ctk_get_ctrl_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void *ctk_get_ctrl_buffer(int size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get_ctrl_buffer is sometimes defined as a MACRO and cannot be used as a function pointer */
    return get_ctrl_buffer((kal_uint16) size);
}


/*****************************************************************************
 * FUNCTION
 *  ctk_free_ctrl_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ptr     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void ctk_free_ctrl_buffer(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    free_ctrl_buffer(ptr);
}


/*****************************************************************************
 * FUNCTION
 *  ctk_bzero
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ptr         [IN]         
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
__inline static void ctk_bzero(void *ptr, int size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(ptr);
    memset(ptr, 0, size);
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 


/*****************************************************************************
 * FUNCTION
 *  ctk_convert_input_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static S16 ctk_convert_input_type(ctk_input_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 override_flag = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (type & CTK_INPUT_TYPE_OVERRIDE)
    {
        override_flag = INPUT_TYPE_OVERRIDE_DEFAULT;
    }

    type &= (~CTK_INPUT_TYPE_OVERRIDE);

    switch (type)
    {
        case CTK_INPUT_TYPE_DEFAULT:
            /* Let MMI GUI to determine the input type */
            return INPUT_TYPE_NUMERIC;

        case CTK_INPUT_TYPE_ALPHANUMERIC_SENTENCECASE:
            return INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | override_flag;

        case CTK_INPUT_TYPE_ALPHANUMERIC_UPPERCASE:
            return INPUT_TYPE_ALPHANUMERIC_UPPERCASE | override_flag;

        case CTK_INPUT_TYPE_ALPHANUMERIC_LOWERCASE:
            return INPUT_TYPE_ALPHANUMERIC_LOWERCASE | override_flag;

        case CTK_INPUT_TYPE_ALPHA:
            return INPUT_TYPE_ALPHANUMERIC_LOWERCASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES | override_flag;

        case CTK_INPUT_TYPE_NUMBER:
            return INPUT_TYPE_NUMERIC | override_flag;

        case CTK_INPUT_TYPE_DECIMAL:
            return INPUT_TYPE_DECIMAL_NUMERIC | override_flag;

        case CTK_INPUT_TYPE_PASSWORD_ALPHANUMERIC:
            return INPUT_TYPE_ALPHANUMERIC_PASSWORD | override_flag;
		
		case CTK_INPUT_TYPE_PASSWORD_ALPHA:
			return INPUT_TYPE_ALPHANUMERIC_PASSWORD | INPUT_TYPE_USE_ONLY_ENGLISH_MODES | override_flag;

		case CTK_INPUT_TYPE_PASSWORD_NUMBER:
            return INPUT_TYPE_NUMERIC_PASSWORD | override_flag;

        case CTK_INPUT_TYPE_PHONE_NUMBER:
            /* Input buffer size needs to be incremented by 1 */
            return INPUT_TYPE_PHONE_NUMBER | INPUT_TYPE_PLUS_CHARACTER_HANDLING | override_flag;

        case CTK_INPUT_TYPE_ALPHANUMERIC_SENTENCECASE_USE_ENCODING_BASED_LENGTH:
            return (INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ENCODING_BASED_LENGTH | override_flag);

        default:
            CTK_DBG_ASSERT(0);
            return INPUT_TYPE_ALPHANUMERIC_SENTENCECASE;
    }
}

static void ctk_layout_release_history_data(ctk_layout_struct *this);

/*****************************************************************************
 *
 * CTK Object
 *
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  ctk_object_is_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  obj         [IN]        
 *  type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool ctk_object_is_type(ctk_object_handle obj, ctk_object_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_object_struct *s;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(ctk_object_is_valid_type(obj));

    s = OBJ_T(obj);

    if (s->type == type)
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  ctk_object_is_valid_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  obj     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool ctk_object_is_valid_type(ctk_object_handle obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_object_struct *s;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(obj);
    s = OBJ_T(obj);

    switch (s->type)
    {
        case CTK_OBJECT_TYPE_APP:
        case CTK_OBJECT_TYPE_SCREEN:
        case CTK_OBJECT_TYPE_LAYOUT:
            return KAL_TRUE;
        default:
            return KAL_FALSE;
    }
}

/* -------------------------- Utility Functions  -------------------------------   */


/*****************************************************************************
 * FUNCTION
 *  ctk_object_release
 * DESCRIPTION
 *  
 * PARAMETERS
 *  obj     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
__inline static void ctk_object_release(ctk_object_handle obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_object_struct *this = OBJ_T(obj);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    this->type = CTK_OBJECT_TYPE_INVALID;   /* prevent using the handle after released */

    ctk_mem_free(obj, this);
}

/*****************************************************************************
 *
 * CTK Application
 *
 * Sanity checks
 * 1. ASSERT(IS_APP(appid))
 * 2. check APP_STATE(appid)
 * 3. check unsupported freature
 *
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  ctk_app_create
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cs_arg      [IN]     
 * RETURNS
 *  
 *****************************************************************************/
ctk_app_handle ctk_app_create(ctk_app_create_struct *cs_arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_app_struct *this;

    ctk_mem_alloc_hdlr myalloc;
    ctk_mem_free_hdlr myfree;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT((cs_arg->app_mem_alloc_fp == NULL && cs_arg->app_mem_free_fp == NULL) ||
           (cs_arg->app_mem_alloc_fp != NULL && cs_arg->app_mem_free_fp != NULL));

    CTK_DBG_ASSERT(cs_arg->app_mem_auto_freeall == NULL);   /* not supported yet */

    /* allocate memory */
    myalloc = cs_arg->app_mem_alloc_fp;
    if (myalloc == NULL)
    {
        myalloc = ctk_get_ctrl_buffer;
        myfree = ctk_free_ctrl_buffer;
    }
    else
    {
        myfree = cs_arg->app_mem_free_fp;
    }

    this = myalloc(sizeof(ctk_app_struct));
    ctk_bzero(this, sizeof(ctk_app_struct));

    /* object data */
    this->type = CTK_OBJECT_TYPE_APP;
    this->app_p = this;

    /* app data */
    this->app_state = CTK_APP_STATE_CREATED;

    strcpy(this->app_name, cs_arg->app_name);
    this->app_taskid = cs_arg->app_taskid;
    this->app_mem_alloc_fp = myalloc;
    this->app_mem_free_fp = myfree;
    this->app_rpc_MMI_void_fp = cs_arg->app_rpc_MMI_void_fp;
    this->app_rpc_UA_void_fp = cs_arg->app_rpc_UA_void_fp;
    this->app_rpc_MMI_handle_fp = cs_arg->app_rpc_MMI_handle_fp;
    this->app_rpc_UA_handle_fp = cs_arg->app_rpc_UA_handle_fp;

    return APP_H(this);
}


/*****************************************************************************
 * FUNCTION
 *  ctk_app_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  appid       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ctk_app_close(ctk_app_handle appid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_app_struct *this;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(IS_APP(appid) && APP_STATE(appid) == CTK_APP_STATE_CREATED);
    this = APP_T(appid);

    this->app_state = CTK_APP_STATE_CLOSING;

    // TODO: we should automatically release all screens belong to it. (However, widget library already do this)

    this->app_state = CTK_APP_STATE_CLOSED;

    this->type = CTK_OBJECT_TYPE_INVALID;
    this->app_mem_free_fp(this);
}


/*****************************************************************************
 * FUNCTION
 *  ctk_app_get_state
 * DESCRIPTION
 *  
 * PARAMETERS
 *  appid       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
ctk_app_state_enum ctk_app_get_state(ctk_app_handle appid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(IS_APP(appid));

    return APP_STATE(appid);
}

/*************************************************************************
 *
 * Memory
 *
 *************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  ctk_mem_alloc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  container       [IN]        
 *  size            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *ctk_mem_alloc(ctk_object_handle container, int size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *m;
    ctk_object_struct *this = OBJ_T(container);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CTK_DBG_ASSERT(ctk_object_is_valid_type(container) && this->app_p);

    m = OBJ_GET_APP(this)->app_mem_alloc_fp(size);
    ASSERT(m);  /* We might handle exception in the future */

    ctk_bzero(m, size); /* zero it by default */

    return m;
}


/*****************************************************************************
 * FUNCTION
 *  ctk_mem_free
 * DESCRIPTION
 *  
 * PARAMETERS
 *  container       [IN]        
 *  ptr             [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void ctk_mem_free(ctk_object_handle container, void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_object_struct *this = OBJ_T(container);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CTK_DBG_ASSERT(this->app_p);

    OBJ_GET_APP(this)->app_mem_free_fp(ptr);
}

/*************************************************************************
 *
 * Inter-process execution
 *
 *************************************************************************/

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 


/*****************************************************************************
 * FUNCTION
 *  ctk_remote_execute_in_UA_h
 * DESCRIPTION
 *  
 * PARAMETERS
 *  container       [IN]        
 *  fp              [IN]        
 *  handle          [IN]        
 *  is_blocking     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ctk_remote_execute_in_UA_h(
        ctk_object_handle container,
        void (*fp) (ctk_object_handle),
        ctk_object_handle handle,
        kal_bool is_blocking)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_object_struct *this = OBJ_T(container);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* module_type          modid   = ctk_get_active_module_id(); */

    CTK_DBG_ASSERT(ctk_object_is_valid_type(container) && OBJ_GET_APP(this));

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* 0 */ 
    if (this->app_p->app_rpc_UA_handle_fp)
    {
        this->app_p->app_rpc_UA_handle_fp(fp, handle, is_blocking);
    }
    else
    {
        fp(handle);
    }
#endif /* 0 */ 

}


/*****************************************************************************
 * FUNCTION
 *  ctk_remote_execute_in_MMI_h
 * DESCRIPTION
 *  
 * PARAMETERS
 *  container       [IN]        
 *  fp              [IN]        
 *  handle          [IN]        
 *  is_blocking     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ctk_remote_execute_in_MMI_h(
        ctk_object_handle container,
        void (*fp) (ctk_object_handle),
        ctk_object_handle handle,
        kal_bool is_blocking)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_object_struct *this = OBJ_T(container);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* module_type                  modid    = ctk_get_active_module_id(); */

    CTK_DBG_ASSERT(ctk_object_is_valid_type(container) && OBJ_GET_APP(this));

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* 0 */ 
    if (this->app_p->app_rpc_MMI_handle_fp)
    {
        this->app_p->app_rpc_MMI_handle_fp(fp, handle, is_blocking);
    }
    else
    {
        fp(handle);
    }
#endif /* 0 */ 
}

/*************************************************************************
 *
 * CTK Screen
 *
 * Sanity check:
 *  1. ASSERT(IS_SCREEN(screenid))
 * 2. check SCREEN_STATE(screenid)
 * 3. check unsupported freature
 *
 *************************************************************************/

/*************************************************************************
 * CTK Screen - local functions 
 *************************************************************************/

/* 
 * management of MMI screen ID
 */


/*****************************************************************************
 * FUNCTION
 *  ctk_MMI_scrid_set_map
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_p       [IN]         
 *  id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void ctk_MMI_scrid_set_map(ctk_screen_struct *scr_p, ctk_MMI_screen_id id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < CTK_SCREEN_MAX; i++)
    {
        if (ctk_MMI_scrid_map[i].scr_p == NULL)
        {
            ctk_MMI_scrid_map[i].scr_p = scr_p;
            ctk_MMI_scrid_map[i].id = id;
            return;
        }
    }
    ASSERT(0);
}


/*****************************************************************************
 * FUNCTION
 *  ctk_MMI_scrid_get_handle_from_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static ctk_screen_struct *ctk_MMI_scrid_get_handle_from_id(ctk_MMI_screen_id id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(id);

    for (i = 0; i < CTK_SCREEN_MAX; i++)
    {
        if (ctk_MMI_scrid_map[i].id == id)
        {
            return ctk_MMI_scrid_map[i].scr_p;
        }
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  ctk_screen_allocate_MMI_scrid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_p               [IN]         
 *  predefined_id       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static ctk_MMI_screen_id ctk_screen_allocate_MMI_scrid(ctk_screen_struct *scr_p, ctk_MMI_screen_id predefined_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    ctk_MMI_screen_id id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(scr_p);

    if (predefined_id)
    {
        id = predefined_id;
    }
    else
    {
        for (i = 0; i < CTK_SCREEN_MAX; i++)
        {
            if (ctk_MMI_scrid_free_list[i] == 0)
            {
                ctk_MMI_scrid_free_list[i] = scr_p;
                id = CTK_BASE + i;
                break;
            }
        }
        ASSERT(id);
    }

    /* Set the mapping */
    ctk_MMI_scrid_set_map(scr_p, id);

    return id;
}


/*****************************************************************************
 * FUNCTION
 *  ctk_screen_release_MMI_scrid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void ctk_screen_release_MMI_scrid(ctk_MMI_screen_id id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id >= CTK_BASE && id < CTK_BASE + CTK_SCREEN_MAX)   /* auto-generated MMI screen ID */
    {
        ctk_MMI_scrid_free_list[id - CTK_BASE] = NULL;
    }

    for (i = 0; i < CTK_SCREEN_MAX; i++)
    {
        if (ctk_MMI_scrid_map[i].id == id)
        {
            ctk_MMI_scrid_map[i].id = 0;
            ctk_MMI_scrid_map[i].scr_p = NULL;
        }
    }
}

/*
 * Implementation of MMI callbacks
 */


/*****************************************************************************
 * FUNCTION
 *  ctk_screen_get_current
 * DESCRIPTION
 *  This function gets the current mtk_sceen
 * PARAMETERS
 *  void
 * RETURNS
 *  The current mtk_screen_struct
 *  NULL if the current MMI screen is not an CTK screen.
 *****************************************************************************/
static ctk_screen_struct *ctk_screen_get_current(void)  /* Used after SetExitHandler */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ctk_MMI_scrid_get_handle_from_id(GetExitScrnID());
}


/*****************************************************************************
 * FUNCTION
 *  ctk_screen_general_entry_function
 * DESCRIPTION
 *  This function acts as the entry function of all screens belong to CTK
 *  It is typically invoked from GoBackHistory()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ctk_screen_general_entry_function(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_struct *this = ctk_MMI_scrid_get_handle_from_id(GetCurrScrnId());

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CTK_LOG("ctk_screen_general_entry_function() - enter");
    CTK_DBG_ASSERT(mmiapi_is_MMI_task());

    ASSERT(this && this->scr_on_enter_fp);

    this->scr_on_enter_fp(SCREEN_H(this));

    CTK_LOG("ctk_screen_general_entry_function() - exit");
}


/*****************************************************************************
 * FUNCTION
 *  ctk_screen_general_exit_handler
 * DESCRIPTION
 *  This function acts as the exit function of all screens belong to CTK
 *  It is typically invoked in the ExecuteCurrExitHandler()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ctk_screen_general_exit_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_struct *this;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CTK_LOG("ctk_screen_general_exit_handler() - enter");
    CTK_DBG_ASSERT(mmiapi_is_MMI_task());

    this = ctk_screen_get_current();
    ASSERT(this && this->scr_on_exit_fp);

    this->scr_on_exit_fp(SCREEN_H(this));

    CTK_LOG("ctk_screen_general_exit_handler() - exit");
}


/*****************************************************************************
 * FUNCTION
 *  ctk_screen_general_key_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ctk_screen_general_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_struct *this;
    ctk_key_info_struct *key = NULL;
    U16 keycode, keytype;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CTK_LOG("ctk_screen_general_key_handler() - enter");
    CTK_DBG_ASSERT(mmiapi_is_MMI_task());

    GetkeyInfo(&keycode, &keytype);

    if (keytype == KEY_EVENT_UP && _ctk_skip_key == keycode)
    {
        /*
         * CTK service should be used by widget, and entry/draw ctk screen is invoked by KEY_EVENT_UP.
         * When general MMI screen (non-widget screens) gobackhistory and back to ctk screen,
         * entry ctk screen is invoked by KEY_LEFT_ARROW's KEY_EVENT_DOWN.
         * We need to know if ctk screen changes by KEY_EVENT_DOWN.
         *
         * If it triggers by KEY_EVENT_DOWN, we need to discard the key event KEY_EVENT_UP
         * Because we will call SetKeyHandler (..., KEY_EVENT_UP, it will cause execute
         * ctk_screen_general_key_handler() continually.
         */
        _ctk_skip_key = KEY_INVALID;
        return;
    }
    _ctk_skip_key = KEY_INVALID;

    this = ctk_screen_get_current();
    ASSERT(this);

    switch (keycode)
    {
        case KEY_ENTER:
            if (this->scr_enter_key.is_set)
            {
                key = &(this->scr_enter_key);
            }
            else
            {   /*
                 * if no add KEY_ENTER in ctk_screen_add_key_UA, 
                 * KEY_ENTER is the same with KEY_LSK 
                 */
                key = &(this->scr_LSK);
            }
            break;
        case KEY_LSK:
            key = &(this->scr_LSK);
            break;
        case KEY_RSK:
            key = &(this->scr_RSK);
            break;
        case KEY_LEFT_ARROW:
            key = &(this->scr_left_key);
            break;
        case KEY_RIGHT_ARROW:
            key = &(this->scr_right_key);
            break;
        default:
            CTK_DBG_ASSERT(0);
            return;
    }

    if (key->onetime)   /* All keys with 'onetime' attribute are mutual exclusive */
    {
        if (this->scr_key_press_times > 0)
        {
            return;
        }
        this->scr_key_press_times++;    /* the key handler might invoke ctk_screen_enable_key_again */

        ClearInputEventHandler(MMI_DEVICE_ALL);
    }

    if (key->key_MMI_fp)
    {
        if (key->callback_with_key_identifier)
        {
            ((ctk_key_identifer_callback_hdlr) key->key_MMI_fp) (SCREEN_H(this), (ctk_key_identifier_t) key);
        }
        else
        {
            key->key_MMI_fp(SCREEN_H(this));
        }
    }

    if (key->key_UA_fp)
    {
        // TODO: Race condition
        /*
         * If we invoke key->key_UA_fp here, WAP might not be in a consistent state
         * * If we use ctk_remote_execute_in_UA_h asynchronous, the screen might be already switched after WAP process
         * * this RPC request.
         * * If we use ctk_remote_execute_in_UA_h blocking, WAP wait for MMI in the key handler.
         * *
         * * Rationale: key handler should be processed in WAP instead of MMI.
         * *
         */
        if (key->callback_with_key_identifier)
        {
            ((ctk_key_identifer_callback_hdlr) key->key_UA_fp) (SCREEN_H(this), (ctk_key_identifier_t) key);
        }
        else
        {
            key->key_UA_fp(SCREEN_H(this));
        }
        /* ctk_remote_execute_in_UA_h(SCREEN_H(this), key->key_UA_fp, SCREEN_H(this), KAL_FALSE); */
    }
}


/*****************************************************************************
 * FUNCTION
 *  ctk_screen_setup_key_handler
 * DESCRIPTION
 *  Setup key handler
 * PARAMETERS
 *  this            [IN]     
 *  layout_p        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void ctk_screen_setup_key_handler(ctk_screen_struct *this, ctk_layout_struct *layout_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 keycode, keytype;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * We do not use change_left_softkey, ... to set label & text 
     * * because it was already drawn in ShowCategoryXScreen
     */
    if (this->scr_LSK.is_set && layout_p->lay_set_LSK_fp)
    {
        layout_p->lay_set_LSK_fp(LAYOUT_H(layout_p));
    }
    if (this->scr_RSK.is_set && layout_p->lay_set_RSK_fp)
    {
        layout_p->lay_set_RSK_fp(LAYOUT_H(layout_p));
    }

    /*
     * CTK service should be used by widget, and entry/draw ctk screen is invoked by KEY_EVENT_UP.
     * When general MMI screen (non-widget screens) gobackhistory and back to ctk screen,
     * entry ctk screen is invoked by KEY_LEFT_ARROW's KEY_EVENT_DOWN.
     * We need to know if ctk screen changes by KEY_EVENT_DOWN.
     *
     * If it triggers by KEY_EVENT_DOWN, we need to discard the key event KEY_EVENT_UP
     * Because we will call SetKeyHandler (..., KEY_EVENT_UP, it will cause execute
     * ctk_screen_general_key_handler() continually.
     * 
     * We don't need consider KEY_ENTER because if the screen doesn't set LSK key handler,
     * MMI framework will convert KEY_ENTER to KEY_LSK
     */
    GetkeyInfo(&keycode, &keytype);
    if (IsMainLCDHistoryBack() &&
        (keycode == KEY_LEFT_ARROW || keycode == KEY_RIGHT_ARROW) &&
        keytype == KEY_EVENT_DOWN)
    {
        _ctk_skip_key = keycode;
    }

    if (this->scr_enter_key.is_set)
    {
        SetKeyHandler(ctk_screen_general_key_handler, KEY_ENTER, KEY_EVENT_UP);
        ClearKeyHandler(KEY_ENTER, KEY_EVENT_DOWN);
    }
    if (this->scr_left_key.is_set)
    {
        // TODO: we set KEY_EVENT_UP instead of KEY_EVENT_DOWN  because widget use KEY_EVENT_UP, 
        // and it might invoke widget function immediately after go back to widget 
        SetKeyHandler(ctk_screen_general_key_handler, KEY_LEFT_ARROW, KEY_EVENT_UP);
        ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    }
    if (this->scr_right_key.is_set)
    {
        SetKeyHandler(ctk_screen_general_key_handler, KEY_RIGHT_ARROW, KEY_EVENT_UP);
        ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ctk_screen_add_history
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_p       [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void ctk_screen_add_history(ctk_screen_struct *scr_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    S16 zero = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CTK_LOG("ctk_screen_add_history()");
    CTK_DBG_ASSERT(mmiapi_is_MMI_task());

    h.scrnID = scr_p->scr_MMI_scrid;
    h.entryFuncPtr = ctk_screen_general_entry_function;

    /* History data are stored in ctk_layout instead of MMI history */
    memset(h.guiBuffer, 0, MAX_GUI_BUFFER);
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & zero);

    // TODO: we may use use a variant of AddHistory() because AddHistory() waste MAX_GUI_BUFFER bytes.
    AddHistory(h);
}

/*************************************************************************
 * CTK Screen - APIs from the UA layer
 *************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  ctk_screen_create
 * DESCRIPTION
 *  
 * PARAMETERS
 *  appid       [IN]        
 *  sc_arg      [IN]         
 * RETURNS
 *  
 *****************************************************************************/
ctk_screen_handle ctk_screen_create(ctk_app_handle appid, ctk_screen_create_struct *sc_arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_struct *this;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(IS_APP(appid) && APP_STATE(appid) == CTK_APP_STATE_CREATED);
    ASSERT(sc_arg->scr_on_enter_fp && sc_arg->scr_on_exit_fp);

    this = (ctk_screen_struct*) ctk_mem_alloc(appid, sizeof(ctk_screen_struct));

    this->type = CTK_OBJECT_TYPE_SCREEN;
    this->app_p = APP_T(appid);

    this->scr_state = CTK_SCREEN_STATE_CREATED;
    this->scr_flag = CTK_SCREEN_FLAG_NONE;

    this->scr_MMI_scrid = ctk_screen_allocate_MMI_scrid(this, sc_arg->scr_predefined_id);
    this->scr_on_enter_fp = sc_arg->scr_on_enter_fp;
    this->scr_on_exit_fp = sc_arg->scr_on_exit_fp;
    this->scr_on_post_close_fp = sc_arg->scr_on_post_close_fp;
    this->scr_on_pre_paint_fp = sc_arg->scr_on_pre_paint_fp;

    this->scr_localdata_p = sc_arg->scr_localdata_p;
    this->scr_attached_layout_p = NULL;

    this->scr_key_press_times = 0;

    return SCREEN_H(this);
}


/*****************************************************************************
 * FUNCTION
 *  ctk_screen_set_on_enter_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrid                   [IN]        
 *  on_post_enter_fp        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ctk_screen_set_on_enter_handler(ctk_screen_handle scrid, ctk_screen_callback_hdlr on_post_enter_fp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_struct *this = SCREEN_T(scrid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(IS_SCREEN(scrid));   /* available for all ctk_screen_state_enum */

    this->scr_on_enter_fp = on_post_enter_fp;
}


/*****************************************************************************
 * FUNCTION
 *  ctk_screen_get_on_enter_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrid       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
ctk_screen_callback_hdlr ctk_screen_get_on_enter_handler(ctk_screen_handle scrid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_struct *this = SCREEN_T(scrid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(IS_SCREEN(scrid));   /* available for all ctk_screen_state_enum */

    return this->scr_on_enter_fp;
}


/*****************************************************************************
 * FUNCTION
 *  ctk_screen_set_on_exit_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrid           [IN]        
 *  on_exit_fp      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ctk_screen_set_on_exit_handler(ctk_screen_handle scrid, ctk_screen_callback_hdlr on_exit_fp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_struct *this = SCREEN_T(scrid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(IS_SCREEN(scrid));   /* available for all ctk_screen_state_enum */

    this->scr_on_exit_fp = on_exit_fp;
}


/*****************************************************************************
 * FUNCTION
 *  ctk_screen_get_on_exit_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrid       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
ctk_screen_callback_hdlr ctk_screen_get_on_exit_handler(ctk_screen_handle scrid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_struct *this = SCREEN_T(scrid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(IS_SCREEN(scrid));   /* available for all ctk_screen_state_enum */

    return this->scr_on_exit_fp;
}


/*****************************************************************************
 * FUNCTION
 *  ctk_screen_set_on_post_close_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrid                   [IN]        
 *  on_post_close_fp        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ctk_screen_set_on_post_close_handler(ctk_screen_handle scrid, ctk_screen_callback_hdlr on_post_close_fp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_struct *this = SCREEN_T(scrid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(IS_SCREEN(scrid));   /* available for all ctk_screen_state_enum */

    this->scr_on_post_close_fp = on_post_close_fp;
}


/*****************************************************************************
 * FUNCTION
 *  ctk_screen_get_on_post_close_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrid       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
ctk_screen_callback_hdlr ctk_screen_get_on_post_close_handler(ctk_screen_handle scrid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_struct *this = SCREEN_T(scrid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(IS_SCREEN(scrid));   /* available for all ctk_screen_state_enum */

    return this->scr_on_post_close_fp;
}


/*****************************************************************************
 * FUNCTION
 *  ctk_screen_set_on_pre_paint_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrid               [IN]        
 *  on_pre_paint_fp     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ctk_screen_set_on_pre_paint_handler(ctk_screen_handle scrid, ctk_screen_callback_hdlr on_pre_paint_fp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_struct *this = SCREEN_T(scrid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(IS_SCREEN(scrid));   /* available for all ctk_screen_state_enum */

    this->scr_on_pre_paint_fp = on_pre_paint_fp;
}


/*****************************************************************************
 * FUNCTION
 *  ctk_screen_get_on_pre_paint_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrid       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
ctk_screen_callback_hdlr ctk_screen_get_on_pre_paint_handler(ctk_screen_handle scrid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_struct *this = SCREEN_T(scrid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(IS_SCREEN(scrid));   /* available for all ctk_screen_state_enum */

    return this->scr_on_pre_paint_fp;
}


/*****************************************************************************
 * FUNCTION
 *  ctk_screen_set_local_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrid       [IN]        
 *  data        [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void ctk_screen_set_local_data(ctk_screen_handle scrid, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_struct *this = SCREEN_T(scrid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(IS_SCREEN(scrid));   /* available for all ctk_screen_state_enum */

    this->scr_localdata_p = data;
}


/*****************************************************************************
 * FUNCTION
 *  ctk_screen_get_local_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrid       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *ctk_screen_get_local_data(ctk_screen_handle scrid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_struct *this = SCREEN_T(scrid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(IS_SCREEN(scrid));   /* available for all ctk_screen_state_enum */

    return this->scr_localdata_p;
}

/* adaptation to WAP widget */


/*****************************************************************************
 * FUNCTION
 *  ctk_screen_set_msf_window
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrid       [IN]        
 *  window      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ctk_screen_set_msf_window(ctk_screen_handle scrid, kal_uint32 window)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_struct *this = SCREEN_T(scrid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(IS_SCREEN(scrid));   /* available for all ctk_screen_state_enum */

    this->scr_msf_window = window;
}


/*****************************************************************************
 * FUNCTION
 *  ctk_screen_get_msf_window
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrid       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 ctk_screen_get_msf_window(ctk_screen_handle scrid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_struct *this = SCREEN_T(scrid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(IS_SCREEN(scrid));   /* available for all ctk_screen_state_enum */

    return this->scr_msf_window;
}


/*****************************************************************************
 * FUNCTION
 *  ctk_screen_attach_layout
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrid           [IN]        
 *  layoutid        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ctk_screen_attach_layout(ctk_screen_handle scrid, ctk_layout_handle layoutid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_struct *this = SCREEN_T(scrid);
    ctk_layout_struct *layout = LAYOUT_T(layoutid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(IS_SCREEN(scrid) && (SCREEN_STATE(scrid) == CTK_SCREEN_STATE_CREATED));

    ASSERT(this->scr_attached_layout_p == NULL);
    ASSERT(layout->lay_parent == NULL);

    this->scr_state = CTK_SCREEN_STATE_LAYOUT_ATTACHED;
    this->scr_attached_layout_p = LAYOUT_T(layoutid);
    layout->lay_parent = this;
}

/* might return NULL */


/*****************************************************************************
 * FUNCTION
 *  ctk_screen_get_layout
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrid       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
ctk_layout_handle ctk_screen_get_layout(ctk_screen_handle scrid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_struct *this = SCREEN_T(scrid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(IS_SCREEN(scrid));   /* available for all ctk_screen_state_enum */

    return LAYOUT_H(this->scr_attached_layout_p);
}


/*****************************************************************************
 * FUNCTION
 *  ctk_screen_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrid       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ctk_screen_close(ctk_screen_handle scrid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_struct *this = SCREEN_T(scrid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CTK_LOG("ctk_screen_close()");

    /* The screen should NOT be active */
    ASSERT(IS_SCREEN(scrid));
    EXT_ASSERT(
        (SCREEN_STATE(scrid) == CTK_SCREEN_STATE_LAYOUT_ATTACHED) || (SCREEN_STATE(scrid) == CTK_SCREEN_STATE_CREATED),
        SCREEN_STATE(scrid),
        0,
        0);

    this->scr_state = CTK_SCREEN_STATE_CLOSING;

    if (this->scr_attached_layout_p)
    {
        ctk_layout_close(LAYOUT_H(this->scr_attached_layout_p));
        this->scr_attached_layout_p = NULL;
    }

    ctk_screen_release_MMI_scrid(this->scr_MMI_scrid);

    this->scr_state = CTK_SCREEN_STATE_CLOSED;

    // TODO: Should we run this in UA layer? Maybe not. (The execution order need to be kept)
    if (this->scr_on_post_close_fp)
    {
        this->scr_on_post_close_fp(scrid);
    }

    ctk_object_release(scrid);
}


/*****************************************************************************
 * FUNCTION
 *  ctk_screen_get_current_state
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrid       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
ctk_screen_state_enum ctk_screen_get_current_state(ctk_screen_handle scrid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(IS_SCREEN(scrid));

    return SCREEN_STATE(scrid);
}


/*****************************************************************************
 * FUNCTION
 *  ctk_screen_get_MMI_screen_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrid       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
ctk_MMI_screen_id ctk_screen_get_MMI_screen_id(ctk_screen_handle scrid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_struct *this = SCREEN_T(scrid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(IS_SCREEN(scrid));

    return this->scr_MMI_scrid;
}

/*************************************************************************
 * CTK Screen - Screen management (in UA or MMI layer)
 *
 * Sanity check:
 *  1. ASSERT(IS_SCREEN(screenid))
 * 3. check unsupported freature
 *
 *************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  ctk_screen_get_current_scrid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
ctk_screen_handle ctk_screen_get_current_scrid(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return SCREEN_H(ctk_screen_get_current());
}


/*****************************************************************************
 * FUNCTION
 *  ctk_screen_invoke_on_enter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrid       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ctk_screen_invoke_on_enter(ctk_screen_handle scrid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_struct *this = SCREEN_T(scrid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(IS_SCREEN(scrid));
    CTK_LOG("ctk_screen_invoke_on_enter()");

    ctk_remote_execute_in_MMI_h(OBJ_H(scrid), this->scr_on_enter_fp, SCREEN_H(this), KAL_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  ctk_screen_invoke_on_exit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrid       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ctk_screen_invoke_on_exit(ctk_screen_handle scrid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_struct *this = SCREEN_T(scrid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(IS_SCREEN(scrid));
    CTK_LOG("ctk_screen_invoke_on_exit()");

    // TODO: What if the screen is changed before this function is executed. Maybe we should use ctk_screen_general_exit_handler instead
    ctk_remote_execute_in_MMI_h(OBJ_H(scrid), this->scr_on_exit_fp, SCREEN_H(this), KAL_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  ctk_screen_invoke_redraw
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrid       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ctk_screen_invoke_redraw(ctk_screen_handle scrid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* ctk_remote_execute_in_MMI_h(OBJ_H(scrid), ctk_screen_redraw, scrid); */
    ctk_screen_struct *this = SCREEN_T(scrid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(IS_SCREEN(scrid));
    CTK_LOG("ctk_screen_invoke_redraw()");

    if (this->scr_state != CTK_SCREEN_STATE_ACTIVE)
    {
        /* User application might update the content of the CTK screen when it is not active */
        CTK_LOG("ctk_screen_invoke_redraw() - screen not active");
        return;
    }

    /* The content of the list might be already changed, we should redraw it immediately */
    ctk_remote_execute_in_MMI_h(OBJ_H(scrid), ctk_screen_redraw, SCREEN_H(scrid), KAL_TRUE);
}


/*************************************************************************
 * CTK Screen - APIs from the MMI layer
 *
 * Sanity check:
 *  1. ASSERT(IS_SCREEN(screenid))
 * 2. check SCREEN_STATE(screenid)
 * 3. check unsupported freature
 * 4. check the current task id  is MMI
 *
 *************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  ctk_screen_enter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrid       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ctk_screen_enter(ctk_screen_handle scrid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_struct *this = SCREEN_T(scrid);
    ctk_layout_struct *layout;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CTK_LOG("ctk_screen_enter() - enter");
    CTK_DBG_ASSERT(mmiapi_is_MMI_task());

    ASSERT(IS_SCREEN(scrid) && SCREEN_STATE(scrid) == CTK_SCREEN_STATE_LAYOUT_ATTACHED);
    /* in MMI task */
    ASSERT_bypass_temporarily(ctk_get_active_module_id() == MOD_MMI);

    this->scr_state = CTK_SCREEN_STATE_ACTIVE;

    /* Note that we do not ctk_screen_enable_key_again() in ctk_screen_redraw */
    ctk_screen_enable_key_again(scrid);

    layout = this->scr_attached_layout_p;
    ASSERT(layout);

    /*
     * 1. Execute current exit handler & register new exit handler 
     * * After this, lay_show_fp can use ctk_screen_get_current by using current screen ID
     */
    EntryNewScreen(this->scr_MMI_scrid, ctk_screen_general_exit_handler, NULL, NULL);

    /* 
     * 2. Display the layout
     * The internal implementation of lay_show_fp might be ShowCategoryXScreen or direct use of wgui API
     */

    if (this->scr_on_pre_paint_fp)
    {
        this->scr_on_pre_paint_fp(scrid);
    }

    layout->lay_show_fp(this, layout);

    /*
     * 3. Release history
     *
     * In original MMI, releasing of history data was done in ExecutePopHistory() ->decrement()
     * CTK maintains history data by itself
     */
    ctk_layout_release_history_data(layout);
    this->scr_flag = CTK_SCREEN_FLAG_NONE;

    /* 4. Register Key handlers */
    ctk_screen_setup_key_handler(this, layout);

    CTK_LOG("ctk_screen_enter() - exit");
}


/*****************************************************************************
 * FUNCTION
 *  ctk_screen_redraw
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrid       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ctk_screen_redraw(ctk_screen_handle scrid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_struct *this = SCREEN_T(scrid);
    ctk_layout_struct *layout_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CTK_LOG("ctk_screen_redraw() - enter");
    CTK_DBG_ASSERT(mmiapi_is_MMI_task());

    if (this->scr_state != CTK_SCREEN_STATE_ACTIVE)
    {   /* User application might update the content of the CTK screen when it is not active */
        CTK_LOG("ctk_screen_redraw() - exit - screen not active");
        return;
    }

    /*
     * We can not simply use RedrawCategoryFunction.
     * *
     * * For example:
     * * In a displayed inline layout, we change some data by ctk_inline_set_item_copy(), then the data
     * * contained in MMI (wgui_inline_items) still point to old data (which might be already released).
     * * RedrawCategoryScreen will reference the old data.
     * * As a result, we need to call lay_show_fp() again.
     * *
     */
    ASSERT_bypass_temporarily(ctk_get_active_module_id() == MOD_MMI);
    CTK_DBG_ASSERT(IS_SCREEN(scrid));
    layout_p = this->scr_attached_layout_p;
    ASSERT(layout_p);

    /*
     * We backup the state of the screen first, use it to show the layout, and then release it.
     */
    this->scr_flag = CTK_SCREEN_FLAG_REDRAW;
    layout_p->lay_backup_content_fp(this, layout_p);
    layout_p->lay_show_fp(this, layout_p);
    ctk_layout_release_history_data(layout_p);
    this->scr_flag = CTK_SCREEN_FLAG_NONE;

    /* We still need to register key handler because ShowCategoryXScreen might override it. */
    ctk_screen_setup_key_handler(this, layout_p);

    CTK_LOG("ctk_screen_redraw() - exit - finished");
}


/*****************************************************************************
 * FUNCTION
 *  ctk_screen_exit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrid           [IN]        
 *  exit_type       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ctk_screen_exit(ctk_screen_handle scrid, ctk_screen_exit_enum exit_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_struct *this = SCREEN_T(scrid);
    ctk_layout_struct *lay_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CTK_LOG("ctk_screen_exit() - enter");
    CTK_DBG_ASSERT(mmiapi_is_MMI_task());

    /* Initialize */
    ASSERT_bypass_temporarily(ctk_get_active_module_id() == MOD_MMI);
    CTK_DBG_ASSERT(IS_SCREEN(scrid) && SCREEN_STATE(scrid) == CTK_SCREEN_STATE_ACTIVE);

    this->scr_state = CTK_SCREEN_STATE_LAYOUT_ATTACHED;

    lay_p = this->scr_attached_layout_p;
    ASSERT(lay_p);
    if (lay_p->lay_close_display_fp)    /* Close display */
    {
        lay_p->lay_close_display_fp(this, lay_p);
    }

    /* Debug: these history data should be released immediately after the screen is displayed. */
    CTK_DBG_ASSERT(lay_p->lay_inputBuffer == NULL && lay_p->lay_guiBuffer == NULL);

    /* Put into history */
    switch (exit_type)
    {
        case CTK_SCREEN_EXIT_NOPAUSE:
            break;
        case CTK_SCREEN_EXIT_PAUSE:
            CTK_LOG("ctk_screen_exit() - backup history data and add history");
            this->scr_flag = CTK_SCREEN_FLAG_EXIT_IN_HISTORY;
            lay_p->lay_backup_content_fp(this, lay_p);
            ctk_screen_add_history(this);
            break;
        case CTK_SCREEN_EXIT_PAUSE_NOT_IN_HISTORY:
            CTK_LOG("ctk_screen_exit() - backup history data");
            this->scr_flag = CTK_SCREEN_FLAG_EXIT_NOT_IN_HISTORY;
            lay_p->lay_backup_content_fp(this, lay_p);
            break;
        default:
            ASSERT(0);
            break;
    }

    CTK_LOG("ctk_screen_exit() - exit");
}


/*****************************************************************************
 * FUNCTION
 *  ctk_screen_exit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrid           [IN]        
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool ctk_screen_is_back_history(ctk_screen_handle scrid)
{
    ctk_screen_struct *this = SCREEN_T(scrid);

    if (this->scr_flag == CTK_SCREEN_FLAG_EXIT_IN_HISTORY)
    {
        return KAL_TRUE;
    }
    return KAL_FALSE;
}


/*************************************************************************
 *
 * CTK Screen - Key handling
 *
 *************************************************************************/
/* Used when we need parameters for ShowCategoryXScreen */


/*****************************************************************************
 * FUNCTION
 *  ctk_screen_get_LSK_label
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrid       [IN]        
 *  label       [OUT]         
 *  image       [OUT]         
 * RETURNS
 *  void
 *****************************************************************************/
void ctk_screen_get_LSK_label(ctk_screen_handle scrid, ctk_string_id *label, ctk_image_id *image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_struct *this = SCREEN_T(scrid);
    ctk_key_info_struct *info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    info = &(this->scr_LSK);
    if (info->is_set)
    {
        *label = info->label;
        *image = info->image;
    }
    else
    {
        *label = 0;
        *image = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  ctk_screen_get_RSK_label
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrid       [IN]        
 *  label       [OUT]         
 *  image       [OUT]         
 * RETURNS
 *  void
 *****************************************************************************/
void ctk_screen_get_RSK_label(ctk_screen_handle scrid, ctk_string_id *label, ctk_image_id *image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_struct *this = SCREEN_T(scrid);
    ctk_key_info_struct *info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    info = &(this->scr_RSK);
    if (info->is_set)
    {
        *label = info->label;
        *image = info->image;
    }
    else
    {
        *label = 0;
        *image = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  ctk_screen_add_softkey_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrid                               [IN]        
 *  label                               [IN]        
 *  image                               [IN]        
 *  softkey_MMI_fp                      [IN]        
 *  softkey_UA_fp                       [IN]        
 *  onetime                             [IN]        
 *  keycode                             [IN]        
 *  callback_with_key_identifier        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static ctk_key_identifier_t ctk_screen_add_softkey_internal(
                                ctk_screen_handle scrid,
                                ctk_string_id label,
                                ctk_image_id image,
                                ctk_screen_callback_hdlr softkey_MMI_fp,
                                ctk_screen_callback_hdlr softkey_UA_fp,
                                kal_bool onetime,
                                ctk_key_code keycode,
                                kal_bool callback_with_key_identifier)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_struct *this = SCREEN_T(scrid);
    ctk_key_info_struct *info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (keycode == KEY_LSK)
    {
        CTK_INIT_STRUCT(this->scr_LSK);
        info = &(this->scr_LSK);
    }
    else
    {
        CTK_INIT_STRUCT(this->scr_RSK);
        info = &(this->scr_RSK);
    }
    info->is_set = KAL_TRUE;
    info->image = image;
    info->label = label;
    info->key_MMI_fp = softkey_MMI_fp;
    info->key_UA_fp = softkey_UA_fp;
    info->onetime = onetime;
    info->callback_with_key_identifier = callback_with_key_identifier;
    return (ctk_key_identifier_t) info;
}


/*****************************************************************************
 * FUNCTION
 *  ctk_screen_add_key_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrid                               [IN]        
 *  keycode                             [IN]        
 *  key_MMI_fp                          [IN]        
 *  key_UA_fp                           [IN]        
 *  onetime                             [IN]        
 *  callback_with_key_identifier        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static ctk_key_identifier_t ctk_screen_add_key_internal(
                                ctk_screen_handle scrid,
                                ctk_key_code keycode,
                                ctk_screen_callback_hdlr key_MMI_fp,
                                ctk_screen_callback_hdlr key_UA_fp,
                                kal_bool onetime,
                                kal_bool callback_with_key_identifier)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_struct *this = SCREEN_T(scrid);
    ctk_key_info_struct *info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (keycode)
    {
        case KEY_ENTER:
            CTK_INIT_STRUCT(this->scr_enter_key);
            info = &(this->scr_enter_key);
            break;
        case KEY_LEFT_ARROW:
            CTK_INIT_STRUCT(this->scr_left_key);
            info = &(this->scr_left_key);
            break;
        case KEY_RIGHT_ARROW:
            CTK_INIT_STRUCT(this->scr_right_key);
            info = &(this->scr_right_key);
            break;
        default:
            /* We only support limited keys */
            CTK_DBG_ASSERT(0);
            return 0;
    }
    info->is_set = KAL_TRUE;
    info->key_MMI_fp = key_MMI_fp;
    info->key_UA_fp = key_UA_fp;
    info->onetime = onetime;
    info->callback_with_key_identifier = callback_with_key_identifier;
    return (ctk_key_identifier_t) info;
}


/*****************************************************************************
 * FUNCTION
 *  ctk_screen_addLSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrid               [IN]        
 *  label               [IN]        
 *  image               [IN]        
 *  softkey_MMI_fp      [IN]        
 *  onetime             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ctk_screen_addLSK(
        ctk_screen_handle scrid,
        ctk_string_id label,
        ctk_image_id image,
        ctk_screen_callback_hdlr softkey_MMI_fp,
        kal_bool onetime)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ctk_screen_add_softkey_internal(scrid, label, image, softkey_MMI_fp, NULL, onetime, KEY_LSK, KAL_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  ctk_screen_addRSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrid               [IN]        
 *  label               [IN]        
 *  image               [IN]        
 *  softkey_MMI_fp      [IN]        
 *  onetime             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ctk_screen_addRSK(
        ctk_screen_handle scrid,
        ctk_string_id label,
        ctk_image_id image,
        ctk_screen_callback_hdlr softkey_MMI_fp,
        kal_bool onetime)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ctk_screen_add_softkey_internal(scrid, label, image, softkey_MMI_fp, NULL, onetime, KEY_RSK, KAL_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  ctk_screen_add_key
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrid           [IN]        
 *  keycode         [IN]        
 *  key_MMI_fp      [IN]        
 *  onetime         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ctk_screen_add_key(
        ctk_screen_handle scrid,
        ctk_key_code keycode,
        ctk_screen_callback_hdlr key_MMI_fp,
        kal_bool onetime)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ctk_screen_add_key_internal(scrid, keycode, key_MMI_fp, NULL, onetime, KAL_FALSE);
}

/* if label = image = 0, the key will not take effect */


/*****************************************************************************
 * FUNCTION
 *  ctk_screen_addLSK_UA
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrid               [IN]        
 *  label               [IN]        
 *  image               [IN]        
 *  softkey_MMI_fp      [IN]        
 *  softkey_UA_fp       [IN]        
 *  onetime             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ctk_screen_addLSK_UA(
        ctk_screen_handle scrid,
        ctk_string_id label,
        ctk_image_id image,
        ctk_screen_callback_hdlr softkey_MMI_fp,
        ctk_screen_callback_hdlr softkey_UA_fp,
        kal_bool onetime)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ctk_screen_add_softkey_internal(scrid, label, image, softkey_MMI_fp, softkey_UA_fp, onetime, KEY_LSK, KAL_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  ctk_screen_addRSK_UA
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrid               [IN]        
 *  label               [IN]        
 *  image               [IN]        
 *  softkey_MMI_fp      [IN]        
 *  softkey_UA_fp       [IN]        
 *  onetime             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ctk_screen_addRSK_UA(
        ctk_screen_handle scrid,
        ctk_string_id label,
        ctk_image_id image,
        ctk_screen_callback_hdlr softkey_MMI_fp,
        ctk_screen_callback_hdlr softkey_UA_fp,
        kal_bool onetime)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ctk_screen_add_softkey_internal(scrid, label, image, softkey_MMI_fp, softkey_UA_fp, onetime, KEY_RSK, KAL_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  ctk_screen_add_key_UA
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrid           [IN]        
 *  keycode         [IN]        
 *  key_MMI_fp      [IN]        
 *  key_UA_fp       [IN]        
 *  onetime         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ctk_screen_add_key_UA(
        ctk_screen_handle scrid,
        ctk_key_code keycode,
        ctk_screen_callback_hdlr key_MMI_fp,
        ctk_screen_callback_hdlr key_UA_fp,
        kal_bool onetime)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ctk_screen_add_key_internal(scrid, keycode, key_MMI_fp, key_UA_fp, onetime, KAL_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  ctk_screen_addLSK_with_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrid               [IN]        
 *  label               [IN]        
 *  image               [IN]        
 *  softkey_MMI_fp      [IN]        
 *  softkey_UA_fp       [IN]        
 *  onetime             [IN]        
 * RETURNS
 *  
 *****************************************************************************/
extern ctk_key_identifier_t ctk_screen_addLSK_with_id(
                                ctk_screen_handle scrid,
                                ctk_string_id label,
                                ctk_image_id image,
                                ctk_key_identifer_callback_hdlr softkey_MMI_fp,
                                ctk_key_identifer_callback_hdlr softkey_UA_fp,
                                kal_bool onetime)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ctk_screen_add_softkey_internal(
            scrid,
            label,
            image,
            (ctk_screen_callback_hdlr) softkey_MMI_fp,
            (ctk_screen_callback_hdlr) softkey_UA_fp,
            onetime,
            KEY_LSK,
            KAL_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  ctk_screen_addRSK_with_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrid               [IN]        
 *  label               [IN]        
 *  image               [IN]        
 *  softkey_MMI_fp      [IN]        
 *  softkey_UA_fp       [IN]        
 *  onetime             [IN]        
 * RETURNS
 *  
 *****************************************************************************/
extern ctk_key_identifier_t ctk_screen_addRSK_with_id(
                                ctk_screen_handle scrid,
                                ctk_string_id label,
                                ctk_image_id image,
                                ctk_key_identifer_callback_hdlr softkey_MMI_fp,
                                ctk_key_identifer_callback_hdlr softkey_UA_fp,
                                kal_bool onetime)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ctk_screen_add_softkey_internal(
            scrid,
            label,
            image,
            (ctk_screen_callback_hdlr) softkey_MMI_fp,
            (ctk_screen_callback_hdlr) softkey_UA_fp,
            onetime,
            KEY_RSK,
            KAL_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  ctk_screen_add_key_with_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrid           [IN]        
 *  keycode         [IN]        
 *  key_MMI_fp      [IN]        
 *  key_UA_fp       [IN]        
 *  onetime         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
ctk_key_identifier_t ctk_screen_add_key_with_id(
                        ctk_screen_handle scrid,
                        ctk_key_code keycode,
                        ctk_key_identifer_callback_hdlr key_MMI_fp,
                        ctk_key_identifer_callback_hdlr key_UA_fp,
                        kal_bool onetime)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ctk_screen_add_key_internal(
            scrid,
            keycode,
            (ctk_screen_callback_hdlr) key_MMI_fp,
            (ctk_screen_callback_hdlr) key_UA_fp,
            onetime,
            KAL_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  ctk_screen_enable_key_again
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrid       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ctk_screen_enable_key_again(ctk_screen_handle scrid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_struct *this = SCREEN_T(scrid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    this->scr_key_press_times = 0;
}


/*****************************************************************************
 * FUNCTION
 *  ctk_screen_add_inline_Done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrid           [IN]        
 *  softkey_fp      [IN]        
 *  onetime         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ctk_screen_add_inline_Done(
        ctk_screen_handle scrid,
        ctk_screen_callback_hdlr softkey_fp,
        /* MMI layer */ kal_bool onetime)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ctk_screen_add_inline_Done_UA(scrid, softkey_fp, NULL, onetime);
}


/*****************************************************************************
 * FUNCTION
 *  ctk_screen_add_inline_Done_UA
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrid               [IN]        
 *  softkey_MMI_fp      [IN]        
 *  softkey_UA_fp       [IN]        
 *  onetime             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ctk_screen_add_inline_Done_UA(
        ctk_screen_handle scrid,
        ctk_screen_callback_hdlr softkey_MMI_fp,
        ctk_screen_callback_hdlr softkey_UA_fp,
        kal_bool onetime)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * Inline edit might place the Done key at the left softkey instead of the right one
     * for single-line edit.
     */
    ctk_screen_addLSK_UA(scrid, 0, 0, softkey_MMI_fp, softkey_UA_fp, onetime);
    ctk_screen_addRSK_UA(scrid, 0, 0, softkey_MMI_fp, softkey_UA_fp, onetime);
}

/*************************************************************************
 *
 * CTK Layout
 *
 *************************************************************************/

/*************************************************************************
 * CTK Layout - internal implementation
 *************************************************************************/

/* Save inputBuffer and guiBuffer of the layout object without changing MMI history */


/*****************************************************************************
 * FUNCTION
 *  ctk_layout_AddNHistory
 * DESCRIPTION
 *  
 * PARAMETERS
 *  this            [IN]         
 *  guiBuffer       [IN]         
 *  inputBuffer     [IN]         
 *  size            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void ctk_layout_AddNHistory(ctk_layout_struct *this, U8 *guiBuffer, U8 *inputBuffer, U16 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* cf. AddNHistory */
    CTK_DBG_ASSERT(this->lay_inputBuffer == NULL && this->lay_guiBuffer == NULL);       /* prevent memory leak */

    this->lay_inputBuffer = ctk_mem_alloc(LAYOUT_H(this), size + ENCODING_LENGTH + 2);
    memcpy(this->lay_inputBuffer, &size, 2);
    memcpy((PS8) (this->lay_inputBuffer + 2), (PS8) inputBuffer, (U32) size);

    this->lay_guiBuffer = ctk_mem_alloc(LAYOUT_H(this), MAX_GUI_BUFFER);
    memcpy(this->lay_guiBuffer, guiBuffer, MAX_GUI_BUFFER);
}


/*****************************************************************************
 * FUNCTION
 *  ctk_layout_GetCurrNInputBuffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  this        [IN]     
 *  size        [IN]     
 * RETURNS
 *  
 *****************************************************************************/
static U8 *ctk_layout_GetCurrNInputBuffer(ctk_layout_struct *this, U16 *size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* cf. GetCurrNInputBuffer */
    if (this->lay_inputBuffer)
    {
        memcpy(size, this->lay_inputBuffer, 2);
        return this->lay_inputBuffer + 2;
    }
    else
    {
        *size = 0;
        return NULL;
    }
}

/* Save inputBuffer and guiBuffer of the layout object without changing MMI history */


/*****************************************************************************
 * FUNCTION
 *  ctk_layout_AddHistory
 * DESCRIPTION
 *  
 * PARAMETERS
 *  this        [IN]     
 *  h           [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void ctk_layout_AddHistory(ctk_layout_struct *this, history *h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* cf. AddHistory */
    int length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CTK_DBG_ASSERT(this->lay_inputBuffer == NULL && this->lay_guiBuffer == NULL);       /* prevent memory leak */

    length = mmi_ucs2strlen((PS8) h->inputBuffer);
    if (length)
    {
        this->lay_inputBuffer = ctk_mem_alloc(LAYOUT_H(this), (length + 1) * ENCODING_LENGTH);
        mmi_ucs2cpy((PS8) this->lay_inputBuffer, (PS8) h->inputBuffer);
    }
    this->lay_guiBuffer = ctk_mem_alloc(LAYOUT_H(this), MAX_GUI_BUFFER);
    memcpy(this->lay_guiBuffer, h->guiBuffer, MAX_GUI_BUFFER);
}


/*****************************************************************************
 * FUNCTION
 *  ctk_layout_release_history_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  this        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void ctk_layout_release_history_data(ctk_layout_struct *this)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (this->lay_guiBuffer)
    {
        ctk_mem_free(OBJ_H(this), this->lay_guiBuffer);
        this->lay_guiBuffer = NULL;
    }
    if (this->lay_inputBuffer)
    {
        ctk_mem_free(OBJ_H(this), this->lay_inputBuffer);
        this->lay_inputBuffer = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  ctk_layout_general_set_LSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  layoutid        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void ctk_layout_general_set_LSK(ctk_layout_handle layoutid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CTK_UNUSED(layoutid);

    SetLeftSoftkeyFunction(ctk_screen_general_key_handler, KEY_EVENT_UP);
}

#if 0   /* Compilation warning */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

/*************************************************************************
 * CTK Layout - public API
 *************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  ctk_layout_get_parent_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  layoutid        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
ctk_screen_handle ctk_layout_get_parent_screen(ctk_layout_handle layoutid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_layout_struct *this = LAYOUT_T(layoutid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(IS_LAYOUT(layoutid));

    return LAYOUT_H(this->lay_parent);
}


/*****************************************************************************
 * FUNCTION
 *  ctk_screen_get_layout_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrid           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
ctk_layout_handle ctk_screen_get_layout_handle(ctk_screen_handle scrid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_struct *this = SCREEN_T(scrid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(IS_SCREEN(scrid));   /* available for all ctk_screen_state_enum */

    return (ctk_layout_handle)(this->scr_attached_layout_p);
}


/* 
 * Typically application developers do not need to invoke ctk_layout_close() by himself
 * because ctk_screen_close will do this.
 */


/*****************************************************************************
 * FUNCTION
 *  ctk_layout_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  layoutid        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ctk_layout_close(ctk_layout_handle layoutid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_layout_struct *this = LAYOUT_T(layoutid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(IS_LAYOUT(layoutid));

    if (this->lay_release_fp)
    {
        /* Release data for different layout types */
        this->lay_release_fp(this);
    }

    ctk_layout_release_history_data(this);

    ctk_object_release(layoutid);
}

/* -------------------------- Utility Functions  -------------------------------   */


/*****************************************************************************
 * FUNCTION
 *  ctk_layout_create_base_object
 * DESCRIPTION
 *  
 * PARAMETERS
 *  appid       [IN]        
 *  type        [IN]        
 *  size        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
__inline static ctk_layout_struct *ctk_layout_create_base_object(
                                    ctk_app_handle appid,
                                    ctk_layout_type_enum type,
                                    int size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_layout_struct *this;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(IS_APP(appid) && APP_STATE(appid) == CTK_APP_STATE_CREATED);

    this = (ctk_layout_struct*) ctk_mem_alloc(appid, size);

    this->type = CTK_OBJECT_TYPE_LAYOUT;
    this->app_p = APP_T(appid);

    this->lay_type = type;
    this->lay_parent = NULL;

    return this;
}

/*************************************************************************
 * 
 * CTK Inline Layout
 * -------------
 *
 * Note: we can not change the item type of inline editor after it is displayed;
 * Otherwise, the history data might be corrupted.
 *
 *************************************************************************/

#define IS_INLINE_LAYOUT(h)  (IS_LAYOUT(h) && LAYOUT_TYPE(h) == CTK_LAYOUT_TYPE_INLINE)
#define INLINE_T(p)  ((ctk_inline_struct*)p)

static void ctk_inline_general_edit_custom_function(void);
static void ctk_inline_key_handler_wrapper(void);

_ctk_utf8_editor *ctk_utf8_editor_context_p;

/*************************************************************************
 * CTK Inline Layout - internal implementation
 *************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  ctk_inline_general_edit_custom_function
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ctk_inline_general_edit_custom_function(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
    SetInputMethodAndDoneCaptionIcon(ctk_inline_current_img_title);
    SetLeftSoftkeyFunction(EntryScrForInputMethodAndDone, KEY_EVENT_UP);
}

/* Copy From DataAccount */


/*****************************************************************************
 * FUNCTION
 *  ctk_inline_IP4_print_3digit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  output      [IN]        
 *  num         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void ctk_inline_IP4_print_3digit(PU8 output, U8 num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf[8];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(buf, "%03d", num);
    buf[3] = '\0';
    mmi_asc_to_ucs2((PS8) output, (PS8) buf);
}


/*****************************************************************************
 * FUNCTION
 *  ctk_inline_IP4_contruct_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  string_buffer       [IN]     
 *  IP1                 [IN]     
 *  IP2                 [IN]     
 *  IP3                 [IN]     
 *  IP4                 [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void ctk_inline_IP4_contruct_hdlr(U8 *string_buffer, U8 *IP1, U8 *IP2, U8 *IP3, U8 *IP4)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 buf[4 * 2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* The conversion is not efficient */
    ctk_inline_IP4_print_3digit(buf, (U8) gui_atoi((UI_string_type) IP1));
    mmi_ucs2cpy((PS8) string_buffer, (PS8) buf);
    mmi_ucs2cat((PS8) string_buffer, (PS8) L".");

    ctk_inline_IP4_print_3digit(buf, (U8) gui_atoi((UI_string_type) IP2));
    mmi_ucs2cat((PS8) string_buffer, (PS8) buf);
    mmi_ucs2cat((PS8) string_buffer, (PS8) L".");

    ctk_inline_IP4_print_3digit(buf, (U8) gui_atoi((UI_string_type) IP3));
    mmi_ucs2cat((PS8) string_buffer, (PS8) buf);
    mmi_ucs2cat((PS8) string_buffer, (PS8) L".");

    ctk_inline_IP4_print_3digit(buf, (U8) gui_atoi((UI_string_type) IP4));
    mmi_ucs2cat((PS8) string_buffer, (PS8) buf);
}


/*****************************************************************************
 * FUNCTION
 *  ctk_inline_fill_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_p       [IN]     
 *  this        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void ctk_inline_fill_data(ctk_screen_struct *scr_p, ctk_inline_struct *this)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    ctk_inline_item_struct *item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(wgui_inline_items, 0, sizeof(wgui_inline_items));

    for (i = 0; i < this->in_num_items; i++)
    {
        item = &this->in_items[i];

        switch (item->activation)
        {
            case CTK_INLINE_ACTIVATION_AUTO:
                SetInlineItemActivation(wgui_inline_items + i, INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
                break;
            case CTK_INLINE_ACTIVATION_LSK:
                SetInlineItemActivation(wgui_inline_items + i, KEY_LSK, KEY_EVENT_UP);
                break;
        }

        switch (item->type)
        {
            case CTK_INLINE_ITEM_TYPE_CAPTION:
                SetInlineItemCaption(wgui_inline_items + i, (U8*) GetString(item->data.caption.title));
                break;

            case CTK_INLINE_ITEM_TYPE_SINGLE_LINE:
                SetInlineItemTextEdit(
                    wgui_inline_items + i,
                    item->data.single_line.buffer,
                    item->data.single_line.buffer_size,
                    item->data.single_line.input_type);
                /*
                 * Because our Theme could set Inline menu Selector and single line highlight color,
                 * we need to disable InlineItemHighlight here.
                 */
                DisableInlineItemHighlight(wgui_inline_items+i); /* Follow UI Convention */
                break;

            case CTK_INLINE_ITEM_TYPE_UTF8_EDITOR:
                /* Special handle in ctk */
                SetInlineItemDisplayOnly(wgui_inline_items + i, (U8*) item->data.utf8_editor.buffer);
                ctk_utf8_editor_context_p = (_ctk_utf8_editor*)(&(item->data));
                break;

            case CTK_INLINE_ITEM_TYPE_EDITOR:
                SetInlineItemFullScreenEdit(
                    wgui_inline_items + i,
                    item->data.editor.str_title,
                    item->data.editor.img_title,
                    item->data.editor.buffer,
                    item->data.editor.buffer_size,
                    item->data.editor.input_type);
                if (item->data.editor.use_input_method_menu)
                {
                    SetInlineFullScreenEditCustomFunction(
                        wgui_inline_items + i,
                        ctk_inline_general_edit_custom_function);
                }

                break;

            case CTK_INLINE_ITEM_TYPE_IP4:
                SetInlineItemIP4(
                    wgui_inline_items + i,
                    item->data.IP4.IP[0],
                    item->data.IP4.IP[1],
                    item->data.IP4.IP[2],
                    item->data.IP4.IP[3],
                    ctk_inline_IP4_contruct_hdlr);
                break;

            case CTK_INLINE_ITEM_TYPE_DISPLAY_ONLY:
                SetInlineItemDisplayOnly(wgui_inline_items + i, (U8*) item->data.display_only.buffer);
                break;

            case CTK_INLINE_ITEM_TYPE_SELECT:
                SetInlineItemSelect(
                    wgui_inline_items + i,
                    item->data.select.num_options,
                    item->data.select.list_of_options,
                    &(item->data.select.highlighted));
                break;

            default:
                break;
        }

        if (this->in_flag_list[i] & CTK_INLINE_ITEM_FLAG_UNDERLINE)
        {
            SetInlineItemDottedUnderline(wgui_inline_items + i);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  ctk_utf8_editor_input_method_and_done_go_back
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ctk_utf8_editor_input_method_and_done_go_back(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ctk_utf8_editor_context_p->buffer_size is bytes in UTF8 */
    memcpy(ctk_utf8_editor_context_p->buffer, ctk_utf8_editor_context_p->content, ctk_utf8_editor_context_p->buffer_size*ENCODING_LENGTH);
    GoBeyondMarkerScr(SCR_ID_CTK_UTF8_EDITOR_SCREEN);
}


/*****************************************************************************
 * FUNCTION
 *  ctk_utf8_editor_input_method_and_done_hilite_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void ctk_utf8_editor_input_method_and_done_hilite_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (index == 0)
	{
		ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
		ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
		SetLeftSoftkeyFunction(ctk_utf8_editor_input_method_and_done_go_back, KEY_EVENT_UP);
		SetKeyHandler(ctk_utf8_editor_input_method_and_done_go_back, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
		SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
		SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
	}
	else
	{
		mmi_frm_highlight_input_method_generic();
	}
}


/*****************************************************************************
 * FUNCTION
 *  entry_ctk_utf8_editor_input_method_and_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void entry_ctk_utf8_editor_input_method_and_done (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[10];
    U16 numItems;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_INPUT_METHOD_AND_DONE, NULL, entry_ctk_utf8_editor_input_method_and_done, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_INPUT_METHOD_AND_DONE);

    SetParentHandler(MENU_INPUT_METHOD_AND_DONE_OPTION_ID);
    RegisterHighlightHandler(ctk_utf8_editor_input_method_and_done_hilite_handler);
    numItems = GetNumOfChild(MENU_INPUT_METHOD_AND_DONE_OPTION_ID);
    GetSequenceStringIds(MENU_INPUT_METHOD_AND_DONE_OPTION_ID, nStrItemList);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (PU16) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  entry_ctk_utf8_editor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void entry_ctk_utf8_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 *gui_buffer_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CTK_UTF8_EDITOR_SCREEN, NULL, entry_ctk_utf8_editor, NULL);
    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_CTK_UTF8_EDITOR_SCREEN);
    if (gui_buffer_p == NULL)
    {
        /* ctk_utf8_editor_context_p->buffer_size is bytes in UTF8 */
        memcpy(ctk_utf8_editor_context_p->content, ctk_utf8_editor_context_p->buffer, ctk_utf8_editor_context_p->buffer_size*ENCODING_LENGTH);
    }

    ShowCategory215Screen(
        ctk_utf8_editor_context_p->str_title,
        ctk_utf8_editor_context_p->img_title,
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        ctk_utf8_editor_context_p->input_type,
        ctk_utf8_editor_context_p->content,
        ctk_utf8_editor_context_p->buffer_size,
        gui_buffer_p);

    SetLeftSoftkeyFunction(entry_ctk_utf8_editor_input_method_and_done, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  ctk_inline_general_highlight_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void ctk_inline_general_highlight_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* 
     * We add left softkey here.
     * It is tricky that WGUI might set LSK for some inline items
     */
    ctk_screen_struct *scr;
    ctk_inline_struct *this;
    ctk_inline_item_struct *item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CTK_LOG("ctk_inline_general_highlight_handler()");

    scr = ctk_screen_get_current();
    ASSERT(scr && scr->scr_attached_layout_p);

    this = (ctk_inline_struct*) scr->scr_attached_layout_p;

    CTK_DBG_ASSERT(index < this->in_num_items);
    if (index >= this->in_num_items)
    {
        return;
    }

    item = &this->in_items[index];

    /* Add LSK for display only */
    if (item->type == CTK_INLINE_ITEM_TYPE_DISPLAY_ONLY && item->data.display_only.edit_fp)
    {
        ChangeLeftSoftkey(item->data.display_only.edit_strid, item->data.display_only.edit_imageid);
        SetCategory57LeftSoftkeyFunction(item->data.display_only.edit_fp);
    }
    else if (item->type == CTK_INLINE_ITEM_TYPE_UTF8_EDITOR)
    {
        ChangeLeftSoftkey(item->data.utf8_editor.edit_strid, item->data.utf8_editor.edit_imageid);
        SetCategory57LeftSoftkeyFunction(entry_ctk_utf8_editor);
    }
    else if (this->in_set_LSK)  /* Basically, in_set_LSK and 'display only' item are mutual exclusive */
    {
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        SetCategory57LeftSoftkeyFunction(ctk_inline_key_handler_wrapper);
    }

    /* Change title when highlight is changed */
    if (this->in_title_list[index])
    {
        ChangeTitleString((PU8) GetString(this->in_title_list[index]));
        draw_title();
    }
}


/*****************************************************************************
 * FUNCTION
 *  ctk_inline_general_cancel_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ctk_inline_general_cancel_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_struct *scr;
    ctk_inline_struct *this;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CTK_LOG("ctk_inline_general_cancel_handler()");

    scr = ctk_screen_get_current();
    ASSERT(scr && scr->scr_attached_layout_p);

    this = (ctk_inline_struct*) scr->scr_attached_layout_p;

    if (this->in_cancel_fp)
    {
        // TODO: invoke in UA layer?
        this->in_cancel_fp(SCREEN_H(scr));
    }
    else
    {
        GoBackHistory();
    }
}


/*****************************************************************************
 * FUNCTION
 *  ctk_inline_show
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_p       [IN]     
 *  lay_p       [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void ctk_inline_show(ctk_screen_struct *scr_p, ctk_layout_struct *lay_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 inputBufferSize;

    ctk_inline_struct *this = INLINE_T(lay_p);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CTK_LOG("ctk_inline_show()");

    InitializeCategory57Screen();
    guiBuffer = this->lay_guiBuffer;
    inputBuffer = ctk_layout_GetCurrNInputBuffer(lay_p, &inputBufferSize);

    SetParentHandler(0);
    RegisterHighlightHandler(ctk_inline_general_highlight_handler);

    ctk_inline_fill_data(scr_p, this);

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, this->in_num_items, inputBuffer);
    }

    /* This is not recorded in history and should be set every time before ShowCategory57Screen */
    if (this->in_disable_done)
    {
        DisableCategory57ScreenDone();
    }
    else
    {
        EnableCategory57ScreenDone();
    }
    if (this->in_set_modified != 1)
    {
        ShowCategory57Screen(
            (U16) this->in_str_title,
            (U16) this->in_img_title,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            this->in_num_items,
            this->in_disable_icons ? NULL : this->in_icon_list,
            wgui_inline_items,
            this->in_highlighted,   /* ignored if history exists */
            guiBuffer);

        /* Workaround */
        ctk_inline_current_img_title = this->in_img_title;
    }
    else
    {
        gdi_lcd_freeze(TRUE);

        ShowCategory57Screen(
            (U16) this->in_str_title,
            (U16) this->in_img_title,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            this->in_num_items,
            this->in_disable_icons ? NULL : this->in_icon_list,
            wgui_inline_items,
            this->in_highlighted,   /* ignored if history exists */
            guiBuffer);

        /* Workaround */
        ctk_inline_current_img_title = this->in_img_title;


        /* This will be recorded in history and we do not need to set it every time. */
        set_wgui_inline_list_menu_changed();

        gdi_lcd_freeze(FALSE);
        gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
        this->in_set_modified = 1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  ctk_inline_close_display
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_p       [IN]     
 *  this        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void ctk_inline_close_display(ctk_screen_struct *scr_p, ctk_layout_struct *this)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CTK_UNUSED(scr_p);
    CTK_UNUSED(this);

    CTK_LOG("ctk_inline_close_display()");

    CloseCategory57Screen();
}


/*****************************************************************************
 * FUNCTION
 *  ctk_inline_release
 * DESCRIPTION
 *  
 * PARAMETERS
 *  layout_p        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void ctk_inline_release(ctk_layout_struct *layout_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    ctk_inline_struct *this = (ctk_inline_struct*) layout_p;
    ctk_inline_item_struct *item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(this->in_items);

    for (i = 0; i < this->in_num_items; i++)
    {
        item = &this->in_items[i];
        if (!item->created)
        {
            continue;
        }

        switch (item->type)
        {
            case CTK_INLINE_ITEM_TYPE_SINGLE_LINE:
                ctk_mem_free(OBJ_H(this), item->data.single_line.buffer);
                break;
            case CTK_INLINE_ITEM_TYPE_UTF8_EDITOR:
                ctk_mem_free(OBJ_H(this), item->data.utf8_editor.content);
                ctk_mem_free(OBJ_H(this), item->data.utf8_editor.buffer);
                ctk_utf8_editor_context_p = NULL;
                break;
            case CTK_INLINE_ITEM_TYPE_EDITOR:
                ctk_mem_free(OBJ_H(this), item->data.editor.buffer);
                break;
            case CTK_INLINE_ITEM_TYPE_IP4:
                ctk_mem_free(OBJ_H(this), item->data.IP4.buffer);
                ctk_mem_free(OBJ_H(this), item->data.IP4.IP[0]);
                break;
            case CTK_INLINE_ITEM_TYPE_DISPLAY_ONLY:
                ctk_mem_free(OBJ_H(this), item->data.display_only.buffer);
                break;
            case CTK_INLINE_ITEM_TYPE_SELECT:
                ctk_mem_free(OBJ_H(this), item->data.select.list_of_options);
                break;
            default:
                break;
        }
    }

    ctk_mem_free(OBJ_H(this), this->in_items);
}


/*****************************************************************************
 * FUNCTION
 *  ctk_inline_backup_content
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_p       [IN]     
 *  lay_p       [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void ctk_inline_backup_content(ctk_screen_struct *scr_p, ctk_layout_struct *lay_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    U16 inputBufferSize;
    U8 *newInputBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetCategoryHistory(h.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();

    if (inputBufferSize + 16 > MAX_INPUT_BUFFER)    /* Exceeding MMI history limit */
    {
        newInputBuffer = ctk_mem_alloc(OBJ_H(scr_p), inputBufferSize + 16);
        GetCategory57Data(newInputBuffer);
    }
    else
    {
        GetCategory57Data((U8*) h.inputBuffer);
    }

    ctk_layout_AddNHistory(lay_p, h.guiBuffer, newInputBuffer ? newInputBuffer : h.inputBuffer, inputBufferSize);

    if (newInputBuffer)
    {
        ctk_mem_free(OBJ_H(scr_p), newInputBuffer);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ctk_inline_key_handler_wrapper
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ctk_inline_key_handler_wrapper(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();    /* finalize data input */

    ctk_screen_general_key_handler();
}

/* Typically we won't set LSK for inline layout unless  ctk_inline_enable_done was invoked */


/*****************************************************************************
 * FUNCTION
 *  ctk_inline_set_LSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  layoutid        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void ctk_inline_set_LSK(ctk_layout_handle layoutid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CTK_UNUSED(layoutid);

    /*
     * This is a dummy function, we do not set left softkey function,
     * * ctk_inline_key_handler_wrapper is invoked for left softkey only if SetCategory57LeftSoftkeyFunction
     * * is invoked in other place.
     */
    /* SetCategory57LeftSoftkeyFunction(ctk_inline_key_handler_wrapper); */
}


/*****************************************************************************
 * FUNCTION
 *  ctk_inline_set_RSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  layoutid        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void ctk_inline_set_RSK(ctk_layout_handle layoutid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CTK_UNUSED(layoutid);

    SetCategory57RightSoftkeyFunctions(ctk_inline_key_handler_wrapper, ctk_inline_general_cancel_handler);
}

/*************************************************************************
 * CTK Inline Layout - public API
 *************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  ctk_inline_create
 * DESCRIPTION
 *  
 * PARAMETERS
 *  appid       [IN]        
 *  lc          [IN]         
 * RETURNS
 *  
 *****************************************************************************/
ctk_layout_handle ctk_inline_create(ctk_app_handle appid, ctk_inline_create_struct *lc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_inline_struct *this;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(lc->in_num_items >= 1 && lc->in_num_items < CTK_INLINE_MAX_ITEMS);

    this =
        (ctk_inline_struct*) ctk_layout_create_base_object(appid, CTK_LAYOUT_TYPE_INLINE, sizeof(ctk_inline_struct));

    this->lay_show_fp = ctk_inline_show;
    this->lay_backup_content_fp = ctk_inline_backup_content;
    this->lay_close_display_fp = ctk_inline_close_display;
    this->lay_release_fp = ctk_inline_release;
    /* Note: refer to ctk_screen_add_inline_Done() */
    this->lay_set_LSK_fp = ctk_inline_set_LSK;
    this->lay_set_RSK_fp = ctk_inline_set_RSK;

    this->in_num_items = lc->in_num_items;
    this->in_highlighted = lc->in_highlighted;
    this->in_str_title = lc->in_str_title;
    this->in_img_title = lc->in_img_title;
    this->in_cancel_fp = lc->in_cancel_fp;
    this->in_disable_icons = lc->in_disable_icons ? 1 : 0;
    this->in_disable_done = lc->in_disable_done ? 1 : 0;
    this->in_set_LSK = lc->in_set_LSK ? 1 : 0;
    memset(this->in_flag_list, 0, sizeof(this->in_flag_list));
    this->in_items = (ctk_inline_item_struct*) ctk_mem_alloc(appid, sizeof(ctk_inline_item_struct) * lc->in_num_items);

    CTK_DBG_ASSERT(this->in_highlighted < this->in_num_items);

    return LAYOUT_H(this);
}

/*
 * NOTE: be sure to ctk_screen_redraw or invoke CTK screen OnEnter function.
 * Otherwise, functions like RedrawCategoryFunction might use data pointers that are already released
 */


/*****************************************************************************
 * FUNCTION
 *  ctk_inline_set_item_copy
 * DESCRIPTION
 *  
 * PARAMETERS
 *  layoutid        [IN]        
 *  index           [IN]        
 *  icon            [IN]        
 *  str_title       [IN]        
 *  type            [IN]        
 *  copy_struct     [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void ctk_inline_set_item_copy(
        ctk_layout_handle layoutid,
        int index,
        U16 icon,
        ctk_string_id str_title,
        ctk_inline_item_type_enum type,
        void *copy_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*
     * We copy the input data buffer in order to reduce the dependency of another task (e.g. WAP).
     * * MMS might be running while MMI is changing the content of the input data 
     * * As a result, the display & the data control should be separated
     */

    ctk_inline_struct *this = INLINE_T(layoutid);
    ctk_inline_item_struct *item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(IS_INLINE_LAYOUT(layoutid));
    ASSERT(copy_struct != NULL);
    ASSERT(index >= 0 && index < this->in_num_items);

    item = &(this->in_items[index]);
    item->activation = CTK_INLINE_ACTIVATION_NONE;
    this->in_icon_list[index] = icon;
    this->in_title_list[index] = str_title;

    /* We should use other function like ctk_inline_update_display_only_data instead */
    ASSERT(!item->created);

    // TODO: We do not handle the case that MMI is configured ASCII instead of Unicode
    switch (type)
    {
        case CTK_INLINE_ITEM_TYPE_CAPTION:
        {
            ctk_inline_item_caption_copy_struct *c = copy_struct;

            item->type = CTK_INLINE_ITEM_TYPE_CAPTION;
            item->data.caption.title = c->title;
        }
            break;
        case CTK_INLINE_ITEM_TYPE_SINGLE_LINE:
        {
            /* 
             * The underlying MMI requires the user to allocate buffer one more char 
             * when input type is INPUT_TYPE_PLUS_CHARACTER_HANDLING 
             * However, the length parameter need not be added by 1.
             */
            ctk_inline_item_single_line_copy_struct *c = copy_struct;
            S32 buf_size = 0;

            item->type = CTK_INLINE_ITEM_TYPE_SINGLE_LINE;
            if ((c->input_type & (~CTK_INPUT_TYPE_OVERRIDE)) ==
                CTK_INPUT_TYPE_ALPHANUMERIC_SENTENCECASE_USE_ENCODING_BASED_LENGTH)
            {
                buf_size = c->max_len + 1;
                item->data.single_line.buffer = ctk_mem_alloc(layoutid, (c->max_len + 1) * ENCODING_LENGTH);
            }
            else if ((c->input_type & (~CTK_INPUT_TYPE_OVERRIDE)) == CTK_INPUT_TYPE_PHONE_NUMBER)
            {
                buf_size = (c->max_len + 2) * ENCODING_LENGTH;
                item->data.single_line.buffer = ctk_mem_alloc(layoutid, (c->max_len + 2) * ENCODING_LENGTH);
            }
            else
            {
                buf_size = (c->max_len + 1) * ENCODING_LENGTH;
                item->data.single_line.buffer = ctk_mem_alloc(layoutid, (c->max_len + 1) * ENCODING_LENGTH);
            }
            item->data.single_line.buffer_size = (c->max_len + 1);
            item->data.single_line.input_type = ctk_convert_input_type(c->input_type) | INPUT_TYPE_ONE_LESS_CHARACTER;

            if (c->default_text)
            {
            #ifdef WAP_SUPPORT
                if (c->is_UTF8)
                {
                    /*
                     * Because we enable input_type "INPUT_TYPE_USE_ENCODING_BASED_LENGTH",
                     * the acceptable string memory size is (c->max_len+1) in bytes
                     */
                    widget_utf8_to_ucs2_string(
                        (kal_uint8*) (item->data.single_line.buffer),
                        buf_size,
                        (kal_uint8*) c->default_text);
                }
                else
            #endif /* WAP_SUPPORT */ 
                    mmi_ucs2cpy((S8*) (item->data.single_line.buffer), (S8*) c->default_text);
            }

            item->activation = c->activation;
        }
            break;

        case CTK_INLINE_ITEM_TYPE_UTF8_EDITOR:
        {
            ctk_inline_item_utf8_editor_copy_struct *c = copy_struct;
            S32 buf_size = 0;

            item->type = CTK_INLINE_ITEM_TYPE_UTF8_EDITOR;
            buf_size = c->max_len + 1;  /* bytes in UTF8 format */
            item->data.utf8_editor.content = ctk_mem_alloc(layoutid, buf_size*ENCODING_LENGTH);
            memset(item->data.utf8_editor.content, 0, buf_size);
            item->data.utf8_editor.buffer = ctk_mem_alloc(layoutid, buf_size*ENCODING_LENGTH);
            item->data.utf8_editor.buffer_size = buf_size;
            item->data.utf8_editor.input_type = ctk_convert_input_type(c->input_type) | INPUT_TYPE_ONE_LESS_CHARACTER;
            item->data.utf8_editor.str_title = c->str_title;
            item->data.utf8_editor.img_title = c->img_title;
            item->data.utf8_editor.use_input_method_menu = c->use_input_method_menu;
            if (c->default_text)
            {
            #ifdef WAP_SUPPORT
                if (c->is_UTF8)
                {
                    /*
                     * Because we enable input_type "INPUT_TYPE_USE_ENCODING_BASED_LENGTH",
                     * the acceptable string memory size is (c->max_len+1) in bytes
                     */
                    widget_utf8_to_ucs2_string(
                        (kal_uint8*) (item->data.utf8_editor.buffer),
                        buf_size,
                        (kal_uint8*) c->default_text);
                }
                else
            #endif /* WAP_SUPPORT */ 
                    mmi_ucs2cpy((S8*) (item->data.utf8_editor.buffer), (S8*) c->default_text);
            }
            item->data.utf8_editor.edit_strid = c->edit_strid;
        }
            break;
        case CTK_INLINE_ITEM_TYPE_EDITOR:
        {
            ctk_inline_item_editor_copy_struct *c = copy_struct;
            S32 buf_size = 0;

            item->type = CTK_INLINE_ITEM_TYPE_EDITOR;
            if ((c->input_type & (~CTK_INPUT_TYPE_OVERRIDE)) ==
                CTK_INPUT_TYPE_ALPHANUMERIC_SENTENCECASE_USE_ENCODING_BASED_LENGTH)
            {
                buf_size = c->max_len + 1;
                item->data.editor.buffer = ctk_mem_alloc(layoutid, (c->max_len + 1) * ENCODING_LENGTH);
            }
            else if ((c->input_type & (~CTK_INPUT_TYPE_OVERRIDE)) == CTK_INPUT_TYPE_PHONE_NUMBER)
            {
                buf_size = (c->max_len + 2) * ENCODING_LENGTH;
                item->data.editor.buffer = ctk_mem_alloc(layoutid, (c->max_len + 2) * ENCODING_LENGTH);
            }
            else
            {
                buf_size = (c->max_len + 1) * ENCODING_LENGTH;
                item->data.editor.buffer = ctk_mem_alloc(layoutid, (c->max_len + 1) * ENCODING_LENGTH);
            }
            item->data.editor.buffer_size = (c->max_len + 1);
            item->data.editor.input_type = ctk_convert_input_type(c->input_type) | INPUT_TYPE_ONE_LESS_CHARACTER;
            item->data.editor.str_title = c->str_title;
            item->data.editor.img_title = c->img_title;
            item->data.editor.use_input_method_menu = c->use_input_method_menu;
            if (c->default_text)
            {
            #ifdef WAP_SUPPORT
                if (c->is_UTF8)
                {
                    /*
                     * Because we enable input_type "INPUT_TYPE_USE_ENCODING_BASED_LENGTH",
                     * the acceptable string memory size is (c->max_len+1) in bytes
                     */
                    widget_utf8_to_ucs2_string(
                        (kal_uint8*) (item->data.editor.buffer),
                        buf_size,
                        (kal_uint8*) c->default_text);
                }
                else
            #endif /* WAP_SUPPORT */ 
                    mmi_ucs2cpy((S8*) (item->data.editor.buffer), (S8*) c->default_text);
            }

            item->activation = CTK_INLINE_ACTIVATION_LSK;   /* It's required */
        }
            break;

        case CTK_INLINE_ITEM_TYPE_IP4:
        {
            ctk_inline_item_IP4_copy_struct *c = copy_struct;

            item->type = CTK_INLINE_ITEM_TYPE_IP4;

            item->data.IP4.IP[0] = ctk_mem_alloc(layoutid, 4 * ENCODING_LENGTH * 4);
            item->data.IP4.IP[1] = ((U8*) item->data.IP4.IP[0]) + 4 * ENCODING_LENGTH;
            item->data.IP4.IP[2] = ((U8*) item->data.IP4.IP[1]) + 4 * ENCODING_LENGTH;
            item->data.IP4.IP[3] = ((U8*) item->data.IP4.IP[2]) + 4 * ENCODING_LENGTH;
            ctk_inline_IP4_print_3digit(item->data.IP4.IP[0], c->IP[0]);
            ctk_inline_IP4_print_3digit(item->data.IP4.IP[1], c->IP[1]);
            ctk_inline_IP4_print_3digit(item->data.IP4.IP[2], c->IP[2]);
            ctk_inline_IP4_print_3digit(item->data.IP4.IP[3], c->IP[3]);

            item->data.IP4.buffer = ctk_mem_alloc(layoutid, 16 * ENCODING_LENGTH);

            item->activation = CTK_INLINE_ACTIVATION_AUTO;
        }
            break;

        case CTK_INLINE_ITEM_TYPE_DISPLAY_ONLY:
        {
            /* cf. ctk_inline_update_display_only_data() */
            int text_len;
            ctk_inline_item_display_only_copy_struct *c = copy_struct;

            item->type = CTK_INLINE_ITEM_TYPE_DISPLAY_ONLY;

            if (c->text == NULL)
            {
                c->text = (U8*) ctk_empty_string;
            }

        #ifdef WAP_SUPPORT
            if (c->is_UTF8)
            {
                text_len = widget_utf8_length((kal_uint8*) c->text);
            }
            else
        #endif /* WAP_SUPPORT */ 
                text_len = widget_ucs2_length((kal_uint8*) c->text);

            item->data.display_only.buffer = ctk_mem_alloc(layoutid, (text_len + 1) * ENCODING_LENGTH);

        #ifdef WAP_SUPPORT
            if (c->is_UTF8)
            {
                widget_utf8_to_ucs2_string(
                    (kal_uint8*) (item->data.display_only.buffer),
                    (text_len + 1) * ENCODING_LENGTH,
                    (kal_uint8*) c->text);
            }
            else
        #endif /* WAP_SUPPORT */ 
                mmi_ucs2cpy((S8*) (item->data.display_only.buffer), (S8*) c->text);

            item->data.display_only.edit_fp = c->edit_fp;
            item->data.display_only.edit_strid = c->edit_strid;
            item->data.display_only.edit_imageid = c->edit_imageid;
        }
            break;
        case CTK_INLINE_ITEM_TYPE_SELECT:
        {
            int i;
            ctk_inline_item_select_copy_struct *c = copy_struct;

            CTK_DBG_ASSERT(c->highlighted >= 0 && c->highlighted < c->num_options);
            if (c->highlighted < 0 || c->highlighted >= c->num_options)
            {
                c->highlighted = 0;
            }

            item->type = CTK_INLINE_ITEM_TYPE_SELECT;
            item->data.select.num_options = c->num_options;
            item->data.select.list_of_options = ctk_mem_alloc(layoutid, c->num_options * sizeof(U8*));
            item->data.select.highlighted = c->highlighted;

            for (i = 0; i < c->num_options; i++)
            {
                this->in_items[index].data.select.list_of_options[i] = (U8*) GetString(c->list_options_strid[i]);
            }

            item->activation = CTK_INLINE_ACTIVATION_AUTO;
        }
            break;
        default:
            ASSERT(0);
    }

    /* Mark the item as created */
    item->created = KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  ctk_inline_set_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  layoutid        [IN]        
 *  index           [IN]        
 *  flags           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ctk_inline_set_flag(ctk_layout_handle layoutid, int index, ctk_inline_item_flag_t flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_inline_struct *this = INLINE_T(layoutid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(IS_INLINE_LAYOUT(layoutid));
    ASSERT(index >= 0 && index < this->in_num_items);

    this->in_flag_list[index] |= flags;
}


/*****************************************************************************
 * FUNCTION
 *  ctk_inline_unset_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  layoutid        [IN]        
 *  index           [IN]        
 *  flags           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ctk_inline_unset_flag(ctk_layout_handle layoutid, int index, ctk_inline_item_flag_t flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_inline_struct *this = INLINE_T(layoutid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(IS_INLINE_LAYOUT(layoutid));
    ASSERT(index >= 0 && index < this->in_num_items);

    this->in_flag_list[index] &= ~flags;
}


/*****************************************************************************
 * FUNCTION
 *  ctk_inline_update_display_only_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  layoutid        [IN]        
 *  index           [IN]        
 *  text            [IN]         
 *  is_UTF8         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ctk_inline_update_display_only_data(ctk_layout_handle layoutid, int index, U8 *text, kal_bool is_UTF8)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_inline_struct *this = INLINE_T(layoutid);
    ctk_inline_item_struct *item;
    int text_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(IS_INLINE_LAYOUT(layoutid));
    ASSERT(index >= 0 && index < this->in_num_items);

    item = &(this->in_items[index]);
    ASSERT(item->created && item->type == CTK_INLINE_ITEM_TYPE_DISPLAY_ONLY);

    /* Note that the original buffer is released and should not be used anymore!! */
    ctk_mem_free(layoutid, item->data.display_only.buffer);

    if (text == NULL)
    {
        text = (U8*) ctk_empty_string;
    }

#ifdef WAP_SUPPORT
    if (is_UTF8)
    {
        text_len = widget_utf8_length((kal_uint8*) text);
    }
    else
#endif /* WAP_SUPPORT */ 
        text_len = widget_ucs2_length((kal_uint8*) text);

    item->data.display_only.buffer = ctk_mem_alloc(layoutid, (text_len + 1) * ENCODING_LENGTH);

#ifdef WAP_SUPPORT
    if (is_UTF8)
    {
        widget_utf8_to_ucs2_string(
            (kal_uint8*) (item->data.display_only.buffer),
            (text_len + 1) * ENCODING_LENGTH,
            (kal_uint8*) text);
    }
    else
#endif /* WAP_SUPPORT */ 
        mmi_ucs2cpy((S8*) (item->data.display_only.buffer), (S8*) text);

    ctk_inline_set_modified(LAYOUT_H(this));
}

/* The user does not need to free the returned data by themselve */


/*****************************************************************************
 * FUNCTION
 *  ctk_inline_get_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  layoutid        [IN]        
 *  index           [IN]        
 *  type_p          [OUT]         
 *  result_p        [OUT]         
 * RETURNS
 *  void
 *****************************************************************************/
void ctk_inline_get_result(
        ctk_layout_handle layoutid,
        int index,
        ctk_inline_item_type_enum *type_p,
        ctk_inline_result_union *result_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_inline_struct *this = INLINE_T(layoutid);
    ctk_inline_item_struct *item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(IS_INLINE_LAYOUT(layoutid));
    ASSERT(index >= 0 && index < this->in_num_items);

    item = &(this->in_items[index]);
    *type_p = item->type;
    switch (item->type)
    {
        case CTK_INLINE_ITEM_TYPE_CAPTION:
        {
            CTK_DBG_ASSERT(0);
            /* do nothing */
            break;
        }
        case CTK_INLINE_ITEM_TYPE_SINGLE_LINE:
        {
            result_p->input_buffer = (char*)item->data.single_line.buffer;
            break;
        }
        case CTK_INLINE_ITEM_TYPE_IP4:
        {
            ctk_inline_IP4_contruct_hdlr(
                item->data.IP4.buffer,
                item->data.IP4.IP[0],
                item->data.IP4.IP[1],
                item->data.IP4.IP[2],
                item->data.IP4.IP[3]);
            result_p->input_buffer = (char*)item->data.IP4.buffer;
            break;
        }
        case CTK_INLINE_ITEM_TYPE_UTF8_EDITOR:
        {
            result_p->input_buffer = (char*)item->data.utf8_editor.buffer;
            break;
        }
        case CTK_INLINE_ITEM_TYPE_EDITOR:
        {
            result_p->input_buffer = (char*)item->data.editor.buffer;
            break;
        }
        case CTK_INLINE_ITEM_TYPE_SELECT:
        {
            result_p->select_highlight = item->data.select.highlighted;
            break;
        }
        default:
            ASSERT(0);
    }
}

/*
 * This function does not take effects until ctk_screen_invoke_redraw or 
 * * OnEnter callback of CTK screen is invoked 
 */


/*****************************************************************************
 * FUNCTION
 *  ctk_inline_enable_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  layoutid        [IN]        
 *  state           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ctk_inline_enable_done(ctk_layout_handle layoutid, kal_bool state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* 
     * Note that we should only DisableCategory57ScreenDone() when we are in Category57 
     * As a result, we do not invoke DisableCategory57ScreenDone() directly here.
     */
    ctk_inline_struct *this = INLINE_T(layoutid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CTK_DBG_ASSERT(IS_INLINE_LAYOUT(layoutid));
    this->in_disable_done = !state;
}


/*****************************************************************************
 * FUNCTION
 *  ctk_inline_set_modified
 * DESCRIPTION
 *  
 * PARAMETERS
 *  layoutid        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ctk_inline_set_modified(ctk_layout_handle layoutid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_inline_struct *this = INLINE_T(layoutid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CTK_DBG_ASSERT(IS_INLINE_LAYOUT(layoutid));

    /* 
     * Note that we should  not call set_wgui_inline_list_menu_changed until we are in Category57
     */
    this->in_set_modified = 1;
}

/*************************************************************************
 *
 * CTK PCategory Layout
 * ------------------
 * A category screen can be used by CTK Pcategory Layout only if:
 * 1. Only two APIs are required to manipuate it: ShowCategoryXScreen and SetCategoryXRightSoftkeyFunction (Optional)
 * 2. ...
 * Half of available MMI categories screens are supported by ctk_pcategory.
 * 
 * TODO: Support backup of input buffer into history.inputBuffer.
 *
 *************************************************************************/
#define IS_PCATEGORY_LAYOUT(h) (IS_LAYOUT(h) && LAYOUT_TYPE(h) == CTK_LAYOUT_TYPE_PCATEGORY)
#define PCATEGORY_T(p)  ((ctk_pcategory_struct*)p)

/*************************************************************************
 * CTK PCategory Layout - Internal Implementation
 *************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  ctk_pcategory_general_highlight_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void ctk_pcategory_general_highlight_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_struct *scr;
    ctk_pcategory_struct *this;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CTK_LOG("ctk_pcategory_general_highlight_handler()");

    scr = ctk_screen_get_current();
    ASSERT(scr && scr->scr_attached_layout_p);

    this = PCATEGORY_T(scr->scr_attached_layout_p);

    if (this->pcat_highlight_fp)
    {
        this->pcat_highlight_fp(SCREEN_H(scr), index);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ctk_pcategory_show
 * DESCRIPTION
 *  
 * PARAMETERS
 *  screen_p        [IN]     
 *  layout_p        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void ctk_pcategory_show(ctk_screen_struct *screen_p, ctk_layout_struct *layout_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_pcategory_struct *this = PCATEGORY_T(layout_p);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CTK_LOG_VAR((CTK_LOG_GROUP, "ctk_pcategory_show(%x)", (unsigned int)this->pcat_show_fp));

    if (this->pcat_highlight_fp)
    {
        SetParentHandler(0);
        RegisterHighlightHandler(ctk_pcategory_general_highlight_handler);
    }

    this->pcat_show_fp(LAYOUT_H(this));
}


/*****************************************************************************
 * FUNCTION
 *  ctk_pcategory_backup_content
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_p       [IN]     
 *  lay_p       [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void ctk_pcategory_backup_content(ctk_screen_struct *scr_p, ctk_layout_struct *lay_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    S16 zero = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetCategoryHistory(h.guiBuffer);
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & zero);

    ctk_layout_AddHistory(lay_p, &h);
}


/*****************************************************************************
 * FUNCTION
 *  ctk_pcategory_close_display
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_p           [IN]     
 *  layout_p        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void ctk_pcategory_close_display(ctk_screen_struct *scr_p, ctk_layout_struct *layout_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_pcategory_struct *this = PCATEGORY_T(layout_p);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CTK_UNUSED(scr_p);

    CTK_LOG("ctk_pcategory_close_display()");

    if (this->pcat_highlight_fp)
    {
        /* Failsafe. It should be already cleared in CloseCategoryFunction */
        ClearHighlightHandler();
    }
}


/*****************************************************************************
 * FUNCTION
 *  ctk_pcategory_set_RSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  layoutid        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void ctk_pcategory_set_RSK(ctk_layout_handle layoutid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_pcategory_struct *this = PCATEGORY_T(layoutid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CTK_DBG_ASSERT(IS_PCATEGORY_LAYOUT(layoutid));

    if (this->pcat_set_default_RSK_fp)
    {
        this->pcat_set_default_RSK_fp(ctk_screen_general_key_handler, KEY_EVENT_UP);
    }
    else
    {
        SetRightSoftkeyFunction(ctk_screen_general_key_handler, KEY_EVENT_UP);
    }
}

/*************************************************************************
 * CTK Pcategory Layout - public API
 *************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  ctk_pcategory_create
 * DESCRIPTION
 *  Create a new Pcategory layout object
 * PARAMETERS
 *  appid       [IN]        Target application handle
 *  pcat        [IN]        Create structure (We will not use its content after this function returns)
 * RETURNS
 *  The created layout handle
 *****************************************************************************/
ctk_layout_handle ctk_pcategory_create(ctk_app_handle appid, ctk_pcategory_create_struct *pcat)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_pcategory_struct *this;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    this =
        (ctk_pcategory_struct*) ctk_layout_create_base_object(
                                    appid,
                                    CTK_LAYOUT_TYPE_PCATEGORY,
                                    sizeof(ctk_pcategory_struct));

    this->lay_show_fp = ctk_pcategory_show;
    this->lay_backup_content_fp = ctk_pcategory_backup_content;
    this->lay_close_display_fp = NULL;
    this->lay_release_fp = NULL;
    this->lay_set_LSK_fp = ctk_layout_general_set_LSK;
    this->lay_set_RSK_fp = ctk_pcategory_set_RSK;
    this->lay_close_display_fp = ctk_pcategory_close_display;

    this->pcat_show_fp = pcat->pcat_show_fp;
    this->pcat_set_default_RSK_fp = pcat->pcat_set_default_RSK_fp;
    this->pcat_highlight_fp = pcat->pcat_highlight_fp;

    return LAYOUT_H(this);
}


/*****************************************************************************
 * FUNCTION
 *  ctk_pcategory_get_gui_buffer
 * DESCRIPTION
 *  Return the saved guiBuffer
 * PARAMETERS
 *  layoutid        [IN]        The target layout object
 * RETURNS
 *  The saved guiBuffer or NULL if no history exists.
 *****************************************************************************/
U8 *ctk_pcategory_get_gui_buffer(ctk_layout_handle layoutid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_layout_struct *this = LAYOUT_T(layoutid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CTK_DBG_ASSERT(IS_PCATEGORY_LAYOUT(layoutid));

    return this->lay_guiBuffer;
}

/*************************************************************************
 * Predefined callback functions of CTK screen
 * ---------------------------------
 * We define some common-used callback functions 
 *************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  ctk_generic_on_enter
 * DESCRIPTION
 *  Typically used as OnEnter callback handler that do nothing special
 * PARAMETERS
 *  scrid       [IN]        The target CTK screen
 * RETURNS
 *  void
 *****************************************************************************/
void ctk_generic_on_enter(ctk_screen_handle scrid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ctk_screen_enter(scrid);
}


/*****************************************************************************
 * FUNCTION
 *  ctk_generic_on_exit_pause
 * DESCRIPTION
 *  Typically used as OnExit callback handler when we want to put the target screen into MMI history.
 * PARAMETERS
 *  scrid       [IN]        The target CTK screen
 * RETURNS
 *  void
 *****************************************************************************/
void ctk_generic_on_exit_pause(ctk_screen_handle scrid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ctk_screen_exit(scrid, CTK_SCREEN_EXIT_PAUSE);
}


/*****************************************************************************
 * FUNCTION
 *  ctk_generic_on_exit_nopause
 * DESCRIPTION
 *  Typically used as OnExit callback handler when we do not want to put the target screen into
 *  MMI history.
 * PARAMETERS
 *  scrid       [IN]        The target CTK screen
 * RETURNS
 *  void
 *****************************************************************************/
void ctk_generic_on_exit_nopause(ctk_screen_handle scrid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ctk_screen_exit(scrid, CTK_SCREEN_EXIT_NOPAUSE);
}


/*****************************************************************************
 * FUNCTION
 *  ctk_generic_on_goback
 * DESCRIPTION
 *  Typically used as a key callback handler for GoBackHistory
 * PARAMETERS
 *  scrid       [IN]        The target CTK screen
 * RETURNS
 *  void
 *****************************************************************************/
void ctk_generic_on_goback(ctk_screen_handle scrid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackHistory();
}
#endif /* OBIGO_Q03C */ 

