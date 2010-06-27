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
 * EventsDef.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for event handler, screen history and interrupt event queue.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _EVENTSDEF_H
#define _EVENTSDEF_H

#ifndef __MMI_FEATURES__
#error "MMI_features.h should be included before EventsDef.h"
#endif 

/***************************************************************************** 
* Define
*****************************************************************************/
#if defined (__MMI_DUAL_SIM__) || defined (__MMI_DUAL_SIM_SINGLE_CALL__)
    #define MAX_SLAVE_PROTOCOL_EVENT	450         /* max number of events (protocol, timer & hardware) */
#endif /* __MMI_DUAL_SIM__ */

#ifdef OBIGO_Q05A
    #define MAX_PROTOCOL_EVENT 700  /* max number of events (protocol, timer & hardware) */
#else 
    #if defined(__MMI_BT_SUPPORT__) || defined(__MMI_IMPS__)
        #define MAX_PROTOCOL_EVENT 700  /* max number of events (protocol, timer & hardware) */
    #else /* #if defined(__MMI_BT_SUPPORT__) || defined(__MMI_IMPS__) */ 
        #if (!defined(LOW_COST_SUPPORT)) || defined(__MMI_GPRS_FEATURES__)
            #define MAX_PROTOCOL_EVENT	450         /* max number of events (protocol, timer & hardware) */
        #else
            #define MAX_PROTOCOL_EVENT	250         /* max number of events (protocol, timer & hardware) */
        #endif
    #endif /* #if defined(__MMI_BT_SUPPORT__) || defined(__MMI_IMPS__) */ 
#endif /* #ifdef OBIGO_Q05A */

#if !defined(LOW_COST_SUPPORT)
    #define MAX_INTERRUPT_EVENT	30       /* max number of interrupt events (protocol, timer & hardware) */
#else
    #define MAX_INTERRUPT_EVENT	20       /* max number of interrupt events (protocol, timer & hardware) */
#endif

#if !defined(LOW_COST_SUPPORT)
    #define MAX_HISTORY		50
#else
    #define MAX_HISTORY		30
#endif

    #define  MIN_HISTORY    0

/***************************************************************************** 
* Typedef 
*****************************************************************************/
typedef enum
{
    /* Idiograhpic interrupt event */
    MMI_FRM_INT_CLAM_OPEN =          0x00000001,
    MMI_FRM_INT_CLAM_CLOSE =         0x00000002,
    MMI_FRM_INT_AUDIO_PLAY_FINISH =  0x00000004,
    /* Battery interruption events */
    MMI_FRM_INT_CHARGER_IN =         0x00000008,
    MMI_FRM_INT_CHARGER_OUT =        0x00000010,
    MMI_FRM_INT_CHARGE_COMPLETE =    0x00000020,
    MMI_FRM_INT_USB_CHARGER_IN =     0x00000040,
    MMI_FRM_INT_USB_CHARGER_OUT =    0x00000080,
    MMI_FRM_INT_USB_NO_CHARGER_IN =  0x00000100,
    MMI_FRM_INT_USB_NO_CHARGER_OUT = 0x00000200,
    /* Gpio interruption events */
    MMI_FRM_INT_EARPHONE_PLUG_IN =   0x00000400,
    MMI_FRM_INT_EARPHONE_PLUG_OUT =  0x00000800,
    /* SMS interruption events */
    MMI_FRM_INT_SMS_DELIVER =        0x00001000,
    MMI_FRM_INT_SMS_STATUS_REPORT =  0x00002000,
    MMI_FRM_INT_SMS_MSG_WAITING =    0x00004000,
    MMI_FRM_INT_SMS_APP_DATA =       0x00008000,   
    /* File manager card interruption events */
    MMI_FRM_INT_FMGR_CARD_PLUG_IN =  0x00010000,
    MMI_FRM_INT_FMGR_CARD_PLUG_OUT = 0x00020000,
	/* Incoming call */
	MMI_FRM_INT_VOIP_CALL_RING = 	 0x00040000,
	MMI_FRM_INT_CC_CALL_RING = 		 0x00080000,
    /* MMS interruption event */
    MMI_FRM_INT_MMS =                0x40000000,    /* Because enum's default data type is signed int, we don't use the 31th. bit */
    /* BT interruption event */
    MMI_FRM_INT_BT =                 0x20000000,

    /* Interrupt event group */
    MMI_FRM_INT_CLAM =           MMI_FRM_INT_CLAM_OPEN | MMI_FRM_INT_CLAM_CLOSE,                                        /* 0x00000003 */
    MMI_FRM_INT_AUDIO_PLAY =     MMI_FRM_INT_AUDIO_PLAY_FINISH,
    MMI_FRM_INT_CHARGER =        MMI_FRM_INT_CHARGER_IN | MMI_FRM_INT_CHARGER_OUT | MMI_FRM_INT_CHARGE_COMPLETE,        /* 0x00000018 */
    MMI_FRM_INT_USB_CHARGER =    MMI_FRM_INT_USB_CHARGER_IN | MMI_FRM_INT_USB_CHARGER_OUT,                              /* 0x000000c0 */
    MMI_FRM_INT_USB_NO_CHARGER = MMI_FRM_INT_USB_NO_CHARGER_IN | MMI_FRM_INT_USB_NO_CHARGER_OUT,                        /* 0x00000300 */
    MMI_FRM_INT_EARPHONE =       MMI_FRM_INT_EARPHONE_PLUG_IN | MMI_FRM_INT_EARPHONE_PLUG_OUT,                          /* 0x00000c00 */
    MMI_FRM_INT_SMS =            MMI_FRM_INT_SMS_DELIVER | MMI_FRM_INT_SMS_STATUS_REPORT | MMI_FRM_INT_SMS_MSG_WAITING, /* 0x00007000 */
    MMI_FRM_INT_FMGR_CARD =      MMI_FRM_INT_FMGR_CARD_PLUG_IN | MMI_FRM_INT_FMGR_CARD_PLUG_OUT,                        /* 0x00018000 */
    MMI_FRM_INT_WAP_MMS =        MMI_FRM_INT_MMS,
    MMI_FRM_INT_BT_TASK =        MMI_FRM_INT_BT,

    /* Common interrupt events boundary */
    MMI_FRM_COMMON_INT_BEGIN =   MMI_FRM_INT_CLAM_OPEN,
    MMI_FRM_COMMON_INT_END =     MMI_FRM_INT_FMGR_CARD_PLUG_OUT,
    
    /* Interrupt events category */
    MMI_FRM_INT_GPIO =           MMI_FRM_INT_CLAM | MMI_FRM_INT_EARPHONE,
    MMI_FRM_INT_BATTERY =        MMI_FRM_INT_CHARGER | MMI_FRM_INT_USB_CHARGER | MMI_FRM_INT_USB_NO_CHARGER,
    /* Non mmi task interrupt events can't be blocked like common interrupt events for its occurrence is not accompany with the message */
    MMI_FRM_INT_NON_MMI_TASK_EVENTS =   MMI_FRM_INT_WAP_MMS | MMI_FRM_INT_BT_TASK,
    MMI_FRM_INT_TOTAL_INTERRUPT_EVENT = MMI_FRM_INT_GPIO | MMI_FRM_INT_BATTERY | MMI_FRM_INT_WAP_MMS | MMI_FRM_INT_FMGR_CARD | MMI_FRM_INT_AUDIO_PLAY_FINISH | MMI_FRM_INT_SMS,
    /* All the interrupt events which could invoke popup screen */
    MMI_FRM_INT_COMMON_INTERRUPT_EVENT = MMI_FRM_INT_EARPHONE | MMI_FRM_INT_BATTERY | MMI_FRM_INT_FMGR_CARD | MMI_FRM_INT_SMS | MMI_FRM_INT_WAP_MMS | MMI_FRM_INT_BT_TASK

} mmi_frm_int_event_type;

typedef U8(*interrupt_event_hdlr)(mmi_frm_int_event_type);

/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/

#endif /* _EVENTSDEF_H */ 

