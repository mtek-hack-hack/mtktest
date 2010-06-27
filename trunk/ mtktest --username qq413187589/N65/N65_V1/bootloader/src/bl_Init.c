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
 *   bl_Init.c
 *
 * Project:
 * --------
 *   NFB - Bootloader
 *
 * Description:
 * ------------
 *   This file defines the stack distribution, will be referenced in bootarm.s
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
 * removed!
 * removed!
 * removed!
 * removed!
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

#include <kal_release.h>
#include <bl_MTK_BB_REG.h>
#include <bl_init.h>

extern void NFIReconfigure(void);
extern void custom_setEMI(void);


/**********************************************************
Description : Setting MCU PLL.
Input       : None
Output      : None
***********************************************************/
static void PLL_Init(void)
{
#if ( defined(MT6228) || defined(MT6229) || defined(MT6230) )

	kal_uint16 i;

#ifdef EXT_26M
   // 1. Power on DSP_DIV2, MCU_DIV2, and CLKSQ
   *(volatile kal_uint16 *)0x80000320 = 0x9800;
   // 2. Enable MCU clock divider
   *(volatile kal_uint16 *)0x80000110 = 0x0008;
#elif defined (EXT_13M)
   // Power on CLKSQ
   *(volatile kal_uint16 *)0x80000320 = 0x0800;
#endif

   // 3. Boost MCU and DSP PLL (MDPLL) to 104MHz (MUST)
   *(volatile kal_uint16 *)0x80000100 = 0x0087;
   *(volatile kal_uint16 *)0x80000100 = 0x0007;

   // 4. Power ou MPLL
   *(volatile kal_uint16 *)0x80000320 = 0x4000;

   // 5. delay until PLL is stable, at least 50us
	for (i=0;i<0x100;i++);

   // 6. Define ARM(CPU, Data cache, TCM) and MCU PLL
#ifdef MCU_104M
   // MCU and BUS clock 2:1
   *(volatile kal_uint16 *)0x80000118 = 0x0703;
#elif defined MCU_52M
   // MCU and BUS clock 1:1
   *(volatile kal_uint16 *)0x80000118 = 0x0303;
#elif defined MCU_26M
   // MCU and BUS clock 1:1
   *(volatile kal_uint16 *)0x80000118 = 0x0101;
#elif defined MCU_13M
   // MCU and BUS clock 1:1
   *(volatile kal_uint16 *)0x80000118 = 0x0000;
#endif

   // 7. Enable MPLL output
   *(volatile kal_uint16 *)0x80000110 |= 0x0002;

#elif defined(MT6225)

	kal_uint16 i;

#ifdef EXT_26M
   // 1. Power on DSP_DIV2, MCU_DIV2, and CLKSQ
   *(volatile kal_uint16 *)0x80000320 = 0x9800;
   // 2. Enable MCU clock divider
   *(volatile kal_uint16 *)0x80000110 = 0x0002;
#elif defined (EXT_13M)
   // Power on CLKSQ
   *(volatile kal_uint16 *)0x80000320 = 0x0800;
#endif

   // 3. Boost MCU and DSP PLL (MDPLL) to 104MHz (MUST)
   *(volatile kal_uint16 *)0x80000100 = 0x0080;
   *(volatile kal_uint16 *)0x80000100 = 0x0000;
   
   // 4. Power ou MPLL
   *(volatile kal_uint16 *)0x80000320 = 0x2000;
   
   // 5. delay until PLL is stable, at least 50us
	for (i=0;i<0x100;i++);
   
   // 6. Define ARM(CPU, Data cache, TCM) and MCU PLL
#ifdef MCU_104M   
   // MCU and BUS clock 2:1
   *(volatile kal_uint16 *)0x80000118 = 0x0703;
#elif defined MCU_52M
   // MCU and BUS clock 1:1
   *(volatile kal_uint16 *)0x80000118 = 0x0303;
#elif defined MCU_26M
   // MCU and BUS clock 1:1
   *(volatile kal_uint16 *)0x80000118 = 0x0101;
#elif defined MCU_13M
   // MCU and BUS clock 1:1
   *(volatile kal_uint16 *)0x80000118 = 0x0000;   
#endif      

   // 7. Enable MPLL output
   *(volatile kal_uint16 *)0x80000100 |= 0x0010; 
   
#endif  /* MT6228 || MT6229 || MT6230 */
}

/**********************************************************
Description : Setting EMI according to MCU clock rate.
Input       : None
Output      : None
***********************************************************/
static void EMI_Setting(void)
{
   custom_setEMI();
}


/**********************************************************
Description : Restart watchdog counter.
Input       : None
Output      : None
***********************************************************/
void WacthDogRestart(void)
{
   *(volatile kal_uint32 *)(0x80040008) = 0x1971;
}

/**********************************************************
Description : Disable watchdog counter.
Input       : None
Output      : None
***********************************************************/
void WacthDogDisable(void)
{
   *(volatile kal_uint32 *)(0x80040000) = 0x2200;
}


/**********************************************************
Description : Wait for 32KHz clock srouce stable.
Input       : None
Output      : None
***********************************************************/
void WaitFor32KStable(void)
{
   kal_uint32 result;
   kal_uint16 result_low;
   kal_uint16 result_high;
   
   * (volatile kal_uint16 *) DRVPDN_CON2_CLR = DRVPDN_CON2_TDMA;
   
   DRV_WriteReg(SM_FMDURATION,0);
       
   while(1)
   {
      DRV_Reg(SM_CTRL) |= SM_CTRL_FM_START;
      
      while(!(DRV_Reg(SM_STAT) & SM_STAT_FM_RDY));
      
      result_low = DRV_Reg(SM_FM_RESULT_LOW);
      result_high = DRV_Reg(SM_FM_RESULT_HIGH) & SM_FM_RESULT_HIGH_MASK;
      result = (result_low | (result_high << 16));
      
      if ((result < 950) && (result > 650))
         break;   	
   }
   
   * (volatile kal_uint16 *) DRVPDN_CON2_SET = DRVPDN_CON2_TDMA;
}


/**********************************************************
Description : Initialization configuration
Input       : None
Output      : None
***********************************************************/
void INTConfig(void)
{
   WacthDogRestart();

   PLL_Init();
   
   EMI_Setting();   
}

#ifdef __CHIP_VERSION_CHECK__
extern void PutUARTByte(kal_uint8 data);
#define HW_VER    ((kal_uint16 *)(CONFIG_base+0x0000)) /* Hardware ver register */
#define HW_CODE   ((kal_uint16 *)(CONFIG_base+0x0008)) /* Hardware ver register */

/**********************************************************
Description : HW ID check with software load version
Input       : None
Output      : None
***********************************************************/
void INT_Version_Check(void)
{
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
      PutUARTByte('@');
      while(1)
      {
         PutUARTByte(' ');
         PutUARTByte('H');
         PutUARTByte('W');
         PutUARTByte('=');
         PutUARTByte('M');
         PutUARTByte('T');
         for(i = 12; i >= 0; i -= 4)
         {
            PutUARTByte('0' + ((HwCode >> i) & 0x0F));
         }
         PutUARTByte(HExtra);
         PutUARTByte(',');
         PutUARTByte(' ');
         PutUARTByte('S');
         PutUARTByte('W');
         PutUARTByte('=');
         PutUARTByte('M');
         PutUARTByte('T');
         for(i = 12; i >= 0; i -= 4)
         {
            PutUARTByte('0' + ((BuildCode >> i) & 0x0F));
         }
         PutUARTByte(ExtraVer);
         PutUARTByte(' ');
         PutUARTByte('\r');
         PutUARTByte('\n');
         
         for(i = 0xFFFFF; i > 0; i--) ;
         PutUARTByte('#');
      }
   }
}
#endif /* __CHIP_VERSION_CHECK__ */

/**********************************************************
Description : Start GPT Timer 3
Input       : None
Output      : None
***********************************************************/
void startGPTTImer3(void)
{
   *(volatile kal_uint32 *)(0x8010001c) = 0;
   *(volatile kal_uint32 *)(0x80100024) = 0x07;
   *(volatile kal_uint32 *)(0x8010001c) = 1;

   return;
}


/**********************************************************
Description : Stop GPT Timer 3 and get the counter
Input       : None
Output      : 16bits counter duration
***********************************************************/
kal_uint16 stopGPTTImer3(void)
{
   kal_uint16 duration;
   
   duration = *(volatile kal_uint32 *)(0x80100020);
   *(volatile kal_uint32 *)(0x8010001c) = 0;
   
   return duration;
}


/**********************************************************
Description : Device initialization according to definition.
Input       : None
Output      : None
***********************************************************/
void DriverInit(void)
{
   kal_uint16  delay;

   for (delay=0; delay<0xffff; delay++);

   WacthDogRestart();
   
   WaitFor32KStable();
   
   WacthDogRestart();

   uart_init();

   NFIReconfigure();
   
   // Disable power-down control of DMA
   *(volatile kal_uint32 *)(0x80000320) = 0x01;
}




