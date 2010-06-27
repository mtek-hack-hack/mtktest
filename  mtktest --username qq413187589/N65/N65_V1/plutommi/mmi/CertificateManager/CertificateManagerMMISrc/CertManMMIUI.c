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
*******************************************************************************/
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
 *
 * Filename:
 * ---------
 *  CertManMMIUI.c
 *
 * Project:
 * --------
 *  Certificate Manager
 *
 * Description:
 * ------------
 *   This file is intends for handling UI of Certificate Manager
 *
 * Author:
 * ------------
 * -------
 *
 ********************************************************************************/
/* ShriKant */
#ifdef __CERTMAN_SUPPORT__

#include "PixtelDataTypes.h"
#include "wgui_categories_inputs.h"
#include "CertManMMIGProts.h"
#include "CertManMMIResDef.h"
#include "CertManMMITypes.h"
#include "CertManMMIProts.h"
#include "Ucs2prot.h"
#include "CommonScreens.h"

#ifdef __DRM_SUPPORT__
#include "drm_def.h"
#endif 
#include "FileManagerGProt.h"   /* file path */
#include "FileManagerDef.h"
#include "FileMgr.h"
#include "FileMgrStruct.h"

extern fmgr_context_struct *fmgr_p;


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_set_protocol_events
 * DESCRIPTION
 *  function to et protocol handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_set_protocol_events(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_certman_install_certificates_ind_handler, MSG_ID_MMI_CERTMAN_INSTALL_CERT_IND);
    SetProtocolEventHandler(mmi_certman_launch_certificates_ind_handler, MSG_ID_MMI_CERTMAN_LAUNCH_CERT_IND);
    SetProtocolEventHandler(mmi_certman_select_certificates_ind_handler, MSG_ID_MMI_CERTMAN_SELECT_CERT_IND);
    SetProtocolEventHandler(mmi_certman_view_certificates_ind_handler, MSG_ID_MMI_CERTMAN_VIEW_CERT_IND);
    SetProtocolEventHandler(mmi_certman_invalid_certificates_ind_handler, MSG_ID_MMI_CERTMAN_INVALID_CERT_IND);
    SetProtocolEventHandler(mmi_certman_select_user_certificates_ind_handler, MSG_ID_MMI_CERTMAN_SELECT_USER_CERT_IND);
    SetProtocolEventHandler(mmi_certman_privkey_usage_password_ind_handler, MSG_ID_CERTMAN_PRIVKEY_USAGE_PASSWORD_IND);
    SetProtocolEventHandler(
        mmi_certman_send_privkey_usage_confirm_ind_handler,
        MSG_ID_CERTMAN_PRIVKEY_USAGE_CONFIRM_IND);

}

/*****************************IMPORT CERTIFICATES*****************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_pre_entry_get_decryption_password
 * DESCRIPTION
 *  pre entry function to input decryption password
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_pre_entry_get_decryption_password(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_certman_pre_entry_get_decryption_password");
    memset(
        g_mmi_certman_context.import_context_p->password,
        0,
        sizeof(g_mmi_certman_context.import_context_p->password));
    g_mmi_certman_context.screen_id = 0;
    mmi_certman_get_decryption_password();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_get_decryption_password
 * DESCRIPTION
 *  entry screen to input decryption password
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_get_decryption_password(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer; /* Buffer holding history data */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_certman_entry_new_screen(SCR_ID_CERTMAN_GET_DECR_PWD, mmi_certman_get_decryption_password);
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_certman_get_decryption_password");
    gui_buffer = GetCurrGuiBuffer(SCR_ID_CERTMAN_GET_DECR_PWD);
    RegisterInputBoxValidationFunction(mmi_certman_decr_pwd_length_validation);
    enable_resized_small_screen();
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);   /* To set  the Right soft key */
    ShowCategory111Screen(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        STR_CERTMAN_INPUT_PASSWORD,
        INPUT_TYPE_ALPHANUMERIC_PASSWORD,
        g_mmi_certman_context.import_context_p->password,
        CERTMAN_PASSWORD_LENGTH,
        NULL,
        gui_buffer);
    SetLeftSoftkeyFunction(mmi_certman_decryption_pwd_lsk, KEY_EVENT_UP);
    SetCategory111RightSoftkeyFunction(mmi_certman_exit_pwd_screen, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_decryption_pwd_lsk
 * DESCRIPTION
 *  lsk function for decryption pwd screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_decryption_pwd_lsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_certman_context.screen_id = 0;
    mmi_certman_check_decryption_pwd(g_mmi_certman_context.import_context_p->password);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_decr_pwd_length_validation
 * DESCRIPTION
 *  It checks if the Min. required password entered or not
 * PARAMETERS
 *  text_p          [IN]        
 *  cursor_p        [IN]        
 *  length          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_decr_pwd_length_validation(U8 *text_p, U8 *cursor_p, S32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((length) < 1)
    {
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_POUND, KEY_EVENT_UP);
    }
    else
    {
        EnableLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        SetKeyHandler(mmi_certman_decryption_pwd_lsk, KEY_POUND, KEY_EVENT_UP);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_exit_pwd_screen
 * DESCRIPTION
 *  This function is for exit from pdecryption password screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_exit_pwd_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* mmi_certman_install_certificates_rsp(MMI_FALSE); */
    mmi_certman_exit_from_import();
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_pre_entry_display_file_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_pre_entry_display_file_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == mmi_certman_check_screen_in_history())
    {
        mmi_certman_history_replace(
            SCR_ID_CERTMAN_PROGRESS_SCREEN,
            SCR_ID_CERTMAN_FILE_INFO,
            mmi_certman_display_file_info);
    }
    else
    {
        g_mmi_certman_context.screen_id = 0;
        mmi_certman_display_file_info();
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_display_file_info
 * DESCRIPTION
 *  Entry function to display PKCS#12 file information
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_display_file_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *file_info;
    U8 *gui_buffer;
    S8 buf[5] = { '\0' };
    S8 buf1[10] = { '\0' };
    U16 no_of_pkeys;
    S32 buff_length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_buffer = GetCurrGuiBuffer(SCR_ID_CERTMAN_FILE_INFO);
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_certman_display_file_info");
    buff_length = MAX_SUB_MENUS * MAX_SUB_MENU_SIZE;
    file_info = (PU8) subMenuData;
    file_info[0] = 0;
    file_info[1] = 0;
    mmi_certman_entry_new_screen(SCR_ID_CERTMAN_FILE_INFO, mmi_certman_display_file_info);

    no_of_pkeys = mmi_certman_get_no_of_private_keys();
    sprintf((S8*) buf, "%d", no_of_pkeys);
    mmi_asc_to_ucs2((S8*) buf1, (S8*) buf);

    mmi_ucs2ncpy((PS8) file_info, (PS8) GetString(STR_CERTMAN_FILE_CONTAINS), buff_length);
    buff_length = (buff_length -=
                   ENCODING_LENGTH * mmi_ucs2strlen((S8*) GetString(STR_CERTMAN_FILE_CONTAINS))) > 0 ? buff_length : 0;

    mmi_ucs2ncat((PS8) file_info, (PS8) L":\n\n", buff_length);
    buff_length = (buff_length -= ENCODING_LENGTH * mmi_ucs2strlen((S8*) L":\n\n")) > 0 ? buff_length : 0;

    mmi_ucs2ncat((PS8) file_info, (PS8) buf1, buff_length);
    buff_length = (buff_length -= ENCODING_LENGTH * mmi_ucs2strlen((S8*) buf1)) > 0 ? buff_length : 0;

    mmi_ucs2ncat((PS8) file_info, (PS8) L" ", buff_length);
    buff_length = (buff_length -= ENCODING_LENGTH * mmi_ucs2strlen((S8*) L" ")) > 0 ? buff_length : 0;

    mmi_ucs2ncat((PS8) file_info, (PS8) GetString(STR_CERTMAN_PRIVATE_KEY), buff_length);
    buff_length = (buff_length -=
                   ENCODING_LENGTH * mmi_ucs2strlen((S8*) GetString(STR_CERTMAN_PRIVATE_KEY))) > 0 ? buff_length : 0;

    mmi_ucs2ncat((PS8) file_info, (PS8) L"\n", buff_length);
    buff_length = (buff_length -= ENCODING_LENGTH * mmi_ucs2strlen((S8*) L"\n")) > 0 ? buff_length : 0;

    mmi_ucs2ncat((PS8) file_info, (PS8) buf1, buff_length);
    buff_length = (buff_length -= ENCODING_LENGTH * mmi_ucs2strlen((S8*) buf1)) > 0 ? buff_length : 0;

    mmi_ucs2ncat((PS8) file_info, (PS8) L" ", buff_length);
    buff_length = (buff_length -= ENCODING_LENGTH * mmi_ucs2strlen((S8*) L" ")) > 0 ? buff_length : 0;

    mmi_ucs2ncat((PS8) file_info, (PS8) GetString(STR_CERTMAN_PERSONAL_CERTIFICATE), buff_length);
    buff_length = (buff_length -=
                   ENCODING_LENGTH * mmi_ucs2strlen((S8*) GetString(STR_CERTMAN_PERSONAL_CERTIFICATE))) >
        0 ? buff_length : 0;

    ShowCategory74Screen(
        STR_CERTMAN_PERSONAL_CERTIFICATE,
        NULL,
        STR_GLOBAL_SAVE,
        NULL,
        STR_CERTMAN_CERTIFICATE_DISCARD,
        NULL,
        file_info,
        mmi_ucs2strlen((const S8*)file_info),
        gui_buffer);
    SetLeftSoftkeyFunction(mmi_certman_display_file_info_lsk, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_certman_discard_file, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_display_file_info_lsk
 * DESCRIPTION
 *  LSK function for file info screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_display_file_info_lsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_certman_context.screen_id = 0;
    mmi_certman_save_file();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_discard_file
 * DESCRIPTION
 *  This function discards file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_discard_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_certman_context.screen_id = 0;
    DisplayPopup((PU8) GetString(STR_CERTMAN_NOT_SAVED), NULL, NULL, MMI_CERTMAN_POPUP_DURATION, 0);
    /* DeleteNHistory(1); */
    /* mmi_certman_install_certificates_rsp(MMI_FALSE); */
    mmi_certman_exit_from_import();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_pre_entry_display_certificate_contents
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_pre_entry_display_certificate_contents(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_certman_context.cert_info = (PU8) subMenuData;
    g_mmi_certman_context.cert_info[0] = 0;
    g_mmi_certman_context.cert_info[1] = 0;
    mmi_certman_fill_certificate_contents_only(
        g_mmi_certman_context.cert_info,
        &(g_mmi_certman_context.import_context_p->parsed_data_p->cert));

    if (MMI_TRUE == mmi_certman_check_screen_in_history())
    {
        mmi_certman_history_replace(
            SCR_ID_CERTMAN_PROGRESS_SCREEN,
            SCR_ID_CERTMAN_CERTIFICATE_DETAILS,
            mmi_certman_display_certificate_contents);
    }
    else
    {
        g_mmi_certman_context.screen_id = 0;
        mmi_certman_display_certificate_contents();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_display_certificate_contents
 * DESCRIPTION
 *  This function display the contents of the certificate in case of import
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_display_certificate_contents(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_buffer = GetCurrGuiBuffer(SCR_ID_CERTMAN_CERTIFICATE_DETAILS);
    mmi_certman_entry_new_screen(SCR_ID_CERTMAN_CERTIFICATE_DETAILS, mmi_certman_display_certificate_contents);

    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_certman_display_certificate_contents");
    ShowCategory74Screen(
        STR_CERTMAN_CERTIFICATE_INFO,
        NULL,
        STR_GLOBAL_SAVE,
        NULL,
        STR_CERTMAN_CERTIFICATE_DISCARD,
        NULL,
        g_mmi_certman_context.cert_info,
        (mmi_ucs2strlen((const S8*)g_mmi_certman_context.cert_info)),
        gui_buffer);
    SetLeftSoftkeyFunction(mmi_certman_import_insecure_root_certificate, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_certman_display_certificate_rsk, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_import_insecure_root_certificate
 * DESCRIPTION
 *  This function check whether the certificate is secure or not
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_import_insecure_root_certificate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_certman_context.import_context_p->parsed_data_p->insecure_rootca_warning != 0)
    {
        DisplayConfirm(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            get_string(STR_CERTMAN_INSECURE_CERT),
            IMG_GLOBAL_QUESTION,
            NULL);

        SetLeftSoftkeyFunction(mmi_certman_check_certificate_expiry, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_certman_display_certificate_rsk, KEY_EVENT_UP);
    }
    else
    {
        mmi_certman_check_certificate_expiry();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_check_certificate_expiry
 * DESCRIPTION
 *  This function is for checking the expiry of the certificate
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_check_certificate_expiry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_certman_context.import_context_p->parsed_data_p->cert_expired != 0)
    {
        DisplayConfirm(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            get_string(STR_CERTMAN_EXPIRED_CERT),
            IMG_GLOBAL_QUESTION,
            NULL);
        SetLeftSoftkeyFunction(mmi_certman_save_certificate, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_certman_display_certificate_rsk, KEY_EVENT_UP);
    }
    else
    {
        mmi_certman_save_certificate();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_display_certificate_rsk
 * DESCRIPTION
 *  the RSK function for display certificate entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_display_certificate_rsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_certman_context.screen_id = 0;
    /* DisplayPopup((PU8) GetString(STR_CERTMAN_DISCARDED), NULL, NULL, MMI_CERTMAN_POPUP_DURATION, 0); */
    mmi_certman_display_message_with_callback(STR_CERTMAN_DISCARDED, mmi_certman_discard_certificate);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_get_certificate_inputs
 * DESCRIPTION
 *  This finction is to get certificate's input by user
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_get_certificate_inputs(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;
    U8 *inputBuffer = NULL;
    U16 inputBufferSize = 0;
    S32 total_inline_items;

    /* U16 ImageList[CERT_INPUTS_INLINE_TOTAL] = {0, }; */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_certman_category57_entry_new_screen(SCR_ID_CERTMAN_CERTIFICATE_INPUTS, mmi_certman_get_certificate_inputs);
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_certman_get_certificate_inputs");

    InitializeCategory57Screen();

    gui_buffer = GetCurrGuiBuffer(SCR_ID_CERTMAN_CERTIFICATE_INPUTS);
    if (gui_buffer == NULL)
    {
        g_mmi_certman_context.selected_protection_method[0] = (U8*) GetString(STR_GLOBAL_PASSWORD);
    }
    /*  else
       {
       DisableCategory57ScreenDone();
       } */

    inputBuffer = GetCurrNInputBuffer(SCR_ID_CERTMAN_CERTIFICATE_INPUTS, &inputBufferSize);

    SetParentHandler(0);

    mmi_certman_certificate_input_inline_struct();

    RegisterHighlightHandler(mmi_certman_highlight_certificate_input_inline_item);
    if (g_mmi_certman_context.import_context_p->cert_group != CERTMAN_CERTGRP_PERSONAL)
    {
        total_inline_items = 4;
    }
    else
    {
        total_inline_items = 10;
    }
    if (inputBuffer)
    {
        SetCategory57Data(wgui_inline_items, total_inline_items, inputBuffer);
    }
    SetInlineListMenuChanged();
    ShowCategory57Screen(
        STR_CERTMAN_CERTIFICATE_DETAILS,
        NULL,
        STR_GLOBAL_OK,
        NULL,
        STR_GLOBAL_BACK,
        NULL,
        total_inline_items,
        NULL,
        wgui_inline_items,
        0,
        gui_buffer);

    SetCategory57RightSoftkeyFunctions(
        mmi_certman_certificate_inputs_rsk,
        mmi_certman_exit_from_import_with_gobackhistory);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_get_certificate_label_inputs
 * DESCRIPTION
 *  Callback for full screen edit from inline edit screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_get_certificate_label_inputs(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
    SetLeftSoftkeyFunction(EntryScrForInputMethodAndDone, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_certificate_input_inline_struct
 * DESCRIPTION
 *  This function is to input the inline screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_certificate_input_inline_struct()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_certman_certificate_input_inline_struct");
    /* Inline Label Caption */
    SetInlineItemActivation(&(wgui_inline_items[0]), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&(wgui_inline_items[0]), (U8*) GetString(STR_CERTMAN_CERTIFICATE_LABEL));

    /* Inline Label */
    SetInlineItemActivation(&(wgui_inline_items[1]), KEY_LSK, KEY_EVENT_UP);

    SetInlineItemFullScreenEdit(
        &(wgui_inline_items[1]),
        STR_CERTMAN_CERTIFICATE_LABEL,
        0,
        (U8*) g_mmi_certman_context.import_context_p->certificate_label,
        CERTMAN_LABEL_LENGTH / 2,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE);
    SetInlineFullScreenEditCustomFunction(&(wgui_inline_items[1]), mmi_certman_get_certificate_label_inputs);

    /* Inline Key Usage Caption */
    SetInlineItemActivation(&(wgui_inline_items[2]), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    SetInlineItemCaption(&(wgui_inline_items[2]), (U8*) GetString(STR_CERTMAN_CERTIFICATE_KEY_USAGE));

    /* Inline Key Usage Value */

    SetInlineItemActivation(&(wgui_inline_items[3]), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemDisplayOnly(&(wgui_inline_items[3]), (U8*) g_mmi_certman_context.show_string);

    if (g_mmi_certman_context.import_context_p->cert_group == CERTMAN_CERTGRP_PERSONAL)
    {
        g_mmi_certman_context.selected_protection_method[0] = (U8*) GetString(STR_GLOBAL_NONE);
        g_mmi_certman_context.selected_protection_method[1] =
            (U8*) GetString(STR_CERTMAN_CERTIFICATE_PRIV_KEY_CONFIRMATION);
        g_mmi_certman_context.selected_protection_method[2] = (U8*) GetString(STR_GLOBAL_PASSWORD);
        /* Caption */

        SetInlineItemActivation(&(wgui_inline_items[4]), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
        SetInlineItemCaption(&(wgui_inline_items[4]), (U8*) GetString(STR_CERTMAN_CERTIFICATE_PRIVATE_KEY_PROTECTION));

        /* Inline Select */
        SetInlineItemActivation(&(wgui_inline_items[5]), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
        SetInlineItemSelect(
            &(wgui_inline_items[5]),
            (S32) 3,
            (U8 **) g_mmi_certman_context.selected_protection_method,
            (S32*) (&g_mmi_certman_context.import_context_p->protection_method));
        SetInlineItemActivation(&(wgui_inline_items[6]), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
        SetInlineItemCaption(&(wgui_inline_items[6]), (U8*) GetString(STR_CERTMAN_INPUT_PASSWORD));
        /* Inline Edit */

        memset(g_mmi_certman_context.import_context_p->privatekey_pwd, 0, 2);
        SetInlineItemActivation(&(wgui_inline_items[7]), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
        SetInlineItemTextEdit(
            &(wgui_inline_items[7]),
            (U8*) g_mmi_certman_context.import_context_p->privatekey_pwd,
            CERTMAN_PKPWD_SIZE / 2,
            INPUT_TYPE_ALPHANUMERIC_PASSWORD);

        SetInlineItemActivation(&(wgui_inline_items[8]), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
        SetInlineItemCaption(&(wgui_inline_items[8]), (U8*) GetString(STR_CERTMAN_CERTIFICATE_CONFIRM_PWD));

        /* Inline Edit */
        memset(g_mmi_certman_context.import_context_p->privatekey_cnf_pwd, 0, 2);
        SetInlineItemActivation(&(wgui_inline_items[9]), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
        SetInlineItemTextEdit(
            &(wgui_inline_items[9]),
            (U8*) g_mmi_certman_context.import_context_p->privatekey_cnf_pwd,
            CERTMAN_PKPWD_SIZE / 2,
            INPUT_TYPE_ALPHANUMERIC_PASSWORD);

        // DisableInlineItem(&(wgui_inline_items[4]), 4);
        // DisableInlineItem(&(wgui_inline_items[5]), 5);
        RegisterInlineSelectHighlightHandler(
            &wgui_inline_items[5],
            mmi_certman_highlight_certificate_input_inline_item);

        DisableInlineItem(&(wgui_inline_items[6]), 6);
        DisableInlineItem(&(wgui_inline_items[7]), 7);
        DisableInlineItem(&(wgui_inline_items[8]), 8);
        DisableInlineItem(&(wgui_inline_items[9]), 9);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_show_password_editer
 * DESCRIPTION
 *  This functions is for enabling the inline items
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_show_password_editer()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_certman_context.import_context_p->protection_method == CERTMAN_PROTECT_USAGE_PASSWORD)
    {
        EnableInlineItem(&(wgui_inline_items[6]), 6);
        EnableInlineItem(&(wgui_inline_items[7]), 7);
        EnableInlineItem(&(wgui_inline_items[8]), 8);
        EnableInlineItem(&(wgui_inline_items[9]), 9);
    }
    else
    {
        DisableInlineItem(&(wgui_inline_items[6]), 6);
        DisableInlineItem(&(wgui_inline_items[7]), 7);
        DisableInlineItem(&(wgui_inline_items[8]), 8);
        DisableInlineItem(&(wgui_inline_items[9]), 9);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_entry_select_key_usage_screen
 * DESCRIPTION
 *  This function is the entry key usage screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_entry_select_key_usage_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;
    U32 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; count < MMI_CERTMAN_TOTAL_KEY_USAGE; count++)
    {
        mmi_ucs2cpy(
            (S8*) g_mmi_certman_context.key_usage_list[count],
            (S8*) get_string((U16) (STR_CERTMAN_KP_ALL + 1 + count)));
    }
    mmi_certman_set_key_purpose(g_mmi_certman_context.import_context_p->key_purpose);
    mmi_certman_entry_new_screen(SCR_ID_CERTMAN_CERTIFICATE_KEY_USAGES, mmi_certman_entry_select_key_usage_screen);
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_certman_entry_select_key_usage_screen");

    gui_buffer = GetCurrGuiBuffer(SCR_ID_CERTMAN_CERTIFICATE_KEY_USAGES);
    SetCheckboxToggleRightSoftkeyFunctions(mmi_certman_import_set_selected_listbox_and_goback, GoBackHistory);

    ShowCategory187Screen(
        STR_CERTMAN_CERTIFICATE_KEY_USAGE,
        NULL,
        MMI_CERTMAN_TOTAL_KEY_USAGE,
        mmi_certman_get_item_hdlr,
        mmi_certman_get_item_img_hdlr,
        NULL,
        NULL,
        (U8*) g_mmi_certman_context.list_of_state,
        0,
        NULL,
        gui_buffer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_highlight_certificate_input_inline_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern UI_string_type wgui_inline_edit_get_RSK_string(void);

void mmi_certman_highlight_certificate_input_inline_item(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == 3)
    {
        mmi_certman_show_password_editer();
        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, NULL);
        SetLeftSoftkeyFunction(mmi_certman_entry_select_key_usage_screen, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_import_set_selected_listbox_and_goback
 * DESCRIPTION
 *  set selected listbox
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_import_set_selected_listbox_and_goback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 no_of_true = 0;
    U8 temp_string[10];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_certman_import_set_selected_listbox_and_goback");
    g_mmi_certman_context.import_context_p->key_purpose = 0;
    memset(g_mmi_certman_context.show_string, 0, 2);
    if (g_mmi_certman_context.list_of_state[MMI_CERTMAN_KP_SERVER_AUTH] == MMI_TRUE)
    {
        g_mmi_certman_context.import_context_p->key_purpose |= CERTMAN_KP_SERVER_AUTH;
        mmi_ucs2cat((S8*) g_mmi_certman_context.show_string, (S8*) GetString(STR_CERTMAN_KP_SERVER_AUTH));
        mmi_ucs2cat((S8*) g_mmi_certman_context.show_string, (S8*) L";\n");
        no_of_true++;
    }
    if (g_mmi_certman_context.list_of_state[MMI_CERTMAN_KP_CLIENT_AUTH] == MMI_TRUE)
    {
        g_mmi_certman_context.import_context_p->key_purpose |= CERTMAN_KP_CLIENT_AUTH;
        mmi_ucs2cat((S8*) g_mmi_certman_context.show_string, (S8*) GetString(STR_CERTMAN_KP_CLIENT_AUTH));
        mmi_ucs2cat((S8*) g_mmi_certman_context.show_string, (S8*) L";\n");
        no_of_true++;
    }
    if (g_mmi_certman_context.list_of_state[MMI_CERTMAN_KP_CODE_SIGNING] == MMI_TRUE)
    {
        g_mmi_certman_context.import_context_p->key_purpose |= CERTMAN_KP_CODE_SIGNING;
        mmi_ucs2cat((S8*) g_mmi_certman_context.show_string, (S8*) GetString(STR_CERTMAN_KP_CODE_SIGNING));
        mmi_ucs2cat((S8*) g_mmi_certman_context.show_string, (S8*) L";\n");
        no_of_true++;
    }
    if (g_mmi_certman_context.list_of_state[MMI_CERTMAN_KP_EMAIL_PROTECTION] == MMI_TRUE)
    {
        g_mmi_certman_context.import_context_p->key_purpose |= CERTMAN_KP_EMAIL_PROTECTION;
        mmi_ucs2cat((S8*) g_mmi_certman_context.show_string, (S8*) GetString(STR_CERTMAN_KP_EMAIL_PROTECTION));
        mmi_ucs2cat((S8*) g_mmi_certman_context.show_string, (S8*) L";\n");
        no_of_true++;
    }
    if (g_mmi_certman_context.list_of_state[MMI_CERTMAN_KP_IPSEC_ENDSYSTEM] == MMI_TRUE)
    {
        g_mmi_certman_context.import_context_p->key_purpose |= CERTMAN_KP_IPSEC_ENDSYSTEM;
        mmi_ucs2cat((S8*) g_mmi_certman_context.show_string, (S8*) GetString(STR_CERTMAN_KP_IPSEC_ENDSYSTEM));
        mmi_ucs2cat((S8*) g_mmi_certman_context.show_string, (S8*) L";\n");
        no_of_true++;
    }
    if (g_mmi_certman_context.list_of_state[MMI_CERTMAN_KP_IPSEC_TUNNEL] == MMI_TRUE)
    {
        g_mmi_certman_context.import_context_p->key_purpose |= CERTMAN_KP_IPSEC_TUNNEL;
        mmi_ucs2cat((S8*) g_mmi_certman_context.show_string, (S8*) GetString(STR_CERTMAN_KP_IPSEC_TUNNEL));
        mmi_ucs2cat((S8*) g_mmi_certman_context.show_string, (S8*) L";\n");
        no_of_true++;
    }
    if (g_mmi_certman_context.list_of_state[MMI_CERTMAN_KP_IPSEC_USER] == MMI_TRUE)
    {
        g_mmi_certman_context.import_context_p->key_purpose |= CERTMAN_KP_IPSEC_USER;
        mmi_ucs2cat((S8*) g_mmi_certman_context.show_string, (S8*) GetString(STR_CERTMAN_KP_IPSEC_USER));
        mmi_ucs2cat((S8*) g_mmi_certman_context.show_string, (S8*) L";\n");
        no_of_true++;
    }
    if (g_mmi_certman_context.list_of_state[MMI_CERTMAN_KP_TIME_STAMPING] == MMI_TRUE)
    {
        g_mmi_certman_context.import_context_p->key_purpose |= CERTMAN_KP_TIME_STAMPING;
        mmi_ucs2cat((S8*) g_mmi_certman_context.show_string, (S8*) GetString(STR_CERTMAN_KP_TIME_STAMPING));
        mmi_ucs2cat((S8*) g_mmi_certman_context.show_string, (S8*) L";\n");
        no_of_true++;
    }
    if (g_mmi_certman_context.list_of_state[MMI_CERTMAN_KP_OCSP_SIGNING] == MMI_TRUE)
    {
        g_mmi_certman_context.import_context_p->key_purpose |= CERTMAN_KP_OCSP_SIGNING;
        mmi_ucs2cat((S8*) g_mmi_certman_context.show_string, (S8*) GetString(STR_CERTMAN_KP_OCSP_SIGNING));
        mmi_ucs2cat((S8*) g_mmi_certman_context.show_string, (S8*) L";\n");
        no_of_true++;
    }
    if (no_of_true == MMI_CERTMAN_TOTAL_KEY_USAGE)
    {
        mmi_ucs2cpy((S8*) g_mmi_certman_context.show_string, (S8*) GetString(STR_CERTMAN_KP_ALL));
    }
    GoBackHistory();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_certificate_inputs_rsk
 * DESCRIPTION
 *  RSK function for certificate inputs
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_certificate_inputs_rsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_certman_context.screen_id = 0;
    mmi_certman_check_label();
}

/**************************************************************************/
/*****************************LAUNCH CERTIFICATES**************************/
/**************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_highlight_authority_certificates
 * DESCRIPTION
 *  This function is for highlight authority certificate
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_highlight_authority_certificates(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_certman_display_authority_certificates, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_highlight_user_certificates
 * DESCRIPTION
 *  This function is for highlight user certificate
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_highlight_user_certificates(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_certman_display_user_certificates, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_highlight_view_certificates
 * DESCRIPTION
 *  This function is to highlight view
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_highlight_view_certificates(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_certman_view_certificates, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_highlight_delete_certificates
 * DESCRIPTION
 *  This function is to highlight  delete
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_highlight_delete_certificates(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_certman_pre_delete_certificates, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_highlight_delete_all_certificates
 * DESCRIPTION
 *  This function is to highlight delete all
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_highlight_delete_all_certificates(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_certman_pre_delete_all_certificates, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_highlight_key_usage_certificates
 * DESCRIPTION
 *  This function is to highlight key usage
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_highlight_key_usage_certificates(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_certman_key_usages_certificates, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_entry_launch_certificate_manager
 * DESCRIPTION
 *  Entry function to launch certificate manager
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_entry_launch_certificate_manager(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    U16 nStrItemList[2];
    U16 num_of_items = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* PRINT_INFORMATION_2(MMI_TRACE_INFO, "Enters mmi_certman_entry_certificate_manager_launch"); */
    mmi_certman_entry_new_screen(SCR_ID_CERTMAN_CERTIFICATE_GROUPS, mmi_certman_entry_launch_certificate_manager);
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_certman_entry_launch_certificate_manager");
    gui_buffer = GetCurrGuiBuffer(SCR_ID_CERTMAN_CERTIFICATE_GROUPS);
    num_of_items = GetNumOfChild(MENU_ID_CERTMAN_ALL_CERT);
    GetSequenceStringIds(MENU_ID_CERTMAN_ALL_CERT, nStrItemList);
    SetParentHandler(MENU_ID_CERTMAN_ALL_CERT);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ShowCategory15Screen(
        STR_CERTMAN_CERTIFICATE_MANAGER,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_of_items,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        LIST_MENU,
        0,
        gui_buffer);
    SetRightSoftkeyFunction(mmi_certman_exit_certificate_manager, KEY_EVENT_UP);
    // mmi_certman_free(nStrItemList);
    // nStrItemList = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_exit_certificate_manager
 * DESCRIPTION
 *  function to exit certificate manager
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_exit_certificate_manager(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_certman_launch_certificates_rsp(MMI_FALSE, g_mmi_certman_context.launch_select_context_p->trans_id);
    mmi_certman_launch_deinit();
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_pre_entry_display_certificate_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_pre_entry_display_certificate_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == mmi_certman_check_screen_in_history())
    {
        mmi_certman_history_replace(
            SCR_ID_CERTMAN_PROGRESS_SCREEN,
            SCR_ID_CERTMAN_CERTIFICATE_LIST,
            mmi_certman_display_certificate_list);
    }
    else
    {
        g_mmi_certman_context.screen_id = 0;
        mmi_certman_display_certificate_list();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_check_is_progress_screen_present
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
pBOOL mmi_certman_check_is_progress_screen_present()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetActiveScreenId() == SCR_ID_CERTMAN_PROGRESS_SCREEN ||
        (IsScreenPresent(SCR_ID_CERTMAN_PROGRESS_SCREEN) == MMI_TRUE))
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_display_certificate_list
 * DESCRIPTION
 *  Function to display the certificate list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_display_certificate_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 gui_buffer; /* Buffer holding history data */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_certman_context.screen_id = 0;
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_certman_display_certificate_list");
    if (g_mmi_certman_context.launch_select_context_p->current_state == MMI_CERTMAN_LAUNCH_SELECT_CREATE_LIST)
    {
        g_mmi_certman_context.launch_select_context_p->certificate_count = 0;
        g_mmi_certman_context.launch_select_context_p->current_state = MMI_CERTMAN_LAUNCH_SELECT_GROUP_REQ;
        mmi_certman_launch_select_state(NULL);
        return;
    }

    if (g_mmi_certman_context.launch_select_context_p->certificate_count == 0)
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_EMPTY), NULL, NULL, MMI_CERTMAN_POPUP_DURATION, 0);
        return;
    }
    mmi_certman_entry_new_screen(SCR_ID_CERTMAN_CERTIFICATE_LIST, mmi_certman_display_certificate_list);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_CERTMAN_CERTIFICATE_LIST);

    /* SetParentHandler(SCR_ID_CERTMAN_CERTIFICATE_LIST); */
    RegisterHighlightHandler(mmi_certman_certificate_list_highlight_handler);
    ShowCategory184Screen(
        g_mmi_certman_context.popup_string_id,
        0,
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        g_mmi_certman_context.launch_select_context_p->certificate_count,
        mmi_certman_get_certificates,
        NULL,
        0,
        gui_buffer);

    SetLeftSoftkeyFunction(mmi_certman_launch_options, KEY_EVENT_UP);
    SetKeyHandler(mmi_certman_launch_options, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_get_certificates
 * DESCRIPTION
 *  To get the certificates from list
 * PARAMETERS
 *  item_index          [IN]        (index of current item)
 *  str_buff            [IN]        
 *  img_buff_p          [IN]        
 *  str_img_mask        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_certman_get_certificates(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_certman_get_certificates");
    if ((item_index < 0) || (item_index > MMI_CERTMAN_CERTIFICATES_MAX))
    {
        return FALSE;
    }

    mmi_ucs2cpy(
        (PS8) str_buff,
        (PS8) g_mmi_certman_context.launch_select_context_p->certificate_list[item_index].cert_label);
    if (g_mmi_certman_context.launch_select_context_p->certificate_list[item_index].cert_group ==
        CERTMAN_CERTGRP_ROOTCA)
    {
        *img_buff_p = NULL;
        return TRUE;
    }
    if (g_mmi_certman_context.launch_select_context_p->certificate_list[item_index].cert_group ==
        CERTMAN_CERTGRP_ROOTCA)
    {
        *img_buff_p = NULL;
        return TRUE;
    }
    if (g_mmi_certman_context.launch_select_context_p->certificate_list[item_index].cert_group ==
        CERTMAN_CERTGRP_OTHERUSER)
    {
        *img_buff_p = NULL;
        return TRUE;
    }
    if (g_mmi_certman_context.launch_select_context_p->certificate_list[item_index].cert_group ==
        CERTMAN_CERTGRP_PERSONAL)
    {
        *img_buff_p = NULL;
        return TRUE;
    }
    *img_buff_p = NULL;
    return TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_certificate_list_highlight_handler
 * DESCRIPTION
 *  highlight handler for certificate
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_certificate_list_highlight_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_certman_context.launch_select_context_p->selected_index = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_launch_options
 * DESCRIPTION
 *  Functions for launch options
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_launch_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    U16 nStrItemList[4];
    U16 num_of_items = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_certman_launch_options");
    mmi_certman_entry_new_screen(SCR_ID_CERTMAN_CERTIFICATE_OPTIONS, mmi_certman_launch_options);
    /* EntryNewScreen(SCR_ID_CERTMAN_CERTIFICATE_OPTIONS, NULL, mmi_certman_launch_options, NULL); */
    gui_buffer = GetCurrGuiBuffer(SCR_ID_CERTMAN_CERTIFICATE_GROUPS);
    num_of_items = GetNumOfChild(MENU_ID_CERTMAN_OPTIONS);
    /* nStrItemList = mmi_certman_malloc(sizeof(U16) * num_of_items); */
    GetSequenceStringIds(MENU_ID_CERTMAN_OPTIONS, nStrItemList);
    SetParentHandler(MENU_ID_CERTMAN_OPTIONS);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_of_items,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        LIST_MENU,
        0,
        gui_buffer);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    // mmi_certman_free(nStrItemList);
    // nStrItemList = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_pre_entry_view_certificate_content
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_pre_entry_view_certificate_content(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_certman_context.cert_info = (PU8) subMenuData;
    g_mmi_certman_context.cert_info[0] = 0;
    g_mmi_certman_context.cert_info[1] = 0;
    mmi_certman_fill_certificate_contents_only(
        g_mmi_certman_context.cert_info,
        g_mmi_certman_context.launch_select_context_p->display_p);
    if (MMI_TRUE == mmi_certman_check_screen_in_history())
    {
        mmi_certman_history_replace(
            SCR_ID_CERTMAN_PROGRESS_SCREEN,
            SCR_ID_CERTMAN_CERTIFICATE_VIEW,
            mmi_certman_view_certificate_content);
    }
    else
    {
        g_mmi_certman_context.screen_id = 0;
        mmi_certman_view_certificate_content();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_view_certificate_content
 * DESCRIPTION
 *  entry function to view certificate content in case of launch
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_view_certificate_content(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_buffer = GetCurrGuiBuffer(SCR_ID_CERTMAN_CERTIFICATE_VIEW);

    mmi_certman_entry_new_screen(SCR_ID_CERTMAN_CERTIFICATE_VIEW, mmi_certman_view_certificate_content);
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_certman_launch_options");

    ShowCategory74Screen(
        STR_CERTMAN_CERTIFICATE_INFO,
        NULL,
        NULL,
        NULL,
        STR_GLOBAL_BACK,
        NULL,
        g_mmi_certman_context.cert_info,
        (mmi_ucs2strlen((const S8*)g_mmi_certman_context.cert_info)),
        gui_buffer);
    /* SetLeftSoftkeyFunction(, KEY_EVENT_UP); */
    SetRightSoftkeyFunction(mmi_certman_exit_view, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_exit_view
 * DESCRIPTION
 *  function ro exit from view
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_exit_view(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteUptoScrID(SCR_ID_CERTMAN_CERTIFICATE_LIST);
    certman_cert_display_content_free(g_mmi_certman_context.launch_select_context_p->display_p);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_pre_delete_certificates
 * DESCRIPTION
 *  pre function for delete
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_pre_delete_certificates(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index = g_mmi_certman_context.launch_select_context_p->selected_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_certman_pre_delete_certificates");
    if (g_mmi_certman_context.launch_select_context_p->certificate_list[index].cert_prop == CERTMAN_PROP_READ_ONLY)
    {
        DisplayPopup((PU8) GetString(STR_CERTMAN_READ_ONLY), NULL, NULL, MMI_CERTMAN_POPUP_DURATION, 0);
        DeleteUptoScrID(SCR_ID_CERTMAN_CERTIFICATE_LIST);
        /* DeleteNHistory(1); */
    }
    else
    {
        DisplayConfirm(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            get_string(STR_GLOBAL_DELETE),
            IMG_GLOBAL_QUESTION,
            NULL);
        SetLeftSoftkeyFunction(mmi_certman_delete_certificates, KEY_EVENT_UP);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_pre_delete_all_certificates
 * DESCRIPTION
 *  pre function for delete all
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_pre_delete_all_certificates(void)
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
        get_string(STR_GLOBAL_DELETE_ALL),
        IMG_GLOBAL_QUESTION,
        NULL);
    SetLeftSoftkeyFunction(mmi_certman_delete_all_certificates, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_key_usages_certificates
 * DESCRIPTION
 *  Entry function to set key usages
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_key_usages_certificates(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;
    U32 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; count < MMI_CERTMAN_TOTAL_KEY_USAGE; count++)
    {
        /* memset(g_certman_option_list[count].menu_string,2,'\0'); */
        mmi_ucs2cpy(
            (S8*) g_mmi_certman_context.key_usage_list[count],
            (S8*) get_string((U16) (STR_CERTMAN_KP_ALL + 1 + count)));
    }
    mmi_certman_set_key_purpose(g_mmi_certman_context.launch_select_context_p->
                                certificate_list[g_mmi_certman_context.launch_select_context_p->selected_index].
                                key_purpose);
    mmi_certman_entry_new_screen(SCR_ID_CERTMAN_CERTIFICATE_SET_KEY_USAGES, mmi_certman_key_usages_certificates);
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_certman_key_usages_certificates");
    gui_buffer = GetCurrGuiBuffer(SCR_ID_CERTMAN_CERTIFICATE_SET_KEY_USAGES);
    SetCheckboxToggleRightSoftkeyFunctions(mmi_certman_launch_set_selected_listbox_and_goback, GoBackHistory);

    ShowCategory187Screen(
        STR_CERTMAN_CERTIFICATE_KEY_USAGE,
        NULL,
        MMI_CERTMAN_TOTAL_KEY_USAGE,
        mmi_certman_get_item_hdlr,
        mmi_certman_get_item_img_hdlr,
        NULL,
        NULL,
        (U8*) g_mmi_certman_context.list_of_state,
        0,
        NULL,
        gui_buffer);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_set_key_purpose
 * DESCRIPTION
 *  function to set key purpose values
 * PARAMETERS
 *  key_purpose     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_set_key_purpose(U32 key_purpose)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((key_purpose & CERTMAN_KP_SERVER_AUTH) == CERTMAN_KP_SERVER_AUTH)
    {
        g_mmi_certman_context.list_of_state[MMI_CERTMAN_KP_SERVER_AUTH] = MMI_TRUE;
    }
    if ((key_purpose & CERTMAN_KP_CLIENT_AUTH) == CERTMAN_KP_CLIENT_AUTH)
    {
        g_mmi_certman_context.list_of_state[MMI_CERTMAN_KP_CLIENT_AUTH] = MMI_TRUE;
    }
    if ((key_purpose & CERTMAN_KP_CODE_SIGNING) == CERTMAN_KP_CODE_SIGNING)
    {
        g_mmi_certman_context.list_of_state[MMI_CERTMAN_KP_CODE_SIGNING] = MMI_TRUE;
    }
    if ((key_purpose & CERTMAN_KP_EMAIL_PROTECTION) == CERTMAN_KP_EMAIL_PROTECTION)
    {
        g_mmi_certman_context.list_of_state[MMI_CERTMAN_KP_EMAIL_PROTECTION] = MMI_TRUE;
    }

    if ((key_purpose & CERTMAN_KP_IPSEC_ENDSYSTEM) == CERTMAN_KP_IPSEC_ENDSYSTEM)
    {
        g_mmi_certman_context.list_of_state[MMI_CERTMAN_KP_IPSEC_ENDSYSTEM] = MMI_TRUE;
    }
    if ((key_purpose & CERTMAN_KP_IPSEC_TUNNEL) == CERTMAN_KP_IPSEC_TUNNEL)
    {
        g_mmi_certman_context.list_of_state[MMI_CERTMAN_KP_IPSEC_TUNNEL] = MMI_TRUE;
    }
    if ((key_purpose & CERTMAN_KP_IPSEC_USER) == CERTMAN_KP_IPSEC_USER)
    {
        g_mmi_certman_context.list_of_state[MMI_CERTMAN_KP_IPSEC_USER] = MMI_TRUE;
    }
    if ((key_purpose & CERTMAN_KP_TIME_STAMPING) == CERTMAN_KP_TIME_STAMPING)
    {
        g_mmi_certman_context.list_of_state[MMI_CERTMAN_KP_TIME_STAMPING] = MMI_TRUE;
    }
    if ((key_purpose & CERTMAN_KP_OCSP_SIGNING) == CERTMAN_KP_OCSP_SIGNING)
    {
        g_mmi_certman_context.list_of_state[MMI_CERTMAN_KP_OCSP_SIGNING] = MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_launch_set_selected_listbox_and_goback
 * DESCRIPTION
 *  function to set seleced list box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_launch_set_selected_listbox_and_goback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = g_mmi_certman_context.launch_select_context_p->selected_index;
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_certman_launch_set_selected_listbox_and_goback");
    g_mmi_certman_context.launch_select_context_p->certificate_list[index].key_purpose = 0;
    if (g_mmi_certman_context.list_of_state[MMI_CERTMAN_KP_SERVER_AUTH] == MMI_TRUE)
    {
        g_mmi_certman_context.launch_select_context_p->certificate_list[index].key_purpose |= CERTMAN_KP_SERVER_AUTH;
    }
    if (g_mmi_certman_context.list_of_state[MMI_CERTMAN_KP_CLIENT_AUTH] == MMI_TRUE)
    {
        g_mmi_certman_context.launch_select_context_p->certificate_list[index].key_purpose |= CERTMAN_KP_CLIENT_AUTH;
    }
    if (g_mmi_certman_context.list_of_state[MMI_CERTMAN_KP_CODE_SIGNING] == MMI_TRUE)
    {
        g_mmi_certman_context.launch_select_context_p->certificate_list[index].key_purpose |= CERTMAN_KP_CODE_SIGNING;
    }
    if (g_mmi_certman_context.list_of_state[MMI_CERTMAN_KP_EMAIL_PROTECTION] == MMI_TRUE)
    {
        g_mmi_certman_context.launch_select_context_p->certificate_list[index].key_purpose |=
            CERTMAN_KP_EMAIL_PROTECTION;
    }
    if (g_mmi_certman_context.list_of_state[MMI_CERTMAN_KP_IPSEC_ENDSYSTEM] == MMI_TRUE)
    {
        g_mmi_certman_context.launch_select_context_p->certificate_list[index].key_purpose |=
            CERTMAN_KP_IPSEC_ENDSYSTEM;
    }
    if (g_mmi_certman_context.list_of_state[MMI_CERTMAN_KP_IPSEC_TUNNEL] == MMI_TRUE)
    {
        g_mmi_certman_context.launch_select_context_p->certificate_list[index].key_purpose |= CERTMAN_KP_IPSEC_TUNNEL;
    }
    if (g_mmi_certman_context.list_of_state[MMI_CERTMAN_KP_IPSEC_USER] == MMI_TRUE)
    {
        g_mmi_certman_context.launch_select_context_p->certificate_list[index].key_purpose |= CERTMAN_KP_IPSEC_USER;
    }
    if (g_mmi_certman_context.list_of_state[MMI_CERTMAN_KP_TIME_STAMPING] == MMI_TRUE)
    {
        g_mmi_certman_context.launch_select_context_p->certificate_list[index].key_purpose |= CERTMAN_KP_TIME_STAMPING;
    }
    if (g_mmi_certman_context.list_of_state[MMI_CERTMAN_KP_OCSP_SIGNING] == MMI_TRUE)
    {
        g_mmi_certman_context.launch_select_context_p->certificate_list[index].key_purpose |= CERTMAN_KP_OCSP_SIGNING;
    }
    SetProtocolEventHandler(mmi_certman_launch_update_key_purpose_cnf_handler, MSG_ID_CERTMAN_UPDATE_KEY_PURPOSE_CNF);
    g_mmi_certman_context.screen_id = 0;
    mmi_certman_progress_screen();
    certman_send_update_key_purpose_req(
        MOD_MMI,
        g_mmi_certman_context.launch_select_context_p->trans_id,
        g_mmi_certman_context.launch_select_context_p->certificate_list[index].cert_id,
        g_mmi_certman_context.launch_select_context_p->certificate_list[index].key_purpose);
    /* GoBackHistory(); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_get_item_hdlr
 * DESCRIPTION
 *  function to get item handler
 * PARAMETERS
 *  item_index      [IN]        
 *  str_buff        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_certman_get_item_hdlr(S32 item_index, UI_string_type str_buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) str_buff, (S8*) g_mmi_certman_context.key_usage_list[item_index]);
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_get_item_img_hdlr
 * DESCRIPTION
 *  function to get images
 * PARAMETERS
 *  item_index      [IN]        
 *  state           [IN]        
 *  img_buff_p      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_certman_get_item_img_hdlr(S32 item_index, U8 state, PU8 *img_buff_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *img_buff_p = get_image((MMI_ID_TYPE) ((state) ? CHECKBOX_ON_IMAGE_ID : CHECKBOX_OFF_IMAGE_ID));
    return TRUE;
}

/**************************************************************************/
/*****************************SELECT CERTIFICATES**************************/
/**************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_pre_entry_certificates_selection_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_pre_entry_certificates_selection_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == mmi_certman_check_screen_in_history())
    {
        mmi_certman_history_replace(
            SCR_ID_CERTMAN_PROGRESS_SCREEN,
            SCR_ID_CERTMAN_SELECT_CERTIFICATE,
            mmi_certman_certificates_selection_list);
    }
    else
    {
        g_mmi_certman_context.screen_id = 0;
        mmi_certman_certificates_selection_list();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_certificates_selection_list
 * DESCRIPTION
 *  entry function for the selection of certificates
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_certificates_selection_list()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_certman_context.launch_select_context_p->certificate_count == 0)
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_EMPTY), NULL, NULL, MMI_CERTMAN_POPUP_DURATION, 0);
        mmi_certman_select_certificates_rsp(MMI_FALSE, 0, 0, g_mmi_certman_context.launch_select_context_p->trans_id);
        mmi_certman_launch_deinit();
        return;
    }
    mmi_certman_entry_new_screen(SCR_ID_CERTMAN_SELECT_CERTIFICATE, mmi_certman_certificates_selection_list);
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_certman_certificates_selection_list");
    gui_buffer = GetCurrGuiBuffer(SCR_ID_CERTMAN_SELECT_CERTIFICATE);
    if (g_mmi_certman_context.launch_select_context_p->multiple_selection_flag)
    {

        SetCheckboxToggleRightSoftkeyFunctions(
            mmi_certman_select_multiple_certificate,
            mmi_certman_exit_select_certificate);

        ShowCategory187Screen(
            STR_CERTMAN_CERTIFICATES,
            NULL,
            g_mmi_certman_context.launch_select_context_p->certificate_count,
            mmi_certman_input_cert_label,
            mmi_certman_get_item_img_hdlr,
            NULL,
            NULL,
            (U8*) g_mmi_certman_context.launch_select_context_p->is_selected,
            0,
            NULL,
            gui_buffer);

    }
    else
    {
        RegisterHighlightHandler(mmi_certman_certificate_list_highlight_handler);
        ShowCategory184Screen(
            STR_CERTMAN_CERTIFICATES,
            0,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            g_mmi_certman_context.launch_select_context_p->certificate_count,
            mmi_certman_get_certificates,
            NULL,
            0,
            gui_buffer);
        SetLeftSoftkeyFunction(mmi_certman_select_single_certificate, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_certman_exit_select_certificate, KEY_EVENT_UP);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_input_cert_label
 * DESCRIPTION
 *  function to get certificate label
 * PARAMETERS
 *  item_index      [IN]        
 *  str_buff        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_certman_input_cert_label(S32 item_index, UI_string_type str_buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy(
        (S8*) str_buff,
        (S8*) g_mmi_certman_context.launch_select_context_p->certificate_list[item_index].cert_label);
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_select_single_certificate
 * DESCRIPTION
 *  function to fill certficate id's of selected certificates in case of multiple_selection_flag=FALSE
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_select_single_certificate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index = g_mmi_certman_context.launch_select_context_p->selected_index;
    mmi_certman_certificate_ids_struct selected_certs;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_certman_select_single_certificate");
    selected_certs.count = 1;
    selected_certs.cert_ids[0] = g_mmi_certman_context.launch_select_context_p->certificate_list[index].cert_id;
    mmi_certman_select_certificates_rsp(
        MMI_TRUE,
        selected_certs.count,
        selected_certs.cert_ids,
        g_mmi_certman_context.launch_select_context_p->trans_id);
    mmi_certman_launch_deinit();
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_select_multiple_certificate
 * DESCRIPTION
 *  function to fill certficate id's of selected certificates  in case of multiple_selection_flag=TRUE
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_select_multiple_certificate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 temp_count = 0;
    mmi_certman_certificate_ids_struct selected_certs;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_certman_select_multiple_certificate");
    selected_certs.count = 0;
    for (temp_count = 0; temp_count < g_mmi_certman_context.launch_select_context_p->certificate_count; temp_count++)
    {
        if (g_mmi_certman_context.launch_select_context_p->is_selected[temp_count] == 1)
        {
            selected_certs.cert_ids[selected_certs.count] =
                g_mmi_certman_context.launch_select_context_p->certificate_list[temp_count].cert_id;
            selected_certs.count++;
        }

    }
    mmi_certman_select_certificates_rsp(
        MMI_TRUE,
        selected_certs.count,
        selected_certs.cert_ids,
        g_mmi_certman_context.launch_select_context_p->trans_id);
    mmi_certman_launch_deinit();
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_exit_select_certificate
 * DESCRIPTION
 *  function to exit select certificate
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_exit_select_certificate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_certman_select_certificates_rsp(MMI_FALSE, 0, 0, g_mmi_certman_context.launch_select_context_p->trans_id);
    mmi_certman_launch_deinit();
    GoBackHistory();
}

/*********************************************************************************/
/*****************************PRIVATE KEY PASSWORD REQUEST ***********************/
/*********************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_pre_entry_get_priv_key_password
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_pre_entry_get_priv_key_password(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_certman_context.screen_id = 0;
    memset(
        g_mmi_certman_context.priv_key_context_p->privatekey_pwd,
        0,
        sizeof(g_mmi_certman_context.priv_key_context_p->privatekey_pwd));
    mmi_certman_get_priv_key_password();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_get_priv_key_password
 * DESCRIPTION
 *  input function for private key pwd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_get_priv_key_password(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer; /* Buffer holding history data */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_certman_entry_new_screen(SCR_ID_CERTMAN_PRIVKEY_PASSWORD, mmi_certman_get_priv_key_password);
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_certman_launch_options");
    gui_buffer = GetCurrGuiBuffer(SCR_ID_CERTMAN_PRIVKEY_PASSWORD);
    RegisterInputBoxValidationFunction(mmi_certman_pwd_length_validation);
    enable_resized_small_screen();
    ShowCategory111Screen(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        STR_CERTMAN_INPUT_PASSWORD,
        INPUT_TYPE_ALPHANUMERIC_PASSWORD,
        g_mmi_certman_context.priv_key_context_p->privatekey_pwd,
        CERTMAN_PASSWORD_LENGTH,
        NULL,
        gui_buffer);
    SetLeftSoftkeyFunction(mmi_certman_get_priv_key_password_ok, KEY_EVENT_UP);
    SetCategory111RightSoftkeyFunction(mmi_certman_exit_priv_key_pwd_screen, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_exit_priv_key_pwd_screen
 * DESCRIPTION
 *  exit function for private key pwd screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_exit_priv_key_pwd_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackHistory();
    certman_send_privkey_usage_password_rsp(MOD_MMI, g_mmi_certman_context.priv_key_context_p->trans_id, MMI_FALSE);
    if (g_mmi_certman_context.priv_key_context_p)
    {
        mmi_certman_free(g_mmi_certman_context.priv_key_context_p);
        g_mmi_certman_context.priv_key_context_p = NULL;
    }
    g_mmi_certman_context.current_status = MMI_CERTMAN_IDLE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_get_priv_key_password_ok
 * DESCRIPTION
 *  LSK function for private key pwd screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_get_priv_key_password_ok(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackHistory();
    mmi_certman_check_priv_key_pwd();
    g_mmi_certman_context.current_status = MMI_CERTMAN_IDLE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_pwd_length_validation
 * DESCRIPTION
 *  function to check the pwd length
 * PARAMETERS
 *  text_p          [IN]        
 *  cursor_p        [IN]        
 *  length          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_pwd_length_validation(U8 *text_p, U8 *cursor_p, S32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((length) < 1)
    {
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_POUND, KEY_EVENT_UP);
    }
    else
    {
        EnableLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        SetKeyHandler(mmi_certman_check_priv_key_pwd, KEY_POUND, KEY_EVENT_UP);
    }

}

/*********************************************************************************/
/*****************************PRIVATE KEY CONFIRMATION****************************/
/*********************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_priv_key_confirmation
 * DESCRIPTION
 *  function for the private key confirmation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_priv_key_confirmation(void)
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
        L"Use Personal Certificate",
        IMG_GLOBAL_QUESTION,
        NULL);

    SetLeftSoftkeyFunction(mmi_certman_priv_key_confirmation_yes, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_certman_priv_key_confirmation_no, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_priv_key_confirmation_yes
 * DESCRIPTION
 *  function for positive confirmation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_priv_key_confirmation_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_certman_priv_key_confirmation_yes");
    GoBackHistory();
    certman_send_privkey_usage_confirm_rsp(MOD_MMI, g_mmi_certman_context.priv_key_context_p->trans_id, MMI_TRUE);
    if (g_mmi_certman_context.priv_key_context_p)
    {
        mmi_certman_free(g_mmi_certman_context.priv_key_context_p);
        g_mmi_certman_context.priv_key_context_p = NULL;
    }
    g_mmi_certman_context.current_status = MMI_CERTMAN_IDLE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_priv_key_confirmation_no
 * DESCRIPTION
 *  function to handle the rsk of confirmation screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_priv_key_confirmation_no(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_certman_priv_key_confirmation_no");
    GoBackHistory();
    certman_send_privkey_usage_confirm_rsp(MOD_MMI, g_mmi_certman_context.priv_key_context_p->trans_id, MMI_FALSE);
    if (g_mmi_certman_context.priv_key_context_p)
    {
        mmi_certman_free(g_mmi_certman_context.priv_key_context_p);
        g_mmi_certman_context.priv_key_context_p = NULL;
    }
    g_mmi_certman_context.current_status = MMI_CERTMAN_IDLE;
}

/***************************************************************************/
/*****************************VIEW / INVALID CERTIFICATE'S CONTENT ONLY*****/
/***************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_highlight_invalid_cert_install
 * DESCRIPTION
 *  This function is for highlight invalid certificate install
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_highlight_invalid_cert_install(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_certman_invalid_cert_install, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_highlight_invalid_cert_continue
 * DESCRIPTION
 *  This function is for highlight invalid certificate continue
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_highlight_invalid_cert_continue(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_certman_invalid_cert_continue, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_highlight_invalid_cert_cancel
 * DESCRIPTION
 *  This function is for highlight invalid certificate cancel
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_highlight_invalid_cert_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_certman_invalid_cert_cancel, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_pre_entry_view_certificate_contents_only
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_pre_entry_view_certificate_contents_only(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_certman_context.cert_info = (PU8) subMenuData;
    g_mmi_certman_context.cert_info[0] = 0;
    g_mmi_certman_context.cert_info[1] = 0;
    mmi_certman_fill_certificate_contents_only(
        g_mmi_certman_context.cert_info,
        &(g_mmi_certman_context.view_invalid_context_p->parsed_data_p->cert));

    certman_parsed_data_free(g_mmi_certman_context.view_invalid_context_p->parsed_data_p);
    if (MMI_TRUE == mmi_certman_check_screen_in_history())
    {
        mmi_certman_history_replace(
            SCR_ID_CERTMAN_PROGRESS_SCREEN,
            SCR_ID_CERTMAN_VIEW_CERTIFICATE_CONTENTS,
            mmi_certman_entry_view_certificate_contents_only);
    }
    else
    {
        g_mmi_certman_context.screen_id = 0;
        mmi_certman_entry_view_certificate_contents_only();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_entry_view_certificate_contents_only
 * DESCRIPTION
 *  entry function for view certificate contents only
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_entry_view_certificate_contents_only(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_buffer = GetCurrGuiBuffer(SCR_ID_CERTMAN_VIEW_CERTIFICATE_CONTENTS);
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_certman_entry_view_certificate_contents_only");
    mmi_certman_entry_new_screen(
        SCR_ID_CERTMAN_VIEW_CERTIFICATE_CONTENTS,
        mmi_certman_entry_view_certificate_contents_only);

    if (g_mmi_certman_context.current_status == MMI_CERTMAN_INVALID)
    {
        ShowCategory74Screen(
            STR_CERTMAN_CERTIFICATE_INFO,
            NULL,
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            g_mmi_certman_context.cert_info,
            mmi_ucs2strlen((const S8*)g_mmi_certman_context.cert_info),
            gui_buffer);
        SetLeftSoftkeyFunction(mmi_certman_invalid_certificate_option, KEY_EVENT_UP);
    }
    else
    {
        ShowCategory74Screen(
            STR_CERTMAN_CERTIFICATE_INFO,
            NULL,
            NULL,
            NULL,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            g_mmi_certman_context.cert_info,
            mmi_ucs2strlen((const S8*)g_mmi_certman_context.cert_info),
            gui_buffer);

    }
    SetRightSoftkeyFunction(mmi_certman_back_view_invalid_certificate_contents_only, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_back_view_invalid_certificate_contents_only
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_back_view_invalid_certificate_contents_only(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_certman_context.current_status == MMI_CERTMAN_INVALID)
    {
        mmi_certman_invalid_certificates_rsp(
            MMI_CERTMAN_INVALID_CERT_DENY,
            g_mmi_certman_context.view_invalid_context_p->trans_id);
    }
    mmi_certman_back_view_invalid_certificate_contents();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_invalid_certificate_option
 * DESCRIPTION
 *  Entry function to invalid certificate options
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_invalid_certificate_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    U16 nStrItemList[3];
    U16 num_of_items = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_certman_context.screen_id = 0;
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "Enters mmi_certman_invalid_certificate_option()");
    mmi_certman_entry_new_screen(SCR_ID_CERTMAN_INVALID_CERT_OPTION, mmi_certman_invalid_certificate_option);
    gui_buffer = GetCurrGuiBuffer(SCR_ID_CERTMAN_INVALID_CERT_OPTION);
    if (g_mmi_certman_context.view_invalid_context_p->install_option == MMI_TRUE)
    {
        num_of_items = GetNumOfChild(MENU_ID_CERTMAN_INVALID_OPTIONS2);
        GetSequenceStringIds(MENU_ID_CERTMAN_INVALID_OPTIONS2, nStrItemList);
        SetParentHandler(MENU_ID_CERTMAN_INVALID_OPTIONS2);
    }
    else
    {
        num_of_items = GetNumOfChild(MENU_ID_CERTMAN_INVALID_OPTIONS1);
        GetSequenceStringIds(MENU_ID_CERTMAN_INVALID_OPTIONS1, nStrItemList);
        SetParentHandler(MENU_ID_CERTMAN_INVALID_OPTIONS1);
    }
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ShowCategory15Screen(
        STR_CERTMAN_INVALID_CERTIFICATE,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        NULL,
        NULL,
        num_of_items,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        LIST_MENU,
        0,
        gui_buffer);
    //SetleftSoftkeyFunction(mmi_certman_, KEY_EVENT_UP);
    // mmi_certman_free(nStrItemList);
    // nStrItemList = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_invalid_cert_install
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_invalid_cert_install(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_certman_context.view_invalid_context_p->current_state = MMI_CERTMAN_VIEW_INVALID_CERT_LABEL;
    mmi_certman_view_invalid_state(NULL);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_pre_entry_invalid_cert_label
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_pre_entry_invalid_cert_label(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_certman_context.screen_id = 0;
    memset(g_mmi_certman_context.view_invalid_context_p->label, CERTMAN_LABEL_SIZE, 0);
    mmi_certman_input_invalid_cert_label();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_input_invalid_cert_label
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_input_invalid_cert_label(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_certman_entry_new_screen(SCR_ID_CERTMAN_INVALID_CERT_LABEL, mmi_certman_input_invalid_cert_label);
    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_CERTMAN_INVALID_CERT_LABEL);

    ShowCategory5Screen(
        STR_CERTMAN_CERTIFICATE_LABEL,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_CERTMAN_DISCARDED,
        0,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        (U8*) g_mmi_certman_context.view_invalid_context_p->label,
        CERTMAN_LABEL_LENGTH,
        gui_buffer_p);

    SetLeftSoftkeyFunction(mmi_certman_invalid_cert_check_label, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(mmi_certman_invalid_cert_cancel, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_invalid_cert_check_label
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_invalid_cert_check_label(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    certman_error_enum error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_certman_invalid_cert_check_label");
    g_mmi_certman_context.screen_id = 0;

    error = certman_import_check_label_exists(g_mmi_certman_context.view_invalid_context_p->label, CERTMAN_DCS_UCS2);
    switch (error)
    {
        case CERTMAN_ERR_LABEL_EXISTS:
            g_mmi_certman_context.view_invalid_context_p->current_state = MMI_CERTMAN_VIEW_INVALID_CERT_LABEL;
            mmi_certman_view_invalid_state(NULL);
            mmi_certman_handle_error(error);
            break;
        case CERTMAN_ERR_INVALID_LABEL:
            g_mmi_certman_context.view_invalid_context_p->current_state = MMI_CERTMAN_VIEW_INVALID_CERT_LABEL;
            mmi_certman_view_invalid_state(NULL);
            mmi_certman_handle_error(error);
            break;
        default:

            error = certman_ctx_import_new(
                        g_mmi_certman_context.view_invalid_context_p->job_id,
                        g_mmi_certman_context.view_invalid_context_p->ref_id,
                        &(g_mmi_certman_context.view_invalid_context_p->ctx_import_p));

            error = certman_import_set_label(
                        g_mmi_certman_context.view_invalid_context_p->ctx_import_p,
                        g_mmi_certman_context.view_invalid_context_p->label,
                        CERTMAN_DCS_UCS2);
            /* mmi_certman_progress_screen(); */

            ASSERT(error <= CERTMAN_ERR_NONE);
            g_mmi_certman_context.view_invalid_context_p->current_state = MMI_CERTMAN_VIEW_INVALID_IMPORT;
            mmi_certman_progress_screen();
            certman_send_import_req(
                MOD_MMI,
                g_mmi_certman_context.view_invalid_context_p->trans_id,
                g_mmi_certman_context.view_invalid_context_p->ctx_import_p);

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_invalid_cert_continue
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_invalid_cert_continue(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_certman_context.screen_id = 0;
    mmi_certman_back_view_invalid_certificate_contents();
    mmi_certman_invalid_certificates_rsp(
        MMI_CERTMAN_INVALID_CERT_ACCEPT,
        g_mmi_certman_context.view_invalid_context_p->trans_id);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_invalid_cert_cancel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_invalid_cert_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_certman_back_view_invalid_certificate_contents();
    mmi_certman_invalid_certificates_rsp(
        MMI_CERTMAN_INVALID_CERT_DENY,
        g_mmi_certman_context.view_invalid_context_p->trans_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_back_view_invalid_certificate_contents
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_back_view_invalid_certificate_contents(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* mmi_certman_progress_screen(); */
    g_mmi_certman_context.view_invalid_context_p->current_state = MMI_CERTMAN_VIEW_INVALID_PARSE_END;
    g_mmi_certman_context.screen_id = 0;
    mmi_certman_progress_screen();
    certman_send_parse_end_req(
        MOD_MMI,
        g_mmi_certman_context.view_invalid_context_p->trans_id,
        (kal_uint16) g_mmi_certman_context.view_invalid_context_p->job_id);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_exit_view_invalid_certificate_contents_only_with_gobackhistory
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_exit_view_invalid_certificate_contents_only_with_gobackhistory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackHistory();
    mmi_certman_exit_view_invalid_certificate_contents_only();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_fill_certificate_contents_only
 * DESCRIPTION
 *  function to fill the certificate contents in case of view
 * PARAMETERS
 *  cert_info           [IN]        
 *  display_cert        [?]         [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_fill_certificate_contents_only(U8 *cert_info, certman_cert_display_struct *display_cert)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 temp_buffer1[20];
    U8 temp_buffer2[10];
    U8 temp_array[MMI_CERTMAN_MAX_FIELD_SIZE];
    S32 buff_length;

    memset(cert_info, 0, 2);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_certman_fill_certificate_contents_only");
    buff_length = MAX_SUB_MENUS * MAX_SUB_MENU_SIZE;
    if (g_mmi_certman_context.current_status == MMI_CERTMAN_INVALID)
    {
        U16 error_str_id;

        mmi_ucs2ncat((PS8) cert_info, (PS8) GetString(STR_CERTMAN_INVALID_CERT_ERROR), buff_length);
        buff_length = (buff_length -=
                       ENCODING_LENGTH * mmi_ucs2strlen((S8*) GetString(STR_CERTMAN_INVALID_CERT_ERROR))) >
            0 ? buff_length : 0;

        mmi_ucs2ncat((PS8) cert_info, (PS8) L":\n", buff_length);
        buff_length = (buff_length -= ENCODING_LENGTH * mmi_ucs2strlen((S8*) L":\n")) > 0 ? buff_length : 0;

        error_str_id = mmi_certman_error_string_id();
        mmi_ucs2ncat((PS8) cert_info, (PS8) GetString(error_str_id), buff_length);
        buff_length = (buff_length -=
                       ENCODING_LENGTH * mmi_ucs2strlen((S8*) GetString(error_str_id))) > 0 ? buff_length : 0;

        mmi_ucs2ncat((PS8) cert_info, (PS8) L"\n\n", buff_length);
        buff_length = (buff_length -= ENCODING_LENGTH * mmi_ucs2strlen((S8*) L"\n\n")) > 0 ? buff_length : 0;

        mmi_ucs2ncat((PS8) cert_info, (PS8) GetString(STR_CERTMAN_CERTIFICATE_DETAILS), buff_length);
        buff_length = (buff_length -=
                       ENCODING_LENGTH * mmi_ucs2strlen((S8*) GetString(STR_CERTMAN_CERTIFICATE_DETAILS))) >
            0 ? buff_length : 0;

        mmi_ucs2ncat((PS8) cert_info, (PS8) L"\n ", buff_length);
        buff_length = (buff_length -= ENCODING_LENGTH * mmi_ucs2strlen((S8*) L"\n ")) > 0 ? buff_length : 0;

    }
    /* Certificate Label */
    if (g_mmi_certman_context.current_status != MMI_CERTMAN_IMPORT && display_cert->label)
    {
        mmi_ucs2ncat((PS8) cert_info, (PS8) GetString(STR_CERTMAN_CERTIFICATE_LABEL), buff_length);
        buff_length = (buff_length -=
                       ENCODING_LENGTH * mmi_ucs2strlen((S8*) GetString(STR_CERTMAN_CERTIFICATE_LABEL))) > 0 ? buff_length : 0;

        mmi_ucs2ncat((PS8) cert_info, (PS8) L":  ", buff_length);
        buff_length = (buff_length -= ENCODING_LENGTH * mmi_ucs2strlen((S8*) L":  ")) > 0 ? buff_length : 0;

        mmi_ucs2ncat((PS8) cert_info, (PS8) L"\n", buff_length);
        buff_length = (buff_length -= ENCODING_LENGTH * mmi_ucs2strlen((S8*) L"\n")) > 0 ? buff_length : 0;

        memset(temp_array, 0, 2);
        mmi_certman_cert_strncpy(temp_array, display_cert->label, display_cert->dcs_label, MMI_CERTMAN_MAX_FIELD_SIZE);
        mmi_ucs2ncat((PS8) cert_info, (PS8) temp_array, buff_length);
        buff_length = (buff_length -=
                       ENCODING_LENGTH * mmi_ucs2strlen((S8*) GetString(STR_CERTMAN_FILE_CONTAINS))) > 0 ? buff_length : 0;

        mmi_ucs2ncat((PS8) cert_info, (PS8) L"\n\n", buff_length);
        buff_length = (buff_length -= ENCODING_LENGTH * mmi_ucs2strlen((S8*) L"\n\n")) > 0 ? buff_length : 0;
    }

    /* Certificate Serial no. */
    if (display_cert->serial)
    {
        U32 counter;
        U8 temp_array1[40] = {0, };
        mmi_ucs2ncat((PS8) cert_info, (PS8) GetString(STR_CERTMAN_CERT_SERIAL_NO), buff_length);
        buff_length = (buff_length -=
                       ENCODING_LENGTH * mmi_ucs2strlen((S8*) GetString(STR_CERTMAN_CERT_SERIAL_NO))) >
            0 ? buff_length : 0;

        mmi_ucs2ncat((PS8) cert_info, (PS8) L":  ", buff_length);
        buff_length = (buff_length -= ENCODING_LENGTH * mmi_ucs2strlen((S8*) L":  ")) > 0 ? buff_length : 0;

        mmi_ucs2ncat((PS8) cert_info, (PS8) L"\n", buff_length);
        buff_length = (buff_length -= ENCODING_LENGTH * mmi_ucs2strlen((S8*) L"\n")) > 0 ? buff_length : 0;
        for (counter = 0; counter < display_cert->serial_size; counter++)
        {
            sprintf((S8*) temp_buffer2, "%x", display_cert->serial[counter]);
            strcat((S8*) temp_array1, (S8*) temp_buffer2);
        }
        mmi_asc_to_ucs2((PS8) temp_array, (PS8) temp_array1);
        mmi_ucs2ncat((PS8) cert_info, (PS8) temp_array, buff_length);
        buff_length = (buff_length -= ENCODING_LENGTH * mmi_ucs2strlen((S8*) temp_array)) > 0 ? buff_length : 0;

        mmi_ucs2ncat((PS8) cert_info, (PS8) L"\n\n", buff_length);
        buff_length = (buff_length -= ENCODING_LENGTH * mmi_ucs2strlen((S8*) L"\n\n")) > 0 ? buff_length : 0;
    }

    /* Certificate Version */

    if (display_cert->version)
    {
        mmi_ucs2ncat((PS8) cert_info, (PS8) GetString(STR_CERTMAN_CERT_VERSION), buff_length);
        buff_length = (buff_length -=
                       ENCODING_LENGTH * mmi_ucs2strlen((S8*) GetString(STR_CERTMAN_CERT_VERSION))) > 0 ? buff_length : 0;

        mmi_ucs2ncat((PS8) cert_info, (PS8) L":  ", buff_length);
        buff_length = (buff_length -= ENCODING_LENGTH * mmi_ucs2strlen((S8*) L":  ")) > 0 ? buff_length : 0;

        mmi_ucs2ncat((PS8) cert_info, (PS8) L"\n", buff_length);
        buff_length = (buff_length -= ENCODING_LENGTH * mmi_ucs2strlen((S8*) L"\n")) > 0 ? buff_length : 0;

        sprintf((PS8) temp_buffer1, "%d", display_cert->version);
        mmi_asc_to_ucs2((PS8) temp_buffer2, (PS8) temp_buffer1);
        mmi_ucs2ncat((PS8) cert_info, (PS8) temp_buffer2, buff_length);
        buff_length = (buff_length -= ENCODING_LENGTH * mmi_ucs2strlen((S8*) temp_buffer2)) > 0 ? buff_length : 0;

        mmi_ucs2ncat((PS8) cert_info, (PS8) L"\n\n", buff_length);
        buff_length = (buff_length -= ENCODING_LENGTH * mmi_ucs2strlen((S8*) L"\n\n")) > 0 ? buff_length : 0;
    }
    /* Certificate Issuer */
    mmi_ucs2ncat((PS8) cert_info, (PS8) GetString(STR_CERTMAN_CERT_ISSUER), buff_length);
    buff_length = (buff_length -=
                   ENCODING_LENGTH * mmi_ucs2strlen((S8*) GetString(STR_CERTMAN_CERT_ISSUER))) > 0 ? buff_length : 0;

    mmi_ucs2ncat((PS8) cert_info, (PS8) L":  ", buff_length);
    buff_length = (buff_length -= ENCODING_LENGTH * mmi_ucs2strlen((S8*) L":  ")) > 0 ? buff_length : 0;

    mmi_ucs2ncat((PS8) cert_info, (PS8) L"\n", buff_length);
    buff_length = (buff_length -= ENCODING_LENGTH * mmi_ucs2strlen((S8*) L"\n")) > 0 ? buff_length : 0;

    /* Certificate Issuer Common Name */
    if (display_cert->issuer.names[CERTMAN_NAMETYPE_COMMON_NAME])
    {
        memset(temp_array, 0, 2);
        mmi_certman_cert_strncpy(
            temp_array,
            display_cert->issuer.names[CERTMAN_NAMETYPE_COMMON_NAME],
            display_cert->issuer.dcs[CERTMAN_NAMETYPE_COMMON_NAME],
            MMI_CERTMAN_MAX_FIELD_SIZE);
        mmi_ucs2ncat((PS8) cert_info, (PS8) temp_array, buff_length);
        buff_length = (buff_length -= ENCODING_LENGTH * mmi_ucs2strlen((S8*) temp_array)) > 0 ? buff_length : 0;

        mmi_ucs2ncat((PS8) cert_info, (PS8) L"\n", buff_length);
        buff_length = (buff_length -= ENCODING_LENGTH * mmi_ucs2strlen((S8*) L"\n")) > 0 ? buff_length : 0;
    }

    /* Certificate Issuer Orgainization */

    if (display_cert->issuer.names[CERTMAN_NAMETYPE_ORGANISATION])
    {
        memset(temp_array, 0, 2);
        mmi_certman_cert_strncpy(
            temp_array,
            display_cert->issuer.names[CERTMAN_NAMETYPE_ORGANISATION],
            display_cert->issuer.dcs[CERTMAN_NAMETYPE_ORGANISATION],
            MMI_CERTMAN_MAX_FIELD_SIZE);
        mmi_ucs2ncat((PS8) cert_info, (PS8) temp_array, buff_length);
        buff_length = (buff_length -= ENCODING_LENGTH * mmi_ucs2strlen((S8*) temp_array)) > 0 ? buff_length : 0;

        mmi_ucs2ncat((PS8) cert_info, (PS8) L"\n", buff_length);
        buff_length = (buff_length -= ENCODING_LENGTH * mmi_ucs2strlen((S8*) L"\n")) > 0 ? buff_length : 0;

    }

    /* Certificate Issuer Country */
    if (display_cert->issuer.names[CERTMAN_NAMETYPE_COUNTRY])
    {
        memset(temp_array, 0, 2);
        mmi_certman_cert_strncpy(
            temp_array,
            display_cert->issuer.names[CERTMAN_NAMETYPE_COUNTRY],
            display_cert->issuer.dcs[CERTMAN_NAMETYPE_COUNTRY],
            MMI_CERTMAN_MAX_FIELD_SIZE);
        mmi_ucs2ncat((PS8) cert_info, (PS8) temp_array, buff_length);
        buff_length = (buff_length -= ENCODING_LENGTH * mmi_ucs2strlen((S8*) temp_array)) > 0 ? buff_length : 0;

        mmi_ucs2ncat((PS8) cert_info, (PS8) L"\n\n", buff_length);
        buff_length = (buff_length -= ENCODING_LENGTH * mmi_ucs2strlen((S8*) L"\n\n")) > 0 ? buff_length : 0;

    }

    /* Certificate Subject */

    mmi_ucs2ncat((PS8) cert_info, (PS8) GetString(STR_CERTMAN_CERT_SUBJECT), buff_length);
    buff_length = (buff_length -=
                   ENCODING_LENGTH * mmi_ucs2strlen((S8*) GetString(STR_CERTMAN_CERT_SUBJECT))) > 0 ? buff_length : 0;

    mmi_ucs2ncat((PS8) cert_info, (PS8) L":  ", buff_length);
    buff_length = (buff_length -= ENCODING_LENGTH * mmi_ucs2strlen((S8*) L":  ")) > 0 ? buff_length : 0;

    mmi_ucs2ncat((PS8) cert_info, (PS8) L"\n", buff_length);
    buff_length = (buff_length -= ENCODING_LENGTH * mmi_ucs2strlen((S8*) L"\n")) > 0 ? buff_length : 0;

    /* Certificate Subject Common Name */
    if (display_cert->subject.names[CERTMAN_NAMETYPE_COMMON_NAME])
    {
        memset(temp_array, 0, 2);
        mmi_certman_cert_strncpy(
            temp_array,
            display_cert->subject.names[CERTMAN_NAMETYPE_COMMON_NAME],
            display_cert->subject.dcs[CERTMAN_NAMETYPE_COMMON_NAME],
            MMI_CERTMAN_MAX_FIELD_SIZE);
        mmi_ucs2ncat((PS8) cert_info, (PS8) temp_array, buff_length);
        buff_length = (buff_length -= ENCODING_LENGTH * mmi_ucs2strlen((S8*) temp_array)) > 0 ? buff_length : 0;

        mmi_ucs2ncat((PS8) cert_info, (PS8) L"\n", buff_length);
        buff_length = (buff_length -= ENCODING_LENGTH * mmi_ucs2strlen((S8*) L"\n")) > 0 ? buff_length : 0;
    }

    /* Certificate subject Orgainization */

    if (display_cert->subject.names[CERTMAN_NAMETYPE_ORGANISATION])
    {
        memset(temp_array, 0, 2);
        mmi_certman_cert_strncpy(
            temp_array,
            display_cert->subject.names[CERTMAN_NAMETYPE_ORGANISATION],
            display_cert->subject.dcs[CERTMAN_NAMETYPE_ORGANISATION],
            MMI_CERTMAN_MAX_FIELD_SIZE);
        mmi_ucs2ncat((PS8) cert_info, (PS8) temp_array, buff_length);
        buff_length = (buff_length -= ENCODING_LENGTH * mmi_ucs2strlen((S8*) temp_array)) > 0 ? buff_length : 0;

        mmi_ucs2ncat((PS8) cert_info, (PS8) L"\n", buff_length);
        buff_length = (buff_length -= ENCODING_LENGTH * mmi_ucs2strlen((S8*) L"\n")) > 0 ? buff_length : 0;

    }

    /* Certificate subject Country */
    if (display_cert->subject.names[CERTMAN_NAMETYPE_COUNTRY])
    {
        memset(temp_array, 0, 2);
        mmi_certman_cert_strncpy(
            temp_array,
            display_cert->subject.names[CERTMAN_NAMETYPE_COUNTRY],
            display_cert->subject.dcs[CERTMAN_NAMETYPE_COUNTRY],
            MMI_CERTMAN_MAX_FIELD_SIZE);
        mmi_ucs2ncat((PS8) cert_info, (PS8) temp_array, buff_length);
        buff_length = (buff_length -= ENCODING_LENGTH * mmi_ucs2strlen((S8*) temp_array)) > 0 ? buff_length : 0;

        mmi_ucs2ncat((PS8) cert_info, (PS8) L"\n\n", buff_length);
        buff_length = (buff_length -= ENCODING_LENGTH * mmi_ucs2strlen((S8*) L"\n\n")) > 0 ? buff_length : 0;
    }

    /* Certificate Valid From */
    mmi_ucs2ncat((PS8) cert_info, (PS8) GetString(STR_CERTMAN_CERT_VALID_FROM), buff_length);
    buff_length = (buff_length -=
                   ENCODING_LENGTH * mmi_ucs2strlen((S8*) GetString(STR_CERTMAN_CERT_VALID_FROM))) > 0 ? buff_length : 0;

    mmi_ucs2ncat((PS8) cert_info, (PS8) L":  ", buff_length);
    buff_length = (buff_length -= ENCODING_LENGTH * mmi_ucs2strlen((S8*) L":  ")) > 0 ? buff_length : 0;

    mmi_ucs2ncat((PS8) cert_info, (PS8) L"\n", buff_length);
    buff_length = (buff_length -= ENCODING_LENGTH * mmi_ucs2strlen((S8*) L"\n")) > 0 ? buff_length : 0;

    sprintf(
        (S8*) temp_buffer1,
        "%d-%d-%d",
        display_cert->valid_from.nDay,
        display_cert->valid_from.nMonth,
        display_cert->valid_from.nYear);
    mmi_asc_to_ucs2((PS8) temp_array, (PS8) temp_buffer1);
    mmi_ucs2ncat((PS8) cert_info, (PS8) temp_array, buff_length);
    buff_length = (buff_length -= ENCODING_LENGTH * mmi_ucs2strlen((S8*) temp_array)) > 0 ? buff_length : 0;

    mmi_ucs2ncat((PS8) cert_info, (PS8) L"\n\n", buff_length);
    buff_length = (buff_length -= ENCODING_LENGTH * mmi_ucs2strlen((S8*) L"\n\n")) > 0 ? buff_length : 0;

    /* Certificate valid Upto */

    mmi_ucs2ncat((PS8) cert_info, (PS8) GetString(STR_CERTMAN_CERT_VALID_UPTO), buff_length);
    buff_length = (buff_length -=
                   ENCODING_LENGTH * mmi_ucs2strlen((S8*) GetString(STR_CERTMAN_CERT_VALID_UPTO))) > 0 ? buff_length : 0;

    mmi_ucs2ncat((PS8) cert_info, (PS8) L":  ", buff_length);
    buff_length = (buff_length -= ENCODING_LENGTH * mmi_ucs2strlen((S8*) L":  ")) > 0 ? buff_length : 0;

    mmi_ucs2ncat((PS8) cert_info, (PS8) L"\n", buff_length);
    buff_length = (buff_length -= ENCODING_LENGTH * mmi_ucs2strlen((S8*) L"\n")) > 0 ? buff_length : 0;

    sprintf(
        (S8*) temp_buffer1,
        "%d-%d-%d",
        display_cert->valid_until.nDay,
        display_cert->valid_until.nMonth,
        display_cert->valid_until.nYear);
    mmi_asc_to_ucs2((PS8) temp_array, (PS8) temp_buffer1);
    mmi_ucs2ncat((PS8) cert_info, (PS8) temp_array, buff_length);
    buff_length = (buff_length -= ENCODING_LENGTH * mmi_ucs2strlen((S8*) temp_array)) > 0 ? buff_length : 0;

    mmi_ucs2ncat((PS8) cert_info, (PS8) L"\n\n", buff_length);
    buff_length = (buff_length -= ENCODING_LENGTH * mmi_ucs2strlen((S8*) L"\n\n")) > 0 ? buff_length : 0;
    /* Certificate Finger Print */
    mmi_ucs2ncat((PS8) cert_info, (PS8) GetString(STR_CERTMAN_CERT_FINGER_PRINT), buff_length);
    buff_length = (buff_length -=
                   ENCODING_LENGTH * mmi_ucs2strlen((S8*) GetString(STR_CERTMAN_CERT_FINGER_PRINT))) > 0 ? buff_length : 0;

    mmi_ucs2ncat((PS8) cert_info, (PS8) L":  ", buff_length);
    buff_length = (buff_length -= ENCODING_LENGTH * mmi_ucs2strlen((S8*) L":  ")) > 0 ? buff_length : 0;

    mmi_ucs2ncat((PS8) cert_info, (PS8) L"\n", buff_length);
    buff_length = (buff_length -= ENCODING_LENGTH * mmi_ucs2strlen((S8*) L"\n")) > 0 ? buff_length : 0;

    if (display_cert->fngrprt_sha1)
    {
        U32 counter;
        U8 temp_array1[40] = {0, };
        for (counter = 0; counter < CERTMAN_SHA1_SIZE; counter++)
        {
            sprintf((S8*) temp_buffer2, "%x", display_cert->fngrprt_sha1[counter]);
            strcat((S8*) temp_array1, (S8*) temp_buffer2);
        }
        mmi_asc_to_ucs2((PS8) temp_array, (PS8) temp_array1);
        mmi_ucs2ncat((PS8) cert_info, (PS8) temp_array, buff_length);
        buff_length = (buff_length -= ENCODING_LENGTH * mmi_ucs2strlen((S8*) temp_array)) > 0 ? buff_length : 0;

        mmi_ucs2ncat((PS8) cert_info, (PS8) L"\n\n", buff_length);
        buff_length = (buff_length -= ENCODING_LENGTH * mmi_ucs2strlen((S8*) L"\n\n")) > 0 ? buff_length : 0;

    }
    /* Certificate Type */
    mmi_ucs2ncat((PS8) cert_info, (PS8) GetString(STR_CERTMAN_CERT_TYPE), buff_length);
    buff_length = (buff_length -=
                   ENCODING_LENGTH * mmi_ucs2strlen((S8*) GetString(STR_CERTMAN_CERT_TYPE))) > 0 ? buff_length : 0;

    mmi_ucs2ncat((PS8) cert_info, (PS8) L":  ", buff_length);
    buff_length = (buff_length -= ENCODING_LENGTH * mmi_ucs2strlen((S8*) L":  ")) > 0 ? buff_length : 0;

    mmi_ucs2ncat((PS8) cert_info, (PS8) L"\n", buff_length);
    buff_length = (buff_length -= ENCODING_LENGTH * mmi_ucs2strlen((S8*) L"\n")) > 0 ? buff_length : 0;

    if (display_cert->cert_type == CERTMAN_CERTTYPE_X509)
    {
        //mmi_ucs2ncat((PS8) cert_info, (PS8) GetString(STR_CERTMAN_CERT_TYPE), buff_length);
        //buff_length = (buff_length -= ENCODING_LENGTH * mmi_ucs2strlen((S8*) GetString(STR_CERTMAN_CERT_TYPE))) > 0 ? buff_length : 0;

        mmi_ucs2ncat((PS8) cert_info, (PS8) GetString(STR_CERTMAN_CERTTYPE_X509), buff_length);
        buff_length = (buff_length -=
                       ENCODING_LENGTH * mmi_ucs2strlen((S8*) GetString(STR_CERTMAN_CERTTYPE_X509))) > 0 ? buff_length : 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_error_string_id
 * DESCRIPTION
 *  function for error string
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U32 mmi_certman_error_string_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 error_string = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_mmi_certman_context.view_invalid_context_p->error & MMI_CERTMAN_WARN_BCONST_NOT_CRITICAL) ==
        MMI_CERTMAN_WARN_BCONST_NOT_CRITICAL)
    {
        error_string = STR_CERTMAN_WARN_BCONST_NOT_CRITICAL;
    }
    if ((g_mmi_certman_context.view_invalid_context_p->error & MMI_CERTMAN_WARN_UNKNOWN_CRITICAL_EXT) ==
        MMI_CERTMAN_WARN_UNKNOWN_CRITICAL_EXT)
    {
        error_string = STR_CERTMAN_WARN_UNKNOWN_CRITICAL_EXT;
    }
    if ((g_mmi_certman_context.view_invalid_context_p->error & MMI_CERTMAN_WARN_VALIDITY) == MMI_CERTMAN_WARN_VALIDITY)
    {
        error_string = STR_CERTMAN_WARN_VALIDITY;
    }
    if ((g_mmi_certman_context.view_invalid_context_p->error & MMI_CERTMAN_WARN_KEY_MISUSE) ==
        MMI_CERTMAN_WARN_KEY_MISUSE)
    {
        error_string = STR_CERTMAN_WARN_KEY_MISUSE;
    }
    if ((g_mmi_certman_context.view_invalid_context_p->error & MMI_CERTMAN_WARN_INVALID_SIGNATURE) ==
        MMI_CERTMAN_WARN_INVALID_SIGNATURE)
    {
        error_string = STR_CERTMAN_WARN_INVALID_SIGNATURE;
    }
    if ((g_mmi_certman_context.view_invalid_context_p->error & MMI_CERTMAN_WARN_CORRUPTED_CERT) ==
        MMI_CERTMAN_WARN_CORRUPTED_CERT)
    {
        error_string = STR_CERTMAN_WARN_CORRUPTED_CERT;
    }
    if ((g_mmi_certman_context.view_invalid_context_p->error & MMI_CERTMAN_WARN_TRUSTED_NO_KEY_USAGE) ==
        MMI_CERTMAN_WARN_TRUSTED_NO_KEY_USAGE)
    {
        error_string = STR_CERTMAN_WARN_TRUSTED_NO_KEY_USAGE;
    }
    if ((g_mmi_certman_context.view_invalid_context_p->error & MMI_CERTMAN_WARN_NO_CERT_HASH) ==
        MMI_CERTMAN_WARN_NO_CERT_HASH)
    {
        error_string = STR_CERTMAN_WARN_NO_CERT_HASH;
    }
    if ((g_mmi_certman_context.view_invalid_context_p->error & MMI_CERTMAN_WARN_URLS_DONT_MATCH) ==
        MMI_CERTMAN_WARN_URLS_DONT_MATCH)
    {
        error_string = STR_CERTMAN_WARN_URLS_DONT_MATCH;
    }
    if ((g_mmi_certman_context.view_invalid_context_p->error & MMI_CERTMAN_WARN_NO_TRUSTED_CERTS) ==
        MMI_CERTMAN_WARN_NO_TRUSTED_CERTS)
    {
        error_string = STR_CERTMAN_WARN_NO_TRUSTED_CERTS;
    }
    if ((g_mmi_certman_context.view_invalid_context_p->error & MMI_CERTMAN_WARN_TRUSTED_EXPIRED) ==
        MMI_CERTMAN_WARN_TRUSTED_EXPIRED)
    {
        error_string = STR_CERTMAN_WARN_TRUSTED_EXPIRED;
    }

    return error_string;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_progress_screen
 * DESCRIPTION
 *  entry function for progress screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_progress_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_certman_entry_new_screen(SCR_ID_CERTMAN_PROGRESS_SCREEN, mmi_certman_progress_screen);
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_certman_progress_screen");
    /* EntryNewScreen(SCR_ID_CERTMAN_PROGRESS_SCREEN, NULL, mmi_certman_progress_screen, NULL); */

    // TODO::put an animated image
    ShowCategory66Screen(
        NULL,
        NULL,   /* GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID), */
        0,
        0,
        0,
        0,
        (U8*) GetString(STR_GLOBAL_PLEASE_WAIT),
        IMG_GLOBAL_PROGRESS,
        NULL);

    ClearAllKeyHandler();
    /* End key is still valid */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_entry_new_screen
 * DESCRIPTION
 *  wrapper for entry new screen
 * PARAMETERS
 *  newscrnID       [IN]        
 *  handler         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_entry_new_screen(U16 newscrnID, FuncPtr handler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(newscrnID, mmi_certman_generic_exit_handler, NULL, NULL);
    g_mmi_certman_context.screen_id = newscrnID;
    g_mmi_certman_context.entry_fun = handler;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_generic_exit_handler
 * DESCRIPTION
 *  generic exit handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_generic_exit_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    U16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_certman_context.screen_id != 0)
    {
        h.scrnID = g_mmi_certman_context.screen_id;
        h.entryFuncPtr = g_mmi_certman_context.entry_fun;
        mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & nHistory);
        GetCategoryHistory(h.guiBuffer);
        AddHistory(h);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_history_replace
 * DESCRIPTION
 *  
 * PARAMETERS
 *  out_scrn_id     [IN]        
 *  in_scrn_id      [IN]        
 *  in_src_func     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_history_replace(U16 out_scrn_id, U16 in_scrn_id, FuncPtr in_src_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    HistoryReplace(out_scrn_id, in_scrn_id, in_src_func);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_category57_entry_new_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  newscrnID       [IN]        
 *  handler         [IN]        [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_category57_entry_new_screen(U16 newscrnID, FuncPtr handler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(newscrnID, mmi_certman_category57_exit_handler, NULL, NULL);
    g_mmi_certman_context.screen_id = newscrnID;
    g_mmi_certman_context.entry_fun = handler;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_category57_exit_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_category57_exit_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    U16 input_buffer_size = 0;
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_certman_context.screen_id != 0)
    {
        h.scrnID = g_mmi_certman_context.screen_id;
        CloseCategory57Screen();
        h.entryFuncPtr = g_mmi_certman_context.entry_fun;
        mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & nHistory);
        GetCategory57History(h.guiBuffer);
        input_buffer_size = (U16) GetCategory57DataSize();
        GetCategory57Data((U8*) h.inputBuffer);
        AddNHistory(h, input_buffer_size);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_check_screen_in_history
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
pBOOL mmi_certman_check_screen_in_history()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetActiveScreenId() != SCR_ID_CERTMAN_PROGRESS_SCREEN)
    {
        if ((IsScreenPresent(SCR_ID_CERTMAN_PROGRESS_SCREEN) == MMI_TRUE))
        {
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_check_detail_history
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
pBOOL mmi_certman_check_detail_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((GetActiveScreenId() != SCR_ID_CERTMAN_PROGRESS_SCREEN)
        && (IsScreenPresent(SCR_ID_CERTMAN_PROGRESS_SCREEN) == MMI_FALSE))
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_import_incorrect_pwd_continue
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_import_incorrect_pwd_continue(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_certman_context.screen_id = 0;
    mmi_certman_import_state(NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_full_screen_popup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_full_screen_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_certman_entry_new_screen(SCR_ID_CERTMAN_FULL_SCREEN_POPUP, mmi_certman_full_screen_popup);
    ShowCategory2Screen(
        STR_CERTMAN_CERTIFICATE_INFO,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        0,
        0,
        g_mmi_certman_context.popup_string_id,
        NULL);

    SetLeftSoftkeyFunction(mmi_certman_full_screen_continue, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_full_screen_continue
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_full_screen_continue(void)
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
 *  mmi_certman_incorrect_pwd_screen_popup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_incorrect_pwd_screen_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_certman_entry_new_screen(SCR_ID_CERTMAN_INCORRECT_PWD_SCREEN_POPUP, mmi_certman_incorrect_pwd_screen_popup);
    ShowCategory2Screen(
        STR_CERTMAN_CERTIFICATE_INFO,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        0,
        0,
        g_mmi_certman_context.popup_string_id,
        NULL);

    SetLeftSoftkeyFunction(mmi_certman_import_incorrect_pwd_continue, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_handle_error_with_callback
 * DESCRIPTION
 *  common function to handle error with callback
 * PARAMETERS
 *  error           [IN]        
 *  callback        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_handle_error_with_callback(certman_error_enum error, FuncPtr callback)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 image_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_certman_handle_error");

    switch (error)
    {
        case CERTMAN_ERR_MEMFULL:
            g_mmi_certman_context.popup_string_id = STR_CERTMAN_MEMORY_FULL;
            image_id = IMG_GLOBAL_ERROR;
            break;
        case CERTMAN_ERR_INVALID_CONTEXT:
            g_mmi_certman_context.popup_string_id = STR_CERTMAN_INVALID_CONTEXT;
            image_id = IMG_GLOBAL_ERROR;
            break;
        case CERTMAN_ERR_FILE_NOT_FOUND:
            g_mmi_certman_context.popup_string_id = FMGR_FS_FILE_NOT_FOUND_TEXT;
            image_id = IMG_GLOBAL_ERROR;
            break;
        case CERTMAN_ERR_FS_ERROR:
            g_mmi_certman_context.popup_string_id = STR_CERTMAN_FILE_ERROR;
            image_id = IMG_GLOBAL_ERROR;
            break;
        case CERTMAN_ERR_INVALID_ENCODING:
            g_mmi_certman_context.popup_string_id = STR_CERTMAN_INVALID_ENCODING;
            image_id = IMG_GLOBAL_ERROR;
            break;
        case CERTMAN_ERR_UNSUPPORTED_CONTENT:
            g_mmi_certman_context.popup_string_id = STR_GLOBAL_UNSUPPORTED_FORMAT;
            image_id = IMG_GLOBAL_ERROR;
            break;
        case CERTMAN_ERR_INCORRECT_PASSWORD:
        {
            if (MMI_TRUE == mmi_certman_check_screen_in_history())
            {
                g_mmi_certman_context.popup_string_id = STR_CERTMAN_INCORRECT_PASSWORD;
                mmi_certman_history_replace(
                    SCR_ID_CERTMAN_PROGRESS_SCREEN,
                    SCR_ID_CERTMAN_INCORRECT_PWD_SCREEN_POPUP,
                    mmi_certman_incorrect_pwd_screen_popup);
            }
            else
            {
                DisplayPopup(
                    (PU8) GetString(STR_CERTMAN_INCORRECT_PASSWORD),
                    IMG_GLOBAL_ERROR,
                    NULL,
                    MMI_CERTMAN_POPUP_DURATION,
                    0);
            }
            return;
        }
            break;
        case CERTMAN_ERR_NEED_PASSWORD:
            g_mmi_certman_context.popup_string_id = STR_CERTMAN_NEED_PASSWORD;
            image_id = IMG_GLOBAL_WARNING;
            break;
        case CERTMAN_ERR_INVALID_JOB:
            g_mmi_certman_context.popup_string_id = STR_CERTMAN_INVALID_JOB;
            image_id = IMG_GLOBAL_ERROR;
            break;
        case CERTMAN_ERR_INVALID_CERT_ID:
            g_mmi_certman_context.popup_string_id = STR_CERTMAN_INVALID_CERT_ID;
            image_id = IMG_GLOBAL_ERROR;
            break;
        case CERTMAN_ERR_LABEL_EXISTS:
            g_mmi_certman_context.popup_string_id = STR_CERTMAN_LABEL_EXISTS;
            image_id = IMG_GLOBAL_WARNING;
            break;
        case CERTMAN_ERR_DISK_FULL:
            g_mmi_certman_context.popup_string_id = FMGR_FS_DISK_FULL_TEXT;
            image_id = IMG_GLOBAL_ERROR;
            break;
        case CERTMAN_ERR_INVALID_PASSWORD:
            g_mmi_certman_context.popup_string_id = STR_CERTMAN_INVALID_PASSWORD;
            image_id = IMG_GLOBAL_ERROR;
            break;
        case CERTMAN_ERR_INVALID_LABEL:
            g_mmi_certman_context.popup_string_id = STR_CERTMAN_INVALID_LABEL;
            image_id = IMG_GLOBAL_ERROR;
            break;
        case CERTMAN_ERR_OUT_OF_RANGE:
            g_mmi_certman_context.popup_string_id = STR_CERTMAN_OUT_OF_RANGE;
            image_id = IMG_GLOBAL_ERROR;
            break;
        case CERTMAN_ERR_INVALID_CERT_GROUP:
            g_mmi_certman_context.popup_string_id = STR_CERTMAN_INVALID_CERT_GROUP;
            image_id = IMG_GLOBAL_ERROR;
            break;
        case CERTMAN_ERR_INVALID_KEY_PURPOSE:
            g_mmi_certman_context.popup_string_id = STR_CERTMAN_INVALID_KEY_PURPOSE;
            image_id = IMG_GLOBAL_ERROR;
            break;
        case CERTMAN_ERR_INVALID_DOMAIN:
            g_mmi_certman_context.popup_string_id = STR_CERTMAN_INVALID_DOMAIN;
            image_id = IMG_GLOBAL_ERROR;
            break;
        case CERTMAN_ERR_CERT_NOT_FOUND:
            g_mmi_certman_context.popup_string_id = STR_CERTMAN_CERTIFICATE_NOT_FOUND;
            image_id = IMG_GLOBAL_ERROR;
            break;
        case CERTMAN_ERR_KEY_PURPOSE_DENIED:
            g_mmi_certman_context.popup_string_id = STR_CERTMAN_KEY_PURPOSE_DENIED;
            image_id = IMG_GLOBAL_ERROR;
            break;
        case CERTMAN_ERR_KEY_NOT_FOUND:
            g_mmi_certman_context.popup_string_id = STR_CERTMAN_KEY_NOT_FOUND;
            image_id = IMG_GLOBAL_ERROR;
            break;
        case CERTMAN_ERR_INVALID_DATA:
            g_mmi_certman_context.popup_string_id = STR_CERTMAN_INVALID_DATA;
            image_id = IMG_GLOBAL_ERROR;
            break;
        case CERTMAN_ERR_INVALID_INPUT:
            g_mmi_certman_context.popup_string_id = STR_CERTMAN_INVALID_INPUT;
            image_id = IMG_GLOBAL_ERROR;
            break;
        case CERTMAN_ERR_CHAIN_NOT_ALLOWED:
        case CERTMAN_ERR_INVALID_FILENAME:
        case CERTMAN_ERR_NO_PWD_CALLBACK:
        case CERTMAN_ERR_FAIL:
        case CERTMAN_ERR_INVALID_PATH:
        case CERTMAN_ERR_FIRST_BOOTUP:
        case CERTMAN_ERR_ID_NOT_FOUND:
        case CERTMAN_ERR_ID_ALREADY_EXISTS:
            g_mmi_certman_context.popup_string_id = STR_GLOBAL_ERROR;
            image_id = IMG_GLOBAL_ERROR;
            break;
        case CERTMAN_ERR_TOO_MANY_CERTS:
            g_mmi_certman_context.popup_string_id = STR_CERTMAN_TOO_MANY_CERT;
            image_id = IMG_GLOBAL_ERROR;
            break;
        case CERTMAN_ERR_ACCESS_DENIED:
            g_mmi_certman_context.popup_string_id = STR_CERTMAN_ACCESS_DENIED;
            image_id = IMG_GLOBAL_ERROR;
            break;
        case CERTMAN_ERR_CERT_EXISTS:
            g_mmi_certman_context.popup_string_id = STR_CERTMAN_CERT_EXISTS;
            image_id = IMG_GLOBAL_ERROR;
            break;
        case CERTMAN_ERR_READ_ONLY:
            g_mmi_certman_context.popup_string_id = STR_CERTMAN_READ_ONLY;
            image_id = IMG_GLOBAL_ERROR;
            break;
        case CERTMAN_ERR_SUBJECT_NOT_FOUND:
        case CERTMAN_ERR_SUBJECT_UID_NOT_FOUND:
            g_mmi_certman_context.popup_string_id = STR_CERTMAN_SUBJECT_NOT_FOUND;
            image_id = IMG_GLOBAL_ERROR;
            break;
        case CERTMAN_ERR_ISSUER_NOT_FOUND:
        case CERTMAN_ERR_ISSUER_UID_NOT_FOUND:
            g_mmi_certman_context.popup_string_id = STR_CERTMAN_ISSUER_NOT_FOUND;
            image_id = IMG_GLOBAL_ERROR;
            break;
        case CERTMAN_ERR_EXT_NOT_FOUND:
            g_mmi_certman_context.popup_string_id = STR_CERTMAN_EXT_NOT_FOUND;
            image_id = IMG_GLOBAL_ERROR;
            break;
        case CERTMAN_ERR_CORRUPTED_DATA:
            g_mmi_certman_context.popup_string_id = STR_CERTMAN_CORRUPTED_DATA;
            image_id = IMG_GLOBAL_ERROR;
            break;
        case CERTMAN_ERR_FILE_CORRUPTED:
            g_mmi_certman_context.popup_string_id = STR_CERTMAN_CORRUPTED_FILE;
            image_id = IMG_GLOBAL_ERROR;
            break;
        case CERTMAN_ERR_FILE_TOO_LARGE:
            g_mmi_certman_context.popup_string_id = STR_CERTMAN_FILE_TOO_LARGE;
            image_id = IMG_GLOBAL_ERROR;
            break;
        case CERTMAN_ERR_CONVERT_FAIL:
            g_mmi_certman_context.popup_string_id = STR_CERTMAN_CONVERT_FAIL;
            image_id = IMG_GLOBAL_ERROR;
            break;
        default:
            return;
    }

    if (MMI_TRUE == mmi_certman_check_screen_in_history())
    {
        g_mmi_certman_context.popup_handler_callback = callback;
        mmi_certman_history_replace(
            SCR_ID_CERTMAN_PROGRESS_SCREEN,
            SCR_ID_CERTMAN_GENERAL_POPUP_SCREEN,
            mmi_certman_general_error_handler_if_screen_in_history);
    }
    else
    {
        if (callback)
        {
            DisplayPopupCallBack(
                (PU8) GetString(g_mmi_certman_context.popup_string_id),
                image_id,
                NULL,
                MMI_CERTMAN_POPUP_DURATION,
                0,
                callback);
        }
        else
        {
            DisplayPopup(
                (PU8) GetString(g_mmi_certman_context.popup_string_id),
                image_id,
                NULL,
                MMI_CERTMAN_POPUP_DURATION,
                0);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_general_error_handler_if_screen_in_history
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_general_error_handler_if_screen_in_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_certman_entry_new_screen(SCR_ID_CERTMAN_GENERAL_POPUP_SCREEN, mmi_certman_incorrect_pwd_screen_popup);
    ShowCategory2Screen(
        STR_CERTMAN_CERTIFICATE_INFO,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        0,
        0,
        g_mmi_certman_context.popup_string_id,
        NULL);
    if (g_mmi_certman_context.popup_handler_callback == NULL)
    {
        SetLeftSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
    else
    {
        SetLeftSoftkeyFunction(g_mmi_certman_context.popup_handler_callback, KEY_EVENT_UP);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_handle_error
 * DESCRIPTION
 *  common function to handle error
 * PARAMETERS
 *  error       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_handle_error(certman_error_enum error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_certman_handle_error_with_callback(error, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_displaypop_with_calback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  string              [IN]        
 *  imageId             [IN]        
 *  imageOnBottom       [IN]        
 *  popupDuration       [IN]        
 *  toneId              [IN]        
 *  f                   [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_displaypop_with_calback(
        U8 *string,
        U16 imageId,
        U8 imageOnBottom,
        U32 popupDuration,
        U8 toneId,
        FuncPtr f)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopupCallBack(string, imageId, imageOnBottom, popupDuration, toneId, f);
    /* StartTimer(MMI_CERTMAN_TIMER_ID, popupDuration, f); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_display_message_with_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  message         [IN]        
 *  callback        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_display_message_with_callback(U16 message, FuncPtr callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == mmi_certman_check_screen_in_history())
    {
        g_mmi_certman_context.popup_string_id = message;
        g_mmi_certman_context.popup_handler_callback = callback;
        mmi_certman_history_replace(
            SCR_ID_CERTMAN_PROGRESS_SCREEN,
            SCR_ID_CERTMAN_GENERAL_POPUP_SCREEN,
            mmi_certman_general_error_handler_if_screen_in_history);
    }
    else
    {
        if (callback)
        {
            mmi_certman_displaypop_with_calback(
                (PU8) GetString(message),
                NULL,
                NULL,
                MMI_CERTMAN_POPUP_DURATION,
                0,
                callback);
        }
        else
        {
            DisplayPopup((PU8) GetString(message), NULL, NULL, MMI_CERTMAN_POPUP_DURATION, 0);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_display_message
 * DESCRIPTION
 *  
 * PARAMETERS
 *  message     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_display_message(U16 message)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_certman_display_message_with_callback(message, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_pre_entry_display_user_certificate_list_by_issuer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_pre_entry_display_user_certificate_list_by_issuer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == mmi_certman_check_screen_in_history())
    {
        mmi_certman_history_replace(
            SCR_ID_CERTMAN_PROGRESS_SCREEN,
            SCR_ID_CERTMAN_CERTIFICATE_LIST,
            mmi_certman_display_user_certificate_list_by_issuer);
    }
    else
    {
        g_mmi_certman_context.screen_id = 0;
        mmi_certman_display_user_certificate_list_by_issuer();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_display_user_certificate_list_by_issuer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_display_user_certificate_list_by_issuer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_certman_context.user_cert_list_context_p->cert_count == 0)
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_EMPTY), NULL, NULL, MMI_CERTMAN_POPUP_DURATION, 0);
        mmi_certman_select_certificates_rsp(MMI_FALSE, 0, 0, g_mmi_certman_context.user_cert_list_context_p->trans_id);
        mmi_certman_user_certificates_list_deinit();
        return;
    }
    mmi_certman_entry_new_screen(
        SCR_ID_CERTMAN_USER_CERTIFICATE_LIST_BY_ISSUER,
        mmi_certman_display_user_certificate_list_by_issuer);
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_certman_display_user_certificate_list_by_issuer");
    gui_buffer = GetCurrGuiBuffer(SCR_ID_CERTMAN_USER_CERTIFICATE_LIST_BY_ISSUER);
    RegisterHighlightHandler(mmi_certman_user_certificate_list_highlight_handler);
    ShowCategory184Screen(
        STR_CERTMAN_CERTIFICATES,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        g_mmi_certman_context.user_cert_list_context_p->cert_count,
        mmi_certman_get_personal_certificates,
        NULL,
        0,
        gui_buffer);
    SetLeftSoftkeyFunction(mmi_certman_select_user_certificate_lsk, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_certman_select_user_certificate_rsk, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_get_personal_certificates
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index          [IN]        
 *  str_buff            [IN]        
 *  img_buff_p          [?]         [?]
 *  str_img_mask        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
pBOOL mmi_certman_get_personal_certificates(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_certman_get_personal_certificates");
    if ((item_index < 0) || (item_index > MMI_CERTMAN_CERTIFICATES_MAX))
    {
        return FALSE;
    }

    mmi_ucs2cpy(
        (PS8) str_buff,
        (PS8) g_mmi_certman_context.user_cert_list_context_p->certificate_list[item_index].cert_label);
    if (g_mmi_certman_context.user_cert_list_context_p->certificate_list[item_index].cert_group ==
        CERTMAN_CERTGRP_PERSONAL)
    {
        *img_buff_p = NULL;
        return TRUE;
    }
    *img_buff_p = NULL;
    return TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_select_user_certificate_lsk
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_select_user_certificate_lsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index = g_mmi_certman_context.user_cert_list_context_p->selected_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_certman_select_usjjer_certificate_lsk");
    /* g_mmi_certman_context.user_cert_list_context_p->certificate_list[index].cert_id; */
    mmi_certman_select_user_certificates_rsp(
        g_mmi_certman_context.user_cert_list_context_p->certificate_list[index].cert_id,
        MMI_TRUE,
        g_mmi_certman_context.user_cert_list_context_p->trans_id);
    GoBackHistory();
    mmi_certman_user_certificates_list_deinit();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_select_user_certificate_rsk
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_select_user_certificate_rsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackHistory();
    mmi_certman_exit_user_certificates_list();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_user_certificate_list_highlight_handler
 * DESCRIPTION
 *  highlight handler for certificate
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_user_certificate_list_highlight_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_certman_context.user_cert_list_context_p->selected_index = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_pre_enter_install
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  result(?)       [IN](?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_pre_enter_install(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILE_INFO_STRUCT file_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmgr_kernel_get_file_info(fmgr_p->cur_index, &file_info);
    if (fmgr_check_file_present() < FMGR_NO_ERROR)
    {
        return;
    }
    mmi_certman_install_certificates_ind(MOD_MMI, MMI_CERTMAN_OPEN, 1, (kal_wchar*) file_info.file_name);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_launch_certficate_manager
 * DESCRIPTION
 *  Function to launch certificate manager
 * PARAMETERS
 *  void
 *  index(?)        [IN](?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_launch_certficate_manager(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_certman_launch_certificates_ind(MOD_MMI, MMI_CERTMAN_OPEN, 1);
    /* mmi_certman_select_certificates_ind(MOD_MMI, MMI_CERTMAN_OPEN, MMI_FALSE, 1, MMI_CERTMAN_CERT_GROUP_USER); */

}
#endif /* __CERTMAN_SUPPORT__ */ 
/* Shrikant */

