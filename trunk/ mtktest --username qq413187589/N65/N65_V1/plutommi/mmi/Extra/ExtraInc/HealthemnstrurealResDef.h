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
 * HealthMensturalResDef.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file defines resource id for Menstrual application.
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _MMI_HEALTHMENSTRUAL_RESDEF_H
#define _MMI_HEALTHMENSTRUAL_RESDEF_H

#include "MMI_features.h"
#ifdef __MMI_MENSTRUAL__

#include "MMIDataType.h" 

typedef enum
{
    SCR_ID_MENS_WELCOME = HEALTH_MENSTRUAL + 1,
    SCR_ID_MENS_INPUT,
    SCR_ID_MENS_RESULT,
    SCR_ID_MENS_PROB
} SCR_ID_MENS_ENUM;

typedef enum
{
    STR_SCR_HEALTH_MENSIS_CAPTION = HEALTH_MENSTRUAL + 1,
    STR_HEALTH_MENSIS_DATE_CAPTION,
    STR_LAST_DATE,
    STR_DATE_FORMAT_HEALTH_MENSIS,
    STR_AVERAGE_DAYS_HEALTH_MENSIS,
    STR_INVALID_AVERAGE_DAY_MESSAGE,
    STR_SCR_HEALTH_MENSIS_PROBABILITY_CAPTION,
    //STR_AVERAGE_DAYS_HEALTH_NAVIGATE,
    STR_SCR_HEALTH_MENSIS_PROBABILITY_MESSAGE,
    STR_CANNOT_NAVIGATE_FURTHER_MESSAGE,
    //STR_CALENDER_MENSES_CAPTION,
    STR_CALENDER_MESSAAGE1_PP,
    STR_CALENDER_MESSAAGE2_MENS,
    STR_CALENDER_MESSAAGE2_SHORT_MENS,
    STR_HEALTH_WRONG_DATE_MSG,
    EXTRA_HEALTH_MENU_MENSTRUAL_STRINGID
} STR_ID_MENS_ENUM;

typedef enum
{
    IMG_SCR_HEALTH_MENSIS = HEALTH_MENSTRUAL + 1,
#ifdef __MMI_CALENDAR_V2__
    IMG_HEALTH_MENSIS_PP,
    IMG_HEALTH_MENSIS_MENSES,
#endif
    IMG_HEALTH_MENSIS_TOTAL
} IMG_ID_MENS_ENUM;
#endif /* __MMI_MENSTRUAL__*/
#endif /*_MMI_HEALTHMENSTRUAL_RESDEF_H*/
