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
 * JProvWap.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is general source file for OTA provisioning
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
#ifndef _JPROVWAP_C
#define _JPROVWAP_C


#if defined (JATAAYU_SUPPORT) && (defined (WAP_SUPPORT) || (defined (MMS_SUPPORT)))
#include <ddl.h>
#include "JProvWap.h"
#include "JBrowserMMIProts.h"

#ifdef __MMI_JATAAYU_CCA_SUPPORT__
#include "JProvCCAHandler.h"
#else /* __MMI_JATAAYU_CCA_SUPPORT__ */ 
#include "FileManagerDef.h"
#include "FileMgr.h"
#include "Ucs2prot.h"
#include "custom_nvram_editor_data_item.h"
#include "JProvOma.h"
#include "JProvNE.h"
#include <jcal.h>
#include <jdi_XML.h>
#include <jdi_WBXML.h>
#include <jdi_urivalidation.h>
#include "JProfileHandlerTypes.h"
#include "JProfileHandlerResDef.h"
#include "JProfileHandlerProts.h"
#include "JBrowserResDef.h"
#include "app_mine.h"
#include "MessagesResourceData.h"       /* IMG_NEW_MESSAGE_NOTIFICATION_MSG */
#include "SmsGuiInterfaceType.h"
#include "SmsGuiInterfaceProt.h"
#include "jdd_ui_ResDef.h"

#include "gpioInc.h"    /* TurnOnBacklight */

#include "SettingProfile.h"     /* For WARNING_TONE Enum value */
#include "ProfileGprots.h"      /* playRequestedTone() */
#include "AlarmFrameWorkProt.h"

static prov_queue_data_struct *prov_data_queue[PROV_MAX_NBR_DOCUMENTS];
static S8 g_prov_data_queue_current_item = 0;
static S8 g_prov_data_queue_last_item = 0;
S8 g_prov_data_queue_size = 0;

static U8 g_prov_settings_present = 0x00;

U8 g_prov_bearer = PROV_INVALID_BEARER;
U8 g_prov_setting_type = PROV_BRS_SETTINGS;
U8 g_prov_data_account_index = 0x00;
U8 g_prov_appl_flag = PROV_NO_APPLICATION;

mmi_cc_set_csd_profile_req_struct *g_prov_set_csd_req_p = NULL;

#ifdef __MMI_GPRS_FEATURES__
mmi_ps_set_gprs_data_account_req_struct *g_prov_set_gprs_req_p = NULL;
#endif 

static U16 g_prov_instal_stringID;

FuncPtr g_prov_timeout_hdlr = NULL;

extern void (*g_DTCNTReadyCallback) (void);
extern void PlayMessageArrivalTone(void);
extern pBOOL GetUCS2Flag(PS8 buffer);
extern MMI_BOOL mmi_brw_validate_url(U8 *url_p);

#endif /* __MMI_JATAAYU_CCA_SUPPORT__ */ 

U16 g_prov_newsetting_stringID = STR_ID_PROV_NEW_SETTINGS;
U8 g_prov_pend_set = 0;
U8 *g_prov_profile_name_p = NULL;

#define PROV_MAX_FILE_SIZE_SUPPORT  10*1024
ETaskID g_activated_task_id = 0;


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_receive_da_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  session_id                  [IN]        
 *  mime_type                   [IN]        
 *  mime_subtype                [IN]        
 *  action_type                 [IN]        
 *  filename                    [IN]        
 *  download_url                [IN]        
 *  mime_type_str_string        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_receive_da_file(
        S32 session_id,
        S32 mime_type,
        S32 mime_subtype,
        S32 action_type,
        PU16 filename,
        PS8 download_url,
        PS8 mime_type_str_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;
    JC_UINT32 uiFileSize = 0;
    JDD_FSHANDLE FileSysHandle = NULL;
    JDD_FILE FileHandle = NULL;
    JC_INT32 iNumberofItems;

    U32 provLength = 0;
    S8 *prov_buffer_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("Inside mmi_prov_receive_da_file");
    g_activated_task_id = jdd_MemGetActiveModuleID();
    jdd_MemSetActiveModuleID(E_TASK_BROWSER_UI);

    ret_code = jdd_FSInitialize(&FileSysHandle);
    if (ret_code != JC_OK)
    {
        ASSERT(0);
    }

    FileHandle = (JDD_FILE) jdd_FSOpen(FileSysHandle, (U16*) filename, E_OPEN_READ_MODE);

    jdd_FSGetSize(FileHandle, &uiFileSize);
    provLength = uiFileSize;
    if (provLength >= PROV_MAX_FILE_SIZE_SUPPORT)
    {
        provLength = 0;
    }
    else
    {
        prov_buffer_p = jdd_MemAlloc((provLength + 1), 1);
        if (prov_buffer_p == NULL)
        {
            ASSERT(0);
        }

        iNumberofItems = jdd_FSRead(prov_buffer_p, provLength, 1, FileHandle);

    }
    jdd_FSClose(FileHandle);
    jdd_FSDelete(FileSysHandle, (U16*) filename);
    jdd_FSDeinitialize(FileSysHandle);
#ifdef __MMI_JATAAYU_CCA_SUPPORT__
    if (mmi_prov_cca_check_queue_size())
#else 
    if (g_prov_data_queue_size == PROV_MAX_NBR_DOCUMENTS)
#endif 
    {

        DisplayPopup(
            (PU8) GetString(STR_ID_PROV_MAX_QUE_SIZE),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            WARNING_TONE);

        return;
    }

#ifdef __MMI_JATAAYU_CCA_SUPPORT__
    mmi_prov_provisioning_data_handler(prov_buffer_p, provLength, (S8*) mime_type_str_string);
    jdd_MemSetActiveModuleID(g_activated_task_id);
    g_activated_task_id = 0;
#else /* __MMI_JATAAYU_CCA_SUPPORT__ */ 
    mmi_prov_handle_provisioning_data_ext(prov_buffer_p, provLength, (S8*) mime_type_str_string);
#endif /* __MMI_JATAAYU_CCA_SUPPORT__ */ 

    PRINT_INFORMATION("Exit mmi_prov_receive_da_file");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_handle_provisioning_data
 * DESCRIPTION
 *  It opens the file at the path specified,reads the file & copy data into buffer and then pass
 *  the buffer for further processing
 * PARAMETERS
 *  content_type_p      [IN]        
 *  filePath            [IN]        
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 mmi_prov_handle_provisioning_data(kal_int8 *content_type_p, kal_wchar *filePath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    JC_RETCODE ret_code = JC_OK;
    JC_UINT32 uiFileSize = 0;
    JDD_FSHANDLE FileSysHandle = NULL;
    JDD_FILE FileHandle = NULL;
    JC_INT32 iNumberofItems;

    U32 provLength = 0;
    S8 *prov_buffer_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret_code = jdd_FSInitialize(&FileSysHandle);
    if (ret_code != JC_OK)
    {
        return ret_code;
    }

    FileHandle = (JDD_FILE) jdd_FSOpen(FileSysHandle, (U16*) filePath, E_OPEN_READ_MODE);

    jdd_FSGetSize(FileHandle, &uiFileSize);
    provLength = uiFileSize;
    if (provLength >= PROV_MAX_FILE_SIZE_SUPPORT)
    {
        provLength = 0;
    }
    else
    {
        prov_buffer_p = jdd_MemAlloc((provLength + 1), 1);

        iNumberofItems = jdd_FSRead(prov_buffer_p, provLength, 1, FileHandle);
    }
    jdd_FSClose(FileHandle);
    jdd_FSDelete(FileSysHandle, (U16*) filePath);
    jdd_FSDeinitialize(FileSysHandle);

#ifdef __MMI_JATAAYU_CCA_SUPPORT__
    if (mmi_prov_cca_check_queue_size())
#else 
    if (g_prov_data_queue_size == PROV_MAX_NBR_DOCUMENTS)
#endif 
    {

        DisplayPopup(
            (PU8) GetString(STR_ID_PROV_MAX_QUE_SIZE),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            WARNING_TONE);

        return ret_code;
    }

#ifdef __MMI_JATAAYU_CCA_SUPPORT__
    mmi_prov_provisioning_data_handler(prov_buffer_p, provLength, (S8*) content_type_p);
#else 
    mmi_prov_handle_provisioning_data_ext(prov_buffer_p, provLength, (S8*) content_type_p);
#endif 

    return ret_code;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_convert_ip_string_to_array
 * DESCRIPTION
 *  This converts an IP string into an array
 * PARAMETERS
 *  parm_element_p      [IN]        
 *  proxy_ip_p          [IN]        IN\OUT
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_prov_convert_ip_string_to_array(S8 *parm_element_p, U8 *proxy_ip_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 proxy[MAX_PART_IP_ADDRESS];
    U32 i, j;
    U32 ip_part;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_brw_check_ip(parm_element_p))
    {
        return PROV_ERR;
    }
    if ((*parm_element_p) < '0' || (*parm_element_p) > '9')
    {
        return PROV_ERR;
    }

    for (j = 0; j < MAX_PART_IP_ADDRESS; ++j)
    {
        for (i = 0; (i < 3) && (strlen(parm_element_p));)
        {
            if (*parm_element_p == '.')
            {
                break;
            }
            if ((*parm_element_p) >= '0' && (*parm_element_p) <= '9')
            {
                proxy[i] = *parm_element_p++;
                i++;
            }
            else
            {
                return PROV_ERR;
            }
        }
        proxy[i] = '\0';
        ip_part = (U32) atoi(proxy);
        if (ip_part > PROV_IP_PART_MAX_VALUE)
        {
            ip_part = PROV_IP_PART_MAX_VALUE;

        }
        proxy_ip_p[j] = (U8) ip_part;
        ++parm_element_p;
    }
    return PROV_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_deinit
 * DESCRIPTION
 *  It deinits the Provisioing module
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* g_prov_settings_present=0x00; */
}

#ifndef __MMI_JATAAYU_CCA_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_handle_provisioning_data_ext
 * DESCRIPTION
 *  It handles the prov. data buffer received
 *  based on if it is an OMA or Nokia format, a popup is shown if max queue size is reached
 * PARAMETERS
 *  prov_buffer_p       [IN]        
 *  prov_length         [IN]        
 *  content_type_p      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_handle_provisioning_data_ext(S8 *prov_buffer_p, U32 prov_length, S8 *content_type_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if (g_prov_data_queue_size == PROV_MAX_NBR_DOCUMENTS)
       {
       
       DisplayPopup(
       (PU8) GetString(STR_ID_PROV_MAX_QUE_SIZE),
       IMG_GLOBAL_WARNING,
       1,
       UI_POPUP_NOTIFYDURATION_TIME,
       WARNING_TONE);
       return;
       }
       else
       { */
    if (mmi_prov_check_if_substring(content_type_p, APPLICATION_VND_WAP_CONNECTIVITY_WBXML) == 0)
    {
        g_prov_instal_stringID = STR_ID_PROV_INSTALL_SETTINGS;
        g_prov_newsetting_stringID = STR_ID_PROV_NEW_SETTINGS;
        mmi_prov_oma_handle_settings(prov_buffer_p, prov_length, content_type_p);

    }
    else if (mmi_prov_check_if_substring(content_type_p, APPLICATION_X_WAP_PROV_BROWSER_SETTINGS) == 0)
    {

        g_prov_instal_stringID = STR_ID_PROV_INSTALL_SETTINGS;
        g_prov_newsetting_stringID = STR_ID_PROV_NEW_SETTINGS;
        mmi_prov_NE_handle_WSP_headers((U8 **) & prov_buffer_p, (U32*) & prov_length);
        mmi_prov_NE_handle_settings(prov_buffer_p, prov_length);

    }
    else if (mmi_prov_check_if_substring(content_type_p, APPLICATION_X_WAP_PROV_BROWSER_BOOKMARKS) == 0)
    {

        g_prov_instal_stringID = STR_ID_PROV_INSTALL_BOOKMARK;
        g_prov_newsetting_stringID = STR_ID_PROV_NEW_BOOKMARK;
        mmi_prov_NE_handle_WSP_headers((U8 **) & prov_buffer_p, (U32*) & prov_length);
        mmi_prov_NE_handle_settings(prov_buffer_p, prov_length);

    }
    /* } */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_show_new_settings_popup
 * DESCRIPTION
 *  This will take the control to the Idle screen or will show an new settings popup screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_show_new_settings_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TurnOnBacklight(1);
    g_prov_settings_present = 0x01;
    if ((g_idle_context.IsOnIdleScreen || g_idle_context.ScreenSaverRunFlag) && !isInCall())
    {
        PlayMessageArrivalTone();
        /* EntryIdleScreen(); */
        if (g_prov_data_queue_size == 1)
        {
            mmi_prov_show_install_settings_dialog();
        }

    }
    else
    {
        if ((!isInCall()) && (!AlmIsTonePlaying()))
        {
            if (GetActiveScreenId() != SCR_ID_PROV_INSTALL_NEW_SETTINGS &&
                GetActiveScreenId() != SCR_ID_PROV_PROF_NEW_SETTINGS_POPUP)
            {
                //commented by tk
                // PlayMessageArrivalTone();
                // mmi_prov_entry_show_new_settings_popup();
                mmi_msg_entry_new_msg_popup(MSG_NEW_PROV_SETTING);      /* Added by Tk */
            }
            else
            {
                PlayMessageArrivalTone();
            }
        }
    }

    jdd_MemSetActiveModuleID(g_activated_task_id);
    g_activated_task_id = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_go_back_install_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_go_back_install_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* GoBackHistory(); */
    mmi_prov_handle_cancel();
    DeleteScreenIfPresent(SCR_ID_PROV_ABORT_SETTINGS_SETUP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_go_back_profile_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_go_back_profile_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* GoBackHistory(); */
    mmi_prov_handle_back();
    DeleteScreenIfPresent(SCR_ID_PROV_ABORT_SETTINGS_SETUP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_confirm_abort_setting_set_up
 * DESCRIPTION
 *  This displays Confirmation screen for the settings to be installed or cancled
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_confirm_abort_setting_set_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_PROV_ABORT_SETTINGS_SETUP, NULL, mmi_prov_confirm_abort_setting_set_up, NULL);

    ShowCategory164Screen(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        STR_ID_PROV_ABORT_SETTINGS_SETUP,
        IMG_GLOBAL_QUESTION,
        NULL);

    playRequestedTone(WARNING_TONE);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    if ((FALSE == IsScreenPresent(SCR_ID_PROF_HDLR_PROF_LIST)))
    {
        SetLeftSoftkeyFunction(mmi_prov_go_back_install_setting, KEY_EVENT_UP);
    }
    else
    {
        SetLeftSoftkeyFunction(mmi_prov_go_back_profile_screen, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_entry_show_new_settings_popup
 * DESCRIPTION
 *  This is entry function for New Settings popup
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_entry_show_new_settings_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_PROV_PROF_NEW_SETTINGS_POPUP, NULL, mmi_prov_entry_show_new_settings_popup, NULL);
    /* ShowCategory65Screen((PU8) GetString(STR_ID_PROV_NEW_SETTINGS), IMG_ID_PROV_NEW_NOTIFICATION_MSG, NULL); */
    //    ShowCategory65Screen((PU8) GetString(STR_ID_PROV_NEW_SETTINGS), IMG_NEW_MESSAGE_NOTIFICATION_MSG, NULL);
    //      ShowCategory164Screen(STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_CANCEL, IMG_ID_PROV_CANCEL, (U16) STR_ID_PROV_INSTALL_SETTINGS, IMG_GLOBAL_QUESTION, NULL);
    ShowCategory123Screen(
        0,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_CANCEL,
        IMG_ID_PROV_CANCEL,
        STR_ID_PROV_INSTALL_SETTINGS,
        IMG_GLOBAL_QUESTION,
        0);
    /*
     * End key is also disabled. We set GoBackHistory on key up such that KeyUp indication wont be used 
     * * by the overlapped screen. 
     */
    /* SetGroupKeyHandler(NULL,(PU16)PresentAllKeys,(U8) TOTAL_KEYS, (U16) KEY_EVENT_UP); */
    //    SetGroupKeyHandler(GoBackHistory, (PU16) PresentAllKeys, (U8) TOTAL_KEYS, (U16) KEY_EVENT_UP);
    //    SetGroupKeyHandler(NULL, (PU16) PresentAllKeys, (U8) TOTAL_KEYS, (U16) KEY_EVENT_DOWN);

    SetLeftSoftkeyFunction(mmi_prov_oma_handle_install_application, KEY_EVENT_UP);
    /* SetRightSoftkeyFunction(mmi_prov_handle_cancel, KEY_EVENT_UP); */
    SetRightSoftkeyFunction(mmi_prov_confirm_abort_setting_set_up, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_show_install_settings_dialog
 * DESCRIPTION
 *  This displays Confirmation screen for the settings to be installed or cancled
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_show_install_settings_dialog(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
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
#endif /* 0 */ 

    mmi_prov_set_current_instal_stringID();

    EntryNewScreen(SCR_ID_PROV_INSTALL_NEW_SETTINGS, NULL, mmi_prov_show_install_settings_dialog, NULL);

    ShowCategory123Screen(
        0,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_CANCEL,
        IMG_ID_PROV_CANCEL,
        /* STR_ID_PROV_INSTALL_SETTINGS, */ g_prov_instal_stringID,
        IMG_GLOBAL_QUESTION,
        0);
    SetLeftSoftkeyFunction(mmi_prov_handle_ok, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_prov_confirm_abort_setting_set_up, KEY_EVENT_UP);
    SetKeyHandler(mmi_prov_handle_cancel, KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_handle_error_code
 * DESCRIPTION
 *  This function display proper Popup for a particular eror code
 * PARAMETERS
 *  error_code      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_handle_error_code(U16 error_code) /* changes PROV */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 msg_string_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("Inside mmi_prov_handle_error_code");
    mmi_prov_set_current_instal_stringID();
    switch (error_code)
    {
        case PROV_ERR:
            if (g_prov_instal_stringID == STR_ID_PROV_INSTALL_BOOKMARK)
            {
                msg_string_id = STR_ID_PROV_BOOKMARK_INVALID;
            }
            else
            {
                msg_string_id = STR_ID_PROV_INVALID_SETTINGS;
            }
            break;
        case PROV_ERR_UNSUPPORTED_SETTING:
            msg_string_id = STR_ID_PROV_UNSUPPORTED_SETTING;
            break;
        case PROV_MEM_FULL:
            msg_string_id = STR_ID_JATAAYU_JDD_BROWSER_NOT_ENOUGH_MEMORY;
            break;
        default:
            if (g_prov_instal_stringID == STR_ID_PROV_INSTALL_BOOKMARK)
            {
                msg_string_id = STR_ID_PROV_BOOKMARK_INVALID;
            }
            else
            {
                msg_string_id = STR_ID_PROV_INVALID_SETTINGS;
            }
            break;
    }

    DisplayPopupCallBack(
        (PU8) GetString(msg_string_id),
        IMG_GLOBAL_ERROR,
        1,
        PROV_INVALID_SETTINGS_TIMEOUT,
        ERROR_TONE,
        g_prov_timeout_hdlr);

    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "Exit mmi_prov_handle_error_code - ", msg_string_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_handle_ok
 * DESCRIPTION
 *  This deals with the sequences that happen when a user accepts the setings to be installed
 *  in this the wbxml prov. doc is decoded and information is extracted from it
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_handle_ok(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    struct xml XMLInfo = {0, };
    WBXML_HANDLE WBXMLHandle;
    PROV_RETCODE i_ret = PROV_OK;
    prov_queue_data_struct *prov_data_p;
    JC_RETCODE ret = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_prov_setting_type = 0x00; /* dara  reset all the previous values */
    g_prov_setting_type |= PROV_BRS_SETTINGS;
    prov_data_p = prov_data_queue[g_prov_data_queue_current_item];
    if (!prov_data_p->plength)
    {
        i_ret = PROV_MEM_FULL;
    }
    PRINT_INFORMATION("Inside mmi_prov_handle_ok");
    if (i_ret == PROV_OK)
    {
        i_ret = jdi_WBXMLDecode((U8*) prov_data_p->pbuffer, prov_data_p->plength, &XMLInfo, NULL, 0, 0, &WBXMLHandle);
        if (ret == JC_OK)
        {
            i_ret = PROV_OK;
        }
        else if (ret == JC_ERR_MEMORY_ALLOCATION)
        {
            i_ret = PROV_MEM_FULL;
        }
        else
        {
            i_ret = PROV_ERR;
        }
    }
    if (i_ret != PROV_OK)
    {
        g_prov_timeout_hdlr = mmi_prov_handle_error_state_callback;
        PRINT_INFORMATION("Inside mmi_prov_handle_ok, checks WBXMLDecode");
        /* DisplayPopupCallBack(
           (PU8) GetString(STR_ID_PROV_INVALID_SETTINGS),
           IMG_GLOBAL_ERROR,
           1,
           PROV_INVALID_SETTINGS_TIMEOUT,
           ERROR_TONE,
           g_prov_timeout_hdlr); */
        mmi_prov_handle_error_code(i_ret);
        goto error_handle;
    }
    mmi_prov_handle_data_account_mem_free();    /* Added by tk to handle empty APN case */
    mmi_prov_handle_data_account_mem_allocate();
    mmi_prov_handle_profile_mem_allocate();

    if (strcmp(XMLInfo.root->name, NE_ROOT_TAG) == 0)
    {

        g_prov_setting_type |= PROV_NOKIA_SETTINGS;
        PRINT_INFORMATION("Inside mmi_prov_handle_ok, Handlr NE Setting");
        i_ret = mmi_prov_NE_insert_settings_parm(XMLInfo.root);
        if (i_ret == PROV_ERR)
        {
            g_prov_timeout_hdlr = mmi_prov_handle_error_state_callback;
            PRINT_INFORMATION("Inside mmi_prov_handle_ok, checks mmi_prov_NE_insert_settings_parm");
            mmi_prov_handle_error_code(i_ret);  /* changes PROV */
            goto error_handle;
        }

    }
    else if (strcmp(XMLInfo.root->name, OMA_ROOT_TAG) == 0)
    {
        g_prov_setting_type |= PROV_OMA_SETTINGS;
        PRINT_INFORMATION("Inside mmi_prov_handle_ok, Handlr OMA Setting");
        i_ret = mmi_prov_oma_insert_settings_parm(XMLInfo.root);
        if (g_prov_appl_flag == PROV_NO_APPLICATION)
        {
            i_ret = PROV_ERR;
        }
        if (i_ret == PROV_OK)
        {
            mmi_prov_oma_handle_install_application();
            goto error_handle;
        }
        else
        {
            g_prov_timeout_hdlr = mmi_prov_handle_error_state_callback;
            PRINT_INFORMATION("Inside mmi_prov_handle_ok, checks mmi_prov_oma_insert_settings_parm");
            mmi_prov_handle_error_code(i_ret);  /* changes PROV */
            goto error_handle;
        }
    }
    else
    {
        PRINT_INFORMATION("Inside mmi_prov_handle_ok, Handle Error state ");
        mmi_prov_handle_error_state();
        goto error_handle;
    }

    if (g_prov_setting_type & PROV_BOOKMARK_SETTINGS)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "Inside mmi_prov_handle_ok, Handle Bookmark - ", i_ret);
        g_prov_timeout_hdlr = mmi_prov_handle_error_state_callback;
        if (i_ret == PROV_BKM_OK)
        {
            DisplayPopupCallBack(
                (PU8) GetString(STR_ID_PROV_BOOKMARK_STORED),
                IMG_GLOBAL_ACTIVATED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                SUCCESS_TONE,
                g_prov_timeout_hdlr);

        }
        else if (i_ret == PROV_BKM_FULL)
        {
            DisplayPopupCallBack(
                /* (PU8) GetString(STR_ID_PROV_BOOKMARK_FULL), */ (PU8) GetString(STR_ID_BRW_BOOKMARK_FULL),
                IMG_GLOBAL_WARNING,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                WARNING_TONE,
                g_prov_timeout_hdlr);

        }
        else if (i_ret == PROV_BKM_INVALID)
        {
            DisplayPopupCallBack(
                (PU8) GetString(STR_ID_PROV_BOOKMARK_INVALID),
                IMG_GLOBAL_ERROR,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                ERROR_TONE,
                g_prov_timeout_hdlr);
        }
        goto error_handle;
    }

    if ((i_ret == PROV_ERR) || (g_prov_bearer == PROV_INVALID_BEARER))
    {
        g_prov_timeout_hdlr = mmi_prov_handle_error_state_callback;
        DisplayPopupCallBack(
            (PU8) GetString(STR_ID_PROV_INVALID_BEARER),
            IMG_GLOBAL_ERROR,
            1,
            PROV_INVALID_SETTINGS_TIMEOUT,
            ERROR_TONE,
            g_prov_timeout_hdlr);
        goto error_handle;
    }
    else if ((g_prov_setting_type & PROV_MMS_SETTINGS) && (g_prov_bearer == PROV_CSD_BEARER))   /* changes PROV */
    {
        g_prov_timeout_hdlr = mmi_prov_handle_error_state_callback;
        DisplayPopupCallBack(
            (PU8) GetString(STR_ID_PROV_UNSUPPORTED_SETTING),
            IMG_GLOBAL_ERROR,
            1,
            PROV_INVALID_SETTINGS_TIMEOUT,
            ERROR_TONE,
            g_prov_timeout_hdlr);
        goto error_handle;
    }

    mmi_prov_show_profile_list_menu();
  error_handle:

    jdi_XMLFreeTree(&XMLInfo);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_set_current_instal_stringID
 * DESCRIPTION
 *  This API is to set the current instal string id to display.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_set_current_instal_stringID(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (prov_data_queue[g_prov_data_queue_current_item])
    {
        g_prov_instal_stringID = prov_data_queue[g_prov_data_queue_current_item]->instal_stringID;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_handle_get_next_prov_data
 * DESCRIPTION
 *  This API is to remove the present entry from the queue & get the next provisioing doc if any
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_handle_get_next_prov_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_prov_pend_set = 0;
    g_prov_bearer = PROV_INVALID_BEARER;
    g_prov_setting_type |= PROV_BRS_SETTINGS;
    g_ph_cntx.profile_module = PH_PROFILE_NULL;

    if (g_prov_data_queue_size > 0)
    {
        mmi_prov_delete_queue_entry();
    }
    mmi_prov_handle_profile_mem_free();

    if (g_prov_data_queue_size > 0)
    {
        /* Do not merge with the above condition ..its intentional */
        mmi_prov_show_install_settings_dialog();
    }
    else
    {
        /* EntryIdleScreen(); */
        DisplayIdleScreen();
        /* DeleteUptoScrID(IDLE_SCREEN_ID); */
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_handle_error_state
 * DESCRIPTION
 *  It handles the error state if any occured during installing the settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_handle_error_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_prov_handle_get_next_prov_data();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_handle_error_state_callback
 * DESCRIPTION
 *  It handles the error state if any occured during installing the settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_handle_error_state_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* GoBackHistory(); */
    mmi_prov_handle_get_next_prov_data();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_handle_cancel
 * DESCRIPTION
 *  This API is to handle if the RSK cancel is pressed for the new settings arrived confirmation screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_handle_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_prov_handle_get_next_prov_data();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_show_profile_list_menu
 * DESCRIPTION
 *  This API is to get the profile list menu (browser or MMS)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_show_profile_list_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_prov_setting_type & PROV_BRS_SETTINGS) && (!(g_prov_setting_type & PROV_MMS_SETTINGS)))
    {
        mmi_ph_pre_entry_show_profile_list_menu(PH_BROWSER_PROV_PROFILE);
    }
    else if (g_prov_setting_type & PROV_MMS_SETTINGS)
    {
        mmi_ph_pre_entry_show_profile_list_menu(PH_MMS_PROV_PROFILE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_get_dataaccount_data
 * DESCRIPTION
 *  This API gets the CSD or GPRS data account list for the user to select from
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_get_dataaccount_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_prov_pend_set = 1;

    if (g_prov_bearer == PROV_CSD_BEARER)
    {
        mmi_dtcnt_select_account(mmi_ph_prof_callback, g_ph_cntx.ph_title_img_id, DATA_ACCOUNT_BEARER_CSD);
    }
    else if (g_prov_bearer == PROV_GPRS_BEARER)
    {
        mmi_dtcnt_select_account(mmi_ph_prof_callback, g_ph_cntx.ph_title_img_id, DATA_ACCOUNT_BEARER_GPRS);
    }
}

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
#ifdef __MMI_GPRS_FEATURES__
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_GPRS_FEATURES__ */ 
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
/* under construction !*/
/* under construction !*/
#ifdef __MMI_GPRS_FEATURES__
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
#endif /* __MMI_GPRS_FEATURES__ */ 
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

#ifdef __MMI_GPRS_FEATURES__
/*****************************************************************************
 * FUNCTION
 *  mmi_prov_prof_save_gprs_data_acct
 * DESCRIPTION
 *  This is API for sending the Set request to L4 for the selected GPRS data acount
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_prof_save_gprs_data_acct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_prov_set_gprs_req();
}
#endif /* __MMI_GPRS_FEATURES__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_prof_save_csd_data_acct
 * DESCRIPTION
 *  This is API for sending the Set request to L4 for the selected CSD data acount
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_prof_save_csd_data_acct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_prov_set_csd_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_handle_back
 * DESCRIPTION
 *  To handle the BACK key pressed during the time of installation of received prov. settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_handle_back(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_prov_handle_data_account_mem_free();

    if (g_prov_appl_flag > 0)
    {
        mmi_prov_oma_check_pending_application();
    }
    else
    {
        mmi_prov_handle_get_next_prov_data();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_add_to_queue
 * DESCRIPTION
 *  This Add's the new settings received into the queue to be processed later on.
 * PARAMETERS
 *  prov_buffer_p       [IN]        Provisioing data buffer
 *  prov_length         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_add_to_queue(S8 *prov_buffer_p, U32 prov_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_prov_data_queue_last_item >= PROV_MAX_NBR_DOCUMENTS)
    {
        g_prov_data_queue_last_item = 0;
    }

    prov_data_queue[g_prov_data_queue_last_item] =
        (prov_queue_data_struct*) jdd_MemAlloc(sizeof(prov_queue_data_struct), 1);
    ASSERT(prov_data_queue[g_prov_data_queue_last_item]);
    /* prov_data_queue[g_prov_data_queue_last_item]->pbuffer = jdd_MemAlloc(prov_length, 1); */
    prov_data_queue[g_prov_data_queue_last_item]->pbuffer = prov_buffer_p;

    /* memcpy(prov_data_queue[g_prov_data_queue_last_item]->pbuffer, prov_buffer_p, prov_length); */
    prov_data_queue[g_prov_data_queue_last_item]->plength = prov_length;
    prov_data_queue[g_prov_data_queue_last_item]->instal_stringID = g_prov_instal_stringID;

    g_prov_data_queue_last_item++;
    g_prov_data_queue_size++;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_delete_queue_entry
 * DESCRIPTION
 *  Deletes the current queue entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_delete_queue_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (prov_data_queue[g_prov_data_queue_current_item]->pbuffer)
    {
        jdd_MemFree(prov_data_queue[g_prov_data_queue_current_item]->pbuffer);
        prov_data_queue[g_prov_data_queue_current_item]->pbuffer = NULL;
    }
    if (prov_data_queue[g_prov_data_queue_current_item])
    {
        jdd_MemFree(prov_data_queue[g_prov_data_queue_current_item]);
        prov_data_queue[g_prov_data_queue_current_item] = NULL;
    }

    ++g_prov_data_queue_current_item;
    --g_prov_data_queue_size;
    if (g_prov_data_queue_current_item >= PROV_MAX_NBR_DOCUMENTS)
    {
        g_prov_data_queue_current_item = 0;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_handle_terminate
 * DESCRIPTION
 *  THis API terminates the Provisoining module
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_handle_terminate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (g_prov_data_queue_size > 0)
    {
        if (prov_data_queue[g_prov_data_queue_current_item]->pbuffer)
        {
            jdd_MemFree(prov_data_queue[g_prov_data_queue_current_item]->pbuffer);
            prov_data_queue[g_prov_data_queue_current_item]->pbuffer = NULL;
        }
        if (prov_data_queue[g_prov_data_queue_current_item])
        {
            jdd_MemFree(prov_data_queue[g_prov_data_queue_current_item]);
            prov_data_queue[g_prov_data_queue_current_item] = NULL;
        }

        g_prov_data_queue_size--;
        g_prov_data_queue_current_item++;
        if (g_prov_data_queue_current_item >= PROV_MAX_NBR_DOCUMENTS)
        {
            g_prov_data_queue_current_item = 0;
        }
    }

    g_prov_bearer = PROV_INVALID_BEARER;
    g_prov_setting_type |= PROV_BRS_SETTINGS;

    mmi_prov_handle_data_account_mem_free();
    mmi_prov_handle_profile_mem_free();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_hilite_data_account
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_hilite_data_account(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_prov_data_account_index = (U8) index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_check_and_install_new_settings
 * DESCRIPTION
 *  THis Checks if there is any provisioning data availbale to be installed
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_prov_check_and_install_new_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_prov_pend_set)
    {
        mmi_prov_handle_get_next_prov_data();
    }

    if (g_prov_settings_present)
    {
        if (g_prov_data_queue_size > 0)
        {
            /* mmi_prov_show_install_settings_dialog(); */
            return 1;
        }
        else
        {
            g_prov_settings_present = 0x00;
            return 0;
        }
    }
    else
    {
        return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_check_if_substring
 * DESCRIPTION
 *  This function checks whether the sub-string starts with the given string.
 *  on an error it returns -1 else returns 0.
 * PARAMETERS
 *  string_p            [IN]        The main string
 *  sub_string_p        [IN]        The sub string to be checked
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_prov_check_if_substring(const S8 *string_p, const S8 *sub_string_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 buf_len;
    S32 start_len;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (string_p == NULL)
    {
        return -1;
    }
    if (sub_string_p == NULL)
    {
        return -1;
    }

    buf_len = strlen(string_p);
    start_len = strlen(sub_string_p);

    if (start_len > buf_len)
    {
        return -1;
    }
    for (i = 0; i < start_len; i++)
    {
        if (sub_string_p[i] != string_p[i])
        {
            return -1;
        }
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_set_csd_req
 * DESCRIPTION
 *  This API send an request to the L4 to set the CSD data filled for the selected index
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_set_csd_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    U8 ref_count;
    U16 msg_len;

    mmi_cc_set_csd_profile_req_struct *set_csd_req_p = NULL, *set_csd_req_p1 = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_ph_cntx.ph_dataaccount_index >= MAX_DATA_ACCOUNT_GSM_LIMIT)
    {
        return;
    }

    if (g_prov_setting_type & PROV_NOKIA_SETTINGS)
    {
        if (g_prov_set_csd_req_p != NULL)
        {
            g_prov_set_csd_req_p->csd_module = 0;
            g_prov_set_csd_req_p->auth_type = 0;
            g_prov_set_csd_req_p->prof_id = g_ph_cntx.profile_display_p->data_account;

            if (g_prov_profile_name_p != NULL)
            {
                U32 len = 0;

                len = strlen((S8*) g_prov_profile_name_p);
                if (len >= PROV_MAX_DATA_ACCOUNT_NAME_LEN)
                {
                    len = PROV_MAX_DATA_ACCOUNT_NAME_LEN - 1;
                }
                memcpy((S8*) g_prov_set_csd_req_p->name.name, (S8*) g_prov_profile_name_p, len);

                g_prov_set_csd_req_p->name.name[len] = '\0';
                g_prov_set_csd_req_p->name.name_dcs = PHB_ASCII;
                g_prov_set_csd_req_p->name.name_length = len;
            }
        }
    }
    else if (g_prov_setting_type & PROV_OMA_SETTINGS)
    {
        set_csd_req_p = jdd_MemAlloc(sizeof(mmi_cc_set_csd_profile_req_struct), 1);
        set_csd_req_p->prof_id = g_ph_cntx.profile_display_p->data_account;
        if (g_prov_dataAccountData_p != NULL)
        {
            mmi_prov_oma_fill_csd_data_account_info(g_prov_dataAccountData_p, &set_csd_req_p);
        }
        else
        {
            PRINT_INFORMATION_2(MMI_TRACE_INFO,
                                 " JProvWap.c ........No Valid Data Account(NAPDEF) Available in the OMA Provisionig setting\n");
            if (set_csd_req_p)
            {
                jdd_MemFree(set_csd_req_p);
                set_csd_req_p = NULL;
            }
            return;
        }
    }

    set_csd_req_p1 = (mmi_cc_set_csd_profile_req_struct*)
        OslConstructDataPtr(sizeof(mmi_cc_set_csd_profile_req_struct));

    ref_count = set_csd_req_p1->ref_count;
    msg_len = set_csd_req_p1->msg_len;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_MMI_CC_SET_CSD_PROFILE_REQ;
    if (g_prov_setting_type & PROV_NOKIA_SETTINGS)
    {
        memcpy((void*)set_csd_req_p1, (void*)g_prov_set_csd_req_p, sizeof(mmi_cc_set_csd_profile_req_struct));
        set_csd_req_p1->ref_count = ref_count;
        set_csd_req_p1->msg_len = msg_len;
        Message.oslDataPtr = (oslParaType*) set_csd_req_p1;
    }
    else if (g_prov_setting_type & PROV_OMA_SETTINGS)
    {
        memcpy((void*)set_csd_req_p1, (void*)set_csd_req_p, sizeof(mmi_cc_set_csd_profile_req_struct));
        set_csd_req_p1->ref_count = ref_count;
        set_csd_req_p1->msg_len = msg_len;
        Message.oslDataPtr = (oslParaType*) set_csd_req_p1;
        if (set_csd_req_p)
        {
            jdd_MemFree(set_csd_req_p);
            set_csd_req_p = NULL;
        }

    }
    Message.oslPeerBuffPtr = NULL;
    SetProtocolEventHandler(mmi_prov_set_csd_rsp, PRT_MMI_CC_SET_CSD_PROFILE_RSP);
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_set_csd_rsp
 * DESCRIPTION
 *  This API handles the RSP sent by L4 for Set CSD req .
 *  Done popup is shown if rsp is positive
 * PARAMETERS
 *  info_p      [IN]        Rsp obtained from L4
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_set_csd_rsp(void *info_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_cc_set_csd_profile_rsp_struct *localPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_ph_cntx.ph_initialised)
    {
        return;
    }
    localPtr = (mmi_cc_set_csd_profile_rsp_struct*) info_p;

    g_prov_timeout_hdlr = mmi_prov_get_next_appl_or_new_doc_callback;

    if (localPtr->result == KAL_TRUE)
    {
        mmi_prov_handle_data_account_set_rsp((U8) PROV_CSD_BEARER);
    }
    else
    {
        DisplayPopupCallBack(
            (PU8) GetString(STR_GLOBAL_NOT_DONE),
            IMG_GLOBAL_UNFINISHED,
            1,
            PROV_DATA_ACCOUNT_NOTIFY_TIMEOUT,
            ERROR_TONE,
            g_prov_timeout_hdlr);

        DeleteUptoScrID(IDLE_SCREEN_ID);
    }

}

#ifdef __MMI_GPRS_FEATURES__
/*****************************************************************************
 * FUNCTION
 *  mmi_prov_set_gprs_req
 * DESCRIPTION
 *  This API send an request to the L4 to set the GPRS data filled for the selected index
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_set_gprs_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    mmi_ps_set_gprs_data_account_req_struct *set_gprs_req_p = NULL, *set_gprs_req_p1 = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_ph_cntx.ph_dataaccount_index >= MAX_DATA_ACCOUNT_GPRS_LIMIT)
    {
        return;
    }
    if (g_prov_setting_type & PROV_NOKIA_SETTINGS)
    {
        if (g_prov_set_gprs_req_p != NULL)
        {
            /* Added by tk to handle empty APN case */
            if (g_prov_set_gprs_req_p->gprs_account.apn_length == 0)
            {
                g_prov_timeout_hdlr = mmi_prov_get_next_appl_or_new_doc_callback;
                mmi_prov_handle_data_account_set_rsp((U8) PROV_GPRS_BEARER);
                return;
            }
            /* end */
            g_prov_set_gprs_req_p->gprs_account.context_id =
                g_ph_cntx.profile_display_p->data_account - MAX_DATA_ACCOUNT_GSM_LIMIT + 1;
            if (g_prov_profile_name_p != NULL)
            {
                U32 len = 0;

                len = strlen((S8*) g_prov_profile_name_p);
                if (len >= PROV_MAX_GPRS_DATAACCOUNT_NAME)
                {
                    len = PROV_MAX_GPRS_DATAACCOUNT_NAME - 1;
                }
            #if 0   /* added by tk */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif /* 0 */ 

                memcpy((S8*) g_prov_set_gprs_req_p->gprs_account.name, (S8*) g_prov_profile_name_p, len);

                g_prov_set_gprs_req_p->gprs_account.name[len] = '\0';
                g_prov_set_gprs_req_p->gprs_account.name_dcs = PHB_ASCII;
                g_prov_set_gprs_req_p->gprs_account.name_length = len;
            }
        }
    }
    else if (g_prov_setting_type & PROV_OMA_SETTINGS)
    {
        set_gprs_req_p = jdd_MemAlloc(sizeof(mmi_ps_set_gprs_data_account_req_struct), 1);

        set_gprs_req_p->gprs_account.context_id =
            g_ph_cntx.profile_display_p->data_account - MAX_DATA_ACCOUNT_GSM_LIMIT + 1;
        if (g_prov_dataAccountData_p != NULL)
        {
            mmi_prov_oma_fill_gprs_data_account_info(g_prov_dataAccountData_p, &set_gprs_req_p);
        }
        else
        {
            PRINT_INFORMATION_2(MMI_TRACE_INFO,
                                 " JProvWap.c ........No Valid Data Account(NAPDEF) Available in the OMA Provisionig setting\n");
            if (set_gprs_req_p)
            {
                jdd_MemFree(set_gprs_req_p);
                set_gprs_req_p = NULL;
            }
            return;
        }
        /* Added by tk to handle empty APN case */
        if (set_gprs_req_p->gprs_account.apn_length == 0)
        {
            g_prov_timeout_hdlr = mmi_prov_get_next_appl_or_new_doc_callback;
            mmi_prov_handle_data_account_set_rsp((U8) PROV_GPRS_BEARER);
            if (set_gprs_req_p)
            {
                jdd_MemFree(set_gprs_req_p);
                set_gprs_req_p = NULL;
            }
            return;
        }
        /* end */
    }
    set_gprs_req_p1 = (mmi_ps_set_gprs_data_account_req_struct*)
        OslConstructDataPtr(sizeof(mmi_ps_set_gprs_data_account_req_struct));

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_MMI_PS_SET_GPRS_DATA_ACCOUNT_REQ;
    if (g_prov_setting_type & PROV_NOKIA_SETTINGS)
    {
        memcpy(
            (void*)&set_gprs_req_p1->gprs_account,
            (void*)&g_prov_set_gprs_req_p->gprs_account,
            sizeof(g_prov_set_gprs_req_p->gprs_account));
        Message.oslDataPtr = (oslParaType*) set_gprs_req_p1;
    }
    else if (g_prov_setting_type & PROV_OMA_SETTINGS)
    {
        memcpy(
            (void*)&set_gprs_req_p1->gprs_account,
            (void*)&set_gprs_req_p->gprs_account,
            sizeof(set_gprs_req_p->gprs_account));
        Message.oslDataPtr = (oslParaType*) set_gprs_req_p1;
        if (set_gprs_req_p)
        {
            jdd_MemFree(set_gprs_req_p);
            set_gprs_req_p = NULL;
        }
    }

    Message.oslPeerBuffPtr = NULL;
    SetProtocolEventHandler(mmi_prov_set_gprs_rsp, PRT_MMI_PS_SET_GPRS_DATA_ACCOUNT_RSP);
    OslMsgSendExtQueue(&Message);
}
#endif /* __MMI_GPRS_FEATURES__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_set_gprs_rsp
 * DESCRIPTION
 *  This API handles the RSP sent by L4 for Set GPRS req .
 *  Done popup is shown if rsp is positive
 * PARAMETERS
 *  info_p      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_set_gprs_rsp(void *info_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

#ifdef __MMI_GPRS_FEATURES__

    mmi_ps_set_gprs_data_account_rsp_struct *localPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_ph_cntx.ph_initialised)
    {
        return;
    }

    localPtr = (mmi_ps_set_gprs_data_account_rsp_struct*) info_p;

    g_prov_timeout_hdlr = mmi_prov_get_next_appl_or_new_doc_callback;

    if (localPtr->result == KAL_TRUE)
    {
        mmi_prov_handle_data_account_set_rsp((U8) PROV_GPRS_BEARER);
    }
    else
    {
        DisplayPopupCallBack(
            (PU8) GetString(STR_GLOBAL_NOT_DONE),
            IMG_GLOBAL_UNFINISHED,
            1,
            PROV_DATA_ACCOUNT_NOTIFY_TIMEOUT,
            ERROR_TONE,
            g_prov_timeout_hdlr);

        DeleteUptoScrID(IDLE_SCREEN_ID);
    }

#endif /* __MMI_GPRS_FEATURES__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_handle_data_account_set_rsp
 * DESCRIPTION
 *  This is general API to handle the data account rsp for both CSD & GPRS Data Account
 *  Profile data is updated into NVRAM & done popup is shown.
 * PARAMETERS
 *  data_account        [IN]        CSD or GPRS
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_handle_data_account_set_rsp(U8 data_account)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_prov_setting_type & PROV_NOKIA_SETTINGS)
    {
        if (g_prov_setting_type & PROV_BRS_SETTINGS)
        {
            if ((strlen((S8*) g_ph_cntx.ph_wap_profile_p->homepage_url) == 0)
                && (strlen((S8*) g_ph_cntx.ph_mms_profile_p->mmsc_url) == 0))
            {
                S8 default_url[] = "http://";

                strcpy((S8*) g_ph_cntx.ph_wap_profile_p->homepage_url, default_url);
            }
            mmi_ph_update_prov_nvram_wap_profile();
        }
        else if (g_prov_setting_type & PROV_MMS_SETTINGS)
        {
            mmi_ph_update_prov_nvram_mms_profile();
        }
    }
    else if (g_prov_setting_type & PROV_OMA_SETTINGS)
    {
        if ((g_prov_setting_type & PROV_BRS_SETTINGS) && (g_prov_appl_flag & PROV_BROWSER_APPLICATION))
        {
            mmi_ph_update_prov_nvram_wap_profile();
        }
        else if ((g_prov_setting_type & PROV_MMS_SETTINGS) && (g_prov_appl_flag & PROV_MMS_APPLICATION))
        {
            mmi_ph_update_prov_nvram_mms_profile();
        }
    }
    DisplayPopupCallBack(
        (PU8) GetString(STR_GLOBAL_DONE),
        IMG_GLOBAL_ACTIVATED,
        1,
        PROV_DATA_ACCOUNT_NOTIFY_TIMEOUT,
        SUCCESS_TONE,
        g_prov_timeout_hdlr);

    DeleteUptoScrID(IDLE_SCREEN_ID);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_handle_proxy_ip
 * DESCRIPTION
 *  This function handles the proxy IP when received in the settings
 * PARAMETERS
 *  attr_p      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_handle_proxy_ip(ATTRIBUTE *attr_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 proxy_ip[MAX_PART_IP_ADDRESS];
    S8 parm_element[PROV_MIN_SIZE_REQ + 1];
    PROV_RETCODE i_ret = PROV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*  if (strcmp(attr_p->name, PROV_VALUE) == 0) MAUI_00555503 */
    if ((mmi_prov_check_not_null((void*)attr_p)) && (strcmp(attr_p->name, PROV_VALUE) == 0))   /* MAUI_00555503 */
    {
        mmi_ucs2_to_asc(parm_element, (S8*) attr_p->value);
        i_ret = mmi_prov_convert_ip_string_to_array(parm_element, proxy_ip);
        if (i_ret == PROV_ERR)
        {
            memset(proxy_ip, 0, MAX_PART_IP_ADDRESS);
        }
        memcpy(g_ph_cntx.ph_wap_profile_p->proxy_ip, proxy_ip, MAX_PART_IP_ADDRESS);
        memcpy(g_ph_cntx.ph_mms_profile_p->proxy_ip, proxy_ip, MAX_PART_IP_ADDRESS);

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_handle_nap_auth_type
 * DESCRIPTION
 *  This function handles the different nap authentication types
 *  received in the settings
 * PARAMETERS
 *  attr_p      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_handle_nap_auth_type(ATTRIBUTE *attr_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S8 parm_element[PROV_MIN_SIZE_REQ + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*  if (strcmp(attr_p->name, PROV_VALUE) == 0) MAUI_00555503 */
    if ((mmi_prov_check_not_null((void*)attr_p)) && (strcmp(attr_p->name, PROV_VALUE) == 0))   /* MAUI_00555503 */
    {
        mmi_ucs2_to_asc(parm_element, (S8*) attr_p->value);

        if (g_prov_bearer == PROV_CSD_BEARER)
        {
            if (strcmp(parm_element, PAP) == 0)
            {
                if (g_prov_set_csd_req_p)
                {
                    g_prov_set_csd_req_p->auth_type = PROV_AUTHTYPE_PAP;
                }
            }
            else if (strcmp(parm_element, CHAP) == 0)
            {
                if (g_prov_set_csd_req_p)
                {
                    g_prov_set_csd_req_p->auth_type = PROV_AUTHTYPE_CHAP;
                }
            }
        }
    #ifdef __MMI_GPRS_FEATURES__
        else if (g_prov_bearer == PROV_GPRS_BEARER)
        {
            if (strcmp(parm_element, PAP) == 0)
            {
                if (g_prov_set_gprs_req_p)
                {
                    g_prov_set_gprs_req_p->gprs_account.authentication_type = PROV_AUTHTYPE_PAP;
                }
            }
            else if (strcmp(parm_element, CHAP) == 0)
            {
                if (g_prov_set_gprs_req_p)
                {
                    g_prov_set_gprs_req_p->gprs_account.authentication_type = PROV_AUTHTYPE_CHAP;
                }
            }
        }
    #endif /* __MMI_GPRS_FEATURES__ */ 
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_handle_nap_auth_name
 * DESCRIPTION
 *  This function handles the NAP name parameter received in the settings
 * PARAMETERS
 *  attr_p      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_handle_nap_auth_name(ATTRIBUTE *attr_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*  if (strcmp(attr_p->name, PROV_VALUE) == 0) MAUI_00555503 */
    if ((mmi_prov_check_not_null((void*)attr_p)) && (strcmp(attr_p->name, PROV_VALUE) == 0))   /* MAUI_00555503 */
    {
        len = mmi_ucs2strlen((S8*) attr_p->value);
        if (g_prov_bearer == PROV_CSD_BEARER)
        {
            if (g_prov_set_csd_req_p)
            {
                if (len >= PROV_MAX_USER_LEN)
                {
                    len = PROV_MAX_USER_LEN - 1;
                }
                mmi_ucs2_n_to_asc((S8*) g_prov_set_csd_req_p->user_id, (S8*) attr_p->value, len * ENCODING_LENGTH);
                g_prov_set_csd_req_p->user_id[len] = '\0';
            }
        }
    #ifdef __MMI_GPRS_FEATURES__

        else if (g_prov_bearer == PROV_GPRS_BEARER)
        {
            if (g_prov_set_gprs_req_p)
            {
                if (len >= PROV_MAX_GPRS_USERNAME)
                {
                    len = PROV_MAX_GPRS_USERNAME - 1;
                }
                mmi_ucs2_n_to_asc(
                    (S8*) g_prov_set_gprs_req_p->gprs_account.user_name,
                    (S8*) attr_p->value,
                    len * ENCODING_LENGTH);
                g_prov_set_gprs_req_p->gprs_account.user_name[len] = '\0';
            }
        }
    #endif /* __MMI_GPRS_FEATURES__ */ 
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_handle_nap_auth_pw
 * DESCRIPTION
 *  This function handles the NAP password received in the settings
 * PARAMETERS
 *  attr_p      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_handle_nap_auth_pw(ATTRIBUTE *attr_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*  if (strcmp(attr_p->name, PROV_VALUE) == 0) MAUI_00555503 */
    if ((mmi_prov_check_not_null((void*)attr_p)) && (strcmp(attr_p->name, PROV_VALUE) == 0))   /* MAUI_00555503 */
    {
        len = mmi_ucs2strlen((S8*) attr_p->value);
        if (g_prov_bearer == PROV_CSD_BEARER)
        {
            if (g_prov_set_csd_req_p)
            {
                if (len >= PROV_MAX_PASSWD_LEN)
                {
                    len = PROV_MAX_PASSWD_LEN - 1;
                }
                mmi_ucs2_n_to_asc((S8*) g_prov_set_csd_req_p->passwd, (S8*) attr_p->value, len * ENCODING_LENGTH);
                g_prov_set_csd_req_p->passwd[len] = '\0';
            }
        }
    #ifdef __MMI_GPRS_FEATURES__

        else if (g_prov_bearer == PROV_GPRS_BEARER)
        {

            if (len >= PROV_MAX_GPRS_USERPASSWD)
            {
                len = PROV_MAX_GPRS_USERPASSWD - 1;
            }

            if (g_prov_set_gprs_req_p)
            {
                mmi_ucs2_n_to_asc(
                    (S8*) g_prov_set_gprs_req_p->gprs_account.password,
                    (S8*) attr_p->value,
                    len * ENCODING_LENGTH);
                g_prov_set_gprs_req_p->gprs_account.password[len] = '\0';
            }
        }
    #endif /* __MMI_GPRS_FEATURES__ */ 
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_handle_profile_name
 * DESCRIPTION
 *  This function handles the profile name parameter received in the settings
 * PARAMETERS
 *  attr_p      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_handle_profile_name(ATTRIBUTE *attr_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_prov_profile_name_p = (U8*) jdd_MemAlloc(PROV_PROFILE_PROFILE_NAME_LEN + 1, 1);

    /*  if (strcmp(attr_p->name, PROV_VALUE) == 0) MAUI_00555503 */
    if ((mmi_prov_check_not_null((void*)attr_p)) && (strcmp(attr_p->name, PROV_VALUE) == 0))   /* MAUI_00555503 */
    {
        if (GetUCS2Flag((S8*) attr_p->value))
        {
            mmi_ucs2_to_asc((S8*) g_prov_profile_name_p, (S8*) GetString(STR_ID_PROF_HDLR_DEFAULT_PROFILE_NAME));
        }
        else
        {
            len = mmi_ucs2strlen((S8*) attr_p->value);
            if (len >= PROV_PROFILE_PROFILE_NAME_LEN)
            {
                len = PROV_PROFILE_PROFILE_NAME_LEN - 1;
            }
            mmi_ucs2_n_to_asc((S8*) g_prov_profile_name_p, (S8*) attr_p->value, len * ENCODING_LENGTH);
            g_prov_profile_name_p[len] = '\0';
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_handle_homepage_url
 * DESCRIPTION
 *  This function handles homepage url received in the settings
 * PARAMETERS
 *  attr_p      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_handle_homepage_url(ATTRIBUTE *attr_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*  if (strcmp(attr_p->name, PROV_VALUE) == 0) MAUI_00555503 */
    if ((mmi_prov_check_not_null((void*)attr_p)) && (strcmp(attr_p->name, PROV_VALUE) == 0))   /* MAUI_00555503 */
    {
        len = mmi_ucs2strlen((S8*) attr_p->value);
        if (len >= PROV_PROFILE_HOMEPAGE_URL_LEN)
        {
            len = PROV_PROFILE_HOMEPAGE_URL_LEN - 1;
        }
        mmi_ucs2_n_to_asc((S8*) g_ph_cntx.ph_wap_profile_p->homepage_url, (S8*) attr_p->value, len * ENCODING_LENGTH);
        g_ph_cntx.ph_wap_profile_p->homepage_url[len] = '\0';

        if (jdi_isValidUrl((JC_UINT8*) g_ph_cntx.ph_wap_profile_p->homepage_url))
        {
            if (mmi_prov_check_if_substring((PS8) g_ph_cntx.ph_wap_profile_p->homepage_url, (PS8) "http://") != 0x00)
            {
                S8 homepage[PROV_PROFILE_HOMEPAGE_URL_LEN + 10] = "http://";

                strcat(homepage, (PS8) g_ph_cntx.ph_wap_profile_p->homepage_url);
                memset(g_ph_cntx.ph_wap_profile_p->homepage_url, 0, PROV_PROFILE_HOMEPAGE_URL_LEN);
                len = strlen(homepage);
                if (len >= PROV_PROFILE_HOMEPAGE_URL_LEN)
                {
                    len = PROV_PROFILE_HOMEPAGE_URL_LEN - 1;
                }
                memcpy(g_ph_cntx.ph_wap_profile_p->homepage_url, homepage, len);
                g_ph_cntx.ph_wap_profile_p->homepage_url[len] = '\0';
            }
        }
        else
        {
            S8 *default_url = "http://";

            memset(g_ph_cntx.ph_wap_profile_p->homepage_url, 0, PROV_PROFILE_HOMEPAGE_URL_LEN);
            strcpy((PS8) g_ph_cntx.ph_wap_profile_p->homepage_url, default_url);
        }

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_handle_mmsc_url
 * DESCRIPTION
 *  This function handles homepage url received in the settings
 * PARAMETERS
 *  attr_p      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_handle_mmsc_url(ATTRIBUTE *attr_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*  if (strcmp(attr_p->name, PROV_VALUE) == 0) MAUI_00555503 */
    if ((mmi_prov_check_not_null((void*)attr_p)) && (strcmp(attr_p->name, PROV_VALUE) == 0))   /* MAUI_00555503 */
    {
        len = mmi_ucs2strlen((S8*) attr_p->value);
        if (len >= PROV_PROFILE_MMSC_URL_LEN)
        {
            len = PROV_PROFILE_MMSC_URL_LEN - 1;
        }

        mmi_ucs2_n_to_asc((S8*) g_ph_cntx.ph_mms_profile_p->mmsc_url, (S8*) attr_p->value, len * ENCODING_LENGTH);
        g_ph_cntx.ph_mms_profile_p->mmsc_url[len] = '\0';

        if (jdi_isValidUrl((JC_UINT8*) g_ph_cntx.ph_mms_profile_p->mmsc_url))
        {
            if (mmi_prov_check_if_substring((PS8) g_ph_cntx.ph_mms_profile_p->mmsc_url, (PS8) "http://") != 0x00)
            {
                S8 homepage[PROV_PROFILE_MMSC_URL_LEN + 10] = "http://";

                strcat(homepage, (PS8) g_ph_cntx.ph_mms_profile_p->mmsc_url);
                memset(g_ph_cntx.ph_mms_profile_p->mmsc_url, 0, PROV_PROFILE_MMSC_URL_LEN);
                len = strlen(homepage);
                if (len >= PROV_PROFILE_MMSC_URL_LEN)
                {
                    len = PROV_PROFILE_MMSC_URL_LEN - 1;
                }
                memcpy(g_ph_cntx.ph_mms_profile_p->mmsc_url, homepage, len);
                g_ph_cntx.ph_mms_profile_p->mmsc_url[len] = '\0';
            }
        }
        else
        {
            S8 *default_url = "http://";

            memset(g_ph_cntx.ph_mms_profile_p->mmsc_url, 0, PROV_PROFILE_MMSC_URL_LEN);
            strcpy((PS8) g_ph_cntx.ph_mms_profile_p->mmsc_url, default_url);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_handle_data_account_mem_allocate
 * DESCRIPTION
 *  This allocates memory for the CSD & GPRS data account set request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_handle_data_account_mem_allocate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_prov_set_csd_req_p == NULL)
    {
        g_prov_set_csd_req_p = (mmi_cc_set_csd_profile_req_struct*)
            jdd_MemAlloc(sizeof(mmi_cc_set_csd_profile_req_struct), 1);
    }
#ifdef __MMI_GPRS_FEATURES__
    if (g_prov_set_gprs_req_p == NULL)
    {
        g_prov_set_gprs_req_p = (mmi_ps_set_gprs_data_account_req_struct*)
            jdd_MemAlloc(sizeof(mmi_ps_set_gprs_data_account_req_struct), 1);
    }
#endif /* __MMI_GPRS_FEATURES__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_handle_profile_mem_allocate
 * DESCRIPTION
 *  This allocates dynamic memory to the WAP & MMS profiles
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_handle_profile_mem_allocate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_ph_cntx.ph_wap_profile_p == NULL)
    {
        g_ph_cntx.ph_wap_profile_p =
            (nvram_wap_profile_content_struct*) jdd_MemAlloc(NVRAM_EF_WAP_PROFILE_CONTENT_SIZE, 1);
    }
    if (g_ph_cntx.ph_mms_profile_p == NULL)
    {
        g_ph_cntx.ph_mms_profile_p =
            (nvram_mms_profile_content_struct*) jdd_MemAlloc(NVRAM_EF_MMS_PROFILE_CONTENT_SIZE, 1);
    }
    g_ph_cntx.ph_initialised = MMI_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_handle_profile_mem_free
 * DESCRIPTION
 *  This Frees the memory used for the wap & MMS profile structs
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_handle_profile_mem_free(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_ph_cntx.ph_wap_profile_p != NULL)
    {
        jdd_MemFree(g_ph_cntx.ph_wap_profile_p);
        g_ph_cntx.ph_wap_profile_p = NULL;

    }
    if (g_ph_cntx.ph_mms_profile_p == NULL)
    {
        jdd_MemFree(g_ph_cntx.ph_mms_profile_p);
        g_ph_cntx.ph_mms_profile_p = NULL;
    }
    g_ph_cntx.ph_initialised = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_handle_data_account_mem_free
 * DESCRIPTION
 *  This frees the memory used by the CSD & GPRS data account req. structs
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_handle_data_account_mem_free(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_prov_set_csd_req_p != NULL)
    {
        jdd_MemFree(g_prov_set_csd_req_p);
        g_prov_set_csd_req_p = NULL;
    }
#ifdef __MMI_GPRS_FEATURES__
    if (g_prov_set_gprs_req_p != NULL)
    {
        jdd_MemFree(g_prov_set_gprs_req_p);
        g_prov_set_gprs_req_p = NULL;
    }
#endif /* __MMI_GPRS_FEATURES__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_get_next_appl_or_new_doc_callback
 * DESCRIPTION
 *  Checks if some application settings are pending or any other prov. doc is available
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_get_next_appl_or_new_doc_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* GoBackHistory(); */

    if (g_prov_appl_flag > 0)
    {
        mmi_prov_oma_check_pending_application();
    }
    else
    {
        mmi_prov_handle_get_next_prov_data();
    }

}


/* Added for MAUI_00555503 starts */
/*****************************************************************************
 * FUNCTION
 *  mmi_prov_check_not_null
 * DESCRIPTION
 *  Checks if the input attribute / parameter is NULL or not.
 * PARAMETERS
 *  inp_p       [IN]        
 * RETURNS
 *  JC_BOOLEAN
 *****************************************************************************/
MMI_BOOL mmi_prov_check_not_null(void *inp_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return ((inp_p == NULL) ? MMI_FALSE : MMI_TRUE) ;
}
/* MAUI_00555503 Ends */
#endif /* __MMI_JATAAYU_CCA_SUPPORT__ */ 

#endif /* defined (JATAAYU_SUPPORT) && (defined (WAP_SUPPORT) || (defined (MMS_SUPPORT))) */ 

#endif /* _JPROVWAP_C */ 

