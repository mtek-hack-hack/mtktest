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
 * nvram_data_items.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *    This file defines logical data items stored in NVRAM. 
 *    These logical data items are used in object code of Protocol Stack software.
 *
 *    As for customizable logical data items, they are defined in nvram_user_defs.h
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
 *******************************************************************************/

#ifndef NVRAM_DATA_ITEMS_H
#define NVRAM_DATA_ITEMS_H

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

    /* Header files should be include before this one */
#ifndef NUCLEUS
#define NUCLEUS /* to prevent from definition confilct */
#endif 

#if defined(__MA_L1__)
/* under construction !*/
#endif  /* __MA_L1__ */
#include "kal_release.h"
#include "ex_item.h"
#ifndef _TASKINIT_H
#include "stack_config.h"
#endif 
#include "stack_buff_pool.h"
#include "ctrl_buff_pool.h"
#include "tst_buff_pool.h"
#include "sysconf_statistics.h"
#include "nvram_defs.h"

#if defined(__MA_L1__)
/* under construction !*/
#endif  /* __MA_L1__ */
#include "stack_common.h"

#if defined(__GEMINI__)
#define NVRAM_DUAL_RECORD 2
#else
#define NVRAM_DUAL_RECORD 1
#endif



/** 
 * Step 1: (See comment of nvram_data_item.c for detail).
 * Vendor defined logical data item ID's. 
 * These logical data items are used in object code of Protocol Stack software.
 *
 */

    typedef enum
    {
        /* System record, keep the system version */
        NVRAM_EF_SYS_LID,
        /* Branch record, keep the branch version */
        NVRAM_EF_BRANCH_VERNO_LID,
        /* CustPack record, keep the custpack version */
        NVRAM_EF_CUSTPACK_VERNO_LID,

        NVRAM_EF_START,
        NVRAM_EF_SYS_EXCEPTION_LID = NVRAM_EF_START,
        NVRAM_EF_SYS_STATISTICS_LID,
        NVRAM_EF_L1_START,
        NVRAM_EF_L1_AGCPATHLOSS_LID = NVRAM_EF_L1_START,
        NVRAM_EF_L1_RAMPTABLE_GSM850_LID,
        NVRAM_EF_L1_RAMPTABLE_GSM900_LID,
        NVRAM_EF_L1_RAMPTABLE_DCS1800_LID,
        NVRAM_EF_L1_RAMPTABLE_PCS1900_LID,
        NVRAM_EF_L1_EPSK_START,
        NVRAM_EF_L1_EPSK_RAMPTABLE_GSM850_LID = NVRAM_EF_L1_EPSK_START,
        NVRAM_EF_L1_EPSK_RAMPTABLE_GSM900_LID,
        NVRAM_EF_L1_EPSK_RAMPTABLE_DCS1800_LID,
        NVRAM_EF_L1_EPSK_RAMPTABLE_PCS1900_LID,
        NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_GSM850_LID,
        NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_GSM900_LID,
        NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_DCS1800_LID,
        NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_PCS1900_LID,
        NVRAM_EF_L1_EPSK_END = NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_PCS1900_LID,
        NVRAM_EF_L1_AFCDATA_LID,
        NVRAM_EF_L1_TXIQ_LID,
        NVRAM_EF_L1_RFSPECIALCOEF_LID,
        NVRAM_EF_L1_INTERSLOT_RAMP_GSM850_LID,
        NVRAM_EF_L1_INTERSLOT_RAMP_GSM900_LID,
        NVRAM_EF_L1_INTERSLOT_RAMP_DCS1800_LID,
        NVRAM_EF_L1_INTERSLOT_RAMP_PCS1900_LID,
        NVRAM_EF_L1_CRYSTAL_AFCDATA_LID,
        NVRAM_EF_L1_CRYSTAL_CAPDATA_LID,
        NVRAM_EF_L1_END = NVRAM_EF_L1_CRYSTAL_CAPDATA_LID,
        NVRAM_EF_UL1_START,
        NVRAM_EF_UL1_TEMP_DAC_LID = NVRAM_EF_UL1_START,
        NVRAM_EF_UL1_PATHLOSS_BAND1_LID,
        NVRAM_EF_UL1_PATHLOSS_BAND2_LID,
        NVRAM_EF_UL1_PATHLOSS_BAND3_LID,
        NVRAM_EF_UL1_TXDAC_BAND1_LID,
        NVRAM_EF_UL1_TXDAC_BAND2_LID,
        NVRAM_EF_UL1_TXDAC_BAND3_LID,
        NVRAM_EF_UL1_END = NVRAM_EF_UL1_TXDAC_BAND3_LID,
    #if defined(__WIFI_SUPPORT__)
        NVRAM_EF_WNDRV_START,
        NVRAM_EF_WNDRV_MAC_ADDRESS_LID = NVRAM_EF_WNDRV_START,
        NVRAM_EF_WNDRV_TX_POWER_2400M_LID,
        NVRAM_EF_WNDRV_TX_POWER_5000M_LID,
        NVRAM_EF_WNDRV_DAC_DC_OFFSET_LID,
        NVRAM_EF_WNDRV_TX_ALC_POWER_LID,
        NVRAM_EF_WNDRV_ALC_SLOPE_LID,
        NVRAM_EF_WNDRV_END = NVRAM_EF_WNDRV_ALC_SLOPE_LID,
    #endif /* defined(__WIFI_SUPPORT__) */ 
        NVRAM_EF_EXTBCCH_LID,
        NVRAM_EF_EQ_PLMN_LID,
        NVRAM_EF_BAND_INFO_LID,
        NVRAM_EF_TST_FILTER_LID,
        NVRAM_EF_CB_CH_INFO_LID,
        NVRAM_EF_SMSAL_MWIS_LID,
        NVRAM_EF_TCM_STATISTICS_LID,
        NVRAM_EF_CFU_FLAG_LID,
        NVRAM_EF_MM_EQPLMN_LOCIGPRS_LID,
        NVRAM_EF_CTM_DEFAULT_SETTINGS_LID,
        NVRAM_EF_ALS_LINE_ID_LID,
        NVRAM_EF_MSCAP_LID,
        NVRAM_EF_CLASSMARK_RACAP_LID,
        NVRAM_EF_SIM_ASSERT_LID,
        NVRAM_EF_RTC_DATA_LID,

        NVRAM_EF_UMTS_PLMN_LID,
        NVRAM_EF_UMTS_NET_PAR_LID,
        NVRAM_EF_UMTS_IMSI_LID,
        NVRAM_EF_UMTS_START_HFN_LID,
        NVRAM_EF_UMTS_CSE_CACHE_INFO_LID,
        NVRAM_EF_UMTS_USIME_RRC_DYNAMIC_CAP_LID,
        NVRAM_EF_L1_3G_CAL_DATA_LID,
        NVRAM_EF_FLC_STATISTICS_LID,

        /* Don't remove this line: insert LID definition above */
        NVRAM_EF_LAST_LID_CORE
    } nvram_lid_core_enum;

/**
 * Step 2:
 * Defines constants of size and number of records for each logical data item.
 * For linear-fixed, TOTAL is greater than 1, and SIZE is size of each record;
 * for transparent, TOTAL must be exaclty 1, and SIZE is size of entire data item.
 *
 * Each logical data item must be:
 * 1> Size must be EVEN
 * 2> Size of default value must be equal to the logical data item's size.
 *
 * Notice:
 * If total number of L1 Calibration data items is changed, NVRAM_L1CAL_ELEMENT_TOTAL
 * must be modified properly.
 */

/** System record:
 * [  DATA_VERSION  ][ PADDING ][ LOCK_PATTERN ]
 *    18 bytes          4 bytes  12 bytes
 * Size must be 
 * strlen(CODED_DATA_VERSION) + strlen(CODED_PADDING_LENGTH) + strlen(NVRAM_LOCK_PATTERN) 
 * And must be even-byte aligned.
 *
 * System record is two-copied. It is controlled directly by NVRAM Layer itself.
 * Ie, their record ID's are: 1 and 2.
 */

#define NVRAM_EF_SYS_SIZE                 34
#define NVRAM_EF_SYS_TOTAL                1

#define CODED_DATA_VERSION_SIZE           18
#define CODED_PADDING_SIZE                4

#define CODED_LOCK_PATTERN_SIZE           12
#define CODED_LOCK_PATTERN_OFFSET         22

#define NVRAM_EF_BRANCH_VERNO_SIZE  NVRAM_EF_SYS_SIZE
#define NVRAM_EF_BRANCH_VERNO_TOTAL NVRAM_EF_SYS_TOTAL

#define NVRAM_EF_CUSTPACK_VERNO_SIZE NVRAM_EF_SYS_SIZE
#define NVRAM_EF_CUSTPACK_VERNO_TOTAL NVRAM_EF_SYS_TOTAL

/**
 * TST Filter
 *   PS filter length + L1 filter length (current max number is 22*5, exact number should be decided at codegen stage)
 */
#define NVRAM_EF_TST_FILTER_SIZE         (((END_OF_MOD_ID+7)/8) + (LAST_SAP_CODE+1) + (2*(END_OF_MOD_ID+1)) + 44*5)
#define NVRAM_EF_TST_FILTER_TOTAL        1

/**
 * System Exception Dumping
 */
#define NVRAM_EF_SYS_EXCEPTION_SIZE       TOTAL_EXPTR_SIZE
#define NVRAM_EF_SYS_EXCEPTION_TOTAL      10

/**
 * System Statistics
 */
#define NVRAM_EF_SYS_STATISTICS_SIZE       sizeof(stack_statistics_struct)
#define NVRAM_EF_SYS_STATISTICS_TOTAL      1

/************************************************************
 * Start of L1 Calibration data
 ************************************************************/
/**
 * Total number of L1 Calibration data items
 */
#if defined(__EPSK_TX__)
#define NVRAM_EF_L1_EPSK_SUBTRAHEND 0
#else
#define NVRAM_EF_L1_EPSK_SUBTRAHEND (NVRAM_EF_L1_EPSK_END - NVRAM_EF_L1_EPSK_START + 1)
#endif

#define NVRAM_L1CAL_ELEMENT_TOTAL (NVRAM_EF_L1_END - NVRAM_EF_L1_START + 1 - NVRAM_EF_L1_EPSK_SUBTRAHEND)
 

/**
 * Total number of UL1 Calibration data items
 */
#if defined(__WCDMA_RAT__) && defined(__MTK_UL1_FDD__)
/* under construction !*/
#else
#define NVRAM_UL1CAL_ELEMENT_TOTAL 0
#endif

/**
 * L1 AGC Path Loss
 */
#define NVRAM_EF_L1_AGCPATHLOSS_SIZE     sizeof(l1cal_agcPathLoss_T)
#define NVRAM_EF_L1_AGCPATHLOSS_TOTAL    1

/**
 * L1 Ramp Table for GSM850
 */
#define NVRAM_EF_L1_RAMPTABLE_GSM850_SIZE    sizeof(l1cal_rampTable_T)
#define NVRAM_EF_L1_RAMPTABLE_GSM850_TOTAL   1

/**
 * L1 Ramp Table for GSM900
 */
#define NVRAM_EF_L1_RAMPTABLE_GSM900_SIZE    sizeof(l1cal_rampTable_T)
#define NVRAM_EF_L1_RAMPTABLE_GSM900_TOTAL   1

/**
 * L1 Ramp Table for DCS1800
 */
#define NVRAM_EF_L1_RAMPTABLE_DCS1800_SIZE   sizeof(l1cal_rampTable_T)
#define NVRAM_EF_L1_RAMPTABLE_DCS1800_TOTAL  1

/**
 * L1 Ramp Table for PCS1900
 */
#define NVRAM_EF_L1_RAMPTABLE_PCS1900_SIZE   sizeof(l1cal_rampTable_T)
#define NVRAM_EF_L1_RAMPTABLE_PCS1900_TOTAL  1

#if defined(__EPSK_TX__)
/**
 * L1 EPSK_Ramp Table for GSM850
 */
#define NVRAM_EF_L1_EPSK_RAMPTABLE_GSM850_SIZE    sizeof(l1cal_rampTable_T)
#define NVRAM_EF_L1_EPSK_RAMPTABLE_GSM850_TOTAL   1

/**
 * L1 EPSK_Ramp Table for GSM900
 */
#define NVRAM_EF_L1_EPSK_RAMPTABLE_GSM900_SIZE    sizeof(l1cal_rampTable_T)
#define NVRAM_EF_L1_EPSK_RAMPTABLE_GSM900_TOTAL   1

/**
 * L1 EPSK_Ramp Table for DCS1800
 */
#define NVRAM_EF_L1_EPSK_RAMPTABLE_DCS1800_SIZE   sizeof(l1cal_rampTable_T)
#define NVRAM_EF_L1_EPSK_RAMPTABLE_DCS1800_TOTAL  1

/**
 * L1 EPSK_Ramp Table for PCS1900
 */
#define NVRAM_EF_L1_EPSK_RAMPTABLE_PCS1900_SIZE   sizeof(l1cal_rampTable_T)
#define NVRAM_EF_L1_EPSK_RAMPTABLE_PCS1900_TOTAL  1
#endif /* defined(__EPSK_TX__) */ 
/**
 * L1 AFC Data
 */
#define NVRAM_EF_L1_AFCDATA_SIZE         sizeof(l1cal_afcData_T)
#define NVRAM_EF_L1_AFCDATA_TOTAL        1

/**
 * L1 TXIQ Calibration data
 */
#define NVRAM_EF_L1_TXIQ_SIZE         sizeof(l1cal_txiq_T)
#define NVRAM_EF_L1_TXIQ_TOTAL        1

/**
 * L1 RF Special Coef Calibration data
 */
#define NVRAM_EF_L1_RFSPECIALCOEF_SIZE         sizeof(l1cal_rfspecialcoef_T)
#define NVRAM_EF_L1_RFSPECIALCOEF_TOTAL        1

/**
 * L1 Inter-slot ramp table Calibration data for GSM 850
 */
#define NVRAM_EF_L1_INTERSLOT_RAMP_GSM850_SIZE    sizeof(l1cal_interRampData_T)
#define NVRAM_EF_L1_INTERSLOT_RAMP_GSM850_TOTAL   1

/**
 * L1 Inter-slot ramp table Calibration data for GSM 900
 */
#define NVRAM_EF_L1_INTERSLOT_RAMP_GSM900_SIZE    sizeof(l1cal_interRampData_T)
#define NVRAM_EF_L1_INTERSLOT_RAMP_GSM900_TOTAL   1

/**
 * L1 Inter-slot ramp table Calibration data for DCS 1800
 */
#define NVRAM_EF_L1_INTERSLOT_RAMP_DCS1800_SIZE    sizeof(l1cal_interRampData_T)
#define NVRAM_EF_L1_INTERSLOT_RAMP_DCS1800_TOTAL   1

/**
 * L1 Inter-slot ramp table Calibration data for PCS 1900
 */
#define NVRAM_EF_L1_INTERSLOT_RAMP_PCS1900_SIZE    sizeof(l1cal_interRampData_T)
#define NVRAM_EF_L1_INTERSLOT_RAMP_PCS1900_TOTAL   1

#if defined(__EPSK_TX__)
/**********************************************************************************/
/**
 * L1 EPSK Inter-slot ramp table Calibration data for GSM 850
 */
#define NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_GSM850_SIZE    sizeof(l1cal_EPSK_interRampData_T)
#define NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_GSM850_TOTAL   1

/**
 * L1 EPSK Inter-slot ramp table Calibration data for GSM 900
 */
#define NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_GSM900_SIZE    sizeof(l1cal_EPSK_interRampData_T)
#define NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_GSM900_TOTAL   1

/**
 * L1 EPSK Inter-slot ramp table Calibration data for DCS 1800
 */
#define NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_DCS1800_SIZE    sizeof(l1cal_EPSK_interRampData_T)
#define NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_DCS1800_TOTAL   1

/**
 * L1 EPSK Inter-slot ramp table Calibration data for PCS 1900
 */
#define NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_PCS1900_SIZE    sizeof(l1cal_EPSK_interRampData_T)
#define NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_PCS1900_TOTAL   1

#endif /* defined(__EPSK_TX__) */ 

/**********************************************************************************/
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
#endif /* __WCDMA_RAT__ && __MTK_UL1_FDD__ */
/**********************************************************************************/
/**
 * L1 Crystal AFC Data
 */
#define NVRAM_EF_L1_CRYSTAL_AFCDATA_SIZE         sizeof(l1cal_crystalAfcData_T)
#define NVRAM_EF_L1_CRYSTAL_AFCDATA_TOTAL        1

/**
 * L1 Crystal CAP Data
 */
#define NVRAM_EF_L1_CRYSTAL_CAPDATA_SIZE         sizeof(l1cal_crystalCapData_T)
#define NVRAM_EF_L1_CRYSTAL_CAPDATA_TOTAL        1

/************************************************************
 * End of L1 Calibration data
 ************************************************************/
#if defined(__WIFI_SUPPORT__)
/************************************************************
 * Start of WNDRV Calibration data
 ************************************************************/
 /**
 * Total number of WNDRV Calibration data items
 */
#define NVRAM_WNDRV_CAL_ELEMENT_TOTAL NVRAM_EF_WNDRV_END - NVRAM_EF_WNDRV_START + 1

/**
 * WNDRV Permanent MAC Address
 */
#define NVRAM_EF_WNDRV_MAC_ADDRESS_SIZE     sizeof(wndrv_cal_mac_addr_struct)
#define NVRAM_EF_WNDRV_MAC_ADDRESS_TOTAL    1

/**
 * WNDRV 2.4G TX Power Table
 */
#define NVRAM_EF_WNDRV_TX_POWER_2400M_SIZE    sizeof(wndrv_cal_txpwr_2400M_struct)
#define NVRAM_EF_WNDRV_TX_POWER_2400M_TOTAL   1

/**
 * WNDRV 5.0G TX Power Table
 */
#define NVRAM_EF_WNDRV_TX_POWER_5000M_SIZE    sizeof(wndrv_cal_txpwr_5000M_struct)
#define NVRAM_EF_WNDRV_TX_POWER_5000M_TOTAL   1

/**
 * WNDRV DAC DC OFFSET
 */
#define NVRAM_EF_WNDRV_DAC_DC_OFFSET_SIZE    sizeof(wndrv_cal_dac_dc_offset_struct)
#define NVRAM_EF_WNDRV_DAC_DC_OFFSET_TOTAL   1


#define NVRAM_EF_WNDRV_TX_ALC_POWER_SIZE    sizeof(wndrv_cal_tx_ALC_2400M_struct)
#define NVRAM_EF_WNDRV_TX_ALC_POWER_TOTAL   1

#define NVRAM_EF_WNDRV_ALC_SLOPE_SIZE    sizeof(wndrv_cal_ALC_Slope_2400M_struct)
#define NVRAM_EF_WNDRV_ALC_SLOPE_TOTAL   1

/************************************************************
 * End of WNDRV Calibration data
 ************************************************************/
#endif /* defined(__WIFI_SUPPORT__) */ 

/**
 * MSCAP
 */
#define NVRAM_EF_MSCAP_SIZE              4
#define NVRAM_EF_MSCAP_TOTAL             (1 * NVRAM_DUAL_RECORD)

/**
 * CLASSMARK_RACAP
 */
#define NVRAM_EF_CLASSMARK_RACAP_SIZE          12
#define NVRAM_EF_CLASSMARK_RACAP_TOTAL         (1 * NVRAM_DUAL_RECORD)

/**
 * EXTBCCH
 */
#define NVRAM_EF_EXTBCCH_SIZE            56
#define NVRAM_EF_EXTBCCH_TOTAL           (1 * NVRAM_DUAL_RECORD)

/** EQ_PLMN
 * 
 */
#define NVRAM_EF_EQ_PLMN_SIZE            38
#define NVRAM_EF_EQ_PLMN_TOTAL           (1 * NVRAM_DUAL_RECORD)

/** BAND_INFO
 * 
 */
#define NVRAM_EF_BAND_INFO_SIZE            6
#define NVRAM_EF_BAND_INFO_TOTAL           (1 * NVRAM_DUAL_RECORD)

/**
 * Drx parameters
 */
#define NVRAM_EF_DRX_PARAM_SIZE           2
#define NVRAM_EF_DRX_PARAM_TOTAL          1

/**
 * CB Mask
 */
#define NVRAM_EF_CB_CH_INFO_SIZE              50
#define NVRAM_EF_CB_CH_INFO_TOTAL             (1 * NVRAM_DUAL_RECORD)

/**
 * SMSAL message waiting indication status
 */
#define NVRAM_EF_SMSAL_MWIS_SIZE           6
#define NVRAM_EF_SMSAL_MWIS_TOTAL          (2 * NVRAM_DUAL_RECORD)

/**
 * TCP statistics
 */
#define NVRAM_EF_TCM_STATISTICS_SIZE         16 /* 22 */
#define NVRAM_EF_TCM_STATISTICS_TOTAL        (1 * NVRAM_DUAL_RECORD)

#if defined(__CCM_NO_RESET__)
/**
 * Add last call cost
 */
#define NVRAM_EF_ALS_LINE_ID_SIZE             6
#define NVRAM_EF_ALS_LINE_ID_TOTAL            (1 * NVRAM_DUAL_RECORD)
#elif defined (__CPHS__)
/**
 * Line id
 */
#define NVRAM_EF_ALS_LINE_ID_SIZE             2
#define NVRAM_EF_ALS_LINE_ID_TOTAL            (1 * NVRAM_DUAL_RECORD)
#endif  

/**
 * CFU FLAG
 */
#define NVRAM_EF_CFU_FLAG_SIZE             2
#define NVRAM_EF_CFU_FLAG_TOTAL            (1 * NVRAM_DUAL_RECORD)

/* Johnny 2005/11/07: add eqplmn_locigprs in nvram */
#ifdef __PS_SERVICE__
#define NVRAM_EF_MM_EQPLMN_LOCIGPRS_SIZE 52
#define NVRAM_EF_MM_EQPLMN_LOCIGPRS_TOTAL (1 * NVRAM_DUAL_RECORD)
#endif /* __PS_SERVICE__ */ 

#ifdef __CTM_SUPPORT__
    /* CTM */
#define    NVRAM_EF_CTM_DEFAULT_SETTINGS_TOTAL 1
#define    NVRAM_EF_CTM_DEFAULT_SETTINGS_SIZE 6
#endif /* __CTM_SUPPORT__ */ 

/*
 * SIM log
 */
#define NVRAM_EF_SIM_ASSERT_SIZE  16
#ifdef __SHADOW_SUPPORT_SB__
#define NVRAM_EF_SIM_ASSERT_TOTAL 10
#else
#define NVRAM_EF_SIM_ASSERT_TOTAL 80
#endif
/*
 * 3G Monza
 */
#define NVRAM_EF_UMTS_PLMN_SIZE				4
#define NVRAM_EF_UMTS_PLMN_TOTAL				1

#define NVRAM_EF_UMTS_NET_PAR_SIZE			8190 /* MAX_NVRAM_RECORD_SIZE */
#define NVRAM_EF_UMTS_NET_PAR_TOTAL			1

#define NVRAM_EF_UMTS_IMSI_SIZE				24
#define NVRAM_EF_UMTS_IMSI_TOTAL				1

#define NVRAM_EF_UMTS_START_HFN_SIZE			6
#define NVRAM_EF_UMTS_START_HFN_TOTAL			1

#define NVRAM_EF_UMTS_CSE_CACHE_INFO_SIZE       8190
#define NVRAM_EF_UMTS_CSE_CACHE_INFO_TOTAL      1

#define NVRAM_EF_UMTS_USIME_RRC_DYNAMIC_CAP_SIZE      23
#define NVRAM_EF_UMTS_USIME_RRC_DYNAMIC_CAP_TOTAL     1

#define NVRAM_EF_L1_3G_CAL_DATA_SIZE		8184
#define NVRAM_EF_L1_3G_CAL_DATA_TOTAL		1

#define NVRAM_EF_FLC_STATISTICS_SIZE        2000
#define NVRAM_EF_FLC_STATISTICS_TOTAL       1 

    typedef enum
    {
        NVRAM_SYS_AUTO_DETECT = 1,
        NVRAM_SYS_FLIGHTMODE_STATE,
        NVRAM_SYS_DSP_PATCH,
        NVRAM_SYS_SIM_PLUS_SETTING,
        NVRAM_SYS_FIXED_GAIN_MECH_FOR_HELIOS2,
        NVRAM_SYS_FACTORY_FLAG,
        NVRAM_SYS_CV_CALIBRATION,
        NVRAM_SYS_CACHE_MAX
    } NVRAM_SYS_CACHE_OCTETDATA;

#ifdef __cplusplus
}
#endif 

#endif /* NVRAM_DATA_ITEMS_H */ /* define NVRAM_DATA_ITEMS_H */

