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
 *  AppMemMgr.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  App-Based Shared Memory Manager
 *
 *  App-based shared memory is allocated before entering an application, and 
 *  released when exiting an application. 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"
#include "stdC.h"
#include "L4Dr.h"
#include "MMIDataType.h"
#include "GlobalDefs.h"
#include "MMI_trc.h"
#include "app_mem.h"
#include "FrameworkGprot.h"
#include "FrameworkProt.h"
#include "DebugInitDef.h"
#include "CommonScreensEnum.h"
#include "CommonScreens.h"
#include "SettingProfile.h"         /* for tone ID */
#include "wgui_categories_fmgr.h"   /* Category 212 */
#include "mmiapi_func.h"
#include "wgui_categories_popup.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef 
 *****************************************************************************/

/* States of mmi_frm_appmem_stop_confirm_screen_yes() */
typedef enum
{
    /* Normal case */
    MMI_FRM_APPMEM_STOP_STATE_IGNORE,
    /* Inside mmi_frm_appmem_stop_confirm_screen_yes() */
    MMI_FRM_APPMEM_STOP_STATE_WAITING,
    /* Stop operation finished inside mmi_frm_appmem_stop_confirm_screen_yes() */
    MMI_FRM_APPMEM_STOP_STATE_FINISHED
} mmi_frm_appmem_stop_state_enum;

/* Context of the prompt screen */
typedef struct 
{
    /* Properties of the application requesting to free up more memory */
    MMI_ID_TYPE app_name;
    MMI_ID_TYPE app_icon;
    /* Requested memory size */
    U32 required_size;
    MMI_BOOL require_full_pool;
    /* Used inside mmi_frm_appmem_stop_confirm_screen_yes() */
    mmi_frm_appmem_stop_state_enum stop_state;
    kal_uint32 app_id_confirm_to_stop;
    /* Keep SCR_APPMEM_STOP_PROMPT & SCR_APPMEM_STOP_PROGRESSING in history 
       at its exit function. */
    MMI_BOOL keep_prompt_screen_in_history;
    void (*success_callback)(void);
} mmi_frm_appmem_prompt_struct;

typedef struct 
{
    /* Number of applications using App-based ASM */
    S32 num_app;
    /* Detailed information */
    applib_mem_ap_usage_struct applist[MMI_FRM_APPMEM_MAX_APP_PROMPTED];
} mmi_frm_appmem_prompt_screen_struct;

/*****************************************************************************              
 * Local Variable                                                                    
 *****************************************************************************/

/* Life cycle: prompt user to stop applications -> successfully get the memory or cancelled */
static mmi_frm_appmem_prompt_struct g_mmi_frm_appmem_prompt;

/* Life cycle: inside the prompt screen only (SCR_APPMEM_STOP_PROMPT) */
static mmi_frm_appmem_prompt_screen_struct *g_mmi_frm_appmem_prompt_screen = NULL;

/*****************************************************************************              
 * Local Function                                                                    
 *****************************************************************************/

/* Prototype declarations: */
static void mmi_frm_appmem_entry_prompt_screen(void);
static void mmi_frm_appmem_entry_progressing_screen(void);
static void mmi_frm_appmem_invoke_release_mem_success_callback(void);
static void mmi_frm_appmem_stop_finished_handler(kal_uint32 app_id, kal_uint32 string_id, kal_bool result);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_is_in_prompt_screens
 * DESCRIPTION
 *  Whether MMI is inside prompt screens (SCR_APPMEM_STOP_PROMPT and SCR_APPMEM_STOP_PROGRESSING)
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_frm_appmem_is_in_prompt_screens(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 curr_scr_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    curr_scr_id = GetExitScrnID();
    return curr_scr_id == SCR_APPMEM_STOP_PROMPT || 
           curr_scr_id == SCR_APPMEM_STOP_PROGRESSING;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_is_prompt_screens_in_history
 * DESCRIPTION
 *  Whether a prompt screen (SCR_APPMEM_STOP_PROMPT or SCR_APPMEM_STOP_PROGRESSING)
 *  is inside history.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_frm_appmem_is_prompt_screens_in_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return IsScreenPresent(SCR_APPMEM_STOP_PROMPT) || 
           IsScreenPresent(SCR_APPMEM_STOP_PROGRESSING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_jump_to_prompt_screen
 * DESCRIPTION
 *  Go back to the prompt screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_jump_to_prompt_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(IsScreenPresent(SCR_APPMEM_STOP_PROMPT));
    GoBackToHistory(SCR_APPMEM_STOP_PROMPT);
}
 

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_exit_progressing_screen
 * DESCRIPTION
 *  Exit function of progressing screen 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_exit_progressing_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (g_mmi_frm_appmem_prompt.keep_prompt_screen_in_history)
    {
        h.scrnID = SCR_APPMEM_STOP_PROGRESSING;
        h.entryFuncPtr = mmi_frm_appmem_entry_progressing_screen;
        mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) L"");
        GetCategoryHistory(h.guiBuffer);
    
        AddHistory(h);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_check_enough_memory
 * DESCRIPTION
 *  Check if the free memory is enough
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_frm_appmem_check_enough_memory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_frm_appmem_prompt.require_full_pool && applib_mem_ap_get_alloc_count() == 0)
    {
        return MMI_TRUE;
    }

    if (!g_mmi_frm_appmem_prompt.require_full_pool && 
         applib_mem_ap_get_max_alloc_size() >= g_mmi_frm_appmem_prompt.required_size)
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_entry_progressing_screen
 * DESCRIPTION
 *  Entry function of progressing screen when an application has not finished stopping
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_entry_progressing_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    MMI_BOOL bShowProgressScr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    bShowProgressScr = !mmi_frm_appmem_check_enough_memory() || 
                        mmi_is_redrawing_bk_screens();     /* redrawn by small screen */

    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ASM_ENTRY_PROGRESSING_SCREEN, bShowProgressScr);
    
    if (bShowProgressScr)
    {    
        EntryNewScreen(SCR_APPMEM_STOP_PROGRESSING, mmi_frm_appmem_exit_progressing_screen, NULL, NULL);     

        guiBuffer = GetCurrGuiBuffer(SCR_APPMEM_STOP_PROGRESSING);

		ShowCategory165Screen(
            0,                                  /* Left softkey */
            0,
            STR_GLOBAL_BACK,                    /* Right softkey */
            0,
			(UI_string_type)GetString(STR_ID_APPMEM_WAITING_FOR_STOP),
            IMG_GLOBAL_PROGRESS,
            guiBuffer);
 
        SetRightSoftkeyFunction(mmi_frm_appmem_jump_to_prompt_screen, KEY_EVENT_UP);
    }
    else
    {
        DisplayPopupCallBack(
            (U8*) GetString(STR_ID_APPMEM_NOTIFY_STARTING_NEW), 
            IMG_GLOBAL_INFO, 
            0, 
            UI_POPUP_NOTIFYDURATION_TIME_2000, 
            SUCCESS_TONE, 
            mmi_frm_appmem_invoke_release_mem_success_callback);
    }        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_stop_confirm_screen_yes
 * DESCRIPTION
 *  User confirm to stop an application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_stop_confirm_screen_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_frm_appmem_prompt.stop_state = MMI_FRM_APPMEM_STOP_STATE_WAITING;

    applib_mem_ap_stop_app_by_MMI_task(g_mmi_frm_appmem_prompt.app_id_confirm_to_stop);

    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ASM_STOP_CONFIRM_YES, 
                g_mmi_frm_appmem_prompt.app_id_confirm_to_stop,
                g_mmi_frm_appmem_prompt.stop_state);
        
    if (g_mmi_frm_appmem_prompt.stop_state != MMI_FRM_APPMEM_STOP_STATE_FINISHED)
    {
        /* mmi_frm_appmem_stop_finished_handler() was not invoked inside
           applib_mem_ap_stop_app_by_MMI_task(), we display progressing
           screen to wait for mmi_frm_appmem_stop_finished_handler() */ 
        mmi_frm_appmem_entry_progressing_screen();
    }

    g_mmi_frm_appmem_prompt.stop_state = MMI_FRM_APPMEM_STOP_STATE_IGNORE;    

}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_entry_stop_confirm_screen
 * DESCRIPTION
 *  Ask user to confirm to stop application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_entry_stop_confirm_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (UI_string_type) GetString(STR_ID_APPMEM_STOP),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_frm_appmem_stop_confirm_screen_yes, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_prompt_screen_get_item
 * DESCRIPTION
 *  Callback function to draw the info box of prompt screen
 * PARAMETERS
 *  item_index      [IN]        Index of menu item
 *  str_buff        [OUT]       Output text buffer
 *  img_buff_p      [OUT]       Output image buffer
 *  str_img_mask    [OUT]       (deprecated)
 * RETURNS
 *  Success or not
 *****************************************************************************/
static pBOOL mmi_frm_appmem_prompt_screen_get_item(
                S32 item_index, 
                UI_string_type str_buff, 
                PU8 *img_buff_p, 
                U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_mem_ap_usage_struct *applist;
    S8 size_str[32];
    S8 size_str_ucs2[32 * 2];
    S32 app_name_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_mmi_frm_appmem_prompt_screen &&
               item_index < g_mmi_frm_appmem_prompt_screen->num_app);

    applist = g_mmi_frm_appmem_prompt_screen->applist;
    
    mmi_ucs2ncpy((S8*) str_buff, GetString((U16) applist[item_index].string_id), (MAX_SUB_MENU_SIZE / 2));
    app_name_len = mmi_ucs2strlen((S8*) str_buff);

    if (applist[item_index].is_stopping)
    {
        mmi_ucs2ncpy(
            (S8*) str_buff + (app_name_len * 2), 
            (S8*) GetString(STR_ID_APPMEM_ATTR_STOPPING),
            (MAX_SUB_MENU_SIZE / 2) - app_name_len);
    }
    else
    {
        sprintf((char*) size_str, " (%d K)", applist[item_index].mem_size / 1024);
        mmi_asc_to_ucs2(size_str_ucs2, size_str);
        
        mmi_ucs2ncpy(
            (S8*) str_buff + (app_name_len * 2), 
            size_str_ucs2, 
            (MAX_SUB_MENU_SIZE / 2) - app_name_len);
    }
    
    *img_buff_p = (PU8) GetImage((U16) applist[item_index].icon_id);

    return (pBOOL) MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_prompt_screen_init_info
 * DESCRIPTION
 *  Initialize the info box
 * PARAMETERS
 *  void
 * RETURNS
 *  The minimum height of info box
 *****************************************************************************/
static S32 mmi_frm_appmem_prompt_screen_init_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 msg_length;
    UI_string_type msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg = (UI_string_type) GetString(STR_ID_APPMEM_PROMPT_STOP_APP);
    msg_length = gui_strlen(msg);

    create_multiline_inputbox_set_buffer(msg, msg_length, msg_length, 0);
    resize_multiline_inputbox(UI_device_width, UI_device_height);
    
    MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW | 
        UI_MULTI_LINE_INPUT_BOX_VIEW_MODE | UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR;

    show_multiline_inputbox_no_draw();

    /* Add (get_multiline_inputbox_line_height() / 4) for extra spacing */
    return get_multiline_inputbox_line_height() * MMI_multiline_inputbox.n_lines +
           MMI_multiline_inputbox.text_y + (get_multiline_inputbox_line_height() / 4);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_prompt_screen_draw_info
 * DESCRIPTION
 *  Callback function to draw the info box of prompt screen
 * PARAMETERS
 *  idx     [IN]    menu item index
 *  x1      [IN]    x of left-top point
 *  y1      [IN]    y of left-top point
 *  x2      [IN]    x of right-bottom point
 *  y2      [IN]    y of right-bottom point
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_prompt_screen_draw_info(S32 idx, S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    move_multiline_inputbox(x1, y1);
    resize_multiline_inputbox(x2 - x1 + 1, y2 - y1 + 1);
    show_multiline_inputbox_no_draw();
    
    show_multiline_inputbox();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_prompt_screen_hide_info
 * DESCRIPTION
 *  Callback function to hide the info box of prompt screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_prompt_screen_hide_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_prompt_screen_stop_highlighted
 * DESCRIPTION
 *  Stop the current highlighted application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_prompt_screen_stop_highlighted(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 highlited_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_ASSERT(GetExitScrnID() == SCR_APPMEM_STOP_PROMPT &&
               g_mmi_frm_appmem_prompt_screen);

    highlited_item = GetHighlightedItem();
    MMI_ASSERT(highlited_item < g_mmi_frm_appmem_prompt_screen->num_app);

    g_mmi_frm_appmem_prompt.app_id_confirm_to_stop = 
        g_mmi_frm_appmem_prompt_screen->applist[highlited_item].app_id;

    mmi_frm_appmem_entry_stop_confirm_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_prompt_screen_wait_highlighted
 * DESCRIPTION
 *  Wait a stopping application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_prompt_screen_wait_highlighted(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    mmi_frm_appmem_entry_progressing_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_prompt_screen_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of prompt screen
 * PARAMETERS
 *  item_index  [IN]    currently highlighted menu index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_prompt_screen_highlight_hdlr(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (g_mmi_frm_appmem_prompt_screen->num_app == 0)
    {
        return;
    }
    
    MMI_ASSERT(g_mmi_frm_appmem_prompt_screen && 
               item_index < g_mmi_frm_appmem_prompt_screen->num_app);
    
    if (!g_mmi_frm_appmem_prompt_screen->applist[item_index].is_stopping)
    {
        ChangeLeftSoftkey(STR_GLOBAL_STOP, 0);
        SetLeftSoftkeyFunction(mmi_frm_appmem_prompt_screen_stop_highlighted, KEY_EVENT_UP);
    }
    else
    {
        ChangeLeftSoftkey(STR_ID_APPMEM_WAIT, 0);
        SetLeftSoftkeyFunction(mmi_frm_appmem_prompt_screen_wait_highlighted, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_exit_prompt_screen
 * DESCRIPTION
 *  Exit function of prompt screen 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_exit_prompt_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (g_mmi_frm_appmem_prompt.keep_prompt_screen_in_history)
    {
        h.scrnID = SCR_APPMEM_STOP_PROMPT;
        h.entryFuncPtr = mmi_frm_appmem_entry_prompt_screen;
        mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) L"");
        GetCategoryHistory(h.guiBuffer);
    
        AddHistory(h);
    }

    OslMfree(g_mmi_frm_appmem_prompt_screen);
    g_mmi_frm_appmem_prompt_screen = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_entry_prompt_screen
 * DESCRIPTION
 *  Entry function of prompt screen to stop other applications
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_entry_prompt_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S32 info_box_height;
    MMI_BOOL bShowPromptScr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_mmi_frm_appmem_prompt_screen == NULL);

    bShowPromptScr = !mmi_frm_appmem_check_enough_memory() || 
                        mmi_is_redrawing_bk_screens(); /* redrawn by small screen */

    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ASM_ENTRY_PROMPT_SCREEN, bShowPromptScr);
    
    if (bShowPromptScr)
    {
        EntryNewScreen(SCR_APPMEM_STOP_PROMPT, mmi_frm_appmem_exit_prompt_screen, NULL, NULL);     

        guiBuffer = GetCurrGuiBuffer(SCR_APPMEM_STOP_PROMPT);

        g_mmi_frm_appmem_prompt_screen = 
            (mmi_frm_appmem_prompt_screen_struct*) OslMalloc(sizeof(mmi_frm_appmem_prompt_screen_struct));

        g_mmi_frm_appmem_prompt_screen->num_app = 
            (S32) applib_mem_ap_get_current_usage(
                    g_mmi_frm_appmem_prompt_screen->applist,
                    MMI_FRM_APPMEM_MAX_APP_PROMPTED);

        info_box_height = mmi_frm_appmem_prompt_screen_init_info();        

        RegisterHighlightHandler(mmi_frm_appmem_prompt_screen_highlight_hdlr);
        
        ShowCategory211Screen(
            STR_ID_APPMEM_OUT_OF_MEMORY,
            0, 
            STR_GLOBAL_STOP,
            0, 
            STR_GLOBAL_BACK, 
            0, 
            g_mmi_frm_appmem_prompt_screen->num_app, 
            mmi_frm_appmem_prompt_screen_get_item, 
            NULL, 
            mmi_frm_appmem_prompt_screen_draw_info,
            mmi_frm_appmem_prompt_screen_hide_info,
            info_box_height,            /* Info box height */
            0,                          /* Background image of info box */
            0,                          /* Highlight item index */
            guiBuffer);

       SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
    else
    {
        DisplayPopupCallBack(
            (U8*) GetString(STR_ID_APPMEM_NOTIFY_STARTING_NEW), 
            IMG_GLOBAL_INFO, 
            0, 
            UI_POPUP_NOTIFYDURATION_TIME_2000, 
            SUCCESS_TONE, 
            mmi_frm_appmem_invoke_release_mem_success_callback);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_invoke_release_mem_success_callback
 * DESCRIPTION
 *  Invoke the calling application there is enough memory
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_invoke_release_mem_success_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(mmi_frm_appmem_check_enough_memory());
    MMI_ASSERT(mmiapi_is_MMI_task());

    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ASM_INVOKE_SUCCESS_CB, 
                g_mmi_frm_appmem_prompt.app_name,
                g_mmi_frm_appmem_prompt.success_callback);

    DeleteScreenIfPresent(SCR_APPMEM_STOP_PROMPT);
    DeleteScreenIfPresent(SCR_APPMEM_STOP_PROGRESSING);

    /* Enter another screen by registered callback function */
    g_mmi_frm_appmem_prompt.keep_prompt_screen_in_history = MMI_FALSE;
    g_mmi_frm_appmem_prompt.success_callback();

    /* The callback function must enter new MMI screen */
    MMI_ASSERT(!mmi_frm_appmem_is_in_prompt_screens() &&
               !mmi_frm_appmem_is_prompt_screens_in_history());
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_stop_finished_handler
 * DESCRIPTION
 *  Callback handler when an application finished stop operation
 * PARAMETERS
 *  app_id      [IN]    ID of the application to be stopped
 *  string_id   [IN]    Name of the application to be stopped
 *  result      [IN]    whether the stop operation suceeds or not
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_stop_finished_handler(kal_uint32 app_id, kal_uint32 string_id, kal_bool result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_appmem_is_in_prompt_screens() ||
        g_mmi_frm_appmem_prompt.stop_state == MMI_FRM_APPMEM_STOP_STATE_WAITING) /* In confirm screen */
    {
        U32 msgId;
        U16 icon;
        U8 tone;
        FuncPtr callback;
        if (mmi_frm_appmem_check_enough_memory())
        {
            msgId = STR_ID_APPMEM_NOTIFY_STARTING_NEW;
            icon = IMG_GLOBAL_INFO;
            tone = SUCCESS_TONE;        
            callback = mmi_frm_appmem_invoke_release_mem_success_callback;
        }
        else if (result) 
        {
            msgId = STR_ID_APPMEM_NOTIFY_STOPPED;
            icon = IMG_GLOBAL_INFO;
            tone = SUCCESS_TONE;
            callback = mmi_frm_appmem_jump_to_prompt_screen;
        }
        else
        {
            msgId = STR_ID_APPMEM_NOTIFY_STOP_FAILED;
            icon = IMG_GLOBAL_WARNING;
            tone = ERROR_TONE;
            callback = mmi_frm_appmem_jump_to_prompt_screen;
        }

        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ASM_STOP_FINISHED_HANDLER, msgId, callback);
                            
        DisplayPopupCallBack((U8*)GetString((U16)msgId), icon, 0, UI_POPUP_NOTIFYDURATION_TIME_2000, tone, callback);

        if (g_mmi_frm_appmem_prompt.stop_state == MMI_FRM_APPMEM_STOP_STATE_WAITING)
        {
            g_mmi_frm_appmem_prompt.stop_state = MMI_FRM_APPMEM_STOP_STATE_FINISHED;
        }
    }
    else 
    {
        /* 
         * 1. If prompt screen is in history - it will be processed after goback to prompt screen 
         * 2. If prompt screen is not in history - silently ignore the result 
         *    (Maybe it goes back to idle screen)
         */
    }
}


/*****************************************************************************              
 * Extern Global Variable                                                                    
 *****************************************************************************/

/*****************************************************************************              
 * Extern Global Function                                                                    
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_prompt_to_release_mem
 * DESCRIPTION
 *  Show "out-of-memory" screen and prompt user to stop other applications in order 
 *  to release more memory.
 *
 *  Remark: 
 *  1. This function is not suggested to be used in "interrupt screens" 
 *     (e.g. MT call or USB plug-in indication)
 *     Otherwise, it might re-enter the prompt screen and confuse user.
 *  2. 'success_callback' needs to enter a new MMI screen!
 *  3. There is no "failure callback" due to complex interaction of MMI screens.
 *     Applications that use this function should never adopt any explicit or 
 *     implicit "waiting" state for the result.
 *
 *     For example, user may press End key in the "out-of-memory" screen and
 *     try to enter the application again. 
 *
 *  Warning: This function can only be used in MMI task.
 * PARAMETERS
 *  app_name            [IN]    String ID of the application 
 *  app_icon            [IN]    Image ID of the application 
 *  required_size       [IN]    Minimum required memory for the application
 *  success_callback    [IN]    Callback function when getting memory successfully 
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_appmem_prompt_to_release_mem(
        MMI_ID_TYPE app_name, 
        MMI_ID_TYPE app_icon, 
        U32 required_size,
        void (*success_callback)(void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(required_size <= applib_mem_ap_get_pool_size());

    /* Avoid reentrance of the prompt screen.
       Application developers should be careful on designing the screen flow */
    MMI_ASSERT(!mmi_frm_appmem_is_in_prompt_screens() && 
               !mmi_frm_appmem_is_prompt_screens_in_history());

    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ASM_PROMPT_TO_RELEASE_MEM, app_name, required_size);

    /* Note the context g_mmi_frm_appmem_prompt is not reset  */
    g_mmi_frm_appmem_prompt.app_name = app_name;
    g_mmi_frm_appmem_prompt.app_icon = app_icon;
    g_mmi_frm_appmem_prompt.required_size = required_size;
    g_mmi_frm_appmem_prompt.require_full_pool = MMI_FALSE;    
    g_mmi_frm_appmem_prompt.stop_state = MMI_FRM_APPMEM_STOP_STATE_IGNORE;
    g_mmi_frm_appmem_prompt.keep_prompt_screen_in_history = MMI_TRUE;
    g_mmi_frm_appmem_prompt.success_callback = success_callback;

    mmi_frm_appmem_entry_prompt_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_prompt_to_release_full_pool
 * DESCRIPTION
 *  Show "out-of-memory" screen and prompt user to stop other applications in order 
 *  to release more memory.
 *  
 *  This function is similar to mmi_frm_appmem_prompt_to_release_mem
 *  but it requires the whole pool.
 *
 *  Warning: This function can only be used in MMI task.
 * PARAMETERS
 *  app_name            [IN]    String ID of the application 
 *  app_icon            [IN]    Image ID of the application 
 *  success_callback    [IN]    Callback function when getting memory successfully 
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_appmem_prompt_to_release_full_pool(
        MMI_ID_TYPE app_name, 
        MMI_ID_TYPE app_icon, 
        void (*success_callback)(void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Avoid reentrance of the prompt screen.
       Application developers should be careful on designing the screen flow */
    MMI_ASSERT(!mmi_frm_appmem_is_in_prompt_screens() && 
               !mmi_frm_appmem_is_prompt_screens_in_history());

    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ASM_PROMPT_TO_RELEASE_FULL_POOL, app_name);

    /* Note the context g_mmi_frm_appmem_prompt is not reset  */
    g_mmi_frm_appmem_prompt.app_name = app_name;
    g_mmi_frm_appmem_prompt.app_icon = app_icon;
    g_mmi_frm_appmem_prompt.required_size = 0;
    g_mmi_frm_appmem_prompt.require_full_pool = MMI_TRUE;
    g_mmi_frm_appmem_prompt.stop_state = MMI_FRM_APPMEM_STOP_STATE_IGNORE;
    g_mmi_frm_appmem_prompt.keep_prompt_screen_in_history = MMI_TRUE;
    g_mmi_frm_appmem_prompt.success_callback = success_callback;

    mmi_frm_appmem_entry_prompt_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_init
 * DESCRIPTION
 *  Initialize app-based ASM.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_appmem_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    applib_mem_ap_init(mmi_frm_appmem_stop_finished_handler);
}


/***************************************************************************** 
 * Unit Test 
 *****************************************************************************/

#ifdef APPLIB_MEM_UNIT_TEST

#define MMI_FRM_APPMEM_TEST1_SIZE   (10*1024)

#define MMI_FRM_APPMEM_TEST2_SIZE   (20*1024)

#define MMI_FRM_APPMEM_TEST3_SIZE   (30*1024)

#define MMI_FRM_APPMEM_TEST4_SIZE   (40*1024)

#define MMI_FRM_APPMEM_TEST5_SIZE   (50*1024)

/* start index of APPs */
#define TEST_ITEM_START     (2)

/* no. of unit-test menu items */
#define TEST_ITEM_NUM       (sizeof(g_appmem_ut_test_func)/sizeof(void*) + TEST_ITEM_START)

/* string length of menu items */
#define TEST_ITEM_STR_LEN   (30)

/* popup time for each APP */
#define TEST_APP_POPUP_TIME (500)   /* ms */

static void mmi_frm_appmem_ut_2nd_entry(S32 selected_item);
static void mmi_frm_appmem_ut_hilight_hdlr(S32 index);
static void mmi_frm_appmem_ut_start(void);
static void mmi_frm_ut_app_entry(void);

/* test function for each APP */
void (* const g_appmem_ut_test_func[])(void (*)(void), MMI_BOOL) = {
    mmi_frm_appmem_unit_test_prepare_to_enter_test1,
    mmi_frm_appmem_unit_test_prepare_to_enter_test2,
    mmi_frm_appmem_unit_test_prepare_to_enter_test3,
    mmi_frm_appmem_unit_test_prepare_to_enter_test4,
    mmi_frm_appmem_unit_test_prepare_to_enter_test5};

/* mem. allocation size for each APP */
const U32 g_appmem_ut_allocate_size[] = {
    MMI_FRM_APPMEM_TEST1_SIZE,
    MMI_FRM_APPMEM_TEST2_SIZE,
    MMI_FRM_APPMEM_TEST3_SIZE,
    MMI_FRM_APPMEM_TEST4_SIZE,
    MMI_FRM_APPMEM_TEST5_SIZE};

/* structure for appmem unit-test variables */
typedef struct {
    S32 selected_item;
    S8 item_list_str[TEST_ITEM_NUM][TEST_ITEM_STR_LEN*ENCODING_LENGTH];
    S8 *item_list[TEST_ITEM_NUM];
} mmi_frm_appmem_ut_context_struct;

/* appmem unit-test context variable */
static mmi_frm_appmem_ut_context_struct g_appmem_ut_cntx = {
    /* selected_item */
    TEST_ITEM_START,
    /* item_list_str */
    {
    "",
    /* "Free All TEST Memory" */
    "F\0r\0e\0e\0 \0A\0l\0l\0 \0T\0E\0S\0T\0 \0M\0e\0m\0o\0r\0y\0\0\0"}
};


#include "stdlib.h"

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_unit_test_stress_alloc
 * DESCRIPTION
 *  Unit test routine
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_unit_test_stress_alloc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 *ptr_list[100];
    kal_int32 i, count, free_space_original, tmp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST1);
    applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST2);
    applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST3);
    applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST4);
    applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST5);    

    free_space_original = applib_mem_ap_get_total_left_size();

#define ALLOC_SIZE(_idx)    ((_idx) + (_idx) * 256)
#define PTR_LIST_SIZE       (sizeof(ptr_list) / sizeof(void*))

    for (i = 0; i < PTR_LIST_SIZE; i++)
    {
        if ((ptr_list[i] = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_TEST1, ALLOC_SIZE(i))) == NULL)
        {
            MMI_ASSERT(applib_mem_ap_get_max_alloc_size() < ALLOC_SIZE(i));
            break;
        }
    }

    count = i;
    MMI_ASSERT(count > 0);
    MMI_ASSERT(applib_mem_ap_get_alloc_count() == count);

    applib_mem_ap_check_integrity();

    tmp = 0;
    for (i = 0; i < count; i++)
    {
        if (i & 0x01)
        {
            /* keep odd ones allocated */
            tmp += ALLOC_SIZE(i);
        }
        else
        {   /* free even ones */
            applib_mem_ap_free(ptr_list[i]);
        }
    }

    MMI_ASSERT(tmp < free_space_original - applib_mem_ap_get_total_left_size());

    applib_mem_ap_check_integrity();

    if (count >= 2)
    {
        for (i = 1; i < count; i += 2)
        {
            MMI_ASSERT(applib_mem_ap_is_valid_block(ptr_list[i]));
        }
    }

    applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST2);

    applib_mem_ap_check_integrity();

    applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST1);

    applib_mem_ap_check_integrity();

    MMI_ASSERT(free_space_original == applib_mem_ap_get_total_left_size());
    MMI_ASSERT(applib_mem_ap_get_alloc_count() == 0);    

    /* Random alloc/free */

    for (i = 0; i < PTR_LIST_SIZE; i++)
    {
        ptr_list[i] = NULL;
    }

    for (;;)
    {
        kal_int32 key = rand();
        if ((key % 1000) == 0)
        {
            break;
        }
        
        if (applib_mem_ap_get_alloc_count() == PTR_LIST_SIZE || key % 3 == 0)
        {
            i = ((key + 1) % PTR_LIST_SIZE);
            for (; i != key % PTR_LIST_SIZE; i++, i %= PTR_LIST_SIZE)
            {
                if (ptr_list[i])
                {
                    applib_mem_ap_free(ptr_list[i]);
                    ptr_list[i] = NULL;
                    break;
                }
            }
        }
        else
        {
            for (i = 0; i < PTR_LIST_SIZE; i++)
            {
                if (!ptr_list[i])
                {
                    kal_uint32 size = key % applib_mem_ap_get_pool_size();
                    ptr_list[i] = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_TEST1 + (key % 5), size);
                    /* Test memory corruption detection */
                    // ptr_list[i][size/4] = 1;
                    // ptr_list[i][size/4 + 1] = 1;
                    // ptr_list[i][size/4 + 2] = 1;
                    break;
                }
            }
        }
        applib_mem_ap_check_integrity();
    }

    applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST1);
    applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST2);
    applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST3);
    applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST4);
    applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST5);    
    MMI_ASSERT(free_space_original == applib_mem_ap_get_total_left_size());
    MMI_ASSERT(applib_mem_ap_get_alloc_count() == 0);
}


static void mmi_frm_appmem_unit_test_stop_1_timer_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST1);    
    applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_TEST1, KAL_TRUE);
}


static void mmi_frm_appmem_unit_test_stop_1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StartTimer(FM_AUTO_TEST_COMMNON_TIMER, 10000, mmi_frm_appmem_unit_test_stop_1_timer_hdlr);
}


static void mmi_frm_appmem_unit_test_stop_2_timer_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST2);
    applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_TEST2, KAL_TRUE);
}


static void mmi_frm_appmem_unit_test_stop_2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StartTimer(FM_AUTO_TEST_COMMNON_TIMER, 300, mmi_frm_appmem_unit_test_stop_2_timer_hdlr);
}


static void mmi_frm_appmem_unit_test_stop_3_timer_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST3);    
    applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_TEST3, KAL_TRUE);
}


static void mmi_frm_appmem_unit_test_stop_3(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StartTimer(FM_AUTO_TEST_COMMNON_TIMER, 3000, mmi_frm_appmem_unit_test_stop_3_timer_hdlr);
}


static void mmi_frm_appmem_unit_test_stop_4(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST4);        
    /* Return immediately */   
    applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_TEST4, KAL_TRUE);
}


static void mmi_frm_appmem_unit_test_stop_5(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Return immediately */
    applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_TEST5, KAL_FALSE); /* Fail */
}

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_unit_test_success_callback1
 * DESCRIPTION
 *  Callback function when memory was released.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void (*g_mmi_frm_appmem_unit_test_run_callback1)(void);

static void mmi_frm_appmem_unit_test_success_callback1(void)
{
    void *ptr = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_TEST1, MMI_FRM_APPMEM_TEST1_SIZE);
    MMI_ASSERT(ptr);
    g_mmi_frm_appmem_unit_test_run_callback1();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_unit_test_prepare_to_enter_test1
 * DESCRIPTION
 *  Simple program to test screen-based ASM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_appmem_unit_test_prepare_to_enter_test1(
    void (*run_callback)(void),
    MMI_BOOL clear_all)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (clear_all)
        applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST1);
    
    g_mmi_frm_appmem_unit_test_run_callback1 = run_callback;
    if (applib_mem_ap_alloc(APPLIB_MEM_AP_ID_TEST1, MMI_FRM_APPMEM_TEST1_SIZE))
    {
        run_callback();
    }
    else
    {
        mmi_frm_appmem_prompt_to_release_mem(
            APPLIB_MEM_AP_ID_TEST1,
            IMG_GLOBAL_L1,
            MMI_FRM_APPMEM_TEST1_SIZE,
            mmi_frm_appmem_unit_test_success_callback1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_unit_test_success_callback2
 * DESCRIPTION
 *  Callback function when memory was released.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void (*g_mmi_frm_appmem_unit_test_run_callback2)(void);

static void mmi_frm_appmem_unit_test_success_callback2(void)
{
    void *ptr = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_TEST2, MMI_FRM_APPMEM_TEST2_SIZE);
    MMI_ASSERT(ptr);
    g_mmi_frm_appmem_unit_test_run_callback2();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_unit_test_prepare_to_enter_test2
 * DESCRIPTION
 *  Simple program to test screen-based ASM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_appmem_unit_test_prepare_to_enter_test2(
    void (*run_callback)(void),
    MMI_BOOL clear_all)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (clear_all)
        applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST2);

    g_mmi_frm_appmem_unit_test_run_callback2 = run_callback;    
    if (applib_mem_ap_alloc(APPLIB_MEM_AP_ID_TEST2, MMI_FRM_APPMEM_TEST2_SIZE))
    {
        run_callback();
    }
    else
    {
        mmi_frm_appmem_prompt_to_release_mem(
            APPLIB_MEM_AP_ID_TEST2,
            IMG_GLOBAL_L2,
            MMI_FRM_APPMEM_TEST2_SIZE,
            mmi_frm_appmem_unit_test_success_callback2);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_unit_test_success_callback3
 * DESCRIPTION
 *  Callback function when memory was released.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void (*g_mmi_frm_appmem_unit_test_run_callback3)(void);

static void mmi_frm_appmem_unit_test_success_callback3(void)
{
    void *ptr = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_TEST3, MMI_FRM_APPMEM_TEST3_SIZE);
    MMI_ASSERT(ptr);
    g_mmi_frm_appmem_unit_test_run_callback3();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_unit_test_prepare_to_enter_test3
 * DESCRIPTION
 *  Simple program to test screen-based ASM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_appmem_unit_test_prepare_to_enter_test3(
    void (*run_callback)(void),
    MMI_BOOL clear_all)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (clear_all)
        applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST3);

    g_mmi_frm_appmem_unit_test_run_callback3 = run_callback;    
    if (applib_mem_ap_alloc(APPLIB_MEM_AP_ID_TEST3, MMI_FRM_APPMEM_TEST3_SIZE))
    {
        run_callback();
    }
    else
    {
        mmi_frm_appmem_prompt_to_release_mem(
            APPLIB_MEM_AP_ID_TEST3,
            IMG_GLOBAL_L3,
            MMI_FRM_APPMEM_TEST3_SIZE,
            mmi_frm_appmem_unit_test_success_callback3);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_unit_test_success_callback4
 * DESCRIPTION
 *  Callback function when memory was released.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void (*g_mmi_frm_appmem_unit_test_run_callback4)(void);

static void mmi_frm_appmem_unit_test_success_callback4(void)
{
    void *ptr = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_TEST4, MMI_FRM_APPMEM_TEST4_SIZE);
    MMI_ASSERT(ptr);
    g_mmi_frm_appmem_unit_test_run_callback4();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_unit_test_prepare_to_enter_test4
 * DESCRIPTION
 *  Simple program to test screen-based ASM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_appmem_unit_test_prepare_to_enter_test4(
    void (*run_callback)(void),
    MMI_BOOL clear_all)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (clear_all)
        applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST4);

    g_mmi_frm_appmem_unit_test_run_callback4 = run_callback;    
    if (applib_mem_ap_alloc(APPLIB_MEM_AP_ID_TEST4, MMI_FRM_APPMEM_TEST4_SIZE))
    {
        run_callback();
    }
    else
    {
        mmi_frm_appmem_prompt_to_release_mem(
            APPLIB_MEM_AP_ID_TEST4,
            IMG_GLOBAL_L4,
            MMI_FRM_APPMEM_TEST4_SIZE,
            mmi_frm_appmem_unit_test_success_callback4);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_unit_test_success_callback5
 * DESCRIPTION
 *  Callback function when memory was released.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void (*g_mmi_frm_appmem_unit_test_run_callback5)(void);

static void mmi_frm_appmem_unit_test_success_callback5(void)
{
    void *ptr = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_TEST5, MMI_FRM_APPMEM_TEST5_SIZE);
    MMI_ASSERT(ptr);
    g_mmi_frm_appmem_unit_test_run_callback5();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_unit_test_prepare_to_enter_test5
 * DESCRIPTION
 *  Simple program to test screen-based ASM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_appmem_unit_test_prepare_to_enter_test5(
    void (*run_callback)(void), 
    MMI_BOOL clear_all)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (clear_all)
        applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST5);

    g_mmi_frm_appmem_unit_test_run_callback5 = run_callback;    
    if (applib_mem_ap_alloc(APPLIB_MEM_AP_ID_TEST5, MMI_FRM_APPMEM_TEST5_SIZE))
    {
        run_callback();
    }
    else
    {
        mmi_frm_appmem_prompt_to_release_mem(
            APPLIB_MEM_AP_ID_TEST5,
            IMG_GLOBAL_L5,
            MMI_FRM_APPMEM_TEST5_SIZE,
            mmi_frm_appmem_unit_test_success_callback5);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_unit_test_setup_environment
 * DESCRIPTION
 *  Setup environment for unit test of app-based ASM 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_appmem_unit_test_setup_environment(MMI_BOOL stress_test)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static MMI_BOOL first_time = MMI_TRUE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (first_time)
    {
        first_time = MMI_FALSE;
        
        applib_mem_ap_register(
            APPLIB_MEM_AP_ID_TEST1, 
            STR_GLOBAL_1, 
            IMG_GLOBAL_L1, 
            mmi_frm_appmem_unit_test_stop_1);
        applib_mem_ap_register(
            APPLIB_MEM_AP_ID_TEST2, 
            STR_GLOBAL_2, 
            IMG_GLOBAL_L2, 
            mmi_frm_appmem_unit_test_stop_2);
        applib_mem_ap_register(
            APPLIB_MEM_AP_ID_TEST3, 
            STR_GLOBAL_3, 
            IMG_GLOBAL_L3, 
            mmi_frm_appmem_unit_test_stop_3);
        applib_mem_ap_register(
            APPLIB_MEM_AP_ID_TEST4, 
            STR_GLOBAL_4, 
            IMG_GLOBAL_L4, 
            mmi_frm_appmem_unit_test_stop_4);
        applib_mem_ap_register(
            APPLIB_MEM_AP_ID_TEST5, 
            STR_GLOBAL_5, 
            IMG_GLOBAL_L5, 
            mmi_frm_appmem_unit_test_stop_5);
    }

    if (stress_test)
        mmi_frm_appmem_unit_test_stress_alloc();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_ut_app_entry
 * DESCRIPTION
 *  entry function for APP N
 * PARAMETERS
 *  none
 * RETURNS
 *  none
 *****************************************************************************/
static void mmi_frm_ut_app_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopup((U8 *)(g_appmem_ut_cntx.item_list_str+g_appmem_ut_cntx.selected_item), 
                    IMG_GLOBAL_INFO, 0, TEST_APP_POPUP_TIME, SUCCESS_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_start
 * DESCRIPTION
 *  key handler to start unit-test function
 * PARAMETERS
 *  none
 * RETURNS
 *  none
 *****************************************************************************/
static void mmi_frm_appmem_ut_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* execute selected item */
    if (g_appmem_ut_cntx.selected_item == 0)
    {
        /* update memory info., do nothing here */
    }
    else if (g_appmem_ut_cntx.selected_item == 1)
    {
        mmi_frm_appmem_unit_test_stress_alloc();
    }
    else if (g_appmem_ut_cntx.selected_item >= TEST_ITEM_START)
    {
        if (g_appmem_ut_test_func[g_appmem_ut_cntx.selected_item-TEST_ITEM_START])
        {
            g_appmem_ut_test_func[g_appmem_ut_cntx.selected_item-TEST_ITEM_START](
                    mmi_frm_ut_app_entry, MMI_FALSE);
        }
    }
    
    /* redraw screen to update display info */
    if (GetActiveScreenId() == SCR_FRM_UNIT_TEST)
        mmi_frm_appmem_ut_2nd_entry(g_appmem_ut_cntx.selected_item);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_hilight_hdlr
 * DESCRIPTION
 *  high light handler
 * PARAMETERS
 *  index   [IN]    high-lighted item
 * RETURNS
 *  none
 *****************************************************************************/
static void mmi_frm_appmem_ut_hilight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_appmem_ut_cntx.selected_item = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_2nd_entry
 * DESCRIPTION
 *  display main appmem unit-test screen
 * PARAMETERS
 *  selected_item   [IN]    selected item
 * RETURNS
 *  none
 *****************************************************************************/
static void mmi_frm_appmem_ut_2nd_entry(S32 selected_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 tmp_str[TEST_ITEM_STR_LEN*ENCODING_LENGTH];
    U16 icon_list[TEST_ITEM_NUM+1];
    S32 i;
    U8 *gui_buffer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(TEST_ITEM_NUM < (IMG_GLOBAL_LEND-IMG_GLOBAL_LSTART));

    /* update memory info */
    sprintf(tmp_str, "Max. To Alloc: %d", applib_mem_ap_get_max_alloc_size());
    mmi_asc_to_ucs2(g_appmem_ut_cntx.item_list_str[0], tmp_str);

    /* initialize string data for each menu item */
    for (i=0; i<(TEST_ITEM_NUM-TEST_ITEM_START); i++)
    {
        sprintf(tmp_str, "APP %d (%d)", i+1, g_appmem_ut_allocate_size[i]);
        mmi_asc_to_ucs2(g_appmem_ut_cntx.item_list_str[i+TEST_ITEM_START], tmp_str);
        icon_list[TEST_ITEM_START+i] = IMG_GLOBAL_LSTART+(i+1);
    }
    icon_list[TEST_ITEM_NUM] = 0;

    gui_buffer = GetCurrGuiBuffer(SCR_FRM_UNIT_TEST);
    RegisterHighlightHandler(mmi_frm_appmem_ut_hilight_hdlr);

    ShowCategory53Screen(
        0,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        TEST_ITEM_NUM,
        (U8 **)g_appmem_ut_cntx.item_list,
        icon_list,
        NULL,
        0, g_appmem_ut_cntx.selected_item, gui_buffer);

    SetLeftSoftkeyFunction(mmi_frm_appmem_ut_start, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_entry
 * DESCRIPTION
 *  appmem unit-test screen entry function.
 * PARAMETERS
 *  none
 * RETURNS
 *  none
 *****************************************************************************/
void mmi_frm_appmem_ut_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_FRM_UNIT_TEST, NULL, mmi_frm_appmem_ut_entry, NULL);

    /* unit test initialization without stress test */
    mmi_frm_appmem_unit_test_setup_environment(MMI_FALSE);

    /* link item string data */
    for (i=0; i<TEST_ITEM_NUM; i++)
    {
        g_appmem_ut_cntx.item_list[i] = g_appmem_ut_cntx.item_list_str[i];
    }

    /* screen display */
    mmi_frm_appmem_ut_2nd_entry(g_appmem_ut_cntx.selected_item);
}


#endif /* APPLIB_MEM_UNIT_TEST */


