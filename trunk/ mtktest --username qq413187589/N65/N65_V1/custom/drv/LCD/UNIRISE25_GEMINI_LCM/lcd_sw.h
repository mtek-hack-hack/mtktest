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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/custom/drv/LCD/U25_06B_LCM/lcd_sw.h,v 1.3 2007/09/11 06:36:19 banben Exp $
*
* $Id: lcd_sw.h,v 1.3 2007/09/11 06:36:19 banben Exp $
*
* $Date: 2007/09/11 06:36:19 $
*
* $Name: 1.3 $
*
* $Locker$
*
* $Revision: 1.3 $
*
* $State: Exp $
*
* HISTORY
* Below this line, this part is controlled by CVS. DO NOT MODIFY!!
*----------------------------------------------------------------------------
* $Log: lcd_sw.h,v $
* Revision 1.3  2007/09/11 06:36:19  banben
* UNI@HUANGLIN_20070905  ÒÆÖ²2.4´çtruly  1N2098 ADC=93 TYPE=13  IC LGDP4532 LCDÇý¶¯  Ìá½»ÈÕÆÚ:07/09/11:15
*
* Revision 1.2  2007/08/31 00:20:47  bw
* UNI@bw_20070820 10:15:20   ÒÆÖ²2.4´çLCDÇý¶¯µ½BEIW11,BEIW3H
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
 *    lcd_sw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intends for LCD driver.
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "lcd_if.h"

#ifndef _LCD_SW_H
#define _LCD_SW_H

#if (defined(MT6217) || defined(MT6218B) || defined(MT6219) || defined(MT6225) || defined(MT6226) || defined(MT6226M) || defined(MT6227))
    #define LCD_CMD_DMA_MODE
//    #define LCD_16BIT_MODE
/*UNI@bw_20070820 10:14:58     ÒÆÖ²2.4´çLCDÇý¶¯*/
    #if 1 // defined (BEIW11_BOARD_DRV) || defined(BEIW3H_BOARD_DRV) /* hongzhe.liu 20080603 */
         #define LCD_16BIT_MODE
    #else
    #define LCD_8BIT_MODE
    #endif 

    #define LCD_DUMMYADDR   (0x90000000)

    #define LCD_HX8306A_CTRL_ADDR   LCD_PARALLEL0_A0_LOW_ADDR
    #define LCD_HX8306A_DATA_ADDR   LCD_PARALLEL0_A0_HIGH_ADDR
    #define MAIN_LCD_CMD_ADDR       LCD_HX8306A_CTRL_ADDR
    #define MAIN_LCD_DATA_ADDR      LCD_HX8306A_DATA_ADDR
    #ifdef LCD_16BIT_MODE
    	#define MAIN_LCD_OUTPUT_FORMAT  LCM_16BIT_16_BPP_RGB565_1
    #else
    	#define MAIN_LCD_OUTPUT_FORMAT  LCM_8BIT_16_BPP_RGB565_1
    #endif
#endif

/***********************S1D15G00********************************/
/*HIMAX, 262K Color LCD, Parallel Interface, Pxtel development board*/

#if (defined(MT6217) || defined(MT6218B) || defined(MT6219) || defined(MT6225) || defined(MT6226) || defined(MT6226M) || defined(MT6227))

    #ifdef LCD_CMD_DMA_MODE

    #define LCD_SEND_DMA_CMD(n) \
    {\
        while (LCD_IS_RUNNING);\
        DISABLE_LCD_TRANSFER_COMPLETE_INT;\
        DISABLE_ALL_LCD_LAYER_WINDOW;\
        SET_LCD_ROI_CTRL_NUMBER_OF_CMD(n);\
        ENABLE_LCD_ROI_CTRL_CMD_FIRST;\
        SET_LCD_ROI_WINDOW_SIZE(0, 0);\
        START_LCD_TRANSFER;\
        while (LCD_IS_RUNNING);\
    }

    #ifdef LCD_16BIT_MODE
        #define LCD_CtrlWrite_HX8306A(_data) \
        {\
            SET_LCD_CMD_PARAMETER(0, LCD_CMD, _data);\
            LCD_SEND_DMA_CMD(1);\
        }

        #define LCD_DataWrite_HX8306A(_data) \
        {\
            SET_LCD_CMD_PARAMETER(0, LCD_DATA, _data);\
            LCD_SEND_DMA_CMD(1);\
        }

        #define LCD_delay_HX8306A()

        #define LCD_CtrlWrite_HX8306A_ESD(_data)  \
        {\
            *(volatile kal_uint32 *) LCD_HX8306A_CTRL_ADDR = _data;\
            LCD_delay_HX8306A();\
        }

        #define LCD_DataWrite_HX8306A_ESD(_data) \
        {\
            *(volatile kal_uint32 *) LCD_HX8306A_DATA_ADDR = _data;\
            LCD_delay_HX8306A();\
        }


/*UNI@bw_20070820 11:03:07   ÒÆÖ²2.4´çLCDÇý¶¯  */
	
#define LCD_CtrlWrite_HX8312(_data) \
		{\
			SET_LCD_CMD_PARAMETER(0,LCD_CMD,(_data & 0xFFFF));\
			LCD_SEND_DMA_CMD(1);\
		}\

#define LCD_CtrlWrite_R61505(_data) \
		{\
			SET_LCD_CMD_PARAMETER(0,LCD_CMD,(_data & 0xFFFF));\
			LCD_SEND_DMA_CMD(1);\
		}\
		
#define LCD_DataWrite_R61505(_data) \
		{\
			SET_LCD_CMD_PARAMETER(0,LCD_DATA,(_data & 0xFFFF));\
			LCD_SEND_DMA_CMD(1);\
		}\
		
#define LCD_CtrlWrite_ILI9320(_data) \
		{\
			SET_LCD_CMD_PARAMETER(0,LCD_CMD,(_data & 0xFFFF));\
			LCD_SEND_DMA_CMD(1);\
		}\
		
#define LCD_DataWrite_ILI9320(_data) \
		{\
			SET_LCD_CMD_PARAMETER(0,LCD_DATA,(_data & 0xFFFF));\
			LCD_SEND_DMA_CMD(1);\
		}\

#define LCD_CtrlWrite_ILI9325(_data) \
		{\
			SET_LCD_CMD_PARAMETER(0,LCD_CMD,(_data & 0xFFFF));\
			LCD_SEND_DMA_CMD(1);\
		}\
		
#define LCD_DataWrite_ILI9325(_data) \
		{\
			SET_LCD_CMD_PARAMETER(0,LCD_DATA,(_data & 0xFFFF));\
			LCD_SEND_DMA_CMD(1);\
		}\

#define LCD_CtrlWrite_8347(_data) \
		{\
			SET_LCD_CMD_PARAMETER(0,LCD_CMD,(_data & 0xFFFF));\
			LCD_SEND_DMA_CMD(1);\
		}\
		
#define LCD_DataWrite_8347(_data) \
		{\
			SET_LCD_CMD_PARAMETER(0,LCD_DATA,(_data & 0xFFFF));\
			LCD_SEND_DMA_CMD(1);\
		}\

#define LCD_CtrlWrite_8340(_data) \
		{\
			SET_LCD_CMD_PARAMETER(0,LCD_CMD,(_data & 0xFFFF));\
			LCD_SEND_DMA_CMD(1);\
		}\
		
#define LCD_DataWrite_8340(_data) \
		{\
			SET_LCD_CMD_PARAMETER(0,LCD_DATA,(_data & 0xFFFF));\
			LCD_SEND_DMA_CMD(1);\
		}\

#define LCD_CtrlWrite_FD5408(_data) \
		{\
			SET_LCD_CMD_PARAMETER(0,LCD_CMD,(_data & 0xFFFF));\
			LCD_SEND_DMA_CMD(1);\
		}\
		
#define LCD_DataWrite_FD5408(_data) \
		{\
			SET_LCD_CMD_PARAMETER(0,LCD_DATA,(_data & 0xFFFF));\
			LCD_SEND_DMA_CMD(1);\
		}\

//yangyaojia 2008.3.14




#define LCD_CtrlWrite_FT1505(_data) \
		{\
			SET_LCD_CMD_PARAMETER(0,LCD_CMD,(_data & 0xFFFF));\
			LCD_SEND_DMA_CMD(1);\
		}\




#define LCD_DataWrite_FT1505(_data) \
		{\
			SET_LCD_CMD_PARAMETER(0,LCD_DATA,(_data & 0xFFFF));\
			LCD_SEND_DMA_CMD(1);\
		}\

/* 2009.04.08 added by hongzhe.liu for 39115 + */
#define LCD_CtrlWrite_39115(_data) \
		{\
			SET_LCD_CMD_PARAMETER(0,LCD_CMD,(_data & 0xFFFF));\
			LCD_SEND_DMA_CMD(1);\
		}\

#define LCD_DataWrite_39115(_data) \
		{\
			SET_LCD_CMD_PARAMETER(0,LCD_DATA,(_data & 0xFFFF));\
			LCD_SEND_DMA_CMD(1);\
		}\

/* 2009.04.08 added by hongzhe.liu for 39115 - */

#define LCD_CtrlWrite_HX8340(_data) \
		{\
			SET_LCD_CMD_PARAMETER(0,LCD_CMD,(_data & 0xFFFF));\
			LCD_SEND_DMA_CMD(1);\
		}\




#define LCD_DataWrite_HX8340(_data) \
		{\
			SET_LCD_CMD_PARAMETER(0,LCD_DATA,(_data & 0xFFFF));\
			LCD_SEND_DMA_CMD(1);\
		}\



#define LCD_CtrlWrite_R61505U(_data) \
		{\
			SET_LCD_CMD_PARAMETER(0,LCD_CMD,(_data & 0xFFFF));\
			LCD_SEND_DMA_CMD(1);\
		}\
	
#define LCD_DataWrite_R61505U(_data) \
		{\
			SET_LCD_CMD_PARAMETER(0,LCD_DATA,(_data & 0xFFFF));\
			LCD_SEND_DMA_CMD(1);\
		}\
		
#define LCD_CtrlWrite_TL1763(_data) \
		{\
			SET_LCD_CMD_PARAMETER(0,LCD_CMD,(_data & 0xFFFF));\
			LCD_SEND_DMA_CMD(1);\
		}\
		
#define LCD_DataWrite_TL1763(_data) \
		{\
			SET_LCD_CMD_PARAMETER(0,LCD_DATA,(_data & 0xFFFF));\
			LCD_SEND_DMA_CMD(1);\
		}\
		
#define LCD_CtrlWrite_SSD1289(_data) \
		{\
			SET_LCD_CMD_PARAMETER(0,LCD_CMD,(_data & 0xFFFF));\
			LCD_SEND_DMA_CMD(1);\
		}\
		
#define LCD_DataWrite_SSD1289(_data) \
		{\
			SET_LCD_CMD_PARAMETER(0,LCD_DATA,(_data & 0xFFFF));\
			LCD_SEND_DMA_CMD(1);\
		}\

		

            	#define LCD_CtrlWrite_TFT_ILI9220(_data)  \
		{\
			SET_LCD_CMD_PARAMETER(0,LCD_CMD,(_data & 0xFF00) >>8);\
			SET_LCD_CMD_PARAMETER(1,LCD_CMD,(_data & 0xFF));\
			LCD_SEND_DMA_CMD(2);\
		}\

    #define LCD_RAMWrite_TFT_ILI9220(_data)  \
	       {\
		    SET_LCD_CMD_PARAMETER(0,LCD_DATA,(_data & 0xFF00) >>8);\
			SET_LCD_CMD_PARAMETER(1,LCD_DATA,(_data & 0xFF));\
			LCD_SEND_DMA_CMD(2);\
	       }

#define LCD_CtrlWrite_ILI9320_9650_61(_data) \
		{\
			SET_LCD_CMD_PARAMETER(0,LCD_CMD,(_data & 0xFFFF));\
			LCD_SEND_DMA_CMD(1);\
		}\
		
#define LCD_DataWrite_ILI9320_9650_61(_data) \
		{\
			SET_LCD_CMD_PARAMETER(0,LCD_DATA,(_data & 0xFFFF));\
			LCD_SEND_DMA_CMD(1);\
		}\
		
/*UNI@HUANGLIN_20070905  ÒÆÖ²2.4´çtruly  1N2098 ADC=93 TYPE=13  IC LGDP4532 LCDÇý¶¯  Ìá½»ÈÕÆÚ:07/09/11:15  */
#define LCD_CtrlWrite_TFT_LGDP4532(_data) \
		{\
			SET_LCD_CMD_PARAMETER(0,LCD_CMD,(_data & 0xFFFF));\
			LCD_SEND_DMA_CMD(1);\
		}\
		
#define LCD_DataWrite_TFT_LGDP4532(_data) \
		{\
			SET_LCD_CMD_PARAMETER(0,LCD_DATA,(_data & 0xFFFF));\
			LCD_SEND_DMA_CMD(1);\
		}\
		
/*UNI@bw_20070820 11:03:07   ÒÆÖ²2.4´çLCDÇý¶¯  */


    #elif (defined(LCD_8BIT_MODE))
		#define myLCD_delay_HX8306A() \
		{\
			volatile kal_uint16 iI; \
			for (iI = 0; iI < 0x20; iI++);\
		}

        #define LCD_CtrlWrite_HX8306A(_data) \
        {\
            SET_LCD_CMD_PARAMETER(0, LCD_CMD, (_data >> 8));\
            LCD_SEND_DMA_CMD(1);\
			myLCD_delay_HX8306A();\
            SET_LCD_CMD_PARAMETER(0, LCD_CMD, (_data & 0x00FF));\
            LCD_SEND_DMA_CMD(1);\
        }

        #define LCD_DataWrite_HX8306A(_data) \
        {\
            SET_LCD_CMD_PARAMETER(0, LCD_DATA, (_data >> 8));\
            LCD_SEND_DMA_CMD(1);\
            myLCD_delay_HX8306A();\
            SET_LCD_CMD_PARAMETER(0, LCD_DATA, (_data & 0x00FF));\
            LCD_SEND_DMA_CMD(1);\
        }

        #define LCD_delay_HX8306A()

        #define LCD_CtrlWrite_HX8306A_ESD(_data) \
        {\
            *(volatile kal_uint8 *) LCD_HX8306A_CTRL_ADDR = (_data >> 8);\
            *(volatile kal_uint8 *) LCD_HX8306A_CTRL_ADDR = (_data & 0x00FF);\
            LCD_delay_HX8306A();\
        }

        #define LCD_DataWrite_HX8306A_ESD(_data)  \
        {\
            *(volatile kal_uint8 *) LCD_HX8306A_DATA_ADDR = (_data >> 8);\
            *(volatile kal_uint8 *) LCD_HX8306A_DATA_ADDR = (_data & 0x00FF);\
            LCD_delay_HX8306A();\
        }

    #endif  /*  LCD_16BIT_MODE  */
	
	#else   /* LCD_CMD_DMA_MODE */

    #ifdef LCD_16BIT_MODE
        #define LCD_delay_HX8306A()

        #define LCD_CtrlWrite_HX8306A(_data) \
        {\
            *(volatile kal_uint32 *) LCD_HX8306A_CTRL_ADDR = ((_data & 0xFF00) << 2) | ((_data & 0xFF) << 1);\
            LCD_delay_HX8306A();\
        }

        #define LCD_DataWrite_HX8306A(_data) \
        {\
            *(volatile kal_uint32 *) LCD_HX8306A_DATA_ADDR = ((_data & 0xFF00) << 2) | ((_data & 0xFF) << 1);\
            LCD_delay_HX8306A();\
        }
    #elif (defined(LCD_8BIT_MODE))
		#define myLCD_delay_HX8306A() \
		{\
			volatile kal_uint16 iI; \
			for (iI = 0; iI < 0x20; iI++);\
		}

        #define LCD_CtrlWrite_HX8306A(_data) \
        {\
            *(volatile kal_uint8 *) LCD_HX8306A_CTRL_ADDR = (_data >> 8);\
            myLCD_delay_HX8306A(); \
            *(volatile kal_uint8 *) LCD_HX8306A_CTRL_ADDR = (_data & 0x00FF);\
            myLCD_delay_HX8306A(); \
        }

        #define LCD_DataWrite_HX8306A(_data) \
        {\
            *(volatile kal_uint8 *) LCD_HX8306A_DATA_ADDR = (_data >> 8);\
            myLCD_delay_HX8306A(); \
            *(volatile kal_uint8 *) LCD_HX8306A_DATA_ADDR = (_data & 0x00FF);\
            myLCD_delay_HX8306A(); \
        }
    #endif  /*  LCD_16BIT_MODE  */
    #endif  /* LCD_CMD_DMA_MODE */

    #define LCD_DataRead_HX8306A    (*(volatile kal_uint32 *)LCD_HX8306A_DATA_ADDR);
#endif

#endif   /*_LCD_SW_H*/
