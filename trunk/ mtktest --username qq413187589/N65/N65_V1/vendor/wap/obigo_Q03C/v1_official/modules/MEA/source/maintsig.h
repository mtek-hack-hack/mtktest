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

/*! \file maintsig.h
 *  \brief  Signals used in the internal state machines.
 */

#ifndef _MAINTSIG_H_
#define _MAINTSIG_H_

/*! \enum MeaStateMachine State machines for the MEA module */
typedef enum
{
    MEA_NOTUSED_FSM,/*!< N/A ! Must be the first one. */
    MEA_CONFIG_FSM, /*!< Configuration*/
    MEA_MH_FSM,     /*!< Message Handler*/
    MEA_MV_FSM,     /*!< Message Viewer*/
    MEA_MMV_FSM,    /*!< Multipart/mixed Viewer */
    MEA_MME_FSM,    /*!< Multipart/mixed editor */
    MEA_MOB_FSM,    /*!< Media object browser */
    MEA_SE_FSM,     /*!< SMIL Editor*/
    MEA_ME_FSM,     /*!< Message Editor */
    MEA_IN_FSM,     /*!< Incoming Notifications */
    MEA_ASYNC_FSM,  /*!< Asyncronous operations */
    MEA_MCR_FSM,    /*!< Message Creation and Retrieval FSM */
    MEA_CRH_FSM,    /*!< Content routing handling */
    MEA_COMM_FSM,   /*!< Communication handling */
    MEA_CORE_FSM,   /*!< Core */
    MEA_MR_FSM,     /*!< Message reader */
    MEA_PBH_FSM,    /*!< The phone book handler */
    MEA_CTH_FSM,    /*!< Cross triggering handler */
    MEA_PH_FSM,     /*!< Packet Handler */
    MEA_FSM_MAX_REGS            /* Number of State Machines. */
} MeaStateMachine;

#define MEA_SIGNAL_SENDTO(d, sig) \
    meaSignalSendTo((d), (sig), (unsigned long)0L, (unsigned long)0L, \
    (unsigned long)0L, NULL)

#define MEA_SIGNAL_SENDTO_I(d, sig, i) \
    meaSignalSendTo((d), (sig), i, (unsigned long)0L, (unsigned long)0L, NULL)

#define MEA_SIGNAL_SENDTO_IU(d, sig, i, u) \
    meaSignalSendTo((d), (sig), (i), (u), 0L, NULL)

#define MEA_SIGNAL_SENDTO_IUU(d, sig, i, u1, u2) \
    meaSignalSendTo((d), (sig), (i), (u1), (u2), NULL)

#define MEA_SIGNAL_SENDTO_IUP(d, sig, i, u, p) \
    meaSignalSendTo((d), (sig), (i), (u), (unsigned long)0L, (p))

#define MEA_SIGNAL_SENDTO_IUUP(d, sig, i, u1, u2, p) \
    meaSignalSendTo((d), (sig), (i), (u1), (u2), (p))

#define MEA_SIGNAL_SENDTO_IP(d, sig, i, p) \
    meaSignalSendTo((d), (sig), (i), (unsigned long)0L, (unsigned long)0L, \
        (p))

#define MEA_SIGNAL_SENDTO_U(d, sig, u) \
    meaSignalSendTo((d), (sig), (unsigned long)0L, (u), (unsigned long)0L, \
        NULL)

#define MEA_SIGNAL_SENDTO_UU(d, sig, u1, u2) \
    meaSignalSendTo((d), (sig), (unsigned long)0L, (u1), (u2), NULL)

#define MEA_SIGNAL_SENDTO_UUP(d, sig, u1, u2, p) \
    meaSignalSendTo((d), (sig), (unsigned long)0L, (u1), (u2), (p))

#define MEA_SIGNAL_SENDTO_UP(d, sig, u, p) \
    meaSignalSendTo((d), (sig), (unsigned long)0L, (u), 0L, (p))

#define MEA_SIGNAL_SENDTO_P(d, sig, p) \
    meaSignalSendTo((d), (sig), (unsigned long)0L, (unsigned long)0L, \
    (unsigned long)0L, (p))

/****************************************
 * Type definitions:
 ****************************************/
/*! \struct MeaSignal
 *  The signal data structure */
typedef struct MeaSignalStruct 
{
    struct MeaSignalStruct *next;       /*!< Next signal in the queue */
    MeaStateMachine         dst;        /*!< The destination FSM for this 
                                             signal */
    int                     type;       /*!< Which signal it is */
    long                    i_param;    /*!< Parameter */
    unsigned long           u_param1;   /*!< Parameter: Sometimes used for 
                                             'Sending FSM' */
    unsigned long           u_param2;   /*!< Parameter: Sometimes used for 
                                             'Expected Return Signal' */
    void                   *p_param;    /*!< Pointer to additional parameters*/
} MeaSignal;

/*
 * This kind of function is called when a signal is delivered.
 */
typedef void MeaSignalFunction (MeaSignal *);

/****************************************
 * Exported functions:
 ****************************************/

/*
 * Remove all signals with the specified id and data for a state machine
 */
void meaSignalFlush(MeaStateMachine dst, int id, long i_param,
    unsigned long u_param1, unsigned long u_param2, const void *p_param);

/*
 * Initialize the signal module.
 */
void meaSignalInit(void);

/*
 * Terminate the signal module.
 */
void meaSignalTerminate(void);

/*
 * Process the first signal in the signal queue.
 */
void meaSignalProcess(void);

/* Check if signal queue is empty
 *
 * Returns TRUE if the global signal queue is empty,
 *      FALSE otherwise.
 */
int meaSignalQueueIsEmpty(void);

/*
 * Delete a signal and its parameters.
 */
void meaSignalDelete(MeaSignal *sig);

/*
 * Remove the registered function for destination "dst".
 */
void meaSignalDeregister(MeaStateMachine dst);

/*
 * Register the function "f" to be called when a signal
 * is delivered to destination "dst".
 */
void meaSignalRegisterDst(MeaStateMachine dst, MeaSignalFunction *f);

/*
 * Add a new signal to the end of the global queue.
 */
MeaSignal *meaSignalSendTo(MeaStateMachine dst, int sig, long i_param,
    unsigned long u_param1, unsigned long u_param2, void *p_param);

/*
 * Add an old signal to the beginning of the queue.
 */
void meaSignalPrepend(MeaSignal *sig);

#endif


