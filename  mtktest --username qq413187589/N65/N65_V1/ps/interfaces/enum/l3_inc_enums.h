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
 *   l3_inc_enums.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
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

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/



#ifndef _l3_INC_ENUMS_H
#define _l3_INC_ENUMS_H

#ifdef __MTK_3G_MRAT_ARCH__ 
/* UAS/GAS <-> RATCM begin */
#define MAX_NUM_EQ_PLMN       6
#define MAX_NUM_PLMN_PER_RAT  16
#define MAX_NUM_SEARCH_PLMN   7
#define PS_INVALID_PLMN_SEARCH_TRX_ID 0xff /* Ripple */
/* UAS/GAS <-> RATCM end */

/* Ripple: CB for SMSAL/RATCM/GAS/BMC. */
#define CB_MAX_MSG_CBMI_NUM    60
#define SMSAL_CB_MAX_ENTRY 15
#define CB_MAX_MSG_CBMID_NUM    SMSAL_CB_MAX_ENTRY
#define CB_MAX_MSG_CBMIR_NUM    (SMSAL_CB_MAX_ENTRY*2)
#define CB_MAX_LANG_NUM    SMSAL_CB_MAX_ENTRY
#define CB_MAX_DATA_NUM_PER_PAGE 88

typedef enum
{
    CH_MODE_NONE = 0xff,
    SIGNALLING_ONLY = 0x00,
    SPEECH_FULL_OR_HALF_VER_1 = 0x01,
    SPEECH_FULL_OR_HALF_VER_2 = 0x21,
    SPEECH_FULL_OR_HALF_VER_3 = 0x41, /* is also referred as AMR */
    DATA_43_5_DL_PLUS_14_5_UL = 0x61,
    DATA_29_0_DL_PLUS_14_5_UL = 0x62,
    DATA_43_5_DL_PLUS_29_0_UL = 0x64,
    DATA_14_5_DL_PLUS_43_5_UL = 0x67,
    DATA_14_5_DL_PLUS_29_0_UL = 0x65,
    DATA_29_0_DL_PLUS_43_5_UL = 0x66,
    DATA_43_5_RADIO_INTF_RATE = 0x27,
    DATA_32_0_RADIO_INTF_RATE = 0x63,
    DATA_29_0_RADIO_INTF_RATE = 0x43,
    DATA_14_5_RADIO_INTF_RATE = 0x0f,
    DATA_12_0_RADIO_INTF_RATE = 0x03,
    DATA_06_0_RADIO_INTF_RATE = 0x0b,
    DATA_03_6_RADIO_INTF_RATE = 0x13,

    UMTS_RAB_SPEECH          = 0x70,
    UMTS_RAB_CONVERSATIONAL_DATA,
    UMTS_RAB_STREAMING_DATA,
    UMTS_RAB_NON_DECIDED,
    UMTS_RAB_UNSPECIFIED= 0xff
} channel_mode_enum;
#endif

typedef enum {
    SUBSCRIBED_PTC = 0,
    RESERVED_NW_TO_MS_PTC = 0,
    PTC_1,
    PTC_2,
    PTC_3,
    PTC_4,
    PTC_5,
    PTC_6,
    PTC_7,
    PTC_8,
    PTC_9,
    RESERVED_BIDIRECT_PTC = 15
} peak_throughput_class;

typedef enum {
    RADIO_PRIORITY_1 = 1,
    RADIO_PRIORITY_2,
    RADIO_PRIORITY_3,
    RADIO_PRIORITY_4
} rp_enum;

typedef enum {
    RP_1,
    RP_2,
    RP_3,
    RP_4
} radio_priority;

typedef enum {
    RLC_SUSPEND,
    RLC_RESUME,
    RLC_FAILED,
    RLC_RECEIVE_NOT_READY,
    RLC_RECEIVE_READY
} grr_cause_enum;

typedef enum {
    SUBSCRIBED_DELAY_CLASS = 0,
    RESERVED_NW_TO_MS_DELAY_CLASS = 0,
    DELAY_CLASS1,
    DELAY_CLASS2,
    DELAY_CLASS3,
    DELAY_CLASS4,
    RESERVED_BIDIRECT_DELAY_CLASS = 7,
    TOT_DELAY_CLASS = 8
} delay_class_enum;

typedef enum {
    SUBSCRIBED_REL_CLASS = 0,
    RESERVED_NW_TO_MS_REL_CLASS  = 0,
    REL_CLASS1,
    REL_CLASS2,
    REL_CLASS3,
    REL_CLASS4,
    REL_CLASS5,
    RESERVED_BIDIRECT_REL_CLASS = 7
} reliability_class_enum;

typedef enum {
    SUBSCRIBED_PREC_CLASS = 0,
    RESERVED_NW_TO_MS_PREC_CLASS  = 0,
    PREC_CLASS1,
    PREC_CLASS2,
    PREC_CLASS3,
    RESERVED_BIDIRECT_PREC_CLASS = 7
} precedence_class_enum;

typedef enum {
    SUBSCRIBED_MEAN_THROUGHPUT = 0,
    RESERVED_NW_TO_MS_MEAN_THROUGHPUT = 0,
    MEAN_THROUGHPUT1,
    MEAN_THROUGHPUT2,
    MEAN_THROUGHPUT3,
    MEAN_THROUGHPUT4,
    MEAN_THROUGHPUT5,
    MEAN_THROUGHPUT6,
    MEAN_THROUGHPUT7,
    MEAN_THROUGHPUT8,
    MEAN_THROUGHPUT9,
    MEAN_THROUGHPUT10,
    MEAN_THROUGHPUT11,
    MEAN_THROUGHPUT12,
    MEAN_THROUGHPUT13,
    MEAN_THROUGHPUT14,
    MEAN_THROUGHPUT15,
    MEAN_THROUGHPUT16,
    MEAN_THROUGHPUT17,
    MEAN_THROUGHPUT18,
    RESERVED_BIDIRECT_MEAN_THROUGHPUT = 30,
    BEST_EFFORT_THROUGHPUT = 31
} mean_throughput_enum;

typedef enum {
    SUBSCRIBED_TRAFFIC_CLASS = 0,
    RESERVED_NW_TO_MS_TRAFFIC_CLASS = 0,
    CONVERSATIONAL_CLASS,
    TRAFFIC_CLASS1 = CONVERSATIONAL_CLASS,
    STREAMING_CLASS,
    TRAFFIC_CLASS2 = STREAMING_CLASS,
    INTERACTIVE_CLASS,
    TRAFFIC_CLASS3 = INTERACTIVE_CLASS,
    BACKGROUND_CLASS,
    TRAFFIC_CLASS4 = BACKGROUND_CLASS,
    RESERVED_BIDIRECT_TRAFFIC_CLASS = 7
} traffic_class_enum;

typedef enum {
    SUBSCRIBED_DELIVERY_ORDER = 0,
    RESERVED_NW_TO_MS_DELIVERY_ORDER = 0,
    DELIVERY_ORDER1,
    DELIVERY_ORDER2,
    RESERVED_BIDIRECT_DELIVERY_ORDER = 3
} delivery_order_enum;

typedef enum {
    SUBSCRIBED_DELIVERY_OF_ERR_SDU= 0,
    RESERVED_NW_TO_MS_DELIVERY_OF_ERR_SDU = 0,
    DELIVERY_OF_ERR_SDU1,
    DELIVERY_OF_ERR_SDU2,
    DELIVERY_OF_ERR_SDU3,
    RESERVED_BIDIRECT_DELIVERY_OF_ERR_SDU = 7
} delivery_of_err_sdu_enum;


typedef enum {
    SUBSCRIBED_BIT_ERROR_RATE = 0,
    RESERVED_NW_TO_MS_BIT_ERROR_RATE = 0,
    BIT_ERROR_RATE1,
    BIT_ERROR_RATE2,
    BIT_ERROR_RATE3,
    BIT_ERROR_RATE4,
    BIT_ERROR_RATE5,
    BIT_ERROR_RATE6,
    BIT_ERROR_RATE7,
    BIT_ERROR_RATE8,
    BIT_ERROR_RATE9,
    RESERVED_BIDIRECT_BIT_ERROR_RATE = 15
} residual_bit_error_rate_enum;

typedef enum {
    SUBSCRIBED_SDU_ERR_RATIO = 0,
    RESERVED_NW_TO_MS_SDU_ERR_RATIO = 0,
    SDU_ERR_RATIO1,
    SDU_ERR_RATIO2,
    SDU_ERR_RATIO3,
    SDU_ERR_RATIO4,
    SDU_ERR_RATIO5,
    SDU_ERR_RATIO6,
    SDU_ERR_RATIO7,
    RESERVED_BIDIRECT_SDU_ERR_RATIO = 15
} sdu_err_ratio_enum;

typedef enum {
    SUBSCRIBED_TRAFFIC_HNDL_PRIORITY = 0,
    RESERVED_NW_TO_MS_TRAFFIC_HNDL_PRIORITY = 0,
    TRAFFIC_HNDL_PRIORITY1,
    TRAFFIC_HNDL_PRIORITY2,
    TRAFFIC_HNDL_PRIORITY3
} traffic_hndl_priority_enum;

typedef enum
{
  CS_DOMAIN    = 0,
  PS_DOMAIN    = 1,
  CS_PS_DOMAIN = 2,
  DOMAIN_NONE  = 3
} domain_id_enum;

typedef enum
{
    MANUAL_MODE    = 0,
    AUTOMATIC_MODE = 1
} plmn_selection_mode_enum;

typedef enum
{
    MANUAL_RESELECTION = 0,
    AUTO_RESELECTION   = 1
} plmn_reselection_enum;

typedef enum
{
    GSM_BAND_START  = 0,
    GSM_BAND_P = GSM_BAND_START,
    GSM_BAND_E      = 1,
    GSM_BAND_R      = 2,
    GSM_BAND_1800   = 3,
    GSM_BAND_1900   = 4,
    GSM_BAND_450    = 5,
    GSM_BAND_480    = 6,
    GSM_BAND_850    = 7, 
    MAX_GSM_BANDS   = 8,
    UMTS_BAND_START = 9,
    UMTS_BAND       = UMTS_BAND_START,
    INVALID_BAND    = 0xff
}access_technology_type_enum;

#ifdef __MTK_3G_MRAT_ARCH__
typedef enum
{
    PLMN_STATUS_NONE      = 0,
    PLMN_STATUS_AVAILABLE = 1,
    PLMN_STATUS_CURRENT   = 2,
    PLMN_STATUS_FORBIDDEN = 3    
} plmn_status_enum;

typedef enum{
    GAS_EMERGENCY_CALL        = 0,
    GAS_REGISTRATION          = 1,
    GAS_DETACH                = 2,
    GAS_LOW_PRIORITY_SIG      = 3,
    GAS_CALL_RE_ESTABLISHMENT = 4,
    GAS_SPEECH_CALL           = 5,
    GAS_DATA_CALL             = 6,
    GAS_PAGE_RESP             = 7,
    GAS_SS_DATA               = 8
}gas_est_cause_enum;
#endif

/* Used for giving paging cause to MM and estab. cause to AS. Also
 * used upto application */
typedef enum
{
    ORIG_CONVER_CALL            = 0,
    ORIG_STREAMING_CALL         = 1,
    ORIG_INTERACTIVE_CALL       = 2,
    ORIG_BACKGROUND_CALL        = 3,
    ORIG_SUBSCRIBED_CALL        = 4,
    TERM_CONVER_CALL            = 5,
    TERM_STREAMING_CALL         = 6,
    TERM_INTERACTIVE_CALL       = 7,
    TERM_BACKGROUND_CALL        = 8,
    EMERGENCY_CALL              = 9,
    INTER_RAT_CELL_RESELECTION  = 10,
    INTER_RAT_CELL_CHANGE_ORDER = 11,
    REGISTRATION                = 12,
    DETACH                      = 13,
    HIGH_PRIORITY_SIG           = 14,
    LOW_PRIORITY_SIG            = 15,
    CALL_RE_ESTABLISHMENT       = 16,
    SPEECH_CALL                 = 17,
    DATA_CALL                   = 18,
    LOC_UPDATE                  = 19,
    SMS_DATA                    = 20,
    TCHF_OR_SDCCH_NEEDED        = 21,
    PAGE_RESP                   = 22,
    MEAS_REPORT                 = 23,
    IMSI_DETACH_PROC            = 24,
    MM_PROC                     = 25,
    SS_DATA                     = 26
} est_cause_enum;

typedef enum {
    CAUSE_NONE                     =     0x00,
    IMSI_UNKNOWN_IN_HLR            =     0x02,
    ILLEGAL_MS                     =     0x03,
    IMSI_UNKNOWN_IN_VLR            =     0x04,
    IMEI_NOT_ACCEPTED              =     0x05,
    ILLEGAL_ME                     =     0x06,
    GPRS_NOT_ALLOWED               =     0x07,
    GPRS_NON_GPRS_NOT_ALLOWED      =     0x08,
    MS_ID_NOT_DERIVED_BY_NW        =     0x09,
    IMPLICIT_DETACH                =     0x0a,
    PLMN_NOT_ALLOWED               =     0x0b,
    LOCATION_AREA_NOT_ALLOWED      =     0x0c,
    ROAMING_AREA_NOT_ALLOWED       =     0x0d,
    GPRS_NOT_ALLOWED_IN_PLMN       =     0x0e,
    NO_SUITABLE_CELLS_IN_LA        =     0x0f,
    MSC_TEMP_NOT_REACHABLE         =     0x10,
    NETWORK_FAILURE                =     0x11,
    MAC_FAILURE                    =     0x14,
    SYNC_FAILURE                   =     0x15,
    CONGESTION                     =     0x16,
    GSM_AUTHEN_UNACCEPTABLE        =     0x17,
    SERV_OPTION_NOT_SUPPORTED      =     0x20,
    REQ_SERV_OPTION_NOT_SUBSCRIBED =     0x21,
    SERV_OPTION_TEMP_OUT_OF_ORDER  =     0x22,
    CALL_CANNOT_BE_IDENTIFIED      =     0x26,
    NO_PDP_CONTEXT_ACTIVATED       =     0x28,
    
    RETRY_UPON_ENTRY_INTO_NEWCELL_MIN =  0x30,  /* 30..3f */
    RETRY_UPON_ENTRY_INTO_NEWCELL_MAX =  0x3f,
    
    SEMANTICALLY_INCORRECT_MSG        =  0x5f,
    INVALID_MM_MAND_INFO              =  0x60,
    MSG_TYPE_NON_EXISTENT             =  0x61,
    MSG_TYPE_NOT_IMPLEMENTED          =  0x61,
    MSG_TYPE_INCOMPAT_WITH_PROTO_STATE = 0x62,
    IE_NOT_IMPLEMENTED                 = 0x63,
    CONDITIONAL_MM_IE_ERROR            = 0x64,
    MSG_NOT_COMPAT_WITH_PROTO_STATE    = 0x65,  /* 65..6f */
    PROTO_ERROR_UNSPECIFIED            = 0x6f,
    /* Incase if any more standard cause values are to be added then
     * the cause having the greatest value should be placed just before
     * the internal cause values.
     */
    /* The following cause are internal to Tcm and Gmm */
    FORBIDDEN_PLMN, /* 0x70 */
    ACCESS_CLASS_BARRED,
    NO_COVERAGE,
    GPRS_SERV_NOT_ALLOWED,
    TIMER_EXPIRY,
    SIM_INSERTED,
    SIM_REMOVED,
    SIM_ABSENT,
    SIM_INVALID_FOR_PS,
    SIM_INVALID_FOR_CS,
    SIM_INVALID_FOR_CS_AND_PS,
    LOW_LAYER_FAIL,
    MM_CONN_IN_PROGRESS, /* 0x7c */
    MM_NOT_UPDATED,
    RR_CONN_ESTAB_FAILURE,
    RRC_CONN_ABORT, /* 0x7f */
    MM_CONN_FAILURE, /* 0x80 */
    MM_EMERGENCY_NOT_ALLOWED,
    NO_GPRS_COVERAGE,
    MM_ABNORMAL_LU,
    MM_ABNORMAL_LU_LESS_THEN_4_TIMES,
    #ifdef __MTK_3G_MRAT_ARCH__ 
    MM_DO_NOT_NEED_PLMN_SEARCH,
    #endif
    MM_SAME_LAI_IMSI_ATTACHING //erica tier one
    #ifdef __GEMINI__
    , MM_REJ_CUZ_RR_IN_SUSPEND_MODE /* for ATTACH_REJ *///0x86
    #endif
}mm_cause_enum;

typedef enum
{
    isABSENT = 0,
    isPRESENT = 1
}isPresent_enum;

typedef enum
{
    is_absent = 0,
    is_present = 1
}is_present_enum;

typedef enum
{
    CS_SERVICE = 0,
    PS_SERVICE,
    CS_PS_SERVICE,
    NONE_SERVICE
}mm_user_regn_type_enum;

typedef enum
{
    CS_SERVICE_DETACH = 0,
    PS_SERVICE_DETACH,
    CS_PS_SERVICE_DETACH
}mm_user_srv_detach_enum;

typedef enum
{
   MMI_SEARCH_ANY,
   MMI_SEARCH_NORMAL
} mm_user_search_type_enum;

#define MAX_VAL(VAL_A, VAL_B)   (((VAL_A) > (VAL_B)) ? (VAL_A):(VAL_B))

/* Lanslo 20060621: modify type size for VC simulator environment */
#ifdef __R99__
   #ifdef __MTK_TARGET__ 
       /*Simon20060830 for FLC2 free, add nsapi*/
       #ifdef __FLC2__
          #define RLC_UL_CTRL_HEADER_LENGTH 11 
       #else
       #define RLC_UL_CTRL_HEADER_LENGTH 10  //sizeof rlc_peer_data_info_struct
       #endif
   #else
       #ifdef __FLC2__
         #define RLC_UL_CTRL_HEADER_LENGTH 32
   #else
       #define RLC_UL_CTRL_HEADER_LENGTH 28  //sizeof rlc_peer_data_info_struct
   #endif 
   #endif 
#else
   #ifdef __MTK_TARGET__
       #ifdef __FLC2__
         #define RLC_UL_CTRL_HEADER_LENGTH 10  //sizeof rlc_peer_data_info_struct
       #else
         #define RLC_UL_CTRL_HEADER_LENGTH 9  
       #endif
   #else
       #ifdef __FLC2__
          #define RLC_UL_CTRL_HEADER_LENGTH 32  //sizeof rlc_peer_data_info_struct
       #else
          #define RLC_UL_CTRL_HEADER_LENGTH 28
       #endif
   #endif   	   
#endif
/* eo Lanslo 20060621 */

#define RLC_DL_CTRL_HEADER_LENGTH 3 //sizeof rlc_dl_blk_struct
/* Claire 041116 change : Adapt EGPRS DL interface */
#ifdef __EGPRS_MODE__
#define RLC_DL_EGPRS_CTRL_HEADER_LENGTH 3 //sizeof rlc_dl_egprs_blk_struct
#endif

/* 20060501 mtk00714 change the define value from 16 to 20  */
#ifndef __MTK_3G_MRAT_ARCH__
#define SND_UL_CTRL_HEADER_LENGTH 20  //The size of max(snd_nsapi_ack_tx_buff_struct,snd_nsapi_unack_tx_buff_struct). Reserve by PPP.
#else
#define SND_UL_CTRL_HEADER_LENGTH 16  //The size of max(snd_nsapi_ack_tx_buff_struct,snd_nsapi_unack_tx_buff_struct). Reserve by PPP.
#endif

#define SND_DL_CTRL_HEADER_LENGTH 12  //The size of snd_nsapi_dl_snpdu_buff_struct
#define LLC_HEADER_LENGTH   5
#define LLC_TAIL_LENGTH     3

//The size of (24, llsnd_unitdata_req_struct, llsnd_data_req_struct, LLC_HEADER_LENGTH+RLC_UL_CTRL_HEADER_LENGTH)
/* #define SND_UL_FREE_HEADER_LENGTH 24  */
#define SND_UL_FREE_HEADER_LENGTH MAX_VAL(24, (LLC_HEADER_LENGTH+RLC_UL_CTRL_HEADER_LENGTH)) 

/* Jeff Wu 2006-05-22: The size of ratdm_ps_data_req_struct - peer_buff_struct */
#ifdef __MTK_3G_MRAT_ARCH__ 
#define RATDM_UL_CTRL_RESERVED_HEADER_SPACE 0x08
#endif

typedef enum
{
    LLC_SAPI_NOT_ASSIGNED = 0,
    LLC_SAPI1  =  1,
    LLC_SAPI2  =  2,
    LLC_SAPI3  =  3,
    LLC_SAPI5  =  5,
    LLC_SAPI7  =  7,
    LLC_SAPI8  =  8,
    LLC_SAPI9  =  9,
    LLC_SAPI11 =  11
}llc_sapi_enum;

typedef enum {
    SUBSCRIBED_TRANSFER_DELAY = 0,
    RESERVED_NW_TO_MS_TRANSFER_DELAY   = 0,   
    TRANSFER_DELAY1 = 1,
    TRANSFER_DELAY2 = 15,
    TRANSFER_DELAY3 = 16,
    TRANSFER_DELAY4 = 31,
    TRANSFER_DELAY5 = 32,
    TRANSFER_DELAY6 = 62,
    RESERVED_BIDIRECT_TRANSFER_DELAY = 63 
} transfer_delay_enum;

typedef enum {
    RESERVED_NW_TO_MS_MAX_SDU_SIZE   = 0,
    SUBSCRIBED_MS_TO_NW_MAX_SDU_SIZE = 0,
    SDU_SIZE_1502_OCTETS             = 151,
    SDU_SIZE_1510_OCTETS             = 152,
    SDU_SIZE_1520_OCTETS             = 152,
    RESERVED_BIDIRECT_MAX_SDU_SIZE = 255
} max_sdu_size_enum;

typedef enum {
    SUBSCRIBED_MAX_BIT_RATE_UPLINK = 0,
    RESERVED_NW_TO_MS_MAX_BIT_RATE_UPLINK = 0,
    MAX_BIT_RATE_UPLINK1 = 1,
    MAX_BIT_RATE_UPLINK2 = 63,
    MAX_BIT_RATE_UPLINK3 = 64,
    MAX_BIT_RATE_UPLINK4 = 127,
    MAX_BIT_RATE_UPLINK5 = 128,
    MAX_BIT_RATE_UPLINK6 = 254,
    MAX_BIT_RATE_UPLINK_ZERO = 255		  // erica __SM_3G__
    //RESERVED_BIDIRECT_MAX_BIT_RATE_UPLINK = 255 // meaning is changed in R99 according to 24.008
} max_bit_rate_uplink_enum;

typedef enum {
    SUBSCRIBED_MAX_BIT_RATE_DOWNLINK= 0,
    RESERVED_NW_TO_MS_MAX_BIT_RATE_DOWNLINK = 0,
    MAX_BIT_RATE_DOWNLINK1 = 1,
    MAX_BIT_RATE_DOWNLINK2 = 63,
    MAX_BIT_RATE_DOWNLINK3 = 64,
    MAX_BIT_RATE_DOWNLINK4 = 127,
    MAX_BIT_RATE_DOWNLINK5 = 128,
    MAX_BIT_RATE_DOWNLINK6 = 254,
    MAX_BIT_RATE_DOWNLINK_ZERO = 255	           // erica __SM_3G__
    //RESERVED_BIDIRECT_MAX_BIT_RATE_DOWNLINK= 255 // meaning is changed in R99 according to 24.008
} max_bit_rate_downlink_enum;

typedef enum {
    SUBSCRIBED_GUARANTD_BIT_RATE_UPLINK = 0,
    RESERVED_NW_TO_MS_GUARANTD_BIT_RATE_UPLINK = 0,
    GUARANTD_BIT_RATE_UPLINK1 = 1,
    GUARANTD_BIT_RATE_UPLINK2 = 63,
    GUARANTD_BIT_RATE_UPLINK3 = 64,
    GUARANTD_BIT_RATE_UPLINK4 = 127,
    GUARANTD_BIT_RATE_UPLINK5 = 128,
    GUARANTD_BIT_RATE_UPLINK6 = 254,
    RESERVED_BIDIRECT_GUARANTD_BIT_RATE_UPLINK = 255
} guarantd_bit_rate_uplink_enum;

typedef enum {
    SUBSCRIBED_GUARANTD_BIT_RATE_DOWNLINK= 0,
    RESERVED_NW_TO_MS_GUARANTD_BIT_RATE_DOWNLINK = 0,
    GUARANTD_BIT_RATE_DOWNLINK1 = 1,
    GUARANTD_BIT_RATE_DOWNLINK2 = 63,
    GUARANTD_BIT_RATE_DOWNLINK3 = 64,
    GUARANTD_BIT_RATE_DOWNLINK4 = 127,
    GUARANTD_BIT_RATE_DOWNLINK5 = 128,
    GUARANTD_BIT_RATE_DOWNLINK6 = 254,
    RESERVED_BIDIRECT_GUARANTD_BIT_RATE_DOWNLINK= 255
} guarantd_bit_rate_downlink_enum;

typedef enum {
/* ============================== CM cause ============================== */	
   CM_RADIO_LINK_FAIL = 0, /* Ripple: add for SAT3 use. sec 11.3.2, spec.. 11.14 */
// 3GPP 24.008 clause 10.5.4.11(Annex H) CC+SS cause value
// 3GPP 24.011 clause 8.2.5.4 SMS RP cause value
// 3GPP 24.011 clause 8.1.4.2 SMS CP cause value
// Class(000): 0-15 -> normal event             CC+SS    SMS
   CM_UNASSIGNED_NUM                     = 1,  // X       X
   CM_NO_ROUTE_TO_DESTINATION            = 3,  // X
   CM_CHANNEL_UN_ACCP                    = 6,  // X
   CM_OPR_DTR_BARRING                    = 8,  // X       X
   CM_CALL_BARRED                        = 10, //         X
   CM_RESERVED                           = 11, //         X
// Class(001): 16-31 -> normal event
   CM_NORMAL_CALL_CLR                    = 16, // X
   CM_USER_BUSY                          = 17, // X       X! (SMS: nwk failure)
   CM_NO_USER_RESPONDING                 = 18, // X
   CM_NO_ANSWER_ON_ALERT                 = 19, // X
   CM_CALL_REJECTED                      = 21, // X       X
   CM_NUMBER_CHANGED                     = 22, // X       X! (SMS: congestion)
   CM_PRE_EMPTION                        = 25, // X
   CM_NON_SEL_USER_CLEAR                 = 26, // X
   CM_DEST_OUT_OF_ORDER                  = 27, // X       X
   CM_INVALID_NUMBER_FORMAT              = 28, // X       X
   CM_FACILITY_REJECT                    = 29, // X       X
   CM_RES_STATUS_ENQ                     = 30, // X       X! (SMS:Unknown_Sub)
   CM_NORMAL_UNSPECIFIED                 = 31, // X
// Class(010): 32-48 -> resource unavailable
   CM_NO_CIRCUIT_CHANNEL_AVAIL           = 34, // X
   CM_NETWORK_OUT_OF_ORDER               = 38, // X       X
   CM_TEMPORARY_FAILURE                  = 41, // X       X
   CM_SWITCH_EQUIPMENT_CONGESTION        = 42, // X       X
   CM_ACCESS_INFO_DISCARDED              = 43, // X
   CM_REQUESTED_CKT_CHANEL_NOT_AVIL      = 44, // X
   CM_RESOURCE_UNAVAIL_UNSPECIFIED       = 47, // X       X
// Class(011): 49-64 -> service or option not available
   CM_QOS_UNAVAIL                        = 49, // X
   CM_REQ_FAC_NOT_SUBS                   = 50, // X       X
   CM_IC_BAR_CUG                         = 55, // X
   CM_BEARER_CAP_NOT_AUTHORISED          = 57, // X
   CM_BEARER_CAP_NOT_AVAIL               = 58, // X
   CM_SER_UNAVAILABLE                    = 63, // X
// Class(100): 65-80 -> service or option not implementated
   CM_BEARER_SER_UNIMPL                  = 65, // X
   CM_ACM_EXCEEDED                       = 68, // X
   CM_REQ_FACILITY_UNAVAIL               = 69, // X       X
   CM_RESTR_DIGITAL_INFO                 = 70, // X
   CM_SER_OPT_UNIMPL                     = 79, // X
// Class(101): 81-95 -> invalid message
   CM_INVALID_TI_VALUE                   = 81, // X       X
   CM_USER_NOT_IN_CUG                    = 87, // X
   CM_INCOMPATIBLE_DEST                  = 88, // X
   CM_INVALID_TRANSIT_NW_SEL             = 91, // X
   CM_SEMANTIC_ERR                       = 95, // X       X
// Class(110): 96-112 -> protocol error
   CM_INVALID_MANDATORY_INF              = 96, // X       X
   CM_MSG_TYPE_UNIMPL                    = 97, // X       X
   CM_MSG_TYPE_NOT_COMPATIBLE            = 98, // X       X
   CM_IE_NON_EX                          = 99, // X       X
   CM_COND_IE_ERR                       = 100, // X
   CM_INCOMP_MESG_WITH_STATE            = 101, // X
   CM_RECOVERY_ON_TIMER_EXPIRY          = 102, // X
   CM_PROTOCOL_ERR_UNSPECIFIED          = 111, // X       X
// Class(111): 113-127 -> interworking
   CM_INTER_WRK_UNSPECIFIED             = 127, // X       X
/* ============================== ~CM cause ============================== */

/* ============================== SMS cause ============================== */
// 3GPP 23.040 clause 9.2.3.22 SMS TP cause values
// 128-255 -> SMS cause value
      
   /* PID error */   
   TELEMATIC_INT_WRK_NOT_SUPPORT = 0x80, /* telematic interworking not support */
   SMS_TYPE0_NOT_SUPPORT         = 0x81, /* short message type 0 not support */
   CANNOT_REPLACE_MSG            = 0x82, 
   UNSPECIFIED_PID_ERROR         = 0x8F, 
   
   /* DCS error */
   ALPHABET_NOT_SUPPORT          = 0x90, /* data coding scheme (alphabet) not support */
   MSG_CLASS_NOT_SUPPORT         = 0x91, /* message class not support */
   UNSPECIFIED_TP_DCS            = 0x9f,

   /* Command error */
   CMD_CANNOT_ACTION             = 0xa0, /* command cannot be actioned */
   CMD_NOT_SUPPORT               = 0xa1, /* command unsupported */
   UNSPECIFIED_CMD_ERROR         = 0xaf, 
   
   TPDU_NOT_SUPPORT              = 0xb0,   
   SC_BUSY                       = 0xc0,
   NO_SC_SUBSCRIPTION            = 0xc1,
   SC_SYS_FAILURE                = 0xc2,  /* SC system failure */
   INVALID_SME_ADDR              = 0xc3,  
   DEST_SME_BARRED               = 0xc4,  /* destination SME barred */
   SM_REJ_DUP_SM                 = 0xc5,  /* SM rejected-duplicate SM */
   TP_VPF_NOT_SUPPORT            = 0xc6,
   TP_VP_NOT_SUPPORT             = 0xc7,
      
   SIM_STORAGE_FULL              = 0xd0,
   NO_SMS_STO_IN_SIM             = 0xd1,  /* No SMS storage capability in SIM */
   ERROR_IN_MS                   = 0xd2, 
   MEM_CAP_EXCEEDED              = 0xd3,  /* Memory Capacity Exceeded */
   
   /* SIM Application Toolkit */
   SMS_SAT_BUSY                  = 0xd4,  /* SIM Application Toolkit Busy */
   SMS_SAT_DL_ERROR              = 0xd5,  /* SIM data download error */
   
   /* 0XE0 to 0xFE are specific to application */
   SMS_CP_RETRY_EXCEED           = 0xe0,
   SMS_RP_TR1M_TIMEOUT           = 0xe1,
   SMS_CONNECTION_BROKEN         = 0xe2,
   
   UNSPECIFIED_TP_FCS            = 0xff,

// 3GPP 27.005 clause 3.2.5 SMS ATcmd cause values
// 256-511 -> SMS AT command cause value
   INVALID_PDU_MODE_PARA  = 304,   /* invalid pdu mode parameter */
   INVALID_TEXT_MODE_PARA = 305,   /* invalid text mode parameter */
   SMS_SIM_FAILURE        = 313,   /* sim failure */
   MEM_FAILURE	          = 320,   /* memory failure */
   INVALID_MEM_INDEX	  = 321,   /* invalid memory index */
   MEM_FULL	          = 322,   /* memory full */
   SCA_UNKNOWN	          = 330,   /* SMSC address unknown */
   NO_CNMA_EXPECTED       = 340,   /* no +CNMA acknowledgement expected */
   SMSAL_UNSPECIFIED_ERROR_CAUSE = 500,
   
// 512-767 -> SMS proprietary cause values
   SMSAL_NO_ERROR             = 512,
   MSG_LEN_EXCEEDED           = 513,   /* message length exceeds 
                                          maximum length */
   INVALID_REQ_PARAMETER      = 514,   /* invalid request parameters */
   SMS_ME_STORAGE_FAILURE     = 515,   /* ME storage failure */
   SMSAL_INVALID_BEARER       = 516,   /* Invalid bearer service */
   SMSAL_INVALID_SERVICE_MODE = 517,   /* Invalid service mode */
   SMSAL_INVALID_STORAGE_TYPE = 518,   /* Invalid storage type */
   SMSAL_INVALID_MSG_FORMAT   = 519,   /* Invalid message format */
   TOO_MANY_MO_CONCAT_MSG     = 520,   /* Too many MO concatenated messages */
   SMSAL_NOT_READY            = 521,
   SMSAL_NO_MO_SERVICE        = 522,
   NOT_SUPP_SR_CMD_IN_STORAGE = 523,   /* not support TP-Status-Report & TP-Command in storage */   
   SMSAL_NOT_SUPPORT_MSG_TYPE = 524,   /* Reserved MTI */
   SMS_RL_NO_FREE_ENTITY      = 525,   /* no free entity in RL layer */
   SMS_PORT_NUM_ALREADY_REG   = 526,   /* The port number is already registerred */
   SMS_PORT_NUM_NO_FREE_ENTITY= 527,   /* There is no free entity for port number */
   SMS_RL_MMS_STATE_ERR       = 528,   /* More Message to Send state error */
   SMS_MO_SMS_NOT_ALLOW       = 529,   /* MO SMS is not allow */
   SMS_PS_SUSPENDED           = 530,   /* GPRS is suspended */
   SMS_ME_STORAGE_FULL        = 531,   /* ME storage full */
   SMS_SIM_REFRESHING         = 532,   /* doing SIM refresh */
/* ============================== ~SMS cause ============================== */
   
/* ============================== CC cause ============================== */   
// 768-1023 -> CC proprietary cause values
	CSMCC_CMD_NOT_ALLOW = 768,
	CSMCC_ILLEGAL_CALL_ID,
	CSMCC_CALL_ALLOC_FAIL,
	CSMCC_BC_FILL_FAIL,
	CSMCC_CALL_RE_EST,
	CSMCC_ILLEGAL_DTMF_TONE,
	CSMCC_ILLEGAL_BC,
	CSMCC_MODIFY_ACTUAL_MODE,   
	CSMCC_DATA_ACT_FAIL,
	CSMCC_NO_RESPONSE_FROM_NW,
	CSMCC_CALL_ACCEPT_NOT_ALLOW,

   CM_L4C_GEN_CAUSE = 896,
   CM_L4C_CC_CALL_ABORT = 897,  /*CSD call is aborted by user during call establishment
   				or MT call abort MO call/USSD*/
   CM_L4C_CC_CALL_DISC_IND = 898,  /*CSD call is disconnected due to lower layer failure*/
/* ============================== ~CC cause ============================== */
   
/* ============================== SS cause ============================== */   
// 1024-1279 -> SS proprietary cause values
// 3GPP 23.080 clause 4.3 SS Error Types
   CM_SS_ERR_START                                = 1024,
   CM_SS_ERR_UNKNOWNSUBSCRIBER                    =   1 + CM_SS_ERR_START,
   CM_SS_ERR_ILLEGALSUBSCRIBER                    =   9 + CM_SS_ERR_START,
   CM_SS_ERR_BEARERSERVICENOTPROVISIONED          =  10 + CM_SS_ERR_START,
   CM_SS_ERR_TELESERVICENOTPROVISIONED            =  11 + CM_SS_ERR_START,
   CM_SS_ERR_ILLEGALEQUIPMENT                     =  12 + CM_SS_ERR_START,
   CM_SS_ERR_CALLBARRED                           =  13 + CM_SS_ERR_START,
   CM_SS_ERR_ILLEGALSS_OPERATION                  =  16 + CM_SS_ERR_START,
   CM_SS_ERR_SS_ERRORSTATUS                       =  17 + CM_SS_ERR_START,
   CM_SS_ERR_SS_NOTAVAILABLE                      =  18 + CM_SS_ERR_START,
   CM_SS_ERR_SS_SUBSCRIPTIONVIOLATION             =  19 + CM_SS_ERR_START,
   CM_SS_ERR_SS_INCOMPABILITY                     =  20 + CM_SS_ERR_START,
   CM_SS_ERR_FACILITYNOTSUPPORTED                 =  21 + CM_SS_ERR_START,
   CM_SS_ERR_ABSENTSUBSCRIBER                     =  27 + CM_SS_ERR_START,
   CM_SS_ERR_SHORTTERMDENIAL                      =  29 + CM_SS_ERR_START,
   CM_SS_ERR_LONGTERMDENIAL                       =  30 + CM_SS_ERR_START,
   CM_SS_ERR_SYSTEMFAILURE                        =  34 + CM_SS_ERR_START,
   CM_SS_ERR_DATAMISSING                          =  35 + CM_SS_ERR_START,
   CM_SS_ERR_UNEXPECTEDDATAVALUE                  =  36 + CM_SS_ERR_START,
   CM_SS_ERR_PW_REGISTRATIONFAILURE               =  37 + CM_SS_ERR_START,
   CM_SS_ERR_NEGATIVEPW_CHECK                     =  38 + CM_SS_ERR_START,
   CM_SS_ERR_NUMBEROFPW_ATTEMPTSVIOLATION         =  43 + CM_SS_ERR_START,
   CM_SS_ERR_POSITIONMETHODFAILURE                =  54 + CM_SS_ERR_START,
   CM_SS_ERR_UNKNOWNALPHABET                      =  71 + CM_SS_ERR_START,
   CM_SS_ERR_USSD_BUSY                            =  72 + CM_SS_ERR_START,
   CM_SS_ERR_REJECTEDBYUSER                       = 121 + CM_SS_ERR_START,
   CM_SS_ERR_REJECTEDBYNETWORK                    = 122 + CM_SS_ERR_START,
   CM_SS_ERR_DEFLECTIONTOSERVEDSUBSCRIBER         = 123 + CM_SS_ERR_START,
   CM_SS_ERR_SPECIALSERVICECODE                   = 124 + CM_SS_ERR_START,
   CM_SS_ERR_INVALIDDEFLECTIONTONUMBER            = 125 + CM_SS_ERR_START,
   CM_SS_ERR_MAXNUMBEROFMPTY_PARTICIPANTSEXCEEDED = 126 + CM_SS_ERR_START,
   CM_SS_ERR_RESOURCESNOTAVAILABLE                = 127 + CM_SS_ERR_START,

   CM_SS_GENERALPROBLEM_START                     = 1152,
   CM_SS_GENERALPROBLEM_UNRECOGNIZEDCOMPONENT     =       CM_SS_GENERALPROBLEM_START,
   CM_SS_GENERALPROBLEM_MISTYPEDCOMPONENT         = 1   + CM_SS_GENERALPROBLEM_START,
   CM_SS_GENERALPROBLEM_BADLYSTRUCTUREDCOMPONENT  = 2   + CM_SS_GENERALPROBLEM_START,

   CM_SS_INVOKEPROBLEM_START                      = 1155,
   CM_SS_INVOKEPROBLEM_DUPLICATEINVOKEID          =       CM_SS_INVOKEPROBLEM_START,
   CM_SS_INVOKEPROBLEM_UNRECOGNIZEDOPERATION      = 1  +  CM_SS_INVOKEPROBLEM_START,
   CM_SS_INVOKEPROBLEM_MISTYPEDPARAMETER          = 2  +  CM_SS_INVOKEPROBLEM_START,
   CM_SS_INVOKEPROBLEM_RESOURCELIMITATION         = 3  +  CM_SS_INVOKEPROBLEM_START,
   CM_SS_INVOKEPROBLEM_INITIATINGRELEASE          = 4  +  CM_SS_INVOKEPROBLEM_START,
   CM_SS_INVOKEPROBLEM_UNRECOGNIZEDLINKDID        = 5  +  CM_SS_INVOKEPROBLEM_START,
   CM_SS_INVOKEPROBLEM_LINKEDRESONSEUNEXPECTED    = 6  +  CM_SS_INVOKEPROBLEM_START,
   CM_SS_INVOKEPROBLEM_UNEXPECTEDLINKEDOPERATION  = 7  +  CM_SS_INVOKEPROBLEM_START,

   CM_SS_RETURNRESULTPROBLEM_START                     = 1163,
   CM_SS_RETURNRESULTPROBLEM_RR_UNRECOGNIZEDINVOKEID   =      CM_SS_RETURNRESULTPROBLEM_START,
   CM_SS_RETURNRESULTPROBLEM_RR_RETURNRESULTUNEXPECTED = 1 +  CM_SS_RETURNRESULTPROBLEM_START,
   CM_SS_RETURNRESULTPROBLEM_RR_MISTYPEDPARAMETER      = 2 +  CM_SS_RETURNRESULTPROBLEM_START,

   CM_SS_RETURNERRORPROBLEM_START                      = 1166,
   CM_SS_RETURNERRORPROBLEM_RE_UNRECOGNIZEDINVOKEID    =      CM_SS_RETURNERRORPROBLEM_START,
   CM_SS_RETURNERRORPROBLEM_RE_RETURNERRORUNEXPECTED   = 1 +  CM_SS_RETURNERRORPROBLEM_START,
   CM_SS_RETURNERRORPROBLEM_RE_UNRECOGNIZEDERROR       = 2 +  CM_SS_RETURNERRORPROBLEM_START,
   CM_SS_RETURNERRORPROBLEM_RE_UNEXPECTEDERROR         = 3 +  CM_SS_RETURNERRORPROBLEM_START,
   CM_SS_RETURNERRORPROBLEM_RE_MISTYPEDPARAMETER       = 4 +  CM_SS_RETURNERRORPROBLEM_START,
/* ============================== ~SS cause ============================== */

/* ============================== MM cause ============================== */
// 3GPP 24.008 clause 10.5.3.6(Annex G) MM reject cause values
// 3GPP 24.008 clause 10.5.5.14(Annex G) GMM cause values
// 2048 -> MM cause values
   CM_MM_CAUSE_START                     = 2048,
   CM_MM_CAUSE_NONE                     =     0x00 + CM_MM_CAUSE_START,
   CM_MM_IMSI_UNKNOWN_IN_HLR            =     0x02 + CM_MM_CAUSE_START,
   CM_MM_ILLEGAL_MS                     =     0x03 + CM_MM_CAUSE_START,
   CM_MM_IMSI_UNKNOWN_IN_VLR            =     0x04 + CM_MM_CAUSE_START,
   CM_MM_IMEI_NOT_ACCEPTED              =     0x05 + CM_MM_CAUSE_START,
   CM_MM_ILLEGAL_ME                     =     0x06 + CM_MM_CAUSE_START,
   CM_MM_GPRS_NOT_ALLOWED               =     0x07 + CM_MM_CAUSE_START,
   CM_MM_GPRS_NON_GPRS_NOT_ALLOWED      =     0x08 + CM_MM_CAUSE_START,
   CM_MM_MS_ID_NOT_DERIVED_BY_NW        =     0x09 + CM_MM_CAUSE_START,
   CM_MM_IMPLICIT_DETACH                =     0x0a + CM_MM_CAUSE_START,
   CM_MM_PLMN_NOT_ALLOWED               =     0x0b + CM_MM_CAUSE_START,
   CM_MM_LOCATION_AREA_NOT_ALLOWED      =     0x0c + CM_MM_CAUSE_START,
   CM_MM_ROAMING_AREA_NOT_ALLOWED       =     0x0d + CM_MM_CAUSE_START,
   CM_MM_GPRS_NOT_ALLOWED_IN_PLMN       =     0x0e + CM_MM_CAUSE_START,
   CM_MM_NO_SUITABLE_CELLS_IN_LA        =     0x0f + CM_MM_CAUSE_START,
   CM_MM_MSC_TEMP_NOT_REACHABLE         =     0x10 + CM_MM_CAUSE_START,
   CM_MM_NETWORK_FAILURE                =     0x11 + CM_MM_CAUSE_START,
   CM_MM_MAC_FAILURE                    =     0x14 + CM_MM_CAUSE_START,
   CM_MM_SYNC_FAILURE                   =     0x15 + CM_MM_CAUSE_START,
   CM_MM_CONGESTION                     =     0x16 + CM_MM_CAUSE_START,
   CM_MM_SERV_OPTION_NOT_SUPPORTED      =     0x20 + CM_MM_CAUSE_START,
   CM_MM_REQ_SERV_OPTION_NOT_SUBSCRIBED =     0x21 + CM_MM_CAUSE_START,
   CM_MM_SERV_OPTION_TEMP_OUT_OF_ORDER  =     0x22 + CM_MM_CAUSE_START,
   CM_MM_CALL_CANNOT_BE_IDENTIFIED      =     0x26 + CM_MM_CAUSE_START,
   CM_MM_NO_PDP_CONTEXT_ACTIVATED       =     0x28 + CM_MM_CAUSE_START,
   CM_MM_RETRY_UPON_ENTRY_INTO_NEWCELL_MIN =  0x30 + CM_MM_CAUSE_START,  /* 30..3f */
   CM_MM_RETRY_UPON_ENTRY_INTO_NEWCELL_MAX =  0x3f + CM_MM_CAUSE_START,
   CM_MM_SEMANTICALLY_INCORRECT_MSG        =  0x5f + CM_MM_CAUSE_START,
   CM_MM_INVALID_MM_MAND_INFO              =  0x60 + CM_MM_CAUSE_START,
   CM_MM_MSG_TYPE_NON_EXISTENT             =  0x61 + CM_MM_CAUSE_START,
   CM_MM_MSG_TYPE_NOT_IMPLEMENTED          =  0x61 + CM_MM_CAUSE_START,
   CM_MM_MSG_TYPE_INCOMPAT_WITH_PROTO_STATE = 0x62 + CM_MM_CAUSE_START,
   CM_MM_IE_NOT_IMPLEMENTED                 = 0x63 + CM_MM_CAUSE_START,
   CM_MM_CONDITIONAL_MM_IE_ERROR            = 0x64 + CM_MM_CAUSE_START,
   CM_MM_MSG_NOT_COMPAT_WITH_PROTO_STATE    = 0x65 + CM_MM_CAUSE_START,  /* 65..6f */
   CM_MM_PROTO_ERROR_UNSPECIFIED            = 0x6f + CM_MM_CAUSE_START,

   /* RR connection establishment failure */
   CM_MM_ACCESS_BARRED  ,
   CM_MM_ASSIGNMENT_REJECT ,
   CM_MM_RANDOM_ACCES_FAILURE ,
   CM_MM_RR_NO_SERVICE ,
   CM_RR_PLMN_SRCH_REJ_EMERGENCY,   
   CM_MM_RR_CONN_RELEASE,

   /* other cause */
   CM_MM_AUTH_FAILURE,
   CM_MM_IMSI_DETACH,
   CM_MM_ABORT_BY_NW ,
   CM_MM_CONN_TIMEOUT,
   /* MM internal casuse */
   CM_MM_CM_ENQUEUE_FAIL,
   CM_MM_NOT_UPDATED ,
   CM_MM_STATE_NOT_ALLOWED_CM,
   CM_MM_EMERGENCY_NOT_ALLOWED,
   CM_MM_NO_SERVICE,
   CM_MM_ACCESS_CLASS_BARRED,
#ifdef __GEMINI__
   CM_RR_SUSPEND_FOR_CS_SIG,      /* may be short time */
   CM_RR_SUSPEND_FOR_CS_CALL,   /* may be long time */
   CM_RR_SUSPEND_FOR_PS_SIG,     /* may be short time */
   CM_RR_SUSPEND_FOR_PS_DATA,  /* may be short time or long time */
   CM_RR_SUSPEND_UNSPECIFIED, /* race condtion, RR cannot obtain semaphore, but not yet receive suspend cause from another RR */
 #endif
   CM_MM_CAUSE_END                       = 2048 + 256,
/* ============================== ~MM cause ============================== */

/* ============================== SIM cause ============================== */
   SIM_CAUSE_START                                     = 2560,
   SIM_CAUSE_CMD_SUCCESS                               =     SIM_CAUSE_START,
   SIM_CAUSE_CMD_FAIL                                  = 1 + SIM_CAUSE_START,
   SIM_CAUSE_FATAL_ERROR                               = 2 + SIM_CAUSE_START,
   SIM_CAUSE_NO_INSERTED                               = 3 + SIM_CAUSE_START,
   SIM_CAUSE_CHV_NOT_INIT                              = 4 + SIM_CAUSE_START,
   SIM_CAUSE_CHV_VERIFY_ERROR                          = 5 + SIM_CAUSE_START, /* SIM_CHV_RETRY_ALLOW */
   SIM_CAUSE_CHV_BLOCK                                 = 6 + SIM_CAUSE_START, /* SIM_CHV_BLOCK */
   SIM_CAUSE_ACCESS_NOT_ALLOW                          = 7 + SIM_CAUSE_START, /* */
   SIM_CAUSE_SAT_CMD_BUSY                              = 8 + SIM_CAUSE_START, /* */
   SIM_CAUSE_DL_ERROR                                  = 9 + SIM_CAUSE_START, /* */
   SIM_CAUSE_MEMORY_PROBLEM                            = 10 + SIM_CAUSE_START, /* */
   SIM_CAUSE_TECHNICAL_PROBLEM                         = 11 + SIM_CAUSE_START, /* */
   SIM_CAUSE_PUK_UNLOCK                                = 12 + SIM_CAUSE_START, /* add new enum value to 
                                                                               distinguish whether normal poweron or PUK-unlock-poweron */
   SIM_CAUSE_END,
/* ============================== ~SIM cause ============================== */

/* ============================== PHB cause ============================== */
   PHB_CAUSE_FDN_BLOCKED = 2600,
   PHB_L4C_ERROR = 2601,  /*called number is not approved by PHB*/
/* ============================== ~PHB cause ============================== */

/* ============================== SM cause ============================== */
// 3GPP 24.008 clause 10.5.6.6(Annex I) SM/LLC/SNDCP/PDP/GPRS cause values
// 3072 -> SM cause values

    SM_CAUSE_START                   = 3072,
    LLC_SND_FAILURE                  =   0X19 + SM_CAUSE_START,
    INSUFF_RESOURCE                  =   0X1A + SM_CAUSE_START,
    UNKNOWN_APN                      =   0X1B + SM_CAUSE_START,
    UNKNOWN_PDP_ADDR_OR_TYPE         =   0X1C + SM_CAUSE_START,
    AUTHENTICATION_FAILURE           =   0X1D + SM_CAUSE_START,
    ACTIVATION_REJ_GGSN              =   0X1E + SM_CAUSE_START,
    ACTIVATION_REJ                   =   0X1F + SM_CAUSE_START,
    UNSUPPORTED_SERVICE_OPTION       =   0X20 + SM_CAUSE_START,
    UNSUBSCRIBED_SERVICE_OPTION      =   0X21 + SM_CAUSE_START,
    OUT_OF_ORDER_SERVICE_OPTION      =   0X22 + SM_CAUSE_START,
    REGULAR_DEACTIVATION             =   0X24 + SM_CAUSE_START,
    QOS_NOT_ACCEPTED                 =   0X25 + SM_CAUSE_START,
    NETWORK_FAIL                     =   0X26 + SM_CAUSE_START,
    REACTIVATION_REQD                =   0X27 + SM_CAUSE_START,
    UNSUPPORTED_NW_CONTEXT_ACTIVATION=   0X28 + SM_CAUSE_START, /* Came and went from 4.08 + SM_CAUSE_START,
                                                  should this be removed? */
    SEMANTIC_ERROR_IN_TFT_OP         =   0X29 + SM_CAUSE_START,
    SYNTACTICAL_ERROR_IN_TFT_OP      =   0X2A + SM_CAUSE_START,
    UNKNOWN_PDP_CONTEXT              =   0X2B + SM_CAUSE_START,
    SEMANTIC_ERROR_IN_PACKET_FILTER  =   0X2C + SM_CAUSE_START,
    SYNTAX_ERROR_IN_PACKET_FILTER    =   0X2D + SM_CAUSE_START,
    PDP_CONTEXT_WO_TFT_ALREADY_ACT   =   0X2E + SM_CAUSE_START,
    /* The following cause values are only for sm internal usage */
    INVALID_TI                       =   0X51 + SM_CAUSE_START,
    INCORRECT_MSG                    =   0X5F + SM_CAUSE_START,
    INVALID_MAND_INFO                =   0X60 + SM_CAUSE_START,
    UNIMPLE_MSG_TYPE                 =   0X61 + SM_CAUSE_START,
    INCOMPAT_MSG_TYP_PROTO_STAT      =   0X62 + SM_CAUSE_START,
    UNIMPLE_IE                       =   0X63 + SM_CAUSE_START,
    CONDITIONAL_IE_ERROR             =   0X64 + SM_CAUSE_START,
    INCOMP_MSG_PROTO_STAT            =   0X65 + SM_CAUSE_START,
    UNSPECIFIED                      =   0X6F + SM_CAUSE_START,
    STARTUP_FAILURE , /* cause enum when the link layer startup fails */ 
    SM_CAUSE_END,
/* ============================== ~SM cause ============================== */

/* ============================== ABM cause ============================== */
//
// ABM error causes, Kevin Chien
//    
    ABM_CAUSE_START = 3272,
    ABM_E_SUCCESS,
    ABM_E_INVALID_NW_ACC_ID,
    ABM_E_GPRS_REACTIVATE,
    ABM_E_GPRS_PROTOCOL_REJECTION,
    ABM_E_CSD_REACTIVATE,
    ABM_E_CSD_PPP_NEGOTIATED_FAILED,
    ABM_E_CSD_ACT_FAILED,
    ABM_E_CSD_CALL_SETUP_FAILED,
    ABM_E_WIFI_REACTIVATE,
    ABM_E_WIFI_NOTREADY,
    ABM_E_REJECTED,
/* ============================== ~ABM cause ============================== */

/* ============================== TCM cause ============================== */
    TCM_L4C_INVALID_PARAMETER = 3372,
    TCM_L4C_NSAPI_NOT_IN_USE,
/* ============================== ~TCM cause ============================== */

/* ============================== L4C cause ============================== */
    L4C_CMD_CONFLICT = 3472
/* ============================== ~L4C cause ============================== */
}ps_cause_enum;

typedef kal_uint8 band_selection_enum;
#define BAND_900   0x02
#define BAND_1800 0x08
#define BAND_1900 0x10
#define BAND_DUAL (BAND_900|BAND_1800)
#define BAND_850  0x80

#ifndef __MTK_3G_MRAT_ARCH__
typedef enum
{
   CELL_CHANGED ,
   LA_CHANGED,
   PLMN_CHANGED,
   NUM_OF_GS_CHANGED
} cb_geography_enum;
#endif

#ifdef __MTK_3G_MRAT_ARCH__
/* UAS/GAS <-> RATCM begin */

typedef enum {
    NM_1 = 0,
    NM_2 = 1,
    NM_3 = 2,
    NM_NONE = 3
}network_mode_enum;

typedef enum
{
    ANY_PLMN                                    = 0,
    GIVEN_PLMN_EXCLUDE_FORBIDDEN_LA             = 1,
    GIVEN_PLMN_EXCLUDE_FORBIDDEN_LA_FOR_ROAMING = 2,
    GIVEN_PLMN_ALLOW_ALL_LA                     = 3
} plmn_search_type_enum;

typedef enum {
    PLMN_NOT_FOUND = 0,
    PLMN_FOUND     = 1,
    CANNOT_PROCESS = 2
} plmn_search_result_enum;

typedef enum {
    PLMN_SEARCH_UNRELATED = 0,
    PLMN_SEARCH_FINISHED  = 1
} plmn_search_status_enum;

typedef enum {
    CELL_TYPE_SUITABLE       = 0,
    CELL_TYPE_ACCEPTABLE     = 1,
    CELL_TYPE_NOT_APPLICABLE = 2  
} as_cell_type_enum;

/* Ripple: please do NOT modify the rat_enum constant for that MM use rat "&" "|" operation. */
typedef enum{
    RAT_NONE     = 0, /* Ripple: Do NOT modify the sequence and values. */
    RAT_GSM      = 1,
    RAT_UMTS     = 2,
    RAT_GSM_UMTS = 3
}rat_enum;

typedef enum{
    FORBID_LA_FOR_REG_PROV_SERVICE = 0,
    FORBID_LA_FOR_ROAMING          = 1
} forbidden_la_type_enum;
   
typedef enum
{
    /* UTRAN has not used IE "Ciphering Info" in SECURITY MODE COMMAND to start controlling the ciphering. */
    CipheringNotStarted = 0,
    CipheringUEA0,   /* Use algorithm UEA0 for ciphering*/
    CipheringUEA1   /* Use algorithm UEA1 for ciphering*/
} Ciphering_Status;

typedef enum{
    PROC_STATUS_NONE          = 0,
    ATTACH_PROCEDURE_START    = 1,
    ATTACH_PROCEDURE_SUCCESS  = 2,
    RAU_PROCEDURE_START       = 3,
    RAU_PROCEDURE_SUCCESS     = 4,
    SERVICE_PROCEDURE_START   = 5,
    SERVICE_PROCEDURE_SUCCESS = 6,
    ATTACH_PROCEDURE_FAILURE  = 7,
    RAU_PROCEDURE_FAILURE     = 8,
    SERVICE_PROCEDURE_FAILURE = 9,
    NW_INIT_DETACH_PROCEDURE  = 10,
    CS_DETACH_START           = 11,
    PS_DETACH_START           = 12,
    CS_PS_DETACH_START        = 13,
    LU_PROCEDURE_SUCCESS      = 14,
    LU_PROCEDURE_FAILURE      = 15,
    CM_SERVICE_FAILURE        = 16,
    CS_AUTH_REJ               = 17,
    CS_AUTH_FAIL              = 18,
    PS_AUTH_REJ               = 19,
    PS_AUTH_FAIL              = 20,
    CS_PS_POWER_OFF           = 21,
    DETACH_PROCEDURE_END      = 22,
    MS_STATE_CHANGE           = 23
}regn_proc_status_enum;

/* Ripple */
typedef enum {
    MMAS_NO_CHG_IN_REGN_STATUS = 0,
    MMAS_CS_ATTACHED           = 1,
    MMAS_PS_ATTACHED           = 2,
    MMAS_CS_PS_ATTACHED        = 3,
    MMAS_CS_DETACHED           = 4,
    MMAS_PS_DETACHED           = 5,
    MMAS_CS_PS_DETACHED        = 6
}mmas_regn_status_enum;

typedef enum {
    AS_REL_SCOPE_SIGNALING,
    AS_REL_SCOPE_CONNECTION
}as_rel_scope_enum;

typedef enum
{
    IMSI_TYPE          = 0x01,
    TMSI_TYPE          = 0x04,
    PTMSI_TYPE         = 0x04,
    INVALID_UE_ID_TYPE = 0xff
} ue_id_type_enum;

typedef enum
{
    AS_CONN_EST_SUCC           = 0,
    ACCESS_BARRED              = 1,
    IMM_ASSGN_REJECT_RCVD      = 2,
    RAND_ACC_FAILURE           = 3,
    RR_NO_SERVICE              = 4,
    GIBI_TAG_MISMATCH          = 5,
    UAS_CONN_EST_FAILURE       = 6,
    RR_PLMN_SRCH_REJ_EMERGENCY = 7,
    REDIRECT_SUCC              = 8,
    /*Byron: 2007/05/08: Add reject cause for CCO activation timer is running*/
    CCO_ACTIVATION_TIME_ONGOING= 9
} as_est_cnf_cause_enum; /* ps_cause_enum need modify, too. */

/* ~ Ripple */   

/* ENUMERATED PagingCause */
typedef enum
{
    PagingCause_terminatingConversationalCall	= 0,
    PagingCause_terminatingStreamingCall	= 1,
    PagingCause_terminatingInteractiveCall	= 2,
    PagingCause_terminatingBackgroundCall	= 3,
    PagingCause_terminatingHighPrioritySignalling  = 4,
    PagingCause_terminatingLowPrioritySignalling = 5,
    PagingCause_terminatingCauseUnknown  = 6
}
RATCM_RRC_PagingCause;

/* ENUMERATED ReleaseCause */
typedef enum
{
    normalEvent = 0,
    ReleaseCause_unspecified = 1,
    pre_emptiveRelease = 2,
    ReleaseCause_congestion = 3,
    re_establishmentReject = 4,
    directedsignallingconnectionre_establishment = 5,
    userInactivity = 6
}
RATCM_RRC_ReleaseCause;

typedef enum
{
    SAPI_0_High = 0,
    SAPI_3_Low = 1
} DC_Priority;

typedef enum
{
    DC_Status_SUCCESS = 0,
    /* RRCE couldn't deliver this NAS message successfully to peer entity.*/
    DC_Status_Normal_FAILURE = 1,
    /* RLC layers couldn't deliver this NAS message successfully to peer entity and then discard it*/
    DC_Status_RLC_Discard_FAILURE = 2,
    DC_Status_GIBI_TagMismatch = 3	
} DC_Status;

typedef enum{
    READY_TMR_ACT   = 0,
    READY_TMR_DEACT = 1
}action_on_ready_timer_enum;

typedef enum{
    READY_TMR_EXPIRES = 0,
    READY_TMR_REVIVE  = 1
}ready_timer_status_enum;

typedef enum{
    CIPHER_CMD      = 0,
    TCH_ASSIGN      = 1,
    CHMODE_MODIFY   = 2,
    CHANNEL_RELEASE = 3,
    UAS_RAB_MODIFY  = 4,
    UAS_RAB_EST     = 5
}sync_ind_cause_enum;

/* UAS/GAS <-> RATCM end */

typedef enum{
    SIM_NORM_OP                          = 0x00,
    SIM_TYPE_APPROV_OP                   = 0x80,
    SIM_NORM_OP_AND_SPEC_FACILITY        = 0x01,
    SIM_TYPE_APPROV_OP_AND_SPEC_FACILITY = 0x81,
    SIM_MAINTENANCE                      = 0x02,
    SIM_CELL_TEST_OP                     = 0x04
} sim_op_mode_enum;

typedef enum
{
    SGSNR_0,
    SGSNR_1,
    SGSNR_NOT_PRESENT
} rr_mm_sgsnr_flag_enum; 
#endif


#ifdef __GEMINI__

typedef enum
{
    SIM1_ONLY_CONFIG = 0,
    SIM2_ONLY_CONFIG = 1,
    DAUL_SIM_CONFIG  = 2,
    SIM_CONFIG_STATUS_NONE = 0xFF
} sim_config_status_enum; 

typedef enum
{
    NO_SIM_INSERTED    = 0,
    ONLY_SIM1_INSERTED = 1,
    ONLY_SIM2_INSERTED = 2,
    DUAL_SIM_INSERTED  = 3,
    SIM_INSERT_STATUS_NONE = 0xFF
} sim_insert_status_enum; 

typedef enum
{
    RR_NOT_IN_SUSPEND_MODE         = 0,
    RR_IN_SUSPEND_MODE_FOR_CS_SIG  = 1,
    RR_IN_SUSPEND_MODE_FOR_CS_CALL = 2,
    RR_IN_SUSPEND_MODE_FOR_PS_SIG  = 3,
    RR_IN_SUSPEND_MODE_FOR_PS_DATA = 4,
    RR_IN_SUSPEND_MODE_UNSPECIFIED = 5 //for MM use
} rr_suspend_mode_reason_enum;

#endif /* __GEMINI__ */

#endif // ifndef _l3_INC_ENUMS_H

