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
 *	m12190.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   Setup RF
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *******************************************************************************/


#ifndef  _M12190_H_
#define  _M12190_H_
/*---------------------------------------------------------------------------*/

/*...................................*/

#ifdef  L1D_SIM
   #include "l1_public.h"
#else
   #define  HW_WRITE(ptr,data)   (*(ptr) = (data))
   #define  HW_READ(ptr)         (*(ptr))
#endif

/*...................................*/

#ifndef _L1D_DATA_H_
   #define  PWRRES_BIT        3
   #define  PWRRES            (1<<PWRRES_BIT)
#endif

#define  GAINLOSS( n )        ((signed char)((n)*PWRRES))
#define  TABLE_END            -1

/*...................................*/

#define  IS_CONTINUOUS_RX_SLOT()  ((l1d_rf.rx_slots&CONTISLOTMASK[l1d_rf.cur_slot])==CONTISLOTMASK[l1d_rf.cur_slot])
#define  IS_CONTINUOUS_TX_SLOT()  ((l1d_rf.tx_slots&CONTISLOTMASK[l1d_rf.cur_slot])==CONTISLOTMASK[l1d_rf.cur_slot])
#define  IS_1ST_RX_SLOT()         ((l1d_rf.rx_slots&FIRSTSLOTMASK[l1d_rf.cur_slot])==(1<<l1d_rf.cur_slot))
#define  IS_1ST_TX_SLOT()         ((l1d_rf.tx_slots&FIRSTSLOTMASK[l1d_rf.cur_slot])==(1<<l1d_rf.cur_slot))

/*...................................*/

#ifndef l1_generic_l1_types_h
   typedef enum
   {
      FrequencyBand400,
      FrequencyBand850,
      FrequencyBand900,
      FrequencyBand1800,
      FrequencyBand1900,

      FrequencyBandCount

   } FrequencyBand;
#endif

/*...................................*/

#define  RF_RX             0
#define  RF_TX             1
#define  RF_TX_8G          2
/*...................................*/

typedef  struct
{
   char  cwin_idx;
   char  band;
   char  rtxwin_idx;
   char  is_init;
   char  cur_slot;
   char  rx_slots;
   char  tx_slots;
   char  tx_mod_type;
   unsigned short tx_mod_type2;
   char  modidx;
   char  change;
   char  bb_tx_autocal;
   char  bat_volt;
   char  bat_temp;
   unsigned short apc_dc_offset;
   unsigned short AFC_data;
   unsigned long  RFN_data;
   unsigned long  IFN_data;
   unsigned long  AGC_data;   
   char inj;
   char next_inj;
   char d2c_txiqswap;   
   char  old_band;
   char d2c_txiqconfig; 
#if defined(__EPSK_TX__)
   unsigned char tx_power[4];
#endif
}  sRFSETTING;

extern  sRFSETTING l1d_rf;

/*...................................*/

typedef  struct
{
   unsigned short  ctrl;
   unsigned long   data;

}  sSDATAINITDATA;

/*...................................*/

typedef  struct
{
   int  max_gain;
   int  min_gain;

} sL1DGAINRANGE;

/*...................................*/

typedef  struct
{
   short pos_gain;
   long  setting;
   short A;

} sL1DAGCDATA;

/*...................................*/

#define  PLTABLE_SIZE  13

typedef  struct
{
   short        max_arfcn;
   signed char  gain_offset;

} sAGCGAINOFFSET;

extern  sAGCGAINOFFSET*  AGC_PATHLOSS_TABLE[FrequencyBandCount];

/*...................................*/

#define PROFILE_NUM             16
#define ARFCN_SECTION_NUM       12
#define WEIGHT(n)               ((unsigned short)((n)*(1<<14)))

typedef  struct
{
   unsigned char   point[2][16];

} sRAMPAREADATA;

typedef  struct
{
   signed short     max_arfcn;
   unsigned short   mid_level;
   unsigned short   hi_weight;
   unsigned short   low_weight;

} sARFCN_SECTION;

typedef  struct
{
   signed   long   lowest_power;
   unsigned short  power[16];
   sRAMPAREADATA   ramp[ PROFILE_NUM ];
   sARFCN_SECTION  arfcn_weight[ ARFCN_SECTION_NUM ];
   unsigned short  battery_compensate[3/*volt*/][3/*temp*/];
} sRAMPDATA;

extern  sRAMPDATA*  RampData[FrequencyBandCount];
#if defined(__EPSK_TX__)
extern  sRAMPDATA*  RampData_EPSK[FrequencyBandCount];
#endif

/*...................................*/
typedef struct
{
   unsigned char bbtx_common_mode_voltage;
   unsigned char bbtx_gain;
   unsigned char bbtx_calrcsel;
   unsigned char bbtx_trimI;        // need to set
   unsigned char bbtx_trimQ;        // need to set
   unsigned char bbtx_dccoarseI;    // need to set
   unsigned char bbtx_dccoarseQ;    // need to set
   unsigned char bbtx_offsetI;      // need to set
   unsigned char bbtx_offsetQ;      // need to set
   unsigned char bbtx_isCalibrated; // need to set
   int           apc_bat_low_voltage;
   int           apc_bat_high_voltage;
   int           apc_bat_low_temperature;
   int           apc_bat_high_temperature;
   unsigned char bbtx_common_mode_voltage_h;
   unsigned char bbtx_gain_h;
   unsigned char bbtx_calrcsel_h;
   unsigned char bbtx_trimI_h;
   unsigned char bbtx_trimQ_h;
   unsigned char bbtx_dccoarseI_h;
   unsigned char bbtx_dccoarseQ_h;
   unsigned char bbtx_offsetI_h;
   unsigned char bbtx_offsetQ_h;
   unsigned char bbtx_phsel;
   unsigned char bbtx_phsel_h;
   unsigned char bbrx_gsm850_gsm900_swap;
   unsigned char bbrx_dcs1800_pcs1900_swap;
} sBBTXParameters;

extern sBBTXParameters BBTXParameters;

/*...................................*/

typedef  unsigned char sMIDRAMPDATA[16];
extern sMIDRAMPDATA*  InterRampData[FrequencyBandCount];
#if defined(__EPSK_TX__)
extern sMIDRAMPDATA*  GSM850_EPSK_InterRampData[4];
extern sMIDRAMPDATA*  GSM_EPSK_InterRampData[4];
extern sMIDRAMPDATA*  DCS_EPSK_InterRampData[4];
extern sMIDRAMPDATA*  PCS_EPSK_InterRampData[4];
extern sMIDRAMPDATA** EPSK_InterRampData[5];
#endif
/*...................................*/

#define XO_SlopeArea_Num       8

typedef  struct
{
   long   min_freq;
   short  min_dac;
   long   inv_slope;

}  XO_SLOPE_AREA_DATA;

extern XO_SLOPE_AREA_DATA  XO_SlopeAreaData[XO_SlopeArea_Num];

/*...................................*/

extern long  XO_CapID;
/*.............................................*/

typedef struct
{
   unsigned long icorrection;
   unsigned long qcorrection;
}skyip2coef;

typedef struct
{
   unsigned long ipol;
   unsigned long qpol;
}sky117ip2pol;

typedef struct
{
   unsigned long acode;
   unsigned long amcode;
}mt6139ip2coef;

typedef union
{
   struct
   {  
      skyip2coef data[5/*band*/];
   }skyip2; //for sky74045
   struct
   {  
      skyip2coef data[5/*band*/];
      sky117ip2pol pol[5/*band*/];
   }sky117ip2;
   struct
   {
      mt6139ip2coef data[5/*band*/];
      unsigned long rxamcalmode;
   }mt6139ip2;
   struct
   {
      unsigned char fixgain_enable;
   }sky74137; //for sky74137
}sRxip2;

typedef struct
{
   unsigned long word6_4_0;
   unsigned long word6_5_0;
   unsigned long word6_6_0;
   unsigned long word6_7_0;
   unsigned long bvmode;
   unsigned long c3mode;
   unsigned long wordC3;
}b5ptxcoef;

typedef struct
{
   short pcl_index;
   unsigned char pa_vbias;   
}pa_vbias;

typedef struct
{
   pa_vbias GSM850_pa_vbias[8];
   pa_vbias GSM900_pa_vbias[8];   
   pa_vbias DCS1800_pa_vbias[8];
   pa_vbias PCS1900_pa_vbias[8];      
}mt6140tx_pa_vbias;

typedef   union
{
   struct
   {  
      b5ptxcoef data;
   }b5ptx;
   struct
   {  
      mt6140tx_pa_vbias data;
   }mt6140tx;   
   /*struct
   {
      unsigned long dummy;
   }sTXdummy;*/
}sTxepsk;

typedef struct
{
   sRxip2 rx;
   sTxepsk tx;
}sRFSpecialCoef;

extern  sRFSpecialCoef RFSpecialCoef;
/*...................................*/


extern const  unsigned char   CONTISLOTMASK[5];
extern const  unsigned char   FIRSTSLOTMASK[5];



/*.............................................*/

void  L1D_RF_Init( void );
void  L1D_RF_Init_FIR( void );
void  L1D_RF_PowerOn( void );
void  L1D_RF_PowerOff( void );
void  L1D_RF_WindowOn( void );
void  L1D_RF_WindowOff( void );

void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN );
void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN );
int   L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting );

void  L1D_RF_SetFixGainEnable( unsigned char enable );
void  L1D_RF_SetPathLossTable( int rf_band, void* table );
void  L1D_RF_SetRampTable( int rf_band, void* table );
void  L1D_RF_InitRampTable( int rf_band );
#if defined(__EPSK_TX__) 
void  L1D_RF_SetRampTableEPSK( int rf_band, void* table );
void  L1D_RF_InitRampTableEPSK( int rf_band );
void  L1D_RF_EPSK_SetInterSlotRampTable( int rf_band, int _8G_mode, void* table );
short L1D_RF_SetInterslotPowerLevel(int rf_band, int arfcn, short mod_type);
#endif
void  L1D_RF_SetInterSlotRampTable( int rf_band, void* table );
void  L1D_RF_SetCrystalAFCData( void* table );
void  L1D_RF_SetCrystalCap( int  cap_no );
void  L1D_RF_SetRFSpecialCoef(void* table );
unsigned long  L1D_RF_GetID(void);
void  L1D_RF_SetImmediateBSI(unsigned long bsidata);
void  L1D_RF_GetImmediateBSI( unsigned long bsi_addr, unsigned long *bsi_data  );
void  L1D_RF_TXIQ_Dynamic_Swap( void );
void  L1D_BFE_SetTxIQSwap( void );
void  IMM_RECEIVE_BSI( unsigned short ADD_Ctrl, unsigned long ADD, unsigned short DATA_Ctrl, unsigned long *DATA  );
short L1D_RF_SetTxPowerLevel( int rf_band, int arfcn, short power_dbm, short mod_type );
short L1D_RF_GetRxPathLoss( int rf_band, int arfcn, short request_gain );
void  L1D_RF_NotifyBatteryVoltage( int  micro_volt );
void  L1D_RF_NotifyBatteryTemperature( int  mili_degree );

void  L1D_RF_SetPData_PR( void );
void  L1D_RF_SetPData_PT( void );
void  L1D_RF_SetPData_PR2M( void );
void  L1D_RF_SetPData_PT2M( void );
void  L1D_RF_SetSData_SR1( void );
void  L1D_RF_SetSData_SR2( void );
void  L1D_RF_SetSData_SR3( void );
void  L1D_RF_SetSData_ST1( void );
void  L1D_RF_SetSData_ST2( void );
void  L1D_RF_SetSData_ST3( void );
#if  IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
void  L1D_RF_SetSData_ST2B( void );
void  L1D_RF_SetSData_ST2M( void ); 
void  L1D_RF_Set_FB_FIR( void );
//void L1D_RF_init_FIR_SwitchNB( int wider );
void  L1D_RF_TXIQ_Dynamic_Config( void );
void  L1D_BFE_SetTxIQ_Config( void );
#endif
#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION || IS_CHIP_MT6225_AND_LATTER_VERSION
void  L1D_RF_init_FIR_SwitchNB( int wider );
#endif
void  L1D_AFCDAC_On( void );
void  L1D_AFCDAC_Off( void );
unsigned long  L1D_RF_GetITC_PCL(void);
unsigned short  L1D_RF_GetTxPAVBias_TxITC( unsigned short lb_cw_high_idx, unsigned short hb_cw_high_idx); 

/*.............................................*/

#define  IMMMASK_AFC    0x01
#define  IMMMASK_BSI    0x02
#define  IMMMASK_BPI    0x04
#define  IMMMASK_ALL    (IMMMASK_AFC|IMMMASK_BSI|IMMMASK_BPI)

void     WAIT_TIME_QB( short time_qb );
void     IMM_MODE_BEGIN( unsigned short imm_mask );
void     IMM_MODE_END( void );
void     IMM_SEND_BPI( unsigned short  data );
void     IMM_SEND_BSI( unsigned short ctrl, unsigned long data );

/* ------------------------------------------------------------------------- */
void     IMM_RECEIVE_BSI( unsigned short ctrl1, unsigned long data1, unsigned short ctrl2, unsigned long *data2  );
/*===============================================================================*/
/*    BSI read back                                                              */
/*===============================================================================*/
#define  SCTRL_IMOD_RX_MAIN                 (0x0103+(2<<4)+(2<<6))    /* 13/4Mhz, long  enable negative pulse */
#define  SCTRL_IMOD_RX_SEND                 (0x000B+(2<<4)+(2<<6))    /* 13/4Mhz,                             */
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


#endif



