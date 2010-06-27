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
 *   Msdc_def.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Header file of MSDC driver
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================ 
 ****************************************************************************/
#ifndef MSDC_DEF_H
#define MSDC_DEF_H
#include "dma_sw.h"
#include "reg_base.h"

#define MSDC_MUST_RECORD_PLUGOUT

#define MSDC_DMA		// using DMA transfer instead of polling
#define MSDC_INT		// using hardware interrupt instead of polling
#define MSDC_SD_BITS4_BUS		// using 4bits bus width for SD card which has this feature
#define MMC40_USE_4BIT_BUS // support 4-bit bus for MMC4.0 (MT6218B, MT6219 and later)
// MMC40_USE_8BIT_BUS // only supported by MT6227 MT6228 MT6229 and later

#if defined(__MSDC_SD_MMC__)
#define MSDC_USE_USB_CLK
#if !defined(__MSDC_SD_SDIO__)
#define SD_MMC_HIGH_DENSITY_SUPPORT
#endif
#endif
// #define USE_DMA_BURST
// #define MSDC_DEBUG_INFO
// #define MSDC_USE_INT
//#define MSDC_DEBUG	// used for test and debug
//#define MASS			// using for mass data transfer testing
//#define SD_ERASE
//#define FIFO_THLD		// Set FIFO Threshold
//#define SD_STOP_SLOW // used for some card with incorrect busy status (Siemens, 


//registers address definition
#define MSDC_ADRS		MSDC_base 
// MSDC_CLOCK in the unit of kHz
#if defined(MCU_26M)
#define MSDC_CLOCK		26000		// (kHz)
#define MSDC_OP_CLOCK	13000	
#elif defined(MCU_52M)
#define MSDC_CLOCK		52000		// (kHz)
#define MSDC_OP_CLOCK	13000	
#elif defined(MCU_104M)
#define MSDC_CLOCK		104000	// (kHz)
#define MSDC_OP_CLOCK	13000	
#elif defined(MCU_208M)
#define MSDC_CLOCK		208000	// (kHz)
#define MSDC_OP_CLOCK	13000	
#endif

#if defined(MSDC_USE_USB_CLK)
#define MSDC_CLOCK_USB		48000		// (kHz)
#define MSDC_SD_OP_CLOCK	24000	
	#if defined(__SIM_PLUS__)
	#define MSDC_MMC_OP_CLOCK	12000		
	#endif
#endif

#if defined(DRV_MSDC_MT6225_SERIES)
    #define MSDC_MULTI_BLOCK_WRITE  // enable multiblock write at the same time
#endif
#define __MSDC_NO_WRITE_PROTECT__
// T-Flash card use CD/DAT3 as the card detection and use only one bit data bus
#if defined(__MSDC_TFLASH_DAT3_1BIT_HOT_PLUG__)
	#if defined(MSDC_SD_BITS4_BUS)
		#undef MSDC_SD_BITS4_BUS
	#endif	
	#if defined(__MSDC_NOT_SUPPORT_HOT_PLUG__)
		#undef __MSDC_NOT_SUPPORT_HOT_PLUG__
	#endif	
	#if !defined(__MSDC_NO_WRITE_PROTECT__)
	#define __MSDC_NO_WRITE_PROTECT__
	#endif
#endif
//#define APB_ACCESS_CLK	0x80000400	
// common for SD/MMC and MS(memory stick)
#ifndef DRV_LSD
#define MSDC_CFG		(MSDC_ADRS)
#define MSDC_STA		(MSDC_ADRS+0x04)
#define MSDC_INTR		(MSDC_ADRS+0x08)
#define MSDC_DAT		(MSDC_ADRS+0x0c)
#define MSDC_PS		(MSDC_ADRS+0x10)

#define MSDC_IOCON	(MSDC_ADRS+0x14)	
#else
#define MSDC_CFG		LSD_MSDC_CFG
#define MSDC_STA		LSD_MSDC_STA
#define MSDC_INTR		LSD_MSDC_INT
#define MSDC_DAT		LSD_MSDC_DAT
#define MSDC_PS			LSD_MSDC_PS
#define MSDC_IOCON		LSD_MSDC_IOCON
#endif

#if defined(DRV_MSDC_MT6238_SERIES)
#define MSDC_ADRS2 	MSDC2_base

#define MSDC_CFG2		(MSDC_ADRS2)
#define MSDC_STA2		(MSDC_ADRS2+0x04)
#define MSDC_INTR2	(MSDC_ADRS2+0x08)
#define MSDC_DAT2		(MSDC_ADRS2+0x0c)
#define MSDC_PS2		(MSDC_ADRS2+0x10)
#define MSDC_IOCON2	(MSDC_ADRS2+0x14)
#endif

// macros
#define IS_MSDC_DMA_RUN(a) 	 *(volatile kal_uint32 *)DMA_GLBSTA & (kal_uint32)DMA_GLBSTA_RUN(a)

// masks for MSDC_CFG 
#define MSDC_CFG_MSDC		((kal_uint32)0x00000001)
#define MSDC_CFG_RED			((kal_uint32)0x00000002)
#define MSDC_CFG_NOCRC		((kal_uint32)0x00000004)
#define MSDC_CFG_RST			((kal_uint32)0x00000008)
//#define MSDC_CFG_PWS		((kal_uint32)0x00000010)		// removed
#define MSDC_CFG_CLKSRC		((kal_uint32)0x00000010) //0: MCU, 1: USB
#define MSDC_CFG_STDBY		((kal_uint32)0x00000020)
#define MSDC_CFG_CRED		((kal_uint32)0x00000040)
#define MSDC_CFG_SCKON		((kal_uint32)0x00000080)
#define MSDC_CFG_SCLKF		((kal_uint32)0x0000ff00)
#define MSDC_CFG_INTEN		((kal_uint32)0x00010000)
#define MSDC_CFG_DRQEN		((kal_uint32)0x00020000)
#define MSDC_CFG_PINEN		((kal_uint32)0x00040000)
#define MSDC_CFG_DIRQE		((kal_uint32)0x00080000)
#define MSDC_CFG_RCDEN		((kal_uint32)0x00100000)
#define MSDC_CFG_VDDPD		((kal_uint32)0x00200000)
#define MSDC_CFG_PRCFG0		((kal_uint32)0x00c00000)	// MT6219 INS pin, MT6228, MT6229, MT6227 WP pin control
#define MSDC_CFG_PRCFG1		((kal_uint32)0x03000000)	// CMD/BS pin control
#define MSDC_CFG_PRCFG2		((kal_uint32)0x0c000000)	// DAT pin control
#define MSDC_CFG_FIFOTHD	((kal_uint32)0xf0000000)
#define MSDC_CFG_FIFOTHD_1	((kal_uint32)0x10000000)
#define MSDC_CFG_FIFOTHD_4	((kal_uint32)0x40000000)


// masks for MSDC_STA
#define MSDC_STA_BF			0x0001
#define MSDC_STA_BE	      0x0002
#define MSDC_STA_DRQ	   	0x0004
#define MSDC_STA_INT	    	0x0008
#define MSDC_STA_FIFOCNT	0x00f0
#define MSDC_STA_FIFOCLR	0x4000
#define MSDC_STA_BUSY		0x8000

#define MSDC_INT_DIRQ		0x0001
#define MSDC_INT_PINIRQ		0x0002
#define MSDC_INT_SDCMDIRQ	0x0004
#define MSDC_INT_SDDATIRQ	0x0008
#define MSDC_INT_SDMCIRQ	0x0010
#define MSDC_INT_MSIFIRQ	0x0020
#define MSDC_INT_SDR1BIRQ	0x0040

// SDIO
#define MSDC_INT_SDIOIRQ	0x80

// masks for MSDC_PS
#define MSDC_PS_CDEN			0x0001
#define MSDC_PS_PIEN0		0x0002
#define MSDC_PS_POEN0		0x0004
#define MSDC_PS_PIN0			0x0008
#define MSDC_PS_PINCH		0x0010

//#if defined(MT6228)||defined(MT6229) || defined(MT6227)|| defined(MT6226)|| defined(MT6226M)
#define MSDC_PS_DEBOUNCE	0xf000
#define MSDC_PS_DAT			0xff0000
#define MSDC_PS_CMD			0x1000000
//#endif


#define MSDC_IOCON_ODCCFG0		0x0007	// driving capacity of CMD/BS and SCLK
#define MSDC_IOCON_ODCCFG1		0x0038	// driving capacity of data lines
#define MSDC_IOCON_SCRCFG0		0x0040	// slew rate of the CMD/BS and SCLK
#define MSDC_IOCON_SCRCFG1		0x0080	// slew rate of the data lines
//#if defined(MT6228)||defined(MT6229) || defined(MT6227)|| defined(MT6226)|| defined(MT6226M)
#define MSDC_IOCON_PRCFG3		0x0300	// configure the INS pin status
//#endif
#define MSDC_IOCON_CMDRE		0x8000	// 0: latch the command at rising edge, 1: at falling edge
#define MSDC_IOCON_DLT			0xFF000000 // data latch timing 

#if !defined(DRV_MSDC_MT6225_SERIES)
// configure the output driving capacity and slew rate
#define MSDC_ODC_2MA			0x0
#define MSDC_ODC_4MA			0x1
#define MSDC_ODC_6MA			0x2
#define MSDC_ODC_8MA			0x3
// only MT6227, MT6217 and MT6218B can support following driving capacity
//#if defined(MT6228)||defined(MT6229) || defined(MT6227)|| defined(MT6226)|| defined(MT6226M)
#define MSDC_ODC_10MA		0x4
#define MSDC_ODC_12MA		0x5
#define MSDC_ODC_14MA		0x6
#define MSDC_ODC_16MA		0x7
//#endif
#else
#define MSDC_ODC_4MA			0x0
#define MSDC_ODC_8MA			0x2
#define MSDC_ODC_12MA		0x4
#define MSDC_ODC_16MA		0x6
#endif

#define MSDC_ODC_SLEW_FAST		1
#define MSDC_ODC_SLEW_SLOW		0

//#if defined(MT6228)||defined(MT6229) || defined(MT6227)|| defined(MT6226)|| defined(MT6226M)
#define MSDC_IOCTRL_INS_DISABLE			0
#define MSDC_IOCTRL_INS_PULL_DOWN		1
#define MSDC_IOCTRL_INS_PULL_UP			2
#define MSDC_IOCTRL_INS_KEEPER			3
//#endif

// useful macros
#ifndef DRV_LSD
#define MSDC_WriteReg32(adrs,data)	*(volatile kal_uint32*)(adrs) = (kal_uint32)(data)
#define MSDC_ReadReg32(adrs,pdata)	*(kal_uint32*)(pdata) = *(volatile kal_uint32*)(adrs)
#define MSDC_WriteReg16(adrs,data)	*(volatile kal_uint16*)(adrs) = (kal_uint16)(data)
#define MSDC_ReadReg16(adrs,pdata)	*(kal_uint16*)(pdata) = *(volatile kal_uint16*)(adrs)
#define MSDC_SET_BIT32(address, mask)	*(volatile kal_uint32*)(address) |= (mask)
#define MSDC_CLR_BIT32(address, mask)	*(volatile kal_uint32*)(address) &= ~(mask)
#define MSDC_SET_BIT16(address, mask)	*(volatile kal_uint16*)(address) |= (mask)
#define MSDC_CLR_BIT16(address, mask)	*(volatile kal_uint16*)(address) &= ~(mask)
#define MSDC_CLR_FIFO()			MSDC_SET_BIT32(MSDC_STA,MSDC_STA_FIFOCLR)
#define MSDC_IS_FIFO_EMPTY		(*(volatile kal_uint16*)MSDC_STA & MSDC_STA_BE)
#define MSDC_IS_FIFO_FULL		(*(volatile kal_uint16*)MSDC_STA & MSDC_STA_BF)
#define MSDC_IS_BUSY			(*(volatile kal_uint16*)MSDC_STA & MSDC_STA_BUSY)
#define MSDC_SET_FIFO(x)	{MSDC_CLR_BIT32(MSDC_CFG,MSDC_CFG_FIFOTHD);\
									*(volatile kal_uint32*)MSDC_CFG |= (x << 28);}

#define TurnOnMSDC()			(*(volatile kal_uint16*)DRVPDN_CON1_CLR) = 0x200
#define TurnOffMSDC()		(*(volatile kal_uint16*)DRVPDN_CON1_SET) = 0x200
#define MSDC_CLR_INT()		{\
					kal_uint32 tmp;\
					tmp = *(volatile kal_uint16*)MSDC_INTR;\
				}
#define SET_FIFO_THRESHOLD(n)	*((volatile kal_uint32*)(MSDC_CFG)) &= ~MSDC_CFG_FIFOTHD; \
					*((volatile kal_uint32*)(MSDC_CFG)) |= n << 28;
#define MSDC_IS_INT				(*(volatile kal_uint16*)MSDC_STA& MSDC_STA_INT)
#else
#define MSDC_WriteReg16(adrs,data)		LSD_WriteReg32(adrs,data)
#define MSDC_ReadReg16(adrs,pdata)		LSD_ReadReg16(adrs,pdata)
#define MSDC_ReadReg32(adrs,pdata)		LSD_ReadReg32(adrs,pdata)
#define MSDC_WriteReg32(adrs,data)		LSD_WriteReg32(adrs,data)
#define MSDC_SET_BIT32(address, mask)	LSD_SetBit32(address, mask)
#define MSDC_CLR_BIT32(address, mask)	LSD_ClrBit32(address, mask)
#define MSDC_SET_BIT16(address, mask)	LSD_SetBit32(address, mask)
#define MSDC_CLR_BIT16(address, mask)	LSD_ClrBit32(address, mask)
#define MSDC_IS_BUSY					LSD_IS_BUSY()
#define TurnOnMSDC()					LSD_PDNControl(KAL_FALSE);
#define MSDC_CLR_FIFO()					LSD_CLR_FIFO()
#define MSDC_CLR_INT()
#endif
#define EnableMSDC_DMA()	MSDC_SET_BIT32(MSDC_CFG,MSDC_CFG_DRQEN)
#define DisableMSDC_DMA()	MSDC_CLR_BIT32(MSDC_CFG,MSDC_CFG_DRQEN)
#define RESET_MSDC()			{	\
										kal_uint32 i= 20;\
										MSDC_SET_BIT32(MSDC_CFG,MSDC_CFG_RST);\
										while(i--);\
										MSDC_CLR_BIT32(MSDC_CFG,MSDC_CFG_RST);\
									}
#define MSDC_ENABLE_INT()		MSDC_SET_BIT32(MSDC_CFG,MSDC_CFG_INTEN)
#define MSDC_DISABLE_INT()		MSDC_CLR_BIT32(MSDC_CFG,MSDC_CFG_INTEN)
#define MSDC_ENABLE_CARD_DETECTION()	MSDC_SET_BIT32(MSDC_PS, MSDC_PS_CDEN)
#define MSDC_DISABLE_CARD_DETECTION()	MSDC_CLR_BIT32(MSDC_PS, MSDC_PS_CDEN)	

#if defined(DRV_MSDC_MT6238_SERIES)
#define MSDC_CLR_FIFO2()			MSDC_SET_BIT32(MSDC_STA2,MSDC_STA_FIFOCLR)
#define MSDC_IS_FIFO_EMPTY2		(*(volatile kal_uint16*)MSDC_STA2 & MSDC_STA_BE)
#define MSDC_IS_FIFO_FULL2		(*(volatile kal_uint16*)MSDC_STA2 & MSDC_STA_BF)
#define MSDC_IS_BUSY2			(*(volatile kal_uint16*)MSDC_STA2 & MSDC_STA_BUSY)
#define MSDC_SET_FIFO2(x)	{MSDC_CLR_BIT32(MSDC_CFG2,MSDC_CFG_FIFOTHD);\
									*(volatile kal_uint32*)MSDC_CFG2 |= (x << 28);}

#define TurnOnMSDC2()			(*(volatile kal_uint16*)DRVPDN_CON0_CLR) = DRVPDN_CON0_MSDC2
#define TurnOffMSDC2()		(*(volatile kal_uint16*)DRVPDN_CON0_SET) = DRVPDN_CON0_MSDC2
#define MSDC_CLR_INT2()		{\
					kal_uint32 tmp;\
					tmp = *(volatile kal_uint16*)MSDC_INTR2;\
				}
#define SET_FIFO_THRESHOLD2(n)	*((volatile kal_uint32*)(MSDC_CFG2)) &= ~MSDC_CFG_FIFOTHD; \
					*((volatile kal_uint32*)(MSDC_CFG2)) |= n << 28;
#define MSDC_IS_INT2				(*(volatile kal_uint16*)MSDC_STA2& MSDC_STA_INT)
#define EnableMSDC_DMA2()	MSDC_SET_BIT32(MSDC_CFG2,MSDC_CFG_DRQEN)
#define DisableMSDC_DMA2()	MSDC_CLR_BIT32(MSDC_CFG2,MSDC_CFG_DRQEN)
#define RESET_MSDC2()			{	\
										kal_uint32 i= 20;\
										MSDC_SET_BIT32(MSDC_CFG2,MSDC_CFG_RST);\
										while(i--);\
										MSDC_CLR_BIT32(MSDC_CFG2,MSDC_CFG_RST);\
									}
#define MSDC_ENABLE_INT2()		MSDC_SET_BIT32(MSDC_CFG2,MSDC_CFG_INTEN)
#define MSDC_DISABLE_INT2()		MSDC_CLR_BIT32(MSDC_CFG2,MSDC_CFG_INTEN)
#define MSDC_ENABLE_CARD_DETECTION2()	MSDC_SET_BIT32(MSDC_PS2, MSDC_PS_CDEN)
#define MSDC_DISABLE_CARD_DETECTION2()	MSDC_CLR_BIT32(MSDC_PS2, MSDC_PS_CDEN)	

#endif // DRV_MSDC_MT6238_SERIES

// define event flags
#define EVENT_SDCMDIRQ		((kal_uint32)0x00000001)
#define EVENT_SDDATIRQ		((kal_uint32)0x00000002)
#define EVENT_SDMCIRQ		((kal_uint32)0x00000004)
#define EVENT_MSIFIRQ		((kal_uint32)0x00000008)
#define EVENT_SDR1BIRQ		((kal_uint32)0x00000010)
#define EVENT_PINIRQ		((kal_uint32)0x00000020)
#define EVENT_MSRDYIRQ		((kal_uint32)0x00000040)
#define EVENT_DMAIRQ		((kal_uint32)0x00000100)
#define EVENT_INVALID_IRQ	((kal_uint32)0x80000000)
#define EVENT_ALLIRQ (EVENT_SDCMDIRQ|EVENT_SDDATIRQ|EVENT_SDMCIRQ|EVENT_MSIFIRQ|EVENT_SDR1BIRQ|EVENT_PINIRQ|EVENT_DMAIRQ)

#define MSDC_NOERROR						0
#define MSDC_ERR_CARD_DETECT			101
#define MSDC_CARD_NOT_PRESENT			102
#define MSDC_DMA_FAIL					104
#define MSDC_GPT_TIMEOUT_ERR			199

#define MSDC_TIMEOUT_PERIOD_INI		1100	//	x1ms
#define MSDC_TIMEOUT_PERIOD_DAT		100	//	x10ms
#define MSDC_TIMEOUT_PERIOD_CMD		50	//	x10ms
#define MSDC_INI_CLOCK					240	// kHz
#define MSDC_WRITE_THD_POLL			2*128		// 1K bytes
#define MSDC_READ_THD_POLL				8*128		// 4k bytes

//#if defined(MT6225)
#if defined(DRV_MSDC_INSWP_GPIO_MT6225_SERIES)
#define MSDC_GPIO_MCINS					45
#define MSDC_GPIO_WP						44
#else
#define MSDC_GPIO_MCINS					14
#define MSDC_GPIO_WP						15
#endif

#ifdef __CUST_NEW__
extern const char gpio_simplug_ldo_switch;
extern const char gpio_sim_msdc_switch;
#else
extern  kal_char gpio_simplug_ldo_switch;
extern  kal_char gpio_sim_msdc_switch;
#endif
#define GPIO_LDO_SWITCH 				gpio_simplug_ldo_switch
#define GPIO_EXT_SD_LDO_SWITCH		gpio_ext_sd_ldo_switch
#define GPIO_SIM_MSDC_SWITCH 			gpio_sim_msdc_switch
#define GPIO_SELECT_MSDC				0
#define GPIO_SELECT_SIM					1
#define ENTER_CRITICAL()		{\
													kal_uint32 _savedMask;\
													_savedMask = SaveAndSetIRQMask();

#define EXIT_CRITICAL()			RestoreIRQMask(_savedMask);}


// enum
typedef enum {
	MS_CARD = 0,
	SD_CARD = 1,
	MMC_CARD = 2,
	MSPRO_CARD = 3,
	MMC40_CARD = 4,
	SD20_LCS_CARD = 5,	// SD 2.0 compliant but with byte access mode. (<=2G)
	SD20_HCS_CARD = 6,	// SD 2.0 compliant but with block access mode. (>2G)
	MMC42_CARD = 7,		// MMC 4.2 compliant with block access mode
	MMC_CARD_SIMPLUS = 8,
	
	MSDC_CARD_TYPE_MAX,
	UNKNOWN_CARD = 0xF3
} T_MSDC_CARD;


typedef enum {
	POLLING,
	INTERRUPT,
	DMA
}T_RESP_TYPE;

typedef enum{
	FREQ_1BY2 = 0,		// f = 1/2 * 52M
	FREQ_1BY4 = 1,
	FREQ_1BY8 = 2,
	FREQ_1BY16 = 3
}SerClock_enum;

typedef enum{
 MSDC_IOCTRL_DISABLE		= 0,
 MSDC_IOCTRL_PULL_DOWN	= 1,
 MSDC_IOCTRL_PULL_UP		= 2,
 MSDC_IOCTRL_KEEPER		= 3
}msdc_ioctrl_enum;

#if defined(__SIM_PLUS__)
typedef enum{
	SD_EXT = 0,
	SD_SIM = 1,
	SD_NUM = 2
}sd_select_enum;
/*bewlow comes after JRD SIM+ issue on 2007_03_08, add custom setting on "clock without sim+" and "ext_sd ldo" */
typedef enum{
 MSDC_13M	= 0,
 MSDC_24M	= 1,
}msdc_ClockWithoutSIMPlus;

#define MSDC_NO_EXT_LDO					0xFF
/*end of JRD SIM+ issue on 2007_03_08*/
#elif defined(DRV_MSDC_MT6238_SERIES)
typedef enum{
	SD_EXT = 0,
	SD_MSDC1 = 0,
	SD_MSDC2 = 1,		
	SD_NUM = 2
}sd_select_enum;
#else
typedef enum{
	SD_EXT = 0,
	SD_MSDC1 = 0,
	SD_NUM = 1
}sd_select_enum;
#endif

typedef struct 
{
	//LOCAL_PARA_HDR
	kal_uint8 media_size;
	void *media_array;
}msdc_card_detect_ind_struct; 

typedef struct 
{
	kal_uint32					msdc_clock;	// clock rate of MSDC	
	kal_uint32					op_clock;		
	kal_uint32 					total_count; // separate transfer count larger than 16 bits into various parts.	
	kal_uint32 					timeout_period;  // x 10ms

#if !( (defined(MT6205)) || (defined(MT6205B)) || (defined(MT6208)) || (defined(FPGA)) )
	DMA_INPUT  					msdc_input;
	DMA_HWMENU 					msdc_menu;
#endif
	
	volatile T_MSDC_CARD		mMSDC_type;	// indicate the type of card(SD, MMC, MS)
	volatile kal_bool			mIsPresent; // card is present or not
	volatile kal_bool			mIsInitialized; // card is initialized or not
	volatile kal_bool			mIsChanged; // card is changed or not
	volatile kal_bool 		is_timeout;	// flag to indicate whther the gpt is expired		
	kal_bool						mIsPWDown;	// is MSDC is power down
	kal_uint8 					gpt_handle;	// handler of gpt timer 		
	kal_uint8	 				cmd_sta;
	kal_uint8					dat_sta;
	msdc_ioctrl_enum			ins_level;	// indicate the INS pin pull status;
	kal_uint8 					timeout_count;
	kal_bool						is_poll;
	kal_bool						is_aligned;
	kal_bool						is_init_timeout; // the initialization process larger than 1 sec
	kal_bool						send_ilm;	// 1: means to send ilm to fmt task
	kal_uint8 					msdc_dmaport;
	kal_eventgrpid          MSDC_Events;
#if defined(MSDC_DEBUG_INFO)
kal_char msdc_fname[20];
kal_uint32 msdc_lines;
#endif
	
}MSDC_HANDLE, *pMSDC_HANDLE; 

typedef struct
{
	T_MSDC_CARD type; // indicate the type of card(SD, MMC, MS)
	kal_bool	present; // card is present or not
}msdc_card_ind_strcut;

typedef struct
{
	kal_uint8 cmd_clk_odc;
	kal_uint8 dat_odc;
	kal_uint8 cmd_clk_slew;
	kal_uint8 dat_slew;
}msdc_io_ctrl_struct;

typedef enum
{
	MSDC_HOT_PLUG = 		0x1,	// MSDC support hot plugging
	MSDC2_HOT_PLUG = 		0x2,	// MSDC2 support hot plugging
	MSDC_WP = 				0x4,	//  MSDC support write protecton detection
	MSDC2_WP = 				0x8,	// MSDC2 support write protection detection
	MSDC_SD4_SDIO1 =		0x10,	// SD/MMC use MSDC1(4-bits) and SDIO use MSDC2(1-bits)
	MSDC_SDIO4_SD1	= 		0x20	// vice versa
	//MSDC_SDIO4_SDIO1,  // not support now
}msdc_custom_enum;

extern MSDC_HANDLE MSDC_Blk[SD_NUM];
extern MSDC_HANDLE *gMSDC_Handle;
extern kal_uint32 MSDC_Sector[128];
extern sd_select_enum current_card;
#ifdef MSDC_MUST_RECORD_PLUGOUT
extern kal_bool MSDC_everPlugOut;
#endif

#define EXT_MEM_ID			(kal_uint32)(&MSDC_Blk[SD_EXT])
#define SIMPLUS_MEM_ID		(kal_uint32)(&MSDC_Blk[SD_SIM])

#if defined(MSDC_DEBUG_INFO)
#define MSDC_START_TIMER(x) \
		strcpy(MSDC_Blk[0].msdc_fname,__FILE__);\
		MSDC_Blk[0].msdc_lines = __LINE__;\
		MSDC_Blk[0].is_timeout = KAL_FALSE;\
		GPTI_StartItem(MSDC_Blk[0].gpt_handle,\
                  x,\
                  MSDC_TimeOutHandler,\
                  NULL)
#else
#define MSDC_START_TIMER(x) \
		MSDC_Blk[0].is_timeout = KAL_FALSE;\
		GPTI_StartItem(MSDC_Blk[0].gpt_handle,\
                  x,\
                  MSDC_TimeOutHandler,\
                  NULL)
#endif

#define MSDC_STOP_TIMER()			\
		if(!MSDC_Blk[0].mIsPresent )\
			return MSDC_CARD_NOT_PRESENT;\
		if(!MSDC_Blk[0].is_timeout)\
		{\
			GPTI_StopItem(MSDC_Blk[0].gpt_handle);\
		}\
		else\
		{\
			kal_set_eg_events(MSDC_Blk[0].MSDC_Events, 0, KAL_AND);\
		}

#define MSDC_START_TIMER2(x) \
		MSDC_Blk[1].is_timeout = KAL_FALSE;\
		GPTI_StartItem(MSDC_Blk[1].gpt_handle,\
                  x,\
                  MSDC_TimeOutHandler,\
                  NULL)

#define MSDC_STOP_TIMER2()			\
		if(!MSDC_Blk[1].mIsPresent )\
			return MSDC_CARD_NOT_PRESENT;\
		if(!MSDC_Blk[1].is_timeout)\
		{\
			GPTI_StopItem(MSDC_Blk[1].gpt_handle);\
		}\
		else\
		{\
			kal_set_eg_events(MSDC_Blk[1].MSDC_Events, 0, KAL_AND);\
		}
		
// extern functions
void MSDC_Initialize(void);
kal_bool MSDC_CardDetect(void);
void MSDC_HostSelect(T_MSDC_CARD type);
void BitFieldWrite32(kal_uint32 * dest, kal_uint32 src, kal_uint32 mask);
void BitFieldRead32(kal_uint32 * dest, kal_uint32 src, kal_uint32 mask);
void GetBitFieldN(kal_uint8* dest, kal_uint8* src, kal_uint16 start_bit, kal_uint16 width);
void MSDC_LISR(void);
void MSDC_HISR_Entry(void);
void MSDC_DMA_LISR(void);
void MSDC_DMA_HISR_Entry(void);

extern void MSDC_PDNControl(kal_bool ON);
extern 	kal_bool MSDC_GetMediaChanged(void* id);
extern void MSDC_SendCardInd(module_type dest_id,sd_select_enum sel );
extern int MSDC_GetCardStatus(void *slot_id, int AckType);
extern void MSDC_InvertN(kal_uint8 *dest, kal_uint8 *src, kal_uint8 len);
extern void MSDC_TimeOutHandler(void *parameter);
extern kal_bool MSDC_Check_Card_Present(void);
extern void MSDC_SetClock(kal_uint32 clock);
extern void MSDC_DMATransferFirst(kal_uint32 adrs,kal_uint32 count, kal_bool isTx);
extern kal_uint32 MSDC_DMATransferFinal(void);
extern 	void MSDC_Switch_Card(sd_select_enum sel);
extern void MSDC_Config_INS_WP(msdc_ioctrl_enum ins, msdc_ioctrl_enum wp);

#if defined(__MSDC2_SD_MMC__) || defined(__MSDC2_SD_SDIO__)
void MSDC_Initialize2(void);
void MSDC_LISR2(void);
void MSDC_HISR_Entry2(void);
extern void MSDC_PDNControl2(kal_bool ON);
extern	kal_bool MSDC_GetMediaChanged2(void* id);
extern int MSDC_GetCardStatus2(void *slot_id, int AckType);
extern void MSDC_TimeOutHandler2(void *parameter);
extern kal_bool MSDC_Check_Card_Present2(void);
extern void MSDC_SetClock2(kal_uint32 clock);
extern void MSDC_DMATransferFirst2(kal_uint32 adrs,kal_uint32 count, kal_bool isTx);
extern kal_uint32 MSDC_DMATransferFinal2(void);
#endif // __MSDC2_SD_MMC__

#endif // end of MSDC_DEF_H


