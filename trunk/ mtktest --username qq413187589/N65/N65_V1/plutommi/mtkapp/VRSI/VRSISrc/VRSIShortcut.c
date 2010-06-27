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
 * VRSIShortcut.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for open shorcut application by VRSI.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifndef _MMI_VRSISHORTCUT_C
#define _MMI_VRSISHORTCUT_C

#if defined(__MMI_VRSI__)

/*  Include: MMI header file */
#include "CommonScreens.h"
#include "ProtocolEvents.h"
#include "nvram_user_defs.h"
#include "wgui_softkeys.h"

/* ... Add More MMI header */
#include "med_global.h"
#include "med_struct.h"
#include "med_main.h"
#include "med_api.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "VRSIType.h"
#include "VRSIProt.h"
#include "VRSIResDef.h"
#include "gpioInc.h"
#include "MainMenuDef.h"

/* Shortcut related */
#include "ShortcutsDefs.h"
#include "ShortcutsProts.h"


/*  Include: PS header file */
/* ... Add More PS header */

/* 
 * Typedef 
 */

/* 
 * Define
 */

/* 
 * Local Variable
 */
static U16 g_vrsi_scut_index;

/* 
 * Local Function
 */

/* 
 * Global Variable
 */
extern hiliteInfo maxHiliteInfo[];  /* available hilite func ptrs */
extern S32 ShctCheckItemCanbeExecuted(U16 selitem);

/* extern void  (*left_softkey_functions[])(void); */

/* 
 * Global Function
 */

#define MMI_VRSI_SHORTCUT_CENTRAL


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_scut_central_add_all
 * DESCRIPTION
 *  This function add all shortcut name as central command.
 * PARAMETERS
 *  msg     [IN]        Message from protocol events
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_scut_central_add_all(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i, tag_num, add_count;
    U16 *name_list[MMI_VRSI_MAX_ADD_ENTRY];
    S32 long_list[MMI_VRSI_MAX_ADD_ENTRY];
    U8 is_name_list[MMI_VRSI_MAX_ADD_ENTRY];
    U16 id_list[MMI_VRSI_MAX_ADD_ENTRY];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Abort while adding central command. Will close engine in abort function, so return directly. */
    if (g_vrsi_cntx.vrsi_state != MMI_VRSI_STATE_ADDING_CMD)
    {
        return;
    }

    add_count = g_vrsi_cntx.central_count;

    if (add_count < g_shct_cntx.NumCandShct)
    {
        tag_num =
            ((g_shct_cntx.NumCandShct - add_count) <
             MMI_VRSI_MAX_ADD_ENTRY) ? (g_shct_cntx.NumCandShct - add_count) : MMI_VRSI_MAX_ADD_ENTRY;

        for (i = 0; i < tag_num; i++)
        {
            name_list[i] = (U16*) GetString(ShctGetStringID(g_shct_cntx.CandShctList[i + add_count]));
            long_list[i] = i + add_count + MMI_VRSI_CMD_SCUT_BASE;
            is_name_list[i] = FALSE;
        }

        /* Get session id for each add operation */
        g_vrsi_cntx.session_id = mdi_audio_vrsi_new_session_id();

        /* Add SI tags */
        media_aud_vrsi_add_tags(
            MOD_MMI,
            g_vrsi_cntx.session_id,
            (U8*) g_vrsi_grammar[MMI_VRSI_GRAMMAR_1],
            tag_num,
            name_list,
            long_list,
            is_name_list,
            id_list);

        add_count += tag_num;

        /* Print add fail messages. */
        mmi_vrsi_init_central_count_fail(tag_num, id_list, long_list);
    }

    g_vrsi_cntx.central_count = add_count;

    /* More central command to add */
    if (add_count < g_shct_cntx.NumCandShct)
    {
        mmi_vrsi_init_central_add_req();
    }
    else
    {
        mmi_vrsi_scut_central_add_done();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_scut_central_add_done
 * DESCRIPTION
 *  This function clear flag and add another central commmand.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_scut_central_add_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Add next app's central command */
    g_vrsi_cntx.central_count = 0;
    SetProtocolEventHandler(mmi_vrsi_city_central_add_all, PRT_MMI_VRSI_ADD_CENTRAL_REQ);
    mmi_vrsi_init_central_add_req();
}

#define MMI_VRSI_SHORTCUT_RCG


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_scut_rcg_grammar1_result
 * DESCRIPTION
 *  This function get shortcut index from the recogntion result.
 * PARAMETERS
 *  tag_num         [IN]        Tag number of recognition result
 *  long_list       [IN]        Tag id list of recognition result
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_scut_rcg_grammar1_result(U16 tag_num, S32 *long_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((long_list[0] >= MMI_VRSI_CMD_SCUT_BASE) && (long_list[0] < MMI_VRSI_CMD_SCUT_BASE + g_shct_cntx.NumCandShct))
    {
        g_vrsi_scut_index = (U16) long_list[0] - MMI_VRSI_CMD_SCUT_BASE;

        mmi_vrsi_entry_scut_open_app();
    }
    else
    {
        mmi_vrsi_scut_no_app_prompt();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_entry_scut_open_app
 * DESCRIPTION
 *  Entry function of display opening shortcut prompt.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_entry_scut_open_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_prompt[MMI_VRSI_MAX_PROMPT_STR * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy(str_prompt, GetString(ShctGetStringID(g_shct_cntx.CandShctList[g_vrsi_scut_index])));
    mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_OPENING_PROMPT));

    TurnOnBacklight(1);

    EntryNewScreen(SCR_ID_VRSI_OPEN_SCUT_PROMPT, mmi_vrsi_exit_scut_open_app, NULL, NULL);

    ShowCategory66Screen(
        STR_ID_VRSI_APP,
        MAIN_MENU_TITLE_MULTIMEDIA_ICON,
        STR_GLOBAL_OK,      /* LSK STR */
        0,                  /* LSK IMG */
        STR_GLOBAL_ABORT,   /* RSK STR */
        0,                  /* RSK IMG */
        (U8*) str_prompt,   /* message id */
        0,                  /* icon id */
        NULL);

    SetLeftSoftkeyFunction(mmi_vrsi_scut_open_app, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_vrsi_rcg_abort, KEY_EVENT_UP);

#if defined(__MMI_VRSI_TRAIN_TAG__)
    mmi_vrsi_scut_open_app_play_prompt(str_prompt);
#else 
    mmi_vrsi_util_play_tts((U16*) str_prompt, mmi_vrsi_scut_open_app);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_exit_scut_open_app
 * DESCRIPTION
 *  Exit function of display opening shortcut prompt.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_exit_scut_open_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vrsi_rcg_close();
}

#if defined(__MMI_VRSI_TRAIN_TAG__)


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_scut_open_app_play_prompt
 * DESCRIPTION
 *  This function play SD tags of shortcut application, if no tag trained, play tts instead.
 * PARAMETERS
 *  str_prompt      [IN]        Input prompt string
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_scut_open_app_play_prompt(S8 *str_prompt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mmi_vrsi_util_play_tag(
                MMI_VRSI_GRAMMAR_1,
                MMI_VRSI_APP_SHORTCUT,
                (U16) (g_vrsi_scut_index + MMI_VRSI_CMD_SCUT_BASE),
                mmi_vrsi_scut_open_app_play_prompt1);
    if (result == MED_RES_OK)
    {
        return;
    }

    mmi_vrsi_util_play_tts((U16*) str_prompt, mmi_vrsi_scut_open_app);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_scut_open_app_play_prompt1
 * DESCRIPTION
 *  This function play the tts prompt of open shortcut.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_scut_open_app_play_prompt1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_prompt[MMI_VRSI_MAX_PROMPT_STR * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy(str_prompt, GetString(STR_ID_VRSI_OPENING_PROMPT));
    mmi_vrsi_util_play_tts((U16*) str_prompt, mmi_vrsi_scut_open_app);
}
#endif /* defined(__MMI_VRSI_TRAIN_TAG__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_scut_open_app
 * DESCRIPTION
 *  This function execute the entry function of shortcut application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_scut_open_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 	
    if (ShctCheckItemCanbeExecuted(g_shct_cntx.CandShctList[g_vrsi_scut_index]) == 0)
	{  
    #if defined(__MMI_DEDICATED_KEY_SHORTCUTS__)
        g_shct_cntx.IsKeyRetrieving = TRUE; /* To avoid blinking RSK and LSK when change highlight */
    #endif 
        (*maxHiliteInfo[g_shct_cntx.CandShctList[g_vrsi_scut_index]].entryFuncPtr) ();
    #if defined(__MMI_DEDICATED_KEY_SHORTCUTS__)
        g_shct_cntx.IsKeyRetrieving = FALSE;
    #endif 
    /* left_softkey_functions[KEY_EVENT_UP](); */
    execute_softkey_function(KEY_EVENT_UP, MMI_LEFT_SOFTKEY);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_scut_no_app_prompt
 * DESCRIPTION
 *  This function play tts prompt for no application found.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_scut_no_app_prompt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_prompt[MMI_VRSI_MAX_PROMPT_STR * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy(str_prompt, GetString(STR_ID_VRSI_RCG_NOT_FOUND));
    mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_SHORTCUT_ITEM));
    mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_SPEAK_AGAIN_PROMPT));

    /* Play prompt TTS */
    mmi_vrsi_util_play_tts((U16*) str_prompt, mmi_vrsi_entry_rcg);
}

#define MMI_VRSI_SHORTCUT_TRAINING
#if defined(__MMI_VRSI_TRAIN_TAG__)


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_scut_list_highlight_hdlr
 * DESCRIPTION
 *  highlight function for train SD tags.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_scut_list_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vrsi_scut_index = (U16) index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_entry_scut_list
 * DESCRIPTION
 *  Entry function of train SD tag list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_entry_scut_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 ShctCandList[SHCT_MAX_CANDI_LIST];  /* All shortcut candidate */
    U16 ImageList[SHCT_MAX_CANDI_LIST];
    U16 i;
    vrsi_sd_tag_struct tag_list[MMI_VRSI_MAX_SD_TAG];
    S16 pError;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VRSI_TRAIN_SHORTCUT_LIST, NULL, mmi_vrsi_entry_scut_list, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_VRSI_TRAIN_SHORTCUT_LIST);

    /* Assign shortcut string and image */
    ReadRecord(NVRAM_EF_VRSI_TAG_LID, 1, (void*)tag_list, MMI_VRSI_MAX_SD_TAG * sizeof(vrsi_sd_tag_struct), &pError);
    for (i = 0; i < g_shct_cntx.NumCandShct; i++)
    {
        ShctCandList[i] = ShctGetStringID(g_shct_cntx.CandShctList[i]);

        /* Check if shortcut item has voice tag */
        if (mmi_vrsi_train_util_get_loc_in_list(MMI_VRSI_APP_SHORTCUT, (U16) (MMI_VRSI_CMD_SCUT_BASE + i), tag_list) !=
            0xff)
        {
            ImageList[i] = IMG_ID_VRSI_APP;
        }
        else
        {
            ImageList[i] = IMG_ID_VRSI_SHORTCUT;
        }
    }

    if (guiBuffer == NULL)
    {
        g_vrsi_scut_index = 0;
    }

    RegisterHighlightHandler(mmi_vrsi_scut_list_highlight_hdlr);

    ShowCategory15Screen(
        STR_ID_VRSI_SHORTCUT_LIST,
        MAIN_MENU_TITLE_MULTIMEDIA_ICON,
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        g_shct_cntx.NumCandShct,
        ShctCandList,
        (U16*) ImageList,
        LIST_MENU,
        g_vrsi_scut_index,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_vrsi_scut_pre_entry_train_main, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(mmi_vrsi_scut_pre_entry_train_main, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_scut_pre_entry_train_main
 * DESCRIPTION
 *  Exit function of train SD tag list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_scut_pre_entry_train_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 tag_loc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vrsi_cntx.long_name_ptr = (U16*) GetString(ShctGetStringID(g_shct_cntx.CandShctList[g_vrsi_scut_index]));
    g_vrsi_cntx.long_list[0] = MMI_VRSI_CMD_SCUT_BASE + g_vrsi_scut_index;
    g_vrsi_cntx.long_list_num = 1;

    g_vrsi_cntx.curr_app = MMI_VRSI_APP_SHORTCUT;

    tag_loc = mmi_vrsi_train_util_get_id_and_loc(MMI_VRSI_APP_SHORTCUT, g_vrsi_cntx.long_list[0], NULL);

    /* Modify, Playback, or delete exists voice tag. */
    if (tag_loc < 0xff)
    {
        mmi_vrsi_entry_train_option_del();
    }
    /* No tag exists, add new tag */
    else
    {
        mmi_vrsi_entry_train_option_add();
    }
}

#endif /* defined(__MMI_VRSI_TRAIN_TAG__) */ /* #if defined(__MMI_VRSI_TRAIN_TAG__) */

#endif /* defined(__MMI_VRSI__) */ /* #if defined(__MMI_VRSI__) */
#endif /* _MMI_VRSISHORTCUT_C */ /* #ifndef _MMI_VRSISHORTCUT_C */

