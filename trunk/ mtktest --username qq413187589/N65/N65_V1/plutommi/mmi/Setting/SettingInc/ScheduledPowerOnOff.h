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
 * SchedulePowerOnOff.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file is defines constant, structrue, and function prototypes for SPOF application.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
/*
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/**************************************************************

   FILENAME :ScheduledPowerOnOff.h

   PURPOSE     : nil

   REMARKS     : nil

   AUTHOR      : Gautam Saluja

   DATE     : 

**************************************************************/
/* ScheduledPowerOnOff.h */
#ifndef _MMI_SCHEDULEPOWEROFOFF_H
#define _MMI_SCHEDULEPOWEROFOFF_H

#include "AlarmFrameWorkProt.h"
#include "AlarmDef.h"
#include "ScheduledPowerOnOffResDef.h"
/* 
 * Define
 */
#define SPOF_NUM_STATES_ONOFF 2
#define SPOF_NUM_STATES_ACTINACT 2
#define NUM_ITEM_EDIT_SCREEN 4
#define SPOF_DISABLE 0
#define SPOF_ENABLE 1
#define SPOF_POWERON 0
#define SPOF_POWEROFF 1
/* 
 * Typedef 
 */

typedef struct
{
    S32 CurrHiliteOnOff;
    S32 CurrHiliteActivation;
    S8 *ActStateList[SPOF_NUM_STATES_ACTINACT];
    S8 *OnOffStateList[SPOF_NUM_STATES_ONOFF];
    spof_nvram_struct SPOFList[NUM_OF_SPOF];
    S8 HourBuf[(HOUR_LENGTH + 1) *ENCODING_LENGTH];
    S8 MinBuf[(MINUTE_LENGTH + 1) *ENCODING_LENGTH];
    U8 IsRestoreDefault;
    U8 CurrItem;
} spof_context_struct;

/*
 * Local function
 */
extern void ExitPowerOffConfirmation(void);
extern U8 mmi_spof_del_scr_callback(void *p);
extern void SpofStopPowerOffConfirmation(void);
extern void SPOFExpiryTimeCBH(U8 index, MYTIME *alarmTime, U8 *Freq, U8 *WeekDays, MYTIME* preReminder);
extern void SPOFReInitQueueCBH(void);
extern U8 SponPwrOnHandler(U8 sponIndex);
extern U8 SpofPwrOffHandler(U8 index);
extern U8 SpofPwrOnHandler(U8 index);
extern void ExitSpofEdit(void);
extern void EntrySpofEdit(void);
extern void HighlightSpofList(S32 nIndex);
extern void SpofFillInlineEditStruct(void);
extern void SpofSaveData(void);
extern void SpofHandler(U8);
extern void SpofWritetoNvram(void);
extern BOOL SpofIsTimeClash(U8 hour, U8 min);
extern void EntryPowerOffConfirmation(void);

/* 
 * Extern Global Variable
 */
extern spof_context_struct g_spof_cntx;

/* 
 * Extern Global Function
 */

#endif /* _MMI_SCHEDULEPOWEROFOFF_H */ 

