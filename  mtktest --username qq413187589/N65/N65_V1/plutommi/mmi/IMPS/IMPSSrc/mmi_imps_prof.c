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
 * mmi_imps_prof.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements profile related functions for IMPS application.
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


#include "wgui_inline_edit.h"

#include "custom_data_account.h"

#include "IMPSResDef.h"
#include "mmi_imps_prot.h"

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
const S8 g_imps_zero_ip[] = { '0', '\0', '0', '\0', '0', '\0', '\0', '\0' };    /* 000 */
const S8 g_imps_proxy_port[] = { '8', '\0', '0', '\0', '\0', '\0', '\0', '\0', '\0', '\0' };      /* 8080 */
const S8 g_imps_server_prefix[] = { 'h', '\0', 't', '\0', 't', '\0', 'p', '\0', ':', '\0', '/', '\0', '/', '\0', '\0', '\0' };  /* http:// */

#if defined(__MMI_TOUCH_SCREEN__)
const UI_character_type mmi_imps_mail_allowed[] = L"+_\\-.@A-Za-z0-9";
#endif

/***************************************************************************** 
* Local Function
*****************************************************************************/

/***************************************************************************** 
* Global Variable
*****************************************************************************/

extern wgui_inline_item wgui_inline_items[];
extern const U16 g_imps_inline_icons[];
extern const S8 g_imps_wv[];

/***************************************************************************** 
* Global Function
*****************************************************************************/
extern void set_leading_zero(U8 u8type);


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_init_prof_hilite_hdlr
 * DESCRIPTION
 *  Initialize all profile highlight handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_init_prof_hilite_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    SetHiliteHandler(MENU_ID_IMPS_PROF, mmi_imps_hilite_prof);
    SetHiliteHandler(MENU_ID_IMPS_PROF_ACTIVATE, mmi_imps_hilite_prof_activate);
    SetHiliteHandler(MENU_ID_IMPS_PROF_EDIT, mmi_imps_hilite_prof_edit);
    SetHiliteHandler(MENU_ID_IMPS_PROF_SETTING, mmi_imps_hilite_prof_setting);
    SetHiliteHandler(MENU_ID_IMPS_PROF_CONN, mmi_imps_hilite_prof_conn);
    SetHiliteHandler(MENU_ID_IMPS_PROF_EDITOR_OPT_DONE, mmi_imps_hilite_prof_done);
    SetHiliteHandler(MENU_ID_IMPS_PROF_EDITOR_OPT_INPUT_METH, mmi_imps_hilite_comm_input_meth);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_prof
 * DESCRIPTION
 *  Highlight handler for IMPS -> Profile menu item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_prof(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_pre_entry_prof, KEY_EVENT_UP);
    SetKeyHandler(mmi_imps_pre_entry_prof, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_pre_entry_prof
 * DESCRIPTION
 *  Pre-entry function of profile
 *  1. allocate memory for profile data
 *  2. read profile from NVRAM.
 *  3. entry profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_pre_entry_prof(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imps_p->prof_misc == NULL)
    {
        imps_p->prof_misc = (mmi_imps_prof_misc_struct*) OslMalloc(sizeof(mmi_imps_prof_misc_struct));
        memset(imps_p->prof_misc, 0, sizeof(mmi_imps_prof_misc_struct));
    }

    /* read profile from NVRAM */
    mmi_imps_prof_read_nvram(IMPS_NVRAM_PROF_LIST);

    mmi_imps_entry_prof();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_prof
 * DESCRIPTION
 *  List of profiles
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_prof(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U8 *nStrItemList[IMPS_PROF_COUNT];
    U16 nIconItemList[IMPS_PROF_COUNT] = {0, 0, 0};
    U8 *guiBuffer;
    S32 curr_hilite = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_IMPS_PROF, NULL, mmi_imps_entry_prof, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMPS_PROF);

    for (i = 0; i < IMPS_PROF_COUNT; i++)
    {
        if (mmi_ucs2strlen((S8*) imps_p->prof_misc->prof_name_list[i]) == 0)
        {
            S8 str_tmp[IMPS_PROF_NAME_LEN];

            sprintf(str_tmp, "Profile%d", (i + 1));
            mmi_asc_to_ucs2((S8*) imps_p->prof_misc->prof_name_list[i], str_tmp);
        }

        nStrItemList[i] = (U8*) imps_p->prof_misc->prof_name_list[i];
    }

    if (imps_p->prof_misc->act_prof_indx <= IMPS_PROF_COUNT && imps_p->prof_misc->act_prof_indx > 0)
    {
        nIconItemList[imps_p->prof_misc->act_prof_indx - 1] = IMG_VICON;
        curr_hilite = (S32) (imps_p->prof_misc->act_prof_indx - 1);
    }

    RegisterHighlightHandler(mmi_imps_hilite_prof_list);

    ShowCategory73Screen(
        STR_ID_IMPS_PROF,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        IMPS_PROF_COUNT,
        nStrItemList,
        (U16*) nIconItemList,
        (U16*) gIndexIconsImageList,
        curr_hilite,
        guiBuffer,
        ICON_ICON_TEXT);

    SetLeftSoftkeyFunction(mmi_imps_entry_prof_opt, KEY_EVENT_UP);
    SetKeyHandler(mmi_imps_entry_prof_opt, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    SetDelScrnIDCallbackHandler(SCR_ID_IMPS_PROF, (HistoryDelCBPtr) mmi_imps_prof_del_callback);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_prof_del_callback
 * DESCRIPTION
 *  Callback function when profile list is deleted.
 * PARAMETERS
 *  param       [IN]        Parameter from framework
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_imps_prof_del_callback(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_prof_free_mem();

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_prof_free_mem_n_back
 * DESCRIPTION
 *  Free dynamic memory for Profile and go back to previous screen.
 * PARAMETERS
 *  void
 *  param(?)        [IN]        Parameter from framework(?)(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_prof_free_mem_n_back(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_prof_free_mem();
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_prof_free_mem
 * DESCRIPTION
 *  Free dynamic memory for Profile.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_prof_free_mem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imps_p->prof_misc != NULL)
    {
        OslMfree(imps_p->prof_misc);
        imps_p->prof_misc = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_prof_list
 * DESCRIPTION
 *  Hilite handler for profile list.
 * PARAMETERS
 *  index       [IN]        Index of profile
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_prof_list(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    imps_p->prof_misc->hilte_prof = (U8) index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_prof_opt
 * DESCRIPTION
 *  Entry function of Profile->Option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_prof_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 numItems;
    U16 nStrItemList[2];    /* Activate and Edit */
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_IMPS_PROF_OPT, NULL, mmi_imps_entry_prof_opt, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMPS_PROF_OPT);
    SetParentHandler(MENU_ID_IMPS_PROF_OPT);
    numItems = GetNumOfChild(MENU_ID_IMPS_PROF_OPT);
    GetSequenceStringIds(MENU_ID_IMPS_PROF_OPT, nStrItemList);
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
 *  mmi_imps_hilite_prof_activate
 * DESCRIPTION
 *  Highlight handler of Profile -> Activate menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_prof_activate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_entry_prof_activate, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_prof_activate
 * DESCRIPTION
 *  Pre-Entry function for Profile -> Activate menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_prof_activate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    mmi_imps_nvram_struct *prof_buff;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = imps_p->prof_misc->hilte_prof;

    if (imps_p->prof_misc->act_prof_indx != (i + 1))
    {
        prof_buff = (mmi_imps_nvram_struct*) OslMalloc(NVRAM_EF_IMPS_SIZE);
        mmi_imps_util_read_nvram((void*)prof_buff);

        /* check server */
        if (mmi_ucs2strlen((S8*) prof_buff->prof[i].server) == 0)
        {
            mmi_imps_util_disp_err_popup(STR_ID_IMPS_PROF_NO_CONFIG);
            OslMfree(prof_buff);
            return;
        }

        prof_buff->act_prof_indx = (i + 1);

        /* update activate profile info */
        imps_p->prof_misc->act_prof_indx = (i + 1);

        memcpy(&imps_p->act_prof, &prof_buff->prof[i], sizeof(mmi_imps_prof_struct));

        mmi_imps_util_reset_cont_list();
        mmi_imps_util_reset_presence((void*)prof_buff);

        mmi_imps_util_write_nvram((void*)prof_buff);

        OslMfree(prof_buff);
    }

    /* update act profile info and write to NVRAM */
    DisplayPopup(
        (U8*) GetString(STR_GLOBAL_ACTIVATED),  
        IMG_GLOBAL_ACTIVATED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) SUCCESS_TONE);
    DeleteUptoScrID(SCR_ID_IMPS_PROF);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_prof_edit
 * DESCRIPTION
 *  Highlight handler of Profile -> Edit menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_prof_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_pre_entry_prof_edit, KEY_EVENT_UP);
    SetKeyHandler(mmi_imps_pre_entry_prof_edit, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_pre_entry_prof_edit
 * DESCRIPTION
 *  Pre-entry function inline editor screen of profile.
 *  Retrieve all data account information before entering editor screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_pre_entry_prof_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_display_progressing();

    DataAccountReadyCheck(mmi_imps_dt_acct_callback);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_dt_acct_callback
 * DESCRIPTION
 *  Callback function for Data Account
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_dt_acct_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetExitScrnID() == SCR_ID_IMPS_PROGRESS)
    {
        mmi_imps_entry_prof_edit();
    }

    DeleteScreenIfPresent(SCR_ID_IMPS_PROGRESS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_prof_read_nvram
 * DESCRIPTION
 *  1. Read profile setting from NVRAM
 *  2. After read complete, entry profile edit screen.
 * PARAMETERS
 *  type        [IN]        Cause of reading NVRAM
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_prof_read_nvram(mmi_imps_nvram_cause type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    mmi_imps_nvram_struct *prof_buff = (mmi_imps_nvram_struct*) OslMalloc(NVRAM_EF_IMPS_SIZE);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_util_read_nvram((void*)prof_buff);

    if (type == IMPS_NVRAM_INIT)    /* for initialization, load to active profile */
    {
        if (prof_buff->act_prof_indx > 0 && prof_buff->act_prof_indx <= IMPS_PROF_COUNT)
        {
            memcpy(&imps_p->act_prof, &prof_buff->prof[(prof_buff->act_prof_indx - 1)], sizeof(mmi_imps_prof_struct));

            /* initialize myself in contact list */
            strcpy((S8*) imps_p->cont_info.cont_list[0].id, (S8*) imps_p->act_prof.username);
            imps_p->cont_info.no_cont = 1;
        }
        else
        {
            /* set profile name to NULL to indicate no profile activeated */
            imps_p->act_prof.prof_name[0] = 0;
        }

        /* piggyback sort type */
        imps_p->cont_info.sort_type = prof_buff->sort_type;
    }
    else if (type == IMPS_NVRAM_PROF_LIST)
    {
        for (i = 0; i < IMPS_PROF_COUNT; i++)
            if (mmi_ucs2strlen((S8*) prof_buff->prof[i].prof_name) > 0)
            {
                mmi_ucs2cpy((S8*) imps_p->prof_misc->prof_name_list[i], (S8*) prof_buff->prof[i].prof_name);
            }
        imps_p->prof_misc->act_prof_indx = prof_buff->act_prof_indx;
    }
    else    /* if(type == IMPS_NVRAM_PROF_EDIT)  for profile editing, load to current profile */
    {
        mmi_imps_prof_edit_struct *edit_prof = &imps_p->prof_misc->edit_prof;
        S32 j;
		UI_character_type temp[4];
		U8  offset = 0;

        /* store date to current editing buffer */
        i = (S32) imps_p->prof_misc->hilte_prof;
        if (mmi_ucs2strlen((S8*) prof_buff->prof[i].prof_name) > 0)  /* non-empty profile */
        {
            mmi_ucs2cpy((S8*) edit_prof->prof_name, (S8*) prof_buff->prof[i].prof_name);
            mmi_asc_to_ucs2((S8*) edit_prof->server, (S8*) prof_buff->prof[i].server);
            mmi_asc_to_ucs2((S8*) edit_prof->username, (S8*) prof_buff->prof[i].username);
            mmi_asc_to_ucs2((S8*) edit_prof->passwd, (S8*) prof_buff->prof[i].passwd);
            mmi_asc_to_ucs2((S8*) edit_prof->proxy_username, (S8*) prof_buff->prof[i].proxy_username);
            mmi_asc_to_ucs2((S8*) edit_prof->proxy_passwd, (S8*) prof_buff->prof[i].proxy_passwd);
            mmi_asc_to_ucs2((S8*) edit_prof->auth_usrn, (S8*) prof_buff->prof[i].auth_usrn);
            mmi_asc_to_ucs2((S8*) edit_prof->auth_pwd, (S8*) prof_buff->prof[i].auth_pwd);            

            edit_prof->conn_type = (S32) prof_buff->prof[i].conn_type;
            edit_prof->curr_dt_acct = prof_buff->prof[i].dt_acct;
            edit_prof->use_proxy = (S32) prof_buff->prof[i].use_proxy;
            edit_prof->auto_login = (S32) prof_buff->prof[i].auto_login;
        }
        else
        {
            S8 str_tmp[IMPS_PROF_NAME_LEN];

            memset(edit_prof, 0, sizeof(mmi_imps_prof_edit_struct));
            sprintf(str_tmp, "Profile%d", (i + 1));
            mmi_asc_to_ucs2((S8*) edit_prof->prof_name, str_tmp);
        }

        /* port number */
        if (prof_buff->prof[i].proxy_port == 0) /* no setting before */
        {
            mmi_ucs2cpy((S8*) edit_prof->proxy_port, (S8*) g_imps_proxy_port);
        }
        else
        {
            gui_itoa(prof_buff->prof[i].proxy_port, (UI_string_type) edit_prof->proxy_port, 10);
        }

        /* IP address */      
	    for (j = 0; j < 4; j++)
	    {				
            mmi_ucs2cpy((S8*)&edit_prof->proxy_ip[j], (S8*) L"000");
           
	       gui_itoa((S32) prof_buff->prof[i].proxy_ip[j], (UI_string_type)temp, 10);
	       if (prof_buff->prof[i].proxy_ip[j] < 10)
	       {
    		    offset = 2;
	       }
	       else if (prof_buff->prof[i].proxy_ip[j] < 100)
	       {
	    	    offset = 1;
	       }
	       else
	       {
		        offset = 0;
	       }
		    mmi_ucs2cpy((S8*)&edit_prof->proxy_ip[j][offset], (S8*) temp);
	    }            

        if (edit_prof->curr_dt_acct == 0)
        {
            edit_prof->curr_dt_acct = CUSTOM_DEFAULT_IMPS_DTCNT_ID;
        }

        mmi_dtcnt_get_account_name(
            edit_prof->curr_dt_acct,
            (S8*) imps_p->prof_misc->dt_acct_name,
            MAX_DATA_ACCOUNT_NAME_LEN);
    }

    OslMfree(prof_buff);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_prof_edit
 * DESCRIPTION
 *  Entry Profie->Edit screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_prof_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 numItems;
    U16 nStrItemList[2];    /* Activate and Edit */
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_IMPS_PROF_EDIT, NULL, mmi_imps_entry_prof_edit, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMPS_PROF_EDIT);
    SetParentHandler(MENU_ID_IMPS_PROF_EDIT);
    numItems = GetNumOfChild(MENU_ID_IMPS_PROF_EDIT);
    GetSequenceStringIds(MENU_ID_IMPS_PROF_EDIT, nStrItemList);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ShowCategory52Screen(
        STR_GLOBAL_EDIT,
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
 *  mmi_imps_hilite_prof_setting
 * DESCRIPTION
 *  Highlight handler of Profile -> Edit -> Profile Setting menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_prof_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    imps_p->prof_misc->setting_type = 0;    /* 0 == profile setting */
    SetLeftSoftkeyFunction(mmi_imps_pre_entry_prof_setting, KEY_EVENT_UP);
    SetKeyHandler(mmi_imps_pre_entry_prof_setting, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_prof_conn
 * DESCRIPTION
 *  Highlight handler of Profile -> Edit -> Connection Setting menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_prof_conn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    imps_p->prof_misc->setting_type = 1;    /* 1 == connection setting */
    SetLeftSoftkeyFunction(mmi_imps_pre_entry_prof_conn, KEY_EVENT_UP);
    SetKeyHandler(mmi_imps_pre_entry_prof_conn, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_pre_entry_prof_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_pre_entry_prof_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_prof_read_nvram(IMPS_NVRAM_PROF_EDIT);
    mmi_imps_entry_prof_setting();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_prof_setting
 * DESCRIPTION
 *  Entry inline editor screen of Profile Setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_prof_setting(void)
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
    EntryNewScreen(SCR_ID_IMPS_PROF_SETTING, mmi_imps_exit_prof_setting, NULL, NULL);
    InitializeCategory57Screen();
    mmi_imps_prof_setting_fill_inline_struct();

    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMPS_PROF_SETTING);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_IMPS_PROF_SETTING, &inputBufferSize);

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, IMPS_INLINE_PROF_SETTING, inputBuffer);
    }

    ShowCategory57Screen(
        STR_ID_IMPS_PROF_SETTING,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        STR_GLOBAL_EDIT,
        IMG_GLOBAL_BACK,
        STR_GLOBAL_DONE,
        IMG_GLOBAL_BACK,
        IMPS_INLINE_PROF_SETTING,
        (U16*) g_imps_inline_icons,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_imps_prof_save, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_exit_prof_setting
 * DESCRIPTION
 *  Exit function for inlnine editor screen of Profile Setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_exit_prof_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_leading_zero(TRUE);
    GenericExitInlineScreen(SCR_ID_IMPS_PROF_SETTING, mmi_imps_entry_prof_setting);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_prof_save
 * DESCRIPTION
 *  LSK handler for profile editor screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_prof_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_entry_confirm(STR_GLOBAL_SAVE, mmi_imps_prof_save_yes, mmi_imps_prof_save_no);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_prof_save_no
 * DESCRIPTION
 *  Give up saving profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_prof_save_no(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteUptoScrID(SCR_ID_IMPS_PROF_EDIT);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_prof_save_yes
 * DESCRIPTION
 *  Proceed saving profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_prof_save_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_nvram_struct *prof_buff;
    mmi_imps_prof_struct *prof;
    mmi_imps_prof_edit_struct *edit_prof;
    S32 i;
    S32 port;
    U8 type = imps_p->prof_misc->setting_type;
    U8 data_acct_start = CUSTOM_DEFAULT_IMPS_DTCNT_ID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    edit_prof = &imps_p->prof_misc->edit_prof;

    /* port */
    port = (S32) gui_atoi(edit_prof->proxy_port);

    if (type == 0)  /* 0 == Profie setting */
    {
        /* check profile name */
        if (mmi_ucs2strlen((S8*) edit_prof->prof_name) == 0)
        {
            mmi_imps_util_disp_err_popup(STR_ID_IMPS_ERR_EMPTY_NAME);
            return;
        }

        if (mmi_ucs2cmp((S8*) edit_prof->username, (S8*) g_imps_wv) == 0)
        {
            edit_prof->username[0] = 0;
        }

        /* check server */
        if (mmi_ucs2strlen((S8*) edit_prof->server) == 0)
        {
            mmi_imps_util_disp_err_popup(STR_ID_IMPS_ERR_INVALID_SERVER);
            return;
        }

        /* allow empty username */
        /* check user name */
        /*if (mmi_ucs2strlen((S8*) edit_prof->username) == 0)
        {
            mmi_imps_util_disp_err_popup(STR_ID_IMPS_ERR_INVALID_USERNAME);
            return;
        }*/

    #ifndef IMPS_FOR_OMA_ONLY
        /* check "wv:" and append */
#if 0    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif        
    #endif /* IMPS_FOR_OMA_ONLY */ 
    }
    else
    {
        if (port == 0 || port > 65535)
        {
            mmi_imps_util_disp_err_popup(STR_ID_IMPS_ERR_INVALID_PORT);
            return;
        }
    }

    i = (S32) imps_p->prof_misc->hilte_prof;

    prof_buff = (mmi_imps_nvram_struct*) OslMalloc(NVRAM_EF_IMPS_SIZE);

    memset(prof_buff, 0, NVRAM_EF_IMPS_SIZE);

    mmi_imps_util_read_nvram((void*)prof_buff);

    /* retrieve the address of editing profile */
    prof = &prof_buff->prof[i];

    /* profile name */
    if (mmi_ucs2strlen((S8*) edit_prof->prof_name) == 0)
    {
        /* copy default value of profile name if not exists */
        S8 str_tmp[IMPS_PROF_NAME_LEN];

        sprintf(str_tmp, "Profile%d", (i + 1));
        mmi_asc_to_ucs2((S8*) prof->prof_name, str_tmp);
    }
    else
    {
        mmi_ucs2cpy((S8*) prof->prof_name, (S8*) edit_prof->prof_name);
    }

    if (type == 0)
    {
        /* server */
        mmi_ucs2_to_asc((S8*) prof->server, (S8*) edit_prof->server);

        /* user name */
        mmi_ucs2_to_asc((S8*) prof->username, (S8*) edit_prof->username);

        /* password */
        mmi_ucs2_to_asc((S8*) prof->passwd, (S8*) edit_prof->passwd);

        /* auto login */
        prof->auto_login = (U8) edit_prof->auto_login;

        /* auto update */
        //prof->auto_update = (U8) edit_prof->auto_update;

        /* make sure the data account is updated */
        if (edit_prof->curr_dt_acct <= data_acct_start)
        {
            prof->dt_acct = data_acct_start;
        }
    }
    else
    {
        /* connection type */
        prof->conn_type = (U8) edit_prof->conn_type;

        /* data account */
        prof->dt_acct = edit_prof->curr_dt_acct;

        /* user proxy */
        prof->use_proxy = (U8) edit_prof->use_proxy;

        /* proxy server */
        prof->proxy_ip[0] = (U8) gui_atoi(edit_prof->proxy_ip[0]);
        prof->proxy_ip[1] = (U8) gui_atoi(edit_prof->proxy_ip[1]);
        prof->proxy_ip[2] = (U8) gui_atoi(edit_prof->proxy_ip[2]);
        prof->proxy_ip[3] = (U8) gui_atoi(edit_prof->proxy_ip[3]);

        /* port */
        prof->proxy_port = (U16) port;

        /* proxy user name */
        mmi_ucs2_to_asc((S8*) prof->proxy_username, (S8*) edit_prof->proxy_username);

        /* proxy passwd */
        mmi_ucs2_to_asc((S8*) prof->proxy_passwd, (S8*) edit_prof->proxy_passwd);

        /* http auth user name */
        mmi_ucs2_to_asc((S8*) prof->auth_usrn, (S8*) edit_prof->auth_usrn);

        /* http auth passwd */
        mmi_ucs2_to_asc((S8*) prof->auth_pwd, (S8*) edit_prof->auth_pwd);        
    }

    /* update data if it's current activate profile */
    if ((i + 1) == imps_p->prof_misc->act_prof_indx)
    {
        U8 critical_changed = 0;

        /* if the username or server changed, shall not reset the cache */

        if (mmi_ucs2cmp((S8*) prof_buff->prof[i].server, (S8*) imps_p->act_prof.server)
            || mmi_ucs2cmp((S8*) prof_buff->prof[i].username, (S8*) imps_p->act_prof.username))
        {
            critical_changed = 1;
        }

        memcpy(&imps_p->act_prof, &prof_buff->prof[i], sizeof(mmi_imps_prof_struct));

        if (critical_changed)
        {
            mmi_imps_util_reset_cont_list();
            mmi_imps_util_reset_presence((void*)prof_buff);
        }
    }

    mmi_imps_util_write_nvram((void*)prof_buff);

    /* update profile name in profile list */
    mmi_ucs2cpy((S8*) imps_p->prof_misc->prof_name_list[i], (S8*) prof_buff->prof[i].prof_name);

    mmi_imps_util_disp_popup_done();
    DeleteUptoScrID(SCR_ID_IMPS_PROF_EDIT);

    OslMfree(prof_buff);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_prof_setting_fill_inline_struct
 * DESCRIPTION
 *  Fill inline editor structure of profile.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_prof_setting_fill_inline_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_prof_edit_struct *edit_prof = &imps_p->prof_misc->edit_prof;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Yes/No */
    imps_p->prof_misc->yes_no_list[0] = (U8*) GetString(STR_GLOBAL_NO);
    imps_p->prof_misc->yes_no_list[1] = (U8*) GetString(STR_GLOBAL_YES);

    set_leading_zero(FALSE);

    /* Profile Name */
    SetInlineItemActivation(&wgui_inline_items[0], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[0], (U8*) GetString(STR_ID_IMPS_PROF_NAME));

    SetInlineItemActivation(&wgui_inline_items[1], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[1],
        STR_ID_IMPS_PROF_NAME,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        (U8*) edit_prof->prof_name,
        IMPS_PROF_NAME_LEN,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[1], mmi_imps_hilite_prof_full_edit);

    /* Server */
#ifdef IMPS_PROF_TEST_CODE
    if (mmi_ucs2strlen((S8*) edit_prof->server) == 0)
    {
        mmi_asc_to_ucs2((S8*) edit_prof->server, (S8*) "http://210.61.82.71:888");
    }
#else /* IMPS_PROF_TEST_CODE */ 
    if (mmi_ucs2strlen((S8*) edit_prof->server) == 0)
    {
        mmi_ucs2cpy((S8*) edit_prof->server, (S8*) g_imps_server_prefix);
    }
#endif /* IMPS_PROF_TEST_CODE */ 

    SetInlineItemActivation(&wgui_inline_items[2], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[2], (U8*) GetString(STR_ID_IMPS_SERVER));

    SetInlineItemActivation(&wgui_inline_items[3], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[3],
        STR_ID_IMPS_SERVER,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        (U8*) edit_prof->server,
        IMPS_MAX_SERVER_ADDRESS_LEN,
        INPUT_TYPE_USE_ONLY_ENGLISH_MODES | INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[3], mmi_imps_hilite_prof_full_edit);

    /* User Name */
    if (mmi_ucs2strlen((S8*) edit_prof->username) == 0)
    {
        mmi_ucs2cpy((S8*) edit_prof->username, (S8*) g_imps_wv);
    }

    SetInlineItemActivation(&wgui_inline_items[4], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[4], (U8*) GetString(STR_ID_IMPS_USERNAME));

    SetInlineItemActivation(&wgui_inline_items[5], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[5],
        STR_ID_IMPS_USERNAME,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        (U8*) edit_prof->username,
        IMPS_MAX_USERID_LEN,
        INPUT_TYPE_USE_ONLY_ENGLISH_MODES | INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[5], mmi_imps_hilite_prof_full_edit);

    SetInlineItemActivation(&wgui_inline_items[6], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[6], (U8*) GetString(STR_ID_IMPS_PASSWD));
    SetInlineItemActivation(&wgui_inline_items[7], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[7],
        STR_ID_IMPS_PASSWD,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        (U8*) edit_prof->passwd,
        IMPS_MAX_PASSWORD_LEN,
        INPUT_TYPE_USE_ONLY_ENGLISH_MODES | INPUT_TYPE_ALPHANUMERIC_PASSWORD,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[7], mmi_imps_hilite_prof_full_edit);

    /* Auto Login */
    SetInlineItemActivation(&wgui_inline_items[8], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[8], (U8*) GetString(STR_ID_IMPS_AUTO_LOGIN));
    SetInlineItemActivation(&wgui_inline_items[9], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(&wgui_inline_items[9], 2, imps_p->prof_misc->yes_no_list, &edit_prof->auto_login);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_pre_entry_prof_conn
 * DESCRIPTION
 *  Pre-entry function for connection setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_pre_entry_prof_conn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_prof_read_nvram(IMPS_NVRAM_PROF_EDIT);
    mmi_imps_entry_prof_conn();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_prof_conn
 * DESCRIPTION
 *  Entry inline editor screen of Connection Setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_prof_conn(void)
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
    EntryNewScreen(SCR_ID_IMPS_PROF_SETTING, mmi_imps_exit_prof_conn, NULL, NULL);
    InitializeCategory57Screen();
    mmi_imps_prof_conn_fill_inline_struct();

    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMPS_PROF_SETTING);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_IMPS_PROF_SETTING, &inputBufferSize);

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, IMPS_INLINE_PROF_CONN, inputBuffer);
    }

    ShowCategory57Screen(
        STR_ID_IMPS_PROF_CONN,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        STR_GLOBAL_EDIT,
        IMG_GLOBAL_BACK,
        STR_GLOBAL_DONE,
        IMG_GLOBAL_BACK,
        IMPS_INLINE_PROF_CONN,
        (U16*) g_imps_inline_icons,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_imps_prof_save, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_exit_prof_conn
 * DESCRIPTION
 *  Exit function for inlnine editor screen of Connection Setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_exit_prof_conn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_leading_zero(TRUE);
    GenericExitInlineScreen(SCR_ID_IMPS_PROF_SETTING, mmi_imps_entry_prof_conn);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_prof_conn_fill_inline_struct
 * DESCRIPTION
 *  Fill inline editor structure of profile.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_prof_conn_fill_inline_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Yes/No */
    imps_p->prof_misc->yes_no_list[0] = (U8*) GetString(STR_GLOBAL_NO);
    imps_p->prof_misc->yes_no_list[1] = (U8*) GetString(STR_GLOBAL_YES);

    /* WAP/HTTP */
    imps_p->prof_misc->wap_http_list[0] = (U8*) GetString(STR_ID_IMPS_HTTP);
    imps_p->prof_misc->wap_http_list[1] = (U8*) GetString(STR_ID_IMPS_WAP);

    set_leading_zero(FALSE);

    /* Data Account */
    SetInlineItemActivation(&wgui_inline_items[0], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[0], (U8*) GetString(STR_ID_IMPS_DATA_ACCT));
    SetInlineItemActivation(&wgui_inline_items[1], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemImageText(
        &wgui_inline_items[1],
        (U8*) imps_p->prof_misc->dt_acct_name,
        (PU8) NULL,
        NULL,
        NULL,
        MAX_DATA_ACCOUNT_NAME_LEN,
        0,
        0,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE);
    SetInlineFullScreenEditCustomFunctionImageText(&wgui_inline_items[1], mmi_imps_prof_list_data_acct);
    ShowAsControl(&wgui_inline_items[1]);

    /* Connection type */
    SetInlineItemActivation(&wgui_inline_items[2], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[2], (U8*) GetString(STR_ID_IMPS_CONN_TYPE));
    SetInlineItemActivation(&wgui_inline_items[3], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &wgui_inline_items[3],
        2,
        imps_p->prof_misc->wap_http_list,
        &imps_p->prof_misc->edit_prof.conn_type);

    /* Use proxy */
    SetInlineItemActivation(&wgui_inline_items[4], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[4], (U8*) GetString(STR_ID_IMPS_USE_PROXY));
    SetInlineItemActivation(&wgui_inline_items[5], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &wgui_inline_items[5],
        2,
        imps_p->prof_misc->yes_no_list,
        &imps_p->prof_misc->edit_prof.use_proxy);

    /* Proxy server */
    SetInlineItemActivation(&wgui_inline_items[6], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[6], (U8*) GetString(STR_ID_IMPS_PROXY_SERVER));

    SetInlineItemActivation(&wgui_inline_items[7], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemIP4(
        &wgui_inline_items[7],
        (U8*) imps_p->prof_misc->edit_prof.proxy_ip[0],
        (U8*) imps_p->prof_misc->edit_prof.proxy_ip[1],
        (U8*) imps_p->prof_misc->edit_prof.proxy_ip[2],
        (U8*) imps_p->prof_misc->edit_prof.proxy_ip[3],
        mmi_imps_prof_ip_addr_callback);

    SetInlineItemActivation(&wgui_inline_items[8], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[8], (U8*) GetString(STR_ID_IMPS_PROXY_PORT));
    SetInlineItemActivation(&wgui_inline_items[9], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(
        &wgui_inline_items[9],
        (U8*) imps_p->prof_misc->edit_prof.proxy_port,
        IMPS_PROF_PORT_LEN,
        INPUT_TYPE_NUMERIC);
    LeftJustifyInlineItem(&wgui_inline_items[9]);    
    DisableInlineItemHighlight(&wgui_inline_items[9]);

    /* Proxy User Name */
    SetInlineItemActivation(&wgui_inline_items[10], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[10], (U8*) GetString(STR_ID_IMPS_PROXY_USERNAME));

    SetInlineItemActivation(&wgui_inline_items[11], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[11],
        STR_ID_IMPS_USERNAME,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        (U8*) imps_p->prof_misc->edit_prof.proxy_username,
        IMPS_MAX_PROXY_USERNAME_LEN,
        INPUT_TYPE_USE_ONLY_ENGLISH_MODES | INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[11], mmi_imps_hilite_prof_full_edit);

    /* Proxy Password */
    SetInlineItemActivation(&wgui_inline_items[12], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[12], (U8*) GetString(STR_ID_IMPS_PROXY_PASSWD));
    SetInlineItemActivation(&wgui_inline_items[13], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[13],
        STR_ID_IMPS_PASSWD,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        (U8*) imps_p->prof_misc->edit_prof.proxy_passwd,
        IMPS_MAX_PROXY_PASSWORD_LEN,
        INPUT_TYPE_USE_ONLY_ENGLISH_MODES | INPUT_TYPE_ALPHANUMERIC_PASSWORD,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[13], mmi_imps_hilite_prof_full_edit);

    /* Http auth User Name */
    SetInlineItemActivation(&wgui_inline_items[14], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[14], (U8*) GetString(STR_ID_IMPS_HTTP_AUTH_USERNAME));

    SetInlineItemActivation(&wgui_inline_items[15], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[15],
        STR_ID_IMPS_USERNAME,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        (U8*) imps_p->prof_misc->edit_prof.auth_usrn,
        IMPS_MAX_NAME_LEN,
        INPUT_TYPE_USE_ONLY_ENGLISH_MODES | INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[15], mmi_imps_hilite_prof_full_edit);

    /* Http auth Password */
    SetInlineItemActivation(&wgui_inline_items[16], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[16], (U8*) GetString(STR_ID_IMPS_HTTP_AUTH_PASSWD));
    SetInlineItemActivation(&wgui_inline_items[17], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[17],
        STR_ID_IMPS_PASSWD,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        (U8*) imps_p->prof_misc->edit_prof.auth_pwd,
        IMPS_MAX_HTTP_AUTH_PASSWORD_LEN,
        INPUT_TYPE_USE_ONLY_ENGLISH_MODES | INPUT_TYPE_ALPHANUMERIC_PASSWORD,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[17], mmi_imps_hilite_prof_full_edit);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_prof_ip_addr_callback
 * DESCRIPTION
 *  Callback function for IP address editor in inline editor screen
 * PARAMETERS
 *  string_buffer       [?]     [?]     [?]     [?]
 *  IP1                 [?]     [?]     [?]     [?]
 *  IP2                 [?]     [?]     [?]     [?]
 *  IP3                 [?]     [?]     [?]     [?]
 *  IP4                 [?]     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_prof_ip_addr_callback(U8 *string_buffer, U8 *IP1, U8 *IP2, U8 *IP3, U8 *IP4)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 Point[4];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_to_ucs2((S8*) Point, (S8*) ".");

    mmi_ucs2cpy((PS8) string_buffer, (PS8) IP1);
    mmi_ucs2cat((PS8) string_buffer, (PS8) Point);
    mmi_ucs2cat((PS8) string_buffer, (PS8) IP2);
    mmi_ucs2cat((PS8) string_buffer, (PS8) Point);
    mmi_ucs2cat((PS8) string_buffer, (PS8) IP3);
    mmi_ucs2cat((PS8) string_buffer, (PS8) Point);
    mmi_ucs2cat((PS8) string_buffer, (PS8) IP4);
}


#if defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
* FUNCTION
*  mmi_imps_email_custom_function
* DESCRIPTION
*
*
* PARAMETERS
*  void
* RETURNS
 *  the description of return value, if any.(?)
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/
void mmi_imps_email_custom_function(void)
{
    mmi_pen_editor_set_vk_keys(MMI_TRUE, mmi_imps_mail_allowed, NULL);
}
#endif /* defined(__MMI_TOUCH_SCREEN__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_prof_full_edit
 * DESCRIPTION
 *  Highlight handler of all common full screen eidtor.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_prof_full_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);
    SetLeftSoftkeyFunction(mmi_imps_entry_comm_full_edit_opt, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_comm_full_edit_opt
 * DESCRIPTION
 *  Entry common full screen editor in Profile.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_comm_full_edit_opt(void)
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
    EntryNewScreen(SCR_ID_IMPS_COMM_FULL_EDIT_OPT, NULL, mmi_imps_entry_comm_full_edit_opt, NULL);
    SetParentHandler(MENU_ID_IMPS_PROF_EDITOR_OPT);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMPS_COMM_FULL_EDIT_OPT);
    nItems = GetNumOfChild(MENU_ID_IMPS_PROF_EDITOR_OPT);
    GetSequenceStringIds(MENU_ID_IMPS_PROF_EDITOR_OPT, itemList);
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
 *  mmi_imps_hilite_prof_done
 * DESCRIPTION
 *  Highlight handler of all common full screen eidtor -> Done option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_prof_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(ConfirmInlineFullScreenEdit, KEY_EVENT_UP);
	SetKeyHandler(ConfirmInlineFullScreenEdit, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
	SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_prof_gprs_dt_callback_
 * DESCRIPTION
 *  Callback function for GPRS Data Account
 * PARAMETERS
 *  account_id      [IN]        
 *  index(?)        [IN]        Highlight index of selected account(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_prof_gprs_dt_callback_(U32 account_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    imps_p->prof_misc->edit_prof.curr_dt_acct = (U8) account_id;
    mmi_dtcnt_get_account_name((U8) account_id, (S8*) imps_p->prof_misc->dt_acct_name, MAX_DATA_ACCOUNT_NAME_LEN);

    DeleteUptoScrID(SCR_ID_IMPS_PROF_SETTING);
    GoBackHistory();
    SetInlineListMenuChanged();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_prof_gprs_dt_callback
 * DESCRIPTION
 *  Callback function for GPRS Data Account
 * PARAMETERS
 *  index       [IN]        Highlight index of selected account
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_prof_gprs_dt_callback(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*   mmi_ucs2ncpy((S8*)imps_p->prof_misc->dt_acct_name,
       (S8*)g_GPRS_DataAccount[index].DataAccountName,
       MAX_DATA_ACCOUNT_NAME_LEN);
       imps_p->prof_misc->edit_prof.curr_dt_acct = (U8)(index + MAX_DATA_ACCOUNT_GSM_LIMIT);
       
       DeleteUptoScrID(SCR_ID_IMPS_PROF_SETTING);
       GoBackHistory();
       SetInlineListMenuChanged(); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_prof_list_data_acct
 * DESCRIPTION
 *  LSK handler of Data Account item in Profile Setting inline editor screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_prof_list_data_acct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_dtcnt_select_account(
        mmi_imps_prof_gprs_dt_callback_,
        MENU_ID_IMPS_MAIN,
        DATA_ACCOUNT_BEARER_GPRS | DATA_ACCOUNT_BEARER_WIFI);
}

#endif