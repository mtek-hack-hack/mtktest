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
 *   init.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the HW initialization.
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*******************************************************************************
 * Include header files
 *******************************************************************************/

#include "kal_release.h"
#include "reg_base.h"
#include "init.h"
#include "intrCtrl.h"
#include "isrentry.h"
#include "custom_config.h"
#include "stack_buff_pool.h"
#include "fat_fs.h"
#include "drv_comm.h"
#include "bmt.h"
#include "pwic.h"
#include "wdt_sw.h"
#include "bl_MTK_BB_REG.h"
#include "drvpdn.h"
#include <stdio.h>
#include <string.h>
#include <rt_misc.h>   /* for __rt_lib_init() */
#include <stdlib.h>
#ifdef __CHIP_VERSION_CHECK__
#include "Uart_sw.h"
#endif /* __CHIP_VERSION_CHECK__ */

#if defined(MT6208)
#include "drv_comm.h"
#include "wdt_sw.h"
#endif /* MT6208 */

#ifdef __MULTI_BOOT__
#include "syscomp_config.h"
#include "multiboot_config.h"
#endif   /*__MULTI_BOOT__*/

#include "gpio_sw.h"
#include "cache_sw.h"


/*******************************************************************************
 * Define pragma
 *******************************************************************************/

#ifdef __ADS__
#if (!defined(MT6208) && !defined(MT6205B))
#pragma import __use_realtime_division
#endif   /* !MT6208 && MT6205B */
#else   /* __ADS__ */
#pragma import __use_realtime_division
#endif   /* __ADS__ */


/*******************************************************************************
 * Define global data
 *******************************************************************************/

static kal_uint16 _boot_mode = 0 /* NORMAL Mode */;
kal_uint32 rand_num_seed;
static kal_uint16 _32khz_gpio_pin = 0xFFFF;
static kal_uint16 _32khz_gpio_data = 0xFFFF;
static kal_uint32 _32khz_user_cnt;

/*
 * Need to use a segment of internal RAM to generate randum number seed.
 * We pick up address 0x40002000 since it won't be modified by other
 * program such as bootloader.
 */
static const kal_uint32 RAND_GEN_START_ADDR = 0x40002000;


/*******************************************************************************
 * Declare import data
 *******************************************************************************/

extern BMTStruct BMT;          /* Main BMT struct */
extern boot_mode_type system_boot_mode;
extern kal_uint32 SYS_Stack_Pool[];


/*******************************************************************************
 * Declare import function prototype 
 *******************************************************************************/

static void systemIntialization(void);
static void HWDInitialization(void);
static void systemInitializeResource(void);

#if defined(KAL_ON_NUCLEUS) && defined(NU_DEBUG)
#define RTOS_DEBUG
#endif	/* KAL_ON_NUCLEUS && NU_DEBUG */

#if defined(KAL_ON_THREADX) && !defined(TX_DISABLE_ERROR_CHECKING)
#define RTOS_DEBUG
#endif	/* KAL_ON_THREADX && !TX_DISABLE_ERROR_CHECKING */

#if defined(KAL_ON_OSCAR)
#define RTOS_DEBUG
#endif  /* KAL_ON_OSCAR */

#define _SST_FUNCTION_ENABLE_

#ifdef _SST_FUNCTION_ENABLE_
/* under construction !*/
#endif  /* _SST_FUNCTION_ENABLE_ */

extern int  mainp(void);
extern void Drv_Init_Phase1(void);
extern void Drv_Init_Phase2(void);
extern int  stack_check_msgid_range(void);
extern void kal_initialize_mem(void);
extern void fatal_error_handler( kal_uint8 *, kal_int32, kal_int32);
extern kal_char *release_dsp_fw(void);
extern kal_char *release_dsp_ptch(void);
extern kal_char *release_verno(void);
extern kal_char *release_branch(void);
extern kal_char *release_hw_ver(void);

#ifdef _MAUI_SOFTWARE_LA_
/* under construction !*/
#endif /* _MAUI_SOFTWARE_LA_ */

#if !defined(__L1_STANDALONE__) && !defined(EMPTY_MMI)
extern void  MMICheckDiskDisplay(void);
#endif

#ifdef IDMA_DOWNLOAD
extern void idma_load(void);
#endif /* IDMA_DOWNLOAD */

#ifdef MTK_SLEEP_ENABLE
extern void L1SM_Init( void );
#endif

#ifndef L1_NOT_PRESENT
extern void L1D_SetInitMode( kal_int16 mode );
#else
extern void HW_Divider_Initialization(void);
#endif /* !L1_NOT_PRESENT */

#if !defined(__MAUI_BASIC__)
extern void Initialize_FDD_tables(void);
extern int Check_NORFlash_Formatted(void);
#endif

#ifdef __USB_ENABLE__
extern kal_bool INT_USBBoot(void);
extern void isrCTIRQ1_USBPowerOn(void);
#endif /*__USB_ENABLE__*/

#if ( (defined(__MTK_TARGET__) || defined (MTK_KAL_MNT)) && !defined(__MAUI_BASIC__) && !defined(__L1_STANDALONE__)  && !defined(EMPTY_MMI) ) 
extern void InitializeResourceVariables(void);
#endif /* __MTK_TARGET__ || MTK_KAL_MNT */

#ifdef _NAND_FLASH_BOOTING_
extern kal_bool NFB_SecondaryImageLoaded;
extern void NFB_LoadingSecondaryMAUI(void);
extern void NFB_InitThirdROM(void);
#endif

#ifdef __CHIP_VERSION_CHECK__
extern void U_PutUARTByte(UART_PORT port, kal_uint8 data);
#endif /* __CHIP_VERSION_CHECK__ */


/*************************************************************************
* FUNCTION
*  INT_SetPLL
*
* DESCRIPTION
*  This function dedicates for PLL setting.
*
* CALLS
*  Non
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void INT_SetPLL(void)
{
#ifdef MT6205B

#if defined(EXT_26M)
   
   /*for DSP configuration*/
   *(volatile kal_uint16 *)PDN_CLR0 =  0x8000;			/* PDN_CON0 turn on DSP div by 2 */
   *(volatile kal_uint16 *)CLK_CON |= 0x0001;      /* DSP div by 2 */
    
#if defined(MCU_26M)
   *(volatile kal_uint16 *)MPLL = 0x0001;       /* MCU - MCU Frequency register on MT6205B */
#elif defined (MCU_13M) /* MCU_26M */
   *(volatile kal_uint16 *)PDN_CLR0 = 0x1000;			/* PDN_CON0 turn on MCU div by 2 */
   *(volatile kal_uint16 *)CLK_CON |= 0x0008;   /* MCU div by 2 */
   *(volatile kal_uint16 *)MPLL = 0x0000;       /* MCU - MCU Frequency register on MT6205B */
#endif /* MCU_26M */
      
#endif /* EXT_26M */
      
#ifndef __MAUI_BASIC__
   *(volatile kal_uint16*)PREFETCH_CON = 0x0003;
#endif /* !__MAUI_BASIC__ */

#endif   /* MT6205B */


#if defined(MT6208) && defined(EXT_13M)
{
   kal_uint32 delay;

   /* configuration for MT6208, which features 13, 26, 39 and 52MHz */
   *(volatile kal_uint16 *)PDN_SET0 = 0xa807;
   *(volatile kal_uint16 *)PDN_CLR0 = ~0xa807;

#ifdef MPLLX1
   *(volatile kal_uint16 *)MPLL = 0x0000;
#elif defined(MPLLX2)
   *(volatile kal_uint16 *)MPLL = 0x0001;
#elif defined(MPLLX3)
   *(volatile kal_uint16 *)MPLL = 0x0002;
#elif defined(MPLLX4)
   *(volatile kal_uint16 *)MPLL = 0x0003;
#endif /* MPLL */

   for (delay=0;delay<1000;delay++);

   *(volatile kal_uint16 *)CLK_CON = 0x0002;

#ifdef MPLLX1
#ifndef __MAUI_BASIC__
   /* For stability issue */
   *(volatile kal_uint16*)PREFETCH_CON = 0x0003;
#endif /* !__MAUI_BASIC__ */
#endif /* MPLLX1 */
}
#endif /* MT6208 && EXT_13M */


#if defined(MT6218) || defined(MT6218B) || defined(MT6219)
{
   kal_uint16 i;

#ifdef MCU_52M

#ifdef EXT_26M

   // Power on DSP_DIV2, MPLL, DPLL, MCU_DIV2, and CLKSQ
   *(volatile kal_uint16 *)PDN_CLR0   	= ~0x04ff;
   // Enable MCU clock divider
   *(volatile kal_uint16 *)0x80000108 = 0x0008;
   // Reset the MPLL and setting MPLL to 52MHz
   *(volatile kal_uint16 *)0x80000100 = 0x0083;
   *(volatile kal_uint16 *)0x80000100 = 0x0003;
   // delay until PLL is stable
   for (i=0;i<200;i++);
   // Enable MPLL output
   *(volatile kal_uint16 *)0x80000108 = 0x000a;

#elif defined (EXT_13M) /* EXT_26M */

   // Power on MPLL, DPLL and CLKSQ
   *(volatile kal_uint16 *)PDN_CLR0   	= ~0x94ff;
   // Reset the MPLL and setting MPLL to 52MHz
   *(volatile kal_uint16 *)0x80000100 = 0x0083;
   *(volatile kal_uint16 *)0x80000100 = 0x0003;
   // delay until PLL is stable
   for (i=0;i<200;i++);
   // Enable MPLL output
   *(volatile kal_uint16 *)0x80000108 = 0x0002;
   
#endif   /* EXT_26M */

#elif defined (MCU_26M) /* MCU_52M */

#ifdef EXT_26M

    // Power on DSP_DIV2, MPLL, DPLL, MCU_DIV2, and CLKSQ
    *(volatile kal_uint16 *)PDN_CLR0   	= ~0x04ff;
    // Enable MCU clock divider
    *(volatile kal_uint16 *)0x80000108 = 0x0008;
    // Reset the MPLL and setting MPLL to 26MHz
    *(volatile kal_uint16 *)0x80000100 = 0x0081;
    *(volatile kal_uint16 *)0x80000100 = 0x0001;
    // delay until PLL is stable
    for (i=0;i<200;i++);
    // Enable MPLL output
    *(volatile kal_uint16 *)0x80000108 = 0x000a;

#elif defined (EXT_13M) /* EXT_26M */

    // Power on CLKSQ
    *(volatile kal_uint16 *)PDN_CLR0   	= ~0x94ff;
    // Reset the MPLL and setting MPLL to 26MHz
    *(volatile kal_uint16 *)0x80000100 = 0x0081;
    *(volatile kal_uint16 *)0x80000100 = 0x0001;
    // delay until PLL is stable
    for (i=0;i<200;i++);
    // Enable MPLL output
    *(volatile kal_uint16 *)0x80000108 = 0x0002;
      
#endif   /* EXT_26M */

#endif   /* MCU_52M */
}
#endif   /* MT6218 || MT6218B || MT6219 */


#if defined(MT6217) || defined(MT6226) || defined(MT6227) || defined(MT6226M) || defined(MT6227D) || defined(MT6226D)
{
	kal_uint16 i;

#ifdef EXT_26M

   // Power on DSP_DIV2, MPLL, DPLL, MCU_DIV2, and CLKSQ
    *(volatile kal_uint16 *)PDN_CLR0   	= ~0x04ff;
   // Enable MCU clock divider
   *(volatile kal_uint16 *)0x80000108 = 0x0008;
   // Reset the MPLL and setting MPLL to 52MHz
#if defined(MT6217)
   *(volatile kal_uint16 *)0x80000100 = 0x0083;
   *(volatile kal_uint16 *)0x80000100 = 0x0003;
#else /* MT6217 */
   *(volatile kal_uint16 *)0x80000100 = 0x0084;
   *(volatile kal_uint16 *)0x80000100 = 0x0004;
#endif   /* MT6217 */

	// delay until PLL is stable
	for (i=0;i<200;i++);
   // Enable MPLL output
   *(volatile kal_uint16 *)0x80000108 = 0x000a;

#elif defined (EXT_13M) /* EXT_26M */

   // Power on MPLL, DPLL and CLKSQ
   *(volatile kal_uint16 *)PDN_CLR0   	= ~0x94ff;
   // Reset the MPLL and setting MPLL to 52MHz
#if defined(MT6217)
   *(volatile kal_uint16 *)0x80000100 = 0x0083;
   *(volatile kal_uint16 *)0x80000100 = 0x0003;
#else /* MT6217 */
   *(volatile kal_uint16 *)0x80000100 = 0x0084;
   *(volatile kal_uint16 *)0x80000100 = 0x0004;
#endif   /* MT6217 */
	// delay until PLL is stable
	for (i=0;i<200;i++);
   // Enable MPLL output
   *(volatile kal_uint16 *)0x80000108 = 0x0002;
   
#endif   /* EXT_26M */

#ifdef MCU_52M
   *(volatile kal_uint16 *)0x80000114 = 0x0003;
#elif defined (MCU_39M)
   *(volatile kal_uint16 *)0x80000114 = 0x0002;
#elif defined (MCU_26M)
   *(volatile kal_uint16 *)0x80000114 = 0x0001;
#elif defined (MCU_13M)
   *(volatile kal_uint16 *)0x80000114 = 0x0000;
#endif
}
#endif   /* MT6217 || MT6226 || MT6227 || MT6226M */

#if defined(MT6228) || defined(MT6229) || defined(MT6230)
{
	kal_uint16 i;

#ifdef EXT_26M
   // 1. Power on DSP_DIV2, MCU_DIV2, and CLKSQ
   *PDN_CLR0 = 0x9800;
   // 2. Enable MCU clock divider
   *CLK_CON = 0x0008;
#elif defined (EXT_13M)
   // Power on CLKSQ
   *PDN_CLR0 = 0x0800;
#endif

   // 3. Boost MCU and DSP PLL (MDPLL) to 104MHz (MUST)
   *MPLL = 0x0087;
   *MPLL = 0x0007;
   
   // 4. Power ou MPLL
   *PDN_CLR0 = 0x4000;
   
   // 5. delay until PLL is stable, at least 50us
	for (i=0;i<0x100;i++);
   
   // 6. Define ARM(CPU, Data cache, TCM) and MCU PLL
#ifdef MCU_104M   
   // MCU and BUS clock 2:1
   *MCUCLK_CON = 0x0703;
#elif defined MCU_52M
   // MCU and BUS clock 1:1
   *MCUCLK_CON = 0x0303;
#elif defined MCU_26M
   // MCU and BUS clock 1:1
   *MCUCLK_CON = 0x0101;
#elif defined MCU_13M
   // MCU and BUS clock 1:1
   *MCUCLK_CON = 0x0000;   
#endif      

   // 7. Enable MPLL output
   *CLK_CON |= 0x0002;   
}
#endif   /* MT6228 || MT6229 || MT6230 */

#if defined(MT6223)	|| defined(MT6223P)
{
	kal_uint16 i;

#ifdef EXT_26M
   // 1. Power on DSP_DIV2, MCU_DIV2, PLL and CLKSQ
   *PDN_CLR0 = 0xb800;
   // 2. Enable MCU clock divider
   *CLK_CON = 0x0002;
   
#elif defined (EXT_13M) 
   // Power on PLL and CLKSQ
   *PDN_CLR0 = 0x2800;
#endif

   // 3. Select PLL input from CLKSQ, set div_ctrl to 6 such that PLL gives 104MHz clock
   *PLL = 0xc008;
   
   // 4. Reset PLL
   *PLL = 0Xc088;
   
   // 5. Select CLKSQ_DIV2_MCU to provide 13MHz
   *CLK_CON = 0x2;
   
   // 6. Define ARM(CPU, Data cache, TCM) and MCU PLL
#ifdef  MCU_52M
   // MCU and BUS clock 1:1
   *MCUCLK_CON = 0x0303;
#elif defined MCU_26M
   // MCU and BUS clock 1:1
   *MCUCLK_CON = 0x0101;
#elif defined MCU_13M
   // MCU and BUS clock 1:1
   *MCUCLK_CON = 0x0000;   
#endif      
   
   // 7. MPLL/2 nad DPLL/2 enable
   *CLK_CON = 0x3; 
   
   // 8. delay until PLL is stable, at least 50us
	for (i=0;i<0x200;i++);

   // 9. DPLLSEL = 1'b1, MPLLSEL=2'b10
   *PLL = 0xc030; // 
}
#endif   /* MT6223 	|| defined(MT6223P)*/

#ifdef MT6225
{
	kal_uint16 i;

#ifdef EXT_26M
   // 1. Power on DSP_DIV2, MCU_DIV2, and CLKSQ
   *PDN_CLR0 = 0x9800;
   // 2. Enable MCU clock divider
   *CLK_CON = 0x0002;
#elif defined (EXT_13M)
   // Power on CLKSQ
   *PDN_CLR0 = 0x0800;
#endif

   // 3. Boost MCU and DSP PLL (MDPLL) to 104MHz (MUST)
   *PLL = 0x0080;
   *PLL = 0x0000;
   
   // 4. Power ou MPLL
   *PDN_CLR0 = 0x2000;
   
   // 5. delay until PLL is stable, at least 50us
   for (i=0;i<0x100;i++);
   
   // 6. Define ARM(CPU, Data cache, TCM) and MCU PLL
#ifdef MCU_104M   
   // MCU and BUS clock 2:1
   *MCUCLK_CON = 0x0703;
#elif defined MCU_52M
   // MCU and BUS clock 1:1
   *MCUCLK_CON = 0x0303;
#elif defined MCU_26M
   // MCU and BUS clock 1:1
   *MCUCLK_CON = 0x0101;
#elif defined MCU_13M
   // MCU and BUS clock 1:1
   *MCUCLK_CON = 0x0000;   
#endif      

   // 7. Enable MPLL output
   *PLL |= 0x0010;   
}
#endif  /* MT6225 */
#if defined(MT6238)
	{
		kal_uint16 i;

	   // 1. Power on DSP_DIV2, MPLL, DPLL, MCU_DIV2, and CLKSQ
	   *PDN_CON = 0x0000;
	   
	   // 2. Enable MCU/DSP clock divider
#ifdef EXT_26M
		*CLK_CON = 0x0083;
#elif defined (EXT_13M)
	   	*CLK_CON = 0x0003;
#endif

	   // 3. Reset PLL.
	   *PLL = 0x0080;
	   
	   // 4. Release the reset, wait for PLL output stable.
	   *PLL = 0x0000;

	   // 5. delay until PLL is stable, at least 50us
	   for (i=0;i<0x100;i++);    
	   
	   // 6. Select PLL output for M/U/D-PLL.
	   *PLL = 0x0070;

	   // 7. Define ARM(CPU, Data cache, TCM) and MCU Clock.
#ifdef MCU_208M   
		*MCUCLK_CON = 0x7F37;		
#elif MCU_104M   
		*MCUCLK_CON = 0x7737;
#elif defined MCU_52M
		*MCUCLK_CON = 0x7333;
#elif defined MCU_26M
		*MCUCLK_CON = 0x7111;
#elif defined MCU_13M
		*MCUCLK_CON = 0x7000;   
#endif  	   
	}
#endif	// #if defined(MT6238)

}

/*__FUE__ compile option is used for FOTA firmware update engine */
/*add this  compile option  to avoid compiling other function*/
#ifndef __FUE__



void delayms(unsigned int t)
{
	unsigned int  i;
	while(t--)
	{
		i=9600 ;
		while(i--);	
	}
}


/*************************************************************************
* FUNCTION
*  Application_Initialize
*
* DESCRIPTION
*   This function implements project protocol stack, hardware depedent
* initialization
*
* CALLS
*  Initialize()
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
#if defined(KAL_ON_NUCLEUS)
//Huyanwei Touch Here
void Application_Initialize (void *first_available_memory)
#elif defined(KAL_ON_THREADX)
void tx_application_define(void *first_unused_memory)
#endif
{
   /* setlocale(LC_CTYPE,"C"); */
   __rt_lib_init(0, 0);   /* passing 0 since we don't use the heap */

   /* Multi-Boot */
#ifdef __MULTI_BOOT__

   _boot_mode = *(volatile kal_uint16 *)BOOT_CONFIG_ADDR;
   
#ifndef L1_NOT_PRESENT
   L1D_SetInitMode(_boot_mode);
#endif /* L1_NOT_PRESENT */

#endif /* __MULTI_BOOT__ */

   systemIntialization();

#ifdef MTK_PCM
   nvrm_init();
#endif

   HWDInitialization(); 

#if defined(G_SENSOR_SUPPORT)
//Huyanwei Add It 
   Init_GSensor();
#endif

#ifdef _NAND_FLASH_BOOTING_
   NFB_InitThirdROM();
   NFB_LoadingSecondaryMAUI();   
#endif /* _NAND_FLASH_BOOTING_ */

   Drv_Init_Phase2(); // Huyanwei Camera Init .....

   /* Resource initialization */
   systemInitializeResource();

   /* check ranges of all message ID */
   stack_check_msgid_range();
  
   /* MAUI protocol stack entry routine */
   mainp();   
   
#ifdef _MAUI_SOFTWARE_LA_
/* under construction !*/
#endif /* _MAUI_SOFTWARE_LA_ */

#ifdef __PRODUCTION_RELEASE__

#ifdef __MULTI_BOOT__
   if ( system_boot_mode!=FACTORY_BOOT )
#endif
      WDT_Enable(KAL_TRUE);

#endif /* __PRODUCTION_RELEASE__ */
}


/*************************************************************************
* FUNCTION
*  systemIntialization
*
* DESCRIPTION
*   This function implements the system specific initialization, including
*   interrupt central controller, FDD and KAL.
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
static void systemIntialization(void)
{
   kal_bool  ret_val = KAL_FALSE;
   
   initINTR();  /* initialize the interrupt controller */
   
   IRQ_LISR_Init();
   
#ifndef _NAND_FLASH_BOOTING_   
   Initialize_FDD_tables();
#endif /* _NAND_FLASH_BOOTING_ */   

   /* Register display handler */
	kal_register_print_string_function((kal_print_string_func_ptr)stack_print);

	/* Register stack fatal error handler */
	kal_register_fatal_error_handler((kal_error_func_ptr)fatal_error_handler);
	
   kal_initialize_mem();
   
   /* Initializing the Buffer Pool Information */
   stack_init_buff_pool_info();
   
   /* Create buffer pools */
   ret_val = stack_resources_init();   

   /* Initialize KAL resources */
	kal_initialize();
}


int bPrintEnable = 0;
/*************************************************************************
* FUNCTION
*  HWDInitialization
*
* DESCRIPTION
*   This function implements hardware dependent initialization and
*   management
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
static void HWDInitialization(void)
{
#ifdef MT6208 /* only MT6208 need to do this */
   /* Baseband power up control, 32khz oscillator power down mode */
   {
      kal_uint32 delay=1000000;

      REG_WRITE(RTC_base, 0x4316);
      while (delay>0) {  /* delay for settling 32KHz */
         delay--;
      }
   }
#endif /* MT6208 */

#ifdef MTK_SLEEP_ENABLE
   /* Added by Anthony Chin 03/18/2002. For sleep mode management. */
   L1SM_Init();
#endif /* MTK_SLEEP_ENABLE */

#ifndef L1_NOT_PRESENT
#ifdef __HW_DIVIDER__
   /* Power on Divider.(PDN_CON2) */
   HW_Divider_Initialization();
#endif /* __HW_DIVIDER__ */
#endif	/* L1_NOT_PRESENT */

#ifdef IDMA_DOWNLOAD
   /* Load DSP via iDMA. */
   REG_WRITE(DPRAM_CPU_base, 0);
   idma_load();
#endif /* IDMA_DOWNLOAD */

   Drv_Init_Phase1();
   
   WDT_Enable(KAL_FALSE);

#ifdef __USB_ENABLE__

   if ( INT_USBBoot() )
   {
#ifndef __NVRAM_IN_USB_MS__
#if ( !defined(MT6208) )
      *(volatile kal_uint16 *)(TDMA_base+0x14) = 0x1000;
#endif /* !MT6208 */
      *(volatile kal_uint16 *)PDN_CLR2   	= 0x0001;
      IRQUnmask(IRQ_CTIRQ1_CODE);
      *(volatile kal_uint16 *)(TDMA_base+0x150) = *(volatile kal_uint16 *)(TDMA_base+0x150) | 0x0002;
      IRQ_Register_LISR(IRQ_CTIRQ1_CODE, isrCTIRQ1_USBPowerOn,"CTIRQ1");
#endif /* !__NVRAM_IN_USB_MS__ */
   }
   
#endif /*__USB_ENABLE__*/

#ifdef L1_NOT_PRESENT

#if ( !defined(MT6208) )
   *(volatile kal_uint16 *)(TDMA_base+0x14) = 0x1000;
#endif /* !MT6208 */
   *(volatile kal_uint16 *)PDN_CLR2   	= 0x0001;
   IRQUnmask(IRQ_CTIRQ1_CODE);
   *(volatile kal_uint16 *)(TDMA_base+0x150) = *(volatile kal_uint16 *)(TDMA_base+0x150) | 0x0002;
   
#endif /* L1_NOT_PRESENT */

bPrintEnable = 1;
}


/*************************************************************************
* FUNCTION
*   systemInitializeResource
*
* DESCRIPTION
*   This function aims resource initialization, including audio, image, 
*   font etc.
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void systemInitializeResource(void)
{
#if ( (defined(__MTK_TARGET__) || defined (MTK_KAL_MNT)) && !defined(__MAUI_BASIC__) && !defined(__L1_STANDALONE__)  && !defined(EMPTY_MMI)) 

   InitializeResourceVariables();
   
#endif	   


#ifndef _NAND_FLASH_BOOTING_

#if ( defined(__USB_ENABLE__) && !defined(__MAUI_BASIC__) )

   if ( ((BMT.PWRon != CHRPWRON) && (BMT.PWRon != PWRKEYPWRON) && (BMT.PWRon != USBPWRON)) || 
        ((BMT.PWRon == PWRKEYPWRON) && (Check_NORFlash_Formatted() == 1)) )
        
#elif ( defined(__MAUI_BASIC__) || defined(_SIMULATION))

   if ( (BMT.PWRon != CHRPWRON) && (BMT.PWRon != USBPWRON) )
   
#else

   if ( ((BMT.PWRon != CHRPWRON) && (BMT.PWRon != PWRKEYPWRON)) || 
        ((BMT.PWRon == PWRKEYPWRON) && (Check_NORFlash_Formatted() == 1)) )
        
#endif

      DRV_POWERON();


#if !defined(__L1_STANDALONE__) && !defined(EMPTY_MMI)

#ifdef __MULTI_BOOT__

   if ( (BMT.PWRon == PWRKEYPWRON) && (Check_NORFlash_Formatted()==1 || MTK_FACTORY_MODE==INT_BootMode()) )
   
#else

   if ( (BMT.PWRon == PWRKEYPWRON) && (Check_NORFlash_Formatted() == 1) )
   
#endif   /*__MULTI_BOOT__*/

      MMICheckDiskDisplay();
      
#endif

#endif /* !_NAND_FLASH_BOOTING_ */

   srand(rand_num_seed);
}



/*************************************************************************
* FUNCTION
*  INT_SetChipReg
*
* DESCRIPTION
*   This function sets registers on the chip at system initial stage.
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void INT_SetChipReg()
{
#if defined(MT6218B)

   if (INT_ecoVersion() <= EN) 
   {
      /* Changing the output driving capability on both digital and analog die to solve the bug at BBRX comb filter */

      *(ACIF_CON1) = 0x0600;

      *(AC_ODS_CON) = 0x0004;
   }

#elif defined(MT6219)   /* MT6218B */

   if (INT_ecoVersion() <= BV) 
   {
      /* Changing the output driving capability on both digital and analog die to solve the bug at BBRX comb filter */

      *(ACIF_CON1) = 0x0600;

      *(AC_ODS_CON) = 0x0004;
   }

#elif defined(MT6217)   /* MT6218B */

    /* change DSP ROM rm value */

    *((volatile kal_uint32 *)0x80000800) = 0x1505;

    *((volatile kal_uint32 *)0x80000804) = 0x1717;

    *((volatile kal_uint32 *)0x80000808) = 0x1517;
    
#elif defined(MT6228_S00)   /* MT6218B */    

    /*
     * To fix the bug of RX/TX, apply the setting for reworked MT6228.
     */

    *(volatile kal_uint32 *)0x80010068 |= 0x00008a80;

#elif defined(MT6229_S00)   /* MT6218B */

    /*
     * To fix the hardware bug of IRDMA, 
     * set the IRWIN register such that IRDMA does not always have the first priority.
     */
    *(volatile kal_uint32 *)0x80000500 = 0;

#elif defined(MT6226M)

   if ((*HW_CODE == 0x6219) && ((*HW_VER & 0xff00) == 0x8b00))

      *ACIF_CON0 |= 0x0001;
      
#elif defined(MT6223)	|| defined(MT6223P)

   *ACIF_CON0 = 0x1;

#endif  /* MT6218B */
}

/*************************************************************************
* FUNCTION
*  INT_Version_Check
*
* DESCRIPTION
*   This function implements HW ID check with software load version
*
* CALLS
*  U_PutUARTByte
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
#ifdef __CHIP_VERSION_CHECK__
void INT_Version_Check(void)
{
#ifndef _NAND_FLASH_BOOTING_
   volatile register kal_uint16 HwCode;
   register kal_uint8 HExtra = ' ';
   register kal_uint16 BuildCode;
   register kal_int32 i;
   
   HwCode = *HW_CODE;
   BuildCode = *HW_VER;
   
   // MT6217AT/AN
   if ((HwCode == 0x6218) && (BuildCode == 0x8B03))
   {
      HwCode = 0x6217;
   }
   // MT6223P
   else if ((HwCode == 0x6223) && (*((volatile kal_uint16 *)(CONFIG_base+0xf010)) & 0x8000))
   {
      HExtra = 'P';
   }
   // MT6226M
   else if ((HwCode == 0x6219) && ((BuildCode & 0xFF00) == 0x8B00))
   {
      HwCode = 0x6226;
      HExtra = 'M';
   }
   // MT6226D
   else if ((HwCode == 0x6226) && ((BuildCode & 0xFF00) == 0x8D00))
   {
      HExtra = 'D';
   }
   // MT6227D
   else if ((HwCode == 0x6227) && ((BuildCode & 0xFF00) == 0x8D00))
   {
      HExtra = 'D';
   }
	
#if defined(MT6205B)
   BuildCode = 0x6205;
#elif defined(MT6217)
   BuildCode = 0x6217;
#elif defined(MT6219)
   BuildCode = 0x6219;
#elif defined(MT6223)
   BuildCode = 0x6223;
#elif defined (MT6223P)
   BuildCode = 0x6223;
   #define	ExtraVer 'P'
#elif defined(MT6225)
   BuildCode = 0x6225;
#elif defined(MT6226)
   BuildCode = 0x6226;
#elif defined(MT6226D)
   BuildCode = 0x6226;
   #define	ExtraVer 'D'
#elif defined(MT6226M)
   BuildCode = 0x6226;
   #define	ExtraVer 'M'
#elif defined(MT6227)
   BuildCode = 0x6227;
#elif defined(MT6227D)
   BuildCode = 0x6227;
   #define	ExtraVer 'D'
#elif defined(MT6228)
   BuildCode = 0x6228;
#elif defined(MT6229)
   BuildCode = 0x6229;
#elif defined(MT6230)
   BuildCode = 0x6230;
#else
   BuildCode = 0;
#endif

#ifndef ExtraVer
   #define	ExtraVer ' '
#endif

   if ((HwCode != BuildCode) || (HExtra != ExtraVer))
   {
      U_PutUARTByte(uart_port1, '@');
      while(1)
      {
         U_PutUARTByte(uart_port1, ' ');
         U_PutUARTByte(uart_port1, 'H');
         U_PutUARTByte(uart_port1, 'W');
         U_PutUARTByte(uart_port1, '=');
         U_PutUARTByte(uart_port1, 'M');
         U_PutUARTByte(uart_port1, 'T');
         for(i = 12; i >= 0; i -= 4)
         {
            U_PutUARTByte(uart_port1, '0' + ((HwCode >> i) & 0x0F));
         }
         U_PutUARTByte(uart_port1, HExtra);
         U_PutUARTByte(uart_port1, ',');
         U_PutUARTByte(uart_port1, ' ');
         U_PutUARTByte(uart_port1, 'S');
         U_PutUARTByte(uart_port1, 'W');
         U_PutUARTByte(uart_port1, '=');
         U_PutUARTByte(uart_port1, 'M');
         U_PutUARTByte(uart_port1, 'T');
         for(i = 12; i >= 0; i -= 4)
         {
            U_PutUARTByte(uart_port1, '0' + ((BuildCode >> i) & 0x0F));
         }
         U_PutUARTByte(uart_port1, ExtraVer);
         U_PutUARTByte(uart_port1, ' ');
         U_PutUARTByte(uart_port1, '\r');
         U_PutUARTByte(uart_port1, '\n');	
         
         for(i = 0xFFFFF; i > 0; i--) ;
         U_PutUARTByte(uart_port1, '#');
      }
   }
#endif /* _NAND_FLASH_BOOTING_ */
}
#endif /* __CHIP_VERSION_CHECK__ */

/*************************************************************************
* FUNCTION
*  INT_Config
*
* DESCRIPTION
*   This function implements adjusting Memory Block 0 (EMI_CON0) Wait
*  State's setting
*
* CALLS
*  INT_Decrypt, INT_SetPLL, INT_SetChipReg
*
* PARAMETERS
*
* RETURNS
*  the seed value for random number
*
* GLOBALS AFFECTED
*
*************************************************************************/
int INT_Config(void)
{
   kal_uint32 i, seed;
   kal_uint16 result_low, result_high;

#if defined(__MULTI_BOOT__) && !defined(L1D_TEST_COSIM)
   /* Check BOOT_CONFIG_ADDR */
   if ( 0 != (*(volatile kal_uint16 *)BOOT_CONFIG_ADDR) )
   {
      /* Enter FT_MODE, delay for waiting UART flush TX buffer */
   #if defined(MCU_26M)   
      kal_uint32 delay;      
      for (delay = 0; delay < 10000; delay++)
         ;   /* nop */         
   #elif defined(MCU_52M)   
      kal_uint32 delay;
      for (delay = 0; delay < 25000; delay++)
         ;   /* nop */
   #endif
   }
#endif   /* __MULTI_BOOT__ & !L1D_TEST_COSIM */


#ifdef MT6218B
   if (INT_ecoVersion() == BN)
      *(volatile kal_uint16 *)0x80000500 = 0x0001 ;
#endif   /* MT6218B */

#if defined(MT6226) || defined(MT6227) || defined(MT6226M)
   if (INT_ecoVersion() == ECO_E1)
      *(volatile kal_uint16 *)0x80500108 = 0x1000;
#endif /* MT6226 || MT6227 || MT6226M */


#if defined(_SIMULATION)

    /*
     * For co-sim load,
     * EMI on both bank 0 and bank 1 are assigned with 0x4102.
     * And Register 0x80010044 (EMI General Control Register) reserves the default value.
     */
#if (!defined(MT6205B) && !defined(MT6208))

    *EMI_CONA = 0x00004102;    
    *EMI_CONB = 0x00004102;  
    
#else /* !MT6205B && !MT6208 */

    *EMI_CON0 = 0x4102;
    *EMI_CON1 = 0x4102;
    
#endif /* !MT6205B && MT6208 */

   INT_SetPLL();

#else /* _SIMULATION */

#ifndef _NAND_FLASH_BOOTING_

   custom_setEMI();

   INT_SetPLL();
   
#endif /* _NAND_FLASH_BOOTING_ */

#ifdef MT6225
   *(volatile kal_uint32 *)(0x80010078) = 0;
#endif /* MT6225 */

#endif /* _SIMULATION */

   INT_SetChipReg();

#if defined(_SIMULATION)

    /* no need to generate a real random number seed in co-sim */

   seed = 0;

#else   /* _SIMULATION */

   /* generate a random number via reading internal SRAM or 32K-clock calibration */
   for (seed = 0, i = 0; i < (1024 / 4); i++) {

      /* XOR memory data */
      seed = seed ^ *((kal_uint32 *)RAND_GEN_START_ADDR + i);
   }

   /* check if the seed is zero */
   if (seed == 0) {

      /* try to find another seed */

      /* try 32K clock */

      *(volatile kal_uint16 *)DRVPDN_CON2_CLR   = DRVPDN_CON2_TDMA;

      DRV_WriteReg(SM_FMDURATION,0);

      DRV_Reg(SM_CTRL) |= SM_CTRL_FM_START;
      
      while (!(DRV_Reg(SM_STAT) & SM_STAT_FM_RDY)) ;
      
      result_low = DRV_Reg(SM_FM_RESULT_LOW);

      result_high = DRV_Reg(SM_FM_RESULT_HIGH) & SM_FM_RESULT_HIGH_MASK;

      seed = (result_low | (result_high << 16));
   }

#endif  /* _SIMULATION */

   /*
    * NoteXXX: Seed cannot be store in the global variable rand_num_seed directly.
    *          This is because that RW-data will be initialized later.
    *          Just return the seed.
    */

   return seed;
}


/*************************************************************************
* FUNCTION
*  INT_SwitchMCUClock
*
* DESCRIPTION
*   This function intended for switching MCU clock.
* Be very careful that, before this function is called, user must ensure
* that there is very save EMI setting.
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool INT_SwitchMCUClock(mcu_clock_enum inputclk)
{
   kal_uint32 savedMask;
   kal_bool   status=KAL_TRUE;
   
   savedMask = SaveAndSetIRQMask();
   
#if defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6225)

   switch (inputclk) {

   case MCU_13MHZ:

      *MCUCLK_CON = 0x0000;

      break;

   case MCU_26MHZ:

      *MCUCLK_CON = 0x0101;

      break;

   case MCU_52MHZ:

      *MCUCLK_CON = 0x0303;

      break;

   case MCU_104MHZ:

      *MCUCLK_CON = 0x0703;

      break;

   default:

      status = KAL_FALSE;

      break;
   }
   
#elif defined(MT6223)	|| defined(MT6223P)

   switch ( inputclk )
   {
      case MCU_13MHZ: *MCUCLK_CON &= 0x00f0 ;
                      break;
      case MCU_26MHZ: *MCUCLK_CON &= 0x00f0 ;
                      *MCUCLK_CON |= 0x01f1 ;
                      break;
      case MCU_39MHZ: *MCUCLK_CON &= 0x00f0 ;
                      *MCUCLK_CON |= 0x02f2 ;
                      break;
      case MCU_52MHZ: *MCUCLK_CON &= 0x00f0 ;
                      *MCUCLK_CON |= 0x03f3 ;
                      break;
      default : status = KAL_FALSE;
   }   
   

#elif defined(MT6217) || defined(MT6226) || defined(MT6227) || defined(MT6226M) || defined(MT6227D) || defined(MT6226D)

   switch ( inputclk )
   {
      case MCU_13MHZ: *(volatile kal_uint16 *)0x80000114 = 0x0000 ;
                      break;
      case MCU_26MHZ: *(volatile kal_uint16 *)0x80000114 = 0x0001 ;
                      break;
      case MCU_39MHZ: *(volatile kal_uint16 *)0x80000114 = 0x0002 ;
                      break;
      case MCU_52MHZ: *(volatile kal_uint16 *)0x80000114 = 0x0003 ;
                      break;
      default : status = KAL_FALSE;
   }
   
#elif defined(MT6218B) || defined(MT6219)

   #ifdef EXT_26M   
   
      switch ( inputclk )
      {
         case MCU_13MHZ: /* Bypass MPLL, but retain MCU_DIV2 */
                         *(volatile kal_uint16 *)0x80000108 |= 0x0008;
                         *(volatile kal_uint16 *)0x80000108 &= ~(0x0002);                         
                         break;
         case MCU_26MHZ: /* Bypass MPLL and MCU_DIV2*/
                         *(volatile kal_uint16 *)0x80000108 &= ~(0x000a);
                         break;
         case MCU_52MHZ: /* Do not bypass both MPLL and MCU_DIV2*/
                         *(volatile kal_uint16 *)0x80000108 |= 0x000a;
                         break;
      default : status = KAL_FALSE;
         
      }
      
   #elif defined EXT_13M
   
      switch ( inputclk )
      {
         case MCU_13MHZ: /* Bypass MPLL and MCU_DIV2*/
                         *(volatile kal_uint16 *)0x80000108 &= ~(0x000a);
                         break;
         case MCU_26MHZ: /* Bypass MPLL and MCU_DIV2*/
                         *(volatile kal_uint16 *)0x80000108 &= ~(0x000a);
                         *(volatile kal_uint16 *)0x80000100 = 0x01;
                         {
                            kal_uint8  i;
                            // delay until PLL is stable
		                      for (i=0;i<200;i++);
                         }
                         *(volatile kal_uint16 *)0x80000108 |= 0x0002;
                         break;
         case MCU_52MHZ: /* Bypass MPLL and MCU_DIV2*/
                         *(volatile kal_uint16 *)0x80000108 &= ~(0x000a);
                         *(volatile kal_uint16 *)0x80000100 = 0x03;
                         {
                            kal_uint8  i;
                            // delay until PLL is stable
		                      for (i=0;i<200;i++);
                         }
                         *(volatile kal_uint16 *)0x80000108 |= 0x0002;
                         break;
         default : status = KAL_FALSE;
      }
       
   #endif /* EXT_26M */ 
   
#elif defined(MT6238)
      switch ( inputclk )
      {

   case MCU_13MHZ:

      *MCUCLK_CON = 0x7000;

      break;

   case MCU_26MHZ:

      *MCUCLK_CON = 0x7111;

      break;

   case MCU_52MHZ:

      *MCUCLK_CON = 0x7333;

      break;

   case MCU_104MHZ:

      *MCUCLK_CON = 0x7737;

      break;

   case MCU_208MHZ:

      *MCUCLK_CON = 0x7F37;

      break;

   default:

      status = KAL_FALSE;

      break;
    }
#endif

   RestoreIRQMask(savedMask);
   
   return status;
}

/*************************************************************************
* FUNCTION
*  INT_BootMode
*
* DESCRIPTION
*   This function implements to return boot mode. Remember the routine muse
* be called after Application_Initialize.
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint16 INT_BootMode(void)
{
   return _boot_mode;
}

#ifdef __MTK_TARGET__
#pragma arm section code = "SNORCODE"
#endif /* __MTK_TARGET__ */

/*************************************************************************
* FUNCTION
*  INT_DisableDataCache
*
* DESCRIPTION
*  This is specific function for flash driver only.
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint32 INT_DisableDataCache(void)
{
#if ( !defined(MT6205B) && !defined(MT6208) && !defined(MT6228) && !defined(MT6229) && !defined(MT6230) && !defined(MT6225) && !defined(MT6238) )

   kal_uint32  restore_value;
   
   restore_value = *(kal_uint32 *)(0x80010050);
   *(kal_uint32 *)(0x80010050) &= ~(0x30000);
   return restore_value;
   
#else

   return 0;
   
#endif
}

/*************************************************************************
* FUNCTION
*  INT_RestoreDataCache
*
* DESCRIPTION
*  This is specific function for flash driver only.
*
* CALLS
*
* PARAMETERS
*  Value to be restored.
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void INT_RestoreDataCache(kal_uint32 restore_value)
{
#if ( !defined(MT6205B) && !defined(MT6208) && !defined(MT6228) && !defined(MT6229) && !defined(MT6230) && !defined(MT6225)  && !defined(MT6238))

   *(kal_uint32 *)(0x80010050) = restore_value;
   return;
   
#else

   return;
   
#endif
}

/*************************************************************************
* FUNCTION
*  INT_DisableCodePrefetch
*
* DESCRIPTION
*  This is specific function for flash driver only.
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
#ifdef MT6205B
kal_uint32 INT_DisableCodePrefetch(void)
{
   kal_uint32  restore_value;
   
   restore_value = *(kal_uint32 *)(0x80010030);
   *(kal_uint32 *)(0x80010030) &= ~(0x2);
   return restore_value;
}
#endif

/*************************************************************************
* FUNCTION
*  INT_RestoreCodePrefetch
*
* DESCRIPTION
*  This is specific function for flash driver only.
*
* CALLS
*
* PARAMETERS
*  Value to be restored.
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
#ifdef MT6205B
void INT_RestoreCodePrefetch(kal_uint32 restore_value)
{
   *(kal_uint32 *)(0x80010030) = restore_value;
}
#endif

#ifdef __MTK_TARGET__
#pragma arm section code
#endif /* __MTK_TARGET__ */

/*************************************************************************
* FUNCTION
*  INT_InvokeSSTEngine
*
*************************************************************************/
void INT_InvokeSSTEngine(kal_char *err_msg_ptr, kal_int32 err_code, kal_int32 os_err_code)
{
#ifdef _SST_FUNCTION_ENABLE_
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* _SST_FUNCTION_ENABLE_ */

   return;
}

/*************************************************************************
* FUNCTION
*  INT_QueryPowerDownStatus
*
* DESCRIPTION
*  Used to read-back the 4 power down control registers.
*
* CALLS
*
* PARAMETERS
*  Pointer of type CONFIG_PDN_TYPE.
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void INT_QueryPowerDownStatus(CONFIG_PDN_TYPE *PDN_ptr)
{
   PDN_ptr->pdn_con0 = *(volatile kal_uint16 *)PDN_CON0;
   PDN_ptr->pdn_con1 = *(volatile kal_uint16 *)PDN_CON1;
   PDN_ptr->pdn_con2 = *(volatile kal_uint16 *)PDN_CON2;
   PDN_ptr->pdn_con3 = *(volatile kal_uint16 *)PDN_CON3;
}

/*************************************************************************
* FUNCTION
*  INT_SetPowerDownStatus
*
* DESCRIPTION
*  Setting 4 power down control registers.
*
* CALLS
*
* PARAMETERS
*  Pointer of type CONFIG_PDN_TYPE.
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void INT_SetPowerDownStatus(CONFIG_PDN_TYPE *PDN_ptr)
{
   *(volatile kal_uint16 *)PDN_SET0 = PDN_ptr->pdn_con0;
   *(volatile kal_uint16 *)PDN_SET1 = PDN_ptr->pdn_con1;
   *(volatile kal_uint16 *)PDN_SET2 = PDN_ptr->pdn_con2;
   *(volatile kal_uint16 *)PDN_SET3 = PDN_ptr->pdn_con3;   

   *(volatile kal_uint16 *)PDN_CLR0 = ~(PDN_ptr->pdn_con0);
   *(volatile kal_uint16 *)PDN_CLR1 = ~(PDN_ptr->pdn_con1);
   *(volatile kal_uint16 *)PDN_CLR2 = ~(PDN_ptr->pdn_con2);
   *(volatile kal_uint16 *)PDN_CLR3 = ~(PDN_ptr->pdn_con3);   
}

/*************************************************************************
* FUNCTION
*  release_bb_chip
*
* DESCRIPTION
*   This function returns the version number of the baseband chip
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_char* release_bb_chip(void)
{
   static kal_char str_return[]="MT6205B, E00";

#if defined(FPGA)
   strcpy(str_return, "FPGA");
#elif defined(MT6208)
   strcpy(str_return, "MT6208");
#elif defined(MT6205)
   strcpy(str_return, "MT6205");
#else /* future chips will definitely apply this rule */
   kal_uint16 hw_code;
   kal_uint8 majrev; /* bit 8~11 of HW_VER register */
   kal_uint8 ffix; /* bit 0~3 of HW_VER register */
   kal_uint16 hw_version;
   kal_uint16 temp_num;

   hw_code = *HW_CODE;
   hw_version = *HW_VER;
   majrev = (hw_version >> 8) & 0x000f; /* get MAJREV from HW_VER */
   ffix = hw_version & 0x000f; /* get FFIX from HW_VER */

   /* convert the HW_CODE to natural representation*/
   temp_num = (hw_code & 0x000f);
   hw_code >>= 4;
   temp_num += (hw_code & 0x000f) * 10;
   hw_code >>= 4;
   temp_num += (hw_code & 0x000f) * 100;
   hw_code >>= 4;
   temp_num += (hw_code & 0x000f) * 1000;

   /* construct the string for the chips MTxxxxx, ECOx */
   if (majrev == 0x0a) /* directiver A, which often skip the directive */
   {
      sprintf(str_return, "MT%4d, E%02d", temp_num, ffix);
   }
   else if (majrev == 0x0b && temp_num == 6219)
   {
      /* special hanlding for MT6226M */
      sprintf(str_return, "MT6226M, E%02d", ffix);
   }
   else
   {
      sprintf(str_return, "MT%4d%1X, E%02d", temp_num, majrev, ffix);
   }
#endif

   return str_return;
}

/*************************************************************************
* FUNCTION
*  AnalogDieID
*
* DESCRIPTION
*  This function returns identification of analog die
*
* CALLS
*
* PARAMETERS
*  None
*
* RETURNS
*  Identification of analog die
*
* GLOBALS AFFECTED
*  None
*
*************************************************************************/
analog_die_id AnalogDieID()
{
#ifdef MT6218B

   if (*(ANALOG_HW_VERSION) == 0x0000 && *(ANALOG_HW_CODE) == 0x0000)
      return B63216A;
   else if (*(ANALOG_HW_VERSION) == 0x8c00 && *(ANALOG_HW_CODE) == 0x6216)
      return C63216A;
   else
      return UNKNOWN_ANALOG_DIE;

#elif defined(MT6219)   /* #ifdef MT6218B */

   if (*(ANALOG_HW_VERSION) == 0x8c00 && *(ANALOG_HW_CODE) == 0x6216)
      return C63216A;
   else if (*(ANALOG_HW_VERSION) == 0x8c01 && *(ANALOG_HW_CODE) == 0x6216)
      return C63216B;
   else
      return UNKNOWN_ANALOG_DIE;

#else   /* #ifdef MT6218B */

   return UNKNOWN_ANALOG_DIE;

#endif   /* MT6218B */
}

/*************************************************************************
* FUNCTION
*  INT_ecoVersion
*
* DESCRIPTION
*  This function returns the ECO version number of baseband chipset
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
ECO_VERSION INT_ecoVersion(void)
{
#if defined(MT6205B)

   if (*HW_CODE == 0x6205 && *HW_VER == 0x8b00)

      return EN;

   return MT6205B_latest_chip;

#elif defined(MT6218)   /* MT6205B */

   if (*HW_CODE == 0x6218 && *HW_VER == 0x8a00)

      return AN;

   return MT6218_latest_chip;

#elif defined(MT6218B)   /* MT6205B */

   if (*HW_CODE == 0x6218 && *HW_VER == 0x8b00)

      return BN;

   else if (*HW_CODE == 0x6218 && *HW_VER == 0x8b01)

      return CN;

   else if (*HW_CODE == 0x6218 && *HW_VER == 0x8b02) {

      if (AnalogDieID() == B63216A)

         return DN;

      else if (AnalogDieID() == C63216A)

         return EN;

   } else if (*HW_CODE == 0x6218 && *HW_VER == 0x8b03)

      return FN;

   else if (*HW_CODE == 0x6218 && *HW_VER == 0x8b04)

      return GN;

   return MT6218B_latest_chip;

#elif defined(MT6217)   /* MT6218 */

   if (*HW_CODE == 0x6217 && *HW_VER == 0x8a00) {

      if (AnalogDieID() == C63216B)

         return BN;
   }

   return MT6217_latest_chip;

#elif defined(MT6219)   /* MT6205B */

   if (*HW_CODE == 0x6219 && *HW_VER == 0x8a00) {

      if (AnalogDieID() == C63216A)

         return AV;

      else if (AnalogDieID() == C63216B)

         return BV;

   } else if (*HW_CODE == 0x6219 && *HW_VER == 0x8a01) {

      if (AnalogDieID() == C63216B)

         return EV;

   }

   return MT6219_latest_chip;

#elif defined(MT6227) || defined(MT6226) || defined(MT6226M)

   /* the hardware code of MT6226M IS 6219 */

   if ( (*HW_CODE == 0x6226 || *HW_CODE == 0x6227 || *HW_CODE == 0x6219) && *HW_VER == 0x8a00) {

      return ECO_E1;

   } else if ( (*HW_CODE == 0x6226 || *HW_CODE == 0x6227 || *HW_CODE == 0x6219) && *HW_VER == 0x8a01) {

      return ECO_E2;

   }

   return MT6227_latest_chip;

#elif defined(MT6225)

   if (*HW_CODE == 0x6225 && *HW_VER == 0x8a00) {
      return ECO_E1;
   } else if (*HW_CODE == 0x6225 && *HW_VER == 0x8a01) {
      return ECO_E2;
   } else if (*HW_CODE == 0x6225 && *HW_VER == 0x8a02) {
      return ECO_E3;
   } else if (*HW_CODE == 0x6225 && *HW_VER == 0x8a03) {
      return ECO_E4;
   }

   return MT6225_latest_chip;

#elif defined(MT6228)

   return MT6228_latest_chip;

#elif defined(MT6229)

   return MT6229_latest_chip;
   
#elif defined(MT6230)

   return MT6230_latest_chip;   
   
#elif defined(MT6223)	|| defined(MT6223P)

/*
  if (*HW_CODE == 0x6223 && *HW_VER == 0x8a01) {
      return ECO_E2;   
   } else if (*HW_CODE == 0x6223 && *HW_VER == 0x8a04) {
      return ECO_E5;
   }
*/
   return MT6223_latest_chip;

#elif defined(MT6227D) || defined(MT6226D)

   return MT6227D_latest_chip;
#elif defined(MT6238)

   return MT6238_latest_chip;

#else   /* MT6205B */

   /* no one should invoke this function for unknown chip */

   EXT_ASSERT(0, 0, 0, 0);

   return 0;

#endif   /* MT6025B */
}

/*************************************************************************
* FUNCTION
*  INT_VersionNumbers
*
* DESCRIPTION
*   This function returns the version number of the followings
*   1. Chip version
*   2. DSP version
*   3. DSP patch version
*   4. MCU software version
*   5. Baseband board version
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void INT_VersionNumbers(version_struct * ptr_version)
{
   ptr_version->bb_chip = release_bb_chip();
   ptr_version->dsp_fw = release_dsp_fw();
   ptr_version->dsp_ptch = release_dsp_ptch();
   ptr_version->mcu_sw = release_verno();
   ptr_version->mcu_sw_branch = release_branch();
   ptr_version->bb_board = release_hw_ver();
   return;
}

#ifdef __RVCT__

/*************************************************************************
* FUNCTION
*  __user_initial_stackheap
*
* DESCRIPTION
*  This dummy function is implemented to make the linker happy for RVCT.
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
__value_in_regs struct __initial_stackheap __user_initial_stackheap(unsigned i0, unsigned i1, unsigned i2, unsigned i3)
{
   struct __initial_stackheap config;

   kal_fatal_error_handler("Should-not-Execute", KAL_ERROR_SHOULD_NOT_EXECUTE, KAL_ERROR_KAL_SUB_ERROR_CODE1);

   config.heap_base = i1;
   config.heap_limit = i1;
   config.stack_base = i1; 
   config.stack_limit = 0;

   return config;
}

/*************************************************************************
* FUNCTION
*  _sys_command_string
*
* DESCRIPTION
*  This dummy function is implemented for non semi-hosting and
*  heap extension support.
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
char *$Sub$$_sys_command_string(char *cmd, int len)
{
   return 0;
}

#endif   /* __RVCT__ */

/*************************************************************************
* FUNCTION
*  INT_GetCurrentTime
*
* DESCRIPTION
*  This function access 32KHz Counter and return Counter Value
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*  Value of 32KHz Counter
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint32 INT_GetCurrentTime(void)
{
#if defined(MT6238)	
   return *(volatile kal_uint32*)(0x82000230);
#else
   return *(volatile kal_uint32*)(0x80200230);  
#endif	//    #if defined(MT6238)	
}

/*************************************************************************
* FUNCTION
*  INT_CheckSystemDriveOnNAND()
*
* DESCRIPTION
*  Query the location of system drive, either NAND-flash or NOR-flash
*
* PARAMETERS
*
* RETURNS
*  KAL_TRUE: NFB or System Drive On NAND
*  KAL_FALSE: otherwise
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool INT_CheckSystemDriveOnNAND(void)
{
#if ( defined(__FS_SYSDRV_ON_NAND__) || defined( _NAND_FLASH_BOOTING_) )

   return KAL_TRUE;
   
#else

   return KAL_FALSE;

#endif /* __FS_SYSDRV_ON_NAND__ || _NAND_FLASH_BOOTING_ */
}

/*************************************************************************
* FUNCTION
*  INT_IsBootByCodeShadow()
*
* DESCRIPTION
*  Query if system boot via code shadow, 
*  On the other word, binary code copy to RAM before execution
*
* PARAMETERS
*
* RETURNS
*  KAL_TRUE: Nand Flash booting
*  KAL_FALSE: otherwise
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool INT_IsBootByCodeShadow(void)
{
#if defined(_NAND_FLASH_BOOTING_)

   return KAL_TRUE;
   
#else

   return KAL_FALSE;

#endif /* _NAND_FLASH_BOOTING_ */
}

/*************************************************************************
* FUNCTION
*  INT_IsCodeShadowDone()
*
* DESCRIPTION
*  Query if binary code already ready via code shadow, 
*
* PARAMETERS
*
* RETURNS
*  KAL_TRUE: ! Nand Flash Booting , or Secondary Image loaded on NFB
*  KAL_FALSE: otherwise
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool INT_IsCodeShadowDone(void)
{
#if defined(_NAND_FLASH_BOOTING_)

   return NFB_SecondaryImageLoaded;
   
#else

   return KAL_TRUE;

#endif /* _NAND_FLASH_BOOTING_ */
}


/*************************************************************************
* FUNCTION
*  init_32khz_output
*
* DESCRIPTION
*  This function initializes 32khz clock output.
*  This should be invoked in the initial state to get the GPIO pin for
*  32khz clock output.
*
* PARAMETERS
*  gpio_pin   -   GPIO pin for 32KHz clock output
*
* RETURNS
*  none
*
*************************************************************************/
void init_32khz_output(kal_uint16 gpio_pin, kal_uint16 gpio_data)
{
    _32khz_gpio_pin = gpio_pin;
    _32khz_gpio_data = gpio_data;
}


/*************************************************************************
* FUNCTION
*  enable_32khz_output
*
* DESCRIPTION
*  This function enables 32KHz clock output.
*
* PARAMETERS
*  none
*
* RETURNS
*  0 for success; -1 for failure
*
*************************************************************************/
kal_int32 enable_32khz_output(void)
{
   kal_uint32 irq;


   /* validate user count */
   if ((_32khz_user_cnt + 1) == 0) {
       ASSERT(0);
   }

   /* validate GPIO pin number */
   if (_32khz_gpio_pin == 0xFFFF) {
       return -1;
   }

   /* increament user count */
   irq = SaveAndSetIRQMask();
   _32khz_user_cnt++;
   RestoreIRQMask(irq);

   if (_32khz_user_cnt == 1) {
       /* first enable; config 32KHz clock output */
       GPIO_ModeSetup(_32khz_gpio_pin, _32khz_gpio_data);
   }

   return 0;
}


/*************************************************************************
* FUNCTION
*  disable_32khz_output
*
* DESCRIPTION
*  This function disables 32KHz clock output (if and only if there is
*  no more use).
*
* PARAMETERS
*  none
*
* RETURNS
*  0 for success; -1 for failure
*
*************************************************************************/
kal_int32 disable_32khz_output(void)
{
   kal_uint32 irq;

   /* validate user count */
   if (_32khz_user_cnt == 0) {
       ASSERT(0);
   }

   /* validate GPIO pin number */
   if (_32khz_gpio_pin == 0xFFFF) {
       return -1;
   }

   /* decreament user count */
   irq = SaveAndSetIRQMask();
   _32khz_user_cnt--;
   RestoreIRQMask(irq);

   if (_32khz_user_cnt == 0) {
       /* last disable; config as general purpose IO */
       GPIO_ModeSetup(_32khz_gpio_pin, 0);
       GPIO_InitIO(OUTPUT, _32khz_gpio_pin);
       GPIO_WriteIO(0, _32khz_gpio_pin);
   }

   return 0;
}


/*************************************************************************
* FUNCTION
*  show_sysinit_msg
*
* DESCRIPTION
*  This function shows system intialization messages. It is called in the
*  entry point of the TST READER task.
*
* PARAMETERS
*  none
*
* RETURNS
*  0
*
*************************************************************************/
kal_int32 show_sysinit_msg(void)
{
   kal_uint32 ret;
   kal_char buff[40];


#if defined(MT6238)

   /* display the page table usage for ARM9 MMU */

   ret = check_cptbl_pool();
   if (ret != 0) {
      system_print("WARNING!!WARNING!!WARNING!!WARNING!!WARNING!!WARNING!!WARNING!!WARNING!!");
      system_print("PAGE TABLE config failure");
      sprintf(buff, "needs %d bytes for %cptbl pool", ret, 'c');
      system_print(buff);
      system_print("WARNING!!WARNING!!WARNING!!WARNING!!WARNING!!WARNING!!WARNING!!WARNING!!");
   }

   ret = check_fptbl_pool();
   if (ret != 0) {
      system_print("WARNING!!WARNING!!WARNING!!WARNING!!WARNING!!WARNING!!WARNING!!WARNING!!");
      system_print("PAGE TABLE config failure");
      sprintf(buff, "needs %d bytes for %cptbl pool", ret, 'f');
      system_print(buff);
      system_print("WARNING!!WARNING!!WARNING!!WARNING!!WARNING!!WARNING!!WARNING!!WARNING!!");
   }
#endif	/* MT6238 */


   return 0;
}

#undef RTOS_DEBUG


#endif /*__FUE__*/
