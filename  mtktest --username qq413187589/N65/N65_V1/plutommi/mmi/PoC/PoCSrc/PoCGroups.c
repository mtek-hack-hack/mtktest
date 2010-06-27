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
 *  PoCGroups.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements poc groups
 *
 * Author:
 * -------
 * -------
 *
==============================================================
 *              HISTORY
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
 *=============================================================
 *******************************************************************************/

#include "MMI_features.h"
#ifdef __MMI_POC__

#ifndef __MTK_TARGET__
#include <Windows.h>
#endif
#include "MMI_include.h"
#include "mdi_datatype.h"
#include "ProtocolEvents.h"
#include "CommonScreens.h"
#include "SettingProfile.h"
#include "ProfileGprots.h"
#include "CallSetup.h"
#include "custom_nvram_editor_data_item.h"
#include "custom_data_account.h"
#include "DataAccountGProt.h"
#include "sip_msg_api.h"
#include "sip_ua_api.h"
#include "app2soc_struct.h"
#include "soc_api.h"
#include "app2sip_struct.h"
#include "app2xdm_struct.h"
#include "mmi2poc_struct.h"
#include "custom_poc_config.h"
#include "PoCGprot.h"
#include "PoCProt.h"
#include "app2xdm_enums.h"
#include "wgui_tab_bars.h"


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_contact
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_contact(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_poc_entry_contact, KEY_EVENT_UP);
    SetKeyHandler(mmi_poc_entry_contact, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_contact_opt
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_contact_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_poc_entry_contact_opt, KEY_EVENT_UP);
    SetKeyHandler(mmi_poc_entry_contact_opt, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_contact_opt_settings
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_contact_opt_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_poc_entry_contact_opt_settings, KEY_EVENT_UP);
    SetKeyHandler(mmi_poc_entry_contact_opt_settings, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_contact_opt_settings_modify
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_contact_opt_settings_modify(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_poc_entry_contact_opt_settings_modify, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_contact_opt_settings_add
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_contact_opt_settings_add(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_poc_entry_contact_opt_settings_add, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_contact_opt_settings_delete
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_contact_opt_settings_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_poc_entry_contact_opt_settings_delete_cfrm, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_contact_opt_settings_info
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_contact_opt_settings_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_poc_entry_contact_opt_settings_info, KEY_EVENT_UP);
    SetKeyHandler(mmi_poc_entry_contact_opt_settings_info, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_contact_opt_settings_attributes_allow_invite
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_contact_opt_settings_attributes_allow_invite(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_poc_entry_contact_opt_settings_attributes_allow_invite, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_contact_opt_settings_attributes_allow_invite_accept
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_contact_opt_settings_attributes_allow_invite_accept(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_poc_contact_set_allow_invite_accept, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_contact_opt_settings_attributes_allow_invite_auto
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_contact_opt_settings_attributes_allow_invite_auto(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_poc_contact_set_allow_invite_auto, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_contact_opt_settings_attributes_allow_invite_reject
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_contact_opt_settings_attributes_allow_invite_reject(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_poc_contact_set_allow_invite_reject, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_contact_opt_settings_attributes_allow_subscribe
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_contact_opt_settings_attributes_allow_subscribe(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_poc_entry_allow_subscribe, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_contact_opt_settings_attributes_allow_subscribe_block
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_contact_opt_settings_attributes_allow_subscribe_block(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_poc_entry_allow_subscribe_block, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_contact_opt_settings_attributes_allow_subscribe_polite_block
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_contact_opt_settings_attributes_allow_subscribe_polite_block(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_poc_entry_allow_subscribe_polite_block, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_contact_opt_settings_attributes_allow_subscribe_allow
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_contact_opt_settings_attributes_allow_subscribe_allow(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_poc_entry_allow_subscribe_allow, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_contact_opt_settings_attributes_provide_pres
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_contact_opt_settings_attributes_provide_pres(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_poc_entry_contact_opt_settings_attributes_provide_pres, KEY_EVENT_UP);
    SetKeyHandler(mmi_poc_entry_contact_opt_settings_attributes_provide_pres, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_contact_opt_settings_attributes_subscribe_pres
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_contact_opt_settings_attributes_subscribe_pres(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_poc_contact_set_subscribe_pres, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_contact_opt_send_alert
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_contact_opt_send_alert(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_poc_entry_contact_opt_send_alert, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_contact_opt_adhoc_talk
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_contact_opt_adhoc_talk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_poc_entry_contact_opt_adhoc_talk, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_contact_opt_refresh_status
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_contact_opt_refresh_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_poc_contact_send_refresh_status, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_talk_groups
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_talk_groups(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_poc_entry_talk_groups, KEY_EVENT_UP);
    SetKeyHandler(mmi_poc_entry_talk_groups, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_talk_groups_opt
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_talk_groups_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_poc_entry_talk_groups_opt, KEY_EVENT_UP);
    SetKeyHandler(mmi_poc_entry_talk_groups_opt, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_talk_groups_opt_entry_settings
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_talk_groups_opt_entry_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_poc_entry_talk_groups_opt_entry_settings, KEY_EVENT_UP);
    SetKeyHandler(mmi_poc_entry_talk_groups_opt_entry_settings, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_talk_groups_opt_entry_settings_add
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_talk_groups_opt_entry_settings_add(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_poc_entry_talk_groups_opt_entry_settings_add, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_talk_groups_opt_entry_settings_add_from_contact
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_talk_groups_opt_entry_settings_add_from_contact(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_poc_entry_talk_groups_opt_entry_settings_add_from_contact, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_talk_groups_opt_entry_settings_delete
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_talk_groups_opt_entry_settings_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_poc_talk_groups_opt_entry_delete_cfrm, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_talk_groups_opt_entry_settings_entry_info
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_talk_groups_opt_entry_settings_entry_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_poc_entry_talk_groups_opt_entry_settings_entry_info, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_talk_groups_opt_entry_settings_entry_attributes_conf_state
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_talk_groups_opt_entry_settings_entry_attributes_conf_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_poc_talk_group_set_conf_state, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_talk_groups_opt_entry_settings_entry_attributes_invite_user_dyna
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_talk_groups_opt_entry_settings_entry_attributes_invite_user_dyna(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_poc_talk_group_set_invite_user_dyna, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_talk_groups_opt_entry_settings_entry_attributes_join_handling
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_talk_groups_opt_entry_settings_entry_attributes_join_handling(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_poc_talk_group_set_join_handling, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_talk_groups_opt_entry_settings_entry_attributes_init_conf
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_talk_groups_opt_entry_settings_entry_attributes_init_conf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_poc_talk_group_set_init_conf, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_talk_groups_opt_entry_settings_entry_attributes_anonymity
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_talk_groups_opt_entry_settings_entry_attributes_anonymity(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_poc_talk_group_set_anonymity, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_talk_groups_opt_add_group
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_talk_groups_opt_add_group(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_poc_entry_talk_groups_opt_add_group, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_talk_groups_opt_delete_group
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_talk_groups_opt_delete_group(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_poc_entry_talk_group_opt_delete_cfrm, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_talk_groups_opt_group_info
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_talk_groups_opt_group_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_poc_entry_talk_groups_opt_group_info, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_talk_groups_info_entry_attributes_conf_state
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_talk_groups_info_entry_attributes_conf_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_poc_talk_group_set_default_conf_state, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_talk_groups_info_entry_attributes_invite_user_dyna
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_talk_groups_info_entry_attributes_invite_user_dyna(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_poc_talk_group_set_default_invite_user_dyna, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_talk_groups_info_entry_attributes_join_handling
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_talk_groups_info_entry_attributes_join_handling(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_poc_talk_group_set_default_join_handling, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_talk_groups_info_entry_attributes_init_conf
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_talk_groups_info_entry_attributes_init_conf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_poc_talk_group_set_default_init_conf, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_talk_groups_info_entry_attributes_anonymity
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_talk_groups_info_entry_attributes_anonymity(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_poc_talk_group_set_default_anonymity, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_highlight_talk_groups_opt_call_others_group
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_highlight_talk_groups_opt_call_others_group(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_poc_entry_talk_groups_opt_call_others_group, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_hint_allow_invite
 * DESCRIPTION
 *  Hint handler of PoC menu
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_hint_allow_invite(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) hintData[(index)], 0, MAX_SUB_MENU_SIZE);

    switch (g_poc_cntx_p->contact_entry_disp.allow_invite)
    {
        case POC_SETTING_TRUE:
            mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_ID_POC_MANUAL_ANS));
            break;
        case POC_SETTING_FALSE:
            mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_ID_POC_REJECT));
            break;
        case POC_SETTING_ACCEPT:
            mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_ID_POC_AUTO_ACCEPT));
            break;
        default:
            mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_EMPTY));
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_hint_allow_subscribe
 * DESCRIPTION
 *  Hint handler of PoC menu
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_hint_allow_subscribe(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) hintData[(index)], 0, MAX_SUB_MENU_SIZE);

    switch (g_poc_cntx_p->contact_entry_disp.auth_rule.sub_handling)
    {
        case POC_MMI_SUB_BLOCK:
            mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_ID_POC_REJECT));
            break;
        case POC_MMI_SUB_POLITE_BLOCK:
            mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_ID_POC_POLITE_BLOCK));
            break;
        case POC_MMI_SUB_ALLOW:
            mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_ID_POC_ACCEPT));
            break;
        default:
            mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_EMPTY));
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_hint_subscribe_pres
 * DESCRIPTION
 *  Hint handler of PoC menu
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_hint_subscribe_pres(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) hintData[(index)], 0, MAX_SUB_MENU_SIZE);

    switch (g_poc_cntx_p->contact_entry_disp.sub_pres)
    {
        case POC_SETTING_TRUE:
            mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_ON));
            break;
        default:
            mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_OFF));
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_contact
 * DESCRIPTION
 *  poc contact screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_contact(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *nStrItemList[POC_MAX_CONTACT_DISPLAY_NUM];
    U8 *guiBuffer;
    BOOL list_is_ready_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_poc_cntx_p->progressing.contact == MMI_TRUE)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_POC_PROCESSING),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
        return;
    }

    mmi_poc_check_and_update_contact();

    EntryNewScreen(SCR_ID_POC_CONTACT, NULL, mmi_poc_entry_contact, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_POC_CONTACT);

    RegisterHighlightHandler(mmi_poc_contact_highlight_handler);

    if (g_poc_cntx_p->contact_num == 0)
    {
        mmi_ucs2cpy((S8*) g_poc_cntx_p->contact_entry_disp.display_name, (PS8) GetString(STR_GLOBAL_EMPTY_LIST));
        nStrItemList[0] = g_poc_cntx_p->contact_entry_disp.display_name;
        ShowCategory6Screen(
            STR_ID_POC_CONTACTS,
            GetRootTitleIcon(MENU_ID_POC_MAIN),
            STR_GLOBAL_ADD,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            1,
            nStrItemList,
            NULL,
            0,
            guiBuffer);
        SetLeftSoftkeyFunction(mmi_poc_entry_contact_opt_settings_add, KEY_EVENT_UP);
    }
    else
    {
        if (guiBuffer != NULL)
        {
            memset((void*)guiBuffer, 0, 2);
            if (g_poc_cntx_p->contact_selected >= g_poc_cntx_p->contact_num)
            {
                g_poc_cntx_p->contact_selected = g_poc_cntx_p->contact_num - 1;
            }
        }
        else
        {
            g_poc_cntx_p->contact_selected = 0;
        }

        ShowCategory425Screen(
            (UI_string_type) GetString(STR_ID_POC_CONTACTS),
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            0,
            0,
            0,
            g_poc_cntx_p->contact_num,
            mmi_poc_contact_get_items,
            mmi_poc_contact_get_hints,
            (PU8) GetImage(IMG_ID_POC_ONLINE),
            (PU8) GetImage(IMG_ID_POC_ONLINE),
            g_poc_cntx_p->contact_selected,
            guiBuffer,
            &list_is_ready_p);

        SetLeftSoftkeyFunction(mmi_poc_entry_contact_opt, KEY_EVENT_UP);
        SetKeyHandler(mmi_poc_entry_contact_opt, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }

    if (g_poc_cntx_p->contact_num > 0)
    {
        SetKeyHandler(mmi_poc_contact_1_to_1_invite, KEY_SEND, KEY_EVENT_DOWN);
    }

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_contact_get_items
 * DESCRIPTION
 *  Fill items of contact list into UI buffers
 * PARAMETERS
 *  start_index     [IN]        Start index of item to be retrieved
 *  menu_data       [IN]        Address of menu data
 *  data_size       [IN]        Maximal number of menu items can be put in the buffer
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_poc_contact_get_items(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;
    S32 count = (S32) g_poc_cntx_p->contact_num;
    mmi_poc_contact_list_disp *cont;
    gui_iconlist_menu_item *item = menu_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0, j = (i + start_index); i < data_size && j < count; i++, j++)
    {
        cont = &g_poc_cntx_p->contact_list_disp[j];

        if (g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].pres.is_active == MMI_TRUE)
        {
            item->image_list[0] = (PU8) GetImage(IMG_ID_POC_ONLINE);
        }
        else
        {
            item->image_list[0] = (PU8) GetImage(IMG_ID_POC_OFFLINE);
        }

        item->image_list[1] = NULL;

        if (g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].allow_invite == POC_SETTING_FALSE)
        {
            item->image_list[2] = (PU8) GetImage(IMG_ID_POC_BLOCK);
        }
        else
        {
            item->image_list[2] = NULL;
        }

        mmi_poc_util_copy_with_dot(
            (S8*) g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id]. display_name,
            (S8*) item->item_list[0],
            MAX_SUBMENU_CHARACTERS - 1);

        mmi_poc_util_copy_with_dot(
            (S8*) g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].uri,
            (S8*) item->item_list[1],
            MAX_SUBMENU_CHARACTERS - 1);

        item++;
    }

    return i;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_contact_get_hints
 * DESCRIPTION
 *  Fill items of hint list into UI buffers. Currently, it's no use.
 * PARAMETERS
 *  start_index     [IN]        Start index of item to be retrieved
 *  hint_array      [IN]        Buffer to strore list of hints
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_poc_contact_get_hints(S32 start_index, UI_string_type *hint_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_util_copy_with_dot
 * DESCRIPTION
 *  Append three dots to the end of string
 * PARAMETERS
 *  source      [IN]            Source buffer.
 *  dest        [IN/OUT]        Destination buffer.
 *  max_len     [IN]            Max characters can be put in destination buffer , including NULL terminate
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_util_copy_with_dot(S8 *source, S8 *dest, S32 max_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *tmp_buff = OslMalloc((POC_MAX_URI_LEN + 1) * ENCODING_LENGTH);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_n_to_ucs2((S8*) tmp_buff, (S8*) source, POC_MAX_URI_LEN);

    if (mmi_ucs2strlen(tmp_buff) <= max_len)
    {
        mmi_ucs2cpy((S8*) dest, (S8*) tmp_buff);
    }
    else
    {
        /* do not clear end of string because mmi_ucs2ncpy will auto set NULL terminate */
        mmi_ucs2ncpy((S8*) dest, (S8*) tmp_buff, max_len - 4);
        mmi_ucs2cat((S8*) dest, (S8*) g_poc_three_dot);
    }

    OslMfree(tmp_buff);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_sort_contact_by_name
 * DESCRIPTION
 *  sort contact by display name
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_sort_contact_by_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, j;
    mmi_poc_contact_list_disp *cont1;
    mmi_poc_contact_list_disp *cont2;
    mmi_poc_contact_list_disp temp_contact;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_poc_cntx_p->contact_num; i++)
    {
        cont1 = &g_poc_cntx_p->contact_list_disp[i];
        for (j = i + 1; j < g_poc_cntx_p->contact_num; j++)
        {
            cont2 = &g_poc_cntx_p->contact_list_disp[j];
            if (strcmp(
                    (S8*) g_poc_cntx_p->contact_list[cont1->group_id].entries[cont1->entry_id].display_name,
                    (S8*) g_poc_cntx_p->contact_list[cont2->group_id].entries[cont2->entry_id].display_name) > 0)
            {
                memcpy(&temp_contact, &g_poc_cntx_p->contact_list_disp[i], sizeof(mmi_poc_contact_list_disp));
                memcpy(
                    &g_poc_cntx_p->contact_list_disp[i],
                    &g_poc_cntx_p->contact_list_disp[j],
                    sizeof(mmi_poc_contact_list_disp));
                memcpy(&g_poc_cntx_p->contact_list_disp[j], &temp_contact, sizeof(mmi_poc_contact_list_disp));
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_check_and_update_contact
 * DESCRIPTION
 *  check and update contact, including sort
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_check_and_update_contact(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_poc_cntx_p->contact_local_updated == MMI_FALSE)
    {
        g_poc_cntx_p->contact_num = 0;
        memset(g_poc_cntx_p->contact_list_disp, 0, sizeof(mmi_poc_contact_list_disp) * POC_MAX_CONTACT_DISPLAY_NUM);
        for (i = 0; i < MAX_POC_GROUP_FILE_NUM * MAX_POC_GROUPS_PER_FILE_NUM; i++)
        {
            if (g_poc_cntx_p->contact_list[i].valid == MMI_TRUE)
            {
                for (j = 0; j < g_poc_cntx_p->contact_list[i].no_entries; j++)
                {
                    g_poc_cntx_p->contact_list_disp[g_poc_cntx_p->contact_num].group_id = i;
                    g_poc_cntx_p->contact_list_disp[g_poc_cntx_p->contact_num].entry_id = j;
                    g_poc_cntx_p->contact_num++;
                }
            }
        }
        mmi_poc_sort_contact_by_name();
        g_poc_cntx_p->contact_local_updated = MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_contact_highlight_handler
 * DESCRIPTION
 *  poc contact highlight handler
 * PARAMETERS
 *  index       [IN]        Current selected index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_contact_highlight_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_poc_cntx_p->contact_selected = (U8) index;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_contact_opt
 * DESCRIPTION
 *  contact option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_contact_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];    /* Stores the strings id of submenus returned */
    U16 nNumofItem;                     /* Stores no of children in the submenu */
    U8 *guiBuffer;                      /* Buffer holding history data */
    U16 menuId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_POC_CONTACT_OPT, NULL, mmi_poc_entry_contact_opt, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_POC_CONTACT_OPT);
    menuId = MENU_ID_POC_CONTACT_OPT;

    nNumofItem = GetNumOfChild(menuId);
    GetSequenceStringIds(menuId, nStrItemList);
    SetParentHandler(menuId);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_ID_POC_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        1,
        0,
        guiBuffer);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_contact_opt_settings
 * DESCRIPTION
 *  contact option setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_contact_opt_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];    /* Stores the strings id of submenus returned */
    U16 nNumofItem;                     /* Stores no of children in the submenu */
    U8 *guiBuffer;                      /* Buffer holding history data */
    U16 menuId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_POC_CONTACT_ENTRY_SETTINGS, NULL, mmi_poc_entry_contact_opt_settings, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_POC_CONTACT_ENTRY_SETTINGS);
    menuId = MENU_ID_POC_CONTACT_OPT_SETTINGS;

    nNumofItem = GetNumOfChild(menuId);
    GetSequenceStringIds(menuId, nStrItemList);
    SetParentHandler(menuId);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ShowCategory15Screen(
        STR_ID_POC_ENTRY_SETTINGS,
        GetRootTitleIcon(MENU_ID_POC_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        1,
        0,
        guiBuffer);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_contact_opt_settings_modify
 * DESCRIPTION
 *  contact option settings modify screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_contact_opt_settings_modify(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, ImageLocation = 0;
    U8 *inputBuffer;
    U8 *guiBuffer;
    U16 inputBufferSize;
    U16 IconList[POC_CONTACT_INLINE_NUM];
    mmi_poc_contact_list_disp *cont;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_POC_CONTACT_ENTRY_MODIFY, mmi_poc_exit_contact_opt_settings_modify, NULL, NULL);

    InitializeCategory57Screen();
    guiBuffer = GetCurrGuiBuffer(SCR_ID_POC_CONTACT_ENTRY_MODIFY);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_POC_CONTACT_ENTRY_MODIFY, &inputBufferSize);
    SetParentHandler(MENU_ID_POC_CONTACT_OPT_SETTINGS_MODIFY);

    mmi_poc_contact_fill_inline_struct(XDM_PUT_REPLACE);

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, POC_CONTACT_INLINE_NUM, inputBuffer);
    }
    else
    {
        cont = &g_poc_cntx_p->contact_list_disp[g_poc_cntx_p->contact_selected];

        g_poc_cntx_p->contact_entry_disp.allow_invite =
            g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].allow_invite;
        g_poc_cntx_p->contact_entry_disp.sub_pres =
            g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].sub_pres;
        memcpy(
            &g_poc_cntx_p->contact_entry_disp.auth_rule,
            &g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].auth_rule,
            sizeof(poc_pres_authrule_struct));
        if (strlen((S8*) g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].uri))
        {
            mmi_asc_n_to_ucs2(
                (S8*) g_poc_cntx_p->contact_entry_disp.uri,
                (S8*) g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].uri,
                POC_MAX_URI_LEN - 1);
        }
        else
        {
            mmi_asc_n_to_ucs2(
                (S8*) g_poc_cntx_p->contact_entry_disp.uri,
                (S8*) POC_MMI_SIP_PREFIX,
                POC_MAX_URI_LEN - 1);
        }
        mmi_asc_n_to_ucs2(
            (S8*) g_poc_cntx_p->contact_entry_disp.display_name,
            (S8*) g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].display_name,
            POC_MAX_DISP_LEN - 1);
        memcpy(
            &g_poc_cntx_p->contact_entry_disp.pres,
            &g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].pres,
            sizeof(mmi_poc_presence_struct));
    }

    if (guiBuffer == 0)
    {
        g_poc_cntx_p->inline_item_changed = MMI_FALSE;
    }

    if ((get_wgui_inline_list_menu_status() || g_poc_cntx_p->inline_item_changed) &&
        (GetInlineDoneFlag(guiBuffer) == 0))
    {
        SetInlineDoneFlag(guiBuffer);
    }

    for (i = 0; i < POC_CONTACT_INLINE_NUM; i++)
    {
        if (i % 2)
        {
            IconList[i] = IMG_ID_POC_NOIMAGE;
        }
        else
        {
            IconList[i] = IMG_ID_POC_CONTACT_NAME + ImageLocation;
            ImageLocation++;
        }
    }

    ShowCategory57Screen(
        STR_ID_POC_ENTRY_INFO,
        GetRootTitleIcon(MENU_ID_POC_MAIN),
        STR_GLOBAL_EDIT,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        POC_CONTACT_INLINE_NUM,
        IconList,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_poc_entry_contact_opt_settings_modify_cfrm, GoBackHistory);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_exit_contact_opt_settings_modify
 * DESCRIPTION
 *  modify exit screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_exit_contact_opt_settings_modify(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_leading_zero(TRUE);
    GenericExitInlineScreen(SCR_ID_POC_CONTACT_ENTRY_MODIFY, mmi_poc_entry_contact_opt_settings_modify);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_contact_fill_inline_struct
 * DESCRIPTION
 *  fill inline editor structure
 * PARAMETERS
 *  op      [IN]        XDM_PUT_ADD or XDM_PUT_REPLACE
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_contact_fill_inline_struct(U8 op)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 BufferSize = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetInlineItemActivation((wgui_inline_items + POC_CONTACT_NAME), KEY_LSK, KEY_EVENT_UP);
    SetInlineItemActivation((wgui_inline_items + POC_CONTACT_URI), KEY_LSK, KEY_EVENT_UP);
    SetInlineItemActivation((wgui_inline_items + POC_CONTACT_ATTR), KEY_LSK, KEY_EVENT_UP);

    SetInlineItemCaption((wgui_inline_items + POC_CONTACT_NAME_STR), (U8*) GetString(STR_ID_POC_NAME));
    SetInlineItemCaption((wgui_inline_items + POC_CONTACT_URI_STR), (U8*) GetString(STR_ID_POC_URI));
    SetInlineItemCaption((wgui_inline_items + POC_CONTACT_ATTR_STR), (U8*) GetString(STR_ID_POC_ATTRIBUTES));

    BufferSize = POC_MAX_DISP_LEN - 1;

    SetInlineItemFullScreenEdit_ext(
        (wgui_inline_items + POC_CONTACT_NAME),
        STR_ID_POC_NAME,
        GetRootTitleIcon(MENU_ID_POC_MAIN),
        (U8*) (g_poc_cntx_p->contact_entry_disp.display_name),
        BufferSize,
        (INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES),
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);

    SetInlineFullScreenEditCustomFunction(wgui_inline_items + POC_CONTACT_NAME, mmi_poc_entry_full_line_edit);

    if (op == XDM_PUT_ADD)
    {
        BufferSize = POC_MAX_URI_LEN - 1;

        SetInlineItemFullScreenEdit_ext(
            (wgui_inline_items + POC_CONTACT_URI),
            STR_ID_POC_URI,
            GetRootTitleIcon(MENU_ID_POC_MAIN),
            (U8*) (g_poc_cntx_p->contact_entry_disp.uri),
            BufferSize,
            (INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES),
            INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);

        SetInlineFullScreenEditCustomFunction(wgui_inline_items + POC_CONTACT_URI, mmi_poc_entry_full_line_edit);
    }
    else
    {
        SetInlineItemDisplayOnly(
            (wgui_inline_items + POC_TALK_GROUP_URI),
            (U8*) (g_poc_cntx_p->contact_entry_disp.uri));
    }

    SetInlineItemImageText(
        (wgui_inline_items + POC_CONTACT_ATTR),
        (U8*) GetString(STR_ID_POC_SET_ATTR),
        (PU8) NULL,
        NULL,
        NULL,
        POC_MAX_DISP_LEN,
        0,
        0,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE);
    SetInlineFullScreenEditCustomFunctionImageText(
        (wgui_inline_items + POC_CONTACT_ATTR),
        mmi_poc_entry_contact_opt_settings_attributes);
    ShowAsControl(wgui_inline_items + POC_CONTACT_ATTR);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_contact_opt_settings_add
 * DESCRIPTION
 *  settings add screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_contact_opt_settings_add(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, ImageLocation = 0;
    U8 *inputBuffer;
    U8 *guiBuffer;
    U16 inputBufferSize;
    U16 IconList[POC_CONTACT_INLINE_NUM];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_poc_cntx_p->contact_num >= POC_GROUP_LOCAL_MAX_ENTRIES_NUM)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_POC_ERR_MAXIMUM_REACHED),
            IMG_GLOBAL_UNFINISHED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
        return;
    }

    EntryNewScreen(SCR_ID_POC_CONTACT_ENTRY_ADD, mmi_poc_exit_contact_opt_settings_add, NULL, NULL);

    InitializeCategory57Screen();
    guiBuffer = GetCurrGuiBuffer(SCR_ID_POC_CONTACT_ENTRY_ADD);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_POC_CONTACT_ENTRY_ADD, &inputBufferSize);
    SetParentHandler(MENU_ID_POC_CONTACT_OPT_SETTINGS_ADD);

    mmi_poc_contact_fill_inline_struct(XDM_PUT_ADD);

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, POC_CONTACT_INLINE_NUM, inputBuffer);
    }
    else
    {
        memset(&g_poc_cntx_p->contact_entry_disp, 0, sizeof(mmi_poc_contact_entry_disp_struct));

    #ifdef __MMI_POC_ETS_TESTCODE__
        mmi_asc_n_to_ucs2(
            (S8*) g_poc_cntx_p->contact_entry_disp.uri,
            (S8*) "sip:PocUser1E@ims3.vfd2-testnetz.de",
            POC_MAX_URI_LEN - 1);
    #else /* __MMI_POC_ETS_TESTCODE__ */ 
        mmi_asc_n_to_ucs2(
            (S8*) g_poc_cntx_p->contact_entry_disp.uri,
            (S8*) POC_MMI_SIP_PREFIX,
            POC_MAX_URI_LEN - 1);
    #endif /* __MMI_POC_ETS_TESTCODE__ */ 
        g_poc_cntx_p->contact_entry_disp.allow_invite = POC_SETTING_TRUE;
        g_poc_cntx_p->contact_entry_disp.sub_pres = POC_SETTING_TRUE;
        g_poc_cntx_p->contact_entry_disp.auth_rule.sub_handling = POC_MMI_SUB_ALLOW;
        g_poc_cntx_p->contact_entry_disp.auth_rule.pres_attr = POC_PRES_PROVIDE_ALL;
    }

    if (guiBuffer == 0)
    {
        g_poc_cntx_p->inline_item_changed = MMI_FALSE;
    }

    if ((get_wgui_inline_list_menu_status() || g_poc_cntx_p->inline_item_changed) &&
        (GetInlineDoneFlag(guiBuffer) == 0))
    {
        SetInlineDoneFlag(guiBuffer);
    }

    for (i = 0; i < POC_CONTACT_INLINE_NUM; i++)
    {
        if (i % 2)
        {
            IconList[i] = IMG_ID_POC_NOIMAGE;
        }
        else
        {
            IconList[i] = IMG_ID_POC_CONTACT_NAME + ImageLocation;
            ImageLocation++;
        }
    }

    ShowCategory57Screen(
        STR_ID_POC_ENTRY_INFO,
        GetRootTitleIcon(MENU_ID_POC_MAIN),
        STR_GLOBAL_EDIT,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        POC_CONTACT_INLINE_NUM,
        IconList,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_poc_entry_contact_opt_settings_add_cfrm, GoBackHistory);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_exit_contact_opt_settings_add
 * DESCRIPTION
 *  settings add screen exit function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_exit_contact_opt_settings_add(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_leading_zero(TRUE);
    GenericExitInlineScreen(SCR_ID_POC_CONTACT_ENTRY_ADD, mmi_poc_entry_contact_opt_settings_add);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_contact_opt_settings_attributes
 * DESCRIPTION
 *  settings attribute screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_contact_opt_settings_attributes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];    /* Stores the strings id of submenus returned */
    U16 nNumofItem;                     /* Stores no of children in the submenu */
    U8 *guiBuffer;                      /* Buffer holding history data */
    U16 menuId;
    U8 *PoCHint[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_POC_CONTACT_ENTRY_ATTR, NULL, mmi_poc_entry_contact_opt_settings_attributes, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_POC_CONTACT_ENTRY_ATTR);
    menuId = MENU_ID_POC_CONTACT_OPT_SETTINGS_ATTRIBUTES;

    nNumofItem = GetNumOfChild(menuId);
    GetSequenceStringIds(menuId, nStrItemList);
    SetParentHandler(menuId);
    ConstructHintsList(menuId, PoCHint);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_ID_POC_ATTRIBUTES,
        GetRootTitleIcon(MENU_ID_POC_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        PoCHint,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_go_back_contact_list
 * DESCRIPTION
 *  go back contact list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_go_back_contact_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stopRequestedTone(WARNING_TONE);
    DeleteUptoScrID(SCR_ID_POC_CONTACT);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_contact_opt_settings_attributes_allow_invite
 * DESCRIPTION
 *  allow invite screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_contact_opt_settings_attributes_allow_invite(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];    /* Stores the strings id of submenus returned */
    U16 nNumofItem;                     /* Stores no of children in the submenu */
    U8 *guiBuffer;                      /* Buffer holding history data */
    U16 menuId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(
        SCR_ID_POC_CONTACT_ENTRY_ALLOW_INVITE,
        NULL,
        mmi_poc_entry_contact_opt_settings_attributes_allow_invite,
        NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_POC_CONTACT_ENTRY_ALLOW_INVITE);
    menuId = MENU_ID_POC_CONTACT_OPT_SETTINGS_ATTRIBUTES_ALLOW_INVITE;

    nNumofItem = GetNumOfChild(menuId);
    GetSequenceStringIds(menuId, nStrItemList);
    SetParentHandler(menuId);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ShowCategory15Screen(
        STR_ID_POC_ALLOW_INVITE,
        GetRootTitleIcon(MENU_ID_POC_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        1,
        0,
        guiBuffer);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_contact_set_allow_invite_accept
 * DESCRIPTION
 *  set allow invite option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_contact_set_allow_invite_accept(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_poc_cntx_p->contact_entry_disp.allow_invite = POC_SETTING_TRUE;
    g_poc_cntx_p->inline_item_changed = MMI_TRUE;
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_contact_set_allow_invite_auto
 * DESCRIPTION
 *  set allow invite option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_contact_set_allow_invite_auto(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_poc_cntx_p->contact_entry_disp.allow_invite = POC_SETTING_ACCEPT;
    g_poc_cntx_p->inline_item_changed = MMI_TRUE;
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_contact_set_allow_invite_reject
 * DESCRIPTION
 *  set allow invite option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_contact_set_allow_invite_reject(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_poc_cntx_p->contact_entry_disp.allow_invite = POC_SETTING_FALSE;
    g_poc_cntx_p->inline_item_changed = MMI_TRUE;
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_allow_subscribe
 * DESCRIPTION
 *  allow subscribe screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_allow_subscribe(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];    /* Stores the strings id of submenus returned */
    U16 nNumofItem;                     /* Stores no of children in the submenu */
    U8 *guiBuffer;                      /* Buffer holding history data */
    U16 menuId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_POC_CONTACT_ENTRY_ALLOW_SUBSCRIBE, NULL, mmi_poc_entry_allow_subscribe, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_POC_CONTACT_ENTRY_ALLOW_SUBSCRIBE);
    menuId = MENU_ID_POC_CONTACT_OPT_SETTINGS_ATTRIBUTES_ALLOW_SUBSCRIBE;

    nNumofItem = GetNumOfChild(menuId);
    GetSequenceStringIds(menuId, nStrItemList);
    SetParentHandler(menuId);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ShowCategory15Screen(
        STR_ID_POC_ALLOW_SUBSCRIBE,
        GetRootTitleIcon(MENU_ID_POC_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        1,
        0,
        guiBuffer);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_allow_subscribe_block
 * DESCRIPTION
 *  allow subscribe block
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_allow_subscribe_block(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_poc_cntx_p->contact_entry_disp.auth_rule.sub_handling = POC_MMI_SUB_BLOCK;
    g_poc_cntx_p->inline_item_changed = MMI_TRUE;
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_allow_subscribe_polite_block
 * DESCRIPTION
 *  allow subscribe polite block
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_allow_subscribe_polite_block(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_poc_cntx_p->contact_entry_disp.auth_rule.sub_handling = POC_MMI_SUB_POLITE_BLOCK;
    g_poc_cntx_p->inline_item_changed = MMI_TRUE;
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_allow_subscribe_allow
 * DESCRIPTION
 *  allow subscribe, allow
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_allow_subscribe_allow(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_poc_cntx_p->contact_entry_disp.auth_rule.sub_handling = POC_MMI_SUB_ALLOW;
    g_poc_cntx_p->inline_item_changed = MMI_TRUE;
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_contact_set_subscribe_pres
 * DESCRIPTION
 *  set subscribe presence
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_contact_set_subscribe_pres(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_poc_cntx_p->contact_entry_disp.sub_pres)
    {
        case POC_SETTING_TRUE:
            g_poc_cntx_p->contact_entry_disp.sub_pres = POC_SETTING_FALSE;
            break;
        default:
            g_poc_cntx_p->contact_entry_disp.sub_pres = POC_SETTING_TRUE;
            break;
    }

    DisplayPopup(
        (U8*) GetString(STR_GLOBAL_DONE),
        IMG_GLOBAL_ACTIVATED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) SUCCESS_TONE);
    g_poc_cntx_p->inline_item_changed = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_contact_opt_settings_attributes_provide_pres
 * DESCRIPTION
 *  provide presence screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_contact_opt_settings_attributes_provide_pres(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];
    U16 nNumofItem;
    U8 i = 0;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(
        SCR_ID_POC_CONTACT_ENTRY_PRES_ATTR,
        NULL,
        mmi_poc_entry_contact_opt_settings_attributes_provide_pres,
        NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_POC_CONTACT_ENTRY_PRES_ATTR);
    nNumofItem = GetNumOfChild(MENU_ID_POC_CONTACT_OPT_SETTINGS_ATTRIBUTES_PROVIDE_PRES);

    GetSequenceStringIds(MENU_ID_POC_CONTACT_OPT_SETTINGS_ATTRIBUTES_PROVIDE_PRES, nStrItemList);

    for (i = 0; i < nNumofItem; i++)
    {
        subMenuDataPtrs[i] = subMenuData[i];
        memset((S8*) subMenuDataPtrs[i], 0, MAX_SUB_MENU_SIZE);
        mmi_ucs2ncpy((S8*) subMenuDataPtrs[i], GetString(nStrItemList[i]), MAX_SUBMENU_CHARACTERS - 1);

    }

    SetParentHandler(MENU_ID_POC_CONTACT_OPT_SETTINGS_ATTRIBUTES_PROVIDE_PRES);

    if (guiBuffer == NULL)
    {
        memset(g_poc_cntx_p->pres_attr_disp, 0, sizeof(U8) * POC_PRES_TOTAL_NUM);
        if (g_poc_cntx_p->contact_entry_disp.auth_rule.pres_attr & POC_PRES_PROVIDE_ACTIVITY)
        {
            g_poc_cntx_p->pres_attr_disp[POC_PRES_ACTIVITY] = MMI_TRUE;
        }
        if (g_poc_cntx_p->contact_entry_disp.auth_rule.pres_attr & POC_PRES_PROVIDE_MOOD)
        {
            g_poc_cntx_p->pres_attr_disp[POC_PRES_MOOD] = MMI_TRUE;
        }
        if (g_poc_cntx_p->contact_entry_disp.auth_rule.pres_attr == POC_PRES_PROVIDE_ALL)
        {
            g_poc_cntx_p->pres_attr_disp[POC_PRES_ALL] = MMI_TRUE;
        }
    }

    SetCheckboxToggleRightSoftkeyFunctions(mmi_poc_contact_set_pres_attr_cfrm, GoBackHistory);

    ShowCategory140Screen(
        STR_ID_POC_PRESENCE_ATTR,
        GetRootTitleIcon(MENU_ID_POC_MAIN),
        nNumofItem,
        (U8 **) subMenuDataPtrs,
        g_poc_cntx_p->pres_attr_disp,
        0,
        guiBuffer);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_contact_set_pres_attr_cfrm
 * DESCRIPTION
 *  set presence attribute confirm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_contact_set_pres_attr_cfrm(void)
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

    SetLeftSoftkeyFunction(mmi_poc_contact_set_pres_attr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(poc_go_back_entry_attr, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_contact_set_pres_attr
 * DESCRIPTION
 *  set presence attribute
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_contact_set_pres_attr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_poc_cntx_p->contact_entry_disp.auth_rule.pres_attr = 0;
    if (g_poc_cntx_p->pres_attr_disp[POC_PRES_ACTIVITY] == MMI_TRUE)
    {
        g_poc_cntx_p->contact_entry_disp.auth_rule.pres_attr |= POC_PRES_PROVIDE_ACTIVITY;
    }
    if (g_poc_cntx_p->pres_attr_disp[POC_PRES_MOOD] == MMI_TRUE)
    {
        g_poc_cntx_p->contact_entry_disp.auth_rule.pres_attr |= POC_PRES_PROVIDE_MOOD;
    }
    if (g_poc_cntx_p->pres_attr_disp[POC_PRES_ALL] == MMI_TRUE)
    {
        g_poc_cntx_p->contact_entry_disp.auth_rule.pres_attr |= POC_PRES_PROVIDE_ALL;
    }
    g_poc_cntx_p->inline_item_changed = MMI_TRUE;
    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, UI_POPUP_NOTIFYDURATION_TIME, SUCCESS_TONE);
    DeleteScreenIfPresent(SCR_ID_POC_CONTACT_ENTRY_PRES_ATTR);
}


/*****************************************************************************
 * FUNCTION
 *  poc_go_back_entry_attr
 * DESCRIPTION
 *  go back to entry screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void poc_go_back_entry_attr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stopRequestedTone(WARNING_TONE);
    DeleteScreenIfPresent(SCR_ID_POC_CONTACT_ENTRY_PRES_ATTR);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_contact_opt_settings_modify_cfrm
 * DESCRIPTION
 *  settings modify confirm screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_contact_opt_settings_modify_cfrm(void)
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

    SetLeftSoftkeyFunction(mmi_poc_contact_send_modify, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_poc_go_back_contact_list, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_contact_send_modify
 * DESCRIPTION
 *  send settings modify
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_contact_send_modify(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_poc_cntx_p->curr_contact_op = XDM_PUT_REPLACE;
    mmi_poc_update_group_entry_req(XDM_PUT_REPLACE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_contact_opt_settings_add_cfrm
 * DESCRIPTION
 *  add confirm screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_contact_opt_settings_add_cfrm(void)
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

    SetLeftSoftkeyFunction(mmi_poc_contact_send_add, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_poc_go_back_contact_list, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_contact_send_add
 * DESCRIPTION
 *  send contact add
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_contact_send_add(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_POC_ALWAYS_CREATE_MTK_CONTACT__
    U8 i, j;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_poc_cntx_p->contact_num > 0) ||
        ((g_poc_cntx_p->contact_list[0].valid == MMI_TRUE) &&
         (g_poc_cntx_p->contact_list[0].list_name[0] != 0)))
    {
    #ifdef __MMI_POC_ALWAYS_CREATE_MTK_CONTACT__
        for (i = 0; i < MAX_POC_GROUP_FILE_NUM * MAX_POC_GROUPS_PER_FILE_NUM; i++)
        {
            if (!strncmp
                ((S8*) g_poc_cntx_p->contact_list[i].list_name, (S8*) POC_MTK_DEFAULT_CONTACT,
                 sizeof(POC_MTK_DEFAULT_CONTACT)))
            {
                break;
            }
        }
        if (i == MAX_POC_GROUP_FILE_NUM * MAX_POC_GROUPS_PER_FILE_NUM)
        {
            /* mtk contact not found */
            mmi_poc_create_group_list_req();
        }
        else
        {
            g_poc_cntx_p->curr_contact_op = XDM_PUT_ADD;
            mmi_poc_update_group_entry_req(XDM_PUT_ADD);
        }
    #else /* __MMI_POC_ALWAYS_CREATE_MTK_CONTACT__ */ 
        g_poc_cntx_p->curr_contact_op = XDM_PUT_ADD;
        mmi_poc_update_group_entry_req(XDM_PUT_ADD);
    #endif /* __MMI_POC_ALWAYS_CREATE_MTK_CONTACT__ */ 
    }
    else
    {
        memset(g_poc_cntx_p->contact_list, 0, sizeof(g_poc_cntx_p->contact_list));
        mmi_poc_create_group_list_req();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_progressing
 * DESCRIPTION
 *  entry progressing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_progressing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_POC_GENERAL_PROGRESSING, NULL, mmi_poc_entry_progressing, NULL);
    DeleteScreenIfPresent(SCR_ID_POC_GENERAL_PROGRESSING);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_POC_GENERAL_PROGRESSING);

    ShowCategory141Screen(
        STR_ID_POC_MAIN,
        GetRootTitleIcon(MENU_ID_POC_MAIN),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (U8*) GetString(STR_ID_POC_PROCESSING),
        IMG_GLOBAL_PROGRESS,
        NULL);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_update_group_entry_req
 * DESCRIPTION
 *  update group entry request
 * PARAMETERS
 *  op      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_update_group_entry_req(U8 op)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_poc_contact_list_disp *cont;
    poc_update_group_entry_req_struct *myMsgPtr;
    U8 i, new_idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_poc_cntx_p->curr_use_xdm_mode == MMI_TRUE)
    {

        myMsgPtr = (poc_update_group_entry_req_struct*) OslConstructDataPtr(sizeof(poc_update_group_entry_req_struct));
        memset(
            (U8*) myMsgPtr + sizeof(mmi_poc_dummy_req_struct),
            0,
            sizeof(poc_update_group_entry_req_struct) - sizeof(mmi_poc_dummy_req_struct));

        myMsgPtr->request_id = POC_REQUEST_ID;
        myMsgPtr->op = op;

        cont = &g_poc_cntx_p->contact_list_disp[g_poc_cntx_p->contact_selected];

        myMsgPtr->entry.allow_invite = g_poc_cntx_p->contact_entry_disp.allow_invite;
        myMsgPtr->entry.sub_pres = g_poc_cntx_p->contact_entry_disp.sub_pres;
        memcpy(
            &myMsgPtr->entry.auth_rule,
            &g_poc_cntx_p->contact_entry_disp.auth_rule,
            sizeof(poc_pres_authrule_struct));
        mmi_ucs2_n_to_asc((S8*) myMsgPtr->entry.uri, (S8*) g_poc_cntx_p->contact_entry_disp.uri, POC_MAX_URI_LEN - 1);
        mmi_ucs2_n_to_asc(
            (S8*) myMsgPtr->entry.disp_name,
            (S8*) g_poc_cntx_p->contact_entry_disp.display_name,
            POC_MAX_DISP_LEN - 1);

        if (myMsgPtr->entry.uri[0] == 0 || !strstr((S8*) myMsgPtr->entry.uri, (S8*) "@"))
        {
            DisplayPopup(
                (PU8) GetString(STR_ID_POC_NULL_STR_ERR),
                IMG_GLOBAL_UNFINISHED,
                1,
                CS_NOTIFYDURATION,
                ERROR_TONE);
            OslFreeDataPtr((void*)myMsgPtr);
            return;
        }

        myMsgPtr->entry.xdm_item = 0;
        g_poc_cntx_p->session_xdm = 0;

        if (op == XDM_PUT_ADD)
        {
        #ifdef __MMI_POC_ALWAYS_CREATE_MTK_CONTACT__
            myMsgPtr->entry.xdm_item = 0x0F;
            strncpy(
                (char*)myMsgPtr->list_name,
                (char*)g_poc_cntx_p->contact_list[cont->group_id].list_name,
                POC_MAX_DISP_LEN - 1);
        #else /* __MMI_POC_ALWAYS_CREATE_MTK_CONTACT__ */ 
            U8 least_num = POC_GROUP_LOCAL_MAX_ENTRIES_NUM;

            myMsgPtr->entry.xdm_item = 0x0F;
            g_poc_cntx_p->update_grp_idx = 0;
            for (i = 0; i < MAX_POC_GROUP_FILE_NUM * MAX_POC_GROUPS_PER_FILE_NUM; i++)
            {
                if ((g_poc_cntx_p->contact_list[i].valid == MMI_TRUE) &&
                    (g_poc_cntx_p->contact_list[i].no_entries < least_num))
                {
                    least_num = g_poc_cntx_p->contact_list[i].no_entries;
                    g_poc_cntx_p->update_grp_idx = i;
                }
            }
            strncpy(
                (char*)myMsgPtr->list_name,
                (char*)g_poc_cntx_p->contact_list[g_poc_cntx_p->update_grp_idx].list_name,
                POC_MAX_DISP_LEN - 1);
        #endif /* __MMI_POC_ALWAYS_CREATE_MTK_CONTACT__ */ 

        }
        else
        {
            strncpy(
                (char*)myMsgPtr->list_name,
                (char*)g_poc_cntx_p->contact_list[cont->group_id].list_name,
                POC_MAX_DISP_LEN - 1);

            if (strncmp
                ((S8*) myMsgPtr->entry.uri,
                 (S8*) g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].uri, POC_MAX_URI_LEN - 1) ||
                strncmp(
                    (S8*) myMsgPtr->entry.disp_name,
                    (S8*) g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].display_name,
                    POC_MAX_DISP_LEN - 1))
            {
                myMsgPtr->entry.xdm_item |= POC_XDM_GL_PRESENT;
            }
            if (myMsgPtr->entry.allow_invite !=
                g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].allow_invite)
            {
                myMsgPtr->entry.xdm_item |= POC_XDM_AL_PRESENT;
            }
            if (myMsgPtr->entry.auth_rule.pres_attr !=
                g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].auth_rule.pres_attr ||
                myMsgPtr->entry.auth_rule.sub_handling !=
                g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].auth_rule.sub_handling)
            {
                if (g_poc_cntx_p->contact_entry_disp.auth_rule.sub_handling != POC_MMI_SUB_EMPTY)
                {
                    myMsgPtr->entry.auth_rule.sub_handling =
                        g_poc_cntx_p->contact_entry_disp.auth_rule.sub_handling - 1;
                }
                myMsgPtr->entry.xdm_item |= POC_XDM_AR_PRESENT;
            }
            if (myMsgPtr->entry.sub_pres != g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].sub_pres)
            {
                myMsgPtr->entry.xdm_item |= POC_XDM_RLS_PRESENT;
            }
        }

        g_poc_cntx_p->session_xdm = myMsgPtr->entry.xdm_item;

        SetProtocolEventHandler(mmi_poc_update_group_entry_rsp, MSG_ID_POC_UPDATE_GROUP_ENTRY_RSP);

        g_poc_cntx_p->progressing.contact = MMI_TRUE;
        mmi_poc_entry_progressing();
        DeleteUptoScrID(SCR_ID_POC_CONTACT);
        DeleteScreenIfPresent(SCR_ID_POC_CONTACT);

        Message.oslSrcId = MOD_MMI;
        Message.oslDestId = MOD_POC;
        Message.oslMsgId = MSG_ID_POC_UPDATE_GROUP_ENTRY_REQ;
        Message.oslDataPtr = (oslParaType*) myMsgPtr;
        Message.oslPeerBuffPtr = NULL;
        OslMsgSendExtQueue(&Message);
    }
    else
    {
        kal_uint8	temp_uri[POC_MAX_URI_LEN];

        memset((S8*) temp_uri, 0, sizeof(temp_uri));
        mmi_ucs2_n_to_asc((S8*) temp_uri, (S8*) g_poc_cntx_p->contact_entry_disp.uri, POC_MAX_URI_LEN - 1);

        if (temp_uri[0] == 0 || !strstr((S8*) temp_uri, (S8*) "@"))
        {
            DisplayPopup(
                (PU8) GetString(STR_ID_POC_NULL_STR_ERR),
                IMG_GLOBAL_UNFINISHED,
                1,
                CS_NOTIFYDURATION,
                ERROR_TONE);
            return;
        }
        
        mmi_poc_entry_progressing();
        DeleteUptoScrID(SCR_ID_POC_CONTACT);
        DeleteScreenIfPresent(SCR_ID_POC_CONTACT);
        if (g_poc_cntx_p->curr_contact_op == XDM_PUT_REPLACE)
        {
            cont = &g_poc_cntx_p->contact_list_disp[g_poc_cntx_p->contact_selected];
            memset(
                g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].uri,
                0,
                sizeof(g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].uri));
            mmi_ucs2_n_to_asc(
                (S8*) g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].uri,
                (S8*) g_poc_cntx_p->contact_entry_disp.uri,
                (U32) POC_MAX_URI_LEN - 1);
            memset(
                g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].display_name,
                0,
                sizeof(g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].display_name));
            mmi_ucs2_n_to_asc(
                (S8*) g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].display_name,
                (S8*) g_poc_cntx_p->contact_entry_disp.display_name,
                (U32) POC_MAX_DISP_LEN - 1);

            g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].allow_invite =
                g_poc_cntx_p->contact_entry_disp.allow_invite;

            memcpy(
                &g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].auth_rule,
                &g_poc_cntx_p->contact_entry_disp.auth_rule,
                sizeof(poc_pres_authrule_struct));

            if (g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].sub_pres !=
                g_poc_cntx_p->contact_entry_disp.sub_pres)
            {
                g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].sub_pres =
                    g_poc_cntx_p->contact_entry_disp.sub_pres;
                if (g_poc_cntx_p->curr_use_pres_mode == MMI_TRUE)
                {
                    if (g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].sub_pres == POC_SETTING_TRUE)
                    {
                        mmi_poc_entry_update_subscribe_req(
                            POC_SUBSCRIBE_ACTION,
                            g_poc_cntx_p->contact_list[cont->group_id].entries[cont-> entry_id]. uri);
                        SetProtocolEventHandler(
                            mmi_poc_update_subscribe_success_rsp,
                            MSG_ID_POC_PRESENCE_SUBSCRIBE_RSP);
                    }
                    else if (g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].sub_pres ==
                             POC_SETTING_FALSE)
                    {
                        mmi_poc_entry_update_subscribe_req(
                            POC_UNSUBSCRIBE_ACTION,
                            g_poc_cntx_p->contact_list[cont->group_id].entries[cont-> entry_id]. uri);
                        SetProtocolEventHandler(
                            mmi_poc_update_subscribe_success_rsp,
                            MSG_ID_POC_PRESENCE_SUBSCRIBE_RSP);
                    }
                    else
                    {
                        g_poc_cntx_p->progressing.contact = MMI_FALSE;
                        if (GetActiveScreenId() == SCR_ID_POC_GENERAL_PROGRESSING)
                        {
                            DisplayPopup(
                                (U8*) GetString(STR_GLOBAL_DONE),
                                IMG_GLOBAL_ACTIVATED,
                                1,
                                UI_POPUP_NOTIFYDURATION_TIME,
                                (U8) SUCCESS_TONE);
                        }
                        DeleteScreenIfPresent(SCR_ID_POC_GENERAL_PROGRESSING);
                    }
                }
                else
                {
                    g_poc_cntx_p->progressing.contact = MMI_FALSE;
                    if (GetActiveScreenId() == SCR_ID_POC_GENERAL_PROGRESSING)
                    {
                        DisplayPopup(
                            (U8*) GetString(STR_GLOBAL_DONE),
                            IMG_GLOBAL_ACTIVATED,
                            1,
                            UI_POPUP_NOTIFYDURATION_TIME,
                            (U8) SUCCESS_TONE);
                    }
                    DeleteScreenIfPresent(SCR_ID_POC_GENERAL_PROGRESSING);
                }
            }
            else
            {
                g_poc_cntx_p->progressing.contact = MMI_FALSE;
                if (GetActiveScreenId() == SCR_ID_POC_GENERAL_PROGRESSING)
                {
                    DisplayPopup(
                        (U8*) GetString(STR_GLOBAL_DONE),
                        IMG_GLOBAL_ACTIVATED,
                        1,
                        UI_POPUP_NOTIFYDURATION_TIME,
                        (U8) SUCCESS_TONE);
                }
                DeleteScreenIfPresent(SCR_ID_POC_GENERAL_PROGRESSING);
            }
        }
        else
        {
        #ifdef __MMI_POC_ALWAYS_CREATE_MTK_CONTACT__
            for (i = 0; i < MAX_POC_GROUP_FILE_NUM * MAX_POC_GROUPS_PER_FILE_NUM; i++)
            {
                if (g_poc_cntx_p->contact_list[i].valid == MMI_TRUE)
                {
                    if (!strcmp((S8*) g_poc_cntx_p->contact_list[i].list_name, (S8*) POC_MTK_DEFAULT_CONTACT))
                    {
                        break;
                    }
                }
            }
            ASSERT(i != MAX_POC_GROUP_FILE_NUM * MAX_POC_GROUPS_PER_FILE_NUM);
        #else /* __MMI_POC_ALWAYS_CREATE_MTK_CONTACT__ */ 
            i = g_poc_cntx_p->update_grp_idx;
        #endif /* __MMI_POC_ALWAYS_CREATE_MTK_CONTACT__ */ 
            new_idx = g_poc_cntx_p->contact_list[i].no_entries;
            memset(
                g_poc_cntx_p->contact_list[i].entries[new_idx].uri,
                0,
                sizeof(g_poc_cntx_p->contact_list[i].entries[new_idx].uri));
            mmi_ucs2_n_to_asc(
                (S8*) g_poc_cntx_p->contact_list[i].entries[new_idx].uri,
                (S8*) g_poc_cntx_p->contact_entry_disp.uri,
                (U32) POC_MAX_URI_LEN - 1);
            memset(
                g_poc_cntx_p->contact_list[i].entries[new_idx].display_name,
                0,
                sizeof(g_poc_cntx_p->contact_list[i].entries[new_idx].display_name));
            mmi_ucs2_n_to_asc(
                (S8*) g_poc_cntx_p->contact_list[i].entries[new_idx].display_name,
                (S8*) g_poc_cntx_p->contact_entry_disp.display_name,
                (U32) POC_MAX_DISP_LEN - 1);

            g_poc_cntx_p->contact_list[i].entries[new_idx].allow_invite = g_poc_cntx_p->contact_entry_disp.allow_invite;

            memcpy(
                &g_poc_cntx_p->contact_list[i].entries[new_idx].auth_rule,
                &g_poc_cntx_p->contact_entry_disp.auth_rule,
                sizeof(poc_pres_authrule_struct));

            g_poc_cntx_p->contact_list[i].entries[new_idx].sub_pres = g_poc_cntx_p->contact_entry_disp.sub_pres;
            if ((g_poc_cntx_p->contact_list[i].entries[new_idx].sub_pres == POC_SETTING_TRUE) &&
                (g_poc_cntx_p->curr_use_pres_mode == MMI_TRUE))
            {
                mmi_poc_entry_update_subscribe_req(
                    POC_SUBSCRIBE_ACTION,
                    g_poc_cntx_p->contact_list[i].entries[new_idx].uri);
                SetProtocolEventHandler(mmi_poc_update_subscribe_success_rsp, MSG_ID_POC_PRESENCE_SUBSCRIBE_RSP);
            }
            else
            {
                g_poc_cntx_p->progressing.contact = MMI_FALSE;
                if (GetActiveScreenId() == SCR_ID_POC_GENERAL_PROGRESSING)
                {
                    DisplayPopup(
                        (U8*) GetString(STR_GLOBAL_DONE),
                        IMG_GLOBAL_ACTIVATED,
                        1,
                        UI_POPUP_NOTIFYDURATION_TIME,
                        (U8) SUCCESS_TONE);
                }
                DeleteScreenIfPresent(SCR_ID_POC_GENERAL_PROGRESSING);
            }
            g_poc_cntx_p->contact_list[i].no_entries++;
        }
        g_poc_cntx_p->contact_local_updated = MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_update_group_entry_rsp
 * DESCRIPTION
 *  update group entry response handler
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_update_group_entry_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    poc_update_group_entry_rsp_struct *msgRsp;
    mmi_poc_contact_list_disp *cont;
    U8 i, new_idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgRsp = (poc_update_group_entry_rsp_struct*) info;

    ClearProtocolEventHandler(MSG_ID_POC_UPDATE_GROUP_ENTRY_RSP);

    if (msgRsp->result == POC_OK)
    {
        if (g_poc_cntx_p->curr_contact_op == XDM_PUT_REPLACE)
        {
            cont = &g_poc_cntx_p->contact_list_disp[g_poc_cntx_p->contact_selected];
            if (msgRsp->xdm_item & POC_XDM_GL_PRESENT)
            {
                memset(
                    g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].uri,
                    0,
                    sizeof(g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].uri));
                mmi_ucs2_n_to_asc(
                    (S8*) g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].uri,
                    (S8*) g_poc_cntx_p->contact_entry_disp.uri,
                    (U32) POC_MAX_URI_LEN - 1);
                memset(
                    g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].display_name,
                    0,
                    sizeof(g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].display_name));
                mmi_ucs2_n_to_asc(
                    (S8*) g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].display_name,
                    (S8*) g_poc_cntx_p->contact_entry_disp.display_name,
                    (U32) POC_MAX_DISP_LEN - 1);
            }
            if (msgRsp->xdm_item & POC_XDM_AL_PRESENT)
            {
                g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].allow_invite =
                    g_poc_cntx_p->contact_entry_disp.allow_invite;
            }
            if (msgRsp->xdm_item & POC_XDM_AR_PRESENT)
            {
                memcpy(
                    &g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].auth_rule,
                    &g_poc_cntx_p->contact_entry_disp.auth_rule,
                    sizeof(poc_pres_authrule_struct));
            }

            if (msgRsp->xdm_item & POC_XDM_RLS_PRESENT)
            {
                if (g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].sub_pres !=
                    g_poc_cntx_p->contact_entry_disp.sub_pres)
                {
                    g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].sub_pres =
                        g_poc_cntx_p->contact_entry_disp.sub_pres;
                #ifdef __POC_NON_RLS__
                    if (g_poc_cntx_p->curr_use_pres_mode == MMI_TRUE)
                    {
                        if (g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].sub_pres ==
                            POC_SETTING_TRUE)
                        {
                            mmi_poc_entry_update_subscribe_req(
                                POC_SUBSCRIBE_ACTION,
                                g_poc_cntx_p->contact_list[cont->group_id].entries[cont-> entry_id]. uri);
                            if (msgRsp->xdm_item == g_poc_cntx_p->session_xdm)
                            {
                                SetProtocolEventHandler(
                                    mmi_poc_update_subscribe_success_rsp,
                                    MSG_ID_POC_PRESENCE_SUBSCRIBE_RSP);
                            }
                            else
                            {
                                SetProtocolEventHandler(
                                    mmi_poc_update_subscribe_partial_success_rsp,
                                    MSG_ID_POC_PRESENCE_SUBSCRIBE_RSP);
                            }
                        }
                        else if (g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].sub_pres ==
                                 POC_SETTING_FALSE)
                        {
                            mmi_poc_entry_update_subscribe_req(
                                POC_UNSUBSCRIBE_ACTION,
                                g_poc_cntx_p->contact_list[cont->group_id].entries[cont-> entry_id]. uri);
                            if (msgRsp->xdm_item == g_poc_cntx_p->session_xdm)
                            {
                                SetProtocolEventHandler(
                                    mmi_poc_update_subscribe_success_rsp,
                                    MSG_ID_POC_PRESENCE_SUBSCRIBE_RSP);
                            }
                            else
                            {
                                SetProtocolEventHandler(
                                    mmi_poc_update_subscribe_partial_success_rsp,
                                    MSG_ID_POC_PRESENCE_SUBSCRIBE_RSP);
                            }
                        }
                        else
                        {
                            g_poc_cntx_p->progressing.contact = MMI_FALSE;
                            if (GetActiveScreenId() == SCR_ID_POC_GENERAL_PROGRESSING)
                            {
                                if (msgRsp->xdm_item == g_poc_cntx_p->session_xdm)
                                {
                                    DisplayPopup(
                                        (U8*) GetString(STR_GLOBAL_DONE),
                                        IMG_GLOBAL_ACTIVATED,
                                        1,
                                        UI_POPUP_NOTIFYDURATION_TIME,
                                        (U8) SUCCESS_TONE);
                                }
                                else
                                {
                                    DisplayPopup(
                                        (U8*) GetString(STR_ID_POC_ERR_REG_PARTIAL_SUCCESS),
                                        IMG_GLOBAL_ACTIVATED,
                                        1,
                                        UI_POPUP_NOTIFYDURATION_TIME,
                                        (U8) WARNING_TONE);
                                }
                            }
                            DeleteScreenIfPresent(SCR_ID_POC_GENERAL_PROGRESSING);
                        }
                    }
                    else
                    {
                        g_poc_cntx_p->progressing.contact = MMI_FALSE;
                        if (GetActiveScreenId() == SCR_ID_POC_GENERAL_PROGRESSING)
                        {
                            if (msgRsp->xdm_item == g_poc_cntx_p->session_xdm)
                            {
                                DisplayPopup(
                                    (U8*) GetString(STR_GLOBAL_DONE),
                                    IMG_GLOBAL_ACTIVATED,
                                    1,
                                    UI_POPUP_NOTIFYDURATION_TIME,
                                    (U8) SUCCESS_TONE);
                            }
                            else
                            {
                                DisplayPopup(
                                    (U8*) GetString(STR_ID_POC_ERR_REG_PARTIAL_SUCCESS),
                                    IMG_GLOBAL_ACTIVATED,
                                    1,
                                    UI_POPUP_NOTIFYDURATION_TIME,
                                    (U8) WARNING_TONE);
                            }
                        }
                        DeleteScreenIfPresent(SCR_ID_POC_GENERAL_PROGRESSING);
                    }
                #else /* __POC_NON_RLS__ */ 
                    g_poc_cntx_p->progressing.contact = MMI_FALSE;
                    if (GetActiveScreenId() == SCR_ID_POC_GENERAL_PROGRESSING)
                    {
                        if (msgRsp->xdm_item == g_poc_cntx_p->session_xdm)
                        {
                            DisplayPopup(
                                (U8*) GetString(STR_GLOBAL_DONE),
                                IMG_GLOBAL_ACTIVATED,
                                1,
                                UI_POPUP_NOTIFYDURATION_TIME,
                                (U8) SUCCESS_TONE);
                        }
                        else
                        {
                            DisplayPopup(
                                (U8*) GetString(STR_ID_POC_ERR_REG_PARTIAL_SUCCESS),
                                IMG_GLOBAL_ACTIVATED,
                                1,
                                UI_POPUP_NOTIFYDURATION_TIME,
                                (U8) WARNING_TONE);
                        }
                    }
                    DeleteScreenIfPresent(SCR_ID_POC_GENERAL_PROGRESSING);
                #endif /* __POC_NON_RLS__ */ 
                }
                else
                {
                    g_poc_cntx_p->progressing.contact = MMI_FALSE;
                    if (GetActiveScreenId() == SCR_ID_POC_GENERAL_PROGRESSING)
                    {
                        if (msgRsp->xdm_item == g_poc_cntx_p->session_xdm)
                        {
                            DisplayPopup(
                                (U8*) GetString(STR_GLOBAL_DONE),
                                IMG_GLOBAL_ACTIVATED,
                                1,
                                UI_POPUP_NOTIFYDURATION_TIME,
                                (U8) SUCCESS_TONE);
                        }
                        else
                        {
                            DisplayPopup(
                                (U8*) GetString(STR_ID_POC_ERR_REG_PARTIAL_SUCCESS),
                                IMG_GLOBAL_ACTIVATED,
                                1,
                                UI_POPUP_NOTIFYDURATION_TIME,
                                (U8) WARNING_TONE);
                        }
                    }
                    DeleteScreenIfPresent(SCR_ID_POC_GENERAL_PROGRESSING);
                }
            }
            else
            {
                g_poc_cntx_p->progressing.contact = MMI_FALSE;
                if (GetActiveScreenId() == SCR_ID_POC_GENERAL_PROGRESSING)
                {
                    if (msgRsp->xdm_item == g_poc_cntx_p->session_xdm)
                    {
                        DisplayPopup(
                            (U8*) GetString(STR_GLOBAL_DONE),
                            IMG_GLOBAL_ACTIVATED,
                            1,
                            UI_POPUP_NOTIFYDURATION_TIME,
                            (U8) SUCCESS_TONE);
                    }
                    else
                    {
                        DisplayPopup(
                            (U8*) GetString(STR_ID_POC_ERR_REG_PARTIAL_SUCCESS),
                            IMG_GLOBAL_ACTIVATED,
                            1,
                            UI_POPUP_NOTIFYDURATION_TIME,
                            (U8) WARNING_TONE);
                    }
                }
                DeleteScreenIfPresent(SCR_ID_POC_GENERAL_PROGRESSING);
            }
        }
        else
        {
        #ifdef __MMI_POC_ALWAYS_CREATE_MTK_CONTACT__
            for (i = 0; i < MAX_POC_GROUP_FILE_NUM * MAX_POC_GROUPS_PER_FILE_NUM; i++)
            {
                if (g_poc_cntx_p->contact_list[i].valid == MMI_TRUE)
                {
                    if (!strcmp((S8*) g_poc_cntx_p->contact_list[i].list_name, (S8*) POC_MTK_DEFAULT_CONTACT))
                    {
                        break;
                    }
                }
            }
            ASSERT(i != MAX_POC_GROUP_FILE_NUM * MAX_POC_GROUPS_PER_FILE_NUM);
        #else /* __MMI_POC_ALWAYS_CREATE_MTK_CONTACT__ */ 
            i = g_poc_cntx_p->update_grp_idx;
        #endif /* __MMI_POC_ALWAYS_CREATE_MTK_CONTACT__ */ 
            new_idx = g_poc_cntx_p->contact_list[i].no_entries;
            if (msgRsp->xdm_item & POC_XDM_GL_PRESENT)
            {
                memset(
                    g_poc_cntx_p->contact_list[i].entries[new_idx].uri,
                    0,
                    sizeof(g_poc_cntx_p->contact_list[i].entries[new_idx].uri));
                mmi_ucs2_n_to_asc(
                    (S8*) g_poc_cntx_p->contact_list[i].entries[new_idx].uri,
                    (S8*) g_poc_cntx_p->contact_entry_disp.uri,
                    (U32) POC_MAX_URI_LEN - 1);
                memset(
                    g_poc_cntx_p->contact_list[i].entries[new_idx].display_name,
                    0,
                    sizeof(g_poc_cntx_p->contact_list[i].entries[new_idx].display_name));
                mmi_ucs2_n_to_asc(
                    (S8*) g_poc_cntx_p->contact_list[i].entries[new_idx].display_name,
                    (S8*) g_poc_cntx_p->contact_entry_disp.display_name,
                    (U32) POC_MAX_DISP_LEN - 1);
            }
            if (msgRsp->xdm_item & POC_XDM_AL_PRESENT)
            {
                g_poc_cntx_p->contact_list[i].entries[new_idx].allow_invite =
                    g_poc_cntx_p->contact_entry_disp.allow_invite;
            }
            if (msgRsp->xdm_item & POC_XDM_AR_PRESENT)
            {
                memcpy(
                    &g_poc_cntx_p->contact_list[i].entries[new_idx].auth_rule,
                    &g_poc_cntx_p->contact_entry_disp.auth_rule,
                    sizeof(poc_pres_authrule_struct));
            }

            if (msgRsp->xdm_item & POC_XDM_RLS_PRESENT)
            {
                g_poc_cntx_p->contact_list[i].entries[new_idx].sub_pres = g_poc_cntx_p->contact_entry_disp.sub_pres;
            #ifdef __POC_NON_RLS__
                if (g_poc_cntx_p->curr_use_pres_mode == MMI_TRUE)
                {
                    if (g_poc_cntx_p->contact_list[i].entries[new_idx].sub_pres == POC_SETTING_TRUE)
                    {
                        mmi_poc_entry_update_subscribe_req(
                            POC_SUBSCRIBE_ACTION,
                            g_poc_cntx_p->contact_list[i].entries[new_idx].uri);
                        if (msgRsp->xdm_item == g_poc_cntx_p->session_xdm)
                        {
                            SetProtocolEventHandler(
                                mmi_poc_update_subscribe_success_rsp,
                                MSG_ID_POC_PRESENCE_SUBSCRIBE_RSP);
                        }
                        else
                        {
                            SetProtocolEventHandler(
                                mmi_poc_update_subscribe_partial_success_rsp,
                                MSG_ID_POC_PRESENCE_SUBSCRIBE_RSP);
                        }
                    }
                    else
                    {
                        g_poc_cntx_p->progressing.contact = MMI_FALSE;
                        if (GetActiveScreenId() == SCR_ID_POC_GENERAL_PROGRESSING)
                        {
                            if (msgRsp->xdm_item == g_poc_cntx_p->session_xdm)
                            {
                                DisplayPopup(
                                    (U8*) GetString(STR_GLOBAL_DONE),
                                    IMG_GLOBAL_ACTIVATED,
                                    1,
                                    UI_POPUP_NOTIFYDURATION_TIME,
                                    (U8) SUCCESS_TONE);
                            }
                            else
                            {
                                DisplayPopup(
                                    (U8*) GetString(STR_ID_POC_ERR_REG_PARTIAL_SUCCESS),
                                    IMG_GLOBAL_ACTIVATED,
                                    1,
                                    UI_POPUP_NOTIFYDURATION_TIME,
                                    (U8) WARNING_TONE);
                            }
                        }
                        DeleteScreenIfPresent(SCR_ID_POC_GENERAL_PROGRESSING);
                    }
                }
                else
                {
                    g_poc_cntx_p->progressing.contact = MMI_FALSE;
                    if (GetActiveScreenId() == SCR_ID_POC_GENERAL_PROGRESSING)
                    {
                        if (msgRsp->xdm_item == g_poc_cntx_p->session_xdm)
                        {
                            DisplayPopup(
                                (U8*) GetString(STR_GLOBAL_DONE),
                                IMG_GLOBAL_ACTIVATED,
                                1,
                                UI_POPUP_NOTIFYDURATION_TIME,
                                (U8) SUCCESS_TONE);
                        }
                        else
                        {
                            DisplayPopup(
                                (U8*) GetString(STR_ID_POC_ERR_REG_PARTIAL_SUCCESS),
                                IMG_GLOBAL_ACTIVATED,
                                1,
                                UI_POPUP_NOTIFYDURATION_TIME,
                                (U8) WARNING_TONE);
                        }
                    }
                    DeleteScreenIfPresent(SCR_ID_POC_GENERAL_PROGRESSING);
                }
            #else /* __POC_NON_RLS__ */ 
                g_poc_cntx_p->progressing.contact = MMI_FALSE;
                if (GetActiveScreenId() == SCR_ID_POC_GENERAL_PROGRESSING)
                {
                    if (msgRsp->xdm_item == g_poc_cntx_p->session_xdm)
                    {
                        DisplayPopup(
                            (U8*) GetString(STR_GLOBAL_DONE),
                            IMG_GLOBAL_ACTIVATED,
                            1,
                            UI_POPUP_NOTIFYDURATION_TIME,
                            (U8) SUCCESS_TONE);
                    }
                    else
                    {
                        DisplayPopup(
                            (U8*) GetString(STR_ID_POC_ERR_REG_PARTIAL_SUCCESS),
                            IMG_GLOBAL_ACTIVATED,
                            1,
                            UI_POPUP_NOTIFYDURATION_TIME,
                            (U8) WARNING_TONE);
                    }
                }
                DeleteScreenIfPresent(SCR_ID_POC_GENERAL_PROGRESSING);
            #endif /* __POC_NON_RLS__ */ 
            }
            else
            {
                g_poc_cntx_p->progressing.contact = MMI_FALSE;
                if (GetActiveScreenId() == SCR_ID_POC_GENERAL_PROGRESSING)
                {
                    if (msgRsp->xdm_item == g_poc_cntx_p->session_xdm)
                    {
                        DisplayPopup(
                            (U8*) GetString(STR_GLOBAL_DONE),
                            IMG_GLOBAL_ACTIVATED,
                            1,
                            UI_POPUP_NOTIFYDURATION_TIME,
                            (U8) SUCCESS_TONE);
                    }
                    else
                    {
                        DisplayPopup(
                            (U8*) GetString(STR_ID_POC_ERR_REG_PARTIAL_SUCCESS),
                            IMG_GLOBAL_ACTIVATED,
                            1,
                            UI_POPUP_NOTIFYDURATION_TIME,
                            (U8) WARNING_TONE);
                    }
                }
                DeleteScreenIfPresent(SCR_ID_POC_GENERAL_PROGRESSING);
            }
            g_poc_cntx_p->contact_list[i].no_entries++;
        }
        g_poc_cntx_p->contact_local_updated = MMI_FALSE;
    }
    else
    {
        g_poc_cntx_p->progressing.contact = MMI_FALSE;
        if (GetActiveScreenId() == SCR_ID_POC_GENERAL_PROGRESSING)
        {
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_NOT_DONE),
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
        }
        DeleteScreenIfPresent(SCR_ID_POC_GENERAL_PROGRESSING);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_update_subscribe_success_rsp
 * DESCRIPTION
 *  update subscribe success response handler
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_update_subscribe_success_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_poc_cntx_p->progressing.contact = MMI_FALSE;
    if (GetActiveScreenId() == SCR_ID_POC_GENERAL_PROGRESSING)
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_DONE),
            IMG_GLOBAL_ACTIVATED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) SUCCESS_TONE);
    }
    DeleteScreenIfPresent(SCR_ID_POC_GENERAL_PROGRESSING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_update_subscribe_partial_success_rsp
 * DESCRIPTION
 *  update subscribe partial success response handler
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_update_subscribe_partial_success_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_poc_cntx_p->progressing.contact = MMI_FALSE;
    if (GetActiveScreenId() == SCR_ID_POC_GENERAL_PROGRESSING)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_POC_ERR_REG_PARTIAL_SUCCESS),
            IMG_GLOBAL_ACTIVATED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
    }
    DeleteScreenIfPresent(SCR_ID_POC_GENERAL_PROGRESSING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_create_group_list_req
 * DESCRIPTION
 *  create group list request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_create_group_list_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    poc_create_group_list_req_struct *myMsgPtr;
    U8 new_idx, contact_idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_poc_cntx_p->curr_use_xdm_mode == MMI_TRUE)
    {
        myMsgPtr = (poc_create_group_list_req_struct*) OslConstructDataPtr(sizeof(poc_create_group_list_req_struct));
        memset(
            (U8*) myMsgPtr + sizeof(mmi_poc_dummy_req_struct),
            0,
            sizeof(poc_create_group_list_req_struct) - sizeof(mmi_poc_dummy_req_struct));

        myMsgPtr->request_id = POC_REQUEST_ID;
        strncpy((char*)myMsgPtr->list_name, (char*)POC_MTK_DEFAULT_CONTACT, POC_MAX_DISP_LEN - 1);

        myMsgPtr->entry.xdm_item = 0x0F;
        myMsgPtr->entry.allow_invite = g_poc_cntx_p->contact_entry_disp.allow_invite;
        myMsgPtr->entry.sub_pres = g_poc_cntx_p->contact_entry_disp.sub_pres;

        if (g_poc_cntx_p->contact_entry_disp.auth_rule.sub_handling != POC_MMI_SUB_EMPTY)
        {
            myMsgPtr->entry.auth_rule.sub_handling = g_poc_cntx_p->contact_entry_disp.auth_rule.sub_handling - 1;
        }

        myMsgPtr->entry.auth_rule.pres_attr = g_poc_cntx_p->contact_entry_disp.auth_rule.pres_attr;

        mmi_ucs2_n_to_asc((S8*) myMsgPtr->entry.uri, (S8*) g_poc_cntx_p->contact_entry_disp.uri, POC_MAX_URI_LEN - 1);
        mmi_ucs2_n_to_asc(
            (S8*) myMsgPtr->entry.disp_name,
            (S8*) g_poc_cntx_p->contact_entry_disp.display_name,
            POC_MAX_DISP_LEN - 1);

        if (myMsgPtr->entry.uri[0] == 0 || !strstr((S8*) myMsgPtr->entry.uri, (S8*) "@"))
        {
            DisplayPopup(
                (PU8) GetString(STR_ID_POC_NULL_STR_ERR),
                IMG_GLOBAL_UNFINISHED,
                1,
                CS_NOTIFYDURATION,
                ERROR_TONE);
            OslFreeDataPtr((void*)myMsgPtr);
            return;
        }

        SetProtocolEventHandler(mmi_poc_create_group_list_rsp, MSG_ID_POC_CREATE_GROUP_LIST_RSP);

        g_poc_cntx_p->progressing.contact = MMI_TRUE;
        mmi_poc_entry_progressing();
        DeleteUptoScrID(SCR_ID_POC_CONTACT);
        DeleteScreenIfPresent(SCR_ID_POC_CONTACT);

        Message.oslSrcId = MOD_MMI;
        Message.oslDestId = MOD_POC;
        Message.oslMsgId = MSG_ID_POC_CREATE_GROUP_LIST_REQ;
        Message.oslDataPtr = (oslParaType*) myMsgPtr;
        Message.oslPeerBuffPtr = NULL;
        OslMsgSendExtQueue(&Message);
    }
    else
    {
        kal_uint8	temp_uri[POC_MAX_URI_LEN];

        memset((S8*) temp_uri, 0, sizeof(temp_uri));
        mmi_ucs2_n_to_asc((S8*) temp_uri, (S8*) g_poc_cntx_p->contact_entry_disp.uri, POC_MAX_URI_LEN - 1);

        if (temp_uri[0] == 0 || !strstr((S8*) temp_uri, (S8*) "@"))
        {
            DisplayPopup(
                (PU8) GetString(STR_ID_POC_NULL_STR_ERR),
                IMG_GLOBAL_UNFINISHED,
                1,
                CS_NOTIFYDURATION,
                ERROR_TONE);
            return;
        }
        
        mmi_poc_entry_progressing();
        DeleteUptoScrID(SCR_ID_POC_CONTACT);
        DeleteScreenIfPresent(SCR_ID_POC_CONTACT);
        for (contact_idx = 0; contact_idx < MAX_POC_GROUP_FILE_NUM * MAX_POC_GROUPS_PER_FILE_NUM; contact_idx++)
        {
            if (g_poc_cntx_p->contact_list[contact_idx].valid == MMI_FALSE)
            {
                break;
            }
        }
        g_poc_cntx_p->contact_list[contact_idx].valid = MMI_TRUE;
        strncpy(
            (S8*) g_poc_cntx_p->contact_list[contact_idx].list_name,
            (S8*) POC_MTK_DEFAULT_CONTACT,
            POC_MAX_DISP_LEN - 1);
        g_poc_cntx_p->contact_list[contact_idx].no_entries = 1;
        new_idx = 0;

        memset(
            g_poc_cntx_p->contact_list[contact_idx].entries[new_idx].uri,
            0,
            sizeof(g_poc_cntx_p->contact_list[contact_idx].entries[new_idx].uri));
        mmi_ucs2_n_to_asc(
            (S8*) g_poc_cntx_p->contact_list[contact_idx].entries[new_idx].uri,
            (S8*) g_poc_cntx_p->contact_entry_disp.uri,
            (U32) POC_MAX_URI_LEN - 1);
        memset(
            g_poc_cntx_p->contact_list[contact_idx].entries[new_idx].display_name,
            0,
            sizeof(g_poc_cntx_p->contact_list[contact_idx].entries[new_idx].display_name));
        mmi_ucs2_n_to_asc(
            (S8*) g_poc_cntx_p->contact_list[contact_idx].entries[new_idx].display_name,
            (S8*) g_poc_cntx_p->contact_entry_disp.display_name,
            (U32) POC_MAX_DISP_LEN - 1);

        g_poc_cntx_p->contact_list[contact_idx].entries[new_idx].allow_invite =
            g_poc_cntx_p->contact_entry_disp.allow_invite;

        memcpy(
            &g_poc_cntx_p->contact_list[contact_idx].entries[new_idx].auth_rule,
            &g_poc_cntx_p->contact_entry_disp.auth_rule,
            sizeof(poc_pres_authrule_struct));

        g_poc_cntx_p->contact_list[contact_idx].entries[new_idx].sub_pres = g_poc_cntx_p->contact_entry_disp.sub_pres;
        if ((g_poc_cntx_p->contact_list[contact_idx].entries[new_idx].sub_pres == POC_SETTING_TRUE) &&
            (g_poc_cntx_p->curr_use_pres_mode == MMI_TRUE))
        {
            mmi_poc_entry_update_subscribe_req(
                POC_SUBSCRIBE_ACTION,
                g_poc_cntx_p->contact_list[contact_idx].entries[new_idx].uri);
            SetProtocolEventHandler(mmi_poc_update_subscribe_success_rsp, MSG_ID_POC_PRESENCE_SUBSCRIBE_RSP);
        }
        else
        {
            g_poc_cntx_p->progressing.contact = MMI_FALSE;
            if (GetActiveScreenId() == SCR_ID_POC_GENERAL_PROGRESSING)
            {
                DisplayPopup(
                    (U8*) GetString(STR_GLOBAL_DONE),
                    IMG_GLOBAL_ACTIVATED,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    (U8) SUCCESS_TONE);
            }
            DeleteScreenIfPresent(SCR_ID_POC_GENERAL_PROGRESSING);
        }
        g_poc_cntx_p->contact_local_updated = MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_create_group_list_rsp
 * DESCRIPTION
 *  create group list response handler
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_create_group_list_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    poc_create_group_list_rsp_struct *msgRsp;
    U8 new_idx, contact_idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgRsp = (poc_create_group_list_rsp_struct*) info;

    ClearProtocolEventHandler(MSG_ID_POC_CREATE_GROUP_LIST_RSP);

    if (msgRsp->result == POC_OK)
    {
    #ifndef __POC_NON_RLS__
        g_poc_cntx_p->progressing.contact = MMI_FALSE;
        if (GetActiveScreenId() == SCR_ID_POC_GENERAL_PROGRESSING)
        {
            if (msgRsp->xdm_item == 0x0F)
            {
                DisplayPopup(
                    (U8*) GetString(STR_GLOBAL_DONE),
                    IMG_GLOBAL_ACTIVATED,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    (U8) SUCCESS_TONE);
            }
            else
            {
                DisplayPopup(
                    (U8*) GetString(STR_ID_POC_ERR_REG_PARTIAL_SUCCESS),
                    IMG_GLOBAL_ACTIVATED,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    (U8) WARNING_TONE);
            }
        }
        DeleteScreenIfPresent(SCR_ID_POC_GENERAL_PROGRESSING);
    #endif /* __POC_NON_RLS__ */ 

        for (contact_idx = 0; contact_idx < MAX_POC_GROUP_FILE_NUM * MAX_POC_GROUPS_PER_FILE_NUM; contact_idx++)
        {
            if (g_poc_cntx_p->contact_list[contact_idx].valid == MMI_FALSE)
            {
                break;
            }
        }

        g_poc_cntx_p->contact_list[contact_idx].valid = MMI_TRUE;
        strncpy(
            (S8*) g_poc_cntx_p->contact_list[contact_idx].list_name,
            (S8*) POC_MTK_DEFAULT_CONTACT,
            POC_MAX_DISP_LEN - 1);
        g_poc_cntx_p->contact_list[contact_idx].no_entries = 1;
        new_idx = 0;
        if (msgRsp->xdm_item & POC_XDM_GL_PRESENT)
        {
            memset(
                g_poc_cntx_p->contact_list[contact_idx].entries[new_idx].uri,
                0,
                sizeof(g_poc_cntx_p->contact_list[contact_idx].entries[new_idx].uri));
            mmi_ucs2_n_to_asc(
                (S8*) g_poc_cntx_p->contact_list[contact_idx].entries[new_idx].uri,
                (S8*) g_poc_cntx_p->contact_entry_disp.uri,
                (U32) POC_MAX_URI_LEN - 1);
            memset(
                g_poc_cntx_p->contact_list[contact_idx].entries[new_idx].display_name,
                0,
                sizeof(g_poc_cntx_p->contact_list[contact_idx].entries[new_idx].display_name));
            mmi_ucs2_n_to_asc(
                (S8*) g_poc_cntx_p->contact_list[contact_idx].entries[new_idx].display_name,
                (S8*) g_poc_cntx_p->contact_entry_disp.display_name,
                (U32) POC_MAX_DISP_LEN - 1);
        }
        if (msgRsp->xdm_item & POC_XDM_AL_PRESENT)
        {
            g_poc_cntx_p->contact_list[contact_idx].entries[new_idx].allow_invite =
                g_poc_cntx_p->contact_entry_disp.allow_invite;
        }
        if (msgRsp->xdm_item & POC_XDM_AR_PRESENT)
        {
            memcpy(
                &g_poc_cntx_p->contact_list[contact_idx].entries[new_idx].auth_rule,
                &g_poc_cntx_p->contact_entry_disp.auth_rule,
                sizeof(poc_pres_authrule_struct));
        }
        if (msgRsp->xdm_item & POC_XDM_RLS_PRESENT)
        {
            g_poc_cntx_p->contact_list[contact_idx].entries[new_idx].sub_pres =
                g_poc_cntx_p->contact_entry_disp.sub_pres;
        #ifdef __POC_NON_RLS__
            if ((g_poc_cntx_p->contact_list[contact_idx].entries[new_idx].sub_pres == POC_SETTING_TRUE) &&
                (g_poc_cntx_p->curr_use_pres_mode == MMI_TRUE))
            {
                mmi_poc_entry_update_subscribe_req(
                    POC_SUBSCRIBE_ACTION,
                    g_poc_cntx_p->contact_list[contact_idx].entries[new_idx].uri);
                if (msgRsp->xdm_item == 0x0F)
                {
                    SetProtocolEventHandler(mmi_poc_update_subscribe_success_rsp, MSG_ID_POC_PRESENCE_SUBSCRIBE_RSP);
                }
                else
                {
                    SetProtocolEventHandler(
                        mmi_poc_update_subscribe_partial_success_rsp,
                        MSG_ID_POC_PRESENCE_SUBSCRIBE_RSP);
                }
            }
            else
            {
                g_poc_cntx_p->progressing.contact = MMI_FALSE;
                if (GetActiveScreenId() == SCR_ID_POC_GENERAL_PROGRESSING)
                {
                    if (msgRsp->xdm_item == 0x0F)
                    {
                        DisplayPopup(
                            (U8*) GetString(STR_GLOBAL_DONE),
                            IMG_GLOBAL_ACTIVATED,
                            1,
                            UI_POPUP_NOTIFYDURATION_TIME,
                            (U8) SUCCESS_TONE);
                    }
                    else
                    {
                        DisplayPopup(
                            (U8*) GetString(STR_ID_POC_ERR_REG_PARTIAL_SUCCESS),
                            IMG_GLOBAL_ACTIVATED,
                            1,
                            UI_POPUP_NOTIFYDURATION_TIME,
                            (U8) WARNING_TONE);
                    }
                }
                DeleteScreenIfPresent(SCR_ID_POC_GENERAL_PROGRESSING);
            }
        #endif /* __POC_NON_RLS__ */ 
        }
        else
        {
            g_poc_cntx_p->progressing.contact = MMI_FALSE;
            if (GetActiveScreenId() == SCR_ID_POC_GENERAL_PROGRESSING)
            {
                if (msgRsp->xdm_item == 0x0F)
                {
                    DisplayPopup(
                        (U8*) GetString(STR_GLOBAL_DONE),
                        IMG_GLOBAL_ACTIVATED,
                        1,
                        UI_POPUP_NOTIFYDURATION_TIME,
                        (U8) SUCCESS_TONE);
                }
                else
                {
                    DisplayPopup(
                        (U8*) GetString(STR_ID_POC_ERR_REG_PARTIAL_SUCCESS),
                        IMG_GLOBAL_ACTIVATED,
                        1,
                        UI_POPUP_NOTIFYDURATION_TIME,
                        (U8) WARNING_TONE);
                }
            }
            DeleteScreenIfPresent(SCR_ID_POC_GENERAL_PROGRESSING);
        }
        g_poc_cntx_p->contact_local_updated = MMI_FALSE;
    }
    else
    {
        g_poc_cntx_p->progressing.contact = MMI_FALSE;
        if (GetActiveScreenId() == SCR_ID_POC_GENERAL_PROGRESSING)
        {
            if (msgRsp->cause == POC_GRP_CAUSE_MAX_NUM_REACHES)
            {
                DisplayPopup(
                    (U8*) GetString(STR_ID_POC_ERR_MAXIMUM_REACHED),
                    IMG_GLOBAL_UNFINISHED,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    (U8) ERROR_TONE);
            }
            else
            {
                DisplayPopup(
                    (U8*) GetString(STR_GLOBAL_NOT_DONE),
                    IMG_GLOBAL_UNFINISHED,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    (U8) ERROR_TONE);
            }
        }
        DeleteScreenIfPresent(SCR_ID_POC_GENERAL_PROGRESSING);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_update_subscribe_req
 * DESCRIPTION
 *  update subscribe request
 * PARAMETERS
 *  op      [IN]        
 *  uri     [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_update_subscribe_req(U8 op, U8 *uri)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    poc_presence_subscribe_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (poc_presence_subscribe_req_struct*) OslConstructDataPtr(sizeof(poc_presence_subscribe_req_struct));

    myMsgPtr->action = op;
    myMsgPtr->use_presence_list = MMI_FALSE;

    memcpy(myMsgPtr->uri, uri, POC_MAX_URI_LEN * sizeof(U8));

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_POC;
    Message.oslMsgId = MSG_ID_POC_PRESENCE_SUBSCRIBE_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

    ClearProtocolEventHandler(MSG_ID_POC_PRESENCE_SUBSCRIBE_RSP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_contact_opt_settings_delete_cfrm
 * DESCRIPTION
 *  entry delete confirm screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_contact_opt_settings_delete_cfrm(void)
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

    SetLeftSoftkeyFunction(mmi_poc_contact_send_delete, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_poc_go_back_contact_list, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_contact_send_delete
 * DESCRIPTION
 *  send entry delete
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_contact_send_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_poc_entry_progressing();
    DeleteUptoScrID(SCR_ID_POC_CONTACT);
    DeleteScreenIfPresent(SCR_ID_POC_CONTACT);

    mmi_poc_del_group_entry_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_del_group_entry_req
 * DESCRIPTION
 *  entry delete request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_del_group_entry_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    poc_del_group_entry_req_struct *myMsgPtr;
    mmi_poc_contact_list_disp *cont;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_poc_cntx_p->curr_use_xdm_mode == MMI_TRUE)
    {
        cont = &g_poc_cntx_p->contact_list_disp[g_poc_cntx_p->contact_selected];

        g_poc_cntx_p->progressing.contact = MMI_TRUE;

        myMsgPtr = (poc_del_group_entry_req_struct*) OslConstructDataPtr(sizeof(poc_del_group_entry_req_struct));
        memset(
            (U8*) myMsgPtr + sizeof(mmi_poc_dummy_req_struct),
            0,
            sizeof(poc_del_group_entry_req_struct) - sizeof(mmi_poc_dummy_req_struct));

        myMsgPtr->request_id = POC_REQUEST_ID;
        strncpy(
            (char*)myMsgPtr->list_name,
            (char*)g_poc_cntx_p->contact_list[cont->group_id].list_name,
            POC_MAX_DISP_LEN - 1);
        strncpy(
            (char*)myMsgPtr->uri,
            (char*)g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].uri,
            POC_MAX_URI_LEN - 1);
        myMsgPtr->xdm_item = 0x0F;

        SetProtocolEventHandler(mmi_poc_del_group_entry_rsp, MSG_ID_POC_DEL_GROUP_ENTRY_RSP);

        Message.oslSrcId = MOD_MMI;
        Message.oslDestId = MOD_POC;
        Message.oslMsgId = MSG_ID_POC_DEL_GROUP_ENTRY_REQ;
        Message.oslDataPtr = (oslParaType*) myMsgPtr;
        Message.oslPeerBuffPtr = NULL;
        OslMsgSendExtQueue(&Message);
    }
    else
    {
    #ifndef __POC_NON_RLS__
        g_poc_cntx_p->progressing.contact = MMI_FALSE;
        if (GetActiveScreenId() == SCR_ID_POC_GENERAL_PROGRESSING)
        {
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_DONE),
                IMG_GLOBAL_ACTIVATED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) SUCCESS_TONE);
        }
        DeleteScreenIfPresent(SCR_ID_POC_GENERAL_PROGRESSING);
    #endif /* __POC_NON_RLS__ */ 
        cont = &g_poc_cntx_p->contact_list_disp[g_poc_cntx_p->contact_selected];

    #ifdef __POC_NON_RLS__
        if ((g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].sub_pres == POC_SETTING_TRUE) &&
            (g_poc_cntx_p->curr_use_pres_mode == MMI_TRUE))
        {
            mmi_poc_entry_update_subscribe_req(
                POC_UNSUBSCRIBE_ACTION,
                g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].uri);
            SetProtocolEventHandler(mmi_poc_update_subscribe_success_rsp, MSG_ID_POC_PRESENCE_SUBSCRIBE_RSP);
        }
        else
        {
            g_poc_cntx_p->progressing.contact = MMI_FALSE;
            if (GetActiveScreenId() == SCR_ID_POC_GENERAL_PROGRESSING)
            {
                DisplayPopup(
                    (U8*) GetString(STR_GLOBAL_DONE),
                    IMG_GLOBAL_ACTIVATED,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    (U8) SUCCESS_TONE);
            }
            DeleteScreenIfPresent(SCR_ID_POC_GENERAL_PROGRESSING);
        }
    #endif /* __POC_NON_RLS__ */ 
        i = g_poc_cntx_p->contact_list[cont->group_id].no_entries - 1;
        memcpy(
            &g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id],
            &g_poc_cntx_p->contact_list[cont->group_id].entries[i],
            sizeof(mmi_poc_contact_entry_struct));
        memset(&g_poc_cntx_p->contact_list[cont->group_id].entries[i], 0, sizeof(mmi_poc_contact_entry_struct));

        if (g_poc_cntx_p->contact_list[cont->group_id].no_entries > 0)
        {
            g_poc_cntx_p->contact_list[cont->group_id].no_entries--;
        }

        g_poc_cntx_p->contact_local_updated = MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_del_group_entry_rsp
 * DESCRIPTION
 *  delete contact entry response handler
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_del_group_entry_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    poc_del_group_entry_rsp_struct *msgRsp;
    U8 i;
    mmi_poc_contact_list_disp *cont;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgRsp = (poc_del_group_entry_rsp_struct*) info;

    ClearProtocolEventHandler(MSG_ID_POC_DEL_GROUP_ENTRY_RSP);

    if (msgRsp->result == POC_OK)
    {
    #ifndef __POC_NON_RLS__
        g_poc_cntx_p->progressing.contact = MMI_FALSE;
        if (GetActiveScreenId() == SCR_ID_POC_GENERAL_PROGRESSING)
        {
            if (msgRsp->xdm_item == 0x0F)
            {
                DisplayPopup(
                    (U8*) GetString(STR_GLOBAL_DONE),
                    IMG_GLOBAL_ACTIVATED,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    (U8) SUCCESS_TONE);
            }
            else
            {
                DisplayPopup(
                    (U8*) GetString(STR_ID_POC_ERR_REG_PARTIAL_SUCCESS),
                    IMG_GLOBAL_ACTIVATED,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    (U8) WARNING_TONE);
            }
        }
        DeleteScreenIfPresent(SCR_ID_POC_GENERAL_PROGRESSING);
    #endif /* __POC_NON_RLS__ */ 
        cont = &g_poc_cntx_p->contact_list_disp[g_poc_cntx_p->contact_selected];

    #ifdef __POC_NON_RLS__
        if ((g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].sub_pres == POC_SETTING_TRUE) &&
            (g_poc_cntx_p->curr_use_pres_mode == MMI_TRUE))
        {
            mmi_poc_entry_update_subscribe_req(
                POC_UNSUBSCRIBE_ACTION,
                g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].uri);
            if (msgRsp->xdm_item == 0x0F)
            {
                SetProtocolEventHandler(mmi_poc_update_subscribe_success_rsp, MSG_ID_POC_PRESENCE_SUBSCRIBE_RSP);
            }
            else
            {
                SetProtocolEventHandler(
                    mmi_poc_update_subscribe_partial_success_rsp,
                    MSG_ID_POC_PRESENCE_SUBSCRIBE_RSP);
            }

        }
        else
        {
            g_poc_cntx_p->progressing.contact = MMI_FALSE;
            if (msgRsp->xdm_item == 0x0F)
            {
                DisplayPopup(
                    (U8*) GetString(STR_GLOBAL_DONE),
                    IMG_GLOBAL_ACTIVATED,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    (U8) SUCCESS_TONE);
            }
            else
            {
                DisplayPopup(
                    (U8*) GetString(STR_ID_POC_ERR_REG_PARTIAL_SUCCESS),
                    IMG_GLOBAL_ACTIVATED,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    (U8) WARNING_TONE);
            }
        }
        DeleteScreenIfPresent(SCR_ID_POC_GENERAL_PROGRESSING);
    #endif /* __POC_NON_RLS__ */ 

        i = g_poc_cntx_p->contact_list[cont->group_id].no_entries - 1;
        memcpy(
            &g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id],
            &g_poc_cntx_p->contact_list[cont->group_id].entries[i],
            sizeof(mmi_poc_contact_entry_struct));
        memset(&g_poc_cntx_p->contact_list[cont->group_id].entries[i], 0, sizeof(mmi_poc_contact_entry_struct));

        if (g_poc_cntx_p->contact_list[cont->group_id].no_entries > 0)
        {
            g_poc_cntx_p->contact_list[cont->group_id].no_entries--;
        }

        g_poc_cntx_p->contact_local_updated = MMI_FALSE;
    }
    else
    {
        g_poc_cntx_p->progressing.contact = MMI_FALSE;
        if (GetActiveScreenId() == SCR_ID_POC_GENERAL_PROGRESSING)
        {
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_NOT_DONE),
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
        }
        DeleteScreenIfPresent(SCR_ID_POC_GENERAL_PROGRESSING);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_contact_opt_settings_info
 * DESCRIPTION
 *  entry settings info screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_contact_opt_settings_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];
    U16 nNumofItem;
    U8 *guiBuffer;
    U8 *PoCHint[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_POC_CONTACT_ENTRY_INFO, NULL, mmi_poc_entry_contact_opt_settings_info, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_POC_CONTACT_ENTRY_INFO);

    nNumofItem = GetNumOfChild(MENU_ID_POC_CONTACT_OPT_SETTINGS_INFO);
    GetSequenceStringIds(MENU_ID_POC_CONTACT_OPT_SETTINGS_INFO, nStrItemList);
    SetParentHandler(MENU_ID_POC_CONTACT_OPT_SETTINGS_INFO);
    ConstructHintsList(MENU_ID_POC_CONTACT_OPT_SETTINGS_INFO, PoCHint);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_ID_POC_MAIN,
        GetRootTitleIcon(MENU_ID_POC_MAIN),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        PoCHint,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_hint_entry_activity
 * DESCRIPTION
 *  hint handler of PoC menu
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_hint_entry_activity(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_poc_contact_list_disp *cont;
    mmi_poc_presence_struct *pres;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cont = &g_poc_cntx_p->contact_list_disp[g_poc_cntx_p->contact_selected];
    pres = &g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].pres;

    memset((S8*) hintData[(index)], 0, MAX_SUB_MENU_SIZE);

    if (pres->person.activity_present == MMI_TRUE)
    {
        if (pres->person.activity <= POC_ACTIVITY_BUSY)
        {
            mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString((U16) (STR_ID_POC_AWAY + pres->person.activity)));
        }
        else
        {
            mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_UNSUPPORTED_FORMAT));
        }
    }
    else
    {
        mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_EMPTY));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_hint_entry_mood
 * DESCRIPTION
 *  hint handler of PoC menu
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_hint_entry_mood(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_poc_contact_list_disp *cont;
    mmi_poc_presence_struct *pres;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cont = &g_poc_cntx_p->contact_list_disp[g_poc_cntx_p->contact_selected];
    pres = &g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].pres;

    memset((S8*) hintData[(index)], 0, MAX_SUB_MENU_SIZE);

    if (pres->person.mood_present == MMI_TRUE)
    {
        switch (pres->person.mood)
        {
            case POC_MOOD_HAPPY:
                mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_ID_POC_HAPPY));
                break;
            case POC_MOOD_BORED:
                mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_ID_POC_BORED));
                break;
            case POC_MOOD_DEPRESSED:
                mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_ID_POC_DEPRESSED));
                break;
            default:
                mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_UNSUPPORTED_FORMAT));
                break;
        }
    }
    else
    {
        mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_EMPTY));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_contact_opt_send_alert
 * DESCRIPTION
 *  send alert screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_contact_opt_send_alert(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_poc_cntx_p->progressing.alert == MMI_TRUE)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_POC_PROCESSING),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
        return;
    }

    if (g_poc_cntx_p->curr_privacy_mode)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_POC_ERR_TURN_OFF_PRIVACY_MODE),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
        return;
    }

    EntryNewScreen(SCR_ID_POC_CONTACT_ALERT, NULL, mmi_poc_entry_contact_opt_send_alert, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_POC_CONTACT_ALERT);

    if (guiBuffer == NULL)
    {
        memset(g_poc_cntx_p->alert_text_buf, 0, sizeof(g_poc_cntx_p->alert_text_buf));
    }

    ShowCategory5Screen(
        STR_ID_POC_ALERT_TEXT,
        GetRootTitleIcon(MENU_ID_POC_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES,
        (PU8) g_poc_cntx_p->alert_text_buf,
        MMI_POC_MAX_MSG_LEN,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_poc_send_personal_alert_req, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_send_personal_alert_req
 * DESCRIPTION
 *  send alert request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_send_personal_alert_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    poc_send_personal_alert_req_struct *myMsgPtr;
    mmi_poc_contact_list_disp *cont;
    U8 message_buf[MMI_POC_MAX_MSG_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_poc_entry_progressing();
    DeleteUptoScrID(SCR_ID_POC_MAIN);

    cont = &g_poc_cntx_p->contact_list_disp[g_poc_cntx_p->contact_selected];
    g_poc_cntx_p->progressing.alert = MMI_TRUE;

    myMsgPtr = (poc_send_personal_alert_req_struct*) OslConstructDataPtr(sizeof(poc_send_personal_alert_req_struct));
    memset(
        (U8*) myMsgPtr + sizeof(mmi_poc_dummy_req_struct),
        0,
        sizeof(poc_send_personal_alert_req_struct) - sizeof(mmi_poc_dummy_req_struct));

    myMsgPtr->request_id = POC_REQUEST_ID;
    myMsgPtr->num_addr = 1;

    memcpy(
        myMsgPtr->recipient[0].disp_name,
        g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].display_name,
        sizeof(U8) * POC_MAX_DISP_LEN);

    memcpy(
        myMsgPtr->recipient[0].uri,
        g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].uri,
        sizeof(U8) * POC_MAX_URI_LEN);

    mmi_ucs2_to_asc((S8*) myMsgPtr->content, (S8*) g_poc_cntx_p->alert_text_buf);
    myMsgPtr->content_length = strlen((S8*) myMsgPtr->content);

    SetProtocolEventHandler(mmi_poc_send_personal_alert_rsp, MSG_ID_POC_SEND_PERSONAL_ALERT_RSP);

    memset(message_buf, 0, sizeof(message_buf));
    strncpy((S8*) message_buf, (S8*) myMsgPtr->content, MMI_POC_MAX_MSG_LEN - 1);
    mmi_poc_history_add(
        POC_OUTGOING_ALERT,
        MMI_FALSE,
        (U8*) myMsgPtr->recipient[0].disp_name,
        (U8*) myMsgPtr->recipient[0].uri,
        message_buf);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_POC;
    Message.oslMsgId = MSG_ID_POC_SEND_PERSONAL_ALERT_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_send_personal_alert_rsp
 * DESCRIPTION
 *  send alert response handler
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_send_personal_alert_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    poc_send_personal_alert_rsp_struct *msgRsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgRsp = (poc_send_personal_alert_rsp_struct*) info;

    ClearProtocolEventHandler(MSG_ID_POC_SEND_PERSONAL_ALERT_RSP);

    g_poc_cntx_p->progressing.alert = MMI_FALSE;

    if (msgRsp->result == POC_OK)
    {
        if (GetActiveScreenId() == SCR_ID_POC_GENERAL_PROGRESSING)
        {
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_DONE),
                IMG_GLOBAL_ACTIVATED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) SUCCESS_TONE);
        }
    }
    else
    {
        if (GetActiveScreenId() == SCR_ID_POC_GENERAL_PROGRESSING)
        {
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_NOT_DONE),
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
        }
    }
    DeleteScreenIfPresent(SCR_ID_POC_GENERAL_PROGRESSING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_contact_opt_adhoc_talk
 * DESCRIPTION
 *  adhoc talk screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_contact_opt_adhoc_talk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nNumofItem;
    U8 i = 0;
    U8 *guiBuffer;
    mmi_poc_contact_list_disp *cont;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_POC_CONTACT_ADHOC_TALK, NULL, mmi_poc_entry_contact_opt_adhoc_talk, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_POC_CONTACT_ADHOC_TALK);

    nNumofItem = g_poc_cntx_p->contact_num;

    if (nNumofItem > POC_MAX_CONTACT_DISPLAY_NUM)
    {
        nNumofItem = POC_MAX_CONTACT_DISPLAY_NUM;
    }

    for (i = 0; i < nNumofItem; i++)
    {
        cont = &g_poc_cntx_p->contact_list_disp[i];
        subMenuDataPtrs[i] = subMenuData[i];
        memset((S8*) subMenuDataPtrs[i], 0, MAX_SUB_MENU_SIZE);
        if (strlen((S8*) g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].display_name))
        {
            mmi_asc_n_to_ucs2(
                (S8*) subMenuDataPtrs[i],
                (S8*) g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id]. display_name,
                MAX_SUBMENU_CHARACTERS - 1);
        }
        else
        {
            mmi_asc_n_to_ucs2(
                (S8*) subMenuDataPtrs[i],
                (S8*) g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].uri,
                MAX_SUBMENU_CHARACTERS - 1);
        }
    }

    SetParentHandler(MENU_ID_POC_CONTACT_OPT_ADHOC_TALK);

    if (guiBuffer == NULL)
    {
        memset(g_poc_cntx_p->adhoc_sel_disp, 0, sizeof(U8) * POC_MAX_CONTACT_DISPLAY_NUM);
    }

    SetCheckboxToggleRightSoftkeyFunctions(mmi_poc_contact_call_adhoc_cfrm, GoBackHistory);

    ShowCategory140Screen(
        STR_ID_POC_CONTACTS,
        GetRootTitleIcon(MENU_ID_POC_MAIN),
        nNumofItem,
        (U8 **) subMenuDataPtrs,
        g_poc_cntx_p->adhoc_sel_disp,
        0,
        guiBuffer);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_contact_call_adhoc_cfrm
 * DESCRIPTION
 *  adhoc talk confirm screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_contact_call_adhoc_cfrm(void)
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
        get_string(STR_GLOBAL_DIAL),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_poc_contact_call_adhoc, KEY_EVENT_UP);
    SetRightSoftkeyFunction(poc_go_back_entry_opt, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_contact_call_adhoc
 * DESCRIPTION
 *  call adhoc talk
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_contact_call_adhoc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    poc_addr_struct callee[POC_MAX_ADDR_NUM];
    U8 i, total_adhoc_num = 0;
    mmi_poc_contact_list_disp *cont;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(callee, 0, sizeof(callee));

    for (i = 0; i < POC_MAX_CONTACT_DISPLAY_NUM; i++)
    {
        cont = &g_poc_cntx_p->contact_list_disp[i];
        if (g_poc_cntx_p->adhoc_sel_disp[i] == MMI_TRUE)
        {
            if (total_adhoc_num >= POC_MAX_ADDR_NUM)
            {
                DisplayPopup(
                    (U8*) GetString(STR_ID_POC_ERR_MAXIMUM_REACHED),
                    IMG_GLOBAL_UNFINISHED,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    (U8) ERROR_TONE);
                DeleteScreenIfPresent(SCR_ID_POC_CONTACT_ADHOC_TALK);
                return;
            }
            memcpy(
                &callee[total_adhoc_num].uri,
                &g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].uri,
                sizeof(U8) * POC_MAX_URI_LEN);
            total_adhoc_num++;
        }
    }

    if (total_adhoc_num < 2)
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_INVALID),
            IMG_GLOBAL_UNFINISHED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
        DeleteScreenIfPresent(SCR_ID_POC_CONTACT_ADHOC_TALK);
        return;
    }
    memset(g_poc_cntx_p->cm_talk_group_name, 0, sizeof(g_poc_cntx_p->cm_talk_group_name));
    memset(g_poc_cntx_p->cm_talk_list, 0, sizeof(g_poc_cntx_p->cm_talk_list));
    g_poc_cntx_p->cm_talk_list_num = 0;
    memset(&g_poc_cntx_p->calling_disp, 0, sizeof(g_poc_cntx_p->calling_disp));

    mmi_poc_entry_inviting();
    mmi_poc_talk_invite_req(POC_AD_HOC_GROUP_TALK, total_adhoc_num, callee, 0, 0, 0);

}


/*****************************************************************************
 * FUNCTION
 *  poc_go_back_entry_opt
 * DESCRIPTION
 *  go back entry option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void poc_go_back_entry_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stopRequestedTone(WARNING_TONE);
    DeleteScreenIfPresent(SCR_ID_POC_CONTACT_ADHOC_TALK);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_contact_send_refresh_status
 * DESCRIPTION
 *  send refresh status
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_contact_send_refresh_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_poc_contact_list_disp *cont;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cont = &g_poc_cntx_p->contact_list_disp[g_poc_cntx_p->contact_selected];

    if (g_poc_cntx_p->progressing.refresh == MMI_TRUE)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_POC_PROCESSING),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
        return;
    }

    if (g_poc_cntx_p->curr_use_pres_mode == MMI_FALSE)
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_NOT_DONE),
            IMG_GLOBAL_UNFINISHED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
        return;
    }

    mmi_poc_entry_progressing();
    DeleteScreenIfPresent(SCR_ID_POC_CONTACT_OPT);

    g_poc_cntx_p->progressing.refresh = MMI_TRUE;

    mmi_poc_oneshot_pres_subscribe_req(g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].uri);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_oneshot_pres_subscribe_req
 * DESCRIPTION
 *  oneshot presence subscribe request
 * PARAMETERS
 *  uri     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_oneshot_pres_subscribe_req(U8 *uri)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    poc_presence_subscribe_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (poc_presence_subscribe_req_struct*) OslConstructDataPtr(sizeof(poc_presence_subscribe_req_struct));
    memset(
        (U8*) myMsgPtr + sizeof(mmi_poc_dummy_req_struct),
        0,
        sizeof(poc_presence_subscribe_req_struct) - sizeof(mmi_poc_dummy_req_struct));

    myMsgPtr->action = POC_ONESHOT_SUBSCRIBE_ACTION;
    myMsgPtr->use_presence_list = MMI_FALSE;

    memcpy(myMsgPtr->uri, uri, POC_MAX_URI_LEN * sizeof(U8));

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_POC;
    Message.oslMsgId = MSG_ID_POC_PRESENCE_SUBSCRIBE_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

    SetProtocolEventHandler(mmi_poc_oneshot_pres_subscribe_rsp, MSG_ID_POC_PRESENCE_SUBSCRIBE_RSP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_oneshot_pres_subscribe_rsp
 * DESCRIPTION
 *  oneshot presence subscribe response
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_oneshot_pres_subscribe_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    poc_presence_subscribe_rsp_struct *msgRsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgRsp = (poc_presence_subscribe_rsp_struct*) info;

    g_poc_cntx_p->progressing.refresh = MMI_FALSE;

    ClearProtocolEventHandler(MSG_ID_POC_PRESENCE_SUBSCRIBE_RSP);

    if (GetActiveScreenId() == SCR_ID_POC_GENERAL_PROGRESSING)
    {
        if (msgRsp->result == POC_OK)
        {
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_DONE),
                IMG_GLOBAL_ACTIVATED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) SUCCESS_TONE);
        }
        else
        {
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_NOT_DONE),
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
        }
    }
    DeleteScreenIfPresent(SCR_ID_POC_GENERAL_PROGRESSING);
}

////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
//              TALK GROUP Functions    start
////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_talk_groups
 * DESCRIPTION
 *  Talk group entry screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_talk_groups(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_poc_cntx_p->progressing.contact == MMI_TRUE)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_POC_PROCESSING),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
        return;
    }

    EntryNewScreen(SCR_ID_POC_TALK_GROUP, NULL, mmi_poc_entry_talk_groups, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_POC_TALK_GROUP);

    if (g_poc_cntx_p->talk_group_local_updated == MMI_FALSE)
    {
        mmi_poc_sort_talk_group_by_name();
        g_poc_cntx_p->talk_group_local_updated = MMI_TRUE;
    }

    RegisterHighlightHandler(mmi_poc_talk_group_highlight_handler);

    for (i = 0; i < g_poc_cntx_p->talk_group_num; i++)
    {
        subMenuDataPtrs[i] = subMenuData[i];
        memset((S8*) subMenuDataPtrs[i], 0, MAX_SUB_MENU_SIZE);
        if (strlen((S8*) g_poc_cntx_p->talk_group_list[i].display_name))
        {
            mmi_poc_util_copy_with_dot(
                (S8*) g_poc_cntx_p->talk_group_list[i].display_name,
                (S8*) subMenuDataPtrs[i],
                MAX_SUBMENU_CHARACTERS - 1);
        }
        else
        {
            mmi_poc_util_copy_with_dot(
                (S8*) (S8*) g_poc_cntx_p->talk_group_list[i].list_uri,
                (S8*) subMenuDataPtrs[i],
                MAX_SUBMENU_CHARACTERS - 1);
        }
    }

    if (g_poc_cntx_p->talk_group_num == 0)
    {
        subMenuDataPtrs[0] = (U8*) GetString(STR_GLOBAL_EMPTY_LIST);
        ShowCategory6Screen(
            STR_ID_POC_TALK_GROUPS,
            GetRootTitleIcon(MENU_ID_POC_MAIN),
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            1,
            subMenuDataPtrs,
            0,
            0,
            guiBuffer);
        SetLeftSoftkeyFunction(mmi_poc_entry_talk_groups_opt_empty, KEY_EVENT_UP);
    }
    else
    {
        if (guiBuffer != NULL)
        {
            memset((void*)guiBuffer, 0, 2);
            if (g_poc_cntx_p->talk_group_selected >= g_poc_cntx_p->talk_group_num)
            {
                g_poc_cntx_p->talk_group_selected = g_poc_cntx_p->talk_group_num - 1;
            }
        }
        else
        {
            g_poc_cntx_p->talk_group_selected = 0;
        }

        ShowCategory84Screen(
            STR_ID_POC_TALK_GROUPS,
            GetRootTitleIcon(MENU_ID_POC_MAIN),
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            g_poc_cntx_p->talk_group_num,
            subMenuDataPtrs,
            (U16*) gIndexIconsImageList,
            1,
            (S32) g_poc_cntx_p->talk_group_selected,
            guiBuffer);

        SetLeftSoftkeyFunction(mmi_poc_entry_talk_groups_entry, KEY_EVENT_UP);
        SetKeyHandler(mmi_poc_entry_talk_groups_entry, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }

    if (g_poc_cntx_p->talk_group_num > 0)
    {
        SetKeyHandler(mmi_poc_talk_group_invite, KEY_SEND, KEY_EVENT_DOWN);
    }
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_talk_group_highlight_handler
 * DESCRIPTION
 *  Talk group highlight handler
 * PARAMETERS
 *  index       [IN]        Current selected index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_talk_group_highlight_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_poc_cntx_p->talk_group_selected = (U8) index;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_sort_talk_group_by_name
 * DESCRIPTION
 *  sort talk group by name
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_sort_talk_group_by_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, j, k;
    poc_talk_group_struct temp_group;
    poc_talk_group_entry_struct temp_group_entry;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_poc_cntx_p->talk_group_num = 0;
    for (i = 0; i < MAX_POC_TALK_GROUP_FILE_NUM * MAX_POC_TALK_GROUPS_PER_FILE_NUM; i++)
    {
        if (g_poc_cntx_p->talk_group_list[i].valid == MMI_TRUE)
        {
            g_poc_cntx_p->talk_group_num++;
        }
    }

    for (i = 0; i < g_poc_cntx_p->talk_group_num; i++)
    {
        for (j = i + 1; j < g_poc_cntx_p->talk_group_num; j++)
        {
            if (strcmp(
                    (S8*) g_poc_cntx_p->talk_group_list[i].display_name,
                    (S8*) g_poc_cntx_p->talk_group_list[j].display_name) > 0)
            {
                memcpy(&temp_group, &g_poc_cntx_p->talk_group_list[i], sizeof(poc_talk_group_struct));
                memcpy(
                    &g_poc_cntx_p->talk_group_list[i],
                    &g_poc_cntx_p->talk_group_list[j],
                    sizeof(poc_talk_group_struct));
                memcpy(&g_poc_cntx_p->talk_group_list[j], &temp_group, sizeof(poc_talk_group_struct));
            }
        }
    }

    for (i = 0; i < g_poc_cntx_p->talk_group_num; i++)
    {
        for (j = 0; j < g_poc_cntx_p->talk_group_list[i].no_entries; j++)
        {
            for (k = j + 1; k < g_poc_cntx_p->talk_group_list[i].no_entries; k++)
            {
                if (strcmp(
                        (S8*) g_poc_cntx_p->talk_group_list[i].entries[j].uri,
                        (S8*) g_poc_cntx_p->talk_group_list[i].entries[k].uri) > 0)
                {
                    memcpy(
                        &temp_group_entry,
                        &g_poc_cntx_p->talk_group_list[i].entries[j],
                        sizeof(poc_talk_group_entry_struct));
                    memcpy(
                        &g_poc_cntx_p->talk_group_list[i].entries[j],
                        &g_poc_cntx_p->talk_group_list[i].entries[k],
                        sizeof(poc_talk_group_entry_struct));
                    memcpy(
                        &g_poc_cntx_p->talk_group_list[i].entries[k],
                        &temp_group_entry,
                        sizeof(poc_talk_group_entry_struct));
                }
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_talk_groups_opt_empty
 * DESCRIPTION
 *  option for empty talk group
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_talk_groups_opt_empty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];    /* Stores the strings id of submenus returned */
    U16 nNumofItem;                     /* Stores no of children in the submenu */
    U8 *guiBuffer;                      /* Buffer holding history data */
    U16 menuId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_POC_TALK_GROUP_OPT_EMPTY, NULL, mmi_poc_entry_talk_groups_opt_empty, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_POC_TALK_GROUP_OPT_EMPTY);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_POC_TALK_GROUP_OPT_EMPTY);
    menuId = MENU_ID_POC_TALK_GROUPS_OPT_EMPTY;

    nNumofItem = GetNumOfChild(menuId);
    GetSequenceStringIds(menuId, nStrItemList);
    SetParentHandler(menuId);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_ID_POC_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        1,
        0,
        guiBuffer);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_talk_groups_entry
 * DESCRIPTION
 *  talk entry screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_talk_groups_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S8 *icon_list[POC_TALK_GROUP_LOCAL_MAX_ENTRIES_NUM];
    U8 i;
    U8 curr_grp = g_poc_cntx_p->talk_group_selected;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_POC_TALK_GROUP_ENTRY, NULL, mmi_poc_entry_talk_groups_entry, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_POC_TALK_GROUP_ENTRY);

    RegisterHighlightHandler(mmi_poc_talk_group_entry_highlight_handler);

    memset(g_poc_cntx_p->cm_disp, 0, sizeof(g_poc_cntx_p->cm_disp));

    if (strlen((S8*) g_poc_cntx_p->talk_group_list[curr_grp].display_name))
    {
        mmi_asc_n_to_ucs2(
            (S8*) g_poc_cntx_p->cm_disp,
            (S8*) g_poc_cntx_p->talk_group_list[curr_grp].display_name,
            POC_MAX_DISP_LEN - 1);
    }
    else
    {
        mmi_poc_util_copy_with_dot(
            (S8*) g_poc_cntx_p->talk_group_list[curr_grp].list_uri,
            (S8*) g_poc_cntx_p->cm_disp,
            POC_MAX_DISP_LEN - 1);
    }

    for (i = 0; i < g_poc_cntx_p->talk_group_list[curr_grp].no_entries; i++)
    {
        subMenuDataPtrs[i] = subMenuData[i];
        memset((S8*) subMenuDataPtrs[i], 0, MAX_SUB_MENU_SIZE);
        mmi_poc_util_copy_with_dot(
            (S8*) g_poc_cntx_p->talk_group_list[curr_grp].entries[i].uri,
            (S8*) subMenuDataPtrs[i],
            MAX_SUBMENU_CHARACTERS - 1);
    }

    if (g_poc_cntx_p->talk_group_list[curr_grp].no_entries == 0)
    {
        subMenuDataPtrs[0] = (U8*) GetString(STR_GLOBAL_EMPTY_LIST);
        ShowCategory6Screen(
            STR_ID_POC_CONTACTS,
            GetRootTitleIcon(MENU_ID_POC_MAIN),
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            1,
            subMenuDataPtrs,
            NULL,
            0,
            guiBuffer);

        SetLeftSoftkeyFunction(mmi_poc_entry_talk_groups_opt, KEY_EVENT_UP);
        SetKeyHandler(mmi_poc_entry_talk_groups_opt, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
    else
    {
        if (guiBuffer != NULL)
        {
            memset((void*)guiBuffer, 0, 2);
            if (g_poc_cntx_p->talk_entry_selected >= g_poc_cntx_p->talk_group_list[curr_grp].no_entries)
            {
                g_poc_cntx_p->talk_entry_selected = g_poc_cntx_p->talk_group_list[curr_grp].no_entries - 1;
            }
        }
        else
        {
            g_poc_cntx_p->talk_entry_selected = 0;
        }

        for (i = 0; i < g_poc_cntx_p->talk_group_list[curr_grp].no_entries; i++)
        {
            icon_list[i] = GetImage(gIndexIconsImageList[i]);
        }
        ShowCategory174Screen(
            g_poc_cntx_p->cm_disp,
            (PU8) GetImage(GetRootTitleIcon(MENU_ID_POC_MAIN)),
            (PU8) GetString(STR_GLOBAL_OPTIONS),
            (PU8) GetImage(IMG_GLOBAL_OK),
            (PU8) GetString(STR_GLOBAL_BACK),
            (PU8) GetImage(IMG_GLOBAL_BACK),
            g_poc_cntx_p->talk_group_list[curr_grp].no_entries,
            subMenuDataPtrs,
            (PU8*) icon_list,
            0,
            0,
            0,
            guiBuffer);

        SetLeftSoftkeyFunction(mmi_poc_entry_talk_groups_opt, KEY_EVENT_UP);
        SetKeyHandler(mmi_poc_entry_talk_groups_opt, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_talk_group_entry_highlight_handler
 * DESCRIPTION
 *  highlight handler of talk group entry
 * PARAMETERS
 *  index           [IN]        
 *  indes(?)        [IN]        Current selected index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_talk_group_entry_highlight_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_poc_cntx_p->talk_entry_selected = (U8) index;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_talk_groups_opt
 * DESCRIPTION
 *  talk group option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_talk_groups_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];    /* Stores the strings id of submenus returned */
    U16 nNumofItem;                     /* Stores no of children in the submenu */
    U8 *guiBuffer;                      /* Buffer holding history data */
    U16 menuId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_POC_TALK_GROUP_OPT, NULL, mmi_poc_entry_talk_groups_opt, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_POC_TALK_GROUP_OPT);
    menuId = MENU_ID_POC_TALK_GROUPS_OPT;

    nNumofItem = GetNumOfChild(menuId);
    GetSequenceStringIds(menuId, nStrItemList);
    SetParentHandler(menuId);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_ID_POC_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        1,
        0,
        guiBuffer);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_talk_groups_opt_entry_settings
 * DESCRIPTION
 *  setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_talk_groups_opt_entry_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];
    U16 nNumofItem;
    U8 *guiBuffer;
    U16 menuId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_POC_TALK_GROUP_ENTRY_SETTINGS, NULL, mmi_poc_entry_talk_groups_opt_entry_settings, NULL);

    if (g_poc_cntx_p->talk_group_list[g_poc_cntx_p->talk_group_selected].no_entries == 0)
    {
        menuId = MENU_ID_POC_TALK_GROUPS_OPT_ENTRY_SETTINGS_NO_ENTRY;
    }
    else
    {
        menuId = MENU_ID_POC_TALK_GROUPS_OPT_ENTRY_SETTINGS;
    }

    guiBuffer = GetCurrGuiBuffer(SCR_ID_POC_TALK_GROUP_ENTRY_SETTINGS);
    nNumofItem = GetNumOfChild(menuId);
    GetSequenceStringIds(menuId, nStrItemList);
    SetParentHandler(menuId);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ShowCategory15Screen(
        STR_ID_POC_ENTRY_SETTINGS,
        GetRootTitleIcon(MENU_ID_POC_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        1,
        0,
        guiBuffer);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_talk_groups_opt_entry_settings_add
 * DESCRIPTION
 *  add new entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_talk_groups_opt_entry_settings_add(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_poc_cntx_p->talk_entry_info_source = POC_TALK_ENTRY_NEW;
    mmi_poc_entry_talk_groups_opt_entry_settings_add_general();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_talk_groups_opt_entry_settings_add_general
 * DESCRIPTION
 *  add screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_talk_groups_opt_entry_settings_add_general(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, ImageLocation = 0;
    U8 *inputBuffer;
    U8 *guiBuffer;
    U16 inputBufferSize;
    U16 IconList[POC_TALK_GROUP_ENTRY_INLINE_NUM];
    U8 curr_grp = g_poc_cntx_p->talk_group_selected;
    mmi_poc_contact_list_disp *cont;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cont = &g_poc_cntx_p->contact_list_disp[g_poc_cntx_p->contact_selected];

    if (g_poc_cntx_p->talk_group_list[curr_grp].no_entries >= POC_TALK_GROUP_LOCAL_MAX_ENTRIES_NUM)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_POC_ERR_MAXIMUM_REACHED),
            IMG_GLOBAL_UNFINISHED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
        return;
    }

    EntryNewScreen(
        SCR_ID_POC_TALK_GROUP_ENTRY_ADD,
        mmi_poc_exit_talk_groups_opt_entry_settings_add_general,
        NULL,
        NULL);

    InitializeCategory57Screen();
    guiBuffer = GetCurrGuiBuffer(SCR_ID_POC_TALK_GROUP_ENTRY_ADD);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_POC_TALK_GROUP_ENTRY_ADD, &inputBufferSize);
    SetParentHandler(MENU_ID_POC_TALK_GROUPS_OPT_ENTRY_SETTINGS_ADD);

    mmi_poc_talk_entry_fill_inline_struct(XDM_PUT_ADD);

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, POC_TALK_GROUP_ENTRY_INLINE_NUM, inputBuffer);
    }
    else
    {
        if (g_poc_cntx_p->talk_entry_info_source == POC_TALK_ENTRY_FROM_CONTACT)
        {
            memset(&g_poc_cntx_p->talk_entry_disp, 0, sizeof(poc_talk_group_entry_disp_struct));
            memset(&g_poc_cntx_p->talk_entry_disp.group_rule, POC_SETTING_TRUE, sizeof(poc_group_param_struct));
            mmi_asc_n_to_ucs2(
                (S8*) g_poc_cntx_p->talk_entry_disp.uri,
                (S8*) g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].uri,
                POC_MAX_URI_LEN - 1);
            set_wgui_inline_list_menu_changed();
        }
        else
        {
            memset(&g_poc_cntx_p->talk_entry_disp, 0, sizeof(poc_talk_group_entry_disp_struct));
            memset(&g_poc_cntx_p->talk_entry_disp.group_rule, POC_SETTING_TRUE, sizeof(poc_group_param_struct));
            mmi_asc_n_to_ucs2(
                (S8*) g_poc_cntx_p->talk_entry_disp.uri,
                (S8*) POC_MMI_SIP_PREFIX,
                POC_MAX_URI_LEN - 1);
        }
    }

    if (guiBuffer == 0)
    {
        g_poc_cntx_p->inline_item_changed = MMI_FALSE;
    }

    if ((get_wgui_inline_list_menu_status() || g_poc_cntx_p->inline_item_changed) &&
        (GetInlineDoneFlag(guiBuffer) == 0))
    {
        SetInlineDoneFlag(guiBuffer);
    }

    for (i = 0; i < POC_TALK_GROUP_ENTRY_INLINE_NUM; i++)
    {
        if (i % 2)
        {
            IconList[i] = IMG_ID_POC_NOIMAGE;
        }
        else
        {
            IconList[i] = IMG_ID_POC_CONTACT_URI + ImageLocation;
            ImageLocation++;
        }
    }

    ShowCategory57Screen(
        STR_ID_POC_ENTRY_INFO,
        GetRootTitleIcon(MENU_ID_POC_MAIN),
        STR_GLOBAL_EDIT,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        POC_TALK_GROUP_ENTRY_INLINE_NUM,
        IconList,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_poc_entry_talk_group_opt_settings_add_cfrm, GoBackHistory);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_exit_talk_groups_opt_entry_settings_add_general
 * DESCRIPTION
 *  exit function for add general screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_exit_talk_groups_opt_entry_settings_add_general(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_leading_zero(TRUE);
    GenericExitInlineScreen(SCR_ID_POC_TALK_GROUP_ENTRY_ADD, mmi_poc_entry_talk_groups_opt_entry_settings_add_general);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_talk_entry_fill_inline_struct
 * DESCRIPTION
 *  fill inline structure
 * PARAMETERS
 *  op      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_talk_entry_fill_inline_struct(U8 op)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 BufferSize = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetInlineItemActivation((wgui_inline_items + POC_TALK_GROUP_ENTRY_URI), KEY_LSK, KEY_EVENT_UP);
    SetInlineItemActivation((wgui_inline_items + POC_TALK_GROUP_ENTRY_ATTR), KEY_LSK, KEY_EVENT_UP);

    SetInlineItemCaption((wgui_inline_items + POC_TALK_GROUP_ENTRY_URI_STR), (U8*) GetString(STR_ID_POC_URI));
    SetInlineItemCaption((wgui_inline_items + POC_TALK_GROUP_ENTRY_ATTR_STR), (U8*) GetString(STR_ID_POC_ATTRIBUTES));

    if (op == XDM_PUT_ADD)
    {
        BufferSize = POC_MAX_URI_LEN - 1;

        SetInlineItemFullScreenEdit_ext(
            (wgui_inline_items + POC_TALK_GROUP_ENTRY_URI),
            STR_ID_POC_URI,
            GetRootTitleIcon(MENU_ID_POC_MAIN),
            (U8*) (g_poc_cntx_p->talk_entry_disp.uri),
            BufferSize,
            (INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES),
            INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);

        SetInlineFullScreenEditCustomFunction(
            wgui_inline_items + POC_TALK_GROUP_ENTRY_URI,
            mmi_poc_entry_full_line_edit);
    }
    else
    {
        SetInlineItemDisplayOnly(
            (wgui_inline_items + POC_TALK_GROUP_ENTRY_URI),
            (U8*) (g_poc_cntx_p->talk_entry_disp.uri));
    }

    SetInlineItemImageText(
        (wgui_inline_items + POC_TALK_GROUP_ENTRY_ATTR),
        (U8*) GetString(STR_ID_POC_SET_ATTR),
        0,
        0,
        0,
        POC_MAX_DISP_LEN,
        0,
        0,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE);
    SetInlineFullScreenEditCustomFunctionImageText(
        (wgui_inline_items + POC_TALK_GROUP_ENTRY_ATTR),
        mmi_poc_entry_talk_groups_opt_entry_attr);
    ShowAsControl(wgui_inline_items + POC_TALK_GROUP_ENTRY_ATTR);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_talk_groups_opt_entry_attr
 * DESCRIPTION
 *  entry attribute screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_talk_groups_opt_entry_attr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];
    U16 nNumofItem;
    U8 *guiBuffer;
    U16 menuId;
    U8 *PoCHint[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_POC_TALK_GROUP_ENTRY_ATTR, NULL, mmi_poc_entry_talk_groups_opt_entry_attr, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_POC_TALK_GROUP_ENTRY_ATTR);
    menuId = MENU_ID_POC_TALK_GROUPS_OPT_ENTRY_SETTINGS_ENTRY_ATTRIBUTES;

    nNumofItem = GetNumOfChild(menuId);
    GetSequenceStringIds(menuId, nStrItemList);
    SetParentHandler(menuId);
    ConstructHintsList(menuId, PoCHint);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ShowCategory52Screen(
        STR_ID_POC_ATTRIBUTES,
        GetRootTitleIcon(MENU_ID_POC_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        PoCHint,
        0,
        0,
        guiBuffer);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_talk_group_set_conf_state
 * DESCRIPTION
 *  change settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_talk_group_set_conf_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_poc_cntx_p->talk_entry_disp.group_rule.allow_conference_state)
    {
        case POC_SETTING_TRUE:
            g_poc_cntx_p->talk_entry_disp.group_rule.allow_conference_state = POC_SETTING_FALSE;
            break;
        case POC_SETTING_FALSE:
            g_poc_cntx_p->talk_entry_disp.group_rule.allow_conference_state = POC_SETTING_TRUE;
            break;
        default:
            g_poc_cntx_p->talk_entry_disp.group_rule.allow_conference_state = POC_SETTING_TRUE;
            break;
    }
    DisplayPopup(
        (U8*) GetString(STR_GLOBAL_DONE),
        IMG_GLOBAL_ACTIVATED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) SUCCESS_TONE);
    g_poc_cntx_p->inline_item_changed = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_talk_group_set_invite_user_dyna
 * DESCRIPTION
 *  change settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_talk_group_set_invite_user_dyna(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_poc_cntx_p->talk_entry_disp.group_rule.allow_invite_user_dynamically)
    {
        case POC_SETTING_TRUE:
            g_poc_cntx_p->talk_entry_disp.group_rule.allow_invite_user_dynamically = POC_SETTING_FALSE;
            break;
        case POC_SETTING_FALSE:
            g_poc_cntx_p->talk_entry_disp.group_rule.allow_invite_user_dynamically = POC_SETTING_TRUE;
            break;
        default:
            g_poc_cntx_p->talk_entry_disp.group_rule.allow_invite_user_dynamically = POC_SETTING_TRUE;
            break;
    }
    DisplayPopup(
        (U8*) GetString(STR_GLOBAL_DONE),
        IMG_GLOBAL_ACTIVATED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) SUCCESS_TONE);
    g_poc_cntx_p->inline_item_changed = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_talk_group_set_join_handling
 * DESCRIPTION
 *  change settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_talk_group_set_join_handling(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_poc_cntx_p->talk_entry_disp.group_rule.join_handling)
    {
        case POC_SETTING_TRUE:
            g_poc_cntx_p->talk_entry_disp.group_rule.join_handling = POC_SETTING_FALSE;
            break;
        case POC_SETTING_FALSE:
            g_poc_cntx_p->talk_entry_disp.group_rule.join_handling = POC_SETTING_TRUE;
            break;
        default:
            g_poc_cntx_p->talk_entry_disp.group_rule.join_handling = POC_SETTING_TRUE;
            break;
    }
    DisplayPopup(
        (U8*) GetString(STR_GLOBAL_DONE),
        IMG_GLOBAL_ACTIVATED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) SUCCESS_TONE);
    g_poc_cntx_p->inline_item_changed = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_talk_group_set_init_conf
 * DESCRIPTION
 *  change settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_talk_group_set_init_conf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_poc_cntx_p->talk_entry_disp.group_rule.allow_initiate_conference)
    {
        case POC_SETTING_TRUE:
            g_poc_cntx_p->talk_entry_disp.group_rule.allow_initiate_conference = POC_SETTING_FALSE;
            break;
        case POC_SETTING_FALSE:
            g_poc_cntx_p->talk_entry_disp.group_rule.allow_initiate_conference = POC_SETTING_TRUE;
            break;
        default:
            g_poc_cntx_p->talk_entry_disp.group_rule.allow_initiate_conference = POC_SETTING_TRUE;
            break;
    }
    DisplayPopup(
        (U8*) GetString(STR_GLOBAL_DONE),
        IMG_GLOBAL_ACTIVATED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) SUCCESS_TONE);
    g_poc_cntx_p->inline_item_changed = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_talk_group_set_anonymity
 * DESCRIPTION
 *  change settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_talk_group_set_anonymity(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_poc_cntx_p->talk_entry_disp.group_rule.allow_anonymity)
    {
        case POC_SETTING_TRUE:
            g_poc_cntx_p->talk_entry_disp.group_rule.allow_anonymity = POC_SETTING_FALSE;
            break;
        case POC_SETTING_FALSE:
            g_poc_cntx_p->talk_entry_disp.group_rule.allow_anonymity = POC_SETTING_TRUE;
            break;
        default:
            g_poc_cntx_p->talk_entry_disp.group_rule.allow_anonymity = POC_SETTING_TRUE;
            break;
    }
    DisplayPopup(
        (U8*) GetString(STR_GLOBAL_DONE),
        IMG_GLOBAL_ACTIVATED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) SUCCESS_TONE);
    g_poc_cntx_p->inline_item_changed = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_talk_group_set_default_conf_state
 * DESCRIPTION
 *  change settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_talk_group_set_default_conf_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_poc_cntx_p->talk_group_disp.default_rule.allow_conference_state)
    {
        case POC_SETTING_TRUE:
            g_poc_cntx_p->talk_group_disp.default_rule.allow_conference_state = POC_SETTING_FALSE;
            break;
        case POC_SETTING_FALSE:
            g_poc_cntx_p->talk_group_disp.default_rule.allow_conference_state = POC_SETTING_TRUE;
            break;
        default:
            g_poc_cntx_p->talk_group_disp.default_rule.allow_conference_state = POC_SETTING_TRUE;
            break;
    }
    DisplayPopup(
        (U8*) GetString(STR_GLOBAL_DONE),
        IMG_GLOBAL_ACTIVATED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) SUCCESS_TONE);
    g_poc_cntx_p->inline_item_changed = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_talk_group_set_default_invite_user_dyna
 * DESCRIPTION
 *  change settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_talk_group_set_default_invite_user_dyna(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_poc_cntx_p->talk_group_disp.default_rule.allow_invite_user_dynamically)
    {
        case POC_SETTING_TRUE:
            g_poc_cntx_p->talk_group_disp.default_rule.allow_invite_user_dynamically = POC_SETTING_FALSE;
            break;
        case POC_SETTING_FALSE:
            g_poc_cntx_p->talk_group_disp.default_rule.allow_invite_user_dynamically = POC_SETTING_TRUE;
            break;
        default:
            g_poc_cntx_p->talk_group_disp.default_rule.allow_invite_user_dynamically = POC_SETTING_TRUE;
            break;
    }
    DisplayPopup(
        (U8*) GetString(STR_GLOBAL_DONE),
        IMG_GLOBAL_ACTIVATED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) SUCCESS_TONE);
    g_poc_cntx_p->inline_item_changed = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_talk_group_set_default_join_handling
 * DESCRIPTION
 *  change settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_talk_group_set_default_join_handling(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_poc_cntx_p->talk_group_disp.default_rule.join_handling)
    {
        case POC_SETTING_TRUE:
            g_poc_cntx_p->talk_group_disp.default_rule.join_handling = POC_SETTING_FALSE;
            break;
        case POC_SETTING_FALSE:
            g_poc_cntx_p->talk_group_disp.default_rule.join_handling = POC_SETTING_TRUE;
            break;
        default:
            g_poc_cntx_p->talk_group_disp.default_rule.join_handling = POC_SETTING_TRUE;
            break;
    }
    DisplayPopup(
        (U8*) GetString(STR_GLOBAL_DONE),
        IMG_GLOBAL_ACTIVATED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) SUCCESS_TONE);
    g_poc_cntx_p->inline_item_changed = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_talk_group_set_default_init_conf
 * DESCRIPTION
 *  change settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_talk_group_set_default_init_conf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_poc_cntx_p->talk_group_disp.default_rule.allow_initiate_conference)
    {
        case POC_SETTING_TRUE:
            g_poc_cntx_p->talk_group_disp.default_rule.allow_initiate_conference = POC_SETTING_FALSE;
            break;
        case POC_SETTING_FALSE:
            g_poc_cntx_p->talk_group_disp.default_rule.allow_initiate_conference = POC_SETTING_TRUE;
            break;
        default:
            g_poc_cntx_p->talk_group_disp.default_rule.allow_initiate_conference = POC_SETTING_TRUE;
            break;
    }
    DisplayPopup(
        (U8*) GetString(STR_GLOBAL_DONE),
        IMG_GLOBAL_ACTIVATED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) SUCCESS_TONE);
    g_poc_cntx_p->inline_item_changed = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_talk_group_set_default_anonymity
 * DESCRIPTION
 *  change settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_talk_group_set_default_anonymity(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_poc_cntx_p->talk_group_disp.default_rule.allow_anonymity)
    {
        case POC_SETTING_TRUE:
            g_poc_cntx_p->talk_group_disp.default_rule.allow_anonymity = POC_SETTING_FALSE;
            break;
        case POC_SETTING_FALSE:
            g_poc_cntx_p->talk_group_disp.default_rule.allow_anonymity = POC_SETTING_TRUE;
            break;
        default:
            g_poc_cntx_p->talk_group_disp.default_rule.allow_anonymity = POC_SETTING_TRUE;
            break;
    }
    DisplayPopup(
        (U8*) GetString(STR_GLOBAL_DONE),
        IMG_GLOBAL_ACTIVATED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) SUCCESS_TONE);
    g_poc_cntx_p->inline_item_changed = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_hint_talk_group_entry_conf_state
 * DESCRIPTION
 *  Hint handler of PoC menu
 * PARAMETERS
 *  index       [IN]        Current selected index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_hint_talk_group_entry_conf_state(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    poc_group_param_struct *grule;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    grule = &g_poc_cntx_p->talk_entry_disp.group_rule;

    memset((S8*) hintData[(index)], 0, MAX_SUB_MENU_SIZE);

    switch (grule->allow_conference_state)
    {
        case POC_SETTING_TRUE:
            mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_ON));
            break;
        case POC_SETTING_FALSE:
            mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_OFF));
            break;
        case POC_SETTING_NA:
            mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_EMPTY));
            break;
        default:
            mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_EMPTY));
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_hint_talk_group_entry_invite_user_dyna
 * DESCRIPTION
 *  Hint handler of PoC menu
 * PARAMETERS
 *  index       [IN]        Current selected index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_hint_talk_group_entry_invite_user_dyna(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    poc_group_param_struct *grule;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    grule = &g_poc_cntx_p->talk_entry_disp.group_rule;

    memset((S8*) hintData[(index)], 0, MAX_SUB_MENU_SIZE);

    switch (grule->allow_invite_user_dynamically)
    {
        case POC_SETTING_TRUE:
            mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_ON));
            break;
        case POC_SETTING_FALSE:
            mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_OFF));
            break;
        case POC_SETTING_NA:
            mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_EMPTY));
            break;
        default:
            mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_EMPTY));
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_hint_talk_group_entry_join_handling
 * DESCRIPTION
 *  Hint handler of PoC menu
 * PARAMETERS
 *  index       [IN]        Current selected index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_hint_talk_group_entry_join_handling(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    poc_group_param_struct *grule;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    grule = &g_poc_cntx_p->talk_entry_disp.group_rule;

    memset((S8*) hintData[(index)], 0, MAX_SUB_MENU_SIZE);

    switch (grule->join_handling)
    {
        case POC_SETTING_TRUE:
            mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_ON));
            break;
        case POC_SETTING_FALSE:
            mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_OFF));
            break;
        case POC_SETTING_NA:
            mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_EMPTY));
            break;
        default:
            mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_EMPTY));
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_hint_talk_group_entry_init_conf
 * DESCRIPTION
 *  Hint handler of PoC menu
 * PARAMETERS
 *  index       [IN]        Current selected index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_hint_talk_group_entry_init_conf(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    poc_group_param_struct *grule;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    grule = &g_poc_cntx_p->talk_entry_disp.group_rule;

    memset((S8*) hintData[(index)], 0, MAX_SUB_MENU_SIZE);

    switch (grule->allow_initiate_conference)
    {
        case POC_SETTING_TRUE:
            mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_ON));
            break;
        case POC_SETTING_FALSE:
            mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_OFF));
            break;
        case POC_SETTING_NA:
            mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_EMPTY));
            break;
        default:
            mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_EMPTY));
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_hint_talk_group_entry_anonymity
 * DESCRIPTION
 *  Hint handler of PoC menu
 * PARAMETERS
 *  index       [IN]        Current selected index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_hint_talk_group_entry_anonymity(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    poc_group_param_struct *grule;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    grule = &g_poc_cntx_p->talk_entry_disp.group_rule;

    memset((S8*) hintData[(index)], 0, MAX_SUB_MENU_SIZE);

    switch (grule->allow_anonymity)
    {
        case POC_SETTING_TRUE:
            mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_ON));
            break;
        case POC_SETTING_FALSE:
            mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_OFF));
            break;
        case POC_SETTING_NA:
            mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_EMPTY));
            break;
        default:
            mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_EMPTY));
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_hint_talk_group_conf_state
 * DESCRIPTION
 *  Hint handler of PoC menu
 * PARAMETERS
 *  index       [IN]        Current selected index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_hint_talk_group_conf_state(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    poc_group_param_struct *grule;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    grule = &g_poc_cntx_p->talk_group_disp.default_rule;

    memset((S8*) hintData[(index)], 0, MAX_SUB_MENU_SIZE);

    switch (grule->allow_conference_state)
    {
        case POC_SETTING_TRUE:
            mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_ON));
            break;
        case POC_SETTING_FALSE:
            mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_OFF));
            break;
        case POC_SETTING_NA:
            mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_EMPTY));
            break;
        default:
            mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_EMPTY));
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_hint_talk_group_invite_user_dyna
 * DESCRIPTION
 *  Hint handler of PoC menu
 * PARAMETERS
 *  index       [IN]        Current selected index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_hint_talk_group_invite_user_dyna(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    poc_group_param_struct *grule;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    grule = &g_poc_cntx_p->talk_group_disp.default_rule;

    memset((S8*) hintData[(index)], 0, MAX_SUB_MENU_SIZE);

    switch (grule->allow_invite_user_dynamically)
    {
        case POC_SETTING_TRUE:
            mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_ON));
            break;
        case POC_SETTING_FALSE:
            mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_OFF));
            break;
        case POC_SETTING_NA:
            mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_EMPTY));
            break;
        default:
            mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_EMPTY));
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_hint_talk_group_join_handling
 * DESCRIPTION
 *  Hint handler of PoC menu
 * PARAMETERS
 *  index       [IN]        Current selected index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_hint_talk_group_join_handling(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    poc_group_param_struct *grule;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    grule = &g_poc_cntx_p->talk_group_disp.default_rule;

    memset((S8*) hintData[(index)], 0, MAX_SUB_MENU_SIZE);

    switch (grule->join_handling)
    {
        case POC_SETTING_TRUE:
            mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_ON));
            break;
        case POC_SETTING_FALSE:
            mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_OFF));
            break;
        case POC_SETTING_NA:
            mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_EMPTY));
            break;
        default:
            mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_EMPTY));
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_hint_talk_group_init_conf
 * DESCRIPTION
 *  Hint handler of PoC menu
 * PARAMETERS
 *  index       [IN]        Current selected index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_hint_talk_group_init_conf(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    poc_group_param_struct *grule;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    grule = &g_poc_cntx_p->talk_group_disp.default_rule;

    memset((S8*) hintData[(index)], 0, MAX_SUB_MENU_SIZE);

    switch (grule->allow_initiate_conference)
    {
        case POC_SETTING_TRUE:
            mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_ON));
            break;
        case POC_SETTING_FALSE:
            mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_OFF));
            break;
        case POC_SETTING_NA:
            mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_EMPTY));
            break;
        default:
            mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_EMPTY));
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_hint_talk_group_anonymity
 * DESCRIPTION
 *  Hint handler of PoC menu
 * PARAMETERS
 *  index       [IN]        Current selected index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_hint_talk_group_anonymity(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    poc_group_param_struct *grule;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    grule = &g_poc_cntx_p->talk_group_disp.default_rule;

    memset((S8*) hintData[(index)], 0, MAX_SUB_MENU_SIZE);

    switch (grule->allow_anonymity)
    {
        case POC_SETTING_TRUE:
            mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_ON));
            break;
        case POC_SETTING_FALSE:
            mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_OFF));
            break;
        case POC_SETTING_NA:
            mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_EMPTY));
            break;
        default:
            mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_EMPTY));
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_talk_group_opt_settings_add_cfrm
 * DESCRIPTION
 *  add confirm screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_talk_group_opt_settings_add_cfrm(void)
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

    SetLeftSoftkeyFunction(mmi_poc_talk_group_entry_send_add, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_poc_go_back_talk_group_list, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_talk_group_entry_send_add
 * DESCRIPTION
 *  send add
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_talk_group_entry_send_add(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_poc_cntx_p->curr_talk_group_op = XDM_PUT_ADD;
    mmi_poc_update_talk_group_entry_req(XDM_PUT_ADD);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_go_back_talk_group_entry_list
 * DESCRIPTION
 *  go back entry list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_go_back_talk_group_entry_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stopRequestedTone(WARNING_TONE);
    DeleteUptoScrID(SCR_ID_POC_TALK_GROUP_ENTRY);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_go_back_talk_group_list
 * DESCRIPTION
 *  go back talk group list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_go_back_talk_group_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stopRequestedTone(WARNING_TONE);
    DeleteUptoScrID(SCR_ID_POC_TALK_GROUP);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_update_talk_group_entry_req
 * DESCRIPTION
 *  update talk group entry request
 * PARAMETERS
 *  op      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_update_talk_group_entry_req(U8 op)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    poc_update_talk_group_entry_req_struct *myMsgPtr;
    U8 new_idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_poc_cntx_p->curr_use_xdm_mode == MMI_TRUE)
    {

        myMsgPtr =
            (poc_update_talk_group_entry_req_struct*)
            OslConstructDataPtr(sizeof(poc_update_talk_group_entry_req_struct));
        memset(
            (U8*) myMsgPtr + sizeof(mmi_poc_dummy_req_struct),
            0,
            sizeof(poc_update_talk_group_entry_req_struct) - sizeof(mmi_poc_dummy_req_struct));

        myMsgPtr->request_id = POC_REQUEST_ID;
        myMsgPtr->op = op;
        strncpy(
            (char*)myMsgPtr->list_uri,
            (char*)g_poc_cntx_p->talk_group_list[g_poc_cntx_p->talk_group_selected].list_uri,
            POC_MAX_URI_LEN - 1);

        memcpy(&myMsgPtr->entry.group_rule, &g_poc_cntx_p->talk_entry_disp.group_rule, sizeof(poc_group_param_struct));

        mmi_ucs2_n_to_asc((S8*) myMsgPtr->entry.uri, (S8*) g_poc_cntx_p->talk_entry_disp.uri, POC_MAX_URI_LEN - 1);

        if (myMsgPtr->entry.uri[0] == 0 || !strstr((S8*) myMsgPtr->entry.uri, (S8*) "@"))
        {
            DisplayPopup(
                (PU8) GetString(STR_ID_POC_NULL_STR_ERR),
                IMG_GLOBAL_UNFINISHED,
                1,
                CS_NOTIFYDURATION,
                ERROR_TONE);
            DeleteScreenIfPresent(SCR_ID_POC_GENERAL_PROGRESSING);
            OslFreeDataPtr((void*)myMsgPtr);
            return;
        }

        SetProtocolEventHandler(mmi_poc_update_talk_group_entry_rsp, MSG_ID_POC_UPDATE_TALK_GROUP_ENTRY_RSP);

        g_poc_cntx_p->progressing.contact = MMI_TRUE;
        mmi_poc_entry_progressing();
        DeleteUptoScrID(SCR_ID_POC_TALK_GROUP);
        DeleteScreenIfPresent(SCR_ID_POC_TALK_GROUP);

        Message.oslSrcId = MOD_MMI;
        Message.oslDestId = MOD_POC;
        Message.oslMsgId = MSG_ID_POC_UPDATE_TALK_GROUP_ENTRY_REQ;
        Message.oslDataPtr = (oslParaType*) myMsgPtr;
        Message.oslPeerBuffPtr = NULL;
        OslMsgSendExtQueue(&Message);
    }
    else
    {
        mmi_poc_entry_progressing();
        DeleteUptoScrID(SCR_ID_POC_TALK_GROUP);
        DeleteScreenIfPresent(SCR_ID_POC_TALK_GROUP);
        g_poc_cntx_p->progressing.contact = MMI_FALSE;
        if (GetActiveScreenId() == SCR_ID_POC_GENERAL_PROGRESSING)
        {
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_DONE),
                IMG_GLOBAL_ACTIVATED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) SUCCESS_TONE);
        }
        DeleteScreenIfPresent(SCR_ID_POC_GENERAL_PROGRESSING);

        if (g_poc_cntx_p->curr_talk_group_op == XDM_PUT_REPLACE)
        {

            memcpy(
                &g_poc_cntx_p->talk_group_list[g_poc_cntx_p->talk_group_selected]. entries[g_poc_cntx_p->talk_entry_selected].group_rule,
                &g_poc_cntx_p->talk_entry_disp.group_rule,
                sizeof(poc_group_param_struct));
            memset(
                g_poc_cntx_p->talk_group_list[g_poc_cntx_p->talk_group_selected]. entries[g_poc_cntx_p->talk_entry_selected].uri,
                0,
                sizeof(g_poc_cntx_p->talk_group_list[g_poc_cntx_p->talk_group_selected]. entries[g_poc_cntx_p->talk_entry_selected].uri));
            mmi_ucs2_n_to_asc(
                (S8*) g_poc_cntx_p->talk_group_list[g_poc_cntx_p->talk_group_selected]. entries[g_poc_cntx_p->talk_entry_selected].uri,
                (S8*) g_poc_cntx_p->talk_entry_disp.uri,
                (U32) POC_MAX_URI_LEN - 1);
        }
        else
        {
            new_idx = g_poc_cntx_p->talk_group_list[g_poc_cntx_p->talk_group_selected].no_entries;
            memset(
                g_poc_cntx_p->talk_group_list[g_poc_cntx_p->talk_group_selected].entries[new_idx].uri,
                0,
                sizeof(g_poc_cntx_p->talk_group_list[g_poc_cntx_p->talk_group_selected].entries[new_idx].uri));
            mmi_ucs2_n_to_asc(
                (S8*) g_poc_cntx_p->talk_group_list[g_poc_cntx_p->talk_group_selected].entries[new_idx]. uri,
                (S8*) g_poc_cntx_p->talk_entry_disp.uri,
                (U32) POC_MAX_URI_LEN - 1);
            memcpy(
                &g_poc_cntx_p->talk_group_list[g_poc_cntx_p->talk_group_selected].entries[new_idx].group_rule,
                &g_poc_cntx_p->talk_entry_disp.group_rule,
                sizeof(poc_group_param_struct));

            g_poc_cntx_p->talk_group_list[g_poc_cntx_p->talk_group_selected].no_entries++;
        }
        g_poc_cntx_p->talk_group_local_updated = MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_update_talk_group_entry_rsp
 * DESCRIPTION
 *  update talk group entry response handler
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_update_talk_group_entry_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    poc_update_talk_group_entry_rsp_struct *msgRsp;
    U8 new_idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgRsp = (poc_update_talk_group_entry_rsp_struct*) info;

    ClearProtocolEventHandler(MSG_ID_POC_UPDATE_TALK_GROUP_ENTRY_RSP);

    g_poc_cntx_p->progressing.contact = MMI_FALSE;

    if (msgRsp->result == POC_OK)
    {
        if (GetActiveScreenId() == SCR_ID_POC_GENERAL_PROGRESSING)
        {
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_DONE),
                IMG_GLOBAL_ACTIVATED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) SUCCESS_TONE);
        }
        DeleteScreenIfPresent(SCR_ID_POC_GENERAL_PROGRESSING);

        if (g_poc_cntx_p->curr_talk_group_op == XDM_PUT_REPLACE)
        {

            memcpy(
                &g_poc_cntx_p->talk_group_list[g_poc_cntx_p->talk_group_selected]. entries[g_poc_cntx_p->talk_entry_selected].group_rule,
                &g_poc_cntx_p->talk_entry_disp.group_rule,
                sizeof(poc_group_param_struct));
            memset(
                g_poc_cntx_p->talk_group_list[g_poc_cntx_p->talk_group_selected]. entries[g_poc_cntx_p->talk_entry_selected].uri,
                0,
                sizeof(g_poc_cntx_p->talk_group_list[g_poc_cntx_p->talk_group_selected]. entries[g_poc_cntx_p->talk_entry_selected].uri));
            mmi_ucs2_n_to_asc(
                (S8*) g_poc_cntx_p->talk_group_list[g_poc_cntx_p->talk_group_selected]. entries[g_poc_cntx_p->talk_entry_selected].uri,
                (S8*) g_poc_cntx_p->talk_entry_disp.uri,
                (U32) POC_MAX_URI_LEN - 1);
        }
        else
        {
            new_idx = g_poc_cntx_p->talk_group_list[g_poc_cntx_p->talk_group_selected].no_entries;
            memset(
                g_poc_cntx_p->talk_group_list[g_poc_cntx_p->talk_group_selected].entries[new_idx].uri,
                0,
                sizeof(g_poc_cntx_p->talk_group_list[g_poc_cntx_p->talk_group_selected].entries[new_idx].uri));
            mmi_ucs2_n_to_asc(
                (S8*) g_poc_cntx_p->talk_group_list[g_poc_cntx_p->talk_group_selected].entries[new_idx]. uri,
                (S8*) g_poc_cntx_p->talk_entry_disp.uri,
                (U32) POC_MAX_URI_LEN - 1);
            memcpy(
                &g_poc_cntx_p->talk_group_list[g_poc_cntx_p->talk_group_selected].entries[new_idx].group_rule,
                &g_poc_cntx_p->talk_entry_disp.group_rule,
                sizeof(poc_group_param_struct));

            g_poc_cntx_p->talk_group_list[g_poc_cntx_p->talk_group_selected].no_entries++;
        }
        g_poc_cntx_p->talk_group_local_updated = MMI_FALSE;
    }
    else
    {
        if (GetActiveScreenId() == SCR_ID_POC_GENERAL_PROGRESSING)
        {
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_NOT_DONE),
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
        }
        DeleteScreenIfPresent(SCR_ID_POC_GENERAL_PROGRESSING);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_talk_groups_opt_entry_settings_entry_info
 * DESCRIPTION
 *  entry info entry screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_talk_groups_opt_entry_settings_entry_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, ImageLocation = 0;
    U8 *inputBuffer;
    U8 *guiBuffer;
    U16 inputBufferSize;
    U16 IconList[POC_TALK_GROUP_ENTRY_INLINE_NUM];
    U8 curr_grp = g_poc_cntx_p->talk_group_selected;
    U8 curr_entry = g_poc_cntx_p->talk_entry_selected;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(
        SCR_ID_POC_TALK_GROUP_ENTRY_INFO,
        mmi_poc_exit_talk_groups_opt_entry_settings_entry_info,
        NULL,
        NULL);

    InitializeCategory57Screen();
    guiBuffer = GetCurrGuiBuffer(SCR_ID_POC_TALK_GROUP_ENTRY_INFO);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_POC_TALK_GROUP_ENTRY_INFO, &inputBufferSize);
    SetParentHandler(MENU_ID_POC_TALK_GROUPS_OPT_ENTRY_SETTINGS_ENTRY_INFO);

    mmi_poc_talk_entry_fill_inline_struct(XDM_PUT_REPLACE);

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, POC_TALK_GROUP_ENTRY_INLINE_NUM, inputBuffer);
    }
    else
    {
        memcpy(
            &g_poc_cntx_p->talk_entry_disp.group_rule,
            &g_poc_cntx_p->talk_group_list[curr_grp].entries[curr_entry].group_rule,
            sizeof(poc_group_param_struct));
        if (strlen((S8*) g_poc_cntx_p->talk_group_list[curr_grp].entries[curr_entry].uri))
        {
            mmi_asc_n_to_ucs2(
                (S8*) g_poc_cntx_p->talk_entry_disp.uri,
                (S8*) g_poc_cntx_p->talk_group_list[curr_grp].entries[curr_entry].uri,
                POC_MAX_URI_LEN - 1);
        }
        else
        {
            mmi_asc_n_to_ucs2(
                (S8*) g_poc_cntx_p->talk_entry_disp.uri,
                (S8*) POC_MMI_SIP_PREFIX,
                POC_MAX_URI_LEN - 1);
        }
    }

    if (guiBuffer == 0)
    {
        g_poc_cntx_p->inline_item_changed = MMI_FALSE;
    }

    if ((get_wgui_inline_list_menu_status() || g_poc_cntx_p->inline_item_changed) &&
        (GetInlineDoneFlag(guiBuffer) == 0))
    {
        SetInlineDoneFlag(guiBuffer);
    }

    for (i = 0; i < POC_TALK_GROUP_ENTRY_INLINE_NUM; i++)
    {
        if (i % 2)
        {
            IconList[i] = IMG_ID_POC_NOIMAGE;
        }
        else
        {
            IconList[i] = IMG_ID_POC_CONTACT_URI + ImageLocation;
            ImageLocation++;
        }
    }

    ShowCategory57Screen(
        STR_ID_POC_ENTRY_INFO,
        GetRootTitleIcon(MENU_ID_POC_MAIN),
        STR_GLOBAL_EDIT,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        POC_TALK_GROUP_ENTRY_INLINE_NUM,
        IconList,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_poc_entry_talk_group_entry_info_cfrm, GoBackHistory);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_exit_talk_groups_opt_entry_settings_entry_info
 * DESCRIPTION
 *  entry info exit function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_exit_talk_groups_opt_entry_settings_entry_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_leading_zero(TRUE);
    GenericExitInlineScreen(SCR_ID_POC_TALK_GROUP_ENTRY_INFO, mmi_poc_entry_talk_groups_opt_entry_settings_entry_info);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_talk_group_entry_info_cfrm
 * DESCRIPTION
 *  change confirm screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_talk_group_entry_info_cfrm(void)
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

    SetLeftSoftkeyFunction(mmi_poc_talk_group_entry_send_modify, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_poc_go_back_talk_group_entry_list, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_talk_group_entry_send_modify
 * DESCRIPTION
 *  send entry modify
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_talk_group_entry_send_modify(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_poc_cntx_p->curr_talk_group_op = XDM_PUT_REPLACE;
    mmi_poc_update_talk_group_entry_req(XDM_PUT_REPLACE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_talk_groups_opt_entry_settings_add_from_contact
 * DESCRIPTION
 *  add from contact screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_talk_groups_opt_entry_settings_add_from_contact(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 curr_grp = g_poc_cntx_p->talk_group_selected;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_poc_cntx_p->talk_group_list[curr_grp].no_entries >= POC_TALK_GROUP_LOCAL_MAX_ENTRIES_NUM)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_POC_ERR_MAXIMUM_REACHED),
            IMG_GLOBAL_UNFINISHED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
        return;
    }

    mmi_poc_check_and_update_contact();

    if (g_poc_cntx_p->contact_num == 0)
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_EMPTY),
            IMG_GLOBAL_EMPTY,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
        return;
    }

    EntryNewScreen(
        SCR_ID_POC_TALK_GROUP_ENTRY_FROM_CONTACT,
        NULL,
        mmi_poc_entry_talk_groups_opt_entry_settings_add_from_contact,
        NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_POC_TALK_GROUP_ENTRY_FROM_CONTACT);

    RegisterHighlightHandler(mmi_poc_talk_groups_add_from_contact_highlight_hdlr);

    ShowCategory184Screen(
        STR_ID_POC_CONTACTS,
        GetRootTitleIcon(MENU_ID_POC_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        g_poc_cntx_p->contact_num,
        mmi_poc_add_talk_entry_contact_name,
        mmi_poc_add_talk_entry_contact_uri,
        0,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_poc_pass_contact_to_talk_entry, KEY_EVENT_UP);
    SetKeyHandler(mmi_poc_pass_contact_to_talk_entry, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_talk_groups_add_from_contact_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for add from contact
 * PARAMETERS
 *  index       [IN]        Currently selected index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_talk_groups_add_from_contact_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_poc_cntx_p->contact_selected = (U8) index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_add_talk_entry_contact_name
 * DESCRIPTION
 *  add talk entry contact name
 * PARAMETERS
 *  item_index          [IN]        
 *  str_buff            [IN]        
 *  img_buff_p          [?]         
 *  str_img_mask        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_poc_add_talk_entry_contact_name(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_poc_contact_list_disp *cont;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cont = &g_poc_cntx_p->contact_list_disp[item_index];

    if ((item_index < 0) || (item_index > g_poc_cntx_p->contact_num))
    {
        return MMI_FALSE;
    }

    mmi_poc_util_copy_with_dot(
        (S8*) g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].display_name,
        (S8*) str_buff,
        MAX_SUBMENU_CHARACTERS - 1);

    *img_buff_p = (PU8) GetImage(gIndexIconsImageList[item_index]);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_add_talk_entry_contact_uri
 * DESCRIPTION
 *  add talk entry contact uri
 * PARAMETERS
 *  item_index      [IN]        
 *  hint_array      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_poc_add_talk_entry_contact_uri(S32 item_index, UI_string_type *hint_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_poc_contact_list_disp *cont;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cont = &g_poc_cntx_p->contact_list_disp[item_index];

    mmi_poc_util_copy_with_dot(
        (S8*) g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].uri,
        (PS8) * hint_array,
        MAX_SUBMENU_CHARACTERS - 1);
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_pass_contact_to_talk_entry
 * DESCRIPTION
 *  pass contact to talk entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_pass_contact_to_talk_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_poc_cntx_p->talk_entry_info_source = POC_TALK_ENTRY_FROM_CONTACT;
    mmi_poc_entry_talk_groups_opt_entry_settings_add_general();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_talk_groups_opt_entry_delete_cfrm
 * DESCRIPTION
 *  entry delete confirm screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_talk_groups_opt_entry_delete_cfrm(void)
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

    SetLeftSoftkeyFunction(mmi_poc_talk_group_entry_send_delete, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_poc_go_back_talk_group_list, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_talk_group_entry_send_delete
 * DESCRIPTION
 *  send entry delete
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_talk_group_entry_send_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_poc_entry_progressing();
    DeleteUptoScrID(SCR_ID_POC_TALK_GROUP);
    DeleteScreenIfPresent(SCR_ID_POC_TALK_GROUP);
    mmi_poc_del_talk_group_entry_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_del_talk_group_entry_req
 * DESCRIPTION
 *  entry delete request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_del_talk_group_entry_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    U8 curr_grp = g_poc_cntx_p->talk_group_selected;
    U8 curr_entry = g_poc_cntx_p->talk_entry_selected;
    poc_del_talk_group_entry_req_struct *myMsgPtr;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_poc_cntx_p->curr_use_xdm_mode == MMI_TRUE)
    {

        g_poc_cntx_p->progressing.contact = MMI_TRUE;

        myMsgPtr =
            (poc_del_talk_group_entry_req_struct*) OslConstructDataPtr(sizeof(poc_del_talk_group_entry_req_struct));
        memset(
            (U8*) myMsgPtr + sizeof(mmi_poc_dummy_req_struct),
            0,
            sizeof(poc_del_talk_group_entry_req_struct) - sizeof(mmi_poc_dummy_req_struct));

        myMsgPtr->request_id = POC_REQUEST_ID;
        strncpy(
            (char*)myMsgPtr->list_uri,
            (char*)g_poc_cntx_p->talk_group_list[curr_grp].list_uri,
            POC_MAX_URI_LEN - 1);
        strncpy(
            (char*)myMsgPtr->uri,
            (char*)g_poc_cntx_p->talk_group_list[curr_grp].entries[curr_entry].uri,
            POC_MAX_URI_LEN - 1);

        SetProtocolEventHandler(mmi_poc_del_talk_group_entry_rsp, MSG_ID_POC_DEL_TALK_GROUP_ENTRY_RSP);

        Message.oslSrcId = MOD_MMI;
        Message.oslDestId = MOD_POC;
        Message.oslMsgId = MSG_ID_POC_DEL_TALK_GROUP_ENTRY_REQ;
        Message.oslDataPtr = (oslParaType*) myMsgPtr;
        Message.oslPeerBuffPtr = NULL;
        OslMsgSendExtQueue(&Message);
    }
    else
    {
        g_poc_cntx_p->progressing.contact = MMI_FALSE;
        if (GetActiveScreenId() == SCR_ID_POC_GENERAL_PROGRESSING)
        {
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_DONE),
                IMG_GLOBAL_ACTIVATED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) SUCCESS_TONE);
        }

        DeleteScreenIfPresent(SCR_ID_POC_GENERAL_PROGRESSING);

        i = g_poc_cntx_p->talk_group_list[curr_grp].no_entries - 1;
        memcpy(
            &g_poc_cntx_p->talk_group_list[curr_grp].entries[g_poc_cntx_p->talk_entry_selected],
            &g_poc_cntx_p->talk_group_list[curr_grp].entries[i],
            sizeof(poc_talk_group_entry_struct));

        memset(&g_poc_cntx_p->talk_group_list[curr_grp].entries[i], 0, sizeof(poc_talk_group_entry_struct));

        if (g_poc_cntx_p->talk_group_list[curr_grp].no_entries > 0)
        {
            g_poc_cntx_p->talk_group_list[curr_grp].no_entries--;
        }

        g_poc_cntx_p->talk_group_local_updated = MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_del_talk_group_entry_rsp
 * DESCRIPTION
 *  delete talk group entry response handler
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_del_talk_group_entry_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    poc_del_talk_group_entry_rsp_struct *msgRsp;
    U8 i;
    U8 curr_grp = g_poc_cntx_p->talk_group_selected;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgRsp = (poc_del_talk_group_entry_rsp_struct*) info;

    ClearProtocolEventHandler(MSG_ID_POC_DEL_TALK_GROUP_ENTRY_RSP);

    g_poc_cntx_p->progressing.contact = MMI_FALSE;

    if (msgRsp->result == POC_OK)
    {
        if (GetActiveScreenId() == SCR_ID_POC_GENERAL_PROGRESSING)
        {
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_DONE),
                IMG_GLOBAL_ACTIVATED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) SUCCESS_TONE);
        }

        DeleteScreenIfPresent(SCR_ID_POC_GENERAL_PROGRESSING);

        i = g_poc_cntx_p->talk_group_list[curr_grp].no_entries - 1;
        memcpy(
            &g_poc_cntx_p->talk_group_list[curr_grp].entries[g_poc_cntx_p->talk_entry_selected],
            &g_poc_cntx_p->talk_group_list[curr_grp].entries[i],
            sizeof(poc_talk_group_entry_struct));

        memset(&g_poc_cntx_p->talk_group_list[curr_grp].entries[i], 0, sizeof(poc_talk_group_entry_struct));

        if (g_poc_cntx_p->talk_group_list[curr_grp].no_entries > 0)
        {
            g_poc_cntx_p->talk_group_list[curr_grp].no_entries--;
        }

        g_poc_cntx_p->talk_group_local_updated = MMI_FALSE;
    }
    else
    {
        if (GetActiveScreenId() == SCR_ID_POC_GENERAL_PROGRESSING)
        {
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_NOT_DONE),
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
        }
        DeleteScreenIfPresent(SCR_ID_POC_GENERAL_PROGRESSING);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_talk_groups_opt_add_group
 * DESCRIPTION
 *  add group screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_talk_groups_opt_add_group(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, ImageLocation = 0;
    U8 *inputBuffer;
    U8 *guiBuffer;
    U16 inputBufferSize;
    U16 IconList[POC_TALK_GROUP_INLINE_NUM];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_poc_cntx_p->talk_group_num >= MAX_POC_TALK_GROUP_FILE_NUM)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_POC_ERR_MAXIMUM_REACHED),
            IMG_GLOBAL_UNFINISHED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
        return;
    }

    EntryNewScreen(SCR_ID_POC_TALK_GROUP_ADD, mmi_poc_exit_talk_groups_opt_add_group, NULL, NULL);

    InitializeCategory57Screen();
    guiBuffer = GetCurrGuiBuffer(SCR_ID_POC_TALK_GROUP_ADD);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_POC_TALK_GROUP_ADD, &inputBufferSize);
    SetParentHandler(MENU_ID_POC_TALK_GROUPS_OPT_ADD_GROUP);

    mmi_poc_talk_group_fill_inline_struct(XDM_PUT_ADD);

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, POC_TALK_GROUP_INLINE_NUM, inputBuffer);
    }
    else
    {
        memset(&g_poc_cntx_p->talk_group_disp, 0, sizeof(poc_talk_group_disp_struct));
        g_poc_cntx_p->talk_group_disp.entries = custom_mmi_talk_group_entries;
        g_poc_cntx_p->talk_group_disp.invite_member_option[0] = (U8*) GetString(STR_GLOBAL_OFF);
        g_poc_cntx_p->talk_group_disp.invite_member_option[1] = (U8*) GetString(STR_GLOBAL_ON);

    #ifdef __MMI_POC_ETS_TESTCODE__
        mmi_asc_n_to_ucs2(
            (S8*) g_poc_cntx_p->talk_group_disp.list_uri,
            (S8*) "sip:POCGroup1@ims3.vfd2-testnetz.de",
            POC_MAX_URI_LEN - 1);
    #else /* __MMI_POC_ETS_TESTCODE__ */ 
        mmi_asc_n_to_ucs2(
            (S8*) g_poc_cntx_p->talk_group_disp.list_uri,
            (S8*) POC_MMI_SIP_PREFIX,
            POC_MAX_URI_LEN - 1);
    #endif /* __MMI_POC_ETS_TESTCODE__ */ 

    }

    if (guiBuffer == 0)
    {
        g_poc_cntx_p->inline_item_changed = MMI_FALSE;
    }

    if ((get_wgui_inline_list_menu_status() || g_poc_cntx_p->inline_item_changed) &&
        (GetInlineDoneFlag(guiBuffer) == 0))
    {
        SetInlineDoneFlag(guiBuffer);
    }

    for (i = 0; i < POC_TALK_GROUP_INLINE_NUM; i++)
    {
        if (i % 2)
        {
            IconList[i] = IMG_ID_POC_NOIMAGE;
        }
        else
        {
            IconList[i] = IMG_ID_POC_PROFILE_USER_NAME + ImageLocation;
            ImageLocation++;
        }
    }

    ShowCategory57Screen(
        STR_ID_POC_GROUP_INFO,
        GetRootTitleIcon(MENU_ID_POC_MAIN),
        STR_GLOBAL_EDIT,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        POC_TALK_GROUP_INLINE_NUM,
        IconList,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_poc_entry_talk_groups_opt_add_select_entry, GoBackHistory);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_exit_talk_groups_opt_add_group
 * DESCRIPTION
 *  exit screen for add group
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_exit_talk_groups_opt_add_group(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_leading_zero(TRUE);
    GenericExitInlineScreen(SCR_ID_POC_TALK_GROUP_ADD, mmi_poc_entry_talk_groups_opt_add_group);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_talk_group_fill_inline_struct
 * DESCRIPTION
 *  fill talk group inline structure
 * PARAMETERS
 *  op      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_talk_group_fill_inline_struct(U8 op)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 BufferSize = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_poc_cntx_p->talk_group_disp.invite_member_option[0] = (U8*) GetString(STR_GLOBAL_OFF);
    g_poc_cntx_p->talk_group_disp.invite_member_option[1] = (U8*) GetString(STR_GLOBAL_ON);

    SetInlineItemActivation((wgui_inline_items + POC_TALK_GROUP_NAME), KEY_LSK, KEY_EVENT_UP);
    SetInlineItemActivation((wgui_inline_items + POC_TALK_GROUP_URI), KEY_LSK, KEY_EVENT_UP);
    SetInlineItemActivation(
        (wgui_inline_items + POC_TALK_GROUP_MAX_PARTICIPANT),
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemActivation(
        (wgui_inline_items + POC_TALK_GROUP_INVITE_MEMBER),
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemActivation((wgui_inline_items + POC_TALK_GROUP_DEFAULT_RULE), KEY_LSK, KEY_EVENT_UP);

    SetInlineItemCaption((wgui_inline_items + POC_TALK_GROUP_NAME_STR), (U8*) GetString(STR_ID_POC_NAME));
    SetInlineItemCaption((wgui_inline_items + POC_TALK_GROUP_URI_STR), (U8*) GetString(STR_ID_POC_URI));
    SetInlineItemCaption(
        (wgui_inline_items + POC_TALK_GROUP_MAX_PARTICIPANT_STR),
        (U8*) GetString(STR_ID_POC_MAX_PARTICIPANTS));
    SetInlineItemCaption(
        (wgui_inline_items + POC_TALK_GROUP_INVITE_MEMBER_STR),
        (U8*) GetString(STR_ID_POC_INVITE_MEMBER));
    SetInlineItemCaption(
        (wgui_inline_items + POC_TALK_GROUP_DEFAULT_RULE_STR),
        (U8*) GetString(STR_ID_POC_DEFAULT_RULE));

    BufferSize = POC_MAX_DISP_LEN - 1;

    SetInlineItemFullScreenEdit_ext(
        (wgui_inline_items + POC_TALK_GROUP_NAME),
        STR_ID_POC_NAME,
        GetRootTitleIcon(MENU_ID_POC_MAIN),
        (U8*) (g_poc_cntx_p->talk_group_disp.display_name),
        BufferSize,
        (INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES),
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);

    SetInlineFullScreenEditCustomFunction(wgui_inline_items + POC_TALK_GROUP_NAME, mmi_poc_entry_full_line_edit);

    if (op == XDM_PUT_ADD)
    {
        BufferSize = POC_MAX_URI_LEN - 1;

        SetInlineItemFullScreenEdit_ext(
            (wgui_inline_items + POC_TALK_GROUP_URI),
            STR_ID_POC_URI,
            GetRootTitleIcon(MENU_ID_POC_MAIN),
            (U8*) (g_poc_cntx_p->talk_group_disp.list_uri),
            BufferSize,
            (INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES),
            INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);

        SetInlineFullScreenEditCustomFunction(wgui_inline_items + POC_TALK_GROUP_URI, mmi_poc_entry_full_line_edit);
    }
    else
    {
        SetInlineItemDisplayOnly(
            (wgui_inline_items + POC_TALK_GROUP_URI),
            (U8*) (g_poc_cntx_p->talk_group_disp.list_uri));
    }

    BufferSize = POC_MAX_GROUP_PARTICIPANT_LEN;
    SetInlineItemTextEdit(
        (wgui_inline_items + POC_TALK_GROUP_MAX_PARTICIPANT),
        (U8*) (g_poc_cntx_p->talk_group_disp.max_participant_count),
        BufferSize,
        INPUT_TYPE_NUMERIC);

    SetInlineItemSelect(
        (wgui_inline_items + POC_TALK_GROUP_INVITE_MEMBER),
        (S32) POC_MAX_GROUP_TYPE_OPTION_NUM,
        (U8 **) g_poc_cntx_p->talk_group_disp.invite_member_option,
        (S32*) & g_poc_cntx_p->talk_group_disp.invite_member);

    SetInlineItemImageText(
        (wgui_inline_items + POC_TALK_GROUP_DEFAULT_RULE),
        (U8*) GetString(STR_ID_POC_SET_ATTR),
        0,
        0,
        0,
        POC_MAX_DISP_LEN,
        0,
        0,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE);
    SetInlineFullScreenEditCustomFunctionImageText(
        (wgui_inline_items + POC_TALK_GROUP_DEFAULT_RULE),
        mmi_poc_entry_talk_groups_opt_attr);
    ShowAsControl(wgui_inline_items + POC_TALK_GROUP_DEFAULT_RULE);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_talk_groups_opt_attr
 * DESCRIPTION
 *  talk group option attribute screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_talk_groups_opt_attr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];
    U16 nNumofItem;
    U8 *guiBuffer;
    U16 menuId;
    U8 *PoCHint[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_POC_TALK_GROUP_INFO_ATTR, NULL, mmi_poc_entry_talk_groups_opt_attr, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_POC_TALK_GROUP_INFO_ATTR);
    menuId = MENU_ID_POC_TALK_GROUPS_OPT_GROUP_INFO_ATTR;

    nNumofItem = GetNumOfChild(menuId);
    GetSequenceStringIds(menuId, nStrItemList);
    SetParentHandler(menuId);
    ConstructHintsList(menuId, PoCHint);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ShowCategory52Screen(
        STR_ID_POC_ATTRIBUTES,
        GetRootTitleIcon(MENU_ID_POC_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        PoCHint,
        0,
        0,
        guiBuffer);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_talk_groups_opt_add_select_entry
 * DESCRIPTION
 *  add group select entry screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_talk_groups_opt_add_select_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nNumofItem;
    U8 i = 0;
    U8 *guiBuffer;
    mmi_poc_contact_list_disp *cont;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_poc_check_and_update_contact();

    nNumofItem = g_poc_cntx_p->contact_num;

    if (g_poc_cntx_p->contact_num == 0)
    {
        memset(g_poc_cntx_p->adhoc_sel_disp, 0, sizeof(U8) * POC_MAX_CONTACT_DISPLAY_NUM);
        mmi_poc_entry_talk_groups_opt_add_group_cfrm();
        return;
    }

    EntryNewScreen(
        SCR_ID_POC_TALK_GROUP_ADD_GROUP_SELECT_ENTRY,
        NULL,
        mmi_poc_entry_talk_groups_opt_add_select_entry,
        NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_POC_TALK_GROUP_ADD_GROUP_SELECT_ENTRY);

    if (nNumofItem > POC_MAX_CONTACT_DISPLAY_NUM)
    {
        nNumofItem = POC_MAX_CONTACT_DISPLAY_NUM;
    }

    for (i = 0; i < nNumofItem; i++)
    {
        subMenuDataPtrs[i] = subMenuData[i];
        memset((S8*) subMenuDataPtrs[i], 0, MAX_SUB_MENU_SIZE);
        cont = &g_poc_cntx_p->contact_list_disp[i];
        if (strlen((S8*) g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].display_name))
        {
            mmi_asc_n_to_ucs2(
                (S8*) subMenuDataPtrs[i],
                (S8*) g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id]. display_name,
                MAX_SUBMENU_CHARACTERS - 1);
        }
        else
        {
            mmi_poc_util_copy_with_dot(
                (S8*) g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].uri,
                (S8*) subMenuDataPtrs[i],
                MAX_SUBMENU_CHARACTERS - 1);
        }
    }
    SetParentHandler(MENU_ID_POC_TALK_GROUPS_OPT_ADD_GROUP_SEL_ENTRY);

    if (guiBuffer == NULL)
    {
        memset(g_poc_cntx_p->adhoc_sel_disp, 0, sizeof(U8) * POC_MAX_CONTACT_DISPLAY_NUM);
    }

    SetCheckboxToggleRightSoftkeyFunctions(mmi_poc_entry_talk_groups_opt_add_group_cfrm, GoBackHistory);

    ShowCategory140Screen(
        STR_ID_POC_CONTACTS,
        GetRootTitleIcon(MENU_ID_POC_MAIN),
        nNumofItem,
        (U8 **) subMenuDataPtrs,
        g_poc_cntx_p->adhoc_sel_disp,
        0,
        guiBuffer);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_talk_groups_opt_add_group_cfrm
 * DESCRIPTION
 *  add group confirm screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_talk_groups_opt_add_group_cfrm(void)
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

    SetLeftSoftkeyFunction(mmi_poc_create_talk_group_list_req, KEY_EVENT_UP);
    SetRightSoftkeyFunction(poc_go_back_create_talk_group_add_contact, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  poc_go_back_create_talk_group_add_contact
 * DESCRIPTION
 *  go back from add contact
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void poc_go_back_create_talk_group_add_contact(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stopRequestedTone(WARNING_TONE);
    DeleteUptoScrID(SCR_ID_POC_TALK_GROUP);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_create_talk_group_list_req
 * DESCRIPTION
 *  create talk group request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_create_talk_group_list_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    poc_create_talk_group_list_req_struct *myMsgPtr;
    mmi_poc_contact_list_disp *cont;
    U8 i, j;
    U8 StrDigit[POC_MAX_GROUP_PARTICIPANT_LEN + 1];
    U8 curr_grp = g_poc_cntx_p->talk_group_num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr =
        (poc_create_talk_group_list_req_struct*) OslConstructDataPtr(sizeof(poc_create_talk_group_list_req_struct));
    memset(
        (U8*) myMsgPtr + sizeof(mmi_poc_dummy_req_struct),
        0,
        sizeof(poc_create_talk_group_list_req_struct) - sizeof(mmi_poc_dummy_req_struct));
    myMsgPtr->no_entries = 0;

    memcpy(
        &myMsgPtr->entries[myMsgPtr->no_entries].uri,
        &g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_active].uri,
        sizeof(U8) * POC_MAX_URI_LEN);
    memcpy(
        &g_poc_cntx_p->talk_group_disp.entries[myMsgPtr->no_entries].uri,
        &g_poc_cntx_p->profile_list[g_poc_cntx_p->profile_active].uri,
        sizeof(U8) * POC_MAX_URI_LEN);
    memset(&myMsgPtr->entries[myMsgPtr->no_entries].group_rule, POC_SETTING_TRUE, sizeof(poc_group_param_struct));
    memset(
        &g_poc_cntx_p->talk_group_disp.entries[myMsgPtr->no_entries].group_rule,
        POC_SETTING_TRUE,
        sizeof(poc_group_param_struct));
    myMsgPtr->no_entries++;
    g_poc_cntx_p->talk_group_disp.no_entries = myMsgPtr->no_entries;

    for (i = 0; i < POC_MAX_CONTACT_DISPLAY_NUM; i++)
    {
        cont = &g_poc_cntx_p->contact_list_disp[i];
        if (g_poc_cntx_p->adhoc_sel_disp[i] == MMI_TRUE)
        {
            if (myMsgPtr->no_entries >= POC_GROUP_MAX_ENTRIES_NUM)
            {
                DisplayPopup(
                    (U8*) GetString(STR_ID_POC_ERR_MAXIMUM_REACHED),
                    IMG_GLOBAL_UNFINISHED,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    (U8) ERROR_TONE);
                OslFreeDataPtr((void*)myMsgPtr);
                return;
            }
            if (g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].uri[0] == 0 ||
                !strstr((S8*) g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].uri, (S8*) "@"))
            {
                DisplayPopup(
                    (PU8) GetString(STR_ID_POC_NULL_STR_ERR),
                    IMG_GLOBAL_UNFINISHED,
                    1,
                    CS_NOTIFYDURATION,
                    ERROR_TONE);
                DeleteScreenIfPresent(SCR_ID_POC_TALK_GROUP_ADD_GROUP_SELECT_ENTRY);
                OslFreeDataPtr((void*)myMsgPtr);
                return;
            }

            for (j = 0; j < myMsgPtr->no_entries; j++)
            {
                if (!strcmp
                    ((char*)g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].uri,
                     (char*)myMsgPtr->entries[j].uri))
                {
                    break;
                }
            }

            if (j == myMsgPtr->no_entries)
            {
                memcpy(
                    &myMsgPtr->entries[myMsgPtr->no_entries].uri,
                    &g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].uri,
                    sizeof(U8) * POC_MAX_URI_LEN);
                memcpy(
                    &g_poc_cntx_p->talk_group_disp.entries[myMsgPtr->no_entries].uri,
                    &g_poc_cntx_p->contact_list[cont->group_id].entries[cont->entry_id].uri,
                    sizeof(U8) * POC_MAX_URI_LEN);
                memset(
                    &myMsgPtr->entries[myMsgPtr->no_entries].group_rule,
                    POC_SETTING_TRUE,
                    sizeof(poc_group_param_struct));
                memset(
                    &g_poc_cntx_p->talk_group_disp.entries[myMsgPtr->no_entries].group_rule,
                    POC_SETTING_TRUE,
                    sizeof(poc_group_param_struct));
                myMsgPtr->no_entries++;
                g_poc_cntx_p->talk_group_disp.no_entries = myMsgPtr->no_entries;
            }
        }
    }

    if (g_poc_cntx_p->curr_use_xdm_mode == MMI_TRUE)
    {

        myMsgPtr->request_id = POC_REQUEST_ID;
        mmi_ucs2_n_to_asc((S8*) myMsgPtr->list_uri, (S8*) g_poc_cntx_p->talk_group_disp.list_uri, POC_MAX_URI_LEN - 1);

        if (myMsgPtr->list_uri[0] == 0 || !strstr((S8*) myMsgPtr->list_uri, (S8*) "@"))
        {
            DisplayPopup(
                (PU8) GetString(STR_ID_POC_NULL_STR_ERR),
                IMG_GLOBAL_UNFINISHED,
                1,
                CS_NOTIFYDURATION,
                ERROR_TONE);
            DeleteScreenIfPresent(SCR_ID_POC_TALK_GROUP_ADD_GROUP_SELECT_ENTRY);
            OslFreeDataPtr((void*)myMsgPtr);
            return;
        }

        myMsgPtr->display_name_lang = POC_GRP_LANG_NONE;
        mmi_ucs2_n_to_asc(
            (S8*) myMsgPtr->display_name,
            (S8*) g_poc_cntx_p->talk_group_disp.display_name,
            POC_MAX_DISP_LEN - 1);

        mmi_ucs2_to_asc((S8*) StrDigit, (S8*) g_poc_cntx_p->talk_group_disp.max_participant_count);
        myMsgPtr->max_participant_count = (U8) atoi((S8*) StrDigit);
        if (g_poc_cntx_p->talk_group_disp.invite_member == MMI_TRUE)
        {
            myMsgPtr->invite_member = POC_SETTING_TRUE;
        }
        else
        {
            myMsgPtr->invite_member = POC_SETTING_FALSE;
        }
        memcpy(&myMsgPtr->default_rule, &g_poc_cntx_p->talk_group_disp.default_rule, sizeof(poc_group_param_struct));

        myMsgPtr->more_data = MMI_FALSE;

        SetProtocolEventHandler(mmi_poc_create_talk_group_list_rsp, MSG_ID_POC_CREATE_TALK_GROUP_LIST_RSP);

        g_poc_cntx_p->progressing.contact = MMI_TRUE;
        mmi_poc_entry_progressing();
        DeleteUptoScrID(SCR_ID_POC_TALK_GROUP);
        DeleteScreenIfPresent(SCR_ID_POC_TALK_GROUP);

        Message.oslSrcId = MOD_MMI;
        Message.oslDestId = MOD_POC;
        Message.oslMsgId = MSG_ID_POC_CREATE_TALK_GROUP_LIST_REQ;
        Message.oslDataPtr = (oslParaType*) myMsgPtr;
        Message.oslPeerBuffPtr = NULL;
        OslMsgSendExtQueue(&Message);
    }
    else
    {
        mmi_poc_entry_progressing();
        g_poc_cntx_p->progressing.contact = MMI_FALSE;
        DeleteUptoScrID(SCR_ID_POC_TALK_GROUP);
        DeleteScreenIfPresent(SCR_ID_POC_TALK_GROUP);
        if (GetActiveScreenId() == SCR_ID_POC_GENERAL_PROGRESSING)
        {
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_DONE),
                IMG_GLOBAL_ACTIVATED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) SUCCESS_TONE);
        }
        DeleteScreenIfPresent(SCR_ID_POC_GENERAL_PROGRESSING);

        ASSERT(g_poc_cntx_p->talk_group_num < MAX_POC_TALK_GROUP_FILE_NUM);

        memset(
            g_poc_cntx_p->talk_group_list[curr_grp].list_uri,
            0,
            sizeof(g_poc_cntx_p->talk_group_list[curr_grp].list_uri));
        mmi_ucs2_n_to_asc(
            (S8*) g_poc_cntx_p->talk_group_list[curr_grp].list_uri,
            (S8*) g_poc_cntx_p->talk_group_disp.list_uri,
            POC_MAX_URI_LEN - 1);
        g_poc_cntx_p->talk_group_list[curr_grp].display_name_lang = g_poc_cntx_p->talk_group_disp.display_name_lang;
        memset(
            g_poc_cntx_p->talk_group_list[curr_grp].display_name,
            0,
            sizeof(g_poc_cntx_p->talk_group_list[curr_grp].display_name));
        mmi_ucs2_n_to_asc(
            (S8*) g_poc_cntx_p->talk_group_list[curr_grp].display_name,
            (S8*) g_poc_cntx_p->talk_group_disp.display_name,
            POC_MAX_DISP_LEN - 1);
        mmi_ucs2_to_asc((S8*) StrDigit, (S8*) g_poc_cntx_p->talk_group_disp.max_participant_count);
        g_poc_cntx_p->talk_group_list[curr_grp].max_participant_count = (U8) atoi((S8*) StrDigit);
        if (g_poc_cntx_p->talk_group_disp.invite_member == MMI_TRUE)
        {
            g_poc_cntx_p->talk_group_list[curr_grp].invite_member = POC_SETTING_TRUE;
        }
        else
        {
            g_poc_cntx_p->talk_group_list[curr_grp].invite_member = POC_SETTING_FALSE;
        }
        memcpy(
            &g_poc_cntx_p->talk_group_list[curr_grp].default_rule,
            &g_poc_cntx_p->talk_group_disp.default_rule,
            sizeof(poc_group_param_struct));
        g_poc_cntx_p->talk_group_list[curr_grp].no_entries = g_poc_cntx_p->talk_group_disp.no_entries;

        memcpy(
            &g_poc_cntx_p->talk_group_list[curr_grp].entries,
            g_poc_cntx_p->talk_group_disp.entries,
            sizeof(poc_talk_group_entry_struct) * POC_TALK_GROUP_LOCAL_MAX_ENTRIES_NUM);
        g_poc_cntx_p->talk_group_list[curr_grp].valid = MMI_TRUE;
        g_poc_cntx_p->talk_group_num++;
        g_poc_cntx_p->talk_group_local_updated = MMI_FALSE;

        OslFreeDataPtr((void*)myMsgPtr);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_create_talk_group_list_rsp
 * DESCRIPTION
 *  create talk group list response handler
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_create_talk_group_list_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    poc_create_talk_group_list_rsp_struct *msgRsp;
    U8 StrDigit[POC_MAX_GROUP_PARTICIPANT_LEN + 1];
    U8 curr_grp = g_poc_cntx_p->talk_group_num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgRsp = (poc_create_talk_group_list_rsp_struct*) info;

    ClearProtocolEventHandler(MSG_ID_POC_CREATE_TALK_GROUP_LIST_RSP);

    g_poc_cntx_p->progressing.contact = MMI_FALSE;

    if (msgRsp->result == POC_OK)
    {
        if (GetActiveScreenId() == SCR_ID_POC_GENERAL_PROGRESSING)
        {
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_DONE),
                IMG_GLOBAL_ACTIVATED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) SUCCESS_TONE);
        }
        DeleteScreenIfPresent(SCR_ID_POC_GENERAL_PROGRESSING);

        ASSERT(g_poc_cntx_p->talk_group_num < MAX_POC_TALK_GROUP_FILE_NUM);

        memset(
            g_poc_cntx_p->talk_group_list[curr_grp].list_uri,
            0,
            sizeof(g_poc_cntx_p->talk_group_list[curr_grp].list_uri));

    #if (0) /* use the new addr from network */
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* (0) */ 

        strncpy(
            (char*)g_poc_cntx_p->talk_group_list[curr_grp].list_uri,
            (char*)msgRsp->list_uri,
            POC_MAX_URI_LEN - 1);

        g_poc_cntx_p->talk_group_list[curr_grp].display_name_lang = g_poc_cntx_p->talk_group_disp.display_name_lang;
        memset(
            g_poc_cntx_p->talk_group_list[curr_grp].display_name,
            0,
            sizeof(g_poc_cntx_p->talk_group_list[curr_grp].display_name));
        mmi_ucs2_n_to_asc(
            (S8*) g_poc_cntx_p->talk_group_list[curr_grp].display_name,
            (S8*) g_poc_cntx_p->talk_group_disp.display_name,
            POC_MAX_DISP_LEN - 1);
        mmi_ucs2_to_asc((S8*) StrDigit, (S8*) g_poc_cntx_p->talk_group_disp.max_participant_count);
        g_poc_cntx_p->talk_group_list[curr_grp].max_participant_count = (U8) atoi((S8*) StrDigit);
        if (g_poc_cntx_p->talk_group_disp.invite_member == MMI_TRUE)
        {
            g_poc_cntx_p->talk_group_list[curr_grp].invite_member = POC_SETTING_TRUE;
        }
        else
        {
            g_poc_cntx_p->talk_group_list[curr_grp].invite_member = POC_SETTING_FALSE;
        }
        memcpy(
            &g_poc_cntx_p->talk_group_list[curr_grp].default_rule,
            &g_poc_cntx_p->talk_group_disp.default_rule,
            sizeof(poc_group_param_struct));
        g_poc_cntx_p->talk_group_list[curr_grp].no_entries = g_poc_cntx_p->talk_group_disp.no_entries;

        memcpy(
            &g_poc_cntx_p->talk_group_list[curr_grp].entries,
            g_poc_cntx_p->talk_group_disp.entries,
            sizeof(poc_talk_group_entry_struct) * POC_TALK_GROUP_LOCAL_MAX_ENTRIES_NUM);
        g_poc_cntx_p->talk_group_list[curr_grp].valid = MMI_TRUE;
        g_poc_cntx_p->talk_group_num++;
        g_poc_cntx_p->talk_group_local_updated = MMI_FALSE;
    }
    else
    {
        if (GetActiveScreenId() == SCR_ID_POC_GENERAL_PROGRESSING)
        {
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_NOT_DONE),
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
        }
        DeleteScreenIfPresent(SCR_ID_POC_GENERAL_PROGRESSING);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_talk_group_opt_delete_cfrm
 * DESCRIPTION
 *  delete confirm screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_talk_group_opt_delete_cfrm(void)
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

    SetLeftSoftkeyFunction(mmi_poc_talk_group_send_delete, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_poc_go_back_talk_group_list, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_talk_group_send_delete
 * DESCRIPTION
 *  send talk group delete
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_talk_group_send_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_poc_entry_progressing();
    DeleteUptoScrID(SCR_ID_POC_TALK_GROUP);
    DeleteScreenIfPresent(SCR_ID_POC_TALK_GROUP);

    mmi_poc_del_talk_group_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_del_talk_group_req
 * DESCRIPTION
 *  delete talk group request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_del_talk_group_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    poc_del_talk_group_list_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_poc_cntx_p->curr_use_xdm_mode == MMI_TRUE)
    {
        g_poc_cntx_p->progressing.contact = MMI_TRUE;

        myMsgPtr =
            (poc_del_talk_group_list_req_struct*) OslConstructDataPtr(sizeof(poc_del_talk_group_list_req_struct));
        memset(
            (U8*) myMsgPtr + sizeof(mmi_poc_dummy_req_struct),
            0,
            sizeof(poc_del_talk_group_list_req_struct) - sizeof(mmi_poc_dummy_req_struct));

        myMsgPtr->request_id = POC_REQUEST_ID;
        strncpy(
            (char*)myMsgPtr->list_uri,
            (char*)g_poc_cntx_p->talk_group_list[g_poc_cntx_p->talk_group_selected].list_uri,
            POC_MAX_URI_LEN - 1);

        SetProtocolEventHandler(mmi_poc_del_talk_group_rsp, MSG_ID_POC_DEL_TALK_GROUP_LIST_RSP);

        Message.oslSrcId = MOD_MMI;
        Message.oslDestId = MOD_POC;
        Message.oslMsgId = MSG_ID_POC_DEL_TALK_GROUP_LIST_REQ;
        Message.oslDataPtr = (oslParaType*) myMsgPtr;
        Message.oslPeerBuffPtr = NULL;
        OslMsgSendExtQueue(&Message);
    }
    else
    {
        g_poc_cntx_p->progressing.contact = MMI_FALSE;
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_DONE),
            IMG_GLOBAL_ACTIVATED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) SUCCESS_TONE);
        DeleteScreenIfPresent(SCR_ID_POC_GENERAL_PROGRESSING);

        memcpy(
            &g_poc_cntx_p->talk_group_list[g_poc_cntx_p->talk_group_selected],
            &g_poc_cntx_p->talk_group_list[g_poc_cntx_p->talk_group_num - 1],
            sizeof(poc_talk_group_struct));

        memset(&g_poc_cntx_p->talk_group_list[g_poc_cntx_p->talk_group_num - 1], 0, sizeof(poc_talk_group_struct));

        if (g_poc_cntx_p->talk_group_num > 0)
        {
            g_poc_cntx_p->talk_group_num--;
        }
        g_poc_cntx_p->talk_group_local_updated = MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_del_talk_group_rsp
 * DESCRIPTION
 *  delete talk group response handler
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_del_talk_group_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    poc_del_talk_group_list_rsp_struct *msgRsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgRsp = (poc_del_talk_group_list_rsp_struct*) info;

    ClearProtocolEventHandler(MSG_ID_POC_DEL_TALK_GROUP_LIST_RSP);

    g_poc_cntx_p->progressing.contact = MMI_FALSE;

    if (msgRsp->result == POC_OK)
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_DONE),
            IMG_GLOBAL_ACTIVATED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) SUCCESS_TONE);
        DeleteScreenIfPresent(SCR_ID_POC_GENERAL_PROGRESSING);

        memcpy(
            &g_poc_cntx_p->talk_group_list[g_poc_cntx_p->talk_group_selected],
            &g_poc_cntx_p->talk_group_list[g_poc_cntx_p->talk_group_num - 1],
            sizeof(poc_talk_group_struct));

        memset(&g_poc_cntx_p->talk_group_list[g_poc_cntx_p->talk_group_num - 1], 0, sizeof(poc_talk_group_struct));

        if (g_poc_cntx_p->talk_group_num > 0)
        {
            g_poc_cntx_p->talk_group_num--;
        }

        g_poc_cntx_p->talk_group_local_updated = MMI_FALSE;
    }
    else
    {
        if (GetActiveScreenId() == SCR_ID_POC_GENERAL_PROGRESSING)
        {
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_NOT_DONE),
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
        }
        DeleteScreenIfPresent(SCR_ID_POC_GENERAL_PROGRESSING);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_talk_groups_opt_group_info
 * DESCRIPTION
 *  group info screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_talk_groups_opt_group_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, ImageLocation = 0;
    U8 *inputBuffer;
    U8 *guiBuffer;
    U16 inputBufferSize;
    U16 IconList[POC_TALK_GROUP_INLINE_NUM];
    U8 temp_str[(POC_MAX_GROUP_PARTICIPANT_LEN + 1) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_POC_TALK_GROUP_INFO, mmi_poc_exit_talk_groups_opt_group_info, NULL, NULL);

    InitializeCategory57Screen();
    guiBuffer = GetCurrGuiBuffer(SCR_ID_POC_TALK_GROUP_INFO);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_POC_TALK_GROUP_INFO, &inputBufferSize);
    SetParentHandler(MENU_ID_POC_TALK_GROUPS_OPT_GROUP_INFO);

    mmi_poc_talk_group_fill_inline_struct(XDM_PUT_REPLACE);

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, POC_TALK_GROUP_INLINE_NUM, inputBuffer);
    }
    else
    {
        memset(&g_poc_cntx_p->talk_group_disp, 0, sizeof(poc_talk_group_disp_struct));
        g_poc_cntx_p->talk_group_disp.entries = custom_mmi_talk_group_entries;
        if (strlen((S8*) g_poc_cntx_p->talk_group_list[g_poc_cntx_p->talk_group_selected].list_uri))
        {
            mmi_asc_n_to_ucs2(
                (S8*) g_poc_cntx_p->talk_group_disp.list_uri,
                (S8*) g_poc_cntx_p->talk_group_list[g_poc_cntx_p->talk_group_selected].list_uri,
                POC_MAX_URI_LEN - 1);
        }
        else
        {
            mmi_asc_n_to_ucs2(
                (S8*) g_poc_cntx_p->talk_group_disp.list_uri,
                (S8*) POC_MMI_SIP_PREFIX,
                POC_MAX_URI_LEN - 1);
        }

        g_poc_cntx_p->talk_group_disp.display_name_lang =
            g_poc_cntx_p->talk_group_list[g_poc_cntx_p->talk_group_selected].display_name_lang;
        mmi_asc_n_to_ucs2(
            (S8*) g_poc_cntx_p->talk_group_disp.display_name,
            (S8*) g_poc_cntx_p->talk_group_list[g_poc_cntx_p->talk_group_selected].display_name,
            POC_MAX_DISP_LEN - 1);
        sprintf(
            (S8*) temp_str,
            "%d",
            g_poc_cntx_p->talk_group_list[g_poc_cntx_p->talk_group_selected].max_participant_count);
        mmi_asc_n_to_ucs2(
            (S8*) g_poc_cntx_p->talk_group_disp.max_participant_count,
            (S8*) temp_str,
            POC_MAX_GROUP_PARTICIPANT_LEN - 1);
        g_poc_cntx_p->talk_group_disp.invite_member_option[0] = (U8*) GetString(STR_GLOBAL_OFF);
        g_poc_cntx_p->talk_group_disp.invite_member_option[1] = (U8*) GetString(STR_GLOBAL_ON);

        if (g_poc_cntx_p->talk_group_list[g_poc_cntx_p->talk_group_selected].invite_member == POC_SETTING_TRUE)
        {
            g_poc_cntx_p->talk_group_disp.invite_member = MMI_TRUE;
        }
        else
        {
            g_poc_cntx_p->talk_group_disp.invite_member = MMI_FALSE;
        }

        memcpy(
            &g_poc_cntx_p->talk_group_disp.default_rule,
            &g_poc_cntx_p->talk_group_list[g_poc_cntx_p->talk_group_selected].default_rule,
            sizeof(poc_group_param_struct));
        /* don't need to fill group entries */
    }

    if (guiBuffer == 0)
    {
        g_poc_cntx_p->inline_item_changed = MMI_FALSE;
    }

    if ((get_wgui_inline_list_menu_status() || g_poc_cntx_p->inline_item_changed) &&
        (GetInlineDoneFlag(guiBuffer) == 0))
    {
        SetInlineDoneFlag(guiBuffer);
    }

    for (i = 0; i < POC_TALK_GROUP_INLINE_NUM; i++)
    {
        if (i % 2)
        {
            IconList[i] = IMG_ID_POC_NOIMAGE;
        }
        else
        {
            IconList[i] = IMG_ID_POC_PROFILE_USER_NAME + ImageLocation;
            ImageLocation++;
        }
    }

    ShowCategory57Screen(
        STR_ID_POC_GROUP_INFO,
        GetRootTitleIcon(MENU_ID_POC_MAIN),
        STR_GLOBAL_EDIT,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        POC_TALK_GROUP_INLINE_NUM,
        IconList,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_poc_entry_talk_groups_opt_group_info_cfrm, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_exit_talk_groups_opt_group_info
 * DESCRIPTION
 *  exit function for group info screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_exit_talk_groups_opt_group_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_leading_zero(TRUE);
    GenericExitInlineScreen(SCR_ID_POC_TALK_GROUP_INFO, mmi_poc_entry_talk_groups_opt_group_info);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_talk_groups_opt_group_info_cfrm
 * DESCRIPTION
 *  change group info confirm screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_talk_groups_opt_group_info_cfrm(void)
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

    SetLeftSoftkeyFunction(mmi_poc_update_talk_group_param_req, KEY_EVENT_UP);
    SetRightSoftkeyFunction(poc_go_back_create_talk_group_add_contact, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_update_talk_group_param_req
 * DESCRIPTION
 *  update talk group parameter request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_update_talk_group_param_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    poc_update_talk_group_param_req_struct *myMsgPtr;
    U8 StrDigit[POC_MAX_GROUP_PARTICIPANT_LEN + 1];
    U8 curr_grp = g_poc_cntx_p->talk_group_selected;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_poc_cntx_p->curr_use_xdm_mode == MMI_TRUE)
    {
        myMsgPtr =
            (poc_update_talk_group_param_req_struct*)
            OslConstructDataPtr(sizeof(poc_update_talk_group_param_req_struct));
        memset(
            (U8*) myMsgPtr + sizeof(mmi_poc_dummy_req_struct),
            0,
            sizeof(poc_update_talk_group_param_req_struct) - sizeof(mmi_poc_dummy_req_struct));

        mmi_poc_entry_progressing();
        DeleteUptoScrID(SCR_ID_POC_TALK_GROUP);
        DeleteScreenIfPresent(SCR_ID_POC_TALK_GROUP);

        g_poc_cntx_p->progressing.contact = MMI_TRUE;

        myMsgPtr->request_id = POC_REQUEST_ID;
        mmi_ucs2_n_to_asc((S8*) myMsgPtr->list_uri, (S8*) g_poc_cntx_p->talk_group_disp.list_uri, POC_MAX_URI_LEN - 1);
        myMsgPtr->display_name_lang = POC_GRP_LANG_NONE;
        mmi_ucs2_n_to_asc(
            (S8*) myMsgPtr->display_name,
            (S8*) g_poc_cntx_p->talk_group_disp.display_name,
            POC_MAX_DISP_LEN - 1);

        mmi_ucs2_to_asc((S8*) StrDigit, (S8*) g_poc_cntx_p->talk_group_disp.max_participant_count);
        myMsgPtr->max_participant_count = (U8) atoi((S8*) StrDigit);

        if (g_poc_cntx_p->talk_group_disp.invite_member == MMI_TRUE)
        {
            myMsgPtr->invite_member = POC_SETTING_TRUE;
        }
        else
        {
            myMsgPtr->invite_member = POC_SETTING_FALSE;
        }
        memcpy(&myMsgPtr->default_rule, &g_poc_cntx_p->talk_group_disp.default_rule, sizeof(poc_group_param_struct));

        SetProtocolEventHandler(mmi_poc_update_talk_group_param_rsp, MSG_ID_POC_UPDATE_TALK_GROUP_PARAM_RSP);

        Message.oslSrcId = MOD_MMI;
        Message.oslDestId = MOD_POC;
        Message.oslMsgId = MSG_ID_POC_UPDATE_TALK_GROUP_PARAM_REQ;
        Message.oslDataPtr = (oslParaType*) myMsgPtr;
        Message.oslPeerBuffPtr = NULL;
        OslMsgSendExtQueue(&Message);
    }
    else
    {
        mmi_poc_entry_progressing();
        g_poc_cntx_p->progressing.contact = MMI_FALSE;
        DeleteUptoScrID(SCR_ID_POC_TALK_GROUP);
        DeleteScreenIfPresent(SCR_ID_POC_TALK_GROUP);
        if (GetActiveScreenId() == SCR_ID_POC_GENERAL_PROGRESSING)
        {
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_DONE),
                IMG_GLOBAL_ACTIVATED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) SUCCESS_TONE);
        }
        DeleteScreenIfPresent(SCR_ID_POC_GENERAL_PROGRESSING);
        memset(
            g_poc_cntx_p->talk_group_list[curr_grp].list_uri,
            0,
            sizeof(g_poc_cntx_p->talk_group_list[curr_grp].list_uri));
        mmi_ucs2_n_to_asc(
            (S8*) g_poc_cntx_p->talk_group_list[curr_grp].list_uri,
            (S8*) g_poc_cntx_p->talk_group_disp.list_uri,
            POC_MAX_URI_LEN - 1);
        g_poc_cntx_p->talk_group_list[curr_grp].display_name_lang = g_poc_cntx_p->talk_group_disp.display_name_lang;
        memset(
            g_poc_cntx_p->talk_group_list[curr_grp].display_name,
            0,
            sizeof(g_poc_cntx_p->talk_group_list[curr_grp].display_name));
        mmi_ucs2_n_to_asc(
            (S8*) g_poc_cntx_p->talk_group_list[curr_grp].display_name,
            (S8*) g_poc_cntx_p->talk_group_disp.display_name,
            POC_MAX_DISP_LEN - 1);
        mmi_ucs2_to_asc((S8*) StrDigit, (S8*) g_poc_cntx_p->talk_group_disp.max_participant_count);
        g_poc_cntx_p->talk_group_list[curr_grp].max_participant_count = (U8) atoi((S8*) StrDigit);
        g_poc_cntx_p->talk_group_list[curr_grp].invite_member = g_poc_cntx_p->talk_group_disp.invite_member;
        memcpy(
            &g_poc_cntx_p->talk_group_list[curr_grp].default_rule,
            &g_poc_cntx_p->talk_group_disp.default_rule,
            sizeof(poc_group_param_struct));
        g_poc_cntx_p->talk_group_local_updated = MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_update_talk_group_param_rsp
 * DESCRIPTION
 *  update talk group parameter response hanlder
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_update_talk_group_param_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    poc_update_talk_group_param_rsp_struct *msgRsp;
    U8 StrDigit[POC_MAX_GROUP_PARTICIPANT_LEN + 1];
    U8 curr_grp = g_poc_cntx_p->talk_group_selected;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgRsp = (poc_update_talk_group_param_rsp_struct*) info;

    ClearProtocolEventHandler(MSG_ID_POC_UPDATE_TALK_GROUP_PARAM_RSP);

    g_poc_cntx_p->progressing.contact = MMI_FALSE;

    if (msgRsp->result == POC_OK)
    {
        if (GetActiveScreenId() == SCR_ID_POC_GENERAL_PROGRESSING)
        {
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_DONE),
                IMG_GLOBAL_ACTIVATED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) SUCCESS_TONE);
        }
        DeleteScreenIfPresent(SCR_ID_POC_GENERAL_PROGRESSING);
        memset(
            g_poc_cntx_p->talk_group_list[curr_grp].list_uri,
            0,
            sizeof(g_poc_cntx_p->talk_group_list[curr_grp].list_uri));
        mmi_ucs2_n_to_asc(
            (S8*) g_poc_cntx_p->talk_group_list[curr_grp].list_uri,
            (S8*) g_poc_cntx_p->talk_group_disp.list_uri,
            POC_MAX_URI_LEN - 1);
        g_poc_cntx_p->talk_group_list[curr_grp].display_name_lang = g_poc_cntx_p->talk_group_disp.display_name_lang;
        memset(
            g_poc_cntx_p->talk_group_list[curr_grp].display_name,
            0,
            sizeof(g_poc_cntx_p->talk_group_list[curr_grp].display_name));
        mmi_ucs2_n_to_asc(
            (S8*) g_poc_cntx_p->talk_group_list[curr_grp].display_name,
            (S8*) g_poc_cntx_p->talk_group_disp.display_name,
            POC_MAX_DISP_LEN - 1);
        mmi_ucs2_to_asc((S8*) StrDigit, (S8*) g_poc_cntx_p->talk_group_disp.max_participant_count);
        g_poc_cntx_p->talk_group_list[curr_grp].max_participant_count = (U8) atoi((S8*) StrDigit);
        g_poc_cntx_p->talk_group_list[curr_grp].invite_member = g_poc_cntx_p->talk_group_disp.invite_member;
        memcpy(
            &g_poc_cntx_p->talk_group_list[curr_grp].default_rule,
            &g_poc_cntx_p->talk_group_disp.default_rule,
            sizeof(poc_group_param_struct));
        g_poc_cntx_p->talk_group_local_updated = MMI_FALSE;
    }
    else
    {
        if (GetActiveScreenId() == SCR_ID_POC_GENERAL_PROGRESSING)
        {
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_NOT_DONE),
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
        }
        DeleteScreenIfPresent(SCR_ID_POC_GENERAL_PROGRESSING);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_presence_notify_ind
 * DESCRIPTION
 *  presence notify indication handler
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_presence_notify_ind(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, j, pinfo_idx, presence_updated = MMI_FALSE;
    poc_presence_notify_ind_struct *msgRsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgRsp = (poc_presence_notify_ind_struct*) info;

    if (msgRsp->result == POC_OK)
    {
        if (msgRsp->full_state == MMI_TRUE)
        {
            for (i = 0; i < MAX_POC_GROUP_FILE_NUM * MAX_POC_GROUPS_PER_FILE_NUM; i++)
            {
                if (g_poc_cntx_p->contact_list[i].valid == MMI_TRUE)
                {
                    for (j = 0; j < g_poc_cntx_p->contact_list[i].no_entries; j++)
                    {
                        memset(&g_poc_cntx_p->contact_list[i].entries[j].pres, 0, sizeof(mmi_poc_presence_struct));
                    }
                }
            }
        }
        for (pinfo_idx = 0; pinfo_idx < msgRsp->num_pinfo; pinfo_idx++)
        {
            for (i = 0; i < MAX_POC_GROUP_FILE_NUM * MAX_POC_GROUPS_PER_FILE_NUM; i++)
            {
                if (g_poc_cntx_p->contact_list[i].valid == MMI_TRUE)
                {
                    for (j = 0; j < g_poc_cntx_p->contact_list[i].no_entries; j++)
                    {
                        if (!strncmp
                            ((S8*) msgRsp->pinfo[pinfo_idx].entity,
                             (S8*) g_poc_cntx_p->contact_list[i].entries[j].uri, POC_MAX_URI_LEN - 1))
                        {
                            g_poc_cntx_p->contact_list[i].entries[j].pres.is_active =
                                msgRsp->pinfo[pinfo_idx].is_active;
                            g_poc_cntx_p->contact_list[i].entries[j].pres.person.activity_present =
                                msgRsp->pinfo[pinfo_idx].person.activity_present;
                            g_poc_cntx_p->contact_list[i].entries[j].pres.person.activity =
                                msgRsp->pinfo[pinfo_idx].person.activity;
                            g_poc_cntx_p->contact_list[i].entries[j].pres.person.mood_present =
                                msgRsp->pinfo[pinfo_idx].person.mood_present;
                            g_poc_cntx_p->contact_list[i].entries[j].pres.person.mood =
                                msgRsp->pinfo[pinfo_idx].person.mood;

                            presence_updated = MMI_TRUE;
                        }
                    }
                }
            }
        }
        if ((presence_updated == MMI_TRUE) && (msgRsp->more_data == MMI_FALSE))
        {
            if (GetActiveScreenId() == SCR_ID_POC_CONTACT || GetActiveScreenId() == SCR_ID_POC_CONTACT_ENTRY_INFO)
            {
                DisplayPopup(
                    (U8*) GetString(STR_ID_POC_PRESENCE_UPDATED),
                    IMG_GLOBAL_ACTIVATED,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    (U8) SUCCESS_TONE);
            }
        }
    }
    mmi_poc_presence_notify_res();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_presence_notify_res
 * DESCRIPTION
 *  send presence notify res to protocol
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_presence_notify_res(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    poc_presence_notify_res_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (poc_presence_notify_res_struct*) OslConstructDataPtr(sizeof(poc_presence_notify_res_struct));
    memset(
        (U8*) myMsgPtr + sizeof(mmi_poc_dummy_req_struct),
        0,
        sizeof(poc_presence_notify_res_struct) - sizeof(mmi_poc_dummy_req_struct));

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_POC;
    Message.oslMsgId = MSG_ID_POC_PRESENCE_NOTIFY_RES;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_talk_groups_opt_call_others_group
 * DESCRIPTION
 *  call others group screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_talk_groups_opt_call_others_group(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, ImageLocation = 0;
    U8 *inputBuffer;
    U8 *guiBuffer;
    U16 inputBufferSize;
    U16 IconList[POC_CALL_OTHERS_GROUP_INLINE_NUM];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_POC_TALK_GROUP_CALL_OTHERS_GROUP, mmi_poc_exit_talk_groups_opt_call_others_group, NULL, NULL);

    InitializeCategory57Screen();
    guiBuffer = GetCurrGuiBuffer(SCR_ID_POC_TALK_GROUP_CALL_OTHERS_GROUP);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_POC_TALK_GROUP_CALL_OTHERS_GROUP, &inputBufferSize);
    SetParentHandler(MENU_ID_POC_TALK_GROUPS_OPT_CALL_OTHERS_GROUP);

    mmi_poc_call_others_group_fill_inline_struct();

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, POC_CALL_OTHERS_GROUP_INLINE_NUM, inputBuffer);
    }
    else
    {
        memset(&g_poc_cntx_p->talk_group_disp, 0, sizeof(poc_talk_group_disp_struct));
        g_poc_cntx_p->talk_group_disp.entries = custom_mmi_talk_group_entries;
        g_poc_cntx_p->talk_group_disp.invite_member_option[0] = (U8*) GetString(STR_GLOBAL_OFF);
        g_poc_cntx_p->talk_group_disp.invite_member_option[1] = (U8*) GetString(STR_GLOBAL_ON);
        mmi_asc_n_to_ucs2(
            (S8*) g_poc_cntx_p->talk_group_disp.list_uri,
            (S8*) POC_MMI_SIP_PREFIX,
            POC_MAX_URI_LEN - 1);
    #ifdef __MMI_POC_REM_OTHERS_GROUP__
        if (mmi_ucs2strlen((S8*) g_poc_cntx_p->others_group_disp.list_uri))
        {
            memcpy(
                &g_poc_cntx_p->talk_group_disp,
                &g_poc_cntx_p->others_group_disp,
                sizeof(poc_talk_group_disp_struct));
            g_poc_cntx_p->talk_group_disp.invite_member_option[0] = (U8*) GetString(STR_GLOBAL_OFF);
            g_poc_cntx_p->talk_group_disp.invite_member_option[1] = (U8*) GetString(STR_GLOBAL_ON);
        }
        else
        {
            memset(g_poc_cntx_p->talk_group_disp.list_uri, 0, sizeof(g_poc_cntx_p->talk_group_disp.list_uri));

        #ifdef __MMI_POC_ETS_TESTCODE__
            mmi_asc_n_to_ucs2(
                (S8*) g_poc_cntx_p->talk_group_disp.list_uri,
                (S8*) "sip:POCGroup1@ims3.vfd2-testnetz.de",
                POC_MAX_URI_LEN - 1);
        #else /* __MMI_POC_ETS_TESTCODE__ */ 
            mmi_asc_n_to_ucs2(
                (S8*) g_poc_cntx_p->talk_group_disp.list_uri,
                (S8*) POC_MMI_SIP_PREFIX,
                POC_MAX_URI_LEN - 1);
        #endif /* __MMI_POC_ETS_TESTCODE__ */ 

        }
    #endif /* __MMI_POC_REM_OTHERS_GROUP__ */ 
    }

    if (guiBuffer == 0)
    {
        g_poc_cntx_p->inline_item_changed = MMI_FALSE;
    }

    if ((get_wgui_inline_list_menu_status() || g_poc_cntx_p->inline_item_changed) &&
        (GetInlineDoneFlag(guiBuffer) == 0))
    {
        SetInlineDoneFlag(guiBuffer);
    }

    for (i = 0; i < POC_CALL_OTHERS_GROUP_INLINE_NUM; i++)
    {
        if (i % 2)
        {
            IconList[i] = IMG_ID_POC_NOIMAGE;
        }
        else
        {
            IconList[i] = IMG_ID_POC_CONTACT_URI + ImageLocation;
            ImageLocation++;
        }
    }

    ShowCategory57Screen(
        STR_ID_POC_GROUP_INFO,
        GetRootTitleIcon(MENU_ID_POC_MAIN),
        STR_GLOBAL_EDIT,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        POC_CALL_OTHERS_GROUP_INLINE_NUM,
        IconList,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_poc_entry_talk_groups_opt_call_others_group_cfrm, GoBackHistory);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_exit_talk_groups_opt_call_others_group
 * DESCRIPTION
 *  exit function for call others group screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_exit_talk_groups_opt_call_others_group(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_leading_zero(TRUE);
    GenericExitInlineScreen(SCR_ID_POC_TALK_GROUP_CALL_OTHERS_GROUP, mmi_poc_entry_talk_groups_opt_call_others_group);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_call_others_group_fill_inline_struct
 * DESCRIPTION
 *  fill inline structure
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_call_others_group_fill_inline_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 BufferSize = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_poc_cntx_p->talk_group_disp.invite_member_option[0] = (U8*) GetString(STR_GLOBAL_OFF);
    g_poc_cntx_p->talk_group_disp.invite_member_option[1] = (U8*) GetString(STR_GLOBAL_ON);

    SetInlineItemActivation((wgui_inline_items + POC_CALL_OTHERS_GROUP_URI), KEY_LSK, KEY_EVENT_UP);
    SetInlineItemActivation(
        (wgui_inline_items + POC_CALL_OTHERS_GROUP_INVITE_MEMBER),
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);

    SetInlineItemCaption((wgui_inline_items + POC_CALL_OTHERS_GROUP_URI_STR), (U8*) GetString(STR_ID_POC_URI));
    SetInlineItemCaption(
        (wgui_inline_items + POC_CALL_OTHERS_GROUP_INVITE_MEMBER_STR),
        (U8*) GetString(STR_ID_POC_INVITE_MEMBER));

    BufferSize = POC_MAX_URI_LEN - 1;

    SetInlineItemFullScreenEdit_ext(
        (wgui_inline_items + POC_CALL_OTHERS_GROUP_URI),
        STR_ID_POC_URI,
        GetRootTitleIcon(MENU_ID_POC_MAIN),
        (U8*) (g_poc_cntx_p->talk_group_disp.list_uri),
        BufferSize,
        (INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES),
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);

    SetInlineFullScreenEditCustomFunction(wgui_inline_items + POC_CALL_OTHERS_GROUP_URI, mmi_poc_entry_full_line_edit);

    SetInlineItemSelect(
        (wgui_inline_items + POC_CALL_OTHERS_GROUP_INVITE_MEMBER),
        (S32) POC_MAX_GROUP_TYPE_OPTION_NUM,
        (U8 **) g_poc_cntx_p->talk_group_disp.invite_member_option,
        (S32*) & g_poc_cntx_p->talk_group_disp.invite_member);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_entry_talk_groups_opt_call_others_group_cfrm
 * DESCRIPTION
 *  call other groups confirm screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_entry_talk_groups_opt_call_others_group_cfrm(void)
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
        get_string(STR_GLOBAL_DIAL),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_poc_call_others_group_req, KEY_EVENT_UP);
    SetRightSoftkeyFunction(poc_go_back_create_talk_group_add_contact, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_poc_call_others_group_req
 * DESCRIPTION
 *  call other groups request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_poc_call_others_group_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    poc_addr_struct callee[POC_MAX_ADDR_NUM];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_poc_cntx_p->call_status != POC_CALL_NONE)
    {
        MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POC_CALL_STATE, (S32) g_poc_cntx_p->call_status);
        DisplayPopup(
            (U8*) GetString(STR_ID_POC_ERR_TERMINATE_CALL_FIRST),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
        return;
    }

    g_poc_cntx_p->ptt_button_status = POC_PTT_DOWN;

    memset(g_poc_cntx_p->cm_talk_list, 0, sizeof(g_poc_cntx_p->cm_talk_list));
    memset(&g_poc_cntx_p->calling_disp, 0, sizeof(g_poc_cntx_p->calling_disp));

    g_poc_cntx_p->cm_talk_list_num = 0;

    mmi_ucs2_n_to_asc(
        (S8*) g_poc_cntx_p->calling_disp.uri,
        (S8*) g_poc_cntx_p->talk_group_disp.list_uri,
        POC_MAX_URI_LEN - 1);

    memset(callee, 0, sizeof(callee));

    mmi_ucs2_n_to_asc((S8*) callee[0].uri, (S8*) g_poc_cntx_p->talk_group_disp.list_uri, POC_MAX_URI_LEN - 1);

    memset(g_poc_cntx_p->cm_talk_group_name, 0, sizeof(g_poc_cntx_p->cm_talk_group_name));

    mmi_poc_entry_inviting();

    mmi_poc_ptt_release();

#ifdef __MMI_POC_REM_OTHERS_GROUP__
    memcpy(&g_poc_cntx_p->others_group_disp, &g_poc_cntx_p->talk_group_disp, sizeof(poc_talk_group_disp_struct));
#endif 

    if (g_poc_cntx_p->talk_group_disp.invite_member)
    {
        mmi_poc_talk_invite_req(POC_PRE_ARRANGED_GROUP_TALK, 1, callee, 0, 0, 0);
    }
    else
    {
        mmi_poc_talk_invite_req(POC_CHAT_GROUP_TALK, 1, callee, 0, 0, 0);
    }
}

#endif /* __MMI_POC__ */ 

