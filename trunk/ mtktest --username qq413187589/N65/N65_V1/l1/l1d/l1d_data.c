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

/*******************************************************************************
 *
 * Filename:
 * ---------
 *	l1d_data.c
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   Definition of global data & tables used in L1D
 *
 * Author:
 * -------
 * -------
 *
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
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *******************************************************************************/

#include  "l1d_cid.h"
#include  "l1d_reg.h"
#include  "l1d_data.h"
#include  "l1d_custom_rf.h"
#include  "l1d_rf.h"
#include  "m12190.h"

/* ========================================================================= */

typedef  unsigned char    uint8;
typedef  unsigned short   uint16;
typedef  unsigned long    uint32;
typedef    signed char    int8;
typedef    signed short   int16;
typedef    signed long    int32;

/* ========================================================================= */

#define  TQ_FBWIN_START_OFFSET   (TQ_SR1+TQ_SBWIN_DSP_EXTEND1+TQ_BURST_HEAD_GUARD)
#define  TQ_FSWIN_DTIRQ_DELAY    ((TQ_SLOT_LEN-TQ_FBWIN_START_OFFSET-TQ_SBWIN_DSP_EXTEND2)/2)
/* ========================================================================= */


/* ========================================================================= */
/* #if  (IS_CHIP_MT6205)||(IS_CHIP_MT6208)||(IS_FPGA_TARGET) */
/*--------------------------------------------------------*/
/*   RX GAIN SETTING                                      */
/*--------------------------------------------------------*/
/* Value | Single-End_Voltage  |                          */
/*-------+---------------------|                          */
/*   0   |     AVDD*0.8        |                          */
/*   1   |     AVDD*0.4        |                          */
/*--------------------------------------------------------*/

#if   BBRX_GAIN_DOUBLE==0
   #define RX_GAIN_SE  (float)0.8
#elif BBRX_GAIN_DOUBLE==1
   #define RX_GAIN_SE  (float)0.4
#endif

#if  (IS_CHIP_MT6205A)||(IS_CHIP_MT6208)||(IS_FPGA_TARGET)||(IS_CHIP_MT6218A)||(IS_CHIP_MT6218B)||(IS_CHIP_MT6219)||(IS_CHIP_MT6228)||(IS_CHIP_MT6227)||(IS_CHIP_MT6229)||(IS_CHIP_MT6225)||(IS_CHIP_MT6268T)||(IS_CHIP_MT6223)||(IS_CHIP_MT6238)
/*----------------------------------------------*/
/*                  BBTX_GAIN                   */
/*----------------------------------------------*/
/* Value | Output Swing || Value | Output Swing */
/*-------+--------------||-------+--------------*/
/*   3   |  AVDD*0.900  ||   7   |  AVDD*0.360  */
/*   2   |  AVDD*0.720  ||   6   |  AVDD*0.288  */
/*   1   |  AVDD*0.576  ||   5   |  AVDD*0.225  */
/*   0   |  AVDD*0.450  ||   4   |  AVDD*0.180  */
/*----------------------------------------------*/

#if   BBTX_GAIN==3
   #define TX_GAIN_DIFF  (float)0.900
#elif BBTX_GAIN==2
   #define TX_GAIN_DIFF  (float)0.720
#elif BBTX_GAIN==1
   #define TX_GAIN_DIFF  (float)0.576
#elif BBTX_GAIN==0
   #define TX_GAIN_DIFF  (float)0.450
#elif (BBTX_GAIN==-1)||(BBTX_GAIN==7)
   #define TX_GAIN_DIFF  (float)0.360
#elif (BBTX_GAIN==-2)||(BBTX_GAIN==6)
   #define TX_GAIN_DIFF  (float)0.288
#elif (BBTX_GAIN==-3)||(BBTX_GAIN==5)
   #define TX_GAIN_DIFF  (float)0.225
#elif (BBTX_GAIN==-4)||(BBTX_GAIN==4)
   #define TX_GAIN_DIFF  (float)0.180
#endif

#endif

#if  (IS_CHIP_MT6205B)
/*----------------------------------------------*/
/*                  BBTX_GAIN                   */
/*----------------------------------------------*/
/* Value | Output Swing || Value | Output Swing */
/*-------+--------------||-------+--------------*/
/*   3   |  AVDD*0.53   ||   7   |  AVDD*0.38   */
/*   2   |  AVDD*0.49   ||   6   |  AVDD*0.36   */
/*   1   |  AVDD*0.46   ||   5   |  AVDD*0.33   */
/*   0   |  AVDD*0.41   ||   4   |  AVDD*0.31   */
/*----------------------------------------------*/

#if   BBTX_GAIN==3
   #define TX_GAIN_DIFF  (float)0.53
#elif BBTX_GAIN==2
   #define TX_GAIN_DIFF  (float)0.49
#elif BBTX_GAIN==1
   #define TX_GAIN_DIFF  (float)0.46
#elif BBTX_GAIN==0
   #define TX_GAIN_DIFF  (float)0.41
#elif (BBTX_GAIN==-1)||(BBTX_GAIN==7)
   #define TX_GAIN_DIFF  (float)0.38
#elif (BBTX_GAIN==-2)||(BBTX_GAIN==6)
   #define TX_GAIN_DIFF  (float)0.36
#elif (BBTX_GAIN==-3)||(BBTX_GAIN==5)
   #define TX_GAIN_DIFF  (float)0.33
#elif (BBTX_GAIN==-4)||(BBTX_GAIN==4)
   #define TX_GAIN_DIFF  (float)0.31
#endif

#endif



/*...........................................................................*/
/*OSREQ*/ #ifdef __MTK_TARGET__
/*OSREQ*/ #pragma arm section rwdata = "INTERNRW" , rodata = "INTERNCONST" , zidata = "INTERNZI"
/*OSREQ*/ #endif /* __MTK_TARGET__ */
/*...........................................................................*/

#if IS_CHIP_MT6218_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION /* 14-bit RXADC */
/*MT6218~*/ const  float bb_cali_scale=((2*RX_GAIN_SE/16383)/(TX_GAIN_DIFF/1023));
#else                                 /* 11-bit RXADC */
/*OTHER*/   const  float bb_cali_scale=((2*RX_GAIN_SE/2047)/(TX_GAIN_DIFF/1023));
#endif

#if IS_CHIP_MT6238
   const signed long bb_tx_opt_swing_dac_sqr=((BBTX_GAIN_SWING*5420)/(2*1120))*((BBTX_GAIN_SWING*5420)/(2*1120));    //MT6238 Rx ADC short of 2dB
#elif IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION || IS_CHIP_MT6225_AND_LATTER_VERSION
   const signed long bb_tx_opt_swing_dac_sqr=((BBTX_GAIN_SWING*6912)/(2*1120))*((BBTX_GAIN_SWING*6912)/(2*1120));
#elif IS_CHIP_MT6218B_AND_LATTER_VERSION
   const signed long bb_tx_opt_swing_dac_sqr=((BBTX_GAIN_SWING*5184)/(2*1120))*((BBTX_GAIN_SWING*5184)/(2*1120));
#endif

/*----------------------------------------*/
/* Calibration data for round trip delay  */
/*----------------------------------------*/
#ifdef  L1D_SIM
const  short  TxPropagationDelay = 0;
#else
const  short  TxPropagationDelay = TX_PROPAGATION_DELAY;
#endif

/*----------------------------------------*/
/* data for BFE setting                   */
/*----------------------------------------*/
const unsigned char bbrx_iq_swap               = (0x01& BBRX_IQ_SWAP              );
const unsigned char bbrx_gain_double           = (0x01& BBRX_GAIN_DOUBLE          );
const unsigned char bbtx_iq_swap               = (0x01& BBTX_IQ_SWAP              );
const unsigned char bbtx_calrcsel              = (0x07& BBTX_CALRCSEL             );
const unsigned char bbtx_calbias               = (0x1F& BBTX_CALBIAS              );
const unsigned char bbtx_common_mode_voltage   = (0x07& BBTX_COMMON_MODE_VOLTAGE  );
const unsigned char bbtx_gain                  = (0x07& BBTX_GAIN                 );
const unsigned char bbtx_trim_i                = (0x0F& BBTX_TRIM_I               );
const unsigned char bbtx_trim_q                = (0x0F& BBTX_TRIM_Q               );
#if  IS_CHIP_MT6225_AND_LATTER_VERSION || IS_SAIC_CHIP_MT6223_AND_LATTER_VERSION
const unsigned char bbtx_dccoarse_i            = (0x03& BBTX_DCCOARSE_I           );
const unsigned char bbtx_dccoarse_q            = (0x03& BBTX_DCCOARSE_Q           );
#endif
const unsigned char bbtx_offset_i              = (0x3F& BBTX_OFFSET_I             );
const unsigned char bbtx_offset_q              = (0x3F& BBTX_OFFSET_Q             );
#if  IS_EDGE_SAIC_CHIP_MT6238_AND_LATTER_VERSION
const unsigned char bbtx_phsel                 = (0x0F& BBTX_PHSEL                );
#else
const unsigned char bbtx_phsel                 = (0x07& BBTX_PHSEL                );
#endif

#if  IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
const unsigned char bbtx_calrcsel_h            = (0x07& BBTX_CALRCSEL_H           );
const unsigned char bbtx_common_mode_voltage_h = (0x07& BBTX_COMMON_MODE_VOLTAGE_H);
const unsigned char bbtx_gain_h                = (0x07& BBTX_GAIN_H               );
const unsigned char bbtx_trim_i_h              = (0x0F& BBTX_TRIM_I_H             );
const unsigned char bbtx_trim_q_h              = (0x0F& BBTX_TRIM_Q_H             );
   #if IS_SAIC_CHIP_MT6223_AND_LATTER_VERSION
const unsigned char bbtx_dccoarse_i_h          = (0x03& BBTX_DCCOARSE_I_H         );
const unsigned char bbtx_dccoarse_q_h          = (0x03& BBTX_DCCOARSE_Q_H         );
   #endif
const unsigned char bbtx_offset_i_h            = (0x3F& BBTX_OFFSET_I_H           );
const unsigned char bbtx_offset_q_h            = (0x3F& BBTX_OFFSET_Q_H           );
#if  IS_EDGE_SAIC_CHIP_MT6238_AND_LATTER_VERSION
const unsigned char bbtx_phsel_h               = (0x0F& BBTX_PHSEL_H              );
#else
const unsigned char bbtx_phsel_h               = (0x07& BBTX_PHSEL_H              );
#endif
   #if (!IS_CHIP_MT6223) /*MT6223 don't support 8PSK*/
const unsigned char bbtx_rpsel                 = (0x03& BBTX_RPSEL                );
const unsigned char bbtx_inten                 = (0x01& BBTX_INTEN                );
const unsigned char bbtx_sw_qbcnt              = (0x1F& BBTX_SW_QBCNT             );
   #endif
#endif

#if  IS_CHIP_MT6227
const unsigned char bbtx_iqswap_onfly          = (0x01& BBTX_IQSWAP_ONFLY         );
#endif
/*----------------------------------------*/
/* data for BBTX setting                  */
/*----------------------------------------*/
#ifdef GSM850_IN_GSM900_PATH
#define  GSM850_GSM900_SWAP    GSM850_IN_GSM900_PATH
#endif
#ifndef  GSM850_GSM900_SWAP
#define  GSM850_GSM900_SWAP    0
#endif
#ifndef  DCS1800_PCS1900_SWAP
#define  DCS1800_PCS1900_SWAP  0
#endif


sBBTXParameters BBTXParameters =
{
   (0x07& BBTX_COMMON_MODE_VOLTAGE),
   (0x07& BBTX_GAIN),
   (0x07& BBTX_CALRCSEL),
   (0x0F& BBTX_TRIM_I),
   (0x0F& BBTX_TRIM_Q),
   (0x03& BBTX_DCCOARSE_I),
   (0x03& BBTX_DCCOARSE_Q),
   (0x3F& BBTX_OFFSET_I),
   (0x3F& BBTX_OFFSET_Q),
   0,   /* bbtx_isCalibrated */
   BAT_LOW_VOLTAGE,
   BAT_HIGH_VOLTAGE,
   BAT_LOW_TEMPERATURE,
   BAT_HIGH_TEMPERATURE,
   (0x07& BBTX_COMMON_MODE_VOLTAGE_H),
   (0x07& BBTX_GAIN_H),
   (0x07& BBTX_CALRCSEL_H),
   (0x0F& BBTX_TRIM_I_H),
   (0x0F& BBTX_TRIM_Q_H),
   (0x03& BBTX_DCCOARSE_I_H),
   (0x03& BBTX_DCCOARSE_Q_H),
   (0x3F& BBTX_OFFSET_I_H),
   (0x3F& BBTX_OFFSET_Q_H),
#if  IS_EDGE_SAIC_CHIP_MT6238_AND_LATTER_VERSION
   (0x0F& BBTX_PHSEL),
   (0x0F& BBTX_PHSEL_H),
#else
   (0x07& BBTX_PHSEL),
   (0x07& BBTX_PHSEL_H),
#endif
   (0x01& GSM850_GSM900_SWAP),
   (0x01& DCS1800_PCS1900_SWAP),
};

const  int     apc_bat_voltage_period = BAT_VOLTAGE_SAMPLE_PERIOD;
const  int     apc_bat_voltage_count = BAT_VOLTAGE_AVERAGE_COUNT;
const  int     apc_bat_temperature_period = BAT_TEMPERATURE_SAMPLE_PERIOD;
const  int     apc_bat_temperature_count = BAT_TEMPERATURE_AVERAGE_COUNT;

/*--------------------------------------------------------*/
/* data for BDL/BUL data                                  */
/*--------------------------------------------------------*/
const unsigned short bdlcon_data  = BDLCON_DATA;
const unsigned short bulcon1_data = BULCON1_DATA;
const unsigned short bulcon2_data = BULCON2_DATA;

/* ========================================================================= */

const   int16  TQ_Afc_ChargeInIdle = TQ_AFC_CHARGE_IN_IDLE;
const   int16  TQ_FBWin_Start_Offset = TQ_FBWIN_START_OFFSET;  /* 216 QB  */
const   int16  TQ_FSWin_DTIRQ_Delay  = TQ_FSWIN_DTIRQ_DELAY;   /* 190 QB  */
/* ========================================================================= */

const   int16  FrequencyBias = 0;
int16  AFC_Dac_TRx_Offset[5/*band*/] =
{  0, /* FrequencyBand400  */
   0, /* FrequencyBand850  */
   0, /* FrequencyBand900  */
   0, /* FrequencyBand1800 */
   0, /* FrequencyBand1900 */
};

/* ========================================================================= */
const  uint16  FM_DURATION = FM_DURATION_DEFAULT;
const  uint16  CLK_SETTLE  = CLK_SETTLE_DEFAULT;
/* ========================================================================= */

#ifndef  PDATA_GSM850_PR1
#define  PDATA_GSM850_PR1    0x00
#endif

#ifndef  PDATA_GSM850_PR2
#define  PDATA_GSM850_PR2    0x00
#endif

#ifndef  PDATA_GSM850_PR3
#define  PDATA_GSM850_PR3    0x00
#endif

#ifndef  PDATA_GSM850_PT1
#define  PDATA_GSM850_PT1    0x00
#endif

#ifndef  PDATA_GSM850_PT2
#define  PDATA_GSM850_PT2    0x00
#endif

#ifndef  PDATA_GSM850_PT3
#define  PDATA_GSM850_PT3    0x00
#endif

#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
const  int16  PDATA_TABLE[/*5*/][2][5] =
{     /* FrequencyBand400 (not support)  */
   {  { 0, 0, 0, 0 },
      { 0, 0, 0, 0 },
   }, /* FrequencyBand850  */
   {  {  PDATA_GSM850_PR1, PDATA_GSM850_PR2, PDATA_GSM850_PR2B, PDATA_GSM850_PR3, PDATA_GSM850_PR3A  } ,   /* RX */
      {  PDATA_GSM850_PT1, PDATA_GSM850_PT2, PDATA_GSM850_PT2B, PDATA_GSM850_PT3, PDATA_GSM850_PT3A  } ,   /* TX */
   }, /* FrequencyBand900  */
   {  {  PDATA_GSM_PR1, PDATA_GSM_PR2, PDATA_GSM_PR2B, PDATA_GSM_PR3, PDATA_GSM_PR3A  } ,            /* RX */
      {  PDATA_GSM_PT1, PDATA_GSM_PT2, PDATA_GSM_PT2B, PDATA_GSM_PT3, PDATA_GSM_PT3A  } ,            /* TX */
   }, /* FrequencyBand1800 */
   {  {  PDATA_DCS_PR1, PDATA_DCS_PR2, PDATA_DCS_PR2B, PDATA_DCS_PR3, PDATA_DCS_PR3A  } ,            /* RX */
      {  PDATA_DCS_PT1, PDATA_DCS_PT2, PDATA_DCS_PT2B, PDATA_DCS_PT3, PDATA_DCS_PT3A  } ,            /* TX */
   }, /* FrequencyBand1900 */
   {  {  PDATA_PCS_PR1, PDATA_PCS_PR2, PDATA_PCS_PR2B, PDATA_PCS_PR3, PDATA_PCS_PR3A  } ,            /* RX */
      {  PDATA_PCS_PT1, PDATA_PCS_PT2, PDATA_PCS_PT2B, PDATA_PCS_PT3, PDATA_PCS_PT3A  } ,            /* TX */
   }
};
#else
const  int16  PDATA_TABLE[/*5*/][2][3] =
{     /* FrequencyBand400 (not support)  */
   {  { 0, 0, 0 },
      { 0, 0, 0 },
   }, /* FrequencyBand850  */
   {  {  PDATA_GSM850_PR1, PDATA_GSM850_PR2, PDATA_GSM850_PR3  } ,   /* RX */
      {  PDATA_GSM850_PT1, PDATA_GSM850_PT2, PDATA_GSM850_PT3  } ,   /* TX */
   }, /* FrequencyBand900  */
   {  {  PDATA_GSM_PR1, PDATA_GSM_PR2, PDATA_GSM_PR3  } ,            /* RX */
      {  PDATA_GSM_PT1, PDATA_GSM_PT2, PDATA_GSM_PT3  } ,            /* TX */
   }, /* FrequencyBand1800 */
   {  {  PDATA_DCS_PR1, PDATA_DCS_PR2, PDATA_DCS_PR3  } ,            /* RX */
      {  PDATA_DCS_PT1, PDATA_DCS_PT2, PDATA_DCS_PT3  } ,            /* TX */
   }, /* FrequencyBand1900 */
   {  {  PDATA_PCS_PR1, PDATA_PCS_PR2, PDATA_PCS_PR3  } ,            /* RX */
      {  PDATA_PCS_PT1, PDATA_PCS_PT2, PDATA_PCS_PT3  } ,            /* TX */
   }
};
#endif

#if  IS_CHIP_MT6218_AND_LATTER_VERSION
/*MT6218~*/ const  int16  PDATA_TABLE2[5][2][2] =
/*MT6218~*/ {     /* FrequencyBand400 (not support)  */
/*MT6218~*/    {  { 0, 0 },
/*MT6218~*/       { 0    },
/*MT6218~*/    }, /* FrequencyBand850  */
/*MT6218~*/    {  {  PDATA_GSM850_PR2M1, PDATA_GSM850_PR2M2  } ,   /* RX */
/*MT6218~*/       {  PDATA_GSM850_PT2B                       } ,   /* TX */
/*MT6218~*/    }, /* FrequencyBand900  */
/*MT6218~*/    {  {  PDATA_GSM_PR2M1   , PDATA_GSM_PR2M2     } ,   /* RX */
/*MT6218~*/       {  PDATA_GSM_PT2B                          } ,   /* TX */
/*MT6218~*/    }, /* FrequencyBand1800 */
/*MT6218~*/    {  {  PDATA_DCS_PR2M1   , PDATA_DCS_PR2M2     } ,   /* RX */
/*MT6218~*/       {  PDATA_DCS_PT2B                          } ,   /* TX */
/*MT6218~*/    }, /* FrequencyBand1900 */
/*MT6218~*/    {  {  PDATA_PCS_PR2M1   , PDATA_PCS_PR2M2     } ,   /* RX */
/*MT6218~*/       {  PDATA_PCS_PT2B                          } ,   /* TX */
/*MT6218~*/    }
/*MT6218~*/ };
#endif
 
#if  IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
const  int16  PDATA_TABLE3[5][3][3] =
{     /* FrequencyBand400 (not support)  */
   {  { 0, 0 },
      { 0, 0 },
   }, /* FrequencyBand850  */
   {  {  PDATA_GSM850_PR2M1,    PDATA_GSM850_PR2M2,    PDATA_GSM850_PR2M3  } ,   /* RX */
      {  PDATA_GSM850_PT2M1_G8, PDATA_GSM850_PT2M2_G8, PDATA_GSM850_PT2M3_G8  } ,/* TX g8*/
      {  PDATA_GSM850_PT2M1_8G, PDATA_GSM850_PT2M2_8G, PDATA_GSM850_PT2M3_8G  } ,/* TX 8g*/
   }, /* FrequencyBand900  */
   {  {  PDATA_GSM_PR2M1   ,    PDATA_GSM_PR2M2     , PDATA_GSM_PR2M3     } ,    /* RX */
      {  PDATA_GSM_PT2M1_G8   , PDATA_GSM_PT2M2_G8  , PDATA_GSM_PT2M3_G8    } ,  /* TX g8*/
      {  PDATA_GSM_PT2M1_8G   , PDATA_GSM_PT2M2_8G  , PDATA_GSM_PT2M3_8G    } ,  /* TX 8g*/
   }, /* FrequencyBand1800 */                                                    
   {  {  PDATA_DCS_PR2M1   , PDATA_DCS_PR2M2, PDATA_DCS_PR2M3     } ,            /* RX */
      {  PDATA_DCS_PT2M1_G8   , PDATA_DCS_PT2M2_G8 , PDATA_DCS_PT2M3_G8     } ,  /* TX g8*/
      {  PDATA_DCS_PT2M1_8G   , PDATA_DCS_PT2M2_8G , PDATA_DCS_PT2M3_8G     } ,  /* TX 8g*/
   }, /* FrequencyBand1900 */
   {  {  PDATA_PCS_PR2M1   , PDATA_PCS_PR2M2   , PDATA_PCS_PR2M3     } ,         /* RX */
      {  PDATA_PCS_PT2M1_G8   , PDATA_PCS_PT2M2_G8   , PDATA_PCS_PT2M3_G8    } , /* TX g8*/
      {  PDATA_PCS_PT2M1_8G   , PDATA_PCS_PT2M2_8G   , PDATA_PCS_PT2M3_8G    } , /* TX 8g*/
   }
};
#endif
/*...........................................................................*/

const APBADDR  PDATA_REG_TABLE[/*4:5*/] =
{
   BPI_V( BPIDX(0,0) ),
   BPI_V( BPIDX(1,0) ),
   BPI_V( BPIDX(2,0) ),
   BPI_V( BPIDX(3,0) ),
#if  IS_GPRS
   BPI_V( BPIDX(4,0) ),
#endif
};

#if  IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
const APBADDR  PDATA_REG_TABLE2[/*4:5*/] =
{
   BPI_V( 35 ),
   BPI_V( 36 ),
   BPI_V( 37 ),
   BPI_V( 38 ),
#if  IS_GPRS
   BPI_V( 39 ),
#endif
};
#endif

#if  IS_CHIP_MT6218_AND_LATTER_VERSION
/*MT6218~*/ const APBADDR  PDATA_PT2B_REG_TABLE[2][3] =
/*MT6218~*/ {
/*MT6218~*/    { BPI_V( 20 ), BPI_V( 15 ), BPI_V( 21 ) },
/*MT6218~*/    { BPI_V( 16 ), BPI_V( 15 ), BPI_V( 17 ) },
/*MT6218~*/ };
/*MT6218~*/
/*MT6218~*/ const APBADDR  PDATA_PR2M_REG_TABLE[4] =
/*MT6218~*/ {
/*MT6218~*/    0,
/*MT6218~*/    BPI_V( 16 ),
/*MT6218~*/    BPI_V( 18 ),
/*MT6218~*/    BPI_V( 20 ),
/*MT6218~*/ };
#endif

#if  IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
const APBADDR  PDATA_PT2M_REG_TABLE[4] =
{
   0,
   BPI_V( 26 ), 
   BPI_V( 29 ), 
   BPI_V( 32 ),   
};

const APBADDR  PDATA_PR2M_REG_TABLE[4] =
{
   0,
   BPI_V( 20 ),
   BPI_V( 22 ),
   BPI_V( 24 ),
};
#endif

/*...........................................................................*/
#if  IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
#ifdef L1D_TEST
int16  RX_START_TQ_TABLE[8] =
{
   /* TQ_SLOT_BEGIN(i) + */ -TQ_SR1,               /* RX_START_CWIN_REG_TABLE[c][0]                   */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_PR1,               /* RX_START_CWIN_REG_TABLE[c][1]                   */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_PR2,               /* RX_START_CWIN_REG_TABLE[c][2]                   */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_PR2B,              /* RX_START_CWIN_REG_TABLE[c][3]                   */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_SR2,               /* RX_START_RIDX_REG_TABLE[i][0]                   */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_BDLON,             /* RX_START_RIDX_REG_TABLE[i][1]                   */
   /* TQ_SLOT_BEGIN(i) + */  TQ_MAXIMUM,           /* RX_START_RIDX_REG_TABLE[i][2] (for FBWIN_HEAD)  */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_AFC_READY,         /* RX_START_RIDX_REG_TABLE[i][3] (for FBWIN_HEAD)  */
};
#else
const int16  RX_START_TQ_TABLE[8] =
{
   /* TQ_SLOT_BEGIN(i) + */ -TQ_SR1,               /* RX_START_CWIN_REG_TABLE[c][0]                   */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_PR1,               /* RX_START_CWIN_REG_TABLE[c][1]                   */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_PR2,               /* RX_START_CWIN_REG_TABLE[c][2]                   */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_PR2B,              /* RX_START_CWIN_REG_TABLE[c][3]                   */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_SR2,               /* RX_START_RIDX_REG_TABLE[i][0]                   */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_BDLON,             /* RX_START_RIDX_REG_TABLE[i][1]                   */
   /* TQ_SLOT_BEGIN(i) + */  TQ_MAXIMUM,           /* RX_START_RIDX_REG_TABLE[i][2] (for FBWIN_HEAD)  */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_AFC_READY,         /* RX_START_RIDX_REG_TABLE[i][3] (for FBWIN_HEAD)  */
};
#endif

#elif IS_CHIP_MT6225_AND_LATTER_VERSION
#ifdef L1D_TEST
int16  RX_START_TQ_TABLE[7] =
{
   /* TQ_SLOT_BEGIN(i) + */ -TQ_SR1,               /* RX_START_CWIN_REG_TABLE[c][0]                   */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_PR1,               /* RX_START_CWIN_REG_TABLE[c][1]                   */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_PR2,               /* RX_START_CWIN_REG_TABLE[c][2]                   */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_SR2,               /* RX_START_RIDX_REG_TABLE[i][0]                   */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_BDLON,             /* RX_START_RIDX_REG_TABLE[i][1]                   */
   /* TQ_SLOT_BEGIN(i) + */  TQ_MAXIMUM,           /* RX_START_RIDX_REG_TABLE[i][2] (for FBWIN_HEAD)  */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_AFC_READY,         /* RX_START_RIDX_REG_TABLE[i][3] (for FBWIN_HEAD)  */
};
#else
const int16  RX_START_TQ_TABLE[7] =
{
   /* TQ_SLOT_BEGIN(i) + */ -TQ_SR1,               /* RX_START_CWIN_REG_TABLE[c][0]                   */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_PR1,               /* RX_START_CWIN_REG_TABLE[c][1]                   */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_PR2,               /* RX_START_CWIN_REG_TABLE[c][2]                   */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_SR2,               /* RX_START_RIDX_REG_TABLE[i][0]                   */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_BDLON,             /* RX_START_RIDX_REG_TABLE[i][1]                   */
   /* TQ_SLOT_BEGIN(i) + */  TQ_MAXIMUM,           /* RX_START_RIDX_REG_TABLE[i][2] (for FBWIN_HEAD)  */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_AFC_READY,         /* RX_START_RIDX_REG_TABLE[i][3] (for FBWIN_HEAD)  */
};
#endif

#else
const int16  RX_START_TQ_TABLE[7] =
{
   /* TQ_SLOT_BEGIN(i) + */ -TQ_SR1,               /* RX_START_CWIN_REG_TABLE[c][0]                   */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_PR1,               /* RX_START_CWIN_REG_TABLE[c][1]                   */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_PR2,               /* RX_START_CWIN_REG_TABLE[c][2]                   */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_SR2,               /* RX_START_RIDX_REG_TABLE[i][0]                   */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_BDLON,             /* RX_START_RIDX_REG_TABLE[i][1]                   */
   /* TQ_SLOT_BEGIN(i) + */  TQ_MAXIMUM,           /* RX_START_RIDX_REG_TABLE[i][2] (for FBWIN_HEAD)  */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_AFC_READY,         /* RX_START_RIDX_REG_TABLE[i][3] (for FBWIN_HEAD)  */
};
#endif

/*...........................................................................*/

#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
const int16  RX_END_TQ_TABLE[5] =
{
   /* TQ_SLOT_BEGIN(n) + */  TQ_SR3,               /* RX_END_CWIN_REG_TABLE[c][0]     */
   /* TQ_SLOT_BEGIN(n) + */  TQ_PR3,               /* RX_END_CWIN_REG_TABLE[c][1]     */
   /* TQ_SLOT_BEGIN(n) + */  TQ_PR3A,              /* RX_END_CWIN_REG_TABLE[c][2]     */
   /* TQ_SLOT_BEGIN(n) + */  TQ_BDLOFF,            /* RX/FSI_END_RIDX_REG_TABLE[i][0] */
   /* TQ_SLOT_BEGIN(n) + */  TQ_MAXIMUM,           /* FSI_END_RIDX_REG_TABLE[i][1]    */
};
#else
const int16  RX_END_TQ_TABLE[4] =
{
   /* TQ_SLOT_BEGIN(n) + */  TQ_SR3,               /* RX_END_CWIN_REG_TABLE[c][0]     */
   /* TQ_SLOT_BEGIN(n) + */  TQ_PR3,               /* RX_END_CWIN_REG_TABLE[c][1]     */
   /* TQ_SLOT_BEGIN(n) + */  TQ_BDLOFF,            /* RX/FSI_END_RIDX_REG_TABLE[i][0] */
   /* TQ_SLOT_BEGIN(n) + */  TQ_MAXIMUM,           /* FSI_END_RIDX_REG_TABLE[i][1]    */
};
#endif

/*...........................................................................*/

#if  IS_GPRS
const int16  RX_MIDDLE_TQ_TABLE[3] =
{
   /* TQ_SLOT_BEGIN(i) + */ +TQ_BDLOFF,            /* RX_MIDDLE_RIDX_REG_TABLE[i][0] */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_BDLON,             /* RX_MIDDLE_RIDX_REG_TABLE[i][1] */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_SR2M,              /* RX_MIDDLE_RIDX_REG_TABLE[i][2] */
};

#if  IS_CHIP_MT6218_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6218~*/ const int16  RX_MIDDLE_TQ_TABLE2[2] =
/*MT6218~*/ {
/*MT6218~*/    /* TQ_SLOT_BEGIN(i) + */ -TQ_PR2M1,             /* RX_MIDDLE_RIDX_REG_TABLE2[i][0] */
/*MT6218~*/    /* TQ_SLOT_BEGIN(i) + */ -TQ_PR2M2,             /* RX_MIDDLE_RIDX_REG_TABLE2[i][1] */
/*MT6218~*/ };
#endif
#endif


/*...........................................................................*/

const int16  TX_START_TQ_TABLE[8] =
{
   /* TQ_SLOT_BEGIN(i) + */ -TQ_AFC_READY,          /* TX_START_CWIN_REG_TABLE[c][0] */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_ST1,                /* TX_START_CWIN_REG_TABLE[c][1] */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_PT1,                /* TX_START_CWIN_REG_TABLE[c][2] */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_PT2,                /* TX_START_CWIN_REG_TABLE[c][3] */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_APCON,              /* TX_START_TIDX_REG_TABLE[i][0] */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_APCON,              /* TX_START_TIDX_REG_TABLE[i][1] */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_BULON,              /* TX_START_TIDX_REG_TABLE[i][2] */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_ST2,                /* Bright4 : For TDMA_BSI( txwin_sr2 ), not used in Bright2 */
};

#if  IS_CHIP_MT6218_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6218~*/ const int16  TX_START_TQ_TABLE2[1] =
/*MT6218~*/ {
/*MT6218~*/    /* TQ_SLOT_BEGIN(i) + */ -TQ_PT2B,               /* TX_START_CWIN_REG_TABLE2[c][0] */
/*MT6218~*/ };
#endif

#if  IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6229~*/ const int16  TX_START_TQ_TABLE3[1] =
/*MT6229~*/ {
/*MT6229~*/    /* TQ_SLOT_BEGIN(i) + */ -TQ_ST2B,               /* TX_START_CWIN_REG_TABLE2[c][0] */
/*MT6229~*/ };
#endif

/*...........................................................................*/

const int16  TX_END_TQ_TABLE[6] =
{  /* TQ_SLOT_BEGIN(n) + */  TQ_AFC2_2_BOFF,       /* TX_END_CWIN_REG_TABLE[c][0] */
   /* TQ_SLOT_BEGIN(n) + */  TQ_ST3,               /* TX_END_CWIN_REG_TABLE[c][1] */
   /* TQ_SLOT_BEGIN(n) + */  TQ_PT3,               /* TX_END_CWIN_REG_TABLE[c][2] */
   /* TQ_SLOT_BEGIN(n) + */  TQ_BULOFF,            /* TX_END_TIDX_REG_TABLE[i][0] */
   /* TQ_SLOT_BEGIN(n) + */  TQ_APCOFF,            /* TX_END_TIDX_REG_TABLE[i][1] */
   /* TQ_SLOT_BEGIN(n) + */  TQ_APCOFF,            /* TX_END_TIDX_REG_TABLE[i][2] */
};

/*...........................................................................*/

#if  IS_GPRS
const int16  TX_MIDDLE_TQ_TABLE[4] =
{
   /* TQ_SLOT_BEGIN(i) */ +TQ_BULOFF,              /* TX_MIDDLE_TIDX_REG_TABLE[i][0] */
   /* TQ_SLOT_BEGIN(i) */ -TQ_BULON,               /* TX_MIDDLE_TIDX_REG_TABLE[i][1] */
   /* TQ_SLOT_BEGIN(i) */ -TQ_APCMID,              /* TX_MIDDLE_TIDX_REG_TABLE[i][2] */
   /* TQ_SLOT_BEGIN(i) */ -TQ_APCMID,              /* TX_MIDDLE_TIDX_REG_TABLE[i][3] */
};

#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
#if IS_EPSK_TX_SUPPORT
/*EGPRS*/const int16  TX_MIDDLE_TQ_TABLE2[2][4] =
/*EGPRS*/{
/*EGPRS*/   /* TQ_SLOT_BEGIN(i) */{ -TQ_ST2M_G8,
/*EGPRS*/   /* TQ_SLOT_BEGIN(i) */  -TQ_PT2M1_G8,
/*EGPRS*/   /* TQ_SLOT_BEGIN(i) */  -TQ_PT2M2_G8,
/*EGPRS*/   /* TQ_SLOT_BEGIN(i) */  -TQ_PT2M3_G8 },
/*EGPRS*/   	
/*EGPRS*/   /* TQ_SLOT_BEGIN(i) */{ -TQ_ST2M_8G,
/*EGPRS*/   /* TQ_SLOT_BEGIN(i) */  -TQ_PT2M1_8G,
/*EGPRS*/   /* TQ_SLOT_BEGIN(i) */  -TQ_PT2M2_8G,
/*EGPRS*/   /* TQ_SLOT_BEGIN(i) */  -TQ_PT2M3_8G },
/*EGPRS*/};
#endif
#endif

#endif /*End of "IS_GPRS"*/


/*...........................................................................*/

const  int16  PM_START_TQ_TABLE[7] =
{
   TQ_SLOT0_BEGIN,
   TQ_SLOT1_BEGIN + TQ_AFC_READY,
   TQ_SLOT2_BEGIN + TQ_AFC_READY,
   TQ_SLOT3_BEGIN + TQ_AFC_READY,
   TQ_SLOT4_BEGIN + TQ_AFC_READY,
   TQ_SLOT5_BEGIN + TQ_AFC_READY,
   TQ_VALIDATE-1-TQ_SHORT_PMWIN_LEN-QR_BOFF_2_IDLE,
};

/*...........................................................................*/
#if L1D_PM_ENHANCE
const  int16  SHORT_PM_START_TQ_TABLE[4] =
{
   TQ_PM0_BEGIN_HF,
   TQ_PM1_BEGIN_HF,
   TQ_PM2_BEGIN_HF,
   TQ_PM3_BEGIN_HF,
};
#if L1D_PM_1R7PM
const  int16  PM_1R7PM_START_TQ_TABLE[6] =
{
   TQ_PM0_BEGIN_1R7PM,   //Null
   TQ_PM1_BEGIN_1R7PM,
   TQ_PM2_BEGIN_1R7PM,
   TQ_PM3_BEGIN_1R7PM,
   TQ_PM4_BEGIN_1R7PM,
   TQ_CTIRQ1-100-TQ_1R7PM_PMWIN_LEN_IN_IDLE,
};
#endif
#endif

/*...........................................................................*/
#if  IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
const  int16  PM_TQ_TABLE[10] =
{
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_SR1,                                     /* PM_CWIN_REG_TABLE[c][0] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_PR1,                                     /* PM_CWIN_REG_TABLE[c][1] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_PR2,                                     /* PM_CWIN_REG_TABLE[c][2] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_PR2B,                                    /* PM_CWIN_REG_TABLE[c][3] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */  TQ_SHORT_PMWIN_LEN+TQ_SR3,                  /* PM_CWIN_REG_TABLE[c][4] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */  TQ_SHORT_PMWIN_LEN+TQ_PR3,                  /* PM_CWIN_REG_TABLE[c][5] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */  TQ_SHORT_PMWIN_LEN+TQ_PR3A,                 /* PM_CWIN_REG_TABLE[c][6] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_SR2,                                     /* PM_RIDX_REG_TABLE[i][0] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_BDLON,                                   /* PM_RIDX_REG_TABLE[i][1] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */  TQ_SHORT_PMWIN_LEN+TQ_BDLOFF,               /* PM_RIDX_REG_TABLE[i][2] */
};
#if L1D_PM_ENHANCE
const  int16  PM_IN_IDLE_TQ_TABLE[10] =
{
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_SR1,                                     /* PM_CWIN_REG_TABLE[c][0] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_PR1,                                     /* PM_CWIN_REG_TABLE[c][1] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_PR2,                                     /* PM_CWIN_REG_TABLE[c][2] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_PR2B,                                    /* PM_CWIN_REG_TABLE[c][3] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */  TQ_SHORT_PMWIN_LEN_IN_IDLE+TQ_SR3,          /* PM_CWIN_REG_TABLE[c][4] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */  TQ_SHORT_PMWIN_LEN_IN_IDLE+TQ_PR3,          /* PM_CWIN_REG_TABLE[c][5] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */  TQ_SHORT_PMWIN_LEN_IN_IDLE+TQ_PR3A,         /* PM_CWIN_REG_TABLE[c][6] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_SR2,                                     /* PM_RIDX_REG_TABLE[i][0] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_BDLON,                                   /* PM_RIDX_REG_TABLE[i][1] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */  TQ_SHORT_PMWIN_LEN_IN_IDLE+TQ_BDLOFF,       /* PM_RIDX_REG_TABLE[i][2] */
};
#if L1D_PM_1R7PM
const  int16  PM_1R7PM_TQ_TABLE[10] =
{
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_SR1,                                     /* PM_CWIN_REG_TABLE[c][0] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_PR1,                                     /* PM_CWIN_REG_TABLE[c][1] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_PR2,                                     /* PM_CWIN_REG_TABLE[c][2] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_PR2B,                                    /* PM_CWIN_REG_TABLE[c][3] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */  TQ_1R7PM_PMWIN_LEN_IN_IDLE+TQ_SR3,          /* PM_CWIN_REG_TABLE[c][4] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */  TQ_1R7PM_PMWIN_LEN_IN_IDLE+TQ_PR3,          /* PM_CWIN_REG_TABLE[c][5] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */  TQ_1R7PM_PMWIN_LEN_IN_IDLE+TQ_PR3A,         /* PM_CWIN_REG_TABLE[c][6] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_SR2,                                     /* PM_RIDX_REG_TABLE[i][0] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_BDLON,                                   /* PM_RIDX_REG_TABLE[i][1] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */  TQ_1R7PM_PMWIN_LEN_IN_IDLE+TQ_BDLOFF,       /* PM_RIDX_REG_TABLE[i][2] */
};
#endif
#endif

#else
const  int16  PM_TQ_TABLE[8] =
{
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_SR1,                                     /* PM_CWIN_REG_TABLE[c][0] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_PR1,                                     /* PM_CWIN_REG_TABLE[c][1] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_PR2,                                     /* PM_CWIN_REG_TABLE[c][2] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */  TQ_SHORT_PMWIN_LEN+TQ_SR3,                  /* PM_CWIN_REG_TABLE[c][3] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */  TQ_SHORT_PMWIN_LEN+TQ_PR3,                  /* PM_CWIN_REG_TABLE[c][4] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_SR2,                                     /* PM_RIDX_REG_TABLE[i][0] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_BDLON,                                   /* PM_RIDX_REG_TABLE[i][1] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */  TQ_SHORT_PMWIN_LEN+TQ_BDLOFF,               /* PM_RIDX_REG_TABLE[i][2] */
};
#if L1D_PM_ENHANCE
const  int16  PM_IN_IDLE_TQ_TABLE[8] =
{
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_SR1,                                     /* PM_CWIN_REG_TABLE[c][0] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_PR1,                                     /* PM_CWIN_REG_TABLE[c][1] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_PR2,                                     /* PM_CWIN_REG_TABLE[c][2] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */  TQ_SHORT_PMWIN_LEN_IN_IDLE+TQ_SR3,          /* PM_CWIN_REG_TABLE[c][3] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */  TQ_SHORT_PMWIN_LEN_IN_IDLE+TQ_PR3,          /* PM_CWIN_REG_TABLE[c][4] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_SR2,                                     /* PM_RIDX_REG_TABLE[i][0] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_BDLON,                                   /* PM_RIDX_REG_TABLE[i][1] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */  TQ_SHORT_PMWIN_LEN_IN_IDLE+TQ_BDLOFF,       /* PM_RIDX_REG_TABLE[i][2] */
};
#if L1D_PM_1R7PM
const  int16  PM_1R7PM_TQ_TABLE[8] =
{
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_SR1,                                     /* PM_CWIN_REG_TABLE[c][0] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_PR1,                                     /* PM_CWIN_REG_TABLE[c][1] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_PR2,                                     /* PM_CWIN_REG_TABLE[c][2] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */  TQ_1R7PM_PMWIN_LEN_IN_IDLE+TQ_SR3,          /* PM_CWIN_REG_TABLE[c][3] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */  TQ_1R7PM_PMWIN_LEN_IN_IDLE+TQ_PR3,          /* PM_CWIN_REG_TABLE[c][4] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_SR2,                                     /* PM_RIDX_REG_TABLE[i][0] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_BDLON,                                   /* PM_RIDX_REG_TABLE[i][1] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */  TQ_1R7PM_PMWIN_LEN_IN_IDLE+TQ_BDLOFF,       /* PM_RIDX_REG_TABLE[i][2] */
};
#endif
#endif

#endif

/*...........................................................................*/

const  int16  FWIN_POS_TABLE[8] =
{
   TQ_SLOT0_BEGIN+TQ_FBWIN_START_OFFSET,
   TQ_SLOT1_BEGIN+TQ_FBWIN_START_OFFSET,
   TQ_SLOT2_BEGIN+TQ_FBWIN_START_OFFSET,
   TQ_SLOT3_BEGIN+TQ_FBWIN_START_OFFSET,
   TQ_SLOT4_BEGIN+TQ_FBWIN_START_OFFSET,
   TQ_SLOT5_BEGIN+TQ_FBWIN_START_OFFSET,
   TQ_SLOT6_BEGIN+TQ_FBWIN_START_OFFSET,
   TQ_SLOT7_BEGIN+TQ_FBWIN_START_OFFSET,
};

/*...........................................................................*/

#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
const  int16 FSWIN_STOP_DATA_TABLE[9] =
{
   TQ_FSWIN_STOP_FSYNC+TQ_SR3,
   TQ_FSWIN_STOP_FSYNC+TQ_PR3,
   TQ_FSWIN_STOP_FSYNC+TQ_PR3A,
   TQ_MAXIMUM,
   TQ_FSWIN_STOP_FSYNC+TQ_BDLOFF,
   PDATA_IDLE,
   PDATA_IDLE,
   (int16)SCTRL_IDLE|AGCIDX(FS_RXWIN_IDX+0),
   (int16)SCTRL_IDLE|AGCIDX(FS_RXWIN_IDX+1),
};

const  APBADDR  FSWIN_STOP_REG_TABLE[2][8] =
{
   {  TDMA_BSI(AGCIDX(FS_RXWIN_IDX+0)),
      BPI_EV_40,
      BPI_EV_41,
      TDMA_BDLON(FS_RXWIN_IDX+0),
      TDMA_BDLOFF(FS_RXWIN_IDX+0),
      BPI_V(BPIRES1),
      BPI_V(BPIRES2),
      BSI_Dn_CON(AGCDTIDX(FS_RXWIN_IDX+0))
   },
   {  TDMA_BSI(AGCIDX(FS_RXWIN_IDX+1)),
      BPI_EV_40,
      BPI_EV_41,
      TDMA_BDLON(FS_RXWIN_IDX+1),
      TDMA_BDLOFF(FS_RXWIN_IDX+1),
      BPI_V(BPIRES1),
      BPI_V(BPIRES2),
      BSI_Dn_CON(AGCDTIDX(FS_RXWIN_IDX+1))
   }
};

#else
const  int16 FSWIN_STOP_DATA_TABLE[7] =
{
   TQ_FSWIN_STOP_FSYNC+TQ_SR3,
   TQ_FSWIN_STOP_FSYNC+TQ_PR3,
   TQ_MAXIMUM,
   TQ_FSWIN_STOP_FSYNC+TQ_BDLOFF,
   PDATA_IDLE,
   (int16)SCTRL_IDLE|AGCIDX(FS_RXWIN_IDX+0),
   (int16)SCTRL_IDLE|AGCIDX(FS_RXWIN_IDX+1),
};

const  APBADDR  FSWIN_STOP_REG_TABLE[2][6] =
{
   {  TDMA_BSI(AGCIDX(FS_RXWIN_IDX+0)),
      TDMA_BPI(BPIRES),
      TDMA_BDLON(FS_RXWIN_IDX+0),
      TDMA_BDLOFF(FS_RXWIN_IDX+0),
      BPI_V(BPIRES),
      BSI_Dn_CON(AGCDTIDX(FS_RXWIN_IDX+0))
   },
   {  TDMA_BSI(AGCIDX(FS_RXWIN_IDX+1)),
      TDMA_BPI(BPIRES),
      TDMA_BDLON(FS_RXWIN_IDX+1),
      TDMA_BDLOFF(FS_RXWIN_IDX+1),
      BPI_V(BPIRES),
      BSI_Dn_CON(AGCDTIDX(FS_RXWIN_IDX+1))
   }
};
#endif

const  uint32 FSWIN_STOP_BSI_DATA_TABLE[1] =
{
   SDATA_IDLE,
};

const  APBADDR  FSWIN_STOP_BSI_REG_TABLE[2] =
{  (APBADDR)BSI_Dn_DAT(AGCDTIDX(FS_RXWIN_IDX+0)),
   (APBADDR)BSI_Dn_DAT(AGCDTIDX(FS_RXWIN_IDX+1))
};

/* ========================================================================= */

const    unsigned char   LOWEST_TX_POWER[5] =
{
   5,  /*#FrequencyBand400  */
   5,  /*#FrequencyBand850  */
   5,  /* FrequencyBand900  */
   0,  /* FrequencyBand1800 */
   0,  /* FrequencyBand1900 */
};

/*---------------------------------------------------------------------------*/

const  unsigned char  CONTISLOTMASK[5] =
{
   0x81, 0x3, 0x6, 0xC, 0x18
};

const  unsigned char  FIRSTSLOTMASK[5] =
{
   0x1, 0x3, 0x7, 0xF, 0x0
};
/*---------------------------------------------------------------------------*/

#if  (IS_CHIP_MT6208)||(IS_FPGA_TARGET)
/*FPGA,MT6208*/ const short  FIR_COEF[] =
/*FPGA,MT6208*/ {  19 /*count*/,
/*FPGA,MT6208*/    /*-----------------------------------*/
/*FPGA,MT6208*/    0x007F, 0x007E, 0x007E, 0x007E, 0x0000,
/*FPGA,MT6208*/    0x0002, 0x0006, 0x000A, 0x000C, 0x000D,
/*FPGA,MT6208*/    0x000C, 0x000A, 0x0006, 0x0002, 0x0000,
/*FPGA,MT6208*/    0x007E, 0x007E, 0x007E, 0x007F
/*FPGA,MT6208*/    /*-----------------------------------*/
/*FPGA,MT6208*/ };
#elif  IS_CHIP_MT6205
/*MT6205*/ const short  FIR_COEF[] =
/*MT6205*/ {   16 /*count*/,
/*MT6205*/     /*-------------------------------------*/
/*MT6205*/     2,  4,  5,  3,  0, -6, -12, -16, -16, -8,
/*MT6205*/     7, 28, 52, 74, 90, 95
/*MT6205*/     /*-------------------------------------*/
/*MT6205*/ };
#elif  IS_CHIP_MT6217 || IS_CHIP_MT6219 || IS_CHIP_MT6227 || IS_CHIP_MT6228 
/*MT6217*/ const short  FIR_COEF[] =
/*MT6217*/ {   16 /*count*/,
/*MT6217*/     /*-------------------------------------*/
/*MT6217*/     2,  4,  5,  3,  0, -6, -12, -16, -16, -8,
/*MT6217*/     7, 28, 52, 74, 90, 95
/*MT6217*/     /*-------------------------------------*/
/*MT6217*/ };
#elif  IS_CHIP_MT6218
/*MT6218*/ const short  FIR_COEF[] =
/*MT6218*/ {   16 /*count*/,
/*MT6218*/     /*-------------------------------------*/
/*MT6218*/     4,  8, 10,  6,  0,-12, -24, -32, -32,-16,
/*MT6218*/    14, 56,104,148,180,190
/*MT6218*/     /*-------------------------------------*/
/*MT6218*/ };
#elif IS_CHIP_MT6225_AND_LATTER_VERSION
/*MT6225*/ const short  FIR_COEF[] =    /* WB FIR, 0020h */	/* New WB FIR Coeffs as MT6229 */
/*MT6225*/ {   11 /*count*/,
/*MT6225*/     /*-------------------------------------*/
/*MT6225*/     2, 9, -4, -20, 5, 43, 1, -87, -35, 186, 
/*MT6225*/     319
/*MT6225*/     /*-------------------------------------*/
/*MT6225*/ };
/*MT6225*/ const short  NB_FIR_COEF[] = /* NB FIR, 0070h */
/*MT6225*/ {   11 /*count*/,
/*MT6225*/     /*-------------------------------------*/
/*MT6225*/     -1, 1, 5, 7, -1, -18, -27, -2, 64, 139, 
/*MT6225*/     172
/*MT6225*/     /*-------------------------------------*/
/*MT6225*/ };
/*MT6225*/ const short  NB_FIR_COEF_WIDER[] = /* NB FIR for TX auto Cal, 0070h */
/*MT6225*/ {   11 /*count*/,
/*MT6225*/     /*-------------------------------------*/
/*MT6225*/     -3,  -3,  3,  13,  10, -13, -37, -18, 58, 152,
/*MT6225*/     195
/*MT6225*/     /*-------------------------------------*/
/*MT6225*/ };
#endif

#if  IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION

#if IS_CHIP_MT6238
/*MT6238*/ const short  FIR_COEF[] =    /* WB FIR, 0020h */
/*MT6238*/ {   11 /*count*/,
/*MT6238*/     /*-------------------------------------*/
/*MT6238*/     -3, 5, 7, -12, -11, 27, 17, -58, -29, 167, 
/*MT6238*/     295
/*MT6238*/     /*-------------------------------------*/
/*MT6238*/ };
/*MT6238*/ const short  NB_FIR_COEF[] = /* NB FIR, 0070h */
/*MT6238*/ {   11 /*count*/,
/*MT6238*/     /*-------------------------------------*/
/*MT6238*/     0, -4, -4, 6, 15, 0, -32, -31, 44, 155,     
/*MT6238*/     209
/*MT6238*/     /*-------------------------------------*/
/*MT6238*/ };
/*MT6238*/ const short  NB_FIR_COEF_WIDER[] = /* NB FIR for TX auto Cal, 0070h */
/*MT6238*/ {   11 /*count*/,
/*MT6238*/     /*-------------------------------------*/
/*MT6238*/     -3,  -3,  3,  13,  10, -13, -37, -18, 58, 152,
/*MT6238*/     195
/*MT6238*/     /*-------------------------------------*/
/*MT6238*/ };
#elif IS_CHIP_MT6223
/*MT6223*/ const short  FIR_COEF[] =    /* WB FIR, 0020h */
/*MT6223*/ {   11 /*count*/,
/*MT6223*/     /*-------------------------------------*/
/*MT6223*/     -1, 8, 3, -15, -6, 32, 11, -65, -29, 172, 
/*MT6223*/     298
/*MT6223*/     /*-------------------------------------*/
/*MT6223*/ };
/*MT6223*/ const short  NB_FIR_COEF[] = /* NB FIR, 0070h */
/*MT6223*/ {   11 /*count*/,
/*MT6223*/     /*-------------------------------------*/
/*MT6223*/     -1, 1, 5, 7, -1, -18, -27, -2, 64, 139, 
/*MT6223*/     172
/*MT6223*/     /*-------------------------------------*/
/*MT6223*/ };
/*MT6223*/ const short  NB_FIR_COEF_WIDER[] = /* NB FIR for TX auto Cal, 0070h */
/*MT6223*/ {   11 /*count*/,
/*MT6223*/     /*-------------------------------------*/
/*MT6223*/     -3,  -3,  3,  13,  10, -13, -37, -18, 58, 152,
/*MT6223*/     195
/*MT6223*/     /*-------------------------------------*/
/*MT6223*/ };
#elif IS_CHIP_MT6229 || IS_CHIP_MT6268T
/*MT6229*/ const short  FIR_COEF[] =    /* WB FIR, 0020h */
/*MT6229*/ {   11 /*count*/,
/*MT6229*/     /*-------------------------------------*/
/*MT6229*/     2, 9, -4, -20, 5, 43, 1, -87, -35, 186, 
/*MT6229*/     319
/*MT6229*/     /*-------------------------------------*/
/*MT6229*/ };
/*MT6229*/ const short  NB_FIR_COEF[] = /* NB FIR, 0070h */
/*MT6229*/ {   11 /*count*/,
/*MT6229*/     /*-------------------------------------*/
/*MT6229*/     -1, 1, 5, 7, -1, -18, -27, -2, 64, 139, 
/*MT6229*/     172
/*MT6229*/     /*-------------------------------------*/
/*MT6229*/ };
/*MT6229*/ const short  NB_FIR_COEF_WIDER[] = /* NB FIR for TX auto Cal, 0070h */
/*MT6229*/ {   11 /*count*/,
/*MT6229*/     /*-------------------------------------*/
/*MT6229*/     -3,  -3,  3,  13,  10, -13, -37, -18, 58, 152,
/*MT6229*/     195
/*MT6229*/     /*-------------------------------------*/
/*MT6229*/ };
#endif

#ifdef L1D_TEST
/*MT6229,L1D_TEST~*/ const short  VCXO_NARROW_FB_FIR_COEF[] =  /* Narrow Band FIR for FB */
/*MT6229,L1D_TEST~*/ {   11 /*count*/,
/*MT6229,L1D_TEST~*/     /*-------------------------------------*/
/*MT6229,L1D_TEST~*/     -2, -3, -3, 0, 6, 16, 30, 46, 61, 71, 75,
/*MT6229,L1D_TEST~*/     /*-------------------------------------*/
/*MT6229,L1D_TEST~*/ };
/*MT6229,L1D_TEST~*/ const short  VCXO_WIDE_FB_FIR_COEF[] =    /* Wide Band  FIR for FB */
/*MT6229,L1D_TEST~*/ {   11 /*count*/,
/*MT6229,L1D_TEST~*/     /*-------------------------------------*/
/*MT6229,L1D_TEST~*/     1, -1, -5, -10, -12, -7, 12, 41, 75, 102, 113,
/*MT6229,L1D_TEST~*/     /*-------------------------------------*/
/*MT6229,L1D_TEST~*/ };
/*MT6229,L1D_TEST~*/ const short  TCVCXO_NARROW_FB_FIR_COEF[] =  /* Narrow Band  FIR for FB */
/*MT6229,L1D_TEST~*/ {   11 /*count*/,
/*MT6229,L1D_TEST~*/     /*-------------------------------------*/
/*MT6229,L1D_TEST~*/     7, 8, 12, 16, 21, 26, 30, 34, 37, 39, 40,
/*MT6229,L1D_TEST~*/     /*-------------------------------------*/
/*MT6229,L1D_TEST~*/ };
/*MT6229,L1D_TEST~*/ const short  TCVCXO_WIDE_FB_FIR_COEF[] =    /* Wide Band FIR for FB */
/*MT6229,L1D_TEST~*/ {   11 /*count*/,
/*MT6229,L1D_TEST~*/     /*-------------------------------------*/
/*MT6229,L1D_TEST~*/     3, 5, 3, -4, -16, -21, -9, 26, 76, 121, 139,
/*MT6229,L1D_TEST~*/     /*-------------------------------------*/
/*MT6229,L1D_TEST~*/ };
#endif


#if defined(MT6229_FB_VCXO)
/*MT6229~*/ const short  NARROW_FB_FIR_COEF[] =  /* Narrow Band FIR for FB */
/*MT6229~*/ {   11 /*count*/,
/*MT6229~*/     /*-------------------------------------*/
/*MT6229~*/     -2, -3, -3, 0, 6, 16, 30, 46, 61, 71, 75,
/*MT6229~*/     /*-------------------------------------*/
/*MT6229~*/ };
/*MT6229~*/ const short  WIDE_FB_FIR_COEF[] =    /* Wide Band  FIR for FB */
/*MT6229~*/ {   11 /*count*/,
/*MT6229~*/     /*-------------------------------------*/
/*MT6229~*/     1, -1, -5, -10, -12, -7, 12, 41, 75, 102, 113,
/*MT6229~*/     /*-------------------------------------*/
/*MT6229~*/ };
#else
/*MT6229~*/ const short  NARROW_FB_FIR_COEF[] =  /* Narrow Band  FIR for FB */
/*MT6229~*/ {   11 /*count*/,
/*MT6229~*/     /*-------------------------------------*/
/*MT6229~*/     7, 8, 12, 16, 21, 26, 30, 34, 37, 39, 40,
/*MT6229~*/     /*-------------------------------------*/
/*MT6229~*/ };
/*MT6229~*/ const short  WIDE_FB_FIR_COEF[] =    /* Wide Band FIR for FB */
/*MT6229~*/ {   11 /*count*/,
/*MT6229~*/     /*-------------------------------------*/
/*MT6229~*/     3, 5, 3, -4, -16, -21, -9, 26, 76, 121, 139,
/*MT6229~*/     /*-------------------------------------*/
/*MT6229~*/ };
#endif

#endif

#if !(IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION)
    #if defined(AFC_VCXO)
        const unsigned char USE_3_SUBSTAGES_FB_STAGE1 = 1;
    #else
        const unsigned char USE_3_SUBSTAGES_FB_STAGE1 = 0;
    #endif
#endif

/*-----------------------------*/
/* define DSP power constance  */
/*-----------------------------*/
const int dsp_power_constance = (DSP_MAGIC_VALUE*64);

#ifndef  DCS_TX_GAIN_SETTING
   #define  DCS_TX_GAIN_SETTING    0
#endif
#ifndef  PCS_TX_GAIN_SETTING
   #define  PCS_TX_GAIN_SETTING    0
#endif

#if (DCS_TX_GAIN_SETTING<=-1) ||(PCS_TX_GAIN_SETTING<=-1) ||(DCS_TX_GAIN_SETTING>=3) ||(PCS_TX_GAIN_SETTING>=3)
   #error "MT6139E TX gain setting out of range!"
#endif
const unsigned char dcs_tx_gain_setting=DCS_TX_GAIN_SETTING;
const unsigned char pcs_tx_gain_setting=PCS_TX_GAIN_SETTING;

/*---------------------------------*/
/* AFC Kalman filter coefficients  */
/*---------------------------------*/
#define     AFC_A0_G_SNR          (2560)      /*   a0=0.5, g=1, SNR=4  (0.625) * (2^12) */
#if defined(AFC_VCXO)                                                             
   #define  AFC_PAD               (5120)      /*   (1.2e-6)     * (2^24) */
#else                                                                           
   #define  AFC_PAD                (640)      /*   (1.2e-6)     * (2^24) */ 
#endif                                                                            
const int32 AFC_KALMAN_FILTER_PAD = ( (AFC_PAD<<12)/AFC_A0_G_SNR )>>4;   /* VCXO:512, TCVCXO:64 */


/* ========================================================================= */
/*...........................................................................*/
/*OSREQ*/ #ifdef __MTK_TARGET__
/*OSREQ*/ #pragma arm section rwdata , rodata , zidata
/*OSREQ*/ #endif /* __MTK_TARGET__ */
/*...........................................................................*/


