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
 * mmi_imps_chat.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements all chat related functions for IMPS application.
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



#include "Wgui_tab_bars.h"
#include "PhoneSetupGprots.h"
#include "Conversions.h"

#include "IMPSResDef.h"
#include "mmi_imps_prot.h"

#include "FileManagerGProt.h"
#include "Fmt_struct.h"

#include "App_mine.h"

#ifdef __DRM_SUPPORT__
#include "Drm_gprot.h"
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
const S8 g_imps_wv[] = { 'w', '\0', 'v', '\0', ':', '\0', '\0', '\0' }; /* wv: */

/* string of mood */
const S8 *const g_imps_mood_str[IMPS_NUM_MOOD] = 
{
    (S8 *) L":)",
    (S8 *) L":(",
    (S8 *) L":@",
    (S8 *) L"^ol",
    (S8 *) L":$",
    (S8 *) L";)",
    (S8 *) L"(L)",
    (S8 *) L"|-)",
    (S8 *) L"+o(",
    (S8 *) L":|",
    (S8 *) L":s"
};

/* mapping table of mood and icons */
static wgui_multiline_icon_struct g_imps_mood_icon_list[IMPS_NUM_MOOD] = 
{
    {NULL, 0, 0, ":)"},
    {NULL, 0, 0, ":("},
    {NULL, 0, 0, ":@"},
    {NULL, 0, 0, "^ol"},
    {NULL, 0, 0, ":$"},
    {NULL, 0, 0, ";)"},
    {NULL, 0, 0, "(L)"},
    {NULL, 0, 0, "|-)"},
    {NULL, 0, 0, "+o("},
    {NULL, 0, 0, ":|"},
    {NULL, 0, 0, ":s"}
};


/* indexing icons for inline editor */
const U16 g_imps_inline_icons[30] = 
{
    IMG_GLOBAL_L1, 0,
    IMG_GLOBAL_L2, 0,
    IMG_GLOBAL_L3, 0,
    IMG_GLOBAL_L4, 0,
    IMG_GLOBAL_L5, 0,
    IMG_GLOBAL_L6, 0,
    IMG_GLOBAL_L7, 0,
    IMG_GLOBAL_L8, 0,
    IMG_GLOBAL_L9, 0,
    IMG_GLOBAL_L10, 0,
    IMG_GLOBAL_L11, 0,
    IMG_GLOBAL_L12, 0,
    IMG_GLOBAL_L13, 0,
    IMG_GLOBAL_L14, 0,    
    IMG_GLOBAL_L15, 0    
};


/* prefix of UCS2 file */
const U8 g_imps_ucs2_file_prefix[2] = {0xFF, 0xFE};

/***************************************************************************** 
* Local Function
*****************************************************************************/
static void mmi_imps_pre_entry_chat_list_rejected(void);
static void mmi_imps_get_rejected_user_abort(void);

/***************************************************************************** 
* Global Variable
*****************************************************************************/

extern wgui_inline_item wgui_inline_items[];

/***************************************************************************** 
* Global Function
*****************************************************************************/


#ifdef IMPS_TEST_CODE

/*****************************************************************************
 * FUNCTION
 *  mmi_imps_test_chat_key_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_test_chat_key_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    imps_entity_struct entity;
    mmi_imps_room_struct *room = &imps_p->room_info.room_list[imps_p->chat_info.curr_room];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_to_ucs2((S8*) entity.sname, (S8*) "Joooo");
    mmi_imps_chat_recv_msg((U16*) L"I am Max!!!", imps_p->chat_info.curr_room, &entity, FALSE, NULL);
    UpdateCategory435LogText((U8*) room->chat_buff, mmi_ucs2strlen((S8*) room->chat_buff));
}
#endif /* IMPS_TEST_CODE */ 



/*****************************************************************************
 * FUNCTION
 *  mmi_imps_init_chat_hilite_hdlr
 * DESCRIPTION
 *  Initialize all chat highlight handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_init_chat_hilite_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    SetHiliteHandler(MENU_ID_IMPS_CONT_SEND_MSG, mmi_imps_hilite_cont_send_msg);        
    SetHiliteHandler(MENU_ID_IMPS_CONT_BLOCK_GRANT, mmi_imps_hilite_block_grant);
    SetHiliteHandler(MENU_ID_IMPS_CONT_CHAT_ROOMS, mmi_imps_hilite_chat_room);
    
    /* chat */
    SetHiliteHandler(MENU_ID_IMPS_CHAT_OPT_WRITE, mmi_imps_hilite_chat_write);
    SetHiliteHandler(MENU_ID_IMPS_CHAT_OPT_SEND, mmi_imps_hilite_chat_send);
    SetHiliteHandler(MENU_ID_IMPS_CHAT_OPT_INVITE, mmi_imps_hilite_chat_invite);
    SetHiliteHandler(MENU_ID_IMPS_CHAT_OPT_INSERT_SYMBOL, mmi_imps_hilite_chat_insert_symbol);
    SetHiliteHandler(MENU_ID_IMPS_CHAT_OPT_LIST_MEMBER, mmi_imps_hilite_chat_member);
    SetHiliteHandler(MENU_ID_IMPS_CHAT_OPT_SAVE_TEXT, mmi_imps_hilite_chat_save);
    SetHiliteHandler(MENU_ID_IMPS_CHAT_OPT_CLOSE, mmi_imps_hilite_chat_close);
    SetHiliteHandler(MENU_ID_IMPS_CHAT_OPT_INPUT_METH, mmi_imps_hilite_comm_input_meth);
    SetHiliteHandler(MENU_ID_IMPS_CHAT_OPT_SEND_DONE, mmi_imps_hilite_chat_send_done);
    SetHiliteHandler(MENU_ID_IMPS_CHAT_SAVE_OPT_DONE, mmi_imps_hilite_chat_save_opt_done);
    SetHiliteHandler(MENU_ID_IMPS_CHAT_SAVE_OPT_INPUT_METH, mmi_imps_hilite_comm_input_meth);
    SetHiliteHandler(MENU_ID_IMPS_CHAT_OPT_TEXT_FORMAT, mmi_imps_hilite_chat_text_format);
    SetHiliteHandler(MENU_ID_IMPS_CHAT_OPT_SEND_FILE, mmi_imps_hilite_chat_send_file);
    
    SetHiliteHandler(MENU_ID_IMPS_CHAT_ADD_MEMBER, mmi_imps_hilite_chat_add_member);
    SetHiliteHandler(MENU_ID_IMPS_CHAT_LIST_REJECTED, mmi_imps_hilite_chat_list_rejected);
    SetHiliteHandler(MENU_ID_IMPS_CHAT_LIST_JOINED, mmi_imps_hilite_chat_list_joined);
    SetHiliteHandler(MENU_ID_IMPS_CHAT_ADD_MEMBER_DIRECTLY, mmi_imps_hilite_chat_add_directly);
    SetHiliteHandler(MENU_ID_IMPS_CHAT_ADD_MEMBER_FROM_ONLINE, mmi_imps_hilite_chat_add_from_online);
    SetHiliteHandler(MENU_ID_IMPS_CHAT_LIST_MEMBER_OPT_DEL, mmi_imps_hilite_chat_del_member);
    SetHiliteHandler(MENU_ID_IMPS_CHAT_LIST_MEMBER_OPT_SET_MOD_USER, mmi_imps_hilite_chat_set_mod_user);
    SetHiliteHandler(MENU_ID_IMPS_CHAT_LIST_JOINED_OPT_ADD_MEM, mmi_imps_hilite_chat_add_to_mem);
    SetHiliteHandler(MENU_ID_IMPS_CHAT_LIST_JOINED_OPT_ADD_REJ, mmi_imps_hilite_chat_add_to_rejected);
        
    /* chat room */
    SetHiliteHandler(MENU_ID_IMPS_ROOM_OPT_JUMP_TO, mmi_imps_hilite_room_jump_to);
    SetHiliteHandler(MENU_ID_IMPS_ROOM_OPT_CREATE, mmi_imps_hilite_room_open);
    SetHiliteHandler(MENU_ID_IMPS_ROOM_OPT_SEARCH, mmi_imps_hilite_room_search);
    SetHiliteHandler(MENU_ID_IMPS_ROOM_OPT_CLOSE, mmi_imps_hilite_room_close);
    SetHiliteHandler(MENU_ID_IMPS_ROOM_OPT_JOIN, mmi_imps_hilite_room_join);

    SetHiliteHandler(MENU_ID_IMPS_ROOM_INVITE_OPT_DONE, mmi_imps_hilite_invite_note_opt_done);
    SetHiliteHandler(MENU_ID_IMPS_ROOM_INVITE_OPT_INPUT_METH, mmi_imps_hilite_comm_input_meth);

#ifdef IMPS_FOR_OMA_ONLY    
    SetHiliteHandler(MENU_ID_IMPS_GROUP_OPT_BROADCAST, mmi_imps_hilite_group_broadcast);
#endif /* IMPS_FOR_OMA_ONLY */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_init_icon_list
 * DESCRIPTION
 *  Initialize mood icon mapping table
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_init_mood_icon_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 width, height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* initialize mood table */
    for (i = 0; i < IMPS_NUM_MOOD; i++)
    {
        /* file icons */
        g_imps_mood_icon_list[i].icon = (PU8) GetImage((U16) (IMG_ID_IMPS_HAPPY + i));

        /* measure height and width */
        gui_measure_image(g_imps_mood_icon_list[i].icon, &width, &height);
        g_imps_mood_icon_list[i].icon_height = (U8) height;
        g_imps_mood_icon_list[i].icon_width = (U8) width;
    }
}

#define CHAT_IMPS


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_cont_send_msg
 * DESCRIPTION
 *  Highlight handler of Send/Read Message option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_cont_send_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_pre_entry_chat, KEY_EVENT_UP);
    SetKeyHandler(mmi_imps_pre_entry_chat, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_pre_entry_chat
 * DESCRIPTION
 *  Pre-Entry function of chat room
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_pre_entry_chat(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U8 *id;
    UI_character_type *nick_name;
    U8 new_room = TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    id = &imps_p->cont_info.cont_list[imps_p->cont_info.curr_cont].id[0];
    nick_name = &imps_p->cont_info.cont_list[imps_p->cont_info.curr_cont].nick_name[0];

    /* check if chat room for the friend already exists */
    for (i = 0; i < IMPS_MAX_NO_ROOM; i++)
    {
        if (imps_p->room_info.room_list[i].is_used)
        {
            /* in single room, the room id is friend's id */
            if (mmi_imps_util_is_id_same((S8*) id, (S8*) imps_p->room_info.room_list[i].room_id))
            {
                new_room = FALSE;
                break;
            }
        }
    }

    if (i == IMPS_MAX_NO_ROOM)  /* all chat rooms are occupied */
    {
        i = mmi_imps_util_get_empty_room_slot();
        if (i == IMPS_MAX_NO_ROOM)
        {
            mmi_imps_util_disp_err_popup(STR_ID_IMPS_ERR_CHAT_ROOM_FULL);
            return;
        }
    }

    if (new_room)
    {
        /* reset all data */
        mmi_imps_room_struct *room = &imps_p->room_info.room_list[i];

        memset(room, 0, sizeof(mmi_imps_room_struct));
        room->is_used = TRUE;
        room->type = IMPS_ROOM_TYPE_SINGLE;
        room->tab_index = imps_p->gen_info.curr_tab = imps_p->gen_info.no_tab;
        imps_p->gen_info.no_tab++;
        strcpy((S8*) room->room_id, (S8*) id);

        /* display be screen name if the user's alias is not empty */
        /* in single room : room id is friend's id, room->sname is friend's nick name */
        if (mmi_ucs2strlen((S8*) nick_name))
        {
            mmi_ucs2cpy((S8*) room->room_name, (S8*) nick_name);
            mmi_ucs2cpy((S8*) room->sname, (S8*) nick_name);
        }
        else
        {
            mmi_asc_to_ucs2((S8*) room->room_name, (S8*) id);
            room->sname[0] = 0;
        }

        imps_p->room_info.no_rooms++;

        /* update display buffer */
        mmi_imps_new_room_string((S8*) room->chat_buff, (S8*) room->room_name);

    }
    else
    {
        imps_p->gen_info.curr_tab = (U8) imps_p->room_info.room_list[i].tab_index;
    }

    imps_p->chat_info.curr_room = (U8) i;

    imps_p->chat_info.sel_color = 0;
    imps_p->chat_info.sel_size = 0;
    imps_p->chat_info.sel_style = 0;
    
    mmi_imps_entry_chat();
    DeleteScreenIfPresent(SCR_ID_IMPS_CONT_OPT);
    DeleteScreenIfPresent(SCR_ID_IMPS_CONT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_chat_show_input_screen
 * DESCRIPTION
 *  Show input editor in chatting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_chat_show_input_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Category435ShowPopup(TRUE);
    imps_p->room_info.room_list[imps_p->chat_info.curr_room].edit_mode = TRUE;
    SetKeyHandler(mmi_imps_chat_send_key_hdlr, KEY_SEND, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_chat_hide_input_screen
 * DESCRIPTION
 *  Hide input editor in chatting screen
 * PARAMETERS
 *  redraw      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_chat_hide_input_screen(BOOL redraw)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Category435HidePopup(redraw);
    imps_p->room_info.room_list[imps_p->chat_info.curr_room].edit_mode = FALSE;
    mmi_imps_chat_register_key_hdlr();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_chat_register_key_hdlr
 * DESCRIPTION
 *  Register key handlers for chatting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_chat_register_key_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 keyCodes[] = {KEY_0, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_STAR, KEY_POUND};
    U8 nKeyCodes = (U8) 12;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetCategory435RSKFunction(GoBackHistory);

    if (imps_p->room_info.room_list[imps_p->chat_info.curr_room].edit_mode == FALSE)
    {
        SetKeyHandler(mmi_imps_tab_prev, KEY_LEFT_ARROW, KEY_EVENT_DOWN);       /* move to previous tab */
        SetKeyHandler(mmi_imps_tab_next, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);      /* move to next tab */
        SetGroupKeyHandler(mmi_imps_chat_show_input_screen, keyCodes, nKeyCodes, KEY_EVENT_UP);
    }
    else
    {
        SetKeyHandler(mmi_imps_chat_send_key_hdlr, KEY_SEND, KEY_EVENT_DOWN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_chat_input_rsk_hdlr
 * DESCRIPTION
 *  RSK handler of input screen. Hide input popup screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_chat_input_rsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_chat_hide_input_screen(TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_chat
 * DESCRIPTION
 *  Entry chat room of IMPS application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_chat(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    mmi_imps_room_struct *room = &imps_p->room_info.room_list[imps_p->chat_info.curr_room];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_IMPS_CHAT, mmi_imps_exit_chat, NULL, NULL);

    /* if GUI buffer is not NULL, shall histroy shall be reset */
    if ((room->clear_gui_buff) && (room->edit_mode == FALSE))
    {
        guiBuffer = NULL;
        room->clear_gui_buff = FALSE;
    }
    else
    {
        guiBuffer = GetCurrGuiBuffer(SCR_ID_IMPS_CHAT);
    }

    if (room->edit_mode == FALSE)   /* clear buffer */
    {
        imps_p->chat_info.input_buff[0] = 0;
    }

    SetParentHandler(0);

    /* initialize tab */
    mmi_imps_tab_init();

    /* configure icons */
    wgui_config_general_multiline_icon_handler(MMI_FALSE, IMPS_NUM_MOOD, g_imps_mood_icon_list);

    ShowCategory435Screen(
        (UI_string_type) room->room_name,
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (S8) imps_p->gen_info.no_tab,
        (S8) imps_p->gen_info.curr_tab,
        MMI_tab_bar_items,
        room->edit_mode,
        NULL,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        (U8*) imps_p->chat_info.input_buff,
        IMPS_MAX_CHAT_INPUT_LEN,
        (U8*) room->chat_buff,
        mmi_ucs2strlen((S8*) room->chat_buff),
        wgui_general_multiline_icon_handler,
        (PU8) GetImage(IMG_ID_IMPS_HAPPY),
        guiBuffer);

    SetCategory435TabSelectCallback(mmi_imps_tab_jump);

    /* mark the unread message flag as FALSE */
    room->unread_msg = FALSE;

    mmi_imps_util_blink_tab();

    /* update status icon because it might be changed when new message read */
    mmi_imps_util_update_status_icon();

    /* reset message icon in contact list */
    mmi_imps_cont_reset_msg_icon();

    /* RSK/LSK handlers for editable mode */
    SetCategory435EditorRSKFunction(mmi_imps_chat_input_rsk_hdlr);
    SetCategory435EditorLSKFunction(mmi_imps_chat_input_opt);

    /* RSK/LSK handlers for read-only mode */
    SetCategory435RSKFunction(GoBackHistory);
    SetCategory435LSKFunction(mmi_imps_entry_chat_opt);

    mmi_imps_chat_register_key_hdlr();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_exit_chat
 * DESCRIPTION
 *  Exit chat room of IMPS application (128*128/128*160)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_exit_chat(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_reset_general_multiline_icon_handler();
    GenericExitScreen(SCR_ID_IMPS_CHAT, mmi_imps_entry_chat);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_chat_opt
 * DESCRIPTION
 *  Entry option screen of chat room
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_chat_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 numItems;
    U16 nStrItemList[9];
    U8 *guiBuffer;
    U16 menu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imps_p->room_info.room_list[imps_p->chat_info.curr_room].type == IMPS_ROOM_TYPE_SINGLE)
    {
        menu_id = MENU_ID_IMPS_CHAT_OPT2;
    }
    else if (imps_p->room_info.room_list[imps_p->chat_info.curr_room].pri_level == IMPS_PRI_LEVEL_USER)
    {
        /* keneng : ordinary user case */
        menu_id = MENU_ID_IMPS_CHAT_OPT;
    }
    else
    {
        menu_id = MENU_ID_IMPS_CHAT_OPT1;
    }

    EntryNewScreen(SCR_ID_IMPS_CHAT_OPT, NULL, mmi_imps_entry_chat_opt, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMPS_CHAT_OPT);

    SetParentHandler(menu_id);
    numItems = GetNumOfChild_Ext(menu_id);
    GetSequenceStringIds_Ext(menu_id, nStrItemList);
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
 *  mmi_imps_hilite_chat_write
 * DESCRIPTION
 *  Highlight handler of Chat -> Option -> Write menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_chat_write(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_entry_chat_write, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_chat_write
 * DESCRIPTION
 *  Display popup write message screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_chat_write(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* GoBackHistory();*/
    imps_p->room_info.room_list[imps_p->chat_info.curr_room].edit_mode = MMI_TRUE;
    mmi_imps_entry_chat();
    DeleteScreenIfPresent(SCR_ID_IMPS_CHAT_OPT);     
    DeleteScreenIfPresent(SCR_ID_IMPS_CHAT);   
    /* mmi_imps_chat_show_input_screen(); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_chat_send
 * DESCRIPTION
 *  Highlight handler of Send menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_chat_send(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_chat_send_done, KEY_EVENT_UP);
    SetKeyHandler(mmi_imps_chat_send_done, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_chat_send_done
 * DESCRIPTION
 *  Highlight handler of Send -> Option -> Done
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_chat_send_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_chat_send_done, KEY_EVENT_UP);
    SetKeyHandler(mmi_imps_chat_send_done, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}

#ifdef IMPS_FOR_OMA_ONLY


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_chat_private_msg
 * DESCRIPTION
 *  Check if it's a private message within a chat room
 * PARAMETERS
 *  session_id      [IN]        Id of the chat session
 *  buff            [IN]        Buffer of input message
 *  curr_room       [IN]        Index of current chat room
 * RETURNS
 *  TRUE if it's a private message; otherwise FALSE
 *****************************************************************************/
BOOL mmi_imps_chat_private_msg(S32 session_id, S16 *buff, U8 curr_room)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S16 *msg = buff;
    U32 length;
    mmi_imps_room_struct *room = &imps_p->room_info.room_list[curr_room];
    S32 count = (S32) room->no_joined;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (room->type == IMPS_ROOM_TYPE_SINGLE)
    {
        return FALSE;
    }

    for (i = 0; i < count; i++)
    {
        length = mmi_ucs2strlen((S8*) room->joined_user[i].sname);
        if (mmi_ucs2ncmp((S8*) room->joined_user[i].sname, (S8*) msg, length) == 0)
        {
            break;
        }
    }

    if (i == count)
    {
        return FALSE;
    }

    msg += length;
    if (mmi_ucs2strlen((S8*) msg))
    {
        mmi_imps_ps_send_msg_req(
            session_id,
            (S16*) msg,
            room->room_id,
            IMPS_ENTITY_TYPE_SCREEN_NAME,
            (S8*) room->joined_user[i].sname,
            FALSE);
        return TRUE;
    }
    return FALSE;
}
#endif /* IMPS_FOR_OMA_ONLY */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_chat_send_key_hdlr
 * DESCRIPTION
 *  Send key handler of chat screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_chat_send_key_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_room_struct *room = &imps_p->room_info.room_list[imps_p->chat_info.curr_room];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((S8*) imps_p->chat_info.input_buff))
    {
        S32 session_id = mmi_imps_chat_insert_session();

        /* check if there is any empty session can be used */
        if (session_id == 0)
        {
            mmi_imps_util_play_tone(IMPS_ERR_TONE);
            mmi_imps_chat_display_send_failed(imps_p->chat_info.curr_room, imps_p->chat_info.input_buff);            
        }
        else
        {
            U8 entity_type;

            mmi_imps_chat_disp_input_msg();
        #ifndef IMPS_TEST_CODE
        #ifdef IMPS_FOR_OMA_ONLY
            if (mmi_imps_chat_private_msg(session_id, (S16*) imps_p->chat_info.input_buff, imps_p->chat_info.curr_room) == FALSE)
        #endif 
            {
                if (room->type == IMPS_ROOM_TYPE_SINGLE)
                {
                    entity_type = IMPS_ENTITY_TYPE_USER;
                }
                else
                {
                    entity_type = IMPS_ENTITY_TYPE_GROUP;
                }

                mmi_imps_ps_send_msg_req(session_id, (S16*) imps_p->chat_info.input_buff, room->room_id, (U8) entity_type, NULL, TRUE);
            }
        #endif /* IMPS_TEST_CODE */ 
        }
        mmi_imps_chat_hide_input_screen(FALSE);
        UpdateCategory435LogText((U8*) room->chat_buff, (S32) mmi_ucs2strlen((S8*) room->chat_buff));
        imps_p->chat_info.input_buff[0] = 0;
    }
    else
    {
        mmi_imps_chat_hide_input_screen(TRUE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_chat_send_done
 * DESCRIPTION
 *  Highlight handler of Send -> Option -> Done
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_chat_send_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_room_struct *room = &imps_p->room_info.room_list[imps_p->chat_info.curr_room];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((S8*) imps_p->chat_info.input_buff))
    {
        S32 session_id = mmi_imps_chat_insert_session();

        /* check if there is any empty session can be used */
        if (session_id == 0)
        {
            mmi_imps_util_play_tone(IMPS_ERR_TONE);
            mmi_imps_chat_display_send_failed(imps_p->chat_info.curr_room, imps_p->chat_info.input_buff);            
        }
        else
        {
            U8 entity_type;

            mmi_imps_chat_disp_input_msg();
        #ifndef IMPS_TEST_CODE

        #ifdef IMPS_FOR_OMA_ONLY
            if (mmi_imps_chat_private_msg(session_id, (S16*) imps_p->chat_info.input_buff, imps_p->chat_info.curr_room) == FALSE)
        #endif 
            {
                if (room->type == IMPS_ROOM_TYPE_SINGLE)
                {
                    entity_type = IMPS_ENTITY_TYPE_USER;
                }
                else
                {
                    entity_type = IMPS_ENTITY_TYPE_GROUP;
                }

                mmi_imps_ps_send_msg_req(session_id, (S16*) imps_p->chat_info.input_buff, room->room_id, (U8) entity_type, NULL, TRUE);
            }
            imps_p->chat_info.input_buff[0] = 0;
        #endif /* IMPS_TEST_CODE */ 
        }
    }

    gui_lock_double_buffer();
    GoBackToHistory(SCR_ID_IMPS_CHAT);
    gui_unlock_double_buffer();
    mmi_imps_chat_hide_input_screen(FALSE);
    UpdateCategory435LogText((U8*) room->chat_buff, (S32) mmi_ucs2strlen((S8*) room->chat_buff));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_chat_input_opt
 * DESCRIPTION
 *  Entry option screen of chat input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_chat_input_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 numItems;
    U16 nStrItemList[5];
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imps_p->gen_info.imps_version < IMPS_CSP_VERSION_13)
    {
        mmi_frm_hide_menu_item(MENU_ID_IMPS_CHAT_OPT_TEXT_FORMAT);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_IMPS_CHAT_OPT_TEXT_FORMAT);
    }
    
    EntryNewScreen(SCR_ID_IMPS_CHAT_OPT, NULL, mmi_imps_chat_input_opt, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMPS_CHAT_OPT);

    SetParentHandler(MENU_ID_IMPS_CHAT_INPUT_OPT);
    numItems = GetNumOfChild_Ext(MENU_ID_IMPS_CHAT_INPUT_OPT);
    GetSequenceStringIds_Ext(MENU_ID_IMPS_CHAT_INPUT_OPT, nStrItemList);
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
 *  mmi_imps_chat_disp_input_msg
 * DESCRIPTION
 *  Insert new input message in chat room.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_chat_disp_input_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *tmp_input_buff = OslMalloc(IMPS_MAX_CHAT_BUFF * ENCODING_LENGTH);
    wgui_color_buffer_writer_struct writer;
    BOOL result;
	U16 ch;
    mmi_imps_room_struct *room = &imps_p->room_info.room_list[imps_p->chat_info.curr_room];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tmp_input_buff[0] = 0;
    wgui_color_buffer_create_writer(&writer, (U8*) tmp_input_buff, IMPS_MAX_CHAT_BUFF * ENCODING_LENGTH);
    wgui_color_buffer_write_char(&writer, GUI_INPUT_COLOR_04 /* colorrr++ */ );

    /* group talk */
    if ((room->type != IMPS_ROOM_TYPE_SINGLE) && mmi_ucs2strlen((S8*) room->sname))
    {
        wgui_color_buffer_write_char(&writer, '<');
        wgui_color_buffer_write_string(&writer, (U8*) room->sname, MMI_FALSE, &result);
        wgui_color_buffer_write_char(&writer, '>');
    }
    else
    {
        U16 *tmp_chat_buff1 = OslMalloc(IMPS_MAX_CHAT_BUFF);
        U16 *tmp_chat_buff2 = OslMalloc(IMPS_MAX_CHAT_BUFF * ENCODING_LENGTH);

        sprintf((S8*) tmp_chat_buff1, "<%s>", (S8*) imps_p->act_prof.username);
        mmi_asc_to_ucs2((S8*) tmp_chat_buff2, (S8*) tmp_chat_buff1);
        wgui_color_buffer_write_string(&writer, (U8*) tmp_chat_buff2, MMI_FALSE, &result);
        OslMfree(tmp_chat_buff1);
        OslMfree(tmp_chat_buff2);
    }

    wgui_color_buffer_write_char(&writer, GUI_INPUT_MARKER_RESET_ALL);
    wgui_color_buffer_write_string(&writer, (U8*) L"\n", MMI_FALSE, &result);
    
    /* text format */
    
    /* style */
    ch = 0;
    if (imps_p->chat_info.sel_style & IMPS_FONT_STYLE_BOLD)
    {
        ch |= GUI_INPUT_MARKER_BOLD;
    }
    if (imps_p->chat_info.sel_style & IMPS_FONT_STYLE_ITALIC)
    {
        ch |= GUI_INPUT_MARKER_ITALIC;
    }
    if (imps_p->chat_info.sel_style & IMPS_FONT_STYLE_UNDERLINE)
    {
        ch |= GUI_INPUT_MARKER_UNDERLINE;
    }
    if (ch != 0)
    {
        wgui_color_buffer_write_char(&writer, ch);
    }

    /* size */
    ch = 0;
    if (imps_p->chat_info.sel_size == IMPS_FONT_SIZE_BIG || imps_p->chat_info.sel_size == IMPS_FONT_SIZE_HUGE)
    {
        ch = GUI_INPUT_MARKER_LARGE;
    }
    else if (imps_p->chat_info.sel_size == IMPS_FONT_SIZE_MEDIUM)
    {
        ch |= GUI_INPUT_MARKER_MEDIUM;
    }
    else if (imps_p->chat_info.sel_size == IMPS_FONT_SIZE_TINY || imps_p->chat_info.sel_size == IMPS_FONT_SIZE_SMALL)
    {
        ch |= GUI_INPUT_MARKER_SMALL;
    }
    if (ch != 0)
    {
        wgui_color_buffer_write_char(&writer, ch);
    }

    /* color */
    ch = 0;
    switch (imps_p->chat_info.sel_color)
    {
        case IMPS_FONT_COLOR_BLACK:
            ch = GUI_INPUT_COLOR_BLACK;
            break;

        case IMPS_FONT_COLOR_GREEN:
            ch = GUI_INPUT_COLOR_GREEN;
            break;

        case IMPS_FONT_COLOR_SILVER:
            ch = GUI_INPUT_COLOR_SILVER;
            break;

        case IMPS_FONT_COLOR_LIME:
            ch = GUI_INPUT_COLOR_LIME;
            break;

        case IMPS_FONT_COLOR_GRAY:
            ch = GUI_INPUT_COLOR_GRAY;
            break;

        case IMPS_FONT_COLOR_OLIVE:
            ch = GUI_INPUT_COLOR_OLIVE;
            break;

        case IMPS_FONT_COLOR_WHITE:
            ch = GUI_INPUT_COLOR_WHITE;
            break;

        case IMPS_FONT_COLOR_YELLOW:
            ch = GUI_INPUT_COLOR_YELLOW;
            break;

        case IMPS_FONT_COLOR_MAROON:
            ch = GUI_INPUT_COLOR_MAROON;
            break;

        case IMPS_FONT_COLOR_NAVY:
            ch = GUI_INPUT_COLOR_NAVY;
            break;

        case IMPS_FONT_COLOR_RED:
            ch = GUI_INPUT_COLOR_RED;
            break;

        case IMPS_FONT_COLOR_BLUE:
            ch = GUI_INPUT_COLOR_BLUE;
            break;

        case IMPS_FONT_COLOR_PURPLE:
            ch = GUI_INPUT_COLOR_PURPLE;
            break;

        case IMPS_FONT_COLOR_TEAL:
            ch = GUI_INPUT_COLOR_TEAL;
            break;

        case IMPS_FONT_COLOR_FUCHSIA:
            ch = GUI_INPUT_COLOR_FUCHSIA;
            break;

        case IMPS_FONT_COLOR_AQUA:
            ch = GUI_INPUT_COLOR_AQUA;
            break;

        default:
            break;                
    }

    if (ch != 0)
    {
        wgui_color_buffer_write_char(&writer, ch);
    }
    
    wgui_color_buffer_write_string(&writer, (U8*) imps_p->chat_info.input_buff, MMI_FALSE, &result);
    wgui_color_buffer_write_char(&writer, GUI_INPUT_MARKER_RESET_ALL);    
    wgui_color_buffer_write_string(&writer, (U8*) L"\n\n", MMI_FALSE, &result);

    mmi_imps_chat_flush_msg(tmp_input_buff, (S32) imps_p->chat_info.curr_room);
    OslMfree(tmp_input_buff);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_chat_recv_msg
 * DESCRIPTION
 *  Handler when receiving a incoming message for current chat room
 * PARAMETERS
 *  ind         [?]         [?]         [?]         [?]
 *  room_id     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_chat_recv_msg(mmi_imps_newmessage_ind_struct *ind, U8 room_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *tmp_sname_buff;
    U16 *tmp_input_buff = NULL;
    S8 *temp_buff = NULL;
    wgui_color_buffer_writer_struct writer;
    BOOL result;
    mmi_imps_room_struct *room = &imps_p->room_info.room_list[room_id];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tmp_input_buff = OslMalloc(IMPS_MAX_CHAT_BUFF * ENCODING_LENGTH);
    tmp_input_buff[0] = 0;
    wgui_color_buffer_create_writer(&writer, (U8*) tmp_input_buff, IMPS_MAX_CHAT_BUFF * ENCODING_LENGTH);    
    if (ind->use_file == IMPS_CONTENT_STORE_BUF)
    {
        wgui_color_buffer_write_char(&writer, GUI_INPUT_COLOR_00);

        /* insert input into buffer */
        wgui_color_buffer_write_char(&writer, '<');
        if (mmi_ucs2strlen((S8*) ind->sender.sname) > 0)
        {
            wgui_color_buffer_write_string(&writer, (U8*) ind->sender.sname, MMI_FALSE, &result);
        }
        else
        {
            tmp_sname_buff = OslMalloc(IMPS_MAX_ID_LEN * ENCODING_LENGTH);
            mmi_asc_to_ucs2((S8*) tmp_sname_buff, (S8*) ind->sender.id);
            wgui_color_buffer_write_string(&writer, (U8*) tmp_sname_buff, MMI_FALSE, &result);
            OslMfree(tmp_sname_buff);
        }

        wgui_color_buffer_write_string(&writer, (U8*) L">\n", MMI_FALSE, &result);
        wgui_color_buffer_write_char(&writer, GUI_INPUT_MARKER_RESET_ALL);

        /* text format */
        if (ind->is_font_p)
        {
            U16 ch;
            
            /* style */
            ch = 0;
            if (ind->font.style & IMPS_FONT_STYLE_BOLD)
            {
                ch |= GUI_INPUT_MARKER_BOLD;
            }
            if (ind->font.style & IMPS_FONT_STYLE_ITALIC)
            {
                ch |= GUI_INPUT_MARKER_ITALIC;
            }
            if (ind->font.style & IMPS_FONT_STYLE_UNDERLINE)
            {
                ch |= GUI_INPUT_MARKER_UNDERLINE;
            }
            if (ch != 0)
            {
                wgui_color_buffer_write_char(&writer, ch);
            }

            /* size */
            ch = 0;
            if (ind->font.size == IMPS_FONT_SIZE_BIG || ind->font.size == IMPS_FONT_SIZE_HUGE)
            {
                ch = GUI_INPUT_MARKER_LARGE;
            }
            else if (ind->font.size == IMPS_FONT_SIZE_MEDIUM)
            {
                ch = GUI_INPUT_MARKER_MEDIUM;
            }
            else if (ind->font.size == IMPS_FONT_SIZE_TINY || ind->font.size == IMPS_FONT_SIZE_SMALL)
            {
                ch = GUI_INPUT_MARKER_SMALL;
            }
            if (ch != 0)
            {
                wgui_color_buffer_write_char(&writer, ch);
            }

            /* color */
            ch = 0;
            switch (ind->font.color)
            {
                case IMPS_FONT_COLOR_BLACK:
                    ch = GUI_INPUT_COLOR_BLACK;
                    break;

                case IMPS_FONT_COLOR_GREEN:
                    ch = GUI_INPUT_COLOR_GREEN;
                    break;

                case IMPS_FONT_COLOR_SILVER:
                    ch = GUI_INPUT_COLOR_SILVER;
                    break;

                case IMPS_FONT_COLOR_LIME:
                    ch = GUI_INPUT_COLOR_LIME;
                    break;

                case IMPS_FONT_COLOR_GRAY:
                    ch = GUI_INPUT_COLOR_GRAY;
                    break;

                case IMPS_FONT_COLOR_OLIVE:
                    ch = GUI_INPUT_COLOR_OLIVE;
                    break;

                case IMPS_FONT_COLOR_WHITE:
                    ch = GUI_INPUT_COLOR_WHITE;
                    break;

                case IMPS_FONT_COLOR_YELLOW:
                    ch = GUI_INPUT_COLOR_YELLOW;
                    break;

                case IMPS_FONT_COLOR_MAROON:
                    ch = GUI_INPUT_COLOR_MAROON;
                    break;

                case IMPS_FONT_COLOR_NAVY:
                    ch = GUI_INPUT_COLOR_NAVY;
                    break;

                case IMPS_FONT_COLOR_RED:
                    ch = GUI_INPUT_COLOR_RED;
                    break;

                case IMPS_FONT_COLOR_BLUE:
                    ch = GUI_INPUT_COLOR_BLUE;
                    break;

                case IMPS_FONT_COLOR_PURPLE:
                    ch = GUI_INPUT_COLOR_PURPLE;
                    break;

                case IMPS_FONT_COLOR_TEAL:
                    ch = GUI_INPUT_COLOR_TEAL;
                    break;

                case IMPS_FONT_COLOR_FUCHSIA:
                    ch = GUI_INPUT_COLOR_FUCHSIA;
                    break;

                case IMPS_FONT_COLOR_AQUA:
                    ch = GUI_INPUT_COLOR_AQUA;
                    break;

                default:
                    break;                
            }

            if (ch != 0)
            {
                wgui_color_buffer_write_char(&writer, ch);
            }    
        }
        wgui_color_buffer_write_string(&writer, (U8*) ind->message_content, MMI_FALSE, &result);
        wgui_color_buffer_write_char(&writer, GUI_INPUT_MARKER_RESET_ALL);
        wgui_color_buffer_write_string(&writer, (U8*) L"\n\n", MMI_FALSE, &result);   

        mmi_imps_chat_flush_msg(tmp_input_buff, (S32) room_id);
        room->clear_gui_buff = TRUE;         
    }
    else if (ind->use_file == IMPS_CONTENT_STORE_FILE)
    {
        S32 fd;
        S32 ret;
        temp_buff = OslMalloc(FMGR_MAX_PATH_LEN + 1);
        imps_p->path_buff[0] = 0;
        sprintf(temp_buff, "%c:\\", IMPS_PUBLIC_DRV);
        mmi_asc_to_ucs2((S8*) imps_p->path_buff, (S8*) temp_buff);
        mmi_ucs2cat((S8*) imps_p->path_buff, (S8*) IMPS_DEFAULT_FILE_PATH);
        OslMfree(temp_buff);
       
        fd = FS_Open((U16*)imps_p->path_buff, FS_OPEN_DIR | FS_READ_ONLY);
        if (fd < 0)
        {
            ret  = FS_CreateDir((U16*)imps_p->path_buff);
            if (ret == FS_NO_ERROR)
			{
        	    mmi_ucs2cat((S8*) imps_p->path_buff, (S8*) mmi_fmgr_extract_file_name((S8*) ind->message_content)); 
                ret = FS_Move((U16*) ind->message_content, (U16*) imps_p->path_buff, FS_MOVE_KILL, NULL, NULL, 0); 
            }
        }
        else
        {
            FS_Close(fd);
            
            mmi_ucs2cat((S8*) imps_p->path_buff, (S8*) mmi_fmgr_extract_file_name((S8*) ind->message_content)); 
            ret = FS_Move((U16*) ind->message_content, (U16*) imps_p->path_buff, FS_MOVE_KILL, NULL, NULL, 0); 
        }

        #if (!defined(__MMI_SHOW_FILE_EXT__))
            PmgRemoveFileExt((S8*) imps_p->path_buff);
        #elif (!defined(__MMI_SHOW_DAF_FILE_EXT__))
            PmgRemoveFileDAFExt((S8*) imps_p->path_buff);
        #endif

        wgui_color_buffer_write_char(&writer, GUI_INPUT_COLOR_00);

        /* insert input into buffer */
        wgui_color_buffer_write_char(&writer, '<');
        if (mmi_ucs2strlen((S8*) ind->sender.sname) > 0)
        {
            wgui_color_buffer_write_string(&writer, (U8*) ind->sender.sname, MMI_FALSE, &result);
        }
        else
        {
            tmp_sname_buff = OslMalloc(IMPS_MAX_ID_LEN * ENCODING_LENGTH);
            mmi_asc_to_ucs2((S8*) tmp_sname_buff, (S8*) ind->sender.id);
            wgui_color_buffer_write_string(&writer, (U8*) tmp_sname_buff, MMI_FALSE, &result);
            OslMfree(tmp_sname_buff);
        }
        
        wgui_color_buffer_write_string(&writer, (U8*) L">\n", MMI_FALSE, &result);
        wgui_color_buffer_write_char(&writer, GUI_INPUT_MARKER_RESET_ALL);        

		wgui_color_buffer_write_string(&writer, (U8*)GetString(STR_ID_IMPS_RECEIVE_NEW_FILE), MMI_FALSE, &result);
        wgui_color_buffer_write_string(&writer, (U8*) L"\n", MMI_FALSE, &result);

	    if (ret == FS_NO_ERROR)
    	{
            wgui_color_buffer_write_string(&writer, (U8*) imps_p->path_buff, MMI_FALSE, &result);
            wgui_color_buffer_write_string(&writer, (U8*) L"\n\n", MMI_FALSE, &result);
    	}
    	else
    	{
    	    wgui_color_buffer_write_string(&writer, (U8*)GetString(GetFileSystemErrorString(ret)), MMI_FALSE, &result);
    	    wgui_color_buffer_write_string(&writer, (U8*) L"\n\n", MMI_FALSE, &result);
    	}
        mmi_imps_chat_flush_msg(tmp_input_buff, (S32) room_id);
        room->clear_gui_buff = TRUE;     
    }
    else if (ind->use_file == IMPS_CONTENT_STORE_URL)
    {
        U16 disp_buff[IMPS_MAX_CONTENT_LEN], temp_buff1[20];
        strcpy((S8*) imps_p->path_buff, (S8*) ind->message_content);
        disp_buff[0] = 0;
        mmi_ucs2cpy((S8*) disp_buff, (S8*) GetString(STR_ID_IMPS_NEW_FILE_FROM));
        mmi_asc_to_ucs2((S8*) temp_buff1, (S8*) ind->sender.id);
        mmi_ucs2cat((S8*) disp_buff, (S8*) temp_buff1);
        mmi_ucs2cat((S8*) disp_buff, (S8*) L",\n");
        mmi_ucs2cat((S8*) disp_buff, (S8*) GetString(STR_GLOBAL_DOWNLOAD_ASK));
        DisplayConfirm(
                STR_GLOBAL_YES,
                IMG_GLOBAL_YES,
                STR_GLOBAL_NO,
                IMG_GLOBAL_NO,
                (UI_string_type) disp_buff,
                IMG_GLOBAL_QUESTION,
                WARNING_TONE);

        SetLeftSoftkeyFunction(mmi_imps_entry_dl_large_file, KEY_EVENT_UP);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
    else if (ind->use_file == IMPS_CONTENT_STORE_NO_SPACE)
    {
        wgui_color_buffer_write_string(&writer, (U8*) GetString(STR_ID_IMPS_ERR_MESSAGE_TOO_LARGE), MMI_FALSE, &result);
        mmi_imps_chat_flush_msg(tmp_input_buff, (S32) room_id);
        room->clear_gui_buff = TRUE; 
    }
    else
    {
    }

    OslMfree(tmp_input_buff);  
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_chat_save_file_callback
 * DESCRIPTION
 *  Callback function for copying file
 * PARAMETERS
 *  info        [?]     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_chat_save_file_callback(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fmt_copy_rsp_strcut *msgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgPtr = (mmi_fmt_copy_rsp_strcut*) info;

    if (msgPtr->result >= 0)
    {
        mmi_imps_util_disp_warning_popup(STR_ID_IMPS_RECEIVE_NEW_FILE);
    }
    else
    {
        imps_p->gen_info.curr_action = 0;
        mmi_imps_util_disp_err_popup(GetFileSystemErrorString(msgPtr->result));
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_imps_chat_display_send_failed
 * DESCRIPTION
 *  Display error message if a message can not be sent
 * PARAMETERS
 *  room_id     [IN]        Index of room in room list
 *  msg         [IN]        Text message to be display
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_chat_display_send_failed(U8 room_id, U16 *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *tmp_input_buff = OslMalloc(IMPS_MAX_CHAT_BUFF * ENCODING_LENGTH);
    wgui_color_buffer_writer_struct writer;
    BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tmp_input_buff[0] = 0;
    wgui_color_buffer_create_writer(&writer, (U8*) tmp_input_buff, IMPS_MAX_CHAT_BUFF * ENCODING_LENGTH);
    wgui_color_buffer_write_char(&writer, GUI_INPUT_COLOR_00);

    wgui_color_buffer_write_string(&writer, (U8*) GetString(STR_ID_IMPS_MSG_CANNOT_SEND), MMI_FALSE, &result);
    wgui_color_buffer_write_char(&writer, GUI_INPUT_MARKER_RESET_ALL);
    wgui_color_buffer_write_char(&writer, '\n');
    wgui_color_buffer_write_string(&writer, (U8*) msg, MMI_FALSE, &result);
    wgui_color_buffer_write_string(&writer, (U8*) L"\n\n", MMI_FALSE, &result);

    mmi_imps_chat_flush_msg(tmp_input_buff, (S32) room_id);

    OslMfree(tmp_input_buff);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_chat_disp_user_change_msg
 * DESCRIPTION
 *  Display member joined/left message in the chat room
 * PARAMETERS
 *  room_id         [IN]        Index of room
 *  joined_user     [?]         [?]
 *  type            [IN]        Type of change
 *  member(?)       [IN]        Left memeber(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_chat_disp_user_change_msg(S32 room_id, imps_entity_struct *joined_user, S32 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *tmp_sname_buff;
    U16 *tmp_input_buff = OslMalloc(IMPS_MAX_CHAT_BUFF * ENCODING_LENGTH);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* insert input into buffer */
    if (mmi_ucs2strlen((S8*) joined_user->sname))
    {
        mmi_ucs2cpy((S8*) tmp_input_buff, (S8*) joined_user->sname);
    }
    else
    {
        tmp_sname_buff = OslMalloc(IMPS_MAX_ID_LEN * ENCODING_LENGTH);
        mmi_asc_to_ucs2((S8*) tmp_sname_buff, (S8*) joined_user->id);
        mmi_ucs2cpy((S8*) tmp_input_buff, (S8*) tmp_sname_buff);
        OslMfree(tmp_sname_buff);
    }

    mmi_ucs2cat((S8*) tmp_input_buff, (S8*) L" ");

    if (type == IMPS_ROOM_MEMBER_JOINED)
    {
        mmi_ucs2cat((S8*) tmp_input_buff, (S8*) GetString(STR_ID_IMPS_JOINED_ROOM));
    }
    else
    {
        mmi_ucs2cat((S8*) tmp_input_buff, (S8*) GetString(STR_ID_IMPS_LEFT_CHAT_ROOM));
    }

    mmi_ucs2cat((S8*) tmp_input_buff, (S8*) L"\n\n");

    mmi_imps_chat_flush_msg(tmp_input_buff, room_id);

    OslMfree(tmp_input_buff);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_chat_flush_msg
 * DESCRIPTION
 *  Flush message into display buffer
 * PARAMETERS
 *  data        [IN]        Data to be flush to display buffer
 *  room_id     [IN]        Index of chat room
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_chat_flush_msg(U16 *data, S32 room_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 input_len;
    S32 disp_len;
    S32 total_len;
    U16 *tmp_chat_buff = OslMalloc(IMPS_MAX_CHAT_BUFF * ENCODING_LENGTH);
    mmi_imps_room_struct *room = &imps_p->room_info.room_list[room_id];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    input_len = mmi_ucs2strlen((S8*) data);
    disp_len = mmi_ucs2strlen((S8*) room->chat_buff);
    total_len = input_len + disp_len;

    if (total_len < IMPS_MAX_CHAT_BUFF)
    {
        mmi_ucs2cat((S8*) room->chat_buff, (S8*) data);
    }
    else
    {
        /* truncated previous string */
        U8 *cursor = (U8*) & room->chat_buff[0];
        U8 *end = (U8*) & room->chat_buff[(IMPS_MAX_CHAT_BUFF - 1)];

        cursor += ((total_len - IMPS_MAX_CHAT_BUFF + 1) * ENCODING_LENGTH);

        while ((cursor[0] != 0 || cursor[1] != 0) && (cursor < end))
        {
            if (cursor[0] == '\n' && cursor[1] == '\0')
            {
                cursor += 2;    /* move cursor to new line */
                break;
            }
            cursor += 2;
        }

        memset(tmp_chat_buff, 0, IMPS_MAX_CHAT_BUFF * ENCODING_LENGTH);

        if (cursor < end)
        {
            mmi_ucs2ncpy((S8*) tmp_chat_buff, (S8*) cursor, (end - cursor));
        }

        room->chat_buff[0] = 0;
        mmi_ucs2cpy((S8*) room->chat_buff, (S8*) tmp_chat_buff);
        mmi_ucs2cat((S8*) room->chat_buff, (S8*) data);
    }

    OslMfree(tmp_chat_buff);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_chat_insert_session
 * DESCRIPTION
 *  Insert a chat session into queue
 * PARAMETERS
 *  void
 * RETURNS
 *  index of session
 *****************************************************************************/
S32 mmi_imps_chat_insert_session(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < IMPS_MAX_CHAT_MSG_COUNT; i++)
        if (imps_p->chat_info.chat_session[i].session_id == 0)
        {
            break;
        }

    if (i == IMPS_MAX_CHAT_MSG_COUNT)
    {
        return 0;
    }
    else
    {
        mmi_imps_chat_session_struct *session = &imps_p->chat_info.chat_session[i];

        mmi_ucs2cpy(
            (S8*) session->input_buff,
            (S8*) imps_p->chat_info.input_buff);
        session->session_id = mmi_imps_util_get_seq_no();
        strcpy((S8*) session->room_id, (S8*) imps_p->room_info.room_list[imps_p->chat_info.curr_room].room_id);
        return session->session_id;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_chat_insert_symbol
 * DESCRIPTION
 *  Highlight handler of Insert Symbol menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_chat_insert_symbol(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_entry_chat_insert_symbol, KEY_EVENT_UP);
    SetKeyHandler(mmi_imps_entry_chat_insert_symbol, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_chat_insert_symbol
 * DESCRIPTION
 *  Display list of symbols to be inserted to chatting screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_chat_insert_symbol(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    U8 *guiBuffer;
    U16 icons[IMPS_NUM_MOOD] = 
    {
        IMG_ID_IMPS_HAPPY,
        IMG_ID_IMPS_SAD,
        IMG_ID_IMPS_ANGRY,
        IMG_ID_IMPS_JEALOUS,
        IMG_ID_IMPS_ASHAMED,
        IMG_ID_IMPS_INVINCIBLE,
        IMG_ID_IMPS_IN_LOVE,
        IMG_ID_IMPS_SLEEPY,
        IMG_ID_IMPS_BORED,
        IMG_ID_IMPS_EXCITED,
        IMG_ID_IMPS_ANXIOUS
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_IMPS_INSERT_SYMBOL, NULL, mmi_imps_entry_chat_insert_symbol, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMPS_INSERT_SYMBOL);

    SetParentHandler(0);

    RegisterHighlightHandler(mmi_imps_hilite_symbol);

    for (i = 0; i < IMPS_NUM_MOOD; i++)
    {
        memset(subMenuData[i], 0, MAX_SUB_MENU_SIZE);
        mmi_ucs2cpy((S8*) subMenuData[i], (S8*) GetString((U16) (STR_ID_IMPS_HAPPY + i)));
        subMenuDataPtrs[i] = subMenuData[i];
    }

    ShowCategory53Screen(
        STR_ID_IMPS_INSERT_SYMBOL,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        IMPS_NUM_MOOD,
        (U8 **) subMenuDataPtrs,
        (U16*) icons,
        (U8 **) g_imps_mood_str,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_imps_sym_sel_done, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_symbol
 * DESCRIPTION
 *  Highlight handler in symbol list screen
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_symbol(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    imps_p->chat_info.sel_sym = (U8) index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_sym_sel_done
 * DESCRIPTION
 *  Handler when finish selecting a symbol
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_sym_sel_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 input_len = mmi_ucs2strlen((S8*) imps_p->chat_info.input_buff);
    S32 sym_len = mmi_ucs2strlen((S8*) g_imps_mood_str[imps_p->chat_info.sel_sym]);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((input_len + sym_len) > (IMPS_MAX_CHAT_INPUT_LEN - 1))
    {
        mmi_imps_util_disp_err_popup(STR_ID_IMPS_ERR_NO_SPACE);
    }
    else
    {
        /* lock buffer to prevent redraw */
        gui_lock_double_buffer();
        GoBackToHistory(SCR_ID_IMPS_CHAT);
        gui_unlock_double_buffer();
        Category435DirectInsertString((UI_string_type) g_imps_mood_str[imps_p->chat_info.sel_sym], TRUE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_dl_large_file
 * DESCRIPTION
 *  mmi_imps_entry_dl_large_file.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_dl_large_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    mmi_imps_ps_dl_large_file_req();
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_chat_text_format
 * DESCRIPTION
 *  Highlight handler of Text format menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_chat_text_format(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_pre_entry_chat_text_format, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_pre_entry_chat_text_format
 * DESCRIPTION
 *  Pre-Entry function of Room->Join option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_pre_entry_chat_text_format(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imps_p->room_info.inline_text_format == NULL)
    {
        imps_p->room_info.inline_text_format = OslMalloc(sizeof(mmi_imps_text_format_inline_struct));
    }

    /* reset buffer */
    imps_p->room_info.inline_text_format->text_color = imps_p->chat_info.sel_color;
    imps_p->room_info.inline_text_format->text_size = imps_p->chat_info.sel_size;
    imps_p->room_info.inline_text_format->text_style_bold = 0;
    imps_p->room_info.inline_text_format->text_style_italics= 0;    
    imps_p->room_info.inline_text_format->text_style_underline= 0;    
    if (imps_p->chat_info.sel_style & IMPS_FONT_STYLE_BOLD)
    {
        imps_p->room_info.inline_text_format->text_style_bold = 1;
    }
    if (imps_p->chat_info.sel_style & IMPS_FONT_STYLE_ITALIC)
    {
        imps_p->room_info.inline_text_format->text_style_italics= 1;    
    }
    if (imps_p->chat_info.sel_style & IMPS_FONT_STYLE_UNDERLINE)
    {
        imps_p->room_info.inline_text_format->text_style_underline= 1;    
    }
    mmi_imps_entry_chat_text_format();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_chat_text_format
 * DESCRIPTION
 *  Entry Text format screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_chat_text_format(void)
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
    EntryNewScreen(SCR_ID_IMPS_CHAT_TEXT_FORMAT, mmi_imps_eixt_chat_text_format, NULL, NULL);

    InitializeCategory57Screen();

    mmi_imps_chat_text_format_fill_inline_struct();

    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMPS_CHAT_TEXT_FORMAT);

    inputBuffer = GetCurrNInputBuffer(SCR_ID_IMPS_CHAT_TEXT_FORMAT, &inputBufferSize);

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, IMPS_INLINE_TEXT_FORMAT, inputBuffer);
    }

    ShowCategory57Screen(
        STR_ID_IMPS_TEXT_FORMAT,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        STR_GLOBAL_EDIT,
        IMG_GLOBAL_BACK,
        STR_GLOBAL_DONE,
        IMG_GLOBAL_BACK,
        IMPS_INLINE_TEXT_FORMAT,
        (U16*) g_imps_inline_icons,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_imps_chat_text_format_done, GoBackHistory);

    SetDelScrnIDCallbackHandler(SCR_ID_IMPS_CHAT_TEXT_FORMAT, (HistoryDelCBPtr) mmi_imps_text_format_scr_del_callback);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_eixt_chat_text_format
 * DESCRIPTION
 *  Exit function of Text format option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_eixt_chat_text_format(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GenericExitInlineScreen(SCR_ID_IMPS_CHAT_TEXT_FORMAT, mmi_imps_entry_chat_text_format);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_chat_text_format_fill_inline_struct
 * DESCRIPTION
 *  Fill inline struct of Text format screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_chat_text_format_fill_inline_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_text_format_inline_struct *text_format = imps_p->room_info.inline_text_format;
	U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    text_format->yes_no_list[0] = (U8*) GetString(STR_GLOBAL_NO);
    text_format->yes_no_list[1] = (U8*) GetString(STR_GLOBAL_YES);

    for (i = 0; i < IMPS_FONT_SIZE_MAX_NUM; i++)
    {
        text_format->size_list[i] = (U8*) GetString((U16) (STR_IMPS_TEXT_SIZE_DEFAULT + i));
    }

    for (i = 0; i < IMPS_FONT_COLOR_MAX_NUM; i++)
    {
        text_format->color_list[i] = (U8*) GetString((U16) (STR_IMPS_TEXT_COLOR_DEFAULT + i));
    }

    /* style_bold */
    SetInlineItemActivation(&wgui_inline_items[0], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[0], (U8*) GetString(STR_ID_IMPS_TEXT_BOLD));
    SetInlineItemActivation(&wgui_inline_items[1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(&wgui_inline_items[1], 2, text_format->yes_no_list, &text_format->text_style_bold);    

    /* style_italic */
    SetInlineItemActivation(&wgui_inline_items[2], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[2], (U8*) GetString(STR_ID_IMPS_TEXT_ITALIC));
    SetInlineItemActivation(&wgui_inline_items[3], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(&wgui_inline_items[3], 2, text_format->yes_no_list, &text_format->text_style_italics);        

    /* style_underline */
    SetInlineItemActivation(&wgui_inline_items[4], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[4], (U8*) GetString(STR_ID_IMPS_TEXT_UNDERLINE));
    SetInlineItemActivation(&wgui_inline_items[5], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(&wgui_inline_items[5], 2, text_format->yes_no_list, &text_format->text_style_underline);    
    
    /* color */
    SetInlineItemActivation(&wgui_inline_items[6], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[6], (U8*) GetString(STR_ID_IMPS_TEXT_COLOR));
    SetInlineItemActivation(&wgui_inline_items[7], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(&wgui_inline_items[7], IMPS_FONT_COLOR_MAX_NUM, text_format->color_list, &text_format->text_color);        

    /* size */
    SetInlineItemActivation(&wgui_inline_items[8], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[8], (U8*) GetString(STR_ID_IMPS_TEXT_SIZE));
    SetInlineItemActivation(&wgui_inline_items[9], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(&wgui_inline_items[9], IMPS_FONT_SIZE_MAX_NUM, text_format->size_list, &text_format->text_size);        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_chat_text_format_done
 * DESCRIPTION
 *  Handler of text format done
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_chat_text_format_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_text_format_inline_struct *text_format = imps_p->room_info.inline_text_format;
    mmi_imps_chat_info_struct *chat_info = &imps_p->chat_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    chat_info->sel_color = (U8) text_format->text_color;
    chat_info->sel_size = (U8) text_format->text_size;
    chat_info->sel_style = 0;
    if (text_format->text_style_bold == 1)
    {
        chat_info->sel_style |= IMPS_FONT_STYLE_BOLD;
    }
    if (text_format->text_style_italics == 1)
    {
        chat_info->sel_style |= IMPS_FONT_STYLE_ITALIC;
    }
    if (text_format->text_style_underline == 1)
    {
        chat_info->sel_style |= IMPS_FONT_STYLE_UNDERLINE;
    }   
    /* lock buffer to prevent redraw */
    gui_lock_double_buffer();
    GoBackToHistory(SCR_ID_IMPS_CHAT);
    gui_unlock_double_buffer();    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_text_format_scr_del_callback
 * DESCRIPTION
 *  Callback function when text format screen is deleted.
 * PARAMETERS
 *  param       [IN]        Parameter from framework
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_imps_text_format_scr_del_callback(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_text_format_free_mem();

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_text_format_free_mem
 * DESCRIPTION
 *  Free inline editor memory for Text format screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_text_format_free_mem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    OslMfree(imps_p->room_info.inline_text_format);
    imps_p->room_info.inline_text_format = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_chat_send_file
 * DESCRIPTION
 *  Hilite handler of send file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_chat_send_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_entry_chat_send_file, KEY_EVENT_UP);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_chat_send_file
 * DESCRIPTION
 *  Entry send file screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_chat_send_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET_ALL(&filter);
#if 0    
/* under construction !*/
/* under construction !*/
#if defined(GDI_USING_PNG)
/* under construction !*/
#endif 
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif    

    mmi_fmgr_select_path_and_enter(APP_IMPS, FMGR_SELECT_FILE | FMGR_SELECT_REPEAT | FMGR_SELECT_ARCHIVE, filter, (S8*) L"root", mmi_imps_chat_sel_file_callback);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_chat_sel_file_callback
 * DESCRIPTION
 *  Callback function for selected image from File Manager
 * PARAMETERS
 *  filePath        [IN]        File path+name from File Manager
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_chat_sel_file_callback(void *filePath, S32 is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_room_struct *room = &imps_p->room_info.room_list[imps_p->chat_info.curr_room];    
	S32 session_id;
	S32 fileLen = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filePath == NULL)
    {
        GoBackToHistory(SCR_ID_IMPS_CHAT_OPT);
        return;
    }
    else
    {
        S32 f_result;
        applib_mime_type_struct *mime_type;
        S8 *mime_string = NULL;
        
    #ifdef __DRM_SUPPORT__
        BOOL is_Forwardable;

        is_Forwardable = DRM_interdev_movable(NULL, (U16*) filePath);    

        if (!is_Forwardable)
        {
            mmi_imps_util_disp_warning_popup(STR_GLOBAL_DRM_PROHIBITED);
            return;
        }
    #endif /* __DRM_SUPPORT__ */ 

        if ((f_result = mmi_imps_util_get_file_size(filePath, &fileLen)) == FS_NO_ERROR)
        {
            if (fileLen > IMPS_MAX_PIC_SIZE)
            {
                mmi_imps_util_disp_err_popup(STR_ID_IMPS_SIZE_TOO_LARGE);                
                return;
            }
            if (fileLen == 0)
            {
                mmi_imps_util_disp_err_popup(STR_ID_IMPS_EMPTY_FILE);                
                return;
            }
        }
        else
        {
            mmi_imps_util_disp_err_popup(GetFileSystemErrorString(f_result));            
            return;
        }

        /* store file in buffer */
        mmi_ucs2cpy((S8*) imps_p->path_buff, (S8*) filePath);

        if (is_short)
        {
            mmi_chset_mixed_text_to_ucs2_str(
                (kal_uint8*) mmi_fmgr_extract_file_name((S8*) imps_p->path_buff),
                (FMGR_MAX_FILE_LEN + 1) * 2,
                (kal_uint8*) mmi_fmgr_extract_file_name((S8*) filePath),
                PhnsetGetDefEncodingType());
        }

        /* check the accepted content type when not_agreed_all equals TRUE */
#ifdef __DRM_SUPPORT__
        mime_string = (S8*) DRM_get_content_type(0, (U16*) filePath);
#endif /* __DRM_SUPPORT__ */  
        if (mime_string == NULL)
        {
            mime_type = mime_get_file_type((U16*) filePath);            
            if (mime_type != NULL)
            {
                mime_string = mime_type->mime_string;
            }
        }
        
        if (mime_string != NULL)
        {
            if (imps_p->gen_info.not_agreed_all == TRUE
                && mmi_imps_util_stricmp(mime_string, "text/plain") == TRUE)
            {
                FS_HANDLE fileHandle = 0;
                U16 *fileName = OslMalloc((FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH);
                U8 tempbuff[20];
                U32 len;
                BOOL found = FALSE;
                imps_accepted_content_type_struct *accepted_content = 
                                (imps_accepted_content_type_struct*) OslMalloc(sizeof(imps_accepted_content_type_struct));

                sprintf((S8*)tempbuff, "%s%s", IMPS_SYS_FILE_DIRECTORY, IMPS_CONTENT_TYPE_FILE_NAME);
                mmi_asc_to_ucs2((S8*) fileName, (S8*) tempbuff);
                fileHandle = FS_Open(fileName, FS_READ_ONLY);
                OslMfree(fileName);

                if (fileHandle > 0)
                {
                    S8 *s;
                    while (FS_Read(fileHandle, 
                                   (void*) accepted_content, 
                                   sizeof(imps_accepted_content_type_struct), 
                                   &len) == FS_NO_ERROR && len > 0)
                    {
                        s = strchr(accepted_content->mime_type, '/');
                        if (mmi_imps_util_stricmp(mime_string, accepted_content->mime_type) == FALSE ||
                            (strchr(accepted_content->mime_type, '*') != NULL &&
                             mmi_imps_util_strnicmp(mime_string, accepted_content->mime_type, s - accepted_content->mime_type) == 0))
                        {
                            found = TRUE;
                            break;
                        }
                    }
                }

                FS_Close(fileHandle);

                if (found == TRUE)
                {
                    if (accepted_content->content_policy == IMPS_CONTENT_POLICY_EXTRA_COST && 
                        fileLen > accepted_content->content_policy_limit)
                    {
                        OslMfree(accepted_content);
                        mmi_imps_entry_confirm(STR_ID_IMPS_CONTENT_POLICY_EXTRA_COST, mmi_imps_send_file_confirm_yes, mmi_imps_send_file_confirm_no);
                        return;
                    }
                    else if (accepted_content->content_policy == IMPS_CONTENT_POLICY_REJECT &&
                             fileLen > accepted_content->content_policy_limit)
                    {
                        OslMfree(accepted_content);
                        mmi_imps_util_disp_warning_popup(STR_ID_IMPS_CONTENT_POLICY_REJECT);                        
                        return;
                    }
                }
                else
                {
                    OslMfree(accepted_content);
                    mmi_imps_util_disp_warning_popup(STR_ID_IMPS_ERR_SERVER_NOT_SUPPORT);                    
                    return;                
                }

                OslMfree(accepted_content);
            }
        }
        else
        {
            mmi_imps_util_disp_warning_popup(STR_ID_IMPS_ERR_SERVER_NOT_SUPPORT);            
            return;            
        }

        #if (!defined(__MMI_SHOW_FILE_EXT__))
            PmgRemoveFileExt((S8*) imps_p->path_buff);
        #elif (!defined(__MMI_SHOW_DAF_FILE_EXT__))
            PmgRemoveFileDAFExt((S8*) imps_p->path_buff);
        #endif

        mmi_ucs2cpy((S8*) imps_p->chat_info.input_buff, (S8*) imps_p->path_buff);
        session_id = mmi_imps_chat_insert_session();

        /* check if there is any empty session can be used */
        if (session_id == 0)
        {
            mmi_imps_util_play_tone(IMPS_ERR_TONE);
            mmi_imps_chat_display_send_failed(imps_p->chat_info.curr_room, imps_p->chat_info.input_buff);            
        }
        else
        {
            U8 entity_type;

            mmi_imps_chat_disp_input_msg();
#ifndef IMPS_TEST_CODE

#ifdef IMPS_FOR_OMA_ONLY
            if (mmi_imps_chat_private_msg(session_id, (S16*) imps_p->chat_info.input_buff, imps_p->chat_info.curr_room) == FALSE)
#endif 
            {
                if (room->type == IMPS_ROOM_TYPE_SINGLE)
                {
                    entity_type = IMPS_ENTITY_TYPE_USER;
                }
                else
                {
                    entity_type = IMPS_ENTITY_TYPE_GROUP;
                }

                mmi_imps_ps_send_msg_req(session_id, (S16*) imps_p->chat_info.input_buff, room->room_id, (U8) entity_type, NULL, FALSE);
            }
            imps_p->chat_info.input_buff[0] = 0;
#endif /* IMPS_TEST_CODE */ 
        }
    }

    gui_lock_double_buffer();
    GoBackToHistory(SCR_ID_IMPS_CHAT);
    gui_unlock_double_buffer();
    mmi_imps_chat_hide_input_screen(FALSE);
    UpdateCategory435LogText((U8*) room->chat_buff, (S32) mmi_ucs2strlen((S8*) room->chat_buff));    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_send_file_confirm_yes
 * DESCRIPTION
 *  Confirmation NO of sending file.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 ****************************************************************************/
void mmi_imps_send_file_confirm_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_room_struct *room = &imps_p->room_info.room_list[imps_p->chat_info.curr_room];    
    S32 session_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    session_id = mmi_imps_chat_insert_session();

    /* check if there is any empty session can be used */
    if (session_id == 0)
    {
        mmi_imps_util_play_tone(IMPS_ERR_TONE);
        mmi_imps_chat_display_send_failed(imps_p->chat_info.curr_room, imps_p->chat_info.input_buff);        
    }
    else
    {
        U8 entity_type;

        mmi_imps_chat_disp_input_msg();
#ifndef IMPS_TEST_CODE

#ifdef IMPS_FOR_OMA_ONLY
        if (mmi_imps_chat_private_msg(session_id, (S16*) imps_p->chat_info.input_buff, imps_p->chat_info.curr_room) == FALSE)
#endif 
        {
            if (room->type == IMPS_ROOM_TYPE_SINGLE)
            {
                entity_type = IMPS_ENTITY_TYPE_USER;
            }
            else
            {
                entity_type = IMPS_ENTITY_TYPE_GROUP;
            }

            mmi_imps_ps_send_msg_req(session_id, (S16*) imps_p->chat_info.input_buff, room->room_id, (U8) entity_type, NULL, FALSE);
        }
        imps_p->chat_info.input_buff[0] = 0;
#endif /* IMPS_TEST_CODE */ 
    }
    
    gui_lock_double_buffer();
    GoBackToHistory(SCR_ID_IMPS_CHAT);
    gui_unlock_double_buffer();
    mmi_imps_chat_hide_input_screen(FALSE);
    UpdateCategory435LogText((U8*) room->chat_buff, (S32) mmi_ucs2strlen((S8*) room->chat_buff));       
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_send_file_confirm_no
 * DESCRIPTION
 *  Confirmation YES of sending file.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 ****************************************************************************/
void mmi_imps_send_file_confirm_no(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    imps_p->chat_info.input_buff[0] = 0;
    
    gui_lock_double_buffer();
    GoBackToHistory(SCR_ID_IMPS_CHAT);
    gui_unlock_double_buffer();
    mmi_imps_chat_hide_input_screen(FALSE);
    UpdateCategory435LogText((U8*) imps_p->room_info.room_list[imps_p->chat_info.curr_room].chat_buff, 
                             (S32) mmi_ucs2strlen((S8*) imps_p->room_info.room_list[imps_p->chat_info.curr_room].chat_buff));  
}



/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_chat_member
 * DESCRIPTION
 *  Highlight handler of List Member menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_chat_member(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_pre_entry_chat_member, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_chat_member
 * DESCRIPTION
 *  Display list of members who is currently on that chat room
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_chat_member(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S32 i, count;
    imps_entity_list_struct *member = imps_p->room_info.member;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef IMPS_TEST_CODE
    imps_p->room_info.member = OslMalloc(sizeof(imps_entity_list_struct));
    member = imps_p->room_info.member;
    memset(member, 0, sizeof(imps_entity_list_struct));
    member->entity_count = 1;
    strcpy((s8*) member->entity[0].id, (S8*) imps_p->cont_info.cont_list[0].id);
    mmi_ucs2cpy((S8*) member->entity[0].sname, (S8*) imps_p->cont_info.cont_list[0].alias);
    member->entity[0].entity_type = IMPS_PRI_LEVEL_ADM;
#endif

    if ( member == NULL || member->entity_count == 0)  
    {
        mmi_imps_util_disp_empty_popup();
        if (imps_p->room_info.member)
        {
            OslMfree(imps_p->room_info.member);
            imps_p->room_info.member = NULL;
        }        
        return;
    }

    EntryNewScreen(SCR_ID_IMPS_CHAT_MEMBER, NULL, mmi_imps_entry_chat_member, NULL);

    /* fill member */
    for (i = 0, count = 0; i < MAX_SUB_MENUS && i < member->entity_count; i++)
    {
        if (strlen((S8*) member->entity[i].id))
        {
            mmi_imps_util_ansi_2_ucs2_menu(
                (S8*) member->entity[i].id,
                (S8*) subMenuData[count],
                MAX_SUBMENU_CHARACTERS);

            subMenuDataPtrs[count] = subMenuData[count]; 
            hintDataPtrs[count] = NULL;
            count++;
        }
    }

    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMPS_CHAT_MEMBER);

    SetParentHandler(0);

    RegisterHighlightHandler(mmi_imps_hilite_list_member_item);

    ShowCategory53Screen(
        STR_ID_IMPS_LIST_MEMBER,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (S32) count,
        (U8 **) subMenuDataPtrs,
        (U16*) gIndexIconsImageList,
        (U8 **) hintDataPtrs,
        0,
        0,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_imps_entry_chat_list_member_opt, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetDelScrnIDCallbackHandler(SCR_ID_IMPS_CHAT_MEMBER, (HistoryDelCBPtr) mmi_imps_member_scr_del_callback);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_member_scr_del_callback
 * DESCRIPTION
 *  Function to free memory when member list screen is deleted.
 * PARAMETERS
 *  param       [?]     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_imps_member_scr_del_callback(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imps_p->room_info.member)
    {
        OslMfree(imps_p->room_info.member);
        imps_p->room_info.member = NULL;
    }

    return FALSE;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_chat_save
 * DESCRIPTION
 *  Highlight handler of Save menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_chat_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_entry_chat_save, KEY_EVENT_UP);
    SetKeyHandler(mmi_imps_entry_chat_save, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_chat_save
 * DESCRIPTION
 *  Entry function of Save menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_chat_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((S8*) imps_p->room_info.room_list[imps_p->chat_info.curr_room].chat_buff) == 0)
    {
        mmi_imps_util_disp_err_popup(STR_ID_IMPS_EMPTY_INPUT);
    }
    else
    {
        FMGR_FILTER filter;

        FMGR_FILTER_INIT(&filter);
        FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);

        mmi_fmgr_select_path_and_enter(
            APP_IMPS,
            FMGR_SELECT_FOLDER,
            filter,
            (S8*) L"root",
            mmi_imps_chat_save_select_path_done);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_chat_save_select_path_done
 * DESCRIPTION
 *  callback function when select path to save text finished.
 * PARAMETERS
 *  path            [?]         [?]         [?]         [?]
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_chat_save_select_path_done(void *path, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (path)
    {
        imps_p->file_buff[0] = 0;
        mmi_ucs2cpy((S8*) imps_p->path_buff, (S8*) path);
        mmi_imps_entry_chat_save_filename();
    }
    else
    {
        GoBackToHistory(SCR_ID_IMPS_CHAT_OPT);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_chat_save_filename
 * DESCRIPTION
 *  Display screen for the user to enter file name for saving chat message
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_chat_save_filename(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_IMPS_CHAT_FILENAME, NULL, mmi_imps_entry_chat_save_filename, NULL);

    SetParentHandler(0);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMPS_CHAT_FILENAME);

    ShowCategory5Screen(
        STR_GLOBAL_FILENAME,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        (U8*) imps_p->file_buff,
        FMGR_MAX_INPUT_FILE_LEN,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_imps_entry_chat_save_opt, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_chat_save_opt
 * DESCRIPTION
 *  Display option screen for saving chat message.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_chat_save_opt(void)
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
    EntryNewScreen(SCR_ID_IMPS_CHAT_SAVE_OPT, NULL, mmi_imps_entry_chat_save_opt, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMPS_CHAT_SAVE_OPT);
    SetParentHandler(MENU_ID_IMPS_CHAT_SAVE_OPT);
    numItems = GetNumOfChild(MENU_ID_IMPS_CHAT_SAVE_OPT);
    GetSequenceStringIds(MENU_ID_IMPS_CHAT_SAVE_OPT, nStrItemList);
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
 *  mmi_imps_hilite_chat_save_opt_done
 * DESCRIPTION
 *  Highlight handler of Chat Save -> File Name -> Option -> Done
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_chat_save_opt_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_chat_save_done, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_chat_save_done
 * DESCRIPTION
 *  LSK handler when confirm to save chat message
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_chat_save_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 path_len = mmi_ucs2strlen((S8*) imps_p->path_buff);
    S32 file_len = mmi_ucs2strlen((S8*) imps_p->file_buff);
    S8 *file_buff;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (file_len == 0)
    {
        GoBackHistory();
        mmi_imps_util_disp_err_popup(STR_ID_IMPS_EMPTY_FILENAME);
        return;
    }

     file_len = file_len + strlen(".txt");
    if ((path_len + file_len) > FMGR_MAX_PATH_LEN)
    {
        GoBackHistory();
        mmi_imps_util_disp_err_popup(STR_ID_IMPS_FILENAME_TOO_LONG);
        return;
    }

    file_buff = OslMalloc((FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH);

    mmi_ucs2cpy((S8*) file_buff, (S8*) imps_p->path_buff);
    mmi_ucs2cat((S8*) file_buff, (S8*) imps_p->file_buff);
    mmi_ucs2cat((S8*) file_buff, (S8*) L".txt");

    if (mmi_imps_util_check_file_exist(file_buff))
    {
        GoBackHistory();
        mmi_imps_util_disp_err_popup(STR_ID_IMPS_DUPLICATE_FILENAME);
        OslMfree(file_buff);
        return;
    }
    else
    {
        FS_HANDLE fileHandle;

        fileHandle = FS_Open((U16*) file_buff, FS_CREATE_ALWAYS);

        if (fileHandle > 0)
        {
            S32 result;
            U32 len;
            wgui_color_buffer_reader_struct reader;
            S8 *out_buff = OslMalloc(IMPS_MAX_CHAT_BUFF * ENCODING_LENGTH);

            /* create reader and strip color related markers */
            wgui_color_buffer_create_reader(
                &reader,
                (U8*) imps_p->room_info.room_list[imps_p->chat_info.curr_room].chat_buff);
            wgui_color_buffer_read_stripped_text(
                &reader,
                (U8*) out_buff,
                IMPS_MAX_CHAT_BUFF * ENCODING_LENGTH,
                (S32*) & len);

            /* UCS2 string prefix */
            result = FS_Write(fileHandle, (void*)g_imps_ucs2_file_prefix, 2, &len);
            result = FS_Write(
                        fileHandle,
                        (void*)out_buff,
                        (mmi_ucs2strlen ((S8*) imps_p->room_info.room_list[imps_p->chat_info.curr_room].chat_buff) * ENCODING_LENGTH),
                        &len);
            FS_Close(fileHandle);

            if (result < 0)
            {
                mmi_imps_util_disp_err_popup(GetFileSystemErrorString(result));
                if (result == FS_DISK_FULL)
                {
                    FS_Delete((U16*) file_buff);
                }
            }
            else
            {
                mmi_imps_util_disp_popup_done();
                DeleteUptoScrID(SCR_ID_IMPS_CHAT);
            }

            OslMfree(out_buff);
        }
        else
        {
            mmi_imps_util_disp_err_popup(GetFileSystemErrorString(fileHandle));
        }

    }

    OslMfree(file_buff);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_chat_close
 * DESCRIPTION
 *  Highlight handler of Close Chat Room menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_chat_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_entry_chat_close, KEY_EVENT_UP);
    SetKeyHandler(mmi_imps_entry_chat_close, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_chat_close
 * DESCRIPTION
 *  Entry function of Close Chat Room menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_chat_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_entry_confirm(STR_GLOBAL_CLOSE, mmi_imps_chat_close, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_chat_close
 * DESCRIPTION
 *  Confirm to close a chat room
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_chat_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* if it's a group, shall send request to protocol */
    mmi_imps_room_struct *room = &imps_p->room_info.room_list[imps_p->chat_info.curr_room];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef IMPS_TEST_CODE
    if (room->type == IMPS_ROOM_TYPE_GROUP_CREATE)
    {
        /* send delete group request */
        mmi_imps_display_progressing();
        mmi_imps_ps_del_group_req(room->room_id);
    }
    else if (room->type == IMPS_ROOM_TYPE_GROUP_JOIN)
    {
        /* send leave group request */
        mmi_imps_display_progressing();
        mmi_imps_ps_leave_group_req(room->room_id);
    }
    else
    {
        /* single talk */
        mmi_imps_room_close_finished(room);
        mmi_imps_pre_entry_cont();
        DeleteScreenIfPresent(SCR_ID_IMPS_CHAT);
        DeleteScreenIfPresent(SCR_ID_IMPS_CHAT_OPT);
    }

#else /* IMPS_TEST_CODE */ 
    mmi_imps_pre_entry_cont();
    DeleteScreenIfPresent(SCR_ID_IMPS_CHAT);
    DeleteScreenIfPresent(SCR_ID_IMPS_CHAT_OPT);
    mmi_imps_room_close_finished(room);
#endif /* IMPS_TEST_CODE */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_room_close_finished
 * DESCRIPTION
 *  Reset context of chat room when finish closing chat room
 * PARAMETERS
 *  room        [?]     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_room_close_finished(mmi_imps_room_struct *room)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reset status icon of contact list */
    if (room->type == IMPS_ROOM_TYPE_SINGLE)
    {
        /* reset status icon of contact */
        for (i = 1; i < imps_p->cont_info.no_cont; i++)
        {
            if (mmi_imps_util_is_id_same((S8*) room->room_id, (S8*) imps_p->cont_info.cont_list[i].id))
            {
                /* contact list found, unset new message state */
                imps_p->cont_info.cont_list[i].comm_state &= ~IMPS_CONT_NEW_MSG;
                break;
            }
        }
    }

    imps_p->chat_info.curr_room = 0;
    imps_p->room_info.curr_item = 0;
    imps_p->room_info.no_rooms--;
    mmi_imps_tab_del(room->tab_index, 0);
    mmi_imps_room_reset_cntx(room);
    mmi_imps_util_update_status_icon();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_close_chat_room_done
 * DESCRIPTION
 *  Callback handler when close chat room finished
 * PARAMETERS
 *  result      [IN]        Error cause of result
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_close_chat_room_done(S32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* finished close chat room */
    mmi_imps_room_struct *room = &imps_p->room_info.room_list[imps_p->chat_info.curr_room];
    BOOL chat_present = IsScreenPresent(SCR_ID_IMPS_CHAT);
    S16 *ucs2_folder = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result != IMPS_OK)
    {

        if (imps_p->gen_info.is_reentry)
        {
            mmi_imps_re_entry_app();
            mmi_imps_util_disp_err_popup(mmi_imps_util_get_err_str(result));
        }
        else
        {
            mmi_imps_util_disp_err_popup(mmi_imps_util_get_err_str(result));
            if (chat_present)   /* entry from chat screen */
            {
                mmi_imps_util_del_scr_after_progress(SCR_ID_IMPS_CHAT);
            }
            else    /* entry from room list */
            {
                mmi_imps_util_del_scr_after_progress(SCR_ID_IMPS_CHAT_ROOM_OPT);
            }
        }
    }
    else    /* close finished */
    {
        /* keneng : delete joined user and rejected user file */
        ucs2_folder = OslMalloc((FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH);
        mmi_imps_util_file_path((S8*) ucs2_folder, (S8*) IMPS_REJECTED_USER, imps_p->chat_info.curr_room);        
        FS_Delete((const WCHAR*) ucs2_folder);
        OslMfree(ucs2_folder);
        
        /* update tab info, delete one tab */
        mmi_imps_room_close_finished(room);

        if (imps_p->gen_info.is_reentry)
        {
            mmi_imps_re_entry_app();
        }
        else
        {
            if (IsScreenPresent(SCR_ID_IMPS_CHAT))  /* entry from chat screen */
            {
                /* single talk */
                if (GetActiveScreenId() == SCR_ID_IMPS_PROGRESS)
                {
                    mmi_imps_pre_entry_cont();
                    DeleteScreenIfPresent(SCR_ID_IMPS_CHAT_OPT);
                    DeleteScreenIfPresent(SCR_ID_IMPS_PROGRESS);
                }
                else
                {
                    mmi_imps_util_del_scr_after_progress(SCR_ID_IMPS_CHAT);
                    HistoryReplace(SCR_ID_IMPS_CHAT, SCR_ID_IMPS_CONT, mmi_imps_pre_entry_cont);
                }
            }
            else
            {
                /* alyways regarded as success */
                mmi_imps_util_disp_popup_done();
                mmi_imps_util_del_scr_after_progress(SCR_ID_IMPS_CHAT_ROOM);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_chat_add_member
 * DESCRIPTION
 *  highlight add member menuitem
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_chat_add_member(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_entry_chat_add_member, KEY_EVENT_UP);
    SetKeyHandler(mmi_imps_entry_chat_add_member, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_chat_add_member
 * DESCRIPTION
 *  entry add member screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_chat_add_member(void)
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
    /* keneng : if the user is ordinay user, should not entry this screen */
    if (imps_p->room_info.room_list[imps_p->chat_info.curr_room].pri_level == IMPS_PRI_LEVEL_USER)
    {
        mmi_imps_util_disp_err_popup(STR_ID_IMPS_ERR_INVALID_REQUEST);
        return;
    }

    EntryNewScreen(SCR_ID_IMPS_CHAT_ADD_MEMBER, NULL, mmi_imps_entry_chat_add_member, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMPS_CHAT_ADD_MEMBER);
    SetParentHandler(MENU_ID_IMPS_CHAT_ADD_MEMBER);
    numItems = GetNumOfChild(MENU_ID_IMPS_CHAT_ADD_MEMBER);
    GetSequenceStringIds(MENU_ID_IMPS_CHAT_ADD_MEMBER, nStrItemList);
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
 *  mmi_imps_hilite_chat_list_rejected
 * DESCRIPTION
 *  highlight list rejected user menuitem
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_chat_list_rejected(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_pre_entry_chat_list_rejected, KEY_EVENT_UP);   
    SetKeyHandler(mmi_imps_pre_entry_chat_list_rejected, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_pre_entry_chat_list_rejected
 * DESCRIPTION
 *  prepare to entry list rejected user screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imps_pre_entry_chat_list_rejected(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    imps_entity_list_struct *user_list = OslMalloc(sizeof(imps_entity_list_struct));
    mmi_imps_room_info_struct *room_info = &imps_p->room_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* if the user is ordinay user, should not entry this screen */
    if (room_info->room_list[imps_p->chat_info.curr_room].pri_level == IMPS_PRI_LEVEL_USER)
    {
        mmi_imps_util_disp_err_popup(STR_ID_IMPS_ERR_INVALID_REQUEST);
        return;
    }

    /* display progressing screen */
    mmi_imps_pre_entry_progressing(
        STR_ID_IMPS,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        0,
        0,
        STR_GLOBAL_ABORT,
        0,
        (U8*) GetString(STR_ID_IMPS_PROGRESSING),
        NULL,
        IMG_GLOBAL_PROGRESS,
        NULL,
        mmi_imps_get_rejected_user_abort,
        mmi_imps_get_rejected_user_abort);    

    memset(user_list, 0, sizeof(user_list));
    user_list->entity_count = 0;
   
    mmi_imps_ps_reject_group_user_req(MMI_FALSE, (void*)user_list);
    OslMfree(user_list);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_get_rejected_user_abort
 * DESCRIPTION
 *  abort get rejected user
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imps_get_rejected_user_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_entry_abort();
    mmi_imps_ps_abort_get_joined_user_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_chat_list_rejected
 * DESCRIPTION
 *  entry list rejected user screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_chat_list_rejected(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S32 i;
    S32 count;
    mmi_imps_room_info_struct *room_info = &imps_p->room_info;
    imps_entity_list_struct *rejected_user = NULL;
    S16 *ucs2_folder = NULL;     

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    room_info->rejected_user = OslMalloc(sizeof(imps_entity_list_struct));
    rejected_user = room_info->rejected_user;
    memset(rejected_user, 0, sizeof(imps_entity_list_struct));    

    ucs2_folder = OslMalloc((FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH);
    mmi_imps_util_file_path((S8*) ucs2_folder, (S8*) IMPS_REJECTED_USER, imps_p->chat_info.curr_room);
    mmi_imps_util_get_entity_from_file((imps_entity_list_struct*) rejected_user, (S8*) ucs2_folder);
    OslMfree(ucs2_folder);

    if (rejected_user->entity_count == 0)
    {
        mmi_imps_util_disp_empty_popup();
        OslMfree(imps_p->room_info.rejected_user);
        imps_p->room_info.rejected_user = NULL;        
        return;
    }

    EntryNewScreen(SCR_ID_IMPS_CHAT_REJECTED, NULL, mmi_imps_entry_chat_list_rejected, NULL);

    /* fill rejected */
    for (i = 0, count = 0; i < MAX_SUB_MENUS && i < rejected_user->entity_count; i++)
    {
        if (strlen((S8*) rejected_user->entity[i].id))
        {
            mmi_imps_util_ansi_2_ucs2_menu(
                (S8*) rejected_user->entity[i].id,
                (S8*) subMenuData[count],
                MAX_SUBMENU_CHARACTERS);

            subMenuDataPtrs[count] = subMenuData[count];
            hintDataPtrs[count] = NULL;
            count++;
        }
    }

    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMPS_CHAT_REJECTED);

    SetParentHandler(0);

    RegisterHighlightHandler(mmi_imps_hilite_list_rejected_item);

    ShowCategory53Screen(
        STR_ID_IMPS_LIST_REJECTED,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (S32) count,
        (U8 **) subMenuDataPtrs,
        (U16*) gIndexIconsImageList,
        (U8 **) hintDataPtrs,
        0,
        0,
        guiBuffer);

    ChangeLeftSoftkey(STR_GLOBAL_DELETE, 0);
    SetLeftSoftkeyFunction(mmi_imps_chat_pre_del_rejected, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    
    SetDelScrnIDCallbackHandler(SCR_ID_IMPS_CHAT_REJECTED, (HistoryDelCBPtr) mmi_imps_rejected_scr_del_callback);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_rejected_scr_del_callback
 * DESCRIPTION
 *  Function to free memory when rejected user list screen is deleted.
 * PARAMETERS
 *  param       [?]     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_imps_rejected_scr_del_callback(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_free_list_rejected_buff();

    return FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imps_free_list_rejected_buff
 * DESCRIPTION
 *  Free memory of list rejected screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_free_list_rejected_buff(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imps_p->room_info.rejected_user != NULL)
    {
        OslMfree(imps_p->room_info.rejected_user);
        imps_p->room_info.rejected_user = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_chat_pre_del_rejected
 * DESCRIPTION
 *  confirmation of delete user from rejected list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_chat_pre_del_rejected(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_entry_confirm(STR_GLOBAL_DELETE, mmi_imps_chat_del_rejected, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_chat_list_joined
 * DESCRIPTION
 *  highlight list joined user menuitem
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_chat_list_joined(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_pre_entry_chat_list_joined, KEY_EVENT_UP);
    /* SetKeyHandler(mmi_imps_entry_chat_list_joined, KEY_RIGHT_ARROW, KEY_EVENT_DOWN); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_pre_entry_chat_list_joined
 * DESCRIPTION
 *  prepare to entry list joined user screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_pre_entry_chat_list_joined(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* display progressing screen */
    mmi_imps_pre_entry_progressing(
        STR_ID_IMPS,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        0,
        0,
        STR_GLOBAL_ABORT,
        0,
        (U8*) GetString(STR_ID_IMPS_PROGRESSING),
        NULL,
        IMG_GLOBAL_PROGRESS,
        NULL,
        mmi_imps_get_joined_user_abort,
        mmi_imps_get_joined_user_abort);

#ifdef IMPS_TEST_CODE
    mmi_imps_entry_chat_list_joined();
#else 
    mmi_imps_ps_get_joined_user_req();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_get_joined_user_abort
 * DESCRIPTION
 *  abort get joined user
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_get_joined_user_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_entry_abort();

#ifdef IMPS_TEST_CODE
    SetKeyHandler(mmi_imps_get_joined_user_abort_finish, KEY_SEND, KEY_EVENT_DOWN);
#else 
    mmi_imps_ps_abort_get_joined_user_req();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_chat_list_joined
 * DESCRIPTION
 *  entry list joined user screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_chat_list_joined(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S32 i;
    S32 count;
    imps_entity_list_struct *joined_user = imps_p->room_info.joined_user;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (joined_user == NULL || joined_user->entity_count == 0)
    {
        mmi_imps_util_disp_empty_popup();
        mmi_imps_free_list_joined_buff();
        return;
    }

    EntryNewScreen(SCR_ID_IMPS_CHAT_JOINED, NULL, mmi_imps_entry_chat_list_joined, NULL);

    /* fill joined */
    for (i = 0, count = 0; i < MAX_SUB_MENUS && i < joined_user->entity_count; i++)
    {
        if (strlen((S8*) joined_user->entity[i].id) || mmi_ucs2strlen((S8*) joined_user->entity[i].sname))
        {
            mmi_imps_util_ansi_2_ucs2_menu(
                (S8*) joined_user->entity[i].id,
                (S8*) hintData[count],
                MAX_SUBMENU_CHARACTERS);

            if (mmi_ucs2strlen((S8*) joined_user->entity[i].sname))
            {
                mmi_ucs2cpy((S8*) subMenuData[count], (S8*) joined_user->entity[i].sname);
            }
            else
            {
                mmi_ucs2cpy((S8*) subMenuData[count], (S8*) GetString(STR_ID_IMPS_ANONYMOUS));
            }

            subMenuDataPtrs[count] = subMenuData[count];

            if (mmi_ucs2strlen((S8*) hintData[count]))
            {
                hintDataPtrs[count] = hintData[count];
            }
            else
            {
                hintDataPtrs[count] = NULL;
            }
            count++;
        }
    }

    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMPS_CHAT_JOINED);

    SetParentHandler(0);

    if (imps_p->room_info.room_list[imps_p->chat_info.curr_room].pri_level != IMPS_PRI_LEVEL_USER)
    {
        RegisterHighlightHandler(mmi_imps_hilite_list_joined_item);
    }

    ShowCategory53Screen(
        STR_ID_IMPS_LIST_JOINED,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (S32) count,
        (U8 **) subMenuDataPtrs,
        (U16*) gIndexIconsImageList,
        (U8 **) hintDataPtrs,
        0,
        0,
        guiBuffer);

    /* keneng : if current user is administrator or moderator */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetDelScrnIDCallbackHandler(SCR_ID_IMPS_CHAT_JOINED, (HistoryDelCBPtr) mmi_imps_joined_scr_del_callback);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_joined_scr_del_callback
 * DESCRIPTION
 *  Function to free memory when joined user list screen is deleted.
 * PARAMETERS
 *  param       [?]     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_imps_joined_scr_del_callback(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_free_list_joined_buff();

    return FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imps_free_list_joined_buff
 * DESCRIPTION
 *  Free memory of list joined screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_free_list_joined_buff(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imps_p->room_info.joined_user != NULL)
    {
        OslMfree(imps_p->room_info.joined_user);
        imps_p->room_info.joined_user = NULL;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imps_get_joined_user_abort_finish
 * DESCRIPTION
 *  finish abort get joined user
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_get_joined_user_abort_finish(void)
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
        if (GetActiveScreenId() == SCR_ID_IMPS_PROGRESS)
        {
            GoBackToHistory(SCR_ID_IMPS_CHAT_OPT);
        }
        else
        {
            mmi_imps_util_del_scr_after_progress(SCR_ID_IMPS_CHAT_OPT);
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_list_member_item
 * DESCRIPTION
 *  highlight handle in list member screen
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_list_member_item(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    imps_p->room_info.curr_sel_user = (U8) index;

    /* keneng : if selected item is "myself" */
    if (mmi_imps_util_is_id_same
        ((S8*) imps_p->room_info.member->entity[index].id,
         (S8*) imps_p->cont_info.cont_list[0].id))
    {
        ChangeLeftSoftkey(0, 0);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);
        SetLeftSoftkeyFunction(mmi_imps_entry_chat_list_member_opt, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_list_rejected_item
 * DESCRIPTION
 *  highlight handle in list rejected user screen
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_list_rejected_item(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    imps_p->room_info.curr_sel_user = (U8) index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_list_joined_item
 * DESCRIPTION
 *  highlight handle in list joined user screen
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_list_joined_item(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    imps_p->room_info.curr_sel_user= (U8) index;

    if (mmi_imps_util_is_id_same
        ((S8*) imps_p->room_info.joined_user->entity[index].id,
         (S8*) imps_p->cont_info.cont_list[0].id))
    {
        ChangeLeftSoftkey(0, 0);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);
        SetLeftSoftkeyFunction(mmi_imps_entry_chat_list_joined_opt, KEY_EVENT_UP);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_chat_add_directly
 * DESCRIPTION
 *  highlight handle of add member directly
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_chat_add_directly(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_pre_entry_chat_add_direct, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_pre_entry_chat_add_direct
 * DESCRIPTION
 *  pre entry add member direct
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_pre_entry_chat_add_direct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* keneng : mark it as add contact */
    imps_p->add_cause = IMPS_ADD_MEMBER;

    imps_p->file_buff[0] = 0;   /* reuse path and file buffer */
    mmi_ucs2cpy((S8*) imps_p->path_buff, g_imps_wv);

    mmi_imps_entry_add_direct();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_chat_add_from_online
 * DESCRIPTION
 *  highlight handle of add member from online
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_chat_add_from_online(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_pre_entry_chat_add_from_online, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_pre_entry_chat_add_from_online
 * DESCRIPTION
 *  pre entry add member from online
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_pre_entry_chat_add_from_online(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    imps_p->room_info.invite_or_add = IMPS_ADD_MEMBER_ONLINE;

    mmi_imps_entry_chat_invite();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_add_member_from_online
 * DESCRIPTION
 *  add member from online
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_add_member_from_online(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    imps_entity_list_struct *user_list = OslMalloc(sizeof(imps_entity_list_struct));
    mmi_imps_cont_struct *cont =
        &imps_p->cont_info.cont_list[imps_p->invite_info.invite_cand_list[imps_p->invite_info.curr_sel_cont]];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(user_list, 0, sizeof(imps_entity_list_struct));

    mmi_imps_display_progressing();
    DeleteScreenIfPresent(SCR_ID_IMPS_ADD_MEMBER_FROM_ONLINE);

    user_list->entity_count = 1;
    user_list->entity[0].entity_type = IMPS_ENTITY_TYPE_USER;
    strcpy((S8*) user_list->entity[0].id, (S8*) cont->id);

#ifdef IMPS_TEST_CODE
    mmi_imps_add_member_done(0);
#else 
    mmi_imps_ps_add_group_member_req((void*)user_list);
#endif 
    OslMfree(user_list);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_pre_entry_chat_member
 * DESCRIPTION
 *  pre entry list member
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_pre_entry_chat_member(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* display progressing screen */
    mmi_imps_pre_entry_progressing(
        STR_ID_IMPS,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        0,
        0,
        STR_GLOBAL_ABORT,
        0,
        (U8*) GetString(STR_ID_IMPS_PROGRESSING),
        NULL,
        IMG_GLOBAL_PROGRESS,
        NULL,
        mmi_imps_get_group_member_abort,
        mmi_imps_get_group_member_abort);

#ifdef IMPS_TEST_CODE
    mmi_imps_get_member_done(0);
#else 
    mmi_imps_ps_get_group_member_req();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_get_group_member_abort
 * DESCRIPTION
 *  abort get group member
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_get_group_member_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_entry_abort();

#ifdef IMPS_TEST_CODE
    SetKeyHandler(mmi_imps_get_joined_user_abort_finish, KEY_SEND, KEY_EVENT_DOWN);
#else 
    mmi_imps_ps_abort_get_group_member_req();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_chat_list_member_opt
 * DESCRIPTION
 *  option of list member
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_chat_list_member_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 numItems;
    U16 nStrItemList[2];
    U8 *guiBuffer, i;
    imps_entity_list_struct *member = imps_p->room_info.member;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_IMPS_CHAT_MEMBER_OPT, NULL, mmi_imps_entry_chat_list_member_opt, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMPS_CHAT_MEMBER_OPT);
    SetParentHandler(MENU_ID_IMPS_CHAT_LIST_MEMBER_OPT);
    numItems = GetNumOfChild(MENU_ID_IMPS_CHAT_LIST_MEMBER_OPT);
    if (imps_p->room_info.room_list[imps_p->chat_info.curr_room].pri_level == IMPS_PRI_LEVEL_MOD)
    {
        numItems--;
    }
    GetSequenceStringIds(MENU_ID_IMPS_CHAT_LIST_MEMBER_OPT, nStrItemList);

    if (member->entity[imps_p->room_info.curr_sel_user].entity_type == IMPS_PRI_LEVEL_MOD)
    {
        for (i = 0; i < numItems; i++)
        {
            if (nStrItemList[i] == STR_ID_IMPS_SET_MODERATOR)
            {
                nStrItemList[i] = STR_ID_IMPS_SET_USER;
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
 *  mmi_imps_hilite_chat_del_member
 * DESCRIPTION
 *  highlight handle of delete member
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_chat_del_member(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_entry_del_member_confirm, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_del_member_confirm
 * DESCRIPTION
 *  confirmation of delete member
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_del_member_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_entry_confirm(STR_ID_IMPS_DELETE_MEMBER, mmi_imps_del_member, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_del_member
 * DESCRIPTION
 *  delete member
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_del_member(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* display progressing screen */
    mmi_imps_display_progressing();
    DeleteScreenIfPresent(SCR_ID_IMPS_CHAT_MEMBER_OPT);

    /* send request to PS */
#ifdef IMPS_TEST_CODE
    mmi_imps_del_member_done(0);
#else 
    mmi_imps_ps_remove_group_member_req();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_del_member_done
 * DESCRIPTION
 *  delete member done
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_del_member_done(S32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    imps_entity_list_struct *member = imps_p->room_info.member;
    U8 i = imps_p->room_info.curr_sel_user;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == IMPS_OK /* IMPS_OK */ )
    {
        /* keneng : del member from member list */
        memcpy(&member->entity[i], &member->entity[i + 1], (member->entity_count - i - 1) * sizeof(imps_entity_struct));
        memset(&member->entity[member->entity_count - 1], 0, sizeof(imps_entity_struct));
        member->entity_count--;

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
        DeleteScreenIfPresent(SCR_ID_IMPS_PROGRESS);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_chat_set_mod_user
 * DESCRIPTION
 *  highlight handle of set member as moderator or ordinary user
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_chat_set_mod_user(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_chat_set_mod_user, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_chat_set_mod_user
 * DESCRIPTION
 *  set user as moderator or ordinary user
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_chat_set_mod_user(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* display progressing screen */
    mmi_imps_display_progressing();
    DeleteScreenIfPresent(SCR_ID_IMPS_CHAT_MEMBER_OPT);

#ifdef IMPS_TEST_CODE
    mmi_imps_chat_set_mod_user_done(0);
#else 
    mmi_imps_ps_member_access_req();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_chat_set_mod_user_done
 * DESCRIPTION
 *  set user to moderator or ordinary user done
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_chat_set_mod_user_done(S32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *pri_level = &imps_p->room_info.member->entity[imps_p->room_info.curr_sel_user].entity_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == 0 /* IMPS_OK */ )
    {

        if (*pri_level == IMPS_PRI_LEVEL_MOD)
        {
            *pri_level = IMPS_PRI_LEVEL_USER;
        }
        else if (*pri_level == IMPS_PRI_LEVEL_USER)
        {
            *pri_level = IMPS_PRI_LEVEL_MOD;
        }

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
        DeleteScreenIfPresent(SCR_ID_IMPS_PROGRESS);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_chat_del_rejected
 * DESCRIPTION
 *  delete rejected user
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_chat_del_rejected(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    imps_entity_list_struct *user_list = OslMalloc(sizeof(imps_entity_list_struct));
    mmi_imps_room_info_struct *room_info = &imps_p->room_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* display progressing screen */
    mmi_imps_display_progressing();

    memset(user_list, 0, sizeof(user_list));
    user_list->entity_count = 1;
    user_list->entity[0].entity_type = IMPS_ENTITY_TYPE_USER;
    strcpy((S8*) user_list->entity[0].id, (S8*) room_info->rejected_user->entity[room_info->curr_sel_user].id);
    if (mmi_ucs2strlen((S8*) room_info->rejected_user->entity[room_info->curr_sel_user].sname))
    {
        mmi_ucs2cpy((S8*) user_list->entity[0].sname, (S8*) room_info->rejected_user->entity[room_info->curr_sel_user].sname);
    }

    /* send request to PS */
#ifdef IMPS_TEST_CODE
    mmi_imps_delete_reject_user_done(0);
#else 
    mmi_imps_ps_reject_group_user_req(MMI_FALSE, (void*)user_list);
#endif 
    OslMfree(user_list);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_chat_list_joined_opt
 * DESCRIPTION
 *  option of list joined user
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_chat_list_joined_opt(void)
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
    EntryNewScreen(SCR_ID_IMPS_CHAT_JOINED_OPT, NULL, mmi_imps_entry_chat_list_joined_opt, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMPS_CHAT_JOINED_OPT);
    SetParentHandler(MENU_ID_IMPS_CHAT_LIST_JOINED_OPT);
    numItems = GetNumOfChild(MENU_ID_IMPS_CHAT_LIST_JOINED_OPT);
    GetSequenceStringIds(MENU_ID_IMPS_CHAT_LIST_JOINED_OPT, nStrItemList);
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
 *  mmi_imps_get_joined_from_file
 * DESCRIPTION
 *  get joined user from given file
 * PARAMETERS
 *  filename        [?]         [?]
 *  count           [IN]        
 *  pri_level(?)        [IN](?)
 *  file_name       [?](?)(?)
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_imps_get_joined_from_file(S16 *filename, U8 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    FS_HANDLE fileHandle = 0;

    imps_entity_struct *buff = (imps_entity_struct*) OslMalloc(sizeof(imps_entity_struct));
    imps_entity_list_struct *joined_user = imps_p->room_info.joined_user;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (count)
    {
        U32 len;
        S32 result;

        fileHandle = FS_Open((U16*) filename, FS_READ_ONLY);

        if (fileHandle > 0)
        {
            for (i = 0; i < count; i++)
            {
                result = FS_Read(fileHandle, (void*)buff, sizeof(imps_entity_struct), &len);

                if (result == FS_NO_ERROR)
                {
                    strcpy((S8*) joined_user->entity[joined_user->entity_count].id, (S8*) buff->id);
                    mmi_ucs2cpy((S8*) joined_user->entity[joined_user->entity_count].sname, (S8*) buff->sname);      /* sname must be present */
                    joined_user->entity_count++;
                }
            }
            FS_Close(fileHandle);

            FS_Delete((U16*) filename);
        }
    }

    OslMfree(buff);
    return fileHandle;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_chat_add_to_mem
 * DESCRIPTION
 *  highlight handle of add user to member
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_chat_add_to_mem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_entry_add_to_mem_confirm, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_add_to_mem_confirm
 * DESCRIPTION
 *  confirmation of add user to member
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_add_to_mem_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_entry_confirm(STR_ID_IMPS_ADD_TO_MEM, mmi_imps_chat_add_to_mem, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_chat_add_to_mem
 * DESCRIPTION
 *  add user to member list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_chat_add_to_mem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    imps_entity_list_struct *user_list = OslMalloc(sizeof(imps_entity_list_struct));
    imps_entity_struct *entity = &imps_p->room_info.joined_user->entity[imps_p->room_info.curr_sel_user];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* display progressing screen */
    memset(user_list, 0, sizeof(imps_entity_list_struct));

    mmi_imps_display_progressing();
    DeleteScreenIfPresent(SCR_ID_IMPS_CHAT_JOINED_OPT);

    user_list->entity_count = 1;
    user_list->entity[0].entity_type = IMPS_ENTITY_TYPE_USER;
    strcpy((S8*) user_list->entity[0].id, (S8*) entity->id);
    if (mmi_ucs2strlen((S8*) entity->sname))
    {
        mmi_ucs2cpy((S8*) user_list->entity[0].sname, (S8*) entity->sname);
    }


    /* send request to PS */
#ifdef IMPS_TEST_CODE
    mmi_imps_add_member_done(0);
#else 
    mmi_imps_ps_add_group_member_req((void*)user_list);
#endif 
    OslMfree(user_list);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_add_member_done
 * DESCRIPTION
 *  function after add group member
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_add_member_done(S32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == 0 /* IMPS_OK */ )
    {
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
        DeleteScreenIfPresent(SCR_ID_IMPS_PROGRESS);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_get_member_from_file
 * DESCRIPTION
 *  get group member from given file
 * PARAMETERS
 *  filename        [?]         [?]
 *  count           [IN]        
 *  pri_level       [IN]        
 *  file_name       [?](?)(?)
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_imps_get_member_from_file(S16 *filename, U8 count, U8 pri_level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    FS_HANDLE fileHandle = 0;

    imps_entity_struct *buff = (imps_entity_struct*) OslMalloc(sizeof(imps_entity_struct));
    imps_entity_list_struct *member = imps_p->room_info.member;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (count)
    {
        U32 len;
        S32 result;

        fileHandle = FS_Open((U16*) filename, FS_READ_ONLY);

        if (fileHandle > 0)
        {
            for (i = 0; i < count; i++)
            {
                result = FS_Read(fileHandle, (void*)buff, sizeof(imps_entity_struct), &len);

                if (result == FS_NO_ERROR && len > 0)
                {
                    strcpy((S8*) member->entity[member->entity_count].id, (S8*) buff->id);    /* keneng : id must be present */
                    mmi_ucs2cpy((S8*) member->entity[member->entity_count].sname, (S8*) buff->sname);    /* keneng : sname must be present */
                    member->entity[member->entity_count].entity_type = pri_level;
                    member->entity_count++;
                }
            }
            FS_Close(fileHandle);

            FS_Delete((U16*) filename);
        }
    }

    OslMfree(buff);
    return (S32) fileHandle;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_get_member_done
 * DESCRIPTION
 *  function after get group member
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_get_member_done(S32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == IMPS_OK /* IMPS_OK */ )
    {
        if (GetActiveScreenId() == SCR_ID_IMPS_PROGRESS)
        {
            mmi_imps_entry_chat_member();
            DeleteScreenIfPresent(SCR_ID_IMPS_PROGRESS);
        }
        else
        {
            if (IsScreenPresent(SCR_ID_IMPS_PROGRESS))
            {
                HistoryReplace(SCR_ID_IMPS_PROGRESS, SCR_ID_IMPS_CHAT_MEMBER, mmi_imps_entry_chat_member);
            }
            else
            {
                if (imps_p->room_info.member)
                {
                    OslMfree(imps_p->room_info.member);
                    imps_p->room_info.member = NULL;
                }                
            }
        }
    }
    else
    {
        mmi_imps_util_disp_err_popup(mmi_imps_util_get_err_str(result));
        DeleteScreenIfPresent(SCR_ID_IMPS_PROGRESS);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_chat_add_to_rejected
 * DESCRIPTION
 *  highlight handle of add user to rejected list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_chat_add_to_rejected(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_entry_add_to_rejected_confirm, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_add_to_rejected_confirm
 * DESCRIPTION
 *  confirmation of add user to rejected list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_add_to_rejected_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_entry_confirm(STR_ID_IMPS_ADD_TO_REJ, mmi_imps_chat_add_to_rejected, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_chat_add_to_rejected
 * DESCRIPTION
 *  add user to rejected list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_chat_add_to_rejected(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    imps_entity_list_struct *user_list = OslMalloc(sizeof(imps_entity_list_struct));
    imps_entity_list_struct *joined_user = imps_p->room_info.joined_user;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* display progressing screen */
    mmi_imps_display_progressing();
    DeleteScreenIfPresent(SCR_ID_IMPS_CHAT_JOINED_OPT);

    memset(user_list, 0, sizeof(user_list));
    user_list->entity_count = 1;
    user_list->entity[0].entity_type = IMPS_ENTITY_TYPE_USER;
    strcpy((S8*) user_list->entity[0].id, (S8*) joined_user->entity[imps_p->room_info.curr_sel_user].id);

    /* send request to PS */
#ifdef IMPS_TEST_CODE
    mmi_imps_add_reject_user_done(0);
#else 
    mmi_imps_ps_reject_group_user_req(MMI_TRUE, (void*)user_list);
#endif 
    OslMfree(user_list);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_add_reject_user_done
 * DESCRIPTION
 *  function after add rejected user
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_add_reject_user_done(S32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == IMPS_OK /* IMPS_OK */ )
    {
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
        DeleteScreenIfPresent(SCR_ID_IMPS_PROGRESS);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_delete_reject_user_done
 * DESCRIPTION
 *  function after delete rejected user
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_delete_reject_user_done(S32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == 0 /* IMPS_OK */ )
    {
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
        DeleteScreenIfPresent(SCR_ID_IMPS_PROGRESS);
        DeleteScreenIfPresent(SCR_ID_IMPS_CHAT_REJECTED);
    }

}


#define BLOCK_IMPS


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_block_grant
 * DESCRIPTION
 *  Highlight handler of Glock/Grant option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_block_grant(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_entry_block_grant, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_block_grant
 * DESCRIPTION
 *  Entry funtion of Glock/Grant option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_block_grant(void)
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

    mmi_imps_display_progressing();

#ifdef IMPS_TEST_CODE
    mmi_imps_block_grant_done(0);
#else /* IMPS_TEST_CODE */ 
    if (imps_p->cont_info.cont_list[imps_p->cont_info.curr_cont].comm_state & IMPS_CONT_BLOCK)
    {
        mmi_imps_ps_block_entity_req(IMPS_GRANT);
    }
    else
    {
        mmi_imps_ps_block_entity_req(IMPS_BLOCK);
    }
#endif /* IMPS_TEST_CODE */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_block_grant_done
 * DESCRIPTION
 *  Callback function when finish blocking/granting a contact
 * PARAMETERS
 *  result      [IN]        
 *  S32(?)      [IN]        Result of request(?)(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_block_grant_done(S32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == 0 /* IMPS_OK */ )
    {
        if (imps_p->cont_info.cont_list[imps_p->cont_info.curr_cont].comm_state & IMPS_CONT_BLOCK)      /* currently blocked */
        {
            imps_p->cont_info.cont_list[imps_p->cont_info.curr_cont].comm_state &= ~(IMPS_CONT_BLOCK);
        }
        else
        {
            imps_p->cont_info.cont_list[imps_p->cont_info.curr_cont].comm_state |= IMPS_CONT_BLOCK;
        }

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
        mmi_imps_util_del_scr_after_progress(SCR_ID_IMPS_CONT);
    }
}

#define ROOM_IMPS


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_room_reset_cntx
 * DESCRIPTION
 *  Reset global context of a chat room
 * PARAMETERS
 *  room        [IN]        Address of the conext buffer of a room
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_room_reset_cntx(mmi_imps_room_struct *room)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    mmi_imps_chat_session_struct *chat_session;
    mmi_imps_invite_session_struct *invite_session;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reset chat sessions */
    for (i = 0; i < IMPS_MAX_CHAT_MSG_COUNT; i++)
    {
        chat_session = &imps_p->chat_info.chat_session[i];
        if (chat_session->session_id > 0)
        {
            if (mmi_imps_util_is_id_same((S8*) room->room_id, (S8*) chat_session->room_id))   /* session of current closed chat room */
            {
                chat_session->session_id = 0;
                chat_session->input_buff[0] = 0;
                chat_session->room_id[0] = 0;
            }
        }
    }

    /* reset invite sessions */
    for (i = 0; i < IMPS_MAX_INVITEE_SESSION; i++)
    {
        invite_session = &imps_p->invite_info.invite_session[i];
        if (invite_session->session_id > 0)
        {
            if (mmi_imps_util_is_id_same((S8*) room->room_id, (S8*) invite_session->room_id)) /* session of current closed chat room */
            {
                invite_session->session_id = 0;
                invite_session->cont_id[0] = 0;
                invite_session->room_id[0] = 0;
            }
        }
    }

    memset(room, 0, sizeof(mmi_imps_room_struct));
    room->tab_index = 0xff;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_new_room_string
 * DESCRIPTION
 *  Append starting
 * PARAMETERS
 *  chat_buff       [IN/OUT]        Buffer to store starting text.
 *  room            [IN]            String of room index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_new_room_string(S8 *chat_buff, S8 *room)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_color_buffer_writer_struct writer;
    BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    chat_buff[0] = 0;
    chat_buff[1] = 0;
    wgui_color_buffer_create_writer(&writer, (U8*) chat_buff, IMPS_MAX_CHAT_BUFF * ENCODING_LENGTH);
    wgui_color_buffer_write_char(&writer, GUI_INPUT_COLOR_46);

    wgui_color_buffer_write_string(&writer, (U8*) GetString(STR_ID_IMPS_NEW_ROOM_CREATED), MMI_FALSE, &result);
    wgui_color_buffer_write_string(&writer, (U8*) L" [", MMI_FALSE, &result);
    wgui_color_buffer_write_string(&writer, (U8*) room, MMI_FALSE, &result);
    wgui_color_buffer_write_string(&writer, (U8*) L"]\n\n", MMI_FALSE, &result);
    wgui_color_buffer_write_char(&writer, GUI_INPUT_MARKER_RESET_ALL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_chat_room
 * DESCRIPTION
 *  Highlight handler of Chat Rooms option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_chat_room(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_entry_room, KEY_EVENT_UP);
    SetKeyHandler(mmi_imps_entry_room, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_room
 * DESCRIPTION
 *  Entry chat room list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_room(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S32 i, j;
    S32 count = (S32) imps_p->room_info.no_rooms;
    U16 img_list[IMPS_MAX_NO_ROOM];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_IMPS_CHAT_ROOM, NULL, mmi_imps_entry_room, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMPS_CHAT_ROOM);

    SetParentHandler(0);

    RegisterHighlightHandler(mmi_imps_hilite_room);

    if (count == 0)
    {
        mmi_ucs2cpy((S8*) subMenuData[0], (S8*) GetString(STR_GLOBAL_EMPTY_LIST));
        img_list[0] = IMG_GLOBAL_L1;
        count = 1;
        subMenuDataPtrs[0] = subMenuData[0];
    }
    else
    {
        for (i = 0, j = 0; i < IMPS_MAX_NO_ROOM; i++)
        {
            mmi_imps_room_struct *room = &imps_p->room_info.room_list[i];

            if (room->is_used)
            {
                memset(subMenuData[j], 0, MAX_SUB_MENU_SIZE);

                mmi_imps_util_copy_with_dot((S8*) room->room_name, (S8*) subMenuDataPtrs[j], MAX_SUBMENU_CHARACTERS);

                subMenuDataPtrs[j] = subMenuData[j];

                if (room->type == IMPS_ROOM_TYPE_SINGLE)
                {
                    img_list[j] = IMG_ID_IMPS_TALK_MENU;
                }
                else
                {
                    img_list[j] = IMG_ID_IMPS_CHATROOM_MENU;
                }
                j++;
            }
        }
    }

    ShowCategory84Screen(
        STR_ID_IMPS_CHAT_ROOMS,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        count,
        (U8 **) subMenuDataPtrs,
        (U16*) img_list,
        0,
        0,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_imps_entry_room_opt, KEY_EVENT_UP);
    SetKeyHandler(mmi_imps_entry_room_opt, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_room
 * DESCRIPTION
 *  Entry chat room list
 * PARAMETERS
 *  index       [IN]        Index of current highlighting chat room
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_room(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    imps_p->room_info.curr_item = (U8) index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_room_opt
 * DESCRIPTION
 *  Entry option screen for chat room
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_room_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 numItems;
    U16 nStrItemList[5];
    U8 *guiBuffer;
    U16 menu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imps_p->room_info.no_rooms == 0)
    {
        menu_id = MENU_ID_IMPS_ROOM_OPT2;
    }
    else
    {
        menu_id = MENU_ID_IMPS_ROOM_OPT;
    }

    EntryNewScreen(SCR_ID_IMPS_CHAT_ROOM_OPT, NULL, mmi_imps_entry_room_opt, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMPS_CHAT_ROOM_OPT);

    SetParentHandler(menu_id);
    numItems = GetNumOfChild_Ext(menu_id);
    GetSequenceStringIds_Ext(menu_id, nStrItemList);
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
 *  mmi_imps_hilite_room_open
 * DESCRIPTION
 *  Highlight handler of Chat Room -> Create
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_room_open(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_pre_entry_room_open, KEY_EVENT_UP);
    SetKeyHandler(mmi_imps_pre_entry_room_open, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_pre_entry_room_open
 * DESCRIPTION
 *  Pre-Entry function for Create Room option. Reset all buffers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_pre_entry_room_open(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_imps_util_get_empty_room_slot() == IMPS_MAX_NO_ROOM)        /* all chat rooms are occupied */
    {
        mmi_imps_util_disp_err_popup(STR_ID_IMPS_ERR_CHAT_ROOM_FULL);
        return;
    }

    if (imps_p->room_info.inline_open_room == NULL)
    {
        imps_p->room_info.inline_open_room = OslMalloc(sizeof(mmi_imps_room_inline_struct));
    }

    imps_p->room_info.inline_open_room->room_name[0] = 0;
    imps_p->room_info.inline_open_room->topic[0] = 0;
    imps_p->room_info.inline_open_room->welcome[0] = 0;
    imps_p->room_info.inline_open_room->sname[0] = 0;
    mmi_imps_entry_room_open();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_room_open
 * DESCRIPTION
 *  Inline editor screen for create/edit a chat room
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_room_open(void)
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
    EntryNewScreen(SCR_ID_IMPS_CHAT_ROOM_OPEN, mmi_imps_exit_room_open, NULL, NULL);

    InitializeCategory57Screen();

    mmi_imps_room_create_fill_inline_struct();

    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMPS_CHAT_ROOM_OPEN);

    inputBuffer = GetCurrNInputBuffer(SCR_ID_IMPS_CHAT_ROOM_OPEN, &inputBufferSize);

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, IMPS_INLINE_EDIT_ROOM, inputBuffer);
    }

    ShowCategory57Screen(
        STR_ID_IMPS_CHAT_ROOMS,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        STR_GLOBAL_EDIT,
        IMG_GLOBAL_BACK,
        STR_GLOBAL_DONE,
        IMG_GLOBAL_BACK,
        IMPS_INLINE_EDIT_ROOM,
        (U16*) g_imps_inline_icons,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_imps_room_create_done, GoBackHistory);

    SetDelScrnIDCallbackHandler(SCR_ID_IMPS_CHAT_ROOM_OPEN, (HistoryDelCBPtr) mmi_imps_room_scr_del_callback);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_exit_room_open
 * DESCRIPTION
 *  Exit function of Inline editor screen for create/edit a chat room
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_exit_room_open(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GenericExitInlineScreen(SCR_ID_IMPS_CHAT_ROOM_OPEN, mmi_imps_entry_room_open);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_room_scr_del_callback
 * DESCRIPTION
 *  Function to free memory when inline editor screen is deleted.
 * PARAMETERS
 *  param       [?]     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_imps_room_scr_del_callback(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_free_room_mem();

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_free_room_mem
 * DESCRIPTION
 *  Free memory for editing room
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_free_room_mem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imps_p->room_info.inline_open_room && imps_p->gen_info.curr_action != MSG_ID_MMI_IMPS_CREATE_GROUP_REQ)
    {
        OslMfree(imps_p->room_info.inline_open_room);
        imps_p->room_info.inline_open_room = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_room_create_fill_inline_struct
 * DESCRIPTION
 *  Fill inline editor structure for Edit/Create Room screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_room_create_fill_inline_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_room_inline_struct *inline_open_room = imps_p->room_info.inline_open_room;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* keneng : access type */
    inline_open_room->open_restrict_list[0] = (U8*) GetString(STR_ID_IMPS_OPEN);
    inline_open_room->open_restrict_list[1] = (U8*) GetString(STR_ID_IMPS_RESTRICT);

    /* Yes/No */
    inline_open_room->yes_no_list[0] = (U8*) GetString(STR_GLOBAL_YES);
    inline_open_room->yes_no_list[1] = (U8*) GetString(STR_GLOBAL_NO);    

    /* Name */
    SetInlineItemActivation(&wgui_inline_items[0], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[0], (U8*) GetString(STR_ID_IMPS_CHAT_ROOM_NAME));
    SetInlineItemActivation(&wgui_inline_items[1], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[1],
        STR_ID_IMPS_CHAT_ROOM_NAME,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        (U8*) inline_open_room->room_name,
        IMPS_MAX_NAME_LEN,
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
        (U8*) inline_open_room->sname,
        IMPS_MAX_NAME_LEN,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[3], mmi_imps_hilite_prof_full_edit);

    /* Topic */
    SetInlineItemActivation(&wgui_inline_items[4], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[4], (U8*) GetString(STR_ID_IMPS_TOPIC));
    SetInlineItemActivation(&wgui_inline_items[5], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[5],
        STR_ID_IMPS_TOPIC,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        (U8*) inline_open_room->topic,
        IMPS_MAX_NAME_LEN,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[5], mmi_imps_hilite_prof_full_edit);

    /* Welcome Text */
    SetInlineItemActivation(&wgui_inline_items[6], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[6], (U8*) GetString(STR_ID_IMPS_WELCOME_TEXT));
    SetInlineItemActivation(&wgui_inline_items[7], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[7],
        STR_ID_IMPS_WELCOME_TEXT,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        (U8*) inline_open_room->welcome,
        IMPS_MAX_NOTE_LEN,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[7], mmi_imps_hilite_prof_full_edit);

    /* keneng : access type */
    SetInlineItemActivation(&wgui_inline_items[8], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[8], (U8*) GetString(STR_ID_IMPS_ACCESS_TYPE));
    SetInlineItemActivation(&wgui_inline_items[9], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(&wgui_inline_items[9], 2, inline_open_room->open_restrict_list, &inline_open_room->access_type);

    /* Subscribe notify */
    SetInlineItemActivation(&wgui_inline_items[10], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[10], (U8*) GetString(STR_ID_IMPS_SUBSCRIBE_NOTIFY));
    SetInlineItemActivation(&wgui_inline_items[11], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(&wgui_inline_items[11], 2, inline_open_room->yes_no_list, &inline_open_room->subscribe_notify);        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_room_create_done
 * DESCRIPTION
 *  Done key handler of Room -> Edit option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_room_create_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_entry_confirm(STR_GLOBAL_OPEN, mmi_imps_room_create_yes, mmi_imps_util_go_back_2_hist);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_room_create_yes
 * DESCRIPTION
 *  Confirm to create/edit a chat room
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_room_create_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((S8*) imps_p->room_info.inline_open_room->room_name) == 0)
    {
        mmi_imps_util_disp_err_popup(STR_ID_IMPS_ERR_EMPTY_NAME);
        return;
    }
    else if (mmi_ucs2strlen((S8*) imps_p->room_info.inline_open_room->sname) == 0)
    {
        mmi_imps_util_disp_err_popup(STR_ID_IMPS_ERR_EMPTY_DISP_NAME);
        return;
    }
    else if (mmi_imps_util_is_group_name_valid((S8*) imps_p->room_info.inline_open_room->room_name) == FALSE)
    {
        mmi_imps_util_disp_err_popup(STR_ID_IMPS_INVALID_GROUP_NAME);
        return;
    }

    mmi_imps_display_progressing();

#ifdef IMPS_TEST_CODE
    mmi_imps_room_create_finish(0);
#else /* IMPS_TEST_CODE */ 
    /* send request to PS */
    mmi_imps_ps_create_group_req();
#endif /* IMPS_TEST_CODE */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_room_create_finish
 * DESCRIPTION
 *  Finish creating/editing a chat room
 * PARAMETERS
 *  result      [IN]        Result of the operation
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_room_create_finish(S32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == 0 /* IMPS_OK */ )
    {
        /* finding empty chat room */
        S32 i;
        mmi_imps_room_struct *room = NULL;
        mmi_imps_room_inline_struct *inline_open_room = imps_p->room_info.inline_open_room;

        for (i = 0; i < IMPS_MAX_NO_ROOM; i++)
        {
            room = &imps_p->room_info.room_list[i];
            if (room->is_used == FALSE)
            {
                break;
            }
        }

        /* shall always find an empty chat room */
        MMI_ASSERT(i < IMPS_MAX_NO_ROOM);

        memset(room, 0, sizeof(mmi_imps_room_struct));

        /* update group list */
        strcpy((S8*) room->room_id, (S8*) inline_open_room->room_id);
        mmi_ucs2cpy((S8*) room->room_name, (S8*) inline_open_room->room_name);

        if (mmi_ucs2strlen((S8*) inline_open_room->topic))
        {
            mmi_ucs2cpy((S8*) room->room_topic, (S8*) inline_open_room->topic);
        }

        if (mmi_ucs2strlen((S8*) inline_open_room->welcome))
        {
            mmi_ucs2cpy((S8*) room->welcome, (S8*) inline_open_room->welcome);
        }

        if (mmi_ucs2strlen((S8*) inline_open_room->sname))
        {
            mmi_ucs2cpy((S8*) room->sname, (S8*) inline_open_room->sname);
        }

        room->subs_notify = TRUE;
        if (inline_open_room->subscribe_notify == 1)
        {
            room->subs_notify = FALSE;
        }

        /* keneng : access type */
        room->access_type = (U8) inline_open_room->access_type;

        room->pri_level = IMPS_PRI_LEVEL_ADM;

        room->is_used = TRUE;
        room->type = IMPS_ROOM_TYPE_GROUP_CREATE;

        imps_p->chat_info.curr_room = (U8) i;
        imps_p->room_info.no_rooms++;

        /* update display buffer */
        mmi_imps_new_room_string((S8*) room->chat_buff, (S8*) room->room_name);

        /* update list of chat rooms */
        room->tab_index = imps_p->gen_info.curr_tab = imps_p->gen_info.no_tab;
        imps_p->gen_info.no_tab++;

        if (imps_p->gen_info.is_reentry)
        {
            mmi_imps_re_entry_app();
        }
        else
        {
            if (GetActiveScreenId() == SCR_ID_IMPS_PROGRESS)
            {
                mmi_imps_entry_chat();
                mmi_imps_util_del_scr_after_progress(SCR_ID_IMPS_CONT);
                DeleteScreenIfPresent(SCR_ID_IMPS_CONT);
            }
            else
            {
                mmi_imps_util_del_scr_after_progress(SCR_ID_IMPS_CONT);
                HistoryReplace(SCR_ID_IMPS_CONT, SCR_ID_IMPS_CHAT, mmi_imps_entry_chat);
            }
        }
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
            mmi_imps_util_del_scr_after_progress(SCR_ID_IMPS_CHAT_ROOM);
        }
    }

    /* free allocated memory */
    mmi_imps_free_room_mem();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_room_search
 * DESCRIPTION
 *  Highlight handler of Chat Room -> Search
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_room_search(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_room_pre_entry_search, KEY_EVENT_UP);
    SetKeyHandler(mmi_imps_room_pre_entry_search, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_room_pre_entry_search
 * DESCRIPTION
 *  Pre-entry inline editor screen for searching chat room
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_room_pre_entry_search(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_imps_util_get_empty_room_slot() == IMPS_MAX_NO_ROOM)        /* all chat rooms are occupied */
    {
        mmi_imps_util_disp_err_popup(STR_ID_IMPS_ERR_CHAT_ROOM_FULL);
        return;
    }

    if (imps_p->search_room == NULL)
    {
        imps_p->search_room = (mmi_imps_search_room_struct*) OslMalloc(sizeof(mmi_imps_search_room_struct));
    }

    memset(imps_p->search_room, 0, sizeof(mmi_imps_search_room_struct));

    mmi_imps_entry_room_search();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_room_search
 * DESCRIPTION
 *  Entry inline editor screen for searching chat room
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_room_search(void)
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
    EntryNewScreen(SCR_ID_IMPS_CHAT_ROOM_SEARCH, mmi_imps_exit_room_search, NULL, NULL);

    InitializeCategory57Screen();

    mmi_imps_room_search_fill_inline_struct();

    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMPS_CHAT_ROOM_SEARCH);

    inputBuffer = GetCurrNInputBuffer(SCR_ID_IMPS_CHAT_ROOM_SEARCH, &inputBufferSize);

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, IMPS_INLINE_SEARCH_ROOM, inputBuffer);
    }

    ShowCategory57Screen(
        STR_GLOBAL_SEARCH,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        STR_GLOBAL_EDIT,
        IMG_GLOBAL_BACK,
        STR_GLOBAL_DONE,
        IMG_GLOBAL_BACK,
        IMPS_INLINE_SEARCH_ROOM,
        (U16*) g_imps_inline_icons,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_imps_entryt_room_search_opt, GoBackHistory);

    SetDelScrnIDCallbackHandler(SCR_ID_IMPS_CHAT_ROOM_SEARCH, (HistoryDelCBPtr) mmi_imps_search_scr_del_callback);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_exit_room_search
 * DESCRIPTION
 *  Entry inline editor screen for searching chat room
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_exit_room_search(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();

    AddHistoryEx(
        SCR_ID_IMPS_CHAT_ROOM_SEARCH,
        mmi_imps_entry_room_search,
        GetCategoryHistory,
        GetCategory57DataSize,
        GetCategory57Data,
        NULL,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_room_search_fill_inline_struct
 * DESCRIPTION
 *  Fill inline editor structure for searching chat room screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_room_search_fill_inline_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_search_room_struct *search_room = imps_p->search_room;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ID */
    SetInlineItemActivation(&wgui_inline_items[0], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[0], (U8*) GetString(STR_ID_IMPS_ROOM_ID));
    SetInlineItemActivation(&wgui_inline_items[1], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[1],
        STR_ID_IMPS_ROOM_ID,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        (U8*) search_room->room_id,
        IMPS_MAX_ID_LEN,
        INPUT_TYPE_USE_ONLY_ENGLISH_MODES | INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[1], mmi_imps_hilite_prof_full_edit);    
    
    /* Name */
    SetInlineItemActivation(&wgui_inline_items[2], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[2], (U8*) GetString(STR_ID_IMPS_CHAT_ROOM_NAME));
    SetInlineItemActivation(&wgui_inline_items[3], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[3],
        STR_ID_IMPS_CHAT_ROOM_NAME,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        (U8*) search_room->room_name,
        IMPS_MAX_NAME_LEN,
        INPUT_TYPE_USE_ONLY_ENGLISH_MODES | INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[3], mmi_imps_hilite_prof_full_edit);

    /* Topic */
    SetInlineItemActivation(&wgui_inline_items[4], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[4], (U8*) GetString(STR_ID_IMPS_TOPIC));
    SetInlineItemActivation(&wgui_inline_items[5], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[5],
        STR_ID_IMPS_TOPIC,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        (U8*) search_room->room_topic,
        IMPS_MAX_NAME_LEN,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[5], mmi_imps_hilite_prof_full_edit);

    /* Owner */
    SetInlineItemActivation(&wgui_inline_items[6], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[6], (U8*) GetString(STR_ID_IMPS_OWNER));
    SetInlineItemActivation(&wgui_inline_items[7], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[7],
        STR_ID_IMPS_OWNER,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        (U8*) search_room->room_owner,
        IMPS_MAX_ID_LEN,
        INPUT_TYPE_USE_ONLY_ENGLISH_MODES | INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[7], mmi_imps_hilite_prof_full_edit);

    /* Joined User */
    SetInlineItemActivation(&wgui_inline_items[8], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[8], (U8*) GetString(STR_ID_IMPS_JOINED_USER));
    SetInlineItemActivation(&wgui_inline_items[9], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[9],
        STR_ID_IMPS_JOINED_USER,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        (U8*) search_room->room_joined_user,
        IMPS_MAX_ID_LEN,
        INPUT_TYPE_USE_ONLY_ENGLISH_MODES | INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[9], mmi_imps_hilite_prof_full_edit);

    /* Autojoined user */
    SetInlineItemActivation(&wgui_inline_items[10], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[10], (U8*) GetString(STR_ID_IMPS_AUTO_JOINED_USER));
    SetInlineItemActivation(&wgui_inline_items[11], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[11],
        STR_ID_IMPS_AUTO_JOINED_USER,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        (U8*) search_room->room_autojoin_user,
        IMPS_MAX_ID_LEN,
        INPUT_TYPE_USE_ONLY_ENGLISH_MODES | INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[11], mmi_imps_hilite_prof_full_edit);    
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entryt_room_search_opt
 * DESCRIPTION
 *  "Done" key handler in Chat Room Search screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entryt_room_search_opt(void)
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
    EntryNewScreen(SCR_ID_IMPS_SEARCH_OPT, NULL, mmi_imps_entryt_room_search_opt, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMPS_SEARCH_OPT);
    SetParentHandler(MENU_ID_IMPS_SEARCH_OPT);
    numItems = GetNumOfChild(MENU_ID_IMPS_SEARCH_OPT);
    GetSequenceStringIds(MENU_ID_IMPS_SEARCH_OPT, nStrItemList);

    SetHiliteHandler(MENU_ID_IMPS_SEARCH_OPT_SEARCH, mmi_imps_hilite_room_search_done);
    SetHiliteHandler(MENU_ID_IMPS_SEARCH_OPT_QUIT, mmi_imps_hilite_room_search_quit);
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
 *  mmi_imps_hilite_room_search_done
 * DESCRIPTION
 *  Highlight handler of Chat Room Search -> Done option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_room_search_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_room_search_start, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_room_search_quit
 * DESCRIPTION
 *  Highlight handler of Chat Room Search -> Quit option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_room_search_quit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_room_search_quit, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_room_search_start
 * DESCRIPTION
 *  Start searching chat rooms
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_room_search_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((S8*) imps_p->search_room->room_id) == 0 &&
        mmi_ucs2strlen((S8*) imps_p->search_room->room_name) == 0 &&
        mmi_ucs2strlen((S8*) imps_p->search_room->room_topic) == 0 &&
        mmi_ucs2strlen((S8*) imps_p->search_room->room_owner) == 0 &&
        mmi_ucs2strlen((S8*) imps_p->search_room->room_joined_user) == 0 &&
        mmi_ucs2strlen((S8*) imps_p->search_room->room_autojoin_user) == 0)
    {
        mmi_imps_util_disp_err_popup(STR_ID_IMPS_EMPTY_INPUT);
        return;
    }

    imps_p->search_result.search_cause = IMPS_SEARCH_ROOM;

    /* rest previous searched data */
    imps_p->search_result.count = 0;

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
#ifdef IMPS_TEST_CODE
    mmi_imps_entry_search_result();
    DeleteScreenIfPresent(SCR_ID_IMPS_PROGRESS);
#else /* IMPS_TEST_CODE */ 
    mmi_imps_ps_search_req(IMPS_SEARCH_ROOM);
#endif /* IMPS_TEST_CODE */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_room_close
 * DESCRIPTION
 *  Highlight handler of Room List -> Close option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_room_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_entry_room_close, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_room_close
 * DESCRIPTION
 *  Display confirmation screen for the user to decide close chat room of not.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_room_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_entry_confirm(STR_GLOBAL_CLOSE, mmi_imps_room_close, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_room_close
 * DESCRIPTION
 *  Handler of Room List -> Close option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_room_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;
    mmi_imps_room_struct *room;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* find out the location of chat room in the list */
    for (i = 0, j = 0; i < IMPS_MAX_NO_ROOM; i++)
    {
        if (imps_p->room_info.room_list[i].is_used)
        {
            if (j == (S32) imps_p->room_info.curr_item)
            {
                break;
            }
            else
            {
                j++;
            }
        }
    }

    room = &imps_p->room_info.room_list[i];
    imps_p->chat_info.curr_room = i;

#ifndef IMPS_TEST_CODE
    /* if it's a group, shall send request to protocol */
    if (room->type == IMPS_ROOM_TYPE_GROUP_CREATE)
    {
        /* send delete group request */
        mmi_imps_display_progressing();
        mmi_imps_ps_del_group_req(room->room_id);
    }
    else if (room->type == IMPS_ROOM_TYPE_GROUP_JOIN)
    {
        /* send leave group request */
        mmi_imps_display_progressing();
        mmi_imps_ps_leave_group_req(room->room_id);
    }
    else
    {
        /*
         * single talk, close room directly, 
         * for other chat rooms, because always reported as success, 
         * we always clear context for all cases.
         */
        mmi_imps_room_close_finished(room);
        mmi_imps_util_disp_popup_done();
        DeleteUptoScrID(SCR_ID_IMPS_CHAT_ROOM);
    }

#else /* IMPS_TEST_CODE */ 
    mmi_imps_room_close_finished(room);
    mmi_imps_util_disp_popup_done();
    DeleteUptoScrID(SCR_ID_IMPS_CHAT_ROOM);
    DeleteScreenIfPresent(SCR_ID_IMPS_CHAT_ROOM);
#endif /* IMPS_TEST_CODE */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_room_join
 * DESCRIPTION
 *  Highlight handler of Room List -> Join option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_room_join(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_pre_entry_room_direct_join, KEY_EVENT_UP);
    SetKeyHandler(mmi_imps_pre_entry_room_direct_join, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_pre_entry_room_direct_join
 * DESCRIPTION
 *  Pre-Entry function of Room->Join option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_pre_entry_room_direct_join(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_imps_util_get_empty_room_slot() == IMPS_MAX_NO_ROOM)        /* all chat rooms are occupied */
    {
        mmi_imps_util_disp_err_popup(STR_ID_IMPS_ERR_CHAT_ROOM_FULL);
        return;
    }

    if (imps_p->room_info.inline_join == NULL)
    {
        imps_p->room_info.inline_join = OslMalloc(sizeof(mmi_imps_join_inline_struct));
    }

    /* reset buffer */
    imps_p->room_info.inline_join->disclose_id = 0;
    imps_p->room_info.inline_join->sname[0] = 0;
    imps_p->room_info.inline_join->room_id[0] = 0;
    mmi_imps_entry_room_direct_join();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_room_direct_join
 * DESCRIPTION
 *  Entry function of Room->Join option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_room_direct_join(void)
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
    EntryNewScreen(SCR_ID_IMPS_ROOM_JOIN_DIRECT, mmi_imps_eixt_room_direct_join, NULL, NULL);

    InitializeCategory57Screen();

    mmi_imps_room_join_fill_inline_struct();

    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMPS_ROOM_JOIN_DIRECT);

    inputBuffer = GetCurrNInputBuffer(SCR_ID_IMPS_ROOM_JOIN_DIRECT, &inputBufferSize);

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, IMPS_INLINE_ROOM_JOIN_DIRECT, inputBuffer);
    }

    ShowCategory57Screen(
        STR_ID_IMPS_JOIN,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        STR_GLOBAL_EDIT,
        IMG_GLOBAL_BACK,
        STR_GLOBAL_DONE,
        IMG_GLOBAL_BACK,
        IMPS_INLINE_ROOM_JOIN_DIRECT,
        (U16*) g_imps_inline_icons,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_imps_room_direct_join_confirm, GoBackHistory);

    SetDelScrnIDCallbackHandler(SCR_ID_IMPS_ROOM_JOIN_DIRECT, (HistoryDelCBPtr) mmi_imps_join_scr_del_callback);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_eixt_room_direct_join
 * DESCRIPTION
 *  Exit function of Room->Join option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_eixt_room_direct_join(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GenericExitInlineScreen(SCR_ID_IMPS_ROOM_JOIN_DIRECT, mmi_imps_entry_room_direct_join);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_room_join_fill_inline_struct
 * DESCRIPTION
 *  Fill inline struct of Room->Join screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_room_join_fill_inline_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_join_inline_struct *join_room = imps_p->room_info.inline_join;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    join_room->yes_no_list[0] = (U8*) GetString(STR_GLOBAL_YES);
    join_room->yes_no_list[1] = (U8*) GetString(STR_GLOBAL_NO);

    /* Room Name */
    SetInlineItemActivation(&wgui_inline_items[0], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[0], (U8*) GetString(STR_ID_IMPS_ROOM_ID));
    SetInlineItemActivation(&wgui_inline_items[1], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[1],
        STR_ID_IMPS_CHAT_ROOM_NAME,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        (U8*) join_room->room_id,
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
        (U8*) join_room->sname,
        IMPS_MAX_NAME_LEN,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[3], mmi_imps_hilite_prof_full_edit);

    /* Disclose ID */
    SetInlineItemActivation(&wgui_inline_items[4], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[4], (U8*) GetString(STR_ID_IMPS_DISCLOSE_ID));
    SetInlineItemActivation(&wgui_inline_items[5], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(&wgui_inline_items[5], 2, join_room->yes_no_list, &join_room->disclose_id);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_room_direct_join_confirm
 * DESCRIPTION
 *  Display confirmation screen for joining a chat room
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_room_direct_join_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_entry_confirm(STR_ID_IMPS_JOIN, mmi_imps_room_direct_join_yes, mmi_imps_util_go_back_2_hist);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_room_direct_join_yes
 * DESCRIPTION
 *  Proceed joining chat room
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_room_direct_join_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *id = OslMalloc(IMPS_MAX_ID_LEN * ENCODING_LENGTH);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if the room is already joined */
    mmi_ucs2_to_asc(id, (S8*) imps_p->room_info.inline_join->room_id);
    if (mmi_imps_util_is_room_joined(id))
    {
        mmi_imps_util_disp_err_popup(STR_ID_IMPS_ERR_ROOM_ALREADY_JOINED);
    }
    else if (mmi_ucs2strlen((S8*) imps_p->room_info.inline_join->sname) == 0)
    {
        mmi_imps_util_disp_err_popup(STR_ID_IMPS_ERR_EMPTY_DISP_NAME);
    }
    else
    {
        mmi_imps_display_progressing();
        imps_p->room_info.join_cause = IMPS_JOIN_DIRECT;

        mmi_imps_ps_join_group_req(id);
    }

    OslMfree(id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_room_jump_to
 * DESCRIPTION
 *  Highlight handler of Room List -> Jump To option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_room_jump_to(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_room_jump_to, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_room_jump_to
 * DESCRIPTION
 *  Handler of Room List -> Jump To option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_room_jump_to(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;
    mmi_imps_room_struct *room;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0, j = 0; i < IMPS_MAX_NO_ROOM; i++)
    {
        if (imps_p->room_info.room_list[i].is_used)
        {
            if (j == (S32) imps_p->room_info.curr_item)
            {
                break;
            }
            else
            {
                j++;
            }
        }
    }

    /* if it's a group, shall send request to protocol */

    room = &imps_p->room_info.room_list[i];
    imps_p->chat_info.curr_room = (U8) i;
    imps_p->gen_info.curr_tab = room->tab_index;

    mmi_imps_entry_chat();
    DeleteUptoScrID(SCR_ID_IMPS_CONT);
    DeleteScreenIfPresent(SCR_ID_IMPS_CONT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_pre_entry_join
 * DESCRIPTION
 *  Pre-Entry inline editor screen for joining a chat room.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_pre_entry_join(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    mmi_imps_room_struct *room;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if it's dupicated joined */
    for (i = 0; i < IMPS_MAX_NO_ROOM; i++)
    {
        room = &imps_p->room_info.room_list[i];
        if (room->is_used)
        {
            if (IsScreenPresent(SCR_ID_IMPS_SEARCH_RESULT))
            {
                if (mmi_imps_util_is_id_same
                    ((S8*) imps_p->search_result.entity[imps_p->search_result.curr_item].id, (S8*) room->room_id))
                {
                    /* found match */
                    mmi_imps_util_disp_err_popup(STR_ID_IMPS_ERR_ROOM_ALREADY_JOINED);
                    return;
                }
            }
            else if (IsScreenPresent(SCR_ID_IMPS_INVITATION_IND))
            {
                if (mmi_imps_util_is_id_same
                    ((S8*) imps_p->invite_info.invite_pending_list[imps_p->invite_info.curr_pend_invite].node->group_id, (S8*) room->room_id))
                {
                    /* found match */
                    mmi_imps_util_disp_err_popup(STR_ID_IMPS_ERR_ROOM_ALREADY_JOINED);
                    return;
                }                
            }
        }
    }

    if (mmi_imps_util_get_empty_room_slot() == IMPS_MAX_NO_ROOM)        /* all chat rooms are occupied */
    {
        mmi_imps_util_disp_err_popup(STR_ID_IMPS_ERR_CHAT_ROOM_FULL);
        return;
    }

    if (imps_p->room_info.inline_join == NULL)
    {
        imps_p->room_info.inline_join = OslMalloc(sizeof(mmi_imps_join_inline_struct));
    }

    /* reset buffer */
    imps_p->room_info.inline_join->disclose_id = 0;
    imps_p->room_info.inline_join->sname[0] = 0;
    mmi_imps_entry_join();

    /* DeleteScreenIfPresent(SCR_ID_IMPS_CHAT_ROOM_JOIN); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_join
 * DESCRIPTION
 *  Entry inline editor screen for joining a chat room.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_join(void)
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
    EntryNewScreen(SCR_ID_IMPS_CHAT_ROOM_JOIN, mmi_imps_exit_join, NULL, NULL);

    InitializeCategory57Screen();

    mmi_imps_join_fill_inline_struct();

    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMPS_CHAT_ROOM_JOIN);

    inputBuffer = GetCurrNInputBuffer(SCR_ID_IMPS_CHAT_ROOM_JOIN, &inputBufferSize);

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, IMPS_INLINE_JOIN_ROOM, inputBuffer);
    }

    ShowCategory57Screen(
        STR_ID_IMPS_JOIN,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        STR_GLOBAL_EDIT,
        IMG_GLOBAL_BACK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        IMPS_INLINE_JOIN_ROOM,
        (U16*) g_imps_inline_icons,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_imps_join_room, mmi_imps_join_free_mem_n_back);

    SetDelScrnIDCallbackHandler(SCR_ID_IMPS_CHAT_ROOM_JOIN, (HistoryDelCBPtr) mmi_imps_join_scr_del_callback);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_exit_join
 * DESCRIPTION
 *  Exit function for Join Room screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_exit_join(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GenericExitInlineScreen(SCR_ID_IMPS_CHAT_ROOM_JOIN, mmi_imps_entry_join);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_join_fill_inline_struct
 * DESCRIPTION
 *  Fill inline structure of Join Chat room screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_join_fill_inline_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_join_inline_struct *join_room = imps_p->room_info.inline_join;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    join_room->yes_no_list[0] = (U8*) GetString(STR_GLOBAL_YES);
    join_room->yes_no_list[1] = (U8*) GetString(STR_GLOBAL_NO);

    /* Display Name */
    SetInlineItemActivation(&wgui_inline_items[0], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[0], (U8*) GetString(STR_ID_IMPS_DISPLAY_NAME));
    SetInlineItemActivation(&wgui_inline_items[1], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[1],
        STR_ID_IMPS_DISPLAY_NAME,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        (U8*) join_room->sname,
        IMPS_MAX_NAME_LEN,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[1], mmi_imps_hilite_prof_full_edit);

    /* Disclose ID */
    SetInlineItemActivation(&wgui_inline_items[2], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[2], (U8*) GetString(STR_ID_IMPS_DISCLOSE_ID));
    SetInlineItemActivation(&wgui_inline_items[3], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(&wgui_inline_items[3], 2, join_room->yes_no_list, &join_room->disclose_id);

    /* Subscribe notify */
    SetInlineItemActivation(&wgui_inline_items[4], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[4], (U8*) GetString(STR_ID_IMPS_SUBSCRIBE_NOTIFY));
    SetInlineItemActivation(&wgui_inline_items[5], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(&wgui_inline_items[5], 2, join_room->yes_no_list, &join_room->subscribe_notify);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_join_free_mem_n_back
 * DESCRIPTION
 *  Free inline editor memory and go back to previous screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_join_free_mem_n_back(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_join_free_mem();
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_join_scr_del_callback
 * DESCRIPTION
 *  Callback function when join chat room screen is deleted.
 * PARAMETERS
 *  param       [IN]        Parameter from framework
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_imps_join_scr_del_callback(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imps_p->gen_info.curr_action == 0)  /* nothing happens now */
    {
        mmi_imps_join_free_mem();
    }

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_join_room
 * DESCRIPTION
 *  Display confirmation screen to determine join chat room or not
 * PARAMETERS
 *  void
 *  param(?)        [IN]        Parameter from framework(?)(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_join_room(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_entry_confirm(STR_ID_IMPS_JOIN, mmi_imps_join_room_yes, mmi_imps_util_go_back_2_hist);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_join_room_yes
 * DESCRIPTION
 *  Preceed join a chat room
 * PARAMETERS
 *  void
 *  param(?)        [IN]        Parameter from framework(?)(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_join_room_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_join_inline_struct *join_room = imps_p->room_info.inline_join;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((S8*) join_room->sname) == 0)
    {
        mmi_imps_util_disp_err_popup(STR_ID_IMPS_ERR_EMPTY_DISP_NAME);
        return;
    }

    mmi_imps_display_progressing();

    /* check if it's join from invitation screen of a voluntarily join */
    if (IsScreenPresent(SCR_ID_IMPS_INVITATION_IND))
    {
        mmi_imps_invite_accept();
        imps_p->room_info.join_cause = IMPS_JOIN_FROM_INVITE;
    }
    else
    {
    #ifdef IMPS_TEST_CODE
    #else /* IMPS_TEST_CODE */ 
        imps_p->room_info.join_cause = IMPS_JOIN_FROM_SEARCH;
        mmi_imps_ps_join_group_req((S8*) imps_p->search_result.entity[imps_p->search_result.curr_item].id);
    #endif /* IMPS_TEST_CODE */ 
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_join_room_finished
 * DESCRIPTION
 *  Preceed join a chat room
 * PARAMETERS
 *  msg     [?]     [?]     [?]     [?]
 *  param(?)        [IN]        Parameter from framework(?)(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_join_room_finished(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    mmi_imps_join_group_rsp_struct *rsp = (mmi_imps_join_group_rsp_struct*) msg;
    mmi_imps_room_struct *room;
    mmi_imps_join_inline_struct *inline_join = imps_p->room_info.inline_join;
    U8 join_cause = imps_p->room_info.join_cause;
	U16 *ucs2_folder = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rsp->result == IMPS_OK)
    {
        /* find empty chat room */
        for (i = 0; i < IMPS_MAX_NO_ROOM; i++)
        {
            if (imps_p->room_info.room_list[i].is_used == FALSE)
            {
                break;
            }
        }

        /* copy data to chat room context */
        imps_p->chat_info.curr_room = (U8) i;

        imps_p->room_info.no_rooms++;
        room = &imps_p->room_info.room_list[i];
        memset(room, 0, sizeof(mmi_imps_room_struct));
        room->is_used = TRUE;
        room->type = IMPS_ROOM_TYPE_GROUP_JOIN;
        /* keneng : privilege level */
        room->pri_level = IMPS_PRI_LEVEL_USER;

        if (join_cause == IMPS_JOIN_FROM_SEARCH)    /* entry from search result */
        {
            strcpy((S8*) room->room_id, (S8*) imps_p->search_result.entity[imps_p->search_result.curr_item].id);
        }
        else if (join_cause == IMPS_JOIN_DIRECT)    /* direct join */
        {
            mmi_ucs2_to_asc((S8*) room->room_id, (S8*) inline_join->room_id);
        }
        else    /* invitation result */
        {
            strcpy(
                (S8*) room->room_id,
                (S8*) imps_p->invite_info.invite_pending_list[imps_p->invite_info.curr_pend_invite].node->group_id);
        }

        memset(room->room_name, 0, sizeof(room->room_name));
        /* get room name from room_id */
        if (strchr((S8*) room->room_id, '/') != NULL)
        {
            if (strchr((S8*) room->room_id, '@') != NULL)
            {
                S32 len = strchr((S8*) room->room_id, '@') - strchr((S8*) room->room_id, '/') - 1;
                if ((IMPS_MAX_NAME_LEN - 1) >= len)
                {
                    mmi_asc_n_to_ucs2((S8*) room->room_name, (S8*) (strchr((S8*) room->room_id, '/') + 1), len);
                }
                else
                {
                    mmi_asc_n_to_ucs2((S8*) room->room_name, (S8*) (strchr((S8*) room->room_id, '/') + 1), (IMPS_MAX_NAME_LEN - 4));
                    mmi_ucs2cat((S8*) room->room_name, (S8*) L"...");
                }
            }
            else
            {
                S32 len = strchr((S8*) room->room_id, '/') - ((S8*) room->room_id) - 1;
                S32 totallen = strlen((S8*) room->room_id);
                if ((totallen - len) <= (IMPS_MAX_NAME_LEN - 1))
                {
                    mmi_asc_to_ucs2((S8*) room->room_name, (S8*) (strchr((S8*) room->room_id, '/') + 1));                 
                }
                else
                {
                    mmi_asc_n_to_ucs2((S8*) room->room_name, (S8*) (strchr((S8*) room->room_id, '/') + 1), (IMPS_MAX_NAME_LEN - 4));
                    mmi_ucs2cat((S8*) room->room_name, (S8*) L"...");                    
                }
                
            }
        }
        else
        {
            S32 totallen = strlen((S8*) room->room_id);
            if (totallen <= (IMPS_MAX_NAME_LEN - 1))
            {
                mmi_asc_to_ucs2((S8*) room->room_name, (S8*) room->room_id);
            }
            else
            {
                mmi_asc_n_to_ucs2((S8*) room->room_name, (S8*) room->room_id, (IMPS_MAX_NAME_LEN - 4));
                mmi_ucs2cat((S8*) room->room_name, (S8*) L"...");                 
            }
        }
        

        /* update display buffer */
        mmi_imps_new_room_string((S8*) room->chat_buff, (S8*) room->room_name);

        /* welcome text */
        if (mmi_ucs2strlen((S8*) rsp->welcome_text))
        {
            mmi_ucs2cpy((S8*) room->welcome, (S8*) rsp->welcome_text);
            mmi_ucs2cat((S8*) room->chat_buff, (S8*) GetString(STR_ID_IMPS_WELCOME_TEXT));
            mmi_ucs2cat((S8*) room->chat_buff, (S8*) L":\n");
            mmi_ucs2cat((S8*) room->chat_buff, (S8*) rsp->welcome_text);
            mmi_ucs2cat((S8*) room->chat_buff, (S8*) L"\n\n");
        }

        ucs2_folder = OslMalloc((FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH);
        mmi_imps_util_get_filename_from_fileindex(rsp->joined_users_list.entity_list_file_index, IMPS_LIST_FILE_JOINED, (S8*) ucs2_folder);
        FS_Delete(ucs2_folder);
        OslMfree(ucs2_folder);        

        /* update tab */
        room->tab_index = imps_p->gen_info.curr_tab = imps_p->gen_info.no_tab;
        imps_p->gen_info.no_tab++;

        /* set room's display name as user's name */
        if (rsp->screen_name.entity_type == IMPS_ENTITY_TYPE_SCREEN_NAME)
        {
            mmi_ucs2cpy((S8*) room->sname, (S8*) rsp->screen_name.sname);
        }
        else
        {
            mmi_ucs2cpy((S8*) room->sname, (S8*) inline_join->sname);
        }

        if (imps_p->gen_info.is_reentry)
        {
            mmi_imps_re_entry_app();
        }
        else
        {
            if (GetActiveScreenId() == SCR_ID_IMPS_PROGRESS)
            {
                mmi_imps_entry_chat();
                if (IsScreenPresent(SCR_ID_IMPS_CONT))
                {
                    mmi_imps_util_del_scr_after_progress(SCR_ID_IMPS_CONT);
                    DeleteScreenIfPresent(SCR_ID_IMPS_CONT);
                }
                else    /* CHAT screen */
                {
                    mmi_imps_util_del_scr_after_progress(SCR_ID_IMPS_CHAT);
                    DeleteScreenIfPresent(SCR_ID_IMPS_CHAT);
                }
            }
            else
            {
                if (IsScreenPresent(SCR_ID_IMPS_CONT))
                {
                    mmi_imps_util_del_scr_after_progress(SCR_ID_IMPS_CONT);
                    HistoryReplace(SCR_ID_IMPS_CONT, SCR_ID_IMPS_CHAT, mmi_imps_entry_chat);
                }
                else if (IsScreenPresent(SCR_ID_IMPS_CHAT)) /* chat screen present */
                {
                    mmi_imps_util_del_scr_after_progress(SCR_ID_IMPS_CHAT);
                }
                else
                {
                    /* other application, do nothing */
                }
            }
        }
    }
    else
    {
        mmi_imps_util_disp_err_popup(mmi_imps_util_get_err_str(rsp->result));
        if (imps_p->gen_info.is_reentry)
        {
            mmi_imps_re_entry_app();
        }
        else
        {
            /* check if it's join from invitation screen of a voluntarily join */
            if (IsScreenPresent(SCR_ID_IMPS_INVITATION_IND))
            {
                if (IsScreenPresent(SCR_ID_IMPS_CONT))
                {
                    mmi_imps_util_del_scr_after_progress(SCR_ID_IMPS_CONT);
                }
                else    /* (IsScreenPresent(SCR_ID_IMPS_CHAT)) */
                {
                    mmi_imps_util_del_scr_after_progress(SCR_ID_IMPS_CHAT);
                }
            }
            else if (IsScreenPresent(SCR_ID_IMPS_SEARCH_RESULT))        /* join from search result */
            {
                mmi_imps_util_del_scr_after_progress(SCR_ID_IMPS_SEARCH_RESULT);
            }
            else    /* direct join */
            {
                mmi_imps_util_del_scr_after_progress(SCR_ID_IMPS_CHAT_ROOM_OPT);
            }
        }
    }

    /* free memory */
    mmi_imps_join_free_mem();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_join_free_mem
 * DESCRIPTION
 *  Free inline editor memory for Join Chat Room screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_join_free_mem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* currently request for join */
    if (imps_p->room_info.inline_join && imps_p->gen_info.curr_action != MSG_ID_MMI_IMPS_JOIN_GROUP_REQ)
    {
        OslMfree(imps_p->room_info.inline_join);
        imps_p->room_info.inline_join = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_room_search_quit
 * DESCRIPTION
 *  Quit Chat Room search procedure
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_room_search_quit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackToHistory(SCR_ID_IMPS_CHAT_ROOM_OPT);
}

#endif