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
 * SimDetectionDef.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for #defines of Boot Up module
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
/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**************************************************************

   FILENAME : SimDetectionDef.h

   PURPOSE     : defines of Boot Up module

   REMARKS     : nil

   AUTHOR      : Deepali

   DATE     : 12/03/03

**************************************************************/

#ifndef __SIM_DETECTION_DEF_H__
#define __SIM_DETECTION_DEF_H__

#include "SimDetectionResDef.h"

#define MAX_PWD_LENGTH_MMI          9
#define MMI_MIN_PASSWORD_LENGTH     4
#define MMI_MIN_PUK_LENGTH          8

#define ENTER_PIN_SCR               1
#define ENTER_PUK_SCR               2
#define ENTER_SIM_SCR               3
#define ENTER_PHONELOCK             4
#define ENTER_SIM_INSERTION         5
#define ENTER_PUK_BLOCKED           6
#define ENTER_SIM_BLOCK             7
#define ENTER_CONFIRM_PIN           8
#define ENTER_NEW_PIN               9
#define ENTER_NP                    10
#define ENTER_SP                    11
#define ENTER_CP                    12
#define ENTER_NSP                   13
#define ENTER_SIMP                  14
/* SML menu implementation */
#ifdef __MMI_SML_MENU__
#define ENTER_NS_SP                 15
#define ENTER_SIM_C                 16
#define ENTER_IDLE_SCR              17
#ifdef __MMI_SML_NP_ONLY__
#define ENTER_NP_PENDING            18
#endif
#else
#define ENTER_IDLE_SCR              15
#endif /* __MMI_SML_MENU__ */

/* Defines for Network detection */
#define MAX_PLMN_LEN_MMI            6
#define MAX_LENGTH_DISPLAY_NAME     20

#define MAX_APHORISM_LIST_LENGTH    35
#define MAX_INSERT_SCR_DIGITS       13
#define MAX_ECC_NUMBER_LIST_LENGTH  5
#define MAX_LENGTH_SERVICE_PROVIDER 17
#define MAX_LENGTH_OPERATOR_NAME    21
#define MAX_LENGTH_OWNER_NUMBER     41
#define MAX_LENGTH_SHORT_OPERATOR_NAME 11

/* Battery Signal Strength Macros */

// MTK Modified, 031116, Robin, Signal strength ranging form 1 ~ 31
// 0 means no signal strength, 99 means invaild pattern
// Because NetWorkSignalLevelIndication() use "less than", so SIGNAL_STRENGTH_LEVEL5 shall be 32
/*
 * > -84 dBm : 4
 * -85~-89dBm : 3
 * -90~-94dBm : 2
 * -100~ -95 dBm : 1
 * < 100dBm : 0
 * 
 * Defined values
 * 
 * <rssi>:
 * 0 -113 dBm or less
 * 1 -111 dBm
 * 2...30 -109... -53 dBm
 * 31 -51 dBm or greater
 * 99 not known or not detectable
 */

#define  SIGNAL_STRENGTH_NONE          0
#define  SIGNAL_STRENGTH_INVAILD       99
#define  SIGNAL_STRENGTH_LEVEL1        6
#define  SIGNAL_STRENGTH_LEVEL2        9
#define  SIGNAL_STRENGTH_LEVEL3        12
#define  SIGNAL_STRENGTH_LEVEL4        15
// #define  SIGNAL_STRENGTH_LEVEL5     32

#define CODE_VERIFIED_TIMEOUT                   2000

#define APHORISM_SCR_TIME                       2000
#define WELCOME_SCR_TIME                        2000

typedef enum
{
    NO_SERVICE,
    LIMITED_SERVICE,
    FULL_SERVICE
} SERVICE_TYPE;

typedef enum
{
    MMI_TYPE_NO_REQUIRED,
    MMI_TYPE_PHONELOCK,
    MMI_TYPE_CHV1,
    MMI_TYPE_CHV2,
    MMI_TYPE_UBCHV1,
    MMI_TYPE_UBCHV2,
    MMI_TYPE_NP,
    MMI_TYPE_NSP,
    MMI_TYPE_SP,
    MMI_TYPE_CP,
    MMI_TYPE_IMSI_LOCK,
    MMI_TYPE_PERSONALIZATION_KEY,
    MMI_TYPE_CHV1_BLOCKED,
    MMI_TYPE_CHV2_BLOCKED,
    MMI_TYPE_SIM_CARD_BLOCKED,
    MMI_TYPE_UBCHV2_BLOCKED,
    MMI_TYPE_UBCHV1_CHV1_NOT_LOCK,
    MMI_TYPE_LINK_NS_SP,
    MMI_TYPE_LINK_SIM_C,
    MMI_TYPE_UNSPECIFIED
} MMISMUSECURITYTYPEENUM;

typedef enum
{
    MMI_SIM_CARD_REMOVED,
    MMI_SIM_ACCESS_ERROR,
    MMI_SIM_REFRESH,
    MMI_SIM_BT_ACCESS_PROFILE_ON = 5,
    MMI_SIM_BT_ACCESS_PROFILE_OFF
} MMISIMERRORCAUSEENUM;

typedef enum
{
    MMI_SIM_CMD_SUCCESS = 2560,
    MMI_SIM_CMD_FAIL = 2561,
    MMI_SIM_FATAL_ERROR = 2562,
    MMI_SIM_NO_INSERTED = 2563,
    MMI_SIM_CHV_NOT_INIT = 2564,
    MMI_SIM_CHV_RETRY_ALLOW = 2565,
    MMI_SIM_CHV_BLOCK = 2566,
    MMI_SIM_ACCESS_NOT_ALLOW = 2567,
    MMI_SIM_SAT_CMD_BUSY = 2568,
    MMI_SIM_DL_ERROR = 2569,
    MMI_SIM_MEMORY_PROBLEM = 2570,
    MMI_SIM_TECHNICAL_PROBLEM = 2571,
    MMI_SIM_EF_RECORD_FULL = 2573
} MMISMURESULTCMDRESULTENUM;

/* Enum for results of Network Attached Indecation */
typedef enum
{
    MMI_RAC_OK,
    MMI_RAC_NO_CELL,
    MMI_RAC_LIMITED_SERVICE,
    MMI_RAC_ERROR,
    MMI_RAC_INVALID_SIM,
    MMI_RAC_ATTEMPT_TO_UPDATE,
    MMI_RAC_SEARCHING
} MMIRACRESPONSEENUM;

typedef enum
{
    MMI_REG_STATE_NOT_REGISTERED = 0,
    MMI_REG_STATE_REGISTERED,
    MMI_REG_STATE_SEARCHING,
    MMI_REG_STATE_REG_DENIED,
    MMI_REG_STATE_UNKNOWN,
    MMI_REG_STATE_NOT_ACTIVE
} REGSTATEENUM;

/********************************************************/

typedef struct
{
    U8 IsCampOnTonePlayed;
    U8 testRoaming;     /* Robin 1211:
                           1: Never send get IMEI request
                           2: Waiting get IMEI response
                           3: IMEI response has came  */
    U8 CurrentServiceType;      /* Service types to be returned to other applications */
    U8 AbnormalReset;           /* Max for abnormal reset 0912 */
    U16 NoOfPLMNSupported;
    U8 PrevScreenIndicator;
    U8 ForCMToIdentifySOSCall;  /* For CM notification */
    U8 InvalidSimShowed;
    U8 CurrentCampOnBand;       /* Robin 1009 reserve for Rx_Level_Ind interface change */
    U8 RequireRPLMN;            /* paul for not display RPLMN if SPN say so */
    U8 SOSCallFlagTOAvoidHistorySave;
    U8 PowerOnMode;     /* Power on Mode */
    U8 NandIdCheckRes;

#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
    U8 IsRacActivated;
    U8 PhoneLockNeeded;
#endif /* __MMI_DUAL_SIM_SINGLE_CALL__ */

    /* diamond, 2005/08/15 bootup revise */
    U8 PowerOnMMIStatus;
    U8 PowerOnSIMStatus;
    U8 PowerOnNWStatus;
    U8 PowerOffMMIStatus;
    /* end, diamond */

} pwr_context_struct;

typedef struct
{
    U8 PowerOnCharger;          /* Tells if the power on is bcos of charger */
    U8 PowerOnChargingPeriod;   /* Tells if charging is going on during power on charger */
    U8 ChargingAbnormal;        /* If abnormal case of charging. */
    U8 ChargingComplete;        /* Tells if charging is complete. (Robin 1121 for engineer mode) */
    U8 LowBatteryFlag;          /* Tels if Battery is low. */
    U8 LowBatteryTxProhibitFlag;
    U8 chargerLevel;
    U8 batteryStatus;
    U8 isChargerConnected;      /* Tells if charger is connected */
    U8 LowBatteryCutOffCallCnt;
    U8 BatteryNotifyModId;      /* Battery notify module ID: default=0 */
} charbat_context_struct;

#ifdef __MMI_NITZ__
typedef struct
{
    U8 opname_from_nitz;
    U8 country_init;
    U8 plmn[MAX_PLMN_LEN_MMI+1];
    U8 display_name[MAX_LENGTH_DISPLAY_NAME * ENCODING_LENGTH];
} idle_nitz_struct;
#endif /* __MMI_NITZ__ */

/********************************************************/

/* diamond, 2005/08/15 bootup revise */
typedef enum
{
    MMI_POWER_ON_DEFAULT,                           /* 0000 0000 */
    MMI_POWER_ON_INDICATION,                        /* 0000 0001 POWER_ON_KEYPAD */
    MMI_POWER_ON_DISK_CHECK,
    MMI_POWER_ON_FLIGHT_MODE_QUERY,                 /* 0000 0011 Flight mode query screen */
    MMI_POWER_ON_ANIMATION = 0x04,                  /* 0000 0100 Power on animation start */
    MMI_POWER_ON_ANIMATION_PSWD_REQ,                /* 0000 0101 Password requirement ind received */
    MMI_POWER_ON_ANIMATION_SIM_FAIL,                /* 0000 0110 SIM failure received ind received */
    MMI_POWER_ON_LOW_BATTERY = 0x08,                /* 0000 1000 Low battery warning */
    MMI_POWER_ON_NAND_CHECK,                        /* 0000 1001 NAND check screen */
    MMI_POWER_ON_SECURITY_NO_PSWD = 0x10,           /* 0001 0000 Security check (no password required) */
    MMI_POWER_ON_SECURITY_PHONE_LOCK,               /* 0001 0001 Security check (phone lock) */
    MMI_POWER_ON_SECURITY_SIM_LOCK,                 /* 0001 0010 Security check (SIM lock) */
    MMI_POWER_ON_SECURITY_PERSONALIZATION = 0x14,   /* 0001 0100 Security check (personalization lock) */
    MMI_POWER_ON_WELCOME = 0x20,                    /* 0010 0000 Welcome screen */
    MMI_POWER_ON_APHORISM,                          /* 0010 0001 Aphorism screen */
    MMI_POWER_ON_NW_SEARCHING = 0x40,               /* 0100 0000 Network searching screen */
    MMI_POWER_ON_IDLE = 0x80                        /* 1000 0000 Idle screen */
} POWERONMMISTATUS;

typedef enum
{
    MMI_SIM_STATUS_INVALID = 0x01,          /* xxxx xxx1 invalid SIM */
    MMI_SIM_STATUS_NOT_INSERT = 0x02,       /* xxxx xx1x SIM not inserted */
    MMI_SIM_STATUS_REFRESH = 0x04,          /* xxxx x1xx SIM refresh */
    MMI_SIM_STATUS_SECURITY_CHECK = 0x08,   /* xxxx 1xxx SIM need to check security after power on animation */
    MMI_SIM_STATUS_FAILURE_RSP = 0x10,      /* xxx1 xxxx SIM failure response received */
    MMI_SIM_STATUS_ROAMING = 0x20,          /* xx1x xxxx Roaming */
#ifdef __MMI_SIMAP_SUPPORT__
    MMI_SIM_STATUS_BT_ACCESS = 0x40,
#endif
    MMI_SIM_STATUS_3G = 0x80                /* 1xxx xxxx 3G SIM (reserved) */
} POWERONSIMSTATUS;                         /* x means don't care bit */

typedef enum
{
    MMI_NW_STATUS_NETWORK_FLAG = 0x01,  /* xxxx xxx1 full service or searching timeout */
    MMI_NW_STATUS_REG_FAILED = 0x02,    /* xxxx xx1x registration failed */
    MMI_NW_STATUS_FLIGHT_MODE = 0x04,   /* xxxx x1xx flight mode is activated */
    MMI_NW_STATUS_PLMNSEL_MODE = 0x08,  /* xxxx 1xxx manual PLMN selection mode */
    MMI_NW_STATUS_WCDMA_ONLY = 0x10     /* xxx1 xxxx only allow to camp on WCDMA networks */
} POWERONNWSTATUS;                      /* x means don't care bit */

typedef enum
{
    MMI_POWER_OFF_DEFAULT,                          /* 0000 0000 */
    MMI_POWER_OFF_ANIMATION = 0x08,                 /* 0000 1000 */
    MMI_POWER_OFF_ANIMATION_NW_DETACH = 0x09,       /* 0000 1xx1 */
    MMI_POWER_OFF_ANIMATION_WAP_DETACH = 0x0A,      /* 0000 1x1x */
    MMI_POWER_OFF_ANIMATION_AUDIO_FINISH = 0x0C,    /* 0000 11xx */
    MMI_POWER_OFF_QUIT = 0x10
} POWEROFFMMISTATUS;                                /* x means don't care bit */

/* end, diamond */

typedef struct _plmn_info
{
    U32 plmn_bcd;
    U16 string_index;
} PLMNINFO;

#endif /* __SIM_DETECTION_DEF_H__ */ 

