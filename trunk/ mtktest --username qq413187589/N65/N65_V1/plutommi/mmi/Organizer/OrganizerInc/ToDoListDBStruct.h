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
 *	ToDoListDBStruct.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef _MMI_PIMEVTDBSTRUCT_H
#define _MMI_PIMEVTDBSTRUCT_H
#ifdef __J2ME__
#include "j2me_custom_option.h"
#if defined(SUPPORT_JSR_75_PIM)

#ifndef __APP_DATETIME_H__
#error "please include app_datetime.h first"
#endif


typedef struct
{
	kal_uint16					index;
	kal_uint16					handle;
	applib_time_struct			startTime;			// This variable use to store the date, day and Time of an task
	applib_time_struct			endTime;		// This variable stote the End time in Hours of an Task ( Duration )
	kal_uint8					note[MAX_TODO_LIST_NOTE];		// Note of an Task
	kal_uint8					alarm;				// Weather Alarm is On or Off
	kal_uint8			repeat;				// Repeat values of Alarm
	kal_uint8					days;				// Week days
    kal_uint8 Type;                         /* Type of task */
    kal_uint8 Priority;                     /* Priority of task */
    kal_uint8 Location[MAX_TODO_LIST_NOTE]; /* Location of an Task */
} mmi_evtdb_java_entry_struct;

/*
   Add:
      sort_type : sort by which type, the result will return in response msg
      index:      0xFFFF
      return ---  index : sort by sort_type, handle: phsical index

   update:
      sort_type : sort type
      index:      if sort type = MMI_EVTDB_NO_SORT, index = store_index
                  else , index = sort_index
      return ---  index/handle : no use

   delete:
      sort_type  : sort type
      index:      if sort type = MMI_EVTDB_NO_SORT, index = store_index
                  else , index = sort_index
      return ---  index/handle : no use
*/

typedef struct
{
   LOCAL_PARA_HDR
   kal_uint8  sort_type;  // add by eric, reference to mmi_evtdb_sort_enum
   kal_uint16 index;      // change by eric
   mmi_evtdb_java_entry_struct* entry_ptr;
} mmi_evtdb_java_set_entry_req_struct;

typedef struct
{
   LOCAL_PARA_HDR
   kal_uint8 result;
   kal_uint16 index;  // add by eric
   kal_uint16 handle;
} mmi_evtdb_java_set_entry_rsp_struct;


/*
    Get:
      sort_type : sort by which type
      index:      if sort type = MMI_EVTDB_NO_SORT, index = store_index
                  else , index = sort_index
      count:      1

    Get Total:
      count:      0

*/


typedef struct
{
   LOCAL_PARA_HDR
   kal_uint8  sort_type; // add by eric, reference to mmi_evtdb_sort_enum
   kal_uint16 index;
   kal_uint16 count;
   mmi_evtdb_java_entry_struct* entry_ptr;
} mmi_evtdb_java_get_entry_req_struct;

typedef struct
{
   LOCAL_PARA_HDR
   kal_uint8 result;
   kal_uint16 count;
} mmi_evtdb_java_get_entry_rsp_struct;
#endif /*SUPPORT_JSR_75_PIM*/
#endif /*ifdef __J2ME__*/
#endif //_MMI_PIMEVTDBSTRUCT_H
