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
 *   fs_kal.h
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

#ifndef _FS_KAL_H
#define _FS_KAL_H

#ifdef __cplusplus
extern "C" {
#endif

/*************************************************************************
 * Constant Definition
 *************************************************************************/
#define RTF_NO_WAIT		0	/* if obtain fail return immediately*/
#define RTF_INFINITE 	1  /* timeout value to wait forever */


/*************************************************************************
 * Function Declaration
 *************************************************************************/
	/* get current date and time and store it in *DOSFileDateTime */
	RTTDLL void           RTFAPI RTFSYSGetDateTime(RTFDOSDateTime * DOSFileDateTime);

	/* allocate a mutex and return a reference to it */
	RTTDLL RTFMutex *     RTFAPI RTFSYSAllocMutex(const char * Name);

	/* lock a mutex with given timeout in milliseconds. The return value must
	 * be RTF_NO_ERROR (mutex is locked) or RTF_TIMEOUT (failed) */
	RTTDLL int            RTFAPI RTFSYSLockMutex(RTFMutex * Mutex, UINT Timeout);

	/* release a locked mutex */
	RTTDLL void           RTFAPI RTFSYSFreeMutex(RTFMutex * Mutex);

	/* return 1 if the current task has looked the given mutex and 0 otherwise */
	RTTDLL int            RTFAPI RTFSYSOwnMutex(RTFMutex * Mutex);

	/* allocate a TLS (task local storage) index. At least 4 such indexes
	 * should be available to RTFiles. Device drivers may required even more. */
	RTTDLL int            RTFAPI RTFSYSAllocTLS(void);

	/* set TLS data of the current task */
	RTTDLL void           RTFAPI RTFSYSSetTLS(int Index, void * Value);

	/* retrieve TLS data of the current task */
	RTTDLL void *         RTFAPI RTFSYSGetTLS(int Index);

	/* display an error message and abort the program with the given error
	 * code. RTFiles calls this function on all fatal errors. */
	RTTDLL void           RTFAPI RTFSYSErrorExit(const char * Message, UINT ExitCode);

/*************************************************************************
 * External Function Declaration
 *************************************************************************/
        extern kal_taskid     kal_get_current_thread_ID(void);
#ifdef  __cplusplus
}
#endif

#endif /* _FS_KAL_H */


