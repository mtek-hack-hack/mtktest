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
 * VRSINameQuery.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for name query of VRSI.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifndef _MMI_VRSINAMEQUERY_C
#define _MMI_VRSINAMEQUERY_C

#if defined(__MMI_VRSI__)

/*  Include: MMI header file */
#include "CommonScreens.h"
#include "gpioInc.h"

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
#include "MainMenuDef.h"

#include "PhonebookDef.h"
#include "PhonebookTypes.h"
#include "PhonebookProt.h"
#include "CallManagementGprot.h"

#if defined(__FLIGHT_MODE_SUPPORT__)
#include "SimDetectionGprot.h"
#endif 

#ifdef __MMI_DUAL_SIM_MASTER__
#include "MTPNP_PFAL_CC.h"
#endif  /*__MMI_DUAL_SIM_MASTER__*/


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

/* 
 * Local Function
 */

/* 
 * Global Variable
 */
extern U16 PhoneBookEntryCount;
extern U16 g_phb_name_index[];
extern MMI_PHB_ENTRY_BCD_STRUCT PhoneBook[MAX_PB_ENTRIES];

/* 
 * Global Function
 */


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_nquery_rcg_grammar1_result
 * DESCRIPTION
 *  This function handle the recognition result for grammar 1 in name query scenario
 * PARAMETERS
 *  tag_num         [IN]        result tag number
 *  long_list       [IN]        result index list
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_nquery_rcg_grammar1_result(U16 tag_num, S32 *long_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i, j;
    U16 min_name_id = 0xffff, min_store_index = 0xffff;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* find the first entry in phonebook list order */
    for (i = 0; i < tag_num; i++)
    {
        for (j = 0; j < PhoneBookEntryCount; j++)
        {
            if (g_phb_name_index[j] == long_list[i])
            {
                if (j < min_name_id)
                {
                    min_name_id = j;
                    min_store_index = long_list[i];
                }
                break;
            }

        }
    }

    if (min_store_index < MAX_PB_ENTRIES)
    {
        /* Only handle first record for name query */
        g_vrsi_cntx.long_list[0] = min_store_index;

        g_phb_cntx.highlight_entry = min_name_id;
        g_vrsi_cntx.retry = 0;

        mmi_vrsi_pre_entry_nquery_list();
    }
    else    /* Not in name list, try result in city list */
    {
        mmi_vrsi_city_rcg_grammar1_result(tag_num, long_list);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_nquery_grammar5_prompt
 * DESCRIPTION
 *  Prompt message of name query
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_nquery_grammar5_prompt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_prompt[(MAX_PB_NAME_LENGTH + 60) * ENCODING_LENGTH];
    U16 store_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    store_index = g_phb_name_index[g_phb_cntx.highlight_entry];

    mmi_ucs2cpy(str_prompt, GetString(STR_ID_VRSI_TTS_FOUND));

    g_vrsi_cntx.curr_grammar = MMI_VRSI_GRAMMAR_5;  /* Assign grammar for rcg result callback */
    g_vrsi_cntx.curr_scenario = VRSI_CMD1_NAME_QUERY;

    mmi_vrsi_util_play_tts((U16*) str_prompt, mmi_vrsi_nquery_grammar5_prompt2);
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_nquery_grammar5_prompt2
 * DESCRIPTION
 *  Prompt message of name query
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_nquery_grammar5_prompt2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_prompt[(MAX_PB_NAME_LENGTH + 60) * ENCODING_LENGTH];
    S32 result;
    U16 store_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    store_index = g_phb_name_index[g_phb_cntx.highlight_entry];

    /* Play SD tag if exists. */
    result = mmi_vrsi_util_play_name_tag(MMI_VRSI_GRAMMAR_1, MMI_VRSI_APP_DIAL, store_index, mmi_vrsi_nquery_grammar5_prompt3);

    if (result == MED_RES_OK)
    {
        return;
    }

    /* Play SI instead */
    mmi_ucs2cat(str_prompt, (S8*) PhoneBook[store_index].alpha_id.name);
    mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_GRAMMAR5_PROMPT));

    /* Play prompt TTS */
    mmi_vrsi_util_play_tts((U16*) str_prompt, mmi_vrsi_rcg_start_command);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_nquery_grammar5_prompt3
 * DESCRIPTION
 *  Prompt message of name query
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_nquery_grammar5_prompt3(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_prompt[(MAX_PB_NAME_LENGTH + 60) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_GRAMMAR5_PROMPT));

    /* Play prompt TTS */
    mmi_vrsi_util_play_tts((U16*) str_prompt, mmi_vrsi_rcg_start_command);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_nquery_get_index
 * DESCRIPTION
 *  Highlight index callback function
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_nquery_get_index(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.active_index = (U16) nIndex;
    g_phb_cntx.highlight_entry = (U16) nIndex;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_pre_entry_nquery_list
 * DESCRIPTION
 *  Pre enter name query list function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_pre_entry_nquery_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * Check if it can be list in advance
     */
#ifdef __MMI_DUAL_SIM_MASTER__
    if(MTPNP_PFAL_Phb_IsReady()==MTPNP_FALSE)
#else  /* __MMI_DUAL_SIM_MASTER__ */
    if (!g_phb_cntx.phb_ready || g_phb_cntx.processing)
#endif   /* __MMI_DUAL_SIM_MASTER__ */
    {
        mmi_phb_entry_not_ready(STR_PROCESSING_PHONEBOOK);
        return;
    }
    else if (PhoneBookEntryCount == 0)
    {
        DisplayPopup(
            (PU8) GetString(STR_NO_ENTRIES_MESSAGE),
            IMG_GLOBAL_EMPTY,
            TRUE,
            PHB_NOTIFY_TIMEOUT,
            EMPTY_LIST_TONE);
        return;
    }

    /*
     *Check if phonebook entry has been updated, and if need to use alpha_index function.
     */
    if (g_phb_cntx.refresh_list)
    {
        mmi_phb_list_build_alpha_index(NULL, 0, TRUE, MMI_STORAGE_NONE);
        g_phb_cntx.refresh_list = MMI_PHB_ENTRY_NO_CHANGE;
    }

    /* Enter image phonebook list for large size screen. */
#if defined(__MMI_FILE_MANAGER__) && defined(__MTK_TARGET__)
    if (UI_device_height == 220 && UI_device_width == 176)
    {
        mmi_vrsi_entry_nquery_image_list1();
    }
#endif /* defined(__MMI_FILE_MANAGER__) && defined(__MTK_TARGET__) */ 
    else
    {
        mmi_vrsi_entry_nquery_list1();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_entry_nquery_list1
 * DESCRIPTION
 *  Entry name query result list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_entry_nquery_list1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TurnOnBacklight(1);

    EntryNewScreen(SCR_ID_VRSI_NAME_QUERY_LIST1, mmi_vrsi_exit_nquery_list1, NULL, NULL);
    RegisterHighlightHandler(mmi_vrsi_nquery_get_index);

    ShowCategory184Screen(
        STR_ID_VRSI_APP,
        MAIN_MENU_TITLE_MULTIMEDIA_ICON,
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        PhoneBookEntryCount,
        mmi_phb_list_get_item,
        mmi_phb_list_get_hint,
        g_phb_cntx.highlight_entry,
        NULL);

    /* register multi-tap function for fast jump, for full list only */
    register_multitap_no_draw_key_handlers();
    set_multitap_functions(mmi_phb_list_alpha_index, mmi_phb_list_alpha_index_input_callback);
    change_multitap_mode(0);

    SetLeftSoftkeyFunction(mmi_phb_entry_op_option, KEY_EVENT_UP);
    SetKeyHandler(mmi_phb_entry_op_option, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

#if defined(__FLIGHT_MODE_SUPPORT__)
    if (!mmi_bootup_get_active_flight_mode())
#endif 
    {
    #ifdef __MMI_DUAL_SIM_MASTER__
        MTPNP_PFAL_CC_HandleSendKeys(mmi_phb_choose_number_normal,KEY_EVENT_UP);
    #else	/* __MMI_DUAL_SIM_MASTER__ */
        SetKeyHandler(mmi_phb_choose_number_normal, KEY_SEND, KEY_EVENT_UP);
     #endif  /* __MMI_DUAL_SIM_MASTER__ */
    }

    mmi_vrsi_nquery_grammar5_prompt();
    g_vrsi_cntx.retry++;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_entry_nquery_image_list1
 * DESCRIPTION
 *  Entry name query result list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_entry_nquery_image_list1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TurnOnBacklight(1);

    EntryNewScreen(SCR_ID_VRSI_NAME_QUERY_LIST1, mmi_vrsi_exit_nquery_list1, NULL, NULL);
    RegisterHighlightHandler(mmi_vrsi_nquery_get_index);

    ShowCategory212Screen(
        STR_ID_VRSI_APP,
        MAIN_MENU_TITLE_MULTIMEDIA_ICON,
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,         /* LSK */
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,            /* RSK */
        PhoneBookEntryCount,
        mmi_phb_list_get_item,
        mmi_phb_list_get_null_hint,
        mmi_phb_image_list1_draw_title_info,
        NULL,                       /* No call back needed when change highlight */
        2,                          /* Info box row count */
        0,                          /* info bg image id */
        g_phb_cntx.highlight_entry, /* Highlight item index */
        NULL);

    register_multitap_no_draw_key_handlers();
    set_multitap_functions(mmi_phb_list_alpha_index, mmi_phb_list_alpha_index_input_callback);
    change_multitap_mode(0);

    SetLeftSoftkeyFunction(mmi_phb_entry_op_option, KEY_EVENT_UP);
    SetKeyHandler(mmi_phb_entry_op_option, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

#if defined(__FLIGHT_MODE_SUPPORT__)
    if (!mmi_bootup_get_active_flight_mode())
#endif 
    {
    #ifdef __MMI_DUAL_SIM_MASTER__
        MTPNP_PFAL_CC_HandleSendKeys(mmi_phb_choose_number_normal,KEY_EVENT_UP);
    #else	/* __MMI_DUAL_SIM_MASTER__ */
        SetKeyHandler(mmi_phb_choose_number_normal, KEY_SEND, KEY_EVENT_UP);
     #endif  /* __MMI_DUAL_SIM_MASTER__ */
    }

    mmi_vrsi_nquery_grammar5_prompt();
    g_vrsi_cntx.retry++;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_exit_nquery_list1
 * DESCRIPTION
 *  Exit name query result list. Will leave VR session if next screen is not in scenario
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_exit_nquery_list1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scr_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scr_id = GetActiveScreenId();

    if ((scr_id == SCR_ID_VRSI_RCG_MAIN) || (scr_id == SCR_ID_VRSI_NAME_QUERY_LIST1))
    {
        return;
    }
    else if (scr_id == SCR_PBOOK_ENTRY_OPTIONS) /* Add list to history if go to option menu */
    {
        GenericExitScreen(SCR_PBOOK_LIST, mmi_phb_list_pre_entry);
    }

    mmi_vrsi_rcg_close();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_entry_nquery_list1_in_history
 * DESCRIPTION
 *  Entry name query result list after retry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_entry_nquery_list1_in_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_list_pre_entry();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_nquery_pre_entry_option
 * DESCRIPTION
 *  List screen key handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_nquery_pre_entry_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_entry_op_option();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_nquery_pre_dial
 * DESCRIPTION
 *  List screen key handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_nquery_pre_dial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S8 pbnumstring[(MAX_PB_NUMBER_LENGTH+1+1)*ENCODING_LENGTH];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_convert_get_ucs2_number(pbnumstring, g_phb_name_index[g_phb_cntx.active_index]); /* BCD number format. */
	#ifdef __MMI_DUAL_SIM_MASTER__
		mmi_ucm_app_entry_dial_option((U8*)pbnumstring,NULL,NULL);
	#endif /*__MMI_DUAL_SIM_MASTER__*/
	#ifndef __MMI_DUAL_SIM_MASTER__
		#ifdef __MMI_VOIP__
		mmi_voip_app_make_call((PS8)pbnumstring);
		#else 
        MakeCall((PS8)pbnumstring);
		#endif 
	#endif /*__MMI_DUAL_SIM_MASTER__*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_nquery_goto_previous
 * DESCRIPTION
 *  List screen key handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_nquery_goto_previous(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vrsi_cntx.retry = 0;
    ExecuteCurrKeyHandler(KEY_UP_ARROW, KEY_EVENT_DOWN);    /* Simulate Up Key */

    mmi_vrsi_nquery_grammar5_prompt();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_nquery_goto_next
 * DESCRIPTION
 *  List screen key handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_nquery_goto_next(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vrsi_cntx.retry = 0;
    ExecuteCurrKeyHandler(KEY_DOWN_ARROW, KEY_EVENT_DOWN);  /* Simulate Down Key */

    mmi_vrsi_nquery_grammar5_prompt();
}

#endif /* defined(__MMI_VRSI__) */ /* #if defined(__MMI_VRSI__) */
#endif /* _MMI_VRSINAMEQUERY_C */ /* #ifndef _MMI_VRSINAMEQUERY_C */

