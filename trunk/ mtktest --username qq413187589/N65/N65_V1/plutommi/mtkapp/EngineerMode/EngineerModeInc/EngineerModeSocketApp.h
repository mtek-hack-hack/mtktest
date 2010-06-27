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
 * EngineerModeSocketApp.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for implement the engineer mode socket application
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/* MTK Add Robin 1001 for saperate MMI feature by project */
#include "MMI_features.h"
/* MTK End */

#if (defined(__MMI_ENGINEER_MODE__) && defined(__MMI_GPRS_PING_APP__) && defined(__TCPIP__) && defined(__PS_SERVICE__))

/* Defination */
#define INVAILD_PING_PARAM    -1
#define EM_IPADDRES_LEN      (16 * ENCODING_LENGTH)
#define EM_MAX_INLINE_LEN  (8 * ENCODING_LENGTH)
#define EM_MAX_INLINE_ITEM_LIST 8

/* Type Defination  */
typedef enum
{

    EM_PING_TIMEOUT = 0,
    EM_PING_START,
    EM_PING_RECV,
    EM_PING_FIN
} EM_PING_SCR_UPDATE_CAUSE;

typedef enum
{

    EM_GPRS_PING_IP_STR = 0,
    EM_GPRS_PING_IP,

    EM_GPRS_PING_SIZE_STR,
    EM_GPRS_PING_SIZE,

    EM_GPRS_PING_COUNT_STR,
    EM_GPRS_PING_COUNT,

    EM_GPRS_PING_TIMEOUT_STR,
    EM_GPRS_PING_TIMEOUT
} DATA_ACCOUNT_INLINE;

/* Function declaration */
extern void InitEngineerModeSocketApp(void);
extern void HighlightEmSocketPing(void);
extern void EntryEmSockePingMenu(void);
extern void ExitEmSocketPingMenu(void);
extern void EmPingInitInlinParam(void);
extern void EmPingFillInlineStruct(void);
extern void EmPingPreparedIPAddressString(U8 *string_buffer, U8 *IP1, U8 *IP2, U8 *IP3, U8 *IP4);
extern void EmPingStart(S8 *AscAddr);
extern void EmPingStop(void);
extern void EmPingSocNotify(void *inMsg);
extern void EmSocketAppPingInit(void);
extern void EmPingUpdateScreen(U8 cause, S32 duration);
extern void ExitEmPingRspPage(void);
extern void EntryEmPingMenuParamError(void);
extern void EmPingCheckParam(void);

extern void EmPingTimeourHandler(void);
extern kal_bool EmPingRecvPkt(void);
extern void EmPingSendPkt(void);
extern void EmPingStartAct(kal_char *serv_addr);
extern void EmPingStopTimer(void);
extern void EmPingStartTimer(kal_uint16 seqNo);

#endif /* (defined(__MMI_ENGINEER_MODE__) && defined(__MMI_GPRS_PING_APP__) && defined(__TCPIP__) && defined(__PS_SERVICE__)) */ 

