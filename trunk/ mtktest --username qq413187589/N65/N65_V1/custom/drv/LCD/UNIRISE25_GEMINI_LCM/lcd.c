/*****************************************************************************
* Copyright Statement:  
* --------------------
* This software is protected by Copyright and the information contained
* herein is confidential. The software may not be copied and the information
* contained herein may not be used or disclosed except with the written
* permission of BEIWEI Inc. (C) 2005
*
*****************************************************************************/
/*============================================================================
*
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/custom/drv/LCD/U25_06B_LCM/lcd.c,v 1.8 2007/09/27 01:09:53 bw Exp $
*
* $Id: lcd.c,v 1.8 2007/09/27 01:09:53 bw Exp $
*
* $Date: 2007/09/27 01:09:53 $
*
* $Name: 1.8 $
*
* $Locker$
*
* $Revision: 1.8 $
*
* $State: Exp $
*
* HISTORY
* Below this line, this part is controlled by CVS. DO NOT MODIFY!!
*----------------------------------------------------------------------------
* $Log: lcd.c,v $
* Revision 1.8  2007/09/27 01:09:53  bw
* UNI@bw_20070926 15:06:43  添加信利2.0寸LCD 信利TFT8K0640FPC-A1/1N0756/S6D0128/TYPE:9/2007-09-26软件开始支持
*
* Revision 1.7  2007/09/11 06:25:45  banben
* UNI@HUANGLIN_20070905  移植2.4寸truly  1N2098 ADC=93 TYPE=13  IC LGDP4532 LCD驱动  提交日期:07/09/11:15
*
* Revision 1.6  2007/09/05 06:24:45  bw
* UNI@bw_20070816 15:06:43 [ALL][ALL] 添加精电2.0寸LCD
* 	  精电/FPC-SH9656-51A-56/9656-51/LGDP4524/ADC:1011/TYPE:13/2007-08-16软件开始支持
* 	  精电/FPC-SH9656-51A-56/9516-51/LGDP4524/ADC:1011/TYPE:13/2007-08-16软件开始支持
*
* Revision 1.5  2007/08/31 00:20:39  bw
* UNI@bw_20070820 10:15:20   移植2.4寸LCD驱动到BEIW11,BEIW3H
*
* Revision 1.4  2007/07/26 03:45:25  bw
* UNI@bw_0726 解决精电31LCD半亮水波纹问题
*
* Revision 1.3  2007/07/12 09:41:53  bw
* UNI@bw_20070711整理lcd的adc值范围.使其覆盖所有adc值.防止单板无法开机
*
* Revision 1.2  2007/05/21 06:08:10  yangzeping
* UNI@yangzeping_20070521e 14:08 提交BEIW8,BEIW9的LCD驱动(176x220)
*
* Revision 1.1  2007/05/17 07:11:40  bw
* UNI@bw_20070517 15:10:01 MTK U25 U26 06B V30 version
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
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
 *    lcd.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the LCD driver.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_comm.h"
#include "reg_base.h"
#include "lcd_sw_inc.h"
#include "lcd_sw.h"
#include "lcd_hw.h"
/*Serial interface*/
#include "lcd_if.h"
#include "lcd_sw_rnd.h"

#ifdef CAMERA_MODULE
#include "VIM_HIGH_API.h"
#include "gpio_drv.h"
#endif

#ifndef __CUST_NEW__
extern void GPIO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada);
extern void GPIO_WriteIO(char data, char port);
#endif /* __CUST_NEW__ */

extern void PWM2_level(kal_uint8 level);
volatile kal_uint32 g_iFactor = 50;
kal_bool  lcd_assert_fail = KAL_FALSE;
kal_uint8 lcd_check = 0;
kal_uint8 lcd_reg_index = 0;
kal_uint16 lcd_id_adc;
kal_uint16 Mmi_Lcd_Id_Type = 0;


#ifdef DUAL_LCD

	#ifndef COLOR_SUBLCD
		const kal_uint8 SubLCDSetArray[]=
		{
			0x01,	// 0000 0001
			0x02,	// 0000 0010
			0x04,	// 0000 0100
			0x08,	// 0000 1000
			0x10,	// 0001 0000
			0x20,	// 0010 0000
			0x40,	// 0100 0000
			0x80	// 1000 0000
		};

		const kal_uint8 SubLCDReSetArray[]=
		{
			0xFE,	// 1111 1110
			0xFD,	// 1111 1101
			0xFB,	// 1111 1011
			0xF7,	// 1111 0111
			0xEF,	// 1110 1111
			0xDF,	// 1101 1111
			0xBF,	// 1011 1111
			0x7F	// 0111 1111
		};
	#endif
#endif

void LCD_Delay(kal_uint32 delay_count)
{
	volatile kal_uint32 delay;
	for (delay = 0; delay < delay_count * g_iFactor; delay++);
}

void LCD_Delay_ms(kal_uint8 time)
{
	volatile unsigned long delay;
	for (delay =0;delay <time*9600;delay++) {} // 1ms
}

void LCD_Delayms(kal_uint8 time)
{
	volatile unsigned long delay;
	for (delay =0;delay <time*9600;delay++) {} // 1ms
}


void spi_ini(void)
{
}

#if (defined(MT6217) || defined(MT6218B) || defined(MT6219) || defined(MT6225) || defined(MT6226) || defined(MT6226M) || defined(MT6227))
void init_lcd_interface(void)
{
	kal_uint32 i;

	SET_LCD_CTRL_RESET_PIN;
	LCD_Delay(2);

	REG_LCD_ROI_CTRL = 0;
	CLEAR_LCD_CTRL_RESET_PIN;
    #if (defined(MT6219) || defined(MT6225) || defined(MT6226) || defined(MT6226M) || defined(MT6227))
	   	SET_LCD_PARALLEL_CE2WR_SETUP_TIME((kal_uint32)2);
	   	SET_LCD_PARALLEL_CE2WR_HOLD_TIME(2);
	   	SET_LCD_PARALLEL_CE2RD_SETUP_TIME(3);
	   	SET_LCD_PARALLEL_WRITE_WAIT_STATE(4);
	   	SET_LCD_PARALLEL_READ_LATENCY_TIME(31);
	   	SET_LCD_ROI_CTRL_CMD_LATENCY(2);
        SET_LCD_SERIAL_CLOCK_52M;

        #if (defined(MT6225) || defined(MT6226) || defined(MT6226M) || defined(MT6227))
            #if (defined(LCD_18BIT_MODE))
                #ifndef __CUST_NEW__
                    GPIO_ModeSetup(55, 1);  // LCD D[16]
                    GPIO_ModeSetup(56, 1);  // LCD D[17]
                #else
    		        *((volatile unsigned short *) 0x801201B0) |= 0x4000;  // LCD D[16]
	    	        *((volatile unsigned short *) 0x801201D0) |= 0x0001;  // LCD D[17]
                #endif
   	            SET_LCD_PARALLEL_18BIT_DATA_BUS;
          	#elif (defined(LCD_16BIT_MODE))
                SET_LCD_PARALLEL_16BIT_DATA_BUS;
            #elif (defined(LCD_8BIT_MODE))
   		        SET_LCD_PARALLEL_8BIT_DATA_BUS;
   		    #endif /* (defined(LCD_18BIT_MODE)) */

		// XXX LCD GAMMA Here!!
   	    /*SET_LCD_PARALLEL_GAMMA_R_TABLE(LCD_PARALLEL_GAMMA_DISABLE);
   	    SET_LCD_PARALLEL_GAMMA_G_TABLE(LCD_PARALLEL_GAMMA_DISABLE);
   	    SET_LCD_PARALLEL_GAMMA_B_TABLE(LCD_PARALLEL_GAMMA_DISABLE);*/

		    for (i = 0; i < 62; i++) {
                SET_GAMMA_TABLE(LCD_GAMMA_TABLE0, i, i);
            }

		    SET_GAMMA_TABLE(LCD_GAMMA_TABLE0, 62, 61);
		    SET_GAMMA_TABLE(LCD_GAMMA_TABLE0, 63, 61);
		    SET_LCD_PARALLEL_GAMMA_R_TABLE(LCD_PARALLEL_GAMMA_TABLE0);
   	        SET_LCD_PARALLEL_GAMMA_G_TABLE(LCD_PARALLEL_GAMMA_TABLE0);
       	    SET_LCD_PARALLEL_GAMMA_B_TABLE(LCD_PARALLEL_GAMMA_TABLE0);
        #endif  /* (defined(MT6225) || defined(MT6226) || defined(MT6226M) || defined(MT6227)) */
        #if (defined(MT6219))
        DISABLE_LCD_PARALLEL_SYNC;
        #endif
    #endif /* (defined(MT6219) || defined(MT6225) || defined(MT6226) || defined(MT6226M) || defined(MT6227)) */

	LCD_Delay(100);
	SET_LCD_CTRL_RESET_PIN;
	LCD_Delay(5);
}	/* init_lcd_interface() */
#endif /* (defined(MT6217) || defined(MT6218B) || defined(MT6219) || defined(MT6225) || defined(MT6226) || defined(MT6226M) || defined(MT6227)) */



/*===================The above is LCD dependent==========*/
#if ( (defined(MT6205B)) || (defined(MT6218)) )
void LCD_memcpy(void *dst /*s1*/, const void *src /*s2*/, kal_uint16 size)
{
   #ifdef LCD_DMAENABLE
      kal_uint32 srcaddr=(kal_uint32)src;
      kal_uint32 dstaddr=(kal_uint32)dst;
      kal_uint16 size_MSB = (kal_uint16)(size >> 9);
      kal_uint16 size_LSB = (kal_uint16)(size & 0x01ff);

      ASSERT(lcd_assert_fail==KAL_FALSE);
      lcd_assert_fail = KAL_TRUE;
      ASSERT(DRV_Reg(LCD_REFR)==0x00);
      if(size_MSB)
      {
         DRV_WriteReg(LCD_MSBSRC,(kal_uint16)(srcaddr >> 16));
         DRV_WriteReg(LCD_LSBSRC,(kal_uint16)srcaddr);

         DRV_WriteReg(LCD_REFR,0x0000);
         DRV_WriteReg(LCD_MSBDST,(kal_uint16)(dstaddr >> 16));
         DRV_WriteReg(LCD_LSBDST,(kal_uint16)(dstaddr));

         DRV_WriteReg(LCD_CADDRSET,512);
         DRV_WriteReg(LCD_PADDRSET,size_MSB);
         DRV_WriteReg(LCD_CHOP,0);

         DRV_WriteReg(LCD_PCON,LCD_PCON_DINC);

         DRV_WriteReg(LCD_START,LCD_START_BIT);
         while(DRV_Reg(LCD_GSTA)&LCD_GSTA_PRUN);
         DRV_WriteReg(LCD_START,LCD_STOP_BIT);
      }

      if (size_LSB)
      {
         srcaddr = (srcaddr + size - size_LSB);
         dstaddr = (dstaddr + size - size_LSB);

         DRV_WriteReg(LCD_MSBSRC,(kal_uint16)(srcaddr >> 16));
         DRV_WriteReg(LCD_LSBSRC,(kal_uint16)srcaddr);

         DRV_WriteReg(LCD_REFR,0x0000);
         DRV_WriteReg(LCD_MSBDST,(kal_uint16)(dstaddr >> 16));
         DRV_WriteReg(LCD_LSBDST,(kal_uint16)(dstaddr));

         DRV_WriteReg(LCD_CADDRSET,size_LSB);
         DRV_WriteReg(LCD_PADDRSET,1);
         DRV_WriteReg(LCD_CHOP,0);

         DRV_WriteReg(LCD_PCON,LCD_PCON_DINC);

         DRV_WriteReg(LCD_START,LCD_START_BIT);
         while(DRV_Reg(LCD_GSTA)&LCD_GSTA_PRUN);
         DRV_WriteReg(LCD_START,LCD_STOP_BIT);
      }

      lcd_assert_fail = KAL_FALSE;
   #else /*!LCD_DMAENABLE*/
      kal_mem_cpy(dst,src,size);
   #endif   /*LCD_DMAENABLE*/
}
#else /*!(MT6205B,MT6218)*/
void LCD_memcpy(void *dst /*s1*/, const void *src /*s2*/, kal_uint16 size)
{
   kal_mem_cpy(dst,src,size);
}
#endif   /*(MT6205B,MT6218)*/

#if defined(LCD_FT1505C_YT372804PL)
#include "lcd_ft1505c_yt372804pl.h"
#elif defined(LCD_FT1505C_YT372604PE)
#include "lcd_ft1505c_yt372604pe.h"
#elif defined(LCD_FT1505C_YT372604PF)
#include "lcd_ft1505c_yt372604pf.h"
#elif defined(LCD_FT1505C_YT372804PK)
#include "lcd_ft1505c_yt372804pk.h"
#elif defined(LCD_FT1505C_YT372404PQ)
#include "lcd_ft1505c_yt372404pq.h"
#endif 



void LCD_FunConfig(void)
{
	Mmi_Lcd_Id_Type  = 4;
#if defined(LCD_FT1505C_YT372804PL)
	MainLCD = &LCD_func_FT1505;
#elif defined(LCD_FT1505C_YT372604PE)
	MainLCD = &LCD_func_FT1505;
#elif defined(LCD_FT1505C_YT372604PF)
	MainLCD = &LCD_func_FT1505;
#elif defined(LCD_FT1505C_YT372804PK)
	MainLCD = &LCD_func_FT1505;
#elif defined(LCD_FT1505C_YT372404PQ)
	MainLCD = &LCD_func_FT1505;
#endif 
}

