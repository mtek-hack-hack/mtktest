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
 *   idle_task.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is for the functions of idle task.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef __MTK_TARGET__
#include "kal_release.h"
#include "stack_common.h"  
#include "stack_msgs.h"
#include "app_ltlcom.h"
#include "syscomp_config.h"
#include "task_config.h"      /* Task creation */

#include "l1_const.h"
#include "l1_types.h"
//#include "reg_base.h"
#include "l1d_reg.h"
#include "l1d_cid.h"
#if defined(DCM_ENABLE)
#include "init.h"
#endif
#if ( (IS_CHIP_MT6238) || (IS_CHIP_MT6235) )
#include "cp15.h"
#endif  /* (IS_CHIP_MT6238) || (IS_CHIP_MT6235) */


#if (IS_CHIP_MT6227_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION)
bool L1_DCM_Enable;
#endif
kal_uint32 SaveAndSetIRQMask(void);
void RestoreIRQMask(kal_uint32);
/*
 * NoteXXX: SaveAndSetIRQMask()/RestoreIRQMask() are APIs for appilcations to disable/restore
 *          IRQ. They will restrict the disable duration. But idle task disables IRQ for a 
 *          time due to DCM. Thus LockIRQ()/RestoreIRQ() are used here. Only the idle task
 *          can use them!! Other applications are not allowed to use LockIRQ()/RestoreIRQ().
 */
kal_uint32 LockIRQ(void);
void RestoreIRQ(kal_uint32);

#if defined(KAL_ON_NUCLEUS)
NU_TASK *IdleTaskTCB;
#elif defined(KAL_ON_THREADX)
TX_THREAD *IdleTaskTCB;
#endif

#pragma arm section code = "INTERNCODE"

#pragma arm section rwdata = "INTERNRW" , rodata = "INTERNCONST" , zidata = "INTERNZI"
#if defined(DCM_ENABLE)
volatile static kal_uint32 dcm_state = 0;
volatile static bool dcm_excuted = false;
 /* dcm_state = 0, 104/52 MHz.
                1, 104/52->13/26 MHz transition.
                2, 13/26 Mhz.
                3, 13/26->104/52 MHz transition. */
static struct
{
   uint8   	dcmHandleCount;
   uint32   dcmDisable;					/* Default not disable DCM */
   /* mtk01940: for MT6227, use this flag to distinguish dedi or idle mode */   
   #if (IS_CHIP_MT6227 || IS_CHIP_MT6228) 
   bool     isIdleMode;         
   #endif
   
} dcm = { 0, 0 };
extern int custom_DynamicClockSwitch(mcu_clock_enum clock);
#endif	/* DCM_ENABLE */

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/* Note that idle task is only created when MTK_SLEEP_ENABLE is defined. */
void IdleTask( task_entry_struct * task_entry_ptr )
{
#if defined(KAL_ON_NUCLEUS)
	IdleTaskTCB = (NU_TASK*)task_info_g[task_entry_ptr->task_indx].task_id;
#elif defined(KAL_ON_THREADX)
	IdleTaskTCB = (TX_THREAD *)task_info_g[task_entry_ptr->task_indx].task_id;
#endif
	
   while(1)
   {
       /* Partial sleep mode for MCU and AVB block.
          To force MCU and AVB bus CLK stopped when system is in idle task.
          System will run again and CLK resume automatically only when IRQ comes.
       */
   	
#if defined(MTK_SLEEP_ENABLE) || defined(L1D_TEST)
   #if defined( DCM_ENABLE )
      kal_uint32 _savedMask;
      volatile kal_uint16 i,j=0;
      register kal_uint32 start, end, duration, tqwrap;

      _savedMask = LockIRQ();

      start = *((volatile kal_uint16 *)(TDMA_base + 0x00));

      /* Check if DMA, GMC and LCD_DMA is in Power Down Mode. */
      if ( 
#if (IS_CHIP_MT6229)
            (((*(volatile kal_uint32 *)0x80030000) & 0x00055555)==0) &&  /* Check DMA1~10, ignore DMA11~14 */
            (((*PDN_CON0) & 0x0078) == 0x0078) &&           /* Check PDN_CON0 IRDMA, PPP, CHE, and WAVETABLE down */
            ((*PDN_CON1) & 0x0080) &&           /* Check PDN_CON1 LCD down */
            ((*PDN_CON3) == 0xFFFF) &&          /* Check PDN_CON3 all down [GMC]*/
            *MCUCLK_CON == 0x0703 &&
#elif ( (IS_CHIP_MT6238) || (IS_CHIP_MT6235) ) //add by jerry
            (((*DMA_GLBSTA) & 0x00055555)==0) &&  /* Check DMA1~10, ignore DMA11~14 */
            (((*PDN_CON0) & 0x0078) == 0x0078) &&           /* Check PDN_CON0 IRDMA, PPP, CHE, and WAVETABLE down */
            ((*PDN_CON1) & 0x0080) &&           /* Check PDN_CON1 LCD down */
            ((*PDN_CON3) == 0xFFFF) &&          /* Check PDN_CON3 all down [GMC]*/
            *MCUCLK_CON == 0x7F37 &&            /*EMICLK,ARMCLK,AHBX4CLK,AHBX8CLK,104,208,52,104*/  
#elif (IS_CHIP_MT6228)
            (((*(volatile kal_uint32 *)0x80030000) & 0x00055555)==0) &&  /* Check DMA1~10, ignore DMA11~14 */
            (((*PDN_CON0) & 0x0038) == 0x0038) &&           /* Check PDN_CON0 PPP, CHE, and WAVETABLE down */
            ((*PDN_CON1) & 0x0080) &&           /* Check PDN_CON1 LCD down */
            ((*PDN_CON3) == 0xFFFF) &&          /* Check PDN_CON3 all down [GMC]*/
            *MCUCLK_CON == 0x0703 &&
#elif ( IS_CHIP_MT6223)
            (((*(volatile kal_uint32 *)0x80030000) & 0x00055555)==0) &&  /* Check DMA1~10, ignore DMA11~14 */
            (((*PDN_CON0) & 0x0048) == 0x0048) &&           /* Check PDN_CON0 IRDMA, and WAVETABLE down */
            ((*PDN_CON1) & 0x0080) &&           /* Check PDN_CON1 LCD down */
            ((*PDN_CON3) == 0x0001) &&          /* Check PDN_CON3 all down [GMC]*/
            *MCUCLK_CON == 0x0303 &&
#elif ( IS_CHIP_MT6225)
            (((*(volatile kal_uint32 *)0x80030000) & 0x00055555)==0) &&  /* Check DMA1~10, ignore DMA11~14 */
            (((*PDN_CON0) & 0x0048) == 0x0048) &&           /* Check PDN_CON0 IRDMA, and WAVETABLE down */
            ((*PDN_CON1) & 0x0080) &&           /* Check PDN_CON1 LCD down */
            ((*PDN_CON3) == 0x1801) &&          /* Check PDN_CON3 all down [GMC]*/
            *MCUCLK_CON == 0x0703 &&             
#elif ( IS_CHIP_MT6227)
            (((*(volatile kal_uint32 *)0x80030000) & 0x00055555)==0) &&  /* Check DMA1~10, ignore DMA11~14 */
            ((*PDN_CON0) & 0x0008) &&           /* Check PDN_CON0 WAVETABLE down */
            ((*PDN_CON1) & 0x0080) &&           /* Check PDN_CON1 LCD down */
            (((*PDN_CON3) & 0x7F91) == 0x7F91)&&           /* Check PDN_CON3 all down [GMC] (valid:0x7F91) */           
            *MCUCLK_CON == 0x0003 &&
#elif ( IS_CHIP_MT6217 )           
            (((*(volatile kal_uint32 *)0x80030000) & 0x00015555)==0) &&  /* Check DMA1~10, ignore DMA10~13 for 6217 */
            (((*PDN_CON0) & 0x0038) == 0x0038) &&           /* Check PDN_CON0 RESIZER, JPEG, and WAVETABLE down */
            ((*PDN_CON1) & 0x0080) &&           /* Check PDN_CON1 LCD down */
            *MCUCLK_CON == 0x0003 &&
#endif            
            dcm.dcmDisable == 0 
          )
      {
         #if ( (IS_CHIP_MT6228) || (IS_CHIP_MT6229)||(IS_CHIP_MT6235)||(IS_CHIP_MT6238))    
          	/* Gate GMC DMA */
            kal_uint32 tmp;
            tmp = GateDG();
            for (i = 0; i < 20; i++)
                ;
         #endif

         /*To access an address not in existance will ensure that EMI access is complete.*/
         #if ( (IS_CHIP_MT6238) || (IS_CHIP_MT6235) )
            j =  *(volatile kal_uint16 *)0x28000000; 
         #else
         j =  *(volatile kal_uint16 *)0x24000000; 
         #endif
         /*A26=1 means will not get data via data cache, it will access EMI directly.*/
         
         dcm_state = 1; /* DCM @ 104/52->13/26Mhz */ 

         /* Change WS and clock rate. */ 
         /* mtk01940 
           ======================================
	                        Idle      Dedi
	         MT6217         13MHz     x
	         MT6229         26MHz     26MHz
	         MT6227         13MHZ     26MHz
	         MT6223         13MHz     13MHz
	         MT6225
	         MT6228
	         MT6229
	         MT6227D
           ======================================
         */
         #if (IS_CHIP_MT6227 || IS_CHIP_MT6228)
           #ifdef MT6227D
             custom_DynamicClockSwitch( MCU_13MHZ );
           #else
             if(dcm.isIdleMode)
             {         
                custom_DynamicClockSwitch( MCU_13MHZ );
             }
             else
             {
                custom_DynamicClockSwitch( MCU_26MHZ );
             }
           #endif
         #elif (IS_CHIP_MT6229)
             custom_DynamicClockSwitch( MCU_26MHZ );
         #else
             custom_DynamicClockSwitch( MCU_13MHZ );  
         #endif
         /* mtk01940 */       
         
         dcm_state = 2; /* DCM @ 13/26MHz */
         
         #if ((IS_CHIP_MT6228) || (IS_CHIP_MT6229)||(IS_CHIP_MT6235)||(IS_CHIP_MT6238))  
            /* Recover GMC DMA gating */
            UngateDG(tmp);
         #endif
      
         /* check if IRQ is disabled for more than 60 qbits */
         end = *((volatile kal_uint16 *)(TDMA_base + 0x00));
         if (end >= start) {
            duration = end - start;
         } else {
            tqwrap = *(volatile kal_uint16 *)(TDMA_base + 0x04);
            duration = (tqwrap - start) + end;
         }
         if (duration > 60) {
            EXT_ASSERT(0, duration, start, end);
         }
         
         *SLEEP_CON = 0x0003;
         #if ( (IS_CHIP_MT6238) || (IS_CHIP_MT6235) )
            cp15_enter_low_pwr_state();
         #endif /* MT6238 */            
      }
      else
      {
      	*SLEEP_CON = 0x0001;
      	#if ( (IS_CHIP_MT6238) || (IS_CHIP_MT6235) )
           cp15_enter_low_pwr_state();
        #endif  /* MT6238 */   
      	   
      }
      
      RestoreIRQ(_savedMask);
   #elif defined(MT6218B)         
       kal_uint32 _savedMask;
       
       _savedMask = LockIRQ();

       if ( (((*(volatile kal_uint16 *)0x80000300) & 0x0038)==0x0038)  &&
             ((*(volatile kal_uint16 *)0x80000304) & 0x0080) )
       {
          /* Power down AHB only when WT & JPEG & Resizer & LCD is turned off. */	            
          *SLEEP_CON = 0x0003;  
       }	
       else
       {
          *SLEEP_CON = 0x0001;
       }	       
       
       RestoreIRQ(_savedMask);
   #else
      /*To temporarily avoid the problem on AHB.*/
      *SLEEP_CON = 0x0001; 
   #endif /* End #if defined(DCM_ENABLE)*/   
#endif /* End #if defined(MTK_SLEEP_ENABLE) || defined(L1D_TEST) */      
   }    /* Infinite loop */
}

#if defined( DCM_ENABLE )
void DCM_Recovery(void)
{  /* For MT6217/MT6227: back to 52MHz; For MT6228/MT6229: back to 104MHz */
   volatile kal_uint16 i,j=0;
      
   if( dcm_state == 2 ) 
   {
      #if ((IS_CHIP_MT6228) || (IS_CHIP_MT6229)||(IS_CHIP_MT6235) || (IS_CHIP_MT6238))    
       	/* Gate GMC DMA */
        kal_uint32 tmp;
      #endif
      
      /* mtk01940 
        ======================================
                       Idle      Dedi
        MT6217         13MHz     x
        MT6229         26MHz     26MHz
        MT6227         13MHZ     26MHz
        MT6223         13MHz     13MHz
        MT6225
        MT6228         
        MT6229
        ======================================
      */      
      #if (IS_CHIP_MT6227 || IS_CHIP_MT6228)
        #ifdef MT6227D
          EXT_ASSERT( *MCUCLK_CON == 0x0000,0,0,0 ); //13MHz
        #else
          if(dcm.isIdleMode)
          {
             EXT_ASSERT( *MCUCLK_CON == 0x0000,0,0,0 ); //13MHz
          }
          else
          {
             #if (IS_CHIP_MT6228)
             EXT_ASSERT( *MCUCLK_CON == 0x0101,0,0,0 ); //26MHz for MT6228
             #else
             EXT_ASSERT( *MCUCLK_CON == 0x0001,0,0,0 ); //26MHz for MT6227
             #endif
          }        
        #endif
      #elif (IS_CHIP_MT6229)
        EXT_ASSERT( *MCUCLK_CON == 0x0101,0,0,0 ); //26MHz
      #elif (IS_CHIP_MT6238)
        EXT_ASSERT( *MCUCLK_CON == 0x7000,0,0,0 ); //13MHz
      #else        
        EXT_ASSERT( *MCUCLK_CON == 0x0000,0,0,0 ); //13MHz
      #endif
      /* mtk01940 */

      dcm_state = 3; /* DCM @ 13/26->104/52MHz */
      
      #if ((IS_CHIP_MT6228) || (IS_CHIP_MT6229)||(IS_CHIP_MT6235)||(IS_CHIP_MT6238))    
       	/* Gate GMC DMA */
        tmp = GateDG();
         for (i = 0; i < 20; i++)
             ;
      #endif
                            
      /* I_Bit is disabled and Wait until EMI access is complete.
         Otherwise, some external(Burst/Async/Sync RAM), some will get problems. */
      #if ( (IS_CHIP_MT6238) || (IS_CHIP_MT6235) )
         j =  *(volatile kal_uint16 *)0x28000000; 
      #else
      j =  *(volatile kal_uint16 *)0x24000000; 
      #endif 
      /*A26=1 means will not get data via data cache, it will access EMI directly.*/
   
      /* Change WS and clock rate. */
      #if ((IS_CHIP_MT6228) || (IS_CHIP_MT6229) || (IS_CHIP_MT6225))
         custom_DynamicClockSwitch( MCU_104MHZ );
      #elif ((IS_CHIP_MT6217)|| (IS_CHIP_MT6227)|| (IS_CHIP_MT6223))
         custom_DynamicClockSwitch( MCU_52MHZ );
      #elif ((IS_CHIP_MT6238)|| (IS_CHIP_MT6235))
         custom_DynamicClockSwitch( MCU_208MHZ );
      #endif
      
      #if ( (IS_CHIP_MT6228) || (IS_CHIP_MT6229)||(IS_CHIP_MT6238)|| (IS_CHIP_MT6235))  
         /* Recover GMC DMA gating */
         UngateDG(tmp);
      #endif
      
      dcm_state = 0; /* DCM @ 104/52MHz */
      dcm_excuted = true;/* Record the execution of DCM and print in L1SM_FrameTick */
   }
}

#endif /* DCM_ENABLE */
  
#pragma arm section rwdata , rodata , zidata

#pragma arm section code

#if (IS_CHIP_MT6227_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION)
#if defined( DCM_ENABLE )
bool DCM_Query_Status(void)
{
   bool status = dcm_excuted;
   dcm_excuted = false;/* Restored to default state */
   return status;
} 
uint8 DCM_GetHandle( void )
{	
   EXT_ASSERT(dcm.dcmHandleCount<32,0,0,0);
   return dcm.dcmHandleCount++;   /* Using handle number from 0, not 1 */
}
void DCM_Enable( uint8 handle )
{   
   uint32 _savedMask;
   
   _savedMask = SaveAndSetIRQMask();
   dcm.dcmDisable &= ~(1 << handle);   
   RestoreIRQMask(_savedMask);
}
void DCM_Disable( uint8 handle )
{
   uint32 _savedMask;
   
   _savedMask = SaveAndSetIRQMask();
   dcm.dcmDisable |= (1 << handle);
   RestoreIRQMask(_savedMask);
}

/* mtk01940: for MT6227, to distinguish from dedi or idle */
#if (IS_CHIP_MT6227 || IS_CHIP_MT6228)
void DCM_IsIdleMode(bool isCurMode)
{
	dcm.isIdleMode = isCurMode;
}
#endif

#else
bool DCM_Query_Status(void) {}
uint8 DCM_GetHandle( void ) {}
void DCM_Enable( uint8 handle ) {}
void DCM_Disable( uint8 handle ) {}

/* mtk01940 */
#if (IS_CHIP_MT6227 || IS_CHIP_MT6228)
void DCM_IsIdleMode(bool isCurMode) {}
#endif

#endif /* DCM_ENABLE */
#endif /* IS_CHIP_MT6227_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION */

/*************************************************************************
* FUNCTION                                                            
*	idle_create
*
* DESCRIPTION                                                           
*	This function implements idle entity's create handler.
*
* PARAMETERS
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool
idle_create(comptask_handler_struct **handle)
{
	static const comptask_handler_struct idle_handler_info = 
	{
		IdleTask,			/* task entry function */
		NULL,			/* task initialization function */
		NULL,		/* task configuration function */
		NULL,			/* task reset handler */
		NULL			/* task termination handler */
	};

	*handle = (comptask_handler_struct *)&idle_handler_info;
#if (IS_CHIP_MT6227_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION)
#if defined (DCM_ENABLE)
	L1_DCM_Enable = true;
#else
	L1_DCM_Enable = false;
#endif
#endif
	return KAL_TRUE;
}
#else  /* __MTK_TARGET__ */
   
#endif


