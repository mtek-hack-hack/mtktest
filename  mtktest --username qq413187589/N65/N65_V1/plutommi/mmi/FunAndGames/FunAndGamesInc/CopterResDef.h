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
 * GameCopterDefs.h
  *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Game id define Copter.
 *
 * Author:
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _MMI_GX_COPTER_DEFS_H
#define _MMI_GX_COPTER_DEFS_H

/***************************************************************************** 
* Typedef 
*****************************************************************************/
/* String ID */
typedef enum
{
    STR_ID_GX_COPTER_GAME_NAME = GAME_COPTER_BASE + 1,

#if defined(__MMI_TOUCH_SCREEN__)
    STR_ID_GX_COPTER_HELP_DESCRIPTION_TP,
#else 
    STR_ID_GX_COPTER_HELP_DESCRIPTION,
#endif 

    STR_ID_GX_COPTER_GAME_NAME_SUBMARINE,

#if defined(__MMI_TOUCH_SCREEN__)
    STR_ID_GX_COPTER_HELP_DESCRIPTION_SUBMARINE_TP,
#else 
    STR_ID_GX_COPTER_HELP_DESCRIPTION_SUBMARINE,
#endif 
    STR_ID_GX_COPTER_GAME_NAME_JET,

#if defined(__MMI_TOUCH_SCREEN__)
    STR_ID_GX_COPTER_HELP_DESCRIPTION_JET_TP,
#else 
    STR_ID_GX_COPTER_HELP_DESCRIPTION_JET,
#endif 

    STR_ID_GX_COPTER_COUNT
} gx_copter_str_id_enum;

/* Image ID */
typedef enum
{
    IMG_ID_GX_COPTER_GAME_ICON = GAME_COPTER_BASE + 1,
    IMG_ID_GX_COPTER_OBSTACLE,
    IMG_ID_GX_COPTER_NUMBER_0,
    IMG_ID_GX_COPTER_NUMBER_1,
    IMG_ID_GX_COPTER_NUMBER_2,
    IMG_ID_GX_COPTER_NUMBER_3,
    IMG_ID_GX_COPTER_NUMBER_4,
    IMG_ID_GX_COPTER_NUMBER_5,
    IMG_ID_GX_COPTER_NUMBER_6,
    IMG_ID_GX_COPTER_NUMBER_7,
    IMG_ID_GX_COPTER_NUMBER_8,
    IMG_ID_GX_COPTER_NUMBER_9,
    IMG_ID_GX_COPTER_BOX,
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    IMG_ID_GX_COPTER_SCORE,
#endif
    IMG_ID_GX_COPTER_TITLE,
    IMG_ID_GX_COPTER_0,
    IMG_ID_GX_COPTER_1,
    IMG_ID_GX_COPTER_2,
    IMG_ID_GX_COPTER_CRASHED_0,
    IMG_ID_GX_COPTER_CRASHED_1,
    IMG_ID_GX_COPTER_CRASHED_2,
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    IMG_ID_GX_COPTER_GOTEXT,
#endif
    IMG_ID_GX_COPTER_GRADESMAP,
    IMG_ID_GX_COPTER_GOPIC,
#if defined(__MMI_TOUCH_SCREEN__)
    IMG_ID_GX_COPTER_UP,
    IMG_ID_GX_COPTER_DOWN,
#endif /* defined(__MMI_TOUCH_SCREEN__) */ 
    IMG_ID_GX_COPTER_BACKGROUND,

#ifdef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    //added for multi-language support
    IMG_ID_GX_COPTER_GOTEXT_LANGUAGE0,
    IMG_ID_GX_COPTER_GOTEXT_LANGUAGE1,
    IMG_ID_GX_COPTER_GOTEXT_LANGUAGE2,
    IMG_ID_GX_COPTER_GOTEXT_LANGUAGE3,
    IMG_ID_GX_COPTER_GOTEXT_LANGUAGE4,
    IMG_ID_GX_COPTER_GOTEXT_LANGUAGE5,
    IMG_ID_GX_COPTER_GOTEXT_LANGUAGE6,
    IMG_ID_GX_COPTER_GOTEXT_LANGUAGE7,
    IMG_ID_GX_COPTER_GOTEXT_LANGUAGE8,
    IMG_ID_GX_COPTER_GOTEXT_LANGUAGE9,
#endif  /* __MMI_GAME_MULTI_LANGUAGE_SUPPORT__ */

    IMG_ID_GX_COPTER_COUNT
} gx_copter_img_id_neum;

#endif /* _MMI_GX_COPTER_DEFS_H */ /* IS_COPTER_BASE_GAME */

