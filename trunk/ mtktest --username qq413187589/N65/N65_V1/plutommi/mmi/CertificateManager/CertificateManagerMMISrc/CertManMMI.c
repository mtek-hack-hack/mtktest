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
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  CertManMMI.c
 *
 * Project:
 * --------
 *  Certificate Manager
 *
 * Description:
 * ------------
 *   This file is intends for Certificate Manager MMI
 *
 * Author:
 * ------------
 * -------
 *
************************************************************************************/
/* ShriKant */
#ifdef __CERTMAN_SUPPORT__

#include "PixtelDataTypes.h"
#include "wgui_categories_inputs.h"
#include "CertManMMIGProts.h"
#include "CertManMMIResDef.h"
#include "CertManMMITypes.h"
#include "CertManMMIProts.h"
#include "CommonScreens.h"
#include "Ucs2prot.h"


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_certman_set_protocol_events();
    mmi_certman_mem_init();

    SetHiliteHandler(MENU_ID_CERTMAN_AUTHORITY_CERT, mmi_certman_highlight_authority_certificates);
    SetHiliteHandler(MENU_ID_CERTMAN_USER_CERT, mmi_certman_highlight_user_certificates);
    SetHiliteHandler(MENU_ID_CERTMAN_OPTION_VIEW_CERTIFICATE, mmi_certman_highlight_view_certificates);
    SetHiliteHandler(MENU_ID_CERTMAN_OPTION_DELETE_CERTIFICATE, mmi_certman_highlight_delete_certificates);
    SetHiliteHandler(MENU_ID_CERTMAN_OPTION_DELETE_ALL_CERTIFICATE, mmi_certman_highlight_delete_all_certificates);
    SetHiliteHandler(MENU_ID_CERTMAN_OPTION_TRUST_SETTINGS_CERTIFICATE, mmi_certman_highlight_key_usage_certificates);

    SetHiliteHandler(MENU_ID_CERTMAN_INVALID_OPTION_INSTALL, mmi_certman_highlight_invalid_cert_install);
    SetHiliteHandler(MENU_ID_CERTMAN_INVALID_OPTION_CONTINUE, mmi_certman_highlight_invalid_cert_continue);
    SetHiliteHandler(MENU_ID_CERTMAN_INVALID_OPTION_CANCEL, mmi_certman_highlight_invalid_cert_cancel);

}

/**************************************************************************/
/*****************************IMPORT CERTIFICATES**************************/
/**************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_import_init
 * DESCRIPTION
 *  functiom to init import
 * PARAMETERS
 *  msg             [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_import_init(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_certman_install_cert_ind_struct *install_certificate_ind = (mmi_certman_install_cert_ind_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_certman_parse_begin_cnf_handler, MSG_ID_CERTMAN_PARSE_BEGIN_CNF);
    SetProtocolEventHandler(mmi_certman_certificates_detail_cnf_handler, MSG_ID_CERTMAN_PARSE_CERT_DETAIL_CNF);
    SetProtocolEventHandler(mmi_certman_import_cnf_handler, MSG_ID_CERTMAN_IMPORT_CNF);
    SetProtocolEventHandler(mmi_certman_send_parse_end_cnf_handler, MSG_ID_CERTMAN_PARSE_END_CNF);
    g_mmi_certman_context.import_context_p = mmi_certman_malloc(sizeof(mmi_certman_import_context_struct));

    if (g_mmi_certman_context.import_context_p == NULL)
    {
        mmi_certman_handle_error(CERTMAN_ERR_MEMFULL);
        mmi_certman_install_certificates_rsp(MMI_FALSE, install_certificate_ind->trans_id);
        return;
    }
    g_mmi_certman_context.current_status = MMI_CERTMAN_IMPORT;
    g_mmi_certman_context.import_context_p->trans_id = install_certificate_ind->trans_id;
    mmi_certman_start_import((void*)install_certificate_ind->cert_filename);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_exit_from_import_with_gobackhistory
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_exit_from_import_with_gobackhistory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_certman_exit_from_import();
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_import_state
 * DESCRIPTION
 *  functions for import's state
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_import_state(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 error;
    certman_encoding_enum encoding_type = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_certman_import_state");

    switch (g_mmi_certman_context.import_context_p->current_state)
    {
        case MMI_CERTMAN_IMPORT_IDLE:
        {
            U8 *filename_p;

            filename_p = (U8*) msg;
            error = certman_parse_get_encoding_type_by_file((kal_wchar*) filename_p, &encoding_type);
            if (error != CERTMAN_ERR_NONE)
            {
                mmi_certman_handle_error_with_callback(error, mmi_certman_exit_from_import_with_gobackhistory);
                break;
            }
            error = certman_ctx_parse_new_by_file(
                        (kal_wchar*) filename_p,
                        encoding_type,
                        &(g_mmi_certman_context.import_context_p->ctx_parse_p));

            if (error != CERTMAN_ERR_NONE)
            {
                mmi_certman_handle_error_with_callback(error, mmi_certman_exit_from_import_with_gobackhistory);
                break;
            }
            g_mmi_certman_context.import_context_p->count = 0;
            g_mmi_certman_context.import_context_p->current_state = MMI_CERTMAN_IMPORT_CHECK_ENCODING;
            mmi_certman_import_state(&encoding_type);
        }
            break;
        case MMI_CERTMAN_IMPORT_CHECK_ENCODING:
            encoding_type = *((certman_encoding_enum*) msg);
            if (encoding_type == CERTMAN_ENC_PK12)
            {
                g_mmi_certman_context.import_context_p->current_state = MMI_CERTMAN_IMPORT_GET_DECR_PWD;
                mmi_certman_import_state(NULL);
            }
            else
            {
                mmi_certman_progress_screen();
                g_mmi_certman_context.import_context_p->current_state = MMI_CERTMAN_IMPORT_PARSING;
                certman_send_parse_begin_req(
                    MOD_MMI,
                    g_mmi_certman_context.import_context_p->trans_id,
                    g_mmi_certman_context.import_context_p->ctx_parse_p);
            }
            break;
        case MMI_CERTMAN_IMPORT_GET_DECR_PWD:
            mmi_certman_pre_entry_get_decryption_password();
            break;

        case MMI_CERTMAN_IMPORT_PARSING:
        {
            U16 temp_count = 0;
            certman_parse_begin_cnf_struct *parsed_begin_cnf_p;

            parsed_begin_cnf_p = (certman_parse_begin_cnf_struct*) msg;
            g_mmi_certman_context.import_context_p->job_id = parsed_begin_cnf_p->job_id;
            g_mmi_certman_context.import_context_p->trans_id = parsed_begin_cnf_p->trans_id;
            if (parsed_begin_cnf_p->status == CERTMAN_ERR_INCORRECT_PASSWORD)
            {
                g_mmi_certman_context.import_context_p->current_state = MMI_CERTMAN_IMPORT_GET_DECR_PWD;
                if (!mmi_certman_check_screen_in_history())
                {
                    mmi_certman_import_state(NULL);
                }
                mmi_certman_handle_error(parsed_begin_cnf_p->status);
                return;
            }
            if (parsed_begin_cnf_p->status != CERTMAN_ERR_NONE)
            {
                mmi_certman_handle_error(parsed_begin_cnf_p->status);
                mmi_certman_exit_from_import();
                return;
            }

            certman_ctx_parse_free(g_mmi_certman_context.import_context_p->ctx_parse_p);
            g_mmi_certman_context.import_context_p->cert_total =
                parsed_begin_cnf_p->parsed_info[CERTMAN_PARSED_CERTGRP_ALL].cert_count;

            ASSERT(g_mmi_certman_context.import_context_p->cert_total <= CERTMAN_NUM_PARSED_CERT);

            for (temp_count = 0; temp_count < g_mmi_certman_context.import_context_p->cert_total; temp_count++)
            {
                g_mmi_certman_context.import_context_p->cert_ref_ids[temp_count] =
                    parsed_begin_cnf_p->parsed_info[CERTMAN_PARSED_CERTGRP_ALL].cert_ref_ids[temp_count];
            }
            if ((parsed_begin_cnf_p->num_private_key) > 0)
            {
                g_mmi_certman_context.import_context_p->num_priv_key = parsed_begin_cnf_p->num_private_key;
                g_mmi_certman_context.import_context_p->current_state = MMI_CERTMAN_IMPORT_DISPLAY_FILE_INFO;
                mmi_certman_import_state(NULL);

            }
            else
            {
                g_mmi_certman_context.import_context_p->current_state = MMI_CERTMAN_IMPORT_DETAIL_REQUEST;
                mmi_certman_import_state(NULL);
            }
        }
            break;
        case MMI_CERTMAN_IMPORT_DISPLAY_FILE_INFO:
            mmi_certman_pre_entry_display_file_info();
            break;
        case MMI_CERTMAN_IMPORT_DETAIL_REQUEST:
            g_mmi_certman_context.import_context_p->key_purpose = CERTMAN_KP_SERVER_AUTH
                | CERTMAN_KP_CLIENT_AUTH
                | CERTMAN_KP_CODE_SIGNING
                | CERTMAN_KP_EMAIL_PROTECTION
                | CERTMAN_KP_IPSEC_ENDSYSTEM
                | CERTMAN_KP_IPSEC_TUNNEL | CERTMAN_KP_IPSEC_USER | CERTMAN_KP_TIME_STAMPING | CERTMAN_KP_OCSP_SIGNING;
            mmi_ucs2cpy((S8*) g_mmi_certman_context.show_string, (S8*) GetString(STR_CERTMAN_KP_ALL));
            g_mmi_certman_context.import_context_p->protection_method = CERTMAN_PROTECT_NONE;
            mmi_certman_certificates_detail();
            break;
        case MMI_CERTMAN_IMPORT_DISPLAY:
            mmi_certman_pre_entry_display_certificate_contents();
            break;
        case MMI_CERTMAN_IMPORT_GET_CERT_INFO:
            mmi_certman_get_certificate_inputs();
            break;
        case MMI_CERTMAN_IMPORT_IMPORT:
        {
            certman_import_cnf_struct *import_cnf_p;

            import_cnf_p = (certman_import_cnf_struct*) msg;
            error = import_cnf_p->status;
            g_mmi_certman_context.import_context_p->cert_id = import_cnf_p->cert_id;

            if (error != CERTMAN_ERR_NONE)
            {
                if (error == CERTMAN_ERR_MEMFULL || error == CERTMAN_ERR_DISK_FULL
                    || error == CERTMAN_ERR_DISK_FULL || error == CERTMAN_ERR_INVALID_JOB
                    || error == CERTMAN_ERR_FS_ERROR)
                {
                    mmi_certman_handle_error(error);
                    mmi_certman_exit_from_import();
                    break;
                }
                else
                {
                    GoBackHistory();
                    mmi_certman_handle_error_with_callback(error, mmi_certman_import_error);
                    break;
                }
            }
            else if (g_mmi_certman_context.import_context_p->cert_group == CERTMAN_PARSED_CERTGRP_PERSONAL)
            {
                error = certman_import_set_privkey_protection(
                            g_mmi_certman_context.import_context_p->ctx_import_p,
                            g_mmi_certman_context.import_context_p->protection_method,
                            g_mmi_certman_context.import_context_p->privatekey_pwd);
                mmi_certman_handle_error(error);
            }
            certman_ctx_import_free(g_mmi_certman_context.import_context_p->ctx_import_p);
            g_mmi_certman_context.import_context_p->current_state = MMI_CERTMAN_IMPORT_SET_KEY_PURPOSE;
            mmi_certman_display_message_with_callback(STR_GLOBAL_DONE, mmi_certman_import_key_purpose_request);

        }
            break;
        case MMI_CERTMAN_IMPORT_SET_KEY_PURPOSE:
        {
            certman_update_key_purpose_cnf_struct *purpose_cnf_p;

            purpose_cnf_p = (certman_update_key_purpose_cnf_struct*) msg;
            error = purpose_cnf_p->status;
            mmi_certman_handle_error(error);
            g_mmi_certman_context.import_context_p->current_state = MMI_CERTMAN_IMPORT_DETAIL_REQUEST;
            mmi_certman_import_state(NULL);
        }
            break;

        case MMI_CERTMAN_IMPORT_END_PARSING:
        {
            certman_parse_end_cnf_struct *parse_end_cnf_p;

            parse_end_cnf_p = (certman_parse_end_cnf_struct*) msg;
            error = parse_end_cnf_p->status;
            mmi_certman_handle_error(error);
            break;
        }

        default:
            ASSERT(0);

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_import_error
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_import_error(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackHistory();
    if (g_mmi_certman_context.current_status == MMI_CERTMAN_INVALID)
    {
        g_mmi_certman_context.view_invalid_context_p->current_state = MMI_CERTMAN_VIEW_INVALID_PARSE_END;
        g_mmi_certman_context.screen_id = 0;
        mmi_certman_progress_screen();
        certman_send_parse_end_req(
            MOD_MMI,
            g_mmi_certman_context.view_invalid_context_p->trans_id,
            g_mmi_certman_context.view_invalid_context_p->job_id);
    }
    else
    {
        g_mmi_certman_context.import_context_p->current_state = MMI_CERTMAN_IMPORT_DETAIL_REQUEST;
        mmi_certman_import_state(NULL);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_check_decryption_pwd
 * DESCRIPTION
 *  function to check the decrytion password
 * PARAMETERS
 *  pwd     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_check_decryption_pwd(U8 *pwd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 password[CERTMAN_PASSWORD_SIZE];
    certman_error_enum error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2_to_asc((S8*) password, (S8*) pwd);
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_certman_check_decryption_pwd");
    error = certman_parse_set_decrypt_password(g_mmi_certman_context.import_context_p->ctx_parse_p, password);
    if (error == CERTMAN_ERR_INVALID_PASSWORD)
    {
        g_mmi_certman_context.import_context_p->current_state = MMI_CERTMAN_IMPORT_GET_DECR_PWD;
        mmi_certman_import_state(NULL);
        mmi_certman_handle_error(error);
        return;
    }
    if (error != CERTMAN_ERR_NONE)
    {
        mmi_certman_handle_error(error);
        mmi_certman_exit_from_import();
        return;
    }
    mmi_certman_progress_screen();
    g_mmi_certman_context.import_context_p->current_state = MMI_CERTMAN_IMPORT_PARSING;
    certman_send_parse_begin_req(
        MOD_MMI,
        g_mmi_certman_context.import_context_p->trans_id,
        g_mmi_certman_context.import_context_p->ctx_parse_p);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_check()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetActiveScreenId() == SCR_ID_CERTMAN_PROGRESS_SCREEN)
    {
        GoBackHistory();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_certificates_detail
 * DESCRIPTION
 *  function for certifcate detail
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_certificates_detail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 total;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_certman_certificates_detail");
    total = certman_get_cert_count(CERTMAN_CERTGRP_NONE, CERTMAN_KP_NONE);
    if ((g_mmi_certman_context.import_context_p->count < g_mmi_certman_context.import_context_p->cert_total)
        && (total < MMI_CERTMAN_CERTIFICATES_MAX))
    {
        if (mmi_certman_check_detail_history())
        {
            mmi_certman_progress_screen();
        }
        g_mmi_certman_context.import_context_p->current_state = MMI_CERTMAN_IMPORT_DISPLAY;
        certman_send_parse_cert_detail_req(
            MOD_MMI,
            g_mmi_certman_context.import_context_p->trans_id,
            g_mmi_certman_context.import_context_p->job_id,
            g_mmi_certman_context.import_context_p->cert_ref_ids[g_mmi_certman_context.import_context_p->count]);
        g_mmi_certman_context.import_context_p->count++;
    }
    else
    {
        if (total >= MMI_CERTMAN_CERTIFICATES_MAX)
        {
            mmi_certman_check();
            mmi_certman_display_message(STR_CERTMAN_MAX_LIMIT);
        }
        mmi_certman_progress_screen();
        certman_send_parse_end_req(
            MOD_MMI,
            g_mmi_certman_context.import_context_p->trans_id,
            g_mmi_certman_context.import_context_p->job_id);
        g_mmi_certman_context.import_context_p->current_state = MMI_CERTMAN_IMPORT_END_PARSING;
        /* Add popup for max limit */

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_import_deinit
 * DESCRIPTION
 *  function to deinit the import
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_import_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_certman_context.import_context_p)
    {
        mmi_certman_free(g_mmi_certman_context.import_context_p);
        g_mmi_certman_context.import_context_p = NULL;
    }
    /* error = mmi_certman_mem_deinit(); */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_start_import
 * DESCRIPTION
 *  function to start import
 * PARAMETERS
 *  filename        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_start_import(void *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_certman_context.import_context_p->current_state = MMI_CERTMAN_IMPORT_IDLE;
    mmi_certman_import_state(filename);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_import_key_purpose_request
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_import_key_purpose_request(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* GoBackHistory(); */
    SetProtocolEventHandler(mmi_certman_import_update_key_purpose_cnf_handler, MSG_ID_CERTMAN_UPDATE_KEY_PURPOSE_CNF);
    mmi_certman_progress_screen();
    certman_send_update_key_purpose_req(
        MOD_MMI,
        g_mmi_certman_context.import_context_p->trans_id,
        g_mmi_certman_context.import_context_p->cert_id,
        g_mmi_certman_context.import_context_p->key_purpose);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_check_label
 * DESCRIPTION
 *  function to check label
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_check_label(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    certman_error_enum error;

    /* U8 label[CERTMAN_LABEL_SIZE]; */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_certman_check_label");
    /* if given file is PKCS#12 and private key is password protected) */
    if (g_mmi_certman_context.import_context_p->protection_method == CERTMAN_PROTECT_USAGE_PASSWORD)
    {
        /* If private key pwd and confirm pwd are not equal */
        if (!mmi_ucs2cmp(
                (PS8) g_mmi_certman_context.import_context_p->privatekey_pwd,
                (PS8) g_mmi_certman_context.import_context_p->privatekey_cnf_pwd))
        {
            g_mmi_certman_context.import_context_p->current_state = MMI_CERTMAN_IMPORT_GET_CERT_INFO;
            mmi_certman_import_state(NULL);
            mmi_certman_display_message(STR_CERTMAN_MISMATCHED);

            return;
        }
    }
    error = certman_import_check_label_exists(g_mmi_certman_context.import_context_p->certificate_label, CERTMAN_DCS_UCS2);
    switch (error)
    {
        case CERTMAN_ERR_LABEL_EXISTS:
            g_mmi_certman_context.import_context_p->current_state = MMI_CERTMAN_IMPORT_GET_CERT_INFO;
            mmi_certman_import_state(NULL);
            mmi_certman_handle_error(error);
            break;
        case CERTMAN_ERR_INVALID_LABEL:
            g_mmi_certman_context.import_context_p->current_state = MMI_CERTMAN_IMPORT_GET_CERT_INFO;
            mmi_certman_import_state(NULL);
            mmi_certman_handle_error(error);
            break;
        default:

            error = certman_ctx_import_new(
                        g_mmi_certman_context.import_context_p->job_id,
                        g_mmi_certman_context.import_context_p->cert_ref_ids[g_mmi_certman_context.import_context_p->count - 1],
                        &(g_mmi_certman_context.import_context_p->ctx_import_p));

            error = certman_import_set_label(
                        g_mmi_certman_context.import_context_p->ctx_import_p,
                        g_mmi_certman_context.import_context_p->certificate_label,
                        CERTMAN_DCS_UCS2);
            /* mmi_certman_progress_screen(); */

            ASSERT(error <= CERTMAN_ERR_NONE);
            g_mmi_certman_context.import_context_p->current_state = MMI_CERTMAN_IMPORT_IMPORT;
            mmi_certman_progress_screen();
            certman_send_import_req(
                MOD_MMI,
                g_mmi_certman_context.import_context_p->trans_id,
                g_mmi_certman_context.import_context_p->ctx_import_p);

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_exit_from_import
 * DESCRIPTION
 *  function to exit form import
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_exit_from_import(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 trans_id = g_mmi_certman_context.import_context_p->trans_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_certman_exit_from_import");
    switch (g_mmi_certman_context.import_context_p->current_state)
    {
        case MMI_CERTMAN_IMPORT_IDLE:
            mmi_certman_install_certificates_rsp(MMI_FALSE, trans_id);
            break;
        case MMI_CERTMAN_IMPORT_CHECK_ENCODING:
            mmi_certman_install_certificates_rsp(MMI_FALSE, trans_id);
            break;
        case MMI_CERTMAN_IMPORT_GET_DECR_PWD:
            mmi_certman_install_certificates_rsp(MMI_FALSE, trans_id);
            certman_ctx_parse_free(g_mmi_certman_context.import_context_p->ctx_parse_p);
            break;
        case MMI_CERTMAN_IMPORT_PARSING:
            certman_ctx_parse_free(g_mmi_certman_context.import_context_p->ctx_parse_p);
            mmi_certman_install_certificates_rsp(MMI_FALSE, trans_id);
            break;
        case MMI_CERTMAN_IMPORT_DISPLAY_FILE_INFO:
            /* certman_ctx_parse_free(g_mmi_certman_context.import_context_p->ctx_parse_p); */
            mmi_certman_install_certificates_rsp(MMI_FALSE, trans_id);
            break;
        case MMI_CERTMAN_IMPORT_DETAIL_REQUEST:
            mmi_certman_install_certificates_rsp(MMI_FALSE, trans_id);
            break;
        case MMI_CERTMAN_IMPORT_DISPLAY:
            certman_parsed_data_free(g_mmi_certman_context.import_context_p->parsed_data_p);
            mmi_certman_install_certificates_rsp(MMI_FALSE, trans_id);
            break;
        case MMI_CERTMAN_IMPORT_GET_CERT_INFO:
            mmi_certman_install_certificates_rsp(MMI_FALSE, trans_id);
            break;
        case MMI_CERTMAN_IMPORT_IMPORT:

            certman_ctx_import_free(g_mmi_certman_context.import_context_p->ctx_import_p);
            mmi_certman_install_certificates_rsp(MMI_FALSE, trans_id);
            break;
        case MMI_CERTMAN_IMPORT_SET_KEY_PURPOSE:
            mmi_certman_install_certificates_rsp(MMI_FALSE, trans_id);
            break;
        case MMI_CERTMAN_IMPORT_END_PARSING:

            mmi_certman_install_certificates_rsp(MMI_TRUE, trans_id);

            if (GetActiveScreenId() == SCR_ID_CERTMAN_PROGRESS_SCREEN)
            {
                GoBackHistory();
            }
            else
            {
                DeleteScreenIfPresent(SCR_ID_CERTMAN_PROGRESS_SCREEN);
            }
            break;
        default:
            mmi_certman_install_certificates_rsp(MMI_FALSE, trans_id);
            return;
    }
    mmi_certman_import_deinit();
    g_mmi_certman_context.current_status = MMI_CERTMAN_IDLE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_exit_from_select_launch
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_exit_from_select_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 trans_id = g_mmi_certman_context.launch_select_context_p->trans_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_certman_context.current_status == MMI_CERTMAN_SELECT)
    {
        switch (g_mmi_certman_context.launch_select_context_p->current_state)
        {
            case MMI_CERTMAN_LAUNCH_SELECT_VIEW_CERT:
                certman_cert_display_content_free(g_mmi_certman_context.launch_select_context_p->display_p);
                break;
        }
        mmi_certman_select_certificates_rsp(MMI_FALSE, 0, 0, trans_id);
    }
    else
    {
        mmi_certman_launch_certificates_rsp(MMI_FALSE, trans_id);
    }
    mmi_certman_launch_deinit();
    g_mmi_certman_context.current_status = MMI_CERTMAN_IDLE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_get_no_of_private_keys
 * DESCRIPTION
 *  function to get no. of private keys
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_certman_get_no_of_private_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mmi_certman_context.import_context_p->num_priv_key;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_save_file
 * DESCRIPTION
 *  function to save file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_save_file()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_certman_context.import_context_p->current_state = MMI_CERTMAN_IMPORT_DETAIL_REQUEST;
    mmi_certman_import_state(NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_save_certificate
 * DESCRIPTION
 *  function to save certficate
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_save_certificate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_certman_save_certificate");
    DeleteScreenIfPresent(SCR_ID_CERTMAN_CERTIFICATE_DETAILS);
    g_mmi_certman_context.screen_id = 0;
    if (g_mmi_certman_context.import_context_p->parsed_data_p->cert_exists != 0)
    {
        g_mmi_certman_context.import_context_p->current_state = MMI_CERTMAN_IMPORT_DETAIL_REQUEST;
        mmi_certman_import_state(NULL);
        mmi_certman_display_message(STR_CERTMAN_CERT_EXISTS);

        return;
    }

    if (g_mmi_certman_context.import_context_p->parsed_data_p->cert.subject.names[CERTMAN_NAMETYPE_COMMON_NAME])
    {
        mmi_certman_cert_strncpy(
            g_mmi_certman_context.import_context_p->certificate_label,
            g_mmi_certman_context.import_context_p->parsed_data_p->cert.subject.names[CERTMAN_NAMETYPE_COMMON_NAME],
            g_mmi_certman_context.import_context_p->parsed_data_p->cert.subject.dcs[CERTMAN_NAMETYPE_COMMON_NAME],
            CERTMAN_LABEL_SIZE);
    }
    else if (g_mmi_certman_context.import_context_p->parsed_data_p->cert.subject.
             names[CERTMAN_NAMETYPE_ORGANISATION_UNIT])
    {
        mmi_certman_cert_strncpy(
            g_mmi_certman_context.import_context_p->certificate_label,
            g_mmi_certman_context.import_context_p->parsed_data_p->cert.subject.names[CERTMAN_NAMETYPE_ORGANISATION_UNIT],
            g_mmi_certman_context.import_context_p->parsed_data_p->cert.subject.dcs[CERTMAN_NAMETYPE_ORGANISATION_UNIT],
            CERTMAN_LABEL_SIZE);
    }
    g_mmi_certman_context.import_context_p->cert_group =
        g_mmi_certman_context.import_context_p->parsed_data_p->cert_group;

    certman_parsed_data_free(g_mmi_certman_context.import_context_p->parsed_data_p);
    g_mmi_certman_context.import_context_p->current_state = MMI_CERTMAN_IMPORT_GET_CERT_INFO;
    mmi_certman_import_state(NULL);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_discard_certificate
 * DESCRIPTION
 *  function to discard certiifcate
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_discard_certificate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* GoBackHistory(); */
    certman_parsed_data_free(g_mmi_certman_context.import_context_p->parsed_data_p);
    g_mmi_certman_context.import_context_p->current_state = MMI_CERTMAN_IMPORT_DETAIL_REQUEST;
    mmi_certman_import_state(NULL);

}

/**************************************************************************/
/*****************************lAUNCH /SELECT CERTIFICATES******************/
/**************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_launch_init
 * DESCRIPTION
 *  init function for launch
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_launch_init(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_certman_launch_cert_ind_struct *launch_certificate_ind = (mmi_certman_launch_cert_ind_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Launch & Select */
    SetProtocolEventHandler(mmi_certman_get_cert_list_by_group_cnf_handler, MSG_ID_CERTMAN_GET_CERT_LIST_BY_GROUP_CNF);
    SetProtocolEventHandler(mmi_certman_send_get_cert_disp_by_id_cnf_handler, MSG_ID_CERTMAN_GET_CERT_DISP_BY_ID_CNF);
    SetProtocolEventHandler(mmi_certman_send_delete_cert_cnf_handler, MSG_ID_CERTMAN_DELETE_CERT_CNF);
    SetProtocolEventHandler(mmi_certman_send_delete_all_cert_cnf_handler, MSG_ID_CERTMAN_DELETE_ALL_CERT_CNF);
    g_mmi_certman_context.launch_select_context_p = mmi_certman_malloc(sizeof(mmi_certman_launch_select_context_struct));
    if (g_mmi_certman_context.launch_select_context_p == NULL)
    {
        mmi_certman_handle_error(CERTMAN_ERR_MEMFULL);
        mmi_certman_launch_certificates_rsp(MMI_FALSE, launch_certificate_ind->trans_id);
        return;

    }
    g_mmi_certman_context.launch_select_context_p->trans_id = launch_certificate_ind->trans_id;
    g_mmi_certman_context.launch_select_context_p->current_state = MMI_CERTMAN_LAUNCH_SELECT_IDLE;
    g_mmi_certman_context.current_status = MMI_CERTMAN_LAUNCH;
    mmi_certman_launch_select_state(NULL);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_launch_deinit
 * DESCRIPTION
 *  deinit function for launch
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_launch_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_certman_free(g_mmi_certman_context.launch_select_context_p);
    g_mmi_certman_context.current_status = MMI_CERTMAN_IDLE;
    /* error = mmi_certman_mem_deinit(); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_select_init
 * DESCRIPTION
 *  init function for select
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_select_init(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_certman_select_cert_ind_struct *select_certificate_ind = (mmi_certman_select_cert_ind_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Launch & Select */
    SetProtocolEventHandler(mmi_certman_get_cert_list_by_group_cnf_handler, MSG_ID_CERTMAN_GET_CERT_LIST_BY_GROUP_CNF);
    SetProtocolEventHandler(mmi_certman_send_get_cert_disp_by_id_cnf_handler, MSG_ID_CERTMAN_GET_CERT_DISP_BY_ID_CNF);
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_certman_select_init");
    g_mmi_certman_context.launch_select_context_p = mmi_certman_malloc(sizeof(mmi_certman_launch_select_context_struct));
    if (g_mmi_certman_context.launch_select_context_p == NULL)
    {
        mmi_certman_handle_error(CERTMAN_ERR_MEMFULL);
        mmi_certman_select_certificates_rsp(MMI_FALSE, 0, 0, select_certificate_ind->trans_id);
        return;
    }
    g_mmi_certman_context.launch_select_context_p->certificate_count = 0;
    g_mmi_certman_context.launch_select_context_p->current_state = MMI_CERTMAN_LAUNCH_SELECT_GROUP_REQ;
    g_mmi_certman_context.current_status = MMI_CERTMAN_SELECT;
    switch (select_certificate_ind->cert_group)
    {
        case MMI_CERTMAN_CERT_GROUP_ALL:
            g_mmi_certman_context.launch_select_context_p->cert_group = CERTMAN_CERTGRP_NONE;
            break;
        case MMI_CERTMAN_CERT_GROUP_ROOT_CA:
            g_mmi_certman_context.launch_select_context_p->cert_group = CERTMAN_CERTGRP_ROOTCA;
            break;
        case MMI_CERTMAN_CERT_GROUP_INTERMEDIATE_CA:
            g_mmi_certman_context.launch_select_context_p->cert_group = CERTMAN_CERTGRP_CA;
            break;
        case MMI_CERTMAN_CERT_GROUP_AUTHORITY:
            g_mmi_certman_context.launch_select_context_p->cert_group = CERTMAN_CERTGRP_ROOTCA | CERTMAN_CERTGRP_CA;
            break;
        case MMI_CERTMAN_CERT_GROUP_OTHER_USER:
            g_mmi_certman_context.launch_select_context_p->cert_group = CERTMAN_CERTGRP_OTHERUSER;
            break;
        case MMI_CERTMAN_CERT_GROUP_PERSONAL:
            g_mmi_certman_context.launch_select_context_p->cert_group = CERTMAN_CERTGRP_PERSONAL;
            break;
        case MMI_CERTMAN_CERT_GROUP_USER:
            g_mmi_certman_context.launch_select_context_p->cert_group =
                CERTMAN_CERTGRP_OTHERUSER | CERTMAN_CERTGRP_PERSONAL;
            break;
    }
    g_mmi_certman_context.launch_select_context_p->multiple_selection_flag =
        select_certificate_ind->multiple_selection_flag;
    g_mmi_certman_context.launch_select_context_p->trans_id = select_certificate_ind->trans_id;
    /* g_mmi_certman_context.launch_select_context_p->key_purpose = CERTMAN_KP_NONE; */
    mmi_certman_progress_screen();
    mmi_certman_launch_select_state(NULL);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_launch_select_state
 * DESCRIPTION
 *  function for the state of knowing the state fo launch/select
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_launch_select_state(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 more = 0;
    U32 total;

    /* certman_encoding_enum encoding_type = 0; */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_certman_launch_select_state");
    switch (g_mmi_certman_context.launch_select_context_p->current_state)
    {
        case MMI_CERTMAN_LAUNCH_SELECT_IDLE:
            mmi_certman_entry_launch_certificate_manager();
            break;
        case MMI_CERTMAN_LAUNCH_SELECT_GROUP_REQ:
            more = (kal_uint32) msg;
            g_mmi_certman_context.launch_select_context_p->current_state = MMI_CERTMAN_LAUNCH_SELECT_CREATE_LIST;

            certman_send_get_cert_list_by_group_req(
                MOD_MMI,
                g_mmi_certman_context.launch_select_context_p->trans_id,
                g_mmi_certman_context.launch_select_context_p->cert_group,
                CERTMAN_KP_NONE,
                more);
            break;
        case MMI_CERTMAN_LAUNCH_SELECT_CREATE_LIST:
        {
            certman_get_cert_list_by_group_cnf_struct *group_cnf;

            group_cnf = (certman_get_cert_list_by_group_cnf_struct*) msg;
            mmi_certman_handle_error(group_cnf->status);
            if (group_cnf->status == CERTMAN_ERR_MEMFULL)
            {
                mmi_certman_exit_from_select_launch();
                break;
            }

            if (group_cnf->more > 0)
            {
                mmi_certman_update_certificate_list(group_cnf);
                g_mmi_certman_context.launch_select_context_p->current_state = MMI_CERTMAN_LAUNCH_SELECT_GROUP_REQ;
                mmi_certman_launch_select_state((void*)group_cnf->more);
                break;
            }
            else
            {
                mmi_certman_update_certificate_list(group_cnf);
                g_mmi_certman_context.launch_select_context_p->current_state = MMI_CERTMAN_LAUNCH_SELECT_DISPLAY_LIST;
                mmi_certman_launch_select_state(NULL);
                break;
            }

        }
        case MMI_CERTMAN_LAUNCH_SELECT_DISPLAY_LIST:
            if (g_mmi_certman_context.current_status == MMI_CERTMAN_LAUNCH)
            {
                mmi_certman_pre_entry_display_certificate_list();

            }
            else if (g_mmi_certman_context.current_status == MMI_CERTMAN_SELECT)
            {
                mmi_certman_pre_entry_certificates_selection_list();
            }
            return;
        case MMI_CERTMAN_LAUNCH_SELECT_VIEW_CERT:
        {
            certman_get_cert_disp_by_id_cnf_struct *disp_cnf = (certman_get_cert_disp_by_id_cnf_struct*) msg;

            g_mmi_certman_context.screen_id = 0;
            if (disp_cnf->status == CERTMAN_ERR_NONE)
            {

                mmi_certman_pre_entry_view_certificate_content();
            }
            else
            {

                if (MMI_TRUE == mmi_certman_check_screen_in_history())
                {
                    mmi_certman_handle_error_with_callback(disp_cnf->status, GoBackHistory);
                }
                else
                {
                    mmi_certman_handle_error(disp_cnf->status);
                }
            }
        }
            break;
        default:
            ASSERT(0);

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_display_authority_certificates
 * DESCRIPTION
 *  function to initialize for authority certificates
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_display_authority_certificates(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 more = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_certman_display_authority_certificates");
    g_mmi_certman_context.launch_select_context_p->cert_group = CERTMAN_CERTGRP_ROOTCA | CERTMAN_CERTGRP_CA;
    g_mmi_certman_context.popup_string_id = STR_CERTMAN_AUTHORITY_CERT;
    g_mmi_certman_context.launch_select_context_p->certificate_count = 0;
    /* g_mmi_certman_launch_context_p->key_purpose = CERTMAN_KP_NONE; */
    mmi_certman_progress_screen();

    g_mmi_certman_context.launch_select_context_p->current_state = MMI_CERTMAN_LAUNCH_SELECT_GROUP_REQ;
    mmi_certman_launch_select_state((void*)more);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_display_user_certificates
 * DESCRIPTION
 *  function to initialize for user certificates
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_display_user_certificates(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 more = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_certman_context.launch_select_context_p->cert_group = CERTMAN_CERTGRP_OTHERUSER | CERTMAN_CERTGRP_PERSONAL;
    g_mmi_certman_context.popup_string_id = STR_CERTMAN_USER_CERT;
    g_mmi_certman_context.launch_select_context_p->certificate_count = 0;
    mmi_certman_progress_screen();
    g_mmi_certman_context.launch_select_context_p->current_state = MMI_CERTMAN_LAUNCH_SELECT_GROUP_REQ;
    mmi_certman_launch_select_state((void*)more);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_update_certificate_list
 * DESCRIPTION
 *  function to update list
 * PARAMETERS
 *  group_cnf       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_update_certificate_list(certman_get_cert_list_by_group_cnf_struct *group_cnf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_certman_update_certificate_list");
    ASSERT(group_cnf->size <= CERTMAN_NUM_CERT_IN_LIST);
    for (count = 0; count < group_cnf->size; count++)
    {
        g_mmi_certman_context.launch_select_context_p->certificate_list[g_mmi_certman_context.launch_select_context_p->
                                                                        certificate_count].cert_id =
            group_cnf->cert_list[count].id;
        g_mmi_certman_context.launch_select_context_p->certificate_list[g_mmi_certman_context.launch_select_context_p->
                                                                        certificate_count].cert_group =
            group_cnf->cert_list[count].group;
        g_mmi_certman_context.launch_select_context_p->certificate_list[g_mmi_certman_context.launch_select_context_p->
                                                                        certificate_count].key_purpose =
            group_cnf->cert_list[count].key_purpose_allowed;
        g_mmi_certman_context.launch_select_context_p->certificate_list[g_mmi_certman_context.launch_select_context_p->
                                                                        certificate_count].cert_prop =
            group_cnf->cert_list[count].properties;
        mmi_certman_cert_strncpy(
            g_mmi_certman_context.launch_select_context_p->certificate_list[g_mmi_certman_context.launch_select_context_p->certificate_count].cert_label,
            group_cnf->cert_list[count].label,
            group_cnf->cert_list[count].dcs,
            CERTMAN_LABEL_SIZE);

        g_mmi_certman_context.launch_select_context_p->certificate_count++;

        ASSERT(g_mmi_certman_context.launch_select_context_p->certificate_count <= MMI_CERTMAN_CERTIFICATES_MAX);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_view_certificates
 * DESCRIPTION
 *  function to send request for certificate contents
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_view_certificates(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* get_selected_item_id(certificate_id); */
    U16 index = g_mmi_certman_context.launch_select_context_p->selected_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_certman_progress_screen();
    certman_send_get_cert_disp_by_id_req(
        MOD_MMI,
        g_mmi_certman_context.launch_select_context_p->trans_id,
        g_mmi_certman_context.launch_select_context_p->certificate_list[index].cert_id);

    g_mmi_certman_context.launch_select_context_p->current_state = MMI_CERTMAN_LAUNCH_SELECT_VIEW_CERT;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_delete_certificates
 * DESCRIPTION
 *  request to delete certificate
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_delete_certificates(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index = g_mmi_certman_context.launch_select_context_p->selected_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_certman_progress_screen();
    certman_send_delete_cert_req(
        MOD_MMI,
        g_mmi_certman_context.launch_select_context_p->trans_id,
        g_mmi_certman_context.launch_select_context_p->certificate_list[index].cert_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_delete_all_certificates
 * DESCRIPTION
 *  request to delete all certificates
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_delete_all_certificates(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_certman_progress_screen();
    certman_send_delete_all_cert_req(
        MOD_MMI,
        g_mmi_certman_context.launch_select_context_p->trans_id,
        g_mmi_certman_context.launch_select_context_p->cert_group);
}

/*********************************************************************************/
/*****************************PRIVATE KEY PASSWORD REQUEST ***********************/
/*********************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_privkey_usage_password_ind
 * DESCRIPTION
 *  function for private key password ind
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_privkey_usage_password_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    certman_privkey_usage_password_ind_struct *privkey_usage_password
        = (certman_privkey_usage_password_ind_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_certman_privkey_usage_password_ind");
    g_mmi_certman_context.priv_key_context_p = mmi_certman_malloc(sizeof(mmi_certman_private_key_context_struct));
    if (g_mmi_certman_context.priv_key_context_p == NULL)
    {
        mmi_certman_handle_error(CERTMAN_ERR_MEMFULL);
        return;
    }
    g_mmi_certman_context.priv_key_context_p->trans_id = privkey_usage_password->trans_id;
    g_mmi_certman_context.priv_key_context_p->cert_id = privkey_usage_password->cert_id;
    mmi_certman_cert_strncpy(
        g_mmi_certman_context.priv_key_context_p->label,
        privkey_usage_password->label,
        privkey_usage_password->dcs,
        CERTMAN_LABEL_SIZE);
    g_mmi_certman_context.priv_key_context_p->pwd_callback = privkey_usage_password->pcb;
    switch (privkey_usage_password->state)
    {
        case CERTMAN_PWDAUTH_FIRST:
            mmi_certman_pre_entry_get_priv_key_password();
            break;
        case CERTMAN_PWDAUTH_FAILED_RETRY_AGAIN:
            mmi_certman_display_message_with_callback(
                STR_CERTMAN_INCORRECT_PASSWORD,
                mmi_certman_pre_entry_get_priv_key_password);
            break;
        case CERTMAN_PWDAUTH_FAILED_ABORT:
            mmi_certman_display_message(STR_CERTMAN_INCORRECT_PASSWORD);
            break;
        case CERTMAN_PWDAUTH_SUCCEEDED:
            if (g_mmi_certman_context.priv_key_context_p)
            {
                mmi_certman_free(g_mmi_certman_context.priv_key_context_p);
                g_mmi_certman_context.priv_key_context_p = NULL;
            }
            g_mmi_certman_context.current_status = MMI_CERTMAN_IDLE;
            break;
        default:
            ASSERT(0);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_check_priv_key_pwd
 * DESCRIPTION
 *  function to check private key pwd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_check_priv_key_pwd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 temp_string[CERTMAN_PASSWORD_SIZE];
    U16 pwd_length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_certman_check_priv_key_pwd");
    mmi_ucs2_to_asc((S8*) temp_string, (S8*) g_mmi_certman_context.priv_key_context_p->privatekey_pwd);
    pwd_length = strlen((S8*) temp_string);
    if (g_mmi_certman_context.priv_key_context_p->pwd_callback)
    {
        g_mmi_certman_context.priv_key_context_p->pwd_callback(
                                                    g_mmi_certman_context.priv_key_context_p->trans_id,
                                                    g_mmi_certman_context.priv_key_context_p->cert_id,
                                                    (kal_uint8*) temp_string,
                                                    pwd_length);
    }
    certman_send_privkey_usage_password_rsp(MOD_MMI, g_mmi_certman_context.priv_key_context_p->trans_id, MMI_TRUE);
    if (g_mmi_certman_context.priv_key_context_p)
    {
        mmi_certman_free(g_mmi_certman_context.priv_key_context_p);
        g_mmi_certman_context.priv_key_context_p = NULL;
    }
}

/***************************************************************************/
/*****************************PRIVATE KEY CONFIRMATION**********************/
/***************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_send_privkey_usage_confirm_ind
 * DESCRIPTION
 *  function to confirm private key
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_send_privkey_usage_confirm_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    certman_privkey_usage_confirm_ind_struct *privkey_usage_confirm = (certman_privkey_usage_confirm_ind_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_certman_send_privkey_usage_confirm_ind");
    g_mmi_certman_context.priv_key_context_p = mmi_certman_malloc(sizeof(mmi_certman_private_key_context_struct));

    g_mmi_certman_context.priv_key_context_p->trans_id = privkey_usage_confirm->trans_id;
    g_mmi_certman_context.priv_key_context_p->cert_id = privkey_usage_confirm->cert_id;
    mmi_certman_cert_strncpy(
        g_mmi_certman_context.priv_key_context_p->label,
        privkey_usage_confirm->label,
        privkey_usage_confirm->dcs,
        CERTMAN_LABEL_SIZE);
    mmi_certman_priv_key_confirmation();
}

/***************************************************************************/
/*****************************View Certificate******************************/
/***************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_view_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_view_init(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_certman_view_cert_ind_struct *view_certificate_ind = (mmi_certman_view_cert_ind_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_certman_parse_begin_cnf_handler, MSG_ID_CERTMAN_PARSE_BEGIN_CNF);
    SetProtocolEventHandler(mmi_certman_certificates_detail_cnf_handler, MSG_ID_CERTMAN_PARSE_CERT_DETAIL_CNF);
    SetProtocolEventHandler(mmi_certman_import_cnf_handler, MSG_ID_CERTMAN_IMPORT_CNF);
    SetProtocolEventHandler(mmi_certman_send_parse_end_cnf_handler, MSG_ID_CERTMAN_PARSE_END_CNF);

    g_mmi_certman_context.view_invalid_context_p = mmi_certman_malloc(sizeof(mmi_certman_view_invalid_context_struct));
    g_mmi_certman_context.current_status = MMI_CERTMAN_VIEW;
    if (g_mmi_certman_context.view_invalid_context_p == NULL)
    {
        mmi_certman_handle_error(CERTMAN_ERR_MEMFULL);
        mmi_certman_view_certificates_rsp(MMI_FALSE, view_certificate_ind->trans_id);
        return;
    }
    g_mmi_certman_context.view_invalid_context_p->trans_id = view_certificate_ind->trans_id;
    g_mmi_certman_context.view_invalid_context_p->current_state = MMI_CERTMAN_VIEW_INVALID_IDLE;
    mmi_certman_view_invalid_state((void*)view_certificate_ind->filename);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_invalid_certificate_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_invalid_certificate_init(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_certman_invalid_cert_ind_struct *invalid_certificate_ind = (mmi_certman_invalid_cert_ind_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_certman_invalid_certificate_init");

    SetProtocolEventHandler(mmi_certman_parse_begin_cnf_handler, MSG_ID_CERTMAN_PARSE_BEGIN_CNF);
    SetProtocolEventHandler(mmi_certman_certificates_detail_cnf_handler, MSG_ID_CERTMAN_PARSE_CERT_DETAIL_CNF);
    SetProtocolEventHandler(mmi_certman_import_cnf_handler, MSG_ID_CERTMAN_IMPORT_CNF);
    SetProtocolEventHandler(mmi_certman_send_parse_end_cnf_handler, MSG_ID_CERTMAN_PARSE_END_CNF);

    g_mmi_certman_context.view_invalid_context_p = mmi_certman_malloc(sizeof(mmi_certman_view_invalid_context_struct));
    g_mmi_certman_context.current_status = MMI_CERTMAN_INVALID;
    if (g_mmi_certman_context.view_invalid_context_p == NULL)
    {
        mmi_certman_handle_error(CERTMAN_ERR_MEMFULL);
        mmi_certman_invalid_certificates_rsp(MMI_CERTMAN_INVALID_CERT_DENY, invalid_certificate_ind->trans_id);

        return;
    }
    g_mmi_certman_context.view_invalid_context_p->install_option = invalid_certificate_ind->disable_install_option;
    g_mmi_certman_context.view_invalid_context_p->current_state = MMI_CERTMAN_VIEW_INVALID_IDLE;
    g_mmi_certman_context.view_invalid_context_p->error = invalid_certificate_ind->error;
    g_mmi_certman_context.view_invalid_context_p->trans_id = invalid_certificate_ind->trans_id;
    mmi_certman_view_invalid_state((void*)invalid_certificate_ind->cert_filename);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_view_invalid_state
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_view_invalid_state(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    certman_error_enum error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_certman_launch_select_state");
    switch (g_mmi_certman_context.view_invalid_context_p->current_state)
    {
        case MMI_CERTMAN_VIEW_INVALID_IDLE:
        {
            U8 *filename;
            certman_encoding_enum encoding_type = 0;

            filename = (U8*) msg;
            error = certman_parse_get_encoding_type_by_file((kal_wchar*) filename, &encoding_type);
            if (error != CERTMAN_ERR_NONE)
            {
                mmi_certman_handle_error_with_callback(
                    error,
                    mmi_certman_exit_view_invalid_certificate_contents_only_with_gobackhistory);
                break;
            }
            error = certman_ctx_parse_new_by_file(
                        (kal_wchar*) filename,
                        encoding_type,
                        &(g_mmi_certman_context.view_invalid_context_p->ctx_parse_p));
            mmi_certman_handle_error(error);
            if (error != CERTMAN_ERR_NONE)
            {
                mmi_certman_handle_error_with_callback(
                    error,
                    mmi_certman_exit_view_invalid_certificate_contents_only_with_gobackhistory);
                break;
            }
            if (encoding_type == CERTMAN_ENC_DER)
            {
                mmi_certman_progress_screen();
                /* SetProtocolEventHandler(mmi_certman_parse_begin_cnf_handler, MSG_ID_CERTMAN_PARSE_BEGIN_CNF); */
                certman_send_parse_begin_req(
                    MOD_MMI,
                    g_mmi_certman_context.view_invalid_context_p->trans_id,
                    g_mmi_certman_context.view_invalid_context_p->ctx_parse_p);
                g_mmi_certman_context.view_invalid_context_p->current_state = MMI_CERTMAN_VIEW_INVALID_PARSING;
            }
            else
            {

                mmi_certman_handle_error_with_callback(
                    CERTMAN_ERR_INVALID_DATA,
                    mmi_certman_exit_view_invalid_certificate_contents_only_with_gobackhistory);
            }

        }
            break;
        case MMI_CERTMAN_VIEW_INVALID_PARSING:
        {
            certman_parse_begin_cnf_struct *parsed_begin_cnf_p;

            parsed_begin_cnf_p = (certman_parse_begin_cnf_struct*) msg;
            certman_ctx_parse_free(g_mmi_certman_context.view_invalid_context_p->ctx_parse_p);
            g_mmi_certman_context.view_invalid_context_p->job_id = parsed_begin_cnf_p->job_id;
            g_mmi_certman_context.view_invalid_context_p->trans_id = parsed_begin_cnf_p->trans_id;
            g_mmi_certman_context.view_invalid_context_p->ref_id =
                parsed_begin_cnf_p->parsed_info[CERTMAN_PARSED_CERTGRP_ALL].cert_ref_ids[0];
            /* SetProtocolEventHandler(mmi_certman_certificates_detail_cnf_handler, MSG_ID_CERTMAN_PARSE_CERT_DETAIL_CNF); */
            if (parsed_begin_cnf_p->parsed_info[CERTMAN_PARSED_CERTGRP_ALL].cert_count > 0)
            {
                /* mmi_certman_progress_screen(); */
                certman_send_parse_cert_detail_req(
                    MOD_MMI,
                    parsed_begin_cnf_p->trans_id,
                    parsed_begin_cnf_p->job_id,
                    parsed_begin_cnf_p->parsed_info[CERTMAN_PARSED_CERTGRP_ALL].cert_ref_ids[0]);
                g_mmi_certman_context.view_invalid_context_p->current_state = MMI_CERTMAN_VIEW_INVALID_DETAIL;
            }
            else
            {
                mmi_certman_exit_view_invalid_certificate_contents_only();
            }
        }
            break;
        case MMI_CERTMAN_VIEW_INVALID_DETAIL:
        {
            certman_parse_cert_detail_cnf_struct *cert_detail_p = (certman_parse_cert_detail_cnf_struct*) msg;

            if (cert_detail_p->status != CERTMAN_ERR_NONE)
            {
                mmi_certman_handle_error(error);
                mmi_certman_exit_view_invalid_certificate_contents_only();
            }
            else
            {
                g_mmi_certman_context.view_invalid_context_p->current_state = MMI_CERTMAN_VIEW_INVALID_DISPLAY;
                mmi_certman_view_invalid_state(NULL);
            }
            break;
        }
        case MMI_CERTMAN_VIEW_INVALID_DISPLAY:
            mmi_certman_pre_entry_view_certificate_contents_only();
            break;
        case MMI_CERTMAN_VIEW_INVALID_CERT_LABEL:
            mmi_certman_pre_entry_invalid_cert_label();
            break;
        case MMI_CERTMAN_VIEW_INVALID_IMPORT:
        {
            certman_import_cnf_struct *import_cnf_p;

            import_cnf_p = (certman_import_cnf_struct*) msg;
            error = import_cnf_p->status;
            /* g_mmi_certman_context.import_context_p->cert_id = import_cnf_p->cert_id; */
            if (error != CERTMAN_ERR_NONE)
            {
                if (error == CERTMAN_ERR_MEMFULL || error == CERTMAN_ERR_DISK_FULL
                    || error == CERTMAN_ERR_INVALID_JOB || error == CERTMAN_ERR_FS_ERROR)
                {
                    mmi_certman_handle_error(error);
                    mmi_certman_exit_view_invalid_certificate_contents_only();
                    break;
                }
                else
                {
                    mmi_certman_handle_error_with_callback(error, mmi_certman_import_error);
                }
            }
            certman_ctx_import_free(g_mmi_certman_context.view_invalid_context_p->ctx_import_p);
            g_mmi_certman_context.view_invalid_context_p->current_state = MMI_CERTMAN_VIEW_INVALID_PARSE_END;
            mmi_certman_display_message(STR_GLOBAL_DONE);
            g_mmi_certman_context.screen_id = 0;
            mmi_certman_invalid_certificates_rsp(
                MMI_CERTMAN_INVALID_CERT_INSTALL,
                g_mmi_certman_context.view_invalid_context_p->trans_id);

            mmi_certman_progress_screen();
            certman_send_parse_end_req(
                MOD_MMI,
                g_mmi_certman_context.view_invalid_context_p->trans_id,
                g_mmi_certman_context.view_invalid_context_p->job_id);
        }

            break;

        case MMI_CERTMAN_VIEW_INVALID_PARSE_END:
        {
            certman_parse_end_cnf_struct *parse_end_cnf_p;

            parse_end_cnf_p = (certman_parse_end_cnf_struct*) msg;
            error = parse_end_cnf_p->status;
            mmi_certman_exit_view_invalid_certificate_contents_only_with_gobackhistory();
        }
            break;
        default:
            ASSERT(g_mmi_certman_context.view_invalid_context_p->current_state <= MMI_CERTMAN_VIEW_INVALID_PARSE_END);

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_exit_view_invalid_certificate_contents_only
 * DESCRIPTION
 *  exit function for view invalid certifcate contents only
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_exit_view_invalid_certificate_contents_only(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 trans_id = g_mmi_certman_context.view_invalid_context_p->trans_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_mmi_certman_context.view_invalid_context_p->current_state)
    {
        case MMI_CERTMAN_VIEW_INVALID_IDLE:
            certman_ctx_parse_free(g_mmi_certman_context.view_invalid_context_p->ctx_parse_p);
            if (g_mmi_certman_context.current_status == MMI_CERTMAN_VIEW)
            {
                mmi_certman_view_certificates_rsp(MMI_FALSE, trans_id);
            }
            else
            {
                mmi_certman_invalid_certificates_rsp(MMI_CERTMAN_INVALID_CERT_DENY, trans_id);
            }
        case MMI_CERTMAN_VIEW_INVALID_PARSING:
            if (g_mmi_certman_context.current_status == MMI_CERTMAN_VIEW)
            {
                mmi_certman_view_certificates_rsp(MMI_FALSE, trans_id);
            }
            else
            {
                mmi_certman_invalid_certificates_rsp(MMI_CERTMAN_INVALID_CERT_DENY, trans_id);
            }
        case MMI_CERTMAN_VIEW_INVALID_DETAIL:
            if (g_mmi_certman_context.current_status == MMI_CERTMAN_VIEW)
            {
                mmi_certman_view_certificates_rsp(MMI_FALSE, trans_id);
            }
            else
            {
                mmi_certman_invalid_certificates_rsp(MMI_CERTMAN_INVALID_CERT_DENY, trans_id);
            }
            break;
        case MMI_CERTMAN_VIEW_INVALID_DISPLAY:

            break;
        case MMI_CERTMAN_VIEW_INVALID_CERT_LABEL:
            if (g_mmi_certman_context.current_status == MMI_CERTMAN_INVALID)
            {
                mmi_certman_invalid_certificates_rsp(MMI_CERTMAN_INVALID_CERT_DENY, trans_id);
            }
            else
            {
                ASSERT(0);
            }
            break;
        case MMI_CERTMAN_VIEW_INVALID_IMPORT:
            if (g_mmi_certman_context.current_status == MMI_CERTMAN_INVALID)
            {
                mmi_certman_invalid_certificates_rsp(MMI_CERTMAN_INVALID_CERT_DENY, trans_id);
            }
            else
            {
                ASSERT(0);
            }
            break;
        case MMI_CERTMAN_VIEW_INVALID_PARSE_END:
            if (g_mmi_certman_context.current_status == MMI_CERTMAN_VIEW)
            {
                mmi_certman_view_certificates_rsp(MMI_FALSE, trans_id);
            }
            break;
        default:
            ASSERT(0);

    }
    mmi_certman_view_invalid_deinit();
    g_mmi_certman_context.current_status = MMI_CERTMAN_IDLE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_view_invalid_deinit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_view_invalid_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_certman_context.view_invalid_context_p)
    {
        mmi_certman_free(g_mmi_certman_context.view_invalid_context_p);
        g_mmi_certman_context.view_invalid_context_p = NULL;
    }
    /* error = mmi_certman_mem_deinit(); */

}

/**************************************************************************/
/*****************************User Certificates List***********************/
/**************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_select_user_certificates_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_select_user_certificates_init(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_certman_select_user_certificates_init");

    SetProtocolEventHandler(
        mmi_certman_get_cert_list_by_issuers_file_cnf_handler,
        MSG_ID_CERTMAN_GET_CERT_LIST_BY_ISSUERS_FILE_CNF);
    SetProtocolEventHandler(
        mmi_certman_get_cert_list_by_issuers_data_ind_handler,
        MSG_ID_CERTMAN_GET_CERT_LIST_BY_ISSUERS_DATA_IND);

    g_mmi_certman_context.user_cert_list_context_p = mmi_certman_malloc(sizeof(mmi_certman_user_certificates_list));
    if (g_mmi_certman_context.user_cert_list_context_p == NULL)
    {
        mmi_certman_handle_error(CERTMAN_ERR_MEMFULL);
        mmi_certman_select_user_certificates_rsp(
            0,
            MMI_FALSE,
            ((mmi_certman_select_user_cert_ind_struct*) msg)->trans_id);
        return;
    }
    g_mmi_certman_context.current_status = MMI_CERTMAN_USER_CERT_LIST;
    g_mmi_certman_context.user_cert_list_context_p->current_state = MMI_CERTMAN_USER_CERT_LIST_IDLE;
    mmi_certman_select_user_certificate_state(msg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_select_user_certificate_state
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_select_user_certificate_state(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_mmi_certman_context.user_cert_list_context_p->current_state)
    {
        case MMI_CERTMAN_USER_CERT_LIST_IDLE:
        {
            mmi_certman_select_user_cert_ind_struct *user_cert_list;

            user_cert_list = (mmi_certman_select_user_cert_ind_struct*) msg;
            mmi_certman_progress_screen();
            g_mmi_certman_context.user_cert_list_context_p->trans_id = user_cert_list->trans_id;
            /* kal_wsprintf(user_cert_list->issuer_filename,"%s","c:\\tempfiles\\first_2_issuers.dat"); */
            certman_send_get_cert_list_by_issuers_file_req(
                MOD_MMI,
                g_mmi_certman_context.user_cert_list_context_p->trans_id,
                CERTMAN_CERTGRP_PERSONAL,   /* CERTMAN_CERTGRP_ROOTCA */
                user_cert_list->key_purpose,
                user_cert_list->cert_types,
                user_cert_list->cert_type_len,
                user_cert_list->issuer_filename);
            g_mmi_certman_context.user_cert_list_context_p->current_state =
                MMI_CERTMAN_USER_CERT_LIST_BY_ISSUERS_FILE_REQ;
            break;
        }
        case MMI_CERTMAN_USER_CERT_LIST_BY_ISSUERS_FILE_REQ:
        {
            certman_get_cert_list_by_issuers_file_cnf_struct *cert_list =
                (certman_get_cert_list_by_issuers_file_cnf_struct*) msg;
            g_mmi_certman_context.user_cert_list_context_p->cert_count = 0;
            if (cert_list->status != CERTMAN_ERR_NONE)
            {
                g_mmi_certman_context.screen_id = 0;
                mmi_certman_handle_error_with_callback(
                    cert_list->status,
                    mmi_certman_exit_user_certificates_list_with_goback_history);
                mmi_certman_select_user_certificates_rsp(
                    0,
                    MMI_FALSE,
                    g_mmi_certman_context.user_cert_list_context_p->trans_id);

                /* mmi_certman_exit_user_certificates_list(); */
            }
            else
            {
                if (cert_list->num_certs == 0)
                {
                    g_mmi_certman_context.screen_id = 0;
                    mmi_certman_display_message_with_callback(
                        STR_CERTMAN_CERTIFICATE_NOT_FOUND,
                        mmi_certman_exit_user_certificates_list_with_goback_history);
                    mmi_certman_select_user_certificates_rsp(
                        0,
                        MMI_TRUE,
                        g_mmi_certman_context.user_cert_list_context_p->trans_id);
                    break;
                }
                g_mmi_certman_context.user_cert_list_context_p->current_state =
                    MMI_CERTMAN_USER_CERT_LIST_BY_ISSUERS_DATA_IND;
            }
            break;
        }
        case MMI_CERTMAN_USER_CERT_LIST_BY_ISSUERS_DATA_IND:
        {
            certman_get_cert_list_by_issuers_data_ind_struct *issuer_data_ind =
                (certman_get_cert_list_by_issuers_data_ind_struct*) msg;
            certman_update_issuer_cert_list(issuer_data_ind);
            if (issuer_data_ind->last == 1)
            {
                g_mmi_certman_context.user_cert_list_context_p->current_state = MMI_CERTMAN_USER_CERT_LIST_DISPLAY;
            }
            break;

        }
        case MMI_CERTMAN_USER_CERT_LIST_DISPLAY:
        {
            mmi_certman_pre_entry_display_user_certificate_list_by_issuer();
        }
            break;
        default:
            ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  certman_update_issuer_cert_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  issuer_data     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void certman_update_issuer_cert_list(certman_get_cert_list_by_issuers_data_ind_struct *issuer_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "certman_update_issuer_cert_list");
    for (count = 0;
         count < CERTMAN_NUM_CERT_IN_LIST &&
         g_mmi_certman_context.user_cert_list_context_p->cert_count < CERTMAN_NUM_CERT_IN_LIST; count++)
    {
        g_mmi_certman_context.user_cert_list_context_p->certificate_list[g_mmi_certman_context.
                                                                         user_cert_list_context_p->cert_count].cert_id =
            issuer_data->cert_list[count].id;
        g_mmi_certman_context.user_cert_list_context_p->certificate_list[g_mmi_certman_context.
                                                                         user_cert_list_context_p->cert_count].
            cert_group = issuer_data->cert_list[count].group;
        g_mmi_certman_context.user_cert_list_context_p->certificate_list[g_mmi_certman_context.
                                                                         user_cert_list_context_p->cert_count].
            key_purpose = issuer_data->cert_list[count].key_purpose_allowed;
        g_mmi_certman_context.user_cert_list_context_p->certificate_list[g_mmi_certman_context.
                                                                         user_cert_list_context_p->cert_count].
            cert_prop = issuer_data->cert_list[count].properties;
        mmi_certman_cert_strncpy(
            g_mmi_certman_context.user_cert_list_context_p->certificate_list[g_mmi_certman_context.user_cert_list_context_p->cert_count].cert_label,
            issuer_data->cert_list[count].label,
            issuer_data->cert_list[count].dcs,
            CERTMAN_LABEL_SIZE);

        g_mmi_certman_context.user_cert_list_context_p->cert_count++;

        ASSERT(g_mmi_certman_context.user_cert_list_context_p->cert_count <= MMI_CERTMAN_CERTIFICATES_MAX);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_exit_user_certificates_list_with_goback_history
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_exit_user_certificates_list_with_goback_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackHistory();
    mmi_certman_user_certificates_list_deinit();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_exit_user_certificates_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_exit_user_certificates_list()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 trans_id = g_mmi_certman_context.user_cert_list_context_p->trans_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_mmi_certman_context.user_cert_list_context_p->current_state)
    {
        case MMI_CERTMAN_USER_CERT_LIST_IDLE:
            break;
        case MMI_CERTMAN_USER_CERT_LIST_BY_ISSUERS_FILE_REQ:
            break;
        case MMI_CERTMAN_USER_CERT_LIST_BY_ISSUERS_DATA_IND:
            break;
        case MMI_CERTMAN_USER_CERT_LIST_DISPLAY:
            break;
        default:
            ASSERT(0);
    }
    mmi_certman_select_user_certificates_rsp(0, MMI_FALSE, trans_id);
    mmi_certman_user_certificates_list_deinit();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_user_certificates_list_deinit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_user_certificates_list_deinit()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_certman_context.user_cert_list_context_p)
    {
        mmi_certman_free(g_mmi_certman_context.user_cert_list_context_p);
        g_mmi_certman_context.user_cert_list_context_p = NULL;
    }
    g_mmi_certman_context.current_status = MMI_CERTMAN_IDLE;
}

/**************************************************************************/
/*****************************Common Functions**************************/
/**************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_cert_strncpy
 * DESCRIPTION
 *  
 * PARAMETERS
 *  Destination     [IN]        
 *  Source          [IN]        
 *  dcs_type        [IN]        
 *  dest_size       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_cert_strncpy(U8 *Destination, U8 *Source, certman_dcs_enum dcs_type, U32 dest_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dcs_type == CERTMAN_DCS_ASCII)
    {
        mmi_asc_n_to_ucs2((S8*) Destination, (S8*) Source, (dest_size - ENCODING_LENGTH) / ENCODING_LENGTH);
    }
    else
    {
        mmi_ucs2ncpy((S8*) Destination, (S8*) Source, (dest_size - ENCODING_LENGTH) / ENCODING_LENGTH);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_mem_init
 * DESCRIPTION
 *  function to init buffer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_mem_init()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_certman_context.adm_id == 0)
    {
        g_mmi_certman_context.adm_id = kal_adm_create(g_mmi_certman_context.mem_pool, MMI_CERTMAN_MEM_SIZE, NULL, KAL_FALSE);
        ASSERT(g_mmi_certman_context.adm_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_malloc
 * DESCRIPTION
 *  wrapper for malloc
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *mmi_certman_malloc(kal_uint32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *mem_output_ptr = NULL;

    /* KAL_ADM_ID jdd_mem_adm_id = 0; */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_certman_context.adm_id != 0 && size > 0)
    {
        mem_output_ptr = kal_adm_alloc(g_mmi_certman_context.adm_id, size);
    }
    if (mem_output_ptr == NULL)
    {
    #ifndef __PRODUCTION_RELEASE__
        ASSERT(0);
    #endif 
    }
    memset(mem_output_ptr, 0, size);
    return mem_output_ptr;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_free
 * DESCRIPTION
 *  wrapper for free
 * PARAMETERS
 *  free_mem_p      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_free(void *free_mem_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_certman_context.adm_id != 0 && free_mem_p != NULL)
    {
        kal_adm_free(g_mmi_certman_context.adm_id, free_mem_p);
        free_mem_p = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_refresh_display_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_refresh_display_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 more = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteUptoScrID(SCR_ID_CERTMAN_CERTIFICATE_GROUPS);
    g_mmi_certman_context.launch_select_context_p->certificate_count = 0;
    mmi_certman_progress_screen();
    g_mmi_certman_context.launch_select_context_p->current_state = MMI_CERTMAN_LAUNCH_SELECT_GROUP_REQ;
    mmi_certman_launch_select_state((void*)more);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_deinit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_certman_deinit");
    switch (g_mmi_certman_context.current_status)
    {
        case MMI_CERTMAN_IMPORT:
            mmi_certman_exit_from_import();
            break;
        case MMI_CERTMAN_LAUNCH:
        case MMI_CERTMAN_SELECT:
            mmi_certman_exit_from_select_launch();
            break;
        case MMI_CERTMAN_PRIVATE_KEY_PWD:
            certman_send_privkey_usage_password_rsp(
                MOD_MMI,
                g_mmi_certman_context.priv_key_context_p->trans_id,
                MMI_FALSE);
            if (g_mmi_certman_context.priv_key_context_p)
            {
                mmi_certman_free(g_mmi_certman_context.priv_key_context_p);
                g_mmi_certman_context.priv_key_context_p = NULL;
            }
            break;
        case MMI_CERTMAN_PRIVATE_KEY_CONFIRM:
            certman_send_privkey_usage_confirm_rsp(
                MOD_MMI,
                g_mmi_certman_context.priv_key_context_p->trans_id,
                MMI_FALSE);
            if (g_mmi_certman_context.priv_key_context_p)
            {
                mmi_certman_free(g_mmi_certman_context.priv_key_context_p);
                g_mmi_certman_context.priv_key_context_p = NULL;
            }
            break;
        case MMI_CERTMAN_VIEW:
        case MMI_CERTMAN_INVALID:
            if (g_mmi_certman_context.view_invalid_context_p)
            {
                /* g_mmi_certman_context.view_invalid_context_p = NULL; */
                mmi_certman_exit_view_invalid_certificate_contents_only();
            }
            break;
        case MMI_CERTMAN_USER_CERT_LIST:
            mmi_certman_user_certificates_list_deinit();
            break;
        case MMI_CERTMAN_IDLE:
            /* Do Nothing */
            break;
        default:
            ASSERT(0);
    }
    g_mmi_certman_context.current_status = MMI_CERTMAN_IDLE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_get_cert_label
 * DESCRIPTION
 *  retrieves certificate label given the specified certificate ID
 * PARAMETERS
 *  cert_id             [IN]            ID of the certificate label to retrieve
 *  label_buffer        [IN/OUT]        Buffer provided by caller in which label will be filled into
 *  buf_size            [IN]            Buffer size (the number of usable bytes in buffer, include zero-terminate)
 * RETURNS
 *  KAL_TRUE
 *  KAL_FALSE
 *****************************************************************************/
kal_bool mmi_certman_get_cert_label(kal_uint32 cert_id, kal_uint8 *label_buffer, kal_uint32 buf_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 error;
    kal_uint8 *label;
    certman_dcs_enum dcs;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    label = mmi_certman_malloc(buf_size);

    error = certman_get_cert_label(cert_id, label, buf_size, &dcs);
    if (error == CERTMAN_ERR_NONE)
    {
        mmi_certman_cert_strncpy(label_buffer, label, dcs, buf_size);
        mmi_certman_free(label);
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}

#endif /* __CERTMAN_SUPPORT__ */ 
/* Shrikant */

