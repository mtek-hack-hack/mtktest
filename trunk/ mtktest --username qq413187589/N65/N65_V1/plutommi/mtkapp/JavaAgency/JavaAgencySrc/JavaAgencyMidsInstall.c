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
#define JAVA_LAUNCH_AFTER_INSTALL

#include "CommonScreens.h"
#include "ProtocolEvents.h"

#include "PhoneBookDef.h"       /* need IMG_PROCESSING_PHONEBOOK */
#include "MainMenuDef.h"        /* need MAIN_MENU_TITLE_FUNANDGAMES_ICON */
#include "ProfileGprots.h"      /* need MYQUEUE */
#include "SettingDefs.h"        // need STR_SCREENSAVER_EMPTY/*Cylen 0926, customize display char*/
#include "wap.h"
#include "ScreenSaverDefs.h"    /* need STR_SCREENSAVER_EMPTY */

/* ... Add media headers */
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "CallmanagementIdDef.h"

#include "mmiapi.h"

#include "jal.h"
#include "jvm_adaptor.h"
#include "JavaAgencyDef.h"
#include "JavaAgencyProt.h"
#include "jam_msg_handler.h"

#include "FileManagerGProt.h"
#include "app_mine.h"
#include "gpioInc.h"            /* GPIO_BACKLIGHT_SHORT_TIME */
#include "wgui_categories_inputs.h "/* INPUT_TYPE_USE_ONLY_ENGLISH_MODES */
#include "DLAgentResDef.h"
#include "j2me_custom.h"
#include "jam_internal.h"


extern java_context_struct g_java;
extern kal_bool needToSendGetListReq;

/*****************************************************************************
 * FUNCTION
 *  mmi_java_is_installing
 * DESCRIPTION
 *  To check if java is installing or updating MIDlet.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_java_is_installing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return ( g_java.mids_install_state > INSTALL_VALID_STATE ||
             g_java.mids_update_state > UPDATE_VALID_STATE);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_recv_drm_local_install_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  MsgStruct       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_recv_drm_local_install_req(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_drm_local_install_req_struct *s = (wap_drm_local_install_req_struct*) MsgStruct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_java_local_install_content_routing((kal_uint8*) s->midlet_path);
    free_ctrl_buffer(s->midlet_path);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_mids_install_clean_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_mids_install_clean_screen()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 screenId = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteScreenIfPresent(SCR_JAVA_START_INSTALLING);
    DeleteScreenIfPresent(SCR_JAVA_INSTALL_CONFIRM);
    DeleteScreenIfPresent(SCR_JAVA_START_UPDATING);
    DeleteScreenIfPresent(SCR_JAVA_VM_INSTALLING);
    DeleteScreenIfPresent(SCR_JAVA_UPDATE_CONFIRM);
    DeleteScreenIfPresent(SCR_JAVA_SHOW_PERCENTAGE);
    DeleteScreenIfPresent(SCR_JAVA_APP_MIDS_OPTION);

    screenId = GetActiveScreenId();

    if (screenId == SCR_JAVA_START_INSTALLING ||
        screenId == SCR_JAVA_INSTALL_CONFIRM ||
        screenId == SCR_JAVA_START_UPDATING ||
        screenId == SCR_JAVA_VM_INSTALLING ||
        screenId == SCR_JAVA_SHOW_PERCENTAGE || 
        screenId == SCR_JAVA_UPDATE_CONFIRM  ||
        screenId == SCR_JAVA_APP_MIDS_OPTION  )
    {
        GoBackHistory();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_receive_da_file
 * DESCRIPTION
 *  handler function:  Download agent send a jad/jar file to MMI
 * PARAMETERS
 *  mime_type           [IN]        
 *  mime_subtype        [IN]        
 *  action              [IN]        
 *  file_path           [IN]        
 *  url                 [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_receive_da_file (S32 session_id, S32 mime_type, S32 mime_subtype,S32 action, PU16 file_path, PS8 url, PS8 mime_type_string)
{
	kal_wchar *url_buf;

    if( mmi_java_is_in_voice_call() )
    {
        DisplayPopup(
            (PU8) GetString(STR_JAVA_ERROR_CODE_IN_CALL),
            IMG_GLOBAL_ERROR,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
        return;
    }

	url_buf = get_ctrl_buffer( (strlen(url)+1) * ENCODING_LENGTH );
	kal_wsprintf(url_buf,"%s",url);

	if(mime_subtype == MIME_SUBTYPE_JAD)
	{
		mmi_java_mids_install(0,(kal_wchar*)file_path,NULL, url_buf, KAL_TRUE);
	}
	else
	{
		mmi_java_mids_install(0,NULL, (kal_wchar*)file_path, url_buf, KAL_TRUE);
	}

	free_ctrl_buffer(url_buf);

	return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_mids_install_delete_callback
 * DESCRIPTION
 *  Send abort message to VM to terminate installing
 * PARAMETERS
 *  in_param    [IN]    no use here
 * RETURNS
 *  return if we want to stop delete the screen
 *****************************************************************************/
BOOL mmi_java_mids_install_delete_callback(void *in_param)
{
    if( g_java.is_local_install &&
        (( g_java.mids_install_state > INSTALL_VALID_STATE &&
           g_java.mids_install_state != INSTALL_ABORT_STATE)    ||
         ( g_java.mids_update_state > UPDATE_VALID_STATE &&
           g_java.mids_update_state != UPDATE_ABORT_STATE)))
    {
        mmi_java_send_java_abort_req();
    }
    return MMI_FALSE;
}

static kal_wchar *mmi_jad_file_name;
static kal_wchar *mmi_jar_file_name;
static kal_wchar *mmi_download_url;
static kal_bool  mmi_delete_after_install_fail = KAL_FALSE;
/*****************************************************************************
 * FUNCTION
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_java_clear_install_info()
{
    if(mmi_jad_file_name)
    {
        if(mmi_delete_after_install_fail)
        {
            FS_Delete(mmi_jad_file_name);
        }
        free_ctrl_buffer(mmi_jad_file_name);
    }
    if(mmi_jar_file_name)
    {
        if(mmi_delete_after_install_fail)
        {
            FS_Delete(mmi_jar_file_name);
        }
        free_ctrl_buffer(mmi_jar_file_name);
    }
    if(mmi_download_url)
    {
        free_ctrl_buffer(mmi_download_url);
    }

    mmi_jad_file_name = mmi_jar_file_name = mmi_download_url = NULL;
    mmi_delete_after_install_fail = KAL_FALSE;
}

/*****************************************************************************
 * FUNCTION
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_java_set_install_info(
    kal_wchar *jad_file_name,
    kal_wchar *jar_file_name,
    kal_wchar *download_url,
    kal_bool  delete)
{
    mmi_java_clear_install_info();

    if(jad_file_name)
    {
        mmi_jad_file_name = (kal_wchar *)get_ctrl_buffer((mmi_ucs2strlen((S8*)jad_file_name)+1) * ENCODING_LENGTH);
        mmi_ucs2cpy((S8*)mmi_jad_file_name, (S8*)jad_file_name);
    }
    if(jar_file_name)
    {
        mmi_jar_file_name = (kal_wchar *)get_ctrl_buffer((mmi_ucs2strlen((S8*)jar_file_name)+1) * ENCODING_LENGTH);
        mmi_ucs2cpy((S8*)mmi_jar_file_name, (S8*)jar_file_name);
    }

    if(download_url)
    {
        mmi_download_url = (kal_wchar *)get_ctrl_buffer((mmi_ucs2strlen((S8*)download_url)+1) * ENCODING_LENGTH);
        mmi_ucs2cpy((S8*)mmi_download_url, (S8*)download_url);
    }
    mmi_delete_after_install_fail = delete;
}
/*****************************************************************************
 * FUNCTION
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_java_mids_install_internal(void)
{
    if (mmi_jad_file_name)
    {
        g_java.is_jad_file_install = MMI_TRUE;
        mmi_java_send_mids_install_req(mmi_jad_file_name, mmi_jar_file_name, mmi_download_url);
    }
    else
    {
        g_java.is_jad_file_install = MMI_FALSE;
        mmi_java_send_mids_install_req(mmi_jad_file_name, mmi_jar_file_name, mmi_download_url);
    }

    mmi_java_entry_mids_install_start();
    if (g_java.is_jad_file_install)
    {
        g_java.mids_install_state = INSTALL_JAD_DOWNLOAD_STATE;
    }
    else
    {
        g_java.mids_install_state = INSTALL_JAR_DOWNLOAD_STATE;
    }
    g_java.mids_update_state = UPDATE_INVALID_STATE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_mids_install_ask_terminate_cb
 * DESCRIPTION
 *  Callback function to handle
 *  Ask user if they want to terminate VM first before install MIDlet
 * PARAMETERS
 *  teminate    [IN]    user select yes/No
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_mids_install_ask_terminate_cb(BOOL terminate)
{
    if(terminate)
    {
        g_java.screen_after_terminate = TER_ENTRY_INSTALL_JAVA;
        jvm_pause_state_exit();
        mmi_java_entry_terminating(MMI_FALSE);
    }
    else
    {


        g_java.mids_install_state = INSTALL_VALID_STATE;
        g_java.mids_update_state = UPDATE_VALID_STATE;
        g_java.is_local_install = MMI_FALSE;
        g_java.is_at_install = MMI_FALSE;
        mmi_java_clear_install_info();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_mids_install
 * DESCRIPTION
 *  This routines handles MMI_JAVA_INSTALL_MIDS_IND from MOD_J2ME to
 *  indicate user whether installation process is successful
 * PARAMETERS
 *  session_id          [IN]        
 *  jad_file_name       [?]         
 *  jar_file_name       [?]         
 *  download_url        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_mids_install(
        kal_int32 session_id,
        kal_wchar *jad_file_name,
        kal_wchar *jar_file_name,
        kal_wchar *download_url,
        kal_bool delete)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_java.mids_install_state != INSTALL_VALID_STATE)
    {
        mmi_java_display_is_busy();
        if(delete)
        {
            if(jad_file_name)
            {
                FS_Delete(jad_file_name);
            }
            if(jar_file_name)
            {
                FS_Delete(jar_file_name);
            }
        }
        return;
    }


    mmi_java_set_install_info(jad_file_name, jar_file_name, download_url, delete);

#if defined(J2ME_SUPPORT_PAUSE) && !defined(__SUPPORT_NATIVE_INSTALLER__)
    if (jvm_is_pause_mode())
    {
        if( jvm_get_initiate_game_type() == GAMETYPE_JAVA_GAME)
        {
            mmi_java_entry_cb_terminate_dialog(mmi_java_mids_install_ask_terminate_cb, (U16*)GetString(STR_JAVA_TERMINATE_JAVA_GAME));
        }
        else if( jvm_get_initiate_game_type() == GAMETYPE_INFUSIO_EUREKA )
        {
            mmi_java_entry_cb_terminate_dialog(mmi_java_mids_install_ask_terminate_cb, (U16*)GetString(STR_JAVA_TERMINATE_EUREKA));
        }
        else
        {
            mmi_java_display_is_busy();
        }
        return;
    }
    if (mmi_java_check_and_display_is_busy())
    {
        mmi_java_clear_install_info();
        return;
    }
#endif /* J2ME_SUPPORT_PAUSE */
    mmi_java_mids_install_internal();

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_send_mids_install_req
 * DESCRIPTION
 *  Send message "MMI_JAVA_SEND_INSTALL_MIDS_REQ" to java
 * PARAMETERS
 *  jad_file_path           [?]         
 *  jar_file_path           [?]         
 *  download_url            [IN]        The url where we can update MIDlet
 *  jad_file(?)             [IN]        If this MIDLet is a jad file
 *  file_path_name(?)       [IN]        The file path where we save in file system
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_send_mids_install_req(kal_wchar *jad_file_path, kal_wchar *jar_file_path, kal_wchar *download_url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_java_install_mids_req_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_SEND_INSTALL_MIDS_REQ);

    /* g_java.is_jad_file_install = jad_file_path == NULL ? KAL_FALSE : KAL_TRUE ; */

    msg = (mmi_java_install_mids_req_struct*) OslConstructDataPtr(sizeof(mmi_java_install_mids_req_struct));
    msg->session_id = 0;
	msg->game_type = GAMETYPE_JAVA_GAME;

    msg->jad_file_path = msg->jar_file_path = msg->download_url = NULL;

    if(jad_file_path)
    {
        msg->jad_file_path = (kal_wchar *) get_ctrl_buffer( (mmi_ucs2strlen((S8*)jad_file_path) +1 )* ENCODING_LENGTH );
        mmi_ucs2cpy((S8*)msg->jad_file_path, (S8*)jad_file_path);
    }

    if(jar_file_path)
    {
        msg->jar_file_path = (kal_wchar *) get_ctrl_buffer( (mmi_ucs2strlen((S8*)jar_file_path) +1 )* ENCODING_LENGTH );
        mmi_ucs2cpy((S8*)msg->jar_file_path, (S8*)jar_file_path);
    }

    if(download_url)
    {
        msg->download_url =  (kal_wchar *) get_ctrl_buffer( (mmi_ucs2strlen((S8*)download_url) +1 )* ENCODING_LENGTH );
        mmi_ucs2cpy((S8*)msg->download_url, (S8*)download_url);
    }


    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_J2ME;
    Message.oslMsgId = MSG_ID_MMI_JAVA_INSTALL_MIDS_REQ;
    Message.oslDataPtr = (local_para_struct*) msg;
    Message.oslPeerBuffPtr = NULL;
    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_mids_install_confirm_ind, MSG_ID_MMI_JAVA_INSTALL_CONFIRM_IND);
    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_mids_install_cnf, MSG_ID_MMI_JAVA_INSTALL_MIDS_CNF);

    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_mids_install_start
 * DESCRIPTION
 *  show a screen to indicate user JAD file or JAR file is downloading
 *  and start to install
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/* void mmi_java_enter_mids_start_installing(void) */
void mmi_java_entry_mids_install_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_JAVA_START_INSTALLING, NULL, mmi_java_entry_mids_install_start, NULL);

    ShowCategory66Screen(
        STR_JAVA_START_INSTALLING,
        mmi_java_get_title_icon(),
        0,
        0,
        STR_JAVA_ABORT,
        IMG_JAVA_ABORT,
        (PU8) GetString(STR_JAVA_START_INSTALLING),
        IMG_PROCESSING_PHONEBOOK,
        NULL);

    SetKeyHandler(mmi_java_mids_endkey_abort_hdlr, KEY_END, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(mmi_java_mids_abort_hdlr, KEY_EVENT_UP);
    SetDelScrnIDCallbackHandler(SCR_JAVA_START_INSTALLING, mmi_java_mids_install_delete_callback);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_recv_mids_install_confirm_ind
 * DESCRIPTION
 *  This routines handles MMI_JAVA_INSTALL_CONFIRM_IND from MOD_J2ME to
 *  prompt user whether or not install the MIDS
 * PARAMETERS
 *  MsgStruct       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_java_install_confirm_ind_struct mmi_java_mids_install_confirm_ind_msg;
void mmi_java_recv_mids_install_confirm_ind(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_INSTALL_CONFIRM_IND);

    if (g_java.mids_install_state > INSTALL_VALID_STATE ||
        g_java.mids_update_state > UPDATE_VALID_STATE )
    {

        kal_mem_cpy(
            &mmi_java_mids_install_confirm_ind_msg,
            (mmi_java_install_confirm_ind_struct*) MsgStruct,
            sizeof(mmi_java_install_confirm_ind_struct));

        /* mmi_java_mids_install_clean_screen(); */

        mmi_java_entry_mids_install_confirm();

        //      DeleteScreenIfPresent(SCR_JAVA_VM_INSTALLING);
        //     DeleteScreenIfPresent(SCR_JAVA_START_INSTALLING);
        //    DeleteScreenIfPresent(SCR_JAVA_START_UPDATING);

        /*    if(   g_java.mids_install_state == INSTALL_JAR_DOWNLOAD_STATE ||
           g_java.mids_install_state == INSTALL_JAD_DOWNLOAD_STATE)
           g_java.mids_install_state = INSTALL_CONFIRM_STATE;
           else
           g_java.mids_update_state = UPDATE_CONFIRM_INS_STATE; */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_mids_install_confirm
 * DESCRIPTION
 *  Install Confirm screen Entry Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/* void mmi_java_enter_mids_install_confirm_ind(void) */
void mmi_java_entry_mids_install_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *str;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_JAVA_INSTALL_CONFIRM, NULL, mmi_java_entry_mids_install_confirm, NULL);

    /* playRequestedTone(WARNING_TONE); */

    guiBuffer = GetCurrGuiBuffer(SCR_JAVA_INSTALL_CONFIRM);

    str = (U8*) mmi_java_mids_install_confirm_ind_msg.confirm_msg;

    ShowCategory74Screen(
        STR_JAVA_DOWNLOAD_ASK,
        mmi_java_get_title_icon(),
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (PU8) str,
        mmi_ucs2strlen((PS8) str),
        NULL);

    SetKeyHandler(mmi_java_mids_install_confirm_cancel_hdlr, KEY_END, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_java_mids_install_confirm_yes_hdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_java_mids_install_confirm_no_hdlr, KEY_EVENT_UP);

    TurnOnBacklight(GPIO_BACKLIGHT_SHORT_TIME);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_mids_install_confirm_yes_hdlr
 * DESCRIPTION
 *  Handle Function, revoked when select "YES" in "INSTALL CONFIRM" screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/* void mmi_java_send_mids_install_confirm_res_yes(void) */
void mmi_java_mids_install_confirm_yes_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //ClearInputEventHandler(MMI_DEVICE_ALL);
    GoBackHistory();    /* leave confirm page */
    mmi_java_send_mids_install_confirm_res(KAL_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_mids_install_confirm_no_hdlr
 * DESCRIPTION
 *  Handle Function, revoked when select "NO" in "INSTALL CONFIRM" screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_mids_install_confirm_no_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //ClearInputEventHandler(MMI_DEVICE_ALL);
    /* quit the screen of SCR_JAVA_INSTALL_CONFIRM (Install?) */

    mmi_java_send_mids_install_confirm_res(KAL_FALSE);

	if(g_java.mids_install_state != INSTALL_INVALID_STATE)
	{
    	g_java.mids_install_state = INSTALL_ABORT_STATE;
    }
    else if(g_java.mids_update_state  != UPDATE_INVALID_STATE)
    {
    	g_java.mids_update_state = UPDATE_ABORT_STATE;
    }
    else
    {
        ASSERT(0);
    }
    mmi_java_mids_install_clean_screen();

}
/*****************************************************************************
 * FUNCTION
 *  mmi_java_mids_install_confirm_cancel_hdlr
 * DESCRIPTION
 *  Handle Function, revoked when press "END key" in "INSTALL CONFIRM" screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_mids_install_confirm_cancel_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //ClearInputEventHandler(MMI_DEVICE_ALL);
    /* quit the screen of SCR_JAVA_INSTALL_CONFIRM (Install?) */
    mmi_java_send_mids_install_confirm_res(KAL_FALSE);
	if(g_java.mids_install_state != INSTALL_INVALID_STATE)
	{
    	g_java.mids_install_state = INSTALL_ABORT_STATE;
    }
    else if(g_java.mids_update_state  != UPDATE_INVALID_STATE)
    {
    	g_java.mids_update_state = UPDATE_ABORT_STATE;
    }
    else
    {
        ASSERT(0);
    }
    DisplayIdleScreen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_send_mids_install_confirm_res
 * DESCRIPTION
 *  This routines send MSG_ID_MMI_JAVA_INSTALL_CONFIRM_RES to MOD_J2ME
 *  to send install request and set protocol event handler of  MSG_ID_MMI_JAVA_INSTALL_MIDS_CNF
 * PARAMETERS
 *  confirm     [IN]        KAL_TRUE if really want to install this MIDS
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_send_mids_install_confirm_res(kal_bool confirm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_java_install_confirm_res_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ClearInputEventHandler(MMI_DEVICE_ALL); */

    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_SEND_INSTALL_CONFIRM_RES);

    msg = (mmi_java_install_confirm_res_struct*) OslConstructDataPtr(sizeof(mmi_java_install_confirm_res_struct));
    msg->session_id = 0;
    msg->confirm = confirm;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_J2ME;
    Message.oslMsgId = MSG_ID_MMI_JAVA_INSTALL_CONFIRM_RES;
    Message.oslDataPtr = (local_para_struct*) msg;
    Message.oslPeerBuffPtr = NULL;
    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_mids_install_cnf, MSG_ID_MMI_JAVA_INSTALL_MIDS_CNF);
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_recv_mids_install_cnf
 * DESCRIPTION
 *  This routines handles MMI_JAVA_INSTALL_MIDS_CNF from MOD_J2ME to
 *  send a response back to MOD_J2ME
 * PARAMETERS
 *  MsgStruct       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_recv_mids_install_cnf(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_install_mids_cnf_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_INSTALL_MIDS_CNF);

    if (g_java.mids_install_state > INSTALL_VALID_STATE ||
        g_java.mids_install_state == INSTALL_ABORT_STATE)
    {

        g_java.mids_install_state = INSTALL_FINISH_STATE;
        g_java.mids_update_state = UPDATE_FINISH_STATE;
        msg = (mmi_java_install_mids_cnf_struct*) MsgStruct;

        if (msg->error_code == J2ME_NO_ERROR)
        {
            DisplayPopup(
                (PU8) GetString(STR_JAVA_INSTALLED),
                IMG_GLOBAL_ACTIVATED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                SUCCESS_TONE);
        }
        else
        {
            if(mmi_java_is_drm_file(mmi_jad_file_name) || mmi_java_is_drm_file(mmi_jar_file_name))
            {
                mmi_delete_after_install_fail = KAL_FALSE;
            }

            DisplayPopup((PU8) msg->error_string, IMG_GLOBAL_UNFINISHED, 1, UI_POPUP_NOTIFYDURATION_TIME, ERROR_TONE);
        }

        mmi_java_mids_install_clean_screen();

        if(g_java.is_at_install)
        {
            mmi_java_send_at_loacl_install_cnf(msg->error_code);
            g_java.is_at_install = MMI_FALSE;
        }
    #ifdef JAVA_LAUNCH_AFTER_INSTALL
        if (msg->error_code == J2ME_NO_ERROR)
        {
            if (g_keylock_context.gKeyPadLockFlag == 0)
            {
                mmi_java_entry_launch_after_install_confirm();
            }
        }
    #endif /* JAVA_LAUNCH_AFTER_INSTALL */ 
        mmi_java_clear_install_info();
    }
    g_java.mids_install_state = INSTALL_VALID_STATE;
    g_java.mids_update_state = UPDATE_VALID_STATE;
    g_java.is_local_install = MMI_FALSE;
    g_java.is_at_install = MMI_FALSE;
    if(g_java.percentage_ind_midlet_name)
    {
        free_ctrl_buffer(g_java.percentage_ind_midlet_name);
        g_java.percentage_ind_midlet_name = NULL;
    }

    //      if(jad_file) free_ctrl_buffer(jad_file);
    //      if(jar_file) free_ctrl_buffer(jar_file);
    //      jar_file = jad_file = NULL;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_launch_after_install_confirm
 * DESCRIPTION
 *  The entry function to ask user if they want launch directly after installation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_entry_launch_after_install_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *str;

    U32 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_java.mids_info_end = g_java.mids_info_start = -1;

    /* get list at the very beginning */
    needToSendGetListReq = KAL_TRUE;

    g_java.mids_index = 0;
    g_java.mids_info[g_java.mids_index - g_java.mids_info_start].mids_id = (U32) - 1;
    g_java.mids_info[g_java.mids_index - g_java.mids_info_start].mid_count = 1;
    g_java.mid_info[g_java.mid_index].mid_id = (U32) 0;

    mmi_java_fetch_mids_list(0, (UI_string_type) NULL, (PU8*) NULL, 0);

    count = g_java.total_java_app_mids;
    if (count == 0)
    {
        DisplayPopup(
            (PU8) GetString(STR_SCREENSAVER_EMPTY),
            IMG_GLOBAL_EMPTY,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            EMPTY_LIST_TONE);
        return;

    }
    else
    {
        needToSendGetListReq = KAL_TRUE;
        mmi_java_fetch_mids_list(count - 1, (UI_string_type) NULL, (PU8*) NULL, 0);
        g_java.mids_index = count - 1;
        g_java.mid_index = 0;
        EntryNewScreen(SCR_JAVA_LAUNCH_AFTER_INSTALL, NULL, mmi_java_entry_launch_after_install_confirm, NULL);

        guiBuffer = GetCurrGuiBuffer(SCR_JAVA_LAUNCH_AFTER_INSTALL);

        str = (U8*) get_string(STR_JAVA_LAUNCH_AFTER_INSTALL);
        ShowCategory74Screen(
            STR_JAVA_LAUNCH_ASK,
            mmi_java_get_title_icon(),
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            (PU8) str,
            mmi_ucs2strlen((PS8) str),
            NULL);

        SetLeftSoftkeyFunction(mmi_java_launch_after_install_confirm_yes_hdlr, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_java_launch_after_install_confirm_no_hdlr, KEY_EVENT_UP);
    }

}
/*****************************************************************************
 * FUNCTION
 *  mmi_java_launch_after_install
 * DESCRIPTION
 *  Handle Function, revoked when select "YES" to launch after installation.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_entry_mid_launch_after_install(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_java.is_launch_after_install = TRUE;
    g_java.is_select_after_install = FALSE;
    g_java.is_launch_eureka_by_wap = FALSE;
    DisplayIdleScreen();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_launch_ask_terminate_cb
 * DESCRIPTION
 *  Callback function to handle
 *  Ask user if they want to terminate VM first before install MIDlet
 * PARAMETERS
 *  teminate    [IN]    user select yes/No
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_launch_after_install_ask_terminate_cb(BOOL terminate)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(terminate)
    {
        g_java.screen_after_terminate = TER_ENTRY_LAUNCH_AFTER_INSTALL;
        jvm_pause_state_exit();
        mmi_java_entry_terminating(MMI_FALSE);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_launch_after_install_confirm_yes_hdlr
 * DESCRIPTION
 *  Handle Function, revoked when select "YES" to launch after installation.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_launch_after_install_confirm_yes_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 count;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (jvm_is_busy())
    {
        if( jvm_get_initiate_game_type() == GAMETYPE_JAVA_GAME)
        {
            mmi_java_entry_cb_terminate_dialog(mmi_java_launch_after_install_ask_terminate_cb, (U16*)GetString(STR_JAVA_TERMINATE_JAVA_GAME));
        }
        else if( jvm_get_initiate_game_type() == GAMETYPE_INFUSIO_EUREKA )
        {
            mmi_java_entry_cb_terminate_dialog(mmi_java_launch_after_install_ask_terminate_cb, (U16*)GetString(STR_JAVA_TERMINATE_EUREKA));
        }
        else
        {
            mmi_java_display_is_busy();
        }
        DeleteScreenIfPresent(SCR_JAVA_LAUNCH_AFTER_INSTALL);
        return;
    }

    count = g_java.mids_info[g_java.mids_index - g_java.mids_info_start].mid_count;

    if( count == 1 )
    {
        mmi_java_entry_mid_launch_after_install();
    }
    else
    {
        g_java.is_select_after_install = TRUE;
        mmi_java_send_mid_getlist_req();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_launch_after_install_confirm_no_hdlr
 * DESCRIPTION
 *  Handle Function, revoked when select "NO" to launch after installation.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_launch_after_install_confirm_no_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_mids_update
 * DESCRIPTION
 *  Update Feature Entry Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/* void mmi_java_execute_update(void) */
void mmi_java_entry_mids_update(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_java_is_no_network_service())
    {
        DisplayPopup(
            (PU8) GetString(ERROR_NETWORK_FAIL),
            IMG_GLOBAL_ERROR,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
        return;
    }
    if (mmi_java_check_and_display_is_busy())
    {
        return;
    }

    if (g_java.mids_update_state == UPDATE_VALID_STATE)
    {
        g_java.mids_install_state = INSTALL_INVALID_STATE;
        g_java.mids_update_state = UPDATE_CONFIRM_UPD_STATE;
        mmi_java_entry_mids_update_confirm();
    }
    else
    {
        mmi_java_display_is_busy();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_mids_update_confirm
 * DESCRIPTION
 *  Updating Ask Entry Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/* void mmi_java_enter_mids_update_req_asking(void) */
void mmi_java_entry_mids_update_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *str;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_JAVA_UPDATE_CONFIRM, NULL, mmi_java_entry_mids_update_confirm, NULL);

    /* playRequestedTone(WARNING_TONE); */

    guiBuffer = GetCurrGuiBuffer(SCR_JAVA_UPDATE_CONFIRM);

    //      mmi_asc_to_ucs2 ((PS8)gJavaPrintableStr,
    //      "Do you want the update application from the webpage it was installed before?");

    str = (U8*) get_string(STR_JAVA_START_UPDATE_ASK);
    ShowCategory74Screen(
        STR_JAVA_UPDATE_ASK,
        mmi_java_get_title_icon(),
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (PU8) str,
        mmi_ucs2strlen((PS8) str),
        NULL);

    SetKeyHandler(mmi_java_mids_update_confirm_cancel_hdlr, KEY_END, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_java_mids_update_confirm_yes_hdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_java_mids_update_confirm_no_hdlr, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_mids_update_confirm_yes_hdlr
 * DESCRIPTION
 *  Handle Function: revoked when select "YES" in "UPDATE CONFIRM" screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/* void mmi_java_send_mids_update_req_yes(void) */
void mmi_java_mids_update_confirm_yes_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //ClearInputEventHandler(MMI_DEVICE_ALL);
    /* quit the screen of SCR_JAVA_UPDATE_CONFIRM (Update?) */
    GoBackHistory();//KEY PRESSED */

    /* mmi_java_mids_install_clean_screen(); */
    mmi_java_entry_mids_update_start();
    g_java.mids_update_state = UPDATE_JAD_DOWNLOAD_STATE;

    mmi_java_send_mids_update_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_mids_update_confirm_no_hdlr
 * DESCRIPTION
 *  Handle Function: revoked when select "NO" in "UPDATE CONFIRM" screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/* void mmi_java_send_mids_update_req_no(void) */
void mmi_java_mids_update_confirm_no_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //ClearInputEventHandler(MMI_DEVICE_ALL);
    /* quit the screen of SCR_JAVA_UPDATE_CONFIRM (Update?) */
    GoBackHistory();    /* KEY PRESSED */
    g_java.mids_install_state = INSTALL_VALID_STATE;
    g_java.mids_update_state = UPDATE_VALID_STATE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_mids_update_confirm_cancel_hdlr
 * DESCRIPTION
 *  Handle Function: revoked when press "END key" in "UPDATE CONFIRM" screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_mids_update_confirm_cancel_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //ClearInputEventHandler(MMI_DEVICE_ALL);
    /* quit the screen of SCR_JAVA_UPDATE_CONFIRM (Update?) */
    g_java.mids_install_state = INSTALL_VALID_STATE;
    g_java.mids_update_state = UPDATE_VALID_STATE;
    DisplayIdleScreen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_mids_update_start
 * DESCRIPTION
 *  Updating Entry Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/* void mmi_java_enter_mids_start_updating(void) */
void mmi_java_entry_mids_update_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_JAVA_START_UPDATING, NULL, mmi_java_entry_mids_update_start, NULL);

    ShowCategory66Screen(
        STR_JAVA_START_UPDATING,
        mmi_java_get_title_icon(),
        0,
        0,
        STR_JAVA_ABORT,
        IMG_JAVA_ABORT,
        (PU8) GetString(STR_JAVA_START_UPDATING),
        IMG_PROCESSING_PHONEBOOK,
        NULL);

    SetKeyHandler(mmi_java_mids_endkey_abort_hdlr, KEY_END, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(mmi_java_mids_abort_hdlr, KEY_EVENT_UP);
    SetDelScrnIDCallbackHandler(SCR_JAVA_START_UPDATING, mmi_java_mids_install_delete_callback);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_send_mids_update_req
 * DESCRIPTION
 *  This routines send MSG_ID_MMI_JAVA_MIDS_UPDATE_REQ to MOD_J2ME to send update
 *  request and set protocol event handler of  MSG_ID_MMI_JAVA_MIDS_UPDATE_CNF
 * PARAMETERS
 *  void
 *  IN   confirm    KAL_TRUE if really want to install this MIDS(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_send_mids_update_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_java_mids_update_req_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_SEND_MIDS_UPDATE_REQ);
    /* ClearInputEventHandler(MMI_DEVICE_ALL); */

    msg = (mmi_java_mids_update_req_struct*) OslConstructDataPtr(sizeof(mmi_java_mids_update_req_struct));
    msg->session_id = 0;
	msg->game_type = GAMETYPE_JAVA_GAME;
    msg->mids_id = g_java.mids_info[g_java.mids_index - g_java.mids_info_start].mids_id;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_J2ME;
    Message.oslMsgId = MSG_ID_MMI_JAVA_MIDS_UPDATE_REQ;
    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_mids_update_cnf, MSG_ID_MMI_JAVA_MIDS_UPDATE_CNF);
    Message.oslDataPtr = (local_para_struct*) msg;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_recv_mids_update_cnf
 * DESCRIPTION
 *  This routines handles MMI_JAVA_MIDS_UPDATE_CNF from MOD_J2ME to
 *  popup a screen to indicate the user Update Done
 * PARAMETERS
 *  MsgStruct       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_recv_mids_update_cnf(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_mids_update_cnf_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_MIDS_UPDATE_CNF);

    if (g_java.mids_update_state > UPDATE_VALID_STATE ||
        g_java.mids_update_state == UPDATE_ABORT_STATE)
    {

        g_java.mids_install_state = INSTALL_FINISH_STATE;
        g_java.mids_update_state = UPDATE_FINISH_STATE;

        msg = (mmi_java_mids_update_cnf_struct*) MsgStruct;
/*
        if (msg->error_code == J2ME_NO_ERROR)
        {
            DisplayPopup(
                (PU8) GetString(STR_JAVA_UPDATED),
                IMG_GLOBAL_OK,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                SUCCESS_TONE);
        }
        else
        {
            DisplayPopup((PU8) msg->error_string, IMG_GLOBAL_UNFINISHED, 1, UI_POPUP_NOTIFYDURATION_TIME, ERROR_TONE);
        }
        */
        mmi_java_mids_install_clean_screen();
    }
    g_java.mids_install_state = INSTALL_VALID_STATE;
    g_java.mids_update_state = UPDATE_VALID_STATE;
    g_java.is_local_install = MMI_FALSE;
    g_java.is_at_install = MMI_FALSE;
    if(g_java.percentage_ind_midlet_name)
    {
        free_ctrl_buffer(g_java.percentage_ind_midlet_name);
        g_java.percentage_ind_midlet_name = NULL;
}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_recv_get_file_and_save_ind
 * DESCRIPTION
 *  This routines handles MMI_WAP_GET_FILE_AND_SAVE_IND  from MOD_WAP to
 *  display a animation to indicate the user Downloading is processing
 * PARAMETERS
 *  MsgStruct       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_java_get_file_and_save_ind_struct java_get_file_and_save_ind_msg;
void mmi_java_recv_get_file_and_save_ind(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_WAP_GET_FILE_AND_SAVE_IND);

    kal_mem_cpy(
        &java_get_file_and_save_ind_msg,
        (mmi_java_get_file_and_save_ind_struct*) MsgStruct,
        sizeof(mmi_java_get_file_and_save_ind_struct));
    if(GetActiveScreenId() == SCR_JAVA_SHOW_PERCENTAGE)
    {
        GoBackHistory();
    }
    DeleteScreenIfPresent(SCR_JAVA_SHOW_PERCENTAGE);
    mmi_java_send_get_file_and_sav_res();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_mids_vm_installing
 * DESCRIPTION
 *  MIDS VM Installing Entry Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_entry_mids_vm_installing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_JAVA_VM_INSTALLING, NULL, mmi_java_entry_mids_vm_installing, NULL);

    ShowCategory66Screen(
        STR_JAVA_VM_INSTALLING,
        mmi_java_get_title_icon(),
        0,
        0,
        STR_JAVA_ABORT,
        IMG_JAVA_ABORT,
        (PU8) GetString(STR_JAVA_VM_INSTALLING),
        IMG_PROCESSING_PHONEBOOK,
        NULL);

    SetKeyHandler(mmi_java_mids_endkey_abort_hdlr, KEY_END, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(mmi_java_mids_abort_hdlr, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_send_java_get_file_and_sav_res
 * DESCRIPTION
 *  This routines send MSG_ID_MMI_WAP_GET_FILE_AND_SAVE_RES to MOD_WAP to send
 *  response
 * PARAMETERS
 *  void
 *  IN   confirm    KAL_TRUE if really want to install this MIDS(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_send_get_file_and_sav_res(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_java_get_file_and_save_res_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_WAP_GET_FILE_AND_SAVE_RES);
    /* ClearInputEventHandler(MMI_DEVICE_ALL); */

    msg = (mmi_java_get_file_and_save_res_struct*) OslConstructDataPtr(sizeof(mmi_java_get_file_and_save_res_struct));
    msg->session_id = msg->session_id;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_J2ME;
    Message.oslMsgId = MSG_ID_MMI_JAVA_GET_FILE_AND_SAVE_RES;
    Message.oslDataPtr = (local_para_struct*) msg;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_recv_wap_abort_cnf
 * DESCRIPTION
 *  This routines handles MMI_WAP_ABORT_CNF  from MOD_WAP to popup a screen
 *  indicating WAP terminates its process and MMI can then abort VM.
 * PARAMETERS
 *  MsgStruct       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_recv_wap_abort_cnf(void *MsgStruct)   /* no used */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_wap_abort_cnf_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_ABORT_CNF);

    msg = (mmi_wap_abort_cnf_struct*) MsgStruct;

    if (msg->error_code == J2ME_NO_ERROR)
    {
        mmi_java_send_java_abort_req();
    }
    else if (msg->error_code == J2ME_ABORT_FAIL)
    {
        if (msg->is_JAD_file == KAL_TRUE)
        {
            mmi_java_send_java_abort_req();
        }
        else
        {
            DisplayPopup(
                (PU8) GetString(STR_JAVA_ABORT_FAILED),
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                ERROR_TONE);
        }
    }
    else
    {
        ASSERT((msg->error_code != J2ME_NO_ERROR) && (msg->error_code == J2ME_ABORT_FAIL));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_mids_abort_hdlr
 * DESCRIPTION
 *  This routines send MSG_ID_MMI_JAVA_ABORT_REQ to MOD_J2ME
 *  to request aborting
 * PARAMETERS
 *  void
 *  IN permission(?)
 *  IN execute(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_mids_abort_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //ClearInputEventHandler(MMI_DEVICE_ALL);

    mmi_java_send_java_abort_req();
    mmi_java_mids_install_clean_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_mids_endkey_abort_hdlr
 * DESCRIPTION
 *  This routines send MSG_ID_MMI_JAVA_ABORT_REQ to MOD_J2ME
 *  to request aborting
 *  and go to Idle screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_mids_endkey_abort_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //ClearInputEventHandler(MMI_DEVICE_ALL);
    //      g_java.mids_install_state = INSTALL_VALID_STATE;
    //      g_java.mids_update_state = UPDATE_VALID_STATE;
    mmi_java_send_java_abort_req();
    DisplayIdleScreen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_send_java_abort_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_send_java_abort_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_java_abort_req_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_SEND_ABORT_REQ);

    if (g_java.mids_install_state > INSTALL_VALID_STATE && g_java.mids_install_state != INSTALL_INVALID_STATE)
    {
        g_java.mids_install_state = INSTALL_ABORT_STATE;
    }
    else if (g_java.mids_update_state > UPDATE_VALID_STATE && g_java.mids_update_state != UPDATE_INVALID_STATE)
    {
        g_java.mids_update_state = UPDATE_ABORT_STATE;
    }

    msg = (mmi_java_abort_req_struct*) OslConstructDataPtr(sizeof(mmi_java_abort_req_struct));

    msg->session_id = 0;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_J2ME;
    Message.oslMsgId = MSG_ID_MMI_JAVA_ABORT_REQ;
    Message.oslDataPtr = (local_para_struct*) msg;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_recv_java_abort_cnf
 * DESCRIPTION
 *  This routines handles MMI_JAVA_ABORT_CNF  from MOD_J2ME to popup a screen
 *  indicating VM terminates its process.
 * PARAMETERS
 *  MsgStruct       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_recv_java_abort_cnf(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_abort_cnf_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_ABORT_CNF);

    msg = (mmi_java_abort_cnf_struct*) MsgStruct;

    if (msg->error_code == J2ME_NO_ERROR)
    {
        /* DisplayPopup((PU8)GetString(STR_JAVA_ABORTED), IMG_GLOBAL_OK, 1, UI_POPUP_NOTIFYDURATION_TIME, SUCCESS_TONE); */
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_JAVA_ABORTED),
            IMG_GLOBAL_UNFINISHED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_local_install_content_routing
 * DESCRIPTION
 *  Parse information in the MIDlet before start to local install
 * PARAMETERS
 *  file_path       [IN]        The file path of MIDlet which user want to install
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_local_install_content_routing(kal_uint8 *file_path)
/* void j2me_content_routing(kal_uint8* file_path) */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int len;
    kal_uint8 *jad_file = NULL;
    kal_uint8 *jar_file = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_java.is_local_install = MMI_TRUE;

    len = mmi_ucs2strlen((const S8*)file_path);
    len <<= 1;

    //      jad_file = jar_file = NULL;
    //      if(jad_file) free_ctrl_buffer(jad_file);
    //      if(jar_file) free_ctrl_buffer(jar_file);

    if (((kal_wchar*) file_path)[(len - 2) >> 1] == 'd' || ((kal_wchar*) file_path)[(len - 2) >> 1] == 'D')
    {
        jad_file = get_ctrl_buffer((kal_uint16) len + 2);
        memcpy(jad_file, file_path, len + 2);
        if ((jar_file = (kal_uint8*) get_jar_url((kal_wchar*) jad_file)) == NULL)
        {
            jar_file = get_ctrl_buffer((kal_uint16) len + 2);
            memcpy(jar_file, file_path, len + 2);
            ((kal_wchar*) jar_file)[(len - 2) >> 1] = 'r';
        }

        if (FS_GetAttributes((WCHAR*) jar_file) < FS_NO_ERROR)
        {
            free_ctrl_buffer(jar_file);
            jar_file = get_ctrl_buffer((kal_uint16) len + 2);
            memcpy(jar_file, file_path, len + 2);
            ((kal_wchar*) jar_file)[(len - 2) >> 1] = 'r';
            if (FS_GetAttributes((WCHAR*) jar_file) < FS_NO_ERROR)
            {
                DisplayPopup(
                    (PU8) GetString(STR_JAVA_ERROR_CODE_JAR_NOT_FOUND),
                    IMG_GLOBAL_UNFINISHED,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    ERROR_TONE);
                return;
            }
        }

        mmi_java_mids_install(0, (kal_wchar*) jad_file, (kal_wchar*) jar_file, L"file://", KAL_FALSE);


    }
    else
    {
        jar_file = get_ctrl_buffer((kal_uint16) len + 2);
        memcpy(jar_file, file_path, len + 2);
        mmi_java_mids_install(0, NULL, (kal_wchar*) jar_file, L"file://", KAL_FALSE);
    }

    if(jad_file) free_ctrl_buffer(jad_file);
    if(jar_file) free_ctrl_buffer(jar_file);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_recv_at_loacl_install_res
 * DESCRIPTION
 *  Handle Function: revoked when receive MMI_JAVA_AT_LOCAL_INSTALL_CNF
 * PARAMETERS
 *  MsgStruct       [IN]        The message sent from AT command. We will pass to Java task.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_send_at_loacl_install_cnf(S32 error_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_local_install_res_req_struct *p = NEW_LOCAL_PTR(mmi_java_local_install_res_req_struct);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_AT_LOCAL_INSTALL_CNF);

    p->error_code = error_code;

    SEND_MESSAGE(MOD_MMI, MOD_L4C, MMI_J2ME_SAP, MSG_ID_MMI_JAVA_LOCAL_INSTALL_RES_REQ, p, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_recv_at_local_install_req
 * DESCRIPTION
 *  Handle Function: revoked when receive MMI_JAVA_AT_LOCAL_INSTALL_REQ
 * PARAMETERS
 *  MsgStruct       [IN]        The message sent from AT command. We will pass to java task
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_recv_at_local_install_req(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_local_install_req_ind_struct *s = (mmi_java_local_install_req_ind_struct*) MsgStruct;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_AT_LOCAL_INSTALL_REQ);

    /* java_local_install_cnt++; */
#if defined(J2ME_SUPPORT_PAUSE) && !defined(__SUPPORT_NATIVE_INSTALLER__)
    if (jvm_is_pause_mode())
    {
        mmi_java_display_is_busy_for_pause_mode();
        mmi_java_send_at_loacl_install_cnf(J2ME_INSTALL_FAIL);
        goto FINAL;
    }
#endif /* J2ME_SUPPORT_PAUSE */

    if (!mmi_java_is_in_idle_screen() 
#ifndef __SUPPORT_NATIVE_INSTALLER__
		|| jvm_is_busy()
#else
		|| !jvm_task_ready()
#endif /* !__SUPPORT_NATIVE_INSTALLER__ */
		)
    {
        mmi_java_display_is_busy();
        mmi_java_send_at_loacl_install_cnf(J2ME_INSTALL_FAIL);
        goto FINAL;
    }

    g_java.is_at_install = MMI_TRUE;
    mmi_java_mids_install(0, (kal_wchar*) s->jad_file_name, (kal_wchar*) s->jar_file_name, L"file://", KAL_FALSE);

FINAL:
    if(s->jad_file_name!=NULL)
        free_ctrl_buffer(s->jad_file_name);
    if(s->jar_file_name!=NULL)
        free_ctrl_buffer(s->jar_file_name);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_recv_show_percentage_ind
 * DESCRIPTION
 * PARAMETERS
 *  MsgStruct       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_recv_show_percentage_ind(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_show_percentage_ind_struct *msg = (mmi_java_show_percentage_ind_struct*) MsgStruct;
    U8 percentage;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_SHOW_PERCENTAGE_IND, msg->current, msg->total);

    if  (g_java.mids_install_state > INSTALL_VALID_STATE ||
         g_java.mids_update_state > UPDATE_VALID_STATE )
    {
        if(g_java.percentage_ind_midlet_name)
        {
            free_ctrl_buffer(msg->midlet_name);
        }
        else
        {
            g_java.percentage_ind_midlet_name = (U8*)msg->midlet_name;
        }
        if( msg->total != 0)
        {
            percentage = (U8) (msg->current * 100 / msg->total);
        }
        else
        {
            percentage = 99;
        }

        if (GetActiveScreenId() == SCR_JAVA_SHOW_PERCENTAGE)
        {
            if (g_java.download_percentage != percentage)
            {
                g_java.download_percentage = percentage;
                UpdateCategory402Value(g_java.download_percentage, NULL);
            }
        }
        else if (!IsScreenPresent(SCR_JAVA_SHOW_PERCENTAGE))
        {
            g_java.download_percentage = percentage;
            mmi_java_entry_pecentage_bar();
        }
        else
        {
            g_java.download_percentage = percentage;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_pecentage_bar
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_entry_pecentage_bar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_JAVA_SHOW_PERCENTAGE, NULL, mmi_java_entry_pecentage_bar, NULL);

    ShowCategory402Screen(
        (U8*) GetString(STR_JAVA_DOWNLOADING),
        mmi_java_get_title_icon(),
        0,
        0,
        STR_JAVA_ABORT,
        IMG_JAVA_ABORT,
        NULL,//(U8*)mmi_java_show_percentage_ind_msg.midlet_name,
        g_java.download_percentage,
        NULL);

    SetKeyHandler(mmi_java_mids_endkey_abort_hdlr, KEY_END, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(mmi_java_mids_abort_hdlr, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_send_get_install_drv_res
 * DESCRIPTION
 * PARAMETERS
 *  drv     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_send_get_install_drv_res(S8 drv)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_java_get_install_drv_res_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg = (mmi_java_get_install_drv_res_struct*) OslConstructDataPtr(sizeof(mmi_java_get_install_drv_res_struct));

    if(drv == 0)  /* User Cancel */
    {
        msg->drv = -1;
    }
    else
    {
    msg->drv = drv;
    }

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_J2ME;
    Message.oslMsgId = MSG_ID_MMI_JAVA_GET_INSTALL_DRV_RES;
    Message.oslDataPtr = (local_para_struct*) msg;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_recv_get_install_drv_ind
 * DESCRIPTION
 * PARAMETERS
 *  MsgStruct       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_recv_get_install_drv_ind(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //mmi_java_get_install_drv_ind_struct *msg = (mmi_java_get_install_drv_ind_struct*) MsgStruct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmgr_sel_drv_and_enter(APP_JAVA, mmi_java_send_get_install_drv_res, 0);
}

#define AUTHENTICATION

static U8 g_java_auth_username[ MMI_JAVA_AUTH_LEN_USERNAME * ENCODING_LENGTH];
static U8 g_java_auth_password[ MMI_JAVA_AUTH_LEN_PASSWORD * ENCODING_LENGTH];

/*****************************************************************************
 * FUNCTION
 *  mmi_java_auth_yes_hdlr
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_auth_yes_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // TODO
    mmi_java_send_get_auth_res(g_java_auth_username, g_java_auth_password);

    if( GetActiveScreenId() == SCR_JAVA_AUTH )
    {
        GoBackHistory();
    }
    else
    {
        GoBacknHistory(1);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_auth_endkey_hdlr
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_auth_endkey_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // TODO
    //mmi_java_send_cancel_req(OMA_DOWNLOAD_MEDIA_OBJ_REQUEST);
    mmi_java_send_get_auth_res(NULL, NULL);
    DisplayIdleScreen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_auth_cancel_hdlr
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_auth_no_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // TODO
    mmi_java_send_get_auth_res(NULL, NULL);

    if( GetActiveScreenId() == SCR_JAVA_AUTH )
    {
        GoBackHistory();
    }
    else
    {
        GoBacknHistory(1);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_auth_confirm_hdlr
 * DESCRIPTION
 *  Function for submitting the authentication information
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_auth_confirm_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(mmi_ucs2strlen((S8*)g_java_auth_username) == 0)
    {
        DisplayPopup((PU8) GetString(STR_DA_EMPTY_USERNAME), IMG_GLOBAL_ERROR, 1, UI_POPUP_NOTIFYDURATION_TIME, (U8) ERROR_TONE);
        return;
    }
    else
    {
        DisplayConfirm(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            get_string(STR_GLOBAL_SUBMIT),
            IMG_GLOBAL_QUESTION,
            WARNING_TONE);
        SetKeyHandler(mmi_java_auth_endkey_hdlr, KEY_END, KEY_EVENT_DOWN);
        SetLeftSoftkeyFunction(mmi_java_auth_yes_hdlr, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_java_auth_no_hdlr, KEY_EVENT_UP);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_auth_open_full_screen_editor
 * DESCRIPTION
 *  Callback for full screen edit from inline edit screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_auth_open_full_screen_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecuteCurrKeyHandler(KEY_0, KEY_EVENT_DOWN);
    ExecuteCurrKeyHandler(KEY_0, KEY_EVENT_UP);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_java_auth_full_screen_editor_options
 * DESCRIPTION
 *  Callback for full screen edit from inline edit screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_auth_full_screen_editor_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
    SetLeftSoftkeyFunction(EntryScrForInputMethodAndDone, KEY_EVENT_UP);
    SetInputMethodAndDoneCaptionIcon(mmi_java_get_title_icon());
}
/*****************************************************************************
 * FUNCTION
 *  mmi_java_softkey_label_highlight_hdlr
 * DESCRIPTION
 *  Custom Highlight handler to change the label of LSK in case of inline edit screen.
 * PARAMETERS
 *  index       [IN]        Index of highlighted item
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_softkey_label_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 NumericKeys[] = {KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_STAR, KEY_POUND};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetGroupKeyHandler(mmi_java_auth_open_full_screen_editor, NumericKeys, 11, KEY_EVENT_UP);

    ChangeLeftSoftkey(STR_GLOBAL_EDIT, 0);
    SetKeyHandler(mmi_java_auth_endkey_hdlr, KEY_END, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_java_auth_open_full_screen_editor, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_exit_auth_handler
 * DESCRIPTION
 *  Exit function for authentication screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_exit_auth_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history Scr;
    S16 nHistory = 0;
    U16 inputBufferSize;    /* added for inline edit history */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Scr.scrnID = SCR_JAVA_AUTH;
    CloseCategory57Screen();
    Scr.entryFuncPtr = mmi_java_entry_auth;
    mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) & nHistory);
    GetCategory57History(Scr.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();    /* added for inline edit history */
    GetCategory57Data((U8*) Scr.inputBuffer);           /* added for inline edit history */
    AddNHistory(Scr, (U16) inputBufferSize);            /* added for inline edit history */
}

/*************************************************************************
* FUNCTION
* DESCRIPTION
* PARAMETERS
* RETURNS
*************************************************************************/
void mmi_java_entry_auth(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 inputBufferSize;
    InlineItem authenticate_list[4];
    U16 IconsImageList[4];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_JAVA_AUTH, mmi_java_exit_auth_handler, NULL, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_JAVA_AUTH);

    InitializeCategory57Screen();
    memset(authenticate_list, 0, sizeof(authenticate_list));

    /* For username caption */
    SetInlineItemActivation(
        &authenticate_list[J2ME_INLINE_USERNAME_CAPTION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(&authenticate_list[J2ME_INLINE_USERNAME_CAPTION], (U8*) GetString(STR_GLOBAL_USERNAME));

    /* For username string */
    SetInlineItemActivation(&authenticate_list[J2ME_INLINE_USERNAME], KEY_0, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit(
        &authenticate_list[J2ME_INLINE_USERNAME],
        STR_GLOBAL_USERNAME,
        mmi_java_get_title_icon(),
        (U8*) g_java_auth_username,
        MMI_JAVA_AUTH_LEN_USERNAME,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES);
    SetInlineFullScreenEditCustomFunction(
        &authenticate_list[J2ME_INLINE_USERNAME],
        mmi_java_auth_full_screen_editor_options);

    /* For password caption */
    SetInlineItemActivation(
        &authenticate_list[J2ME_INLINE_PASSWORD_CAPTION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(&authenticate_list[J2ME_INLINE_PASSWORD_CAPTION], (U8*) GetString(STR_GLOBAL_PASSWORD));

    /* For password string */
    SetInlineItemActivation(&authenticate_list[J2ME_INLINE_PASSWORD], KEY_0, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit(
        &authenticate_list[J2ME_INLINE_PASSWORD],
        STR_GLOBAL_PASSWORD,
        mmi_java_get_title_icon(),
        (U8*) g_java_auth_password,
        MMI_JAVA_AUTH_LEN_PASSWORD,
        INPUT_TYPE_ALPHANUMERIC_PASSWORD | INPUT_TYPE_USE_ONLY_ENGLISH_MODES);
    SetInlineFullScreenEditCustomFunction(
        &authenticate_list[J2ME_INLINE_PASSWORD],
        mmi_java_auth_full_screen_editor_options);

    inputBuffer = GetCurrNInputBuffer(SCR_JAVA_AUTH, &inputBufferSize);

    if (inputBuffer != NULL)
    {
        SetCategory57Data(authenticate_list, 4, inputBuffer);
    }

    SetParentHandler(0);

    /* Set the softkey label to be displayed in  Category57 screen */
    RegisterHighlightHandler(mmi_java_softkey_label_highlight_hdlr);

    IconsImageList[0] = gIndexIconsImageList[0];
    IconsImageList[1] = 0;
    IconsImageList[2] = gIndexIconsImageList[1];
    IconsImageList[3] = 0;

    ShowCategory57Screen(
        STR_GLOBAL_AUTHENTICATION,
        mmi_java_get_title_icon(),
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_CANCEL,
        0,
        4,
        (U16*) IconsImageList,
        authenticate_list,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions( mmi_java_auth_confirm_hdlr, mmi_java_auth_no_hdlr);

}

/*************************************************************************
* FUNCTION
* DESCRIPTION
* PARAMETERS
* RETURNS
*************************************************************************/
void mmi_java_recv_get_auth_ind(void *MsgStruct)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_get_auth_ind_struct *msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg = (mmi_java_get_auth_ind_struct *) MsgStruct;

    memset(g_java_auth_username, 0, sizeof(g_java_auth_username));
    memset(g_java_auth_password, 0, sizeof(g_java_auth_password));

    mmi_java_entry_auth();
}

/*************************************************************************
* FUNCTION
* DESCRIPTION
* PARAMETERS
* RETURNS
*************************************************************************/
void mmi_java_send_get_auth_res(U8* username, U8* password)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_java_get_auth_res_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg = (mmi_java_get_auth_res_struct*) OslConstructDataPtr(sizeof(mmi_java_get_auth_res_struct));

    mmi_ucs2cpy((S8*)msg->username, (S8*) username);
    mmi_ucs2cpy((S8*)msg->password, (S8*) password);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_J2ME;
    Message.oslMsgId = MSG_ID_MMI_JAVA_GET_AUTH_RES;
    Message.oslDataPtr = (local_para_struct*) msg;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

}


#endif /* __J2ME__ */

