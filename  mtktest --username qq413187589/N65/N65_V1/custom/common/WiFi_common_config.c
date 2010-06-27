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
 *  wndrv_rf_ah.c
 *
 * Project:
 * --------
 *  Maui_Software
 *
 * Description:
 * ------------
 *  Airoha RF related Functions
 *
 * Author:
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __MTK_TARGET__
#if defined(__WIFI_SUPPORT__)
/*******************************************************************************
*                E X T E R N A L   R E F E R E N C E S
********************************************************************************
*/
#include "precomp.h"

/*******************************************************************************
*                                      RF part
********************************************************************************
*/
/*******************************************************************************
*                                      AL2236
********************************************************************************
*/

/*******************************************************************************
*                          C O N S T A N T S
********************************************************************************
*/
/* PAU MPDR parameters */
#define PAU_MAC_PROC_DELAY_1_AIROHA             NSEC_TO_MCR_TIMING(1500)    /* M1 = 1.5 us */
#define PAU_MAC_PROC_DELAY_2_AIROHA             NSEC_TO_MCR_TIMING(300)     /* M2 = 0.3 us */
#define PAU_RX_PLCP_DELAY_AIROHA                NSEC_TO_MCR_TIMING(5000)    /* RxPLCPDelay = 5 us */

#define PAU_MPDR_AIROHA                         ((PAU_MAC_PROC_DELAY_1_AIROHA & MPDR_MAC_PRC_DELAY_1) | \
                                                ((PAU_RX_PLCP_DELAY_AIROHA << 8) & MPDR_RX_PLCP_DELAY) | \
                                                ((PAU_MAC_PROC_DELAY_2_AIROHA << 16) & MPDR_MAC_PRC_DELAY_2))

/* PAU slot time related parameters */
#define PAU_TX_SIFS_TX_AIROHA_LONG_SLOT         NSEC_TO_MCR_TIMING(5700)    /* TxSIFSTx = 5.7 us */
#define PAU_TX_SIFS_TX_AIROHA_SHORT_SLOT        NSEC_TO_MCR_TIMING(5700)    /* TxSIFSTx = 5.7 us */

#define PAU_TX_PIFS_CCA_AIROHA_LONG_SLOT        NSEC_TO_MCR_TIMING(25400)   /* TxPIFSCCA = 25.4 us */
#define PAU_TX_PIFS_CCA_AIROHA_SHORT_SLOT       NSEC_TO_MCR_TIMING(14400)   /* TxPIFSCCA = 14.4 us */

#define PAU_SLOT_TIME_1_AIROHA_LONG_SLOT        NSEC_TO_MCR_TIMING(20400)   /* SlotTime1 = 20.4 us */
#define PAU_SLOT_TIME_1_AIROHA_SHORT_SLOT       NSEC_TO_MCR_TIMING(9400)    /* SlotTime1 = 9.4 us */

#define PAU_SLOT_TIME_2_AIROHA_LONG_SLOT        NSEC_TO_MCR_TIMING(20000)   /* SlotTime2 = 20 us */
#define PAU_SLOT_TIME_2_AIROHA_SHORT_SLOT       NSEC_TO_MCR_TIMING(9000)    /* SlotTime2 = 9 us */

#define PAU_TNTDR_AIROHA_LONG_SLOT              ((PAU_TX_SIFS_TX_AIROHA_LONG_SLOT & TNTDR_TX_SIFS_TX) | \
                                                ((PAU_TX_PIFS_CCA_AIROHA_LONG_SLOT << 16) & TNTDR_TX_PIFS_CCA))
#define PAU_TNTDR_AIROHA_SHORT_SLOT             ((PAU_TX_SIFS_TX_AIROHA_SHORT_SLOT & TNTDR_TX_SIFS_TX) | \
                                                ((PAU_TX_PIFS_CCA_AIROHA_SHORT_SLOT << 16) & TNTDR_TX_PIFS_CCA))

#define PAU_STDR_AIROHA_LONG_SLOT               ((PAU_SLOT_TIME_1_AIROHA_LONG_SLOT & STDR_SLOT_TIME_1) | \
                                                ((PAU_SLOT_TIME_2_AIROHA_LONG_SLOT << 16) & STDR_SLOT_TIME_2))
#define PAU_STDR_AIROHA_SHORT_SLOT              ((PAU_SLOT_TIME_1_AIROHA_SHORT_SLOT & STDR_SLOT_TIME_1) | \
                                                ((PAU_SLOT_TIME_2_AIROHA_SHORT_SLOT << 16) & STDR_SLOT_TIME_2))

/* PAU PPORCR parameters */
#define PAU_TX_PE_ON_AIROHA_2230                NSEC_TO_MCR_TIMING(1600)    /* TXPEOn = 1.6 us */
#define PAU_TX_RX_ON_AIROHA_2230                NSEC_TO_MCR_TIMING(0)       /* TXRXOn = 0 us */
#define PAU_TR_SW_ON_AIROHA_2230                NSEC_TO_MCR_TIMING(3400)    /* TRSWOn = 3.4 us */
#define PAU_PA_PE_ON_AIROHA_2230                NSEC_TO_MCR_TIMING(3400)    /* PAPEOn = 3.4 us */

#define PAU_PPORCR0_AIROHA_2230                 ((PAU_TX_PE_ON_AIROHA_2230 & PPORCR0_TX_PE_ON) | \
                                                ((PAU_TX_RX_ON_AIROHA_2230 << 16) & PPORCR0_TX_RX_ON))
#define PAU_PPORCR1_AIROHA_2230                 ((PAU_TR_SW_ON_AIROHA_2230 & PPORCR1_TR_SW_ON) | \
                                                ((PAU_PA_PE_ON_AIROHA_2230 << 16) & PPORCR1_PA_PE_ON))

/* PAU PPDRCR parameters */
#define PAU_TX_PE_OFF_AIROHA_2230               NSEC_TO_MCR_TIMING(500)     /* TXPEOff = 0.5 us */
#define PAU_TX_RX_OFF_AIROHA_2230               NSEC_TO_MCR_TIMING(750)     /* TXRXOff = 1 us */
#define PAU_TR_SW_OFF_AIROHA_2230               NSEC_TO_MCR_TIMING(750)     /* TRSWOff = 1 us */
#define PAU_PA_PE_OFF_AIROHA_2230               NSEC_TO_MCR_TIMING(500)     /* PAPEOff = 1 us */
#define PAU_RX_PE_ON_AIROHA_2230                NSEC_TO_MCR_TIMING(4000)    /* RXPEOn = 4 us */

#define PAU_PPDRCR0_AIROHA_2230                 ((PAU_TX_PE_OFF_AIROHA_2230 & PPDRCR0_TX_PE_OFF) | \
                                                ((PAU_TX_RX_OFF_AIROHA_2230 << 16) & PPDRCR0_TX_RX_OFF))
#define PAU_PPDRCR1_AIROHA_2230                 ((PAU_TR_SW_OFF_AIROHA_2230 & PPDRCR1_TR_SW_OFF) | \
                                                ((PAU_PA_PE_OFF_AIROHA_2230 << 16) & PPDRCR1_PA_PE_OFF))
#define PAU_PPDRCR2_AIROHA_2230                 (PAU_RX_PE_ON_AIROHA_2230 & PPDRCR2_RX_PE_ON)

/* RF initialization wait delay */
#define RF_INIT_WAIT_DELAY_AIROHA               0       /* us */

/* ED adjustment related parameters */
#define RSSI_AT_NOISE_FLOOR_BASELINE_AIROHA_24  -74     /* dBm */

/* Tx power gain default settings */
#define TX_POWER_GAIN_AIROHA_CCK                0x26
#define TX_POWER_GAIN_AIROHA_OFDM_24            0x30

#define TX_POWER_GAIN_AH2236_CCK_LOWER_BOUND 0
#define TX_POWER_GAIN_AH2236_CCK_UPPER_BOUND 0x3F
#define TX_POWER_GAIN_AH2236_OFDM_LOWER_BOUND 0
#define TX_POWER_GAIN_AH2236_OFDM_UPPER_BOUND 0x3F
#define TX_POWER_GAIN_AH2236_CCK_INIT_LEAP 2
#define TX_POWER_GAIN_AH2236_OFDM_INIT_LEAP 2

/* Tx power gain step: 0.5 dB/step */
#define TX_POWER_GAIN_STEP_AIROHA_NUM           1       /* numerator */
#define TX_POWER_GAIN_STEP_AIROHA_DENOM         2       /* denominator */

/* Coefficients of RSSI calculation equation (ratio 10000:1) */
#define RSSI_COEFF_A_AL2236_24                  -20873
#define RSSI_COEFF_BL_AL2236_24                 22200
#define RSSI_COEFF_BM_AL2236_24                 -130836
#define RSSI_COEFF_BH_AL2236_24                 -346691

#define RSSI_COEFF_A_2_AIROHA_24                -71
#define RSSI_COEFF_A_1_AIROHA_24                -18481
#define RSSI_COEFF_A_0_AIROHA_24                -298941
#define RSSI_COEFF_C_LNA_0_AIROHA_24            220000  /* for LNA=0 */
#define RSSI_COEFF_C_LNA_1_AIROHA_24            0       /* for LNA=1 */

/* Coefficients of link quality calculation equation (ratio 10000:1) */
#define LQ_COEFF_RSSI_AL2236_24                 14358
#define LQ_COEFF_HW_LQ_AL2236_24                16000
#define LQ_COEFF_CONST_AL2236_24                16562
#define LQ_COEFF_RSSI_AL2236_5                  19583
#define LQ_COEFF_HW_LQ_AL2236_5                 -200
#define LQ_COEFF_CONST_AL2236_5                 1852044

/* NIC power management wake-up time */
#define NIC_PM_WAKE_UP_TIME_AIROHA              500     /* us */

/*******************************************************************************
*                         D A T A   T Y P E S
********************************************************************************
*/

/*******************************************************************************
*                        P U B L I C   D A T A
********************************************************************************
*/
#if ( IS_RF_CHIP_AL2236 )
/* Airoha AL2236 */
/* PAU initial table for AL2236 RF chipsets in 2.4 GHz band */
static const NIC_MCR_CONFIG_ENTRY pauInitTableForAiroha2236_24[] = {
    {MCR_PCICR,     0x00000180},        //Initial PAEN polarity
    {MCR_PSCR,      0x39421222},        //SPI setting
    {MCR_PPORCR0,   PAU_PPORCR0_AIROHA_2230},
    {MCR_PPORCR1,   PAU_PPORCR1_AIROHA_2230},
    {MCR_PPDRCR0,   PAU_PPDRCR0_AIROHA_2230},
    {MCR_PPDRCR1,   PAU_PPDRCR1_AIROHA_2230},
    {MCR_PPDRCR2,   PAU_PPDRCR2_AIROHA_2230},
    {MCR_MPDR,      PAU_MPDR_AIROHA},
    {MCR_TNTDR,     PAU_TNTDR_AIROHA_LONG_SLOT},
    {MCR_STDR,      PAU_STDR_AIROHA_LONG_SLOT},
    {MCR_BGCR0,     (TX_POWER_GAIN_AIROHA_CCK << 8)},       //15-8: Beacon TX Power setting
    {MCR_RFTPCR,    (TX_POWER_GAIN_AIROHA_CCK | (TX_POWER_GAIN_AIROHA_OFDM_24 << 8))}   //15-8: OFDM RF power setting for ACK/CTS..., 7-0: CCK RF power setting for ACK/CTS
};

const NIC_BBCR_CONFIG_ENTRY phyBBInitTableForAiroha2236[] = {
    {81,  0x1b},  // bandgap current
    {83,  0xfb},  // TX DAC buffer current
    {84,  0x15},  // DAC common mode/gain mode
    {92,  0x41},  // RX ADC gain mode 1V
    {93,  0xa8},  // RX ADC bias current
    {94,  0x40},  // RX ADC common mode

    {45,  0x54},  // Target 1
    {46,  0x1c},
    {45,  0x55},  // Target 2
    {46,  0x1d},
    {45,  0x51},  // LNA thr  : G1 & G2 switch
    {46,  0x1f},
    {45,  0x52},  // LNA thr2 : low & middle switch
    {46,  0x1f},
    {45,  0x53},  // LNA thr3 : high & middle switch
    {46,  0x1b},
    {45,  0x56},  // G1 & G2
    {46,  0x90},
    {45,  0x57},  // G2 & G3
    {46,  0x10},
    {45,  0x58},  // G4 : for middle gain
    {46,  0x0b},
    {45,  0x00},  // op mode
    {46,  0x22},
    {45,  0x01},  // T1 , T2
    //{46,  0xf4},
    {46,  0x64},
    {45,  0x02},  // T3 , T4
    {46,  0x60},
    {45,  0x03},  // T5 , T6
    {46,  0x64},
    {45,  0x04},  // T7 , T8
    {46,  0x64},
    {45,  0x05},
    {46,  0x66},
    {45,  0x4C},
    {46,  0xD3},

/* for adjacent channel */
    {49,  0x4A},  // SQ1
    {50,  0xCA},  // SQ2
    {77,  0x94},  // OFDM OSD

    {45,  0x4b},  // Ed thr
    {46,  0x18},
    {45,  0x78},  // CCK thr
    {46,  0x07},
    {45,  0x79},  // OFDM thr
    {46,  0x07},
    {45,  0x77},  // CCK AR & OFDM AR
    {46,  0xa7},
    {45,  0x83},  // jmp_down_thr & jump_up_thr
    {46,  0x63},
    {45,  0x7d},  // LNA gain
    {46,  0x11},
    {45,  0x84},  // LNA middle gain
    {46,  0xe7},
    {45,  0x5b},  // ZC threshold
    {46,  0x10},
    {45,  0x82},  // IQ accumulation time
    {46,  0x12}
};

/* AL2236 RF initialization table for 2.4 GHz band */
const UINT_32 phyRFInitTableForAiroha2236_24[] = {
    0x800116C7,
    0x8000B802,
    0x8000E7F3,
    0x800905A4,
    0x800F4DC5,
    0x800805B6,
    0x800A0688,
    0x800543B9,
    0x80001BBA,
    0x80000F9B,
    0x80039D8C,
#ifdef __WIFI_OSC_26MHZ__
    0x8008080D,
#else
    0x8008000D,
#endif
    0x8000587F
};

#if SUPPORT_ED_ADJUST_MULTI_LEVEL_FLOAT_STATE
/* For ED Adjustment */
const ED_FLOATED_MARGIN_STRUC edFloatedMarginsForAiroha2230Ch7[ED_FLOAT_ED_LEVELS] = {
    {0x10, 0x16, 0x14},
    {0x18, 0x1a, 0x1a},
    {0x1f, 0x1f, 0x1f}
};

/* For ED Adjustment */
const ED_FLOATED_MARGIN_STRUC edFloatedMarginsForAiroha2230ChNone7[ED_FLOAT_ED_LEVELS] = {
    {0x10, 0x16, 0x12},
    {0x18, 0x1a, 0x1a},
    {0x1f, 0x1f, 0x1f}
};
#endif

#ifdef __WIFI_OSC_26MHZ__
/* AL2236 channel table for 2.4 GHz band, 26 Mhz reference clock */
const NIC_RF_CHANNEL_PROG_ENTRY phyRFChnlTableForAiroha2236_24[] = {
    { 1,    2,  { 0x8001F5D0, 0x80089D91, 0, 0 } },
    { 2,    2,  { 0x8001F5D0, 0x800EC4F1, 0, 0 } },
    { 3,    2,  { 0x8001E5D0, 0x8004EC51, 0, 0 } },
    { 4,    2,  { 0x8001E5D0, 0x800B13B1, 0, 0 } },
    { 5,    2,  { 0x8001F5E0, 0x80013B11, 0, 0 } },
    { 6,    2,  { 0x8001F5E0, 0x80076271, 0, 0 } },
    { 7,    2,  { 0x8001F5E0, 0x800D89E1, 0, 0 } },
    { 8,    2,  { 0x8001E5E0, 0x8003B141, 0, 0 } },
    { 9,    2,  { 0x8001E5E0, 0x8009D8A1, 0, 0 } },
    { 10,   2,  { 0x8001F5F0, 0x80000001, 0, 0 } },
    { 11,   2,  { 0x8001F5F0, 0x80062761, 0, 0 } },
    { 12,   2,  { 0x8001F5F0, 0x800C4EC1, 0, 0 } },
    { 13,   2,  { 0x8001E5F0, 0x80027621, 0, 0 } },
    { 14,   2,  { 0x8001F600, 0x80013B11, 0, 0 } }
};

#else

/* AL2236 channel table for 2.4 GHz band, 20 Mhz reference clock */
const NIC_RF_CHANNEL_PROG_ENTRY phyRFChnlTableForAiroha2236_24[] = {
    { 1,    2,  { 0x8001F790, 0x80033331, 0, 0 } },
    { 2,    2,  { 0x8001F790, 0x800B3331, 0, 0 } },
    { 3,    2,  { 0x8001E790, 0x80033331, 0, 0 } },
    { 4,    2,  { 0x8001E790, 0x800B3331, 0, 0 } },
    { 5,    2,  { 0x8001F7A0, 0x80033331, 0, 0 } },
    { 6,    2,  { 0x8001F7A0, 0x800B3331, 0, 0 } },
    { 7,    2,  { 0x8001E7A0, 0x80033331, 0, 0 } },
    { 8,    2,  { 0x8001E7A0, 0x800B3331, 0, 0 } },
    { 9,    2,  { 0x8001F7B0, 0x80033331, 0, 0 } },
    { 10,   2,  { 0x8001F7B0, 0x800B3331, 0, 0 } },
    { 11,   2,  { 0x8001E7B0, 0x80033331, 0, 0 } },
    { 12,   2,  { 0x8001E7B0, 0x800B3331, 0, 0 } },
    { 13,   2,  { 0x8001F7C0, 0x80033331, 0, 0 } },
    { 14,   2,  { 0x8001E7C0, 0x80066661, 0, 0 } }
};
#endif


static
VOID
phyRFInitForAiroha2236(IN PMP_ADAPTER adapter_p);

static
VOID
phyRFEnterActiveForAiroha2236(IN PMP_ADAPTER adapter_p);

static
VOID
phyRFEnterSleepForAiroha2236(IN PMP_ADAPTER adapter_p);

UINT_8
phyRFEnterActiveForAH2236Instructions(IN PMP_ADAPTER adapter_p,
                                      IN UINT        bufferLen,
                                      IN PUINT_32    bufferP);

UINT_8
phyRFEnterSleepForAH2236Instructions(IN PMP_ADAPTER adapter_p,
                                     IN UINT        bufferLen,
                                     IN PUINT_32    bufferP);

static
VOID
phyRFSwitchChannelForAiroha2236(IN PMP_ADAPTER                adapter_p,
                                IN PNIC_RF_CHANNEL_PROG_ENTRY entry_p);

static
VOID
phyRFSetRelTxpowForAiroha223x(IN PMP_ADAPTER pAdapter,
                              IN OUT PUINT_8      pu1Txpow,
                              OUT PUINT_8         pu1GainDiscount);

#if SUPPORT_ED_ADJUST_MULTI_LEVEL_FLOAT_STATE
static
BOOLEAN
edGetFloatedMarginsForAiroha2230(IN  PMP_ADAPTER adapter_p,
                                 IN  UINT        floatLevel,
                                 OUT PUINT_8     marginAGCED_p,
                                 OUT PUINT_8     marginCCK_p,
                                 OUT PUINT_8     marginOFDM_p);
#endif

/* NIC RF-specific configuration structure for Airoha AL2230 */
NIC_RF_SPECIFIC_CONFIG rfConfigAiroha2236 = {
    NIC_RF_AIROHA_2236,
    "Airoha AL2236",

    /* PAU initialization table */
    (PNIC_MCR_CONFIG_ENTRY) pauInitTableForAiroha2236_24,
    sizeof(pauInitTableForAiroha2236_24) / sizeof(NIC_MCR_CONFIG_ENTRY),
#if SUPPORT_802_11A
    NULL,
    0,
#endif

    /* PAU slot time settings */
    PAU_TNTDR_AIROHA_LONG_SLOT,
    PAU_STDR_AIROHA_LONG_SLOT,

    PAU_TNTDR_AIROHA_SHORT_SLOT,
    PAU_STDR_AIROHA_SHORT_SLOT,

    /* Baseband initialization table */
    (PNIC_BBCR_CONFIG_ENTRY) phyBBInitTableForAiroha2236,
    sizeof(phyBBInitTableForAiroha2236) / sizeof(NIC_BBCR_CONFIG_ENTRY),
    NULL,
    0,
#if SUPPORT_802_11A
    NULL,
    0,
#endif

    /* RF initialization table */
    NULL,
    0,
#if SUPPORT_802_11A
    NULL,
    0,
#endif
    /* RF initialization wait delay (in us) */
    RF_INIT_WAIT_DELAY_AIROHA,

    /* RF-specific handlers */
    phyRFInitForAiroha2236,
    phyRFEnterActiveForAiroha2236,
    phyRFEnterSleepForAiroha2236,
    phyRFSwitchChannelForAiroha2236,
#if SUPPORT_ED_ADJUST_MULTI_LEVEL_FLOAT_STATE
    NULL,
#endif

    /* RF channel programming table */
    (PNIC_RF_CHANNEL_PROG_ENTRY) phyRFChnlTableForAiroha2236_24,
    sizeof(phyRFChnlTableForAiroha2236_24) / sizeof(NIC_RF_CHANNEL_PROG_ENTRY),
#if SUPPORT_802_11A
    NULL,
    0,
#endif

    /* ED adjustment related parameters */
    RSSI_AT_NOISE_FLOOR_BASELINE_AIROHA_24,
#if SUPPORT_802_11A
    0,
#endif

    /* Default Tx power gain */
    TX_POWER_GAIN_AIROHA_CCK,
    TX_POWER_GAIN_AIROHA_OFDM_24,
#if SUPPORT_802_11A
    0,
#endif

    TX_POWER_GAIN_AH2236_CCK_LOWER_BOUND,
    TX_POWER_GAIN_AH2236_CCK_UPPER_BOUND,
    TX_POWER_GAIN_AH2236_OFDM_LOWER_BOUND,
    TX_POWER_GAIN_AH2236_OFDM_UPPER_BOUND,

    TX_POWER_GAIN_AH2236_CCK_INIT_LEAP,
    TX_POWER_GAIN_AH2236_OFDM_INIT_LEAP,

    /* Tx power gain step */
    TX_POWER_GAIN_STEP_AIROHA_NUM,
    TX_POWER_GAIN_STEP_AIROHA_DENOM,
#if MT5911_BB
    /* RSSI calculation related parameters */
    {RSSI_COEFF_A_AL2236_24,  RSSI_COEFF_A_AL2236_24},
    {RSSI_COEFF_BL_AL2236_24, RSSI_COEFF_BL_AL2236_24},
    {RSSI_COEFF_BM_AL2236_24, RSSI_COEFF_BM_AL2236_24},
    {RSSI_COEFF_BH_AL2236_24, RSSI_COEFF_BH_AL2236_24},
    /* Link quality calculation related parameters */
    {LQ_COEFF_RSSI_AL2236_24,  LQ_COEFF_RSSI_AL2236_5},
    {LQ_COEFF_HW_LQ_AL2236_24, LQ_COEFF_HW_LQ_AL2236_5},
    {LQ_COEFF_CONST_AL2236_24, LQ_COEFF_CONST_AL2236_5},
#else
    /* RSSI calculation related parameters */
    RSSI_COEFF_A_2_AIROHA_24,
    RSSI_COEFF_A_1_AIROHA_24,
    RSSI_COEFF_A_0_AIROHA_24,
    RSSI_COEFF_C_LNA_0_AIROHA_24,
    RSSI_COEFF_C_LNA_1_AIROHA_24,
#if SUPPORT_802_11A
    0,
    0,
    0,
    0,
    0,
#endif
#endif

    /* NIC power management wake-up time */
    NIC_PM_WAKE_UP_TIME_AIROHA,
#if SUPPORT_LOW_POWER
    phyRFEnterActiveForAH2236Instructions,
    phyRFEnterSleepForAH2236Instructions,
#endif
    phyRFSetRelTxpowForAiroha223x
};

#endif //( IS_RF_CHIP_AL2236 )

/*******************************************************************************
*                       P R I V A T E   D A T A
********************************************************************************
*/

/*******************************************************************************
*                             M A C R O S
********************************************************************************
*/

/*******************************************************************************
*              F U N C T I O N   D E C L A R A T I O N S
********************************************************************************
*/

/*******************************************************************************
*                          F U N C T I O N S
********************************************************************************
*/
#if ( IS_RF_CHIP_AL2236 )
/*******************************************************************************
**  phyAirohaCal2236
**
**  descriptions: This routine is called to do power on calibration for
**                  Airoha AL2236 RF chip.
**  parameters:
**      adapter_p - Pointer to the Adapter structure
**  return:         (none)
**  note:
*******************************************************************************/
VOID
phyAirohaCal2236(IN PMP_ADAPTER adapter_p)
{
    UINT    i;
    UINT_32 temp32;
    BOOLEAN status;
    UINT_8  oldCR84;
    UINT_8  oldCR82;
    UINT_8  oldCR88;

    /* power on calibration */
    NIC_MCR_RD(adapter_p, MCR_PPMCR, &temp32);
    temp32 |= PPMCR_GPIO_RF_SHDN;
    NIC_MCR_WR(adapter_p, MCR_PPMCR, temp32);

    for (i = 0; i < 3; i++) {
        kalUdelay(50);
    }

    BCIRead8(adapter_p, BBCR_CR84, &oldCR84, TRUE, 0xff);
    BCIRead8(adapter_p, BBCR_CR82, &oldCR82, TRUE, 0xff);
    BCIRead8(adapter_p, BBCR_CR88, &oldCR88, TRUE, 0xff);

    BCIWrite8(adapter_p, BBCR_CR85, 0x00 , TRUE, 0xff);
    BCIWrite8(adapter_p, BBCR_CR8, 0x80 , TRUE, 0xff);
    BCIWrite8(adapter_p, BBCR_CR82, 0x80, TRUE, 0xff);
    BCIWrite8(adapter_p, BBCR_CR84, (UINT_8) (oldCR84 | BIT(7)), TRUE, 0xff);
    BCIWrite8(adapter_p, BBCR_CR88, (UINT_8) (oldCR88 | BIT(7)), TRUE, 0xff);
    BCIWrite8(adapter_p, BBCR_CR88, oldCR88, TRUE, 0xff);

    /* TXDCOC */
    NIC_MCR_WR_AND_WAIT(adapter_p, MCR_PSPR, 0x8000D87F,
        PSPR_SYNTH_PROG_START, 2, 5, status);
    kalUdelay(50);

    /* IQ imbalance */
    NIC_MCR_WR_AND_WAIT(adapter_p, MCR_PSPR, 0x8000787F,
        PSPR_SYNTH_PROG_START, 2, 5, status);
    kalUdelay(50);


    NIC_MCR_WR_AND_WAIT(adapter_p, MCR_PSPR, 0x8000587F,
        PSPR_SYNTH_PROG_START, 2, 5, status);

    /* restore CR82, CR84 normal operation after calibration*/
    BCIWrite8(adapter_p, BBCR_CR84, oldCR84, TRUE, 0xff);
    BCIWrite8(adapter_p, BBCR_CR82, oldCR82, TRUE, 0xff);

}   /* phyAirohaCal2236 */

/*******************************************************************************
**  phyRFInitForAiroha2236
**
**  descriptions:
**      This routine is called to initialize Airoha 2236 RF chipset.
**  parameters:
**      adapter_p - Pointer to the Adapter structure
**  return:       (none)
**  note:
*******************************************************************************/
static
VOID
phyRFInitForAiroha2236(IN PMP_ADAPTER adapter_p)
{
    UINT_32 temp32;

    DEBUGFUNC("phyRFInitForAiroha2236");

    INITLOG(("\n"));

    /* Write the per-band RF initial table to the RF chipset. */
        if (adapter_p->rfInitSeqFromEEPROM) {
            /* Write the common RF initial table to the RF chipset. */
            phyWriteRFInitTable(adapter_p,
                                adapter_p->rfInitSeqs,
                                adapter_p->rfInitSeqNum,
                                RF_INIT_WAIT_DELAY_AIROHA);
        }
        else {
            /* Write the common RF initial table to the RF chipset. */
            phyWriteRFInitTable(adapter_p,
                                (PUINT_32) phyRFInitTableForAiroha2236_24,
                                sizeof(phyRFInitTableForAiroha2236_24) / sizeof(UINT_32),
                                RF_INIT_WAIT_DELAY_AIROHA);
        }

        phyRFSwitchChannelForAiroha2236(adapter_p,
               (PNIC_RF_CHANNEL_PROG_ENTRY)&phyRFChnlTableForAiroha2236_24[0]);

        NIC_MCR_RD(adapter_p, MCR_PPMCR, &temp32);
        temp32 |= PPMCR_GPIO_RF_SHDN;
        NIC_MCR_WR(adapter_p, MCR_PPMCR, temp32);

        /* post process for some RF init */
        phyAirohaCal2236(adapter_p);
}   /* phyRFInitForAiroha2236 */

/*******************************************************************************
**  phyRFEnterActiveForAiroha2236
**
**  descriptions: This routine is called to let Airoha RF chipset enter RF
**                active state.
**  parameters:
**      adapter_p - Pointer to the Adapter structure
**  return:       (none)
**  note:
*******************************************************************************/
static
VOID
phyRFEnterActiveForAiroha2236(IN PMP_ADAPTER adapter_p)
{
    UINT_32	temp32, status;
    DEBUGFUNC("phyRFEnterActiveForAiroha2236");

    DBGLOG(HW, TRACE, ("\n"));

    /*  RF leave deep sleep mode */
    NIC_MCR_WR_AND_WAIT(adapter_p, MCR_PSPR, 0x800116C7,
    PSPR_SYNTH_PROG_START, 2, 5, status);

    kalUdelay(250);

    /* power on RF */
    NIC_MCR_RD(adapter_p, MCR_PPMCR, &temp32);

    /* Set the SHDN bit of the PPMCR */
    temp32 |= PPMCR_GPIO_RF_SHDN;
    NIC_MCR_WR(adapter_p, MCR_PPMCR, temp32);

    /* for AL chipset need  stable time 400us from leave deep sleep mode  */
    kalUdelay(150);
}   /* phyRFEnterActiveForAiroha */

/*******************************************************************************
**  phyRFEnterSleepForAiroha2236
**
**  descriptions: This routine is called to let Airoha RF chipset enter RF
**                sleep state.
**  parameters:
**      adapter_p - Pointer to the Adapter structure
**  return:       (none)
**  note:
*******************************************************************************/
static
VOID
phyRFEnterSleepForAiroha2236(IN PMP_ADAPTER adapter_p)
{
    UINT_32 tmp32;

    DEBUGFUNC("phyRFEnterSleepForAiroha2236");

    DBGLOG(HW, TRACE, ("\n"));

    NIC_MCR_RD(adapter_p, MCR_PPMCR, &tmp32);
    /* Clear the GPIO_PE1 bit of the PPMCR */
    tmp32 &= ~PPMCR_GPIO_RF_SHDN;
    NIC_MCR_WR(adapter_p, MCR_PPMCR, tmp32);

    NIC_MCR_WR(adapter_p, MCR_PSPR, 0x800516C7);
}   /* phyRFEnterSleepForAiroha */

#if SUPPORT_LOW_POWER
/*******************************************************************************
**  phyRFEnterActiveForAH2236Instructions
**
**  descriptions: This routine is called to let Maxim RF chipset enter RF
**                active state.
**  parameters:
**      adapter_p - Pointer to the Adapter structure
**  return:       (none)
**  note:
*******************************************************************************/
UINT_8
phyRFEnterActiveForAH2236Instructions(IN PMP_ADAPTER adapter_p,
                                      IN UINT        bufferLen,
                                      IN PUINT_32    bufferP)
{
    UINT_32                    temp32;
    UINT_8                     index = 0;

    DEBUGFUNC("phyRFEnterActiveForAH2236Instructions");

    DBGLOG(HW, TRACE, ("\n"));

    if (adapter_p->RF_LDO_state & BIT(0)) {
        /*  RF leave deep sleep mode */
        bufferP[index] = LP_RFCR_WR(0x0116C7);
        index += 1;
        
        /* for airoha need 400 us delay for wakeup RF chip */
        bufferP[index] = LP_DELAY_US(250);
        index += 1;
    }
    /* Abort RF Idle mode. */
    NIC_MCR_RD(adapter_p, MCR_PPMCR, &temp32);
    /* Set the SHDN bit of the PPMCR */
    temp32 |= PPMCR_GPIO_RF_SHDN;
    LP_MCR_WR(MCR_PPMCR , temp32, bufferP[index], bufferP[index + 1]);
    index += 2;

     /* for AL chipset need  stable time 400us from leave deep sleep mode  */
     bufferP[index] = LP_DELAY_US(150);
     index += 1;

    ASSERT(bufferLen >= index);

    return index;
}   /* phyRFEnterActiveForAH2236Instructions */

/*******************************************************************************
**  phyRFEnterSleepForAH2236Instructions
**
**  descriptions: This routine is called to let Maxim RF chipset enter RF
**                sleep state.
**  parameters:
**      adapter_p - Pointer to the Adapter structure
**  return:       (none)
**  note:
*******************************************************************************/
UINT_8
phyRFEnterSleepForAH2236Instructions(IN PMP_ADAPTER adapter_p,
                                     IN UINT        bufferLen,
                                     IN PUINT_32    bufferP)
{
    UINT_32 tmp32;
    UINT_8  index = 0;

    DEBUGFUNC("phyRFEnterSleepForAH2236Instructions");

    DBGLOG(HW, TRACE, ("\n"));

    ASSERT(bufferLen);

    NIC_MCR_RD(adapter_p, MCR_PPMCR, &tmp32);
    /* Clear the SHDN bit of the PPMCR */
    tmp32 &= ~PPMCR_GPIO_RF_SHDN;
    LP_MCR_WR(MCR_PPMCR , tmp32, bufferP[index], bufferP[index+1]);
    index += 2;

    if (adapter_p->RF_LDO_state & BIT(0)) {
        /*  RF enter deep sleep mode */
        bufferP[index] = LP_RFCR_WR(0x516C7);
        index += 1;
    }
    return index;
}   /* phyRFEnterSleepForAH2236Instructions */
#endif

/*******************************************************************************
**  phyRFSwitchChannelForAiroha2236
**
**  descriptions: This routine is called to switch channel for Airoha RF
**                chipset.
**  parameters:
**      adapter_p - Pointer to the Adapter structure
**  return:         (none)
**  note:
*******************************************************************************/
static
VOID
phyRFSwitchChannelForAiroha2236(IN PMP_ADAPTER                adapter_p,
                                IN PNIC_RF_CHANNEL_PROG_ENTRY entry_p)
{
    UINT    i;
    BOOLEAN status;

    DEBUGFUNC("phyRFSwitchChannelForAiroha2236");

    DBGLOG(HW, TRACE, ("\n"));

    /* Program the synthesizer. */
    for (i = 0; i < entry_p->numSynthProgWords; i++) {
        NIC_MCR_WR_AND_WAIT(adapter_p, MCR_PSPR, entry_p->synthProgWords[i],
            PSPR_SYNTH_PROG_START, 2, 5, status);

        ASSERT(status);
    }

    /* Stall 150 us for synthesizer stable. */    
    kalUdelay(150);

}   /* phyRFSwitchChannelForAiroha2236 */


/*******************************************************************************
**  phyRFSetRelTxpowForAiroha223x
**
**  descriptions:
**      This routine is called to set the user configured Tx Power
**      level in percentage for Airoha RF chipset.
**  parameters:
**      adapter_p - Pointer to the Adapter structure
**      pu1Txpow - buffer of tx power level in percentage
**      pu1GainDiscount - buffer of tx power gain discount
**  return:
**      the real
**  note:
**      2232, 2236, and 2238 are supported.
*******************************************************************************/
static
VOID
phyRFSetRelTxpowForAiroha223x(IN  PMP_ADAPTER pAdapter,
                              IN  OUT PUINT_8 pu1Txpow,
                              OUT PUINT_8     pu1GainDiscount)
{
    if (*pu1Txpow == 100) {
        *pu1GainDiscount = 0;
    }
    else if (*pu1Txpow >= 50) {
        *pu1Txpow = 50;
        *pu1GainDiscount = 6;
    }
    else if (*pu1Txpow >= 25) {
        *pu1Txpow = 25;
        *pu1GainDiscount = 12;
    }
    else {
        *pu1Txpow = 0;
        /* use minimum gain */
        *pu1GainDiscount = 0xFF;
    }
} /* phyRFSetRelTxpowForAiroha223x */

#if SUPPORT_ED_ADJUST_MULTI_LEVEL_FLOAT_STATE
/*******************************************************************************
**  edGetFloatedMarginsForAiroha2230
**
**  descriptions: This routine is called to get a set of floated ED margins
**                for Airoha RF chipset.
**  parameters:
**      adapter_p - Pointer to the Adapter structure
**      floatLevel - The current ED float level
**  results:
**      marginAGCED_p - Pointer to the AGC ED margin
**      marginCCK_p - Pointer to the CCK margin
**      marginOFDM_p - Pointer to the OFDM margin
**  return:
**      FALSE
**  note:
*******************************************************************************/
static
BOOLEAN
edGetFloatedMarginsForAiroha2230(IN  PMP_ADAPTER adapter_p,
                                 IN  UINT        floatLevel,
                                 OUT PUINT_8     marginAGCED_p,
                                 OUT PUINT_8     marginCCK_p,
                                 OUT PUINT_8     marginOFDM_p)
{
    PED_FLOATED_MARGIN_STRUC entry_p;

    DEBUGFUNC("edGetFloatedMarginsForAiroha2230");

    DBGLOG(HW, INFO, ("\n"));

    if (MP_TEST_FLAG(adapter_p, MP_ADAPTER_FLAG_LINK_DETECTION |
                                 MP_ADAPTER_FLAG_ON_LINE_SITE_SURVEY |
                                 MP_ADAPTER_FLAG_DEDICATED_MEASUREMENT)) {
        return FALSE;
    } else {
        if (adapter_p->mib.dot11CurrentChannel  == 7) {
             entry_p =
                 (PED_FLOATED_MARGIN_STRUC) &edFloatedMarginsForAiroha2230Ch7[floatLevel];
        } else {
            entry_p =
                 (PED_FLOATED_MARGIN_STRUC) &edFloatedMarginsForAiroha2230ChNone7[floatLevel];
        }
    }

    *marginAGCED_p = entry_p->AGCEDMargin;
    *marginCCK_p = entry_p->CCKMargin;
    *marginOFDM_p = entry_p->OFDMMargin;

    return TRUE;
}   /* edGetFloatedMarginsForAiroha2230 */
#endif
#endif //( IS_RF_CHIP_AL2236 )

/*******************************************************************************
*                                      Other RF
********************************************************************************
*/

/*******************************************************************************
*                                      Other parts
********************************************************************************
*/
#endif //(__WIFI_SUPPORT__)
#endif