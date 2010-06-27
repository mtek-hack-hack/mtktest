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
 *  MMITimer.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  MMI Timer header file.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef MMI_TIMER_H
#define MMI_TIMER_H

/*****************************************************************************
* Include                                                                     
*****************************************************************************/
#include "FrameworkStruct.h"
#include "TimerEvents.h"
#include "L4dr.h"
#include "WrapperGprot.h"

/*****************************************************************************
* Define                                                                      
*****************************************************************************/

/* MTK added by JL for sync with alignment time definition */
#define TIMER_IS_ALIGNMENT              0
#define TIMER_IS_NO_ALIGNMENT           1

/* timer_info: bit15        - timer type : align (0) or non-align (1) 
               bit14~bit0   - reserved */
#define TIMER_INFO_TYPE_FIELD       (0x8000)
#define TIMER_INFO_RESERVED_FIELD   (0x7FFF)


/*****************************************************************************
* Typedef                                                                     
*****************************************************************************/

/*****************************************************************************
* Local Variable                                                              
*****************************************************************************/

/*****************************************************************************
* Local Function                                                              
*****************************************************************************/

/*****************************************************************************
* Extern Global Variable                                                      
*****************************************************************************/

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
extern void StartTimer(U16 timerid, U32 delay, FuncPtr funcPtr);


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
extern void StartTimerEx(U16 timerid, U32 delay, oslTimerFuncPtr funcPtr, void* arg);


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
extern void StartNonAlignTimer(U16 timerid, U32 delay, FuncPtr funcPtr);


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
extern void StartNonAlignTimerEx(U16 timerid, U32 delay, oslTimerFuncPtr funcPtr, void* arg);


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
extern void StopTimer(U16 timerid);


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
extern BOOL IsMyTimerExist(U16 nTimerId);


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
extern MMI_BOOL mmi_frm_is_align_base_timer(void *base_timer_ptr);


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
extern void mmi_frm_suspend_timers(U32 type);


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
extern void mmi_frm_resume_timers(U32 type);


/*****************************************************************************
 * FUNCTION
 *  L4SetClock
 * DESCRIPTION
 *  This function is to set the clock request.
 * PARAMETERS
 *  datetime        [IN]        
 *  FuncRspPtr      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void L4SetClock(rtc_format_struct datetime, oslTaskFuncPtr FuncRspPtr);


/*****************************************************************************
 * FUNCTION
 *  L4SetClockRSP
 * DESCRIPTION
 *  This function is to get to the result of clock set response.
 * PARAMETERS
 *  buf         [IN]        Buf         
 * RETURNS
 *  void
 *****************************************************************************/
extern void L4SetClockRSP(void *buf);


/*****************************************************************************
 * FUNCTION
 *  L4GetClockTime
 * DESCRIPTION
 *  This function is to request to get the clock.
 * PARAMETERS
 *  FuncRspPtr      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void L4GetClockTime(oslTaskFuncPtr FuncRspPtr);


/*****************************************************************************
 * FUNCTION
 *  L4GetClockTimeRSP
 * DESCRIPTION
 *  This function is to receive the clock response.
 * PARAMETERS
 *  buf         [IN]        Buf         
 * RETURNS
 *  void
 *****************************************************************************/
extern void L4GetClockTimeRSP(void *buf);


#endif /* MMI_TIMER_H */ 

