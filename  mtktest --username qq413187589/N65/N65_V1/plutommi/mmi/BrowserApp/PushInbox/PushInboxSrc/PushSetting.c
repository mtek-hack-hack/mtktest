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
 * JProfileUIHandler.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is source file for UI handling for the profile handler
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

#define __NEWSIMULATOR

#include "MMI_include.h"



#include "PushInboxResDef.h"
#include "PushInboxProts.h"
#include "ProfileHandlerResDef.h"
#include "custom_nvram_editor_data_item.h"

#include "CommonScreens.h"


#include "SettingProfile.h"
#include "Nvram_enums.h"
#include "ProtocolEvents.h"

#undef __NEWSIMULATOR
#ifdef __MMI_BROWSER_2__

global_push_cntx g_push_cntx;
static nvram_push_setting_struct SettingData = {0};
nvram_push_setting_struct *push_setting_data = &SettingData;

static U8 g_push_trust_setting_index, g_push_sl_setting_index, g_push_enable_index;


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_init_push
 * DESCRIPTION
 *  Push Setting initialization at boot up.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_init_push(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU_ID_PUSH_ENABLE, mmi_brw_push_enable_highlight_hdlr);
    SetHiliteHandler(MENU_ID_PUSH_TRUST_SETTING, mmi_brw_push_trust_setting_highlight_hdlr);
    SetHiliteHandler(MENU_ID_PUSH_SL_SETTING, mmi_brw_push_sl_setting_highlight_hdlr);
    SetHiliteHandler(MENU_ID_PUSH_TRUST_LIST, mmi_brw_push_trust_list_highlight_hdlr);

    SetHiliteHandler(MENU_ID_PUSH_TRUST_LIST_PHONE_NO, mmi_brw_push_trust_add_new_phone_highlight_hdlr);
    SetHiliteHandler(MENU_ID_PUSH_TRUST_LIST_IP_ADDRESS, mmi_brw_push_trust_add_new_ip_highlight_hdlr);
    SetHiliteHandler(MENU_ID_PUSH_TRUST_LIST_DOMAIN_NAME, mmi_brw_push_trust_add_new_domain_highlight_hdlr);

    SetHiliteHandler(MENU_ID_PUSH_TRUST_LIST_MODIFY, mmi_brw_push_modify_trust_addr_highlight_hdlr);
    SetHiliteHandler(MENU_ID_PUSH_TRUST_LIST_DELETE, mmi_brw_push_delete_trust_addr_highlight_hdlr);
    SetHiliteHandler(MENU_ID_PUSH_TRUST_LIST_DELETE_ALL, mmi_brw_push_delete_all_trust_addr_highlight_hdlr);

    SetHintHandler(MENU_ID_PUSH_ENABLE, HintPushEnable);
    SetHintHandler(MENU_ID_PUSH_TRUST_SETTING, HintPushTrustSetting);
    SetHintHandler(MENU_ID_PUSH_SL_SETTING, HintPushSlSetting);
}


/*****************************************************************************
 * FUNCTION
 *  HintPushEnable
 * DESCRIPTION
 *  Hint status for Enable push menu.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HintPushEnable(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((PS8) hintData[(index)], 0, sizeof(hintData[(index)]));
    mmi_ucs2cpy((PS8) hintData[(index)], (PS8) GetString(g_push_cntx.enable_push_strid));
}


/*****************************************************************************
 * FUNCTION
 *  HintPushTrustSetting
 * DESCRIPTION
 *  Hint status for Trust Setting menu.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HintPushTrustSetting(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((PS8) hintData[(index)], 0, sizeof(hintData[(index)]));
    mmi_ucs2cpy((PS8) hintData[(index)], (PS8) GetString(g_push_cntx.trust_setting_strid));
}


/*****************************************************************************
 * FUNCTION
 *  HintPushSlSetting
 * DESCRIPTION
 *  Hint status for SL Setting menu .
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HintPushSlSetting(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((PS8) hintData[(index)], 0, sizeof(hintData[(index)]));
    mmi_ucs2cpy((PS8) hintData[(index)], (PS8) GetString(g_push_cntx.sl_setting_strid));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_enable_highlight_hdlr
 * DESCRIPTION
 *  Higlight handler for Enable Push menu option.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_enable_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_brw_psh_entry_push_enable, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_psh_entry_push_enable, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_trust_setting_highlight_hdlr
 * DESCRIPTION
 *  Higlight handler for trust setting menu option.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_trust_setting_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_brw_psh_entry_trust_setting, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_psh_entry_trust_setting, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_sl_setting_highlight_hdlr
 * DESCRIPTION
 *  Higlight handler for Sl setting menu option.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_sl_setting_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_brw_psh_entry_sl_setting, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_psh_entry_sl_setting, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_trust_list_highlight_hdlr
 * DESCRIPTION
 *  Higlight handler for Trust List menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_trust_list_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_brw_psh_entry_trust_list, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_psh_entry_trust_list, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_trust_add_new_phone_highlight_hdlr
 * DESCRIPTION
 *  Higlight handler to Add New trust entry by phone number menu option.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_trust_add_new_phone_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_brw_psh_entry_by_phone_no, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_psh_entry_by_phone_no, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_trust_add_new_ip_highlight_hdlr
 * DESCRIPTION
 *  Higlight handler to Add New trust entry by IP address menu option.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_trust_add_new_ip_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_brw_psh_entry_by_ip_address, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_psh_entry_by_ip_address, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_trust_add_new_domain_highlight_hdlr
 * DESCRIPTION
 *  Higlight handler to Add New trust entry by domain name menu option.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_trust_add_new_domain_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_brw_psh_entry_by_domain_name, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_psh_entry_by_domain_name, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_modify_trust_addr_highlight_hdlr
 * DESCRIPTION
 *  Higlight handler to modify menu option.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_modify_trust_addr_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_brw_psh_entry_modify_trust_addr, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_psh_entry_modify_trust_addr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_delete_trust_addr_highlight_hdlr
 * DESCRIPTION
 *  Higlight handler to delete menu option.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_delete_trust_addr_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_brw_psh_entry_delete_trust_addr, KEY_EVENT_UP);
 //   SetKeyHandler(mmi_brw_psh_entry_delete_trust_addr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_delete_all_trust_addr_highlight_hdlr
 * DESCRIPTION
 *  Higlight handler to delete all menu option.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_delete_all_trust_addr_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_brw_psh_entry_delete_all_trust_addr, KEY_EVENT_UP);
  //  SetKeyHandler(mmi_brw_psh_entry_delete_all_trust_addr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_psh_entry_modify_trust_addr
 * DESCRIPTION
 *  Entry function to modify a trust list entry.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_psh_entry_modify_trust_addr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = mmi_brw_get_trust_addr_index();

    memset(g_push_cntx.trust_address, '\0', sizeof(g_push_cntx.trust_address));

    if (push_setting_data->trust_addr_arr[index].addr_type != WAP_PMG_ADDR_IP)
    {
        mmi_asc_to_ucs2((S8*) g_push_cntx.trust_address, (S8*) push_setting_data->trust_addr_arr[index].addr);
    }
    else
    {
        memcpy(g_push_cntx.trust_address, push_setting_data->trust_addr_arr[index].addr, NVRAM_PUSH_ADDR_LEN_MAX);
    }

    if (push_setting_data->trust_addr_arr[index].addr_type == WAP_PMG_ADDR_PHONE)
    {
        mmi_brw_psh_entry_by_phone_no();
    }
    else if (push_setting_data->trust_addr_arr[index].addr_type == WAP_PMG_ADDR_IP)
    {
        mmi_brw_psh_entry_by_ip_address();
    }
    else if (push_setting_data->trust_addr_arr[index].addr_type == WAP_PMG_ADDR_TEXT)
    {
        mmi_brw_psh_entry_by_domain_name();
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_psh_entry_delete_trust_addr
 * DESCRIPTION
 *  Entry function to delete a trust list entry.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_psh_entry_delete_trust_addr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S8 str[20];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((PS8) str, (PS8) get_string(STR_GLOBAL_DELETE));

    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (UI_string_type) str,
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_brw_psh_delete_trust_addr, KEY_EVENT_UP);
    
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
  //  SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_psh_delete_trust_addr
 * DESCRIPTION
 *  LSK handler for trust list delete option.It updates the NVRAM.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_psh_delete_trust_addr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;
    S16 error;
	 U8 trustaddr_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = mmi_brw_get_trust_addr_index();

    for (; index < g_push_cntx.trust_addr_count - 1; index++)
    {
        push_setting_data->trust_addr_arr[index].addr_type = push_setting_data->trust_addr_arr[index + 1].addr_type;
        strcpy(
            (S8*) push_setting_data->trust_addr_arr[index].addr,
            (S8*) push_setting_data->trust_addr_arr[index + 1].addr);
    }
    push_setting_data->trust_addr_arr[g_push_cntx.trust_addr_count - 1].addr_type = 0;
    strcpy((S8*) push_setting_data->trust_addr_arr[g_push_cntx.trust_addr_count - 1].addr, "");

    WriteRecord(NVRAM_EF_PUSH_SETTING_LID, 1, push_setting_data, sizeof(nvram_push_setting_struct), &error);
	g_push_cntx.trust_addr_count--;
	index = 0;

	while (index < g_push_cntx.trust_addr_count)
	{
		if ((g_push_cntx.trust_addr_count - index) < WAP_PMG_MAX_MSG_ADDR_LIST_SIZE)
		{
			trustaddr_count = g_push_cntx.trust_addr_count - index;
			mmi_brw_push_send_trust_list(index, trustaddr_count);
			index = g_push_cntx.trust_addr_count;
		}
		else
		{
			mmi_brw_push_send_trust_list(index, WAP_PMG_MAX_MSG_ADDR_LIST_SIZE);
			index = index + WAP_PMG_MAX_MSG_ADDR_LIST_SIZE;
		}
	}

	if (g_push_cntx.trust_addr_count == 0)
	{
		mmi_brw_push_send_trust_list(0, g_push_cntx.trust_addr_count);
	}

    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, 1000, SUCCESS_TONE);

    DeleteScreenIfPresent(SCR_ID_PSH_SELECT_TRUST_ADDRESS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_psh_entry_delete_all_trust_addr
 * DESCRIPTION
 *  Entry function for delete all option.It shows a confirmation screen. 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_psh_entry_delete_all_trust_addr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S8 str[26];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((PS8) str, (PS8) get_string(STR_GLOBAL_DELETE_ALL));

    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (UI_string_type) str,
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_brw_psh_delete_all_trust_addr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_psh_delete_all_trust_addr
 * DESCRIPTION
 *  This API deletes all the trust list entries and updates the NVRAM.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_psh_delete_all_trust_addr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 index, error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < g_push_cntx.trust_addr_count; index++)
    {
        push_setting_data->trust_addr_arr[index].addr_type = 0;
        strcpy((S8*) push_setting_data->trust_addr_arr[index].addr, "");
    }

    WriteRecord(NVRAM_EF_PUSH_SETTING_LID, 1, push_setting_data, sizeof(nvram_push_setting_struct), &error);

	 g_push_cntx.trust_addr_count = 0;

	 mmi_brw_push_send_trust_list(0, g_push_cntx.trust_addr_count);

    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, 1000, SUCCESS_TONE);

    DeleteScreenIfPresent(SCR_ID_PSH_SELECT_TRUST_ADDRESS);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_get_trust_addr_index
 * DESCRIPTION
 *  This API returns the index of the current selected trust list entry.
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 mmi_brw_get_trust_addr_index(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_push_cntx.trust_addr_count < NVRAM_PUSH_TRUST_ADDR_LIST_MAX)
    {
        return g_push_cntx.trust_addr_index - 1;
    }
    else
    {
        return g_push_cntx.trust_addr_index;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_psh_entry_by_phone_no
 * DESCRIPTION
 *  Entry function to add a new entry in trust list via phone number .
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_psh_entry_by_phone_no(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* U8    trust_address[NVRAM_PUSH_ADDR_LEN_MAX]; */

    EntryNewScreen(SCR_ID_PSH_ADD_NEW_BY_PHONE_NO, NULL, mmi_brw_psh_entry_by_phone_no, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_PSH_ADD_NEW_BY_PHONE_NO);

    ShowCategory5Screen(
        STR_ID_PUSH_INBOX_TRUST_LIST_PHONE_NUMBER,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        INPUT_TYPE_NUMERIC,
        g_push_cntx.trust_address,
        32,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_brw_psh_validate_phone_no, KEY_EVENT_UP);
    /* SetKeyHandler(mmi_brw_psh_validate_phone_no, KEY_RIGHT_ARROW, KEY_EVENT_DOWN); */
    SetCategory5RightSoftkeyFunction(mmi_brw_psh_free_mem_back_history, KEY_EVENT_UP);
    // SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    //      SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_psh_validate_phone_no
 * DESCRIPTION
 *  Validate the entered address in phone number format .If validation gets success then it
	saves the entry to NVRAM.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_psh_validate_phone_no(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	 U8 *addr_p = NULL;
	 S8 ucs2_len = 0, strlen_manual = 0;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	 addr_p = g_push_cntx.trust_address;
	 ucs2_len = mmi_ucs2strlen((S8*)g_push_cntx.trust_address); 

	while (*addr_p == '0' && strlen_manual <= NVRAM_PUSH_ADDR_LEN_MAX)
	{
		addr_p+=2;
		strlen_manual++;
	}
/*	if (i != 0)
	{
		mmi_ucs2cpy((S8*)g_push_cntx.trust_address, (S8*)addr_p);
	}
    
    if (g_push_cntx.trust_address[0] == '\0')*/
	if (strlen_manual == ucs2_len)
    {
        /* DisplayConfirm(
           STR_GLOBAL_INVALID,
           0,
           STR_GLOBAL_NO,
           IMG_GLOBAL_NO,
           get_string(STR_ID_PUSH_SETTING_INVALID_ENTRY),
           IMG_GLOBAL_QUESTION,
           0);
           
           SetLeftSoftkeyFunction(mmi_brw_psh_go_to_trust_screen, KEY_EVENT_UP);
           SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP); */

        DisplayPopup(
            (PU8) GetString(STR_ID_PUSH_SETTING_INVALID_ENTRY),
            IMG_GLOBAL_ERROR,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);

    }
    else
    {
        if (strlen_manual != 0)
		{
			mmi_ucs2cpy((S8*)g_push_cntx.trust_address, (S8*)addr_p);
		}
        DisplayConfirm(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            get_string(STR_GLOBAL_SAVE),
            IMG_GLOBAL_QUESTION,
            WARNING_TONE);

        SetLeftSoftkeyFunction(mmi_brw_psh_save_trust_entry_phone_no, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_brw_psh_phone_no_rsk_handling, KEY_EVENT_UP);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_psh_go_to_trust_screen
 * DESCRIPTION
 *  This API saves the trust list entry if they get modified or a new entry is added then it comes to 
	Push Trust list screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_psh_go_to_trust_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index, i;
    S16 error;
	 U8 trustaddr_count;
	U8 ascii_addr[NVRAM_PUSH_ADDR_LEN_MAX] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_push_cntx.add_entry_flag == PUSH_MODIFY_TRUST_ENTRY)
    {
        index = mmi_brw_get_trust_addr_index();
        mmi_ucs2_to_asc((S8*) push_setting_data->trust_addr_arr[index].addr, (S8*) g_push_cntx.trust_address);
    }
    else if (g_push_cntx.add_entry_flag == PUSH_ADD_NEW_TRUST_ENTRY)
    {
        mmi_ucs2_n_to_asc((S8*) ascii_addr,
			(S8*) g_push_cntx.trust_address,NVRAM_PUSH_ADDR_LEN_MAX * ENCODING_LENGTH);
		
		for (i = 0; i < g_push_cntx.trust_addr_count; i++)
		{
			if (strcmp((S8*)ascii_addr,
						(S8*)push_setting_data->trust_addr_arr[i].addr) == 0)
			{
				DisplayPopup(
				(PU8) GetString(STR_ID_PUSH_SAME_ITEM_EXIST),
				IMG_GLOBAL_WARNING,
				1,
				UI_POPUP_NOTIFYDURATION_TIME,
				ERROR_TONE);
				DeleteUptoScrID(SCR_ID_PSH_TRUST_LIST);
				return;
			}
		}

        push_setting_data->trust_addr_arr[g_push_cntx.trust_addr_count].addr_type = g_push_cntx.trust_addr_type;
        mmi_ucs2_to_asc(
            (S8*) push_setting_data->trust_addr_arr[g_push_cntx.trust_addr_count].addr,
            (S8*) g_push_cntx.trust_address);
		g_push_cntx.trust_addr_count++;  // ritesh this might affect some others.needs to check
    }
	index = 0;
	while (index < g_push_cntx.trust_addr_count)
	{
		if ((g_push_cntx.trust_addr_count - index) < WAP_PMG_MAX_MSG_ADDR_LIST_SIZE)
		{
			trustaddr_count = g_push_cntx.trust_addr_count - index;
			mmi_brw_push_send_trust_list(index, trustaddr_count);
			index = g_push_cntx.trust_addr_count;
		}
		else
		{
			mmi_brw_push_send_trust_list(index, WAP_PMG_MAX_MSG_ADDR_LIST_SIZE);
			index = index + WAP_PMG_MAX_MSG_ADDR_LIST_SIZE;
		}
	}

    WriteRecord(NVRAM_EF_PUSH_SETTING_LID, 1, push_setting_data, sizeof(nvram_push_setting_struct), &error);
    /* ReadRecord(NVRAM_EF_PUSH_SETTING_LID, 1,push_setting_data, sizeof(nvram_push_setting_struct), &error); */
	 DisplayPopup(
		(PU8) GetString(STR_GLOBAL_DONE),
		IMG_GLOBAL_ACTIVATED,
		1,
		UI_POPUP_NOTIFYDURATION_TIME,
		SUCCESS_TONE);
    DeleteUptoScrID(SCR_ID_PSH_TRUST_LIST);
 //   GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_psh_save_trust_entry_phone_no
 * DESCRIPTION
 *  Saves the trust entry as phone number.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_psh_save_trust_entry_phone_no(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_push_cntx.trust_addr_type = WAP_PMG_ADDR_PHONE;
    mmi_brw_psh_go_to_trust_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_psh_phone_no_rsk_handling
 * DESCRIPTION
 * RSK handling for add new entry by phone number editor screen. 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_psh_phone_no_rsk_handling(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteScreenIfPresent(SCR_ID_PSH_ADD_NEW_BY_PHONE_NO);
    memset((S8*) g_push_cntx.trust_address, '\0', sizeof(g_push_cntx.trust_address));
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_psh_entry_by_domain_name
 * DESCRIPTION
 *  Entry function to add a ner entry to trust list via domain name.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_psh_entry_by_domain_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_PSH_ADD_NEW_BY_DOMAIN_NAME, NULL, mmi_brw_psh_entry_by_domain_name, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_PSH_ADD_NEW_BY_DOMAIN_NAME);

    ShowCategory5Screen(
        STR_ID_PUSH_INBOX_TRUST_LIST_DOMAIN_NAME,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES,
        g_push_cntx.trust_address,
        NVRAM_PUSH_ADDR_LEN_MAX,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_brw_psh_validate_domain_name, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(mmi_brw_psh_free_mem_back_history, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_psh_validate_domain_name
 * DESCRIPTION
 *  It validates the new entry entered as domain name .
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_psh_validate_domain_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_push_cntx.trust_address[0] == '\0')
    {
        /* DisplayConfirm(
           STR_GLOBAL_INVALID,
           0,
           STR_GLOBAL_NO,
           IMG_GLOBAL_NO,
           get_string(STR_ID_PUSH_INBOX_SERVICE_MESSAGE_DELETE),
           IMG_GLOBAL_QUESTION,
           0);
           
           SetLeftSoftkeyFunction(mmi_brw_psh_go_to_trust_screen, KEY_EVENT_UP);
           SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP); */
        DisplayPopup(
            (PU8) GetString(STR_ID_PUSH_SETTING_INVALID_ENTRY),
            IMG_GLOBAL_ERROR,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
    }
    else
    {

        DisplayConfirm(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            get_string(STR_GLOBAL_SAVE),
            IMG_GLOBAL_QUESTION,
            WARNING_TONE);

        SetLeftSoftkeyFunction(mmi_brw_psh_save_trust_entry_domain_name, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_brw_psh_domain_rsk_handling, KEY_EVENT_UP);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_psh_free_mem_back_history
 * DESCRIPTION
 *	RSK handler for phone number editor screen .
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_psh_free_mem_back_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) g_push_cntx.trust_address, '\0', sizeof(g_push_cntx.trust_address));
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_psh_save_trust_entry_domain_name
 * DESCRIPTION
 *  Save the trust entry by Domain name.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_psh_save_trust_entry_domain_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_push_cntx.trust_addr_type = WAP_PMG_ADDR_TEXT;
    mmi_brw_psh_go_to_trust_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_psh_domain_rsk_handling
 * DESCRIPTION
 * RSK handling for domain name editor screen. 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_psh_domain_rsk_handling(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteScreenIfPresent(SCR_ID_PSH_ADD_NEW_BY_DOMAIN_NAME);
    memset((S8*) g_push_cntx.trust_address, '\0', sizeof(g_push_cntx.trust_address));
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_psh_entry_by_ip_address
 * DESCRIPTION
 *  Entry function to add a new entry to trust list in ip address format.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_psh_entry_by_ip_address(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *input_buffer_p = NULL; /* added for inline edit history */
    U8 *gui_buffer_p = NULL; /* Buffer holding history data */
    U16 input_buffer_size;
    U16 EditConnTypeIconList[2] = {IMG_GLOBAL_L1, 0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_PSH_ADD_NEW_BY_IP_ADDRESS, mmi_brw_push_exit_add_new_by_ip_address, NULL, NULL);

    InitializeCategory57Screen();

    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_PSH_ADD_NEW_BY_IP_ADDRESS);
    input_buffer_p = GetCurrNInputBuffer(SCR_ID_PSH_ADD_NEW_BY_IP_ADDRESS, &input_buffer_size);        /* added for inline edit history */

    mmi_brw_push_edit_ip_fill_inline_struct();

    if (input_buffer_p != NULL)
    {
        SetCategory57Data(wgui_inline_items, 2, input_buffer_p);

    }
    if (GetInlineDoneFlag(gui_buffer_p) != 0)
    {
        SetInlineDoneFlag(gui_buffer_p);
    }
    /* else
       {
       DisableCategory57ScreenDone();
       }
       //  SetInlineListMenuChanged();
       //  DisableCategory57ScreenDone();
       // set_wgui_inline_list_menu_status(1);
       //NOTE : this thing is if we want to update the connection type on the change in highlight...presently not needed       
       //      RegisterHighlightHandler(mmi_brw_prof_highlight_inline_item_conn_type);
       
       //   g_prof_done_flag = 0x01; */

    ShowCategory57Screen(
        STR_ID_PUSH_INBOX_TRUST_LIST_IP_ADDRESS,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_ID_PUSH_INBOX_TRUST_LIST_IP_ADDRESS,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        2,
        EditConnTypeIconList,
        wgui_inline_items,
        0,
        gui_buffer_p);

    //       ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    //       SetLeftSoftkeyFunction(mmi_brw_psh_save_trust_entry_ip_address, KEY_EVENT_UP);
    SetCategory57RightSoftkeyFunctions(mmi_brw_psh_show_save_confirmation_scr, GoBackHistory);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_psh_show_save_confirmation_scr
 * DESCRIPTION
 *  Dispalys confirmation screen for a trust list entry going to be added in IP address format.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_psh_show_save_confirmation_scr(void)
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
        get_string(STR_GLOBAL_SAVE),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_brw_psh_save_trust_entry_ip_address, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_brw_psh_ip_rsk_handling, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_psh_save_trust_entry_ip_address
 * DESCRIPTION
 * Save &  validate the trust list entry. 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_psh_save_trust_entry_ip_address(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 ip_value[4];
    U32 ip_sum = 0;
    S8 ucs2_val[2];
    S8 *val = ".";

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ip_value[0] = (U8) gui_atoi((UI_string_type) g_push_cntx.IP1);
    ip_value[1] = (U8) gui_atoi((UI_string_type) g_push_cntx.IP2);
    ip_value[2] = (U8) gui_atoi((UI_string_type) g_push_cntx.IP3);
    ip_value[3] = (U8) gui_atoi((UI_string_type) g_push_cntx.IP4);

    ip_sum = ip_value[0] + ip_value[1] + ip_value[2] + ip_value[3];

    if (ip_sum == 0x00)
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_PROF_HDLR_INVALID_IP),
            IMG_GLOBAL_ERROR,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
    }
    else
    {
        mmi_asc_to_ucs2((S8*) ucs2_val, (S8*) val);

        mmi_ucs2cpy((S8*) g_push_cntx.trust_address, (S8*) g_push_cntx.IP1);
        mmi_ucs2cat((S8*) g_push_cntx.trust_address, (S8*) ucs2_val);

        mmi_ucs2cat((S8*) g_push_cntx.trust_address, (S8*) g_push_cntx.IP2);
        mmi_ucs2cat((S8*) g_push_cntx.trust_address, (S8*) ucs2_val);

        mmi_ucs2cat((S8*) g_push_cntx.trust_address, (S8*) g_push_cntx.IP3);
        mmi_ucs2cat((S8*) g_push_cntx.trust_address, (S8*) ucs2_val);

        mmi_ucs2cat((S8*) g_push_cntx.trust_address, (S8*) g_push_cntx.IP4);

        g_push_cntx.trust_addr_type = WAP_PMG_ADDR_IP;
        mmi_brw_psh_go_to_trust_screen();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_psh_ip_rsk_handling
 * DESCRIPTION
 *  RSK handler for a trust list entry in IP address format.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_psh_ip_rsk_handling(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteScreenIfPresent(SCR_ID_PSH_ADD_NEW_BY_IP_ADDRESS);
    GoBackHistory();
}

extern U8 mmi_prov_convert_proxy_ipstring_to_array(U8 *parm_element_p, U8 *proxy_ip_p);


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_edit_ip_fill_inline_struct
 * DESCRIPTION
 *  This API allows user to edit the TRUST list entry in IP address format.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_edit_ip_fill_inline_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 proxy_ip[4];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetInlineItemActivation((wgui_inline_items + 1), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption((wgui_inline_items + 0), (U8*) GetString(STR_ID_PUSH_INBOX_TRUST_LIST_IP_ADDRESS));

    if (mmi_prov_convert_proxy_ipstring_to_array(g_push_cntx.trust_address, proxy_ip) != 1)
    {
        ReturnThreeDigitString(g_push_cntx.IP1, proxy_ip[0]);
        ReturnThreeDigitString(g_push_cntx.IP2, proxy_ip[1]);
        ReturnThreeDigitString(g_push_cntx.IP3, proxy_ip[2]);
        ReturnThreeDigitString(g_push_cntx.IP4, proxy_ip[3]);
    }
    else
    {
        ReturnThreeDigitString(g_push_cntx.IP1, (U8) g_push_cntx.trust_address[0]);
        ReturnThreeDigitString(g_push_cntx.IP2, (U8) g_push_cntx.trust_address[1]);
        ReturnThreeDigitString(g_push_cntx.IP3, (U8) g_push_cntx.trust_address[2]);
        ReturnThreeDigitString(g_push_cntx.IP4, (U8) g_push_cntx.trust_address[3]);
    }

    SetInlineItemIP4(
        (wgui_inline_items + 1),
        (U8*) g_push_cntx.IP1,
        (U8*) g_push_cntx.IP2,
        (U8*) g_push_cntx.IP3,
        (U8*) g_push_cntx.IP4,
        PreparedIPAddressString);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_exit_add_new_by_ip_address
 * DESCRIPTION
 *  Exit handler for IP address entry screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_exit_add_new_by_ip_address(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    U16 input_buffer_size;
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    h.scrnID = SCR_ID_PSH_ADD_NEW_BY_IP_ADDRESS; 
    CloseCategory57Screen();
    h.entryFuncPtr = mmi_brw_psh_entry_by_ip_address;
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & nHistory);
    GetCategory57History(h.guiBuffer);
    input_buffer_size = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) h.inputBuffer);
    AddNHistory(h, input_buffer_size);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_enable_index
 * DESCRIPTION
 *  This API updates the global data when user select push enable menu option as ON/OFF
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_enable_index(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_push_enable_index = (U8) index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_sl_setting_index
 * DESCRIPTION
 * This API updates the global data when user select push SL setting option as Never/Confirm/Without Confirm
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_sl_setting_index(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_push_sl_setting_index = (U8) index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_trust_setting_index
 * DESCRIPTION
 *  This API updates the global data when user select Trust setting menu option as Disable/Always Ask.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_trust_setting_index(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_push_trust_setting_index = (U8) index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_psh_entry_push_enable
 * DESCRIPTION
 *  Entry function to ENable Push menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_psh_entry_push_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 *gui_buffer_p;   /* Buffer holding history data */
    U32 num_of_item;    /* Stores no of children in the submenu */
    U32 count;
    U16 nStrItemList[3];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_PSH_PUSH_ENABLE, NULL, mmi_brw_psh_entry_push_enable, NULL);

    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_PSH_PUSH_ENABLE);

    num_of_item = GetNumOfChild(MENU_ID_PUSH_ENABLE);
    GetSequenceStringIds(MENU_ID_PUSH_ENABLE, nStrItemList);
    SetParentHandler(MENU_ID_PUSH_ENABLE);

    for (count = 0; count < num_of_item; count++)
    {
        memset((S8*) subMenuDataPtrs[count], 0, MAX_SUB_MENU_SIZE);
        mmi_ucs2ncpy((S8*) subMenuDataPtrs[count], (S8*) GetString(nStrItemList[count]), MAX_SUBMENU_CHARACTERS);
    }

    RegisterHighlightHandler(mmi_brw_push_enable_index);

  /*  ShowCategory353Screen(
        (U8*) GetString(STR_ID_PUSH_INBOX_ENABLE_PUSH),
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_of_item,
        (U8 **) subMenuDataPtrs,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        gui_buffer_p);*/

	 ShowCategory36Screen(
        STR_ID_PUSH_INBOX_ENABLE_PUSH,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_SELECT,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_of_item,
        (U8 **) subMenuDataPtrs,
        (U16) g_push_enable_index,
        gui_buffer_p);

    SetLeftSoftkeyFunction(mmi_brw_push_save_push_enable_status, KEY_EVENT_UP);
  //  SetKeyHandler(mmi_brw_push_save_push_enable_status, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
  //  SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_psh_entry_trust_setting
 * DESCRIPTION
 *  Entry Function to Trust Setting menu .
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_psh_entry_trust_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 *gui_buffer_p;   /* Buffer holding history data */
    U32 num_of_item;    /* Stores no of children in the submenu */
    U32 count;
    U16 nStrItemList[3];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_PSH_TRUST_SETTING, NULL, mmi_brw_psh_entry_trust_setting, NULL);

    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_PSH_TRUST_SETTING);

    num_of_item = GetNumOfChild(MENU_ID_PUSH_TRUST_SETTING);
    GetSequenceStringIds(MENU_ID_PUSH_TRUST_SETTING, nStrItemList);
    SetParentHandler(MENU_ID_PUSH_TRUST_SETTING);

    for (count = 0; count < num_of_item; count++)
    {
        memset((S8*) subMenuDataPtrs[count], 0, MAX_SUB_MENU_SIZE);
        mmi_ucs2ncpy((S8*) subMenuDataPtrs[count], (S8*) GetString(nStrItemList[count]), MAX_SUBMENU_CHARACTERS);
    }

    RegisterHighlightHandler(mmi_brw_push_trust_setting_index);

  /*  ShowCategory353Screen(
        (U8*) GetString(STR_ID_PUSH_INBOX_TRUST_SETTING),
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_of_item,
        (U8 **) subMenuDataPtrs,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        gui_buffer_p);*/

	ShowCategory36Screen(
        STR_ID_PUSH_INBOX_TRUST_SETTING,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_SELECT,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_of_item,
        (U8 **) subMenuDataPtrs,
        (U16) g_push_trust_setting_index,
        gui_buffer_p);


    SetLeftSoftkeyFunction(mmi_brw_push_save_trust_setting_status, KEY_EVENT_UP);
 //   SetKeyHandler(mmi_brw_push_save_trust_setting_status, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

  //  SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_psh_entry_sl_setting
 * DESCRIPTION
 *  Entry Function to SL Setting menu .
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_psh_entry_sl_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 *gui_buffer_p;   /* Buffer holding history data */
    U32 num_of_item;    /* Stores no of children in the submenu */
    U32 count;
    U16 nStrItemList[3];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_PSH_SL_SETTING, NULL, mmi_brw_psh_entry_sl_setting, NULL);

    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_PSH_SL_SETTING);

    num_of_item = GetNumOfChild(MENU_ID_PUSH_SL_SETTING);
    GetSequenceStringIds(MENU_ID_PUSH_SL_SETTING, nStrItemList);
    SetParentHandler(MENU_ID_PUSH_SL_SETTING);

    for (count = 0; count < num_of_item; count++)
    {
        memset((S8*) subMenuDataPtrs[count], 0, MAX_SUB_MENU_SIZE);
        mmi_ucs2ncpy((S8*) subMenuDataPtrs[count], (S8*) GetString(nStrItemList[count]), MAX_SUBMENU_CHARACTERS);
    }

    RegisterHighlightHandler(mmi_brw_push_sl_setting_index);

 /*   ShowCategory353Screen(
        (U8*) GetString(STR_ID_PUSH_INBOX_SL_SETTING),
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_of_item,
        (U8 **) subMenuDataPtrs,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        gui_buffer_p);*/

	ShowCategory36Screen(
        STR_ID_PUSH_INBOX_SL_SETTING,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_SELECT,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_of_item,
        (U8 **) subMenuDataPtrs,
        (U16) g_push_sl_setting_index,
        gui_buffer_p);

    SetLeftSoftkeyFunction(mmi_brw_push_save_sl_setting_status, KEY_EVENT_UP);
//    SetKeyHandler(mmi_brw_push_save_sl_setting_status, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

 //   SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_psh_entry_trust_list
 * DESCRIPTION
 *  Entry Function to Trust List menu .
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_psh_entry_trust_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 *gui_buffer_p = NULL, trusted_addr_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_PSH_TRUST_LIST, NULL, mmi_brw_psh_entry_trust_list, NULL);

    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_PSH_TRUST_LIST);

    RegisterHighlightHandler(mmi_brw_psh_highlight_trust_list_addr);

    mmi_brw_psh_get_trust_list();
    trusted_addr_count = g_push_cntx.trust_addr_count;

    if (trusted_addr_count < NVRAM_PUSH_TRUST_ADDR_LIST_MAX)
    {
        trusted_addr_count++;
    }

    /* ShowCategory53Screen(
       STR_ID_PROF_HDLR_SELECT_PROF_CAPTION,
       GetRootTitleIcon(SERVICES_WAP_MENU_ID),
       STR_GLOBAL_OK,
       IMG_GLOBAL_OK,
       STR_GLOBAL_BACK,
       IMG_GLOBAL_BACK,
       trusted_addr_count,
       (U8 **) subMenuDataPtrs,
       (PU16)0,
       0,
       0,
       0,
       gui_buffer_p); */

    ShowCategory353Screen(
        (U8*) GetString(STR_ID_PUSH_INBOX_TRUSTED_LIST),
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        trusted_addr_count,
        (U8 **) subMenuDataPtrs,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        gui_buffer_p);

    SetLeftSoftkeyFunction(mmi_brw_push_pre_entry_edit_addr, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_push_pre_entry_edit_addr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_save_push_enable_status
 * DESCRIPTION
 *  This API saves the ENable push status and send its status to service layer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_save_push_enable_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (push_setting_data->push_enable_flag != g_push_enable_index)
    {
        push_setting_data->push_enable_flag = g_push_enable_index;
        WriteRecord(NVRAM_EF_PUSH_SETTING_LID, 1, push_setting_data, sizeof(nvram_push_setting_struct), &error);
		  mmi_brw_push_send_config_ind();
    }
	DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, 1000, SUCCESS_TONE);
    DeleteScreenIfPresent(SCR_ID_PSH_PUSH_ENABLE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_save_trust_setting_status
 * DESCRIPTION
 *  This API saves the trust setting status to NVRAM.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_save_trust_setting_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (push_setting_data->trust_setting_flag != g_push_trust_setting_index)
    {
        push_setting_data->trust_setting_flag = g_push_trust_setting_index;
        WriteRecord(NVRAM_EF_PUSH_SETTING_LID, 1, push_setting_data, sizeof(nvram_push_setting_struct), &error);
		  mmi_brw_push_send_config_ind();
    }
	DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, 1000, SUCCESS_TONE);
	DeleteScreenIfPresent(SCR_ID_PSH_TRUST_SETTING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_save_sl_setting_status
 * DESCRIPTION
 *  This API saves the SL setting status to NVRAM.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_save_sl_setting_status(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (push_setting_data->sl_setting_flag != g_push_sl_setting_index)
    {
        push_setting_data->sl_setting_flag = g_push_sl_setting_index;
        WriteRecord(NVRAM_EF_PUSH_SETTING_LID, 1, push_setting_data, sizeof(nvram_push_setting_struct), &error);
		  mmi_brw_push_send_config_ind();
    }
	DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, 1000, SUCCESS_TONE);
    DeleteScreenIfPresent(SCR_ID_PSH_SL_SETTING);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_psh_get_trust_list
 * DESCRIPTION
 *  This API is used to get the trust list in submenu data.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_psh_get_trust_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_push_cntx.trust_addr_count = 0;

    for (count = 0; count < NVRAM_PUSH_TRUST_ADDR_LIST_MAX && push_setting_data->trust_addr_arr[count].addr[0] != '\0';
         count++)
    {
        mmi_asc_n_to_ucs2((S8*) subMenuData[count], (S8*) push_setting_data->trust_addr_arr[count].addr, 41);
        g_push_cntx.trust_addr_count++;

    }
    count = g_push_cntx.trust_addr_count;

    if (count < NVRAM_PUSH_TRUST_ADDR_LIST_MAX)
    {

        for (; count != 0; count--)
        {
            mmi_ucs2cpy((S8*) subMenuData[count], (S8*) subMenuData[count - 1]);
        }
        mmi_ucs2cpy((S8*) subMenuData[0], (S8*) GetString(STR_ID_PUSH_INBOX_TRUST_LIST_ADD_NEW));
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_get_trust_list_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_psh_get_trust_list_count(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   /* g_push_cntx.trust_addr_count = 0;

    while( g_push_cntx.trust_addr_count < NVRAM_PUSH_TRUST_ADDR_LIST_MAX && 
		push_setting_data->trust_addr_arr[g_push_cntx.trust_addr_count].addr[0] != '\0')
	{
        g_push_cntx.trust_addr_count++;

    }*/
	for (g_push_cntx.trust_addr_count = 0;
		g_push_cntx.trust_addr_count < NVRAM_PUSH_TRUST_ADDR_LIST_MAX && 
		push_setting_data->trust_addr_arr[g_push_cntx.trust_addr_count].addr[0] != '\0';
		g_push_cntx.trust_addr_count++);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_pre_entry_edit_addr
 * DESCRIPTION
 * Pre entry edit function to select a entry from Trust List. 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_pre_entry_edit_addr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_push_cntx.trust_addr_index == 0 && g_push_cntx.trust_addr_count < NVRAM_PUSH_TRUST_ADDR_LIST_MAX)
    {
        memset(g_push_cntx.trust_address, 0, sizeof(g_push_cntx.trust_address));
        g_push_cntx.add_entry_flag = PUSH_ADD_NEW_TRUST_ENTRY;
        mmi_brw_push_entry_add_new_addr();
    }
    else
    {
        g_push_cntx.add_entry_flag = PUSH_MODIFY_TRUST_ENTRY;
        mmi_brw_push_entry_select_editable_addr();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_entry_add_new_addr
 * DESCRIPTION
 *  Entry function to add a new entry to trust list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_entry_add_new_addr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 *gui_buffer_p;   /* Buffer holding history data */
    U32 num_of_item;    /* Stores no of children in the submenu */
    U32 count;
    U16 nStrItemList[3];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_PSH_ADD_NEW, NULL, mmi_brw_push_entry_add_new_addr, NULL);

    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_PSH_ADD_NEW);

    num_of_item = GetNumOfChild(MENU_ID_PUSH_TRUST_ADD_NEW);
    GetSequenceStringIds(MENU_ID_PUSH_TRUST_ADD_NEW, nStrItemList);
    SetParentHandler(MENU_ID_PUSH_TRUST_ADD_NEW);

    for (count = 0; count < num_of_item; count++)
    {
        memset((S8*) subMenuDataPtrs[count], 0, MAX_SUB_MENU_SIZE);
        mmi_ucs2ncpy((S8*) subMenuDataPtrs[count], (S8*) GetString(nStrItemList[count]), MAX_SUBMENU_CHARACTERS);
    }

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory353Screen(
        (U8*) GetString(STR_ID_PUSH_INBOX_ADD_NEW),
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_of_item,
        (U8 **) subMenuDataPtrs,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        gui_buffer_p);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_entry_select_editable_addr
 * DESCRIPTION
 *  Entry function to edit a selceted entry from the trust list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_entry_select_editable_addr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 *gui_buffer_p;   /* Buffer holding history data */
    U32 num_of_item;    /* Stores no of children in the submenu */
    U32 count;
    U16 nStrItemList[3];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_PSH_SELECT_TRUST_ADDRESS, NULL, mmi_brw_push_entry_select_editable_addr, NULL);

    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_PSH_SELECT_TRUST_ADDRESS);

    num_of_item = GetNumOfChild(MENU_ID_PUSH_TRUST_SELECT_ADDR);
    GetSequenceStringIds(MENU_ID_PUSH_TRUST_SELECT_ADDR, nStrItemList);
    SetParentHandler(MENU_ID_PUSH_TRUST_SELECT_ADDR);

    for (count = 0; count < num_of_item; count++)
    {
        memset((S8*) subMenuDataPtrs[count], 0, MAX_SUB_MENU_SIZE);
        mmi_ucs2ncpy((S8*) subMenuDataPtrs[count], (S8*) GetString(nStrItemList[count]), MAX_SUBMENU_CHARACTERS);
    }

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory353Screen(
        (U8*) GetString(STR_GLOBAL_OPTIONS),
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_of_item,
        (U8 **) subMenuDataPtrs,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        gui_buffer_p);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_psh_highlight_trust_list_addr
 * DESCRIPTION
 * Highlight handler for the index in the trust list.It updates the global data for further use.  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_psh_highlight_trust_list_addr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_push_cntx.trust_addr_index = (U8) index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_phs_pre_entry_push_setting
 * DESCRIPTION
 *  This is pre entry function to push setting menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_phs_pre_entry_push_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_init_push();
    mmi_brw_phs_get_setting_from_nvram();
    mmi_brw_phs_entry_push_setting();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_phs_entry_push_setting
 * DESCRIPTION
 *  Entry function for push setting menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_phs_entry_push_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;                      /* Buffer holding history data */
    U16 nStrItemList[MAX_SUB_MENUS];    /* Stores the strings id of submenus returned */
    U16 nNumofItem;                     /* Stores no of children in the submenu */
    U8 *PopUpList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_PSH_PUSH_SETTING, NULL, mmi_brw_phs_entry_push_setting, NULL);

    mmi_brw_push_setting_update_hint_status();
    /* Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_ID_PSH_PUSH_SETTING);
    /* Retrieve no of child of menu item to be displayed */
    nNumofItem = GetNumOfChild_Ext(MENU_ID_PUSH_SETTING);
    GetSequenceStringIds_Ext(MENU_ID_PUSH_SETTING, nStrItemList);
    /* Set current parent id */
    SetParentHandler(MENU_ID_PUSH_SETTING);
    /* Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* construct hint popup strings for menu items */
    ConstructHintsList(MENU_ID_PUSH_SETTING, PopUpList);

    ShowCategory52Screen(
        STR_ID_PUSH_INBOX_SETTING,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        (U8 **) PopUpList,
        0,
        0,
        guiBuffer);

    /* Register function with right softkey */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_phs_get_setting_from_nvram
 * DESCRIPTION
 *  This API collects the push setting from NVRAM.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_phs_get_setting_from_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  /*  if (push_setting_data == NULL)
    {
        push_setting_data = (nvram_push_setting_struct*) OslMalloc(sizeof(nvram_push_setting_struct));
    }*/

    ReadRecord(NVRAM_EF_PUSH_SETTING_LID, 1, push_setting_data, sizeof(nvram_push_setting_struct), &error);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_setting_update_hint_status
 * DESCRIPTION
 *  This API is responsible for updation of various menu hint status.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_setting_update_hint_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (push_setting_data->trust_setting_flag == PUSH_TRUST_SETTING_DISABLE)
    {
        g_push_cntx.trust_setting_strid = STR_ID_PUSH_INBOX_TRUST_LIST_DISABLE;
		g_push_trust_setting_index = push_setting_data->trust_setting_flag;
    }
    else if (push_setting_data->trust_setting_flag == PUSH_TRUST_SETTING_ALWAYS)
    {
        g_push_cntx.trust_setting_strid = STR_ID_PUSH_INBOX_TRUST_LIST_ALWAYS;
		g_push_trust_setting_index = push_setting_data->trust_setting_flag;
    }
    else if (push_setting_data->trust_setting_flag == PUSH_TRUST_SETTING_ALWAYS_ASK)
    {
        g_push_cntx.trust_setting_strid = STR_ID_PUSH_INBOX_TRUST_LIST_ALWAYS_ASK;
		g_push_trust_setting_index = push_setting_data->trust_setting_flag;
    }

    if (push_setting_data->sl_setting_flag == PUSH_SL_SETTING_NEVER)
    {
        g_push_cntx.sl_setting_strid = STR_ID_PUSH_INBOX_SL_SETTING_NEVER;
		g_push_sl_setting_index = push_setting_data->sl_setting_flag;
    }
    else if (push_setting_data->sl_setting_flag == PUSH_SL_SETTING_CONFIRM)
    {
        g_push_cntx.sl_setting_strid = STR_ID_PUSH_INBOX_SL_SETTING_CONFIRM;
		g_push_sl_setting_index = push_setting_data->sl_setting_flag;
    }
    else if (push_setting_data->sl_setting_flag == PUSH_SL_SETTING_WITHOUT_CONFIRM)
    {
        g_push_cntx.sl_setting_strid = STR_ID_PUSH_INBOX_SL_SETTING_WITHOUT_CONFIRM;
		g_push_sl_setting_index = push_setting_data->sl_setting_flag;
    }

    if (push_setting_data->push_enable_flag == PUSH_ENABLE_ON)
    {
        g_push_cntx.enable_push_strid = STR_ID_PUSH_ENABLE_ON;
		g_push_enable_index = push_setting_data->push_enable_flag;
    }
    else if (push_setting_data->push_enable_flag == PUSH_ENABLE_OFF)
    {
        g_push_cntx.enable_push_strid = STR_ID_PUSH_ENABLE_OFF;
		g_push_enable_index = push_setting_data->push_enable_flag;
    }
}
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_psh_set_default_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_psh_set_default_setting(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    MMIEQNVRAMRESETREQ *local_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = MSG_ID_MMI_EQ_NVRAM_RESET_REQ;
    local_data = (MMIEQNVRAMRESETREQ*) OslConstructDataPtr(sizeof(MMIEQNVRAMRESETREQ));

    local_data->lid = NVRAM_EF_PUSH_SETTING_LID; /* please fill in the desired LID here */
    local_data->reset_category = NVRAM_RESET_CERTAIN;
    
    Message.oslDataPtr = (oslParaType*) local_data;
    Message.oslPeerBuffPtr = NULL;
    SetProtocolEventHandler(mmi_brw_psh_restore_default_setting, MSG_ID_MMI_EQ_NVRAM_RESET_RSP);
    OslMsgSendExtQueue(&Message);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_psh_restore_default_setting
 * DESCRIPTION
 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

void mmi_brw_psh_restore_default_setting(void *msg)
{
	S16 error;
	
	ReadRecord(NVRAM_EF_PUSH_SETTING_LID, 1, push_setting_data, sizeof(nvram_push_setting_struct), &error);
}
#endif
