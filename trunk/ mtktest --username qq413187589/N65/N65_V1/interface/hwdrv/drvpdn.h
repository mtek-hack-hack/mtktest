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
 *    drvpdn.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the power down management header file
 *
 * Author:
 * -------
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
#ifndef __DRVPDN_H__
#define __DRVPDN_H__

#if ( (!defined(MT6205)) && (!defined(MT6205B)) && (!defined(MT6208)) )

#define __NEW_DRVPDN_FUNCTION__

#endif   /*MT6205, MT6205B, MT6208*/

/*******************************************************************************
 * Constant definition
 *******************************************************************************/
#define DRVPDN_CON0              (CONFIG_base+0x0300)
#define DRVPDN_CON1              (CONFIG_base+0x0304)
#define DRVPDN_CON2              (CONFIG_base+0x0308)
#define DRVPDN_CON3              (CONFIG_base+0x030c)

#define DRVPDN_CON0_SET          (CONFIG_base+0x0310)
#define DRVPDN_CON1_SET          (CONFIG_base+0x0314)
#define DRVPDN_CON2_SET          (CONFIG_base+0x0318)
#define DRVPDN_CON3_SET          (CONFIG_base+0x031c)
#define DRVPDN_CON0_CLR          (CONFIG_base+0x0320)
#define DRVPDN_CON1_CLR          (CONFIG_base+0x0324)
#define DRVPDN_CON2_CLR          (CONFIG_base+0x0328)
#define DRVPDN_CON3_CLR          (CONFIG_base+0x032c)

#ifdef MT6208

#define DRVPDN_CON0_DMA           0x0001
#define DRVPDN_CON0_USB           0x0002
#define DRVPDN_CON0_GCU           0x0004
#define DRVPDN_CON0_XSOC          0x1000
#define DRVPDN_CON0_DPLL          0x2000
#define DRVPDN_CON0_MPLL          0x4000
#define DRVPDN_CON0_DIV2          0x8000

#elif defined(MT6205) || defined(MT6205B) || defined(FPGA)  /* MT6208 */

#define DRVPDN_CON0_DMA           0x0001
#define DRVPDN_CON0_GCU           0x0004
#define DRVPDN_CON0_CLKSQ         0x0800
#define DRVPDN_CON0_MPLL_DIV2     0x1000
#define DRVPDN_CON0_DPLL          0x2000
#define DRVPDN_CON0_DSP_DIV2      0x8000

#elif defined(MT6223) || defined(MT6223P)

#define DRVPDN_CON0_DMA           0x0001
#define DRVPDN_CON0_GCU           0x0004
#define DRVPDN_CON0_WAVETABLE     0x0008
#define DRVPDN_CON0_IRDMA         0x0040
#define DRVPDN_CON0_CLKSQ         0x0800
#define DRVPDN_CON0_MPLL_DIV2     0x1000
#define DRVPDN_CON0_PLL           0x2000
#define DRVPDN_CON0_DSP_DIV2      0x8000

#elif defined(MT6218) || defined(MT6218B) || defined(MT6219) || defined(MT6217) || defined(MT6226) || defined(MT6227) || defined(MT6226M) || defined(MT6227D) || defined(MT6226D) /* MT6208 */

#define DRVPDN_CON0_DMA           0x0001
#define DRVPDN_CON0_USB           0x0002
#define DRVPDN_CON0_GCU           0x0004
#define DRVPDN_CON0_WAVETABLE     0x0008

#if (defined(MT6218B)) || (defined(MT6217))
#define DRVPDN_CON0_JPEG          0x0010
#define DRVPDN_CON0_RESZ          0x0020
#endif  /* MT6218B || MT6217 */

#define DRVPDN_CON0_UPLL          0x0400
#define DRVPDN_CON0_CLKSQ         0x0800
#define DRVPDN_CON0_MCU_DIV2      0x1000
#define DRVPDN_CON0_DPLL          0x2000
#define DRVPDN_CON0_MPLL          0x4000
#define DRVPDN_CON0_DSP_DIV2      0x8000

#elif defined(MT6228) || defined(MT6229) || defined(MT6230)

#define DRVPDN_CON0_DMA           0x0001
#define DRVPDN_CON0_USB           0x0002
#define DRVPDN_CON0_GCU           0x0004
#define DRVPDN_CON0_WAVETABLE     0x0008
#define DRVPDN_CON0_CHE           0x0010
#define DRVPDN_CON0_PFC           0x0020
#define DRVPDN_CON0_TPLL          0x0200
#define DRVPDN_CON0_UPLL          0x0400
#define DRVPDN_CON0_CLKSQ         0x0800
#define DRVPDN_CON0_MCU_DIV2      0x1000
#define DRVPDN_CON0_PLL           0x4000

#elif defined(MT6238)

#define DRVPDN_CON0_DMA           	0x0001
#define DRVPDN_CON0_USB           		0x0002
#define DRVPDN_CON0_GCU           	0x0004
#define DRVPDN_CON0_WAVETABLE     	0x0008
#define DRVPDN_CON0_CHE           	0x0010

#define DRVPDN_CON0_IR           		0x0040
#define DRVPDN_CON0_PWM3        		0x0080
#define DRVPDN_CON0_PWM          	0x0100
#define DRVPDN_CON0_MSDC2         	0x0200
#define DRVPDN_CON0_SIM2		      	0x0400
#define DRVPDN_CON0_H264         		0x0800
#define DRVPDN_CON0_IRDBG1      		0x1000
#define DRVPDN_CON0_IRDBG2      		0x2000

#elif defined(MT6225)

#define DRVPDN_CON0_DMA           0x0001
#define DRVPDN_CON0_USB           0x0002
#define DRVPDN_CON0_GCU           0x0004
#define DRVPDN_CON0_WAVETABLE     0x0008
#define DRVPDN_CON0_IRDBG         0x0400
#define DRVPDN_CON0_CLKSQ         0x0800
#define DRVPDN_CON0_MCU_DIV2      0x1000
#define DRVPDN_CON0_PLL           0x2000
#define DRVPDN_CON0_DSP_DIV2      0x8000

#endif  /* MT6208 */

#define DRVPDN_CON1_GPT           0x0001
#define DRVPDN_CON1_KP            0x0002
#define DRVPDN_CON1_GPIO          0x0004
#define DRVPDN_CON1_UART1         0x0008
#define DRVPDN_CON1_SIM           0x0010
#define DRVPDN_CON1_PWM           0x0020
#define DRVPDN_CON1_ALTER         0x0040
#define DRVPDN_CON1_LCD           0x0080
#define DRVPDN_CON1_UART2         0x0100

#ifdef MT6205B

#define DRVPDN_CON1_PWM2          0x0400

#elif defined(MT6223) || defined(MT6223P)

#define DRVPDN_CON1_PWM2          0x0400
#define DRVPDN_CON1_SWDBG         0x0800
#define DRVPDN_CON1_UART3         0x4000

#elif defined(MT6218) || defined(MT6218B)  || defined(MT6219) || defined(MT6217) || defined(MT6226) || defined(MT6227) || defined(MT6226M) || defined(MT6227D)  || defined(MT6226D)  /* MT6205B */

#define DRVPDN_CON1_MSDC          0x0200
#define DRVPDN_CON1_PWM2          0x0400
#define DRVPDN_CON1_TRC           0x0800

#if defined(MT6218B)|| defined(MT6219) || defined(MT6217) || defined(MT6226) || defined(MT6227) || defined(MT6226M) || defined(MT6227D) || defined(MT6226D)

#define DRVPDN_CON1_NFI           0x1000
#define DRVPDN_CON1_B2SPI         0x2000

#if defined(MT6219) || defined(MT6226) || defined(MT6227) || defined(MT6226M) || defined(MT6227D) || defined(MT6226D)
#define DRVPDN_CON1_UART3         0x4000
#define DRVPDN_CON1_IRDA          0x8000
#endif 	/* MT6219 || MT6226 || MT6227 || MT6226M  || defined(MT6227D)*/

#endif  /* MT6218B || MT6219 || MT6217 || MT6226 || MT6227 || MT6226M  || defined(MT6227D) || defined(MT6226D) || defined(MT6226D)*/

#elif defined(MT6228) || defined(MT6229)  || defined(MT6230)   /* MT6205B */

#define DRVPDN_CON1_MSDC          0x0200
#define DRVPDN_CON1_TRC           0x0400
#define DRVPDN_CON1_PWM2          0x0800
#define DRVPDN_CON1_NFI           0x1000
#define DRVPDN_CON1_B2SPI         0x2000
#define DRVPDN_CON1_UART3         0x4000
#define DRVPDN_CON1_IRDA          0x8000

#elif defined(MT6238)

#define DRVPDN_CON1_PWM1        	0x0020
#define DRVPDN_CON1_MSDC         0x0200
#define DRVPDN_CON1_TRC           	0x0400
#define DRVPDN_CON1_PWM2        	0x0800
#define DRVPDN_CON1_NFI           	0x1000
#define DRVPDN_CON1_SPI        	0x2000	
#define DRVPDN_CON1_UART3         0x4000
#define DRVPDN_CON1_IRDA          0x8000

#elif defined(MT6225)   /* MT6205B */

#define DRVPDN_CON1_MSDC          0x0200
#define DRVPDN_CON1_PWM2          0x0400
#define DRVPDN_CON1_NFI           0x1000
#define DRVPDN_CON1_B2SPI         0x2000
#define DRVPDN_CON1_UART3         0x4000
#define DRVPDN_CON1_IRDA          0x8000

#endif  /* MT6205B */

#define DRVPDN_CON2_TDMA          0x0001
#define DRVPDN_CON2_RTC           0x0002
#define DRVPDN_CON2_BSI           0x0004
#define DRVPDN_CON2_BPI           0x0008
#define DRVPDN_CON2_AFC           0x0010
#define DRVPDN_CON2_APC           0x0020
#define DRVPDN_CON2_FCS           0x0040
#define DRVPDN_CON2_AUXADC        0x0080
#define DRVPDN_CON2_AFE           0x0100
#define DRVPDN_CON2_BFE           0x0200
#define DRVPDN_CON2_GCC           0x0400
#define DRVPDN_CON2_DIV           0x0800
#define DRVPDN_CON2_AAFE          0x1000
#define DRVPDN_CON2_SCCB          0x2000
#define DRVPDN_CON2_BBRX          0x4000
#define DRVPDN_CON2_GMSK          0x8000


#if defined(MT6228) || defined(MT6229) || defined(MT6230)

#define DRVPDN_CON3_ICE           0x0001
#define DRVPDN_CON3_RESZLB        0x0002
#define DRVPDN_CON3_CRZ           0x0004
#define DRVPDN_CON3_TV            0x0008
#define DRVPDN_CON3_IMGPROC       0x0010
#define DRVPDN_CON3_PNG           0x0020
#define DRVPDN_CON3_GIF           0x0040
#define DRVPDN_CON3_GCMQ          0x0080
#define DRVPDN_CON3_G2D           0x0100
#define DRVPDN_CON3_MP4           0x0200
#define DRVPDN_CON3_JPEG          0x0400
#define DRVPDN_CON3_PRZ           0x0800
#define DRVPDN_CON3_ISP           0x1000
#define DRVPDN_CON3_DCT           0x2000
#define DRVPDN_CON3_IMGDMA        0x4000
#define DRVPDN_CON3_DRZ           0x8000

#elif defined(MT6238)

#define DRVPDN_CON3_ICE           0x0001
#define DRVPDN_CON3_RESZLB        0x0002
#define DRVPDN_CON3_CRZ           0x0004
#define DRVPDN_CON3_TV            0x0008
#define DRVPDN_CON3_IMGPROC       0x0010
#define DRVPDN_CON3_PNG           0x0020
#define DRVPDN_CON3_GIF           0x0040
#define DRVPDN_CON3_GCMQ          0x0080
#define DRVPDN_CON3_G2D           0x0100
#define DRVPDN_CON3_MP4           0x0200
#define DRVPDN_CON3_JPEG          0x0400
#define DRVPDN_CON3_PRZ           0x0800
#define DRVPDN_CON3_ISP           0x1000
#define DRVPDN_CON3_DCT           0x2000
#define DRVPDN_CON3_IMGDMA        0x4000
#define DRVPDN_CON3_DRZ           0x8000

#elif defined(MT6225)   /* MT6228 || MT6229 */

#define DRVPDN_CON3_ICE           0x0001
#define DRVPDN_CON3_RESZ          0x0800
#define DRVPDN_CON3_ISP           0x1000

#elif defined(MT6223)  || defined(MT6223P)  /* MT6228 || MT6229 */

#define DRVPDN_CON3_ICE           0x0001
#define DRVPDN_CON1_TRC           0x0800

#else   /* MT6228 || MT6229 */

#define DRVPDN_CON3_ICE           0x0001
#define DRVPDN_CON3_IMGPROC       0x0010
#define DRVPDN_CON3_GIF           0x0040
#define DRVPDN_CON3_GCMQ          0x0080
#define DRVPDN_CON3_G2D           0x0100
#define DRVPDN_CON3_MP4           0x0200
#define DRVPDN_CON3_JPEG          0x0400
#define DRVPDN_CON3_RESZ          0x0800
#define DRVPDN_CON3_ISP           0x1000
#define DRVPDN_CON3_DCT           0x2000
#define DRVPDN_CON3_IMGDMA        0x4000

#endif  /* MT6228 || MT6229 */


/*===================================*/
#if defined(MT6205B)
typedef enum {
   PDN_UART1 = 0,
   PDN_UART2,
   PDN_ALTER,
   PDN_GCU,
   PDN_DMA,
   PDN_SIM,
   PDN_ADC,
   PDN_GPT,
   PDN_PWM,
   PDN_PWM2,
   PDN_MAX_DEV
} PDN_DEVICE;
#else
typedef enum {
   PDN_UART1 = 0,
   PDN_UART2,
   PDN_ALTER,
   PDN_GCU,
   PDN_DMA,
   PDN_SIM,
   PDN_ADC,
   PDN_GPT,
   PDN_PWM,
   PDN_PWM2,
   PDN_USB,
   PDN_UART3,   
   PDN_MSDC,
   PDN_NFI,
   PDN_B2PSI,
   PDN_IMGPROC,
   PDN_IMGDMA,
   PDN_GIF,
   PDN_RESZ,
   PDN_IRDA,
   PDN_TRC,
   PDN_PFC,
   PDN_PNG,
   PDN_MSDC2,
   PDN_MAX_DEV
} PDN_DEVICE;
#endif

typedef struct
{
   kal_uint32 addr;
   kal_uint16 code;
} PDN_INPUT;
/*******************************************************************************
 * Function declaration
 *******************************************************************************/
extern kal_uint8 L1SM_GetHandle(void);
extern void L1SM_SleepDisable(kal_uint8);
extern void L1SM_SleepEnable(kal_uint8);
extern void L1SM_UnIRQSleepDisable(kal_uint8 handle);
extern void L1SM_UnIRQSleepEnable(kal_uint8 handle);
extern void DRVPDN_Enable(kal_uint32 addr,kal_uint16 code,kal_uint8 handle);
extern void DRVPDN_Disable(kal_uint32 addr,kal_uint16 code,kal_uint8 hanlde);

#endif /* __DRVPDN_H__ */

