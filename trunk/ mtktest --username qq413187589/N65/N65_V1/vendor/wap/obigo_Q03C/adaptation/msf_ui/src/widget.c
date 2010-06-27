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
 * widget.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Widget general routines
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
 * removed!
 * removed!
 * removed!
 * removed!
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

#include "msf_cfg.h"

#include "msf_def.h"
#include "msf_int.h"
#include "msf_core.h"
#include "msf_mem.h"
#include "msf_dcvt.h"
#include "msf_log.h"
#include "msf_errc.h"
#include "msf_wid.h"
#include "msf_pipe.h"
#include "msf_file.h"
#include "msf_lib.h"

#include "widget.h"
#include "msf_mem.h"
#include "wapadp.h"

#include "CallmanagementGprot.h"
#include "CallManagementStruct.h"
#include "CallStructureManagementProt.h"

#ifdef __MMI_UCM__
#include "UCMGProt.h"
#endif

/////////////////////////////////////////////////////////////////////////////////////
// global variables
/////////////////////////////////////////////////////////////////////////////////////

/* Global context */
widget_context_struct g_widget_context = {0};

// TODO: replace widget_all_keys[] with PresentAllKeys[]
U16 widget_all_keys[MAX_KEYS];

/* While wap task is processing incoming primitive */
kal_bool wap_is_busy;

stack_timer_struct widget_timer;

static jmp_buf widget_jmpbuf;
static int widget_insideRun;

static const kal_uint16 widget_data_size_table[WIDGET_MAX_TYPE] = 
{
    0,                              /* PreString */
    sizeof(widget_header_struct),   /* Root */
    /* window category */
    sizeof(widget_screen_struct),
    sizeof(widget_paintbox_struct),
    sizeof(widget_form_struct),
    sizeof(widget_dialog_struct),
    sizeof(widget_menu_struct),
    sizeof(widget_editor_struct),
    /* resource category */
    sizeof(widget_image_struct),
    sizeof(widget_style_struct),
    sizeof(widget_string_struct),
    sizeof(widget_icon_struct),
    sizeof(widget_action_struct),
    sizeof(widget_sound_struct),
    /* gadget category */
    sizeof(widget_gadget_string_struct),
    sizeof(widget_gadget_input_struct),
    sizeof(widget_gadget_select_group_struct),
    sizeof(widget_gadget_image_struct),
    sizeof(widget_gadget_date_struct),
    sizeof(widget_gadget_bar_struct),
    /* custom category */
    sizeof(widget_choice_element_struct),
    sizeof(widget_raw_data_struct),
    /* extension */
    sizeof(widget_ctk_struct)
};


void widget_pipeNotify(MSF_UINT8 modId, int fileHandle, int eventType);

extern U16 GetCmMarkerScrnID(void);

/////////////////////////////////////////////////////////////////////////////////////
// static functions
/////////////////////////////////////////////////////////////////////////////////////
static void* widget_convert (MSF_UINT8 module, MSF_UINT16 signal, void* buffer);
static void widget_destruct (MSF_UINT8 module, MSF_UINT16 signal, void* p);
static void widget_exception_handler(void);

static void widget_delete_file_poll(widget_header_struct *object);
static void widget_delete_pipe_poll(widget_header_struct *object);

/*
 * widget_init() is invoked in two cases
 * * 1. System boot
 * * 2. Out-of-memory -> restart Obigo framework
 */


/*****************************************************************************
 * FUNCTION
 *  widget_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    widget_all_keys[0] = 0xffff;

    wap_is_busy = KAL_TRUE;

    msf_mem_init(MSF_MODID_WIDGET, NULL);

#ifdef WIDGET_PROFILING
    widget_init_profiling();
#endif 
    widget_init_system();
    widget_init_message_notification();
    widget_init_ctk();
    widget_init_IPC();
    widget_init_GUI();
    widget_init_paint_input_gadget();
    widget_init_rawfile();
    widget_init_sound();
    widget_init_image();
    widget_init_font();
    widget_init_fmgr();
    widget_init_fullscreen_menu();
    widget_init_fullscreen_editor();
    widget_init_key_queue();
#ifdef WIDGET_PRECACHE_IMAGE
    widget_init_precache_image();
#endif 
#ifdef __MMI_TOUCH_SCREEN__
    widget_init_pen();
#endif 
}

/* 
 * widget_deinit() is invoked typically when Out-of-memory -> restart Obigo framework
 */


/*****************************************************************************
 * FUNCTION
 *  widget_deinit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * Call path:
     * * 1. (Typically) Shutdown WAP -> HDIa_widgetReleaseAll ->  widget_deinit
     * * 2. Out of memory -> HDIa_widgetReleaseAll  -> widget_deinit
     * *
     * * Note that we should do file operations here.
     */

    widget_deinit_sound();
    widget_deinit_image();
    widget_deinit_font();
    widget_deinit_ctk();
    widget_deinit_GUI();
    widget_deinit_fmgr();
#ifdef WIDGET_PRECACHE_IMAGE
    widget_deinit_precache_image();
#endif 
#ifdef __MMI_TOUCH_SCREEN__
    widget_deinit_pen();
#endif 
    widget_deinit_rawfile();
    widget_deinit_system();
}

/****************************************************************
 * Widget object alllocation & deallocation
 ***************************************************************/

/*****************************************************************************
 * FUNCTION
 *  widget_convert
 * DESCRIPTION
 *  Convert signals owned by the WIDGET module.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void* widget_convert (MSF_UINT8 module, MSF_UINT16 signal, void* buffer)
{
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  widget_exception_handler
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_exception_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (widget_insideRun)
    {
        longjmp(widget_jmpbuf, 1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_destruct
 * DESCRIPTION
 *  Convert signals owned by the WIDGET module.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_destruct (MSF_UINT8 module, MSF_UINT16 signal, void* p)
{
    if (p == NULL)
        return;

    MSF_MEM_FREE (module, p);
}


/*****************************************************************************
 * FUNCTION
 *  das_terminate
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_terminate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_SIGNAL_DEREGISTER_QUEUE(MSF_MODID_WIDGET);
    /* We should not free all widget module memory here because
     * widget module only handles pipe notify.
     * When terminating widget module, there should not process pipe notify.
    MSF_MEM_FREE_ALL(MSF_MODID_WIDGET);
    */
    MSF_MODULE_IS_TERMINATED(MSF_MODID_WIDGET);
    MSF_KILL_TASK(MSF_MODID_WIDGET);
    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_WIDGET, WIDGET_44E6C5BEFECD20259BC2185501907A8A, "WIDGET: Terminated\n"));
}


/*****************************************************************************
 * FUNCTION
 *  widget_receive
 * DESCRIPTION
 *  this function will be called when MSF environment send message to module JAS.
 * PARAMETERS
 *  srcModule       [IN]        
 *  signal          [IN]        
 *  p               [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void widget_receive(MSF_UINT8 srcModule, MSF_UINT16 signal, void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (signal)
    {
        case MSF_SIG_PIPE_NOTIFY:
            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_WIDGET, WIDGET_FEF3A5D9FFF1909059D75B767DE50FE8, "WIDGET: Received MSF_SIG_PIPE_NOTIFY\n"));
            widget_pipeNotify(MSF_MODID_WIDGET, ((msf_pipe_notify_t*) p)->handle, ((msf_pipe_notify_t*) p)->eventType);
            MSF_MEM_FREE(MSF_MODID_WIDGET, p);
            break;
        case MSF_SIG_MODULE_TERMINATE:
            widget_terminate();
            break;
        default:
            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_WIDGET, WIDGET_0BB94EBA4EC16058C01CD9AE0797AAE7, "WIDGET: Received unknown signal (%04x)\n", signal));
            MSF_MEM_FREE(MSF_MODID_WIDGET, p);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  WIDGETc_start
 * DESCRIPTION
 *  this function will be called when module WIDGET is initialized.
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void WIDGETc_start(void)
{
    /* widget_init */
    widget_insideRun = FALSE;
    
    MSF_MEM_INIT(MSF_MODID_WIDGET, widget_exception_handler);
    MSF_SIGNAL_REG_FUNCTIONS(MSF_MODID_WIDGET, widget_convert, widget_destruct);
    MSF_SIGNAL_REGISTER_QUEUE(MSF_MODID_WIDGET);
    MSF_MODULE_IS_CREATED(MSF_MODID_WIDGET, "WIDGET 0.1");
    MSF_MODULE_IS_ACTIVE(MSF_MODID_WIDGET);
    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_WIDGET, WIDGET_00832869EECEFCC61040851BCA8C571B, "WIDGET: Initialized\n"));
}

/*****************************************************************************
 * FUNCTION
 *  WIDGETc_wantsToRun
 * DESCRIPTION
 *  this function will be called when MSF environment want to known module jas have something to do or not.
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
int WIDGETc_wantsToRun(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (MSF_SIGNAL_QUEUE_LENGTH(MSF_MODID_WIDGET) > 0);
}


/*****************************************************************************
 * FUNCTION
 *  WIDGETc_run
 * DESCRIPTION
 *  this function will be called when module WIDGET want process something.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void WIDGETc_run(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (setjmp(widget_jmpbuf) == 0)
    {
        widget_insideRun = TRUE;

        while (MSF_SIGNAL_RETRIEVE(MSF_MODID_WIDGET, widget_receive));

        widget_insideRun = FALSE;
    }
    else
    {
        /*
         * A longjmp from das_exception_handler. If we are here there is no more
         * * memory, and the situation could not be worse.
         * * Send out an error and terminate.
         */
        MSF_ERROR(MSF_MODID_WIDGET, MSF_ERR_SYSTEM_FATAL);
        MSF_PIPE_CLOSE_ALL(MSF_MODID_WIDGET);
        MSF_FILE_CLOSE_ALL(MSF_MODID_WIDGET);
        MSF_WIDGET_RELEASE_ALL(MSF_MODID_WIDGET);
        MSF_MEM_FREE_ALL(MSF_MODID_WIDGET);
        MSF_MODULE_IS_TERMINATED(MSF_MODID_WIDGET);
        MSF_SIGNAL_DEREGISTER_QUEUE(MSF_MODID_WIDGET);
        MSF_KILL_TASK(MSF_MODID_WIDGET);
    }
}


/*****************************************************************************
 * FUNCTION
 *  WIDGETc_kill
 * DESCRIPTION
 *  this function will be called MSF environment want terminate WIDGET module.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void WIDGETc_kill(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_PIPE_CLOSE_ALL(MSF_MODID_WIDGET);
    MSF_FILE_CLOSE_ALL(MSF_MODID_WIDGET);
    MSF_WIDGET_RELEASE_ALL(MSF_MODID_WIDGET);
    MSF_MEM_FREE_ALL(MSF_MODID_WIDGET);
    MSF_KILL_TASK(MSF_MODID_WIDGET);
}


/*****************************************************************************
 * FUNCTION
 *  widget_malloc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId           [IN]        
 *  type            [IN]        
 *  extra_size      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
widget_header_struct *widget_malloc(MSF_UINT8 modId, widget_data_type_enum type, int extra_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_header_struct *w;
    int size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* detect size */
    size = widget_data_size_table[type];
    size += extra_size;

    /* allocate the memory */
#ifdef WIDGET_MALLOC_IN_OWNER_MODULE
    w = (widget_header_struct*) widget_malloc_mem(modId, size);
#else 
    w = (widget_header_struct*) widget_malloc_mem(size);
#endif 

#ifdef WIDGET_PROFILING
    WPROF_CTX->malloc_counter++;
    WPROF_CTX->malloc_counter_by_type[type]++;
    WPROF_CTX->malloc_size_by_type[type] += size;
    WPROF_CTX->current_memory_usage += size;
    if (WPROF_CTX->max_memory_usage < WPROF_CTX->current_memory_usage)
    {
        WPROF_CTX->max_memory_usage = WPROF_CTX->current_memory_usage;
    }
#endif /* WIDGET_PROFILING */ 

    memset(w, 0, size);

    /* initialize the struct member */
    w->data_type = type;

    /* default reference count is 1 */
    INC_REF(w);

    /* assign the default flag */
    switch (type)
    {
            /* case WIDGET_DIALOG_INPUT_TYPE: */
        case WIDGET_CHOICE_ELEMENT_TYPE:
        case WIDGET_RAW_DATA_TYPE:
            w->flag |= WIDGET_FLAG_INTERNAL;
            DEC_REF(w);                     /* should attach one place, and free automatic */
            break;
        case WIDGET_GADGET_STRING_TYPE:
        case WIDGET_GADGET_INPUT_TYPE:
        case WIDGET_GADGET_SELECT_GROUP_TYPE:
        case WIDGET_GADGET_IMAGE_TYPE:
        case WIDGET_GADGET_DATE_TYPE:
        case WIDGET_GADGET_BAR_TYPE:
            w->flag |= WIDGET_FLAG_GADGET;  /* the gadget is also the window */
            w->flag |= WIDGET_FLAG_WINDOW;
            break;
        case WIDGET_SCREEN_TYPE:
            DEC_REF(w);                     /* should attach one place, and free automatic */
            break;
        case WIDGET_PAINTBOX_TYPE:
        case WIDGET_FORM_TYPE:
        case WIDGET_DIALOG_TYPE:
        case WIDGET_MENU_TYPE:
        case WIDGET_EDITOR_TYPE:
            w->flag |= WIDGET_FLAG_WINDOW;
            break;
        case WIDGET_CTK_TYPE:  // * Extension of MsfWindow */
            w->flag |= WIDGET_FLAG_WINDOW;
            break;
        case WIDGET_IMAGE_TYPE:
        case WIDGET_STYLE_TYPE:
        case WIDGET_STRING_TYPE:
        case WIDGET_ICON_TYPE:
        case WIDGET_SOUND_TYPE:
            w->flag |= WIDGET_FLAG_RESOURCE;
            break;
        case WIDGET_ACTION_TYPE:
            w->flag |= WIDGET_FLAG_RESOURCE;
            break;
        default:
            WAP_DBG_ASSERT(0);
    }
    /* If it is automatically free()-ed , might cause double free */
    /*
     * if(type == WIDGET_STYLE_TYPE)
     * {
     * DEC_REF(w);
     * }
     */

    /* insert into free list */
    {
        WAP_VERBOSE_ASSERT(HDIa_getModuleID() == modId);
        if (WSYS_CTX->free_obj_list[modId] != NULL)
        {
            w->next_memory_block = WSYS_CTX->free_obj_list[modId];
        }
        WSYS_CTX->free_obj_list[modId] = w;
        w->module_id = modId;
    }
    return w;
}

/*
 * Data referenced by widget_header_struct.childs was (will be) released in HDIa_widgetReleaseAll or HDIa_widgetRelease.
 */


/*****************************************************************************
 * FUNCTION
 *  widget_free
 * DESCRIPTION
 *  
 * PARAMETERS
 *  w       [?]     
 * RETURNS
 *  
 *****************************************************************************/
kal_bool widget_free(widget_header_struct *w)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;

    kal_uint8 module_id = HDIa_getModuleID();
    kal_uint8 from_begin = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // TODO: check if w is MsfWindow, then it should be removed from the screen first.

    /* Reference: widget_init_GUI() */

    if (w == (widget_header_struct*) WGUI_CTX->current_screen)
    {
        WGUI_CTX->current_screen = NULL;
    }
    if (w == (widget_header_struct*) WGUI_CTX->current_window)
    {
        WGUI_CTX->current_window = NULL;
    }
    /* Menu key events might be processed before widget_paint_hdlr but after HDIa_widgetRelease */
    if (w == (widget_header_struct*) WGUI_CTX->current_menu)
    {
        WGUI_CTX->current_menu = NULL;
    }
    if (w == (widget_header_struct*) WGUI_CTX->current_vertical_scrollbar)
    {
        WGUI_CTX->current_vertical_scrollbar = NULL;
    }
    if (w == (widget_header_struct*) WGUI_CTX->current_horizontal_scrollbar)
    {
        WGUI_CTX->current_horizontal_scrollbar = NULL;
    }
    if (w == (widget_header_struct*) WGUI_CTX->current_focused_gadget)
    {
        WGUI_CTX->current_focused_gadget = NULL;
    }
    if (w == (widget_header_struct*) WGUI_CTX->current_focused_paintbox)
    {
        WGUI_CTX->in_paintbox = 0;
        WGUI_CTX->current_focused_paintbox = NULL;
    }
    if (w == (widget_header_struct*) WGUI_CTX->current_dialog)
    {
        WGUI_CTX->current_dialog = NULL;
    }

    // TODO: Move some of the following code to HDIa_widgetSetInFocus & HDIa_widgetRemove
    if (IS_GADGET_TYPE(w))
    {
        widget_stop_paint_gadget_command(w);
    }

    if (IS_GADGET_STRING_TYPE(w))
    {
        widget_remove_blinking(_GSTR(w));
    }

#ifdef WIDGET_STRING_GET_VISIBLE_USE_CACHE
    if (IS_STRING_TYPE(w))
    {
        /* Applications should use HDIa_widgetExtStringClearCacheGetVisible() explicitly before releasing MsfString */
        WAP_DBG_ASSERT((MsfStringHandle) w != WFONT_CTX->cache_string);
        widget_release_get_visible_cache_by_string((MsfStringHandle) w);
    }
#endif /* WIDGET_STRING_GET_VISIBLE_USE_CACHE */ 

    if (IS_ACCESSKEY_TYPE(w))
    {
        /* We should not use widget_free() on MsfAccesskey objects */
        WAP_DBG_ASSERT(0);
    }

    if (IS_GADGET_IMAGE_TYPE(w))
    {
        widget_remove_marquee(_GIMG(w));
    }

    if (IS_FORM_TYPE(w))
    {
    #ifdef WIDGET_SLIDING_SMIL_SUPPORT
        widget_form_remove_sliding_info(_FORM(w));
    #endif 
    }

    if (IS_IMAGE_TYPE(w) || IS_SOUND_TYPE(w))
    {
        /*
         * sometimes pipe notifications on image/audio are invoked
         * after objects are already released
         */
        widget_delete_pipe_poll(_H(w));
        widget_delete_file_poll(_H(w));
    }

    if (IS_IMAGE_TYPE(w))
    {
        widget_image_release(_IMG(w));
    }

    if (IS_SOUND_TYPE(w))
    {
        widget_sound_release(_SND(w));
    }

    if (IS_WINDOW_GADGET_TYPE(w) || IS_SCREEN_TYPE(w))
    {
        widget_delete_accesskey_by_window((MSF_UINT32) w);
    }

#ifdef __MMI_TOUCH_SCREEN__
    widget_MMI_remove_pen_handler_if_necessary(w);
#endif 

    if (IS_SCREEN_TYPE(w))      // TODO: replace it with HDIa_widgetRemove
    {
        int cnt;

        widget_index_childs(cnt, &WGUI_CTX->widget_root, w);
        if (cnt >= 0)
        {

            for (i = cnt + 1; i < WGUI_CTX->widget_root.childs_sum; i++)
            {
                WGUI_CTX->widget_root.childs[i - 1] = WGUI_CTX->widget_root.childs[i];
            }
            WGUI_CTX->widget_root.childs[i - 1] = NULL;
            WGUI_CTX->widget_root.childs_sum--;
            if (WGUI_CTX->widget_root.childs_sum > 0)
            {
                widget_header_struct *screen, *window;

                widget_get_active_childs(screen, &WGUI_CTX->widget_root);
                if (screen)
                {
                    /* Set focus to the previous screen */
                    HDIa_widgetSetInFocus((MSF_UINT32) screen, 1);
                    widget_get_active_childs(window, screen);
                    if (window)
                    {
                        HDIa_widgetSetInFocus((MSF_UINT32) window, 1);
                    }
                }
            }
        }
    }
    else if (IS_WINDOW_TYPE(w)) // TODO: replace it with HDIa_widgetRemove
    {
        int cnt;
        widget_screen_struct *screen = _SCREEN(w->parent);

        if (screen)
        {
            widget_index_childs(cnt, screen, w);
            if (cnt >= 0)
            {

                for (i = cnt + 1; i < screen->childs_sum; i++)
                {
                    screen->childs[i - 1] = screen->childs[i];
                }
                screen->childs[i - 1] = NULL;
                screen->childs_sum--;
            }
        }
    }

    if (IS_CTK_TYPE(w))
    {
        widget_release_ctk_data(_CTK(w));
    }

    // TODO: should we do this in HDIa_widgetRemove
    if (IS_MENU_TYPE(w) || IS_GADGET_SELECT_GROUP_TYPE(w))
    {
        if (WGUI_CTX->is_widget_screen) // TODO: check widget_is_window_gadget_displayed
        {
            gui_fixed_icontext_list_menuitem_stop_scroll();
            gui_fixed_icontext_menuitem_stop_scroll();
            gui_fixed_twostate_menuitem_stop_scroll();
        }

        if (w == _H(WENTER_MENU_CTX->target_menu))
        {
            widget_goback_to_widget_screen();
            widget_init_fullscreen_menu();
        }
    }

    if (IS_EDITOR_TYPE(w) || IS_GADGET_INPUT_TYPE(w))
    {
        widget_leave_fullscreen_editor_screen_if_present(_H(w));
    }

    for (i = module_id; i < MSF_NUMBER_OF_MODULES; i++)
    {
        widget_header_struct *node, *prev_node;

        if (from_begin && i == module_id)
        {
            continue;
        }

        for (prev_node = NULL, node = WSYS_CTX->free_obj_list[i]; node; node = node->next_memory_block)
        {
            if (node == w)  /* free this widget */
            {
                if (prev_node)
                {
                    prev_node->next_memory_block = node->next_memory_block;
                }
                else
                {
                    WSYS_CTX->free_obj_list[i] = node->next_memory_block;
                }

            #ifdef WIDGET_MALLOC_IN_OWNER_MODULE
                if (node->childs)
                {
                    widget_free_mem(node->module_id, node->childs);
                }
                widget_free_mem(node->module_id, node);
            #else /* WIDGET_MALLOC_IN_OWNER_MODULE */ 
                if (node->childs)
                {
                    widget_free_mem(node->childs);
                }
                widget_free_mem(node);
            #endif /* WIDGET_MALLOC_IN_OWNER_MODULE */ 

            #ifdef WIDGET_PROFILING
                WPROF_CTX->malloc_counter--;
                WPROF_CTX->malloc_counter_by_type[node->data_type]--;
                WPROF_CTX->malloc_size_by_type[node->data_type] -= widget_data_size_table[node->data_type];
                WPROF_CTX->current_memory_usage -= widget_data_size_table[node->data_type];
                if (node->data_type == WIDGET_RAW_DATA_TYPE)
                {
                    WPROF_CTX->current_memory_usage -= _RAW(node)->size;
                    WPROF_CTX->malloc_size_by_type[node->data_type] -= _RAW(node)->size;
                }
            #endif /* WIDGET_PROFILING */ 

                /*
                 * Test duplicated releasing. We do this immediately after widget_free_mem
                 * * because no MSF_MEM_ALLOC is allowed before this.
                 * * Functions like HDIa_fileRemove will allocate memory.
                 */
                _H(w)->data_type = WIDGET_MAX_TYPE;
                return KAL_TRUE;
            }
            prev_node = node;
        }
        if (!from_begin)
        {
            from_begin = 1;
            i = 0;
            continue;
        }
    }
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  widget_check_object_validity
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [?]     
 * RETURNS
 *  
 *****************************************************************************/
kal_bool widget_check_object_validity(widget_header_struct *handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (handle && handle->data_type < (kal_uint8) WIDGET_MAX_TYPE)
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
 *  widget_release_all
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_release_all(MSF_UINT8 modId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (WSYS_CTX->free_obj_list[modId])
    {
        NO_REF(WSYS_CTX->free_obj_list[modId]);
        widget_free(WSYS_CTX->free_obj_list[modId]);
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_dump_memory_usage
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_dump_memory_usage(void)
{
#ifndef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    widget_header_struct *node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MSF_NUMBER_OF_MODULES; i++)
        if ((node = WSYS_CTX->free_obj_list[i]))
        {
            while (node)
            {
                widget_show_info(node);
                node = node->next_memory_block;
            }
        }
#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  widget_notify
 * DESCRIPTION
 *  
 * PARAMETERS
 *  h           [?]         
 *  type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_notify(widget_header_struct *h, MsfNotificationType type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool is_legal = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (h)
    {
        if (IS_SCREEN_TYPE(h))
        {
            if (_SCREEN(h)->property_mask & MSF_WINDOW_PROPERTY_NOTIFY)
                if (type == MsfNotifyFocus || type == MsfNotifyLostFocus)
                {
                    is_legal = KAL_TRUE;
                }
        }
        else if (IS_WINDOW_TYPE(h))
        {
            if (_WINDOW(h)->property_mask & MSF_WINDOW_PROPERTY_NOTIFY)
            {
                is_legal = KAL_TRUE;
            }
        }
        else if (IS_GADGET_TYPE(h))
        {
            if (_WINDOW(h)->property_mask & MSF_GADGET_PROPERTY_NOTIFY)
            {
                is_legal = KAL_TRUE;
            }

            /* Otherwise, it may cause infinite loop in BRS paintbox containing a input gadget  */
            //if(type != MsfNotifyFocus && type != MsfNotifyLostFocus) 
            //     is_legal = KAL_TRUE;
        }
    }

    if (is_legal)
    {
        /*
         * Assume a dialog on a empty homepage disappears, 
         * * and then the paintbox is focused. we need to repaint it.
         * * Otherwise it won't repaint because it contains no window
         * *
         * * FIXME. solve it in a more graceful way
         */
        //if(type==MsfNotifyStateChange)
        // widget_clear(&WGUI_CTX->display_size,&WGUI_CTX->display_pos);

        HDIc_widgetNotify(h->module_id, (MSF_UINT32) h, type);
    }
}

/****************************************************************
 * RAW DATA
 ***************************************************************/


/*****************************************************************************
 * FUNCTION
 *  widget_create_raw_data_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  module_id       [IN]        
 *  size            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
widget_raw_data_struct *widget_create_raw_data_ext(kal_uint8 module_id, int size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_raw_data_struct *raw = widget_create_raw_data(module_id, size);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    raw->module_id = module_id;
    raw->size = size;
    raw->used_size = 0;
    return raw;
}


/*****************************************************************************
 * FUNCTION
 *  widget_set_raw_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  raw         [?]         
 *  src         [IN]        
 *  length      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_set_raw_data(widget_raw_data_struct *raw, const void *src, int length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (src)
    {
        memcpy(raw->data, src, length);
    }
}

/****************************************************************
 * Resouce callback function
 ***************************************************************/


/*****************************************************************************
 * FUNCTION
 *  widget_fileNotify
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId           [IN]        
 *  fileHandle      [IN]        
 *  eventType       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_fileNotify(MSF_UINT8 modId, int fileHandle, int eventType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (eventType != HDI_FILE_READ_READY)
    {
        WAP_DBG_ASSERT(0);  /* We do not expect this */
        HDIa_fileClose(fileHandle);
        return;
    }
    for (i = 0; i < WSYS_CTX->fn_sum; i++)
    {
        if (WSYS_CTX->fn_handle[i] == fileHandle)
        {
            int ret = WIDGET_READ_ERROR;

            switch (WSYS_CTX->fn_data[i]->data_type)
            {
                case WIDGET_IMAGE_TYPE:
                    ret = widget_read_image_from_file(
                            WSYS_CTX->fn_handle[i],
                            WSYS_CTX->fn_size[i],
                            _IMG(WSYS_CTX->fn_data[i]),
                            KAL_FALSE,
                            KAL_FALSE);
                    break;
                case WIDGET_SOUND_TYPE:
                    ret = widget_read_sound_from_file(
                            WSYS_CTX->fn_handle[i],
                            WSYS_CTX->fn_size[i],
                            _SND(WSYS_CTX->fn_data[i]),
                            KAL_FALSE,
                            KAL_FALSE);
                    break;
                default:
                    ASSERT(0);
            }
            switch (ret)
            {
                case WIDGET_WAIT_SELECT:
                    return;
                case WIDGET_READ_FINISH:
                case WIDGET_READ_ERROR:
                    /* FALLTHROUGH */ ;
            }
            HDIa_fileClose(WSYS_CTX->fn_handle[i]);

            WSYS_CTX->fn_handle[i] = WSYS_CTX->fn_handle[WSYS_CTX->fn_sum - 1];
            WSYS_CTX->fn_data[i] = WSYS_CTX->fn_data[WSYS_CTX->fn_sum - 1];
            WSYS_CTX->fn_size[i] = WSYS_CTX->fn_size[WSYS_CTX->fn_sum - 1];
            WSYS_CTX->fn_sum--;
            return;
        }
    }
    /* fileHandle not in map */
    WAP_DBG_ASSERT(0);  /* not real error */
    HDIa_fileClose(fileHandle);
}


/*****************************************************************************
 * FUNCTION
 *  widget_delete_file_poll
 * DESCRIPTION
 *  
 * PARAMETERS
 *  object      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_delete_file_poll(widget_header_struct *object)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < WSYS_CTX->fn_sum; i++)
    {
        if (WSYS_CTX->fn_data[i] == object)
        {
            /* After the file is closed, no more notification will be delivered. */
            HDIa_fileClose(WSYS_CTX->fn_handle[i]);
            WSYS_CTX->fn_handle[i] = WSYS_CTX->fn_handle[WSYS_CTX->fn_sum - 1];
            WSYS_CTX->fn_data[i] = WSYS_CTX->fn_data[WSYS_CTX->fn_sum - 1];
            WSYS_CTX->fn_size[i] = WSYS_CTX->fn_size[WSYS_CTX->fn_sum - 1];
            WSYS_CTX->fn_sum--;
            return;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_add_file_poll
 * DESCRIPTION
 *  
 * PARAMETERS
 *  f           [IN]        
 *  object      [?]         
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_add_file_poll(int f, widget_header_struct *object, int size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Restart WAP if lacking resource */
    WAP_RST_ASSERT(WSYS_CTX->fn_sum < MAX_WIDGET_FILE_NOTIFY_SUM);
    WSYS_CTX->fn_handle[WSYS_CTX->fn_sum] = f;
    WSYS_CTX->fn_data[WSYS_CTX->fn_sum] = object;
    WSYS_CTX->fn_size[WSYS_CTX->fn_sum] = size;
    WSYS_CTX->fn_sum++;
}


/*****************************************************************************
 * FUNCTION
 *  widget_file_close_all
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_file_close_all()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* UNIFINISHED */
}


/*****************************************************************************
 * FUNCTION
 *  widget_pipe_notify_delay_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  arg             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static int g_widget_sound_pipe_cnt = 0;
void widget_pipe_notify_delay_hdlr(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_widget_sound_pipe_cnt = 0;
    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_WIDGET, WIDGET_D8C08608F7F677C43E08F30CC150A941, "WIDGET: widget_pipe_notify_delay_hdlr\n"));
    HDIc_pipeNotify(MSF_MODID_WIDGET, WSYS_CTX->pn_delay_handle[(int)arg], WSYS_CTX->pn_delay_eventType[(int)arg]);
    WSYS_CTX->pn_delay_handle[(int)arg] = 0;
    WSYS_CTX->pn_delay_eventType[(int)arg] = 0;
}


/*****************************************************************************
 * FUNCTION
 *  widget_pipeNotify
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId           [IN]        
 *  fileHandle      [IN]        
 *  eventType       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_pipeNotify(MSF_UINT8 modId, int fileHandle, int eventType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < WSYS_CTX->pn_sum; i++)
    {
        if (WSYS_CTX->pn_handle[i] == fileHandle)
        {
            int ret = WIDGET_READ_ERROR;

            switch (WSYS_CTX->pn_data[i]->data_type)
            {
                case WIDGET_IMAGE_TYPE:
                    ret = widget_read_image_from_pipe(WSYS_CTX->pn_handle[i], _IMG(WSYS_CTX->pn_data[i]), KAL_FALSE);
                    break;
                case WIDGET_SOUND_TYPE:
                    {
                        g_widget_sound_pipe_cnt++;
                        if (g_widget_sound_pipe_cnt >= WIDGET_PIPE_DELAY_COUNTER && WSYS_CTX->pn_delay_handle[WSYS_CTX->pn_delay_cnt] == 0)
                        {
                            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_WIDGET, WIDGET_97EEF0C2F57322DFC2D082C22DCC70A5, "WIDGET: Start timer to avoid MMI starving\n"));
                            WSYS_CTX->pn_delay_handle[WSYS_CTX->pn_delay_cnt] = fileHandle;
                            WSYS_CTX->pn_delay_eventType[WSYS_CTX->pn_delay_cnt] = eventType;
                            widget_start_timer(WIDGET_PIPE_NOTIFY_DELAY_TIMER, widget_pipe_notify_delay_hdlr, (void*)(WSYS_CTX->pn_delay_cnt), WIDGET_PIPE_NOTIFY_DELAY_TIME);
                            WSYS_CTX->pn_delay_cnt++;
                            if (WSYS_CTX->pn_delay_cnt == MAX_WIDGET_PIPE_NOTIFY_SUM/2)
                            {
                                WSYS_CTX->pn_delay_cnt = 0;
                            }
                            return;
                        }
                        ret = widget_read_sound_from_pipe(WSYS_CTX->pn_handle[i], _SND(WSYS_CTX->pn_data[i]), KAL_FALSE);
                    }
                    break;
                default:
                    ASSERT(0);
            }
            switch (ret)
            {
                case WIDGET_WAIT_SELECT:
                    return;
                case WIDGET_READ_FINISH:
                case WIDGET_READ_ERROR:
                    /* FALLTHROUGH */ ;
            }
            HDIa_pipeDeleteByHandle(WSYS_CTX->pn_handle[i]);
            WSYS_CTX->pn_handle[i] = WSYS_CTX->pn_handle[WSYS_CTX->pn_sum - 1];
            WSYS_CTX->pn_data[i] = WSYS_CTX->pn_data[WSYS_CTX->pn_sum - 1];
            WSYS_CTX->pn_sum--;
            return;
        }
    }

    /* This pipe is ignored, act as a dummy reader */
    switch (eventType)
    {
        case HDI_PIPE_EVENT_CLOSED:
            HDIa_pipeDeleteByHandle(fileHandle);
            return;
        case HDI_PIPE_EVENT_WRITE:
            return; /* should not go here ? */
    }

    /* HDI_PIPE_EVENT_READ */
    for (;;)
    {
        int is_open;
        long size;
        char tmpbuf[64];

        if (HDIa_pipeStatus(fileHandle, &is_open, &size) == HDI_PIPE_ERROR_BAD_HANDLE)
        {
            return;
        }

        if (!is_open)
        {
            HDIa_pipeDeleteByHandle(fileHandle);
            return;
        }
        if (size == 0)
        {
            HDIa_pipePoll(fileHandle);
            return;
        }
        HDIa_pipeRead(fileHandle, tmpbuf, 64);
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_delete_pipe_poll
 * DESCRIPTION
 *  
 * PARAMETERS
 *  object      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_delete_pipe_poll(widget_header_struct *object)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* sometimes we want to ignore a pipe */
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < WSYS_CTX->pn_sum; i++)
    {
        if (WSYS_CTX->pn_data[i] == object)
        {
            /*
             * We cannot delete the pipe (HDIa_pipeDeleteByHandle) here because 
             * * the writer (e.g. BRS) might not handle the case HDIa_pipeWrite return FALSE,
             * * and it might not delete the pipe correctly. (TODO: check if this can happen )
             * * (This is different from widget_delete_file_poll())
             * * As a resut, we leave the pipe open, and left widget_pipeNotify() act as
             * * a dummy reader to read all left data.
             */
            WSYS_CTX->pn_handle[i] = WSYS_CTX->pn_handle[WSYS_CTX->pn_sum - 1];
            WSYS_CTX->pn_data[i] = WSYS_CTX->pn_data[WSYS_CTX->pn_sum - 1];
            WSYS_CTX->pn_sum--;
            /* to avoid continue to read the data */
            HDIa_pipeDeleteByHandle(WSYS_CTX->pn_handle[i]);
            return;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_add_pipe_poll
 * DESCRIPTION
 *  
 * PARAMETERS
 *  f           [IN]        
 *  object      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void widget_add_pipe_poll(int f, widget_header_struct *object)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Restart WAP if lacking resource */
    WAP_RST_ASSERT(WSYS_CTX->pn_sum < MAX_WIDGET_PIPE_NOTIFY_SUM);
    WSYS_CTX->pn_handle[WSYS_CTX->pn_sum] = f;
    WSYS_CTX->pn_data[WSYS_CTX->pn_sum] = object;
    WSYS_CTX->pn_sum++;
}


/*****************************************************************************
 * FUNCTION
 *  widget_pipe_close_all
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_pipe_close_all()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* UNIFINISHED */
}

/****************************************************************
 * Widget Timer
 ***************************************************************/


/*****************************************************************************
 * FUNCTION
 *  widget_start_base_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  base_timer_ptr      [?]         
 *  time_out            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_start_base_timer(void *base_timer_ptr, unsigned int time_out)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stack_start_timer((stack_timer_struct*) base_timer_ptr, 0, time_out);
}


/*****************************************************************************
 * FUNCTION
 *  widget_stop_base_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  base_timer_ptr      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_stop_base_timer(void *base_timer_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stack_stop_timer((stack_timer_struct*) base_timer_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  widget_timer_callback_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  arg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_timer_callback_handler(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int timer = (int)arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WSYS_CTX->event_timers[timer].id = 0;
    WSYS_CTX->event_timers[timer].callback(WSYS_CTX->event_timers[timer].callback_arg);
}


/*****************************************************************************
 * FUNCTION
 *  widget_start_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  timer           [IN]        
 *  func            [IN]        
 *  func_arg        [?]         
 *  msec            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_start_timer(int timer, widget_timer_func func, void *func_arg, unsigned long msec)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (timer == WIDGET_MMS_VIEWER_SCROLL_TIMER)
    {
        /* Pending the timer until no scrolling */
        widget_stop_timer(timer);
    }

    /*
     * It is not enough to stop old timer here because the timer expiry message might be already enqueued.
     * * In worst case, it might make the queue full. 
     */
    if (WSYS_CTX->event_timers[timer].id)
    {
        return;
    }

    msec /= 100;
    if (msec == 0)
    {
        msec = 1;
    }

    WSYS_CTX->event_timers[timer].callback = func;
    WSYS_CTX->event_timers[timer].callback_arg = func_arg;

    WSYS_CTX->event_timers[timer].id = evshed_set_event(
                                        WSYS_CTX->scheduler,
                                        (kal_timer_func_ptr) widget_timer_callback_handler,
                                        (void*)timer,
                                        msec * KAL_TICKS_100_MSEC);
}


/*****************************************************************************
 * FUNCTION
 *  widget_stop_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  timer       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_stop_timer(int timer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (WSYS_CTX->event_timers[timer].id)   /* to prevent duplicated stop  */
    {
        evshed_cancel_event(WSYS_CTX->scheduler, &(WSYS_CTX->event_timers[timer].id));
        WSYS_CTX->event_timers[timer].id = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_timer_expiry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void widget_timer_expiry(ilm_struct *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (stack_is_time_out_valid(&widget_timer))
    {
        evshed_timer_handler(WSYS_CTX->scheduler);
    }

    stack_process_time_out(&widget_timer);
}


/*****************************************************************************
 * FUNCTION
 *  widget_init_system
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_init_system(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Create base timer */

    if(WSYS_CTX->scheduler == NULL)
    {
        stack_init_timer(&widget_timer, "WIDGET_TIMER", MOD_WAP);

        /* create event scheduler */
        WSYS_CTX->scheduler = new_evshed(
                                &widget_timer,
                                widget_start_base_timer,
                                widget_stop_base_timer,
                                0,
                                kal_evshed_get_mem,
                                kal_evshed_free_mem,
                                0);
    }
    memset(WSYS_CTX->event_timers, 0, sizeof(WSYS_CTX->event_timers));

    memset(WSYS_CTX->free_obj_list, 0, sizeof(WSYS_CTX->free_obj_list));

    WSYS_CTX->fn_sum = 0;
    WSYS_CTX->pn_sum = 0;
}


/*****************************************************************************
 * FUNCTION
 *  widget_deinit_system
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_deinit_system(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    evshed_delete_all_events(WSYS_CTX->scheduler);
    
    stack_stop_timer(&widget_timer);
}

/****************************************************************
 * Profiling
 ***************************************************************/

#ifdef WIDGET_PROFILING


/*****************************************************************************
 * FUNCTION
 *  widget_init_profiling
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_init_profiling(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WPROF_CTX->cnt_try_paint = 0;
    WPROF_CTX->cnt_paint = 0;
    WPROF_CTX->malloc_counter = 0;
    memset(WPROF_CTX->malloc_counter_by_type, 0, sizeof(WPROF_CTX->malloc_counter_by_type));
    memset(WPROF_CTX->malloc_size_by_type, 0, sizeof(WPROF_CTX->malloc_size_by_type));
    WPROF_CTX->current_memory_usage = 0;
    WPROF_CTX->max_memory_usage = 0;
}
#endif /* WIDGET_PROFILING */ 

/****************************************************************
 * Widget Memory
 ***************************************************************/

/* Used to allocate widget_header_struct* and widget_header_struct.childs */

#ifdef WIDGET_MALLOC_IN_OWNER_MODULE
void *widget_malloc_mem(MSF_UINT8 modId, int size)
#else 
void *widget_malloc_mem(int size)
#endif 
{

#ifdef USING_WINDOWS_MALLOC
    return malloc(size);
#endif 
#ifdef USING_CONTROL_BUFFER
    return get_ctrl_buffer(size);
#endif 
#ifdef USING_OBIGO_MALLOC
    void *pointer;

#ifdef WIDGET_MALLOC_IN_OWNER_MODULE
    pointer = MSF_MEM_ALLOC(modId, size);
#else 
    pointer = MSF_MEM_ALLOC(MSF_MODID_WIDGET, size);
#endif 

    ASSERT(pointer != NULL);

    return pointer;
#endif /* USING_OBIGO_MALLOC */ 
}

#ifdef WIDGET_MALLOC_IN_OWNER_MODULE
void widget_free_mem(MSF_UINT8 modId, void *pointer)
#else 
void widget_free_mem(void *pointer)
#endif 
{
#ifdef USING_WINDOWS_MALLOC
    free(pointer);
#endif 
#ifdef USING_CONTROL_BUFFER
    free_ctrl_buffer(pointer);
#endif 
#ifdef USING_OBIGO_MALLOC
#ifdef WIDGET_MALLOC_IN_OWNER_MODULE
    MSF_MEM_FREE(modId, pointer);
#else 
    MSF_MEM_FREE(MSF_MODID_WIDGET, pointer);
#endif 
#endif /* USING_OBIGO_MALLOC */ 
}

/****************************************************************
 * External queue
 ***************************************************************/
// TODO: redirect action/user event via external queue, and then we will not need wap_is_busy

#include "kal_release.h"

/*
 * We do not accept key event when we are "NOT" waiting external queues 
 * * Otherwise, the action/user event might be put in internal queue in unexpected way.
 */


/*****************************************************************************
 * FUNCTION
 *  widget_waiting_external_queue
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_waiting_external_queue(void)
{
#ifdef WIDGET_TMPFIX_DYNAMIC_LIST
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (WIPC_CTX->extq_mutex_locked_by_WAP)
    {
        WIPC_CTX->extq_mutex_locked_by_WAP = 0;
        kal_give_mutex(WIPC_CTX->WAP_extq_mutex);
    }
#endif /* WIDGET_TMPFIX_DYNAMIC_LIST */ 

#ifdef __MMI_TOUCH_SCREEN__
    widget_pen_on_post_msf_fsm();
#endif 

    wap_is_busy = KAL_FALSE;

    if (WKEY_CTX->is_processing_key)
    {
        WKEY_CTX->is_processing_key = 0;
        if (WKEY_CTX->last_process_time == 0)
        {
            kal_get_time(&WKEY_CTX->last_process_time);
        }
    }

    if (WIPC_CTX->is_executing_RPC)
    {
        if (WIPC_CTX->RPC_finish_callback)
        {
            WIPC_CTX->RPC_finish_callback();
        }

        WIPC_CTX->is_executing_RPC = 0;
        WIPC_CTX->RPC_finish_callback = NULL;
    }

}


/*****************************************************************************
 * FUNCTION
 *  widget_finish_external_queue
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_finish_external_queue(void)
{
#ifdef WIDGET_TMPFIX_DYNAMIC_LIST
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * This is very tricky and will be removed after new dynamic list is ready.
     * *
     * * 1. WAP is blocked here only if the mutex is already taken by callback of dynamic list.
     * *  Otherwise, WIPC_CTX->WAP_is_waiting is reset to zero immediately.
     * * 2. Take lock after receive_msg_ext_q() instead of "before receive_msg_ext_q" to prevent starvation.
     * * 3. We do not set WIPC_CTX->WAP_is_waiting because it is difficult to handle widget_execute_MMI
     * *
     */

    /* WIPC_CTX->WAP_is_waiting = 1; */
    if (WIPC_CTX->MMI_try_to_lock_extq_mutex)
    {
        /* Prevent starvation of MMI */
        kal_sleep_task(5);
    }
    kal_take_mutex(WIPC_CTX->WAP_extq_mutex);
    /* WIPC_CTX->WAP_is_waiting = 0; */

    ASSERT(!WIPC_CTX->extq_mutex_locked_by_MMI);
    WIPC_CTX->extq_mutex_locked_by_WAP = 1;
#endif /* WIDGET_TMPFIX_DYNAMIC_LIST */ 

    wap_is_busy = KAL_TRUE;

    WKEY_CTX->is_processing_key = 0;
    WIPC_CTX->is_executing_RPC = 0;
    WIPC_CTX->RPC_finish_callback = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  widget_check_is_incoming_call
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool widget_check_is_incoming_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UCM__
    return (kal_bool)((mmi_ucm_app_total_call(MMI_UCM_CALL_TYPE_ALL) == 0 && IsScreenPresent(GetCmMarkerScrnID())) ||
                      isIncomingCall());
#else 
    return (kal_bool)(!isInCall() && IsScreenPresent(GetCmMarkerScrnID()) ||
                      GetIncomingCallHandle() != -1);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  widget_check_is_in_call
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool widget_check_is_in_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UCM__
    return (kal_bool)(mmi_ucm_app_total_call(MMI_UCM_CALL_TYPE_ALL) > 0);
#else 
    return (kal_bool)isInCall();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  widget_check_is_in_non_wap_call
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool widget_check_is_in_non_wap_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UCM__
    return (kal_bool)(mmi_ucm_app_total_call(MMI_UCM_CALL_TYPE_NO_CSD) > 0);
#else 
    return (kal_bool)(isInCall() && !GetWapCallPresent());
#endif
}


/*****************************************************************************
 * FUNCTION
 *  widget_check_no_call_or_wap_call
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool widget_check_no_call_or_wap_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UCM__
    return (kal_bool)(mmi_ucm_app_total_call(MMI_UCM_CALL_TYPE_ALL) == 0 ||
//                      mmi_ucm_app_total_call(MMI_UCM_CSD_CALL_TYPE_ALL) == mmi_ucm_app_total_call(MMI_UCM_CALL_TYPE_ALL));
                      mmi_ucm_app_total_call(MMI_UCM_CSD_CALL_TYPE_ALL) > 0);
#else 
    return (kal_bool)(!isInCall() || (isInCall() && GetWapCallPresent()));
#endif
}





