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
 * ToDoListEnum.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file defines screen, string, and image id of to do list application.
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
/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/**************************************************************

   FILENAME : ToDoListEnum.h

   PURPOSE     : To Do List application

   REMARKS     : nil

   AUTHOR      : Arvind

   DATE     : 20th Oct,2003

**************************************************************/

#ifndef _PIXTEL_TODO_LIST_ENUM_H
#define _PIXTEL_TODO_LIST_ENUM_H

#include "MMI_features.h"
#ifdef __MMI_TODOLIST__

#include "StdC.h"
#include "MMIDataType.h"
#include "ToDoListResDef.h"

typedef enum mmi_tdl_error_enum
{
	MMI_TDL_EXPIRED_ALARM = 0,  /* Repeat is once and start time is overdue */
    MMI_TDL_SUCCESS,    
    MMI_TDL_INVALID_START_TIME,
    MMI_TDL_INVALID_END_TIME,
    MMI_TDL_INVALID_NOTES,  /* Notes is empty */    
    MMI_TDL_INVALID_ALARM,
    MMI_TDL_INVALID_REPEAT,
    MMI_TDL_REPEAT_OUT_OF_BOUNDARY,
    MMI_TDL_ERROR
} MMI_TDL_ERROR_ENUM;
#ifdef __SYNCML_SUPPORT__
typedef enum
{
    MMI_TDL_SYNCML_ERR_NO_ERROR = 0,
    MMI_TDL_SYNCML_ERR_EMPTY_NAME,
    MMI_TDL_SYNCML_ERR_DUPLICATE_NAME,
    MMI_TDL_SYNCML_ERR_MEMORY_FULL,
    MMI_TDL_SYNCML_ERR_INVALID_FILENAME,
    MMI_TDL_SYNCML_ERR_SELECT_PATH_TOO_LONG,
    MMI_TDL_SYNCML_ERR_UNSUPPORT_FORMAT,
    MMI_TDL_SYNCML_ERR_UNKNOWN,
    MMI_TDL_SYNCML_ERR_INVALID_INDEX,    
    MMI_TDL_SYNCML_ERR_DELETE_FAIL,	
    MMI_TDL_SYNCML_ERR_INVALID_OPERATION,
    MMI_TDL_SYNCML_ERR_TOTAL
} vclndr_syncml_error_enum;

typedef enum
{
    MMI_TDL_SYNCML_GET = 0,
    MMI_TDL_SYNCML_ADD,
    MMI_TDL_SYNCML_MODIFY,
    MMI_TDL_SYNCML_DELETE,
    MMI_TDL_SYNCML_TOTAL_OPERATIONS
}vclndr_syncml_operations_enum;
#endif /* __SYNCML_SUPPORT__ */
#endif /* __MMI_TODOLIST__ */
#endif /* _PIXTEL_TODO_LIST_ENUM_H */ 

