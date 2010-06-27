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
 *   FunAndGamesResDef.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Fun And Game source file
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
#ifndef FUNANDGAMESRESDEF_H
#define FUNANDGAMESRESDEF_H
/* MTK added, Max: add customized compile option 1001 */
#include "MMI_features.h"
#include "j2me_custom.h"
/* MTK end */
#include "MMIDataType.h"

#define FUNANDGAMES_BASE                     (3000)

/* Fun and Games main menu ---------------------------------------------   */
// #define FUNANDGAMES_MAX_THEMES       3

#if defined(__MMI_VERSION_2__)
typedef enum
{
#if defined(__J2ME__)
    FUN_ENUM_JAVA,
    FNG_ENUM_SETTING_JAVA,
    #ifdef OGDR_SECURITY_SETTING
    FNG_ENUM_SECURITY_JAVA,
    #endif

    #ifdef __SUPPORT_INFUSIO__
    FNG_ENUM_JAVA_EUREKA,
    #endif /* __SUPPORT_INFUSIO__ */
#endif /* __J2ME__ */

#if defined(__MMI_GAME__)
    FUN_ENUM_GAMES,
#endif 

#if defined(__MMI_3D_GAME__)
    FUN_ENUM_3D_GAME,
#endif 

#if defined(__MMI_MOTION_APP__)
    FUN_ENUM_MOTION_APP,
#endif 

#if defined (__MMI_THEMES_APPLICATION__)
    FUN_ENUM_THEME,
#endif 

#if defined (__MMI_PICTURE_EDITOR_SUPPORT__)
    FUN_ENUM_PIC_EDITOR,
#endif 

#if defined (__MMI_AVATAR__)
    FUN_ENUM_AVATAR,
#endif 

    FUN_ENUM_TOTAL
} FunAndGameMenu;

typedef enum
{
#if defined(__MMI_MOBILE_TV_PLAYER__)
    MMEDIA_ENUM_MOBILE_TV_PLAYER,
#endif

#if defined (__MMI_CAMERA__)
#ifndef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
    MMEDIA_ENUM_CAMERA,
#endif 
#endif /* defined (__MMI_CAMERA__) */ 

#if defined(__MMI_IMAGE_VIEWER__)
    MMEDIA_ENUM_IMAGEVIEWER,
#endif 

#ifndef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
#if defined (__MMI_VIDEO_RECORDER__)
    MMEDIA_ENUM_VIDEO_RECORDER,
#endif 
#if defined (__MMI_VIDEO_PLAYER__)
    MMEDIA_ENUM_VIDEO_PLAYER,
#endif 
#endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 

#if defined(__MMI_VIDEO_EDITOR__)
    MMEDIA_ENUM_VIDEO_EDITOR,
#endif

#if defined(__MMI_PHOTOEDITOR__)
    MMEDIA_ENUM_PHOTO_EDITOR,
#endif 

#if defined(__MMI_BARCODEREADER__)
    MMEDIA_ENUM_BARCODEREADER,
#endif 

#ifndef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
#if defined(__MMI_AUDIO_PLAYER__)
    MMEDIA_ENUM_AUDIO_PLAYER,
#endif 
#endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 

#if defined(__MMI_AB_REPEATER__)
    MMEDIA_ENUM_AB_REPEATER,
#endif 

#if defined(__MMI_SOUND_RECORDER__)
    MMEDIA_ENUM_SOUND_RECORDER,
#endif 

#if defined (__MMI_FM_RADIO__)
    MMEDIA_ENUM_FM_RADIO,
#endif 

#if defined(__MMI_FM_RADIO_SCHEDULE_REC__)
    MMEDIA_ENUM_FM_SCHEDULE_RECORD,
#endif 

/* hongzhe.liu  add start */
#if  defined (ANALOG_TV_SUPPORT)  
   MMEDIA_ENUM_ANALOGTV_RECORDER,
   #if defined(TV_RECORD_SUPPORT)
   //Huyanwei Add It 
   MMEDIA_ENUM_ANALOG_TV_RECORD_ENTRY,
  #endif				
#endif
/* hongzhe.liu  add end */

#if defined(__MMI_RING_COMPOSER__) && defined(__MMI_IMELODY_SUPPORT__)
    MMEDIA_ENUM_COMPOSER,
#endif 

#if defined(__MMI_VOICE_MEMO__)
    MMEDIA_ENUM_VOICE_MEMO,
#endif 

#if defined(__MMI_VRSD__)
    MMEDIA_ENUM_VRSD,
#endif 

#if defined(__MMI_VRSI__)
    MMEDIA_ENUM_VRSI,
#endif

#if defined(__MMI_SLIDESHOW__)
    MMEDIA_ENUM_SLIDESHOW,
#endif

    MMEDIA_ENUM_TOTAL
} MultiMediaMenu;

#else /* defined(__MMI_VERSION_2__) */ 
#ifdef __MMI_OP01_MENU_NOSIM_LIST__
typedef enum
{
#if defined(__J2ME__)
    FUN_ENUM_NOSIM_JAVA,
    FNG_ENUM_SETTING_NOSIM_JAVA,
#ifdef OGDR_SECURITY_SETTING
    FNG_ENUM_SECURITY_NOSIM_JAVA,
#endif /* OGDR_SECURITY_SETTING */
#ifdef __SUPPORT_INFUSIO__
    FNG_ENUM_JAVA_NOSIM_EUREKA,
#endif /* __SUPPORT_INFUSIO__ */
#endif /* __J2ME__ */

#if defined(__MMI_GAME__)
    FUN_ENUM_NOSIM_GAMES,
#endif 

#if defined(__MMI_3D_GAME__)
    FUN_ENUM_NOSIM_3D_GAME,
#endif 

#if defined(__MMI_MOTION_APP__)
    FUN_ENUM_NOSIM_MOTION_APP,
#endif 

#if defined(__MMI_STOPWATCH__)
    FUN_ENUM_NOSIM_STOPWATCH,
#endif 

#if defined (__MMI_PICTURE_EDITOR_SUPPORT__)
    FUN_ENUM_NOSIM_PIC_EDITOR,
#endif 

#if defined (__MMI_AVATAR__)
    FUN_ENUM_NOSIM_AVATAR,
#endif 

    FUN_ENUM_NOSIM_TOTAL
} FunAndGameNoSimMenu;
typedef enum
{
#if defined (__MMI_CAMERA__)
#ifndef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
    MMEDIA_ENUM_NOSIM_CAMERA,
#endif 
#endif /* defined (__MMI_CAMERA__) */ 
#ifndef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
#if defined(__MMI_AUDIO_PLAYER__)
    MMEDIA_ENUM_NOSIM_AUDIO_PLAYER,
#endif 
#endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 
#if defined (__MMI_FM_RADIO__)
    MMEDIA_ENUM_NOSIM_FM_RADIO,
#endif 
#if defined(__MMI_IMAGE_VIEWER__)
    MMEDIA_ENUM_NOSIM_IMAGEVIEWER,
#endif 
#if defined(__MMI_PHOTOEDITOR__)
    MMEDIA_ENUM_NOSIM_PHOTO_EDITOR,
#endif 
#ifndef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
#if defined (__MMI_VIDEO_RECORDER__)
    MMEDIA_ENUM_NOSIM_VIDEO_RECORDER,
#endif 
#if defined (__MMI_VIDEO_PLAYER__)
    MMEDIA_ENUM_NOSIM_VIDEO_PLAYER,
#endif 
#endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 
#if defined(__MMI_VIDEO_EDITOR__)
    MMEDIA_ENUM_NOSIM_VIDEO_EDITOR,
#endif
#if defined(__MMI_BARCODEREADER__)
    MMEDIA_ENUM_NOSIM_BARCODEREADER,
#endif 
#if defined(__MMI_SOUND_RECORDER__)
    MMEDIA_ENUM_NOSIM_SOUND_RECORDER,
#endif 
#if defined(__MMI_AB_REPEATER__)
    MMEDIA_ENUM_NOSIM_AB_REPEATER,
#endif 
#if defined(__MMI_FM_RADIO_SCHEDULE_REC__)
    MMEDIA_ENUM_NOSIM_FM_SCHEDULE_RECORD,
#endif 
#if defined(__MMI_RING_COMPOSER__) && defined(__MMI_IMELODY_SUPPORT__)
    MMEDIA_ENUM_NOSIM_COMPOSER,
#endif 

#if defined(__MMI_VOICE_MEMO__)
    MMEDIA_ENUM_NOSIM_VOICE_MEMO,
#endif 

#if defined(__MMI_VRSD__)
    MMEDIA_ENUM_NOSIM_VRSD,
#endif 

#if defined(__MMI_VRSI__)
    MMEDIA_ENUM_NOSIM_VRSI,
#endif 
    MMEDIA_ENUM_NOSIM_TOTAL
} MultiMediaNoSimMenu;
#endif /* __MMI_OP01_MENU_NOSIM_LIST__ */

#ifdef __MMI_OP01_MENU_9MATRIX__
/* under construction !*/
/* under construction !*/
#if defined(__MMI_IMAGE_VIEWER__)
/* under construction !*/
#endif 
#if defined(__MMI_PHOTOEDITOR__)
/* under construction !*/
#endif 
#if defined (__MMI_VIDEO_RECORDER__)
/* under construction !*/
#endif 
#if defined (__MMI_VIDEO_PLAYER__)
/* under construction !*/
#endif 
#if defined(__MMI_VIDEO_EDITOR__)
/* under construction !*/
#endif
#if defined(__MMI_BARCODEREADER__)
/* under construction !*/
#endif 
#if defined(__MMI_SOUND_RECORDER__)
/* under construction !*/
#endif 
#if defined(__MMI_GAME__)
/* under construction !*/
#endif
#if defined(__MMI_3D_GAME__)
/* under construction !*/
#endif 
#if defined(__MMI_AB_REPEATER__)
/* under construction !*/
#endif 
#if defined(__MMI_FM_RADIO_SCHEDULE_REC__)
/* under construction !*/
#endif 
#if defined(__MMI_RING_COMPOSER__) && defined(__MMI_IMELODY_SUPPORT__)
/* under construction !*/
#endif 
#if defined(__MMI_VOICE_MEMO__)
/* under construction !*/
#endif 
#if defined(__MMI_VRSD__)
/* under construction !*/
#endif 
#if defined(__MMI_VRSI__)
/* under construction !*/
#endif  				
#if defined(__MMI_MOTION_APP__) 
/* under construction !*/
#endif 
#if defined( __MMI_STOPWATCH__)        
/* under construction !*/
#endif  
#if defined (__MMI_PICTURE_EDITOR_SUPPORT__)
/* under construction !*/
#endif
#if defined(__MMI_AVATAR__)
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#else /* __MMI_OP01_MENU_9MATRIX__ */
typedef enum
{
#if defined (__MMI_CAMERA__)
    MMEDIA_ENUM_CAMERA,
#endif 

#if defined(__MMI_IMAGE_VIEWER__)
    MMEDIA_ENUM_IMAGEVIEWER,
#endif 

#if defined (__MMI_VIDEO_RECORDER__)
    MMEDIA_ENUM_VIDEO_RECORDER,
#endif 

#if defined (__MMI_VIDEO_PLAYER__)
    MMEDIA_ENUM_VIDEO_PLAYER,
#endif 

#if defined(__MMI_VIDEO_EDITOR__)
    MMEDIA_ENUM_VIDEO_EDITOR,
#endif

#if defined(__MMI_PHOTOEDITOR__)
    MMEDIA_ENUM_PHOTO_EDITOR,
#endif 

#if defined(__MMI_BARCODEREADER__)
    MMEDIA_ENUM_BARCODEREADER,
#endif 

#if defined(__MMI_AUDIO_PLAYER__)
    MMEDIA_ENUM_AUDIO_PLAYER,
#endif 

#if defined(__MMI_AB_REPEATER__)
    MMEDIA_ENUM_AB_REPEATER,
#endif 

#if defined(__MMI_SOUND_RECORDER__)
    MMEDIA_ENUM_SOUND_RECORDER,
#endif 

#if defined (__MMI_FM_RADIO__)
    MMEDIA_ENUM_FM_RADIO,
#endif 

#if defined(__MMI_FM_RADIO_SCHEDULE_REC__)
    MMEDIA_ENUM_FM_SCHEDULE_RECORD,
#endif 

/* hongzhe.liu  add start */
#if  defined (ANALOG_TV_SUPPORT)  
   MMEDIA_ENUM_ANALOGTV_RECORDER,
   #if defined(TV_RECORD_SUPPORT)
   //Huyanwei Add It 
   MMEDIA_ENUM_ANALOG_TV_RECORD_ENTRY,
  #endif				

#endif
/* hongzhe.liu  add end */

#if defined(__MMI_RING_COMPOSER__) && defined(__MMI_IMELODY_SUPPORT__)
    MMEDIA_ENUM_COMPOSER,
#endif 

#if defined(__MMI_VOICE_MEMO__)
    MMEDIA_ENUM_VOICE_MEMO,
#endif 

#if defined(__MMI_VRSD__)
    MMEDIA_ENUM_VRSD,
#endif 

#if defined(__MMI_VRSI__)
    MMEDIA_ENUM_VRSI,
#endif 

#if defined(__MMI_FILE_MANAGER__)
    MMEDIA_ENUM_FILE_MANAGER,
#endif

    MMEDIA_ENUM_TOTAL
} MultiMediaMenu;
#endif /* __MMI_OP01_MENU_9MATRIX__ */

typedef enum
{
#if defined(__J2ME__)
    FUN_ENUM_JAVA,
    FNG_ENUM_SETTING_JAVA,
    #ifdef OGDR_SECURITY_SETTING
    FNG_ENUM_SECURITY_JAVA,
    #endif

    #ifdef __SUPPORT_INFUSIO__
    FNG_ENUM_SETTING_JAVA_EUREKA,
    #endif 

#endif 

#if defined(__MMI_GAME__)
    FUN_ENUM_GAMES,
#endif 

#if defined(__MMI_3D_GAME__)
    FUN_ENUM_3D_GAME,
#endif 

#if defined(__MMI_MOTION_APP__)
    FUN_ENUM_MOTION_APP,
#endif 

#if defined (__MMI_THEMES_APPLICATION__)
    FUN_ENUM_THEME,
#endif 

#if defined (__MMI_PICTURE_EDITOR_SUPPORT__)
    FUN_ENUM_PIC_EDITOR,
#endif 

#if defined (__MMI_AVATAR__)
    FUN_ENUM_AVATAR,
#endif 

    FUN_ENUM_TOTAL
} FunAndGameMenu;

#endif /* defined(__MMI_VERSION_2__) */ // #if defined(__MMI_VERSION_2__)

typedef enum
{
    SCR3000_FUNANDGAMES = FUN_GAMES_BASE + 1,
    SCR_ID_THM_MENU,
    SCR_ID_THM_OPTIONS,
    SCR_ID_THM_UPDATE_PERIOD,
    SCR_ID_THM_SET_ORDER,
    SCR_ID_DOWNLOAD_THM_INFO,
    SCR_ID_DOWNLOAD_THM_STORAGE,
    SCR_ID_DOWNLOAD_THM_COMPLETE,
    SCR_ID_DOWNLOAD_ENTER_ADDRESS,
    SCR_ID_DOWNLOAD_EDIT_ADDRESS,
    SCR_ID_DOWNLOAD_DONE_OPTION,
    SCR_ID_FNG_SETTING_JAVA,
    SCR_ID_FNG_SECURITY_JAVA,
    SCR_ID_FNG_NUM
} SCREENID_LIST_FUNANDGAMES;

typedef enum
{
    STR_MENU3101_THEMES = FUN_GAMES_BASE + 1,
    STR_MENU3104_VOICE_MEMO,
    STR_SCR3000_FUNANDGAMES_CAPTION,
    STR_SCR3000_FUNANDGAMES_LSK,
    STR_SCR3000_FUNANDGAMES_RSK,
    STR_SCR3001_THEMES_CAPTION,
    STR_SCR3001_THEMES_LSK,
    STR_SCR3001_THEMES_RSK,
    STR_MENU3201_UPDATE_PERIOD,
    STR_MENU3202_SET_ORDER,
    STR_SCR3002_THEMES_OPTIONS_CAPTION,
    STR_SCR3002_THEMES_OPTIONS_LSK,
    STR_SCR3002_THEMES_OPTIONS_RSK,
    STR_MENU3301_UPDATE_OFF,
    STR_MENU3302_UPDATE_HOURLY,
    STR_MENU3303_UPDATE_DAILY,
    STR_MENU3304_UPDATE_WEEKLY,
    STR_SCR3003_UPDATE_PERIOD_CAPTION,
    STR_SCR3003_UPDATE_PERIOD_LSK,
    STR_SCR3003_UPDATE_PERIOD_RSK,
    STR_SCR3004_SET_ORDER_CAPTION,
    STR_SCR3004_SET_ORDER_RSK,
    STR_SCR3018_SET_GAMES_CAPTION,
    STR_SCR3018_SET_GAMES_LSK,
    STR_SCR3017_SNAKE,
    STR_SCR3018_SET_SNAKE_CAPTION,
    STR_SCR3018_SET_COLORBALLS_CAPTION,
    STR_SCR3018_SET_SNAKE_LSK,
    STR_THEMES_ACTIVATE,
    STR_MENU_UPDATE_MONTHLY,
    STR_MENU_UPDATE_SEASONALLY,
    STR_THEME_ACTIVATE_SUCCESS,
    STR_THEME_OFF_UPADTE_SUCCESS,
    STR_GAMES_RICHES,
    STR_THEME_NONE,
   /** pls don't change the order of themes strings **/
    STR_THEME_DEFAULT,
    STR_THEME_THEME2,
    STR_THEME_THEME3,
    STR_THEME_THEME4,
    STR_THEME_THEME5,
    STR_THEME_THEME6,
    STR_THEME_THEME7,
    STR_THEME_THEME8,
    STR_THEME_THEME9,
    STR_THEME_THEME10,
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
    STR_DOWNLOAD_INFO_TITLE_ID,
    STR_SELECT_STORAGE_TITLE_ID,
    STR_DOWNLOAD_THEME_UNSUPPORTED,
    STR_ID_DOWNLOAD_THEME_FILE_NAME,
    STR_ID_DOWNLOAD_THEME_FILE_SIZE,
    STR_ID_DOWNLOAD_THEME_URL,
    STR_ID_THEME_STORAGE_PHONE,
    STR_ID_THEME_STORAGE_CARD,
    STR_ID_THEME_DOWNLOAD_COMPLETE,
    STR_ID_THEME_DOWNLOAD_ABORT,
    STR_ID_DLT_DISK_FULL,
    STR_ID_DLT_WRITE_PROTECTED,
    STR_ID_DLT_UNSUFFICIENT_MEMORY,
    STR_ID_DLT_NO_MEMORY_CARD,
    STR_ID_USER_CANCEL,
    STR_ID_CONNECTION_BREAK,
    STR_ID_ERROR_DOWNLOAD,
    STR_ID_DLT_LCD_MISMATCH,
    STR_ID_DLT_ERROR_CREATE_FILE,
    STR_ID_DLT_ERROR_IN_FILE,
    STR_THEME_NOT_AVAILABLE,
    STR_THEME_ALREADY_ACTIVATED,
    STR_THEME_DELETE_SUCCESS,
    STR_THEMES_DELETE,
    STR_THEMES_DOWNLOAD,
    STR_THEME_FORMAT_NOT_SUPPORTED,
    STR_THEME_UNKNOWN_ERROR,
    STR_DOWNLOAD_ENTER_ADDRESS,
    STR_THEME_USB_MODE_DEFAULT_THEME,
    STR_LCD_SIZE_MISMATCH,
    STR_THEME_ERROR_FILENAME_INCORRECT,
    STR_THEME_ERROR_PHONE_MODEL_MISMATCH,
    STR_THEME_ERROR_WAP_ALREADY_ACTIVE,
    STR_THEME_FILE_DOWNLOADED,
	STR_THEME_INVALID_URL,
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 

    /*  FNG Setting */
    STR_ID_FNG_SETTING_JAVA,
    STR_ID_FNG_SETTING_JAVA_AUD,
    STR_ID_FNG_SETTING_JAVA_VIB,
    STR_ID_FNG_SETTING_JAVA_NET_ICON,
    STR_ID_FNG_SETTING_JAVA_VK,
    STR_ID_FNG_SETTING_JAVA_PROF_ID,
    STR_ID_FNG_SETTING_JAVA_STORAGE,
    STR_ID_FNG_SETTING_JAVA_HEAP,

    STR_ID_FNG_SECURITY_JAVA,
    STR_ID_FNG_SECURITY_JAVA_RESTORE,
    STR_ID_FNG_JAVA_EUREKA,
    STR_THEMES_ALARM_ACTIVATION,


#ifdef __MMI_THEMES_V2_SUPPORT__
    STR_ID_DLT_THM_PROGRESS,
    STR_DEFAULT_THEME_ACTIVATION,
#endif /* __MMI_THEMES_V2_SUPPORT__ */
    STR_ID_FNG_MAX
} STRINGID_LIST_FUNANDGAMES;

typedef enum
{
    IMG_MENU3101_THEMES = FUN_GAMES_BASE + 1,
    IMG_MENU3104_VOICE_MEMO,
    IMG_MENU3106_WALLPAPER,
    IMG_MENU3107_SCREENSAVER,
    IMG_MENU3201_UPDATE_PERIOD,
    IMG_MENU3202_SET_ORDER,
    IMAGE_THEME_SELECTED,
    IMAGE_NOIMAGE_THEME,
#ifdef __MMI_THEMES_V2_SUPPORT__
    IMAGE_PHONE_THEME,
    IMAGE_CARD_THEME,
    IMAGE_SYSTEM_THEME,
    IMAGE_ACTIVATED_THEME,
#endif /* __MMI_THEMES_V2_SUPPORT__ */ 
    IMG_MENU_UPDATE_MONTHLY,
    IMG_MENU_UPDATE_SEASONALLY,
    IMG_THEMES_CAPTION,
    IMG_SET_ORDER_MENU_CAPTION,
    IMG_SET_THEME,
    IMG_THEME2_RSKU,
    IMG_THEME3_RSKU,
    IMG_THEME4_RSKU,
    IMG_THEME5_RSKU,
    IMG_THEME6_RSKU,
    IMG_THEME7_RSKU,
    IMG_THEME8_RSKU,
    IMG_THEME9_RSKU,
    IMG_THEME10_RSKU,

    /* IMG_THEME1_RSKD, */
    IMG_THEME2_RSKD,
    IMG_THEME3_RSKD,
    IMG_THEME4_RSKD,
    IMG_THEME5_RSKD,
    IMG_THEME6_RSKD,
    IMG_THEME7_RSKD,
    IMG_THEME8_RSKD,
    IMG_THEME9_RSKD,
    IMG_THEME10_RSKD,

    /* IMG_THEME1_LSKD, */
    IMG_THEME2_LSKD,
    IMG_THEME3_LSKD,
    IMG_THEME4_LSKD,
    IMG_THEME5_LSKD,
    IMG_THEME6_LSKD,
    IMG_THEME7_LSKD,
    IMG_THEME8_LSKD,
    IMG_THEME9_LSKD,
    IMG_THEME10_LSKD,

    /* IMG_THEME1_LSKU, */
    IMG_THEME2_LSKU,
    IMG_THEME3_LSKU,
    IMG_THEME4_LSKU,
    IMG_THEME5_LSKU,
    IMG_THEME6_LSKU,
    IMG_THEME7_LSKU,
    IMG_THEME8_LSKU,
    IMG_THEME9_LSKU,
    IMG_THEME10_LSKU,

    /* IMG_THEME1_TBAR, */
    IMG_THEME2_TBAR,
    IMG_THEME3_TBAR,
    IMG_THEME4_TBAR,
    IMG_THEME5_TBAR,
    IMG_THEME6_TBAR,
    IMG_THEME7_TBAR,
    IMG_THEME8_TBAR,
    IMG_THEME9_TBAR,
    IMG_THEME10_TBAR,
#ifdef __MMI_THEMES_V2_SUPPORT__
    IMG_DOWNLOAD_TITLE_ID,
    IMG_SELECT_STORAGE_TITLE_ID,
    IMG_THEME_ACTIVATION,
#endif /* __MMI_THEMES_V2_SUPPORT__ */ 

    /* FNG Setting */
    IMG_ID_FNG_SETTING_JAVA,
    IMG_ID_FNG_SETTING_JAVA_AUD,
    IMG_ID_FNG_SETTING_JAVA_VIB,
    IMG_ID_FNG_SETTING_JAVA_NET_ICON,
    IMG_ID_FNG_SETTING_JAVA_VK,
    IMG_ID_FNG_SETTING_JAVA_STORAGE,
    IMG_ID_FNG_SETTING_JAVA_HEAP,
    IMG_ID_FNG_SETTING_JAVA_PROF_ID,

    IMG_ID_FNG_SECURITY_JAVA,
    IMG_ID_FNG_JAVA_EUREKA,

    IMG_ID_FNG_FMGR_SUB_ICON
} IMAGEID_LIST_FUNANDGAMES;

#endif /* FUNANDGAMESRESDEF_H */ 

