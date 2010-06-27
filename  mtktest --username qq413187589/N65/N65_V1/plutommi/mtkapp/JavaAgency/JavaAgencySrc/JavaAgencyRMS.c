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
 * Filename:
 * ---------
 * JavaSrc.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends to handle all scenario of Java Content Manager and 
 *   interaction betweens MMI and Java task.
 *
 * Author:
 * -------
 * -------
 * -------
 *==============================================================================
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

#include "MMI_include.h"
#ifdef __J2ME__

#include "CommonScreens.h"
#include "ProtocolEvents.h"

#include "MainMenuDef.h"        /* need MAIN_MENU_TITLE_FUNANDGAMES_ICON */

#include "JavaAgencyDef.h"
#include "JavaAgencyProt.h"
// #include "jal_internal.h"
#include "jam_msg_handler.h"

/*****************************************************************************
 * FUNCTION
 *  mmi_java_recv_reset_rms_ind
 * DESCRIPTION
 *  This routines handles MMI_JAVA_INSTALL_RESET_RMS_IND from MOD_J2ME to
 *  prompt user whether or not reset RMS
 * PARAMETERS
 *  MsgStruct       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_java_install_reset_rms_ind_struct reset_rms_ind_msg;
void mmi_java_recv_reset_rms_ind(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_mem_cpy(
        &reset_rms_ind_msg,
        (mmi_java_install_reset_rms_ind_struct*) MsgStruct,
        sizeof(mmi_java_install_reset_rms_ind_struct));

    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_RESET_RMS_IND);

    mmi_java_entry_reset_rms_res();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_reset_rms_res
 * DESCRIPTION
 *  Reset RMS Confirm screen Entry Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_entry_reset_rms_res(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *str;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_JAVA_RESET_RMS_CONFIRM, NULL, mmi_java_entry_reset_rms_res, NULL);

    /* playRequestedTone(WARNING_TONE); */

    guiBuffer = GetCurrGuiBuffer(SCR_JAVA_RESET_RMS_CONFIRM);

    //mmi_asc_to_ucs2 ((PS8)gJavaPrintableStr,
    //"Do you want the new version application to be able to use the information stored by the old version application?");
    str = (U8*) get_string(STR_JAVA_RESET_RMS_ASK);

    ShowCategory74Screen(
        STR_JAVA_KEEP_RMS,
        mmi_java_get_title_icon(),
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (PU8) str,
        mmi_ucs2strlen((PS8) str),
        NULL);

    SetLeftSoftkeyFunction(mmi_java_send_reset_rms_res_yes, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_java_send_reset_rms_res_no, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_send_reset_rms_res_yes
 * DESCRIPTION
 *  Handle Function: revoked when select "YES" in "RESET RMS" screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_send_reset_rms_res_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);
    GoBackHistory();    /* KEY PRESSED */
    mmi_java_send_reset_rms_res(KAL_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_send_reset_rms_res_no
 * DESCRIPTION
 *  Handle Function: revoked when select "NO" in "RESET RMS" screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_send_reset_rms_res_no(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);
    GoBackHistory();    /* KEY PRESSED */
    mmi_java_send_reset_rms_res(KAL_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_send_reset_rms_res
 * DESCRIPTION
 *  This routines send MMI_JAVA_SEND_RESET_RMS_RES to MOD_J2ME for user decision
 * PARAMETERS
 *  confirm     [IN]        KAL_TRUE if really want to install this MIDS
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_send_reset_rms_res(S8 confirm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_java_install_reset_rms_res_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_SEND_RESET_RMS_RES);
    ClearInputEventHandler(MMI_DEVICE_ALL);

    msg = (mmi_java_install_reset_rms_res_struct*) OslConstructDataPtr(sizeof(mmi_java_install_reset_rms_res_struct));

    msg->session_id = reset_rms_ind_msg.session_id;
    msg->confirm = confirm;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_J2ME;
    Message.oslMsgId = MSG_ID_MMI_JAVA_INSTALL_RESET_RMS_RES;
    Message.oslDataPtr = (local_para_struct*) msg;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}

#endif /* __J2ME__ */ 

