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
 *
 * Filename:
 * ---------
 * customer_email_num.c
 *
 * Project:
 * --------
 *   MAUI Project
 *
 * Description:
 * ------------
 *   This file is used to define the E-mail maximum message number.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#include "kal_release.h"
#include "customer_ps_inc.h"

#ifdef __EMAIL__

#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"    /* local/peer struct */

#include "rtc_sw.h"
#include "email_mmi.h"
#include "email_export.h"

#if MMI_EMAIL_MAX_ACCTS > MMI_EMAIL_SYS_MAX_ACCTS    
#error MMI_EMAIL_MAX_ACCTS shall <= MMI_EMAIL_SYS_MAX_ACCTS (defined in email_mmi.h)
#endif

#ifdef __EMAIL_USE_ASM_ADM__
kal_uint32 g_email_mem_pool[(EMAIL_MEM_POOL_SIZE + 3) / 4]; /* the email pool array */
#endif /* __EMAIL_USE_ASM_ADM__ */

/* POP3-related global variables */
kal_uint32 pop3_msgid_list_g[EMAIL_MAX_MSG_NUM];            	      
kal_uint32 pop3_msgsize_list_g[EMAIL_MAX_MSG_NUM];     

/* Mailbox-related global variables */
kal_uint16               email_sort_list_g[EMAIL_MAX_MSG_NUM];
email_nv_mb_entry_struct email_nvmb_entry_g[EMAIL_MAX_MSG_NUM];
email_mb_entry_struct    email_mb_entry_g[EMAIL_MAX_MSG_NUM];

#ifndef __NO_IMAP__
imap_cache_list_struct   g_imap_cache_list[IMAP_CACHE_MAX_ENTRY_NUM_PER_MAILBOX]; /* cache entry list */
kal_uint16  g_imap_sort_list[IMAP_CACHE_MAX_ENTRY_NUM_PER_MAILBOX]; /* the array storing sorting result */
kal_uint32  g_imap_uid_list[IMAP_CACHE_MAX_ENTRY_NUM_PER_MAILBOX];

kal_uint16 email_get_imap_cache_cotent_max_num(void)
{
   return (IMAP_CACHE_MAX_CONTENT_NUM_PER_MAILBOX);
}

kal_uint16 email_get_imap_cache_entry_max_num(void)
{
   return (IMAP_CACHE_MAX_ENTRY_NUM_PER_MAILBOX);
}

kal_uint16 email_get_imap_cache_marked_max_num(void)
{
    return (IMAP_MAX_MARKED_UID_NUM);
}
#endif /* __NO_IMAP__ */

/* UID list which obtained by UIDL command */
kal_uint8 pop3_uid_list_g[EMAIL_MAX_MSG_NUM][POP3_UIDL_DIGEST_LEN];   

/* UID list which stored the email retrieved */
email_nv_uidl_entry_struct email_nvuidl_entry_g[EMAIL_UIDL_ENTRY_NUM];
kal_uint8 pop3_nv_uid_flag_g[EMAIL_UIDL_ENTRY_NUM];   

/*****************************************************************************
* FUNCTION
*  email_get_max_uidl_num 
* DESCRIPTION
*   This function is used to define the E-mail maximum UIDL number.
*
* PARAMETERS
*
* RETURNS
*  kal_uint16
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_uint16 email_get_max_uidl_num (void)
{
   return (EMAIL_UIDL_ENTRY_NUM);
}

/*****************************************************************************
* FUNCTION
*  email_get_max_num 
* DESCRIPTION
*   This function is used to define the 
*   E-mail maximum message box number.
*
* PARAMETERS
*
* RETURNS
*  kal_uint16
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_uint16 email_get_max_num (void)
{
   return (EMAIL_MAX_MSG_NUM);
}

/*****************************************************************************
* FUNCTION
*  email_get_max_msg_size 
* DESCRIPTION
*   This function is used to define the E-mail maximum message size.
*   NOTE that this number will be used to reserve file system space.
* 
* PARAMETERS
*
* RETURNS
*  kal_uint32
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_uint32 email_get_max_msg_size()
{
   return (kal_uint32)MMI_EMAIL_MAX_MSG_SIZE;
}

/*****************************************************************************
* FUNCTION
*  email_get_min_msg_size 
* DESCRIPTION
*   This function is used to define the E-mail minimum message size.
* 
* PARAMETERS
*
* RETURNS
*  kal_uint32
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_uint32 email_get_min_msg_size()
{
   return (kal_uint32)MMI_EMAIL_MIN_MSG_SIZE;
}

/*****************************************************************************
* FUNCTION
*  email_get_max_attach_size 
* DESCRIPTION
*   This function is used to define the E-mail maximum per attachment size.
* 
* PARAMETERS
*
* RETURNS
*  kal_uint32
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_uint32 email_get_max_attach_size()
{
   return (kal_uint32)MMI_EMAIL_MAX_ATTACH_SIZE;
}

/*****************************************************************************
* FUNCTION
*  email_get_total_max_attach_size 
* DESCRIPTION
*   This function is used to define 
*   the E-mail maximum total attachment size.
* 
* PARAMETERS
*
* RETURNS
*  kal_uint32
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_uint32 email_get_total_max_attach_size()
{
   return (kal_uint32)MMI_EMAIL_TOTAL_MAX_ATTACH_SIZE;
}

/*****************************************************************************
* FUNCTION
*  email_get_total_max_addr_size
* DESCRIPTION
*   This function is used to define 
*   the E-mail maximum total address size.
* 
* PARAMETERS
*
* RETURNS
*  kal_uint16
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_uint16 email_get_total_max_addr_size(void) 
{
    return (kal_uint16) MMI_EMAIL_MAX_LEN_ADDR_LIST;
}


/*****************************************************************************
* FUNCTION
*  email_get_total_max_acct_size
* DESCRIPTION
*   This function is used to define 
*   the E-mail maximum total account size.
* 
* PARAMETERS
*
* RETURNS
*  kal_uint8
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_uint8 email_get_total_max_acct_size(void) 
{
    return (kal_uint8) MMI_EMAIL_MAX_ACCTS;
}


/*****************************************************************************
* FUNCTION
*  email_get_default_acct_activated_index
* DESCRIPTION
*   This function is used to define default account activated index.
*
*   with activated index   : 1 <= x <= MMI_EMAIL_MAX_ACCTS
*   without activated index: MMI_EMAIL_MAX_ACCTS+1
*   
*   NOTE that if you want to have default activated account, 
*             the email address of this account cannot be empty !!
*
* PARAMETERS
*
* RETURNS
*  kal_uint8
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_uint8 email_get_default_acct_activated_index(void) 
{
    return (kal_uint8) MMI_EMAIL_MAX_ACCTS+1;
}


/* 
 * by default, we does not turn on the account default value to save the code size
 * if customer wants to this feature, could turn it on
 */
//#define EMAIL_USE_ALL_DEFAULT_ACCT_VALUES

/*****************************************************************************
* FUNCTION
*  email_get_default_acct_value
* DESCRIPTION
*   This function is used to return the default account value by given index.
*
*   no activated index: MMI_EMAIL_MAX_ACCTS+1
* 
* PARAMETERS
*   index         IN      index: start from 1
*   default_value OUT     used to return default value, NULL: no default value
* RETURNS
*  void
* GLOBALS AFFECTED
*   None
*****************************************************************************/
void email_get_default_acct_value(kal_uint8 index, mmi_acct_profile_struct const **default_value) 
{   
#ifdef EMAIL_USE_ALL_DEFAULT_ACCT_VALUES
    const static mmi_acct_profile_struct acct_default_value[MMI_EMAIL_MAX_ACCTS] =
    {
    	/* account 1 */    	
        {
            /* imap_pop3_info_struct */
            0, /* service_type ==> data account id */
            0, /* in_protocol  ==> POP3 (0) IMAP (1) */
            0, /* check_interval ==> Periodical check time of mails.(In minutes) */

            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, /* IMAP4 draft folder name */
            0, /* draft_name_len */

            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, /* IMAP4 sent folder name */
            0, /* sent_name_len */

            MMI_EMAIL_MAX_MSG_SIZE, /* max_download_size */

            KAL_FALSE, /* leave_copy_on_server */

            0, /* bit_flag */

            EMAIL_DOWNLOAD_ALL, /* download_option for pop3 */
            EMAIL_DOWNLOAD_ALL, /* download_option for imap4 */

            0, /* del_after_n_days */
            KAL_FALSE, /* del_server_mails */

            /* smtp_info_struct */
            0, /* charset_disp_name */
            0, /* disp_name_len */

            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, /* display_name (null terminated) */

            0, /* email_addr_len */

            /* email_address (null terminated) */
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

            0, /* reply_to_addr_len */

            /* reply_to_addr (null terminated) */
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

            /* signature_struct */
            KAL_FALSE, /* on_off */
            0, /* charset_text */
            0, /* signature_type */

            0, /* text_len */
            /* text (null terminated) */
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

            /* email_attach_struct */
            0, /* charset_attach */
            0, /* mime_type */
            0, /* mime_subtype */

            0, /* attach_path_len */
            /* attach_file_name (null terminated) */
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

            KAL_FALSE, /* smtp_auth */
            KAL_TRUE, /* smtp_auth_same */

            /* login_info_struct, used for SMTP auth */
            0, /* user_name_length */
            /* user_name (null terminated) */
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0,

            0, /* pass_word_length */
            /* pass_word (null terminated) */
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

            0, /* bit_flag */
            0, 0, 0, /* reserved */

            0, /* bit_flag */
            0, 0, 0, /* reserved */

            /* login_info_struct, used for incoming server */
            0, /* user_name_length */
            /* user_name (null terminated) */
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0,

            0, /* pass_word_length */
            /* pass_word (null terminated) */
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, /* bit_flag */
            0, 0, 0, /* reserved */

            /* server_address_struct, In coming server address */
            0, /* port_number */
            0, /* server_name_len */
            /* server_name (null terminated) */
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, /* bit_flag */
            0, 0, 0, /* reserved */

            /* server_address_struct, Out going server address */
            0, /* port_number */
            0, /* server_name_len */
            /* server_name (null terminated) */
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, /* bit_flag */
            0, 0, 0, /* reserved */

            0, /* acct_name_len */
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, /* acct_name (UCS2, NOT null terminated) */

            0, /* bit_flag */
            0 /* reserved */
        },
    	/* account 2 */
        {
            /* imap_pop3_info_struct */
            0, /* service_type ==> data account id */
            0, /* in_protocol  ==> POP3 (0) IMAP (1) */
            0, /* check_interval ==> Periodical check time of mails.(In minutes) */

            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, /* IMAP4 draft folder name */
            0, /* draft_name_len */

            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, /* IMAP4 sent folder name */
            0, /* sent_name_len */

            MMI_EMAIL_MAX_MSG_SIZE, /* max_download_size */

            KAL_FALSE, /* leave_copy_on_server */

            0, /* bit_flag */

            EMAIL_DOWNLOAD_ALL, /* download_option for pop3 */
            EMAIL_DOWNLOAD_ALL, /* download_option for imap4 */

            0, /* del_after_n_days */
            KAL_FALSE, /* del_server_mails */

            /* smtp_info_struct */
            0, /* charset_disp_name */
            0, /* disp_name_len */

            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, /* display_name (null terminated) */

            0, /* email_addr_len */

            /* email_address (null terminated) */
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

            0, /* reply_to_addr_len */

            /* reply_to_addr (null terminated) */
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    
            /* signature_struct */
            KAL_FALSE, /* on_off */
            0, /* charset_text */
            0, /* signature_type */

            0, /* text_len */
            /* text (null terminated) */
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

            /* email_attach_struct */
            0, /* charset_attach */
            0, /* mime_type */
            0, /* mime_subtype */

            0, /* attach_path_len */
            /* attach_file_name (null terminated) */
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

            KAL_FALSE, /* smtp_auth */
            KAL_TRUE, /* smtp_auth_same */

            /* login_info_struct, used for SMTP auth */
            0, /* user_name_length */
            /* user_name (null terminated) */
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0,

            0, /* pass_word_length */
            /* pass_word (null terminated) */
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

            0, /* bit_flag */
            0, 0, 0, /* reserved */

            0, /* bit_flag */
            0, 0, 0, /* reserved */

            /* login_info_struct, used for incoming server */
            0, /* user_name_length */
            /* user_name (null terminated) */
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0,

            0, /* pass_word_length */
            /* pass_word (null terminated) */
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, /* bit_flag */
            0, 0, 0, /* reserved */

            /* server_address_struct, In coming server address */
            0, /* port_number */
            0, /* server_name_len */
            /* server_name (null terminated) */
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, /* bit_flag */
            0, 0, 0, /* reserved */

            /* server_address_struct, Out going server address */
            0, /* port_number */
            0, /* server_name_len */
            /* server_name (null terminated) */
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, /* bit_flag */
            0, 0, 0, /* reserved */

            0, /* acct_name_len */
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, /* acct_name (UCS2, NOT null terminated) */

            0, /* bit_flag */
            0 /* reserved */
        },
    	/* account 3 */
        {
            /* imap_pop3_info_struct */
            0, /* service_type ==> data account id */
            0, /* in_protocol  ==> POP3 (0) IMAP (1) */
            0, /* check_interval ==> Periodical check time of mails.(In minutes) */

            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, /* IMAP4 draft folder name */
            0, /* draft_name_len */

            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, /* IMAP4 sent folder name */
            0, /* sent_name_len */

            MMI_EMAIL_MAX_MSG_SIZE, /* max_download_size */

            KAL_FALSE, /* leave_copy_on_server */

            0, /* bit_flag */

            EMAIL_DOWNLOAD_ALL, /* download_option for pop3 */
            EMAIL_DOWNLOAD_ALL, /* download_option for imap4 */

            0, /* del_after_n_days */
            KAL_FALSE, /* del_server_mails */

            /* smtp_info_struct */
            0, /* charset_disp_name */
            0, /* disp_name_len */

            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, /* display_name (null terminated) */

            0, /* email_addr_len */

            /* email_address (null terminated) */
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

            0, /* reply_to_addr_len */

            /* reply_to_addr (null terminated) */
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

            /* signature_struct */
            KAL_FALSE, /* on_off */
            0, /* charset_text */
            0, /* signature_type */

            0, /* text_len */
            /* text (null terminated) */
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

            /* email_attach_struct */
            0, /* charset_attach */
            0, /* mime_type */
            0, /* mime_subtype */

            0, /* attach_path_len */
            /* attach_file_name (null terminated) */
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

            KAL_FALSE, /* smtp_auth */
            KAL_TRUE, /* smtp_auth_same */

            /* login_info_struct, used for SMTP auth */
            0, /* user_name_length */
            /* user_name (null terminated) */
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0,

            0, /* pass_word_length */
            /* pass_word (null terminated) */
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

            0, /* bit_flag */
            0, 0, 0, /* reserved */

            0, /* bit_flag */
            0, 0, 0, /* reserved */

            /* login_info_struct, used for incoming server */
            0, /* user_name_length */
            /* user_name (null terminated) */
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0,

            0, /* pass_word_length */
            /* pass_word (null terminated) */
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, /* bit_flag */
            0, 0, 0, /* reserved */

            /* server_address_struct, In coming server address */
            0, /* port_number */
            0, /* server_name_len */
            /* server_name (null terminated) */
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, /* bit_flag */
            0, 0, 0, /* reserved */

            /* server_address_struct, Out going server address */
            0, /* port_number */
            0, /* server_name_len */
            /* server_name (null terminated) */
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, /* bit_flag */
            0, 0, 0, /* reserved */

            0, /* acct_name_len */
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, /* acct_name (UCS2, NOT null terminated) */

            0, /* bit_flag */
            0 /* reserved */
        }
    };
#endif /* EMAIL_USE_ALL_DEFAULT_ACCT_VALUES */

    if (default_value)
    {
        *default_value = NULL;
    }

    if (!default_value || index == 0 || index > MMI_EMAIL_MAX_ACCTS)
    {
        return;
    }


#ifdef EMAIL_USE_ALL_DEFAULT_ACCT_VALUES

    /* 
     * here is just the code for your reference
     * you can assign the default account value for each profile or particular profile
     */
    *default_value = &acct_default_value[index - 1];

#endif /* EMAIL_USE_ALL_DEFAULT_ACCT_VALUES */

}


#ifdef __EMAIL_USE_ASM_ADM__
/*****************************************************************************
* FUNCTION
*  email_get_mem_pool
* DESCRIPTION
*   This function is used to get the address and size 
*   of the email memory pool.
* 
* PARAMETERS
*   mem_addr      OUT     address of memory pool
*   size          OUT     size of memory pool
* RETURNS
*  kal_bool
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_bool email_get_mem_pool(void **mem_addr, kal_uint32 *size)
{
    if (mem_addr == NULL || size == NULL)
    {
        return KAL_FALSE;
    }

    *mem_addr = (void*)g_email_mem_pool;
    *size = sizeof(g_email_mem_pool);
    return KAL_TRUE;
}
#endif /* __EMAIL_USE_ASM_ADM__ */

#endif /* __EMAIL__ */


