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

/*******************************************************************************
 *
 * Filename:
 * ---------
 * msf_signal.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for signal handling adapter functions of Mobile Suite Framework
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#define _FILE_CODE_  _MSF_SIGNAL_C_

#include "kal_release.h"        /* Basic data type */

#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */

#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */

#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */

#include "event_shed.h" /* Event scheduler */

#include "stack_timer.h"        /* Stack timer */

#include "app_buff_alloc.h"

#include "stdarg.h"
#include "stdio.h"

#include "msf_cfg.h"
#include "msm_int.h"
#include "msf_int.h"
#include "msf_lib.h"
#include "msf_mem.h"

#include "wapadp.h"

#define MSM_SIG_Q_LEN        50 /* 25 */
#define MOD_SIG_Q_LEN        25 /* 15 */

typedef LCD_IP_CQUEUE(void *, MSM_SIG_Q_LEN) msm_sig_q_type;
     typedef LCD_IP_CQUEUE(void *, MOD_SIG_Q_LEN) mod_sig_q_type;

     void *msf_sig_q_tbl[MSF_NUMBER_OF_MODULES];

/**********************************************************************
 * HDI signal funktions
 **********************************************************************/


/*****************************************************************************
 * FUNCTION
 *  HDIa_signalRegisterQueue
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msfUid      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
     void HDIa_signalRegisterQueue(MSF_UINT8 msfUid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msfUid == MSF_MODID_MSM)
    {
        msf_sig_q_tbl[msfUid] = MSF_MEM_ALLOC(MSF_MODID_MSM, sizeof(msm_sig_q_type));
        LCD_IP_CQUEUE_INIT((*(msm_sig_q_type*) msf_sig_q_tbl[msfUid]));
    }
    else
    {
        msf_sig_q_tbl[msfUid] = MSF_MEM_ALLOC(MSF_MODID_MSM, sizeof(mod_sig_q_type));
        LCD_IP_CQUEUE_INIT((*(mod_sig_q_type*) msf_sig_q_tbl[msfUid]));
    }
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_signalDeregisterQueue
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msfUid      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_signalDeregisterQueue(MSF_UINT8 msfUid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *sig_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msf_sig_q_tbl[msfUid] == NULL)
    {
        return;
    }

    if (msfUid == MSF_MODID_MSM)
    {
        /* delete all signals not retrieved yet */
        while (!LCD_IP_CQUEUE_IS_EMPTY((*(msm_sig_q_type*) msf_sig_q_tbl[msfUid])))
        {
            LCD_IP_CQUEUE_REMOVE((*(msm_sig_q_type*) msf_sig_q_tbl[msfUid]), sig_ptr);
            HDIa_signalFreeMemory(sig_ptr);
        }
    }
    else
    {
        /* delete all signals not retrieved yet */
        while (!LCD_IP_CQUEUE_IS_EMPTY((*(mod_sig_q_type*) msf_sig_q_tbl[msfUid])))
        {
            LCD_IP_CQUEUE_REMOVE((*(mod_sig_q_type*) msf_sig_q_tbl[msfUid]), sig_ptr);
            HDIa_signalFreeMemory(sig_ptr);
        }
    }

    /* free signal queue */
    MSF_MEM_FREE(MSF_MODID_MSM, msf_sig_q_tbl[msfUid]);
    msf_sig_q_tbl[msfUid] = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_signalAllocMemory
 * DESCRIPTION
 *  
 * PARAMETERS
 *  signalDataLength        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *HDIa_signalAllocMemory(MSF_UINT16 signalDataLength)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MSF_MEM_ALLOC(MSF_MODID_MSM, signalDataLength);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_signalFreeMemory
 * DESCRIPTION
 *  
 * PARAMETERS
 *  signalData      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_signalFreeMemory(void *signalData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_MEM_FREE(MSF_MODID_MSM, signalData);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_signalSend
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msfUid                  [IN]        
 *  signalData              [?]         
 *  signalDataLength        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_signalSend(MSF_UINT8 msfUid, void *signalData, MSF_UINT16 signalDataLength)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msfUid >= MSF_NUMBER_OF_MODULES || msf_sig_q_tbl[msfUid] == NULL)
    {
        /* dest module doesn't exist */
        HDIa_signalFreeMemory(signalData);
        return HDI_SIGNAL_ERROR_QUEUE_UNKNOWN;
    }

    if (msfUid == MSF_MODID_MSM)
    {
        if (LCD_IP_CQUEUE_IS_FULL((*(msm_sig_q_type*) msf_sig_q_tbl[msfUid])))
        {
            /* queue is full */
            HDIa_signalFreeMemory(signalData);
            return HDI_SIGNAL_ERROR_QUEUE_FULL;
        }
        LCD_IP_CQUEUE_INSERT((*(msm_sig_q_type*) msf_sig_q_tbl[msfUid]), signalData);
    }
    else
    {
    #ifdef WPS_TASK_SUPPORT
        extern kal_bool msf_is_wps_task(MSF_UINT8 msfUid);
    #endif 

        if (LCD_IP_CQUEUE_IS_FULL((*(mod_sig_q_type*) msf_sig_q_tbl[msfUid])))
        {
            /* queue is full */
            HDIa_signalFreeMemory(signalData);
            return HDI_SIGNAL_ERROR_QUEUE_FULL;
        }
        LCD_IP_CQUEUE_INSERT((*(mod_sig_q_type*) msf_sig_q_tbl[msfUid]), signalData);

    #ifdef WPS_TASK_SUPPORT
        if (msf_is_wps_task(msfUid) == KAL_TRUE)
        {
            extern kal_bool wps_want_to_run;
            char *c = (char*)signalData;
            kal_uint16 msg_id = (*c << 8) + *(c + 1);

            /* unsolicited event */
            if (msg_id == MSF_SIG_SOCKET_NOTIFY
                || msg_id == MSF_SIG_SOCKET_CONNECT_RESPONSE
                || msg_id == MSF_SIG_SOCKET_HOST_BY_NAME || msg_id == MSF_SIG_FILE_NOTIFY)
            {
                extern void widget_send_update_event_to_wps(void);

                widget_send_update_event_to_wps();
            }
            else
            {
                wps_want_to_run = KAL_TRUE;
            }
        }
    #endif /* WPS_TASK_SUPPORT */ 
    }

    return HDI_SIGNAL_OK;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_signalRetrieve
 * DESCRIPTION
 *  
 * PARAMETERS
 *  destModId       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *HDIa_signalRetrieve(MSF_UINT8 destModId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *sig_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (destModId >= MSF_NUMBER_OF_MODULES || msf_sig_q_tbl[destModId] == NULL)
    {
        /* dest module doesn't exist */
        return NULL;
    }

    if (destModId == MSF_MODID_MSM)
    {
        if (LCD_IP_CQUEUE_IS_EMPTY((*(msm_sig_q_type*) msf_sig_q_tbl[destModId])))
        {
            /* queue is empty */
            return NULL;
        }

        LCD_IP_CQUEUE_REMOVE((*(msm_sig_q_type*) msf_sig_q_tbl[destModId]), sig_ptr);
    }
    else
    {
        if (LCD_IP_CQUEUE_IS_EMPTY((*(mod_sig_q_type*) msf_sig_q_tbl[destModId])))
        {
            /* queue is empty */
            return NULL;
        }

        LCD_IP_CQUEUE_REMOVE((*(mod_sig_q_type*) msf_sig_q_tbl[destModId]), sig_ptr);
    }

    return sig_ptr;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_signalQueueLength
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msfUid      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_signalQueueLength(MSF_UINT8 msfUid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int q_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msfUid >= MSF_NUMBER_OF_MODULES || msf_sig_q_tbl[msfUid] == NULL)
    {
        /* dest module doesn't exist */
        return -1;
    }

    if (msfUid == MSF_MODID_MSM)
    {
        LCD_IP_CQUEUE_NUM_OF_ITEMS((*(msm_sig_q_type*) msf_sig_q_tbl[msfUid]), q_len);
    }
    else
    {
        LCD_IP_CQUEUE_NUM_OF_ITEMS((*(mod_sig_q_type*) msf_sig_q_tbl[msfUid]), q_len);
    }

    return q_len;
}


/*****************************************************************************
 * FUNCTION
 *  HDI_signalQueueInit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HDI_signalQueueInit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MSF_NUMBER_OF_MODULES; i++)
    {
        msf_sig_q_tbl[i] = NULL;
    }
}

