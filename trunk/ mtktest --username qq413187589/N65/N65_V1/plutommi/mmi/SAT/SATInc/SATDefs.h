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
 * SATDefs.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   SIM application toolkit related functions
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

/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

 /**************************************************************

   FILENAME : SATDefs.h

   PURPOSE     : SAT application 

   REMARKS     : nil

   AUTHOR      : NEERAJ SHARMA

   DATE     : Mar 24,03

**************************************************************/

#ifndef __SAT_DEF_H__
#define __SAT_DEF_H__

#include "SATResDef.h"

#define SAT_MESSAGE_WAIT_TIMER_DURATION 15000   /* diamond, 2005/06/15 modified for DRAGONFLY_DEMO SCR #1011 */
#define SAT_NO_RESPONSE_TIMER_DURATION  180000
#define SAT_DISPLAY_TEXT_DELAY_DURATION 5000    /* diamond, 2005/07/11 duration for DISPLAY TEXT "clear after a delay" case */
#define SAT_HELP_TIMER_DURATION         90000

#define MAX_ICON_SUPPORT                15      /* diamond, 2006/05/22 Support 15 SAT icons */
#define SAT_BASIC_IMAGE                 0x11
#define SAT_COLOR_IMAGE                 0x21
#define SAT_COLOR_IMAGE_TRANSPARENCY    0x22

#define SAT_LANG_CHINESE                "zh"
#define SAT_LANG_ENGLISH                "en"

#define INPUT_TYPE_YES_NO               200

typedef enum
{
    SAT_ICON_SELF_EX = 0x00,
    SAT_ICON_NOT_SELF_EX
} SAT_ICON_SELFEX_ATTR;

typedef enum
{
    SAT_CALL_DISCONNECT_BEFORE_CONNECT = 0x00,
    SAT_CALL_DISCONNECT_AFTER_CONNECT
} SAT_CALL_EXIT_CAUSE;

typedef enum
{
    SAT_NONE_CMD = 0x00,
    SAT_SELECT_ITEM_CMD,
    SAT_DISPLAY_TEXT_CMD,
    SAT_GET_INPUT,
    SAT_GET_INKEY,
    SAT_CALL_SETUP_CMD,
    SAT_SEND_SMS_CMD,
    SAT_SEND_SS_CMD,
    SAT_SEND_USSD_CMD,
    SAT_PLAY_TONE_CMD,
    SAT_LAUNCH_BROWSER_CMD,
    SAT_SEND_DTMF_CMD,
    SAT_IMAGE_IDLE_CMD,
    SAT_IMAGE_READLEN_CMD,
    SAT_IMAGE_READINST_CMD,
    SAT_IMAGE_READDATA_CMD,
#ifdef __SATCE__
    SAT_OPEN_CHANNEL_CMD,
    SAT_CLOSE_CHANNEL_CMD,
    SAT_SEND_DATA_CMD,
    SAT_RECEIVE_DATA_CMD,
#endif /* __SATCE__ */ 
    SAT_CMD_STATE_MAX
} SAT_CMD_STATE;

#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
typedef enum
{
    SAT_CMD_NONE = 0,
    SAT_CMD_SIM1 = 1,
    SAT_CMD_SIM2 = 2
} SAT_CMD_FROM_SIM;
#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */

typedef enum
{
    SAT_NEXT_ACTION_NONE = 0x00,
    SAT_NEXT_ACTION_REFRESH = 0x01,
    SAT_NEXT_ACTION_MORE_TIME = 0x02,
    SAT_NEXT_ACTION_POLL_INTERVAL = 0x03,
    SAT_NEXT_ACTION_POLLING_OFF = 0x04,
    SAT_NEXT_ACTION_SETUP_EVENT_LIST = 0x05,
    SAT_NEXT_ACTION_SETUP_CALL = 0x10,
    SAT_NEXT_ACTION_SEND_SS = 0x11,
    SAT_NEXT_ACTION_SEND_USSD = 0x12,
    SAT_NEXT_ACTION_SEND_SMS = 0x13,
    SAT_NEXT_ACTION_SEND_DTMF = 0x14,
    SAT_NEXT_ACTION_LAUNCH_BROWSER = 0x15,
    SAT_NEXT_ACTION_PLAY_TONE = 0x20,
    SAT_NEXT_ACTION_DISPLAY_TEXT = 0x21,
    SAT_NEXT_ACTION_GET_INKEY = 0x22,
    SAT_NEXT_ACTION_GET_INPUT = 0x23,
    SAT_NEXT_ACTION_SELECT_ITEM = 0x24,
    SAT_NEXT_ACTION_SETUP_MENU = 0x25,
    SAT_NEXT_ACTION_PROVIDE_LOCAL_INFO = 0x26,
    SAT_NEXT_ACTION_TIMER_MANAGEMENT = 0x27,
    SAT_NEXT_ACTION_SETUP_IDLE_TEXT = 0x28,
    SAT_NEXT_ACTION_PERFORM_CARD_APDU = 0x30,
    SAT_NEXT_ACTION_POWER_ON_CARD = 0x31,
    SAT_NEXT_ACTION_POWER_OFF_CARD = 0x32,
    SAT_NEXT_ACTION_GET_READER_STATUS = 0x33,
    SAT_NEXT_ACTION_RUN_AT_COMMAND = 0x34,
    SAT_NEXT_ACTION_LANGUAGE_NOTIFICATION = 0x35,
    SAT_NEXT_ACTION_OPEN_CHANNEL = 0x40,
    SAT_NEXT_ACTION_CLOSE_CHANNEL = 0x41,
    SAT_NEXT_ACTION_RECEIVE_DATA = 0x42,
    SAT_NEXT_ACTION_SEND_DATA = 0x43,
    SAT_NEXT_ACTION_GET_CHANNEL_STATUS = 0x44,
    SAT_NEXT_ACTION_RESERVED_FOR_TIA = 0x60,
    SAT_NEXT_ACTION_END_SESSION = 0x81
} SAT_NEXT_ACTION_LIST;

typedef enum
{
    SAT_PRI_NORMAL = 0,
    SAT_PRI_HIGH = 1
} SAT_DSPL_PRIORITY;

typedef enum
{
    SAT_CLEAR_AFTER_DELAY = 0,
    SAT_CLEAR_BY_USR = 1
} SAT_CLEAR_TEXT;

#endif /* __SAT_DEF_H__ */ 

