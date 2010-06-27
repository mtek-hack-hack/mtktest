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

#include "wgui_inline_edit.h"

#include "ServiceDefs.h"
#include "CommonScreens.h"
#include "ProfileHandlerTypes.h"
#include "ProfileHandlerProts.h"
#include "ProfileHandlerResDef.h"
#include "CentralConfigAgentResDef.h"
#include "BrowserMain.h"
#include "DataAccountGProt.h"
#include "Wap_ps_struct.h"
#include "custom_nvram_editor_data_item.h"

#include "Nvram_enums.h"

#undef __NEWSIMULATOR
/*  Include: MMI header file */

#ifdef __MMI_BROWSER_2__

profile_context_struct g_prof_cntx;

static U8 g_prof_conn_index;
static U8 g_prof_done_flag;
static U8 g_prof_data_account_index;
static g_prof_connection_type;

nvram_profile_content_struct *g_prof_profile_content_p[] = {0, 0};
nvram_profile_name_array_struct *g_prof_name_arr_p[] = {0, 0};
nvram_profile_content_struct *g_prof_activated_profile_content[] = {0, 0};

extern void mmi_prov_send_end_key_event(void);
extern void mmi_brw_active_profile_changed(void);
extern void mmi_umms_set_current_mms_profile(BOOL boot_up);
extern void mmi_prov_send_cca_status(void);
/****************************************************************************
* Macro
*****************************************************************************/
#define SELECT_BEARER(index, func_ptr)                           \
{                                                                \
   case index:                                                   \
      {                                                          \
         SetLeftSoftkeyFunction(func_ptr,KEY_EVENT_UP);          \
         SetKeyHandler(func_ptr, KEY_RIGHT_ARROW,KEY_EVENT_DOWN);\
      }                                                          \
      break;                                                     \
}

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_deinit_profiles
 * DESCRIPTION
 *  This is the deinitialization routine,to free the memory  & reset values used by profile handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prof_deinit_profiles(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_prof_cntx.profile_display_p != NULL)
    {
        OslMfree(g_prof_cntx.profile_display_p);
        g_prof_cntx.profile_display_p = NULL;
    }
   /***** Deinitialize memory for Browser ******/

    if (g_prof_name_arr_p[BRW_PROF_BROWSER_PROFILE] != NULL)
    {
        OslMfree(g_prof_name_arr_p[BRW_PROF_BROWSER_PROFILE]);
        g_prof_name_arr_p[BRW_PROF_BROWSER_PROFILE] = NULL;
    }

    if (g_prof_profile_content_p[BRW_PROF_BROWSER_PROFILE] != NULL)
    {
        OslMfree(g_prof_profile_content_p[BRW_PROF_BROWSER_PROFILE]);
        g_prof_profile_content_p[BRW_PROF_BROWSER_PROFILE] = NULL;
    }

    if (g_prof_activated_profile_content[BRW_PROF_BROWSER_PROFILE] != NULL)
    {
        OslMfree(g_prof_activated_profile_content[BRW_PROF_BROWSER_PROFILE]);
        g_prof_activated_profile_content[BRW_PROF_BROWSER_PROFILE] = NULL;
    }
   /***** Deinitialize memory for MMS ******/

    if (g_prof_name_arr_p[BRW_PROF_MMS_PROFILE] != NULL)
    {
        OslMfree(g_prof_name_arr_p[BRW_PROF_MMS_PROFILE]);
        g_prof_name_arr_p[BRW_PROF_MMS_PROFILE] = NULL;
    }

    if (g_prof_profile_content_p[BRW_PROF_MMS_PROFILE] != NULL)
    {
        OslMfree(g_prof_profile_content_p[BRW_PROF_MMS_PROFILE]);
        g_prof_profile_content_p[BRW_PROF_MMS_PROFILE] = NULL;
    }

    if (g_prof_activated_profile_content[BRW_PROF_MMS_PROFILE] != NULL)
    {
        OslMfree(g_prof_activated_profile_content[BRW_PROF_MMS_PROFILE]);
        g_prof_activated_profile_content[BRW_PROF_MMS_PROFILE] = NULL;
    }
	 g_prof_cntx.active_profile_modified = FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_init
 * DESCRIPTION
 *  This is the profile handler Initialization API
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prof_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   /***** initialization for Browser *******/
    /* mmi_brw_prof_set_default_setting(BRW_PROF_BROWSER_PROFILE); */

    if (g_prof_activated_profile_content[BRW_PROF_BROWSER_PROFILE] == NULL)
    {
        g_prof_activated_profile_content[BRW_PROF_BROWSER_PROFILE] =
            (nvram_profile_content_struct*) OslMalloc(NVRAM_EF_WAP_PROFILE_CONTENT_SIZE);
    }
    ReadValue(
        NVRAM_BRW_ACTIVATED_WAP_PROFILE_INDEX,
        &g_prof_cntx.actived_profile_content_index[BRW_PROF_BROWSER_PROFILE],
        DS_BYTE,
        &error);
    if (g_prof_cntx.actived_profile_content_index[BRW_PROF_BROWSER_PROFILE] > NVRAM_PROFILE_MAX)
    {
        g_prof_cntx.actived_profile_content_index[BRW_PROF_BROWSER_PROFILE] = 0x00;
        WriteValue(
            NVRAM_BRW_ACTIVATED_WAP_PROFILE_INDEX,
            &g_prof_cntx.actived_profile_content_index[BRW_PROF_BROWSER_PROFILE],
            DS_BYTE,
            &error);
    }

    mmi_brw_prof_get_activated_profile_data(
        BRW_PROF_BROWSER_PROFILE,
        g_prof_cntx.actived_profile_content_index[BRW_PROF_BROWSER_PROFILE]);

   /***** initialization for MMS *******/

    if (g_prof_activated_profile_content[BRW_PROF_MMS_PROFILE] == NULL)
    {
        g_prof_activated_profile_content[BRW_PROF_MMS_PROFILE] =
            (nvram_profile_content_struct*) OslMalloc(NVRAM_EF_MMS_PROFILE_CONTENT_SIZE);
    }
    ReadValue(
        NVRAM_BRW_ACTIVATED_MMS_PROFILE_INDEX,
        &g_prof_cntx.actived_profile_content_index[BRW_PROF_MMS_PROFILE],
        DS_BYTE,
        &error);
    if (g_prof_cntx.actived_profile_content_index[BRW_PROF_MMS_PROFILE] > NVRAM_PROFILE_MAX)
    {
        g_prof_cntx.actived_profile_content_index[BRW_PROF_MMS_PROFILE] = 0x00;
        WriteValue(
            NVRAM_BRW_ACTIVATED_MMS_PROFILE_INDEX,
            &g_prof_cntx.actived_profile_content_index[BRW_PROF_MMS_PROFILE],
            DS_BYTE,
            &error);
    }

    mmi_brw_prof_get_activated_profile_data(
        BRW_PROF_MMS_PROFILE,
        g_prof_cntx.actived_profile_content_index[BRW_PROF_MMS_PROFILE]);

    /* Set Highlight handlers */
    SetHiliteHandler(MENU_ID_PROF_SELECT_PROFILE_DELETE, mmi_brw_prof_delete_profile_highlight_hdlr);
    SetHiliteHandler(MENU_ID_PROF_SELECT_PROFILE_ACTIVATE, mmi_brw_prof_activate_profile_highlight_hdlr);
    SetHiliteHandler(MENU_ID_PROF_SELECT_PROFILE_EDIT, mmi_brw_prof_edit_profile_highlight_hdlr);
    SetHiliteHandler(MENU_ID_PROF_SELECT_PROFILE_VIEW_ONLY, mmi_brw_prof_edit_profile_highlight_hdlr);

	SetProtocolEventHandler(mmi_brw_prof_activated_profile_id_req,MSG_ID_WAP_GET_BRA_PROF_ID_REQ);
//	SetProtocolEventHandler(mmi_brw_prof_profile_content_req,MSG_ID_WAP_GET_PROF_CONTENT_REQ);
	SetProtocolEventHandler((PsFuncPtr) mmi_brw_prof_profile_content_req, MSG_ID_WAP_GET_PROF_CONTENT_REQ);
	SetProtocolEventHandler((PsFuncPtr)mmi_brw_prof_profile_list_req,MSG_ID_WAP_GET_PROF_LIST_REQ);
	SetProtocolEventHandler(jam_get_user_agent_req, MSG_ID_WAP_GET_USER_AGENT_REQ);

	g_prof_cntx.active_profile_modified = FALSE;
	g_prof_cntx.active_profile_deleted = FALSE; 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_edit_profile_highlight_hdlr
 * DESCRIPTION
 *  *  It is the highlight handler for the (MENU_ID_PROF_SELECT_PROFILE_EDIT menu item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prof_edit_profile_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_brw_prof_pre_entry_edit_selected_profile, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_prof_pre_entry_edit_selected_profile, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_delete_profile_highlight_hdlr
 * DESCRIPTION
 *  It is the highlight handler for the (MENU_ID_PROF_SELECT_PROFILE_DELETE menu item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prof_delete_profile_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_brw_prof_pre_entry_delete_selected_profile, KEY_EVENT_UP);
   // SetKeyHandler(mmi_brw_prof_entry_delete_selected_profile, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_activate_profile_highlight_hdlr
 * DESCRIPTION
 *  It is the highlight handler for the (MENU_ID_PROF_SELECT_PROFILE_ACTIVATE menu item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prof_activate_profile_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

  //  SetLeftSoftkeyFunction(mmi_brw_prof_entry_activate_selected_profile, KEY_EVENT_UP);
	SetLeftSoftkeyFunction(mmi_brw_prof_activate_selected_profile, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_entry_activate_selected_profile
 * DESCRIPTION
 *  It is the entry function for the activate profile confirmation screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prof_entry_activate_selected_profile(void)
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
        get_string(STR_ID_PROF_HDLR_ACTIVATE_PROFILE),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_brw_prof_activate_selected_profile, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_pre_entry_delete_selected_profile
 * DESCRIPTION
 *  This is pre entry function before delete can be performed.It checks whether the profile going to be deleted 
	is the currently activated profile.If so then it display a confirmation screen first.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prof_pre_entry_delete_selected_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = mmi_brw_prof_update_profile_index();
    /*if (index == g_prof_cntx.actived_profile_name_index[g_prof_cntx.profile_module])
    {*/
        DisplayConfirm(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            get_string(STR_ID_PROF_HDLR_DELETE_PROFILE),
            IMG_GLOBAL_QUESTION,
            WARNING_TONE);

        SetLeftSoftkeyFunction(mmi_brw_prof_entry_delete_selected_profile, KEY_EVENT_UP);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    /*}
    else
    {
        mmi_brw_prof_entry_delete_selected_profile();
    }*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_entry_delete_selected_profile
 * DESCRIPTION
 *  Entry function to delete a selected profile.It deletes the profile and updates the NVRAM.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prof_entry_delete_selected_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 index, temp_index = 0;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = mmi_brw_prof_update_profile_index();

    if (g_prof_cntx.actived_profile_content_index[g_prof_cntx.profile_module] ==
        g_prof_name_arr_p[g_prof_cntx.profile_module]->nvram_profile_name_array[index].content_index)
    {
        temp_index = 1;
    }

    mmi_brw_prof_reset_profile_content(g_prof_name_arr_p[g_prof_cntx.profile_module]->nvram_profile_name_array[index].
                                     content_index);

    for (; index < NVRAM_PROFILE_MAX; index++)
    {
        g_prof_name_arr_p[g_prof_cntx.profile_module]->nvram_profile_name_array[index].conn_type
            = g_prof_name_arr_p[g_prof_cntx.profile_module]->nvram_profile_name_array[index + 1].conn_type;

        g_prof_name_arr_p[g_prof_cntx.profile_module]->nvram_profile_name_array[index].content_index
            = g_prof_name_arr_p[g_prof_cntx.profile_module]->nvram_profile_name_array[index + 1].content_index;

        g_prof_name_arr_p[g_prof_cntx.profile_module]->nvram_profile_name_array[index].permission_bits
            = g_prof_name_arr_p[g_prof_cntx.profile_module]->nvram_profile_name_array[index + 1].permission_bits;

        g_prof_name_arr_p[g_prof_cntx.profile_module]->nvram_profile_name_array[index].dcs
            = g_prof_name_arr_p[g_prof_cntx.profile_module]->nvram_profile_name_array[index + 1].dcs;

        mmi_ucs2cpy(
            (S8*) g_prof_name_arr_p[g_prof_cntx.profile_module]->nvram_profile_name_array[index].profile_name,
            (S8*) g_prof_name_arr_p[g_prof_cntx.profile_module]->nvram_profile_name_array[index + 1].profile_name);

    }
    if (temp_index == 1)
    {
        g_prof_cntx.actived_profile_content_index[g_prof_cntx.profile_module]
            = g_prof_name_arr_p[g_prof_cntx.profile_module]->nvram_profile_name_array[0].content_index;
		mmi_brw_prof_get_activated_profile_data(g_prof_cntx.profile_module, 
								g_prof_cntx.actived_profile_content_index[g_prof_cntx.profile_module]);
		if (g_prof_cntx.profile_module == BRW_PROF_BROWSER_PROFILE)
		{
			g_prof_cntx.active_profile_modified = TRUE;
			mmi_brw_active_profile_changed_without_ui();
		}
		else if (g_prof_cntx.profile_module == BRW_PROF_MMS_PROFILE)
		{
			g_prof_cntx.active_profile_modified = TRUE;
			mmi_umms_set_current_mms_profile(TRUE);
		}
		g_prof_cntx.active_profile_deleted = TRUE;
    }
	
    if (g_prof_cntx.profile_module == BRW_PROF_BROWSER_PROFILE)
    {
        WriteValue(
            NVRAM_BRW_ACTIVATED_WAP_PROFILE_INDEX,
            &g_prof_cntx.actived_profile_content_index[g_prof_cntx.profile_module],
            DS_BYTE,
            &error);
        WriteRecord(
            NVRAM_EF_WAP_PROFILE_NAMES_LID,
            1,
            g_prof_name_arr_p[g_prof_cntx.profile_module],
            NVRAM_EF_WAP_PROFILE_NAMES_SIZE,
            &error);
    }
    else if (g_prof_cntx.profile_module == BRW_PROF_MMS_PROFILE)
    {
        WriteValue(
            NVRAM_BRW_ACTIVATED_MMS_PROFILE_INDEX,
            &g_prof_cntx.actived_profile_content_index[g_prof_cntx.profile_module],
            DS_BYTE,
            &error);
        WriteRecord(
            NVRAM_EF_MMS_PROFILE_NAMES_LID,
            1,
            g_prof_name_arr_p[g_prof_cntx.profile_module],
            NVRAM_EF_MMS_PROFILE_NAMES_SIZE,
            &error);
    }
    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, UI_POPUP_NOTIFYDURATION_TIME, SUCCESS_TONE);
    DeleteNHistory(1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_activate_selected_profile
 * DESCRIPTION
 *  This API activates the selected profile and updates the NVRAM.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prof_activate_selected_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = mmi_brw_prof_update_profile_index();

    g_prof_cntx.actived_profile_content_index[g_prof_cntx.profile_module]
        = g_prof_name_arr_p[g_prof_cntx.profile_module]->nvram_profile_name_array[index].content_index;
    if (g_prof_cntx.profile_module == BRW_PROF_BROWSER_PROFILE)
    {
        WriteValue(
            NVRAM_BRW_ACTIVATED_WAP_PROFILE_INDEX,
            &g_prof_cntx.actived_profile_content_index[g_prof_cntx.profile_module],
            DS_BYTE,
            &error);
    }
    else if (g_prof_cntx.profile_module == BRW_PROF_MMS_PROFILE)
    {
        WriteValue(
            NVRAM_BRW_ACTIVATED_MMS_PROFILE_INDEX,
            &g_prof_cntx.actived_profile_content_index[g_prof_cntx.profile_module],
            DS_BYTE,
            &error);
    }
    mmi_brw_prof_get_activated_profile_data(
        g_prof_cntx.profile_module,
        g_prof_cntx.actived_profile_content_index[g_prof_cntx.profile_module]);

    /*mmi_brw_active_profile_changed();*/
	
	if (g_prof_cntx.profile_module == BRW_PROF_BROWSER_PROFILE
		&& g_prof_cntx.prov_flag == BRW_NO_PROVISIONING)
	{
    mmi_brw_active_profile_changed();
	}
	else if (g_prof_cntx.profile_module == BRW_PROF_MMS_PROFILE
		&& g_prof_cntx.prov_flag == BRW_NO_PROVISIONING)
	{
	    mmi_umms_set_current_mms_profile(FALSE);
}
}
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_display_activation_popup
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prof_display_activation_popup(void)
{
	if (g_prof_cntx.prov_flag == BRW_NO_PROVISIONING)
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_DONE),
            IMG_GLOBAL_ACTIVATED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            SUCCESS_TONE);
        DeleteNHistory(1);
		DeleteScreenIfPresent(SCR_ID_PROF_HDLR_EDIT_PROFILE);
		DeleteScreenIfPresent(SCR_ID_PROF_HDLR_SELECTED_PROFILE);
     }
	 else if (g_prof_cntx.prov_flag == BRW_PROV_BROWSER_ONLY)
	 {
		 mmi_prov_send_cca_status();
	 }
	 g_prof_cntx.active_profile_modified = FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_pre_entry_edit_selected_profile
 * DESCRIPTION
 *  It is the pre entry function for the edit profile screen,in this the profile content data is
 *  extracted from the NVRAM & data account info is requested ,on the response of data account
 *  edit profile entry function is called.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prof_pre_entry_edit_selected_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index, temp_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_prof_done_flag = 0x00;
    index = mmi_brw_prof_update_profile_index();

    temp_index = g_prof_name_arr_p[g_prof_cntx.profile_module]->nvram_profile_name_array[index].content_index;

    mmi_brw_prof_get_selected_profile_content_data(temp_index);
    DataAccountReadyCheck(mmi_brw_prof_pre_entry_data_account);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_get_selected_profile_content_data
 * DESCRIPTION
 *  This gets the content data for the profile index selected()
 *  its general for browser & MMS profiles
 * PARAMETERS
 *  profile_index       [IN]        Profile index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prof_get_selected_profile_content_data(U8 profile_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_prof_profile_content_p[g_prof_cntx.profile_module] == NULL)
    {
        g_prof_profile_content_p[g_prof_cntx.profile_module] =
            (nvram_profile_content_struct*) OslMalloc(NVRAM_EF_WAP_PROFILE_CONTENT_SIZE);
    }

    mmi_brw_prof_get_profile_nvram_content_data(profile_index);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_pre_entry_show_profile_list_menu
 * DESCRIPTION
 *  It is an pre entry function for showing profile name list.
 *  This makes the global profile name data ready to be displayed
 * PARAMETERS
 *  profile     [IN]        Profile Type (Browser or MMS)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prof_pre_entry_show_profile_list_menu(prof_profile_enum profile)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (profile == BRW_PROF_BROWSER_PROFILE || profile == BRW_PROF_BROWSER_PROV_PROFILE)
    {
        g_prof_cntx.profile_module = BRW_PROF_BROWSER_PROFILE;
        /* mmi_brw_prof_init();  // ritesh added for temporary as init will be done by browser */
        mmi_brw_prof_get_brw_profile_name_list();
    }
    else if (profile == BRW_PROF_MMS_PROFILE || profile == BRW_PROF_MMS_PROV_PROFILE)
    {
        g_prof_cntx.profile_module = BRW_PROF_MMS_PROFILE;
        /* mmi_brw_prof_init();  // ritesh added for temporary as init will be done by browser */
        mmi_brw_prof_get_mms_profile_name_list();
    }
    if (profile == BRW_PROF_MMS_PROV_PROFILE || profile == BRW_PROF_BROWSER_PROV_PROFILE)
    {
        g_prof_cntx.prov_flag = BRW_PROV_BROWSER_ONLY;
        mmi_brw_prof_get_profile_name_list();
        if (g_prof_cntx.profile_count1 == NVRAM_PROFILE_MAX)
        {
            mmi_brw_prof_entry_show_profile_list_menu();
        }
        else
        {
            mmi_brw_prov_save_profile();
        }
    }
    else
    {
        g_prof_cntx.prov_flag = BRW_NO_PROVISIONING;
        mmi_brw_prof_entry_show_profile_list_menu();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_entry_show_profile_list_menu
 * DESCRIPTION
 *  Entry function to show profile name list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
//extern void mmi_test_dm(void);
void mmi_brw_prof_entry_show_profile_list_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 *gui_buffer_p = NULL, profile_count;
    S32 activated_index = 0;

    U16 activated_profile_image[NVRAM_PROFILE_MAX] = {0, };
	 U16 title_id,lsk_id,lsk_img_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* g_prov_pend_set = 0; */

    /* activated_index = mmi_brw_prof_get_activated_profile_index(); */

    EntryNewScreen(SCR_ID_PROF_HDLR_PROF_LIST, NULL, mmi_brw_prof_entry_show_profile_list_menu, NULL);

    if (g_prof_cntx.active_profile_deleted == TRUE)
	{
		g_prof_cntx.active_profile_deleted = FALSE;
	}
	else
	{
    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_PROF_HDLR_PROF_LIST);
	}

    RegisterHighlightHandler(mmi_brw_prof_highlight_select_profile);

    activated_index = mmi_brw_prof_get_profile_name_list();
    profile_count = g_prof_cntx.profile_count1;
    if (profile_count == 0)
    {
        if (g_prof_cntx.profile_module == BRW_PROF_BROWSER_PROFILE)
        {
            activated_profile_image[g_prof_cntx.actived_profile_name_index[g_prof_cntx.profile_module]] = 0;
        }
        /* else
           {
           activated_profile_image[g_prof_cntx.mms_actived_profile_name_index] = 0;
           } */
    }
    else
    {
        if (profile_count == NVRAM_PROFILE_MAX)
        {
            activated_profile_image[g_prof_cntx.actived_profile_name_index[g_prof_cntx.profile_module]] =
                IMG_ID_PROF_HDLR_SET_ACTIVATED_PROFILE;
        }
        else
        {
            activated_profile_image[g_prof_cntx.actived_profile_name_index[g_prof_cntx.profile_module] + 1] =
                IMG_ID_PROF_HDLR_SET_ACTIVATED_PROFILE;
        }
    }
    if (profile_count < NVRAM_PROFILE_MAX)
    {
        profile_count++;
        activated_index++;
    }
	 if (g_prof_cntx.prov_flag == BRW_PROV_BROWSER_ONLY)
	 {
		 title_id = STR_ID_CCA_REPLACE_SETTING;
		 lsk_id = STR_GLOBAL_INSTALL;
		 lsk_img_id = 0;
	 }
	 else
	 {
		 title_id = STR_ID_PROF_HDLR_SELECT_PROF_CAPTION;
		 lsk_id = STR_GLOBAL_OK;
		 lsk_img_id = IMG_GLOBAL_OK;
	 }
    ShowCategory53Screen(
        title_id,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        lsk_id,
        lsk_img_id,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        profile_count,
        (U8 **) subMenuDataPtrs,
        (PU16) activated_profile_image,
        0,
        0,
        activated_index,
        gui_buffer_p);

    if (g_prof_cntx.prov_flag == BRW_PROV_BROWSER_ONLY)
    {
        SetLeftSoftkeyFunction(mmi_brw_prov_update_selected_profile, KEY_EVENT_UP);
        SetKeyHandler(mmi_brw_prov_update_selected_profile, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_prov_send_end_key_event, KEY_END, KEY_EVENT_DOWN);
    }
    else
    {
        SetLeftSoftkeyFunction(mmi_brw_prof_pre_entry_edit_profile, KEY_EVENT_UP);
        SetKeyHandler(mmi_brw_prof_pre_entry_edit_profile, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
//	SetKeyHandler(mmi_test_dm,KEY_1,KEY_EVENT_UP);

    /* Register function for left soft key */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_pre_entry_edit_profile
 * DESCRIPTION
 *  It is an pre entry function for edit or add a new profile.
 *  for any selected profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prof_pre_entry_edit_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_prof_cntx.profile_index == 0 && g_prof_cntx.profile_count1 < NVRAM_PROFILE_MAX)
    {
        mmi_brw_prof_entry_add_new_profile();
    }
    else
    {
        mmi_brw_prof_entry_select_editable_profile();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_entry_select_editable_profile
 * DESCRIPTION
 *  This is entry function for the screen showing menu items (Activate ,Edit profile,Delete Profile )
 *  for any selected profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prof_entry_select_editable_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 *gui_buffer_p;       /* Buffer holding history data */
    U32 num_of_item = 0;    /* Stores no of children in the submenu */
    S8 profile_name_string[(NVRAM_PROFILE_NAME_LEN + 1) * ENCODING_LENGTH];
    U32 count, index;
    U16 nStrItemList[3];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_PROF_HDLR_SELECTED_PROFILE, NULL, mmi_brw_prof_entry_select_editable_profile, NULL);

    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_PROF_HDLR_SELECTED_PROFILE);

    index = mmi_brw_prof_update_profile_index();

    if (g_prof_name_arr_p[g_prof_cntx.profile_module]->nvram_profile_name_array[index].permission_bits
        == BRW_PROF_READ_WRITE)
    {
        num_of_item = GetNumOfChild(MENU_ID_PROF_SELECT_PROFILE);
        GetSequenceStringIds(MENU_ID_PROF_SELECT_PROFILE, nStrItemList);
        SetParentHandler(MENU_ID_PROF_SELECT_PROFILE);
    }
    else if (g_prof_name_arr_p[g_prof_cntx.profile_module]->nvram_profile_name_array[index].permission_bits
             == BRW_PROF_READ_ONLY)
    {
        num_of_item = GetNumOfChild(MENU_ID_PROF_SELECT_DEFAULT_PROFILE);
        GetSequenceStringIds(MENU_ID_PROF_SELECT_DEFAULT_PROFILE, nStrItemList);
        SetParentHandler(MENU_ID_PROF_SELECT_DEFAULT_PROFILE);
    }

    for (count = 0; count < num_of_item; count++)
    {
        memset((S8*) subMenuDataPtrs[count], 0, MAX_SUB_MENU_SIZE);
        mmi_ucs2ncpy((S8*) subMenuDataPtrs[count], (S8*) GetString(nStrItemList[count]), MAX_SUBMENU_CHARACTERS);
    }

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* index=mmi_brw_prof_update_profile_index(); */

    if (g_prof_name_arr_p[g_prof_cntx.profile_module]->nvram_profile_name_array[index].dcs == BRW_PROF_DCS_ASCII)
    {
        mmi_asc_to_ucs2(
            (S8*) profile_name_string,
            (S8*) g_prof_name_arr_p[g_prof_cntx.profile_module]->nvram_profile_name_array[index].profile_name);
    }
    else if (g_prof_name_arr_p[g_prof_cntx.profile_module]->nvram_profile_name_array[index].dcs == BRW_PROF_DCS_UCS)
    {
        mmi_ucs2cpy(
            (S8*) profile_name_string,
            (S8*) (g_prof_name_arr_p[g_prof_cntx.profile_module]->nvram_profile_name_array[index].profile_name));
    }

    ShowCategory353Screen(
        (U8*) (profile_name_string),
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
 *  mmi_brw_prof_get_activated_profile_index
 * DESCRIPTION
 *  THis API returns the activated profile index
 * PARAMETERS
 *  void
 * RETURNS
 *  U8    activated profile index
 *****************************************************************************/
U8 mmi_brw_prof_get_activated_profile_index(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_prof_cntx.profile_module == BRW_PROF_BROWSER_PROFILE)
    {
        ReadValue(
            NVRAM_BRW_ACTIVATED_WAP_PROFILE_INDEX,
            &g_prof_cntx.actived_profile_content_index[g_prof_cntx.profile_module],
            DS_BYTE,
            &error);
    }
    else if (g_prof_cntx.profile_module == BRW_PROF_MMS_PROFILE)
    {
        ReadValue(
            NVRAM_BRW_ACTIVATED_MMS_PROFILE_INDEX,
            &g_prof_cntx.actived_profile_content_index[g_prof_cntx.profile_module],
            DS_BYTE,
            &error);
    }
    return g_prof_cntx.actived_profile_content_index[g_prof_cntx.profile_module];

    /* return 0; */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_entry_add_new_profile
 * DESCRIPTION
 *  This API is used to fill the default content to a new profile.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prof_entry_add_new_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = mmi_brw_prof_check_free_content_index(g_prof_cntx.profile_count1);

    if (g_prof_profile_content_p[g_prof_cntx.profile_module] == NULL)
    {
        g_prof_profile_content_p[g_prof_cntx.profile_module] =
            (nvram_profile_content_struct*) OslMalloc(NVRAM_EF_WAP_PROFILE_CONTENT_SIZE);
    }
    g_prof_profile_content_p[g_prof_cntx.profile_module]->data_account_primary_id
        = BRW_PROF_DEFAULT_DATA_ACCOUNT_PRIMARY_ID;

    g_prof_profile_content_p[g_prof_cntx.profile_module]->data_account_secondary_id
        = BRW_PROF_DEFAULT_DATA_ACCOUNT_SECONDARY_ID;

    g_prof_profile_content_p[g_prof_cntx.profile_module]->conn_type = BRW_PROF_DEFAULT_CONN_TYPE;

    g_prof_profile_content_p[g_prof_cntx.profile_module]->proxy_ip[0] = BRW_PROF_DEFAULT_IP1;
    g_prof_profile_content_p[g_prof_cntx.profile_module]->proxy_ip[1] = BRW_PROF_DEFAULT_IP2;
    g_prof_profile_content_p[g_prof_cntx.profile_module]->proxy_ip[2] = BRW_PROF_DEFAULT_IP3;
    g_prof_profile_content_p[g_prof_cntx.profile_module]->proxy_ip[3] = BRW_PROF_DEFAULT_IP4;

    g_prof_profile_content_p[g_prof_cntx.profile_module]->proxy_port = BRW_PROF_DEFAULT_PROXY_PORT;

    
	 strcpy((S8*) g_prof_profile_content_p[g_prof_cntx.profile_module]->url, (S8*) BRW_PROF_DEFAULT_URL_NAME);
    strcpy((S8*) g_prof_profile_content_p[g_prof_cntx.profile_module]->username, (S8*) BRW_PROF_DEFAULT_USERNAME);
    strcpy((S8*) g_prof_profile_content_p[g_prof_cntx.profile_module]->password, (S8*) BRW_PROF_DEFAULT_PASSWORD);

    g_prof_name_arr_p[g_prof_cntx.profile_module]->nvram_profile_name_array[g_prof_cntx.profile_count1].content_index =
        index;

    DataAccountReadyCheck(mmi_brw_prof_pre_entry_data_account);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_check_free_content_index
 * DESCRIPTION
 *  This API checks for the free index from content index array of NVRAM_PROFILE_MAX .
	NVRAM_PROFILE_MAX = 10
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_brw_prof_check_free_content_index(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 temp_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_index = index;
    if (g_prof_cntx.content_index_array[index] == 0)
    {
        return index;
    }
    while (g_prof_cntx.content_index_array[temp_index] != 0 && temp_index != 0)
    {
        --temp_index;
        if (g_prof_cntx.content_index_array[temp_index] == 0)
        {
            return temp_index;
        }
    }
    temp_index = index;
    while (g_prof_cntx.content_index_array[temp_index] != 0 && temp_index != NVRAM_PROFILE_MAX)
    {
        ++temp_index;
        if (g_prof_cntx.content_index_array[temp_index] == 0)
        {
            return temp_index;
        }
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_get_profile_name_list
 * DESCRIPTION
 *  This API extracts profile names from the g_prof_name_arr_p
 *  into the subMenuData to be displayed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_brw_prof_get_profile_name_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, prof_count = 0;
    U8 content_index, activated_index, activated_index_flag = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_prof_cntx.profile_count1 = 0;
    activated_index = mmi_brw_prof_get_activated_profile_index();
    if (activated_index > NVRAM_PROFILE_MAX)
    {
        activated_index = 0;
    }
    for (content_index = 0; content_index < NVRAM_PROFILE_MAX; content_index++)
    {
        g_prof_cntx.content_index_array[content_index] = 0;
    }

    for (i = 0; i < NVRAM_PROFILE_MAX; i++)
    {
        if (g_prof_name_arr_p[g_prof_cntx.profile_module]->nvram_profile_name_array[i].dcs == BRW_PROF_DCS_UCS)
        {
            if (g_prof_name_arr_p[g_prof_cntx.profile_module]->nvram_profile_name_array[i].profile_name != '\0')
            {
                mmi_ucs2cpy(
                    (S8*) subMenuData[i],
                    (S8*) (g_prof_name_arr_p[g_prof_cntx.profile_module]->nvram_profile_name_array[i].profile_name));
				
                if (activated_index ==
                    g_prof_name_arr_p[g_prof_cntx.profile_module]->nvram_profile_name_array[i].content_index &&
                    activated_index_flag == 0)
                {
                    activated_index = i;
                    g_prof_cntx.actived_profile_name_index[g_prof_cntx.profile_module] = i;
                    activated_index_flag = 1;
                }
                g_prof_cntx.content_index_array[g_prof_name_arr_p[g_prof_cntx.profile_module]->
                                                nvram_profile_name_array[i].content_index] = 1;
                g_prof_cntx.profile_count1++;
            }

        }
        else if (g_prof_name_arr_p[g_prof_cntx.profile_module]->nvram_profile_name_array[i].dcs == BRW_PROF_DCS_ASCII)
        {
            if (g_prof_name_arr_p[g_prof_cntx.profile_module]->nvram_profile_name_array[i].profile_name[0] != '\0')
            {
                mmi_asc_to_ucs2(
                    (S8*) subMenuData[i],
                    (S8*) (g_prof_name_arr_p[g_prof_cntx.profile_module]->nvram_profile_name_array[i].profile_name));
               /**** added for content index availability ****/

                if (activated_index ==
                    g_prof_name_arr_p[g_prof_cntx.profile_module]->nvram_profile_name_array[i].content_index &&
                    activated_index_flag == 0)
                {
                    activated_index = i;
                    g_prof_cntx.actived_profile_name_index[g_prof_cntx.profile_module] = i;
                    activated_index_flag = 1;
                }
                g_prof_cntx.content_index_array[g_prof_name_arr_p[g_prof_cntx.profile_module]->
                                                nvram_profile_name_array[i].content_index] = 1;
                g_prof_cntx.profile_count1++;
            }
        }

    }

    prof_count = g_prof_cntx.profile_count1;

    if (prof_count < NVRAM_PROFILE_MAX)
    {
        for (; prof_count != 0; prof_count--)
        {
            mmi_ucs2cpy((S8*) subMenuData[prof_count], (S8*) subMenuData[prof_count - 1]);
        }
     mmi_ucs2cpy((S8*) subMenuData[0], (S8*) GetString(STR_ID_PROF_HDLR_ADD_NEW));
        /* mmi_asc_to_ucs2((S8*) subMenuData[0], (S8*) "Add New"); */
    }
    return activated_index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_highlight_select_profile
 * DESCRIPTION
 *  This gets the highlighted index and stores it into global profile index
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prof_highlight_select_profile(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_prof_cntx.profile_index = (U8) index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_entry_view_selected_profile
 * DESCRIPTION
 *  It is the entry function for the view profile screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prof_entry_view_selected_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *input_buffer_p; /* added for inline edit history */
    U8 *gui_buffer_p;   /* Buffer holding history data */
    U16 input_buffer_size;
    U16 EditProfileIconList[MAX_INLINE_ITEM_EDIT_PROFILE_LIST] = {IMG_GLOBAL_L1, 0, IMG_GLOBAL_L2, 0,
        IMG_GLOBAL_L3, 0, IMG_GLOBAL_L4, 0,
        IMG_GLOBAL_L5, 0, IMG_GLOBAL_L6, 0
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_PROF_HDLR_VIEW_PROFILE, mmi_brw_prof_exit_view_selected_profile, NULL, NULL);

    InitializeCategory57Screen();

    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_PROF_HDLR_EDIT_PROFILE);
    input_buffer_p = GetCurrNInputBuffer(SCR_ID_PROF_HDLR_EDIT_PROFILE, &input_buffer_size);    /* added for inline edit history */

    mmi_brw_prof_selected_profile_default_fill_inline_struct();

    if (input_buffer_p != NULL)
    {
        SetCategory57Data(wgui_inline_items, MAX_INLINE_ITEM_EDIT_PROFILE_LIST, input_buffer_p);
    }

    ShowCategory57Screen(
        STR_ID_PROF_HDLR_VIEW_PROFILE,
        /* STR_ID_PROF_HDLR_SELECT_PROF_CAPTION, */ GetRootTitleIcon(SERVICES_WAP_MENU_ID),
         0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        MAX_INLINE_ITEM_EDIT_PROFILE_LIST,
        EditProfileIconList,
        wgui_inline_items,
        0,
        gui_buffer_p);

    SetCategory57RightSoftkeyFunctions(NULL, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_entry_edit_selected_profile
 * DESCRIPTION
 *  It is the entry function for the edit profile screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prof_entry_edit_selected_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *input_buffer_p; /* added for inline edit history */
    U8 *gui_buffer_p;   /* Buffer holding history data */
    U16 input_buffer_size;
    U16 EditProfileIconList[MAX_INLINE_ITEM_EDIT_PROFILE_LIST] = {IMG_GLOBAL_L1, 0, IMG_GLOBAL_L2, 0,
        IMG_GLOBAL_L3, 0, IMG_GLOBAL_L4, 0,
        IMG_GLOBAL_L5, 0, IMG_GLOBAL_L6, 0
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_PROF_HDLR_EDIT_PROFILE, mmi_brw_prof_exit_edit_selected_profile, NULL, NULL);

    InitializeCategory57Screen();

    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_PROF_HDLR_EDIT_PROFILE);
    input_buffer_p = GetCurrNInputBuffer(SCR_ID_PROF_HDLR_EDIT_PROFILE, &input_buffer_size);    /* added for inline edit history */

    mmi_brw_prof_selected_profile_fill_inline_struct();

    if (input_buffer_p != NULL)
    {
        SetCategory57Data(wgui_inline_items, MAX_INLINE_ITEM_EDIT_PROFILE_LIST, input_buffer_p);
    }

    if ((GetInlineDoneFlag(gui_buffer_p) == 0) && (g_prof_done_flag == 0x01))
    {
        SetInlineDoneFlag(gui_buffer_p);
    }

    RegisterHighlightHandler(mmi_brw_prof_highlight_inline_item);

    ShowCategory57Screen(
        STR_ID_PROF_HDLR_EDIT_PROFILE,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID), /* modified by tk */
        STR_GLOBAL_EDIT,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        MAX_INLINE_ITEM_EDIT_PROFILE_LIST,
        EditProfileIconList,
        wgui_inline_items,
        0,
        gui_buffer_p);

    SetCategory57RightSoftkeyFunctions(mmi_brw_prof_save_selected_profile_changes, GoBackHistory);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_selected_profile_default_fill_inline_struct
 * DESCRIPTION
 *  This API handles the inline items in the edit profile screen ,like data account,username ,password,conn type.....
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prof_selected_profile_default_fill_inline_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 buffer_size = 0;
    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_prof_cntx.profile_display_p == NULL)
    {
        g_prof_cntx.profile_display_p = (profile_content_struct*) OslMalloc(sizeof(profile_content_struct));
    }

    SetInlineItemActivation((wgui_inline_items + BRW_PROF_NAME), KEY_LSK, KEY_EVENT_UP);
    SetInlineItemActivation((wgui_inline_items + BRW_PROF_HOMEPAGE), KEY_LSK, KEY_EVENT_UP);
    SetInlineItemActivation((wgui_inline_items + BRW_PROF_DATA_ACCOUNT), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemActivation((wgui_inline_items + BRW_PROF_CONN_TYPE), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemActivation((wgui_inline_items + BRW_PROF_USER_NAME), KEY_LSK, KEY_EVENT_UP);
    SetInlineItemActivation((wgui_inline_items + BRW_PROF_USER_PASSWORD), KEY_LSK, KEY_EVENT_UP);

    SetInlineItemCaption((wgui_inline_items + BRW_PROF_NAME_STR), (U8*) GetString(STR_ID_PROF_HDLR_RENAME_PROFILE));

    if (g_prof_cntx.profile_module == BRW_PROF_BROWSER_PROFILE)
    {
        SetInlineItemCaption((wgui_inline_items + BRW_PROF_HOMEPAGE_STR), (U8*) GetString(STR_ID_PROF_HDLR_HOMEPAGE));
    }
    else if (g_prof_cntx.profile_module == BRW_PROF_MMS_PROFILE)
    {
        SetInlineItemCaption((wgui_inline_items + BRW_PROF_HOMEPAGE_STR), (U8*) GetString(STR_ID_PROF_HDLR_MMSC_URL));
    }

    SetInlineItemCaption(
        (wgui_inline_items + BRW_PROF_DATA_ACCOUNT_STR),
        (U8*) GetString(STR_ID_PROF_HDLR_DATA_ACCOUNT));
    SetInlineItemCaption((wgui_inline_items + BRW_PROF_CONN_TYPE_STR), (U8*) GetString(STR_ID_PROF_HDLR_CONN_TYPE));
    SetInlineItemCaption((wgui_inline_items + BRW_PROF_USER_NAME_STR), (U8*) GetString(STR_ID_PROF_HDLR_USER_NAME));
    SetInlineItemCaption((wgui_inline_items + BRW_PROF_USER_PASSWORD_STR), (U8*) GetString(STR_ID_PROF_HDLR_PASSWORD));

    SetInlineItemDisplayOnly(
        (wgui_inline_items + BRW_PROF_DATA_ACCOUNT),
        (U8*) g_prof_cntx.profile_display_p->data_account_name);

    /* profile connection type */
    if ((g_prof_profile_content_p[g_prof_cntx.profile_module]->conn_type == BRW_PROF_CONN_TYPE_CONNECTION_OREINTED)
        || (g_prof_profile_content_p[g_prof_cntx.profile_module]->conn_type ==
            BRW_PROF_CONN_TYPE_CONNECTION_OREINTED_SECURE))
    {
        SetInlineItemDisplayOnly(
            (wgui_inline_items + BRW_PROF_CONN_TYPE),
            (U8*) GetString(STR_ID_PROF_HDLR_CONN_TYPE_WAP));
    }
    else if (g_prof_profile_content_p[g_prof_cntx.profile_module]->conn_type == BRW_PROF_CONN_TYPE_HTTP)
    {
        SetInlineItemDisplayOnly(
            (wgui_inline_items + BRW_PROF_CONN_TYPE),
            (U8*) GetString(STR_ID_PROF_HDLR_CONN_TYPE_HTTP));
    }
    /* profile name inline item */
    index = mmi_brw_prof_update_profile_index();

    if (g_prof_name_arr_p[g_prof_cntx.profile_module]->nvram_profile_name_array[index].dcs == BRW_PROF_DCS_ASCII)
    {
        mmi_asc_to_ucs2(
            (S8*) g_prof_cntx.profile_display_p->profile_name,
            (S8*) (g_prof_name_arr_p[g_prof_cntx.profile_module]->nvram_profile_name_array[index].profile_name));

    }
    else if (g_prof_name_arr_p[g_prof_cntx.profile_module]->nvram_profile_name_array[index].dcs == BRW_PROF_DCS_UCS)
    {
        mmi_ucs2cpy(
            (S8*) g_prof_cntx.profile_display_p->profile_name,
            (S8*) (g_prof_name_arr_p[g_prof_cntx.profile_module]->nvram_profile_name_array[index].profile_name));
    }

    SetInlineItemDisplayOnly((wgui_inline_items + BRW_PROF_NAME), (U8*) g_prof_cntx.profile_display_p->profile_name);

    /* profile homepage url inline item */
    mmi_asc_to_ucs2(
        (S8*) g_prof_cntx.profile_display_p->url,
        (S8*) (g_prof_profile_content_p[g_prof_cntx.profile_module]->url));

    SetInlineItemDisplayOnly((wgui_inline_items + BRW_PROF_HOMEPAGE), (U8*) g_prof_cntx.profile_display_p->url);
    /* profile username inline item */
    buffer_size = NVRAM_PROFILE_USERNAME_LEN;

    mmi_asc_to_ucs2(
        (S8*) g_prof_cntx.profile_display_p->username,
        (S8*) (g_prof_profile_content_p[g_prof_cntx.profile_module]->username));

    SetInlineItemDisplayOnly((wgui_inline_items + BRW_PROF_USER_NAME), (U8*) g_prof_cntx.profile_display_p->username);

    /* profile password inline item */
    mmi_asc_to_ucs2(
        (S8*) g_prof_cntx.profile_display_p->password,
        (S8*) (g_prof_profile_content_p[g_prof_cntx.profile_module]->password));

    SetInlineItemDisplayOnly(
        (wgui_inline_items + BRW_PROF_USER_PASSWORD),
        (U8*) g_prof_cntx.profile_display_p->password);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_selected_profile_fill_inline_struct
 * DESCRIPTION
 *  This API handles the inline items in the edit profile screen ,like data account,username ,password,conn type.....
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prof_selected_profile_fill_inline_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 buffer_size = 0;
    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_prof_cntx.profile_display_p == NULL)
    {
        g_prof_cntx.profile_display_p = (profile_content_struct*) OslMalloc(sizeof(profile_content_struct));
    }

    SetInlineItemActivation((wgui_inline_items + BRW_PROF_NAME), KEY_LSK, KEY_EVENT_UP);
    SetInlineItemActivation((wgui_inline_items + BRW_PROF_HOMEPAGE), KEY_LSK, KEY_EVENT_UP);
    SetInlineItemActivation((wgui_inline_items + BRW_PROF_DATA_ACCOUNT), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemActivation((wgui_inline_items + BRW_PROF_CONN_TYPE), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemActivation((wgui_inline_items + BRW_PROF_USER_NAME), KEY_LSK, KEY_EVENT_UP);
    SetInlineItemActivation((wgui_inline_items + BRW_PROF_USER_PASSWORD), KEY_LSK, KEY_EVENT_UP);

    SetInlineItemCaption((wgui_inline_items + BRW_PROF_NAME_STR), (U8*) GetString(STR_ID_PROF_HDLR_RENAME_PROFILE));

    if (g_prof_cntx.profile_module == BRW_PROF_BROWSER_PROFILE)
    {
        SetInlineItemCaption((wgui_inline_items + BRW_PROF_HOMEPAGE_STR), (U8*) GetString(STR_ID_PROF_HDLR_HOMEPAGE));
    }
    else if (g_prof_cntx.profile_module == BRW_PROF_MMS_PROFILE)
    {
        SetInlineItemCaption((wgui_inline_items + BRW_PROF_HOMEPAGE_STR), (U8*) GetString(STR_ID_PROF_HDLR_MMSC_URL));
    }

    SetInlineItemCaption(
        (wgui_inline_items + BRW_PROF_DATA_ACCOUNT_STR),
        (U8*) GetString(STR_ID_PROF_HDLR_DATA_ACCOUNT));
    SetInlineItemCaption((wgui_inline_items + BRW_PROF_CONN_TYPE_STR), (U8*) GetString(STR_ID_PROF_HDLR_CONN_TYPE));
    SetInlineItemCaption((wgui_inline_items + BRW_PROF_USER_NAME_STR), (U8*) GetString(STR_ID_PROF_HDLR_USER_NAME));
    SetInlineItemCaption((wgui_inline_items + BRW_PROF_USER_PASSWORD_STR), (U8*) GetString(STR_ID_PROF_HDLR_PASSWORD));

    SetInlineItemDisplayOnly(
        (wgui_inline_items + BRW_PROF_DATA_ACCOUNT),
        (U8*) g_prof_cntx.profile_display_p->data_account_name);

    /* profile connection type */
    if ((g_prof_profile_content_p[g_prof_cntx.profile_module]->conn_type == BRW_PROF_CONN_TYPE_CONNECTION_OREINTED)
        || (g_prof_profile_content_p[g_prof_cntx.profile_module]->conn_type ==
            BRW_PROF_CONN_TYPE_CONNECTION_OREINTED_SECURE))
    {
        SetInlineItemDisplayOnly(
            (wgui_inline_items + BRW_PROF_CONN_TYPE),
            (U8*) GetString(STR_ID_PROF_HDLR_CONN_TYPE_WAP));
    }
    else if (g_prof_profile_content_p[g_prof_cntx.profile_module]->conn_type == BRW_PROF_CONN_TYPE_HTTP)
    {
        SetInlineItemDisplayOnly(
            (wgui_inline_items + BRW_PROF_CONN_TYPE),
            (U8*) GetString(STR_ID_PROF_HDLR_CONN_TYPE_HTTP));
    }
    /* profile name inline item */
    buffer_size = NVRAM_PROFILE_NAME_LEN;
    if (g_prof_cntx.profile_index == 0 && g_prof_cntx.profile_count1 < NVRAM_PROFILE_MAX)
    {
        if (g_prof_cntx.profile_module == BRW_PROF_BROWSER_PROFILE)
        {
            mmi_asc_to_ucs2(
                (S8*) g_prof_cntx.profile_display_p->profile_name,
                (S8*) BRW_PROF_DEFAULT_WAP_PROFILE_NAME);
        }
        else if (g_prof_cntx.profile_module == BRW_PROF_MMS_PROFILE)
        {
            mmi_asc_to_ucs2(
                (S8*) g_prof_cntx.profile_display_p->profile_name,
                (S8*) BRW_PROF_DEFAULT_MMS_PROFILE_NAME);
        }
    }
    else
    {
        index = mmi_brw_prof_update_profile_index();
        if (g_prof_name_arr_p[g_prof_cntx.profile_module]->nvram_profile_name_array[index].dcs == BRW_PROF_DCS_ASCII)
        {
            mmi_asc_to_ucs2(
                (S8*) g_prof_cntx.profile_display_p->profile_name,
                (S8*) (g_prof_name_arr_p[g_prof_cntx.profile_module]->nvram_profile_name_array[index].profile_name));

        }
        else if (g_prof_name_arr_p[g_prof_cntx.profile_module]->nvram_profile_name_array[index].dcs == BRW_PROF_DCS_UCS)
        {
            mmi_ucs2cpy(
                (S8*) g_prof_cntx.profile_display_p->profile_name,
                (S8*) (g_prof_name_arr_p[g_prof_cntx.profile_module]->nvram_profile_name_array[index].profile_name));
        }
    }

    SetInlineItemFullScreenEdit(
        (wgui_inline_items + BRW_PROF_NAME),
        STR_ID_PROF_HDLR_RENAME_PROFILE,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        (U8*) g_prof_cntx.profile_display_p->profile_name,
        buffer_size,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ENCODING_BASED_LENGTH | INPUT_TYPE_ONE_LESS_CHARACTER);
    SetInlineFullScreenEditCustomFunction(
        wgui_inline_items + BRW_PROF_NAME,
        mmi_brw_prof_editable_profile_full_screen_edit);
    /* profile homepage url inline item */
    buffer_size = NVRAM_PROFILE_URL_LEN;
    mmi_asc_to_ucs2(
        (S8*) g_prof_cntx.profile_display_p->url,
        (S8*) (g_prof_profile_content_p[g_prof_cntx.profile_module]->url));
    SetInlineItemFullScreenEdit(
        (wgui_inline_items + BRW_PROF_HOMEPAGE),
        STR_ID_PROF_HDLR_HOMEPAGE,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        (U8*) g_prof_cntx.profile_display_p->url,
        buffer_size,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES);
    SetInlineFullScreenEditCustomFunction(
        wgui_inline_items + BRW_PROF_HOMEPAGE,
        mmi_brw_prof_editable_profile_full_screen_edit);
    /* profile username inline item */
    buffer_size = NVRAM_PROFILE_USERNAME_LEN;

    mmi_asc_to_ucs2(
        (S8*) g_prof_cntx.profile_display_p->username,
        (S8*) (g_prof_profile_content_p[g_prof_cntx.profile_module]->username));

    SetInlineItemFullScreenEdit(
        (wgui_inline_items + BRW_PROF_USER_NAME),
        STR_ID_PROF_HDLR_USER_NAME,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        (U8*) (g_prof_cntx.profile_display_p->username),
        buffer_size,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES);

    SetInlineFullScreenEditCustomFunction(
        wgui_inline_items + BRW_PROF_USER_NAME,
        mmi_brw_prof_editable_profile_full_screen_edit);
    /* profile password inline item */
    buffer_size = NVRAM_PROFILE_PASSWORD_LEN;
    mmi_asc_to_ucs2(
        (S8*) g_prof_cntx.profile_display_p->password,
        (S8*) (g_prof_profile_content_p[g_prof_cntx.profile_module]->password));

    SetInlineItemFullScreenEdit(
        (wgui_inline_items + BRW_PROF_USER_PASSWORD),
        STR_ID_PROF_HDLR_PASSWORD,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        (U8*) (g_prof_cntx.profile_display_p->password),
        buffer_size,
        INPUT_TYPE_ALPHANUMERIC_PASSWORD | INPUT_TYPE_USE_ONLY_ENGLISH_MODES);

    SetInlineFullScreenEditCustomFunction(
        wgui_inline_items + BRW_PROF_USER_PASSWORD,
        mmi_brw_prof_editable_profile_full_screen_edit);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_update_profile_index
 * DESCRIPTION
 *  This API decrement the index by 1 if "Add New" is visible at profile list (means if number of profiles in the list 
	is less than NVRAM_MAX_PROFILE).
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_brw_prof_update_profile_index(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index = g_prof_cntx.profile_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_prof_cntx.profile_count1 && g_prof_cntx.profile_count1 < NVRAM_PROFILE_MAX && g_prof_cntx.profile_index)
    {
        index--;
    }
    return index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_highlight_inline_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prof_highlight_inline_item(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == BRW_PROF_DATA_ACCOUNT)
    {
        ChangeLeftSoftkey(STR_GLOBAL_SELECT, 0);
		/*if (g_prof_cntx.profile_module == BRW_PROF_BROWSER_PROFILE)
		{
        SetLeftSoftkeyFunction(mmi_brw_prof_entry_data_account_type, KEY_EVENT_UP);
		}
		else if (g_prof_cntx.profile_module == BRW_PROF_MMS_PROFILE)
		{
			SetLeftSoftkeyFunction(mmi_brw_prof_entry_data_account_type_bearers, KEY_EVENT_UP);
		}*/

		SetLeftSoftkeyFunction(mmi_brw_prof_entry_data_account_type_bearers, KEY_EVENT_UP);

    }
    else if (index == BRW_PROF_CONN_TYPE)
    {
        ChangeLeftSoftkey(STR_GLOBAL_SELECT, 0);
        SetLeftSoftkeyFunction(mmi_brw_prof_show_connection_type_options, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_entry_data_account_type
 * DESCRIPTION
 *  It shows the primary and secondary data account
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prof_entry_data_account_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer_p;
    S32 num_of_item = 0;
    S32 count;
    U16 nStrItemList[MAX_CONN_TYPE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_PROF_HDLR_DATA_ACCOUNT, NULL, mmi_brw_prof_entry_data_account_type, NULL);

    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_PROF_HDLR_DATA_ACCOUNT);

    num_of_item = GetNumOfChild(MENU_ID_PROF_DATA_ACCOUNT);
    GetSequenceStringIds(MENU_ID_PROF_DATA_ACCOUNT, nStrItemList);
    SetParentHandler(MENU_ID_PROF_DATA_ACCOUNT);

    RegisterHighlightHandler(mmi_brw_prof_data_account_type_highlight_hdlr);

    for (count = 0; count < num_of_item; count++)
    {
        memset((S8*) subMenuDataPtrs[count], 0, MAX_SUB_MENU_SIZE);
        mmi_ucs2ncpy((S8*) subMenuDataPtrs[count], (S8*) GetString(nStrItemList[count]), MAX_SUBMENU_CHARACTERS);
    }
    /* conn_type_index = mmi_brw_prof_get_highlighted_menu_item(); */

    ShowCategory353Screen(
        (U8*) GetString(STR_ID_PROF_HDLR_DATA_ACCOUNT),
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

    SetLeftSoftkeyFunction(mmi_brw_prof_entry_data_account_type_bearers, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_entry_data_account_type_bearers
 * DESCRIPTION
 *  It shows the bearer (GSM ,GPRS & WIFI) as per the data account type
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prof_entry_data_account_type_bearers(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer_p;

    /* S32 num_of_item = 0; */
    S32 count = 0;
  //  S8 profile_name_string[(NVRAM_PROFILE_NAME_LEN + 1) * ENCODING_LENGTH];
	U16 string_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef PROF_GSM_SUPPORT

    memset((S8*) subMenuDataPtrs[count], 0, MAX_SUB_MENU_SIZE);
    mmi_ucs2ncpy(
        (S8*) subMenuDataPtrs[count++],
        (S8*) GetString(STR_ID_PROF_HDLR_DATA_ACCOUNT_BEARER_GSM),
        MAX_SUBMENU_CHARACTERS);
#endif /* PROF_GSM_SUPPORT */ 

#ifdef PROF_GPRS_SUPPORT

    memset((S8*) subMenuDataPtrs[count], 0, MAX_SUB_MENU_SIZE);
    mmi_ucs2ncpy(
        (S8*) subMenuDataPtrs[count++],
        (S8*) GetString(STR_ID_PROF_HDLR_DATA_ACCOUNT_BEARER_GPRS),
        MAX_SUBMENU_CHARACTERS);
#endif /* PROF_GPRS_SUPPORT */ 

#ifdef __WIFI_SUPPORT__
if (g_prof_cntx.profile_module == BRW_PROF_BROWSER_PROFILE)
{
    memset((S8*) subMenuDataPtrs[count], 0, MAX_SUB_MENU_SIZE);
    mmi_ucs2ncpy(
        (S8*) subMenuDataPtrs[count++],
        (S8*) GetString(STR_ID_PROF_HDLR_DATA_ACCOUNT_BEARER_WIFI),
        MAX_SUBMENU_CHARACTERS);
}
#endif /* __WIFI_SUPPORT__ */ 

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
    #ifdef PROF_NONE_SUPPORT
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* PROF_NONE_SUPPORT */ 
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
#endif

	string_id = STR_ID_PROF_HDLR_DATA_ACCOUNT;

    EntryNewScreen(SCR_ID_PROF_HDLR_DATA_ACCOUNT_TYPE, NULL, mmi_brw_prof_entry_data_account_type_bearers, NULL);

    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_PROF_HDLR_DATA_ACCOUNT_TYPE);

    /* if (g_prof_data_account_index == 0)
       {
       num_of_item = GetNumOfChild(MENU_ID_PROF_DATA_ACCOUNT_PRIMARY);
       GetSequenceStringIds((MENU_ID_PROF_DATA_ACCOUNT_PRIMARY, nStrItemList);
       SetParentHandler((MENU_ID_PROF_DATA_ACCOUNT_PRIMARY);
       mmi_asc_to_ucs2(
       (S8*) profile_name_string,
       (S8*) "Primary");
       
       }
       else
       {
       num_of_item = GetNumOfChild(MENU_ID_PROF_DATA_ACCOUNT_SECONDARY);
       GetSequenceStringIds(MENU_ID_PROF_DATA_ACCOUNT_SECONDARY, nStrItemList);
       SetParentHandler(MENU_ID_PROF_DATA_ACCOUNT_SECONDARY);
       mmi_asc_to_ucs2(
       (S8*) profile_name_string,
       (S8*) "Secondary");
       } */

    RegisterHighlightHandler(mmi_brw_prof_data_account_type_bearers_highlight_hdlr);

    /* for (count = 0; count < num_of_item; count++)
       {
       memset((S8*) subMenuDataPtrs[count], 0, MAX_SUB_MENU_SIZE);
       mmi_ucs2ncpy((S8*) subMenuDataPtrs[count], (S8*) GetString(nStrItemList[count]), MAX_SUBMENU_CHARACTERS);
       } */
    /* conn_type_index = mmi_brw_prof_get_highlighted_menu_item(); */

    ShowCategory353Screen(
		(U8*)GetString(string_id),
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
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
        gui_buffer_p);

    /* SetLeftSoftkeyFunction(mmi_brw_prof_show_data_account_bearer_list, KEY_EVENT_UP); */

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_show_csd_bearer_list
 * DESCRIPTION
 *  It calls the data account API to show CSD bearer list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prof_show_csd_bearer_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_dtcnt_select_account(mmi_brw_prof_callback, SERVICES_WAP_MENU_ID, DATA_ACCOUNT_BEARER_CSD);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_show_gprs_bearer_list
 * DESCRIPTION
 *  It calls the data account API to show GPRS bearer list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prof_show_gprs_bearer_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_dtcnt_select_account(mmi_brw_prof_callback, SERVICES_WAP_MENU_ID, DATA_ACCOUNT_BEARER_GPRS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_show_wifi_bearer_list
 * DESCRIPTION
 * It calls the data account API to show Wifi bearer list. 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prof_show_wifi_bearer_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_dtcnt_select_account(mmi_brw_prof_callback, SERVICES_WAP_MENU_ID, DATA_ACCOUNT_BEARER_WIFI);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_select_none_bearer_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prof_select_none_bearer_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_to_ucs2((S8*) g_prof_cntx.profile_display_p->data_account_name_secondary, (S8*) "");
    g_prof_profile_content_p[g_prof_cntx.profile_module]->data_account_secondary_id = -1;

    mmi_brw_prof_concatenate_primary_secondary_data_account();
    g_prof_done_flag = 0x01;
    DeleteUptoScrID(SCR_ID_PROF_HDLR_EDIT_PROFILE);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prof_callback(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_prof_cntx.profile_display_p == NULL)
    {
        g_prof_cntx.profile_display_p = (profile_content_struct*) OslMalloc(sizeof(profile_content_struct));
    }
    g_prof_cntx.profile_display_p->data_account = (U8) index;

    if (g_prof_data_account_index == 0)
    {
        g_prof_profile_content_p[g_prof_cntx.profile_module]->data_account_primary_id =
            g_prof_cntx.profile_display_p->data_account;

        mmi_dtcnt_get_account_name(
            g_prof_cntx.profile_display_p->data_account,
            (S8*) g_prof_cntx.profile_display_p->data_account_name_primary,
            MAX_DATA_ACCOUNT_NAME_LEN);
    }
    else
    {
        g_prof_profile_content_p[g_prof_cntx.profile_module]->data_account_secondary_id =
            g_prof_cntx.profile_display_p->data_account;

        mmi_dtcnt_get_account_name(
            g_prof_cntx.profile_display_p->data_account,
            (S8*) g_prof_cntx.profile_display_p->data_account_name_secondary,
            MAX_DATA_ACCOUNT_NAME_LEN);
    }

    mmi_brw_prof_concatenate_primary_secondary_data_account();
    g_prof_done_flag = 0x01;
    DeleteUptoScrID(SCR_ID_PROF_HDLR_EDIT_PROFILE);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_pre_entry_data_account
 * DESCRIPTION
 *  It is pre entry call to data account.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prof_pre_entry_data_account(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_prof_cntx.profile_display_p == NULL)
    {
        g_prof_cntx.profile_display_p = (profile_content_struct*) OslMalloc(sizeof(profile_content_struct));
    }

    mmi_brw_prof_get_data_account_name();

    mmi_brw_prof_concatenate_primary_secondary_data_account();
    index = mmi_brw_prof_update_profile_index();

    if (g_prof_cntx.profile_index == 0 && g_prof_cntx.profile_count1 < NVRAM_PROFILE_MAX)
    {
        mmi_brw_prof_entry_edit_selected_profile();
    }
    else
    {
        if (g_prof_name_arr_p[g_prof_cntx.profile_module]->nvram_profile_name_array[index].permission_bits
            == BRW_PROF_READ_WRITE)
        {
            mmi_brw_prof_entry_edit_selected_profile();
        }
        else if (g_prof_name_arr_p[g_prof_cntx.profile_module]->nvram_profile_name_array[index].permission_bits
                 == BRW_PROF_READ_ONLY)
        {
            mmi_brw_prof_entry_view_selected_profile();
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_get_data_account_name
 * DESCRIPTION
 *  It gives the name of selected data account from primary or secondary.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prof_get_data_account_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_dtcnt_get_account_name(
        g_prof_profile_content_p[g_prof_cntx.profile_module]->data_account_primary_id,
        (S8*) g_prof_cntx.profile_display_p->data_account_name_primary,
        MAX_DATA_ACCOUNT_NAME_LEN);

    if (g_prof_profile_content_p[g_prof_cntx.profile_module]->data_account_secondary_id == (U8) - 1)
    {
        mmi_asc_to_ucs2((S8*) g_prof_cntx.profile_display_p->data_account_name_secondary, (S8*) "");
    }
    else
    {
        mmi_dtcnt_get_account_name(
            g_prof_profile_content_p[g_prof_cntx.profile_module]->data_account_secondary_id,
            (S8*) g_prof_cntx.profile_display_p->data_account_name_secondary,
            MAX_DATA_ACCOUNT_NAME_LEN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_concatenate_primary_secondary_data_account
 * DESCRIPTION
 *  It gives the data account name by concating the primary and secondary data account name.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prof_concatenate_primary_secondary_data_account(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 temp[4];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy(
        (S8*) g_prof_cntx.profile_display_p->data_account_name,
        (S8*) g_prof_cntx.profile_display_p->data_account_name_primary);

    mmi_asc_to_ucs2((S8*) temp, "\\");
    if (g_prof_cntx.profile_display_p->data_account_name_secondary[0] != 0)
    {
        mmi_ucs2cat((S8*) g_prof_cntx.profile_display_p->data_account_name, (S8*) temp);

        mmi_ucs2cat(
            (S8*) g_prof_cntx.profile_display_p->data_account_name,
            (S8*) g_prof_cntx.profile_display_p->data_account_name_secondary);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_show_connection_type_options
 * DESCRIPTION
 *  It shows the various connection type menu item available
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prof_show_connection_type_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer_p;
    S32 num_of_item = 0;
    S32 count;
    U32 conn_type_index;
    U16 nStrItemList[MAX_CONN_TYPE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_PROF_HDLR_CONN_TYPE, NULL, mmi_brw_prof_show_connection_type_options, NULL);

    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_PROF_HDLR_CONN_TYPE);

    num_of_item = GetNumOfChild(MENU_ID_PROF_CONNECTION_TYPE);
    GetSequenceStringIds(MENU_ID_PROF_CONNECTION_TYPE, nStrItemList);
    SetParentHandler(MENU_ID_PROF_CONNECTION_TYPE);

    RegisterHighlightHandler(mmi_brw_prof_conn_type_highlight_hdlr);

    if (g_prof_profile_content_p[g_prof_cntx.profile_module]->conn_type ==
        BRW_PROF_CONN_TYPE_CONNECTION_OREINTED_SECURE ||
		  (g_prof_profile_content_p[g_prof_cntx.profile_module]->conn_type == BRW_PROF_CONN_TYPE_HTTP && 
		  g_prof_profile_content_p[g_prof_cntx.profile_module]->proxy_port == 443))
    {
        g_prof_cntx.profile_display_p->security_opt_index = 1;
    }
    else
    {
        g_prof_cntx.profile_display_p->security_opt_index = 0;
    }
    for (count = 0; count < num_of_item; count++)
    {
        memset((S8*) subMenuDataPtrs[count], 0, MAX_SUB_MENU_SIZE);
        mmi_ucs2ncpy((S8*) subMenuDataPtrs[count], (S8*) GetString(nStrItemList[count]), MAX_SUBMENU_CHARACTERS);
    }

    g_prof_connection_type = mmi_brw_prof_get_highlighted_menu_item();
    ShowCategory36Screen(
        STR_ID_PROF_HDLR_CONN_TYPE,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_of_item,
        (U8 **) subMenuDataPtrs,
        (U16) g_prof_connection_type,
        gui_buffer_p);

    SetLeftSoftkeyFunction(mmi_brw_prof_entry_edit_connection_type_details, KEY_EVENT_UP);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_entry_edit_connection_type_details
 * DESCRIPTION
 *  This is the entry fucntion for connection type details inline item screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prof_entry_edit_connection_type_details(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *input_buffer_p; /* added for inline edit history */
    U8 *gui_buffer_p;   /* Buffer holding history data */
    U16 input_buffer_size;
    U16 EditConnTypeIconList[MAX_INLINE_ITEM_EDIT_CONN_TYPE_LIST] = {IMG_GLOBAL_L1, 0, IMG_GLOBAL_L2, 0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_PROF_HDLR_EDIT_CONN_TYPE, mmi_brw_prof_exit_edit_connection_type_details, NULL, NULL);

    InitializeCategory57Screen();

    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_PROF_HDLR_EDIT_CONN_TYPE);
    input_buffer_p = GetCurrNInputBuffer(SCR_ID_PROF_HDLR_EDIT_CONN_TYPE, &input_buffer_size);  /* added for inline edit history */

    mmi_brw_prof_edit_conn_type_fill_inline_struct();

    if (input_buffer_p != NULL)
    {
        if (g_prof_conn_index == BRW_PROF_MENU_HTTP)
        {
            SetCategory57Data(wgui_inline_items, MAX_INLINE_ITEM_EDIT_CONN_TYPE_LIST, input_buffer_p);
        }
        else
        {
            SetCategory57Data(wgui_inline_items, 2, input_buffer_p);
        }
    }
    if (GetInlineDoneFlag(gui_buffer_p) == 0)
    {
        SetInlineDoneFlag(gui_buffer_p);
    }
  
	if (g_prof_conn_index != g_prof_connection_type)
	{
		set_wgui_inline_list_menu_status(1);
	}
    //NOTE : this thing is if we want to update the connection type on the change in highlight...presently not needed
    //      RegisterHighlightHandler(mmi_brw_prof_highlight_inline_item_conn_type);

    g_prof_done_flag = 0x01;

    ShowCategory57Screen(
        STR_GLOBAL_EDIT,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_EDIT,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        MAX_INLINE_ITEM_EDIT_CONN_TYPE_LIST,
        EditConnTypeIconList,
        wgui_inline_items,
        0,
        gui_buffer_p);

    SetCategory57RightSoftkeyFunctions(mmi_brw_prof_save_connection_type_changes, GoBackHistory);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_save_connection_type_changes
 * DESCRIPTION
 *  This API saves the changes done with the connection type like port & IP
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prof_save_connection_type_changes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 ip_value[4];
    U32 ip_sum = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ip_value[0] = (U8) gui_atoi((UI_string_type) g_prof_cntx.profile_display_p->IP1);
    ip_value[1] = (U8) gui_atoi((UI_string_type) g_prof_cntx.profile_display_p->IP2);
    ip_value[2] = (U8) gui_atoi((UI_string_type) g_prof_cntx.profile_display_p->IP3);
    ip_value[3] = (U8) gui_atoi((UI_string_type) g_prof_cntx.profile_display_p->IP4);

    ip_sum = ip_value[0] + ip_value[1] + ip_value[2] + ip_value[3];

    if ((ip_sum == 0x00) && ((g_prof_conn_index == BRW_PROF_MENU_CONNECTION_OREINTED)))
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
        U32 port = 0;
        port = (U32) gui_atoi((UI_string_type) g_prof_cntx.profile_display_p->proxy_port);

        if (!mmi_ucs2strlen((S8*) g_prof_cntx.profile_display_p->proxy_port))
        {
            DisplayPopup(
                (PU8) GetString(STR_ID_PROF_HDLR_INVALID_INPUT),
                IMG_GLOBAL_ERROR,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                ERROR_TONE);
        }
        else if (port >= BRW_PROF_USHORT_MAX)
        {
            DisplayPopup(
                (PU8) GetString(STR_ID_PROF_HDLR_INVALID_INPUT),
                IMG_GLOBAL_ERROR,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                ERROR_TONE);
        }
        else
        {
			if (g_prof_conn_index == BRW_PROF_MENU_CONNECTION_OREINTED)
			{
				if (g_prof_cntx.profile_display_p->security_opt_index == 1)
				{
					gui_itoa(
					(S32) 9203,
					(U16*) g_prof_cntx.profile_display_p->proxy_port,
					10);

					port = 9203;
				}
				else if (g_prof_cntx.profile_display_p->security_opt_index == 0)
				{
					gui_itoa(
					(S32) 9201,
					(U16*) g_prof_cntx.profile_display_p->proxy_port,
					10);

					port = 9201;
				}
			}
            g_prof_profile_content_p[g_prof_cntx.profile_module]->proxy_ip[0] = ip_value[0];
            g_prof_profile_content_p[g_prof_cntx.profile_module]->proxy_ip[1] = ip_value[1];
            g_prof_profile_content_p[g_prof_cntx.profile_module]->proxy_ip[2] = ip_value[2];
            g_prof_profile_content_p[g_prof_cntx.profile_module]->proxy_ip[3] = ip_value[3];

            g_prof_profile_content_p[g_prof_cntx.profile_module]->proxy_port = (U16) port;

            mmi_brw_prof_update_connection_type();
            GoBackHistory();

        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_update_connection_type
 * DESCRIPTION
 *  This API updates the connection type in the edit profile screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prof_update_connection_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_prof_highlight_inline_item_conn_type(g_prof_conn_index);
    DeleteNHistory(1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_get_highlighted_menu_item
 * DESCRIPTION
 *  It gives the higlighted connection type menu item
 * PARAMETERS
 *  void
 * RETURNS
 *  U8 connection type highlighted
 *****************************************************************************/
U8 mmi_brw_prof_get_highlighted_menu_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_prof_profile_content_p[g_prof_cntx.profile_module]->conn_type == BRW_PROF_CONN_TYPE_CONNECTION_OREINTED)
        || (g_prof_profile_content_p[g_prof_cntx.profile_module]->conn_type ==
            BRW_PROF_CONN_TYPE_CONNECTION_OREINTED_SECURE))
    {
        return (U8) BRW_PROF_MENU_CONNECTION_OREINTED;
    }
    else if (g_prof_profile_content_p[g_prof_cntx.profile_module]->conn_type == BRW_PROF_CONN_TYPE_HTTP)
    {
        return (U8) BRW_PROF_MENU_HTTP;
    }

    return (U8) BRW_PROF_MENU_CONNECTION_OREINTED;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_data_account_type_highlight_hdlr
 * DESCRIPTION
 *  This API is to update the global connection type index
 * PARAMETERS
 *  index       [IN]        Highlighted index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prof_data_account_type_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_prof_data_account_index = (U8) index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_data_account_type_bearers_highlight_hdlr
 * DESCRIPTION
 *  This API is to update the global data account type index
 * PARAMETERS
 *  index       [IN]        Highlighted index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prof_data_account_type_bearers_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (index)
    {
    #ifdef PROF_GSM_SUPPORT
            SELECT_BEARER(bearer_gsm, mmi_brw_prof_show_csd_bearer_list);
    #endif 

    #ifdef PROF_GPRS_SUPPORT
            SELECT_BEARER(bearer_gprs, mmi_brw_prof_show_gprs_bearer_list);
    #endif 

    #ifdef __WIFI_SUPPORT__
            SELECT_BEARER(bearer_wifi, mmi_brw_prof_show_wifi_bearer_list);
    #endif 

    #ifdef PROF_NONE_SUPPORT
            SELECT_BEARER(bearer_none, mmi_brw_prof_select_none_bearer_list);
    #endif 
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_conn_type_highlight_hdlr
 * DESCRIPTION
 *  This API is to update the global connection type index
 * PARAMETERS
 *  index       [IN]        Highlighted index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prof_conn_type_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_prof_conn_index = (U8) index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_edit_conn_type_fill_inline_struct
 * DESCRIPTION
 *  This API handles the connection type inline edit screen,containing inline items like IP ,proxy port
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prof_edit_conn_type_fill_inline_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 buffer_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_prof_cntx.profile_display_p == NULL)
    {
        g_prof_cntx.profile_display_p = (profile_content_struct*) OslMalloc(sizeof(profile_content_struct));
    }
    if (g_prof_conn_index == BRW_PROF_MENU_HTTP)
    {
        SetInlineItemActivation(
            (wgui_inline_items + BRW_PROF_CONN_TYPE_IP_ADDRESS),
            INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
            0);
        SetInlineItemCaption(
            (wgui_inline_items + BRW_PROF_CONN_TYPE_IP_ADDRESS_STR),
            (U8*) GetString(STR_ID_PROF_HDLR_PROXY_ADDRESS));
        SetInlineItemActivation(
            (wgui_inline_items + BRW_PROF_CONN_TYPE_SECURITY),
            INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
            0);
        SetInlineItemCaption(
            (wgui_inline_items + BRW_PROF_CONN_TYPE_SECURITY_STR),
            (U8*) GetString(STR_ID_PROF_HDLR_PORT));
        /* dara NOTE ..for http ..its port in place of security */

        buffer_size = 6;
        SetInlineItemTextEdit(
            (wgui_inline_items + BRW_PROF_CONN_TYPE_SECURITY),
            (U8*) (g_prof_cntx.profile_display_p->proxy_port),
            buffer_size,
            INPUT_TYPE_NUMERIC);

        gui_itoa(
            (S32) g_prof_profile_content_p[g_prof_cntx.profile_module]->proxy_port,
            (U16*) g_prof_cntx.profile_display_p->proxy_port,
            10);

    }
    else
    {
        SetInlineItemActivation(
            (wgui_inline_items + BRW_PROF_CONN_TYPE_IP_ADDRESS),
            INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
            0);
        SetInlineItemCaption(
            (wgui_inline_items + BRW_PROF_CONN_TYPE_IP_ADDRESS_STR),
            (U8*) GetString(STR_ID_PROF_HDLR_IP_ADDRESS));

        // #if defined (WAP_SEC_SUPPORT) && defined (JATAAYU_SUPPORT)

        SetInlineItemActivation(
            (wgui_inline_items + BRW_PROF_CONN_TYPE_SECURITY),
            INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
            0);
        SetInlineItemCaption(
            (wgui_inline_items + BRW_PROF_CONN_TYPE_SECURITY_STR),
            (U8*) GetString(STR_ID_PROF_HDLR_SECURITY));

        g_prof_cntx.profile_display_p->security_option[0] = (U8*) GetString(STR_ID_PROF_HDLR_OFF);
        g_prof_cntx.profile_display_p->security_option[1] = (U8*) GetString(STR_ID_PROF_HDLR_ON);
        SetInlineItemSelect(
            (wgui_inline_items + BRW_PROF_CONN_TYPE_SECURITY),
            (S32) 0x02,
            (U8 **) g_prof_cntx.profile_display_p->security_option,
            (S32*) (&(g_prof_cntx.profile_display_p->security_opt_index)));
        // #endif /* defined (WAP_SEC_SUPPORT) && defined (JATAAYU_SUPPORT) */

        gui_itoa(
            (S32) g_prof_profile_content_p[g_prof_cntx.profile_module]->proxy_port,
            (U16*) g_prof_cntx.profile_display_p->proxy_port,
            10);

    }

    ReturnThreeDigitString(
        g_prof_cntx.profile_display_p->IP1,
        (U8) g_prof_profile_content_p[g_prof_cntx.profile_module]->proxy_ip[0]);
    ReturnThreeDigitString(
        g_prof_cntx.profile_display_p->IP2,
        (U8) g_prof_profile_content_p[g_prof_cntx.profile_module]->proxy_ip[1]);
    ReturnThreeDigitString(
        g_prof_cntx.profile_display_p->IP3,
        (U8) g_prof_profile_content_p[g_prof_cntx.profile_module]->proxy_ip[2]);
    ReturnThreeDigitString(
        g_prof_cntx.profile_display_p->IP4,
        (U8) g_prof_profile_content_p[g_prof_cntx.profile_module]->proxy_ip[3]);

    SetInlineItemIP4(
        (wgui_inline_items + BRW_PROF_CONN_TYPE_IP_ADDRESS),
        (U8*) g_prof_cntx.profile_display_p->IP1,
        (U8*) g_prof_cntx.profile_display_p->IP2,
        (U8*) g_prof_cntx.profile_display_p->IP3,
        (U8*) g_prof_cntx.profile_display_p->IP4,
        PreparedIPAddressString);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_highlight_inline_item_conn_type
 * DESCRIPTION
 *  This API updates the Browser & MMS proifle structs based  on the highlighted index
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prof_highlight_inline_item_conn_type(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == BRW_PROF_MENU_CONNECTION_OREINTED)
    {

        if (mmi_ucs2cmp
            ((S8*) g_prof_cntx.profile_display_p->security_option[g_prof_cntx.profile_display_p->security_opt_index],
             (S8*) GetString(STR_ID_PROF_HDLR_ON)) == 0)
        {
            g_prof_profile_content_p[g_prof_cntx.profile_module]->conn_type =
                BRW_PROF_CONN_TYPE_CONNECTION_OREINTED_SECURE;
            g_prof_name_arr_p[g_prof_cntx.profile_module]->nvram_profile_name_array[g_prof_cntx.profile_index].
                conn_type = BRW_PROF_CONN_TYPE_CONNECTION_OREINTED_SECURE;

        }
        else
        {
            g_prof_profile_content_p[g_prof_cntx.profile_module]->conn_type = BRW_PROF_CONN_TYPE_CONNECTION_OREINTED;
            g_prof_name_arr_p[g_prof_cntx.profile_module]->nvram_profile_name_array[g_prof_cntx.profile_index].
                conn_type = BRW_PROF_CONN_TYPE_CONNECTION_OREINTED;
        }

    }
    else if (index == BRW_PROF_MENU_HTTP)
    {

        g_prof_profile_content_p[g_prof_cntx.profile_module]->conn_type = BRW_PROF_CONN_TYPE_HTTP;
        g_prof_name_arr_p[g_prof_cntx.profile_module]->nvram_profile_name_array[g_prof_cntx.profile_index].conn_type =
            BRW_PROF_CONN_TYPE_HTTP;

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_exit_edit_connection_type_details
 * DESCRIPTION
 *  It is te exit handler for the edit connection type screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prof_exit_edit_connection_type_details(void)
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
    h.scrnID = SCR_ID_PROF_HDLR_EDIT_CONN_TYPE;
    CloseCategory57Screen();
    h.entryFuncPtr = mmi_brw_prof_entry_edit_connection_type_details;
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & nHistory);
    GetCategory57History(h.guiBuffer);
    input_buffer_size = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) h.inputBuffer);
    AddNHistory(h, input_buffer_size);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_exit_view_selected_profile
 * DESCRIPTION
 *  exit handler for edit profile screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prof_exit_view_selected_profile(void)
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
    h.scrnID = SCR_ID_PROF_HDLR_VIEW_PROFILE;
    CloseCategory57Screen();
    h.entryFuncPtr = mmi_brw_prof_entry_view_selected_profile;
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & nHistory);
    GetCategory57History(h.guiBuffer);
    input_buffer_size = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) h.inputBuffer);
    AddNHistory(h, input_buffer_size);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_exit_edit_selected_profile
 * DESCRIPTION
 *  exit handler for edit profile screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prof_exit_edit_selected_profile(void)
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
    h.scrnID = SCR_ID_PROF_HDLR_EDIT_PROFILE;
    CloseCategory57Screen();
    h.entryFuncPtr = mmi_brw_prof_entry_edit_selected_profile;
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & nHistory);
    GetCategory57History(h.guiBuffer);
    input_buffer_size = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) h.inputBuffer);
    AddNHistory(h, input_buffer_size);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_editable_profile_full_screen_edit
 * DESCRIPTION
 *  It is the inline full screen edit custom function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prof_editable_profile_full_screen_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_prof_update_profile_inline_values();
    ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
    SetInputMethodAndDoneCaptionIcon(GetRootTitleIcon(SERVICES_WAP_MENU_ID));
    SetLeftSoftkeyFunction(EntryScrForInputMethodAndDone, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_update_profile_inline_values
 * DESCRIPTION
 *  It fills the global profile structure based on the inline edit displayable data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prof_update_profile_inline_values(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2_to_asc(
        (S8*) (g_prof_profile_content_p[g_prof_cntx.profile_module]->password),
        (S8*) (g_prof_cntx.profile_display_p->password));

    /* Other values can be updated later like username */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_save_selected_profile_changes
 * DESCRIPTION
 *  This is the entry function for the save edit profile changes confirmation screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prof_save_selected_profile_changes(void)
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

    SetLeftSoftkeyFunction(mmi_brw_prof_editable_profile_save_changes, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_brw_prof_editable_profile_reject_changes, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_editable_profile_reject_changes
 * DESCRIPTION
 *  It handles the Press of RSK(NO) on the save changes screen for the editable profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prof_editable_profile_reject_changes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteNHistory(1);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_editable_profile_save_changes
 * DESCRIPTION
 *  It invokes the storage into the NVRAM for the changes done in the profile struct (Browser ,MMS)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prof_editable_profile_save_changes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

  //  MMI_BOOL IsValidURL;
	 S16 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mmi_brw_validate_url((PU8) g_prof_cntx.profile_display_p->url);
    if (result >= 0)
    {

        if (g_prof_cntx.profile_count1 < NVRAM_PROFILE_MAX && g_prof_cntx.profile_index == 0)
        {
            if (g_prof_profile_content_p[g_prof_cntx.profile_module]->data_account_primary_id ==
                g_prof_profile_content_p[g_prof_cntx.profile_module]->data_account_secondary_id)
            {
                DisplayPopup(
                    (PU8) GetString(STR_ID_PROF_HDLR_DATA_ACCOUNT_ERROR),
                    IMG_GLOBAL_ERROR,
                    1,
                    1000,
                    ERROR_TONE);
            }
            else
            {
                mmi_brw_prof_nvram_add_new_profile();
            }
        }
        else
        {
            if (g_prof_profile_content_p[g_prof_cntx.profile_module]->data_account_primary_id ==
                g_prof_profile_content_p[g_prof_cntx.profile_module]->data_account_secondary_id)
            {
                DisplayPopup(
                    (PU8) GetString(STR_ID_PROF_HDLR_DATA_ACCOUNT_ERROR),
                    IMG_GLOBAL_ERROR,
                    1,
                    1000,
                    ERROR_TONE);
            }
            else
            {
                U8 index;

                index = mmi_brw_prof_update_profile_index();
					 if (index == g_prof_cntx.actived_profile_content_index[g_prof_cntx.profile_module])
                {
						g_prof_cntx.active_profile_modified = TRUE;
					 }
                mmi_brw_prof_update_nvram_profile();

                if (index == g_prof_cntx.actived_profile_content_index[g_prof_cntx.profile_module])
                {
                    mmi_brw_prof_update_activated_profile_data();
                }

            }
        }

    }
    else
    {
        DisplayPopup((PU8) GetString(STR_ID_PROF_HDLR_INVALID_URL_ERROR), IMG_GLOBAL_ERROR, 1, 1000, ERROR_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_update_activated_profile_data
 * DESCRIPTION
 *  It updates activated profile data
 * PARAMETERS
 *  void
 * RETURNS
 *  g_prof_activated_wap_profile(?)
 *****************************************************************************/
void mmi_brw_prof_update_activated_profile_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    strcpy(
        (char*)g_prof_activated_profile_content[g_prof_cntx.profile_module]->url,
        (char*)g_prof_profile_content_p[g_prof_cntx.profile_module]->url);

    strcpy(
        (char*)g_prof_activated_profile_content[g_prof_cntx.profile_module]->username,
        (char*)g_prof_profile_content_p[g_prof_cntx.profile_module]->username);

    strcpy(
        (char*)g_prof_activated_profile_content[g_prof_cntx.profile_module]->password,
        (char*)g_prof_profile_content_p[g_prof_cntx.profile_module]->password);

    g_prof_activated_profile_content[g_prof_cntx.profile_module]->empty =
        g_prof_profile_content_p[g_prof_cntx.profile_module]->empty;

    g_prof_activated_profile_content[g_prof_cntx.profile_module]->editable =
        g_prof_profile_content_p[g_prof_cntx.profile_module]->editable;

    g_prof_activated_profile_content[g_prof_cntx.profile_module]->proxy_port =
        g_prof_profile_content_p[g_prof_cntx.profile_module]->proxy_port;

    g_prof_activated_profile_content[g_prof_cntx.profile_module]->data_account_primary_id =
        g_prof_profile_content_p[g_prof_cntx.profile_module]->data_account_primary_id;

    g_prof_activated_profile_content[g_prof_cntx.profile_module]->data_account_secondary_id =
        g_prof_profile_content_p[g_prof_cntx.profile_module]->data_account_secondary_id;

    g_prof_activated_profile_content[g_prof_cntx.profile_module]->conn_type =
        g_prof_profile_content_p[g_prof_cntx.profile_module]->conn_type;

    for (index = 0; index < 4; index++)
    {
        g_prof_activated_profile_content[g_prof_cntx.profile_module]->proxy_ip[index] =
            g_prof_profile_content_p[g_prof_cntx.profile_module]->proxy_ip[index];
    }

	 if (g_prof_cntx.profile_module == BRW_PROF_BROWSER_PROFILE
		&& g_prof_cntx.prov_flag == BRW_NO_PROVISIONING)
	 {
		 g_prof_cntx.active_profile_modified = TRUE;
		mmi_brw_active_profile_changed();
	 }
	 else if (g_prof_cntx.profile_module == BRW_PROF_MMS_PROFILE
		 && g_prof_cntx.prov_flag == BRW_NO_PROVISIONING)
	{
	    g_prof_cntx.active_profile_modified = TRUE;
		 mmi_umms_set_current_mms_profile(FALSE);
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_get_activated_wap_profile
 * DESCRIPTION
 *  It returns the pointer to the activated wap profile content struct
 * PARAMETERS
 *  void
 * RETURNS
 *  g_prof_activated_wap_profile
 *****************************************************************************/
nvram_profile_content_struct *mmi_brw_prof_get_activated_wap_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_prof_activated_profile_content[BRW_PROF_BROWSER_PROFILE];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_get_activated_mms_profile
 * DESCRIPTION
 *  It returns the pointer to the activated wap profile content struct
 * PARAMETERS
 *  void
 * RETURNS
 *  g_prof_activated_wap_profile
 *****************************************************************************/
nvram_profile_content_struct *mmi_brw_prof_get_activated_mms_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_prof_activated_profile_content[BRW_PROF_MMS_PROFILE];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_set_default_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  profile_type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prof_set_default_setting(U8 profile_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    MMIEQNVRAMRESETREQ *local_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_prof_cntx.profile_module = profile_type;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = MSG_ID_MMI_EQ_NVRAM_RESET_REQ;
    local_data = (MMIEQNVRAMRESETREQ*) OslConstructDataPtr(sizeof(MMIEQNVRAMRESETREQ));
    if (profile_type == BRW_PROF_BROWSER_PROFILE)
    {
        local_data->lid = NVRAM_EF_WAP_PROFILE_NAMES_LID; /* please fill in the desired LID here */
        local_data->reset_category = NVRAM_RESET_CERTAIN;
    }
    else if (profile_type == BRW_PROF_MMS_PROFILE)
    {
        local_data->lid = NVRAM_EF_MMS_PROFILE_NAMES_LID; /* please fill in the desired LID here */
        local_data->reset_category = NVRAM_RESET_CERTAIN;
    }
    Message.oslDataPtr = (oslParaType*) local_data;
    Message.oslPeerBuffPtr = NULL;
    SetProtocolEventHandler(mmi_brw_prof_restore_default_setting, MSG_ID_MMI_EQ_NVRAM_RESET_RSP);
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_restore_default_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prof_restore_default_setting(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_prof_cntx.profile_module == BRW_PROF_BROWSER_PROFILE)
    {
        mmi_brw_prof_set_wap_default_profile_list();
		mmi_brw_prof_get_activated_profile_data(
            BRW_PROF_BROWSER_PROFILE,
            g_prof_cntx.actived_profile_content_index[BRW_PROF_BROWSER_PROFILE]);
		mmi_brw_active_profile_changed_without_ui();
		mmi_brw_psh_set_default_setting();
    }
    else if (g_prof_cntx.profile_module == BRW_PROF_MMS_PROFILE)
    {
        mmi_brw_prof_set_mms_default_profile_list();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_set_default_setting_temp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prof_set_default_setting_temp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_prof_set_default_setting(1);
    mmi_brw_prof_set_default_setting(0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prov_save_profile
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prov_save_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = mmi_brw_prof_check_free_content_index(g_prof_cntx.profile_count1);

    if (g_prof_cntx.profile_display_p == NULL)
    {
        g_prof_cntx.profile_display_p = (profile_content_struct*) OslMalloc(sizeof(profile_content_struct));
    }

    if (g_prof_profile_content_p[g_prof_cntx.profile_module] == NULL)
    {
        g_prof_profile_content_p[g_prof_cntx.profile_module] =
            (nvram_profile_content_struct*) OslMalloc(NVRAM_EF_WAP_PROFILE_CONTENT_SIZE);
    }
    g_prof_name_arr_p[g_prof_cntx.profile_module]->nvram_profile_name_array[g_prof_cntx.profile_count1].content_index
        = index;
    mmi_brw_prov_get_content_from_setting();
    mmi_brw_prof_nvram_add_new_profile();
    if (g_prof_cntx.prov_activate_profile_flag == 0)
    {
        g_prof_cntx.actived_profile_content_index[g_prof_cntx.profile_module] = index;

        if (g_prof_cntx.profile_module == BRW_PROF_BROWSER_PROFILE)
        {
            WriteValue(
                NVRAM_BRW_ACTIVATED_WAP_PROFILE_INDEX,
                &g_prof_cntx.actived_profile_content_index[g_prof_cntx.profile_module],
                DS_BYTE,
                &error);
        }
        else if (g_prof_cntx.profile_module == BRW_PROF_MMS_PROFILE)
        {
            WriteValue(
                NVRAM_BRW_ACTIVATED_MMS_PROFILE_INDEX,
                &g_prof_cntx.actived_profile_content_index[g_prof_cntx.profile_module],
                DS_BYTE,
                &error);
        }
        mmi_brw_prof_get_activated_profile_data(
            BRW_PROF_BROWSER_PROFILE,
            g_prof_cntx.actived_profile_content_index[g_prof_cntx.profile_module]);

        g_prof_cntx.prov_activate_profile_flag = 1;
    }
    g_prof_cntx.setting_installed = 1;
	mmi_brw_prov_update_remaining_profile_count();
    mmi_prov_commit_setting();
    /* GoBackHistory(); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prov_update_selected_profile
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prov_update_selected_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_prof_name_arr_p[g_prof_cntx.profile_module]->nvram_profile_name_array[g_prof_cntx.profile_index].
        permission_bits == BRW_PROF_READ_WRITE)
    {
        if (g_prof_cntx.profile_display_p == NULL)
        {
            g_prof_cntx.profile_display_p = (profile_content_struct*) OslMalloc(sizeof(profile_content_struct));
        }

        if (g_prof_profile_content_p[g_prof_cntx.profile_module] == NULL)
        {
            g_prof_profile_content_p[g_prof_cntx.profile_module] =
                (nvram_profile_content_struct*) OslMalloc(NVRAM_EF_WAP_PROFILE_CONTENT_SIZE);
        }
        mmi_brw_prov_get_content_from_setting();
        mmi_brw_prof_update_nvram_profile();
        if (g_prof_cntx.prov_activate_profile_flag == 0)
        {
            mmi_brw_prof_activate_selected_profile();
            g_prof_cntx.prov_activate_profile_flag = 1;
        }
        g_prof_cntx.setting_installed = 1;
		mmi_brw_prov_update_remaining_profile_count();
		DeleteScreenIfPresent(SCR_ID_PROF_HDLR_PROF_LIST);
        GoBackHistory();
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_PROV_HDLR_PERMISSION_DENIED),
            IMG_GLOBAL_ERROR,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_wap_set_homepage
 * DESCRIPTION
 *  
 * PARAMETERS
 *  homepage_url        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_brw_prof_wap_set_homepage(S8 *homepage_url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_prof_activated_profile_content[BRW_PROF_BROWSER_PROFILE]->editable == BRW_PROF_READ_ONLY)
    {
        return FALSE;
    }
    else
    {
        memset(g_prof_activated_profile_content[BRW_PROF_BROWSER_PROFILE]->url, '\0', NVRAM_PROFILE_URL_LEN);
        strcpy((S8*) g_prof_activated_profile_content[BRW_PROF_BROWSER_PROFILE]->url, (S8*) homepage_url);

        WriteRecord(
            NVRAM_EF_WAP_PROFILE_CONTENT_LID,
            (U16) (g_prof_cntx.actived_profile_content_index[BRW_PROF_BROWSER_PROFILE] + 1),
            g_prof_activated_profile_content[BRW_PROF_BROWSER_PROFILE],
            NVRAM_EF_WAP_PROFILE_CONTENT_SIZE,
            &error);

        return TRUE;
    }
}
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_activated_profile_id_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  homepage_url        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prof_activated_profile_id_req(void *msg)
{
	
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    wap_get_bra_prof_id_rsp_struct *local_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_J2ME;
    Message.oslMsgId = MSG_ID_WAP_GET_BRA_PROF_ID_RSP;

    local_data = (wap_get_bra_prof_id_rsp_struct*) OslConstructDataPtr(sizeof(wap_get_bra_prof_id_rsp_struct));

    local_data->prof_id = g_prof_cntx.actived_profile_content_index[BRW_PROF_BROWSER_PROFILE];
    local_data->net_id = g_prof_activated_profile_content[BRW_PROF_BROWSER_PROFILE]->data_account_primary_id;
    local_data->net_id2 = g_prof_activated_profile_content[BRW_PROF_BROWSER_PROFILE]->data_account_secondary_id;

    Message.oslDataPtr = (oslParaType*) local_data;
    Message.oslPeerBuffPtr = NULL;

    OslMsgSendExtQueue(&Message);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_profile_content_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  homepage_url        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prof_profile_content_req(void *local_param, int mod_id, void *ilm)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
	MYQUEUE Message;
	nvram_profile_content_struct *profile_content = NULL;
	wap_get_prof_content_req_struct *msgData =(wap_get_prof_content_req_struct *)local_param;
	wap_get_prof_content_rsp_struct *local_data = NULL;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  
	Message.oslSrcId = MOD_MMI;
    Message.oslDestId = mod_id;
    Message.oslMsgId = MSG_ID_WAP_GET_PROF_CONTENT_RSP;

	local_data = (wap_get_prof_content_rsp_struct*) OslConstructDataPtr(sizeof(wap_get_prof_content_rsp_struct));

	if (msgData->id <= NVRAM_PROFILE_MAX-1) // if profile id exist in the range
	{
		mmi_brw_prof_get_brw_profile_name_list();
		if (g_prof_name_arr_p[BRW_PROF_BROWSER_PROFILE]->nvram_profile_name_array[msgData->id].profile_name[0] != '\0')
		{
			profile_content = mmi_prof_get_content(BRW_PROF_BROWSER_PROFILE,
					(U16)g_prof_name_arr_p[BRW_PROF_BROWSER_PROFILE]->nvram_profile_name_array[msgData->id].content_index);
		}
	}
	if (profile_content != NULL)
	{
		local_data->result =  WAP_PROF_SUCCESS;
		local_data->id = msgData->id;
		local_data->conn_type = mmi_brw_prof_wap_conn_type(profile_content->conn_type);
		
		local_data->prx_ip[0] = profile_content->proxy_ip[0];
		local_data->prx_ip[1] = profile_content->proxy_ip[1];
		local_data->prx_ip[2] = profile_content->proxy_ip[2];
		local_data->prx_ip[3] = profile_content->proxy_ip[3];

		local_data->prx_port = profile_content->proxy_port;
		local_data->net_id = profile_content->data_account_primary_id;
		local_data->net_id2 = profile_content->data_account_secondary_id;	
   
		memset((S8*)local_data->username,'\0',WAP_PROF_MAX_UID_SIZE);
		memset((S8*)local_data->password,'\0',WAP_PROF_MAX_UID_SIZE);

		strncpy((S8*)local_data->username, (S8*) profile_content->username,WAP_PROF_MAX_UID_SIZE-1);
		strncpy((S8*)local_data->password, (S8*) profile_content->password,WAP_PROF_MAX_UID_SIZE-1);

		OslMfree(profile_content);
		profile_content = NULL;
	}
	else
	{
		local_data->result =  WAP_PROF_INVALID_ID;
	}

	Message.oslDataPtr = (oslParaType*) local_data;
    Message.oslPeerBuffPtr = NULL;

    OslMsgSendExtQueue(&Message);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_profile_list_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  homepage_url        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prof_profile_list_req(void *local_param, int mod_id, void *ilm)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
	MYQUEUE Message;
	wap_get_prof_list_rsp_struct *local_data = NULL;
	wap_prof_entry_struct *profile = NULL;

	S16 count = 0;
	S16 index = 0;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	Message.oslSrcId = MOD_MMI;
    Message.oslDestId = mod_id;
    Message.oslMsgId = MSG_ID_WAP_GET_PROF_LIST_RSP;

	local_data = (wap_get_prof_list_rsp_struct*) OslConstructDataPtr(sizeof(wap_get_prof_list_rsp_struct));
	
	mmi_brw_prof_get_brw_profile_name_list();

	while(g_prof_name_arr_p[BRW_PROF_BROWSER_PROFILE]->nvram_profile_name_array[count].profile_name[0] != '\0' &&
			count < NVRAM_PROFILE_MAX)
	{
		count++;
	}
	local_data->number = count;
	local_data->prof_list = (wap_prof_entry_struct*)OslMalloc(sizeof(wap_prof_entry_struct)*count);

	while(index <count)
	{
		profile = local_data->prof_list+index;
		profile->id = index;
		profile->conn_type = mmi_brw_prof_wap_conn_type 
							(g_prof_name_arr_p[BRW_PROF_BROWSER_PROFILE]->nvram_profile_name_array[index].conn_type);

		profile->name.dcs = BRW_PROF_DCS_UCS;

		memset((S8*)profile->name.value,'\0',WAP_PROF_MAX_NAME_SIZE);
		
        if (g_prof_name_arr_p[BRW_PROF_BROWSER_PROFILE]->nvram_profile_name_array[index].dcs == BRW_PROF_DCS_ASCII)
		{
			mmi_asc_n_to_ucs2(
                (S8*) profile->name.value,
                (S8*) g_prof_name_arr_p[BRW_PROF_BROWSER_PROFILE]->nvram_profile_name_array[index].profile_name, (WAP_PROF_MAX_NAME_SIZE-ENCODING_LENGTH)/ENCODING_LENGTH);
        }
        else
        {
			mmi_ucs2ncpy(
                (S8*) profile->name.value,
                (S8*) g_prof_name_arr_p[BRW_PROF_BROWSER_PROFILE]->nvram_profile_name_array[index].profile_name, 
				(WAP_PROF_MAX_NAME_SIZE-ENCODING_LENGTH)/ENCODING_LENGTH);
        }
/**** ritesh start MAUI_00469079 ****/
		profile->name.len = mmi_ucs2strlen((S8*) profile->name.value) * ENCODING_LENGTH;
/**** ritesh end MAUI_00469079 ****/	
		index++;
	}

	Message.oslDataPtr = (oslParaType*) local_data;
    Message.oslPeerBuffPtr = NULL;

    OslMsgSendExtQueue(&Message);


}
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_profile_list_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  homepage_url        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
wap_prof_conn_type_enum mmi_brw_prof_wap_conn_type(prof_conn_type_enum conn_type)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
	switch (conn_type)
	{
		case BRW_PROF_CONN_TYPE_HTTP:

				return WAP_PROF_CONN_TYPE_HTTP;

		case BRW_PROF_CONN_TYPE_CONNECTION_OREINTED:

				return WAP_PROF_CONN_TYPE_WSP_CO;

		case BRW_PROF_CONN_TYPE_CONNECTION_OREINTED_SECURE:

				return WAP_PROF_CONN_TYPE_WSP_CL;
	}
	return WAP_PROF_CONN_TYPE_HTTP;
}

/*****************************************************************************
 * FUNCTION
 *  jam_get_user_agent_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       [?]     
 * RETURNS
 *  void
 *****************************************************************************/

void jam_get_user_agent_req(void *msg)
{
	wap_get_user_agent_rsp_struct *myMsgPtr = NULL;
	ilm_struct *ilm_ptr = NULL;
	char url_str[] = "MAUI WAP BROWSER";

	myMsgPtr = (wap_get_user_agent_rsp_struct*) OslConstructDataPtr(sizeof(wap_get_user_agent_rsp_struct));
	memset(myMsgPtr->user_agent, 0x00, sizeof(myMsgPtr->user_agent));
	myMsgPtr->user_agent_len = strlen(url_str);
	memset(myMsgPtr->user_agent, 0, myMsgPtr->user_agent_len);
	memcpy(myMsgPtr->user_agent, &url_str, myMsgPtr->user_agent_len);

	ilm_ptr = allocate_ilm(MOD_WAP);
	ilm_ptr->src_mod_id = MOD_WAP;
	ilm_ptr->sap_id = J2ME_MMI_SAP;
	ilm_ptr->dest_mod_id = MOD_J2ME;
	ilm_ptr->local_para_ptr = (local_para_struct*) myMsgPtr;
	ilm_ptr->msg_id = MSG_ID_WAP_GET_USER_AGENT_RSP;
	ilm_ptr->peer_buff_ptr = NULL;

	msg_send_ext_queue(ilm_ptr);
}

#endif /* __MMI_BROWSER_2__ */ 

