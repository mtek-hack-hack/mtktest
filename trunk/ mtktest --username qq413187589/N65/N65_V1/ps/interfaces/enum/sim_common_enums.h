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
 *	sim_common.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   This file defines the data structure, enum and constant for SIM.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
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
 *==============================================================================
 *******************************************************************************/

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/

#ifndef SIM_COMMON_ENUM_H
#define SIM_COMMON_ENUM_H

/* +2 to support Rel.4 SIM card */
#ifdef __CPHS__
#define MAX_SST_LEN              17
#else
#define MAX_SST_LEN              15
#endif
#define MAX_PROFILE_LEN          18
#define MAX_SIM_TIMER_NUM         1
#define MAX_DATA_LEN            256
#define NUM_OF_BYTE_ECC           3
#define MAX_ECC_NUM               5
#define NUM_OF_BYTE_LP            2
#define MAX_LP_NUM                5
#define MAX_EF_HEADER_LEN        15
#define MAX_DF_HEADER_LEN        22
#define NUM_GID1                 20
#define NUM_GID2                 20
#define LEN_OF_OPNAME            20
#define LEN_OF_SOPNAME           10
#define LEN_OF_SPN               17
#define SIZE_OF_LOCATION_INFO     7

/* Define the Service table length of SIM and USIM */
#define SIM_SUPPORT_SST_LEN     15   
#define USIM_SUPPORT_UST_LEN   8
#define USIM_SUPPORT_EST_LEN   2
#define CPHS_SST_LEN   2
#define USAT_TERMINAL_PROFILE_LEN 18

/* Define the UICC file path from MF */
#define PATH_MF_ID   {0x00,0x00,0x00,0x00,0x00,0x00}  
#define PATH_GSM_ID   {0x7F,0x20,0x00,0x00,0x00,0x00}
#define PATH_TELECOM_ID   {0x7F,0x10,0x00,0x00,0x00,0x00}
#define PATH_IRIDIUM_ID   {0x7F,0x20,0x5F,0x30,0x00,0x00}
#define PATH_GLOBST_ID   {0x7F,0x20,0x5F,0x31,0x00,0x00}
#define PATH_ICO_ID   {0x7F,0x20,0x5F,0x32,0x00,0x00}
#define PATH_ACES_ID   {0x7F,0x20,0x5F,0x33,0x00,0x00}
#define PATH_EIA_ID   {0x7F,0x20,0x5F,0x40,0x00,0x00}
#define PATH_CTS_ID   {0x7F,0x20,0x5F,0x60,0x00,0x00}
#define PATH_SOLSA_ID   {0x7F,0x20,0x5F,0x70,0x00,0x00}
#define PATH_MEXE_ID   {0x7F,0x20,0x5F,0x3C,0x00,0x00}
#define PATH_GRAPHICS_ID   {0x7F,0x10,0x5F,0x50,0x00,0x00}
#define PATH_ICCID_ID   {0x2F,0xE2,0x00,0x00,0x00,0x00}
#define PATH_ELP_ID   {0x2F,0x05,0x00,0x00,0x00,0x00}
#define PATH_SAI_ID   {0x7F,0xFF,0x5F,0x70,0x4F,0x30}      /* Also under 7F20 */
#define PATH_SLL_ID   {0x7F,0xFF,0x5F,0x70,0x4F,0x31}      /* Also under 7F20 */
#define PATH_MEXE_ST_ID   {0x7F,0xFF,0x5F,0x3C,0x4F,0x40}  /* Also under 7F20 */
#define PATH_ORPK_ID   {0x7F,0xFF,0x5F,0x3C,0x4F,0x41}     /* Also under 7F20 */
#define PATH_ARPK_ID   {0x7F,0xFF,0x5F,0x3C,0x4F,0x42}     /* Also under 7F20 */
#define PATH_TPRPK_ID   {0x7F,0xFF,0x5F,0x3C,0x4F,0x43}    /* Also under 7F20 */
#define PATH_IMG_ID   {0x7F,0x10,0x5F,0x50,0x4F,0x20}
#define PATH_LP_ID   {0x7F,0xFF,0x6F,0x05,0x00,0x00}       /* Also under 7F20 in USIM called EF_LI */
#define PATH_IMSI_ID   {0x7F,0xFF,0x6F,0x07,0x00,0x00}     /* Also under 7F20 */
#define PATH_KC_ID   {0x7F,0xFF,0x5F,0x3B,0x4F,0x20}       /* Also 6F20 under 7F20 */
#define PATH_PLMNSEL_ID   {0x7F,0x20,0x6F,0x30,0x00,0x00}  /* This file is only in SIM */
#define PATH_HPLMN_ID   {0x7F,0xFF,0x6F,0x31,0x00,0x00}    /* Also under 7F20 */
#define PATH_ACMAX_ID   {0x7F,0xFF,0x6F,0x37,0x00,0x00}    /* Also under 7F20 */
#define PATH_SST_ID   {0x7F,0x20,0x6F,0x38,0x00,0x00}      /* Cannot be mapped to UST */
#define PATH_ACM_ID   {0x7F,0xFF,0x6F,0x39,0x00,0x00}      /* Also under 7F20 */
#define PATH_GID1_ID   {0x7F,0xFF,0x6F,0x3E,0x00,0x00}     /* Also under 7F20*/
#define PATH_GID2_ID   {0x7F,0xFF,0x6F,0x3F,0x00,0x00}     /* Also under 7F20*/
#define PATH_SPN_ID   {0x7F,0xFF,0x6F,0x46,0x00,0x00}      /* Also under 7F20*/
#define PATH_PUCT_ID   {0x7F,0xFF,0x6F,0x41,0x00,0x00}     /* Also under 7F20*/     
#define PATH_CBMI_ID   {0x7F,0xFF,0x6F,0x45,0x00,0x00}     /* Also under 7F20*/
#define PATH_BCCH_ID   {0x7F,0x20,0x6F,0x74,0x00,0x00}     /* This file is only in SIM*/
#define PATH_ACC_ID   {0x7F,0xFF,0x6F,0x78,0x00,0x00}      /* Also under 7F20*/
#define PATH_FPLMN_ID   {0x7F,0xFF,0x6F,0x7B,0x00,0x00}    /* Also under 7F20*/
#define PATH_LOCI_ID   {0x7F,0xFF,0x6F,0x7E,0x00,0x00}     /* Also under 7F20*/     
#define PATH_AD_ID   {0x7F,0xFF,0x6F,0xAD,0x00,0x00}       /* Also under 7F20*/
#define PATH_PHASE_ID   {0x7F,0x20,0x6F,0xAE,0x00,0x00}    /* This file is only in SIM */
#define PATH_VGCS_ID   {0x7F,0xFF,0x6F,0xB1,0x00,0x00}     /* Also under 7F20*/
#define PATH_VGCSS_ID   {0x7F,0xFF,0x6F,0xB2,0x00,0x00}    /* Also under 7F20*/
#define PATH_VBS_ID   {0x7F,0xFF,0x6F,0xB3,0x00,0x00}      /* Also under 7F20*/
#define PATH_VBSS_ID   {0x7F,0xFF,0x6F,0xB4,0x00,0x00}     /* Also under 7F20*/
#define PATH_EMLPP_ID   {0x7F,0xFF,0x6F,0xB5,0x00,0x00}    /* Also under 7F20*/
#define PATH_AAEM_ID   {0x7F,0xFF,0x6F,0xB6,0x00,0x00}     /* Also under 7F20*/
#define PATH_CBMID_ID   {0x7F,0xFF,0x6F,0x48,0x00,0x00}    /* Also under 7F20*/
#define PATH_ECC_ID   {0x7F,0xFF,0x6F,0xB7,0x00,0x00}      /* Also under 7F20*/
#define PATH_CBMIR_ID   {0x7F,0xFF,0x6F,0x50,0x00,0x00}    /* Also under 7F20*/
#define PATH_DCK_ID   {0x7F,0xFF,0x6F,0x2C,0x00,0x00}      /* Also under 7F20*/
#define PATH_CNL_ID   {0x7F,0xFF,0x6F,0x32,0x00,0x00}      /* Also under 7F20*/      
#define PATH_NIA_ID   {0x7F,0xFF,0x6F,0x51,0x00,0x00}      /* Also under 7F20*/
#define PATH_KCGPRS_ID   {0x7F,0xFF,0x5F,0x3B,0x4F,0x52}   /* Also under 7F20*/
#define PATH_LOCIGPRS_ID   {0x7F,0xFF,0x6F,0x73,0x00,0x00} /* Also 6F53 under 7F20 */
#define PATH_SUME_ID   {0x7F,0x10,0x6F,0x54,0x00,0x00}     /* Also 6F54 under 7F20*/
#define PATH_PLMNWACT_ID   {0x7F,0xFF,0x6F,0x60,0x00,0x00} /* Also under 7F20*/
#define PATH_OPLMNWACT_ID   {0x7F,0xFF,0x6F,0x61,0x00,0x00}/* Also under 7F20*/
#define PATH_HPLMNACT_ID   {0x7F,0xFF,0x6F,0x62,0x00,0x00} /* Also under 7F20*/
#define PATH_CPBCCH_ID   {0x7F,0xFF,0x5F,0x3B,0x4F,0x63}   /* Also 6F63 under 7F20 */
#define PATH_INVSCAN_ID   {0x7F,0xFF,0x5F,0x3B,0x4F,0x64}  /* Also 6F64 under 7F20 */
#define PATH_VM_WAIT_ID   {0x7F,0x20,0x6F,0x11,0x00,0x00}
#define PATH_CPHS_SST_ID   {0x7F,0x20,0x6F,0x12,0x00,0x00}
#define PATH_CF_FLAG_ID   {0x7F,0x20,0x6F,0x13,0x00,0x00}
#define PATH_OP_STRING_ID   {0x7F,0x20,0x6F,0x14,0x00,0x00}
#define PATH_CSP_ID   {0x7F,0x20,0x6F,0x15,0x00,0x00}
#define PATH_CPHS_INFO_ID   {0x7F,0x20,0x6F,0x16,0x00,0x00}
#define PATH_MAILBOX_NUM_ID   {0x7F,0x20,0x6F,0x17,0x00,0x00}
#define PATH_OP_SHORTFORM_ID   {0x7F,0x20,0x6F,0x18,0x00,0x00}
#define PATH_INFO_NUM_ID   {0x7F,0x20,0x6F,0x19,0x00,0x00}
#define PATH_ADN_ID   {0x7F,0x10,0x6F,0x3A,0x00,0x00}      /* !!!!! */
#define PATH_FDN_ID   {0x7F,0xFF,0x6F,0x3B,0x00,0x00}      /* Also 6F3B under 7F10 */
#define PATH_SMS_ID   {0x7F,0xFF,0x6F,0x3C,0x00,0x00}      /* Also 6F3C under 7F10 */
#define PATH_CCP_ID   {0x7F,0x10,0x6F,0x4F,0x00,0x00}      /* !!!!! Map to ECCP in USIM. Also 6F3D under 7F10 */
#define PATH_ECCP_ID   {0x7F,0x10,0x6F,0x4F,0x00,0x00}     /* !!!!! */
#define PATH_MSISDN_ID   {0x7F,0xFF,0x6F,0x40,0x00,0x00}   /* Also 6F40 under 7F10 */
#define PATH_SMSP_ID   {0x7F,0xFF,0x6F,0x42,0x00,0x00}     /* Also 6F42 under 7F10 */
#define PATH_SMSS_ID   {0x7F,0xFF,0x6F,0x43,0x00,0x00}     /* Also 6F43 under 7F10 */
#define PATH_LND_ID   {0x7F,0x10,0x6F,0x44,0x00,0x00}      /* xxxxx */
#define PATH_SDN_ID   {0x7F,0xFF,0x6F,0x49,0x00,0x00}      /* Also 6F49 under 7F10 */
#define PATH_EXT1_ID   {0x7F,0x10,0x6F,0x4A,0x00,0x00}     /* !!!!! */
#define PATH_EXT2_ID   {0x7F,0xFF,0x6F,0x4B,0x00,0x00}     /* Also 6F4B under 7F10 */     
#define PATH_EXT3_ID   {0x7F,0xFF,0x6F,0x4C,0x00,0x00}     /* Also 6F4C under 7F10 */
#define PATH_BDN_ID   {0x7F,0xFF,0x6F,0x4D,0x00,0x00}      /* Also 6F4D under 7F10 */
#define PATH_EXT4_ID   {0x7F,0xFF,0x6F,0x55,0x00,0x00}     /* Also 6F4E under 7F10 */
#define PATH_SMSR_ID   {0x7F,0x10,0x6F,0x47,0x00,0x00}
#define PATH_CMI_ID   {0x7F,0xFF,0x6F,0x58,0x00,0x00}      /* Also under 7F20*/
#define PATH_IMG_1_ID   {0x7F,0x10,0x5F,0x50,0x4F,0x01}
#define PATH_IMG_2_ID   {0x7F,0x10,0x5F,0x50,0x4F,0x02}
#define PATH_IMG_3_ID   {0x7F,0x10,0x5F,0x50,0x4F,0x03}
#define PATH_IMG_4_ID   {0x7F,0x10,0x5F,0x50,0x4F,0x04}
#define PATH_IMG_5_ID   {0x7F,0x10,0x5F,0x50,0x4F,0x05}
#define PATH_IMG_6_ID   {0x7F,0x10,0x5F,0x50,0x4F,0x06}
#define PATH_IMG_7_ID   {0x7F,0x10,0x5F,0x50,0x4F,0x07}
#define PATH_IMG_8_ID   {0x7F,0x10,0x5F,0x50,0x4F,0x08}
#define PATH_IMG_9_ID   {0x7F,0x10,0x5F,0x50,0x4F,0x09}
#define PATH_IMG_A_ID   {0x7F,0x10,0x5F,0x50,0x4F,0x0A}
#define PATH_IMG_B_ID   {0x7F,0x10,0x5F,0x50,0x4F,0x0B}
#define PATH_IMG_C_ID   {0x7F,0x10,0x5F,0x50,0x4F,0x0C}
#define PATH_IMG_D_ID   {0x7F,0x10,0x5F,0x50,0x4F,0x0D}
#define PATH_IMG_E_ID   {0x7F,0x10,0x5F,0x50,0x4F,0x0E}
#define PATH_IMG_F_ID   {0x7F,0x10,0x5F,0x50,0x4F,0x0F}
#define PATH_VID_ID   {0x7F,0x43,0x00,0x00,0x00,0x00} 
/* HomeZone Support */
#define PATH_HZ_ID   {0x7F,0x43,0x6F,0x60,0x00,0x00}
#define PATH_HZ_CACHE1_ID   {0x7F,0x43,0x6F,0x61,0x00,0x00}
#define PATH_HZ_CACHE2_ID   {0x7F,0x43,0x6F,0x62,0x00,0x00}
#define PATH_HZ_CACHE3_ID   {0x7F,0x43,0x6F,0x63,0x00,0x00}
#define PATH_HZ_CACHE4_ID   {0x7F,0x43,0x6F,0x64,0x00,0x00}
#define PATH_PNN_ID   {0x7F,0xFF,0x6F,0xC5,0x00,0x00}
#define PATH_OPL_ID   {0x7F,0xFF,0x6F,0xC6,0x00,0x00}
#define PATH_MBDN_ID   {0x7F,0x20,0x6F,0xC7,0x00,0x00}
#define PATH_EXT6_ID   {0x7F,0x20,0x6F,0xC8,0x00,0x00}
#define PATH_MBI_ID   {0x7F,0x20,0x6F,0xC9,0x00,0x00}
#define PATH_MWIS_ID   {0x7F,0x20,0x6F,0xCA,0x00,0x00}
#define PATH_CFIS_ID   {0x7F,0x20,0x6F,0xCB,0x00,0x00}
#define PATH_EXT7_ID   {0x7F,0x20,0x6F,0xCC,0x00,0x00}
#define PATH_SPDI_ID   {0x7F,0x20,0x6F,0xCD,0x00,0x00}
#define PATH_MMSN_ID   {0x7F,0x20,0x6F,0xCE,0x00,0x00}
#define PATH_EXT8_ID   {0x7F,0x20,0x6F,0xCF,0x00,0x00}
#define PATH_MMSICP_ID   {0x7F,0x20,0x6F,0xD0,0x00,0x00}
#define PATH_MMSUP_ID   {0x7F,0x20,0x6F,0xD1,0x00,0x00}
#define PATH_MMSUCP_ID   {0x7F,0x20,0x6F,0xD2,0x00,0x00}
#define PATH_DIR_ID   {0x2F,0x00,0x00,0x00,0x00,0x00}
#define PATH_ARR_ID   {0x2F,0x06,0x00,0x00,0x00,0x00}
#define PATH_USIM_ID   {0x7F,0xFF,0x00,0x00,0x00,0x00}
#define PATH_U_LI_ID   {0x7F,0xFF,0x6F,0x05,0x00,0x00}
#define PATH_U_IMSI_ID   {0x7F,0xFF,0x6F,0x07,0x00,0x00}
#define PATH_U_KEYS_ID   {0x7F,0xFF,0x6F,0x08,0x00,0x00}
#define PATH_U_KEYSPS_ID   {0x7F,0xFF,0x6F,0x09,0x00,0x00}
#define PATH_U_PLMNWACT_ID   {0x7F,0xFF,0x6F,0x60,0x00,0x00}
#define PATH_U_HPPLMN_ID   {0x7F,0xFF,0x6F,0x31,0x00,0x00}
#define PATH_U_ACMMAX_ID   {0x7F,0xFF,0x6F,0x37,0x00,0x00}
#define PATH_U_UST_ID   {0x7F,0xFF,0x6F,0x38,0x00,0x00}
#define PATH_U_ACM_ID   {0x7F,0xFF,0x6F,0x39,0x00,0x00}
#define PATH_U_GID1_ID   {0x7F,0xFF,0x6F,0x3E,0x00,0x00}
#define PATH_U_GID2_ID   {0x7F,0xFF,0x6F,0x3F,0x00,0x00}
#define PATH_U_SPN_ID   {0x7F,0xFF,0x6F,0x46,0x00,0x00}
#define PATH_U_PUCT_ID   {0x7F,0xFF,0x6F,0x41,0x00,0x00}
#define PATH_U_CBMI_ID   {0x7F,0xFF,0x6F,0x45,0x00,0x00}
#define PATH_U_ACC_ID   {0x7F,0xFF,0x6F,0x78,0x00,0x00}
#define PATH_U_FPLMN_ID   {0x7F,0xFF,0x6F,0x7B,0x00,0x00}
#define PATH_U_LOCI_ID   {0x7F,0xFF,0x6F,0x7E,0x00,0x00}
#define PATH_U_AD_ID   {0x7F,0xFF,0x6F,0xAD,0x00,0x00}
#define PATH_U_CBMID_ID   {0x7F,0xFF,0x6F,0x48,0x00,0x00}
#define PATH_U_ECC_ID   {0x7F,0xFF,0x6F,0xB7,0x00,0x00}
#define PATH_U_CBMIR_ID   {0x7F,0xFF,0x6F,0x50,0x00,0x00}
#define PATH_U_PSLOCI_ID   {0x7F,0xFF,0x6F,0x73,0x00,0x00}
#define PATH_U_FDN_ID   {0x7F,0xFF,0x6F,0x3B,0x00,0x00}
#define PATH_U_SMS_ID   {0x7F,0xFF,0x6F,0x3C,0x00,0x00}
#define PATH_U_MSISDN_ID   {0x7F,0xFF,0x6F,0x40,0x00,0x00}
#define PATH_U_SMSP_ID   {0x7F,0xFF,0x6F,0x42,0x00,0x00}
#define PATH_U_SMSS_ID   {0x7F,0xFF,0x6F,0x43,0x00,0x00}
#define PATH_U_SDN_ID   {0x7F,0xFF,0x6F,0x49,0x00,0x00}
#define PATH_U_EXT2_ID   {0x7F,0xFF,0x6F,0x4B,0x00,0x00}
#define PATH_U_EXT3_ID   {0x7F,0xFF,0x6F,0x4C,0x00,0x00}
#define PATH_U_SMSR_ID   {0x7F,0xFF,0x6F,0x47,0x00,0x00}
#define PATH_U_ICI_ID   {0x7F,0xFF,0x6F,0x80,0x00,0x00}
#define PATH_U_OCI_ID   {0x7F,0xFF,0x6F,0x81,0x00,0x00}
#define PATH_U_ICT_ID   {0x7F,0xFF,0x6F,0x82,0x00,0x00}
#define PATH_U_OCT_ID   {0x7F,0xFF,0x6F,0x83,0x00,0x00}
#define PATH_U_EXT5_ID   {0x7F,0xFF,0x6F,0x4E,0x00,0x00}
#define PATH_U_CCP2_ID   {0x7F,0xFF,0x6F,0x4F,0x00,0x00}
#define PATH_U_EMLPP_ID   {0x7F,0xFF,0x6F,0xB5,0x00,0x00}
#define PATH_U_AAEM_ID   {0x7F,0xFF,0x6F,0xB6,0x00,0x00}
#define PATH_U_HIDDENKEY_ID   {0x7F,0xFF,0x6F,0xC3,0x00,0x00}
#define PATH_U_BDN_ID   {0x7F,0xFF,0x6F,0x4D,0x00,0x00}
#define PATH_U_EXT4_ID   {0x7F,0xFF,0x6F,0x55,0x00,0x00}
#define PATH_U_CMI_ID   {0x7F,0xFF,0x6F,0x58,0x00,0x00}
#define PATH_U_EST_ID   {0x7F,0xFF,0x6F,0x56,0x00,0x00}
#define PATH_U_ACL_ID   {0x7F,0xFF,0x6F,0x57,0x00,0x00}
#define PATH_U_DCK_ID   {0x7F,0xFF,0x6F,0x2C,0x00,0x00}
#define PATH_U_CNL_ID   {0x7F,0xFF,0x6F,0x32,0x00,0x00}
#define PATH_U_STARTHFN_ID   {0x7F,0xFF,0x6F,0x5B,0x00,0x00}
#define PATH_U_THRESHOLD_ID   {0x7F,0xFF,0x6F,0x5C,0x00,0x00}
#define PATH_U_OPLMNWACT_ID   {0x7F,0xFF,0x6F,0x61,0x00,0x00}
#define PATH_U_HPLMNWACT_ID   {0x7F,0xFF,0x6F,0x62,0x00,0x00}
#define PATH_U_ARR_ID   {0x7F,0xFF,0x6F,0x06,0x00,0x00}
#define PATH_U_NETPAR_ID   {0x7F,0xFF,0x6F,0xC4,0x00,0x00}
#define PATH_U_PNN_ID   {0x7F,0xFF,0x6F,0xC5,0x00,0x00}
#define PATH_U_OPL_ID   {0x7F,0xFF,0x6F,0xC6,0x00,0x00}
#define PATH_U_MBDN_ID   {0x7F,0xFF,0x6F,0xC7,0x00,0x00}
#define PATH_U_EXT6_ID   {0x7F,0xFF,0x6F,0xC8,0x00,0x00}
#define PATH_U_MBI_ID   {0x7F,0xFF,0x6F,0xC9,0x00,0x00}
#define PATH_U_MWIS_ID   {0x7F,0xFF,0x6F,0xCA,0x00,0x00}
#define PATH_U_CFIS_ID   {0x7F,0xFF,0x6F,0xCB,0x00,0x00}
#define PATH_U_EXT7_ID   {0x7F,0xFF,0x6F,0xCC,0x00,0x00}
#define PATH_U_SPDI_ID   {0x7F,0xFF,0x6F,0xCD,0x00,0x00}
#define PATH_U_MMSN_ID   {0x7F,0xFF,0x6F,0xCE,0x00,0x00}
#define PATH_U_EXT8_ID   {0x7F,0xFF,0x6F,0xCF,0x00,0x00}
#define PATH_U_MMSICP_ID   {0x7F,0xFF,0x6F,0xD0,0x00,0x00}
#define PATH_U_MMSUP_ID   {0x7F,0xFF,0x6F,0xD1,0x00,0x00}
#define PATH_U_MMSUCP_ID   {0x7F,0xFF,0x6F,0xD2,0x00,0x00}
#define PATH_U_NIA_ID   {0x7F,0xFF,0x6F,0xD3,0x00,0x00}
#define PATH_U_VGCS_ID   {0x7F,0xFF,0x6F,0xB1,0x00,0x00}
#define PATH_U_VGCSS_ID   {0x7F,0xFF,0x6F,0xB2,0x00,0x00}
#define PATH_U_VBS_ID   {0x7F,0xFF,0x6F,0xB3,0x00,0x00}
#define PATH_U_VBSS_ID   {0x7F,0xFF,0x6F,0xB4,0x00,0x00}
#define PATH_U_VGCSCA_ID   {0x7F,0xFF,0x6F,0xD4,0x00,0x00}
#define PATH_U_VBSCA_ID   {0x7F,0xFF,0x6F,0xD5,0x00,0x00}
#define PATH_U_GBAP_ID   {0x7F,0xFF,0x6F,0xD6,0x00,0x00}
#define PATH_U_MSK_ID   {0x7F,0xFF,0x6F,0xD7,0x00,0x00}
#define PATH_U_MUK_ID   {0x7F,0xFF,0x6F,0xD8,0x00,0x00}
#define PATH_U_GBANL_ID   {0x7F,0xFF,0x6F,0xDA,0x00,0x00}
#define PATH_U_SOLSA_ID   {0x7F,0xFF,0x5F,0x70,0x00,0x00}
#define PATH_U_SAI_ID   {0x7F,0xFF,0x4F,0x30,0x00,0x00}
#define PATH_U_SLL_ID   {0x7F,0xFF,0x4F,0x31,0x00,0x00}
#define PATH_U_LSAD_ID   {0x00,0x00,0x00,0x00,0x00,0x00}
#define PATH_U_PHONEBOOK_ID   {0x7F,0xFF,0x5F,0x3A,0x00,0x00}
#define PATH_U_PBR_ID   {0x7F,0xFF,0x5F,0x3A,0x4F,0x30}
#define PATH_U_IAP_ID   {0x00,0x00,0x00,0x00,0x00,0x00}
#define PATH_U_ADN_ID   {0x00,0x00,0x00,0x00,0x00,0x00}
#define PATH_U_EXT1_ID   {0x00,0x00,0x00,0x00,0x00,0x00}
#define PATH_U_PBC_ID   {0x00,0x00,0x00,0x00,0x00,0x00}
#define PATH_U_GRP_ID   {0x00,0x00,0x00,0x00,0x00,0x00}
#define PATH_U_AAS_ID   {0x00,0x00,0x00,0x00,0x00,0x00}
#define PATH_U_GAS_ID   {0x00,0x00,0x00,0x00,0x00,0x00}
#define PATH_U_ANR_ID   {0x00,0x00,0x00,0x00,0x00,0x00}
#define PATH_U_SNE_ID   {0x00,0x00,0x00,0x00,0x00,0x00}
#define PATH_U_CCP1_ID   {0x00,0x00,0x00,0x00,0x00,0x00}
#define PATH_U_UID_ID   {0x00,0x00,0x00,0x00,0x00,0x00}
#define PATH_U_PSC_ID   {0x7F,0xFF,0x5F,0x3A,0x4F,0x22}
#define PATH_U_CC_ID   {0x7F,0xFF,0x5F,0x3A,0x4F,0x23}
#define PATH_U_PUID_ID   {0x7F,0xFF,0x5F,0x3A,0x4F,0x24}
#define PATH_U_EMAIL_ID   {0x00,0x00,0x00,0x00,0x00,0x00}
#define PATH_U_GSMACCESS_ID   {0x7F,0xFF,0x5F,0x3B,0x00,0x00}
#define PATH_U_KC_ID   {0x7F,0xFF,0x5F,0x3B,0x4F,0x20}
#define PATH_U_KCGPRS_ID   {0x7F,0xFF,0x5F,0x3B,0x4F,0x52}
#define PATH_U_CPBCCH_ID   {0x7F,0xFF,0x5F,0x3B,0x4F,0x63}
#define PATH_U_INVSCAN_ID   {0x7F,0xFF,0x5F,0x3B,0x4F,0x64}
#define PATH_U_MEXE_ID   {0x7F,0xFF,0x5F,0x3C,0x00,0x00}
#define PATH_U_MEXEST_ID   {0x7F,0xFF,0x5F,0x3C,0x4F,0x40}
#define PATH_U_ORPK_ID   {0x7F,0xFF,0x5F,0x3C,0x4F,0x41}
#define PATH_U_ARPK_ID   {0x7F,0xFF,0x5F,0x3C,0x4F,0x42}
#define PATH_U_TPRPK_ID   {0x7F,0xFF,0x5F,0x3C,0x4F,0x43}
#define PATH_U_TKCDF_ID   {0x00,0x00,0x00,0x00,0x00,0x00}
#define PATH_U_WLAN_ID   {0x7F,0xFF,0x5F,0x40,0x00,0x00}
#define PATH_U_PSEUDO_ID   {0x7F,0xFF,0x5F,0x40,0x4F,0x41}
#define PATH_U_UPLMNWLAN_ID   {0x7F,0xFF,0x5F,0x40,0x4F,0x42}
#define PATH_U_OPLMNWLAN_ID   {0x7F,0xFF,0x5F,0x40,0x4F,0x43}
#define PATH_U_USSIDL_ID   {0x7F,0xFF,0x5F,0x40,0x4F,0x44}
#define PATH_U_OSSIDL_ID   {0x7F,0xFF,0x5F,0x40,0x4F,0x45}
#define PATH_U_WRI_ID   {0x7F,0xFF,0x5F,0x40,0x4F,0x46}
#define PATH_G_PHONEBOOK_ID   {0x7F,0x10,0x5F,0x3A,0x00,0x00}
#define PATH_G_PBR_ID   {0x7F,0x10,0x5F,0x3A,0x4F,0x30}
#define PATH_G_IAP_ID   {0x00,0x00,0x00,0x00,0x00,0x00}
#define PATH_G_ADN_ID   {0x00,0x00,0x00,0x00,0x00,0x00}
#define PATH_G_EXT1_ID   {0x00,0x00,0x00,0x00,0x00,0x00}
#define PATH_G_PBC_ID   {0x00,0x00,0x00,0x00,0x00,0x00}
#define PATH_G_GRP_ID   {0x00,0x00,0x00,0x00,0x00,0x00}
#define PATH_G_AAS_ID   {0x00,0x00,0x00,0x00,0x00,0x00}
#define PATH_G_GAS_ID   {0x00,0x00,0x00,0x00,0x00,0x00}
#define PATH_G_ANR_ID   {0x00,0x00,0x00,0x00,0x00,0x00}
#define PATH_G_SNE_ID   {0x00,0x00,0x00,0x00,0x00,0x00}
#define PATH_G_CCP1_ID   {0x00,0x00,0x00,0x00,0x00,0x00}
#define PATH_G_UID_ID   {0x00,0x00,0x00,0x00,0x00,0x00}
#define PATH_G_PSC_ID   {0x7F,0x10,0x5F,0x3A,0x4F,0x22}
#define PATH_G_CC_ID   {0x7F,0x10,0x5F,0x3A,0x4F,0x23}
#define PATH_G_PUID_ID   {0x7F,0x10,0x5F,0x3A,0x4F,0x24}
#define PATH_G_EMAIL_ID   {0x00,0x00,0x00,0x00,0x00,0x00}
#define PATH_MULTIMEDIA_ID   {0x7F,0x10,0x5F,0x3B,0x00,0x00}
#define PATH_MML_ID   {0x7F,0x10,0x5F,0x3B,0x4F,0x47}
#define PATH_MMDF_ID   {0x7F,0x10,0x5F,0x3B,0x4F,0x48}
#define PATH_NONE_ID   {0x00,0x00,0x00,0x00,0x00,0x00}

#ifdef LOW_COST_SUPPORT
#define MAX_SUPPORT_EF_PLMNSEL_REC       10
#define MAX_SUPPORT_EF_UPLMNWACT_REC     10
#define MAX_SUPPORT_EF_OPLMNWACT_REC     10
#else
#define MAX_SUPPORT_EF_PLMNSEL_REC       150
#define MAX_SUPPORT_EF_UPLMNWACT_REC     150
#define MAX_SUPPORT_EF_OPLMNWACT_REC     150
#endif /* LOW_COST_SUPPORT */

#define MAX_SUPPORT_EF_PLMNSEL_SIZE 3 * MAX_SUPPORT_EF_PLMNSEL_REC
#define MAX_SUPPORT_EF_UPLMNWACT_SIZE 5 * MAX_SUPPORT_EF_UPLMNWACT_REC
#define MAX_SUPPORT_EF_OPLMNWACT_SIZE 5 * MAX_SUPPORT_EF_OPLMNWACT_REC

typedef enum
{
    SIMCALLCONTROL_NOMODIFY,
    SIMCALLCONTROL_CALLTOSS,
    SIMCALLCONTROL_CALLTOUSSD,
    SIMCALLCONTROL_SSTOCALL,
    SIMCALLCONTROL_SSTOUSSD,
    SIMCALLCONTROL_USSDTOCALL,
    SIMCALLCONTROL_USSDTOSS,
    SIMCALLCONTROL_L4RETRY
}sim_call_control_type_enum;


typedef enum
{
   TYPE_NONE=0,
   TYPE_ADN=0x2,
   TYPE_FDN=0x4,
   TYPE_BDN=0x8,
   TYPE_ADN_BDN=0x0A,
   TYPE_FDN_BDN=0x0C
}sim_dn_enum;

typedef enum
{
   SIM_CHV_1=1,
   SIM_CHV_2=2
}sim_chv_type_enum;

typedef enum
{
   RESET,
   INIT,
   PUK1
}sim_start_mode_enum;

typedef enum
{
   SIM_PHASE_0,
   SIM_PHASE_2=2,
   SIM_PHASE_3=3
}sim_phase_enum;

typedef enum
{
   ELP,
   LP,
   USIM_LI,
   USIM_PL
}sim_lp_file_type_enum;



typedef enum
{
   SIM_FILE_SIZE,
   SIM_REC_NUM,
   SIM_REC_SIZE
}sim_info_type_enum;

typedef enum
{
   SIM_TYPE_NULL,
   SIM_TYPE_TEST_SIM,
   SIM_TYPE_TEST_USIM,
   SIM_TYPE_SIM,
   SIM_TYPE_USIM
} sim_type_query_enum;

#ifndef __USIM_SUPPORT__
typedef enum
{
   SERVICE_CHV_DISABLE_FUNCTION=1,
   SERVICE_ADN,
   SERVICE_FDN,
   SERVICE_SMS,
   SERVICE_AOC,
   SERVICE_CCP,
   SERVICE_PLMNSEL,
   SERVICE_RFU1,
   SERVICE_MSISDN,
   SERVICE_EXT1,
   SERVICE_EXT2,
   SERVICE_SMSP,
   SERVICE_LND,
   SERVICE_CBMI,
   SERVICE_GID1,
   SERVICE_GID2,
   SERVICE_SPN,
   SERVICE_SDN,
   SERVICE_EXT3,
   SERVICE_RFU2,
   SERVICE_VGCS,
   SERVICE_VBS,
   SERVICE_EMLPP,
   SERVICE_AAEM,
   SERVICE_DATA_DOWNLOAD_SMS_CB,
   SERVICE_DATA_DOWNLOAD_SMS_PP,
   SERVICE_MENU_SELECTION,
   SERVICE_CALL_CONTROL,
   SERVICE_PROACTIVE_SIM,
   SERVICE_CBMIR,
   SERVICE_BDN,
   SERVICE_EXT4,
   SERVICE_DCK,
   SERVICE_CNL,
   SERVICE_SMSR,
   SERVICE_NW_IND_ALERT,
   SERVICE_MO_SMS,
   SERVICE_GPRS,
   SERVICE_IMAGE,
   SERVICE_SOLSA,
   SERVICE_USSD,
   SERVICE_RUN_AT_CMD,
   SERVICE_PLMNWACT,
   SERVICE_OPLMNWACT,
   SERVICE_HPLMNWACT,
   SERVICE_CPBCCH,
   SERVICE_INVSCAN,
   SERVICE_ECCP,
   SERVICE_MEXE,
   SERVICE_RFU,
   SERVICE_PLMN_NAME,
   SERVICE_OPLMN_LIST,
   SERVICE_MAILBOX_DIAL_NUM,
   SERVICE_MSG_WAIT_IND,
   SERVICE_CALL_FWD_IND,
   SERVICE_SP_DSPL_INFO,
   SERVICE_MMS,
   SERVICE_EXT8,
   SERVICE_MMS_UCP,
   SERVICE_EMPTY, /* 60 */
   SERVICE_CSP=(4*SIM_SUPPORT_SST_LEN+1),
   SERVICE_SST,
   SERVICE_MAILBOX_NUM,
   SERVICE_OPNAME_SHORTFORM,
   SERVICE_INFO_NUM,
   SERVICE_END
}sim_service_enum;
#else /* __USIM_SUPPORT__ */
typedef enum
{
    SERVICE_CHV_DISABLE_FUNCTION=1,
    SERVICE_ADN,
    SERVICE_FDN,
    SERVICE_SMS,
    SERVICE_AOC,
    SERVICE_CCP,
    SERVICE_PLMNSEL,
    SERVICE_RFU1,
    SERVICE_MSISDN,
    SERVICE_EXT1,
    SERVICE_EXT2,
    SERVICE_SMSP,
    SERVICE_LND,
    SERVICE_CBMI,
    SERVICE_GID1,
    SERVICE_GID2,
    SERVICE_SPN,
    SERVICE_SDN,
    SERVICE_EXT3,
    SERVICE_RFU2,
    SERVICE_VGCS,
    SERVICE_VBS,
    SERVICE_EMLPP,
    SERVICE_AAEM,
    SERVICE_DATA_DOWNLOAD_SMS_CB,
    SERVICE_DATA_DOWNLOAD_SMS_PP,
    SERVICE_MENU_SELECTION,
    SERVICE_CALL_CONTROL,
    SERVICE_PROACTIVE_SIM,
    SERVICE_CBMIR,
    SERVICE_BDN,
    SERVICE_EXT4,
    SERVICE_DCK,
    SERVICE_CNL,
    SERVICE_SMSR,
    SERVICE_NW_IND_ALERT,
    SERVICE_MO_SMS,
    SERVICE_GPRS,
    SERVICE_IMAGE,
    SERVICE_SOLSA,
    SERVICE_USSD,
    SERVICE_RUN_AT_CMD,
    SERVICE_PLMNWACT,
    SERVICE_OPLMNWACT,
    SERVICE_HPLMNWACT,
    SERVICE_CPBCCH,
    SERVICE_INVSCAN,
    SERVICE_ECCP,
    SERVICE_MEXE,
    SERVICE_RFU,
    SERVICE_PLMN_NAME,
    SERVICE_OPLMN_LIST,
    SERVICE_MAILBOX_DIAL_NUM,
    SERVICE_MSG_WAIT_IND,
    SERVICE_CALL_FWD_IND,
    SERVICE_SP_DSPL_INFO,
    SERVICE_MMS,
    SERVICE_EXT8,
    SERVICE_MMS_UCP,
    SERVICE_EMPTY, /* 60 */
    SERVICE_CSP=(4*SIM_SUPPORT_SST_LEN+1),
    SERVICE_SST,
    SERVICE_MAILBOX_NUM,
    SERVICE_OPNAME_SHORTFORM,
    SERVICE_INFO_NUM,
    SERVICE_END
}sim_service_enum;

typedef enum
{
    SERVICE_U_LOCAL_PHB=1,
    SERVICE_U_FDN,
    SERVICE_U_EXT2,
    SERVICE_U_SDN,
    SERVICE_U_EXT3,
    SERVICE_U_BDN,
    SERVICE_U_EXT4,
    SERVICE_U_OCI_OCT,
    SERVICE_U_ICI_ICT,
    SERVICE_U_SMS,
    SERVICE_U_SMSR,
    SERVICE_U_SMSP,
    SERVICE_U_AOC,
    SERVICE_U_CCP,
    SERVICE_U_CBMI,
    SERVICE_U_CBMIR,
    SERVICE_U_GID1,
    SERVICE_U_GID2,
    SERVICE_U_SPN,
    SERVICE_U_PLMNWACT,
    SERVICE_U_MSISDN,
    SERVICE_U_IMG,
    SERVICE_U_SOLSA,
    SERVICE_U_EMLPP,
    SERVICE_U_AAEM,
    SERVICE_U_RFU,
    SERVICE_U_GSM_ACCESS,
    SERVICE_U_DATA_DOWNLOAD_SMS_PP,
    SERVICE_U_DATA_DOWNLOAD_SMS_CB,
    SERVICE_U_CALL_CONTROL,
    SERVICE_U_SMS_CONTROL,
    SERVICE_U_RUN_AT_CMD,
    SERVICE_U_RFU_1,
    SERVICE_U_EST,
    SERVICE_U_ACL,
    SERVICE_U_DCK,
    SERVICE_U_CO_NWLIST,
    SERVICE_U_GSM_SECURITY_CTX,
    SERVICE_U_CPBCCH,
    SERVICE_U_INVSCAN,
    SERVICE_U_MEXE,
    SERVICE_U_OPLMNWACT,
    SERVICE_U_HPLMNWACT,
    SERVICE_U_EXT5,
    SERVICE_U_PLMN_NAME,
    SERVICE_U_OPLMN_LIST,
    SERVICE_U_MAILBOX_DIAL_NUM,
    SERVICE_U_MSG_WAIT_IND,
    SERVICE_U_CALL_FWD_IND,
    SERVICE_U_RFU_2,
    SERVICE_U_SP_DSPL_INFO,
    SERVICE_U_MMS,
    SERVICE_U_EXT8,
    SERVICE_U_GPRS_CALL_CONTROL,
    SERVICE_U_MMS_UCP,
    SERVICE_U_NIA,
    SERVICE_U_END
} usim_service_enum;

#define SERVICE_EST_FDN 0x01
#define SERVICE_EST_BDN 0x02
#define SERVICE_EST_ACL 0x03

#endif /* __USIM_SUPPORT__ */

typedef enum
{
   SIM_CARD_REMOVED,
   SIM_ACCESS_ERROR,
   SIM_REFRESH,
   SIM_REFRESH_POWER_OFF,
   SIM_PUK1,
   SIM_ACCESS_PROFILE_ON,
   SIM_ACCESS_PROFILE_OFF
}sim_error_cause_enum;

typedef enum
{
   SIM_SEEK_TYPE1_FROM_BEG=0x00,
   SIM_SEEK_TYPE1_FROM_BACK=0x01,
   SIM_SEEK_TYPE1_FROM_NEXT=0x02,
   SIM_SEEK_TYPE1_FROM_PREV=0x03,
   SIM_SEEK_TYPE2_FROM_BEG=0x10,
   SIM_SEEK_TYPE2_FROM_BACK=0x11,
   SIM_SEEK_TYPE2_FROM_NEXT=0x12,
   SIM_SEEK_TYPE2_FROM_PREV=0x13
}sim_seek_type_mode_enum;

typedef enum
{
   SIM_CMD_SUCCESS        = 2560,
   SIM_CMD_FAIL           = 2561,
   SIM_FATAL_ERROR        = 2562,
   SIM_NO_INSERTED        = 2563,
   SIM_CHV_NOT_INIT       = 2564,
   SIM_CHV_RETRY_ALLOW    = 2565,
   SIM_CHV_BLOCK          = 2566,
   SIM_ACCESS_NOT_ALLOW   = 2567,
   SIM_SAT_CMD_BUSY       = 2568,
   SIM_DL_ERROR           = 2569,
   SIM_MEMORY_PROBLEM     = 2570,
   SIM_TECHNICAL_PROBLEM  = 2571,
   SIM_PUK_UNLOCK   = 2572, /* add new enum value to distinguish whether normal poweron or PUK-unlock-poweron */   
   SIM_EF_RECORD_FULL = 2573, /*add new enum value to represent no free record in the file*/
   /* USIM related results */
   SIM_SELECT_FILE_INVALID = 2574,
   SIM_SELECT_DF_TERMINATED = 2575,
   SIM_NO_EF_SELECTED = 2576,
   SIM_FILE_NOT_FOUND = 2577,
   SIM_RECORD_NOT_FOUND = 2578,
   SIM_REF_DATA_NOT_FOUND = 2579,
   SIM_INCREASE_FAIL = 2580,
   SIM_AUTH_ERROR_WRONG_MAC = 2581,
   SIM_AUTH_ERROR_GSM_NOT_SUPPORT = 2582
}sim_cmd_result_enum;

typedef enum
{
   SIM_REPORT_MEMORY_PROBLEM,	
   SIM_ACCESS_NOT_FULFILLED,
   SIM_SECORD_CODE_BLOCK	
}sim_status_report_enum;


typedef enum
{
   VERIFY,
   DISABLE,
   ENABLE,
   CHANGE,
   UNBLOCK
}sim_security_operation_enum;

typedef enum
{
   SERVICE_NOT_SUPPORT,
   SERVICE_SUPPORT,
   SERVICE_ALLOCATE,
   SERVICE_UNDEFINED
}sim_service_state_enum;

#ifndef __USIM_SUPPORT__
typedef enum
{

   FILE_NONE,
   FILE_MF_IDX,
   FILE_GSM_IDX,
   FILE_TELECOM_IDX,
   FILE_IRIDIUM_IDX,
   FILE_GLOBST_IDX,
   FILE_ICO_IDX,
   FILE_ACES_IDX,
   FILE_EIA_IDX,
   FILE_CTS_IDX,
   FILE_SOLSA_IDX,
   FILE_MEXE_IDX,
   FILE_GRAPHICS_IDX,
   FILE_ICCID_IDX,
   FILE_ELP_IDX,
   FILE_SAI_IDX,
   FILE_SLL_IDX,
   FILE_MEXE_ST_IDX,
   FILE_ORPK_IDX,
   FILE_ARPK_IDX,
   FILE_TPRPK_IDX,/*20*/
   FILE_IMG_IDX,
   FILE_LP_IDX,
   FILE_IMSI_IDX,
   FILE_KC_IDX,
   FILE_PLMNSEL_IDX,
   FILE_HPLMN_IDX,
   FILE_ACMAX_IDX,
   FILE_SST_IDX,
   FILE_ACM_IDX,
   FILE_GID1_IDX,/*30*/
   FILE_GID2_IDX,
   FILE_SPN_IDX,
   FILE_PUCT_IDX,
   FILE_CBMI_IDX,
   FILE_BCCH_IDX,
   FILE_ACC_IDX,
   FILE_FPLMN_IDX,
   FILE_LOCI_IDX,
   FILE_AD_IDX,
   FILE_PHASE_IDX,
   FILE_VGCS_IDX,
   FILE_VGCSS_IDX,
   FILE_VBS_IDX,
   FILE_VBSS_IDX,
   FILE_EMLPP_IDX,
   FILE_AAEM_IDX,
   FILE_CBMID_IDX,
   FILE_ECC_IDX,
   FILE_CBMIR_IDX,
   FILE_DCK_IDX, /*50*/
   FILE_CNL_IDX,
   FILE_NIA_IDX,
   FILE_KCGPRS_IDX,
   FILE_LOCIGPRS_IDX,
   FILE_SUME_IDX,
   FILE_PLMNWACT_IDX,
   FILE_OPLMNWACT_IDX,
   FILE_HPLMNACT_IDX,
   FILE_CPBCCH_IDX,
   FILE_INVSCAN_IDX,/*60*/
   FILE_VM_WAIT_IDX,
   FILE_CPHS_SST_IDX,
   FILE_CF_FLAG_IDX,
   FILE_OP_STRING_IDX,
   FILE_CSP_IDX,
   FILE_CPHS_INFO_IDX,
   FILE_MAILBOX_NUM_IDX,
   FILE_OP_SHORTFORM_IDX,
   FILE_INFO_NUM_IDX,
   FILE_ADN_IDX,
   FILE_FDN_IDX, /*71*/
   FILE_SMS_IDX,
   FILE_CCP_IDX,
   FILE_ECCP_IDX,
   FILE_MSISDN_IDX,
   FILE_SMSP_IDX,
   FILE_SMSS_IDX,
   FILE_LND_IDX,
   FILE_SDN_IDX,
   FILE_EXT1_IDX,
   FILE_EXT2_IDX,
   FILE_EXT3_IDX,
   FILE_BDN_IDX,
   FILE_EXT4_IDX,
   FILE_SMSR_IDX,
   FILE_CMI_IDX,
   FILE_IMG_1_IDX,
   FILE_IMG_2_IDX,
   FILE_IMG_3_IDX,
   FILE_IMG_4_IDX,
   FILE_IMG_5_IDX,
   FILE_IMG_6_IDX,
   FILE_IMG_7_IDX,
   FILE_IMG_8_IDX,
   FILE_IMG_9_IDX,
   FILE_IMG_A_IDX,
   FILE_IMG_B_IDX,
   FILE_IMG_C_IDX,
   FILE_IMG_D_IDX,
   FILE_IMG_E_IDX,
   FILE_IMG_F_IDX,  /* 101 */
   #ifdef __HOMEZONE_SUPPORT__
   /* For HomeZone support */
   FILE_VID_IDX,
   FILE_HZ_IDX,
   FILE_HZ_CACHE1_IDX,
   FILE_HZ_CACHE2_IDX,
   FILE_HZ_CACHE3_IDX,
   FILE_HZ_CACHE4_IDX,
   #endif /* __HOMEZONE_SUPPORT__ */
   /* Support Rel.4 SIM files in 51.011 */
   FILE_PNN_IDX,
   FILE_OPL_IDX,
   FILE_MBDN_IDX,
   FILE_EXT6_IDX,
   FILE_MBI_IDX,
   FILE_MWIS_IDX,
   FILE_CFIS_IDX,
   FILE_EXT7_IDX,
   FILE_SPDI_IDX,
   FILE_MMSN_IDX,
   FILE_EXT8_IDX,
   FILE_MMSICP_IDX,
   FILE_MMSUP_IDX,
   FILE_MMSUCP_IDX,
   SIM_TOT_FILES
}sim_file_index_enum;
#else /* __USIM_SUPPORT__ */
#define sim_file_index_enum usim_file_index_enum
typedef enum
{
    FILE_NONE,         
    FILE_MF_IDX,
    FILE_GSM_IDX,
    FILE_TELECOM_IDX,
    FILE_IRIDIUM_IDX,
    FILE_GLOBST_IDX,
    FILE_ICO_IDX,
    FILE_ACES_IDX,
    FILE_EIA_IDX,
    FILE_CTS_IDX,
    FILE_SOLSA_IDX, /*10*/
    FILE_MEXE_IDX, 
    FILE_GRAPHICS_IDX,
    FILE_ICCID_IDX,
    FILE_ELP_IDX,
    FILE_SAI_IDX,
    FILE_SLL_IDX,
    FILE_MEXE_ST_IDX,
    FILE_ORPK_IDX,
    FILE_ARPK_IDX,
    FILE_TPRPK_IDX,/*20*/
    FILE_IMG_IDX,
    FILE_LP_IDX,
    FILE_IMSI_IDX,
    FILE_KC_IDX,
    FILE_PLMNSEL_IDX,
    FILE_HPLMN_IDX,
    FILE_ACMAX_IDX,
    FILE_SST_IDX,
    FILE_ACM_IDX,
    FILE_GID1_IDX,/*30*/
    FILE_GID2_IDX,
    FILE_SPN_IDX,
    FILE_PUCT_IDX,
    FILE_CBMI_IDX,
    FILE_BCCH_IDX,
    FILE_ACC_IDX,
    FILE_FPLMN_IDX,
    FILE_LOCI_IDX,
    FILE_AD_IDX,
    FILE_PHASE_IDX,/*40*/
    FILE_VGCS_IDX,
    FILE_VGCSS_IDX,
    FILE_VBS_IDX,
    FILE_VBSS_IDX,
    FILE_EMLPP_IDX,
    FILE_AAEM_IDX,
    FILE_CBMID_IDX,
    FILE_ECC_IDX,
    FILE_CBMIR_IDX,
    FILE_DCK_IDX,/*50*/
    FILE_CNL_IDX,
    FILE_NIA_IDX,
    FILE_KCGPRS_IDX,
    FILE_LOCIGPRS_IDX,
    FILE_SUME_IDX,
    FILE_PLMNWACT_IDX,
    FILE_OPLMNWACT_IDX,
    FILE_HPLMNACT_IDX,
    FILE_CPBCCH_IDX,
    FILE_INVSCAN_IDX,/*60*/
    FILE_VM_WAIT_IDX,
    FILE_CPHS_SST_IDX,
    FILE_CF_FLAG_IDX,
    FILE_OP_STRING_IDX,
    FILE_CSP_IDX,
    FILE_CPHS_INFO_IDX,
    FILE_MAILBOX_NUM_IDX,
    FILE_OP_SHORTFORM_IDX,
    FILE_INFO_NUM_IDX,
    FILE_ADN_IDX,
    FILE_FDN_IDX,/*71*/
    FILE_SMS_IDX,
    FILE_CCP_IDX,
    FILE_ECCP_IDX,
    FILE_MSISDN_IDX,
    FILE_SMSP_IDX,
    FILE_SMSS_IDX,
    FILE_LND_IDX,
    FILE_SDN_IDX,
    FILE_EXT1_IDX,/*80*/
    FILE_EXT2_IDX,
    FILE_EXT3_IDX,
    FILE_BDN_IDX,
    FILE_EXT4_IDX,
    FILE_SMSR_IDX,
    FILE_CMI_IDX,
    FILE_IMG_1_IDX,
    FILE_IMG_2_IDX,
    FILE_IMG_3_IDX,
    FILE_IMG_4_IDX,/*90*/
    FILE_IMG_5_IDX,
    FILE_IMG_6_IDX,
    FILE_IMG_7_IDX,
    FILE_IMG_8_IDX,
    FILE_IMG_9_IDX,
    FILE_IMG_A_IDX,
    FILE_IMG_B_IDX,
    FILE_IMG_C_IDX,
    FILE_IMG_D_IDX,
    FILE_IMG_E_IDX,
    FILE_IMG_F_IDX,/* 101 */
   #ifdef __HOMEZONE_SUPPORT__    
    FILE_VID_IDX, 
    /* HomeZone Support */
    FILE_HZ_IDX,
    FILE_HZ_CACHE1_IDX,
    FILE_HZ_CACHE2_IDX,
    FILE_HZ_CACHE3_IDX,
    FILE_HZ_CACHE4_IDX,
    #endif /* __HOMEZONE_SUPPORT__ */
    FILE_PNN_IDX,
    FILE_OPL_IDX,
    FILE_MBDN_IDX,
    FILE_EXT6_IDX,
    FILE_MBI_IDX,
    FILE_MWIS_IDX,
    FILE_CFIS_IDX,
    FILE_EXT7_IDX,
    FILE_SPDI_IDX,
    FILE_MMSN_IDX,
    FILE_EXT8_IDX,
    FILE_MMSICP_IDX,
    FILE_MMSUP_IDX,
    FILE_MMSUCP_IDX,
    SIM_TOT_FILES,
    FILE_DIR_IDX  = SIM_TOT_FILES,
    FILE_ARR_IDX,       
    FILE_USIM_IDX,
    FILE_U_LI_IDX,
    FILE_U_IMSI_IDX,
    FILE_U_KEYS_IDX,
    FILE_U_KEYSPS_IDX,
    FILE_U_PLMNWACT_IDX, /*129*/
    FILE_U_HPPLMN_IDX,
    FILE_U_ACMMAX_IDX,
    FILE_U_UST_IDX,
    FILE_U_ACM_IDX,
    FILE_U_GID1_IDX,
    FILE_U_GID2_IDX,
    FILE_U_SPN_IDX,
    FILE_U_PUCT_IDX,
    FILE_U_CBMI_IDX,
    FILE_U_ACC_IDX,/*139*/
    FILE_U_FPLMN_IDX,
    FILE_U_LOCI_IDX,
    FILE_U_AD_IDX,
    FILE_U_CBMID_IDX,
    FILE_U_ECC_IDX,
    FILE_U_CBMIR_IDX,
    FILE_U_PSLOCI_IDX,
    FILE_U_FDN_IDX,
    FILE_U_SMS_IDX,
    FILE_U_MSISDN_IDX,/*149*/
    FILE_U_SMSP_IDX,  
    FILE_U_SMSS_IDX,
    FILE_U_SDN_IDX,
    FILE_U_EXT2_IDX,
    FILE_U_EXT3_IDX,
    FILE_U_SMSR_IDX,
    FILE_U_ICI_IDX,
    FILE_U_OCI_IDX,
    FILE_U_ICT_IDX,
    FILE_U_OCT_IDX, /*159*/
    FILE_U_EXT5_IDX,  
    FILE_U_CCP2_IDX,
    FILE_U_EMLPP_IDX,
    FILE_U_AAEM_IDX,
    FILE_U_HIDDENKEY_IDX,
    FILE_U_BDN_IDX,
    FILE_U_EXT4_IDX,
    FILE_U_CMI_IDX,
    FILE_U_EST_IDX,
    FILE_U_ACL_IDX, /*169*/
    FILE_U_DCK_IDX,  
    FILE_U_CNL_IDX,
    FILE_U_STARTHFN_IDX,
    FILE_U_THRESHOLD_IDX,
    FILE_U_OPLMNWACT_IDX,
    FILE_U_HPLMNWACT_IDX,
    FILE_U_ARR_IDX,
    FILE_U_NETPAR_IDX,
    FILE_U_PNN_IDX,
    FILE_U_OPL_IDX, /*179*/
    FILE_U_MBDN_IDX,
    FILE_U_EXT6_IDX,
    FILE_U_MBI_IDX,
    FILE_U_MWIS_IDX,
    FILE_U_CFIS_IDX,
    FILE_U_EXT7_IDX,
    FILE_U_SPDI_IDX,
    FILE_U_MMSN_IDX,
    FILE_U_EXT8_IDX,
    FILE_U_MMSICP_IDX, /*189*/
    FILE_U_MMSUP_IDX,
    FILE_U_MMSUCP_IDX,
    FILE_U_NIA_IDX,
    FILE_U_VGCS_IDX,
    FILE_U_VGCSS_IDX,
    FILE_U_VBS_IDX,
    FILE_U_VBSS_IDX,
    FILE_U_VGCSCA_IDX,
    FILE_U_VBSCA_IDX,
    FILE_U_GBAP_IDX, /*199*/
    FILE_U_MSK_IDX,   
    FILE_U_MUK_IDX,
    FILE_U_GBANL_IDX,
    FILE_U_SOLSA_IDX,
    FILE_U_SAI_IDX,
    FILE_U_SLL_IDX,
    FILE_U_LSAD_IDX,
    FILE_U_PHONEBOOK_IDX,
    FILE_U_PBR_IDX,
    FILE_U_IAP_IDX, /*209*/
    FILE_U_ADN_IDX,   
    FILE_U_EXT1_IDX,
    FILE_U_PBC_IDX,
    FILE_U_GRP_IDX,
    FILE_U_AAS_IDX,
    FILE_U_GAS_IDX,
    FILE_U_ANR_IDX,
    FILE_U_SNE_IDX,
    FILE_U_CCP1_IDX,
    FILE_U_UID_IDX, /*219*/
    FILE_U_PSC_IDX,   
    FILE_U_CC_IDX,
    FILE_U_PUID_IDX,
    FILE_U_EMAIL_IDX,
    FILE_U_GSMACCESS_IDX,
    FILE_U_KC_IDX,
    FILE_U_KCGPRS_IDX,
    FILE_U_CPBCCH_IDX,
    FILE_U_INVSCAN_IDX,
    FILE_U_MEXE_IDX, /*229*/
    FILE_U_MEXEST_IDX, 
    FILE_U_ORPK_IDX,
    FILE_U_ARPK_IDX,
    FILE_U_TPRPK_IDX,
    FILE_U_TKCDF_IDX,
    FILE_U_WLAN_IDX,
    FILE_U_PSEUDO_IDX,
    FILE_U_UPLMNWLAN_IDX,
    FILE_U_OPLMNWLAN_IDX,
    FILE_U_USSIDL_IDX, /*239*/
    FILE_U_OSSIDL_IDX,  
    FILE_U_WRI_IDX,
    FILE_G_PHONEBOOK_IDX,
    FILE_G_PBR_IDX,
    FILE_G_IAP_IDX,
    FILE_G_ADN_IDX,
    FILE_G_EXT1_IDX,
    FILE_G_PBC_IDX,
    FILE_G_GRP_IDX,
    FILE_G_AAS_IDX, /*249*/
    FILE_G_GAS_IDX,    
    FILE_G_ANR_IDX,
    FILE_G_SNE_IDX,
    FILE_G_CCP1_IDX,
    FILE_G_UID_IDX,
    FILE_G_PSC_IDX,
    FILE_G_CC_IDX,
    FILE_G_PUID_IDX,
    FILE_G_EMAIL_IDX,
    FILE_MULTIMEDIA_IDX, /*259*/
    FILE_MML_IDX,     
    FILE_MMDF_IDX,
    UICC_TOTAL_FILES /* 262 UICC_TOTAL_FILES */
}usim_file_index_enum;
#endif /* __USIM_SUPPORT__ */

#ifndef __USIM_SUPPORT__
typedef enum
{
   SIM_NO_FILE_ID     = 0x0000,
   MASTER_FILE_ID     = 0x3f00, /* Master File */
   /* Dedicated File under Master File */
   DF_GSM_ID          = 0x7f20,
   DF_TELECOM_ID      = 0x7f10,

   /* Dedicated files under DF_GSM */
   DF_IRIDIUM_ID      = 0x5f30,
   DF_GLOBST_ID       = 0x5f31,
   DF_ICO_ID          = 0x5f32,
   DF_ACeS_ID         = 0x5f33,
   DF_EIA_ID          = 0x5f40,
   DF_CTS_ID          = 0x5f60,
   DF_SoLSA_ID        = 0x5f70,
   DF_MExE_ID         = 0x5f3C,
   /* Dedicated File under DF_TELECOM */
   DF_GRAPHICS_ID     = 0x5f50,
   /* Elementary Files under Master File */
   EF_ICCID_ID        = 0x2fE2,
   EF_ELP_ID          = 0x2f05,
   /* Elementary Files under DF_SoLSA */
   EF_SAI_ID          = 0x4f30,
   EF_SLL_ID          = 0x4f31,
   /* Elementary Files under DF_MExE */
   EF_MExE_ST_ID      = 0x4f40,
   EF_ORPK_ID         = 0x4f41,
   EF_ARPK_ID         = 0x4f42,
   EF_TPRPK_ID        = 0x4f43,
   /* Elementary Files at DF_GRAPHICS */
   EF_IMG_ID          = 0x4f20,

   EF_IMG_1_ID        = 0x4f01,
   EF_IMG_2_ID        = 0x4f02,
   EF_IMG_3_ID        = 0x4f03,
   EF_IMG_4_ID        = 0x4f04,
   EF_IMG_5_ID        = 0x4f05,
   EF_IMG_6_ID        = 0x4f06,
   EF_IMG_7_ID        = 0x4f07,
   EF_IMG_8_ID        = 0x4f08,
   EF_IMG_9_ID        = 0x4f09,
   EF_IMG_A_ID        = 0x4f0a,
   EF_IMG_B_ID        = 0x4f0b,
   EF_IMG_C_ID        = 0x4f0c,
   EF_IMG_D_ID        = 0x4f0d,
   EF_IMG_E_ID        = 0x4f0e,
   EF_IMG_F_ID        = 0x4f0f,

   /* Elementary Files under DF_GSM */
   EF_LP_ID           = 0x6f05,
   EF_IMSI_ID         = 0x6f07,
   EF_Kc_ID           = 0x6f20,
   EF_PLMNsel_ID      = 0x6f30,
   EF_HPLMN_ID        = 0x6f31,
   EF_ACMax_ID        = 0x6f37,
   EF_SST_ID          = 0x6f38,
   EF_ACM_ID          = 0x6f39,
   EF_GID1_ID         = 0x6f3E,
   EF_GID2_ID         = 0x6f3F,
   EF_SPN_ID          = 0x6f46,
   EF_PUCT_ID         = 0x6f41,
   EF_CBMI_ID         = 0x6f45,
   EF_BCCH_ID         = 0x6f74,
   EF_ACC_ID          = 0x6f78,
   EF_FPLMN_ID        = 0x6f7B,
   EF_LOCI_ID         = 0x6f7E,
   EF_AD_ID           = 0x6fAD,
   EF_PHASE_ID        = 0x6fAE,
   EF_VGCS_ID         = 0x6fB1,
   EF_VGCSS_ID        = 0x6fB2,
   EF_VBS_ID          = 0x6fB3,
   EF_VBSS_ID         = 0x6fB4,
   EF_eMLPP_ID        = 0x6fB5,
   EF_AAeM_ID         = 0x6fB6,
   EF_CBMID_ID        = 0x6f48,
   EF_ECC_ID          = 0x6fB7,
   EF_CBMIR_ID        = 0x6f50,
   EF_DCK_ID          = 0x6f2C,
   EF_CNL_ID          = 0x6f32,
   EF_NIA_ID          = 0x6f51,
   EF_KcGPRS_ID       = 0x6f52,
   EF_LOCIGPRS_ID     = 0x6f53,
   EF_SUME_ID         = 0x6f54,
   EF_PLMNwACT_ID     = 0x6f60,
   EF_OPLMNwACT_ID    = 0x6f61,
   EF_HPLMNACT_ID     = 0x6f62,
   EF_CPBCCH_ID       = 0x6f63,
   EF_INVSCAN_ID      = 0x6f64,
   EF_VM_WAIT_ID      = 0x6F11,
   EF_CPHS_SST_ID     = 0x6F12,
   EF_CF_FLAG_ID      = 0x6F13,
   EF_OP_STRING_ID    = 0x6F14,
   EF_CSP_ID          = 0x6F15,
   EF_CPHS_INFO_ID    = 0x6F16,
   EF_MAILBOX_NUM_ID  = 0x6F17,
   EF_OP_SHORTFORM_ID = 0x6F18,
   EF_INFO_NUM_ID     = 0x6F19,
   /* Elementary Files at DF_TELECOM Level */
   EF_ADN_ID          = 0x6f3A,
   EF_FDN_ID          = 0x6f3B,
   EF_SMS_ID          = 0x6f3C,
   EF_CCP_ID          = 0x6f3D,
   EF_ECCP_ID         = 0x6f4F,
   EF_MSISDN_ID       = 0x6f40,
   EF_SMSP_ID         = 0x6f42,
   EF_SMSS_ID         = 0x6f43,
   EF_LND_ID          = 0x6f44,
   EF_SDN_ID          = 0x6f49,
   EF_EXT1_ID         = 0x6f4A,
   EF_EXT2_ID         = 0x6f4B,
   EF_EXT3_ID         = 0x6f4C,
   EF_BDN_ID          = 0x6f4D,
   EF_EXT4_ID         = 0x6f4E,
   EF_SMSR_ID         = 0x6f47,
   EF_CMI_ID          = 0x6f58,
#ifdef __HOMEZONE_SUPPORT__   
   DF_VID_ID                = 0x7F43,
   EF_HZ_ID                  = 0x6F60,
   EF_HZ_CACHE1_ID   = 0x6F61,
   EF_HZ_CACHE2_ID   = 0x6F62,
   EF_HZ_CACHE3_ID   = 0x6F63,
   EF_HZ_CACHE4_ID   = 0x6F64,
#endif /* __HOMEZONE_SUPPORT__ */   
   /* Support Rel.4 SIM files in 51.011 */
   EF_PNN_ID = 0x6FC5,
   EF_OPL_ID = 0x6FC6,
   EF_MBDN_ID    = 0x6FC7,
   EF_EXT6_ID     = 0x6FC8,
   EF_MBI_ID       = 0x6FC9,
   EF_MWIS_ID    = 0x6FCA,
   EF_CFIS_ID      =  0x6FCB,
   EF_EXT7_ID      = 0x6FCC,
   EF_SPDI_ID      = 0x6FCD,
   EF_MMSN_ID     = 0x6FCE,
   EF_EXT8_ID      = 0x6FCF,
   EF_MMSICP_ID  = 0x6FD0,
   EF_MMSUP_ID   = 0x6FD1,
   EF_MMSUCP_ID = 0x6FD2,   
   EF_NULL            = 0xFFFF
}sim_file_id_enum;
#else  /* __USIM_SUPPORT__ */
#define sim_file_id_enum usim_file_id_enum
typedef enum
{
    SIM_NO_FILE_ID     = 0x0000,
    MASTER_FILE_ID     = 0x3f00, /* Master File */
    /* Dedicated File under Master File */
    DF_GSM_ID          = 0x7f20,
    DF_TELECOM_ID      = 0x7f10,

    /* Dedicated files under DF_GSM */
    DF_IRIDIUM_ID      = 0x5f30,
    DF_GLOBST_ID       = 0x5f31,
    DF_ICO_ID          = 0x5f32,
    DF_ACeS_ID         = 0x5f33,
    DF_EIA_ID          = 0x5f40,
    DF_CTS_ID          = 0x5f60,
    DF_SoLSA_ID        = 0x5f70,
    DF_MExE_ID         = 0x5f3C,
    /* Dedicated File under DF_TELECOM */
    DF_GRAPHICS_ID     = 0x5f50,
    /* Elementary Files under Master File */
    EF_ICCID_ID        = 0x2fE2,
    EF_ELP_ID          = 0x2f05,
    /* Elementary Files under DF_SoLSA */
    EF_SAI_ID          = 0x4f30,
    EF_SLL_ID          = 0x4f31,
    /* Elementary Files under DF_MExE */
    EF_MExE_ST_ID      = 0x4f40,
    EF_ORPK_ID         = 0x4f41,
    EF_ARPK_ID         = 0x4f42,
    EF_TPRPK_ID        = 0x4f43,
    /* Elementary Files at DF_GRAPHICS */
    EF_IMG_ID          = 0x4f20,
    EF_IMG_1_ID        = 0x4f01,
    EF_IMG_2_ID        = 0x4f02,
    EF_IMG_3_ID        = 0x4f03,
    EF_IMG_4_ID        = 0x4f04,
    EF_IMG_5_ID        = 0x4f05,
    EF_IMG_6_ID        = 0x4f06,
    EF_IMG_7_ID        = 0x4f07,
    EF_IMG_8_ID        = 0x4f08,
    EF_IMG_9_ID        = 0x4f09,
    EF_IMG_A_ID        = 0x4f0a,
    EF_IMG_B_ID        = 0x4f0b,
    EF_IMG_C_ID        = 0x4f0c,
    EF_IMG_D_ID        = 0x4f0d,
    EF_IMG_E_ID        = 0x4f0e,
    EF_IMG_F_ID        = 0x4f0f,

    /* Elementary Files under DF_GSM */
    EF_LP_ID           = 0x6f05,
    EF_IMSI_ID         = 0x6f07,
    EF_Kc_ID           = 0x6f20,
    EF_PLMNsel_ID      = 0x6f30,
    EF_HPLMN_ID        = 0x6f31,
    EF_ACMax_ID        = 0x6f37,
    EF_SST_ID          = 0x6f38,
    EF_ACM_ID          = 0x6f39,
    EF_GID1_ID         = 0x6f3E,
    EF_GID2_ID         = 0x6f3F,
    EF_SPN_ID          = 0x6f46,
    EF_PUCT_ID         = 0x6f41,
    EF_CBMI_ID         = 0x6f45,
    EF_BCCH_ID         = 0x6f74,
    EF_ACC_ID          = 0x6f78,
    EF_FPLMN_ID        = 0x6f7B,
    EF_LOCI_ID         = 0x6f7E,
    EF_AD_ID           = 0x6fAD,
    EF_PHASE_ID        = 0x6fAE,
    EF_VGCS_ID         = 0x6fB1,
    EF_VGCSS_ID        = 0x6fB2,
    EF_VBS_ID          = 0x6fB3,
    EF_VBSS_ID         = 0x6fB4,
    EF_eMLPP_ID        = 0x6fB5,
    EF_AAeM_ID         = 0x6fB6,
    EF_CBMID_ID        = 0x6f48,
    EF_ECC_ID          = 0x6fB7,
    EF_CBMIR_ID        = 0x6f50,
    EF_DCK_ID          = 0x6f2C,
    EF_CNL_ID          = 0x6f32,
    EF_NIA_ID          = 0x6f51,
    EF_KcGPRS_ID       = 0x6f52,
    EF_LOCIGPRS_ID     = 0x6f53,
    EF_SUME_ID         = 0x6f54,
    EF_PLMNwACT_ID     = 0x6f60,
    EF_OPLMNwACT_ID    = 0x6f61,
    EF_HPLMNACT_ID     = 0x6f62,
    EF_CPBCCH_ID       = 0x6f63,
    EF_INVSCAN_ID      = 0x6f64,
    EF_VM_WAIT_ID      = 0x6F11,
    EF_CPHS_SST_ID     = 0x6F12,
    EF_CF_FLAG_ID      = 0x6F13,
    EF_OP_STRING_ID    = 0x6F14,
    EF_CSP_ID          = 0x6F15,
    EF_CPHS_INFO_ID    = 0x6F16,
    EF_MAILBOX_NUM_ID  = 0x6F17,
    EF_OP_SHORTFORM_ID = 0x6F18,
    EF_INFO_NUM_ID     = 0x6F19,
    /* Elementary Files at DF_TELECOM Level */
    EF_ADN_ID          = 0x6f3A,
    EF_FDN_ID          = 0x6f3B,
    EF_SMS_ID          = 0x6f3C,
    EF_CCP_ID          = 0x6f3D,
    EF_ECCP_ID         = 0x6f4F,
    EF_MSISDN_ID       = 0x6f40,
    EF_SMSP_ID         = 0x6f42,
    EF_SMSS_ID         = 0x6f43,
    EF_LND_ID          = 0x6f44,
    EF_SDN_ID          = 0x6f49,
    EF_EXT1_ID         = 0x6f4A,
    EF_EXT2_ID         = 0x6f4B,
    EF_EXT3_ID         = 0x6f4C,
    EF_BDN_ID          = 0x6f4D,
    EF_EXT4_ID         = 0x6f4E,
    EF_SMSR_ID         = 0x6f47,
    EF_CMI_ID          = 0x6f58,
    /* HomeZone Support */
    DF_VID_ID                = 0x7F43,
    EF_HZ_ID                  = 0x6F60,
    EF_HZ_CACHE1_ID   = 0x6F61,
    EF_HZ_CACHE2_ID   = 0x6F62,
    EF_HZ_CACHE3_ID   = 0x6F63,
    EF_HZ_CACHE4_ID   = 0x6F64,
    EF_PNN_ID               = 0x6FC5,
    EF_OPL_ID               =  0x6FC6,
    EF_MBDN_ID              = 0x6FC7,
    EF_EXT6_ID             = 0x6FC8,
    EF_MBI_ID               = 0x6FC9,
    EF_MWIS_ID            = 0x6FCA,
    EF_CFIS_ID             =  0x6FCB,
    EF_EXT7_ID             = 0x6FCC,
    EF_SPDI_ID             = 0x6FCD,
    EF_MMSN_ID           = 0x6FCE,
    EF_EXT8_ID            = 0x6FCF,
    EF_MMSICP_ID        = 0x6FD0,
    EF_MMSUP_ID         = 0x6FD1,
    EF_MMSUCP_ID       = 0x6FD2,
    EF_DIR_ID              =  0x2F00,
    /* USIM FILES */
    EF_ARR_ID              = 0x2F06,
    DF_USIM_ID            = 0x7FFF,
    EF_U_LI_ID             = 0x6F05,
    EF_U_IMSI_ID        = 0x6F07,
    EF_U_KEYS_ID        = 0x6F08,
    EF_U_KEYSPS_ID    = 0x6F09,
    EF_U_PLMNWACT_ID    = 0x6F60,
    EF_U_HPPLMN_ID         = 0x6F31,
    EF_U_ACMMAX_ID        = 0x6F37,
    EF_U_UST_ID               = 0x6F38,
    EF_U_ACM_ID               =0x6F39,
    EF_U_GID1_ID             = 0x6F3E,
    EF_U_GID2_ID             = 0x6F3F,
    EF_U_SPN_ID               = 0x6F46,
    EF_U_PUCT_ID             = 0x6F41,
    EF_U_CBMI_ID             = 0x6F45,
    EF_U_ACC_ID              = 0x6F78,
    EF_U_FPLMN_ID          = 0x6F7B,
    EF_U_LOCI_ID             = 0x6F7E,
    EF_U_AD_ID                = 0x6FAD,
    EF_U_CBMID_ID          = 0x6F48,
    EF_U_ECC_ID              = 0x6FB7,
    EF_U_CBMIR_ID          = 0x6F50,
    EF_U_PSLOCI_ID         = 0x6F73,
    EF_U_FDN_ID              = 0x6F3B,
    EF_U_SMS_ID              = 0x6F3C,
    EF_U_MSISDN_ID        = 0x6F40,
    EF_U_SMSP_ID            = 0x6F42,
    EF_U_SMSS_ID            = 0x6F43,
    EF_U_SDN_ID              = 0x6F49,
    EF_U_EXT2_ID            = 0x6F4B,
    EF_U_EXT3_ID            = 0x6F4C,
    EF_U_SMSR_ID           = 0x6F47,
    EF_U_ICI_ID               = 0x6F80,
    EF_U_OCI_ID              = 0x6F81,
    EF_U_ICT_ID              = 0x6F82,
    EF_U_OCT_ID             = 0x6F83,
    EF_U_EXT5_ID           = 0x6F4E,
    EF_U_CCP2_ID           = 0x6F4F,
    EF_U_EMLPP_ID         = 0x6FB5,
    EF_U_AAEM_ID          = 0x6FB6,
    EF_U_HIDDENKEY_ID    = 0x6FC3,
    EF_U_BDN_ID                = 0x6F4D,
    EF_U_EXT4_ID              = 0x6F55,
    EF_U_CMI_ID                = 0x6F58,
    EF_U_EST_ID                = 0x6F56,
    EF_U_ACL_ID                = 0x6F57,
    EF_U_DCK_ID                = 0x6F2C,
    EF_U_CNL_ID                = 0x6F32,
    EF_U_STARTHFN_ID     = 0x6F5B,
    EF_U_THRESHOLD_ID   = 0x6F5C,
    EF_U_OPLMNWACT_ID  = 0x6F61,
    EF_U_HPLMNWACT_ID  = 0x6F62,
    EF_U_ARR_ID                = 0x6F06,
    EF_U_NETPAR_ID         = 0x6FC4,
    EF_U_PNN_ID                = 0x6FC5,
    EF_U_OPL_ID                = 0x6FC6,
    EF_U_MBDN_ID             = 0x6FC7,
    EF_U_EXT6_ID              = 0x6FC8,
    EF_U_MBI_ID                =  0x6FC9,
    EF_U_MWIS_ID              = 0x6FCA,
    EF_U_CFIS_ID               = 0x6FCB,
    EF_U_EXT7_ID               = 0x6FCC,
    EF_U_SPDI_ID               = 0x6FCD,
    EF_U_MMSN_ID             = 0x6FCE,
    EF_U_EXT8_ID              = 0x6FCF,
    EF_U_MMSICP_ID          = 0x6FD0,
    EF_U_MMSUP_ID           = 0x6FD1,
    EF_U_MMSUCP_ID          = 0x6FD2,
    EF_U_NIA_ID                 = 0x6FD3,
    EF_U_VGCS_ID               = 0x6FB1,
    EF_U_VGCSS_ID             = 0x6FB2,
    EF_U_VBS_ID                 = 0x6FB3,
    EF_U_VBSS_ID               = 0x6FB4,
    EF_U_VGCSCA_ID           = 0x6FD4,
    EF_U_VBSCA_ID             = 0x6FD5,
    EF_U_GBAP_ID               = 0x6FD6,
    EF_U_MSK_ID                 = 0x6FD7,
    EF_U_MUK_ID                 = 0x6FD8,
    EF_U_GBANL_ID             = 0x6FDA,
    DF_U_SOLSA_ID             = 0x5F70,
    EF_U_SAI_ID                  = 0x4F30,
    EF_U_SLL_ID                  = 0x4F31,
    EF_U_LSAD_ID               = 0x0000,
    DF_U_PHONEBOOK_ID    = 0x5F3A,
    EF_U_PBR_ID                 = 0x4F30,
    EF_U_IAP_ID                  = 0x0000,
    EF_U_ADN_ID                 = 0x0000,
    EF_U_EXT1_ID                = 0x0000,
    EF_U_PBC_ID                  = 0x0000,
    EF_U_GRP_ID                 =  0x0000,
    EF_U_AAS_ID                 = 0x0000,
    EF_U_GAS_ID                 = 0x0000,
    EF_U_ANR_ID                 = 0x0000,
    EF_U_SNE_ID                 = 0x0000,
    EF_U_CCP1_ID                = 0x0000,
    EF_U_UID_ID                   = 0x0000,
    EF_U_PSC_ID                  = 0x4F22,
    EF_U_CC_ID                    = 0x4F23,
    EF_U_PUID_ID                = 0x4F24,
    EF_U_EMAIL_ID              = 0x0000,
    DF_U_GSMACCESS_ID    = 0x5F3B,
    EF_U_KC_ID                   = 0x4F20,
    EF_U_KCGPRS_ID           = 0x4F52,
    EF_U_CPBCCH_ID           = 0x4F63,
    EF_U_INVSCAN_ID         = 0x4F64,
    DF_U_MEXE_ID              = 0x5F3C,
    EF_U_MEXEST_ID          = 0x4F40,
    EF_U_ORPK_ID              = 0x4F41,
    EF_U_ARPK_ID              = 0x4F42,
    EF_U_TPRPK_ID             = 0x4F43,
    EF_U_TKCDF_ID             = 0x0000,
    DF_U_WLAN_ID              = 0x5F40,
    EF_U_PSEUDO_ID           = 0x4F41,
    EF_U_UPLMNWLAN_ID    = 0x4F42,
    EF_U_OPLMNWLAN_ID    = 0x4F43,
    EF_U_USSIDL_ID            = 0x4F44,
    EF_U_OSSIDL_ID            = 0x4F45,
    EF_U_WRI_ID                 = 0x4F46,
    DF_G_PHONEBOOK_ID    = 0x5F3A,
    EF_G_PBR_ID                 = 0x4F30,
    EF_G_IAP_ID                  = 0x0000,
    EF_G_ADN_ID                 = 0x0000,
    EF_G_EXT1_ID                = 0x0000,
    EF_G_PBC_ID                  = 0x0000,
    EF_G_GRP_ID                 =  0x0000,
    EF_G_AAS_ID                 = 0x0000,
    EF_G_GAS_ID                 = 0x0000,
    EF_G_ANR_ID                 = 0x0000,
    EF_G_SNE_ID                 = 0x0000,
    EF_G_CCP1_ID                = 0x0000,
    EF_G_UID_ID                   = 0x0000,    
    EF_G_PSC_ID                 = 0x4F22,
    EF_G_CC_ID                   = 0x4F23,
    EF_G_PUID_ID                = 0x4F24,
    EF_G_EMAIL_ID              = 0x0000,
    DF_MULTIMEDIA_ID       = 0x5F3B,
    EF_MML_ID                     = 0x4F47,
    EF_MMDF_ID                   = 0x4F48,
    EF_NULL                          = 0xFFFF
}usim_file_id_enum;
#endif /* __USIM_SUPPORT__ */

typedef enum
{
   SIM_NOT_READY, /* initial state */
   SIM_CARD_NOT_INSERTED, /* No SIM found after initialization */
   NORMAL_SIM_PRESENCE, /* Normal SIM found after initialization */
   TEST_SIM_PRESENCE /* Test SIM found after initialization */
}sim_card_status_enum;

#ifdef __SAT__
typedef enum
{
   SAT_MM_NO_SERVICE,
   SAT_MM_LIMITED_SERVICE,
   SAT_MM_NORMAL_SERVICE
}sat_mm_status_enum;

typedef enum
{
   SAT_CALL_DISCONNECT,
   SAT_CALL_CONNECT
}sat_call_status_enum;

typedef enum
{
   TYPE_SIM_INIT_AND_FULL_FILE_CHANGE,
   TYPE_FILE_CHANGE,
   TYPE_SIM_INIT_AND_FILE_CHANGE,
   TYPE_SIM_INIT,
   TYPE_SIM_RESET    
}sat_refresh_type_enum;
#endif

typedef struct 
{
   /* This field gives the actual file id of EF */ 
   sim_file_id_enum           file_id;

   /* This field gives the id of the parent of the EF */ 
   sim_file_index_enum        parent_file_idx;

   /* This field gives the id of the grandparent of the EF */ 
   sim_file_index_enum        grand_parent_file_idx;

}sim_ef_info_struct;

extern const sim_ef_info_struct sim_ef_info[ SIM_TOT_FILES ];
#define SIM_EF_INFO(sim_file_index_enum, X)  sim_ef_info[sim_file_index_enum].X
#ifdef __GEMINI__
extern sim_service_state_enum sim_service_table_query(sim_service_enum service_id, kal_uint8 simInterface);
extern kal_bool is_test_sim(kal_uint8 simInterface);
extern sim_card_status_enum check_sim_card_status(kal_uint8 simInterface);
#else
extern sim_service_state_enum sim_service_table_query(sim_service_enum service_id);
extern kal_bool is_test_sim(void);
extern sim_card_status_enum check_sim_card_status(void);
#endif

//extern sim_service_state_enum sim_service_table_query_2(sim_service_enum service_id);
extern sim_file_index_enum sim_id_map_to_index(kal_uint16 file_id);
//extern kal_bool is_test_sim_2(void);
#ifdef __USIM_SUPPORT__
/******************************************************************************
 *
 * USIM Part
 *
 ******************************************************************************/

typedef enum
{
    USIM_PIN1_APP1 = 0x01,
    USIM_PIN1_APP2 = 0x02,
    USIM_PIN1_APP3 = 0x03,
    USIM_PIN1_APP4 = 0x04,
    USIM_PIN1_APP5 = 0x05,
    USIM_PIN1_APP6 = 0x06,
    USIM_PIN1_APP7 = 0x07,
    USIM_PIN1_APP8 = 0x08,    
    USIM_PIN_ADM1 = 0x0A,
    USIM_PIN_ADM2 = 0x0B,
    USIM_PIN_ADM3 = 0x0C,
    USIM_PIN_ADM4 = 0x0D,
    USIM_PIN_ADM5 = 0x0E,
    USIM_PIN_UNIV = 0x11,
    USIM_PIN2_APP1 = 0x81,
    USIM_PIN2_APP2 = 0x82,
    USIM_PIN2_APP3 = 0x83,
    USIM_PIN2_APP4 = 0x84,
    USIM_PIN2_APP5 = 0x85,
    USIM_PIN2_APP6 = 0x86,
    USIM_PIN2_APP7 = 0x87,
    USIM_PIN2_APP8 = 0x88,
    USIM_PIN_ADM6 = 0x8A,
    USIM_PIN_ADM7 = 0x8B,
    USIM_PIN_ADM8 = 0x8C,
    USIM_PIN_ADM9 = 0x8D,
    USIM_PIN_ADM10 = 0x8E
}usim_pin_type_enum;


#if 0
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
#endif /* 0 */

typedef enum {
    USIM_COMMAND_SUCCESS = 0x9000,
    USIM_PROACTIVE_CMD_PENDING = 0x9100, /* 91 XX Group */
    USIM_SAT_BUSY = 0x9300,
    USIM_WARNING_NVM_UNCHANGED = 0x6200,
    USIM_RETURN_DATA_CORRUPTED = 0x6281,
    USIM_EOF_REACHED = 0x6282,
    USIM_SELECTED_FILE_INVALID = 0x6283,
    USIM_SELECTED_DF_TERMINATED = 0x6285,
    USIM_VERIFICATION_FAIL_RETRY_NOT_ALLOWED = 0x63C0,
    USIM_VERIFICATION_FAIL_1_RETRY_ALLOWED = 0x63C1,
    USIM_VERIFICATION_FAIL_2_RETRY_ALLOWED = 0x63C2,
    USIM_VERIFICATION_FAIL_3_RETRY_ALLOWED = 0x63C3,
    USIM_VERIFICATION_FAIL_4_RETRY_ALLOWED = 0x63C4,
    USIM_VERIFICATION_FAIL_5_RETRY_ALLOWED = 0x63C5,
    USIM_VERIFICATION_FAIL_6_RETRY_ALLOWED = 0x63C6,
    USIM_VERIFICATION_FAIL_7_RETRY_ALLOWED = 0x63C7,
    USIM_VERIFICATION_FAIL_8_RETRY_ALLOWED = 0x63C8,
    USIM_VERIFICATION_FAIL_9_RETRY_ALLOWED = 0x63C9,
    USIM_VERIFICATION_FAIL_10_RETRY_ALLOWED = 0x63CA,
    USIM_VERIFICATION_FAIL_11_RETRY_ALLOWED = 0x63CB,
    USIM_VERIFICATION_FAIL_12_RETRY_ALLOWED = 0x63CC,
    USIM_VERIFICATION_FAIL_13_RETRY_ALLOWED = 0x63CD,
    USIM_VERIFICATION_FAIL_14_RETRY_ALLOWED = 0x63CE,
    USIM_VERIFICATION_FAIL_15_RETRY_ALLOWED = 0x63CF,
    USIM_EXECUTION_ERROR_NVM_UNCHANGED = 0x6400,
    USIM_EXECUTION_ERROR_NVM_CHANGED = 0x6500,
    USIM_MEMORY_PROBLEM = 0x6581,
    USIM_WRONG_LENGTH = 0x6700, /* 67 XX Group */
    USIM_WRONG_PARAMETER = 0x6B00,
    USIM_INS_NOT_SUPPORTED = 0x6D00,
    USIM_CLASS_NOT_SUPPORTED = 0x6E00,
    USIM_TECHNICAL_PROBLEM = 0x6F00, /* 6F XX Group */
    USIM_FUNCTIONS_IN_CLA_NOT_SUPPORTED = 0x6800,
    USIM_LOGIC_CHANNEL_NOT_SUPPORTED = 0x6881,
    USIM_SECURE_MESSAGING_NOT_SUPPORTED = 0x6882,
    USIM_CMD_NOT_ALLOW = 0x6900,
    USIM_CMD_INCOMP_FILE_STRUCT = 0x6981,
    USIM_SECURITY_STATUS_NOT_SATISFIED = 0x6982,
    USIM_PIN_BLOCKED = 0x6983,
    USIM_REF_DATA_INVALID = 0x6984,
    USIM_CONDITION_OF_USE_NOT_SATISFIED = 0x6985,
    USIM_CMD_NOT_ALLOW_WITH_NO_EF = 0x6986,
    USIM_INCORRECT_PARA_IN_DATA_FIELD = 0x6A80,
    USIM_FUNCTION_NOT_SUPPORT = 0x6A81,
    USIM_FILE_NOT_FOUND = 0x6A82,
    USIM_RECORD_NOT_FOUND = 0x6A83,
    USIM_INCORRECT_P1_P2 = 0x6A86,
    USIM_INCORRECT_LC = 0x6A87,
    USIM_REF_DATA_NOT_FOUND = 0x6A88,
    USIM_INCREASE_FAIL = 0x9850,
    USIM_AUTH_ERR_INCORRECT_MAC = 0x9862,
    USIM_AUTH_ERR_GSM_SECURITY_NOT_SUPPORTED = 0x9864
} usim_sw_enum;




typedef enum 
{
    MS_NO_MODE,
    UMTS_DUAL_MODE,
    UMTS_ONLY_MODE,
    GSM_ONLY_MODE
} ms_config_enum;

typedef enum
{
    UICC_NOT_INIT,
    NO_SIM_INSIDE,
    SIM_CARD_INSIDE,
    UICC_USIM_INSIDE,
    UICC_SIM_INSIDE
} uicc_card_type_enum;

typedef enum
{
    SFI_NOT_SUPPORT,
    SFI_FILE_ID,
    SFI_PROP_ID
} sfi_usage_enum;

typedef struct 
{
   /* This field gives the actual file id of EF */ 
   usim_file_id_enum           file_id;

   /* This field gives the id of the parent of the EF */ 
   usim_file_index_enum        parent_file_idx;

   /* This field gives the id of the grandparent of the EF */ 
   usim_file_index_enum        grand_parent_file_idx;

   /* This field is used by USIM select by path function */
   kal_uint8                        full_path[6];
}usim_ef_info_struct;

extern const usim_ef_info_struct usim_ef_info[UICC_TOTAL_FILES];

typedef enum {
    USIM_STATUS_NO_IND,
    USIM_STATUS_APP_INIT,
    USIM_STATUS_APP_TERMINAL
} usim_status_opt_enum;

typedef enum {
    USIM_STATUS_FCP,
    USIM_STATUS_DF_NAME,
    USIM_STATUS_NO_RETURN = 0x0C
} usim_status_rsp_enum;
#endif /* __USIM_SUPPORT__ */
#ifndef __USIM_SUPPORT__
typedef enum
{
   NEXT_RECORD     = 0x02,
   PREVIOUS_RECORD = 0x03,
   ABSOLUTE_RECORD = 0x04,
   CURRENT_RECORD  = 0x04
}sim_record_access_mode_enum;
#else /* __USIM_SUPPORT__ */
#define sim_record_access_mode_enum usim_record_access_mode_enum
typedef enum {
    NEXT_RECORD = 0x02,
    PREVIOUS_RECORD = 0x03,
    ABSOLUTE_RECORD = 0x04,
    CURRENT_RECORD = 0x04
} usim_record_access_mode_enum;
#endif /* __USIM_SUPPORT__ */

typedef enum
{
   USIM_FILE_SIZE,
   USIM_REC_NUM,
   USIM_REC_SIZE
}usim_info_type_enum;

typedef enum
{
   SIM1 = 0x00,
   SIM2 = 0x01
}sim_interface_enum;

#endif


