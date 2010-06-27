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
 * Filename:
 * ---------
 * nvram_editor_data_item.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is intends for NVRAM editor.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 ****************************************************************************/

#ifndef NVRAM_EDTIOR_DATA_ITEM_SYSTEM_H
#define NVRAM_EDTIOR_DATA_ITEM_SYSTEM_H

#ifndef __MAUI_BASIC__
/***************************************************************************** 
* Include
*****************************************************************************/
#ifdef GEN_FOR_PC 
#include "m12190.h"
#include "l1cal.h"
#include "batparm.h"
#if defined(__WIFI_SUPPORT__)
#include "wndrv_cal.h"
#endif
#endif

#ifndef __L1_STANDALONE__
#include "l4c2uem_struct.h"
#include "device.h"
#include "mcd_l4_common.h"
#endif /* __L1_STANDALONE__ */ 
#include "nvram_data_items.h"
/***************************************************************************** 
* Define
*****************************************************************************/

/* macro of verno */
#define VER_LID(lid) lid##_VERNO lid
#define VER(lid)  lid##_VERNO

/* verno of data items */
#define  NVRAM_EF_SYS_EXCEPTION_LID_VERNO                    "000"
#define  NVRAM_EF_SYS_STATISTICS_LID_VERNO                   "000"

#define  NVRAM_EF_L1_AGCPATHLOSS_LID_VERNO                   "002"
#define  NVRAM_EF_L1_RAMPTABLE_GSM850_LID_VERNO              "002"
#define  NVRAM_EF_L1_RAMPTABLE_GSM900_LID_VERNO              "002"
#define  NVRAM_EF_L1_RAMPTABLE_DCS1800_LID_VERNO             "002"
#define  NVRAM_EF_L1_RAMPTABLE_PCS1900_LID_VERNO             "002"
#define  NVRAM_EF_L1_EPSK_RAMPTABLE_GSM850_LID_VERNO         "002"
#define  NVRAM_EF_L1_EPSK_RAMPTABLE_GSM900_LID_VERNO         "002"
#define  NVRAM_EF_L1_EPSK_RAMPTABLE_DCS1800_LID_VERNO        "002"
#define  NVRAM_EF_L1_EPSK_RAMPTABLE_PCS1900_LID_VERNO        "002"
#define  NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_GSM850_LID_VERNO    "002"
#define  NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_GSM900_LID_VERNO    "002"
#define  NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_DCS1800_LID_VERNO   "002"
#define  NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_PCS1900_LID_VERNO   "002"
#define  NVRAM_EF_L1_AFCDATA_LID_VERNO                       "002"
#define  NVRAM_EF_L1_TXIQ_LID_VERNO                          "004"
#define  NVRAM_EF_L1_RFSPECIALCOEF_LID_VERNO                 "003"
#define  NVRAM_EF_L1_INTERSLOT_RAMP_GSM850_LID_VERNO         "002"
#define  NVRAM_EF_L1_INTERSLOT_RAMP_GSM900_LID_VERNO         "002"
#define  NVRAM_EF_L1_INTERSLOT_RAMP_DCS1800_LID_VERNO        "002"
#define  NVRAM_EF_L1_INTERSLOT_RAMP_PCS1900_LID_VERNO        "002"
#define  NVRAM_EF_L1_CRYSTAL_AFCDATA_LID_VERNO               "002"
#define  NVRAM_EF_L1_CRYSTAL_CAPDATA_LID_VERNO               "002"
#define NVRAM_EF_UL1_TEMP_DAC_LID_VERNO                      "000"
#define NVRAM_EF_UL1_PATHLOSS_BAND1_LID_VERNO                "000"
#define NVRAM_EF_UL1_PATHLOSS_BAND2_LID_VERNO                "000"
#define NVRAM_EF_UL1_PATHLOSS_BAND3_LID_VERNO                "000"
#define NVRAM_EF_UL1_TXDAC_BAND1_LID_VERNO                   "000"
#define NVRAM_EF_UL1_TXDAC_BAND2_LID_VERNO                   "000"
#define NVRAM_EF_UL1_TXDAC_BAND3_LID_VERNO                   "000"

#define  NVRAM_EF_WNDRV_MAC_ADDRESS_LID_VERNO                "000"
#define  NVRAM_EF_WNDRV_TX_POWER_2400M_LID_VERNO             "010"
#define  NVRAM_EF_WNDRV_TX_POWER_5000M_LID_VERNO             "020"
#define  NVRAM_EF_WNDRV_DAC_DC_OFFSET_LID_VERNO              "030"
#define  NVRAM_EF_WNDRV_TX_ALC_POWER_LID_VERNO               "040"
#define  NVRAM_EF_WNDRV_ALC_SLOPE_LID_VERNO                  "050"

#define  NVRAM_EF_EXTBCCH_LID_VERNO                          "000"
#define  NVRAM_EF_EQ_PLMN_LID_VERNO                          "000"
#define  NVRAM_EF_BAND_INFO_LID_VERNO                        "000"
#define  NVRAM_EF_TST_FILTER_LID_VERNO                       "002"
#define  NVRAM_EF_CB_CH_INFO_LID_VERNO                       "001"

#define NVRAM_EF_SMSAL_MWIS_LID_VERNO                        "000"
#define  NVRAM_EF_TCM_STATISTICS_LID_VERNO                   "001"
#define  NVRAM_EF_CFU_FLAG_LID_VERNO                         "000"
#define  NVRAM_EF_MM_EQPLMN_LOCIGPRS_LID_VERNO               "000"
#define  NVRAM_EF_CTM_DEFAULT_SETTINGS_LID_VERNO             "000"
#define  NVRAM_EF_MSCAP_LID_VERNO                            "000"
#define  NVRAM_EF_ALS_LINE_ID_LID_VERNO                      "002"
#define NVRAM_EF_CLASSMARK_RACAP_LID_VERNO                   "003"
#define NVRAM_EF_SIM_ASSERT_LID_VERNO                        "000"
#define NVRAM_EF_RTC_DATA_LID_VERNO                          "000"
#define NVRAM_EF_UMTS_PLMN_LID_VERNO                         "000"
#define NVRAM_EF_UMTS_NET_PAR_LID_VERNO                      "000"
#define NVRAM_EF_UMTS_IMSI_LID_VERNO                         "000"
#define NVRAM_EF_UMTS_START_HFN_LID_VERNO                    "000"
#define NVRAM_EF_UMTS_CSE_CACHE_INFO_LID_VERNO               "000"
#define NVRAM_EF_UMTS_USIME_RRC_DYNAMIC_CAP_LID_VERNO        "000"
#define NVRAM_EF_L1_3G_CAL_DATA_LID_VERNO                    "000"
#define NVRAM_EF_FLC_STATISTICS_LID_VERNO                    "000"

#if defined(G_SENSOR_SUPPORT)
//Huyanwei Add It 
#define NVRAM_G_SENSOR_LID_VERNO                    "000"
#define NVRAM_G_SENSOR_CALIBRANTION_LID_VERNO "000"
#endif

#if defined(HORSERACE_SUPPORT)
//Huyanwei Add It 
#define NVRAM_HORSERACE_LID_VERNO                    "000"
#endif

#if defined(DOUBLE_BATTERY_SUPPORT)
//Huyanwei Add It 
#define NVRAM_ADC_LID_VERNO                          "000"
#endif

/***************************************************************************** 
* Typedef 
*****************************************************************************/
#ifndef __L1_STANDALONE__
typedef struct
{
    kal_uint32 total_rx_data;
    kal_uint32 total_tx_data;
    kal_uint32 last_rx_data;
    kal_uint32 last_tx_data;
} nvram_ef_tcm_statistics_struct;

#ifdef __CCM_NO_RESET__
typedef struct
{
    kal_uint8 als_line_id[2];
    kal_uint8 last_ccm[4];
} nvram_ef_als_line_id_struct;
#else
typedef struct
{	
	kal_uint8 als_line_id[2];
}nvram_ef_als_line_id_struct;
#endif

typedef struct
{
    kal_uint8 byte1;
    kal_uint8 byte2;
    kal_uint8 byte3;
    kal_uint8 byte4;
    kal_uint16 byte5_byte6;
    kal_uint8 byte7;
    kal_uint8 byte8;
    kal_uint8 byte9;
    kal_uint8 byte10;
    kal_uint8 byte11;
    kal_uint8 byte12;
} nvram_ef_classmark_racap_struct;

typedef struct
{
    kal_uint8 cfu_flag[2];
} nvram_ef_cfu_flag_struct;

typedef struct _nvram_ef_cb_ch_info_struct
{
    kal_uint16 cbmir_mask;
    kal_uint16 dcs_mask;
    kal_uint8 cbmi_mask[6];
    kal_uint16 cbmi[20];
} nvram_ef_cb_ch_info_struct;

typedef struct
{
    kal_uint8 message_waiting_indication_status[5];
    kal_uint8 pad;
} nvram_ef_smsal_mwis_struct;

typedef struct
{
    kal_uint8 nvram_ef_tst_filter[NVRAM_EF_TST_FILTER_SIZE];
} nvram_ef_tst_filter_struct;

typedef struct
{
    kal_uint8 mcc1;
    kal_uint8 mcc2;
    kal_uint8 mcc3;
    kal_uint8 mnc1;
    kal_uint8 mnc2;
    kal_uint8 mnc3;
    kal_uint8 arfcn_MSB;
    kal_uint8 arfcn_LSB;
    kal_uint8 byte[48]; /* 16 for SI2bis, 16 for SI2ter, 16 for BA range */
} nvram_ef_extbcch_struct;

typedef struct
{
    kal_uint8 byte[NVRAM_EF_EQ_PLMN_SIZE];
} nvram_ef_eq_plmn_struct;

typedef struct
{
    kal_uint8 byte[NVRAM_EF_BAND_INFO_SIZE];
} nvram_ef_band_info_struct;

typedef struct
{
    kal_uint16 cbmi_mask;
    kal_uint16 cbmir_mask;
    kal_uint16 dcs_mask;
} nvram_ef_cb_mask_struct;

#ifdef __PS_SERVICE__
typedef struct
{
    kal_uint8 byte[NVRAM_EF_MM_EQPLMN_LOCIGPRS_SIZE];
} nvram_ef_mm_eqplmn_locigprs_struct;
#endif /* __PS_SERVICE__ */ 

#ifdef __CTM_SUPPORT__
typedef struct
{
    kal_uint8 ctm_raw_data[NVRAM_EF_CTM_DEFAULT_SETTINGS_SIZE];
} nvram_ef_ctm_default_settings_struct;
#endif /* __CTM_SUPPORT__ */ 

typedef struct
{
    kal_uint8 speech_version;
    kal_uint8 data_cap1;
    kal_uint8 data_cap2;
    kal_uint8 channel_coding;
} nvram_ef_mscap_struct;
#endif /* __L1_STANDALONE__ */ 

typedef struct
{
    kal_uint32 data[4];
}nvram_ef_sim_assert_struct;

typedef struct
{
	kal_uint8		rtc_sec;    /* seconds after the minute   - [0,59]  */
	kal_uint8		rtc_min;    /* minutes after the hour     - [0,59]  */
	kal_uint8		rtc_hour;   /* hours after the midnight   - [0,23]  */
	kal_uint8		rtc_day;    /* day of the month           - [1,31]  */
	kal_uint8		rtc_mon;    /* months 		               - [1,12] */
	kal_uint8		rtc_wday;   /* days in a week 		      - [1,7] */
	kal_uint8		rtc_year;   /* years                      - [0,127] */
} nvram_ef_rtc;


typedef struct
{
    kal_uint8     time_valid;
    nvram_ef_rtc        rtc_time;
    kal_uint8     ticks_diff_valid;
    kal_int32    ticks_diff_per_hour;
} nvram_ef_rtc_calibration;

#ifdef __WCDMA_RAT__  
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __WCDMA_RAT__ */

#if defined(__MA_L1__) || defined(__WCDMA_RAT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#if !defined(__PRODUCTION_RELEASE__) && defined(__FLC2__)
typedef  struct
{ 
    kal_uint8 data[2000];
} nvram_ef_flc_statistics_struct;
#endif /* !__PRODUCTION_RELEASE__ && __FLC2__ */


#ifdef GEN_FOR_PC

/***************************************************************************** 
* META Description
*****************************************************************************/
BEGIN_NVRAM_DATA
/***********************************************************************
  *** This is a nvram data item bit level description for meta tools nvram editor
  ***
  *** Logical Data Item ID : NVRAM_EF_SYS_EXCEPTION_LID
  ***
  *** Module: L1
  ***
  *** Description:
  ***
  *** Maintainer:
  ***
  ***********************************************************************/
    LID_BIT VER_LID(NVRAM_EF_SYS_EXCEPTION_LID)
     EX_LOG_T *NVRAM_EF_SYS_EXCEPTION_TOTAL
     {
     };

 /***********************************************************************
  *** This is a nvram data item bit level description for meta tools nvram editor
  ***
  *** Logical Data Item ID : NVRAM_EF_SYS_STATISTICS_LID
  ***
  *** Module: L1
  ***
  *** Description:
  ***
  *** Maintainer:
  ***
  ***********************************************************************/
     LID_BIT VER_LID(NVRAM_EF_SYS_STATISTICS_LID)
     stack_statistics_struct *NVRAM_EF_SYS_STATISTICS_TOTAL
     {
     };

/******************************
 ***  Section:  L1 Calibration Data
 ******************************/

 /*
  *
  * Notes:  The defination of L1 calibration data structure is located at 
  *            "inc/l1cal.h". Here, provide decriptions only.
  */
 /***********************************************************************
  *** This is a nvram data item bit level description for meta tools nvram editor
  ***
  *** Logical Data Item ID : NVRAM_EF_L1_AGCPATHLOSS_LID
  ***
  *** Module: L1
  ***
  *** Description:
  ***
  *** Maintainer:
  ***
  ***********************************************************************/
     LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_L1_AGCPATHLOSS_LID)
     l1cal_agcPathLoss_T *NVRAM_EF_L1_AGCPATHLOSS_TOTAL
     {

     };

/***********************************************************************
  ***  This is a nvram data item bit level description for meta tools nvram editor
  ***
  ***  Logical Data Item ID : NVRAM_EF_L1_RAMPTABLE_GSM850_LID
  ***
  ***  Module: L1
  ***
  ***  Description:
  ***
  ***  Maintainer:
  ***
  ***********************************************************************/
     LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_L1_RAMPTABLE_GSM850_LID)
     l1cal_rampTable_T *NVRAM_EF_L1_RAMPTABLE_GSM850_TOTAL
     {

     };

/***********************************************************************
  ***  This is a nvram data item bit level description for meta tools nvram editor
  ***
  ***  Logical Data Item ID : NVRAM_EF_L1_RAMPTABLE_GSM900_LID
  ***
  ***  Module: L1
  ***
  ***  Description:
  ***
  ***  Maintainer:
  ***
  ***********************************************************************/
     LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_L1_RAMPTABLE_GSM900_LID)
     l1cal_rampTable_T *NVRAM_EF_L1_RAMPTABLE_GSM900_TOTAL
     {

     };

/***********************************************************************
  ***  This is a nvram data item bit level description for meta tools nvram editor
  ***
  ***  Logical Data Item ID : NVRAM_EF_L1_RAMPTABLE_DCS1800_LID
  ***
  ***  Module: L1
  ***
  ***  Description:
  ***
  ***  Maintainer:
  ***
  ***********************************************************************/
     LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_L1_RAMPTABLE_DCS1800_LID)
     l1cal_rampTable_T *NVRAM_EF_L1_RAMPTABLE_DCS1800_TOTAL
     {
     };

/***********************************************************************
  ***  This is a nvram data item bit level description for meta tools nvram editor
  ***
  ***  Logical Data Item ID : NVRAM_EF_L1_RAMPTABLE_PCS1900_LID
  ***
  ***  Module: L1
  ***
  ***  Description:
  ***
  ***  Maintainer:
  ***
  ***********************************************************************/
     LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_L1_RAMPTABLE_PCS1900_LID)
     l1cal_rampTable_T *NVRAM_EF_L1_RAMPTABLE_DCS1800_TOTAL
     {
     };
 #if defined(__EPSK_TX__)

/***********************************************************************
  ***  This is a nvram data item bit level description for meta tools nvram editor
  ***
  ***  Logical Data Item ID : NVRAM_EF_L1_EPSK_RAMPTABLE_GSM850_LID
  ***
  ***  Module: L1
  ***
  ***  Description:
  ***
  ***  Maintainer:
  ***
  ***********************************************************************/
     LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_L1_EPSK_RAMPTABLE_GSM850_LID)
     l1cal_rampTable_T *NVRAM_EF_L1_EPSK_RAMPTABLE_GSM850_TOTAL
     {

     };

/***********************************************************************
  ***  This is a nvram data item bit level description for meta tools nvram editor
  ***
  ***  Logical Data Item ID : NVRAM_EF_L1_EPSK_RAMPTABLE_GSM900_LID
  ***
  ***  Module: L1
  ***
  ***  Description:
  ***
  ***  Maintainer:
  ***
  ***********************************************************************/
     LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_L1_EPSK_RAMPTABLE_GSM900_LID)
     l1cal_rampTable_T *NVRAM_EF_L1_EPSK_RAMPTABLE_GSM900_TOTAL
     {

     };

/***********************************************************************
  ***  This is a nvram data item bit level description for meta tools nvram editor
  ***
  ***  Logical Data Item ID : NVRAM_EF_L1_RAMPTABLE_DCS1800_LID
  ***
  ***  Module: L1
  ***
  ***  Description:
  ***
  ***  Maintainer:
  ***
  ***********************************************************************/
     LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_L1_EPSK_RAMPTABLE_DCS1800_LID)
     l1cal_rampTable_T *NVRAM_EF_L1_EPSK_RAMPTABLE_DCS1800_TOTAL
     {
     };

/***********************************************************************
  ***  This is a nvram data item bit level description for meta tools nvram editor
  ***
  ***  Logical Data Item ID : NVRAM_EF_L1_EPSK_RAMPTABLE_PCS1900_LID
  ***
  ***  Module: L1
  ***
  ***  Description:
  ***
  ***  Maintainer:
  ***
  ***********************************************************************/
     LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_L1_EPSK_RAMPTABLE_PCS1900_LID)
     l1cal_rampTable_T *NVRAM_EF_L1_EPSK_RAMPTABLE_DCS1800_TOTAL
     {
     };

/***********************************************************************
  ***  This is a nvram data item bit level description for meta tools nvram editor
  ***
  ***  Logical Data Item ID : NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_GSM850_LID
  ***
  ***  Module: L1
  ***
  ***  Description:
  ***
  ***  Maintainer:
  ***
  ***********************************************************************/
     LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_GSM850_LID)
     l1cal_EPSK_interRampData_T *NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_GSM850_TOTAL
     {
     };

/***********************************************************************
  ***  This is a nvram data item bit level description for meta tools nvram editor
  ***
  ***  Logical Data Item ID : NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_GSM900_LID
  ***
  ***  Module: L1
  ***
  ***  Description:
  ***
  ***  Maintainer:
  ***
  ***********************************************************************/
     LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_GSM900_LID)
     l1cal_EPSK_interRampData_T *NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_GSM900_TOTAL
     {
     };

/***********************************************************************
  ***  This is a nvram data item bit level description for meta tools nvram editor
  ***
  ***  Logical Data Item ID : NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_DCS1800_LID
  ***
  ***  Module: L1
  ***
  ***  Description:
  ***
  ***  Maintainer:
  ***
  ***********************************************************************/
     LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_DCS1800_LID)
     l1cal_EPSK_interRampData_T *NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_DCS1800_TOTAL
     {
     };

/***********************************************************************
  ***  This is a nvram data item bit level description for meta tools nvram editor
  ***
  ***  Logical Data Item ID : NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_PCS1900_LID
  ***
  ***  Module: L1
  ***
  ***  Description:
  ***
  ***  Maintainer:
  ***
  ***********************************************************************/
     LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_PCS1900_LID)
     l1cal_EPSK_interRampData_T *NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_PCS1900_TOTAL
     {
     };

 #endif /* defined(__EPSK_TX__) */ 

#if defined(__WCDMA_RAT__) && defined(__MTK_UL1_FDD__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __WCDMA_RAT__ && __MTK_UL1_FDD__ */     
/***********************************************************************
  ***  This is a nvram data item bit level description for meta tools nvram editor
  ***
  ***  Logical Data Item ID : NVRAM_EF_L1_AFCDATA_LID
  ***
  ***  Module: L1
  ***
  ***  Description:
  ***
  ***  Maintainer:
  ***
  ***********************************************************************/
     LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_L1_AFCDATA_LID)
     l1cal_afcData_T *NVRAM_EF_L1_AFCDATA_TOTAL
     {
     };

/***********************************************************************
  ***  This is a nvram data item bit level description for meta tools nvram editor
  ***
  ***  Logical Data Item ID : NVRAM_EF_L1_TXIQ_LID
  ***
  ***  Module: L1
  ***
  ***  Description:
  ***
  ***  Maintainer:
  ***
  ***********************************************************************/
     LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_L1_TXIQ_LID)
     l1cal_txiq_T *NVRAM_EF_L1_TXIQ_TOTAL
     {
     };

/***********************************************************************
  ***  This is a nvram data item bit level description for meta tools nvram editor
  ***
  ***  Logical Data Item ID : NVRAM_EF_L1_RFSPECIALCOEF_LID
  ***
  ***  Module: L1
  ***
  ***  Description:
  ***
  ***  Maintainer:
  ***
  ***********************************************************************/
     LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_L1_RFSPECIALCOEF_LID)
     l1cal_rfspecialcoef_T *NVRAM_EF_L1_RFSPECIALCOEF_TOTAL
     {
     };
 #ifdef __PS_SERVICE__
/***********************************************************************
  ***  This is a nvram data item bit level description for meta tools nvram editor
  ***
  ***  Logical Data Item ID : NVRAM_EF_L1_INTERSLOT_RAMP_GSM850_LID
  ***
  ***  Module: L1
  ***
  ***  Description:
  ***
  ***  Maintainer:
  ***
  ***********************************************************************/
     LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_L1_INTERSLOT_RAMP_GSM850_LID)
     l1cal_interRampData_T *NVRAM_EF_L1_INTERSLOT_RAMP_GSM850_TOTAL
     {
     };

/***********************************************************************
  ***  This is a nvram data item bit level description for meta tools nvram editor
  ***
  ***  Logical Data Item ID : NVRAM_EF_L1_INTERSLOT_RAMP_GSM900_LID
  ***
  ***  Module: L1
  ***
  ***  Description:
  ***
  ***  Maintainer:
  ***
  ***********************************************************************/
     LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_L1_INTERSLOT_RAMP_GSM900_LID)
     l1cal_interRampData_T *NVRAM_EF_L1_INTERSLOT_RAMP_GSM900_TOTAL
     {
     };

/***********************************************************************
  ***  This is a nvram data item bit level description for meta tools nvram editor
  ***
  ***  Logical Data Item ID : NVRAM_EF_L1_INTERSLOT_RAMP_DCS1800_LID
  ***
  ***  Module: L1
  ***
  ***  Description:
  ***
  ***  Maintainer:
  ***
  ***********************************************************************/
     LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_L1_INTERSLOT_RAMP_DCS1800_LID)
     l1cal_interRampData_T *NVRAM_EF_L1_INTERSLOT_RAMP_DCS1800_TOTAL
     {
     };

/***********************************************************************
  ***  This is a nvram data item bit level description for meta tools nvram editor
  ***
  ***  Logical Data Item ID : NVRAM_EF_L1_INTERSLOT_RAMP_PCS1900_LID
  ***
  ***  Module: L1
  ***
  ***  Description:
  ***
  ***  Maintainer:
  ***
  ***********************************************************************/
     LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_L1_INTERSLOT_RAMP_PCS1900_LID)
     l1cal_interRampData_T *NVRAM_EF_L1_INTERSLOT_RAMP_PCS1900_TOTAL
     {
     };
 #endif /* __PS_SERVICE__ */ 
/***********************************************************************
  ***  This is a nvram data item bit level description for meta tools nvram editor
  ***
  ***  Logical Data Item ID : NVRAM_EF_L1_CRYSTAL_AFCDATA_LID
  ***
  ***  Module: L1
  ***
  ***  Description:
  ***
  ***  Maintainer:
  ***
  ***********************************************************************/
     LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_L1_CRYSTAL_AFCDATA_LID)
     l1cal_crystalAfcData_T *NVRAM_EF_L1_CRYSTAL_AFCDATA_TOTAL
     {
     };

/***********************************************************************
  ***  This is a nvram data item bit level description for meta tools nvram editor
  ***
  ***  Logical Data Item ID : NVRAM_EF_L1_CRYSTAL_CAPDATA_LID
  ***
  ***  Module: L1
  ***
  ***  Description:
  ***
  ***  Maintainer:
  ***
  ***********************************************************************/
     LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_L1_CRYSTAL_CAPDATA_LID)
     l1cal_crystalCapData_T *NVRAM_EF_L1_CRYSTAL_CAPDATA_TOTAL
     {
     };

 #if defined(__WIFI_SUPPORT__)
/***********************************************************************
  ***  This is a nvram data item bit level description for meta tools nvram editor
  ***
  ***  Logical Data Item ID : NVRAM_EF_WNDRV_MAC_ADDRESS_LID
  ***
  ***  Module: WNDRV
  ***
  ***  Description:
  ***
  ***  Maintainer:
  ***
  ***********************************************************************/
     LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_WNDRV_MAC_ADDRESS_LID)
     wndrv_cal_mac_addr_struct *NVRAM_EF_WNDRV_MAC_ADDRESS_TOTAL
     {
     };

/***********************************************************************
  ***  This is a nvram data item bit level description for meta tools nvram editor
  ***
  ***  Logical Data Item ID : NVRAM_EF_WNDRV_TX_POWER_2400M_LID
  ***
  ***  Module: WNDRV
  ***
  ***  Description:
  ***
  ***  Maintainer:
  ***
  ***********************************************************************/
     LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_WNDRV_TX_POWER_2400M_LID)
     wndrv_cal_txpwr_2400M_struct *NVRAM_EF_WNDRV_TX_POWER_2400M_TOTAL
     {
     };

/***********************************************************************
  ***  This is a nvram data item bit level description for meta tools nvram editor
  ***
  ***  Logical Data Item ID : NVRAM_EF_WNDRV_TX_POWER_5000M_LID
  ***
  ***  Module: WNDRV
  ***
  ***  Description:
  ***
  ***  Maintainer:
  ***
  ***********************************************************************/
     LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_WNDRV_TX_POWER_5000M_LID)
     wndrv_cal_txpwr_5000M_struct *NVRAM_EF_WNDRV_TX_POWER_5000M_TOTAL
     {
     };

/***********************************************************************
  ***  This is a nvram data item bit level description for meta tools nvram editor
  ***
  ***  Logical Data Item ID : NVRAM_EF_WNDRV_DAC_DC_OFFSET_LID
  ***
  ***  Module: WNDRV
  ***
  ***  Description:
  ***
  ***  Maintainer:
  ***
  ***********************************************************************/
     LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_WNDRV_DAC_DC_OFFSET_LID)
     wndrv_cal_dac_dc_offset_struct *NVRAM_EF_WNDRV_DAC_DC_OFFSET_TOTAL
     {
     };

     LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_WNDRV_TX_ALC_POWER_LID)
     wndrv_cal_tx_ALC_2400M_struct *NVRAM_EF_WNDRV_TX_ALC_POWER_TOTAL
     {
     };

     LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_WNDRV_ALC_SLOPE_LID)
     wndrv_cal_ALC_Slope_2400M_struct *NVRAM_EF_WNDRV_ALC_SLOPE_TOTAL
     {
     };

 #endif /* defined(__WIFI_SUPPORT__) */ 

 #ifndef __L1_STANDALONE__
/***********************************************************************
  ***  This is a nvram data item bit level description for meta tools nvram editor
  ***
  ***  Logical Data Item ID : NVRAM_EF_EXTBCCH_LID
  ***
  ***  Module: 
  ***
  ***  Description:
  ***
  ***  Maintainer: Claire
  ***
  ***********************************************************************/
     LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EXTBCCH_LID)
     nvram_ef_extbcch_struct *NVRAM_EF_EXTBCCH_TOTAL
     {
         mcc1:"mobile country code 1 "
         {
         };

       mcc2:"mobile country code 2 "
         {
         };
       mcc3:"mobile country code 3 "
         {
         };
       mnc1:"mobile network code 1 "
         {
         };
       mnc2:"mobile network code 2 "
         {
         };
       mnc3:"mobile network code 3 "
         {
         };
       arfcn_MSB:"last time serving cell arfcn MSB "
         {
         };
       arfcn_LSB:"last time serving cell arfcn LSB "
         {
         };
       byte:"Extended BCCH Frequency List (Refer to 04.18 10.5.2.22, Neighbour Cell Description"
         {
         };
     };

 #ifdef __R99__
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EQ_PLMN_LID)
     nvram_ef_eq_plmn_struct *NVRAM_EF_EQ_PLMN_TOTAL
     {
     };
 #endif /* __R99__ */ 

     LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_BAND_INFO_LID)
     nvram_ef_band_info_struct *NVRAM_EF_BAND_INFO_TOTAL
     {
     };

/***********************************************************************
  ***  This is a nvram data item bit level description for meta tools nvram editor
  ***
  ***  Logical Data Item ID : NVRAM_EF_TST_FILTER_LID
  ***
  ***  Module: TST
  ***
  ***  Description:
  ***
  ***  Maintainer:
  ***
  ***********************************************************************/
/* Lisen 0604 TST */
     LID_BIT VER_LID(NVRAM_EF_TST_FILTER_LID)
     nvram_ef_tst_filter_struct *NVRAM_EF_TST_FILTER_TOTAL
     {
         nvram_ef_tst_filter:"tst specific data"
         {
         };
     };

/***********************************************************************
  ***  This is a nvram data item bit level description for meta tools nvram editor
  ***
  ***  Logical Data Item ID : NVRAM_EF_CB_CH_INFO_LID
  ***
  ***  Module: SMS
  ***
  ***  Description:  
  ***
  ***  Maintainer: Johnnie Chen
  ***
  ***********************************************************************/
LID_BIT VER_LID(NVRAM_EF_CB_CH_INFO_LID)
     nvram_ef_cb_ch_info_struct *NVRAM_EF_CB_CH_INFO_TOTAL
     {
         cbmir_mask:"CBMIR MASK"
         {
           cbmir_0:1 "CBMIR [0]"
             {
               0x0:"Disable";
                 0x1:"Enable";
             };

           cbmir_1:1 "CBMIR [1]"
             {
               0x0:"Disable";
               0x1:"Enable";
             };

           cbmir_2:1 "CBMIR [2]"
             {
               0x0:"Disable";
               0x1:"Enable";
             };

           cbmir_3:1 "CBMIR [3]"
             {
               0x0:"Disable";
               0x1:"Enable";
             };

           cbmir_4:1 "CBMIR [4]"
             {
               0x0:"Disable";
               0x1:"Enable";
             };

           cbmir_5:1 "CBMIR [5]"
             {
               0x0:"Disable";
               0x1:"Enable";
             };

           cbmir_6:1 "CBMIR [6]"
             {
               0x0:"Disable";
               0x1:"Enable";
             };

           cbmir_7:1 "CBMIR [7]"
             {
               0x0:"Disable";
               0x1:"Enable";
             };

           cbmir_8_15:8 "CBMIR [8] ~ [15], Same as above"
             {
             };
         };

       dcs_mask:"DCS MASK"
         {
           dcs_mask_0:8 "DCS [0] ~ DCS [7]"
             {
             };

           dcs_mask_8:8 "DCS [8] ~ DCS [15]"
             {
             };

         };

       cbmi_mask:"CBMI MASK"
         {
           cbmi_mask:24 "CBMI_MASK for ME"
             {
             };

           cbmi_mask:24 "CBMI_MASK for SIM"
             {
             };
         };

       cbmi:"CBMI storage in ME";
     };

/***********************************************************************
  ***  This is a nvram data item bit level description for meta tools nvram editor
  ***
  ***  Logical Data Item ID : NVRAM_EF_SMSAL_MWIS_LID
  ***
  ***  Module: SMSAL
  ***
  ***  Description:
  ***
  ***  Maintainer: Keven Chien
  ***
  ***********************************************************************/
LID_BIT VER_LID(NVRAM_EF_SMSAL_MWIS_LID)
     nvram_ef_smsal_mwis_struct *NVRAM_EF_SMSAL_MWIS_TOTAL
     {
         message_waiting_indication_status:"Message waiting indication status";
         message_waiting_indication_status[0]
         {
           vm:1 "Voice mail"
             {
               0x0:"Set indication active";
                 0x1:"Set indication inactive";
             };

           fax:1 "FAX"
             {
               0x0:"Set indication active";
               0x1:"Set indication inactive";
             };

           email:1 "Email"
             {
               0x0:"Set indication active";
               0x1:"Set indication inactive";
             };

           other:1 "Other"
             {
               0x0:"Set indication active";
               0x1:"Set indication inactive";
             };

           RFU:4 "RFU"
             {
               0x0:"Set indication active";
               0x1:"Set indication inactive";
             };
         };

         message_waiting_indication_status[1]
         {
           vm:8 "Number of Voicemail message waiting"
             {
             };
         };

         message_waiting_indication_status[2]
         {
           fm:8 "Number of fax mail message waiting"
             {
             };
         };

         message_waiting_indication_status[3]
         {
           em:8 "Number of email message waiting"
             {
             };
         };

         message_waiting_indication_status[4]
         {
           om:8 "Number of other message waiting"
             {
             };
         };

       pad:"Padding"
         {
         };
     };

/***********************************************************************
  ***  This is a nvram data item bit level description for meta tools nvram editor
  ***
  ***  Logical Data Item ID : NVRAM_EF_TCM_STATISTICS_LID
  ***
  ***  Module: 
  ***
  ***  Description:  
  ***
  ***  Maintainer: 
  ***
  ***********************************************************************/
LID_BIT VER_LID(NVRAM_EF_TCM_STATISTICS_LID)
     nvram_ef_tcm_statistics_struct *NVRAM_EF_TCM_STATISTICS_TOTAL
     {
         total_rx_data:"Total received bytes"
         {
         };

       total_tx_data:"Total transmitted bytes"
         {
         };
       last_rx_data:"Received bytes of last"
         {
         };
       last_tx_data:"Transmitted bytes of last call"
         {
         };
     };

/***********************************************************************
  ***  This is a nvram data item bit level description for meta tools nvram editor
  ***
  ***  Logical Data Item ID : NVRAM_EF_CFU_FLAG_LID
  ***
  ***  Module: 
  ***
  ***  Description:  
  ***
  ***  Maintainer: Paul Yuang
  ***
  ***********************************************************************/
LID_BIT VER_LID(NVRAM_EF_CFU_FLAG_LID)
     nvram_ef_cfu_flag_struct *NVRAM_EF_CFU_FLAG_TOTAL
     {
         cfu_flag:"CFU flag"
         {
         };
     };

 #ifdef __PS_SERVICE__
LID_BIT VER_LID(NVRAM_EF_MM_EQPLMN_LOCIGPRS_LID)
     nvram_ef_mm_eqplmn_locigprs_struct * NVRAM_EF_MM_EQPLMN_LOCIGPRS_TOTAL
     {
     };
 #endif /* __PS_SERVICE__ */ 

 #ifdef __CTM_SUPPORT__
     LID_BIT VER_LID(NVRAM_EF_CTM_DEFAULT_SETTINGS_LID)
     nvram_ef_ctm_default_settings_struct *NVRAM_EF_CTM_DEFAULT_SETTINGS_TOTAL
     {
     };
 #endif /* __CTM_SUPPORT__ */ 
/***********************************************************************
  ***  This is a nvram data item bit level description for meta tools nvram editor
  ***
  ***  Logical Data Item ID : NVRAM_EF_MSCAP_LID
  ***
  ***  Module:
  ***
  ***  Description:
  ***
  ***  Maintainer:
  ***
  ***********************************************************************/
     LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_MSCAP_LID)
     nvram_ef_mscap_struct *NVRAM_EF_MSCAP_TOTAL
     {
         speech_version:"Supported speech version"
         {
           FR:1 "FR"
             {
               0x0:"Not supported";
                 0x1:"Supported";
             };

           HR:1 "HR"
             {
               0x0:"Not supported";
               0x1:"Supported";
             };

           EFR:1 "EFR"
             {
               0x0:"Not supported";
               0x1:"Supported";
             };

           AMR_FR:1 "AMR FR"
             {
               0x0:"Not supported";
               0x1:"Supported";
             };

           AMR_HR:1 "AMR HR"
             {
               0x0:"Not supported";
               0x1:"Supported";
             };
         };

       data_cap1:"Supported speech version"
         {
           CSD:1 "CSD"
             {
               0x0:"Not Supported";
               0x1:"Supported";
             };

           trans_fax:1 "Transparent Fax"
             {
               0x0:"Not Supported";
               0x1:"Supported";
             };

           non_trans_fax:1 "Non-transparent Fax"
             {
               0x0:"Not Supported";
               0x1:"Supported";
             };

           trans_data_cs:1 "Transparent data circuit synchronous"
             {
               0x0:"Not Supported";
               0x1:"Supported";
             };

           non_trans_data_cs:1 "Non-transparent data circuit synchronous"
             {
               0x0:"Not Supported";
               0x1:"Supported";
             };

           trans_data_acs:1 "Transparent data circuit asynchronous"
             {
               0x0:"Not Supported";
               0x1:"Supported";
             };

           non_trans_data_acs:1 "Non-transparent data circuit asynchronous"
             {
               0x0:"Not Supported";
               0x1:"Supported";
             };

           trans_PAD_aa:1 "Transparent PAD access asynchronous"
             {
               0x0:"Not Supported";
               0x1:"Supported";
             };
         };

       data_cap2:"Supported speech version"
         {
           non_trans_PAD_aa:1 "Non-transparent PAD access asynchronous"
             {
               0x0:"Not Supported";
               0x1:"Supported";
             };

           trans_data_ps:1 "Transparent data packet synchronous"
             {
               0x0:"Not Supported";
               0x1:"Supported";
             };

           non_trans_PAD_pas:1 "Non-transparent data packet asynchronous"
             {
               0x0:"Not Supported";
               0x1:"Supported";
             };

           HSCSD_multislot:5 "HSCSD multislot class"
             {
             };

         };

       channel_coding:"Supported speech version"
         {
           tch_f48:1 "TCH/F4.8"
             {
               0x0:"Not Supported";
               0x1:"Supported";
             };

           tch_f96:1 "TCH/F9.6"
             {
               0x0:"Not Supported";
               0x1:"Supported";
             };

           tch_f144:1 "TCH/F14.4"
             {
               0x0:"Not Supported";
               0x1:"Supported";
             };

           tch_f288:1 "TCH/F28.8"
             {
               0x0:"Not Supported";
               0x1:"Supported";
             };

           tch_f32:1 "TCH/F32"
             {
               0x0:"Not Supported";
               0x1:"Supported";
             };

           tch_f432:1 "TCH/F43.2"
             {
               0x0:"Not Supported";
               0x1:"Supported";
             };
         };
     };

 #if defined (__CCM_NO_RESET__)
/***********************************************************************
  ***  This is a nvram data item bit level description for meta tools nvram editor
  ***
  ***  Logical Data Item ID : NVRAM_EF_ALS_LINE_ID_LID
  ***
  ***  Module:
  ***
  ***  Description:
  ***
  ***  Maintainer: Paul Yuang
  ***
  ***********************************************************************/
LID_BIT VER_LID(NVRAM_EF_ALS_LINE_ID_LID)
     nvram_ef_als_line_id_struct *NVRAM_EF_ALS_LINE_ID_TOTAL
     {
         als_line_id:"als_line_id"
         {
         };
	 last_ccm: "last call cost"
	 {
	 };
     };
 #elif defined (__CPHS__)
 LID_BIT VER_LID(NVRAM_EF_ALS_LINE_ID_LID)
     nvram_ef_als_line_id_struct *NVRAM_EF_ALS_LINE_ID_TOTAL
     {
         als_line_id:"als_line_id"
         {
         };
     };
 #endif  

LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_CLASSMARK_RACAP_LID)
     nvram_ef_classmark_racap_struct *NVRAM_EF_CLASSMARK_RACAP_TOTAL
     {
         byte1:""
         {
           a54:1 "A5/4"
             {
             };

           a55:1 "A5/5"
             {
             };
           a56:1 "A5/6"
             {
             };
           a57:1 "A5/7"
             {
             };
           band3:1 "Band 3"
             {
             };
           band2:1 "Band 2"
             {
             };
           band1:1 "Band 1"
             {
             };
           spare:1 "Spare"
             {
             };
         };

       byte2:""
         {
           radio_cap1:4
             {
             };
           radio_cap2:4
             {
             };
         };

       byte3:""
         {
           ucs2:1 "UCS2 treatment"
             {
             };
           hscsd_mtslot_cap:5 "HSCSD Multi slot capability"
             {
             };
           hscsd_mtslot_cap_p:1 "HSCSD Multi slot capability present"
             {
             };
           rsupport:1 "R-GSM support"
             {
             };
         };

       byte4:""
         {
           gsm400_p:1 "GSM400 present"
             {
             };
           ms_posi_method:5 "MS Positioning method"
             {
             };
           ms_posi_method_p:1 "MS Positioning method present"
             {
             };
           em_cap:1 "Extended Measurement Capability"
             {
             };
         };

       byte5_byte6:""
         {
           gsm1900_r_cap:4 "GSM1900 Radio Capability"
             {
             };
           gsm1900_r_cap_p:1 "GSM1900 Radio Capability present"
             {
             };
           gsm850_r_cap:4 "GSM850 Radio Capability"
             {
             };
           gsm850_r_cap_p:1 "GSM850 Radio Capability present"
             {
             };
           gsm400_r_cap:4 "GSM400 Radio Capability"
             {
             };
           gsm400_supp:2 "GSM400 Bands Supported"
             {
             };
         };

       byte7:"Octet3 of Mobile Station Classmark2 information element"
         {
           spare:3 "Spare"
             {
             };
           a51:1 "A5/1"
             {
             };
           es_ind:1 "ES IND"
             {
             };
           rev_level:2 "Revision level"
             {
             };
           spare:1 "Spare"
             {
             };
         };

         /* Default: 0x78, PS capability present, ss=3, MT-PP SMS supported, on support E-GSM */
       byte8:"Octet4 of Mobile Station Classmark2 information element"
         {
           spare:1 "Spare"
             {
             };
           vgcs:1 "VGCS"
             {
             };
           vbs:1 "VBS"
             {
             };
           sm_cap:1 "SM capability"
             {
             };
           SSScr_ind:2 "SS Screen Indicator"
             {
             };
           ps_cap:1 "PS capability"
             {
             };
           spare:1 "Spare"
             {
             };
         };

         /* Default: 0x81, Classmark3 present, A5/2 supported */
       byte9:"Octet5 of Mobile Station Classmark2 information element"
         {
           a52:1 "A5/2"
             {
             };
           a53:1 "A5/3"
             {
             };
           cmsp:1 "CMSP"
             {
             };
           solsa:1 "SoLSA"
             {
             };
           spare:1 "Spare"
             {
             };
           lcsva_cap:1 "LCSVA CAP"
             {
             };
           spare:1 "Spare"
             {
             };
           cm3:1 "Support options in Classmark 3"
             {
             };
         };

       byte10:"GPRS related parameters used in Mobile Station Radio Access Capability IE"
         {
           rev_level_ind:1 "Revision Level Indicator"
             {
             };
           gprs_ext_dyna_cap:1 "GPRS Extended Dynamic Allocation Capability"
             {
             };
           gprs_mtslot_cap:5 "GPRS Multi slot capability"
             {
             };
           gprs_mtslot_cap_p:1 "GPRS Multi slot capability present"
             {
             };
         };

       byte11:"GPRS related parameters used in Mobile network capability IE"
         {
           gea_1:1 "GEA7"
             {
             };
           gea_2:1 "GEA6"
             {
             };
           gea_3:1 "GEA5"
             {
             };
           gea_4:1 "GEA4"
             {
             };
           gea_5:1 "GEA3"
             {
             };
           gea_6:1 "GEA2"
             {
             };
           gea_7:1 "GEA1"
             {
             };
           sm_cap_gprs:1 "SM capabilities via GPRS channels"
             {
             };
         };

       byte12:"GPRS related parameters used in Mobile network capability IE"
         {
           pfc:1 "BSS packet flow proedure"
             {
             };
           spare:7 "Spare"
             {
             };
         };

     };
#ifdef __WCDMA_RAT__     
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __WCDMA_RAT__ */
#if defined(__MA_L1__) || defined(__WCDMA_RAT__)
/* under construction !*/
#endif

#if !defined(__PRODUCTION_RELEASE__) && defined(__FLC2__)
LID_BIT VER_LID(NVRAM_EF_FLC_STATISTICS_LID) nvram_ef_flc_statistics_struct * NVRAM_EF_FLC_STATISTICS_TOTAL{};
#endif /* !__PRODUCTION_RELEASE__ && __FLC2__ */
 #endif /* __L1_STANDALONE__ */ 

LID_BIT VER_LID(NVRAM_EF_SIM_ASSERT_LID) nvram_ef_sim_assert_struct* NVRAM_EF_SIM_ASSERT_TOTAL {};

END_NVRAM_DATA
#endif /* GEN_FOR_PC */ 
#endif /* __MAUI_BASIC__ */ 
#endif /* NVRAM_EDTIOR_DATA_ITEM_SYSTEM_H */ 

