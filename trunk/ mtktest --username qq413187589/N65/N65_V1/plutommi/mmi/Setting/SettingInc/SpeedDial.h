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
 * SpeedDial.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for Speed dial applicaion
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
/**************************************************************

   FILENAME : SpeedDial.h

   PURPOSE     : Speeddial application 


   REMARKS     : nil

   AUTHOR      : nil

   DATE     : 

**************************************************************/

#ifndef _SPEEDDIAL_H
#define _SPEEDDIAL_H
#include "custom_mmi_default_value.h"   /* NVRAM_REVISE */

#define MAX_SPEED_DIAL_NUMBER  8

#ifdef __MMI_PHB_MAX_NAME_60__
#define NVRAM_SPEEDDIAL_RECORD_SIZE 1680
#else 
#define NVRAM_SPEEDDIAL_RECORD_SIZE 1200
#endif 

#if 0   /* NVRAM_REVISE */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ /* NVRAM_REVISE */

extern void HighlightPhbSpeedDialStatus(void);
extern void HintPhbSpeedDial(U16);
extern void EntryPhbSpeedDialStatus(void);
extern void HighlightPhbSpeedDial(void);
extern void EntryPhbSpeedDial(void);
extern void ExitPhbSpeedDial(void);

extern void PhbInitSpeedDial(void);
extern void HighlightPhbSpeedDialSetNum(void);
extern void EntryPhbSpeedDialSetNum(void);

/* void ExitScrSpeedDialMain(void); */
extern void HighlightPhbSpeedDialSetNumOptionEdit(void);
extern void HighlightPhbSpeedDialSetNumOptionDel(void);
extern void EntryPhbSpeedDialSetNumOption(void);
extern void EntryPhbSpeedDialSetNumDelConfirm(void);
extern void PhbReadSpeedDialNVRAM(void);
extern void PhbSetSpeedDialFormList(void);
extern void PhbDelSpeedDialFromList(void);
extern void PhbSpeedDailEntryHiliteHandler(S32);
extern void PhbMakeCallFromSpeedDial(void);
extern PS8 PhbGetSpeedDialNum(U16);
extern void ShowSpeedDial(void);
extern void PhbSetSpeedDialPhbIndex(U16);
extern void PhbGetSpeedDialInfo(void);
extern void PhbGetSpeedDialInfo_Ext(void);
extern void PhbGetSpeedDialPhbIndexReq(U8, U16, U8);
extern void PhbGetSpeedDialPhbIndexRsp(void *);
extern MMI_BOOL PhbGetSpeedDialStatus(void);
extern void PhbSpeedDialLookupNumberFromList(U16 speed_index);

#endif /* _SPEEDDIAL_H */ 

