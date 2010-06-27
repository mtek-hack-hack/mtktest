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
 * Copyright (C) Teleca Mobile Technologies AB, 2002-2004.
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
 */

/*! \file macore.h
 *  Core functions for MEA.
 */

#ifndef _MACORE_H_
#define _MACORE_H_

#ifndef _MAINTSIG_H_
#error You must include maintsig.h before macore.h!
#endif

/******************************************************************************
 * Constants
 *****************************************************************************/

/*! \enum MeaCoreSignalId
 *  Signals for the CORE FSM */
typedef enum 
{
    /*! Terminates the MEA application by calling the MEA_TERMINATE macro
     */
    MEA_SIG_CORE_TERMINATE_APP,

    /*! The SMA module is activated
     * u_param1 = module id
     */
    MEA_SIG_CORE_MODULE_ACTIVE,

    /*! A module is deactivated
     * u_param1 = module id
     */
    MEA_SIG_CORE_MODULE_TERMINATED,

    /*! The SMA module is started.
     *
     */
    MEA_SIG_CORE_SMA_STARTED_PLY,

    /*! The SMA has stopped playing.
     * u_param = the result, see #SmaResult
     */
    MEA_SIG_CORE_SMA_STOP

    /*!UM: We don't have normal termination(MEA_SIG_CORE_TERMINATE_APP)
     * Terminates the MEA application by calling the MEA_TERMINATE macro
     * Sometimes using MEA_TERMINATE directly causes memory leak
     */
    ,MEA_SIG_CORE_ABNORMAL_TERMINATE_APP
}MeaCoreSignalId;

/*! \enum MeaStartupMode
 *  \brief The startup modes for MEA. 
 *  MEA can be started in two different ways - context started from another 
 *  application as a "functionality extension" for that application, or by 
 * itself from a program manager 
 */
typedef enum
{
    MEA_STARTUP_MODE_DEFAULT,  /*!< Default start-up */
    MEA_STARTUP_MODE_MENU,     /*!< The MEA is started in menu mode */
    MEA_STARTUP_MODE_NEW,      /*!< Content is attached to the start-up of the
                                     MEA */
    MEA_STARTUP_MODE_NEW_TEMPLATE, /*!< Create a new template  */
    MEA_STARTUP_MODE_EDIT,     /*!< Edit a Send.req message */
    MEA_STARTUP_MODE_REPLY,    /*!< Replay to a message */  
    MEA_STARTUP_MODE_REPLY_ALL,/*!< Replay to a message */  
    MEA_STARTUP_MODE_FORWARD,  /*!< Forward a message */ 
    MEA_STARTUP_MODE_DELETE,   /*!< Delete a message */
    MEA_STARTUP_MODE_VIEW,     /*!< View a message */
    MEA_STARTUP_MODE_SCHEME,   /*!< A MMSTO:, MMS: or MAILTO: scheme is 
                                    attached to the start-up of the MEA */
    MEA_STARTUP_MODE_CONFIG,   /*!< Configuration */
    MEA_STARTUP_MODE_SEND,     /*!< Send a message  */
    MEA_STARTUP_MODE_DOWNLOAD, /*!< Download a message  */
    MEA_STARTUP_MODE_PROVISIONING,/*!< Wait for provisioning */
    MEA_STARTUP_MODE_NONE      /*!< The MEA has not been started */
}MeaStartupMode;

/*! Close down with, but show a dialog first */
#define MEA_PANIC_IMPLICIT          0x01
/*! Close down without any dialog */
#define MEA_PANIC_EXPLICIT          0x02
/*! Define for telling MEA to shut down */
#define MEA_PANIC                   0x01

/*! Terminate the MEA */
#define MEA_TERMINATE               meaPanic(FALSE)

extern jmp_buf meaJmpBuf;
extern int meaPanicMode;

/******************************************************************************
 * Data-types
 *****************************************************************************/

/******************************************************************************
 * Prototypes 
 *****************************************************************************/

void meaInit(MSF_BOOL internalOnly);
void meaTerminate(MSF_BOOL internalOnly);

void meaCoreInit(MSF_BOOL internalOnly);
void meaCoreTerminate(MSF_BOOL internalOnly);

MSF_BOOL meaIsExceptionAllowed(void);
void meaAllowException(MSF_BOOL state);

MSF_BOOL meaIsInsideRun(void);
void meaSetInsideRun(MSF_BOOL state);

void meaModuleStart(MSF_UINT32 modId, MSF_BOOL useCallback, 
    MeaStateMachine fsm, unsigned int signal);
void meaModuleStarted(MSF_UINT32 modId);
void meaModuleStop(MSF_UINT32 modId, MSF_BOOL terminateApp);
MSF_BOOL meaIsModuleStarted(MSF_UINT32 modId);
void meaModuleStopped(MSF_UINT32 modId);

void meaSetStartupParameters(const msf_module_execute_cmd_t *command);
MeaStartupMode meaGetStartupMode(void);

void meaSetStartupFsm(MeaStateMachine stateM);
MeaStateMachine meaGetStartupFsm(void);

void meaPanic(int showDialog);
void meaHandleMmsErrors(int result);

void meaActivateStartupFsm(void);
void meaPlaySmil(MmsMsgId msgId, MmsFileType fileType, MeaStateMachine fsm, 
    unsigned int sig);
#endif


