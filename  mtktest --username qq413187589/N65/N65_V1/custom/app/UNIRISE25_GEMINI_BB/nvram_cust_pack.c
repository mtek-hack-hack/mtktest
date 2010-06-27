/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 * nvram_cust_pack.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
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
 *============================================================================
 ****************************************************************************/
#if !defined(__MAUI_BASIC__) && !defined(__L1_STANDALONE__)
#ifdef NVRAM_AUTO_GEN
#include "nvram_auto_gen.h"
#endif 

#include "kal_release.h"

#include "nvram_defs.h"
#include "nvram_user_defs.h"
#include "custom_nvram_editor_data_item.h"
#include "custom_mmi_default_value.h"

/*
 * Warning! Never Change the order of everything in this file
 */
const kal_uint8 NVRAM_SETTING_DEFAULT[NVRAM_SETTING_SIZE] = 
{
    'W', 0x00, 'e', 0x00, 'l', 0x00, 'c', 0x00, 'o', 0x00, 'm', 0x00, 'e', 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

/* For Cache file */
const kal_uint8 NVRAM_CACHE_BYTE_DEFAULT[NVRAM_CACHE_SIZE] = 
{
    0xFF,                                                   /* NVRAM_PHONELOCK_INDEX, //0 */
    0xFF,                                                   /* NVRAM_AUTOLOCK_TIMEOUT_INDEX, */
    0x00,                                                   /* NVRAM_SETTING_PHONELOCK, */
    0x00,                                                   /* NVRAM_SETTING_AUTOKEYPADLOCK, */
    0x00,                                                   /* NVRAM_SETTING_AUTOREDIAL, */
    0x00,                                                   /* NVRAM_SETTING_AUTOKEYPADLOCK_TIME, //5 */
    0x00,                                                   /* NVRAM_SETTING_WELCOME_TEXT, */
    0x01,                                                   /* NVRAM_SETTING_APHORISM_TEXT, */
    0x01,                                                   /* NVRAM_SETTING_CALL_TIME_DISPLAY, */
    0x00,                                                   /* NVRAM_SETTING_SPEED_DIAL, */
    0x07,                                                   /* NVRAM_SETTING_CONTRAST_LEVEL, //10 */
    0x00,                                                   /* NVRAM_SETTING_AUTOUPDATE_DT_TIME, */
    0x00,                                                   /* NVRAM_SETTING_OWNER_NO, */
    0x01,                                                   /* NVRAM_SETTING_STATUS_DT_TIME, */
    0x00,                                                   /* NVRAM_SETTING_LANG,//17 */
    0x00,                                                   /* NVRAM_SETTING_CTR,//15 */
    0x07,                                                   /* NVRAM_SETTING_CONTRAST_SUBLCD_LEVEL, */
    0xFF,                                                   /* NVRAM_HELP_ENABLED_FLAG, */
    0x00,                                                   /* NVRAM_PROFILES_ACTIVATED, */
    0xFF,                                                   /* NVRAM_MISSED_CALL_NUM, */
    0xFF,                                                   /* NVRAM_SMSCOUNTERS_SENT,//20 */
    0xFF,                                                   /* NVRAM_SMSCOUNTERS_RECD, */
    0x00,                                                   /* NVRAM_DOWNLOAD_IMAGE, */
    0x00,                                                   /* NVRAM_DOWNLOAD_TONE, */
    0x07,                                                   /* CURRENT_CITY, */
    0x00,                                                   /* TIME_FORMAT, //25 */
    0x00,                                                   /* DATE_FORMAT, */
    0xFF,                                                   /* NVRAM_GAME_SNAKE_LEVEL, */
    0xFF,                                                   /* LUNAR_CALENDAR, */
    0x01,                                                   /* NVRAM_DOWNLOAD_CITY1, */
    0x00,                                                   /* NVRAM_DOWNLOAD_CITY2, //30 */
    0x00,                                                   /* NVRAM_SCREENSAVER_STATUS,            // 0 for Off, 1 for On */
    0x1E,                                                   /* NVRAM_SCREENSAVER_WAITING,           // 0 for 5 Sec, 1 for 15 Sec, 2 for 30 Sec, 3 for 1 Minute */
    0x02,                                                   /* NVRAM_CALLERID, */
    0xFF,                                                   /* NVRAM_GROUPINDEX, */
    0xFF,                                                   /* NVRAM_GAME_RICHES_STATUS,//35 */
    0xFF,                                                   /* NVRAM_RICHES_OPTION_STATUS, */
    0xFF,                                                   /* NVRAM_PROFILES_LASTACTIVATED, */
    0xFF,                                                   /* TOH_CURRENT_LEVEL, */
    0xFF,                                                   /* SMASH_CURRENT_LEVEL, */
    0xFF,                                                   /* NVRAM_SMS_ACTIVE_PROFILE_INDEX, //40 */
    0xFF,                                                   /* SMS_CONCAT_MSG_REF_VALUE, */
    0xFF,                                                   /* NVRAM_COLORBALLS_OPTION_STATUS, */
    0xFF,                                                   /* NVRAM_PROFILES_LOUDSPKR, */
    FACTORY_RESTORE_DEFAULT_SPEED_DIAL,                     /* RESTORE_DEFAULT_SPEED_DIAL,//44 */
    FACTORY_RESTORE_DEFAULT_CONTRAST_SUBLCD_LEVEL_VALUE,    /* RESTORE_DEFAULT_CONTRAST_SUBLCD_LEVEL, //45 */
    FACTORY_RESTORE_DEFAULT_CONTRAST_MAINLCD_LEVEL_VALUE,   /* RESTORE_DEFAULT_CONTRAST_LEVEL, */
    FACTORY_RESTORE_DEFAULT_WELCOME_TEXT_STATUS,            /* RESTORE_DEFAULT_WELCOME_TEXT, */
    FACTORY_RESTORE_DEFAULT_APHORISM_TEXT_STATUS,           /* RESTORE_DEFAULT_APHORISM_TEXT, */
    FACTORY_RESTORE_DEFAULT_OWNER_NO_STATUS,                /* RESTORE_DEFAULT_OWNER_NO, */
    FACTORY_RESTORE_DEFAULT_STATUS_SHOW_DT_TIME_STATUS,     /* RESTORE_DEFAULT_STATUS_SHOW_DT_TIME,//50 */
    FACTORY_RESTORE_DEFAULT_AUTOUPDATE_TIME_VALUE,          /* RESTORE_DEFAULT_AUTOUPDATE_TIME, */
    FACTORY_RESTORE_DEFAULT_SCREENSAVER_STATUS,             /* RESTORE_DEFAULT_SCREENSAVER_STATUS, */
    FACTORY_RESTORE_DEFAULT_SCREENSAVER_WAITING_TIME,       /* RESTORE_DEFAULT_SCREENSAVER_WAITING, */
    FACTORY_RESTORE_DEFAULT_PROFILES_ACTIVATED_ID,          /* RESTORE_DEFAULT_PROFILES_ACTIVATED, */
    0x00,                                                   /* RESTORE_DEFAULT_TIME_FORMAT,//55 */
    0x00,                                                   /* RESTORE_DEFAULT_DATE_FORMAT, */
    0x00,                                                   /* NVRAM_DOWNLOAD_MELODY, */
    LEVEL5,                                                 /* NVRAM_NORMAL_MODE_VOICE_LEVEL, */
    LEVEL5,                                                 /* NVRAM_LDSPK_MODE_VOICE_LEVEL, */
    LEVEL5,                                                 /* NVRAM_HDSET_MODE_VOICE_LEVEL,//60 */
    0x00,                                                   /* NVRAM_NITZTIMEZONE, */
    0x00,                                                   /* NVRAM_WALLPAPER_ROTATE_STATUS, */
    0xFF,                                                   /* NVRAM_GX_MAJUNG_LEVEL, */
    0xFF,                                                   /* NVRAM_GX_MEMORY_LEVEL, */
    0x00,                                                   /* NVRAM_DEFAULT_USB_APP,  //65 */
    FACTORY_RESTORE_DEFAULT_FMRDO_BACKGROUND_PLAY,          /* NVRAM_FMRDO_BACKGROUND_PLAY, */
    FACTORY_RESTORE_DEFAULT_FMRDO_SKIN,                     /* NVRAM_FMRDO_SKIN, */
    FACTORY_RESTORE_DEFAULT_FMRDO_VOLUME,                   /* NVRAM_FMRDO_VOLUME, */
    FACTORY_RESTORE_DEFAULT_AUDPLY_LIST_AUTO_GEN,           /* NVRAM_AUDPLY_LIST_AUTO_GEN, */
    FACTORY_RESTORE_DEFAULT_AUDPLY_VOLUME,                  /* NVRAM_AUDPLY_VOLUME, */
    FACTORY_RESTORE_DEFAULT_AUDPLY_PREFER_LIST,             /* NVRAM_AUDPLY_PREFER_LIST, */
    FACTORY_RESTORE_DEFAULT_AUDPLY_SKIN,                    /* NVRAM_AUDPLY_SKIN, */
    FACTORY_RESTORE_DEFAULT_AUDPLY_REPEAT,                  /* NVRAM_AUDPLY_REPEAT, */
    FACTORY_RESTORE_DEFAULT_AUDPLY_SHUFFLE,                 /* NVRAM_AUDPLY_SHUFFLE, */
    FACTORY_RESTORE_DEFAULT_AUDPLY_BACKGROUND_PLAY,         /* NVRAM_AUDPLY_BACKGROUND_PLAY, */
    FACTORY_RESTORE_DEFAULT_SNDREC_STORAGE,                 /* NVRAM_SNDREC_STORAGE,//76 */
    FACTORY_RESTORE_DEFAULT_SNDREC_FORMAT,                  /* NVRAM_SNDREC_FORMAT, */
    0xFF,                                                   /* NVRAM_IP_NUMBER_SETTING, */
    0xFF,                                                   /* NVRAM_SET_MAINMENU_STYLE, */
    0xFF,                                                   /* NVRAM_EF_FMGR_SORT_OPTION_LID, // 80 */
    0xFF,                                                   /* NVRAM_GFX_AUDIO_SETTING, */
    0xFF,                                                   /* NVRAM_GFX_AUDIO_VOLUMN, */
    0xFF,                                                   /* NVRAM_GFX_VIBRATION_SETTING, */
    0xFF,                                                   /* NVRAM_GX_PUZZLE_LEVEL, */
    0xFF,                                                   /* NVRAM_GX_STAIR_LEVEL, */
    0xFF,                                                   /* NVRAM_SETTING_DEF_ENCODING, */
    0xFF,                                                   /* NVRAM_STOPWATCH_TOTAL_RECORDS, */
    0xFF,                                                   /* NVRAM_JAVA_SETTING_SOUND, */
    0xFF,                                                   /* NVRAM_JAVA_SETTING_PROF_ID, */
    0xFF,                                                   /* NVRAM_ALM_SNOOZE_TIME, */
    0xFF,                                                   /* NVRAM_VDOPLY_VOLUMN, */
    0xFF,                                                   /* NVRAM_SETTING_OPN_DISPLAY, */
    0xFF,                                                   /* RESTORE_DEFAULT_OPN_DISPLAY, */
    0xFF,                                                   /* NVRAM_BLACK_LIST_SETTING, */
    0xFF,                                                   /* NVRAM_VRSD_RCG_SETTING, //95 */
    0x00,                                                   /* NVRAM_PHB_SPEAK_NAME_ON_OFF, */
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
};

kal_uint8 const NVRAM_CACHE_SHORT_DEFAULT[NVRAM_CACHE_SIZE] = 
{
    0xFF, 0xFF, /* NVRAM_SHORTDATA1_INDEX, */
    0xFF, 0xFF, /* NVRAM_SHORTDATA2_INDEX, */
    0x00, 0x00, /* NVRAM_SNAKE_LEVEL1_SCORE, */
    0x00, 0x00, /* NVRAM_SNAKE_LEVEL2_SCORE, */
    0x00, 0x00, /* NVRAM_SNAKE_LEVEL3_SCORE, */
    0x00, 0x00, /* NVRAM_SNAKE_LEVEL4_SCORE, */
    0x00, 0x00, /* NVRAM_F1RACE_SCORE, */
    0x01, 0x00, /* NVRAM_CURRENT_SCREENSVER_ID, */
    0x01, 0x00, /* NVRAM_PHB_STORAGE_LOCATION, */
    0x01, 0x00, /* NVRAM_FUNANDGAMES_SETWALLPAPER, */
    0x00, 0x00, /* NVRAM_GAME_DOLL_GRADE, */
    0x00, 0x00, /* TOH_LEVEL1_HIGHEST_SCORE, */
    0x00, 0x00, /* TOH_LEVEL2_HIGHEST_SCORE, */
    0x00, 0x00, /* TOH_LEVEL3_HIGHEST_SCORE, */
    0x00, 0x00, /* TOH_LEVEL4_HIGHEST_SCORE, */
    0x00, 0x00, /* NVRAM_RICHES_EASY_SCORE, */
    0x00, 0x00, /* NVRAM_RICHES_NORMAL_SCORE, */
    0x00, 0x00, /* NVRAM_RICHES_HARD_SCORE, */
    0x00, 0x00, /* NVRAM_COLORBALLS_EASY_SCORE, */
    0x00, 0x00, /* NVRAM_COLORBALLS_NORMAL_SCORE, */
    0x00, 0x00, /* NVRAM_COLORBALLS_HARD_SCORE, */
    0x00, 0x00, /* NVRAM_SMASH_NORMAL_SCORE, */
    0x00, 0x00, /* NVRAM_SMASH_SPEEDY_SCORE, */
    0x00, 0x00, /* NVRAM_SMASH_ACCURACY_SCORE, */
    0xFF, 0xFF, /* NVRAM_SETTING_CTR_TIME, */
    0x0D, 0x00, /* NVRAM_SETTING_PREFER_INPUT_METHOD, */
    0x01, 0x00, /* RESTORE_DEFAULT_CURRENT_SCREENSVER_ID, */
    0x01, 0x00, /* RESTORE_DEFAULT_FUNANDGAMES_SETWALLPAPER, */
    0x0D, 0x00, /* RESTORE_PREFER_INPUT_METHOD, */
    0xFF, 0xFF, /* NVRAM_GX_NINJA_SCORE, */
    0xFF, 0xFF, /* NVRAM_GX_MAJUNG_EASY_SCORE, */
    0xFF, 0xFF, /* NVRAM_GX_MAJUNG_NORMAL_SCORE, */
    0xFF, 0xFF, /* NVRAM_GX_MAJUNG_HARD_SCORE, */
    0xFF, 0xFF, /* NVRAM_GX_MEMORY_EASY_SCORE, */
    0xFF, 0xFF, /* NVRAM_GX_MEMORY_NORMAL_SCORE, */
    0xFF, 0xFF, /* NVRAM_GX_MEMORY_HARD_SCORE, */
    0xFF, 0xFF, /* NVRAM_GX_COPTER_SCORE, */
    0xFF, 0xFF, /* NVRAM_GX_PUZZLE_EASY_SCORE, */
    0xFF, 0xFF, /* NVRAM_GX_PUZZLE_NORMAL_SCORE, */
    0xFF, 0xFF, /* NVRAM_GX_PUZZLE_HARD_SCORE, */
    0xFF, 0xFF, /* NVRAM_GX_PANDA_SCORE, */
    0xFF, 0xFF, /* NVRAM_GX_STAIR_EASY_SCORE, */
    0xFF, 0xFF, /* NVRAM_GX_STAIR_NORMAL_SCORE, */
    0xFF, 0xFF, /* NVRAM_GX_STAIR_HARD_SCORE, */
    0xFF, 0xFF, /* NVRAM_GX_UFO_SCORE, */
    0xFF, 0xFF, /* NVRAM_GX_DANCE_SCORE, */
    0xFF, 0xFF, /* NVRAM_CAM_FILENAME_SEQ_NO, */
    0xFF, 0xFF, /* NVRAM_IMG_VIEWER_FILE_PATH, */
    0xFF, 0xFF, /* NVRAM_VDOREC_FILENAME_SEQ_NO, */
    0xFF, 0xFF, /* NVRAM_VDOPLY_SNAPSHOT_SEQ_NO, */
    0x01, 0x00, /* NVRAM_RESTORE_POWER_ON_DISPLAY, */
    0x01, 0x00, /* NVRAM_RESTORE_POWER_OFF_DISPLAY, */
    0x01, 0x00, /* NVRAM_CURRENT_POWER_ON_DISPLAY, */
    0x01, 0x00, /* NVRAM_CURRENT_POWER_OFF_DISPLAY, */
    0xFF, 0xFF, /* NVRAM_POWER_ON_DISPLAY_SUCCESS, */
    0xFF, 0xFF, /* NVRAM_POWER_OFF_DISPLAY_SUCCESS, */
    0xFF, 0xFF, /* NVRAM_SCREENSAVER_DISPLAY_SUCCESS, */
    0xFF, 0xFF, /* NVRAM_POWER_ON_FORCE_STOP_TIME, */
    0xFF, 0xFF, /* NVRAM_POWER_OFF_FORCE_STOP_TIME, */
    0x01, 0x00, /* NVRAM_SETWALLPAPER_SUB, */
    0x01, 0x00, /* RESTORE_DEFAULT_SETWALLPAPER_SUB, */
    0xFF, 0xFF, /* NVRAM_CH_QUICK_END_TIME, */
    0xFF, 0xFF, /* NVRAM_GX_MAGICSUSHI_SCORE, */
    0xFF, 0xFF, /* NVRAM_SCR_SNAPSHOT_SEQ_NO, */
    0xFF, 0xFF, /* NVRAM_SETTING_TVOUT_FORMAT, */
    0xFF, 0xFF, /* NVRAM_SETTING_TVOUT_STYLE, */
    0xFF, 0xFF, /* NVRAM_AUDIO_MIC_VOLUME_SET, */
    0xFF, 0xFF, /* NVRAM_SMS_CONCAT_MSG_REF_VALUE, */
    0xFF, 0xFF, /*  */
    0xFF, 0xFF, /*  */
    0xFF, 0xFF, /*  */
    0xFF, 0xFF, /*  */
    0xFF, 0xFF, /*  */
    0xFF, 0xFF, /*  */
    0xFF, 0xFF, /*  */
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
};

kal_uint8 const NVRAM_CACHE_DOUBLE_DEFAULT[NVRAM_CACHE_SIZE] = 
{
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
};
const kal_uint8 NVRAM_PHONEBOOK_SOS_DEFAULT[NVRAM_PHONEBOOK_SOS_RECORD_SIZE] = 
{
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
};
const kal_uint8 NVRAM_PHONEBOOK_SPEEDDIAL_DEFAULT[NVRAM_PHONEBOOK_SPEEDDIAL_RECORD_SIZE];
const kal_uint8 NVRAM_EF_SMSAL_MAILBOX_ADDR_DEFAULT[] = 
{
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, /* Alpha ID */
    0x00,   /* Length of BCD number */
    0xff,   /* TON and NPI */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, /* Dailling number */
    0xff,   /* capability/configuration identifier */
    0xff    /* extension 1 record identifier */
};

kal_uint8 const NVRAM_EF_MS_SECURITY_DEFAULT[] = 
{
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,         /* reg_ps_key */
    0x00,                                                   /* security_indication */
    0x00,                                                   /* auto_lock_item */
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   /* np_code */
    0x21, 0x43, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,         /* np_key */
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   /* nsp_code */
    0x65, 0x87, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,         /* nsp_key */
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,                                       /* np_of_sp */
    0x00, 0x00, 0x00,                                       /* np_of_cp */
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* gid1 */
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* gid2 */
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,         /* sp_key */
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,         /* cp_key */
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   /* imsi_code */
    0x33, 0x44, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,         /* imsi_key */
    0x11, 0x22, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,         /* phone_key */
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   /* last_imsi */
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,         /* pin1 */
    0x00,                                                   /* pin1_valid */
    0x00,                                                    /* phone_lock_verified */
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 /* iccid */
};

#ifdef __CPHS__
const kal_uint8 NVRAM_EF_ALS_LINE_ID_DEFAULT[NVRAM_EF_ALS_LINE_ID_SIZE] = 
{
    0x0, 0x0
};
#endif /* __CPHS__ */ 

const kal_uint8 NVRAM_EF_MSCAP_DEFAULT[NVRAM_EF_MSCAP_SIZE] = 
{
#if defined(__AMR_SUPPORT__)
    0x1f,   /* Supported speech version (FR,HR,EFR,AMR FR,AMR HR) */
#elif !defined(MT6205)
    0x07,   /* Supported speech version (FR,HR,EFR) */
#else 
    0x05,   /* Supported speech version (FR,EFR) */
#endif 

#if defined(__CSD_T__) && defined(__CSD_NT__) && defined(__CSD_FAX__)
    0x63,   /* Supported data capability 1 (T & NT & FAX_T) */
#elif defined(__CSD_T__) && defined(__CSD_NT__)
    0x61,   /* Supported data capability 1 (T & NT) */
#elif defined(__CSD_T__) && defined(__CSD_FAX__)
    0x23,   /* Supported data capability 1 (T & FAX_T) */
#elif defined(__CSD_NT__) && defined(__CSD_FAX__)
    0x43,   /* Supported data capability 1 (NT & FAX_T) */
#elif defined(__CSD_T__)
    0x21,   /* Supported data capability 1 (ONLY T) */
#elif defined(__CSD_NT__)
    0x41,   /* Supported data capability 1 (ONLY NT) */
#elif defined(__CSD_FAX__)
    0x02,   /* Supported data capability 1 (ONLY FAX_T) */
#else 
    0x00,   /* Supported data capability 1 (NO SUPPORT CSD) */
#endif 
    0x00,   /* Supported data capability 2 */
#if defined(CSD_SUPPORT) || defined(__CSD_FAX__)
#if !defined(MT6205)
    0x1f    /* Supported channel coding (2.4k,4.8k,9.6k,14.4k,HR) */
#else 
    0x0f    /* Supported channel coding (2.4k,4.8k,9.6k,14.4k) */
#endif 
#else /* defined(CSD_SUPPORT) || defined(__CSD_FAX__) */ 
    0x00
#endif /* defined(CSD_SUPPORT) || defined(__CSD_FAX__) */ 
};

kal_uint8 const NVRAM_EF_RAC_PREFERENCE_DEFAULT[] = 
{
    /* Ripple: 20050513, Auto band, then turn on all supported bands. */
#if defined(__EGSM900__) && defined(__DCS1800__) && defined(__GSM850__) && defined(__PCS1900__)
    0x9A,
#elif defined( __EGSM900__ ) && defined( __DCS1800__ ) && defined( __GSM850__ )
    0x8A,
#elif defined( __EGSM900__ ) && defined( __DCS1800__ ) && defined( __PCS1900__ )
    0x1A,
#elif defined( __GSM850__ ) && defined( __PCS1900__ ) && defined( __EGSM900__ )
    0x92,
#elif defined( __GSM850__ ) && defined( __PCS1900__ ) && defined( __DCS1800__ )
    0x98,
#elif defined( __EGSM900__ ) && defined( __DCS1800__ )
    0x0A,   /* prefered band: 900 + 1800 */
#elif defined( __GSM850__ ) && defined( __PCS1900__ )
    0x90,   /* prefered band: 850 + 1900 */
#elif defined( __GSM850__ ) && defined( __DCS1800__ )
    0x88,   /* prefered band: 850 + 1800 */
#elif defined( __EGSM900__ ) && defined( __PCS1900__ )
    0x12,   /* prefered band: 900 + 1900 */
#elif defined( __EGSM900__ )
    0x02,   /* prefered band: 900 */
#elif defined( __DCS1800__ )
    0x08,   /* prefered band: 1800 */
#elif defined( __GSM850__ )
    0x80,   /* prefered band: 850 */
#elif defined( __PCS1900__ )
    0x10,   /* prefered band: 1900 */
#else 
    0x0A,   /* prefered band: 900 + 1800 */
#endif 
    // 0x80 /* PLMN selection mode and Preferred Service in NMO III */
    0xC0    /* GPRS auto attach */
};

kal_uint8 const NVRAM_EF_SMSAL_COMMON_PARAM_DEFAULT[] = 
{
#if defined (__CS_SERVICE__) && defined (__PS_SERVICE__)
    0x03,               /* bearer service : GSM prefer */
#elif defined (__PS_SERVICE__)
    0x00,               /* bearer service : GPRS Only */
#else 
    0x01,               /* bearer service : GSM Only */
#endif 
    0x00, 0x00,         /* status report, reply path OFF */
    0x02,               /* VP: Relative format */
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    0x01, 0x01, 0x01,   /* mem1, mem2, mem3 */
#else/* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
    0x05, 0x05, 0x05,   /* mem1, mem2, mem3 */
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
    0x00, 0x01,         /* CB setting */
    0x00,               /* AT default profile ID */
    0x00,               /* First Octet */
    0x00,               /* Turn Off SMS FDN */
    0x00,
    0x00
};

/* Cell Broadcast Default Channel Setting. */
/* The channels set will not shown in MMI, but it will received CB if CB is turned on. */
/* This setting may be changed by customer. DON'T remove it. */
kal_uint8 const NVRAM_EF_CB_DEFAULT_CH_DEFAULT[] = 
{
    0xFF, 0xFF, /* default CH 1 , for example:  chanel 50 is 0x00, 0x32 */
    0xFF, 0xFF, /* default CH 2  */
    0xFF, 0xFF, /* default CH 3  */
    0xFF, 0xFF, /* default CH 4  */
    0xFF, 0xFF, /* default CH 5  */
    0xFF, 0xFF, /* default CH 6  */
    0xFF, 0xFF, /* default CH 7  */
    0xFF, 0xFF, /* default CH 8  */
    0xFF, 0xFF, /* default CH 9  */
    0xFF, 0xFF  /* default CH 10 */
};

#endif /* !defined(__MAUI_BASIC__) && !defined(__L1_STANDALONE__) */ 

