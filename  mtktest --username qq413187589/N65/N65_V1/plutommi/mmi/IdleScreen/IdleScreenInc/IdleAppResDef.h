/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   IdleAppResDef.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for idle screen resource definitions
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __IDLE_RES_DEF_H__
#define __IDLE_RES_DEF_H__

#include "MMI_features.h"
#include "MMIDataType.h"    /* for resource base */

/***************************************************************************** 
 * Typedef for Resource Enum
 *****************************************************************************/
/* Screen IDs */
typedef enum
{
    IDLE_SCREEN_ID = IDLE_APP_BASE + 1,
    IDLE_SCREEN_ID_DUMMY, 
    IDLE_SCREEN_DIGIT_HANDLER_ID,
    IDLE_SCREEN_DIGIT_OPTIONS_ID,
    IDLE_SCREEN_SCREENSAVER_ID,
    IDLE_SCREEN_DUMMY_ID,
    SCREEN_SAVER_PARTIAL_ON_ID,
    POPUP_SCREENID,
    SCR_ID_IDLE_END
} IDLE_SCR_ID_ENUM;

/* String IDs */
typedef enum
{
    IDLE_SCREEN_LSK_TEXT = IDLE_APP_BASE + 1,
#ifdef __MMI_SUBLCD_MASTER_MODE__
    STR_IDLE_DUMMY_SCREEN, 
#endif
    IDLE_SCREEN_RSK_TEXT,
    STR_IDLE_NETWORK_SRCH_SCR,
    STR_INVALID_LOCATION,
    STR_NO_PHONE_NUM,
    STR_NO_SPEED_DIAL_NUM_SAVED,
    STR_DATE_TIME_UPDATE_REMINDER,
    KEYPAD_LOCKED_RSK_TEXT,
#ifdef __MMI_TOUCH_SCREEN__
    SCREEN_LOCKED_TEXT,
#endif
#ifdef __MMI_VOIP__
    STR_ID_DIALER_SCREEN_OPTIONS_GSM_DIAL,
    STR_ID_DIALER_SCREEN_OPTIONS_WLAN_DIAL,
    STR_ID_DIALER_SCREEN_OPTIONS_CHANGE_MODE,
#endif /* __MMI_VOIP__ */
#ifdef __MMI_OP01_WITH_WAP_KEY__
    STR_ID_ENTRY_WAP_CONFIRM,
#endif
    STR_ID_IDLE_NW_SEL_CONFIRM,
    STR_ID_IDLE_END
} IDLE_STR_ID_ENUM;

/* Image IDs */
typedef enum
{
    IDLE_SCREEN_LSK_ICON = IDLE_APP_BASE + 1,

    DIAL_PAD_MO_CALL_LSK_IMG_ID,
    DIAL_PAD_MO_CALL_RSK_IMG_ID,

    IDLE_SCREEN_RSK_ICON,
    IMG_IDLE_NETWORK_SRCH_SCR,
    POWER_ON_ANIMATION_IMAGE_ID,

    IMG_ID_IDLE_END
} IDLE_IMG_ID_ENUM;

#endif /*__IDLE_RES_DEF_H__ */

