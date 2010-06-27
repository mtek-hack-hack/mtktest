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

/*! \file maintsig.c
 *  \brief The internal signal queue.
 */

/* MSF */
#include "msf_def.h"
#include "msf_cfg.h"
#include "msf_mem.h"
#include "msf_log.h"

/* MEA */
#include "maintsig.h"
#include "mamem.h"


/****************************************
 * Constants:
 ****************************************/

/*! Max number of signal structs stored in the free list: */
#define MEA_SIG_MAX_FREE_LIST_LENGTH   10

/****************************************
 * Global variables:
 ****************************************/

/*lint -esym(956,m_signal_queue_first,m_signal_queue_last) */
/*lint -esym(956,m_signal_free_list,m_signal_free_list_length,m_signal_func) */
/* Non const, non volatile static or external variable. Not a problem since 
 * we're not running anything multithreaded. */

/* The global queue of signals to be delivered: */
static MeaSignal    *mea_signal_queue_first;
static MeaSignal    *mea_signal_queue_last;

/* List of available signal structs. This is used
 * to reduce the number of allocations. */
static MeaSignal   *mea_signal_free_list;
static int          mea_signal_free_list_length;

/*! The table of known FSM/destinations */
static MeaSignalFunction *mea_signal_func[MEA_FSM_MAX_REGS];

/* Logging of signals to file */
#ifdef MSF_LOG_MODULE
static void logSignal(const MeaSignal *sig);
static const char *fsmName(MeaStateMachine fsm);
#endif /* MSF_LOG_MODULE */

/*!
 *  \brief Remove all signals with the specified id and data 
 *  for a state machine. Can be used to remove expired timers from the 
 *  queue when the timer is removed.
 *  \param dst      Current state machine
 *  \param id       The signal ID
 *  \param i_param  Signal parameter
 *  \param u_param1 Signal parameter
 *  \param u_param2 Signal parameter
 *  \param p_param  Signal parameter
 */
void meaSignalFlush(MeaStateMachine dst, int id, long i_param,
    unsigned long u_param1, unsigned long u_param2, const void *p_param)
{
    MeaSignal *sig     = mea_signal_queue_first;
    MeaSignal *prev    = NULL;
    MeaSignal *current = NULL;

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
                mea_signal_queue_first = sig->next;
            } /* if */

            current = sig->next;
            meaSignalDelete(sig);
            sig = current;
        }
        else
        {
            sig = sig->next;
        } /* if */

        prev = sig;
    } /* while */
} /* mSignalFlush */

/*!
 * \brief Initialize the signal module.
 */
void meaSignalInit (void)
{
    int i;
    
    mea_signal_queue_first      = mea_signal_queue_last = NULL;
    mea_signal_free_list        = NULL;
    mea_signal_free_list_length = 0;
    
    for (i = 0; i < MEA_FSM_MAX_REGS; i++)
    {
        mea_signal_func[i] = NULL;
    }
}

/*!
 * \brief Terminate the signal module.
 */
void meaSignalTerminate (void)
{
   MeaSignal   *sig;
    int           i;
    
    /* Empty the signal queue */
    while (!meaSignalQueueIsEmpty()) 
    {
        sig = mea_signal_queue_first;
        mea_signal_queue_first = sig->next;
        meaSignalDelete(sig);
    }
    
    /* Empty the list of free signal structs */
    while (mea_signal_free_list != NULL) 
    {
        sig = mea_signal_free_list;
        mea_signal_free_list = sig->next;
        MEA_FREE(sig);
    }
    
    /* Reset the function pointers */
    for (i = 0; i < MEA_FSM_MAX_REGS; i++)
    {
        mea_signal_func[i] = NULL;
    }
}

/*!
 * \brief Process the first signal in the signal queue.
 */
void meaSignalProcess(void)
{
    MeaSignal           *signal;
    MeaSignalFunction   *func;
    int                  idx;
    
    signal = mea_signal_queue_first;
    if (signal != NULL) 
    {
        mea_signal_queue_first = signal->next;
        if (mea_signal_queue_first == NULL)
        {
            mea_signal_queue_last = NULL;
        }
        idx = signal->dst;
        if ((idx >= 0) && (idx < MEA_FSM_MAX_REGS) &&
            ((func = mea_signal_func[idx]) != NULL))
        {
#ifdef MSF_LOG_MODULE
            logSignal(signal);
#endif
            func(signal);
        }
        else
        {
            meaSignalDelete(signal);
        }
    }
}

/*!
 * \return TRUE if the global signal queue is empty, otherwise FALSE.
 */
int meaSignalQueueIsEmpty (void)
{
    return mea_signal_queue_first == NULL;
}

/*!
 *  \brief Delete a signal and its parameters.
 *  \param sig The signal to delete
 */
void meaSignalDelete(MeaSignal *sig)
{
    if (sig == NULL)
    {
        return;
    }
    
    if (mea_signal_free_list_length < MEA_SIG_MAX_FREE_LIST_LENGTH) 
    {
        sig->next = mea_signal_free_list;
        mea_signal_free_list = sig;
        mea_signal_free_list_length++;
    }
    else
    {
        /*lint -e{774} */
        MEA_FREE(sig);
    }
}

/*!
 *  \brief Register the function "f" to be called when a signal
 *  is delivered to destination "dst".
 *  \param dst The destination FSM
 *  \param f The function to register
 */
void meaSignalRegisterDst(MeaStateMachine dst, MeaSignalFunction *f)
{
    if ((dst < MEA_FSM_MAX_REGS) && (dst > MEA_NOTUSED_FSM))
    {
        mea_signal_func[dst] = f;
    }
    else
    {
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
            MAINTSIG_C4391DF6E8E00BC32FB5E7816C04B785, "meaSignalRegisterDst: FSM dst (%d) out of bounds\n", dst));
    } /* if */
}

/*!
 *  \brief Remove the registered function for destination "dst".
 *  \param dst The FSM to deregister
 */
void meaSignalDeregister(MeaStateMachine dst)
{
    if ((dst < MEA_FSM_MAX_REGS) && (dst > MEA_NOTUSED_FSM))
    {
        mea_signal_func[dst] = NULL;
    }
    else
    {
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA,
            MAINTSIG_19480F37A60B0DD438E3D8E87EC7689A, "meaSignalDeregister: FSM dst (%d) out of bounds\n", dst));
    } /* if */
}

/*!
 *  \brief Add a new signal to the end of the global queue.
 *  \param dst      Current state machine
 *  \param signum   The signal ID
 *  \param i_param  Signal parameter
 *  \param u_param1 Signal parameter
 *  \param u_param2 Signal parameter
 *  \param p_param  Signal parameter
 *  \return The new signal. Could be NULL on erroneous destination FSM. 
 */
MeaSignal *meaSignalSendTo(MeaStateMachine dst, int signum,
    long i_param, unsigned long u_param1, unsigned long u_param2,
    void *p_param)
{
    MeaSignal *signal = NULL;

    if ((dst <= MEA_NOTUSED_FSM) || (dst >= MEA_FSM_MAX_REGS))
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MAINTSIG_C53FD130862BDF53ECE7943BA4291CB4, "%s(%d): Broken signal: non-existant destination FSM!\n",
        __FILE__, __LINE__));
        return NULL;
    } /* if */
    
    if (mea_signal_free_list == NULL)
    {
        signal = MEA_ALLOC(sizeof(MeaSignal));
    }
    else 
    {
        signal = mea_signal_free_list;
        mea_signal_free_list = signal->next;
        --mea_signal_free_list_length;
    } /* if */
    
    signal->type = signum;
    signal->dst = dst;
    signal->i_param = i_param;
    signal->u_param1 = u_param1;
    signal->u_param2 = u_param2;
    signal->p_param = p_param;
    
    signal->next = NULL;
    if (mea_signal_queue_last != NULL) 
    {
        mea_signal_queue_last->next = signal;
        mea_signal_queue_last = signal;
    }
    else 
    {
        mea_signal_queue_first = mea_signal_queue_last = signal;
    } /* if */

    return signal;
} /* mSignalSendTo */

/*!
 *  \brief Add an old signal to the beginning of the queue.
 *  \param sig The signal to put at the front of the queue.
 */
void meaSignalPrepend (MeaSignal *sig)
{
    if (sig == NULL)
    {
        return;
    }
    
    sig->next = mea_signal_queue_first;
    if (mea_signal_queue_last == NULL)
    {
        mea_signal_queue_last = sig;
    }
    mea_signal_queue_first = sig;
}

#ifdef MSF_LOG_MODULE

/*
 * Translate FSM enum to string
 */
static const char *fsmName(MeaStateMachine fsm)
{
    switch (fsm)
    {
    case MEA_CONFIG_FSM:
        return "Configuration";
    case MEA_MH_FSM :
        return "Message handler";
    case MEA_MV_FSM:
        return "Message viewer";
    case MEA_SE_FSM:
        return "SMIL editor";
    case MEA_ME_FSM :
        return "Message editor";
    case MEA_IN_FSM:
        return "Incoming notifications";
    case MEA_ASYNC_FSM:
        return "Asyncronous file operations";
    case MEA_MCR_FSM :
        return "Message creation";
    case MEA_MR_FSM :
        return "Message reader";
    case MEA_CRH_FSM :
        return "Content router handler";
    case MEA_COMM_FSM :
        return "Communication handler";
    case MEA_CORE_FSM :
        return "Core";
    case MEA_PBH_FSM :
        return "Phone book handler";
    case MEA_CTH_FSM:
        return "Cross triggering handler";
    case MEA_PH_FSM:
        return "Packet Handler";
    case MEA_MMV_FSM:
        return "Multipart mixed viewer";
    case MEA_MME_FSM:
        return "Multipart mixed editor";
    case MEA_MOB_FSM:
        return "Media object browser";
    case MEA_FSM_MAX_REGS:
    default :
        return "Unknown";
    } /* switch */
} /* fsmName */

/*
 * Logging of signals to file
 */
static void logSignal(const MeaSignal *sig)
{
#ifdef WAP_SUPPORT
    if (sig->dst != MEA_CONFIG_FSM && sig->type !=  4)
#endif /* WAP_SUPPORT */
    MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA,
        MAINTSIG_B41720380F5684734355715F5A186ED7, "MEA Internal SIG to %-20s %6d %7d %8d %8d %9d\n",
        fsmName(sig->dst), sig->type,
        sig->i_param, sig->u_param1, sig->u_param2, sig->p_param));
} /* logSignal */

#endif /* MSF_LOG_MODULE */


