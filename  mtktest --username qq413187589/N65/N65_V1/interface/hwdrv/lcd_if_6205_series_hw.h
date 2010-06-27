/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001-2007
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
 * lcd_if.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is to define LCD HW register in 6205, 6208 series.
 *
 * Author:
 * -------
 * -------
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Log$
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
 *
 *
 *
 *******************************************************************************/
#ifndef __LCD_IF_6205_SERIES_HW_H__
#define __LCD_IF_6205_SERIES_HW_H__

#include "kal_release.h"
#include "drv_features.h"

#if (defined(MT6205B))

/*Global Register*/
   #define LCD_GSTA              (LCD_base+0x0000)
   #define LCD_INTEN             (LCD_base+0x0004)
   #define LCD_INTSTA            (LCD_base+0x0008)
   #define LCD_INT_STATUS_REG    (LCD_base+0x0008)
   #define LCD_GSTA_PRUN         0x0001
   #define LCD_GSTA_SRUN         0x0002

   #define LCD_INTEN_PCPL        0x0001
   #define LCD_INTEN_SOVR        0x0002

   #define LCD_INTSTA_PCPL       0x0001
   #define LCD_INTSTA_SOVR       0x0002

/*Parallel LCD interface*/
   #define LCD_PCON              (LCD_base+0x0010)
   #define LCD_REFR              (LCD_base+0x0014)
   #define LCD_START             (LCD_base+0x0018)
   #define LCD_MSBSRC            (LCD_base+0x001c)
   #define LCD_LSBSRC            (LCD_base+0x0020)
   #define LCD_MSBDST            (LCD_base+0x0024)
   #define LCD_LSBDST            (LCD_base+0x0028)
   #define LCD_PADDRSET          (LCD_base+0x002c)
   #define LCD_CADDRSET          (LCD_base+0x0030)
   #define LCD_CHOP              (LCD_base+0x0034)

   #define LCD_PCON_GRADMASK     0x0003   /*00:B/W or 256 color, 01: 4096 color*/
   #define LCD_PCON_ACC          0x0100
   #define LCD_PCON_DINC         0x0200

   #define LCD_REFR_MASK         0x0fff
   #define LCD_START_BIT         0x8000
   #define LCD_STOP_BIT          0x0000

   #define LCD_PASET_MASK        0x03ff
   #define LCD_CASET_MASK        0x03ff
   #define LCD_CHOP_MASK         0x03ff
/*Serial Interface*/
   #define LCD_SCON              (LCD_base+0x0050)
   #define LCD_SSTA              (LCD_base+0x0054)
   #define LCD_DATACS0_A0LOW     (LCD_base+0x0060)  //Write Control data
   #define LCD_DATACS0_A0HIGH    (LCD_base+0x0064)  //Write display data
   #define LCD_DATACS1_A0LOW     (LCD_base+0x0068)  //Write Control data
   #define LCD_DATACS1_A0HIGH    (LCD_base+0x006c)  //Write display data

   #define LCD_SCON_SPO          0x0001
   #define LCD_SCON_SPH          0x0002
   #define LCD_SCON_SCRMASK      0x000c
   #define LCD_SCON_9BIT         0x0010
   #define LCD_SCON_CS0PO        0x0100
   #define LCD_SCON_CS1PO        0x0200
   #define LCD_SCON_NORMAL       (LCD_SCON_SPH|LCD_SCON_SPO)
                                 
   #define LCD_SSTA_EMP0         0x0001
   #define LCD_SSTA_EMP1         0x0002
#endif   /* MT6205B */

#if defined(MT6208)
   #define LCD_CTRL0             (LCD_base+0x0000)
   #define LCD_CTRL1             (LCD_base+0x0004)
   #define LCD_IRQEN             (LCD_base+0x0008)
   #define LCD_INT_STATUS_REG    (LCD_base+0x000c)
   #define LCD_STS               (LCD_base+0x000C)
   #define LCD_TIDE              (LCD_base+0x0010)
   #define LCD_COUNT             (LCD_base+0x0014)
   #define LCD_DATA_A0LOW        (LCD_base+0x0018) //Write Control data
   #define LCD_DATA_A0HIGH       (LCD_base+0x001C) //Write display data

   //CTRL0
   #define LCD_CTRL0_SPO         0x0001
   #define LCD_CTRL0_SPH         0x0002
   #define LCD_CTRL0_SCRMask     0x000c
   #define LCD_CTRL0_SCRDiv2     0x0000
   #define LCD_CTRL0_SCRDiv4     0x0004
   #define LCD_CTRL0_SCRDiv8     0x0008
   #define LCD_CTRL0_SCRDiv16    0x000c
   #define LCD_CTRL0_Normal      0x0003

   //LCD_CTRL1
   #define  LCD_CTRL1_CONT       0x0001
   #define  LCD_CTRL1_DSB0       0x0002
   #define  LCD_CTRL1_DSB1       0x0004
   #define  LCD_CTRL1_CS0PO      0x0008
   #define  LCD_CTRL1_CS1PO      0x0010
   //continuous mode enable, DSB0,DSB1 = 1,1 , CS0PO,CS1PO = LOW enable
   #define LCD_CTRL1_Normal      0x0007
   //continuous mode enable, DSB0,DSB1 = 0,0 , CS0PO,CS1PO = high enable
   #define LCD_CTRL1_NormalOff   0x0019

   //LCD_IRQEN
   #define LCD_IRQEN_TXTIDE      0x0001
   #define LCD_IRQEN_IDLE        0x0002

   //LCD_STS
   #define LCD_STS_TXTIDE        0x0001
   #define LCD_STS_IDLE          0x0002
#endif   /* MT6208 */
               

#endif //__LCD_IF_6205_SERIES_HW_H__
