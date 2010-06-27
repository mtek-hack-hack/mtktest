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
#include "kal_release.h"

/* MSF */
#include "msf_int.h"
#include "msf_mem.h"
#include "msf_dcvt.h"

/* MMS */
#include "mms_def.h"
#include "mms_cfg.h"
#include "mms_if.h"
#include "mltypes.h"

/* SLS */
#include "sls_def.h"
#include "sls_cfg.h"
#include "sls_if.h"

/* SMA */
#include "sma_def.h"

/* MMA */
#include "mmsadp.h"
#include "mma_def.h"
#include "mma_intsig.h"
#include "mma_main.h"
#include "mma_utils.h"

/* The global queue of signals to be delivered: */
static MmaSignal    *mma_signal_queue_first;
static MmaSignal    *mma_signal_queue_last;

/* List of available signal structs. This is used
 * to reduce the number of allocations. */
static MmaSignal   *mma_signal_free_list;
static int          mma_signal_free_list_length;

/* Max number of signal structs stored in the free list: */
#define MMA_SIG_MAX_FREE_LIST_LENGTH   5

/*****************************************************************************
 * FUNCTION
 *  mma_signal_terminate
 * DESCRIPTION
 *  Check if the global internal signal queue is empty.
 * PARAMETERS
 *  void
 * RETURNS
 *  Return TRUE if the global signal queue is empty. FALSE otherwise.
 *****************************************************************************/
kal_bool mma_signal_queue_is_empty (void)
{
    return (mma_signal_queue_first == NULL);
}

/*****************************************************************************
 * FUNCTION
 *  mma_signal_send_to
 * DESCRIPTION
 *  Add a new internal signal to the end of the global internal queue.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MmaSignal *mma_signal_send_to(int signum, long i_param, unsigned long u_param1, unsigned long u_param2, void *p_param)
{
    MmaSignal *signal = NULL;
    
    if ( mma_signal_free_list == NULL)
    {
        signal = MMA_ALLOC(sizeof(MmaSignal));
    }
    else 
    {
        signal = mma_signal_free_list;
        mma_signal_free_list = signal->next;
        --mma_signal_free_list_length;
    }
    
    if (signal != NULL)
    {
        signal->type = signum;
//        signal->dst = dst;
        signal->i_param = i_param;
        signal->u_param1 = u_param1;
        signal->u_param2 = u_param2;
        signal->p_param = p_param;
    
        signal->next = NULL;
        if ( mma_signal_queue_last != NULL) 
        {
            mma_signal_queue_last->next = signal;
            mma_signal_queue_last = signal;
        }
        else 
        {
            mma_signal_queue_first = mma_signal_queue_last = signal;
        }
    }

    return signal;
} /* mSignalSendTo */


/*****************************************************************************
 * FUNCTION
 *  mma_signal_delete
 * DESCRIPTION
 *  Delete a internal signal and its parameters.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mma_signal_delete(MmaSignal *sig)
{
    if (sig == NULL)
    {
        return;
    }
    
    if (mma_signal_free_list_length < MMA_SIG_MAX_FREE_LIST_LENGTH) 
    {
        sig->next = mma_signal_free_list;
        mma_signal_free_list = sig;
        mma_signal_free_list_length++;
    }
    else
    {
        MMA_FREE(sig);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mma_signal_init
 * DESCRIPTION
 *  Initialize the internal signal module.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mma_signal_init (void)
{
    mma_signal_queue_first      = mma_signal_queue_last = NULL;
    mma_signal_free_list        = NULL;
    mma_signal_free_list_length = 0;
}

/*****************************************************************************
 * FUNCTION
 *  mma_signal_process
 * DESCRIPTION
 *  Process the first signal in the internal signal queue.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mma_signal_process(void)
{
    MmaSignal           *signal;
    
    signal = mma_signal_queue_first;
    if (signal != NULL) 
    {
        mma_signal_queue_first = signal->next;
        if (mma_signal_queue_first == NULL)
        {
            mma_signal_queue_last = NULL;
        }
        mma_main_signal_handler(signal);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mma_signal_terminate
 * DESCRIPTION
 *  Terminate the internal signal module.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mma_signal_terminate (void)
{
    MmaSignal   *sig;
    
    /* Empty the signal queue */
    while ( !mma_signal_queue_is_empty()) 
    {
        sig = mma_signal_queue_first;
        mma_signal_queue_first = sig->next;
        mma_signal_delete(sig);
    }
    
    /* Empty the list of free signal structs */
    while (mma_signal_free_list != NULL) 
    {
        sig = mma_signal_free_list;
        mma_signal_free_list = sig->next;
        MMA_FREE(sig);
    }
}

