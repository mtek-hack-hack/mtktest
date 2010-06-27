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
 * mph_cs_def.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contains common typedef, definition prototypes exported by L1A
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
 * removed!
 *
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _MPH_CS_DEF_H
#define _MPH_CS_DEF_H

#ifndef _MPH_TYPES_H
#error "mph_types.h should be included before mph_cs_def.h"
#endif


#define MPH_N201_MAX                          (23)
#define MPH_MAX_POWER_SCAN_ARFCN_COUNT        (200)
#define MPH_MAX_BA_LIST_LEN                   (32)
#ifdef __BA_RANGE__
#define MPH_MAX_STORED_BA_LIST_LEN            (96)
#else
#define MPH_MAX_STORED_BA_LIST_LEN            (33)
#endif
#define MPH_MAX_HOPPING_FREQ_LIST_LEN         (64)
#define MPH_MAX_EXT_MEAS_FREQ_LIST_LEN        (33)
#define MPH_MAX_NEIGHBOR_BSIC_NUM             (32)
#define MPH_MAX_NEIGHBOR_BCCH_NUM             (1)
#define MPH_CIPHER_KEY_LENGTH                 (8)

#define MPH_PGSM900 0x01 /* PGSM900 1..124 */
#define MPH_EGSM900 0x02 /* EGSM900 0..124, 975..1023 */
#define MPH_RGSM900 0x04 /* RGSM900 0..124, 955..1023 */
#define MPH_DCS1800 0x08 /* DCS1800 512..885 */
#define MPH_PCS1900 0x10 /* PCS1900 512..810 */
#define MPH_GSM450  0x20 /* GSM450  259..293 */
#define MPH_GSM480  0x40 /* GSM480  306..340 */
#define MPH_GSM850  0x80 /* GSM850  128..251 */

/*************************************************************************************
*  Decide power scan arfcn count
*  User can tune MPH_MAX_POWER_SCAN_ARFCN_COUNT to decide the POWER SCAN MAX LENGTH
*************************************************************************************/
#define MPH_PGSM900_ARFCN_COUNT (124-1+1)                /* PGSM900 1..124 */
#define MPH_EGSM900_ARFCN_COUNT ((124-0+1)+(1023-975+1)) /* EGSM900 0..124, 975..1023 */
#define MPH_RGSM900_ARFCN_COUNT ((124-0+1)+(1023-955+1)) /* RGSM900 0..124, 955..1023 */
#define MPH_DCS1800_ARFCN_COUNT (885-512+1)              /* DCS1800 512..885 */
#define MPH_PCS1900_ARFCN_COUNT (810-512+1)              /* PCS1900 512..810 */
#define MPH_GSM450_ARFCN_COUNT  (293-259+1)              /* GSM450  259..293 */
#define MPH_GSM480_ARFCN_COUNT  (340-306+1)              /* GSM480  306..340 */
#define MPH_GSM850_ARFCN_COUNT  (251-128+1)              /* GSM850  128..251 */
#define MPH_MAX_POWER_SCAN_GSM850_RESULTS_LEN  40
#define MPH_MAX_POWER_SCAN_GSM900_RESULTS_LEN  40
#define MPH_MAX_POWER_SCAN_DCS1800_RESULTS_LEN 40
#define MPH_MAX_POWER_SCAN_PCS1900_RESULTS_LEN 40

#ifdef __PGSM900__ /* PGSM900 1..124 */
  #define TEMP_MPH_PGSM900 MPH_PGSM900
  #define TEMP_MPH_MAX_POWER_SCAN_RESULTS_LEN_PGSM900  MPH_PGSM900_ARFCN_COUNT
#else
  #define TEMP_MPH_PGSM900 0
  #define TEMP_MPH_MAX_POWER_SCAN_RESULTS_LEN_PGSM900 (0)
#endif

#ifdef __EGSM900__ /* EGSM900 0..124, 975..1023 */
  #define TEMP_MPH_EGSM900 (MPH_PGSM900|MPH_EGSM900)
 #ifdef __PGSM900__ 
  #define TEMP_MPH_MAX_POWER_SCAN_RESULTS_LEN_EGSM900 (MPH_EGSM900_ARFCN_COUNT-                      \
                                                       TEMP_MPH_MAX_POWER_SCAN_RESULTS_LEN_PGSM900)
 #else
  #define TEMP_MPH_MAX_POWER_SCAN_RESULTS_LEN_EGSM900 (MPH_EGSM900_ARFCN_COUNT)
 #endif
#else
  #define TEMP_MPH_EGSM900 0
  #define TEMP_MPH_MAX_POWER_SCAN_RESULTS_LEN_EGSM900 (0)
#endif

#ifdef __RGSM900__ /* RGSM900 0..124, 955..1023 */
  #define TEMP_MPH_RGSM900 (MPH_PGSM900|MPH_EGSM900|MPH_RGSM900)
 #if defined( __PGSM900__ ) && defined( __EGSM900__ )
  #define TEMP_MPH_MAX_POWER_SCAN_RESULTS_LEN_RGSM900 (MPH_RGSM900_ARFCN_COUNT-                     \
                                                       TEMP_MPH_MAX_POWER_SCAN_RESULTS_LEN_PGSM900- \
                                                       TEMP_MPH_MAX_POWER_SCAN_RESULTS_LEN_EGSM900)
 #elif defined( __PGSM900__ )
  #define TEMP_MPH_MAX_POWER_SCAN_RESULTS_LEN_RGSM900 (MPH_RGSM900_ARFCN_COUNT-                     \
                                                       TEMP_MPH_MAX_POWER_SCAN_RESULTS_LEN_PGSM900)
 #elif defined( __EGSM900__ )
  #define TEMP_MPH_MAX_POWER_SCAN_RESULTS_LEN_RGSM900 (MPH_RGSM900_ARFCN_COUNT-                     \
                                                       TEMP_MPH_MAX_POWER_SCAN_RESULTS_LEN_EGSM900)
 #else
  #define TEMP_MPH_MAX_POWER_SCAN_RESULTS_LEN_RGSM900  MPH_RGSM900_ARFCN_COUNT
 #endif
#else
  #define TEMP_MPH_RGSM900 0
  #define TEMP_MPH_MAX_POWER_SCAN_RESULTS_LEN_RGSM900 (0)
#endif

#ifdef __DCS1800__ /* DCS1800 512..885 */
  #define TEMP_MPH_DCS1800 MPH_DCS1800
  #define TEMP_MPH_MAX_POWER_SCAN_RESULTS_LEN_DCS1800  MPH_DCS1800_ARFCN_COUNT
#else
  #define TEMP_MPH_DCS1800 0
  #define TEMP_MPH_MAX_POWER_SCAN_RESULTS_LEN_DCS1800 (0)
#endif

#ifdef __PCS1900__ /* PCS1900 512..810 */
  #define TEMP_MPH_PCS1900 MPH_PCS1900
 #ifndef __DCS1800__
  #define TEMP_MPH_MAX_POWER_SCAN_RESULTS_LEN_PCS1900  MPH_PCS1900_ARFCN_COUNT
 #else
  #define TEMP_MPH_MAX_POWER_SCAN_RESULTS_LEN_PCS1900 (0)
 #endif
#else
  #define TEMP_MPH_PCS1900 0
  #define TEMP_MPH_MAX_POWER_SCAN_RESULTS_LEN_PCS1900 (0)
#endif

#ifdef __GSM450__ /* GSM450  259..293 */
  #define TEMP_MPH_GSM450 MPH_GSM450
  #define TEMP_MPH_MAX_POWER_SCAN_RESULTS_LEN_GSM450  MPH_GSM450_ARFCN_COUNT
#else
  #define TEMP_MPH_GSM450 0
  #define TEMP_MPH_MAX_POWER_SCAN_RESULTS_LEN_GSM450  (0)
#endif

#ifdef __GSM480__ /* GSM480  306..340 */
  #define TEMP_MPH_GSM480 MPH_GSM480
  #define TEMP_MPH_MAX_POWER_SCAN_RESULTS_LEN_GSM480  MPH_GSM480_ARFCN_COUNT
#else
  #define TEMP_MPH_GSM480 0
  #define TEMP_MPH_MAX_POWER_SCAN_RESULTS_LEN_GSM480  (0)
#endif

#ifdef __GSM850__ /* GSM850  128..251 */
  #define TEMP_MPH_GSM850 MPH_GSM850
  #define TEMP_MPH_MAX_POWER_SCAN_RESULTS_LEN_GSM850  MPH_GSM850_ARFCN_COUNT
#else
  #define TEMP_MPH_GSM850 0
  #define TEMP_MPH_MAX_POWER_SCAN_RESULTS_LEN_GSM850  (0)
#endif

#define MPH_AVAILABLE_BANDS (TEMP_MPH_PGSM900|TEMP_MPH_EGSM900|TEMP_MPH_RGSM900|TEMP_MPH_DCS1800|   \
                             TEMP_MPH_PCS1900|TEMP_MPH_GSM450 |TEMP_MPH_GSM480 |TEMP_MPH_GSM850)
                             
#define TEMP_MPH_MAX_POWER_SCAN_RESULTS_LEN ( TEMP_MPH_MAX_POWER_SCAN_RESULTS_LEN_GSM450  + \
                                              TEMP_MPH_MAX_POWER_SCAN_RESULTS_LEN_GSM480  + \
                                              TEMP_MPH_MAX_POWER_SCAN_RESULTS_LEN_GSM850  + \
                                              TEMP_MPH_MAX_POWER_SCAN_RESULTS_LEN_PGSM900 + \
                                              TEMP_MPH_MAX_POWER_SCAN_RESULTS_LEN_EGSM900 + \
                                              TEMP_MPH_MAX_POWER_SCAN_RESULTS_LEN_RGSM900 + \
                                              TEMP_MPH_MAX_POWER_SCAN_RESULTS_LEN_DCS1800 + \
                                              TEMP_MPH_MAX_POWER_SCAN_RESULTS_LEN_PCS1900 )
                                              
#define MPH_MAX_POWER_SCAN_RESULTS_LEN ( TEMP_MPH_MAX_POWER_SCAN_RESULTS_LEN > MPH_MAX_POWER_SCAN_ARFCN_COUNT     \
                                         ? MPH_MAX_POWER_SCAN_ARFCN_COUNT : TEMP_MPH_MAX_POWER_SCAN_RESULTS_LEN )                                     

/* ---- END Decide POWER SCAN MAX LENGTH ------------------------------------------ */

#define MPH_ALGORITHM_A5_1  (0)
#define MPH_ALGORITHM_A5_2  (1)
#define MPH_ALGORITHM_A5_3  (2)
#define MPH_ALGORITHM_A5_4  (3)
#define MPH_ALGORITHM_A5_5  (4)
#define MPH_ALGORITHM_A5_6  (5)
#define MPH_ALGORITHM_A5_7  (6)

#define MPH_HANDOVER_TYPE_PRE_SYNC        (0)
#define MPH_HANDOVER_TYPE_PSEUDO_SYNC     (1)
#define MPH_HANDOVER_TYPE_FINELY_SYNC     (2)
#define MPH_HANDOVER_TYPE_NON_SYNC        (3)

#define MPH_HANDOVER_L1_NO_ERROR              (0)
#if 0
/* under construction !*/
#endif
#define MPH_HANDOVER_L1_TA_OUT_OF_RANGE       (1)

#define MPH_TCH_LOOP_A (0)
#define MPH_TCH_LOOP_B (1)
#define MPH_TCH_LOOP_C (2)
#define MPH_TCH_LOOP_D (3)
#define MPH_TCH_LOOP_E (4)
#define MPH_TCH_LOOP_F (5)
#define MPH_TCH_LOOP_I (6)

#define MPH_OPEN_TCH_LOOP (8)

#define MPH_DAI_TEST_NORMAL          (0)
#define MPH_DAI_TEST_SPEECH_DEC_DTX  (1)
#define MPH_DAI_TEST_SPEECH_ENC_DTX  (2)
#define MPH_DAI_TEST_ACOUTIC_AD_DA   (4)

#define MPH_POWER_CLASS_1         (0)
#define MPH_POWER_CLASS_2         (1)
#define MPH_POWER_CLASS_3         (2)
#define MPH_POWER_CLASS_4         (3)
#define MPH_POWER_CLASS_5         (4)
#define MPH_POWER_CLASS_NOT_CURRENT   (-1)
#define MPH_POWER_CLASS_INVALID   (-1)

#define MPH_CBCH_BASIC_ONLY      (0x01)
#define MPH_CBCH_EXTENDED_ONLY   (0x02)
#define MPH_CBCH_ALL             (0x03)

typedef enum
{
   MPH_ATC_MANDATORY = 0,
   MPH_ATC_OPTIONAL
} mph_handover_atc_enum;

typedef enum
{
   MPH_CH_TYPE_NONE = 0,
   MPH_CH_TYPE_TCH_FR,
   MPH_CH_TYPE_TCH_HR,
   MPH_CH_TYPE_SDCCH_4,
   MPH_CH_TYPE_SDCCH_8,
   MPH_CH_TYPE_BCCH,
   MPH_CH_TYPE_RACH,
   MPH_CH_TYPE_PCH,
   MPH_CH_TYPE_CCCH,
   MPH_CH_TYPE_SDCCH,
   MPH_CH_TYPE_SACCH,
   MPH_CH_TYPE_FACCH,
   MPH_CH_TYPE_CBCH,
   MPH_CH_TYPE_NBCCH,

#ifdef __PS_SERVICE__
   MPH_CH_TYPE_PPCH,
   MPH_CH_TYPE_PCCCH,
   MPH_CH_TYPE_PBCCH,
   MPH_CH_TYPE_NPBCCH,
   MPH_CH_TYPE_PRACH,
   MPH_CH_TYPE_PACCH,
#endif

   MPH_CH_TYPE_NUM /* the number of channel types */
} mph_channel_type_enum;

typedef enum
{
   MPH_CH_MODE_NONE = 0xff,
   MPH_CH_MODE_SIGNALLING_ONLY = 0x00,
   MPH_CH_MODE_FULL_OR_HALF_SPEECH_VER1 = 0x01,   /* SPEECH Ver1 */
   MPH_CH_MODE_FULL_OR_HALF_SPEECH_VER2 = 0x21,   /* SPEECH Ver2 */
   MPH_CH_MODE_FULL_OR_HALF_SPEECH_VER3 = 0x41,   /* SPEECH Ver3 */
   MPH_CH_MODE_DATA_43_5_DL_PLUS_14_5_UL = 0x61,
   MPH_CH_MODE_DATA_29_0_DL_PLUS_14_5_UL = 0x62,
   MPH_CH_MODE_DATA_43_5_DL_PLUS_29_0_UL = 0x64,
   MPH_CH_MODE_DATA_14_5_DL_PLUS_43_5_UL = 0x67,
   MPH_CH_MODE_DATA_14_5_DL_PLUS_29_0_UL = 0x65,
   MPH_CH_MODE_DATA_29_0_DL_PLUS_43_5_UL = 0x66,
   MPH_CH_MODE_DATA_43_5_RADIO_INTF_RATE = 0x27,
   MPH_CH_MODE_DATA_32_0_RADIO_INTF_RATE = 0x63,
   MPH_CH_MODE_DATA_29_0_RADIO_INTF_RATE = 0x43,
   MPH_CH_MODE_DATA_14_5_RADIO_INTF_RATE = 0x0f,   /* data 14400 */
   MPH_CH_MODE_DATA_12_0_RADIO_INTF_RATE = 0x03,   /* data 9600 */
   MPH_CH_MODE_DATA_06_0_RADIO_INTF_RATE = 0x0b,   /* data 4800 */
   MPH_CH_MODE_DATA_03_6_RADIO_INTF_RATE = 0x13    /* data 2400 */
} mph_channel_mode_enum;

typedef enum
{
   MPH_NORMAL_PAGING=0,
   MPH_EXTENDED_PAGING,
   MPH_PAGING_REORG,
   MPH_SAME_PAGING_MODE
} mph_paging_mode_enum;


#ifdef __PS_SERVICE__

typedef enum
{
   BOTH_CHANGE=0,
   POWER_CLASS_CHANGE,
   MS_TXPWR_CHANGE
} mph_txpwr_change_cause_enum;

#endif

typedef enum
{
   MPH_GOOD_BLOCK           = 0,
   MPH_BAD_BLOCK            = 1,
#ifdef __GEMINI__
   MPH_CONFLICT_WITH_OTHERS = 2,/* channel conflict with peer misc. channels */
   MPH_CONFLICT_WITH_PCH    = 3,/* channel conflict with peer-PCH */
   MPH_CONFLICT_WITH_BCCH   = 4,/* channel conflict with peer-BCCH */
   MPH_BLOCK_SHARING        = 5 /* channel sharing when conflict with peer-PCH */
#else
   MPH_CONFLICT             = 2
#endif /* end of __GEMINI__ */
} mph_block_mointor_enum;


typedef struct
{
   kal_uint8   list_ref;   /* list reference no for differentiating the
                              related report of different list */
   kal_uint8   arfcn_list_len;   /* Number of ARFCNs in the list */
   /* list of BCCH ARFCNs default MAX_BCCH_ARFCNS - 32,
      since likely maximum number of neighbors in BA(BCCH) or
      BA(GPRS) is 32 can be configured based on L1 requirements */
   ARFCN       arfcn_list[MPH_MAX_BA_LIST_LEN+1];
} mph_bcch_list_struct;

typedef struct
{
   kal_uint8   list_ref;   /* list reference no for differentiating the
                              related report of different list */
   kal_uint8   arfcn_list_len;   /* Number of ARFCNs in the stored list */
   /* list of BCCH ARFCNs is 
   BA list from System Information (SI2, Si2bis and SI2ter, up to 32 BCCH carriers) +
   The BCCH of the camped on cell (just only 1) +
   BA range (from the channel release message without defining the max number) */
   ARFCN       arfcn_list[MPH_MAX_STORED_BA_LIST_LEN];
} mph_stored_bcch_list_struct;

typedef struct
{
   kal_int32      hsn;
   kal_int32      maio;
   kal_int32      freq_list_len; /* If it is not hopping, the freq_list_len=1 */
   ARFCN          freq_list[MPH_MAX_HOPPING_FREQ_LIST_LEN];
} mph_hopping_freq_list_struct;

typedef struct
{
   /* 3 bits training sequence code  0 - 7 */
   TSC                           tsc;
   /* refer to mph_hopping_freq_list_struct */
   mph_hopping_freq_list_struct  freq_list;
} mph_freq_params_struct;

typedef struct
{
   TimeSlot                time_slot; /* time slot number */
   SubChannel              sub_channel;  /* 0:subchannel 0, 1:subchannel 1 */
   mph_channel_type_enum   channel_type; /* refer to mph_channel_type_enum */
   mph_channel_mode_enum   channel_mode; /* refer to mph_channel_mode_enum */
   /* refer to mph_freq_paras_structure */
   mph_freq_params_struct  freq_params;
} mph_channel_description_struct;

typedef struct
{
   ARFCN          arfcn;   /* Arfcn to confirm BSIC */
   kal_bool       bsic_valid; /* Whether bsic is valid. */
   /* The frame offset of L1 timing for this acquisition.*/
   FrameNumber    frame_offset;
   /* The ebit offset of L1 timing for this acquisition. */
   kal_int32      ebit_offset;
   /* It indicates if L1 initiates the retry acquisition as the first
      trial is failed. */
   kal_bool       need_retry;
   kal_bool       retry_FB_SB;
} mph_neighbor_bsic_acquisition_struct;
#if 1 //__NORMAL_NW_SEARCH__
typedef struct
{
   ARFCN          arfcn;   /* Arfcn to confirm BSIC */
   kal_bool       is_need_freq_correction;
} mph_cell_bsic_acquisition_struct;
#endif
typedef struct
{
   ARFCN          arfcn;   /* Arfcn to confirm BSIC */
   kal_bool       bsic_valid; /* Whether bsic is valid. */
   BSIC           bsic; /* Base transceiver Station Identity Code */
   kal_uint16     bcch_mask; /* TC mask for bcch */
   /* The frame offset of L1 timing for this acquisition.*/
   FrameNumber    frame_offset;
   /* The ebit offset of L1 timing for this acquisition. */
   kal_int32      ebit_offset;
   /* KAL_TRUE: high priorityKAL_FALSE: normal priority */
   kal_bool       is_prior_to_acquire;
   /* It indicates if L1 initiates the retry acquisition as the first
      trial is failed. */
   kal_bool       need_retry;
   /* elly, 2006/12/14, tier-1 network search enhancement.
    * use_priority_index_order:
    * - TRUE: The network search priority would base on the index. 
    *         The carrier with smaller priority_index has higher priority.
    * - FALSE:The carrier with minimum delay would be searched first.
    */
   kal_bool       use_priority_index_order;
#ifdef __GEMINI__
   kal_uint16      priority_index; /*maruco20071107,RR may add more priorities for acquiring NBCCH.*/
#else
   kal_uint8      priority_index;
#endif
} mph_neighbor_bcch_acquisition_struct;

#ifdef __EGPRS_MODE__
typedef enum
{
  MPH_NONE_ATS,
  MPH_TS1,
  MPH_TS2
} mph_ats_type_enum;
#endif

#if 1 //__NORMAL_NW_SEARCH__
typedef struct
{
   ARFCN          arfcn;   /* Arfcn to confirm BSIC */
   BSIC           bsic; /* Base transceiver Station Identity Code */
   kal_uint16     bcch_mask; /* TC mask for bcch */
   /* The frame offset of L1 timing for this acquisition.*/
   FrameNumber    frame_offset;
   /* The ebit offset of L1 timing for this acquisition. */
   kal_int32      ebit_offset;
   /* elly, 2006/12/14, tier-1 network search enhancement.
    * use_priority_index_order:
    * - TRUE: The network search priority would base on the index. 
    *         The carrier with smaller priority_index has higher priority.
    * - FALSE:The carrier with minimum delay would be searched first.
    */
   kal_bool       use_priority_index_order;
#ifdef __GEMINI__
   kal_uint16      priority_index; /*maruco20071107,RR may add more priorities for acquiring NBCCH.*/
#else
   kal_uint8      priority_index;
#endif
} mph_cell_bcch_acquisition_struct;
#endif

#ifdef __GEMINI__
typedef enum
{
   MPH_SIM1_ONLY_CONFIG,
   MPH_SIM2_ONLY_CONFIG,
   MPH_DAUL_SIM_CONFIG
} mph_sim_config_status_enum;

typedef enum
{
   MPH_NO_SIM_INSERTED,
   MPH_ONLY_SIM1_INSERTED,
   MPH_ONLY_SIM2_INSERTED,
   MPH_DUAL_SIM_INSERTED
} mph_sim_insert_status_enum; 
#endif /*end of __GEMINI__ */

#endif /* end of _MPH_CS_DEF_H */


