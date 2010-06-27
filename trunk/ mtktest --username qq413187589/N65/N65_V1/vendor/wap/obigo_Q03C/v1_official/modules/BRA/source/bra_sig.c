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
/*
 * bra_sig.c
 *
 * Created by Mats Tedenvall, Wed Jul 10 10:11 2002.
 *
 * Revision history:
 *   020710, MTV: Created
 *
 */
/************************************************************
 *
 * Sending and receiving signals in the protocol stack:
 *
 ************************************************************/
#include "bra_sig.h"
#include "msf_def.h"
#include "msf_mem.h"

/****************************************
 * Constants:
 ****************************************/

/* Max number of registered signal destinations: */
#define BRA_SIG_MAX_REGS               40

/* Max number of signal structs stored in the free list: */
#define BRA_SIG_MAX_FREE_LIST_LENGTH   10


/****************************************
 * Global variables:
 ****************************************/

/* The global queue of signals to be delivered: */
static bra_signal_t *bra_signal_queue_first;
static bra_signal_t *bra_signal_queue_last;

/* List of available signal structs. This is used
 * to reduce the number of allocations. */
static bra_signal_t *bra_signal_free_list;
static int         bra_signal_free_list_length;

/* The table of known destinations */
static bra_signal_function_t *bra_signal_func[BRA_SIG_MAX_REGS];


/****************************************
 * External function:
 ****************************************/

extern void
bra_signal_process_external (bra_signal_t *sig);


/*********************************************
 * Function definitions:
 *********************************************/

/*
 * Initialize the signal module.
 */
void
bra_signal_init (void)
{
  int i;

  bra_signal_queue_first = bra_signal_queue_last = NULL;
  bra_signal_free_list = NULL;
  bra_signal_free_list_length = 0;

  for (i = 0; i < BRA_SIG_MAX_REGS; i++)
    bra_signal_func[i] = NULL;
}

/*
 * Terminate the signal module.
 */
void
bra_signal_terminate (void)
{
  bra_signal_t *sig;
  int           i;

  while (!bra_signal_queue_is_empty ()) {
    sig = bra_signal_queue_first;
    bra_signal_queue_first = sig->next;
    bra_signal_delete (sig);
  }

  while (bra_signal_free_list != NULL) {
    sig = bra_signal_free_list;
    bra_signal_free_list = sig->next;
    MSF_MEM_FREE (MSF_MODID_BRA, sig);
  }

  for (i = 0; i < BRA_SIG_MAX_REGS; i++)
    bra_signal_func[i] = NULL;
}


/*
 * Process the first signal in the signal queue.
 */
void
bra_signal_process (void)
{
  bra_signal_t          *sig;
  bra_signal_function_t *func;
  int                    idx;

  sig = bra_signal_queue_first;
  if (sig != NULL) {
    bra_signal_queue_first = sig->next;
    if (bra_signal_queue_first == NULL)
      bra_signal_queue_last = NULL;
    idx = sig->dst >> 4;
    if ((idx >= 0) && (idx < BRA_SIG_MAX_REGS) &&
        ((func = bra_signal_func[idx]) != NULL))
      func (sig);
    else
      bra_signal_delete (sig);
  }
}

/*
 * Register the function "f" to be called when a signal
 * is delivered to destination "dst".
 */
void
bra_signal_register_dst (int dst, bra_signal_function_t *f)
{
  bra_signal_func[dst >> 4] = f;
}

/*
 * Remove the registrated function for destination "dst".
 */
void
bra_signal_deregister (int dst)
{
  bra_signal_func[dst >> 4] = NULL;
}

/*
 * Delete a signal.
 */
void
bra_signal_delete (bra_signal_t *sig)
{
  if (sig == NULL)
    return;

  if (bra_signal_free_list_length < BRA_SIG_MAX_FREE_LIST_LENGTH) {
    sig->next = bra_signal_free_list;
    bra_signal_free_list = sig;
    bra_signal_free_list_length++;
  }
  else
    MSF_MEM_FREE (MSF_MODID_BRA, sig);
}

/*
 * Return TRUE if the global signal queue is empty,
 * FALSE otherwise.
 */
int
bra_signal_queue_is_empty (void)
{
  return bra_signal_queue_first == NULL;
}

/*
 * Add a new signal to the end of the global queue.
 */
void
bra_signal_sendto (int dst, int signum,
                 long int i_param,
                 unsigned long int u_param1,
                 unsigned long int u_param2,
                 void *p_param)
{
  bra_signal_t *sig;

  if (bra_signal_free_list == NULL) {
    sig = MSF_MEM_ALLOCTYPE (MSF_MODID_BRA, bra_signal_t);
    if (sig == NULL) {
      MSF_MEM_FREE (MSF_MODID_BRA, p_param);
      return;
    }
  }
  else {
    sig = bra_signal_free_list;
    bra_signal_free_list = sig->next;
    bra_signal_free_list_length--;
  }

  sig->type = signum;
  sig->dst = dst;
  sig->i_param = i_param;
  sig->u_param1 = u_param1;
  sig->u_param2 = u_param2;
  sig->p_param = p_param;

  sig->next = NULL;
  if (bra_signal_queue_last != NULL) {
    bra_signal_queue_last->next = sig;
    bra_signal_queue_last = sig;
  }
  else {
    bra_signal_queue_first = bra_signal_queue_last = sig;
  }
}

/*
 * Add an old signal to the beginning of the queue.
 */
void
bra_signal_prepend (bra_signal_t *sig)
{
  if (sig == NULL)
    return;

  sig->next = bra_signal_queue_first;
  if (bra_signal_queue_last == NULL)
    bra_signal_queue_last = sig;
  bra_signal_queue_first = sig;
}


