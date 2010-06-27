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
 *  VoIPCall.c
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

#ifdef __MMI_BT_SUPPORT__
#include "BTMMIScrGprots.h"
#endif
#include "CallManagementGprot.h"
#include "DateTimeGprot.h"
#include "gpioInc.h"
#include "ProfileGprots.h"
#include "PhoneBookGprot.h"
#ifdef __MMI_SOUND_RECORDER__
#include "SoundRecorderProt.h"
#endif
#include "wgui.h"
#include "wgui_status_icons.h"

#include "VoIPResDef.h"
#include "VoIPGProt.h"
#include "VoIPProt.h"


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_highlight_new_call
 * DESCRIPTION
 *  Highlight handler of VoIP\New Call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_highlight_new_call(void)
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
    SetLeftSoftkeyFunction(mmi_voip_entry_new_call, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_highlight_dial
 * DESCRIPTION
 *  Highlight handler of VoIP\New Call\Option\Dial
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_highlight_dial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_voip_pre_dial, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_highlight_save_phonebook
 * DESCRIPTION
 *  Highlight handler of VoIP\New Call\Option\Save to Phonebook
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_highlight_save_phonebook(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_voip_entry_save_phonebook, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_highlight_input_method_in_call
 * DESCRIPTION
 *  Highlight handler of VoIP\New Call\Option\Input Method
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_highlight_input_method_in_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(EntryAPRequiredInputMethodScreen, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    RegisterInputMethodScreenCloseFunction(mmi_voip_go_back_2_history);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_highlight_sos
 * DESCRIPTION
 *  Highlight handler of VoIP\New Call\Option\SOS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_highlight_sos(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_voip_entry_sos, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_highlight_hold_single
 * DESCRIPTION
 *  Highlight handler of Call Option\Hold Single
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_highlight_hold_single(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_voip_entry_hold_single, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_highlight_hold_conference
 * DESCRIPTION
 *  Highlight handler of Call Option\Hold Conference
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_highlight_hold_conference(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_voip_entry_hold_conference, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_highlight_retrieve_single
 * DESCRIPTION
 *  Highlight handler of Call Option\Retrieve Single
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_highlight_retrieve_single(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_voip_entry_retrieve_single, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_highlight_retrieve_conference
 * DESCRIPTION
 *  Highlight handler of Call Option\Retrieve Conference
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_highlight_retrieve_conference(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_voip_entry_retrieve_conference, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_highlight_swap
 * DESCRIPTION
 *  Highlight handler of Call Option\Swap
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_highlight_swap(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_voip_entry_swap, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_highlight_conference
 * DESCRIPTION
 *  Highlight handler of Call Option\Conference
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_highlight_conference(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_voip_entry_conference, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_highlight_split
 * DESCRIPTION
 *  Highlight handler of Call Option\Split
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_highlight_split(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_voip_entry_split, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_highlight_end_single
 * DESCRIPTION
 *  Highlight handler of Call Option\End Single
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_highlight_end_single(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_voip_entry_end_single, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_highlight_end_conference
 * DESCRIPTION
 *  Highlight handler of Call Option\End Conference
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_highlight_end_conference(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_voip_entry_end_conference, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_highlight_end_all
 * DESCRIPTION
 *  Highlight handler of Call Option\End All
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_highlight_end_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_voip_entry_end_all, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_highlight_transfer
 * DESCRIPTION
 *  Highlight handler of Call Option\Transfer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_highlight_transfer(void)
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
    SetLeftSoftkeyFunction(mmi_voip_entry_transfer, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_highlight_phonebook
 * DESCRIPTION
 *  Highlight handler of Call Option\Phonebook
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_highlight_phonebook(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_phb_call_enter_from_active_call, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


#ifdef __MMI_SOUND_RECORDER__
/*****************************************************************************
 * FUNCTION
 *  mmi_voip_highlight_sound_recorder
 * DESCRIPTION
 *  Highlight handler of Call Option\Sound Recorder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_highlight_sound_recorder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_sndrec_entry_in_voip_call, KEY_EVENT_UP); // TODO: mmi_sndrec_entry_in_voip_call
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}
#endif /* __MMI_SOUND_RECORDER__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_highlight_mute
 * DESCRIPTION
 *  Highlight handler of Call Option\Mute
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_highlight_mute(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_voip_cntx_p->call_misc_info.isMute == TRUE)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OFF, IMG_GLOBAL_OK);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_ON, IMG_GLOBAL_OK);
    }
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_voip_set_mute, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_highlight_dtmf_in_call
 * DESCRIPTION
 *  Highlight handler of Call Option\DTMF
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_highlight_dtmf_in_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_voip_cntx_p->call_misc_info.isDtmf == TRUE)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OFF, IMG_GLOBAL_OK);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_ON, IMG_GLOBAL_OK);
    }
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_voip_set_dtmf_in_call, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_highlight_transfer_option
 * DESCRIPTION
 *  Highlight handler of Transfer Option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_highlight_transfer_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_voip_entry_transfer_option, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_highlight_transfer_option_done
 * DESCRIPTION
 *  Highlight handler of Transfer Option\Transfer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_highlight_transfer_option_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_voip_entry_transfer_call_determined, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_hint_mute
 * DESCRIPTION
 *  Hint handler of Call Option\Mute
 * PARAMETERS
 *  index       [IN]        Current selected index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_hint_mute(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(hintData[index], 0, MAX_SUB_MENU_SIZE);
    if (g_voip_cntx_p->call_misc_info.isMute == TRUE)
    {
        mmi_ucs2cpy((S8*) hintData[index], (S8*) GetString(STR_GLOBAL_ON));
    }
    else
    {
        mmi_ucs2cpy((S8*) hintData[index], (S8*) GetString(STR_GLOBAL_OFF));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_hint_dtmf_in_call
 * DESCRIPTION
 *  Hint handler of Call Option\DTMF
 * PARAMETERS
 *  index       [IN]        Current selected index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_hint_dtmf_in_call(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(hintData[index], 0, MAX_SUB_MENU_SIZE);
    if (g_voip_cntx_p->call_misc_info.isDtmf == TRUE)
    {
        mmi_ucs2cpy((S8*) hintData[index], (S8*) GetString(STR_GLOBAL_ON));
    }
    else
    {
        mmi_ucs2cpy((S8*) hintData[index], (S8*) GetString(STR_GLOBAL_OFF));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_login_confirm
 * DESCRIPTION
 *  Login confirmation screen before dialing.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_login_confirm(void)
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
        get_string(STR_ID_VOIP_LOGIN),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);
    SetLeftSoftkeyFunction(mmi_voip_entry_status, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_voip_go_back_to_call_editor, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_go_back_to_call_editor
 * DESCRIPTION
 *  Go back to call editor screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_go_back_to_call_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteScreenIfPresent(SCR_ID_VOIP_CALL_EDITOR_OPTION);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_new_call
 * DESCRIPTION
 *  Entry function of VoIP\New Call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_new_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VOIP_CALL_EDITOR, NULL, mmi_voip_entry_new_call, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_VOIP_CALL_EDITOR);
    ShowCategory404Screen(
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        IMG_ID_VOIP_CALL_EDITOR,
        g_voip_cntx_p->call_misc_info.dispUri,
        VOIP_URI_LEN,
        guiBuffer);
    SetLeftSoftkeyFunction(mmi_voip_entry_call_editor_option, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(mmi_voip_pre_dial, KEY_SEND, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_voip_entry_in_call_endkey, KEY_END, KEY_EVENT_DOWN);

    /* must set KEY_EVENT_DOWN function to overwrite original side key handler of category 52 */
    SetKeyHandler(mmi_voip_entry_sidekey, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_voip_entry_sidekey, KEY_VOL_DOWN, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_call_editor_option
 * DESCRIPTION
 *  Entry function of VoIP\New Call\Option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_call_editor_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U16 nStrItemList[MAX_SUB_MENUS];    /* Dial, Save to Phonebook, Input Method, SOS */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VOIP_CALL_EDITOR_OPTION, NULL, mmi_voip_entry_call_editor_option, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_VOIP_CALL_EDITOR_OPTION);
    SetParentHandler(MENU_ID_VOIP_CALL_EDITOR_OPTION);
    numItems = GetNumOfChild(MENU_ID_VOIP_CALL_EDITOR_OPTION);
    GetSequenceStringIds(MENU_ID_VOIP_CALL_EDITOR_OPTION, nStrItemList);
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

    /* ensure at least one call exists, otherwise side key behavior should be the same as up/down arrow */
    if (g_voip_cntx_p->call_list_info.numTotal > 0)
    {
        /* must set KEY_EVENT_DOWN function to overwrite original side key handler of category 52 */
        SetKeyHandler(mmi_voip_entry_sidekey, KEY_VOL_UP, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_voip_entry_sidekey, KEY_VOL_DOWN, KEY_EVENT_DOWN);
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_outgoing_call
 * DESCRIPTION
 *  Entry function of outgoing call screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_outgoing_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VOIP_OUTGOING_CALL, NULL, mmi_voip_entry_outgoing_call, NULL);
    DeleteScreenIfPresent(SCR_ID_VOIP_OUTGOING_CALL); /* ensure no two outgoing call screens in the history */
    guiBuffer = GetCurrGuiBuffer(SCR_ID_VOIP_OUTGOING_CALL);
    memset(g_voip_cntx_p->call_misc_info.dispUri, 0, (VOIP_URI_LEN * ENCODING_LENGTH));
    mmi_asc_n_to_ucs2(
        (S8*)g_voip_cntx_p->call_misc_info.dispUri,
        (S8*)g_voip_cntx_p->call_misc_info.inputUri,
        VOIP_URI_LEN);

    /* originapp_info will be reset after call disconnects, 
       need to write it back so that display name can be found by the redialing number */
    if ((g_voip_cntx_p->call_setting_info.saved_setting.autoRedial == TRUE) && 
        (mmi_ucs2strlen((S8*)g_voip_cntx_p->call_redial_info.redialName)))
    {
        g_voip_cntx_p->call_originapp_info.moOrgin = MMI_VOIP_PHB; /* set to default */
        mmi_ucs2ncpy((S8*)g_voip_cntx_p->call_originapp_info.dispName, (S8*)g_voip_cntx_p->call_redial_info.redialName, VOIP_DISP_NAME_LEN);
        memcpy(g_voip_cntx_p->call_originapp_info.remoteUri, g_voip_cntx_p->call_redial_info.redialUri, VOIP_URI_LEN);
    }
    
    if (mmi_voip_get_outgoing_disp_name(
            MMI_VOIP_PHB|MMI_VOIP_HISTORY|MMI_VOIP_SOS, 
            g_voip_cntx_p->call_misc_info.dispUri, 
            g_voip_cntx_p->call_misc_info.dispUri, 
            VOIP_URI_LEN) == TRUE)
    {
        if (g_voip_cntx_p->call_setting_info.saved_setting.autoRedial == TRUE)
        {
            mmi_ucs2ncpy((S8*)g_voip_cntx_p->call_redial_info.redialName, (S8*)g_voip_cntx_p->call_misc_info.dispUri, VOIP_DISP_NAME_LEN);
        }
    }
    ShowCategory18Screen(
        0,
        0,
        0,
        STR_GLOBAL_ABORT,
        0,
        STR_ID_VOIP_CALLING,
        g_voip_cntx_p->call_misc_info.dispUri,
        NULL,
        0,
        IMG_ID_VOIP_OUTGOING_CALL,
        NULL,
        FALSE,
        guiBuffer);
    SetRightSoftkeyFunction(mmi_voip_entry_abort_call, KEY_EVENT_UP);
    SetKeyHandler(mmi_voip_entry_abort_call, KEY_END, KEY_EVENT_DOWN);

    /* must set KEY_EVENT_DOWN function to overwrite original side key handler of category 52 */
    SetKeyHandler(mmi_voip_entry_sidekey, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_voip_entry_sidekey, KEY_VOL_DOWN, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_redialing_call
 * DESCRIPTION
 *  Entry function of redial call screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_redialing_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VOIP_REDIALING_CALL, NULL, mmi_voip_entry_redialing_call, NULL);
    DeleteScreenIfPresent(SCR_ID_VOIP_REDIALING_CALL);   /* ensure no two redialing call screens in the history */
    guiBuffer = GetCurrGuiBuffer(SCR_ID_VOIP_REDIALING_CALL);
    memset(g_voip_cntx_p->call_redial_info.redialStr, 0, MMI_VOIP_MAX_STRING_LEN);
    mmi_voip_get_redial_string((U8*)g_voip_cntx_p->call_redial_info.redialStr);
    ShowCategory18Screen(
        0,
        0,
        0,
        STR_GLOBAL_ABORT,
        0,
        STR_ID_VOIP_REDIALING,
        (U8*)g_voip_cntx_p->call_redial_info.redialStr,
        NULL,
        0,
        IMG_ID_VOIP_OUTGOING_CALL,
        NULL,
        FALSE,
        guiBuffer);
    SetRightSoftkeyFunction(mmi_voip_entry_abort_redial, KEY_EVENT_UP);
    SetKeyHandler(mmi_voip_entry_abort_redial, KEY_END, KEY_EVENT_DOWN);

    /* must set KEY_EVENT_DOWN function to overwrite original side key handler of category 52 */
    SetKeyHandler(mmi_voip_entry_sidekey, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_voip_entry_sidekey, KEY_VOL_DOWN, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_incoming_call
 * DESCRIPTION
 *  Entry function of incoming call screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_incoming_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    S32 callId = 0, callIndex = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VOIP_INCOMING_CALL, NULL, mmi_voip_entry_incoming_call, NULL);
    DeleteScreenIfPresent(SCR_ID_VOIP_INCOMING_CALL);   /* ensure no two incoming call screens in the history */
    guiBuffer = GetCurrGuiBuffer(SCR_ID_VOIP_INCOMING_CALL);
    callId = mmi_voip_get_incoming_call_id();
    callIndex = mmi_voip_get_call_index(callId);
    memset((S8*) subMenuData[0], 0, MAX_SUB_MENU_SIZE);
    if (mmi_ucs2strlen((S8*) g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[0].dispName) != 0)
    {
        mmi_ucs2ncpy(
            (S8*) subMenuData[0],
            (S8*) g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[0].dispName,
            VOIP_DISP_NAME_LEN);
    }
    else
    {
        mmi_asc_n_to_ucs2(
            (S8*) subMenuData[0],
            (S8*) g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[0].remoteUri,
            (MAX_SUBMENU_CHARACTERS - 1));
    }
    ShowCategory18Screen(
        0,
        STR_ID_VOIP_ANSWER,
        0,
        STR_ID_VOIP_REJECT,
        0,
        STR_ID_VOIP_RINGING,
        (U8*) subMenuData[0],
        NULL,
        0,
        IMG_ID_VOIP_INCOMING_CALL,
        NULL,
        FALSE,
        guiBuffer);
    
    /* must set KEY_EVENT_DOWN function to overwrite original side key handler of category 52 */
    SetKeyHandler(mmi_voip_entry_sidekey, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_voip_entry_sidekey, KEY_VOL_DOWN, KEY_EVENT_DOWN);

    /* any key answer is only applicable to the first incoming call, both for voip and gsm */
    if ((g_voip_cntx_p->call_setting_info.saved_setting.autoAnswer == 1) && 
        (g_voip_cntx_p->call_list_info.numTotal == 1) && (GetTotalCallCount() == 0))
    {
        SetGroupKeyHandler(mmi_voip_entry_answer_call, (U16*)PresentAllKeys, TOTAL_KEYS, KEY_EVENT_DOWN);
    }
    
    SetLeftSoftkeyFunction(mmi_voip_entry_answer_call, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_voip_entry_reject_call, KEY_EVENT_UP);
    SetKeyHandler(mmi_voip_entry_answer_call, KEY_SEND, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_voip_entry_reject_call, KEY_END, KEY_EVENT_DOWN);

    mmi_voip_play_incoming_tone();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_in_call
 * DESCRIPTION
 *  Entry function of in call screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_in_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 rskStr = 0, numItems = 0;
    S32 currhiliteTab = 0, i = 0, j = 0;
    MYTIME currTime, duration;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VOIP_IN_CALL, mmi_voip_exit_in_call, mmi_voip_entry_in_call, NULL);
    DeleteScreenIfPresent(SCR_ID_VOIP_IN_CALL); /* ensure no two active call screens in the history */
    guiBuffer = GetCurrGuiBuffer(SCR_ID_VOIP_IN_CALL);
#ifdef __MMI_BT_SUPPORT__
    if (mmi_bt_is_incall_aud_swap2bt() != MMI_TRUE)
#endif
    {
        rskStr = (g_voip_cntx_p->call_misc_info.isLoud == TRUE) ? (STR_ID_VOIP_HAND_HELD) : (STR_ID_VOIP_HAND_FREE);
    }
    for (i = 0; i < g_voip_cntx_p->call_list_info.numTotal; i++)
    {
        if (g_voip_cntx_p->call_list_info.call_info[i].currState == MMI_VOIP_ACTIVE_STATE)
        {
            MMI_tab_bar_items[i].icon = get_image(IMG_ID_VOIP_CALL_STATE_ACTIVE);
        }
        else if (g_voip_cntx_p->call_list_info.call_info[i].currState == MMI_VOIP_HOLD_STATE)
        {
            MMI_tab_bar_items[i].icon = get_image(IMG_ID_VOIP_CALL_STATE_HOLD);
        }
        else
        {
            PRINT_INFORMATION("\n[mmi_voip_entry_in_call] Call State should either MMI_VOIP_ACTIVE_STATE or MMI_VOIP_HOLD_STATE\n");
        }
        MMI_tab_bar_items[i].text = NULL;
        MMI_tab_bar_items[i].flags = 0; /* no blink */
    }
    currhiliteTab = g_voip_cntx_p->call_misc_info.currhiliteTab;
    DTGetRTCTime(&currTime);
    for (i = 0; i < g_voip_cntx_p->call_list_info.numTotal; i++)
    {
        for (j = 0; j < g_voip_cntx_p->call_list_info.call_info[i].numDialog; j++)
        {
            if ((i == currhiliteTab) && (j == 0))   /* only display duration of the first dialog */
            {
                numItems = g_voip_cntx_p->call_list_info.call_info[i].numDialog;
                /* overflow 2030/12/31/23:59:59 */
                if (g_voip_cntx_p->call_list_info.call_info[i].dialog_info[j].startTime.nYear == 2030 && 
                    currTime.nYear < g_voip_cntx_p->call_list_info.call_info[i].dialog_info[j].startTime.nYear)
                {
                    currTime.nYear = g_voip_cntx_p->call_list_info.call_info[i].dialog_info[j].startTime.nYear;
                    currTime.nMonth = g_voip_cntx_p->call_list_info.call_info[i].dialog_info[j].startTime.nMonth;
                    currTime.nDay = g_voip_cntx_p->call_list_info.call_info[i].dialog_info[j].startTime.nDay + 1;
                }
                GetTimeDifference(
                    &currTime,
                    &g_voip_cntx_p->call_list_info.call_info[i].dialog_info[j].startTime,
                    &duration);
            }
        }
    }
    for (i = 0; i < numItems; i++)
    {
        subMenuDataPtrs[i] = subMenuData[i];
        memset((S8*)subMenuDataPtrs[i], 0, MAX_SUB_MENU_SIZE);
        if (mmi_ucs2strlen((S8*)g_voip_cntx_p->call_list_info.call_info[currhiliteTab].dialog_info[i].dispName) != 0)
        {
            mmi_ucs2ncpy(
                (S8*)subMenuDataPtrs[i],
                (S8*)g_voip_cntx_p->call_list_info.call_info[currhiliteTab].dialog_info[i].dispName,
                VOIP_DISP_NAME_LEN);
        }
        else if (mmi_ucs2strlen((S8*)g_voip_cntx_p->call_list_info.call_info[currhiliteTab].dialog_info[i].appName) != 0)
        {
            mmi_ucs2ncpy(
                (S8*)subMenuDataPtrs[i], 
                (S8*)g_voip_cntx_p->call_list_info.call_info[currhiliteTab].dialog_info[i].appName, 
                VOIP_DISP_NAME_LEN);
        }
        else
        {
            mmi_asc_n_to_ucs2(
                (S8*)subMenuDataPtrs[i],
                (S8*)g_voip_cntx_p->call_list_info.call_info[currhiliteTab].dialog_info[i].remoteUri,
                (MAX_SUBMENU_CHARACTERS - 1));
        }
    }
#if ((defined __MMI_WGUI_CSK_ENABLE__) && (defined __MMI_TOUCH_SCREEN__))
    EnableCenterSoftkey(0, IMG_CSK_DIAL_ICON);
#endif 
    RegisterHighlightHandler(mmi_voip_highlight_in_call_item);
    ShowCategory403Screen(
        (U8*)GetString(STR_ID_VOIP_MAIN),
        GetRootTitleIcon(MENU_ID_VOIP_MAIN),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        rskStr,
        0,
        (S8)g_voip_cntx_p->call_list_info.numTotal,
        (S8)g_voip_cntx_p->call_misc_info.currhiliteTab,
        MMI_tab_bar_items,
        &duration,
        NULL,
        subMenuDataPtrs,
        NULL,
        numItems,
        (U16)g_voip_cntx_p->call_misc_info.currhiliteIndex,
        guiBuffer);
    SetCategory403TabSelectCallback(mmi_voip_tab_jump);
    SetKeyHandler(mmi_voip_tab_prev, KEY_LEFT_ARROW, KEY_EVENT_DOWN);   /* move to previous tab */
    SetKeyHandler(mmi_voip_tab_next, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);  /* move to next tab */

    SetLeftSoftkeyFunction(mmi_voip_entry_call_option, KEY_EVENT_UP);
#ifdef __MMI_BT_SUPPORT__
    if (mmi_bt_is_incall_aud_swap2bt() != MMI_TRUE)
    {
        SetRightSoftkeyFunction(mmi_voip_set_loud_speaker, KEY_EVENT_UP);
    }
#else
    {
        SetRightSoftkeyFunction(mmi_voip_set_loud_speaker, KEY_EVENT_UP);
    }    
#endif /* __MMI_BT_SUPPORT__ */

#if ((defined __MMI_WGUI_CSK_ENABLE__) && (defined __MMI_TOUCH_SCREEN__))
    SetCenterSoftkeyFunction(mmi_voip_pre_send_dtmf, KEY_EVENT_UP);
#endif 

    SetGroupKeyHandler(mmi_voip_pre_send_dtmf, (U16*)VoIPDTMFDigits, MMI_VOIP_MAX_NUM_DIGITS, KEY_EVENT_DOWN);

    SetKeyHandler(mmi_voip_entry_in_call_sendkey, KEY_SEND, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_voip_entry_in_call_endkey, KEY_END, KEY_EVENT_DOWN);

    /* must set KEY_EVENT_DOWN function to overwrite original side key handler of category 52 */
    SetKeyHandler(mmi_voip_entry_sidekey, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_voip_entry_sidekey, KEY_VOL_DOWN, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_exit_in_call
 * DESCRIPTION
 *  Exit function of in call screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_exit_in_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if ((defined __MMI_WGUI_CSK_ENABLE__) && (defined __MMI_TOUCH_SCREEN__))
    ResetCenterSoftkey();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_highlight_in_call_item
 * DESCRIPTION
 *  Highlight index in the active call screen.
 * PARAMETERS
 *  index       [IN]        Current highlight index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_highlight_in_call_item(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_voip_cntx_p->call_misc_info.currhiliteIndex = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_tab_jump
 * DESCRIPTION
 *  Jump to tab based on index for Category403.
 * PARAMETERS
 *  index       [IN]        Current highlight tab
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_tab_jump(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_voip_cntx_p->call_misc_info.currhiliteTab = index;
    g_voip_cntx_p->call_misc_info.currhiliteIndex = 0;
    mmi_voip_entry_in_call();
    DeleteScreenIfPresent(SCR_ID_VOIP_IN_CALL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_tab_prev
 * DESCRIPTION
 *  Move to previous tab for Category403.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_tab_prev(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_voip_cntx_p->call_misc_info.currhiliteTab == 0)
    {
        g_voip_cntx_p->call_misc_info.currhiliteTab = g_voip_cntx_p->call_list_info.numTotal - 1;
    }
    else
    {
        g_voip_cntx_p->call_misc_info.currhiliteTab--;
    }
    g_voip_cntx_p->call_misc_info.currhiliteIndex = 0;
    mmi_voip_entry_in_call();
    DeleteScreenIfPresent(SCR_ID_VOIP_IN_CALL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_tab_next
 * DESCRIPTION
 *  Move to next tab for Category403.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_tab_next(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_voip_cntx_p->call_misc_info.currhiliteTab == g_voip_cntx_p->call_list_info.numTotal - 1)
    {
        g_voip_cntx_p->call_misc_info.currhiliteTab = 0;
    }
    else
    {
        g_voip_cntx_p->call_misc_info.currhiliteTab++;
    }
    g_voip_cntx_p->call_misc_info.currhiliteIndex = 0;
    mmi_voip_entry_in_call();
    DeleteScreenIfPresent(SCR_ID_VOIP_IN_CALL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_tab_highlight
 * DESCRIPTION
 *  Adjust highlight tab for Category403.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_tab_highlight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 callId = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    callId = mmi_voip_get_active_call_id();
    /* active call exists, highlight on active call */
    if (callId != -1)
    {
        g_voip_cntx_p->call_misc_info.currhiliteTab = mmi_voip_get_call_index(callId);
        g_voip_cntx_p->call_misc_info.currhiliteIndex = 0;
    }
    /* no active call, highlight on original call */
    else
    {
        /* original call doesn't exist, highlight on last call */
        if (g_voip_cntx_p->call_misc_info.currhiliteTab > g_voip_cntx_p->call_list_info.numTotal - 1)
        {
            g_voip_cntx_p->call_misc_info.currhiliteTab = g_voip_cntx_p->call_list_info.numTotal - 1;
            g_voip_cntx_p->call_misc_info.currhiliteIndex = 0;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_dtmf_editor
 * DESCRIPTION
 *  Entry function of dtmf editor in call.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_dtmf_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U8 *inputStr = GetCurrInputBuffer(SCR_ID_VOIP_DTMF_EDITOR);
    S32 inputLen = 0, currhiliteTab = 0, callState = MMI_VOIP_IDLE_STATE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VOIP_DTMF_EDITOR, NULL, mmi_voip_entry_dtmf_editor, NULL);
    if (mmi_ucs2strlen((S8*)inputStr) != 0)
    {
        inputLen = (MMI_VOIP_DTMF_LEN > mmi_ucs2strlen((S8*)inputStr)) ? 
            (mmi_ucs2strlen((S8*)inputStr)) : (MMI_VOIP_DTMF_LEN - 1);
        
        memset(g_voip_cntx_p->call_misc_info.dispDtmf, 0, (MMI_VOIP_DTMF_LEN * ENCODING_LENGTH));
        mmi_ucs2ncpy((S8*)g_voip_cntx_p->call_misc_info.dispDtmf, (S8*)inputStr, inputLen);
    }
    guiBuffer = GetCurrGuiBuffer(SCR_ID_VOIP_DTMF_EDITOR);
    ShowCategory16Screen(
        STR_GLOBAL_SAVE,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        g_voip_cntx_p->call_misc_info.dispDtmf,
        MMI_VOIP_DTMF_LEN,
        guiBuffer);
    wgui_save_key_handlers();
    SetLeftSoftkeyFunction(mmi_voip_entry_save_phonebook, KEY_EVENT_UP);
    SetCategory16RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    currhiliteTab = g_voip_cntx_p->call_misc_info.currhiliteTab;
    callState = g_voip_cntx_p->call_list_info.call_info[currhiliteTab].currState;
    if ((callState == MMI_VOIP_ACTIVE_STATE) && (g_voip_cntx_p->call_misc_info.isDtmf == TRUE))
    {
        SetGroupKeyHandler(mmi_voip_dtmf_key_down, (U16*)VoIPDTMFDigits, MMI_VOIP_MAX_NUM_DIGITS, KEY_EVENT_DOWN);
        SetGroupKeyHandler(mmi_voip_dtmf_key_up, (U16*)VoIPDTMFDigits, MMI_VOIP_MAX_NUM_DIGITS, KEY_EVENT_UP);
        SetGroupKeyHandler(MMI_dummy_function, (U16*)VoIPDTMFDigits, MMI_VOIP_MAX_NUM_DIGITS, KEY_EVENT_LONG_PRESS);
        SetGroupKeyHandler(MMI_dummy_function, (U16*)VoIPDTMFDigits, MMI_VOIP_MAX_NUM_DIGITS, KEY_EVENT_REPEAT);
    }
    else
    {
        SetGroupKeyHandler(MMI_dummy_function, (U16*)VoIPDTMFDigits, MMI_VOIP_MAX_NUM_DIGITS, KEY_EVENT_DOWN);
        SetGroupKeyHandler(MMI_dummy_function, (U16*)VoIPDTMFDigits, MMI_VOIP_MAX_NUM_DIGITS, KEY_EVENT_UP);
        SetGroupKeyHandler(MMI_dummy_function, (U16*)VoIPDTMFDigits, MMI_VOIP_MAX_NUM_DIGITS, KEY_EVENT_LONG_PRESS);
        SetGroupKeyHandler(MMI_dummy_function, (U16*)VoIPDTMFDigits, MMI_VOIP_MAX_NUM_DIGITS, KEY_EVENT_REPEAT);
    }

    SetKeyHandler(mmi_voip_entry_in_call_endkey, KEY_END, KEY_EVENT_DOWN);

    /* must set KEY_EVENT_DOWN function to overwrite original side key handler of category 52 */
    SetKeyHandler(mmi_voip_entry_sidekey, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_voip_entry_sidekey, KEY_VOL_DOWN, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_call_option
 * DESCRIPTION
 *  Entry function of call option screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_call_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U16 nStrItemList[MAX_SUB_MENUS];
    U8 *nHintItemList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VOIP_CALL_OPTION, NULL, mmi_voip_entry_call_option, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_VOIP_CALL_OPTION);
    SetParentHandler(MENU_ID_VOIP_CALL_OPTION);
    mmi_voip_hide_call_option();
    numItems = GetNumOfChild_Ext(MENU_ID_VOIP_CALL_OPTION);
    GetSequenceStringIds_Ext(MENU_ID_VOIP_CALL_OPTION, nStrItemList);
    ConstructHintsList(MENU_ID_VOIP_CALL_OPTION, nHintItemList);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ShowCategory52Screen(
        STR_ID_VOIP_CALL_OPTION,
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

    SetKeyHandler(mmi_voip_entry_in_call_endkey, KEY_END, KEY_EVENT_DOWN);

    /* must set KEY_EVENT_DOWN function to overwrite original side key handler of category 52 */
    SetKeyHandler(mmi_voip_entry_sidekey, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_voip_entry_sidekey, KEY_VOL_DOWN, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_hide_call_option
 * DESCRIPTION
 *  Hide and unhide call option menu item based on current state.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_hide_call_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 currhiliteTab = 0, callIndex = 0, callId = 0, othercallId = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currhiliteTab = g_voip_cntx_p->call_misc_info.currhiliteTab;
    callId = g_voip_cntx_p->call_list_info.call_info[currhiliteTab].callId;

    if (g_voip_cntx_p->call_list_info.numHeld < MMI_VOIP_MAX_HELD_CALL)
    {
        if (g_voip_cntx_p->call_list_info.call_info[currhiliteTab].currState == MMI_VOIP_ACTIVE_STATE)
        {
            if (g_voip_cntx_p->call_list_info.call_info[currhiliteTab].numDialog == 1)
            {
                mmi_frm_unhide_menu_item(MENU_ID_VOIP_HOLD_SINGLE);
                mmi_frm_hide_menu_item(MENU_ID_VOIP_HOLD_CONFERENCE);
                mmi_frm_hide_menu_item(MENU_ID_VOIP_SPLIT);
            }
            else    /* conference call */
            {
                mmi_frm_hide_menu_item(MENU_ID_VOIP_HOLD_SINGLE);
                mmi_frm_unhide_menu_item(MENU_ID_VOIP_HOLD_CONFERENCE);
                mmi_frm_unhide_menu_item(MENU_ID_VOIP_SPLIT);
            }
        }
        else    /* not active */
        {
            mmi_frm_hide_menu_item(MENU_ID_VOIP_HOLD_SINGLE);
            mmi_frm_hide_menu_item(MENU_ID_VOIP_HOLD_CONFERENCE);
            mmi_frm_hide_menu_item(MENU_ID_VOIP_SPLIT);
        }
    }
    else    /* call boundary exceeds */
    {
        mmi_frm_hide_menu_item(MENU_ID_VOIP_HOLD_SINGLE);
        mmi_frm_hide_menu_item(MENU_ID_VOIP_HOLD_CONFERENCE);
        mmi_frm_hide_menu_item(MENU_ID_VOIP_SPLIT);
    }

    if (mmi_voip_get_active_call_id() == -1)
    {
        if (g_voip_cntx_p->call_list_info.call_info[currhiliteTab].currState == MMI_VOIP_HOLD_STATE)
        {
            if (g_voip_cntx_p->call_list_info.call_info[currhiliteTab].numDialog == 1)
            {
                mmi_frm_unhide_menu_item(MENU_ID_VOIP_RETRIEVE_SINGLE);
                mmi_frm_hide_menu_item(MENU_ID_VOIP_RETRIEVE_CONFERENCE);
            }
            else    /* conference call */
            {
                mmi_frm_hide_menu_item(MENU_ID_VOIP_RETRIEVE_SINGLE);
                mmi_frm_unhide_menu_item(MENU_ID_VOIP_RETRIEVE_CONFERENCE);
            }
        }
        else    /* not held */
        {
            mmi_frm_hide_menu_item(MENU_ID_VOIP_RETRIEVE_SINGLE);
            mmi_frm_hide_menu_item(MENU_ID_VOIP_RETRIEVE_CONFERENCE);
        }
    }
    else    /* active call exists */
    {
        mmi_frm_hide_menu_item(MENU_ID_VOIP_RETRIEVE_SINGLE);
        mmi_frm_hide_menu_item(MENU_ID_VOIP_RETRIEVE_CONFERENCE);
    }

    /* swap */
    if (((g_voip_cntx_p->call_list_info.call_info[currhiliteTab].currState == MMI_VOIP_ACTIVE_STATE) &&
         (g_voip_cntx_p->call_list_info.numHeld > 0)) ||
        ((g_voip_cntx_p->call_list_info.call_info[currhiliteTab].currState == MMI_VOIP_HOLD_STATE) &&
         (mmi_voip_get_active_call_id() != -1)))
    {
        mmi_frm_unhide_menu_item(MENU_ID_VOIP_SWAP);
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_ID_VOIP_SWAP);
    }

    /* conference */
    if ((g_voip_cntx_p->call_list_info.call_info[currhiliteTab].currState == MMI_VOIP_ACTIVE_STATE) &&
        (g_voip_cntx_p->call_list_info.call_info[currhiliteTab].numDialog == 1))
    {
        mmi_voip_get_held_call_list(TRUE);
        othercallId = g_voip_cntx_p->call_list_info.held_call_info[0].callId;
        if (othercallId != -1)  /* at least one single held call */
        {
            mmi_frm_unhide_menu_item(MENU_ID_VOIP_CONFERENCE);
        }
        else
        {
            mmi_frm_hide_menu_item(MENU_ID_VOIP_CONFERENCE);
        }
    }
    else if ((g_voip_cntx_p->call_list_info.call_info[currhiliteTab].currState == MMI_VOIP_HOLD_STATE) &&
             (g_voip_cntx_p->call_list_info.call_info[currhiliteTab].numDialog == 1))
    {
        othercallId = mmi_voip_get_active_call_id();
        if (othercallId != -1)  /* other active call exists */
        {
            callIndex = mmi_voip_get_call_index(othercallId);
            if (g_voip_cntx_p->call_list_info.call_info[callIndex].numDialog == 1)
            {
                mmi_frm_unhide_menu_item(MENU_ID_VOIP_CONFERENCE);
            }
            else
            {
                mmi_frm_hide_menu_item(MENU_ID_VOIP_CONFERENCE);
            }
        }
        else
        {
            mmi_frm_hide_menu_item(MENU_ID_VOIP_CONFERENCE);
        }
    }
    else    /* not single active and not single held */
    {
        mmi_frm_hide_menu_item(MENU_ID_VOIP_CONFERENCE);
    }

    /* end conference */
    if (g_voip_cntx_p->call_list_info.call_info[currhiliteTab].numDialog != 1)  /* conference call */
    {
        mmi_frm_unhide_menu_item(MENU_ID_VOIP_END_CONFERENCE);
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_ID_VOIP_END_CONFERENCE);
    }

    /* end all */
    if (g_voip_cntx_p->call_list_info.numTotal >= 2)
    {
        mmi_frm_unhide_menu_item(MENU_ID_VOIP_END_ALL);
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_ID_VOIP_END_ALL);
    }

    /* transfer */
    if (g_voip_cntx_p->call_list_info.call_info[currhiliteTab].numDialog == 1)
    {
        mmi_frm_unhide_menu_item(MENU_ID_VOIP_TRANSFER);
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_ID_VOIP_TRANSFER);
    }

    /* sound recorder, mute and dtmf */
    if (g_voip_cntx_p->call_list_info.call_info[currhiliteTab].currState == MMI_VOIP_ACTIVE_STATE)
    {
    #ifdef __MMI_SOUND_RECORDER__
        mmi_frm_unhide_menu_item(MENU_ID_VOIP_SOUND_RECORDER);
    #else
        mmi_frm_hide_menu_item(MENU_ID_VOIP_SOUND_RECORDER);
    #endif
        mmi_frm_unhide_menu_item(MENU_ID_VOIP_MUTE);
        if (g_voip_cntx_p->call_setting_info.saved_setting.dtmf == VOIP_DTMF_TYPE_NONE) /* DTMF in call setting is off */
        {
            mmi_frm_hide_menu_item(MENU_ID_VOIP_DTMF);
        }
        else
        {
            mmi_frm_unhide_menu_item(MENU_ID_VOIP_DTMF);
        }
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_ID_VOIP_SOUND_RECORDER);
        mmi_frm_hide_menu_item(MENU_ID_VOIP_MUTE);
        mmi_frm_hide_menu_item(MENU_ID_VOIP_DTMF);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_transfer
 * DESCRIPTION
 *  Entry function of call option\Transfer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_transfer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VOIP_TRANSFER, NULL, mmi_voip_entry_transfer, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_VOIP_TRANSFER);
    ShowCategory404Screen(
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        IMG_ID_VOIP_CALL_EDITOR,
        g_voip_cntx_p->call_misc_info.dispUri,
        VOIP_URI_LEN,
        guiBuffer);
    SetLeftSoftkeyFunction(mmi_voip_entry_transfer_option, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(mmi_voip_entry_in_call_endkey, KEY_END, KEY_EVENT_DOWN);

    /* must set KEY_EVENT_DOWN function to overwrite original side key handler of category 52 */
    SetKeyHandler(mmi_voip_entry_sidekey, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_voip_entry_sidekey, KEY_VOL_DOWN, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_transfer_option
 * DESCRIPTION
 *  Entry function of transfer option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_transfer_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U16 nStrItemList[MAX_SUB_MENUS]; /* Transfer, Input Method */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VOIP_TRANSFER_OPTION, NULL, mmi_voip_entry_transfer_option, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_VOIP_TRANSFER_OPTION);
    SetParentHandler(MENU_ID_VOIP_TRANSFER_OPTION);
    numItems = GetNumOfChild(MENU_ID_VOIP_TRANSFER_OPTION);
    GetSequenceStringIds(MENU_ID_VOIP_TRANSFER_OPTION, nStrItemList);
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

    /* ensure at least one call exists, otherwise side key behavior should be the same as up/down arrow */
    if (g_voip_cntx_p->call_list_info.numTotal > 0)
    {
        /* must set KEY_EVENT_DOWN function to overwrite original side key handler of category 52 */
        SetKeyHandler(mmi_voip_entry_sidekey, KEY_VOL_UP, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_voip_entry_sidekey, KEY_VOL_DOWN, KEY_EVENT_DOWN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_multi_held_call
 * DESCRIPTION
 *  Entry function of call option\Swap or Conference
 *  if more than one held calls can be selected.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_multi_held_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    S32 callId = 0, i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VOIP_MULTI_HELD_CALL, NULL, mmi_voip_entry_multi_held_call, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_VOIP_MULTI_HELD_CALL);
    callId = g_voip_cntx_p->call_list_info.held_call_info[i].callId;
    while ((i < MMI_VOIP_MAX_HELD_CALL) && (callId != -1))
    {
        subMenuDataPtrs[i] = subMenuData[i];
        memset(subMenuDataPtrs[i], 0, MAX_SUB_MENU_SIZE);
        if (mmi_ucs2strlen((S8*)g_voip_cntx_p->call_list_info.held_call_info[i].dispName) != 0)
        {
            mmi_ucs2ncpy(
                (S8*)subMenuDataPtrs[i],
                (S8*)g_voip_cntx_p->call_list_info.held_call_info[i].dispName,
                VOIP_DISP_NAME_LEN);
        }
        else if (mmi_ucs2strlen((S8*)g_voip_cntx_p->call_list_info.held_call_info[i].appName) != 0)
        {
            mmi_ucs2ncpy(
                (S8*)subMenuDataPtrs[i],
                (S8*)g_voip_cntx_p->call_list_info.held_call_info[i].appName,
                VOIP_DISP_NAME_LEN);
        }
        else
        {
            mmi_asc_n_to_ucs2(
                (S8*)subMenuDataPtrs[i],
                (S8*)g_voip_cntx_p->call_list_info.held_call_info[i].remoteUri,
                (MAX_SUBMENU_CHARACTERS - 1));
        }
        i++;
        if (i < MMI_VOIP_MAX_HELD_CALL)
        {
            callId = g_voip_cntx_p->call_list_info.held_call_info[i].callId;
        }
    }
    RegisterHighlightHandler(mmi_voip_highlight_multi_held_call_item);
    ShowCategory6Screen(
        STR_ID_VOIP_CALL_OPTION,
        GetRootTitleIcon(MENU_ID_VOIP_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        i,
        subMenuDataPtrs,
        NULL,
        0,
        guiBuffer);
    SetLeftSoftkeyFunction(mmi_voip_entry_held_call_selected, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(mmi_voip_entry_in_call_endkey, KEY_END, KEY_EVENT_DOWN);

    /* must set KEY_EVENT_DOWN function to overwrite original side key handler of category 52 */
    SetKeyHandler(mmi_voip_entry_sidekey, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_voip_entry_sidekey, KEY_VOL_DOWN, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_highlight_multi_held_call_item
 * DESCRIPTION
 *  Highlight index in the mutliple held calls screen.
 * PARAMETERS
 *  index       [IN]        Current highlight index.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_highlight_multi_held_call_item(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_voip_cntx_p->call_misc_info.currhiliteIndex = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_set_loud_speaker
 * DESCRIPTION
 *  Turn on and turn off loud speaker in call.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_set_loud_speaker(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_voip_cntx_p->call_misc_info.isLoud == TRUE)
    {
        g_voip_cntx_p->call_misc_info.isLoud = FALSE;
        if (GetExitScrnID() == SCR_ID_VOIP_IN_CALL)
        {
            ChangeRightSoftkey(STR_ID_VOIP_HAND_FREE, 0);
        }
        DisbleHandsFree();
        SetLoudSpeaker(FALSE);
        mmi_voip_entry_popup((U8*)GetString(STR_ID_VOIP_LOUD_SPEAKER_OFF), IMG_GLOBAL_ACTIVATED);
    }
    else
    {
        g_voip_cntx_p->call_misc_info.isLoud = TRUE;
        if (GetExitScrnID() == SCR_ID_VOIP_IN_CALL)
        {
            ChangeRightSoftkey(STR_ID_VOIP_HAND_HELD, 0);
        }
        EnableHandsFree();
        SetLoudSpeaker(TRUE);
        mmi_voip_entry_popup((U8*)GetString(STR_ID_VOIP_LOUD_SPEAKER_ON), IMG_GLOBAL_ACTIVATED);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_set_mute
 * DESCRIPTION
 *  Turn on and turn off microphone in call option.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_set_mute(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_voip_cntx_p->call_misc_info.isMute == TRUE)
    {
        g_voip_cntx_p->call_misc_info.isMute = FALSE;
        MuteOffMicrophone();
        HideStatusIcon(STATUS_ICON_MUTE);
        UpdateStatusIcons();
        mmi_ucs2cpy((S8*) hintData[GetCurrHiliteID()], (S8*) GetString(STR_GLOBAL_OFF));
        Category52ChangeItemDescription(GetCurrHiliteID(), (U8*) GetString(STR_GLOBAL_OFF));
        ChangeLeftSoftkey(STR_GLOBAL_ON, IMG_GLOBAL_OK);
    }
    else
    {
        g_voip_cntx_p->call_misc_info.isMute = TRUE;
        MuteOnMicrophone();
        ShowStatusIcon(STATUS_ICON_MUTE);
        UpdateStatusIcons();
        mmi_ucs2cpy((S8*) hintData[GetCurrHiliteID()], (S8*) GetString(STR_GLOBAL_ON));
        Category52ChangeItemDescription(GetCurrHiliteID(), (U8*) GetString(STR_GLOBAL_ON));
        ChangeLeftSoftkey(STR_GLOBAL_OFF, IMG_GLOBAL_OK);
    }
    RedrawCategoryFunction();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_set_dtmf_in_call
 * DESCRIPTION
 *  Temporarily turn on and turn off DTMF in call option.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_set_dtmf_in_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_voip_cntx_p->call_misc_info.isDtmf == TRUE)
    {
        g_voip_cntx_p->call_misc_info.isDtmf = FALSE;
        mmi_ucs2cpy((S8*) hintData[GetCurrHiliteID()], (S8*) GetString(STR_GLOBAL_OFF));
        Category52ChangeItemDescription(GetCurrHiliteID(), (U8*) GetString(STR_GLOBAL_OFF));
        ChangeLeftSoftkey(STR_GLOBAL_ON, IMG_GLOBAL_OK);
    }
    else
    {
        g_voip_cntx_p->call_misc_info.isDtmf = TRUE;
        mmi_ucs2cpy((S8*) hintData[GetCurrHiliteID()], (S8*) GetString(STR_GLOBAL_ON));
        Category52ChangeItemDescription(GetCurrHiliteID(), (U8*) GetString(STR_GLOBAL_ON));
        ChangeLeftSoftkey(STR_GLOBAL_OFF, IMG_GLOBAL_OK);
    }
    RedrawCategoryFunction();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_popup
 * DESCRIPTION
 *  Entry function of VoIP popup.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_popup(U8 *string, U16 imageId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_POPUP_SCREEN, mmi_voip_exit_popup, NULL, NULL);
    if ((g_voip_cntx_p->call_list_info.numTotal == 1) && (imageId == IMG_ID_VOIP_CALL_ENDED))
    {
        mmi_voip_play_droptone();
    }
    ShowCategory63Screen(string, imageId, NULL);
    StartTimer(VOIP_POPUP_TIMER, MMI_VOIP_GENERAL_TIMEOUT, mmi_voip_entry_popup_over);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_exit_popup
 * DESCRIPTION
 *  Exit function of VoIP popup.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_exit_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("\n[mmi_voip_exit_popup] Popup Finish\n");
    mmi_voip_stop_droptone();
    StopTimer(VOIP_POPUP_TIMER);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_popup_over
 * DESCRIPTION
 *  Entry function when popup timer expiry.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_popup_over(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("\n[mmi_voip_entry_popup_over] Timer Expiry\n");
    mmi_voip_stop_droptone();
    StopTimer(VOIP_POPUP_TIMER);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_marker
 * DESCRIPTION
 *  Entry function of VoIP marker.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_marker(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!IsScreenPresent(SCR_ID_VOIP_MARKER)) /* ensure no two voip markers in the history */
    {
        EntryNewScreen(SCR_ID_VOIP_MARKER, NULL, mmi_voip_entry_marker, NULL);    
        ShowCategoryDummyScreen();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_go_back_screen_check
 * DESCRIPTION
 *  Go back to screen based on current state.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_go_back_screen_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* pending action exists, do not adjust history */
    if (g_voip_cntx_p->call_list_info.processCId == -1)
    {
        if ((mmi_voip_get_incoming_call_id() != -1) &&
            (mmi_voip_get_incoming_call_id() != g_voip_cntx_p->call_list_info.bkrejCId))
        {
            if (!IsScreenPresent(SCR_ID_VOIP_INCOMING_CALL))
            {
                mmi_voip_entry_incoming_call();
            }
            /* force to add processing screen to history when current screen is processing screen.
               it is to prevent no popup case so that processing screen is not deleted */
            else if ((GetExitScrnID() == SCR_ID_VOIP_PROCESSING) || (GetExitScrnID() == SCR_ID_VOIP_OUTGOING_CALL))
            {
                EntryNewScreen(GLOBAL_SCR_DUMMY, NULL, NULL, NULL);
            }
            DeleteScreenIfPresent(SCR_ID_VOIP_PROCESSING);
            DeleteScreenIfPresent(SCR_ID_VOIP_REDIALING_CALL);
            DeleteScreenIfPresent(SCR_ID_VOIP_OUTGOING_CALL);
            DeleteScreenIfPresent(SCR_ID_VOIP_CALL_EDITOR_OPTION);
            DeleteScreenIfPresent(SCR_ID_VOIP_CALL_EDITOR);
            DeleteScreenIfPresent(SCR_ID_VOIP_MULTI_HELD_CALL);
            DeleteScreenIfPresent(SCR_ID_VOIP_TRANSFER_OPTION);
            DeleteScreenIfPresent(SCR_ID_VOIP_TRANSFER);
            DeleteScreenIfPresent(SCR_ID_VOIP_CALL_OPTION);
            DeleteScreenIfPresent(SCR_ID_VOIP_DTMF_EDITOR);
            DeleteScreenIfPresent(SCR_ID_VOIP_IN_CALL);
            if (GetExitScrnID() == GLOBAL_SCR_DUMMY)
            {
                DeleteUptoScrID(SCR_ID_VOIP_INCOMING_CALL);
                GoBackHistory(); /* go back to incoming call screen */
            }
            // mmi_voip_play_incoming_tone();
        }
        else if (mmi_voip_get_outgoing_call_id() != -1)
        {
            if (!IsScreenPresent(SCR_ID_VOIP_OUTGOING_CALL))
            {
                mmi_voip_entry_outgoing_call();
            }
            /* force to add processing screen to history when current screen is processing screen.
               it is to prevent no popup case so that processing screen is not deleted */
            else if ((GetExitScrnID() == SCR_ID_VOIP_PROCESSING) || (GetExitScrnID() == SCR_ID_VOIP_OUTGOING_CALL))
            {
                EntryNewScreen(GLOBAL_SCR_DUMMY, NULL, NULL, NULL);
            }
            DeleteScreenIfPresent(SCR_ID_VOIP_PROCESSING);
            DeleteScreenIfPresent(SCR_ID_VOIP_REDIALING_CALL);
            DeleteScreenIfPresent(SCR_ID_VOIP_INCOMING_CALL);
            DeleteScreenIfPresent(SCR_ID_VOIP_CALL_EDITOR_OPTION);
            DeleteScreenIfPresent(SCR_ID_VOIP_CALL_EDITOR);
            DeleteScreenIfPresent(SCR_ID_VOIP_MULTI_HELD_CALL);
            DeleteScreenIfPresent(SCR_ID_VOIP_TRANSFER_OPTION);
            DeleteScreenIfPresent(SCR_ID_VOIP_TRANSFER);
            DeleteScreenIfPresent(SCR_ID_VOIP_CALL_OPTION);
            DeleteScreenIfPresent(SCR_ID_VOIP_DTMF_EDITOR);
            DeleteScreenIfPresent(SCR_ID_VOIP_IN_CALL);
            if (GetExitScrnID() == GLOBAL_SCR_DUMMY)
            {
                DeleteUptoScrID(SCR_ID_VOIP_OUTGOING_CALL);
                GoBackHistory(); /* go back to outgoing call screen */
            }
        }
        else
        {
            mmi_voip_tab_highlight(); /* no matter call exists or not, adjust tab highlight */
            if ((mmi_voip_get_active_call_id() != -1) || (g_voip_cntx_p->call_list_info.numHeld > 0))
            {
                if (!IsScreenPresent(SCR_ID_VOIP_IN_CALL))
                {
                    mmi_voip_entry_in_call();
                }
                /* force to add processing screen to history when current screen is processing screen.
                   it is to prevent no popup case so that processing screen is not deleted */
                else if ((GetExitScrnID() == SCR_ID_VOIP_PROCESSING) || (GetExitScrnID() == SCR_ID_VOIP_OUTGOING_CALL))
                {
                    EntryNewScreen(GLOBAL_SCR_DUMMY, NULL, NULL, NULL);
                }
                DeleteScreenIfPresent(SCR_ID_VOIP_PROCESSING);
                DeleteScreenIfPresent(SCR_ID_VOIP_REDIALING_CALL);
                DeleteScreenIfPresent(SCR_ID_VOIP_INCOMING_CALL);
                DeleteScreenIfPresent(SCR_ID_VOIP_OUTGOING_CALL);
                DeleteScreenIfPresent(SCR_ID_VOIP_CALL_EDITOR_OPTION);
                DeleteScreenIfPresent(SCR_ID_VOIP_CALL_EDITOR);
                DeleteScreenIfPresent(SCR_ID_VOIP_MULTI_HELD_CALL);
                DeleteScreenIfPresent(SCR_ID_VOIP_TRANSFER_OPTION);
                DeleteScreenIfPresent(SCR_ID_VOIP_TRANSFER);
                DeleteScreenIfPresent(SCR_ID_VOIP_CALL_OPTION);
                DeleteScreenIfPresent(SCR_ID_VOIP_DTMF_EDITOR);
                if (GetExitScrnID() == GLOBAL_SCR_DUMMY)
                {
                    DeleteUptoScrID(SCR_ID_VOIP_IN_CALL);
                    GoBackHistory(); /* go back to active call screen */
                }
            }
            else
            {
                /* force to add processing screen to history when current screen is processing screen.
                   it is to prevent no popup case so that processing screen is not deleted */
                if ((GetExitScrnID() == SCR_ID_VOIP_PROCESSING) || (GetExitScrnID() == SCR_ID_VOIP_OUTGOING_CALL))
                {
                    EntryNewScreen(GLOBAL_SCR_DUMMY, NULL, NULL, NULL);
                }
                DeleteScreenIfPresent(SCR_ID_VOIP_PROCESSING);
                DeleteScreenIfPresent(SCR_ID_VOIP_REDIALING_CALL);
                DeleteScreenIfPresent(SCR_ID_VOIP_INCOMING_CALL);
                DeleteScreenIfPresent(SCR_ID_VOIP_OUTGOING_CALL);
                DeleteScreenIfPresent(SCR_ID_VOIP_CALL_EDITOR_OPTION);
                DeleteScreenIfPresent(SCR_ID_VOIP_CALL_EDITOR);
                DeleteScreenIfPresent(SCR_ID_VOIP_MULTI_HELD_CALL);
                DeleteScreenIfPresent(SCR_ID_VOIP_TRANSFER_OPTION);
                DeleteScreenIfPresent(SCR_ID_VOIP_TRANSFER);
                DeleteScreenIfPresent(SCR_ID_VOIP_CALL_OPTION);
                DeleteScreenIfPresent(SCR_ID_VOIP_DTMF_EDITOR);
                DeleteScreenIfPresent(SCR_ID_VOIP_IN_CALL);
                DeleteScreenIfPresent(SCR_ID_VOIP_MARKER);
                if (GetExitScrnID() == GLOBAL_SCR_DUMMY)
                {
                    GoBackHistory();
                }
            }
        }
    }
}
#endif /* __MMI_VOIP__ */

