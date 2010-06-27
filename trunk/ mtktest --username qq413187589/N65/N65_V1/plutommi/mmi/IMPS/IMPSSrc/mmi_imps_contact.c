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
 * mmi_imps_contact.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements contact list related functions for IMPS application.
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

#include "PhoneBookGprot.h"

#include "IMPSResDef.h"
#include "mmi_imps_prot.h"

#include "FileManagerGProt.h"

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


#ifdef IMPS_TEST_CODE


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_test_search_complete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_test_search_complete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_entry_search_result();
    DeleteUptoScrID(SCR_ID_IMPS_CONT_OPT);
}

#endif /* IMPS_TEST_CODE */ 

/*****************************************************************************
 * FUNCTION
 *  mmi_imps_init_contact_hilite_hdlr
 * DESCRIPTION
 *  Initialize all contact highlight handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_init_contact_hilite_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    SetHiliteHandler(MENU_ID_IMPS_CONT_DEL, mmi_imps_hilite_del_cont);
    
    /* add contact */
    SetHiliteHandler(MENU_ID_IMPS_CONT_ADD, mmi_imps_hilite_add_cont);
    SetHiliteHandler(MENU_ID_IMPS_CONT_ADD_DIRECT, mmi_imps_hilite_add_direct);
    SetHiliteHandler(MENU_ID_IMPS_SEARCH_DIRECT, mmi_imps_hilite_direct_search);
    SetHiliteHandler(MENU_ID_IMPS_SEARCH_PHB, mmi_imps_hilite_search_from_phb);

    SetHiliteHandler(MENU_ID_IMPS_CONT_ADD_NAME_OPT_DONE, mmi_imps_hilite_input_name_opt_done);
    SetHiliteHandler(MENU_ID_IMPS_CONT_ADD_NAME_OPT_INPUT_METH, mmi_imps_hilite_comm_input_meth);

    /* sort */
    SetHiliteHandler(MENU_ID_IMPS_CONT_SORT, mmi_imps_hilite_sort);
    SetHiliteHandler(MENU_ID_IMPS_SORT_BY_NAME, mmi_imps_hilite_sort_by_name);
    SetHiliteHandler(MENU_ID_IMPS_SORT_BY_GROUP, mmi_imps_hilite_sort_by_group);
    SetHiliteHandler(MENU_ID_IMPS_SORT_BY_STATUS, mmi_imps_hilite_sort_by_status);

    SetHiliteHandler(MENU_ID_IMPS_CONT_MANAGE_GROUP, mmi_imps_hilite_manage_group);

    /* group */
    SetHiliteHandler(MENU_ID_IMPS_GROUP_OPT_CREATE, mmi_imps_hilite_group_create);
    SetHiliteHandler(MENU_ID_IMPS_GROUP_OPT_LIST_MEMBER, mmi_imps_hilite_group_list_member);
    SetHiliteHandler(MENU_ID_IMPS_GROUP_OPT_EDIT, mmi_imps_hilite_group_edit);
    SetHiliteHandler(MENU_ID_IMPS_GROUP_OPT_DELETE, mmi_imps_hilite_group_del);

#ifdef IMPS_FOR_OMA_ONLY
    /* sbuscribe presence */
    SetHiliteHandler(MENU_ID_IMPS_CONT_SUBSCRIBE, mmi_imps_hilite_subscribe);
    SetHiliteHandler(MENU_ID_IMPS_CONT_UNSUBSCRIBE, mmi_imps_hilite_unsubscribe);
#endif /* IMPS_FOR_OMA_ONLY */ 

}


#define CONT_IMPS


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_pre_entry_cont
 * DESCRIPTION
 *  Pre-Entry function of contact list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_pre_entry_cont(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((void*)subMenuData[0], 0, MAX_SUB_MENU_SIZE);
    if (mmi_ucs2strlen((S8*) imps_p->cont_info.cont_list[0].alias) == 0)
    {
        mmi_asc_n_to_ucs2((S8*) subMenuData[0], (S8*) imps_p->cont_info.cont_list[0].id, MAX_SUBMENU_CHARACTERS);
    }
    else
    {
        mmi_ucs2ncpy((S8*) subMenuData[0], (S8*) imps_p->cont_info.cont_list[0].alias, MAX_SUBMENU_CHARACTERS);
    }
    strcpy((S8*) imps_p->cont_info.cont_list[0].group_id, (S8*) "MySelf");

    mmi_imps_sort_list();

    imps_p->gen_info.curr_tab = 0;

    mmi_imps_entry_cont();

    DeleteScreenIfPresent(SCR_ID_IMPS_CHAT);

    mmi_imps_check_system_message();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_cont_get_items
 * DESCRIPTION
 *  Fill items of contact list into UI buffers
 * PARAMETERS
 *  start_index     [IN]        Start index of item to be retrieved
 *  menu_data       [IN]        Address of menu data
 *  data_size       [IN]        Maximal number of menu items can be put in the buffer
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_imps_cont_get_items(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;
    S32 count = (S32) imps_p->cont_info.no_cont;
    mmi_imps_cont_struct *cont;
    gui_iconlist_menu_item *item = menu_data;
    mmi_imps_group_struct *group;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0, j = (i + start_index); i < data_size && j < count; i++, j++)
    {
        cont = &imps_p->cont_info.cont_list[j];

        if (cont->availability == IMPS_PA_USER_UNKNOWN)
        {
            item->image_list[0] = (PU8) GetImage(IMG_ID_IMPS_REFRESH);
        }
        else
        {
            item->image_list[0] = (PU8) GetImage((U16) (cont->availability + IMG_ID_IMPS_ONLINE));
        }

        if (cont->comm_state & IMPS_CONT_NEW_MSG)
        {
            item->image_list[1] = (PU8) GetImage(IMG_ID_IMPS_MESSAGE);
        }
        else
        {
            item->image_list[1] = NULL;
        }

        if (cont->comm_state & IMPS_CONT_BLOCK)
        {
            item->image_list[2] = (PU8) GetImage(IMG_ID_IMPS_BLOCK);
        }
        else
        {
            item->image_list[2] = NULL;
        }

        if (mmi_ucs2strlen((S8*) cont->nick_name) != 0)
        {
            mmi_imps_util_copy_with_dot((S8*) cont->nick_name, (S8*) item->item_list[0], MAX_SUBMENU_CHARACTERS);
            
        }
        else if (mmi_ucs2strlen((S8*) cont->alias) != 0)
        {
            mmi_imps_util_copy_with_dot((S8*) cont->alias, (S8*) item->item_list[0], MAX_SUBMENU_CHARACTERS);
        }
        else
        {
            mmi_imps_util_ansi_2_ucs2_menu((S8*) cont->id, (S8*) item->item_list[0], MAX_SUBMENU_CHARACTERS);            
        }

        if (j == 0)
        {
            mmi_ucs2cpy((S8*) item->item_list[1], (S8*) GetString(STR_ID_IMPS_MYSELF));
        }
        else
        {
            S32 k;

            /* find the group that contact belongs to */
            for (k = 0; k < IMPS_MAX_NO_GROUP; k++)
            {
                group = &imps_p->group_info.group_list[k];
                if (strcmp((S8*) group->group_id, (S8*) cont->group_id) == 0)
                {
                    if (mmi_ucs2strlen((S8*) group->group_name))
                    {
                        mmi_imps_util_copy_with_dot(
                            (S8*) group->group_name,
                            (S8*) item->item_list[1],
                            MAX_SUBMENU_CHARACTERS);
                    }
                    else
                    {
                        mmi_imps_util_ansi_2_ucs2_menu(
                            (S8*) cont->group_id,
                            (S8*) item->item_list[1],
                            MAX_SUBMENU_CHARACTERS);
                    }
                }
            }
        }

        item++;
    }

    return i;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_cont_get_hints
 * DESCRIPTION
 *  Fill items of hint list into UI buffers. Currently, it's no use.
 * PARAMETERS
 *  start_index     [IN]        Start index of item to be retrieved
 *  hint_array      [IN]        Buffer to strore list of hints
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_imps_cont_get_hints(S32 start_index, UI_string_type *hint_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_cont
 * DESCRIPTION
 *  Entry main screen of IMPS (contact list and chatting screen)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_cont(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    BOOL list_is_ready_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_IMPS_CONT, NULL, mmi_imps_pre_entry_cont, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMPS_CONT);

    if (imps_p->cont_info.clear_gui_buff)
    {
        guiBuffer = NULL;
        imps_p->cont_info.clear_gui_buff = FALSE;
    }

    SetParentHandler(0);

    RegisterHighlightHandler(mmi_imps_hilite_contact);

    mmi_imps_tab_init();

    ShowCategory425Screen(
        (UI_string_type) GetString(STR_ID_IMPS_CONT_LIST),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (S8) imps_p->gen_info.no_tab,
        (S8) imps_p->gen_info.curr_tab,
        MMI_tab_bar_items,
        (S32) imps_p->cont_info.no_cont,
        mmi_imps_cont_get_items,
        mmi_imps_cont_get_hints,
        (PU8) GetImage(IMG_ID_IMPS_ONLINE),
        (PU8) GetImage(IMG_ID_IMPS_MESSAGE),
        imps_p->cont_info.curr_cont,
        guiBuffer,
        &list_is_ready_p);

    SetCategory425TabSelectCallback(mmi_imps_tab_jump);

    /* set/reset all blinking/unblinking status */
    mmi_imps_util_blink_tab();

    SetLeftSoftkeyFunction(mmi_imps_entry_cont_opt, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(mmi_imps_tab_prev, KEY_LEFT_ARROW, KEY_EVENT_DOWN);   /* move to previous tab */
    SetKeyHandler(mmi_imps_tab_next, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);  /* move to next tab */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_cont_reset_msg_icon
 * DESCRIPTION
 *  Reset status icon of current highlighted chat room.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_cont_reset_msg_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    mmi_imps_room_struct *room = &imps_p->room_info.room_list[imps_p->chat_info.curr_room];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* only apply to single talk, for group chat, the status of contact list does not affect */
    if (room->type == IMPS_ROOM_TYPE_SINGLE)
    {
        /* start from the first contact except myself */
        for (i = 1; i < imps_p->cont_info.no_cont; i++)
        {
            /* keneng : in single talk room, room_id is remote user's id */
            if (mmi_imps_util_is_id_same((S8*) room->room_id, (S8*) imps_p->cont_info.cont_list[i].id))
            {
                /* contact list found, unset new message state */
                imps_p->cont_info.cont_list[i].comm_state &= ~IMPS_CONT_NEW_MSG;
                mmi_imps_cont_redraw_list();
                break;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_contact
 * DESCRIPTION
 *  Highlight handler of contact list
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_contact(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    imps_p->cont_info.curr_cont = (U8) index;

    if (index > 0)
    {
        SetKeyHandler(mmi_imps_pre_entry_chat, KEY_SEND, KEY_EVENT_DOWN);
    }
    else
    {
        ClearKeyHandler(KEY_SEND, KEY_EVENT_DOWN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_cont_opt
 * DESCRIPTION
 *  Display option screen for contact list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_cont_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 numItems;
    U16 nStrItemList[16];   /* Activate and Edit */
    U8 *guiBuffer;
    U16 menu_id;
    U8 is_cont_blocked = FALSE;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imps_p->cont_info.curr_cont == 0)
    {
        menu_id = MENU_ID_IMPS_CONT_MY_OPT;
    }
    else
    {
        menu_id = MENU_ID_IMPS_CONT_USER_OPT;   /* MENU_ID_IMPS_CONT_CHAT_OPT */
        if (imps_p->cont_info.cont_list[imps_p->cont_info.curr_cont].comm_state & IMPS_CONT_BLOCK)
        {
            is_cont_blocked = TRUE;
        }
    }

    if (imps_p->gen_info.imps_version < IMPS_CSP_VERSION_13)
    {
        mmi_frm_hide_menu_item(MENU_ID_IMPS_CONT_SUBS_UNSUBS_NOTIFY);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_IMPS_CONT_SUBS_UNSUBS_NOTIFY);
    }    

    EntryNewScreen(SCR_ID_IMPS_CONT_OPT, NULL, mmi_imps_entry_cont_opt, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMPS_CONT_OPT);
    SetParentHandler(menu_id);
    numItems = GetNumOfChild_Ext(menu_id);
    GetSequenceStringIds_Ext(menu_id, nStrItemList);


    /* switch between Block and Grant */
    if (is_cont_blocked)
    {
        for (i = 0; i < numItems; i++)
        {
            if (nStrItemList[i] == STR_ID_IMPS_BLOCK_CONTACT)
            {
                nStrItemList[i] = STR_ID_IMPS_GRANT_CONTACT;
                break;
            }
        }
    }

    /* switch bettween Subs notify and Unsubs notify */
    if (imps_p->gen_info.is_sub_notify == MMI_TRUE)
    {
        for (i = 0; i < numItems; i++)
        {
            if (nStrItemList[i] == STR_ID_IMPS_SUBSCRIBE_NOTIFY)
            {
                nStrItemList[i] = STR_ID_IMPS_UNSUBSCRIBE_NOTIFY;
                break;
            }
        }
    }

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
 *  mmi_imps_cont_redraw_list
 * DESCRIPTION
 *  Redraw contact list when changed.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_cont_redraw_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* force to redraw contact list */
    if (GetActiveScreenId() == SCR_ID_IMPS_CONT)
    {
        RefreshCategory425Screen(imps_p->cont_info.no_cont, imps_p->cont_info.curr_cont);
    }
    else
    {
        imps_p->cont_info.clear_gui_buff = TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_cont_update_when_msg_come
 * DESCRIPTION
 *  Update status of contact when new message comes
 * PARAMETERS
 *  entity      [IN]        Entity to be redraw
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_cont_update_when_msg_come(imps_entity_struct *entity)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 count = (S32) imps_p->cont_info.no_cont;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (entity == NULL)
    {
        return;
    }

    for (i = 1; i < count; i++)
    {
        mmi_imps_cont_struct *cont = &imps_p->cont_info.cont_list[i];

        if (mmi_imps_util_is_id_same((S8*) cont->id, (S8*) entity->id))       /* found contact */
        {
            cont->comm_state |= IMPS_CONT_NEW_MSG;
            mmi_imps_cont_redraw_list();
            break;
        }
    }
}

#define DEL_CONT_IMPS


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_del_cont
 * DESCRIPTION
 *  Highlight handler of Delete Contact option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_del_cont(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_entry_del_cont_confirm, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_del_cont_confirm
 * DESCRIPTION
 *  Display confirmation screen for deleting a contact
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_del_cont_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!imps_p->gen_info.auto_update_done)
    {
        mmi_imps_util_disp_warning_popup(STR_ID_IMPS_ERR_CONT_NOT_READY);
        return;
    }

    mmi_imps_entry_confirm(STR_GLOBAL_DELETE, mmi_imps_del_cont, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_del_cont
 * DESCRIPTION
 *  Proceed deleting a contact
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_del_cont(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* display progressing screen */
    mmi_imps_display_progressing();

    /* delete remote part */
#ifdef IMPS_TEST_CODE
    mmi_imps_del_cont_finished(0);
#else 
    mmi_imps_ps_del_cont_req();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_del_cont_finished
 * DESCRIPTION
 *  Callback function when protocol finishes deleting process.
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_del_cont_finished(S32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == 0 /* IMPS_OK */ )
    {
        S32 i = (S32) imps_p->cont_info.curr_cont;
        S32 count = (S32) imps_p->cont_info.no_cont;
        S32 j;

        /* decrease counter in group by 1 */
        for (j = 0; j < IMPS_MAX_NO_GROUP; j++)
        {
            if (mmi_imps_util_is_id_same
                ((S8*) imps_p->group_info.group_list[j].group_id, (S8*) imps_p->cont_info.cont_list[i].group_id))
            {
                imps_p->group_info.group_list[j].no_users--;
            }
        }

        /* remove contact list from file and context */
        if (i < (IMPS_MAX_NO_CONT - 1))
        {
            memcpy(
                &imps_p->cont_info.cont_list[i],
                &imps_p->cont_info.cont_list[i + 1],
                (count - i - 1) * sizeof(mmi_imps_cont_struct));
            memset(&imps_p->cont_info.cont_list[count - 1], 0, sizeof(mmi_imps_cont_struct));
        }
        else
        {
            memset(&imps_p->cont_info.cont_list[i], 0, sizeof(mmi_imps_cont_struct));
        }

        imps_p->cont_info.no_cont--;

        mmi_imps_util_write_cont();

        mmi_imps_util_disp_popup_done();

        if (imps_p->gen_info.is_reentry)
        {
            mmi_imps_re_entry_app();
        }
        else
        {
            mmi_imps_util_del_scr_after_progress(SCR_ID_IMPS_CONT);     /* delete screen between contact list and progressing screen */
        }

        /* clear GUI buffer to make the list refreshed */
        imps_p->cont_info.clear_gui_buff = TRUE;
    }
    else
    {
        mmi_imps_util_disp_err_popup(mmi_imps_util_get_err_str(result));
        if (imps_p->gen_info.is_reentry)
        {
            mmi_imps_re_entry_app();
        }
        else
        {
            mmi_imps_util_del_scr_after_progress(SCR_ID_IMPS_CONT_OPT); /* delete screen between opiion screen and progressing screen */
        }
    }
}



#define SORT_IMPS


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_sort_save
 * DESCRIPTION
 *  Save sorting type to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_sort_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_nvram_struct *nvram_buff = (mmi_imps_nvram_struct*) OslMalloc(NVRAM_EF_IMPS_SIZE);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* read data from NVRAM */
    mmi_imps_util_read_nvram((void*)nvram_buff);

    nvram_buff->sort_type = (U8) imps_p->cont_info.sort_type;

    mmi_imps_util_write_nvram((void*)nvram_buff);

    OslMfree(nvram_buff);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_subs_unsubs_notify
 * DESCRIPTION
 *  Highlight handler of Contact List -> subs/unsubs notify option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_subs_unsubs_notify(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_subs_unsubs_notify, KEY_EVENT_UP);  
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_subs_unsubs_notify
 * DESCRIPTION
 *  Handler of Subscribe/Unsubscribe notify
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_subs_unsubs_notify(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* shall not function before auto-update finished */
    if (!imps_p->gen_info.auto_update_done)
    {
        mmi_imps_util_disp_warning_popup(STR_ID_IMPS_ERR_CONT_NOT_READY);
        return;
    }

    /* display progressing screen */
    mmi_imps_display_progressing();
    
    if (imps_p->gen_info.is_sub_notify == MMI_TRUE)
    {
#ifdef IMPS_TEST_CODE
        mmi_imps_unsubs_notify_finished(0);
#else /* IMPS_TEST_CODE */ 
        mmi_imps_ps_unsubs_notify_req();
#endif /* IMPS_TEST_CODE */
    }
    else
    {
#ifdef IMPS_TEST_CODE
        mmi_imps_subs_notify_finished(0);
#else /* IMPS_TEST_CODE */ 
        mmi_imps_ps_subs_notify_req();
#endif /* IMPS_TEST_CODE */        
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_sort
 * DESCRIPTION
 *  Highlight handler of Contact List -> Sort option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_sort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_entry_sort, KEY_EVENT_UP);
    SetKeyHandler(mmi_imps_entry_sort, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_sort
 * DESCRIPTION
 *  Entry function of Contact List -> Sort option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_sort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 numItems;
    U16 nStrItemList[3];    /* only Login and Profile Setting */
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!imps_p->gen_info.auto_update_done)
    {
        mmi_imps_util_disp_warning_popup(STR_ID_IMPS_ERR_CONT_NOT_READY);
        return;
    }

    EntryNewScreen(SCR_ID_IMPS_SORT, NULL, mmi_imps_entry_sort, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMPS_SORT);
    SetParentHandler(MENU_ID_IMPS_CONT_SORT);
    numItems = GetNumOfChild(MENU_ID_IMPS_CONT_SORT);
    GetSequenceStringIds(MENU_ID_IMPS_CONT_SORT, nStrItemList);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ShowCategory52Screen(
        STR_ID_IMPS_SORT_LIST,
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
 *  mmi_imps_hilite_sort_by_name
 * DESCRIPTION
 *  Highlight handler of Contact List -> Sort -> By Name option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_sort_by_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_entry_sort_by_name, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_sort_by_name
 * DESCRIPTION
 *  Handler of Contact List -> Sort -> By Name option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_sort_by_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    imps_p->cont_info.sort_type = IMPS_SORT_BY_NAME;
    mmi_imps_sort_save();
    imps_p->cont_info.clear_gui_buff = TRUE;
    GoBackToHistory(SCR_ID_IMPS_CONT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_sort_by_status
 * DESCRIPTION
 *  Highlight handler of Contact List -> Sort -> By Status option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_sort_by_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_entry_sort_by_status, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_sort_by_status
 * DESCRIPTION
 *  Handler of Contact List -> Sort -> By Status option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_sort_by_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    imps_p->cont_info.sort_type = IMPS_SORT_BY_STATUS;
    mmi_imps_sort_save();
    imps_p->cont_info.clear_gui_buff = TRUE;
    GoBackToHistory(SCR_ID_IMPS_CONT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_sort_by_group
 * DESCRIPTION
 *  Highlight handler of Contact List -> Sort -> By Group option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_sort_by_group(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_entry_sort_by_group, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_sort_by_group
 * DESCRIPTION
 *  Handler of Contact List -> Sort -> By Group option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_sort_by_group(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    imps_p->cont_info.sort_type = IMPS_SORT_BY_GROUP;
    mmi_imps_sort_save();
    imps_p->cont_info.clear_gui_buff = TRUE;
    GoBackToHistory(SCR_ID_IMPS_CONT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_sort_list
 * DESCRIPTION
 *  Sort contact list according to selecting criterion
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_sort_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (imps_p->cont_info.sort_type)
    {
        case IMPS_SORT_BY_STATUS:
            mmi_imps_sort_by_status();
            break;
        case IMPS_SORT_BY_GROUP:
            mmi_imps_sort_by_group();
            break;
        default:    /* case IMPS_SORT_BY_NAME: */
            mmi_imps_sort_by_name();
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_sort_by_name
 * DESCRIPTION
 *  Sort list by name
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_sort_by_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;
    S32 count = (S32) imps_p->cont_info.no_cont;
    mmi_imps_cont_struct *cont_buff = (mmi_imps_cont_struct*) OslMalloc(sizeof(mmi_imps_cont_struct));
    S8 *str1, *str2;
    S8 *str_buff1 = OslMalloc(IMPS_MAX_ID_LEN * ENCODING_LENGTH);
    S8 *str_buff2 = OslMalloc(IMPS_MAX_ID_LEN * ENCODING_LENGTH);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 1; i < count; i++)
    {
        for (j = 1; j < count; j++)
        {
            if (i >= j)
            {
                continue;
            }

            /* compare alais first */
            if (strlen((S8*) imps_p->cont_info.cont_list[i].nick_name))
            {
                str1 = (S8*) imps_p->cont_info.cont_list[i].nick_name;
            }
            else
            {
                mmi_asc_to_ucs2(str_buff1, (S8*) imps_p->cont_info.cont_list[i].id);
                str1 = str_buff1;
            }

            /* compare alais first */
            if (strlen((S8*) imps_p->cont_info.cont_list[j].nick_name))
            {
                str2 = (S8*) imps_p->cont_info.cont_list[j].nick_name;
            }
            else
            {
                mmi_asc_to_ucs2(str_buff2, (S8*) imps_p->cont_info.cont_list[j].id);
                str2 = str_buff2;
            }

            if ((mmi_ucs2cmp((S8*) str1, (S8*) str2) > 0))
            {
                memcpy(cont_buff, &imps_p->cont_info.cont_list[j], sizeof(mmi_imps_cont_struct));
                memcpy(&imps_p->cont_info.cont_list[j], &imps_p->cont_info.cont_list[i], sizeof(mmi_imps_cont_struct));
                memcpy(&imps_p->cont_info.cont_list[i], cont_buff, sizeof(mmi_imps_cont_struct));
            }
        }
    }

    OslMfree(cont_buff);
    OslMfree(str_buff1);
    OslMfree(str_buff2);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_sort_by_status
 * DESCRIPTION
 *  Sort list by status
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_sort_by_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;
    S32 count = (S32) imps_p->cont_info.no_cont;
    mmi_imps_cont_struct *cont_buff = (mmi_imps_cont_struct*) OslMalloc(sizeof(mmi_imps_cont_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 1; i < count; i++)
    {
        for (j = 1; j < count; j++)
        {
            if ((imps_p->cont_info.cont_list[i].availability > imps_p->cont_info.cont_list[j].availability) && i < j)
            {
                memcpy(cont_buff, &imps_p->cont_info.cont_list[j], sizeof(mmi_imps_cont_struct));
                memcpy(&imps_p->cont_info.cont_list[j], &imps_p->cont_info.cont_list[i], sizeof(mmi_imps_cont_struct));
                memcpy(&imps_p->cont_info.cont_list[i], cont_buff, sizeof(mmi_imps_cont_struct));
            }
        }
    }

    OslMfree(cont_buff);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_sort_by_group
 * DESCRIPTION
 *  Sort list by group
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_sort_by_group(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;
    S32 count = (S32) imps_p->cont_info.no_cont;
    mmi_imps_cont_struct *cont_buff = (mmi_imps_cont_struct*) OslMalloc(sizeof(mmi_imps_cont_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 1; i < count; i++)
    {
        for (j = 1; j < count; j++)
        {
            if (strcmp((S8*) imps_p->cont_info.cont_list[i].group_id, (S8*) imps_p->cont_info.cont_list[j].group_id) >
                0 && i < j)
            {
                memcpy(cont_buff, &imps_p->cont_info.cont_list[j], sizeof(mmi_imps_cont_struct));
                memcpy(&imps_p->cont_info.cont_list[j], &imps_p->cont_info.cont_list[i], sizeof(mmi_imps_cont_struct));
                memcpy(&imps_p->cont_info.cont_list[i], cont_buff, sizeof(mmi_imps_cont_struct));
            }
        }
    }

    OslMfree(cont_buff);
}

#define ADD_CONTACT


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_add_cont
 * DESCRIPTION
 *  Highlight handler of Contact List -> Add Contact option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_add_cont(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_entry_add_cont, KEY_EVENT_UP);
    SetKeyHandler(mmi_imps_entry_add_cont, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_add_cont
 * DESCRIPTION
 *  Display available option for Add Contact
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_add_cont(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 numItems;
    U16 nStrItemList[3];
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!imps_p->gen_info.auto_update_done)
    {
        mmi_imps_util_disp_warning_popup(STR_ID_IMPS_ERR_CONT_NOT_READY);
        return;
    }
    else if (imps_p->cont_info.no_cont >= IMPS_MAX_NO_CONT)
    {
        mmi_imps_util_disp_err_popup(STR_ID_IMPS_ERR_CONT_FULL);
        return;
    }
    else if (imps_p->group_info.no_group == 0)
    {
        mmi_imps_util_disp_err_popup(STR_ID_IMPS_ERR_NO_GROUP);
        return;
    }

    EntryNewScreen(SCR_ID_IMPS_ADD_CONT, NULL, mmi_imps_entry_add_cont, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMPS_ADD_CONT);
    SetParentHandler(MENU_ID_IMPS_CONT_ADD);
    numItems = GetNumOfChild_Ext(MENU_ID_IMPS_CONT_ADD);
    GetSequenceStringIds_Ext(MENU_ID_IMPS_CONT_ADD, nStrItemList);
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
 *  mmi_imps_hilite_direct_search
 * DESCRIPTION
 *  Highlight handler of direct search option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_direct_search(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_pre_entry_cont_search, KEY_EVENT_UP);
    SetKeyHandler(mmi_imps_pre_entry_cont_search, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_search_from_phb
 * DESCRIPTION
 *  Highlight handler of Contact List -> Add Contact -> Search From Phonebook option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_search_from_phb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_entry_search_from_phb, KEY_EVENT_UP);
    SetKeyHandler(mmi_imps_entry_search_from_phb, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_search_from_phb
 * DESCRIPTION
 *  Entry function for Contact List -> Add Contact -> Search From Phonebook option
 * PARAMETERS
 *  void
 *  entity(?)(?)(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_search_from_phb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_generic_enter_list(mmi_imps_search_phb_callback);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_pre_entry_cont_search
 * DESCRIPTION
 *  Pre-Entry function of inline editor screen for Search Contact.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_pre_entry_cont_search(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imps_p->search_cont == NULL)
    {
        imps_p->search_cont = (mmi_imps_search_cont_struct*) OslMalloc(sizeof(mmi_imps_search_cont_struct));
    }

    /* initialize */
    memset(imps_p->search_cont, 0, sizeof(mmi_imps_search_cont_struct));

    mmi_imps_entry_cont_search();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_search_phb_callback
 * DESCRIPTION
 *  Callback function for phone book search
 * PARAMETERS
 *  entity      [?]     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_search_phb_callback(MMI_PHB_VCARD_STRUCT *entity)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (entity != NULL)
    {
        mmi_imps_search_cont_struct *search_cont;

        if (imps_p->search_cont == NULL)
        {
            imps_p->search_cont = (mmi_imps_search_cont_struct*) OslMalloc(sizeof(mmi_imps_search_cont_struct));
            /* initialize */
            imps_p->search_cont->user_alias[0] = 0;
            imps_p->search_cont->user_emailaddr[0] = 0;
            imps_p->search_cont->user_firstname[0] = 0;
            imps_p->search_cont->user_id[0] = 0;
            imps_p->search_cont->user_lastname[0] = 0;
            imps_p->search_cont->user_mobile_number[0] = 0;
            imps_p->search_cont->user_max_age[0] = 0;
            imps_p->search_cont->user_min_age[0] = 0;
            imps_p->search_cont->fname[0] = 0;
            imps_p->search_cont->city[0] = 0;
            /* imps_p->search_cont->free_text[0] = 0; */
            imps_p->search_cont->intention[0] = 0;
            imps_p->search_cont->hobbies[0] = 0;
        }

        search_cont = imps_p->search_cont;

        if (strlen((S8*) entity->emailAddress))
        {
            mmi_asc_to_ucs2((S8*) search_cont->user_emailaddr, (S8*) entity->emailAddress);
        }

        if (strlen((S8*) entity->number))
        {
            mmi_asc_to_ucs2((S8*) search_cont->user_mobile_number, (S8*) entity->number);
        }

        if (mmi_ucs2strlen((S8*) entity->name))
        {
            mmi_ucs2cpy((S8*) search_cont->user_alias, (S8*) entity->name);
        }

        mmi_imps_entry_cont_search();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_is_search_cont_changed
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
BOOL mmi_imps_is_search_cont_changed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((S8*) imps_p->search_cont->user_alias)
        || mmi_ucs2strlen((S8*) imps_p->search_cont->user_emailaddr)
        || mmi_ucs2strlen((S8*) imps_p->search_cont->user_firstname)
        || mmi_ucs2strlen((S8*) imps_p->search_cont->user_id)
        || mmi_ucs2strlen((S8*) imps_p->search_cont->user_lastname)
        || mmi_ucs2strlen((S8*) imps_p->search_cont->user_max_age)
        || mmi_ucs2strlen((S8*) imps_p->search_cont->user_min_age)
        || mmi_ucs2strlen((S8*) imps_p->search_cont->user_mobile_number)
        || mmi_ucs2strlen((S8*) imps_p->search_cont->fname)
        || mmi_ucs2strlen((S8*) imps_p->search_cont->city)
        /* && mmi_ucs2strlen((S8*) imps_p->search_cont->free_text) == 0 */
        || mmi_ucs2strlen((S8*) imps_p->search_cont->intention)
        || mmi_ucs2strlen((S8*) imps_p->search_cont->hobbies))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_cont_search_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_cont_search_item(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index != 2) /* phone number */
    {
        if (mmi_imps_is_search_cont_changed())
        {
            ChangeRightSoftkey(STR_GLOBAL_DONE, 0);
            SetRightSoftkeyFunction(mmi_imps_entryt_search_opt, KEY_EVENT_UP);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_cont_search
 * DESCRIPTION
 *  Entry inline editor screen for Search Contact.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_cont_search(void)
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
    EntryNewScreen(SCR_ID_IMPS_CONT_SEARCH_INLINE, mmi_imps_exit_cont_search, NULL, NULL);

    InitializeCategory57Screen();

    mmi_imps_search_fill_inline_struct();

    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMPS_CONT_SEARCH_INLINE);

    inputBuffer = GetCurrNInputBuffer(SCR_ID_IMPS_CONT_SEARCH_INLINE, &inputBufferSize);

    RegisterHighlightHandler(mmi_imps_hilite_cont_search_item);

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, IMPS_INLINE_SEARCH_CONT, inputBuffer);
    }

    ShowCategory57Screen(
        STR_ID_IMPS_SEARCH_CONTACT,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        STR_GLOBAL_EDIT,
        IMG_GLOBAL_BACK,
        STR_GLOBAL_DONE,
        IMG_GLOBAL_BACK,
        IMPS_INLINE_SEARCH_CONT,
        (U16*) g_imps_inline_icons,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_imps_entryt_search_opt, mmi_imps_search_free_mem_n_back);

    SetDelScrnIDCallbackHandler(SCR_ID_IMPS_CONT_SEARCH_INLINE, (HistoryDelCBPtr) mmi_imps_search_scr_del_callback);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_exit_cont_search
 * DESCRIPTION
 *  Exit function for Search Contact screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_exit_cont_search(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_exit_inline_editor(SCR_ID_IMPS_CONT_SEARCH_INLINE, mmi_imps_pre_entry_cont_search);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_search_free_mem_n_back
 * DESCRIPTION
 *  Free memory use in Search screen and go back to previous screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_search_free_mem_n_back(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_free_search_mem();
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_free_search_mem
 * DESCRIPTION
 *  Free memory of search screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_free_search_mem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imps_p->search_cont != NULL)
    {
        OslMfree(imps_p->search_cont);
        imps_p->search_cont = NULL;
    }
    else if (imps_p->search_room != NULL)
    {
        OslMfree(imps_p->search_room);
        imps_p->search_room = NULL;        
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_search_scr_del_callback
 * DESCRIPTION
 *  Function to free memory when inline editor screen is deleted.
 * PARAMETERS
 *  param       [?]     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_imps_search_scr_del_callback(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_free_search_mem();

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_search_fill_inline_struct
 * DESCRIPTION
 *  Fill inline editor structure of Contact Search screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_search_fill_inline_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_search_cont_struct *search_cont = imps_p->search_cont;
	U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Prepare */
    search_cont->status_list[0] = (U8*) GetString(STR_ID_IMPS_UNSPECIFIED);
    search_cont->status_list[1] = (U8*) GetString(STR_ID_IMPS_ONLINE);
    search_cont->status_list[2] = (U8*) GetString(STR_ID_IMPS_OFFLINE);

    search_cont->gender_list[0] = (U8*) GetString(STR_ID_IMPS_NO_DISCLOSE);
    search_cont->gender_list[1] = (U8*) GetString(STR_ID_IMPS_FEMALE);
    search_cont->gender_list[2] = (U8*) GetString(STR_ID_IMPS_MALE);
    search_cont->gender_list[3] = (U8*) GetString(STR_ID_IMPS_UNSPECIFIED);

    for (i = 0; i < 8; i++)
    {
        search_cont->marital_status_list[i] = (U8*) GetString((U16) (STR_ID_IMPS_NO_DISCLOSE + i));
    }    

    /* User alias */
    SetInlineItemCaption(&wgui_inline_items[0], (U8*) GetString(STR_ID_IMPS_ALIAS));
    SetInlineItemActivation(&wgui_inline_items[1], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[1],
        STR_ID_IMPS_ALIAS,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        (U8*) search_cont->user_alias,
        IMPS_MAX_NAME_LEN,
        INPUT_TYPE_USE_ONLY_ENGLISH_MODES | INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[1], mmi_imps_hilite_prof_full_edit);    

    /* Online status */
    SetInlineItemCaption(&wgui_inline_items[2], (U8*) GetString(STR_ID_IMPS_STATUS));
    SetInlineItemActivation(&wgui_inline_items[3], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(&wgui_inline_items[3], 3, search_cont->status_list, &search_cont->user_onlinestatus);       

    /* Email */
    SetInlineItemCaption(&wgui_inline_items[4], (U8*) GetString(STR_ID_IMPS_EMAIL));
    SetInlineItemActivation(&wgui_inline_items[5], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(
		&wgui_inline_items[5],
		(U8*) search_cont->user_emailaddr,
		IMPS_MAX_USER_EMAIL_ADDRESS_LEN,
		INPUT_TYPE_ALPHANUMERIC_LOWERCASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES);
#if defined(__MMI_TOUCH_SCREEN__)
    SetInlineTextEditCustomFunction(&wgui_inline_items[5], mmi_imps_email_custom_function);
#endif
    DisableInlineItemHighlight(&wgui_inline_items[5]);

    /*
    SetInlineItemActivation(&wgui_inline_items[5], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[5],
        STR_ID_IMPS_EMAIL,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        (U8*) search_cont->user_emailaddr,
        IMPS_MAX_USER_EMAIL_ADDRESS_LEN,
        INPUT_TYPE_USE_ONLY_ENGLISH_MODES | INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[5], mmi_imps_hilite_prof_full_edit);    
*/
    /* User Id */
    SetInlineItemCaption(&wgui_inline_items[6], (U8*) GetString(STR_ID_IMPS_USERID));
    SetInlineItemActivation(&wgui_inline_items[7], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[7],
        STR_ID_IMPS_USERID,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        (U8*) search_cont->user_id,
        IMPS_MAX_ID_LEN,
        INPUT_TYPE_USE_ONLY_ENGLISH_MODES | INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[7], mmi_imps_hilite_prof_full_edit);      

    /* First Name */
    SetInlineItemCaption(&wgui_inline_items[8], (U8*) GetString(STR_ID_IMPS_FIRST_NAME));
    SetInlineItemActivation(&wgui_inline_items[9], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[9],
        STR_ID_IMPS_FIRST_NAME,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        (U8*) search_cont->user_firstname,
        IMPS_MAX_SEARCH_KEYWORD_LEN,
        INPUT_TYPE_USE_ONLY_ENGLISH_MODES | INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[9], mmi_imps_hilite_prof_full_edit);    

    /* Last Name */
    SetInlineItemCaption(&wgui_inline_items[10], (U8*) GetString(STR_ID_IMPS_LAST_NAME));
    SetInlineItemActivation(&wgui_inline_items[11], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[11],
        STR_ID_IMPS_LAST_NAME,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        (U8*) search_cont->user_lastname,
        IMPS_MAX_SEARCH_KEYWORD_LEN,
        INPUT_TYPE_USE_ONLY_ENGLISH_MODES | INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[11], mmi_imps_hilite_prof_full_edit);    

    /* Friendly Name */
    SetInlineItemCaption(&wgui_inline_items[12], (U8*) GetString(STR_ID_IMPS_FRIENDLY_NAME));
    SetInlineItemActivation(&wgui_inline_items[13], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[13],
        STR_ID_IMPS_FRIENDLY_NAME,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        (U8*) search_cont->fname,
        IMPS_MAX_SEARCH_KEYWORD_LEN,
        INPUT_TYPE_USE_ONLY_ENGLISH_MODES | INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[13], mmi_imps_hilite_prof_full_edit);      

    /* Mobile Number */
    SetInlineItemCaption(&wgui_inline_items[14], (U8*) GetString(STR_ID_IMPS_PHONE_NO));
    SetInlineItemActivation(&wgui_inline_items[15], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(
        &wgui_inline_items[15],
        (U8*) search_cont->user_mobile_number,
        IMPS_MAX_USER_MOBILE_PHONE_LEN,
        INPUT_TYPE_PHONE_NUMBER | INPUT_TYPE_PLUS_CHARACTER_HANDLING);
    EnableInlineItemBoundary(&wgui_inline_items[15]);
    DisableInlineItemHighlight(&wgui_inline_items[15]);    

    /* Max Age */
    SetInlineItemCaption(&wgui_inline_items[16], (U8*) GetString(STR_ID_IMPS_MAX_AGE));
    SetInlineItemActivation(&wgui_inline_items[17], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(
        &wgui_inline_items[17],
        (U8*) search_cont->user_max_age,
        3,
        INPUT_TYPE_NUMERIC);
    EnableInlineItemBoundary(&wgui_inline_items[17]);
    DisableInlineItemHighlight(&wgui_inline_items[17]);    

    /* Min Age */
    SetInlineItemCaption(&wgui_inline_items[18], (U8*) GetString(STR_ID_IMPS_MIN_AGE));
    SetInlineItemActivation(&wgui_inline_items[19], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(
        &wgui_inline_items[19],
        (U8*) search_cont->user_min_age,
        3,
        INPUT_TYPE_NUMERIC);
    EnableInlineItemBoundary(&wgui_inline_items[19]);
    DisableInlineItemHighlight(&wgui_inline_items[19]);     

    /* Gender */
    SetInlineItemCaption(&wgui_inline_items[20], (U8*) GetString(STR_ID_IMPS_GENDER));
    SetInlineItemActivation(&wgui_inline_items[21], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(&wgui_inline_items[21], 4, search_cont->gender_list, &search_cont->gender);      

    /* City */
    SetInlineItemCaption(&wgui_inline_items[22], (U8*) GetString(STR_ID_IMPS_CITY));
    SetInlineItemActivation(&wgui_inline_items[23], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[23],
        STR_ID_IMPS_CITY,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        (U8*) search_cont->city,
        IMPS_MAX_SEARCH_KEYWORD_LEN,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[23], mmi_imps_hilite_prof_full_edit);      

    /* Marital Status */
    SetInlineItemCaption(&wgui_inline_items[24], (U8*) GetString(STR_ID_IMPS_MARITAL_STATUS));
    SetInlineItemActivation(&wgui_inline_items[25], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(&wgui_inline_items[25], 8, search_cont->marital_status_list, &search_cont->marital_status);         
    

    /* Free Text */
    /*SetInlineItemActivation(&wgui_inline_items[24], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[24], (U8*) GetString(STR_ID_IMPS_FREE_TEXT));
    SetInlineItemActivation(&wgui_inline_items[25], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit(
        &wgui_inline_items[25],
        STR_ID_IMPS_FREE_TEXT,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        (U8*) search_cont->free_text,
        IMPS_MAX_FREE_TEXT_LEN,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[25], mmi_imps_hilite_prof_full_edit); */       

    /* Intention */
    SetInlineItemCaption(&wgui_inline_items[26], (U8*) GetString(STR_ID_IMPS_INTENTION));
    SetInlineItemActivation(&wgui_inline_items[27], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[27],
        STR_ID_IMPS_INTENTION,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        (U8*) search_cont->intention,
        IMPS_MAX_SEARCH_KEYWORD_LEN,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[27], mmi_imps_hilite_prof_full_edit);    

    /* Hobbies */
    SetInlineItemCaption(&wgui_inline_items[28], (U8*) GetString(STR_ID_IMPS_HOBBIES));
    SetInlineItemActivation(&wgui_inline_items[29], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[29],
        STR_ID_IMPS_HOBBIES,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        (U8*) search_cont->hobbies,
        IMPS_MAX_SEARCH_KEYWORD_LEN,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[29], mmi_imps_hilite_prof_full_edit);      
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entryt_search_opt
 * DESCRIPTION
 *  "Done" key handler in Search screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entryt_search_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 numItems;
    U16 nStrItemList[3];
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_IMPS_SEARCH_OPT, NULL, mmi_imps_entryt_search_opt, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMPS_SEARCH_OPT);
    SetParentHandler(MENU_ID_IMPS_SEARCH_OPT);
    numItems = GetNumOfChild(MENU_ID_IMPS_SEARCH_OPT);
    GetSequenceStringIds(MENU_ID_IMPS_SEARCH_OPT, nStrItemList);

    SetHiliteHandler(MENU_ID_IMPS_SEARCH_OPT_SEARCH, mmi_imps_hilite_search_done);
    SetHiliteHandler(MENU_ID_IMPS_SEARCH_OPT_QUIT, mmi_imps_hilite_search_quit);
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
 *  mmi_imps_hilite_search_done
 * DESCRIPTION
 *  Highlight handler of Search -> Done option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_search_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_search_start, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_search_start
 * DESCRIPTION
 *  Start searching contact procedure
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_search_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if all the fileds are empty */
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif    

    mmi_imps_pre_entry_progressing(
        STR_ID_IMPS,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        0,
        0,
        STR_GLOBAL_ABORT,
        0,
        (U8*) GetString(STR_GLOBAL_SEARCH),
        NULL,
        IMG_GLOBAL_PROGRESS,
        NULL,
        mmi_imps_search_abort,
        mmi_imps_search_abort);

    /* send request to search */
    imps_p->search_result.search_cause = IMPS_SEARCH_CONT;

    /* rest previous searched data */
    imps_p->search_result.count = 0;

#ifdef IMPS_TEST_CODE
    strcpy((S8*) imps_p->search_result.entity[0].id, (S8*) "TEST 1");
    mmi_asc_to_ucs2((S8*) imps_p->search_result.entity[0].sname, (S8*) "TEST 1");

    strcpy((S8*) imps_p->search_result.entity[1].id, (S8*) "TEST 2");
    mmi_asc_to_ucs2((S8*) imps_p->search_result.entity[1].sname, (S8*) "TEST 2");

    strcpy((S8*) imps_p->search_result.entity[2].id, (S8*) "TEST 3");
    mmi_asc_to_ucs2((S8*) imps_p->search_result.entity[2].sname, (S8*) "TEST 3");

    imps_p->search_result.count = 3;
    SetKeyHandler(mmi_imps_test_search_complete, KEY_SEND, KEY_EVENT_DOWN);
#else /* IMPS_TEST_CODE */ 
    mmi_imps_ps_search_req(IMPS_SEARCH_CONT);
#endif /* IMPS_TEST_CODE */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_search_quit
 * DESCRIPTION
 *  Highlight handler of Search -> Quit option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_search_quit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_search_quit, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_search_quit
 * DESCRIPTION
 *  Quit search procedure
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_search_quit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackToHistory(SCR_ID_IMPS_ADD_CONT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_pre_entry_sel_group
 * DESCRIPTION
 *  Pre-Entry function for selecting group when adding new contacts
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_pre_entry_sel_group(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_imps_util_is_cont_exist((S8*) imps_p->search_result.entity[imps_p->search_result.curr_item].id))
    {
        mmi_imps_util_disp_err_popup(STR_ID_IMPS_CONTACT_EXIST);
        return;
    }

    /* display list of groups */
    mmi_imps_entry_sel_group();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_sel_group
 * DESCRIPTION
 *  List of group for the user to select
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_sel_group(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S32 i;
    mmi_imps_group_struct *group;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imps_p->cont_info.no_cont >= IMPS_MAX_NO_CONT)
    {
        mmi_imps_util_disp_warning_popup(STR_ID_IMPS_ERR_CONT_LIST_FULL);
        return;
    }
    
    EntryNewScreen(SCR_ID_IMPS_SELECT_GROUP, NULL, mmi_imps_entry_sel_group, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMPS_SELECT_GROUP);

    SetParentHandler(0);

    RegisterHighlightHandler(mmi_imps_hilite_sel_group);

    for (i = 0; i < (S32) imps_p->group_info.no_group; i++)
    {
        group = &imps_p->group_info.group_list[i];

        /* if group name is not empty */
        if (mmi_ucs2strlen((S8*) group->group_name))
        {
            mmi_imps_util_copy_with_dot((S8*) group->group_name, (S8*) subMenuData[i], MAX_SUBMENU_CHARACTERS);
        }
        else
        {
            mmi_imps_util_ansi_2_ucs2_menu((S8*) group->group_id, (S8*) subMenuData[i], MAX_SUBMENU_CHARACTERS);
        }

        mmi_imps_util_generate_name_hint((S8*) NULL, i, MAX_SUBMENU_CHARACTERS);

        subMenuDataPtrs[i] = subMenuData[i];
    }

    ShowCategory53Screen(
        STR_ID_IMPS_SELECT_GROUP,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (S32) imps_p->group_info.no_group,
        (U8 **) subMenuDataPtrs,
        (U16*) gIndexIconsImageList,
        (U8 **) hintDataPtrs,
        0,
        0,
        guiBuffer);

    /* entry from search contact or watcher list */
    if (IsScreenPresent(SCR_ID_IMPS_SEARCH_RESULT) || IsScreenPresent(SCR_ID_IMPS_WATCHER_LIST))
    {
        SetLeftSoftkeyFunction(mmi_imps_pre_entry_input_name, KEY_EVENT_UP);
    }
    else
    {
        SetLeftSoftkeyFunction(mmi_imps_pre_entry_add_direct, KEY_EVENT_UP);
    }

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_sel_group
 * DESCRIPTION
 *  Highlight handler of group list for selecting item.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_sel_group(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    imps_p->group_info.curr_item = (U8) index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_pre_entry_input_name
 * DESCRIPTION
 *  Pre-entry function of input name screen when adding contact
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_pre_entry_input_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_entity_struct *sel_entity = &imps_p->search_result.entity[imps_p->search_result.curr_item];

    /* alias */
    if (mmi_ucs2strlen((S8*) sel_entity->sname))
    {
        mmi_ucs2cpy((S8*) imps_p->file_buff, (S8*) sel_entity->sname);
    }
    else
    {
        imps_p->file_buff[0] = 0;
    }
    mmi_imps_entry_cont_input_name();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_cont_input_name
 * DESCRIPTION
 *  Input display name of contact
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_cont_input_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_IMPS_ADD_CONT_INPUT_NAME, NULL, mmi_imps_entry_cont_input_name, NULL);

    SetParentHandler(0);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMPS_ADD_CONT_INPUT_NAME);

    /* reuse file_buff */
    ShowCategory5Screen(
        STR_ID_IMPS_DISPLAY_NAME,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        (U8*) imps_p->file_buff,
        IMPS_MAX_NAME_LEN,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_imps_entry_add_cont_input_name_opt, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_add_cont_input_name_opt
 * DESCRIPTION
 *  Option screen for input name option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_add_cont_input_name_opt(void)
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
    EntryNewScreen(SCR_ID_IMPS_ADD_CONT_INPUT_NAME_OPT, NULL, mmi_imps_entry_add_cont_input_name_opt, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMPS_ADD_CONT_INPUT_NAME_OPT);

    SetParentHandler(MENU_ID_IMPS_CONT_ADD_NAME_OPT);
    numItems = GetNumOfChild(MENU_ID_IMPS_CONT_ADD_NAME_OPT);
    GetSequenceStringIds(MENU_ID_IMPS_CONT_ADD_NAME_OPT, nStrItemList);
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
 *  mmi_imps_hilite_input_name_opt_done
 * DESCRIPTION
 *  Start adding contact list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_input_name_opt_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsScreenPresent(SCR_ID_IMPS_ABOUT_FRIEND))  /* about friend */
    {
        SetLeftSoftkeyFunction(mmi_imps_about_friend_edit_done, KEY_EVENT_UP);
    }
    else    /* add contact list */
    {
        SetLeftSoftkeyFunction(mmi_imps_add_cont_done, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_add_cont_done
 * DESCRIPTION
 *  Start adding contact
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_add_cont_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* display progressing screen */
    mmi_imps_display_progressing();

    imps_p->cont_info.add_type = IMPS_ADD_CONT_SEARCH;

#ifdef IMPS_TEST_CODE
    mmi_imps_add_cont_finished(0);
#else /* IMPS_TEST_CODE */ 
    mmi_imps_add_cont_req(
        imps_p->group_info.group_list[imps_p->group_info.curr_item].group_id,
        imps_p->search_result.entity[imps_p->search_result.curr_item].id,
        (S8*) imps_p->file_buff);

#endif /* IMPS_TEST_CODE */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_add_cont_finished
 * DESCRIPTION
 *  Callback function when finishing adding a contact
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_add_cont_finished(S32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 
     * partial success, subscribe error (server not support)
     * regard it as success
     */
    if (result == 0 || result == IMPS_ERROR_SUBSCRIPTION_NOT_SUPPORT)   /* IMPS_OK */
    {
        /* add contact to local-saved file */
        mmi_imps_cont_struct *cont = &imps_p->cont_info.cont_list[imps_p->cont_info.no_cont];
        mmi_imps_entity_struct *sel_entity;

        memset(cont, 0, sizeof(mmi_imps_cont_struct));

        /* contact id */
        if (imps_p->cont_info.add_type == IMPS_ADD_CONT_SEARCH)
        {
            sel_entity = &imps_p->search_result.entity[imps_p->search_result.curr_item];
            strcpy((S8*) cont->id, (S8*) sel_entity->id);
        }
        else
        {
            mmi_ucs2_to_asc((S8*) cont->id, (S8*) imps_p->path_buff);
        }

        if (mmi_ucs2strlen((S8*) imps_p->file_buff))
        {
            mmi_ucs2cpy((S8*) cont->nick_name, (S8*) imps_p->file_buff);
        }

        /* status */
        cont->availability = IMPS_PA_USER_NOT_AVAILABLE;

        strcpy((S8*) cont->group_id, (S8*) imps_p->group_info.group_list[imps_p->group_info.curr_item].group_id);
        imps_p->group_info.group_list[imps_p->group_info.curr_item].no_users++;

        /* MMI_ASSERT(imps_p->group_info.group_list[imps_p->group_info.curr_item].no_users <= IMPS_MAX_ENTITY_NUMBER); */

        imps_p->cont_info.no_cont++;
        mmi_imps_util_write_cont();

        /* clear gui buffer when re-entry contact list */
        imps_p->cont_info.clear_gui_buff = TRUE;
        mmi_imps_util_write_group();

        mmi_imps_util_disp_popup_done();
    }
    else
    {
        mmi_imps_util_disp_err_popup(mmi_imps_util_get_err_str(result));
    }

    if (imps_p->gen_info.is_reentry)
    {
        mmi_imps_re_entry_app();
    }
    else
    {
        if (imps_p->cont_info.no_cont == IMPS_MAX_NO_CONT)
        {
            mmi_imps_util_del_scr_after_progress(SCR_ID_IMPS_CONT_OPT);
        }
        else
        {
            if (imps_p->cont_info.add_type == IMPS_ADD_CONT_SEARCH)
            {
                mmi_imps_util_del_scr_after_progress(SCR_ID_IMPS_SEARCH_RESULT);
            }
            else
            {
                mmi_imps_util_del_scr_after_progress(SCR_ID_IMPS_ADD_CONT);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_add_direct
 * DESCRIPTION
 *  Highlight handler of Add Contact -> Add Directly option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_add_direct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_entry_sel_group, KEY_EVENT_UP);
    SetKeyHandler(mmi_imps_entry_sel_group, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_pre_entry_add_direct
 * DESCRIPTION
 *  Pre-Entry function for Add Contact -> Add Directly option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_pre_entry_add_direct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    imps_p->file_buff[0] = 0;   /* reuse path and file buffer */

    /* keneng : mark it as add contact */
    imps_p->add_cause = IMPS_ADD_CONTACT;

    mmi_ucs2cpy((S8*) imps_p->path_buff, g_imps_wv);
    mmi_imps_entry_add_direct();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_add_direct
 * DESCRIPTION
 *  Entry Add Directly option --> input name and nick name screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_add_direct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 inputBufferSize, scr_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* keneng : check if current add contact or member */
    if (imps_p->add_cause == IMPS_ADD_CONTACT)
    {
        scr_id = SCR_ID_IMPS_ADD_CONT_DIRECT;
    }
    else if (imps_p->add_cause == IMPS_ADD_MEMBER)
    {
        scr_id = SCR_ID_IMPS_ADD_MEMBER_DIRECT;
    }
    else
    {
        MMI_ASSERT(0);
    }

    EntryNewScreen(scr_id, mmi_imps_exit_add_direct, NULL, NULL);

    InitializeCategory57Screen();

    mmi_imps_add_direct_fill_inline_struct();

    guiBuffer = GetCurrGuiBuffer(scr_id);

    inputBuffer = GetCurrNInputBuffer(scr_id, &inputBufferSize);

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, IMPS_INLINE_ADD_DIRECT, inputBuffer);
    }

    ShowCategory57Screen(
        STR_ID_IMPS_ADD_DIRECTLY,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        STR_GLOBAL_EDIT,
        IMG_GLOBAL_BACK,
        STR_GLOBAL_DONE,
        IMG_GLOBAL_BACK,
        IMPS_INLINE_ADD_DIRECT,
        (U16*) g_imps_inline_icons,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_imps_add_direct_save, GoBackHistory);

    /* SetDelScrnIDCallbackHandler(scr_id, (HistoryDelCBPtr) mmi_imps_add_direct_scr_del_callback); */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_exit_add_direct
 * DESCRIPTION
 *  Exit function for Add Directly option --> input name and nick name screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_exit_add_direct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scr_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imps_p->add_cause == IMPS_ADD_CONTACT)
    {
        scr_id = SCR_ID_IMPS_ADD_CONT_DIRECT;
    }
    else if (imps_p->add_cause == IMPS_ADD_MEMBER)
    {
        scr_id = SCR_ID_IMPS_ADD_MEMBER_DIRECT;
    }
    else
    {
        MMI_ASSERT(0);
    }

    GenericExitInlineScreen(scr_id, mmi_imps_entry_add_direct);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_add_direct_fill_inline_struct
 * DESCRIPTION
 *  Fill inline structure for Direct Add contact screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_add_direct_fill_inline_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* User name */
    SetInlineItemActivation(&wgui_inline_items[0], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[0], (U8*) GetString(STR_ID_IMPS_USERNAME));
    SetInlineItemActivation(&wgui_inline_items[1], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[1],
        STR_ID_IMPS_USERNAME,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        (U8*) imps_p->path_buff,
        IMPS_MAX_ID_LEN,
        INPUT_TYPE_USE_ONLY_ENGLISH_MODES | INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[1], mmi_imps_hilite_prof_full_edit);

    /* Display Name */
    SetInlineItemActivation(&wgui_inline_items[2], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[2], (U8*) GetString(STR_ID_IMPS_DISPLAY_NAME));
    SetInlineItemActivation(&wgui_inline_items[3], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[3],
        STR_ID_IMPS_DISPLAY_NAME,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        (U8*) imps_p->file_buff,
        IMPS_MAX_NAME_LEN,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[3], mmi_imps_hilite_prof_full_edit);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_add_direct_save
 * DESCRIPTION
 *  Confirmation screen for adding contact
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_add_direct_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_entry_confirm(STR_GLOBAL_ADD, mmi_imps_add_direct_save_yes, mmi_imps_util_go_back_2_hist);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_add_direct_save_yes
 * DESCRIPTION
 *  Confirm to add contact
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_add_direct_save_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *id = OslMalloc(IMPS_MAX_ID_LEN * ENCODING_LENGTH);
    imps_entity_list_struct *user_list = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2_to_asc((S8*) id, (S8*) imps_p->path_buff);

    if (imps_p->add_cause == IMPS_ADD_CONTACT)
    {
        if (mmi_imps_util_is_cont_exist(id))
        {
            mmi_imps_util_disp_err_popup(STR_ID_IMPS_CONTACT_EXIST);
        }
        else
        {
            /* display progressing screen */
            mmi_imps_display_progressing();

            imps_p->cont_info.add_type = IMPS_ADD_CONT_DIRECT;

        #ifdef IMPS_TEST_CODE
            mmi_imps_add_cont_finished(0);
        #else /* IMPS_TEST_CODE */ 
            mmi_imps_add_cont_req(
                imps_p->group_info.group_list[imps_p->group_info.curr_item].group_id,
                (U8*) id,
                (S8*) imps_p->file_buff);

        #endif /* IMPS_TEST_CODE */ 
        }
    }
    else if (imps_p->add_cause == IMPS_ADD_MEMBER)
    {

        /* display progressing screen */
        mmi_imps_display_progressing();

        DeleteScreenIfPresent(SCR_ID_IMPS_ADD_MEMBER_DIRECT);

        user_list = OslMalloc(sizeof(imps_entity_list_struct));

        memset(user_list, 0, sizeof(imps_entity_list_struct));

        user_list->entity_count = 1;
        user_list->entity[0].entity_type = IMPS_ENTITY_TYPE_USER;
        strcpy((S8*) user_list->entity[0].id, (S8*) id);
        if (mmi_ucs2strlen((S8*) imps_p->file_buff))
        {
            mmi_ucs2cpy((S8*) user_list->entity[0].sname, (S8*) imps_p->file_buff);
        }

    #ifdef IMPS_TEST_CODE
        mmi_imps_add_member_done(0);
    #else 
        mmi_imps_ps_add_group_member_req((void*)user_list);
    #endif 
        OslMfree(user_list);

    }
    else
    {
    }

    OslMfree(id);

}


#define GROUP_IMPS


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_manage_group
 * DESCRIPTION
 *  Highlight handler of Manage Group option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_manage_group(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_entry_group, KEY_EVENT_UP);
    SetKeyHandler(mmi_imps_entry_group, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}

#ifdef IMPS_FOR_OMA_ONLY


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_group_subscribe
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_group_subscribe(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_group_struct *group = &imps_p->group_info.group_list[imps_p->group_info.curr_item];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_display_progressing();
    mmi_imps_ps_subs_group_pa_req(group->group_id);
}
#endif /* IMPS_FOR_OMA_ONLY */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_group
 * DESCRIPTION
 *  Entry Manage Group option. Display list of groups.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_group(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S32 i;
    S32 no_items;
    mmi_imps_group_info_struct *group_info = &imps_p->group_info;
    mmi_imps_group_struct *group;
	U16 lsk_str = STR_GLOBAL_OPTIONS, lsk_img = IMG_GLOBAL_OPTIONS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!imps_p->gen_info.auto_update_done)
    {
        mmi_imps_util_disp_warning_popup(STR_ID_IMPS_ERR_CONT_NOT_READY);
        return;
    }

    EntryNewScreen(SCR_ID_IMPS_GROUP, NULL, mmi_imps_entry_group, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMPS_GROUP);

    SetParentHandler(0);

    RegisterHighlightHandler(mmi_imps_hilite_group);

    if (group_info->no_group)
    {
        for (i = 0, no_items = 0; i < (S32) group_info->no_group; i++)
        {
            group = &group_info->group_list[i];
            /* if group name is not empty */
            if (mmi_ucs2strlen((S8*) group->group_name))
            {
                mmi_imps_util_copy_with_dot((S8*) group->group_name, (S8*) subMenuData[i], MAX_SUBMENU_CHARACTERS);
            }
            else
            {
                mmi_imps_util_ansi_2_ucs2_menu((S8*) group->group_id, (S8*) subMenuData[i], MAX_SUBMENU_CHARACTERS);
            }

            mmi_imps_util_generate_name_hint((S8*) NULL, i, MAX_SUBMENU_CHARACTERS);
            no_items++;
            subMenuDataPtrs[i] = subMenuData[i];
        }
    }
    else
    {
        mmi_ucs2cpy((S8*) subMenuData[0], (S8*) GetString(STR_GLOBAL_EMPTY_LIST));
        no_items = 1;
        i = 0;  /* i is reused for checking if the group is empty */
        hintDataPtrs[0] = NULL;
        subMenuDataPtrs[0] = subMenuData[0];
		lsk_str = STR_GLOBAL_ADD;
		lsk_img = IMG_GLOBAL_OK;
    }

    ShowCategory53Screen(
        STR_ID_IMPS_MANAGE_GROUPS,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        lsk_str,
        lsk_img,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (S32) no_items,
        (U8 **) subMenuDataPtrs,
        (U16*) gIndexIconsImageList,
        (U8 **) hintDataPtrs,
        0,
        imps_p->group_info.curr_item,
        guiBuffer);

    /* group is empty */
    if (i == 0)
    {
        SetLeftSoftkeyFunction(mmi_imps_pre_entry_group_create, KEY_EVENT_UP);
    }
    else
    {
        SetLeftSoftkeyFunction(mmi_imps_entry_group_opt, KEY_EVENT_UP);
        SetKeyHandler(mmi_imps_entry_group_opt, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    #ifdef IMPS_FOR_OMA_ONLY
        SetKeyHandler(mmi_imps_group_subscribe, KEY_SEND, KEY_EVENT_DOWN);
    #endif 
    }

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_group
 * DESCRIPTION
 *  Highlight handler of group items
 * PARAMETERS
 *  index       [IN]        Index of current highlighting item.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_group(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    imps_p->group_info.curr_item = (U8) index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_group_opt
 * DESCRIPTION
 *  Display option screen of Group
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_group_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 numItems;
    U16 nStrItemList[5];    /* Activate and Edit */
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_IMPS_GROUP_OPT, NULL, mmi_imps_entry_group_opt, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMPS_GROUP_OPT);
    SetParentHandler(MENU_ID_IMPS_GROUP_OPT);
    numItems = GetNumOfChild(MENU_ID_IMPS_GROUP_OPT);
    GetSequenceStringIds(MENU_ID_IMPS_GROUP_OPT, nStrItemList);
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
 *  mmi_imps_hilite_group_create
 * DESCRIPTION
 *  Highlight handler of Group -> Create
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_group_create(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_pre_entry_group_create, KEY_EVENT_UP);
    SetKeyHandler(mmi_imps_pre_entry_group_create, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_group_edit
 * DESCRIPTION
 *  Highlight handler of Group -> Edit
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_group_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    imps_p->group_info.is_created = FALSE;
    SetLeftSoftkeyFunction(mmi_imps_pre_entry_group_edit, KEY_EVENT_UP);
    SetKeyHandler(mmi_imps_pre_entry_group_edit, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_pre_entry_group_create
 * DESCRIPTION
 *  Pre-Entry function of Group -> Create. Load data before entry editing screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_pre_entry_group_create(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    imps_p->group_info.is_created = TRUE;
    mmi_imps_pre_entry_group_edit();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_pre_entry_group_edit
 * DESCRIPTION
 *  Pre-Entry function of Group -> Edit. Load data before entry editing screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_pre_entry_group_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_group_info_struct *grp_info = &imps_p->group_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (grp_info->no_group == IMPS_MAX_NO_GROUP && grp_info->is_created)
    {
        mmi_imps_util_disp_err_popup(STR_ID_IMPS_ERR_CONT_LIST_FULL);
        return;
    }

    if (grp_info->inline_edit_group == NULL)
    {
        grp_info->inline_edit_group = OslMalloc(sizeof(mmi_imps_group_info_struct));
    }

    if (grp_info->is_created)   /* create groupd */
    {
        memset(grp_info->inline_edit_group, 0, sizeof(mmi_imps_group_info_struct));
    }
    else    /* load saved data to group */
    {
        mmi_imps_group_inline_struct *grp_edit = grp_info->inline_edit_group;
        mmi_imps_group_struct *curr_grp = &imps_p->group_info.group_list[imps_p->group_info.curr_item];

        mmi_ucs2cpy((S8*) grp_edit->group_name, (S8*) curr_grp->group_name);
        grp_edit->open_status = (S32) curr_grp->open_status;
        grp_edit->open_mood = (S32) curr_grp->open_mood;
        grp_edit->open_pic = (S32) curr_grp->open_pic;
        grp_edit->open_text = (S32) curr_grp->open_text;
        grp_edit->do_not_notify = (S32) curr_grp->do_not_notify;
    }

    /* load data of current selected group */
    mmi_imps_entry_group_edit();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_group_edit
 * DESCRIPTION
 *  Entry function for creating or editing a group
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_group_edit(void)
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
    EntryNewScreen(SCR_ID_IMPS_GROUP_EDIT, mmi_imps_exit_group_edit, NULL, NULL);

    InitializeCategory57Screen();
    mmi_imps_group_fill_inline_struct();

    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMPS_GROUP_EDIT);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_IMPS_GROUP_EDIT, &inputBufferSize);

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, IMPS_INLINE_GROUP_EDIT, inputBuffer);
    }

    ShowCategory57Screen(
        STR_ID_IMPS_MANAGE_GROUPS,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        STR_GLOBAL_EDIT,
        IMG_GLOBAL_BACK,
        STR_GLOBAL_DONE,
        IMG_GLOBAL_BACK,
        IMPS_INLINE_GROUP_EDIT,
        (U16*) g_imps_inline_icons,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_imps_group_save, mmi_imps_group_free_mem_n_back);

    SetDelScrnIDCallbackHandler(SCR_ID_IMPS_GROUP_EDIT, (HistoryDelCBPtr) mmi_imps_group_scr_del_callback);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_group_scr_del_callback
 * DESCRIPTION
 *  Function to free memory when inline editor screen is deleted.
 * PARAMETERS
 *  param       [?]     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_imps_group_scr_del_callback(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_group_free_mem();

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_exit_group_edit
 * DESCRIPTION
 *  Exit function for creating or editing a group
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_exit_group_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GenericExitInlineScreen(SCR_ID_IMPS_GROUP_EDIT, mmi_imps_entry_group_edit);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_group_free_mem
 * DESCRIPTION
 *  Free inline editor memory for group management
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_group_free_mem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imps_p->group_info.inline_edit_group
        && imps_p->gen_info.curr_action != MSG_ID_MMI_IMPS_ADD_CONTACT_LIST_REQ
        && imps_p->gen_info.curr_action != MSG_ID_MMI_IMPS_EDIT_CONTACT_LIST_REQ)
    {
        OslMfree(imps_p->group_info.inline_edit_group);
        imps_p->group_info.inline_edit_group = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_group_free_mem_n_back
 * DESCRIPTION
 *  Free inline editor memory for group management and back to previous screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_group_free_mem_n_back(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_group_free_mem();
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_group_fill_inline_struct
 * DESCRIPTION
 *  Fill inline editor structure of a group
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_group_fill_inline_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_group_inline_struct *inline_edit_group = imps_p->group_info.inline_edit_group;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inline_edit_group->open_hide_list[0] = (U8*) GetString(STR_ID_IMPS_SHOW);
    inline_edit_group->open_hide_list[1] = (U8*) GetString(STR_ID_IMPS_HIDE);

    inline_edit_group->yes_no_list[0] = (U8*) GetString(STR_GLOBAL_YES);
    inline_edit_group->yes_no_list[1] = (U8*) GetString(STR_GLOBAL_NO);

    /* Name */
    SetInlineItemActivation(&wgui_inline_items[0], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[0], (U8*) GetString(STR_ID_IMPS_NAME));
    SetInlineItemActivation(&wgui_inline_items[1], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[1],
        STR_ID_IMPS_NAME,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        (U8*) inline_edit_group->group_name,
        IMPS_MAX_NAME_LEN,
        INPUT_TYPE_USE_ONLY_ENGLISH_MODES | INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[1], mmi_imps_hilite_prof_full_edit);

    /* Availability */
    SetInlineItemActivation(&wgui_inline_items[2], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[2], (U8*) GetString(STR_ID_IMPS_STATUS));
    SetInlineItemActivation(&wgui_inline_items[3], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(&wgui_inline_items[3], 2, inline_edit_group->open_hide_list, &inline_edit_group->open_status);

    /* My Profile */
    SetInlineItemActivation(&wgui_inline_items[4], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[4], (U8*) GetString(STR_ID_IMPS_MY_PROFILE));
    SetInlineItemActivation(&wgui_inline_items[5], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(&wgui_inline_items[5], 2, inline_edit_group->open_hide_list, &inline_edit_group->open_text);

    /* Mood */
    SetInlineItemActivation(&wgui_inline_items[6], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[6], (U8*) GetString(STR_ID_IMPS_MOOD));
    SetInlineItemActivation(&wgui_inline_items[7], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(&wgui_inline_items[7], 2, inline_edit_group->open_hide_list, &inline_edit_group->open_mood);

    /* My Picture */
    SetInlineItemActivation(&wgui_inline_items[8], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[8], (U8*) GetString(STR_ID_IMPS_MY_PICTURE));
    SetInlineItemActivation(&wgui_inline_items[9], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(&wgui_inline_items[9], 2, inline_edit_group->open_hide_list, &inline_edit_group->open_pic);

    /* Do not Notify */
    SetInlineItemActivation(&wgui_inline_items[10], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[10], (U8*) GetString(STR_ID_IMPS_SUBSCRIBE_NOTIFY));
    SetInlineItemActivation(&wgui_inline_items[11], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(&wgui_inline_items[11], 2, inline_edit_group->yes_no_list, &inline_edit_group->do_not_notify);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_group_save
 * DESCRIPTION
 *  Display confirmation screen for saving group information
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_group_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_entry_confirm(STR_GLOBAL_SAVE, mmi_imps_group_save_yes, mmi_imps_util_go_back_2_hist);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_group_save_yes
 * DESCRIPTION
 *  Confirm to save group information
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_group_save_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_group_inline_struct *grp_edit = imps_p->group_info.inline_edit_group;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((S8*) grp_edit->group_name) == 0)
    {
        mmi_imps_util_disp_err_popup(STR_ID_IMPS_ERR_EMPTY_NAME);
        return;
    }
    else if (mmi_imps_util_is_group_name_valid((S8*) grp_edit->group_name) == FALSE)
    {
        mmi_imps_util_disp_err_popup(STR_ID_IMPS_INVALID_GROUP_NAME);
        return;
    }

    /* display progressing screen for group */
    mmi_imps_display_progressing();

#ifdef IMPS_TEST_CODE
    /* write group data to FS */
    mmi_imps_util_write_group();
    mmi_imps_util_disp_popup_done();
    DeleteUptoScrID(SCR_ID_IMPS_GROUP);
#else /* IMPS_TEST_CODE */ 
    /* send request to update group information */
    if (imps_p->group_info.is_created == FALSE)
    {
        mmi_imps_ps_edit_contact_list_req();
    }
    else
    {
        mmi_imps_ps_add_contact_list_req();
    }
#endif /* IMPS_TEST_CODE */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_group_edit_done
 * DESCRIPTION
 *  Callback function when finish groud edit/create
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  result      IN    error code(?)(?)(?)(?)
 *****************************************************************************/
void mmi_imps_group_edit_done(S32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == IMPS_OK)
    {
        /* update context */
        mmi_imps_group_inline_struct *grp_edit = imps_p->group_info.inline_edit_group;
        mmi_imps_group_struct *curr_grp;

        /* fill data to group list */
        if (imps_p->group_info.is_created)  /* create groupd */
        {
            imps_p->group_info.curr_item = imps_p->group_info.no_group;
            imps_p->group_info.no_group++;
        }

        curr_grp = &imps_p->group_info.group_list[imps_p->group_info.curr_item];

        mmi_ucs2cpy((S8*) curr_grp->group_name, (S8*) grp_edit->group_name);
        curr_grp->open_status = (U8) grp_edit->open_status;
        curr_grp->open_mood = (U8) grp_edit->open_mood;
        curr_grp->open_pic = (U8) grp_edit->open_pic;
        curr_grp->open_text = (U8) grp_edit->open_text;
        curr_grp->do_not_notify = (U8) grp_edit->do_not_notify;

        /* generate group id */
        if (imps_p->group_info.is_created)  /* create groupd */
        {
            S8 *buff = OslMalloc(IMPS_MAX_ID_LEN);
            U32 len, i = 0;

            /* generate group id */
            mmi_ucs2_to_asc((S8*) buff, (S8*) grp_edit->group_name);
            len = strlen((S8*) imps_p->act_prof.username);
            while (imps_p->act_prof.username[i] != '@' && i < len) i++;
            strncpy((S8*) curr_grp->group_id, (S8*) imps_p->act_prof.username, i);
            sprintf((S8*) &curr_grp->group_id[i], "/%s%s", buff, &imps_p->act_prof.username[i]);            

            OslMfree(buff);

            curr_grp->no_users = 0;
        }
        mmi_imps_util_write_group();
        mmi_imps_util_disp_popup_done();
    }
    else
    {
        mmi_imps_util_disp_err_popup(mmi_imps_util_get_err_str(result));
    }

    if (imps_p->gen_info.is_reentry)
    {
        mmi_imps_re_entry_app();
    }
    else
    {
        mmi_imps_util_del_scr_after_progress(SCR_ID_IMPS_GROUP);        /* delete screen between group list and progressing screen */
    }

    /* free dynamic alloacted buffer */
    mmi_imps_group_free_mem();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_group_del
 * DESCRIPTION
 *  Highlight handler of Group -> Delete
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_group_del(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_entry_group_del, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_group_del
 * DESCRIPTION
 *  Display confirmation screen for deleting a group
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_group_del(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imps_p->group_info.group_list[imps_p->group_info.curr_item].no_users > 0)
    {
        mmi_imps_util_disp_err_popup(STR_ID_IMPS_GROUP_NOT_EMPTY);
        return;
    }

    mmi_imps_entry_confirm(STR_GLOBAL_DELETE, mmi_imps_group_del_yes, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_group_del_yes
 * DESCRIPTION
 *  Proceed deleting group process
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_group_del_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_display_progressing();

#ifdef IMPS_TEST_CODE
    mmi_imps_group_del_done(0);
#else 
    mmi_imps_ps_del_contact_list_req();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_group_del_done
 * DESCRIPTION
 *  Callback function after deleting complete
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_group_del_done(S32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == 0 /* IMPS_OK */ )
    {
        S32 i = (S32) imps_p->group_info.curr_item;

        /* delete entry from RAM */
        if (i == (IMPS_MAX_NO_GROUP - 1))   /* last item */
        {
            memset(&imps_p->group_info.group_list[i], 0, sizeof(mmi_imps_group_struct));
        }
        else
        {
            memcpy(
                &imps_p->group_info.group_list[i],
                &imps_p->group_info.group_list[i + 1],
                sizeof(mmi_imps_group_struct) * (IMPS_MAX_NO_GROUP - i - 1));
        }

        imps_p->group_info.no_group--;

        mmi_imps_util_write_group();

        /* delete entry from file */
        mmi_imps_util_disp_popup_done();
    }
    else
    {
        mmi_imps_util_disp_err_popup(mmi_imps_util_get_err_str(result));
    }

    if (imps_p->gen_info.is_reentry)
    {
        mmi_imps_re_entry_app();
    }
    else
    {
        mmi_imps_util_del_scr_after_progress(SCR_ID_IMPS_GROUP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_group_list_member
 * DESCRIPTION
 *  Highlight handler of Group -> List Member
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_group_list_member(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_pre_entry_group_list_member, KEY_EVENT_UP);
    SetKeyHandler(mmi_imps_pre_entry_group_list_member, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_pre_entry_group_list_member
 * DESCRIPTION
 *  Pre-Entry function of Group -> List Member. Construct list to display
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_pre_entry_group_list_member(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;
    S32 no_cont = (S32) imps_p->cont_info.no_cont;
    S32 count = 0;
    U8 *group_id = &imps_p->group_info.group_list[imps_p->group_info.curr_item].group_id[0];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0, j = 0; i < no_cont; i++)
    {
        mmi_imps_cont_struct *cont = &imps_p->cont_info.cont_list[i];

        if (mmi_imps_util_is_id_same((S8*) cont->group_id, (S8*) group_id))
        {
            mmi_imps_util_ansi_2_ucs2_menu((S8*) cont->id, (S8*) subMenuData[j], MAX_SUBMENU_CHARACTERS);
            subMenuDataPtrs[j] = subMenuData[j];
            mmi_imps_util_generate_name_hint((S8*) cont->nick_name, j, MAX_SUBMENU_CHARACTERS);
            count++;
            j++;
        }
    }

    imps_p->group_info.group_list[imps_p->group_info.curr_item].no_users = (U8) j;

    mmi_imps_entry_group_list_member();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_group_list_member
 * DESCRIPTION
 *  Entry function of Group -> List Member
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_group_list_member(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imps_p->group_info.group_list[imps_p->group_info.curr_item].no_users == 0)
    {
        mmi_imps_util_disp_empty_popup();
    }
    else
    {
        U8 *guiBuffer;
        S32 i;
        U16 icon_list[IMPS_MAX_NO_CONT];
        S32 count = imps_p->group_info.group_list[imps_p->group_info.curr_item].no_users;
        for (i = 0; i < count; i++)
        {
            icon_list[i] = IMG_ID_IMPS_ABOUT_ONLINE;
        }

        EntryNewScreen(SCR_ID_IMPS_LIST_GROUP_MEMBER, NULL, mmi_imps_pre_entry_group_list_member, NULL);

        guiBuffer = GetCurrGuiBuffer(SCR_ID_IMPS_LIST_GROUP_MEMBER);

        SetParentHandler(0);

        ShowCategory53Screen(
            STR_ID_IMPS_LIST_MEMBER,
            GetRootTitleIcon(MENU_ID_IMPS_MAIN),
            0,
            0,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            (S32) count,
            (U8 **) subMenuDataPtrs,
            (U16*) icon_list,
            (U8 **) hintDataPtrs,
            0,
            0,
            guiBuffer);

        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    }
}


#ifdef IMPS_FOR_OMA_ONLY


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_subscribe
 * DESCRIPTION
 *  Highlight handler of Subscribe Presence menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_subscribe(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_entry_subscribe, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_unsubscribe
 * DESCRIPTION
 *  Highlight handler of Unsubscribe Presence menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_unsubscribe(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_entry_unsubscribe, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_subscribe
 * DESCRIPTION
 *  Entry function for Subscribe Presence menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_subscribe(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    imps_entity_list_struct *id_list = OslMalloc(sizeof(imps_entity_list_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_display_progressing();
    
    memset(id_list, 0, sizeof(imps_entity_list_struct));
    id_list->entity_count = 1;
    id_list->entity.entity_type = IMPS_ENTITY_TYPE_USER;
    strcpy(id_list->entity.id,imps_p->cont_info.cont_list[imps_p->cont_info.curr_cont].id); 

    mmi_imps_ps_subs_pa_req((void*) id_list);

    OslMfree(id_list);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_unsubscribe
 * DESCRIPTION
 *  Entry function for Unsubscribe Presence menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_unsubscribe(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_display_progressing();

    mmi_imps_ps_unsubs_pa_req((S8*) imps_p->cont_info.cont_list[imps_p->cont_info.curr_cont].id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_group_broadcast
 * DESCRIPTION
 *  Highlight handler of Group Broadcast menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_group_broadcast(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_entry_group_broadcast, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_group_broadcast
 * DESCRIPTION
 *  Entry function of Group Broadcast menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_group_broadcast(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_IMPS_GROUP_BROADCAST, NULL, mmi_imps_entry_group_broadcast, NULL);

    SetParentHandler(0);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMPS_INVITE_NOTE);

    if (guiBuffer == NULL)  /* first time entry, reset input buffer */
    {
        imps_p->path_buff[0] = 0;
    }

    ShowCategory5Screen(
        STR_ID_IMPS_BROADCAST,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        STR_GLOBAL_SEND,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        (U8*) imps_p->path_buff,    /* reuse path buffer */
        IMPS_MAX_NOTE_LEN,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_imps_group_broadcast_done, KEY_EVENT_UP);

    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_group_broadcast_done
 * DESCRIPTION
 *  Proceed broadcasting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_group_broadcast_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_display_progressing();
    mmi_imps_ps_broadcast_msg_req(imps_p->group_info.curr_item, (S8*) imps_p->path_buff);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_group_broadcast_finished
 * DESCRIPTION
 *  Broadcast finished
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_group_broadcast_finished(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_util_disp_popup_done();
    mmi_imps_util_del_scr_after_progress(SCR_ID_IMPS_GROUP);
}

#endif /* IMPS_FOR_OMA_ONLY */ 

#endif /* __MMI_IMPS__ */ /* #ifdef __MMI_IMPS__ */


