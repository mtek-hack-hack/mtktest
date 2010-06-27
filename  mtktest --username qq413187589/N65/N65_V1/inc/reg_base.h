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
 *   reg_base.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Definition for chipset register base and global configuration registers
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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

#ifndef _REG_BASE_H
#define _REG_BASE_H

#define   UINT16P             unsigned short *
#define   UINT32P             unsigned int   *

/*******************************************************************************
 *                          MCU/DSP Sherif
 *******************************************************************************/
#if defined(MT6238)
#define DPRAM_CPU_base           (0xA0000000)
#define DPRAM2_CPU_base          (0xA1000000)
#else
#define DPRAM_CPU_base           (0x50000000)
#endif	// #if defined(MT6238)

/*******************************************************************************
 *                          MCU Subsystem
 *******************************************************************************/
/* APB Memory Map */

/* APB Bus 0 */
#if defined(MT6238)

/* SHK: APB Bus 0. */

#define EFUSE_base             	    (0x80000000)   /* Config registers  (Clk, Power Down, Ver) */
#define CONFIG_base            	    (0x80010000)   /* Config registers  (Clk, Power Down, Ver) */
#define GPIO_base                	(0x80020000)   /* GPIO */
#define RGU_base                 	(0x80030000)   /* Reset Generation Unit */


/* SHK: APB Bus 1. */

#define EMI_base                 	(0x81000000)   /* EMI registers */
#define CIRQ_base                	(0x81010000)   /* IRQ Controller */
#define DMA_base                 	(0x81020000)   /* DMA Controller */
#define UART1_base               	(0x81030000)   /* UART / SIR IrDA */
#define UART2_base               	(0x81040000)   /* UART / SIR IrDA */
#define UART3_base               	(0x81050000)   /* UART / SIR IrDA */
#define GPT_base                 	(0x81060000)   /* General Purpose Timer */
#define ALERTER_base                (0x81070000)   /* Audio Alerter */
#define KP_base                  	(0x81080000)   /* Keypad Scanner */
#define PWM_base                 	(0x81090000)   /* Pulse Width Modulator */
#define SIM_base                 	(0x810A0000)   /* SIM Card interface */
#define L2C_base                 	(0x810B0000)   /* Data cache controller */
#define RTC_base                 	(0x810C0000)   /* Real Time Clock unit */
#define CHE_base                 	(0x810D0000)   /* Cipher Hash Engine */
#define PFC_base                 	(0x810E0000)   /* PPP Framer */
#define IRDA_base                	(0x810F0000)   /* IrDA */
#define I2C_base                	(0x81100000)   /* Serial Camera Control Bus */
#define MSDC_base                	(0x81110000)   /* MSDC */
#define NFI_base                 	(0x81120000)   /* NAND Flash Interface */
#define SIM2_base                 	(0x81130000)   /* SIM2 Interface */
#define MSDC2_base              	(0x81140000)   /* MSDC2 Controller. */


/* SHK: APB Bus 2. */

#define TDMA_base                	(0x82000000)   /* TDMA Timer */
#define BSI_base                 	(0x82010000)   /* Baseband Serial Interface */
#define BPI_base                 	(0x82020000)   /* Baseband Parallel Interface */
#define AFC_base                 	(0x82030000)   /* AFC */
#define APC_base                 	(0x82040000)   /* TX Power Control */
#define AUXADC_base                 (0x82050000)   /* Auxiliary ADC */
#define DIVIDER_base                (0x82060000)   /* Divider */
#define FCS_base                 	(0x82070000)   /* FCS Unit */
#define GCU_base                 	(0x82080000)   /* GPRS Crypto Unit */
#define CSD_ACC_base           	    (0x82090000)   /* CSD_ACC */
#define SHARE_base               	(0x820A0000)   /* DSP to CPU interrupt control (shared register) */
#define IRDBG_base               	(0x820B0000)   /* IRDBG */
#define SHARE2_base             	(0x820C0000)   /* DSP2 to CPU interrupt control (shared register) */
#define IRDBG2_base                 (0x820D0000)   /* IRDBG */
#define PATCH_base               	(0x820E0000)   /* DSP to CPU interrupt control (shared register) */
#define AFE_base                 	(0x820F0000)   /* Audio interface */
#define BFE_base                	(0x82100000)   /* Base-band Front End */


/* SHK: APB Bus '5'. */

#define PLL_base                 	(0x83000000)   /* PLL Configuration. */
#define MIXED_base               	(0x83010000)   /* Analog Chip Interface Controller */
#define TVDAC_base               	(0x83020000)   /* TVDAC */


/* SHK: APB Bus 6. */

#define GMC_base                 	(0x84000000)   /* Graphics Memory Controller */
#define G2D_base                 	(0x84010000)   /* 2D Accelerator */
#define GCMQ_base                	(0x84020000)   /* 2D Command Queue */
#define GIFDEC_base              	(0x84030000)   /* GIF Decoder */
#define IMGDMA_base                 (0x84040000)   /* Image DMA */
#define PNGDEC_base             	(0x84050000)   /* PNG Decoder */
#define MP4_base                 	(0x84060000)   /* MPEG4 Codec */
#define MP4_DEBLK_base              (0x84070000)   /* MPEG4 Codec */
#define JPEG_CODEC_base             (0x84080000)   /* JPEG Decoder */
#define TVCON_base               	(0x84090000)   /* TV Controller */
#define TVENC_base               	(0x840A0000)   /* TC Encoder */
#define CAMERA_base                 (0x840B0000)   /* Camera Interface */
#define IMGPROC_base                (0x840C0000)   /* Image Engine */
#define PRZ_base                 	(0x840D0000)   /* Post Processing Resizer */
#define CRZ_base                 	(0x840E0000)   /* Capture Resizer */
#define DRZ_base                 	(0x840F0000)   /* Drop Resizer */
#define H264_base                 	(0x84100000)   /* H.264  */
#define SPI_base                 	(0x84110000)   /* SPI  */


#define LCD_base                    (0x90000000)   /* LCD */


#else	// #if defined(MT6238)

#define CONFIG_base              (0x80000000)   /* Config registers  (Clk, Power Down, Ver) */
#define EMI_base                 (0x80010000)   /* EMI registers */
#define CIRQ_base                (0x80020000)   /* IRQ Controller */
#define DMA_base                 (0x80030000)   /* DMA Controller */
#define RGU_base                 (0x80040000)   /* Reset Generation Unit */

#if ( defined(MT6228) || defined(MT6229) || defined(MT6230) )
#define L2C_base                 (0x80050000)   /* Data cache controller */
#elif !defined(MT6225)   /* MT6228 || MT6229 || MT6230 */
#define DEBUG_base               (0x80050000)   /* Debug registers */
#endif /* MT6228 || MT6229 || MT6230 */

#define GCU_base                 (0x80060000)   /* GPRS Crypto Unit */

#if ( defined(MT6228) || defined(MT6229) || defined(MT6230) )
#define SWDBG_base               (0x80070000)   /* Software Debug */
#elif defined(MT6225) || defined(MT6223) || defined(MT6223P)
#define I2C_base                 (0x80070000)   /* I2C */
#endif /* MT6228 */

#if defined(MT6223) || defined(MT6223P)
#define SWDBG_base               (0x80090000)   /* Software Debug */
#else
#define NFI_base                 (0x80090000)   /* NAND Flash Interface */
#endif

#if !defined(MT6225)
#define SCCB_base                (0x800a0000)   /* Serial Camera Control Bus */
#endif  /* !MT6225 */

#define GPT_base                 (0x80100000)   /* General Purpose Timer */
#define KP_base                  (0x80110000)   /* Keypad Scanner */
#define GPIO_base                (0x80120000)   /* GPIO */
#define UART1_base               (0x80130000)   /* UART / SIR IrDA */
#define SIM_base                 (0x80140000)   /* SIM Card interface */
#define PWM_base                 (0x80150000)   /* Pulse Width Modulator */
#define ALERTER_base             (0x80160000)   /* Audio Alerter */

#if ( defined(MT6228) || defined(MT6229) || defined(MT6230) )
#define CHE_base                 (0x80170000)   /* Cipher Hash Engine */
#elif defined(MT6225) || defined(MT6223) || defined(MT6223P)
#define SEJ_base                 (0x80170000)   /* Security Engine for JTAG protection */
#endif /* MT6228 */

#if ( defined(MT6205B) || defined(MT6208) )
#define LCD_base                 (0x80170000)   /* LCD */
#else
#define LCD_base                 (0x90000000)   /* LCD */
#endif

#define UART2_base               (0x80180000)   /* UART / SIR IrDA 2 */

#if ( defined(MT6228) || defined(MT6229) || defined(MT6230) )
#define PFC_base                 (0x80190000)   /* PPP Framer */
#elif !defined(MT6225)   /* MT6228 || MT6229 || MT6230 */
#define MMC_base                 (0x80190000)   /* Multi-Media Card */
#endif /* MT6228 || MT6229 || MT6230 */

#if ( !defined(MT6208) && !defined(MT6205B) )
#define IRDA_base                (0x801a0000)   /* IrDA */
#define UART3_base               (0x801b0000)   /* UART3 */
#endif 

#if ( !defined(MT6208) && !defined(MT6205B) )
#define B2PSI_base               (0X801c0000)   /* Baseband to PMIC Serious Interface */
#endif 

#define TDMA_base                (0x80200000)   /* TDMA Timer */
#define SM_base                  (0x80200200)   /* Sleep Mode */
#define RTC_base                 (0x80210000)   /* Real Time Clock unit */
#define BSI_base                 (0x80220000)   /* Baseband Serial Interface */
#define BPI_base                 (0x80230000)   /* Baseband Parallel Interface */
#define AFC_base                 (0x80240000)   /* AFC */
#define APC_base                 (0x80250000)   /* TX Power Control */
#define FCS_base                 (0x80260000)   /* FCS Unit */
#define AUXADC_base              (0x80270000)   /* Auxiliary ADC */

#if ( !defined(MT6208) && !defined(MT6205B) )
#define DIVIDER_base             (0x80280000)   /* Divider */
#define CSD_ACC_base             (0x80290000)   /* CSD_ACC */
#define MSDC_base                (0x802a0000)   /* MSDC */
#endif 

#define SHARE_base               (0x80300000)   /* DSP to CPU interrupt control (shared register) */
#define PATCH_base               (0x80310000)   /* DSP to CPU interrupt control (shared register) */

#if defined(MT6229) || defined(MT6230) || defined(MT6223) || defined(MT6223P)
#define SHARE2_base              (0x80320000)   /* DSP2 to CPU interrupt control (shared register) */
#elif defined(MT6225) 
#define IRDBG_base               (0x80320000)   /* IRDBG */
#endif  /* MT6229 || MT6230 */

#if defined(MT6223) || defined(MT6223P)
#define PATCH2_base              (0x80330000)   /* PATCH2 */
#endif /* MT6223  || defined(MT6223P)*/

#define AFE_base                 (0x80400000)   /* Audio interface */
#define BFE_base                 (0x80410000)   /* Base-band Front End */

#if defined(MT6225)
#define DIGRF_base               (0x80430000)   /* DigitalRF interface */
#endif  /* MT6225 */

/* APB Bus 5 */
#if ( !defined(MT6208) && !defined(MT6205B) )
#define MIXED_base               (0x80500000)   /* Analog Chip Interface Controller */
#endif 

#if ( !defined(MT6205B) && !defined(MT6208) && !defined(MT6228) && !defined(MT6229) && !defined(MT6230) && !defined(MT6225)  && !defined(MT6223) &&  !defined(MT6223P))
#define JPEG_CODEC_base          (0x80600000)
#define RESIZER_base             (0x80610000)
#endif

#if defined(MT6219) || defined(MT6226) || defined(MT6227) || defined(MT6226M) || defined(MT6227D) || defined(MT6226D)
#define CAMERA_base              (0x80620000)
#define IMGPROC_base             (0x80630000)
#define GIF_base                 (0x80650000)
#define GCMQ_base                (0x80660000)
#define G2D_base                 (0x80670000)
#define MP4_base                 (0x80680000)
#define IMGDMA_base              (0x80690000)
#define SCCB_I2C_base            (0x800A0000)   
#endif

#if ( defined(MT6228) || defined(MT6229) || defined(MT6230) )
#define JPEG_CODEC_base          (0x80600000)   /* JPEG Decoder */
#define PRZ_base                 (0x80610000)   /* Post Processing Resizer */
#define CAMERA_base              (0x80620000)   /* Camera Interface */
#define IMGPROC_base             (0x80630000)   /* Image Engine */
#define PNGDEC_base              (0x80640000)   /* PNG Decoder */
#define GIFDEC_base              (0x80650000)   /* GIF Decoder */
#define GCMQ_base                (0x80660000)   /* 2D Command Queue */
#define G2D_base                 (0x80670000)   /* 2D Accelerator */
#define MP4_base                 (0x80680000)   /* MPEG4 Codec */
#define IMGDMA_base              (0x80690000)   /* Image DMA */
#define CRZ_base                 (0x806a0000)   /* Capture Resizer */
#define DRZ_base                 (0x806b0000)   /* Drop Resizer */
#define TVENC_base               (0x806c0000)   /* TC Encoder */
#define TVCON_base               (0x806d0000)   /* TV Controller */
#define GMC_base                 (0x806e0000)   /* Graphics Memory Controller */
#define L1C_base                 (0x80700000)   /* Code cache controller and MPU */
#endif

#if defined(MT6225)
#define PRZ_base                 (0x80610000)   /* Post Processing Resizer */
#define CAMERA_base              (0x80620000)   /* Camera Interface */
#endif  /* MT6225 */


#endif	// #if defined(MT6238)
/* VERSION Registers */
#define HW_VER    ((UINT16P)(CONFIG_base+0x0000)) /* Hardware ver register */
#define FW_VER    ((UINT16P)(CONFIG_base+0x0004)) /* Firmware ver register */
#define HW_CODE   ((UINT16P)(CONFIG_base+0x0008)) /* Hardware ver register */


/*******************************************************************************
 *                         Configuration Register
 *******************************************************************************/

/* System special register */
#if defined(MT6223) || defined(MT6223P)
#define SW_MISC_L                ((volatile UINT32P)(CONFIG_base+0x10))
#define SW_MISC_H                ((volatile UINT32P)(CONFIG_base+0x14))
#endif

/* CLK Registers on APB CPU */
#if ( defined(MT6228) || defined(MT6229) || defined(MT6230) )

#define MPLL                     ((volatile UINT16P)(CONFIG_base+0x100))   /* MPLL Freq control */
#define DPLL                     ((volatile UINT16P)(CONFIG_base+0x104))   /* DPLL Freq control */
#define UPLL                     ((volatile UINT16P)(CONFIG_base+0x108))   /* UPLL Freq control */
#define TPLL                     ((volatile UINT16P)(CONFIG_base+0x10C))   /* TPLL Freq control */
#define CLK_CON                  ((volatile UINT16P)(CONFIG_base+0x110))   /* Clock control */
#define SLEEP_CON                ((volatile UINT16P)(CONFIG_base+0x114))   /* Sleep control */
#define MCUCLK_CON               ((volatile UINT16P)(CONFIG_base+0x118))   /* MCU Clock Control */
#define DSPCLK_CON               ((volatile UINT16P)(CONFIG_base+0x11C))   /* DSP Clock Control */

#elif defined(MT6225) || defined(MT6223) || defined(MT6223P)  /* MT6228 || MT6229 || MT6230 */

#define PLL                      ((volatile UINT16P)(CONFIG_base+0x100))   /* PLL Freq control */
#define CLK_CON                  ((volatile UINT16P)(CONFIG_base+0x110))   /* Clock control */
#define SLEEP_CON                ((volatile UINT16P)(CONFIG_base+0x114))   /* Sleep control */
#define MCUCLK_CON               ((volatile UINT16P)(CONFIG_base+0x118))   /* MCU Clock Control */
#define DSPCLK_CON               ((volatile UINT16P)(CONFIG_base+0x11C))   /* DSP Clock Control */

#elif defined(MT6238)

#define PLL                      		((volatile UINT16P)(PLL_base+0x000))   /* PLL Freq control */
#define PLL2                    		((volatile UINT16P)(PLL_base+0x004))   /* PLL Freq control 2 */
#define CPLL                      	((volatile UINT16P)(PLL_base+0x008))   /* CPLL Freq control */
#define CPLL2                      	((volatile UINT16P)(PLL_base+0x00C))   /* CPLL Freq control 2 */
#define TPLL                     	((volatile UINT16P)(PLL_base+0x010))   /* TPLL Freq control */
#define TPLL2                     	((volatile UINT16P)(PLL_base+0x014))   /* TPLL Freq control 2 */
#define CLK_CON                  	((volatile UINT16P)(PLL_base+0x018))   /* Clock control */
#define PDN_CON                  	((volatile UINT16P)(PLL_base+0x01C))   /* Clock control */

#define SLEEP_CON                	((volatile UINT16P)(CONFIG_base+0x114))   /* Sleep control */
#define MCUCLK_CON              ((volatile UINT16P)(CONFIG_base+0x118))   /* MCU Clock Control */
#define DSPCLK_CON               ((volatile UINT16P)(CONFIG_base+0x11C))   /* DSP Clock Control */
#define IDN_SEL				((volatile UINT16P)(CONFG_BASE+0x0200))  /* Internal Debug Select Register. */


#define PLL2_TPLL_PDN          0x0001


#else   /* MT6228 || MT6229 || MT6230 */

#define MPLL                     ((volatile UINT16P)(CONFIG_base+0x100))   /* PLL1 Freq control */
#define DPLL                     ((volatile UINT16P)(CONFIG_base+0x104))   /* PLL2 Freq control */
#define CLK_CON                  ((volatile UINT16P)(CONFIG_base+0x108))   /* Clock control */
#define SLEEP_CON                ((volatile UINT16P)(CONFIG_base+0x10C))   /* Clock control */

#if ( !defined(MT6208) && !defined(MT6205B) )
#define UPLL                     ((volatile UINT16P)(CONFIG_base+0x110))   /* USB Freq control */
#endif /* !MT6208 && !MT6205B */

#if defined(MT6217) || defined(MT6226) || defined(MT6227) || defined(MT6226M) || defined(MT6227D) || defined(MT6226D)
#define MCUCLK_CON               ((volatile UINT16P)(CONFIG_base+0x114))   /* MCU Clock Control */
#endif   /* MT6217 || MT6226 || MT6227 || MT6226M  || defined(MT6227D) || defined(MT6226D)*/

#endif /* MT6228 || MT6229 || MT6230 */

/* Reset Registers */
#define SW_RSTN                  ((volatile UINT16P)(CONFIG_base+0x0200))  /* Software reset register */
#define SW_DSP_RSTN              ((volatile UINT16P)(CONFIG_base+0x0204))  /* CPU to DSP reset register */

/* Software Power-down Control Registers */
#define PDN_CON0                 ((volatile UINT16P)(CONFIG_base+0x0300))  /* Power-down control 1 */
#define PDN_CON1                 ((volatile UINT16P)(CONFIG_base+0x0304))  /* Power-down control 2 */
#define PDN_CON2                 ((volatile UINT16P)(CONFIG_base+0x0308))  /* Power-down control 3 */
#define PDN_CON3                 ((volatile UINT16P)(CONFIG_base+0x030C))  /* Power-down control 4 */
#define PDN_SET0                 ((volatile UINT16P)(CONFIG_base+0x0310))  /* Power-down set 1 */
#define PDN_SET1                 ((volatile UINT16P)(CONFIG_base+0x0314))  /* Power-down set 2 */
#define PDN_SET2                 ((volatile UINT16P)(CONFIG_base+0x0318))  /* Power-down set 3 */
#define PDN_SET3                 ((volatile UINT16P)(CONFIG_base+0x031C))  /* Power-down set 4 */
#define PDN_CLR0                 ((volatile UINT16P)(CONFIG_base+0x0320))  /* Power-down clear 1 */
#define PDN_CLR1                 ((volatile UINT16P)(CONFIG_base+0x0324))  /* Power-down clear 2 */
#define PDN_CLR2                 ((volatile UINT16P)(CONFIG_base+0x0328))  /* Power-down clear 3 */
#define PDN_CLR3                 ((volatile UINT16P)(CONFIG_base+0x032C))  /* Power-down clear 4 */

#if ( defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6238))
#define PDN_CON4                 ((volatile UINT16P)(CONFIG_base+0x0330))  /* Power-down control 5 */
#define PDN_SET4                 ((volatile UINT16P)(CONFIG_base+0x0334))  /* Power-down set 5 */
#define PDN_CLR4                 ((volatile UINT16P)(CONFIG_base+0x0338))  /* Power-down clear 5 */

#if defined(MT6238)
#define APB_CON                  	((volatile UINT16P)(CONFIG_base+0x0404))  /* APB bus crontrol */
#define SLOWDN_CON             	((volatile UINT16P)(CONFIG_base+0x0408))  /* Slow down control register */
#else	//#if defined(MT6238)
#define APB_CON                  ((volatile UINT16P)(CONFIG_base+0x0400))  /* APB bus crontrol */
#define SLOWDN_CON               ((volatile UINT16P)(CONFIG_base+0x0404))  /* Slow down control register */
#endif	// #if defined(MT6238)
#define AHB_CON                  ((volatile UINT16P)(CONFIG_base+0x0500))  /* AHB bus crontrol */

#define SYSRAM_CON               ((volatile UINT16P)(CONFIG_base+0x0600))  /* SYSRAM control */

#define ACIF_CON0                ((volatile UINT16P)(CONFIG_base+0x0700))  /* Analog chip interface control 0 */
#if defined(MT6238)
#define ACIF_CON1                ((volatile UINT16P)(CONFIG_base+0x0704))  /* Analog chip interface control 1 */
#endif	// #if defined(MT6238)
#define ACIF_CON2                ((volatile UINT16P)(CONFIG_base+0x0708))  /* Analog chip interface control 2 */

#define WAVE_SD_CON              ((volatile UINT16P)(CONFIG_base+0x0800))  /* Wave table slow down control */

#define ROM_DELSEL0              ((volatile UINT16P)(CONFIG_base+0x0900))  /* MCU ROM setting control */
#define RAM_DELSEL0              ((volatile UINT16P)(CONFIG_base+0x0a00))  /* MCU RAM setting control */
#if defined(MT6238)
#define EFUSE_CON             ((volatile UINT32P)(0x80000000))  			/* eFuse control */
#define CHIPID1                  ((volatile UINT32P)(EFUSE_CON+0x0010))  /* Chip ID register 1 */
#define CHIPID2                  ((volatile UINT32P)(EFUSE_CON+0x0014))  /* Chip ID register 2 */
#define CHIPID3                  ((volatile UINT32P)(EFUSE_CON+0x0018))  /* Chip ID register 3 */
#define CHIPID4                  ((volatile UINT32P)(EFUSE_CON+0x001c))  /* Chip ID register 4 */
#else
#define EFUSE_CON                ((volatile UINT16P)(CONFIG_base+0xf000))  /* eFuse control */
                                                                           
#define CHIPID1                  ((volatile UINT16P)(CONFIG_base+0xf010))  /* Chip ID register 1 */
#define CHIPID2                  ((volatile UINT16P)(CONFIG_base+0xf014))  /* Chip ID register 2 */
#define CHIPID3                  ((volatile UINT16P)(CONFIG_base+0xf018))  /* Chip ID register 3 */
#define CHIPID4                  ((volatile UINT16P)(CONFIG_base+0xf01c))  /* Chip ID register 4 */
#endif	// #if defined(MT6238)
#endif /* MT6228 || MT6229 || MT6230 */

#if ( defined(MT6226M) )
#define ACIF_CON0                ((volatile UINT16P)(CONFIG_base+0x0704))  /* Analog chip interface control 0 */
#endif /* MT6226M */

/* ACIF control */
#if ( !defined(MT6208) && !defined(MT6205B) )
#define ACIF_CON1                ((volatile UINT16P)(CONFIG_base+0x0704)) /* Analog Chip Interface Control Register 1 */
#endif   /* !MT6208 && !MT6205B */

#if defined(MT6225)
#define APB_CON                  ((volatile UINT16P)(CONFIG_base+0x0404))  /* APB bus crontrol */
#define SYSRAM_CON               ((volatile UINT16P)(CONFIG_base+0x0600))  /* SYSRAM control */
#endif  /* MT6225 */

#if defined(MT6223) || defined(MT6223P)
#define ACIF_CON0                ((volatile UINT16P)(CONFIG_base+0x0700))  /* Analog chip interface control 0 */
#endif /* MT6223 || defined(MT6223P) */


/*******************************************************************************
 *                          EMI Registers
 *******************************************************************************/
#if defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6225)

#define EMI_CONA                 ((volatile UINT32P)(EMI_base+0x0000))  /* EMI control register for bank 0 */
#define EMI_CONB                 ((volatile UINT32P)(EMI_base+0x0008))  /* EMI control register for bank 1 */
#define EMI_CONC                 ((volatile UINT32P)(EMI_base+0x0010))  /* EMI control register for bank 2 */
#define EMI_COND                 ((volatile UINT32P)(EMI_base+0x0018))  /* EMI control register for bank 3 */
#define EMI_CONI                 ((volatile UINT32P)(EMI_base+0x0040))  /* EMI control register 0 for Mobile-RAM */
#define EMI_CONJ                 ((volatile UINT32P)(EMI_base+0x0048))  /* EMI control register 1 for Mobile-RAM */
#define EMI_CONK                 ((volatile UINT32P)(EMI_base+0x0050))  /* EMI control register 2 for Mobile-RAM */
#define EMI_CONL                 ((volatile UINT32P)(EMI_base+0x0058))  /* EMI control register 3 for Mobile-RAM */
#define EMI_REMAP                ((volatile UINT16P)(EMI_base+0x0060))  /* EMI Re-map Control Register */
#define EMI_GENA                 ((volatile UINT32P)(EMI_base+0x0068))  /* EMI General Control Register 0 */
#define EMI_GENB                 ((volatile UINT32P)(EMI_base+0x0070))  /* EMI General Control Register 1 */

#if defined(MT6229) || defined(MT6230)
#define EMI_GENC                 ((volatile UINT32P)(EMI_base+0x0078))  /* EMI General Control Register 2 */
#endif /* MT6229 || MT6230 */

#if defined(MT6225)
#define EMI_ADMUX                ((volatile UINT32P)(EMI_base+0x0078))  /* ADMUX Control Register */
#endif /* MT6225 */

#elif defined(MT6205B) || defined(MT6208)   /* MT6228 || MT6229 || MT6230 */

#define EMI_CON0                 ((volatile UINT16P)(EMI_base+0x0000))  /* Bank 0 configuration */
#define EMI_CONA                 EMI_CON0
#define EMI_CON1                 ((volatile UINT16P)(EMI_base+0x0004))  /* Bank 1 configuration */
#define EMI_CONB                 EMI_CON1
#define EMI_CON2                 ((volatile UINT16P)(EMI_base+0x0008))  /* Bank 2 configuration */
#define EMI_CONC                 EMI_CON2
#define EMI_CON3                 ((volatile UINT16P)(EMI_base+0x000C))  /* Bank 3 configuration */
#define EMI_COND                 EMI_CON3
#define EMI_CON4                 ((volatile UINT16P)(EMI_base+0x0010))  /* Boot Mapping config  */
#define EMI_CON5                 ((volatile UINT16P)(EMI_base+0x0014))
#define EMI_GEN                  ((volatile UINT16P)(EMI_base+0x0014))
#define SDRAM_MODE               ((volatile UINT16P)(EMI_base+0x0020))
#define SDRAM_COMD               ((volatile UINT16P)(EMI_base+0x0024))
#define SDRAM_SET                ((volatile UINT16P)(EMI_base+0x0028))
#define PREFETCH_CON             ((volatile UINT16P)(EMI_base+0x0030))

#elif defined MT6218    /* MT6228 || MT6229 || MT6230 */

#define EMI_CONA0                ((volatile UINT16P)(EMI_base+0x0000))  /* Bank 0 configuration */
#define EMI_CONA1                ((volatile UINT16P)(EMI_base+0x0004))  /* Bank 0 configuration */
#define EMI_CONB0                ((volatile UINT16P)(EMI_base+0x0008))  /* Bank 1 configuration */
#define EMI_CONB1                ((volatile UINT16P)(EMI_base+0x000C))  /* Bank 1 configuration */
#define EMI_CONC0                ((volatile UINT16P)(EMI_base+0x0010))  /* Bank 2 configuration */
#define EMI_CONC1                ((volatile UINT16P)(EMI_base+0x0014))  /* Bank 2 configuration */
#define EMI_COND0                ((volatile UINT16P)(EMI_base+0x0018))  /* Bank 3 configuration */
#define EMI_COND1                ((volatile UINT16P)(EMI_base+0x001C))  /* Bank 3 configuration */
#define EMI_CONE0                ((volatile UINT16P)(EMI_base+0x0020))  /* Bank 4 configuration */
#define EMI_CONE1                ((volatile UINT16P)(EMI_base+0x0024))  /* Bank 4 configuration */
#define EMI_CONF0                ((volatile UINT16P)(EMI_base+0x0028))  /* Bank 5 configuration */
#define EMI_CONF1                ((volatile UINT16P)(EMI_base+0x002C))  /* Bank 5 configuration */
#define EMI_REMAP                ((volatile UINT16P)(EMI_base+0x0030))  /* EMI Re-map Control Register */
#define EMI_GEN                  ((volatile UINT16P)(EMI_base+0x0034))  /* EMI General Control Register */
#define PREFETCH_CON             ((volatile UINT16P)(EMI_base+0x0050))  /* Code Cache and Code Prefetch Control Register */
#define EMI_PATCHEN              ((volatile UINT16P)(EMI_base+0x0060))  /* EMI Patch Enable Register */
#define EMI_MSBPA0               ((volatile UINT16P)(EMI_base+0x0064))  /* EMI Patch Address 0 MSB Register */
#define EMI_LSBPA0               ((volatile UINT16P)(EMI_base+0x0068))  /* EMI Patch Address 0 LSB Register */
#define EMI_MSBPD0               ((volatile UINT16P)(EMI_base+0x006C))  /* EMI Patch Instruction 0 MLB Register */
#define EMI_LSBPD0               ((volatile UINT16P)(EMI_base+0x0070))  /* EMI Patch Instruction 1 LSB Register */
#define EMI_MSBPA1               ((volatile UINT16P)(EMI_base+0x0074))  /* EMI Patch Address 1 MSB Register */
#define EMI_LSBPA1               ((volatile UINT16P)(EMI_base+0x0078))  /* EMI Patch Address 1 LSB Register */
#define EMI_MSBPD1               ((volatile UINT16P)(EMI_base+0x007C))  /* EMI Patch Instruction 1 MLB Register */
#define EMI_LSBPD1               ((volatile UINT16P)(EMI_base+0x0080))  /* EMI Patch Instruction 1 LSB Register */

#elif defined(MT6238)

/* SHK: MT6238 here. */

#define EMI_CONA                 	((volatile UINT32P)(EMI_base+0x0000))  /* EMI control register for bank 0 */
#define EMI_CONB                 	((volatile UINT32P)(EMI_base+0x0008))  /* EMI control register for bank 1 */
#define EMI_CONC                 	((volatile UINT32P)(EMI_base+0x0010))  /* EMI control register for bank 2 */
#define EMI_COND                 	((volatile UINT32P)(EMI_base+0x0018))  /* EMI control register for bank 3 */

#define EMI_CONI                 	((volatile UINT32P)(EMI_base+0x0040))  /* EMI control register 0 for MR/EMR */
#define EMI_CONJ                 	((volatile UINT32P)(EMI_base+0x0048))  /* EMI control register 1 for DRAM Controller timing configuration 1. */
#define EMI_CONK                 	((volatile UINT32P)(EMI_base+0x0050))  /* EMI control register 2 for DRAM Controller timing configuration 2. */
#define EMI_CONL                 	((volatile UINT32P)(EMI_base+0x0058))  /* EMI control register 3 for DRAM Controller read data path configuration. */
#define EMI_CONM                 	((volatile UINT32P)(EMI_base+0x0060))  /* EMI control register 3 for DRAM Controller read delay timing configuration. */
#define EMI_CONN                 	((volatile UINT32P)(EMI_base+0x0068))  /* EMI control register 3 for DRAM Controller function configuration. */

#define EMI_GENA                 	((volatile UINT32P)(EMI_base+0x0070))  /* EMI General Control Register 0 */
#define EMI_GENB                 	((volatile UINT32P)(EMI_base+0x0078))  /* EMI General Control Register 1 */
#define EMI_GENC                 	((volatile UINT32P)(EMI_base+0x0080))  /* EMI General Control Register 2 */
#define EMI_GEND                 	((volatile UINT32P)(EMI_base+0x0088))  /* EMI General Control Register 3 */

#define EMI_REMAP                ((volatile UINT32P)(EMI_base+0x0070))  /* EMI Re-map Control Register */

#else   /* MT6228 || MT6229 || MT6230 */

#define EMI_CONA                 ((volatile UINT32P)(EMI_base+0x0000))  /* Bank 0 configuration */
#define EMI_CONB                 ((volatile UINT32P)(EMI_base+0x0008))  /* Bank 1 configuration */
#define EMI_CONC                 ((volatile UINT32P)(EMI_base+0x0010))  /* Bank 2 configuration */
#define EMI_COND                 ((volatile UINT32P)(EMI_base+0x0018))  /* Bank 3 configuration */
#define EMI_CONE                 ((volatile UINT32P)(EMI_base+0x0020))  /* Bank 4 configuration */
#define EMI_CONF                 ((volatile UINT32P)(EMI_base+0x0028))  /* Bank 5 configuration */
#define EMI_CONG                 ((volatile UINT32P)(EMI_base+0x0030))  /* Bank 6 configuration */
#define EMI_CONH                 ((volatile UINT32P)(EMI_base+0x0038))  /* Bank 7 configuration */
#define EMI_REMAP                ((volatile UINT16P)(EMI_base+0x0040))  /* EMI Re-map Control Register */
#define EMI_GEN                  ((volatile UINT32P)(EMI_base+0x0044))  /* EMI General Control Register */
#define PREFETCH_CON             ((volatile UINT32P)(EMI_base+0x0050))  /* Code Cache and Code Prefetch Control Register */

#if defined(MT6223) || defined(MT6223P)
#define EMI_ADMUX                ((volatile UINT32P)(EMI_base+0x0078))  /* ADMUX Control Register */
#endif /* MT6223  || defined(MT6223P)*/

#endif  /* MT6228 || MT6229 || MT6230 */


/*******************************************************************************
 *                          Analog
 *******************************************************************************/
#if !defined(MT6208) && !defined(MT6205B)
#define AC_ODS_CON               ((volatile UINT16P)(MIXED_base + 0x0000))
#define ANALOG_HW_VERSION        ((volatile UINT16P)(MIXED_base + 0x0004))
#define ANALOG_HW_CODE           ((volatile UINT16P)(MIXED_base + 0x0008))
#endif /* !MT6208 && !MT6205B */

/*******************************************************************************
 *                          Boot Mode Control Register
 *******************************************************************************/
#if defined(MT6225)
#define BOOT_CONFIG_ADDR         ((volatile UINT16P)0x80120000)
#elif defined(MT6208) || defined(MT6205B)
#define BOOT_CONFIG_ADDR         ((volatile UINT16P)0x80120004)
#elif defined(MT6218B) || defined(MT6217) || defined(MT6219) 
#define BOOT_CONFIG_ADDR         ((volatile UINT16P)0x80120010)
#elif defined(MT6226) || defined(MT6227) || defined(MT6226M) 
#define BOOT_CONFIG_ADDR         ((volatile UINT16P)0x80120010)
#elif defined(MT6228) || defined(MT6229) || defined(MT6230)
#define BOOT_CONFIG_ADDR         ((volatile UINT16P)0x80120010)
#elif ( defined(MT6227D)  || defined(MT6226D))
#define BOOT_CONFIG_ADDR         ((volatile UINT16P)0x80000010)
#elif defined(MT6238)
//#define BOOT_CONFIG_ADDR         ((volatile UINT16P)0x80010010)
#define BOOT_CONFIG_ADDR         ((volatile UINT16P)0x800200C0)

#else
#define BOOT_CONFIG_ADDR         SW_MISC_L
#endif /* MT6225 */

#endif /* _REG_BASE_H */


