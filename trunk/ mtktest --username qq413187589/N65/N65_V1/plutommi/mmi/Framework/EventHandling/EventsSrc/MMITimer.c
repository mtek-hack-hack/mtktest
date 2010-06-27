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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *  MMITimer.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  MMI Timer.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*****************************************************************************
* Include                                                                     
*****************************************************************************/

/*  Include: MMI header file */
#include "MMI_features.h"
#include "stdC.h"
#include "L4dr.h"
#include "MMIDataType.h"
#include "FrameworkGprot.h"        
#include "FrameworkProt.h"  
#include "DebugInitDef.h"
#include "MMI_trc.h" 


/*****************************************************************************
* Define                                                                      
*****************************************************************************/ 

/* the recommended value: 12 or 24 */
#define SIMULTANEOUS_TIMER_NUM         (12)

/* MSB(Most Significant Bit) of g_timer_table.timer_id[i] is align_timer_mask */
#define NO_ALIGNMENT_TIMER_MASK        (0x8000)
#define ALIGNMENT_TIMER_MASK           (0)

/* ticks of 20 millisecond. because KAL did not define the valye. define in floating falue to avoid early rouning */
#define MMI_TICKS_20_MSEC  (KAL_TICKS_1_SEC/50.0)

/* ticks of 5 millisecond. because KAL did not define the valye. define in floating falue to avoid early rouning */
#define MMI_TICKS_5_MSEC  (KAL_TICKS_1_SEC/200.0)
 

/*****************************************************************************
* Typedef                                                                     
*****************************************************************************/

/* 
 * MTK added for two kinds of timer, one is for exactly time, another allow to delay.
 * TO Pixtel, This two defines should move to a proper place where 
 * can be used by other files.
 */

typedef struct {
    U16 timer_info;     /* timer info. */
    eventid event_id;   /* event_id returned from evshed_set_event() */
    oslTimerFuncPtr callback_func;  /* timer_expiry_func */
    void* arg;
} mmi_frm_timer_type;


typedef struct timertable
{
    mmi_frm_timer_type tm[SIMULTANEOUS_TIMER_NUM];  /* timer items */
    struct timertable *next;    /* point to the next TIMERTABLE data */
} TIMERTABLE;


/*****************************************************************************
* Local Variable                                                              
*****************************************************************************/

/*
 * In most case, the timers won't run simultaneously.
 * We run-time allocate the memory to store the timer information. 
 */
static TIMERTABLE g_timer_table = {0};
static U16 g_timer_table_size = 0;
static U16 g_timer_table_used = 0;

static oslTaskFuncPtr get_clocktime_callback_func;
static oslTaskFuncPtr set_clocktime_callback_func;

/* 
 * MTK added for two kinds of timer, one is for exactly time, another allow to delay.
 */
static stack_timer_struct base_timer1; /* no alignment timer */
static stack_timer_struct base_timer2; /* allow alignment timer */
static event_scheduler *event_scheduler1_ptr, *event_scheduler2_ptr;
static void L4StartTimer(
        unsigned short nTimerId,
        oslTimerFuncPtr TimerExpiry,
        void *funcArg,
        unsigned long nTimeDuration,
        unsigned char alignment);

/*****************************************************************************
* Extern Global Variable                                                      
*****************************************************************************/

/*****************************************************************************
* Local Function                                                              
*****************************************************************************/

//#define __MMI_FRM_TIMER_UNIT_TEST__

#ifdef __MMI_FRM_TIMER_UNIT_TEST__
static void mmi_frm_ut_timer(void);
static void mmi_frm_ut_align_timer(void *p);
static void mmi_frm_ut_nonalign_timer(void *p);
#endif /* __MMI_FRM_TIMER_UNIT_TEST__ */

static void L4StartBaseTimer(void *base_timer_ptr, unsigned int time_out);
static void L4StopBaseTimer(void *base_timer_ptr);
static MMI_BOOL L4TimerUsePreciseTick(unsigned short nTimerId);
static void L4CallBackTimer(void *p);
static void L4StopTimer(unsigned short nTimerId);


/*****************************************************************************
* Extern Global Function                                                      
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  StartTimer
 * DESCRIPTION
 *  This is used to set a timer
 * PARAMETERS
 *  timerid     [IN]        
 *  delay       [IN]        
 *  funcPtr     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void StartTimer(U16 timerid, U32 delay, FuncPtr funcPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    L4StopTimer(timerid);
    L4StartTimer(timerid, (oslTimerFuncPtr)funcPtr, 
                    (void *)timerid, delay, TIMER_IS_ALIGNMENT);
}


/*****************************************************************************
 * FUNCTION
 *  StartTimerEx
 * DESCRIPTION
 *  This is used to set a timer with the argument
 * PARAMETERS
 *  timerid     [IN]        
 *  delay       [IN]        
 *  funcPtr     [IN]        
 *  arg         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void StartTimerEx(U16 timerid, U32 delay, oslTimerFuncPtr funcPtr, void* arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    L4StopTimer(timerid);
    L4StartTimer(timerid, (oslTimerFuncPtr)funcPtr, 
                    (void *)arg, delay, TIMER_IS_ALIGNMENT);
}


/*****************************************************************************
 * FUNCTION
 *  StartNonAlignTimer
 * DESCRIPTION
 *  start a non-alignment timer
 * PARAMETERS
 *  timerid     [IN]        
 *  delay       [IN]        
 *  funcPtr     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void StartNonAlignTimer(U16 timerid, U32 delay, FuncPtr funcPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    L4StopTimer(timerid);
    L4StartTimer(timerid, (oslTimerFuncPtr)funcPtr, 
                    (void *)timerid, delay, TIMER_IS_NO_ALIGNMENT);
}


/*****************************************************************************
 * FUNCTION
 *  StartNonAlignTimerEx
 * DESCRIPTION
 *  start a non-alignment timer with the argument
 * PARAMETERS
 *  timerid     [IN]        
 *  delay       [IN]        
 *  funcPtr     [IN]        
 *  argument    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void StartNonAlignTimerEx(U16 timerid, U32 delay, oslTimerFuncPtr funcPtr, void* arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    L4StopTimer(timerid);
    L4StartTimer(timerid, (oslTimerFuncPtr)funcPtr, 
                    (void *)arg, delay, TIMER_IS_NO_ALIGNMENT);
}

/*****************************************************************************
 * FUNCTION
 *  StopTimer
 * DESCRIPTION
 *  This is used to reset a timer
 * PARAMETERS
 *  timerid     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void StopTimer(U16 timerid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    L4StopTimer(timerid);
}


/*****************************************************************************
 * FUNCTION
 *  EvshedMMITimerHandler
 * DESCRIPTION
 *  MMI Timer Event Scheduler
 * PARAMETERS
 *  dataPtr     [IN]        Data from L4
 * RETURNS
 *  void
 *****************************************************************************/
void EvshedMMITimerHandler(void *dataPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    stack_timer_struct *stack_timer_ptr;

    stack_timer_ptr = (stack_timer_struct*) dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (stack_timer_ptr == &base_timer1)
    {
        if (stack_is_time_out_valid(&base_timer1))
        {
            evshed_timer_handler(event_scheduler1_ptr);
        }
        stack_process_time_out(&base_timer1);
    }
    else if (stack_timer_ptr == &base_timer2)
    {
        if (stack_is_time_out_valid(&base_timer2))
        {
            evshed_timer_handler(event_scheduler2_ptr);
        }
        stack_process_time_out(&base_timer2);
    }
}


/*****************************************************************************
 * FUNCTION
 *  L4SetClock
 * DESCRIPTION
 *  This function is to set the clock request.
 * PARAMETERS
 *  datetime        [IN]        
 *  FuncRspPtr      [IN]        
 *  a(?)            [IN]        Void
 * RETURNS
 *  void
 *****************************************************************************/
void L4SetClock(rtc_format_struct datetime, oslTaskFuncPtr FuncRspPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    mmi_eq_set_rtc_time_req_struct *local_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* store the set time clock callback function */
    set_clocktime_callback_func = FuncRspPtr;

    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->msg_id = (U16) MSG_ID_MMI_EQ_SET_RTC_TIME_REQ;
    local_data = (mmi_eq_set_rtc_time_req_struct*)
        construct_local_para(sizeof(mmi_eq_set_rtc_time_req_struct), TD_CTRL);

    local_data->set_type = RTC_SETTING_TYPE_DATETIME;
    local_data->rtc_type = RTC_TIME_CLOCK_IND;
    local_data->info.alarm_format = 0;
    local_data->info.alarm_index = 0;
    local_data->info.type = 0;
    local_data->info.text[0] = '\0';
    local_data->info.recurr = 0;
    local_data->info.data_time.rtc_year = datetime.rtc_year;
    local_data->info.data_time.rtc_wday = datetime.rtc_wday;
    local_data->info.data_time.rtc_mon = datetime.rtc_mon;
    local_data->info.data_time.rtc_day = datetime.rtc_day;
    local_data->info.data_time.rtc_hour = datetime.rtc_hour;
    local_data->info.data_time.rtc_min = datetime.rtc_min;
    local_data->info.data_time.rtc_sec = datetime.rtc_sec;

    ilm_ptr->local_para_ptr = (local_para_struct*) local_data;
    ilm_ptr->peer_buff_ptr = NULL;
    SEND_ILM(MOD_MMI, MOD_L4C, MMI_L4C_SAP, ilm_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  L4SetClockRSP
 * DESCRIPTION
 *  This function is to get to the result of clock set response.
 * PARAMETERS
 *  buf         [?]         
 *  a(?)        [IN]        Buf
 * RETURNS
 *  void
 *****************************************************************************/
void L4SetClockRSP(void *buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (set_clocktime_callback_func != NULL)
    {
        set_clocktime_callback_func(buf);
    }
}


/*****************************************************************************
 * FUNCTION
 *  L4GetClockTime
 * DESCRIPTION
 *  This function is to request to get the clock.
 * PARAMETERS
 *  FuncRspPtr      [IN]        
 *  a(?)            [IN]        Void
 * RETURNS
 *  void
 *****************************************************************************/
void L4GetClockTime(oslTaskFuncPtr FuncRspPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    mmi_eq_get_rtc_time_req_struct *local_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* store the get time clock callback function */
    get_clocktime_callback_func = FuncRspPtr;

    ilm_ptr = allocate_ilm(MOD_MMI);
    local_data = (mmi_eq_get_rtc_time_req_struct*)
        construct_local_para(sizeof(mmi_eq_get_rtc_time_req_struct), TD_CTRL);

    local_data->rtc_type = RTC_TIME_CLOCK_IND;

    ilm_ptr->msg_id = (U16) MSG_ID_MMI_EQ_GET_RTC_TIME_REQ;
    ilm_ptr->local_para_ptr = (local_para_struct*) local_data;
    ilm_ptr->peer_buff_ptr = NULL;

    SEND_ILM(MOD_MMI, MOD_L4C, MMI_L4C_SAP, ilm_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  L4GetClockTimeRSP
 * DESCRIPTION
 *  This function is to receive the clock response.
 * PARAMETERS
 *  buf         [?]         
 *  a(?)        [IN]        Buf
 * RETURNS
 *  void
 *****************************************************************************/
void L4GetClockTimeRSP(void *buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (get_clocktime_callback_func != NULL)
    {
        get_clocktime_callback_func(buf);
    }
}


/*****************************************************************************
 * FUNCTION
 *  L4InitTimer
 * DESCRIPTION
 *  This function is to init the timer while task create.
 * PARAMETERS
 *  void
 *  a(?)        [IN]        Void
 * RETURNS
 *  void
 *****************************************************************************/
void L4InitTimer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    TIMERTABLE *p;
    TIMERTABLE *pp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Try to free TIMERTABLE list exclude g_timer_table */
    p = g_timer_table.next;
    pp = NULL;
    do
    {
        if (p != NULL)
        {
            pp = p->next;
            OslMfree(p);
        }
        p = pp;
    } while (p != NULL);
    /* reset g_timer_talbe */
    memset(&g_timer_table, 0, sizeof(TIMERTABLE));
    g_timer_table_size = SIMULTANEOUS_TIMER_NUM;
    g_timer_table_used = 0;

    /* Initiate the clock time callback function. */
    get_clocktime_callback_func = NULL;
    set_clocktime_callback_func = NULL;

    /* Initate the no alignment stack timer */
    stack_init_timer(&base_timer1, "MMI_Base_Timer1", MOD_MMI);

    /* Create a no alignment timer schedule */
    event_scheduler1_ptr = new_evshed(
                            &base_timer1,
                            L4StartBaseTimer,
                            L4StopBaseTimer,
                            0,
                            kal_evshed_get_mem,
                            kal_evshed_free_mem,
                            0);

    /* Initate the alignment stack timer */
    stack_init_timer(&base_timer2, "MMI_Base_Timer2", MOD_MMI);

    /* Create an alignment timer schedule */
    event_scheduler2_ptr = new_evshed(
                            &base_timer2,
                            L4StartBaseTimer,
                            L4StopBaseTimer,
                            0,
                            kal_evshed_get_mem,
                            kal_evshed_free_mem,
                            254);

    #ifdef __MMI_FRM_TIMER_UNIT_TEST__   
    mmi_frm_ut_timer();
    #endif /* __MMI_FRM_TIMER_UNIT_TEST__ */

}


/*****************************************************************************
 * FUNCTION
 *  L4StartTimer
 * DESCRIPTION
 *  This function is to start timer. To added for two kinds of timer, 
 *  one is for exactly time, another allow to delay.
 * PARAMETERS
 *  nTimerId            [IN]        timer id 
 *  TimerExpiry         [IN]        timer expiry callback function
 *  funcArg             [IN]        argument for expiry callback function 
 *  nTimeDuration       [IN]        timeout value
 *  alignment           [IN]        alignment/non-alignment attribute
 * RETURNS
 *  void
 *****************************************************************************/
static void L4StartTimer(
        unsigned short nTimerId,
        oslTimerFuncPtr TimerExpiry,
        void *funcArg,
        unsigned long nTimeDuration,
        unsigned char alignment)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    TIMERTABLE *pTable = NULL;
    U16 i = 0;
    U32 temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (TimerExpiry == NULL)
    {   /* If TimerExpiry is NULL, we don't start the timer */
        MMI_ASSERT(0);
        return;
    }

    MMI_ASSERT(nTimerId < MAX_TIMERS);

    if (L4TimerUsePreciseTick(nTimerId))
    {
        alignment = TIMER_IS_NO_ALIGNMENT;
    }

    if (nTimeDuration == 1000)
    {
        temp = KAL_TICKS_1_SEC - 4;
    }
    else
    {
        temp = (U32)((nTimeDuration / 5) * MMI_TICKS_5_MSEC);
    }

    if (temp == 0)
    {
        /* Cause by by rounding. If expire immediately, MoDIS boot-up failure because MMI keeps running and block NVRAM task */
        temp = (U32)MMI_TICKS_5_MSEC;
    }

    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_L4DRV_STARTTIMER_HDLR, nTimerId, TimerExpiry, temp, alignment);

    pTable = &g_timer_table;
    if (g_timer_table_used >= g_timer_table_size)
    {
        /*
         * TIMERTABLE list doesn't have enough space, allocate the memory 
         *
         * If we need to allocate the memeory, it means that MMI may have 
         * such many timers run simultaneously. We won't free the memory 
         * after we allocate more memory in TIMERTABLE list.
         */
        do
        {
            if (pTable->next == NULL)
            {
                pTable->next = OslMalloc(sizeof(TIMERTABLE));
                memset(pTable->next, 0, sizeof(TIMERTABLE));
                g_timer_table_size += SIMULTANEOUS_TIMER_NUM;
                pTable = pTable->next;
                i = 0;
                break;
            }
            pTable = pTable->next;
        } while (pTable != NULL);
    }
    else
    {
        /* find the empty record in g_timer_table list */
        i = 0;
        do
        {
            if (pTable->tm[i].event_id == NULL)
            {   /* find the empty space */
                break;
            }
            i++;
            if (i >= SIMULTANEOUS_TIMER_NUM)
            {
                pTable = pTable->next;
                i = 0;
            }
        } while (pTable != NULL);

        if (pTable == NULL)
        {
            /* Can't find the empty space in TIMERTABLE list, assert!!! */
            MMI_ASSERT(0);
        }
    }   /* if (g_timer_table_used >= g_timer_table_size) */

    /* 
     * already find the empty record, and then start timer 
     *
     * event_sheduler1 = NO alignment scherulder
     * event_sheduler2 = alignment scherulder (low power)
     */
    if (alignment == TIMER_IS_NO_ALIGNMENT)
    {
        /* MSB(Most Significant Bit) is align_timer_mask */
        pTable->tm[i].timer_info = nTimerId | NO_ALIGNMENT_TIMER_MASK;
        pTable->tm[i].event_id = evshed_set_event(
                                    event_scheduler1_ptr,
                                    (kal_timer_func_ptr) L4CallBackTimer,
                                    (void*)&(pTable->tm[i]),
                                    temp);
        pTable->tm[i].arg = funcArg;
        pTable->tm[i].callback_func = TimerExpiry;
        g_timer_table_used++;
    }
    else if (alignment == TIMER_IS_ALIGNMENT)
    {
        /* MSB(Most Significant Bit) is align_timer_mask */
        pTable->tm[i].timer_info = nTimerId | ALIGNMENT_TIMER_MASK;
        pTable->tm[i].event_id = evshed_set_event(
                                    event_scheduler2_ptr,
                                    (kal_timer_func_ptr) L4CallBackTimer,
                                    (void*)&(pTable->tm[i]),
                                    temp);
        pTable->tm[i].arg = funcArg;
        pTable->tm[i].callback_func = TimerExpiry;
        g_timer_table_used++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_is_align_base_timer
 * DESCRIPTION
 *  is the given base timer an alignment one
 * PARAMETERS
 *  base_timer_ptr        [IN]        base timer pointer
 * RETURNS
 *  IMER_IS_ALIGNMENT (MMI_TRUE) or TIMER_IS_NO_ALIGNMENT (MMI_FALSE)
 *****************************************************************************/
MMI_BOOL mmi_frm_is_align_base_timer(void *base_timer_ptr)
{
    if ( base_timer_ptr == (void *)&base_timer2 )
        return MMI_TRUE;
    else
        return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_suspend_timers
 * DESCRIPTION
 *  suspend all timers of given type
 * PARAMETERS
 *  type        [IN]        timer type (alignment or non-alignment)
 * RETURNS
 *  none
 *****************************************************************************/
void mmi_frm_suspend_timers(U32 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    event_scheduler *ev = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    switch(type)
    {
    case TIMER_IS_NO_ALIGNMENT:

        ev = event_scheduler1_ptr;
        break;
        
    case TIMER_IS_ALIGNMENT:
        ev = event_scheduler2_ptr;
        break;

    default:
        /* undefined type */
        MMI_ASSERT(0);
        break;
    }
    evshed_suspend_all_events(ev);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_resume_timers
 * DESCRIPTION
 *  resume all timers of given type
 * PARAMETERS
 *  type        [IN]        timer type (alignment or non-alignment)
 * RETURNS
 *  none
 *****************************************************************************/
void mmi_frm_resume_timers(U32 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    event_scheduler *ev = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    switch(type)
    {
    case TIMER_IS_NO_ALIGNMENT:

        ev = event_scheduler1_ptr;
        break;
        
    case TIMER_IS_ALIGNMENT:
        ev = event_scheduler2_ptr;
        break;

    default:
        /* undefined type */
        MMI_ASSERT(0);
        break;
    }
    evshed_resume_all_events(ev);
}


/*****************************************************************************
 * FUNCTION
 *  IsMyTimerExist
 * DESCRIPTION
 *  does the timer exist
 * PARAMETERS
 *  nTimerId        [IN]        
 * RETURNS
 *  timer exists or not
 *****************************************************************************/
BOOL IsMyTimerExist(U16 nTimerId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    TIMERTABLE *pTable = &g_timer_table;
    U16 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(nTimerId < MAX_TIMERS);

    /* find the nTimerId in TIMERTABLE list */
     do
     {
         /* MSB(Most Significant Bit) of timer_id is align_timer_mask */
         if ((pTable->tm[i].timer_info & (~NO_ALIGNMENT_TIMER_MASK)) == nTimerId)
         {
            /* timer found */
            return MMI_TRUE;
         }
         i++;
         if (i >= SIMULTANEOUS_TIMER_NUM)
         {
             pTable = pTable->next;
             i = 0;
         }
     } while (pTable != NULL);
    
    return MMI_FALSE;
}


/***************************************************************************** 
* Local Function
*****************************************************************************/

#ifdef __MMI_FRM_TIMER_UNIT_TEST__

#define ALIGN_TEST_TIMEOUT      1000   /* ms */
#define NON_ALIGN_TEST_TIMEOUT  1100   /* ms */

#define ALIGN_TEST_TM_ID        MMI_TIMER_BASE
#define NON_ALIGN_TEST_TM_ID    KEY_TIMER_ID_NONE

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_ut_timer
 * DESCRIPTION
 *  timer unit-test
 * PARAMETERS
 *  none
 * RETURNS
 *  none
 *****************************************************************************/
static void mmi_frm_ut_timer(void)
{
    /* unit test for non-alignment timer in NVRAM access */
    L4StartTimer(NON_ALIGN_TEST_TM_ID, (oslTimerFuncPtr)mmi_frm_ut_nonalign_timer, 
        (void *)NON_ALIGN_TEST_TM_ID, NON_ALIGN_TEST_TIMEOUT, TIMER_IS_NO_ALIGNMENT);
    
    /* unit test for alignment timer in NVRAM access */
    L4StartTimer(ALIGN_TEST_TM_ID, (oslTimerFuncPtr)mmi_frm_ut_align_timer, 
        (void *)ALIGN_TEST_TM_ID, ALIGN_TEST_TIMEOUT, TIMER_IS_ALIGNMENT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_ut_nonalign_timer
 * DESCRIPTION
 *  timer callback for non-align timer unit test
 * PARAMETERS
 *  timer id
 * RETURNS
 *  none
 *****************************************************************************/
static void mmi_frm_ut_nonalign_timer(void *p)
{
    if (IsInNVRAMProcedure())
    {
        Trace2(TRACE_GROUP_1, "[UT] non-align timer works in nvram access");
        //kal_print("\n[UT] non-align timer works in nvram access\n");
    }
    else
    {
        L4StartTimer(NON_ALIGN_TEST_TM_ID, (oslTimerFuncPtr)mmi_frm_ut_nonalign_timer, 
            (void *)NON_ALIGN_TEST_TM_ID, NON_ALIGN_TEST_TIMEOUT, TIMER_IS_NO_ALIGNMENT);
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_ut_align_timer
 * DESCRIPTION
 *  timer callback for align timer unit test
 * PARAMETERS
 *  timer id
 * RETURNS
 *  none
 *****************************************************************************/
static void mmi_frm_ut_align_timer(void *p)
{
    if (IsInNVRAMProcedure())
    {
        Trace2(TRACE_GROUP_1, "[UT] align timer will die in nvram access");
        MMI_ASSERT(0);
    }
    else
    {
        L4StartTimer(ALIGN_TEST_TM_ID, (oslTimerFuncPtr)mmi_frm_ut_align_timer, 
            (void *)ALIGN_TEST_TM_ID, ALIGN_TEST_TIMEOUT, TIMER_IS_ALIGNMENT);
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_ut_timer_with_arg
 * DESCRIPTION
 *  time unit-test:
 *  StartTimerEx(), StartNonAlignTimerEx(), StopTimer()
 * PARAMETERS
 *  tc          [IN]        test case id  
 * RETURNS
 *  none
 *****************************************************************************/
static void mmi_frm_ut_align_timer_with_arg(void *p);
static void mmi_frm_ut_nonalign_timer_with_arg(void *p);
void mmi_frm_ut_timer_with_arg(int tc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* We could parser the string to execute the different actions. */
    switch(tc)
    {
        case 1:
            Trace2(TRACE_GROUP_1, "[Timer-UT] mmi_frm_ut_timer_with_arg : 1");
            StartTimerEx(ALIGN_TEST_TM_ID, ALIGN_TEST_TIMEOUT, mmi_frm_ut_align_timer_with_arg, (void*)1);
            StartNonAlignTimerEx(NON_ALIGN_TEST_TM_ID, NON_ALIGN_TEST_TIMEOUT, mmi_frm_ut_nonalign_timer_with_arg, (void*)110);
            /* add the code here */
            break;
        case 2:
            Trace2(TRACE_GROUP_1, "[Timer-UT] mmi_frm_ut_timer_with_arg : 2");
            StartTimerEx(ALIGN_TEST_TM_ID, ALIGN_TEST_TIMEOUT, mmi_frm_ut_align_timer_with_arg, (void*)20);
            StartNonAlignTimerEx(NON_ALIGN_TEST_TM_ID, NON_ALIGN_TEST_TIMEOUT, mmi_frm_ut_nonalign_timer_with_arg, (void*)220);

            /* add the code here */
            break;
        case 3:
            Trace2(TRACE_GROUP_1, "[Timer-UT] mmi_frm_ut_timer_with_arg : 3");
            StopTimer(ALIGN_TEST_TM_ID);
            StopTimer(NON_ALIGN_TEST_TM_ID);
            /* add the code here */
            break;
        default:
            /* add the code here */
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_ut_align_timer_with_arg
 * DESCRIPTION
 *  timer callback for align timer unit test
 * PARAMETERS
 *  timer id
 * RETURNS
 *  none
 *****************************************************************************/
static void mmi_frm_ut_align_timer_with_arg(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((int)p == 1)
    {
        Trace2(TRACE_GROUP_1, "[Timer-UT] mmi_frm_ut_align_timer_with_arg timeout (1)");
        StartTimerEx(ALIGN_TEST_TM_ID, ALIGN_TEST_TIMEOUT/3, mmi_frm_ut_align_timer_with_arg, (void*)2);
    }
    else if ((int)p == 2)
    {
        Trace2(TRACE_GROUP_1, "[Timer-UT] mmi_frm_ut_align_timer_with_arg timeout (2)");
        StartTimerEx(ALIGN_TEST_TM_ID, ALIGN_TEST_TIMEOUT*2/3, mmi_frm_ut_align_timer_with_arg, (void*)3);
    }
    else if ((int)p == 3)
    {
        Trace2(TRACE_GROUP_1, "[Timer-UT] mmi_frm_ut_align_timer_with_arg timeout (3) - finish");
    }
    else if ((int)p == 20)
    {
        Trace2(TRACE_GROUP_1, "[Timer-UT] mmi_frm_ut_align_timer_with_arg timeout (20)");
        StartTimerEx(ALIGN_TEST_TM_ID, ALIGN_TEST_TIMEOUT, mmi_frm_ut_align_timer_with_arg, (void*)21);
    }
    else if ((int)p == 21)
    {
        Trace2(TRACE_GROUP_1, "[Timer-UT] mmi_frm_ut_align_timer_with_arg timeout (21)");
        StartTimerEx(ALIGN_TEST_TM_ID, ALIGN_TEST_TIMEOUT/2, mmi_frm_ut_align_timer_with_arg, (void*)20);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_ut_nonalign_timer_with_arg
 * DESCRIPTION
 *  timer callback for nonalign timer unit test
 * PARAMETERS
 *  timer id
 * RETURNS
 *  none
 *****************************************************************************/
static void mmi_frm_ut_nonalign_timer_with_arg(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((int)p == 110)
    {
        Trace2(TRACE_GROUP_1, "[Timer-UT] mmi_frm_ut_nonalign_timer_with_arg timeout (110)");
        StartNonAlignTimerEx(NON_ALIGN_TEST_TM_ID, NON_ALIGN_TEST_TIMEOUT*2, mmi_frm_ut_nonalign_timer_with_arg, (void*)120);
    }
    else if ((int)p == 120)
    {
        Trace2(TRACE_GROUP_1, "[Timer-UT] mmi_frm_ut_nonalign_timer_with_arg timeout (120) - finish");
    }
    else if ((int)p == 220)
    {
        Trace2(TRACE_GROUP_1, "[Timer-UT] mmi_frm_ut_nonalign_timer_with_arg timeout (220)");
        StartNonAlignTimerEx(NON_ALIGN_TEST_TM_ID, NON_ALIGN_TEST_TIMEOUT/2, mmi_frm_ut_nonalign_timer_with_arg, (void*)221);
    }
    else if ((int)p == 221)
    {
        Trace2(TRACE_GROUP_1, "[Timer-UT] mmi_frm_ut_nonalign_timer_with_arg timeout (221)");
        StartNonAlignTimerEx(NON_ALIGN_TEST_TM_ID, NON_ALIGN_TEST_TIMEOUT, mmi_frm_ut_nonalign_timer_with_arg, (void*)220);
    }
}

#endif /* __MMI_FRM_TIMER_UNIT_TEST__ */


/*****************************************************************************
 * FUNCTION
 *  L4StopTimer
 * DESCRIPTION
 *  This function is to stop timer. 
 *  To added for two kinds of timer, one is for exactly time, another allow to delay.
 * PARAMETERS
 *  nTimerId        [IN]        
 *  a(?)            [IN]        NTimerId
 * RETURNS
 *  void
 *****************************************************************************/
static void L4StopTimer(unsigned short nTimerId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    TIMERTABLE *pTable = &g_timer_table;
    U16 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(nTimerId < MAX_TIMERS);
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_L4DRV_STOPTIMER_HDLR, nTimerId);

    /* find the nTimerId in TIMERTABLE list */
    do
    {
        /* MSB(Most Significant Bit) of timer_id is align_timer_mask */
        if ((pTable->tm[i].timer_info & (~NO_ALIGNMENT_TIMER_MASK)) == nTimerId)
        {
            /* find the nTimerId */
            if (pTable->tm[i].event_id != NULL)
            {
                if ((pTable->tm[i].timer_info & NO_ALIGNMENT_TIMER_MASK) == NO_ALIGNMENT_TIMER_MASK)
                {   /* NO_ALIGNMENT_TIMER */
                    evshed_cancel_event(event_scheduler1_ptr, &(pTable->tm[i].event_id));
                }
                else
                {   /* ALIGNMENT_TIMER */
                    evshed_cancel_event(event_scheduler2_ptr, &(pTable->tm[i].event_id));
                }

                g_timer_table_used--;
                memset( &(pTable->tm[i]), 0, sizeof(mmi_frm_timer_type));
            }
            break;
        }
        i++;
        if (i >= SIMULTANEOUS_TIMER_NUM)
        {
            pTable = pTable->next;
            i = 0;
        }
    } while (pTable != NULL);

    /* if can't find nTimerId, do nothing */

}


/*****************************************************************************
 * FUNCTION
 *  L4StopBaseTimer
 * DESCRIPTION
 *  This function is to assign the stop timer base.
 * PARAMETERS
 *  base_timer_ptr      [?]         
 *  a(?)                [IN]        Base_timer_ptr
 * RETURNS
 *  void
 *****************************************************************************/
static void L4StopBaseTimer(void *base_timer_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stack_stop_timer((stack_timer_struct*) base_timer_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  L4StartBaseTimer
 * DESCRIPTION
 *  This function is to assign the start timer base.
 * PARAMETERS
 *  base_timer_ptr      [?]         
 *  time_out            [IN]        
 *  a(?)                [IN]        Base_timer_ptr
 *  b(?)                [IN]        Time_out
 * RETURNS
 *  void
 *****************************************************************************/
static void L4StartBaseTimer(void *base_timer_ptr, unsigned int time_out)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stack_start_timer((stack_timer_struct*) base_timer_ptr, 0, time_out);
}


/*****************************************************************************
 * FUNCTION
 *  L4TimerUsePreciseTick
 * DESCRIPTION
 *  Typically we round timer period to multiple of 100ms. 
 *  However, some timers need to be more accurate.
 * PARAMETERS
 *  nTimerId        [IN]        Timer ID
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL L4TimerUsePreciseTick(unsigned short nTimerId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (nTimerId)
    {
    #if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)
        case PEN_POLLING_TIMER:
            return MMI_TRUE;
    #endif /* defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__) */ 
        default:
            return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  L4CallBackTimer
 * DESCRIPTION
 *  This function is to execute the timer expire.
 * PARAMETERS
 *  p           [IN]         pointer to timer item
 * RETURNS
 *  void
 *****************************************************************************/
static void L4CallBackTimer(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_timer_type *pTimer = (mmi_frm_timer_type *)p;
    U32 nTimerId = pTimer->timer_info & (~NO_ALIGNMENT_TIMER_MASK);
    oslTimerFuncPtr pTimerExpiry = pTimer->callback_func;
    void * arg = pTimer->arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(nTimerId < MAX_TIMERS);

    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_L4DRV_CBTIMER_HDLR, nTimerId, pTimerExpiry);
    g_timer_table_used--;
    memset( pTimer, 0, sizeof(mmi_frm_timer_type)); /* clear timer */
    
    /*
     * we process g_timer_table_used, event_id and timer_id ... first 
     * because the user may call stoptimer() in the timer_expiry_func
     */

    if (pTimerExpiry)
    {
        pTimerExpiry((void *)arg);
    }

    mmi_frm_fetch_msg_from_extQ_to_circularQ();

    /* 
     * Because we modify MMI process protocol events and key events mechanism,
     * we don't need to process key events here.
     */
}


