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
 *   fs_kal.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file system service abstraction layer for file system 
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/**************************************************************************/
/*                                                                        */
/*  File: SYSW32.C                               Copyright (c) 1998,2002  */
/*  Version: 4.0                                 On Time Informatik GmbH  */
/*                                                                        */
/*                                                                        */
/*                                      On Time        /////////////----- */
/*                                    Informatik GmbH /////////////       */
/* --------------------------------------------------/////////////        */
/*                                  Real-Time and System Software         */
/*                                                                        */
/**************************************************************************/

/*************************************************************************
 * Included header files
 *************************************************************************/
#if defined(WIN32)
#include "windows.h" 
#endif

#include "kal_release.h"
#include "intrCtrl.h"
#include "rtfiles.h"
#include "fs_kal.h"
#include "rtc_sw.h"
#include "rtfex.h"

/*************************************************************************
 * Constant and Declaration
 *************************************************************************/
/*  TLS: Thread Local Storage */ 
#define MAX_TLS_INDEX 2
#define INI_SEM 1		
#define FS_TLS_DEFAULT 0
#define MAX_MUTEX          10

static RTFMutex   M[ MAX_MUTEX ];
static kal_uint32 NextMutex = 0;
extern _XData* gFS_TaskData[][MAX_TLS_INDEX];
//static _XData*    FS_TLS_g[ RTF_MAX_THREAD ][ MAX_TLS_INDEX ] = {0};
//static kal_taskid FS_TCT_g[ RTF_MAX_THREAD ] = {0};
static kal_int32  FS_TLS_Index = -1;
static kal_int8   FS_TCT_Index = 0;  

#ifndef WIN32
extern kal_bool INT_QueryExceptionStatus(void);
#endif

/*************************************************************************
* FUNCTION
*  stack_config
*
* DESCRIPTION
*  This function implements to get system date time
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void 
RTFAPI RTFSYSGetDateTime(RTFDOSDateTime * TimeDate)
{
	t_rtc rtc_time;

	/* XXX!!!. Can consider to align to rtc structure definition */
	RTC_GetTime(&rtc_time);

	TimeDate->Day = rtc_time.rtc_day;
	TimeDate->Hour = rtc_time.rtc_hour;
	TimeDate->Minute = rtc_time.rtc_min;
	TimeDate->Month = rtc_time.rtc_mon;
	/* Second only contain 5 bits , WCP_SW, MOD START */
	TimeDate->Second2 = rtc_time.rtc_sec >> 1; 
	/* Second only contain 5 bits , WCP_SW, MOD END */
	/* Adapt to windows is 1980 base while RTC is 2000 base, Karen Hsu, MOD START */
	TimeDate->Year1980 = rtc_time.rtc_year + 20;
	//TimeDate->Year1980 = rtc_time.rtc_year;
	/* Adapt to windows is 1980 base while RTC is 2000 base, Karen Hsu, MOD END */
}

/*************************************************************************
* FUNCTION
*  RTFSYSAllocMutex
*
* DESCRIPTION
*  This function implements to create filesystem mutex
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
RTFMutex* 
RTFAPI RTFSYSAllocMutex(const char * Name)
{
	if (NextMutex >= MAX_MUTEX)
		RTFSYSErrorExit("out of mutexes for RTFiles", 1);

	M[NextMutex].rtf_lock_count = 0;
	M[NextMutex].rtf_sem_owner = KAL_NILTASK_ID;
   /* Solve MMI hang for waiting lock, Karen Hsu, 2004/04/23, ADD START */
   M[NextMutex].DeviceNum_1 = 0;
   M[NextMutex].DeviceNum_2 = 0;
   /* Solve MMI hang for waiting lock, Karen Hsu, 2004/04/23, ADD END */		
	M[NextMutex++].rtf_sem = kal_create_sem((kal_char*)Name, INI_SEM);

	return &M[NextMutex-1];
}

/*************************************************************************
* FUNCTION
*  RTFSYSOwnMutex
*
* DESCRIPTION
*  This function implements to get filesystem mutex
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
int RTFAPI 
RTFSYSOwnMutex(RTFMutex * Mutex)
{
	kal_taskid current_task;

	current_task = kal_get_current_thread_ID();

	if (Mutex->rtf_sem_owner == current_task)
		return (int)(KAL_TRUE);
	else
		return (int)(KAL_FALSE);
}

/*************************************************************************
* FUNCTION
*  RTFSYSLockMutex
*
* DESCRIPTION
*  This function implements to take mutex during dedicated time period
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
int 
RTFAPI RTFSYSLockMutex(RTFMutex * Mutex, UINT Timeout)
{
	/* XXX!!!. Timeout lock is not support by Nucleus Plus =>wrong*/
	kal_taskid current_task;
	int ret_val = RTF_NO_ERROR;

#ifdef __P_PROPRIETARY_COPYRIGHT__
/* under construction !*/
/* under construction !*/
#endif

	current_task = kal_get_current_thread_ID();
	// task not ready
	if(current_task == KAL_NILTASK_ID)
		return RTF_NO_ERROR;
		
	if (Mutex->rtf_sem_owner == current_task) {
		Mutex->rtf_lock_count++;
		return (ret_val);
	}

	ret_val = ((kal_take_sem(Mutex->rtf_sem, (kal_wait_mode)Timeout) == KAL_SUCCESS) ? RTF_NO_ERROR : MT_LOCK_MUTEX_FAIL);
	if(ret_val != RTF_NO_ERROR)
		return ret_val; 
	/* Update owner and lock count */
	Mutex->rtf_sem_owner = current_task;
	Mutex->rtf_lock_count = 1;

	return (ret_val);
}

/*************************************************************************
* FUNCTION
*  RTFSYSFreeMutex
*
* DESCRIPTION
*  This function implements to release filesystem mutex
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void RTFAPI 
RTFSYSFreeMutex(RTFMutex * Mutex)
{
	kal_taskid current_task;
	
#ifdef __P_PROPRIETARY_COPYRIGHT__
/* under construction !*/
/* under construction !*/
#endif

	current_task = kal_get_current_thread_ID();
	// task not ready
	if(current_task == KAL_NILTASK_ID)
		return ;

#ifndef WIN32		
	if (INT_QueryExceptionStatus() == KAL_FALSE) /* Should only be possible for exception cases */		
 	  ASSERT(Mutex->rtf_sem_owner == current_task);
#else
 	ASSERT(Mutex->rtf_sem_owner == current_task);
#endif 

	Mutex->rtf_lock_count--;

	if (Mutex->rtf_lock_count == 0) {
		Mutex->rtf_sem_owner = KAL_NILTASK_ID;
      /* Solve MMI hang for waiting lock, Karen Hsu, 2004/04/23, ADD START */
      Mutex->DeviceNum_1 = 0;
      Mutex->DeviceNum_2 = 0;
      /* Solve MMI hang for waiting lock, Karen Hsu, 2004/04/23, ADD END */				
		kal_give_sem(Mutex->rtf_sem);
	}
}

/*************************************************************************
* FUNCTION
*  RTFSYSAllocTLS
*
* DESCRIPTION
*  This function implements to record filesystem internal task index
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
int RTFAPI 
RTFSYSAllocTLS(void)
{  
	ASSERT(FS_TLS_Index < MAX_TLS_INDEX);
	return(++FS_TLS_Index);
}

/*************************************************************************
* FUNCTION
*  stack_config
*
* DESCRIPTION
*  This function implements to config Protocol Stack's configuration
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void RTFAPI 
RTFSYSSetTLS(int Index, void * Value)
{
	kal_uint8 task_indx;
	kal_taskid current_task;

	ASSERT(Index <= FS_TLS_Index);

	current_task = kal_get_current_thread_ID();
	/* Find current task id is registered or not */
	for (task_indx=0; task_indx<FS_TCT_Index+1; task_indx++) {
		if (gFS_TaskList[task_indx] == current_task) break;
	}

	/* Not found */
	if (task_indx == FS_TCT_Index+1) {
		if (FS_TCT_Index >= FS_MAX_THREAD) {
			kal_fatal_error_handler("FS Alloc TLS over maximum",
											KAL_ERROR_FILESYS_INTERNAL_FAILED,
											KAL_ERROR_KAL_INTERNAL_FAIL);
			return;
		}

		/* Register current task id as new one */
		gFS_TaskList[FS_TCT_Index] = current_task;
		gFS_TaskData[FS_TCT_Index++][Index] = (_XData*)Value;
		return;
	}

	gFS_TaskData[ task_indx ][ Index ] = (_XData*)Value;

	return;
}

/*************************************************************************
* FUNCTION
*  stack_config
*
* DESCRIPTION
*  This function implements to config Protocol Stack's configuration
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void * RTFAPI 
RTFSYSGetTLS(int Index)
{
	kal_uint8 task_indx;
	kal_taskid current_task;

	ASSERT(Index < MAX_TLS_INDEX);

	current_task = kal_get_current_thread_ID();
	for (task_indx=0; task_indx<FS_TCT_Index+1; task_indx++) {
		if (gFS_TaskList[task_indx] == current_task) break;
	}

	//ASSERT(task_indx != FS_TCT_Index);
	if(task_indx == FS_TCT_Index+1)
		return (void*)FS_TLS_DEFAULT;

	return(void*)gFS_TaskData[ task_indx ][ Index ];
}

/*************************************************************************
* FUNCTION
*  RTFSYSErrorExit
*
* DESCRIPTION
*  This function implements to filesystem fatal error handler
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void RTFAPI 
RTFSYSErrorExit(const char * Message, UINT ExitCode)
{
	kal_fatal_error_handler((char*)Message,
									KAL_ERROR_FILESYS_INTERNAL_FAILED,
									ExitCode);
}

/*************************************************************************
* FUNCTION
*  _rtfLock
*
* DESCRIPTION
*  This function implements to set and lock 
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
#if defined(WIN32)
//#include<windows.h>
CRITICAL_SECTION CS;

BYTE 
_rtfLock(BYTE * Lock)
{
	kal_uint8 tmp;
	static kal_uint8 first = 0;	   
   
   if(!first)
   {
      InitializeCriticalSection(&CS);
      first = 1;
   }

   EnterCriticalSection(&CS);
   
	tmp = *Lock;
	*Lock = 1;

	LeaveCriticalSection(&CS);

	return tmp;
}
#else
BYTE 
_rtfLock(BYTE * Lock)
{
	kal_uint8 tmp;
	kal_uint32 savedmask;

	/* Critical Section */
	savedmask = SaveAndSetIRQMask();

	tmp = *Lock;
	*Lock = 1;

	RestoreIRQMask(savedmask);

	return tmp;
}
#endif


