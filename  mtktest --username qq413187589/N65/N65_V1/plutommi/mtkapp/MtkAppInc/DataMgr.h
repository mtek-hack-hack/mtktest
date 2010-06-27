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
*  DataMgr.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   A generic mechanism for data store/retrieve to/from file
*
* Author:
* -------
*  Tim Chen
*
*==============================================================================
*           HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * $Log$
 *
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/
#ifndef _MMI_DATA_MGR_H_
#define _MMI_DATA_MGR_H_

/* Notice - Include "FileSystemDef.h" and "FileMgr.h" before this file */

/* To use the following functions, you must #define __MMI_DATA_STORE__ */
#define MAX_RECORD_NUM 2048
#define MAX_RECORD_BITSET_SIZE (MAX_RECORD_NUM/8)
#define MAX_RECORD_SIZE 1024
#define DB_FS_SEEK_FAIL 1
#define DB_OUT_OF_LIMIT 2
#define DB_RECORD_NOT_FOUND 3

typedef struct
{
    UI_character_type db_file[FMGR_MAX_PATH_LEN + 1];
    U16 record_num;
    U16 record_size;
    U16 max_record_num;
    BOOL is_active;
    U8 bitset[MAX_RECORD_BITSET_SIZE];
    U8 buff[MAX_RECORD_SIZE + 1];
} mmi_data_record_store_type;

extern S32 mmi_data_init_record_store(mmi_data_record_store_type *context, S8 *db_file, S32 record_size);
extern S32 mmi_data_add_record(mmi_data_record_store_type *context, U16 *record_id, void *data);
extern S32 mmi_data_get_record(mmi_data_record_store_type *context, U16 record_id, void *data);
extern S32 mmi_data_set_record(mmi_data_record_store_type *context, U16 record_id, void *data, BOOL always_add);
extern S32 mmi_data_delete_record(mmi_data_record_store_type *context, U16 record_id);
extern S32 mmi_data_check_record(mmi_data_record_store_type *context, U16 record_id, BOOL check_db_file);      /* return 0 means it's found! */
extern S32 mmi_data_check_space_for_set_record(mmi_data_record_store_type *context, U16 record_id);
extern S32 mmi_data_check_space_for_add_record(mmi_data_record_store_type *context);
#endif /* _MMI_DATA_MGR_H_ */ 

