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
 * VoiceDial.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for Voice Dialing.
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
 *------------------------------------------------------------------------------
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifndef _MMI_VRSDDIAL_C
#define _MMI_VRSDDIAL_C

#if defined(__MMI_VRSD__) && defined(__MMI_VRSD_DIAL__)

/*  Include: MMI header file */
#include "CommonScreens.h"
#include "nvram_user_defs.h"
#include "MessagesExDcl.h"

/* Med */
#include "med_global.h"
#include "med_struct.h"
#include "med_api.h"
#include "med_main.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"

#include "VRSDResDef.h"
#include "VRSD.h"
#include "VRSDDial.h"
#include "PhonebookTypes.h"
#include "PhonebookGProt.h"
#include "PhonebookDef.h"
#include "SettingDefs.h"        /* For FDN on Message */
#include "SettingsGdcl.h"

/* 
 * Typedef 
 */
typedef enum
{
    MMI_VRSD_DIAL_MENU_ALL,
    MMI_VRSD_DIAL_MENU_ADD_ONLY,
    MMI_VRSD_DIAL_MENU_CHANGE_DEL
} vrsddial_menu_type_enum;

/* 
 * Define
 */

/* 
 * Local Variable
 */
static U16 g_vrsddial_store_index;

/* 
 * Local Function
 */

/* 
 * Global Variable
 */
extern MMI_PHB_ENTRY_BCD_STRUCT PhoneBook[];
extern U16 g_phb_name_index[];
extern U16 PhoneBookEntryCount;

/* 
 * Global Function
 */
#ifdef __GEMINI__
extern kal_bool is_sim_replaced(kal_uint8 simInterface);
#else
extern kal_bool is_sim_replaced(void);
#endif

#define MMI_VRSD_DIAL_INIT


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsddial_init
 * DESCRIPTION
 *  This function initialize Voice Dial application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsddial_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vrsd_register_rcg_callback(MMI_VRSD_APP_DIAL, mmi_vrsddial_rcg_callback);

    mmi_vrsddial_init_highlight_handler();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsddial_init_highlight_handler
 * DESCRIPTION
 *  This function initialize Voice Dial application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsddial_init_highlight_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU_ID_VRSD_DIAL, mmi_vrsddial_highlight_app);

    SetHiliteHandler(MENU_ID_VRSD_DIAL_MAIN_ADD, mmi_vrsddial_highlight_main_add);      /* Will change according to entry screen */
    SetHiliteHandler(MENU_ID_VRSD_DIAL_MAIN_CHANGE, mmi_vrsddial_highlight_main_change);
    SetHiliteHandler(MENU_ID_VRSD_DIAL_MAIN_DELETE, mmi_vrsddial_highlight_main_delete);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsddial_check_sim_change
 * DESCRIPTION
 *  Check if SIM changed when first time bootup and enter idle screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  BOOL  TRUE if sim changed, FALSE if not
 *****************************************************************************/
BOOL mmi_vrsddial_check_sim_change(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vrsd_cntx.vrtag_sync == 0)
    {
        g_vrsd_cntx.vrtag_sync = 1;
    #ifdef __GEMINI__
        if (is_sim_replaced(0) || is_sim_replaced(1))
    #else
        if (is_sim_replaced())
    #endif
        {
            if (mmi_vrsd_get_total_tag_count(MMI_VRSD_APP_DIAL))
            {
                DisplayConfirm(
                    STR_GLOBAL_YES,
                    IMG_GLOBAL_YES,
                    STR_GLOBAL_NO,
                    IMG_GLOBAL_NO,
                    get_string(STR_ID_VRSD_DIAL_REFRESH_SIM),
                    IMG_GLOBAL_QUESTION,
                    WARNING_TONE);

                SetLeftSoftkeyFunction(mmi_vrsddial_delete_all_tag_in_sim_pre_req, KEY_EVENT_UP);
                SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

                return TRUE;
            }
        }
    }
    return FALSE;
}

#define MMI_VRSD_DIAL_LIST


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsddial_highlight_app
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsddial_highlight_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);

    SetLeftSoftkeyFunction(mmi_phb_vrsddial_enter_tag_list, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(mmi_phb_vrsddial_enter_tag_list, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsddial_entry_empty_list
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsddial_entry_empty_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    guiBuffer = GetCurrGuiBuffer(SCR_ID_VRSD_DIAL_EMPTY_LIST);

    EntryNewScreen(SCR_ID_VRSD_DIAL_EMPTY_LIST, NULL, mmi_phb_vrsddial_enter_tag_list, NULL);

    ShowCategory2Screen(
        STR_ID_VRSD_DIAL,
        IMG_ID_VRSD_APP,
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        STR_GLOBAL_EMPTY_LIST,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_vrsddial_main_menu_add_only, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}

#define MMI_VRSD_DIAL_MAIN_MENU


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsddial_highlight_main_add
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsddial_highlight_main_add(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_phb_vrsddial_enter_no_tag_list, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsddial_highlight_main_change
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsddial_highlight_main_change(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vrsddial_change_tag, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsddial_highlight_main_delete
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsddial_highlight_main_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vrsddial_delete_confirm, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsddial_main_menu_add_only
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsddial_main_menu_add_only(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Highlight Handler will re-register in main menu function. */
    SetHiliteHandler(MENU_ID_VRSD_DIAL_MAIN_ADD, mmi_vrsddial_highlight_main_add);

    mmi_vrsddial_main_menu(mmi_vrsddial_main_menu_add_only, MMI_VRSD_DIAL_MENU_ADD_ONLY);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsddial_main_menu_all_option
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsddial_main_menu_all_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vrsddial_store_index = g_phb_cntx.active_index;

    SetHiliteHandler(MENU_ID_VRSD_DIAL_MAIN_ADD, mmi_vrsddial_highlight_main_add);

    mmi_vrsddial_main_menu(mmi_vrsddial_main_menu_all_option, MMI_VRSD_DIAL_MENU_ALL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsddial_main_menu
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  entry_ptr       [IN]            
 *  type            [IN]            
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsddial_main_menu(void (*entry_ptr) (void), U8 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[4];
    U16 nNumofItem;

    U32 HideItemId = -1;
    U32 maskingByte = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VRSD_DIAL_MAIN_MENU, NULL, entry_ptr, NULL);
    nNumofItem = GetNumOfChild(MENU_ID_VRSD_DIAL_MAIN_MENU);
    GetSequenceStringIds(MENU_ID_VRSD_DIAL_MAIN_MENU, nStrItemList);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_VRSD_DIAL_MAIN_MENU);
    SetParentHandler(MENU_ID_VRSD_DIAL_MAIN_MENU);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /*
     * Register all highlight handler again, because RsetBit() may change the highlight handler when hide menu.
     * Note that add handler has registered before enter this function.
     */
    SetHiliteHandler(MENU_ID_VRSD_DIAL_MAIN_CHANGE, mmi_vrsddial_highlight_main_change);
    SetHiliteHandler(MENU_ID_VRSD_DIAL_MAIN_DELETE, mmi_vrsddial_highlight_main_delete);

    /* Display menu option accordingly, hide unsupport menu here. */
    if (type == MMI_VRSD_DIAL_MENU_ADD_ONLY)
    {
        nNumofItem = 1; /* Display first option only */
    }
    else if (type == MMI_VRSD_DIAL_MENU_CHANGE_DEL)
    {
        HideItemId = GetChildMenuIDIndexByParentMenuID(MENU_ID_VRSD_DIAL_MAIN_MENU, MENU_ID_VRSD_DIAL_MAIN_MENU);
        ResetBit(maskingByte, HideItemId);  /* 0:Add */

        MaskHiliteItems(MENU_ID_VRSD_DIAL_MAIN_MENU, maskingByte);
        nNumofItem = MaskItems(nStrItemList, (U8) nNumofItem, maskingByte);
    }

    ShowCategory15Screen(
        STR_ID_VRSD_DIAL,
        IMG_ID_VRSD_APP,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        LIST_MENU,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

#define VRSD_DIAL_PHB_OPTION_MENU


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsddial_phb_highlight_main_add
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsddial_phb_highlight_main_add(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vrsddial_add_tag, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsddial_phb_main_menu_pre_entry
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsddial_phb_main_menu_pre_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Synchronize with file system for first time login. */
    mmi_vrsd_sync_tag_with_db();

    g_vrsddial_store_index = g_phb_name_index[g_phb_cntx.active_index];

    if (mmi_vrsd_util_get_tag_id(MMI_VRSD_APP_DIAL, g_vrsddial_store_index) != 0xffff)  /* Tag exists */
    {
        mmi_vrsddial_phb_main_menu_change_delete();
    }
    else    /* No tag associated */
    {
        mmi_vrsddial_phb_main_menu_add_only();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsddial_phb_main_menu_change_delete
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsddial_phb_main_menu_change_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vrsddial_main_menu(mmi_vrsddial_phb_main_menu_change_delete, MMI_VRSD_DIAL_MENU_CHANGE_DEL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsddial_phb_main_menu_add_only
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsddial_phb_main_menu_add_only(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU_ID_VRSD_DIAL_MAIN_ADD, mmi_vrsddial_phb_highlight_main_add);

    mmi_vrsddial_main_menu(mmi_vrsddial_phb_main_menu_add_only, MMI_VRSD_DIAL_MENU_ADD_ONLY);
}

#define VRSD_DIAL_OPTIONS


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsddial_train_result_callback
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  result      [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsddial_train_result_callback(U8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == MMI_VRSD_TRN_SUCCESS)
    {
        mmi_vrsddial_phb_get_new_highlight();
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_DONE),
            IMG_GLOBAL_ACTIVATED,
            TRUE,
            UI_POPUP_NOTIFYDURATION_TIME,
            SUCCESS_TONE);
        DeleteNScrId(SCR_ID_VRSD_DIAL_MAIN_MENU);
    }
    else
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_ERROR),
            IMG_GLOBAL_ERROR,
            TRUE,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
        DeleteUptoScrID(SCR_ID_VRSD_DIAL_MAIN_MENU);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsddial_add_tag_from_list
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsddial_add_tag_from_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vrsddial_store_index = g_phb_cntx.active_index_second;
    mmi_vrsddial_add_tag();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsddial_add_tag
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsddial_add_tag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_vrsd_cntx.vrtag_id = mmi_vrsd_util_get_tag_id(MMI_VRSD_APP_NONE, 0xffff)) != 0xffff) /* Use 0xffff as parameter to get "empty tag id" */
    {
        mmi_vrsd_train_init(MMI_VRSD_APP_DIAL, g_vrsddial_store_index, mmi_vrsddial_train_result_callback);
    }
    else    /* No empty tag available */
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_VRSD_NO_EMPTY_TAG),
            IMG_GLOBAL_ERROR,
            TRUE,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsddial_change_tag
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsddial_change_tag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_vrsd_cntx.vrtag_id = mmi_vrsd_util_get_tag_id(MMI_VRSD_APP_DIAL, g_vrsddial_store_index)) != 0xffff)
    {
        mmi_vrsd_train_init(MMI_VRSD_APP_DIAL, g_vrsddial_store_index, mmi_vrsddial_train_result_callback);
    }
    else
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_EMPTY),
            IMG_GLOBAL_ERROR,
            TRUE,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsddial_delete_confirm
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsddial_delete_confirm(void)
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
        get_string(STR_GLOBAL_DELETE),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_vrsddial_delete_tag_req, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsddial_delete_tag_req
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsddial_delete_tag_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 tag_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((tag_id = mmi_vrsd_util_get_tag_id(MMI_VRSD_APP_DIAL, g_vrsddial_store_index)) != 0xffff)
    {
        mmi_vrsd_del_tag_req(tag_id);
    }
    else
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_EMPTY),
            IMG_GLOBAL_ERROR,
            TRUE,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
    }

    DeleteNScrId(SCR_ID_VRSD_DIAL_MAIN_MENU);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsddial_delete_all_tag_in_sim_pre_req
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsddial_delete_all_tag_in_sim_pre_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vrsddial_delete_all_tag_req(MMI_SIM);   /* SIM */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsddial_delete_all_tag_req
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  storage     [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsddial_delete_all_tag_req(U8 storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    vrsd_tag_struct tag_list[MMI_VRSD_MAX_TAG];
    S16 pError;
    S32 result;
    BOOL error = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Retrieve data from NVRAM */
    ReadRecord(
        NVRAM_EF_VRSD_TAG_LID,
        MMI_VRSD_GROUP_ALL,
        (void*)tag_list,
        MMI_VRSD_MAX_TAG * sizeof(vrsd_tag_struct),
        &pError);

    for (i = 0; i < MMI_VRSD_MAX_TAG; i++)
    {
        if (((tag_list[i].app_id == MMI_VRSD_APP_DIAL) && (tag_list[i].appref_id != 0xffff)) &&
            ((storage == MMI_STORAGE_BOTH) || (storage == MMI_SIM && tag_list[i].appref_id >= MAX_PB_PHONE_ENTRIES)))
        {
            result = media_aud_vr_del_tag(MOD_MMI, MED_VR_ISD_MODE, MED_VR_NO_CARE_LANG, MMI_VRSD_GROUP_ALL, i);

            if (result != MED_RES_OK)
            {
                error = TRUE;
                continue;
            }

            tag_list[i].appref_id = 0xffff;
            tag_list[i].app_id = MMI_VRSD_APP_NONE;
        }
    }

    WriteRecord(
        NVRAM_EF_VRSD_TAG_LID,
        MMI_VRSD_GROUP_ALL,
        (void*)tag_list,
        MMI_VRSD_MAX_TAG * sizeof(vrsd_tag_struct),
        &pError);

    if (error)
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_ERROR),
            IMG_GLOBAL_ERROR,
            TRUE,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
    }
    else
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_DONE),
            IMG_GLOBAL_ACTIVATED,
            TRUE,
            UI_POPUP_NOTIFYDURATION_TIME,
            SUCCESS_TONE);
    }

    DeleteNScrId(SCR_ID_VRSD_DIAL_MAIN_MENU);   /* If not delete all from main menu, then delete Idle screen SIM refresh confirm */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsddial_delete_tag_by_store_index
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  store_index     [IN]            
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsddial_delete_tag_by_store_index(U16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U16 tag_id;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tag_id = mmi_vrsd_util_get_tag_id(MMI_VRSD_APP_DIAL, store_index);

    result = media_aud_vr_del_tag(MOD_MMI, MED_VR_ISD_MODE, MED_VR_NO_CARE_LANG, MMI_VRSD_GROUP_ALL, tag_id);

}

#define MMI_VRSD_DIAL_RECG


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsddial_rcg_callback
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  appref_id       [IN]            
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsddial_rcg_callback(U16 appref_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check if phonebook is ready */
#ifdef __MMI_DUAL_SIM_MASTER__
     if(MTPNP_PFAL_Phb_IsReady()==MTPNP_FALSE)
#else   /* __MMI_DUAL_SIM_MASTER__ */
    if (!g_phb_cntx.phb_ready || g_phb_cntx.processing) /* Phonebook not ready */
#endif  /* __MMI_DUAL_SIM_MASTER__ */
    {
        DisplayPopup(
            (PU8) GetString(STR_PROCESSING_PHONEBOOK),
            IMG_GLOBAL_ERROR,
            TRUE,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
    }
    /* check tag mapping exists first. */
    else if ((appref_id != 0xffff) && mmi_phb_util_check_entry_exist(appref_id))
    {
        g_vrsddial_store_index = appref_id;
        /* playback */
        mmi_vrsd_playback_req(g_vrsd_cntx.vrtag_id, NULL);

        /* Entry Found Screen and dial out. */
        mmi_vrsddial_entry_rcg_found();
    }
    /* FDN on, entry in SIM mapping not found */
    else if ((appref_id != 0xffff) && (appref_id >= MAX_PB_PHONE_ENTRIES) && gSecuritySetupContext.FdlStatus)
    {
        DisplayPopup(
            (PU8) GetString(STR_FDL_IS_ON),
            IMG_GLOBAL_UNFINISHED,
            TRUE,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
    }
    /* Phonebook entry not exists. Need to do more prompt here? */
    else
    {
        mmi_vrsd_error_popup((U16) MED_RES_NO_MATCH);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsddial_entry_rcg_found
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsddial_entry_rcg_found(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S8 str_found[MAX_PB_NAME_LENGTH + 60];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VRSD_RCG_FOUND, mmi_vrsddial_exit_rcg_found, NULL, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_VRSD_RCG_FOUND);

    mmi_ucs2cpy(str_found, GetString(STR_ID_VRSD_DIAL_FOUND));
    mmi_ucs2cat(str_found, (S8*) PhoneBook[g_vrsddial_store_index].alpha_id.name);
    mmi_ucs2cat(str_found, (S8*) L"\n");
    mmi_ucs2cat(str_found, GetString(STR_ID_VRSD_DIAL_AUTO_DIAL));

    ShowCategory66Screen(
        STR_ID_VRSD_DIAL,
        IMG_ID_VRSD_APP,
        STR_GLOBAL_DIAL,    /* LSK STR */
        0,                  /* LSK IMG */
        STR_GLOBAL_ABORT,   /* RSK STR */
        0,                  /* RSK IMG */
        (U8*) str_found,    /* message string */
        0,                  /* icon id */
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_vrsddial_rcg_auto_dial, KEY_EVENT_UP);

    if (guiBuffer == NULL)
    {
        /* Automatically Dial out */
        StopTimer(VRSD_DIAL_AUTO_DIAL_TIMER);
        StartTimer(VRSD_DIAL_AUTO_DIAL_TIMER, MMI_VRSD_DIAL_OUT_TIME, mmi_vrsddial_rcg_auto_dial);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsddial_exit_rcg_found
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsddial_exit_rcg_found(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(VRSD_DIAL_AUTO_DIAL_TIMER);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsddial_rcg_auto_dial
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsddial_rcg_auto_dial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_vrsddial_auto_dial(g_vrsddial_store_index);
}

#define MMI_VRSD_DIAL_UTIL


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsddial_phb_get_new_highlight
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsddial_phb_get_new_highlight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i, j;
    U16 store_index;
    U16 EntryCount = 0;
    vrsd_tag_struct tag_list[MMI_VRSD_MAX_TAG];
    S16 pError;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Read voice tag list from NVRAM */
    ReadRecord(
        NVRAM_EF_VRSD_TAG_LID,
        MMI_VRSD_GROUP_ALL,
        (void*)tag_list,
        MMI_VRSD_MAX_TAG * sizeof(vrsd_tag_struct),
        &pError);

    for (i = 0; i < PhoneBookEntryCount; i++)
    {
        store_index = g_phb_name_index[i];

        for (j = 0; j < MMI_VRSD_MAX_TAG; j++)
        {
            if ((tag_list[j].app_id == MMI_VRSD_APP_DIAL) && (tag_list[j].appref_id == store_index))
            {
                if (store_index == g_vrsddial_store_index)
                {
                    g_phb_cntx.new_highlight_entry = EntryCount;
                    return;
                }

                EntryCount++;
                break;
            }
        }
    }

}

#endif /* defined(__MMI_VRSD__) && defined(__MMI_VRSD_DIAL__) */ /* #if defined(__MMI_VRSD__) && defined(__MMI_VRSD_DIAL__) */
#endif /* _MMI_VRSDDIAL_C */ /* #ifndef _MMI_VRSDDIAL_C */

