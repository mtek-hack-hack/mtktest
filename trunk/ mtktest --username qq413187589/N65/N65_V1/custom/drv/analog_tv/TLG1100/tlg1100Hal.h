#ifndef _TLG1100HAL_H_
#define _TLG1100HAL_H_
/****************************************************************************/
/*!@file  tlg1100Hal.h
 *
 * @brief Hardware Definitions for the TLG1100 programmatic interface support.
 *
 * This file contains the api definitions for the TLG1100 Ultra Low Power
 * NTSC/PAL Tuner/Decoder chip support library.
 *
 *
 ****************************************************************************/
/* Revision Information:
 *
 * $Revision: 1.28 $
 *
 * (c) 2006 Telegent Systems
 ****************************************************************************/

#include "tlg1100Config.h"

#define BIT0                        ((unsigned short)0x0001) /*!< bit  0 */
#define BIT1                        ((unsigned short)0x0002) /*!< bit  1 */
#define BIT2                        ((unsigned short)0x0004) /*!< bit  2 */
#define BIT3                        ((unsigned short)0x0008) /*!< bit  3 */
#define BIT4                        ((unsigned short)0x0010) /*!< bit  4 */
#define BIT5                        ((unsigned short)0x0020) /*!< bit  5 */
#define BIT6                        ((unsigned short)0x0040) /*!< bit  6 */
#define BIT7                        ((unsigned short)0x0080) /*!< bit  7 */
#define BIT8                        ((unsigned short)0x0100) /*!< bit  8 */
#define BIT9                        ((unsigned short)0x0200) /*!< bit  9 */
#define BIT10                       ((unsigned short)0x0400) /*!< bit 10 */
#define BIT11                       ((unsigned short)0x0800) /*!< bit 11 */
#define BIT12                       ((unsigned short)0x1000) /*!< bit 12 */
#define BIT13                       ((unsigned short)0x2000) /*!< bit 13 */
#define BIT14                       ((unsigned short)0x4000) /*!< bit 14 */
#define BIT15                       ((unsigned short)0x8000) /*!< bit 15 */

#define BIT3_0                      ((unsigned short)0x000f)
#define BIT7_4                      ((unsigned short)0x00f0)
#define BIT11_8                     ((unsigned short)0x0f00)
#define BIT15_12                    ((unsigned short)0xf000)
#define BIT7_0                      (BIT7_4|BIT3_0)
#define BIT15_8                     (BIT15_12|BIT11_8)
#define BIT15_0                     (BIT15_8|BIT7_0)
#define BIT11_0                     (BIT11_8|BIT7_0)
#define BIT14_10                    (BIT14|BIT13|BIT12|BIT11|BIT10)
#define BIT6_0                      (BIT6|BIT5|BIT4|BIT3_0)
#define BIT5_0                      (BIT5|BIT4|BIT3_0)
#define BIT11_9                     (BIT11|BIT10|BIT9)
#define BIT12_9                     (BIT12|BIT11_9)

/** Clear a masked area in a register value                                   */
#define TLGHAL_CLEAR(reg, mask) reg &= ((uint16) ~(mask))

/** Set a masked area to a value                                              */
#define TLGHAL_SET(reg, var, shift, mask) \
                    reg = ((uint16) (((reg) & ~(mask)) | (((var) << (shift)) & (mask))))

/** Get a field in a register                                                 */
#define TLGHAL_GET(var, reg, shift, mask) var = (((reg) & (mask)) >> (shift))

/******************************************************************************
* TLG1100 CHIP REVISION CONTROL DEFINES
******************************************************************************/

/*
 * Chip Version Configuration Section
 */

/*****************************************************************************
* CHIP CONFIG CONSTANTS
*
* The following are chip version configuration constants and should not be
* changed.
*****************************************************************************/
#define TLG_CHIP_TYPE_MASK          (0xffff0000)
#define TLG_CHIP_TYPE_SHIFT         (16)

#define TLG_CHIP_REV_MASK           (0x0000ff00)
#define TLG_CHIP_REV_SHIFT          (8)
#define TLG_CHIP_PATCH_MASK         (0x000000ff)
#define TLG_CHIP_PATCH_SHIFT        (0)

#define TLG_CHIP_VER_CFG(t, r)      ( ((t) << TLG_CHIP_TYPE_SHIFT) \
                                    | ((r)  << TLG_CHIP_REV_SHIFT) )

#define TLG1100_VERS_1_1            \
                    TLG_CHIP_VER_CFG(TLG_CHIP_TYPE_TLG1100_1,TLG_CHIP_REV_1)
#define TLG1100_VERS_1_2            \
                    TLG_CHIP_VER_CFG(TLG_CHIP_TYPE_TLG1100_1,TLG_CHIP_REV_2)
#define TLG1100_VERS_1_3           \
                    TLG_CHIP_VER_CFG(TLG_CHIP_TYPE_TLG1100_1,TLG_CHIP_REV_3)


#define TLG_NO_VERS    (TLG_CHIP_TYPE_MASK|TLG_CHIP_REV_MASK)

/** Chip version configuration.
*
* TLG_CHIP_VERS defines the latest type and version of chip that the current
* code compile will support. It uses the defines TLG_CHIP_TYPE and 
* TLG_CHIP_REV which are declared in tlg1100Config.h.
*
*/
#define TLG_CHIP_VERS         TLG_CHIP_VER_CFG(TLG_CHIP_TYPE, TLG_CHIP_REV)

#define TLG_CHIP_CMP_GE(v) \
     ( (((v) & TLG_CHIP_TYPE_MASK) >> TLG_CHIP_TYPE_SHIFT) == TLG_CHIP_TYPE \
     && (((v) & TLG_CHIP_REV_MASK)  >> TLG_CHIP_REV_SHIFT)  >= TLG_CHIP_REV)

#define TLG_CHIP_CMP_EQ(v) \
    ( (((v) & TLG_CHIP_TYPE_MASK) >> TLG_CHIP_TYPE_SHIFT) == TLG_CHIP_TYPE \
    && (((v) & TLG_CHIP_REV_MASK)  >> TLG_CHIP_REV_SHIFT)  == TLG_CHIP_REV)


#if !TLG_CHIP_CMP_EQ(TLG1100_VERS_1_2) && !TLG_CHIP_CMP_EQ(TLG1100_VERS_1_1) && !TLG_CHIP_CMP_EQ(TLG1100_VERS_1_3)
ERROR! UNSUPPORTED CHIP VERSION
#endif

/** Compile in code to support TLG1100 1.3.
*/
#if defined(TLG_SUPPORT_RUNTIME_CHECK) || TLG_CHIP_CMP_EQ(TLG1100_VERS_1_3)
#define TLG_CMP_CHIP_1_3 (1)
#endif /* TLG_CMP_CHIP_1_2 */

/** Compile in code to support TLG1100 1.2.
*/
#if defined(TLG_SUPPORT_RUNTIME_CHECK) || TLG_CHIP_CMP_EQ(TLG1100_VERS_1_2)
#define TLG_CMP_CHIP_1_2 (1)
#endif /* TLG_CMP_CHIP_1_2 */

/** Compile in code to support TLG1100 1.1
*/
#if defined(TLG_SUPPORT_RUNTIME_CHECK) || TLG_CHIP_CMP_EQ(TLG1100_VERS_1_1)
#define TLG_CMP_CHIP_1_1 (1)
#endif /* TLG_CMP_CHIP_1_1 */

/*
 * TLG1100_REGNAME                      (reg addr)
 *
 * TLG1100_REGNAME_FIELDNAME_MASK       (bits that define field)
 *
 * TLG1100_REGNAME_FIELDNAME_SHIFT      (least significant bit in field. Number
 *                                       of bits to shift to normalize field
 *                                       value)
 *
 * TLG1100_REGNAME_DEFAULT_VALUE        (initialization value for register)
 */
#define TLG1100_PWR                                                     (0x0000)
#define     TLG1100_PWR_SPORT_ATOP_MASK             (BIT7)
#define     TLG1100_PWR_SPORT_ATOP_SHIFT            (7)
#define     TLG1100_PWR_SRST_DTOP_MASK              (BIT6)
#define     TLG1100_PWR_SRST_DTOP_SHIFT             (6)
#define     TLG1100_PWR_JTAG_MASK                   (BIT5)
#define     TLG1100_PWR_JTAG_SHIFT                  (5)
#define     TLG1100_PWR_VDD_CORE_MASK               (BIT2)
#define     TLG1100_PWR_VDD_CORE_SHIFT              (2)
#define     TLG1100_PWR_CLK27_MASK                  (BIT1)
#define     TLG1100_PWR_CLK27_SHIFT                 (1)
#define     TLG1100_PWR_XTL_MASK                    (BIT0)
#define     TLG1100_PWR_XTL_SHIFT                   (0)
#define TLG1100_SRST                                                    (0x0001)
#define     TLG1100_SRST_SOFT_RST_MASK              (BIT0)
#define     TLG1100_SRST_SOFT_RST_SHIFT             (0)
#define TLG1100_VIDEO_STANDARD                                          (0x0002)
#define     TLG1100_VIDEO_STANDARD_MASK             (BIT3_0)
#define     TLG1100_VIDEO_STANDARD_SHIFT            (0)
#define TLG1100_ATOP_ADC_CAL_2                                          (0x0004)
#define     TLG_ATOP_ADC_CAL_2_FORCE_CAL_MASK       (BIT12)
#define     TLG_ATOP_ADC_CAL_2_FORCE_CAL_SHIFT      (12)
#define TLG1100_ATOP_ADC_CAL_13                                         (0x000f)
#define     TLG1100_ATOP_ADC_CAL_13_FRC_LD_MASK     (BIT12)
#define     TLG1100_ATOP_ADC_CAL_13_FRC_LD_SHIFT    (12)
#define TLG1100_ATOP_AGC_CAL_12                                         (0x001b)
#define TLG1100_ATOP_AGC_CAL_13                                         (0x001c)
#define TLG1100_ATOP_AGC_CAL_14                                         (0x001d)
#define TLG1100_ATOP_FILT_CAL_1                                         (0x0021)
#define     TLG1100_ATOP_FILT_CAL_1_FRC_FC_VAL_MASK  (BIT14_10)
#define     TLG1100_ATOP_FILT_CAL_1_FRC_FC_VAL_SHIFT (10)
#define     FILT_FORCE_FC_VAL                       (0x4000)
#define     FILT_FC_F3P0                            (0x0020) 
#define     FILT_FC_F2P5                            (0x0001)
#define TLG1100_ATOP_FILT_CAL_2                                         (0x0022)
#define     EDGE_CNT_FORCE_VAL_8                    (0x0364)
#define     EDGE_CNT_FORCE_VAL_6                    (0x0485)
#define     EDGE_CNT_FORCE_VAL_5                    (0x056d)
#define     TLG1100_ATOP_FILT_CAL_2_FRC_FC_MASK     (BIT12)
#define     TLG1100_ATOP_FILT_CAL_2_FRC_FC_SHIFT    (12)
#define     EDGE_CNT_FORCE_VAL_MASK                 (BIT10|BIT9|BIT8|BIT7_0)
#define     EDGE_CNT_FORCE_VAL_SHIFT                (0)
#define TLG1100_LUMA_PLL				            (0x0054)
#define     TLG1100_LUNA_EN_MASK                    (BIT15)
#define     TLG1100_LUNA_EN_SHIFT		            (15)
#define TLG1100_ATOP_LNACAL_5                                           (0x002e)
#define TLG1100_ATOP_LNACAL_6                                           (0x002f)
#define TLG1100_ATOP_LNACAL_7                                           (0x0030)
#define TLG1100_ATOP_SARADC                                             (0x0033)
#define     TLG1100_SARADC_FREEZE_MUX_MASK          (BIT12)
#define     TLG1100_SARADC_FREEZE_MUX_SHIFT         (12)
#define     TLG1100_SARADC_FREEZE_SEL_MASK          (BIT11|BIT10|BIT9|BIT8)
#define     TLG1100_SARADC_FREEZE_SEL_SHIFT         (8)
#define     TLG1100_SARADC_FREEZE_SEL_VAL           (0xd)
#define TLG1100_ATOP_TRKFIL_CAL_1                                       (0x0036)
#define     TLG1100_ATOP_TRKFIL_DISCH_TIME_MASK     (BIT1|BIT2|BIT3)
#define     TLG1100_ATOP_TRKFIL_DISCH_TIME_SHIFT    (1)
#define     TLG1100_ATOP_TRKFIL_DCYLE_MASK          (BIT9|BIT10|BIT11|BIT15_12)
#define     TLG1100_ATOP_TRKFIL_DCYLE_SHIFT         (9)
#define     TLG1100_ATOP_TRKFIL_CMP_CLK_DIV_MASK    (BIT6|BIT7)
#define     TLG1100_ATOP_TRKFIL_CMP_CLK_DIV_SHIFT   (6) 
#define TLG1100_ATOP_TRKFIL_CAL_2                                       (0x0037)
#define	    TLG1100_TRKFIL_ENABLE_DISH_MASK	        (BIT9)
#define	    TLG1100_TRKFIL_ENABLE_DISH_SHIFT        (9)
#define	    TLG1100_TRKFIL_SETT_TIME_MASK           (BIT10|BIT11|BIT12)
#define	    TLG1100_TRKFIL_SETT_TIME_SHIFT          (10)
#define TLG1100_ATOP_TRKFIL_CAL_3                                       (0x0038)
#define TLG1100_ATOP_TRKFIL_CAL_4                                       (0x0039)
#define TLG1100_DEMOD_HPF                                               (0x003d)
#define     TLG1100_DEMOD_HPF_CHN_FIL_MASK          (BIT4)
#define     TLG1100_DEMOD_HPF_CHN_FIL_SHIFT         (4)
#define     TLG1100_DEMOD_HPF_VID_PWR_MASK          (BIT7)
#define     TLG1100_DEMOD_HPF_VID_PWR_SHIFT         (7)
#define     TLG1100_DEMOD_HPF_NTCH_DBL_MASK         (BIT9)
#define     TLG1100_DEMOD_HPF_NTCH_DBL_SHIFT        (9)
#define TLG1100_TONE_NOTCH1                                             (0x004a)
#define     TLG1100_TONE_NOTCH1_BW_MASK             (BIT6|BIT5|BIT4)
#define     TLG1100_TONE_NOTCH1_BW_SHIFT            (4)
#define     TLG1100_TONE_NOTCH1_BYP_MASK            (BIT1)
#define     TLG1100_TONE_NOTCH1_BYP_SHIFT           (1)
#define     TLG1100_TONE_NOTCH1_EN_MASK             (BIT0)
#define     TLG1100_TONE_NOTCH1_EN_SHIFT            (0)
#define TLG1100_TONE_NOTCH2                                             (0x004b)
#define     TLG1100_TONE_NOTCH2_NEG_MASK            (BIT15)
#define     TLG1100_TONE_NOTCH2_NEG_SHIFT           (15)
#define     TLG1100_TONE_NOTCH2_HZ_MASK             (BIT14|BIT13|BIT12|BIT11_0)
#define     TLG1100_TONE_NOTCH2_HZ_SHIFT            (0)
#define TLG1100_LUMA_PLL2                                               (0x0053)
#define     TLG1100_LUMA_PLL2_C3_MASK               (BIT14|BIT13|BIT12)
#define     TLG1100_LUMA_PLL2_C3_SHIFT              (12)
#define TLG1100_LUMA_PLL3                                               (0x0054)
#define     TLG1100_LUMA_PLL3_ENABLE_MASK           (BIT15)
#define     TLG1100_LUMA_PLL3_ENABLE_SHIFT          (15)
#define     TLG1100_LUMA_PLL3_BYPLF2_MASK           (BIT12)
#define     TLG1100_LUMA_PLL3_BYPLF2_SHIFT          (12)
#define TLG1100_CHRMA_SCALE                                             (0x0068)
#define     TLG1100_CHRMA_SCALE_V_MASK              (BIT15_8)
#define     TLG1100_CHRMA_SCALE_V_SHIFT             (8)
#define     TLG1100_CHRMA_SCALE_U_MASK              (BIT7_0)
#define     TLG1100_CHRMA_SCALE_U_SHIFT             (0)
#define TLG1100_FAVG                                                    (0x006c)
#define     TLG1100_FAVG_AUTO2_MASK                 (BIT9)
#define     TLG1100_FAVG_AUTO2_SHIFT                (9)
#define     TLG1100_FAVG_AUTO_MASK                  (BIT8)
#define     TLG1100_FAVG_AUTO_SHIFT                 (8)
#define TLG1100_LUMA_SCALE                                              (0x006d)
#define     TLG1100_LUMA_SCALE_Y_MASK               (BIT3_0)
#define     TLG1100_LUMA_SCALE_Y_SHIFT              (0)
#define TLG1100_VID_CONFIG2                                             (0x006f)
#define     TLG1100_VID_CONFIG2_FF_MIN_OFF_MASK     (BIT6)
#define     TLG1100_VID_CONFIG2_FF_MIN_OFF_SHIFT    (6)
#define     TLG1100_VID_CONFIG2_SWAPCH_MASK         (BIT4)
#define     TLG1100_VID_CONFIG2_SWAPCH_SHIFT        (4)
#define TLG1100_VID_CONFIG3                                             (0x0070)
#define     TLG1100_VID_CONFIG3_FF_FILLWD_MASK      (BIT15)
#define     TLG1100_VID_CONFIG3_FF_FILLWD_SHIFT     (15)
#define     TLG1100_VID_CONFIG3_FF_ROM_MASK         (BIT7)
#define     TLG1100_VID_CONFIG3_FF_ROM_SHIFT        (7)
#define     TLG1100_VID_CONFIG3_SMP_ADJ_ALG_MASK    (BIT6|BIT5)
#define     TLG1100_VID_CONFIG3_SMP_ADJ_ALG_SHIFT   (5)
#define     TLG1100_VID_CONFIG3_INV601_MASK         (BIT4)
#define     TLG1100_VID_CONFIG3_INV601_SHIFT        (4)
#define     TLG1100_VID_CONFIG3_SWAPCB_MASK         (BIT2)
#define     TLG1100_VID_CONFIG3_FLIBCB_SHIFT        (2)
#define     TLG1100_VID_CONFIG3_BWMODE_MASK         (BIT0)
#define     TLG1100_VID_CONFIG3_BWMODE_SHIFT        (0)
#define     TLG1100_VID_CONFIG3_DEFAULT_VALUE       (0x8634)
#define TLG1100_VID_CONFIG4                                             (0x0071)
#define     TLG1100_VID_CONFIG4_HDECI_MASK          (BIT9|BIT8)
#define     TLG1100_VID_CONFIG4_HDECI_SHIFT         (8)
#define     TLG1100_VID_CONFIG4_DEFAULT_VALUE       (0x8c6a)
#define     TLG1100_VID_V_WIN_MASK                  (BIT7_4)
#define     TLG1100_VID_V_WIN_SHIFT                 (4)
#define TLG1100_VID_CONFIG5                                             (0x0072)
#define     TLG1100_VID_CONFIG5_FF_BUF_CTL_MASK     (BIT6|BIT5)
#define     TLG1100_VID_CONFIG5_FF_BUF_CTL_SHIFT    (5)
#define     TLG1100_VID_CONFIG5_FF_BUF_CTL_FREEZE   (3)
#define     TLG1100_VID_CONFIG5_FF_BUF_CTL_UNFREEZE (2)
#define     TLG1100_VID_CONFIG5_FF_BUF_CTL_AUTO     (0)
#define     TLG1100_VID_CONFIG5_FF_EN_MASK          (BIT0)
#define     TLG1100_VID_CONFIG5_FF_EN_SHIFT         (0)
#define TLG1100_VID_CONFIG6                                             (0x0073)
#define     TLG1100_VID_CONFIG6_FF_AGE_BUF_MASK     (BIT15)
#define     TLG1100_VID_CONFIG6_FF_AGE_BUF_SHIFT    (15)
#define TLG1100_VID_CONFIG9                                             (0x0076)
#define     TLG1100_VID_CONFIG9_FF_EXT_CNTR_MASK    (BIT7)
#define     TLG1100_VID_CONFIG9_FF_EXT_CNTR_SHIFT   (7)
#define TLG1100_VID_CONFIG10                                            (0x0077)
#define     TLG1100_VID_CONFIG10_FAVG_EN_MASK       (BIT12)
#define     TLG1100_VID_CONFIG10_FAVG_EN_SHIFT      (12)
#define     TLG1100_VID_CONFIG10_FAVG_ALPHA_MASK    (BIT5_0)
#define     TLG1100_VID_CONFIG10_FAVG_ALPHA_SHIFT    (0)
#define TLG1100_EXT_SYNC_CFG                                            (0x0078)
#define     TLG1100_EXT_SYNC_CFG_SL_MASK            (BIT15)
#define     TLG1100_EXT_SYNC_CFG_SL_SHIFT           (15)
#define     TLG1100_EXT_SYNC_CFG_HH_MASK            (BIT14)
#define     TLG1100_EXT_SYNC_CFG_HH_SHIFT           (14)
#define     TLG1100_EXT_SYNC_CFG_HL_MASK            (BIT6)
#define     TLG1100_EXT_SYNC_CFG_HL_SHIFT           (6)
#define     TLG1100_EXT_SYNC_CFG_V_MASK             (BIT1)
#define     TLG1100_EXT_SYNC_CFG_V_SHIFT            (1)
#define     TLG1100_EXT_SYNC_CFG_H_MASK             (BIT0)
#define     TLG1100_EXT_SYNC_CFG_H_SHIFT            (0)
#define TLG1100_EXT_HSYNC_CTL1                                          (0x007f)
#define     TLG1100_EXT_HSYNC_CTL1_H1_START_MASK    (BITS15_0)
#define     TLG1100_EXT_HSYNC_CTL1_H1_START_SHIFT   (0)
#define TLG1100_EXT_HSYNC_CTL2                                          (0x0080)
#define     TLG1100_EXT_HSYNC_CTL2_H1_STOP_MASK     (BITS15_0)
#define     TLG1100_EXT_HSYNC_CTL2_H1_STOP_SHIFT    (0)
#define TLG1100_EXT_HSYNC_CTL3                                          (0x0081)
#define     TLG1100_EXT_HSYNC_CTL3_L1_START_MASK    (BITS15_0)
#define     TLG1100_EXT_HSYNC_CTL3_L1_START_SHIFT   (0)
#define TLG1100_EXT_HSYNC_CTL4                                          (0x0082)
#define     TLG1100_EXT_HSYNC_CTL4_L1_STOP_MASK     (BITS15_0)
#define     TLG1100_EXT_HSYNC_CTL4_L1_STOP_SHIFT    (0)
#define TLG1100_EXT_HSYNC_CTL5                                          (0x0083)
#define     TLG1100_EXT_HSYNC_CTL5_L2_START_MASK    (BITS15_0)
#define     TLG1100_EXT_HSYNC_CTL5_L2_START_SHIFT   (0)
#define TLG1100_EXT_HSYNC_CTL6                                          (0x0084)
#define     TLG1100_EXT_HSYNC_CTL6_L2_STOP_MASK     (BITS15_0)
#define     TLG1100_EXT_HSYNC_CTL6_L2_STOP_SHIFT    (0)
#define TLG1100_EXT_VSYNC_CTL1                                          (0x0085)
#define     TLG1100_EXT_VSYNC_CTL1_H1_START_MASK    (BITS15_0)
#define     TLG1100_EXT_VSYNC_CTL1_H1_START_SHIFT   (0)
#define TLG1100_EXT_VSYNC_CTL2                                          (0x0086)
#define     TLG1100_EXT_VSYNC_CTL2_H1_STOP_MASK     (BITS15_0)
#define     TLG1100_EXT_VSYNC_CTL2_H1_STOP_SHIFT    (0)
#define TLG1100_EXT_VSYNC_CTL3                                          (0x0087)
#define     TLG1100_EXT_VSYNC_CTL3_H2_START_MASK    (BITS15_0)
#define     TLG1100_EXT_VSYNC_CTL3_H2_START_SHIFT   (0)
#define TLG1100_EXT_VSYNC_CTL4                                          (0x0088)
#define     TLG1100_EXT_VSYNC_CTL4_H2_STOP_MASK     (BITS15_0)
#define     TLG1100_EXT_VSYNC_CTL4_H2_STOP_SHIFT    (0)
#define TLG1100_EXT_VSYNC_CTL5                                          (0x0089)
#define     TLG1100_EXT_VSYNC_CTL5_H3_START_MASK    (BITS15_0)
#define     TLG1100_EXT_VSYNC_CTL5_H3_START_SHIFT   (0)
#define TLG1100_EXT_VSYNC_CTL6                                          (0x008a)
#define     TLG1100_EXT_VSYNC_CTL6_H3_STOP_MASK     (BITS15_0)
#define     TLG1100_EXT_VSYNC_CTL6_H3_STOP_SHIFT    (0)

#define TLG1100_SOUND_DEMOD1                                            (0x008b)
#define     TLG1100_SOUND_DEMOD1_2CHN_EN_MASK       (BIT8)
#define     TLG1100_SOUND_DEMOD1_2CHN_EN_SHIFT      (8)
#define     TLG1100_SOUND_DEMOD1_RTONE_MASK         (BIT7|BIT6)
#define     TLG1100_SOUND_DEMOD1_RTONE_SHIFT        (6)
#define     TLG1100_SOUND_DEMOD1_LTONE_MASK         (BIT5|BIT4)
#define     TLG1100_SOUND_DEMOD1_LTONE_SHIFT        (4)
#define     TLG1100_SOUND_DEMOD1_MASTER_MASK        (BIT3)
#define     TLG1100_SOUND_DEMOD1_MASTER_SHIFT       (3)
#define     TLG1100_SOUND_DEMOD1_TTONE_EN_MASK      (BIT1)
#define     TLG1100_SOUND_DEMOD1_TTONE_EN_SHIFT     (1)
#define     TLG1100_SOUND_DEMOD1_SOUND_EN_MASK      (BIT0)
#define     TLG1100_SOUND_DEMOD1_SOUND_EN_SHIFT     (0)
#define TLG1100_SOUND_DEMOD2                                            (0x008c)
#define     TLG1100_SOUND_DEMOD2_LOCK_MASK          (BIT15_8)
#define     TLG1100_SOUND_DEMOD2_LOCK_SHIFT         (8)
#define     TLG1100_SOUND_DEMOD2_PLL_GAIN_MASK      (BIT7)
#define     TLG1100_SOUND_DEMOD2_PLL_GAIN_SHIFT     (7)
#define     TLG1100_SOUND_DEMOD2_AUD_GAIN_MASK      (BIT6|BIT5|BIT4)
#define     TLG1100_SOUND_DEMOD2_AUD_GAIN_SHIFT     (4)
#define     TLG1100_SOUND_DEMOD2_HPF_HOLD_MASK      (BIT3)
#define     TLG1100_SOUND_DEMOD2_HPF_HOLD_SHIFT     (3)
#define     TLG1100_SOUND_DEMOD2_HPF_GAIN_MASK      (BIT2|BIT1|BIT0)
#define     TLG1100_SOUND_DEMOD2_HPF_GAIN_SHIFT     (0)
#define TLG1100_SOUND_DEMOD3                                            (0x008d)
#define     TLG1100_SOUND_DEMOD3_MASK               (0x03FF)
#define     TLG1100_SOUND_DEEMP2_EN_MASK            (BIT9)
#define     TLG1100_SOUND_DEEMP2_EN_SHIFT           (9)
#define     TLG1100_SOUND_DEEMP_EN_MASK             (BIT8)
#define     TLG1100_SOUND_DEEMP_EN_SHIFT            (8)
#define     TLG1100_SOUND_DEEMP2_SEL_MASK           (BIT7_4)
#define     TLG1100_SOUND_DEEMP2_SEL_SHIFT          (4)
#define     TLG1100_SOUND_DEEMP_SEL_MASK            (BIT3_0)
#define     TLG1100_SOUND_DEEMP_SEL_SHIFT           (0)
#define TLG1100_SOUND_DEMOD4                                            (0x008e)
#define     TLG1100_SOUND_DEMOD4_CIC_RATE_MASK      (BIT7_0)
#define     TLG1100_SOUND_DEMOD4_CIC_RATE_SHIFT     (0)
#define TLG1100_SOUND_DEMOD5                                            (0x008f)
#define     TLG1100_SOUND_DECI2_SEL_MASK            (BIT0)
#define     TLG1100_SOUND_DECI2_SEL_SHIFT           (0)
#define TLG1100_SOUND_DEMOD12                                           (0x0096)
#define     TLG1100_SOUND_MLEN_MASK                 (BIT12|BIT11_8)
#define     TLG1100_SOUND_MLEN_SHIFT                (8)
#define     TLG1100_SOUND_SLEN_MASK                 (BIT5|BIT4|BIT3_0)
#define     TLG1100_SOUND_SLEN_SHIFT                (0)
#define TLG1100_SOUND_DSMDAC                                            (0x0097)
#define     TLG1100_SOUND_DSMDAC_SCALE_MASK         (BIT5|BIT4)
#define     TLG1100_SOUND_DSMDAC_SCALE_SHIFT        (4)
#define     TLG1100_SOUND_DSMDAC_2CHAN_MASK         (BIT1)
#define     TLG1100_SOUND_DSMDAC_2CHAN_SHIFT        (1)
#define     TLG1100_SOUND_DSMDAC_ENABLE_MASK        (BIT0)
#define     TLG1100_SOUND_DSMDAC_ENABLE_SHIFT       (0)
#define TLG1100_MODES                                                   (0x0098)
#define     TLG1100_MODES_ALT_MASK                  (BIT3_0)
#define     TLG1100_MODES_ALT_SHIFT                 (0)
#define     TLG1100_MODES_ALT_ADC                   (2)
#define TLG1100_GPIO_OUTPUT                                             (0x009d)
#define     TLG1100_GPIO_OUTPUT_USER_MASK           (BIT3|BIT2|BIT1)
#define     TLG1100_GPIO_OUTPUT_USER_SHIFT          (1)
#define TLG1100_GPIO_ENABLE                                             (0x009e)
#define     TLG1100_GPIO_ENABLE_USER_MASK           (BIT3|BIT2|BIT1)
#define     TLG1100_GPIO_ENABLE_USER_SHIFT          (1)
/*
 * Registers 0x0100 - 0x0148 are Read Only:
 * - should be read with TLG_ReadRegNS()
 * - they should not be written
 */
#define TLG1100_ATOP_ADCCAL_STATUS1                                     (0x0100)
#define     TLG1100_ATOP_ADCCAL_COEF_10_MASK        (BIT11_0)
#define     TLG1100_ATOP_ADCCAL_COEF_10_SHIFT       (0)
#define TLG1100_ATOP_ADCCAL_STATUS12                                    (0x010b)
#define TLG1100_ATOP_AGCCAL_STATUS2                                     (0x010d)
#define     TLG1100_ATOP_AGCCAL_LOOP2_ACC_MASK      (BIT15_12|BIT11|BIT10)
#define     TLG1100_ATOP_AGCCAL_LOOP2_ACC_SHIFT     (10)
#define TLG1100_ATOP_AGCCAL_STATUS3                                     (0x010e)
#define     TLG1100_ATOP_AGCCAL_LOOP1_ACC_MASK      (BIT15_12|BIT11)
#define     TLG1100_ATOP_AGCCAL_LOOP1_ACC_SHIFT     (11)
#define TLG1100_ATOP_FILCAL_STATUS1                                     (0x0111)
#define     TLG1100_ATOP_FILCAL_STATUS1_RCAL_MASK_1_2   (BIT7_4|BIT3)
#define     TLG1100_ATOP_FILCAL_STATUS1_RCAL_SHIFT_1_2  (3)
#define     TLG1100_ATOP_FILCAL_STATUS1_RCAL_MASK_1_1   (BIT7_4)
#define     TLG1100_ATOP_FILCAL_STATUS1_RCAL_SHIFT_1_1  (4)
#define TLG1100_LNACAL_STAT1                                            (0x0113)
#define     TLG1100_LNA1_GAIN_MASK_1_1              (BIT1|BIT0)
#define     TLG1100_LNA1_GAIN_SHIFT_1_1             (0)
#define TLG1100_LNACAL_STAT2                                            (0x0114)
#define     TLG1100_LNA2_GAIN_MASK                  (BIT12_9)
#define     TLG1100_LNA2_GAIN_SHIFT                 (9)
#define TLG1100_LNACAL_STAT3                                            (0x0115)
#define TLG1100_ATOP_TRKFIL_CAL_STATUS6                                 (0x011c)
#define TLG1100_TONE_NOTCH_STAT2                                        (0x0120)
#define     TLG1100_TONE_NOTCH_STAT2_AVG_MAG_MASK   (BIT11_0) 
#define     TLG1100_TONE_NOTCH_STAT2_AVG_MAG_SHIFT  (0)
#define TLG1100_PEAK_RMS_AGC_STAT3                                      (0x0123)
#define TLG1100_LUMA_PLL_STAT2                                          (0x0129)
#define TLG1100_VSYNC_STAT2                                             (0x0132)
#define TLG1100_VIDSTAT2                                                (0x0139)
#define     TLG1100_LNA1_GAIN_MASK_1_2              (BIT10|BIT9)
#define     TLG1100_LNA1_GAIN_SHIFT_1_2             (9)
#define TLG1100_LOCK_DETECTOR                                           (0x013b)
#define     TLG1100_VSYNC_SLOCK                     (BIT6)
#define     TLG1100_VSYNC_LOCK                      (BIT5)
#define     TLG1100_VSYNC_LOCK_SHIFT                (5)
#define     TLG1100_VID_LOCK                        (BIT4)
#define     TLG1100_SOUND_LOCK                      (BIT3)
#define     TLG1100_SOUND_LOCK_SHIFT                (3)
#define     TLG1100_CHROMA_LOCK                     (BIT2)
#define     TLG1100_LUMA_LOCK                       (BIT1)
#define     TLG1100_HSYNC_LOCK                      (BIT0)
#define     TLG1100_LOCK_MASK                       (BIT6|BIT5|BIT4|BIT3_0)
#define     TLG1100_LOCK_SHIFT                      (0)
#define TLG1100_MXS_POWER                                               (0x0180)
#define     TLG1100_LNA_MODE_MASK                   (BIT13|BIT14|BIT15)
#define     TLG1100_LNA_MODE_SHIFT                  (13) 
#define TLG1100_SYN_VCO_PWR                                             (0x0181)
#define TLG1100_UHF_CAL_OVERRIDE                                        (0x0184)
#define     TLG1100_UHF_CAL_OVERRIDE_AGC_MASK       (BIT9)
#define     TLG1100_UHF_CAL_OVERRIDE_AGC_SHIFT      (9)
#define     TLG1100_UHF_CAL_OVERRIDE_GAIN_MASK      (BIT8|BIT7_0)
#define     TLG1100_UHF_CAL_OVERRIDE_GAIN_SHIFT     (0)
#define TLG1100_UHF_BIAS_CONTROL                                        (0x0185)
#define     TLG1100_UHF_ATTEN_MASK                  (BIT9|BIT10|BIT11)
#define     TLG1100_UHF_ATTEN_SHIFT                 (9)
#define TLG1100_VHF2_FREQ_CONTROL                                       (0x0186)	
#define     TLG1100_VHF2_RCCAL_CAP_MASK             (BIT3_0)
#define     TLG1100_VHF2_RCCAL_CAP_SHIFT            (0)
#define TLG1100_VHF2_CAL_OVERRIDE                                       (0x0187)
#define     TLG1100_VHF2_CAL_OVERRIDE_RES_MASK      (BIT14_10)
#define     TLG1100_VHF2_CAL_OVERRIDE_RES_SHIFT     (10)
#define     TLG1100_VHF2_CAL_OVERRIDE_AGC_MASK      (BIT9)
#define     TLG1100_VHF2_CAL_OVERRIDE_AGC_SHIFT     (9)
#define     TLG1100_VHF2_CAL_OVERRIDE_GAIN_MASK     (BIT8|BIT7_0)
#define     TLG1100_VHF2_CAL_OVERRIDE_GAIN_SHIFT    (0)
#define TLG1100_VHF2_BIAS_CONTROL                                       (0x0188)
#define     TLG1100_VHF2_ATTEN_MASK                 (BIT9|BIT10|BIT11) 
#define     TLG1100_VHF2_ATTEN_SHIFT                (9)
#define TLG1100_VHF1_FREQ_CONTROL                                       (0x0189)
#define     TLG1100_VHF1_FREQ_CTL_KILL_H5_MASK      (BIT6)	
#define     TLG1100_VHF1_FREQ_CTL_KILL_H5_SHIFT     (6)	
#define     TLG1100_VHF1_FREQ_CTL_KILL_H3_MASK      (BIT5)	
#define     TLG1100_VHF1_FREQ_CTL_KILL_H3_SHIFT     (5)	
#define     TLG1100_VHF1_RCCAL_CAP_MASK             (BIT3_0)
#define     TLG1100_VHF1_RCCAL_CAP_SHIFT            (0)
#define TLG1100_VHF1_CAL_OVERRIDE                                       (0x018a)
#define     TLG1100_VHF1_CAL_OVERRIDE_RES_MASK      (BIT14_10)
#define     TLG1100_VHF1_CAL_OVERRIDE_RES_SHIFT     (10)
#define     TLG1100_VHF1_CAL_OVERRIDE_AGC_MASK      (BIT9)
#define     TLG1100_VHF1_CAL_OVERRIDE_AGC_SHIFT     (9)
#define     TLG1100_VHF1_CAL_OVERRIDE_GAIN_MASK     (BIT8|BIT7_0)
#define     TLG1100_VHF1_CAL_OVERRIDE_GAIN_SHIFT    (0)
#define TLG1100_VHF1_BIAS_CONTROL                                       (0x018b)
#define     TLG1100_VHF1_ATTEN_MASK                 (BIT9|BIT10|BIT11) 
#define     TLG1100_VHF1_ATTEN_SHIFT                (9)
#define TLG1100_TRKCTRL                                                 (0x018d)
#define     TLG1100_TRKCTRL_CAL_EN                  (BIT15)
#define     TLG1100_TRKCTRL_CUR                     (BIT7)
#define     TLG1100_TRKCTRL_CAL_SETTING             (TLG1100_TRKCTRL_CAL_EN \
                                                    |TLG1100_TRKCTRL_CUR    \
                                                    |TLG1100_TRKCTRL_POWERUP_DAC)
#define     TLG1100_TRKCTRL_POWERUP_DAC             (BIT0)
#define TLG1100_VERS_CHECK                                              (0x018e)
#define     TLG1100_VERS_CHECK_REV_MASK             (BIT15_12)
#define     TLG1100_VERS_CHECK_REV_SHIFT            (12)
#define     TLG1100_VERS_CHECK_VER_MASK             (BIT11_8)
#define     TLG1100_VERS_CHECK_VER_SHIFT            (8)
#define     TLG1100_VERS_CHECK_NOREV                (0xf)
#define TLG1100_MIXER_BIAS                                              (0x018f)
#define     TLG1100_MIX_UHFSEL_MASK                 (BIT5)
#define     TLG1100_MIX_UHFSEL_SHIFT                (5)
#define TLG1100_BBFIL_BIAS                                              (0x0193)
#define     TLG1100_BBFIL_M6DB_MASK                 (BIT15)
#define     TLG1100_BBFIL_M6DB_SHIFT                (15)
#define TLG1100_ADC_BIAS                                                (0x0198)
#define     TLG1100_ADC_NULL_MASK                   (BIT8)
#define     TLG1100_ADC_NULL_SHIFT                  (8)
#define TLG1100_SYN_NDIVIDER                                            (0x01a5)
#define	TLG1100_SYN_RDIVIDER                                            (0x01a6)
#define TLG1100_SYN_CTRL                                                (0x01a7)
#define     TLG1100_SYN_CTRL_RST_MASK               (BIT8)
#define TLG1100_SYN_REGULATOR                                           (0x01a8)
#define     TLG1100_SYN_REGULATOR_VOLT_MASK         (BIT11_9)
#define     TLG1100_SYN_REGULATOR_VOLT_SHIFT        (9)
/* 0x01b0 is Read Only */
#define TLG1100_VCO_BS_STAT                                             (0x01b0)
#define     TLG1100_SYNTH_LOCK_MASK                 (BIT12)
#define     TLG1100_SYNTH_LOCK_SHIFT                (12)
#define     TLG1100_VCO_BS_CODE_MASK                (BIT6_0)
#define     TLG1100_VCO_BS_CODE_SHIFT               (0)
#define TLG1100_VCOL_BS_NLO                                             (0x01b2)
#define TLG1100_VCOL_BS_NHI                                             (0x01b3)
#define     TLG1100_VCOL_BS_VALUE_MASK              (0x3fff)



#endif /* _TLG1100HAL_H_ */
