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
 *  FrameworkProt.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Framework function declaration
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef FRAMEWORK_PROT_H
#define FRAMEWORK_PROT_H


/***************************************************************************** 
 * Include header file
 *****************************************************************************/

#include "MMI_features.h"           /* Must include these files for data type */
#include "MMIDataType.h"
#include "L4Dr.h"
#include "FrameworkStruct.h"

/* Theme manager */
#include "ThemeConverter.h"
#include "filemgr.h"                /* Must include this file before ThemeArchiverDef.h */
#include "ThemeArchiverDef.h" 

/* Task */
#include "TaskInit.h"
#include "MMITaskProt.h"

/* History */
#include "HistoryDef.h"
#include "HistoryDcl.h"
#include "SubLCDHistoryDef.h"
#include "SubLCDHistoryDcl.h"

/* Events handling */
#include "EventsDcl.h"


/***************************************************************************** 
* Define
*****************************************************************************/

/* Queue global MACRO */
#define CIRCQ_NODE_SIZE sizeof(MYQUEUE)
#if defined(__MMI_DUAL_SIM_MASTER__)
#define CIRCQ_NO_OF_NODES 130
#else
#define CIRCQ_NO_OF_NODES 65 
#endif

/***************************************************************************** 
* Global Variable
*****************************************************************************/

/* MMITask global data */
extern oslMsgqid mmi_ext_qid; 
extern MMI_BOOL g_keypad_flag;
extern drv_get_key_func keypad_ptr;     
extern U8 gInitAllAppFlag;         
extern U8 gInsertSimAppFlag;

/* History global data */
extern pBOOL IsBackHistory;

/* Event handler global data */
extern U16 maxProtocolEvent;
extern U16 usedProtocolEvent;
extern PseventInfo protocolEventHandler[];      /* array size: MAX_PROTOCOL_EVENT */

#ifdef __MMI_DUAL_SIM__
extern U16 maxSlaveProtocolEvent;
extern U16 usedSlaveProtocolEvent;
extern PseventInfo SlaveProtocolEventHandler[]; /* array size: MAX_SLAVE_PROTOCOL_EVENT */
#endif /* __MMI_DUAL_SIM__ */

/***************************************************************************** 
* Global Function
*****************************************************************************/

/* Timer global function */
extern void EvshedMMITimerHandler(void *dataPtr); 
extern void L4InitTimer(void);

/* Keypad global function */
extern void KeyHandleBeforePWRON(void *paraBuff); 

/* sublcd history */
extern void GoBackSubLCDHistoryInt(void);

/* event handler */
extern void mmi_proc_inject_string(void * in);
extern void mmi_frm_reset_interrupt_event_context(void);


#endif /* FRAMEWORK_PROT_H*/ 

