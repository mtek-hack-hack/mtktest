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
/*******************************************************************************
 *  Modification Notice:
 *  --------------------------
 *  This software is modified by MediaTek Inc. and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2001
 *
 *******************************************************************************/

 /*******************************************************************************
 * Filename:
 * ---------
 *   TextPhoneControl.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  .......
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Log$
 *
 * removed!
 * removed!
 * created by clearfsimport
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * created by clearfsimport
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * created by clearfsimport
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 *******************************************************************************/
#include "MMI_include.h"

#ifndef __MMI_UCM__

#ifdef __CTM_SUPPORT__

// #define __CTM_DEBUG

#include "CommonScreens.h"

#include "wgui_status_icons.h"
#include "wgui_tab_bars.h"

#include "gpioInc.h"
#include "SettingProfile.h"
#include "CallManagementIDDef.h"
#include "CallManagementStruct.h"
#include "OutgoingCallHelperProt.h"
#include "OutgoingCallManagementProt.h"
#include "CallManagementGprot.h"

#include "ProfileGprots.h"
#include "IdleAppProt.h"

#include "TextPhoneDef.h"
#include "TextPhoneProt.h"


static mmi_ctm_context_struct g_ctm_cntxt;
mmi_ctm_context_struct *ctm_p = &g_ctm_cntxt;


/*****************************************************************************
 * FUNCTION
 *  mmi_init_ctm_call
 * DESCRIPTION
 *  To Initialize the CTM Call application
 *  
 *  This function sets up the handlers required for event flow and
 *  application management
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_init_ctm_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(ctm_p, 0, sizeof(mmi_ctm_context_struct));

    ReadValue(NVRAM_CTM_MODE, &ctm_p->status, DS_BYTE, &error);
    ReadValue(NVRAM_CTM_SETTING, &ctm_p->mode_setting, DS_BYTE, &error);
    if (ctm_p->status == 0xff)
    {
        ctm_p->status = FALSE;
    }
    if (ctm_p->mode_setting == 0xff)
    {
        ctm_p->mode_setting = MMI_CTM_SETTING_MANUAL_DIRECT;
    }

    mmi_ctm_send_get_default_req();

    SetHiliteHandler(MITEM_CTM_MENU, highlight_ctm_main);
    SetHiliteHandler(MITEM_CTM_MODE, highlight_ctm_mode);
    SetHiliteHandler(MITEM_CTM_SETTING, highlight_ctm_setting);

    SetHiliteHandler(MITEM_CTM_EDITOR_DONE, highlight_ctm_edit_done);
    SetHiliteHandler(MITEM_CTM_INPUT_METHOD, highlight_ctm_input_method);

    SetHintHandler(MITEM_CTM_MODE, hint_ctm_mode);

    SetProtocolEventHandler(mmi_ctm_get_default_rsp_hdlr, MSG_ID_MMI_CTM_DEFAULT_CHANGED_IND);
    SetProtocolEventHandler(mmi_ctm_connect_ind_hdlr, MSG_ID_MMI_CTM_CONNECTED_IND);
    SetProtocolEventHandler(mmi_ctm_recv_text_ind_hdlr, MSG_ID_MMI_CTM_RECV_TEXT_IND);
    /* SetProtocolEventHandler (mmi_ctm_tty_plug_ind_hdlr, MSG_ID_MMI_CTM_TTY_PLUG_IND); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ctm_get_state
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  void(?)     [IN]        *
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_ctm_get_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (U8) ctm_p->state;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ctm_set_state
 * DESCRIPTION
 *  
 * PARAMETERS
 *  state       [IN]        
 *  void(?)     [IN]        *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ctm_set_state(U8 state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("\n SET CTM STATE:%d \n", state);

    ctm_p->state = state;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ctm_reset_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  void(?)     [IN]        *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ctm_reset_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(ctm_p->remote_buffer, 0, MAX_CTM_DATA_BUFFER_LEN);
    memset(ctm_p->local_buffer, 0, MAX_CTM_DATA_BUFFER_LEN);
    memset(ctm_p->pending_buffer, 0, MAX_CTM_EDITOR_BUFFER_LEN);
    memset(ctm_p->editor_buffer, 0, MAX_CTM_EDITOR_BUFFER_LEN);
    ctm_p->remote_len = 0;
    ctm_p->local_len = 0;
    ctm_p->pending_len = 0;
    ctm_p->sent_len = 0;
}


/*****************************************************************************
 * FUNCTION
 *  highlight_ctm_main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  void(?)     [IN]        *
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_ctm_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    SetLeftSoftkeyFunction(entry_ctm_menu, KEY_EVENT_UP);
    SetKeyHandler(entry_ctm_menu, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  highlight_ctm_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  void(?)     [IN]        *
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_ctm_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ctm_p->status == TRUE)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OFF, 0);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_ON, 0);
    }

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_ctm_toggle_mode, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  highlight_ctm_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  void(?)     [IN]        *
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_ctm_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    SetLeftSoftkeyFunction(entry_ctm_setting_selection, KEY_EVENT_UP);
    SetKeyHandler(entry_ctm_setting_selection, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  highlight_ctm_setting_items
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 *  void(?)     [IN]        *
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_ctm_setting_items(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ctm_p->index = index;
}


/*****************************************************************************
 * FUNCTION
 *  highlight_ctm_edit_done
 * DESCRIPTION
 *  highlight handler for change input method in editor option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_ctm_edit_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_ctm_edit_done, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  highlight_ctm_input_method
 * DESCRIPTION
 *  highlight handler for change input method in editor option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_ctm_input_method(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(EntryInputMethodScreen, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  hint_ctm_mode
 * DESCRIPTION
 *  hint
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void hint_ctm_mode(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ctm_p->status == TRUE)
    {
        mmi_ucs2cpy((S8*) hintData[index], (S8*) GetString(STR_GLOBAL_ON));
    }
    else
    {
        mmi_ucs2cpy((S8*) hintData[index], (S8*) GetString(STR_GLOBAL_OFF));
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ctm_set_default_rsp_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ctm_set_default_rsp_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pBOOL result = TRUE;

#ifndef __CTM_DEBUG
    mmi_ctm_set_default_rsp_struct *rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (mmi_ctm_set_default_rsp_struct*) info;
    result = rsp->result;
#endif /* __CTM_DEBUG */ 

    PRINT_INFORMATION("\n CTM SET DEFAULT RSP \n");

    if (result == TRUE)
    {

    }
    else
    {

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ctm_get_default_rsp_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ctm_get_default_rsp_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pBOOL result = TRUE;
    pBOOL on_off = TRUE;
    U8 mode = CTM_DIRECT_MODE;
    U8 mmi_mode = 0;

#ifndef __CTM_DEBUG
    mmi_ctm_get_default_rsp_struct *rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (mmi_ctm_get_default_rsp_struct*) info;
    result = rsp->result;
    on_off = rsp->is_turn_on;
    mode = rsp->ctm_interface;
#endif /* __CTM_DEBUG */ 

    PRINT_INFORMATION("\n CTM GET DEFAULT RSP \n");

    if (result == TRUE)
    {
        S16 error;

        if (ctm_p->status != on_off)
        {
            ctm_p->status = on_off;
            WriteValue(NVRAM_CTM_MODE, &ctm_p->status, DS_BYTE, &error);
        }
        switch (mode)
        {
            case CTM_BAUDOT_MODE:
                mmi_mode = MMI_CTM_SETTING_BAUDOT;
                break;
            case CTM_HCO_MODE:
                mmi_mode = MMI_CTM_SETTING_HCO;
                break;
            case CTM_VCO_MODE:
                mmi_mode = MMI_CTM_SETTING_VCO;
                break;
            case CTM_DIRECT_MODE:
                /* MMI mode_setting should be auto or manual direct */
                if (ctm_p->mode_setting != MMI_CTM_SETTING_MANUAL_DIRECT &&
                    ctm_p->mode_setting != MMI_CTM_SETTING_AUTO_DIRECT)
                {
                    mmi_mode = MMI_CTM_SETTING_MANUAL_DIRECT;
                }
                else
                {
                    mmi_mode = ctm_p->mode_setting;
                }
                break;
            default:
                ASSERT(0);
                break;
        }

        /* MMI mode setting should be the same as L4 mode */
        if (mmi_mode != ctm_p->mode_setting)
        {
            ctm_p->mode_setting = mmi_mode;
            WriteValue(NVRAM_CTM_SETTING, &ctm_p->mode_setting, DS_BYTE, &error);
        }

        if (ctm_p->status == TRUE)
        {
            ShowStatusIcon(STATUS_ICON_TTY_INDICATOR);
            /* only hide earphone when it's real tty, 
               direct mode still take as earphone */
            if (ctm_p->mode_setting < MMI_CTM_SETTING_MANUAL_DIRECT)
            HideStatusIcon(STATUS_ICON_EARPHONE_INDICATOR);
        }
        else
        {
            HideStatusIcon(STATUS_ICON_TTY_INDICATOR);
        }
        UpdateStatusIcons();
    }
    //else
    //ASSERT(0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ctm_open_rsp_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ctm_open_rsp_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pBOOL result = TRUE;
    U8 ctm_interface = CTM_DIRECT_MODE;

#ifndef __CTM_DEBUG
    mmi_ctm_open_rsp_struct *rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (mmi_ctm_open_rsp_struct*) info;
    result = rsp->result;
    ctm_interface = rsp->ctm_interface;
#endif /* __CTM_DEBUG */ 

    PRINT_INFORMATION("\n CTM OPEN RSP \n");

    if (ctm_p->state == MMI_CTM_STATE_OPENING)
    {
        if (result == TRUE)
        {
            /* open OK */
            mmi_ctm_set_state(MMI_CTM_STATE_OPENED);
            ctm_p->mode_activated = ctm_interface;
        }
        else
        {
            mmi_ctm_set_state(MMI_CTM_STATE_IDLE);
        }

        {
            S8 mode = 0xff;

            /* open fail */

            if (ctm_p->tty_status == TRUE)
            {
                /* with TTY, open as TTY */
                switch (ctm_p->mode_setting)
                {
                    case MMI_CTM_SETTING_HCO:
                        mode = CTM_HCO_MODE;
                        break;
                    case MMI_CTM_SETTING_VCO:
                        mode = CTM_VCO_MODE;
                        break;
                    case MMI_CTM_SETTING_BAUDOT:
                        mode = CTM_BAUDOT_MODE;
                        break;
                    default:
                		/* CTM ON, earphone in, direct mode => keep open as direct mode, take it as earphone */
                		mode = CTM_DIRECT_MODE;
                        break;
                }
            }
            else
            {
                switch (ctm_p->mode_setting)
                {
                    case MMI_CTM_SETTING_AUTO_DIRECT:
                    case MMI_CTM_SETTING_MANUAL_DIRECT:
                        /* no TTY, open as direct */
                        mode = CTM_DIRECT_MODE;
                        break;
                    default:
                        break;
                }
            }

            ASSERT(ctm_p->mode_setting <= MMI_CTM_SETTING_AUTO_DIRECT);

            if (mode != 0xff && mode != ctm_interface)
            {
                mmi_ctm_set_state(MMI_CTM_STATE_OPENING);
                mmi_ctm_send_open_req(mode);
                return;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ctm_close_rsp_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ctm_close_rsp_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("\n CTM CLOSE RSP\n");

    if (ctm_p->state == MMI_CTM_STATE_CLOSING)
    {
        mmi_ctm_set_state(MMI_CTM_STATE_IDLE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ctm_connect_rsp_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ctm_connect_rsp_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pBOOL result = TRUE;

#ifndef __CTM_DEBUG
    mmi_ctm_connect_rsp_struct *rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (mmi_ctm_connect_rsp_struct*) info;
    result = rsp->result;
#endif /* __CTM_DEBUG */ 

    PRINT_INFORMATION("\n CTM CONNECT RSP\n");

    if (ctm_p->state == MMI_CTM_STATE_CONNECTING)
    {
        if (result == TRUE)
        {
            /* connect OK */
            mmi_ctm_set_state(MMI_CTM_STATE_CONNECTED);

            mmi_ctm_reset_buffer();

            /* enter chat screen */
            if (GetExitScrnID() == SCR_CTM_CONNECTING ||
            	GetExitScrnID() == SCR_CM_ACTIVECALLSCREEN)
            {
                entry_ctm_talking();
                DeleteScreenIfPresent(SCR_CM_ACTIVECALLSCREEN);
            }
        }
        else
        {
            /* connect fail */
            mmi_ctm_set_state(MMI_CTM_STATE_OPENED);
            DisplayPopup((PU8) GetString(STR_GLOBAL_NOT_AVAILABLE), IMG_GLOBAL_ERROR, 0, 2000, ERROR_TONE);
        }
    }
#ifdef __CTM_DEBUG
    StartTimer(CM_NOTIFYDURATION_TIMER, 2000, (FuncPtr) mmi_ctm_recv_text_ind_hdlr);
#endif 
    DeleteScreenIfPresent(SCR_CTM_CONNECTING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ctm_connect_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ctm_connect_ind_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ctm_p->state == MMI_CTM_STATE_OPENED || ctm_p->state == MMI_CTM_STATE_CONNECTING)
    {
        mmi_ctm_set_state(MMI_CTM_STATE_CONNECTED);
        mmi_ctm_reset_buffer();
    }

    /* enter chat screen */
    if (GetExitScrnID() == SCR_CM_ACTIVECALLSCREEN)
    {
        entry_ctm_talking();
        DeleteScreenIfPresent(SCR_CM_ACTIVECALLSCREEN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ctm_send_text_rsp_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ctm_send_text_rsp_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pBOOL result = TRUE;
    U16 finished_len;

#ifndef __CTM_DEBUG
    mmi_ctm_send_text_rsp_struct *rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (mmi_ctm_send_text_rsp_struct*) info;
    result = rsp->result;
#endif /* __CTM_DEBUG */ 

    PRINT_INFORMATION("\n CTM SEND TEXT RSP\n");

    finished_len = ctm_p->sent_len;
    ctm_p->sent_len = 0;

    if (result == TRUE)
    {
        if (MAX_CTM_DATA_COUNT - ctm_p->local_len > finished_len)
        {
            ctm_p->local_len += finished_len;
            mmi_ucs2ncat((PS8) ctm_p->local_buffer, (PS8) ctm_p->pending_buffer, finished_len);
        }
        else
        {
            memset(ctm_p->local_buffer, 0, MAX_CTM_DATA_BUFFER_LEN);
            ctm_p->local_len = finished_len;
            mmi_ucs2ncpy((PS8) ctm_p->local_buffer, (PS8) ctm_p->pending_buffer, finished_len);
        }

        ctm_p->pending_len -= finished_len;

        if (ctm_p->pending_len > 0)
        {
            mmi_ucs2cpy((PS8) ctm_p->pending_buffer, (PS8) & ctm_p->pending_buffer[finished_len << 1]);
        }
        else
        {
            memset(ctm_p->pending_buffer, 0, MAX_CTM_EDITOR_BUFFER_LEN);
        }

        if (finished_len > 0 && GetExitScrnID() == SCR_CTM_TALKING)
        {
            UpdateCategory430LSK(STR_GLOBAL_EDIT, 0);
        }

        if (GetExitScrnID() == SCR_CTM_TALKING)
        {
            if (ctm_p->pending_len == 0)
            {
                ConfigureCategory430SendingBox(FALSE, 0);
            }
            else
            {
                ConfigureCategory430SendingBox(TRUE, 0);
            }
        }
    }

    if (ctm_p->pending_len > 0)
    {
        mmi_ctm_send_text_req((PS8) ctm_p->pending_buffer, ctm_p->pending_len);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ctm_recv_text_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ctm_recv_text_ind_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 space, len;
    PU16 text;

#ifdef __CTM_DEBUG
    U16 temp[] = L"abc12345def\n";

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    len = 12;
    text = temp;
#else /* __CTM_DEBUG */ 
    mmi_ctm_recv_text_ind_struct *ind;

    ind = (mmi_ctm_recv_text_ind_struct*) info;
    len = ind->num_of_char;
    text = ind->text;
#endif /* __CTM_DEBUG */ 

    PRINT_INFORMATION("\n CTM RECV TEXT IND\n");

    len = mmi_skip_unicode_char(text, len, 0x0008);
    space = MAX_CTM_DATA_COUNT - ctm_p->remote_len;
    if (space > len)
    {
        ctm_p->remote_len += len;
        mmi_ucs2cat((PS8) ctm_p->remote_buffer, (PS8) text);
    }
    else
    {
        ctm_p->remote_len = len;
        mmi_ucs2cpy((PS8) ctm_p->remote_buffer, (PS8) text);
    }
    if (GetExitScrnID() == SCR_CTM_TALKING)
    {
        UpdateCategory430LogBox(TRUE, FALSE);
    }

#ifdef __CTM_DEBUG
    StartTimer(CM_AUTOANSWER_NOTIFYDURATION_TIMER, 2000, (FuncPtr) mmi_ctm_recv_text_ind_hdlr);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ctm_tty_plug_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ctm_tty_plug_ind_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ctm_tty_plug_ind_struct *ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind = (mmi_ctm_tty_plug_ind_struct*) info;

    /* ctm_p->tty_status = ind->is_plug_in; */

    mmi_ctm_switch_tty_status(ind->is_plug_in);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ctm_switch_tty_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_present      [IN]        
 *  void(?)         [IN]        *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ctm_switch_tty_status(pBOOL is_present)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_present)
    {
        /* plug in */
        if (mmi_ctm_get_mode())
        {
            /* CTM on, take as TTY */
            ctm_p->tty_status = TRUE;
            if ((ctm_p->state != MMI_CTM_STATE_IDLE &&
                 ctm_p->mode_activated == CTM_DIRECT_MODE) ||
                (ctm_p->state == MMI_CTM_STATE_IDLE && GetTotalActiveCallCount() + GetTotalHoldCallCount() >= 1))
            {
                S8 mode = 0xff;

                /* plug in, open again */
                if (ctm_p->state != MMI_CTM_STATE_IDLE)
                {
                    mmi_ctm_set_state(MMI_CTM_STATE_CLOSING);
                    mmi_ctm_send_close_req();
                }
                switch (ctm_p->mode_setting)
                {
                    case MMI_CTM_SETTING_HCO:
                        mode = CTM_HCO_MODE;
                        break;
                    case MMI_CTM_SETTING_VCO:
                        mode = CTM_VCO_MODE;
                        break;
                    case MMI_CTM_SETTING_BAUDOT:
                        mode = CTM_BAUDOT_MODE;
                        break;
                    default:
                    	/* CTM ON, earphone in, direct mode => keep open as direct mode, take it as earphone */
                		mode = CTM_DIRECT_MODE;
                        break;
                }
                if (mode != 0xff)
                {
                    mmi_ctm_set_state(MMI_CTM_STATE_OPENING);
                    mmi_ctm_send_open_req(mode);
                }
            }
        }
        else
        {
            /* CTM off, take as headset */
            ctm_p->tty_status = FALSE;
        }
    }
    else
    {
        /* plug out */
        ctm_p->tty_status = FALSE;
        if (mmi_ctm_get_mode())
        {
            /* CTM on, TTY to direct */
            if (ctm_p->state != MMI_CTM_STATE_IDLE)
            {
                mmi_ctm_set_state(MMI_CTM_STATE_CLOSING);
                mmi_ctm_send_close_req();
            }

            if (((ctm_p->mode_setting == MMI_CTM_SETTING_AUTO_DIRECT ||
                  ctm_p->mode_setting == MMI_CTM_SETTING_MANUAL_DIRECT) &&
                 (ctm_p->mode_activated != CTM_DIRECT_MODE || 
                  ctm_p->state == MMI_CTM_STATE_CLOSING)) ||
                (ctm_p->state == MMI_CTM_STATE_IDLE && GetTotalActiveCallCount() + GetTotalHoldCallCount() >= 1))
            {
                /* plug out, open again */
                mmi_ctm_set_state(MMI_CTM_STATE_OPENING);
                mmi_ctm_send_open_req(CTM_DIRECT_MODE);
            }
        }
        else
        {
            /* CTM off, do nothing */
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ctm_send_open_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mode        [IN]        
 *  void(?)     [IN]        *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ctm_send_open_req(U8 mode)
{
#ifndef __CTM_DEBUG
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_ctm_open_req_struct *param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ClearInputEventHandler(MMI_DEVICE_ALL); */

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = MSG_ID_MMI_CTM_OPEN_REQ;

    param = (mmi_ctm_open_req_struct*) OslConstructDataPtr(sizeof(mmi_ctm_open_req_struct));

    param->ctm_interface = mode;

    Message.oslDataPtr = (oslParaType*) param;
    Message.oslPeerBuffPtr = NULL;

    SetProtocolEventHandler(mmi_ctm_open_rsp_hdlr, MSG_ID_MMI_CTM_OPEN_RSP);
    OslMsgSendExtQueue(&Message);
#else /* __CTM_DEBUG */ 
    StartTimer(CM_NOTIFYDURATION_TIMER, 2000, (FuncPtr) mmi_ctm_open_rsp_hdlr);
#endif /* __CTM_DEBUG */ 
    PRINT_INFORMATION("\n CTM OPEN REQ\n");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ctm_send_close_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  void(?)     [IN]        *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ctm_send_close_req(void)
{
#ifndef __CTM_DEBUG
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ClearInputEventHandler(MMI_DEVICE_ALL); */

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = MSG_ID_MMI_CTM_CLOSE_REQ;

    Message.oslDataPtr = NULL;
    Message.oslPeerBuffPtr = NULL;

    SetProtocolEventHandler(mmi_ctm_close_rsp_hdlr, MSG_ID_MMI_CTM_CLOSE_RSP);
    OslMsgSendExtQueue(&Message);
#else /* __CTM_DEBUG */ 
    StartTimer(CM_ALERT_NOTIFYDURATION_TIMER, 2000, (FuncPtr) mmi_ctm_close_rsp_hdlr);
#endif /* __CTM_DEBUG */ 
    PRINT_INFORMATION("\n CTM CLOSE REQ\n");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ctm_send_connect_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  void(?)     [IN]        *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ctm_send_connect_req(void)
{
#ifndef __CTM_DEBUG
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = MSG_ID_MMI_CTM_CONNECT_REQ;

    Message.oslDataPtr = NULL;
    Message.oslPeerBuffPtr = NULL;

    SetProtocolEventHandler(mmi_ctm_connect_rsp_hdlr, MSG_ID_MMI_CTM_CONNECT_RSP);
    OslMsgSendExtQueue(&Message);
#else /* __CTM_DEBUG */ 
    StartTimer(CM_NOTIFYDURATION_TIMER, 2000, (FuncPtr) mmi_ctm_connect_rsp_hdlr);
#endif /* __CTM_DEBUG */ 
    PRINT_INFORMATION("\n CTM CONNECT REQ\n");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ctm_send_text_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  text        [IN]        
 *  length      [IN]        
 *  void(?)     [IN]        *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ctm_send_text_req(PS8 text, U16 length)
{
#ifndef __CTM_DEBUG
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_ctm_send_text_req_struct *param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = MSG_ID_MMI_CTM_SEND_TEXT_REQ;

    param = (mmi_ctm_send_text_req_struct*) OslConstructDataPtr(sizeof(mmi_ctm_send_text_req_struct));

    if (length > CTM_SEND_TEXT_CHAR_MAX_NUM)
    {
        param->num_of_char = CTM_SEND_TEXT_CHAR_MAX_NUM;
        mmi_ucs2ncpy((PS8) param->text, text, CTM_SEND_TEXT_CHAR_MAX_NUM);
    }
    else
    {
        param->num_of_char = length;
        mmi_ucs2cpy((PS8) param->text, text);
    }
    ctm_p->sent_len = param->num_of_char;

    Message.oslDataPtr = (oslParaType*) param;
    Message.oslPeerBuffPtr = NULL;

    SetProtocolEventHandler(mmi_ctm_send_text_rsp_hdlr, MSG_ID_MMI_CTM_SEND_TEXT_RSP);
    OslMsgSendExtQueue(&Message);
#else /* __CTM_DEBUG */ 
    if (length > CTM_SEND_TEXT_CHAR_MAX_NUM)
    {
        ctm_p->sent_len = CTM_SEND_TEXT_CHAR_MAX_NUM;
    }
    else
    {
        ctm_p->sent_len = length;
    }

    StartTimer(CM_NOTIFYDURATION_TIMER, 2000, (FuncPtr) mmi_ctm_send_text_rsp_hdlr);
#endif /* __CTM_DEBUG */ 
    PRINT_INFORMATION("\n CTM SEND TEXT REQ\n");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ctm_send_set_default_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  on_off      [IN]        
 *  mode        [IN]        
 *  void(?)     [IN]        *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ctm_send_set_default_req(pBOOL on_off, U8 mode)
{
#ifndef __CTM_DEBUG
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_ctm_set_default_req_struct *param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = MSG_ID_MMI_CTM_SET_DEFAULT_REQ;

    param = (mmi_ctm_set_default_req_struct*) OslConstructDataPtr(sizeof(mmi_ctm_set_default_req_struct));

    param->is_turn_on = on_off;

    switch (mode)
    {
        case MMI_CTM_SETTING_BAUDOT:
            param->ctm_interface = CTM_BAUDOT_MODE;
            break;
        case MMI_CTM_SETTING_HCO:
            param->ctm_interface = CTM_HCO_MODE;
            break;
        case MMI_CTM_SETTING_VCO:
            param->ctm_interface = CTM_VCO_MODE;
            break;
        default:
            param->ctm_interface = CTM_DIRECT_MODE;
            break;
    }
    Message.oslDataPtr = (oslParaType*) param;
    Message.oslPeerBuffPtr = NULL;

    SetProtocolEventHandler(mmi_ctm_set_default_rsp_hdlr, MSG_ID_MMI_CTM_SET_DEFAULT_RSP);
    OslMsgSendExtQueue(&Message);
#else /* __CTM_DEBUG */ 
    StartTimer(CM_NOTIFYDURATION_TIMER, 2000, (FuncPtr) mmi_ctm_set_default_rsp_hdlr);
#endif /* __CTM_DEBUG */ 
    PRINT_INFORMATION("\n CTM SEND SET DEFAULT REQ\n");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ctm_send_get_default_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  void(?)     [IN]        *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ctm_send_get_default_req(void)
{
#ifndef __CTM_DEBUG
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = MSG_ID_MMI_CTM_GET_DEFAULT_REQ;

    Message.oslDataPtr = NULL;
    Message.oslPeerBuffPtr = NULL;

    SetProtocolEventHandler(mmi_ctm_get_default_rsp_hdlr, MSG_ID_MMI_CTM_GET_DEFAULT_RSP);
    OslMsgSendExtQueue(&Message);
#else /* __CTM_DEBUG */ 
    StartTimer(CM_NOTIFYDURATION_TIMER, 2000, (FuncPtr) mmi_ctm_get_default_rsp_hdlr);
#endif /* __CTM_DEBUG */ 
    PRINT_INFORMATION("\n CTM SEND GET DEFAULT REQ\n");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ctm_connect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  void(?)     [IN]        *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ctm_connect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ctm_p->state == MMI_CTM_STATE_OPENED)
    {
        mmi_ctm_set_state(MMI_CTM_STATE_CONNECTING);
        mmi_ctm_send_connect_req();
        entry_ctm_connect_animation();
    }
    else if (ctm_p->state == MMI_CTM_STATE_CONNECTED)
    {
        /* back to active screen to direct to chat screen */
        GoBackHistory();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ctm_edit_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  void(?)     [IN]        *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ctm_edit_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ctm_p->pending_len += mmi_ucs2strlen((PS8) ctm_p->editor_buffer);
    mmi_ucs2cat((PS8) ctm_p->pending_buffer, (PS8) ctm_p->editor_buffer);
    memset(ctm_p->editor_buffer, 0, MAX_CTM_EDITOR_BUFFER_LEN);

    if (ctm_p->sent_len == 0)
    {
        mmi_ctm_send_text_req((PS8) ctm_p->pending_buffer, ctm_p->pending_len);
    }

    if (IsScreenPresent(SCR_CM_ACTIVECALLSCREEN))
    {
        GoBackToHistory(SCR_CM_ACTIVECALLSCREEN);
    }
    else if (IsScreenPresent(SCR_CTM_TALKING))
    {
        GoBackToHistory(SCR_CTM_TALKING);
    }
    else
    {
        ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ctm_toggle_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  void(?)     [IN]        *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ctm_toggle_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U16 str_id;
    pBOOL old;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    old = mmi_ctm_is_tty_on();
    if (ctm_p->status == TRUE)
    {
        ctm_p->status = FALSE;
    }
    else
    {
        ctm_p->status = TRUE;
    }

    WriteValue(NVRAM_CTM_MODE, &ctm_p->status, DS_BYTE, &error);

    mmi_ctm_send_set_default_req(ctm_p->status, ctm_p->mode_setting);

    if (ctm_p->status == TRUE)
    {
        /* off -> on */
        str_id = STR_CTM_ON_SELECTED;
        ShowStatusIcon(STATUS_ICON_TTY_INDICATOR);
        /* with earphone, take as TTY */
        ctm_p->tty_status = isEarphonePlugged;
        if (isEarphonePlugged == TRUE && mmi_ctm_is_tty_on())
        {
            str_id = STR_CTM_HEADSET_TO_TTY;
            /* deactivate earphone mode, Tim */
            mmi_profiles_earphone_plug_out_callback();
        #if (defined (__MMI_STATUS_ICON_EN_EARPHONE__) || defined(__MMI_BT_SUPPORT__))
            IdleResetStatusIcon(STATUS_ICON_EARPHONE_INDICATOR);
        #endif 
        }
    }
    else
    {
        /* on -> off */
        str_id = STR_CTM_OFF_SELECTED;
        HideStatusIcon(STATUS_ICON_TTY_INDICATOR);
        ctm_p->tty_status = FALSE;
        if (isEarphonePlugged == TRUE && old == TRUE)
        {
            str_id = STR_CTM_TTY_TO_HEADSET;
            /* activate earphone mode, Tim */
            mmi_profiles_earphone_plug_in_callback();
        #if (defined (__MMI_STATUS_ICON_EN_EARPHONE__) || defined(__MMI_BT_SUPPORT__))
            IdleSetStatusIcon(STATUS_ICON_EARPHONE_INDICATOR);
        #endif 
        }
    }

    DisplayPopup((PU8) GetString(str_id), IMG_GLOBAL_ACTIVATED, 1, 2000, SUCCESS_TONE);

    /*
     * hint_ctm_mode(GetCurrHiliteID());
     * RedrawCategoryFunction();
     * highlight_ctm_mode();
     */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ctm_setting_select
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  void(?)     [IN]        *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ctm_setting_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U16 str_id = STR_GLOBAL_DONE;
    pBOOL old;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    old = mmi_ctm_is_tty_on();
    ctm_p->mode_setting = (U8) ctm_p->index;

    WriteValue(NVRAM_CTM_SETTING, &ctm_p->mode_setting, DS_BYTE, &error);

    mmi_ctm_send_set_default_req(ctm_p->status, ctm_p->mode_setting);
	 if (old == FALSE && mmi_ctm_is_tty_on() == TRUE)
    {
        /* off -> on */
        /* with earphone, take as TTY */
        if (isEarphonePlugged == TRUE)
        {
            str_id = STR_CTM_HEADSET_TO_TTY;
            /* deactivate earphone mode, Tim */
            mmi_profiles_earphone_plug_out_callback();
        #if (defined (__MMI_STATUS_ICON_EN_EARPHONE__) || defined(__MMI_BT_SUPPORT__))
            IdleResetStatusIcon(STATUS_ICON_EARPHONE_INDICATOR);
        #endif 
        }
    }
	 else if (old == TRUE && mmi_ctm_is_tty_on() == FALSE)
    {
        /* on -> off */
        if (isEarphonePlugged == TRUE)
        {
            str_id = STR_CTM_TTY_TO_HEADSET;
            /* activate earphone mode, Tim */
            mmi_profiles_earphone_plug_in_callback();
        #if (defined (__MMI_STATUS_ICON_EN_EARPHONE__) || defined(__MMI_BT_SUPPORT__))
            IdleSetStatusIcon(STATUS_ICON_EARPHONE_INDICATOR);
        #endif 
        }
    }

    DisplayPopup((PU8) GetString(str_id), IMG_GLOBAL_ACTIVATED, 1, 2000, SUCCESS_TONE);

    DeleteScreenIfPresent(SCR_CTM_SETTING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ctm_get_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  void(?)     [IN]        *
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_ctm_get_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ctm_p->status;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ctm_get_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  void(?)     [IN]        *
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_ctm_get_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ctm_p->mode_setting;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ctm_is_tty_on
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  void(?)     [IN]        *
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_ctm_is_tty_on(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* TTY on depends on status and setting */
    /* TTY status depends on status and earphone plug in or not */
    if (ctm_p->status == TRUE && 
    	  (ctm_p->mode_setting == MMI_CTM_SETTING_BAUDOT ||
    	   ctm_p->mode_setting == MMI_CTM_SETTING_HCO ||
    	   ctm_p->mode_setting == MMI_CTM_SETTING_VCO))
        return TRUE;
    else
    	  return FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ctm_get_tty_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  void(?)     [IN]        *
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_ctm_get_tty_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ctm_p->tty_status;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_skip_unicode_char
 * DESCRIPTION
 *  
 * PARAMETERS
 *  str         [IN]        
 *  len         [IN]        
 *  ch          [IN]        
 *  void(?)     [IN]        *
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_skip_unicode_char(PU16 str, U16 len, U16 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 length, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    length = len;
    for (i = 0; i < length; i++)
    {
        if (str[i] == ch)
        {
            mmi_ucs2cpy((PS8) & str[i], (PS8) & str[i + 1]);
            str[length] = 0;
            length--;
        }
    }
    return length;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ctm_set_tty_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_present      [IN]        
 *  void(?)         [IN]        *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ctm_set_tty_status(pBOOL is_present)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ctm_get_mode())
    {
        ctm_p->tty_status = is_present;
    }
    else
    {
        ctm_p->tty_status = FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  entry_ctm_menu
 * DESCRIPTION
 *  CTM main menu: Mode, Setting
 * PARAMETERS
 *  void
 *  void(?)     [IN]        *
 * RETURNS
 *  void
 *****************************************************************************/
void entry_ctm_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[4];
    U16 nNumofItem;
    S16 error;
    U8 *guiBuffer;
    static U8 *PopUpList[4];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_CTM_MENU, NULL, entry_ctm_menu, NULL);

    ReadValue(NVRAM_CTM_MODE, &ctm_p->status, DS_BYTE, &error);
    if (ctm_p->status == 0xff)
    {
        ctm_p->status = FALSE;
    }

    ReadValue(NVRAM_CTM_SETTING, &ctm_p->mode_setting, DS_BYTE, &error);
    if (ctm_p->mode_setting == 0xff)
    {
        ctm_p->mode_setting = MMI_CTM_SETTING_MANUAL_DIRECT;
    }

    guiBuffer = GetCurrGuiBuffer(SCR_CTM_MENU);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    nNumofItem = GetNumOfChild(MITEM_CTM_MENU);
    GetSequenceStringIds(MITEM_CTM_MENU, nStrItemList);
    SetParentHandler(MITEM_CTM_MENU);
    ConstructHintsList(MITEM_CTM_MENU, PopUpList);

    ShowCategory55Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MAIN_MENU_SETTINGS_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U8 **) PopUpList,
        0,
        guiBuffer);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;

}


/*****************************************************************************
 * FUNCTION
 *  entry_ctm_setting_selection
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  void(?)     [IN]        *
 * RETURNS
 *  void
 *****************************************************************************/
void entry_ctm_setting_selection(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[20];
    U16 nNumofItem;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_CTM_SETTING, NULL, entry_ctm_setting_selection, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_CTM_SETTING);

    RegisterHighlightHandler(highlight_ctm_setting_items);
    nNumofItem = GetNumOfChild(MITEM_CTM_SETTING);
    GetSequenceStringIds(MITEM_CTM_SETTING, nStrItemList);
    SetParentHandler(MITEM_CTM_SETTING);

    ShowCategory11Screen(
        STR_MITEM_CTM_SETTING,
        GetRootTitleIcon(MAIN_MENU_SETTINGS_MENUID),
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        nNumofItem,
        nStrItemList,
        ctm_p->mode_setting,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_ctm_setting_select, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  entry_ctm_connect_animation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  void(?)     [IN]        *
 * RETURNS
 *  void
 *****************************************************************************/
void entry_ctm_connect_animation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_CTM_CONNECTING, NULL, entry_ctm_connect_animation, NULL);

    DeleteScreenIfPresent(SCR1003_CM_ACTIVECALLOPTIONS);

    ShowCategory66Screen(0, 0, 0, 0, 0, 0, (PU8) GetString(STR_CTM_CONNECTING), IMG_GLOBAL_PROGRESS, NULL);

    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  entry_ctm_talking
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  void(?)     [IN]        *
 * RETURNS
 *  void
 *****************************************************************************/
void entry_ctm_talking(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 lsk = 0;
    pBOOL show_highlight = FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ctm_p->state < MMI_CTM_STATE_CONNECTED)
    {
        /* not connected, use default active screen */
        if (IsScreenPresent(SCR_CM_ACTIVECALLSCREEN))
        {
            GoBackToHistory(SCR_CM_ACTIVECALLSCREEN);
        }
        else
        {
            EntryScr1002ActiveCall();
        }
        return;
    }

    EntryNewScreen(SCR_CTM_TALKING, NULL, entry_ctm_talking, NULL);

    PRINT_INFORMATION("\nCTM TALKING SCREEN\n");

    if (MAX_CTM_EDITOR_COUNT - ctm_p->pending_len > 0)
    {
        lsk = STR_GLOBAL_EDIT;
    }

    if (ctm_p->pending_len != 0)
    {
        show_highlight = TRUE;
    }

    ShowCategory430Screen(
        STR_CTM_CHAT,
        0,
        lsk,
        0,
        STR_MITEM2041_CM_DROP,
        0,
        ctm_p->remote_buffer,
        ctm_p->remote_len,
        ctm_p->local_buffer,
        ctm_p->local_len,
        show_highlight,
        MAX_CTM_EDITOR_COUNT,
        ctm_p->pending_buffer,
        0,
        (PU8) GetString(STR_CTM_REMOTE),
        (PU8) GetString(STR_CTM_LOCAL),
        NULL);

    SetLeftSoftkeyFunction(entry_ctm_editor, KEY_EVENT_UP);

    SetRightSoftkeyFunction(HangupAll, KEY_EVENT_UP);
    SetKeyHandler(HangupAll, KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  entry_ctm_editor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  void(?)     [IN]        *
 * RETURNS
 *  void
 *****************************************************************************/
void entry_ctm_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S32 length;
	S16 required_input_modes[] = {
        INPUT_MODE_MULTITAP_UPPERCASE_ABC,
        INPUT_MODE_123,
        INPUT_MODE_SMART_UPPERCASE_ABC,
        -1    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_CTM_EDITOR, NULL, entry_ctm_editor, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_CTM_EDITOR);

    length = MAX_CTM_EDITOR_COUNT - ctm_p->pending_len;
        
	ShowCategory5Screen_ext(
        STR_GLOBAL_EDIT,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        INPUT_TYPE_ALPHANUMERIC_UPPERCASE,
        (PU8) ctm_p->editor_buffer,
        length + 1,
        guiBuffer,
        0,
        required_input_modes,
        NULL);

    /*ClearKeyHandler(KEY_POUND, KEY_EVENT_DOWN);*/
    SetLeftSoftkeyFunction(mmi_ctm_edit_done/*entry_ctm_editor_option*/, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  ctm_return_to_editor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  void(?)     [IN]        *
 * RETURNS
 *  void
 *****************************************************************************/
void ctm_return_to_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBacknHistory(1);
}


/*****************************************************************************
 * FUNCTION
 *  entry_ctm_editor_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  void(?)     [IN]        *
 * RETURNS
 *  void
 *****************************************************************************/
void entry_ctm_editor_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[10];
    U8 *guiBuffer;
    U16 nNumofItem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_CTM_EDITOR_OPTION, NULL, entry_ctm_editor_option, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_CTM_EDITOR_OPTION);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    nNumofItem = GetNumOfChild(MITEM_CTM_EDITOR_OPTION);
    GetSequenceStringIds(MITEM_CTM_EDITOR_OPTION, nStrItemList);
    SetParentHandler(MITEM_CTM_EDITOR_OPTION);

    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
        0,
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

    RegisterInputMethodScreenCloseFunction(ctm_return_to_editor);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    return;

}

#endif /* __CTM_SUPPORT__ */ 

#endif /* __MMI_UCM__ */