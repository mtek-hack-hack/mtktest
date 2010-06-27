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
 *  VoIPSetting.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Coding Template header file
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

#ifdef __MMI_VOIP__

#include "ProtocolEvents.h"
#include "CommonScreens.h"
#include "SettingProfile.h"
#include "custom_nvram_editor_data_item.h"
#include "custom_data_account.h"

#include "CallManagementGprot.h"
#include "DataAccountGProt.h"
#ifdef __MMI_TOUCH_SCREEN__
#include "gui_virtual_keyboard.h"
#endif

#include "VoIPResDef.h"
#include "VoIPGProt.h"
#include "VoIPProt.h"

extern MMI_BOOL voip_custom_get_p2p_call_state(void);

#ifdef __MMI_TOUCH_SCREEN__
gui_virtual_keyboard_pen_enum g_voip_disable_new_line[] = {GUI_VKBD_PEN_NEWLINE, GUI_VKBD_PEN_NONE};
#endif

const voip_codec_enum g_voip_codec_table[] = 
{
    VOIP_CODEC_AMR,
    VOIP_CODEC_G729,
    VOIP_CODEC_G7231,
    VOIP_CODEC_G726_16,
    VOIP_CODEC_G726_24,
    VOIP_CODEC_G726_32,
    VOIP_CODEC_G726_40,
    VOIP_CODEC_PCMA,
    VOIP_CODEC_PCMU,
    VOIP_CODEC_CN
};


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_highlight_main_menu
 * DESCRIPTION
 *  Highlight handler of Services\VoIP
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_highlight_main_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_voip_pre_entry_main_menu, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_voip_pre_entry_main_menu, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_highlight_status
 * DESCRIPTION
 *  Highlight handler of VoIP\Login(Logout)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_highlight_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_voip_entry_status, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_highlight_summary
 * DESCRIPTION
 *  Highlight handler of VoIP\Current Status
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_highlight_summary(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_voip_entry_summary, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_highlight_prof_setting
 * DESCRIPTION
 *  Highlight handler of VoIP\Profile Setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_highlight_prof_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_voip_entry_prof_setting, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_voip_entry_prof_setting, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_highlight_prof_setting_option_activate
 * DESCRIPTION
 *  Highlight handler of VoIP\Profile Setting\Profile X\Active
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_highlight_prof_setting_option_activate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_voip_entry_prof_activate, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_highlight_prof_setting_option_edit
 * DESCRIPTION
 *  Highlight handler of VoIP\Profile Setting\Profile X\Edit
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_highlight_prof_setting_option_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_voip_entry_prof_edit, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_voip_entry_prof_edit, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_highlight_prof_edit_common
 * DESCRIPTION
 *  Highlight handler of VoIP\Profile Setting\Profile X\Edit\Common Setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_highlight_prof_edit_common(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_voip_cntx_p->prof_setting_info.currScr = SCR_ID_VOIP_PROF_COMMON;

    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_voip_pre_entry_prof_edit_inlineitems, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_voip_pre_entry_prof_edit_inlineitems, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_highlight_prof_edit_account
 * DESCRIPTION
 *  Highlight handler of VoIP\Profile Setting\Profile X\Edit\Account Setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_highlight_prof_edit_account(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_voip_cntx_p->prof_setting_info.currScr = SCR_ID_VOIP_PROF_ACCOUNT;

    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_voip_entry_prof_edit_inlineitems, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_voip_pre_entry_prof_edit_inlineitems, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_highlight_prof_edit_outbound
 * DESCRIPTION
 *  Highlight handler of VoIP\Profile Setting\Profile X\Edit\Outbound Server
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_highlight_prof_edit_outbound(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_voip_cntx_p->prof_setting_info.currScr = SCR_ID_VOIP_PROF_OUTBOUND;

    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_voip_entry_prof_edit_inlineitems, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_voip_pre_entry_prof_edit_inlineitems, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_highlight_prof_edit_register
 * DESCRIPTION
 *  Highlight handler of VoIP\Profile Setting\Profile X\Edit\Register Server
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_highlight_prof_edit_register(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_voip_cntx_p->prof_setting_info.currScr = SCR_ID_VOIP_PROF_REGISTER;

    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_voip_entry_prof_edit_inlineitems, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_voip_pre_entry_prof_edit_inlineitems, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_highlight_prof_edit_nat
 * DESCRIPTION
 *  Highlight handler of VoIP\Profile Setting\Profile X\Edit\NAT Setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_highlight_prof_edit_nat(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_voip_cntx_p->prof_setting_info.currScr = SCR_ID_VOIP_PROF_NAT;

    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_voip_entry_prof_edit_inlineitems, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_voip_pre_entry_prof_edit_inlineitems, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_highlight_full_screen_editor
 * DESCRIPTION
 *  Highlight handler of full screen editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_highlight_full_screen_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_voip_entry_full_screen_editor_option, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
#ifdef __MMI_TOUCH_SCREEN__
    mmi_pen_editor_set_vk_keys(MMI_FALSE, NULL, g_voip_disable_new_line);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_highlight_done
 * DESCRIPTION
 *  Highlight handler of full screen editor\Option\Done
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_highlight_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(ConfirmInlineFullScreenEdit, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_highlight_input_method_in_menu
 * DESCRIPTION
 *  Highlight handler of full screen editor\Option\Input Method
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_highlight_input_method_in_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(EntryInputMethodScreen, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    RegisterInputMethodScreenCloseFunction(mmi_voip_go_back_2_history);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_highlight_call_setting
 * DESCRIPTION
 *  Highlight handler of VoIP\Call Setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_highlight_call_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_voip_entry_call_setting, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_voip_entry_call_setting, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_highlight_auto_answer
 * DESCRIPTION
 *  Highlight handler of VoIP\Call Setting\Auto Answer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_highlight_auto_answer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_voip_cntx_p->call_setting_info.currScr = SCR_ID_VOIP_SETTING_AUTO_ANSWER;
    g_voip_cntx_p->call_setting_info.currIndex = 0;

    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_voip_entry_setting_general, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_voip_entry_setting_general, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_highlight_auto_reject
 * DESCRIPTION
 *  Highlight handler of VoIP\Call Setting\Auto Reject
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_highlight_auto_reject(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_voip_cntx_p->call_setting_info.currScr = SCR_ID_VOIP_SETTING_AUTO_REJECT;
    g_voip_cntx_p->call_setting_info.currIndex = 0;

    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_voip_entry_setting_general, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_voip_entry_setting_general, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_highlight_auto_redial
 * DESCRIPTION
 *  Highlight handler of VoIP\Call Setting\Auto Redial
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_highlight_auto_redial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_voip_cntx_p->call_setting_info.currScr = SCR_ID_VOIP_SETTING_AUTO_REDIAL;
    g_voip_cntx_p->call_setting_info.currIndex = 0;

    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_voip_entry_setting_general, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_voip_entry_setting_general, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_highlight_hide_caller_id
 * DESCRIPTION
 *  Highlight handler of VoIP\Call Setting\Hide Caller ID
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_highlight_hide_caller_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_voip_cntx_p->call_setting_info.currScr = SCR_ID_VOIP_SETTING_HIDE_CALLER_ID;
    g_voip_cntx_p->call_setting_info.currIndex = 0;

    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_voip_entry_setting_general, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_voip_entry_setting_general, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_highlight_dtmf_in_menu
 * DESCRIPTION
 *  Highlight handler of VoIP\Call Setting\DTMF
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_highlight_dtmf_in_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_voip_cntx_p->call_setting_info.currScr = SCR_ID_VOIP_SETTING_DTMF;
    g_voip_cntx_p->call_setting_info.currIndex = 0;

    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_voip_entry_setting_general, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_voip_entry_setting_general, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_highlight_secure_rtp
 * DESCRIPTION
 *  Highlight handler of VoIP\Call Setting\Secure RTP
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_highlight_secure_rtp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_voip_cntx_p->call_setting_info.currScr = SCR_ID_VOIP_SETTING_SECURE_RTP;
    g_voip_cntx_p->call_setting_info.currIndex = 0;

    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_voip_entry_setting_general, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_voip_entry_setting_general, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_highlight_comfort_noise
 * DESCRIPTION
 *  Highlight handler of VoIP\Call Setting\Comfort Noise
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_highlight_comfort_noise(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_voip_cntx_p->call_setting_info.currScr = SCR_ID_VOIP_SETTING_COMFORT_NOISE;
    g_voip_cntx_p->call_setting_info.currIndex = 0;

    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_voip_entry_setting_general, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_voip_entry_setting_general, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_highlight_set_codec_order
 * DESCRIPTION
 *  Highlight handler of VoIP\Call Setting\Set Codec Order
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_highlight_set_codec_order(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_voip_cntx_p->call_setting_info.currScr = SCR_ID_VOIP_SETTING_SET_CODEC_ORDER;
    g_voip_cntx_p->call_setting_info.currIndex = 0;

    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_voip_entry_set_codec_order, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_voip_entry_set_codec_order, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_hint_auto_answer
 * DESCRIPTION
 *  Hint handler of VoIP\Call Setting\Auto Answer
 * PARAMETERS
 *  index       [IN]        Current selected index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_hint_auto_answer(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(hintData[index], 0, MAX_SUB_MENU_SIZE);

    if (g_voip_cntx_p->call_setting_info.saved_setting.autoAnswer == 0)
    {
        mmi_ucs2cpy((S8*)hintData[index], (S8*)GetString(STR_GLOBAL_OFF));
    }
    else if (g_voip_cntx_p->call_setting_info.saved_setting.autoAnswer == 1)
    {
        mmi_ucs2cpy((S8*)hintData[index], (S8*)GetString(STR_ID_VOIP_SETTING_ANYKEY));
    }
    else
    {
        mmi_ucs2cpy((S8*)hintData[index], (S8*)GetString(STR_ID_VOIP_SETTING_AUTO));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_hint_auto_reject
 * DESCRIPTION
 *  Hint handler of VoIP\Call Setting\Auto Reject
 * PARAMETERS
 *  index       [IN]        Current selected index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_hint_auto_reject(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(hintData[index], 0, MAX_SUB_MENU_SIZE);

    if (g_voip_cntx_p->call_setting_info.saved_setting.autoReject == 0)
    {
        mmi_ucs2cpy((S8*) hintData[index], (S8*) GetString(STR_GLOBAL_OFF));
    }
    else if (g_voip_cntx_p->call_setting_info.saved_setting.autoReject == 1)
    {
        mmi_ucs2cpy((S8*) hintData[index], (S8*) GetString(STR_ID_VOIP_SETTING_REJECT_UNKNOWN));
    }
    else
    {
        mmi_ucs2cpy((S8*) hintData[index], (S8*) GetString(STR_ID_VOIP_SETTING_REJECT_ALL));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_hint_auto_redial
 * DESCRIPTION
 *  Hint handler of VoIP\Call Setting\Auto Redial
 * PARAMETERS
 *  index       [IN]        Current selected index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_hint_auto_redial(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(hintData[index], 0, MAX_SUB_MENU_SIZE);

    if (g_voip_cntx_p->call_setting_info.saved_setting.autoRedial == 0)
    {
        mmi_ucs2cpy((S8*) hintData[index], (S8*) GetString(STR_GLOBAL_OFF));
    }
    else
    {
        mmi_ucs2cpy((S8*) hintData[index], (S8*) GetString(STR_GLOBAL_ON));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_hint_hide_caller_id
 * DESCRIPTION
 *  Hint handler of VoIP\Call Setting\Hide Caller ID
 * PARAMETERS
 *  index       [IN]        Current selected index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_hint_hide_caller_id(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(hintData[index], 0, MAX_SUB_MENU_SIZE);

    if (g_voip_cntx_p->call_setting_info.saved_setting.hidecallerId == 0)
    {
        mmi_ucs2cpy((S8*) hintData[index], (S8*) GetString(STR_GLOBAL_OFF));
    }
    else
    {
        mmi_ucs2cpy((S8*) hintData[index], (S8*) GetString(STR_GLOBAL_ON));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_hint_dtmf_in_menu
 * DESCRIPTION
 *  Hint handler of VoIP\Call Setting\DTMF
 * PARAMETERS
 *  index       [IN]        Current selected index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_hint_dtmf_in_menu(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(hintData[index], 0, MAX_SUB_MENU_SIZE);

    if (g_voip_cntx_p->call_setting_info.saved_setting.dtmf == VOIP_DTMF_IN_BAND)
    {
        mmi_ucs2cpy((S8*) hintData[index], (S8*) GetString(STR_ID_VOIP_SETTING_INBAND));
    }
    else if (g_voip_cntx_p->call_setting_info.saved_setting.dtmf == VOIP_DTMF_OUT_OF_BAND)
    {
        mmi_ucs2cpy((S8*) hintData[index], (S8*) GetString(STR_ID_VOIP_SETTING_OUTBAND));
    }
    else
    {
        mmi_ucs2cpy((S8*) hintData[index], (S8*) GetString(STR_GLOBAL_OFF));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_hint_secure_rtp
 * DESCRIPTION
 *  Hint handler of VoIP\Call Setting\Secure RTP
 * PARAMETERS
 *  index       [IN]        Current selected index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_hint_secure_rtp(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(hintData[index], 0, MAX_SUB_MENU_SIZE);

    if (g_voip_cntx_p->call_setting_info.saved_setting.srtp == 0)
    {
        mmi_ucs2cpy((S8*) hintData[index], (S8*) GetString(STR_GLOBAL_OFF));
    }
    else
    {
        mmi_ucs2cpy((S8*) hintData[index], (S8*) GetString(STR_GLOBAL_ON));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_hint_comfort_noise
 * DESCRIPTION
 *  Hint handler of VoIP\Call Setting\Comfort Noise
 * PARAMETERS
 *  index       [IN]        Current selected index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_hint_comfort_noise(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(hintData[index], 0, MAX_SUB_MENU_SIZE);

    if (g_voip_cntx_p->call_setting_info.saved_setting.comfortNoise == 0)
    {
        mmi_ucs2cpy((S8*) hintData[index], (S8*) GetString(STR_GLOBAL_ON));
    }
    else
    {
        mmi_ucs2cpy((S8*) hintData[index], (S8*) GetString(STR_GLOBAL_OFF));
    }
}


#ifdef SIP_CONFORMANCE_TEST
/*****************************************************************************
 * FUNCTION
 *  mmi_voip_highlight_option_query
 * DESCRIPTION
 *  Highlight handler of VoIP\Option Query
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_highlight_option_query(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_voip_cntx_p->call_misc_info.dispUri, 0, (VOIP_URI_LEN * ENCODING_LENGTH));
    memset(g_voip_cntx_p->call_misc_info.inputUri, 0, VOIP_URI_LEN);

    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_voip_entry_option_query, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}
#endif /* SIP_CONFORMANCE_TEST */


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_pre_entry_main_menu
 * DESCRIPTION
 *  Determine to go to VoIP main menu or not based on current state.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_pre_entry_main_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_voip_cntx_p->reg_state_info)
    {
        case MMI_VOIP_DEREG_STATE:
        case MMI_VOIP_REG_STATE:
            mmi_voip_entry_main_menu();
            break;
        case MMI_VOIP_PROCESS_STATE:
            mmi_voip_set_processing_parameter(
                STR_ID_VOIP_MAIN,
                STR_ID_VOIP_PROCESSING,
                IMG_GLOBAL_PROGRESS,
                0,
                0,
                STR_GLOBAL_BACK,
                GoBackHistory,
                0,
                DisplayIdleScreen);
            mmi_voip_entry_processing_screen();
            break;
        default:
            MMI_ASSERT(0);  /* unexpectedly go to MMI_VOIP_REG_STATE_TOTAL */
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_main_menu
 * DESCRIPTION
 *  Entry function of Services\VoIP
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_main_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 numItems = 0, i = 0;
    U16 nStrItemList[MAX_SUB_MENUS];    /* Login(Logout), Profile Setting, Call Setting, New Call */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsScreenPresent(SCR_ID_VOIP_PROCESSING))
    {
        HistoryReplace(SCR_ID_VOIP_PROCESSING, SCR_ID_VOIP_MAIN, mmi_voip_entry_main_menu);
        return;
    }

    EntryNewScreen(SCR_ID_VOIP_MAIN, NULL, mmi_voip_entry_main_menu, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_VOIP_MAIN);
    SetParentHandler(MENU_ID_VOIP_MAIN);
    if (g_voip_cntx_p->reg_state_info == MMI_VOIP_REG_STATE)
    {
        mmi_frm_hide_menu_item(MENU_ID_VOIP_PROF_SETTING);  /* hide profile setting menu if VoIP is login */
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_VOIP_PROF_SETTING);
    }
    numItems = GetNumOfChild_Ext(MENU_ID_VOIP_MAIN);
    GetSequenceStringIds_Ext(MENU_ID_VOIP_MAIN, nStrItemList);
    if (g_voip_cntx_p->reg_state_info == MMI_VOIP_REG_STATE)
    {
        for (i = 0; i < MAX_SUB_MENUS; i++)
        {
            if (nStrItemList[i] == STR_ID_VOIP_LOGIN)
            {
                nStrItemList[i] = STR_ID_VOIP_LOGOUT;   /* change login string to logout if VoIP is login */
            }
        }
    }
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ShowCategory52Screen(
        STR_ID_VOIP_MAIN,
        GetRootTitleIcon(MENU_ID_VOIP_MAIN),
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
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_status
 * DESCRIPTION
 *  Entry function of VoIP\Login(Logout)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_voip_cntx_p->prof_setting_info.actprofIndex == -1)
    {
        DisplayPopup(
            (U8*)GetString(STR_ID_VOIP_NO_ACTIVATED_PROFILE),
            IMG_GLOBAL_UNFINISHED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
        DeleteScreenIfPresent(SCR_ID_VOIP_CALL_EDITOR_OPTION);  /* go back to call editor screen */
        return;
    }

    switch (g_voip_cntx_p->reg_state_info)
    {
        case MMI_VOIP_DEREG_STATE:
            mmi_voip_set_processing_parameter(
                STR_ID_VOIP_LOGIN,
                STR_ID_VOIP_CONNECT_TO_SERVER,
                IMG_GLOBAL_PROGRESS,
                0,
                0,
                STR_GLOBAL_ABORT,
                mmi_voip_entry_abort_login,
                0,
                mmi_voip_entry_abort_login_endkey);
            mmi_voip_entry_processing_screen();
            mmi_voip_register_req();
            break;
        case MMI_VOIP_REG_STATE:
            mmi_voip_set_processing_parameter(
                STR_ID_VOIP_LOGOUT,
                STR_ID_VOIP_DISCONNECT_FROM_SERVER,
                IMG_GLOBAL_PROGRESS,
                0,
                0,
                STR_GLOBAL_BACK,
                mmi_voip_go_back_2_history,
                0,
                0);
            mmi_voip_entry_processing_screen();
            mmi_voip_deregister_req();
            break;
        case MMI_VOIP_PROCESS_STATE:
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_auto_login
 * DESCRIPTION
 *  Entry function when auto login timer expiry.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_auto_login(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 profIndex = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("\n[mmi_voip_entry_auto_login] Auto Login Timer Expiry\n");
    profIndex = g_voip_cntx_p->prof_setting_info.actprofIndex;
    if ((profIndex != -1) && (g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].comm_info.autoLogin == 1)) /* auto login */
    {
        if ((GetExitScrnID() >= SCR_ID_VOIP_PROCESSING) && (GetExitScrnID() <= SCR_ID_VOIP_FULL_EDITOR_OPTION))
        {
            PRINT_INFORMATION("\n[mmi_voip_entry_auto_login] VoIP Profile Related Screen, Cannot Auto Login\n");
            StartTimer(VOIP_AUTOLOGIN_TIMER, (MMI_VOIP_GENERAL_TIMEOUT * 10), mmi_voip_entry_auto_login);        
        }
        else if ((GetExitScrnID() >= SCR_ID_VOIP_MAIN) && (GetExitScrnID() <= SCR_ID_VOIP_TOTAL))
        {
            PRINT_INFORMATION("\n[mmi_voip_entry_auto_login] VoIP Related Screen, Processing Screen Must Show\n");
            mmi_voip_set_processing_parameter(
                STR_ID_VOIP_LOGIN,
                STR_ID_VOIP_CONNECT_TO_SERVER,
                IMG_GLOBAL_PROGRESS,
                0,
                0,
                STR_GLOBAL_ABORT,
                mmi_voip_entry_abort_login,
                0,
                mmi_voip_entry_abort_login_endkey);
            mmi_voip_entry_processing_screen();
            mmi_voip_register_req();      
        } 
        else /* outside of VoIP */
        {
            mmi_voip_register_req();
        }
    }
    else
    {
        PRINT_INFORMATION("\n[mmi_voip_entry_auto_login] Auto Login Setting Not Found\n");
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_abort_login
 * DESCRIPTION
 *  Entry function to abort login by RSK.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_abort_login(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_voip_set_processing_parameter(
        STR_GLOBAL_ABORT,
        STR_GLOBAL_ABORTING,
        IMG_GLOBAL_PROGRESS,
        0,
        0,
        STR_GLOBAL_BACK,
        mmi_voip_go_back_2_history,
        0,
        0);
    mmi_voip_entry_processing_screen();
    DeleteScreenIfPresent(SCR_ID_VOIP_PROCESSING);
    mmi_voip_deregister_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_abort_login_endkey
 * DESCRIPTION
 *  Entry function to abort login by END key.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_abort_login_endkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayIdleScreen();
    mmi_voip_deregister_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_summary
 * DESCRIPTION
 *  Entry function of VoIP\Current Status
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_summary(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VOIP_SUMMARY, NULL, NULL, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_VOIP_SUMMARY);
    memset(subMenuData, 0, (MAX_SUB_MENUS * MAX_SUB_MENU_SIZE));
    mmi_voip_get_summary_string((U8*)subMenuData);
    ShowCategory74Screen(
        STR_ID_VOIP_SUMMARY,
        GetRootTitleIcon(MENU_ID_VOIP_MAIN),
        0,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (U8*)subMenuData,
        MAX_SUB_MENUS * MAX_SUB_MENU_SIZE,
        guiBuffer);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_prof_setting
 * DESCRIPTION
 *  Entry function of VoIP\Profile Setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_prof_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    S32 i = 0;
    U8 *profileNames[MMI_VOIP_MAX_PROFILE_NUM];
    U16 iconList1[MMI_VOIP_MAX_PROFILE_NUM], iconList2[MMI_VOIP_MAX_PROFILE_NUM];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VOIP_PROF_SETTING, NULL, mmi_voip_entry_prof_setting, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_VOIP_PROF_SETTING);
    for (i = 0; i < MMI_VOIP_MAX_PROFILE_NUM; i++)
    {
        profileNames[i] = (U8*)g_voip_cntx_p->prof_setting_info.saved_prof[i].comm_info.profName;
        if (!mmi_ucs2strlen((S8*)profileNames[i]))
        {            
            profileNames[i] = (U8*)GetString(STR_ID_VOIP_PROF_COMMON_PROF1 + i);
        }
        iconList1[i] = 0; /* initialize profile activation icon */
        if (i == g_voip_cntx_p->prof_setting_info.actprofIndex)
        {
            iconList1[i] = IMG_VICON;
        }
        iconList2[i] = IMG_GLOBAL_L1 + i;
    }
    RegisterHighlightHandler(mmi_voip_highlight_prof_setting_item);
    ShowCategory73Screen(
        STR_ID_VOIP_PROF_SETTING,
        GetRootTitleIcon(MENU_ID_VOIP_MAIN),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        MMI_VOIP_MAX_PROFILE_NUM,
        profileNames,
        iconList1,
        iconList2,
        0,
        guiBuffer,
        ICON_ICON_TEXT);
    SetLeftSoftkeyFunction(mmi_voip_entry_prof_setting_option, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_voip_entry_prof_setting_option, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_highlight_prof_setting_item
 * DESCRIPTION
 *  Highlight index of selecting a profile in VoIP\Profile Setting
 * PARAMETERS
 *  index       [IN]        Current highlight index.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_highlight_prof_setting_item(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_voip_cntx_p->prof_setting_info.currprofIndex = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_prof_setting_option
 * DESCRIPTION
 *  Entry function of VoIP\Profile Setting\Option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_prof_setting_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U16 nStrItemList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VOIP_PROF_SETTING_OPTION, NULL, mmi_voip_entry_prof_setting_option, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_VOIP_PROF_SETTING_OPTION);
    SetParentHandler(MENU_ID_VOIP_PROF_SETTING_OPTION);
    numItems = GetNumOfChild(MENU_ID_VOIP_PROF_SETTING_OPTION);
    GetSequenceStringIds(MENU_ID_VOIP_PROF_SETTING_OPTION, nStrItemList);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_ID_VOIP_MAIN),
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
 *  mmi_voip_entry_prof_activate
 * DESCRIPTION
 *  Entry function of VoIP\Profile Setting\Profile X\Activate
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_prof_activate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 profIndex = g_voip_cntx_p->prof_setting_info.currprofIndex;
    U16 errorstrId = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    errorstrId = mmi_voip_prof_validate_activation(profIndex);
    if (errorstrId != 0)
    {
        DisplayPopup(
            (U8*)GetString(errorstrId), 
            IMG_GLOBAL_UNFINISHED, 
            1, 
            UI_POPUP_NOTIFYDURATION_TIME, 
            ERROR_TONE);
        return;
    }
    g_voip_cntx_p->prof_setting_info.actprofIndex = profIndex;
    mmi_voip_save_profile_active_index();
    DisplayPopup(
        (U8*)GetString(STR_GLOBAL_ACTIVATED),
        IMG_GLOBAL_ACTIVATED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        SUCCESS_TONE);
    DeleteScreenIfPresent(SCR_ID_VOIP_PROF_EDIT_INLINEITEMS);
    DeleteScreenIfPresent(SCR_ID_VOIP_PROF_EDIT);
    DeleteScreenIfPresent(SCR_ID_VOIP_PROF_SETTING_OPTION);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_prof_edit
 * DESCRIPTION
 *  Entry function of VoIP\Profile Setting\Profile X\Edit
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_prof_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U16 nStrItemList[MAX_SUB_MENUS];
    /* Common Setting, Account Setting, Outbound Server, Register Server, NAT Setting */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VOIP_PROF_EDIT, NULL, mmi_voip_entry_prof_edit, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_VOIP_PROF_EDIT);
    SetParentHandler(MENU_ID_VOIP_PROF_SETTING_OPTION_EDIT);
    numItems = GetNumOfChild(MENU_ID_VOIP_PROF_SETTING_OPTION_EDIT);
    GetSequenceStringIds(MENU_ID_VOIP_PROF_SETTING_OPTION_EDIT, nStrItemList);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ShowCategory52Screen(
        STR_GLOBAL_EDIT,
        GetRootTitleIcon(MENU_ID_VOIP_PROF_SETTING),
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
 *  mmi_voip_pre_entry_prof_edit_inlineitems
 * DESCRIPTION
 *  Pre-entry function of VoIP\Profile Setting\Profile X\Edit\Inline Editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_pre_entry_prof_edit_inlineitems(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DataAccountReadyCheck(mmi_voip_entry_prof_edit_inlineitems);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_prof_edit_inlineitems
 * DESCRIPTION
 *  Entry function of VoIP\Profile Setting\Profile X\Edit\Inline Editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_prof_edit_inlineitems(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 currScreen = g_voip_cntx_p->prof_setting_info.currScr;
    S32 profIndex = g_voip_cntx_p->prof_setting_info.currprofIndex;
    U8 *guiBuffer = NULL, *inputBuffer = NULL;
    U16 inputBufferSize = 0, titleId = 0, imgId = 0, numItems = 0;
    S32 i = 0;
    U16 iconList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VOIP_PROF_EDIT_INLINEITEMS, mmi_voip_exit_prof_edit_inlineitems, NULL, NULL);
    InitializeCategory57Screen();
    guiBuffer = GetCurrGuiBuffer(SCR_ID_VOIP_PROF_EDIT_INLINEITEMS);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_VOIP_PROF_EDIT_INLINEITEMS, &inputBufferSize);
    switch (currScreen)
    {
        case SCR_ID_VOIP_PROF_COMMON:
            if (inputBuffer == NULL)
            {
                mmi_voip_update_prof_common_cache_to_disp(profIndex);
            }
            titleId = STR_ID_VOIP_PROF_EDIT_COMMON;
            imgId = IMG_ID_VOIP_PROF_COMMON_PROF_NAME;
            numItems = mmi_voip_setup_prof_common_inlineitems();
            break;
        case SCR_ID_VOIP_PROF_ACCOUNT:
            if (inputBuffer == NULL)
            {
                mmi_voip_update_prof_acct_cache_to_disp(profIndex);
            }
            titleId = STR_ID_VOIP_PROF_EDIT_ACCOUNT;
            imgId = IMG_ID_VOIP_PROF_ACCOUNT_SIP_SERVER;
            numItems = mmi_voip_setup_prof_acct_inlineitems();
            break;
        case SCR_ID_VOIP_PROF_OUTBOUND:
            if (inputBuffer == NULL)
            {
                mmi_voip_update_prof_outbound_cache_to_disp(profIndex);
            }
            titleId = STR_ID_VOIP_PROF_EDIT_OUTBOUND;
            imgId = IMG_ID_VOIP_PROF_OUTBOUND_STATUS;
            numItems = mmi_voip_setup_prof_outbound_inlineitems();
            break;
        case SCR_ID_VOIP_PROF_REGISTER:
            if (inputBuffer == NULL)
            {
                mmi_voip_update_prof_register_cache_to_disp(profIndex);
            }
            titleId = STR_ID_VOIP_PROF_EDIT_REGISTER;
            imgId = IMG_ID_VOIP_PROF_REGISTER_STATUS;
            numItems = mmi_voip_setup_prof_register_inlineitems();
            break;
        case SCR_ID_VOIP_PROF_NAT:
            if (inputBuffer == NULL)
            {
                mmi_voip_update_prof_nat_cache_to_disp(profIndex);
            }
            titleId = STR_ID_VOIP_PROF_EDIT_NAT;
            imgId = IMG_ID_VOIP_PROF_NAT_STATUS;
            numItems = mmi_voip_setup_prof_nat_inlineitems();
            break;
        default:
            MMI_ASSERT(0);
    }
    for (i = 0; i < numItems; i++)
    {
        if (i % 2)
        {
            iconList[i] = 0;
        }
        else
        {
            iconList[i] = imgId + (i / 2);
        }
    }
    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, numItems, inputBuffer);
    }
    ShowCategory57Screen(
        titleId,
        GetRootTitleIcon(MENU_ID_VOIP_PROF_SETTING),
        STR_GLOBAL_EDIT,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        iconList,
        wgui_inline_items,
        0,
        guiBuffer);
    SetCategory57RightSoftkeyFunctions(mmi_voip_entry_prof_confirm, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_exit_prof_edit_inlineitems
 * DESCRIPTION
 *  Exit function of VoIP\Profile Setting\Profile X\Edit\Inline Editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_exit_prof_edit_inlineitems(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    U16 inputBuffSize = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    h.scrnID = SCR_ID_VOIP_PROF_EDIT_INLINEITEMS;
    h.entryFuncPtr = mmi_voip_entry_prof_edit_inlineitems;
    GetCategoryHistory(h.guiBuffer);
    GetCategory57Data(h.inputBuffer);
    inputBuffSize = (U16) GetCategory57DataSize();
    AddNHistory(h, inputBuffSize);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_update_prof_common_cache_to_disp
 * DESCRIPTION
 *  Copy g_voip_cntx_p->prof_setting_info.saved_prof[index] to
 *  g_voip_cntx_p->prof_setting_info.disp_prof for Common Setting.
 * PARAMETERS
 *  profIndex           [IN]            Index of intended to update profile
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_update_prof_common_cache_to_disp(S32 profIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Profile Name */
    memset(g_voip_cntx_p->prof_setting_info.disp_prof.profileName, 0, (MMI_VOIP_MAX_PROFILE_NAME_LEN * sizeof(U16)));
    mmi_ucs2ncpy(
        (S8*)g_voip_cntx_p->prof_setting_info.disp_prof.profileName,
        (S8*)g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].comm_info.profName,
        MMI_VOIP_MAX_PROFILE_NAME_LEN);
    if (!mmi_ucs2strlen((S8*)g_voip_cntx_p->prof_setting_info.disp_prof.profileName))
    {
        mmi_ucs2cpy(
            (S8*)g_voip_cntx_p->prof_setting_info.disp_prof.profileName,
            (S8*)GetString(STR_ID_VOIP_PROF_COMMON_PROF1 + profIndex));
        MMI_ASSERT(g_voip_cntx_p->prof_setting_info.disp_prof.profileName[MMI_VOIP_MAX_PROFILE_NAME_LEN - 1] == '\0');
    }
    
    /* Data Account */
    g_voip_cntx_p->prof_setting_info.disp_prof.dataacctIndex =
        g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].comm_info.dataAcct;

    /* Auto Login */
    g_voip_cntx_p->prof_setting_info.disp_prof.selectionIndex =
        g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].comm_info.autoLogin;

    /* Voice Mail Server */
    memset(g_voip_cntx_p->prof_setting_info.disp_prof.serverName, 0, (VOIP_URI_LEN * ENCODING_LENGTH));
    mmi_asc_n_to_ucs2(
        (S8*)g_voip_cntx_p->prof_setting_info.disp_prof.serverName,
        (S8*)g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].comm_info.vmServer,
        VOIP_URI_LEN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_update_prof_acct_cache_to_disp
 * DESCRIPTION
 *  Copy g_voip_cntx_p->prof_setting_info.saved_prof[index] to
 *  g_voip_cntx_p->prof_setting_info.disp_prof for Account Setting.
 * PARAMETERS
 *  profIndex           [IN]            Index of intended to update profile
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_update_prof_acct_cache_to_disp(S32 profIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* SIP Server */
    memset(g_voip_cntx_p->prof_setting_info.disp_prof.serverName, 0, (VOIP_URI_LEN * ENCODING_LENGTH));
    mmi_asc_n_to_ucs2(
        (S8*)g_voip_cntx_p->prof_setting_info.disp_prof.serverName,
        (S8*)g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].acct_info.sipServer,
        VOIP_URI_LEN);

    /* SIP Port */
    memset(g_voip_cntx_p->prof_setting_info.disp_prof.portNumber, 0, (MMI_VOIP_MAX_PORT_LEN * ENCODING_LENGTH));
    gui_itoa(
        g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].acct_info.sipPort,
        (UI_string_type)g_voip_cntx_p->prof_setting_info.disp_prof.portNumber,
        10);

    /* Display Name */
    memset(g_voip_cntx_p->prof_setting_info.disp_prof.displayName, 0, (VOIP_DISP_NAME_LEN * sizeof(U16)));
    mmi_ucs2ncpy(
        (S8*)g_voip_cntx_p->prof_setting_info.disp_prof.displayName,
        (S8*)g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].acct_info.dispName,
        VOIP_DISP_NAME_LEN);

    /* Username */
    memset(g_voip_cntx_p->prof_setting_info.disp_prof.username, 0, (VOIP_USERNAME_LEN * ENCODING_LENGTH));
    mmi_asc_n_to_ucs2(
        (S8*)g_voip_cntx_p->prof_setting_info.disp_prof.username,
        (S8*)g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].acct_info.username,
        VOIP_USERNAME_LEN);

    /* Password */
    memset(g_voip_cntx_p->prof_setting_info.disp_prof.password, 0, (VOIP_PASSWORD_LEN * ENCODING_LENGTH));
    mmi_asc_n_to_ucs2(
        (S8*)g_voip_cntx_p->prof_setting_info.disp_prof.password,
        (S8*)g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].acct_info.password,
        VOIP_PASSWORD_LEN);

    /* Authorization Name */
    memset(g_voip_cntx_p->prof_setting_info.disp_prof.authName, 0, (VOIP_USERNAME_LEN * ENCODING_LENGTH));
    mmi_asc_n_to_ucs2(
        (S8*)g_voip_cntx_p->prof_setting_info.disp_prof.authName,
        (S8*)g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].acct_info.authName,
        VOIP_USERNAME_LEN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_update_prof_outbound_cache_to_disp
 * DESCRIPTION
 *  Copy g_voip_cntx_p->prof_setting_info.saved_prof[index] to
 *  g_voip_cntx_p->prof_setting_info.disp_prof for Outbound Server.
 * PARAMETERS
 *  profIndex           [IN]            Index of intended to update profile
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_update_prof_outbound_cache_to_disp(S32 profIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Status */
    g_voip_cntx_p->prof_setting_info.disp_prof.selectionIndex =
        g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].out_server_info.status;

    /* Outbound Server */
    memset(g_voip_cntx_p->prof_setting_info.disp_prof.serverName, 0, (VOIP_URI_LEN * ENCODING_LENGTH));
    mmi_asc_n_to_ucs2(
        (S8*)g_voip_cntx_p->prof_setting_info.disp_prof.serverName,
        (S8*)g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].out_server_info.server,
        VOIP_URI_LEN);

    /* Outbound Port */
    memset(g_voip_cntx_p->prof_setting_info.disp_prof.portNumber, 0, (MMI_VOIP_MAX_PORT_LEN * ENCODING_LENGTH));
    gui_itoa(
        g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].out_server_info.port,
        (UI_string_type)g_voip_cntx_p->prof_setting_info.disp_prof.portNumber,
        10);

    /* Username */
    memset(g_voip_cntx_p->prof_setting_info.disp_prof.username, 0, (VOIP_USERNAME_LEN * ENCODING_LENGTH));
    mmi_asc_n_to_ucs2(
        (S8*)g_voip_cntx_p->prof_setting_info.disp_prof.username,
        (S8*)g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].out_server_info.username,
        VOIP_USERNAME_LEN);

    /* Password */
    memset(g_voip_cntx_p->prof_setting_info.disp_prof.password, 0, (VOIP_PASSWORD_LEN * ENCODING_LENGTH));
    mmi_asc_n_to_ucs2(
        (S8*)g_voip_cntx_p->prof_setting_info.disp_prof.password,
        (S8*)g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].out_server_info.password,
        VOIP_PASSWORD_LEN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_update_prof_register_cache_to_disp
 * DESCRIPTION
 *  Copy g_voip_cntx_p->prof_setting_info.saved_prof[index] to
 *  g_voip_cntx_p->prof_setting_info.disp_prof for Register Server.
 * PARAMETERS
 *  profIndex           [IN]            Index of intended to update profile
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_update_prof_register_cache_to_disp(S32 profIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Status */
    g_voip_cntx_p->prof_setting_info.disp_prof.selectionIndex =
        g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].reg_server_info.status;

    /* Register Server */
    memset(g_voip_cntx_p->prof_setting_info.disp_prof.serverName, 0, (VOIP_URI_LEN * ENCODING_LENGTH));
    mmi_asc_n_to_ucs2(
        (S8*)g_voip_cntx_p->prof_setting_info.disp_prof.serverName,
        (S8*)g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].reg_server_info.server,
        VOIP_URI_LEN);

    /* Register Port */
    memset(g_voip_cntx_p->prof_setting_info.disp_prof.portNumber, 0, (MMI_VOIP_MAX_PORT_LEN * ENCODING_LENGTH));
    gui_itoa(
        g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].reg_server_info.port,
        (UI_string_type)g_voip_cntx_p->prof_setting_info.disp_prof.portNumber,
        10);

    /* Username */
    memset(g_voip_cntx_p->prof_setting_info.disp_prof.username, 0, (VOIP_USERNAME_LEN * ENCODING_LENGTH));
    mmi_asc_n_to_ucs2(
        (S8*)g_voip_cntx_p->prof_setting_info.disp_prof.username,
        (S8*)g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].reg_server_info.username,
        VOIP_USERNAME_LEN);

    /* Password */
    memset(g_voip_cntx_p->prof_setting_info.disp_prof.password, 0, (VOIP_PASSWORD_LEN * ENCODING_LENGTH));
    mmi_asc_n_to_ucs2(
        (S8*)g_voip_cntx_p->prof_setting_info.disp_prof.password,
        (S8*)g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].reg_server_info.password,
        VOIP_PASSWORD_LEN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_update_prof_nat_cache_to_disp
 * DESCRIPTION
 *  Copy g_voip_cntx_p->prof_setting_info.saved_prof[index] to
 *  g_voip_cntx_p->prof_setting_info.disp_prof for NAT Setting.
 * PARAMETERS
 *  profIndex           [IN]            Index of intended to update profile
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_update_prof_nat_cache_to_disp(S32 profIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Status */
    g_voip_cntx_p->prof_setting_info.disp_prof.selectionIndex =
        g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].nat_info.natStatus;

    /* Firewall IP */
    memset(g_voip_cntx_p->prof_setting_info.disp_prof.ipAddr[0], 0, (MMI_VOIP_MAX_IP_SEG * ENCODING_LENGTH));
    memset(g_voip_cntx_p->prof_setting_info.disp_prof.ipAddr[1], 0, (MMI_VOIP_MAX_IP_SEG * ENCODING_LENGTH));
    memset(g_voip_cntx_p->prof_setting_info.disp_prof.ipAddr[2], 0, (MMI_VOIP_MAX_IP_SEG * ENCODING_LENGTH));
    memset(g_voip_cntx_p->prof_setting_info.disp_prof.ipAddr[3], 0, (MMI_VOIP_MAX_IP_SEG * ENCODING_LENGTH));
    
    if (g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].nat_info.natFirewall[0] == 0)
    {
        mmi_ucs2cpy((S8*)g_voip_cntx_p->prof_setting_info.disp_prof.ipAddr[0], (S8*)zeroIp);
        mmi_ucs2cpy((S8*)g_voip_cntx_p->prof_setting_info.disp_prof.ipAddr[1], (S8*)zeroIp);
        mmi_ucs2cpy((S8*)g_voip_cntx_p->prof_setting_info.disp_prof.ipAddr[2], (S8*)zeroIp);
        mmi_ucs2cpy((S8*)g_voip_cntx_p->prof_setting_info.disp_prof.ipAddr[3], (S8*)zeroIp);
    }
    else
    {
        gui_itoa(
            g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].nat_info.natFirewall[0],
            (UI_string_type)g_voip_cntx_p->prof_setting_info.disp_prof.ipAddr[0],
            10);
        gui_itoa(
            g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].nat_info.natFirewall[1],
            (UI_string_type)g_voip_cntx_p->prof_setting_info.disp_prof.ipAddr[1],
            10);
        gui_itoa(
            g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].nat_info.natFirewall[2],
            (UI_string_type)g_voip_cntx_p->prof_setting_info.disp_prof.ipAddr[2],
            10);
        gui_itoa(
            g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].nat_info.natFirewall[3],
            (UI_string_type)g_voip_cntx_p->prof_setting_info.disp_prof.ipAddr[3],
            10);
    }

    /* STUN Server */
    memset(g_voip_cntx_p->prof_setting_info.disp_prof.serverName, 0, (VOIP_URI_LEN * ENCODING_LENGTH));
    mmi_asc_n_to_ucs2(
        (S8*)g_voip_cntx_p->prof_setting_info.disp_prof.serverName,
        (S8*)g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].nat_info.stunServer,
        VOIP_URI_LEN);

    /* STUN Port */
    memset(g_voip_cntx_p->prof_setting_info.disp_prof.portNumber, 0, (MMI_VOIP_MAX_PORT_LEN * ENCODING_LENGTH));
    gui_itoa(
        g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].nat_info.stunPort,
        (UI_string_type)g_voip_cntx_p->prof_setting_info.disp_prof.portNumber,
        10);

    /* Refresh Interval */
    g_voip_cntx_p->prof_setting_info.disp_prof.intervalIndex =
        g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].nat_info.refInterval;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_update_prof_common_disp_to_cache
 * DESCRIPTION
 *  Copy g_voip_cntx_p->prof_setting_info.disp_prof to
 *  g_voip_cntx_p->prof_setting_info.saved_prof[index] for Common Setting.
 * PARAMETERS
 *  profIndex           [IN]            Index of intended to update profile
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_update_prof_common_disp_to_cache(S32 profIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Profile Name */
    memset(
        g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].comm_info.profName,
        0,
        (MMI_VOIP_MAX_PROFILE_NAME_LEN * sizeof(U16)));
    mmi_ucs2ncpy(
        (S8*) g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].comm_info.profName,
        (S8*) g_voip_cntx_p->prof_setting_info.disp_prof.profileName,
        MMI_VOIP_MAX_PROFILE_NAME_LEN);

    /* Data Account */
    g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].comm_info.dataAcct =
        g_voip_cntx_p->prof_setting_info.disp_prof.dataacctIndex;

    /* Auto Login */
    g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].comm_info.autoLogin =
        g_voip_cntx_p->prof_setting_info.disp_prof.selectionIndex;

    /* Voice Mail Server */
    memset(g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].comm_info.vmServer, 0, VOIP_URI_LEN);
    mmi_ucs2_n_to_asc(
        (S8*) g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].comm_info.vmServer,
        (S8*) g_voip_cntx_p->prof_setting_info.disp_prof.serverName,
        (VOIP_URI_LEN * ENCODING_LENGTH));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_update_prof_acct_disp_to_cache
 * DESCRIPTION
 *  Copy g_voip_cntx_p->prof_setting_info.disp_prof to
 *  g_voip_cntx_p->prof_setting_info.saved_prof[index] for Account Setting.
 * PARAMETERS
 *  profIndex           [IN]            Index of intended to update profile
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_update_prof_acct_disp_to_cache(S32 profIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* SIP Server */
    memset(g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].acct_info.sipServer, 0, VOIP_URI_LEN);
    mmi_ucs2_n_to_asc(
        (S8*) g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].acct_info.sipServer,
        (S8*) g_voip_cntx_p->prof_setting_info.disp_prof.serverName,
        (VOIP_URI_LEN * ENCODING_LENGTH));

    /* SIP Port */
    g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].acct_info.sipPort = gui_atoi((UI_string_type) g_voip_cntx_p->prof_setting_info.disp_prof.portNumber);

    /* Display Name */
    memset(
        g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].acct_info.dispName,
        0,
        (VOIP_DISP_NAME_LEN * sizeof(U16)));
    mmi_ucs2ncpy(
        (S8*) g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].acct_info.dispName,
        (S8*) g_voip_cntx_p->prof_setting_info.disp_prof.displayName,
        VOIP_DISP_NAME_LEN);

    /* Username */
    memset(g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].acct_info.username, 0, VOIP_USERNAME_LEN);
    mmi_ucs2_n_to_asc(
        (S8*) g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].acct_info.username,
        (S8*) g_voip_cntx_p->prof_setting_info.disp_prof.username,
        (VOIP_USERNAME_LEN * ENCODING_LENGTH));

    /* Password */
    memset(g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].acct_info.password, 0, VOIP_PASSWORD_LEN);
    mmi_ucs2_n_to_asc(
        (S8*) g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].acct_info.password,
        (S8*) g_voip_cntx_p->prof_setting_info.disp_prof.password,
        (VOIP_PASSWORD_LEN * ENCODING_LENGTH));

    /* Authorization Name */
    memset(g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].acct_info.authName, 0, VOIP_USERNAME_LEN);
    mmi_ucs2_n_to_asc(
        (S8*) g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].acct_info.authName,
        (S8*) g_voip_cntx_p->prof_setting_info.disp_prof.authName,
        (VOIP_USERNAME_LEN * ENCODING_LENGTH));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_update_prof_outbound_disp_to_cache
 * DESCRIPTION
 *  Copy g_voip_cntx_p->prof_setting_info.disp_prof to
 *  g_voip_cntx_p->prof_setting_info.saved_prof[index] for Outbound Server.
 * PARAMETERS
 *  profIndex           [IN]            Index of intended to update profile
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_update_prof_outbound_disp_to_cache(S32 profIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Status */
    g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].out_server_info.status =
        g_voip_cntx_p->prof_setting_info.disp_prof.selectionIndex;

    /* Outbound Server */
    memset(g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].out_server_info.server, 0, VOIP_URI_LEN);
    mmi_ucs2_n_to_asc(
        (S8*) g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].out_server_info.server,
        (S8*) g_voip_cntx_p->prof_setting_info.disp_prof.serverName,
        (VOIP_URI_LEN * ENCODING_LENGTH));

    /* Outbound Port */
    g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].out_server_info.port = gui_atoi((UI_string_type) g_voip_cntx_p->prof_setting_info.disp_prof.portNumber);

    /* Username */
    memset(g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].out_server_info.username, 0, VOIP_USERNAME_LEN);
    mmi_ucs2_n_to_asc(
        (S8*) g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].out_server_info.username,
        (S8*) g_voip_cntx_p->prof_setting_info.disp_prof.username,
        (VOIP_USERNAME_LEN * ENCODING_LENGTH));

    /* Password */
    memset(g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].out_server_info.password, 0, VOIP_PASSWORD_LEN);
    mmi_ucs2_n_to_asc(
        (S8*) g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].out_server_info.password,
        (S8*) g_voip_cntx_p->prof_setting_info.disp_prof.password,
        (VOIP_PASSWORD_LEN * ENCODING_LENGTH));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_update_prof_register_disp_to_cache
 * DESCRIPTION
 *  Copy g_voip_cntx_p->prof_setting_info.disp_prof to
 *  g_voip_cntx_p->prof_setting_info.saved_prof[index] for Register Server.
 * PARAMETERS
 *  profIndex           [IN]            Index of intended to update profile
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_update_prof_register_disp_to_cache(S32 profIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Status */
    g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].reg_server_info.status =
        g_voip_cntx_p->prof_setting_info.disp_prof.selectionIndex;

    /* Register Server */
    memset(g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].reg_server_info.server, 0, VOIP_URI_LEN);
    mmi_ucs2_n_to_asc(
        (S8*) g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].reg_server_info.server,
        (S8*) g_voip_cntx_p->prof_setting_info.disp_prof.serverName,
        (VOIP_URI_LEN * ENCODING_LENGTH));

    /* Register Port */
    g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].reg_server_info.port = gui_atoi((UI_string_type) g_voip_cntx_p->prof_setting_info.disp_prof.portNumber);

    /* Username */
    memset(g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].reg_server_info.username, 0, VOIP_USERNAME_LEN);
    mmi_ucs2_n_to_asc(
        (S8*) g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].reg_server_info.username,
        (S8*) g_voip_cntx_p->prof_setting_info.disp_prof.username,
        (VOIP_USERNAME_LEN * ENCODING_LENGTH));

    /* Password */
    memset(g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].reg_server_info.password, 0, VOIP_PASSWORD_LEN);
    mmi_ucs2_n_to_asc(
        (S8*) g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].reg_server_info.password,
        (S8*) g_voip_cntx_p->prof_setting_info.disp_prof.password,
        (VOIP_PASSWORD_LEN * ENCODING_LENGTH));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_update_prof_nat_disp_to_cache
 * DESCRIPTION
 *  Copy g_voip_cntx_p->prof_setting_info.disp_prof to
 *  g_voip_cntx_p->prof_setting_info.saved_prof[index] for NAT Setting.
 * PARAMETERS
 *  profIndex           [IN]            Index of intended to update profile
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_update_prof_nat_disp_to_cache(S32 profIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Status */
    g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].nat_info.natStatus =
        g_voip_cntx_p->prof_setting_info.disp_prof.selectionIndex;

    /* Firewall IP */
    g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].nat_info.natFirewall[0] = gui_atoi((UI_string_type) g_voip_cntx_p->prof_setting_info.disp_prof.ipAddr[0]);
    g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].nat_info.natFirewall[1] = gui_atoi((UI_string_type) g_voip_cntx_p->prof_setting_info.disp_prof.ipAddr[1]);
    g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].nat_info.natFirewall[2] = gui_atoi((UI_string_type) g_voip_cntx_p->prof_setting_info.disp_prof.ipAddr[2]);
    g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].nat_info.natFirewall[3] = gui_atoi((UI_string_type) g_voip_cntx_p->prof_setting_info.disp_prof.ipAddr[3]);

    /* STUN Server */
    memset(g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].nat_info.stunServer, 0, VOIP_URI_LEN);
    mmi_ucs2_n_to_asc(
        (S8*) g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].nat_info.stunServer,
        (S8*) g_voip_cntx_p->prof_setting_info.disp_prof.serverName,
        (VOIP_URI_LEN * ENCODING_LENGTH));

    /* STUN Port */
    g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].nat_info.stunPort = gui_atoi((UI_string_type) g_voip_cntx_p->prof_setting_info.disp_prof.portNumber);

    /* Refresh Interval */
    g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].nat_info.refInterval =
        g_voip_cntx_p->prof_setting_info.disp_prof.intervalIndex;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_setup_prof_common_inlineitems
 * DESCRIPTION
 *  Setup inline items for Common Setting.
 * PARAMETERS
 *  void
 * RETURNS
 *  Number of inline items used in Common Setting.
 *****************************************************************************/
S32 mmi_voip_setup_prof_common_inlineitems(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Profile Name caption */
    SetInlineItemCaption(
        wgui_inline_items + MMI_VOIP_PROF_COMMON_PROFNAME_CAP,
        (U8*) GetString(STR_ID_VOIP_PROF_COMMON_PROFNAME));

    /* Profile Name */
    SetInlineItemActivation(wgui_inline_items + MMI_VOIP_PROF_COMMON_PROFNAME, KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        wgui_inline_items + MMI_VOIP_PROF_COMMON_PROFNAME,
        STR_ID_VOIP_PROF_COMMON_PROFNAME,
        GetRootTitleIcon(MENU_ID_VOIP_MAIN),
        (U8*) g_voip_cntx_p->prof_setting_info.disp_prof.profileName,
        MMI_VOIP_MAX_PROFILE_NAME_LEN,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(
        wgui_inline_items + MMI_VOIP_PROF_COMMON_PROFNAME,
        mmi_voip_highlight_full_screen_editor);

    /* Data Account caption */
    SetInlineItemCaption(
        wgui_inline_items + MMI_VOIP_PROF_COMMON_DATAACCT_CAP,
        (U8*) GetString(STR_ID_VOIP_PROF_COMMON_DATAACCOUNT));

    /* Data Account */
    SetInlineItemActivation(wgui_inline_items + MMI_VOIP_PROF_COMMON_DATAACCT, KEY_LSK, KEY_EVENT_UP);
    memset(g_voip_cntx_p->prof_setting_info.disp_prof.dataacctName, 0, ((MAX_DATA_ACCOUNT_NAME_LEN + 1) * sizeof(U16)));
    mmi_dtcnt_get_account_name(
        g_voip_cntx_p->prof_setting_info.disp_prof.dataacctIndex,
        (S8*) g_voip_cntx_p->prof_setting_info.disp_prof.dataacctName,
        MAX_DATA_ACCOUNT_NAME_LEN);
    SetInlineItemImageText(
        wgui_inline_items + MMI_VOIP_PROF_COMMON_DATAACCT,
        (U8*) g_voip_cntx_p->prof_setting_info.disp_prof.dataacctName,
        0,
        0,
        0,
        MAX_DATA_ACCOUNT_NAME_LEN,
        0,
        0,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ENCODING_BASED_LENGTH);
    SetInlineFullScreenEditCustomFunctionImageText(
        wgui_inline_items + MMI_VOIP_PROF_COMMON_DATAACCT,
        mmi_voip_entry_prof_data_acct);
    ShowAsControl(wgui_inline_items + MMI_VOIP_PROF_COMMON_DATAACCT);

    /* Auto Login caption */
    SetInlineItemCaption(
        wgui_inline_items + MMI_VOIP_PROF_COMMON_AUTOLOGIN_CAP,
        (U8*) GetString(STR_ID_VOIP_PROF_COMMON_AUTOLOGIN));

    /* Auto Login */
    SetInlineItemActivation(
        wgui_inline_items + MMI_VOIP_PROF_COMMON_AUTOLOGIN,
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    g_voip_cntx_p->prof_setting_info.disp_prof.twoList[0] = (U8*) GetString(STR_GLOBAL_OFF);
    g_voip_cntx_p->prof_setting_info.disp_prof.twoList[1] = (U8*) GetString(STR_GLOBAL_ON);
    SetInlineItemSelect(
        wgui_inline_items + MMI_VOIP_PROF_COMMON_AUTOLOGIN,
        2,
        g_voip_cntx_p->prof_setting_info.disp_prof.twoList,
        &g_voip_cntx_p->prof_setting_info.disp_prof.selectionIndex);

    /* Voice Mail Server caption */
    SetInlineItemCaption(
        wgui_inline_items + MMI_VOIP_PROF_COMMON_VMSERVER_CAP,
        (U8*) GetString(STR_ID_VOIP_PROF_COMMON_VMSERVER));

    /* Voice Mail Server */
    SetInlineItemActivation(wgui_inline_items + MMI_VOIP_PROF_COMMON_VMSERVER, KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        wgui_inline_items + MMI_VOIP_PROF_COMMON_VMSERVER,
        STR_ID_VOIP_PROF_COMMON_VMSERVER,
        GetRootTitleIcon(MENU_ID_VOIP_MAIN),
        g_voip_cntx_p->prof_setting_info.disp_prof.serverName,
        VOIP_URI_LEN,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(
        wgui_inline_items + MMI_VOIP_PROF_COMMON_VMSERVER,
        mmi_voip_highlight_full_screen_editor);

    return MMI_VOIP_PROF_COMMON_INLINE_TOTAL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_setup_prof_acct_inlineitems
 * DESCRIPTION
 *  Setup inline items for Account Setting.
 * PARAMETERS
 *  void
 * RETURNS
 *  Number of inline items used in Account Setting.
 *****************************************************************************/
S32 mmi_voip_setup_prof_acct_inlineitems(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* SIP Server caption */
    SetInlineItemCaption(
        wgui_inline_items + MMI_VOIP_PROF_ACCT_SIPSERVER_CAP,
        (U8*) GetString(STR_ID_VOIP_PROF_ACCOUNT_SIPSERVER));

    /* SIP Server */
    SetInlineItemActivation(wgui_inline_items + MMI_VOIP_PROF_ACCT_SIPSERVER, KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        wgui_inline_items + MMI_VOIP_PROF_ACCT_SIPSERVER,
        STR_ID_VOIP_PROF_ACCOUNT_SIPSERVER,
        GetRootTitleIcon(MENU_ID_VOIP_MAIN),
        g_voip_cntx_p->prof_setting_info.disp_prof.serverName,
        VOIP_URI_LEN,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(
        wgui_inline_items + MMI_VOIP_PROF_ACCT_SIPSERVER,
        mmi_voip_highlight_full_screen_editor);

    /* SIP Port caption */
    SetInlineItemCaption(
        wgui_inline_items + MMI_VOIP_PROF_ACCT_SIPPORT_CAP,
        (U8*) GetString(STR_ID_VOIP_PROF_ACCOUNT_SIPPORT));

    /* SIP Port */
    SetInlineItemActivation(wgui_inline_items + MMI_VOIP_PROF_ACCT_SIPPORT, INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(
        wgui_inline_items + MMI_VOIP_PROF_ACCT_SIPPORT,
        g_voip_cntx_p->prof_setting_info.disp_prof.portNumber,
        MMI_VOIP_MAX_PORT_LEN,
        INPUT_TYPE_NUMERIC);
    RightJustifyInlineItem(wgui_inline_items + MMI_VOIP_PROF_ACCT_SIPPORT);
    EnableInlineItemBoundary(wgui_inline_items + MMI_VOIP_PROF_ACCT_SIPPORT);
    DisableInlineItemHighlight(wgui_inline_items + MMI_VOIP_PROF_ACCT_SIPPORT);
    /* EnableInlineItemDefaultText(); */
    SetInlineItemTextEditDefaultItemNameIfEmpty(
        wgui_inline_items + MMI_VOIP_PROF_ACCT_SIPPORT,
        STR_ID_VOIP_PROF_DEFAULT);

    /* Display Name caption */
    SetInlineItemCaption(
        wgui_inline_items + MMI_VOIP_PROF_ACCT_DISPNAME_CAP,
        (U8*) GetString(STR_ID_VOIP_PROF_ACCOUNT_DISPNAME));

    /* Display Name */
    SetInlineItemActivation(wgui_inline_items + MMI_VOIP_PROF_ACCT_DISPNAME, KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        wgui_inline_items + MMI_VOIP_PROF_ACCT_DISPNAME,
        STR_ID_VOIP_PROF_ACCOUNT_DISPNAME,
        GetRootTitleIcon(MENU_ID_VOIP_MAIN),
        (U8*) g_voip_cntx_p->prof_setting_info.disp_prof.displayName,
        VOIP_DISP_NAME_LEN,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(
        wgui_inline_items + MMI_VOIP_PROF_ACCT_DISPNAME,
        mmi_voip_highlight_full_screen_editor);

    /* Username caption */
    SetInlineItemCaption(
        wgui_inline_items + MMI_VOIP_PROF_ACCT_USERNAME_CAP,
        (U8*) GetString(STR_ID_VOIP_PROF_USERNAME));

    /* Username */
    SetInlineItemActivation(wgui_inline_items + MMI_VOIP_PROF_ACCT_USERNAME, KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        wgui_inline_items + MMI_VOIP_PROF_ACCT_USERNAME,
        STR_ID_VOIP_PROF_USERNAME,
        GetRootTitleIcon(MENU_ID_VOIP_MAIN),
        g_voip_cntx_p->prof_setting_info.disp_prof.username,
        VOIP_USERNAME_LEN,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(
        wgui_inline_items + MMI_VOIP_PROF_ACCT_USERNAME,
        mmi_voip_highlight_full_screen_editor);

    /* Password caption */
    SetInlineItemCaption(
        wgui_inline_items + MMI_VOIP_PROF_ACCT_PASSWORD_CAP,
        (U8*) GetString(STR_ID_VOIP_PROF_PASSWORD));

    /* Password */
    SetInlineItemActivation(wgui_inline_items + MMI_VOIP_PROF_ACCT_PASSWORD, KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        wgui_inline_items + MMI_VOIP_PROF_ACCT_PASSWORD,
        STR_ID_VOIP_PROF_PASSWORD,
        GetRootTitleIcon(MENU_ID_VOIP_MAIN),
        g_voip_cntx_p->prof_setting_info.disp_prof.password,
        VOIP_PASSWORD_LEN,
        INPUT_TYPE_ALPHANUMERIC_PASSWORD | INPUT_TYPE_USE_ONLY_ENGLISH_MODES,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(
        wgui_inline_items + MMI_VOIP_PROF_ACCT_PASSWORD,
        mmi_voip_highlight_full_screen_editor);

    /* Authorization Name caption */
    SetInlineItemCaption(
        wgui_inline_items + MMI_VOIP_PROF_ACCT_AUTHNAME_CAP,
        (U8*) GetString(STR_ID_VOIP_PROF_ACCOUNT_AUTHNAME));

    /* Authorization Name */
    SetInlineItemActivation(wgui_inline_items + MMI_VOIP_PROF_ACCT_AUTHNAME, KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        wgui_inline_items + MMI_VOIP_PROF_ACCT_AUTHNAME,
        STR_ID_VOIP_PROF_ACCOUNT_AUTHNAME,
        GetRootTitleIcon(MENU_ID_VOIP_MAIN),
        g_voip_cntx_p->prof_setting_info.disp_prof.authName,
        VOIP_USERNAME_LEN,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(
        wgui_inline_items + MMI_VOIP_PROF_ACCT_AUTHNAME,
        mmi_voip_highlight_full_screen_editor);

    return MMI_VOIP_PROF_ACCT_INLINE_TOTAL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_setup_prof_outbound_inlineitems
 * DESCRIPTION
 *  Setup inline items for Outbound Server.
 * PARAMETERS
 *  void
 * RETURNS
 *  Number of inline items used in Outbound Server.
 *****************************************************************************/
S32 mmi_voip_setup_prof_outbound_inlineitems(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Status caption */
    SetInlineItemCaption(
        wgui_inline_items + MMI_VOIP_PROF_OUTBOUND_STATUS_CAP,
        (U8*) GetString(STR_ID_VOIP_PROF_STATUS));

    /* Status */
    SetInlineItemActivation(
        wgui_inline_items + MMI_VOIP_PROF_OUTBOUND_STATUS,
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    g_voip_cntx_p->prof_setting_info.disp_prof.threeList[0] = (U8*) GetString(STR_ID_VOIP_PROF_OUTBOUND_NEVER);
    g_voip_cntx_p->prof_setting_info.disp_prof.threeList[1] = (U8*) GetString(STR_ID_VOIP_PROF_AUTO);
    g_voip_cntx_p->prof_setting_info.disp_prof.threeList[2] = (U8*) GetString(STR_ID_VOIP_PROF_OUTBOUND_ALWAYS);
    SetInlineItemSelect(
        wgui_inline_items + MMI_VOIP_PROF_OUTBOUND_STATUS,
        3,
        g_voip_cntx_p->prof_setting_info.disp_prof.threeList,
        &g_voip_cntx_p->prof_setting_info.disp_prof.selectionIndex);

    /* Outbound Server caption */
    SetInlineItemCaption(
        wgui_inline_items + MMI_VOIP_PROF_OUTBOUND_SERVER_CAP,
        (U8*) GetString(STR_ID_VOIP_PROF_OUTBOUND_SERVER));

    /* Outbound Server */
    SetInlineItemActivation(wgui_inline_items + MMI_VOIP_PROF_OUTBOUND_SERVER, KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        wgui_inline_items + MMI_VOIP_PROF_OUTBOUND_SERVER,
        STR_ID_VOIP_PROF_OUTBOUND_SERVER,
        GetRootTitleIcon(MENU_ID_VOIP_MAIN),
        g_voip_cntx_p->prof_setting_info.disp_prof.serverName,
        VOIP_URI_LEN,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(
        wgui_inline_items + MMI_VOIP_PROF_OUTBOUND_SERVER,
        mmi_voip_highlight_full_screen_editor);

    /* Outbound Port caption */
    SetInlineItemCaption(
        wgui_inline_items + MMI_VOIP_PROF_OUTBOUND_PORT_CAP,
        (U8*) GetString(STR_ID_VOIP_PROF_OUTBOUND_PORT));

    /* Outbound Port */
    SetInlineItemActivation(wgui_inline_items + MMI_VOIP_PROF_OUTBOUND_PORT, INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(
        wgui_inline_items + MMI_VOIP_PROF_OUTBOUND_PORT,
        g_voip_cntx_p->prof_setting_info.disp_prof.portNumber,
        MMI_VOIP_MAX_PORT_LEN,
        INPUT_TYPE_NUMERIC);
    RightJustifyInlineItem(wgui_inline_items + MMI_VOIP_PROF_OUTBOUND_PORT);
    EnableInlineItemBoundary(wgui_inline_items + MMI_VOIP_PROF_OUTBOUND_PORT);
    DisableInlineItemHighlight(wgui_inline_items + MMI_VOIP_PROF_OUTBOUND_PORT);
    /* EnableInlineItemDefaultText(); */
    SetInlineItemTextEditDefaultItemNameIfEmpty(
        wgui_inline_items + MMI_VOIP_PROF_OUTBOUND_PORT,
        STR_ID_VOIP_PROF_DEFAULT);

    /* Username caption */
    SetInlineItemCaption(
        wgui_inline_items + MMI_VOIP_PROF_OUTBOUND_USERNAME_CAP,
        (U8*) GetString(STR_ID_VOIP_PROF_ACCOUNT_AUTHNAME));

    /* Username */
    SetInlineItemActivation(wgui_inline_items + MMI_VOIP_PROF_OUTBOUND_USERNAME, KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        wgui_inline_items + MMI_VOIP_PROF_OUTBOUND_USERNAME,
        STR_ID_VOIP_PROF_ACCOUNT_AUTHNAME,
        GetRootTitleIcon(MENU_ID_VOIP_MAIN),
        g_voip_cntx_p->prof_setting_info.disp_prof.username,
        VOIP_USERNAME_LEN,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(
        wgui_inline_items + MMI_VOIP_PROF_OUTBOUND_USERNAME,
        mmi_voip_highlight_full_screen_editor);

    /* Password caption */
    SetInlineItemCaption(
        wgui_inline_items + MMI_VOIP_PROF_OUTBOUND_PASSWORD_CAP,
        (U8*) GetString(STR_ID_VOIP_PROF_PASSWORD));

    /* Password */
    SetInlineItemActivation(wgui_inline_items + MMI_VOIP_PROF_OUTBOUND_PASSWORD, KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        wgui_inline_items + MMI_VOIP_PROF_OUTBOUND_PASSWORD,
        STR_ID_VOIP_PROF_PASSWORD,
        GetRootTitleIcon(MENU_ID_VOIP_MAIN),
        g_voip_cntx_p->prof_setting_info.disp_prof.password,
        VOIP_PASSWORD_LEN,
        INPUT_TYPE_ALPHANUMERIC_PASSWORD | INPUT_TYPE_USE_ONLY_ENGLISH_MODES,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(
        wgui_inline_items + MMI_VOIP_PROF_OUTBOUND_PASSWORD,
        mmi_voip_highlight_full_screen_editor);

    return MMI_VOIP_PROF_OUTBOUND_INLINE_TOTAL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_setup_prof_register_inlineitems
 * DESCRIPTION
 *  Setup inline items for Register Server.
 * PARAMETERS
 *  void
 * RETURNS
 *  Number of inline items used in Register Server.
 *****************************************************************************/
S32 mmi_voip_setup_prof_register_inlineitems(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Status caption */
    SetInlineItemCaption(
        wgui_inline_items + MMI_VOIP_PROF_REGISTER_STATUS_CAP,
        (U8*) GetString(STR_ID_VOIP_PROF_STATUS));

    /* Status */
    SetInlineItemActivation(
        wgui_inline_items + MMI_VOIP_PROF_REGISTER_STATUS,
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    g_voip_cntx_p->prof_setting_info.disp_prof.twoList[0] = (U8*) GetString(STR_GLOBAL_OFF);
    g_voip_cntx_p->prof_setting_info.disp_prof.twoList[1] = (U8*) GetString(STR_GLOBAL_ON);
    SetInlineItemSelect(
        wgui_inline_items + MMI_VOIP_PROF_REGISTER_STATUS,
        2,
        g_voip_cntx_p->prof_setting_info.disp_prof.twoList,
        &g_voip_cntx_p->prof_setting_info.disp_prof.selectionIndex);

    /* Register Server caption */
    SetInlineItemCaption(
        wgui_inline_items + MMI_VOIP_PROF_REGISTER_SERVER_CAP,
        (U8*) GetString(STR_ID_VOIP_PROF_REGISTER_SERVER));

    /* Register Server */
    SetInlineItemActivation(wgui_inline_items + MMI_VOIP_PROF_REGISTER_SERVER, KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        wgui_inline_items + MMI_VOIP_PROF_REGISTER_SERVER,
        STR_ID_VOIP_PROF_REGISTER_SERVER,
        GetRootTitleIcon(MENU_ID_VOIP_MAIN),
        g_voip_cntx_p->prof_setting_info.disp_prof.serverName,
        VOIP_URI_LEN,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(
        wgui_inline_items + MMI_VOIP_PROF_REGISTER_SERVER,
        mmi_voip_highlight_full_screen_editor);

    /* Register Port caption */
    SetInlineItemCaption(
        wgui_inline_items + MMI_VOIP_PROF_REGISTER_PORT_CAP,
        (U8*) GetString(STR_ID_VOIP_PROF_REGISTER_PORT));

    /* Register Port */
    SetInlineItemActivation(wgui_inline_items + MMI_VOIP_PROF_REGISTER_PORT, INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(
        wgui_inline_items + MMI_VOIP_PROF_REGISTER_PORT,
        g_voip_cntx_p->prof_setting_info.disp_prof.portNumber,
        MMI_VOIP_MAX_PORT_LEN,
        INPUT_TYPE_NUMERIC);
    RightJustifyInlineItem(wgui_inline_items + MMI_VOIP_PROF_REGISTER_PORT);
    EnableInlineItemBoundary(wgui_inline_items + MMI_VOIP_PROF_REGISTER_PORT);
    DisableInlineItemHighlight(wgui_inline_items + MMI_VOIP_PROF_REGISTER_PORT);
    /* EnableInlineItemDefaultText(); */
    SetInlineItemTextEditDefaultItemNameIfEmpty(
        wgui_inline_items + MMI_VOIP_PROF_REGISTER_PORT,
        STR_ID_VOIP_PROF_DEFAULT);

    /* Username caption */
    SetInlineItemCaption(
        wgui_inline_items + MMI_VOIP_PROF_REGISTER_USERNAME_CAP,
        (U8*) GetString(STR_ID_VOIP_PROF_ACCOUNT_AUTHNAME));

    /* Username */
    SetInlineItemActivation(wgui_inline_items + MMI_VOIP_PROF_REGISTER_USERNAME, KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        wgui_inline_items + MMI_VOIP_PROF_REGISTER_USERNAME,
        STR_ID_VOIP_PROF_ACCOUNT_AUTHNAME,
        GetRootTitleIcon(MENU_ID_VOIP_MAIN),
        g_voip_cntx_p->prof_setting_info.disp_prof.username,
        VOIP_USERNAME_LEN,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(
        wgui_inline_items + MMI_VOIP_PROF_REGISTER_USERNAME,
        mmi_voip_highlight_full_screen_editor);

    /* Password caption */
    SetInlineItemCaption(
        wgui_inline_items + MMI_VOIP_PROF_REGISTER_PASSWORD_CAP,
        (U8*) GetString(STR_ID_VOIP_PROF_PASSWORD));

    /* Password */
    SetInlineItemActivation(wgui_inline_items + MMI_VOIP_PROF_REGISTER_PASSWORD, KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        wgui_inline_items + MMI_VOIP_PROF_REGISTER_PASSWORD,
        STR_ID_VOIP_PROF_PASSWORD,
        GetRootTitleIcon(MENU_ID_VOIP_MAIN),
        g_voip_cntx_p->prof_setting_info.disp_prof.password,
        VOIP_PASSWORD_LEN,
        INPUT_TYPE_ALPHANUMERIC_PASSWORD | INPUT_TYPE_USE_ONLY_ENGLISH_MODES,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(
        wgui_inline_items + MMI_VOIP_PROF_REGISTER_PASSWORD,
        mmi_voip_highlight_full_screen_editor);

    return MMI_VOIP_PROF_REGISTER_INLINE_TOTAL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_setup_prof_nat_inlineitems
 * DESCRIPTION
 *  Setup inline items for NAT Setting.
 * PARAMETERS
 *  void
 * RETURNS
 *  Number of inline items used in NAT Setting.
 *****************************************************************************/
S32 mmi_voip_setup_prof_nat_inlineitems(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Status caption */
    SetInlineItemCaption(wgui_inline_items + MMI_VOIP_PROF_NAT_STATUS_CAP, (U8*) GetString(STR_ID_VOIP_PROF_STATUS));

    /* Status */
    SetInlineItemActivation(wgui_inline_items + MMI_VOIP_PROF_NAT_STATUS, INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    g_voip_cntx_p->prof_setting_info.disp_prof.threeList[0] = (U8*) GetString(STR_GLOBAL_OFF);
    g_voip_cntx_p->prof_setting_info.disp_prof.threeList[1] = (U8*) GetString(STR_ID_VOIP_PROF_NAT_STATICNAT);
    g_voip_cntx_p->prof_setting_info.disp_prof.threeList[2] = (U8*) GetString(STR_ID_VOIP_PROF_NAT_STUNSERVER);
    SetInlineItemSelect(
        wgui_inline_items + MMI_VOIP_PROF_NAT_STATUS,
        3,
        g_voip_cntx_p->prof_setting_info.disp_prof.threeList,
        &g_voip_cntx_p->prof_setting_info.disp_prof.selectionIndex);

    /* NAT Firewall IP caption */
    SetInlineItemCaption(
        wgui_inline_items + MMI_VOIP_PROF_NAT_FIREWALL_CAP,
        (U8*) GetString(STR_ID_VOIP_PROF_NAT_FIREWALL));

    /* NAT Firewall IP */
    SetInlineItemActivation(wgui_inline_items + MMI_VOIP_PROF_NAT_FIREWALL, INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemIP4(
        wgui_inline_items + MMI_VOIP_PROF_NAT_FIREWALL,
        g_voip_cntx_p->prof_setting_info.disp_prof.ipAddr[0],
        g_voip_cntx_p->prof_setting_info.disp_prof.ipAddr[1],
        g_voip_cntx_p->prof_setting_info.disp_prof.ipAddr[2],
        g_voip_cntx_p->prof_setting_info.disp_prof.ipAddr[3],
        mmi_voip_prof_ip_addr_convert);

    /* STUN Server caption */
    SetInlineItemCaption(
        wgui_inline_items + MMI_VOIP_PROF_NAT_STUNSERVER_CAP,
        (U8*) GetString(STR_ID_VOIP_PROF_NAT_STUNSERVER));

    /* STUN Server */
    SetInlineItemActivation(wgui_inline_items + MMI_VOIP_PROF_NAT_STUNSERVER, KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        wgui_inline_items + MMI_VOIP_PROF_NAT_STUNSERVER,
        STR_ID_VOIP_PROF_NAT_STUNSERVER,
        GetRootTitleIcon(MENU_ID_VOIP_MAIN),
        g_voip_cntx_p->prof_setting_info.disp_prof.serverName,
        VOIP_URI_LEN,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(
        wgui_inline_items + MMI_VOIP_PROF_NAT_STUNSERVER,
        mmi_voip_highlight_full_screen_editor);

    /* STUN Port caption */
    SetInlineItemCaption(
        wgui_inline_items + MMI_VOIP_PROF_NAT_STUNPORT_CAP,
        (U8*) GetString(STR_ID_VOIP_PROF_NAT_STUNPORT));

    /* STUN Port */
    SetInlineItemActivation(wgui_inline_items + MMI_VOIP_PROF_NAT_STUNPORT, INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(
        wgui_inline_items + MMI_VOIP_PROF_NAT_STUNPORT,
        g_voip_cntx_p->prof_setting_info.disp_prof.portNumber,
        MMI_VOIP_MAX_PORT_LEN,
        INPUT_TYPE_NUMERIC);
    RightJustifyInlineItem(wgui_inline_items + MMI_VOIP_PROF_NAT_STUNPORT);
    EnableInlineItemBoundary(wgui_inline_items + MMI_VOIP_PROF_NAT_STUNPORT);
    DisableInlineItemHighlight(wgui_inline_items + MMI_VOIP_PROF_NAT_STUNPORT);
    /* EnableInlineItemDefaultText(); */
    SetInlineItemTextEditDefaultItemNameIfEmpty(
        wgui_inline_items + MMI_VOIP_PROF_NAT_STUNPORT,
        STR_ID_VOIP_PROF_DEFAULT);

    /* NAT Refresh Interval caption */
    SetInlineItemCaption(
        wgui_inline_items + MMI_VOIP_PROF_NAT_INTERVAL_CAP,
        (U8*) GetString(STR_ID_VOIP_PROF_NAT_INTERVAL));

    /* NAT Refresh Interval */
    SetInlineItemActivation(wgui_inline_items + MMI_VOIP_PROF_NAT_INTERVAL, INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    g_voip_cntx_p->prof_setting_info.disp_prof.fiveList[0] = (U8*) GetString(STR_ID_VOIP_PROF_AUTO);
    g_voip_cntx_p->prof_setting_info.disp_prof.fiveList[1] = (U8*) GetString(STR_ID_VOIP_PROF_NAT_9SEC);
    g_voip_cntx_p->prof_setting_info.disp_prof.fiveList[2] = (U8*) GetString(STR_ID_VOIP_PROF_NAT_15SEC);
    g_voip_cntx_p->prof_setting_info.disp_prof.fiveList[3] = (U8*) GetString(STR_ID_VOIP_PROF_NAT_30SEC);
    g_voip_cntx_p->prof_setting_info.disp_prof.fiveList[4] = (U8*) GetString(STR_ID_VOIP_PROF_NAT_60SEC);
    SetInlineItemSelect(
        wgui_inline_items + MMI_VOIP_PROF_NAT_INTERVAL,
        5,
        g_voip_cntx_p->prof_setting_info.disp_prof.fiveList,
        &g_voip_cntx_p->prof_setting_info.disp_prof.intervalIndex);

    return MMI_VOIP_PROF_NAT_INLINE_TOTAL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_full_screen_editor_option
 * DESCRIPTION
 *  Entry function of full screen editor\Option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_full_screen_editor_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U16 nStrItemList[MAX_SUB_MENUS];    /* Done, Input Method */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VOIP_FULL_EDITOR_OPTION, NULL, mmi_voip_entry_full_screen_editor_option, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_VOIP_FULL_EDITOR_OPTION);
    SetParentHandler(MENU_ID_VOIP_FULL_EDITOR_OPTION);
    numItems = GetNumOfChild(MENU_ID_VOIP_FULL_EDITOR_OPTION);
    GetSequenceStringIds(MENU_ID_VOIP_FULL_EDITOR_OPTION, nStrItemList);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_ID_VOIP_MAIN),
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
 *  mmi_voip_entry_prof_data_acct
 * DESCRIPTION
 *  Entry function of data account
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_prof_data_acct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_dtcnt_select_account(mmi_voip_prof_data_acct_callback, MENU_ID_VOIP_MAIN, DATA_ACCOUNT_BEARER_PS_ONLY);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_prof_data_acct_callback
 * DESCRIPTION
 *  Callback function for data account selection
 * PARAMETERS
 *  index           [IN]            Selected index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_prof_data_acct_callback(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_voip_cntx_p->prof_setting_info.disp_prof.dataacctIndex = index;
    DeleteUptoScrID(SCR_ID_VOIP_PROF_EDIT_INLINEITEMS);
    GoBackHistory();
    SetInlineListMenuChanged();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_prof_ip_addr_convert
 * DESCRIPTION
 *  Convert ip format to ip string.
 * PARAMETERS
 *  ipStr           [IN/OUT]        Ip string in unicode
 *  ip1             [IN]            First number in the ip format
 *  ip2             [IN]            Second number in the ip format
 *  ip3             [IN]            Third number in the ip format
 *  ip4             [IN]            Fourth number in the ip format
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_prof_ip_addr_convert(U8 *ipStr, U8 *ip1, U8 *ip2, U8 *ip3, U8 *ip4)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 dot[4];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_to_ucs2((S8*) dot, (S8*) ".");

    mmi_ucs2cpy((S8*) ipStr, (S8*) ip1);
    mmi_ucs2cat((S8*) ipStr, (S8*) dot);
    mmi_ucs2cat((S8*) ipStr, (S8*) ip2);
    mmi_ucs2cat((S8*) ipStr, (S8*) dot);
    mmi_ucs2cat((S8*) ipStr, (S8*) ip3);
    mmi_ucs2cat((S8*) ipStr, (S8*) dot);
    mmi_ucs2cat((S8*) ipStr, (S8*) ip4);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_prof_validate_activation
 * DESCRIPTION
 *  The profile can be activated only if SIP server and username are not empty.
 * PARAMETERS
 *  profIndex           [IN]            Index of profile
 * RETURNS
 *  String id of the error.
 *****************************************************************************/
U16 mmi_voip_prof_validate_activation(S32 profIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 errorstrId = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (voip_custom_get_p2p_call_state() == FALSE)
    {
        if (!strlen((S8*) g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].acct_info.sipServer))
        {
            errorstrId = STR_ID_VOIP_EMPTY_SIP_SERVER;
        }
        if (!strlen((S8*) g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].acct_info.username))
        {
            errorstrId = STR_ID_VOIP_EMPTY_USERNAME;
        }
    }
    else    /* p2p is on in the engineering mode */
    {
        if (!strlen((S8*) g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].acct_info.username))
        {
            errorstrId = STR_ID_VOIP_EMPTY_USERNAME;
        }
    }
    return errorstrId;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_prof_validate_inputs
 * DESCRIPTION
 *  Check if the input is valid based on the current screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  String id of the error.
 *****************************************************************************/
U16 mmi_voip_prof_validate_inputs(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 currScreen = g_voip_cntx_p->prof_setting_info.currScr;
    U16 errorstrId = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (currScreen)
    {
        case SCR_ID_VOIP_PROF_COMMON:
            /* validate profile name */
            if (!mmi_ucs2strlen((S8*)g_voip_cntx_p->prof_setting_info.disp_prof.profileName))
            {
                errorstrId = STR_ID_VOIP_EMPTY_PROFILE_NAME;
            }

            /* validate voice mail server */
            if (mmi_voip_validate_uri(g_voip_cntx_p->prof_setting_info.disp_prof.serverName) == FALSE)
            {
                errorstrId = STR_ID_VOIP_INVALID_VM_SERVER;
            }
            break;
        case SCR_ID_VOIP_PROF_ACCOUNT:
            if (voip_custom_get_p2p_call_state() == FALSE)
            {
                /* validate sip server */
                if ((g_voip_cntx_p->prof_setting_info.actprofIndex == g_voip_cntx_p->prof_setting_info.currprofIndex) &&
                    (!mmi_ucs2strlen((S8*)g_voip_cntx_p->prof_setting_info.disp_prof.serverName)))
                {
                    errorstrId = STR_ID_VOIP_EMPTY_SIP_SERVER;
                }

                /* validate port number */
                if (!mmi_ucs2strlen((S8*)g_voip_cntx_p->prof_setting_info.disp_prof.portNumber))
                {
                    gui_itoa(0, (UI_string_type)g_voip_cntx_p->prof_setting_info.disp_prof.portNumber, 10);
                }
                else
                {
                    if (mmi_voip_validate_port(g_voip_cntx_p->prof_setting_info.disp_prof.portNumber) == FALSE)
                    {
                        errorstrId = STR_ID_VOIP_INVALID_PORT_NUMBER;
                    }
                }

                /* validate username */
                if ((g_voip_cntx_p->prof_setting_info.actprofIndex == g_voip_cntx_p->prof_setting_info.currprofIndex) &&
                    (!mmi_ucs2strlen((S8*)g_voip_cntx_p->prof_setting_info.disp_prof.username)))
                {
                    errorstrId = STR_ID_VOIP_EMPTY_USERNAME;
                }
                else
                {
                    if (mmi_voip_validate_uri(g_voip_cntx_p->prof_setting_info.disp_prof.username) == FALSE)
                    {
                        errorstrId = STR_ID_VOIP_INVALID_USERNAME;
                    }
                }
            }
            else    /* p2p is on in the engineering mode */
            {
                /* validate username */
                if ((g_voip_cntx_p->prof_setting_info.actprofIndex == g_voip_cntx_p->prof_setting_info.currprofIndex) &&
                    (!mmi_ucs2strlen((S8*)g_voip_cntx_p->prof_setting_info.disp_prof.username)))
                {
                    errorstrId = STR_ID_VOIP_EMPTY_USERNAME;
                }
                else
                {
                    if (mmi_voip_validate_uri(g_voip_cntx_p->prof_setting_info.disp_prof.username) == FALSE)
                    {
                        errorstrId = STR_ID_VOIP_INVALID_USERNAME;
                    }
                }
            }
            break;
        case SCR_ID_VOIP_PROF_OUTBOUND:
            /* validate outbound server */
            if (((g_voip_cntx_p->prof_setting_info.disp_prof.selectionIndex == 1) || 
                 (g_voip_cntx_p->prof_setting_info.disp_prof.selectionIndex == 2)) &&
                (!mmi_ucs2strlen((S8*)g_voip_cntx_p->prof_setting_info.disp_prof.serverName)))
            {
                errorstrId = STR_ID_VOIP_EMPTY_OUTBOUND_SERVER;
            }

            /* validate port number */
            if (!mmi_ucs2strlen((S8*)g_voip_cntx_p->prof_setting_info.disp_prof.portNumber))
            {
                gui_itoa(0, (UI_string_type)g_voip_cntx_p->prof_setting_info.disp_prof.portNumber, 10);
            }
            else
            {
                if (mmi_voip_validate_port(g_voip_cntx_p->prof_setting_info.disp_prof.portNumber) == FALSE)
                {
                    errorstrId = STR_ID_VOIP_INVALID_PORT_NUMBER;
                }
            }
            break;
        case SCR_ID_VOIP_PROF_REGISTER:
            /* validate register server */
            if ((g_voip_cntx_p->prof_setting_info.disp_prof.selectionIndex == 1) &&
                (!mmi_ucs2strlen((S8*)g_voip_cntx_p->prof_setting_info.disp_prof.serverName)))
            {
                errorstrId = STR_ID_VOIP_EMPTY_REGISTER_SERVER;
            }

            /* validate port number */
            if (!mmi_ucs2strlen((S8*)g_voip_cntx_p->prof_setting_info.disp_prof.portNumber))
            {
                gui_itoa(0, (UI_string_type)g_voip_cntx_p->prof_setting_info.disp_prof.portNumber, 10);
            }
            else
            {
                if (mmi_voip_validate_port(g_voip_cntx_p->prof_setting_info.disp_prof.portNumber) == FALSE)
                {
                    errorstrId = STR_ID_VOIP_INVALID_PORT_NUMBER;
                }
            }
            break;
        case SCR_ID_VOIP_PROF_NAT:
            /* validate nat firewall ip */
            if ((g_voip_cntx_p->prof_setting_info.disp_prof.selectionIndex == 1) &&
                (mmi_voip_validate_ip
                 (g_voip_cntx_p->prof_setting_info.disp_prof.ipAddr[0],
                  g_voip_cntx_p->prof_setting_info.disp_prof.ipAddr[1],
                  g_voip_cntx_p->prof_setting_info.disp_prof.ipAddr[2],
                  g_voip_cntx_p->prof_setting_info.disp_prof.ipAddr[3]) == FALSE))
            {
                errorstrId = STR_ID_VOIP_INVALID_IP_ADDRESS;
            }

            /* validate stun server */
            if ((g_voip_cntx_p->prof_setting_info.disp_prof.selectionIndex == 2) &&
                (!mmi_ucs2strlen((S8*)g_voip_cntx_p->prof_setting_info.disp_prof.serverName)))
            {
                errorstrId = STR_ID_VOIP_EMPTY_STUN_SERVER;
            }

            /* validate port number */
            if (!mmi_ucs2strlen((S8*)g_voip_cntx_p->prof_setting_info.disp_prof.portNumber))
            {
                gui_itoa(0, (UI_string_type) g_voip_cntx_p->prof_setting_info.disp_prof.portNumber, 10);
            }
            else
            {
                if (mmi_voip_validate_port(g_voip_cntx_p->prof_setting_info.disp_prof.portNumber) == FALSE)
                {
                    errorstrId = STR_ID_VOIP_INVALID_PORT_NUMBER;
                }
            }
            break;
        default:
            MMI_ASSERT(0);
    }
    return errorstrId;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_prof_confirm
 * DESCRIPTION
 *  Confirmation screen before saving the profile.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_prof_confirm(void)
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
    SetLeftSoftkeyFunction(mmi_voip_entry_prof_save, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_voip_go_back_to_prof_edit, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_prof_save
 * DESCRIPTION
 *  Save the profile.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_prof_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 errorstrId = 0;
    U16 currScreen = g_voip_cntx_p->prof_setting_info.currScr;
    S32 profIndex = g_voip_cntx_p->prof_setting_info.currprofIndex;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    errorstrId = mmi_voip_prof_validate_inputs();
    if (errorstrId != 0)
    {
        DisplayPopup(
            (U8*)GetString(errorstrId), 
            IMG_GLOBAL_UNFINISHED, 
            1, 
            UI_POPUP_NOTIFYDURATION_TIME, 
            ERROR_TONE);
        return;
    }
    switch (currScreen)
    {
        case SCR_ID_VOIP_PROF_COMMON:
            mmi_voip_update_prof_common_disp_to_cache(profIndex);
            break;
        case SCR_ID_VOIP_PROF_ACCOUNT:
            mmi_voip_update_prof_acct_disp_to_cache(profIndex);
            break;
        case SCR_ID_VOIP_PROF_OUTBOUND:
            mmi_voip_update_prof_outbound_disp_to_cache(profIndex);
            break;
        case SCR_ID_VOIP_PROF_REGISTER:
            mmi_voip_update_prof_register_disp_to_cache(profIndex);
            break;
        case SCR_ID_VOIP_PROF_NAT:
            mmi_voip_update_prof_nat_disp_to_cache(profIndex);
            break;
        default:
            MMI_ASSERT(0);
    }
    if (mmi_voip_save_profile(profIndex))
    {
        DisplayPopup(
            (U8*)GetString(STR_GLOBAL_SAVED),
            IMG_GLOBAL_ACTIVATED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            SUCCESS_TONE);
        DeleteScreenIfPresent(SCR_ID_VOIP_PROF_EDIT_INLINEITEMS);
    }
    else
    {
        DisplayPopup(
            (U8*)GetString(STR_GLOBAL_NOT_DONE),
            IMG_GLOBAL_UNFINISHED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
        DeleteScreenIfPresent(SCR_ID_VOIP_PROF_EDIT_INLINEITEMS);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_go_back_to_prof_edit
 * DESCRIPTION
 *  Go back to profile edit screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_go_back_to_prof_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteScreenIfPresent(SCR_ID_VOIP_PROF_EDIT_INLINEITEMS);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_call_setting
 * DESCRIPTION
 *  Entry function of VoIP\Call Setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_call_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U16 nStrItemList[MAX_SUB_MENUS];
    /* Auto Answer, Auto Reject, Auto Redial, Hide Caller ID, DTMF, Secure RTP, Comfort Noise, Set Codec Order */
    U8 *nHintItemList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VOIP_CALL_SETTING, NULL, mmi_voip_entry_call_setting, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_VOIP_CALL_SETTING);
    SetParentHandler(MENU_ID_VOIP_CALL_SETTING);
    numItems = GetNumOfChild(MENU_ID_VOIP_CALL_SETTING);
    GetSequenceStringIds(MENU_ID_VOIP_CALL_SETTING, nStrItemList);
    ConstructHintsList(MENU_ID_VOIP_CALL_SETTING, nHintItemList);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ShowCategory52Screen(
        STR_ID_VOIP_CALL_SETTING,
        GetRootTitleIcon(MENU_ID_VOIP_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        nHintItemList,
        0,
        0,
        guiBuffer);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_setting_general
 * DESCRIPTION
 *  Entry function of VoIP\Call Setting\OK
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_setting_general(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 currScreen = g_voip_cntx_p->call_setting_info.currScr;
    U8 *guiBuffer = NULL;
    U16 titleId = 0, numItems = 0;
    U16 nStrItemList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VOIP_SETTING_GENERAL, NULL, mmi_voip_entry_setting_general, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_VOIP_SETTING_GENERAL);
    switch (currScreen)
    {
        case SCR_ID_VOIP_SETTING_AUTO_ANSWER:
            mmi_voip_update_setting_answer_cache_to_disp();
            titleId = STR_ID_VOIP_SETTING_AUTO_ANSWER;
            numItems = 3;
            nStrItemList[0] = STR_GLOBAL_OFF;
            nStrItemList[1] = STR_ID_VOIP_SETTING_ANYKEY;
            nStrItemList[2] = STR_ID_VOIP_SETTING_AUTO;
            break;
        case SCR_ID_VOIP_SETTING_AUTO_REJECT:
            mmi_voip_update_setting_reject_cache_to_disp();
            titleId = STR_ID_VOIP_SETTING_AUTO_REJECT;
            numItems = 3;
            nStrItemList[0] = STR_GLOBAL_OFF;
            nStrItemList[1] = STR_ID_VOIP_SETTING_REJECT_UNKNOWN;
            nStrItemList[2] = STR_ID_VOIP_SETTING_REJECT_ALL;
            break;
        case SCR_ID_VOIP_SETTING_AUTO_REDIAL:
            mmi_voip_update_setting_redial_cache_to_disp();
            titleId = STR_ID_VOIP_SETTING_AUTO_REDIAL;
            numItems = 2;
            nStrItemList[0] = STR_GLOBAL_OFF;
            nStrItemList[1] = STR_GLOBAL_ON;
            break;
        case SCR_ID_VOIP_SETTING_HIDE_CALLER_ID:
            mmi_voip_update_setting_hide_cache_to_disp();
            titleId = STR_ID_VOIP_SETTING_HIDE_CALLER_ID;
            numItems = 2;
            nStrItemList[0] = STR_GLOBAL_OFF;
            nStrItemList[1] = STR_GLOBAL_ON;
            break;
        case SCR_ID_VOIP_SETTING_DTMF:
            mmi_voip_update_setting_dtmf_cache_to_disp();
            titleId = STR_ID_VOIP_SETTING_DTMF;
            numItems = 3;
            nStrItemList[0] = STR_ID_VOIP_SETTING_INBAND;
            nStrItemList[1] = STR_ID_VOIP_SETTING_OUTBAND;
            nStrItemList[2] = STR_GLOBAL_OFF;
            break;
        case SCR_ID_VOIP_SETTING_SECURE_RTP:
            mmi_voip_update_setting_srtp_cache_to_disp();
            titleId = STR_ID_VOIP_SETTING_SECURE_RTP;
            numItems = 2;
            nStrItemList[0] = STR_GLOBAL_OFF;
            nStrItemList[1] = STR_GLOBAL_ON;
            break;
        case SCR_ID_VOIP_SETTING_COMFORT_NOISE:
            mmi_voip_update_setting_noise_cache_to_disp();
            titleId = STR_ID_VOIP_SETTING_COMFORT_NOISE;
            numItems = 2;
            nStrItemList[0] = STR_GLOBAL_ON;
            nStrItemList[1] = STR_GLOBAL_OFF;
            break;
        case SCR_ID_VOIP_SETTING_SET_CODEC_ORDER:
        default:
            MMI_ASSERT(0);
    }
    RegisterHighlightHandler(mmi_voip_highlight_setting_general_item);
    ShowCategory11Screen(
        titleId,
        GetRootTitleIcon(MENU_ID_VOIP_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16) g_voip_cntx_p->call_setting_info.currIndex,
        guiBuffer);
    SetLeftSoftkeyFunction(mmi_voip_entry_setting_general_confirm, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_highlight_setting_general_item
 * DESCRIPTION
 *  Highlight item of selecting a selection in VoIP\Call Setting\OK
 * PARAMETERS
 *  index           [IN]            Current highlight index.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_highlight_setting_general_item(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_voip_cntx_p->call_setting_info.currIndex = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_update_setting_answer_cache_to_disp
 * DESCRIPTION
 *  Copy g_voip_cntx_p->call_setting_info.saved_setting to
 *  g_voip_cntx_p->call_setting_info.currIndex for Auto Answer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_update_setting_answer_cache_to_disp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_voip_cntx_p->call_setting_info.currIndex = g_voip_cntx_p->call_setting_info.saved_setting.autoAnswer;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_update_setting_reject_cache_to_disp
 * DESCRIPTION
 *  Copy g_voip_cntx_p->call_setting_info.saved_setting to
 *  g_voip_cntx_p->call_setting_info.currIndex for Auto Reject.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_update_setting_reject_cache_to_disp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_voip_cntx_p->call_setting_info.currIndex = g_voip_cntx_p->call_setting_info.saved_setting.autoReject;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_update_setting_redial_cache_to_disp
 * DESCRIPTION
 *  Copy g_voip_cntx_p->call_setting_info.saved_setting to
 *  g_voip_cntx_p->call_setting_info.currIndex for Auto Redial.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_update_setting_redial_cache_to_disp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_voip_cntx_p->call_setting_info.currIndex = g_voip_cntx_p->call_setting_info.saved_setting.autoRedial;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_update_setting_hide_cache_to_disp
 * DESCRIPTION
 *  Copy g_voip_cntx_p->call_setting_info.saved_setting to
 *  g_voip_cntx_p->call_setting_info.currIndex for Hide Caller ID.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_update_setting_hide_cache_to_disp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_voip_cntx_p->call_setting_info.currIndex = g_voip_cntx_p->call_setting_info.saved_setting.hidecallerId;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_update_setting_dtmf_cache_to_disp
 * DESCRIPTION
 *  Copy g_voip_cntx_p->call_setting_info.saved_setting to
 *  g_voip_cntx_p->call_setting_info.currIndex for DTMF.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_update_setting_dtmf_cache_to_disp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_voip_cntx_p->call_setting_info.currIndex = g_voip_cntx_p->call_setting_info.saved_setting.dtmf;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_update_setting_srtp_cache_to_disp
 * DESCRIPTION
 *  Copy g_voip_cntx_p->call_setting_info.saved_setting to
 *  g_voip_cntx_p->call_setting_info.currIndex for SRTP.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_update_setting_srtp_cache_to_disp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_voip_cntx_p->call_setting_info.currIndex = g_voip_cntx_p->call_setting_info.saved_setting.srtp;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_update_setting_noise_cache_to_disp
 * DESCRIPTION
 *  Copy g_voip_cntx_p->call_setting_info.saved_setting to
 *  g_voip_cntx_p->call_setting_info.currIndex for Comfort Noise.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_update_setting_noise_cache_to_disp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_voip_cntx_p->call_setting_info.currIndex = g_voip_cntx_p->call_setting_info.saved_setting.comfortNoise;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_update_setting_codec_cache_to_disp
 * DESCRIPTION
 *  Copy g_voip_cntx_p->call_setting_info.saved_setting to
 *  g_voip_cntx_p->call_setting_info.dispCodec for Set Codec Order.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_update_setting_codec_cache_to_disp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_voip_cntx_p->call_setting_info.numCodec; i++)
    {
        memset(g_voip_cntx_p->call_setting_info.dispCodec[i], 0, (MMI_VOIP_MAX_CODEC_NAME_LEN * ENCODING_LENGTH));
        if (strlen((S8*) g_voip_cntx_p->call_setting_info.saved_setting.codecOrder[i]))
        {
            mmi_asc_n_to_ucs2(
                (S8*) g_voip_cntx_p->call_setting_info.dispCodec[i],
                (S8*) g_voip_cntx_p->call_setting_info.saved_setting.codecOrder[i],
                MMI_VOIP_MAX_CODEC_NAME_LEN);
            for (j = 0; j < MMI_VOIP_MAX_CODEC_NUM; j++)
            {
                if (!mmi_ucs2cmp((S8*)g_voip_cntx_p->call_setting_info.dispCodec[i], (S8*)GetString(STR_ID_VOIP_SETTING_CODEC2 + j)))
                {
                    g_voip_cntx_p->call_setting_info.codecEnum[i] = g_voip_codec_table[j + 1];  /* AMR should not appear in the menu */
                    break;
                }
            }
        }
        else
        {
            g_voip_cntx_p->call_setting_info.numCodec = i;
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_update_setting_answer_disp_to_cache
 * DESCRIPTION
 *  Copy g_voip_cntx_p->call_setting_info.currIndex to
 *  g_voip_cntx_p->call_setting_info.saved_setting for Auto Answer.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means the data is different from the original;
 *  FALSE means the data is the same as the original.
 *****************************************************************************/
MMI_BOOL mmi_voip_update_setting_answer_disp_to_cache(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_voip_cntx_p->call_setting_info.saved_setting.autoAnswer != g_voip_cntx_p->call_setting_info.currIndex)
    {
        g_voip_cntx_p->call_setting_info.saved_setting.autoAnswer = g_voip_cntx_p->call_setting_info.currIndex;
        return TRUE;
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_update_setting_reject_disp_to_cache
 * DESCRIPTION
 *  Copy g_voip_cntx_p->call_setting_info.currIndex to
 *  g_voip_cntx_p->call_setting_info.saved_setting for Auto Reject.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means the data is different from the original;
 *  FALSE means the data is the same as the original.
 *****************************************************************************/
MMI_BOOL mmi_voip_update_setting_reject_disp_to_cache(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_voip_cntx_p->call_setting_info.saved_setting.autoReject != g_voip_cntx_p->call_setting_info.currIndex)
    {
        g_voip_cntx_p->call_setting_info.saved_setting.autoReject = g_voip_cntx_p->call_setting_info.currIndex;
        return TRUE;
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_update_setting_redial_disp_to_cache
 * DESCRIPTION
 *  Copy g_voip_cntx_p->call_setting_info.currIndex to
 *  g_voip_cntx_p->call_setting_info.saved_setting for Auto Redial.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means the data is different from the original;
 *  FALSE means the data is the same as the original.
 *****************************************************************************/
MMI_BOOL mmi_voip_update_setting_redial_disp_to_cache(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_voip_cntx_p->call_setting_info.saved_setting.autoRedial != g_voip_cntx_p->call_setting_info.currIndex)
    {
        g_voip_cntx_p->call_setting_info.saved_setting.autoRedial = g_voip_cntx_p->call_setting_info.currIndex;
        return TRUE;
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_update_setting_hide_disp_to_cache
 * DESCRIPTION
 *  Copy g_voip_cntx_p->call_setting_info.currIndex to
 *  g_voip_cntx_p->call_setting_info.saved_setting for Hide Caller ID.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means the data is different from the original;
 *  FALSE means the data is the same as the original.
 *****************************************************************************/
MMI_BOOL mmi_voip_update_setting_hide_disp_to_cache(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_voip_cntx_p->call_setting_info.saved_setting.hidecallerId != g_voip_cntx_p->call_setting_info.currIndex)
    {
        g_voip_cntx_p->call_setting_info.saved_setting.hidecallerId = g_voip_cntx_p->call_setting_info.currIndex;
        return TRUE;
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_update_setting_dtmf_disp_to_cache
 * DESCRIPTION
 *  Copy g_voip_cntx_p->call_setting_info.currIndex to
 *  g_voip_cntx_p->call_setting_info.saved_setting for DTMF.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means the data is different from the original;
 *  FALSE means the data is the same as the original.
 *****************************************************************************/
MMI_BOOL mmi_voip_update_setting_dtmf_disp_to_cache(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_voip_cntx_p->call_setting_info.saved_setting.dtmf != g_voip_cntx_p->call_setting_info.currIndex)
    {
        g_voip_cntx_p->call_setting_info.saved_setting.dtmf = g_voip_cntx_p->call_setting_info.currIndex;
        return TRUE;
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_update_setting_srtp_disp_to_cache
 * DESCRIPTION
 *  Copy g_voip_cntx_p->call_setting_info.currIndex to
 *  g_voip_cntx_p->call_setting_info.saved_setting for SRTP.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means the data is different from the original;
 *  FALSE means the data is the same as the original.
 *****************************************************************************/
MMI_BOOL mmi_voip_update_setting_srtp_disp_to_cache(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_voip_cntx_p->call_setting_info.saved_setting.srtp != g_voip_cntx_p->call_setting_info.currIndex)
    {
        g_voip_cntx_p->call_setting_info.saved_setting.srtp = g_voip_cntx_p->call_setting_info.currIndex;
        return TRUE;
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_update_setting_noise_disp_to_cache
 * DESCRIPTION
 *  Copy g_voip_cntx_p->call_setting_info.currIndex to
 *  g_voip_cntx_p->call_setting_info.saved_setting for Comfort Noise.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means the data is different from the original;
 *  FALSE means the data is the same as the original.
 *****************************************************************************/
MMI_BOOL mmi_voip_update_setting_noise_disp_to_cache(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_voip_cntx_p->call_setting_info.saved_setting.comfortNoise != g_voip_cntx_p->call_setting_info.currIndex)
    {
        g_voip_cntx_p->call_setting_info.saved_setting.comfortNoise = g_voip_cntx_p->call_setting_info.currIndex;
        return TRUE;
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_update_setting_codec_disp_to_cache
 * DESCRIPTION
 *  Copy g_voip_cntx_p->call_setting_info.dispCodec to
 *  g_voip_cntx_p->call_setting_info.saved_setting for Set Codec Order.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means the data is different from the original;
 *  FALSE means the data is the same as the original.
 *****************************************************************************/
MMI_BOOL mmi_voip_update_setting_codec_disp_to_cache(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_voip_cntx_p->call_setting_info.numCodec; i++)
    {
        memset(g_voip_cntx_p->call_setting_info.saved_setting.codecOrder[i], 0, MMI_VOIP_MAX_CODEC_NAME_LEN);
        mmi_ucs2_n_to_asc(
            (S8*) g_voip_cntx_p->call_setting_info.saved_setting.codecOrder[i],
            (S8*) g_voip_cntx_p->call_setting_info.dispCodec[i],
            (MMI_VOIP_MAX_CODEC_NAME_LEN * ENCODING_LENGTH));
        for (j = 0; j < MMI_VOIP_MAX_CODEC_NUM; j++)
        {
            if (!mmi_ucs2cmp((S8*)g_voip_cntx_p->call_setting_info.dispCodec[i], (S8*)GetString(STR_ID_VOIP_SETTING_CODEC2 + j)))
            {
                g_voip_cntx_p->call_setting_info.codecEnum[i] = g_voip_codec_table[j + 1];      /* AMR should not appear in the menu */
                break;
            }
        }
    }
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_setting_general_confirm
 * DESCRIPTION
 *  Confirmation screen before saving the setting.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_setting_general_confirm(void)
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
    SetLeftSoftkeyFunction(mmi_voip_entry_setting_general_save, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_voip_go_back_to_call_setting, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_setting_general_save
 * DESCRIPTION
 *  Save the setting.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_setting_general_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 currScreen = g_voip_cntx_p->call_setting_info.currScr;
    MMI_BOOL isChange = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (currScreen)
    {
        case SCR_ID_VOIP_SETTING_AUTO_ANSWER:
            isChange = mmi_voip_update_setting_answer_disp_to_cache();
            break;
        case SCR_ID_VOIP_SETTING_AUTO_REJECT:
            isChange = mmi_voip_update_setting_reject_disp_to_cache();
            break;
        case SCR_ID_VOIP_SETTING_AUTO_REDIAL:
            isChange = mmi_voip_update_setting_redial_disp_to_cache();
            break;
        case SCR_ID_VOIP_SETTING_HIDE_CALLER_ID:
            isChange = mmi_voip_update_setting_hide_disp_to_cache();
            break;
        case SCR_ID_VOIP_SETTING_DTMF:
            isChange = mmi_voip_update_setting_dtmf_disp_to_cache();
            break;
        case SCR_ID_VOIP_SETTING_SECURE_RTP:
            isChange = mmi_voip_update_setting_srtp_disp_to_cache();
            break;
        case SCR_ID_VOIP_SETTING_COMFORT_NOISE:
            isChange = mmi_voip_update_setting_noise_disp_to_cache();
            break;
        case SCR_ID_VOIP_SETTING_SET_CODEC_ORDER:
        default:
            MMI_ASSERT(0);
    }
    if (mmi_voip_save_setting())
    {
        if (isChange)
        {
            mmi_voip_setting_req();
        }
        else
        {
            DisplayPopup(
                (U8*)GetString(STR_GLOBAL_SAVED),
                IMG_GLOBAL_ACTIVATED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                SUCCESS_TONE);
            DeleteScreenIfPresent(SCR_ID_VOIP_SETTING_GENERAL);
        }
    }
    else
    {
        DisplayPopup(
            (U8*)GetString(STR_GLOBAL_NOT_DONE),
            IMG_GLOBAL_UNFINISHED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
        DeleteScreenIfPresent(SCR_ID_VOIP_SETTING_GENERAL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_go_back_to_call_setting
 * DESCRIPTION
 *  Go back to call setting screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_go_back_to_call_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteScreenIfPresent(SCR_ID_VOIP_SETTING_GENERAL);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_set_codec_order
 * DESCRIPTION
 *  Entry function of VoIP\Call Setting\Set Codec Order
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_set_codec_order(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U8 *nStrItemList[MAX_SUB_MENUS];
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VOIP_SETTING_SET_CODEC_ORDER, NULL, mmi_voip_entry_set_codec_order, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_VOIP_SETTING_SET_CODEC_ORDER);
    mmi_voip_update_setting_codec_cache_to_disp();
    numItems = g_voip_cntx_p->call_setting_info.numCodec;
    for (i = 0; i < numItems; i++)
    {
        nStrItemList[i] = g_voip_cntx_p->call_setting_info.dispCodec[i];
    }
    RegisterHighlightHandler(mmi_voip_highlight_set_codec_order_item);
    ShowCategory6Screen(
        STR_ID_VOIP_SETTING_SET_CODEC_ORDER,
        GetRootTitleIcon(MENU_ID_VOIP_MAIN),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        NULL,
        g_voip_cntx_p->call_setting_info.currIndex,
        guiBuffer);
    SetLeftSoftkeyFunction(mmi_voip_entry_set_codec_order_option, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_voip_entry_set_codec_order_option, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_highlight_set_codec_order_item
 * DESCRIPTION
 *  Highlight item of selecting a selection in VoIP\Call Setting\Set Codec Order
 * PARAMETERS
 *  index           [IN]            Current highlight index.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_highlight_set_codec_order_item(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_voip_cntx_p->call_setting_info.currIndex = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_set_codec_order_option
 * DESCRIPTION
 *  Entry function of VoIP\Call Setting\Set Codec Order\Option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_set_codec_order_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VOIP_SETTING_SET_CODEC_ORDER_OPTION, NULL, mmi_voip_entry_set_codec_order_option, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_VOIP_SETTING_SET_CODEC_ORDER_OPTION);

    g_voip_cntx_p->call_setting_info.currPriority = g_voip_cntx_p->call_setting_info.currIndex + 1;
    ShowCategory87Screen(
        STR_ID_VOIP_SETTING_PRIORITY,
        GetRootTitleIcon(MENU_ID_VOIP_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        1,
        g_voip_cntx_p->call_setting_info.numCodec,
        &g_voip_cntx_p->call_setting_info.currPriority,
        guiBuffer);
    SetLeftSoftkeyFunction(mmi_voip_entry_setting_codec_confirm, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_setting_codec_confirm
 * DESCRIPTION
 *  Confirmation screen before saving the codec order.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_setting_codec_confirm(void)
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
    SetLeftSoftkeyFunction(mmi_voip_entry_setting_codec_save, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_voip_go_back_to_codec_order, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_setting_codec_save
 * DESCRIPTION
 *  Save the codec order.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_setting_codec_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 srcIndex = g_voip_cntx_p->call_setting_info.currIndex;
    S32 destIndex = g_voip_cntx_p->call_setting_info.currPriority - 1;
    S32 i = 0;
    MMI_BOOL isChange = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srcIndex < destIndex)
    {
        memset(
            g_voip_cntx_p->call_setting_info.dispCodec[destIndex],
            0,
            (MMI_VOIP_MAX_CODEC_NAME_LEN * ENCODING_LENGTH));
        mmi_asc_n_to_ucs2(
            (S8*) g_voip_cntx_p->call_setting_info.dispCodec[destIndex],
            (S8*) g_voip_cntx_p->call_setting_info.saved_setting.codecOrder[srcIndex],
            MMI_VOIP_MAX_CODEC_NAME_LEN);
        for (i = srcIndex; i < destIndex; i++)
        {
            memset(g_voip_cntx_p->call_setting_info.dispCodec[i], 0, (MMI_VOIP_MAX_CODEC_NAME_LEN * ENCODING_LENGTH));
            mmi_asc_n_to_ucs2(
                (S8*) g_voip_cntx_p->call_setting_info.dispCodec[i],
                (S8*) g_voip_cntx_p->call_setting_info.saved_setting.codecOrder[i + 1],
                MMI_VOIP_MAX_CODEC_NAME_LEN);
        }
        g_voip_cntx_p->call_setting_info.currIndex = destIndex;
    }
    else if (srcIndex > destIndex)
    {
        memset(
            g_voip_cntx_p->call_setting_info.dispCodec[destIndex],
            0,
            (MMI_VOIP_MAX_CODEC_NAME_LEN * ENCODING_LENGTH));
        mmi_asc_n_to_ucs2(
            (S8*) g_voip_cntx_p->call_setting_info.dispCodec[destIndex],
            (S8*) g_voip_cntx_p->call_setting_info.saved_setting.codecOrder[srcIndex],
            MMI_VOIP_MAX_CODEC_NAME_LEN);
        for (i = srcIndex; i > destIndex; i--)
        {
            memset(g_voip_cntx_p->call_setting_info.dispCodec[i], 0, (MMI_VOIP_MAX_CODEC_NAME_LEN * ENCODING_LENGTH));
            mmi_asc_n_to_ucs2(
                (S8*) g_voip_cntx_p->call_setting_info.dispCodec[i],
                (S8*) g_voip_cntx_p->call_setting_info.saved_setting.codecOrder[i - 1],
                MMI_VOIP_MAX_CODEC_NAME_LEN);
        }
        g_voip_cntx_p->call_setting_info.currIndex = destIndex;
    }
    else    /* srcIndex == destIndex */
    {
        /* do nothing */
    }
    isChange = mmi_voip_update_setting_codec_disp_to_cache();
    if (mmi_voip_save_setting())
    {
        if (isChange)
        {
            mmi_voip_setting_req();
        }
        else
        {
            DisplayPopup(
                (U8*)GetString(STR_GLOBAL_SAVED),
                IMG_GLOBAL_ACTIVATED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                SUCCESS_TONE);
            DeleteScreenIfPresent(SCR_ID_VOIP_SETTING_SET_CODEC_ORDER_OPTION);
        }
    }
    else
    {
        DisplayPopup(
            (U8*)GetString(STR_GLOBAL_NOT_DONE),
            IMG_GLOBAL_UNFINISHED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
        DeleteScreenIfPresent(SCR_ID_VOIP_SETTING_SET_CODEC_ORDER_OPTION);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_go_back_to_codec_order
 * DESCRIPTION
 *  Go back to set codec order screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_go_back_to_codec_order(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteScreenIfPresent(SCR_ID_VOIP_SETTING_SET_CODEC_ORDER_OPTION);
    GoBackHistory();
}


#ifdef SIP_CONFORMANCE_TEST
/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_option_query
 * DESCRIPTION
 *  Entry function of VoIP\Option Query
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_option_query(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VOIP_OPTION_QUERY_EDITOR, NULL, mmi_voip_entry_option_query, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_VOIP_OPTION_QUERY_EDITOR);
    ShowCategory5Screen(
        STR_ID_VOIP_MAIN,
        GetRootTitleIcon(MENU_ID_VOIP_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES,
        g_voip_cntx_p->call_misc_info.dispUri,
        VOIP_URI_LEN,
        guiBuffer);
    SetLeftSoftkeyFunction(mmi_voip_entry_option_query_check, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_option_query_result
 * DESCRIPTION
 *  Display option query result.
 * PARAMETERS
 *  asciiData           [IN]            Option query result in ascii
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_option_query_result(U8 *asciiData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_n_to_ucs2((S8*)subMenuData, (S8*)asciiData, VOIP_SIP_OPTION_LEN);

    EntryNewScreen(SCR_ID_VOIP_OPTION_QUERY_RESULT, NULL, NULL, NULL);
    ShowCategory74Screen(
        STR_ID_VOIP_OPTION_QUERY,
        GetRootTitleIcon(MENU_ID_VOIP_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        0,
        IMG_GLOBAL_BACK,
        (U8*)subMenuData,
        (MAX_SUB_MENUS * MAX_SUB_MENU_SIZE),
        NULL);
    SetLeftSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}
#endif /* SIP_CONFORMANCE_TEST */


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_go_back_2_history
 * DESCRIPTION
 *  Delete one history and go back history.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_go_back_2_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBacknHistory(1);
}
#endif /* __MMI_VOIP__ */

