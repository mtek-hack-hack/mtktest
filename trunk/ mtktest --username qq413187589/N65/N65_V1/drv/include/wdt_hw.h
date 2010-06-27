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
 *    wdt_hw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intends for WDT driver.
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
#ifndef _WDT_HW_H
#define _WDT_HW_H
#include "drv_features.h"

#define WDT_base                RGU_base                            /* Watchdog Timer                         */

/*****************
 * WDT Registers *
 *****************/
#if defined(DRV_WDT_LIMIT_REG) || defined(FPGA)
   #define 	WDT_MODE   	                     (WDT_base+0x0000)
   #define 	WDT_LENGTH 	                     (WDT_base+0x0004)
   #define 	WDT_RESTART 	                  (WDT_base+0x0008)
   #define 	WDT_STATUS  	                  (WDT_base+0x000C)
   #define 	RGU_PERIPH_RESET                 (WDT_base+0x0010)
   #define 	RGU_DSP_RESET                    (WDT_base+0x0014)
   #define 	WDT_RSTINTERVAL  	               (WDT_base+0x0018)
                                             
   #define 	WDT_MODE_KEYMASK	               0xff00
   #define 	WDT_MODE_EXTEN		               0x0004
   #define 	WDT_MODE_EXTPOL		            0x0002
   #define 	WDT_MODE_ENABLE		            0x0001
   #define 	WDT_LENGTH_TOUT		            0xff00
   #define 	WDT_LENGTH_KEYMASK	            0x00ff
   #define 	WDT_RESTART_KEY		            0x1971
   #define 	WDT_STATUS_BITMASK	            0x8000
   #define 	WDT_LENGTH_KEY		               0x0008
   #define 	WDT_MODE_KEY		               0x2200
   #define  WDT_RSTINTERVAL_MASK             0x0fff
   
   #define  RGU_PERIPH_RESET_APB_PERIPH      0x8000
   #define  RGU_PERIPH_RESET_DMA             0x4000
   
   #define  RGU_DSP_RESET_BIT                0x8000
#endif   /*DRV_WDT_LIMIT_REG,FPGA*/

#if defined(DRV_WDT_BASIC_REG)
   #define 	WDT_MODE   	                     (WDT_base+0x0000)
   #define 	WDT_LENGTH 	                     (WDT_base+0x0004)
   #define 	WDT_RESTART 	                  (WDT_base+0x0008)
   #define 	WDT_STATUS  	                  (WDT_base+0x000C)
   #define 	RGU_PERIPH_RESET                 (WDT_base+0x0010)
   #define 	RGU_DSP_RESET                    (WDT_base+0x0014)
   #define 	WDT_RSTINTERVAL  	               (WDT_base+0x0018)
   #define 	WDT_SWRST        	               (WDT_base+0x001c)
                                             
   /*WDT_MODE*/
   #define 	WDT_MODE_KEYMASK	               0xff00
   #define 	WDT_MODE_AUTORST                 0x0010
   #define 	WDT_MODE_IRQEN		               0x0008
   #define 	WDT_MODE_EXTEN		               0x0004
   #define 	WDT_MODE_EXTPOL		            0x0002
   #define 	WDT_MODE_ENABLE		            0x0001
   #define 	WDT_MODE_KEY		               0x2200
   
   /*WDT_LENGTH*/
   #define 	WDT_LENGTH_TOUT		            0xffe0
   #define 	WDT_LENGTH_KEYMASK	            0x001f
   #define 	WDT_LENGTH_KEY		               0x0008
   
   /*WDT_RESTART*/
   #define 	WDT_RESTART_KEY		            0x1971
   
   /*WDT_STATUS*/
   #define 	WDT_STATUS_BITMASK	            0xc000
   #define 	WDT_STATUS_SWWDT  	            0x4000
   
   /*WDT_RSTINTERVAL*/
   #define  WDT_RSTINTERVAL_MASK             0x0fff
   
   /*RGU_PERIPH_RESET*/
   #define  RGU_PERIPH_RESET_APB_PERIPH      0x8000
   #define  RGU_PERIPH_RESET_DMA             0x4000
   #define  RGU_PERIPH_RESET_USB             0x2000
   #define  RGU_PERIPH_RESET_DISP            0x0800
   
   /*RGU_DSP_RESET*/
   #define  RGU_DSP_RESET_BIT                0x8000
   
   /*WDT_SWRST*/
   #define  WDT_SWRST_KEY                    0x1209
#endif   /*DRV_WDT_BASIC_REG*/
#endif   /*_WDT_HW_H*/

