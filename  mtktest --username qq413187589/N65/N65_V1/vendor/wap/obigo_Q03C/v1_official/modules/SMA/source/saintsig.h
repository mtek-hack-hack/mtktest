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
 */

#ifndef _SAINTSIG_H
#define _SAINTSIG_H

/*--- Definitions/Declarations ---*/

/*--- Types ---*/

/*********************************************
 * Signal destinations.
 * The constants here are chosen to allow
 * each destination a large enough interval
 * in which to define its signal values.
 *********************************************/


typedef enum
{
    SMA_FSM_MAIN,       /* FSM used for message handling */
    SMA_FSM_ASYNC,      /* FSM used for async operations */
    SMA_FSM_SBP,        /* FSM used to save bodypart to file */
    SMA_FSM_SLIDE,      /* FSM used to generate a slide */	
	SMA_FSM_PIPE,		/* FSM for handling pipe operations */	
    SMA_FSM_ATTACHMENT,	/* FSM for handling attachment operations */	
    SMA_FSM_MAX_REGS	/* Number of State Machines */	
} SmaStateMachine;


/**************************************************
 * Macros
 **************************************************/

#define SMA_SIGNAL_SENDTO(d, sig) \
  smaSignalSendTo ((d), (sig), 0, 0, 0, NULL)

#define SMA_SIGNAL_SENDTO_I(d, sig, i) \
  smaSignalSendTo ((d), (sig), i, 0, 0, NULL)

#define SMA_SIGNAL_SENDTO_U(d, sig, u) \
  smaSignalSendTo ((d), (sig), 0, (u), 0, NULL)

#define SMA_SIGNAL_SENDTO_IU(d, sig, i, u) \
  smaSignalSendTo ((d), (sig), (i), (u), 0, NULL)

#define SMA_SIGNAL_SENDTO_UU(d, sig, u1, u2) \
  smaSignalSendTo ((d), (sig), 0, (u1), (u2), NULL)

#define SMA_SIGNAL_SENDTO_IUU(d, sig, i, u1, u2) \
  smaSignalSendTo ((d), (sig), (i), (u1), (u2), NULL)

#define SMA_SIGNAL_SENDTO_P(d, sig, p) \
  smaSignalSendTo ((d), (sig), 0, 0, 0, (p))

#define SMA_SIGNAL_SENDTO_IP(d, sig, i, p) \
  smaSignalSendTo ((d), (sig), (i), 0, 0, (p))

#define SMA_SIGNAL_SENDTO_UP(d, sig, u, p) \
  smaSignalSendTo ((d), (sig), 0, (u), 0, (p))

#define SMA_SIGNAL_SENDTO_IUP(d, sig, i, u, p) \
  smaSignalSendTo ((d), (sig), (i), (u), 0, (p))

#define SMA_SIGNAL_SENDTO_UUP(d, sig, u1, u2, p) \
  smaSignalSendTo ((d), (sig), 0, (u1), (u2), (p))

#define SMA_SIGNAL_SENDTO_IUUP(d, sig, i, u1, u2, p) \
  smaSignalSendTo ((d), (sig), (i), (u1), (u2), (p))



/****************************************
 * Type definitions:
 ****************************************/

typedef struct SmaSignalStruct {
  struct SmaSignalStruct *next;
  int                    dst;      /* The destination for this signal */
  int                    type;     /* Which signal it is */
  long int               i_param;  /* Parameters: */
  unsigned long int      u_param1;
  unsigned long int      u_param2;
  void                  *p_param;
} SmaSignal;

/*
 * This kind of function is called when a signal is delivered.
 */
typedef void SmaSignalFunction (SmaSignal *);


/****************************************
 * Exported functions:
 ****************************************/

/*
 * Initialize the signal module.
 */
void smaSignalInit (void);

/*
 * Terminate the signal module.
 */
void smaSignalTerminate (void);


/*
 * Process the first signal in the signal queue.
 */
void smaSignalProcess(void);

/*
 * Return TRUE if the global signal queue is empty,
 * FALSE otherwise.
 */
int smaSignalQueueIsEmpty(void);

/*
 * Delete a signal and its parameters.
 */
void smaSignalDelete (SmaSignal *sig);

/*
 * Register the function "f" to be called when a signal
 * is delivered to destination "dst".
 */
void smaSignalRegisterDst (SmaStateMachine dst, SmaSignalFunction *f);

/*
 * Remove the registrated function for destination "dst".
 */
void smaSignalDeregister ( SmaStateMachine dst);

/*
 * Add a new signal to the end of the global queue.
 */
SmaSignal *smaSignalSendTo( SmaStateMachine dst, 
                           int signum,
                           long i_param,
                           unsigned long u_param1,
                           unsigned long u_param2,
                           void *p_param);


/*
 * Add an old signal to the beginning of the queue.
 */
void smaSignalPrepend(SmaSignal *sig);

#endif /* _SAINTSIG_H */


