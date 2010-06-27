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
 * mmi_imps_util.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements all common utilities for IMPS application.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifndef _MMI_IMPS_UTIL_C
#define _MMI_IMPS_UTIL_C
#ifdef __MMI_IMPS__
/*  Include: MMI header file */

#include "CommonScreens.h"


#include "wgui_inline_edit.h"

#include "IMPSResDef.h"
#include "mmi_imps_prot.h"
#include "custom_imps_config.h"

#include "nvram_user_defs.h"
#include "FileManagerGProt.h"
#include "wgui_tab_bars.h"
#include "Wgui_status_icons.h"
#include "QuickAccessMenuItemProt.h"
#include "ProfileGprots.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "gpioInc.h"
#include "CallManagementGprot.h"
#include "IdleAppDef.h"
#include "app_mine.h"
#include "wap_ps_struct.h"

#ifdef __MMI_SUBLCD_MASTER_MODE__
#endif


/*  Include: PS header file */
/* ... Add More PS header */

/***************************************************************************** 
* Define
*****************************************************************************/

/***************************************************************************** 
* Typedef 
*****************************************************************************/

/***************************************************************************** 
* Local Variable
*****************************************************************************/
const S8 g_imps_cont_filename[] = { 'c', '\0', 'o', '\0', 'n', '\0', 't', '\0', '\0', '\0' };
const S8 g_imps_group_filename[] = { 'g', '\0', 'r', '\0', 'o', '\0', 'u', '\0', 'p', '\0', '\0', '\0' };
const S8 g_imps_three_dot[] = { '.', '\0', '.', '\0', '.', '\0', '\0', '\0' };

#ifdef __MTK_TARGET__
__align(2)
#endif 
     const U8 g_imps_msg_tone[] = 
     {
         0x4D, 0x54, 0x68, 0x64, 0x00, 0x00, 0x00, 0x06,
         0x00, 0x00, 0x00, 0x01, 0x03, 0xC0, 0x4D, 0x54,
         0x72, 0x6B, 0x00, 0x00, 0x00, 0xA2, 0x00, 0xFF,
         0x02, 0x16, 0x43, 0x6F, 0x70, 0x79, 0x72, 0x69,
         0x67, 0x68, 0x74, 0x20, 0x63, 0x20, 0x32, 0x30,
         0x30, 0x35, 0x20, 0x62, 0x79, 0x20, 0x43, 0x43,
         0x00, 0xFF, 0x01, 0x02, 0x43, 0x43, 0x00, 0xFF,
         0x58, 0x04, 0x04, 0x02, 0x18, 0x08, 0x00, 0xFF,
         0x59, 0x02, 0x00, 0x00, 0x00, 0xFF, 0x51, 0x03,
         0x03, 0xD0, 0x90, 0x00, 0xC0, 0x60, 0x00, 0xB0,
         0x07, 0x6E, 0x00, 0x90, 0x3E, 0x64, 0x00, 0xC1,
         0x52, 0x00, 0xB1, 0x07, 0x5C, 0x00, 0x91, 0x3E,
         0x64, 0x83, 0x60, 0x90, 0x43, 0x64, 0x00, 0x91,
         0x43, 0x64, 0x83, 0x60, 0x90, 0x45, 0x64, 0x00,
         0x91, 0x45, 0x64, 0x81, 0x70, 0x90, 0x35, 0x64,
         0x00, 0x24, 0x64, 0x00, 0x91, 0x30, 0x64, 0x00,
         0x2B, 0x64, 0x00, 0x26, 0x64, 0x81, 0x70, 0x35,
         0x64, 0x81, 0x70, 0x26, 0x00, 0x00, 0x2B, 0x00,
         0x00, 0x90, 0x24, 0x00, 0x00, 0x35, 0x00, 0x00,
         0x91, 0x30, 0x00, 0x00, 0x90, 0x43, 0x00, 0x00,
         0x3E, 0x00, 0x81, 0x70, 0x45, 0x00, 0x00, 0x91,
         0x3E, 0x00, 0x00, 0x35, 0x00, 0x81, 0x70, 0x45,
         0x00, 0x00, 0x43, 0x00, 0x00, 0xFF, 0x2F, 0x00,

     };

 #ifdef __MTK_TARGET__
__align(2)
 #endif 
     const U8 g_imps_err_tone[] = 
     {
         0x4D, 0x54, 0x68, 0x64, 0x00, 0x00, 0x00, 0x06,
         0x00, 0x00, 0x00, 0x01, 0x03, 0xC0, 0x4D, 0x54,
         0x72, 0x6B, 0x00, 0x00, 0x00, 0x76, 0x00, 0xFF,
         0x02, 0x16, 0x43, 0x6F, 0x70, 0x79, 0x72, 0x69,
         0x67, 0x68, 0x74, 0x20, 0x63, 0x20, 0x32, 0x30,
         0x30, 0x33, 0x20, 0x62, 0x79, 0x20, 0x43, 0x43,
         0x00, 0xFF, 0x01, 0x02, 0x43, 0x43, 0x00, 0xFF,
         0x58, 0x04, 0x04, 0x02, 0x18, 0x08, 0x00, 0xFF,
         0x59, 0x02, 0x00, 0x00, 0x00, 0xFF, 0x51, 0x03,
         0x09, 0x27, 0xC0, 0x00, 0x99, 0x44, 0x64, 0x00,
         0x4F, 0x64, 0x00, 0x52, 0x7D, 0x05, 0x38, 0x64,
         0x23, 0x4B, 0x64, 0x2A, 0x4A, 0x64, 0x05, 0x3E,
         0x64, 0x35, 0x41, 0x64, 0x53, 0x4D, 0x64, 0x05,
         0x42, 0x64, 0x0C, 0x52, 0x00, 0x00, 0x44, 0x00,
         0x00, 0x4F, 0x00, 0x05, 0x38, 0x00, 0x23, 0x4B,
         0x00, 0x2A, 0x4A, 0x00, 0x05, 0x3E, 0x00, 0x35,
         0x41, 0x00, 0x53, 0x4D, 0x00, 0x05, 0x42, 0x00,
         0x00, 0xFF, 0x2F, 0x00,
     };

/***************************************************************************** 
* Local Function
*****************************************************************************/

/***************************************************************************** 
* Global Variable
*****************************************************************************/

const mmi_imps_err_mapping_struct g_imps_err_tbl[] = 
{
    {IMPS_OK,     STR_GLOBAL_OK},                                         /* 0 */
    {IMPS_ERROR_GENERAL, STR_ID_IMPS_ERR_UNKNOWN_ERROR},              /* -1 */
    {IMPS_ERROR_INVALID_PARAMETER, STR_ID_IMPS_ERR_INVALID_INPUT},    /* -2 */
    {IMPS_ERROR_WRONG_TRANSACTION_ID, STR_ID_IMPS_ERR_UNKNOWN_ERROR}, /* -3 */   
    {IMPS_ERROR_HTTP_FAIL, STR_ID_IMPS_ERR_CONN_FAILED},              /* -4 */
    {IMPS_ERROR_ABORT_FAIL, STR_ID_IMPS_ERR_ABORT_FAIL},                   /* -5 */
    {IMPS_ERROR_WRONG_MSG_TYPE, STR_ID_IMPS_ERR_CONN_FAILED},              /* -6 */  
    {IMPS_ERROR_REQUEST_TIMEOUT, STR_ID_IMPS_ERR_REQUEST_TIMEOUT},         /* -7 */   
    {IMPS_ERROR_CREATE_XML_FILE_FAIL, STR_ID_IMPS_ERR_SEND_REQUEST_FAIL},  /* -8 */     /* attar : request can not be fulfilled */
    {IMPS_ERROR_PARSE_XML_FILE_FAIL, STR_ID_IMPS_ERR_RECV_RESPONSE_FAIL},  /* -9 */     /* attar : invalid content format */
    {IMPS_ERROR_FILE_ACCESS_ERROR, STR_ID_IMPS_ERR_FILE_ACCESS_ERROR},     /* -10 */   
    {IMPS_ERROR_SERVICE_UNAVAILABLE, STR_ID_IMPS_ERR_UNKNOWN_ERROR},       /* -11 */   
    {IMPS_ERROR_SERVICE_NOT_AGREED, STR_ID_IMPS_ERR_UNSUPPORT_SERVICE}, /* -12 */
    {IMPS_ERROR_NOT_LOGGED_IN, STR_ID_IMPS_ERR_NOT_LOGIN},              /* -13 */
    {IMPS_ERROR_ALREADY_LOGGED_IN, STR_ID_IMPS_ERR_ALREADY_LOGIN},      /* -14 */
    {IMPS_ERROR_LOGIN_INVALID_PASSWD, STR_ID_IMPS_ERR_INVALID_PASSWD},  /* -15 */
    {IMPS_ERROR_LOGIN_INVALID_USER, STR_ID_IMPS_ERR_INVALID_USERNAME},  /* -16 */
    {IMPS_ERROR_LOGIN_INVALID_SERVER, STR_ID_IMPS_ERR_INVALID_SERVER},  /* -17 */
    {IMPS_ERROR_BAD_CLIENT_REQUEST, STR_ID_IMPS_ERR_INVALID_REQUEST},   /* -18 */
    {IMPS_ERROR_SERVER_NOT_SUPPORT, STR_ID_IMPS_ERR_SERVER_NOT_SUPPORT},/* -19 */
    {IMPS_ERROR_SESSION_PROBLEM, STR_ID_IMPS_ERR_SESSION_PROBLEM},      /* -20 */ /* attar: imps sesssion related problem */
    {IMPS_ERROR_PRESENCE_PROBLEM, STR_ID_IMPS_ERR_PRESENCE_PROBLEM},    /* -21 */ /* attar: imps presence related problem */
    {IMPS_ERROR_GROUP_PROBLEM, STR_ID_IMPS_ERR_GROUP_PROBLEM},          /* -22 *//* attar: imps group related problem */
    {IMPS_ERROR_SENDER_IS_BLOCKED, STR_ID_IMPS_ERR_MSG_SEND_FAIL},      /* -23 */   
    {IMPS_ERROR_UNAUTHORIZED, STR_ID_IMPS_ERR_AUTH_FAIL},               /* -24 */    
    {IMPS_ERROR_SCREEN_NAME_IN_USE, STR_ID_IMPS_ERR_SNAME_IN_USE},      /* -25 */ 
    {IMPS_ERROR_SEARCH_NEED_NAME_OR_TOPIC, STR_ID_IMPS_ERR_NO_SEATCH_RESULT},          /* -26 */
    {IMPS_ERROR_TOO_BROAD_SEARCH_CRITERIA, STR_ID_IMPS_ERR_TOO_BROAD_SEARCH_CRITERIA}, /* -27 */  
    {IMPS_ERROR_SUBSCRIPTION_NOT_SUPPORT, STR_ID_IMPS_ERR_UNKNOWN_ERROR},   /* -28 */    
    {IMPS_ERROR_GROUP_ALREADY_EXIST, STR_ID_IMPS_ERR_ROOM_EXIST},           /* -29 */        
    {IMPS_ERROR_GROUP_NOT_EXIST, STR_ID_IMPS_ERR_ROOM_NOT_EXIST},           /* -30 */
    {IMPS_ERROR_GROUP_ALREADY_JOINED, STR_ID_IMPS_ERR_ROOM_ALREADY_JOINED}, /* -31 */ 
    {IMPS_ERROR_GROUP_NOT_JOINED, STR_ID_IMPS_ERR_ROOM_NOT_JOINED},         /* -32 */
    {IMPS_ERROR_FORCED_LEAVE_GROUP, STR_GLOBAL_ERROR},                      /* -33 */ /* not required, because it's sent with MSG_ID_MMI_IMPS_LEAVE_GROUP_IND */
    {IMPS_ERROR_PRIVATE_MESSAGE_DISABLED, STR_ID_IMPS_ERR_INVALID_REQUEST}, /* -34 */
    {IMPS_ERROR_INVITE_NOT_EXIST, STR_ID_IMPS_ERR_INVALID_REQUEST},         /* -35 */
    {IMPS_ERROR_UNSUPPORT_CONTENT_TYPE, STR_ID_IMPS_ERR_INVALID_REQUEST},   /* -36 */
    {IMPS_ERROR_IM_NOT_EXIST, STR_ID_IMPS_ERR_INVALID_REQUEST},             /* -37 */
    {IMPS_ERROR_MESSAGE_IS_REJECTED, STR_ID_IMPS_ERR_MSG_REJECT_BY_RECIPIENT},  /* -38 */        
    {IMPS_ERROR_HIT_MAX_GROUP, STR_ID_IMPS_ERR_CHAT_ROOM_FULL},            /* -39 */
    {IMPS_ERROR_HIT_MAX_TRANSACTION, STR_ID_IMPS_ERR_NETWORK_BUSY},        /* -40 */
    {IMPS_ERROR_HIT_MAX_INVITATION, STR_ID_IMPS_ERR_NETWORK_BUSY},         /* -41 */
    {IMPS_ERROR_HIT_MAX_CONTACTS, STR_ID_IMPS_ERR_CONT_FULL},              /* -42 */
    {IMPS_ERROR_HIT_MAX_CONTACT_LISTS, STR_ID_IMPS_ERR_CONT_LIST_FULL},    /* -43 */
    {IMPS_ERROR_HIT_MAX_JOINED_USER, STR_ID_IMPS_ERR_ROOM_FULL},           /* -44 */
    {IMPS_ERROR_SERVER_OR_NETWORK_ERROR, STR_ID_IMPS_ERR_SERVER_OR_NETWORK_ERROR},  /* -45 */
    {IMPS_ERROR_NO_ENOUGH_SPACE, STR_ID_IMPS_ERR_NO_ENOUGH_SPACE},                  /* -46 */
    {IMPS_ERROR_NO_AVAILABLE_VERSION, STR_ID_IMPS_ERR_NO_AVAILABLE_VERSION},        /* -47 */
    {IMPS_ERROR_SYSTEM_MESSAGE_RESPONSE_REQUIRE, STR_ID_IMPS_ERR_SYSTEM_MESSAGE_RESPONSE_REQUIRE},  /* -48 */
    {IMPS_ERROR_TOO_MANY_WRONG_SYSTEM_MESSAGE_RESPONSE, STR_ID_IMPS_ERR_TOO_MANY_WRONG_SM_RESPONSE},/* -49 */
    {IMPS_ERROR_UNKNOWN_SYSTEM_MESSAGE_ID, STR_ID_IMPS_ERR_UNKNOWN_SYSTEM_MESSAGE_ID},              /* -50 */
    {IMPS_ERROR_INCORRECT_VERIFICATION_KEY, STR_ID_IMPS_ERR_INCORRECT_VERIFICATION_KEY},            /* -51 */
    {IMPS_ERROR_MESSAGE_TOO_LARGE, STR_ID_IMPS_ERR_MESSAGE_TOO_LARGE},          /* -52 */
    {IMPS_ERROR_DATA_NOT_COMPLETE, STR_ID_IMPS_ERR_DATA_NOT_COMPLETE},          /* -53 */
    {IMPS_ERROR_UNSUPPORTED_MEDIA_TYPE, STR_ID_IMPS_ERR_INVALID_REQUEST},       /* -54 */
    {IMPS_ERROR_NOT_ALLOWED_NOTIFICATION_TYPE, STR_ID_IMPS_ERR_INVALID_REQUEST},/* -55 */
    {IMPS_ERROR_MINIMUM_AGE_NOT_FULFILLED, STR_ID_IMPS_ERR_INVALID_REQUEST},    /* -56 */        
    {IMPS_ERROR_PUBLIC_PROFILE_NOT_COMPLETE, STR_ID_IMPS_ERR_PP_NOT_COMPLETE},  /* -57 */
    {IMPS_ERROR_PUBLIC_PROFILE_NOT_AVAILABLE, STR_ID_IMPS_ERR_PP_NOT_COMPLETE}, /* -58 */ 
    {IMPS_ERROR_NOT_SUCCESSFULLY_LOGOUT_LAST_TIME, STR_ID_IMPS_ERR_UNKNOWN_ERROR},  /* -59 */ 
    {IMPS_ERROR_DOMAIN_NOT_SUPPORTED, STR_ID_IMPS_ERR_INVALID_REQUEST},         /* -60 */
    {IMPS_ERROR_GROUP_INSUFFICIENT_PRIVILEGES,     STR_ID_IMPS_ERR_INVALID_REQUEST}, /* -61 */
    {IMPS_ERROR_USER_ID_TOO_LONG,     STR_ID_IMPS_ERR_ID_TOO_LONG},                  /* -62 */
    {IMPS_ERROR_PASSWORD_TOO_LONG,     STR_ID_IMPS_ERR_PSW_TOO_LONG}                 /* -63 */
};

/*****************************************************************************
* Global Function
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_util_get_err_str
 * DESCRIPTION
 *  Get error string for a error code.
 * PARAMETERS
 *  err     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_imps_util_get_err_str(S32 err)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;
    S16 entry;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    entry = sizeof(g_imps_err_tbl) / sizeof(mmi_imps_err_mapping_struct);

    for (i = 0; i < entry; i++)
    {
        if (g_imps_err_tbl[i].err_cause == err)
        {
            return g_imps_err_tbl[i].str_id;
        }
    }

    return STR_ID_IMPS_ERR_UNKNOWN_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_util_init_list
 * DESCRIPTION
 *  Initialize contact list and group list from file system.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_util_init_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_util_read_cont();
    mmi_imps_util_read_group();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_util_read_nvram
 * DESCRIPTION
 *  Read profile info from NVRAM
 * PARAMETERS
 *  buff        [?]     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_util_read_nvram(void *buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(NVRAM_EF_IMPS_LID, 1, (void*)buff, NVRAM_EF_IMPS_SIZE, &error);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_util_write_nvram
 * DESCRIPTION
 *  Write profile info to NVRAM
 * PARAMETERS
 *  buff        [?]     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_util_write_nvram(void *buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteRecord(NVRAM_EF_IMPS_LID, 1, (void*)buff, NVRAM_EF_IMPS_SIZE, &error);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_util_get_file_size
 * DESCRIPTION
 *  Get size of a file
 * PARAMETERS
 *  filePathPtr     [?]     [?]     [?]     [?]
 *  fileSizePtr     [?]     [?]     [?]     [?]
 *  fileSizePrt(?)      [IN/OUT]        Address to store the size of file(?)(?)(?)
 *  filePathPrt(?)      [IN]            File path and name(?)(?)(?)
 * RETURNS
 *  Error cause of file open
 *****************************************************************************/
S32 mmi_imps_util_get_file_size(S8 *filePathPtr, S32 *fileSizePtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fileHandle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fileHandle = FS_Open((U16*) filePathPtr, FS_READ_ONLY);

    if (fileHandle > 0)
    {
        S32 result;

        result = FS_GetFileSize(fileHandle, (U32*) fileSizePtr);

        FS_Close(fileHandle);

        return result;
    }

    return fileHandle;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_util_check_file_exist
 * DESCRIPTION
 *  Check if the file already exists.
 * PARAMETERS
 *  filePathName        [IN]        Full file path + name
 * RETURNS
 *  TRUE if exists, otherwise, FALSE.
 *****************************************************************************/
BOOL mmi_imps_util_check_file_exist(S8 *filePathName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fileHandle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fileHandle = FS_Open((U16*) filePathName, FS_READ_ONLY);

    if (fileHandle > 0)
    {
        FS_Close(fileHandle);
        return TRUE;
    }

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_util_update_cont
 * DESCRIPTION
 *  Remove dangling file and update contact list to file
 * PARAMETERS
 *  void
 *  filePathName(?)     [IN]        Full file path + name(?)(?)(?)
 * RETURNS
 *  TRUE if exists, otherwise, FALSE.(?)(?)(?)(?)
 *****************************************************************************/
void mmi_imps_util_update_cont(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 count = (S32) imps_p->cont_info.no_cont;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* remove dangling contact list */
    for (i = 0; i < count; i++)
    {
        if ((imps_p->cont_info.cont_list[i].comm_state & IMPS_CONT_PA_READY) == 0)
        {
            if (i < (count - 1))
            {
                memcpy(&imps_p->cont_info.cont_list[i], &imps_p->cont_info.cont_list[i + 1], (count - i - 1));
                memset(&imps_p->cont_info.cont_list[count], 0, sizeof(mmi_imps_cont_struct));
            }
            else
            {
                memset(&imps_p->cont_info.cont_list[i], 0, sizeof(mmi_imps_cont_struct));
            }

            count--;
        }
    }

    imps_p->cont_info.no_cont = (U8) count;

    mmi_imps_util_write_cont();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_util_write_cont
 * DESCRIPTION
 *  Write contact list data to file
 * PARAMETERS
 *  void
 * RETURNS
 *  result of file operation
 *****************************************************************************/
S32 mmi_imps_util_write_cont(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fileHandle;
    S16 *ucs2_folder = OslMalloc((FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_util_get_work_path((S8*) ucs2_folder);
    mmi_ucs2cat((S8*) ucs2_folder, (S8*) g_imps_cont_filename);

    fileHandle = FS_Open((U16*) ucs2_folder, FS_CREATE_ALWAYS);

    OslMfree(ucs2_folder);

    if (fileHandle > 0)
    {
        S32 result;

        U32 len;

        result = FS_Write(
                    fileHandle,
                    (void*)&imps_p->cont_info.cont_list[0],
                    sizeof(mmi_imps_cont_struct) * IMPS_MAX_NO_CONT,
                    (U32*) & len);

        FS_Close(fileHandle);

        return result;
    }

    return fileHandle;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_util_read_cont
 * DESCRIPTION
 *  Read contact list data from file
 * PARAMETERS
 *  void
 * RETURNS
 *  result of file operation
 *****************************************************************************/
S32 mmi_imps_util_read_cont(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fileHandle;
    S16 *ucs2_folder = OslMalloc((FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH);
    mmi_imps_cont_struct *cont;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_util_get_work_path((S8*) ucs2_folder);
    mmi_ucs2cat((S8*) ucs2_folder, (S8*) g_imps_cont_filename);

    fileHandle = FS_Open((U16*) ucs2_folder, FS_READ_ONLY);

    if (fileHandle > 0)
    {
        U32 len;
        S32 i;

        FS_Read(
            fileHandle,
            (void*)&imps_p->cont_info.cont_list[0],
            sizeof(mmi_imps_cont_struct) * IMPS_MAX_NO_CONT,
            (U32*) & len);

        for (i = 1; i < IMPS_MAX_NO_CONT; i++)
        {
            cont = &imps_p->cont_info.cont_list[i];
            if (strlen((S8*) cont->id))
            {
                cont->comm_state = 0;
                cont->availability = IMPS_PA_USER_UNKNOWN;
            }
            else
            {
                break;
            }
        }

        imps_p->cont_info.no_cont = (U8) i;

        FS_Close(fileHandle);

        OslMfree(ucs2_folder);

    }
#ifdef IMPS_TEST_CODE
    else
    {
        S32 result;
        U32 len;
        S32 i;

        fileHandle = FS_Open((U16*) ucs2_folder, FS_CREATE_ALWAYS);

        if (strlen((S8*) imps_p->act_prof.username) == 0)
        {
            strcpy((S8*) imps_p->cont_info.cont_list[0].id, (S8*) "Max Chen");
        }
        else
        {
            strcpy((S8*) imps_p->cont_info.cont_list[0].id, (S8*) imps_p->act_prof.username);
        }

        strcpy((S8*) imps_p->cont_info.cont_list[0].group_id, (S8*) "MySelf");
        mmi_ucs2cpy((S8*) imps_p->cont_info.cont_list[0].alias, (S8*) L"MAXMAX");

        for (i = 1; i < IMPS_MAX_NO_CONT; i++)
        {
            sprintf((S8*) imps_p->cont_info.cont_list[i].id, (S8*) "Max %ld", i);
            sprintf((S8*) imps_p->cont_info.cont_list[i].group_id, "WCP_SW_PS%ld", (IMPS_MAX_NO_CONT - i));
            mmi_asc_to_ucs2((S8*) imps_p->cont_info.cont_list[i].alias, (S8*) "IMPS");
            imps_p->cont_info.cont_list[i].availability = (U8) (i % 3);
        }
        result = FS_Write(
                    fileHandle,
                    (void*)&imps_p->cont_info.cont_list[0],
                    sizeof(mmi_imps_cont_struct) * IMPS_MAX_NO_CONT,
                    (U32*) & len);

        FS_Close(fileHandle);

        OslMfree(ucs2_folder);

        return result;
    }
#elif defined(IMPS_PROF_TEST_CODE)
    else
    {
        S32 result;
        U32 len;

        fileHandle = FS_Open((U16*) ucs2_folder, FS_CREATE_ALWAYS);

        if (strlen((S8*) imps_p->act_prof.username) == 0)
        {
            strcpy((S8*) imps_p->cont_info.cont_list[0].id, (S8*) "wv:max");
        }
        else
        {
            strcpy((S8*) imps_p->cont_info.cont_list[0].id, (S8*) imps_p->act_prof.username);
        }

        strcpy((S8*) imps_p->cont_info.cont_list[0].group_id, (S8*) "MySelf");
        mmi_ucs2cpy((S8*) imps_p->cont_info.cont_list[0].nick_name, (S8*) L"max");

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* 0 */ 

        result = FS_Write(
                    fileHandle,
                    (void*)&imps_p->cont_info.cont_list[0],
                    sizeof(mmi_imps_cont_struct) * 1,
                    (U32*) & len);

        FS_Close(fileHandle);
        imps_p->cont_info.no_cont = (U8) 1;

        OslMfree(ucs2_folder);

        return result;
    }
#endif 
    return fileHandle;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_util_write_group
 * DESCRIPTION
 *  Write group data to file
 * PARAMETERS
 *  void
 * RETURNS
 *  result of file operation
 *****************************************************************************/
S32 mmi_imps_util_write_group(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fileHandle;
    S16 *ucs2_folder = OslMalloc((FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_util_get_work_path((S8*) ucs2_folder);

    mmi_ucs2cat((S8*) ucs2_folder, (S8*) g_imps_group_filename);

    fileHandle = FS_Open((U16*) ucs2_folder, FS_CREATE_ALWAYS);

    OslMfree(ucs2_folder);

    if (fileHandle > 0)
    {
        S32 result;
        U32 len;

        result = FS_Write(
                    fileHandle,
                    (void*)&imps_p->group_info.group_list[0],
                    sizeof(mmi_imps_group_struct) * IMPS_MAX_NO_GROUP,
                    (U32*) & len);
        FS_Close(fileHandle);

        return result;
    }

    return fileHandle;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_util_read_group
 * DESCRIPTION
 *  Write group data to file
 * PARAMETERS
 *  void
 * RETURNS
 *  result of file operation
 *****************************************************************************/
S32 mmi_imps_util_read_group(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fileHandle;
    S16 *ucs2_folder = OslMalloc((FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_util_get_work_path((S8*) ucs2_folder);
    mmi_ucs2cat((S8*) ucs2_folder, (S8*) g_imps_group_filename);

    fileHandle = FS_Open((U16*) ucs2_folder, FS_READ_ONLY);

    if (fileHandle > 0)
    {
        U32 len;
        S32 i;

        FS_Read(
            fileHandle,
            (void*)&imps_p->group_info.group_list[0],
            sizeof(mmi_imps_group_struct) * IMPS_MAX_NO_GROUP,
            (U32*) & len);

        for (i = 0; i < IMPS_MAX_NO_GROUP; i++)
        {
            if (strlen((S8*) imps_p->group_info.group_list[i].group_id))
            {
                imps_p->group_info.group_list[i].is_sync = FALSE;
            }
            else
            {
                break;
            }
        }

        imps_p->group_info.no_group = (U8) i;

        FS_Close(fileHandle);
        OslMfree(ucs2_folder);
        return 0;
    }
#ifdef IMPS_TEST_CODE
    else
    {
        S32 result;
        U32 len;

        fileHandle = FS_Open((U16*) ucs2_folder, FS_CREATE_ALWAYS);
        strcpy((S8*) imps_p->group_info.group_list[0].group_id, (S8*) "WCP_SW_PS1");
        mmi_asc_to_ucs2((S8*) imps_p->group_info.group_list[0].group_name, (S8*) "PS1");
        imps_p->group_info.group_list[0].no_users = (IMPS_MAX_NO_CONT - 1);
        imps_p->group_info.group_list[0].is_sync = TRUE;

        strcpy((S8*) imps_p->group_info.group_list[1].group_id, (S8*) "WCP_SW_PS2");
        mmi_asc_to_ucs2((S8*) imps_p->group_info.group_list[1].group_name, (S8*) "PS2");
        imps_p->group_info.group_list[1].no_users = 0;
        imps_p->group_info.group_list[0].is_sync = FALSE;
        imps_p->group_info.no_group = 2;

        result = FS_Write(
                    fileHandle,
                    (void*)&imps_p->group_info.group_list[0],
                    sizeof(mmi_imps_group_struct) * IMPS_MAX_NO_GROUP,
                    (U32*) & len);

        FS_Close(fileHandle);
        OslMfree(ucs2_folder);
        return result;

    }
#endif /* IMPS_TEST_CODE */ 
    OslMfree(ucs2_folder);
    return fileHandle;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_util_reset_cont_list
 * DESCRIPTION
 *  Reset contact list when data account changed.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_util_reset_cont_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* update contact list */
    memset(&imps_p->cont_info.cont_list[0], 0, IMPS_MAX_NO_CONT * sizeof(mmi_imps_cont_struct));
    strcpy((S8*) imps_p->cont_info.cont_list[0].id, (S8*) imps_p->act_prof.username);
    imps_p->cont_info.no_cont = 1;
    mmi_imps_util_write_cont();

    /* reset group list */
    memset(&imps_p->group_info.group_list[0], 0, IMPS_MAX_NO_GROUP * sizeof(mmi_imps_group_struct));
    mmi_imps_util_write_group();
    imps_p->group_info.no_group = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_util_reset_presence
 * DESCRIPTION
 *  Reset presence data when data account changed.
 * PARAMETERS
 *  buff        [OUT]       Buffer which stores whole NVRAM data.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_util_reset_presence(void *buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_nvram_struct *nvram_data = (mmi_imps_nvram_struct*) buff;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&nvram_data->about_me, 0, sizeof(mmi_imps_presence_nvram_struct));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_util_is_id_same
 * DESCRIPTION
 *  Compare if two ids are identical (without wv:)
 * PARAMETERS
 *  id1     [IN]        Id to be compared
 *  id2     [IN]        Id to be compared
 * RETURNS
 *  TRUE if identical; otherwise, FALSE
 *****************************************************************************/
BOOL mmi_imps_util_is_id_same(S8 *id1, S8 *id2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *str1, *str2;
    S8 *comp1, *comp2;
    BOOL result = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    comp1 = OslMalloc(IMPS_MAX_ID_LEN);
    comp2 = OslMalloc(IMPS_MAX_ID_LEN);

    /* remove wv: */
    str1 = id1;
    if (str1[0] == 'w' && str1[1] == 'v' && str1[2] == ':')
    {
        str1 += 3;
    }

    str2 = id2;
    if (str2[0] == 'w' && str2[1] == 'v' && str2[2] == ':')
    {
        str2 += 3;
    }

    strcpy(comp1, str1);
    strcpy(comp2, str2);

    /* check if @ exist */
    str1 = strstr(comp1, "@");
    str2 = strstr(comp2, "@");

    if (str1 == NULL && str2 != NULL)   /* trancated @ after str_at2 */
    {
        str2[0] = '\0';
    }
    else if (str1 != NULL && str2 == NULL)
    {
        str1[0] = '\0';
    }

    if (mmi_imps_util_stricmp(comp1, comp2) == 0)
    {
        result = TRUE;
    }

    OslMfree(comp1);
    OslMfree(comp2);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_util_is_cont_exist
 * DESCRIPTION
 *  Check if the contact already exists in contact list
 * PARAMETERS
 *  id      [IN]        Id of the contact
 * RETURNS
 *  TRUE if the contact exists; otherwise, FALSE
 *****************************************************************************/
BOOL mmi_imps_util_is_cont_exist(S8 *id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 count = (S32) imps_p->cont_info.no_cont;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if contact exists */

    for (i = 0; i < count; i++)
        if (mmi_imps_util_is_id_same(id, (S8*) imps_p->cont_info.cont_list[i].id))
        {
            return TRUE;
        }

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_util_is_room_joined
 * DESCRIPTION
 *  Check if the user has already joined the chat room
 * PARAMETERS
 *  id      [IN]        Id of the chat room
 * RETURNS
 *  TRUE if the user has already joined the chat room; otherwise, FALSE
 *****************************************************************************/
BOOL mmi_imps_util_is_room_joined(S8 *id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if the room is already joined */
    for (i = 0; i < IMPS_MAX_NO_ROOM; i++)
        if (imps_p->room_info.room_list[i].is_used)
            if (strcmp(id, (S8*) imps_p->room_info.room_list[i].room_id) == 0)
            {
                return TRUE;
            }

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_util_get_empty_room_slot
 * DESCRIPTION
 *  Get the index of empty slot of chat room
 * PARAMETERS
 *  void
 * RETURNS
 *  Index in the chat room array
 *****************************************************************************/
S32 mmi_imps_util_get_empty_room_slot(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if all check rooms are occupied */
    for (i = 0; i < IMPS_MAX_NO_ROOM; i++)
    {
        if (imps_p->room_info.room_list[i].is_used == FALSE)
        {
            break;
        }
    }

    return i;
}

#define NVRAM_FILE_IMPS


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_get_mine_type
 * DESCRIPTION
 *  Reset contact list when data account changed.
 * PARAMETERS
 *  file_ext        [IN]        Get the mine of a file from its file extension.
 * RETURNS
 *  mine type string.
 *****************************************************************************/
S8 *mmi_imps_get_mine_type(S8 *file_ext)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_mime_type_struct *mime = mime_type_look_up(NULL, file_ext, 0, 0);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mime)
    {
        return mime->mime_string;
    }
    else
    {
        return NULL;
    }
}

#ifdef IMPS_TEST_CODE


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_write_watch_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_write_watch_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 len;
    S32 i, count = 5;
    FS_HANDLE fileHandle;
    S16 *ucs2_folder = OslMalloc((FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH);
    imps_watcher_entity_struct *buff = OslMalloc(sizeof(imps_watcher_entity_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_util_get_work_path((S8*) ucs2_folder);

    mmi_ucs2cat((S8*) ucs2_folder, (S8*) L"watch");

    fileHandle = FS_Open((U16*) ucs2_folder, FS_CREATE_ALWAYS);

    for (i = 0; i < count; i++)
    {
        sprintf((S8*) buff->watcher_user_id, "Max Chen %ld", i);
        mmi_asc_to_ucs2((S8*) buff->watcher_status, "WCP_SW_PS1");

        FS_Write(fileHandle, (void*)buff, sizeof(imps_watcher_entity_struct), &len);
    }

    imps_p->search_result.count = 5;

    FS_Close(fileHandle);
    OslMfree(ucs2_folder);
    OslMfree(buff);
}
#endif /* IMPS_TEST_CODE */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_util_get_work_path
 * DESCRIPTION
 *  Get path of working directory
 * PARAMETERS
 *  dest        [OUT]       Buffer to store result
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_util_get_work_path(S8 *dest)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *buff = OslMalloc(FMGR_MAX_PATH_LEN * ENCODING_LENGTH);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(buff, "%s", IMPS_SYS_FILE_DIRECTORY);
    mmi_asc_to_ucs2(dest, buff);
    OslMfree(buff);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_util_get_img_path
 * DESCRIPTION
 *  Get the path to store image
 * PARAMETERS
 *  dest        [OUT]       Buffer to store result
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_util_get_img_path(S8 *dest)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *buff = OslMalloc(FMGR_MAX_PATH_LEN * ENCODING_LENGTH);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(buff, "%s%s", IMPS_SYS_FILE_DIRECTORY, IMPS_STATUS_CONTENT_FOLDER);
    mmi_asc_to_ucs2(dest, buff);
    OslMfree(buff);
}

#define HISTORY_IMPS


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_util_is_in_imps
 * DESCRIPTION
 *  Check if it's currently in IMPS application
 * PARAMETERS
 *  void
 * RETURNS
 *  TURE if it's in IMPS application; otherwise, FALSE.
 *****************************************************************************/
BOOL mmi_imps_util_is_in_imps(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scr_id = GetActiveScreenId();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_imps_util_is_imps_scr(scr_id))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_util_is_imps_scr
 * DESCRIPTION
 *  Check if the screen in IMPS application.
 * PARAMETERS
 *  scr_id      [IN]        Screen index to be examined.
 * RETURNS
 *  TRUE if the screen is an IMPS screen; otherwise, FALSE.
 *****************************************************************************/
BOOL mmi_imps_util_is_imps_scr(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (scr_id > SCR_ID_IMPS_START && scr_id < SCR_ID_IMPS_END)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_util_del_up_to_screen
 * DESCRIPTION
 *  Delete IMPS screens until scr_id
 * PARAMETERS
 *  scr_id      [IN]        Ending screen of deletion, this screen won't be deleted.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_util_del_up_to_screen(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 next_scr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (GetNextScrnIdOf(scr_id, &next_scr))
    {
        if (mmi_imps_util_is_imps_scr(next_scr))
        {
            DeleteScreenIfPresent(next_scr);
        }
        else
        {
            return;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_util_go_back_2_hist
 * DESCRIPTION
 *  Go back to previous 2 screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_util_go_back_2_hist(void)
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
 *  mmi_imps_util_del_scr_after_progress
 * DESCRIPTION
 *  Delete screen between progressing screen and result screen.
 *  Result screen is not included.
 * PARAMETERS
 *  result_scr      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_util_del_scr_after_progress(U16 result_scr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 start_scr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetNextScrnIdOf(result_scr, &start_scr) == MMI_TRUE)
    {
        /* because the result screen might not be in history, this will ensure the correctness */
        DeleteBetweenScreen(start_scr, SCR_ID_IMPS_PROGRESS);
    }
    else
    {
        DeleteScreenIfPresent(SCR_ID_IMPS_PROGRESS);
    }
}

#define BUFF_IMPS


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_util_free_buff_when_logout
 * DESCRIPTION
 *  Free allocated buffers required after login
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_util_free_buff_when_logout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* free allocated buffer when logout automatically or manually */

    /* presence */
    mmi_imps_free_presence_buff();

    /* search data */
    mmi_imps_free_search_mem();

    /* invitation */
    mmi_imps_invite_ind_free_mem();
    mmi_imps_free_invite_list();

    /* edit room */
    mmi_imps_free_room_mem();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_util_get_seq_no
 * DESCRIPTION
 *  Get sequence number of session
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_imps_util_get_seq_no(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ++imps_p->gen_info.seq_no;

    if (imps_p->gen_info.seq_no > IMPS_MAX_SEQ_NUM)
    {
        imps_p->gen_info.seq_no = 1;
    }

    return imps_p->gen_info.seq_no;
}

#define STRING_IMPS


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_util_copy_with_dot
 * DESCRIPTION
 *  Append three dots to the end of string
 * PARAMETERS
 *  source      [IN]            Source buffer.
 *  dest        [IN/OUT]        Destination buffer.
 *  max_len     [IN]            Max characters can be put in destination buffer , including NULL terminate
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_util_copy_with_dot(S8 *source, S8 *dest, S32 max_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen(source) < max_len)
    {
        mmi_ucs2cpy((S8*) dest, (S8*) source);
    }
    else
    {
        /* do not clear end of string because mmi_ucs2ncpy will auto set NULL terminate */
        mmi_ucs2ncpy((S8*) dest, (S8*) source, max_len - 4);
        mmi_ucs2cat((S8*) dest, (S8*) g_imps_three_dot);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_util_ansi_2_ucs2_menu
 * DESCRIPTION
 *  Generate menu item from ASCII string
 * PARAMETERS
 *  source      [IN]            Source buffer.
 *  dest        [IN/OUT]        Destination buffer.
 *  max_len     [IN]            Max characters can be put in destination buffer
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_util_ansi_2_ucs2_menu(S8 *source, S8 *dest, S32 max_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *tmp_buff = OslMalloc((IMPS_MAX_ID_LEN + 1) * ENCODING_LENGTH);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_to_ucs2((S8*) tmp_buff, (S8*) source);
    mmi_imps_util_copy_with_dot((S8*) tmp_buff, (S8*) dest, max_len);
    OslMfree(tmp_buff);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_util_generate_name_hint
 * DESCRIPTION
 *  Generate hint value of a menu item
 * PARAMETERS
 *  source      [IN]        Source buffer.
 *  hint_id     [IN]        Index of hint
 *  max_len     [IN]        Max characters can be put in destination buffer
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_util_generate_name_hint(S8 *source, S32 hint_id, S32 max_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen(source))
    {
        mmi_imps_util_copy_with_dot((S8*) source, (S8*) hintData[hint_id], max_len);
        hintDataPtrs[hint_id] = hintData[hint_id];
    }
    else
    {
        hintDataPtrs[hint_id] = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_util_is_group_name_valid
 * DESCRIPTION
 *  Check if the input user name string is allowable.
 *  A user name can only contains string between ASCII 0x20 ~ 0x7E
 *  The plus (+) character can only be placed before numeric character
 * PARAMETERS
 *  name        [IN]        String of input
 * RETURNS
 *  TRUE if the username string follows spec; otherwise, FALSE.
 *****************************************************************************/
BOOL mmi_imps_util_is_group_name_valid(S8 *name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *buff = OslMalloc(IMPS_MAX_ID_LEN);
    S32 i, len;
    S32 at_count = 0;   /* count of @ symbol */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2_to_asc((S8*) buff, (S8*) name);

    len = strlen(buff);

    /* scan each byte */
    for (i = 0; i < len; i++)
    {
        if (buff[i] <= 0x20 || buff[i] > 0x7E)  /* 0x20 == linear white space */
        {
            break;
        }
        else if (buff[i] == '/')    /* 0x2F */
        {
            break;
        }
        else if (buff[i] == '@')    /* can contain only 1 @ */
        {
            if (!at_count)
            {
                at_count++;
            }
            else
            {
                break;
            }
        }
    }

    OslMfree(buff);

    if (i == len)   /* all characters scanned */
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_util_is_username_valid
 * DESCRIPTION
 *  Check if the input user name string is allowable.
 *  A user name can only contains string between ASCII 0x20 ~ 0x7E
 *  The plus (+) character can only be placed before numeric character
 * PARAMETERS
 *  name        [IN]        String of input
 * RETURNS
 *  TRUE if the username string follows spec; otherwise, FALSE.
 *****************************************************************************/
BOOL mmi_imps_util_is_username_valid(S8 *name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *buff = OslMalloc(IMPS_MAX_ID_LEN);
    S32 i, len;
    S32 at_count = 0;   /* count of @ symbol */
    S32 plus_count = 0; /* if it's numeric plus */
    S32 num_count = 0;  /* count of numeric value */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2_to_asc((S8*) buff, (S8*) name);

    len = strlen(buff);

    if (len == 3 && mmi_imps_util_stricmp((S8*) "wv:", (S8*) buff) == 0)
    {
        return FALSE;
    }

    /* scan each byte */
    for (i = 0; i < len; i++)
    {
        if (buff[i] <= 0x20 || buff[i] > 0x7E)  /* 0x20 == linear white space */
        {
            break;
        }
        else if (buff[i] == '/')    /* 0x2F */
        {
            break;
        }
        else if (buff[i] == '+')
        {
            if (!plus_count)
            {
                plus_count++;
            }
            else
            {
                break;
            }
        }
        else if (buff[i] == '@')    /* can contain only 1 @ */
        {
            if (!at_count)
            {
                at_count++;
            }
            else
            {
                break;
            }
        }
        else if (buff[i] >= 0x30 && buff[i] <= 0x39)
        {
            num_count++;
        }
    }

    OslMfree(buff);

    /* check if the user name is wv:+12324454545 */
    if (plus_count)
    {
        if ((plus_count > 1) || (strncmp((S8*) buff, (S8*) "wv:+", 4) != 0))
        {
            return FALSE;
        }
        else if (num_count != (len - 4))    /* it's not a username like wv:+009099090 (all numberic characters) */
        {
            return FALSE;
        }
    }

    if (i == len)   /* all characters scanned */
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_util_append_wv
 * DESCRIPTION
 *  Check if "wv:" string contains in the string.
 *  If not, append it.
 * PARAMETERS
 *  dest        [OUT]       Buffer to be checked andappended.
 *  max_len     [IN]        Max length of buffer
 * RETURNS
 *  TRUE if the username string follows spec; otherwise, FALSE.(?)(?)(?)(?)
 *****************************************************************************/
void mmi_imps_util_append_wv(S8 *dest, S32 max_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *buff = OslMalloc(IMPS_MAX_ID_LEN * ENCODING_LENGTH);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen(dest) < (max_len - 3)) /* minus length of "wv:" */
    {
        mmi_ucs2_n_to_asc(buff, (S8*) dest, 3 * ENCODING_LENGTH);
        if (mmi_imps_util_strnicmp((S8*) "wv:", buff, 3) != 0) /* no "wv:" */
        {
            mmi_ucs2cpy((S8*) buff, (S8*) L"wv:");
            mmi_ucs2cat((S8*) buff, (S8*) dest);
            mmi_ucs2cpy((S8*) dest, (S8*) buff);
        }
    }

    OslMfree(buff);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_util_tolower
 * DESCRIPTION
 *  Convert a charcater to lower case
 * PARAMETERS
 *  ch      [IN]        Charcater to be converted
 * RETURNS
 *  lower case character
 *****************************************************************************/
U8 mmi_imps_util_tolower(U8 ch)
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
 *  mmi_imps_util_strnicmp
 * DESCRIPTION
 *  Compare two string without case with maximum length
 * PARAMETERS
 *  src         [IN]        String pointer to be compared
 *  dest        [IN]        String pointer to be compared
 *  maxlen      [IN]        Lengh to be compared
 * RETURNS
 *  Ture if two string is identical, otherwise, false
 *****************************************************************************/
S8 mmi_imps_util_strnicmp(S8 *src, S8 *dest, S32 maxlen)
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
        ch1 = mmi_imps_util_tolower(*s1++);
        ch2 = mmi_imps_util_tolower(*s2++);
        if (ch1 != ch2)
        {
            return TRUE;
        }
    }

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_util_stricmp
 * DESCRIPTION
 *  Compare two strings without case
 * PARAMETERS
 *  src         [IN]        String pointer to be compared
 *  dest        [IN]        String pointer to be compared
 * RETURNS
 *  Ture if two string is identical, otherwise, false
 *****************************************************************************/
S8 mmi_imps_util_stricmp(S8 *src, S8 *dest)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 len_src = strlen(src);
    S32 len_dest = strlen(dest);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (len_src != len_dest)
    {
        return TRUE;
    }
    else
    {
        return mmi_imps_util_strnicmp(src, dest, len_src);
    }
}

#define UI_COMMON_IMPS


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_util_blink_tab
 * DESCRIPTION
 *  Common function to blink/unblink tabs
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_util_blink_tab(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < IMPS_MAX_NO_ROOM; i++)
    {
        mmi_imps_room_struct *room = &imps_p->room_info.room_list[i];

        if (room->is_used)
        {
            if (room->unread_msg)
            {
                Category425BlinkTab(room->tab_index);
            }
            else
            {
                Category425UnBlinkTab(room->tab_index);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_util_search_cont
 * DESCRIPTION
 *  Search contact according to his id
 * PARAMETERS
 *  id      [?]     [?]     [?]     [?]     To be search
 * RETURNS
 *  buffer that store the context of the contact
 *****************************************************************************/
mmi_imps_cont_struct *mmi_imps_util_search_cont(S8 *id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    count = (S32) imps_p->cont_info.no_cont;

    for (i = 0; i < count; i++)
        if (mmi_imps_util_is_id_same((S8*) id, (S8*) imps_p->cont_info.cont_list[i].id))      /* contact found */
        {
            return &imps_p->cont_info.cont_list[i];
        }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_util_update_status_icon
 * DESCRIPTION
 *  Update status icon when new message comes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_util_update_status_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < IMPS_MAX_NO_ROOM; i++)
    {
        mmi_imps_room_struct *room = &imps_p->room_info.room_list[i];

        if (room->is_used)
        {
            /* still some message there */
            if (room->unread_msg)
            {
                BlinkStatusIcon(STATUS_ICON_IMPS_MSG);
                UpdateStatusIcons();
                return;
            }
        }
    }

    IdleResetStatusIcon(STATUS_ICON_IMPS_MSG);  /* reset message status icon */

    if (imps_p->gen_info.is_login)
    {
        IdleSetStatusIcon(STATUS_ICON_IMPS_LOGIN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_util_update_login_icon
 * DESCRIPTION
 *  Update status icon when login state changed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_util_update_login_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imps_p->gen_info.is_login)
    {
        IdleSetStatusIcon(STATUS_ICON_IMPS_LOGIN);
    }
    else
    {
        IdleResetStatusIcon(STATUS_ICON_IMPS_MSG);  /* reset message status icon */
        IdleResetStatusIcon(STATUS_ICON_IMPS_LOGIN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_util_disp_popup_done
 * DESCRIPTION
 *  Common function to display "Done" in popup screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_util_disp_popup_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TurnOnBacklight(TRUE);
    DisplayPopup(
        (U8*) GetString(STR_GLOBAL_DONE),
        IMG_GLOBAL_ACTIVATED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) SUCCESS_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_util_disp_warning_popup
 * DESCRIPTION
 *  Common function to display warning popup
 * PARAMETERS
 *  str_id      [IN]        Id of string to be displayed
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_util_disp_warning_popup(U16 str_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TurnOnBacklight(TRUE);

    DisplayPopup((U8*) GetString(str_id), IMG_GLOBAL_WARNING, 1, UI_POPUP_NOTIFYDURATION_TIME, (U8) WARNING_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_util_disp_err_popup
 * DESCRIPTION
 *  Common function to display error popup
 * PARAMETERS
 *  str_id      [IN]        Id of string to be displayed
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_util_disp_err_popup(U16 str_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TurnOnBacklight(TRUE);

    DisplayPopup((U8*) GetString(str_id), IMG_GLOBAL_ERROR, 1, UI_POPUP_NOTIFYDURATION_TIME, (U8) ERROR_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_util_disp_empty_popup
 * DESCRIPTION
 *  Common function to display empty popup
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_util_disp_empty_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TurnOnBacklight(TRUE);

    DisplayPopup((PU8) GetString(STR_GLOBAL_EMPTY), IMG_GLOBAL_EMPTY, 0, UI_POPUP_NOTIFYDURATION_TIME, ERROR_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_util_is_on_idle
 * DESCRIPTION
 *  Check if the user is currently on IDLE screen.
 *  Add this function is to prevent too much include files in other files of IMPS
 * PARAMETERS
 *  void
 * RETURNS
 *  IsOnIdleScreen flag in the global context of IDLE screen.
 *****************************************************************************/
U8 mmi_imps_util_is_on_idle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_idle_context.IsOnIdleScreen;
}

#define TAB_IMPS


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_tab_init
 * DESCRIPTION
 *  Initialize tab component
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_tab_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, count;
    mmi_imps_room_struct *room;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_tab_bar_items[0].icon = (PU8) GetImage(IMG_ID_IMPS_CONT_LIST);
    MMI_tab_bar_items[0].text = NULL;
    MMI_tab_bar_items[0].flags = 0;

    count = (S32) imps_p->room_info.no_rooms;

    for (i = 0; i < IMPS_MAX_NO_ROOM; i++)
    {
        room = &imps_p->room_info.room_list[i];
        if (room->is_used)
        {
            S32 tab = (S32) room->tab_index;

            if (room->type == IMPS_ROOM_TYPE_SINGLE)
            {
                MMI_tab_bar_items[tab].icon = (PU8) GetImage(IMG_ID_IMPS_TALK);
            }
            else
            {
                MMI_tab_bar_items[tab].icon = (PU8) GetImage(IMG_ID_IMPS_CHAT_ROOM);
            }

            MMI_tab_bar_items[tab].text = NULL;
            MMI_tab_bar_items[tab].flags = 0;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_tab_jump_current
 * DESCRIPTION
 *  Jump to current tab
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_tab_jump_current(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < IMPS_MAX_NO_ROOM; i++)
        if (imps_p->room_info.room_list[i].is_used)
            if (imps_p->room_info.room_list[i].tab_index == imps_p->gen_info.curr_tab)
            {
                imps_p->chat_info.curr_room = (U8) i;
                break;
            }

    imps_p->room_info.room_list[imps_p->chat_info.curr_room].clear_gui_buff = TRUE;

    mmi_imps_entry_chat();
    DeleteScreenIfPresent(SCR_ID_IMPS_CONT);
    DeleteScreenIfPresent(SCR_ID_IMPS_CHAT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_tab_del
 * DESCRIPTION
 *  Swap to previous tab
 * PARAMETERS
 *  tab_index       [IN]        Index of tab to be removed.
 *  hilite          [IN]        Hilited tab after removed.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_tab_del(U8 tab_index, U8 hilite)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < IMPS_MAX_NO_ROOM; i++)
    {
        mmi_imps_room_struct *room = &imps_p->room_info.room_list[i];

        if (room->is_used)
        {
            if (imps_p->room_info.room_list[i].tab_index > tab_index)
            {
                /* current tab is the tab to be hilite */
                if (imps_p->room_info.room_list[i].tab_index == hilite && hilite)
                {
                    hilite--;
                }
                imps_p->room_info.room_list[i].tab_index--;
            }
        }
    }
    imps_p->gen_info.no_tab--;
    imps_p->gen_info.curr_tab = hilite;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_tab_prev
 * DESCRIPTION
 *  Swap to previous tab
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_tab_prev(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imps_p->gen_info.no_tab == 1)
    {
        return;
    }

    if (imps_p->gen_info.curr_tab == 0)
    {
        imps_p->gen_info.curr_tab = imps_p->gen_info.no_tab - 1;
    }
    else
    {
        imps_p->gen_info.curr_tab--;
    }

    if (imps_p->gen_info.curr_tab == 0)
    {
        mmi_imps_pre_entry_cont();
    }
    else
    {
        mmi_imps_tab_jump_current();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_tab_next
 * DESCRIPTION
 *  Swap to next tab
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_tab_next(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imps_p->gen_info.no_tab == 1)
    {
        return;
    }

    if (imps_p->gen_info.curr_tab == (imps_p->gen_info.no_tab - 1))
    {
        imps_p->gen_info.curr_tab = 0;
    }
    else
    {
        imps_p->gen_info.curr_tab++;
    }

    if (imps_p->gen_info.curr_tab == 0)
    {
        mmi_imps_pre_entry_cont();
    }
    else
    {
        mmi_imps_tab_jump_current();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_tab_jump
 * DESCRIPTION
 *  Jump to tab by index
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_tab_jump(int index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imps_p->gen_info.no_tab == 1)
    {
        return;
    }

    if (index >= imps_p->gen_info.no_tab)
    {
        return;
    }

    imps_p->gen_info.curr_tab = index;

    if (imps_p->gen_info.curr_tab == 0)
    {
        mmi_imps_pre_entry_cont();
    }
    else
    {
        mmi_imps_tab_jump_current();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_tab_redraw
 * DESCRIPTION
 *  Redraw tab
 * PARAMETERS
 *  scr_id      [IN]        Current index of screen
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_tab_redraw(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (scr_id == SCR_ID_IMPS_CONT)
    {
        mmi_imps_tab_init();
        UpdateCategory425TabBar(NULL, (S8) imps_p->gen_info.no_tab, (S8) imps_p->gen_info.curr_tab, MMI_tab_bar_items);

        /* reset all blinking/unblinking status */
        mmi_imps_util_blink_tab();
    }
    else if (scr_id == SCR_ID_IMPS_CHAT)
    {
        mmi_imps_tab_init();
        UpdateCategory435TabBar(NULL, (S8) imps_p->gen_info.no_tab, (S8) imps_p->gen_info.curr_tab, MMI_tab_bar_items);
        /* reset all blinking/unblinking status */
        mmi_imps_util_blink_tab();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_tab_update_event
 * DESCRIPTION
 *  Update tab related screen when interrupt event comes
 * PARAMETERS
 *  room        [IN]        Room in which the event comes.
 *  entity      [IN]        Contact that related to the event
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_tab_update_event(mmi_imps_room_struct *room, imps_entity_struct *entity)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 active_scr = GetActiveScreenId();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* in multi-tab screen */
    if (active_scr == SCR_ID_IMPS_CHAT || active_scr == SCR_ID_IMPS_CONT)
    {
        if (imps_p->gen_info.curr_tab == room->tab_index && active_scr == SCR_ID_IMPS_CHAT)
        {
            /* flush data */
            UpdateCategory435LogText((U8*) room->chat_buff, mmi_ucs2strlen((S8*) room->chat_buff));
        }
        else
        {
            /* blink tab */
            Category425BlinkTab(room->tab_index);
            room->unread_msg = TRUE;
            mmi_imps_cont_update_when_msg_come(entity);
        }
    }
    else
    {
        /* update contact list for new message comes */
        room->unread_msg = TRUE;
        mmi_imps_cont_update_when_msg_come(entity);
    }

    mmi_imps_util_update_status_icon();
}

#define TONE_IMPS


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_util_play_tone
 * DESCRIPTION
 *  General function to play tone and vibration for incoming event.
 * PARAMETERS
 *  tone_type       [IN]        Type of message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_util_play_tone(U8 tone_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL is_in_imps = mmi_imps_util_is_in_imps();
    MMI_ALERT_TYPE alertType;
  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    alertType = GetMtCallAlertTypeEnum();    
    
     if (alertType == MMI_VIBRATION_AND_RING || 
        alertType == MMI_VIBRATION_THEN_RING || 
        alertType == MMI_RING)
    {
        if (!isInCall())                   
        {
        #ifdef __MMI_SUBLCD_MASTER_MODE__
            if (is_in_imps || g_idle_context.IsOnIdleScreen == TRUE || IsSubLCDInMasterMode())
        #else
            if (is_in_imps || g_idle_context.IsOnIdleScreen == TRUE)
        #endif            
            {
                if (tone_type == IMPS_MSG_TONE)
                {
                    mdi_audio_play_string(
                        (void*)g_imps_msg_tone,
                        sizeof(g_imps_msg_tone),
                        MDI_FORMAT_SMF,
                        DEVICE_AUDIO_PLAY_ONCE,
                        NULL,
                        NULL);
                }
                else
                {
                    mdi_audio_play_string(
                        (void*)g_imps_err_tone,
                        sizeof(g_imps_err_tone),
                        MDI_FORMAT_SMF,
                        DEVICE_AUDIO_PLAY_ONCE,
                        NULL,
                        NULL);
                }
            }
        }
        else
        {
            playRequestedTone(SMS_IN_CALL_TONE);
        }
    }
     
    if ((alertType == MMI_VIBRATION_ONLY) || (alertType == MMI_VIBRATION_AND_RING)
        || (alertType == MMI_VIBRATION_THEN_RING))
    {        
#ifdef __MMI_SUBLCD_MASTER_MODE__
            if (is_in_imps || g_idle_context.IsOnIdleScreen == TRUE || IsSubLCDInMasterMode())
#else
            if (is_in_imps || g_idle_context.IsOnIdleScreen == TRUE)
#endif  
            {
                PlayVibratorOnce();
            }    
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_util_find_room
 * DESCRIPTION
 *  Find out the location of chat room in the list buffer according to its room id
 * PARAMETERS
 *  room_id     [IN]        Id of the room
 * RETURNS
 *  index of chat room in the list buffer
 *****************************************************************************/
S32 mmi_imps_util_find_room(S8 *room_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < IMPS_MAX_NO_ROOM; i++)
        if (mmi_imps_util_stricmp((S8*) imps_p->room_info.room_list[i].room_id, room_id) == 0)
        {
            break;
        }
    return i;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_util_find_cont
 * DESCRIPTION
 *  Find out the location of chat room in the list buffer according to its room id
 * PARAMETERS
 *  cont_id     [?]     [?]     [?]     [?]
 *  room_id(?)      [IN]        Id of the room(?)(?)(?)
 * RETURNS
 *  index of chat room in the list buffer
 *****************************************************************************/
S32 mmi_imps_util_find_cont(S8 *cont_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* find contact */
    for (i = 0; i < imps_p->cont_info.no_cont; i++)
        if (mmi_imps_util_is_id_same((S8*) imps_p->cont_info.cont_list[i].id, (S8*) cont_id))
        {
            break;
        }

    return i;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_util_file_path
 * DESCRIPTION
 *  generate file path
 * PARAMETERS
 *  databuff     [?] 
 *  filepath     [IN]       
 * RETURNS
 *  
 *****************************************************************************/
void mmi_imps_util_file_path(S8 *ucs2_folder, S8 *prefix, U8 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    S8 temp1[8], temp2[16];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_util_get_work_path((S8*) ucs2_folder);
    sprintf(temp1, "_%d.dat" ,id);
    mmi_asc_to_ucs2((S8*) temp2, (S8*) temp1);
    mmi_ucs2cat((S8*) ucs2_folder, (S8*) prefix);
    mmi_ucs2cat((S8*) ucs2_folder, (S8*) temp2);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imps_util_get_entity_from_file
 * DESCRIPTION
 *  get entity from file
 * PARAMETERS
 *  databuff     [OUT] 
 *  filepath     [IN]       
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_imps_util_get_entity_from_file(imps_entity_list_struct *databuff, S8 *filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    FS_HANDLE fileHandle;
    imps_entity_struct *buff = (imps_entity_struct*) OslMalloc(sizeof(imps_entity_struct));
    U32 len;  
	U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (filepath == NULL)
    {
        MMI_ASSERT(0);
    }

    fileHandle = FS_Open((U16*) filepath, FS_READ_ONLY);

    if (fileHandle > 0)
    {
        for (i = 0; i < IMPS_MAX_ENTITY_NUMBER; i++)
        {
            result = FS_Read(fileHandle, (void*) buff, sizeof(imps_entity_struct), &len);
            if (result == FS_NO_ERROR && len > 0)
            {
                memcpy(&databuff->entity[i], buff, sizeof(imps_entity_struct));
                databuff->entity_count++;             
            }
            else
            {
                break;
            }
        }   
        FS_Close(fileHandle);   
    }
    
    OslMfree(buff);
    return fileHandle;    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_util_fs_error_handle
 * DESCRIPTION
 *  Handler of file operation
 * PARAMETERS
 *     
 * RETURNS
 *  
 *****************************************************************************/
void mmi_imps_util_fs_error_handle(S32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/     
    if (result != FS_NO_ERROR)
    {
        mmi_imps_util_disp_err_popup(GetFileSystemErrorString(result));
        GoBackToHistory(IDLE_SCREEN_ID);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_util_get_filename_from_fileindex
 * DESCRIPTION
 *  Get filename from file index
 * PARAMETERS
 *   
 * RETURNS
 *  
 *****************************************************************************/
void mmi_imps_util_get_filename_from_fileindex(U32 fileindex, U16 filetype, S8* filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 temp[40];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(temp, "%s%s%x.%c",imps_directory, IMPS_HTTP_REPLY_FOLDER, fileindex, filetype);
    mmi_asc_to_ucs2((S8*) filename, (S8*) temp);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_check_not_agreed_service
 * DESCRIPTION
 *  Check not agreed service by server
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_check_not_agreed_service(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    imps_service_tree_struct *service_tree = 
                (imps_service_tree_struct*) &imps_p->gen_info.not_agreed_serv.not_agreed_services;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* search not agreed */
    if (service_tree->fd_service & (IMPS_FD_SRCH|IMPS_FD_SEARCHFUNC) != (IMPS_FD_SRCH|IMPS_FD_SEARCHFUNC))
    {
        mmi_frm_hide_menu_item(MENU_ID_IMPS_SEARCH_DIRECT);
        mmi_frm_hide_menu_item(MENU_ID_IMPS_ROOM_OPT_SEARCH);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_IMPS_SEARCH_DIRECT);
        mmi_frm_unhide_menu_item(MENU_ID_IMPS_ROOM_OPT_SEARCH);
    }

    /* invite not agreed */
    if (service_tree->fd_service & (IMPS_FD_INVITEFUNC|IMPS_FD_INVIT|IMPS_FD_CAINV) 
        != (IMPS_FD_INVITEFUNC|IMPS_FD_INVIT|IMPS_FD_CAINV))
    {
        mmi_frm_hide_menu_item(MENU_ID_IMPS_CHAT_OPT_INVITE);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_IMPS_CHAT_OPT_INVITE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_util_startup_wap_browser_req
 * DESCRIPTION
 *  Get filename from file index
 * PARAMETERS
 *   
 * RETURNS
 *  
 *****************************************************************************/
void mmi_imps_util_startup_wap_browser_req(U8 type, void *URL)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    wap_browser_startup_req_struct *open_url_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);
    
    open_url_req = (wap_browser_startup_req_struct*) OslConstructDataPtr(sizeof(*open_url_req));
    open_url_req->type = type;
    memset(open_url_req->url, 0, sizeof(open_url_req->url));
    strncpy((S8*)open_url_req->url, (S8*) URL, (sizeof(open_url_req->url) - 1));

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_WAP;
    Message.oslMsgId = MSG_ID_WAP_BROWSER_STARTUP_REQ;
    Message.oslDataPtr = (void*) open_url_req;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);  
}

#define COMMON_IMPS


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_display_progressing
 * DESCRIPTION
 *  Common function to display "Progressing" screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_display_progressing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_pre_entry_progressing(
        STR_ID_IMPS,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        0,
        0,
        0,
        0,
        (U8*) GetString(STR_ID_IMPS_PROGRESSING),
        NULL,
        IMG_GLOBAL_PROGRESS,
        NULL,
        NULL,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_pre_entry_progressing
 * DESCRIPTION
 *  Pre-entry function for progressing screen
 * PARAMETERS
 *  strCaption      [IN]        
 *  imgCaption      [IN]        
 *  strLsk          [IN]        
 *  imgLsk          [IN]        
 *  strRsk          [IN]        
 *  imgRsk          [IN]        
 *  strBody1        [?]         [?]         [?]         [?]
 *  strBody2        [?]         [?]         [?]         [?]
 *  imgBody         [IN]        
 *  lskFuncPtr      [IN]        
 *  rskFuncPtr      [IN]        
 *  endFuncPtr      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_pre_entry_progressing(
        U16 strCaption,
        U16 imgCaption,
        U16 strLsk,
        U16 imgLsk,
        U16 strRsk,
        U16 imgRsk,
        U8 *strBody1,
        U8 *strBody2,
        U16 imgBody,
        FuncPtr lskFuncPtr,
        FuncPtr rskFuncPtr,
        FuncPtr endFuncPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_progress_scr_struct *progress_info = &imps_p->progress_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    progress_info->strCaption = strCaption;
    progress_info->imgCaption = imgCaption;
    progress_info->strLsk = strLsk;
    progress_info->imgLsk = imgLsk;
    progress_info->strRsk = strRsk;
    progress_info->imgRsk = imgRsk;
    progress_info->strBody1 = strBody1;
    progress_info->strBody2 = strBody2;
    progress_info->imgBody = imgBody;
    progress_info->lskFuncPtr = lskFuncPtr;
    progress_info->rskFuncPtr = rskFuncPtr;
    progress_info->endFuncPtr = endFuncPtr;

    mmi_imps_entry_progressing();

    /* prevent the progressing screen being entered twice */
    DeleteScreenIfPresent(SCR_ID_IMPS_PROGRESS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_progressing
 * DESCRIPTION
 *  Common entry function for all progressing screens.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_progressing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    mmi_imps_progress_scr_struct *progress_info = &imps_p->progress_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_IMPS_PROGRESS, NULL, mmi_imps_entry_progressing, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMPS_PROGRESS);

    ShowCategory154Screen(
        progress_info->strCaption,
        progress_info->imgCaption,
        progress_info->strLsk,
        progress_info->imgLsk,
        progress_info->strRsk,
        progress_info->imgRsk,
        (U8*) progress_info->strBody1,
        (U8*) progress_info->strBody2,
        progress_info->imgBody,
        guiBuffer);

    SetLeftSoftkeyFunction(progress_info->lskFuncPtr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(progress_info->rskFuncPtr, KEY_EVENT_UP);
    if (progress_info->endFuncPtr)
    {
        SetKeyHandler(progress_info->endFuncPtr, KEY_END, KEY_EVENT_DOWN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_abort
 * DESCRIPTION
 *  Common function to send abort request to PS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_pre_entry_progressing(
        STR_ID_IMPS,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        0,
        0,
        0,
        0,
        (U8*) GetString(STR_GLOBAL_ABORTING),
        NULL,
        IMG_GLOBAL_PROGRESS,
        NULL,
        NULL,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_confirm
 * DESCRIPTION
 *  Common function to display confirmation screem
 * PARAMETERS
 *  msg             [IN]        String index of message to be displayed in confirmation screen
 *  lskFuncPtr      [IN]        LSK handler of the confirmation screen
 *  rskFuncPtr      [IN]        RSK handler of the confirmation screen
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_confirm(U16 msg, FuncPtr lskFuncPtr, FuncPtr rskFuncPtr)
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
        (UI_string_type) GetString(msg),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(lskFuncPtr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(rskFuncPtr, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_comm_input_meth
 * DESCRIPTION
 *  Common highlight handler of Input Method option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_comm_input_meth(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryInputMethodScreen, KEY_EVENT_UP);
    SetKeyHandler(EntryInputMethodScreen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    RegisterInputMethodScreenCloseFunction(mmi_imps_util_go_back_2_hist);
}

#endif /* __MMI_IMPS__ */ /* #ifdef __MMI_IMPS__ */
#endif /* _MMI_IMPS_UTIL_C */ 

