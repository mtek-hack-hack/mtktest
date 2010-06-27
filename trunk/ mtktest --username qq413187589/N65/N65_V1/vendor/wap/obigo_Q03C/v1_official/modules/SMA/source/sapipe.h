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
/*
 * Copyright (C) Teleca Mobile Technologies AB, 2002-2003.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Teleca Mobile Technologies AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Teleca Mobile Technologies AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 ******************************************************************************
 *
 * File:            $Workfile:   sapipe.h  $
 *
 * Date:            $Date:   May 17 2005 03:06:22  $
 *
 * Revision:        $Revision:   1.5  $
 *
 * Description:     Handling of pipes 
 *
 *****************************************************************************/

/*! \file sapip.h
 *  \brief Pipe handling
 */

#ifndef _SAPIPE_H_
#define _SAPIPE_H_

/******************************************************************************
 * Constants
 *****************************************************************************/
/*! The pipe-name */
#define SMA_PIPE_NAME "sma_pipe"
 /******************************************************************************
 * Types
 *****************************************************************************/
/*! \enum EmaMmnuSignalId Signals used with the Message List FSM */
typedef enum
{
	/*! "Read from file" operation is complete
     *  - Param I : -
     *  - Param U1: -
     *  - Param U2: - 
     *  - Param P : Bytes read
     */
	SMA_SIG_PIPE_FILE_READ_RSP,
	/*! State for writing to pipe
     *  - Param I : -
     *  - Param U1: -
     *  - Param U2: - 
     *  - Param P : -
     */
	SMA_SIG_PIPE_WRITE_PIPE,
	/*! "Copy from file to pipe" operation is complete
     *  - Param I : result of the operation TRUE on success else FALSE
     *  - Param U1: -
     *  - Param U2: - 
     *  - Param P : -
     */
	SMA_FSM_PIPE_COPY_COMPLETE,
	/*! Pipe notification arrived
     *  - Param I : -
     *  - Param U1: -
     *  - Param U2: handle 
     *  - Param P : eventType
     */
	SMA_SIG_PIPE_NOTIFY
} SmaPipeSignalId;

/******************************************************************************
 * Data-structures
 *****************************************************************************/

/******************************************************************************
 * Prototypes
 *****************************************************************************/
void smaPipeInit(void);
void smaPipeTerminate(void);
MSF_BOOL smaCreatePipeOperation(const char *pipeName);
void smaClosePipeOperation(void);
void smaCopyFileToPipe(const char *fileName, MSF_UINT32 offset, MSF_UINT32 size, 
	MSF_BOOL sendResult, SmaStateMachine retFsm, MSF_UINT32 retSig);
#endif /* _SAPIPE_H_ */


