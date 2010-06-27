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
 *   QuickAccessMenuItemResDef.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for quick access menu item resource definitions
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

#ifndef __QUICK_ACCESS_RES_DEF_H__
#define __QUICK_ACCESS_RES_DEF_H__

#include "MMIDataType.h"    /* for resource base */

/***************************************************************************** 
 * Typedef for Resource Enum
 *****************************************************************************/
/* Screen IDs */
typedef enum
{
    KPAD_SCR_UNLOCK_MESSAGE = IDLE_APP_BASE + 350,
    KPAD_SCR_UNLOCK_HELP_MESSAGE,
    KPAD_SCR_UNLOCK_FIRST_HELP_MESSAGE,
    EMERENCY_CALL_SCR_DISPLAY_ID,
    QUICK_ACCESS_SCR_ID_END
} QUICK_ACCESS_SCR_ID_ENUM;

/* String IDs */
typedef enum
{
    KPAD_SCR_UNLOCKED_MESSAGE_RUNNING_STR = IDLE_APP_BASE + 350,

    KPAD_SCR_UNLOCKED_HELP_MESSAGE_RUNNING_STR,
    KPAD_SCR_UNLOCKED_HELP_MESSAGE_RUNNING_STR2,

    KPAD_SCR_UNLOCKED_FIRST_HELP_MESSAGE_RUNNING_STR,
    KPAD_SCR_UNLOCKED_FIRST_HELP_MESSAGE_RUNNING_STR2,

#ifdef __MMI_TOUCH_SCREEN__
    TOUCH_SCR_UNLOCKED_FIRST_HELP_MESSAGE_RUNNING_STR,
    TOUCH_SCR_UNLOCKED_HELP_MESSAGE_RUNNING_STR,
#endif 

    QUICK_ACCESS_STR_ID_END
} QUICK_ACCESS_STR_ID_ENUM;

/* Image IDs */
typedef enum
{
    IMG_KPAD_SCR_UNLOCKED_HELP_MESSAGE = IDLE_APP_BASE + 350,
#ifdef __MMI_TOUCH_SCREEN__
    IMG_TOUCH_SCR_PEN_CLICK_AREA,
#endif 
    QUICK_ACCESS_IMG_ID_END
} QUICK_ACCESS_IMG_ID_ENUM;

#endif /*__QUICK_ACCESS_RES_DEF_H__ */

