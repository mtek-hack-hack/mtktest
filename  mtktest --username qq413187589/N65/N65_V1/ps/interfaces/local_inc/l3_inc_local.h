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
 * L3_INC_STRUCT.H
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file describes the common enums of L3.
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

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/

#ifndef _L3_INC_LOCAL_H
#define _L3_INC_LOCAL_H


/*****************************************************************************
 * Constant Definitions
 *****************************************************************************/
#define RAC_MAX_NUM_LISTED_PLMNS 32

/*****************************************************************************
 * Type Definitions
 *****************************************************************************/
typedef struct {
    kal_uint8 pfi;
    kal_uint8 epi;
    kal_uint8 contents_len; /* in bytes*/
    kal_uint8 contents[29];
} packet_filter_struct;

typedef struct {
    kal_uint8 tft_op_code;
    kal_uint8 spare;
    kal_uint8 num_packet_filters;
    packet_filter_struct packet_list[8];
} tft_struct;

typedef struct {
    kal_uint16      req_n201u; //erica 20070112
} pdp_auxinfo_struct;


typedef struct {
    kal_uint8 length; /* LENGTH*/
    kal_uint8 digit0; /* DIGIT 0*/
    kal_uint8 odd_or_even; /* ODD OR EVEN*/
    kal_uint8 identity_type; /* IDENTITY TYPE*/
    kal_uint8 digit_byte[7];
} imsi_struct;

typedef struct {
    kal_uint16 bcch_list[8];
} bcchs_struct;


typedef struct {
    kal_uint8 length;
    kal_uint8 digit0;
    kal_uint8 odd_or_even;
    kal_uint8 identity_type;
    kal_uint8 digit_byte[7];
} imei_struct;

#ifndef __MTK_3G_MRAT_ARCH__
typedef struct {
    kal_uint8 mcc2; /* MCC DIGIT2*/
    kal_uint8 mcc1; /* MCC DIGIT1*/
    kal_uint8 mnc3; /* MNC DIGIT3 Always 1111*/
    kal_uint8 mcc3; /* MCC DIGIT3*/
    kal_uint8 mnc2; /* MNC DIGIT2*/
    kal_uint8 mnc1; /* MNC DIGIT1*/
    kal_uint8 la_code[2];
    kal_uint8 ra_code;  /* RA CODE*/
    kal_uint16 cell_id; /* CELL ID*/
} cell_info_struct;
#else
typedef struct {
    kal_uint8 mcc1; /* MCC DIGIT1*/
    kal_uint8 mcc2; /* MCC DIGIT2*/
    kal_uint8 mcc3; /* MCC DIGIT3*/
    kal_uint8 mnc1; /* MNC DIGIT1*/
    kal_uint8 mnc2; /* MNC DIGIT2*/
    kal_uint8 mnc3; /* MNC DIGIT3 Always 1111*/
    kal_uint8 la_code[2];
    kal_uint8 ra_code;  /* RA CODE*/
    kal_uint16 cell_id; /* CELL ID*/
} cell_info_struct;
#endif

#ifdef __MTK_3G_MRAT_ARCH__
typedef struct {
    kal_uint8 mcc1; /* MCC DIGIT1*/
    kal_uint8 mcc2; /* MCC DIGIT2*/
    kal_uint8 mcc3; /* MCC DIGIT3*/
    kal_uint8 mnc1; /* MNC DIGIT1*/
    kal_uint8 mnc2; /* MNC DIGIT2*/
    kal_uint8 mnc3; /* MNC DIGIT3 Always 1111*/
    kal_uint8 la_code[2];
    kal_uint8 ra_code; /* RA CODE*/
    kal_uint16 cell_id; /* CELL ID*/
    kal_uint8 rat;  /* rat_enum */
} cell_info_rat_struct;

typedef struct {
    kal_uint8          plmn_count;
    plmn_id_rat_struct plmn_id_rat[RAC_MAX_NUM_LISTED_PLMNS];
    kal_uint8          status[RAC_MAX_NUM_LISTED_PLMNS];	
} rac_plmn_list_struct;

typedef enum
{
    MS_NULL_STATE = 0,
    MS_READY_STATE,
    MS_STANDBY_STATE,
    MS_FORCED_TO_STANDBY_STATE
}gmm_ms_state_enum;

/* UAS/GAS <-> RATCM begin */
typedef struct {
    plmn_id_struct   plmn_id;
    kal_int8         power_level;
    kal_bool         may_suitable_cell_exist;   
                     //TRUE(1) for suitable cell may exist;
                     //FALSE(0) for no suitable cell exist.
} available_plmn_struct;

typedef struct {
    kal_uint8        plmn_count;
    kal_uint8        high_quality_plmn_count;
    available_plmn_struct available_plmn[MAX_NUM_PLMN_PER_RAT];
} as_plmn_list_struct;

/* UAS/GAS <-> RATCM end */
#endif

#endif 


