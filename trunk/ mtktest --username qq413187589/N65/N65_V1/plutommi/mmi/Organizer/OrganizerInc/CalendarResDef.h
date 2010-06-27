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
 *  CalendarResDef.h
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

   FILENAME : CalendarResDef.h

   PURPOSE     : 

   REMARKS     : nil

   AUTHOR      : Sophie Lin

   DATE     : 

**************************************************************/
#ifndef _CALRESDEF_H
#define _CALRESDEF_H

typedef enum
{

    SCR_ID_CLNDR_SCREEN = CAL_BASE + 1,
    SCR_ID_CLNDR_OPTION,
    SCR_ID_CLNDR_JUMP
} SCR_ID_CLNDR_ENUM;

typedef enum
{
    CAL_STRING_LUNAR = CAL_BASE + 1,
    STR_CAL_CHINESE_NO1,    /* do not change the order */
    STR_CAL_CHINESE_NO2,
    STR_CAL_CHINESE_NO3,
    STR_CAL_CHINESE_NO4,
    STR_CAL_CHINESE_NO5,
    STR_CAL_CHINESE_NO6,
    STR_CAL_CHINESE_NO7,
    STR_CAL_CHINESE_NO8,
    STR_CAL_CHINESE_NO9,
    STR_CAL_CHINESE_NO10,
    STR_CAL_CHINESE_NO20,
    STR_CAL_CHINESE_NO30,
    STR_CAL_SOLARTERM1,     /* do not change the order *//* Sligt Cold */
    STR_CAL_SOLARTERM2,
    STR_CAL_SOLARTERM3,
    STR_CAL_SOLARTERM4,
    STR_CAL_SOLARTERM5,
    STR_CAL_SOLARTERM6,
    STR_CAL_SOLARTERM7,
    STR_CAL_SOLARTERM8,
    STR_CAL_SOLARTERM9,
    STR_CAL_SOLARTERM10,
    STR_CAL_SOLARTERM11,
    STR_CAL_SOLARTERM12,
    STR_CAL_SOLARTERM13,
    STR_CAL_SOLARTERM14,
    STR_CAL_SOLARTERM15,
    STR_CAL_SOLARTERM16,
    STR_CAL_SOLARTERM17,
    STR_CAL_SOLARTERM18,
    STR_CAL_SOLARTERM19,
    STR_CAL_SOLARTERM20,
    STR_CAL_SOLARTERM21,
    STR_CAL_SOLARTERM22,
    STR_CAL_SOLARTERM23,
    STR_CAL_SOLARTERM24,
    STR_CAL_ANIMAL1,        /* do not change the order */
    STR_CAL_ANIMAL2,
    STR_CAL_ANIMAL3,
    STR_CAL_ANIMAL4,
    STR_CAL_ANIMAL5,
    STR_CAL_ANIMAL6,
    STR_CAL_ANIMAL7,
    STR_CAL_ANIMAL8,
    STR_CAL_ANIMAL9,
    STR_CAL_ANIMAL10,
    STR_CAL_ANIMAL11,
    STR_CAL_ANIMAL12,
    STR_CAL_KAN1,           /* do not change the order */
    STR_CAL_KAN2,
    STR_CAL_KAN3,
    STR_CAL_KAN4,
    STR_CAL_KAN5,
    STR_CAL_KAN6,
    STR_CAL_KAN7,
    STR_CAL_KAN8,
    STR_CAL_KAN9,
    STR_CAL_KAN10,
    STR_CAL_CHI1,           /* do not change the order */
    STR_CAL_CHI2,
    STR_CAL_CHI3,
    STR_CAL_CHI4,
    STR_CAL_CHI5,
    STR_CAL_CHI6,
    STR_CAL_CHI7,
    STR_CAL_CHI8,
    STR_CAL_CHI9,
    STR_CAL_CHI10,
    STR_CAL_CHI11,
    STR_CAL_CHI12,
    STR_CAL_DIRECTION1,     /* do not change the order */
    STR_CAL_DIRECTION2,
    STR_CAL_DIRECTION3,
    STR_CAL_DIRECTION4,
    STR_CAL_UNFORTUNATE,
    STR_CAL_UNLUCKY,
    STR_CAL_YEAR,
    STR_CAL_MONTH,
    STR_CAL_DAY,
    STR_CLNDR_JUMP_TO,
    STR_CLNDR_DATE,
    STR_CLNDR_WRONG_DATE,
#ifdef __MMI_CALENDAR_V2__
    STR_CLNDR_WEEK_SYMBOL,
    STR_CLNDR_WEEK_SUNDAY,
    STR_CLNDR_WEEK_MONDAY,
    STR_CLNDR_WEEK_TUESDAY,
    STR_CLNDR_WEEK_WEDNESDAY,
    STR_CLNDR_WEEK_THURSDAY,
    STR_CLNDR_WEEK_FRIDAY,
    STR_CLNDR_WEEK_SATURDAY,
    STR_CLNDR_OUT_OF_CALENDAR,
    STR_CLNDR_WEEK_STRING,
#ifdef __MMI_CLNDR_WEEKLY_VIEW_SUPPORT__
    STR_CLNDR_WEEKLY_VIEW,
    STR_CLNDR_MONTHLY_VIEW,
#endif /* __MMI_CLNDR_WEEKLY_VIEW_SUPPORT__ */ 
    STR_CLNDR_ADD_TASK,
    STR_CLNDR_DELETE_TASK,
#endif /* __MMI_CALENDAR_V2__ */ 
#ifdef __MMI_BPP_SUPPORT__
    STR_CLNDR_BPP_PRINT,
    STR_CLNDR_BPP_PREVIEW,
#endif /*__MMI_BPP_SUPPORT__*/
    ORGANIZER_MENU_CALENDER_STRINGID
} STR_ID_CLNDR_ENUM;

typedef enum
{
    CAL_OPTION_IMAGE = CAL_BASE + 1,
    CAL_IMAGE_VIEW,
    CAL_IMAGE_LUNAR,
    IMG_CAL_ON,
    IMG_CAL_OFF,
    MONTH_BLANK_IMAGE,
    ORGANIZER_MENU_CALENDER_IMAGEID,
#ifdef __MMI_CALENDAR_V2__
    IMG_CLNDR_TASK_CLOCK,
    IMG_TOP_UP, /* 072406 new calendar */
    IMG_TOP_DOWN,
    IMG_BOTTOM_UP,
    IMG_BOTTOM_DOWN,
    IMG_HOUR_PLUS_UP,//072406 new calendar
    IMG_HOUR_PLUS_DOWN,
    IMG_HOUR_SUBTRACT_UP,
    IMG_HOUR_SUBTRACT_DOWN,
#ifdef __MMI_CLNDR_ICON_SUPPORT__
    IMG_CLNDR_ICON_REMINDER,
    IMG_CLNDR_ICON_MEETING,
    IMG_CLNDR_ICON_COURSE,
    IMG_CLNDR_ICON_DATE,
    IMG_CLNDR_ICON_CALL,
    IMG_CLNDR_ICON_ANNIVERSIRY,
#endif /* __MMI_CLNDR_ICON_SUPPORT__ */ 
#ifdef __MMI_BIRTHDAY_REMINDER__
    IMG_CLNDR_BIRTHDAY_REMINDER,
#endif    
#endif 
    IMG_CLNDR_TOTAL
} IMG_ID_CLNDR_ENUM;

typedef enum
{
#ifdef __MMI_TODOLIST__
    CLNDR_GOTO_TASK_CAL,
    CLNDR_ADD_TASK,
#endif /* __MMI_TODOLIST__ */ 
    CLNDR_JUMP_TO_DATE,
#ifdef __MMI_CLNDR_WEEKLY_VIEW_SUPPORT__
    CLNDR_VARIED_VIEW,
#endif 
    CLNDR_CAL_TYPE, /* must be last one */
#ifdef __MMI_BPP_SUPPORT__    
    CLNDR_BPP_PRINT,
#endif    
    CLNDR_OPTIONS_TOTAL
} OPTIONS_CLNDR_ENUM;

#endif /* _CALRESDEF_H */ 


