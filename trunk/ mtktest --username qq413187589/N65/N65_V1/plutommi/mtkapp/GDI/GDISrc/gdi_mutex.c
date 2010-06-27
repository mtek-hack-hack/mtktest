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
 * Filename:
 * ---------
 *  gdi_mutex.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GDI Image Hardware Gif related.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#include "gdi_internal.h"
#include "gdc_include.h"

#if defined(GDI_MUTEX_DEBUG) && defined(__MTK_TARGET__)
    //#define GDI_MUTEX_DEBUG_DUMP_STACK
#endif /* GDI_MUTEX_DEBUG */ 

#if 0
/* under construction !*/
#endif


/* extern void* TCD_Current_Thread; */
extern kal_taskid kal_get_current_thread_ID(void);
extern kal_uint8 INT_Exception_Enter;
extern void INT_ExceptionDumpStack(long *dumpbuf, long *current_thread);

#include "drv_comm.h"


/* global mutex variable */
#if defined(__MTK_TARGET__)
#pragma arm section rwdata = "INTERNRW" , rodata = "INTERNCONST" , zidata = "INTERNZI"
#endif 

gdi_mutex_struct gdi_mutex;
int gdi_mutex_serial = 0;

#if defined(__MTK_TARGET__)
#pragma arm section rwdata, rodata , zidata
#endif 

#ifdef GDI_MUTEX_DEBUG_DUMP_STACK
long gdi_mutex_stack_backup[120];
#endif 
#define GDI_MUTEX_GUARD_PATTERN 0x87654321
/* ///////////////////////////////////////////////////////////////////////////////////////////////////// */


/*****************************************************************************
 * FUNCTION
 *  gdi_mutex_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  m       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_mutex_init(gdi_mutex_struct *m)
{
    m->cnt = 0;
    m->tid = NULL;
    m->front_guard = GDI_MUTEX_GUARD_PATTERN;
    m->rear_guard = GDI_MUTEX_GUARD_PATTERN;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_mutex_lock
 * DESCRIPTION
 *  
 * PARAMETERS
 *  M       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_mutex_lock(gdi_mutex_struct *M)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 save_irq_mask;
    kal_taskid gdi_current_thread_id = kal_get_current_thread_ID();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (INT_Exception_Enter)
    {
        return;
    }
    if (gdi_current_thread_id == NULL)
    {
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* DEMO_PROJECT */ 
        return;
    }

    if (gdi_current_thread_id != M->tid)
    {
        /* wait gdi mutex free */
        while (1)
        {
            save_irq_mask = SaveAndSetIRQMask();
            if (M->cnt == 0)
            {
                M->cnt = 1;
                RestoreIRQMask(save_irq_mask);
                break;
            }
            RestoreIRQMask(save_irq_mask);
            kal_sleep_task(1);  /* waiting */
        }

        /* get gdi mutex */

        M->tid = gdi_current_thread_id;
        gdi_mutex_serial++;
    #ifdef GDI_MUTEX_DEBUG_DUMP_STACK
        /* Store Stack Status when gdi mutex lock */
        INT_ExceptionDumpStack(gdi_mutex_stack_backup, (long*)gdi_current_thread_id);
    #endif /* GDI_MUTEX_DEBUG */ 
    }
    else
    {
        save_irq_mask = SaveAndSetIRQMask();
        ++(M->cnt);
        RestoreIRQMask(save_irq_mask);
    }

}


/*****************************************************************************
 * FUNCTION
 *  gdi_mutex_unlock
 * DESCRIPTION
 *  
 * PARAMETERS
 *  M       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_mutex_unlock(gdi_mutex_struct *M)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 save_irq_mask;
    kal_taskid gdi_current_thread_id = kal_get_current_thread_ID();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (INT_Exception_Enter)
    {
        return;
    }

    save_irq_mask = SaveAndSetIRQMask();
    if (gdi_current_thread_id != NULL)
    {
        GDI_DEBUG_ASSERT(M->tid == gdi_current_thread_id);

        if (--M->cnt == 0)
        {
            M->tid = NULL;
        }
    }
    RestoreIRQMask(save_irq_mask);
}

/* ////////////////////////////////////////////////////////////////////////////////////////////////////////// */


/*****************************************************************************
 * FUNCTION
 *  gdi_fast_mutex_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_fast_mutex_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_mutex.cnt = 0;
    gdi_mutex.tid = NULL;
    gdi_mutex.front_guard = GDI_MUTEX_GUARD_PATTERN;
    gdi_mutex.rear_guard = GDI_MUTEX_GUARD_PATTERN;
}

#if defined(__MTK_TARGET__)
#pragma arm section code = "INTERNCODE"
#endif 


/*****************************************************************************
 * FUNCTION
 *  gdi_fast_mutex_lock
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_fast_mutex_lock(void)
{
    kal_taskid gdi_current_thread_id;
    U32 save_irq_mask;

#ifdef DEMO_PROJECT
    GDI_ASSERT(gdi_mutex.front_guard == GDI_MUTEX_GUARD_PATTERN);
    GDI_ASSERT(gdi_mutex.rear_guard == GDI_MUTEX_GUARD_PATTERN);
#endif /* DEMO_PROJECT */ 

    if (INT_Exception_Enter)
        return;

#if 0
/* under construction !*/
/* under construction !*/
		#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#ifdef GDI_MUTEX_DEBUG_DUMP_STACK
/* under construction !*/
/* under construction !*/
		#endif // GDI_MUTEX_DEBUG
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 
    save_irq_mask = SaveAndSetIRQMask();
    if ((gdi_current_thread_id = kal_get_current_thread_ID()) != NULL)
    {
        if (gdi_current_thread_id != gdi_mutex.tid)
        {
            if(gdi_mutex.tid == gdc_thread_id) // Is current GDI user GDC task ( non-blocking task ) ?
                if(!gdi_nb_is_high_priority())   // Should we wait non-blocking finish ?
                    gdi_image_set_abort(TRUE); // Force abort non-blocking job

            /* wait gdi mutex free */
            while (gdi_mutex.cnt)
            {
                RestoreIRQMask(save_irq_mask);
                kal_sleep_task(1);  /* waiting */
                save_irq_mask = SaveAndSetIRQMask();
            }
            gdi_mutex.cnt = 1;
            gdi_mutex.tid = gdi_current_thread_id;
            gdi_mutex_serial++;

            gdi_image_set_abort(FALSE); // disable force abort, because we had got the mutex

    		#ifdef GDI_MUTEX_DEBUG_DUMP_STACK
    		//Store Stack Status when gdi mutex lock
    		INT_ExceptionDumpStack(gdi_mutex_stack_backup,(long*)gdi_current_thread_id);
    		#endif // GDI_MUTEX_DEBUG
        }
        else
        {
            ++(gdi_mutex.cnt);
        }
    }
    RestoreIRQMask(save_irq_mask);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_fast_mutex_unlock
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_fast_mutex_unlock(void)
{
    kal_taskid gdi_current_thread_id;
    U32 save_irq_mask;

    /* kal_taskid gdi_current_thread_id = kal_get_current_thread_ID(); */

    if (INT_Exception_Enter)
        return;

    save_irq_mask = SaveAndSetIRQMask();
    gdi_current_thread_id = kal_get_current_thread_ID();
    if (gdi_current_thread_id != NULL)
    {
        GDI_DEBUG_ASSERT(gdi_mutex.tid == gdi_current_thread_id);

        if (--gdi_mutex.cnt == 0)
        {
            gdi_mutex.tid = NULL;
        }
    }
    RestoreIRQMask(save_irq_mask);

}

#ifdef __MTK_TARGET__
#pragma arm section code
#endif 

BOOL gdi_fast_mutex_is_owner(void)
{
    BOOL ret;
    U32 save_irq_mask;
    save_irq_mask = SaveAndSetIRQMask();
        ret = (gdi_mutex.tid == kal_get_current_thread_ID());
    RestoreIRQMask(save_irq_mask);
    return ret;
}
