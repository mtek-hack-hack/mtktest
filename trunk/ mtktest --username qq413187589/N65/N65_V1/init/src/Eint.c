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
 *   Eint.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description: 
 * ------------
 *   This files define external interrupt management
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
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*************************************************************************
 * Included header files
 *************************************************************************/
#include "kal_release.h"
#include "reg_base.h"
#include "intrCtrl.h"
#include "eint.h"
#include "gpt_sw.h"
#include "drv_comm.h"
#include "drv_hisr.h"


/*************************************************************************
 * Define global variables
 *************************************************************************/
static eint_func EINT_FUNC;
static EINT_SW_DEBOUNCE_STRUCT eint_sw_debounce[EINT_MAX_CHANNEL];
static kal_uint8 *eint_sw_debounce_time_delay;


/*************************************************************************
 * Define function prototpye
 *************************************************************************/
void EINT_HISR_Entry(void);
extern void RestoreIRQ(kal_uint32 irq);
extern kal_uint32 LockIRQ(void);


/*************************************************************************
* FUNCTION
*  Register_EINT
*
* DESCRIPTION
*   This function implements registration of external interrupts
*
* CALLS
*
* PARAMETERS
*  eintno            -     External interrupt vector number
*  Dbounce_En        -     Debounce control enable
*  ACT_Polarity      -     Interrupt polarity
*  reg_hisr          -     Registered hisr
*  auto_umask        -     A flag instruct the systerm to do unmask after
*                          invoking the registered HISR
*
* RETURNS
*  No return
*
* GLOBALS AFFECTED
*
*************************************************************************/
#if defined(__DIRECTION_SENSOR_SUPPORT__)
/* 2009.4.14 added by hongzhe.liu for motion sensor + */
extern const unsigned char MOTION_SENSOR_EINT_NO1;
extern const unsigned char MOTION_SENSOR_EINT_NO2; 
/* 2009.4.14 added by hongzhe.liu for motion sensor - */
#endif
void EINT_Registration(kal_uint8 eintno, kal_bool Dbounce_En, kal_bool ACT_Polarity, \
                       void (reg_hisr)(void), kal_bool auto_umask)
{
   kal_uint32 savedMask;
   kal_uint16 count;


   EXT_ASSERT(eintno < EINT_TOTAL_CHANNEL, eintno, Dbounce_En, ACT_Polarity);
   
   IRQ_Register_LISR(IRQ_EIT_CODE, EINT_LISR, "EINT handler");

   /* Save and set MCU's I,F bits to disable interrupts */
   savedMask = LockIRQ();

   /* Set external interrupt polarity */
   if (ACT_Polarity) 
      EINTaddr(eintno) |= EINT_CON_HIGHLEVEL;
   else
      EINTaddr(eintno) &= ~(EINT_CON_HIGHLEVEL);

   /*
    * NoteXXX: Only EINT 0 ~ (EINT_MAX_CHANNLE - 1) support level trigger.
    *          The de-bounce time is only for level trigger EINT.
    */
   if (eintno < EINT_MAX_CHANNEL) {
      /* Set external interrupt debounce control enable or not */
      if (Dbounce_En) {
         /* check if debounce is enabled */
         if (EINTaddr(eintno) & EINT_CON_DEBOUNCE_EN) {
            /* debounce value is already set; NOP */
         } else {
            EINTaddr(eintno) |= (EINT_CON_DEBOUNCE | EINT_CON_DEBOUNCE_EN);
         }
      }
   else
   {
      /*disable debounce */
      EINTaddr(eintno) &= ~(EINT_CON_DEBOUNCE_EN);
   }
   }

   /* Register external interrupt's HISR */
   EINT_FUNC.eint_func[eintno] = reg_hisr;
   EINT_FUNC.eint_active[eintno] = KAL_FALSE;
   EINT_FUNC.eint_auto_umask[eintno] = auto_umask;

   /* register HISR */
   DRV_Register_HISR(DRV_EINT_HISR_ID, EINT_HISR_Entry);
   
   /* Restore previous MCU's I,F bits setting */
   RestoreIRQ(savedMask);

   /*
    * XXX!!!. Hardware bug
    *    - must wait for 32khz/1 sec to write mask register, will be
    *    fixed in future.
    */
   for (count=0; count<250; count++) ;  /*250:52M*/

   savedMask = LockIRQ();

   *EINT_INTACK = EINT_INTACK_EINT(eintno);
   
#if defined(MT6205) || defined(MT6208) || defined(FPGA) 
   *EINT_MASK &= ~(0x0001 << eintno);
#else
   *EINT_MASK_CLR = (0x0001 << eintno);
#endif

   RestoreIRQ(savedMask);

   /* Set external interrupt is level sensitive */
   #if !defined(__DIRECTION_SENSOR_SUPPORT__)
   
   if( (0)
   #if defined(__DIRECTION_SENSOR_SUPPORT__)
       || eintno == MOTION_SENSOR_EINT_NO1 
       || eintno == MOTION_SENSOR_EINT_NO2
   #endif
   )
   {
	   IRQSensitivity(IRQ_EIT_CODE,EDGE_SENSITIVE);   	
   }else{
   	   IRQSensitivity(IRQ_EIT_CODE,LEVEL_SENSITIVE);
   }

   #endif

   /* Enable external interrupt */
   IRQUnmask(IRQ_EIT_CODE);
}


/*************************************************************************
* FUNCTION
*  EXTRA_EINT_Registration
*
* DESCRIPTION
*   This function implements registration of external interrupts
*
* CALLS
*
* PARAMETERS
*  eintno            -     External interrupt vector number
*  ACT_Polarity      -     Interrupt polarity
*  reg_hisr          -     Registered hisr
*  auto_umask        -     A flag instruct the systerm to do unmask after
*                          invoking the registered HISR
*
* RETURNS
*  No return
*
* GLOBALS AFFECTED
*
*************************************************************************/
void EXTRA_EINT_Registration(kal_uint8 eintno, kal_bool ACT_Polarity, void (reg_hisr)(void), \
                             kal_bool auto_umask)
{
   ASSERT((eintno < EINT_TOTAL_CHANNEL) && (eintno >= EINT_MAX_CHANNEL));

   EINT_Registration(eintno, KAL_FALSE, ACT_Polarity, reg_hisr, auto_umask);
}


/*************************************************************************
* FUNCTION
*  EINT_Set_HW_Debounce
*
* DESCRIPTION
*   This function dedicates to set the hardware debounce time of external 
*   interrupts.
*
* CALLS
*
* PARAMETERS
*   eintno   -   External interrupt vector number
*   ms       -   hardware debounce time (in milli second)
*
* RETURNS
*   No return
*
* GLOBALS AFFECTED
*
*************************************************************************/
void EINT_Set_HW_Debounce(kal_uint8 eintno, kal_uint32 ms)
{
   kal_uint32 cnt;

   /* calculate cnt value based on 32KHz clock cycles */
   cnt = ms << 5;

   /* clear original debounce value */
   EINTaddr(eintno) &= ~EINT_CON_DEBOUNCE;

   /* set new debounce value */
   EINTaddr(eintno) |= (cnt | EINT_CON_DEBOUNCE_EN);
}

/*************************************************************************
* FUNCTION
*  EINT_Set_Polarity
*
* DESCRIPTION
*   This function sets the polarity of external interrupts
*
* CALLS
*
* PARAMETERS
*  eintno            -     External interrupt vector number
*  ACT_Polarity      -     Interrupt polarity
*
* RETURNS
*  No return
*
* GLOBALS AFFECTED
*
*************************************************************************/
void EINT_Set_Polarity(kal_uint8 eintno, kal_bool ACT_Polarity)
{
   kal_uint32 savedMask;
   kal_uint32 count;

   /* Save and set MCU's I,F bits to disable interrupts */
   savedMask = LockIRQ();

   /* Set external interrupt polarity */
   if (ACT_Polarity) 
      EINTaddr(eintno) |= EINT_CON_HIGHLEVEL;
   else
      EINTaddr(eintno) &= ~(EINT_CON_HIGHLEVEL);

   for (count=0; count<250; count++) ;  /*250:52M*/

   *EINT_INTACK = EINT_INTACK_EINT(eintno);

#if ( defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6238))

   *IRQ_EOI2 = IRQCode2Line[IRQ_EIT_CODE];

#else   

   *IRQ_EOI = (1 << IRQCode2Line[IRQ_EIT_CODE]);

#endif
   
   /* Restore previous MCU's I,F bits setting */
   RestoreIRQ(savedMask);
}

/*************************************************************************
* FUNCTION
*  EINT_Set_Sensitivity
*
* DESCRIPTION
*   This function dedicates to set the sensitivity of external 
*   interrupts.
*
* CALLS
*
* PARAMETERS
*   eintno   -   External interrupt vector number
*   sens     -   EDGE_SENSITIVE or LEVEL_SENSITIVE
*
* RETURNS
*   0 for success; -1 for failure
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint32 EINT_Set_Sensitivity(kal_uint8 eintno, kal_bool sens)
{
   kal_uint32 savedMask;
#if defined(MT6205) || defined(MT6205B) || defined(MT6208)

   return -1;
   
#else
   if (eintno >= EINT_MAX_CHANNEL) {
      /* not support level trigger */
      return -1;
   }
   /* Save and set MCU's I,F bits to disable interrupts */
   savedMask = LockIRQ();

   if (sens == EDGE_SENSITIVE) {
      *EINT_SENS &= ~(1 << eintno);
   } else if (sens == LEVEL_SENSITIVE) {
      *EINT_SENS |= (1 << eintno);
   }
   /* Restore previous MCU's I,F bits setting */
   RestoreIRQ(savedMask);

   return 0;
#endif
}


/*************************************************************************
* FUNCTION
*  EINT_Mask
*
* DESCRIPTION
*   This function implements mask of dedicated external interrupt source
*
* CALLS
*
* PARAMETERS
*  eintno         - external interrupt vector number
*
* RETURNS
*  No return
*
* GLOBALS AFFECTED
*
*************************************************************************/
void EINT_Mask(kal_uint8 eintno)
{
#if defined(MT6205) || defined(MT6208) || defined(FPGA) 

   kal_uint32 savedMask;
   
   savedMask = LockIRQ();
   *EINT_MASK |= (0x0001 << eintno);
   RestoreIRQ(savedMask);
   
#else

   *EINT_MASK_SET = (0x0001 << eintno);
   
#endif 
}

/*************************************************************************
* FUNCTION
*  EINT_UnMask
*
* DESCRIPTION
*   This function implements Unmask of dedicated external interrupt source
*
* CALLS
*
* PARAMETERS
*  eintno         - external interrupt vector number
*
* RETURNS
*  No return
*
* GLOBALS AFFECTED
*
*************************************************************************/
void EINT_UnMask(kal_uint8 eintno)
{
#if defined(MT6205) || defined(MT6208) || defined(FPGA) 

   kal_uint32 savedMask;
   
   savedMask = LockIRQ();
   *EINT_MASK &= ~(0x0001 << eintno);
   RestoreIRQ(savedMask);
   
#else

   *EINT_MASK_CLR = (0x0001 << eintno);
   
#endif 
}


/*************************************************************************
* FUNCTION
*  EINT_SaveAndMask
*
* DESCRIPTION
*  This function saves and masks the specified external interrupt
*
* PARAMETERS
*  eintno   -   external interrupt vector number
*
* RETURNS
*  original mask
*
*************************************************************************/
kal_uint32 EINT_SaveAndMask(kal_uint8 eintno)
{
   kal_uint32 savedMask, eint_mask;


   /* lockout interrupt */
   savedMask = LockIRQ();

   /* save EINT mask */
   eint_mask = *EINT_MASK;

   /* mask EINT */
   *EINT_MASK |= (0x0001 << eintno);

   /* un-lockout interrupt */
   RestoreIRQ(savedMask);

   /* clear unnecessary bits */
   eint_mask = eint_mask & (0x0001 << eintno);

   return eint_mask;
}


/*************************************************************************
* FUNCTION
*  EINT_RestoreMask
*
* DESCRIPTION
*  This function restores the MASK of the specified external interrupt
*
* PARAMETERS
*  val   -   value to restore
*
* RETURNS
*  No return
*
*************************************************************************/
void EINT_RestoreMask(kal_uint8 eintno, kal_uint32 val)
{
   kal_uint32 savedMask;


   /* lockout interrupt */   
   savedMask = LockIRQ();

   /*
    * NoteXXX: The external interrup should already be masked here (via the
    *          EINT_SaveAndMask() call). Only need to change the EINT_MASK 
    *          when the external interrupt is originally un-masked.
    */
   if (val == 0) {
       *EINT_MASK &= ~(0x0001 << eintno);
   }
   
   /* un-lockout interrupt */
   RestoreIRQ(savedMask);
}


/*************************************************************************
* FUNCTION
*  EINT_HISR_Entry
*
* DESCRIPTION
*  This function implements main external interrupt HISR registered in
*  global ISR jump table, eint_hisr_func.
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*  No return
*
* GLOBALS AFFECTED
*
*************************************************************************/
void EINT_HISR_Entry(void)
{
   kal_uint8 index;   
   
   for(index  =0; index < EINT_TOTAL_CHANNEL; index++) 
   {
      if ( (EINT_FUNC.eint_active[index] == KAL_TRUE) && (EINT_FUNC.eint_func[index]) ) 
      {

         EINT_FUNC.eint_func[index]();

         EINT_FUNC.eint_active[index] = KAL_FALSE;

         if (EINT_FUNC.eint_auto_umask[index] == KAL_TRUE) 
         {

            EINT_UnMask(index);
         }
      }
   }

#if ( defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6238))

	*IRQ_EOI2 = IRQCode2Line[IRQ_EIT_CODE];

#else

	*IRQ_EOI = (1 << IRQCode2Line[IRQ_EIT_CODE]);

#endif	
}


/*************************************************************************
* FUNCTION
*  EINT_TIMER_CALLBACK
*
* DESCRIPTION
*   This function implements main external interrupt LISR registered in
*  global ISR jump table.
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*  No return
*
* GLOBALS AFFECTED
*
*************************************************************************/
void EINT_TIMER_CALLBACK(void *data)
{
   EINT_SW_DEBOUNCE_STRUCT *sw_debounce = (EINT_SW_DEBOUNCE_STRUCT *)data;

   GPTI_StopItem(sw_debounce->eint_sw_debounce_handle);

   sw_debounce->eint_intr_allow = (sw_debounce->eint_intr_allow == KAL_TRUE)? KAL_FALSE: KAL_TRUE;

   /*
    * This timer is to avoid if interrupt status is changed but 
    * sw_debounce->eint_intr_allow is still in KAL_TRUE state
    * because of no interrupt
    */
   if (sw_debounce->eint_intr_allow) 
   {
      GPTI_StartItem(sw_debounce->eint_sw_debounce_handle, eint_sw_debounce_time_delay[sw_debounce->eint_no], /*0.5 second*/ EINT_TIMER_CALLBACK, data);
   }

   EINT_UnMask(sw_debounce->eint_no);
}


/*************************************************************************
* FUNCTION
*   EINT_LISR
*
* DESCRIPTION
*   Entry function of External Interrupt Service Routine
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*  No return
*
* GLOBALS AFFECTE
*
*************************************************************************/
void EINT_LISR(void)
{
   kal_uint8 index;
   kal_uint16 status;

   status = *EINT_STATUS;

   // for conventional external interrupt!
   for(index=0;index<EINT_MAX_CHANNEL;index++)
   {
      if (status & EINT_STATUS_EINT(index)) 
      {
         GPTI_StopItem(eint_sw_debounce[index].eint_sw_debounce_handle);
         if ( (eint_sw_debounce[index].eint_intr_allow == KAL_FALSE) && 
              (eint_sw_debounce_time_delay[index] > 0) 
            )
         {
            GPTI_StartItem(eint_sw_debounce[index].eint_sw_debounce_handle,
                  eint_sw_debounce_time_delay[index],
                  EINT_TIMER_CALLBACK,
                  &eint_sw_debounce[index]);
            EINT_Mask(index);
         }
         else
         {
            eint_sw_debounce[index].eint_intr_allow = KAL_FALSE;
            // disable interrupt
            EINT_Mask(index);
            ASSERT(EINT_FUNC.eint_func[index]!=NULL);
            if ( EINT_FUNC.eint_func[index] )
            {
               EINT_FUNC.eint_active[index] = KAL_TRUE;

               drv_active_hisr(DRV_EINT_HISR_ID);
            }
         }
         *EINT_INTACK = EINT_INTACK_EINT(index);
      }
   }
   
   // for external interrupt without hardware debounce and always edge sensitive
   for (index=EINT_MAX_CHANNEL; index<EINT_TOTAL_CHANNEL; index++)
   {
   	if (status & EINT_STATUS_EINT(index)) 
   	{
         EINT_Mask(index);
         ASSERT(EINT_FUNC.eint_func[index]!=NULL);
         if ( EINT_FUNC.eint_func[index] )
         { 
            EINT_FUNC.eint_active[index] = KAL_TRUE;

            drv_active_hisr(DRV_EINT_HISR_ID);
         }
         *EINT_INTACK = EINT_INTACK_EINT(index);
      }
   }
}


/*************************************************************************
* FUNCTION
*   EINT_SW_Debounce_Init
*
* DESCRIPTION
*   Initialize debounce time
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*  No return
*
* GLOBALS AFFECTE
*
*************************************************************************/
void EINT_SW_Debounce_Init(void)
{
   kal_uint8 index;

   for (index = 0; index < EINT_MAX_CHANNEL; index++)
   {
      GPTI_GetHandle(&eint_sw_debounce[index].eint_sw_debounce_handle);
      eint_sw_debounce[index].eint_intr_allow = KAL_FALSE;
      eint_sw_debounce[index].eint_no = index;
   }

   eint_sw_debounce_time_delay = custom_config_eint_sw_debounce_time_delay();
}


/*************************************************************************
* FUNCTION
*   EINT_SW_Debounce_Modify
*
* DESCRIPTION
*   Setting debounce time
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*  No return
*
* GLOBALS AFFECTE
*
*************************************************************************/
kal_int32 EINT_SW_Debounce_Modify(kal_uint8 eintno, kal_uint8 debounce_time)
{
   kal_uint32 savedMask;
   
   if ( eintno>=EINT_MAX_CHANNEL )
      return -1;

   savedMask = DisableIRQ();      
   eint_sw_debounce_time_delay[eintno] = debounce_time;
   RestoreIRQ(savedMask);
   
   return 1;
}

