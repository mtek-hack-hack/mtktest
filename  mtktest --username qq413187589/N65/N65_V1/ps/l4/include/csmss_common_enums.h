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
 *	csmss_common_enums.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for type definition used in CSM(SS) module.
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



#ifndef _CSMSS_COMMON_ENUMS_H
#define _CSMSS_COMMON_ENUMS_H

/* the following are used for CSMSS */

typedef enum
{
    CSMSS_NULL_STATE,
    CSMSS_WAIT_FOR_NW_STATE,
    CSMSS_WAIT_FOR_SUB_STATE
}csmss_state_enum;

typedef enum {
   L4_LMI  = 0,
   L4_SAT  = 1,
   L4_RMI  = 3,
   L4_CPHS = 11 //INVALID_SRC
} l4_src_id_enum;

typedef enum {
   L4_SUCCESS  = 0,
   L4_FAIL     = 1,
   L4_CHANGE   = 2
} l4_ret_code_enum;

typedef enum {
   SS_OP_REGISTERSS                            =  10,  //          CISS
   SS_OP_ERASESS                               =  11,  //          CISS
   SS_OP_ACTIVATESS                            =  12,  //          CISS
   SS_OP_DEACTIVATESS                          =  13,  //          CISS
   SS_OP_INTERROGATESS                         =  14,  //          CISS
   SS_OP_NOTIFYSS                              =  16,  // CRSS
   SS_OP_REGISTERPASSWORD                      =  17,  //          CISS
   SS_OP_GETPASSWORD                           =  18,  //          CISS
   SS_OP_PROCESSUNSTRUCTUREDSS_DATA            =  19,  // CRSS AND CISS
   SS_OP_FORWARDCHECKSS_INDICATION             =  38,  //          CISS
   SS_OP_PROCESSUNSTRUCTUREDSS_REQUEST         =  59,  //          CISS
   SS_OP_UNSTRUCTUREDSS_REQUEST                =  60,  //          CISS
   SS_OP_UNSTRUCTUREDSS_NOTIFY                 =  61,  //          CISS
   SS_OP_ERASECCENTRY                          =  77,  //          CISS
   SS_OP_LCS_MOLR                              = 115,  //          CISS
   SS_OP_LCS_LOCATIONNOTIFICATION              = 116,  //          CISS
   SS_OP_CALLDEFLECTION                        = 117,  // CRSS
   SS_OP_USERUSERSERVICE                       = 118,  // CRSS
   SS_OP_ACCESSREGISTERCCENTRY                 = 119,  // CRSS
   SS_OP_FORWARDCUG_INFO                       = 120,  // CRSS
   SS_OP_SPLITMPTY                             = 121,  // CRSS
   SS_OP_RETRIEVEMPTY                          = 122,  // CRSS
   SS_OP_HOLDMPTY                              = 123,  // CRSS
   SS_OP_BUILDMPTY                             = 124,  // CRSS
   SS_OP_FORWARDCHARGEADVICE                   = 125,  // CRSS
   SS_OP_EXPLICITCT                            = 126   // CRSS
} l4_op_code_enum;

typedef enum {// string  SIA   SIB   SIC
   L4_ALLSS,
   L4_EMLPP,  // "75",    -     -     -
   L4_EMLPP0, // "750",   -     -     -
   L4_EMLPP1, // "751",   -     -     -
   L4_EMLPP2, // "752",   -     -     -
   L4_EMLPP3, // "753",   -     -     -
   L4_EMLPP4, // "754",   -     -     -
   L4_CD,     // "66",    -     -     -
   L4_CLIP,   // "30",    -     -     -
   L4_CLIR,   // "31",    -     -     -
   L4_COLP,   // "76",    -     -     -
   L4_COLR,   // "77",    -     -     -
   L4_CFU,    // "21",   DN    BS     -
   L4_CFB,    // "67",   DN    BS     -
   L4_CFNRY,  // "61",   DN    BS     T
   L4_CFNRC,  // "62",   DN    BS     -
   L4_CFA,    // "002",  DN    BS     T
   L4_CFC,    // "004",  DN    BS     T
   L4_CW,     // "43",   BS     -     -
   L4_HOLD,
   L4_MPTY,
   L4_UUS1,   // "361",   R     -     -
   L4_UUS2,   // "362",   R     -     -
   L4_UUS3,   // "363",   R     -     -
   L4_UUSALL, // "360",   R     -     -
   L4_BAOC,   // "33",   PW    BS     -
   L4_BOIC,   // "331",  PW    BS     -
   L4_BOICEXHC, // "332",PW    BS     -
   L4_BAIC,   // "35",   PW    BS     -
   L4_BAICROAM, // "351",PW    BS     -
   L4_BAC,    // "330",  PW    BS     -
   L4_BOC,    // "333",  PW    BS     -
   L4_BIC,    // "353",  PW    BS     -
   L4_ECT,    // "96",
   L4_CCBS,   // "37",    N (1-5)
   L4_FM,     // "214",
   L4_CNAP,   // "300",   -     -     -
   L4_MSP1,   // "591",  PW
   L4_MSP2,   // "592",  PW
   L4_MSP3,   // "593",  PW
   L4_MSP4,   // "594",  PW
   L4_MC,     // "88",       NBR_USER (1-NBR_SB)
   L4_CDIP
} l4_ss_code_enum;

typedef enum { //                           Basic Service group number
// L4_ALL_BS_AND_TS               = N/A    1-12
//         TELESERVICES
   L4_ALL_TELESERVICES            = 10, // 1-6 + 12 
   L4_TELEPHONY                   = 11, // 1
   L4_ALL_DATA_TELESERVICES       = 12, // 2-6
   L4_FACSIMILE_SERVICES          = 13, // 6
   L4_SHORT_MESSAGE_SERVICES      = 16, // 2
   L4_ALL_TELESERVICES_EXCEPT_SMS = 19, // 1 + 3-6 + 12
//         VOICE GROUP SERVICES
   L4_VOICE_GROUP_CALL_SERVICE    = 17,
   L4_VOICE_BROADCAST_SERVICE     = 18,
//         BEARER SERVICE
   L4_ALL_BEARER_SERVICES         = 20, // 7-11
   L4_ALL_ASYNC_SERVICES          = 21, // 7
   L4_ALL_SYNC_SERVICES           = 22, // 8
   L4_ALL_DATA_CIRCUIT_SYNC       = 24, // 8
   L4_ALL_DATA_CIRCUIT_ASYNC      = 25, // 7
   L4_AUXILIARY_TELEPHONY         = 89,
   L4_ALL_GPRS_BEARER_SERVICES    = 99,  // 13
   /* Johnny: these enums do not exist in 22.030, only for MMI display,
      user should not input these enums for tele/bearer service code */
   L4_BS_ALLPADACCESSCA_SERVICES = 100,
   L4_BS_ALLDATAPDS_SERVICES = 101
} l4_bs_code_enum;

typedef enum {    //                        RegisterSS EraseSS ActivateSS DeactivateSS InterrogateSS
   SS_ALLSS                       = 0x00,
   SS_ALLLINEIDENTIFICATIONSS     = 0x10,
   SS_CLIP                        = 0x11, //                                           11.14
   SS_CLIR                        = 0x12, //                                           12.14
   SS_COLP                        = 0x13, //                                           13.14
   SS_COLR                        = 0x14, //                                           14.14
   SS_MCI                         = 0x15,
   SS_ALLNAMEIDENTIFICATIONSS     = 0x18,
   SS_CNAP                        = 0x19, //                                           19.14
   SS_ALLFORWARDINGSS             = 0x20, //20.10      20.11   20.12      20.13        20.14
   SS_CFU                         = 0x21, //21.10      21.11   21.12      21.13        21.14
   SS_ALLCONDFORWARDINGSS         = 0x28, //28.10      28.11   28.12      28.13        28.14
   SS_CFB                         = 0x29, //29.10      29.11   29.12      29.13        29.14
   SS_CFNRY                       = 0x2A, //2A.10      2A.11   2A.12      2A.13        2A.14
   SS_CFNRC                       = 0x2B, //2B.10      2B.11   2B.12      2B.13        2B.14
   SS_CD                          = 0x24,
   SS_ALLCALLOFFERINGSS           = 0x30,
   SS_ECT                         = 0x31,
   SS_MAH                         = 0x32,
   SS_ALLCALLCOMPLETIONSS         = 0x40,
   SS_CW                          = 0x41, //                   41.12      41.13        41.14
   SS_HOLD                        = 0x42, //                              ERASECCENTRY
   SS_CCBS_A                      = 0x43, //                              43.77        43.14
   SS_CCBS_B                      = 0x44,
   SS_MC                          = 0x45,
   SS_ALLMULTIPARTYSS             = 0x50,
   SS_MULTIPTY                    = 0x51,
   SS_ALLCOMMUNITYOFINTEREST_SS   = 0x60,
   SS_CUG                         = 0x61,
   SS_ALLCHARGINGSS               = 0x70,
   SS_AOCI                        = 0x71,
   SS_AOCC                        = 0x72,
   SS_ALLADDITIONALINFOTRANSFERSS = 0x80,
   SS_UUS1                        = 0x81,
   SS_UUS2                        = 0x82,
   SS_UUS3                        = 0x83, //REGISTERPW GETPW
   SS_ALLBARRINGSS                = 0x90, //90.17      90.18   90.12      90.13        90.14
   SS_BARRINGOFOUTGOINGCALLS      = 0x91, //91.17      91.18   91.12      91.13        91.14
   SS_BAOC                        = 0x92, //92.17      92.18   92.12      92.13        92.14
   SS_BOIC                        = 0x93, //93.17      93.18   93.12      93.13        93.14
   SS_BOICEXHC                    = 0x94, //94.17      94.18   94.12      94.13        94.14
   SS_BARRINGOFINCOMINGCALLS      = 0x99, //99.17      99.18   99.12      99.13        99.14
   SS_BAIC                        = 0x9A, //9A.17      9A.18   9A.12      9A.13        9A.14
   SS_BICROAM                     = 0x9B, //9B.17      9B.18   9B.12      9B.13        9B.14
   SS_ALLCALLPRIORITYSS           = 0xA0,
   SS_EMLPP                       = 0xA1, //A1.10                                      A1.14
   SS_ALLLCSPRIVACYEXCEPTION      = 0xB0,
   SS_UNIVERSAL                   = 0xB1,
   SS_CALLRELATED                 = 0xB2,
   SS_CALLUNRELATED               = 0xB3,
   SS_PLMNOPERATOR                = 0xB4,
   SS_ALLMOLR_SS                  = 0xC0,
   SS_BASICSELFLOCATION           = 0xC1,
   SS_AUTONOMOUSSELFLOCATION      = 0xC2,
   SS_TRANSFERTOTHIRDPARTY        = 0xC3,
   SS_ALLPLMN_SPECIFICSS          = 0xF0,
   SS_PLMN_SPECIFICSS_1           = 0xF1,
   SS_PLMN_SPECIFICSS_2           = 0xF2,
   SS_PLMN_SPECIFICSS_3           = 0xF3,
   SS_PLMN_SPECIFICSS_4           = 0xF4,
   SS_PLMN_SPECIFICSS_5           = 0xF5,
   SS_PLMN_SPECIFICSS_6           = 0xF6,
   SS_PLMN_SPECIFICSS_7           = 0xF7,
   SS_PLMN_SPECIFICSS_8           = 0xF8,
   SS_PLMN_SPECIFICSS_9           = 0xF9,
   SS_PLMN_SPECIFICSS_A           = 0xFA,
   SS_PLMN_SPECIFICSS_B           = 0xFB,
   SS_PLMN_SPECIFICSS_C           = 0xFC,
   SS_PLMN_SPECIFICSS_D           = 0xFD,
   SS_PLMN_SPECIFICSS_E           = 0xFE,
   SS_PLMN_SPECIFICSS_F           = 0xFF
} ss_code_enum;

/*
 * Teleservice codes
 * 3GPP TS 29.002 clause 7.6.4.39 / 17.7.9
 */

typedef enum {
   TS_ALLTELESERVICES                       = 0x00,
   TS_ALLSPEECTRANSMISSIONSERVICES          = 0x10,
   TS_TELEPHONY                             = 0x11,
   TS_EMERGENCYCALLS                        = 0x12,
   TS_ALLSHORTMESSAGESERVICES               = 0x20,
   TS_SHORTMESSAGEMT_PP                     = 0x21,
   TS_SHORTMESSAGEMO_PP                     = 0x22,
   TS_ALLFACSIMILETRANSMISSIONSERVICES      = 0x60,
   TS_FACSIMILEGROUP3ANDALTERSPEECH         = 0x61,
   TS_AUTOMATICFACSIMILEGROUP3              = 0x62,
   TS_FACSIMILEGROUP4                       = 0x63,
   TS_ALLDATATELESERVICES                   = 0x70,
   TS_ALLTELESERVICES_EXEPTSMS              = 0x80,
   TS_ALLVOICEGROUPCALLSERVICES             = 0x90,
   TS_VOICEGROUPCALL                        = 0x91,
   TS_VOICEBROADCASTCALL                    = 0x92,
   TS_ALLPLMN_SPECIFICTS                    = 0xD0,
   TS_PLMN_SPECIFICTS_1                     = 0xD1,
   TS_PLMN_SPECIFICTS_2                     = 0xD2,
   TS_PLMN_SPECIFICTS_3                     = 0xD3,
   TS_PLMN_SPECIFICTS_4                     = 0xD4,
   TS_PLMN_SPECIFICTS_5                     = 0xD5,
   TS_PLMN_SPECIFICTS_6                     = 0xD6,
   TS_PLMN_SPECIFICTS_7                     = 0xD7,
   TS_PLMN_SPECIFICTS_8                     = 0xD8,
   TS_PLMN_SPECIFICTS_9                     = 0xD9,
   TS_PLMN_SPECIFICTS_A                     = 0xDA,
   TS_PLMN_SPECIFICTS_B                     = 0xDB,
   TS_PLMN_SPECIFICTS_C                     = 0xDC,
   TS_PLMN_SPECIFICTS_D                     = 0xDD,
   TS_PLMN_SPECIFICTS_E                     = 0xDE,
   TS_PLMN_SPECIFICTS_F                     = 0xDF,
//} teleservice_code_enum;
/*
 * Bearer Service codes
 * 3GPP TS 29.002 clause 7.6.4.38 / 17.7.10
 */
//typedef enum {
   BS_ALLBEARERSERVICES                     = 0x00,
   BS_ALLDATACDA_SERVICES                   = 0x10,
   BS_DATACDA_300BPS                        = 0x11,
   BS_DATACDA_1200BPS                       = 0x12,
   BS_DATACDA_1200_75BPS                    = 0x13,
   BS_DATACDA_2400BPS                       = 0x14,
   BS_DATACDA_4800BPS                       = 0x15,
   BS_DATACDA_9600BPS                       = 0x16,
   BS_GENERAL_DATACDA                       = 0x17,
   BS_ALLDATACDS_SERVICES                   = 0x18,
   BS_DATACDS_1200BPS                       = 0x1A,
   BS_DATACDS_2400BPS                       = 0x1C,
   BS_DATACDS_4800BPS                       = 0x1D,
   BS_DATACDS_9600BPS                       = 0x1E,
   BS_GENERAL_DATACDS                       = 0x1F,
   BS_ALLPADACCESSCA_SERVICES               = 0x20,
   BS_PADACCESSCA_300BPS                    = 0x21,
   BS_PADACCESSCA_200BPS                    = 0x22,
   BS_PADACCESSCA_1200_75BPS                = 0x23,
   BS_PADACCESSCA_2400BPS                   = 0x24,
   BS_PADACCESSCA_800BPS                    = 0x25,
   BS_PADACCESSCA_9600BPS                   = 0x26,
   BS_GENERAL_PADACCESSCA                   = 0x27,
   BS_ALLDATAPDS_SERVICES                   = 0x28,
   BS_DATAPDS_2400BPS                       = 0x2C,
   BS_DATAPDS_4800BPS                       = 0x2D,
   BS_DATAPDS_9600BPS                       = 0x2E,
   BS_GENERAL_DATAPDS                       = 0x2F,
   BS_ALLALTERNATESPEECH_DATACDA            = 0x30,
   BS_ALLALTERNATESPEECH_DATACDS            = 0x38,
   BS_ALLSPEECHFOLLOWEDBYDATACDA            = 0x40,
   BS_ALLSPEECHFOLLOWEDBYDATACDS            = 0x48,
   BS_ALLDATACIRCUITASYNCHRONOUS            = 0x50,
   BS_ALLDATACIRCUITSYNCHRONOUS             = 0x58,
   BS_ALLASYNCHRONOUSSERVICES               = 0x60,
   BS_ALLSYNCHRONOUSSERVICES                = 0x68,
   BS_ALLPLMN_SPECIFICBS                    = 0xD0,
   BS_PLMN_SPECIFICBS_1                     = 0xD1,
   BS_PLMN_SPECIFICBS_2                     = 0xD2,
   BS_PLMN_SPECIFICBS_3                     = 0xD3,
   BS_PLMN_SPECIFICBS_4                     = 0xD4,
   BS_PLMN_SPECIFICBS_5                     = 0xD5,
   BS_PLMN_SPECIFICBS_6                     = 0xD6,
   BS_PLMN_SPECIFICBS_7                     = 0xD7,
   BS_PLMN_SPECIFICBS_8                     = 0xD8,
   BS_PLMN_SPECIFICBS_9                     = 0xD9,
   BS_PLMN_SPECIFICBS_A                     = 0xDA,
   BS_PLMN_SPECIFICBS_B                     = 0xDB,
   BS_PLMN_SPECIFICBS_C                     = 0xDC,
   BS_PLMN_SPECIFICBS_D                     = 0xDD,
   BS_PLMN_SPECIFICBS_E                     = 0xDE,
   BS_PLMN_SPECIFICBS_F                     = 0xDF
//} bearerservice_enum;
} bs_code_enum;

typedef enum {
   CAUSE_NOT_PRESENT = 0,
   CAUSE_PRESENT     = 1
} cause_present_enum;

typedef enum {
   SUBADDRESS_NOT_PRESENT = 0,
   SUBADDRESS_PRESENT     = 1
} subaddress_present_enum;

typedef enum {
   SS_EMLPP_PRIORITY_0 = 0,
   SS_EMLPP_PRIORITY_1 = 1,
   SS_EMLPP_PRIORITY_2 = 2,
   SS_EMLPP_PRIORITY_3 = 3,
   SS_EMLPP_PRIORITY_4 = 4
} emlpp_priority_enum;

typedef enum {
   INVALID_OPERATION,
   SS_OPERATION,
   SIM_OPERATION,
   GPRS_OPERATION,
   CC_OPERATION
} csmss_string_op_enum;

typedef enum {
   SS_ABIT=0x1, // activation
   SS_RBIT=0x2, // registration
   SS_PBIT=0x4, // provision
   SS_QBIT=0x8  // quiescent
} ss_status_enum;

#endif /* End of file csmss_common_enums.h */


