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
 *   bmt_trc.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is trace map definition for BMT.
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _BMT_TRC_H
#define _BMT_TRC_H


#ifndef GEN_FOR_PC

   #ifndef _STACK_CONFIG_H
   #error "stack_config.h should be included before tst_config.h"
   #endif

#else
   #include "kal_trace.h"
#endif /* GEN_FOR_PC */


#ifndef _KAL_TRACE_H
   #error "kal_trace.h should be included before tst_trace.h"
#endif

BEGIN_TRACE_MAP(MOD_BMT)

   TRC_MSG(BMT_CALL_STATE_TRC,"BMT_CallState: callState = %d.")
   TRC_MSG(BMT_INVALID_CHARGER_TRC,"Invalid Charger.")
   TRC_MSG(BMT_ICHARGE_OVER_TRC,"ICHARGE too high.")
   TRC_MSG(BMT_ICHARGE_LOW_TRC,"ICHARGE too low.")
   TRC_MSG(BMT_VBAT_OVER_TRC,"VBAT too high.")
   TRC_MSG(BMT_VTEMP_OVER_TRC,"BATTMP too high.")
   TRC_MSG(BMT_VTEMP_LOW_TRC,"BATTMP too low.")
   TRC_MSG(BMT_CHR_HOLD_TRC,"CHR_HOLD.")
   TRC_MSG(BMT_VBAT_TRC,"VBAT = %d.")
   TRC_MSG(BMT_BATTMP_TRC,"BATTMP = %d.")
   TRC_MSG(BMT_ICHARGE_TRC,"ICHARGE = %d.")   
   TRC_MSG(BMT_VCHARGER_TRC,"VCHARGER = %d.")   
   TRC_MSG(BMT_CHRPRE_ON_STATE_TRC,"STATE = BMT_CHRPRE_ON.")
   TRC_MSG(BMT_CHRPRE_OFF_STATE_TRC,"STATE = BMT_CHRPRE_OFF.")
   TRC_MSG(BMT_FAST_CHARGE_CHANGE_TRC,"Chage state to FAST_CHARGE.")
   TRC_MSG(BMT_FAST_ON_STATE_TRC,"STATE = BMT_CHRFAST_ON.")
   TRC_MSG(BMT_FAST_OFF_STATE_TRC,"STATE = BMT_CHRFAST_OFF.")
	TRC_MSG(BMT_CHR_BATFULL_CHANGE_TRC,"Chage state to CHR_BATFULL.")
	TRC_MSG(BMT_CHR_TOPOFF_CHANGE_TRC,"Chage state to CHR_TOPOFF.")
	TRC_MSG(BMT_CHRTOPOFF_ON_STATE_TRC,"STATE = BMT_CHRTOPOFF_ON.")
	TRC_MSG(BMT_CHR_FAST_CHANGE_TRC,"Chage state to CHR_FAST.")   
	TRC_MSG(BMT_CHRTOPOFF_OFF_STATE_TRC,"STATE = BMT_CHRTOPOFF_OFF.")
	TRC_MSG(BMT_CHRBATFULL_ON_STATE_TRC,"STATE = BMT_CHRBATFULL_ON.")
	TRC_MSG(BMT_CHRBATFULL_OFF_STATE_TRC,"STATE = BMT_CHRBATFULL_OFF.")
	TRC_MSG(BMT_CHRHOLD_STATE_TRC,"STATE = BMT_CHRHOLD.")
	TRC_MSG(BMT_HIGH_BAT_FULL_TRC,"High Battery Full.")
	TRC_MSG(BMT_MEASURE_STOP_TRC,"BMT_MeasureStop.")
	TRC_MSG(BMT_PWRON_TRC,"BMT.PWRon = %d.")
	TRC_MSG(BMT_TASK_MAIN_TRC,"=====================BMT_task_main=====================.")
	TRC_MSG(BMT_SAFETY_TIMER_EXPIRE_TRC,"Safety timer(6 hours) expired.")  
	TRC_MSG(BMT_SAFETY_TIMER_START_TRC,"Safety timer(6 hours) starts.")  
	TRC_MSG(BMT_SAFETY_TIMER_STOP_TRC,"Safety timer(6 hours) stops.")  
	TRC_MSG(BMT_STOP_TIMER_EXPIRE_TRC,"stop timer(30 min) expired.")  
	TRC_MSG(BMT_STOP_TIMER_START_TRC,"Stop timer(30 min) starts.")  
	TRC_MSG(BMT_STOP_TIMER_STOP_TRC,"Stop timer(30 min) stops.")  	
END_TRACE_MAP(MOD_BMT)

#endif /* _BMT_TRC_H */


