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
 * app_usedetails.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains address parse function.
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
#ifndef _APP_USEDETAILS_H
#define _APP_USEDETAILS_H


/***************************************************************************** 
* Define
*****************************************************************************/
#define APPLIB_MIN_PHONE_NUM_LEN    3
#define APPLIB_MAX_PHONE_NUM_LEN    41

/***************************************************************************** 
* Typedef 
*****************************************************************************/
typedef enum 
{
    APPLIB_ADDR_TYPE_EMAIL = 0x1,
    APPLIB_ADDR_TYPE_URL = 0x2,
    APPLIB_ADDR_TYPE_PHONENUMBER = 0x4
}applib_addr_type_enum;

typedef enum 
{
    APPLIB_INPUT_DATA_TYPE_ASCII = 0x1,
    APPLIB_INPUT_DATA_TYPE_UTF8,
    APPLIB_INPUT_DATA_TYPE_UNICODE
}applib_charset_enum;

typedef struct applib_address_node_st
{
    char *data;
    char *data2;  /* Not null for APPLIB_ADDR_TYPE_PHONENUMBER. Same as *data but without written-seq, ex. '(', ')', '-'*/
    kal_int32 dataType; /*APPLIB_ADDR_TYPE_EMAIL, APPLIB_ADDR_TYPE_URL and APPLIB_ADDR_TYPE_PHONENUMBER*/ 
    kal_uint32 pos;
    kal_uint32 length;    /*Count by byte not character*/
    struct applib_address_node_st *next;
}applib_address_node_struct;

typedef void *(*applib_mem_alloc_fn) (kal_uint32);
typedef void (*applib_mem_free_fn) (void *);
typedef kal_bool (*applib_check_stop_fn) (applib_addr_type_enum, applib_address_node_struct *, kal_uint32);

/***************************************************************************** 
             
* Extern Global 
Variable                                                                    
*****************************************************************************/
/***************************************************************************** 
             
* Extern Global 
Function                                                                    
*****************************************************************************/
kal_bool applib_is_valid_email_address(const char *str);
kal_bool applib_is_valid_email_address_unicode(const kal_wchar *str);
kal_uint8 applib_ss_string_parsing(kal_uint8 *string_ptr, kal_uint8 length);

kal_bool applib_is_valid_email_local_part_unicode(const kal_wchar *str, int cnt);
kal_bool applib_is_valid_email_local_part(const char *str, int cnt);
kal_bool applib_is_valid_email_domain_name(const char *str);
kal_bool applib_is_valid_email_domain_name_unicode(const kal_wchar *str);

applib_address_node_struct *applib_get_address_list_from_text_ext(applib_addr_type_enum addr_type,
	applib_mem_alloc_fn mem_alloc_fn, applib_mem_free_fn mem_free_fn, applib_check_stop_fn check_stop_fn,
	applib_charset_enum input_data_type, char *input_data, kal_int32 dataLen, kal_bool *is_stopped);
applib_address_node_struct *applib_get_address_list_from_text(applib_addr_type_enum addr_type,
    applib_mem_alloc_fn mem_alloc_fn, applib_mem_free_fn mem_free_fn, char *input_data, kal_int32 dataLen);
kal_bool applib_free_address_list(applib_address_node_struct **addr_list, applib_mem_free_fn mem_free_fn);
applib_address_node_struct *applib_concatenate_address_list(applib_address_node_struct *list1, 
                                                            applib_address_node_struct *list2);
void applib_remove_duplicate_address(applib_address_node_struct **addr_list, applib_mem_free_fn mem_free_fn);
void applib_remove_duplicate_unicode_address(applib_address_node_struct **addr_list, applib_mem_free_fn mem_free_fn);
#endif /* _APP_USEDETAILS_H */ 

