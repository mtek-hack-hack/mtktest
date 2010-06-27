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
 * PhoneBookHandlerJava.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for providing phonebook interface for java package
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _MMI_PHONEBOOKJAVAHANDLER_H
#define _MMI_PHONEBOOKJAVAHANDLER_H
#include "App_datetime.h"

/* if some header should be include before this one */
//#ifndef _PREINC_H
//#error "preinc.h should be included before header.h"
//#endif

/* 
 * Define
 */
#define MMI_PHB_JAVA_SEARCH_LENGTH ((MAX_PB_EMAIL_LENGTH+1)*ENCODING_LENGTH)

/* 
 * Typedef 
 */
typedef enum
{
    MMI_PHB_NO_SORT,
    MMI_PHB_BY_NAME,
    MMI_PHB_BY_EMAIL,
    MMI_PHB_BY_NUMBER
} mmi_phb_sort_type_enum;

typedef enum
{
    MMI_PHB_JAVA_ERROR,
    MMI_PHB_JAVA_SUCCESS,
    MMI_PHB_JAVA_NOT_READY,
    MMI_PHB_JAVA_NOT_SUPPORT,
    MMI_PHB_JAVA_NOT_FOUND,
    MMI_PHB_JAVA_STORAGE_FULL,
    MMI_PHB_JAVA_NUMBER_TOO_LONG,
    MMI_PHB_JAVA_FDN_ON,
    MMI_PHB_JAVA_OUT_OF_INDEX,
    MMI_PHB_JAVA_EMAIL_FULL,
    MMI_PHB_JAVA_ANR_FULL,
    MMI_PHB_JAVA_BIRTHDAY_ERROR,
    MMI_PHB_JAVA_NO_SIM_CARD
} mmi_phb_java_error_enum;

typedef struct
{
    U16  sort_index; /* sort index or the no. of group member */
    U16  store_index;
    S8 name[(MAX_PB_NAME_LENGTH + 1) *ENCODING_LENGTH];
    S8 number[(MAX_PB_NUMBER_LENGTH + 1 + 1) *ENCODING_LENGTH];
    S8 homeNumber[(MAX_PB_NUMBER_LENGTH + 1 + 1) *ENCODING_LENGTH];
    S8 officeNumber[(MAX_PB_NUMBER_LENGTH + 1 + 1) *ENCODING_LENGTH];
    S8 faxNumber[(MAX_PB_NUMBER_LENGTH + 1 + 1) *ENCODING_LENGTH];
    S8 emailAddress[(MAX_PB_EMAIL_LENGTH + 1) *ENCODING_LENGTH];
    S8 companyName[(MAX_PB_COMPANY_LENGTH + 1) *ENCODING_LENGTH];
    applib_time_struct bDay;
    U8 group_id;  /* 1-based. 0 is no group. 1~MAX_PB_CALLER_GROUPS in NVRAM; MAX_PB_CALLER_GROUPS~ in USIM. */
} mmi_phb_handler_entry_struct;


typedef struct 
{
    U8 group_name[(MAX_PB_NAME_LENGTH+1)*ENCODING_LENGTH];
    U8 group_id;
    U8 padding; /* reserved 2 bytes alignment*/
} mmi_phb_handler_group_struct;


/*
    Add:
       sort_type : sort by which type, the result will return in response msg
       index:      0xFFFF
       return ---  index : sort by sort_type, store_index: phsical index

    update:
       sort_type : sort type
       index:      store_index
       return ---  index/store_index: no use

    delete:
       sort_type  : sort type
       index:      store_index
       return ---  index/store_index: no use
*/

typedef struct
{
    LOCAL_PARA_HDR
//    U8 sort_type;
    U8 storage;
    U16 index; /* physical store_index (0~MAX_PB_ENTRIES-1) for update and delete command */
    mmi_phb_handler_entry_struct *entry_ptr; /* NULL for delete command */
} mmi_phb_handler_set_entry_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    U8 result;
//    U16 index;  /* sort index, not physical store index */
    U16 store_index; /* physical store index */
} mmi_phb_handler_set_entry_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    U8 sort_type;
    U8 storage;
    U8 group;
    U16 index; /* sort index */
    U16 count; /* if count is 0, return the total count */
    mmi_phb_handler_entry_struct *entry_ptr;
} mmi_phb_handler_get_entry_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U8 result;
    U16 count;
} mmi_phb_handler_get_entry_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    S8 pattern[MMI_PHB_JAVA_SEARCH_LENGTH];
    U8 sort_type;
    U8 storage;
    U8 search_type;
    U8 group;
    U16 start_index;  /* 0-based, 0 means the first sorted item, 1 means 2nd sorted item */
    mmi_phb_handler_entry_struct *entry_ptr;
} mmi_phb_handler_search_entry_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U8 result;
    U16 index; /* sort index if succeess */
} mmi_phb_handler_search_entry_rsp_struct;


typedef struct
{
    LOCAL_PARA_HDR
    U8 max_group;
    U8 storage;
    mmi_phb_handler_group_struct* group_ptr;
} mmi_phb_handler_get_group_info_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    U8 result;
    U8 count;
} mmi_phb_handler_get_group_info_rsp_struct;


typedef struct
{
    LOCAL_PARA_HDR
    U8 group_id; /* 0-based */
    mmi_phb_handler_group_struct* group_ptr;
} mmi_phb_handler_set_group_info_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    U8 result;
} mmi_phb_handler_set_group_info_rsp_struct;


/* 
 * Extern Global Variable
 */

/* 
 * Extern Global Function
 */
extern void mmi_phb_java_handler_init(void);
extern void mmi_phb_java_write_req(void *info);
extern void mmi_phb_java_write_rsp(U16 result, U16 store_index);
extern void mmi_phb_java_read_req(void *info);
extern void mmi_phb_java_read_rsp(U16 result, U16 count);
extern void mmi_phb_java_search_req(void *info);
extern void mmi_phb_java_search_rsp(U16 result, U16 store_index);
extern void mmi_phb_java_get_group_info_req(void *info);
extern void mmi_phb_java_get_group_info_rsp(U16 result, U16 count);
extern void mmi_phb_java_set_group_info_req(void *info);
extern void mmi_phb_java_set_group_info_rsp(U16 result);
extern void mmi_phb_java_util_get_record_index_by_id(
                U8 sort_type,
                U8 storage,
                U16 index,
                U16 *record_index,
                U8 *record_storage);
extern U16 mmi_phb_java_util_get_index_by_store_index(U8 sort_type, U8 storage, U16 in_store_index);
extern U16 mmi_phb_java_util_get_store_index_by_sort_index(U8 sort_type, U8 storage, U16 in_sort_index);
extern void mmi_phb_java_util_copy_entry_from_phb(U16 store_index, mmi_phb_handler_entry_struct *entry);
extern void mmi_phb_java_util_rebuild_email_sorting(void);
extern void mmi_phb_java_entry_processing_email(void);
extern void mmi_phb_java_exit_processing_email(void);
#ifdef __MMI_PHB_BIRTHDAY_FIELD__
extern void mmi_phb_java_set_bday(applib_time_struct* b_day, S8* pb_Year, S8* pb_Mon, S8* pb_Day);
extern void mmi_phb_java_get_bday(U16 store_index, applib_time_struct *b_day);
extern MMI_BOOL mmi_phb_java_check_bday_is_valid(applib_time_struct *t);
#else /* defined(__MMI_PHB_BIRTHDAY_FIELD__) */
extern void mmi_phb_java_util_clear_bday(applib_time_struct* b_day);
#endif /* defined(__MMI_PHB_BIRTHDAY_FIELD__) */
#endif /* _MMI_PHONEBOOKJAVAHANDLER_H */ 

