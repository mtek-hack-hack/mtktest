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
 * BGSoundResDef.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for ¡K.
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
#ifndef BGSNDRESDEF_H
#define BGSNDRESDEF_H

#include "MMI_features.h"   /* add if you use any compile options defined in MMI_features.h */

#ifdef __MMI_BG_SOUND_EFFECT__

#include "MMIDataType.h"    /* for resource base */

/***************************************************************************** 
 * Typedef for Resource Enum
 *****************************************************************************/
/* Screen IDs */
typedef enum
{
    SCR_ID_BGSND_BASE = BG_SOUND_BASE,
    SCR_ID_BGSND_CALL_SETUP,
    SCR_ID_BGSND_CS_PLAYBACK,
    SCR_ID_BGSND_CS_EFFECT,
    SCR_ID_BGSND_CS_EXT_EFFECT_OPT,
    SCR_ID_BGSND_MO_CALL_LIST,
    SCR_ID_BGSND_MT_CALL_LIST,
    SCR_ID_BGSND_CALL_MANAGE,
    SCR_ID_BGSND_CM_SETTING,
    SCR_ID_BGSND_CM_EFFECT,
    SCR_ID_BGSND_END
} SCR_ID_BGSND_ENUM;

/* String IDs */
typedef enum
{
    STR_ID_BGSND_BASE = BG_SOUND_BASE,
    STR_ID_BGSND_BG_SOUND,
    STR_ID_BGSND_STATUS,
    STR_ID_BGSND_MO_STATUS,
    STR_ID_BGSND_PLAYBACK_SETUP,
    STR_ID_BGSND_EFFECT_LIST,
    STR_ID_BGSND_ONCE,
    STR_ID_BGSND_INTERVAL,
    STR_ID_BGSND_CONTINUE,
    STR_ID_BGSND_INTERVAL_CAP,
    STR_ID_BGSND_INTERVAL_CAP_SHORT,
    STR_ID_BGSND_VOLUME_CAP,
    STR_ID_BGSND_VOLUME_CAP_SHORT,
    STR_ID_BGSND_INVALID_INTERVAL,
    STR_ID_BGSND_INVALID_VOLUME,
    STR_ID_BGSND_INVALID_FILE,
    STR_ID_BGSND_DEL_FILE_CONFIRM,
    STR_ID_BGSND_OPEN_FILE_FAIL,
    STR_ID_BGSND_PLAY_FAIL,
    STR_ID_BGSND_LIST_FULL,
    STR_ID_BGSND_FILE_DUPLICATED,
    STR_ID_BGSND_CTM_MODE_ON,
    STR_ID_BGSND_SAVE,

    STR_ID_BGSND_NO_EFFECT,
    STR_ID_BGSND_EFFECT_1,
    STR_ID_BGSND_EFFECT_2,
    STR_ID_BGSND_EFFECT_3,
    STR_ID_BGSND_EFFECT_4,
    STR_ID_BGSND_EFFECT_5,
    STR_ID_BGSND_EFFECT_6,
    STR_ID_BGSND_EFFECT_7,
    STR_ID_BGSND_EFFECT_8,
    STR_ID_BGSND_EFFECT_9,
    STR_ID_BGSND_EFFECT_10,
    STR_ID_BGSND_EFFECT_11,
    STR_ID_BGSND_EFFECT_12,
    STR_ID_BGSND_EFFECT_13,
    STR_ID_BGSND_EFFECT_14,
    STR_ID_BGSND_EFFECT_15,
    STR_ID_BGSND_EFFECT_16,
    STR_ID_BGSND_EFFECT_17,
    STR_ID_BGSND_EFFECT_18,
    STR_ID_BGSND_EFFECT_19,
    STR_ID_BGSND_EFFECT_20,
    STR_ID_BGSND_END
}STR_ID_BGSND_ENUM;

/* Image IDs */
typedef enum
{
    IMG_ID_BGSND_BASE = BG_SOUND_BASE,
    IMG_ID_BGSND_APP,
    IMG_ID_BGSND_END
} IMG_ID_BGSND_ENUM;

/* Audio IDs */
typedef enum
{
    AUD_ID_BGSND_BASE = BG_SOUND_BASE,
    AUD_ID_BGSND_EFFECT1,
    AUD_ID_BGSND_EFFECT2,
    AUD_ID_BGSND_EFFECT3,
    AUD_ID_BGSND_EFFECT4,
    AUD_ID_BGSND_EFFECT5,
    AUD_ID_BGSND_EFFECT6,
    AUD_ID_BGSND_EFFECT7,
    AUD_ID_BGSND_EFFECT8,
    AUD_ID_BGSND_EFFECT9,
    AUD_ID_BGSND_EFFECT10,
    AUD_ID_BGSND_END
} AUD_ID_BGSND_ENUM;

#endif /* __MMI_BG_SOUND_EFFECT__ */ 

#endif /* BGSNDRESDEF_H */ 

