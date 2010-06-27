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

/*--- Include files ---*/

#include "msf_def.h"
#include "msf_cfg.h"
#include "msf_mem.h"
#include "msf_log.h"
#include "samem.h"
#include "saintsig.h"


/*--- Definitions/Declarations ---*/

/*--- Types ---*/

/*--- Constants ---*/

/* Max number of signal structs stored in the free list: */
#define SMA_SIG_MAX_FREE_LIST_LENGTH   10

/*--- Forwards ---*/

/*--- Externs ---*/

/*--- Macros ---*/

/*--- Global variables ---*/

/*--- Static variables ---*/



/*! \file maintsig.c
 * \brief  <brief description>
 */

/****************************************
 * Global variables:
 ****************************************/

/*lint -esym(956,m_signal_queue_first,m_signal_queue_last) */
/*lint -esym(956,m_signal_free_list,m_signal_free_list_length,m_signal_func) */
/* Non const, non volatile static or external variable. Not a problem since 
 * we're not running anything multithreaded. */

/* The global queue of signals to be delivered: */
static SmaSignal    *sma_signal_queue_first;
static SmaSignal    *sma_signal_queue_last;

/* List of available signal structs. This is used
 * to reduce the number of allocations. */
static SmaSignal   *sma_signal_free_list;
static int          sma_signal_free_list_length;

/* The table of known FSM/destinations */

static SmaSignalFunction *sma_signal_func[SMA_FSM_MAX_REGS];

/*
 * Initialize the signal module.
 */
void smaSignalInit (void)
{
    int i;
    
    sma_signal_queue_first      = sma_signal_queue_last = NULL;
    sma_signal_free_list        = NULL;
    sma_signal_free_list_length = 0;
    
    for (i = 0; i < SMA_FSM_MAX_REGS; i++)
    {
        sma_signal_func[i] = NULL;
    } /* for */
} /* smaSignalInit */


/*
 * Terminate the signal module.
 */
void smaSignalTerminate (void)
{
    SmaSignal   *sig;
    int           i;
    
    /* Empty the signal queue */
    while ( !smaSignalQueueIsEmpty()) 
    {
        sig = sma_signal_queue_first;
        sma_signal_queue_first = sig->next;
        smaSignalDelete(sig);
    }
    
    /* Empty the list of free signal structs */
    while (sma_signal_free_list != NULL) 
    {
        sig = sma_signal_free_list;
        sma_signal_free_list = sig->next;
        SMA_FREE(sig);
    }
    
    /* Reset the function pointers */
    for (i = 0; i < SMA_FSM_MAX_REGS; i++)
    {
        sma_signal_func[i] = NULL;
    }
}

/*
 * Process the first signal in the signal queue.
 */
void smaSignalProcess(void)
{
    SmaSignal           *signal;
    SmaSignalFunction   *func;
    int                  idx;
    
    signal = sma_signal_queue_first;
    if (signal != NULL) 
    {
        sma_signal_queue_first = signal->next;
        if (sma_signal_queue_first == NULL)
        {
            sma_signal_queue_last = NULL;
        }
        idx = signal->dst;
        if ((idx >= 0) && (idx < SMA_FSM_MAX_REGS) &&
            ((func = sma_signal_func[idx]) != NULL))
        {
            func(signal);
        }
        else
        {
            smaSignalDelete(signal);
        }
    }
}

/*
 * Return TRUE if the global signal queue is empty,
 * FALSE otherwise.
 */
int smaSignalQueueIsEmpty (void)
{
    return sma_signal_queue_first == NULL;
}

/*
 * Delete a signal and its parameters.
 */
void smaSignalDelete(SmaSignal *sig)
{
    if (sig == NULL)
    {
        return;
    }
    
    if (sma_signal_free_list_length < SMA_SIG_MAX_FREE_LIST_LENGTH) 
    {
        sig->next = sma_signal_free_list;
        sma_signal_free_list = sig;
        sma_signal_free_list_length++;
    }
    else
    {
        SMA_FREE(sig);
    }
}

/*
 * Register the function "f" to be called when a signal
 * is delivered to destination "dst".
 */
void smaSignalRegisterDst( SmaStateMachine dst, SmaSignalFunction *f)
{
    if (dst < SMA_FSM_MAX_REGS)
    {
        sma_signal_func[dst] = f;
    }
    else
    {
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
            SAINTSIG_FDBDB0E356841F489BDFC37E76F7D4B2, "SmaSignalRegisterDst: FSM dst (%d) out of bounds\n", dst));
    } /* if */
}

/*
 * Remove the registrated function for destination "dst".
 */
void smaSignalDeregister( SmaStateMachine dst)
{
    if (dst < SMA_FSM_MAX_REGS)
    {
        sma_signal_func[dst] = NULL;
    }
    else
    {
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA,
            SAINTSIG_C9AB44DA732CE827C5224A9F12FEF716, "SmaSignalDeregister: FSM dst (%d) out of bounds\n", dst));
    } /* if */
}

/*
 * Add a new signal to the end of the global queue.
 */
SmaSignal *smaSignalSendTo( SmaStateMachine dst, int signum,
    long i_param, unsigned long u_param1, unsigned long u_param2,
    void *p_param)
{
    SmaSignal *signal = NULL;
    
    if ( sma_signal_free_list == NULL)
    {
        signal = SMA_ALLOC( sizeof(SmaSignal));
    }
    else 
    {
        signal = sma_signal_free_list;
        sma_signal_free_list = signal->next;
        --sma_signal_free_list_length;
    } /* if */
    
    if (signal != NULL)
    {
        signal->type = signum;
        signal->dst = dst;
        signal->i_param = i_param;
        signal->u_param1 = u_param1;
        signal->u_param2 = u_param2;
        signal->p_param = p_param;
    
        signal->next = NULL;
        if ( sma_signal_queue_last != NULL) 
        {
            sma_signal_queue_last->next = signal;
            sma_signal_queue_last = signal;
        }
        else 
        {
            sma_signal_queue_first = sma_signal_queue_last = signal;
        } /* if */
    } /* if */

    return signal;
} /* mSignalSendTo */

/*
 * Remove all signals with the specified id and data for a state machine.
 * Can be used to remove expired timers from the queue when the timer is removed.
 */
void smaSignalFlush( SmaStateMachine dst, int id, long i_param,
    unsigned long u_param1, unsigned long u_param2, const void *p_param)
{
    SmaSignal *sig     = sma_signal_queue_first;
    SmaSignal *prev    = NULL;
    SmaSignal *current = NULL;

    while (sig) 
    {
        if (sig->dst == dst && sig->type == id && sig->i_param == i_param &&
            sig->u_param1 == u_param1 && sig->u_param2 == u_param2 &&
            sig->p_param == p_param)
        {
            if (prev != NULL)
            {
                prev->next = sig->next;
            }
            else
            {
                sma_signal_queue_first = sig->next;
            } /* if */

            current = sig->next;
            smaSignalDelete(sig);
            sig = current;
        }
        else
        {
            sig = sig->next;
        } /* if */

        prev = sig;
    } /* while */
} /* smaSignalFlush */

/*
 * Add an old signal to the beginning of the queue.
 */
void smaSignalPrepend ( SmaSignal *sig)
{
    if (sig == NULL)
    {
        return;
    }
    
    sig->next = sma_signal_queue_first;
    if (sma_signal_queue_last == NULL)
    {
        sma_signal_queue_last = sig;
    }
    sma_signal_queue_first = sig;
} /* smaSignalPrepend */


