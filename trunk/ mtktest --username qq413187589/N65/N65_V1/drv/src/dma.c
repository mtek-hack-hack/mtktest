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
 *    dma.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the DMA driver.
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
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
 *
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
 *
 * removed!
 * removed!
 *
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
 *
 * removed!
 * removed!
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#if ( (defined(MT6205)) || (defined(MT6205B)) || (defined(MT6208)) || (defined(FPGA)) )

#include "drv_comm.h"
#include "drv_hisr.h"
#include "reg_base.h"
#include "intrCtrl.h"
#include "drvpdn.h"
#include "dma_hw.h"
#include "dma_sw.h"
#include "che_hw.h"
#include "lcd_if.h"


//extern void UART_SetDMAIntr(void);
dma_func DMA_CallBac;

extern void DMA_USBTxLISR(void);
extern void DMA_USBRxLISR(void);

static void DMA_HISR(void);


/*
* FUNCTION
*	DMA1_CheckRunStat
*
* DESCRIPTION
*   	Check whether DAM1 is in running
*
* CALLS
*
* PARAMETERS
*	None
*
* RETURNS
*	KAL_TRUE, DMA1 is running
*	KAL_FALSE, DMA1 is stoped
*
* GLOBALS AFFECTED
*   external_global
*/
kal_bool DMA1_CheckRunStat(void)
{
	kal_uint16 tmp;
	tmp = DRV_Reg(DMA_GLBSTS);
	if (tmp & DMA_GLBSTS_RUN1)
		return KAL_TRUE;
	else
		return KAL_FALSE;
}

/*
* FUNCTION
*	DMA1_CheckITStat
*
* DESCRIPTION
*   	Check whether DAM1 has an interrupt pending
*
* CALLS
*
* PARAMETERS
*	None
*
* RETURNS
*	KAL_TRUE, DMA1 has an interrupt pending
*	KAL_FALSE, DMA1 doesn't have any interrupt pending
*
* GLOBALS AFFECTED
*   external_global
*/
kal_bool DMA1_CheckITStat(void)
{
	kal_uint16 tmp;
	tmp = DRV_Reg(DMA_GLBSTS);
	if (tmp & DMA_GLBSTS_IT1)
		return KAL_TRUE;
	else
		return KAL_FALSE;
}

/*
* FUNCTION
*	DMA1_Init
*
* DESCRIPTION
*   	DMA1 intialize the src addr, dst addr, and transfer size
*
* CALLS
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
void DMA1_Init(kal_uint32 src, kal_uint32 dst, kal_uint16 count,void func(void))
{
	kal_uint16 LSB;
	kal_uint16 MSB;

	LSB = (kal_uint16)src;
	MSB = (kal_uint16)(src >> 16);
	DRV_WriteReg(DMA1_MSBSRC,MSB);
   DRV_WriteReg(DMA1_LSBSRC,LSB);
	LSB = (kal_uint16)dst;
	MSB = (kal_uint16)(dst >> 16);
	DRV_WriteReg(DMA1_MSBDST,MSB);
   DRV_WriteReg(DMA1_LSBDST,LSB);
   DRV_WriteReg(DMA1_COUNT,count);

	DMA_CallBac.dma1_func = func;
}

/*
* FUNCTION
*	DMA2_CheckRunStat
*
* DESCRIPTION
*   	Check whether DAM2 is in running
*
* CALLS
*
* PARAMETERS
*	None
*
* RETURNS
*	KAL_TRUE, DMA2 is running
*	KAL_FALSE, DMA2 is stoped
*
* GLOBALS AFFECTED
*   external_global
*/
kal_bool DMA2_CheckRunStat(void)
{
	kal_uint16 tmp;
	tmp = DRV_Reg(DMA_GLBSTS);
	if (tmp & DMA_GLBSTS_RUN2)
		return KAL_TRUE;
	else
		return KAL_FALSE;
}

/*
* FUNCTION
*	DMA2_CheckITStat
*
* DESCRIPTION
*   	Check whether DAM2 has an interrupt pending
*
* CALLS
*
* PARAMETERS
*	None
*
* RETURNS
*	KAL_TRUE, DMA2 has an interrupt pending
*	KAL_FALSE, DMA2 doesn't have any interrupt pending
*
* GLOBALS AFFECTED
*   external_global
*/
kal_bool DMA2_CheckITStat(void)
{
	kal_uint16 tmp;
	tmp = DRV_Reg(DMA_GLBSTS);
	if (tmp & DMA_GLBSTS_IT2)
		return KAL_TRUE;
	else
		return KAL_FALSE;
}

/*
* FUNCTION
*	DMA1_Init
*
* DESCRIPTION
*   	DMA1 intialize the src addr, dst addr, and transfer size
*
* CALLS
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
void DMA2_Init(kal_uint32 src, kal_uint32 dst, kal_uint16 count,void func(void))
{
	kal_uint16 LSB;
	kal_uint16 MSB;

	LSB = (kal_uint16)src;
	MSB = (kal_uint16)(src >> 16);
	DRV_WriteReg(DMA2_MSBSRC,MSB);
	DRV_WriteReg(DMA2_LSBSRC,LSB);
	LSB = (kal_uint16)dst;
	MSB = (kal_uint16)(dst >> 16);
   DRV_WriteReg(DMA2_MSBDST,MSB);
	DRV_WriteReg(DMA2_LSBDST,LSB);
   DRV_WriteReg(DMA2_COUNT,count);
	DMA_CallBac.dma2_func = func;
}

/*
* FUNCTION
*	DMA_LISR
*
* DESCRIPTION
*   	DMA interrupt handler
*
* CALLS
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
void DMA_HISR(void)
{
	if ((DRV_Reg(DMA1_INTSTS))& DMA_INTSTS_MASK)
	{
	   DMA1_Stop();
	   DMA1_ACKI();
	   DMA_CallBac.dma1_func();
	}

	if ((DRV_Reg(DMA2_INTSTS))& DMA_INTSTS_MASK)
	{
	   DMA2_Stop();
	   DMA2_ACKI();
	   DMA_CallBac.dma2_func();
	}
	IRQClearInt(IRQ_DMA_CODE);
	IRQUnmask(IRQ_DMA_CODE);
}

void DMA_LISR(void)
{
   IRQMask(IRQ_DMA_CODE);

   drv_active_hisr(DRV_DMA_HISR_ID);
}

void DMA_Ini(void)
{
   *(volatile kal_uint16 *)DRVPDN_CON0_CLR = DRVPDN_CON0_DMA;

   IRQ_Register_LISR(IRQ_DMA_CODE, DMA_LISR,"DMA handler");

   DRV_Register_HISR(DRV_DMA_HISR_ID, DMA_HISR);

   IRQSensitivity(IRQ_DMA_CODE,LEVEL_SENSITIVE);

   IRQUnmask(IRQ_DMA_CODE);
}

#else /* MT6205 || MT6208 || MT6205B || FPGA */

#include "drv_comm.h"
#include "drv_hisr.h"
#include "reg_base.h"
#include "intrCtrl.h"
#include "dma_hw.h"
#include "dma_sw.h"
#include "drvpdn.h"
#include "che_hw.h"
#include "lcd_if.h"
#include "uart_sw.h"
#include "init.h"

typedef void (* VOID_FUNC)(void);

extern void DMA_USBTxLISR(void);
extern void DMA_USBRxLISR(void);
//extern void UART_SetDMAIntr(void);
extern void UART_TrxHandler_VFIFO(void *parameter);
extern void UART_RecHandler_VFIFO(void *parameter);
extern UARTStruct UARTPort[MAX_UART_PORT_NUM];
extern kal_uint32 kal_get_mytask_priority(void);

void DMA_ERROR_LISR(void);

#ifdef MT6218
VOID_FUNC DMA_LISR_FUNC[DMA_MAX_CHANNEL] =
{
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR
};
#elif defined(MT6218B) || defined(MT6217)
VOID_FUNC DMA_LISR_FUNC[DMA_MAX_CHANNEL] =
{
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR
};
#elif defined(MT6223) || defined(MT6223P)
VOID_FUNC DMA_LISR_FUNC[DMA_MAX_CHANNEL+2] =
{
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR
};
#else
VOID_FUNC DMA_LISR_FUNC[DMA_MAX_CHANNEL] =
{
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR
};
#endif

static DMA_GBL_CLASS dma_gbl_class_g;
static const kal_uint8 dma_gbl_class_to_grade[DMA_MAX_GBL_CLASS + 1]
   = { 0 /* CLASS 0 */, 10 /* CLASS 1 */, 50 /* CLASS 2 */, 100 /* CLASS 3 */, 200 /* CLASS 4 */ };
static kal_uint16 dma_gbl_count[DMA_MAX_GBL_CLASS]
   = { 0 /* CLASS 1 */, 0 /* CLASS 2 */, 0 /* CLASS 3 */, 0 /* CLASS 4 */ };
static const DMA_GBL_PRIORITY_BANK dma_gbl_priority_bank[DMA_GBL_TOTAL_PRIORITY_BANK]
   = { {0, 9, 1}, {10, 39, 2}, {40, 89, 3}, {90, 119, 4}, {120, 169, 5}, {170, 199, 6}, {200, 249, 7}, {250, 255, 8} };

kal_uint32 DMA_Channel_Status = 0xffff;
DMA_PWRCTRL DMA_PWR;
#if defined(MT6223) || defined(MT6223P)
DMA_Master DMA_Owner[DMA_MAX_CHANNEL+2];
#else
DMA_Master DMA_Owner[DMA_MAX_CHANNEL];
#endif

static void DMA_HISR(void);

void DMA_Stop(kal_uint8 channel)
{
	DMA_Stop_Now(channel);
	DMA_ACKI(channel);
}

void DMA_Run(kal_uint8 channel)
{
   DMA_Stop(channel);
   DMA_Start(channel);
}

void DMA_SleepEnable(kal_uint8 channel)
{
   kal_uint32 savedMask;

#if defined(MT6218B)
   return;
#endif   /*MT6218B*/

   savedMask = SaveAndSetIRQMask();

   DMA_PWR.sleepDisable &= ~(1 << channel);

   if (DMA_PWR.sleepDisable == 0)

      DRVPDN_Enable(DRVPDN_CON0,DRVPDN_CON0_DMA,PDN_DMA);

   RestoreIRQMask(savedMask);
}

void DMA_SleepDisable(kal_uint8 channel)
{
   kal_uint32 savedMask;

#if defined(MT6218B)
   return;
#endif   /*MT6218B*/

   savedMask = SaveAndSetIRQMask();

   if (DMA_PWR.sleepDisable == 0)

      DRVPDN_Disable(DRVPDN_CON0,DRVPDN_CON0_DMA,PDN_DMA);

   DMA_PWR.sleepDisable |= (1 << channel);

   RestoreIRQMask(savedMask);
}

kal_uint8 DMA_GetChannel(DMA_Master DMA_CODE)
{
   kal_uint8 index;
   kal_uint8 handle=0xff;
   kal_uint32 savedMask;
   savedMask = SaveAndSetIRQMask();
#if defined(MT6223) || defined(MT6223P)
   for (index = 4; index <= DMA_MAX_CHANNEL+2; index++)
#else /*MT6223*/
   for (index = 4; index <= DMA_MAX_CHANNEL; index++)
#endif
   {
      if ((DMA_Channel_Status & (0x01<<index)) != 0)
      {
         handle = index;
         DMA_Channel_Status &= ~(0x01<<index);
         break;
      }
   }
   RestoreIRQMask(savedMask);
   ASSERT(handle!=0xff);

#ifndef __PRODUCTION_RELEASE__
#if defined(MT6223) || defined(MT6223P)
   for (index = 4; index <= DMA_MAX_CHANNEL+2; index++)
#else
   for (index = 4; index <= DMA_MAX_CHANNEL; index++)
#endif
   {
      if (DMA_Owner[index-1]==DMA_CODE)
         ASSERT(0);
   }
#endif   /*__PRODUCTION_RELEASE__*/

   DMA_Owner[handle-1] = DMA_CODE;
   return handle;
}

void DMA_FreeChannel(kal_uint8 handle)
{
   kal_uint32 savedMask;
   savedMask = SaveAndSetIRQMask();
   DMA_Channel_Status |= (0x01<<handle);
   DMA_Stop(handle);
   DMA_Owner[handle-1] = DMA_IDLE;
   RestoreIRQMask(savedMask);
}

kal_uint8 DMA_FullSize_GetChannel(DMA_Master DMA_CODE)   /* Hw handler. handle = 1~3 */
{
   kal_uint8 index;
   kal_uint8 handle=0xff;
   kal_uint32 savedMask;

   savedMask = SaveAndSetIRQMask();

#ifdef MT6218B
   for (index = 2; index <= DMA_MAX_FULL_CHANNEL; index++)
#else
   for (index = 1; index <= DMA_MAX_FULL_CHANNEL; index++)
#endif
   {
      if ((DMA_Channel_Status & (0x01<<index)) != 0)
      {
         handle = index;
         DMA_Channel_Status &= ~(0x01<<index);
         break;
      }
   }

   RestoreIRQMask(savedMask);

   ASSERT(handle!=0xff);

#ifndef __PRODUCTION_RELEASE__
#ifdef MT6218B
   for(index=2;index<=DMA_MAX_FULL_CHANNEL;index++)
#else /*MT6218B*/
   for(index=1;index<=DMA_MAX_FULL_CHANNEL;index++)
#endif
   {
      if (DMA_Owner[index-1]==DMA_CODE)
         ASSERT(0);
   }
#endif   /*__PRODUCTION_RELEASE__*/

   DMA_Owner[handle-1] = DMA_CODE;

   return handle;
}

void DMA_FullSize_FreeChannel(kal_uint8 handle)
{
   kal_uint32 savedMask;

   savedMask = SaveAndSetIRQMask();

   DMA_Channel_Status |= (0x01<<handle);
   DMA_Stop(handle);
   DMA_Owner[handle-1] = DMA_IDLE;

   RestoreIRQMask(savedMask);
}

void DMA_Config_Internal(kal_uint8 dma_no, DMA_INPUT *dma_menu, kal_bool fullsize, kal_bool b2w, kal_uint8 limit, kal_bool start)
{
   ECO_VERSION eco;
   kal_uint32 dma_con = 0;
   kal_uint32 temp;
   kal_uint32 _savedMask;
   kal_uint32 priority;
   DMA_GBL_CLASS dma_gbl_class;
   kal_uint8 dma_gbl, bank = 0;


   if (DMA_CheckRunStat(dma_no) || DMA_CheckITStat(dma_no))
      ASSERT(0);

   ASSERT(DMA_Owner[dma_no - 1] != DMA_IDLE);

   if (fullsize == KAL_TRUE)
      ASSERT(b2w == KAL_FALSE);

   ASSERT(dma_menu->count <= 0xffff);

   DMA_Stop(dma_no);

   /* get chip version */
   eco = INT_ecoVersion();

#if defined(MT6225)
   /* it is not allowed to use "burst" tx in MT6225 E1, E2, E3*/
   if (eco <= ECO_E3) {
      if (((DMA_TMODE *)(dma_menu->menu))->burst_mode == KAL_TRUE) {
         if (dma_menu->type == DMA_HWTX || dma_menu->type == DMA_SWCOPY || dma_menu->type == DMA_HWTX_RINGBUFF) {
            EXT_ASSERT(0, dma_no, dma_menu->type, b2w);
         }
      }
   }
#endif  /* MT6225 */

   switch(dma_menu->type) {
   case  DMA_HWTX:

      if (fullsize == KAL_TRUE)
         temp = (kal_uint32)(((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->master);
      else
         temp = (kal_uint32)(((DMA_HWMENU *)dma_menu->menu)->master);

      dma_con |= (kal_uint32)(temp << 20);
      dma_con |= DMA_CON_TXCONTRL;
      dma_con |= DMA_CON_DRQ;

      if (fullsize == KAL_TRUE) {
         if (((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->TMOD.burst_mode) {
#ifdef MT6218
            dma_con |= DMA_CON_TMOD;
            dma_con |= (kal_uint32)(((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->TMOD.cycle) << 9;
#endif	/* MT6218 */
         }
      } else {
         if (((DMA_HWMENU *)dma_menu->menu)->TMOD.burst_mode) {
#ifdef MT6218
            dma_con |= DMA_CON_TMOD;
            dma_con |= (kal_uint32)(((DMA_HWMENU *)dma_menu->menu)->TMOD.cycle) << 9;
#endif	/* MT6218 */
         }
      }

      if (fullsize == KAL_TRUE) {
         DRV_WriteReg32(DMA_SRC(dma_no), ((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->source);
         DRV_WriteReg32(DMA_DST(dma_no), ((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->destination);
      }
      else {
         DRV_WriteReg32(DMA_PGMADDR(dma_no), ((DMA_HWMENU *)dma_menu->menu)->addr);
#if !defined(MT6218)
         if(b2w == KAL_TRUE)
            dma_con |= DMA_CON_B2W;
#endif
      }

      break;

   case  DMA_HWRX:

      if (fullsize == KAL_TRUE)
         dma_con |= (kal_uint32)(((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->master) << 20;
      else
         dma_con |= (kal_uint32)(((DMA_HWMENU *)dma_menu->menu)->master) << 20;

      dma_con |= DMA_CON_RXCONTRL;
      dma_con |= DMA_CON_DRQ;

      if (fullsize == KAL_TRUE) {
         if (((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->TMOD.burst_mode) {
#ifdef MT6218
            dma_con |= DMA_CON_TMOD;
            dma_con |= (kal_uint32)(((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->TMOD.cycle) << 9;
#endif	/* MT6218 */
         }
      } else {
         if (((DMA_HWMENU *)dma_menu->menu)->TMOD.burst_mode) {
#ifdef MT6218
            dma_con |= DMA_CON_TMOD;
            dma_con |= (kal_uint32)(((DMA_HWMENU *)dma_menu->menu)->TMOD.cycle) << 9;
#endif	/* MT6218 */
         }
      }

      if (fullsize == KAL_TRUE) {
         DRV_WriteReg32(DMA_SRC(dma_no), ((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->source);
         DRV_WriteReg32(DMA_DST(dma_no), ((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->destination);
      } else {
         DRV_WriteReg32(DMA_PGMADDR(dma_no), ((DMA_HWMENU *)dma_menu->menu)->addr);
#if !defined(MT6218)
         if(b2w == KAL_TRUE)
            dma_con |= DMA_CON_B2W;
#endif
      }

      break;

   case DMA_SWCOPY:

      DRV_WriteReg32(DMA_SRC(dma_no), ((DMA_SWCOPYMENU *)dma_menu->menu)->srcaddr);
      DRV_WriteReg32(DMA_DST(dma_no), ((DMA_SWCOPYMENU *)dma_menu->menu)->dstaddr);
      dma_con = DMA_CON_SWCOPY;

      break;

   case DMA_HWTX_RINGBUFF:

      if (fullsize == KAL_TRUE)
         dma_con |= ((kal_uint32)((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->master) << 20;
      else
         dma_con |= ((kal_uint32)((DMA_HWRINGBUFF_MENU *)dma_menu->menu)->master) << 20;

      dma_con |= DMA_CON_TXCONTRL;
      dma_con |= DMA_CON_DRQ;

      if (fullsize == KAL_TRUE) {
         if (((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->TMOD.burst_mode) {
#ifdef MT6218
            dma_con |= DMA_CON_TMOD;
            dma_con |= (kal_uint32)(((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->TMOD.cycle) << 9;
#endif	/* MT6218 */
         }
      } else {
         if (((DMA_HWRINGBUFF_MENU *)dma_menu->menu)->TMOD.burst_mode) {
#ifdef MT6218
            dma_con |= DMA_CON_TMOD;
            dma_con |= (kal_uint32)(((DMA_HWRINGBUFF_MENU *)dma_menu->menu)->TMOD.cycle) << 9;
#endif	/* MT6218 */
         }
      }

      dma_con |= DMA_CON_WPEN;   /*RAM->Register*/

      if (fullsize == KAL_TRUE) {
         DRV_WriteReg32(DMA_WPPT(dma_no), ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->WPPT);
         DRV_WriteReg32(DMA_WPTO(dma_no), ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->WPTO);
         DRV_WriteReg32(DMA_SRC(dma_no), ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->source);
         DRV_WriteReg32(DMA_DST(dma_no), ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->destination);
      } else {
         DRV_WriteReg32(DMA_WPPT(dma_no), ((DMA_HWRINGBUFF_MENU *)dma_menu->menu)->WPPT);
         DRV_WriteReg32(DMA_WPTO(dma_no), ((DMA_HWRINGBUFF_MENU *)dma_menu->menu)->WPTO);
         DRV_WriteReg32(DMA_PGMADDR(dma_no), ((DMA_HWRINGBUFF_MENU *)dma_menu->menu)->addr);
#if !defined(MT6218)
         if(b2w == KAL_TRUE)
            dma_con |= DMA_CON_B2W;
#endif
      }

      break;

   case DMA_HWRX_RINGBUFF:

      if (fullsize == KAL_TRUE)
         dma_con |= ((kal_uint32) ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->master) << 20;
      else
         dma_con |= ((kal_uint32) ((DMA_HWRINGBUFF_MENU *)dma_menu->menu)->master) << 20;

      dma_con |= DMA_CON_RXCONTRL;
      dma_con |= DMA_CON_DRQ;

      if (fullsize == KAL_TRUE) {
         if (((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->TMOD.burst_mode) {
#ifdef MT6218
            dma_con |= DMA_CON_TMOD;
            dma_con |= (kal_uint32)(((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->TMOD.cycle) << 9;
#endif	/* MT6218 */
         }
      } else {
         if (((DMA_HWRINGBUFF_MENU *)dma_menu->menu)->TMOD.burst_mode) {
#ifdef MT6218
            dma_con |= DMA_CON_TMOD;
            dma_con |= (kal_uint32)(((DMA_HWRINGBUFF_MENU *)dma_menu->menu)->TMOD.cycle) << 9;
#endif	/* MT6218 */
         }
      }

      dma_con |= DMA_CON_WPSD;      /*Register->RAM*/
      dma_con |= DMA_CON_WPEN;

      if (fullsize == KAL_TRUE) {
         DRV_WriteReg32(DMA_WPPT(dma_no), ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->WPPT);
         DRV_WriteReg32(DMA_WPTO(dma_no), ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->WPTO);
         DRV_WriteReg32(DMA_SRC(dma_no), ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->source);
         DRV_WriteReg32(DMA_DST(dma_no), ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->destination);
      } else {
         DRV_WriteReg32(DMA_WPPT(dma_no), ((DMA_HWRINGBUFF_MENU *)dma_menu->menu)->WPPT);
         DRV_WriteReg32(DMA_WPTO(dma_no), ((DMA_HWRINGBUFF_MENU *)dma_menu->menu)->WPTO);
         DRV_WriteReg32(DMA_PGMADDR(dma_no), ((DMA_HWRINGBUFF_MENU *)dma_menu->menu)->addr);
#if !defined(MT6218)
         if(b2w == KAL_TRUE)
            dma_con |= DMA_CON_B2W;
#endif
      }

      break;

   default:

      ASSERT(0);

      break;
   }

   switch(dma_menu->size) {
   case DMA_BYTE:

#if !defined(MT6218)
      if (dma_menu->type != DMA_SWCOPY) {

         if ( (((DMA_TMODE *)(dma_menu->menu))->burst_mode==KAL_TRUE) &&
              (((DMA_TMODE *)(dma_menu->menu))->cycle & 0xf0) )

            dma_con |= DMA_CON_BURST_16BEAT;

         else if ( (((DMA_TMODE *)(dma_menu->menu))->burst_mode==KAL_TRUE) &&
                   (((DMA_TMODE *)(dma_menu->menu))->cycle & 0x08) )

            dma_con |= DMA_CON_BURST_8BEAT;

         else if ( (((DMA_TMODE *)(dma_menu->menu))->burst_mode==KAL_TRUE) &&
                   (((DMA_TMODE *)(dma_menu->menu))->cycle & 0x04) )

             dma_con |= DMA_CON_BURST_4BEAT;
      }
#endif  /* ! MT6218 */

      break;

   case DMA_SHORT:

#if !defined(MT6218)
      if (dma_menu->type != DMA_SWCOPY) {

         if ( (((DMA_TMODE *)(dma_menu->menu))->burst_mode==KAL_TRUE) &&
              (((DMA_TMODE *)(dma_menu->menu))->cycle & 0xf8) )

            dma_con |= DMA_CON_BURST_8BEAT;

         else if ( (((DMA_TMODE *)(dma_menu->menu))->burst_mode==KAL_TRUE) &&
                   (((DMA_TMODE *)(dma_menu->menu))->cycle & 0x04) )

            dma_con |= DMA_CON_BURST_4BEAT;
      }
#endif  /* ! MT6218 */

      dma_con |= DMA_CON_SIZE_SHORT;

      break;

   case DMA_LONG:

#if !defined(MT6218)
      if (dma_menu->type != DMA_SWCOPY) {

         if ( (((DMA_TMODE *)(dma_menu->menu))->burst_mode==KAL_TRUE) &&
              (((DMA_TMODE *)(dma_menu->menu))->cycle & 0xfc) )

            dma_con |= DMA_CON_BURST_4BEAT;
      }
#endif  /* !MT6218 */

      dma_con |= DMA_CON_SIZE_LONG;

      break;

   default:

      ASSERT(0);

      break;
   }

   if (dma_menu->callback != NULL)
   {
      dma_con |= DMA_CON_ITEN;
      DMA_LISR_FUNC[dma_no-1] = dma_menu->callback;
   }

   DRV_WriteReg32(DMA_CON(dma_no),dma_con);
   DRV_WriteReg32(DMA_COUNT(dma_no),(kal_uint32)dma_menu->count);

   /* set the bandwidth limiter */

   _savedMask = SaveAndSetIRQMask();

   dma_gbl_class = dma_gbl_class_g;

   RestoreIRQMask(_savedMask);

   if (dma_gbl_class == 0) {

      /* full speed */

      DRV_WriteReg8(DMA_LIMITER(dma_no), 0);
   } else {

      dma_gbl = dma_gbl_class_to_grade[dma_gbl_class];

      priority = kal_get_mytask_priority();

      if (priority <= dma_gbl_priority_bank[0].upper && priority >= dma_gbl_priority_bank[0].lower)
         bank = dma_gbl_priority_bank[0].bank;
      else if (priority <= dma_gbl_priority_bank[1].upper && priority >= dma_gbl_priority_bank[1].lower)
         bank = dma_gbl_priority_bank[1].bank;
      else if (priority <= dma_gbl_priority_bank[2].upper && priority >= dma_gbl_priority_bank[2].lower)
         bank = dma_gbl_priority_bank[2].bank;
      else if (priority <= dma_gbl_priority_bank[3].upper && priority >= dma_gbl_priority_bank[3].lower)
         bank = dma_gbl_priority_bank[3].bank;
      else if (priority <= dma_gbl_priority_bank[4].upper && priority >= dma_gbl_priority_bank[4].lower)
         bank = dma_gbl_priority_bank[4].bank;
      else if (priority <= dma_gbl_priority_bank[5].upper && priority >= dma_gbl_priority_bank[5].lower)
         bank = dma_gbl_priority_bank[5].bank;
      else if (priority <= dma_gbl_priority_bank[6].upper && priority >= dma_gbl_priority_bank[6].lower)
         bank = dma_gbl_priority_bank[6].bank;
      else if (priority <= dma_gbl_priority_bank[7].upper && priority >= dma_gbl_priority_bank[7].lower)
         bank = dma_gbl_priority_bank[7].bank;
      else
         EXT_ASSERT(0, dma_gbl, priority, bank);

      DRV_WriteReg8(DMA_LIMITER(dma_no), DMA_GBL_PRIORITY_2_BL(bank, dma_gbl));
   }

#if defined(MT6218B) || defined(MT6217)
   lcd_dma_slow_down(dma_gbl_class);
#endif

   if (start) {

      /* configuration is done and start the DMA */

      DMA_Start(dma_no);
   }
}

void DMA_ERROR_LISR(void)
{
   while(1);
}

void DMA_HISR(void)
{
   kal_uint8 index;

#if	defined(MT6223) || defined(MT6223P)
  if (DRV_Reg32(DMA_INTSTA(1)) & DMA_INTSTA_BIT)
  {
      DMA_Stop(1);
      DMA_ACKI(1);
      DMA_LISR_FUNC[0]();
  }
  for(index = 3; index < DMA_MAX_CHANNEL+2; index++)
#else /* MT6223 */
	for(index = 0; index < DMA_MAX_CHANNEL; index++)
#endif
	{
	   if (DRV_Reg32(DMA_INTSTA(index+1)) & DMA_INTSTA_BIT)
	   {
	      DMA_Stop(index+1);
	      DMA_ACKI(index+1);
         DMA_LISR_FUNC[index]();
	   }
	}

#ifdef __DMA_UART_VIRTUAL_FIFO__
	// handle virtual fifo interrupt
	for(index=DMA_VFIFO_CH_S; index<=DMA_VFIFO_CH_E; index++)
	{
		kal_uint32 con = DRV_Reg32(DMA_CON(index));
		if (DRV_Reg32(DMA_INTSTA(index)) & DMA_INTSTA_BIT)
		{

			switch(con >> 20)
			{
				case DMA_CON_MASTER_UART1RX:
					UART_RecHandler_VFIFO(&UARTPort[uart_port1]);
					break;
				case DMA_CON_MASTER_UART1TX:
					UART_TrxHandler_VFIFO(&UARTPort[uart_port1]);
					break;
				case DMA_CON_MASTER_UART2RX:
					UART_RecHandler_VFIFO(&UARTPort[uart_port2]);
					break;
				case DMA_CON_MASTER_UART2TX:
					UART_TrxHandler_VFIFO(&UARTPort[uart_port2]);
					break;
				case DMA_CON_MASTER_UART3RX:
					UART_RecHandler_VFIFO(&UARTPort[uart_port3]);
					break;
				case DMA_CON_MASTER_UART3TX:
					UART_TrxHandler_VFIFO(&UARTPort[uart_port3]);
					break;
			}
			DMA_ACKI(index);
		}
	}
#endif //__DMA_UART_VIRTUAL_FIFO__
	IRQClearInt(IRQ_DMA_CODE);
	IRQUnmask(IRQ_DMA_CODE);
}

void DMA_LISR(void)
{
   IRQMask(IRQ_DMA_CODE);

   drv_active_hisr(DRV_DMA_HISR_ID);
}

void DMA_Ini(void)
{
   kal_uint8 index;

#if defined(MT6223) || defined(MT6223P)
   for (index = 0; index < DMA_MAX_CHANNEL+2; index++)
#else /* MT6223 */
   for (index = 0; index < DMA_MAX_CHANNEL; index++)
#endif
      DMA_Owner[index] = DMA_IDLE;

   *(volatile kal_uint16 *) DRVPDN_CON0_CLR = DRVPDN_CON0_DMA;

   IRQ_Register_LISR(IRQ_DMA_CODE, DMA_LISR, "DMA handler");

   DRV_Register_HISR(DRV_DMA_HISR_ID, DMA_HISR);

   IRQSensitivity(IRQ_DMA_CODE,LEVEL_SENSITIVE);

   IRQUnmask(IRQ_DMA_CODE);
}

kal_bool DMA_memcpy(const void *src, const void *dst, kal_uint32 length)
{
   kal_uint8 handle=0xff;
   DMA_INPUT input;
   DMA_SWCOPYMENU menu;

   handle = DMA_FullSize_GetChannel(DMA_SW);
   ASSERT(handle!=0xff);

   if (handle != 0xff)
   {
      menu.srcaddr = (kal_uint32)src;
      menu.dstaddr = (kal_uint32)dst;
      input.type = DMA_SWCOPY;
      input.menu = &menu;
      input.callback = NULL;

      if ((menu.srcaddr|menu.dstaddr|length) & 0x01)
      {
         if(length > 0xffff)
            return KAL_FALSE;
         input.size = DMA_BYTE;
         input.count = length;
      }
      else if ((menu.srcaddr|menu.dstaddr|length) & 0x02)
      {
         if((length>>1) > 0xffff)
            return KAL_FALSE;
         input.size = DMA_SHORT;
         input.count = length>>1;
      }
      else
      {
         if((length>>2) > 0xffff)
            return KAL_FALSE;
         input.size = DMA_LONG;
         input.count = length>>2;
      }

      DMA_FullSize_Config(handle,&input,KAL_TRUE);
      DMA_WaitUntilRdy(handle);
      DMA_FullSize_FreeChannel(handle);

      return KAL_TRUE;
   }
   else
   {
      return KAL_FALSE;
   }
}


/*
 * This function is used to set the DMA Global Bandwidth Limiter.
 * All DMA channels' bandwidth limit will be updated.
 */
DMA_GBL_HANDLE DMA_SetGBL(DMA_GBL_CLASS dma_gbl_class)
{
   kal_uint8 is_update;
   kal_uint32 _savedMask;
   kal_uint8 limiter;
   kal_uint16 i;

   if (dma_gbl_class > DMA_MAX_GBL_CLASS)
      return (DMA_GBL_HANDLE)DMA_INVALID_GBL_HANDLE;

   is_update = 0;

   _savedMask = SaveAndSetIRQMask();

   if (dma_gbl_class != 0)
      dma_gbl_count[dma_gbl_class - 1]++;

   if (dma_gbl_class > dma_gbl_class_g) {
      dma_gbl_class_g = dma_gbl_class;
      is_update = 1;
   }

   RestoreIRQMask(_savedMask);

   if (is_update == 1) {

      /* need to set DMA bandwidth limit */

      limiter = dma_gbl_class_to_grade[dma_gbl_class];

#ifdef MT6218B
      for (i = 2; i <= DMA_MAX_CHANNEL; i++)
#elif defined(MT6223) || defined(MT6223P) /* MT6218B */
      DRV_WriteReg8(DMA_LIMITER(1), limiter);
      for (i = 4; i <= DMA_MAX_CHANNEL+2; i++)
#else   /* MT6218B */
      for (i = 1; i <= DMA_MAX_CHANNEL; i++)
#endif   /* MT6218B */

         DRV_WriteReg8(DMA_LIMITER(i), limiter);

#if ( defined(MT6218B) || defined(MT6217) )
      lcd_dma_slow_down(dma_gbl_class);
#endif
   }

   return (DMA_GBL_HANDLE)dma_gbl_class;
}


/*
 * This function is used to restore the DMA Global Bandwidth Limiter.
 * All DMA channels' limiter will be updated.
 */
void DMA_RestoreGBL(DMA_GBL_HANDLE dma_gbl_handle)
{
   DMA_GBL_CLASS dma_gbl_class;
   kal_uint8 is_update, max;
   kal_int16 i;
   kal_uint32 _savedMask;
   kal_uint8 limiter;

   if (dma_gbl_handle == DMA_INVALID_GBL_HANDLE)
      return ;

   dma_gbl_class = (DMA_GBL_CLASS)dma_gbl_handle;

   if (dma_gbl_class > DMA_MAX_GBL_CLASS)
      return ;

   is_update = 0;

   /* update DMA GBL */

   _savedMask = SaveAndSetIRQMask();

   if (dma_gbl_class != 0)
      dma_gbl_count[dma_gbl_class - 1]--;

   max = 0;

   /* get the current max of available DMA gbl */
   for (i = DMA_MAX_GBL_CLASS - 1; i >= 0; i--) {
      if (dma_gbl_count[i] > 0) {
         max = i + 1;
         break;
      }
   }

   if (max != dma_gbl_class_g) {

      dma_gbl_class_g = max;

      is_update = 1;
   }

   RestoreIRQMask(_savedMask);

   if (is_update == 0)
      return ;
   else {

      /* need to set DMA bandwidth limit */

      limiter = dma_gbl_class_to_grade[dma_gbl_class];

#ifdef MT6218B
      for (i = 2; i <= DMA_MAX_CHANNEL; i++)
#elif defined(MT6223) || defined(MT6223P) /* MT6218B */
      DRV_WriteReg8(DMA_LIMITER(1), limiter);
      for (i = 4; i <= DMA_MAX_CHANNEL+2; i++)
#else /* MT6218B */
      for (i = 1; i <= DMA_MAX_CHANNEL; i++)
#endif /* MT6218B */

         DRV_WriteReg8(DMA_LIMITER(i), limiter);

#if ( defined(MT6218B) || defined(MT6217) )
      lcd_dma_slow_down(dma_gbl_class);
#endif
   }
}

#endif  /* MT6205 || MT6208 || MT6205B || FPGA */



#ifdef MT6218B

/*
* FUNCTION
*	dma_ch1_init
*
* DESCRIPTION
*  This function is used to initialize DMA channel 1.
*
* CALLS
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
 */
void dma_ch1_init(kal_uint32 dstaddr, kal_uint16 len, kal_uint8 limiter)
{
   DRV_WriteReg32(DMA_DST(1), dstaddr);

   DRV_WriteReg32(DMA_COUNT(1), (kal_uint32)len);

   DRV_WriteReg32(DMA_CON(1), 0 | DMA_CON_SIZE_BYTE | DMA_CON_SINC);

   DRV_WriteReg32(DMA_LIMITER(1),limiter);
}

/*
 * This function is used to start DMA channel 1 for transfer.
 */
void dma_ch1_start(kal_uint32 srcaddr)
{
   DMA_Stop_Now(1);

   DMA_ACKI(1);

   DRV_WriteReg32(DMA_SRC(1), srcaddr);

   DMA_Start(1);
}

/*
 * This function is used to stop transfer of DMA channel 1.
 */
void dma_ch1_stop()
{
   DMA_Stop_Now(1);

   DMA_ACKI(1);
}

#endif   /* MT6218B */


static kal_uint32 dma_slowdown_handle;
static kal_uint32 dma_slowdown_mask;

kal_uint8 dma_slowdown_get_handle(void)
{
   ASSERT(dma_slowdown_handle<32);
   return dma_slowdown_handle++;
}

void dma_slowdown(kal_uint8 handle)
{
   kal_uint32 _savedMask;

   _savedMask = SaveAndSetIRQMask();

   if (dma_slowdown_mask == 0)
   {
      /* Enable WT slowdown */
#if defined(MT6223) || defined(MT6223P)
      *(volatile kal_uint32*)0x80000700 |= 0xFF << 1;
#endif

      che_slowdown();

      /*
       * Original lcd_dma_slow_down(void) internally uses 0x3F as command
       * latency. Here we pass "4" to new lcd_dma_slow_down(level) such that
       * the command latency is longer than before.
       */

#if defined(MT6218B) || defined(MT6217) || defined(MT6223) || defined(MT6223P)
      {
         kal_uint8 index;

         lcd_dma_slow_down(DMA_GBL_CLASS4);

#ifdef MT6218B
         /* nop */
#else   /* MT6218B */
         DRV_WriteReg32(DMA_LIMITER(1),0xff);
#endif   /* MT6218B */

#if defined(MT6223)  || defined(MT6223P)
         /* DMA_MAX_CHANNEL = 6; Note DMA channel of MT6223 is not contiguous, ie.DMA 1,4,5,6,7,8 */
         for(index = 4; index <= DMA_MAX_CHANNEL+2; index++)
#else  /* MT6223 || defined(MT6223P)*/
         DRV_WriteReg32(DMA_LIMITER(2),0xff);

         DRV_WriteReg32(DMA_LIMITER(3),0xff);

         for(index = 4; index <= DMA_MAX_CHANNEL; index++)
#endif /* MT6223 || defined(MT6223P)*/
         {
            DRV_WriteReg32(DMA_LIMITER(index),0xc8);
         }
      }

#elif defined(MT6208) || defined(MT6205B)   /* MT6218B || MT6217 || MT6223 */

      lcd_dma_slow_down(4);

#endif   /* MT6218B || MT6217 || MT6223 || MT6223P */
   }

   dma_slowdown_mask |= (1 << handle);

   RestoreIRQMask(_savedMask);
}

/*
* FUNCTION
*	dma_recover
*
* DESCRIPTION
*  Recover DMA limiter
*
* CALLS
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*/
void dma_recover(kal_uint8 handle)
{
   kal_uint32 _savedMask;

   _savedMask = SaveAndSetIRQMask();

   dma_slowdown_mask &= ~(1 << handle);

   if (dma_slowdown_mask == 0)
   {
      che_recover();

#if defined(MT6208) || defined(MT6205B) || defined(MT6218B) || defined(MT6217) || defined(MT6223) || defined(MT6223P)
      lcd_dma_recovery();
#endif   /* MT6208 || MT6205B || MT6218B || MT6217 || MT6223 || MT6223P */

#if defined(MT6218B) || defined(MT6217) || defined(MT6223) || defined(MT6223P)
      {
         kal_uint8 index;
         kal_uint8 limiter;

         limiter = dma_gbl_class_to_grade[dma_gbl_class_g];

#ifdef MT6218B
         for(index = 2; index <= DMA_MAX_CHANNEL; index++)
         {
#elif defined(MT6223) || defined(MT6223P)   /* MT6218B */
         DRV_WriteReg32(DMA_LIMITER(1), limiter);
         for(index = 4; index <= DMA_MAX_CHANNEL+2; index++)
         {
#else   /* MT6218B */
         for(index = 1; index <= DMA_MAX_CHANNEL; index++)
         {
#endif   /* MT6218B */

            DRV_WriteReg32(DMA_LIMITER(index), limiter);
         }
      }
#endif   /* MT6218B || MT6217 || MT6223 */

	    /* Enable WT slowdown */
#if defined(MT6223) || defined(MT6223P)
         *(volatile kal_uint32*)0x80000700 &= ~0x1FE;
#endif
   }

   RestoreIRQMask(_savedMask);
}

/*
* FUNCTION
*	dma_recover_all
*
* DESCRIPTION
*  Recover all DMA limiter
*
* CALLS
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*/
void dma_recover_all()
{
   kal_uint32 _savedMask;
   kal_uint8 index;

#if !defined(MT6205B) && !defined(MT6208)
   kal_uint8 limiter;
#endif

   _savedMask = SaveAndSetIRQMask();

#if defined(MT6205B) || defined(MT6218B) || defined(MT6217) || defined(MT6223) || defined(MT6223P)
      lcd_dma_recovery();
#endif

#if !defined(MT6205B) && !defined(MT6208)

   limiter = dma_gbl_class_to_grade[dma_gbl_class_g];

#ifdef MT6218B
   for(index = 2; index <= DMA_MAX_CHANNEL; index++) {
#elif defined(MT6223)  || defined(MT6223P) /* MT6218B */
   DRV_WriteReg32(DMA_LIMITER(1), limiter);
   for(index = 4; index <= DMA_MAX_CHANNEL+2; index++) {   
#else   /* MT6218B */
   for(index = 1; index <= DMA_MAX_CHANNEL; index++) {
#endif   /* MT6218B */

      DRV_WriteReg32(DMA_LIMITER(index), limiter);
   }

#endif
	    /* Enable WT slowdown */
#if defined(MT6223) || defined(MT6223P)
         *(volatile kal_uint32*)0x80000700 &= ~0x1FE;
#endif

   RestoreIRQMask(_savedMask);
}


#ifdef __DMA_UART_VIRTUAL_FIFO__

/*
* FUNCTION
*	DMA_Vfifo_init
*
* DESCRIPTION
*  DMA virtual FIFO
*
* CALLS
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*/
void DMA_Vfifo_init(void)
{
	kal_uint32 dma_con = 0;

	if(UART_VFIFO_support[uart_port1])
	{
	// DMA10 for UART1 RX, DMA12 for UART1 TX
	dma_con = (DMA_CON_MASTER_UART1RX << 20)|DMA_CON_DIR|DMA_CON_DRQ|DMA_CON_ITEN;
	   //DRV_WriteReg32(DMA_CON(VDMA_UART1RX_CH),dma_con);
	   DRV_WriteReg32(DMA_CON(UARTPort[uart_port1].Rx_DMA_Ch),dma_con);
	dma_con = 0;
	dma_con = (DMA_CON_MASTER_UART1TX << 20)|DMA_CON_DRQ;
	   //DRV_WriteReg32(DMA_CON(VDMA_UART1TX_CH),dma_con);
	   DRV_WriteReg32(DMA_CON(UARTPort[uart_port1].Tx_DMA_Ch),dma_con);
   }

   if(UART_VFIFO_support[uart_port2])
   {
	// DMA11 for UART2 Rx, DMA13 for UART2 TX
	dma_con = (DMA_CON_MASTER_UART2RX << 20)|DMA_CON_DIR|DMA_CON_DRQ|DMA_CON_ITEN;
	   //DRV_WriteReg32(DMA_CON(VDMA_UART2RX_CH),dma_con);
	   DRV_WriteReg32(DMA_CON(UARTPort[uart_port2].Rx_DMA_Ch),dma_con);
	dma_con = 0;
	dma_con = (DMA_CON_MASTER_UART2TX << 20)|DMA_CON_DRQ;
	   //DRV_WriteReg32(DMA_CON(VDMA_UART2RX_CH),dma_con);
	   DRV_WriteReg32(DMA_CON(UARTPort[uart_port2].Tx_DMA_Ch),dma_con);
   }
	if(UART_VFIFO_support[uart_port3])
	{
	   // DMA13 for UART3 Rx, DMA14 for UART3 TX
	   dma_con = (DMA_CON_MASTER_UART3RX << 20)|DMA_CON_DIR|DMA_CON_DRQ|DMA_CON_ITEN;
	   //DRV_WriteReg32(DMA_CON(VDMA_UART3RX_CH),dma_con);
	   DRV_WriteReg32(DMA_CON(UARTPort[uart_port3].Rx_DMA_Ch),dma_con);
	   dma_con = 0;
	   dma_con = (DMA_CON_MASTER_UART3TX << 20)|DMA_CON_DRQ;
	   //DRV_WriteReg32(DMA_CON(VDMA_UART3TX_CH),dma_con);
	   DRV_WriteReg32(DMA_CON(UARTPort[uart_port3].Tx_DMA_Ch),dma_con);
   }
}

/*
* FUNCTION
*	DMA_Vfifo_SetAdrs
*
* DESCRIPTION
*  DMA virtual FIFO set address
*
* CALLS
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*/
void DMA_Vfifo_SetAdrs(kal_uint32 adrs, kal_uint32 len, DMA_VFIFO_UART ch, kal_bool IsTx )
{
	DRV_WriteReg32(DMA_PGMADDR(ch), adrs);
	DRV_WriteReg32(DMA_FFSIZE(ch), len);
	DRV_WriteReg32(DMA_ALTLEN(ch), DMA_VIFOF_ALERT_LENGTH); //maximum of alert threshold will effect the flow control
	DRV_Reg(DMA_COUNT(ch)) = (IsTx)?DMA_TX_TRIGGER_LEVEL(len):DMA_RX_TRIGGER_LEVEL(len); // set trigger level for DMA interrupt
}

/*
* FUNCTION
*	DMA_Vfifo_Flush
*
* DESCRIPTION
*  Flushing DMA virtual FIFO
*
* CALLS
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*/
void DMA_Vfifo_Flush(DMA_VFIFO_UART ch)
{
   DMA_Stop(ch);
   DMA_Start(ch);
}

#endif //__DMA_UART_VIRTUAL_FIFO__


