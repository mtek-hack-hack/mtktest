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
 * widget_ctk.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Integration of CTK and widget
 *
 * Author:
 * -------
 * -------
*
*==============================================================================
*           HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * $Log$
 *
 * removed!
 * removed!
 * Need to check widget_image_cache_buf first when invoking widget_ctk_show_image_from_cached_buffer()
 *
 * removed!
 * removed!
 * add more trace for debugging
 *
 * removed!
 * removed!
 * fix the bug in widget_ctk_show_progress_bar()
 *
 * removed!
 * removed!
 * fix the layout in widget_MMI_ctk_show_smil_editor_draw_title() (right to left style)
 *
 * removed!
 * removed!
 * fix the bug when draw resource image in MMS editor
 *
 * removed!
 * removed!
 * fix MMS smil editor layout problem in landscape project
 *
 * removed!
 * removed!
 * fix the compile error
 *
 * removed!
 * removed!
 * adjust the position of str title2 in MMS editor
 *
 * removed!
 * removed!
 * need to cache the image when entering MMS SMIL editor
 *
 * removed!
 * removed!
 * add more trace
 *
 * removed!
 * removed!
 * fix the compile error
 *
 * removed!
 * removed!
 * fix the bug of non-blocking image drawing
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * fix the bug in nb_draw_image_callback
 *
 * removed!
 * removed!
 * check in new feature
 *
 * removed!
 * removed!
 * check in new feature
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * revise the code for 240x400 resolution
 *
 * removed!
 * removed!
 * adjust the title string2 in MMS editor
 *
 * removed!
 * removed!
 * revise widget trace
 *
 * removed!
 * removed!
 * revise WIDGET_LOG_VAR API
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * revise the mechanism of widget draw the image in non-blocking
 *
 * removed!
 * removed!
 * add to source control recursely
 *
 * removed!
 * removed!
 * Implement widget supports non-blocking image drawing (stage 1)
 *
 * removed!
 * removed!
 * Implement widget supports non-blocking image drawing (stage 1)
 *
 * removed!
 * removed!
 * Implement widget supports non-blocking image drawing (stage 1)
 *
 * removed!
 * removed!
 * Adjust the MMS size information position in MMS editor
 *
 * removed!
 * removed!
 * Check in for landscape (320X240)
 *
 * removed!
 * removed!
 * Modify ASM usage in MMS SMIL editor (only use screen-based memory)
 *
 * removed!
 * removed!
 * add new API HDIa_widgetExtCreateTextViewNoScrollBar()
 *
 * removed!
 * removed!
 * Add new feature for operator request (think title, scrollbar indication button)
 *
 * removed!
 * removed!
 * Add new API - HDIa_widgetExtSmilEditorChangeSlide()
 *
 * removed!
 * removed!
 * modify the last param in ShowCategory402Screen()
 *
 * removed!
 * removed!
 * Change SMIL editor input method behavior
 *
 * removed!
 * removed!
 * Fix the compile error
 *
 * removed!
 * removed!
 * revise the function HDIa_widgetExtSmilEditorInsetText() to avoid update the screen content
 *
 * removed!
 * removed!
 * modify the function HDIa_widgetExtSmilEditorCheckModified()
 *
 * removed!
 * removed!
 * adjust the image/video preview layout in MMS SMIL editor (consider r2lMMIFlag)
 *
 * removed!
 * removed!
 * add new API HDIa_widgetExtSmilEditorInsetText() for MMS editor to insert the string
 *
 * removed!
 * removed!
 * fix the bug that the image frame of SMIL editor in right-to-left style
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * fix the compile error
 *
 * removed!
 * removed!
 * Use application-base or screen-base memory manager to allocate the buffer for SMIL editor's image cache
 *
 * removed!
 * removed!
 * after the image resizing, the width or height should not be 0
 *
 * removed!
 * removed!
 * Reset the background color of CTK SMIL editor image cache
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * add new API ctk_screen_is_back_history() to fix the bug
 *
 * removed!
 * removed!
 * Use the Category402Screen in widget ctk progress view.
 *
 * removed!
 * removed!
 * reset context->is_video in HDIa_widgetExtSmilEditorUpdateImage()
 *
 * removed!
 * removed!
 * add new API for setting video preview image in SMIL editor
 *
 * removed!
 * removed!
 * clear gdi layer before draw the image
 *
 * removed!
 * removed!
 * add new state for controling widget video
 *
 * removed!
 * removed!
 * The memory mechanism of CTK service can't use HDIa_mem... because there are some bugs in MMS code
 *
 * removed!
 * removed!
 * widget_ctk use WAP memory mechanism
 *
 * removed!
 * removed!
 * modify MMS wcache mechanism
 *
 * removed!
 * removed!
 * Fix the bug. (It also has the problem on the target)
 *
 * removed!
 * removed!
 * Modify MMS viewer layout
 *
 * removed!
 * removed!
 * fix the bug
 *
 * removed!
 * removed!
 * adjust the ctk smil editor layout
 *
 * removed!
 * removed!
 * revise the code for the strange situation
 *
 * removed!
 * removed!
 * fix ctk SMIL editor layout bug
 *
 * removed!
 * removed!
 * fix ctk SMIL editor layout bug
 *
 * removed!
 * removed!
 * wrap the compiler option for MDI API
 *
 * removed!
 * removed!
 * consider the layout in 128X128 and 128X160
 *
 * removed!
 * removed!
 * add new feature - video MMS
 *
 * removed!
 * removed!
 * set the gdi_layer_source key
 *
 * removed!
 * removed!
 * Adjust the SMIL editor title in 128x128 and 128x160 (using small font)
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * Fix the code of the compile option APPMEM_SUPPORT
 *
 * removed!
 * removed!
 * Use APPMEM_SUPPORT to distinguish the feature
 *
 * removed!
 * removed!
 * Have to define APPMEM_SUPPORT then include "kal_release.h"
 *
 * removed!
 * removed!
 * Change the image cache to use ASM
 *
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/

/* 
 * MMI/widget/CTK interaction
 *
 * Symbols:
 * W Typical MsfWindow
 * M MMI
 * C  CTK
 * + set focus
 * - lose focus
 * | adjacent in history
 *
 * ---------------
 * Four original state:
 * 1.    W
 * 2.    W|C
 * 3.    W|M
 * 4.    W|C|M
 * ---------------
 * Possible subsequent actions:
 * + W
 * + C
 * - W
 * - C
 * + M (no special handling requierd)
 * - M (no special handling required)
 * ---------------
 * Scenarios related to CTK:
 * Case 1:
 * W + C = (W | C)
 *
 * Case 2:
 * W |C + W = W
 * W |C1 + C2 = W | C2
 * W |C - C = W
 * 
 * Case 3:
 * W|M + C = W(C)|M        (pending display of C until widget_paint_hdlr() )
 *
 * Case 4:
 * W |C |M + W = W | M        (history node of C is deleted)
 * W |C1 |M + C2 = W (C2) | M (history node of C1 is deleted, pending display of C2 until widget_paint_hdlr() )
 * W |C |M -C = W | M         (history node of C is deleted)
 *
 * ---------------
 *
 * We handle this by:
 * 1. widget_ctk_leave_screen_if_present(NULL) when the active window is changed
 * 2. widget_paint_ctk
 * 3. widget_prepare_to_enter_ctk_window
 *
 */

/* 
 * Termination of widget screen
 *
 * Principle: 
 * ctk_screen_close must be in two states: 
 * 1. CTK_SCREEN_STATE_LAYOUT_ATTACHED 
 * 2. CTK_SCREEN_STATE_CREATED
 * instead of CTK_SCREEN_STATE_ACTIVE!
 *
 * And we might relase a widget CTK window by
 *
 * 1. HDIa_widgetReleaseAll -> widget_free -> widget_ctk_release_data -> ctk_screen_close
 *  (Out-of-memory or module termination)
 * 2. HDIa_widgetRelease -> widget_free -> widget_ctk_release_data -> ctk_screen_close
 *
 */

/*
 * TODO:
 * 1. WAP closing (END)
 * 2. abonormal case like out-of-memory
 */
#include "widget.h"
#include "ctk.h"
#include "../applib/mem/include/app_mem.h"
#include "../applib/misc/include/app_str.h"
#include "ScrMemMgrGprot.h"
#include "wgui_status_icons.h"
#include "wgui_categories.h"
#include "wgui_categories_inputs.h"
#include "wgui_categories_MMS.h"
#include "SATDefs.h"    /* for SAT_WAIT_IMAGE_ID */
#include "messages/messagesinc/MessagesResourceData.h"  /* for IMG_NEW_SMS_SEND */
#include "gpio/gpioInc/GPIOInc.h"       /* Backlight */
#include "CommonScreens.h"
#include "lcd_sw_rnd.h"
#include "gdi_include.h"
#include "gd_primitive.h"

#include "widget_ctk.h"

#include "mdi_datatype.h"
#include "mdi_camera.h"
#include "mdi_video.h"

#ifndef __MED_MEM_POOL__
#define __MED_MEM_POOL__
#endif
#ifdef __MED_MEM_POOL__
#include "..\..\media\common\include\med_utility.h"
#endif

/*****************************************************************************
 * Global variables
 *****************************************************************************/

/*
 * widget_current_ctk - The CTK screen on top of widget screen (no matter it is suspended by another MMI screen or not)
 * There will be atmost one CTK screen that is on top of widget screen.
 * It might be in one of these states: 
 * o WIDGET_CTK_STATE_ENTERED
 * o WIDGET_CTK_STATE_PAUSED
 * (WIDGET_CTK_STATE_NONE & WIDGET_CTK_STATE_PREPARE_TO_ENTER are invalid states)
 *
 * widget_current_ctk is set in WAP instead of MMI, Two places will set it
 * 1. widget_paint_ctk (When focus is on CTK, and widget_paint it)
 * 2. widget_ctk_leave_screen_if_present (when focus is switched, i.e. MSF_WIDGET_REMOVE & MSF_WIDGET_SET_IN_FOCUS)
 */
static widget_ctk_struct *widget_current_ctk;

/* ctk application of WAP */
static ctk_app_handle widget_ctk_appid;

static const U8 widget_ctk_empty_string[2] = {0, 0};

/* CTK SMIL editor image cache buffer pointer */
#ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING
U8 g_widget_image_cache_buf[(GDI_LCD_WIDTH*GDI_LCD_HEIGHT*GDI_MAINLCD_BIT_PER_PIXEL>>3)];
#else
U8 *g_widget_image_cache_buf = NULL;
#endif /* #if defined(WIDGET_PRECACHE_IMAGE) && !defined(__GDI_MEMORY_PROFILE_2__) */
static gdi_handle g_widget_ctk_se_image_cache_layer = 0;

#ifdef WIDGET_SMIL_EDITOR_ICON_IN_INFO_BAR
extern void wgui_redraw_input_information_bar(void);
extern void wgui_redraw_remaining_characters_display(void);
#endif

#ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING
extern S32 widget_query_index_of_nb_image_array(S32 img_width, S32 img_height, widget_gadget_image_struct *gimg);
#define WIDGET_IMAGE_WIDTH_LIMITATION       (176)
#define WIDGET_IMAGE_HEIGHT_LIMITATION      (220)

typedef struct
{
    gdi_handle handle;
    kal_bool   image_in_top;
    S32        clip_x1;
    S32        clip_y1;
    S32        clip_x2;
    S32        clip_y2;
    S32        x;
    S32        y;
    S32        width;
    S32        height;
    
}widget_ctk_smil_nb_image_struct;

static widget_ctk_smil_nb_image_struct widget_ctk_nb_image = {0};

static void widget_ctk_show_image_from_cached_buffer(S32 x_offset, S32 y_offset, S32 width, S32 height, const U8 *buffer_ptr);
#endif /* #ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING */


#define WIDGET_CTK_SET_EMPTY_STR(_str) (_str=(kal_uint8*)widget_ctk_empty_string)
#define WIDGET_CTK_IS_EMPTY_STR(_str)  (_str==widget_ctk_empty_string)


extern pBOOL mmi_bootup_is_idle_screen_reached(void);

/*****************************************************************************
 * FUNCTION
 *  widget_ctk_malloc
 * DESCRIPTION
 *  Initialize the adaptation to CTK
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *widget_ctk_malloc(int size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (void*)HDIa_memAlloc(MSF_MODID_WIDGET, size);
}


/*****************************************************************************
 * FUNCTION
 *  widget_ctk_mfree
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p       [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void widget_ctk_mfree(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    HDIa_memFree(MSF_MODID_WIDGET, p);
}


/*****************************************************************************
 * FUNCTION
 *  widget_init_ctk
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_init_ctk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_app_create_struct app_create;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CTK_INIT_STRUCT(app_create);
    strncpy(app_create.app_name, "widget", CTK_APP_NAME_LEN + 1);
    app_create.app_name[CTK_APP_NAME_LEN] = '\0';
    app_create.app_taskid = MOD_WAP;
    /*
     * The memory mechanism of CTK service can't use HDIa_mem... 
     * because there are some bugs in MMS code
     *
     app_create.app_mem_alloc_fp = widget_ctk_malloc;
     app_create.app_mem_free_fp = widget_ctk_mfree;
     */
    app_create.app_rpc_MMI_void_fp = widget_execute_MMI;
    app_create.app_rpc_UA_void_fp = widget_execute_WAP;
    app_create.app_rpc_MMI_handle_fp = (ctk_rpc_handle) widget_execute_MMI_i;   /* Assume ctk_object_handle is interger-type */
    app_create.app_rpc_UA_handle_fp = (ctk_rpc_handle) widget_execute_WAP_i;

    widget_ctk_appid = ctk_app_create(&app_create);

    widget_current_ctk = NULL;
    if (mmi_bootup_is_idle_screen_reached())
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_INIT_CTK, widget_ctk_appid);
    }

}


/*****************************************************************************
 * FUNCTION
 *  widget_deinit_ctk
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_deinit_ctk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(widget_ctk_appid);
    ctk_app_close(widget_ctk_appid);
    widget_ctk_appid = 0;
    if (mmi_bootup_is_idle_screen_reached())
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_DEINIT_CTK, widget_ctk_appid);
    }

}


/*****************************************************************************
 * FUNCTION
 *  widget_current_ctk_state
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
widget_ctk_state_enum widget_current_ctk_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* If widget_current_ctk != NULL, it must be WIDGET_CTK_STATE_ENTERED or WIDGET_CTK_STATE_PAUSED */
    if (widget_current_ctk == NULL)
    {
        return WIDGET_CTK_STATE_NONE;
    }
    else
    {
        return widget_current_ctk->ctk_state;
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_current_ctk_MMI_screen_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
ctk_MMI_screen_id widget_current_ctk_MMI_screen_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (widget_current_ctk == NULL)
    {
        return 0;
    }
    else
    {
        WAP_DBG_ASSERT(widget_current_ctk->ctk_state == WIDGET_CTK_STATE_ENTERED ||
                       widget_current_ctk->ctk_state == WIDGET_CTK_STATE_PAUSED);
        return ctk_screen_get_MMI_screen_id(widget_current_ctk->ctk_screen);
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_release_ctk_data
 * DESCRIPTION
 *  release CTK data
 * PARAMETERS
 *  ctk     [IN]     The target MsfWindow containg CTK screen
 * RETURNS
 *  void
 *****************************************************************************/
void widget_release_ctk_data(widget_ctk_struct *ctk)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* widget_ctk_leave_screen_if_present should be invoked before this point */
    if (ctk == widget_current_ctk)
    {
        /* If this happens, setting widget_current_ctk as NULL does not solve it */
        WAP_DBG_ASSERT(0);
        widget_current_ctk = NULL;
    }
    ctk_screen_close(ctk->ctk_screen);
}


/*****************************************************************************
 * FUNCTION
 *  widget_prepare_to_enter_ctk_window
 * DESCRIPTION
 *  Used when the CTK window is focused (it might not be in widget_screen)
 * PARAMETERS
 *  ctk     [IN]     The target MsfWindow containg CTK screen
 * RETURNS
 *  void
 *****************************************************************************/
void widget_prepare_to_enter_ctk_window(widget_ctk_struct *ctk)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Wait until widget_paint_hdlr */

    if (ctk->ctk_state == WIDGET_CTK_STATE_NONE)
    {
        /* 
         * Note that we do not set widget_current_ctk here, but in widget_paint_ctk instead.
         * Because it doesn't guarentee to be in widget screen here, and the last CTK screen 
         * might still be active
         */
        ctk->ctk_state = WIDGET_CTK_STATE_PREPARE_TO_ENTER;
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_paint_ctk
 * DESCRIPTION
 *  Go to the CTK screen if the window is just focused
 * PARAMETERS
 *  ctk     [IN]     The target MsfWindow containg CTK screen
 * RETURNS
 *  void
 *****************************************************************************/
void widget_paint_ctk(widget_ctk_struct *ctk)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 
     * After leaving CTK screen and go back to widget screen, ctk->ctk_state will be WIDGET_CTK_STATE_NONE
     * We should not paint it, but do nothing until the focus is changed to another window!!
     * This guarenteed synchronization between different CTK screens
     */
    if (ctk->ctk_state == WIDGET_CTK_STATE_PREPARE_TO_ENTER)
    {
        WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());

        /* We are in MMI task, ctk_screen_enter is not invoked by RPC */
        ctk_screen_invoke_on_enter(ctk->ctk_screen);
        WAP_DBG_ASSERT(!WGUI_CTX->is_widget_screen);

        /*
         * Althogh we will set the state in widget_ctk_on_enter(), 
         * * we still set it here to prevent enter CTK screen again
         */
        WAP_DBG_ASSERT(ctk->ctk_state == WIDGET_CTK_STATE_ENTERED);
        ctk->ctk_state = WIDGET_CTK_STATE_ENTERED;      // TODO: we should remove this line
        ctk->idlescreen_seq_no = WIPC_CTX->idlescreen_seq_no;

        WAP_DBG_ASSERT(widget_current_ctk == NULL);
        widget_current_ctk = ctk;
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_PAINT_CTK, widget_current_ctk);
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_ctk_leave_screen_if_present
 * DESCRIPTION
 *  Leave the current CTK screen (if any)
 *  1. If it is active, leave it
 *  2. If it is interrupted by another MMI screen, delete the history node
 * PARAMETERS
 *  arg     [IN]     
 *  to_remove_handle the target MsfWindow or NULL for delete any active target window(?)
 *  to_remove_modId the target module ID or -1 for delete any active target window(?)
 * RETURNS
 *  void
 * REMARKS
 *  Typically WAP already defocus or release a MsfCtkWindow object, and we need to remove
 *  the corresponding MMI screen (active or in history). Otherwise, MMI might display a CTK
 *  screen with invalid MsfCtkWindow object.
 *****************************************************************************/
typedef struct
{
    widget_header_struct *to_remove_handle;
    int to_remove_modId;
} widget_ctk_leave_screen_param_struct;

static void widget_MMI_ctk_leave_screen_if_present(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_ctk_leave_screen_param_struct *param = (widget_ctk_leave_screen_param_struct*) arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_CTK_LEAVE_SCREEN_IF_PRESENT);

    /*
     * Tmp fix.  Although this should not happen, but ctk_screen_general_key_handler is executed in 
     * * MMI task and it might invoke MSF_WIDGET_SET_IN_FOCUS in MMI task 
     * * (which also invokes widget_ctk_leave_screen_if_present), and when MMI task received  RPC 
     * * request, widget_current_ctk might be already changed.
     */
    if (widget_current_ctk == NULL)
    {
        WAP_DBG_ASSERT(0);
        return;
    }

    if (param->to_remove_handle != NULL)
    {
        if (param->to_remove_handle != _H(widget_current_ctk))
        {
            WAP_DBG_ASSERT(0);
            return;
        }
    }
    else if (param->to_remove_modId >= 0)
    {
        if (widget_current_ctk->module_id != (kal_uint8) param->to_remove_modId)
        {
            WAP_DBG_ASSERT(0);
            return;
        }
    }

    switch (widget_current_ctk->ctk_state)
    {
        case WIDGET_CTK_STATE_ENTERED:
            ASSERT(!WGUI_CTX->is_widget_screen);
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_CTK_LEAVE_SCREEN_IF_PRESENT_ENTERED);

            if (IsScreenPresent(WAP_SCREEN_WIDGET))
            {
                GoBackToHistory(WAP_SCREEN_WIDGET);
            }
            else
            {
                WAP_DBG_ASSERT(0);
                GoBackHistory();
            }
            /* Otherwise, it might press End key in widget CTK screen */
            break;

        case WIDGET_CTK_STATE_PAUSED:
            /* 
             * We should not remove the new MMI screen that interrupts the CTK screen.
             * Instead, when the new MMI screen exits, it go back to widget directly.
             *
             * FIXME. There is still a race condition here that the new MMI screen exits 
             * before we call in ctk_screen_remove_from_history
             */
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_CTK_LEAVE_SCREEN_IF_PRESENT_PAUSED);
            DeleteScreenIfPresent(ctk_screen_get_MMI_screen_id(widget_current_ctk->ctk_screen));

            widget_current_ctk->ctk_state = WIDGET_CTK_STATE_NONE;
            break;

        default:
            EXT_ASSERT(0, (kal_uint32) widget_current_ctk->ctk_state, (kal_uint32) widget_current_ctk, 0);
    }

    widget_current_ctk = NULL;  /* Prevent from being invoked more than one time */
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_CTK_LEAVE_SCREEN_IF_PRESENT_END);
}


/*****************************************************************************
 * FUNCTION
 *  widget_ctk_leave_screen_if_present
 * DESCRIPTION
 *  
 * PARAMETERS
 *  to_remove_handle        [IN]         
 *  to_remove_modId         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_ctk_leave_screen_if_present(widget_header_struct *to_remove_handle, int to_remove_modId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_ctk_leave_screen_param_struct param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_CTK_LEAVE_IF_PRESENT, to_remove_handle, to_remove_modId);

    WAP_DBG_ASSERT(widget_ctk_appid);

    if (widget_current_ctk == NULL)
    {
        return;
    }

    if (to_remove_handle != NULL)
    {
        if (to_remove_handle != _H(widget_current_ctk))
        {
            return;
        }
    }
    else if (to_remove_modId >= 0)
    {
        if (widget_current_ctk->module_id != (kal_uint8) to_remove_modId)
        {
            return;
        }
    }

    /* 
     * We need to handle End key and idle screen specially.
     * 
     * In EntryIdleScreen(), MMI task invoke widget_MMI_on_enter_idle_screen() 
     * and widget_MMI_check_and_display_new_msg() respectively, which both wait
     * WAP task in blocking mode. As a result, we should avoid widget_execute_MMI_xxx() 
     * in idle screen to avoid deadlock.
     * 
     * Assume that history is as follows:
     * 1. MMI screen
     * 2. CTK screen
     * 3. widget screen 
     * 
     * widget_current_ctk != NULL after user press End key and returns to idle screen. 
     *
     */
    if (_CTK(widget_current_ctk)->idlescreen_seq_no != WIPC_CTX->idlescreen_seq_no)
    {
        /* The screen does not exist in history after user returns to idle screen. */
        widget_current_ctk->ctk_state = WIDGET_CTK_STATE_NONE;
        widget_current_ctk = NULL;
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_CTK_LEAVE_IF_PRESENT_RETURN_TO_IDLE);
        return;
    }

    param.to_remove_handle = to_remove_handle;
    param.to_remove_modId = to_remove_modId;

    if (WIPC_CTX->MMI_is_waiting)   /* Typically BRA/MEA UI shutdown in idle screen */
    {
        widget_MMI_ctk_leave_screen_if_present(&param);
    }
    else
    {
        widget_execute_MMI_p(widget_MMI_ctk_leave_screen_if_present, &param, KAL_TRUE);
    }
}

/*****************************************************************************
 * Callback functions 
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  widget_ctk_on_enter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrid       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_ctk_on_enter(ctk_screen_handle scrid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_ctk_struct *ctk;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ctk = (widget_ctk_struct*) ctk_screen_get_msf_window(scrid);
    ASSERT(ctk);

    ctk->ctk_state = WIDGET_CTK_STATE_ENTERED;  /* Maybe paused before */
    ctk_screen_enter(scrid);

    if (ctk->on_post_paint)
    {
        ctk->on_post_paint();
    }
#ifdef WIDGET_TEST_OUT_OF_MEMORY
    SetKeyHandler(widget_simulate_out_of_memory, KEY_POUND, KEY_EVENT_UP);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  widget_ctk_on_pre_paint
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrid       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_ctk_on_pre_paint(ctk_screen_handle scrid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_ctk_struct *ctk;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ctk = (widget_ctk_struct*) ctk_screen_get_msf_window(scrid);
    ASSERT(ctk);

    if (ctk->ctk_flag & WIDGET_CTK_FLAG_DISABLE_SLIM_MENU_STYLE)
    {
        wgui_override_list_menu_slim_style(WGUI_LIST_MENU_SLIM_STYLE_DRAW_ICON);
    }
#ifdef __MMI_WAP_MMS_NUMERIC_LIST_ICON__
    else
    {
        wgui_override_list_menu_slim_style(WGUI_LIST_MENU_SLIM_STYLE_NUMBER);
    }
#endif /* __MMI_WAP_MMS_NUMERIC_LIST_ICON__ */ 

    if (ctk->ctk_flag & WIDGET_CTK_FLAG_BACKLIGHT_ALWAYS_ON)
    {
        TurnOnBacklight(0);
    }

    widget_setup_security_icon();
}


/*****************************************************************************
 * FUNCTION
 *  widget_ctk_on_exit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrid       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_ctk_on_exit(ctk_screen_handle scrid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*
     * Two case here
     * 1. overriden by another MMI screen
     * 2. invoked from wap_entry_widget_screen()
     */

    widget_ctk_struct *ctk = (widget_ctk_struct*) ctk_screen_get_msf_window(scrid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_CTK_ON_EXIT);

    ASSERT(ctk);
    WAP_DBG_ASSERT(ctk == widget_current_ctk);

#ifdef __MMI_WAP_MMS_NUMERIC_LIST_ICON__
    wgui_restore_list_menu_slim_style();
#else /* __MMI_WAP_MMS_NUMERIC_LIST_ICON__ */ 
    if (ctk->ctk_flag & WIDGET_CTK_FLAG_DISABLE_SLIM_MENU_STYLE)
    {
        wgui_restore_list_menu_slim_style();
    }
#endif /* __MMI_WAP_MMS_NUMERIC_LIST_ICON__ */ 

    if (ctk->ctk_flag & WIDGET_CTK_FLAG_BACKLIGHT_ALWAYS_ON)
    {
        TurnOffBacklight();
    }
    if (ctk->ctk_flag & WIDGET_CTK_SMIL_EDITOR_USING_SCRN_MEM)
    {
        /* If SMIL editor use screen-base memory, we need to free the memory when exit the screen. */
    #ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING
        if (widget_ctk_nb_image.handle)
        {
            gdi_image_nb_stop (widget_ctk_nb_image.handle);
        }
        memset(&widget_ctk_nb_image, 0, sizeof(widget_ctk_smil_nb_image_struct));
        /* When stop non-blocking image drawing, we need to unlock the status bar rendering */
    #endif /* #ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING */

        if (g_widget_ctk_se_image_cache_layer)
        {
            gdi_layer_free(g_widget_ctk_se_image_cache_layer);
        }
        g_widget_ctk_se_image_cache_layer = 0;

	#ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING
        /*
         * We don't need to release g_widget_image_cache_buf,
         * it use the global buffer g_widget_cache_nb_buf[]
         */
    #else
        if (g_widget_image_cache_buf != NULL)
        {
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_CTK_SMIL_FREE_SCRMEM);
            mmi_frm_scrmem_free((void*)g_widget_image_cache_buf);
        }
        g_widget_image_cache_buf = NULL;
    #endif /* #if defined(WIDGET_PRECACHE_IMAGE) && !defined(__GDI_MEMORY_PROFILE_2__) */
        HDIa_widgetCtkUnsetFlag((MsfWindowHandle)ctk, WIDGET_CTK_SMIL_EDITOR_USING_SCRN_MEM);
    }

    widget_reset_security_icon();

    if (WGUI_CTX->is_entering_widget_screen)
    {
        /*
         * Returning to the widget screen, we do not put the CTK screen into history
         * This *should* be invoked from widget_ctk_leave_screen_if_present()
         * 
         * We don't reset widget_current_ctk here because we assume widget_ctk_leave_screen_if_present
         * should be invoked!
         */
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_CTK_ON_EXIT_BACK_TO_WIDGET_SCREEN);

        ctk_screen_exit(scrid, CTK_SCREEN_EXIT_PAUSE_NOT_IN_HISTORY);

        ctk->ctk_state = WIDGET_CTK_STATE_NONE;
    }
    else
    {
        /*
         * Interrupted by another MMI screen
         */
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_CTK_ON_EXIT_INTERRUPT);

        ctk_screen_exit(scrid, CTK_SCREEN_EXIT_PAUSE);

        ctk->ctk_state = WIDGET_CTK_STATE_PAUSED;
    }
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetCtkGetWindow
 * DESCRIPTION
 *  Get the MsfWindow handle corresponding to the CTK screen handle
 * PARAMETERS
 *  scrid       [IN]        
 * RETURNS
 *  MsfWindow handle
 *****************************************************************************/
MsfWindowHandle HDIa_widgetCtkGetWindow(ctk_screen_handle scrid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (MsfWindowHandle) ctk_screen_get_msf_window(scrid);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetCtkGetScreenHandle
 * DESCRIPTION
 *  Get the ctk screen handle corresponding to the MsfWindow
 * PARAMETERS
 *  wnd     [IN]        
 * RETURNS
 *  MsfWindow handle
 *****************************************************************************/
ctk_screen_handle HDIa_widgetCtkGetScreenHandle(MsfWindowHandle wnd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return _CTK(wnd)->ctk_screen;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetCtkGetApp
 * DESCRIPTION
 *  CTK application handle is needed to create CTK screen/layout
 * PARAMETERS
 *  void
 * RETURNS
 *  the handle to the CTK application handle of WAP
 *****************************************************************************/
ctk_app_handle HDIa_widgetCtkGetApp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(widget_ctk_appid);
    return widget_ctk_appid;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetCtkCreate
 * DESCRIPTION
 *  modId   -  The current module ID
 *  scrid -  previously created CTK screen handle
 * PARAMETERS
 *  modId       [IN]        
 *  scrid       [IN]        
 * RETURNS
 *  return the handle to the created MsfWindow
 *****************************************************************************/
MsfWindowHandle HDIa_widgetCtkCreate(MSF_UINT8 modId, ctk_screen_handle scrid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_ctk_struct *w = widget_create_ctk(modId);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    w->module_id = modId;
    w->size = WGUI_CTX->default_display_size;
    w->ctk_screen = scrid;
    w->ctk_state = WIDGET_CTK_STATE_NONE;
    w->idlescreen_seq_no = WIPC_CTX->idlescreen_seq_no;

    ctk_screen_set_msf_window(scrid, (kal_uint32) w);

    return (MsfWindowHandle) w;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetCtkSetOnPostPaint
 * DESCRIPTION
 *  Set callback function when screen is paint.
 *  It can be used to setup other keypad.
 * PARAMETERS
 *  wnd             [IN]        MsfWindow containing the CTK screen
 *  callback        [IN]        Callback function invoked when CTK screen is painted.
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetCtkSetOnPostPaint(MsfWindowHandle wnd, void (*callback) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!IS_CTK_TYPE(wnd))
    {
        WAP_DBG_ASSERT(0);
        return;
    }
    _CTK(wnd)->on_post_paint = callback;
}


/*****************************************************************************
 * FUNCTION
 *  widget_ctk_screen_create
 * DESCRIPTION
 *  return a ctk_screen with OnEnter and OnExit handler for Widget screen
 *  
 *  It will override OnEnter, OnExit  handler of the created CTK screen
 * PARAMETERS
 *  void
 * RETURNS
 *  handle to created CTK screen
 *****************************************************************************/
ctk_screen_handle widget_ctk_screen_create(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_create_struct scr_create;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CTK_INIT_STRUCT(scr_create);
    scr_create.scr_on_enter_fp = widget_ctk_on_enter;
    scr_create.scr_on_exit_fp = widget_ctk_on_exit;
    scr_create.scr_on_pre_paint_fp = widget_ctk_on_pre_paint;
    /* scr_on_post_close_fp is set by different types of window individually */

    return ctk_screen_create(HDIa_widgetCtkGetApp(), &scr_create);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetCtkSetFlag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ctk         [IN]        MsfWindow containing the CTK screen
 *  flags       [IN]        Flags to add
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetCtkSetFlag(MsfWindowHandle ctk, widget_ctk_flag_t flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!IS_CTK_TYPE(ctk))
    {
        WAP_DBG_ASSERT(0);
        return;
    }
    _CTK(ctk)->ctk_flag |= flags;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetCtkUnsetFlag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ctk         [IN]        MsfWindow containing the CTK screen
 *  flags       [IN]        Flags to remove
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetCtkUnsetFlag(MsfWindowHandle ctk, widget_ctk_flag_t flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!IS_CTK_TYPE(ctk))
    {
        WAP_DBG_ASSERT(0);
        return;
    }
    _CTK(ctk)->ctk_flag &= ~flags;
}

/*************************************************************************
 *
 * Predefined window types that are implemented with CTK
 * -------------------------------------------
 *
 * Note: We use MSF_MEM_ALLOC instead of ctk_mem_alloc because the allocation size
 * is not deterministic, and it is difficult to find out the boundary value of memory requirement.
 *
 *  Note: We do not support busy icon on CTK window as in widget screen.
 *
 *************************************************************************/

/*************************************************************************
 * Helper functions
 *************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  widget_ctk_free_string_pack
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId       [IN]        
 *  pack        [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_ctk_free_string_pack(MSF_UINT8 modId, widget_string_pack_struct *pack)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (pack->type == WIDGET_STRING_PACK_UCS2 && pack->_u.ucs2)
    {
        MSF_MEM_FREE(modId, pack->_u.ucs2);
        pack->_u.ucs2 = NULL;
    }
    else if (pack->type == WIDGET_STRING_PACK_UTF8 && pack->_u.utf8)
    {
        MSF_MEM_FREE(modId, pack->_u.utf8);
        pack->_u.utf8 = NULL;
    }
}

/* Note: Typically we do not store UTF-8 string internally */


/*****************************************************************************
 * FUNCTION
 *  widget_ctk_copy_string_pack
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId       [IN]        
 *  dst         [OUT]         
 *  src         [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_ctk_copy_string_pack(
                MSF_UINT8 modId,
                widget_string_pack_struct *dst,
                widget_string_pack_struct *src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(dst, 0, sizeof(widget_string_pack_struct));

    if (src->type == WIDGET_STRING_PACK_ID)
    {
        dst->type = WIDGET_STRING_PACK_ID;
        dst->_u.id = src->_u.id;
    }
    else if (src->type == WIDGET_STRING_PACK_UCS2)
    {
        dst->type = WIDGET_STRING_PACK_UCS2;
        dst->_u.ucs2 = widget_ucs2_strdup(modId, src->_u.ucs2);
    }
    else
    {
        dst->type = WIDGET_STRING_PACK_UCS2;
        dst->_u.ucs2 = widget_ucs2_strdup_from_utf8(modId, (const kal_uint8*)src->_u.utf8);
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_ctk_string_pack_get_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pack        [OUT]     
 * RETURNS
 *  
 *****************************************************************************/
static const kal_uint8 *widget_ctk_string_pack_get_data(widget_string_pack_struct *pack)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (pack->type == WIDGET_STRING_PACK_ID)
    {
        return (const kal_uint8*)GetString(pack->_u.id);
    }
    else
    {
        WAP_DBG_ASSERT(pack->type == WIDGET_STRING_PACK_UCS2);
        return pack->_u.ucs2;
    }
}

/*************************************************************************
 * TextView
 *************************************************************************/
static void widget_ctk_show_text_view(ctk_layout_handle layoutid);

typedef struct
{
    MSF_UINT8 modId;
    ctk_string_id str_title;
    ctk_image_id img_title;
    kal_uint32 flags;
    kal_uint8 *text;
} widget_ctk_text_view_struct;

/* Callback function of displaying Category74 */


/*****************************************************************************
 * FUNCTION
 *  widget_ctk_show_text_view
 * DESCRIPTION
 *  
 * PARAMETERS
 *  layoutid        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_ctk_show_text_view(ctk_layout_handle layoutid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_handle scrid = ctk_layout_get_parent_screen(layoutid);
    widget_ctk_text_view_struct *context = (widget_ctk_text_view_struct*) ctk_screen_get_local_data(scrid);
    ctk_string_id str1, str2;
    ctk_image_id img1, img2;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    guiBuffer = ctk_pcategory_get_gui_buffer(layoutid);

    /* MMI categories typically require setting the softkey label before SetLeftSoftkeyFunction */
    ctk_screen_get_LSK_label(scrid, &str1, &img1);
    ctk_screen_get_RSK_label(scrid, &str2, &img2);

    if (context->flags & WIDGET_CTK_TEXT_VIEW_DRAW_NO_SCROLLBAR)
    {
        ShowCategory7Screen(
            context->str_title,
            widget_get_title_icon(context->img_title),
            str1,
            img1,
            str2,
            img2,
            context->text,
            guiBuffer);
    }
    else if (context->flags & WIDGET_CTK_TEXT_VIEW_DRAW_SEPARATOR)
    {
        ShowCategory76Screen(
            context->str_title,
            widget_get_title_icon(context->img_title),
            str1,
            img1,
            str2,
            img2,
            context->text,
            widget_ucs2_length(context->text),
            guiBuffer);
    }
    else
    {
        ShowCategory74Screen(
            context->str_title,
            widget_get_title_icon(context->img_title),
            str1,
            img1,
            str2,
            img2,
            context->text,
            widget_ucs2_length(context->text),
            guiBuffer);
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_ctk_text_view_on_post_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrid       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_ctk_text_view_on_post_close(ctk_screen_handle scrid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_ctk_text_view_struct *context = (widget_ctk_text_view_struct*) ctk_screen_get_local_data(scrid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_MEM_FREE(context->modId, context->text);
    MSF_MEM_FREE(context->modId, context);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtCreateTextViewEx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId           [IN]        
 *  text            [IN]        UCS2, it will be duplicated. (Do we really need to duplicate it?)
 *  str_title       [IN]        
 *  img_title       [IN]        
 * RETURNS
 *  handle of the created MsfWindow
 *****************************************************************************/
MsfWindowHandle HDIa_widgetExtCreateTextViewEx(
                    MSF_UINT8 modId,
                    const kal_uint8 *text,
                    ctk_string_id str_title,
                    ctk_image_id img_title,
                    kal_uint32 flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_handle scrid;
    ctk_layout_handle layoutid;
    ctk_pcategory_create_struct layout_create;
    widget_ctk_text_view_struct *context;
    MsfWindowHandle ctk;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(widget_ctk_appid);

    /* Create CTK screen */
    scrid = widget_ctk_screen_create();
    ctk_screen_set_on_post_close_handler(scrid, widget_ctk_text_view_on_post_close);

    /* Set context */
    context = MSF_MEM_ALLOC(modId, sizeof(widget_ctk_text_view_struct));
    context->modId = modId;
    context->str_title = str_title;
    context->img_title = img_title;
    context->text = widget_ucs2_strdup(modId, text);
    context->flags = flags;
    ctk_screen_set_local_data(scrid, context);

    /* Create Layout */
    CTK_INIT_STRUCT(layout_create);
    layout_create.pcat_show_fp = widget_ctk_show_text_view;
    layoutid = ctk_pcategory_create(widget_ctk_appid, &layout_create);

    ctk_screen_attach_layout(scrid, layoutid);

    /* create MsfWindow */
    ctk = HDIa_widgetCtkCreate(modId, scrid);
    _CTK(ctk)->ctk_predefined_type = WIDGET_CTK_PREDEFINED_TEXT_VIEW;
    return ctk;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtCreateTextView
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId           [IN]        
 *  text            [IN]        UCS2, it will be duplicated. (Do we really need to duplicate it?)
 *  str_title       [IN]        
 *  img_title       [IN]        
 * RETURNS
 *  handle of the created MsfWindow
 *****************************************************************************/
MsfWindowHandle HDIa_widgetExtCreateTextView(
                    MSF_UINT8 modId,
                    const kal_uint8 *text,
                    ctk_string_id str_title,
                    ctk_image_id img_title)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MsfWindowHandle ctk;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ctk = HDIa_widgetExtCreateTextViewEx(
            modId, 
            text, 
            str_title, 
            img_title, 
            WIDGET_CTK_TEXT_VIEW_NORMAL);

    return ctk;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtCreateTextViewSeparator
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId           [IN]        
 *  text            [IN]        
 *  str_title       [IN]        
 *  img_title       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MsfWindowHandle HDIa_widgetExtCreateTextViewSeparator(
                    MSF_UINT8 modId,
                    const kal_uint8 *text,
                    ctk_string_id str_title,
                    ctk_image_id img_title)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MsfWindowHandle ctk;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ctk = HDIa_widgetExtCreateTextViewEx(
            modId, 
            text, 
            str_title, 
            img_title, 
            WIDGET_CTK_TEXT_VIEW_DRAW_SEPARATOR);

    return ctk;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtCreateTextViewNoScrollBar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId           [IN]        
 *  text            [IN]        UCS2, it will be duplicated. (Do we really need to duplicate it?)
 *  str_title       [IN]        
 *  img_title       [IN]        
 * RETURNS
 *  handle of the created MsfWindow
 *****************************************************************************/
MsfWindowHandle HDIa_widgetExtCreateTextViewNoScrollBar(
                    MSF_UINT8 modId,
                    const kal_uint8 *text,
                    ctk_string_id str_title,
                    ctk_image_id img_title)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MsfWindowHandle ctk;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ctk = HDIa_widgetExtCreateTextViewEx(
            modId, 
            text, 
            str_title, 
            img_title, 
            WIDGET_CTK_TEXT_VIEW_DRAW_NO_SCROLLBAR);

    return ctk;
}


/*************************************************************************
 * Please wait
 *************************************************************************/

typedef struct
{
    MSF_UINT8 modId;
    ctk_string_id prompt_string;
} widget_ctk_wait_view_struct;

/* Callback function of displaying Category9 */


/*****************************************************************************
 * FUNCTION
 *  widget_ctk_show_wait_view
 * DESCRIPTION
 *  
 * PARAMETERS
 *  layoutid        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_ctk_show_wait_view(ctk_layout_handle layoutid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_handle scrid = ctk_layout_get_parent_screen(layoutid);
    widget_ctk_wait_view_struct *context = (widget_ctk_wait_view_struct*) ctk_screen_get_local_data(scrid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory9Screen(context->prompt_string, SAT_WAIT_IMAGE_ID, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  widget_ctk_wait_view_on_post_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrid       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_ctk_wait_view_on_post_close(ctk_screen_handle scrid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_ctk_wait_view_struct *context = (widget_ctk_wait_view_struct*) ctk_screen_get_local_data(scrid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_MEM_FREE(context->modId, context);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtCreateWaitView
 * DESCRIPTION
 *  Create a "please wait" screen
 * PARAMETERS
 *  modId               [IN]        
 *  prompt_string       [IN]        
 * RETURNS
 *  handle of the created MsfWindow
 *****************************************************************************/
MsfWindowHandle HDIa_widgetExtCreateWaitView(MSF_UINT8 modId, ctk_string_id prompt_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_handle scrid;
    ctk_layout_handle layoutid;
    ctk_pcategory_create_struct layout_create;
    MsfWindowHandle ctk;
    widget_ctk_wait_view_struct *context;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Create CTK screen */
    scrid = widget_ctk_screen_create();
    ctk_screen_set_on_post_close_handler(scrid, widget_ctk_wait_view_on_post_close);

    context = MSF_MEM_ALLOC(modId, sizeof(widget_ctk_wait_view_struct));
    context->modId = modId;
    context->prompt_string = prompt_string;
    ctk_screen_set_local_data(scrid, context);

    /* Create Layout */
    CTK_INIT_STRUCT(layout_create);
    layout_create.pcat_show_fp = widget_ctk_show_wait_view;
    layoutid = ctk_pcategory_create(widget_ctk_appid, &layout_create);

    ctk_screen_attach_layout(scrid, layoutid);

    /* create MsfWindow */
    ctk = HDIa_widgetCtkCreate(modId, scrid);
    _CTK(ctk)->ctk_predefined_type = WIDGET_CTK_PREDEFINED_WAIT_VIEW;
    _CTK(ctk)->ctk_flag |= WIDGET_CTK_FLAG_BACKLIGHT_ALWAYS_ON;
    return ctk;
}

/*************************************************************************
 * Progress view
 *************************************************************************/
typedef struct
{
    kal_uint8 update_state;
    MSF_UINT8 modId;
    ctk_string_id str_title;
    ctk_image_id img_title;
    MSF_UINT16 percent;
    kal_uint8 *text1, *text2;
} widget_ctk_progress_view_struct;


/* Prevent reference of deallocated data */

/*****************************************************************************
 * FUNCTION
 *  widget_ctk_progress_reset_title_if_necessary
 * DESCRIPTION
 *  
 * PARAMETERS
 *  context     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_ctk_progress_reset_title_if_necessary(widget_ctk_progress_view_struct *context)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (context->text1 && MMI_title_string == (UI_string_type) context->text1)
    {
        MMI_title_string = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_ctk_show_progress_bar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  layoutid        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_ctk_show_progress_bar(ctk_layout_handle layoutid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_handle scrid = ctk_layout_get_parent_screen(layoutid);
    widget_ctk_progress_view_struct *context = (widget_ctk_progress_view_struct*) ctk_screen_get_local_data(scrid);
    ctk_string_id str1, str2;
    ctk_image_id img1, img2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MMI categories typically require setting the softkey label before SetLeftSoftkeyFunction */
    ctk_screen_get_LSK_label(scrid, &str1, &img1);
    ctk_screen_get_RSK_label(scrid, &str2, &img2);

    if (!ctk_screen_is_back_history(scrid) &&
        context->update_state == WIDGET_CTK_PROGRESS_BAR_UPDATE_REQ)
    {
        UpdateCategory402Value(context->percent, context->text2);
        context->update_state = WIDGET_CTK_PROGRESS_BAR_UPDATE_DONE;
    }
    else
    {
        /*
         * Execute widget_ctk_show_progress_bar() first time 
         * after calling HDIa_widgetExtCreateProgressView() or
         * goback history to progressView screen.
         */
        ShowCategory402Screen(
            (U8*)get_string(context->str_title),
            widget_get_title_icon(context->img_title),
            str1,
            img1,
            str2,
            img2,
            (context->text1) ? (U8*) context->text1 : (U8*) L"",
            context->percent,
            /* If context->text2 is "", we assign NULL and then the category will show the percentage info. */
            (context->text2 && app_ucs2_strcmp((const kal_int8 *)(context->text2), (const kal_int8 *)L"")) 
            ? (U8*) context->text2 : NULL);
        context->update_state = WIDGET_CTK_PROGRESS_BAR_UPDATE_DONE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  widget_ctk_show_progress
 * DESCRIPTION
 *  
 * PARAMETERS
 *  layoutid        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_ctk_show_progress(ctk_layout_handle layoutid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_handle scrid = ctk_layout_get_parent_screen(layoutid);
    widget_ctk_progress_view_struct *context = (widget_ctk_progress_view_struct*) ctk_screen_get_local_data(scrid);
    char percent[32];
    kal_uint8 *percent_u;

    ctk_string_id str1, str2;
    ctk_image_id img1, img2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ctk_screen_get_LSK_label(scrid, &str1, &img1);
    ctk_screen_get_RSK_label(scrid, &str2, &img2);

#ifdef MMS_SUPPORT
    if (context->percent == 0)
    {
        percent_u = (kal_uint8*) GetString(MEA_STR_ID_CONNECTING);
    }
    else
#endif /* MMS_SUPPORT */ 
    {
        sprintf(percent, "%d %%", context->percent);
        percent_u = widget_ucs2_strdup_from_utf8(context->modId, (const kal_uint8*)percent);
    }

    /* Prevent title blinking */
    gui_lock_double_buffer();

    ShowCategory208Screen(
        context->str_title,
        widget_get_title_icon(context->img_title),
        str1,
        img1,
        str2,
        img2,
        (S8*) percent_u,
        IMG_NEW_SMS_SEND,
        NULL);

#ifdef MMS_SUPPORT
    /* 
     * original code: if (context->percent != 0)
     *
     * refer CR id [MAUI_00219542]
     * In some strange situation, percent_u is the predefined string, but context->percent is 1.
     */
    if (percent_u != (kal_uint8*) GetString(MEA_STR_ID_CONNECTING))
#endif /* MMS_SUPPORT */ 
    {
        MSF_MEM_FREE(context->modId, percent_u);
    }

    if (context->text1)
    {
        MMI_title_string = (UI_string_type) context->text1;
    #ifdef WIDGET_RESIDENT_STATUS_ICON
        show_title_status_icon();
    #endif
        draw_title();
    }
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  widget_ctk_progress_view_on_post_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrid       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_ctk_progress_view_on_post_close(ctk_screen_handle scrid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_ctk_progress_view_struct *context = (widget_ctk_progress_view_struct*) ctk_screen_get_local_data(scrid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    widget_ctk_progress_reset_title_if_necessary(context);

    if (context->text1)
    {
        MSF_MEM_FREE(context->modId, context->text1);
    }
    if (context->text2)
    {
        MSF_MEM_FREE(context->modId, context->text2);
    }
    MSF_MEM_FREE(context->modId, context);
    context->update_state = WIDGET_CTK_PROGRESS_BAR_UPDATE_NONE;
}

/* It will also update the screen */


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtSetProgressPercentage
 * DESCRIPTION
 *  
 * PARAMETERS
 *  wnd         [IN]        
 *  percent     [IN]        
 *  text1       [IN]        
 *  text2       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtSetProgressPercentage(
        MsfWindowHandle wnd,
        MSF_UINT16 percent,
        const kal_uint8 *text1,
        const kal_uint8 *text2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_handle scrid = HDIa_widgetCtkGetScreenHandle(wnd);
    widget_ctk_progress_view_struct *context = (widget_ctk_progress_view_struct*) ctk_screen_get_local_data(scrid);
    widget_ctk_struct *ctk = (widget_ctk_struct*) HDIa_widgetCtkGetWindow(scrid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Sometimes we use HDIa_widgetExtCreateProgressView and HDIa_widgetExtCreateWaitView interchangeably */
    if (ctk->ctk_predefined_type != WIDGET_CTK_PREDEFINED_PROGRESS_VIEW)
    {
        return;
    }

    ASSERT(context);

    widget_ctk_progress_reset_title_if_necessary(context);

    if (context->text1)
    {
        MSF_MEM_FREE(context->modId, context->text1);
        context->text1 = NULL;
    }
    if (context->text2)
    {
        MSF_MEM_FREE(context->modId, context->text2);
        context->text2 = NULL;
    }

    if (text1)
    {
        context->text1 = widget_ucs2_strdup(context->modId, text1);
    }
    if (text2)
    {
        context->text2 = widget_ucs2_strdup(context->modId, text2);
    }

    context->percent = percent;

    if (context->update_state != WIDGET_CTK_PROGRESS_BAR_UPDATE_NONE)
    {
        context->update_state = WIDGET_CTK_PROGRESS_BAR_UPDATE_REQ;
    }
    ctk_screen_invoke_redraw(scrid);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtCreateProgressView
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId           [IN]        
 *  str_title       [IN]        
 *  img_title       [IN]        
 *  is_bar          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MsfWindowHandle HDIa_widgetExtCreateProgressView(
                    MSF_UINT8 modId,
                    ctk_string_id str_title,
                    ctk_image_id img_title,
                    kal_bool is_bar)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_handle scrid;
    ctk_layout_handle layoutid;
    ctk_pcategory_create_struct layout_create;
    widget_ctk_progress_view_struct *context;
    MsfWindowHandle ctk;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(widget_ctk_appid);

    /* Create CTK screen */
    scrid = widget_ctk_screen_create();
    ctk_screen_set_on_post_close_handler(scrid, widget_ctk_progress_view_on_post_close);

    /* Set context */
    context = MSF_MEM_ALLOC(modId, sizeof(widget_ctk_progress_view_struct));
    context->modId = modId;
    context->str_title = str_title;
    context->img_title = img_title;
    context->update_state = WIDGET_CTK_PROGRESS_BAR_UPDATE_NONE;
    context->percent = 0;
    context->text1 = NULL;
    context->text2 = NULL;
    ctk_screen_set_local_data(scrid, context);

    /* Create Layout */
    CTK_INIT_STRUCT(layout_create);
    if (is_bar)
    {
        layout_create.pcat_show_fp = widget_ctk_show_progress_bar;
    }
    else
    {
        layout_create.pcat_show_fp = widget_ctk_show_progress;
    }
    layoutid = ctk_pcategory_create(widget_ctk_appid, &layout_create);

    ctk_screen_attach_layout(scrid, layoutid);

    /* create MsfWindow */
    ctk = HDIa_widgetCtkCreate(modId, scrid);
    _CTK(ctk)->ctk_predefined_type = WIDGET_CTK_PREDEFINED_PROGRESS_VIEW;
    _CTK(ctk)->ctk_flag |= WIDGET_CTK_FLAG_BACKLIGHT_ALWAYS_ON;
    return ctk;
}

/*************************************************************************
 * ListMenu
 * Category 52 - list of string id
 * Category 53 - list of string pointer
 * Category 73 - two icons per item (without hint)
 *
 *************************************************************************/

typedef struct
{
    MSF_UINT8 modId;
    ctk_string_id str_title;
    ctk_image_id img_title;
    int num_items;
    ctk_string_id *str_item_list;   /* 1. a list of string ID */
    kal_uint8 **str_value_list;     /* 2. a list of strings */
    ctk_image_id *img_item_list;
    ctk_image_id *img_item_list2;
    kal_uint8 **hint_list;

    /* runtime data */
    int highlighted;
} widget_ctk_list_menu_struct;


/*****************************************************************************
 * FUNCTION
 *  widget_ctk_list_menu_free_context
 * DESCRIPTION
 *  
 * PARAMETERS
 *  context     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_ctk_list_menu_free_context(widget_ctk_list_menu_struct *context)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (context->str_item_list)
    {
        MSF_MEM_FREE(context->modId, context->str_item_list);
    }
    if (context->str_value_list)
    {
        for (i = 0; i < context->num_items; i++)
        {
            if (!WIDGET_CTK_IS_EMPTY_STR(context->str_value_list[i]))
            {
                MSF_MEM_FREE(context->modId, context->str_value_list[i]);
            }
        }
        MSF_MEM_FREE(context->modId, context->str_value_list);
    }
    if (context->img_item_list)
    {
        MSF_MEM_FREE(context->modId, context->img_item_list);
    }
    if (context->img_item_list2)
    {
        MSF_MEM_FREE(context->modId, context->img_item_list2);
    }
    if (context->hint_list)
    {
        for (i = 0; i < context->num_items; i++)
        {
            if (context->hint_list[i])
            {
                MSF_MEM_FREE(context->modId, context->hint_list[i]);
            }
        }
        MSF_MEM_FREE(context->modId, context->hint_list);
    }

    MSF_MEM_FREE(context->modId, context);
}


/*****************************************************************************
 * FUNCTION
 *  widget_ctk_list_menu_on_post_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrid       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_ctk_list_menu_on_post_close(ctk_screen_handle scrid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_ctk_list_menu_struct *context = (widget_ctk_list_menu_struct*) ctk_screen_get_local_data(scrid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    widget_ctk_list_menu_free_context(context);
}


/*****************************************************************************
 * FUNCTION
 *  widget_ctk_list_menu_highlight
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrid       [IN]        
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_ctk_list_menu_highlight(ctk_screen_handle scrid, int index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_ctk_list_menu_struct *context = (widget_ctk_list_menu_struct*) ctk_screen_get_local_data(scrid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    context->highlighted = index;
}


/*****************************************************************************
 * FUNCTION
 *  widget_ctk_show_list_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  layoutid        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_ctk_show_list_menu(ctk_layout_handle layoutid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_handle scrid;
    widget_ctk_list_menu_struct *context;
    U8 *guiBuffer;
    ctk_string_id str1, str2;
    ctk_image_id img1, img2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrid = ctk_layout_get_parent_screen(layoutid);
    context = (widget_ctk_list_menu_struct*) ctk_screen_get_local_data(scrid);
    guiBuffer = ctk_pcategory_get_gui_buffer(layoutid);
    ctk_screen_get_LSK_label(scrid, &str1, &img1);
    ctk_screen_get_RSK_label(scrid, &str2, &img2);

    // TODO: we may adopt something like GetDispAttributeOfItem
    if (context->img_item_list2)
    {
        ASSERT(context->str_value_list);
        ShowCategory73Screen(
            context->str_title,
            widget_get_title_icon(context->img_title),
            str1,
            img1,
            str2,
            img2,
            context->num_items,
            (U8 **) context->str_value_list,
            context->img_item_list,
            context->img_item_list2,
            0,
            guiBuffer,
            ICON_ICON_TEXT);
    }
    else if (context->str_item_list)
    {
        ShowCategory52Screen(
            context->str_title,
            widget_get_title_icon(context->img_title),
            str1,
            img1,
            str2,
            img2,
            context->num_items,
            context->str_item_list,
            context->img_item_list,
            (U8 **) context->hint_list,
            0,
            0,
            guiBuffer);
    }
    else
    {
        ASSERT(context->str_value_list);
        ShowCategory53Screen(
            context->str_title,
            widget_get_title_icon(context->img_title),
            str1,
            img1,
            str2,
            img2,
            context->num_items,
            (U8 **) context->str_value_list,
            context->img_item_list,
            (U8 **) context->hint_list,
            0,
            0,
            guiBuffer);
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_ctk_list_menu_create_context
 * DESCRIPTION
 *  Standard MMI list menu
 * PARAMETERS
 *  modId               [IN]        
 *  str_title           [IN]        
 *  img_title           [IN]        
 *  num_items           [IN]        
 *  str_item_list       [IN]        
 *  str_value_list      [IN]        
 *  img_item_list       [IN]        
 *  img_item_list2      [IN]         
 *  hint_list           [IN]        Each entry can points to NULL or a UCS2/UTF-8 string
 *  value_in_UTF8       [IN]        
 * RETURNS
 *  handle of the created MsfWindow
 *****************************************************************************/
#define MAX_HINT_LENGTH (MAX_SUB_MENU_HINT_SIZE/ENCODING_LENGTH - 1)

static widget_ctk_list_menu_struct *widget_ctk_list_menu_create_context(
                                        MSF_UINT8 modId,
                                        ctk_string_id str_title,
                                        ctk_image_id img_title,
                                        int num_items,
                                        ctk_string_id *str_item_list /* case 1 */ ,
                                        kal_uint8 **str_value_list /* case 2 */ ,
                                        ctk_image_id *img_item_list,
                                        ctk_image_id *img_item_list2,
                                        kal_uint8 *hint_list[],
                                        kal_bool value_in_UTF8)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_ctk_list_menu_struct *context;
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    context = MSF_MEM_ALLOC(modId, sizeof(widget_ctk_list_menu_struct));
    memset(context, 0, sizeof(widget_ctk_list_menu_struct));
    context->modId = modId;
    context->str_title = str_title;
    context->img_title = img_title;
    context->num_items = num_items;
    if (str_item_list)
    {
        context->str_value_list = NULL;
        context->str_item_list = MSF_MEM_ALLOC(modId, sizeof(ctk_string_id) * num_items);
        memcpy(context->str_item_list, str_item_list, sizeof(ctk_string_id) * num_items);
    }
    else
    {
        context->str_item_list = NULL;
        context->str_value_list = MSF_MEM_ALLOC(modId, sizeof(kal_uint8*) * num_items);
        for (i = 0; i < num_items; i++)
        {
            if (str_value_list[i])
            {
                if (value_in_UTF8)
                {
                    context->str_value_list[i] = widget_ucs2_strdup_from_utf8(modId, str_value_list[i]);
                }
                else
                {
                    context->str_value_list[i] = widget_ucs2_strdup(modId, str_value_list[i]);
                }
            }
            else
            {
                WIDGET_CTK_SET_EMPTY_STR(context->str_value_list[i]);
            }
        }
    }
    context->img_item_list = MSF_MEM_ALLOC(modId, sizeof(ctk_image_id) * num_items);
    memcpy(context->img_item_list, img_item_list, sizeof(ctk_image_id) * num_items);

    if (img_item_list2)
    {
        context->img_item_list2 = MSF_MEM_ALLOC(modId, sizeof(ctk_image_id) * num_items);
        memcpy(context->img_item_list2, img_item_list2, sizeof(ctk_image_id) * num_items);
    }
    else
    {
        context->img_item_list2 = NULL;
    }

    if (hint_list == NULL)
    {
        context->hint_list = NULL;
    }
    else
    {
        context->hint_list = MSF_MEM_ALLOC(modId, sizeof(kal_uint8*) * num_items);
        for (i = 0; i < num_items; i++)
        {
            if (hint_list[i])
            {
                if (value_in_UTF8)
                {
                    if (hint_list[i][0] != 0)
                    {
                        context->hint_list[i] = widget_ucs2_strdup_from_utf8(modId, hint_list[i]);
                    }
                    else
                    {
                        context->hint_list[i] = NULL;
                    }
                }
                else
                {
                    if (CHR_AT(hint_list[i], 0) != CHR(0))
                    {
                        context->hint_list[i] = widget_ucs2_strdup(modId, hint_list[i]);
                    }
                    else
                    {
                        context->hint_list[i] = NULL;
                    }
                }

                /* Although there is no such limitation in GUI system. We follow MMI convention */
                if (context->hint_list[i] && widget_ucs2_length(context->hint_list[i]) > MAX_HINT_LENGTH)
                {
                    SET_CHR_AT(context->hint_list[i], MAX_HINT_LENGTH - 1, 0);
                }
            }
            else
            {
                context->hint_list[i] = NULL;
            }

        }
    }
    context->highlighted = 0;
    return context;
}


/*****************************************************************************
 * FUNCTION
 *  widget_ctk_create_list_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId               [IN]        
 *  str_title           [IN]        
 *  img_title           [IN]        
 *  num_items           [IN]        
 *  str_item_list       [IN]         
 *  str_value_list      [IN]        
 *  img_item_list       [IN]         
 *  img_item_list2      [IN]         
 *  hint_list           [IN]         
 *  value_in_UTF8       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MsfWindowHandle widget_ctk_create_list_menu(
                        MSF_UINT8 modId,
                        ctk_string_id str_title,
                        ctk_image_id img_title,
                        int num_items,
                        ctk_string_id *str_item_list /* case 1 */ ,
                        kal_uint8 **str_value_list /* case 2 */ ,
                        ctk_image_id *img_item_list,
                        ctk_image_id *img_item_list2,
                        kal_uint8 *hint_list[],
                        kal_bool value_in_UTF8)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_handle scrid;
    ctk_layout_handle layoutid;
    ctk_pcategory_create_struct layout_create;
    widget_ctk_list_menu_struct *context;
    MsfWindowHandle ctk;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(widget_ctk_appid);

    /* Create CTK screen */
    scrid = widget_ctk_screen_create();
    ctk_screen_set_on_post_close_handler(scrid, widget_ctk_list_menu_on_post_close);

    /* Set context */
    context = widget_ctk_list_menu_create_context(
                modId,
                str_title,
                img_title,
                num_items,
                str_item_list,
                str_value_list,
                img_item_list,
                img_item_list2,
                hint_list,
                value_in_UTF8);
    ctk_screen_set_local_data(scrid, context);

    /* Create Layout */
    CTK_INIT_STRUCT(layout_create);
    layout_create.pcat_show_fp = widget_ctk_show_list_menu;
    layout_create.pcat_highlight_fp = widget_ctk_list_menu_highlight;
    layoutid = ctk_pcategory_create(widget_ctk_appid, &layout_create);

    ctk_screen_attach_layout(scrid, layoutid);

    /* create MsfWindow */
    ctk = HDIa_widgetCtkCreate(modId, scrid);
    _CTK(ctk)->ctk_predefined_type = WIDGET_CTK_PREDEFINED_LIST_MENU;
    return ctk;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtCreateListMenu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId               [IN]        
 *  str_title           [IN]        
 *  img_title           [IN]        
 *  num_items           [IN]        
 *  str_item_list       [IN]         
 *  img_item_list       [IN]         
 *  hint_list           [IN]         
 *  value_in_UTF8       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MsfWindowHandle HDIa_widgetExtCreateListMenu(
                    MSF_UINT8 modId,
                    ctk_string_id str_title,
                    ctk_image_id img_title,
                    int num_items,
                    ctk_string_id *str_item_list,
                    ctk_image_id *img_item_list,
                    kal_uint8 *hint_list[],
                    kal_bool value_in_UTF8)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return widget_ctk_create_list_menu(
            modId,
            str_title,
            img_title,
            num_items,
            str_item_list,
            NULL,
            img_item_list,
            NULL,
            hint_list,
            value_in_UTF8);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtCreateListMenuByValue
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId               [IN]        
 *  str_title           [IN]        
 *  img_title           [IN]        
 *  num_items           [IN]        
 *  str_value_list      [IN]        
 *  img_item_list       [IN]         
 *  hint_list           [IN]         
 *  value_in_UTF8       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MsfWindowHandle HDIa_widgetExtCreateListMenuByValue(
                    MSF_UINT8 modId,
                    ctk_string_id str_title,
                    ctk_image_id img_title,
                    int num_items,
                    kal_uint8 **str_value_list,
                    ctk_image_id *img_item_list,
                    kal_uint8 *hint_list[],
                    kal_bool value_in_UTF8)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return widget_ctk_create_list_menu(
            modId,
            str_title,
            img_title,
            num_items,
            NULL,
            str_value_list,
            img_item_list,
            NULL,
            hint_list,
            value_in_UTF8);
}

/* No Hint */


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtCreateListMenuTwoIcons
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId               [IN]        
 *  str_title           [IN]        
 *  img_title           [IN]        
 *  num_items           [IN]        
 *  str_value_list      [IN]        
 *  img_item_list       [IN]         
 *  img_item_list2      [IN]         
 *  value_in_UTF8       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MsfWindowHandle HDIa_widgetExtCreateListMenuTwoIcons(
                    MSF_UINT8 modId,
                    ctk_string_id str_title,
                    ctk_image_id img_title,
                    int num_items,
                    kal_uint8 **str_value_list,
                    ctk_image_id *img_item_list,
                    ctk_image_id *img_item_list2,
                    kal_bool value_in_UTF8)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return widget_ctk_create_list_menu(
            modId,
            str_title,
            img_title,
            num_items,
            NULL,
            str_value_list,
            img_item_list,
            img_item_list2,
            NULL,
            value_in_UTF8);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtUpdateListMenu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  wnd                 [IN]        
 *  str_title           [IN]        
 *  img_title           [IN]        
 *  num_items           [IN]        
 *  str_item_list       [IN]         
 *  img_item_list       [IN]         
 *  hint_list           [IN]         
 *  value_in_UTF8       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtUpdateListMenu(
        MsfWindowHandle wnd,
        ctk_string_id str_title,
        ctk_image_id img_title,
        int num_items,
        ctk_string_id *str_item_list,
        ctk_image_id *img_item_list,
        kal_uint8 *hint_list[],
        kal_bool value_in_UTF8)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_handle scrid = HDIa_widgetCtkGetScreenHandle(wnd);
    widget_ctk_list_menu_struct *context = (widget_ctk_list_menu_struct*) ctk_screen_get_local_data(scrid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    widget_ctk_list_menu_free_context(context);

    context = widget_ctk_list_menu_create_context(
                context->modId,
                str_title,
                img_title,
                num_items,
                str_item_list,
                NULL,
                img_item_list,
                NULL,
                hint_list,
                value_in_UTF8);
    ctk_screen_set_local_data(scrid, context);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtUpdateListMenuByValue
 * DESCRIPTION
 *  
 * PARAMETERS
 *  wnd                 [IN]        
 *  str_title           [IN]        
 *  img_title           [IN]        
 *  num_items           [IN]        
 *  str_value_list      [IN]        
 *  img_item_list       [IN]         
 *  hint_list           [IN]         
 *  value_in_UTF8       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtUpdateListMenuByValue(
        MsfWindowHandle wnd,
        ctk_string_id str_title,
        ctk_image_id img_title,
        int num_items,
        kal_uint8 **str_value_list,
        ctk_image_id *img_item_list,
        kal_uint8 *hint_list[],
        kal_bool value_in_UTF8)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_handle scrid = HDIa_widgetCtkGetScreenHandle(wnd);
    widget_ctk_list_menu_struct *context = (widget_ctk_list_menu_struct*) ctk_screen_get_local_data(scrid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    widget_ctk_list_menu_free_context(context);

    context = widget_ctk_list_menu_create_context(
                context->modId,
                str_title,
                img_title,
                num_items,
                NULL,
                str_value_list,
                img_item_list,
                NULL,
                hint_list,
                value_in_UTF8);
    ctk_screen_set_local_data(scrid, context);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtUpdateListMenuTwoIcons
 * DESCRIPTION
 *  
 * PARAMETERS
 *  wnd                 [IN]        
 *  str_title           [IN]        
 *  img_title           [IN]        
 *  num_items           [IN]        
 *  str_value_list      [IN]        
 *  img_item_list       [IN]         
 *  img_item_list2      [IN]         
 *  value_in_UTF8       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtUpdateListMenuTwoIcons(
        MsfWindowHandle wnd,
        ctk_string_id str_title,
        ctk_image_id img_title,
        int num_items,
        kal_uint8 **str_value_list,
        ctk_image_id *img_item_list,
        ctk_image_id *img_item_list2,
        kal_bool value_in_UTF8)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_handle scrid = HDIa_widgetCtkGetScreenHandle(wnd);
    widget_ctk_list_menu_struct *context = (widget_ctk_list_menu_struct*) ctk_screen_get_local_data(scrid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    widget_ctk_list_menu_free_context(context);

    context = widget_ctk_list_menu_create_context(
                context->modId,
                str_title,
                img_title,
                num_items,
                NULL,
                str_value_list,
                img_item_list,
                img_item_list2,
                NULL,
                value_in_UTF8);
    ctk_screen_set_local_data(scrid, context);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtListMenuUpdateHint
 * DESCRIPTION
 *  
 * PARAMETERS
 *  wnd                 [IN]        
 *  hint                [IN]        Non-null for assign another hint, otherwise for disable hint
 *  index               [IN]        The menu item index to be updated
 *  hint_in_UTF8        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtListMenuUpdateHint(MsfWindowHandle wnd, kal_uint8 *hint, int index, kal_bool hint_in_UTF8)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_handle scrid = HDIa_widgetCtkGetScreenHandle(wnd);
    MSF_UINT8 modId;
    widget_ctk_list_menu_struct *context = (widget_ctk_list_menu_struct*) ctk_screen_get_local_data(scrid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(context);

    WAP_DBG_ASSERT(index < context->num_items);
    if (index >= context->num_items)
    {
        return;
    }

    modId = context->modId;

    if (context->hint_list != NULL)
    {
        if (context->hint_list[index])
        {
            MSF_MEM_FREE(modId, context->hint_list[index]);
        }

        if (hint)
        {
            if (hint_in_UTF8)
            {
                if (hint[0] != 0)
                {
                    context->hint_list[index] = widget_ucs2_strdup_from_utf8(modId, hint);
                }
                else
                {
                    context->hint_list[index] = NULL;
                }
            }
            else
            {
                if (CHR_AT(hint, 0) != CHR(0))
                {
                    context->hint_list[index] = widget_ucs2_strdup(modId, hint);
                }
                else
                {
                    context->hint_list[index] = NULL;
                }
            }

            /* Although there is no such limitation in GUI system. We follow MMI convention */
            if (context->hint_list[index] && widget_ucs2_length(context->hint_list[index]) > MAX_HINT_LENGTH)
            {
                SET_CHR_AT(context->hint_list[index], MAX_HINT_LENGTH - 1, 0);
            }
        }
        else
        {
            context->hint_list[index] = NULL;
        }
    }

    ctk_screen_invoke_redraw(scrid);
}

/* Deprecated */


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtListMenuSetItem
 * DESCRIPTION
 *  
 * PARAMETERS
 *  wnd         [IN]        
 *  index       [IN]        
 *  strid       [IN]        
 *  imageid     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtListMenuSetItem(MsfWindowHandle wnd, int index, ctk_string_id strid, ctk_image_id imageid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_handle scrid = HDIa_widgetCtkGetScreenHandle(wnd);
    widget_ctk_list_menu_struct *context = (widget_ctk_list_menu_struct*) ctk_screen_get_local_data(scrid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(context && _CTK(wnd)->ctk_predefined_type == WIDGET_CTK_PREDEFINED_LIST_MENU);

    if (index < 0 || index >= context->num_items)
    {
        WAP_DBG_ASSERT(0);
        return;
    }
    if (context->str_item_list == NULL)
    {
        WAP_DBG_ASSERT(0);
        return;
    }
    context->str_item_list[index] = strid;
    context->img_item_list[index] = imageid;
}

/* Deprecated */


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtListMenuSetItemByValue
 * DESCRIPTION
 *  
 * PARAMETERS
 *  wnd                 [IN]        
 *  index               [IN]        
 *  string              [IN]         
 *  imageid             [IN]        
 *  value_in_UTF8       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtListMenuSetItemByValue(
        MsfWindowHandle wnd,
        int index,
        kal_uint8 *string,
        ctk_image_id imageid,
        kal_bool value_in_UTF8)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_handle scrid = HDIa_widgetCtkGetScreenHandle(wnd);
    widget_ctk_list_menu_struct *context = (widget_ctk_list_menu_struct*) ctk_screen_get_local_data(scrid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(context && _CTK(wnd)->ctk_predefined_type == WIDGET_CTK_PREDEFINED_LIST_MENU);

    if (index < 0 || index >= context->num_items)
    {
        WAP_DBG_ASSERT(0);
        return;
    }
    if (context->str_value_list == NULL)
    {
        WAP_DBG_ASSERT(0);
        return;
    }

    if (!WIDGET_CTK_IS_EMPTY_STR(context->str_value_list[index]))
    {
        MSF_MEM_FREE(context->modId, context->str_value_list[index]);
    }
    if (value_in_UTF8)
    {
        context->str_value_list[index] = widget_ucs2_strdup_from_utf8(context->modId, string);
    }
    else
    {
        context->str_value_list[index] = widget_ucs2_strdup(context->modId, string);
    }
    context->img_item_list[index] = imageid;
}

/*************************************************************************
 * Dynamic list menu
 *************************************************************************/
typedef struct
{
    MSF_UINT8 modId;
    kal_uint8 is_shown;
    kal_uint16 highlighted;
    ctk_string_id str_title;
    ctk_image_id img_title;
    int num_items;
    widget_list_menu_callback callback;
    widget_list_menu_hint_callback callback_hint;
    void *arg_for_callback;
} widget_ctk_dynamic_list_menu_struct;

#ifdef WIDGET_TMPFIX_DYNAMIC_LIST


/*****************************************************************************
 * FUNCTION
 *  widget_ctk_dynamic_list_menu_take_WAP_extq_lock
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_ctk_dynamic_list_menu_take_WAP_extq_lock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_CTK_DYNAMIC_LIST_MENU_TAKE_WAP_Q_LOCK);
    /* WAP might be on the way of processing external queue now */
    WIPC_CTX->MMI_try_to_lock_extq_mutex = 1;
    kal_take_mutex(WIPC_CTX->WAP_extq_mutex);
    WIPC_CTX->MMI_try_to_lock_extq_mutex = 0;

    /*
     * We assume the callback function does not create new window, which makes sense.
     * * Otherwise, it is difficult to handle widget_execute_MMI() for this case.
     */
    /* WIPC_CTX->WAP_is_waiting = 1; */

    ASSERT(!WIPC_CTX->extq_mutex_locked_by_WAP);
    WIPC_CTX->extq_mutex_locked_by_MMI = 1;
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_CTK_DYNAMIC_LIST_MENU_TAKE_WAP_Q_LOCK_END);
}


/*****************************************************************************
 * FUNCTION
 *  widget_ctk_dynamic_list_menu_give_WAP_extq_lock
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_ctk_dynamic_list_menu_give_WAP_extq_lock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_CTK_DYNAMIC_LIST_MENU_GIVE_WAP_Q_LOCK);
    ASSERT(WIPC_CTX->extq_mutex_locked_by_MMI);
    /* WIPC_CTX->WAP_is_waiting = 0; */
    WIPC_CTX->extq_mutex_locked_by_MMI = 0;
    kal_give_mutex(WIPC_CTX->WAP_extq_mutex);
}

#endif /* WIDGET_TMPFIX_DYNAMIC_LIST */ 


/*****************************************************************************
 * FUNCTION
 *  widget_ctk_dynamic_list_menu_get_item_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index          [IN]        
 *  str_buff            [IN]        
 *  img_buff_p          [IN]         
 *  str_img_mask        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static pBOOL widget_ctk_dynamic_list_menu_get_item_hdlr(
                S32 item_index,
                UI_string_type str_buff,
                PU8 *img_buff_p,
                U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_handle scrid = ctk_screen_get_current_scrid();
    widget_ctk_struct *ctk;
    widget_ctk_dynamic_list_menu_struct *context;
    ctk_image_id imageid;

#ifdef WIDGET_TMPFIX_DYNAMIC_LIST
    kal_bool lock_mutex = KAL_FALSE;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_CTK_DYNAMIC_LIST_MENU_GET_ITEM_HDLR);

    if (scrid == 0 || (ctk = _CTK(ctk_screen_get_msf_window(scrid))) == NULL ||
        !IS_CTK_TYPE(ctk) || ctk->ctk_predefined_type != WIDGET_CTK_PREDEFINED_DYNAMIC_LIST_MENU)
    {
        /* Return dummy result */
        //WAP_DBG_ASSERT(0);
        ASSERT(0);
        return FALSE;
    }

    context = (widget_ctk_dynamic_list_menu_struct*) ctk_screen_get_local_data(scrid);
    if (item_index < 0 || item_index >= context->num_items)
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_CTK_DYNAMIC_LIST_MENU_GET_ITEM_HDLR_INDEX_ERROR, item_index, context->num_items);
        return FALSE;
    }

    if (!context->is_shown)
    {
        /* ctk_screen_invoke_redraw must be executed before HDIa_widgetExtUpdateListMenuByCallback() */
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_CTK_DYNAMIC_LIST_MENU_GET_ITEM_HDLR_SHOW_ERROR, context->is_shown);
        WAP_DBG_ASSERT(0);
        return FALSE;
    }

#ifdef WIDGET_TMPFIX_DYNAMIC_LIST
    if (!WIPC_CTX->WAP_is_waiting)  /* Not invoked from widget_paint() or ctk_invoke_redraw() */
    {
        ASSERT(WIDGET_IS_MMI_TASK());   /* Otherwise, deadlock */
        lock_mutex = KAL_TRUE;
    }

    if (lock_mutex)
    {
        widget_ctk_dynamic_list_menu_take_WAP_extq_lock();
    }

    context->callback(item_index, context->arg_for_callback, (kal_uint8*) str_buff, MAX_SUB_MENU_SIZE, &imageid);
    WAP_DBG_ASSERT(widget_ucs2_length((kal_uint8*) str_buff) <= (MAX_SUB_MENU_SIZE / 2) - 1);

    if (lock_mutex)
    {
        widget_ctk_dynamic_list_menu_give_WAP_extq_lock();
    }
#else /* WIDGET_TMPFIX_DYNAMIC_LIST */ 
    context->callback(item_index, context->arg_for_callback, (kal_uint8*) str_buff, MAX_SUB_MENU_SIZE, &imageid);

#endif /* WIDGET_TMPFIX_DYNAMIC_LIST */ 

    *img_buff_p = get_image((MMI_ID_TYPE) imageid);

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  widget_ctk_dynamic_list_menu_get_hint_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index      [IN]        
 *  hint_array      [IN]         
 * RETURNS
 *  
 *****************************************************************************/
S32 widget_ctk_dynamic_list_menu_get_hint_hdlr(S32 item_index, UI_string_type *hint_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_handle scrid = ctk_screen_get_current_scrid();
    widget_ctk_struct *ctk;
    widget_ctk_dynamic_list_menu_struct *context;

#ifdef WIDGET_TMPFIX_DYNAMIC_LIST
    kal_bool lock_mutex = KAL_FALSE;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_CTK_DYNAMIC_LIST_MENU_GET_HINT_HDLR);

    if (scrid == 0 || (ctk = _CTK(ctk_screen_get_msf_window(scrid))) == NULL ||
        !IS_CTK_TYPE(ctk) || ctk->ctk_predefined_type != WIDGET_CTK_PREDEFINED_DYNAMIC_LIST_MENU)
    {
        /* Return dummy result */
        //WAP_DBG_ASSERT(0);
        ASSERT(0);
        return 0;
    }

    context = (widget_ctk_dynamic_list_menu_struct*) ctk_screen_get_local_data(scrid);
    if (item_index < 0 || item_index >= context->num_items)
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_CTK_DYNAMIC_LIST_MENU_GET_HINT_HDLR_INDEX_ERROR, item_index, context->num_items);
        return 0;
    }

#ifdef WIDGET_TMPFIX_DYNAMIC_LIST
    if (!WIPC_CTX->WAP_is_waiting)  /* Not invoked from widget_paint() or ctk_invoke_redraw() */
    {
        ASSERT(WIDGET_IS_MMI_TASK());   /* Otherwise, deadlock */
        lock_mutex = KAL_TRUE;
    }

    if (lock_mutex)
    {
        widget_ctk_dynamic_list_menu_take_WAP_extq_lock();
    }

    context->callback_hint(item_index, context->arg_for_callback, (kal_uint8*) hint_array[0], MAX_SUB_MENU_HINT_SIZE);
    WAP_DBG_ASSERT(widget_ucs2_length((kal_uint8*) hint_array[0]) <= (MAX_SUB_MENU_HINT_SIZE / 2) - 1);

    if (lock_mutex)
    {
        widget_ctk_dynamic_list_menu_give_WAP_extq_lock();
    }
#else /* WIDGET_TMPFIX_DYNAMIC_LIST */ 
    context->callback_hint(item_index, context->arg_for_callback, (kal_uint8*) hint_array[0], MAX_SUB_MENU_HINT_SIZE);

#endif /* WIDGET_TMPFIX_DYNAMIC_LIST */ 

    if (CHR_AT(*hint_array, 0) == CHR(0))
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_CTK_DYNAMIC_LIST_MENU_GET_HINT_HDLR_STR_ERROR);
        return 0;
    }
    return 1;
}

/* Callback function of displaying Category9 */


/*****************************************************************************
 * FUNCTION
 *  widget_ctk_show_dynamic_list_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  layoutid        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_ctk_show_dynamic_list_menu(ctk_layout_handle layoutid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* 
     * This is very tricky!!
     * When we display dynamic list of MEA, it will use callback function in WAP and take a lot of time to show it.
     * In the mean time, WAP might receive another MMS message and it will update message list of MMS. 
     *
     * widget_paint_hdlr (WAP)  -> show message list (MMI)
     *                      (no race condition) 
     *
     * WAP receive new message (WAP) -> invoke redraw (MMI)
     *                      (no race condition It because WAP is blocked.)
     * 
     * Popup screen -> Go back to message list (MMI) -> show message list (MMI)
     *                            |- -> WAP receive new message -> invoke redraw again
     *                            As a result, we need to block WAP task here.
     *
     * User press down/up key down dynamic list menu (MMI) -> get new item (MMI)
     *                                    |- WAP might receive new message and update data here
     *
     */

    /*
     * Category
     * * 36 - fixed list, radio, with string (not string id)
     * * 140 - fixed list, checkbox, with string (not string id)
     * * 184 - Dynamic icontext menu
     */
    ctk_screen_handle scrid;
    widget_ctk_dynamic_list_menu_struct *context;
    ctk_string_id str1, str2;
    ctk_image_id img1, img2;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_CTK_DYNAMIC_LIST_MENU);

    scrid = ctk_layout_get_parent_screen(layoutid);
    context = (widget_ctk_dynamic_list_menu_struct*) ctk_screen_get_local_data(scrid);

    context->is_shown = 1;

    guiBuffer = ctk_pcategory_get_gui_buffer(layoutid);
    ctk_screen_get_LSK_label(scrid, &str1, &img1);
    ctk_screen_get_RSK_label(scrid, &str2, &img2);

    /* Use Category 184 to emulate radio list, otherwise we may have a very large list */
    ShowCategory184Screen(
        context->str_title,
        widget_get_title_icon(context->img_title),
        str1,
        img1,
        str2,
        img2,
        context->num_items,
        widget_ctk_dynamic_list_menu_get_item_hdlr,
        widget_ctk_dynamic_list_menu_get_hint_hdlr,
        context->highlighted,
        guiBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  widget_ctk_highlight_dynamic_list_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrid       [IN]        
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_ctk_highlight_dynamic_list_menu(ctk_screen_handle scrid, int index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_ctk_dynamic_list_menu_struct *context =
        (widget_ctk_dynamic_list_menu_struct*) ctk_screen_get_local_data(scrid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    context->highlighted = index;
}


/*****************************************************************************
 * FUNCTION
 *  widget_ctk_dynamic_list_menu_free_context
 * DESCRIPTION
 *  
 * PARAMETERS
 *  context     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_ctk_dynamic_list_menu_free_context(widget_ctk_dynamic_list_menu_struct *context)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_MEM_FREE(context->modId, context);
}


/*****************************************************************************
 * FUNCTION
 *  widget_ctk_dynamic_list_menu_on_post_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrid       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_ctk_dynamic_list_menu_on_post_close(ctk_screen_handle scrid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_ctk_dynamic_list_menu_struct *context =
        (widget_ctk_dynamic_list_menu_struct*) ctk_screen_get_local_data(scrid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    widget_ctk_dynamic_list_menu_free_context(context);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtCreateListMenuByCallback
 * DESCRIPTION
 *  Create dynamic radio(two-state) menu
 * PARAMETERS
 *  modId                   [IN]        
 *  str_title               [IN]        
 *  img_title               [IN]        
 *  num_items               [IN]        
 *  highlighted             [IN]        
 *  callback                [IN]        
 *  callback_hint           [IN]        
 *  arg_for_callback        [IN]         
 * RETURNS
 *  handle of the created MsfWindow
 *****************************************************************************/
MsfWindowHandle HDIa_widgetExtCreateListMenuByCallback(
                    MSF_UINT8 modId,
                    ctk_string_id str_title,
                    ctk_image_id img_title,
                    int num_items,
                    kal_uint16 highlighted,
                    widget_list_menu_callback callback,
                    widget_list_menu_hint_callback callback_hint,
                    void *arg_for_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_handle scrid;
    ctk_layout_handle layoutid;
    ctk_pcategory_create_struct layout_create;
    MsfWindowHandle ctk;
    widget_ctk_dynamic_list_menu_struct *context;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(widget_ctk_appid);

    /* Create CTK screen */
    scrid = widget_ctk_screen_create();
    ctk_screen_set_on_post_close_handler(scrid, widget_ctk_dynamic_list_menu_on_post_close);

    /* Set context */
    context = WIDGET_ALLOC_TYPE(modId, widget_ctk_dynamic_list_menu_struct);
    context->modId = modId;
    context->is_shown = 0;
    context->highlighted = (highlighted >= num_items) ? 0 : highlighted;
    context->str_title = str_title;
    context->img_title = img_title;
    context->num_items = num_items;
    context->callback = callback;
    context->callback_hint = callback_hint;
    context->arg_for_callback = arg_for_callback;
    ctk_screen_set_local_data(scrid, context);

    /* Create Layout */
    CTK_INIT_STRUCT(layout_create);
    layout_create.pcat_show_fp = widget_ctk_show_dynamic_list_menu;
    layout_create.pcat_highlight_fp = widget_ctk_highlight_dynamic_list_menu;
    layoutid = ctk_pcategory_create(widget_ctk_appid, &layout_create);

    ctk_screen_attach_layout(scrid, layoutid);

    /* create MsfWindow */
    ctk = HDIa_widgetCtkCreate(modId, scrid);
    _CTK(ctk)->ctk_predefined_type = WIDGET_CTK_PREDEFINED_DYNAMIC_LIST_MENU;
    return ctk;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtUpdateListMenuByCallback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  wnd                     [IN]        
 *  str_title               [IN]        
 *  img_title               [IN]        
 *  num_items               [IN]        
 *  highlighted             [IN]        
 *  callback                [IN]        
 *  callback_hint           [IN]        
 *  arg_for_callback        [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtUpdateListMenuByCallback(
        MsfWindowHandle wnd,
        ctk_string_id str_title,
        ctk_image_id img_title,
        int num_items,
        kal_uint16 highlighted,
        widget_list_menu_callback callback,
        widget_list_menu_hint_callback callback_hint,
        void *arg_for_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_handle scrid = HDIa_widgetCtkGetScreenHandle(wnd);
    widget_ctk_dynamic_list_menu_struct *context =
        (widget_ctk_dynamic_list_menu_struct*) ctk_screen_get_local_data(scrid);
    MSF_UINT8 modId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_UPDATE_LIST_MENU_CALLBACK);

    /* Free old context */
    ASSERT(context);
    modId = context->modId;
    widget_ctk_dynamic_list_menu_free_context(context);

    /* Set context */
    context = WIDGET_ALLOC_TYPE(modId, widget_ctk_dynamic_list_menu_struct);
    context->modId = modId;
    context->is_shown = 0;
    context->highlighted = (highlighted >= num_items) ? 0 : highlighted;
    context->str_title = str_title;
    context->img_title = img_title;
    context->num_items = num_items;
    context->callback = callback;
    context->callback_hint = callback_hint;
    context->arg_for_callback = arg_for_callback;
    ctk_screen_set_local_data(scrid, context);
}

/*************************************************************************
 * List menu (Common API)
 *************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtListMenuGetHilighted
 * DESCRIPTION
 *  Get the index of current highlighted menu item
 * PARAMETERS
 *  wnd     [IN]        
 * RETURNS
 *  index
 *****************************************************************************/
int HDIa_widgetExtListMenuGetHilighted(MsfWindowHandle wnd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_handle scrid = HDIa_widgetCtkGetScreenHandle(wnd);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (_CTK(wnd)->ctk_predefined_type == WIDGET_CTK_PREDEFINED_LIST_MENU)
    {
        widget_ctk_list_menu_struct *context = (widget_ctk_list_menu_struct*) ctk_screen_get_local_data(scrid);

        ASSERT(context);
        return context->highlighted;
    }
    else if (_CTK(wnd)->ctk_predefined_type == WIDGET_CTK_PREDEFINED_DYNAMIC_LIST_MENU)
    {
        widget_ctk_dynamic_list_menu_struct *context =
            (widget_ctk_dynamic_list_menu_struct*) ctk_screen_get_local_data(scrid);
        ASSERT(context);
        return context->highlighted;
    }
    else
    {
        WAP_DBG_ASSERT(0);
        return 0;
    }

}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtListMenuGetCount
 * DESCRIPTION
 *  
 * PARAMETERS
 *  wnd     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetExtListMenuGetCount(MsfWindowHandle wnd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_handle scrid = HDIa_widgetCtkGetScreenHandle(wnd);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (_CTK(wnd)->ctk_predefined_type == WIDGET_CTK_PREDEFINED_LIST_MENU)
    {
        widget_ctk_list_menu_struct *context = (widget_ctk_list_menu_struct*) ctk_screen_get_local_data(scrid);

        ASSERT(context);
        return context->num_items;
    }
    else if (_CTK(wnd)->ctk_predefined_type == WIDGET_CTK_PREDEFINED_DYNAMIC_LIST_MENU)
    {
        widget_ctk_dynamic_list_menu_struct *context =
            (widget_ctk_dynamic_list_menu_struct*) ctk_screen_get_local_data(scrid);
        ASSERT(context);
        return context->num_items;
    }
    else
    {
        WAP_DBG_ASSERT(0);
        return 0;
    }
}

/*************************************************************************
 * Message confirmation
 *************************************************************************/

typedef struct
{
    MSF_UINT8 modId;
    widget_string_pack_struct msg1;
    widget_string_pack_struct msg2;
    ctk_image_id image;
} widget_ctk_message_ind_struct;


/*****************************************************************************
 * FUNCTION
 *  widget_ctk_show_message_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  layoutid        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_ctk_show_message_ind(ctk_layout_handle layoutid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_handle scrid = ctk_layout_get_parent_screen(layoutid);
    widget_ctk_message_ind_struct *context = (widget_ctk_message_ind_struct*) ctk_screen_get_local_data(scrid);
    ctk_string_id str1, str2;
    ctk_image_id img1, img2;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    guiBuffer = ctk_pcategory_get_gui_buffer(layoutid);

    /* MMI categories typically require setting the softkey label before SetLeftSoftkeyFunction */
    ctk_screen_get_LSK_label(scrid, &str1, &img1);
    ctk_screen_get_RSK_label(scrid, &str2, &img2);

    ShowCategory154Screen(
        0,
        0,
        str1,
        img1,
        str2,
        img2,
        (PU8) widget_ctk_string_pack_get_data(&context->msg1),
        (PU8) widget_ctk_string_pack_get_data(&context->msg2),
        context->image,
        guiBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  widget_ctk_message_ind_on_post_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrid       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_ctk_message_ind_on_post_close(ctk_screen_handle scrid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_ctk_message_ind_struct *context = (widget_ctk_message_ind_struct*) ctk_screen_get_local_data(scrid);
    MSF_UINT8 modId = context->modId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    widget_ctk_free_string_pack(modId, &context->msg1);
    widget_ctk_free_string_pack(modId, &context->msg2);

    MSF_MEM_FREE(modId, context);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtCreateMessageInd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId       [IN]        
 *  msg1        [IN]        
 *  msg2        [IN]        
 *  img         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MsfWindowHandle HDIa_widgetExtCreateMessageInd(
                    MSF_UINT8 modId,
                    widget_string_pack_struct msg1,
                    widget_string_pack_struct msg2,
                    ctk_image_id img)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_handle scrid;
    ctk_layout_handle layoutid;
    ctk_pcategory_create_struct layout_create;
    MsfWindowHandle ctk;
    widget_ctk_message_ind_struct *context;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(widget_ctk_appid);

    /* Create CTK screen */
    scrid = widget_ctk_screen_create();
    ctk_screen_set_on_post_close_handler(scrid, widget_ctk_message_ind_on_post_close);

    /* Set context */
    context = MSF_MEM_ALLOC(modId, sizeof(widget_ctk_message_ind_struct));
    context->modId = modId;
    widget_ctk_copy_string_pack(modId, &context->msg1, &msg1);
    widget_ctk_copy_string_pack(modId, &context->msg2, &msg2);
    context->image = img;

    ctk_screen_set_local_data(scrid, context);

    /* Create Layout */
    CTK_INIT_STRUCT(layout_create);
    layout_create.pcat_show_fp = widget_ctk_show_message_ind;
    layoutid = ctk_pcategory_create(widget_ctk_appid, &layout_create);

    ctk_screen_attach_layout(scrid, layoutid);

    /* create MsfWindow */
    ctk = HDIa_widgetCtkCreate(modId, scrid);
    _CTK(ctk)->ctk_predefined_type = WIDGET_CTK_PREDEFINED_MESSAGE_IND;
    return ctk;
}

#if 0   /* Unused */
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

/*************************************************************************
 * Advanced SMIL editor
 *************************************************************************/

#ifdef WIDGET_ADVANCED_SMIL_EDITOR

typedef struct
{
    MSF_UINT8 modId;
    widget_string_pack_struct str_title1;
    widget_string_pack_struct str_title2;
    ctk_image_id img_title;
    kal_int16  input_type;
    MsfStringHandle text;
    kal_uint16 max_text_size;
    kal_uint16 flags;
    MsfImageHandle image;
    MsfImageHandle cached_image;
    kal_uint32 image_is_cached:1;
    kal_uint32 layout_is_formated:1;
    /* Whether Category275CheckIfModified() was invoked */
    kal_uint32 is_set_unmodified:1;
    /* Check if insert the text in MMS SMIL editor */
    kal_uint32 insert_test:1;

    /* The text is modified by MEA */
    kal_uint32 text_is_changed_external:1;
    /* Disable draw image in header/footer area */
    kal_uint32 disable_custom_draw_area:1;

    /* Layout data (widget_ctk_smil_editor_compute_layout) */
    kal_uint32 display_image:1;
    kal_uint32 resize_image:1;
    kal_uint32 is_video:1;
    kal_int16 vbar_width;
    kal_int16 draw_area_1_height;
    kal_int16 draw_area_2_height;
    kal_int16 icon1_x, icon2_x, icon3_x;    /* x-axis position of attachment/sound/image/video icon */
    kal_int16 icon_width, icon_height;
    /* Layout data of the image frame (widget_ctk_smil_editor_compute_layout) */
    kal_int16 icon_frame_x, icon_frame_y;   /* relative coordinate */
    kal_int16 icon_frame_width, icon_frame_height;
    kal_int16 image_frame_x, image_frame_y; /* relative coordinate */
    kal_int16 image_frame_width, image_frame_height;
    /* Layout data of the image (widget_ctk_smil_editor_compute_layout) */
    kal_int16 image_x, image_y;             /* relative coordinate */
    kal_int16 zoom_width, zoom_height;      /* 0 if not resized */
} widget_ctk_smil_editor_struct;



/* Deinitialization of internal data */
static kal_bool g_ctk_smil_change_slide = KAL_FALSE;
static widget_ctk_smil_editor_struct *g_ctk_smil_context = NULL;

/*
 * Display an image in MMI task. We do not use widget_show_animate_image_by_raw_data()
 * * in order to reduce dependence on WAP data structures 
 * * Clipping should be setup properly before this function.
 */


#ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING

/*****************************************************************************
 * FUNCTION
 *  widget_ctk_reset_smil_image_nb_draw_clip
 * DESCRIPTION
 *  reset the clip area to avoid draw nb_image at wrong place
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_ctk_reset_smil_image_nb_draw_clip(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    widget_ctk_nb_image.clip_x1 = 0;
    widget_ctk_nb_image.clip_y1 = 0; 
    widget_ctk_nb_image.clip_x2 = 0; 
    widget_ctk_nb_image.clip_y2 = 0;
}


/*****************************************************************************
 * FUNCTION
 *  widget_ctk_smil_image_nb_draw_done_callback
 * DESCRIPTION
 *  the callback function when decoding the image finish
 *
 * PARAMETERS
 *  result          [IN]        
 *  handle          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_ctk_smil_image_nb_draw_done_callback(GDI_RESULT result, gdi_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_CTK_SMIL_IMAGE_NB_DRAW_DONE_CALLBACK, result);

    if (result != GDI_SUCCEED)
    {

        memset(&widget_ctk_nb_image, 0, sizeof(widget_ctk_smil_nb_image_struct));
        return;
    }
    
    /* Set clipping */
    gui_push_clip();
    gui_set_clip(
        widget_ctk_nb_image.clip_x1,
        widget_ctk_nb_image.clip_y1, 
        widget_ctk_nb_image.clip_x2, 
        widget_ctk_nb_image.clip_y2);

    widget_ctk_show_image_from_cached_buffer(
        widget_ctk_nb_image.x,
        widget_ctk_nb_image.y,
        widget_ctk_nb_image.width,
        widget_ctk_nb_image.height,
        (U8*)g_widget_image_cache_buf);
    
    gui_pop_clip();
    if (WGUI_CTX->precache_nb_image_state != WIDGET_PRECACHE_NB_IMAEG_PROCESSING)
    {
        gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
    }
    if (g_widget_ctk_se_image_cache_layer)
    {
        gdi_layer_free(g_widget_ctk_se_image_cache_layer);
        g_widget_ctk_se_image_cache_layer = 0;
    }
    
    memset(&widget_ctk_nb_image, 0, sizeof(widget_ctk_smil_nb_image_struct));

    /* If we are in pre-cache non-blocking image drawing, we need to notify the caller */
    if (WGUI_CTX->precache_nb_image_state == WIDGET_PRECACHE_NB_IMAEG_PROCESSING)
    {
        /* pre-cache non-blocking image done */
        WGUI_CTX->precache_nb_image_state = WIDGET_PRECACHE_NB_IMAEG_NONE;
        WGUI_CTX->precache_nb_image_cb(KAL_TRUE);
        WGUI_CTX->precache_nb_image_cb = NULL;
    }/* if (WGUI_CTX->precache_nb_image_state == WIDGET_PRECACHE_NB_IMAEG_PROCESSING) */
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_CTK_SMIL_IMAGE_NB_DRAW_DONE_CALLBACK_END);

}

#endif /* #ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING */


/*****************************************************************************
 * FUNCTION
 *  widget_ctk_show_image
 * DESCRIPTION
 *  
 * PARAMETERS
 *  image               [IN]        
 *  x                   [IN]        
 *  y                   [IN]        
 *  zoom_width          [IN]        
 *  zoom_height         [IN]        
 *  resize_image        [IN]        
 *  is_nb_drawing       [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
static void
widget_ctk_show_image(MsfImageHandle image, S32 x, S32 y, S32 zoom_width, S32 zoom_height, kal_bool resize_image, kal_bool *is_nb_drawing)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *image_content;
#ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING
    S32 org_width = _IMG(image)->size.width;
    S32 org_height = _IMG(image)->size.height;
    kal_bool nb_draw = KAL_FALSE;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());

    *is_nb_drawing = KAL_FALSE;

    if (!image)
    {
        return;
    }

#ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING
    if ((WGUI_CTX->precache_nb_image_state == WIDGET_PRECACHE_NB_IMAEG_START) &&
        (org_width > WIDGET_IMAGE_WIDTH_LIMITATION || org_height > WIDGET_IMAGE_HEIGHT_LIMITATION))
    {
        /* execute async image drawing */
        widget_image_nb_draw_default(0, 0, zoom_width - 1, zoom_height - 1);

        nb_draw = KAL_TRUE;
        gdi_nb_set_blt(FALSE, FALSE);
        gdi_nb_set_done_callback(widget_ctk_smil_image_nb_draw_done_callback);
        if (widget_ctk_nb_image.handle)
        {
            gdi_image_nb_stop (widget_ctk_nb_image.handle);
            /* When stop non-blocking image drawing, we need to unlock the status bar rendering */
        }

    }
#endif /* #ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING */


    if ((image_content = (kal_uint8*) widget_image_content_file(image)) != NULL)
    {
        /* draw image file */
        S8 *full_name;

        full_name = (S8*) HDI_FileNameTranslate((const char*)image_content);
    #ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING

        if (nb_draw)
        {
            if (resize_image && zoom_width > 0 && zoom_height > 0)
            {
                widget_ctk_nb_image.handle = gdi_image_nb_draw_resized_file(0, 0, zoom_width, zoom_height, full_name);
            }
            else
            {
                widget_ctk_nb_image.handle = gdi_image_nb_draw_file(0, 0, full_name);
            }
            *is_nb_drawing = KAL_TRUE;
        }
        else
    #endif /* #ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING */

        {
            gdi_image_clear_work_buffer();
            if (resize_image && zoom_width > 0 && zoom_height > 0)
            {
                gdi_image_draw_resized_file(x, y, zoom_width, zoom_height, full_name);
            }
            else
            {
                gdi_image_draw_file(x, y, full_name);
            }
        }

        HDI_FileNameFree((kal_uint8*) full_name);
    }
    else if (IS_PRE_IMAGE_TYPE(image))
    {
        /* If the image is predefined image, WIMG_CTX->pre_image_cache_id will keeps resource image id */
        gdi_image_draw_id(x, y, WIMG_CTX->pre_image_cache_id);
    }
    else if ((image_content = (kal_uint8*) widget_image_content(image)) != NULL)
    {
        /* draw image buffer */
        int length = widget_image_length(image);
        MsfImageFormat format = widget_image_format(image);

    #ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING
        U8 image_id = widget_get_gdi_image_id(format);

        if (nb_draw && length > 0 && image_id != GDI_IMAGE_TYPE_INVALID)
        {
            if (resize_image && zoom_width > 0 && zoom_height > 0)
            {
                widget_ctk_nb_image.handle = gdi_image_nb_draw_resized( 0, 0, zoom_width, zoom_height, image_content); //image_id, length);
            }
            else
            {
                widget_ctk_nb_image.handle = gdi_image_nb_draw( 0, 0, image_content); //image_id, length);
            }
            *is_nb_drawing = KAL_TRUE;
        }
        else
    #endif /* #ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING */

        {
            gdi_image_clear_work_buffer();
            if (length > 0 && format != MsfUnsupportedMediaType)
            {
                if (resize_image && zoom_width > 0 && zoom_height > 0)
                {
                    gdi_image_draw_resized_ext(
                        x,
                        y,
                        zoom_width,
                        zoom_height,
                        image_content,
                        HDIa_widgetExtMsfToMMIImageFormat(format),
                        length);
                }
                else
                {
                    gdi_image_draw_ext(x, y, image_content, HDIa_widgetExtMsfToMMIImageFormat(format), length);
                }
            }
        }
    }
    else
    {
        WAP_DBG_ASSERT(0);
    }
    
#ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING
    if (WGUI_CTX->precache_nb_image_state == WIDGET_PRECACHE_NB_IMAEG_START)
    {
        if (*is_nb_drawing == KAL_TRUE)
        {
            /* need to pre-cache the non-blocking image */
            WGUI_CTX->precache_nb_image_state = WIDGET_PRECACHE_NB_IMAEG_PROCESSING;
        }
        else
        {
            /* pre-cache non-blocking image done */
            WGUI_CTX->precache_nb_image_state = WIDGET_PRECACHE_NB_IMAEG_DONE;        
        }
    }
#endif /* #ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING */
}

/* Show cached image */
#ifndef WIDGET_USE_LAYER_FLATTEN_WITH_CLIPPING


/*****************************************************************************
 * FUNCTION
 *  widget_ctk_show_image_from_cached_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x_offset        [IN]        
 *  y_offset        [IN]        
 *  width           [IN]        
 *  height          [IN]        
 *  buffer_ptr      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void
widget_ctk_show_image_from_cached_buffer(S32 x_offset, S32 y_offset, S32 width, S32 height, const U8 *buffer_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Reference: widget_MMI_show_precached_image() */
    S32 clip_x1, clip_y1, clip_x2, clip_y2;
    S32 x, y, y_multiple;
    U16 *buf = (U16*) buffer_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_get_clip(&clip_x1, &clip_y1, &clip_x2, &clip_y2);

    if ((clip_x2 < x_offset) || (clip_x1 > x_offset + width - 1) || (clip_y2 < y_offset) ||
        (clip_y1 > y_offset + height - 1))
    {
        return;
    }

    if (clip_x1 < x_offset)
    {
        clip_x1 = x_offset;
    }

    if (clip_y1 < y_offset)
    {
        clip_y1 = y_offset;
    }

    if (clip_x2 > x_offset + width - 1)
    {
        clip_x2 = x_offset + width - 1;
    }

    if (clip_y2 > y_offset + height - 1)
    {
        clip_y2 = y_offset + height - 1;
    }

    clip_x1 -= x_offset;
    clip_y1 -= y_offset;
    clip_x2 -= x_offset;
    clip_y2 -= y_offset;

    WAP_DBG_ASSERT(clip_x1 >= 0 && clip_y1 >= 0 && clip_x2 >= 0 && clip_y2 >= 0);

    for (y = clip_y1; y <= clip_y2; y++)
    {
        y_multiple = y * width;
        for (x = clip_x1; x <= clip_x2; x++)
        {
            GDI_SET_BUFFER_PIXEL2(x + x_offset, y + y_offset, buf[y_multiple + x]);
        }
    }
}

#else /* WIDGET_USE_LAYER_FLATTEN_WITH_CLIPPING */ 


/*****************************************************************************
 * FUNCTION
 *  widget_ctk_show_image_from_cached_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x_offset        [IN]        
 *  y_offset        [IN]        
 *  width           [IN]        
 *  height          [IN]        
 *  buffer_ptr      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void
widget_ctk_show_image_from_cached_buffer(S32 x_offset, S32 y_offset, S32 width, S32 height, const U8 *buffer_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Reference: widget_MMI_show_precached_image() */
    gdi_handle base_layer, cache_layer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_UNUSED(buffer_ptr);

    gdi_layer_get_base_handle(&base_layer);

    if (gdi_layer_create_using_outside_memory(
            x_offset,
            y_offset,
            width,
            height,
            &cache_layer,
            (U8*)g_widget_image_cache_buf,
            WIDGET_CTK_SE_IMAGE_CACHE_BUF_SIZE) != GDI_LAYER_SUCCEED)
    {
        WAP_BYPASS_ASSERT(0);
        return;
    }

    gdi_layer_flatten_with_clipping(base_layer, cache_layer, 0, 0);

    gdi_layer_free(cache_layer);
}

#endif /* WIDGET_USE_LAYER_FLATTEN_WITH_CLIPPING */ 

#define icon_frame_color   (gdi_act_color_from_rgb(100, 100, 100, 100))
#define image_frame_color  (gdi_act_color_from_rgb(100, 100, 100, 100))

/* Callback by MMI category 275 */


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_ctk_show_smil_editor_draw_title
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x1              [IN]        
 *  y1              [IN]        
 *  x2              [IN]        
 *  y2              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_MMI_ctk_show_smil_editor_draw_title(
                S32 x1,
                S32 y1,
                S32 x2,
                S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x_start;
    S32 len; 
    S32 str_title2_x_padding = 0;
    kal_int8 *str_title2 = NULL;
    S32 text_width, character_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_push_clip();
    gui_push_text_clip();
    gui_set_clip(x1, y1, x2, y2);
    gui_set_text_clip(x1, y1, x2, y2);

    gui_set_font(&MMI_small_font);

#if defined (WIDGET_SMIL_EDITOR_ICON_IN_INFO_BAR) || defined (__MMI_MAINLCD_128X128__) || defined (__MMI_MAINLCD_128X160__)
    /* 
     * In 128x128 and 128x160, MMS editor title font size will use MMI_small_font.
     * It avoid the title string1 and string2 overlap.
     * Both title string1 and string2 are drawed by widget_ctk
     */

    /* draw title string 1 */
    gui_measure_string(
        (UI_string_type) widget_ctk_string_pack_get_data(&g_ctk_smil_context->str_title1),
        &text_width,
        &character_height);
    if (r2lMMIFlag)
    {
        x_start = (x2 - x1) / 2 + text_width / 2;
    }
    else
    {
        x_start = (x2 - x1) / 2 - text_width / 2;
    }
    gui_move_text_cursor(x_start, y1 + (( (y2 - y1) - character_height) >> 1));
    gui_set_text_color(*current_MMI_theme->title_text_color);
    gui_print_text((UI_string_type) widget_ctk_string_pack_get_data(&g_ctk_smil_context->str_title1));

#endif /* defined (__MMI_MAINLCD_128X128__) || defined (__MMI_MAINLCD_128X160__) */ 

    /* draw title string 2 */
    str_title2 = (kal_int8*)widget_ctk_string_pack_get_data(&g_ctk_smil_context->str_title2);

    /* If title string 2 has ' ' at the end, we remove it. */
    len = app_ucs2_strlen((const kal_int8*)str_title2);
    while (len > 0 && str_title2[2 * (len-1)] == L' ')
    {
        memset(&str_title2[2 * (len-1)], 0, 2);
        len = app_ucs2_strlen((const kal_int8*)str_title2);
    }
    gui_measure_string(
        (UI_string_type) str_title2,
        &text_width,
        &character_height);

#if defined (WIDGET_SMIL_EDITOR_ICON_IN_INFO_BAR)
    if (r2lMMIFlag)
    {
        x_start = (x2 - x1) / 4 + text_width / 2;
    }
    else
    {
        x_start = (x2 - x1) / 4 * 3 - text_width / 2;
    }
#else
    
#if defined (__MMI_MAINLCD_128X128__) || defined (__MMI_MAINLCD_128X160__)
    str_title2_x_padding = 2;
#else
    str_title2_x_padding = 4;
#endif

    if (r2lMMIFlag)
    {
        /* reserve the padding */
        x_start = str_title2_x_padding + text_width;
    }
    else
    {
        /* reserve the padding */
        x_start = x2 - str_title2_x_padding - text_width;
    }
#endif


    gui_move_text_cursor(x_start, y1 + (((y2 - y1) - character_height) >> 1));
    gui_set_text_color(*current_MMI_theme->title_text_color);
    gui_print_text((UI_string_type) widget_ctk_string_pack_get_data(&g_ctk_smil_context->str_title2));
    gui_set_font(&MMI_medium_font);

    gui_pop_text_clip();
    gui_pop_clip();

}

    
/*****************************************************************************
 * FUNCTION
 *  widget_MMI_ctk_show_smil_editor_title
 * DESCRIPTION
 *  
 * PARAMETERS
 *  identifier      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_MMI_ctk_show_smil_editor_title(U32 identifier)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_handle scrid;
    widget_ctk_smil_editor_struct *context;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined (WIDGET_SMIL_EDITOR_ICON_IN_INFO_BAR)
    /* fullscreen editor doesn't have the status/title bar in landscape MMI (320x240) */
    return;
#endif

    if (!identifier || !IS_CTK_TYPE(identifier)
        || _CTK(identifier)->ctk_predefined_type != WIDGET_CTK_PREDEFINED_SMIL_EDITOR)
    {
        WAP_DBG_ASSERT(0);
        return;
    }
    scrid = HDIa_widgetCtkGetScreenHandle((MsfWindowHandle) identifier);
    /* reset_multitaps might redraw inputbox again */
    /* WAP_DBG_ASSERT(ctk_screen_get_current_state(scrid) == CTK_SCREEN_STATE_ACTIVE); */
    context = (widget_ctk_smil_editor_struct*) ctk_screen_get_local_data(scrid);

#if defined (__MMI_MAINLCD_128X128__) || defined (__MMI_MAINLCD_128X160__)
    /* 
     * In 128x128 and 128x160, MMS editor title font size will use MMI_small_font.
     * It avoid the title string1 and string2 overlap.
     */
    MMI_title_string = NULL;
#else /* defined (__MMI_MAINLCD_128X128__) || defined (__MMI_MAINLCD_128X160__) */ 
    MMI_title_string = (UI_string_type) widget_ctk_string_pack_get_data(&context->str_title1);
#endif /* defined (__MMI_MAINLCD_128X128__) || defined (__MMI_MAINLCD_128X160__) */ 
    MMI_title_icon = (PU8) get_image(widget_get_title_icon(context->img_title));

#ifdef WIDGET_RESIDENT_STATUS_ICON
    show_title_status_icon();
#endif
    draw_title();

    widget_MMI_ctk_show_smil_editor_draw_title(
        MMI_title_x, 
        MMI_title_y, 
        MMI_title_x + MMI_title_width - 1, 
        MMI_title_y + MMI_title_height - 1);
}




/*****************************************************************************
 * FUNCTION
 *  widget_MMI_ctk_show_smil_editor_draw_icon_area
 * DESCRIPTION
 *  
 * PARAMETERS
 *  identifier      [IN]        
 *  y_offset        [IN]        
 *  x1              [IN]        
 *  y1              [IN]        
 *  x2              [IN]        
 *  y2              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_MMI_ctk_show_smil_editor_draw_icon_area(
                S32 y_offset,
                S32 x1,
                S32 y1,
                S32 x2,
                S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 _x1, _y1;
    S32 icon_num = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Set clipping */
    gui_push_clip();
    gui_set_clip(x1, y1, x2, y2);

    /* draw the background of the icon */
#if defined (WIDGET_SMIL_EDITOR_ICON_IN_INFO_BAR)
    /* draw attachment/sound/image/video icon */
    _y1 = y1 + SE_PADDING_V_SPACE;
#else

    if (!r2lMMIFlag)
    {
        gdi_draw_solid_rect(
            g_ctk_smil_context->icon_frame_x,
            y_offset + g_ctk_smil_context->icon_frame_y,
            g_ctk_smil_context->icon_frame_x + g_ctk_smil_context->icon_frame_width,
            y_offset + g_ctk_smil_context->icon_frame_y + g_ctk_smil_context->icon_frame_height,
            icon_frame_color);
    }
    else
    {
        gdi_draw_solid_rect(
            x1 + SE_PADDING_H_SPACE,
            y_offset + g_ctk_smil_context->icon_frame_y,
            x2 - SE_PADDING_H_SPACE,
            y_offset + g_ctk_smil_context->icon_frame_y + g_ctk_smil_context->icon_frame_height,
            icon_frame_color);
    }

    /* draw attachment/sound/image/video icon */
    _y1 = y_offset + SE_PADDING_V_SPACE;
#endif /* #if !defined (WIDGET_SMIL_EDITOR_ICON_IN_INFO_BAR) */

    /* draw attachment/sound/image/video icon */
    _x1 = g_ctk_smil_context->icon1_x;

    if (g_ctk_smil_context->flags & WIDGET_SMIL_EDITOR_FLAG_ATTACHMENT)
    {
        gui_show_image(_x1, _y1, (PU8) GetImage(MEA_IMG_SMIL_EDITOR_ATTACHMENT));
        icon_num++;
        _x1 = g_ctk_smil_context->icon2_x;
    }
    if (g_ctk_smil_context->flags & WIDGET_SMIL_EDITOR_FLAG_AUDIO)
    {
        gui_show_image(_x1, _y1, (PU8) GetImage(MEA_IMG_AUDIO));
        icon_num++;
        if (icon_num == 1)
        {
            _x1 = g_ctk_smil_context->icon2_x;
        }
        else if (icon_num == 2)
        {

            _x1 = g_ctk_smil_context->icon3_x;
        }
    }
    if (g_ctk_smil_context->display_image)
    {
        U16 frame_icon = (g_ctk_smil_context->is_video) ? MEA_IMG_SMIL_EDITOR_VIDEO_ICON : MEA_IMG_SMIL_EDITOR_PIC_ICON;

        /* draw image/video icon */
        gui_show_image(_x1, _y1, (PU8) GetImage(frame_icon));
    }
    gui_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_ctk_show_smil_editor_draw_area_1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  identifier      [IN]        
 *  y_offset        [IN]        
 *  clip_x1         [IN]        
 *  clip_y1         [IN]        
 *  clip_x2         [IN]        
 *  clip_y2         [IN]        
 *  is_draw         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_MMI_ctk_show_smil_editor_draw_area_1(
                U32 identifier,
                S32 y_offset,
                S32 clip_x1,
                S32 clip_y1,
                S32 clip_x2,
                S32 clip_y2,
                kal_bool is_draw)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_handle scrid;
    widget_ctk_smil_editor_struct *context;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_UNUSED(clip_x1);

    if (is_draw == KAL_FALSE)
    {
    #ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING
        if (widget_ctk_nb_image.image_in_top == KAL_TRUE)
        {
            widget_ctk_reset_smil_image_nb_draw_clip();
        }
    #endif
        return;
    }

    if (!identifier || !IS_CTK_TYPE(identifier)
        || _CTK(identifier)->ctk_predefined_type != WIDGET_CTK_PREDEFINED_SMIL_EDITOR)
    {
        WAP_DBG_ASSERT(0);
        return;
    }
    scrid = HDIa_widgetCtkGetScreenHandle((MsfWindowHandle) identifier);
    /* reset_multitaps might redraw inputbox again */
    /* WAP_DBG_ASSERT(ctk_screen_get_current_state(scrid) == CTK_SCREEN_STATE_ACTIVE); */
    context = (widget_ctk_smil_editor_struct*) ctk_screen_get_local_data(scrid);

    if (context->disable_custom_draw_area)
    {
        return;
    }

    if ((context->display_image) ||
        (context->flags & WIDGET_SMIL_EDITOR_FLAG_ATTACHMENT) || (context->flags & WIDGET_SMIL_EDITOR_FLAG_AUDIO))
    {
    #if !defined (WIDGET_SMIL_EDITOR_ICON_IN_INFO_BAR)
        widget_MMI_ctk_show_smil_editor_draw_icon_area(
            y_offset,
            clip_x1,
            clip_y1,
            clip_x2,
            clip_y2);
    #endif

        gui_push_clip();
        gui_set_clip(clip_x1, clip_y1, clip_x2, clip_y2);
        
        /* Show image area */
        if (context->display_image && !(context->flags & WIDGET_SMIL_EDITOR_FLAG_IMAGE_ON_BOTTOM))
        {

            /*
             * draw the frame of the image/video
             * Because clip_x1, x2, y1, y2 are assigned by editor component,
             * we need to config the x coordination of the rectangle.
             */
            if (!r2lMMIFlag)
            {
                gdi_draw_rect(
                    context->image_frame_x,
                    y_offset + context->image_frame_y,
                    context->image_frame_x + context->image_frame_width,
                    y_offset + context->image_frame_y + context->image_frame_height,
                    image_frame_color);
            }
            else
            {
                gdi_draw_rect(
                    clip_x1 + SE_PADDING_H_SPACE,
                    y_offset + context->image_frame_y,
                    clip_x2 - SE_PADDING_H_SPACE,
                    y_offset + context->image_frame_y + context->image_frame_height,
                    image_frame_color);

                if ((clip_x2 - clip_x1 - SE_PADDING_H_SPACE*2) >= context->zoom_width)
                {
                    context->image_x = clip_x1 + SE_PADDING_H_SPACE + ((clip_x2 - clip_x1 - SE_PADDING_H_SPACE*2) - context->zoom_width)/2;
                }
            }

        #ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING
            widget_ctk_nb_image.clip_x1 = clip_x1;
            widget_ctk_nb_image.clip_y1 = clip_y1;
            widget_ctk_nb_image.clip_x2 = clip_x2;
            widget_ctk_nb_image.clip_y2 = clip_y2;
            widget_ctk_nb_image.x = context->image_x;
            widget_ctk_nb_image.y = y_offset + context->image_y;
            widget_ctk_nb_image.width = context->zoom_width;
            widget_ctk_nb_image.height = context->zoom_height;
            widget_ctk_nb_image.image_in_top = KAL_TRUE;
        #endif /* #ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING */

            if (g_widget_image_cache_buf)
            {
                /*
                 * We need to check cache buffer pointer here.
                 * Because Ctk will free image cache buffer first and then execute UI_common_screen_exit(),
                 * this callback function may be invoked in UI_common_screen_exit().
                 */
                widget_ctk_show_image_from_cached_buffer(
                    context->image_x,
                    y_offset + context->image_y,
                    context->zoom_width,
                    context->zoom_height,
                    (U8*)g_widget_image_cache_buf);
            }
        }
        gui_pop_clip();
    }

}


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_ctk_show_smil_editor_draw_area_2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  identifier      [IN]        
 *  y_offset        [IN]        
 *  clip_x1         [IN]        
 *  clip_y1         [IN]        
 *  clip_x2         [IN]        
 *  clip_y2         [IN]        
 *  is_draw         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_MMI_ctk_show_smil_editor_draw_area_2(
                U32 identifier,
                S32 y_offset,
                S32 clip_x1,
                S32 clip_y1,
                S32 clip_x2,
                S32 clip_y2,
                kal_bool is_draw)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_handle scrid;
    widget_ctk_smil_editor_struct *context;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_draw == KAL_FALSE)
    {
    #ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING
        if (widget_ctk_nb_image.image_in_top == KAL_FALSE)
        {
            widget_ctk_reset_smil_image_nb_draw_clip();
        }
    #endif
        return;
    }

    if (!identifier || !IS_CTK_TYPE(identifier)
        || _CTK(identifier)->ctk_predefined_type != WIDGET_CTK_PREDEFINED_SMIL_EDITOR)
    {
        WAP_DBG_ASSERT(0);
        return;
    }
    scrid = HDIa_widgetCtkGetScreenHandle((MsfWindowHandle) identifier);
    /* reset_multitaps might redraw inputbox again */
    /* WAP_DBG_ASSERT(ctk_screen_get_current_state(scrid) == CTK_SCREEN_STATE_ACTIVE); */
    context = (widget_ctk_smil_editor_struct*) ctk_screen_get_local_data(scrid);

    if (!context->display_image ||
        context->draw_area_2_height == 0 || !(context->flags & WIDGET_SMIL_EDITOR_FLAG_IMAGE_ON_BOTTOM))
    {
        return;
    }

    if (context->disable_custom_draw_area)
    {
        return;
    }

    gui_push_clip();
    gui_set_clip(clip_x1, clip_y1, clip_x2, clip_y2);

    /*
     * draw the frame of the image/video
     * Because clip_x1, x2, y1, y2 are assigned by editor component,
     * we need to config the x coordination of the rectangle.
     */
    if (!r2lMMIFlag)
    {
        gdi_draw_rect(
            context->image_frame_x,
            y_offset + context->image_frame_y,
            context->image_frame_x + context->image_frame_width,
            y_offset + context->image_frame_y + context->image_frame_height,
            image_frame_color);
    }
    else
    {
        gdi_draw_rect(
            clip_x1 + SE_PADDING_H_SPACE,
            y_offset + context->image_frame_y,
            clip_x2 - SE_PADDING_H_SPACE,
            y_offset + context->image_frame_y + context->image_frame_height,
            image_frame_color);

        if ((clip_x2 - clip_x1 - SE_PADDING_H_SPACE*2) >= context->zoom_width)
        {
            context->image_x = clip_x1 + SE_PADDING_H_SPACE + ((clip_x2 - clip_x1 - SE_PADDING_H_SPACE*2) - context->zoom_width)/2;
        }
    }

#ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING
    widget_ctk_nb_image.clip_x1 = clip_x1;
    widget_ctk_nb_image.clip_y1 = clip_y1;
    widget_ctk_nb_image.clip_x2 = clip_x2;
    widget_ctk_nb_image.clip_y2 = clip_y2;
    widget_ctk_nb_image.x = context->image_x;
    widget_ctk_nb_image.y = y_offset + context->image_y;
    widget_ctk_nb_image.width = context->zoom_width;
    widget_ctk_nb_image.height = context->zoom_height;
    widget_ctk_nb_image.image_in_top = KAL_FALSE;
#endif /* #ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING */

    if (g_widget_image_cache_buf)
    {
        /*
         * We need to check cache buffer pointer here.
         * Because Ctk will free image cache buffer first and then execute UI_common_screen_exit(),
         * this callback function may be invoked in UI_common_screen_exit().
         */
        widget_ctk_show_image_from_cached_buffer(
            context->image_x,
            y_offset + context->image_y,
            context->zoom_width,
            context->zoom_height,
            (U8*)g_widget_image_cache_buf);
    }

    gui_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  widget_ctk_smil_editor_icon_layout_and_get_height
 * DESCRIPTION
 *  
 * PARAMETERS
 *  context         [IN]        
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 widget_ctk_smil_editor_icon_layout_and_get_height(widget_ctk_smil_editor_struct *context)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 img_width = 0, img_height = 0;
    S32 icon_area_height = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_measure_image((PU8) GetImage(MEA_IMG_AUDIO), &img_width, &img_height);
    WAP_DBG_ASSERT(img_width > 0 && img_height > 0);
    context->icon_width = (kal_int16) img_width;
    context->icon_height = (kal_int16) img_height;

#if defined (WIDGET_SMIL_EDITOR_ICON_IN_INFO_BAR)
    /* draw icons in editor's information bar */
    context->icon_frame_y = 0;
    context->icon_frame_width = MMI_content_width - (context->vbar_width + SE_PADDING_H_SPACE * 2);
    context->icon_frame_height = 0;
#else
    context->icon_frame_y = SE_PADDING_V_SPACE / 2;
    context->icon_frame_width = MMI_content_width - (context->vbar_width + SE_PADDING_H_SPACE * 2);
    context->icon_frame_height = context->icon_height + SE_PADDING_V_SPACE;

    if ((context->image != 0) ||
        (context->flags & WIDGET_SMIL_EDITOR_FLAG_AUDIO) || (context->flags & WIDGET_SMIL_EDITOR_FLAG_ATTACHMENT))
    {
        icon_area_height = context->icon_height + SE_PADDING_V_SPACE * 2;
    }
#endif

    if (!r2lMMIFlag)
    {
        context->icon_frame_x = SE_PADDING_H_SPACE;
        context->icon1_x = SE_PADDING_H_START_SPACE + SE_PADDING_H_SPACE;
        context->icon2_x = context->icon1_x + context->icon_width + SE_PADDING_H_SPACE;
        context->icon3_x = context->icon2_x + context->icon_width + SE_PADDING_H_SPACE;
    }
    else
    {
        context->icon_frame_x = SE_PADDING_H_SPACE + context->vbar_width;
        /* (tricky) In right-to-left style, editor component will adjust the visual width */
        context->icon1_x = MMI_content_width - SE_PADDING_H_START_SPACE - SE_PADDING_H_SPACE * 2 - context->icon_width;
        context->icon2_x = context->icon1_x - SE_PADDING_H_SPACE - context->icon_width;
        context->icon3_x = context->icon2_x - SE_PADDING_H_SPACE - context->icon_width;
    }

    /* return height of icon area */
    return icon_area_height;
}


/*****************************************************************************
 * FUNCTION
 *  widget_ctk_smil_editor_compute_layout
 * DESCRIPTION
 *  
 * PARAMETERS
 *  context     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_ctk_smil_editor_compute_layout(widget_ctk_smil_editor_struct *context)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 img_width = 0, img_height = 0;
    S32 icon_area_height = 0;
    S32 zoom_x = 0, zoom_y = 0, zoom_width = 0, zoom_height = 0;
    S32 width_bound = 0, height_bound = 0;  /* Upper bound of image width/height (if no icon area present) */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    context->vbar_width = current_MMI_theme->scrollbar_size;

    /* Compute the size/position */
    icon_area_height = widget_ctk_smil_editor_icon_layout_and_get_height(context);

    context->image_frame_x = context->icon_frame_x;
    context->image_frame_width = context->icon_frame_width;
    if (context->image != 0)
    {
        img_height = widget_image_height(context->image);
        img_width = widget_image_width(context->image);
        width_bound = MMI_content_width - (context->vbar_width + SE_PADDING_H_SPACE) * 4;
        height_bound = MMI_content_height - context->icon_height - SE_EDITOR_MIN_HEIGHT - SE_PADDING_V_SPACE * 4;
    }
    /* Compute size/position of image area */
    if (context->image == 0)
    {
        context->display_image = 0;
        context->draw_area_1_height = icon_area_height;
        context->draw_area_2_height = 0;
    }
    else if (context->flags & WIDGET_SMIL_EDITOR_FLAG_IMAGE_ON_BOTTOM)  /* Image on bottom. Icons on Top */
    {
        /* Image on bottom. Icons on Top */
        context->display_image = 1;
        context->draw_area_1_height = icon_area_height;

        if (img_width < width_bound && img_height < height_bound)
        {
            context->zoom_width = img_width;
            context->zoom_height = img_height;
            context->resize_image = 0;
        }
        else
        {
            gdi_image_util_fit_bbox(
                width_bound,
                height_bound,
                img_width,
                img_height,
                &zoom_x,
                &zoom_y,
                &zoom_width,
                &zoom_height);
            zoom_width = (zoom_width) ? zoom_width : 1;
            zoom_height = (zoom_height) ? zoom_height : 1;
            context->zoom_width = zoom_width;
            context->zoom_height = zoom_height;
            context->resize_image = 1;
        }
        context->image_frame_y = SE_PADDING_V_SPACE / 2;
        context->image_frame_height = context->zoom_height + SE_PADDING_V_SPACE * 2;
        context->image_x = context->image_frame_x + ((context->image_frame_width - context->zoom_width) >> 1);
        context->image_y = context->image_frame_y + ((context->image_frame_height - context->zoom_height) >> 1);
        context->draw_area_2_height = context->image_frame_height + SE_PADDING_V_SPACE;

    }
    else    /* Image and icons both on top */
    {
        /* Image and icons both on top */
        context->display_image = 1;
        context->draw_area_2_height = 0;

        if (img_width < width_bound && img_height < height_bound)
        {
            context->zoom_width = img_width;
            context->zoom_height = img_height;
            context->resize_image = 0;
        }
        else
        {
            gdi_image_util_fit_bbox(
                width_bound,
                height_bound,
                img_width,
                img_height,
                &zoom_x,
                &zoom_y,
                &zoom_width,
                &zoom_height);
            zoom_width = (zoom_width) ? zoom_width : 1;
            zoom_height = (zoom_height) ? zoom_height : 1;
            context->zoom_width = zoom_width;
            context->zoom_height = zoom_height;
            context->resize_image = 1;
        }
        context->image_frame_y = context->icon_frame_y + context->icon_frame_height;
        context->image_frame_height = context->zoom_height + SE_PADDING_V_SPACE * 2;
        context->image_x = context->image_frame_x + ((context->image_frame_width - context->zoom_width) >> 1);
        context->image_y = context->image_frame_y + ((context->image_frame_height - context->zoom_height) >> 1);
        context->draw_area_1_height = context->icon_frame_height + context->image_frame_height + SE_PADDING_V_SPACE;
    }

    g_ctk_smil_context = context;
}

/* Cache image */


/*****************************************************************************
 * FUNCTION
 *  widget_ctk_smil_editor_cache_image
 * DESCRIPTION
 *  
 * PARAMETERS
 *  context     [IN]     
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool widget_ctk_smil_editor_cache_image(widget_ctk_smil_editor_struct *context)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool is_nb_drawing = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (context->zoom_width * context->zoom_height * (GDI_MAINLCD_BIT_PER_PIXEL >> 3) >
        WIDGET_CTK_SE_IMAGE_CACHE_BUF_SIZE)
    {
        WAP_BYPASS_ASSERT(0);
        return KAL_FALSE;
    }
    if(g_widget_ctk_se_image_cache_layer)
    {
        gdi_layer_free(g_widget_ctk_se_image_cache_layer);
    }

    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_CTK_SMIL_EDITOR_CACHE_IMAGE);
    if (gdi_layer_create_using_outside_memory(
            0,
            0,
            context->zoom_width,
            context->zoom_height,
            &g_widget_ctk_se_image_cache_layer,
            (U8*)g_widget_image_cache_buf,
            WIDGET_CTK_SE_IMAGE_CACHE_BUF_SIZE) != GDI_LAYER_SUCCEED)
    {
        WAP_BYPASS_ASSERT(0);
        return KAL_FALSE;
    }

    gdi_layer_push_and_set_active(g_widget_ctk_se_image_cache_layer);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_set_clip(0, 0, context->zoom_width - 1, context->zoom_height - 1);

    /* Fill the background in case that the image is truncated */
#ifdef __MMI_WALLPAPER_ON_BOTTOM__
    gdi_draw_solid_rect(0, 0, context->zoom_width - 1, context->zoom_height - 1, GDI_COLOR_TRANSPARENT);
#else
    gdi_draw_solid_rect(0, 0, context->zoom_width - 1, context->zoom_height - 1, GDI_COLOR_WHITE);
#endif
    if (_IMG(context->image)->video_in_preview == 1)
    {
    #ifdef __MMI_VIDEO_PLAYER__
        char *video_fname;
        MDI_RESULT mdi_ret;
        mdi_video_info_struct video_clip = {0};
    #endif /* #ifdef __MMI_VIDEO_PLAYER__ */

        WAP_DBG_ASSERT(_IMG(context->image)->is_done);
        WAP_DBG_ASSERT(WGUI_CTX->current_video_state != WIDGET_VIDEO_PLAYING ||
                       WGUI_CTX->current_video_state != WIDGET_VIDEO_PLAYING_OUT_OF_LCD);

        context->is_video = 1;
        /* draw the video first frame */
    #ifdef __MMI_VIDEO_PLAYER__
        video_fname = (char*)HDI_FileNameTranslate(widget_image_content_file(context->image));
        /* Because mdi_api is designed for MMI task, we need to call mdi_api in MMI thread */
        mdi_ret = mdi_video_ply_open_clip_file((const S8*)video_fname, &video_clip);
        if (mdi_ret == MDI_RES_VDOPLY_SUCCEED)
        {
            /* draw the first frame of the video */
            mdi_video_ply_seek_and_get_frame((U64) 0, g_widget_ctk_se_image_cache_layer);
            mdi_video_ply_close_clip_file();
        }
        HDI_FileNameFree((kal_uint8*) video_fname);
    #endif /* __MMI_VIDEO_PLAYER__ */ /* #ifdef __MMI_VIDEO_PLAYER__ */

        WGUI_CTX->current_video_state = WIDGET_VIDEO_PREVIEW;
    }
    else
    {
        widget_ctk_show_image(
            context->image,
            0,
            0,
            context->zoom_width,
            context->zoom_height,
            context->resize_image ? KAL_TRUE : KAL_FALSE,
            &is_nb_drawing);
    }

    gdi_layer_pop_and_restore_active();
    if (is_nb_drawing == KAL_FALSE)
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_CTK_SMIL_EDITOR_CACHE_IMAGE_FREE_LAYER);
        gdi_layer_free(g_widget_ctk_se_image_cache_layer);
        g_widget_ctk_se_image_cache_layer = 0;
    }

    /* update context information */
    context->image_is_cached = 1;
    context->cached_image = context->image;

    return KAL_TRUE;
}


#if defined (WIDGET_SMIL_EDITOR_ICON_IN_INFO_BAR)
/*****************************************************************************
 * FUNCTION
 *  widget_MMI_ctk_show_smil_editor_infobar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x1              [IN]        
 *  y1              [IN]        
 *  x2              [IN]        
 *  y2              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_MMI_ctk_show_smil_editor_infobar(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /* Clear the background and draw input method and remaining char info. */
    wgui_input_information_background(x1, y1, x2, y2);
    wgui_multiline_inputbox_show_current_input_method(x1,y1,x2,y2);
    wgui_redraw_remaining_characters_display();

    /* Draw icon, title, size info. of MMS editor */
    widget_MMI_ctk_show_smil_editor_draw_title(x1, y1, x2, y2);
    widget_MMI_ctk_show_smil_editor_draw_icon_area(0, x1, y1, x2, y2);
}
#endif /* #if defined (WIDGET_SMIL_EDITOR_ICON_IN_INFO_BAR) */


/* Main routine for show Smil Editor */
/*****************************************************************************
 * FUNCTION
 *  widget_ctk_show_smil_editor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  layoutid        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_ctk_show_smil_editor(ctk_layout_handle layoutid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_handle scrid = ctk_layout_get_parent_screen(layoutid);
    widget_ctk_smil_editor_struct *context = (widget_ctk_smil_editor_struct*) ctk_screen_get_local_data(scrid);
    ctk_string_id str1, str2;
    ctk_image_id img1, img2;
    U8 *guiBuffer;
    kal_bool adjust_editor_cursor = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Setup category */
    if (g_ctk_smil_change_slide)
    {
        /* If Changing the slide, we use the new screen */
        guiBuffer = NULL;
    }
    else
    {
        guiBuffer = ctk_pcategory_get_gui_buffer(layoutid);
    }

    if (!context->layout_is_formated /* Image is inserted or removed */  ||
        (!guiBuffer && context->image) /* Initially displayed with image */ )
    {
        /* Scroll the editor to display the whole image */
        adjust_editor_cursor = KAL_TRUE;
    }

    /* always execute SMIL editor layout process */
    widget_ctk_smil_editor_compute_layout(context);
    context->layout_is_formated = 1;
    if (context->cached_image != context->image)
    {
        context->image_is_cached = 0;
    }

#ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING
    /*
     * We don't need to release g_widget_image_cache_buf,
     * it is the global buffer
     */
#else
    if (context->image && g_widget_image_cache_buf == NULL)
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_CTK_SMIL_ALLOC_SCRMEM);
        /* Screen-base memory */
        g_widget_image_cache_buf = (U8*)mmi_frm_scrmem_alloc(WIDGET_CTK_SE_IMAGE_CACHE_BUF_SIZE);
        WAP_DBG_ASSERT(g_widget_image_cache_buf != NULL);
        /* When exit the current ctk screen, we need to free the screen-base memory */
        HDIa_widgetCtkSetFlag((MsfWindowHandle) ctk_screen_get_msf_window(scrid), WIDGET_CTK_SMIL_EDITOR_USING_SCRN_MEM);
    }
#endif
#ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING
    /* The application will precache the image first, we need to check the image was cached */
    if (!context->image_is_cached && context->display_image)
#else
    /* We need to cache the image every time when entering MMS SMIL editor */
    if (context->display_image)
#endif /* WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING */
    {
        if (!widget_ctk_smil_editor_cache_image(context))
        {
            /* don't need to cache the image, set display_image to 0 */
            context->display_image = 0;
        }
    }

    /* MMI categories typically require setting the softkey label before SetLeftSoftkeyFunction */
    ctk_screen_get_LSK_label(scrid, &str1, &img1);
    ctk_screen_get_RSK_label(scrid, &str2, &img2);

    /* 
     * If the layout is changed (typically when image is inserted/removed),
     * the text_offset_y in history data might be out-of-range.
     *
     * If the image is on the top, we scroll the editor to the top.
     * Otherwise, we scroll the editor to the bottom.
     *
     * Note: we invoked gui_show_multi_line_input_box more than one time, 
     * the performance could be improved with caution in the future.
     */
    if (adjust_editor_cursor)
    {
        gui_lock_double_buffer();
        /* 
         * Because we shall redraw the inputbox after ShowCategory275Screen() 
         * we do not need to draw header/footer area.
         */
        context->disable_custom_draw_area = 1;
    }

    if (!context->is_set_unmodified)
    {
        Category275SetUnmodified();
        context->is_set_unmodified = 1;
    }

#ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING
    widget_ctk_reset_smil_image_nb_draw_clip();
#endif /* #ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING */

    ShowCategory275Screen(
        (U32) HDIa_widgetCtkGetWindow(scrid),
        str1,
        img1,
        str2,
        img2,
        context->input_type,
        widget_string_content(context->text),
        context->max_text_size + 1,
        (U16) context->vbar_width,
        widget_MMI_ctk_show_smil_editor_title,
        (U16) context->draw_area_1_height,
        (wgui_cat275_draw_area_hdlr)widget_MMI_ctk_show_smil_editor_draw_area_1,
        (U16) context->draw_area_2_height,
        (wgui_cat275_draw_area_hdlr)widget_MMI_ctk_show_smil_editor_draw_area_2,
        guiBuffer);

    g_ctk_smil_change_slide = KAL_FALSE;
    if (adjust_editor_cursor)
    {
        context->disable_custom_draw_area = 0;

    #ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING
        /* need to reset nb_draw_clip when adjust the cursor */
        widget_ctk_reset_smil_image_nb_draw_clip();
    #endif /* #ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING */

        /* Move cursor and repaint the screen */
        if (context->flags & WIDGET_SMIL_EDITOR_FLAG_IMAGE_ON_BOTTOM)
        {
            Category275GotoBottom();
        }
        else
        {
            Category275GotoTop();
        }

        gui_unlock_double_buffer();
        gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
    }

    context->text_is_changed_external = 0;

#if defined (WIDGET_SMIL_EDITOR_ICON_IN_INFO_BAR)
    wgui_multiline_inputbox_register_infobar_callback(
            widget_MMI_ctk_show_smil_editor_infobar,
            NULL,
            0);
    wgui_redraw_input_information_bar();
#endif

}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtCreateSmilEditor
 * DESCRIPTION
 *  Create a SMIL editor window which contains
 *  o Embedded MMI editor
 *  o Inserted image
 *  o Indication of inserted audio/attachment file
 * PARAMETERS
 *  modId           [IN]        Owner module (typically SMA module)
 *  str_title1      [IN]        Tile string in the middle
 *  str_title2      [IN]        Title string in the right (in small font)
 *  img_title       [IN]        Title icon (0 for default icon)
 *  inputString     [IN]        Default input string
 *  maxSize         [IN]        Maximum character count of input (not including '\0')
 *  image           [IN]        Inserted image (0 if no image inserted)
 *  flags           [IN]        Misc. flags
 * RETURNS
 *  handle of the created MsfWindow
 *****************************************************************************/
MsfWindowHandle HDIa_widgetExtCreateSmilEditor(
                    MSF_UINT8 modId,
                    widget_string_pack_struct str_title1,
                    widget_string_pack_struct str_title2,
                    ctk_image_id img_title,
                    MsfStringHandle inputString,
                    kal_uint16 maxSize,
                    MsfImageHandle image,
                    kal_uint16 flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_handle scrid;
    ctk_layout_handle layoutid;
    ctk_pcategory_create_struct layout_create;
    MsfWindowHandle ctk;
    widget_ctk_smil_editor_struct *context;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(widget_ctk_appid);

    /* Create CTK screen */
    scrid = widget_ctk_screen_create();

    /* Set context */
    context = MSF_MEM_ALLOC(modId, sizeof(widget_ctk_smil_editor_struct));
    memset(context, 0, sizeof(widget_ctk_smil_editor_struct));

    context->modId = modId;
    widget_ctk_copy_string_pack(modId, &context->str_title1, &str_title1);
    widget_ctk_copy_string_pack(modId, &context->str_title2, &str_title2);
    context->img_title = img_title;
    if (inputString)
    {
        context->text = widget_copy_string(modId, inputString);
    }
    else
    {
        context->text = HDIa_widgetStringCreate(modId, "", MsfUtf8, 1, 0);
    }
    if (maxSize == 0)
    {
        context->max_text_size = WIDGET_MAX_INPUT_LEN;
    }
    else
    {
        context->max_text_size = maxSize;
    }
    widget_resize_string(_STR(context->text), context->max_text_size);
    WAP_DBG_ASSERT(_STR(context->text)->parent_cnt == 1);
    WAP_DBG_ASSERT(_STR(context->text)->raw->parent_cnt == 1);

    /* The default input method is alphanumeric lower case */
    MMI_current_input_type = INPUT_TYPE_ALPHANUMERIC_LOWERCASE;
    context->flags = flags;
    context->image = image;
    context->cached_image = 0;
    context->image_is_cached = 0;
    context->layout_is_formated = 0;
    context->disable_custom_draw_area = 0;
    context->is_set_unmodified = 0;
    context->text_is_changed_external = 0;
    context->resize_image = 0;
    g_ctk_smil_change_slide = KAL_TRUE;

    ctk_screen_set_local_data(scrid, context);

    /* Create Layout */
    CTK_INIT_STRUCT(layout_create);
    layout_create.pcat_show_fp = widget_ctk_show_smil_editor;
    layout_create.pcat_set_default_RSK_fp = SetCategory275RightSoftkeyFunction;
    layoutid = ctk_pcategory_create(widget_ctk_appid, &layout_create);

    ctk_screen_attach_layout(scrid, layoutid);

    /* create MsfWindow */
    ctk = HDIa_widgetCtkCreate(modId, scrid);
    _CTK(ctk)->ctk_predefined_type = WIDGET_CTK_PREDEFINED_SMIL_EDITOR;

    return ctk;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtSmilEditorUpdateTitle
 * DESCRIPTION
 *  Update SMIL editor title
 *  
 *  Please use HDIa_widgetExtSmilEditorRefresh() later to refresh the display if the
 *  window is active.
 * PARAMETERS
 *  wnd             [IN]        Target MsfWindow containing the CTK screen
 *  str_title1      [IN]        Tile string in the middle
 *  str_title2      [IN]        Title string in the right (in small font)
 *  img_title       [IN]        Title icon
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtSmilEditorUpdateTitle(
        MsfWindowHandle wnd,
        widget_string_pack_struct str_title1,
        widget_string_pack_struct str_title2,
        ctk_image_id img_title)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_ctk_smil_editor_struct *context;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!IS_CTK_TYPE(wnd) || _CTK(wnd)->ctk_predefined_type != WIDGET_CTK_PREDEFINED_SMIL_EDITOR)
    {
        WAP_DBG_ASSERT(0);
        return;
    }

    context = (widget_ctk_smil_editor_struct*) ctk_screen_get_local_data(HDIa_widgetCtkGetScreenHandle(wnd));
    ASSERT(context);
    widget_ctk_free_string_pack(context->modId, &context->str_title1);
    widget_ctk_free_string_pack(context->modId, &context->str_title2);
    widget_ctk_copy_string_pack(context->modId, &context->str_title1, &str_title1);
    widget_ctk_copy_string_pack(context->modId, &context->str_title2, &str_title2);
    context->img_title = img_title;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtSmilEditorUpdateTitle2
 * DESCRIPTION
 *  Update SMIL editor title2
 *  
 *  Please use HDIa_widgetExtSmilEditorRefresh() later to refresh the display if the
 *  window is active.
 * PARAMETERS
 *  wnd             [IN]        Target MsfWindow containing the CTK screen
 *  str_title2      [IN]        Title string in the right (in small font)
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtSmilEditorUpdateTitle2(MsfWindowHandle wnd, widget_string_pack_struct str_title2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_ctk_smil_editor_struct *context;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!IS_CTK_TYPE(wnd) || _CTK(wnd)->ctk_predefined_type != WIDGET_CTK_PREDEFINED_SMIL_EDITOR)
    {
        WAP_DBG_ASSERT(0);
        return;
    }

    context = (widget_ctk_smil_editor_struct*) ctk_screen_get_local_data(HDIa_widgetCtkGetScreenHandle(wnd));
    ASSERT(context);
    widget_ctk_free_string_pack(context->modId, &context->str_title2);
    widget_ctk_copy_string_pack(context->modId, &context->str_title2, &str_title2);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtSmilEditorUpdateImage
 * DESCRIPTION
 *  Update the inserted image of SMIL editor
 *  ctkSmilEditor shows the image/video icon according MsfImageHandle file format
 *  
 *  Please use HDIa_widgetExtSmilEditorRefresh() later to refresh the display if the
 *  window is active.
 * PARAMETERS
 *  wnd         [IN]        Target MsfWindow containing the CTK screen
 *  image       [IN]        Inserted image (0 if the image is removed)
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtSmilEditorUpdateImage(MsfWindowHandle wnd, MsfImageHandle image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_ctk_smil_editor_struct *context;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!IS_CTK_TYPE(wnd) || _CTK(wnd)->ctk_predefined_type != WIDGET_CTK_PREDEFINED_SMIL_EDITOR)
    {
        WAP_DBG_ASSERT(0);
        return;
    }
    WAP_DBG_ASSERT(CTK_SCREEN_STATE_ACTIVE != ctk_screen_get_current_state(HDIa_widgetCtkGetScreenHandle(wnd)));

    context = (widget_ctk_smil_editor_struct*) ctk_screen_get_local_data(HDIa_widgetCtkGetScreenHandle(wnd));
    ASSERT(context);
    context->image = image;
    context->image_is_cached = 0;
    context->layout_is_formated = 0;
    context->display_image = 0; /* setup later in widget_ctk_smil_editor_compute_layout() */
    context->is_video = 0;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtSmilEditorUpdateImageEx
 * DESCRIPTION
 *  Update the inserted image of SMIL editor
 *  The image would be the video preview image.
 *  ctkSmilEditor shows the image/video icon according the 3rd param value
 *  
 *  Please use HDIa_widgetExtSmilEditorRefresh() later to refresh the display if the
 *  window is active.
 * PARAMETERS
 *  wnd         [IN]        Target MsfWindow containing the CTK screen
 *  image       [IN]        Inserted image (0 if the image is removed)
 *  is_video    [IN]        If the video preview image
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtSmilEditorUpdateImageEx(MsfWindowHandle wnd, MsfImageHandle image, kal_bool is_video)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_ctk_smil_editor_struct *context;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    HDIa_widgetExtSmilEditorUpdateImage(wnd, image);
    context = (widget_ctk_smil_editor_struct*) ctk_screen_get_local_data(HDIa_widgetCtkGetScreenHandle(wnd));
    context->is_video = (is_video == KAL_TRUE);
}



/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtSmilEditorUpdateText
 * DESCRIPTION
 *  Update the edit text of SMIL editor (the old text will be discarded)
 *  
 *  Please use HDIa_widgetExtSmilEditorRefresh() later to refresh the display if the
 *  window is active.
 *  
 *  However, we should NOT use this API when the editor is still active.
 *  Otherwise, there is a race condition that MMI editor might modify "released" editor buffer.
 * PARAMETERS
 *  wnd             [IN]        Target MsfWindow containing the CTK screen
 *  inputString     [IN]        Default edit text (0 for clear all)
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtSmilEditorUpdateText(MsfWindowHandle wnd, MsfStringHandle inputString)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_ctk_smil_editor_struct *context;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!IS_CTK_TYPE(wnd) || _CTK(wnd)->ctk_predefined_type != WIDGET_CTK_PREDEFINED_SMIL_EDITOR)
    {
        WAP_DBG_ASSERT(0);
        return;
    }
    WAP_DBG_ASSERT(CTK_SCREEN_STATE_ACTIVE != ctk_screen_get_current_state(HDIa_widgetCtkGetScreenHandle(wnd)));

    context = (widget_ctk_smil_editor_struct*) ctk_screen_get_local_data(HDIa_widgetCtkGetScreenHandle(wnd));
    ASSERT(context);

    HDIa_widgetRelease(context->text);

    if (inputString)
    {
        /* If application assign the input string, we should get the current input method */
        context->text = widget_copy_string(context->modId, inputString);
        context->input_type = MMI_current_input_type;
    }
    else
    {
        context->text = HDIa_widgetStringCreate(context->modId, "", MsfUtf8, 1, 0);
        context->input_type = INPUT_TYPE_ALPHANUMERIC_LOWERCASE;
    }
    widget_resize_string(_STR(context->text), context->max_text_size);
    WAP_DBG_ASSERT(_STR(context->text)->parent_cnt == 1);
    WAP_DBG_ASSERT(_STR(context->text)->raw->parent_cnt == 1);

    context->text_is_changed_external = 1;
    HDIa_widgetExtSmilEditorSetUnmodified(wnd);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtSmilEditorChangeSlide
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_true             [IN]        

 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtSmilEditorChangeSlide(kal_bool is_true)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_true)
    {
        /* If changing the slide, we use the default input method */
        MMI_current_input_type = INPUT_TYPE_ALPHANUMERIC_LOWERCASE;
    }
    g_ctk_smil_change_slide = is_true;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtSmilEditorSetFlag
 * DESCRIPTION
 *  Set new flags
 *  
 *  Please use HDIa_widgetExtSmilEditorRefresh() later to refresh the display if the
 *  window is active.
 * PARAMETERS
 *  wnd         [IN]        Target MsfWindow containing the CTK screen
 *  flags       [IN]        Flags to add
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtSmilEditorSetFlag(MsfWindowHandle wnd, kal_uint16 flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_ctk_smil_editor_struct *context;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!IS_CTK_TYPE(wnd) || _CTK(wnd)->ctk_predefined_type != WIDGET_CTK_PREDEFINED_SMIL_EDITOR)
    {
        WAP_DBG_ASSERT(0);
        return;
    }

    context = (widget_ctk_smil_editor_struct*) ctk_screen_get_local_data(HDIa_widgetCtkGetScreenHandle(wnd));
    ASSERT(context);
    if (flags & WIDGET_SMIL_EDITOR_FLAG_IMAGE_ON_BOTTOM && !(context->flags & WIDGET_SMIL_EDITOR_FLAG_IMAGE_ON_BOTTOM))
    {
        WAP_DBG_ASSERT(CTK_SCREEN_STATE_ACTIVE != ctk_screen_get_current_state(HDIa_widgetCtkGetScreenHandle(wnd)));
        context->layout_is_formated = 0;
    }
    context->flags |= flags;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtSmilEditorUnsetFlag
 * DESCRIPTION
 *  Remove old flags
 *  
 *  Please use HDIa_widgetExtSmilEditorRefresh() later to refresh the display if the
 *  window is active.
 * PARAMETERS
 *  wnd         [IN]        Target MsfWindow containing the CTK screen
 *  flags       [IN]        Flags to remove
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtSmilEditorUnsetFlag(MsfWindowHandle wnd, kal_uint16 flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_ctk_smil_editor_struct *context;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!IS_CTK_TYPE(wnd) || _CTK(wnd)->ctk_predefined_type != WIDGET_CTK_PREDEFINED_SMIL_EDITOR)
    {
        WAP_DBG_ASSERT(0);
        return;
    }

    context = (widget_ctk_smil_editor_struct*) ctk_screen_get_local_data(HDIa_widgetCtkGetScreenHandle(wnd));
    ASSERT(context);
    if (flags & WIDGET_SMIL_EDITOR_FLAG_IMAGE_ON_BOTTOM && (context->flags & WIDGET_SMIL_EDITOR_FLAG_IMAGE_ON_BOTTOM))
    {
        WAP_DBG_ASSERT(CTK_SCREEN_STATE_ACTIVE != ctk_screen_get_current_state(HDIa_widgetCtkGetScreenHandle(wnd)));
        context->layout_is_formated = 0;
    }

    context->flags &= ~flags;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtSmilEditorRefresh
 * DESCRIPTION
 *  Force refresh of the display.
 * PARAMETERS
 *  wnd     [IN]        Target MsfWindow containing the CTK screen
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtSmilEditorRefresh(MsfWindowHandle wnd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_handle scrid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!IS_CTK_TYPE(wnd) || _CTK(wnd)->ctk_predefined_type != WIDGET_CTK_PREDEFINED_SMIL_EDITOR)
    {
        WAP_DBG_ASSERT(0);
        return;
    }
    scrid = HDIa_widgetCtkGetScreenHandle(wnd);

    if (CTK_SCREEN_STATE_ACTIVE == ctk_screen_get_current_state(scrid))
    {
        ctk_screen_invoke_redraw(scrid);
    }
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtSmilEditorGetText
 * DESCRIPTION
 *  Retrieve input text
 * PARAMETERS
 *  wnd     [IN]        Target MsfWindow containing the CTK screen
 * RETURNS
 *  void
 *****************************************************************************/
MsfStringHandle HDIa_widgetExtSmilEditorGetText(MsfWindowHandle wnd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_ctk_smil_editor_struct *context;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!IS_CTK_TYPE(wnd) || _CTK(wnd)->ctk_predefined_type != WIDGET_CTK_PREDEFINED_SMIL_EDITOR)
    {
        WAP_DBG_ASSERT(0);
        return 0;
    }

    context = (widget_ctk_smil_editor_struct*) ctk_screen_get_local_data(HDIa_widgetCtkGetScreenHandle(wnd));
    ASSERT(context);
    return context->text;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtSmilEditorGetTextLength
 * DESCRIPTION
 *  Retrieve input text
 * PARAMETERS
 *  wnd                 [IN]        Target MsfWindow containing the CTK screen
 *  lengthInBytes       [IN]        0 for returning character count. 1 for returning byte count
 * RETURNS
 *  the length
 *****************************************************************************/
int HDIa_widgetExtSmilEditorGetTextLength(MsfWindowHandle wnd, int lengthInBytes)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_ctk_smil_editor_struct *context;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!IS_CTK_TYPE(wnd) || _CTK(wnd)->ctk_predefined_type != WIDGET_CTK_PREDEFINED_SMIL_EDITOR)
    {
        WAP_DBG_ASSERT(0);
        return 0;
    }

    context = (widget_ctk_smil_editor_struct*) ctk_screen_get_local_data(HDIa_widgetCtkGetScreenHandle(wnd));
    ASSERT(context);
    return HDIa_widgetStringGetLength(context->text, lengthInBytes, MsfUtf8);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtSmilEditorSetUnmodified
 * DESCRIPTION
 *  Reset modification information
 * PARAMETERS
 *  wnd     [IN]        Target MsfWindow containing the CTK screen
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtSmilEditorSetUnmodified(MsfWindowHandle wnd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * Note: We do not store the modification state in context because 
     * * "Insert Symbol" change the content of MMI input box when editor screen is hiden.
     */

    WIDGET_UNUSED(wnd);

    Category275SetUnmodified();
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtSmilEditorCheckModified
 * DESCRIPTION
 *  Check if the editor modification information
 * PARAMETERS
 *  wnd     [IN]        Target MsfWindow containing the CTK screen
 * RETURNS
 *  whether the editor is modified
 *****************************************************************************/
kal_bool HDIa_widgetExtSmilEditorCheckModified(MsfWindowHandle wnd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_handle scrid = HDIa_widgetCtkGetScreenHandle(wnd);
    widget_ctk_smil_editor_struct *context;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_UNUSED(wnd);

    if (!IS_CTK_TYPE(wnd) || _CTK(wnd)->ctk_predefined_type != WIDGET_CTK_PREDEFINED_SMIL_EDITOR)
    {
        WAP_DBG_ASSERT(0);
        return KAL_FALSE;
    }

    context = (widget_ctk_smil_editor_struct*) ctk_screen_get_local_data(scrid);
    ASSERT(context);

	if (Category275CheckIfModified())
	{
		return KAL_TRUE;
	}
    else if (context->insert_test == 1)
    {
        /*
         * After inserting the text, MMS application will use this function to check the content is modified.
         * We need to notify the content is changed, and MMS will update their content.
         */
        context->insert_test = 0;
		return KAL_TRUE;
    }
	else
	{
		return KAL_FALSE;
	}
}


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_ctk_smil_editor_input_method_done
 * DESCRIPTION
 *  Check if the editor modification information
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void (*widget_ctk_smil_editor_input_method_done_callback) (void);

static void widget_MMI_ctk_smil_editor_input_method_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 
     * This is used when users press Ok in input method menu.
     * 
     * Typically MEA will delete option menu widget and set focus to smil editor in 
     * the following callback.
     * 
     * It is very tricky here because "Insert Symbol" requires to be in MMI editor screen
     * after InputMethodScreenCloseFunction(). But  widget_goback_to_widget_screen()
     * only returns to WAP_SCREEN_WIDGET.
     * 
     * Note: When users press "Back" in input method menu, it will simply go back to widget screen,
     * while the MsfMenu in MEA is still focused and will be displayed.
     */
    widget_ctk_smil_editor_input_method_done_callback();

    widget_goback_to_widget_screen();

    // TODO: There is still possible race condition if WAP task do something unexpected.
    HDIa_widgetExtPaintDirectly();
}


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_ctk_smil_editor_enter_input_method
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_MMI_ctk_smil_editor_enter_input_method(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    RegisterInputMethodScreenCloseFunction(widget_MMI_ctk_smil_editor_input_method_done);
    EntryInputMethodScreen();
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtSmilEditorEnterInputMethod
 * DESCRIPTION
 *  
 * PARAMETERS
 *  wnd                 [IN]        
 *  done_callback       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtSmilEditorEnterInputMethod(MsfWindowHandle wnd, void (*done_callback) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_UNUSED(wnd);
    WAP_DBG_ASSERT(WGUI_CTX->is_widget_screen);
    widget_ctk_smil_editor_input_method_done_callback = done_callback;

    widget_execute_MMI(widget_MMI_ctk_smil_editor_enter_input_method, KAL_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtSmilEditorInsetText
 * DESCRIPTION
 *  
 * PARAMETERS
 *  wnd                 [IN]        
 *  in_str              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern U8 MMI_current_input_mode;
void HDIa_widgetExtSmilEditorInsetText(MsfWindowHandle wnd, const kal_uint8 * in_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_screen_handle scrid = HDIa_widgetCtkGetScreenHandle(wnd);
    widget_ctk_smil_editor_struct *context;
    U8 *guiBuffer;
    U8  tmp_buf[4];
    gdi_handle layer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!IS_CTK_TYPE(wnd) || _CTK(wnd)->ctk_predefined_type != WIDGET_CTK_PREDEFINED_SMIL_EDITOR)
    {
        WAP_DBG_ASSERT(0);
        return ;
    }

    context = (widget_ctk_smil_editor_struct*) ctk_screen_get_local_data(scrid);
    ASSERT(context);

    guiBuffer = ctk_pcategory_get_gui_buffer(ctk_screen_get_layout_handle(scrid));

	context->insert_test = 1;

    /*
     * The function AppendCategory275String() will update the screen content and blt it.
     * Because we don't want to update the content now,
     * we create another gdi layer to avoid update the current screen.
     */
    gdi_layer_create_using_outside_memory(0, 0, 1, 1, &layer, tmp_buf, 4);
    gdi_layer_push_and_set_active(layer);

    AppendCategory275String(
        MMI_current_input_mode,
        (kal_uint8*)widget_string_content(context->text),//context->text,
        (kal_int32)context->max_text_size,
        (kal_uint8*)in_str,
        (kal_uint8*)guiBuffer);

    gdi_layer_pop_and_restore_active();
    gdi_layer_free(layer);
}


/*****************************************************************************
 * FUNCTION
 *  widget_ctk_smil_editor_precache_nonbacking_image
 * DESCRIPTION
 *  
 * PARAMETERS
 *  arg                 [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_ctk_smil_editor_precache_nonbacking_image(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_ctk_smil_editor_struct *context = (widget_ctk_smil_editor_struct*)arg;
    S32 img_width = 0, img_height = 0;
    S32 zoom_x = 0, zoom_y = 0, zoom_width = 0, zoom_height = 0;
    S32 width_bound = 0, height_bound = 0;  /* Upper bound of image width/height (if no icon area present) */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(context);

    /* Compute the image resize resolution */
    gui_measure_image((PU8) GetImage(MEA_IMG_AUDIO), &img_width, &img_height);
    context->icon_width = (kal_int16) img_width;
    context->icon_height = (kal_int16) img_height;
    img_height = widget_image_height(context->image);
    img_width = widget_image_width(context->image);
    width_bound = MMI_content_width - (context->vbar_width + SE_PADDING_H_SPACE) * 4;
    height_bound = MMI_content_height - context->icon_height - SE_EDITOR_MIN_HEIGHT - SE_PADDING_V_SPACE * 4;
    if (img_width < width_bound && img_height < height_bound)
    {
        context->zoom_width = img_width;
        context->zoom_height = img_height;
        context->resize_image = 0;
    }
    else
    {
        gdi_image_util_fit_bbox(
            width_bound,
            height_bound,
            img_width,
            img_height,
            &zoom_x,
            &zoom_y,
            &zoom_width,
            &zoom_height);
        zoom_width = (zoom_width) ? zoom_width : 1;
        zoom_height = (zoom_height) ? zoom_height : 1;
        context->zoom_width = zoom_width;
        context->zoom_height = zoom_height;
        context->resize_image = 1;
    }
    
    /* pre-cache the image */
    WGUI_CTX->precache_nb_image_state = WIDGET_PRECACHE_NB_IMAEG_START;
    if (!widget_ctk_smil_editor_cache_image(context))
    {
        /* don't need to pre-cache the image, set display_image to 0 */
        context->display_image = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtSmilEditorCacheNonBlockingImage
 * DESCRIPTION
 *  
 * PARAMETERS
 *  wnd                 [IN]        
 *  image               [IN]        
 *  precache_cb         [IN]        
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool HDIa_widgetExtSmilEditorCacheNonBlockingImage(MsfWindowHandle wnd, MsfImageHandle image, FuncPtrShort precache_cb)
{
#ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_ctk_smil_editor_struct *context;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (precache_cb == NULL)
    {
        return KAL_FALSE;
    }
    if (image == (MsfImageHandle)NULL)
    {
        /* no image need to cache */
        precache_cb(KAL_TRUE);
        return KAL_FALSE;
    }
    
    context = (widget_ctk_smil_editor_struct*) ctk_screen_get_local_data(HDIa_widgetCtkGetScreenHandle(wnd));
    ASSERT(context);

    context->vbar_width = current_MMI_theme->scrollbar_size;
    if (context->image != image)
    {
        context->image = image;
    }

    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_EXT_SMIL_EDITOR_CACHE_NONBLOCKING_IMAGE);

    /* If previous nb_image is on going, stop it first. */
    if (widget_ctk_nb_image.handle)
    {
        gdi_image_nb_stop (widget_ctk_nb_image.handle);
        widget_ctk_nb_image.handle = 0;
    }
    /* pre-cache the image */
    WGUI_CTX->precache_nb_image_cb = precache_cb;
    WGUI_CTX->precache_nb_image_state = WIDGET_PRECACHE_NB_IMAEG_START;
    widget_execute_MMI_p((func_ptr) widget_ctk_smil_editor_precache_nonbacking_image, (void*)context, KAL_TRUE);
    
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_EXT_SMIL_EDITOR_CACHE_NONBLOCKING_IMAGE_RETURN, WGUI_CTX->precache_nb_image_state);
    if (WGUI_CTX->precache_nb_image_state == WIDGET_PRECACHE_NB_IMAEG_DONE)
    {
        /* pre-cache non-blocking image done */
        WGUI_CTX->precache_nb_image_state = WIDGET_PRECACHE_NB_IMAEG_NONE;
        WGUI_CTX->precache_nb_image_cb(KAL_TRUE);
        WGUI_CTX->precache_nb_image_cb = NULL;
    }
    return KAL_TRUE;
#else
    return KAL_FALSE;
#endif /* #ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING */
}


#endif /* WIDGET_ADVANCED_SMIL_EDITOR */ 

