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
 *	ToDoListDB.h
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
 * 				HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef _MMI_PIMEVTDB_H
#define _MMI_PIMEVTDB_H
#ifdef __J2ME__
#include "j2me_custom_option.h"
#endif /*__J2ME__*/
#include "app_datetime.h"
#include "custom_mmi_default_value.h"   /* MYTIME */
#include "ToDoListDBStruct.h"
/* if some header should be include before this one */
//#ifndef _PREINC_H
//#error "preinc.h should be included before header.h"
//#endif

/*
** Define
*/
#define TDL_FOR_AT_MAX_FILE_PATH_LEN    50
/*
** Typedef
*/
#if defined(SUPPORT_JSR_75_PIM)
typedef enum MMI_EVTDB_ERROR_ENUM
{
		MMI_EVTDB_JAVA_TDL_EXPIRED_ALARM =0,   /* Repeat is once and start time is overdue*/
        MMI_EVTDB_JAVA_SUCCESS,
    	MMI_EVTDB_JAVA_NOT_SUPPORT,
    	MMI_EVTDB_JAVA_TDL_NOT_READY,
    	MMI_EVTDB_JAVA_NOT_FOUND,
    	MMI_EVTDB_JAVA_STORAGE_FULL,
    	MMI_EVTDB_JAVA_DELETE_FAIL,
    	MMI_EVTDB_JAVA_OUT_OF_INDEX,
    	MMI_EVTDB_JAVA_INVALID_HANDLE,
    	MMI_EVTDB_JAVA_INVALID_DATE,
    	MMI_EVTDB_JAVA_TDL_INVALID_START_TIME,
    	MMI_EVTDB_JAVA_TDL_INVALID_END_TIME,
    	MMI_EVTDB_JAVA_TDL_INVALID_NOTES,  		/* Notes is empty*/    	
		MMI_EVTDB_JAVA_TDL_INVALID_ALARM,
		MMI_EVTDB_JAVA_TDL_INVALID_REPEAT,
		MMI_EVTDB_JAVA_TDL_REPEAT_OUT_OF_BOUNDARY,
    	MMI_EVTDB_JAVA_ERROR

}mmi_evtdb_java_error_enum;

typedef enum
{
    MMI_EVTDB_NO_SORT,
    MMI_EVTDB_SORT_BY_TIME,
    MMI_EVTDB_SORT_MAX
}mmi_evtdb_sort_enum;
#endif /* SUPPORT_JSR_75_PIM */

typedef enum MMI_AT_ERROR_ENUM
{
    MMI_TDL_AT_ERROR_INVALID_FILE_PATH
}mmi_at_error_enum;

typedef enum
{
    MMI_TDL_AT_ADD,
    MMI_TDL_AT_UPDATE,
    MMI_TDL_AT_DELETE,
    MMI_TDL_AT_READ,
    MMI_TDL_AT_QUERY,
    MMI_TDL_AT_MAX
}mmi_tdl_at_command_mode_enum;

/*
** Extern Global Variable
*/

/*
** Extern Global Function
*/
#if defined(SUPPORT_JSR_75_PIM)
extern void mmi_tdl_evtdb_handler_init(void);
extern void mmi_tdl_pim_evtdb_wirte_req(void* info);
extern void mmi_tdl_pim_write_rsp(U16 result, U16 store_index);
extern void mmi_tdl_pim_evtdb_read_req(void* info);
extern void mmi_tdl_pim_read_rsp(U16 result, U16 count);
extern U16 mmi_tdl_pim_update_record(U16 index, mmi_evtdb_java_entry_struct* evtdbEntry);
extern U8 mmi_tdl_pim_get_tdl_field(U16 index, mmi_evtdb_java_entry_struct* entry);
extern S16 mmi_tdl_pim_get_handle(U16 index, U8 sort_type);
extern S16 mmi_tdl_pim_get_sorted_index(U16 handle, U8 sort_type);
#endif /* SUPPORT_JSR_75_PIM */
extern void mmi_tdl_at_handler_init(void);
extern void mmi_tdl_at_req_ind(void* info);
extern void mmi_tdl_at_res_req(U8 mode, BOOL result, U8 number, U8 *file_path);
extern U8 mmi_tdl_at_get_sorted_list(U8 *sorted_list);

#endif /*_MMI_PIMEVTDB_H*/



