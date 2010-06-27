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
 * mmi_imps_common.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements common feature related functions for IMPS application.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"

#ifdef __MMI_IMPS__
/*  Include: MMI header file */
#include "Stdlib.h"
#include "ProtocolEvents.h"

#include "CommonScreens.h"
#include "SimDetectionGprot.h"


#include "wgui_inline_edit.h"

#include "custom_data_account.h"

#include "IMPSResDef.h"
#include "mmi_imps_prot.h"

#ifdef __USB_IN_NORMAL_MODE__
#include "USBDeviceGprot.h"
#endif 

/*  Include: PS header file */
/* ... Add More PS header */

/***************************************************************************** 
* Define
*****************************************************************************/

/***************************************************************************** 
* Typedef 
*****************************************************************************/

/***************************************************************************** 
* Local Variable
*****************************************************************************/

#define IMPS_NUM_INVITE 3
/* give some string at will to replaced by a specific icon */
static wgui_multiline_icon_struct g_imps_invite_icon_list[IMPS_NUM_INVITE] = 
{
    {NULL, 0, 0, "#$#"},        /* owner */
    {NULL, 0, 0, "$#$"},        /* group */
    {NULL, 0, 0, "##$"} /* note */
};

/***************************************************************************** 
* Local Function
*****************************************************************************/
static void mmi_imps_logout_confirm(void);

static void mmi_imps_input_verification_opt(void);
static void mmi_imps_hilite_input_verification_done(void);

/***************************************************************************** 
* Global Variable
*****************************************************************************/

extern wgui_inline_item wgui_inline_items[];
extern const U16 g_imps_inline_icons[];
extern const U16 g_imps_inline_icons[];

/***************************************************************************** 
* Global Function
*****************************************************************************/

#ifdef IMPS_TEST_CODE


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_test_login_complete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_test_login_complete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    imps_p->gen_info.is_login = TRUE;
    imps_p->gen_info.no_tab = 1;
    mmi_imps_pre_entry_cont();
    DeleteScreenIfPresent(SCR_ID_IMPS_PROGRESS);
    DeleteScreenIfPresent(SCR_ID_IMPS_MAIN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_test_invite_success
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_test_invite_success(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_invite_start(0, 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_test_invite_failed
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_test_invite_failed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_invite_start(-1, 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_test_server_disconn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_test_server_disconn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scr_id = GetActiveScreenId();
    BOOL cont_scr = IsScreenPresent(SCR_ID_IMPS_CONT);
    BOOL chat_scr = IsScreenPresent(SCR_ID_IMPS_CHAT);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imps_p->gen_info.is_login == TRUE)
    {
        mmi_imps_util_disp_warning_popup(STR_ID_IMPS_SERVER_DISCONNECT);

        /* check if the user is currently in IMPS application */
        /* it's currently in IMPS application */
        if (cont_scr || chat_scr || scr_id == SCR_ID_IMPS_CONT || scr_id == SCR_ID_IMPS_CHAT)
        {
            if (cont_scr)   /* in contact list screen */
            {
                HistoryReplace(SCR_ID_IMPS_CONT, SCR_ID_IMPS_MAIN, mmi_imps_entry_main);
            }
            else    /* chat screen */
            {
                DeleteUptoScrID(SCR_ID_IMPS_CHAT);
                HistoryReplace(SCR_ID_IMPS_CHAT, SCR_ID_IMPS_MAIN, mmi_imps_entry_main);
            }
            DeleteUptoScrID(SCR_ID_IMPS_MAIN);
        }
    }
    mmi_imps_util_free_buff_when_logout();
    mmi_imps_reset_cntx();
}
#endif /* IMPS_TEST_CODE */ 

#define MAIN_IMPS


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_init_common_hilite_hdlr
 * DESCRIPTION
 *  Initialize all common highlight handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_init_common_hilite_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU_ID_IMPS_LOGIN, mmi_imps_hilite_login);
    SetHiliteHandler(MENU_ID_IMPS_CONT_LOGOUT, mmi_imps_hilite_logout);

    /* subscribe/unsubscribe notify */
    SetHiliteHandler(MENU_ID_IMPS_CONT_SUBS_UNSUBS_NOTIFY, mmi_imps_hilite_subs_unsubs_notify);   
    
    SetHiliteHandler(MENU_ID_IMPS_INPUT_VERIFY_OPT_DONE, mmi_imps_hilite_input_verification_done);
    SetHiliteHandler(MENU_ID_IMPS_INPUT_VERIFY_OPT_INPUT_METH, mmi_imps_hilite_comm_input_meth);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_init_icon_list
 * DESCRIPTION
 *  Initialize invication icon mapping table
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_init_invite_icon_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 width, height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* initialize invite table */
    for (i = 0; i < IMPS_NUM_INVITE; i++)
    {
        /* file icons */
        g_imps_invite_icon_list[i].icon = (PU8) GetImage((U16) (IMG_ID_IMPS_CONT_LIST + i));

        /* measure height and width */
        gui_measure_image(g_imps_invite_icon_list[i].icon, &width, &height);
        g_imps_invite_icon_list[i].icon_height = (U8) height;
        g_imps_invite_icon_list[i].icon_width = (U8) width;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_main
 * DESCRIPTION
 *  Highlight handler of IMPS menu in Message screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_pre_entry_main, KEY_EVENT_UP);
    SetKeyHandler(mmi_imps_pre_entry_main, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_pre_entry_main
 * DESCRIPTION
 *  Pre-Entry function of Message -> Instant Message menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_pre_entry_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __USB_IN_NORMAL_MODE__
	/* in mass storage mode */
    if (mmi_usb_is_in_mass_storage_mode())
    {
        mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
        return; 
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    /* some action that is not finished */
    if (imps_p->gen_info.curr_action == MSG_ID_MMI_IMPS_LOGIN_REQ)      /* login can be aborted */
    {
        mmi_imps_login_progress();
        if (imps_p->system_message != NULL)
        {
            if (imps_p->system_message->curr_index > 0)  /* re entry case */
            {
                imps_p->system_message->curr_index --;
            }
            mmi_imps_check_system_message();
        }
        else
        {
        imps_p->gen_info.is_reentry = TRUE;
    }
    }
    else if (imps_p->gen_info.curr_action != 0)
    {
        mmi_imps_display_progressing();
        imps_p->gen_info.is_reentry = TRUE;
    }
    else if (imps_p->gen_info.is_login == TRUE)
    {
        mmi_imps_pre_entry_cont();
    }
    else
    {
        mmi_imps_entry_main();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_main
 * DESCRIPTION
 *  Entry first screen of IMPS (login/profile setting)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_main(void)
{	 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 numItems;
    U16 nStrItemList[2];    /* only Login and Profile Setting */
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_IMPS_MAIN, NULL, mmi_imps_entry_main, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMPS_MAIN);
    SetParentHandler(MENU_ID_IMPS_MAIN);
    numItems = GetNumOfChild(MENU_ID_IMPS_MAIN);
    GetSequenceStringIds(MENU_ID_IMPS_MAIN, nStrItemList);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ShowCategory52Screen(
        STR_ID_IMPS,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_login
 * DESCRIPTION
 *  Highlight handler of IMPS -> Login
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_login(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_entry_login, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_login_progress
 * DESCRIPTION
 *  Entry progressing screen for login
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_login_progress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_pre_entry_progressing(
        STR_ID_IMPS,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        0,
        0,
        STR_GLOBAL_ABORT,
        0,
        (U8*) GetString(STR_ID_IMPS_LOGIN),
        NULL,
        IMG_GLOBAL_PROGRESS,
        NULL,
        mmi_imps_login_abort,
        mmi_imps_login_abort);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_auto_login
 * DESCRIPTION
 *  Auto login IMPS application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_auto_login(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_prof_struct *act_prof = &imps_p->act_prof;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* something still not ready */
    if (imps_p->gen_info.ps_ready_state != IMPS_LOGIN_READY
#ifdef __FLIGHT_MODE_SUPPORT__            
            || mmi_bootup_get_active_flight_mode() == FLIGHTMODE_SILENT  /* flight mode */
#endif
        )
    {
        return;
    }

    if (mmi_ucs2strlen((S8*) act_prof->prof_name) != 0)
    {
        if (act_prof->auto_login &&
            act_prof->dt_acct >= CUSTOM_DEFAULT_IMPS_DTCNT_ID)
        {
            /* currently in IMPS related menus */
            if (GetActiveScreenId() == SCR_ID_IMPS_MAIN || IsScreenPresent(SCR_ID_IMPS_MAIN))
            {
                mmi_imps_entry_auto_login_confirm();
            }
            else    /* in other application menu */
            {
                /* display auto-login screen and send request to PS */
                mmi_imps_entry_auto_login();
                mmi_imps_ps_login_req();
            }
        }

        imps_p->gen_info.ps_ready_state |= IMPS_LOGIN_ALREADY;  /* set this value to prevent lots of auto-login */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_auto_login
 * DESCRIPTION
 *  Display auto-login screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_auto_login(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* currently in IMPS main menu */
    if (GetActiveScreenId() == SCR_ID_IMPS_MAIN)
    {
        mmi_imps_login_progress();
    }
    else    /* main menu is in history */
    {
        HistoryReplace(SCR_ID_IMPS_MAIN, SCR_ID_IMPS_PROGRESS, mmi_imps_login_progress);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_auto_login_confirm
 * DESCRIPTION
 *  Display confirmation screen to auto-login
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_auto_login_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_entry_confirm(STR_ID_IMPS_LOGIN, mmi_imps_auto_login_yes, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_auto_login_yes
 * DESCRIPTION
 *  Confirm to proceed login process
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_auto_login_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* display auto-login screen and send request to PS */
    mmi_imps_login_progress();
    mmi_imps_ps_login_req();
    DeleteUptoScrID(SCR_ID_IMPS_MAIN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_login
 * DESCRIPTION
 *  Pre-Entry function of Login
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_login(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((S8*) imps_p->act_prof.prof_name) == 0)
    {
        mmi_imps_util_disp_err_popup(STR_ID_IMPS_PROF_NO_CONFIG);
    }
#ifdef IMPS_TEST_CODE
    else
    {
        mmi_imps_login_progress();
        SetKeyHandler(mmi_imps_test_login_complete, KEY_SEND, KEY_EVENT_UP);
    }
#else /* IMPS_TEST_CODE */ 
    else if (imps_p->gen_info.ps_ready_state >= IMPS_LOGIN_READY)
    {
        /* send request to login */
        mmi_imps_login_progress();
        mmi_imps_ps_login_req();
        imps_p->gen_info.ps_ready_state |= IMPS_LOGIN_ALREADY;  /* set this value to prevent lots of auto-login */
    }
    else
    {
        mmi_imps_util_disp_warning_popup(STR_ID_IMPS_NOT_READY);
    }
#endif /* IMPS_TEST_CODE */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_login_abort
 * DESCRIPTION
 *  Abort login process
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_login_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_entry_abort();

#ifdef IMPS_TEST_CODE
    SetKeyHandler(mmi_imps_login_abort_finish, KEY_SEND, KEY_EVENT_DOWN);
#else /* IMPS_TEST_CODE */ 
    /* send abort request to PS */
    mmi_imps_ps_abort_login_req();
#endif /* IMPS_TEST_CODE */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_login_abort_finish
 * DESCRIPTION
 *  Finish aborting process
 * PARAMETERS
 *  void
 *  result(?)       [IN]        Result of aborting(?)(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_login_abort_finish(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsScreenPresent(SCR_ID_IMPS_MAIN))
    {
        if (GetActiveScreenId() == SCR_ID_IMPS_PROGRESS)
        {
            GoBackToHistory(SCR_ID_IMPS_MAIN);
        }
        else
        {
            DeleteScreenIfPresent(SCR_ID_IMPS_PROGRESS);
        }
    }
    else    /* auto-update case */
    {
        if (GetActiveScreenId() == SCR_ID_IMPS_PROGRESS)
        {
            mmi_imps_entry_main();
            DeleteScreenIfPresent(SCR_ID_IMPS_PROGRESS);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_re_entry_app
 * DESCRIPTION
 *  Re-Entry IMPS application after progressing finished
 * PARAMETERS
 *  void
 *  result(?)       [IN]        Result of aborting(?)(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_re_entry_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetActiveScreenId() == SCR_ID_IMPS_PROGRESS)
    {
        if (imps_p->gen_info.is_login)
        {
            mmi_imps_pre_entry_cont();
        }
        else
        {
            mmi_imps_entry_main();
        }

        DeleteScreenIfPresent(SCR_ID_IMPS_PROGRESS);
    }
    else    /* some interrupt came */
    {
        if (imps_p->gen_info.is_login)
        {
            HistoryReplace(SCR_ID_IMPS_PROGRESS, SCR_ID_IMPS_CONT, mmi_imps_pre_entry_cont);
        }
        else
        {
            HistoryReplace(SCR_ID_IMPS_PROGRESS, SCR_ID_IMPS_MAIN, mmi_imps_entry_main);
        }
    }

    imps_p->gen_info.is_reentry = FALSE;
}


#define LOGOUT_IMPS


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_logout
 * DESCRIPTION
 *  Hilite handler of Contact List -> Logout option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_logout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_logout_confirm, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_logout_confirm
 * DESCRIPTION
 *  Entry confirm function of Logout menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imps_logout_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_entry_confirm(STR_ID_IMPS_LOGOUT, mmi_imps_entry_logout, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_logout
 * DESCRIPTION
 *  Entry function of Logout menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_logout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_display_progressing();
#ifdef IMPS_TEST_CODE
    mmi_imps_logout_complete();
#else 
    mmi_imps_ps_logout_req();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_logout_complete
 * DESCRIPTION
 *  Entry function after logout response comes.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_logout_complete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetActiveScreenId() == SCR_ID_IMPS_PROGRESS)
    {
        if (IsScreenPresent(SCR_ID_IMPS_MAIN))
        {
            GoBackToHistory(SCR_ID_IMPS_MAIN);
            return;
        }
        else
        {
            mmi_imps_entry_main();
        }
        DeleteBetweenScreen(SCR_ID_IMPS_CONT, SCR_ID_IMPS_PROGRESS);
    }
    else
    {
        mmi_imps_util_del_scr_after_progress(SCR_ID_IMPS_CONT);
        HistoryReplace(SCR_ID_IMPS_CONT, SCR_ID_IMPS_MAIN, mmi_imps_entry_main);
    }

    mmi_imps_util_free_buff_when_logout();
    mmi_imps_reset_cntx();
}


#define SEARCH_IMPS

/*****************************************************************************
 * FUNCTION
 *  mmi_imps_search_abort
 * DESCRIPTION
 *  Abort searching process
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_search_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_entry_abort();
#ifdef IMPS_TEST_CODE
    SetKeyHandler(mmi_imps_abort_search_finish, KEY_SEND, KEY_EVENT_DOWN);
#else 
    mmi_imps_ps_abort_search_req();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_abort_search_finish
 * DESCRIPTION
 *  Finish aborting search process.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_abort_search_finish(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imps_p->gen_info.is_reentry)
    {
        mmi_imps_re_entry_app();
    }
    else
    {
        if (imps_p->search_result.count)    /* some result already came back */
        {
            mmi_imps_entry_search_result();
            mmi_imps_util_del_scr_after_progress(SCR_ID_IMPS_ADD_CONT);
        }
        else
        {
            U16 end_menu;

            if (imps_p->search_result.search_cause == IMPS_SEARCH_WATCHER)
            {
                end_menu = SCR_ID_IMPS_CONT_OPT;
            }
            else
            {
                end_menu = SCR_ID_IMPS_SEARCH_OPT;
            }

            if (GetActiveScreenId() == SCR_ID_IMPS_PROGRESS)
            {
                GoBackToHistory(end_menu);
            }
            else
            {
                mmi_imps_util_del_scr_after_progress(end_menu);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_search_result
 * DESCRIPTION
 *  Display list of search result
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_search_result(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S32 i;
    S32 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    count = (S32) imps_p->search_result.count;

    if (count == 0)
    {
        mmi_imps_util_disp_empty_popup();
        return;
    }

    for (i = 0; i < count; i++)
    {
        mmi_imps_util_ansi_2_ucs2_menu(
            (S8*) imps_p->search_result.entity[i].id,
            (S8*) subMenuData[i],
            MAX_SUBMENU_CHARACTERS);
        mmi_imps_util_generate_name_hint((S8*) imps_p->search_result.entity[i].sname, i, MAX_SUBMENU_CHARACTERS);
        subMenuDataPtrs[i] = subMenuData[i];
    }

    EntryNewScreen(SCR_ID_IMPS_SEARCH_RESULT, NULL, mmi_imps_entry_search_result, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMPS_SEARCH_RESULT);

    SetParentHandler(0);

    RegisterHighlightHandler(mmi_imps_hilite_search_result);

    ShowCategory53Screen(
        STR_ID_IMPS_SEARCH_RESULT,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        STR_GLOBAL_ADD,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        count,
        (U8 **) subMenuDataPtrs,
        (U16*) gIndexIconsImageList,
        (U8 **) hintDataPtrs,
        0,
        0,
        guiBuffer);

    if (imps_p->search_result.search_cause == IMPS_SEARCH_ROOM)
    {
        ChangeLeftSoftkey(STR_ID_IMPS_JOIN, IMG_GLOBAL_OK);
        SetLeftSoftkeyFunction(mmi_imps_pre_entry_join, KEY_EVENT_UP);
    }
    else    /* search chat room */
    {
        if (imps_p->cont_info.no_cont >= IMPS_MAX_NO_CONT || imps_p->group_info.no_group == 0)
        {
            ChangeLeftSoftkey(0, 0);
        }
        else
        {
            SetLeftSoftkeyFunction(mmi_imps_pre_entry_sel_group, KEY_EVENT_UP);
        }
    }

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_search_result
 * DESCRIPTION
 *  Highlight handler of result list. Store index of current selecting item.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_search_result(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    imps_p->search_result.curr_item = (U8) index;
}

#define INVITE_IMPS


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_chat_invite
 * DESCRIPTION
 *  Highlight handler of Invite Friend menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_chat_invite(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_pre_entry_chat_invite, KEY_EVENT_UP);
    SetKeyHandler(mmi_imps_pre_entry_chat_invite, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_pre_entry_chat_invite
 * DESCRIPTION
 *  Pre-Entry function of Invite menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_pre_entry_chat_invite(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    imps_p->room_info.invite_or_add = IMPS_INVITE_ONLINE;
    mmi_imps_entry_chat_invite();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_chat_invite
 * DESCRIPTION
 *  Entry function of Invite menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_chat_invite(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 icon_list[IMPS_MAX_NO_CONT];
    U16 scr_id = 0, title = 0;
    S32 i, k, no_cont;
    mmi_imps_cont_struct *cont;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    no_cont = (S32) imps_p->cont_info.no_cont;
    k = 0;

    for (i = 1; i < no_cont; i++)   /* neglect MySelf */
    {
        cont = &imps_p->cont_info.cont_list[i];
        if (cont->availability == IMPS_PA_USER_NOT_AVAILABLE || 
            cont->availability == IMPS_PA_USER_UNKNOWN)
        {
            continue;
        }

        if (imps_p->room_info.invite_or_add == IMPS_INVITE_ONLINE &&
            cont->comm_state & IMPS_CONT_BLOCK)
        {
            continue;
        }

        mmi_imps_util_ansi_2_ucs2_menu((S8*) cont->id, (S8*) subMenuData[k], MAX_SUBMENU_CHARACTERS);
        mmi_imps_util_generate_name_hint((S8*) cont->nick_name, k, MAX_SUBMENU_CHARACTERS);
        imps_p->invite_info.invite_cand_list[k] = (U8) i;
        subMenuDataPtrs[k] = subMenuData[k];
        k++;
    }
    
    imps_p->invite_info.invite_count = (U8) k;
    
    if (k == 0)
    {
        mmi_imps_util_disp_empty_popup();
        return;
    }

    if (imps_p->room_info.invite_or_add == IMPS_INVITE_ONLINE)
    {
        scr_id = SCR_ID_IMPS_INVITE;
        title = STR_ID_IMPS_INVITE;
    }
    else if (imps_p->room_info.invite_or_add == IMPS_ADD_MEMBER_ONLINE)
    {
        scr_id = SCR_ID_IMPS_ADD_MEMBER_FROM_ONLINE;
        title = STR_ID_IMPS_ADD_FROM_ONLINE;
    }

    EntryNewScreen(scr_id, NULL, mmi_imps_entry_chat_invite, NULL);

    guiBuffer = GetCurrGuiBuffer(scr_id);

    SetParentHandler(0);

    RegisterHighlightHandler(mmi_imps_hilite_invite_item);

    for (i = 0; i < imps_p->invite_info.invite_count; i++)
    {
        icon_list[i] = IMG_ID_IMPS_ABOUT_ONLINE;
    }

    ShowCategory53Screen(
        title,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        imps_p->invite_info.invite_count,
        (U8 **) subMenuDataPtrs,
        (U16*) icon_list,
        (U8 **) hintDataPtrs,
        0,
        0,
        guiBuffer);

    if (imps_p->room_info.invite_or_add == IMPS_INVITE_ONLINE)
    {
        SetLeftSoftkeyFunction(mmi_imps_entry_invite_note, KEY_EVENT_UP);
        SetKeyHandler(mmi_imps_entry_invite_note, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
    else if (imps_p->room_info.invite_or_add == IMPS_ADD_MEMBER_ONLINE)
    {
        SetLeftSoftkeyFunction(mmi_imps_add_member_from_online, KEY_EVENT_UP);
        SetKeyHandler(mmi_imps_add_member_from_online, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_invite_item
 * DESCRIPTION
 *  Highlight handler of invite candidate list
 * PARAMETERS
 *  index       [IN]        Index of highlighting item
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_invite_item(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    imps_p->invite_info.curr_sel_cont = (U8) index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_invite_note
 * DESCRIPTION
 *  Entry function to input inviting note
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_invite_note(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_IMPS_INVITE_NOTE, NULL, mmi_imps_entry_invite_note, NULL);

    SetParentHandler(0);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMPS_INVITE_NOTE);

    if (guiBuffer == NULL)  /* first time entry, reset input buffer */
    {
        imps_p->path_buff[0] = 0;
    }

    ShowCategory5Screen(
        STR_ID_IMPS_INVITE_NOTE,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        (U8*) imps_p->path_buff,    /* reuse path buffer */
        IMPS_MAX_NOTE_LEN,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_imps_entry_invite_note_opt, KEY_EVENT_UP);

    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_invite_note_opt
 * DESCRIPTION
 *  Display options for inviting note
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_invite_note_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 numItems;
    U16 nStrItemList[2];
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_IMPS_CHAT_NOTE_OPT, NULL, mmi_imps_entry_invite_note_opt, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMPS_CHAT_NOTE_OPT);
    SetParentHandler(MENU_ID_IMPS_ROOM_INVITE_OPT);
    numItems = GetNumOfChild(MENU_ID_IMPS_ROOM_INVITE_OPT);
    GetSequenceStringIds(MENU_ID_IMPS_ROOM_INVITE_OPT, nStrItemList);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_invite_note_opt_done
 * DESCRIPTION
 *  Highlight handler of List Member menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_invite_note_opt_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_invite_done, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_invite_done
 * DESCRIPTION
 *  Finish invitation input and start inviting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_invite_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* check if all sessions are occupied */
    S32 session_id = mmi_imps_invite_insert_session();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (session_id == 0)
    {
        mmi_imps_util_play_tone(IMPS_ERR_TONE);
        mmi_imps_invite_disp_failed_msg();        
    }
    else
    {
        mmi_imps_invite_disp_msg();
        imps_p->room_info.room_list[imps_p->chat_info.curr_room].clear_gui_buff = TRUE;
    #ifndef IMPS_TEST_CODE
        mmi_imps_ps_invite_req(session_id);
    #else /* IMPS_TEST_CODE */ 
        SetKeyHandler(mmi_imps_test_invite_success, KEY_STAR, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_imps_test_invite_failed, KEY_POUND, KEY_EVENT_DOWN);
    #endif /* IMPS_TEST_CODE */ 
    }

    GoBackToHistory(SCR_ID_IMPS_CHAT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_invite_insert_session
 * DESCRIPTION
 *  insert Invitation to session list
 * PARAMETERS
 *  void
 * RETURNS
 *  session index
 *****************************************************************************/
S32 mmi_imps_invite_insert_session(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < IMPS_MAX_INVITEE_SESSION; i++)
        if (imps_p->invite_info.invite_session[i].session_id == 0)
        {
            break;
        }

    if (i == IMPS_MAX_INVITEE_SESSION)
    {
        return 0;
    }
    else
    {
        mmi_imps_invite_session_struct *session = &imps_p->invite_info.invite_session[i];

        session->session_id = mmi_imps_util_get_seq_no();
        strcpy(
            (S8*) session->cont_id,
            (S8*) imps_p->cont_info.cont_list[imps_p->invite_info.invite_cand_list[imps_p->invite_info.curr_sel_cont]].id);
        strcpy((S8*) session->room_id, (S8*) imps_p->room_info.room_list[imps_p->chat_info.curr_room].room_id);
        return session->session_id;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_invite_disp_msg
 * DESCRIPTION
 *  Display invitation message in chat buffer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_invite_disp_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *tmp_cont_buff;
    U16 *tmp_disp_buff = OslMalloc(IMPS_MAX_CHAT_BUFF * ENCODING_LENGTH);
    mmi_imps_cont_struct *cont =
        &imps_p->cont_info.cont_list[imps_p->invite_info.invite_cand_list[imps_p->invite_info.curr_sel_cont]];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* insert input into buffer */
    mmi_ucs2cpy((S8*) tmp_disp_buff, (S8*) GetString(STR_ID_IMPS_INVITING));
    mmi_ucs2cat((S8*) tmp_disp_buff, (S8*) L" ");

    if (mmi_ucs2strlen((S8*) cont->nick_name))
    {
        mmi_ucs2cat((S8*) tmp_disp_buff, (S8*) cont->nick_name);
    }
    else
    {
        tmp_cont_buff = OslMalloc(IMPS_MAX_ID_LEN * ENCODING_LENGTH);
        mmi_asc_to_ucs2((S8*) tmp_cont_buff, (S8*) cont->id);
        mmi_ucs2cat((S8*) tmp_disp_buff, (S8*) tmp_cont_buff);
        OslMfree(tmp_cont_buff);
    }
    mmi_ucs2cat((S8*) tmp_disp_buff, (S8*) L"\n\n");

    mmi_imps_chat_flush_msg(tmp_disp_buff, imps_p->chat_info.curr_room);

    OslMfree(tmp_disp_buff);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_invite_disp_failed_msg
 * DESCRIPTION
 *  Display invitation failed message.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_invite_disp_failed_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *tmp_disp_buff = OslMalloc(IMPS_MAX_CHAT_BUFF * ENCODING_LENGTH);
    mmi_imps_cont_struct *cont =
        &imps_p->cont_info.cont_list[imps_p->invite_info.invite_cand_list[imps_p->invite_info.curr_sel_cont]];
    wgui_color_buffer_writer_struct writer;
    BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tmp_disp_buff[0] = 0;
    wgui_color_buffer_create_writer(&writer, (U8*) tmp_disp_buff, IMPS_MAX_CHAT_BUFF * ENCODING_LENGTH);
    wgui_color_buffer_write_char(&writer, GUI_INPUT_COLOR_00);

    wgui_color_buffer_write_string(&writer, (U8*) GetString(STR_ID_IMPS_INVITE_FAIL), MMI_FALSE, &result);

    /* insert input into buffer */
    wgui_color_buffer_write_char(&writer, ' ');
    if (mmi_ucs2strlen((S8*) cont->nick_name))
    {
        wgui_color_buffer_write_string(&writer, (U8*) cont->nick_name, MMI_FALSE, &result);
    }
    else
    {
        U16 *tmp_id_buff;

        tmp_id_buff = OslMalloc(IMPS_MAX_ID_LEN * ENCODING_LENGTH);
        mmi_asc_to_ucs2((S8*) tmp_id_buff, (S8*) cont->id);
        wgui_color_buffer_write_string(&writer, (U8*) tmp_id_buff, MMI_FALSE, &result);
        OslMfree(tmp_id_buff);
    }

    wgui_color_buffer_write_char(&writer, GUI_INPUT_MARKER_RESET_ALL);

    wgui_color_buffer_write_string(&writer, (U8*) L"\n\n", MMI_FALSE, &result);

    mmi_imps_chat_flush_msg(tmp_disp_buff, imps_p->chat_info.curr_room);

    OslMfree(tmp_disp_buff);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_invite_rsp_success_msg
 * DESCRIPTION
 *  Display invitation failed message.
 * PARAMETERS
 *  session     [IN]        Invitation session
 *  sname       [IN]        Screen name of the invitee
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_invite_rsp_success_msg(mmi_imps_invite_session_struct *session, S8 *sname)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *tmp_disp_buff = OslMalloc(IMPS_MAX_CHAT_BUFF * ENCODING_LENGTH);
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* insert input into buffer */
    if (mmi_ucs2strlen(sname))
    {
        mmi_ucs2cpy((S8*) tmp_disp_buff, (S8*) sname);
    }
    else    /* no screen name */
    {
        mmi_asc_to_ucs2((S8*) tmp_disp_buff, (S8*) session->cont_id);
    }

    mmi_ucs2cat((S8*) tmp_disp_buff, (S8*) L" ");
    mmi_ucs2cat((S8*) tmp_disp_buff, (S8*) GetString(STR_ID_IMPS_JOINED_ROOM));
    mmi_ucs2cat((S8*) tmp_disp_buff, (S8*) L"\n");

    /* find out the room index */
    for (i = 0; i < IMPS_MAX_NO_ROOM; i++)
    {
        if (mmi_imps_util_is_id_same((S8*) session->room_id, (S8*) imps_p->room_info.room_list[i].room_id))
        {
            break;
        }
    }

    MMI_ASSERT(i < IMPS_MAX_NO_ROOM);

    mmi_imps_chat_flush_msg(tmp_disp_buff, i);
    OslMfree(tmp_disp_buff);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_invite_rsp_failed_msg
 * DESCRIPTION
 *  Display invitation failed message.
 * PARAMETERS
 *  session     [?]     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_invite_rsp_failed_msg(mmi_imps_invite_session_struct *session)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U16 *tmp_disp_buff = OslMalloc(IMPS_MAX_CHAT_BUFF * ENCODING_LENGTH);
    U16 *tmp_id_buff = OslMalloc(IMPS_MAX_ID_LEN * ENCODING_LENGTH);
    S32 cont_index;
    mmi_imps_cont_struct *cont;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cont_index = mmi_imps_util_find_cont((S8*) session->cont_id);

    if (cont_index == imps_p->cont_info.no_cont)    /* nobody found */
    {
        mmi_asc_to_ucs2((S8*) tmp_id_buff, (S8*) session->cont_id);
    }
    else
    {
        cont = &imps_p->cont_info.cont_list[cont_index];
        if (mmi_ucs2strlen((S8*) cont->nick_name))
        {
            mmi_ucs2cpy((S8*) tmp_id_buff, (S8*) cont->nick_name);
        }
        else
        {
            mmi_asc_to_ucs2((S8*) tmp_id_buff, (S8*) session->cont_id);
        }
    }

    /* insert input into buffer */
    mmi_ucs2cpy((S8*) tmp_disp_buff, (S8*) GetString(STR_ID_IMPS_INVITE_FAIL));
    mmi_ucs2cat((S8*) tmp_disp_buff, (S8*) L" ");
    mmi_ucs2cat((S8*) tmp_disp_buff, (S8*) tmp_id_buff);
    mmi_ucs2cat((S8*) tmp_disp_buff, (S8*) L"\n\n");
    OslMfree(tmp_id_buff);

    /* find out the room index */
    for (i = 0; i < IMPS_MAX_NO_ROOM; i++)
    {
        if (mmi_imps_util_is_id_same((S8*) session->room_id, (S8*) imps_p->room_info.room_list[i].room_id))
        {
            break;
        }
    }

    MMI_ASSERT(i < IMPS_MAX_NO_ROOM);

    mmi_imps_chat_flush_msg(tmp_disp_buff, i);

    OslMfree(tmp_disp_buff);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_invite_start
 * DESCRIPTION
 *  Start invitation process in PS
 * PARAMETERS
 *  result      [IN]        Result of invitation
 *  id          [IN]        Session index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_invite_start(S32 result, S32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    mmi_imps_invite_session_struct *session = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < IMPS_MAX_INVITEE_SESSION; i++)
    {
        if (imps_p->invite_info.invite_session[i].session_id == id)
        {
            session = &imps_p->invite_info.invite_session[i];
            break;
        }
    }

    if (session == NULL)
    {
        return;
    }

    /* update display buffer and context */
    if (result != IMPS_OK)
    {
        mmi_imps_room_struct *room = &imps_p->room_info.room_list[mmi_imps_util_find_room((S8*) session->room_id)];

	mmi_imps_util_play_tone(IMPS_ERR_TONE);
        mmi_imps_invite_rsp_failed_msg(session);
        mmi_imps_tab_update_event(room, NULL);

        /* clear session */
        session->session_id = 0;
        session->cont_id[0] = 0;
        session->room_id[0] = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_invite_finish
 * DESCRIPTION
 *  Finish invitation in PS. This function is the response handler from PS
 * PARAMETERS
 *  accept          [IN]        If the user accept invitation or not
 *  session_id      [IN]        Id of the invitation session
 *  sender          [IN]        User who accepted the invitation
 *  note            [IN]        Response note of the invitee
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_invite_finish(BOOL accept, S32 session_id, imps_entity_struct *sender, U16 *note)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    mmi_imps_invite_session_struct *session = NULL;
    mmi_imps_room_struct *room = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* find out if a session corresponding to it */
    for (i = 0; i < IMPS_MAX_INVITEE_SESSION; i++)
    {
        if (imps_p->invite_info.invite_session[i].session_id == session_id)
        {
            session = &imps_p->invite_info.invite_session[i];
            break;
        }
    }

    if (session == NULL)
    {
        return;
    }

    /* find out the chat room it belongs to */
    for (i = 0; i < IMPS_MAX_NO_ROOM; i++)
    {
        if (mmi_imps_util_is_id_same((S8*) session->room_id, (S8*) imps_p->room_info.room_list[i].room_id))
        {
            room = &imps_p->room_info.room_list[i];
            break;
        }
    }

    /* session exists without chat room -- clear the session */
    if (room == NULL)
    {
        session->session_id = 0;
        session->cont_id[0] = 0;
        session->room_id[0] = 0;
        return;
    }

    if (accept == FALSE)
    {
        mmi_imps_util_play_tone(IMPS_ERR_TONE);
        mmi_imps_invite_rsp_failed_msg(session);        
    }
    else
    {
        S8 *tmp_disp_buff = OslMalloc(IMPS_MAX_ID_LEN * ENCODING_LENGTH);
        S32 sname_len = mmi_ucs2strlen((S8*) sender->sname);

	mmi_imps_util_play_tone(IMPS_MSG_TONE);

        if (sname_len)
        {
            mmi_imps_invite_rsp_success_msg(session, (S8*) sender->sname);
        }
        else
        {
            mmi_asc_to_ucs2(tmp_disp_buff, (S8*) sender->id);
            mmi_imps_invite_rsp_success_msg(session, (S8*) tmp_disp_buff);
        }

        OslMfree(tmp_disp_buff);
    }

    /* update UI display */
    mmi_imps_tab_update_event(room, NULL);

    /* reset session */
    session->session_id = 0;
    session->cont_id[0] = 0;
    session->room_id[0] = 0;
}

#define INVITE_IND_IMPS


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_check_pending_invite
 * DESCRIPTION
 *  Check if there is any pending invitation
 * PARAMETERS
 *  void
 *  msg(?)      [IN]        Message of invitation.(?)(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_check_pending_invite(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* pending invitation exists */

    if (imps_p->invite_info.invite_pending_list[imps_p->invite_info.curr_pend_invite].node != NULL)
    {
        /* entry invitation screen */
        mmi_imps_entry_invite_ind();
        mmi_imps_util_play_tone(IMPS_MSG_TONE);
    }
    else
    {
        mmi_imps_check_pa_auth();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_invite_ind
 * DESCRIPTION
 *  Entry invite indication screen
 * PARAMETERS
 *  void
 *  msg(?)      [IN]        Message of invitation.(?)(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_invite_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_IMPS_INVITATION_IND, NULL, mmi_imps_entry_invite_ind, NULL);    

    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMPS_INVITATION_IND);

    SetParentHandler(0);

    mmi_imps_invite_ind_gen_note();

    /* configure icons */
    wgui_config_general_multiline_icon_handler(MMI_FALSE, IMPS_NUM_INVITE, g_imps_invite_icon_list);

    ShowCategory78Screen(
        STR_ID_IMPS_INVITATION,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        STR_ID_IMPS_JOIN,
        IMG_GLOBAL_OK,
        STR_GLOBAL_QUIT,
        IMG_GLOBAL_BACK,
        wgui_general_multiline_icon_handler,
        (U8*) imps_p->invite_info.invite_note,
        mmi_ucs2strlen(imps_p->invite_info.invite_note),
        guiBuffer);

    /* re-use join screen */
    SetLeftSoftkeyFunction(mmi_imps_pre_entry_join, KEY_EVENT_UP);

    SetRightSoftkeyFunction(mmi_imps_ps_invite_reject, KEY_EVENT_UP);

    SetDelScrnIDCallbackHandler(SCR_ID_IMPS_INVITATION_IND, (HistoryDelCBPtr) mmi_imps_invite_ind_scr_del_callback);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_invite_reject
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_invite_reject(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_display_progressing();
    mmi_imps_ps_invite_reply_req(FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_invite_ind_scr_del_callback
 * DESCRIPTION
 *  Function to free memory when invitation screen deleted.
 * PARAMETERS
 *  param       [?]     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_imps_invite_ind_scr_del_callback(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_invite_ind_free_mem();

    mmi_imps_invite_ind_release_node();

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_invite_reminder_del_callback
 * DESCRIPTION
 *  Function to free memory when invitation reminder screen deleted.
 * PARAMETERS
 *  param       [?]     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_imps_invite_reminder_del_callback(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_invite_ind_free_mem();

    imps_p->invite_info.reminder_flag = FALSE;

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_invite_ind_free_mem
 * DESCRIPTION
 *  Free memory of invitation screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_invite_ind_free_mem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imps_p->invite_info.invite_note)
    {
        OslMfree(imps_p->invite_info.invite_note);
        imps_p->invite_info.invite_note = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_invite_ind_free_n_back
 * DESCRIPTION
 *  Free memory of invitation screen and go back to previous screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_invite_ind_free_n_back(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* release note buffer */
    mmi_imps_invite_ind_free_mem();

    /* release the holding local parameter */
    mmi_imps_invite_ind_release_node();

    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_invite_ind_release_node
 * DESCRIPTION
 *  Release the holding local parameter
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_invite_ind_release_node(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = (S32) imps_p->invite_info.curr_pend_invite;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imps_p->invite_info.invite_pending_list[i].node)
    {
        free_local_para((local_para_struct*) imps_p->invite_info.invite_pending_list[i].node);
        imps_p->invite_info.invite_pending_list[i].node = NULL;
    }

    /* move index to the next node */
    i++;

    if (i == IMPS_MAX_PEND_INVITATION)
    {
        imps_p->invite_info.curr_pend_invite = 0;
    }
    else
    {
        imps_p->invite_info.curr_pend_invite = (U8) i;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_invite_ind_gen_note
 * DESCRIPTION
 *  Generate invitation note of indication screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_invite_ind_gen_note(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *note;
    S8 *tmp_buff = OslMalloc(IMPS_MAX_NOTE_LEN * ENCODING_LENGTH);      /* temporary buffer for icon */
    mmi_imps_invite_ind_struct *invite_ind =
        imps_p->invite_info.invite_pending_list[imps_p->invite_info.curr_pend_invite].node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imps_p->invite_info.invite_note == NULL)
    {
        imps_p->invite_info.invite_note = OslMalloc(IMPS_MAX_INVITATION_NOTE);
    }

    note = imps_p->invite_info.invite_note;

    /* Owner */
    mmi_asc_to_ucs2((S8*) tmp_buff, g_imps_invite_icon_list[0].string);
    mmi_ucs2cpy(note, (S8*) tmp_buff);
    mmi_ucs2cat(note, (S8*) GetString(STR_ID_IMPS_OWNER));
    mmi_ucs2cat(note, (S8*) L":\n");
    if (invite_ind->sender.entity_type == IMPS_ENTITY_TYPE_SCREEN_NAME)
    {
        mmi_ucs2cat(note, (S8*) invite_ind->sender.sname);
    }
    else
    {
        mmi_asc_to_ucs2((S8*) tmp_buff, (S8*) invite_ind->sender.id);
        mmi_ucs2cat(note, (S8*) tmp_buff);
    }
    mmi_ucs2cat(note, (S8*) L"\n\n");

    /* Group ID */
    mmi_asc_to_ucs2((S8*) tmp_buff, g_imps_invite_icon_list[1].string);
    mmi_ucs2cat(note, (S8*) tmp_buff);
    mmi_ucs2cat(note, (S8*) GetString(STR_ID_IMPS_CHAT_ROOMS));
    mmi_ucs2cat(note, (S8*) L":\n");
    mmi_asc_to_ucs2(tmp_buff, (S8*) invite_ind->group_id);
    mmi_ucs2cat(note, tmp_buff);
    mmi_ucs2cat(note, (S8*) L"\n\n");

    /* Note */
    mmi_ucs2cat(note, (S8*) GetString(STR_ID_IMPS_WELCOME_TEXT));
    mmi_ucs2cat(note, (S8*) L":\n");
    mmi_ucs2cat(note, (S8*) invite_ind->invite_note);

    OslMfree(tmp_buff);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_invite_accept
 * DESCRIPTION
 *  Accept invitation, ask user to input screen name first
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_invite_accept(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* send request to PS */
    mmi_imps_ps_invite_reply_req(TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_invite_reminder
 * DESCRIPTION
 *  Entry reminder invitation screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_invite_reminder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_IMPS_INVITATION_IND, NULL, mmi_imps_entry_invite_reminder, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMPS_INVITATION_IND);

    SetParentHandler(0);

    /* generate note */
    if (imps_p->invite_info.invite_note == NULL)
    {
        imps_p->invite_info.invite_note = OslMalloc(IMPS_MAX_INVITATION_NOTE);
    }

    mmi_ucs2cpy((S8*) imps_p->invite_info.invite_note, (S8*) GetString(STR_ID_IMPS_NEW_INVITE_REMINDER));

    /* configure icons */
    wgui_config_general_multiline_icon_handler(MMI_FALSE, IMPS_NUM_INVITE, g_imps_invite_icon_list);

    ShowCategory78Screen(
        STR_ID_IMPS_NEW_INVITATION,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        wgui_general_multiline_icon_handler,
        (U8*) imps_p->invite_info.invite_note,
        mmi_ucs2strlen(imps_p->invite_info.invite_note),
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetDelScrnIDCallbackHandler(SCR_ID_IMPS_INVITATION_IND, (HistoryDelCBPtr) mmi_imps_invite_reminder_del_callback);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_invite_key_lokced
 * DESCRIPTION
 *  Entry reminder invitation screen when keypad locked
 * PARAMETERS
 *  lsk_img_id      [IN]        
 *  lsk_str_id      [IN]        
 *  rsk_img_id      [IN]        
 *  rsk_str_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_invite_key_lokced(U16 lsk_img_id, U16 lsk_str_id, U16 rsk_img_id, U16 rsk_str_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* generate note */
    if (imps_p->invite_info.invite_note == NULL)
    {
        imps_p->invite_info.invite_note = OslMalloc(IMPS_MAX_INVITATION_NOTE);
    }

    mmi_ucs2cpy((S8*) imps_p->invite_info.invite_note, (S8*) GetString(STR_ID_IMPS_NEW_INVITE_REMINDER));

    ShowCategory154Screen(
        0,
        0,
        lsk_str_id,
        lsk_img_id,
        rsk_str_id,
        rsk_img_id,
        (U8*) imps_p->invite_info.invite_note,
        NULL,
        IMG_GLOBAL_INFO,
        NULL);

    OslMfree(imps_p->invite_info.invite_note);
    imps_p->invite_info.invite_note = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_free_invite_list
 * DESCRIPTION
 *  Free all invite pending list when logout
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_free_invite_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    mmi_imps_invite_list_struct *invite;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < IMPS_MAX_PEND_INVITATION; i++)
    {
        invite = &imps_p->invite_info.invite_pending_list[i];
        if (invite->node)
        {
            free_local_para((local_para_struct*) invite->node);
            invite->node = NULL;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_subs_notify_finished
 * DESCRIPTION
 *  Handler subscribe notify finished
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_subs_notify_finished(U8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == IMPS_OK)
    {
        mmi_imps_util_disp_popup_done();
        imps_p->gen_info.is_sub_notify = MMI_TRUE;
    }
    else
    {
        mmi_imps_util_disp_err_popup(STR_ID_IMPS_ERR_NETWORK_BUSY);
    }
    DeleteScreenIfPresent(SCR_ID_IMPS_PROGRESS);
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_unsubs_notify_finished
 * DESCRIPTION
 *  Handler unsubscribe notify finished
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_unsubs_notify_finished(U8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == IMPS_OK)
    {
        mmi_imps_util_disp_popup_done();
        imps_p->gen_info.is_sub_notify = MMI_FALSE;
    }
    else
    {
        mmi_imps_util_disp_err_popup(STR_ID_IMPS_ERR_NETWORK_BUSY);
    }    
    DeleteScreenIfPresent(SCR_ID_IMPS_PROGRESS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_pre_entry_system_message
 * DESCRIPTION
 *  Entry system message screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_pre_entry_system_message(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    imps_p->system_message->buff = (S8*)OslMalloc(sizeof(imps_system_message_struct));

    memset(imps_p->system_message->buff, 0, sizeof(imps_system_message_struct));
    mmi_imps_system_message_string(imps_p->system_message->buff);

    mmi_imps_entry_system_message();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_system_message
 * DESCRIPTION
 *  Entry system message screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_system_message(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* guiBuffer;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  

    if (imps_p->system_message->buff[0] == '\0')
    {
        OslMfree(imps_p->system_message->buff);        
        return;
    }

    EntryNewScreen(SCR_ID_IMPS_SYSTEM_MESSAGE, NULL, mmi_imps_entry_system_message, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMPS_SYSTEM_MESSAGE);
    SetParentHandler(0);
    
    ShowCategory78Screen(STR_ID_IMPS_SYSTEM_MESSAGE,
                        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
                        STR_GLOBAL_OK, 
                        IMG_GLOBAL_OK,
                        STR_GLOBAL_BACK, 
                        IMG_GLOBAL_BACK,
                        NULL,  /* mmi_wgui_general_multiline_icon_handler */
                        (U8*) imps_p->system_message->buff, 
                        mmi_ucs2strlen(imps_p->system_message->buff), 
                        guiBuffer);    

    if (imps_p->system_message->need_rsp == TRUE)
    {
        /* text or url verification */
        if (imps_p->system_message->verification_type < 2)
        {
            /* if there are any options */
            if (imps_p->system_message->option_count > 0)
            {
                SetLeftSoftkeyFunction(mmi_imps_system_message_option, KEY_EVENT_UP);
            }
            else
            {
                SetLeftSoftkeyFunction(mmi_imps_system_message_res_cnf, KEY_EVENT_UP);
            }
        }
        else
        {
            SetLeftSoftkeyFunction(mmi_imps_view_next_system_message, KEY_EVENT_UP);
        }

        SetRightSoftkeyFunction(mmi_imps_give_up_sm_confirm, KEY_EVENT_UP);    
        SetKeyHandler(mmi_imps_give_up_sm_confirm, KEY_END, KEY_EVENT_DOWN);
    }
    else
    {
        SetLeftSoftkeyFunction(mmi_imps_view_next_system_message, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_imps_view_next_system_message, KEY_EVENT_UP);    
        SetKeyHandler(mmi_imps_view_next_system_message, KEY_END, KEY_EVENT_DOWN);       
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_give_up_sm_confirm
 * DESCRIPTION
 *  Display confirmation screen for give up system message
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_give_up_sm_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_entry_confirm(STR_GLOBAL_CANCEL, mmi_imps_give_up_system_message, GoBackHistory);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_imps_system_message_option
 * DESCRIPTION
 *  mmi_imps_system_message_option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_system_message_option(void)
    {
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    mmi_imps_system_message_struct *sm_info = imps_p->system_message;
    U8 *guiBuffer;
    S32 i;
    S32 count;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    count = (S32) sm_info->option_count;

    MMI_ASSERT(count > 0 && count <= 10);

    for (i = 0; i < count; i++)
    {
        mmi_ucs2cpy((S8*) subMenuData[i], (S8*) sm_info->option[i].text);
        subMenuDataPtrs[i] = subMenuData[i];
    } 
        
    EntryNewScreen(SCR_ID_IMPS_SYSTEM_MESSAGE_OPTION, NULL, mmi_imps_system_message_option, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMPS_SYSTEM_MESSAGE_OPTION);

    SetParentHandler(0);

    RegisterHighlightHandler(mmi_imps_hilite_system_message_option);

    ShowCategory53Screen(
        STR_ID_IMPS_SYSTEM_MESSAGE,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        count,
        (U8 **) subMenuDataPtrs,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_imps_system_message_res_cnf, KEY_EVENT_UP);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(mmi_imps_give_up_sm_confirm, KEY_END, KEY_EVENT_DOWN);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_system_message_option
 * DESCRIPTION
 *  Highlight handler of system message option. Store index of current selecting item.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_system_message_option(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    imps_p->system_message->sel_option = (U8) (index + 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_check_system_message
 * DESCRIPTION
 *  Check if there is any message unprocess
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_check_system_message(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    mmi_imps_system_message_struct *sm_info = imps_p->system_message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sm_info != NULL)
    {   
        if (sm_info->curr_index == sm_info->total)
        {
            mmi_imps_free_system_message();               
            if (sm_info->is_give_up == TRUE && imps_p->gen_info.curr_action == MSG_ID_MMI_IMPS_LOGIN_REQ)
            {
                mmi_imps_login_abort();             
            }
            
            mmi_imps_check_pending_invite();
        }
        else
        {
            if (mmi_imps_util_is_in_imps() && !IsScreenPresent(SCR_ID_IMPS_SYSTEM_MESSAGE))
            {
                /* process 1 system message */
                sm_info->curr_index++;                
                mmi_imps_pre_entry_system_message();  
            }
            else
            {
                mmi_imps_util_disp_warning_popup(STR_ID_IMPS_NEW_SYSTEM_MESSAGE);                
            }
        }
    }
    else
    {
        mmi_imps_check_pending_invite();        
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_view_next_system_message
 * DESCRIPTION
 *  mmi_imps_view_next_system_message
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_view_next_system_message(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/      

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imps_p->gen_info.curr_action == MSG_ID_MMI_IMPS_LOGIN_REQ)
    {
        mmi_imps_login_progress();
    }
   
    mmi_imps_del_system_message_scr();

    /* check if there is any unprocess message */    
    mmi_imps_check_system_message();
}  


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_del_system_message_scr
 * DESCRIPTION
 *  delete system message screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_del_system_message_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/      

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imps_p->system_message->buff)
    {
        OslMfree(imps_p->system_message->buff);
        imps_p->system_message->buff = NULL;
    }

    DeleteScreenIfPresent(SCR_ID_IMPS_SYSTEM_MESSAGE);
    DeleteScreenIfPresent(SCR_ID_IMPS_SYSTEM_MESSAGE_OPTION);
    DeleteScreenIfPresent(SCR_ID_IMPS_VERIFICATION_KEY); 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_give_up_system_message
 * DESCRIPTION
 *  give up system message
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_give_up_system_message(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/      

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    imps_p->system_message->is_give_up = TRUE;
    mmi_imps_del_system_message_scr();


    mmi_imps_check_system_message();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_free_system_message
 * DESCRIPTION
 *  Free system message buffer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_free_system_message(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/      
    U16 *ucs2_folder = OslMalloc((FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) ucs2_folder, (S8*) imps_p->system_message->sm_path);
    FS_Delete(ucs2_folder);
    OslMfree(ucs2_folder);
    if (imps_p->system_message != NULL)
    {
    OslMfree(imps_p->system_message);
    imps_p->system_message = NULL;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_system_message_res_cnf
 * DESCRIPTION
 *  Process system message
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_system_message_res_cnf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/      
    mmi_imps_system_message_struct *sm_info = imps_p->system_message;
    UI_string_type str = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((S8*) sm_info->verification) > 0)
    {
        str = (UI_string_type) sm_info->verification;
    }
    else
    {
        str = (UI_string_type) GetString(STR_GLOBAL_OK);
    }

    DisplayConfirm(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        str,
        0,
        WARNING_TONE);

    if (sm_info->verification_type == 0)
    {
        ChangeLeftSoftkey(STR_GLOBAL_EDIT, 0);
    }
    else if (sm_info->verification_type == 1)
    {
        ChangeLeftSoftkey(STR_ID_IMPS_GOTO, 0);
    }
    else
    {
        
    }
    SetLeftSoftkeyFunction(mmi_imps_system_message_yes, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_imps_give_up_sm_confirm, KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_system_message_yes
 * DESCRIPTION
 *  Process system message yes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_system_message_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/      
    mmi_imps_system_message_struct *sm_info = imps_p->system_message;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((S8*) sm_info->verification) > 0 && sm_info->verification_type == 0)
    {
        /* display 111 screen, input verification key */
        mmi_imps_entry_verification_key();
    }
    else if (strlen((S8*) sm_info->verification) > 0 && sm_info->verification_type == 1)
    {
        U16 nHistory = 0;
        history Scr;        
        
        mmi_imps_util_startup_wap_browser_req(2, (void*) sm_info->verification);
        HistoryReplace(SCR_ID_IMPS_SYSTEM_MESSAGE, SCR_ID_IMPS_VERIFICATION_KEY, mmi_imps_entry_verification_key);
        
        Scr.scrnID = SCR_ID_IMPS_SYSTEM_MESSAGE;
        Scr.entryFuncPtr = mmi_imps_pre_entry_system_message;
        mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) & nHistory);
        GetCategoryHistory(Scr.guiBuffer);
        InsertHistoryBeforeThisScrn(SCR_ID_IMPS_VERIFICATION_KEY, Scr);        
        
        SetKeyHandler(mmi_imps_give_up_sm_confirm, KEY_END, KEY_EVENT_DOWN);
    }
    else
    {
        /* send request to PS */
        mmi_imps_ps_system_message_user_req();        
        
        mmi_imps_view_next_system_message();        
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_verification_key
 * DESCRIPTION
 *  Entry input verification key screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_verification_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/      
    U8 *guiBuffer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/     
    EntryNewScreen(SCR_ID_IMPS_VERIFICATION_KEY, NULL, mmi_imps_entry_verification_key, NULL);   

    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMPS_VERIFICATION_KEY);  

    ShowCategory5Screen_ext(
        STR_ID_IMPS_VERIFICATION_KEY,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        (U8*) imps_p->system_message->verification_key,
        IMPS_MAX_URL_LEN,
        guiBuffer,
        0, //INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
        NULL,
        NULL);

    SetLeftSoftkeyFunction(mmi_imps_input_verification_opt, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_imps_give_up_sm_confirm, KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_input_verification_opt
 * DESCRIPTION
 *  Entry common full screen editor.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imps_input_verification_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 itemList[2];
    U16 nItems;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_IMPS_INPUT_VERIFY_OPT, NULL, mmi_imps_input_verification_opt, NULL);
    SetParentHandler(MENU_ID_IMPS_INPUT_VERIFY_OPT);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMPS_INPUT_VERIFY_OPT);
    nItems = GetNumOfChild(MENU_ID_IMPS_INPUT_VERIFY_OPT);
    GetSequenceStringIds(MENU_ID_IMPS_INPUT_VERIFY_OPT, itemList);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nItems,
        itemList,
        (PU16) gIndexIconsImageList,
        0,
        0,
        0,
        guiBuffer);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_input_verification_done
 * DESCRIPTION
 *  Highlight handler of input verification done 
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imps_hilite_input_verification_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_input_verification_done,KEY_EVENT_UP);
	  SetKeyHandler(mmi_imps_input_verification_done, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_input_verification_done
 * DESCRIPTION
 *  Input verification done
 * PARAMETERS
 *  text        [IN]        
 *  cursor      [IN]        
 *  length      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_input_verification_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_ps_system_message_user_req();
    
    mmi_imps_del_system_message_scr();
    GoBackHistory();

    mmi_imps_view_next_system_message();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_system_message_string
 * DESCRIPTION
 *  Prepare system message string
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_system_message_string(S8* buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    wgui_color_buffer_writer_struct writer;
    BOOL result;
    FS_HANDLE fileHandle = 0;
    S16 *ucs2_folder = OslMalloc((FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH);
    imps_system_message_struct system_message;
    mmi_imps_system_message_struct *sm_info = imps_p->system_message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    buff[0] = 0;
    wgui_color_buffer_create_writer(&writer, (U8*) buff, sizeof(imps_system_message_struct));

    mmi_ucs2cpy((S8*) ucs2_folder, (S8*) sm_info->sm_path);
    fileHandle = FS_Open((U16*) ucs2_folder, FS_READ_ONLY);
    OslMfree(ucs2_folder);

    if (fileHandle > 0)
    {
        U32 len;
        S32 result;
        FS_Seek(fileHandle, sizeof(imps_system_message_struct) * (sm_info->curr_index - 1), FS_FILE_BEGIN);
        result = FS_Read(fileHandle,
                        (void*)&system_message,
                        sizeof(imps_system_message_struct),
                        (U32*) & len);
        if (result == FS_NO_ERROR && len > 0)
        {
            /* save some information to structure */
            strcpy((S8*) sm_info->curr_sm_id, (S8*) system_message.sm_id);
            sm_info->need_rsp = system_message.need_rsp;
            sm_info->option_count = system_message.option_cnt <= 10 ? system_message.option_cnt : 0;
            sm_info->verification_type = system_message.verification_type;
            sm_info->verification_key[0] = 0;
            sm_info->verification[0] = 0;
            sm_info->is_give_up = MMI_FALSE;
            memcpy(sm_info->option, system_message.option, sizeof(imps_system_message_option_struct) * IMPS_MAX_SM_OPTION_NUM);
            if (system_message.verification_type == 0 && mmi_ucs2strlen((S8*) system_message.verification) > 0)
            {
                mmi_ucs2cpy((S8*) sm_info->verification, (S8*) system_message.verification);
            }
            else if (system_message.verification_type == 1 && strlen((S8*) system_message.verification) > 0)
            {
                mmi_asc_to_ucs2((S8*) sm_info->verification, (S8*) system_message.verification);
            }
            else
            {
                /* reserve for other type */
                sm_info->verification_type = 2;
            }
        }
        else
        {
            FS_Close(fileHandle); 
            mmi_imps_view_next_system_message();
            return;
        }
    }
    else
    {        
        return;
    }
    FS_Close(fileHandle); 

    /* prepare string buffer */
    wgui_color_buffer_write_string(&writer, (U8*) system_message.sm_text, MMI_FALSE, &result);
    wgui_color_buffer_write_char(&writer, '\n');
}


#define HTTP_AUTH


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_exit_http_auth
 * DESCRIPTION
 *  Exit function for authentication screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imps_exit_http_auth(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GenericExitInlineScreen(SCR_ID_IMPS_HTTP_AUTH, mmi_imps_entry_http_auth);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_http_auth
 * DESCRIPTION
 *  mmi_imps_entry_http_auth
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_http_auth(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_IMPS_HTTP_AUTH, mmi_imps_exit_http_auth, NULL, NULL);

    InitializeCategory57Screen();

    /* For username caption */
    SetInlineItemActivation(&wgui_inline_items[0], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[0], (U8*) GetString(STR_GLOBAL_USERNAME));

    /* For username string */
    SetInlineItemActivation(&wgui_inline_items[1], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[1],
        STR_GLOBAL_USERNAME,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        (U8*) imps_p->http_auth->username,
        IMPS_MAX_NAME_LEN,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(
        &wgui_inline_items[1],
        mmi_imps_hilite_prof_full_edit);

    /* For password caption */
    SetInlineItemActivation(&wgui_inline_items[2], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[2], (U8*) GetString(STR_GLOBAL_PASSWORD));

    /* For password string */
    SetInlineItemActivation(&wgui_inline_items[3], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[3],
        STR_GLOBAL_PASSWORD,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        (U8*) imps_p->http_auth->password,
        IMPS_MAX_HTTP_AUTH_PASSWORD_LEN,
        INPUT_TYPE_ALPHANUMERIC_PASSWORD | INPUT_TYPE_USE_ONLY_ENGLISH_MODES,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(
        &wgui_inline_items[3],
        mmi_imps_hilite_prof_full_edit);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMPS_HTTP_AUTH);    

    inputBuffer = GetCurrNInputBuffer(SCR_ID_IMPS_HTTP_AUTH, &inputBufferSize);

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, 4, inputBuffer);
    }

    ShowCategory57Screen(
        STR_GLOBAL_AUTHENTICATION,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        STR_GLOBAL_EDIT,
        IMG_GLOBAL_BACK,
        STR_GLOBAL_DONE,
        IMG_GLOBAL_BACK,
        4,
        (U16*) g_imps_inline_icons,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_imps_http_auth_confirm_hdlr, mmi_imps_http_auth_no_hdlr);
    SetKeyHandler(mmi_imps_http_auth_no_hdlr, KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_http_auth_confirm_hdlr
 * DESCRIPTION
 *  Function for submitting the authentication information
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_http_auth_confirm_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mmi_ucs2strlen((S8*)imps_p->http_auth->username) == 0)
    {
        mmi_imps_util_disp_err_popup(STR_ID_IMPS_EMPTY_USERNAME);
        return;
    }
    else
    {
        DisplayConfirm(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            get_string(STR_GLOBAL_SUBMIT),
            IMG_GLOBAL_QUESTION,
            WARNING_TONE);
        SetKeyHandler(mmi_imps_http_auth_no_hdlr, KEY_END, KEY_EVENT_DOWN);
        SetLeftSoftkeyFunction(mmi_imps_http_auth_yes_hdlr, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_imps_http_auth_no_hdlr, KEY_EVENT_UP);
        
        DeleteScreenIfPresent(SCR_ID_IMPS_HTTP_AUTH);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_http_auth_no_hdlr
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_http_auth_no_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imps_p->gen_info.curr_action == MSG_ID_MMI_IMPS_LOGIN_REQ)
    {
        ClearInputEventHandler(MMI_DEVICE_ALL);
        mmi_imps_ps_abort_login_req();
        if (IsScreenPresent(SCR_ID_IMPS_PROGRESS))
        {
            HistoryReplace(SCR_ID_IMPS_PROGRESS, SCR_ID_IMPS_PROGRESS, mmi_imps_entry_abort);
        }
        GoBackHistory();
    }
    else
    {
        GoBackHistory();
    }

    mmi_imps_free_http_auth_buffer();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_http_auth_yes_hdlr
 * DESCRIPTION
 *  Function for submitting the authentication information
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_http_auth_yes_hdlr(void)
{
    ClearInputEventHandler(MMI_DEVICE_ALL);
    mmi_imps_ps_send_http_auth_res();
    GoBackHistory();
    mmi_imps_free_http_auth_buffer();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_free_http_auth_buffer
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_free_http_auth_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imps_p->http_auth != NULL)
    {
        OslMfree(imps_p->http_auth);
        imps_p->http_auth = NULL;
    }
}

#endif
