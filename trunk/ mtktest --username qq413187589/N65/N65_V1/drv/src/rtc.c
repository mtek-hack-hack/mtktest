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
 *    rtc.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the RTC driver.
 *
 * Author:
 * -------
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
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include    "drv_features.h"
#include 	"kal_release.h"
#include 	"stack_common.h"  
#include 	"stack_msgs.h"
#include 	"app_ltlcom.h"       /* Task message communiction */
#include 	"drv_comm.h"
#include    "drvsignals.h"
#include 	"reg_base.h"
#include 	"rtc_hw.h"
#include 	"rtc_sw.h"
#include 	"intrCtrl.h"
#include	   "stack_ltlcom.h"       /*msg_send_ext_queue.....definitions*/
#include	   "stack_config.h"        /*MOD_UART1_HISR,MOD_UART2_HISR*/
#include    "drv_hisr.h"
#ifdef __MULTI_BOOT__
#include "kal_release.h"
#include "syscomp_config.h"
#include "multiboot_config.h"
#endif   /*__MULTI_BOOT__*/
#include "bmt.h"
#include    "nvram_struct.h"
#include    "nvram_enums.h"
#include    "nvram_data_items.h"
#include    "nvram.h"
#include    "nvram_interface.h"
#include    "nvram_user_defs.h"
//#include    "l1_core_private.h"
/*#define  RTC_Test*/
/* #define RTC_CAL_DEBUG */
/* #define RTC_CAL_DEBUG2 */
#if !defined(IC_BURNIN_TEST) && !defined(IC_MODULE_TEST) && !defined(__MAUI_BASIC__) && !defined(__FUE__) && !defined(DRV_RTC_NO_REG_COMM)
   #ifdef DRV_RTC_HW_CALI
      #define RTC_HW_CALIBRATION
   #else
      #define RTC_SW_CALIBRATION
   #endif
#endif

static kal_bool    First_PowerOn=KAL_FALSE;/*use a static variable to recode is this first power on*/
#if !defined(__FUE__)
static rtc_callbac RTC_CALLBAC;
static rtc_module  RTCConfig;

/*for rtc calibration*/
#if defined(RTC_HW_CALIBRATION) || defined(RTC_SW_CALIBRATION)

#if defined(__USB_ENABLE__) && !defined(__NVRAM_IN_USB_MS__)
extern kal_bool INT_USBBoot(void);
#endif /*__USB_ENABLE__*/

extern kal_uint32 L1I_GetTimeStamp(void);

/*for rtc calibration*/
void rtc_cali_init(void *timer_param);

/* Calibration State */
typedef enum
{
   CAL_STATE_NONE = 0,
   CAL_STATE_INIT,
   CAL_STATE_INIT2,
   CAL_STATE_START,
   CAL_STATE_RESET
} rtc_cali_state;


static kal_uint8 cali_state = CAL_STATE_NONE;
static kal_uint8 rtc_tc_int_var = TC_EN_None;
static kal_uint16 tc_min_expire_cnt = 0;


#if defined(RTC_HW_CALIBRATION)
#define RTC_CALI_PERIOD_MINS   (6)  // unit: minutes
#define RTC_CALI_PERIOD_SECS   (RTC_CALI_PERIOD_MINS*60)  // unit: minutes
#define RTC_CALI_REPEAT_DUR_SECS    (8)   // spec: 8 seconds to do one repeate calibration    
#define RTC_CALI_REPEAT_TOTAL_CNT   (RTC_CALI_PERIOD_SECS>>3)
#define RTC_CALI_TICK_VALUE (13000*RTC_CALI_PERIOD_MINS)
#define RTC_STANDARD_FREQ  (32768)
#define RTC_STANDARD_FREQ_8SECS  (RTC_STANDARD_FREQ*8)

#define RTC_CALI_REPEAT_MAX   (63)
#define RTC_CALI_REPEAT_MIN   (-64)
#define RTC_CALI_ONE_TIME_MAX   (2045)
#define RTC_CALI_ONE_TIME_MIN   (-2048)

static kal_uint32 rtc_current_frame_tick;
static kal_uint32 rtc_current_freq_8secs;
static kal_bool one_time_cali = KAL_FALSE;
static kal_int32 inaccurate_total_cnt = 0;
static kal_int32 no_diff_cnt = 0;

#elif defined(RTC_SW_CALIBRATION)
extern BMTStruct BMT;          /*Main BMT struct*/
/* extern NVRAM API */
extern kal_bool nvram_external_read_data(kal_uint8 LID,kal_uint8 rec_index, kal_uint8* buffer, kal_uint16 buffer_size);
kal_timerid   rtc_timer_id=0;
void rtc_timer(void *timer_param); 
void rtc_get_next_time(void);
void rtc_forward_time(t_rtc *rtc_time, kal_uint16 hours, kal_uint16 mins, kal_uint16 secs);
void rtc_backward_time(t_rtc *rtc_time, kal_uint16 hours, kal_uint16 mins, kal_uint16 secs);
void rtc_write_to_nvram(void);

#define rtc_cali_hr_period (1)/*hour*/ 
#define rtc_cali_min_period (2)/*minute*/ 
#define rtc_cali_tick_value (13000*60*rtc_cali_hr_period + 13000*rtc_cali_min_period)
#define rtc_cali_tick_safe_margin   13000 /* ticks */
#define rtc_tick_update_interval (217)/*1300/6 = 216 and 2/3*/
#define rtc_sec_update_interval (1)

static const kal_uint8 days_in_month[13] = 
{
   0, /*Null*/ 
   31, /*Jan*/
   28, /*Feb*/
   31, /*Mar*/
   30, /*Apr*/
   31, /*May*/
   30, /*Jun*/
   31, /*Jul*/
   31, /*Aug*/
   30, /*Sep*/
   31, /*Oct*/
   30, /*Nov*/
   31  /*Dec*/
};

static rtc_nvram_data  rtc_nvram_s;
static t_rtc next_current_time;
static kal_uint32 next_frame_tick, tick_left=0;
static kal_uint16 one_third_tick_count = 0; /* 217 - 216and2/3 = 1/3. The counts for the 1/3. */

static kal_uint8 rtc_al_int_var = AL_EN_None;
static kal_int32 pwroff_inacc_ticks = 0;
static kal_uint32 frame_tick1;
static kal_uint32 frame_tick2;
static kal_int32 frame_tick_1hr_diff;
#endif /* RTC_SW_CALIBRATION */
#endif /*  defined(RTC_HW_CALIBRATION) || defined(RTC_SW_CALIBRATION) */
//extern void dbg_print(char *fmt,...);
#ifdef RTC_Test
void RTC_delay(void)
{
	kal_uint16 i;
	for (i=0;i<2000;i++);
}
#endif

void RTC_setBBPU(kal_uint16 data)
{
   data &= 0x00ff;
   data |= 0x4300;
   DRV_WriteReg(RTC_BBPU,data);
}

#if defined(DRV_RTC_HW_CALI)
/*
* FUNCTION                                                            
*	RTC_write_trigger
*
* DESCRIPTION                                                           
*   	This function is to enable the transfers from core to RTC.
*
* CALLS  
*	It is called to trigger RTC register writing.
*
* PARAMETERS
*	None
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void RTC_write_trigger(void)
{
   DRV_WriteReg(RTC_WRTGR, RTC_WRTGR_WRTGR);
}

/*
* FUNCTION                                                            
*	RTC_write_trigger
*
* DESCRIPTION                                                           
*   	This function is to enable the transfers from core to RTC and wait till it's done.
*
* CALLS  
*	It is called to trigger RTC register writing.
*
* PARAMETERS
*	None
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void RTC_write_trigger_wait(void)
{
   kal_uint32 count=0;
   
   DRV_WriteReg(RTC_WRTGR, RTC_WRTGR_WRTGR);
   //while(count < 10000)
   while(count < 0xffffffff)
   {
      if ((RTC_BBPU_CBUSY & DRV_Reg(RTC_BBPU))==0)
         break;
      count++;
   }
}

#endif

/*
* FUNCTION                                                            
*	isPWROnByRTC
*
* DESCRIPTION                                                           
*   	This function is to check whether "power on" is due to RTC.
*
* CALLS  
*	It is called to check whether "power on" is due to RTC.
*
* PARAMETERS
*	None
*	
* RETURNS
*	KAL_TRUE: "Power on" is due to RTC.
*	KAL_FALSE: "Power on" is not due to RTC.
*
* GLOBALS AFFECTED
*   external_global
*/
kal_bool isPWROnByRTC(void)
{
#if defined(DRV_RTC_PWRON_BBPU_POLARITY) || defined(FPGA)
	kal_uint16 BBPU;
	kal_uint16 POLAR;
	kal_uint16 PWRSW;
	BBPU = DRV_Reg(RTC_BBPU);
	POLAR = BBPU & RTC_BBPU_PWR_POLARITY;
	POLAR >>= 1;
	PWRSW = BBPU & RTC_BBPU_PWR_SW;
	PWRSW >>= 4;
	
	if (POLAR == PWRSW)
	{
		return KAL_TRUE;
	}
	else
	{
		return KAL_FALSE;
	}
#endif   /*DRV_RTC_PWRON_BBPU_POLARITY,FPGA*/

#if defined(DRV_RTC_PWRON_BBPU_SW)
   if (DRV_Reg(RTC_BBPU) & RTC_BBPU_PWR_SW)
      return KAL_TRUE;
   else
      return KAL_FALSE;
#endif   /*DRV_RTC_PWRON_BBPU_SW*/
}
//=================================================================
/*
* FUNCTION                                                            
*	RTC_IRQOneShotEnable
*
* DESCRIPTION                                                           
*   	This function is to setup that RTC interrupt is at oneshot mode
*	or at automatic reset mode. 
*
* CALLS  
*	It is called to setup that RTC interrupt is at oneshot mode
*	or at automatic reset mode. 
*
* PARAMETERS
*	oneShotEN:
*     ONE_SHOT_DIS, automatic reset mode
*     ONE_SHOT_EN, one shot mode
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void RTC_IRQOneShotEnable(kal_uint8 oneShotEN)
{
	if (oneShotEN == ONE_SHOT_DIS)
	{
		DRV_Reg(RTC_IRQ_EN) &= ~RTC_IRQ_EN_ONESHOT;
	}
	else
	{
		DRV_Reg(RTC_IRQ_EN) |= RTC_IRQ_EN_ONESHOT;
	}
#if defined(DRV_RTC_HW_CALI)
   RTC_write_trigger_wait();
#endif
}
//=================================================================
/*
* FUNCTION                                                            
*	RTC_Config
*
* DESCRIPTION                                                           
*   	Configure the RTC interrupt 
*
* CALLS  
*	This function is called to enable RTC interrupt
*
* PARAMETERS
*	AL_EN:
*		AL_EN_None: Alarm interrupt is disable.
*		AL_EN_bySEC: Alarm interrupt is issued by second.
*		AL_EN_byMIN: Alarm interrupt is issued by minute.
*	TC_EN:
*		TC_EN_None: TC interrupt is disable
*		TC_EN_bySEC: TC interrupt is issued by second.
*		TC_EN_byMIN: TC interrupt is issued by minute.
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void RTC_Config(kal_uint8 AL_EN,kal_uint8 TC_EN)
{
	kal_uint16 tmp;
	kal_uint16 BBPU;
   kal_uint32 savedMask;

   savedMask = SaveAndSetIRQMask();   
	tmp = DRV_Reg(RTC_IRQ_EN);
	tmp &=~RTC_IRQ_EN_ONESHOT;
	BBPU = DRV_Reg(RTC_BBPU);

#if defined(RTC_HW_CALIBRATION)
   /* Save user's configuration for Alarm and Time Clock settings. */
   if (TC_EN != TC_EN_NoChange)
      rtc_tc_int_var = TC_EN;
   if (cali_state == CAL_STATE_INIT)
   {
      /* In the calibration INIT state, we need "minute" interrupt. */
      if ((TC_EN != TC_EN_ChkS) && (TC_EN != TC_EN_ChkM))
         TC_EN = TC_EN_NoChange;
   }
   else if (cali_state == CAL_STATE_START)
   {
      if (one_time_cali == KAL_TRUE)
      {
         /* We need "seconds" interrupt. */
         if (TC_EN != TC_EN_ChkS)
            TC_EN = TC_EN_NoChange;
      }
      else
      {
         /* We need "minute" interrupt. */
         if ((TC_EN != TC_EN_ChkS) && (TC_EN != TC_EN_ChkM))
            TC_EN = TC_EN_NoChange;
      }
   }
#elif defined(RTC_SW_CALIBRATION)
   /* Save user's configuration for Alarm and Time Clock settings. */
   if (AL_EN != AL_EN_NoChange)
      rtc_al_int_var = AL_EN;
   if (TC_EN != TC_EN_NoChange)
      rtc_tc_int_var = TC_EN;
   if (cali_state == CAL_STATE_INIT)
   {
      /* In the calibration INIT state, we need "second" interrupt. */
      if (TC_EN != TC_EN_ChkS)
         TC_EN = TC_EN_NoChange;
   }
   else if (cali_state == CAL_STATE_START)
   {
      /* In the calibration START state, we need "minute" interrupt. */
      if ((TC_EN != TC_EN_ChkS) && (TC_EN != TC_EN_ChkM))
         TC_EN = TC_EN_NoChange;
   }
#endif /* RTC_SW_CALIBRATION */
	switch(AL_EN)
	{
		case AL_EN_None:
			tmp &= ~RTC_IRQ_EN_AL; 		/*RTC_ALIRQEnable(KAL_FALSE);*/
			BBPU &=~(RTC_BBPU_ALARM_SW);/*0227 TY adds*/
			break;
		
		case AL_EN_ChkS:
			tmp |= RTC_IRQ_EN_AL;
			DRV_WriteReg(RTC_AL_MASK,(~RTC_AL_MASK_SEC));
			BBPU |=(RTC_BBPU_ALARM_SW);/*0227 TY adds*/
			break;
		
		case AL_EN_ChkMS:
			tmp |= RTC_IRQ_EN_AL;
			DRV_WriteReg(RTC_AL_MASK,(~RTC_AL_MASK_MIN));
			BBPU |=(RTC_BBPU_ALARM_SW);/*0227 TY adds*/
			break;
      
      case AL_EN_ChkHMS:
         tmp |= RTC_IRQ_EN_AL;
         DRV_WriteReg(RTC_AL_MASK,(~RTC_AL_MASK_HOU));
         BBPU |=(RTC_BBPU_ALARM_SW);/*0227 TY adds*/
			break;
	   
	   case AL_EN_ChkDHMS:
	      tmp |= RTC_IRQ_EN_AL;
	      DRV_WriteReg(RTC_AL_MASK,(~RTC_AL_MASK_DOM));
	      BBPU |=(RTC_BBPU_ALARM_SW);/*0227 TY adds*/
			break;
		
		case AL_EN_ChkWHMS:
		   tmp |= RTC_IRQ_EN_AL;
		   DRV_WriteReg(RTC_AL_MASK,(~RTC_AL_MASK_DOW));
		   BBPU |=(RTC_BBPU_ALARM_SW);/*0227 TY adds*/
			break;
			
	   case AL_EN_ChkMDHMS:
	      tmp |= RTC_IRQ_EN_AL;
	      DRV_WriteReg(RTC_AL_MASK,(~RTC_AL_MASK_MTH));
	      BBPU |=(RTC_BBPU_ALARM_SW);/*0227 TY adds*/
			break;
			
	   case AL_EN_ChkYMDHMS:
	      tmp |= RTC_IRQ_EN_AL;
	      DRV_WriteReg(RTC_AL_MASK,(~RTC_AL_MASK_YEA));
	      BBPU |=(RTC_BBPU_ALARM_SW);/*0227 TY adds*/
			break;
			
	   case AL_EN_NoChange:
	      break;

		default:
			break;
	}

	switch(TC_EN)
	{
		case TC_EN_None:
			tmp &= ~RTC_IRQ_EN_TC;
			break;
		
		case TC_EN_ChkS:
			tmp |= RTC_IRQ_EN_TC;
			DRV_WriteReg(RTC_CII_EN,RTC_CII_EN_SEC);
			break;
		
		case TC_EN_ChkM:
			tmp |= RTC_IRQ_EN_TC;
			DRV_WriteReg(RTC_CII_EN,RTC_CII_EN_MIN);
			break;
			
	   case TC_EN_ChkH:
	      tmp |= RTC_IRQ_EN_TC;
	      DRV_WriteReg(RTC_CII_EN,RTC_CII_EN_HOU);
			break;
		
		case TC_EN_ChkD:
	      tmp |= RTC_IRQ_EN_TC;
	      DRV_WriteReg(RTC_CII_EN,RTC_CII_EN_DOM);
			break;
		
		case TC_EN_ChkW:
	      tmp |= RTC_IRQ_EN_TC;
	      DRV_WriteReg(RTC_CII_EN,RTC_CII_EN_DOW);
			break;
			
		case TC_EN_ChkMon:
	      tmp |= RTC_IRQ_EN_TC;
	      DRV_WriteReg(RTC_CII_EN,RTC_CII_EN_MTH);
			break;
			
		case TC_EN_ChkY:
	      tmp |= RTC_IRQ_EN_TC;
	      DRV_WriteReg(RTC_CII_EN,RTC_CII_EN_YEA);
			break;
    
      case TC_EN_NoChange:
         break;
         
		default:
			break;
	}
	DRV_WriteReg(RTC_IRQ_EN,tmp);
	DRV_WriteReg(RTC_BBPU,(BBPU|RTC_BBPU_KEY));/*0227 TY adds*/
#if defined(DRV_RTC_HW_CALI)
   DRV_WriteReg(RTC_WRTGR, RTC_WRTGR_WRTGR);
   //RTC_write_trigger();
#endif /* DRV_RTC_HW_CALI */
	RestoreIRQMask(savedMask);
}
#endif /*!defined(__FUE__)*/


/*
* FUNCTION                                                            
*	RTC_InitTC_Time
*
* DESCRIPTION                                                           
*   	Setup the current time
*
* CALLS  
*	This function is called to setup the current time
*
* PARAMETERS
*	rtctime: the current time.
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void RTC_InitTC_Time(t_rtc *rtctime)		//validate
{
   kal_uint32 savedMask=0;
#if !defined(DRV_RTC_HW_CALI)
   kal_uint32 loop=0;
#endif /* DRV_RTC_HW_CALI */
   
#if defined(RTC_SW_CALIBRATION)
   if(rtc_timer_id!=0)
   {
      cali_state = CAL_STATE_RESET;
   	kal_cancel_timer(rtc_timer_id);
   }	
#endif /* RTC_SW_CALIBRATION */
	
#if !defined(__FUE__)
   savedMask = SaveAndSetIRQMask();   
#endif /*!defined(__FUE__)*/
   /*update time*/
   DRV_WriteReg(RTC_TC_SEC,rtctime->rtc_sec);
	DRV_WriteReg(RTC_TC_MIN,rtctime->rtc_min);
	DRV_WriteReg(RTC_TC_HOU,rtctime->rtc_hour);
	DRV_WriteReg(RTC_TC_DOM,rtctime->rtc_day);
	/*DRV_WriteReg(RTC_TC_DOW,rtctime->rtc_wday);*/
	DRV_WriteReg(RTC_TC_MTH,rtctime->rtc_mon);
	DRV_WriteReg(RTC_TC_YEA,rtctime->rtc_year);
#if !defined(__FUE__)
	RestoreIRQMask(savedMask);
#endif /*!defined(__FUE__)*/
	
#if defined(DRV_RTC_HW_CALI)
   RTC_write_trigger_wait();
#else /* DRV_RTC_HW_CALI */
	for(loop=0;loop<1000;loop++){};
#endif /* DRV_RTC_HW_CALI */
#if defined(RTC_HW_CALIBRATION)
   cali_state = CAL_STATE_NONE;
   rtc_cali_init(0);
#elif defined(RTC_SW_CALIBRATION)
	/*reset calibration, start after rtc initialization*/
   if(rtc_timer_id!=0)
   {
      next_current_time = *rtctime;
   	rtc_cali_init((void*)rtc_timer_id);

     /* save current time to nvram */
      rtc_nvram_s.time_valid = KAL_TRUE;
      rtc_nvram_s.rtc_time = next_current_time;
      rtc_write_to_nvram();
   }	
#endif /* RTC_SW_CALIBRATION */
	
	#ifdef RTC_Test
	RTC_delay();
	#endif
}

#if defined(RTC_SW_CALIBRATION)
/*
* FUNCTION                                                            
*	RTC_Cali_Time
*
* DESCRIPTION                                                           
*   	update the current time
*
* CALLS  
*	This function is to update the current time
*
* PARAMETERS
*	rtctime: the current time.
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void RTC_Cali_Time(t_rtc *rtctime)		//validate
{   
   /*update time*/
   DRV_WriteReg(RTC_TC_SEC,rtctime->rtc_sec);
	DRV_WriteReg(RTC_TC_MIN,rtctime->rtc_min);
	DRV_WriteReg(RTC_TC_HOU,rtctime->rtc_hour);
	DRV_WriteReg(RTC_TC_DOM,rtctime->rtc_day);
	DRV_WriteReg(RTC_TC_MTH,rtctime->rtc_mon);
	DRV_WriteReg(RTC_TC_YEA,rtctime->rtc_year);	
}
/*
* FUNCTION                                                            
*	RTC_Check_Alarm
*
* DESCRIPTION                                                           
*   	check if alarm expires after calibrating time
*
* CALLS  
*	This function is to check if alarm expires after calibrating time
*
* PARAMETERS
*	rtctime: the current time.
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void RTC_Check_Alarm(t_rtc rtctime)		//validate
{   
   kal_uint8 irq=0;
   t_rtc alarm_time, current_time;
   kal_uint32 alarm_sec=0, current_sec=0, new_time=0;

   irq = DRV_Reg(RTC_IRQ_EN);
   /*configure alarm or not*/
   if(irq&RTC_IRQ_EN_AL)
   {
      RTC_GetALTime(&alarm_time);
      RTC_GetTime(&current_time);
      if(alarm_time.rtc_hour==0)
         alarm_sec=(kal_uint32)(24*3600+alarm_time.rtc_min*60+alarm_time.rtc_sec);
      else
         alarm_sec=(kal_uint32)(alarm_time.rtc_hour*3600+alarm_time.rtc_min*60+alarm_time.rtc_sec);
      if(current_time.rtc_hour==0)
         current_sec=(kal_uint32)(24*3600+current_time.rtc_min*60+current_time.rtc_sec);
      else
         current_sec=(kal_uint32)(current_time.rtc_hour*3600+current_time.rtc_min*60+current_time.rtc_sec);   
      /*exceed alarm or not*/         
      if(current_sec<alarm_sec)            
      {
         if(rtctime.rtc_hour==0)
            new_time=(kal_uint32)(24*3600+rtctime.rtc_min*60+rtctime.rtc_sec);
         else
            new_time=(kal_uint32)(rtctime.rtc_hour*3600+rtctime.rtc_min*60+rtctime.rtc_sec);   
         /*change alarm or not*/   
         if(new_time>=alarm_sec)               
         {
             RTC_SetAlarm(&rtctime);
         }   
      }   
   }	   
}
#endif /* RTC_SW_CALIBRATION */

/*
* FUNCTION                                                            
*	RTC_GetTime
*
* DESCRIPTION                                                           
*   	Obtain the current time
*
* CALLS  
*	This function is called to obtain the current time
*
* PARAMETERS
*	rtctime: the current time.
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void RTC_GetTime(t_rtc *rtctime )		//validate
{
#if !defined(__FUE__)
   kal_uint32 savedMask;

   savedMask = SaveAndSetIRQMask();   
#endif /* !defined(__FUE__) */
	rtctime->rtc_sec = DRV_Reg(RTC_TC_SEC);
	rtctime->rtc_min = DRV_Reg(RTC_TC_MIN);
	rtctime->rtc_hour = DRV_Reg(RTC_TC_HOU);
	rtctime->rtc_day = DRV_Reg(RTC_TC_DOM);
	rtctime->rtc_mon = DRV_Reg(RTC_TC_MTH);
	rtctime->rtc_wday = DRV_Reg(RTC_TC_DOW);
	rtctime->rtc_year = DRV_Reg(RTC_TC_YEA);
#if !defined(__FUE__)
	RestoreIRQMask(savedMask);
	#ifdef RTC_Test
	RTC_delay();
	#endif
#endif /* !defined(__FUE__) */
}

/*
* FUNCTION                                                            
*	RTC_SetAlarm
*
* DESCRIPTION                                                           
*   	Setup the alarm time
*
* CALLS  
*	This function is called to setup the alarm time
*
* PARAMETERS
*	rtctime: the expected alarm time.
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void RTC_SetAlarm(t_rtc *rtctime )		//validate 
{
	kal_uint32	loop;
#if !defined(__FUE__)
   //kal_uint32 savedMask=0;
   //savedMask = SaveAndSetIRQMask();
#endif /* !defined(__FUE__) */
    /* Add for loop to ensure that RTC alarm time has been written in. */
   for (loop = 0; loop < 1000000; loop++)
   {
      DRV_WriteReg(RTC_AL_SEC,rtctime->rtc_sec);
	   DRV_WriteReg(RTC_AL_MIN,rtctime->rtc_min);
	   DRV_WriteReg(RTC_AL_HOU,rtctime->rtc_hour);
	   DRV_WriteReg(RTC_AL_DOM,rtctime->rtc_day);
	   DRV_WriteReg(RTC_AL_MTH,rtctime->rtc_mon);
	   DRV_WriteReg(RTC_AL_YEA,rtctime->rtc_year);
      #if defined(DRV_RTC_HW_CALI)
      RTC_write_trigger();
      #endif /*DRV_RTC_HW_CALI*/
      if ((DRV_Reg(RTC_AL_SEC) == rtctime->rtc_sec) && (DRV_Reg(RTC_AL_MIN) == rtctime->rtc_min)
         && (DRV_Reg(RTC_AL_HOU) == rtctime->rtc_hour) && (DRV_Reg(RTC_AL_DOM) == rtctime->rtc_day)
         && (DRV_Reg(RTC_AL_MTH) == rtctime->rtc_mon) && (DRV_Reg(RTC_AL_YEA) == rtctime->rtc_year))
   	     break;
   }
#if !defined(__FUE__)
   //RestoreIRQMask(savedMask);
	#ifdef RTC_Test
	RTC_delay();
	#endif
#endif /* !defined(__FUE__) */
}

/*
* FUNCTION                                                            
*	RTC_GetALTime
*
* DESCRIPTION                                                           
*   	Obtain the alarm time
*
* CALLS  
*	This function is called to obtain the alarm time setting
*
* PARAMETERS
*	rtctime: the alarm time.
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void RTC_GetALTime(t_rtc *rtctime )		//validate
{
	rtctime->rtc_sec = DRV_Reg(RTC_AL_SEC);
	rtctime->rtc_min = DRV_Reg(RTC_AL_MIN);
	rtctime->rtc_hour = DRV_Reg(RTC_AL_HOU);
	rtctime->rtc_day = DRV_Reg(RTC_AL_DOM);
	rtctime->rtc_mon = DRV_Reg(RTC_AL_MTH);
	rtctime->rtc_wday = DRV_Reg(RTC_AL_DOW);
	rtctime->rtc_year = DRV_Reg(RTC_AL_YEA);
	#ifdef RTC_Test
	RTC_delay();
	#endif
}
#if !defined(__FUE__)
//=================================================================
/*
* FUNCTION                                                            
*	RTC_HISR
*
* DESCRIPTION                                                           
*   	RTC interrupt handler
*
* CALLS  
*	This function is called when RTC intr. is coming
*
* PARAMETERS
*	None
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void RTC_HISR(void)
{
	kal_uint16 status;

#if defined(DRV_RTC_PWRON_BBPU_POLARITY)
   kal_uint16 BBPU;
   kal_uint16 POLAR;
   kal_uint16 PWRSW;
   
   BBPU = DRV_Reg(RTC_BBPU);
   POLAR = BBPU & RTC_BBPU_PWR_POLARITY;
   POLAR >>= 1;
   PWRSW = BBPU & RTC_BBPU_PWR_SW;
   #if defined(DRV_RTC_BBPU_AS_6205)
   PWRSW >>= 2;
   #else /*!MT6205*/
   PWRSW >>= 4;
   #endif   /*MT6205*/

   if (POLAR != PWRSW)
   {
      #ifndef __L1_STANDALONE__
      IRQMask(IRQ_RTC_CODE);
      ASSERT(0);
      return;
      #endif   /*__L1_STANDALONE__*/
   }
#endif   /*DRV_RTC_PWRON_BBPU_POLARITY*/ 
#if 0 /*remove this part because rtc initialization is before latch power*/
#if defined(DRV_RTC_PWRON_BBPU_SW)
/* under construction !*/
/* under construction !*/
      #ifndef __L1_STANDALONE__
/* under construction !*/
/* under construction !*/
      #endif   /*__L1_STANDALONE__*/
/* under construction !*/
#endif   /*DRV_RTC_PWRON_BBPU_SW*/
#endif 
   
   status = DRV_Reg(RTC_IRQ_STATUS);
	if (status & RTC_IRQ_STATUS_AL_STAT)
	{
		RTC_CALLBAC.rtc_alfunc();	
      #if defined(RTC_AS_MT6218)
		// set AUTO_PDN bit of RTC_BBPU again which is cleared by RTC 
		{
		   kal_uint16 reg;
		
		   reg = DRV_Reg(RTC_BBPU);
		   reg |= (RTC_BBPU_KEY|RTC_BBPU_AUTOPDN); 
		   DRV_WriteReg(RTC_BBPU, reg );
         #if defined(DRV_RTC_HW_CALI)
         RTC_write_trigger();
         #endif /*DRV_RTC_HW_CALI*/
		}		
		#endif		
	}
	if (status & RTC_IRQ_STATUS_TC_STAT)
	{
		RTC_CALLBAC.rtc_tcfunc();
		
	}
	
	IRQClearInt(IRQ_RTC_CODE);
	IRQUnmask(IRQ_RTC_CODE);
}

void RTC_LISR(void)
{
   IRQMask(IRQ_RTC_CODE);
   //kal_activate_hisr(RTCConfig.hisr);
    drv_active_hisr(DRV_RTC_HISR_ID);
}
#endif /*!defined(__FUE__)*/
/*
* FUNCTION                                                            
*	RTC_isFisrtOn
*
* DESCRIPTION                                                           
*   	Check whether RTC is first on
*
* CALLS  
*	This function is called to check whether RTC is first on
*
* PARAMETERS
*	None
*	
* RETURNS
*	KAL_TRUE: RTC is first on
*	KAL_FALSE: RTC is not first on
*
* GLOBALS AFFECTED
*   external_global
*/
kal_bool RTC_isFisrtOn(void)		//validate
{
	kal_uint16 key1 = DRV_Reg(RTC_POWERKEY1);
	kal_uint16 key2 = DRV_Reg(RTC_POWERKEY2);
	
	if ((key1 == RTC_POWERKEY1_KEY)&&(key2 == RTC_POWERKEY2_KEY))
	{
	   /*TY adds this 2004/10/21 to record this is first power on*/
	   //First_PowerOn=KAL_FALSE;
		return KAL_FALSE;
	}
	else
	{
	   /*TY adds this 2004/10/21 to record if this is first power on*/
	   First_PowerOn=KAL_TRUE;
		return KAL_TRUE;
	}
}
#if !defined(__FUE__)
/*
* FUNCTION                                                            
*	RTC_is_MS_FirstPowerOn
*
* DESCRIPTION                                                           
*   	Check whether RTC is first power on
*
* CALLS  
*	This function is called by MMI. MMI wants to knows this status
*  whenever he wants but the function "RTC_isFisrtOn" is only valid
*  before calling DRV_POWERON function
*
* PARAMETERS
*	None
*	
* RETURNS
*	KAL_TRUE: RTC is first on
*	KAL_FALSE: RTC is not first on
*
* GLOBALS AFFECTED
*   external_global
*/
/*TY adds this 2004/10/21 to record if this is first power on*/	   
kal_bool RTC_is_MS_FirstPowerOn(void)		//validate
{
	if (First_PowerOn==KAL_FALSE)
	{	   
		return KAL_FALSE;
	}
	else
	{	   
		return KAL_TRUE;
	}
}
#endif /*!defined(__FUE__)*/

/*
* FUNCTION                                                            
*	RTC_setPWRKey
*
* DESCRIPTION                                                           
*   	Setup RTC power key
*
* CALLS  
*	This function is called when RTC is first on
*
* PARAMETERS
*	None
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void RTC_setPWRKey(void)		//validate
{
   DRV_WriteReg(RTC_POWERKEY1,RTC_POWERKEY1_KEY);
	DRV_WriteReg(RTC_POWERKEY2,RTC_POWERKEY2_KEY);
}

#if !defined(__FUE__)

#if defined(RTC_HW_CALIBRATION)
/*
* FUNCTION                                                            
*	rtc_get_cali_offset
*
* DESCRIPTION                                                           
*   	To get the repeat calibration count value from register
*
* CALLS  
*	This function is called when doing RTC HW calibration
*
* PARAMETERS
*	None
*	
* RETURNS
*	the calibration count:  -0x40~0x3f (-64~63)
*
* GLOBALS AFFECTED
*   external_global
*/
kal_int8 rtc_get_cali_offset(void)
{
   kal_uint16   data;
   kal_int8     ret_val=0;

   data = DRV_Reg(RTC_CALI);
   if (data&0x0040)
   {
      ret_val = (kal_int8)((~(data)+1)&0x007f);
      ret_val = -ret_val;
   }
   else
   {
      ret_val = (kal_int8)data;
   }
   return ret_val;
}

/*
* FUNCTION                                                            
*	rtc_do_repeat_cali
*
* DESCRIPTION                                                           
*   	To set the repeat calibration count value to register
*
* CALLS  
*	This function is called when doing RTC HW calibration
*
* PARAMETERS
*	None
*	
* RETURNS
*	the calibration count:  -0x40~0x3f (-64~63)
*
* GLOBALS AFFECTED
*   external_global
*/
void rtc_do_repeat_cali(kal_int32  inaccurate_cnt)
{
   kal_int32   cali_cnt;
   kal_uint8   value;

   cali_cnt = inaccurate_cnt/RTC_CALI_REPEAT_TOTAL_CNT;
   /* divided by total count from last repeat calibration to this time. No that we don't do repeat
      calibration when there's no inaccurate count. */
   cali_cnt = cali_cnt/(1+no_diff_cnt);
   #ifdef RTC_CAL_DEBUG
   kal_prompt_trace(MOD_RTC_HISR, "Adjust %d count for repeat calibration register\r\n", cali_cnt);
   #endif /* RTC_CAL_DEBUG */
   cali_cnt += rtc_get_cali_offset();
   #ifdef RTC_CAL_DEBUG
   kal_prompt_trace(MOD_RTC_HISR, "Now the value for repeat calibration is %d\r\n", cali_cnt);
   #endif /* RTC_CAL_DEBUG */

   if (cali_cnt > RTC_CALI_REPEAT_MAX)
   {
      #ifdef RTC_CAL_DEBUG
      kal_prompt_trace(MOD_RTC_HISR, "Warning!! value %d exceeds repeat calibration MAX value!\r\n", cali_cnt);
      #endif /* RTC_CAL_DEBUG */
      cali_cnt = RTC_CALI_REPEAT_MAX;
   }
   else if (cali_cnt < RTC_CALI_REPEAT_MIN)
   {
      #ifdef RTC_CAL_DEBUG
      kal_prompt_trace(MOD_RTC_HISR, "Warning!! value %d exceeds repeat calibration MIN value!\r\n", cali_cnt);
      #endif /* RTC_CAL_DEBUG */
      cali_cnt = RTC_CALI_REPEAT_MIN;
   }
   if (cali_cnt < 0)
   {
      value = ((kal_uint8)(~(-cali_cnt)+1)) & 0x7f;
   }
   else
   {
      value = (kal_uint8)cali_cnt;
   }
   DRV_WriteReg(RTC_CALI, value);
}

/*
* FUNCTION                                                            
*	rtc_do_one_time_cali
*
* DESCRIPTION                                                           
*   	To do the one shot calibration
*
* CALLS  
*	This function is called when doing RTC HW calibration
*
* PARAMETERS
*	None
*	
* RETURNS
*	KAL_TRUE: need to do more one shot calibraiton
*  KAL_FASLE: No need to do more one shot calibration
*
* GLOBALS AFFECTED
*   external_global
*/
kal_bool rtc_do_one_time_cali(void)
{
   kal_uint16  value;

   if (inaccurate_total_cnt > RTC_CALI_ONE_TIME_MAX)
   {
      /* Exceed max value. So calibration with RTC_CALI_ONE_TIME_MAX */
      inaccurate_total_cnt -= RTC_CALI_ONE_TIME_MAX;
      value = RTC_CALI_ONE_TIME_MAX;
      #ifdef RTC_CAL_DEBUG
      kal_prompt_trace(MOD_RTC_HISR, "Do one shot calibration for %d counts, remains: %d counts\r\n", RTC_CALI_ONE_TIME_MAX, inaccurate_total_cnt);
      #endif /* RTC_CAL_DEBUG */
   }
   else if (inaccurate_total_cnt < RTC_CALI_ONE_TIME_MIN)
   {
      /* Less than the min value. So calibration with RTC_CALI_ONE_TIME_MIN */
      inaccurate_total_cnt -= RTC_CALI_ONE_TIME_MIN;
      /* 2's complement. */
      value = (~(-RTC_CALI_ONE_TIME_MIN) + 1) & 0x0fff;
      #ifdef RTC_CAL_DEBUG
      kal_prompt_trace(MOD_RTC_HISR, "Do one shot calibration for %d counts, remains: %d counts\r\n", RTC_CALI_ONE_TIME_MIN, inaccurate_total_cnt);
      #endif /* RTC_CAL_DEBUG */
   }
   else
   {
      #ifdef RTC_CAL_DEBUG
      kal_prompt_trace(MOD_RTC_HISR, "Do one shot calibration for %d counts, remains: 0 counts\r\n", inaccurate_total_cnt);
      #endif /* RTC_CAL_DEBUG */
      /* calibration with inaccurate_total_cnt */
      if (inaccurate_total_cnt < 0)
      {
      /* 2's complement. */
         value = ((kal_uint16)(~(-inaccurate_total_cnt)+1)) & 0x0fff;
      }
      else
      {
         value = (kal_uint16)inaccurate_total_cnt;
      }
      inaccurate_total_cnt = 0;
   }
   #ifdef RTC_CAL_DEBUG
   kal_prompt_trace(MOD_RTC_HISR, "Write to one shot calib. value: %x\r\n", value);
   #endif /* RTC_CAL_DEBUG */
   DRV_WriteReg(RTC_DIFF, value);
   if (inaccurate_total_cnt==0)
   {
      #ifdef RTC_CAL_DEBUG
      kal_prompt_trace(MOD_RTC_HISR, "Finish one shot calibration!!\r\n");
      #endif /* RTC_CAL_DEBUG */
      return KAL_FALSE;
   }
   else
      return KAL_TRUE;
}
#endif /* RTC_HW_CALIBRATION */

/*
* FUNCTION                                                            
*	RTC_TCintr
*
* DESCRIPTION                                                           
*   	RTC Time tick interrupt handler
*
* CALLS  
*	This function is called to handle TC interrupt
*
* PARAMETERS
*	None
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void RTC_TCintr(void)
{
#ifndef L4_NOT_PRESENT
	ilm_struct *RTC_ilm;
	RTC_Primitive *RTC_Prim;
#if defined(RTC_HW_CALIBRATION)
   kal_uint32 frame_tick;
   t_rtc current_time;
   kal_uint32 diff_frame_tick;

   if (cali_state != CAL_STATE_NONE)
   {
      kal_bool need_trigger;
      kal_int32  inaccurate_frame_tick = 0;

      need_trigger = KAL_FALSE;
      RTC_GetTime(&current_time);
      if (current_time.rtc_sec == 0)
      {
         if (cali_state == CAL_STATE_INIT)
         {
            /* Get the L1 frame tick for reference. */
            rtc_current_frame_tick = L1I_GetTimeStamp();
            cali_state = CAL_STATE_START;
            #ifdef RTC_CAL_DEBUG
            kal_prompt_trace(MOD_RTC_HISR, "Start to measure RTC inaccurate. current time - (%d:%d:%d)",
               current_time.rtc_hour, current_time.rtc_min, current_time.rtc_sec);
            kal_prompt_trace(MOD_RTC_HISR, "ini L1 ticks=%d\r\n",rtc_current_frame_tick);
            #endif /* RTC_CAL_DEBUG */
         }
         else if (cali_state == CAL_STATE_START)
         {
            tc_min_expire_cnt++;
            if (RTC_CALI_PERIOD_MINS<=tc_min_expire_cnt)
            {
               tc_min_expire_cnt = 0;
               /* Get the L1 frame tick for computation. */
               frame_tick = L1I_GetTimeStamp();
               if(frame_tick>=rtc_current_frame_tick)
   	            diff_frame_tick=(frame_tick - rtc_current_frame_tick);
               else
               {
   	            diff_frame_tick=(0xffffffff-rtc_current_frame_tick+frame_tick+1);
               }
               /* Compute the difference between expected frame tick count and real frame tick count. */
               inaccurate_frame_tick = diff_frame_tick - RTC_CALI_TICK_VALUE;
               #ifdef RTC_CAL_DEBUG
               kal_prompt_trace(MOD_RTC_HISR, "Finish to measure RTC inaccurate for %d mins. current time - (%d:%d:%d)",
                  RTC_CALI_PERIOD_MINS, current_time.rtc_hour, current_time.rtc_min, current_time.rtc_sec);
               kal_prompt_trace(MOD_RTC_HISR, "L1 ticks=%d, inaccurate ticks=%d\r\n",frame_tick, inaccurate_frame_tick);
               #endif /* RTC_CAL_DEBUG */
               /* The next expected frame tick count. */
               rtc_current_frame_tick += RTC_CALI_TICK_VALUE;
               if (inaccurate_frame_tick == 0)
               {
                  no_diff_cnt++;
                  #ifdef RTC_CAL_DEBUG
                  kal_prompt_trace(MOD_RTC_HISR, "No difference and no need do calibration!!  no_diff_cnt=%d \r\n", no_diff_cnt);
                  #endif /* RTC_CAL_DEBUG */
               }
               else
               {
                  if (inaccurate_frame_tick < 0)
                  {
                     /* Note that there are 650/3 frames ticks per second. */
                     inaccurate_total_cnt = (-inaccurate_frame_tick)*rtc_current_freq_8secs*3/8/650;
                     inaccurate_total_cnt = -inaccurate_total_cnt;
                  }
                  else
                  {
                     inaccurate_total_cnt = inaccurate_frame_tick*rtc_current_freq_8secs*3/8/650;
                  }
                  #ifdef RTC_CAL_DEBUG
                  kal_prompt_trace(MOD_RTC_HISR, "Do repeat calibration for %d counts\r\n", inaccurate_total_cnt);
                  #endif /* RTC_CAL_DEBUG */
                  rtc_do_repeat_cali(inaccurate_total_cnt);
                  one_time_cali = KAL_TRUE;
                  /* Enable TC seconds interrupt */
                  if (rtc_tc_int_var != TC_EN_ChkS)
   		            DRV_WriteReg(RTC_CII_EN,RTC_CII_EN_SEC);
                  need_trigger = KAL_TRUE;
                  no_diff_cnt = 0;
               }
            }
            else
            {
               #ifdef RTC_CAL_DEBUG
               kal_prompt_trace(MOD_RTC_HISR, "In progress for HW RTC calibration. current time - (%d:%d:%d)",
                  current_time.rtc_hour, current_time.rtc_min, current_time.rtc_sec);
               #endif /* RTC_CAL_DEBUG */
            }
         }
      } /* (current_time.rtc_sec == 0) */
      if (one_time_cali == KAL_TRUE)
      {
         kal_bool ret_value;

         ret_value = rtc_do_one_time_cali();
         need_trigger = KAL_TRUE;
         if (ret_value == KAL_FALSE)
         {
            /* No need to do one shot calibration. Change back to minute interrupt if needed. */
            if (rtc_tc_int_var != TC_EN_ChkS)
            {
   		      DRV_WriteReg(RTC_CII_EN,RTC_CII_EN_MIN);
            }
            one_time_cali = KAL_FALSE;
         }
      }
      if (need_trigger == KAL_TRUE)
      {
         RTC_write_trigger();
      }
#elif defined(RTC_SW_CALIBRATION)
   t_rtc current_time;
   kal_uint32 frame_tick;

   if (cali_state != CAL_STATE_NONE)
   {
      RTC_GetTime(&current_time);
      if (cali_state == CAL_STATE_INIT)
      {
   	   kal_uint16 reg_comm2;
   	   //kal_uint16 tmp;

	      //tmp = DRV_Reg(RTC_IRQ_EN);
	      //tmp &=~RTC_IRQ_EN_ONESHOT;
		   //tmp |= RTC_IRQ_EN_TC;
   	   //DRV_WriteReg(RTC_IRQ_EN,tmp);

         #ifdef RTC_CAL_DEBUG2
         kal_prompt_trace(MOD_RTC_HISR, "Start to do poweroff calibration");
         #endif /* RTC_CAL_DEBUG */
         /* Change to calibration start state. */
         cali_state = CAL_STATE_START;
         if (pwroff_inacc_ticks != 0)
         {
            kal_uint16 hours, mins, secs;
            kal_bool neg = KAL_FALSE;

            tc_min_expire_cnt = 0;
            /* Check the time has to be forward or backward. */
            if (pwroff_inacc_ticks < 0)
            {
               neg = KAL_TRUE;
               pwroff_inacc_ticks = -pwroff_inacc_ticks;
            }
            /* Calculate the time shift for hour(60*13000), minute(13000) and second(650/3). */
            hours = pwroff_inacc_ticks/(13000*60);
            pwroff_inacc_ticks = pwroff_inacc_ticks%(13000*60);
            mins = pwroff_inacc_ticks/13000;
            pwroff_inacc_ticks = pwroff_inacc_ticks%13000;
            secs = pwroff_inacc_ticks*3/650;
            #ifdef RTC_CAL_DEBUG2
            kal_prompt_trace(MOD_RTC_HISR, "current time before poweroff calibration- (%d:%d:%d)",
               current_time.rtc_hour, current_time.rtc_min, current_time.rtc_sec);
            #endif /* RTC_CAL_DEBUG */
            /* Calculate the ticks to reach the nearest second boundary. */
            if (neg==KAL_TRUE)
            {
               pwroff_inacc_ticks = pwroff_inacc_ticks - (secs*650/3);
               rtc_backward_time(&current_time, hours, mins, secs);
            }
            else
            {
               secs++;
               pwroff_inacc_ticks = (secs*650/3) - pwroff_inacc_ticks;
               rtc_forward_time(&current_time, hours, mins, secs);
            }
            /* Set the correct time here. */
            RTC_Cali_Time(&current_time);
            #ifdef RTC_CAL_DEBUG2
            kal_prompt_trace(MOD_RTC_HISR, "current time after poweroff calibration- (%d:%d:%d)",
               current_time.rtc_hour, current_time.rtc_min, current_time.rtc_sec);
            #endif /* RTC_CAL_DEBUG */
            if (pwroff_inacc_ticks != 0)
            {
               #ifdef RTC_CAL_DEBUG2
               kal_prompt_trace(MOD_RTC_HISR, "wait %d ticks to do second poweroff calibration",
                  pwroff_inacc_ticks);
               #endif /* RTC_CAL_DEBUG */
               /* Still some ticks hasn't been calibrated. So change to init2 state */
               cali_state = CAL_STATE_INIT2;
               /* Save the correct time in: next_current_time */
               next_current_time = current_time;
               /* We'll write the correct time again when the exact correspoding time(second) comes by using KAL timer. */
               kal_set_timer(rtc_timer_id, (kal_timer_func_ptr)rtc_cali_init, NULL, pwroff_inacc_ticks,0);
            }
         }
         /* validate rtc nvram data */
   	   reg_comm2 = DRV_Reg(DRV_COMM_REG2);
         reg_comm2 |= DRV_COMM_REG2_RTC_NVRAM;
         DRV_WriteReg(DRV_COMM_REG2,reg_comm2);    

         /* Send msg to write current time to nvram */
         rtc_nvram_s.time_valid = KAL_TRUE;
         rtc_nvram_s.rtc_time = current_time;
         rtc_write_to_nvram();

         /* Turn on the TC minute interrupt if necessary. */
         if ((rtc_tc_int_var != TC_EN_ChkS) && (rtc_tc_int_var != TC_EN_ChkM))
   		   DRV_WriteReg(RTC_CII_EN,RTC_CII_EN_MIN);
         if (pwroff_inacc_ticks == 0)
         {
            tick_left=0;
            one_third_tick_count = 0;

            /* We may start calibration here. */
            next_current_time = current_time;
            kal_set_timer(rtc_timer_id, (kal_timer_func_ptr)rtc_timer, NULL, rtc_cali_tick_value+rtc_cali_tick_safe_margin,0);
            #if (!defined(__L1_STANDALONE__)) 
            frame_tick=L1I_GetTimeStamp();
            #endif
            #ifdef RTC_CAL_DEBUG
            kal_prompt_trace(MOD_RTC_HISR, "Start poweron calibration");
            kal_prompt_trace(MOD_RTC_HISR, "(%d:%d:%d): ",next_current_time.rtc_hour,next_current_time.rtc_min,next_current_time.rtc_sec);
            kal_prompt_trace(MOD_RTC_HISR, "ini tick=%d\r\n",frame_tick);                                                   
            #endif /* RTC_CAL_DEBUG */
            next_frame_tick=frame_tick+rtc_cali_tick_value;         
            rtc_get_next_time();    
         }
      }
      else if (cali_state == CAL_STATE_START)
      {
         /* rtc_sec is zero. Meaning it's TC minute expired. */
         if (current_time.rtc_sec == 0)
         {
            if (tc_min_expire_cnt == 0)
            {
               /* Save the frame stick as a refence. */
               frame_tick1=L1I_GetTimeStamp();
               #ifdef RTC_CAL_DEBUG2
               kal_prompt_trace(MOD_RTC_HISR, "Inaccuracy measurement start");
               #endif /* RTC_CAL_DEBUG */
            }
            else if (tc_min_expire_cnt == 60)
            {
               /* Get the frame stick after 60 minutes passed. */
               frame_tick2=L1I_GetTimeStamp();
               /* Calculate the frame tick number for 1 hr of RTC time. */
               if(frame_tick2>=frame_tick1) 
   	            frame_tick_1hr_diff=frame_tick2-frame_tick1 - 13000*60;   
               else
   	            frame_tick_1hr_diff=0xffffffff+frame_tick2-frame_tick1+1 - 13000*60;
               
               #ifdef RTC_CAL_DEBUG2
               kal_prompt_trace(MOD_RTC_HISR, "Inaccuracy measurement done for one hour: %d ticks", frame_tick_1hr_diff);
               #endif /* RTC_CAL_DEBUG */
               /* save frame_tick_1hr_diff(inaccuracy) to nvram here */
               //rtc_nvram_s.ticks_diff_valid = KAL_TRUE;
               //rtc_nvram_s.ticks_diff_per_hour = frame_tick_1hr_diff;
               //rtc_write_to_nvram();
            }
            tc_min_expire_cnt++;
         }
      }
#endif /* RTC_SW_CALIBRATION */
#if defined(RTC_HW_CALIBRATION) || defined(RTC_SW_CALIBRATION)
      /* Check user's configuration for Time Clock interrupt. */
	   switch(rtc_tc_int_var)
	   {
		   case TC_EN_None:
			   return;
			   break;
		   
		   case TC_EN_ChkS:
			   break;
		   
		   case TC_EN_ChkM:
            if (current_time.rtc_sec != 0)
               return;
			   break;
			   
	      case TC_EN_ChkH:
            if ((current_time.rtc_sec != 0) || (current_time.rtc_min != 0))
               return;
			   break;
		   
		   case TC_EN_ChkD:
		   case TC_EN_ChkW:
            if ((current_time.rtc_sec != 0) || (current_time.rtc_min != 0) ||(current_time.rtc_hour != 0))
               return;
			   break;
		   case TC_EN_ChkMon:
            if ((current_time.rtc_sec != 0) || (current_time.rtc_min != 0) ||(current_time.rtc_hour != 0) 
               ||(current_time.rtc_day != 1))
               return;
			   break;
			   
		   case TC_EN_ChkY:
            if ((current_time.rtc_sec != 0) || (current_time.rtc_min != 0) ||(current_time.rtc_hour != 0) 
               ||(current_time.rtc_day != 1) || (current_time.rtc_mon != 1))
               return;
			   break;
 
         case TC_EN_NoChange:
            break;
      
		   default:
			   break;
	   }
   } /*(cali_state != CAL_STATE_NONE)*/
   #ifdef RTC_CAL_DEBUG
   //frame_tick=L1I_GetTimeStamp();
   kal_prompt_trace(MOD_RTC_HISR, "TC interrupt for user\r\n");
   #endif /* RTC_CAL_DEBUG */
#endif /* defined(RTC_HW_CALIBRATION) || defined(RTC_SW_CALIBRATION) */

   //RTC_ilm = allocate_ilm(MOD_RTC_HISR);
   RTC_ilm = allocate_ilm(MOD_DRV_HISR);
   RTC_Prim = (RTC_Primitive*)
				   construct_local_para(sizeof(RTC_Primitive), TD_CTRL);
   RTC_Prim->rtc_ind = RTC_TC_IND;
   //RTC_ilm->src_mod_id = MOD_RTC_HISR;
   RTC_ilm->src_mod_id = MOD_DRV_HISR;
   RTC_ilm->dest_mod_id = MOD_UEM;
   RTC_ilm->sap_id = DRIVER_PS_SAP;
   RTC_ilm->msg_id = MSG_ID_DRVUEM_RTC_PERIOD_IND;
   RTC_ilm->local_para_ptr = (local_para_struct *)RTC_Prim;
	RTC_ilm->peer_buff_ptr = NULL;
   msg_send_ext_queue(RTC_ilm);
#endif   /*L4_NOT_PRESENT*/   
}

void RTC_ALintr(void)
{
   kal_uint16 BBPU;
#ifndef L4_NOT_PRESENT
	ilm_struct *RTC_ilm;
	RTC_Primitive *RTC_Prim;
#endif   /*L4_NOT_PRESENT*/ 
   BBPU = DRV_Reg(RTC_BBPU);
   BBPU &=~(RTC_BBPU_ALARM_SW);/*0227 TY adds*/
	DRV_WriteReg(RTC_BBPU,(BBPU|RTC_BBPU_KEY));/*0227 TY adds*/
#if defined(DRV_RTC_HW_CALI)
   RTC_write_trigger();
#endif /*DRV_RTC_HW_CALI*/
#ifndef L4_NOT_PRESENT
	
   //RTC_ilm = allocate_ilm(MOD_RTC_HISR);
   RTC_ilm = allocate_ilm(MOD_DRV_HISR);
   RTC_Prim = (RTC_Primitive*)
				   construct_local_para(sizeof(RTC_Primitive), TD_CTRL);
   RTC_Prim->rtc_ind = RTC_AL_IND;
   //RTC_ilm->src_mod_id = MOD_RTC_HISR;
   RTC_ilm->src_mod_id = MOD_DRV_HISR;
   RTC_ilm->dest_mod_id = MOD_UEM;
   RTC_ilm->sap_id = DRIVER_PS_SAP;
   RTC_ilm->msg_id = MSG_ID_DRVUEM_RTC_PERIOD_IND;
   RTC_ilm->local_para_ptr = (local_para_struct *)RTC_Prim;
	RTC_ilm->peer_buff_ptr = NULL;
   msg_send_ext_queue(RTC_ilm);
#endif   /*L4_NOT_PRESENT*/ 
   
}


#if defined(RTC_SW_CALIBRATION)
/*
* FUNCTION                                                            
*	rtc_write_to_nvram
*
* DESCRIPTION                                                           
*   	Save RTC SW calibration data to nvram
*
* CALLS  
*	This function is called internally for RTC SW calibration
*
* PARAMETERS
*	None
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*  None
*/
void rtc_write_to_nvram(void)
{
   ilm_struct *rtc_ilm_ptr=0;
   void  *parm_stream=0;
   void  *data_stream=0;
   kal_uint16 pdu_len;

   rtc_ilm_ptr = allocate_ilm(MOD_RTC_HISR);
   rtc_ilm_ptr->msg_id = MSG_ID_NVRAM_WRITE_REQ;

   parm_stream = construct_local_para(sizeof(nvram_write_req_struct), TD_CTRL);
   data_stream = construct_peer_buff(sizeof(rtc_nvram_data), 0, 0, TD_CTRL);

   ((nvram_write_req_struct*) parm_stream)->file_idx =  NVRAM_EF_RTC_DATA_LID;
   ((nvram_write_req_struct*) parm_stream)->para = 1;

   pdu_len = sizeof(rtc_nvram_data);
   kal_mem_cpy(get_pdu_ptr(data_stream, &pdu_len), (void*)&rtc_nvram_s, sizeof(rtc_nvram_data));

   rtc_ilm_ptr->local_para_ptr = (local_para_struct*) parm_stream;
   rtc_ilm_ptr->peer_buff_ptr = (peer_buff_struct*) data_stream;

   rtc_ilm_ptr->src_mod_id  = MOD_RTC_HISR;
   rtc_ilm_ptr->dest_mod_id = MOD_NVRAM;
   rtc_ilm_ptr->sap_id = PS_NVRAM_SAP;
   msg_send_ext_queue(rtc_ilm_ptr);
}

/*
* FUNCTION                                                            
*	rtc_compare_time
*
* DESCRIPTION                                                           
*  Compare the rtc time.
*
* CALLS  
*	This function is called internally for RTC SW calibration
*
* PARAMETERS
*	rtc_time1
*	rtc_time2
*
* RETURNS
*	KAL_TRUE if rtc_time1 > rtc_time2. Else, return KAL_FALSE
*
* GLOBALS AFFECTED
*  None
*/
kal_bool rtc_compare_time(t_rtc *rtc_time1, t_rtc *rtc_time2)
{
   if (rtc_time1->rtc_year < rtc_time2->rtc_year)
      return KAL_FALSE;
   else if (rtc_time1->rtc_year == rtc_time2->rtc_year)
   {
      if (rtc_time1->rtc_mon < rtc_time2->rtc_mon)
         return KAL_FALSE;
      else if (rtc_time1->rtc_mon == rtc_time2->rtc_mon)
      {
         if (rtc_time1->rtc_day < rtc_time2->rtc_day)
            return KAL_FALSE;
         else if (rtc_time1->rtc_day == rtc_time2->rtc_day)
         {
            if (rtc_time1->rtc_hour < rtc_time2->rtc_hour)
               return KAL_FALSE;
            else if (rtc_time1->rtc_hour == rtc_time2->rtc_hour)
            {
               if (rtc_time1->rtc_min < rtc_time2->rtc_min)
                  return KAL_FALSE;
               else if (rtc_time1->rtc_min == rtc_time2->rtc_min)
               {
                  if (rtc_time1->rtc_sec <= rtc_time2->rtc_sec)
                     return KAL_FALSE;
               }
            }
         }
      }
   }
   return KAL_TRUE;
}

/*
* FUNCTION                                                            
*	rtc_get_diff_time
*
* DESCRIPTION                                                           
*  Get the time different between 2 RTC time into hours and minute. Note that if the year difference is
*  more than 1 then we'll see it as invalid.
*
* CALLS  
*	This function is called internally for RTC SW calibration
*
* PARAMETERS
*	curr_time: INPUT for current RTC time
*	prev_time: INPUT for previous RTC time
*  ret_hours: OUTPUT for hours of time difference between current time and previous time
*  ret_mins: OUTPUT for minutes of time difference between current time and previous time
*
* RETURNS
*	KAL_TRUE: If the time difference is valid
*  KAL_FALSE: If the time difference is invalid such as curr_time is older, or the time difference is 
*             too large.
*
* GLOBALS AFFECTED
*  None
*/
kal_bool rtc_get_diff_time(t_rtc *curr_time, t_rtc *prev_time, kal_uint16 *ret_hours, kal_uint16 *ret_mins)
{
   kal_int16 secs;
   kal_int16 mins;
   kal_int32 hours;
   kal_int16 days;

   /* Invalid if the current time is older. */
   if (KAL_FALSE == rtc_compare_time(curr_time, prev_time))
      return KAL_FALSE;

   /* Invalid if the year difference is more than 1. */
   if (curr_time->rtc_year>(prev_time->rtc_year+1))
      return KAL_FALSE;

   days = 0;
   secs = 0;
   mins = 0;
   hours = 0;
   if (curr_time->rtc_sec < prev_time->rtc_sec)
   {
      secs = 60;
      mins = -1;
   }
   secs += (curr_time->rtc_sec - prev_time->rtc_sec);
   if (curr_time->rtc_min < (prev_time->rtc_min - mins))
   {
      mins += 60;
      hours = -1;
   }
   mins += (curr_time->rtc_min - prev_time->rtc_min);
   if (secs >= 30)
      mins++;
   if (curr_time->rtc_hour < (prev_time->rtc_hour - hours))
   {
      hours += 24;
      days = -1;
   }
   hours += (curr_time->rtc_hour - prev_time->rtc_hour);
   if ((curr_time->rtc_year==prev_time->rtc_year) && (curr_time->rtc_mon==prev_time->rtc_mon))
   {
      days += (curr_time->rtc_day - prev_time->rtc_day);
   }
   else
   {
      kal_uint8   month;
      kal_uint8   month_end;

      days += (days_in_month[prev_time->rtc_mon] - prev_time->rtc_day);
      month_end = (curr_time->rtc_year == prev_time->rtc_year) ? curr_time->rtc_mon : 13; 
      for (month = (prev_time->rtc_mon+1); month < month_end; month++)
      {
         days += days_in_month[month];
      }
      if ((0==(prev_time->rtc_year%4))&&(prev_time->rtc_mon<=2))
      {
         if (curr_time->rtc_year != prev_time->rtc_year)
            days++;
         else if (curr_time->rtc_mon>2)
            days++;
      }
      month_end = (curr_time->rtc_year == prev_time->rtc_year) ? 0 : curr_time->rtc_mon; 
      for (month = 1; month < month_end; month++)
      {
         days += days_in_month[month];
      }
      days += curr_time->rtc_day;
      if ((curr_time->rtc_year != prev_time->rtc_year)&&(0==(curr_time->rtc_year%4))&&(curr_time->rtc_mon>2))
         days++;
   }
   hours += (days*24);
   *ret_mins = (kal_uint16)mins;
   *ret_hours = (kal_uint16)hours;
   return KAL_TRUE;
}

/*
* FUNCTION                                                            
*	rtc_forward_time
*
* DESCRIPTION                                                           
*  Increase the RTC time by hours, minutes and seconds.
*
* CALLS  
*	This function is called internally for RTC SW calibration
*
* PARAMETERS
*	rtc_time: current RTC time
*	hours: hours to increase time
*  mins: minutes to increase time
*  secs: seconds to increase time
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*  None
*/
void rtc_forward_time(t_rtc *rtc_time, kal_uint16 hours, kal_uint16 mins, kal_uint16 secs)
{
   secs += rtc_time->rtc_sec;
   mins += rtc_time->rtc_min;
   hours += rtc_time->rtc_hour;
   if (secs>59)
   {
      /*min*/
      mins+=secs/60;
      secs%=60;
   }
   rtc_time->rtc_sec = secs;
   if (mins>59)
   {
      /*hour*/
      hours+=mins/60;
      mins%=60;
   }
   rtc_time->rtc_min = mins;
   if (hours>23)
   {
      kal_uint16  days;
      kal_uint8   max_day;

      /*day of week*/
      days = hours/24;
      hours%=24;
      rtc_time->rtc_wday+=days;
      if(rtc_time->rtc_wday>7)
         rtc_time->rtc_wday-=7;
      /*day of month*/            
      rtc_time->rtc_day+=days;
      max_day = days_in_month[rtc_time->rtc_mon];
      if(rtc_time->rtc_mon==2)
      {
      	kal_uint32 remender;
      	remender=rtc_time->rtc_year%4;
      	if(remender==0)
      		max_day++;
      }    
      if(rtc_time->rtc_day>max_day)
      {
         rtc_time->rtc_day-=max_day;
         
         /*month of year*/
         rtc_time->rtc_mon++;
         if(rtc_time->rtc_mon>12)
         {
            rtc_time->rtc_mon=1;
            rtc_time->rtc_year++;
         }                                      
      }   
   }
   rtc_time->rtc_hour = hours;
}

/*
* FUNCTION                                                            
*	rtc_backward_time
*
* DESCRIPTION                                                           
*  Decrease the RTC time by hours, minutes and seconds.
*
* CALLS  
*	This function is called internally for RTC SW calibration
*
* PARAMETERS
*	rtc_time: current RTC time
*	hours: hours to decrease time
*  mins: minutes to decrease time
*  secs: seconds to decrease time
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*  None
*/
void rtc_backward_time(t_rtc *rtc_time, kal_uint16 hours, kal_uint16 mins, kal_uint16 secs)
{
   kal_uint8 day;

   day = 0;
   if (secs > rtc_time->rtc_sec)
   {
      rtc_time->rtc_sec += 60;
      mins++;
   }
   rtc_time->rtc_sec -= secs;
   if (mins > rtc_time->rtc_min)
   {
      rtc_time->rtc_min += 60;
      hours++;
   }
   rtc_time->rtc_min -= mins;   
   if (hours > rtc_time->rtc_hour)
   {
      rtc_time->rtc_hour += 24;
      day = 1;
   }
   rtc_time->rtc_hour -= hours;   
   if(day==1)
   {
      rtc_time->rtc_wday--;
      if (rtc_time->rtc_wday == 0)
         rtc_time->rtc_wday = 7;
      rtc_time->rtc_day--;
      if (rtc_time->rtc_day == 0)
      {
         rtc_time->rtc_mon--;
         if (rtc_time->rtc_mon == 0)
         {
            rtc_time->rtc_mon = 12;
            rtc_time->rtc_year--;
         }
         rtc_time->rtc_day = days_in_month[rtc_time->rtc_mon];
      	if(rtc_time->rtc_mon==2)
      	{
      		kal_uint32 remender;
      		remender=rtc_time->rtc_year%4;
      		if(remender==0)
      		   rtc_time->rtc_day++;
      	}    
      }
   }   
}

/*
* FUNCTION                                                            
*	rtc_update_time
*
* DESCRIPTION                                                           
*     update time according to time stamp
*
* CALLS  
*	This function is to update time according to time stamp
*
* PARAMETERS
*	None
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void rtc_update_time(void)
{
   kal_uint32 current_frame_tick, diff_frame_tick;
   kal_uint32 sec;
   kal_uint32 tick_left_temp;
   kal_uint16 one_third_tick_count_temp;
   //kal_uint32 max_day=0;  
   #ifdef RTC_CAL_DEBUG
   t_rtc rtctime;
   #endif /* RTC_CAL_DEBUG */
   
   #if (!defined(__L1_STANDALONE__)) 
   current_frame_tick=L1I_GetTimeStamp();
   #endif
   /* Calculate the different ticks between the current time and expected time for calibration timeout. */
   if(current_frame_tick>=next_frame_tick) 
   	diff_frame_tick=(current_frame_tick-next_frame_tick)+tick_left;   
   else
   {
   	diff_frame_tick=(0xffffffff+current_frame_tick-next_frame_tick+1)+tick_left;   
      #ifdef RTC_CAL_DEBUG
      kal_prompt_trace(MOD_RTC_HISR, "KAL time out early, expected:%d (ticks), now:%d \r\n", next_frame_tick, current_frame_tick);
      #endif /* RTC_CAL_DEBUG */
   }
   /* Convert the ticks to minutes. */
   sec=(diff_frame_tick/rtc_tick_update_interval);
   sec=sec*rtc_sec_update_interval;

   /* the 1/3 tick for each second. (217 - 216&2/3)*/
   one_third_tick_count_temp = one_third_tick_count + sec;
   tick_left_temp=(diff_frame_tick%rtc_tick_update_interval) + one_third_tick_count_temp/3;
   /* record the left 1/3 tick count. */
   one_third_tick_count_temp %=3;

   /* The below calculation is neccessary because the tick_left_temp may be larger than
      rtc_tick_update_interval again. */
   while (tick_left_temp >= rtc_tick_update_interval)
   {
      sec += (tick_left_temp/rtc_tick_update_interval);
      one_third_tick_count_temp += (tick_left_temp/rtc_tick_update_interval);
      tick_left_temp = ((tick_left_temp%rtc_tick_update_interval)+one_third_tick_count_temp/3);
      one_third_tick_count_temp %=3;
   }

   /* 15 ticks is about 69 ms. */
   if (tick_left_temp > 15)
   {
      /* If the inaccuracy for second boundary is more than 15 ticks, set kal timer to reach the boundary and wait. */
      kal_set_timer(rtc_timer_id, (kal_timer_func_ptr)rtc_timer, NULL, (rtc_tick_update_interval-tick_left_temp+1),0);
      #ifdef RTC_CAL_DEBUG2
      kal_prompt_trace(MOD_RTC_HISR, "calibration time out not in the second boundary:%d (ticks) \r\n", tick_left_temp);
      #endif /* RTC_CAL_DEBUG */
      return;
   }
   /* At this moment, it's around the second boundary. So we do the calibration here now. */
   tick_left = tick_left_temp;
   one_third_tick_count = one_third_tick_count_temp;
   tc_min_expire_cnt = 0;
   /* Plus some ticks to the timer period to guarantee it will expire longer than expected. */
   kal_set_timer(rtc_timer_id, (kal_timer_func_ptr)rtc_timer, NULL, rtc_cali_tick_value+rtc_cali_tick_safe_margin,0);
   /*update time*/
   /*sec*/
   rtc_forward_time(&next_current_time, 0, 0, sec);

   RTC_Cali_Time(&next_current_time);

   /* Save current time and frame_tick_1hr_diff to nvram. */
   rtc_nvram_s.time_valid = KAL_TRUE;
   rtc_nvram_s.rtc_time = next_current_time;
   rtc_nvram_s.ticks_diff_valid = KAL_TRUE;
   rtc_nvram_s.ticks_diff_per_hour = frame_tick_1hr_diff;
   rtc_write_to_nvram();

   #ifdef RTC_CAL_DEBUG
   RTC_GetTime(&rtctime);
   kal_prompt_trace(MOD_RTC_HISR, "calibration time out(%d:%d:%d):%d \r\n"
      ,rtctime.rtc_hour,rtctime.rtc_min,rtctime.rtc_sec, current_frame_tick);
   kal_prompt_trace(MOD_RTC_HISR, "(update %d:%d:%d,):%d \r\n"
   ,next_current_time.rtc_hour,next_current_time.rtc_min,next_current_time.rtc_sec,current_frame_tick);
   #endif /* RTC_CAL_DEBUG */
   /* Calculate the next calibration timeout in frame tick and time. */
   next_frame_tick=rtc_cali_tick_value+current_frame_tick;
   rtc_get_next_time();      
}
/*
* FUNCTION                                                            
*	rtc_get_next_time
*
* DESCRIPTION                                                           
*     calculate next time out time
*
* CALLS  
*	This function is to calculate nexe time out time
*
* PARAMETERS
*	None
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void rtc_get_next_time(void)
{
     /*next time*/
   rtc_forward_time(&next_current_time, rtc_cali_hr_period, rtc_cali_min_period, 0);
}   


/*
* FUNCTION                                                            
*	rtc_poweroff_cali_init
*
* DESCRIPTION                                                           
*  Calculate the last poweroff period of the handset and the RTC inaccuracy between this period.
*
* CALLS  
*	This function is called internally in handset power on sequence.
*
* PARAMETERS
*	None
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void rtc_poweroff_cali_init(void)
{
	kal_uint16 reg_comm2;
	
   pwroff_inacc_ticks = 0;
   nvram_external_read_data(NVRAM_EF_RTC_DATA_LID, 1, (kal_uint8 *)&rtc_nvram_s, sizeof(rtc_nvram_data));
   #ifdef RTC_CAL_DEBUG2
   kal_prompt_trace(MOD_RTC_HISR, "Get nvram data");
   kal_prompt_trace(MOD_RTC_HISR, "time valid?: %d", rtc_nvram_s.time_valid);
   kal_prompt_trace(MOD_RTC_HISR, "%d-%d-%d (%d:%d:%d): ",rtc_nvram_s.rtc_time.rtc_year, rtc_nvram_s.rtc_time.rtc_mon,
      rtc_nvram_s.rtc_time.rtc_day, rtc_nvram_s.rtc_time.rtc_hour, rtc_nvram_s.rtc_time.rtc_min, rtc_nvram_s.rtc_time.rtc_sec);
   kal_prompt_trace(MOD_RTC_HISR, "tick diff valide?: %d", rtc_nvram_s.ticks_diff_valid);                                                   
   kal_prompt_trace(MOD_RTC_HISR, "ticks_diff_per_hour=%d", rtc_nvram_s.ticks_diff_per_hour);                                                   
   #endif /* RTC_CAL_DEBUG */
   /* RTC_isFirstOn() may be called before in DRV_POWERON(). */
	if ((First_PowerOn==KAL_TRUE) || (KAL_FALSE == RTC_isFisrtOn()))
   {
      reg_comm2 = DRV_Reg(DRV_COMM_REG2);

      /* DRV_COMM_REG2_RTC_NVRAM is to determine if the content of RTC nvram is valid or not. */
      if ((reg_comm2 & DRV_COMM_REG2_RTC_NVRAM) && (rtc_nvram_s.time_valid == KAL_TRUE) && (rtc_nvram_s.ticks_diff_valid == KAL_TRUE))
      {
         kal_uint16 hours, mins, secs;
         t_rtc time;
         kal_bool valid;

         /* Get the RTC current time. */
         RTC_GetTime(&time);
         #ifdef RTC_CAL_DEBUG2
         kal_prompt_trace(MOD_RTC_HISR, "The current power on time: %d-%d-%d (%d:%d:%d): ", time.rtc_year, time.rtc_mon,
            time.rtc_day, time.rtc_hour, time.rtc_min, time.rtc_sec);
         #endif /* RTC_CAL_DEBUG */
         /* calculate the power off period in hours and minutes. */
         valid = rtc_get_diff_time(&time, &(rtc_nvram_s.rtc_time), &hours, &mins);
         #ifdef RTC_CAL_DEBUG2
         kal_prompt_trace(MOD_RTC_HISR, "poweroff period - valid: %d, hours: %d, minutes: %d", valid, hours, mins);
         #endif /* RTC_CAL_DEBUG */
         /* Check if these values are reasonable. */
         if ((valid == KAL_TRUE) && (hours < 7200) 
            && (rtc_nvram_s.ticks_diff_per_hour > -1300) && (rtc_nvram_s.ticks_diff_per_hour < 1300))
         {
            /* calculate the inaccurate difference. */
            pwroff_inacc_ticks = hours*rtc_nvram_s.ticks_diff_per_hour+ mins*rtc_nvram_s.ticks_diff_per_hour/60;

            #ifdef RTC_CAL_DEBUG2
            kal_prompt_trace(MOD_RTC_HISR, "inaccurate ticks during poweroff: %d", pwroff_inacc_ticks);
            #endif /* RTC_CAL_DEBUG */
            /* Check if it's alarm power on and the time has to be backward. */
            if ((BMT.PWRon == RTCPWRON) && (pwroff_inacc_ticks < 0))
            {
               extern void DRV_POWEROFF(void);
               t_rtc alarm_time;

               pwroff_inacc_ticks = -pwroff_inacc_ticks;
               hours = pwroff_inacc_ticks/(13000*60);
               pwroff_inacc_ticks = pwroff_inacc_ticks%(13000*60);
               mins = pwroff_inacc_ticks/13000;
               pwroff_inacc_ticks = pwroff_inacc_ticks%13000;
               secs = pwroff_inacc_ticks*3/650;

               RTC_GetALTime(&alarm_time);

               /* calculate the correct time */
               rtc_backward_time(&time, hours, mins, secs);
               /* Check if the correct time is before the alarm time. */
               if (KAL_TRUE == rtc_compare_time(&alarm_time, &time))
               {
                  #ifdef RTC_CAL_DEBUG2
                  kal_prompt_trace(MOD_RTC_HISR, "Alarm power on, and power off the phone");
                  #endif /* RTC_CAL_DEBUG */
                  RTC_Cali_Time(&time);
                  /* invalidate DRV_COMM_REG2_RTC_NVRAM because time has been calibrated. */
                  reg_comm2 &= ~(DRV_COMM_REG2_RTC_NVRAM);
                  DRV_WriteReg(DRV_COMM_REG2,reg_comm2);
                  #if defined(DRV_RTC_HW_CALI)
                  RTC_write_trigger();
                  #endif /*DRV_RTC_HW_CALI*/
                  /* Power off the phone and wait for alarm power on again.*/
                  DRV_POWEROFF();
               }
            }
         }/* if ((valid == */
      } /* if((reg & DRV_COMM_REG2_RTC_NVRAM */
   } /* if((KAL_FALSE == RTC_isFisrtOn() */
}

/*
* FUNCTION                                                            
*	rtc_timer
*
* DESCRIPTION                                                           
*     system timer callback function
*
* CALLS  
*	This function is called when calibration timer time out
*
* PARAMETERS
*	timer_param
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void rtc_timer(void *timer_param)
{
//   kal_uint32 savedMask;
   kal_uint8  rtc_sec;

   rtc_sec = DRV_Reg(RTC_TC_SEC);
   if ((rtc_tc_int_var != TC_EN_None) && (rtc_tc_int_var != TC_EN_ChkS))
   {
      /* avoid the situation when rtc_sec is around zero for minute interrupt. */
      if (rtc_sec < 3 || rtc_sec > 57)
      {
         #ifdef RTC_CAL_DEBUG
         kal_prompt_trace(MOD_RTC_HISR, "rtc time is in minute boundary :(%d): calibration delays 6 secs. ", rtc_sec);
         #endif /* RTC_CAL_DEBUG */
         /* To skip the miniute boundary, delay about 6 secs to do the calibration. */
         kal_set_timer(rtc_timer_id, (kal_timer_func_ptr)rtc_timer, NULL, 1300 ,0);
         return;
      }
   }
   if (rtc_al_int_var != AL_EN_None)
   {
      kal_uint8  al_rtc_sec;
      kal_uint8  sec_diff;

      al_rtc_sec = DRV_Reg(RTC_AL_SEC);
      sec_diff = (rtc_sec >= al_rtc_sec) ? (rtc_sec-al_rtc_sec):(al_rtc_sec-rtc_sec);
      /* avoid the situation when al_rtc_sec is around rtc_sec for alarm interrupt. */
      if (sec_diff < 3 || sec_diff > 57)
      {
         #ifdef RTC_CAL_DEBUG
         kal_prompt_trace(MOD_RTC_HISR, "rtc time is in alarm boundary :(%d): calibration delays 6 secs. ", rtc_sec);
         #endif /* RTC_CAL_DEBUG */
         /* To skip the alarm boundary, delay about 6 secs to do the calibration. */
         kal_set_timer(rtc_timer_id, (kal_timer_func_ptr)rtc_timer, NULL, 1300 ,0);
         return;
      }
   }
//   savedMask = SaveAndSetIRQMask();
   rtc_update_time();      
//   RestoreIRQMask(savedMask);   
}  
#endif /* RTC_SW_CALIBRATION */

#if defined(RTC_HW_CALIBRATION) || defined(RTC_SW_CALIBRATION)
/*
* FUNCTION                                                            
*	rtc_cali_init
*
* DESCRIPTION                                                           
*     Initialize rtc calibration
*
* CALLS  
*	This function is called at power on or user configures time.
*
* PARAMETERS
*	None
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void rtc_cali_init(void *timer_param)
{   
   kal_uint32 frame_tick;

   if (cali_state == CAL_STATE_NONE)
   {
#ifdef RTC_HW_CALIBRATION
      /* Change calibration state to init and enable RTC minute interrupt.
         And wait 'till the RTC minute expired to start calibration. */
      cali_state = CAL_STATE_INIT;
      if (rtc_tc_int_var != TC_EN_ChkM)
#elif defined(RTC_SW_CALIBRATION)
      /* Change calibration state to init and enable RTC second interrupt.
         And wait 'till the RTC second expired to start calibration. */
      cali_state = CAL_STATE_INIT;
      if (rtc_tc_int_var != TC_EN_ChkS)
#endif
      {
   	   kal_uint16 tmp;

         /**/
	      tmp = DRV_Reg(RTC_IRQ_EN);
	      tmp &=~RTC_IRQ_EN_ONESHOT;
		   tmp |= RTC_IRQ_EN_TC;
   	   DRV_WriteReg(RTC_IRQ_EN,tmp);
#ifdef RTC_HW_CALIBRATION
		   DRV_WriteReg(RTC_CII_EN,RTC_CII_EN_MIN);
         RTC_write_trigger_wait();
      }
      tc_min_expire_cnt = 0;
      no_diff_cnt = 0;
      rtc_current_freq_8secs = RTC_STANDARD_FREQ_8SECS + rtc_get_cali_offset();
      #ifdef RTC_CAL_DEBUG
      kal_prompt_trace(MOD_RTC_HISR, "Initial: repeat calibration count is %d \r\n", (rtc_current_freq_8secs-RTC_STANDARD_FREQ_8SECS));
      #endif /* RTC_CAL_DEBUG */
   }
#elif defined(RTC_SW_CALIBRATION)
		   DRV_WriteReg(RTC_CII_EN,RTC_CII_EN_SEC);
      }
   }
   else if ((cali_state == CAL_STATE_INIT2) || (cali_state == CAL_STATE_RESET))
   {
      /* next_current_time has already been set before in RTC_InitTC_Time() or RTC_TCintr(). */
      if (cali_state == CAL_STATE_INIT2)
      {
         /* Set the adjusted correct time (power off calibration) in this moment. */
         RTC_Cali_Time(&next_current_time);
         #ifdef RTC_CAL_DEBUG2
         kal_prompt_trace(MOD_RTC_HISR, "current time after 2nd poweroff calibration- (%d:%d:%d)",
            next_current_time.rtc_hour, next_current_time.rtc_min, next_current_time.rtc_sec);
         #endif /* RTC_CAL_DEBUG */
      }
      /* Start power on calibration by KAL timer. */
      kal_set_timer(rtc_timer_id, (kal_timer_func_ptr)rtc_timer, NULL, rtc_cali_tick_value+rtc_cali_tick_safe_margin,0);
      #if (!defined(__L1_STANDALONE__)) 
      frame_tick=L1I_GetTimeStamp();
      #endif
      #ifdef RTC_CAL_DEBUG
      kal_prompt_trace(MOD_RTC_HISR, "Start poweron calibration");
      kal_prompt_trace(MOD_RTC_HISR, "(%d:%d:%d): ",next_current_time.rtc_hour,next_current_time.rtc_min,next_current_time.rtc_sec);
      kal_prompt_trace(MOD_RTC_HISR, "ini tick=%d\r\n",frame_tick);                                                   
      #endif /* RTC_CAL_DEBUG */
      tick_left=0;
      one_third_tick_count = 0;
      tc_min_expire_cnt = 0;
      next_frame_tick=frame_tick+rtc_cali_tick_value;         
      rtc_get_next_time();
      /* Change to "start" state. */
      cali_state = CAL_STATE_START;
   }
#endif /* RTC_SW_CALIBRATION */
}   
#endif /*defined(RTC_HW_CALIBRATION) || defined(RTC_SW_CALIBRATION)*/

/*
* FUNCTION                                                            
*	RTC_start_cali
*
* DESCRIPTION                                                           
*  The entry function of RTC calibration.
*
* CALLS  
*	This function is called in bmt_task_init()(in bmt_create.c) because at this moment of the 
*  function, the file system is ready for accessing nvram data.
*
* PARAMETERS
*	None
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void RTC_start_cali(void)
{
#if defined(RTC_SW_CALIBRATION) || defined(RTC_HW_CALIBRATION)
   #if defined(__USB_ENABLE__) && !defined(__NVRAM_IN_USB_MS__)
      /* In this compile option case, when it's USB mode powered on we can't do RTC calibration
         because L1 time stamp won't be updated (L1I_GetTimeStamp()).*/
      if (KAL_FALSE == INT_USBBoot() )
      {
   #endif
	      #if (!defined(__L1_STANDALONE__)) 	
            #if defined(RTC_HW_CALIBRATION)
               rtc_cali_init(0);
            #elif defined(RTC_SW_CALIBRATION)
	            rtc_timer_id=kal_create_timer("RTCcal_Timer");
               rtc_poweroff_cali_init();
               kal_set_timer(rtc_timer_id, (kal_timer_func_ptr)rtc_cali_init, NULL, 1,	0);
            #endif
         #endif /* (!defined(__L1_STANDALONE__)) */
   #if defined(__USB_ENABLE__) && !defined(__NVRAM_IN_USB_MS__)
      }
   #endif
#endif /* defined(RTC_SW_CALIBRATION) || defined(RTC_HW_CALIBRATION) */
}


/*
* FUNCTION                                                            
*	RTC_init
*
* DESCRIPTION                                                           
*     RTC initialization function
*
* CALLS  
*	This function is initialize RTC software
*
* PARAMETERS
*	RTC_TCCallback: time update callback function
*	RTC_ALCallback: alarm callback function
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void RTC_init(void (*RTC_TCCallback)(void),void (*RTC_ALCallback)(void))	//validate
{
	/*status = DRV_Reg(RTC_IRQ_STATUS);*/
	RTC_CALLBAC.rtc_tcfunc = RTC_TCCallback;
	RTC_CALLBAC.rtc_alfunc = RTC_ALCallback;
	/**(volatile kal_uint16 *)RTC_IRQ_EN = RTC_IRQ_EN_ONESHOT;*/
	/*DRV_WriteReg(RTC_IRQ_EN,RTC_IRQ_EN_ALLOFF);*/

	if (RTCConfig.hisr == NULL)
	{
	   //RTCConfig.hisr = kal_create_hisr("RTC_HISR",2,512,RTC_HISR,NULL);
	   RTCConfig.hisr=(void*)0x1234;
	   DRV_Register_HISR(DRV_RTC_HISR_ID, RTC_HISR);
	}   
   /*RTC IRQ configuration*/
   #ifdef __MULTI_BOOT__
	if (INT_BootMode() == MTK_NORMAL_MODE)
	{
      IRQ_Register_LISR(IRQ_RTC_CODE, RTC_LISR,"RTC handler");
		IRQSensitivity(IRQ_RTC_CODE,LEVEL_SENSITIVE);
		#if !defined(IC_MODULE_TEST) // Disable RTC interrupt in module test
      IRQUnmask(IRQ_RTC_CODE);
      #endif
   }
   #else /*__MULTI_BOOT__*/
   IRQ_Register_LISR(IRQ_RTC_CODE, RTC_LISR,"RTC handler");
   IRQSensitivity(IRQ_RTC_CODE,LEVEL_SENSITIVE);
		#if !defined(IC_MODULE_TEST) // Disable RTC interrupt in module test
      IRQUnmask(IRQ_RTC_CODE);
      #endif
   #endif   /*__MULTI_BOOT__*/
   /*config RTC driving current*/
   /*#if defined(DRV_RTC_XOSC_DEF_8)
   DRV_WriteReg(RTC_XOSCCAL,0x8);
   #endif*/
}

#if defined(DRV_RTC_HW_CALI)
/*
* FUNCTION                                                            
*	RTC_wait_debounce
*
* DESCRIPTION                                                           
*     To wait until RTC is not in debouncing
*
* CALLS  
*	This function is called in RTC initialization
*
* PARAMETERS
*	None
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void RTC_wait_debounce(void)
{
   kal_uint32 count=0;
   while(count < 0xffffffff)
   {
      if ((RTC_BBPU_DBING & DRV_Reg(RTC_BBPU))==0)
         break;
      count++;
   }
   #ifdef RTC_CAL_DEBUG
   kal_prompt_trace(MOD_RTC_HISR, "RTC wait debounce count = %x\r\n",count);
   #endif /* RTC_CAL_DEBUG */
}

/*
* FUNCTION                                                            
*	RTC_wait_busy
*
* DESCRIPTION                                                           
*     To wait until the read/write channels between RTC / Core is not busy
*
* CALLS  
*	This function is called after RTC register is written and triggered
*
* PARAMETERS
*	None
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void RTC_wait_busy(void)
{
   kal_uint32 count=0;
   while(count < 0xffffffff)
   {
      if ((RTC_BBPU_CBUSY & DRV_Reg(RTC_BBPU))==0)
         break;
      count++;
   }
   #ifdef RTC_CAL_DEBUG
   kal_prompt_trace(MOD_RTC_HISR, "RTC wait busy count = %x\r\n",count);
   #endif /* RTC_CAL_DEBUG */
}

/*
* FUNCTION                                                            
*	RTC_reload
*
* DESCRIPTION                                                           
*     Reload the values from RTC domain to Core domain
*
* CALLS  
*	This function can be treated as a debugging function.
*
* PARAMETERS
*	None
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void RTC_reload(void)
{
   kal_uint16 reg;
   
   reg = DRV_Reg(RTC_BBPU);
   reg |= (RTC_BBPU_RELOAD|RTC_BBPU_KEY);
   DRV_WriteReg(RTC_BBPU, reg);
}

/*
* FUNCTION                                                            
*	RTC_init
*
* DESCRIPTION                                                           
*     RTC hardware initialization function
*
* CALLS  
*	This function is initialize RTC HW
*
* PARAMETERS
*	None
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void RTC_HW_Init(void)
{
  	RTC_wait_debounce();
  	//RTC_reload(); //For debug purpose
  	RTC_wait_busy();
}
#endif /* DRV_RTC_HW_CALI */

#endif /*!defined(__FUE__)*/


/*
* FUNCTION                                                            
*	RTC_is_config_valid
*
* DESCRIPTION                                                           
*  Check if RTC time and Alarm are valid. If these
*  settings are not correct, we treat it as first power on and
*  reconfigure RTC.
*
* CALLS  
*	This function is to check if RTC time and Alarm are valid.
*
* PARAMETERS
* valid or not
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/

kal_bool RTC_is_config_valid(void)
{
   t_rtc time, alarm;
   
   RTC_GetTime(&time);
   RTC_GetALTime(&alarm);
   
   if((time.rtc_sec>59) ||(alarm.rtc_sec>59)||
      (time.rtc_min>59) ||(alarm.rtc_min>59)||
      (time.rtc_hour>23)||(alarm.rtc_hour>23)   ||
      (time.rtc_day>31) ||(alarm.rtc_day>31)|| 
      (time.rtc_wday>7) ||(alarm.rtc_wday>7)|| 
      (time.rtc_mon>12) ||(alarm.rtc_mon>12) )
   {   
      alarm.rtc_sec=0;
      alarm.rtc_min=0;
      alarm.rtc_hour=0;
      alarm.rtc_day=0;
      alarm.rtc_wday=0;
      alarm.rtc_mon=0;
      RTC_SetAlarm(&alarm);
      return KAL_FALSE;      
}

   return KAL_TRUE;
}   


/*
* FUNCTION                                                            
*	RTC_read_xosc_reg
*
* DESCRIPTION                                                           
*  Read RTC XOSC register value
*
* CALLS  
*	This function is for enginner mode.
*
* PARAMETERS
*  None
*	
* RETURNS
*	RTC XOSC register value
*
* GLOBALS AFFECTED
*   external_global
*/
kal_uint8 RTC_read_xosc_reg(void)
{
   kal_uint16   value;

   value = DRV_Reg(RTC_XOSCCAL);
   return ((kal_uint8)value);
}

/*
* FUNCTION                                                            
*	RTC_write_xosc_reg
*
* DESCRIPTION                                                           
*  Set RTC XOSC register value.
*
* CALLS  
*	This function is for enginner mode.
*
* PARAMETERS
*  RTC XOSC register value to set.
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void RTC_write_xosc_reg(kal_uint8 reg_value)
{
   DRV_WriteReg(RTC_XOSCCAL, ((kal_uint16)reg_value));
#if defined(DRV_RTC_HW_CALI)
   RTC_write_trigger();
#endif
}
