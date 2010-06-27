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
 *    drv_features_6225.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is merged for MT6225 driver features.
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef DRV_FEATURES_6225_H
#define DRV_FEATURES_6225_H

#if  defined(MT6225)

/* Features for LCD */
#define DRV_LAYER_TOTAL_COUNT   4
#undef DRV_LAYER_COLOR_FORMAT						/* support RGB888/ARGB8888 or not */
#define DRV_LAYER_ROTATE							/* support LCD layer rotate or not */
#define DRV_PALETTE_COUNT	1
#define DRV_PALETTE_RGB_565						/* support color palette up to RGB565 */
#undef DRV_PALETTE_RGB_888							/* support color palette up to RGB888 */
#define DRV_LCD_ROI_BACKGROUND_COLOR
#define DRV_LCD_MEMORY_OUTPUT

/*start of XXXXX*/
#define DRV_LCD_MEMORY_OUTPUT_RGB565_SUPPORT
#undef DRV_LCD_MEMORY_OUTPUT_RGB888_SUPPORT
#undef DRV_LCD_MEMORY_OUTPUT_ARGB8888_SUPPORT
#define DRV_LCD_GAMMA_CORRECTION_SUPPORT
#undef DRV_LCD_HW_TRIGGER_SUPPORT
#undef DRV_LCD_DC_TRIGGER_SUPPORT 
#define DRV_LCD_CMD_QUEUE_COUNT 2
#define DRV_LCD_FW_UPDATE_SUPPORT

/* Features for Image Data Path */
#undef DRV_IDP_SUPPORT
#define DRV_IDP_6225_SERIES

/* Features for TVout */
#undef DRV_TVOUT_6228_SERIES 					/* not support TVOUT SERIES  */
/*end of XXXXX*/

#undef DRV_2D_ENGINE_V1								/* support G2D engine V1 */
#undef DRV_2D_ENGINE_V2								/* support G2D engine V2 */

/* Features for USB */
#define DRV_USB_6225_SERIES 					/* support USB 6225 SERIES IP */


/* Features for UPLL */
#define DRV_UPLL_6225_SERIES 					/* support UPLL 6225 SERIES IP */

#define DRV_I2C_25_SERIES

#define USE_INT26_CARD_DETECTION
#define DRV_MSDC_INSWP_MT6219_SERIES
#define DRV_MSDC_MT6225_SERIES
#define MSDC_MULTI_BLOCK_WRITE

/* Features for ADC */
#define DRV_ADC_6225_SERIES

/* Features for GCU*/
#define DRV_GCU_6225_SERIES

/* Features for GPT*/
#define DRV_GPT_6217_SERIES

/* Features for KBD*/
#define DRV_KBD_6225_SERIES

/* Features for PWM */
#define DRV_PWM_6205B_SERIES

/* Features for RTC */
#define DRV_RTC_6218B_SERIES

/* Features for WDT */
#define DRV_WDT_6217_SERIES

/* Features for UART */
#define DRV_UART_6225_SERIES

/* Features for IrDA */
#define DRV_IRDA_6225_SERIES

/* Features for GPIO */
#define DRV_GPIO_6225_SERIES

/* Misc. driver featuers */
#define DRV_MISC_6217_SERIES

/* JPEG FEATURES */
#ifndef __SW_JPEG_CODEC_SUPPORT__
 #define __SW_JPEG_CODEC_SUPPORT__
#endif

/*Multimedia init*/
#define MULTIMEDIA_INIT_MT6219_SERIES

/* Features for Camera ISP */
#define DRV_ISP_6225_SERIES

#define DRV_SIM_GEMINI

   /*Above is MT6225*/
#endif   /*End of MT6225*/
#endif /* DRV_FEATURES_6225_H */
