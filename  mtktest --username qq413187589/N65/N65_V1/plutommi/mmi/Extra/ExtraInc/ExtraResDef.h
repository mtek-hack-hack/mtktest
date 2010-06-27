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
 * ExtraResDefs.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is defines resource id of Extra applications.
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
#ifndef _MMI_EXTRARES_H
#define  _MMI_EXTRARES_H

#include "MMI_features.h"
#include "MMIDataType.h" 


#define MAIN_MENU_EBOOK_TEXT              (EBOOK_BASE+0)

typedef enum
{
    SCR_EXTRA = EXTRA_APP_BASE,
    SCR_HEALTH_MENU,
    SCR9147_APHORISM_TEXT
} SCREENID_LIST_EXTRA;

typedef enum
{
    MAIN_MENU_EXTRA_TEXT = EXTRA_APP_BASE,

#if (defined(__MMI_BMI__) || defined(__MMI_CALORIE__) || defined(__MMI_MENSTRUAL__))
    EXTRA_MENU_HEALTH_STRINGID,
#endif 

#if defined(__MMI_APHORISM__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_APHORISM__) */ 

#if (defined(__MMI_BMI__) || defined(__MMI_CALORIE__) || defined(__MMI_MENSTRUAL__))
    STR_SCR_HEALTH_CAPTION,
#endif 
#if defined(__MMI_DICTIONARY__)
    EXTRA_DICTIONARY_STRINGID,
#endif 
    STR_SCR_EXTRA_TOTAL
} STRINGID_LIST_EXTRA;

typedef enum
{
    EXTRA_TITLE_IMAGEID = EXTRA_APP_BASE + 1,
#if (defined(__MMI_BMI__) || defined(__MMI_CALORIE__) || defined(__MMI_MENSTRUAL__))
    EXTRA_MENU_HEALTH_IMAGEID,
#endif 

#if defined(__MMI_APHORISM__)
/* under construction !*/
#endif 

#if (defined(__MMI_BMI__) || defined(__MMI_CALORIE__) || defined(__MMI_MENSTRUAL__))
    IMG_SCR_HEALTH_CAPTION,
#endif 

    IMG_SCR_EXTRA_TOTAL
} IMAGEID_LIST_EXTRA;

#endif /*_MMI_EXTRARES_H*/

