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
 *  CallManagementStruct.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**************************************************************

   FILENAME : CallManagementStruct.h

   PURPOSE     : Call Management application

   REMARKS     : nil

   AUTHOR      : Subramanya BG 

   DATE     : Nov 11,02

**************************************************************/
#ifdef __MMI_UCM__

#ifndef _PIXCOM_CALLMANAGEMENT_STRUCT_H
#define _PIXCOM_CALLMANAGEMENT_STRUCT_H

#include "L4Dr.h"
#include "DateTimeType.h"
#include "PhoneBookTypes.h"

#define MAX_CALLS          7
#define MAX_HOLD           5
#define CM_NOTIFY_TIMEOUT     UI_POPUP_NOTIFYDURATION_TIME_2000 /* typical notify timeout for CM */
#define CM_AUTOANSWER_NOTIFY_TIMEOUT      2000  /* typical notify timeout for CM */
#define CM_CCBS_NOTIFY_TIMEOUT      10000       /* ccbs notify timeout for CM */
#define CM_WAITFORSS_TIMEOUT  1000

#define MAX_CM_SCREEN_DIGITS_ANYKEY 20  /* Idle screen digits */
#define MAX_CM_SCREEN_DIGITS  13        /* Idle screen digits */

#define CM_HANGUP_REQUESTED      0x01
#define CM_HOLD_REQUESTED     0x02
#define CM_RETRIEVE_REQUESTED 0x04
#define CM_SWAP_REQUESTED     0x08
#define CM_CONF_REQUESTED     0x10
#define CM_SPLIT_REQUESTED    0x20
#define CM_ECT_REQUESTED      0x40

#ifdef MMI_ON_HARDWARE_P
#define CM_VOICE_CALL CSMCC_VOICE_CALL
#define CM_AUX_VOICE_CALL CSMCC_AUX_VOICE_CALL
#define CM_DATA_CALL CSMCC_DATA_CALL
#define CM_CSD_CALL CSMCC_CSD_CALL
#else /* MMI_ON_HARDWARE_P */ 
#define CM_VOICE_CALL 1
#define CM_DATA_CALL 2
#define CM_CSD_CALL 3
#define CM_AUX_VOICE_CALL 4
#endif /* MMI_ON_HARDWARE_P */ 

#ifdef MMI_ON_HARDWARE_P        /* This is incremented by one to accomodate '+' sign */
#define MAX_DIGIT          MAX_CC_ADDR_LEN      /* Max digits in DTMF Buf */
#define MAX_NUMBER         ((MAX_CC_ADDR_LEN+1)*ENCODING_LENGTH)
#define MAX_CM_NUMBER      ((MAX_CC_ADDR_LEN + 20 + 1) * ENCODING_LENGTH)
#define MAX_NAME        ((MAX_PB_NAME_LENGTH+1)*ENCODING_LENGTH)
#else /* MMI_ON_HARDWARE_P */ /* This is incremented to accomodate '+' sign and NULL character */
#define MAX_DIGIT          40+1 /* Max digits in DTMF Buf */
#define MAX_NUMBER         ((40+1+1)*ENCODING_LENGTH)
#define MAX_CM_NUMBER      ((40+20+1+1) * ENCODING_LENGTH)
#define MAX_NAME        40
#endif /* MMI_ON_HARDWARE_P */ 

#define MAX_DTMFBUF_DIGITS 40

typedef S16 CM_CALL_HANDLE;

typedef enum CmEventTypes
{
    CM_PS_CALL_INCOMING,
    CM_PS_INCOMING_CALL_CONNECTED,
    CM_PS_INCOMING_CALL_REJECTED,
    CM_PS_INCOMING_CALL_DROPPED,
    CM_PS_ALL_ACTIVE_CALL_DISCONNECTED,
    CM_PS_ACTIVE_CALL_DISCONNECTED,
    CM_PS_ACTIVE_CALL_HELD,
    CM_PS_HELD_CALL_ACTIVE,
    CM_PS_NWK_CALL_DROP,
    CM_PS_AOC_INDICATION,
    CM_PS_CALLCONNECTED,    /* associated data structure is the int(callIndex). */
    CM_PS_HANGUPSUC,        /* associated data structure is the int(callIndex). */
    CM_PS_HANGUPALLSUC,     /* associated data is void */
    CM_PS_HANGUPALLACTSUC,  /* associated data is void */
    CM_PS_HANGUPALLHLDSUC,  /* associated data is void */
    CM_PS_HOLDSUC,          /* associated data is void */
    CM_PS_RETRIEVESUC,      /* associated data is void */
    CM_PS_SWAPSUC,          /* associated data is void */
    CM_PS_CONFSUC,          /* associated data is void */
    CM_PS_SPLITSUC,         /* associated data structure is the int(callIndex). */
    CM_PS_ECT_SUC,
    CM_PS_SPEECH_IND,
    CM_PS_SHOW_OUTGOING_CALL_SCREEN,
    CM_PS_SHOW_REQUESTING_CALL_SCREEN,
    CM_PS_CALL_WAIT,
    CM_PS_SS_EVENT,
    CM_PS_INCOMING_CALL_DEFLECT,
    CM_PS_CCBS_ACTIVATE,
    CM_PS_ACTIVATED_CCBS,
    CM_PS_CCBS_INVOKE,
    CM_PS_CCBS_INVOKE_DIAL,
    CM_PS_CCBS_INVOKE_REJECT,
    CM_PS_CONFIRM_DTMF_STRING,
    CM_PS_USSD_RECVD,

    CM_KB_OUTGOINGCALL,
    CM_KB_HOLDREQ,
    CM_KB_RETRIEVEREQ,
    CM_KB_SWAPREQ,
    CM_KB_CONFREQ,
    CM_KB_SPLITREQ,
    CM_KB_ECT_REQ,
    CM_KB_HANGUPREQ,
    CM_KB_HANGUPALLREQ,
    CM_KB_HANGUPALLACTREQ,
    CM_KB_HANGUPALLHLDREQ,
    CM_KB_HANG_ALL_CALLS,

    CM_KB_INCOMING_CALL_ACCEPT,
    CM_KB_INCOMING_CALL_REJECT,
    CM_KB_END_ALL_ACTIVE_RETRIEVE_HELD,
    CM_KB_END_ACTIVE_ACCEPT_INCOMING,
    CM_KB_CALL_DEFLECT_REQ
} CM_EVENT_TYPES;

typedef enum ACTION_RESULT
{
    CM_CALL_SUCCESS,
    CM_CALL_FAILURE,
    CM_NO_INCOMING
} ACTION_RESULT;

typedef enum CHLD_REQ_ACTION
{
    CM_ACTION_NONE = 0,
    CM_HANGUPALL_REQ_SENT,
    CM_HANGUPALLACTIVE_REQ_SENT,
    CM_HANGUPALLHLD_REQ_SENT,
    CM_ENDSELECTIVE_REQ_SENT,
    CM_UDUB_REQ_SENT
} CHLD_REQ_ACTION;

typedef enum CallState
{
    CM_IDLE_STATE = 0,
    CM_OUTGOING_STATE,
    CM_INCOMING_STATE,
    CM_ACTIVE_STATE,
    CM_HOLD_STATE,
    CM_DISCONNECTING_STATE, /* Start by Julia: Drop call refinement */
    CM_STATE_UNKNOWN
} CALL_STATE;

typedef enum CallDir
{
    CM_CALL_NONE = 0,
    CM_CALL_MO,
    CM_CALL_MT,
    CM_CALL_MO_STK
} CALL_DIR;

typedef struct _inc_callinfo
{
    U8 num[MAX_NUMBER]; /* for storing original number in MO call */
    /* MTK amanda change 1129 for Call Divert SS string */
    U8 number[MAX_CM_NUMBER];
    //U8                         pbNumber[MAX_NUMBER];   
    // Start by Julia
#ifdef __MMI_CM_BLACK_LIST__
    pBOOL block_flag;   /* indicate if the number is blocked, true means blocked and false means not blocked */
#endif 
    /* End by Julia */
    U8 pBname[MAX_NAME];
    U8 CNAPname[MAX_NAME];
    U8 name_dcs;
    CALL_STATE prev_state;
    CALL_STATE curr_state;
    MYTIME start_time;
    MYTIME end_time;
    CALL_DIR orgination_flag;
    U8 status_flag;
    U8 call_type;
    CM_CALL_HANDLE call_handle;
    CM_CALL_HANDLE group_id;
} CALL_INFO;

typedef struct _outgoingcall
{
    /* MTK amanda change 1129 for Call Divert SS string */
    U8 Number[MAX_CM_NUMBER];   /* Calling Number. */
    PS8 Name;
    U8 call_type;
#ifdef __MMI_USSD_REPLY_UCS2__
    BOOL  bIsUcs2;
#endif /*__MMI_USSD_REPLY_UCS2__*/
} OUTGOING_CALL;

typedef struct l4_result
{
    U8 result;
    U16 cause;
} RESULT;

typedef struct _ussdData
{
    PU8 data;
    U16 length;
} USSD_DATA;

typedef struct _StrHandle
{
    U8 result;
    U16 cause;
    CM_CALL_HANDLE handle;
} STR_HANDLE;

typedef struct _ccmValue
{
    U32 ccm;
    U8 warning;
} CCM_VALUE;

typedef struct IncomingCall
{
    U8 Number[MAX_NUMBER];
    U8 callType;
    S16 callHandle;
} IncomingCall;

typedef struct TimeAndIndex
{
    MYTIME time;
    U8 index;
} TIMEANDINDEX;
#endif /* _PIXCOM_CALLMANAGEMENT_STRUCT_H */ 
#endif /* __MMI_UCM__ */
