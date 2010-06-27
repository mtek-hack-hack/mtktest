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
 *  CertManMMIInterfaces.c
 *
 * Project:
 * --------
 *  Certificate Manager
 *
 * Description:
 * ------------
 *   This file is intends for handling request / responses of Certificate Manager
 *
 * Author:
 * ------------
 * -------
 *
************************************************************************************/

#ifdef __CERTMAN_SUPPORT__

#include "PixtelDataTypes.h"
#include "wgui_categories_inputs.h"
#include "CertManMMIGProts.h"
#include "CertManMMIResDef.h"
#include "CertManMMITypes.h"
#include "CertManMMIProts.h"
#include "CommonScreens.h"

/*********Global Variable**************************************************/
mmi_certman_context g_mmi_certman_context;

/**************************************************************************/
/*****************************CERTMAN'S PRIMITIVE HANDLERS*****************/
/**************************************************************************/

/**************************************************************************/
/*****************************IMPORT CERTIFICATES**************************/
/**************************************************************************/
/*
 * void test()
 * {
 * 
 * msg = g_mmi_certman_context.rsp_msg_p;
 * /StartTimer(JMMS_WAP_NOT_READY_TIMER, 5000, test);  
 * 
 * }
 */


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_parse_begin_cnf_handler
 * DESCRIPTION
 *  handler for begin parsing
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_parse_begin_cnf_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_certman_check_is_progress_screen_present() == MMI_TRUE)
    {
        if (g_mmi_certman_context.current_status == MMI_CERTMAN_VIEW
            || g_mmi_certman_context.current_status == MMI_CERTMAN_INVALID)
        {
            g_mmi_certman_context.screen_id = 0;
            mmi_certman_view_invalid_state(msg);
        }
        else
        {
            g_mmi_certman_context.screen_id = 0;
            mmi_certman_import_state(msg);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_certificates_detail_cnf_handler
 * DESCRIPTION
 *  handler for detail confirmation
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_certificates_detail_cnf_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    certman_parse_cert_detail_cnf_struct *cert_detail_p = (certman_parse_cert_detail_cnf_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_certman_check_is_progress_screen_present() == MMI_TRUE)
    {
        if (g_mmi_certman_context.current_status == MMI_CERTMAN_VIEW
            || g_mmi_certman_context.current_status == MMI_CERTMAN_INVALID)
        {
            g_mmi_certman_context.view_invalid_context_p->parsed_data_p = cert_detail_p->parsed_data;
            mmi_certman_view_invalid_state(msg);
        }
        else
        {
            g_mmi_certman_context.import_context_p->parsed_data_p = cert_detail_p->parsed_data;
            mmi_certman_import_state(msg);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_import_cnf_handler
 * DESCRIPTION
 *  handler import confirmation
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_import_cnf_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_certman_check_is_progress_screen_present() == MMI_TRUE)
    {
        if (g_mmi_certman_context.current_status == MMI_CERTMAN_INVALID)
        {
            g_mmi_certman_context.screen_id = 0;
            mmi_certman_view_invalid_state(msg);
        }
        else
        {
            g_mmi_certman_context.screen_id = 0;
            mmi_certman_import_state(msg);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_import_update_key_purpose_cnf_handler
 * DESCRIPTION
 *  handler for update key purpose cnf
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_import_update_key_purpose_cnf_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_certman_check_is_progress_screen_present() == MMI_TRUE)
    {
        g_mmi_certman_context.screen_id = 0;
        mmi_certman_import_state(msg);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_send_parse_end_cnf_handler
 * DESCRIPTION
 *  handler for parse end cnf
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_send_parse_end_cnf_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_certman_check_is_progress_screen_present() == MMI_TRUE)
    {
        g_mmi_certman_context.screen_id = 0;
        if (g_mmi_certman_context.current_status == MMI_CERTMAN_VIEW
            || g_mmi_certman_context.current_status == MMI_CERTMAN_INVALID)
        {
            mmi_certman_view_invalid_state(msg);
        }
        else
        {
            mmi_certman_exit_from_import();
        }
    }
}

/**************************************************************************/
/*****************************lAUNCH / SELECT CERTIFICATES*****************/
/**************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_get_cert_list_by_group_cnf_handler
 * DESCRIPTION
 *  handler for group cnf
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_get_cert_list_by_group_cnf_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_certman_check_is_progress_screen_present() == MMI_TRUE)
    {
        mmi_certman_launch_select_state(msg);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_send_get_cert_disp_by_id_cnf_handler
 * DESCRIPTION
 *  handler for cert by id cnf
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_send_get_cert_disp_by_id_cnf_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    certman_get_cert_disp_by_id_cnf_struct *disp_cnf = (certman_get_cert_disp_by_id_cnf_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_certman_context.launch_select_context_p->display_p = &(disp_cnf->cert);
    if (mmi_certman_check_is_progress_screen_present() == MMI_TRUE)
    {
        mmi_certman_launch_select_state(msg);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_launch_update_key_purpose_cnf_handler
 * DESCRIPTION
 *  handler for update key purpose in launch
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_launch_update_key_purpose_cnf_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    certman_update_key_purpose_cnf_struct *key_purpose_cnf = (certman_update_key_purpose_cnf_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_certman_check_is_progress_screen_present() == MMI_TRUE)
    {
        g_mmi_certman_context.screen_id = 0;
        if (key_purpose_cnf->status == CERTMAN_ERR_NONE)
        {
            if (MMI_TRUE == mmi_certman_check_screen_in_history())
            {
                DeleteScreenIfPresent(SCR_ID_CERTMAN_PROGRESS_SCREEN);
            }
            else
            {
                GoBackHistory();
            }

        }
        else
        {
            mmi_certman_handle_error(key_purpose_cnf->status);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_send_delete_cert_cnf_handler
 * DESCRIPTION
 *  handler for delete cnf
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_send_delete_cert_cnf_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    certman_delete_cert_cnf_struct *delete_cnf = (certman_delete_cert_cnf_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_certman_check_is_progress_screen_present() == MMI_TRUE)
    {
        g_mmi_certman_context.screen_id = 0;
        if (delete_cnf->status == CERTMAN_ERR_NONE)
        {
            if (certman_get_cert_count(g_mmi_certman_context.launch_select_context_p->cert_group, CERTMAN_KP_NONE))
            {
                mmi_certman_display_message_with_callback(STR_GLOBAL_DONE, mmi_certman_refresh_display_list);
            }
            else
            {
                if (mmi_certman_check_screen_in_history() == MMI_TRUE)
                {
                    U16 scr_id;

                    GetPreviousScrnIdOf(SCR_ID_CERTMAN_PROGRESS_SCREEN, &scr_id);
                    DeleteFromScrUptoScr(scr_id, SCR_ID_CERTMAN_CERTIFICATE_GROUPS);
                }
                else
                {
                    DeleteUptoScrID(SCR_ID_CERTMAN_CERTIFICATE_GROUPS);
                }
                mmi_certman_display_message(STR_GLOBAL_DONE);
            }
        }
        else
        {
            if (mmi_certman_check_screen_in_history() == MMI_TRUE)
            {
                U16 scr_id;

                GetPreviousScrnIdOf(SCR_ID_CERTMAN_PROGRESS_SCREEN, &scr_id);
                DeleteFromScrUptoScr(scr_id, SCR_ID_CERTMAN_CERTIFICATE_LIST);
            }
            else
            {
                DeleteUptoScrID(SCR_ID_CERTMAN_CERTIFICATE_LIST);
            }
            mmi_certman_handle_error(delete_cnf->status);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_send_delete_all_cert_cnf_handler
 * DESCRIPTION
 *  handler for delete all cnf
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_send_delete_all_cert_cnf_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    certman_delete_all_cert_cnf_struct *delete_all_cnf = (certman_delete_all_cert_cnf_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_certman_check_is_progress_screen_present() == MMI_TRUE)
    {
        g_mmi_certman_context.screen_id = 0;
        if (mmi_certman_check_screen_in_history() == MMI_TRUE)
        {
            U16 scr_id;

            GetPreviousScrnIdOf(SCR_ID_CERTMAN_PROGRESS_SCREEN, &scr_id);
            DeleteFromScrUptoScr(scr_id, SCR_ID_CERTMAN_CERTIFICATE_GROUPS);
        }
        else
        {
            DeleteUptoScrID(SCR_ID_CERTMAN_CERTIFICATE_GROUPS);
        }
        if (delete_all_cnf->status == CERTMAN_ERR_NONE)
        {
            mmi_certman_display_message(STR_GLOBAL_DONE);
        }
        else
        {
            mmi_certman_handle_error(delete_all_cnf->status);
        }
    }
}

/*********************************************************************************/
/*****************************Personal Certificate List***************************/
/*********************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_get_cert_list_by_issuers_file_cnf_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_get_cert_list_by_issuers_file_cnf_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_certman_check_is_progress_screen_present() == MMI_TRUE)
    {
        if (g_mmi_certman_context.current_status == MMI_CERTMAN_USER_CERT_LIST)
        {
            mmi_certman_select_user_certificate_state(msg);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_get_cert_list_by_issuers_data_ind_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]    
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_get_cert_list_by_issuers_data_ind_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if(g_mmi_certman_context.user_cert_list_context_p->current_state == MMI_CERTMAN_USER_CERT_LIST_BY_ISSUERS_DATA_IND) */
    {
        if (mmi_certman_check_is_progress_screen_present() == MMI_TRUE)
        {
            if (g_mmi_certman_context.current_status == MMI_CERTMAN_USER_CERT_LIST)
            {
                mmi_certman_select_user_certificate_state(msg);
            }
        }
    }
}

/*********************************************************************************/
/*****************************PRIVATE KEY PASSWORD REQUEST ***********************/
/*********************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_privkey_usage_password_ind_handler
 * DESCRIPTION
 *  handler for pwd ind
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_privkey_usage_password_ind_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_certman_context.current_status = MMI_CERTMAN_PRIVATE_KEY_PWD;
    mmi_certman_privkey_usage_password_ind(msg);

}

/***************************************************************************/
/*****************************PRIVATE KEY CONFIRMATION**********************/
/***************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_send_privkey_usage_confirm_ind_handler
 * DESCRIPTION
 *  handler for confirm ind
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_send_privkey_usage_confirm_ind_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_certman_context.current_status = MMI_CERTMAN_PRIVATE_KEY_CONFIRM;
    mmi_certman_send_privkey_usage_confirm_ind(msg);

}

/**************************************************************************/
/*****************************CERTMAN UI Primitives************************/
/**************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_install_certificates_ind
 * DESCRIPTION
 *  function to install certificate indication
 * PARAMETERS
 *  src_mod         [IN]        
 *  action          [IN]        
 *  trans_id        [IN]        
 *  filename        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_install_certificates_ind(
        module_type src_mod,
        kal_bool action,
        kal_uint32 trans_id,
        kal_wchar *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_certman_install_cert_ind_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Allocate memory. */
    mmi_certman_progress_screen();
    data = (mmi_certman_install_cert_ind_struct*) OslConstructDataPtr(sizeof(mmi_certman_install_cert_ind_struct));
    mmi_ucs2cpy((S8*) data->cert_filename, (S8*) filename);
    data->action = action;
    data->trans_id = trans_id;
    g_mmi_certman_context.src_module = src_mod;
    mmi_certman_send_msg_on_queue(
        g_mmi_certman_context.src_module,
        MOD_MMI,
        (void*)data,
        MSG_ID_MMI_CERTMAN_INSTALL_CERT_IND);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_install_certificates_ind_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_install_certificates_ind_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_certman_install_cert_ind_struct *install_certificate_ind = (mmi_certman_install_cert_ind_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_certman_check_is_progress_screen_present() == MMI_TRUE)
    {
        g_mmi_certman_context.screen_id = 0;
        if (install_certificate_ind->action == MMI_CERTMAN_CANCEL)
        {
            if (g_mmi_certman_context.import_context_p != NULL)
            {
                mmi_certman_exit_from_import();
            }
            mmi_certman_install_certificates_rsp(MMI_FALSE, install_certificate_ind->trans_id);
        }
        else
        {
            mmi_certman_import_init(msg);
        }
    }
    return;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_install_certificates_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  trans_id        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_install_certificates_rsp(kal_bool result, kal_uint32 trans_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_certman_install_cert_rsp_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Allocate memory. */

    data = (mmi_certman_install_cert_rsp_struct*) OslConstructDataPtr(sizeof(mmi_certman_install_cert_rsp_struct));
    data->result = result;
    data->trans_id = trans_id;
    /* Send the response message. */
    mmi_certman_send_msg_on_queue(
        MOD_MMI,
        g_mmi_certman_context.src_module,
        (void*)data,
        MSG_ID_MMI_CERTMAN_INSTALL_CERT_RSP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_launch_certificates_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod         [IN]        
 *  action          [IN]        
 *  trans_id        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_launch_certificates_ind(module_type src_mod, kal_bool action, kal_uint32 trans_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_certman_launch_cert_ind_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Allocate memory. */
    mmi_certman_progress_screen();
    data = (mmi_certman_launch_cert_ind_struct*) OslConstructDataPtr(sizeof(mmi_certman_launch_cert_ind_struct));
    data->action = action;
    data->trans_id = trans_id;
    g_mmi_certman_context.src_module = src_mod;
    mmi_certman_send_msg_on_queue(
        g_mmi_certman_context.src_module,
        MOD_MMI,
        (void*)data,
        MSG_ID_MMI_CERTMAN_LAUNCH_CERT_IND);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_launch_certificates_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  trans_id        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_launch_certificates_rsp(kal_bool result, kal_uint32 trans_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_certman_launch_cert_rsp_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*  Allocate memory  */

    data = (mmi_certman_launch_cert_rsp_struct*) OslConstructDataPtr(sizeof(mmi_certman_launch_cert_rsp_struct));
    data->result = result;
    data->trans_id = trans_id;
    /* Send the response message */
    mmi_certman_send_msg_on_queue(
        MOD_MMI,
        g_mmi_certman_context.src_module,
        (void*)data,
        MSG_ID_MMI_CERTMAN_LAUNCH_CERT_RSP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_launch_certificates_ind_handler
 * DESCRIPTION
 *  function to launch CM
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_launch_certificates_ind_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_certman_launch_cert_ind_struct *launch_certificate_ind = (mmi_certman_launch_cert_ind_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_certman_check_is_progress_screen_present() == MMI_TRUE)
    {
        g_mmi_certman_context.screen_id = 0;
        if (launch_certificate_ind->action == MMI_CERTMAN_CANCEL)
        {
            if (g_mmi_certman_context.launch_select_context_p != NULL)
            {
                mmi_certman_exit_from_select_launch();
            }
            mmi_certman_launch_certificates_rsp(MMI_FALSE, launch_certificate_ind->trans_id);
        }
        else
        {
            mmi_certman_launch_init(msg);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_select_certificates_ind
 * DESCRIPTION
 *  function to select certificate
 * PARAMETERS
 *  src_mod                     [IN]        
 *  action                      [IN]        
 *  multiple_selection_flag     [IN]        
 *  trans_id                    [IN]        
 *  cert_group                  [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_select_certificates_ind(
        module_type src_mod,
        kal_bool action,
        kal_bool multiple_selection_flag,
        kal_uint32 trans_id,
        mmi_certman_cert_group_enum cert_group)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_certman_select_cert_ind_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Allocate memory. */
    mmi_certman_progress_screen();
    data = (mmi_certman_select_cert_ind_struct*) OslConstructDataPtr(sizeof(mmi_certman_select_cert_ind_struct));
    data->action = action;
    data->trans_id = trans_id;
    data->multiple_selection_flag = multiple_selection_flag;
    data->cert_group = cert_group;
    g_mmi_certman_context.src_module = src_mod;
    mmi_certman_send_msg_on_queue(
        g_mmi_certman_context.src_module,
        MOD_MMI,
        (void*)data,
        MSG_ID_MMI_CERTMAN_SELECT_CERT_IND);
    /* Send the response message.
       Message.oslSrcId = g_mmi_certman_context.src_module;
       Message.oslDestId = MOD_MMI;
       Message.oslMsgId = MSG_ID_MMI_CERTMAN_SELECT_CERT_IND;
       Message.oslDataPtr = (oslParaType*) data;
       Message.oslPeerBuffPtr = NULL;
       OslMsgSendExtQueue(&Message); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_select_certificates_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result              [IN]        
 *  count               [IN]        
 *  certificate_ids     [IN]        
 *  trans_id            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_select_certificates_rsp(
        kal_bool result,
        kal_uint32 count,
        kal_uint32 *certificate_ids,
        kal_uint32 trans_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_certman_select_cert_rsp_struct *data;
    U16 temp_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Allocate memory. */
    data = (mmi_certman_select_cert_rsp_struct*) OslConstructDataPtr(sizeof(mmi_certman_select_cert_rsp_struct));
    data->result = result;
    data->trans_id = trans_id;
    if (result == MMI_TRUE)
    {
        data->count = count;
        for (temp_count = 0; temp_count < count; temp_count++)
        {
            data->cert_ids[temp_count] = certificate_ids[temp_count];
        }
    }

    /* Send the response message. */
    mmi_certman_send_msg_on_queue(
        MOD_MMI,
        g_mmi_certman_context.src_module,
        (void*)data,
        MSG_ID_MMI_CERTMAN_SELECT_CERT_RSP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_select_certificates_ind_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_select_certificates_ind_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_certman_select_cert_ind_struct *select_certificate_ind = (mmi_certman_select_cert_ind_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_certman_check_is_progress_screen_present() == MMI_TRUE)
    {
        g_mmi_certman_context.screen_id = 0;
        if (select_certificate_ind->action == MMI_CERTMAN_CANCEL)
        {
            if (g_mmi_certman_context.launch_select_context_p != NULL)
            {
                mmi_certman_exit_from_select_launch();
            }
            mmi_certman_select_certificates_rsp(MMI_FALSE, 0, 0, select_certificate_ind->trans_id);
        }
        else
        {
            mmi_certman_select_init(msg);

        }
    }
}


/*****************************************************************************
 *  
 * FUNCTION
 *  mmi_certman_view_certificates_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod         [IN]        
 *  action          [IN]        
 *  file_name       [IN]       
 *  trans_id        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_view_certificates_ind(module_type src_mod, kal_bool action, kal_wchar *file_name, kal_uint32 trans_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_certman_view_cert_ind_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_certman_progress_screen();
    /* Allocate memory. */
    data = (mmi_certman_view_cert_ind_struct*) OslConstructDataPtr(sizeof(mmi_certman_view_cert_ind_struct));
    data->action = action;
    data->trans_id = trans_id;
    mmi_ucs2cpy((S8*) data->filename, (S8*) file_name);
    g_mmi_certman_context.src_module = src_mod;
    mmi_certman_send_msg_on_queue(
        g_mmi_certman_context.src_module,
        MOD_MMI,
        (void*)data,
        MSG_ID_MMI_CERTMAN_VIEW_CERT_IND);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_view_certificates_ind_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_view_certificates_ind_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_certman_view_cert_ind_struct *view_certificate_ind = (mmi_certman_view_cert_ind_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_certman_check_is_progress_screen_present() == MMI_TRUE)
    {
        g_mmi_certman_context.screen_id = 0;
        if (view_certificate_ind->action == MMI_CERTMAN_CANCEL)
        {
            mmi_certman_install_certificates_rsp(MMI_FALSE, view_certificate_ind->trans_id);
        }
        else
        {
            mmi_certman_view_init(msg);
        }
    }
    return;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_view_certificates_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  trans_id        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_view_certificates_rsp(kal_bool result, kal_uint32 trans_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_certman_view_cert_rsp_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Allocate memory. */

    data = (mmi_certman_view_cert_rsp_struct*) OslConstructDataPtr(sizeof(mmi_certman_view_cert_rsp_struct));
    data->result = result;
    data->trans_id = trans_id;
    /* Send the response message. */
    mmi_certman_send_msg_on_queue(
        MOD_MMI,
        g_mmi_certman_context.src_module,
        (void*)data,
        MSG_ID_MMI_CERTMAN_VIEW_CERT_RSP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_invalid_certificates_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod             [IN]        
 *  action              [IN]        
 *  disable_install     [IN]        
 *  error               [IN]        
 *  mod_name            [IN]         
 *  cert_filename       [IN]         
 *  trans_id            [IN]        
 *  filename(?)         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_invalid_certificates_ind(
        module_type src_mod,
        kal_bool action,
        kal_bool disable_install,
        kal_uint32 error,
        kal_wchar *mod_name,
        kal_wchar *cert_filename,
        kal_uint32 trans_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_certman_invalid_cert_ind_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Allocate memory. */
    mmi_certman_progress_screen();
    data = (mmi_certman_invalid_cert_ind_struct*) OslConstructDataPtr(sizeof(mmi_certman_invalid_cert_ind_struct));

    data->action = action;
    data->trans_id = trans_id;
    data->disable_install_option = disable_install;
    data->error = error;
    mmi_ucs2cpy((S8*) data->mod_name, (S8*) mod_name);
    mmi_ucs2cpy((S8*) data->cert_filename, (S8*) cert_filename);
    g_mmi_certman_context.src_module = src_mod;
    /* Send the response message. */
    mmi_certman_send_msg_on_queue(
        g_mmi_certman_context.src_module,
        MOD_MMI,
        (void*)data,
        MSG_ID_MMI_CERTMAN_INVALID_CERT_IND);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_invalid_certificates_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  invalid_cert_action     [IN]        
 *  trans_id                [IN]        
 *  result                  [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_invalid_certificates_rsp(kal_uint16 invalid_cert_action, kal_uint32 trans_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_certman_invalid_cert_rsp_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Allocate memory. */

    data = (mmi_certman_invalid_cert_rsp_struct*) OslConstructDataPtr(sizeof(mmi_certman_invalid_cert_rsp_struct));
    data->invalid_cert_action = invalid_cert_action;
    data->trans_id = trans_id;
    /* Send the response message. */
    mmi_certman_send_msg_on_queue(
        MOD_MMI,
        g_mmi_certman_context.src_module,
        (void*)data,
        MSG_ID_MMI_CERTMAN_INVALID_CERT_RSP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_invalid_certificates_ind_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_invalid_certificates_ind_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_certman_invalid_cert_ind_struct *invalid_certificate_ind = (mmi_certman_invalid_cert_ind_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_certman_check_is_progress_screen_present() == MMI_TRUE)
    {
        g_mmi_certman_context.screen_id = 0;
        if (invalid_certificate_ind->action == MMI_CERTMAN_CANCEL)
        {
            mmi_certman_invalid_certificates_rsp(MMI_CERTMAN_INVALID_CERT_DENY, invalid_certificate_ind->trans_id);
        }
        else
        {
            mmi_certman_invalid_certificate_init(msg);
            /* mmi_certman_invalid_certificate_start(invalid_certificate_ind->cert_filename); */
        }
    }
    return;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_select_user_certificates_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod                 [IN]        
 *  action                  [IN]        
 *  key_purpose             [IN]        
 *  cert_type_len           [IN]        
 *  cert_types              [IN]         
 *  mod_name                [IN]         
 *  issuers_filename        [IN]         
 *  trans_id                [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_select_user_certificates_ind(
        module_type src_mod,
        kal_bool action,
        kal_uint32 key_purpose,
        kal_uint8 cert_type_len,
        kal_uint8 *cert_types,
        kal_wchar *mod_name,
        kal_wchar *issuers_filename,
        kal_uint32 trans_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_certman_select_user_cert_ind_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Allocate memory. */
    mmi_certman_progress_screen();
    data =
        (mmi_certman_select_user_cert_ind_struct*)
        OslConstructDataPtr(sizeof(mmi_certman_select_user_cert_ind_struct));

    data->action = action;
    data->trans_id = trans_id;
    data->key_purpose = key_purpose;
    data->cert_type_len = cert_type_len;
    memcpy((S8*) data->cert_types, (S8*) cert_types, data->cert_type_len);
    mmi_ucs2cpy((S8*) data->mod_name, (S8*) mod_name);
    mmi_ucs2cpy((S8*) data->issuer_filename, (S8*) issuers_filename);
    g_mmi_certman_context.src_module = src_mod;
    mmi_certman_send_msg_on_queue(
        g_mmi_certman_context.src_module,
        MOD_MMI,
        (void*)data,
        MSG_ID_MMI_CERTMAN_SELECT_USER_CERT_IND);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_select_user_certificates_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cert_id         [IN]        
 *  result          [IN]        
 *  trans_id        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_select_user_certificates_rsp(kal_uint32 cert_id, kal_bool result, kal_uint32 trans_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_certman_select_user_cert_rsp_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Allocate memory. */

    data =
        (mmi_certman_select_user_cert_rsp_struct*)
        OslConstructDataPtr(sizeof(mmi_certman_select_user_cert_rsp_struct));
    data->personal_cert_id = cert_id;
    data->result = result;
    data->trans_id = trans_id;
    /* Send the response message */
    mmi_certman_send_msg_on_queue(
        MOD_MMI,
        g_mmi_certman_context.src_module,
        (void*)data,
        MSG_ID_MMI_CERTMAN_SELECT_USER_CERT_RSP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_send_msg_on_queue
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod         [IN]        
 *  dest_mod        [IN]        
 *  data            [IN]         
 *  msg_id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_send_msg_on_queue(module_type src_mod, module_type dest_mod, void *data, U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = src_mod;
    Message.oslDestId = dest_mod;
    Message.oslMsgId = msg_id;
    Message.oslSapId = MMI_CERTMAN_APP_SAP;
    Message.oslDataPtr = (oslParaType*) data;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_select_user_certificates_ind_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_select_user_certificates_ind_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_certman_select_user_cert_ind_struct *invalid_certificate_ind = (mmi_certman_select_user_cert_ind_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_certman_check_is_progress_screen_present() == MMI_TRUE)
    {
        g_mmi_certman_context.screen_id = 0;
        if (invalid_certificate_ind->action == MMI_CERTMAN_CANCEL)
        {
            mmi_certman_select_user_certificates_rsp(0, MMI_FALSE, invalid_certificate_ind->trans_id);
        }
        else
        {
            mmi_certman_select_user_certificates_init(msg);
        }
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_highlight_install
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_highlight_install(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(mmi_certman_pre_enter_install, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_certman_pre_enter_install, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_highlight_launch_certficate_manager
 * DESCRIPTION
 *  hilite handler for certificate manager
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_certman_highlight_launch_certficate_manager(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_certman_launch_certficate_manager, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_install_da_file
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
void mmi_certman_install_da_file(
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

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_certman_install_certificates_ind(MOD_MMI, MMI_CERTMAN_OPEN, 1, (kal_wchar*) filename);
}
#endif /* __CERTMAN_SUPPORT__ */ 

