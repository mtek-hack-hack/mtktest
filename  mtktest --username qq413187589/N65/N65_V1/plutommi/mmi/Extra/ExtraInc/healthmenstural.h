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
 * HealthMenstural.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file defines constant, enum value, structure, and function prototypes for Menstrual application.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _MMI_HEALTHMENSTRUAL_H
#define _MMI_HEALTHMENSTRUAL_H

#include "MMI_features.h"
#if defined(__MMI_MENSTRUAL__)
#include "MMIDataType.h"
#include "DateTimeType.h"
#include "HealthemnstrurealResDef.h"
/* 
 * Define
 */

/* 
 * Typedef 
 */
typedef enum
{
    MENS_INLINE_DATE_CAP = 0,
    MEMS_INLINE_DATE,
    MEMS_INLINE_PERIOD_CAP,
    MEMS_INLINE_PERIOD,
    MEMS_INLINE_NUM_DAYS,
    MEMS_INLINE_TOTAL
} MENS_INLINE_ENUM;

typedef enum
{
    COLOR_NONE = 0,
    RED_COLOR,
    ORANGE_COLOR,
    YELLOW_COLOR
} MENS_COLOR_EMUM;

typedef enum
{
    MENS_ERR_NONE = 0,
    MENS_ERR_DATE,
    MENS_ERR_PERIOD
} MENS_ERR_MSG_ENUM;

/* 
 * Extern Global Variable
 */

/* 
 * Extern Global Function
 */

extern void MensInit(void);
extern void MensDeInit(void);

extern void HighlightMensApp(void);
extern void EntryMensWelcome(void);
extern void EntryMensInput(void);
extern void ExitMensInput(void);
extern void MensPreEntryInput(void);

/* inline editor */
extern void HighlightMensInputItem(S32 item_index);
extern void MensDisplayResult(void);
extern U8 MensValidateInput(void);
extern void MensPreEntryResult(void);
extern void EntryMensResult(void);
extern void HighlightMensNevigeteDate(S32 index);
extern void MensGoToPreviousDay(void);
extern void MensGoToNextDay(void);
extern void MensGoToPreviousWeek(void);
extern void MensGoToNextWeek(void);
extern void MensGoToPreviousMonth(void);
extern void MensGoToNextMonth(void);
extern void MensDisplayBoundaryPopup(void);
extern S16 MensGetDaysDifference(MYTIME *t1, MYTIME *t2);

extern void EntryMensProbability(void);

extern FLOAT MensGetPregancyProb(S16 DiffDay, S16 AvgPeriod);
extern MENS_COLOR_EMUM MensGetDisplayColor(S16 DiffDay, U8 AvgPeriod);

#ifdef __MMI_CALENDAR_V2__
extern void mmi_mens_construct_cell_info(void);
extern MMI_BOOL mmi_mens_highlight(U32 row, U32 column);
extern MMI_BOOL mmi_mens_left_out_of_boundary(U32 row, U32 column);
extern MMI_BOOL mmi_mens_right_out_of_boundary(U32 row, U32 column);
extern MMI_BOOL mmi_mens_up_out_of_boundary(U32 row, U32 column);
extern MMI_BOOL mmi_mens_down_out_of_boundary(U32 row, U32 column);    
extern MMI_BOOL mmi_mens_up_side_key(U32 row, U32 column);
extern MMI_BOOL mmi_mens_down_side_key(U32 row, U32 column);
extern void mmi_mens_set_content(void);

#endif /*__MMI_CALENDAR_V2__*/

#endif /* defined(__MMI_MENSTRUAL__) */ // #if defined(__MMI_MENSTRUAL__)
#endif /* _MMI_HEALTHMENSTRUAL_H */ // #ifndef _MMI_HEALTHMENSTRUAL_H

