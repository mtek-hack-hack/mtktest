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
 * EmailAppMiscell.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements miscell utilities for Email application.
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
 /**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/**************************************************************

   FILENAME : EmailAppMiscell.c

   PURPOSE     : nil

   REMARKS     : nil

   AUTHOR      : Magesh k

   DATE     : 30-01-2004

**************************************************************/
#include "MMI_include.h"
#ifndef _MMI_EMAILAPPMISCELL_C
#define _MMI_EMAILAPPMISCELL_C

#ifdef __MMI_EMAIL__

#include "Fmt_struct.h"
#include "Conversions.h"
#include "app_mine.h"
#include "CommonScreens.h"
#include "gpioinc.h"
#include "wgui_status_icons.h"
#ifdef __MMI_UCM__
#include "UCMGProt.h"
#endif
#include "CallManagementGprot.h"
#ifdef __MMI_EMAIL_DRM_SUPPORT__
#include "Drm_gprot.h"
#endif 
#include "SimDetectionGprot.h"
#ifdef __USB_IN_NORMAL_MODE__
#include "USBDeviceGprot.h"
#endif
#ifdef __MMI_WLAN_FEATURES__
#include "NetworkSetupDefs.h"
#endif
#ifdef __MMI_DUAL_SIM_MASTER__
#include "mtpnp_ad_master_common_def.h"
#include "mtpnp_ad_master_if.h"
#endif
#include "FileManagerGProt.h"
#include "EmailAppResDef.h"
#include "EmailAppProt.h"
#include "EmailAppGProt.h"
#if defined(__MMI_EMAIL_TEMPLATE__)
#include "Nvram_common_defs.h"
#include "SSCStringHandle.h"
#endif /* defined(__MMI_EMAIL_TEMPLATE__) */

#if defined(__MMI_EMAIL_TEMPLATE__)
const U16 email_template_strings[] = 
{
    STR_EMAIL_TEMPLATE_1,
    STR_EMAIL_TEMPLATE_2,
    STR_EMAIL_TEMPLATE_3,
    STR_EMAIL_TEMPLATE_4,
    STR_EMAIL_TEMPLATE_5,
    STR_EMAIL_TEMPLATE_6,
    STR_EMAIL_TEMPLATE_7,
    STR_EMAIL_TEMPLATE_8,
    STR_EMAIL_TEMPLATE_9,
    STR_EMAIL_TEMPLATE_10
};

#define MMI_EMAIL_TOTAL_TEMPLATE_LANGUAGE        3
extern pBOOL IsTrChineseSet(void); /*IdleAppProt.h, IdleApp.c*/
extern pBOOL IsSmChineseSet(void);
extern void mmi_frm_add_history_before_cm_marker(U16 scrn_id, FuncPtr func_ptr);
#ifdef __MMI_VOIP__
extern U16 mmi_voip_app_get_marker_screen(void);
extern S32 mmi_voip_app_total_call(void);
#endif

static U8 curr_lang[SSC_SIZE]; /*to temporarily save current phone language, in order to recover*/
extern sLanguageDetails *gLanguageArray;
extern U16 gCurrLangIndex;
#endif /* defined(__MMI_EMAIL_TEMPLATE__) */
#ifdef __MMI_EMAIL_DRM_SUPPORT__
BOOL drm_file_ignore;
#endif


const mmi_email_err_string_struct g_email_err_tbl[] = 
{
    {MMI_EMAIL_ACCT_NOT_CONFIG, STR_EMAIL_ERROR_CODE_ACCT_NOT_CONFIG_ID},
    {MMI_EMAIL_INVALID_ACCT_INDEX, STR_EMAIL_ERROR_CODE_INVALID_ACCT_INDEX_ID},
    {MMI_EMAIL_FOLDER_NOT_EXISTING, STR_EMAIL_ERROR_CODE_FOLDER_NOT_EXISTING_ID},
    {MMI_EMAIL_MSG_NOT_EXISTING, STR_EMAIL_ERROR_CODE_MSG_NOT_EXISTING_ID},
    {MMI_EMAIL_CONN_FAIL, STR_EMAIL_ERROR_CODE_CONN_FAIL_ID},
    {MMI_EMAIL_AUTH_FAIL, STR_EMAIL_ERROR_CODE_AUTH_FAIL_ID},
    {MMI_EMAIL_BAD_PAGE_NUMBER, STR_EMAIL_ERROR_CODE_BAD_PAGE_NUMBER_ID},
    {MMI_EMAIL_READ_ONLY_ACCESS, STR_EMAIL_READ_ONLY_ACCESS},
    {MMI_EMAIL_DNS_ERR, STR_EMAIL_DNS_ERR},
    {MMI_EMAIL_APP_SOC_TIMEOUT_ERR, STR_EMAIL_ERROR_CODE_APP_SOC_TIMEOUT_ERR_ID},
    {MMI_EMAIL_GET_HOST_TIMEOUT_ERR, STR_EMAIL_ERROR_CODE_APP_SOC_TIMEOUT_ERR_ID},
    {MMI_EMAIL_POP3_MSG_XACTION_ERR, STR_EMAIL_ERROR_CODE_POP_CMD},
    {MMI_EMAIL_POP3_SESSION_QUIT_ERR, STR_EMAIL_ERROR_CODE_POP_CMD},
    {MMI_EMAIL_POP3_FSM_ERR, STR_EMAIL_ERROR_CODE_POP_CMD},
    {MMI_EMAIL_INVALID_FOLDER_ID, STR_EMAIL_ERROR_CODE_FOLDER_NOT_EXISTING_ID},
    {MMI_EMAIL_MEMORY_ALLOC_FAIL, STR_EMAIL_MEMORY_FULL_ID},
    {MMI_EMAIL_SMTP_RCPT_TO_FAIL, STR_EMAIL_SMTP_RCPT_TO_FAIL},
    {MMI_EMAIL_INVALID_PORT_NUM, STR_EMAIL_ERROR_CODE_INVALID_PORT_NUM_ID},
    {MMI_EMAIL_INVALID_IP_ADDR, STR_EMAIL_ERROR_CODE_INVALID_IP_ADDR_ID},
    {MMI_EMAIL_INVALID_FILE_PATH, STR_EMAIL_WRONG_SETTINGS},
    {MMI_EMAIL_INVALID_EMAIL_ADDR_LEN, STR_EMAIL_WRONG_SETTINGS},
    {MMI_EMAIL_INVALID_DISP_NAME_LEN, STR_EMAIL_WRONG_SETTINGS},
    {MMI_EMAIL_INVALID_USR_LEN, STR_EMAIL_WRONG_SETTINGS},
    {MMI_EMAIL_INVALID_PASS_LEN, STR_EMAIL_WRONG_SETTINGS},
    {MMI_EMAIL_INVALID_ACCT_NAME_LEN, STR_EMAIL_WRONG_SETTINGS},
    {MMI_EMAIL_INVALID_SERVER_NAME_LEN, STR_EMAIL_WRONG_SETTINGS},
    {MMI_EMAIL_INVALID_SERVICE_TYPE, STR_EMAIL_WRONG_SETTINGS},
    {MMI_EMAIL_INVALID_IN_PROTOCOL, STR_EMAIL_WRONG_SETTINGS},
    {MMI_EMAIL_INVALID_CHK_INT, STR_EMAIL_WRONG_SETTINGS},
    {MMI_EMAIL_INVALID_SIGNATURE_LEN, STR_EMAIL_WRONG_SETTINGS},
    {MMI_EMAIL_INVALID_DOWNLOAD_SIZE, STR_EMAIL_WRONG_SETTINGS},
    {MMI_EMAIL_INVALID_FOLDER_NAME_LEN, STR_EMAIL_WRONG_SETTINGS},
    {MMI_EMAIL_SMTP_VERSION_STATE_FAIL, STR_EMAIL_ERROR_CODE_SMTP_CMD},
    {MMI_EMAIL_SMTP_MAIL_FROM_FAIL, STR_EMAIL_ERROR_CODE_SMTP_CMD},
    {MMI_EMAIL_SMTP_GREET_FAIL, STR_EMAIL_ERROR_CODE_SMTP_CMD},
    {MMI_EMAIL_MAIL_DATA_END_FAIL, STR_EMAIL_ERROR_CODE_SMTP_CMD},
    {MMI_EMAIL_SMTP_RCPT_TO_FAIL, STR_EMAIL_ERROR_CODE_SMTP_CMD},
    {MMI_EMAIL_SMTP_DATA_FAIL, STR_EMAIL_ERROR_CODE_SMTP_CMD},
    {MMI_EMAIL_INVALID_FOLDER_NAME_LEN, STR_EMAIL_ERROR_CODE_SMTP_CMD},
    {MMI_EMAIL_INVALID_FOLDER_NAME_LEN, STR_EMAIL_ERROR_CODE_SMTP_CMD},
    {MMI_EMAIL_INVALID_FOLDER_NAME_LEN, STR_EMAIL_ERROR_CODE_SMTP_CMD},
    {MMI_EMAIL_EXCEEDED_MSG_CNT, STR_EMAIL_MEMORY_FULL_ID},
    {MMI_EMAIL_ERROR_MSG_REQ, STR_EMAIL_ERROR_MSG_REQ}, /* shall add assertion */
    {MMI_EMAIL_FILE_QUOTA_EXCEEDED, STR_EMAIL_FILE_QUOTA_EXCEEDED},
    {MMI_EMAIL_IMAP_CLOSE_ERROR, STR_EMAIL_ERROR_CODE_IMAP_CMD},
    {MMI_EMAIL_IMAP_SELECT_ERROR, STR_EMAIL_ERROR_CODE_IMAP_CMD},
    {MMI_EMAIL_IMAP_FETCH_ERROR, STR_EMAIL_ERROR_CODE_IMAP_CMD},
    {MMI_EMAIL_IMAP_STORE_ERROR, STR_EMAIL_ERROR_CODE_IMAP_CMD},
    {MMI_EMAIL_IMAP_LOGOUT_FAIL, STR_EMAIL_ERROR_CODE_IMAP_CMD},
    {MMI_EMAIL_SELECT_FOLDER_FAIL, STR_EMAIL_ERROR_CODE_IMAP_CMD},
    {MMI_EMAIL_MSG_SELECT_FAIL, STR_EMAIL_ERROR_CODE_IMAP_CMD},
    {MMI_EMAIL_NOOP_FAIL, STR_EMAIL_ERROR_CODE_IMAP_CMD},
    {MMI_EMAIL_FOLDER_SELECT_NOT_PERMITTED, STR_EMAIL_FOLDER_SELECT_NOT_PERMITTED},
    {MMI_EMAIL_INVALID_BODY_TYPE, STR_EMAIL_INVALID_MAIL_MESSAGE},
    {MMI_EMAIL_INVALID_BODY_ENCODING, STR_EMAIL_INVALID_MAIL_MESSAGE},
    {MMI_EMAIL_INVALID_MAIL_MESSAGE, STR_EMAIL_INVALID_MAIL_MESSAGE},
    {MMI_EMAIL_STREAM_BUFFER_NOT_ENOUGH, STR_EMAIL_MEMORY_FULL_ID},
    {MMI_EMAIL_LIMITED_RESOURCE, STR_EMAIL_MEMORY_FULL_ID},
    {MMI_EMAIL_SMTP_AUTH_FAIL, STR_EMAIL_ERROR_CODE_AUTH_FAIL_ID},
    {MMI_EMAIL_SMTP_AUTH_NOT_SUPPORT, STR_EMAIL_AUTH_NOT_SUPPORT},
    {MMI_EMAIL_MSG_MARKED_FULL, STR_EMAIL_MSG_MARKED_FULL},
    {MMI_EMAIL_INVALID_SERVER_ADDR, STR_EMAIL_ERROR_CODE_INVALID_IP_ADDR_ID},
    {0, STR_EMAIL_ERROR_CODE_UNKNOWN_ID}
};

#ifdef __MMI_EMAIL_TEMPLATE__
static void mmi_email_set_template_language(U8 langtype);
#endif /*__MMI_EMAIL_TEMPLATE__*/

#define CHSET_UTIL_EMAIL


/*****************************************************************************
 * FUNCTION
 *  mmi_email_util_ucs2_to_chset
 * DESCRIPTION
 *  Convert string from UCS2 to a specific chasert
 * PARAMETERS
 *  data        [IN]            String to be converted in UCS2.
 *  len         [IN]            Length of the string (in bytes)
 *  chset       [IN]            Charset of result string
 *  outLen      [IN/OUT]        Length of converted string(in bytes)
 * RETURNS
 *  pointer to the result string.
 *****************************************************************************/
U8 *mmi_email_util_ucs2_to_chset(U8 *data, U16 len, S32 chset, U16 *outLen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 encoding = 0;
    U8 *convertedData = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *outLen = 0;
    if (len > 0)
    {
        convertedData = OslMalloc(EMAIL_CHSET_BUFF_LEN);
        switch (chset)
        {
            case MMI_CHSET_ASCII:
                memset(convertedData, 0, (len + 1));
                mmi_ucs2_n_to_asc((S8*) convertedData, (S8*) data, len);
                *outLen = len / ENCODING_LENGTH + 1;
                break;
            default:
                encoding = mmi_email_util_get_chset(chset);
                *outLen = mmi_chset_convert(
                            MMI_CHSET_UCS2,
                            (mmi_chset_enum) encoding,
                            (char*)data,
                            (char*)convertedData,
                            EMAIL_CHSET_BUFF_LEN);
                break;
        }
    }
    return convertedData;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_util_chset_to_ucs2
 * DESCRIPTION
 *  Convert string from a specific chasert to UCS2.
 * PARAMETERS
 *  data        [IN]            String to be converted.
 *  len         [IN]            Length of the string (in bytes)
 *  chset       [IN]            Charset of source string
 *  outLen      [IN/OUT]        Length of converted string(in bytes)
 * RETURNS
 *  pointer to the result string.
 *****************************************************************************/
U8 *mmi_email_util_chset_to_ucs2(U8 *data, U16 len, S32 chset, U16 *outLen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 mmiEncoding = 0;
    U8 *convertedData = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *outLen = 0;

    if (len > 0)
    {
        convertedData = OslMalloc(EMAIL_CHSET_BUFF_LEN);

        /* because of buffer size constrained, ASCII charset shall be reduced within boundary */
        if (len > (EMAIL_CHSET_BUFF_LEN - 2) / 2)
        {
            len = (EMAIL_CHSET_BUFF_LEN - 2) / 2;
        }

        switch (chset)
        {
            case MMI_CHSET_ASCII:
                mmi_asc_n_to_ucs2((S8*) convertedData, (S8*) data, len);
                convertedData[len * ENCODING_LENGTH] = 0;
                convertedData[len * ENCODING_LENGTH + 1] = 0;
                *outLen = (len + 1) * ENCODING_LENGTH;
                break;
            default:
                mmiEncoding = mmi_email_util_get_chset(chset);
                *outLen = mmi_chset_convert(
                            (mmi_chset_enum) mmiEncoding,
                            MMI_CHSET_UCS2,
                            (char*)data,
                            (char*)convertedData,
                            EMAIL_CHSET_BUFF_LEN);
                break;
        }
    }
    return convertedData;
}

#define MSG_UTIL_EMAIL


/*****************************************************************************
 * FUNCTION
 *  mmi_email_util_get_chset
 * DESCRIPTION
 *  Convert charset from Email application to the enum value used in conversion function
 * PARAMETERS
 *  src_chset       [IN]        Charset of source.
 * RETURNS
 *  charset enum value for conversion function
 *****************************************************************************/
S32 mmi_email_util_get_chset(S32 src_chset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return src_chset;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_fldr_get_start_scr
 * DESCRIPTION
 *  Get start screen id to be deleted after send/save operations.
 *  This function is used in Write Email and each folder, which constains send/save operation
 * PARAMETERS
 *  void
 * RETURNS
 *  The start screen id to be deleted after send/save.
 *****************************************************************************/
U16 mmi_email_fldr_get_start_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (EMAIL_IS_MENU(MMI_EMAIL_COMP))
    {
        return SCR_ID_EMAIL_COMP;
    }
    else
    {
        U16 startScrnId;
        U16 folderListSrcnId = mmi_email_util_get_fldr_scr_id();

        if (GetNextScrnIdOf(folderListSrcnId, &startScrnId) == FALSE)
        {
            startScrnId = 0;
        }

        return startScrnId;
    }
}

#define STRING_UTIL_EMAIL


/*****************************************************************************
 * FUNCTION
 *  mmi_email_util_correct_disp_name
 * DESCRIPTION
 *  Convert the control characters into space in display name
 * PARAMETERS
 *  disp_name        [IN]        String to be check
 * RETURNS
 *  TRUE
 *****************************************************************************/
BOOL mmi_email_util_correct_disp_name(UI_character_type *disp_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (*disp_name != 0x0000)
    {
        if (*disp_name < 0x0020)
        {
            *disp_name = 0x0020;
        }
        disp_name++;
    }
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_util_is_server_vaild
 * DESCRIPTION
 *  Check if the server address is begin with '.'
 * PARAMETERS
 *  server        [IN]        String to be check
 * RETURNS
 *  TRUE if username is valid; otherwise, FALSE
 *****************************************************************************/
BOOL mmi_email_util_is_server_vaild(S8 *server)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(server[0] == '.' && server[1] == '\0')
    {
        return FALSE;
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_util_is_username_vaild
 * DESCRIPTION
 *  Check if the user name is all ASCII
 * PARAMETERS
 *  username        [IN]        String to be check
 * RETURNS
 *  TRUE if username is valid; otherwise, FALSE
 *****************************************************************************/
BOOL mmi_email_util_is_username_vaild(S8 *username)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (!((*username == 0) && (*(username + 1) == 0)))
    {
        if (username[0] != 0 && username[1] != 0)
        {
            return FALSE;
        }

        if (username[0] < 0x20  || username[1] > 0x7E)
        {
            return FALSE;
        }

        username += 2;
    }

    return TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_email_util_is_password_valid
 * DESCRIPTION
 *  Check if the password is all ASCII
 * PARAMETERS
 *  username        [IN]        String to be check, UCS2 encoded
 * RETURNS
 *  TRUE if username is valid; otherwise, FALSE
 *****************************************************************************/
BOOL mmi_email_util_is_password_valid(S8 *password)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(password == NULL)
    {
        return FALSE;
    }
    else
    {
        while (!((*password == 0) && (*(password + 1) == 0)))
        {
            if (password[0] < 0x20 || password[0] > 0x7E || password[1] != 0)
            {
                return FALSE;
            }
            password += 2;
        }
        return TRUE;
    }   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_util_get_err_code
 * DESCRIPTION
 *  Compute string id to be displayed accoding to error cause
 * PARAMETERS
 *  minor       [IN]        Minor cause
 *  major       [IN]        Major cause
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_email_util_get_err_code(S32 minor, signed char major)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (major)
    {
        case MMI_EMAIL_MAIL_ERR:
            return mmi_email_util_get_err_string(minor);
        case MMI_EMAIL_SOCKET_ERR:
            return STR_EMAIL_ERROR_CODE_NETWORK_ID;
        case MMI_EMAIL_FS_ERR:
            return GetFileSystemErrorString(minor);
        default:
            return STR_EMAIL_ERROR_CODE_UNKNOWN_ID;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_util_ascii_2_ucs2_str
 * DESCRIPTION
 *  Convert from ASCII to UCS2
 * PARAMETERS
 *  str     [IN]        String to be converted
 * RETURNS
 *  address of result string
 *****************************************************************************/
S8 *mmi_email_util_ascii_2_ucs2_str(S8 *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_to_ucs2((S8*) email_p->comm_buff, str);
    return (S8*) email_p->comm_buff;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_util_num_2_ucs2_str
 * DESCRIPTION
 *  Convert from ASCII to UCS2
 * PARAMETERS
 *  num     [IN]        Number to be converted
 * RETURNS
 *  address of result string
 *****************************************************************************/
S8 *mmi_email_util_num_2_ucs2_str(S8 num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 fileNumberAnsii[ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(fileNumberAnsii, "%d", num);
    mmi_asc_to_ucs2((S8*) email_p->comm_buff, fileNumberAnsii);
    return (S8*) email_p->comm_buff;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_util_get_num_len
 * DESCRIPTION
 *  Compute the length of an integer.
 * PARAMETERS
 *  number      [IN]        Number to be computed.
 * RETURNS
 *  the length of the number.
 *****************************************************************************/
S32 mmi_email_util_get_num_len(U32 number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 len;
    S8 *asciiMaxString = OslMalloc(EMAIL_MAX_DWNL_LEN);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf((S8*) asciiMaxString, "%d", number);
    len = strlen((S8*) asciiMaxString);
    OslMfree(asciiMaxString);
    return len;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_util_get_err_string
 * DESCRIPTION
 *  Get string id to represent an error codes of Email
 * PARAMETERS
 *  error       [IN]        Error codes of Email
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_email_util_get_err_string(S32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;
    S16 entry;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    entry = sizeof(g_email_err_tbl) / sizeof(mmi_email_err_string_struct);

    for (i = 0; i < entry; i++)
        if (g_email_err_tbl[i].err_no == error)
        {
            return g_email_err_tbl[i].str_id;
        }

    return STR_EMAIL_ERROR_CODE_UNKNOWN_ID;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_util_chk_addr
 * DESCRIPTION
 *  To check if an email address is valid (contains '@' character *).
 * PARAMETERS
 *  mailAddr        [IN]        Address to be checked (in UCS).
 * RETURNS
 *  TRUE if valid; otherwise FALSE.
 *****************************************************************************/
BOOL mmi_email_util_chk_addr(U8 *mailAddr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (BOOL)applib_is_valid_email_address_unicode((kal_wchar *)mailAddr);
}

#define FILE_UTIL_EMAIL


/*****************************************************************************
 * FUNCTION
 *  mmi_email_util_get_cont_name
 * DESCRIPTION
 *  Get file name of content.
 * PARAMETERS
 *  fileNo          [IN]            Index of content
 *  path_buff       [IN/OUT]        Buffer to store the file path+name
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_util_get_cont_name(S8 fileNo, S8 *path_buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) path_buff, (S8*) mmi_email_util_ascii_2_ucs2_str((S8*) EMAIL_WORKING_PATH));
    mmi_ucs2cat((S8*) path_buff, (S8*) mmi_email_util_ascii_2_ucs2_str(MMI_EMAIL_TEXT_FILE_NAME));
    mmi_ucs2cat((S8*) path_buff, (S8*) mmi_email_util_num_2_ucs2_str(fileNo));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_util_get_comp_attch_name
 * DESCRIPTION
 *  Get file name of attachment.
 * PARAMETERS
 *  fileNo          [IN]            Index of attachment
 *  path_buff       [IN/OUT]        Buffer to store the file path+name
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_util_get_comp_attch_name(S8 fileNo, S8 *path_buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) path_buff, (S8*) mmi_email_util_ascii_2_ucs2_str((S8*) EMAIL_WORKING_PATH));
    mmi_ucs2cat((S8*) path_buff, (S8*) mmi_email_util_ascii_2_ucs2_str((S8*) EMAIL_TEMP_COMPOSE_FLDR_NAME));
    mmi_ucs2cat((S8*) path_buff, (S8*) mmi_email_util_ascii_2_ucs2_str(MMI_EMAIL_ATTACH_FILE_NAME));
    mmi_ucs2cat((S8*) path_buff, (S8*) mmi_email_util_num_2_ucs2_str(fileNo));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_util_get_attch_name
 * DESCRIPTION
 *  Get file name of attachment.
 * PARAMETERS
 *  fileNo          [IN]            Index of attachment
 *  path_buff       [IN/OUT]        Buffer to store the file path+name
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_util_get_attch_name(S8 fileNo, S8 *path_buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) path_buff, (S8*) mmi_email_util_ascii_2_ucs2_str((S8*) EMAIL_WORKING_PATH));
    mmi_ucs2cat((S8*) path_buff, (S8*) mmi_email_util_ascii_2_ucs2_str(MMI_EMAIL_ATTACH_FILE_NAME));
    mmi_ucs2cat((S8*) path_buff, (S8*) mmi_email_util_num_2_ucs2_str(fileNo));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_util_get_sig_name
 * DESCRIPTION
 *  Get file name of signature.
 * PARAMETERS
 *  fileNo          [IN]            Index of profile
 *  path_buff       [IN/OUT]        Buffer to store the file path+name
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_util_get_sig_name(S8 fileNo, S8 *path_buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) path_buff, (S8*) mmi_email_util_ascii_2_ucs2_str((S8*) EMAIL_SIG_WORKING_PATH));
    mmi_ucs2cat((S8*) path_buff, (S8*) mmi_email_util_ascii_2_ucs2_str(EMAIL_SIG_FILE_NAME));
    mmi_ucs2cat((S8*) path_buff, (S8*) mmi_email_util_num_2_ucs2_str(fileNo));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_fldr_read_cont
 * DESCRIPTION
 *  Read content from file system and convert to UCS2.
 * PARAMETERS
 *  fileNo          [IN]            Index of attachment
 *  in_len          [IN]            Length of data to be read (in bytes)
 *  ch_set          [IN]            Charset of file content
 *  out_buff        [IN/OUT]        Pointer to the address which stores the output data
 *  out_len         [IN]            Stores the size of output data (in bytes)
 * RETURNS
 *  void
 *****************************************************************************/
S8 mmi_email_fldr_read_cont(S8 fileNo, S32 in_len, S32 ch_set, U8 **out_buff, U16 *out_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_h;
    U32 errorCode = 0;
    S8 *filepath;
    S8 result = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (in_len == 0)
    {
        return FALSE;
    }
    else if (in_len > EMAIL_MAX_CONT_LEN * EMAIL_UTF8_ENCODING_LENGTH)
    {
        in_len = EMAIL_MAX_CONT_LEN * EMAIL_UTF8_ENCODING_LENGTH;
    }

    filepath = OslMalloc((FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH);

    mmi_email_util_get_cont_name(fileNo, (S8*) filepath);

    file_h = FS_Open((U16*) filepath, FS_READ_ONLY);

    if (file_h > 0)
    {
        FS_Read(file_h, &email_p->misc_info.cont_inline_buff, in_len, &errorCode);

        email_p->misc_info.cont_inline_buff[in_len] = 0;
        email_p->misc_info.cont_inline_buff[in_len + 1] = 0;
        FS_Close(file_h);

        if (errorCode > 0)
        {
            *out_buff = mmi_email_util_chset_to_ucs2(
                            (U8*) email_p->misc_info.cont_inline_buff,
                            (U16) in_len,
                            ch_set,
                            out_len);
            result = TRUE;
        }
        else
        {
            *out_buff = NULL;
            *out_len = 0;
        }
    }

    /* result cont_inline_buff buffer because it's temporary usage */
    email_p->misc_info.cont_inline_buff[0] = 0;
    email_p->misc_info.cont_inline_buff[1] = 0;

    OslMfree(filepath);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_util_get_cont_size
 * DESCRIPTION
 *  Get file size of each content file
 * PARAMETERS
 *  totalTextMsg            [IN]        Total number of content file.
 *  outContentDataSize      [IN]        Buffer to store size of each content file
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_util_get_cont_size(U8 totalTextMsg, S32 *outContentDataSize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    FS_HANDLE emailContentFilePtr;
    S8 *emailContentFileNameBuf = OslMalloc((FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < totalTextMsg; i++)
    {
        mmi_ucs2cpy(
            (S8*) emailContentFileNameBuf,
            (S8*) mmi_email_util_ascii_2_ucs2_str((S8*) EMAIL_WORKING_PATH));
        mmi_ucs2cat(
            (S8*) emailContentFileNameBuf,
            (S8*) mmi_email_util_ascii_2_ucs2_str(MMI_EMAIL_TEXT_FILE_NAME));
        mmi_ucs2cat((S8*) emailContentFileNameBuf, (S8*) mmi_email_util_num_2_ucs2_str((U8) (i + 1)));
        emailContentFilePtr = FS_Open((U16*) emailContentFileNameBuf, FS_READ_ONLY);
        if (emailContentFilePtr < 0)
        {
            /* file open failed */
            outContentDataSize[i] = 0;
        }
        else
        {
            FS_GetFileSize(emailContentFilePtr, (U32*) &(outContentDataSize[i]));
            FS_Close(emailContentFilePtr);
        }
    }
    OslMfree(emailContentFileNameBuf);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_util_rename_after_abort
 * DESCRIPTION
 *  Rollback file name from convention name to composed name, when abort sending
 * PARAMETERS
 *  fileNo              [IN]            Index of file
 *  DestFilePathPtr     [IN/OUT]        Buffer to store file path+name after rename.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_util_rename_after_abort(S8 fileNo, S8 *DestFilePathPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *attachDefaultFileNameBuf = OslMalloc((FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_email_util_get_attch_name(fileNo, (S8*) attachDefaultFileNameBuf);

    FS_Delete((U16*) DestFilePathPtr);

    FS_Rename((U16*) attachDefaultFileNameBuf,(U16*) DestFilePathPtr);
    OslMfree(attachDefaultFileNameBuf);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_util_rename_attch
 * DESCRIPTION
 *  Rename attachment to convention name
 * PARAMETERS
 *  fileNo              [IN]        Index of attachment
 *  srcFilePathPtr      [IN]        Source file
 * RETURNS
 *  Error cause from file system.
 *****************************************************************************/
S32 mmi_email_util_rename_attch(S8 fileNo, S8 *srcFilePathPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = 0;
    S8 *attachDefaultFileNameBuf = OslMalloc((FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH);
    S8 *fileExt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_email_util_get_attch_name(fileNo, (S8*) attachDefaultFileNameBuf);

    /* rename attachX.EXT to attachX. delete the destination file */
    fileExt = mmi_email_get_file_ext(srcFilePathPtr);
    result = FS_Delete((U16*) attachDefaultFileNameBuf);
    if (result < FS_NO_ERROR)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_RENAME_ATTACH_DELETE_FILE, result);
    }

    result = FS_Rename((U16*) srcFilePathPtr,(U16*) attachDefaultFileNameBuf);
    if (result < FS_NO_ERROR)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_RENAME_ATTACH_RENAME_FILE, result);
    }

    OslMfree(attachDefaultFileNameBuf);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_util_rename_default_to_read
 * DESCRIPTION
 *  Rename default attachment name to the name use in Read Email screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_util_rename_default_to_read(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;
    S8 *fileExt;
    S8 *orig_name = OslMalloc((FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH);
    S8 *new_name = OslMalloc((FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH);
    kal_uint8 temp_part_mask[MMI_EMAIL_PART_MASK_SIZE];
#ifndef __MMI_SHOW_DAF_FILE_EXT__
    UI_character_type mp3_str[8];
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(temp_part_mask, 0, sizeof(kal_uint8) * MMI_EMAIL_PART_MASK_SIZE);
    for (i = 0, j = 0; i < email_p->inbox_info.read_info.total_attch; i++)
    {
        if (ISSET_PART_MASK(email_p->fldr_info.curr_part_mask, EMAIL_PART_MASK_ATTACH(i)) == 0)
        {
            j++;
            continue;
        }
        /* Original name */
        mmi_email_util_get_attch_name((U8) (i + 1), orig_name);

        /* Read name */
        mmi_ucs2cpy((S8*) new_name, (S8*) mmi_email_util_ascii_2_ucs2_str((S8*) EMAIL_WORKING_PATH));
        mmi_ucs2cat((S8*) new_name, (S8*) mmi_email_util_ascii_2_ucs2_str(EMAIL_TEMP_FOLDER_NAME));
        mmi_ucs2cat((S8*) new_name, (S8*) mmi_email_util_ascii_2_ucs2_str(EMAIL_READ_TMP_FILE_NAME));
        mmi_ucs2cat((S8*) new_name, (S8*) mmi_email_util_num_2_ucs2_str((U8) (i + 1)));
#ifndef __MMI_SHOW_DAF_FILE_EXT__
        if ((email_p->inbox_info.read_info.attch_list[i].attch_type == MIME_TYPE_AUDIO) &&
            (email_p->inbox_info.read_info.attch_list[i].attch_subtype == MIME_SUBTYPE_AUDIO_MP3))
        {
            mmi_asc_to_ucs2((S8*) mp3_str, ".mp3");
            mmi_ucs2cat((S8*) new_name, (S8*) mp3_str);
        }
        else if ((email_p->inbox_info.read_info.attch_list[i].attch_type == MIME_TYPE_AUDIO) &&
            (email_p->inbox_info.read_info.attch_list[i].attch_subtype == MIME_SUBTYPE_AUDIO_MP2))
        {
            mmi_asc_to_ucs2((S8*) mp3_str, ".mp2");
            mmi_ucs2cat((S8*) new_name, (S8*) mp3_str);
        }
        else
#endif
        {
            fileExt = mmi_email_get_file_ext((S8*) email_p->inbox_info.read_info.attch_list[i].file_name);
            mmi_ucs2cat((S8*) new_name, (S8*) fileExt);
        }

        if ((FS_Rename((U16*) orig_name,(U16*) new_name) == FS_NO_ERROR) ||
            (ISSET_PART_MASK(email_p->fldr_info.curr_part_mask, EMAIL_PART_MASK_ATTACH(i)) != 0))
        {
            mmi_ucs2cpy((S8*) email_p->inbox_info.read_info.attch_list[i].file_path, (S8*) new_name);
            email_p->inbox_info.read_info.attch_list[i].attch_present = TRUE;
            j++;
        }
    }
    email_p->inbox_info.read_info.total_attch = j;
    OslMfree(orig_name);
    OslMfree(new_name);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_util_rename_to_compose
 * DESCRIPTION
 *  Rename default attachment name to compose size
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_util_rename_to_compose(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;
    S32 fileSize;
    S8 *new_name = OslMalloc((FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_p->comp_info.total_attch_size = 0;

    for (i = 0, j = 0; i < MMI_EMAIL_MAX_NUM_ATTACH; i++)
    {
        /* check if the presence of attachment */
        if (!email_p->comp_info.attch_list[i].attch_present)
        {
            continue;
        }
        /* new name */
        mmi_email_util_get_attch_name((U8) (j + 1), new_name);

        /* delete if the same file name is existing */
        FS_Delete((U16*) email_p->comp_info.attch_list[i].file_path);

        if (FS_Rename((U16*) new_name, (U16*) email_p->comp_info.attch_list[i].file_path) == FS_NO_ERROR)
        {
            email_p->comp_info.attch_list[i].attch_present = TRUE;
            /* calculate file size */
            mmi_email_util_get_file_size((S8*) email_p->comp_info.attch_list[i].file_path, &fileSize);
            /* update total attachment size */
            email_p->comp_info.total_attch_size += fileSize;
            j++;
        }
        else
        {
            email_p->comp_info.attch_list[i].attch_present = MMI_FALSE;
        }
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_RENAME_TO_COMPOSE, email_p->comp_info.total_attch_size);
    }

    email_p->comp_info.total_attch = j;

    OslMfree(new_name);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_util_rename_read_to_comp
 * DESCRIPTION
 *  Rename Read attachment name to Compose attachment.
 *  If any error happens for an attachment, set the attachment to empty.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_util_rename_read_to_comp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;
    S32 fileSize;
    S8 *fileExt;
    S8 *comp_name = OslMalloc((FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH);
#ifndef __MMI_SHOW_DAF_FILE_EXT__
    UI_character_type mp3_str[8];
#endif
#ifdef __MMI_EMAIL_DRM_SUPPORT__
    U8 mime_type, mime_subtype;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_p->comp_info.total_attch_size = 0;
#ifdef __MMI_EMAIL_DRM_SUPPORT__
    drm_file_ignore = FALSE;
#endif

    for (i = 0, j = 0; i < email_p->inbox_info.read_info.total_attch; i++)
    {
        if (!ISSET_PART_MASK(email_p->fldr_info.curr_part_mask, EMAIL_PART_MASK_ATTACH(i)))
        {
            continue;
        }
#ifdef __MMI_EMAIL_DRM_SUPPORT__
        if ((email_p->inbox_info.read_info.attch_list[i].attch_type == MIME_TYPE_APPLICATION) &&
            (email_p->inbox_info.read_info.attch_list[i].attch_subtype == MIME_SUBTYPE_DRM_MESSAGE))
        {
            drm_file_ignore = TRUE;
            continue;
        }
        mmi_email_util_get_mine_type(
            (S8*) email_p->inbox_info.read_info.attch_list[i].file_path,
            &mime_type,
            &mime_subtype);
        if (mime_subtype == MIME_SUBTYPE_DRM_MESSAGE)
        {
            drm_file_ignore = TRUE;
            continue;
        }
#endif
        /* check file size */
        if (mmi_email_util_get_file_size((S8*) email_p->inbox_info.read_info.attch_list[i].file_path, &fileSize) ==
            FS_NO_ERROR)
        {
            /* ensure previous total attachment size + current attachment size no greater than 90K */
            if (email_p->inbox_info.read_info.total_attch_size + fileSize <= MMI_EMAIL_TOTAL_MAX_ATTACH_SIZE)
            {
                /* delete if the same file name is existing */
                mmi_ucs2cpy((S8*) comp_name, (S8*) mmi_email_util_ascii_2_ucs2_str((S8*) EMAIL_WORKING_PATH));
                mmi_ucs2cat((S8*) comp_name, (S8*) mmi_email_util_ascii_2_ucs2_str(EMAIL_TEMP_COMPOSE_FLDR_NAME));
                mmi_ucs2cat((S8*) comp_name, (S8*) mmi_email_util_ascii_2_ucs2_str(EMAIL_COMP_TMP_FILE_NAME));
                mmi_ucs2cat((S8*) comp_name, (S8*) mmi_email_util_num_2_ucs2_str((U8) (i + 1)));
#ifndef __MMI_SHOW_DAF_FILE_EXT__
                if ((email_p->inbox_info.read_info.attch_list[i].attch_type == MIME_TYPE_AUDIO) &&
                    (email_p->inbox_info.read_info.attch_list[i].attch_subtype == MIME_SUBTYPE_AUDIO_MP3))
                {
                    mmi_asc_to_ucs2((S8*) mp3_str, ".mp3");
                    mmi_ucs2cat((S8*) comp_name, (S8*) mp3_str);
                }
                else if ((email_p->inbox_info.read_info.attch_list[i].attch_type == MIME_TYPE_AUDIO) &&
                    (email_p->inbox_info.read_info.attch_list[i].attch_subtype == MIME_SUBTYPE_AUDIO_MP2))
                {
                    mmi_asc_to_ucs2((S8*) mp3_str, ".mp2");
                    mmi_ucs2cat((S8*) comp_name, (S8*) mp3_str);
                }
                else
#endif
                {
                    fileExt = mmi_email_get_file_ext((S8*) email_p->inbox_info.read_info.attch_list[i].file_name);
                    mmi_ucs2cat((S8*) comp_name, (S8*) fileExt);
                }
                FS_Delete((U16*) comp_name);

                /* rename */
                if (FS_Rename((U16*) email_p->inbox_info.read_info.attch_list[i].file_path, (U16*) comp_name) == FS_NO_ERROR)
                {
                    mmi_ucs2cpy(
                        (S8*) email_p->comp_info.attch_list[j].file_name,
                        (S8*) email_p->inbox_info.read_info.attch_list[i].file_name);
                    mmi_ucs2cpy((S8*) email_p->comp_info.attch_list[j].file_path, (S8*) comp_name);
                    email_p->comp_info.attch_list[j].attch_type =
                        email_p->inbox_info.read_info.attch_list[i].attch_type;
                    email_p->comp_info.attch_list[j].attch_subtype =
                        email_p->inbox_info.read_info.attch_list[i].attch_subtype;
                    email_p->comp_info.attch_list[j].ch_set = email_p->inbox_info.read_info.attch_list[i].ch_set;
                #ifdef __MMI_EMAIL_DRM_SUPPORT__
                    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_RENAME_READ_TO_COMP_TYPE,
                        email_p->inbox_info.read_info.attch_list[i].drm.is_valid,
                        email_p->inbox_info.read_info.attch_list[i].drm.mime_type,
                        email_p->inbox_info.read_info.attch_list[i].drm.mime_subtype);
                    memcpy(&email_p->comp_info.attch_list[j].drm, &email_p->inbox_info.read_info.attch_list[i].drm, sizeof(email_drm_struct));
                #endif
                    email_p->comp_info.attch_list[j].size = email_p->inbox_info.read_info.attch_list[i].size;
                    email_p->comp_info.attch_list[j].attch_present = TRUE;
                    /* update total attachment size */
                    email_p->comp_info.total_attch_size += fileSize;
                    /* rename successfully, continue next file */
                    j++;
                }
                MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_RENAME_READ_TO_COMP_SIZE, email_p->comp_info.total_attch_size);
            }
            else
            {
                /* file size exceeded */
                email_p->comp_info.except_popup |= EMAIL_EXCEPT_ATT_EXCEED;
            }
        }
    }

    email_p->comp_info.total_attch = j;

    OslMfree(comp_name);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_util_create_working_dir
 * DESCRIPTION
 *  Create working directory
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_util_create_working_dir(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *createFolder = OslMalloc((FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) createFolder, (S8*) mmi_email_util_ascii_2_ucs2_str((S8*) EMAIL_WORKING_PATH));
    FS_CreateDir((U16*) createFolder); /* the api does not support recursive creation */
    mmi_ucs2cat((S8*) createFolder, (S8*) mmi_email_util_ascii_2_ucs2_str(EMAIL_TEMP_FOLDER_NAME));
    FS_CreateDir((U16*) createFolder);
    mmi_ucs2cpy((S8*) createFolder, (S8*) mmi_email_util_ascii_2_ucs2_str((S8*) EMAIL_WORKING_PATH));
    mmi_ucs2cat((S8*) createFolder, (S8*) mmi_email_util_ascii_2_ucs2_str(EMAIL_TEMP_COMPOSE_FLDR_NAME));
    FS_CreateDir((U16*) createFolder);
    OslMfree(createFolder);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_read_copy_attch
 * DESCRIPTION
 *  Copy attachment from file buffer to user selected path
 * PARAMETERS
 *  attchName       [IN]        File name to be saved
 * RETURNS
 *  void
 *****************************************************************************/
S8 mmi_email_read_copy_attch(S8 *attchName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fh;
    S32 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* path too long */
    if ((mmi_ucs2strlen((S8*) email_p->comm_buff) + mmi_ucs2strlen((S8*) attchName) +
         mmi_ucs2strlen((S8*) email_p->fileext_buff)) > FMGR_MAX_PATH_LEN)
    {
        return EMAIL_SAVE_ATTACH_NAME_TOO_LONG;
    }

    /* file name empty */
    if (mmi_ucs2strlen((S8*) attchName) == 0)
    {
        return EMAIL_SAVE_ATTACH_EMPTY_NAME;
    }
    if (email_p->inbox_info.attch_dest_path == NULL)
    {
        email_p->inbox_info.attch_dest_path = OslMalloc((FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH);
    }
    mmi_ucs2cpy((S8*) email_p->inbox_info.attch_dest_path, (S8*) attchName);
    mmi_ucs2cat(email_p->inbox_info.attch_dest_path, (S8*) email_p->fileext_buff);
    if (!mmi_fmgr_is_filename_valid((S8*) email_p->inbox_info.attch_dest_path))
    {
        OslMfree(email_p->inbox_info.attch_dest_path);
        email_p->inbox_info.attch_dest_path = NULL;
        return EMAIL_SAVE_ATTACH_NAME_INVALID;
    }

    /* duplicated file name */
    mmi_ucs2cpy((S8*) email_p->inbox_info.attch_dest_path, (S8*) email_p->comm_buff);
    mmi_ucs2cat(email_p->inbox_info.attch_dest_path, (S8*) attchName);
    mmi_ucs2cat(email_p->inbox_info.attch_dest_path, (S8*) email_p->fileext_buff);

    fh = FS_Open((U16*) email_p->inbox_info.attch_dest_path, FS_READ_ONLY);
    if (fh > 0)
    {
        OslMfree(email_p->inbox_info.attch_dest_path);
        email_p->inbox_info.attch_dest_path = NULL;
        FS_Close(fh);
        return EMAIL_SAVE_ATTACH_DUP_NAME;
    }

    /* send copy request to fmt ask */
    mmi_email_util_reset_file_attr((U16*) email_p->inbox_info.attch_dest_path);
    ret = FS_Delete((U16*) email_p->inbox_info.attch_dest_path);
    mmi_fmgr_send_copy_req(
        FMGR_ACTION_COPY,
        (U8*) email_p->inbox_info.read_info.attch_list[email_p->misc_info.curr_hilite_attch].file_path,
        (U8*) email_p->inbox_info.attch_dest_path,
        mmi_email_read_attch_copy_callback);
    return EMAIL_SAVE_ATTACH_NO_ERR;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_read_attch_copy_callback
 * DESCRIPTION
 *  Callback function for saving attachment to file manager
 * PARAMETERS
 *  info        [IN]        Result of saving attachment
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_read_attch_copy_callback(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* display done and go back to option screen */
    mmi_fmt_copy_rsp_strcut *msgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgPtr = (mmi_fmt_copy_rsp_strcut*) info;

    OslMfree(email_p->inbox_info.attch_dest_path);
    email_p->inbox_info.attch_dest_path = NULL;

    if (mmi_email_util_is_call_interrupt_allow() && GetExitScrnID() != SCR_ID_EMAIL_PROGRESS)
    {
        /* delete progressing screen */
        DeleteScreenIfPresent(SCR_ID_EMAIL_PROGRESS);
        return;
    }

    if (msgPtr->result >= FS_NO_ERROR)
    {
        DeleteUptoScrID(SCR_ID_EMAIL_READ_ATTCH);
        mmi_email_util_display_popup(
            (U8*) GetString(STR_GLOBAL_SAVED),
            IMG_GLOBAL_ACTIVATED,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            SUCCESS_TONE);
    }
    else
    {
        mmi_email_util_display_popup(
            (U8*) GetString((U16) GetFileSystemErrorString(msgPtr->result)), 
            IMG_GLOBAL_ERROR, 
            0, 
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
    }

    DeleteScreenIfPresent(SCR_ID_EMAIL_PROGRESS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_get_file_ext
 * DESCRIPTION
 *  Get file extension of a file name
 * PARAMETERS
 *  pFileName       [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
S8 *mmi_email_get_file_ext(S8 *pFileName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 nLength;
    S8 *pFilePtr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nLength = mmi_ucs2strlen(pFileName);
    if (nLength) /* in case empty filename */
    {
        --nLength;
        nLength *= ENCODING_LENGTH;

        while (nLength)
        {
            if ((pFileName[nLength] == '.') && (pFileName[nLength + 1] == '\0'))
            {
                break;
            }
            else
            {
                nLength -= 2;
            }
        }

        if (nLength) /* in case no file extension */
        {
            pFilePtr = pFileName + nLength;
        }
    }

    return pFilePtr;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_util_get_file_size
 * DESCRIPTION
 *  Get size of a file
 * PARAMETERS
 *  filePathPtr     [?]     [?]
 *  fileSizePtr     [?]     [?]
 *  filePathPrt(?)      [IN]            File path and name(?)
 *  fileSizePrt(?)      [IN/OUT]        Address to store the size of file(?)
 * RETURNS
 *  Error cause of file open
 *****************************************************************************/
S32 mmi_email_util_get_file_size(S8 *filePathPtr, S32 *fileSizePtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fileHandle = FS_Open((U16*) filePathPtr, FS_READ_ONLY);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fileHandle > 0)
    {
        FS_GetFileSize(fileHandle, (U32*) &(*fileSizePtr));
        FS_Close(fileHandle);
        return FS_NO_ERROR;
    }
    return fileHandle;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_util_check_file_exist
 * DESCRIPTION
 *  To check whether file exist or not
 * PARAMETERS
 *  filePathPtr     [IN]        File path
 * RETURNS
 *  TURE of file exists; otherwise FALSE.
 *****************************************************************************/
S32 mmi_email_util_check_file_exist(S8 *filePathPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fileHandle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if file already exist */
    fileHandle = FS_Open((U16*)filePathPtr, FS_READ_ONLY);

    if (fileHandle > 0)
    {
        FS_Close(fileHandle);
        return FS_NO_ERROR;
    }

    return fileHandle;
}

#define SCR_UTIL_EMAIL


/*****************************************************************************
 * FUNCTION
 *  mmi_email_util_add_history
 * DESCRIPTION
 *  Common function to add history node when exiting a screen.
 *  The logic of this function depends on the flag "insert_hist".
 *  This flag determines if the screen shall be added to history or inserted before CM screen
 * PARAMETERS
 *  scrnId              [IN]        Screen index
 *  entryFuncPtr        [IN]        Pointer of the screen entry function
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_util_add_history(U16 scrnId, FuncPtr entryFuncPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history currHistory;
    S16 ucs2InputBuffer = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currHistory.scrnID = scrnId;
    currHistory.entryFuncPtr = entryFuncPtr;
    mmi_ucs2cpy((S8*) currHistory.inputBuffer, (S8*) & ucs2InputBuffer);

    if (!email_p->misc_info.insert_hist)
    {
        GetCategoryHistory(currHistory.guiBuffer);
        AddHistory(currHistory);
    }
    else
    {
#ifdef __MMI_VOIP__
        if (mmi_voip_app_total_call() != 0)
        {
            InsertHistoryBeforeThisScrn(mmi_voip_app_get_marker_screen(), currHistory);
        }
        else
#endif /* __MMI_VOIP__ */
        {
            U16 cmScrnId = GetCmMarkerScrnID();
            
            if (IsScreenPresent(cmScrnId))
            {
                InsertHistoryBeforeThisScrn(GetCmMarkerScrnID(), currHistory);
            }
            else
            {
                AddHistory(currHistory);
            }
        }
    }
    email_p->misc_info.insert_hist = FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_util_add_n_history
 * DESCRIPTION
 *  Common function to add a category 57 history node when exiting a screen.
 *  The logic of this function depends on the flag "insert_hist".
 *  This flag determines if the screen shall be added to history or inserted before CM screen
 * PARAMETERS
 *  scrnId              [IN]        Screen index
 *  entryFuncPtr        [IN]        Pointer of the screen entry function
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_util_add_n_history(U16 scrnId, FuncPtr entryFuncPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history currHistory;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currHistory.scrnID = scrnId;
    currHistory.entryFuncPtr = entryFuncPtr;
    if (!email_p->misc_info.insert_hist)
    {
        U16 inputBufferSize = 0;

        CloseCategory57Screen();
        GetCategoryHistory(currHistory.guiBuffer);
        inputBufferSize = (U16) GetCategory57DataSize();
        GetCategory57Data((U8*) currHistory.inputBuffer);
        AddNHistory(currHistory, inputBufferSize);
    }
    else
    {
#ifdef __MMI_VOIP__
        if (mmi_voip_app_total_call() != 0)
        {
            InsertHistoryBeforeThisScrn(mmi_voip_app_get_marker_screen(), currHistory);
        }
        else
#endif /* __MMI_VOIP__ */
        {
            U16 cmScrnId = GetCmMarkerScrnID();
            
            if (IsScreenPresent(cmScrnId))
            {
                InsertHistoryBeforeThisScrn(GetCmMarkerScrnID(), currHistory);
            }
            else
            {
                AddHistory(currHistory);
            }
        }
    }
    email_p->misc_info.insert_hist = FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_util_go_back_2_hist
 * DESCRIPTION
 *  Go back to previosu 2 screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_util_go_back_2_hist(void)
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
 *  mmi_email_util_folder_select_cap_str
 * DESCRIPTION
 *  Construct caption string of folder according to current protocol.
 * PARAMETERS
 *  strCaptionId        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U8 *mmi_email_util_folder_select_cap_str(U16 strCaptionId)
{
#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Unsent folder is not related to IMAP4 protocol */
    if ((email_p->prof_info.act_prof.in_prot == EMAIL_PROT_IMAP4) &&
        (strCaptionId != STR_EMAIL_UNSENT_ID) &&
        (email_p->main_info.curr_menu != MMI_EMAIL_UNSENT))
    {
        S8 *asciiPageNumberInfoBuff = OslMalloc(EMAIL_MAX_FLDR_CAP_LEN);
        S8 *ucs2PageNumberInfoBuff = OslMalloc(EMAIL_MAX_FLDR_CAP_LEN * ENCODING_LENGTH);
        
        sprintf(
            (S8*) asciiPageNumberInfoBuff,
            " [%d/%d]",
            email_p->fldr_info.curr_page,
            email_p->fldr_info.total_page);
        mmi_asc_to_ucs2((S8*) ucs2PageNumberInfoBuff, (S8*) asciiPageNumberInfoBuff);
        mmi_ucs2cpy((S8*) email_p->misc_info.folder_cap_buff, (S8*) GetString(strCaptionId));
        mmi_ucs2cat((S8*) email_p->misc_info.folder_cap_buff, (S8*) ucs2PageNumberInfoBuff);
        
        OslMfree(asciiPageNumberInfoBuff);
        OslMfree(ucs2PageNumberInfoBuff);
        
        return (U8*) email_p->misc_info.folder_cap_buff;
    }
#endif /* !defined(__MMI_SLIM_EMAIL_NO_IMAP4__) */ 
    return (U8*) GetString(strCaptionId);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_util_exit_scr_by_err
 * DESCRIPTION
 *  Exit all the Email screens when error
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_util_exit_scr_by_err(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scr_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (email_p->main_info.entry_src == EMAIL_FROM_MSG)
    {
        SetDelScrnIDCallbackHandler(SCR_ID_EMAIL_MAIN, NULL);
        mmi_email_util_del_upto_scr(SCR_ID_EMAIL_MAIN);
    }
    else if (email_p->main_info.entry_src == EMAIL_FROM_APP)
    {
        SetDelScrnIDCallbackHandler(SCR_ID_EMAIL_COMP, NULL);
        mmi_email_util_del_upto_scr(SCR_ID_EMAIL_COMP);
    }
    scr_id = GetExitScrnID();
    if (scr_id > SCR_ID_EMAIL_START && scr_id < SCR_ID_EMAIL_END)
    {
        GoBackHistory();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_util_is_scrid_owned
 * DESCRIPTION
 *  Get screen id is owned by Email
 * PARAMETERS
 *  scr_id          [IN]        the screen id
 * RETURNS
 *  TRUE: owned by Email
 *****************************************************************************/
BOOL mmi_email_util_is_scrid_owned(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (((scr_id > SCR_ID_EMAIL_START) && (scr_id < SCR_ID_EMAIL_END)) ? TRUE : FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_util_del_between_scr
 * DESCRIPTION
 *  Delete Email screen between two screens
 * PARAMETERS
 *  start_scr       [IN]        Start screen id to be deleted
 *  end_scr         [IN]        End screen id to be deleted
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_util_del_between_scr(U16 start_scr, U16 end_scr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 next_scr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (GetNextScrnIdOf(start_scr, &next_scr))
    {
        if (next_scr == end_scr)
        {
            break;
        }
        else if (mmi_email_util_is_scrid_owned(next_scr))
        {
            DeleteScreenIfPresent(next_scr);
        }
        else
        {
            break;
        }
    }

    DeleteScreenIfPresent(end_scr);
    DeleteScreenIfPresent(start_scr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_util_del_upto_scr
 * DESCRIPTION
 *  Delete Email screen update to some screen
 * PARAMETERS
 *  end_scr     [IN]        End screen id to be deleted
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_util_del_upto_scr(U16 end_scr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 next_scr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (GetNextScrnIdOf(end_scr, &next_scr))
    {
        if (mmi_email_util_is_scrid_owned(next_scr))
        {
            DeleteScreenIfPresent(next_scr);
        }
        else
        {
            break;
        }
    }

    DeleteScreenIfPresent(end_scr);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_util_display_popup
 * DESCRIPTION
 *  Call DisplayPopup function and turn on back light
 * PARAMETERS
 *  string          [IN]    Char array of string
 *  imageId         [IN]    Image ID
 *  imageOnBottom   [IN]    Reserved
 *  popupDuration   [IN]    Duration of the pop-up
 *  toneId          [IN]    Tone ID
 *  rotation        [IN]    Rotation
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_util_display_popup(
                U8 *string,
                U16 imageId,
                U8 imageOnBottom,
                U32 popupDuration,
                U8 toneId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TurnOnBacklight(1);
    DisplayPopup(string, imageId, imageOnBottom, popupDuration, toneId);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_util_display_popup_callback
 * DESCRIPTION
 *  Call DisplayPopupCallBack function and turn on back light
 * PARAMETERS
 *  string              [IN]    Char array of string
 *  imageId             [IN]    Image ID
 *  imageOnBottom       [IN]    Reserved
 *  popupDuration       [IN]    Duration of the pop-up
 *  toneId              [IN]    Tone ID
 *  f                   [IN]    Callback function pointer
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_util_display_popup_callback(
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
    TurnOnBacklight(1);
    DisplayPopupCallBack(string, imageId, imageOnBottom, popupDuration, toneId, f);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_util_display_err_popup
 * DESCRIPTION
 *  Common function to display popup screen
 * PARAMETERS
 *  minor               [IN]        Minor cause
 *  major               [IN]        Major cause
 *  startDelScrnId      [IN]        Starting index of screen to be deleted
 *  endDelScrnId        [IN]        End index of screen to be deleted
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_util_display_err_popup(S32 minor, signed char major, U16 startDelScrnId, U16 endDelScrnId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 errMsgId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    errMsgId = mmi_email_util_get_err_code(minor, major);
    TurnOnBacklight(1);
    mmi_email_util_display_popup(
        (U8*) GetString(errMsgId),
        IMG_GLOBAL_ERROR,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) ERROR_TONE);
    if (startDelScrnId)
    {
        mmi_email_util_del_between_scr(startDelScrnId, endDelScrnId);
    }
    else
    {
        mmi_email_util_del_upto_scr(endDelScrnId);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_util_clear_end_key_hdlr
 * DESCRIPTION
 *  Clear all handlers of END key
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_util_clear_end_key_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
    ClearKeyHandler(KEY_END, KEY_REPEAT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_util_update_status_icon
 * DESCRIPTION
 *  Update status icon in IDLE screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_util_update_status_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (
#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
        (email_p->prof_info.act_prof.in_prot == EMAIL_PROT_IMAP4) ||
#endif 
        (email_p->main_info.is_mem_full == FALSE))
    {
        HideStatusIcon(STATUS_ICON_UNREAD_EMAIL);
        if (email_p->main_info.unread_mails != 0)
        {
            ShowStatusIcon(STATUS_ICON_UNREAD_EMAIL);
        }
        UpdateStatusIcons();
    }
    else
    {
        HideStatusIcon(STATUS_ICON_UNREAD_EMAIL);
        BlinkStatusIcon(STATUS_ICON_UNREAD_EMAIL);
        UpdateStatusIcons();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_util_update_status_icon_ex
 * DESCRIPTION
 *  Update status icon in IDLE screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_util_update_status_icon_ex(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (email_p->main_info.is_mem_full == FALSE)
    {
        HideStatusIcon(STATUS_ICON_UNREAD_EMAIL);
        ShowStatusIcon(STATUS_ICON_UNREAD_EMAIL);
        UpdateStatusIcons();
    }
    else
    {
        HideStatusIcon(STATUS_ICON_UNREAD_EMAIL);
        BlinkStatusIcon(STATUS_ICON_UNREAD_EMAIL);
        UpdateStatusIcons();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_util_change_title
 * DESCRIPTION
 *  Change title string
 * PARAMETERS
 *  strId       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_util_change_title(U16 strId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeTitleString((U8*) GetString(strId));
    draw_title();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_util_get_fldr_scr_id
 * DESCRIPTION
 *  Get screen id of current folder
 * PARAMETERS
 *  void
 * RETURNS
 *  Screen index
 *****************************************************************************/
U16 mmi_email_util_get_fldr_scr_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (email_p->main_info.curr_menu)
    {
        case MMI_EMAIL_INBOX:
        case MMI_EMAIL_UNSENT:
        case MMI_EMAIL_SENT:
        case MMI_EMAIL_DRAFT:
            return SCR_ID_EMAIL_FOLDER;
        default:
            return SCR_ID_EMAIL_MAIN;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_util_get_abort_func
 * DESCRIPTION
 *  Get function pointer of abort in progressing screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  function pointer of abort function if required.
 *****************************************************************************/
FuncPtr mmi_email_util_get_abort_func(void)
{
#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((email_p->prof_info.act_prof.in_prot == EMAIL_PROT_IMAP4) &&
        (email_p->main_info.curr_menu != MMI_EMAIL_UNSENT) &&
        (email_p->mode_status.curr_mode == EMAIL_MODE_ONLINE))
    {
        return (FuncPtr) mmi_email_ps_abort_req;
    }
#endif /* !defined(__MMI_SLIM_EMAIL_NO_IMAP4__) */ 
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_util_is_call_interrupt_allow
 * DESCRIPTION
 *  To determine if interrupt from call is allowed
 * PARAMETERS
 *  void
 * RETURNS
 *  TURE if screen can be displayed; otherwise, FALSE.
 *****************************************************************************/
U8 mmi_email_util_is_call_interrupt_allow(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UCM__
    if (mmi_ucm_app_total_call(MMI_UCM_VOICE_CALL_TYPE_ALL) > 0)
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
#else /* __MMI_UCM__ */
    if (isInCall() == MMI_FALSE)
    {
        return MMI_TRUE;
    }
    else if ((isInCall() && GetWapCallPresent()) &&
             (GetTotalCallCount() <= 1) && !isIncomingCall())
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
#endif /* __MMI_UCM__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_util_abort_str
 * DESCRIPTION
 *  Get string id of abort key.
 *  If current protocol is POP3 or folder is Unsent, no abort key required.
 * PARAMETERS
 *  void
 * RETURNS
 *  string index of abort key.
 *****************************************************************************/
U16 mmi_email_util_abort_str(void)
{
#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((email_p->prof_info.act_prof.in_prot == EMAIL_PROT_IMAP4) &&
        (email_p->main_info.curr_menu != MMI_EMAIL_UNSENT) &&
        (email_p->mode_status.curr_mode == EMAIL_MODE_ONLINE))
    {
        return STR_GLOBAL_CANCEL;
    }
#endif /* !defined(__MMI_SLIM_EMAIL_NO_IMAP4__) */ 
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_util_abort_img
 * DESCRIPTION
 *  Get image id of abort key.
 *  If current protocol is POP3 or folder is Unsent, no abort key required.
 * PARAMETERS
 *  void
 * RETURNS
 *  image index of abort key.
 *****************************************************************************/
U16 mmi_email_util_abort_img(void)
{
#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((email_p->prof_info.act_prof.in_prot == EMAIL_PROT_IMAP4) &&
        (email_p->main_info.curr_menu != MMI_EMAIL_UNSENT) &&
        (email_p->mode_status.curr_mode == EMAIL_MODE_ONLINE))
    {
        return IMG_GLOBAL_BACK;
    }
#endif /* !defined(__MMI_SLIM_EMAIL_NO_IMAP4__) */ 
    return 0;
}

#define MIME_UTIL_EMAIL


/*****************************************************************************
 * FUNCTION
 *  mmi_email_uti_tolower
 * DESCRIPTION
 *  Convert a character from upper case to lower case
 * PARAMETERS
 *  ch      [IN]        Character to be converted.
 * RETURNS
 *  result of the converting.
 *****************************************************************************/
U8 mmi_email_uti_tolower(U8 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ch >= 'A' && ch <= 'Z')
    {
        return (U8) (ch + ('a' - 'A'));
    }
    return ch;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_uti_strnicmp
 * DESCRIPTION
 *  Compare two string without regarding upper/lower case
 * PARAMETERS
 *  src         [IN]        Source string
 *  dest        [IN]        Destination string
 *  maxlen      [IN]        Length of the string to be compared
 * RETURNS
 *  TRUE if two string is different; otherwise, FALSE.
 *****************************************************************************/
S8 mmi_email_uti_strnicmp(S8 *src, S8 *dest, S32 maxlen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 ch1, ch2;
    S8 *s1, *s2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    s1 = src;
    s2 = dest;

    while (maxlen-- > 0)
    {
        ch1 = mmi_email_uti_tolower(*s1++);
        ch2 = mmi_email_uti_tolower(*s2++);
        if (ch1 != ch2)
        {
            return TRUE;
        }
    }

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_util_get_mine_type
 * DESCRIPTION
 *  Get mine type and mine subtype of a give file according to filename
 * PARAMETERS
 *  filename            [IN]        File name
 *  mime_type           [?]         
 *  mime_subtype        [?]         
 *  mine_type(?)        [OUT]       Mine type of a file
 *  mine_subtype(?)     [OUT]       Mine subtype of a file
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_util_get_mine_type(S8 *filename, U8 *mime_type, U8 *mime_subtype)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *fileExtPtr = mmi_email_get_file_ext((S8*) filename);
    S8 *fileExt = OslMalloc((FMGR_MAX_EXT_LEN + 1) * ENCODING_LENGTH);
    S32 extLen = 0;
    applib_mime_type_struct *mimeTypePtr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(fileExt, 0, (FMGR_MAX_EXT_LEN + 1) * ENCODING_LENGTH);

    if (fileExtPtr)
    {
        /* neglect "." */
        fileExtPtr = fileExtPtr + 2;
        extLen = (((FMGR_MAX_EXT_LEN + 1) > (mmi_ucs2strlen(fileExtPtr))) ? (mmi_ucs2strlen(fileExtPtr)) : (FMGR_MAX_EXT_LEN + 1)); 
        mmi_ucs2_n_to_asc(fileExt, fileExtPtr, extLen * ENCODING_LENGTH);
    }

    if (strlen(fileExt))
    {
        mimeTypePtr = mime_type_look_up(NULL, fileExt, 0, 0);
    }
    if (mimeTypePtr != NULL)
    {
        *mime_type = mimeTypePtr->mime_type;
        *mime_subtype = mimeTypePtr->mime_subtype;
    }
    else
    {
        *mime_type = MIME_TYPE_UNKNOWN;
        *mime_subtype = MIME_SUBTYPE_UNRECOGNIZED;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_GET_MINE_TYPE, *mime_type, *mime_subtype);
    OslMfree(fileExt);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_get_ext_by_type
 * DESCRIPTION
 *  Get file ext according to mine type and mine subtype
 * PARAMETERS
 *  file_ext            [OUT]       File ext name
 *  mime_type           [IN]        mine type
 *  mime_subtype        [IN]        sub type
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_email_get_ext_by_type(S8 *file_ext, applib_mime_type_enum mime_type, applib_mime_subtype_enum mime_subtype)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_mime_type_struct *mime_ptr = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mime_ptr = mime_type_look_up(NULL, NULL, mime_type, mime_subtype);
    
    if (mime_ptr)
    {
        mmi_asc_to_ucs2(file_ext, mime_ptr->file_ext);
        return mmi_ucs2strlen(file_ext);
    }
    else
    {
        mmi_asc_to_ucs2(file_ext, ".tmp");
        return mmi_ucs2strlen(file_ext);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_util_get_attch_icon
 * DESCRIPTION
 *  Get displayed icon of a file according to its file path.
 *  The supported type is sync with file manager.
 * PARAMETERS
 *  filepath        [IN]        File path
 * RETURNS
 *  image index of the given file type
 *****************************************************************************/
U16 mmi_email_util_get_attch_icon(S8 *filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 fileType;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fileType = mmi_fmgr_get_file_group((S8*) filepath);
    if (fileType == FMGR_GROUP_IMAGE)
    {
        return IMG_EMAIL_ATTACH_IMAGE_15x15_ID;
    }
    else if (fileType == FMGR_GROUP_AUDIO)
    {
        return IMG_EMAIL_ATTACH_AUDIO_15x15_ID;
    }
    else if (fileType == FMGR_GROUP_VIDEO)
    {
        return IMG_EMAIL_ATTACH_VIDEO_15x15_ID;
    }
    else
    {
        return IMG_EMAIL_ATTACH_UNKNOWN_15x15_ID;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_util_get_attch_icon_ex
 * DESCRIPTION
 *  Get displayed icon of a file according to its file type.
 * PARAMETERS
 *  file_type       [IN]        
 *  filepath(?)     [IN]        File Type
 * RETURNS
 *  image index of the given file type
 *****************************************************************************/
U16 mmi_email_util_get_attch_icon_ex(U8 file_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (file_type == MIME_TYPE_IMAGE)
    {
        return IMG_EMAIL_ATTACH_NC_IMAGE_15x15_ID;
    }
    else if (file_type == MIME_TYPE_AUDIO)
    {
        return IMG_EMAIL_ATTACH_NC_AUDIO_15x15_ID;
    }
    else if (file_type == MIME_TYPE_VIDEO)
    {
        return IMG_EMAIL_ATTACH_NC_VIDEO_15x15_ID;
    }
    else
    {
        return IMG_EMAIL_ATTACH_NC_UNKNOWN_15x15_ID;
    }
}

#define MEM_UTIL_EMAIL


/*****************************************************************************
 * FUNCTION
 *  mmi_email_util_free_container_pool
 * DESCRIPTION
 *  Free memory pool container and reset folder info.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_util_free_container_pool(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (email_p->mem_pool_info.mem_container.num_pool != -1)
    {
        mmi_mem_destroy_container(&email_p->mem_pool_info.mem_container);
        memset(&email_p->fldr_info.fldr_list, 0, sizeof(mmi_email_fldr_list_info_struct));

        /* -1 to indicate no container now */
        email_p->mem_pool_info.mem_container.num_pool = -1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_util_folder_init
 * DESCRIPTION
 *  Initialize Email MMI for folders
 * PARAMETERS
 *  is_check_comp       [IN]        to check compose done status
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_util_folder_init(MMI_BOOL is_check_comp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar *filename;
    kal_wchar *fsearch;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    filename = (kal_wchar*) OslMalloc(MMI_EMAIL_MAX_FILE_NAME_LEN + 128);
    fsearch = (kal_wchar*) OslMalloc(MMI_EMAIL_MAX_FILE_NAME_LEN);

    kal_wsprintf(filename, "%s%s", EMAIL_WORKING_PATH, EMAIL_TEMP_FOLDER_NAME);
    kal_wsprintf(fsearch, "%s%s*", EMAIL_WORKING_PATH, EMAIL_TEMP_FOLDER_NAME);
    mmi_email_util_del_file_in_folder(filename, fsearch);

    if ((is_check_comp) && 
        (mmi_email_comp_get_done_status() && (email_p->comp_info.total_attch != 0)))
    {
        OslMfree(fsearch);
        OslMfree(filename);
        return;
    }
    kal_wsprintf(filename, "%s%s", EMAIL_WORKING_PATH, EMAIL_TEMP_COMPOSE_FLDR_NAME);
    kal_wsprintf(fsearch, "%s%s*", EMAIL_WORKING_PATH, EMAIL_TEMP_COMPOSE_FLDR_NAME);
    mmi_email_util_del_file_in_folder(filename, fsearch);

    OslMfree(fsearch);
    OslMfree(filename);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_util_del_file_in_folder
 * DESCRIPTION
 *  Delete all the file in folder.
 * PARAMETERS
 *  filename        [IN]        
 *  fsearch         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_util_del_file_in_folder(kal_wchar *filename, kal_wchar *fsearch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 h;
    kal_wchar *fn;
    FS_DOSDirEntry info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fn = filename + kal_wstrlen(filename);
    /* the length of output filename is in bytes, not wchar */
    h = FS_FindFirst(fsearch, 0, 0, &info, fn, 128);
    if (h < 0)
    {
        return;
    }
    do
    {
        /*
         * skip  1) current dir . 
         * *       2) parent dir .. 
         * *       3) directories
         */
        if (kal_wstrcmp(fn, kal_toWCHAR(".")) != 0 &&
            kal_wstrcmp(fn, kal_toWCHAR("..")) != 0 && (info.Attributes & FS_ATTR_DIR) == 0)
        {
            FS_Delete(filename);
        }
    } while (FS_FindNext(h, &info, fn, 128) == FS_NO_ERROR);

    FS_FindClose(h);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_util_reset_file_attr
 * DESCRIPTION
 *  Reset the file attribute to accessible.
 * PARAMETERS
 *  file name        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_util_reset_file_attr(U16 *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 attr = 0;
    FS_HANDLE file_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    file_handle = FS_Open((U16*) file_name, FS_READ_ONLY);
    if (file_handle > 0)
    {
        /* if read-only, reset it */
        attr = FS_GetAttributes((const WCHAR*) file_name);
        if (attr & FS_ATTR_READ_ONLY)
        {
            FS_SetAttributes((const WCHAR*) file_name, (U8) (attr & ~(FS_ATTR_READ_ONLY)));
        }
        FS_Close(file_handle);
    }
}


#ifdef __MMI_EMAIL_DRM_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_email_drm_is_file_lock
 * DESCRIPTION
 *  Whether is DRM file and whether can forward.
 * PARAMETERS
 *  file_name        [IN]        
 *  is_drm_file      [OUT]      
 * RETURNS
 *  whether can forward
 *****************************************************************************/
BOOL mmi_email_drm_is_file_lock(PS8 file_name, BOOL *is_drm_file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 method = DRM_METHOD_NONE;
    FS_HANDLE handle;
    BOOL can_fwd = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    handle = DRM_open_file((PU16) file_name, FS_READ_ONLY, DRM_PERMISSION_NONE);
    if (handle >= FS_NO_ERROR)
    {
        if ((method = DRM_get_object_method(handle, NULL)) == DRM_METHOD_NONE)
        {
            /* non DRM file, can forward to anywhere */
            can_fwd = MMI_TRUE;
            *is_drm_file = MMI_FALSE;
        }
        else
        {
            if (method & DRM_METHOD_V2)
            {
                can_fwd = MMI_TRUE;
                *is_drm_file = MMI_FALSE;
            }
            else
            {
                *is_drm_file = MMI_TRUE;
                
                if (method & DRM_METHOD_SEPARATE_DELIVERY)
                {
                    can_fwd = MMI_TRUE;
                }
                else
                {
                    can_fwd = MMI_FALSE;
                }
            }
        }
        DRM_close_file(handle);
    }
    else
    {
        can_fwd = MMI_FALSE;
        /* CD or FL without right */
        if (handle == DRM_RESULT_NO_PERMISSION && is_drm_file != NULL)
        {
            *is_drm_file = MMI_TRUE;
        }
        else
        {
            *is_drm_file = MMI_FALSE;
        }
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_DRM_IS_FILE_LOCK, method, can_fwd, *is_drm_file);
    return can_fwd;
}
#endif /* __MMI_EMAIL_DRM_SUPPORT__ */ 

#ifdef __MMI_EMAIL_TEMPLATE__

/*****************************************************************************
 * FUNCTION
 *  mmi_email_read_template_from_nvram
 * DESCRIPTION
 *  Read template from NVRAM
 * PARAMETERS
 *  index       [IN]        0~30,index of email template
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_read_template_from_nvram(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index >= NVRAM_EMAIL_RECORD_TOTAL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_READ_TEMPLATE_ERROR, index);
        return;
    }

    memset(email_p->scratch_templ_rec, 0, NVRAM_EMAIL_TEMPL_RECORD_SIZE + ENCODING_LENGTH);
    if (ReadRecord(NVRAM_EF_EMAIL_TEMPLATE_LID, (U16) (index + 1), email_p->scratch_templ_rec, NVRAM_EMAIL_TEMPL_RECORD_SIZE, &error)
        < 0)
    {
        email_p->scratch_templ_rec[0] = '\0';
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_write_template_to_nvram
 * DESCRIPTION
 *  Write template to NVRAM
 * PARAMETERS
 *  index       [IN]        0~30,index of email template
 * RETURNS
 *  TRUE: write success, FALSE: write fail
 *****************************************************************************/
U8 mmi_email_write_template_to_nvram(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index >= NVRAM_EMAIL_RECORD_TOTAL)
    {
        return FALSE;
    }

    if (WriteRecord
        (NVRAM_EF_EMAIL_TEMPLATE_LID, (U16) (index + 1 + 1), email_p->scratch_templ_rec, NVRAM_EMAIL_TEMPL_RECORD_SIZE,
         &error) != NVRAM_EMAIL_TEMPL_RECORD_SIZE)
    {
        return FALSE;
    }
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_set_template_language
 * DESCRIPTION
 *  Set template language
 * PARAMETERS
 *  langtype        [IN]        Language type
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_set_template_language(U8 langtype)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    S16 error;
    S8 tempLang[SSC_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(tempLang, 0, SSC_SIZE);
    switch (langtype)
    {
        case EMAIL_TEMPLATE_LANG_ENGLISH:
            memcpy(tempLang, SSC_ENGLISH, SSC_SIZE);
            break;
        case EMAIL_TEMPLATE_LANG_SIMCHINESE:
            memcpy(tempLang, SSC_SCHINESE, SSC_SIZE);
            break;
        case EMAIL_TEMPLATE_LANG_TRACHINESE:
            memcpy(tempLang, SSC_TCHINESE, SSC_SIZE);
            break;
    }
    for (i = 0; i < MAX_LANGUAGES; i++)
    {
        if (strcmp((PS8) gLanguageArray[i].aLangSSC, (S8*) tempLang) == 0)
        {
            if (gCurrLangIndex != i)
            {
                SetCurrentLanguage(i);
                WriteValue(NVRAM_SETTING_LANG, &i, DS_BYTE, &error);
                break;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_unset_template_language
 * DESCRIPTION
 *  Unset template language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_unset_template_language(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_LANGUAGES; i++)
    {
        if (strcmp((PS8) gLanguageArray[i].aLangSSC, (PS8) curr_lang) == 0)
        {
            if (gCurrLangIndex != i)
            {
                SetCurrentLanguage(i);
                WriteValue(NVRAM_SETTING_LANG, &i, DS_BYTE, &error);
                break;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_write_default_template_to_nvram
 * DESCRIPTION
 *  Write default template to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_email_write_default_template_to_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i = 0;
    S8 *tmpl_str;
    U8 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_EMAIL_NUM_TEMPLATES; i++)
    {
        U16 templateindex = i + mmi_email_calc_template_base();

        tmpl_str = GetString(email_template_strings[i]);
        memset(email_p->scratch_templ_rec, 0, NVRAM_EMAIL_TEMPL_RECORD_SIZE + ENCODING_LENGTH);
        if (tmpl_str)
        {
            memcpy(email_p->scratch_templ_rec, tmpl_str, (mmi_ucs2strlen(tmpl_str) + 1) * ENCODING_LENGTH);
        }
        result = mmi_email_write_template_to_nvram(templateindex);
        if (result == FALSE)
        {
            return FALSE;
        }
    }
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_init_templates
 * DESCRIPTION
 *  Init templates
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE: init success, FALSE: init fail
 *****************************************************************************/
U8 mmi_email_init_templates(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static int init_done = 0;
    static S8 templateSignature[MMI_EMAIL_MAX_TEMPLATE_LENGTH + 1] = "AAA";
    S8 buffer[NVRAM_EMAIL_TEMPL_RECORD_SIZE];
    S16 error;
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (init_done)
    {
        return TRUE;
    }

    init_done = 1;

    if (ReadRecord(NVRAM_EF_EMAIL_TEMPLATE_LID, 1, buffer, NVRAM_EMAIL_TEMPL_RECORD_SIZE, &error) < 0)
    {
        buffer[0] = '\0';
    }

    if (buffer[0] == 'A')
    {
        return TRUE;
    }

    memset(curr_lang, 0, SSC_SIZE);
    memcpy(curr_lang, (PS8) gLanguageArray[gCurrLangIndex].aLangSSC, SSC_SIZE);

    for (i = 0; i < MMI_EMAIL_TOTAL_TEMPLATE_LANGUAGE; i++)
    {
        mmi_email_set_template_language((U8) i);
        if (!mmi_email_write_default_template_to_nvram())
        {
            return FALSE;
        }
    }

    mmi_email_unset_template_language();

    if (WriteRecord(NVRAM_EF_EMAIL_TEMPLATE_LID, 1, templateSignature, NVRAM_EMAIL_TEMPL_RECORD_SIZE, &error) <
        NVRAM_EMAIL_TEMPL_RECORD_SIZE)
    {
        return FALSE;
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_deinit_templates
 * DESCRIPTION
 *  Deinit templates
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_deinit_templates(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_EMAIL_NUM_TEMPLATES; i++)
    {
        if (email_p->templates[i] != NULL)
        {
            OslMfree(email_p->templates[i]);
            email_p->templates[i] = NULL;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_load_templates_in_display_list
 * DESCRIPTION
 *  Load templates to display list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_load_templates_in_display_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_email_deinit_templates();
    for (i = 0; i < MMI_EMAIL_NUM_TEMPLATES; i++)
    {
        U16 templateindex = i + mmi_email_calc_template_base() + 1;

        mmi_email_read_template_from_nvram(templateindex);
        email_p->templates[i] = OslMalloc((mmi_ucs2strlen(email_p->scratch_templ_rec) + 1) * ENCODING_LENGTH);
        mmi_ucs2cpy(email_p->templates[i], email_p->scratch_templ_rec);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_get_templates_to_edit
 * DESCRIPTION
 *  Get templates to edit.
 * PARAMETERS         
 *  buffer      [IN/OUT]        Address of string
 *  index       [IN]            Current highlight index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_get_templates_to_edit(S8 *buffer, U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (email_p->templates[index])
    {
        mmi_ucs2cpy((PS8) buffer, (PS8) email_p->templates[index]);
    }
    else
    {
        buffer[0] = buffer[1] = '\0';
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_delete_template
 * DESCRIPTION
 *  Delete template
 * PARAMETERS
 *  index       [IN]        0~9, template index
 * RETURNS
 *  TRUE: delete success, FALSE: delete fail
 *****************************************************************************/
U8 mmi_email_delete_template(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 templateindex = (U16) index + mmi_email_calc_template_base();
    U8 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(email_p->scratch_templ_rec, 0, NVRAM_EMAIL_TEMPL_RECORD_SIZE + ENCODING_LENGTH);
    result = mmi_email_write_template_to_nvram(templateindex);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_store_template
 * DESCRIPTION
 *  Store templates
 * PARAMETERS
 *  index       [IN]        0~9, template index
 * RETURNS
 *  TRUE: store success, FALSE: store fail
 *****************************************************************************/
U8 mmi_email_store_template(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 templateindex = (U16) index + mmi_email_calc_template_base();
    U8 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mmi_email_write_template_to_nvram(templateindex);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_calc_template_base
 * DESCRIPTION
 *  Calculate template base
 * PARAMETERS
 *  void
 * RETURNS
 *  template base
 *****************************************************************************/
U16 mmi_email_calc_template_base(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 temp_lang_offset = 0;
    U16 temp_base = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsTrChineseSet())
    {
        temp_lang_offset = (U8) EMAIL_TEMPLATE_LANG_TRACHINESE;
    }
    else if (IsSmChineseSet())
    {
        temp_lang_offset = (U8) EMAIL_TEMPLATE_LANG_SIMCHINESE;
    }
    else
    {
        temp_lang_offset = (U8) EMAIL_TEMPLATE_LANG_ENGLISH;
    }
    temp_base = temp_lang_offset * MMI_EMAIL_NUM_TEMPLATES;
    return temp_base;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_email_get_template_index
 * DESCRIPTION
 *  Get current highlight index in template list
 * PARAMETERS
 *  nIndex      [IN]        Current highlight index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_get_template_index(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_GET_TEMPLATE_INDEX, nIndex);
    email_p->curr_template_index = nIndex;
}
#endif /* __MMI_EMAIL_TEMPLATE__ */  


/*****************************************************************************
 * FUNCTION
 *  mmi_email_get_disk_free_blocks
 * DESCRIPTION
 *  Get free space of user drive
 * PARAMETERS
 *  void
 * RETURNS
 *  Free space in bytes
 *****************************************************************************/
U32 mmi_email_get_disk_free_blocks(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char path[10];
    WCHAR wpath[10];
    FS_DiskInfo diskinfo;
    kal_uint32 freebytes;
    S8 drive;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef APP_STORAGE_IN_SYS_DRV
    /* Invisible NOR only */
    drive = FS_GetDrive(FS_DRIVE_I_SYSTEM, 1, FS_NO_ALT_DRIVE);
#else /* APP_STORAGE_IN_SYS_DRV */ 
    /* Order: 1. Visible NOR 2. Invisible NOR */
    drive = FS_GetDrive(FS_DRIVE_V_NORMAL, 1, FS_DRIVE_I_SYSTEM);
#endif /* APP_STORAGE_IN_SYS_DRV */ 
    sprintf(path, "%c:\\", drive);
    mmi_asc_to_ucs2(
        (S8*) wpath,
        (S8*) path);
    
    FS_GetDiskInfo(wpath, &diskinfo, FS_DI_FREE_SPACE | FS_DI_BASIC_INFO);
    freebytes = diskinfo.FreeClusters * diskinfo.SectorsPerCluster * diskinfo.BytesPerSector;
    return freebytes;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_is_sim_valid
 * DESCRIPTION
 *  Get SIM status for Email use
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_email_is_sim_valid(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_bootup_is_sim_valid()
#if defined(__MMI_DUAL_SIM_MASTER__)	
        || mmi_bootup_is_sim2_valid()
#endif /* __MMI_DUAL_SIM_MASTER__ */
        )
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


#ifdef __MMI_DUAL_SIM_MASTER__


/*****************************************************************************
 * FUNCTION
 *  mmi_email_get_dualsim_status
 * DESCRIPTION
 *  Dual SIM mode switch
 * PARAMETERS
 *  void
 * RETURNS
 *  whether SIM card is valid to use
 *****************************************************************************/
BOOL mmi_email_get_dualsim_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    E_MTPNP_AD_STATUS status;
    BOOL ret_status = FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    status = MTPNP_AD_Get_Status();
    switch(status)
    {
    case MTPNP_AD_FLIGHT:
        {
            ret_status = FALSE;
        }
        break;
    case MTPNP_AD_CARD1:
        {
            if (!mmi_bootup_is_sim_valid())
            {
                ret_status = FALSE;
            }
            else
            {
                ret_status = TRUE;
            }
        }
        break;
    case MTPNP_AD_CARD2:
        {
            if (!mmi_bootup_is_sim2_valid())
            {
                ret_status = FALSE;
            }
            else
            {
                ret_status = TRUE;
            }
        }
        break;
    case MTPNP_AD_DUALCARD:
    default:
        {
            if (!mmi_email_is_sim_valid())
            {
                ret_status = FALSE;
            }
            else
            {
                ret_status = TRUE;
            }
        }
        break;
    }
    return ret_status;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_email_bearer_status_show_icon
 * DESCRIPTION
 *  Email icon status according to network bear status.
 * PARAMETERS
 *  void
 * RETURNS
 *  whether to hide Email icon
 *****************************************************************************/
BOOL mmi_email_bearer_status_show_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_email_bearer_status_show_icon_ex(TRUE);
}


/*****************************************************************************
* FUNCTION
*  mmi_email_bearer_status_show_icon_ex
* DESCRIPTION
*  Email icon status according to network bear status.
* PARAMETERS
*  check_usb       [IN]        whether check USB status
* RETURNS
*  whether to hide Email icon
*****************************************************************************/
BOOL mmi_email_bearer_status_show_icon_ex(BOOL check_usb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_WLAN_FEATURES__
    BOOL preferred_mode = FALSE;
#endif /* __MMI_WLAN_FEATURES__ */
    BOOL sim_card = FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __USB_IN_NORMAL_MODE__
    if (check_usb && mmi_usb_is_in_mass_storage_mode())
    {
        HideStatusIcon(STATUS_ICON_UNREAD_EMAIL);
        UpdateStatusIcons();
        return FALSE;
    }
#endif /* __USB_IN_NORMAL_MODE__ */
#ifdef __FLIGHT_MODE_SUPPORT__
    if (mmi_bootup_get_active_flight_mode())
    {
        HideStatusIcon(STATUS_ICON_UNREAD_EMAIL);
        UpdateStatusIcons();
        return FALSE;
    }
#endif /* __FLIGHT_MODE_SUPPORT__ */
#ifdef __MMI_DUAL_SIM_MASTER__
    sim_card = mmi_email_get_dualsim_status();
#else
    sim_card = mmi_email_is_sim_valid();
#endif /* __MMI_DUAL_SIM_MASTER__ */
#ifdef __MMI_WLAN_FEATURES__
    preferred_mode = (mmi_netset_get_active_preferred_mode() == P_GSM_ONLY) ? TRUE : FALSE;
    if (email_p->misc_info.is_wlan_valid == MMI_TRUE)
    {
        if (!sim_card && preferred_mode)
        {
            HideStatusIcon(STATUS_ICON_UNREAD_EMAIL);
            UpdateStatusIcons();
            return FALSE;
        }
        else
        {
            mmi_email_util_update_status_icon();
            return TRUE;
        }
    }
#endif /* __MMI_WLAN_FEATURES__ */
    if (sim_card)
    {
        mmi_email_util_update_status_icon();
        return TRUE;
    }
    HideStatusIcon(STATUS_ICON_UNREAD_EMAIL);
    UpdateStatusIcons();
    return FALSE;
}


#endif /* __MMI_EMAIL__ */
#endif /* _MMI_EMAILAPPMISCELL_C */

