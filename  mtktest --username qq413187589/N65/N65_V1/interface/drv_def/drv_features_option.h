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
 *    drv_features_option.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is merged for all driver feature options.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __DRV_FEATURES_OPTION_H__
#define __DRV_FEATURES_OPTION_H__

/****************JPG IMAGE DATA PATH******************/
#if (!defined(__MTK_TARGET__)||defined(__SW_JPEG_CODEC_SUPPORT__))
	#define DRV_IMG_CLIP_SUPPORT
	#define DRV_IMG_PITCH_MODE_SUPPORT	
	
	/* In the Following, need to be removed.*/
	#define DRV_IMG_RGB888_OUTPUT_SUPPORT
	#define DRV_IMG_MEM_OUTPUT_SUPPORT
	
#elif (defined(DRV_JPG_DATA_PATH_17_SERIES))

#elif (defined(DRV_JPG_DATA_PATH_19_SERIES))
	#define DRV_IMG_CLIP_SUPPORT
	#define DRV_RGB_RESIZE_SUPPORT
#elif (defined(DRV_JPG_DATA_PATH_28_SERIES))
	#define DRV_IMG_CLIP_SUPPORT
	#define DRV_IMG_PITCH_MODE_SUPPORT
   #define DRV_RGB_RESIZE_SUPPORT
   #define DRV_JPG_RESIZE_SUPPORT
	#define DRV_IMG_RGB888_OUTPUT_SUPPORT
	#define DRV_IMG_MEM_OUTPUT_SUPPORT
#endif

/**************** JPEG decoder *******************/
#if (!defined(__MTK_TARGET__)||defined(__SW_JPEG_CODEC_SUPPORT__))
	#define DRV_JPG_SW_DEC_SUPPORT	

#elif defined(DRV_JPG_DEC_17_SERIES)
	#define DRV_JPG_HW_DEC_SUPPORT

#elif defined(DRV_JPG_DEC_19_SERIES)
	#define DRV_JPG_HW_DEC_SUPPORT

#elif defined(DRV_JPG_DEC_28_SERIES)
	#define DRV_JPG_HW_DEC_SUPPORT
#endif

/**************** JPEG encoder *******************/
#if   defined(__SW_JPEG_CODEC_SUPPORT__)
	#define DRV_JPG_SW_ENC_SUPPORT
	#define DRV_JPG_ENC_YUV420_SUPPORT
	#define DRV_JPG_ENC_GRAYSVALE_SUPPORT
	#define DRV_JPG_ENC_MULTI_FORMAT_SUPPORT // Not only YUV422
	
#elif defined(DRV_JPG_ENC_19_SERIES)
	#define DRV_JPG_HW_ENC_SUPPORT
	#define DRV_JPG_SNAPSHOT_SUPPORT
	
#elif defined(DRV_JPG_ENC_28_SERIES)
	#define DRV_JPG_HW_ENC_SUPPORT
	#define DRV_JPG_SNAPSHOT_SUPPORT
	#define DRV_JPG_ENC_THUMBNAIL_SUPPORT	
	#define DRV_JPG_ENC_OVERLAY_SUPPORT
	#define DRV_JPG_ENC_YUV422_SUPPORT
	#define DRV_JPG_ENC_YUV420_SUPPORT
	#define DRV_JPG_ENC_GRAYSVALE_SUPPORT
	#define DRV_JPG_ENC_MULTI_FORMAT_SUPPORT // Not only YUV422
#endif

/**************** JPEG DEP************************/
/*DEC*/
#if (defined(DRV_JPG_SW_DEC_SUPPORT)||defined(DRV_JPG_HW_DEC_SUPPORT))
 #define DRV_JPG_DEC_SUPPORT
#endif

/*ENC*/
#if (defined(DRV_JPG_SW_ENC_SUPPORT)||defined(DRV_JPG_HW_ENC_SUPPORT))
 #define DRV_JPG_ENC_SUPPORT
#endif

/**************** MP4 *******************/
#if defined(DRV_MP4_6219_SERIES)
	#define DRV_MP4_V1
	#define DRV_MP4_V1_ENC_PAUSE_P_NOT_SUPPORT
	#define DRV_MP4_V1_ENC_PARAM_TYPE_1
	#define DRV_MP4_ENC_MODIFY_SPECIAL_Q_FOR_IFRAME
#elif defined(DRV_MP4_6227_SERIES)
	#define DRV_MP4_V1
	#define DRV_MP4_ENC_MODIFY_SPECIAL_Q_FOR_IFRAME
#elif defined(DRV_MP4_6228_SERIES)
	#define DRV_MP4_V2
	#define DRV_MP4_ENC_MODIFY_SPECIAL_Q_FOR_IFRAME
#elif defined(DRV_MP4_6238_SERIES)	
	#define DRV_MP4_V2
	#define DRV_MP4_V2_ENHANCE
#endif


/**************** USB *******************/
#if defined(DRV_USB_6219_SERIES)
	#define DRV_USB_IP_V1
	#define DRV_USB_MCU_52M
#elif defined(DRV_USB_6227_SERIES)
	#define DRV_USB_IP_V1
#elif defined(DRV_USB_6225_SERIES)
	#define DRV_USB_IP_V1
	#define DRV_USB_IRDBG_V2
#elif defined(DRV_USB_6228_SERIES)
	#define DRV_USB_IP_V2
#elif defined(DRV_USB_6229_SERIES)
	#define DRV_USB_IP_V2
	#define DRV_USB_IRDBG_V1
#elif defined(DRV_USB_6238_SERIES)
	#define DRV_USB_IP_V3
	#define USB_20_ENABLE
#endif


/**************** UPLL *******************/
#if defined(DRV_UPLL_6219_SERIES)
	#define DRV_UPLL_V1
#elif defined(DRV_UPLL_6228_SERIES)
	#define DRV_UPLL_V2
#elif defined(DRV_UPLL_6225_SERIES)
	#define DRV_UPLL_V3
#elif defined(DRV_UPLL_6268_SERIES)
	#define DRV_UPLL_V4
#elif defined(DRV_UPLL_6238_SERIES)
	#define DRV_UPLL_V5
#endif

/**************** ADC ******************/
#if defined(DRV_ADC_6205_SERIES)
   #define DRV_ADC_LIMIT_REG
   #define DRV_ADC_OLD_FUNC
   #define DRV_ADC_NO_IMM
#elif defined(DRV_ADC_6205B_SERIES)
   #define DRV_ADC_BASIC_REG
   #define DRV_ADC_MAX_CH_5
   #define DRV_ADC_FULL_FUNC
   #define DRV_ADC_TDMA_TIME
   #define DRV_ADC_IMM
#elif defined(DRV_ADC_6208_SERIES)
   #define DRV_ADC_LIMIT_REG
   /* for adc_pwrdown_enable() */
   #define DRV_ADC_6208_PWRDOWN
   #define DRV_ADC_NO_IMM
#elif defined(DRV_ADC_6217_SERIES)
   #define DRV_ADC_BASIC_REG
   #define DRV_ADC_MAX_CH_7
   #define DRV_ADC_FULL_FUNC
   #define DRV_ADC_TDMA_TIME
   #define DRV_ADC_IMM
#elif defined(DRV_ADC_6218B_SERIES)
   #define DRV_ADC_BASIC_REG
   #define DRV_ADC_MAX_CH_7
   #define DRV_ADC_FULL_FUNC
   #define DRV_ADC_TDMA_TIME
   #define DRV_ADC_IMM
   #define DRV_AUX_AC_CON_DEF_F
#elif defined(DRV_ADC_6225_SERIES)
   #define DRV_ADC_BASIC_REG
   #define DRV_ADC_TDMA_EVENT_REG_POS1
   #define DRV_ADC_MAX_CH_7
   #define DRV_ADC_FULL_FUNC
   #define DRV_ADC_TDMA_TIME
   #define DRV_ADC_IMM
   #define DRV_AUX_AC_CON_DEF_0
#elif defined(DRV_ADC_6226_SERIES)
   #define DRV_ADC_BASIC_REG
   #define DRV_ADC_TDMA_EVENT_REG_POS1
   #define DRV_ADC_MAX_CH_7
   #define DRV_ADC_FULL_FUNC
   #define DRV_ADC_TDMA_TIME
   #define DRV_ADC_IMM
   #define DRV_AUX_AC_CON_DEF_F
#elif defined(DRV_ADC_6228_SERIES)
   #define DRV_ADC_BASIC_REG
   #define DRV_ADC_MAX_CH_7
   #define DRV_ADC_FULL_FUNC
   #define DRV_ADC_TDMA_TIME
   #define DRV_ADC_IMM
   #define DRV_AUX_AC_CON_DEF_X   
#elif defined(DRV_ADC_6229_SERIES)
   #define DRV_ADC_BASIC_REG
   #define DRV_ADC_TDMA_EVENT_REG_POS2
   #define DRV_ADC_TDMA_EN_REG_POS1
   #define DRV_ADC_MAX_CH_7
   #define DRV_ADC_FULL_FUNC
   #define DRV_ADC_TDMA_TIME
   #define DRV_ADC_IMM
   #define DRV_AUX_AC_CON_DEF_X   
#elif defined(DRV_ADC_6223_SERIES)
   #define DRV_ADC_BASIC_REG
   #define DRV_ADC_TDMA_EVENT_REG_POS2
   #define DRV_ADC_TDMA_EN_REG_POS1
   #define DRV_ADC_MAX_CH_7
   #define DRV_ADC_FULL_FUNC
   #define DRV_ADC_TDMA_TIME
   #define DRV_ADC_IMM
   #define DRV_AUX_AC_CON_DEF_0
#elif defined(DRV_ADC_6238_SERIES)
   #define DRV_ADC_BASIC_REG
   #define DRV_ADC_TDMA_EVENT_REG_POS2
   #define DRV_ADC_TDMA_EN_REG_POS1
   #define DRV_ADC_MAX_CH_7
   #define DRV_ADC_FULL_FUNC
   #define DRV_ADC_TDMA_TIME
   #define DRV_ADC_IMM
   #define DRV_AUX_AC_CON_DEF_0

#ifdef TOUCH_PANEL_INTERNAL
   #define DRV_ADC_TOUCH_SCREEN
   #define DRV_TP_NO_EXT_EINT
   #ifndef TOUCH_PANEL_PRESSURE
   #define TOUCH_PANEL_PRESSURE
   #endif
#endif /* TOUCH_PANEL_INTERNAL */
#endif

/**************** GCU ******************/
#if defined(DRV_GCU_6208_SERIES)
   #define DRV_GCU_REG_16BITS
#elif defined(DRV_GCU_6217_SERIES)
   #define DRV_GCU_REG_32BITS
#elif defined(DRV_GCU_6218B_SERIES)
   #define DRV_GCU_REG_32BITS
   #define DRV_GCU_REV_BIT_DISABLE
#elif defined(DRV_GCU_6225_SERIES)
   #define DRV_GCU_REG_32BITS
   #define DRV_GCU_GEA3
#endif

/**************** GPT ******************/
#if defined(DRV_GPT_6217_SERIES)
   #define DRV_GPT_GPT3
#elif defined(DRV_GPT_6218B_SERIES)
   #define DRV_GPT_GPT3
   #define DRV_GPT_6218B_GPT3_TIMING_DEBUG
#endif

/**************** KBD ******************/
#if defined(DRV_KBD_6205_SERIES)
   #define DRV_KBD_32KEYS_EQ_BELOW
   #define DRV_KBD_25_KEYS
#elif defined(DRV_KBD_6217_SERIES)
   #define DRV_KBD_32KEYS_ABOVE
   #define DRV_KBD_42_KEYS
#elif defined(DRV_KBD_6225_SERIES)
   #define DRV_KBD_32KEYS_ABOVE
   #define DRV_KBD_42_KEYS
   #define DRV_KBD_MUX_WITH_GPIO
#elif defined(DRV_KBD_6218_SERIES)
   #define DRV_KBD_32KEYS_ABOVE
   #define DRV_KBD_36_KEYS
#elif defined(DRV_KBD_6223_SERIES)
   #define DRV_KBD_32KEYS_ABOVE
   #define DRV_KBD_35_KEYS
#elif defined(DRV_KBD_6238_SERIES)
   #define DRV_KBD_64KEYS_ABOVE
   #define DRV_KBD_72_KEYS
   #define DRV_KBD_MUX_WITH_GPIO
#endif

/**************** PWM ******************/
#if defined(DRV_PWM_6205B_SERIES)
   #define DRV_PWM_PWM2
   #define DRV_PWM_CLK_SEL
#elif defined(DRV_PWM_6238_SERIES)
   #define DRV_PWM_RWG
#endif

/**************** RTC ******************/
#if defined(DRV_RTC_6205_SERIES)
   #define DRV_RTC_PWRON_BBPU_POLARITY
   #define DRV_RTC_NO_REG_COMM
   #define DRV_RTC_NO_LATCH_PWR_POLL
   #define DRV_RTC_BBPU_AS_6205
#elif defined(DRV_RTC_6208_SERIES)
   #define DRV_RTC_PWRON_BBPU_POLARITY
   #define DRV_RTC_NO_REG_COMM
   #define DRV_RTC_NO_LATCH_PWR_POLL
   #define DRV_RTC_BBPU_AS_6208
#elif defined(DRV_RTC_6205B_SERIES)
   #define DRV_RTC_REG_COMM
   #define DRV_RTC_CII_HALF_SEC
   #define DRV_RTC_INFO_MASK
   #define DRV_RTC_PWRON_BBPU_SW
   #define DRV_RTC_WRITE_ENABLE
   #define DRV_RTC_LATCH_PWR_POLL
   #define DRV_RTC_BBPU_AS_6205B
#elif defined(DRV_RTC_6217_SERIES)
   #define DRV_RTC_REG_COMM
   #define DRV_RTC_CII_HALF_SEC
   #define DRV_RTC_PWRON_BBPU_SW
   #define DRV_RTC_WRITE_ENABLE
   #define DRV_RTC_INIT_POLL
   #define DRV_RTC_LATCH_PWR_POLL
   #define DRV_RTC_BBPU_AS_6205B
#elif defined(DRV_RTC_6218_SERIES)
   #define DRV_RTC_REG_COMM
   #define DRV_RTC_CII_HALF_SEC
   #define DRV_RTC_PWRON_BBPU_SW
   #define DRV_RTC_LATCH_PWR_POLL
   #define DRV_RTC_BBPU_AS_6218
#elif defined(DRV_RTC_6218B_SERIES)
   #define DRV_RTC_REG_COMM
   #define DRV_RTC_CII_HALF_SEC
   #define DRV_RTC_PWRON_BBPU_SW
   #define DRV_RTC_WRITE_ENABLE
   #define DRV_RTC_INIT_POLL
   #define DRV_RTC_LATCH_PWR_POLL
   #define DRV_RTC_BBPU_AS_6205B
#elif defined(DRV_RTC_6226_SERIES)
   #define DRV_RTC_REG_COMM
   #define DRV_RTC_CII_HALF_SEC
   #define DRV_RTC_W_FLAG
   #define DRV_RTC_PWRON_BBPU_SW
   #define DRV_RTC_WRITE_ENABLE
   #define DRV_RTC_TC_BUSY_CHECK
   #define DRV_RTC_INIT_POLL
   #define DRV_RTC_LATCH_PWR_POLL
   #define DRV_RTC_COMM_REG1_SECURITY
   #define DRV_RTC_BBPU_AS_6205B
#elif defined(DRV_RTC_6228_SERIES)
   #define DRV_RTC_REG_COMM
   #define DRV_RTC_CII_HALF_SEC
   #define DRV_RTC_W_FLAG
   #define DRV_RTC_PWRON_BBPU_SW
   #define DRV_RTC_WRITE_ENABLE
   #define DRV_RTC_TC_BUSY_CHECK
   #define DRV_RTC_POWERKEY_BUSY_CHECK
   #define DRV_RTC_INIT_POLL
   #define DRV_RTC_LATCH_PWR_POLL
   #define DRV_RTC_BBPU_AS_6205B
   #define DRV_RTC_XOSC_DEF_8
#elif defined(DRV_RTC_6238_SERIES)
   #define DRV_RTC_REG_COMM
   #define DRV_RTC_CII_HALF_SEC
   #define DRV_RTC_PWRON_BBPU_SW
   #define DRV_RTC_WRITE_ENABLE
   #define DRV_RTC_INIT_POLL
   #define DRV_RTC_LATCH_PWR_POLL
   #define DRV_RTC_BBPU_AS_6238
   #define DRV_RTC_XOSC_DEF_8
   #define DRV_RTC_HW_CALI
#endif

/**************** WDT ******************/
#if defined(DRV_WDT_6205_SERIES)
   #define DRV_WDT_LIMIT_REG
   #define DRV_WDT_RESET_PKEY_RELEASE
   #define DRV_WDT_6205_CHECK_STAT
#elif defined(DRV_WDT_6205B_SERIES)
   #define DRV_WDT_LIMIT_REG
#elif defined(DRV_WDT_6208_SERIES)
   #define DRV_WDT_LIMIT_REG
   #define DRV_WDT_RESET_PKEY_RELEASE
#elif defined(DRV_WDT_6217_SERIES)
   #define DRV_WDT_BASIC_REG
   #define DRV_WDT_LENGTH_11BITS
   #define DRV_WDT_SWRST
#endif

/**************** UART ******************/
#if defined(DRV_UART_6205_SERIES)
   #define DRV_UART_6205_REG
   #define DRV_UART2_OLD_DMA
   #define DRV_UART_2_FIFO_DEPTHS
#elif defined(DRV_UART_6205B_SERIES)
   #define DRV_UART_6205B_REG
   #define DRV_UART2_OLD_DMA
   #define DRV_UART_NO_AUTOESCAPE
   #define DRV_UART_SLEEP_NO_FC
   #define DRV_UART_HIGH_SPEED
   #define DRV_UART_2_FIFO_DEPTHS
#elif defined(DRV_UART_6208_SERIES)
   #define DRV_UART_6208_REG
   #define DRV_UART_NO_AUTOESCAPE
   #define DRV_UART_6208_FC_SETTING
   #define DRV_UART_SLEEP_NO_FC
   #define DRV_UART2_NO_DMA
   #define DRV_UART_1_FIFO_DEPTH
#elif defined(DRV_UART_6217_SERIES)
   #define DRV_UART_BASIC_REG
   #define DRV_UART_VFIFO_EN_REG
   #define DRV_UART2_NORMAL_DMA
   #define DRV_UART_HIGH_SPEED
   #define DRV_UART_AUTO_BAUD
   #define DRV_UART_NO_UART3_PDN
   #define DRV_UART_SLEEP_MODE
   #define DRV_UART_DMA_VFIFO_CONFIG1
   #define DRV_UART_2_FIFO_DEPTHS
#elif defined(DRV_UART_6218_SERIES)
   #define DRV_UART_BASIC_REG
   #define DRV_UART2_NORMAL_DMA
   #define DRV_UART_HIGH_SPEED
   #define DRV_UART_AUTO_BAUD
   #define DRV_UART_6218_TX_DMA
   #define DRV_UART_2_FIFO_DEPTHS
#elif defined(DRV_UART_6218B_SERIES)
   #define DRV_UART_BASIC_REG
   #define DRV_UART_VFIFO_EN_REG
   #define DRV_UART2_NORMAL_DMA
   #define DRV_UART_6218B_AUTOESCAPE
   #define DRV_UART_HIGH_SPEED
   #define DRV_UART_AUTO_BAUD
   #define DRV_UART_NO_UART3_PDN
   #define DRV_UART_SLEEP_MODE
   #define DRV_UART_DMA_VFIFO_CONFIG1
   #define DRV_UART_2_FIFO_DEPTHS
#elif defined(DRV_UART_6219_SERIES)
   #define DRV_UART_BASIC_REG
   #define DRV_UART_VFIFO_EN_REG
   #define DRV_UART2_NORMAL_DMA
   #define DRV_UART_6219_AUTOESCAPE
   #define DRV_UART_HIGH_SPEED
   #define DRV_UART_AUTO_BAUD
   #define DRV_UART_SLEEP_MODE
   #define DRV_UART_DMA_VFIFO_CONFIG2
   #define DRV_UART_2_FIFO_DEPTHS
#elif defined(DRV_UART_6227_SERIES)
   #define DRV_UART_BASIC_REG
   #define DRV_UART_VFIFO_EN_REG
   #define DRV_UART2_NORMAL_DMA
   #define DRV_UART_HIGH_SPEED
   #define DRV_UART_AUTO_BAUD
   #define DRV_UART_SLEEP_MODE
   #define DRV_UART_DMA_VFIFO_CONFIG2
   #define DRV_UART_2_FIFO_DEPTHS
#elif defined(DRV_UART_6225_SERIES)
   #define DRV_UART_BASIC_REG
   #define DRV_UART_VFIFO_EN_REG
   #define DRV_UART2_NORMAL_DMA
   #define DRV_UART_HIGH_SPEED
   #define DRV_UART_AUTO_BAUD
   #define DRV_UART_SLEEP_MODE
   #define DRV_UART_DMA_VFIFO_CONFIG2
   #define DRV_UART_SPEED_SAMPLE_COUNT
   #define DRV_UART_2_FIFO_DEPTHS
#endif

/**************** IRDA ******************/
#if defined(DRV_IRDA_6218B_SERIES)
   #define DRV_IRDA_CRC_DETECT_6218B
#elif defined(DRV_IRDA_6219_SERIES)
   #define DRV_IRDA_CRC_DETECT_6219
   #define DRV_IRDA_PDN
#elif defined(DRV_IRDA_6225_SERIES)
   #define DRV_IRDA_PDN
#elif defined(DRV_IRDA_6228_SERIES)
   #define DRV_IRDA_MODE_SUPPORT
   #define DRV_IRDA_FRAME_ERR_CHECK   
   #define DRV_IRDA_PDN
#endif

/**************** GPIO ******************/
#if defined(DRV_GPIO_6205_SERIES)
   #define DRV_GPIO_REG_AS_6205
   #define DRV_GPIO_6205_FUNC
#elif defined(DRV_GPIO_6205B_SERIES)
   #define DRV_GPIO_REG_AS_6205B
   #define DRV_GPIO_6205B_FUNC
#elif defined(DRV_GPIO_6208_SERIES)
   #define DRV_GPIO_REG_AS_6208
   #define DRV_GPIO_6208_FUNC
#elif defined(DRV_GPIO_6218_SERIES)
   #define DRV_GPIO_REG_AS_6218
   #define DRV_GPIO_FULL_FUNC
   #define DRV_GPIO_DIN_DISCONT
#elif defined(DRV_GPIO_6218B_SERIES)
   #define DRV_GPIO_REG_AS_6218B
   #define DRV_GPIO_FULL_FUNC
   #define DRV_GPIO_DIN_DISCONT
#elif defined(DRV_GPIO_6219_SERIES)
   #define DRV_GPIO_REG_AS_6219
   #define DRV_GPIO_FULL_FUNC
   #define DRV_GPIO_DIN_DISCONT
#elif defined(DRV_GPIO_6225_SERIES)
   #define DRV_GPIO_REG_AS_6225
   #define DRV_GPIO_FULL_FUNC
   #define DRV_GPIO_DIN_DISCONT
#elif defined(DRV_GPIO_6227_SERIES)
   #define DRV_GPIO_REG_AS_6227
   #define DRV_GPIO_FULL_FUNC
   #define DRV_GPIO_DIN_CONTI
   #define DRV_GPIO_MODE8_SPECIAL_POS
#elif defined(DRV_GPIO_6228_SERIES)
   #define DRV_GPIO_REG_AS_6228
   #define DRV_GPIO_FULL_FUNC
   #define DRV_GPIO_DIN_CONTI
#elif defined(DRV_GPIO_6223_SERIES)
   #define DRV_GPIO_REG_AS_6223
   #define DRV_GPIO_FULL_FUNC
   #define DRV_GPIO_DIN_DISCONT
   #define DRV_GPIO_WO_GPO
   #define DRV_GPIO_DEBUG_MODE
   #define DRV_GPIO_CLK_OUT
#elif defined(DRV_GPIO_6238_SERIES)
   #define DRV_GPIO_REG_AS_6238
   #define DRV_GPIO_FULL_FUNC
   #define DRV_GPIO_DIN_CONTI
   #define DRV_GPIO_WO_GPO
   #define DRV_GPIO_CLK_OUT
   #define DRV_GPIO_PULL_SEL
#endif

/**************** MISC ******************/
#if defined(DRV_MISC_6205_SERIES)
   #define DRV_MISC_CHR_CTRL_GPIO
   #define DRV_MISC_TDMA_32K_CALI
   #define DRV_MISC_PDN_NO_SET_CLR
   #define DRV_MISC_TDMA_TIME_MAX_24BITS
   #define DRV_MISC_TDMA_TIME_BASE_8020
#elif defined(DRV_MISC_6208_SERIES)
   #define DRV_MISC_PDN_NO_SET_CLR
   #define DRV_MISC_TDMA_TIME_MAX_24BITS
   #define DRV_MISC_TDMA_TIME_BASE_8020
#elif defined(DRV_MISC_6205B_SERIES)
   #define DRV_MISC_DMA_NO_MEMCPY
   #define DRV_MISC_CHR_CTRL_GPIO
   #define DRV_MISC_TDMA_32K_CALI
   #define DRV_MISC_TDMA_NO_TIME
   #define DRV_MISC_LOW_COST_PROJ
#elif defined(DRV_MISC_6217_SERIES)
   #define DRV_MISC_DMA_MEMCPY
   #define DRV_MISC_CHR_CTRL_GPIO
   #define DRV_MISC_TDMA_32K_CALI
   #define DRV_MISC_TDMA_TIME_BASE_8020
   #define DRV_MISC_TDMA_TIME_MAX_24BITS
#elif defined(DRV_MISC_6218B_SERIES)
   #define DRV_MISC_DMA_MEMCPY
   #define DRV_MISC_CHR_CTRL_GPIO
   #define DRV_MISC_TDMA_32K_CALI
   #define DRV_MISC_TDMA_NO_TIME
#elif defined(DRV_MISC_6219_SERIES)
   #define DRV_MISC_DMA_MEMCPY
   #define DRV_MISC_CHR_CTRL_GPIO
   #define DRV_MISC_TDMA_32K_CALI
   #define DRV_MISC_TDMA_TIME_MAX_19BITS
   #define DRV_MISC_TDMA_TIME_BASE_8020
#elif defined(DRV_MISC_6238_SERIES)
   #define DRV_MISC_DMA_MEMCPY
   #define DRV_MISC_CHR_CTRL_GPIO
   #define DRV_MISC_TDMA_32K_CALI
   #define DRV_MISC_TDMA_TIME_MAX_24BITS
   #define DRV_MISC_TDMA_TIME_BASE_8200
#endif

/*MSDC*/
#if defined(DRV_MSDC_LSD)
   #define DRV_LSD
#endif

#ifdef DRV_MSDC_INSWP_MT6219_SERIES
   #ifdef MT6225
   #define DRV_MSDC_INSWP_GPIO_MT6225_SERIES
   #endif
#endif

/************************************************************************************
   DEPENDENCY CHECK
************************************************************************************/
/* Features for ADC */
#if defined(DRV_ADC_OLD_FUNC) && defined(DRV_ADC_FULL_FUNC)
#error "ADC feature conflict!!"
#endif
#if defined(DRV_ADC_LIMIT_REG) && defined(DRV_ADC_BASIC_REG)
#error "ADC register conflict!!"
#endif
#if defined(DRV_ADC_MAX_CH_5) && defined(DRV_ADC_MAX_CH_7)
#error "ADC feature conflict!!"
#endif
#if defined(DRV_ADC_NO_IMM) && defined(DRV_ADC_IMM)
#error "ADC feature conflict!!"
#endif

/* Features for GCU*/   
#if defined(DRV_GCU_REG_32BITS) && defined(DRV_GCU_REG_16BITS)
#error "GCU feature conflict!!"
#endif

/* Features for KBD */   
#if defined(DRV_KBD_32KEYS_ABOVE) && defined(DRV_KBD_32KEYS_EQ_BELOW)
#error "KBD feature conflict!!"
#endif
#if defined(DRV_KBD_42_KEYS) && (defined(DRV_KBD_36_KEYS) || defined(DRV_KBD_25_KEYS))
#error "KBD feature conflict!!"
#endif
#if defined(DRV_KBD_36_KEYS) && defined(DRV_KBD_25_KEYS)
#error "KBD feature conflict!!"
#endif

/* Features for WDT */
#if defined(DRV_WDT_BASIC_REG) && defined(DRV_WDT_LIMIT_REG)
#error "WDT feature conflict!!"
#endif

/* Features for UART */
#if defined(DRV_UART2_NORMAL_DMA)
   #if defined(DRV_UART2_OLD_DMA)
   #error "UART feature conflict!!"
   #endif
   #if defined(DRV_UART2_NO_DMA)
   #error "UART feature conflict!!"
   #endif
#elif defined(DRV_UART2_OLD_DMA)
   #if defined(DRV_UART2_NO_DMA)
   #error "UART feature conflict!!"
   #endif
#endif

#if defined(__DMA_UART_VIRTUAL_FIFO__)
   #if !defined(DRV_UART_VFIFO_EN_REG)
   #error "UART feature conflict!!"
   #endif
#endif

/* Features for IrDA */
#if defined(__IRDA_FIR_SUPPORT__) || defined(__IRDA_MIR_SUPPORT__)
   #if !defined(DRV_IRDA_MODE_SUPPORT)
   #error "IrDA feature conflict!!"
   #endif
#endif

/*ALL*/
#if (defined(__SW_JPEG_CODEC_SUPPORT__) && (defined(DRV_JPG_DATA_PATH_17_SERIES)|| defined(DRV_JPG_DATA_PATH_19_SERIES)||defined(DRV_JPG_DATA_PATH_28_SERIES)))
   #error "__SW_JPEG_CODEC_SUPPORT__ conflit with image data path setting!!"
#endif

#endif   /*End __DRV_FEATURES_OPTION_H__*/
